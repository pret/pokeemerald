#include "global.h"
#include "event_data.h"
#include "palette.h"
#include "gpu_regs.h"
#include "decompress.h"
#include "battle.h"
#include "battle_message.h"
#include "text.h"
#include "bg.h"
#include "sound.h"
#include "m4a.h"
#include "util.h"
#include "battle_setup.h"
#include "overworld.h"
#include "frontier_util.h"
#include "random.h"
#include "item.h"
#include "battle_tower.h"
#include "constants/songs.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_frontier.h"

extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;

extern const u32 gUnknown_08D854E8[];
extern const u16 gUnknown_08D855E8[];
extern const struct SpriteTemplate gUnknown_08611F5C;
extern const s8 gBattleArenaMoveMindRatings[];

// This file's functions.
static void sub_81A58B4(void);
static void sub_81A5964(void);
static void sub_81A59FC(void);
static void sub_81A5AC4(void);
static void sub_81A5B08(void);
static void sub_81A5B88(void);
static void sub_81A5BE0(void);
static void sub_81A5558(u8 x, u8 y, u8 arg2, u8 battler);

// Const rom data.
static const struct CompressedSpriteSheet gUnknown_08611F74[] =
{
    {gUnknown_08D854E8, 0x200, 0x3E8},
    {0}
};

static void (* const gUnknown_08611F84[])(void) =
{
    sub_81A58B4,
    sub_81A5964,
    sub_81A59FC,
    sub_81A5AC4,
    sub_81A5B08,
    sub_81A5B88,
    sub_81A5BE0,
};

static const u16 gUnknown_08611FA0[6] =
{
    0x003f, 0x0040, 0x0041, 0x0043, 0x0042, 0x0046
};

static const u16 gUnknown_08611FAC[9] =
{
    0x00b3, 0x00b4, 0x00b7, 0x00c8, 0x00b9, 0x00bb, 0x00c4, 0x00c6, 0x00ba
};

// code
void CallBattleArenaFunction(void)
{
    gUnknown_08611F84[gSpecialVar_0x8004]();
}

u8 sub_81A5258(u8 *state)
{
    s32 i;
    u8 ret = 0;
    switch (*state)
    {
    case 0:
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 0, 8, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
        LoadCompressedObjectPic(gUnknown_08611F74);
        LoadCompressedPalette(gUnknown_08D855E8, 0x1F0, 0x20);
        gBattle_WIN0H = 0xFF;
        gBattle_WIN0V = 0x70;
        (*state)++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            HandleBattleWindow(5, 0, 24, 13, 0);
            (*state)++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattleTextBuff1[0] = CHAR_0;
            gBattleTextBuff1[1] = EOS;
            gBattleTextBuff2[0] = CHAR_0;
            gBattleTextBuff2[1] = EOS;
            BattleStringExpandPlaceholdersToDisplayedString(gText_PlayerMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, 15);
            BattlePutTextOnWindow(gText_Vs, 16);
            BattleStringExpandPlaceholdersToDisplayedString(gText_OpponentMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, 17);
            BattlePutTextOnWindow(gText_Mind, 18);
            BattlePutTextOnWindow(gText_Skill, 19);
            BattlePutTextOnWindow(gText_Body, 20);
            BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
            BattlePutTextOnWindow(gDisplayedStringBattle, 21);
            (*state)++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
            for (i = 0; i < 8; i++)
            {
                u8 spriteId = CreateSprite(&gUnknown_08611F5C, 0x40 + (i * 0x10), 84, 0);
                StartSpriteAnim(&gSprites[spriteId], 3);
            }
            ret = 1;
            (*state)++;
        }
        break;
    case 4:
        PlaySE(SE_HANTEI1);
        sub_81A5558(80, 40, 0, 0);
        sub_81A5558(160, 40, 0, 1);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
        BattlePutTextOnWindow(gDisplayedStringBattle, 21);
        (*state)++;
        ret = 1;
        break;
    case 5:
        PlaySE(SE_HANTEI1);
        sub_81A5558(80, 56, 1, 0);
        sub_81A5558(160, 56, 1, 1);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
        BattlePutTextOnWindow(gDisplayedStringBattle, 21);
        (*state)++;
        ret = 1;
        break;
    case 6:
        PlaySE(SE_HANTEI1);
        sub_81A5558(80, 72, 2, 0);
        sub_81A5558(160, 72, 2, 1);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgement);
        BattlePutTextOnWindow(gDisplayedStringBattle, 21);
        (*state)++;
        ret = 1;
        break;
    case 7:
        PlaySE(SE_HANTEI2);
        if (gBattleTextBuff1[0] > gBattleTextBuff2[0])
        {
            ret = 2;
            gBattleScripting.battler = 0;
        }
        else if (gBattleTextBuff1[0] < gBattleTextBuff2[0])
        {
            ret = 3;
            gBattleScripting.battler = 1;
        }
        else
        {
            ret = 4;
        }
        (*state)++;
        break;
    case 8:
        (*state)++;
        break;
    case 9:
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
        HandleBattleWindow(5, 0, 24, 13, WINDOW_CLEAR);
        CopyBgTilemapBufferToVram(0);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 8, 0, 0);
        (*state)++;
        break;
    case 10:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
            FreeSpriteTilesByTag(0x3E8);
            ret = 1;
            (*state)++;
        }
        break;
    }

    return ret;
}

