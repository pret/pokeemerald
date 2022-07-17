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


EWRAM_DATA struct MapPosition gPlayerFacingPosition = {0};

static void Task_ComputerScreenOpenEffect(u8);
static void Task_ComputerScreenCloseEffect(u8);
static void CreateComputerScreenEffectTask(TaskFunc, u16, u16, u8);

static void Task_SecretBasePCTurnOn(u8);

static void Task_PopSecretBaseBalloon(u8);
static void DoBalloonSoundEffect(s16);

static void Task_WateringBerryTreeAnim_Start(u8);
static void Task_WateringBerryTreeAnim_Continue(u8);
static void Task_WateringBerryTreeAnim_End(u8);

static void FieldCallback_SecretBaseCave(void);
static void SpriteCB_CaveEntranceInit(struct Sprite *);
static void SpriteCB_CaveEntranceOpen(struct Sprite *);
static void SpriteCB_CaveEntranceEnd(struct Sprite *);
static void StartSecretBaseCaveFieldEffect(void);

static void FieldCallback_SecretBaseTree(void);
static void SpriteCB_TreeEntranceInit(struct Sprite *);
static void SpriteCB_TreeEntranceOpen(struct Sprite *);
static void SpriteCB_TreeEntranceEnd(struct Sprite *);
static void StartSecretBaseTreeFieldEffect(void);

static void FieldCallback_SecretBaseShrub(void);
static void SpriteCB_ShrubEntranceInit(struct Sprite *);
static void SpriteCB_ShrubEntranceOpen(struct Sprite *);
static void SpriteCB_ShrubEntranceEnd(struct Sprite *);
static void StartSecretBaseShrubFieldEffect(void);

static void SpriteCB_SandPillar_BreakTop(struct Sprite *);
static void SpriteCB_SandPillar_BreakBase(struct Sprite *);
static void SpriteCB_SandPillar_End(struct Sprite *);

static const u8 sSecretPowerCave_Gfx[] = INCBIN_U8("graphics/field_effects/pics/secret_power_cave.4bpp");
static const u8 sFiller[32] = {0};
static const u16 sSecretPowerCave_Pal[] = INCBIN_U16("graphics/field_effects/palettes/secret_power_cave.gbapal");
static const u8 sSecretPowerShrub_Gfx[] = INCBIN_U8("graphics/field_effects/pics/secret_power_shrub.4bpp");
static const u8 sSecretPowerTree_Gfx[] = INCBIN_U8("graphics/field_effects/pics/secret_power_tree.4bpp");
static const u16 sSecretPowerPlant_Pal[] = INCBIN_U16("graphics/field_effects/palettes/secret_power_plant.gbapal");

// TODO: These should also be combined into a single image, not matching for some reason
static const u8 sSandPillar0_Gfx[] = INCBIN_U8("graphics/field_effects/pics/sand_pillar/0.4bpp");
static const u8 sSandPillar1_Gfx[] = INCBIN_U8("graphics/field_effects/pics/sand_pillar/1.4bpp");
static const u8 sSandPillar2_Gfx[] = INCBIN_U8("graphics/field_effects/pics/sand_pillar/2.4bpp");

static const struct OamData sOam_SecretPower =
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

static const union AnimCmd sAnim_SecretPowerCave[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineDropLeft[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineRiseLeft[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineDropRight[] =
{
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_VineRiseRight[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SecretPowerShrub[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_SecretPowerCave[] =
{
    sAnim_SecretPowerCave,
};

static const union AnimCmd *const sAnimTable_SecretPowerTree[] =
{
    sAnim_VineDropLeft,
    sAnim_VineRiseLeft,
    sAnim_VineDropRight,
    sAnim_VineRiseRight,
};

static const union AnimCmd *const sAnimTable_SecretPowerShrub[] =
{
    sAnim_SecretPowerShrub,
};

static const struct SpriteFrameImage sPicTable_SecretPowerCave[] =
{
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 0),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 1),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 2),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 3),
    overworld_frame(sSecretPowerCave_Gfx, 2, 2, 4),
};

static const struct SpriteFrameImage sPicTable_SecretPowerTree[] =
{
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 0),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 1),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 2),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 3),
    overworld_frame(sSecretPowerTree_Gfx, 2, 2, 4),
    // 6th frame exists but isnt accessed, the tree vine metatile is used instead
};

