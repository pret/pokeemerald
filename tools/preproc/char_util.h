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

#ifndef CHAR_UTIL_H
#define CHAR_UTIL_H

#include <cstdint>
#include <cassert>

inline bool IsAscii(unsigned char c)
{
    return (c < 128);
}

inline bool IsAsciiAlpha(unsigned char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

inline bool IsAsciiDigit(unsigned char c)
{
    return (c >= '0' && c <= '9');
}

inline bool IsAsciiHexDigit(unsigned char c)
{
    return ((c >= '0' && c <= '9')
        || (c >= 'a' && c <= 'f')
        || (c >= 'A' && c <= 'F'));
}

inline bool IsAsciiAlphanum(unsigned char c)
{
    return (IsAsciiAlpha(c) || IsAsciiDigit(c));
}

inline bool IsAsciiPrintable(unsigned char c)
{
    return (c >= ' ' && c <= '~');
}

// Returns whether the character can start a C identifier or the identifier of a "{FOO}" constant in strings.
inline bool IsIdentifierStartingChar(unsigned char c)
{
    return IsAsciiAlpha(c) || c == '_';
}

// Returns whether the character can be used in a C identifier or the identifier of a "{FOO}" constant in strings.
inline bool IsIdentifierChar(unsigned char c)
{
    return IsAsciiAlphanum(c) || c == '_';
}

#endif // CHAR_UTIL_H
