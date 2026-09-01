#include "global.h"
#include "line_break.h"
#include "text.h"
#include "malloc.h"

void StripLineBreaks(u8 *src)
{
    u32 currIndex = 0;
    u32 prevChar = EOS;
    while (src[currIndex] != EOS)
    {
        if (src[currIndex] == CHAR_PROMPT_SCROLL || src[currIndex] == CHAR_NEWLINE)
        {
            if (prevChar == CHAR_HYPHEN)
                src[currIndex] = CHAR_ZWS;
            else
                src[currIndex] = CHAR_SPACE;
        }
        prevChar = src[currIndex];
        currIndex++;
    }
}

u32 CountLineBreaks(u8 *src)
{
    u32 currIndex = 0;
    u32 numNewLines = 0;
    while (src[currIndex] != EOS)
    {
        if (src[currIndex] == CHAR_PROMPT_SCROLL || src[currIndex] == CHAR_NEWLINE)
            numNewLines++;
        currIndex++;
    }

    return numNewLines;
}

void BreakStringAutomatic(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt)
{
    u32 currIndex = 0;
    u8 *currSrc = src;
    while (src[currIndex] != EOS)
    {
        if (src[currIndex] == CHAR_PROMPT_CLEAR)
        {
            u8 replacedChar = src[currIndex];
            src[currIndex] = EOS;
            BreakSubStringAutomatic(currSrc, maxWidth, screenLines, fontId, toggleScrollPrompt);
            src[currIndex] = replacedChar;
            currSrc = &src[currIndex + 1];
        }
        currIndex++;
    }
    BreakSubStringAutomatic(currSrc, maxWidth, screenLines, fontId, toggleScrollPrompt);
}

void BreakStringNaive(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt)
{
    u32 currIndex = 0;
    u8 *currSrc = src;
    while (src[currIndex] != EOS)
    {
        if (src[currIndex] == CHAR_PROMPT_CLEAR)
        {
            u8 replacedChar = src[currIndex + 1];
            src[currIndex + 1] = EOS;
            BreakSubStringNaive(currSrc, maxWidth, screenLines, fontId, toggleScrollPrompt);
            src[currIndex + 1] = replacedChar;
            currSrc = &src[currIndex + 1];
        }
        currIndex++;
    }
    BreakSubStringNaive(currSrc, maxWidth, screenLines, fontId, toggleScrollPrompt);
}

