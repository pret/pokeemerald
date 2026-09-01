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

#include <cctype>
#include <cstdio>
#include <cstdarg>
#include <stdexcept>
#include <string>
#include <memory>
#include <cstring>
#include <cerrno>
#include "preproc.h"
#include "c_file.h"
#include "char_util.h"
#include "utf8.h"
#include "string_parser.h"
#include "io.h"

CFile::CFile(const char * filenameCStr, bool isStdin, const char * graphicsRootCStr)
{
    if (isStdin)
        m_location.filename = std::string{"<stdin>/"}.append(filenameCStr);
    else
        m_location.filename = std::string(filenameCStr);
    m_location.lineNum = 1;
    m_location.acceptLineMarker = isStdin;

    m_buffer = ReadFileToBuffer(filenameCStr, isStdin, &m_size);

    m_pos = 0;
    m_isStdin = isStdin;
    m_graphicsRoot = graphicsRootCStr;
    if (m_graphicsRoot.empty()) m_graphicsRoot = "./";
    if (m_graphicsRoot[m_graphicsRoot.length() - 1] != '/') m_graphicsRoot.push_back('/');
}

CFile::CFile(CFile&& other) : m_location(std::move(other.m_location))
{
    m_buffer = other.m_buffer;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_isStdin = other.m_isStdin;

    other.m_buffer = NULL;
}

CFile::~CFile()
{
    free(m_buffer);
}

void CFile::printf(const char *format, ...)
{
    std::va_list args;
    va_start(args, format);
    int n = vsnprintf(NULL, 0, format, args);
    va_end(args);

    char *s = new char[n + 1];
    va_start(args, format);
    std::vsnprintf(s, n + 1, format, args);
    va_end(args);
    m_output.append(s);
    delete[] s;
}

void CFile::putchar(char c)
{
    m_output.append(1, c);
}

void CFile::Preproc()
{
    char stringChar = 0;

    while (m_pos < m_size)
    {
        if (m_location.acceptLineMarker)
        {
            if (m_buffer[m_pos] == '#')
            {
                long hashPos = m_pos;

                long startPos;
                long lineNum;
                std::string filename;

                m_pos++;

                if (m_buffer[m_pos] != ' ')
                    goto linemarker_error;
                m_pos++;

                startPos = m_pos;
                if (!IsAsciiDigit(m_buffer[m_pos]))
                    goto linemarker_error;
                do
                    m_pos++;
                while (IsAsciiDigit(m_buffer[m_pos]));
                lineNum = atol(&m_buffer[startPos]);

                if (m_buffer[m_pos] != ' ')
                    goto linemarker_error;
                m_pos++;

                if (m_buffer[m_pos] != '"')
                    goto linemarker_error;
                m_pos++;

                startPos = m_pos;
                while (m_pos < m_size && m_buffer[m_pos] != '"')
                    m_pos++;
                filename = std::string(&m_buffer[startPos], m_pos - startPos);

                if (m_buffer[m_pos] != '"')
                    goto linemarker_error;
                m_pos++;

                while (m_pos < m_size && m_buffer[m_pos] != '\n')
                    m_pos++;
                if (m_buffer[m_pos] != '\n')
                    goto linemarker_error;
                m_pos++;

                m_location.lineNum = lineNum - 1;
                m_location.filename = std::move(filename);
linemarker_error:
                m_location.acceptLineMarker = false;
                // Re-parse this line so that it's available to cc1.
                m_pos = hashPos;
            }
            else if (!IsAsciiWhitespace(m_buffer[m_pos]))
            {
                m_location.acceptLineMarker = false;
            }
        }

        if (stringChar)
        {
            if (m_buffer[m_pos] == stringChar)
            {
                putchar(stringChar);
                m_pos++;
                stringChar = 0;
            }
            else if (m_buffer[m_pos] == '\\' && m_buffer[m_pos + 1] == stringChar)
            {
                putchar('\\');
                putchar(stringChar);
                m_pos += 2;
            }
            else
            {
                if (m_buffer[m_pos] == '\n')
                    Newline();
                putchar(m_buffer[m_pos]);
                m_pos++;
            }
        }
        else
        {
            TryConvertString();
            TryConvertCompoundString();
            TryConvertIncbin();
            TryConvertIncgfx();

            if (m_pos >= m_size)
                break;

            char c = m_buffer[m_pos++];

            putchar(c);

            if (c == '\n')
                Newline();
            else if (c == '"')
                stringChar = '"';
            else if (c == '\'')
                stringChar = '\'';
        }
    }

    // TODO: Share the tails of compound strings where possible (like the
    // 'ld' optimization for 'SHF_MERGE | SHF_STRINGS').
    for (auto it : m_compoundStrings)
    {
        // HINT: GCC puts the section name into the assembly without any
        // validation, so we're able to apply the 'SHF_MERGE' flag and
        // our own 'sh_entsize' by using '@' to comment out what GCC
        // would have put after the section name.
        // This will not work with Clang, see
        // https://discourse.llvm.org/t/creating-shf-merge-shf-strings-section/86399
        std::printf("static const unsigned char __attribute__((section(\".rodata.compound_string.%016" PRIx64 ",\\\"aM\\\",%%progbits,%ld @\"))) sCompoundString_%016" PRIx64 "[] = {", it.second, it.first.size(), it.second);
        if (it.first.size() > 0)
        {
            std::printf(" 0x%02X", it.first[0]);
            for (std::size_t i = 1; i < it.first.size(); i++)
                std::printf(", 0x%02X", it.first[i]);
        }
        std::printf(" };\n");
    }

    std::puts(m_output.c_str());
}

