#include "global.h"
#include "bg.h"
#include "clear_save_data_menu.h"
#include "decompress.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "gpu_regs.h"
#include "trig.h"
#include "rhh_copyright.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#if RHH_COPYRIGHT_INTRO == TRUE

static const u32 sBgTiles_PoweredBy[] = INCBIN_U32("graphics/rhh_copyright/powered_by.4bpp.lz");
static const u32 sBgTiles_RhhCredits[] = INCBIN_U32("graphics/rhh_copyright/rhh_credits.8bpp.lz");
static const u32 sBgMap_PoweredBy[] = INCBIN_U32("graphics/rhh_copyright/powered_by.bin.lz");
static const u32 sBgMap_RhhCredits[] = INCBIN_U32("graphics/rhh_copyright/rhh_credits.bin.lz");
static const u32 sBgPal_Credits[] = INCBIN_U32("graphics/rhh_copyright/credits.gbapal.lz");
static const u32 sSpriteTiles_DizzyEgg[] = INCBIN_U32("graphics/rhh_copyright/sprites/dizzy_egg.4bpp.lz");
static const u32 sSpriteTiles_Porygon[] = INCBIN_U32("graphics/rhh_copyright/sprites/porygon.4bpp.lz");
static const u16 sSpritePal_DizzyEgg[] = INCBIN_U16("graphics/rhh_copyright/sprites/dizzy_egg.gbapal");
static const u16 sSpritePal_Porygon[] = INCBIN_U16("graphics/rhh_copyright/sprites/porygon.gbapal");
static const u16 sSpritePal_PorygonShiny[] = INCBIN_U16("graphics/rhh_copyright/sprites/shiny.gbapal");


#define TAG_DIZZY   20000
#define TAG_PORYGON 20001

#define PAL_TAG_DIZZY   20000
#define PAL_TAG_PORYGON 20001

#define DIZZY_POS_X 300
#define DIZZY_POS_Y 138
#define DIZZY_COLLISION_POS_X   172
#define PORY_POS_X  -32
#define PORY_POS_Y  115
#define PORYGON_COLLISION_POS_X 140
#define PORYGON_WAIT_TIME   99

#define DIZZY_ANIM_SPEED    4
#define DIZZY_STARS_SPEED   12

static void SpriteCallbacK_DizzyWalking(struct Sprite* sprite);
static void SpriteCallback_PorygonFlying(struct Sprite* sprite);