static const struct SpriteFrameImage sPicTable_SecretPowerShrub[] =
{
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 0),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 1),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 2),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 3),
    overworld_frame(sSecretPowerShrub_Gfx, 2, 2, 4),
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerCave =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_TREE,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_SecretPowerCave,
    .images = sPicTable_SecretPowerCave,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CaveEntranceInit,
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerTree =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_PLANT,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_SecretPowerTree,
    .images = sPicTable_SecretPowerTree,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TreeEntranceInit,
};

static const struct SpriteTemplate sSpriteTemplate_SecretPowerShrub =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SECRET_POWER_PLANT,
    .oam = &sOam_SecretPower,
    .anims = sAnimTable_SecretPowerShrub,
    .images = sPicTable_SecretPowerShrub,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ShrubEntranceInit,
};

const struct SpritePalette gSpritePalette_SecretPower_Cave = {sSecretPowerCave_Pal, FLDEFF_PAL_TAG_SECRET_POWER_TREE};
const struct SpritePalette gSpritePalette_SecretPower_Plant = {sSecretPowerPlant_Pal, FLDEFF_PAL_TAG_SECRET_POWER_PLANT};

static const struct OamData sOam_SandPillar =
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

static const union AnimCmd sAnim_SandPillar[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_SandPillar[] =
{
    sAnim_SandPillar,
};

static const struct SpriteFrameImage sPicTable_SandPillar[] =
{
    {sSandPillar0_Gfx, sizeof(sSandPillar0_Gfx)},
    {sSandPillar1_Gfx, sizeof(sSandPillar1_Gfx)},
    {sSandPillar2_Gfx, sizeof(sSandPillar2_Gfx)},
};

static const struct SpriteTemplate sSpriteTemplate_SandPillar =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SAND_PILLAR,
    .oam = &sOam_SandPillar,
    .anims = sAnimTable_SandPillar,
    .images = sPicTable_SandPillar,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SandPillar_BreakTop,
};

const struct SpritePalette gSpritePalette_SandPillar = {gTilesetPalettes_SecretBase[5], FLDEFF_PAL_TAG_SAND_PILLAR};

static const u8 sRecordMixLights_Gfx[] = INCBIN_U8("graphics/field_effects/pics/record_mix_lights.4bpp");
static const u16 sRecordMixLights_Pal[] = INCBIN_U16("graphics/field_effects/palettes/record_mix_lights.gbapal");

static const struct SpriteFrameImage sPicTable_RecordMixLights[] =
{
    overworld_frame(sRecordMixLights_Gfx, 4, 1, 0),
    overworld_frame(sRecordMixLights_Gfx, 4, 1, 1),
    overworld_frame(sRecordMixLights_Gfx, 4, 1, 2),
};

static const struct SpritePalette sSpritePalette_RecordMixLights = {sRecordMixLights_Pal, 0x1000};

