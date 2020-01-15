#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "starter_choose.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/rgb.h"

#define STARTER_MON_COUNT   3

// Position of the sprite of the selected starter Pokemon
#define STARTER_PKMN_POS_X 120
#define STARTER_PKMN_POS_Y 64

// text
extern const u8 gText_BirchInTrouble[];
extern const u8 gText_ConfirmStarterChoice[];

// this file's functions
static void MainCallback2_StarterChoose(void);
static void sub_8134604(void);
static void Task_StarterChoose1(u8 taskId);
static void Task_StarterChoose2(u8 taskId);
static void Task_StarterChoose3(u8 taskId);
static void Task_StarterChoose4(u8 taskId);
static void Task_StarterChoose5(u8 taskId);
static void Task_StarterChoose6(u8 taskId);
static void Task_MoveStarterChooseCursor(u8 taskId);
static void sub_8134668(u8 taskId);
static void CreateStarterPokemonLabel(u8 selection);
static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y);
void sub_81346DC(struct Sprite *sprite);
void sub_813473C(struct Sprite *sprite);
void StarterPokemonSpriteCallback(struct Sprite *sprite);

static u16 sStarterChooseWindowId;

// .rodata
const u16 gBirchBagGrassPal[][16] =
{
    INCBIN_U16("graphics/misc/birch_bag.gbapal"),
    INCBIN_U16("graphics/misc/birch_grass.gbapal"),
};

const u16 gBirchBallarrow_Pal[] = INCBIN_U16("graphics/misc/birch_ballarrow.gbapal");

const u16 gBirchCircle_Pal[] = INCBIN_U16("graphics/misc/birch_circle.gbapal");

const u32 gBirchBagTilemap[] = INCBIN_U32("graphics/misc/birch_bag_map.bin.lz");

const u32 gBirchGrassTilemap[] = INCBIN_U32("graphics/misc/birch_grass_map.bin.lz");

const u32 gBirchHelpGfx[] = INCBIN_U32("graphics/misc/birch_help.4bpp.lz");

const u32 gUnknown_085B18AC[] = INCBIN_U32("graphics/misc/birch_ballarrow.4bpp.lz");

const u32 gUnknown_085B1BCC[] = INCBIN_U32("graphics/misc/birch_circle.4bpp.lz");

static const struct WindowTemplate gUnknown_085B1DCC[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x0200
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate gUnknown_085B1DDC =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x0260
};

static const struct WindowTemplate gUnknown_085B1DE4 =
{
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 13,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0x0274
};

static const u8 sPokeballCoords[STARTER_MON_COUNT][2] =
{
    {60, 64},
    {120, 88},
    {180, 64},
};

static const u8 sStarterLabelCoords[][2] =
{
    {0, 9},
    {16, 10},
    {8, 4},
};

static const u16 sStarterMon[STARTER_MON_COUNT] =
{
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
};

static const struct BgTemplate gUnknown_085B1E00[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const u8 sTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GREY};

static const struct OamData gOamData_85B1E10 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gOamData_85B1E18 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gOamData_85B1E20 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
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
    .affineParam = 0,
};

static const u8 sCursorCoords[][2] =
{
    {60, 32},
    {120, 56},
    {180, 32},
};

