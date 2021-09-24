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
#include <cstdlib>
#include <list>
#include <queue>
#include <set>
#include <string>
#include "scaninc.h"
#include "source_file.h"

bool CanOpenFile(std::string path)
{
    FILE *fp = std::fopen(path.c_str(), "rb");

    if (fp == NULL)
        return false;

    std::fclose(fp);
    return true;
}

const char *const USAGE = "Usage: scaninc [-I INCLUDE_PATH] FILE_PATH\n";

int main(int argc, char **argv)
{
    std::queue<std::string> filesToProcess;
    std::set<std::string> dependencies;

    std::vector<std::string> includeDirs;

    argc--;
    argv++;

    while (argc > 1)
    {
        std::string arg(argv[0]);
        if (arg.substr(0, 2) == "-I")
        {
            std::string includeDir = arg.substr(2);
            if (includeDir.empty())
            {
                argc--;
                argv++;
                includeDir = std::string(argv[0]);
            }
            if (!includeDir.empty() && includeDir.back() != '/')
            {
                includeDir += '/';
            }
            includeDirs.push_back(includeDir);
        }
        else
        {
            FATAL_ERROR(USAGE);
        }
        argc--;
        argv++;
    }

    if (argc != 1) {
        FATAL_ERROR(USAGE);
    }

    std::string initialPath(argv[0]);

    filesToProcess.push(initialPath);

    while (!filesToProcess.empty())
    {
        std::string filePath = filesToProcess.front();
        SourceFile file(filePath);
        filesToProcess.pop();

        includeDirs.push_back(file.GetSrcDir());
        for (auto incbin : file.GetIncbins())
        {
            dependencies.insert(incbin);
        }
        for (auto include : file.GetIncludes())
        {
            bool exists = false;
            std::string path("");
            for (auto includeDir : includeDirs)
            {
                path = includeDir + include;
                if (CanOpenFile(path))
                {
                    exists = true;
                    break;
                }
            }
            if (!exists && (file.FileType() == SourceFileType::Asm || file.FileType() == SourceFileType::Inc))
            {
                path = include;
            }
            bool inserted = dependencies.insert(path).second;
            if (inserted && exists)
            {
                filesToProcess.push(path);
            }
        }
        includeDirs.pop_back();
    }

    for (const std::string &path : dependencies)
    {
        std::printf("%s\n", path.c_str());
    }
}
