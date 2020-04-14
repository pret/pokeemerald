#include "global.h"
#include "gpu_regs.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "strings.h"
#include "party_menu.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "secret_base.h"
#include "event_data.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "metatile_behavior.h"
#include "string_util.h"
#include "constants/field_effects.h"
#include "constants/metatile_behaviors.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"
#include "constants/tv.h"
#include "constants/vars.h"


EWRAM_DATA struct MapPosition gPlayerFacingPosition = {0};

static void sub_80F9C90(u8);
static void sub_80F9DFC(u8);

static void Task_SecretBasePCTurnOn(u8);

static void Task_PopSecretBaseBalloon(u8);
static void DoBalloonSoundEffect(s16);

static void Task_WateringBerryTreeAnim_1(u8);
static void Task_WateringBerryTreeAnim_2(u8);
static void Task_WateringBerryTreeAnim_3(u8);

static void sub_80F9C44(TaskFunc, u16, u16, u8);

static void FieldCallback_SecretBaseCave(void);
static void CaveEntranceSpriteCallback1(struct Sprite *);
static void CaveEntranceSpriteCallback2(struct Sprite *);
static void CaveEntranceSpriteCallbackEnd(struct Sprite *);
static void StartSecretBaseCaveFieldEffect(void);

static void FieldCallback_SecretBaseTree(void);
static void TreeEntranceSpriteCallback1(struct Sprite *);
static void TreeEntranceSpriteCallback2(struct Sprite *);
static void TreeEntranceSpriteCallbackEnd(struct Sprite *);
static void StartSecretBaseTreeFieldEffect(void);

static void FieldCallback_SecretBaseShrub(void);
static void ShrubEntranceSpriteCallback1(struct Sprite *);
static void ShrubEntranceSpriteCallback2(struct Sprite *);
static void ShrubEntranceSpriteCallbackEnd(struct Sprite *);
static void StartSecretBaseShrubFieldEffect(void);

static void SpriteCB_SandPillar_0(struct Sprite *);
static void SpriteCB_SandPillar_1(struct Sprite *);
static void SpriteCB_SandPillar_2(struct Sprite *);

static const u8 gSpriteImage_858D978[] = INCBIN_U8("graphics/unknown/858E588/0.4bpp");
static const u8 gSpriteImage_858D9F8[] = INCBIN_U8("graphics/unknown/858E588/1.4bpp");
static const u8 gSpriteImage_858DA78[] = INCBIN_U8("graphics/unknown/858E588/2.4bpp");
static const u8 gSpriteImage_858DAF8[] = INCBIN_U8("graphics/unknown/858E588/3.4bpp");
static const u8 gSpriteImage_858DB78[] = INCBIN_U8("graphics/unknown/858E588/4.4bpp");

static const u8 gUnusedEmptySpace_858DBF8[32] = {0};

static const u16 gFieldEffectObjectPalette7[] = INCBIN_U16("graphics/field_effects/palettes/07.gbapal");
static const u8 gSpriteImage_858DC38[] = INCBIN_U8("graphics/unknown/858E5D8/0.4bpp");
static const u8 gSpriteImage_858DCB8[] = INCBIN_U8("graphics/unknown/858E5D8/1.4bpp");
static const u8 gSpriteImage_858DD38[] = INCBIN_U8("graphics/unknown/858E5D8/2.4bpp");
static const u8 gSpriteImage_858DDB8[] = INCBIN_U8("graphics/unknown/858E5D8/3.4bpp");
static const u8 gSpriteImage_858DE38[] = INCBIN_U8("graphics/unknown/858E5D8/4.4bpp");
static const u8 gSpriteImage_858DEB8[] = INCBIN_U8("graphics/unknown/858E5B0/0.4bpp");
static const u8 gSpriteImage_858DF38[] = INCBIN_U8("graphics/unknown/858E5B0/1.4bpp");
static const u8 gSpriteImage_858DFB8[] = INCBIN_U8("graphics/unknown/858E5B0/2.4bpp");
static const u8 gSpriteImage_858E038[] = INCBIN_U8("graphics/unknown/858E5B0/3.4bpp");
static const u8 gSpriteImage_858E0B8[] = INCBIN_U8("graphics/unknown/858E5B0/4.4bpp");
static const u8 gSpriteImage_858E138[] = INCBIN_U8("graphics/unknown/858E5B0/5.4bpp");
static const u16 gFieldEffectObjectPalette8[] = INCBIN_U16("graphics/field_effects/palettes/08.gbapal");
static const u8 gSpriteImage_858E1D8[] = INCBIN_U8("graphics/unknown/858E674/0.4bpp");
static const u8 gSpriteImage_858E2D8[] = INCBIN_U8("graphics/unknown/858E674/1.4bpp");
static const u8 gSpriteImage_858E3D8[] = INCBIN_U8("graphics/unknown/858E674/2.4bpp");