static void sub_81A5558(u8 x, u8 y, u8 arg2, u8 battler)
{
    s32 animNum = 0;
    s32 r6 = 0;
    s32 r1 = 0;
    s8 *ptr1 = gBattleStruct->field_298;
    s8 *ptr2 = gBattleStruct->field_29A;
    u16 *ptr3 = gBattleStruct->field_29C;

    switch (arg2)
    {
    case 0:
        r6 = ptr1[battler];
        r1 = ptr1[BATTLE_OPPOSITE(battler)];
        break;
    case 1:
        r6 = ptr2[battler];
        r1 = ptr2[BATTLE_OPPOSITE(battler)];
        break;
    case 2:
        r6 = (gBattleMons[battler].hp * 100) / ptr3[battler];
        r1 = (gBattleMons[BATTLE_OPPOSITE(battler)].hp * 100) / ptr3[BATTLE_OPPOSITE(battler)];
        break;
    }

    if (r6 > r1)
    {
        animNum = 2;
        if (battler != 0)
            gBattleTextBuff2[0] += 2;
        else
            gBattleTextBuff1[0] += 2;
    }
    else if (r6 == r1)
    {
        animNum = 1;
        if (battler != 0)
            gBattleTextBuff2[0] += 1;
        else
            gBattleTextBuff1[0] += 1;
    }
    else
    {
        animNum = 0;
    }

    r6 = CreateSprite(&gUnknown_08611F5C, x, y, 0);
    StartSpriteAnim(&gSprites[r6], animNum);
}

void sub_81A5698(struct Sprite *sprite)
{
    if (gBattleCommunication[0] > 8)
        DestroySprite(sprite);
}

void sub_81A56B4(void)
{
    s8 *ptr1 = gBattleStruct->field_298;
    s8 *ptr2 = gBattleStruct->field_29A;
    u16 *ptr3 = gBattleStruct->field_29C;

    ptr1[0] = 0;
    ptr1[1] = 0;
    ptr2[0] = 0;
    ptr2[1] = 0;
    ptr3[0] = gBattleMons[0].hp;
    ptr3[1] = gBattleMons[1].hp;
}

void sub_81A56E8(u8 battler)
{
    s8 *ptr1 = gBattleStruct->field_298;

    ptr1[battler] += gBattleArenaMoveMindRatings[gCurrentMove];
}