#define SCROLL_PROMPT_WIDTH 8
void BreakSubStringNaive(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt)
{
    //  If the string already has line breaks, don't interfere with them
    if (StringHasManualBreaks(src))
        return;
    //  Sanity check
    if (src[0] == EOS)
        return;
    u32 numChars = 1;
    u32 numWords = 1;
    u32 currWordIndex = 0;
    u32 currWordLength = 1;
    bool32 isPrevCharSplitting = FALSE;
    bool32 isCurrCharSplitting;
    //  Get numbers of chars in string and count words
    while (src[numChars] != EOS)
    {
        isCurrCharSplitting = IsWordSplittingChar(src, numChars);
        if (isCurrCharSplitting && !isPrevCharSplitting)
            numWords++;
        isPrevCharSplitting = isCurrCharSplitting;
        numChars++;
    }
    //  Allocate enough space for word data
    struct StringWord *allWords = Alloc(numWords*sizeof(struct StringWord));

    allWords[currWordIndex].startIndex = 0;
    allWords[currWordIndex].width = 0;
    isPrevCharSplitting = FALSE;
    //  Fill in word begin index and lengths
    for (u32 i = 1; i < numChars; i++)
    {
        isCurrCharSplitting = IsWordSplittingChar(src, i);
        if (isCurrCharSplitting && !isPrevCharSplitting)
        {
            allWords[currWordIndex].length = currWordLength;
            currWordIndex++;
            currWordLength = 0;
        }
        else if (!isCurrCharSplitting && isPrevCharSplitting)
        {
            allWords[currWordIndex].startIndex = i;
            allWords[currWordIndex].width = 0;
            currWordLength++;
        }
        else
        {
            currWordLength++;
        }
        isPrevCharSplitting = isCurrCharSplitting;
    }
    allWords[currWordIndex].length = currWordLength;

    //  Fill in individual word widths
    for (u32 i = 0; i < numWords; i++)
    {
        for (u32 j = 0; j < allWords[i].length; j++)
            allWords[i].width += GetGlyphWidth(src[allWords[i].startIndex + j], FALSE, fontId);
    }

    //  Step 1: Does it all fit one one line? Then no break
    //  Step 2: Try to split across minimum number of lines
    u32 spaceWidth = GetGlyphWidth(CHAR_SPACE, FALSE, fontId);
    u32 totalWidth = allWords[0].width;
    //  Calculate total widths without any line breaks
    for (u32 i = 1; i < numWords; i++)
        totalWidth += allWords[i].width + spaceWidth;

    //  If it doesn't fit on 1 line, do line breaks
    if (totalWidth > maxWidth)
    {
        u32 currWidth = 0;
        u32 numBreaks = 0;
        u32 currWords = 1;
        for (u32 wordIndex = 0; wordIndex < numWords; wordIndex++)
        {
            currWidth += allWords[wordIndex].width;
            if (numBreaks == screenLines - 1)
            {
                if (SCROLL_PROMPT_WIDTH + currWidth + (currWords - 1) * spaceWidth > maxWidth)
                {
                    src[allWords[wordIndex].startIndex - 1] = CHAR_PROMPT_SCROLL;
                    currWidth = allWords[wordIndex].length;
                    currWords = 1;
                }
                else
                {
                    currWords++;
                }
            }
            else
            {
                if (currWidth + (currWords - 1) * spaceWidth > maxWidth)
                {
                    src[allWords[wordIndex].startIndex - 1] = CHAR_NEWLINE;
                    currWidth = allWords[wordIndex].width;
                    currWords = 1;
                    numBreaks++;
                }
                else
                {
                    currWords++;
                }
            }
        }
    }

    Free(allWords);
}

