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

#include <cstdio>
#include <cstdint>
#include <cstdarg>
#include "preproc.h"
#include "charmap.h"
#include "char_util.h"
#include "utf8.h"

enum LhsType
{
    Char,
    Escape,
    Constant,
    None
};

struct Lhs
{
    LhsType type;
    std::string name;
    std::int32_t code;
};

class CharmapReader
{
public:
    CharmapReader(std::string filename);
    CharmapReader(const CharmapReader&) = delete;
    ~CharmapReader();
    Lhs ReadLhs();
    void ExpectEqualsSign();
    std::string ReadSequence();
    void ExpectEmptyRestOfLine();
    void RaiseError(const char* format, ...);

private:
    char* m_buffer;
    long m_pos;
    long m_size;
    long m_lineNum;
    std::string m_filename;

    void RemoveComments();
    std::string ReadConstant();
    void SkipWhitespace();
};

CharmapReader::CharmapReader(std::string filename) : m_filename(filename)
{
    FILE *fp = std::fopen(filename.c_str(), "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for reading.\n", filename.c_str());

    std::fseek(fp, 0, SEEK_END);

    m_size = std::ftell(fp);

    if (m_size < 0)
        FATAL_ERROR("File size of \"%s\" is less than zero.\n", filename.c_str());

    m_buffer = new char[m_size + 1];

    std::rewind(fp);

    if (std::fread(m_buffer, m_size, 1, fp) != 1)
        FATAL_ERROR("Failed to read \"%s\".\n", filename.c_str());

    m_buffer[m_size] = 0;

    std::fclose(fp);

    m_pos = 0;
    m_lineNum = 1;

    RemoveComments();
}

CharmapReader::~CharmapReader()
{
    delete[] m_buffer;
}

Lhs CharmapReader::ReadLhs()
{
    Lhs lhs;

    for (;;)
    {
        SkipWhitespace();

        if (m_buffer[m_pos] == '\n')
        {
            m_pos++;
            m_lineNum++;
        }
        else
        {
            break;
        }
    }

    if (m_buffer[m_pos] == '\'')
    {
        m_pos++;

        bool isEscape = (m_buffer[m_pos] == '\\');

        if (isEscape)
        {
            m_pos++;
        }

        unsigned char c = m_buffer[m_pos];

        if (c == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in UTF-8 character literal");
            else
                RaiseError("unexpected null character in UTF-8 character literal");
        }

        if (IsAscii(c) && !IsAsciiPrintable(c))
            RaiseError("unexpected character U+%X in UTF-8 character literal", c);

        UnicodeChar unicodeChar = DecodeUtf8(&m_buffer[m_pos]);
        std::int32_t code = unicodeChar.code;

        if (code == -1)
            RaiseError("invalid encoding in UTF-8 character literal");

        m_pos += unicodeChar.encodingLength;

        if (m_buffer[m_pos] != '\'')
            RaiseError("unterminated character literal");

        m_pos++;

        lhs.code = code;

        if (isEscape)
        {
            if (code >= 128)
                RaiseError("escapes using non-ASCII characters are invalid");

            switch (code)
            {
            case '\'':
                lhs.type = LhsType::Char;
                break;
            case '\\':
                lhs.type = LhsType::Char;
            case '"':
                RaiseError("cannot escape double quote");
                break;
            default:
                lhs.type = LhsType::Escape;
            }
        }
        else
        {
            if (code == '\'')
                RaiseError("empty character literal");

            lhs.type = LhsType::Char;
        }
    }
    else if (IsIdentifierStartingChar(m_buffer[m_pos]))
    {
        lhs.type = LhsType::Constant;
        lhs.name = ReadConstant();
    }
    else if (m_buffer[m_pos] == '\r')
    {
        RaiseError("only Unix-style LF newlines are supported");
    }
    else if (m_buffer[m_pos] == 0)
    {
        if (m_pos < m_size)
            RaiseError("unexpected null character");
        lhs.type = LhsType::None;
    }
    else
    {
        RaiseError("junk at start of line");
    }

    return lhs;
}

void CharmapReader::ExpectEqualsSign()
{
    SkipWhitespace();

    if (m_buffer[m_pos] != '=')
        RaiseError("expected equals sign");

    m_pos++;
}

