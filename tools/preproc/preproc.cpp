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
#include <unistd.h>
#include "preproc.h"
#include "asm_file.h"
#include "c_file.h"
#include "charmap.h"

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

static void UsageAndExit(const char *program);

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

void PreprocAsmFile(std::string filename, bool isStdin, bool doEnum)
{
    std::stack<AsmFile> stack;

    stack.push(AsmFile(filename, isStdin, doEnum));
    std::printf("# 1 \"%s\"\n", filename.c_str());

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
            stack.push(AsmFile(stack.top().ReadPath(), false, doEnum));
            stack.top().OutputLocation();
            break;
        case Directive::String:
        {
            unsigned char s[kMaxStringLength];
            int length = stack.top().ReadString(s);
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
        case Directive::Enum:
        {
            if (!stack.top().ParseEnum())
                stack.top().OutputLine();
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

const char* GetFileExtension(const char* filename)
{
    const char* extension = filename;

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

static void UsageAndExit(const char *program)
{
    std::fprintf(stderr, "Usage: %s [-i] [-e] SRC_FILE CHARMAP_FILE\nwhere -i denotes if input is from stdin\n      -e enables enum handling\n", program);
    std::exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int opt;
    const char *source = NULL;
    const char *charmap = NULL;
    bool isStdin = false;
    bool doEnum = false;

    /* preproc [-i] [-e] SRC_FILE CHARMAP_FILE */
    while ((opt = getopt(argc, argv, "ie")) != -1)
    {
        switch (opt)
        {
        case 'i':
            isStdin = true;
            break;
        case 'e':
            doEnum = true;
            break;
        default:
            UsageAndExit(argv[0]);
            break;
        }
    }

    if (optind + 2 != argc)
        UsageAndExit(argv[0]);

    source = argv[optind + 0];
    charmap = argv[optind + 1];

    g_charmap = new Charmap(charmap);

#ifdef _WIN32
	// On Windows, piping from stdout can break newlines. Treat stdout as binary stream to avoid this.
	_setmode(_fileno(stdout), _O_BINARY);
#endif

    const char* extension = GetFileExtension(source);

    if (!extension)
        FATAL_ERROR("\"%s\" has no file extension.\n", argv[1]);

    if ((extension[0] == 's') && extension[1] == 0)
    {
        PreprocAsmFile(source, isStdin, doEnum);
    }
    else if ((extension[0] == 'c' || extension[0] == 'i') && extension[1] == 0)
    {
        if (doEnum)
            FATAL_ERROR("-e is invalid for C sources\n");
        PreprocCFile(source, isStdin);
    }
    else
    {
        FATAL_ERROR("\"%s\" has an unknown file extension of \"%s\".\n", argv[1], extension);
    }

    return 0;
}