static const struct OamData gOamData_858E4D8 =
{
    .y = 0,
    .x = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

static const union AnimCmd gSpriteAnim_858E4E0[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_858E4F8[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_858E510[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_858E528[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_858E540[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_858E558[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const gSpriteAnimTable_858E570[] =
{
    gSpriteAnim_858E4E0,
};

static const union AnimCmd *const gSpriteAnimTable_858E574[] =
{
    gSpriteAnim_858E4F8,
    gSpriteAnim_858E510,
    gSpriteAnim_858E528,
    gSpriteAnim_858E540,
};

static const union AnimCmd *const gSpriteAnimTable_858E584[] =
{
    gSpriteAnim_858E558,
};

static const struct SpriteFrameImage gUnknown_858E588[] =
{
    {gSpriteImage_858D978, 0x80},
    {gSpriteImage_858D9F8, 0x80},
    {gSpriteImage_858DA78, 0x80},
    {gSpriteImage_858DAF8, 0x80},
    {gSpriteImage_858DB78, 0x80},
};

static const struct SpriteFrameImage gUnknown_858E5B0[] =
{
    {gSpriteImage_858DEB8, 0x80},
    {gSpriteImage_858DF38, 0x80},
    {gSpriteImage_858DFB8, 0x80},
    {gSpriteImage_858E038, 0x80},
    {gSpriteImage_858E0B8, 0x80},
};

static const struct SpriteFrameImage gUnknown_858E5D8[] =
{
    {gSpriteImage_858DC38, 0x80},
    {gSpriteImage_858DCB8, 0x80},
    {gSpriteImage_858DD38, 0x80},
    {gSpriteImage_858DDB8, 0x80},
    {gSpriteImage_858DE38, 0x80},
};

static const struct SpriteTemplate gUnknown_0858E600 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1003,
    .oam = &gOamData_858E4D8,
    .anims = gSpriteAnimTable_858E570,
    .images = gUnknown_858E588,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = CaveEntranceSpriteCallback1,
};

static const struct SpriteTemplate gUnknown_0858E618 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1008,
    .oam = &gOamData_858E4D8,
    .anims = gSpriteAnimTable_858E574,
    .images = gUnknown_858E5B0,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = TreeEntranceSpriteCallback1,
};

static const struct SpriteTemplate gUnknown_0858E630 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1008,
    .oam = &gOamData_858E4D8,
    .anims = gSpriteAnimTable_858E584,
    .images = gUnknown_858E5D8,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ShrubEntranceSpriteCallback1,
};

const struct SpritePalette gFieldEffectObjectPaletteInfo7 = {gFieldEffectObjectPalette7, 0x1003};
const struct SpritePalette gFieldEffectObjectPaletteInfo8 = {gFieldEffectObjectPalette8, 0x1008};

static const struct OamData gOamData_858E658 =
{
    .x = 0,
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 2,
};

static const union AnimCmd gSpriteAnim_858E660[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_END,
};

static const union AnimCmd *const gSpriteAnimTable_858E670[] =
{
    gSpriteAnim_858E660,
};

static const struct SpriteFrameImage gUnknown_0858E674[] =
{
    {gSpriteImage_858E1D8, 0x100},
    {gSpriteImage_858E2D8, 0x100},
    {gSpriteImage_858E3D8, 0x100},
};

static const struct SpriteTemplate gUnknown_0858E68C =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x100E,
    .oam = &gOamData_858E658,
    .anims = gSpriteAnimTable_858E670,
    .images = gUnknown_0858E674,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SandPillar_0,
};

// This uses one of the secret base palettes, so there is no "graphics/field_effects/palettes/09.pal" file.
const struct SpritePalette gFieldEffectObjectPaletteInfo9 = {gTilesetPalettes_SecretBase[5], 0x100E};

static const u8 gSpriteImage_858E6AC[] = INCBIN_U8("graphics/unknown/858E84C/0.4bpp");
static const u8 gSpriteImage_858E72C[] = INCBIN_U8("graphics/unknown/858E84C/1.4bpp");
static const u8 gSpriteImage_858E7AC[] = INCBIN_U8("graphics/unknown/858E84C/2.4bpp");
static const u16 gUnknown_0858E82C[] = INCBIN_U16("graphics/unknown/unknown_58E82C.gbapal");

static const struct SpriteFrameImage gUnknown_0858E84C[] =
{
    {gSpriteImage_858E6AC, sizeof(gSpriteImage_858E6AC)},
    {gSpriteImage_858E72C, sizeof(gSpriteImage_858E72C)},
    {gSpriteImage_858E7AC, sizeof(gSpriteImage_858E7AC)},
};

static const struct SpritePalette gUnknown_0858E864 = {gUnknown_0858E82C, 0x1000};

static const union AnimCmd gSpriteAnim_858E86C[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(2, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gSpriteAnimTable_858E87C[] =
{
    gSpriteAnim_858E86C,
};

static const struct SpriteTemplate gUnknown_0858E880 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0x1000,
    .oam = &gObjectEventBaseOam_32x8,
    .anims = gSpriteAnimTable_858E87C,
    .images = gUnknown_0858E84C,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

void sub_80F9BCC(u16 a0, u16 a1, u8 a2)
{
    sub_80F9C44(sub_80F9C90, a0, a1, a2);
}

void sub_80F9BF4(u16 a0, u16 a1, u8 a2)
{
    sub_80F9C44(sub_80F9DFC, a0, a1, a2);
}

bool8 sub_80F9C1C(void)
{
    return FuncIsActiveTask(sub_80F9C90);
}

bool8 sub_80F9C30(void)
{
    return FuncIsActiveTask(sub_80F9DFC);
}

static void sub_80F9C44(void (*taskfunc) (u8), u16 a1, u16 a2, u8 a3)
{
    u8 taskId = CreateTask(taskfunc, a3);

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = a1 == 0 ? 16 : a1;
    gTasks[taskId].data[2] = a1 == 0 ? 20 : a1;
    gTasks[taskId].func(taskId);
}

static void sub_80F9C90(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[3] = 0x78;
        task->data[4] = 0x78;
        task->data[5] = 0x50;
        task->data[6] = 0x51;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[4]));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[6]));
        SetGpuReg(REG_OFFSET_WININ, 0x3F);
        SetGpuReg(REG_OFFSET_WINOUT, 0);

        break;
    case 1:
        task->data[7] = GetGpuReg(REG_OFFSET_BLDCNT);
        task->data[8] = GetGpuReg(REG_OFFSET_BLDY);

        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 0x10);

        break;
    case 2:
        task->data[3] -= task->data[1];
        task->data[4] += task->data[1];

        if (task->data[3] < 1 || task->data[4] > 0xEF)
        {
            task->data[3] = 0;
            task->data[4] = 0xF0;
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, task->data[7]);
            BlendPalettes(0xFFFFFFFF, 0, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[4]));

        if (task->data[3] != 0)
            return;
        break;
    case 3:
        task->data[5] -= task->data[2];
        task->data[6] += task->data[2];

        if (task->data[5] < 1 || task->data[6] > 0x9F)
        {
            task->data[5] = 0;
            task->data[6] = 0xA0;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[6]));

        if (task->data[5] != 0)
            return;
        break;
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, task->data[7]);
        DestroyTask(taskId);
        return;
    }
    task->data[0]++;
}