static const union AnimCmd gSpriteAnim_85B1E30[] =
{
    ANIMCMD_FRAME(48, 30),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_85B1E38[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_85B1E40[] =
{
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(32, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gSpriteAnim_85B1E88[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd * const gSpriteAnimTable_85B1E90[] =
{
    gSpriteAnim_85B1E30,
};

static const union AnimCmd * const gSpriteAnimTable_85B1E94[] =
{
    gSpriteAnim_85B1E38,
    gSpriteAnim_85B1E40,
};

static const union AnimCmd * const gSpriteAnimTable_85B1E9C[] =
{
    gSpriteAnim_85B1E88,
};

static const union AffineAnimCmd gSpriteAffineAnim_85B1EA0[] =
{
    AFFINEANIMCMD_FRAME(16, 16, 0, 0),
    AFFINEANIMCMD_FRAME(16, 16, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gSpriteAffineAnim_85B1EB8[] =
{
    AFFINEANIMCMD_FRAME(20, 20, 0, 0),
    AFFINEANIMCMD_FRAME(20, 20, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd * const gUnknown_085B1ED0 = {gSpriteAffineAnim_85B1EA0};
static const union AffineAnimCmd * const gSpriteAffineAnimTable_85B1ED4[] = {gSpriteAffineAnim_85B1EB8};

static const struct CompressedSpriteSheet gUnknown_085B1ED8[] =
{
    {
        .data = gUnknown_085B18AC,
        .size = 0x0800,
        .tag = 0x1000
    },
    {}
};

static const struct CompressedSpriteSheet gUnknown_085B1EE8[] =
{
    {
        .data = gUnknown_085B1BCC,
        .size = 0x0800,
        .tag = 0x1001
    },
    {}
};

static const struct SpritePalette gUnknown_085B1EF8[] =
{
    {
        .data = gBirchBallarrow_Pal,
        .tag = 0x1000
    },
    {
        .data = gBirchCircle_Pal,
        .tag = 0x1001
    },
    {},
};

static const struct SpriteTemplate sSpriteTemplate_Hand =
{
    .tileTag = 0x1000,
    .paletteTag = 0x1000,
    .oam = &gOamData_85B1E10,
    .anims = gSpriteAnimTable_85B1E90,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81346DC
};

static const struct SpriteTemplate sSpriteTemplate_PokeBall =
{
    .tileTag = 0x1000,
    .paletteTag = 0x1000,
    .oam = &gOamData_85B1E18,
    .anims = gSpriteAnimTable_85B1E94,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_813473C
};

static const struct SpriteTemplate gUnknown_085B1F40 =
{
    .tileTag = 0x1001,
    .paletteTag = 0x1001,
    .oam = &gOamData_85B1E20,
    .anims = gSpriteAnimTable_85B1E9C,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_85B1ED4,
    .callback = StarterPokemonSpriteCallback
};

// .text
u16 GetStarterPokemon(u16 chosenStarterId)
{
    if (chosenStarterId > STARTER_MON_COUNT)
        chosenStarterId = 0;
    return sStarterMon[chosenStarterId];
}

static void VblankCB_StarterChoose(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

#define tStarterSelection   data[0]
#define tPkmnSpriteId       data[1]
#define tCircleSpriteId     data[2]

void CB2_ChooseStarter(void)
{
    u16 savedIme;
    u8 taskId;
    u8 spriteId;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);

    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gBirchHelpGfx, (void *)VRAM);
    LZ77UnCompVram(gBirchBagTilemap, (void *)(BG_SCREEN_ADDR(6)));
    LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085B1E00, ARRAY_COUNT(gUnknown_085B1E00));
    InitWindows(gUnknown_085B1DCC);

    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x2A8, 0xD0);
    clear_scheduled_bg_copies_to_vram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    LoadPalette(GetOverworldTextboxPalettePtr(), 0xE0, 0x20);
    LoadPalette(gBirchBagGrassPal, 0, 0x40);
    LoadCompressedSpriteSheet(&gUnknown_085B1ED8[0]);
    LoadCompressedSpriteSheet(&gUnknown_085B1EE8[0]);
    LoadSpritePalettes(gUnknown_085B1EF8);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_StarterChoose);
    SetMainCallback2(MainCallback2_StarterChoose);

    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x1F);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    taskId = CreateTask(Task_StarterChoose1, 0);
    gTasks[taskId].tStarterSelection = 1;

    // Create hand sprite
    spriteId = CreateSprite(&sSpriteTemplate_Hand, 120, 56, 2);
    gSprites[spriteId].data[0] = taskId;

    // Create three Pokeball sprites
    spriteId = CreateSprite(&sSpriteTemplate_PokeBall, sPokeballCoords[0][0], sPokeballCoords[0][1], 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 0;

    spriteId = CreateSprite(&sSpriteTemplate_PokeBall, sPokeballCoords[1][0], sPokeballCoords[1][1], 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 1;

    spriteId = CreateSprite(&sSpriteTemplate_PokeBall, sPokeballCoords[2][0], sPokeballCoords[2][1], 2);
    gSprites[spriteId].data[0] = taskId;
    gSprites[spriteId].data[1] = 2;

    sStarterChooseWindowId = 0xFF;
}

static void MainCallback2_StarterChoose(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void Task_StarterChoose1(u8 taskId)
{
    CreateStarterPokemonLabel(gTasks[taskId].tStarterSelection);
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
    AddTextPrinterParameterized(0, 1, gText_BirchInTrouble, 0, 1, 0, NULL);
    PutWindowTilemap(0);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = Task_StarterChoose2;
}

static void Task_StarterChoose2(u8 taskId)
{
    u8 selection = gTasks[taskId].tStarterSelection;

    if (gMain.newKeys & A_BUTTON)
    {
        u8 spriteId;

        sub_8134604();

        // Create white circle background
        spriteId = CreateSprite(&gUnknown_085B1F40, sPokeballCoords[selection][0], sPokeballCoords[selection][1], 1);
        gTasks[taskId].tCircleSpriteId = spriteId;

        // Create Pokemon sprite
        spriteId = CreatePokemonFrontSprite(GetStarterPokemon(gTasks[taskId].tStarterSelection), sPokeballCoords[selection][0], sPokeballCoords[selection][1]);
        gSprites[spriteId].affineAnims = &gUnknown_085B1ED0;
        gSprites[spriteId].callback = StarterPokemonSpriteCallback;

        gTasks[taskId].tPkmnSpriteId = spriteId;
        gTasks[taskId].func = Task_StarterChoose3;
    }
    else if ((gMain.newKeys & DPAD_LEFT) && selection > 0)
    {
        gTasks[taskId].tStarterSelection--;
        gTasks[taskId].func = Task_MoveStarterChooseCursor;
    }
    else if ((gMain.newKeys & DPAD_RIGHT) && selection < (STARTER_MON_COUNT - 1))
    {
        gTasks[taskId].tStarterSelection++;
        gTasks[taskId].func = Task_MoveStarterChooseCursor;
    }
}

static void Task_StarterChoose3(u8 taskId)
{
    if (gSprites[gTasks[taskId].tCircleSpriteId].affineAnimEnded &&
      gSprites[gTasks[taskId].tCircleSpriteId].pos1.x == STARTER_PKMN_POS_X &&
      gSprites[gTasks[taskId].tCircleSpriteId].pos1.y == STARTER_PKMN_POS_Y)
    {
        gTasks[taskId].func = Task_StarterChoose4;
    }
}

static void Task_StarterChoose4(u8 taskId)
{
    PlayCry1(GetStarterPokemon(gTasks[taskId].tStarterSelection), 0);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, 1, gText_ConfirmStarterChoice, 0, 1, 0, NULL);
    schedule_bg_copy_tilemap_to_vram(0);
    CreateYesNoMenu(&gUnknown_085B1DDC, 0x2A8, 0xD, 0);
    gTasks[taskId].func = Task_StarterChoose5;
}

static void Task_StarterChoose5(u8 taskId)
{
    u8 spriteId;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:  // YES
        // Return the starter choice and exit.
        gSpecialVar_Result = gTasks[taskId].tStarterSelection;
        ResetAllPicSprites();
        SetMainCallback2(gMain.savedCallback);
        break;
    case 1:  // NO
    case -1: // B button
        PlaySE(SE_SELECT);
        spriteId = gTasks[taskId].tPkmnSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        FreeAndDestroyMonPicSprite(spriteId);

        spriteId = gTasks[taskId].tCircleSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
        gTasks[taskId].func = Task_StarterChoose6;
        break;
    }
}

static void Task_StarterChoose6(u8 taskId)
{
    gTasks[taskId].func = Task_StarterChoose1;
}

static void CreateStarterPokemonLabel(u8 selection)
{
    u8 categoryText[32];
    struct WindowTemplate winTemplate;
    const u8 *speciesName;
    s32 width;
    u8 labelLeft, labelRight, labelTop, labelBottom;

    u16 species = GetStarterPokemon(selection);
    CopyMonCategoryText(SpeciesToNationalPokedexNum(species), categoryText);
    speciesName = gSpeciesNames[species];

    winTemplate = gUnknown_085B1DE4;
    winTemplate.tilemapLeft = sStarterLabelCoords[selection][0];
    winTemplate.tilemapTop = sStarterLabelCoords[selection][1];

    sStarterChooseWindowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(sStarterChooseWindowId, PIXEL_FILL(0));

    width = GetStringCenterAlignXOffset(7, categoryText, 0x68);
    AddTextPrinterParameterized3(sStarterChooseWindowId, 7, width, 1, sTextColors, 0, categoryText);

    width = GetStringCenterAlignXOffset(1, speciesName, 0x68);
    AddTextPrinterParameterized3(sStarterChooseWindowId, 1, width, 0x11, sTextColors, 0, speciesName);

    PutWindowTilemap(sStarterChooseWindowId);
    schedule_bg_copy_tilemap_to_vram(0);

    labelLeft = sStarterLabelCoords[selection][0] * 8 - 4;
    labelRight = (sStarterLabelCoords[selection][0] + 13) * 8 + 4;
    labelTop = sStarterLabelCoords[selection][1] * 8;
    labelBottom = (sStarterLabelCoords[selection][1] + 4) * 8;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(labelLeft, labelRight));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(labelTop, labelBottom));
}

static void sub_8134604(void)
{
    FillWindowPixelBuffer(sStarterChooseWindowId, PIXEL_FILL(0));
    ClearWindowTilemap(sStarterChooseWindowId);
    RemoveWindow(sStarterChooseWindowId);
    sStarterChooseWindowId = 0xFF;
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void Task_MoveStarterChooseCursor(u8 taskId)
{
    sub_8134604();
    gTasks[taskId].func = sub_8134668;
}

static void sub_8134668(u8 taskId)
{
    CreateStarterPokemonLabel(gTasks[taskId].tStarterSelection);
    gTasks[taskId].func = Task_StarterChoose2;
}

static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y)
{
    u8 spriteId;

    spriteId = CreatePicSprite2(species, SHINY_ODDS, 0, 1, x, y, 0xE, 0xFFFF);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

void sub_81346DC(struct Sprite *sprite)
{
    sprite->pos1.x = sCursorCoords[gTasks[sprite->data[0]].tStarterSelection][0];
    sprite->pos1.y = sCursorCoords[gTasks[sprite->data[0]].tStarterSelection][1];
    sprite->pos2.y = Sin(sprite->data[1], 8);
    sprite->data[1] = (u8)(sprite->data[1]) + 4;
}

void sub_813473C(struct Sprite *sprite)
{
    if (gTasks[sprite->data[0]].tStarterSelection == sprite->data[1])
        StartSpriteAnimIfDifferent(sprite, 1);
    else
        StartSpriteAnimIfDifferent(sprite, 0);
}

void StarterPokemonSpriteCallback(struct Sprite *sprite)
{
    //Move sprite to upper center of screen
    if (sprite->pos1.x > STARTER_PKMN_POS_X)
        sprite->pos1.x -= 4;
    if (sprite->pos1.x < STARTER_PKMN_POS_X)
        sprite->pos1.x += 4;
    if (sprite->pos1.y > STARTER_PKMN_POS_Y)
        sprite->pos1.y -= 2;
    if (sprite->pos1.y < STARTER_PKMN_POS_Y)
        sprite->pos1.y += 2;
}
