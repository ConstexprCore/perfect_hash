#!/usr/bin/env python3
"""Amalgamate the ConstexprCore perfect_hash headers into one drop-in header.

Modeled on simdutf's singleheader/amalgamate.py: walk the include graph from a
root header, splice each project header in at the point where it is included,
and leave everything else — system includes, preprocessor conditionals, code —
exactly as written.

Splicing *in place* rather than hoisting matters here: the SIMD helpers are
included inside `#if` blocks and pull in ISA headers (arm_neon.h, emmintrin.h,
lsxintrin.h) that must stay behind their guards.

The bundled dependency (ConstexprCore/useful_abstractions, which supplies
fixed_string.h) is discovered automatically from a CMake build tree, or can be
pointed at with --include-dir, or cloned on demand with --fetch.

Usage:
    python3 singleheader/amalgamate.py                  # write singleheader/perfect_hash.h
    python3 singleheader/amalgamate.py --check          # verify the checked-in copy is current
    python3 singleheader/amalgamate.py --test           # also compile the demo
"""

from __future__ import annotations

import argparse
import datetime
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
PROJECT_ROOT = SCRIPT_DIR.parent

DEFAULT_ROOT_HEADER = "ConstexprCore/perfect_hash.h"
DEFAULT_OUTPUT = SCRIPT_DIR / "perfect_hash.h"
DEFAULT_DEMO = SCRIPT_DIR / "amalgamation_demo.cpp"

DEPENDENCY_REPO = "https://github.com/ConstexprCore/useful_abstractions.git"
DEPENDENCY_DIR_NAME = "useful_abstractions"

INCLUDE_RE = re.compile(r'^\s*#\s*include\s*(?:"([^"]+)"|<([^>]+)>)')
PRAGMA_ONCE_RE = re.compile(r'^\s*#\s*pragma\s+once\s*$')

DEMO_SOURCE = '''// Compile with:  c++ -std=c++23 -I. amalgamation_demo.cpp -o demo
#include "perfect_hash.h"

#include <cstdio>

using namespace ConstexprCore;

static constexpr auto methods = make_perfect_map<
    kv<"GET", 0>, kv<"PUT", 1>, kv<"POST", 2>, kv<"HEAD", 3>,
    kv<"PATCH", 4>, kv<"TRACE", 5>, kv<"DELETE", 6>, kv<"OPTIONS", 7>>();

static_assert(*methods.lookup("POST") == 2);
static_assert(!methods.lookup("BREW").has_value());

int main() {
    for (const char* probe : {"GET", "OPTIONS", "BREW"}) {
        auto hit = methods.lookup(probe);
        std::printf("%-8s -> %s\\n", probe, hit ? "found" : "not found");
    }
    std::printf("built with %s\\n", methods.algorithm_name().data());
    return 0;
}
'''


def log(message: str) -> None:
    print(f"[amalgamate] {message}", file=sys.stderr)


def find_dependency_include_dirs(explicit: list[Path], fetch: bool) -> list[Path]:
    """Locate the include directory of the bundled dependency."""
    if explicit:
        return explicit

    candidates: list[Path] = []
    # A configured CMake build tree keeps the FetchContent checkout here.
    for build_dir in sorted(PROJECT_ROOT.glob("*/_deps")):
        candidates.append(build_dir / f"{DEPENDENCY_DIR_NAME}-src" / "include")
    # A sibling checkout, the usual layout when both repos are cloned by hand.
    candidates.append(PROJECT_ROOT.parent / DEPENDENCY_DIR_NAME / "include")

    for candidate in candidates:
        if (candidate / "ConstexprCore" / "fixed_string.h").is_file():
            log(f"dependency: {candidate}")
            return [candidate]

    if not fetch:
        raise SystemExit(
            f"could not find {DEPENDENCY_DIR_NAME}; configure a CMake build first, "
            f"pass --include-dir <path>, or re-run with --fetch"
        )

    cache = Path(tempfile.gettempdir()) / f"perfect_hash-{DEPENDENCY_DIR_NAME}"
    if not (cache / "include" / "ConstexprCore" / "fixed_string.h").is_file():
        shutil.rmtree(cache, ignore_errors=True)
        log(f"cloning {DEPENDENCY_REPO}")
        subprocess.run(["git", "clone", "--depth", "1", DEPENDENCY_REPO, str(cache)], check=True)
    log(f"dependency: {cache / 'include'}")
    return [cache / "include"]


class Amalgamator:
    def __init__(self, include_dirs: list[Path]) -> None:
        self.include_dirs = include_dirs
        self.included: set[Path] = set()
        self.order: list[str] = []
        self.lines: list[str] = []

    def resolve(self, name: str, current_file: Path) -> Path | None:
        """Map an #include target to a project file, or None if it is a system header."""
        sibling = current_file.parent / name
        if sibling.is_file():
            return sibling.resolve()
        for directory in self.include_dirs:
            candidate = directory / name
            if candidate.is_file():
                return candidate.resolve()
        return None

    def display_name(self, path: Path) -> str:
        for directory in self.include_dirs:
            try:
                return path.relative_to(directory.resolve()).as_posix()
            except ValueError:
                continue
        try:
            return path.relative_to(PROJECT_ROOT).as_posix()
        except ValueError:
            return path.name

    def splice(self, path: Path) -> None:
        path = path.resolve()
        name = self.display_name(path)
        if path in self.included:
            self.lines.append(f"/* skipped duplicate {name} */")
            return
        self.included.add(path)
        self.order.append(name)

        self.lines.append(f"/* begin file {name} */")
        for line in path.read_text(encoding="utf-8").splitlines():
            if PRAGMA_ONCE_RE.match(line):
                # The amalgamation is one file; a per-fragment `#pragma once`
                # would apply to the whole of it.
                self.lines.append(f"/* omitted #pragma once from {name} */")
                continue
            match = INCLUDE_RE.match(line)
            if match:
                target = match.group(1) or match.group(2)
                resolved = self.resolve(target, path)
                if resolved is not None:
                    self.splice(resolved)
                    continue
            self.lines.append(line)
        self.lines.append(f"/* end file {name} */")