static const union AnimCmd sAnimCmd_DizzyWalking[] = {
    ANIMCMD_FRAME(32, DIZZY_ANIM_SPEED),
    ANIMCMD_FRAME(16, DIZZY_ANIM_SPEED),
    ANIMCMD_FRAME(0, DIZZY_ANIM_SPEED),
    ANIMCMD_FRAME(16, DIZZY_ANIM_SPEED),
    ANIMCMD_FRAME(32, DIZZY_ANIM_SPEED),
    ANIMCMD_FRAME(48, DIZZY_ANIM_SPEED),
    ANIMCMD_FRAME(64, DIZZY_ANIM_SPEED),
    ANIMCMD_FRAME(48, DIZZY_ANIM_SPEED),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_DizzyisDizzy[] = {
    ANIMCMD_FRAME(80, DIZZY_STARS_SPEED),
    ANIMCMD_FRAME(96, DIZZY_STARS_SPEED),
    ANIMCMD_FRAME(112, DIZZY_STARS_SPEED),
    ANIMCMD_FRAME(96, DIZZY_STARS_SPEED),
    ANIMCMD_JUMP(0),
};

enum {ANIM_DIZZY_WALKING, ANIM_DIZZY_DIZZY};

static const union AnimCmd *const sAnimCmdTable_DizzyEgg[] = {
    [ANIM_DIZZY_WALKING] = sAnimCmd_DizzyWalking,
    [ANIM_DIZZY_DIZZY] = sAnimCmd_DizzyisDizzy,
};

static const union AnimCmd sAnimCmd_PorygonIdle[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnimCmd_PorygonHitted[] = {
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnimCmd_PorygonGoUp[] = {
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_FRAME(128, 10),
    ANIMCMD_END,
};

enum {ANIM_PORY_IDLE, ANIM_PORY_HIT, ANIM_PORY_GO_UP};

static const union AnimCmd *const sAnimCmdTable_Porygon[] = {
    [ANIM_PORY_IDLE] = sAnimCmd_PorygonIdle,
    [ANIM_PORY_HIT] = sAnimCmd_PorygonHitted,
    [ANIM_PORY_GO_UP] = sAnimCmd_PorygonGoUp,
};

static const union AffineAnimCmd sAffineAnimCmd_PorygonScale[] = {
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnimCmdTable_Porygon[] = {
    sAffineAnimCmd_PorygonScale,
};

static const struct CompressedSpriteSheet sSpriteSheet_DizzyEgg = {
    .data = sSpriteTiles_DizzyEgg,
    .size = 0x1000,
    .tag = TAG_DIZZY,
};

static const struct CompressedSpriteSheet sSpriteSheet_Porygon = {
    .data = sSpriteTiles_Porygon,
    .size = 0x2800,
    .tag = PAL_TAG_PORYGON,
};

static const struct SpritePalette sSpritePalette_DizzyEgg = {
    .data = sSpritePal_DizzyEgg,
    .tag = PAL_TAG_DIZZY,
};

static const struct SpritePalette sSpritePalette_Porygon = {
    .data = sSpritePal_Porygon,
    .tag = PAL_TAG_PORYGON,
};

static const struct OamData sOamData_DizzyEgg = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0,
};

static const struct OamData sOamData_Porygon = {
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 0,
};

static const struct SpriteTemplate sSpriteTemplate_DizzyEgg = {
    .tileTag = TAG_DIZZY,
    .paletteTag = PAL_TAG_DIZZY,
    .oam = &sOamData_DizzyEgg,
    .anims = sAnimCmdTable_DizzyEgg,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbacK_DizzyWalking,
};

static const struct SpriteTemplate sSpriteTemplate_Porygon = {
    .tileTag = TAG_PORYGON,
    .paletteTag = PAL_TAG_PORYGON,
    .oam = &sOamData_Porygon,
    .anims = sAnimCmdTable_Porygon,
    .images = NULL,
    .affineAnims = sAffineAnimCmdTable_Porygon,
    .callback = SpriteCallback_PorygonFlying,
};

enum {BG_0, BG_1, BG_2, BG_3};

static const struct BgTemplate sBgTemplates_RhhCopyrightScreen[] = {
    [BG_0] = {
        .bg = BG_0,
        .charBaseIndex = 3,
        .mapBaseIndex = 24,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    [BG_1] = {
        .bg = BG_1,
        .charBaseIndex = 3,
        .mapBaseIndex = 24,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    [BG_2] = {
        .bg = BG_2,
        .charBaseIndex = 1,
        .mapBaseIndex = 20,
        .screenSize = 2,
        .paletteMode = 1,
        .priority = 0,
        .baseTile = 0,
    },
    [BG_3] = {
        .bg = BG_3,
        .charBaseIndex = 0,
        .mapBaseIndex = 22,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static EWRAM_DATA u8 sDizzyId = 0;
static EWRAM_DATA u8 sPoryId = 0;

static void Task_ShowRhhCredits(u8 taskId);

void RhhIntro_InitCopyrightBgs()
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_RhhCopyrightScreen, ARRAY_COUNT(sBgTemplates_RhhCopyrightScreen));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0x1F);
    HideBg(0);
    HideBg(1);
    HideBg(2);
    ShowBg(3);
}

void RhhIntro_LoadCopyrightBgGraphics()
{
    LZ77UnCompVram(sBgTiles_PoweredBy, (void*) BG_CHAR_ADDR(sBgTemplates_RhhCopyrightScreen[BG_3].charBaseIndex));
    LZ77UnCompVram(sBgMap_PoweredBy, (u16*) BG_SCREEN_ADDR(sBgTemplates_RhhCopyrightScreen[BG_3].mapBaseIndex));
    LZ77UnCompVram(sBgTiles_RhhCredits, (void*) BG_CHAR_ADDR(sBgTemplates_RhhCopyrightScreen[BG_2].charBaseIndex));
    LZ77UnCompVram(sBgMap_RhhCredits, (u16*) BG_SCREEN_ADDR(sBgTemplates_RhhCopyrightScreen[BG_2].mapBaseIndex));
    LoadCompressedPalette(sBgPal_Credits, 0x00, 0x60);
}

void RhhIntro_LoadCopyrightSpriteGraphics()
{
    LoadCompressedSpriteSheet(&sSpriteSheet_DizzyEgg);
    LoadCompressedSpriteSheet(&sSpriteSheet_Porygon);
    LoadSpritePalette(&sSpritePalette_DizzyEgg);
    LoadSpritePalette(&sSpritePalette_Porygon);
}

void RhhIntro_CreateCopyRightSprites()
{
    sDizzyId = CreateSprite(&sSpriteTemplate_DizzyEgg, 0, DIZZY_POS_Y, 0);
    gSprites[sDizzyId].x2 = DIZZY_POS_X;

    sPoryId = CreateSprite(&sSpriteTemplate_Porygon, 0, PORY_POS_Y, 0);
    gSprites[sPoryId].x2 = PORY_POS_X;
}

void RhhIntro_ShowRhhCredits()
{
    ShowBg(2);
    CreateTask(Task_ShowRhhCredits, 0);
}

static void Task_ShowRhhCredits(u8 taskId)
{
    if (GetGpuReg(REG_OFFSET_BLDY) != 0)
    {
        SetGpuReg(REG_OFFSET_BLDY, GetGpuReg(REG_OFFSET_BLDY) - 1);
    }
    else
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        DestroyTask(taskId);
    }
}

#define sTimer data[0]
static void SpriteCallbacK_DizzyWalking(struct Sprite* sprite)
{
    sprite->x2--;

    if (sprite->x2 <= DIZZY_COLLISION_POS_X)
    {
        StartSpriteAnim(sprite, ANIM_DIZZY_DIZZY);
        sprite->callback = SpriteCallbackDummy;
    }

    if (sprite->sTimer % 16 == 0 && sprite->sTimer / 16 > 2)
        PlaySE(SE_BIKE_HOP);

    sprite->sTimer++;
}


static void SpriteCallback_PorygonHit(struct Sprite* sprite)
{
    sprite->x2-=2;
    sprite ->y2 = Sin2(180 + sprite->sTimer * 4) / 128;

    if (sprite->sTimer >= 48)
    {
        StartSpriteAnim(sprite, ANIM_PORY_GO_UP);
        sprite->callback = SpriteCallbackDummy;
    }

    if (sprite->sTimer % 8 == 0)
    {
        if (sprite->sTimer % 16 == 0)
            LoadPalette(sSpritePal_PorygonShiny, 0x10 * (16 + sprite->oam.paletteNum), 0x20);
        else
            LoadPalette(sSpritePal_Porygon, 0x10 * (16 + sprite->oam.paletteNum), 0x20);
    }

    sprite->sTimer++;
}

static void SpriteCallback_PorygonFlying(struct Sprite* sprite)
{
    if (sprite->sTimer >= PORYGON_WAIT_TIME)
    {
        sprite->x2 += 6;

        if (sprite->sTimer % 32 >= 16)
            sprite->y2--;
        else
            sprite->y2++;

        if (sprite->x2 >= PORYGON_COLLISION_POS_X)
        {
            StartSpriteAnim(sprite, ANIM_PORY_HIT);
            sprite->callback = SpriteCallback_PorygonHit;
            sprite->sTimer = 0;
            PlaySE(SE_M_DOUBLE_SLAP);
            PlayCryInternal(SPECIES_PORYGON, 0, 120, 10, 0);
        }
    }
    sprite->sTimer++;
}
#undef sTimer

void RhhIntro_DestroyRhhCreditSprites()
{
    DestroySpriteAndFreeResources(&gSprites[sDizzyId]);
    DestroySpriteAndFreeResources(&gSprites[sPoryId]);
}

#endif //RHH_COPYRIGHT_INTRO
