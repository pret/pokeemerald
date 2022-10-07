#include "global.h"
#include "battle.h"
#include "battle_bg.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/map_types.h"
#include "constants/songs.h"
#include "constants/trainers.h"

#define B_WIN_MSG_WIDTH                     26
#define B_WIN_YESNO_TILEMAP_LEFT            26
#define B_WIN_YESNO_WIDTH                   3
#define ARENA_WIN_SKILL_TILEMAP_LEFT        12
#define ARENA_WIN_SKILL_WIDTH               6
#define ARENA_WIN_JUDGMENT_TEXT_WIDTH       26

struct BattleBackground
{
    const void *tileset;
    const void *tilemap;
    const void *entryTileset;
    const void *entryTilemap;
    const void *palette;
};

// .rodata
static const u16 sUnrefArray[] = {0x0300, 0x0000}; //OamData?

static const struct OamData sVsLetter_V_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sVsLetter_S_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 64,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds0[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sVsLetterAffineAnimCmds1[] =
{
    AFFINEANIMCMD_FRAME(0x0080, 0x0080, 0x00, 0x00),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_FRAME(0x0018, 0x0018, 0x00, 0x80),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sVsLetterAffineAnimTable[] =
{
    sVsLetterAffineAnimCmds0,
    sVsLetterAffineAnimCmds1,
};

#define TAG_VS_LETTERS 10000

static const struct SpriteTemplate sVsLetter_V_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_V_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct SpriteTemplate sVsLetter_S_SpriteTemplate =
{
    .tileTag = TAG_VS_LETTERS,
    .paletteTag = TAG_VS_LETTERS,
    .oam = &sVsLetter_S_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = sVsLetterAffineAnimTable,
    .callback = SpriteCB_VsLetterDummy
};

static const struct CompressedSpriteSheet sVsLettersSpriteSheet =
{
    gVsLettersGfx, 0x1000, TAG_VS_LETTERS
};

const struct BgTemplate gBattleBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 28,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
   {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 26,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

// Shared Window Templates
CALC_WT_BASEBLOCK(B_WIN_MSG, 0, 2, 15, B_WIN_MSG_WIDTH, 4, 0, 144)
CALC_WT_BASEBLOCK(B_WIN_ACTION_PROMPT, 0, 1, 35, 14, 4, 0, 448)
CALC_WT_BASEBLOCK(B_WIN_ACTION_MENU, 0, 17, 35, 12, 4, 5, 400)
CALC_WT_BASEBLOCK(B_WIN_MOVE_NAME_1, 0, 2, 55, 8, 2, 5, 768)
CALC_WT_BASEBLOCK(B_WIN_MOVE_NAME_2, 0, 11, 55, 8, 2, 5, WT_AFTER_B_WIN_MOVE_NAME_1)
CALC_WT_BASEBLOCK(B_WIN_MOVE_NAME_3, 0, 2, 57, 8, 2, 5, WT_AFTER_B_WIN_MOVE_NAME_2)
CALC_WT_BASEBLOCK(B_WIN_MOVE_NAME_4, 0, 11, 57, 8, 2, 5, WT_AFTER_B_WIN_MOVE_NAME_3)
CALC_WT_BASEBLOCK(B_WIN_PP, 0, 21, 55, 4, 2, 5, 656)
CALC_WT_BASEBLOCK(B_WIN_DUMMY, 0, 21, 57, 0, 0, 5, WT_AFTER_B_WIN_PP)
CALC_WT_BASEBLOCK(B_WIN_PP_REMAINING, 0, 25, 55, 4, 2, 5, WT_AFTER_B_WIN_PP)
CALC_WT_BASEBLOCK(B_WIN_MOVE_TYPE, 0, 21, 57, 8, 2, 5, WT_AFTER_B_WIN_PP_REMAINING)
CALC_WT_BASEBLOCK(B_WIN_SWITCH_PROMPT, 0, 21, 55, 8, 4, 5, WT_AFTER_B_WIN_MOVE_TYPE)
CALC_WT_BASEBLOCK(B_WIN_YESNO, 0, B_WIN_YESNO_TILEMAP_LEFT, 9, B_WIN_YESNO_WIDTH, 4, 5, 256)
CALC_WT_BASEBLOCK(B_WIN_LEVEL_UP_BOX, 1, 19, 8, 10, 11, 5, 256)
CALC_WT_BASEBLOCK(B_WIN_LEVEL_UP_BANNER, 2, 18, 0, 12, 3, 6, WT_AFTER_B_WIN_LEVEL_UP_BOX)

// Standard-only Window Templates
CALC_WT_BASEBLOCK(B_WIN_VS_PLAYER, 1, 2, 3, 6, 2, 5, 32)
CALC_WT_BASEBLOCK(B_WIN_VS_OPPONENT, 2, 2, 3, 6, 2, 5, 64)
CALC_WT_BASEBLOCK(B_WIN_VS_MULTI_PLAYER_1, 1, 2, 2, 6, 2, 5, 32)
CALC_WT_BASEBLOCK(B_WIN_VS_MULTI_PLAYER_2, 2, 2, 2, 6, 2, 5, 64)
CALC_WT_BASEBLOCK(B_WIN_VS_MULTI_PLAYER_3, 1, 2, 6, 6, 2, 5, 96)
CALC_WT_BASEBLOCK(B_WIN_VS_MULTI_PLAYER_4, 2, 2, 6, 6, 2, 5, 128)
CALC_WT_BASEBLOCK(B_WIN_VS_OUTCOME_DRAW, 0, 12, 2, 6, 2, 0, 160)
CALC_WT_BASEBLOCK(B_WIN_VS_OUTCOME_LEFT, 0, 4, 2, 7, 2, 0, 160)
CALC_WT_BASEBLOCK(B_WIN_VS_OUTCOME_RIGHT, 0, 19, 2, 7, 2, 0, 176)

static const struct WindowTemplate sStandardBattleWindowTemplates[] =
{
    // Shared Window Templates
    [B_WIN_MSG]                 = WINDOW_TEMPLATE(B_WIN_MSG),
    [B_WIN_ACTION_PROMPT]       = WINDOW_TEMPLATE(B_WIN_ACTION_PROMPT),
    [B_WIN_ACTION_MENU]         = WINDOW_TEMPLATE(B_WIN_ACTION_MENU),
    [B_WIN_MOVE_NAME_1]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_1),
    [B_WIN_MOVE_NAME_2]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_2),
    [B_WIN_MOVE_NAME_3]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_3),
    [B_WIN_MOVE_NAME_4]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_4),
    [B_WIN_PP]                  = WINDOW_TEMPLATE(B_WIN_PP),
    [B_WIN_DUMMY]               = WINDOW_TEMPLATE(B_WIN_DUMMY),
    [B_WIN_PP_REMAINING]        = WINDOW_TEMPLATE(B_WIN_PP_REMAINING),
    [B_WIN_MOVE_TYPE]           = WINDOW_TEMPLATE(B_WIN_MOVE_TYPE),
    [B_WIN_SWITCH_PROMPT]       = WINDOW_TEMPLATE(B_WIN_SWITCH_PROMPT),
    [B_WIN_YESNO]               = WINDOW_TEMPLATE(B_WIN_YESNO),
    [B_WIN_LEVEL_UP_BOX]        = WINDOW_TEMPLATE(B_WIN_LEVEL_UP_BOX),
    [B_WIN_LEVEL_UP_BANNER]     = WINDOW_TEMPLATE(B_WIN_LEVEL_UP_BANNER),
    // Standard-only Window Templates
    [B_WIN_VS_PLAYER]           = WINDOW_TEMPLATE(B_WIN_VS_PLAYER),
    [B_WIN_VS_OPPONENT]         = WINDOW_TEMPLATE(B_WIN_VS_OPPONENT),
    [B_WIN_VS_MULTI_PLAYER_1]   = WINDOW_TEMPLATE(B_WIN_VS_MULTI_PLAYER_1),
    [B_WIN_VS_MULTI_PLAYER_2]   = WINDOW_TEMPLATE(B_WIN_VS_MULTI_PLAYER_2),
    [B_WIN_VS_MULTI_PLAYER_3]   = WINDOW_TEMPLATE(B_WIN_VS_MULTI_PLAYER_3),
    [B_WIN_VS_MULTI_PLAYER_4]   = WINDOW_TEMPLATE(B_WIN_VS_MULTI_PLAYER_4),
    [B_WIN_VS_OUTCOME_DRAW]     = WINDOW_TEMPLATE(B_WIN_VS_OUTCOME_DRAW),
    [B_WIN_VS_OUTCOME_LEFT]     = WINDOW_TEMPLATE(B_WIN_VS_OUTCOME_LEFT),
    [B_WIN_VS_OUTCOME_RIGHT]    = WINDOW_TEMPLATE(B_WIN_VS_OUTCOME_RIGHT),
    DUMMY_WIN_TEMPLATE
};

