#include "global.h"
#include "starter_choose.h"
#include "palette.h"
#include "sprite.h"
#include "pokemon.h"
#include "task.h"
#include "bg.h"
#include "gpu_regs.h"
#include "main.h"
#include "window.h"
#include "text.h"
#include "decompress.h"
#include "menu.h"
#include "sound.h"
#include "constants/songs.h"
#include "event_data.h"
#include "pokedex.h"
#include "data2.h"
#include "international_string_util.h"
#include "trig.h"

#define STARTER_MON_COUNT   3

// Position of the sprite of the selected starter Pokemon
#define STARTER_PKMN_POS_X 120
#define STARTER_PKMN_POS_Y 64

// text
extern const u8 gText_BirchInTrouble[];
extern const u8 gText_ConfirmStarterChoice[];

extern const u16 sStarterMon[STARTER_MON_COUNT];
extern const struct BgTemplate gUnknown_085B1E00[3];
extern const struct WindowTemplate gUnknown_085B1DCC[];
extern const struct WindowTemplate gUnknown_085B1DDC;
extern const struct CompressedSpriteSheet gUnknown_085B1ED8[];
extern const struct CompressedSpriteSheet gUnknown_085B1EE8[];
extern const struct SpritePalette gUnknown_085B1EF8[];
extern const struct SpriteTemplate sSpriteTemplate_PokeBall;
extern const struct SpriteTemplate sSpriteTemplate_Hand;
extern const struct SpriteTemplate gUnknown_085B1F40;
extern const union AffineAnimCmd *const gUnknown_085B1ED0;
extern const u8 sPokeballCoords[STARTER_MON_COUNT][2];
extern const struct WindowTemplate gUnknown_085B1DE4;
extern const u8 gStarterChoose_LabelCoords[][2];
extern const u8 gUnknown_085B1E0C[];
extern const u8 gUnknown_085B1E28[][2];

extern void LoadSav2WindowGfx(u8, u16, u8);
extern void ScanlineEffect_Stop(void);
extern void clear_scheduled_bg_copies_to_vram(void);
extern void dp13_810BB8C(void);
extern void do_scheduled_bg_tilemap_copies_to_vram(void);
extern u16 sub_818D820(u16);
extern const u16 *GetOverworldTextboxPalettePtr(void);
extern u8 sub_818D3E4(u16 species, u32 trainerId, u32 personality, u8 flags, s16 x, s16 y, u8, u16);

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
void StarterPokemonSpriteCallback(struct Sprite *sprite);

static IWRAM_DATA u16 sStarterChooseWindowId;

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

    LZ77UnCompVram(&gBirchHelpGfx, (void *)VRAM);
    LZ77UnCompVram(&gBirchBagTilemap, (void *)(VRAM + 0x3000));
    LZ77UnCompVram(&gBirchGrassTilemap, (void *)(VRAM + 0x3800));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085B1E00, ARRAY_COUNT(gUnknown_085B1E00));
    InitWindows(gUnknown_085B1DCC);

    DeactivateAllTextPrinters();
    LoadSav2WindowGfx(0, 0x2A8, 0xD0);
    clear_scheduled_bg_copies_to_vram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    dp13_810BB8C();

    LoadPalette(GetOverworldTextboxPalettePtr(), 0xE0, 0x20);
    LoadPalette(gBirchBagGrassPal, 0, 0x40);
    LoadCompressedObjectPic(&gUnknown_085B1ED8[0]);
    LoadCompressedObjectPic(&gUnknown_085B1EE8[0]);
    LoadSpritePalettes(gUnknown_085B1EF8);
    BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_StarterChoose);
    SetMainCallback2(MainCallback2_StarterChoose);

    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x1F);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0xFE);
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
    SetWindowBorderStyle(0, FALSE, 0x2A8, 0xD);
    PrintTextOnWindow(0, 1, gText_BirchInTrouble, 0, 1, 0, NULL);
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
    FillWindowPixelBuffer(0, 0x11);
    PrintTextOnWindow(0, 1, gText_ConfirmStarterChoice, 0, 1, 0, NULL);
    schedule_bg_copy_tilemap_to_vram(0);
    CreateYesNoMenu(&gUnknown_085B1DDC, 0x2A8, 0xD, 0);
    gTasks[taskId].func = Task_StarterChoose5;
}

static void Task_StarterChoose5(u8 taskId)
{
    u8 spriteId;

    switch (ProcessMenuInputNoWrap_())
    {
    case 0:  // YES
        // Return the starter choice and exit.
        gSpecialVar_Result = gTasks[taskId].tStarterSelection;
        dp13_810BB8C();
        SetMainCallback2(gMain.savedCallback);
        break;
    case 1:  // NO
    case -1: // B button
        PlaySE(SE_SELECT);
        spriteId = gTasks[taskId].tPkmnSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        sub_818D820(spriteId);

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
    u8 text[32];
    struct WindowTemplate winTemplate;
    const u8 *speciesName;
    s32 width;
    u8 labelLeft, labelRight, labelTop, labelBottom;

    u16 species = GetStarterPokemon(selection);
    CopyMonCategoryText(SpeciesToNationalPokedexNum(species), text);
    speciesName = gSpeciesNames[species];

    winTemplate = gUnknown_085B1DE4;
    winTemplate.tilemapLeft = gStarterChoose_LabelCoords[selection][0];
    winTemplate.tilemapTop = gStarterChoose_LabelCoords[selection][1];

    sStarterChooseWindowId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(sStarterChooseWindowId, 0);

    width = GetStringCenterAlignXOffset(7, text, 0x68);
    box_print(sStarterChooseWindowId, 7, width, 1, gUnknown_085B1E0C, 0, text);

    width = GetStringCenterAlignXOffset(1, speciesName, 0x68);
    box_print(sStarterChooseWindowId, 1, width, 0x11, gUnknown_085B1E0C, 0, speciesName);

    PutWindowTilemap(sStarterChooseWindowId);
    schedule_bg_copy_tilemap_to_vram(0);

    labelLeft = gStarterChoose_LabelCoords[selection][0] * 8 - 4;
    labelRight = (gStarterChoose_LabelCoords[selection][0] + 13) * 8 + 4;
    labelTop = gStarterChoose_LabelCoords[selection][1] * 8;
    labelBottom = (gStarterChoose_LabelCoords[selection][1] + 4) * 8;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(labelLeft, labelRight));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(labelTop, labelBottom));
}

static void sub_8134604(void)
{
    FillWindowPixelBuffer(sStarterChooseWindowId, 0);
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

    spriteId = sub_818D3E4(species, 8, 0, 1, x, y, 0xE, 0xFFFF);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

void sub_81346DC(struct Sprite *sprite)
{
    sprite->pos1.x = gUnknown_085B1E28[gTasks[sprite->data[0]].tStarterSelection][0];
    sprite->pos1.y = gUnknown_085B1E28[gTasks[sprite->data[0]].tStarterSelection][1];
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
