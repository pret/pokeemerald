#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "gpu_regs.h"
#include "trig.h"
#include "main.h"
#include "intro.h"
#include "m4a.h"
#include "expansion_intro.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#if EXPANSION_INTRO == TRUE

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

enum
{
    EXPANSION_INTRO_BG2,
    EXPANSION_INTRO_BG3
};

enum
{
    ANIM_PORY_IDLE,
    ANIM_PORY_HIT,
    ANIM_PORY_GO_UP
};

enum
{
    ANIM_DIZZY_WALKING,
    ANIM_DIZZY_DIZZY
};

static const u32 sBgTiles_PoweredBy[] = INCBIN_U32("graphics/expansion_intro/powered_by.4bpp.lz");
static const u32 sBgTiles_RhhCredits[] = INCBIN_U32("graphics/expansion_intro/rhh_credits.8bpp.lz");
static const u32 sBgMap_PoweredBy[] = INCBIN_U32("graphics/expansion_intro/powered_by.bin.lz");
static const u32 sBgMap_RhhCredits[] = INCBIN_U32("graphics/expansion_intro/rhh_credits.bin.lz");
static const u32 sBgPal_Credits[] = INCBIN_U32("graphics/expansion_intro/credits.gbapal.lz");
static const u32 sSpriteTiles_DizzyEgg[] = INCBIN_U32("graphics/expansion_intro/sprites/dizzy_egg.4bpp.lz");
static const u32 sSpriteTiles_Porygon[] = INCBIN_U32("graphics/expansion_intro/sprites/porygon.4bpp.lz");
static const u16 sSpritePal_DizzyEgg[] = INCBIN_U16("graphics/expansion_intro/sprites/dizzy_egg.gbapal");
static const u16 sSpritePal_Porygon[] = INCBIN_U16("graphics/expansion_intro/sprites/porygon.gbapal");
static const u16 sSpritePal_PorygonShiny[] = INCBIN_U16("graphics/expansion_intro/sprites/shiny.gbapal");

static void SpriteCallback_DizzyWalking(struct Sprite* sprite);
static void SpriteCallback_PorygonFlying(struct Sprite* sprite);
static void Task_ExpansionIntro_HandleBlend(u8 taskId);
static void VBlankCB_ExpansionIntro(void);
static void ExpansionIntro_InitBgs();
static void ExpansionIntro_StartBlend();
static void ExpansionIntro_LoadGraphics();
static void ExpansionIntro_CreateSprites();

