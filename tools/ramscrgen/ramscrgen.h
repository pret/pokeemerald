// Copyright(c) 2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef RAMSCRGEN_H
#define RAMSCRGEN_H

#include <cstdio>
#include <cstdlib>

#ifdef _MSC_VER

#define FATAL_ERROR(format, ...)               \
do                                             \
{                                              \
    std::fprintf(stderr, format, __VA_ARGS__); \
    std::exit(1);                              \
} while (0)

#else

#define FATAL_ERROR(format, ...)                 \
do                                               \
{                                                \
    std::fprintf(stderr, format, ##__VA_ARGS__); \
    std::exit(1);                                \
} while (0)

#endif // _MSC_VER

const int kMaxPath = 256;

#endif // RAMSCRGEN_H
