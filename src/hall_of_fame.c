#include "global.h"
#include "hall_of_fame.h"
#include "task.h"
#include "palette.h"
#include "sprite.h"
#include "pokemon.h"
#include "text.h"
#include "text_window.h"
#include "alloc.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "sound.h"
#include "constants/songs.h"
#include "decompress.h"
#include "save.h"
#include "strings.h"
#include "window.h"
#include "credits.h"
#include "bg.h"
#include "constants/species.h"
#include "constants/game_stat.h"
#include "util.h"
#include "string_util.h"
#include "m4a.h"
#include "international_string_util.h"
#include "scanline_effect.h"
#include "trig.h"
#include "random.h"
#include "event_data.h"
#include "overworld.h"
#include "menu.h"
#include "fldeff_misc.h"
#include "trainer_pokemon_sprites.h"
#include "data.h"
#include "rom_81520A8.h"
#include "constants/rgb.h"

struct HallofFameMon
{
    u32 tid;
    u32 personality;
    u16 species;
    u8 lvl;
    u8 nick[POKEMON_NAME_LENGTH];
};

struct HallofFameTeam
{
    struct HallofFameMon mon[PARTY_SIZE];
};

struct HofGfx
{
    u16 state;
    u8 field_2[16];
    u8 tilemap1[0x1000];
    u8 tilemap2[0x1000];
};

static EWRAM_DATA u32 sUnknown_0203BCD4 = 0;
static EWRAM_DATA struct HallofFameTeam *sHofMonPtr = NULL;
static EWRAM_DATA struct HofGfx *sHofGfxPtr = NULL;

extern struct MusicPlayerInfo gMPlayInfo_BGM;

#define HALL_OF_FAME_MAX_TEAMS 30

// this file's functions
static void ClearVramOamPltt_LoadHofPal(void);
static void sub_8174F70(void);
static void sub_8174FAC(void);
static bool8 sub_81751FC(void);
static void SetCallback2AfterHallOfFameDisplay(void);
static bool8 sub_8175024(void);
static void Task_Hof_InitMonData(u8 taskId);
static void Task_Hof_InitTeamSaveData(u8 taskId);
static void Task_Hof_SetMonDisplayTask(u8 taskId);
static void Task_Hof_TrySaveData(u8 taskId);
static void Task_Hof_WaitForFrames(u8 taskId);
static void Task_Hof_DisplayMon(u8 taskId);
static void Task_Hof_PrintMonInfoAfterAnimating(u8 taskId);
static void Task_Hof_TryDisplayAnotherMon(u8 taskId);
static void Task_Hof_PaletteFadeAndPrintWelcomeText(u8 taskId);
static void sub_8173DC0(u8 taskId);
static void sub_8173EA4(u8 taskId);
static void sub_8173EE4(u8 taskId);
static void Task_Hof_WaitAndPrintPlayerInfo(u8 taskId);
static void Task_Hof_ExitOnKeyPressed(u8 taskId);
static void Task_Hof_HandlePaletteOnExit(u8 taskId);
static void Task_Hof_HandleExit(u8 taskId);
static void Task_HofPC_CopySaveData(u8 taskId);
static void Task_HofPC_PrintDataIsCorrupted(u8 taskId);
static void Task_HofPC_DrawSpritesPrintText(u8 taskId);
static void Task_HofPC_PrintMonInfo(u8 taskId);
static void Task_HofPC_HandleInput(u8 taskId);
static void Task_HofPC_HandlePaletteOnExit(u8 taskId);
static void Task_HofPC_HandleExit(u8 taskId);
static void Task_HofPC_ExitOnButtonPress(u8 taskId);
static void SpriteCB_GetOnScreenAndAnimate(struct Sprite *sprite);
static void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 unused1, u8 unused2);
static void HallOfFame_PrintWelcomeText(u8 unusedPossiblyWindowId, u8 unused2);
static void HallOfFame_PrintPlayerInfo(u8 unused1, u8 unused2);
static void sub_8175364(u8 taskId);
static void sub_81751A4(struct Sprite* sprite);

// const rom data
static const struct BgTemplate sHof_BgTemplates[] =
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
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate sHof_WindowTemplate = {0, 2, 2, 0xE, 6, 0xE, 1};

static const u8 sUnknown_085E5388[] = {0, 1, 2, 0};

static const u8 sUnknown_085E538C[] = {0, 2, 3, 0, 4, 5, 0, 0};

static const struct CompressedSpriteSheet sHallOfFame_ConfettiSpriteSheet[] =
{
    {gContestConfetti_Gfx, 0x220, 1001},
    {},
};

static const struct CompressedSpritePalette sHallOfFame_ConfettiSpritePalette[] =
{
    {gContestConfetti_Pal, 1001},
    {},
};

static const s16 sHallOfFame_MonFullTeamPositions[6][4] =
{
    {120,   210,    120,    40},
    {326,   220,    56,     40},
    {-86,   220,    184,    40},
    {120,   -62,    120,    88},
    {-70,   -92,    200,    88},
    {310,   -92,    40,     88}
};

static const s16 sHallOfFame_MonHalfTeamPositions[3][4] =
{
    {120,   234,    120,    64},
    {326,   244,    56,     64},
    {-86,   244,    184,    64}
};