static unsigned int ConvertHexDigit(char c)
{
    unsigned int digit = 0;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'F')
        digit = 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        digit = 10 + c - 'a';

    return digit;
}

std::string CharmapReader::ReadSequence()
{
    SkipWhitespace();

    long startPos = m_pos;

    unsigned int length = 0;

    while (IsAsciiHexDigit(m_buffer[m_pos]) && IsAsciiHexDigit(m_buffer[m_pos + 1]))
    {
        m_pos += 2;
        length++;

        if (length > kMaxCharmapSequenceLength)
            RaiseError("byte sequence too long (max is %lu bytes)", kMaxCharmapSequenceLength);

        SkipWhitespace();
    }

    if (IsAsciiHexDigit(m_buffer[m_pos]))
        RaiseError("each byte must have 2 hex digits");

    if (length == 0)
        RaiseError("expected byte sequence");

    std::string sequence;
    sequence.reserve(length);

    m_pos = startPos;

    for (unsigned int i = 0; i < length; i++)
    {
        unsigned int digit1 = ConvertHexDigit(m_buffer[m_pos]);
        unsigned int digit2 = ConvertHexDigit(m_buffer[m_pos + 1]);
        unsigned char byte = digit1 * 16 + digit2;
        sequence += byte;

        m_pos += 2;
        SkipWhitespace();
    }

    return sequence;
}

void CharmapReader::ExpectEmptyRestOfLine()
{
    SkipWhitespace();

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos < m_size)
            RaiseError("unexpected null character");
    }
    else if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        m_lineNum++;
    }
    else if (m_buffer[m_pos] == '\r')
    {
        RaiseError("only Unix-style LF newlines are supported");
    }
    else
    {
        RaiseError("junk at end of line");
    }
}

void CharmapReader::RaiseError(const char* format, ...)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];

    std::va_list args;
    va_start(args, format);
    std::vsnprintf(buffer, bufferSize, format, args);
    va_end(args);

    std::fprintf(stderr, "%s:%ld: error: %s\n", m_filename.c_str(), m_lineNum, buffer);

    std::exit(1);
}

void CharmapReader::RemoveComments()
{
    long pos = 0;
    bool inString = false;

    for (;;)
    {
        if (m_buffer[pos] == 0)
            return;

        if (inString)
        {
            if (m_buffer[pos] == '\\' && m_buffer[pos + 1] == '\'')
            {
                pos += 2;
            }
            else
            {
                if (m_buffer[pos] == '\'')
                    inString = false;
                pos++;
            }
        }
        else if (m_buffer[pos] == '@')
        {
            while (m_buffer[pos] != '\n' && m_buffer[pos] != 0)
                m_buffer[pos++] = ' ';
        }
        else
        {
            if (m_buffer[pos] == '\'')
                inString = true;
            pos++;
        }
    }
}

std::string CharmapReader::ReadConstant()
{
    long startPos = m_pos;

    while (IsIdentifierChar(m_buffer[m_pos]))
        m_pos++;

    return std::string(&m_buffer[startPos], m_pos - startPos);
}

void CharmapReader::SkipWhitespace()
{
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
        m_pos++;
}

Charmap::Charmap(std::string filename)
{
    CharmapReader reader(filename);

    for (;;)
    {
        Lhs lhs = reader.ReadLhs();

        if (lhs.type == LhsType::None)
            return;

        reader.ExpectEqualsSign();

        std::string sequence = reader.ReadSequence();

        switch (lhs.type)
        {
        case LhsType::Char:
            if (m_chars.find(lhs.code) != m_chars.end())
                reader.RaiseError("redefining char");
            m_chars[lhs.code] = sequence;
            break;
        case LhsType::Escape:
            if (m_escapes[lhs.code].length() != 0)
                reader.RaiseError("redefining escape");
            m_escapes[lhs.code] = sequence;
            break;
        case LhsType::Constant:
            if (m_constants.find(lhs.name) != m_constants.end())
                reader.RaiseError("redefining constant");
            m_constants[lhs.name] = sequence;
            break;
        }

        reader.ExpectEmptyRestOfLine();
    }
}
