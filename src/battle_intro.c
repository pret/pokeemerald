#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "bg.h"
#include "gpu_regs.h"
#include "main.h"
#include "scanline_effect.h"
#include "task.h"
#include "trig.h"
#include "constants/trainers.h"

static EWRAM_DATA u16 sBgCnt = 0;

extern const u8 gUnknown_0859741A[];
extern const u8 gUnknown_0859741E[];

static void BattleIntroSlide1(u8);
static void BattleIntroSlide2(u8);
static void BattleIntroSlide3(u8);
static void BattleIntroSlideLink(u8);
static void BattleIntroSlidePartner(u8);

static const TaskFunc sBattleIntroSlideFuncs[] =
{
    BattleIntroSlide1, // BATTLE_TERRAIN_GRASS
    BattleIntroSlide1, // BATTLE_TERRAIN_LONG_GRASS
    BattleIntroSlide2, // BATTLE_TERRAIN_SAND
    BattleIntroSlide2, // BATTLE_TERRAIN_UNDERWATER
    BattleIntroSlide2, // BATTLE_TERRAIN_WATER
    BattleIntroSlide1, // BATTLE_TERRAIN_POND
    BattleIntroSlide1, // BATTLE_TERRAIN_MOUNTAIN
    BattleIntroSlide1, // BATTLE_TERRAIN_CAVE
    BattleIntroSlide3, // BATTLE_TERRAIN_BUILDING
    BattleIntroSlide3, // BATTLE_TERRAIN_PLAIN
};

void SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value)
{
    if (bgId < 4)
    {
        sBgCnt = GetGpuReg(gUnknown_0859741A[bgId]);
        switch (attributeId)
        {
        case BG_ANIM_SCREEN_SIZE:
            ((struct BgCnt *)&sBgCnt)->screenSize = value;
            break;
        case BG_ANIM_AREA_OVERFLOW_MODE:
            ((struct BgCnt *)&sBgCnt)->areaOverflowMode = value;
            break;
        case BG_ANIM_MOSAIC:
            ((struct BgCnt *)&sBgCnt)->mosaic = value;
            break;
        case BG_ANIM_CHAR_BASE_BLOCK:
            ((struct BgCnt *)&sBgCnt)->charBaseBlock = value;
            break;
        case BG_ANIM_PRIORITY:
            ((struct BgCnt *)&sBgCnt)->priority = value;
            break;
        case BG_ANIM_PALETTES_MODE:
            ((struct BgCnt *)&sBgCnt)->palettes = value;
            break;
        case BG_ANIM_SCREEN_BASE_BLOCK:
            ((struct BgCnt *)&sBgCnt)->screenBaseBlock = value;
            break;
        }

        SetGpuReg(gUnknown_0859741A[bgId], sBgCnt);
    }
}

int GetAnimBgAttribute(u8 bgId, u8 attributeId)
{
    u16 bgCnt;

    if (bgId < 4)
    {
        bgCnt = GetGpuReg(gUnknown_0859741E[bgId]);
        switch (attributeId)
        {
        case BG_ANIM_SCREEN_SIZE:
            return ((struct BgCnt *)&bgCnt)->screenSize;
        case BG_ANIM_AREA_OVERFLOW_MODE:
            return ((struct BgCnt *)&bgCnt)->areaOverflowMode;
        case BG_ANIM_MOSAIC:
            return ((struct BgCnt *)&bgCnt)->mosaic;
        case BG_ANIM_CHAR_BASE_BLOCK:
            return ((struct BgCnt *)&bgCnt)->charBaseBlock;
        case BG_ANIM_PRIORITY:
            return ((struct BgCnt *)&bgCnt)->priority;
        case BG_ANIM_PALETTES_MODE:
            return ((struct BgCnt *)&bgCnt)->palettes;
        case BG_ANIM_SCREEN_BASE_BLOCK:
            return ((struct BgCnt *)&bgCnt)->screenBaseBlock;
        }
    }

    return 0;
}

void HandleIntroSlide(u8 terrain)
{
    u8 taskId;

    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gPartnerTrainerId != TRAINER_STEVEN_PARTNER && gPartnerTrainerId < TRAINER_CUSTOM_PARTNER)
    {
        taskId = CreateTask(BattleIntroSlidePartner, 0);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        taskId = CreateTask(BattleIntroSlideLink, 0);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        taskId = CreateTask(BattleIntroSlide3, 0);
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON) && gGameVersion != VERSION_RUBY)
    {
        terrain = BATTLE_TERRAIN_UNDERWATER;
        taskId = CreateTask(BattleIntroSlide2, 0);
    }
    else
    {
        taskId = CreateTask(sBattleIntroSlideFuncs[terrain], 0);
    }

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = terrain;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 0;
    gTasks[taskId].data[5] = 0;
    gTasks[taskId].data[6] = 0;
}

