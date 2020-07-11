#include "global.h"
#include "sprite.h"
#include "decompress.h"
#include "unk_transition.h"
#include "battle_transition.h"
#include "task.h"
#include "palette.h"
#include "trig.h"
#include "bg.h"
#include "gpu_regs.h"
#include "constants/rgb.h"

typedef bool8 (*TransitionStateFunc)(struct Task *task);

// this file's functions
static void sub_81DA848(struct Sprite *sprite);
static void sub_81DA9BC(struct Sprite *sprite);
static bool8 sub_81DAACC(struct Task *task);
static bool8 sub_81DAC14(struct Task *task);
static bool8 sub_81DABBC(struct Task *task);
static bool8 sub_81DAB4C(struct Task *task);
static bool8 sub_81DAC80(struct Task *task);
static bool8 sub_81DACEC(struct Task *task);
static bool8 sub_81DAD58(struct Task *task);
static bool8 sub_81DADC4(struct Task *task);
static bool8 sub_81DAE44(struct Task *task);
static bool8 sub_81DAEB0(struct Task *task);
static bool8 sub_81DAF34(struct Task *task);
static bool8 sub_81DAFA0(struct Task *task);
static bool8 sub_81DB02C(struct Task *task);
static bool8 sub_81DB098(struct Task *task);
static bool8 sub_81DB124(struct Task *task);
static bool8 sub_81DB190(struct Task *task);
static bool8 sub_81DB224(struct Task *task);
static bool8 sub_81DB290(struct Task *task);
static bool8 sub_81DB328(struct Task *task);

// const rom data
static const u32 gUnknown_0862AD54[] = INCBIN_U32("graphics/battle_transitions/frontier_transition.4bpp.lz");
static const u32 gUnknown_0862AF30[] = INCBIN_U32("graphics/battle_transitions/frontier_transition.bin");
static const u32 gUnknown_0862B0DC[] = INCBIN_U32("graphics/battle_transitions/frontier_transition_circles.4bpp.lz");
static const u16 gUnknown_0862B53C[] = INCBIN_U16("graphics/battle_transitions/frontier_transition.gbapal");

// Unused Empty data.
static const u8 sFiller[0x1C0] = {0};

static const struct OamData sOamData_862B71C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct CompressedSpriteSheet sUnknown_0862B724 =
{
    .data = gUnknown_0862B0DC,
    .size = 0x1800,
    .tag = 11920
};

static const struct SpritePalette sUnknown_0862B72C =
{
    .data = gUnknown_0862B53C,
    .tag = 11920
};