static const union AnimCmd sAnim_RecordMixLights[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(2, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_RecordMixLights[] =
{
    sAnim_RecordMixLights,
};

static const struct SpriteTemplate sSpriteTemplate_RecordMixLights =
{
    .tileTag = TAG_NONE,
    .paletteTag = 0x1000,
    .oam = &gObjectEventBaseOam_32x8,
    .anims = sAnimTable_RecordMixLights,
    .images = sPicTable_RecordMixLights,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// For accessing pokemon storage PC or the Hall of Fame PC
void ComputerScreenOpenEffect(u16 increment, u16 unused, u8 priority)
{
    CreateComputerScreenEffectTask(Task_ComputerScreenOpenEffect, increment, unused, priority);
}

void ComputerScreenCloseEffect(u16 increment, u16 unused, u8 priority)
{
    CreateComputerScreenEffectTask(Task_ComputerScreenCloseEffect, increment, unused, priority);
}

bool8 IsComputerScreenOpenEffectActive(void)
{
    return FuncIsActiveTask(Task_ComputerScreenOpenEffect);
}

bool8 IsComputerScreenCloseEffectActive(void)
{
    return FuncIsActiveTask(Task_ComputerScreenCloseEffect);
}

#define tState         data[0]
#define tHorzIncrement data[1]
#define tVertIncrement data[2]
#define tWinLeft       data[3]
#define tWinRight      data[4]
#define tWinTop        data[5]
#define tWinBottom     data[6]
#define tBlendCnt      data[7]
#define tBlendY        data[8]

static void CreateComputerScreenEffectTask(void (*taskfunc) (u8), u16 increment, u16 unused, u8 priority)
{
    u8 taskId = CreateTask(taskfunc, priority);

    gTasks[taskId].tState = 0;
    gTasks[taskId].tHorzIncrement = increment == 0 ? 16 : increment;
    gTasks[taskId].tVertIncrement = increment == 0 ? 20 : increment;
    gTasks[taskId].func(taskId);
}

static void Task_ComputerScreenOpenEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tWinLeft = DISPLAY_WIDTH / 2;
        task->tWinRight = DISPLAY_WIDTH / 2;
        task->tWinTop = DISPLAY_HEIGHT / 2;
        task->tWinBottom = DISPLAY_HEIGHT / 2 + 1;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);

        break;
    case 1:
        task->tBlendCnt = GetGpuReg(REG_OFFSET_BLDCNT);
        task->tBlendY = GetGpuReg(REG_OFFSET_BLDY);

        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 16);

        break;
    case 2:
        task->tWinLeft -= task->tHorzIncrement;
        task->tWinRight += task->tHorzIncrement;

        if (task->tWinLeft < 1 || task->tWinRight > DISPLAY_WIDTH - 1)
        {
            task->tWinLeft = 0;
            task->tWinRight = DISPLAY_WIDTH;
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, task->tBlendCnt);
            BlendPalettes(PALETTES_ALL, 0, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));

        if (task->tWinLeft != 0)
            return;
        break;
    case 3:
        task->tWinTop -= task->tVertIncrement;
        task->tWinBottom += task->tVertIncrement;

        if (task->tWinTop < 1 || task->tWinBottom > DISPLAY_HEIGHT - 1)
        {
            task->tWinTop = 0;
            task->tWinBottom = DISPLAY_HEIGHT;
            ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));

        if (task->tWinTop != 0)
            return;
        break;
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, task->tBlendCnt);
        DestroyTask(taskId);
        return;
    }
    task->tState++;
}

static void Task_ComputerScreenCloseEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        gPlttBufferFaded[0] = 0;
        break;
    case 1:
        task->tWinLeft = 0;
        task->tWinRight = DISPLAY_WIDTH;
        task->tWinTop = 0;
        task->tWinBottom = DISPLAY_HEIGHT;

        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        break;
    case 2:
        task->tWinTop += task->tVertIncrement;
        task->tWinBottom -= task->tVertIncrement;

        if (task->tWinTop >= DISPLAY_HEIGHT / 2 || task->tWinBottom <= DISPLAY_HEIGHT / 2 + 1)
        {
            task->tWinTop = DISPLAY_HEIGHT / 2;
            task->tWinBottom = DISPLAY_HEIGHT / 2 + 1;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_ALL | BLDCNT_EFFECT_LIGHTEN);
            SetGpuReg(REG_OFFSET_BLDY, 16);
        }
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(task->tWinTop, task->tWinBottom));

        if (task->tWinTop != DISPLAY_HEIGHT / 2)
            return;
        break;
    case 3:
        task->tWinLeft += task->tHorzIncrement;
        task->tWinRight -= task->tHorzIncrement;

        if (task->tWinLeft >= DISPLAY_WIDTH / 2 || task->tWinRight <= DISPLAY_WIDTH / 2)
        {
            task->tWinLeft = DISPLAY_WIDTH / 2;
            task->tWinRight = DISPLAY_WIDTH / 2;
            BlendPalettes(PALETTES_ALL, 16, 0);
            gPlttBufferFaded[0] = 0;
        }
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(task->tWinLeft, task->tWinRight));

        if (task->tWinLeft != DISPLAY_WIDTH / 2)
            return;
        break;
    default:
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
        return;
    }
    task->tState++;
}