bool CFile::ConsumeHorizontalWhitespace()
{
    if (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
    {
        m_pos++;
        return true;
    }

    return false;
}

bool CFile::ConsumeNewline()
{
    if (m_buffer[m_pos] == '\r' && m_buffer[m_pos + 1] == '\n')
    {
        m_pos += 2;
        Newline();
        putchar('\n');
        return true;
    }

    if (m_buffer[m_pos] == '\n')
    {
        m_pos++;
        Newline();
        putchar('\n');
        return true;
    }

    return false;
}

void CFile::Newline()
{
    m_location.lineNum++;
    m_location.acceptLineMarker = m_isStdin;
}

void CFile::SkipWhitespace()
{
    while (ConsumeHorizontalWhitespace() || ConsumeNewline())
        ;
}

std::vector<unsigned char> CFile::ConvertString()
{
    std::vector<unsigned char> converted;

    while (true)
    {
        SkipWhitespace();

        if (m_buffer[m_pos] == '"')
        {
            unsigned char s[kMaxStringLength];
            int length = 0;
            StringParser stringParser(m_buffer, m_size);
            try
            {
                m_pos += stringParser.ParseString(m_pos, s, length);
            }
            catch (std::runtime_error& e)
            {
                RaiseError(e.what());
            }
            converted.insert(converted.end(), s, s + length);
        }
        else if (m_buffer[m_pos] == ')')
        {
            m_pos++;
            break;
        }
        else
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF");
            if (IsAsciiPrintable(m_buffer[m_pos]))
                RaiseError("unexpected character '%c'", m_buffer[m_pos]);
            else
                RaiseError("unexpected character '\\x%02X'", m_buffer[m_pos]);
        }
    }

    return converted;
}

void CFile::TryConvertString()
{
    long oldPos = m_pos;
    auto oldLocation = m_location;
    bool noTerminator = false;

    if (m_buffer[m_pos] != '_' || (m_pos > 0 && IsIdentifierChar(m_buffer[m_pos - 1])))
        return;

    m_pos++;

    if (m_buffer[m_pos] == '_')
    {
        noTerminator = true;
        m_pos++;
    }

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_location = oldLocation;
        return;
    }

    m_pos++;

    SkipWhitespace();

    printf("{ ");

    std::vector<unsigned char> converted = ConvertString();
    for (std::size_t i = 0; i < converted.size(); i++)
        printf("0x%02X, ", converted[i]);

    if (noTerminator)
        printf(" }");
    else
        printf("0xFF }");
}

