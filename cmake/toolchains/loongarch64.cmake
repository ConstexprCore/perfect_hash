# CMake toolchain for cross-compiling to LoongArch64 (Linux) with LSX enabled.
#
# Uses the Ubuntu-packaged GCC 14 LoongArch cross-compiler
# (g++-14-loongarch64-linux-gnu etc.) together with a QEMU user-mode emulator
# (CPU la464) so that ctest can execute the cross-built binaries.
#
# `-mlsx` guarantees that __loongarch_sx is defined, exercising the
# CONSTEXPRCORE_HAS_LSX comparison paths in include/ConstexprCore/detail/lsx_compare.h.
#
# Usage (from repo root):
#   cmake -B build -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/loongarch64.cmake ...
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR loongarch64)

set(target  loongarch64-linux-gnu)
set(version 14)

set(CMAKE_C_COMPILER   "${target}-gcc-${version}")
set(CMAKE_CXX_COMPILER "${target}-g++-${version}")

# Ubuntu cross packages install the target sysroot under /usr/<target>.
# Point CMake at it so it can find the correct headers and libraries.
set(CMAKE_SYSROOT /usr/${target})

# Search the target sysroot for libraries, headers and packages.
# Never search the sysroot for host build tools (cmake, ninja, etc.).
set(CMAKE_FIND_ROOT_PATH /usr/${target})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Run cross-built test binaries (including ctest POST_BUILD discovery steps)
# through QEMU user-mode emulation.
set(CMAKE_CROSSCOMPILING_EMULATOR "qemu-loongarch64")

# Enable the LSX instruction set so the SIMD compare path is compiled.
# Using *_INIT so it is applied early and can be extended by the user if needed.
set(CMAKE_CXX_FLAGS_INIT "-mlsx")