static void sub_80F9DFC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    int temp = task->data[0];

    switch (temp)
    {
    case 0:
        gPlttBufferFaded[0] = temp;
        break;
    case 1:
        task->data[3] = 0;
        task->data[4] = 0xF0;
        task->data[5] = 0;
        task->data[6] = 0xA0;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[4]));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[6]));
        SetGpuReg(REG_OFFSET_WININ, 0x3F);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 2:
        task->data[5] += task->data[2];
        task->data[6] -= task->data[2];

        if (task->data[5] > 0x4F || task->data[6] < 0x52)
        {
            task->data[5] = 0x50;
            task->data[6] = 0x51;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
            SetGpuReg(REG_OFFSET_BLDY, 0x10);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->data[5], task->data[6]));

        if (task->data[5] != 0x50)
            return;
        break;
    case 3:
        task->data[3] += task->data[1];
        task->data[4] -= task->data[1];

        if (task->data[3] > 0x77 || task->data[4] < 0x79)
        {
            task->data[3] = 0x78;
            task->data[4] = 0x78;
            BlendPalettes(-1, 0x10, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->data[3], task->data[4]));

        if (task->data[3] != 0x78)
            return;
        break;
    default:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
        return;
    }
    task->data[0]++;
}

static void SetCurrentSecretBase(void)
{
    SetCurSecretBaseIdFromPosition(&gPlayerFacingPosition, gMapHeader.events);
    TrySetCurSecretBaseIndex();
}