// Arena-only Window Templates
CALC_WT_BASEBLOCK(ARENA_WIN_PLAYER_NAME, 0, 6, 1, 8, 2, 5, 256)
CALC_WT_BASEBLOCK(ARENA_WIN_VS, 0, 14, 1, 2, 2, 5, WT_AFTER_ARENA_WIN_PLAYER_NAME)
CALC_WT_BASEBLOCK(ARENA_WIN_OPPONENT_NAME, 0, 16, 1, 8, 2, 5, WT_AFTER_ARENA_WIN_VS)
CALC_WT_BASEBLOCK(ARENA_WIN_MIND, 0, 12, 4, 6, 2, 5, WT_AFTER_ARENA_WIN_OPPONENT_NAME)
CALC_WT_BASEBLOCK(ARENA_WIN_SKILL, 0, ARENA_WIN_SKILL_TILEMAP_LEFT, 6, ARENA_WIN_SKILL_WIDTH, 2, 5, WT_AFTER_ARENA_WIN_MIND)
CALC_WT_BASEBLOCK(ARENA_WIN_BODY, 0, 12, 8, 6, 2, 5, WT_AFTER_ARENA_WIN_SKILL)
CALC_WT_BASEBLOCK(ARENA_WIN_JUDGMENT_TITLE, 0, 8, 11, 14, 2, 5, WT_AFTER_ARENA_WIN_BODY)
CALC_WT_BASEBLOCK(ARENA_WIN_JUDGMENT_TEXT, 0, 2, 15, ARENA_WIN_JUDGMENT_TEXT_WIDTH, 4, 7, 144)

