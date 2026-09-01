#include "global.h"
#include "bg.h"
#include "credits_frlg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "fldeff_misc.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "hall_of_fame.h"
#include "hall_of_fame_frlg.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pc_screen_effect.h"
#include "random.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "constants/maps.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define HALL_OF_FAME_MAX_TEAMS 50
#define HALL_OF_FAME_BG_PAL    RGB(22, 24, 29)

STATIC_ASSERT(sizeof(struct HallofFameTeam) * HALL_OF_FAME_MAX_TEAMS <= SECTOR_DATA_SIZE * NUM_HOF_SECTORS, HallOfFameFreeSpace);

struct HofGfx
{
    u16 state;
    u8 field_2[4];
    u8 tilemap1[0x1000];
    u8 tilemap2[0x1000];
};

static EWRAM_DATA u32 sSelectedPaletteIndices = 0;
static EWRAM_DATA struct HallofFameTeam * sHofMonPtr = NULL;
static EWRAM_DATA struct HofGfx * sHofGfxPtr = NULL;

static void Task_Hof_InitMonData(u8 taskId);
static void Task_Hof_InitTeamSaveData(u8 taskId);
static void Task_Hof_TrySaveData(u8 taskId);
static void Task_Hof_DelayAfterSave(u8 taskId);
static void Task_Hof_StartDisplayingMons(u8 taskId);
static void Task_Hof_DisplayMon(u8 taskId);
static void Task_Hof_PlayMonCryAndPrintInfo(u8 taskId);
static void Task_Hof_TryDisplayAnotherMon(u8 taskId);
static void Task_Hof_PaletteFadeAndPrintWelcomeText(u8 taskId);
static void Task_Hof_ApplauseAndConfetti(u8 taskId);
static void Task_Hof_WaitBorderFadeAway(u8 taskId);
static void Task_Hof_SpawnPlayerPic(u8 taskId);
static void Task_Hof_WaitAndPrintPlayerInfo(u8 taskId);
static void Task_Hof_ExitOnKeyPressed(u8 taskId);
static void Task_Hof_HandlePaletteOnExit(u8 taskId);
static void Task_Hof_HandleExit(u8 taskId);
static void SetWarpsToRollCredits(void);
static void Task_HofPC_CopySaveData(u8 taskId);
static void Task_HofPC_DrawSpritesPrintText(u8 taskId);
static void Task_HofPC_PrintMonInfo(u8 taskId);
static void Task_HofPC_HandleInput(u8 taskId);
static void Task_HofPC_HandlePaletteOnExit(u8 taskId);
static void Task_HofPC_HandleExit(u8 taskId);
static void Task_HofPC_PrintDataIsCorrupted(u8 taskId);
static void Task_HofPC_ExitOnButtonPress(u8 taskId);
static void HallOfFame_PrintWelcomeText(u8 a0, u8 a1);
static void HallOfFame_PrintMonInfo(struct HallofFameMon * hofMon, u8 a1, u8 a2);
static void HallOfFame_PrintPlayerInfo(u8 a0, u8 a1);
static void ClearVramOamPltt_LoadHofPal(void);
static void HofInit_ResetGpuBuffersAndLoadConfettiGfx(void);
static void Hof_InitBgs(void);
static bool8 DrawHofBackground(void);
static void SpriteCB_GetOnScreen(struct Sprite *sprite);
static void SpriteCB_Confetti(struct Sprite *sprite);
static bool8 Hof_SpawnConfetti(void);

static const struct BgTemplate sHof_BgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000
    }
};

static const struct WindowTemplate sWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 2,
    .width = 17,
    .height = 6,
    .paletteNum = 13,
    .baseBlock = 0x001
};

static const u8 sTextColors[][4] = {
    { 0, 1, 2 },
    { 0, 2, 3 },
    { 4, 5, 0 }
};

static const struct CompressedSpriteSheet sHallOfFame_ConfettiSpriteSheet[] = {
    {gConfetti_Gfx, 0x220, 1001},
    {}
};

static const struct SpritePalette sHallOfFame_ConfettiSpritePalette[] = {
    {gConfetti_Pal, 1001},
    {}
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

static const struct OamData sOamData_Confetti = {
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8)
};