static const struct OamData sOamData_85E53FC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_85E5404[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E540C[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5414[] =
{
    ANIMCMD_FRAME(2, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E541C[] =
{
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5424[] =
{
    ANIMCMD_FRAME(4, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E542C[] =
{
    ANIMCMD_FRAME(5, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5434[] =
{
    ANIMCMD_FRAME(6, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E543C[] =
{
    ANIMCMD_FRAME(7, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5444[] =
{
    ANIMCMD_FRAME(8, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E544C[] =
{
    ANIMCMD_FRAME(9, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5454[] =
{
    ANIMCMD_FRAME(10, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E545C[] =
{
    ANIMCMD_FRAME(11, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5464[] =
{
    ANIMCMD_FRAME(12, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E546C[] =
{
    ANIMCMD_FRAME(13, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5474[] =
{
    ANIMCMD_FRAME(14, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E547C[] =
{
    ANIMCMD_FRAME(15, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_85E5484[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd * const sSpriteAnimTable_85E548C[] =
{
    sSpriteAnim_85E5404, sSpriteAnim_85E540C, sSpriteAnim_85E5414, sSpriteAnim_85E541C,
    sSpriteAnim_85E5424, sSpriteAnim_85E542C, sSpriteAnim_85E5434, sSpriteAnim_85E543C,
    sSpriteAnim_85E5444, sSpriteAnim_85E544C, sSpriteAnim_85E5454, sSpriteAnim_85E545C,
    sSpriteAnim_85E5464, sSpriteAnim_85E546C, sSpriteAnim_85E5474, sSpriteAnim_85E547C,
    sSpriteAnim_85E5484
};

static const struct SpriteTemplate sSpriteTemplate_85E54D0 =
{
    .tileTag = 1001,
    .paletteTag = 1001,
    .oam = &sOamData_85E53FC,
    .anims = sSpriteAnimTable_85E548C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81751A4
};

static const u16 sHallOfFame_Pal[] = INCBIN_U16("graphics/misc/japanese_hof.gbapal");

static const u32 sHallOfFame_Gfx[] = INCBIN_U32("graphics/misc/japanese_hof.4bpp.lz");

static const struct HallofFameMon sDummyFameMon =
{
    0x3EA03EA, 0, 0, 0, {0}
};

static const u8 sUnused2[] = {2, 1, 3, 6, 4, 5, 0, 0};

// code
static void VBlankCB_HallOfFame(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_HallOfFame(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static bool8 InitHallOfFameScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ClearVramOamPltt_LoadHofPal();
        sHofGfxPtr = AllocZeroed(sizeof(*sHofGfxPtr));
        gMain.state = 1;
        break;
    case 1:
        sub_8174F70();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 7));
        SetGpuReg(REG_OFFSET_BLDY, 0);
        sub_8174FAC();
        sHofGfxPtr->state = 0;
        gMain.state++;
        break;
    case 3:
        if (!sub_8175024())
        {
            SetVBlankCallback(VBlankCB_HallOfFame);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
            gMain.state++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_HallOfFame);
            PlayBGM(MUS_DENDOU);
            return FALSE;
        }
        break;
    }
    return TRUE;
}

#define tDontSaveData       data[0]
#define tDisplayedMonId     data[1]
#define tMonNumber          data[2]
#define tFrameCount         data[3]
#define tPlayerSpriteID     data[4]
#define tMonSpriteId(i)     data[i + 5]

void CB2_DoHallOfFameScreen(void)
{
    if (!InitHallOfFameScreen())
    {
        u8 taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].tDontSaveData = FALSE;
        sHofMonPtr = AllocZeroed(sizeof(*sHofMonPtr));
    }
}

void CB2_DoHallOfFameScreenDontSaveData(void)
{
    if (!InitHallOfFameScreen())
    {
        u8 taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].tDontSaveData = TRUE;
        sHofMonPtr = AllocZeroed(sizeof(*sHofMonPtr));
    }
}

static void Task_Hof_InitMonData(u8 taskId)
{
    u16 i, j;

    gTasks[taskId].tMonNumber = 0; // valid pokes

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 nick[POKEMON_NAME_LENGTH + 2];
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
        {
            sHofMonPtr->mon[i].species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            sHofMonPtr->mon[i].tid = GetMonData(&gPlayerParty[i], MON_DATA_OT_ID);
            sHofMonPtr->mon[i].personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            sHofMonPtr->mon[i].lvl = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            GetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, nick);
            for (j = 0; j < POKEMON_NAME_LENGTH; j++)
            {
                sHofMonPtr->mon[i].nick[j] = nick[j];
            }
            gTasks[taskId].tMonNumber++;
        }
        else
        {
            sHofMonPtr->mon[i].species = 0;
            sHofMonPtr->mon[i].tid = 0;
            sHofMonPtr->mon[i].personality = 0;
            sHofMonPtr->mon[i].lvl = 0;
            sHofMonPtr->mon[i].nick[0] = EOS;
        }
    }

    sUnknown_0203BCD4 = 0;
    gTasks[taskId].tDisplayedMonId = 0;
    gTasks[taskId].tPlayerSpriteID = 0xFF;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        gTasks[taskId].tMonSpriteId(i) = 0xFF;
    }

    if (gTasks[taskId].tDontSaveData)
        gTasks[taskId].func = Task_Hof_SetMonDisplayTask;
    else
        gTasks[taskId].func = Task_Hof_InitTeamSaveData;
}

static void Task_Hof_InitTeamSaveData(u8 taskId)
{
    u16 i;
    struct HallofFameTeam* lastSavedTeam = (struct HallofFameTeam*)(gDecompressionBuffer);

    if (!gHasHallOfFameRecords)
    {
        memset(gDecompressionBuffer, 0, 0x2000);
    }
    else
    {
        if (Save_LoadGameData(3) != TRUE)
            memset(gDecompressionBuffer, 0, 0x2000);
    }

    for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, lastSavedTeam++)
    {
        if (lastSavedTeam->mon[0].species == SPECIES_NONE)
            break;
    }
    if (i >= HALL_OF_FAME_MAX_TEAMS)
    {
        struct HallofFameTeam *afterTeam = (struct HallofFameTeam*)(gDecompressionBuffer);
        struct HallofFameTeam *beforeTeam = (struct HallofFameTeam*)(gDecompressionBuffer);
        afterTeam++;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS - 1; i++, beforeTeam++, afterTeam++)
        {
            *beforeTeam = *afterTeam;
        }
        lastSavedTeam--;
    }
    *lastSavedTeam = *sHofMonPtr;

    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized2(0, 1, gText_SavingDontTurnOffPower, 0, NULL, 2, 1, 3);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_Hof_TrySaveData;
}

static void Task_Hof_TrySaveData(u8 taskId)
{
    gGameContinueCallback = CB2_DoHallOfFameScreenDontSaveData;
    if (TrySavingData(SAVE_HALL_OF_FAME) == 0xFF && gDamagedSaveSectors != 0)
    {
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        FreeAllWindowBuffers();

        if (sHofGfxPtr != NULL)
            FREE_AND_SET_NULL(sHofGfxPtr);
        if (sHofMonPtr != NULL)
            FREE_AND_SET_NULL(sHofMonPtr);

        DestroyTask(taskId);
    }
    else
    {
        PlaySE(SE_SAVE);
        gTasks[taskId].func = Task_Hof_WaitForFrames;
        gTasks[taskId].tFrameCount = 32;
    }
}

static void Task_Hof_WaitForFrames(u8 taskId)
{
    if (gTasks[taskId].tFrameCount)
        gTasks[taskId].tFrameCount--;
    else
        gTasks[taskId].func = Task_Hof_SetMonDisplayTask;
}

static void Task_Hof_SetMonDisplayTask(u8 taskId)
{
    gTasks[taskId].func = Task_Hof_DisplayMon;
}

#define tDestinationX  data[1]
#define tDestinationY  data[2]
#define tSpecies       data[7]

static void Task_Hof_DisplayMon(u8 taskId)
{
    u8 spriteId;
    s16 xPos, yPos, field4, field6;

    u16 currMonId = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &sHofMonPtr->mon[currMonId];

    if (gTasks[taskId].tMonNumber > 3)
    {
        xPos = sHallOfFame_MonFullTeamPositions[currMonId][0];
        yPos = sHallOfFame_MonFullTeamPositions[currMonId][1];
        field4 = sHallOfFame_MonFullTeamPositions[currMonId][2];
        field6 = sHallOfFame_MonFullTeamPositions[currMonId][3];
    }
    else
    {
        xPos = sHallOfFame_MonHalfTeamPositions[currMonId][0];
        yPos = sHallOfFame_MonHalfTeamPositions[currMonId][1];
        field4 = sHallOfFame_MonHalfTeamPositions[currMonId][2];
        field6 = sHallOfFame_MonHalfTeamPositions[currMonId][3];
    }

    if (currMon->species == SPECIES_EGG)
        field6 += 10;

    spriteId = CreatePicSprite2(currMon->species, currMon->tid, currMon->personality, 1, xPos, yPos, currMonId, 0xFFFF);
    gSprites[spriteId].tDestinationX = field4;
    gSprites[spriteId].tDestinationY = field6;
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].tSpecies = currMon->species;
    gSprites[spriteId].callback = SpriteCB_GetOnScreenAndAnimate;
    gTasks[taskId].tMonSpriteId(currMonId) = spriteId;
    ClearDialogWindowAndFrame(0, TRUE);
    gTasks[taskId].func = Task_Hof_PrintMonInfoAfterAnimating;
}

static void Task_Hof_PrintMonInfoAfterAnimating(u8 taskId)
{
    u16 currMonId = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &sHofMonPtr->mon[currMonId];
    struct Sprite *monSprite = &gSprites[gTasks[taskId].tMonSpriteId(currMonId)];

    if (monSprite->callback == SpriteCallbackDummy)
    {
        monSprite->oam.affineMode = 0;
        HallOfFame_PrintMonInfo(currMon, 0, 14);
        gTasks[taskId].tFrameCount = 120;
        gTasks[taskId].func = Task_Hof_TryDisplayAnotherMon;
    }
}

static void Task_Hof_TryDisplayAnotherMon(u8 taskId)
{
    u16 currPokeID = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &sHofMonPtr->mon[currPokeID];

    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
    }
    else
    {
        sUnknown_0203BCD4 |= (0x10000 << gSprites[gTasks[taskId].tMonSpriteId(currPokeID)].oam.paletteNum);
        if (gTasks[taskId].tDisplayedMonId <= 4 && currMon[1].species != SPECIES_NONE) // there is another pokemon to display
        {
            gTasks[taskId].tDisplayedMonId++;
            BeginNormalPaletteFade(sUnknown_0203BCD4, 0, 12, 12, RGB(16, 29, 24));
            gSprites[gTasks[taskId].tMonSpriteId(currPokeID)].oam.priority = 1;
            gTasks[taskId].func = Task_Hof_DisplayMon;
        }
        else
        {
            gTasks[taskId].func = Task_Hof_PaletteFadeAndPrintWelcomeText;
        }
    }
}

static void Task_Hof_PaletteFadeAndPrintWelcomeText(u8 taskId)
{
    u16 i;

    BeginNormalPaletteFade(0xFFFF0000, 0, 0, 0, RGB_BLACK);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gTasks[taskId].tMonSpriteId(i) != 0xFF)
            gSprites[gTasks[taskId].tMonSpriteId(i)].oam.priority = 0;
    }

    HallOfFame_PrintWelcomeText(0, 15);
    PlaySE(SE_DENDOU);
    gTasks[taskId].tFrameCount = 400;
    gTasks[taskId].func = sub_8173DC0;
}

static void sub_8173DC0(u8 taskId)
{
    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
        if ((gTasks[taskId].tFrameCount & 3) == 0 && gTasks[taskId].tFrameCount > 110)
            sub_81751FC();
    }
    else
    {
        u16 i;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (gTasks[taskId].tMonSpriteId(i) != 0xFF)
                gSprites[gTasks[taskId].tMonSpriteId(i)].oam.priority = 1;
        }
        BeginNormalPaletteFade(sUnknown_0203BCD4, 0, 12, 12, RGB(16, 29, 24));
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        CopyWindowToVram(0, 3);
        gTasks[taskId].tFrameCount = 7;
        gTasks[taskId].func = sub_8173EA4;
    }
}

static void sub_8173EA4(u8 taskId)
{
    if (gTasks[taskId].tFrameCount >= 16)
    {
        gTasks[taskId].func = sub_8173EE4;
    }
    else
    {
        gTasks[taskId].tFrameCount++;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tFrameCount * 256);
    }
}

static void sub_8173EE4(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(3);
    gTasks[taskId].tPlayerSpriteID = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId_Debug(gSaveBlock2Ptr->playerGender, TRUE), 1, 120, 72, 6, 0xFFFF);
    AddWindow(&sHof_WindowTemplate);
    LoadWindowGfx(1, gSaveBlock2Ptr->optionsWindowFrameType, 0x21D, 0xD0);
    LoadPalette(stdpal_get(1), 0xE0, 0x20);
    gTasks[taskId].tFrameCount = 120;
    gTasks[taskId].func = Task_Hof_WaitAndPrintPlayerInfo;
}

static void Task_Hof_WaitAndPrintPlayerInfo(u8 taskId)
{
    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
    }
    else if (gSprites[gTasks[taskId].tPlayerSpriteID].pos1.x != 192)
    {
        gSprites[gTasks[taskId].tPlayerSpriteID].pos1.x++;
    }
    else
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        HallOfFame_PrintPlayerInfo(1, 2);
        DrawDialogueFrame(0, 0);
        AddTextPrinterParameterized2(0, 1, gText_LeagueChamp, 0, NULL, 2, 1, 3);
        CopyWindowToVram(0, 3);
        gTasks[taskId].func = Task_Hof_ExitOnKeyPressed;
    }
}

static void Task_Hof_ExitOnKeyPressed(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        FadeOutBGM(4);
        gTasks[taskId].func = Task_Hof_HandlePaletteOnExit;
    }
}

static void Task_Hof_HandlePaletteOnExit(u8 taskId)
{
    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    BeginNormalPaletteFade(0xFFFFFFFF, 8, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_Hof_HandleExit;
}

static void Task_Hof_HandleExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        s32 i;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            u8 spriteId = gTasks[taskId].tMonSpriteId(i);
            if (spriteId != 0xFF)
            {
                FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
                FreeAndDestroyMonPicSprite(spriteId);
            }
        }

        FreeAndDestroyTrainerPicSprite(gTasks[taskId].tPlayerSpriteID);
        HideBg(0);
        HideBg(1);
        HideBg(3);
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        ResetBgsAndClearDma3BusyFlags(0);
        DestroyTask(taskId);

        if (sHofGfxPtr != NULL)
            FREE_AND_SET_NULL(sHofGfxPtr);
        if (sHofMonPtr != NULL)
            FREE_AND_SET_NULL(sHofMonPtr);

        SetCallback2AfterHallOfFameDisplay();
    }
}

static void SetCallback2AfterHallOfFameDisplay(void)
{
    SetMainCallback2(sub_8175620);
}

#undef tDontSaveData
#undef tDisplayedPoke
#undef tMonNumber
#undef tFrameCount
#undef tPlayerSpriteID
#undef tMonSpriteId

#define tCurrTeamNo     data[0]
#define tCurrPageNo     data[1]
#define tCurrMonId      data[2]
#define tMonNo          data[4]
#define tMonSpriteId(i) data[i + 5]

void CB2_DoHallOfFamePC(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        ClearVramOamPltt_LoadHofPal();
        sHofGfxPtr = AllocZeroed(sizeof(*sHofGfxPtr));
        gMain.state = 1;
        break;
    case 1:
        sub_8174F70();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        sub_8174FAC();
        gMain.state++;
        break;
    case 3:
        if (!sub_8175024())
        {
            struct HallofFameTeam *fameTeam = (struct HallofFameTeam*)(gDecompressionBuffer);
            fameTeam->mon[0] = sDummyFameMon;
            sub_80F9BCC(0, 0, 0);
            SetVBlankCallback(VBlankCB_HallOfFame);
            gMain.state++;
        }
        break;
    case 4:
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        if (!sub_80F9C1C())
            gMain.state++;
        break;
    case 5:
        {
            u8 taskId, i;

            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 7));
            SetGpuReg(REG_OFFSET_BLDY, 0);
            taskId = CreateTask(Task_HofPC_CopySaveData, 0);

            for (i = 0; i < PARTY_SIZE; i++)
            {
                gTasks[taskId].tMonSpriteId(i) = 0xFF;
            }

            sHofMonPtr = AllocZeroed(0x2000);
            SetMainCallback2(CB2_HallOfFame);
        }
        break;
    }
}

static void Task_HofPC_CopySaveData(u8 taskId)
{
    sub_81980F0(0, 0x1E, 0, 0xC, 0x226);
    if (Save_LoadGameData(3) != 1)
    {
        gTasks[taskId].func = Task_HofPC_PrintDataIsCorrupted;
    }
    else
    {
        u16 i;
        struct HallofFameTeam* savedTeams;

        CpuCopy16(gDecompressionBuffer, sHofMonPtr, 0x2000);
        savedTeams = sHofMonPtr;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, savedTeams++)
        {
            if (savedTeams->mon[0].species == SPECIES_NONE)
                break;
        }

        if (i < HALL_OF_FAME_MAX_TEAMS)
            gTasks[taskId].tCurrTeamNo = i - 1;
        else
            gTasks[taskId].tCurrTeamNo = HALL_OF_FAME_MAX_TEAMS - 1;

        gTasks[taskId].tCurrPageNo = GetGameStat(GAME_STAT_ENTERED_HOF);

        gTasks[taskId].func = Task_HofPC_DrawSpritesPrintText;
    }
}

static void Task_HofPC_DrawSpritesPrintText(u8 taskId)
{
    struct HallofFameTeam* savedTeams = sHofMonPtr;
    struct HallofFameMon* currMon;
    u16 i;

    for (i = 0; i < gTasks[taskId].tCurrTeamNo; i++)
        savedTeams++;

    currMon = &savedTeams->mon[0];
    sUnknown_0203BCD4 = 0;
    gTasks[taskId].tCurrMonId = 0;
    gTasks[taskId].tMonNo = 0;

    for (i = 0; i < PARTY_SIZE; i++, currMon++)
    {
        if (currMon->species != 0)
            gTasks[taskId].tMonNo++;
    }

    currMon = &savedTeams->mon[0];

    for (i = 0; i < PARTY_SIZE; i++, currMon++)
    {
        if (currMon->species != 0)
        {
            u16 spriteId;
            s16 posX, posY;

            if (gTasks[taskId].tMonNo > 3)
            {
                posX = sHallOfFame_MonFullTeamPositions[i][2];
                posY = sHallOfFame_MonFullTeamPositions[i][3];
            }
            else
            {
                posX = sHallOfFame_MonHalfTeamPositions[i][2];
                posY = sHallOfFame_MonHalfTeamPositions[i][3];
            }

            if (currMon->species == SPECIES_EGG)
                posY += 10;

            spriteId = CreateMonPicSprite_HandleDeoxys(currMon->species, currMon->tid, currMon->personality, 1, posX, posY, i, 0xFFFF);
            gSprites[spriteId].oam.priority = 1;
            gTasks[taskId].tMonSpriteId(i) = spriteId;
        }
        else
        {
            gTasks[taskId].tMonSpriteId(i) = 0xFF;
        }
    }

    BlendPalettes(0xFFFF0000, 0xC, RGB(16, 29, 24));

    ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].tCurrPageNo, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_HOFNumber);

    if (gTasks[taskId].tCurrTeamNo <= 0)
        sub_8198204(gStringVar4, gText_PickCancel, 0, 0, TRUE);
    else
        sub_8198204(gStringVar4, gText_PickNextCancel, 0, 0, TRUE);

    gTasks[taskId].func = Task_HofPC_PrintMonInfo;
}

static void Task_HofPC_PrintMonInfo(u8 taskId)
{
    struct HallofFameTeam* savedTeams = sHofMonPtr;
    struct HallofFameMon* currMon;
    u16 i;
    u16 currMonID;

    for (i = 0; i < gTasks[taskId].tCurrTeamNo; i++)
        savedTeams++;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 spriteId = gTasks[taskId].tMonSpriteId(i);
        if (spriteId != 0xFF)
            gSprites[spriteId].oam.priority = 1;
    }

    currMonID = gTasks[taskId].tMonSpriteId(gTasks[taskId].tCurrMonId);
    gSprites[currMonID].oam.priority = 0;
    sUnknown_0203BCD4 = (0x10000 << gSprites[currMonID].oam.paletteNum) ^ 0xFFFF0000;
    BlendPalettesUnfaded(sUnknown_0203BCD4, 0xC, RGB(16, 29, 24));

    currMon = &savedTeams->mon[gTasks[taskId].tCurrMonId];
    if (currMon->species != SPECIES_EGG)
    {
        StopCryAndClearCrySongs();
        PlayCry1(currMon->species, 0);
    }
    HallOfFame_PrintMonInfo(currMon, 0, 14);

    gTasks[taskId].func = Task_HofPC_HandleInput;
}