static const struct WindowTemplate sBattleArenaWindowTemplates[] =
{
    // Shared Window Templates
    [B_WIN_MSG]                 = WINDOW_TEMPLATE(B_WIN_MSG),
    [B_WIN_ACTION_PROMPT]       = WINDOW_TEMPLATE(B_WIN_ACTION_PROMPT),
    [B_WIN_ACTION_MENU]         = WINDOW_TEMPLATE(B_WIN_ACTION_MENU),
    [B_WIN_MOVE_NAME_1]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_1),
    [B_WIN_MOVE_NAME_2]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_2),
    [B_WIN_MOVE_NAME_3]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_3),
    [B_WIN_MOVE_NAME_4]         = WINDOW_TEMPLATE(B_WIN_MOVE_NAME_4),
    [B_WIN_PP]                  = WINDOW_TEMPLATE(B_WIN_PP),
    [B_WIN_DUMMY]               = WINDOW_TEMPLATE(B_WIN_DUMMY),
    [B_WIN_PP_REMAINING]        = WINDOW_TEMPLATE(B_WIN_PP_REMAINING),
    [B_WIN_MOVE_TYPE]           = WINDOW_TEMPLATE(B_WIN_MOVE_TYPE),
    [B_WIN_SWITCH_PROMPT]       = WINDOW_TEMPLATE(B_WIN_SWITCH_PROMPT),
    [B_WIN_YESNO]               = WINDOW_TEMPLATE(B_WIN_YESNO),
    [B_WIN_LEVEL_UP_BOX]        = WINDOW_TEMPLATE(B_WIN_LEVEL_UP_BOX),
    [B_WIN_LEVEL_UP_BANNER]     = WINDOW_TEMPLATE(B_WIN_LEVEL_UP_BANNER),
    // Arena-only Window Templates
    [ARENA_WIN_PLAYER_NAME]     = WINDOW_TEMPLATE(ARENA_WIN_PLAYER_NAME),
    [ARENA_WIN_VS]              = WINDOW_TEMPLATE(ARENA_WIN_VS),
    [ARENA_WIN_OPPONENT_NAME]   = WINDOW_TEMPLATE(ARENA_WIN_OPPONENT_NAME),
    [ARENA_WIN_MIND]            = WINDOW_TEMPLATE(ARENA_WIN_MIND),
    [ARENA_WIN_SKILL]           = WINDOW_TEMPLATE(ARENA_WIN_SKILL),
    [ARENA_WIN_BODY]            = WINDOW_TEMPLATE(ARENA_WIN_BODY),
    [ARENA_WIN_JUDGMENT_TITLE] = WINDOW_TEMPLATE(ARENA_WIN_JUDGMENT_TITLE),
    [ARENA_WIN_JUDGMENT_TEXT]  = WINDOW_TEMPLATE(ARENA_WIN_JUDGMENT_TEXT),
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate * const gBattleWindowTemplates[] =
{
    [B_WIN_TYPE_NORMAL] = sStandardBattleWindowTemplates,
    [B_WIN_TYPE_ARENA]  = sBattleArenaWindowTemplates,
};