static void AdjustSecretPowerSpritePixelOffsets(void)
{
    if (gPlayerAvatar.flags & 0x6)
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
    else
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
}

bool8 SetUpFieldMove_SecretPower(void)
{
    u8 mb;

    CheckPlayerHasSecretBase();

    if (gSpecialVar_Result == 1 || GetPlayerFacingDirection() != DIR_NORTH)
        return FALSE;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y);

    if (MetatileBehavior_IsSecretBaseCave(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseCave;
        return TRUE;
    }

    if (MetatileBehavior_IsSecretBaseTree(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseTree;
        return TRUE;
    }

    if (MetatileBehavior_IsSecretBaseShrub(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseShrub;
        return TRUE;
    }

    return FALSE;
}

static void FieldCallback_SecretBaseCave(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(SecretBase_EventScript_CaveUseSecretPower);
}

bool8 FldEff_UseSecretPowerCave(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartSecretBaseCaveFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseCaveFieldEffect;

    return FALSE;
}

static void StartSecretBaseCaveFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_CAVE);
    FieldEffectStart(FLDEFF_SECRET_POWER_CAVE);
}

bool8 FldEff_SecretPowerCave(void)
{
    AdjustSecretPowerSpritePixelOffsets();
    CreateSprite(&gUnknown_0858E600,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);
    return FALSE;
}

static void CaveEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_W088);

    sprite->data[0] = 0;
    sprite->callback = CaveEntranceSpriteCallback2;
}

static void CaveEntranceSpriteCallback2(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        if (++sprite->data[0] == 20)
            ToggleSecretBaseEntranceMetatile();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = CaveEntranceSpriteCallbackEnd;
    }
}

static void CaveEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_CAVE);
    EnableBothScriptContexts();
}

static void FieldCallback_SecretBaseTree(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(SecretBase_EventScript_TreeUseSecretPower);
}

bool8 FldEff_UseSecretPowerTree(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartSecretBaseTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseTreeFieldEffect;

    return FALSE;
}

static void StartSecretBaseTreeFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_TREE);
    FieldEffectStart(FLDEFF_SECRET_POWER_TREE);
}

bool8 FldEff_SecretPowerTree(void)
{
    s16 mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y) & 0xFFF;

    if (mb == MB_SECRET_BASE_SPOT_TREE_LEFT)
        gFieldEffectArguments[7] = 0;

    if (mb == MB_SECRET_BASE_SPOT_TREE_RIGHT)
        gFieldEffectArguments[7] = 2;

    AdjustSecretPowerSpritePixelOffsets();

    CreateSprite(&gUnknown_0858E618,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    if (gFieldEffectArguments[7] == 1 || gFieldEffectArguments[7] == 3)
        ToggleSecretBaseEntranceMetatile();

    return FALSE;
}

static void TreeEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_W010);

    sprite->animNum = gFieldEffectArguments[7];
    sprite->data[0] = 0;
    sprite->callback = TreeEntranceSpriteCallback2;
}

static void TreeEntranceSpriteCallback2(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] >= 40)
    {
        if (gFieldEffectArguments[7] == 0 || gFieldEffectArguments[7] == 2)
            ToggleSecretBaseEntranceMetatile();

        sprite->data[0] = 0;
        sprite->callback = TreeEntranceSpriteCallbackEnd;
    }
}

static void TreeEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_TREE);
    EnableBothScriptContexts();
}

static void FieldCallback_SecretBaseShrub(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext1_SetupScript(SecretBase_EventScript_ShrubUseSecretPower);
}

bool8 FldEff_UseSecretPowerShrub(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)StartSecretBaseShrubFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseShrubFieldEffect;

    return FALSE;
}

