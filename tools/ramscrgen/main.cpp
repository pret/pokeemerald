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
#include <cstring>
#include <string>
#include "ramscrgen.h"
#include "sym_file.h"
#include "elf.h"

void HandleCommonInclude(std::string filename, std::string sourcePath, std::string symOrderPath, std::string lang)
{
    auto commonSymbols = GetCommonSymbols(sourcePath, filename);

    for (const auto& commonSym : commonSymbols)
    {
        unsigned long size = commonSym.second;

        int alignment = 4;
        if (size > 4)
            alignment = 8;
        if (size > 8)
            alignment = 16;
        printf(". = ALIGN(%d);\n", alignment);
        printf("%s = .;\n", commonSym.first.c_str());
        printf(". += 0x%lX;\n", size);
    }
}

void ConvertSymFile(std::string filename, std::string sectionName, std::string lang, bool common, std::string sourcePath, std::string commonSymPath, std::string libSourcePath)
{
    SymFile symFile(filename);

    while (!symFile.IsAtEnd())
    {
        symFile.HandleLangConditional(lang);

        Directive directive = symFile.GetDirective();

        switch (directive)
        {
        case Directive::Include:
        {
            std::string incFilename = symFile.ReadPath();
            symFile.ExpectEmptyRestOfLine();
            printf(". = ALIGN(4);\n");
            if (common)
                HandleCommonInclude(incFilename, incFilename[0] == '*' ? libSourcePath : sourcePath, commonSymPath, lang);
            else
                printf("%s(%s);\n", incFilename.c_str(), sectionName.c_str());
            break;
        }
        case Directive::Space:
        {
            unsigned long length;
            if (!symFile.ReadInteger(length))
                symFile.RaiseError("expected integer after .space directive");
            symFile.ExpectEmptyRestOfLine();
            printf(". += 0x%lX;\n", length);
            break;
        }
        case Directive::Align:
        {
            unsigned long amount;
            if (!symFile.ReadInteger(amount))
                symFile.RaiseError("expected integer after .align directive");
            if (amount > 4)
                symFile.RaiseError("max alignment amount is 4");
            amount = 1UL << amount;
            symFile.ExpectEmptyRestOfLine();
            printf(". = ALIGN(%lu);\n", amount);
            break;
        }
        case Directive::Unknown:
        {
            std::string label = symFile.GetLabel();

            if (label.length() != 0)
            {
                printf("%s = .;\n", label.c_str());
            }

            symFile.ExpectEmptyRestOfLine();

            break;
        }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s SECTION_NAME SYM_FILE LANG [-c SRC_PATH,COMMON_SYM_PATH]", argv[0]);
        return 1;
    }

    bool common = false;
    std::string sectionName = std::string(argv[1]);
    std::string symFileName = std::string(argv[2]);
    std::string lang = std::string(argv[3]);
    std::string sourcePath;
    std::string commonSymPath;
    std::string libSourcePath;

    if (argc > 4)
    {
        if (std::strcmp(argv[4], "-c") != 0)
            FATAL_ERROR("error: unrecognized argument \"%s\"\n", argv[4]);

        if (argc < 6)
            FATAL_ERROR("error: missing SRC_PATH,COMMON_SYM_PATH after \"-c\"\n");

        common = true;
        std::string paths = std::string(argv[5]);
        std::size_t commaPos = paths.find(',');

        if (commaPos == std::string::npos)
            FATAL_ERROR("error: missing comma in argument after \"-c\"\n");

        sourcePath = paths.substr(0, commaPos);
        commonSymPath = paths.substr(commaPos + 1);
        commaPos = commonSymPath.find(',');
        if (commaPos == std::string::npos) {
            libSourcePath = "tools/agbcc/lib";
        } else {
            libSourcePath = commonSymPath.substr(commaPos + 1);
            commonSymPath = commonSymPath.substr(0, commaPos);
        }
    }

    ConvertSymFile(symFileName, sectionName, lang, common, sourcePath, commonSymPath, libSourcePath);
    return 0;
}