static const union AnimCmd sAnimCmd_Frame00[] = {
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame01[] = {
    ANIMCMD_FRAME( 1, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame02[] = {
    ANIMCMD_FRAME( 2, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame03[] = {
    ANIMCMD_FRAME( 3, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame04[] = {
    ANIMCMD_FRAME( 4, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame05[] = {
    ANIMCMD_FRAME( 5, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame06[] = {
    ANIMCMD_FRAME( 6, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame07[] = {
    ANIMCMD_FRAME( 7, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame08[] = {
    ANIMCMD_FRAME( 8, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame09[] = {
    ANIMCMD_FRAME( 9, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame10[] = {
    ANIMCMD_FRAME(10, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame11[] = {
    ANIMCMD_FRAME(11, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame12[] = {
    ANIMCMD_FRAME(12, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame13[] = {
    ANIMCMD_FRAME(13, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame14[] = {
    ANIMCMD_FRAME(14, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame15[] = {
    ANIMCMD_FRAME(15, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnimCmd_Frame16[] = {
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_Confetti[] = {
    sAnimCmd_Frame00,
    sAnimCmd_Frame01,
    sAnimCmd_Frame02,
    sAnimCmd_Frame03,
    sAnimCmd_Frame04,
    sAnimCmd_Frame05,
    sAnimCmd_Frame06,
    sAnimCmd_Frame07,
    sAnimCmd_Frame08,
    sAnimCmd_Frame09,
    sAnimCmd_Frame10,
    sAnimCmd_Frame11,
    sAnimCmd_Frame12,
    sAnimCmd_Frame13,
    sAnimCmd_Frame14,
    sAnimCmd_Frame15,
    sAnimCmd_Frame16
};

static const struct SpriteTemplate sSpriteTemplate_Confetti = {
    .tileTag = 1001,
    .paletteTag = 1001,
    .oam = &sOamData_Confetti,
    .anims = sSpriteAnimTable_Confetti,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Confetti
};

static const u16 sHallOfFame_Pal[] = INCGFX_U16("graphics/misc/hall_of_fame.png", ".gbapal");
static const u32 sHallOfFame_Gfx[] = INCGFX_U32("graphics/misc/hall_of_fame.png", ".4bpp.smol");

static const struct HallofFameMon sDummyHofMon = {
    .tid = 0x03EA03EA, // (u16[]){1002, 1002} corrupted sprite template?
    .personality = 0,
    .species = SPECIES_NONE,
    .lvl = 0,
    .nickname = __("          "),
    .isShiny = FALSE,
};

static const u8 sUnused[] = {2, 1, 3, 6, 4, 5};

static void VBlankCB_HofIdle(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_HofIdle(void)
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
        sHofGfxPtr = AllocZeroed(sizeof(struct HofGfx));
        gMain.state = 1;
        break;
    case 1:
        HofInit_ResetGpuBuffersAndLoadConfettiGfx();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 7));
        SetGpuReg(REG_OFFSET_BLDY, 0);
        Hof_InitBgs();
        sHofGfxPtr->state = 0;
        gMain.state++;
        break;
    case 3:
        if (!DrawHofBackground())
        {
            SetVBlankCallback(VBlankCB_HofIdle);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gMain.state++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_HofIdle);
            PlayBGM(MUS_HALL_OF_FAME);
            return FALSE;
        }
        break;
    }
    return TRUE;
}

static void AllocateHoFTeams(void)
{
    sHofMonPtr = AllocZeroed(sizeof(*sHofMonPtr));
    gHoFSaveBuffer = Alloc(SECTOR_SIZE * NUM_HOF_SECTORS);
}

void CB2_DoHallOfFameScreenFrlg(void)
{
    if (!InitHallOfFameScreen())
    {
        u8 taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].data[0] = FALSE;
        AllocateHoFTeams();
    }
}

void CB2_DoHallOfFameScreenDontSaveDataFrlg(void)
{
    u8 taskId;
    if (!InitHallOfFameScreen())
    {
        taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].data[0] = TRUE;
        AllocateHoFTeams();
    }
}

static void Task_Hof_InitMonData(u8 taskId)
{
    u16 i;
    u16 j;
    u8 nick[POKEMON_NAME_LENGTH + 1];

    gTasks[taskId].data[2] = 0;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            sHofMonPtr[0].mon[i].species = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG);
            sHofMonPtr[0].mon[i].tid = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_OT_ID);
            sHofMonPtr[0].mon[i].personality = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_PERSONALITY);
            sHofMonPtr[0].mon[i].lvl = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_LEVEL);
            sHofMonPtr[0].mon[i].isShiny = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_IS_SHINY);
            GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_NICKNAME, nick);
            for (j = 0; j < POKEMON_NAME_LENGTH; j++)
                sHofMonPtr[0].mon[i].nickname[j] = nick[j];
            gTasks[taskId].data[2]++;
        }
        else
        {
            sHofMonPtr[0].mon[i].species = SPECIES_NONE;
            sHofMonPtr[0].mon[i].tid = 0;
            sHofMonPtr[0].mon[i].personality = 0;
            sHofMonPtr[0].mon[i].lvl = 0;
            sHofMonPtr[0].mon[i].isShiny = FALSE;
            sHofMonPtr[0].mon[i].nickname[0] = EOS;
        }
    }
    sSelectedPaletteIndices = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[4] = 0xFF;
    for (i = 0; i < 6; i++)
        gTasks[taskId].data[i + 5] = 0xFF;
    if (gTasks[taskId].data[0])
        gTasks[taskId].func = Task_Hof_StartDisplayingMons;
    else
        gTasks[taskId].func = Task_Hof_InitTeamSaveData;
}

static void Task_Hof_InitTeamSaveData(u8 taskId)
{
    u16 i;
    struct HallofFameTeam *lastSavedTeam = gHoFSaveBuffer;

    if (!gHasHallOfFameRecords)
    {
        memset(gHoFSaveBuffer, 0, SECTOR_SIZE * NUM_HOF_SECTORS);
    }
    else
    {
        if (LoadGameSave(SAVE_HALL_OF_FAME) != SAVE_STATUS_OK)
            memset(gHoFSaveBuffer, 0, SECTOR_SIZE * NUM_HOF_SECTORS);
    }

    for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, lastSavedTeam++)
    {
        if (lastSavedTeam->mon[0].species == SPECIES_NONE)
            break;
    }
    if (i >= HALL_OF_FAME_MAX_TEAMS)
    {
        struct HallofFameTeam *afterTeam = gHoFSaveBuffer;
        struct HallofFameTeam *beforeTeam = gHoFSaveBuffer;
        afterTeam++;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS - 1; i++, beforeTeam++, afterTeam++)
        {
            *beforeTeam = *afterTeam;
        }
        lastSavedTeam--;
    }
    *lastSavedTeam = *sHofMonPtr;

    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized2(0, FONT_NORMAL, gText_SavingDontTurnOffPower, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    CopyWindowToVram(0, COPYWIN_FULL);
    gTasks[taskId].func = Task_Hof_TrySaveData;
}

static void FreeAllHoFMem(void)
{
    TRY_FREE_AND_SET_NULL(sHofGfxPtr);
    TRY_FREE_AND_SET_NULL(sHofMonPtr);
    TRY_FREE_AND_SET_NULL(gHoFSaveBuffer);
}

static void Task_Hof_TrySaveData(u8 taskId)
{
    gGameContinueCallback = CB2_DoHallOfFameScreenDontSaveDataFrlg;
    TrySavingData(SAVE_HALL_OF_FAME);
    PlaySE(SE_SAVE);
    gTasks[taskId].func = Task_Hof_DelayAfterSave;
    gTasks[taskId].data[3] = 32;
}

static void Task_Hof_DelayAfterSave(u8 taskId)
{
    if (gTasks[taskId].data[3] != 0)
        gTasks[taskId].data[3]--;
    else
        gTasks[taskId].func = Task_Hof_StartDisplayingMons;
}

static void Task_Hof_StartDisplayingMons(u8 taskId)
{
    gTasks[taskId].func = Task_Hof_DisplayMon;
}

static void Task_Hof_DisplayMon(u8 taskId)
{
    u8 spriteId;
    s16 srcX;
    s16 srcY;
    s16 dstX;
    s16 dstY;

    u16 currMonId = gTasks[taskId].data[1];
    struct HallofFameMon* currMon = &sHofMonPtr[0].mon[currMonId];


    if (gTasks[taskId].data[2] > 3)
    {
        srcX = sHallOfFame_MonFullTeamPositions[currMonId][0];
        srcY = sHallOfFame_MonFullTeamPositions[currMonId][1];
        dstX = sHallOfFame_MonFullTeamPositions[currMonId][2];
        dstY = sHallOfFame_MonFullTeamPositions[currMonId][3];
    }
    else
    {
        srcX = sHallOfFame_MonHalfTeamPositions[currMonId][0];
        srcY = sHallOfFame_MonHalfTeamPositions[currMonId][1];
        dstX = sHallOfFame_MonHalfTeamPositions[currMonId][2];
        dstY = sHallOfFame_MonHalfTeamPositions[currMonId][3];
    }

    spriteId = CreateMonPicSprite(currMon->species, currMon->isShiny, currMon->personality, 1, srcX, srcY, currMonId, 0xFFFF);
    gSprites[spriteId].data[1] = dstX;
    gSprites[spriteId].data[2] = dstY;
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].callback = SpriteCB_GetOnScreen;
    gTasks[taskId].data[5 + currMonId] = spriteId;
    ClearDialogWindowAndFrame(0, TRUE);
    gTasks[taskId].func = Task_Hof_PlayMonCryAndPrintInfo;
}

static void Task_Hof_PlayMonCryAndPrintInfo(u8 taskId)
{
    u16 currMonId = gTasks[taskId].data[1];
    struct HallofFameMon* currMon = &sHofMonPtr[0].mon[currMonId];
    if (gSprites[gTasks[taskId].data[5 + currMonId]].data[0])
    {
        if (currMon->species != SPECIES_EGG)
            PlayCry_Normal(currMon->species, 0);
        HallOfFame_PrintMonInfo(currMon, 0, 14);
        gTasks[taskId].data[3] = 120;
        gTasks[taskId].func = Task_Hof_TryDisplayAnotherMon;
    }
}

static void Task_Hof_TryDisplayAnotherMon(u8 taskId)
{
    u16 currPokeId = gTasks[taskId].data[1];
    struct HallofFameMon* currMon = &sHofMonPtr[0].mon[currPokeId];

    if (gTasks[taskId].data[3] != 0)
    {
        gTasks[taskId].data[3]--;
    }
    else
    {
        sSelectedPaletteIndices |= (0x10000 << gSprites[gTasks[taskId].data[5 + currPokeId]].oam.paletteNum);
        if (gTasks[taskId].data[1] < PARTY_SIZE - 1 && currMon[1].species != SPECIES_NONE) // there is another Pokémon to display
        {
            gTasks[taskId].data[1]++;
            BeginNormalPaletteFade(sSelectedPaletteIndices, 0, 12, 12, HALL_OF_FAME_BG_PAL);
            gSprites[gTasks[taskId].data[5 + currPokeId]].oam.priority = 1;
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

    BeginNormalPaletteFade(PALETTES_OBJECTS, 0, 0, 0, RGB_BLACK);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gTasks[taskId].data[5 + i] != 0xFF)
            gSprites[gTasks[taskId].data[5 + i]].oam.priority = 0;
    }

    HallOfFame_PrintWelcomeText(0, 15);
    PlaySE(SE_APPLAUSE);
    gTasks[taskId].data[3] = 400;
    gTasks[taskId].func = Task_Hof_ApplauseAndConfetti;
}

static void Task_Hof_ApplauseAndConfetti(u8 taskId)
{
    if (gTasks[taskId].data[3] != 0)
    {
        gTasks[taskId].data[3]--;
        if ((gTasks[taskId].data[3] & 3) == 0 && gTasks[taskId].data[3] > 110)
            Hof_SpawnConfetti();
    }
    else
    {
        u16 i;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (gTasks[taskId].data[5 + i] != 0xFF)
                gSprites[gTasks[taskId].data[5 + i]].oam.priority = 1;
        }
        BeginNormalPaletteFade(sSelectedPaletteIndices, 0, 12, 12, HALL_OF_FAME_BG_PAL);
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        CopyWindowToVram(0, COPYWIN_FULL);
        gTasks[taskId].data[3] = 7;
        gTasks[taskId].func = Task_Hof_WaitBorderFadeAway;
    }
}

static void Task_Hof_WaitBorderFadeAway(u8 taskId)
{
    if (gTasks[taskId].data[3] > 15)
    {
        gTasks[taskId].func = Task_Hof_SpawnPlayerPic;
    }
    else
    {
        gTasks[taskId].data[3]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, 256 * gTasks[taskId].data[3]);
    }
}

static void Task_Hof_SpawnPlayerPic(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(3);
    gTasks[taskId].data[4] = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(gSaveBlock2Ptr->playerGender), TRUE, 0x78, 0x48, 6, 0xFFFF);
    AddWindow(&sWindowTemplate);
    LoadStdWindowGfx(1, 0x21D, BG_PLTT_ID(13));
    gTasks[taskId].data[3] = 120;
    gTasks[taskId].func = Task_Hof_WaitAndPrintPlayerInfo;
}

static void Task_Hof_WaitAndPrintPlayerInfo(u8 taskId)
{
    if (gTasks[taskId].data[3] != 0)
    {
        gTasks[taskId].data[3]--;
    }
    else if (gSprites[gTasks[taskId].data[4]].x != 192)
    {
        gSprites[gTasks[taskId].data[4]].x++;
    }
    else
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        HallOfFame_PrintPlayerInfo(1, 2);
        DrawDialogueFrame(0, 0);
        AddTextPrinterParameterized2(0, FONT_NORMAL, gText_LeagueChamp, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        CopyWindowToVram(0, COPYWIN_FULL);
        gTasks[taskId].func = Task_Hof_ExitOnKeyPressed;
    }
}

static void Task_Hof_ExitOnKeyPressed(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        FadeOutBGM(4);
        gTasks[taskId].func = Task_Hof_HandlePaletteOnExit;
    }
}

static void Task_Hof_HandlePaletteOnExit(u8 taskId)
{
    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, PLTT_SIZE);
    BeginNormalPaletteFade(PALETTES_ALL, 8, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_Hof_HandleExit;
}

static void Task_Hof_HandleExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        s32 i;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            u8 spriteId = gTasks[taskId].data[5 + i];
            if (spriteId != 0xFF)
            {
                FreeAndDestroyMonPicSprite(spriteId);
            }
        }

        FreeAndDestroyTrainerPicSprite(gTasks[taskId].data[4]);
        HideBg(0);
        HideBg(1);
        HideBg(3);
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        ResetBgsAndClearDma3BusyFlags(0);
        DestroyTask(taskId);
        FreeAllHoFMem();

        SetWarpsToRollCredits();
    }
}

static void SetWarpsToRollCredits(void)
{
    VarSet(VAR_MAP_SCENE_INDIGO_PLATEAU_EXTERIOR, 1);
    FlagSet(FLAG_HIDE_MAP_NAME_POPUP);
    gDisableMapMusicChangeOnMapLoad = MUSIC_DISABLE_KEEP;
    SetWarpDestination(MAP_GROUP(MAP_INDIGO_PLATEAU_EXTERIOR), MAP_NUM(MAP_INDIGO_PLATEAU_EXTERIOR), -1, 11, 6);
    DoWarp();
    ResetInitialPlayerAvatarState();
}

void CB2_InitHofPC(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        ClearVramOamPltt_LoadHofPal();
        sHofGfxPtr = AllocZeroed(sizeof(struct HofGfx));
        AllocateHoFTeams();
        gMain.state = 1;
        break;
    case 1:
        HofInit_ResetGpuBuffersAndLoadConfettiGfx();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        Hof_InitBgs();
        gMain.state++;
        break;
    case 3:
        if (!DrawHofBackground())
        {
            ComputerScreenOpenEffect(0, 0, 0);
            SetVBlankCallback(VBlankCB_HofIdle);
            gMain.state++;
        }
        break;
    case 4:
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        if (!IsComputerScreenOpenEffectActive())
            gMain.state++;
        break;
    case 5:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 7));
        SetGpuReg(REG_OFFSET_BLDY, 0);
        CreateTask(Task_HofPC_CopySaveData, 0);
        sHofMonPtr = AllocZeroed(SECTOR_SIZE * NUM_HOF_SECTORS);
        SetMainCallback2(CB2_HofIdle);
        break;
    }
}

static void Task_HofPC_CopySaveData(u8 taskId)
{
    HofPCTopBar_AddWindow(0, 30, 0, 0x0C, 0x226);
    if (LoadGameSave(SAVE_HALL_OF_FAME) != SAVE_STATUS_OK)
    {
        gTasks[taskId].func = Task_HofPC_PrintDataIsCorrupted;
    }
    else
    {
        u16 i;
        struct HallofFameTeam *savedTeams;

        savedTeams = gHoFSaveBuffer;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, savedTeams++)
        {
            if (savedTeams->mon[0].species == SPECIES_NONE)
                break;
        }

        if (i < HALL_OF_FAME_MAX_TEAMS)
            gTasks[taskId].data[0] = i - 1;
        else
            gTasks[taskId].data[0] = HALL_OF_FAME_MAX_TEAMS - 1;

        gTasks[taskId].data[1] = GetGameStat(GAME_STAT_ENTERED_HOF);

        gTasks[taskId].func = Task_HofPC_DrawSpritesPrintText;
    }
}

static void Task_HofPC_DrawSpritesPrintText(u8 taskId)
{
    struct HallofFameTeam *savedTeams = gHoFSaveBuffer;
    struct HallofFameMon *currMon;
    u16 i;

    for (i = 0; i < gTasks[taskId].data[0]; i++)
        savedTeams++;

    currMon = &savedTeams->mon[0];
    sSelectedPaletteIndices = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[4] = 0;

    for (i = 0; i < PARTY_SIZE; i++, currMon++)
    {
        if (currMon->species != SPECIES_NONE)
            gTasks[taskId].data[4]++;
    }

    currMon = &savedTeams->mon[0];

    for (i = 0; i < PARTY_SIZE; i++, currMon++)
    {
        if (currMon->species != SPECIES_NONE)
        {
            u16 spriteId;
            s16 posX, posY;

            if (gTasks[taskId].data[4] > 3)
            {
                posX = sHallOfFame_MonFullTeamPositions[i][2];
                posY = sHallOfFame_MonFullTeamPositions[i][3];
            }
            else
            {
                posX = sHallOfFame_MonHalfTeamPositions[i][2];
                posY = sHallOfFame_MonHalfTeamPositions[i][3];
            }

            spriteId = CreateMonPicSprite(currMon->species, currMon->isShiny, currMon->personality, TRUE, posX, posY, i, 0xFFFF);
            gSprites[spriteId].oam.priority = 1;
            gTasks[taskId].data[5 + i] = spriteId;
        }
        else
        {
            gTasks[taskId].data[5 + i] = 0xFF;
        }
    }

    BlendPalettes(0xFFFF0000, 0xC, HALL_OF_FAME_BG_PAL);

    ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[1], STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_HOFNumber);

    if (gTasks[taskId].data[0] <= 0)
        HofPCTopBar_PrintPair(gStringVar4, gText_PickCancel, 0, 0, TRUE);
    else
        HofPCTopBar_PrintPair(gStringVar4, gText_PickNextCancel, 0, 0, TRUE);

    gTasks[taskId].func = Task_HofPC_PrintMonInfo;
}

static void Task_HofPC_PrintMonInfo(u8 taskId)
{
    struct HallofFameTeam *savedTeams = gHoFSaveBuffer;
    struct HallofFameMon* currMon;
    u16 i;
    u16 currMonId;

    for (i = 0; i < gTasks[taskId].data[0]; i++)
        savedTeams++;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 spriteId = gTasks[taskId].data[5 + i];
        if (spriteId != 0xFF)
            gSprites[spriteId].oam.priority = 1;
    }

    currMonId = gTasks[taskId].data[5 + gTasks[taskId].data[2]];
    gSprites[currMonId].oam.priority = 0;
    sSelectedPaletteIndices = (0x10000 << gSprites[currMonId].oam.paletteNum) ^ 0xFFFF0000;
    BlendPalettesUnfaded(sSelectedPaletteIndices, 0xC, HALL_OF_FAME_BG_PAL);

    currMon = &savedTeams->mon[gTasks[taskId].data[2]];
    if (currMon->species != SPECIES_EGG)
    {
        StopCryAndClearCrySongs();
        PlayCry_Normal(currMon->species, 0);
    }
    HallOfFame_PrintMonInfo(currMon, 0, 14);

    gTasks[taskId].func = Task_HofPC_HandleInput;
}

static void Task_HofPC_HandleInput(u8 taskId)
{
    u16 i;

    if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].data[0] != 0) // prepare another team to view
        {
            gTasks[taskId].data[0]--;
            for (i = 0; i < 6; i++)
            {
                u8 spriteId = gTasks[taskId].data[5 + i];
                if (spriteId != 0xFF)
                {
                    FreeAndDestroyMonPicSprite(spriteId);
                }
            }
            if (gTasks[taskId].data[1] != 0)
                gTasks[taskId].data[1]--;
            gTasks[taskId].func = Task_HofPC_DrawSpritesPrintText;
        }
        else // no more teams to view, turn off hall of fame PC
        {
            if (IsCryPlayingOrClearCrySongs())
            {
                StopCryAndClearCrySongs();
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
            }
            gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
        }
    }
    else if (JOY_NEW(B_BUTTON)) // turn off hall of fame PC
    {
        if (IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        }
        gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
    }
    else if (JOY_NEW(DPAD_UP) && gTasks[taskId].data[2] != 0) // change mon -1
    {
        gTasks[taskId].data[2]--;
        gTasks[taskId].func = Task_HofPC_PrintMonInfo;
    }
    else if (JOY_NEW(DPAD_DOWN) && gTasks[taskId].data[2] < gTasks[taskId].data[4] - 1) // change mon +1
    {
        gTasks[taskId].data[2]++;
        gTasks[taskId].func = Task_HofPC_PrintMonInfo;
    }
}
static void Task_HofPC_HandlePaletteOnExit(u8 taskId)
{
    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, PLTT_SIZE);
    ComputerScreenCloseEffect(0, 0, 0);
    gTasks[taskId].func = Task_HofPC_HandleExit;
}