static const struct BattleBackground sBattleTerrainTable[] =
{
    [BATTLE_TERRAIN_GRASS] =
    {
        .tileset = gBattleTerrainTiles_TallGrass,
        .tilemap = gBattleTerrainTilemap_TallGrass,
        .entryTileset = gBattleTerrainAnimTiles_TallGrass,
        .entryTilemap = gBattleTerrainAnimTilemap_TallGrass,
        .palette = gBattleTerrainPalette_TallGrass,
    },

    [BATTLE_TERRAIN_LONG_GRASS] =
    {
        .tileset = gBattleTerrainTiles_LongGrass,
        .tilemap = gBattleTerrainTilemap_LongGrass,
        .entryTileset = gBattleTerrainAnimTiles_LongGrass,
        .entryTilemap = gBattleTerrainAnimTilemap_LongGrass,
        .palette = gBattleTerrainPalette_LongGrass,
    },

    [BATTLE_TERRAIN_SAND] =
    {
        .tileset = gBattleTerrainTiles_Sand,
        .tilemap = gBattleTerrainTilemap_Sand,
        .entryTileset = gBattleTerrainAnimTiles_Sand,
        .entryTilemap = gBattleTerrainAnimTilemap_Sand,
        .palette = gBattleTerrainPalette_Sand,
    },

    [BATTLE_TERRAIN_UNDERWATER] =
    {
        .tileset = gBattleTerrainTiles_Underwater,
        .tilemap = gBattleTerrainTilemap_Underwater,
        .entryTileset = gBattleTerrainAnimTiles_Underwater,
        .entryTilemap = gBattleTerrainAnimTilemap_Underwater,
        .palette = gBattleTerrainPalette_Underwater,
    },

    [BATTLE_TERRAIN_WATER] =
    {
        .tileset = gBattleTerrainTiles_Water,
        .tilemap = gBattleTerrainTilemap_Water,
        .entryTileset = gBattleTerrainAnimTiles_Water,
        .entryTilemap = gBattleTerrainAnimTilemap_Water,
        .palette = gBattleTerrainPalette_Water,
    },

    [BATTLE_TERRAIN_POND] =
    {
        .tileset = gBattleTerrainTiles_PondWater,
        .tilemap = gBattleTerrainTilemap_PondWater,
        .entryTileset = gBattleTerrainAnimTiles_PondWater,
        .entryTilemap = gBattleTerrainAnimTilemap_PondWater,
        .palette = gBattleTerrainPalette_PondWater,
    },

    [BATTLE_TERRAIN_MOUNTAIN] =
    {
        .tileset = gBattleTerrainTiles_Rock,
        .tilemap = gBattleTerrainTilemap_Rock,
        .entryTileset = gBattleTerrainAnimTiles_Rock,
        .entryTilemap = gBattleTerrainAnimTilemap_Rock,
        .palette = gBattleTerrainPalette_Rock,
    },

    [BATTLE_TERRAIN_CAVE] =
    {
        .tileset = gBattleTerrainTiles_Cave,
        .tilemap = gBattleTerrainTilemap_Cave,
        .entryTileset = gBattleTerrainAnimTiles_Cave,
        .entryTilemap = gBattleTerrainAnimTilemap_Cave,
        .palette = gBattleTerrainPalette_Cave,
    },

    [BATTLE_TERRAIN_BUILDING] =
    {
        .tileset = gBattleTerrainTiles_Building,
        .tilemap = gBattleTerrainTilemap_Building,
        .entryTileset = gBattleTerrainAnimTiles_Building,
        .entryTilemap = gBattleTerrainAnimTilemap_Building,
        .palette = gBattleTerrainPalette_Building,
    },

    [BATTLE_TERRAIN_PLAIN] =
    {
        .tileset = gBattleTerrainTiles_Building,
        .tilemap = gBattleTerrainTilemap_Building,
        .entryTileset = gBattleTerrainAnimTiles_Building,
        .entryTilemap = gBattleTerrainAnimTilemap_Building,
        .palette = gBattleTerrainPalette_Plain,
    },
};

