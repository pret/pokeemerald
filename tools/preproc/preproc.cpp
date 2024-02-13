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

#include <string>
#include <stack>
#include "preproc.h"
#include "asm_file.h"
#include "c_file.h"
#include "charmap.h"

Charmap* g_charmap;

void PrintAsmBytes(unsigned char *s, int length)
{
    if (length > 0)
    {
        std::printf("\t.byte ");
        for (int i = 0; i < length; i++)
        {
            std::printf("0x%02X", s[i]);

            if (i < length - 1)
                std::printf(", ");
        }
        std::putchar('\n');
    }
}

void PreprocAsmFile(std::string filename)
{
    std::stack<AsmFile> stack;

    stack.push(AsmFile(filename));

    for (;;)
    {
        while (stack.top().IsAtEnd())
        {
            stack.pop();

            if (stack.empty())
                return;
            else
                stack.top().OutputLocation();
        }

        Directive directive = stack.top().GetDirective();

        switch (directive)
        {
        case Directive::Include:
            stack.push(AsmFile(stack.top().ReadPath()));
            stack.top().OutputLocation();
            break;
        case Directive::String:
        {
            unsigned char s[kMaxStringLength];
            int length = stack.top().ReadString(s);
            PrintAsmBytes(s, length);
            break;
        }
        // Like String, but prepends FIXED_CASE char
        case Directive::FixedString:
        {
            unsigned char s[kMaxStringLength];
            int length = 0;
            s[length++] = '\x7d'; // FIXED_CASE
            length += stack.top().ReadString(s+length);
            PrintAsmBytes(s, length);
            break;
        }
        case Directive::Braille:
        {
            unsigned char s[kMaxStringLength];
            int length = stack.top().ReadBraille(s);
            PrintAsmBytes(s, length);
            break;
        }
        case Directive::Unknown:
        {
            std::string globalLabel = stack.top().GetGlobalLabel();

            if (globalLabel.length() != 0)
            {
                const char *s = globalLabel.c_str();
                std::printf("%s: ; .global %s\n", s, s);
            }
            else
            {
                stack.top().OutputLine();
            }

            break;
        }
        }
    }
}

void PreprocCFile(const char * filename, bool isStdin)
{
    CFile cFile(filename, isStdin);
    cFile.Preproc();
}

char* GetFileExtension(char* filename)
{
    char* extension = filename;

    while (*extension != 0)
        extension++;

    while (extension > filename && *extension != '.')
        extension--;

    if (extension == filename)
        return nullptr;

    extension++;

    if (*extension == 0)
        return nullptr;

    return extension;
}

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
    {
        std::fprintf(stderr, "Usage: %s SRC_FILE CHARMAP_FILE [-i]\nwhere -i denotes if input is from stdin\n", argv[0]);
        return 1;
    }

    g_charmap = new Charmap(argv[2]);

    char* extension = GetFileExtension(argv[1]);

    if (!extension)
        FATAL_ERROR("\"%s\" has no file extension.\n", argv[1]);

    if ((extension[0] == 's') && extension[1] == 0)
        PreprocAsmFile(argv[1]);
    else if ((extension[0] == 'c' || extension[0] == 'i') && extension[1] == 0) {
        if (argc == 4) {
            if (argv[3][0] == '-' && argv[3][1] == 'i' && argv[3][2] == '\0') {
                PreprocCFile(argv[1], true);
            } else {
                FATAL_ERROR("unknown argument flag \"%s\".\n", argv[3]);
            }
        } else {
            PreprocCFile(argv[1], false);
        }
    } else
        FATAL_ERROR("\"%s\" has an unknown file extension of \"%s\".\n", argv[1], extension);

    return 0;
}