static const union AnimCmd sSpriteAnim_862B734[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862B73C[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_862B744[] =
{
    ANIMCMD_FRAME(128, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_862B74C[] =
{
    sSpriteAnim_862B734,
    sSpriteAnim_862B73C,
    sSpriteAnim_862B744
};

static const struct SpriteTemplate sUnknown_0862B758 =
{
    .tileTag = 11920,
    .paletteTag = 11920,
    .oam = &sOamData_862B71C,
    .anims = sSpriteAnimTable_862B74C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const TransitionStateFunc sPhase2_34_Funcs[] =
{
    sub_81DAACC,
    sub_81DAC14,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DAC80
};

static const TransitionStateFunc sPhase2_35_Funcs[] =
{
    sub_81DAACC,
    sub_81DACEC,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DAD58
};

static const TransitionStateFunc sPhase2_36_Funcs[] =
{
    sub_81DAACC,
    sub_81DADC4,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DAE44
};

static const TransitionStateFunc sPhase2_37_Funcs[] =
{
    sub_81DAACC,
    sub_81DAEB0,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DAF34
};

static const TransitionStateFunc sPhase2_38_Funcs[] =
{
    sub_81DAACC,
    sub_81DAFA0,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DB02C
};

static const TransitionStateFunc sPhase2_39_Funcs[] =
{
    sub_81DAACC,
    sub_81DB098,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DB124
};

static const TransitionStateFunc sPhase2_40_Funcs[] =
{
    sub_81DAACC,
    sub_81DB190,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DB224
};

static const TransitionStateFunc sPhase2_41_Funcs[] =
{
    sub_81DAACC,
    sub_81DB290,
    sub_81DABBC,
    sub_81DAB4C,
    sub_81DB328
};

// code
static void sub_81DA700(void)
{
    u16 *dst1, *dst2;

    GetBg0TilesDst(&dst1, &dst2);
    LZ77UnCompVram(gUnknown_0862AD54, dst2);
    LZ77UnCompVram(gUnknown_0862AF30, dst1);
    LoadPalette(gUnknown_0862B53C, 0xF0, 0x20);
    LoadCompressedSpriteSheet(&sUnknown_0862B724);
    LoadSpritePalette(&sUnknown_0862B72C);
}

static u8 sub_81DA74C(s16 x, s16 y, u8 arg2, u8 arg3, s8 arg4, s8 arg5, u8 spriteAnimNum)
{
    u8 spriteId = CreateSprite(&sUnknown_0862B758, x, y, 0);

    switch (spriteAnimNum)
    {
    case 0:
        gSprites[spriteId].data[0] = 120;
        gSprites[spriteId].data[1] = 45;
        break;
    case 1:
        gSprites[spriteId].data[0] = 89;
        gSprites[spriteId].data[1] = 97;
        break;
    case 2:
        gSprites[spriteId].data[0] = 151;
        gSprites[spriteId].data[1] = 97;
        break;
    }

    gSprites[spriteId].data[2] = arg4;
    gSprites[spriteId].data[3] = arg5;
    gSprites[spriteId].data[6] = arg2;
    gSprites[spriteId].data[7] = arg3;
    gSprites[spriteId].data[4] = 0;
    gSprites[spriteId].data[5] = 0;

    StartSpriteAnim(&gSprites[spriteId], spriteAnimNum);
    gSprites[spriteId].callback = sub_81DA848;

    return spriteId;
}

static void sub_81DA848(struct Sprite *sprite)
{
    s16 *data = sprite->data;

    if (sprite->pos1.x == data[0] && sprite->pos1.y == data[1])
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (data[4] == data[6])
        {
            sprite->pos1.x += data[2];
            data[4] = 0;
        }
        else
        {
            data[4]++;
        }

        if (data[5] == data[7])
        {
            sprite->pos1.y += data[3];
            data[5] = 0;
        }
        else
        {
            data[5]++;
        }
    }
}

static u8 sub_81DA8BC(s16 x, s16 y, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, u8 spriteAnimNum)
{
    u8 spriteId = CreateSprite(&sUnknown_0862B758, x, y, 0);

    switch (spriteAnimNum)
    {
    case 0:
        gSprites[spriteId].data[0] = 120;
        gSprites[spriteId].data[1] = 45;
        break;
    case 1:
        gSprites[spriteId].data[0] = 89;
        gSprites[spriteId].data[1] = 97;
        break;
    case 2:
        gSprites[spriteId].data[0] = 151;
        gSprites[spriteId].data[1] = 97;
        break;
    }

    gSprites[spriteId].data[2] = arg2;
    gSprites[spriteId].data[3] = arg3;
    gSprites[spriteId].data[4] = arg4;
    gSprites[spriteId].data[5] = arg5;
    gSprites[spriteId].data[6] = arg6;

    StartSpriteAnim(&gSprites[spriteId], spriteAnimNum);
    gSprites[spriteId].callback = sub_81DA9BC;

    return spriteId;
}

static void sub_81DA9BC(struct Sprite *sprite)
{
    sprite->pos2.x = (Sin2(sprite->data[2]) * sprite->data[4]) >> 12; // div by 4096
    sprite->pos2.y = (Cos2(sprite->data[2]) * sprite->data[4]) >> 12; // div by 4096

    sprite->data[2] = (sprite->data[2] + sprite->data[3]) % 360;

    if (sprite->data[4] != sprite->data[5])
        sprite->data[4] += sprite->data[6];
    else
        sprite->callback = SpriteCallbackDummy;
}

#define tState          data[0]

static void sub_81DAA20(struct Task *task)
{
    FreeSpriteTilesByTag(11920);
    FreeSpritePaletteByTag(11920);

    DestroySprite(&gSprites[task->data[4]]);
    DestroySprite(&gSprites[task->data[5]]);
    DestroySprite(&gSprites[task->data[6]]);
}

static bool8 sub_81DAA74(struct Task *task)
{
    if (gSprites[task->data[4]].callback == SpriteCallbackDummy
        && gSprites[task->data[5]].callback == SpriteCallbackDummy
        && gSprites[task->data[6]].callback == SpriteCallbackDummy)
        return TRUE;
    else
        return FALSE;
}

static bool8 sub_81DAACC(struct Task *task)
{
    if (task->data[1] == 0)
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);

        task->data[1]++;
        return FALSE;
    }
    else
    {
        sub_81DA700();
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgY(0, 0x500, 2);

        task->data[1] = 0;
        task->tState++;
        return TRUE;
    }
}

static bool8 sub_81DAB4C(struct Task *task)
{
    if (task->data[2] == 0)
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON);

    if (task->data[2] == 16)
    {
        if (task->data[3] == 31)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 0x10, RGB_BLACK);
            task->tState++;
        }
        else
        {
            task->data[3]++;
        }
    }
    else
    {
        u16 blnd;

        task->data[2]++;
        blnd = task->data[2];
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(blnd, 16 - blnd));
    }

    return FALSE;
}