static void CB2_UnusedBattleInit(void);

static void UnusedBattleInit(void)
{
    u8 spriteId;

    ResetSpriteData();
    spriteId = CreateSprite(&gUnusedBattleInitSprite, 0, 0, 0);
    gSprites[spriteId].invisible = TRUE;
    SetMainCallback2(CB2_UnusedBattleInit);
}

static void CB2_UnusedBattleInit(void)
{
    AnimateSprites();
    BuildOamBuffer();
}

void BattleInitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gBattleBgTemplates, ARRAY_COUNT(gBattleBgTemplates));

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        gBattleScripting.windowsType = B_WIN_TYPE_ARENA;
        SetBgTilemapBuffer(1, gBattleAnimBgTilemapBuffer);
        SetBgTilemapBuffer(2, gBattleAnimBgTilemapBuffer);
    }
    else
    {
        gBattleScripting.windowsType = B_WIN_TYPE_NORMAL;
    }

    InitWindows(gBattleWindowTemplates[gBattleScripting.windowsType]);
    DeactivateAllTextPrinters();
}

void InitBattleBgsVideo(void)
{
    DisableInterrupts(INTR_FLAG_HBLANK);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    BattleInitBgsAndWindows();
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

void LoadBattleMenuWindowGfx(void)
{
    LoadUserWindowBorderGfx(2, 0x12, 0x10);
    LoadUserWindowBorderGfx(2, 0x22, 0x10);
    LoadCompressedPalette(gBattleWindowTextPalette, 0x50, 0x20);

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        // Load graphics for the Battle Arena referee's mid-battle messages.
        Menu_LoadStdPalAt(0x70);
        LoadMessageBoxGfx(0, 0x30, 0x70);
        gPlttBufferUnfaded[0x76] = 0;
        CpuCopy16(&gPlttBufferUnfaded[0x76], &gPlttBufferFaded[0x76], 2);
    }
}

void DrawMainBattleBackground(void)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_RECORDED_LINK))
    {
        LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
    {
        LZDecompressVram(gBattleTerrainTiles_Cave, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressVram(gBattleTerrainTilemap_Cave, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleTerrainPalette_Groudon, 0x20, 0x60);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE)
    {
        LZDecompressVram(gBattleTerrainTiles_Water, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressVram(gBattleTerrainTilemap_Water, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleTerrainPalette_Kyogre, 0x20, 0x60);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RAYQUAZA)
    {
        LZDecompressVram(gBattleTerrainTiles_Rayquaza, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressVram(gBattleTerrainTilemap_Rayquaza, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleTerrainPalette_Rayquaza, 0x20, 0x60);
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleTerrainPalette_BuildingLeader, 0x20, 0x60);
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleTerrainPalette_StadiumWallace, 0x20, 0x60);
                return;
            }
        }

        switch (GetCurrentMapBattleScene())
        {
        default:
        case MAP_BATTLE_SCENE_NORMAL:
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(sBattleTerrainTable[gBattleTerrain].palette, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_GYM:
            LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_BuildingGym, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_MAGMA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumMagma, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_AQUA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumAqua, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_SIDNEY:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumSidney, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_PHOEBE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumPhoebe, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_GLACIA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumGlacia, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_DRAKE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumDrake, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_FRONTIER:
            LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
            break;
        }
    }
}

void LoadBattleTextboxAndBackground(void)
{
    LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
    CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
    CopyBgTilemapBufferToVram(0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x40);
    LoadBattleMenuWindowGfx();
    DrawMainBattleBackground();
}