static void Task_HofPC_HandleInput(u8 taskId)
{
    u16 i;

    if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskId].tCurrTeamNo != 0) // prepare another team to view
        {
            gTasks[taskId].tCurrTeamNo--;
            for (i = 0; i < 6; i++)
            {
                u8 spriteId = gTasks[taskId].tMonSpriteId(i);
                if (spriteId != 0xFF)
                {
                    FreeAndDestroyMonPicSprite(spriteId);
                    gTasks[taskId].tMonSpriteId(i) = 0xFF;
                }
            }
            if (gTasks[taskId].tCurrPageNo != 0)
                gTasks[taskId].tCurrPageNo--;
            gTasks[taskId].func = Task_HofPC_DrawSpritesPrintText;
        }
        else // no more teams to view, turn off hall of fame PC
        {
            if (IsCryPlayingOrClearCrySongs())
            {
                StopCryAndClearCrySongs();
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
            }
            gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
        }
    }
    else if (gMain.newKeys & B_BUTTON) // turn off hall of fame PC
    {
        if (IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        }
        gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
    }
    else if (gMain.newKeys & DPAD_UP && gTasks[taskId].tCurrMonId != 0) // change mon -1
    {
        gTasks[taskId].tCurrMonId--;
        gTasks[taskId].func = Task_HofPC_PrintMonInfo;
    }
    else if (gMain.newKeys & DPAD_DOWN && gTasks[taskId].tCurrMonId < gTasks[taskId].tMonNo - 1) // change mon +1
    {
        gTasks[taskId].tCurrMonId++;
        gTasks[taskId].func = Task_HofPC_PrintMonInfo;
    }
}

