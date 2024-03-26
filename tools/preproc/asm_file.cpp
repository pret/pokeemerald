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
#include <stdexcept>
#include "preproc.h"
#include "asm_file.h"
#include "char_util.h"
#include "utf8.h"
#include "string_parser.h"
#include "../../gflib/characters.h"

static int asmFileIdentifier;

AsmFile::AsmFile(std::string filename) : m_filename(filename)
{
    FILE *fp = std::fopen(filename.c_str(), "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open \"%s\" for reading.\n", filename.c_str());

    std::fseek(fp, 0, SEEK_END);

    m_size = std::ftell(fp);

    if (m_size < 0)
        FATAL_ERROR("File size of \"%s\" is less than zero.\n", filename.c_str());
    else if (m_size == 0)
        return; // Empty file

    m_buffer = new char[m_size + 1];

    std::rewind(fp);

    if (std::fread(m_buffer, m_size, 1, fp) != 1)
        FATAL_ERROR("Failed to read \"%s\".\n", filename.c_str());

    m_buffer[m_size] = 0;

    std::fclose(fp);

    m_pos = 0;
    m_lineNum = 1;
    m_lineStart = 0;
    m_curNonLocalLabel = std::string{"_.L"}.append(std::to_string(asmFileIdentifier));
    asmFileIdentifier++;
    m_nonLocalLabelFound = false;
    RemoveComments();
}

AsmFile::AsmFile(AsmFile&& other) : m_filename(std::move(other.m_filename))
{
    m_buffer = other.m_buffer;
    m_pos = other.m_pos;
    m_size = other.m_size;
    m_lineNum = other.m_lineNum;
    m_lineStart = other.m_lineStart;
    m_curNonLocalLabel = other.m_curNonLocalLabel;
    m_nonLocalLabelFound = other.m_nonLocalLabelFound;
    m_localLabels = other.m_localLabels;
    m_identified = false;

    other.m_buffer = nullptr;
}

AsmFile::~AsmFile()
{
    if (m_size > 0) delete[] m_buffer;
}

void AsmFile::TryPrintErrorHeaderMessage ()
{
    if (this->m_identified) {
        return;
    }

    fprintf(stderr, "\n%s: Preproc messages\n", this->m_filename.c_str());
    this->m_identified = true;
}

void AsmFile::RaiseErrorWhereButContinue (long lineNum, const char * format, ...)
{
    this->TryPrintErrorHeaderMessage();

    std::va_list args;
    va_start(args, format);
    this->ReportDiagnosticWhere("error", lineNum, format, args);
    va_end(args);

    Preproc::numErrors++;
}

void AsmFile::RaiseErrorButContinue (const char * format, ...)
{
    this->TryPrintErrorHeaderMessage();

    std::va_list args;
    va_start(args, format);
    this->ReportDiagnostic("error", format, args);
    va_end(args);

    Preproc::numErrors++;
}

