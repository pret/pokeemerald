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

#include "tables.h"

const int g_noteDurationLUT[] =
{
    0, // 0
    1, // 1
    2, // 2
    3, // 3
    4, // 4
    5, // 5
    6, // 6
    7, // 7
    8, // 8
    9, // 9
    10, // 10
    11, // 11
    12, // 12
    13, // 13
    14, // 14
    15, // 15
    16, // 16
    17, // 17
    18, // 18
    19, // 19
    20, // 20
    21, // 21
    22, // 22
    23, // 23
    24, // 24
    24, // 25
    24, // 26
    24, // 27
    28, // 28
    28, // 29
    30, // 30
    30, // 31
    32, // 32
    32, // 33
    32, // 34
    32, // 35
    36, // 36
    36, // 37
    36, // 38
    36, // 39
    40, // 40
    40, // 41
    42, // 42
    42, // 43
    44, // 44
    44, // 45
    44, // 46
    44, // 47
    48, // 48
    48, // 49
    48, // 50
    48, // 51
    52, // 52
    52, // 53
    54, // 54
    54, // 55
    56, // 56
    56, // 57
    56, // 58
    56, // 59
    60, // 60
    60, // 61
    60, // 62
    60, // 63
    64, // 64
    64, // 65
    66, // 66
    66, // 67
    68, // 68
    68, // 69
    68, // 70
    68, // 71
    72, // 72
    72, // 73
    72, // 74
    72, // 75
    76, // 76
    76, // 77
    78, // 78
    78, // 79
    80, // 80
    80, // 81
    80, // 82
    80, // 83
    84, // 84
    84, // 85
    84, // 86
    84, // 87
    88, // 88
    88, // 89
    90, // 90
    90, // 91
    92, // 92
    92, // 93
    92, // 94
    92, // 95
    96, // 96
};

const int g_noteVelocityLUT[] =
{
    0, // 0
    4, // 1
    4, // 2
    4, // 3
    4, // 4
    8, // 5
    8, // 6
    8, // 7
    8, // 8
    12, // 9
    12, // 10
    12, // 11
    12, // 12
    16, // 13
    16, // 14
    16, // 15
    16, // 16
    20, // 17
    20, // 18
    20, // 19
    20, // 20
    24, // 21
    24, // 22
    24, // 23
    24, // 24
    28, // 25
    28, // 26
    28, // 27
    28, // 28
    32, // 29
    32, // 30
    32, // 31
    32, // 32
    36, // 33
    36, // 34
    36, // 35
    36, // 36
    40, // 37
    40, // 38
    40, // 39
    40, // 40
    44, // 41
    44, // 42
    44, // 43
    44, // 44
    48, // 45
    48, // 46
    48, // 47
    48, // 48
    52, // 49
    52, // 50
    52, // 51
    52, // 52
    56, // 53
    56, // 54
    56, // 55
    56, // 56
    60, // 57
    60, // 58
    60, // 59
    60, // 60
    64, // 61
    64, // 62
    64, // 63
    64, // 64
    68, // 65
    68, // 66
    68, // 67
    68, // 68
    72, // 69
    72, // 70
    72, // 71
    72, // 72
    76, // 73
    76, // 74
    76, // 75
    76, // 76
    80, // 77
    80, // 78
    80, // 79
    80, // 80
    84, // 81
    84, // 82
    84, // 83
    84, // 84
    88, // 85
    88, // 86
    88, // 87
    88, // 88
    92, // 89
    92, // 90
    92, // 91
    92, // 92
    96, // 93
    96, // 94
    96, // 95
    96, // 96
    100, // 97
    100, // 98
    100, // 99
    100, // 100
    104, // 101
    104, // 102
    104, // 103
    104, // 104
    108, // 105
    108, // 106
    108, // 107
    108, // 108
    112, // 109
    112, // 110
    112, // 111
    112, // 112
    116, // 113
    116, // 114
    116, // 115
    116, // 116
    120, // 117
    120, // 118
    120, // 119
    120, // 120
    124, // 121
    124, // 122
    124, // 123
    124, // 124
    127, // 125
    127, // 126
    127, // 127
};

const char* g_noteTable[] =
{
    "Cn%01u ",
    "Cs%01u ",
    "Dn%01u ",
    "Ds%01u ",
    "En%01u ",
    "Fn%01u ",
    "Fs%01u ",
    "Gn%01u ",
    "Gs%01u ",
    "An%01u ",
    "As%01u ",
    "Bn%01u ",
};

const char* g_minusNoteTable[] =
{
    "CnM%01u",
    "CsM%01u",
    "DnM%01u",
    "DsM%01u",
    "EnM%01u",
    "FnM%01u",
    "FsM%01u",
    "GnM%01u",
    "GsM%01u",
    "AnM%01u",
    "AsM%01u",
    "BnM%01u",
};
