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

#ifndef ASM_FILE_H
#define ASM_FILE_H

#include <string>
#include "scaninc.h"

enum class IncDirectiveType
{
    None,
    Include,
    Incbin
};

class AsmFile
{
public:
    AsmFile(std::string path);
    ~AsmFile();
    IncDirectiveType ReadUntilIncDirective(std::string& path);

private:
    char *m_buffer;
    int m_pos;
    int m_size;
    int m_lineNum;
    std::string m_path;

    int GetChar()
    {
        if (m_pos >= m_size)
            return -1;

        int c = m_buffer[m_pos++];

        if (c == '\r')
        {
            if (m_pos < m_size && m_buffer[m_pos++] == '\n')
            {
                m_lineNum++;
                return '\n';
            }
            else
            {
                FATAL_INPUT_ERROR("CR line endings are not supported\n");
            }
        }

        if (c == '\n')
            m_lineNum++;

        return c;
    }

    // No newline translation because it's not needed for any use of this function.
    int PeekChar()
    {
        if (m_pos >= m_size)
            return -1;

        return m_buffer[m_pos];
    }

    void SkipTabsAndSpaces()
    {
        while (m_pos < m_size && (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' '))
            m_pos++;
    }

    bool MatchIncDirective(std::string directiveName, std::string& path)
    {
        int length = directiveName.length();
        int i;

        for (i = 0; i < length && m_pos + i < m_size; i++)
            if (directiveName[i] != m_buffer[m_pos + i])
                return false;

        if (i < length)
            return false;

        m_pos += length;

        SkipTabsAndSpaces();

        if (GetChar() != '"')
            FATAL_INPUT_ERROR("no path after \".%s\" directive\n", directiveName.c_str());

        path = ReadPath();

        return true;
    }

    std::string ReadPath();
    void SkipEndOfLineComment();
    void SkipMultiLineComment();
    void SkipString();
};

#endif // ASM_FILE_H