void BreakSubStringAutomatic(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt)
{
    //  If the string already has line breaks, don't interfere with them
    if (StringHasManualBreaks(src))
        return;
    //  Sanity check
    if (src[0] == EOS)
        return;
    u32 numChars = 1;
    u32 numWords = 1;
    u32 currWordIndex = 0;
    u32 currWordLength = 1;
    bool32 isPrevCharSplitting = FALSE;
    bool32 isCurrCharSplitting;
    //  Get numbers of chars in string and count words
    while (src[numChars] != EOS)
    {
        isCurrCharSplitting = IsWordSplittingChar(src, numChars);
        if (isCurrCharSplitting && !isPrevCharSplitting)
            numWords++;
        isPrevCharSplitting = isCurrCharSplitting;
        numChars++;
    }
    //  Allocate enough space for word data
    struct StringWord *allWords = Alloc(numWords*sizeof(struct StringWord));

    allWords[currWordIndex].startIndex = 0;
    allWords[currWordIndex].width = 0;
    isPrevCharSplitting = FALSE;
    //  Fill in word begin index and lengths
    for (u32 i = 1; i < numChars; i++)
    {
        isCurrCharSplitting = IsWordSplittingChar(src, i);
        if (isCurrCharSplitting && !isPrevCharSplitting)
        {
            allWords[currWordIndex].length = currWordLength;
            currWordIndex++;
            currWordLength = 0;
        }
        else if (!isCurrCharSplitting && isPrevCharSplitting)
        {
            allWords[currWordIndex].startIndex = i;
            allWords[currWordIndex].width = 0;
            currWordLength++;
        }
        else
        {
            currWordLength++;
        }
        isPrevCharSplitting = isCurrCharSplitting;
    }
    allWords[currWordIndex].length = currWordLength;

    //  Fill in individual word widths
    for (u32 i = 0; i < numWords; i++)
    {
        for (u32 j = 0; j < allWords[i].length; j++)
            allWords[i].width += GetGlyphWidth(src[allWords[i].startIndex + j], FALSE, fontId);
    }

    //  Step 1: Does it all fit one one line? Then no break
    //  Step 2: Try to split across minimum number of lines
    u32 spaceWidth = GetGlyphWidth(CHAR_SPACE, FALSE, fontId);
    u32 totalWidth = allWords[0].width;
    //  Calculate total widths without any line breaks
    for (u32 i = 1; i < numWords; i++)
        totalWidth += allWords[i].width + spaceWidth;

    if (toggleScrollPrompt == SHOW_SCROLL_PROMPT)
        totalWidth += SCROLL_PROMPT_WIDTH;

    //  If it doesn't fit on 1 line, do fancy line break calculation
    //  NOTE: Currently the line break calculation isn't fancy
    if (totalWidth > maxWidth)
    {
        //  Figure out how many lines are needed with naive method
        u32 currLineWidth = 0;
        u32 totalLines = 1;
        bool32 shouldTryAgain;
        for (currWordIndex = 0; currWordIndex < numWords; currWordIndex++)
        {
            if (toggleScrollPrompt == SHOW_SCROLL_PROMPT && currWordIndex + 1 == numWords)
                currLineWidth += SCROLL_PROMPT_WIDTH;
            if (currLineWidth + allWords[currWordIndex].length > maxWidth)
            {
                totalLines++;
                currLineWidth = allWords[currWordIndex].width;
            }
            else
            {
                currLineWidth += allWords[currWordIndex].width + spaceWidth;
            }
        }

        if (currLineWidth > maxWidth)
            totalLines++;

        //  LINE LAYOUT STARTS HERE
        struct StringLine *stringLines;
        do
        {
            shouldTryAgain = FALSE;
            u16 targetLineWidth = totalWidth/totalLines;
            stringLines = Alloc(totalLines*sizeof(struct StringLine));
            for (u32 lineIndex = 0; lineIndex < totalLines; lineIndex++)
            {
                stringLines[lineIndex].numWords = 0;
                stringLines[lineIndex].spaceWidth = spaceWidth;
                stringLines[lineIndex].extraSpaceWidth = 0;
            }
            currWordIndex = 0;
            u16 currLineIndex = 0;
            stringLines[currLineIndex].words = &allWords[currWordIndex];
            stringLines[currLineIndex].numWords = 1;
            currLineWidth = allWords[currWordIndex].width;
            currWordIndex++;
            while (currWordIndex < numWords)
            {
                if (currLineWidth + spaceWidth + allWords[currWordIndex].width + ((toggleScrollPrompt == SHOW_SCROLL_PROMPT) ? SCROLL_PROMPT_WIDTH : 0) > maxWidth)
                {
                    //  go to next line
                    currLineIndex++;
                    if (currLineIndex == totalLines)
                    {
                        totalLines++;
                        Free(stringLines);
                        shouldTryAgain = TRUE;
                        break;
                    }
                    stringLines[currLineIndex].words = &allWords[currWordIndex];
                    stringLines[currLineIndex].numWords = 1;
                    currLineWidth = allWords[currWordIndex].width;
                    currWordIndex++;
                }
                else if (currLineWidth > targetLineWidth)
                {
                    //  go to next line
                    currLineIndex++;
                    if (currLineIndex == totalLines)
                    {
                        totalLines++;
                        Free(stringLines);
                        shouldTryAgain = TRUE;
                        break;
                    }
                    stringLines[currLineIndex].words = &allWords[currWordIndex];
                    stringLines[currLineIndex].numWords = 1;
                    currLineWidth = allWords[currWordIndex].width;
                    currWordIndex++;
                }
                else
                {
                    //  continue on current line
                    //  add word and space width
                    currLineWidth += spaceWidth + allWords[currWordIndex].width;
                    stringLines[currLineIndex].numWords++;
                    currWordIndex++;
                }
            }
        } while (shouldTryAgain);
        //u32 currBadness = GetStringBadness(stringLines, totalLines, maxWidth);
        BuildNewString(stringLines, totalLines, screenLines, src, toggleScrollPrompt);
        Free(stringLines);
    }

    Free(allWords);
}

