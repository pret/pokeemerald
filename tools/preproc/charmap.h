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

#ifndef CHARMAP_H
#define CHARMAP_H

#include <cstdint>
#include <string>
#include <map>
#include <vector>

class Charmap
{
public:
    Charmap(std::string filename);

    std::string Char(std::int32_t code)
    {
        auto it = m_chars.find(code);

        if (it == m_chars.end())
            return std::string();

        return it->second;
    }

    std::string Escape(unsigned char code)
    {
        return m_escapes[code];
    }

    std::string Constant(std::string identifier)
    {
        auto it = m_constants.find(identifier);

        if (it == m_constants.end())
            return std::string();

        return it->second;
    }
private:
    std::map<std::int32_t, std::string> m_chars;
    std::string m_escapes[128];
    std::map<std::string, std::string> m_constants;
};

#endif // CHARMAP_H
