#include "global.h"
#include "pokeblock.h"
#include "sprite.h"
#include "task.h"
#include "palette.h"
#include "menu.h"
#include "malloc.h"
#include "pokemon.h"
#include "blend_palette.h"
#include "main.h"
#include "menu_helpers.h"
#include "bg.h"
#include "gpu_regs.h"
#include "data2.h"
#include "decompress.h"
#include "event_data.h"
#include "strings.h"
#include "string_util.h"
#include "new_menu_helpers.h"
#include "party_menu.h"
#include "m4a.h"
#include "sound.h"
#include "battle.h" // to get rid of once gMonSpritesGfxPtr is put elsewhere

struct PokeblockFeedStruct
{
    u8 field_0[0x48];
    u8 tilemapBuffer[0x1008];
    u8 field_1050;
    u8 field_1051;
    u8 field_1052;
    bool8 noMonFlip;
    u16 species;
    u16 field_1056;
    u16 field_1058;
    u8 nature;
    u8 monSpriteId_;
    u8 field_105C;
    u8 monSpriteId;
    u8 pokeblockCaseSpriteId;
    u8 pokeblockSpriteId;
    u8 field_1060[0x1E];
    s16 loadGfxState;
    u8 somefield[2];
};

extern u8 gPokeblockMonId;
extern u16 gSpecialVar_ItemId;
extern s16 gPokeblockGain;
extern struct MusicPlayerInfo gMPlay_BGM;
extern struct SpriteTemplate gUnknown_0202499C;

extern struct PokeblockFeedStruct *sPokeblockFeed;
extern struct CompressedSpritePalette sPokeblockSpritePal;

extern bool8 sub_81221EC(void);
extern void sub_806A068(u16, u8);

// this file's functions
static void HandleInitBackgrounds(void);
static void HandleInitWindows(void);
static bool8 LoadMonAndSceneGfx(struct Pokemon *mon);
u8 CreatePokeblockCaseSpriteForFeeding(void);
static u8 CreateMonSprite(struct Pokemon *mon);
void LaunchPokeblockFeedTask(void);
static void SetPokeblockSpritePal(u8 pokeblockCaseId);
void sub_817A5CC(void);
void sub_8148108(u8 spriteId, bool8 a1);
u8 CreatePokeblockSprite(void);
void DoPokeblockCaseThrowEffect(u8 spriteId, bool8 arg1);
static void PrepareMonToMoveToPokeblock(u8 spriteId);
void Task_HandleMonAtePokeblock(u8 taskId);
void Task_PaletteFadeToReturn(u8 taskId);
void sub_817A634(void);
static void sub_817A468(struct Sprite *sprite);

