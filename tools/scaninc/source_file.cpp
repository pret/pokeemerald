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

#include <new>
#include "source_file.h"


SourceFileType GetFileType(std::string& path)
{
    std::size_t pos = path.find_last_of('.');

    if (pos == std::string::npos)
        FATAL_ERROR("no file extension in path \"%s\"\n", path.c_str());

    std::string extension = path.substr(pos + 1);

    if (extension == "c")
        return SourceFileType::Cpp;
    else if (extension == "s")
        return SourceFileType::Asm;
    else if (extension == "h")
        return SourceFileType::Header;
    else if (extension == "inc")
        return SourceFileType::Inc;
    else
        FATAL_ERROR("Unrecognized extension \"%s\"\n", extension.c_str());

    // Unreachable
    return SourceFileType::Cpp;
}

std::string GetDir(std::string& path)
{
    std::size_t slash = path.rfind('/');

    if (slash != std::string::npos)
        return path.substr(0, slash + 1);
    else
        return std::string("");
}

SourceFile::SourceFile(std::string path)
{
    m_file_type = GetFileType(path);

    m_src_dir = GetDir(path);

    if (m_file_type == SourceFileType::Cpp
            || m_file_type == SourceFileType::Header)
    {
        new (&m_source_file.c_file) CFile(path);
        m_source_file.c_file.FindIncbins();
    }
    else
    {
        AsmFile file(path);
        std::set<std::string> incbins;
        std::set<std::string> includes;

        IncDirectiveType incDirectiveType;
        std::string outputPath;

        while ((incDirectiveType = file.ReadUntilIncDirective(outputPath)) != IncDirectiveType::None)
        {
            if (incDirectiveType == IncDirectiveType::Include)
                includes.insert(outputPath);
            else
                incbins.insert(outputPath);
        }

        new (&m_source_file.asm_wrapper) SourceFile::InnerUnion::AsmWrapper{incbins, includes};
    }
}

SourceFileType SourceFile::FileType()
{
    return m_file_type;
}

SourceFile::~SourceFile()
{
    if (m_file_type == SourceFileType::Cpp || m_file_type == SourceFileType::Header)
    {
        m_source_file.c_file.~CFile();
    }
    else
    {
        m_source_file.asm_wrapper.asm_incbins.~set();
        m_source_file.asm_wrapper.asm_includes.~set();
    }
}

const std::set<std::string>& SourceFile::GetIncbins()
{
    if (m_file_type == SourceFileType::Cpp || m_file_type == SourceFileType::Header)
        return m_source_file.c_file.GetIncbins();
    else
        return m_source_file.asm_wrapper.asm_incbins;
}

const std::set<std::string>& SourceFile::GetIncludes()
{
    if (m_file_type == SourceFileType::Cpp || m_file_type == SourceFileType::Header)
        return m_source_file.c_file.GetIncludes();
    else
        return m_source_file.asm_wrapper.asm_includes;
}

std::string& SourceFile::GetSrcDir()
{
    return m_src_dir;
}

