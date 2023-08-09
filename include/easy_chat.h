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
    /*0x00*/ u8 type;
    /*0x01*/ u8 templateId;
    /*0x02*/ u8 numColumns;
    /*0x03*/ u8 numRows;
    /*0x04*/ u8 inputState;
    /*0x05*/ s8 mainCursorColumn;
    /*0x06*/ s8 mainCursorRow;
    /*0x07*/ u8 maxWords;
    /*0x08*/ u8 inputStateBackup;
    /*0x09*/ bool8 inAlphabetMode;
    /*0x0A*/ s8 keyboardColumn;
    /*0x0B*/ s8 keyboardRow;
    /*0x0C*/ u8 keyboardScrollOffset;
    /*0x0D*/ u8 keyboardLastRow;
    /*0x0E*/ u8 wordSelectScrollOffset;
    /*0x0F*/ u8 wordSelectLastRow;
    /*0x10*/ s8 wordSelectColumn;
    /*0x11*/ s8 wordSelectRow;
    /*0x12*/ u8 displayedPersonType;
    /*0x13*/ u8 unused; // Set to 0, never read
    /*0x14*/ u8 quizTitle[32];
    /*0x34*/ const u8 *titleText;
    /*0x38*/ u16 *savedPhrase;
    /*0x3C*/ u16 currentPhrase[9];
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
u8 * CopyEasyChatWord(u8 *dest, u16 word);
bool32 IsEasyChatAnswerUnlocked(int word);
void InitializeEasyChatWordArray(u16 *words, u16 length);
u8 *ConvertEasyChatWordsToString(u8 *dest, const u16 *src, u16 columns, u16 rows);
bool8 IsBardWordInvalid(u16 word);
u16 GetRandomEasyChatWordFromGroup(u16 group);
u16 UnlockRandomTrendySaying(void);
u16 EasyChat_GetNumWordsInGroup(u8);
u16 GetRandomEasyChatWordFromUnlockedGroup(u16);
void DoEasyChatScreen(u8 type, u16 *words, MainCallback callback, u8 displayedPersonType);
void InitQuestionnaireWords(void);
void UnlockTrendySaying(u8 wordIndex);

#endif // GUARD_EASYCHAT_H