static void Task_HofPC_HandlePaletteOnExit(u8 taskId)
{
    struct HallofFameTeam* fameTeam;

    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    fameTeam = (struct HallofFameTeam*)(gDecompressionBuffer);
    fameTeam->mon[0] = sDummyFameMon;
    sub_80F9BF4(0, 0, 0);
    gTasks[taskId].func = Task_HofPC_HandleExit;
}

static void Task_HofPC_HandleExit(u8 taskId)
{
    if (!sub_80F9C30())
    {
        u8 i;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 spriteId = gTasks[taskId].tMonSpriteId(i);
            if (spriteId != 0xFF)
            {
                FreeAndDestroyMonPicSprite(spriteId);
                gTasks[taskId].tMonSpriteId(i) = 0xFF;
            }
        }

        HideBg(0);
        HideBg(1);
        HideBg(3);
        sub_8198314();
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        ResetBgsAndClearDma3BusyFlags(0);
        DestroyTask(taskId);

        if (sHofGfxPtr != NULL)
            FREE_AND_SET_NULL(sHofGfxPtr);
        if (sHofMonPtr != NULL)
            FREE_AND_SET_NULL(sHofMonPtr);

        ReturnFromHallOfFamePC();
    }
}

static void Task_HofPC_PrintDataIsCorrupted(u8 taskId)
{
    sub_8198180(gText_UnkCtrlF800Exit, 8, TRUE);
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized2(0, 1, gText_HOFCorrupted, 0, NULL, 2, 1, 3);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_HofPC_ExitOnButtonPress;
}