#undef tState
#undef tHorzIncrement
#undef tVertIncrement
#undef tWinLeft
#undef tWinRight
#undef tWinTop
#undef tWinBottom
#undef tBlendCnt
#undef tBlendY

static void SetCurrentSecretBase(void)
{
    SetCurSecretBaseIdFromPosition(&gPlayerFacingPosition, gMapHeader.events);
    TrySetCurSecretBaseIndex();
}

static void AdjustSecretPowerSpritePixelOffsets(void)
{
    if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
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
    u8 taskId = CreateFieldMoveTask();

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
    CreateSprite(&sSpriteTemplate_SecretPowerCave,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);
    return FALSE;
}

static void SpriteCB_CaveEntranceInit(struct Sprite *sprite)
{
    PlaySE(SE_M_ROCK_THROW);

    sprite->data[0] = 0;
    sprite->callback = SpriteCB_CaveEntranceOpen;
}

static void SpriteCB_CaveEntranceOpen(struct Sprite *sprite)
{
    if (sprite->data[0] < 40)
    {
        if (++sprite->data[0] == 20)
            ToggleSecretBaseEntranceMetatile();
    }
    else
    {
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_CaveEntranceEnd;
    }
}

static void SpriteCB_CaveEntranceEnd(struct Sprite *sprite)
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
    u8 taskId = CreateFieldMoveTask();

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

    CreateSprite(&sSpriteTemplate_SecretPowerTree,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    if (gFieldEffectArguments[7] == 1 || gFieldEffectArguments[7] == 3)
        ToggleSecretBaseEntranceMetatile();

    return FALSE;
}

static void SpriteCB_TreeEntranceInit(struct Sprite *sprite)
{
    PlaySE(SE_M_SCRATCH);

    sprite->animNum = gFieldEffectArguments[7];
    sprite->data[0] = 0;
    sprite->callback = SpriteCB_TreeEntranceOpen;
}

static void SpriteCB_TreeEntranceOpen(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] >= 40)
    {
        if (gFieldEffectArguments[7] == 0 || gFieldEffectArguments[7] == 2)
            ToggleSecretBaseEntranceMetatile();

        sprite->data[0] = 0;
        sprite->callback = SpriteCB_TreeEntranceEnd;
    }
}

static void SpriteCB_TreeEntranceEnd(struct Sprite *sprite)
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
    u8 taskId = CreateFieldMoveTask();

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

    CreateSprite(&sSpriteTemplate_SecretPowerShrub,
                 gSprites[gPlayerAvatar.spriteId].oam.x + gFieldEffectArguments[5],
                 gSprites[gPlayerAvatar.spriteId].oam.y + gFieldEffectArguments[6],
                 148);

    return FALSE;
}

static void SpriteCB_ShrubEntranceInit(struct Sprite *sprite)
{
    PlaySE(SE_M_POISON_POWDER);

    sprite->data[0] = 0;
    sprite->callback = SpriteCB_ShrubEntranceOpen;
}

static void SpriteCB_ShrubEntranceOpen(struct Sprite *sprite)
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
        sprite->callback = SpriteCB_ShrubEntranceEnd;
    }
}