static void StartSecretBaseShrubFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_SHRUB);
    FieldEffectStart(FLDEFF_SECRET_POWER_SHRUB);
}

bool8 FldEff_SecretPowerShrub(void)
{
    AdjustSecretPowerSpritePixelOffsets();

    CreateSprite(&gUnknown_0858E630,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    return FALSE;
}

static void ShrubEntranceSpriteCallback1(struct Sprite *sprite)
{
    PlaySE(SE_W077);

    sprite->data[0] = 0;
    sprite->callback = ShrubEntranceSpriteCallback2;
}

static void ShrubEntranceSpriteCallback2(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        sprite->data[0]++;

        if (sprite->data[0] == 20)
            ToggleSecretBaseEntranceMetatile();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = ShrubEntranceSpriteCallbackEnd;
    }
}

static void ShrubEntranceSpriteCallbackEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_SHRUB);
    EnableBothScriptContexts();
}

bool8 FldEff_SecretBasePCTurnOn(void)
{
    s16 x, y;
    u8 taskId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    taskId = CreateTask(Task_SecretBasePCTurnOn, 0);
    gTasks[taskId].data[0] = x;
    gTasks[taskId].data[1] = y;
    gTasks[taskId].data[2] = 0;

    return FALSE;
}

static void Task_SecretBasePCTurnOn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[2])
    {
    case 4:
    case 12:
        MapGridSetMetatileIdAt(data[0], data[1], METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(data[0], data[1]);
        break;
    case 8:
    case 16:
        MapGridSetMetatileIdAt(data[0], data[1], METATILE_SecretBase_PC);
        CurrentMapDrawMetatileAt(data[0], data[1]);
        break;
    case 20:
        MapGridSetMetatileIdAt(data[0], data[1], METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(data[0], data[1]);
        FieldEffectActiveListRemove(FLDEFF_PCTURN_ON);
        EnableBothScriptContexts();
        DestroyTask(taskId);
        return;
    }

    data[2]++;
}

void DoSecretBasePCTurnOffEffect(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    PlaySE(SE_PC_OFF);

    if (!VarGet(VAR_CURRENT_SECRET_BASE))
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_PC | METATILE_COLLISION_MASK);
    else
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_RegisterPC | METATILE_COLLISION_MASK);

    CurrentMapDrawMetatileAt(x, y);
}

void PopSecretBaseBalloon(s16 metatileId, s16 x, s16 y)
{
    u8 taskId = CreateTask(Task_PopSecretBaseBalloon, 0);

    gTasks[taskId].data[0] = metatileId;
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 1;
}

static void Task_PopSecretBaseBalloon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[3] == 6)
        data[3] = 0;
    else
        data[3]++;

    if (data[3] == 0)
    {
        if (data[4] == 2)
            DoBalloonSoundEffect(data[0]);

        MapGridSetMetatileIdAt(data[1], data[2], data[0] + data[4]);
        CurrentMapDrawMetatileAt(data[1], data[2]);

        if (data[4] == 3)
            DestroyTask(taskId);
        else
            data[4]++;
    }
}

static void DoBalloonSoundEffect(s16 metatileId)
{
    switch (metatileId)
    {
    case METATILE_SecretBase_RedBalloon:
        PlaySE(SE_FUUSEN1);
        break;
    case METATILE_SecretBase_BlueBalloon:
        PlaySE(SE_FUUSEN2);
        break;
    case METATILE_SecretBase_YellowBalloon:
        PlaySE(SE_FUUSEN3);
        break;
    case METATILE_SecretBase_MudBall:
        PlaySE(SE_TOY_DANGO);
        break;
    }
}

bool8 FldEff_NopA6FC(void)
{
    return FALSE;
}

bool8 FldEff_NopA700(void)
{
    return FALSE;
}

static void DoSecretBaseBreakableDoorEffect(s16 x, s16 y)
{
    PlaySE(SE_TOY_KABE);
    MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_BreakableDoor_BottomOpen);
    MapGridSetMetatileIdAt(x, y - 1, METATILE_SecretBase_BreakableDoor_TopOpen);
    CurrentMapDrawMetatileAt(x, y);
    CurrentMapDrawMetatileAt(x, y - 1);
}