void sub_811828C(u8 taskId)
{
    DestroyTask(taskId);
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
}

static void BattleIntroSlide1(u8 taskId)
{
    int i;

    gBattle_BG1_X += 6;
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            gTasks[taskId].data[2] = 16;
            gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[2] = 1;
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].data[0]++;
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        }
        break;
    case 2:
        gBattle_WIN0V -= 0xFF;
        if ((gBattle_WIN0V & 0xFF00) == 0x3000)
        {
            gTasks[taskId].data[0]++;
            gTasks[taskId].data[2] = 240;
            gTasks[taskId].data[3] = 32;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if (gTasks[taskId].data[3])
        {
            gTasks[taskId].data[3]--;
        }
        else
        {
            if (gTasks[taskId].data[1] == 1)
            {
                if (gBattle_BG1_Y != 0xFFB0)
                    gBattle_BG1_Y -= 2;
            }
            else
            {
                if (gBattle_BG1_Y != 0xFFC8)
                    gBattle_BG1_Y -= 1;
            }
        }

        if (gBattle_WIN0V & 0xFF00)
            gBattle_WIN0V -= 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        // Scanline settings have already been set in CB2_InitBattleInternal()
        for (i = 0; i < 80; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gTasks[taskId].data[2];

        for (; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = -gTasks[taskId].data[2];

        if (!gTasks[taskId].data[2])
        {
            gScanlineEffect.state = 3;
            gTasks[taskId].data[0]++;
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
        }
        break;
    case 4:
        sub_811828C(taskId);
        break;
    }
}

static void BattleIntroSlide2(u8 taskId)
{
    int i;

    switch (gTasks[taskId].data[1])
    {
    case 2:
    case 4:
        gBattle_BG1_X += 8;
        break;
    case 3:
        gBattle_BG1_X += 6;
        break;
    }

    if (gTasks[taskId].data[1] == 4)
    {
        gBattle_BG1_Y = Cos2(gTasks[taskId].data[6]) / 512 - 8;
        if (gTasks[taskId].data[6] < 180)
            gTasks[taskId].data[6] += 4;
        else
            gTasks[taskId].data[6] += 6;

        if (gTasks[taskId].data[6] == 360)
            gTasks[taskId].data[6] = 0;
    }

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gTasks[taskId].data[4] = 16;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            gTasks[taskId].data[2] = 16;
            gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[2] = 1;
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].data[0]++;
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        }
        break;
    case 2:
        gBattle_WIN0V -= 0xFF;
        if ((gBattle_WIN0V & 0xFF00) == 0x3000)
        {
            gTasks[taskId].data[0]++;
            gTasks[taskId].data[2] = 240;
            gTasks[taskId].data[3] = 32;
            gTasks[taskId].data[5] = 1;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if (gTasks[taskId].data[3])
        {
            if (--gTasks[taskId].data[3] == 0)
            {
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(15, 0));
                SetGpuReg(REG_OFFSET_BLDY, 0);
            }
        }
        else
        {
            if ((gTasks[taskId].data[4] & 0x1F) && --gTasks[taskId].data[5] == 0)
            {
                gTasks[taskId].data[4] += 0xFF;
                gTasks[taskId].data[5] = 4;
            }
        }

        if (gBattle_WIN0V & 0xFF00)
            gBattle_WIN0V -= 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        // Scanline settings have already been set in CB2_InitBattleInternal()
        for (i = 0; i < 80; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gTasks[taskId].data[2];

        for (; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = -gTasks[taskId].data[2];

        if (!gTasks[taskId].data[2])
        {
            gScanlineEffect.state = 3;
            gTasks[taskId].data[0]++;
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
        }
        break;
    case 4:
        sub_811828C(taskId);
        break;
    }

    if (gTasks[taskId].data[0] != 4)
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[4], 0));
}

static void BattleIntroSlide3(u8 taskId)
{
    int i;

    gBattle_BG1_X += 8;
    switch (gTasks[taskId].data[0])
    {
    case 0:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gTasks[taskId].data[4] = BLDALPHA_BLEND(8, 8);
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        {
            gTasks[taskId].data[2] = 16;
            gTasks[taskId].data[0]++;
        }
        else
        {
            gTasks[taskId].data[2] = 1;
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].data[0]++;
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        }
        break;
    case 2:
        gBattle_WIN0V -= 0xFF;
        if ((gBattle_WIN0V & 0xFF00) == 0x3000)
        {
            gTasks[taskId].data[0]++;
            gTasks[taskId].data[2] = 240;
            gTasks[taskId].data[3] = 32;
            gTasks[taskId].data[5] = 1;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if (gTasks[taskId].data[3])
        {
            gTasks[taskId].data[3]--;
        }
        else
        {
            if ((gTasks[taskId].data[4] & 0xF) && --gTasks[taskId].data[5] == 0)
            {
                gTasks[taskId].data[4] += 0xFF;
                gTasks[taskId].data[5] = 6;
            }
        }

        if (gBattle_WIN0V & 0xFF00)
            gBattle_WIN0V -= 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        // Scanline settings have already been set in CB2_InitBattleInternal()
        for (i = 0; i < 80; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gTasks[taskId].data[2];

        for (; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = -gTasks[taskId].data[2];

        if (!gTasks[taskId].data[2])
        {
            gScanlineEffect.state = 3;
            gTasks[taskId].data[0]++;
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
        }
        break;
    case 4:
        sub_811828C(taskId);
        break;
    }

    if (gTasks[taskId].data[0] != 4)
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[4], 0));
}

