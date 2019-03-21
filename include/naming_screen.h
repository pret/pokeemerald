#ifndef GUARD_NAMING_SCREEN_H
#define GUARD_NAMING_SCREEN_H

#include "main.h"

#define KBEVENT_NONE 0
#define KBEVENT_PRESSED_A 5
#define KBEVENT_PRESSED_B 6
#define KBEVENT_PRESSED_SELECT 8
#define KBEVENT_PRESSED_START 9

enum
{
    NAMING_SCREEN_PLAYER,
    NAMING_SCREEN_BOX,
    NAMING_SCREEN_CAUGHT_MON,
    NAMING_SCREEN_3,
    NAMING_SCREEN_WALDA,
};

struct NamingScreenTemplate
{
    u8 copyExistingString;
    u8 maxChars;
    u8 iconFunction;
    u8 addGenderIcon;
    u8 initialPage;
    u8 unused;
    const u8 *title;
};

struct NamingScreenData {
    u8 tilemapBuffer1[0x800];
    u8 tilemapBuffer2[0x800];
    u8 tilemapBuffer3[0x800];
    u8 textBuffer[0x20];
    u8 backupBuffer[0x20];
    u8 tileBuffer[0x600];
    u8 state;
    u8 koreanState;
    u8 windows[5];
    u16 inputCharBaseXPos;
    u16 bg1vOffset;
    u16 bg2vOffset;
    u16 bg1Priority;
    u16 bg2Priority;
    u8 bgToReveal;
    u8 bgToHide;
    u8 currentPage;
    u8 cursorSpriteId;
    u8 selectBtnFrameSpriteId;
    u8 keyRepeatStartDelayCopy;
    const struct NamingScreenTemplate *template;
    u8 templateNum;
    u8 *destBuffer;
    u16 monSpecies;
    u16 monGender;
    u32 monPersonality;
    MainCallback returnCallback;
};

enum
{
    PAGE_UPPER,
    PAGE_LOWER,
    PAGE_OTHERS,
};

enum
{
    MAIN_STATE_BEGIN_FADE_IN,
    MAIN_STATE_WAIT_FADE_IN,
    MAIN_STATE_HANDLE_INPUT,
    MAIN_STATE_MOVE_TO_OK_BUTTON,
    MAIN_STATE_START_PAGE_SWAP,
    MAIN_STATE_WAIT_PAGE_SWAP,
    MAIN_STATE_6,
    MAIN_STATE_UPDATE_SENT_TO_PC_MESSAGE,
    MAIN_STATE_BEGIN_FADE_OUT,
};

enum
{
    INPUT_STATE_DISABLED,
    INPUT_STATE_ENABLED,
    INPUT_STATE_2,
};

enum
{
    STATE_NONE,
    STATE_JAUM,
    STATE_MOUM_MERGEABLE,
    STATE_MOUM,
    STATE_JAUM_2_MERGEABLE,
    STATE_JAUM_2,
    STATE_MERGED_JAUM,
};

void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpecies, u16 monGender, u32 monPersonality, MainCallback returnCallback);

#endif // GUARD_NAMING_SCREEN_H