static void Task_HofPC_ExitOnButtonPress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
        gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
}

#undef tCurrTeamNo
#undef tCurrPageNo
#undef tCurrMonId
#undef tMonNo
#undef tMonSpriteId

static void HallOfFame_PrintWelcomeText(u8 unusedPossiblyWindowId, u8 unused2)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
    AddTextPrinterParameterized3(0, 1, GetStringCenterAlignXOffset(1, gText_WelcomeToHOF, 0xD0), 1, sUnknown_085E5388, 0, gText_WelcomeToHOF);
    CopyWindowToVram(0, 3);
}

static void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 unused1, u8 unused2)
{
    u8 text[30];
    u8 *stringPtr;
    s32 dexNumber;
    s32 width;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);

    // dex number
    if (currMon->species != SPECIES_EGG)
    {
        stringPtr = StringCopy(text, gText_Number);
        dexNumber = SpeciesToPokedexNum(currMon->species);
        if (dexNumber != 0xFFFF)
        {
            stringPtr[0] = (dexNumber / 100) + CHAR_0;
            stringPtr++;
            dexNumber %= 100;
            stringPtr[0] = (dexNumber / 10) + CHAR_0;
            stringPtr++;
            stringPtr[0] = (dexNumber % 10) + CHAR_0;
            stringPtr++;
        }
        else
        {
            *(stringPtr)++ = CHAR_QUESTION_MARK;
            *(stringPtr)++ = CHAR_QUESTION_MARK;
            *(stringPtr)++ = CHAR_QUESTION_MARK;
        }
        stringPtr[0] = EOS;
        AddTextPrinterParameterized3(0, 1, 0x10, 1, sUnknown_085E5388, -1, text);
    }

    // nick, species names, gender and level
    memcpy(text, currMon->nick, POKEMON_NAME_LENGTH);
    text[POKEMON_NAME_LENGTH] = EOS;
    if (currMon->species == SPECIES_EGG)
    {
        width = GetStringCenterAlignXOffset(1, text, 0xD0);
        AddTextPrinterParameterized3(0, 1, width, 1, sUnknown_085E5388, -1, text);
        CopyWindowToVram(0, 3);
    }
    else
    {
        width = GetStringRightAlignXOffset(1, text, 0x80);
        AddTextPrinterParameterized3(0, 1, width, 1, sUnknown_085E5388, -1, text);

        text[0] = CHAR_SLASH;
        stringPtr = StringCopy(text + 1, gSpeciesNames[currMon->species]);

        if (currMon->species != SPECIES_NIDORAN_M && currMon->species != SPECIES_NIDORAN_F)
        {
            switch (GetGenderFromSpeciesAndPersonality(currMon->species, currMon->personality))
            {
            case MON_MALE:
                stringPtr[0] = CHAR_MALE;
                stringPtr++;
                break;
            case MON_FEMALE:
                stringPtr[0] = CHAR_FEMALE;
                stringPtr++;
                break;
            }
        }

        stringPtr[0] = EOS;
        AddTextPrinterParameterized3(0, 1, 0x80, 1, sUnknown_085E5388, -1, text);

        stringPtr = StringCopy(text, gText_Level);
        ConvertIntToDecimalStringN(stringPtr, currMon->lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
        AddTextPrinterParameterized3(0, 1, 0x24, 0x11, sUnknown_085E5388, -1, text);

        stringPtr = StringCopy(text, gText_IDNumber);
        ConvertIntToDecimalStringN(stringPtr, (u16)(currMon->tid), STR_CONV_MODE_LEADING_ZEROS, 5);
        AddTextPrinterParameterized3(0, 1, 0x68, 0x11, sUnknown_085E5388, -1, text);

        CopyWindowToVram(0, 3);
    }
}

