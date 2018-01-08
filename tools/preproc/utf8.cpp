// Copyright (c) 2008-2009 Bjoern Hoehrmann <bjoern@hoehrmann.de>
// See http://bjoern.hoehrmann.de/utf-8/decoder/dfa/ for details.
//
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

#include <cstdint>
#include "utf8.h"

static const unsigned char s_byteTypeTable[] =
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 00..1f
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 20..3f
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 40..5f
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 60..7f
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9, // 80..9f
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7, // a0..bf
    8,8,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, // c0..df
    0xa,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x4,0x3,0x3, // e0..ef
    0xb,0x6,0x6,0x6,0x5,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8,0x8, // f0..ff
};

const unsigned char s0 = 0 * 12;
const unsigned char s1 = 1 * 12;
const unsigned char s2 = 2 * 12;
const unsigned char s3 = 3 * 12;
const unsigned char s4 = 4 * 12;
const unsigned char s5 = 5 * 12;
const unsigned char s6 = 6 * 12;
const unsigned char s7 = 7 * 12;
const unsigned char s8 = 8 * 12;

static const unsigned char s_transitionTable[] =
{
    s0,s1,s2,s3,s5,s8,s7,s1,s1,s1,s4,s6, // s0
    s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1, // s1
    s1,s0,s1,s1,s1,s1,s1,s0,s1,s0,s1,s1, // s2
    s1,s2,s1,s1,s1,s1,s1,s2,s1,s2,s1,s1, // s3
    s1,s1,s1,s1,s1,s1,s1,s2,s1,s1,s1,s1, // s4
    s1,s2,s1,s1,s1,s1,s1,s1,s1,s2,s1,s1, // s5
    s1,s1,s1,s1,s1,s1,s1,s3,s1,s3,s1,s1, // s6
    s1,s3,s1,s1,s1,s1,s1,s3,s1,s3,s1,s1, // s7
    s1,s3,s1,s1,s1,s1,s1,s1,s1,s1,s1,s1, // s8
};

// Decodes UTF-8 encoded Unicode code point at "s".
UnicodeChar DecodeUtf8(const char* s)
{
    UnicodeChar unicodeChar;
    int state = s0;
    auto start = s;

    do
    {
        unsigned char byte = *s++;
        int type = s_byteTypeTable[byte];

        if (state == s0)
            unicodeChar.code = (0xFF >> type) & byte;
        else
            unicodeChar.code = (unicodeChar.code << 6) | (byte & 0x3F);

        state = s_transitionTable[state + type];

        if (state == s1)
        {
            unicodeChar.code = -1;
            return unicodeChar;
        }
    } while (state != s0);

    unicodeChar.encodingLength = s - start;

    return unicodeChar;
}
