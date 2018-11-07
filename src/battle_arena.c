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
#include "constants/songs.h"

extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;

extern void (* const gUnknown_08611F84[])(void);
extern const struct CompressedSpriteSheet gUnknown_08611F74[];
extern const u16 gUnknown_08D855E8[];
extern const struct SpriteTemplate gUnknown_08611F5C;

// This file's functions.
void sub_81A5558(u8 x, u8 y, u8 arg2, u8 battler);

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

void sub_81A5558(u8 x, u8 y, u8 arg2, u8 battler)
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