static void HallOfFame_PrintPlayerInfo(u8 unused1, u8 unused2)
{
    u8 text[20];
    u32 width;
    u16 trainerId;

    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    PutWindowTilemap(1);
    DrawStdFrameWithCustomTileAndPalette(1, FALSE, 0x21D, 0xD);
    AddTextPrinterParameterized3(1, 1, 0, 1, sUnknown_085E538C, -1, gText_Name);

    width = GetStringRightAlignXOffset(1, gSaveBlock2Ptr->playerName, 0x70);
    AddTextPrinterParameterized3(1, 1, width, 1, sUnknown_085E538C, -1, gSaveBlock2Ptr->playerName);

    trainerId = (gSaveBlock2Ptr->playerTrainerId[0]) | (gSaveBlock2Ptr->playerTrainerId[1] << 8);
    AddTextPrinterParameterized3(1, 1, 0, 0x11, sUnknown_085E538C, 0, gText_IDNumber);
    text[0] = (trainerId % 100000) / 10000 + CHAR_0;
    text[1] = (trainerId % 10000) / 1000 + CHAR_0;
    text[2] = (trainerId % 1000) / 100 + CHAR_0;
    text[3] = (trainerId % 100) / 10 + CHAR_0;
    text[4] = (trainerId % 10) / 1 + CHAR_0;
    text[5] = EOS;
    width = GetStringRightAlignXOffset(1, text, 0x70);
    AddTextPrinterParameterized3(1, 1, width, 0x11, sUnknown_085E538C, -1, text);

    AddTextPrinterParameterized3(1, 1, 0, 0x21, sUnknown_085E538C, -1, gText_MainMenuTime);
    text[0] = (gSaveBlock2Ptr->playTimeHours / 100) + CHAR_0;
    text[1] = (gSaveBlock2Ptr->playTimeHours % 100) / 10 + CHAR_0;
    text[2] = (gSaveBlock2Ptr->playTimeHours % 10) + CHAR_0;

    if (text[0] == CHAR_0)
        text[0] = CHAR_SPACE;
    if (text[0] == CHAR_SPACE && text[1] == CHAR_0)
        text[8] = CHAR_SPACE;

    text[3] = CHAR_COLON;
    text[4] = (gSaveBlock2Ptr->playTimeMinutes % 100) / 10 + CHAR_0;
    text[5] = (gSaveBlock2Ptr->playTimeMinutes % 10) + CHAR_0;
    text[6] = EOS;

    width = GetStringRightAlignXOffset(1, text, 0x70);
    AddTextPrinterParameterized3(1, 1, width, 0x21, sUnknown_085E538C, -1, text);

    CopyWindowToVram(1, 3);
}