static void BattleIntroSlideLink(u8 taskId)
{
    int i;

    if (gTasks[taskId].data[0] > 1 && !gTasks[taskId].data[4])
    {
        u16 var0 = gBattle_BG1_X & 0x8000;
        if (var0 || gBattle_BG1_X < 80)
        {
            gBattle_BG1_X += 3;
            gBattle_BG2_X -= 3;
        }
        else
        {
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
            CpuFill32(0, (void *)BG_SCREEN_ADDR(30), BG_SCREEN_SIZE);
            gTasks[taskId].data[4] = 1;
        }
    }

    switch (gTasks[taskId].data[0])
    {
    case 0:
        gTasks[taskId].data[2] = 32;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].data[0]++;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].oam.objMode = ST_OAM_OBJ_WINDOW;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].callback = sub_8038B74;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].oam.objMode = ST_OAM_OBJ_WINDOW;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].callback = sub_8038B74;
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
            SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2);
        }
        break;
    case 2:
        gBattle_WIN0V -= 0xFF;
        if ((gBattle_WIN0V & 0xFF00) == 0x3000)
        {
            gTasks[taskId].data[0]++;
            gTasks[taskId].data[2] = 240;
            gTasks[taskId].data[3] = 32;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if (gBattle_WIN0V & 0xFF00)
            gBattle_WIN0V -= 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        // Scanline settings have already been set in CB2_InitBattleInternal()
        for (i = 0; i < 80; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gTasks[taskId].data[2];

        for (; i < 160; i++)
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = -gTasks[taskId].data[2];

        if (!gTasks[taskId].data[2])
        {
            gScanlineEffect.state = 3;
            gTasks[taskId].data[0]++;
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
        }
        break;
    case 4:
        sub_811828C(taskId);
        break;
    }
}

static void BattleIntroSlidePartner(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        gTasks[taskId].data[2] = 1;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (--gTasks[taskId].data[2] == 0)
        {
            gTasks[taskId].data[0]++;
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT512x256);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
            SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN1_BG1 | WININ_WIN1_BG2 | WININ_WIN1_BG3 | WININ_WIN1_OBJ | WININ_WIN1_CLR);
            SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
            gBattle_BG0_Y = -48;
            gBattle_BG1_X = 240;
            gBattle_BG2_X = -240;
        }
        break;
    case 2:
        gBattle_WIN0V += 0x100;
        if ((gBattle_WIN0V & 0xFF00) != 0x100)
            gBattle_WIN0V--;

        if ((gBattle_WIN0V & 0xFF00) == 0x2000)
        {
            gTasks[taskId].data[0]++;
            gTasks[taskId].data[2] = 240;
            gIntroSlideFlags &= ~1;
        }
        break;
    case 3:
        if ((gBattle_WIN0V & 0xFF00) != 0x4C00)
            gBattle_WIN0V += 0x3FC;

        if (gTasks[taskId].data[2])
            gTasks[taskId].data[2] -= 2;

        gBattle_BG1_X = gTasks[taskId].data[2];
        gBattle_BG2_X = -gTasks[taskId].data[2];
        if (!gTasks[taskId].data[2])
            gTasks[taskId].data[0]++;
        break;
    case 4:
        gBattle_BG0_Y += 2;
        gBattle_BG2_Y += 2;
        if ((gBattle_WIN0V & 0xFF00) != 0x5000)
            gBattle_WIN0V += 0xFF;

        if (!gBattle_BG0_Y)
        {
            CpuFill32(0, (void *)BG_SCREEN_ADDR(28), BG_SCREEN_SIZE * 4);
            SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) & ~DISPCNT_WIN1_ON);
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 0);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 0);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(28) | BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(30) | BGCNT_TXT512x256);
            gScanlineEffect.state = 3;
            gTasks[taskId].data[0]++;
        }
        break;
    case 5:
        sub_811828C(taskId);
        break;
    }
}