static std::uint64_t fnv1a(const std::vector<unsigned char>& bytes)
{
    std::uint64_t hash = 0xcbf29ce484222325UL;
    for (auto b : bytes)
        hash = (hash ^ b) * 0x00000100000001b3UL;
    return hash;
}

void CFile::TryConvertCompoundString()
{
    long oldPos = m_pos;
    auto oldLocation = m_location;
    std::string ident = "COMPOUND_STRING";

    if ((m_pos > 0 && IsIdentifierChar(m_buffer[m_pos - 1])) || !CheckIdentifier(ident))
        return;

    m_pos += ident.length();

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_location = oldLocation;
        return;
    }

    m_pos++;
    std::vector<unsigned char> converted = ConvertString();
    converted.push_back(0xFF);

    std::uint64_t hash = fnv1a(converted);
    m_compoundStrings[converted] = hash;
    // WARNING: Assumes no collisions.
    // TODO: Incorporate filename to prevent cross-TU collisions.
    printf("sCompoundString_%016" PRIx64, hash);
}

bool CFile::CheckIdentifier(const std::string& ident)
{
    unsigned int i;

    for (i = 0; i < ident.length() && m_pos + i < (unsigned)m_size; i++)
        if (ident[i] != m_buffer[m_pos + i])
            return false;

    return (i == ident.length());
}

std::string CFile::ReadString()
{
    if (m_buffer[m_pos] != '"')
        RaiseError("expected '\"'");
    m_pos++;

    long startPos = m_pos;

    while (m_buffer[m_pos] != '"')
    {
        if (m_buffer[m_pos] == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF in string");
            else
                RaiseError("unexpected null character in string");
        }

        if (m_buffer[m_pos] == '\r' || m_buffer[m_pos] == '\n')
            RaiseError("unexpected end of line character in string");

        if (m_buffer[m_pos] == '\\')
            RaiseError("unexpected escape in string");

        m_pos++;
    }
    m_pos++;

    return std::string(&m_buffer[startPos], m_pos - 1 - startPos);
}

std::unique_ptr<unsigned char[]> CFile::ReadWholeFile(const std::string& path, int& size)
{
    FILE* fp = std::fopen(path.c_str(), "rb");

    if (fp == nullptr)
        RaiseError("Failed to open \"%s\" for reading.\n", path.c_str());

    std::fseek(fp, 0, SEEK_END);

    size = std::ftell(fp);

    std::unique_ptr<unsigned char[]> buffer = std::unique_ptr<unsigned char[]>(new unsigned char[size]);

    std::rewind(fp);

    if (std::fread(buffer.get(), size, 1, fp) != 1)
        RaiseError("Failed to read \"%s\".\n", path.c_str());

    std::fclose(fp);

    return buffer;
}

int ExtractData(const std::unique_ptr<unsigned char[]>& buffer, int offset, int size)
{
    switch (size)
    {
    case 1:
        return buffer[offset];
    case 2:
        return (buffer[offset + 1] << 8)
            | buffer[offset];
    case 4:
        return (buffer[offset + 3] << 24)
            | (buffer[offset + 2] << 16)
            | (buffer[offset + 1] << 8)
            | buffer[offset];
    default:
        FATAL_ERROR("Invalid size passed to ExtractData.\n");
    }
}

