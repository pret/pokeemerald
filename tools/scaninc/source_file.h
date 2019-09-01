// Copyright(c) 2019 Phlosioneer
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

#ifndef SOURCE_FILE_H
#define SOURCE_FILE_H

#include <string>
#include "scaninc.h"
#include "asm_file.h"
#include "c_file.h"

enum class SourceFileType
{
    Cpp,
    Header,
    Asm,
    Inc
};

SourceFileType GetFileType(std::string& path);

class SourceFile
{
public:

    SourceFile(std::string path);
    ~SourceFile();
    SourceFile(SourceFile const&) = delete;
    SourceFile(SourceFile&&) = delete;
    SourceFile& operator =(SourceFile const&) = delete;
    SourceFile& operator =(SourceFile&&) = delete;
    bool HasIncbins();
    const std::set<std::string>& GetIncbins();
    const std::set<std::string>& GetIncludes();
    std::string& GetSrcDir();
    SourceFileType FileType();

private:
    union InnerUnion {
        CFile c_file;
        struct AsmWrapper {
            std::set<std::string> asm_incbins;
            std::set<std::string> asm_includes;
        } asm_wrapper;

        // Construction and destruction handled by SourceFile.
        InnerUnion() {};
        ~InnerUnion() {};
    } m_source_file;
    SourceFileType m_file_type;
    std::string m_src_dir;
};

#endif // SOURCE_FILE_H

