#!/usr/bin/env python3

from __future__ import annotations

import argparse
from pathlib import Path


COMMENTED_INCLUDES = {
    "#include <ConstexprCore/fixed_string.h>",
    "#include <ConstexprCore/detail/gperf_generator.h>",
    "#include <ConstexprCore/detail/neon_compare.h>",
    "#include <ConstexprCore/detail/sse2_compare.h>",
    "#include <ConstexprCore/detail/lsx_compare.h>",
}


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8")


def rewrite_perfect_hash(text: str) -> str:
    out_lines: list[str] = []
    for line in text.splitlines():
        stripped = line.strip()
        if stripped in COMMENTED_INCLUDES:
            out_lines.append(f"// bundled in single-header: {stripped}")
        else:
            out_lines.append(line)
    return "\n".join(out_lines) + "\n"


def bundle_section(title: str, text: str) -> str:
    return (
        f"// ===== BEGIN BUNDLED HEADER: {title} =====\n"
        f"{text.rstrip()}\n"
        f"// ===== END BUNDLED HEADER: {title} =====\n\n"
    )


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate a single-header perfect_hash.h bundle")
    parser.add_argument("--output", required=True)
    parser.add_argument("--fixed-string", required=True)
    parser.add_argument("--gperf-generator", required=True)
    parser.add_argument("--neon-compare", required=True)
    parser.add_argument("--sse2-compare", required=True)
    parser.add_argument("--lsx-compare", required=True)
    parser.add_argument("--perfect-hash", required=True)
    args = parser.parse_args()

    output_path = Path(args.output)
    inputs = [
        ("fixed_string.h", Path(args.fixed_string), False),
        ("detail/gperf_generator.h", Path(args.gperf_generator), False),
        ("detail/neon_compare.h", Path(args.neon_compare), False),
        ("detail/sse2_compare.h", Path(args.sse2_compare), False),
        ("detail/lsx_compare.h", Path(args.lsx_compare), False),
        ("perfect_hash.h", Path(args.perfect_hash), True),
    ]

    parts = [
        "// Generated file: single-header bundle for ConstexprCore perfect_hash\n"
        "// Do not edit directly; regenerate via the CMake target perfect_hash_singleheader.\n\n"
    ]

    for title, path, rewrite in inputs:
        text = read_text(path)
        if rewrite:
            text = rewrite_perfect_hash(text)
        parts.append(bundle_section(title, text))

    output_path.write_text("".join(parts), encoding="utf-8")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())