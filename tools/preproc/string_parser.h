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

#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <cstdint>
#include <string>
#include "preproc.h"

class StringParser
{
public:
    StringParser(char* buffer, long size) : m_buffer(buffer), m_size(size), m_pos(0) {}
    int ParseString(long srcPos, unsigned char* dest, int &destLength);

private:
    struct Integer
    {
        std::uint32_t value;
        int size;
    };

    char* m_buffer;
    long m_size;
    long m_pos;

    Integer ReadInteger();
    Integer ReadDecimal();
    Integer ReadHex();
    std::string ReadCharOrEscape();
    std::string ReadBracketedConstants();
    void SkipWhitespace();
    void SkipRestOfInteger(int radix);
    void RaiseError(const char* format, ...);
};

#endif // STRING_PARSER_H