static void Task_ShatterSecretBaseBreakableDoor(u8 taskId)
{
    if (gTasks[taskId].data[0] == 7)
    {
        DoSecretBaseBreakableDoorEffect(gTasks[taskId].data[1], gTasks[taskId].data[2]);
        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[0]++;
    }
}

void ShatterSecretBaseBreakableDoor(s16 x, s16 y)
{
    u8 dir = GetPlayerFacingDirection();

    if (dir == DIR_SOUTH)
    {
        DoSecretBaseBreakableDoorEffect(x, y);
    }
    else if (dir == DIR_NORTH)
    {
        u8 taskId = CreateTask(Task_ShatterSecretBaseBreakableDoor, 5);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = x;
        gTasks[taskId].data[2] = y;
    }
}

#define tMetatileID data[0]
static void Task_SecretBaseMusicNoteMatSound(u8 taskId)
{
    if (gTasks[taskId].data[1] == 7)
    {
        switch (gTasks[taskId].tMetatileID)
        {
        case METATILE_SecretBase_NoteMat_C_Low:
            PlaySE(SE_TOY_C);
            break;
        case METATILE_SecretBase_NoteMat_D:
            PlaySE(SE_TOY_D);
            break;
        case METATILE_SecretBase_NoteMat_E:
            PlaySE(SE_TOY_E);
            break;
        case METATILE_SecretBase_NoteMat_F:
            PlaySE(SE_TOY_F);
            break;
        case METATILE_SecretBase_NoteMat_G:
            PlaySE(SE_TOY_G);
            break;
        case METATILE_SecretBase_NoteMat_A:
            PlaySE(SE_TOY_A);
            break;
        case METATILE_SecretBase_NoteMat_B:
            PlaySE(SE_TOY_B);
            break;
        case METATILE_SecretBase_NoteMat_C_High:
            PlaySE(SE_TOY_C1);
            break;
        }

        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[1]++;
    }
}

void PlaySecretBaseMusicNoteMatSound(s16 metatileId)
{
    u8 taskId = CreateTask(Task_SecretBaseMusicNoteMatSound, 5);

    gTasks[taskId].tMetatileID = metatileId;
    gTasks[taskId].data[1] = 0;
}
#undef tMetatileID

static void SpriteCB_GlitterMatSparkle(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] == 8)
        PlaySE(SE_W215);

    if (sprite->data[0] >= 32)
        DestroySprite(sprite);
}

void DoSecretBaseGlitterMatSparkle(void)
{
    s16 x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    s16 y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    u8 spriteId;

    sub_80930E0(&x, &y, 8, 4);

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[22], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].oam.paletteNum = 5;
        gSprites[spriteId].callback = SpriteCB_GlitterMatSparkle;
        gSprites[spriteId].data[0] = 0;
    }
}

bool8 FldEff_SandPillar(void)
{
    s16 x, y;

    ScriptContext2_Enable();
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    gFieldEffectArguments[5] = x;
    gFieldEffectArguments[6] = y;

    switch (GetPlayerFacingDirection())
    {
    case DIR_SOUTH:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 32,
                     0);

        break;

    case DIR_NORTH:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y,
                     148);

        break;

    case DIR_WEST:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x - 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);

        break;

    case DIR_EAST:
        CreateSprite(&gUnknown_0858E68C,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 24,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);

        break;
    }

    return FALSE;
}

static void SpriteCB_SandPillar_0(struct Sprite *sprite)
{
    PlaySE(SE_W088);

    if (MapGridGetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1) == METATILE_SecretBase_SandOrnament_TopWall)
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_SecretBase_Wall_TopMid | METATILE_COLLISION_MASK);
    else
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_SecretBase_SandOrnament_BrokenTop);

    MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_SecretBase_Ground);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);

    sprite->data[0] = 0;
    sprite->callback = SpriteCB_SandPillar_1;
}

static void SpriteCB_SandPillar_1(struct Sprite *sprite)
{
    if (sprite->data[0] < 18)
    {
        sprite->data[0]++;
    }
    else
    {
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_SecretBase_SandOrnament_BrokenBase | METATILE_COLLISION_MASK);
        CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_SandPillar_2;
    }
}

static void SpriteCB_SandPillar_2(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SAND_PILLAR);
    EnableBothScriptContexts();
}