static void ClearVramOamPltt_LoadHofPal(void)
{
    u32 vramOffset, oamOffset, plttOffset;
    u32 vramSize, oamSize, plttSize;

    vramOffset = (VRAM);
    vramSize = VRAM_SIZE;
    while (TRUE)
    {
        DmaFill16(3, 0, vramOffset, 0x1000);
        vramOffset += 0x1000;
        vramSize -= 0x1000;
        if (vramSize <= 0x1000)
        {
            DmaFill16(3, 0, vramOffset, vramSize);
            break;
        }
    }

    oamOffset = OAM;
    oamSize = OAM_SIZE;
    DmaFill32(3, 0, oamOffset, oamSize);

    plttOffset = PLTT;
    plttSize = PLTT_SIZE;
    DmaFill16(3, 0, plttOffset, plttSize);

    ResetPaletteFade();
    LoadPalette(sHallOfFame_Pal, 0, 0x20);
}

static void sub_8174F70(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    reset_temp_tile_data_buffers();
    ResetAllPicSprites();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 8;
    LoadCompressedSpriteSheet(sHallOfFame_ConfettiSpriteSheet);
    LoadCompressedSpritePalette(sHallOfFame_ConfettiSpritePalette);
}

static void sub_8174FAC(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sHof_BgTemplates, ARRAY_COUNT(sHof_BgTemplates));
    SetBgTilemapBuffer(1, sHofGfxPtr->tilemap1);
    SetBgTilemapBuffer(3, sHofGfxPtr->tilemap2);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