static void DrawLinkBattleParticipantPokeballs(u8 taskId, u8 multiplayerId, u8 bgId, u8 destX, u8 destY)
{
    s32 i;
    u16 pokeballStatuses = 0;
    u16 tiles[6];

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gTasks[taskId].data[5] != 0)
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            }
        }
        else
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            }
        }

        for (i = 0; i < 3; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 3, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
    else
    {
        if (multiplayerId == gBattleScripting.multiplayerId)
            pokeballStatuses = gTasks[taskId].data[3];
        else
            pokeballStatuses = gTasks[taskId].data[4];

        for (i = 0; i < 6; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 6, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
}

static void DrawLinkBattleVsScreenOutcomeText(void)
{
    if (gBattleOutcome == B_OUTCOME_DREW)
    {
        BattlePutTextOnWindow(gText_Draw, B_WIN_VS_OUTCOME_DRAW);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleOutcome == B_OUTCOME_WON)
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].id)
            {
            case 0:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 1:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 2:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 3:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            }
        }
        else
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].id)
            {
            case 0:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 1:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 2:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 3:
                BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            }
        }
    }
    else if (gBattleOutcome == B_OUTCOME_WON)
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].id != 0)
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
        }
        else
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
        }
    }
    else
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].id != 0)
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_LEFT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
        }
        else
        {
            BattlePutTextOnWindow(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
            BattlePutTextOnWindow(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
        }
    }
}

void InitLinkBattleVsScreen(u8 taskId)
{
    struct LinkPlayer *linkPlayer;
    u8 *name;
    s32 i, palId;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            for (i = 0; i < MAX_BATTLERS_COUNT; i++)
            {
                name = gLinkPlayers[i].name;
                linkPlayer = &gLinkPlayers[i];

                switch (linkPlayer->id)
                {
                case 0:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_1);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 1, 2, 4);
                    break;
                case 1:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_2);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 2, 2, 4);
                    break;
                case 2:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_3);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 1, 2, 8);
                    break;
                case 3:
                    BattlePutTextOnWindow(name, B_WIN_VS_MULTI_PLAYER_4);
                    DrawLinkBattleParticipantPokeballs(taskId, linkPlayer->id, 2, 2, 8);
                    break;
                }
            }
        }
        else
        {
            u8 playerId = gBattleScripting.multiplayerId;
            u8 opponentId = playerId ^ BIT_SIDE;
            u8 opponentId_copy = opponentId;

            if (gLinkPlayers[playerId].id != 0)
                opponentId = playerId, playerId = opponentId_copy;

            name = gLinkPlayers[playerId].name;
            BattlePutTextOnWindow(name, B_WIN_VS_PLAYER);

            name = gLinkPlayers[opponentId].name;
            BattlePutTextOnWindow(name, B_WIN_VS_OPPONENT);

            DrawLinkBattleParticipantPokeballs(taskId, playerId, 1, 2, 7);
            DrawLinkBattleParticipantPokeballs(taskId, opponentId, 2, 2, 7);
        }
        gTasks[taskId].data[0]++;
        break;
    case 1:
        palId = AllocSpritePalette(TAG_VS_LETTERS);
        gPlttBufferUnfaded[palId * 16 + 0x10F] = gPlttBufferFaded[palId * 16 + 0x10F] = 0x7FFF;
        gBattleStruct->linkBattleVsSpriteId_V = CreateSprite(&sVsLetter_V_SpriteTemplate, 111, 80, 0);
        gBattleStruct->linkBattleVsSpriteId_S = CreateSprite(&sVsLetter_S_SpriteTemplate, 129, 80, 0);
        gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = TRUE;
        gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = TRUE;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (gTasks[taskId].data[5] != 0)
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG1_Y = -36;
            gBattle_BG2_Y = -36;
        }
        else
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG1_Y = (Cos2(gTasks[taskId].data[1]) / 32) - 164;
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG2_Y = (Cos2(gTasks[taskId].data[2]) / 32) - 164;
        }

        if (gTasks[taskId].data[2] != 0)
        {
            gTasks[taskId].data[2] -= 2;
            gTasks[taskId].data[1] += 2;
        }
        else
        {
            if (gTasks[taskId].data[5] != 0)
                DrawLinkBattleVsScreenOutcomeText();

            PlaySE(SE_M_HARDEN);
            DestroyTask(taskId);
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].oam.tileNum += 0x40;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[0] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[0] = 1;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_V].x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_S].x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[2] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[2] = 0;
        }
        break;
    }
}