// Removes comments to simplify further processing.
// It stops upon encountering a null character,
// which may or may not be the end of file marker.
// If it's not, the error will be caught later.
void AsmFile::RemoveComments()
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
        else if (
            (m_buffer[pos] == '@' && (pos == 0 || m_buffer[pos - 1] != '\\'))
            || (m_buffer[pos] == '/' && m_buffer[pos + 1] == '/'))
        {
            while (m_buffer[pos] != '\n' && m_buffer[pos] != 0)
                m_buffer[pos++] = ' ';
        }
        else if (m_buffer[pos] == '/' && m_buffer[pos + 1] == '*')
        {
            m_buffer[pos++] = ' ';
            m_buffer[pos++] = ' ';

            for (;;)
            {
                if (m_buffer[pos] == 0)
                    return;

                if (m_buffer[pos] == '*' && m_buffer[pos + 1] == '/')
                {
                    m_buffer[pos++] = ' ';
                    m_buffer[pos++] = ' ';
                    break;
                }
                else
                {
                    if (m_buffer[pos] != '\n')
                        m_buffer[pos] = ' ';
                    pos++;
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
bool AsmFile::CheckForDirective(std::string name)
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
Directive AsmFile::GetDirective()
{
    SkipWhitespace();

    if (CheckForDirective(".include"))
        return Directive::Include;
    else if (CheckForDirective(".string"))
        return Directive::String;
    else if (CheckForDirective(".braille"))
        return Directive::Braille;
    else
        return Directive::Unknown;
}

LocalLabelInfo::LocalLabelInfo ()
{
    this->defined = true;
}

LocalLabelInfo::LocalLabelInfo (long lineNum)
{
    this->defined = false;
    this->lineNums.emplace(lineNum);
}

// scan each line
// if nonlocal label define:
//  go through each local label found
//  if not defined, print error
//  then set the current nonlocal label
// if local label define:
//  replace local label with nonlocal label equivalent
//  set local label as defined
// if local label in statement:
//  replace local label with nonlocal label equivalent
//  add line number of reference

// Check if we're parsing a label
// the label is a global label if it ends with ::
// the label is a local label if it starts with the local label prefix (currently '$', but check char_util.h) and ends with :
// the label is a nonlocal label if it ends with :
// otherwise, it is not a label
// returns the type of label, and sets the argument pointer to the resulting label string
LabelType AsmFile::TryParseLabel(std::string& returnLabel)
{
    //SkipWhitespace();

    long start = m_pos;
    long pos = m_pos;

    if (IsCharGnuAssemblerNameBeginner(m_buffer[pos]))
    {
        bool isLocalLabel = false;

        if (m_buffer[pos] == LOCAL_LABEL_PREFIX) {
            isLocalLabel = true;
        }

        pos++;

        while (IsPartOfGnuAssemblerName(m_buffer[pos]))
            pos++;

        //
        if (m_buffer[pos] == ':')
        {
            std::size_t newSize = pos - start;
            returnLabel.resize(newSize);
            returnLabel.replace(0, newSize, &m_buffer[start], newSize);

            if (!isLocalLabel) {
                this->FindUndefinedLocalLabelsThenClear();
                this->m_curNonLocalLabel = returnLabel;
                this->m_nonLocalLabelFound = true;
            } else {
                auto localLabelInfo = this->m_localLabels.find(returnLabel);
                if (localLabelInfo == this->m_localLabels.end()) {
                    this->m_localLabels.emplace(returnLabel, LocalLabelInfo());
                } else {
                    if (!localLabelInfo->second.defined) {
                        localLabelInfo->second.defined = true;
                    } else {
                        this->RaiseErrorButContinue("local label %s is already defined", returnLabel.c_str());
                    }
                }
            }

            LabelType labelType;

            if (m_buffer[pos + 1] == ':') {
                if (!isLocalLabel) {
                    labelType = LabelType::Global;
                } else {
                    this->RaiseErrorButContinue("local label %s cannot be made global (change :: to :)", returnLabel.c_str());
                    labelType = LabelType::Local;
                }
                m_pos = pos + 2;
            } else {
                if (isLocalLabel) {
                    labelType = LabelType::Local;
                } else {
                    labelType = LabelType::Nonlocal;
                }
                m_pos = pos + 1;
            }

            if (isLocalLabel) {
                if (!this->m_nonLocalLabelFound) {
                    this->RaiseErrorButContinue("local label %s defined before non-local label", returnLabel.c_str());
                }
                returnLabel.insert(0, this->m_curNonLocalLabel);
            }

            ExpectEmptyRestOfLine();
            return labelType;
        }
    }

    return LabelType::NotALabel;
}

void AsmFile::FindUndefinedLocalLabelsThenClear ()
{
    for (auto const& localLabel : this->m_localLabels) {
        if (!localLabel.second.defined) {
            for (long lineNum : localLabel.second.lineNums) {
                this->RaiseErrorWhereButContinue(lineNum, "local label %s was not defined within its scope", localLabel.first.c_str());
            }
        }
    }

    this->m_localLabels.clear();
}

// return true if a local label was replaced
void AsmFile::FindAndReplaceLocalLabels (std::string& outputLine)
{
    // first check if the prefix is in the line at all
    // to avoid allocating a string

    long pos = m_pos;
    unsigned char c;
    bool foundLocalLabelPrefix = false;

    while (true) {
        c = m_buffer[pos];
        if (c == '\n' || c == '\0') {
            break;
        } else if (c == LOCAL_LABEL_PREFIX) {
            foundLocalLabelPrefix = true;
            break;
        }
        pos++;
    }

    if (!foundLocalLabelPrefix) {
        if (c == '\0') {
            if (pos >= m_size) {
                this->RaiseWarning("file doesn't end with newline");
                puts(&m_buffer[m_lineStart]);
            } else {
                this->RaiseError("unexpected null character");
            }
            m_pos = pos;
        } else {
            m_buffer[pos] = '\0';
            puts(&m_buffer[m_lineStart]);
            m_buffer[pos] = '\n';
            m_pos = pos;
            m_pos++;
            m_lineStart = m_pos;
            m_lineNum++;
        }
        return;
    }

    outputLine.resize(0);

    // a local label can start after any non-name character
    bool canStartLocalLabel = true;

    while (true) {
        c = m_buffer[m_pos];
        //isParsingNonNameChars = IsPartOfGnuAssemblerName(c);

        if (c == LOCAL_LABEL_PREFIX && canStartLocalLabel) {
            outputLine += this->m_curNonLocalLabel;
            //outputLine += LOCAL_LABEL_PREFIX;
            m_pos++;
            bool justFoundLocalLabelPrefix = true;

            long start = m_pos;
            while (true) {
                c = m_buffer[m_pos];
                if (!IsPartOfGnuAssemblerName(c)) {
                    if (justFoundLocalLabelPrefix) {
                        this->RaiseErrorButContinue("local label prefix \"%c\" must be followed by a label name", LOCAL_LABEL_PREFIX);
                    }
                    break;
                }
                justFoundLocalLabelPrefix = false;
                m_pos++;
            }

            std::string localLabelName = std::string(&m_buffer[start - 1], m_pos - start + 1); 
            auto localLabelInfo = this->m_localLabels.find(localLabelName);
            if (localLabelInfo == this->m_localLabels.end()) {
                this->m_localLabels.emplace(localLabelName, LocalLabelInfo(this->m_lineNum));
            // only add line numbers if the label isn't defined
            // as they're only used for reporting errors
            } else if (!localLabelInfo->second.defined) {
                std::set<long> * lineNums = &localLabelInfo->second.lineNums;
                lineNums->emplace_hint(lineNums->end(), this->m_lineNum);
            }

            outputLine += localLabelName;

            if (c == '\n' || c == '\0') {
                break;
            }
        } else if (c == '\n' || c == '\0') {
            break;
        } else {
            canStartLocalLabel = !IsPartOfGnuAssemblerName(c);
            outputLine += c;
        }
        m_pos++;        
    }

    if (c == '\0') {
        if (m_pos >= m_size) {
            this->RaiseWarning("file doesn't end with newline");
            puts(&m_buffer[m_lineStart]);
        } else {
            this->RaiseError("unexpected null character");
        }
    } else {
        puts(outputLine.c_str());
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
}

// Skips tabs and spaces.
void AsmFile::SkipWhitespace()
{
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
        m_pos++;
}

// Reads include path.
std::string AsmFile::ReadPath()
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

    ExpectEmptyRestOfLine();

    return std::string(&m_buffer[startPos], length);
}

// Reads a charmap string.
int AsmFile::ReadString(unsigned char* s)
{
    SkipWhitespace();

    int length;
    StringParser stringParser(m_buffer, m_size);

    try
    {
        m_pos += stringParser.ParseString(m_pos, s, length);
    }
    catch (std::runtime_error& e)
    {
        RaiseError(e.what());
    }

    SkipWhitespace();

    if (ConsumeComma())
    {
        SkipWhitespace();
        int padLength = ReadPadLength();

        while (length < padLength)
        {
            s[length++] = CHAR_SPACE;
        }
    }

    ExpectEmptyRestOfLine();

    return length;
}

void AsmFile::VerifyStringLength(int length)
{
    if (length == kMaxStringLength)
        RaiseError("mapped string longer than %d bytes", kMaxStringLength);
}

int AsmFile::ReadBraille(unsigned char* s)
{
    static std::map<char, unsigned char> encoding =
    {
        { 'A', BRAILLE_CHAR_A },
        { 'B', BRAILLE_CHAR_B },
        { 'C', BRAILLE_CHAR_C },
        { 'D', BRAILLE_CHAR_D },
        { 'E', BRAILLE_CHAR_E },
        { 'F', BRAILLE_CHAR_F },
        { 'G', BRAILLE_CHAR_G },
        { 'H', BRAILLE_CHAR_H },
        { 'I', BRAILLE_CHAR_I },
        { 'J', BRAILLE_CHAR_J },
        { 'K', BRAILLE_CHAR_K },
        { 'L', BRAILLE_CHAR_L },
        { 'M', BRAILLE_CHAR_M },
        { 'N', BRAILLE_CHAR_N },
        { 'O', BRAILLE_CHAR_O },
        { 'P', BRAILLE_CHAR_P },
        { 'Q', BRAILLE_CHAR_Q },
        { 'R', BRAILLE_CHAR_R },
        { 'S', BRAILLE_CHAR_S },
        { 'T', BRAILLE_CHAR_T },
        { 'U', BRAILLE_CHAR_U },
        { 'V', BRAILLE_CHAR_V },
        { 'W', BRAILLE_CHAR_W },
        { 'X', BRAILLE_CHAR_X },
        { 'Y', BRAILLE_CHAR_Y },
        { 'Z', BRAILLE_CHAR_Z },
        { 'a', BRAILLE_CHAR_A },
        { 'b', BRAILLE_CHAR_B },
        { 'c', BRAILLE_CHAR_C },
        { 'd', BRAILLE_CHAR_D },
        { 'e', BRAILLE_CHAR_E },
        { 'f', BRAILLE_CHAR_F },
        { 'g', BRAILLE_CHAR_G },
        { 'h', BRAILLE_CHAR_H },
        { 'i', BRAILLE_CHAR_I },
        { 'j', BRAILLE_CHAR_J },
        { 'k', BRAILLE_CHAR_K },
        { 'l', BRAILLE_CHAR_L },
        { 'm', BRAILLE_CHAR_M },
        { 'n', BRAILLE_CHAR_N },
        { 'o', BRAILLE_CHAR_O },
        { 'p', BRAILLE_CHAR_P },
        { 'q', BRAILLE_CHAR_Q },
        { 'r', BRAILLE_CHAR_R },
        { 's', BRAILLE_CHAR_S },
        { 't', BRAILLE_CHAR_T },
        { 'u', BRAILLE_CHAR_U },
        { 'v', BRAILLE_CHAR_V },
        { 'w', BRAILLE_CHAR_W },
        { 'x', BRAILLE_CHAR_X },
        { 'y', BRAILLE_CHAR_Y },
        { 'z', BRAILLE_CHAR_Z },
        { '0', BRAILLE_CHAR_0 },
        { '1', BRAILLE_CHAR_1 },
        { '2', BRAILLE_CHAR_2 },
        { '3', BRAILLE_CHAR_3 },
        { '4', BRAILLE_CHAR_4 },
        { '5', BRAILLE_CHAR_5 },
        { '6', BRAILLE_CHAR_6 },
        { '7', BRAILLE_CHAR_7 },
        { '8', BRAILLE_CHAR_8 },
        { '9', BRAILLE_CHAR_9 },
        { ' ', BRAILLE_CHAR_SPACE },
        { ',', BRAILLE_CHAR_COMMA },
        { '.', BRAILLE_CHAR_PERIOD },
        { '?', BRAILLE_CHAR_QUESTION_MARK },
        { '!', BRAILLE_CHAR_EXCL_MARK },
        { ':', BRAILLE_CHAR_COLON },
        { ';', BRAILLE_CHAR_SEMICOLON },
        { '-', BRAILLE_CHAR_HYPHEN },
        { '/', BRAILLE_CHAR_SLASH },
        { '(', BRAILLE_CHAR_PAREN },
        { ')', BRAILLE_CHAR_PAREN },
        { '\'', BRAILLE_CHAR_APOSTROPHE },
        { '#', BRAILLE_CHAR_NUMBER },
        { '$', EOS },
    };

    SkipWhitespace();

    int length = 0;

    if (m_buffer[m_pos] != '"')
        RaiseError("expected braille string literal");

    m_pos++;

    bool inNumber = false;
    while (m_buffer[m_pos] != '"')
    {
        if (m_buffer[m_pos] == '\\' && m_buffer[m_pos + 1] == 'n')
        {
            VerifyStringLength(length);
            s[length++] = CHAR_NEWLINE;
            m_pos += 2;
        }
        else
        {
            char c = m_buffer[m_pos];

            if (encoding.count(c) == 0)
            {
                if (IsAsciiPrintable(c))
                    RaiseError("character '%c' not valid in braille string", m_buffer[m_pos]);
                else
                    RaiseError("character '\\x%02X' not valid in braille string", m_buffer[m_pos]);
            }

            if (!inNumber && c >= '0' && c <= '9' )
            {
                // Output number indicator at start of a number
                inNumber = true;
                VerifyStringLength(length);
                s[length++] = BRAILLE_CHAR_NUMBER;
            }
            else if (inNumber && encoding[c] == BRAILLE_CHAR_SPACE)
            {
                // Number ends at a space.
                // Non-number characters encountered before a space will simply be output as is.
                inNumber = false;
            }

            VerifyStringLength(length);
            s[length++] = encoding[c];
            m_pos++;
        }
    }

    m_pos++; // Go past the right quote.

    ExpectEmptyRestOfLine();

    return length;
}

// If we're at a comma, consumes it.
// Returns whether a comma was found.
bool AsmFile::ConsumeComma()
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

// Reads an integer. If the integer is greater than maxValue, it returns -1.
int AsmFile::ReadPadLength()
{
    if (!IsAsciiDigit(m_buffer[m_pos]))
        RaiseError("expected integer");

    int radix = 10;

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        radix = 16;
        m_pos += 2;
    }

    unsigned n = 0;
    int digit;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;

        if (n > kMaxStringLength)
            RaiseError("pad length greater than maximum length (%d)", kMaxStringLength);

        m_pos++;
    }

    return n;
}

// Outputs the current line and moves to the next one.
void AsmFile::OutputLine()
{
    while (m_buffer[m_pos] != '\n' && m_buffer[m_pos] != 0)
        m_pos++;

    if (m_buffer[m_pos] == 0)
    {
        if (m_pos >= m_size)
        {
            RaiseWarning("file doesn't end with newline");
            puts(&m_buffer[m_lineStart]);
        }
        else
        {
            RaiseError("unexpected null character");
        }
    }
    else
    {
        m_buffer[m_pos] = 0;
        puts(&m_buffer[m_lineStart]);
        m_buffer[m_pos] = '\n';
        m_pos++;
        m_lineStart = m_pos;
        m_lineNum++;
    }
}

// Asserts that the rest of the line is empty and moves to the next one.
void AsmFile::ExpectEmptyRestOfLine()
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
    else if (m_buffer[m_pos] == '\r' && m_buffer[m_pos + 1] == '\n')
    {
        m_pos += 2;
        m_lineStart = m_pos;
        m_lineNum++;
    }
    else
    {
        RaiseError("junk at end of line");
    }
}

// Checks if we're at the end of the file.
bool AsmFile::IsAtEnd()
{
    return (m_pos >= m_size);
}

// Output the current location to set gas's logical file and line numbers.
void AsmFile::OutputLocation()
{
    std::printf("# %ld \"%s\"\n", m_lineNum, m_filename.c_str());
}

// Reports a diagnostic message.
void AsmFile::ReportDiagnostic(const char* type, const char* format, std::va_list args)
{
    this->ReportDiagnosticWhere(type, this->m_lineNum, format, args);
}

// Reports a diagnostic message, but with a custom line number
void AsmFile::ReportDiagnosticWhere(const char* type, long lineNum, const char* format, std::va_list args)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];
    std::vsnprintf(buffer, bufferSize, format, args);
    std::fprintf(stderr, "%s:%ld: %s: %s\n", m_filename.c_str(), lineNum, type, buffer);
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
void AsmFile::RaiseError(const char* format, ...)
{
    DO_REPORT("error");
    std::exit(1);
}

// Reports a warning diagnostic.
void AsmFile::RaiseWarning(const char* format, ...)
{
    this->TryPrintErrorHeaderMessage();
    DO_REPORT("warning");
}