static const union AnimCmd sAnimCmd_DizzyWalking[] =
{
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

static const union AnimCmd sAnimCmd_DizzyisDizzy[] =
{
    ANIMCMD_FRAME(80, DIZZY_STARS_SPEED),
    ANIMCMD_FRAME(96, DIZZY_STARS_SPEED),
    ANIMCMD_FRAME(112, DIZZY_STARS_SPEED),
    ANIMCMD_FRAME(96, DIZZY_STARS_SPEED),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimCmdTable_DizzyEgg[] =
{
    [ANIM_DIZZY_WALKING] = sAnimCmd_DizzyWalking,
    [ANIM_DIZZY_DIZZY] = sAnimCmd_DizzyisDizzy,
};

static const union AnimCmd sAnimCmd_PorygonIdle[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnimCmd_PorygonHitted[] =
{
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnimCmd_PorygonGoUp[] =
{
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_FRAME(128, 10),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimCmdTable_Porygon[] =
{
    [ANIM_PORY_IDLE] = sAnimCmd_PorygonIdle,
    [ANIM_PORY_HIT] = sAnimCmd_PorygonHitted,
    [ANIM_PORY_GO_UP] = sAnimCmd_PorygonGoUp,
};

static const union AffineAnimCmd sAffineAnimCmd_PorygonScale[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnimCmdTable_Porygon[] =
{
    sAffineAnimCmd_PorygonScale,
};

static const struct CompressedSpriteSheet sSpriteSheet_DizzyEgg =
{
    .data = sSpriteTiles_DizzyEgg,
    .size = 0x1000,
    .tag = TAG_DIZZY,
};

static const struct CompressedSpriteSheet sSpriteSheet_Porygon =
{
    .data = sSpriteTiles_Porygon,
    .size = 0x2800,
    .tag = PAL_TAG_PORYGON,
};

static const struct SpritePalette sSpritePalette_DizzyEgg =
{
    .data = sSpritePal_DizzyEgg,
    .tag = PAL_TAG_DIZZY,
};

static const struct SpritePalette sSpritePalette_Porygon =
{
    .data = sSpritePal_Porygon,
    .tag = PAL_TAG_PORYGON,
};

static const struct OamData sOamData_DizzyEgg =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 0,
};

static const struct OamData sOamData_Porygon =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 0,
};

static const struct SpriteTemplate sSpriteTemplate_DizzyEgg =
{
    .tileTag = TAG_DIZZY,
    .paletteTag = PAL_TAG_DIZZY,
    .oam = &sOamData_DizzyEgg,
    .anims = sAnimCmdTable_DizzyEgg,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_DizzyWalking,
};

static const struct SpriteTemplate sSpriteTemplate_Porygon =
{
    .tileTag = TAG_PORYGON,
    .paletteTag = PAL_TAG_PORYGON,
    .oam = &sOamData_Porygon,
    .anims = sAnimCmdTable_Porygon,
    .images = NULL,
    .affineAnims = sAffineAnimCmdTable_Porygon,
    .callback = SpriteCallback_PorygonFlying,
};

static const struct BgTemplate sBgTemplates_RhhCopyrightScreen[] =
{
    [EXPANSION_INTRO_BG2] = {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 20,
        .screenSize = 2,
        .paletteMode = 1
    },
    [EXPANSION_INTRO_BG3] = {
        .bg = 3,
        .mapBaseIndex = 22,
        .screenSize = 2
    },
};

void CB2_ExpansionIntro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

#define tState gTasks[taskId].data[0]
#define tFrameCounter gTasks[taskId].data[1]
void Task_HandleExpansionIntro(u8 taskId)
{
    switch (tState)
    {
    case 0:
        SetVBlankCallback(VBlankCB_ExpansionIntro);
        ExpansionIntro_InitBgs();
        ExpansionIntro_LoadGraphics();
        CpuFastFill16(RGB_BLACK, gPlttBufferFaded, 32);
        ShowBg(3);
        BeginNormalPaletteFade(1, 0, 16, 0, RGB_BLACK);
        ExpansionIntro_StartBlend();
        ExpansionIntro_CreateSprites();
        tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
            tState++;
        break;
    case 2:
        if (tFrameCounter == 208)
        {
            tState++;
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        }
        else if (gMain.newKeys != 0)
        {
            CpuFill16(0, gPlttBufferFaded, sizeof(gPlttBufferFaded));
            if (IsCryPlaying())
                StopCry();
            m4aSongNumStop(SE_BIKE_HOP);
            m4aSongNumStop(SE_M_DOUBLE_SLAP);
            tState++;
        }
        else
        {
            tFrameCounter++;
        }
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            ResetSpriteData();
            FreeAllSpritePalettes();
            DestroyTask(taskId);
            CreateTask(Task_Scene1_Load, 0);
            SetMainCallback2(MainCB2_Intro);
        }
        break;
    }
}
#undef tState

static void VBlankCB_ExpansionIntro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ExpansionIntro_InitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_RhhCopyrightScreen, ARRAY_COUNT(sBgTemplates_RhhCopyrightScreen));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0x1F);
    HideBg(0);
    HideBg(1);
    HideBg(2);
    HideBg(3);
}

static void ExpansionIntro_LoadGraphics(void)
{
    LZ77UnCompVram(sBgTiles_PoweredBy, (void*) BG_CHAR_ADDR(sBgTemplates_RhhCopyrightScreen[EXPANSION_INTRO_BG3].charBaseIndex));
    LZ77UnCompVram(sBgMap_PoweredBy, (u16*) BG_SCREEN_ADDR(sBgTemplates_RhhCopyrightScreen[EXPANSION_INTRO_BG3].mapBaseIndex));
    LZ77UnCompVram(sBgTiles_RhhCredits, (void*) BG_CHAR_ADDR(sBgTemplates_RhhCopyrightScreen[EXPANSION_INTRO_BG2].charBaseIndex));
    LZ77UnCompVram(sBgMap_RhhCredits, (u16*) BG_SCREEN_ADDR(sBgTemplates_RhhCopyrightScreen[EXPANSION_INTRO_BG2].mapBaseIndex));
    LoadCompressedPalette(sBgPal_Credits, 0x00, 0x60);

    LoadCompressedSpriteSheet(&sSpriteSheet_DizzyEgg);
    LoadCompressedSpriteSheet(&sSpriteSheet_Porygon);
    LoadSpritePalette(&sSpritePalette_DizzyEgg);
    LoadSpritePalette(&sSpritePalette_Porygon);
}

static void ExpansionIntro_CreateSprites(void)
{
    u32 dizzyId, poryId;

    dizzyId = CreateSprite(&sSpriteTemplate_DizzyEgg, 0, DIZZY_POS_Y, 0);
    gSprites[dizzyId].x2 = DIZZY_POS_X;

    poryId = CreateSprite(&sSpriteTemplate_Porygon, 0, PORY_POS_Y, 0);
    gSprites[poryId].x2 = PORY_POS_X;
}

static void ExpansionIntro_StartBlend(void)
{
    ShowBg(2);
    CreateTask(Task_ExpansionIntro_HandleBlend, 0);
}

static void Task_ExpansionIntro_HandleBlend(u8 taskId)
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
static void SpriteCallback_DizzyWalking(struct Sprite* sprite)
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

#endif //EXPANSION_INTRO