void DrawBattleEntryBackground(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        LZDecompressVram(gBattleVSFrame_Gfx, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressVram(gVsLettersGfx, (void *)OBJ_VRAM0);
        LoadCompressedPalette(gBattleVSFrame_Pal, 0x60, 0x20);
        SetBgAttribute(1, BG_ATTR_SCREENSIZE, 1);
        SetGpuReg(REG_OFFSET_BG1CNT, 0x5C04);
        CopyToBgTilemapBuffer(1, gBattleVSFrame_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(2, gBattleVSFrame_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        gBattle_BG1_Y = 0xFF5C;
        gBattle_BG2_Y = 0xFF5C;
        LoadCompressedSpriteSheetUsingHeap(&sVsLettersSpriteSheet);
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) || gPartnerTrainerId == TRAINER_STEVEN_PARTNER)
        {
            LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            // Set up bg for the multi battle intro where both teams slide in facing the screen.
            // Note Steven's multi battle (which has a dedicated back pic) is excluded above.
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 2);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 2);
            CopyToBgTilemapBuffer(1, gMultiBattleIntroBg_Opponent_Tilemap, 0, 0);
            CopyToBgTilemapBuffer(2, gMultiBattleIntroBg_Player_Tilemap, 0, 0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
    {
        LZDecompressVram(gBattleTerrainAnimTiles_Cave, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressVram(gBattleTerrainAnimTilemap_Cave, (void *)(BG_SCREEN_ADDR(28)));
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE)
    {
        LZDecompressVram(gBattleTerrainAnimTiles_Underwater, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressVram(gBattleTerrainAnimTilemap_Underwater, (void *)(BG_SCREEN_ADDR(28)));
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RAYQUAZA)
    {
        LZDecompressVram(gBattleTerrainAnimTiles_Rayquaza, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressVram(gBattleTerrainAnimTilemap_Rayquaza, (void *)(BG_SCREEN_ADDR(28)));
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
        }

        if (GetCurrentMapBattleScene() == MAP_BATTLE_SCENE_NORMAL)
        {
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(sBattleTerrainTable[gBattleTerrain].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            LZDecompressVram(gBattleTerrainAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressVram(gBattleTerrainAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
        }
    }
}

bool8 LoadChosenBattleElement(u8 caseId)
{
    bool8 ret = FALSE;

    switch (caseId)
    {
    case 0:
        LZDecompressVram(gBattleTextboxTiles, (void *)(BG_CHAR_ADDR(0)));
        break;
    case 1:
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
        CopyBgTilemapBufferToVram(0);
        break;
    case 2:
        LoadCompressedPalette(gBattleTextboxPalette, 0, 0x40);
        break;
    case 3:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
        {
            LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
        {
            LZDecompressVram(gBattleTerrainTiles_Cave, (void *)(BG_CHAR_ADDR(2)));
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressVram(gBattleTerrainTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                break;
            }
        }
        break;
    case 4:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
        {
            LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        {
            if (gGameVersion == VERSION_RUBY)
                LZDecompressVram(gBattleTerrainTilemap_Cave, (void *)(BG_SCREEN_ADDR(26)));
            else
                LZDecompressVram(gBattleTerrainTilemap_Water, (void *)(BG_SCREEN_ADDR(26)));
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressVram(sBattleTerrainTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressVram(gBattleTerrainTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                break;
            }
        }
        break;
    case 5:
        if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_EREADER_TRAINER))
        {
            LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        {
            if (gGameVersion == VERSION_RUBY)
                LoadCompressedPalette(gBattleTerrainPalette_Groudon, 0x20, 0x60);
            else
                LoadCompressedPalette(gBattleTerrainPalette_Kyogre, 0x20, 0x60);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LoadCompressedPalette(gBattleTerrainPalette_BuildingLeader, 0x20, 0x60);
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LoadCompressedPalette(gBattleTerrainPalette_StadiumWallace, 0x20, 0x60);
                    break;
                }
            }

            switch (GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LoadCompressedPalette(sBattleTerrainTable[gBattleTerrain].palette, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_GYM:
                LoadCompressedPalette(gBattleTerrainPalette_BuildingGym, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumMagma, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumAqua, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumSidney, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumPhoebe, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumGlacia, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LoadCompressedPalette(gBattleTerrainPalette_StadiumDrake, 0x20, 0x60);
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
                break;
            }
        }
        break;
    case 6:
        LoadBattleMenuWindowGfx();
        break;
    default:
        ret = TRUE;
        break;
    }

    return ret;
}
