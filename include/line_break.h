#ifndef GUARD_LINE_BREAK_H
#define GUARD_LINE_BREAK_H

#define BADNESS_UNFILLED    1       //  Badness added per pixel diff from max width
#define BADNESS_JAGGED      1       //  Badness added per pixel diff from longest, squared per line
#define BADNESS_RUNT        100     //  Badness added if there's a runt
#define BADNESS_OVERFLOW    100     //  Badness added per pixel overflow, squared per line (not used)
#define BADNESS_WIDE_SPACE  1       //  Badness added per extra pixel width (not used)
#define MAX_SPACE_WIDTH     5

struct StringWord {
    u32 startIndex:16;
    u32 length:8;
    u32 width:8;
};

struct StringLine {
    struct StringWord *words;
    u16 numWords;
    u8 spaceWidth;
    u8 extraSpaceWidth;
};

enum ToggleScrollPrompt
{
    SHOW_SCROLL_PROMPT,
    HIDE_SCROLL_PROMPT,
};

void StripLineBreaks(u8 *src);
u32 CountLineBreaks(u8 *src);
void BreakStringAutomatic(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt);
void BreakSubStringAutomatic(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt);

void BreakStringNaive(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt);
void BreakSubStringNaive(u8 *src, u32 maxWidth, u32 screenLines, u8 fontId, enum ToggleScrollPrompt toggleScrollPrompt);

bool32 IsWordSplittingChar(const u8 *src, u32 index);
u32 GetStringBadness(struct StringLine *stringLines, u32 numLines, u32 maxWidth);
void BuildNewString(struct StringLine *stringLines, u32 numLines, u32 maxLines, u8 *str, enum ToggleScrollPrompt toggleScrollPrompt);
bool32 StringHasManualBreaks(u8 *src);

#endif // GUARD_LINE_BREAK_H