static void CB2_PokeblockFeed(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void VBlankCB_PokeblockFeed(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

bool8 TransitionToPokeblockFeedScene(void)
{
    switch (gMain.state)
    {
    case 0:
        sPokeblockFeed = AllocZeroed(sizeof(*sPokeblockFeed));
        SetVBlankHBlankCallbacksToNull();
        clear_scheduled_bg_copies_to_vram();
        gMain.state++;
        break;
    case 1:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 2:
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 4:
        AllocateMonSpritesGfx();
        gMain.state++;
        break;
    case 5:
        HandleInitBackgrounds();
        gMain.state++;
        break;
    case 6:
        HandleInitWindows();
        gMain.state++;
        break;
    case 7:
        if (LoadMonAndSceneGfx(&gPlayerParty[gPokeblockMonId]))
        {
            gMain.state++;
        }
        break;
    case 8:
        sPokeblockFeed->pokeblockCaseSpriteId = CreatePokeblockCaseSpriteForFeeding();
        gMain.state++;
        break;
    case 9:
        sPokeblockFeed->monSpriteId = CreateMonSprite(&gPlayerParty[gPokeblockMonId]);
        gMain.state++;
        break;
    case 10:
        SetWindowBorderStyle(0, 1, 1, 14);
        gMain.state++;
        break;
    case 11:
        LaunchPokeblockFeedTask();
        gMain.state++;
        break;
    case 12:
        BlendPalettes(-1, 0x10, 0);
        gMain.state++;
        break;
    case 13:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_PokeblockFeed);
        SetMainCallback2(CB2_PokeblockFeed);
        return TRUE;
    }
    return FALSE;
}

void CB2_PreparePokeblockFeedScene(void)
{
    while (1)
    {
        if (sub_81221EC() == TRUE)
            break;
        if (TransitionToPokeblockFeedScene() == TRUE)
            break;
        if (sub_81221AC() == TRUE)
            break;
    }
}

extern const struct BgTemplate gUnknown_085F0550[2];
extern const u8 gBattleTerrainPalette_Frontier[];
extern const u8 gBattleTerrainTiles_Building[];
extern const u8 gUnknown_08D9BA44[];
extern const struct CompressedSpriteSheet gPokeblockCase_SpriteSheet;
extern const struct CompressedSpriteSheet gPokeblock_SpriteSheet;
extern const struct CompressedSpritePalette gPokeblockCase_SpritePal;
extern const struct CompressedSpriteSheet gMonFrontPicTable[];
extern const struct WindowTemplate gUnknown_085F0558[];
extern const u16 gUnknown_0860F074[];
extern const u8 *sPokeblocksPals[];
extern const union AffineAnimCmd * const sSpriteAffineAnimTable_85F05B0[];
extern const union AffineAnimCmd * const sSpriteAffineAnimTable_85F0664[];
extern const union AffineAnimCmd * const sSpriteAffineAnimTable_85F0668[];
extern const union AffineAnimCmd * const sSpriteAffineAnimTable_85F066C[];
extern const struct SpriteTemplate sThrownPokeblockSpriteTemplate;

static void HandleInitBackgrounds(void)
{
    ResetVramOamAndBgCntRegs();

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085F0550, ARRAY_COUNT(gUnknown_085F0550));
    SetBgTilemapBuffer(1, sPokeblockFeed->tilemapBuffer);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(1);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(1);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static bool8 LoadMonAndSceneGfx(struct Pokemon *mon)
{
    u16 species;
    u32 personality, trainerId;
    const struct CompressedSpritePalette *palette;

    switch (sPokeblockFeed->loadGfxState)
    {
    case 0:
        species = GetMonData(mon, MON_DATA_SPECIES2);
        personality = GetMonData(mon, MON_DATA_PERSONALITY);
        HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);
        sPokeblockFeed->loadGfxState++;
        break;
    case 1:
        species = GetMonData(mon, MON_DATA_SPECIES2);
        personality = GetMonData(mon, MON_DATA_PERSONALITY);
        trainerId = GetMonData(mon, MON_DATA_OT_ID);
        palette = GetMonSpritePalStructFromOtIdPersonality(species, trainerId, personality);

        LoadCompressedObjectPalette(palette);
        sub_806A068(palette->tag, 1);
        sPokeblockFeed->loadGfxState++;
        break;
    case 2:
        LoadCompressedObjectPic(&gPokeblockCase_SpriteSheet);
        sPokeblockFeed->loadGfxState++;
        break;
    case 3:
        LoadCompressedObjectPalette(&gPokeblockCase_SpritePal);
        sPokeblockFeed->loadGfxState++;
        break;
    case 4:
        LoadCompressedObjectPic(&gPokeblock_SpriteSheet);
        sPokeblockFeed->loadGfxState++;
        break;
    case 5:
        SetPokeblockSpritePal(gSpecialVar_ItemId);
        LoadCompressedObjectPalette(&sPokeblockSpritePal);
        sPokeblockFeed->loadGfxState++;
        break;
    case 6:
        reset_temp_tile_data_buffers();
        decompress_and_copy_tile_data_to_vram(1, gBattleTerrainTiles_Building, 0, 0, 0);
        sPokeblockFeed->loadGfxState++;
        break;
    case 7:
        if (free_temp_tile_data_buffers_if_possible() != TRUE)
        {
            LZDecompressWram(gUnknown_08D9BA44, sPokeblockFeed->tilemapBuffer);
            sPokeblockFeed->loadGfxState++;
        }
        break;
    case 8:
        LoadCompressedPalette(gBattleTerrainPalette_Frontier, 0x20, 0x60);
        sPokeblockFeed->loadGfxState = 0;
        return TRUE;
    }

    return FALSE;
}

extern void sub_809882C(u8, u16, u8);

static void HandleInitWindows(void)
{
    InitWindows(gUnknown_085F0558);
    DeactivateAllTextPrinters();
    sub_809882C(0, 1, 0xE0);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
    FillWindowPixelBuffer(0, 0);
    PutWindowTilemap(0);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void SetPokeblockSpritePal(u8 pokeblockCaseId)
{
    u8 colorId = GetPokeblockData(&gSaveBlock1Ptr->pokeblocks[pokeblockCaseId], PBLOCK_COLOR);
    sPokeblockSpritePal.data = sPokeblocksPals[colorId - 1];
    sPokeblockSpritePal.tag = TAG_POKEBLOCK_GFX;
}

#define tFrames     data[0]
#define tData1      data[1]

void Task_HandlePokeblockFeed(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        switch (gTasks[taskId].tFrames)
        {
        case 0:
            sPokeblockFeed->field_1050 = 0;
            sPokeblockFeed->field_1058 = 0;
            sub_817A5CC();
            break;
        case 255:
            DoPokeblockCaseThrowEffect(sPokeblockFeed->pokeblockCaseSpriteId, gTasks[taskId].tData1);
            break;
        case 269:
            sPokeblockFeed->pokeblockSpriteId = CreatePokeblockSprite();
            break;
        case 281:
            PrepareMonToMoveToPokeblock(sPokeblockFeed->monSpriteId);
            break;
        case 297:
            gTasks[taskId].func = Task_HandleMonAtePokeblock;
            return;
        }

        if (sPokeblockFeed->field_1058 < sPokeblockFeed->field_1056)
            sub_817A634();
        else if (sPokeblockFeed->field_1058 == sPokeblockFeed->field_1056)
            gTasks[taskId].tFrames = 254;

        sPokeblockFeed->field_1058++;
        gTasks[taskId].tFrames++;
    }
}