static void Task_HofPC_HandleExit(u8 taskId)
{
    if (!IsComputerScreenCloseEffectActive())
    {
        HideBg(0);
        HideBg(1);
        HideBg(3);
        HofPCTopBar_RemoveWindow();
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        ResetBgsAndClearDma3BusyFlags(FALSE);
        DestroyTask(taskId);
        FreeAllHoFMem();

        ReturnFromHallOfFamePC();
    }
}

static void Task_HofPC_PrintDataIsCorrupted(u8 taskId)
{
    HofPCTopBar_Print(gText_AButtonExit, 8, TRUE);
    DrawDialogueFrame(0, 0);
    AddTextPrinterParameterized2(0, FONT_NORMAL, gText_HOFCorrupted, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    CopyWindowToVram(0, COPYWIN_FULL);
    gTasks[taskId].func = Task_HofPC_ExitOnButtonPress;
}

static void Task_HofPC_ExitOnButtonPress(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
        gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
}

static void HallOfFame_PrintWelcomeText(u8 not, u8 used)
{
    u8 x = (0xD0 - GetStringWidth(FONT_NORMAL, gText_WelcomeToHOF, 0)) / 2;
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
    AddTextPrinterParameterized3(0, FONT_NORMAL, x, 1, sTextColors[0], 0, gText_WelcomeToHOF);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 unused1, u8 unused2)
{
    u8 text[16];
    u8 text2[24];
    u16 i;
    u8 *stringPtr;
    u16 dexNumber;
    u8 gender;
    s32 width;
    s32 x;

    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);

    // dex number
    if (currMon->species != SPECIES_EGG)
    {
        StringCopy(text2, gText_Number);
        dexNumber = SpeciesToPokedexNum(currMon->species);
        if (dexNumber != 0xFFFF)
        {
            text[0] = (dexNumber / 100) + CHAR_0;
            text[1] = ((dexNumber %= 100) / 10) + CHAR_0;
            text[2] = (dexNumber % 10) + CHAR_0;
        }
        else
        {
            text[0] = text[1] = text[2] = CHAR_QUESTION_MARK;
        }
        text[3] = EOS;
        StringAppend(text2, text);
        AddTextPrinterParameterized3(0, FONT_NORMAL, 16, 1, sTextColors[0], 0, text2);
    }

    // nick, species names, gender and lvl
    i = 0;
    if (currMon->nickname[0] != EOS)
    {
        for (i = 0; i < 10 && currMon->nickname[i] != EOS; i++)
        {
            text[i] = currMon->nickname[i];
        }
    }
    text[i] = EOS;
    width = GetStringWidth(FONT_NORMAL, text, GetFontAttribute(FONT_NORMAL, FONTATTR_LETTER_SPACING));
    if (currMon->species == SPECIES_EGG)
        x = 0x80 - width / 2;
    else
        x = 0x80 - width;
    AddTextPrinterParameterized3(0, FONT_NORMAL, x, 1, sTextColors[0], 0, text);
    if (currMon->species != SPECIES_EGG)
    {
        text[0] = CHAR_SLASH;
        stringPtr = StringCopy(text + 1, gSpeciesInfo[currMon->species].speciesName);

        if (currMon->species == SPECIES_NIDORAN_M || currMon->species == SPECIES_NIDORAN_F)
            gender = MON_GENDERLESS;
        else
            gender = GetGenderFromSpeciesAndPersonality(currMon->species, currMon->personality);
        switch (gender)
        {
        case MON_MALE:
            *stringPtr++ = CHAR_MALE;
            break;
        case MON_FEMALE:
            *stringPtr++ = CHAR_FEMALE;
            break;
        default:
            *stringPtr++ = CHAR_SPACE;
            break;
        }
        *stringPtr = EOS;

        AddTextPrinterParameterized3(0, FONT_NORMAL, 0x80, 1, sTextColors[0], 0, text);

        stringPtr = StringCopy(text, gText_Level);
        ConvertIntToDecimalStringN(stringPtr, currMon->lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
        AddTextPrinterParameterized3(0, FONT_NORMAL, 0x20, 0x11, sTextColors[0], 0, text);

        stringPtr = StringCopy(text, gText_IDNumber);
        ConvertIntToDecimalStringN(stringPtr, (u16)(currMon->tid), STR_CONV_MODE_LEADING_ZEROS, 5);
        AddTextPrinterParameterized3(0, FONT_NORMAL, 0x60, 0x11, sTextColors[0], 0, text);

    }
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void HallOfFame_PrintPlayerInfo(u8 unused1, u8 unused2)
{
    u8 text[20];
    u16 trainerId;
    s32 textWidth = sWindowTemplate.width * 8 - 6;

    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    PutWindowTilemap(1);
    DrawStdFrameWithCustomTileAndPalette(1, FALSE, 0x21D, 13);
    AddTextPrinterParameterized4(1, FONT_NORMAL, 4, 3, 0, 0, sTextColors[1], 0, gText_Name);

    AddTextPrinterParameterized3(1, FONT_NORMAL, textWidth - GetStringWidth(FONT_NORMAL, gSaveBlock2Ptr->playerName, 0), 3, sTextColors[1], 0, gSaveBlock2Ptr->playerName);

    trainerId = (gSaveBlock2Ptr->playerTrainerId[0]) | (gSaveBlock2Ptr->playerTrainerId[1] << 8);
    AddTextPrinterParameterized3(1, FONT_NORMAL, 4, 18, sTextColors[1], 0, gText_IDNumber);
    text[0] = (trainerId % 100000) / 10000 + CHAR_0;
    text[1] = (trainerId % 10000) / 1000 + CHAR_0;
    text[2] = (trainerId % 1000) / 100 + CHAR_0;
    text[3] = (trainerId % 100) / 10 + CHAR_0;
    text[4] = (trainerId % 10) / 1 + CHAR_0;
    text[5] = EOS;
    AddTextPrinterParameterized3(1, FONT_NORMAL, textWidth - 30, 18, sTextColors[1], 0, text);

    AddTextPrinterParameterized3(1, FONT_NORMAL, 4, 32, sTextColors[1], 0, gText_Time);
    text[0] = (gSaveBlock2Ptr->playTimeHours / 100) + CHAR_0;
    text[1] = (gSaveBlock2Ptr->playTimeHours % 100) / 10 + CHAR_0;
    text[2] = (gSaveBlock2Ptr->playTimeHours % 10) + CHAR_0;

    if (text[0] == CHAR_0)
        text[0] = CHAR_SPACE;
    if (text[0] == CHAR_SPACE && text[1] == CHAR_0)
        text[1] = CHAR_SPACE;

    text[3] = CHAR_COLON;
    text[4] = (gSaveBlock2Ptr->playTimeMinutes % 100) / 10 + CHAR_0;
    text[5] = (gSaveBlock2Ptr->playTimeMinutes % 10) + CHAR_0;
    text[6] = EOS;

    AddTextPrinterParameterized3(1, FONT_NORMAL, textWidth - 36, 32, sTextColors[1], 0, text);

    CopyWindowToVram(1, COPYWIN_FULL);
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
    LoadPalette(sHallOfFame_Pal, BG_PLTT_ID(0), sizeof(sHallOfFame_Pal));
}

static void HofInit_ResetGpuBuffersAndLoadConfettiGfx(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetTempTileDataBuffers();
    ResetAllPicSprites();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 8;
    LoadCompressedSpriteSheet(sHallOfFame_ConfettiSpriteSheet);
    LoadSpritePalette(sHallOfFame_ConfettiSpritePalette);
}

static void Hof_InitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sHof_BgTemplates, NELEMS(sHof_BgTemplates));
    SetBgTilemapBuffer(1, sHofGfxPtr->tilemap1);
    SetBgTilemapBuffer(3, sHofGfxPtr->tilemap2);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

static bool8 DrawHofBackground(void)
{
    switch (sHofGfxPtr->state)
    {
    case 0:
        DecompressAndCopyTileDataToVram(1, sHallOfFame_Gfx, 0, 0, 0);
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
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
        InitTextBoxGfxAndPrinters();
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

static void SpriteCB_EndGetOnScreen(struct Sprite *sprite)
{

}

static void SpriteCB_GetOnScreen(struct Sprite *sprite)
{
    if (sprite->x != sprite->data[1]
        || sprite->y != sprite->data[2])
    {
        if (sprite->x < sprite->data[1])
            sprite->x += 15;
        if (sprite->x > sprite->data[1])
            sprite->x -= 15;

        if (sprite->y < sprite->data[2])
            sprite->y += 10;
        if (sprite->y > sprite->data[2])
            sprite->y -= 10;
    }
    else
    {
        sprite->data[0] = 1;
        sprite->callback = SpriteCB_EndGetOnScreen;
    }
}

static void SpriteCB_Confetti(struct Sprite* sprite)
{
    if (sprite->y2 > 120)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 rand;
        u8 tableID;

        sprite->y2++;
        sprite->y2 += sprite->data[1];

        tableID = sprite->data[0];
        rand = (Random() % 4) + 8;
        sprite->x2 = rand * gSineTable[tableID] / 256;

        sprite->data[0] += 4;
    }
}

static bool8 Hof_SpawnConfetti(void)
{
    u8 spriteId;
    struct Sprite* sprite;

    s16 posX = Random() % 240;
    s16 posY = -(Random() % 8);

    spriteId = CreateSprite(&sSpriteTemplate_Confetti, posX, posY, 0);
    sprite = &gSprites[spriteId];

    StartSpriteAnim(sprite, Random() % 17);

    if (Random() & 3)
        sprite->data[1] = 0;
    else
        sprite->data[1] = 1;

    return FALSE;
}