void InteractWithShieldOrTVDecoration(void)
{
    s16 x, y;
    s32 metatileId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    metatileId = MapGridGetMetatileIdAt(x, y);

    switch (metatileId)
    {
    case METATILE_SecretBase_GoldShield_Base1:
        ConvertIntToDecimalStringN(gStringVar1, 100, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopy(gStringVar2, gText_Gold);

        gSpecialVar_Result = 0;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_GOLD_SHIELD);
        break;
    case METATILE_SecretBase_SilverShield_Base1:
        ConvertIntToDecimalStringN(gStringVar1, 50, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringCopy(gStringVar2, gText_Silver);

        gSpecialVar_Result = 0;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_SILVER_SHIELD);
        break;
    case METATILE_SecretBase_TV:
        gSpecialVar_Result = 1;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_TV);
        break;
    case METATILE_SecretBase_RoundTV:
        gSpecialVar_Result = 2;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_TV);
        break;
    case METATILE_SecretBase_CuteTV:
        gSpecialVar_Result = 3;

        if (!VarGet(VAR_CURRENT_SECRET_BASE))
            return;

        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | SECRET_BASE_USED_TV);
        break;
    }
}

bool8 sub_80FADE4(u16 metatileId, u8 arg1)
{
    if (!CurMapIsSecretBase())
        return FALSE;

    if (!arg1)
    {
        if (metatileId == METATILE_SecretBase_SandOrnament_Top || metatileId == METATILE_SecretBase_SandOrnament_TopWall)
            return TRUE;
        if (metatileId == METATILE_SecretBase_BreakableDoor_TopClosed)
            return TRUE;
    }
    else
    {
        if (metatileId == METATILE_SecretBase_SandOrnament_Base1)
            return TRUE;
        if (metatileId == METATILE_SecretBase_BreakableDoor_BottomClosed)
            return TRUE;
    }

    return FALSE;
}

static void Task_FieldPoisonEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        data[1] += 2;
        if (data[1] > 8)
            data[0]++;
        break;
    case 1:
        data[1] -= 2;
        if (data[1] == 0)
            data[0]++;
        break;
    case 2:
        DestroyTask(taskId);
        return;
    }
    SetGpuReg(REG_OFFSET_MOSAIC, (data[1] << 4) | data[1]);
}

void FldEffPoison_Start(void)
{
    PlaySE(SE_DOKU);
    CreateTask(Task_FieldPoisonEffect, 80);
}

bool32 FldEffPoison_IsActive(void)
{
    return FuncIsActiveTask(Task_FieldPoisonEffect);
}

static void Task_WateringBerryTreeAnim_0(u8 taskId)
{
    gTasks[taskId].func = Task_WateringBerryTreeAnim_1;
}

static void Task_WateringBerryTreeAnim_1(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!ObjectEventIsMovementOverridden(playerObjEvent)
        || ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        sub_808C228(GetPlayerFacingDirection());
        ObjectEventSetHeldMovement(playerObjEvent, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
        gTasks[taskId].func = Task_WateringBerryTreeAnim_2;
    }
}

static void Task_WateringBerryTreeAnim_2(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        s16 value = gTasks[taskId].data[1]++;

        if (value < 10)
            ObjectEventSetHeldMovement(playerObjEvent, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));

        else
            gTasks[taskId].func = Task_WateringBerryTreeAnim_3;
    }
}

static void Task_WateringBerryTreeAnim_3(u8 taskId)
{
    SetPlayerAvatarTransitionFlags(GetPlayerAvatarFlags());
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

void DoWateringBerryTreeAnim(void)
{
    CreateTask(Task_WateringBerryTreeAnim_0, 80);
}

u8 CreateRecordMixingSprite(void)
{
    u8 spriteId;

    LoadSpritePalette(&gUnknown_0858E864);

    spriteId = CreateSprite(&gUnknown_0858E880, 0, 0, 82);

    if (spriteId == MAX_SPRITES)
    {
        return MAX_SPRITES;
    }
    else
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sub_8092FF0(16, 13, &sprite->pos1.x, &sprite->pos1.y);
        sprite->coordOffsetEnabled = TRUE;
        sprite->pos1.x += 16;
        sprite->pos1.y += 2;
    }
    return spriteId;
}

void DestroyRecordMixingSprite(void)
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].template == &gUnknown_0858E880)
        {
            FreeSpritePalette(&gSprites[i]);
            DestroySprite(&gSprites[i]);
        }
    }
}