static void SpriteCB_ShrubEntranceEnd(struct Sprite *sprite)
{
    FieldEffectStop(sprite, FLDEFF_SECRET_POWER_SHRUB);
    EnableBothScriptContexts();
}

#define tX     data[0]
#define tY     data[1]
#define tState data[2]

bool8 FldEff_SecretBasePCTurnOn(void)
{
    s16 x, y;
    u8 taskId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    taskId = CreateTask(Task_SecretBasePCTurnOn, 0);
    gTasks[taskId].tX = x;
    gTasks[taskId].tY = y;
    gTasks[taskId].tState = 0;

    return FALSE;
}

static void Task_SecretBasePCTurnOn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 4:
    case 12:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 8:
    case 16:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 20:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        FieldEffectActiveListRemove(FLDEFF_PCTURN_ON);
        EnableBothScriptContexts();
        DestroyTask(taskId);
        return;
    }

    tState++;
}

#undef tX
#undef tY
#undef tState

void DoSecretBasePCTurnOffEffect(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    PlaySE(SE_PC_OFF);

    if (!VarGet(VAR_CURRENT_SECRET_BASE))
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_PC | MAPGRID_COLLISION_MASK);
    else
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_RegisterPC | MAPGRID_COLLISION_MASK);

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
        PlaySE(SE_BALLOON_RED);
        break;
    case METATILE_SecretBase_BlueBalloon:
        PlaySE(SE_BALLOON_BLUE);
        break;
    case METATILE_SecretBase_YellowBalloon:
        PlaySE(SE_BALLOON_YELLOW);
        break;
    case METATILE_SecretBase_MudBall:
        PlaySE(SE_MUD_BALL);
        break;
    }
}

bool8 FldEff_Nop47(void)
{
    return FALSE;
}

bool8 FldEff_Nop48(void)
{
    return FALSE;
}

static void DoSecretBaseBreakableDoorEffect(s16 x, s16 y)
{
    PlaySE(SE_BREAKABLE_DOOR);
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
            PlaySE(SE_NOTE_C);
            break;
        case METATILE_SecretBase_NoteMat_D:
            PlaySE(SE_NOTE_D);
            break;
        case METATILE_SecretBase_NoteMat_E:
            PlaySE(SE_NOTE_E);
            break;
        case METATILE_SecretBase_NoteMat_F:
            PlaySE(SE_NOTE_F);
            break;
        case METATILE_SecretBase_NoteMat_G:
            PlaySE(SE_NOTE_G);
            break;
        case METATILE_SecretBase_NoteMat_A:
            PlaySE(SE_NOTE_A);
            break;
        case METATILE_SecretBase_NoteMat_B:
            PlaySE(SE_NOTE_B);
            break;
        case METATILE_SecretBase_NoteMat_C_High:
            PlaySE(SE_NOTE_C_HIGH);
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
        PlaySE(SE_M_HEAL_BELL);

    if (sprite->data[0] >= 32)
        DestroySprite(sprite);
}

void DoSecretBaseGlitterMatSparkle(void)
{
    s16 x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    s16 y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    u8 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 4);

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPARKLE], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].oam.priority = 1;
        UpdateSpritePaletteByTemplate(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPARKLE], &gSprites[spriteId]);
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
        CreateSprite(&sSpriteTemplate_SandPillar,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 32,
                     0);

        break;

    case DIR_NORTH:
        CreateSprite(&sSpriteTemplate_SandPillar,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y,
                     148);

        break;

    case DIR_WEST:
        CreateSprite(&sSpriteTemplate_SandPillar,
                     gSprites[gPlayerAvatar.spriteId].oam.x - 8,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);

        break;

    case DIR_EAST:
        CreateSprite(&sSpriteTemplate_SandPillar,
                     gSprites[gPlayerAvatar.spriteId].oam.x + 24,
                     gSprites[gPlayerAvatar.spriteId].oam.y + 16,
                     148);

        break;
    }

    return FALSE;
}

