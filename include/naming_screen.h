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
    u8 unk0;
    u8 maxChars;
    u8 unk2;
    u8 unk3;
    u8 unk4;  //mode?
    u8 unk5;
    u8 unk6;
    u8 unk7;
    const u8 *title;
};

struct NamingScreenData {
 /*0x0*/    u8 tilemapBuffer1[0x800];
 /*0x800*/  u8 tilemapBuffer2[0x800];
 /*0x800*/  u8 tilemapBuffer3[0x800];
 /*0x1800*/ u8 textBuffer[0x10];
 /*0x1810*/ u8 tileBuffer[0x600];
 /*0x1E10*/ u8 state;
 /*0x1E11*/ u8 windows[5];
 /*0x1E16*/ u16 unk1E16;
 /*0x1E18*/ u16 bg1vOffset;
 /*0x1E1A*/ u16 bg2vOffset;
 /*0x1E1C*/ u16 unk1E1C;
 /*0x1E1E*/ u16 unk1E1E;
 /*0x1E20*/ u8 unk1E20;
 /*0x1E21*/ u8 unk1E21;
 /*0x1E22*/ u8 currentPage;
 /*0x1E23*/ u8 cursorSpriteId;
 /*0x1E24*/ u8 unk1E24;
 /*0x1E25*/ u8 unk1E25;
 /*0x1E28*/ const struct NamingScreenTemplate *template;
 /*0x1E2C*/ u8 templateNum;
 /*0x1E30*/ u8 *destBuffer;
 /*0x1E34*/ u16 unk1E34;
 /*0x1E36*/ u16 unk1E36;
 /*0x1E38*/ u32 unk1E38;
 /*0x1E3C*/ MainCallback returnCallback;
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

void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpecies, u16 monGender, u32 monPersonality, MainCallback returnCallback);

#endif // GUARD_NAMING_SCREEN_H
