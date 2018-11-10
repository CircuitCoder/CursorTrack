# CursorTrack

> Warning: This targes win32. Invokes `mingw-w64` the evil cross-compiler. We do not hold responsibilities for any injuries or casualties caused during the using of this software. Uses at your own risk.

# Compile

You just cmake, then you make

```bash
# Change the compiler prefix
editor ./toolchain.cmake

# CMake it
cmake -DCMAKE_TOOLCHAIN_FILE=./toolchain.cmake .
 ```