void sub_81A5718(u8 battler)
{
    s8 *ptr2 = gBattleStruct->field_29A;

    if (gHitMarker & HITMARKER_OBEYS)
    {
        u8 *ptr4 = &gBattleStruct->field_2A2;
        if (*ptr4 & gBitTable[battler])
        {
            *ptr4 &= ~(gBitTable[battler]);
            ptr2[battler] -= 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        {
            if (!(gMoveResultFlags & MOVE_RESULT_MISSED) || gBattleCommunication[6] != 1)
                ptr2[battler] -= 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE && gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
        {
            ptr2[battler] += 1;
        }
        else if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
        {
            ptr2[battler] += 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
        {
            ptr2[battler] -= 1;
        }
        else if (!gProtectStructs[battler].protected)
        {
            ptr2[battler] += 1;
        }
    }
}

void sub_81A57E4(u8 battler, u16 stringId)
{
    s8 *ptr2 = gBattleStruct->field_29A;

    switch (stringId)
    {
    case STRINGID_PKMNSXMADEYUSELESS:
    case STRINGID_PKMNSXMADEITINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSFLINCHING:
    case STRINGID_PKMNSXBLOCKSY2:
    case STRINGID_PKMNSXPREVENTSYLOSS:
    case STRINGID_PKMNSXMADEYINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSBURNS:
    case STRINGID_PKMNSXBLOCKSY:
    case STRINGID_PKMNPROTECTEDBY:
    case STRINGID_PKMNPREVENTSUSAGE:
    case STRINGID_PKMNRESTOREDHPUSING:
    case STRINGID_PKMNPREVENTSPARALYSISWITH:
    case STRINGID_PKMNPREVENTSROMANCEWITH:
    case STRINGID_PKMNPREVENTSPOISONINGWITH:
    case STRINGID_PKMNPREVENTSCONFUSIONWITH:
    case STRINGID_PKMNRAISEDFIREPOWERWITH:
    case STRINGID_PKMNANCHORSITSELFWITH:
    case STRINGID_PKMNPREVENTSSTATLOSSWITH:
    case STRINGID_PKMNSTAYEDAWAKEUSING:
        ptr2[battler] -= 3;
        break;
    }
}

void sub_81A586C(u8 battler)
{
    u16 *ptr3 = gBattleStruct->field_29C;

    ptr3[battler] = gBattleMons[battler].hp;
    if (ptr3[BATTLE_OPPOSITE(battler)] > gBattleMons[BATTLE_OPPOSITE(battler)].hp)
        ptr3[BATTLE_OPPOSITE(battler)] = gBattleMons[BATTLE_OPPOSITE(battler)].hp;
}

static void sub_81A58B4(void)
{
    bool32 isCurrent;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x80;
    else
        isCurrent = gSaveBlock2Ptr->frontier.field_CDC & 0x40;

    if (!isCurrent)
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = 0;

    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

static void sub_81A5964(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_DD8;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x80;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CDC & 0x40;
        break;
    }
}

static void sub_81A59FC(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_DD8 = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x80;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x80);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.field_CDC |= 0x40;
            else
                gSaveBlock2Ptr->frontier.field_CDC &= ~(0x40);
        }
        break;
    }
}

static void sub_81A5AC4(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    sub_81A4C30();
}

static void sub_81A5B08(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > 41)
        gSaveBlock2Ptr->frontier.field_DD8 = gUnknown_08611FAC[Random() % ARRAY_COUNT(gUnknown_08611FAC)];
    else
        gSaveBlock2Ptr->frontier.field_DD8 = gUnknown_08611FA0[Random() % ARRAY_COUNT(gUnknown_08611FA0)];
}

static void sub_81A5B88(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_DD8, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_DD8, gStringVar1);
        gSaveBlock2Ptr->frontier.field_DD8 = 0;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void sub_81A5BE0(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void sub_81A5BF8(void)
{
    u8 width = 27;
    u8 palNum = 7;

    FillBgTilemapBufferRect(0, 0,    254, 14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0,    32,  14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0x31, 0,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x33, 1,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x34, 2,   14, width, 1, palNum);
    width++;
    FillBgTilemapBufferRect(0, 0x35, 28,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x36, 29,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x37, 0,   15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x39, 1,   15, width, 5, palNum);
    FillBgTilemapBufferRect(0, 0x3A, 29,  15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x831, 0,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x833, 1,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x834, 2,  19, width - 2, 1, palNum);
    FillBgTilemapBufferRect(0, 0x835, 28, 19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x836, 29, 19, 1,  1, palNum);
}

void sub_81A5D44(void)
{
    u8 width;
    u8 height;
    u8 palNum = 0;

    FillBgTilemapBufferRect(0, 3, 0, 14, 1, 1, palNum);
    height = 4;
    FillBgTilemapBufferRect(0, 4, 1, 14, 1, 1, palNum);
    width = 27;
    FillBgTilemapBufferRect(0, 5, 2, 14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 6, 28, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 7, 29, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 8, 0, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 9, 1, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xA, 2, 15, width, height, palNum);
    FillBgTilemapBufferRect(0, 0xB, 28, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xC, 29, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xD, 0, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xE, 1, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xF, 2, 19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x10, 28, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0x11, 29, 19, 1, 1, palNum);
}
