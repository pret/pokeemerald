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
#include <cstdarg>
#include <climits>
#include "ramscrgen.h"
#include "sym_file.h"
#include "char_util.h"

SymFile::SymFile(std::string filename) : m_filename(filename)
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
    m_lineStart = 0;
    m_inLangConditional = false;

    RemoveComments();
}

SymFile::SymFile(SymFile&& other) : m_filename(std::move(other.m_filename))
{
    m_buffer = other.m_buffer;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_lineNum = other.m_lineNum;
    m_lineStart = other.m_lineStart;

    other.m_buffer = nullptr;
}

SymFile::~SymFile()
{
    delete[] m_buffer;
}

// Removes comments to simplify further processing.
// It stops upon encountering a null character,
// which may or may not be the end of file marker.
// If it's not, the error will be caught later.
void SymFile::RemoveComments()
{
    long pos = 0;
    char stringChar = 0;

    for (;;)
    {
        if (m_buffer[pos] == 0)
            return;

        if (stringChar != 0)
        {
            if (m_buffer[pos] == '\\' && m_buffer[pos + 1] == stringChar)
            {
                pos += 2;
            }
            else
            {
                if (m_buffer[pos] == stringChar)
                    stringChar = 0;
                pos++;
            }
        }
        else if (m_buffer[pos] == '@' && (pos == 0 || m_buffer[pos - 1] != '\\'))
        {
            while (m_buffer[pos] != '\n' && m_buffer[pos] != 0)
                m_buffer[pos++] = ' ';
        }
        else if (m_buffer[pos] == '/' && m_buffer[pos + 1] == '*')
        {
            m_buffer[pos++] = ' ';
            m_buffer[pos++] = ' ';

            char commentStringChar = 0;

            for (;;)
            {
                if (m_buffer[pos] == 0)
                    return;

                if (commentStringChar != 0)
                {
                    if (m_buffer[pos] == '\\' && m_buffer[pos + 1] == commentStringChar)
                    {
                        m_buffer[pos++] = ' ';
                        m_buffer[pos++] = ' ';
                    }
                    else
                    {
                        if (m_buffer[pos] == commentStringChar)
                            commentStringChar = 0;
                        if (m_buffer[pos] != '\n')
                            m_buffer[pos] = ' ';
                        pos++;
                    }
                }
                else
                {
                    if (m_buffer[pos] == '*' && m_buffer[pos + 1] == '/')
                    {
                        m_buffer[pos++] = ' ';
                        m_buffer[pos++] = ' ';
                        break;
                    }
                    else
                    {
                        if (m_buffer[pos] == '"' || m_buffer[pos] == '\'')
                            commentStringChar = m_buffer[pos];
                        if (m_buffer[pos] != '\n')
                            m_buffer[pos] = ' ';
                        pos++;
                    }
                }
            }
        }
        else
        {
            if (m_buffer[pos] == '"' || m_buffer[pos] == '\'')
                stringChar = m_buffer[pos];
            pos++;
        }
    }
}

// Checks if we're at a particular directive and if so, consumes it.
// Returns whether the directive was found.
bool SymFile::CheckForDirective(std::string name)
{
    long i;
    long length = static_cast<long>(name.length());

    for (i = 0; i < length && m_pos + i < m_size; i++)
        if (name[i] != m_buffer[m_pos + i])
            return false;

    if (i < length)
        return false;

    m_pos += length;

    return true;
}

// Checks if we're at a known directive and if so, consumes it.
// Returns which directive was found.
Directive SymFile::GetDirective()
{
    SkipWhitespace();

    if (CheckForDirective(".include"))
        return Directive::Include;
    else if (CheckForDirective(".space"))
        return Directive::Space;
    else if (CheckForDirective(".align"))
        return Directive::Align;
    else
        return Directive::Unknown;
}

// Checks if we're at label.
// Returns the name if so and an empty string if not.
std::string SymFile::GetLabel(bool requireColon)
{
    long start = m_pos;
    long pos = m_pos;

    if (IsIdentifierStartingChar(m_buffer[pos]))
    {
        pos++;

        while (IsIdentifierChar(m_buffer[pos]))
            pos++;
    }

    if (requireColon)
    {
        if (m_buffer[pos] == ':')
        {
            if (pos != start)
                m_pos = pos + 1;
        }
        else
        {
            pos = start;
        }
    }
    else
    {
        m_pos = pos;
    }

    return std::string(&m_buffer[start], pos - start);
}

// Skips tabs and spaces.
void SymFile::SkipWhitespace()
{
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
        m_pos++;
}