def project_version() -> str:
    text = (PROJECT_ROOT / "CMakeLists.txt").read_text(encoding="utf-8")
    match = re.search(r"project\([^)]*?VERSION\s+([0-9]+\.[0-9]+\.[0-9]+)", text, re.S)
    return match.group(1) if match else "unknown"


def build_header(include_dirs: list[Path], root_header: str, stamp: str) -> str:
    root_path = None
    for directory in include_dirs:
        candidate = directory / root_header
        if candidate.is_file():
            root_path = candidate
            break
    if root_path is None:
        raise SystemExit(f"root header {root_header} not found in {include_dirs}")

    amalgamator = Amalgamator(include_dirs)
    amalgamator.splice(root_path)

    # The point of the amalgamation is that the standard library (plus the
    # compiler's own ISA headers, behind their guards) is all it needs. Prove
    # it rather than trusting the walk.
    leftovers = [
        line for line in amalgamator.lines
        if INCLUDE_RE.match(line) and "ConstexprCore/" in line
    ]
    if leftovers:
        raise SystemExit(
            "amalgamation is not self-contained; unresolved project includes:\n  "
            + "\n  ".join(leftovers)
        )

    banner = [
        f"/* auto-generated on {stamp}. Do not edit! */",
        "/*",
        f" * ConstexprCore perfect_hash {project_version()} — single-header amalgamation.",
        " *",
        " * Compile-time perfect hashing for C++. Drop this file into your project and",
        " * #include it; it is self-contained and needs no other ConstexprCore headers.",
        " *",
        " * Requires C++23. Regenerate with singleheader/amalgamate.py.",
        " *",
        " * Bundled files, in order:",
    ]
    banner += [f" *   {name}" for name in amalgamator.order]
    banner += [" */", ""]
    return "\n".join(banner + amalgamator.lines) + "\n"


def strip_stamp(text: str) -> str:
    """Drop the generated-on line so --check ignores the timestamp."""
    return "\n".join(
        line for line in text.splitlines() if not line.startswith("/* auto-generated on ")
    )


def compile_demo(header: Path, demo: Path) -> None:
    compiler = os.environ.get("CXX", "c++")
    with tempfile.TemporaryDirectory() as tmp:
        workdir = Path(tmp)
        shutil.copy(header, workdir / header.name)
        shutil.copy(demo, workdir / demo.name)
        binary = workdir / "demo"
        command = [compiler, "-std=c++23", "-O2", "-I", str(workdir), str(workdir / demo.name), "-o", str(binary)]
        log(" ".join(command))
        subprocess.run(command, check=True)
        subprocess.run([str(binary)], check=True)
    log("demo compiled and ran cleanly")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT,
                        help=f"amalgamated header to write (default: {DEFAULT_OUTPUT.relative_to(PROJECT_ROOT)})")
    parser.add_argument("--demo", type=Path, default=DEFAULT_DEMO, help="demo source to write alongside the header")
    parser.add_argument("--root-header", default=DEFAULT_ROOT_HEADER, help="entry point of the include graph")
    parser.add_argument("--include-dir", type=Path, action="append", default=[],
                        help="extra include root (repeatable); the project's own include/ is always used")
    parser.add_argument("--fetch", action="store_true", help="git clone the dependency if it cannot be found locally")
    parser.add_argument("--check", action="store_true", help="fail if the file on disk differs from freshly generated output")
    parser.add_argument("--test", action="store_true", help="compile and run the demo against the generated header")
    parser.add_argument("--quiet", action="store_true", help="suppress progress output")
    args = parser.parse_args()

    if args.quiet:
        global log
        log = lambda message: None  # noqa: E731

    include_dirs = [PROJECT_ROOT / "include"]
    include_dirs += find_dependency_include_dirs([d.resolve() for d in args.include_dir], args.fetch)

    stamp = datetime.datetime.now().astimezone().strftime("%Y-%m-%d %H:%M:%S %z")
    text = build_header(include_dirs, args.root_header, stamp)

    if args.check:
        if not args.output.is_file():
            print(f"{args.output} is missing; run singleheader/amalgamate.py", file=sys.stderr)
            return 1
        if strip_stamp(args.output.read_text(encoding="utf-8")) != strip_stamp(text):
            print(f"{args.output} is out of date; run singleheader/amalgamate.py", file=sys.stderr)
            return 1
        log(f"{args.output} is up to date")
        return 0

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(text, encoding="utf-8")
    log(f"wrote {args.output} ({len(text.splitlines())} lines)")

    if args.demo is not None:
        args.demo.parent.mkdir(parents=True, exist_ok=True)
        args.demo.write_text(DEMO_SOURCE, encoding="utf-8")
        log(f"wrote {args.demo}")

    if args.test:
        compile_demo(args.output, args.demo)
    return 0


if __name__ == "__main__":
    sys.exit(main())