static bool8 sub_81DABBC(struct Task *task)
{
    if (sub_81DAA74(task) == TRUE)
        task->tState++;

    return FALSE;
}

void Phase2Task_34(u8 taskId)
{
    while (sPhase2_34_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DAC14(struct Task *task)
{
    task->data[4] = sub_81DA74C(120, -51, 0, 0, 0,   2, 0);
    task->data[5] = sub_81DA74C(-7,  193, 0, 0, 2,  -2, 1);
    task->data[6] = sub_81DA74C(247, 193, 0, 0, -2, -2, 2);

    task->tState++;
    return FALSE;
}

static bool8 sub_81DAC80(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_34));
    }

    return FALSE;
}

void Phase2Task_35(u8 taskId)
{
    while (sPhase2_35_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DACEC(struct Task *task)
{
    task->data[4] = sub_81DA74C(120, 197, 0, 0, 0, -4, 0);
    task->data[5] = sub_81DA74C(241, 59,  0, 1, -4, 2, 1);
    task->data[6] = sub_81DA74C(-1,  59,  0, 1, 4,  2, 2);

    task->tState++;
    return FALSE;
}

static bool8 sub_81DAD58(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_35));
    }

    return FALSE;
}

void Phase2Task_36(u8 taskId)
{
    while (sPhase2_36_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DADC4(struct Task *task)
{
    task->data[4] = sub_81DA8BC(120, 45, 12,  4, 128, 0, -4, 0);
    task->data[5] = sub_81DA8BC(89,  97, 252, 4, 128, 0, -4, 1);
    task->data[6] = sub_81DA8BC(151, 97, 132, 4, 128, 0, -4, 2);

    task->tState++;
    return FALSE;
}

static bool8 sub_81DAE44(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_36));
    }

    return FALSE;
}

void Phase2Task_37(u8 taskId)
{
    while (sPhase2_37_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DAEB0(struct Task *task)
{
    task->data[4] = sub_81DA8BC(120, 80, 284, 8, 131, 35, -3, 0);
    task->data[5] = sub_81DA8BC(120, 80, 44,  8, 131, 35, -3, 1);
    task->data[6] = sub_81DA8BC(121, 80, 164, 8, 131, 35, -3, 2);

    task->tState++;
    return FALSE;
}

static bool8 sub_81DAF34(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_37));
    }

    return FALSE;
}

void Phase2Task_38(u8 taskId)
{
    while (sPhase2_38_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DAFA0(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = sub_81DA74C(120, -51, 0, 0, 0, 4,  0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = sub_81DA74C(-7,  193, 0, 0, 4, -4, 1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = sub_81DA74C(247, 193, 0, 0, -4, -4, 2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 sub_81DB02C(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_38));
    }

    return FALSE;
}

void Phase2Task_39(u8 taskId)
{
    while (sPhase2_39_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DB098(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = sub_81DA74C(120, 197, 0, 0, 0, -8,  0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = sub_81DA74C(241, 78,  0, 0, -8, 1,  1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = sub_81DA74C(-1,  78,  0, 0, 8,  1,  2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 sub_81DB124(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_39));
    }

    return FALSE;
}

void Phase2Task_40(u8 taskId)
{
    while (sPhase2_40_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DB190(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = sub_81DA8BC(120, 45, 12,  4, 128, 0, -4, 0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = sub_81DA8BC(89,  97, 252, 4, 128, 0, -4, 1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = sub_81DA8BC(151, 97, 132, 4, 128, 0, -4, 2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 sub_81DB224(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_40));
    }

    return FALSE;
}

void Phase2Task_41(u8 taskId)
{
    while (sPhase2_41_Funcs[gTasks[taskId].tState](&gTasks[taskId]));
}

static bool8 sub_81DB290(struct Task *task)
{
    if (task->data[1] == 0)
    {
        task->data[4] = sub_81DA8BC(120, 80, 284, 8, 131, 35, -3, 0);
    }
    else if (task->data[1] == 16)
    {
        task->data[5] = sub_81DA8BC(120, 80, 44,  8, 131, 35, -3, 1);
    }
    else if (task->data[1] == 32)
    {
        task->data[6] = sub_81DA8BC(121, 80, 164, 8, 131, 35, -3, 2);
        task->tState++;
    }

    task->data[1]++;
    return FALSE;
}

static bool8 sub_81DB328(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        sub_81DAA20(task);
        DestroyTask(FindTaskIdByFunc(Phase2Task_41));
    }

    return FALSE;
}
