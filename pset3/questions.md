# Questions

## What's `stdint.h`?

This is a header file that provides access to several functions related to integer standards, such as uint8_t, uint32_t, int32_t, and uint16_t . These functions specify the exact width of integers. These functions allow code to be more portable by setting widths dependent on the processor targets (whether 32 bit or 64 bit, for example).

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These functions are a cross-platform implementation of a standard data type. uint8_t is an unsigned int of 8 bits, uint32_t is an unsigned long long, int32_t is a signed long long, and a uint16_t is an unsigned 16 bit int.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Byte: 1
DWORD: 4
LONG: 4
WORD: 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes specify the file is a bitmap with the words "BM", or the hex 0x4D42 .

## What's the difference between `bfSize` and `biSize`?

bfSize describes the entire file size in bytes, whereas biSize is the size of BITMAPINFOHEADER in bytes.

## What does it mean if `biHeight` is negative?

Negative biHeight means the bitmap is is a top-down DIB with the origin at the upper left corner.


## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount .

## Why might `fopen` return `NULL` in `copy.c`?

fopen will return null if it cannot open the file. This can happen if there is not enough memory or the file cannot be found.


## Why is the third argument to `fread` always `1` in our code?

The third argument determines the number of elements fread will read. So this argument is always 1 because we are always reading one file.


## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

1

## What does `fseek` do?

fseek moves the file position indicator.

## What is `SEEK_CUR`?

SEEK_CUR is an option used in fseek to set the offset relative to the current pointer position.