void LaunchPokeblockFeedTask(void)
{
    u8 taskId = CreateTask(Task_HandlePokeblockFeed, 0);
    gTasks[taskId].tFrames = 0;
    gTasks[taskId].tData1 = 1;
}

void Task_WaitForAtePokeblockText(u8 taskId)
{
    if (RunTextPrintersRetIsActive(0) != TRUE)
        gTasks[taskId].func = Task_PaletteFadeToReturn;
}

void Task_HandleMonAtePokeblock(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPokeblockMonId];
    struct Pokeblock *pokeblock = &gSaveBlock1Ptr->pokeblocks[gSpecialVar_ItemId];

    gPokeblockGain = PokeblockGetGain(GetNature(mon), pokeblock);
    GetMonNickname(mon, gStringVar1);
    PokeblockCopyName(pokeblock, gStringVar2);

    if (gPokeblockGain == 0)
        StringExpandPlaceholders(gStringVar4, gText_Var1AteTheVar2);
    else if (gPokeblockGain > 0)
        StringExpandPlaceholders(gStringVar4, gText_Var1HappilyAteVar2);
    else
        StringExpandPlaceholders(gStringVar4, gText_Var1DisdainfullyAteVar2);

    gTextFlags.flag_0 = 1;
    AddTextPrinterParametrized(0, 1, gStringVar4, GetPlayerTextSpeed(), NULL, 2, 1, 3);
    gTasks[taskId].func = Task_WaitForAtePokeblockText;
}

void Task_ReturnAfterPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResetSpriteData();
        FreeAllSpritePalettes();
        m4aMPlayVolumeControl(&gMPlay_BGM, -1, 256);
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        Free(sPokeblockFeed);
        FreeMonSpritesGfx();
    }
}

void Task_PaletteFadeToReturn(u8 taskId)
{
    BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
    gTasks[taskId].func = Task_ReturnAfterPaletteFade;
}

static u8 CreateMonSprite(struct Pokemon* mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2);
    u8 spriteId = CreateSprite(&gUnknown_0202499C, 48, 80, 2);

    sPokeblockFeed->species = species;
    sPokeblockFeed->monSpriteId_ = spriteId;
    sPokeblockFeed->nature = GetNature(mon);
    gSprites[spriteId].data2 = species;
    gSprites[spriteId].callback = SpriteCallbackDummy;

    sPokeblockFeed->noMonFlip = TRUE;
    if (!IsPokeSpriteNotFlipped(species))
    {
        gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_85F05B0;
        gSprites[spriteId].oam.affineMode = 3;
        CalcCenterToCornerVec(&gSprites[spriteId], gSprites[spriteId].oam.shape, gSprites[spriteId].oam.size, gSprites[spriteId].oam.affineMode);
        sPokeblockFeed->noMonFlip = FALSE;
    }

    return spriteId;
}

static void PrepareMonToMoveToPokeblock(u8 spriteId)
{
    gSprites[spriteId].pos1.x = 48;
    gSprites[spriteId].pos1.y = 80;
    gSprites[spriteId].data0 = -8;
    gSprites[spriteId].data1 = 1;
    gSprites[spriteId].callback = sub_817A468;
}

static void sub_817A468(struct Sprite* sprite)
{
    sprite->pos1.x += 4;
    sprite->pos1.y += sprite->data0;
    sprite->data0 += sprite->data1;

    if (sprite->data0 == 0)
        PlayCry1(sprite->data2, 0);
    if (sprite->data0 == 9)
        sprite->callback = SpriteCallbackDummy;
}

u8 CreatePokeblockCaseSpriteForFeeding(void)
{
    u8 spriteId = CreatePokeblockCaseSprite(188, 100, 2);
    gSprites[spriteId].oam.affineMode = 1;
    gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_85F0664;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    return spriteId;
}

void DoPokeblockCaseThrowEffect(u8 spriteId, bool8 a1)
{
    FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
    gSprites[spriteId].oam.affineMode = 3;

    if (!a1)
        gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_85F0668;
    else
        gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_85F066C;

    InitSpriteAffineAnim(&gSprites[spriteId]);
}

u8 CreatePokeblockSprite(void)
{
    u8 spriteId = CreateSprite(&sThrownPokeblockSpriteTemplate, 174, 84, 1);
    gSprites[spriteId].data0 = -12;
    gSprites[spriteId].data1 = 1;
    return spriteId;
}

static void SpriteCB_ThrownPokeblock(struct Sprite* sprite)
{
    sprite->pos1.x -= 4;
    sprite->pos1.y += sprite->data0;
    sprite->data0 += sprite->data1;
    if (sprite->data0 == 10)
        DestroySprite(sprite);
}