// Reads include path.
std::string SymFile::ReadPath()
{
    SkipWhitespace();

    if (m_buffer[m_pos] != '"')
        RaiseError("expected file path");

    m_pos++;

    int length = 0;
    long startPos = m_pos;

    while (m_buffer[m_pos] != '"')
    {
        unsigned char c = m_buffer[m_pos++];

        if (c == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in include string");
            else
                RaiseError("unexpected null character in include string");
        }

        if (!IsAsciiPrintable(c))
            RaiseError("unexpected character '\\x%02X' in include string", c);

        // Don't bother allowing any escape sequences.
        if (c == '\\')
        {
            c = m_buffer[m_pos];
            RaiseError("unexpected escape '\\%c' in include string", c);
        }

        length++;

        if (length > kMaxPath)
            RaiseError("path is too long");
    }

    m_pos++; // Go past the right quote.

    return std::string(&m_buffer[startPos], length);
}

// If we're at a comma, consumes it.
// Returns whether a comma was found.
bool SymFile::ConsumeComma()
{
    if (m_buffer[m_pos] == ',')
    {
        m_pos++;
        return true;
    }

    return false;
}

// Converts digit character to numerical value.
static int ConvertDigit(char c, int radix)
{
    int digit;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'F')
        digit = 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        digit = 10 + c - 'a';
    else
        return -1;

    return (digit < radix) ? digit : -1;
}

// Reads an integer.
bool SymFile::ReadInteger(unsigned long& n)
{
    SkipWhitespace();

    if (!IsAsciiDigit(m_buffer[m_pos]))
        return false;

    int startPos = m_pos;
    int radix = 10;

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        radix = 16;
        m_pos += 2;
    }

    unsigned long cutoff = ULONG_MAX / radix;
    unsigned long cutoffRemainder = ULONG_MAX % radix;
    int digit;

    n = 0;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        if (n < cutoff || (n == cutoff && (unsigned long)digit <= cutoffRemainder))
        {
            n = n * radix + digit;
        }
        else
        {
            m_pos++;

            while (ConvertDigit(m_buffer[m_pos], radix) != -1)
                m_pos++;

            RaiseError("integer is too large (%s)", std::string(&m_buffer[startPos], m_pos - startPos).c_str());
        }

        m_pos++;
    }

    return true;
}

// Asserts that the rest of the line is empty and moves to the next one.
void SymFile::ExpectEmptyRestOfLine()
{
    SkipWhitespace();

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
            RaiseWarning("file doesn't end with newline");
        else
            RaiseError("unexpected null character");
    }
    else if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        m_lineStart = m_pos;
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


void SymFile::SkipLine()
{
    while (m_buffer[m_pos] != 0 && m_buffer[m_pos] != '\n')
        m_pos++;

    if (m_buffer[m_pos] == '\n')
        m_pos++;
}

// Checks if we're at the end of the file.
bool SymFile::IsAtEnd()
{
    return (m_pos >= m_size);
}

void SymFile::HandleLangConditional(std::string lang)
{
    if (m_buffer[m_pos] != '#')
        return;

    m_pos++;

    if (CheckForDirective("begin"))
    {
        if (m_inLangConditional)
            RaiseError("already inside language conditional");

        SkipWhitespace();

        std::string label = GetLabel(false);

        if (label.length() == 0)
            RaiseError("no language name after #begin");

        ExpectEmptyRestOfLine();

        if (lang == label)
        {
            m_inLangConditional = true;
        }
        else
        {
            while (!IsAtEnd() && m_buffer[m_pos] != '#')
                SkipLine();

            if (m_buffer[m_pos] != '#')
                RaiseError("unterminated language conditional");

            m_pos++;

            if (!CheckForDirective("end"))
                RaiseError("expected #end");

            ExpectEmptyRestOfLine();
        }
    }
    else if (CheckForDirective("end"))
    {
        if (!m_inLangConditional)
            RaiseError("not inside language conditional");

        m_inLangConditional = false;

        ExpectEmptyRestOfLine();
    }
    else
    {
        RaiseError("unknown # directive");
    }
}

// Reports a diagnostic message.
void SymFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_filename.c_str(), m_lineNum, type, buffer);
}

#define DO_REPORT(type)                   \
do                                        \
{                                         \
    std::va_list args;                    \
    va_start(args, format);               \
    ReportDiagnostic(type, format, args); \
    va_end(args);                         \
} while (0)

// Reports an error diagnostic and terminates the program.
void SymFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void SymFile::RaiseWarning(const char* format, ...)
{
    DO_REPORT("warning");
}
