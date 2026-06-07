#ifndef GUARD_EASYCHAT_H
#define GUARD_EASYCHAT_H

#include "main.h"

struct EasyChatScreenTemplate
{
    u8 type;
    u8 numColumns;
    u8 numRows;
    u8 frameId:7;
    u8 fourFooterOptions:1;
    const u8 *titleText;
    const u8 *instructionsText1;
    const u8 *instructionsText2;
    const u8 *confirmText1;
    const u8 *confirmText2;
};

struct EasyChatScreen
{
    u8 type;
    u8 templateId;
    u8 numColumns;
    u8 numRows;
    u8 inputState;
    s8 mainCursorColumn;
    s8 mainCursorRow;
    u8 maxWords;
    u8 inputStateBackup;
    bool8 inAlphabetMode;
    s8 keyboardColumn;
    s8 keyboardRow;
    u8 keyboardScrollOffset;
    u8 keyboardLastRow;
    u8 wordSelectScrollOffset;
    u8 wordSelectLastRow;
    s8 wordSelectColumn;
    s8 wordSelectRow;
    u8 displayedPersonType;
    u8 unused; // Set to 0, never read
    u8 quizTitle[32];
    const u8 *titleText;
    u16 *savedPhrase;
    u16 currentPhrase[9];
};

struct EasyChatScreenControl
{
    u16 funcState;
    u16 windowId;
    u16 currentFuncId;
    u8 curWindowAnimState;
    u8 destWindowAnimState;
    s8 windowAnimStateDir;
    u8 modeWindowState;
    bool8 fourFooterOptions; // Never read (template is used directly instead)
    u8 phrasePrintBuffer[193];
    u8 wordSelectPrintBuffer[514];
    u16 scrollOffset;
    int scrollDest;
    int scrollSpeed;
    struct Sprite *mainCursorSprite;
    struct Sprite *rectangleCursorSpriteRight;
    struct Sprite *rectangleCursorSpriteLeft;
    struct Sprite *wordSelectCursorSprite;
    struct Sprite *buttonWindowSprite;
    struct Sprite *modeWindowSprite;
    struct Sprite *scrollIndicatorUpSprite;
    struct Sprite *scrollIndicatorDownSprite;
    struct Sprite *startButtonSprite;
    struct Sprite *selectButtonSprite;
    u16 bg1TilemapBuffer[BG_SCREEN_SIZE / 2];
    u16 bg3TilemapBuffer[BG_SCREEN_SIZE / 2];
};

struct EasyChatPhraseFrameDimensions
{
    u8 left:5;
    u8 top:3;
    u8 width;
    u8 height;
    u8 footerId;
};

struct EasyChatWordInfo
{
    const u8 *text;
    int alphabeticalOrder;
    int enabled;
};

typedef union
{
    const u16 *valueList;
    const struct EasyChatWordInfo *words;
} EasyChatGroupWordData;

struct EasyChatGroup
{
    EasyChatGroupWordData wordData;
    u16 numWords;
    u16 numEnabledWords;
};

struct EasyChatScreenWordData
{
    u16 numUnlockedGroups;
    u16 unlockedGroupIds[EC_NUM_GROUPS];
    u16 numUnlockedAlphabetWords[EC_NUM_ALPHABET_GROUPS];
    u16 unlockedAlphabetWords[EC_NUM_ALPHABET_GROUPS][EC_MAX_WORDS_IN_GROUP];
    u8 unused[44];
    u16 selectedGroupWords[EC_MAX_WORDS_IN_GROUP];
    u16 numSelectedGroupWords;
}; /*size = 0x3BA4*/

struct EasyChatWordsByLetter
{
    const u16 *words;
    int numWords;
};

void InitEasyChatPhrases(void);
void ShowEasyChatScreen(void);
u8 *CopyEasyChatWord(u8 *dest, u16 easyChatWord);
bool32 IsEasyChatAnswerUnlocked(int easyChatWord);
void InitializeEasyChatWordArray(u16 *words, u16 length);
u8 *ConvertEasyChatWordsToString(u8 *dest, const u16 *src, u16 columns, u16 rows);
bool8 IsBardWordInvalid(u16 easyChatWord);
u16 GetRandomEasyChatWordFromGroup(u16 groupId);
u16 UnlockRandomTrendySaying(void);
u16 EasyChat_GetNumWordsInGroup(u8 groupId);
u16 GetRandomEasyChatWordFromUnlockedGroup(u16 groupId);
void DoEasyChatScreen(u8 type, u16 *words, MainCallback exitCallback, u8 displayedPersonType);
void InitQuestionnaireWords(void);
void UnlockTrendySaying(u8 wordIndex);

#endif // GUARD_EASYCHAT_H
