// Copyright(c) 2015-2017 YamaArashi
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
#include <string>
#include "scaninc.h"
#include "asm_file.h"

AsmFile::AsmFile(std::string path)
{
    m_path = path;

    FILE *fp = std::fopen(path.c_str(), "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for reading.\n", path.c_str());

    std::fseek(fp, 0, SEEK_END);

    m_size = std::ftell(fp);

    if (m_size < 0)
        FATAL_ERROR("File size of \"%s\" is less than zero.\n", path.c_str());
    else if (m_size == 0)
        return; // Empty file

    m_buffer = new char[m_size];

    std::rewind(fp);

    if (std::fread(m_buffer, m_size, 1, fp) != 1)
        FATAL_ERROR("Failed to read \"%s\".\n", path.c_str());

    std::fclose(fp);

    m_pos = 0;
    m_lineNum = 1;
}

AsmFile::~AsmFile()
{
    if (m_size > 0) delete[] m_buffer;
}

IncDirectiveType AsmFile::ReadUntilIncDirective(std::string &path)
{
    // At the beginning of each loop iteration, the current file position
    // should be at the start of a line or at the end of the file.
    for (;;)
    {
        SkipTabsAndSpaces();

        IncDirectiveType incDirectiveType = IncDirectiveType::None;

        char c = PeekChar();
        if (c == '.' || c == '#')
        {
            m_pos++;

            if (MatchIncDirective("incbin", path))
                incDirectiveType = IncDirectiveType::Incbin;
            else if (MatchIncDirective("include", path))
                incDirectiveType = IncDirectiveType::Include;
        }

        for (;;)
        {
            int c = GetChar();

            if (c == -1)
                return incDirectiveType;

            if (c == ';')
            {
                SkipEndOfLineComment();
                break;
            }
            else if (c == '/' && PeekChar() == '*')
            {
                m_pos++;
                SkipMultiLineComment();
            }
            else if (c == '"')
            {
                SkipString();
            }
            else if (c == '\n')
            {
                break;
            }
        }

        if (incDirectiveType != IncDirectiveType::None)
            return incDirectiveType;
    }
}

std::string AsmFile::ReadPath()
{
    int length = 0;
    int startPos = m_pos;

    for (;;)
    {
        int c = GetChar();

        if (c == '"')
            break;

        if (c == -1)
            FATAL_INPUT_ERROR("unexpected EOF in include string\n");

        if (c == 0)
            FATAL_INPUT_ERROR("unexpected NUL character in include string\n");

        if (c == '\n')
            FATAL_INPUT_ERROR("unexpected end of line character in include string\n");

        // Don't bother allowing any escape sequences.
        if (c == '\\')
            FATAL_INPUT_ERROR("unexpected escape in include string\n");

        length++;

        if (length > SCANINC_MAX_PATH)
            FATAL_INPUT_ERROR("path is too long");
    }

    return std::string(m_buffer + startPos, length);
}

void AsmFile::SkipEndOfLineComment()
{
    int c;

    do
    {
        c = GetChar();
    } while (c != -1 && c != '\n');
}

void AsmFile::SkipMultiLineComment()
{
    for (;;)
    {
        int c = GetChar();

        if (c == '*')
        {
            if (PeekChar() == '/')
            {
                m_pos++;
                return;
            }
        }
        else if (c == -1)
        {
            return;
        }
    }
}

void AsmFile::SkipString()
{
    for (;;)
    {
        int c = GetChar();

        if (c == '"')
            break;

        if (c == -1)
            FATAL_INPUT_ERROR("unexpected EOF in string\n");

        if (c == '\\')
        {
            c = GetChar();
        }
    }
}