//  Only allow word splitting on allowed chars
bool32 IsWordSplittingChar(const u8 *src, u32 index)
{
    switch (src[index])
    {
    case CHAR_ZWS:
    case CHAR_SPACE:
        return TRUE;
    default:
        return FALSE;
    }
}

//  Badness calculation
//  unfilled lines scale linerarly
//  jagged lines scales by the square
//  runts scale linearly
//  numbers not final
//  ISN'T ACTUALLY USED RIGHT NOW
u32 GetStringBadness(struct StringLine *stringLines, u32 numLines, u32 maxWidth)
{
    u32 badness = 0;
    u32 *lineWidths = Alloc(numLines*4);
    u32 widestWidth = 0;
    for (u32 i = 0; i < numLines; i++)
    {
        lineWidths[i] = 0;
        for (u32 j = 0; j < stringLines[i].numWords; j++)
            lineWidths[i] += stringLines[i].words[j].width;
        lineWidths[i] += (stringLines[i].numWords-1)*stringLines[i].spaceWidth;
        if (lineWidths[i] > widestWidth)
            widestWidth = lineWidths[i];
        if (stringLines[i].numWords == 1)
            badness += BADNESS_RUNT;
    }
    for (u32 i = 0; i < numLines; i++)
    {
        u32 extraSpaceWidth = 0;
        if (lineWidths[i] != widestWidth)
        {
            //  Not the best way to do this, ideally a line should be allowed to get longer than current widest
            //  line. But then the widest line has to be recalculated.
            while (lineWidths[i] + (extraSpaceWidth + 1) * (stringLines[i].numWords - 1) < widestWidth && extraSpaceWidth < MAX_SPACE_WIDTH)
                extraSpaceWidth++;
            lineWidths[i] += extraSpaceWidth*(stringLines[i].numWords-1);
        }
        badness += (maxWidth - lineWidths[i]) * BADNESS_UNFILLED;
        u32 baseBadness = (widestWidth - lineWidths[i]) * BADNESS_JAGGED;
        badness += baseBadness*baseBadness;
        stringLines[i].extraSpaceWidth = extraSpaceWidth;
    }
    Free(lineWidths);
    return badness;
}

//  Build the new string from the data stored in the StringLine structs
void BuildNewString(struct StringLine *stringLines, u32 numLines, u32 maxLines, u8 *str, enum ToggleScrollPrompt toggleScrollPrompt)
{
    u32 srcCharIndex = 0;
    for (u32 lineIndex = 0; lineIndex < numLines; lineIndex++)
    {
        srcCharIndex += stringLines[lineIndex].words[0].length;
        for (u32 wordIndex = 1; wordIndex < stringLines[lineIndex].numWords; wordIndex++)
            //  Add length of word and a space
            srcCharIndex += stringLines[lineIndex].words[wordIndex].length + 1;
        if (lineIndex + 1 < numLines)
        {
            //  Add the appropriate line break depending on line number
            if (lineIndex >= maxLines - 1 && numLines > maxLines && toggleScrollPrompt == SHOW_SCROLL_PROMPT)
                str[srcCharIndex] = CHAR_PROMPT_SCROLL;
            else
                str[srcCharIndex] = CHAR_NEWLINE;
            srcCharIndex++;
        }
    }
}

bool32 StringHasManualBreaks(u8 *src)
{
    u32 charIndex = 0;
    while (src[charIndex] != EOS)
    {
        if (src[charIndex] == CHAR_PROMPT_SCROLL || src[charIndex] == CHAR_NEWLINE)
            return TRUE;
        charIndex++;
    }
    return FALSE;
}
#undef SCROLL_PROMPT_WIDTH
