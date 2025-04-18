# libcnano

(c) 2014-2025 Matthias Arndt <marndt@final-memory.org>

The MIT License applies. Please see COPYING for details.

## Abstract

This provides a reduced library for use with C compilers on embedded or 
resource limited systems like mini and home computers from the 1970s to 1990s.

It is intentionally not 100% compatible with the official C library.
If such a mapping is desired it is up to the user to provide integration
functions.

All code uses stdint.h and stdbool.h types for clarity although the rest of
the source is intentionally compatible with C89 to allow building with more
ancient compilers (if desired).

## How to use

- Compile all .c files under src/ into a static or shared library
- use its functionalities via the libcnano.h header

## Provided functions

### Memory copy

Basic memory copy functions are provided including an optimized variant for
32bit systems.

### String length and copy

Basic functions matching official C library standards are provided.

### String comparison operations

Basic functions to match or find substrings or characters are provided.

### String manipulation operations

Functions are provided for string manipulation in RAM to trim white spaces
and to do case conversions.

## Omitted functions: File and console I/O

The library intentionally does not provide any file or console input or
output operations.

It is possible to implement your own printf or scanf if needed.

The idea is to use operations that are native to the target system.
E.g. call TOS, MSDOS or CP/M directly instead of going through the standard
functions.

## Usage of CMake

Usage of Cmake is optional but a CMakeLists.txt is provided.
The src/ subdirectory may be moved into a project for direct inclusion with
the project specific compiler settings.

The repository intentionally does not make assumptions on compiler settings.

## Original sources imported 2025-04-18

This library originated from 
https://github.com/simonsunnyboy/stlibs4gcc/tree/master/libcnano
