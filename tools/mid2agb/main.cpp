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
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <string>
#include <set>
#include "main.h"
#include "error.h"
#include "midi.h"
#include "agb.h"

FILE* g_inputFile = nullptr;
FILE* g_outputFile = nullptr;

std::string g_asmLabel;
int g_masterVolume = 127;
int g_voiceGroup = 0;
int g_priority = 0;
int g_reverb = -1;
int g_clocksPerBeat = 1;
bool g_exactGateTime = false;
bool g_compressionEnabled = true;

[[noreturn]] static void PrintUsage()
{
    std::printf(
        "Usage: MID2AGB name [options]\n"
        "\n"
        "    input_file  filename(.mid) of MIDI file\n"
        "   output_file  filename(.s) for AGB file (default:input_file)\n"
        "\n"
        "options  -V???  master volume (default:127)\n"
        "         -G???  voice group number (default:0)\n"
        "         -P???  priority (default:0)\n"
        "         -R???  reverb (default:off)\n"
        "            -X  48 clocks/beat (default:24 clocks/beat)\n"
        "            -E  exact gate-time\n"
        "            -N  no compression\n"
    );
    std::exit(1);
}

static std::string StripExtension(std::string s)
{
    std::size_t pos = s.find_last_of('.');

    if (pos > 0 && pos != std::string::npos)
    {
        s = s.substr(0, pos);
    }

    return s;
}

static std::string GetExtension(std::string s)
{
    std::size_t pos = s.find_last_of('.');

    if (pos > 0 && pos != std::string::npos)
    {
        return s.substr(pos + 1);
    }

    return "";
}

struct Option
{
    char letter = 0;
    const char *arg = NULL;
};

static Option ParseOption(int& index, const int argc, char** argv)
{
    static std::set<char> optionsWithArg = { 'L', 'V', 'G', 'P', 'R' };
    static std::set<char> optionsWithoutArg = { 'X', 'E', 'N' };

    assert(index >= 0 && index < argc);

    const char *opt = argv[index];

    assert(opt[0] == '-');
    assert(std::strlen(opt) == 2);

    char letter = std::toupper(opt[1]);

    bool isOption = false;
    bool hasArg = false;

    if (optionsWithArg.count(letter) != 0)
    {
        isOption = true;
        hasArg = true;
    }
    else if (optionsWithoutArg.count(letter) != 0)
    {
        isOption = true;
    }

    if (!isOption)
        PrintUsage();

    Option retVal;

    retVal.letter = letter;

    if (hasArg)
    {
        index++;

        if (index >= argc)
            RaiseError("missing argument for \"-%c\"", letter);

        retVal.arg = argv[index];
    }

    return retVal;
}

int main(int argc, char** argv)
{
    std::string inputFilename;
    std::string outputFilename;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-' && std::strlen(argv[i]) == 2)
        {
            Option option = ParseOption(i, argc, argv);

            switch (option.letter)
            {
            case 'E':
                g_exactGateTime = true;
                break;
            case 'G':
                g_voiceGroup = std::stoi(option.arg);
                break;
            case 'L':
                g_asmLabel = option.arg;
                break;
            case 'N':
                g_compressionEnabled = false;
                break;
            case 'P':
                g_priority = std::stoi(option.arg);
                break;
            case 'R':
                g_reverb = std::stoi(option.arg);
                break;
            case 'V':
                g_masterVolume = std::stoi(option.arg);
                break;
            case 'X':
                g_clocksPerBeat = 2;
                break;
            }
        }
        else
        {
            switch (i)
            {
            case 1:
                inputFilename = argv[i];
                break;
            case 2:
                outputFilename = argv[i];
                break;
            default:
                PrintUsage();
            }
        }
    }

    if (inputFilename.empty())
        PrintUsage();

    if (GetExtension(inputFilename) != "mid")
        RaiseError("input filename extension is not \"mid\"");

    if (outputFilename.empty())
        outputFilename = StripExtension(inputFilename) + ".s";

    if (GetExtension(outputFilename) != "s")
        RaiseError("output filename extension is not \"s\"");

    if (g_asmLabel.empty())
        g_asmLabel = StripExtension(outputFilename);

    g_inputFile = std::fopen(inputFilename.c_str(), "rb");

    if (g_inputFile == nullptr)
        RaiseError("failed to open \"%s\" for reading", inputFilename.c_str());

    g_outputFile = std::fopen(outputFilename.c_str(), "w");

    if (g_outputFile == nullptr)
        RaiseError("failed to open \"%s\" for writing", outputFilename.c_str());

    ReadMidiFileHeader();
    PrintAgbHeader();
    ReadMidiTracks();
    PrintAgbFooter();

    std::fclose(g_inputFile);
    std::fclose(g_outputFile);

    return 0;
}