void CFile::TryConvertIncbin()
{
    std::string idents[4] = { "INCBIN_U8", "INCBIN_U16", "INCBIN_U32", "INCBIN_COMP"};
    int incbinType = -1;

    for (int i = 0; i < 4; i++)
    {
        if (CheckIdentifier(idents[i]))
        {
            incbinType = i;
            break;
        }
    }

    if (incbinType == -1)
        return;

    int size = incbinType < 3 ? 1 << incbinType : 4;

    long oldPos = m_pos;
    auto oldLocation = m_location;

    m_pos += idents[incbinType].length();

    SkipWhitespace();

    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_location = oldLocation;
        return;
    }

    m_pos++;

    printf("{");

    while (true)
    {
        SkipWhitespace();

        auto path = ReadString();

        // INCBIN_COMP; include *compressed* version of file
        if (incbinType == 3)
            path = path.append(".smol");

        int fileSize;
        std::unique_ptr<unsigned char[]> buffer = ReadWholeFile(path, fileSize);

        if ((fileSize % size) != 0)
            RaiseError("Size %d doesn't evenly divide file size %d.\n", size, fileSize);

        int count = fileSize / size;
        int offset = 0;

        for (int i = 0; i < count; i++)
        {
            int data = ExtractData(buffer, offset, size);
            offset += size;
            printf("%uu,", data);
        }

        SkipWhitespace();

        if (m_buffer[m_pos] != ',')
            break;

        m_pos++;
    }

    if (m_buffer[m_pos] != ')')
        RaiseError("expected ')'");

    m_pos++;

    printf("}");
}

void CFile::TryConvertIncgfx()
{
    if (!CheckIdentifier("INCGFX_"))
        return;

    std::string idents[4] = { "INCGFX_U8", "INCGFX_U16", "INCGFX_U32", "INCGFX_COMP" };
    int incgfxType = -1;

    for (int i = 0; i < 4; i++)
    {
        if (CheckIdentifier(idents[i]))
        {
            incgfxType = i;
            break;
        }
    }

    if (incgfxType == -1)
        return;

    int size = incgfxType < 3 ? 1 << incgfxType : 4;

    long oldPos = m_pos;
    auto oldLocation = m_location;

    m_pos += idents[incgfxType].length();

    SkipWhitespace();
    if (m_buffer[m_pos] != '(')
    {
        m_pos = oldPos;
        m_location = oldLocation;
        return;
    }
    m_pos++;

    SkipWhitespace();
    auto source = ReadString();

    SkipWhitespace();
    if (m_buffer[m_pos] != ',')
        RaiseError("expected ','");
    m_pos++;

    SkipWhitespace();
    auto extensions = ReadString();
    if (incgfxType == 3)
        extensions += ".smol";

    SkipWhitespace();
    std::string arguments;
    if (m_buffer[m_pos] == ',')
    {
        m_pos++;
        SkipWhitespace();
        arguments = ReadString();

        SkipWhitespace();
        if (m_buffer[m_pos] != ')')
            RaiseError("expected ')'");
        m_pos++;
    }
    else if (m_buffer[m_pos] == ')')
    {
        m_pos++;
    }
    else
    {
        RaiseError("exected ')' or ','");
    }

    // WARNING: This must stay in-sync with 'tools/scaninc/source_file.cpp'.
    std::string arguments_as_path;
    for (auto c : arguments)
    {
        if (std::isalnum(c))
            arguments_as_path += c;
        else
            arguments_as_path += '_';
    }

    // WARNING: This must stay in-sync with 'tools/scaninc/scaninc.cpp'.
    auto converted = m_graphicsRoot + source + arguments_as_path + extensions;

    int fileSize;
    std::unique_ptr<unsigned char[]> buffer = ReadWholeFile(converted, fileSize);

    if ((fileSize % size) != 0)
        RaiseError("Size %d doesn't evenly divide file size %d.\n", size, fileSize);

    printf("{");

    int count = fileSize / size;
    int offset = 0;
    for (int i = 0; i < count; i++)
    {
        int data = ExtractData(buffer, offset, size);
        offset += size;
        printf("%uu,", data);
    }

    printf("}");
}

// Reports a diagnostic message.
void CFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_location.filename.c_str(), m_location.lineNum, type, buffer);
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
void CFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void CFile::RaiseWarning(const char* format, ...)
{
    DO_REPORT("warning");
}