void sub_8118FBC(int bgId, u8 arg1, u8 arg2, u8 battlerPosition, u8 arg4, u8 *arg5, u16 *arg6, u16 tilesOffset)
{
    int i, j;
    u8 battler = GetBattlerAtPosition(battlerPosition);
    int offset = tilesOffset;
    CpuCopy16(gMonSpritesGfxPtr->sprites[battlerPosition] + BG_SCREEN_SIZE * gBattleMonForms[battler], arg5, BG_SCREEN_SIZE);
    LoadBgTiles(bgId, arg5, 0x1000, tilesOffset);
    for (i = arg2; i < arg2 + 8; i++)
    {
        for (j = arg1; j < arg1 + 8; j++)
        {
            arg6[i * 32 + j] = offset | (arg4 << 12);
            offset++;
        }
    }

    LoadBgTilemap(bgId, arg6, BG_SCREEN_SIZE, 0);
}

#ifdef NONMATCHING
void unref_sub_8119094(u8 arg0, u8 arg1, u8 battlerPosition, u8 arg3, u8 arg4, u16 arg5, u8 arg6, u8 arg7)
{
    int i, j;
    int offset;
    DmaCopy16(3, gMonSpritesGfxPtr->sprites[battlerPosition] + BG_SCREEN_SIZE * arg3, (void *)BG_SCREEN_ADDR(0) + arg5, BG_SCREEN_SIZE);
    offset = (arg5 >> 5) - (arg7 << 9);
    for (i = arg1; i < arg1 + 8; i++)
    {
        for (j = arg0; j < arg0 + 8; j++)
        {
            ((u16 *)BG_VRAM)[i * 32 + j + (arg6 * 0x400) + arg0] = offset | (arg4 << 12);
            offset++;
        }
    }
}
#else
NAKED
void unref_sub_8119094(u8 arg0, u8 arg1, u8 battlerPosition, u8 arg3, u8 arg4, u16 arg5, u8 arg6, u8 arg7)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x4\n\
    ldr r4, [sp, 0x24]\n\
    ldr r5, [sp, 0x28]\n\
    mov r8, r5\n\
    ldr r5, [sp, 0x2C]\n\
    ldr r6, [sp, 0x30]\n\
    mov r9, r6\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    mov r12, r0\n\
    lsls r1, 24\n\
    lsls r2, 24\n\
    lsls r3, 24\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    mov r10, r4\n\
    mov r7, r8\n\
    lsls r7, 16\n\
    lsrs r6, r7, 16\n\
    lsls r5, 24\n\
    lsrs r5, 24\n\
    mov r0, r9\n\
    lsls r0, 24\n\
    mov r9, r0\n\
    ldr r4, =0x040000d4\n\
    ldr r0, =gMonSpritesGfxPtr\n\
    ldr r0, [r0]\n\
    lsrs r2, 22\n\
    adds r0, 0x4\n\
    adds r0, r2\n\
    lsrs r3, 13\n\
    ldr r0, [r0]\n\
    adds r0, r3\n\
    str r0, [r4]\n\
    movs r0, 0xC0\n\
    lsls r0, 19\n\
    adds r6, r0\n\
    str r6, [r4, 0x4]\n\
    ldr r0, =0x80000400\n\
    str r0, [r4, 0x8]\n\
    ldr r0, [r4, 0x8]\n\
    adds r2, r7, 0\n\
    lsrs r2, 21\n\
    mov r6, r9\n\
    lsrs r6, 15\n\
    subs r4, r2, r6\n\
    lsrs r0, r1, 24\n\
    adds r1, r0, 0\n\
    adds r1, 0x8\n\
    cmp r0, r1\n\
    bge _08119148\n\
    mov r9, r1\n\
    mov r7, r12\n\
    lsls r7, 1\n\
    mov r8, r7\n\
    lsls r5, 11\n\
    str r5, [sp]\n\
_08119110:\n\
    mov r2, r12\n\
    adds r3, r2, 0\n\
    adds r3, 0x8\n\
    adds r5, r0, 0x1\n\
    cmp r2, r3\n\
    bge _08119142\n\
    mov r1, r10\n\
    lsls r6, r1, 12\n\
    lsls r0, 6\n\
    movs r7, 0xC0\n\
    lsls r7, 19\n\
    adds r0, r7\n\
    ldr r1, [sp]\n\
    adds r0, r1, r0\n\
    mov r7, r8\n\
    adds r1, r7, r0\n\
    subs r2, r3, r2\n\
_08119132:\n\
    adds r0, r4, 0\n\
    orrs r0, r6\n\
    strh r0, [r1]\n\
    adds r4, 0x1\n\
    adds r1, 0x2\n\
    subs r2, 0x1\n\
    cmp r2, 0\n\
    bne _08119132\n\
_08119142:\n\
    adds r0, r5, 0\n\
    cmp r0, r9\n\
    blt _08119110\n\
_08119148:\n\
    add sp, 0x4\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif
