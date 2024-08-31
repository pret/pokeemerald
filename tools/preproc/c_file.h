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

#ifndef C_FILE_H
#define C_FILE_H

#include <cstdarg>
#include <cstdint>
#include <string>
#include <memory>
#include "preproc.h"

class CFile
{
public:
    CFile(const char * filenameCStr, bool isStdin);
    CFile(CFile&& other);
    CFile(const CFile&) = delete;
    ~CFile();
    void Preproc();

private:
    char* m_buffer;
    long m_pos;
    long m_size;
    long m_lineNum;
    std::string m_filename;
    bool m_isStdin;

    bool ConsumeHorizontalWhitespace();
    bool ConsumeNewline();
    void SkipWhitespace();
    void TryConvertString();
    std::unique_ptr<unsigned char[]> ReadWholeFile(const std::string& path, int& size);
    bool CheckIdentifier(const std::string& ident);
    void TryConvertIncbin();
    void ReportDiagnostic(const char* type, const char* format, std::va_list args);
    void RaiseError(const char* format, ...);
    void RaiseWarning(const char* format, ...);
};

#endif // C_FILE_H