static bool8 sub_8175024(void)
{
    switch (sHofGfxPtr->state)
    {
    case 0:
        decompress_and_copy_tile_data_to_vram(1, sHallOfFame_Gfx, 0, 0, 0);
        break;
    case 1:
        if (free_temp_tile_data_buffers_if_possible())
            return TRUE;
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(1, 1, 0, 0, 0x20, 2);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 3, 0x20, 0xB);
        FillBgTilemapBufferRect_Palette0(1, 1, 0, 0xE, 0x20, 6);
        FillBgTilemapBufferRect_Palette0(3, 2, 0, 0, 0x20, 0x20);

        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(3);
        break;
    case 3:
        InitStandardTextBoxWindows();
        sub_8197200();
        break;
    case 4:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        sHofGfxPtr->state = 0;
        return FALSE;
    }

    sHofGfxPtr->state++;
    return TRUE;
}

static void SpriteCB_GetOnScreenAndAnimate(struct Sprite *sprite)
{
    if (sprite->pos1.x != sprite->tDestinationX
        || sprite->pos1.y != sprite->tDestinationY)
    {
        if (sprite->pos1.x < sprite->tDestinationX)
            sprite->pos1.x += 15;
        if (sprite->pos1.x > sprite->tDestinationX)
            sprite->pos1.x -= 15;

        if (sprite->pos1.y < sprite->tDestinationY)
            sprite->pos1.y += 10;
        if (sprite->pos1.y > sprite->tDestinationY)
            sprite->pos1.y -= 10;
    }
    else
    {
        s16 species = sprite->tSpecies;

        if (species == SPECIES_EGG)
            DoMonFrontSpriteAnimation(sprite, species, TRUE, 3);
        else
            DoMonFrontSpriteAnimation(sprite, species, FALSE, 3);
    }
}

#undef tDestinationX
#undef tDestinationY
#undef tSpecies

static void sub_81751A4(struct Sprite* sprite)
{
    if (sprite->pos2.y > 120)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 rand;
        u8 tableID;

        sprite->pos2.y++;
        sprite->pos2.y += sprite->data[1];

        tableID = sprite->data[0];
        rand = (Random() % 4) + 8;
        sprite->pos2.x = rand * gSineTable[tableID] / 256;

        sprite->data[0] += 4;
    }
}

static bool8 sub_81751FC(void)
{
    u8 spriteID;
    struct Sprite* sprite;

    s16 posX = Random() % 240;
    s16 posY = -(Random() % 8);

    spriteID = CreateSprite(&sSpriteTemplate_85E54D0, posX, posY, 0);
    sprite = &gSprites[spriteID];

    StartSpriteAnim(sprite, Random() % 17);

    if (Random() & 3)
        sprite->data[1] = 0;
    else
        sprite->data[1] = 1;

    return FALSE;
}

void sub_8175280(void)
{
    u8 taskId;

    gSpecialVar_0x8004 = 180;
    taskId = CreateTask(sub_8175364, 0);
    if (taskId != 0xFF)
    {
        gTasks[taskId].data[1] = gSpecialVar_0x8004;
        gSpecialVar_0x8005 = taskId;
    }
}

static void sub_81752C0(void)
{
    u8 taskId;

    if ((taskId = FindTaskIdByFunc(sub_8175364)) != 0xFF)
        DestroyTask(taskId);

    sub_8152254();
    FreeSpriteTilesByTag(0x3E9);
    FreeSpritePaletteByTag(0x3E9);
}

static void sub_81752F4(struct UnkStruct_81520A8 *structPtr)
{
    if (structPtr->yDelta > 110)
    {
        gTasks[structPtr->data[7]].data[15]--;
        sub_81525D0(structPtr->id);
    }
    else
    {
        u8 var;
        s32 rand;

        structPtr->yDelta++;
        structPtr->yDelta += structPtr->data[1];

        var = structPtr->data[0];
        rand = Random();
        rand &= 3;
        rand += 8;
        structPtr->xDelta = (rand) * ((gSineTable[var])) / 256;

        structPtr->data[0] += 4;
    }
}

static void sub_8175364(u8 taskId)
{
    u32 var = 0;
    u16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        if (!sub_81521C0(0x40))
        {
            DestroyTask(taskId);
            gSpecialVar_0x8004 = var;
            gSpecialVar_0x8005 = 0xFFFF;
        }
        LoadCompressedSpriteSheet(sHallOfFame_ConfettiSpriteSheet);
        LoadCompressedSpritePalette(sHallOfFame_ConfettiSpritePalette);
        data[0]++;
        break;
    case 1:
        if (data[1] != 0 && data[1] % 3 == 0)
        {
            var = sub_81524C4(&sOamData_85E53FC, 0x3E9, 0x3E9, Random() % 240, -(Random() % 8), Random() % 0x11, var);
            if (var != 0xFF)
            {
                sub_8152438(var, sub_81752F4);
                if ((Random() & 3) == 0)
                    sub_8152474(var, 1, 1);
                sub_8152474(var, 7, taskId);
                data[15]++;
            }
        }
        sub_81522D4();
        if (data[1] != 0)
            data[1]--;
        else if (data[15] == 0)
            data[0] = 0xFF;
        break;
    case 0xFF:
        sub_81752C0();
        gSpecialVar_0x8004 = var;
        gSpecialVar_0x8005 = 0xFFFF;
        break;
    }
}
