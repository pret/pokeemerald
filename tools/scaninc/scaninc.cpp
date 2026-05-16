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

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <iostream>
#include <tuple>
#include <fstream>
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

const char *const USAGE = "Usage: scaninc [-I INCLUDE_PATH] [-M DEPENDENCY_OUT_PATH] [-g PATH] FILE_PATH\n";

int main(int argc, char **argv)
{
    std::queue<std::string> filesToProcess;
    std::set<std::string> dependencies;
    std::set<std::string> dependencies_includes;
    std::map<std::string, std::pair<std::string, std::string>> dependencies_gfx_rules;

    std::vector<std::string> includeDirs;

    bool makeformat = false;
    std::string make_outfile;
    std::string gfx_root;

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
        else if(arg.substr(0, 2) == "-M")
        {
            makeformat = true;
            argc--;
            argv++;
            make_outfile = std::string(argv[0]);
        }
        else if (arg.substr(0, 2) == "-g")
        {
            argc--;
            argv++;
            gfx_root = std::string(argv[0]);
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

    size_t ext_pos = make_outfile.find_last_of(".");
    auto object_file = make_outfile.substr(0, ext_pos + 1) + "o";
    if (gfx_root.empty()) gfx_root = "./";
    if (gfx_root[gfx_root.length() - 1] != '/') gfx_root.push_back('/');

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
        for (auto incgfx : file.GetIncgfxs())
        {
            // WARNING: This must stay in-sync with 'tools/preproc/c_file.cpp'.
            std::string arguments_as_path;
            for (auto c : incgfx.arguments)
            {
                if (std::isalnum(c))
                    arguments_as_path += c;
                else
                    arguments_as_path += '_';
            }

            // WARNING: This must stay in-sync with 'tools/preproc/c_file.cpp'.
            auto target = gfx_root + incgfx.source + arguments_as_path + incgfx.extensions;
            size_t target_slash_pos = target.find_last_of('/');
            auto mk_target_basedir = target_slash_pos == std::string::npos
                ? ""
                : "\t@mkdir -p '" + target.substr(0, target_slash_pos) + "'\n";
            auto rule = mk_target_basedir + "\t$(GFX) $< $@ " + incgfx.arguments + "\n";

            dependencies.insert(target);

            // If "foo.4bpp.lz" we want a rule for "foo.4bpp", the ".lz"
            // doesn't require any arguments.
            size_t dot_pos = incgfx.extensions.find_first_of('.', 1);
            auto firstTarget = gfx_root + incgfx.source + arguments_as_path + incgfx.extensions.substr(0, dot_pos);
            dependencies_gfx_rules[firstTarget] = std::make_pair(incgfx.source, rule);
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
                if (CanOpenFile(path))
                    exists = true;
            }
            if (!exists)
                continue;

            dependencies_includes.insert(path);
            bool inserted = dependencies.insert(path).second;
            if (inserted && exists)
            {
                filesToProcess.push(path);
            }
        }
        includeDirs.pop_back();
    }

    if (!makeformat)
    {
        for (const std::string &path : dependencies)
        {
            std::printf("%s\n", path.c_str());
        }
        std::cout << std::endl;
    }
    else
    {
        // Write out make rules to a file
        std::ofstream output(make_outfile);

        // Print a make rule for the object file
        output << object_file.c_str() << ":";
        for (const std::string &path : dependencies)
        {
            output << " " << path;
        }
        output << '\n';

        // Dependency list rule.
        // Although these rules are identical, they need to be separate, else make will trigger the rule again after the file is created for the first time.
        output << make_outfile.c_str() << ":";
        for (const std::string &path : dependencies_includes)
        {
            output << " " << path;
        }
        output << '\n';

        // Dummy rules
        // If a dependency is deleted, make will try to make it, instead of rescanning the dependencies before trying to do that.
        for (const std::string &path : dependencies)
        {
            output << path << ":\n";
        }

        // Graphics rules
        // GNU make will issue a warning if there is more than one
        // recipe for a target. This would occur whenever a target is
        // 'INCGFX'ed multiple times, which is something that happens a
        // few times in vanilla. As a workaround, we define a variable
        // with the target's name sanitized and only emit the recipe if
        // the target is not yet defined. This is safe, because
        // targets with the same name necessarily have the same recipe.
        for (auto gfx_rule : dependencies_gfx_rules)
        {
            std::string gfx_var_name = gfx_rule.first;
            gfx_var_name.erase(
                std::remove_if(
                    gfx_var_name.begin(), 
                    gfx_var_name.end(), 
                    [] (char c) { return c == '#' || c == ':' || c == '='; } // invalid chars in GNU Make variables
                ), gfx_var_name.end()
            );
            
            output
                << "ifndef " << gfx_var_name << "\n"
                << gfx_var_name << " := defined\n"
                << gfx_rule.first << ": " << gfx_rule.second.first << "\n" << gfx_rule.second.second
                << "endif\n";
        }

        output.flush();
        output.close();
    }
}