static void SpriteCB_SandPillar_BreakTop(struct Sprite *sprite)
{
    PlaySE(SE_M_ROCK_THROW);

    if (MapGridGetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1) == METATILE_SecretBase_SandOrnament_TopWall)
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_SecretBase_Wall_TopMid | MAPGRID_COLLISION_MASK);
    else
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1, METATILE_SecretBase_SandOrnament_BrokenTop);

    MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_SecretBase_Ground);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6] - 1);
    CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);

    sprite->data[0] = 0;
    sprite->callback = SpriteCB_SandPillar_BreakBase;
}

static void SpriteCB_SandPillar_BreakBase(struct Sprite *sprite)
{
    if (sprite->data[0] < 18)
    {
        sprite->data[0]++;
    }
    else
    {
        MapGridSetMetatileIdAt(gFieldEffectArguments[5], gFieldEffectArguments[6], METATILE_SecretBase_SandOrnament_BrokenBase | MAPGRID_COLLISION_MASK);
        CurrentMapDrawMetatileAt(gFieldEffectArguments[5], gFieldEffectArguments[6]);
        sprite->data[0] = 0;
        sprite->callback = SpriteCB_SandPillar_End;
    }
}

static void SpriteCB_SandPillar_End(struct Sprite *sprite)
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

// As opposed to a small one (single metatile) like the balloons
bool8 IsLargeBreakableDecoration(u16 metatileId, bool8 checkBase)
{
    if (!CurMapIsSecretBase())
        return FALSE;

    if (!checkBase)
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
    PlaySE(SE_FIELD_POISON);
    CreateTask(Task_FieldPoisonEffect, 80);
}

bool32 FldEffPoison_IsActive(void)
{
    return FuncIsActiveTask(Task_FieldPoisonEffect);
}

static void Task_WateringBerryTreeAnim(u8 taskId)
{
    gTasks[taskId].func = Task_WateringBerryTreeAnim_Start;
}

static void Task_WateringBerryTreeAnim_Start(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!ObjectEventIsMovementOverridden(playerObjEvent)
        || ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        // Start watering
        SetPlayerAvatarWatering(GetPlayerFacingDirection());
        ObjectEventSetHeldMovement(playerObjEvent, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
        gTasks[taskId].func = Task_WateringBerryTreeAnim_Continue;
    }
}

static void Task_WateringBerryTreeAnim_Continue(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        s16 value = gTasks[taskId].data[1]++;

        // Continue holding watering action 10 times, then end
        if (value < 10)
            ObjectEventSetHeldMovement(playerObjEvent, GetWalkInPlaceNormalMovementAction(GetPlayerFacingDirection()));
        else
            gTasks[taskId].func = Task_WateringBerryTreeAnim_End;
    }
}

static void Task_WateringBerryTreeAnim_End(u8 taskId)
{
    SetPlayerAvatarTransitionFlags(GetPlayerAvatarFlags());
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

void DoWateringBerryTreeAnim(void)
{
    CreateTask(Task_WateringBerryTreeAnim, 80);
}

// The lights that blink on the counter when mixing records in the cable club
u8 CreateRecordMixingLights(void)
{
    u8 spriteId;

    LoadSpritePalette(&sSpritePalette_RecordMixLights);

    spriteId = CreateSprite(&sSpriteTemplate_RecordMixLights, 0, 0, 82);

    if (spriteId == MAX_SPRITES)
    {
        return MAX_SPRITES;
    }
    else
    {
        struct Sprite *sprite = &gSprites[spriteId];
        GetMapCoordsFromSpritePos(16, 13, &sprite->x, &sprite->y);
        sprite->coordOffsetEnabled = TRUE;
        sprite->x += 16;
        sprite->y += 2;
    }
    return spriteId;
}

void DestroyRecordMixingLights(void)
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].template == &sSpriteTemplate_RecordMixLights)
        {
            FreeSpritePalette(&gSprites[i]);
            DestroySprite(&gSprites[i]);
        }
    }
}
