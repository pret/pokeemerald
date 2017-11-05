#include "global.h"
#include "hall_of_fame.h"
#include "task.h"
#include "palette.h"
#include "sprite.h"
#include "pokemon.h"
#include "text.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "main.h"
#include "sound.h"
#include "songs.h"
#include "decompress.h"
#include "save.h"
#include "window.h"
#include "bg.h"
#include "species.h"
#include "game_stat.h"
#include "blend_palette.h"
#include "string_util.h"
#include "m4a.h"

struct HallofFameMon
{
    u32 tid;
    u32 personality;
    u16 species : 9;
    u16 lvl : 7;
    u8 nick[10];
};

struct HallofFameMons
{
    struct HallofFameMon mons[6];
};

extern struct HallofFameMons *gHofMonsPtr;

struct HofGfx
{
    u16 field_0;
    u8 field_2[0x2010];
};

extern struct HofGfx *gUnknown_0203BCDC;

extern u32 gUnknown_0203BCD4;
extern bool8 HasHallOfFameRecords;
extern u8 gDecompressionBuffer[];
extern struct MusicPlayerInfo gMPlay_BGM;
extern MainCallback gGameContinueCallback;
extern u32 gDamagedSaveSectors;

#define HALL_OF_FAME_MAX_TEAMS 50

// strings
extern const u8 gText_SavingDontTurnOffPower[];
extern const u8 gText_LeagueChamp[];
extern const u8 gText_HOFNumber[];
extern const u8 gText_PickNextCancel[];
extern const u8 gText_PickCancel[];
extern const u8 gText_UnkCtrlF800Exit[];
extern const u8 gText_HOFCorrupted[];

extern void sub_81973C4(u8, u8);
extern u16 AddTextPrinterParametrized(u8 windowId, u8 fontId, const u8 *str, u8 speed, void ( *callback)(u16, struct TextPrinter *), u8 fgColor, u8 bgColor, u8 shadowColor);
extern void sub_8175620(void);
extern u8 TrySavingData(u8);
extern u8 sub_818D3E4(u16 species, u32 trainerId, u32 personality, u8 flags, s16 x, s16 y, u8, u16);
extern void sub_8197434(u8, u8);
extern u16 sub_818D97C(u8 playerGender, u8);
extern u16 sub_818D8AC(u16, u8, s16, s16, u8, u16);
extern const void* stdpal_get(u8);
extern void sub_80987D4(u8, u8, u16, u8);
extern u16 sub_818D820(u16);
extern u16 sub_818D8F0(u16);
extern u16 sub_818D7D8(u16 species, u32 trainerId, u32 personality, u8 arg3, s16 sp0, s16 sp1, u8 sp2, u16 sp3);
extern void sub_8198204(u8 *dst, const u8 *src, u8, u8, u8);
extern bool8 sub_80F9C30(void);
extern void sub_8198314(void);
extern void sub_8137C3C(void);
extern void sub_8198180(const u8 *src, u8, u8);
extern void sub_80F9BF4(u16, u16, u8);
extern void sub_81980F0(u8, u8, u8, u8, u16);
extern void sub_80F9BCC(u16, u16, u8);
extern bool8 sub_80F9C1C(void);

// this file's functions
void sub_8174EC4(void);
void sub_8174F70(void);
void sub_8174FAC(void);
void sub_81751FC(void);
static void SetCallback2AfterHallOfFameDisplay(void);
bool8 sub_8175024(void);
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
void sub_8175120(struct Sprite *sprite);
void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 unused1, u8 unused2);
void HallOfFame_PrintWelcomeText(u8 unusedPossiblyWindowId, u8 arg1);
void HallOfFame_PrintPlayerInfo(u8 unused1, u8 unused2);

void VBlankCB_HallOfFame(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_HallOfFame(void)
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
        sub_8174EC4();
        gUnknown_0203BCDC = AllocZeroed(sizeof(*gUnknown_0203BCDC));
        gMain.state = 1;
        break;
    case 1:
        sub_8174F70();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, 0x3F42);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0x710);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        sub_8174FAC();
        gUnknown_0203BCDC->field_0 = 0;
        gMain.state++;
        break;
    case 3:
        if (!sub_8175024())
        {
            SetVBlankCallback(VBlankCB_HallOfFame);
            BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
            gMain.state++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_HallOfFame);
            PlayBGM(BGM_DENDOU);
            return FALSE;
        }
        break;
    }
    return TRUE;
}

#define tDontSaveData       data[0]
#define tDisplayedMonId     data[1]
#define tPokesNumber        data[2]
#define tFrameCount         data[3]
#define tPlayerSpriteID     data[4]
#define tMonSpriteID(i)     data[i + 5]

void CB2_DoHallOfFameScreen(void)
{
    if (!InitHallOfFameScreen())
    {
        u8 taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].tDontSaveData = FALSE;
        gHofMonsPtr = AllocZeroed(sizeof(*gHofMonsPtr));
    }
}

void CB2_DoHallOfFameScreenDontSaveData(void)
{
    if (!InitHallOfFameScreen())
    {
        u8 taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].tDontSaveData = TRUE;
        gHofMonsPtr = AllocZeroed(sizeof(*gHofMonsPtr));
    }
}

static void Task_Hof_InitMonData(u8 taskId)
{
    u16 i, j;

    gTasks[taskId].tPokesNumber = 0; // valid pokes

    for (i = 0; i < 6; i++)
    {
        u8 nick[POKEMON_NAME_LENGTH + 2];
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
        {
            gHofMonsPtr->mons[i].species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            gHofMonsPtr->mons[i].tid = GetMonData(&gPlayerParty[i], MON_DATA_OT_ID);
            gHofMonsPtr->mons[i].personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            gHofMonsPtr->mons[i].lvl = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            GetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, nick);
            for (j = 0; j < POKEMON_NAME_LENGTH; j++)
            {
                gHofMonsPtr->mons[i].nick[j] = nick[j];
            }
            gTasks[taskId].tPokesNumber++;
        }
        else
        {
            gHofMonsPtr->mons[i].species = 0;
            gHofMonsPtr->mons[i].tid = 0;
            gHofMonsPtr->mons[i].personality = 0;
            gHofMonsPtr->mons[i].lvl = 0;
            gHofMonsPtr->mons[i].nick[0] = EOS;
        }
    }

    gUnknown_0203BCD4 = 0;
    gTasks[taskId].tDisplayedMonId = 0;
    gTasks[taskId].tPlayerSpriteID = 0xFF;

    for (i = 0; i < 6; i++)
    {
        gTasks[taskId].tMonSpriteID(i) = 0xFF;
    }

    if (gTasks[taskId].tDontSaveData)
        gTasks[taskId].func = Task_Hof_SetMonDisplayTask;
    else
        gTasks[taskId].func = Task_Hof_InitTeamSaveData;
}

static void Task_Hof_InitTeamSaveData(u8 taskId)
{
    u16 i;
    struct HallofFameMons* lastSavedTeam = (struct HallofFameMons*)(gDecompressionBuffer);

    if (!HasHallOfFameRecords)
    {
        memset(gDecompressionBuffer, 0, 0x2000);
    }
    else
    {
        if (sub_81534D0(3) != TRUE)
            memset(gDecompressionBuffer, 0, 0x2000);
    }

    for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, lastSavedTeam++)
    {
        if (lastSavedTeam->mons[0].species == 0)
            break;
    }
    if (i >= HALL_OF_FAME_MAX_TEAMS)
    {
        struct HallofFameMons *afterTeam = (struct HallofFameMons*)(gDecompressionBuffer);
        struct HallofFameMons *beforeTeam = (struct HallofFameMons*)(gDecompressionBuffer);
        afterTeam++;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS - 1; i++, beforeTeam++, afterTeam++)
        {
            *beforeTeam = *afterTeam;
        }
        lastSavedTeam--;
    }
    *lastSavedTeam = *gHofMonsPtr;

    sub_81973C4(0, 0);
    AddTextPrinterParametrized(0, 1, gText_SavingDontTurnOffPower, 0, NULL, 2, 1, 3);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_Hof_TrySaveData;
}

static void Task_Hof_TrySaveData(u8 taskId)
{
    gGameContinueCallback = CB2_DoHallOfFameScreenDontSaveData;
    if (TrySavingData(3) == 0xFF && gDamagedSaveSectors != 0)
    {
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        FreeAllWindowBuffers();

        if (gUnknown_0203BCDC != NULL)
            FREE_AND_SET_NULL(gUnknown_0203BCDC);
        if (gHofMonsPtr != NULL)
            FREE_AND_SET_NULL(gHofMonsPtr);

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

extern const s16 sHallOfFame_MonsFullTeamPositions[][4];
extern const s16 sHallOfFame_MonsHalfTeamPositions[][4];

static void Task_Hof_DisplayMon(u8 taskId)
{
    u8 spriteId;
    s16 xPos, yPos, field4, field6;

    u16 currMonId = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &gHofMonsPtr->mons[currMonId];

    if (gTasks[taskId].tPokesNumber > 3)
    {
        xPos = sHallOfFame_MonsFullTeamPositions[currMonId][0];
        yPos = sHallOfFame_MonsFullTeamPositions[currMonId][1];
        field4 = sHallOfFame_MonsFullTeamPositions[currMonId][2];
        field6 = sHallOfFame_MonsFullTeamPositions[currMonId][3];
    }
    else
    {
        xPos = sHallOfFame_MonsHalfTeamPositions[currMonId][0];
        yPos = sHallOfFame_MonsHalfTeamPositions[currMonId][1];
        field4 = sHallOfFame_MonsHalfTeamPositions[currMonId][2];
        field6 = sHallOfFame_MonsHalfTeamPositions[currMonId][3];
    }

    if (currMon->species == SPECIES_EGG)
        field6 += 10;

    spriteId = sub_818D3E4(currMon->species, currMon->tid, currMon->personality, 1, xPos, yPos, currMonId, 0xFFFF);
    gSprites[spriteId].data1 = field4;
    gSprites[spriteId].data2 = field6;
    gSprites[spriteId].data0 = 0;
    gSprites[spriteId].data7 = currMon->species;
    gSprites[spriteId].callback = sub_8175120;
    gTasks[taskId].tMonSpriteID(currMonId) = spriteId;
    sub_8197434(0, 1);
    gTasks[taskId].func = Task_Hof_PrintMonInfoAfterAnimating;
}

static void Task_Hof_PrintMonInfoAfterAnimating(u8 taskId)
{
    u16 currMonId = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &gHofMonsPtr->mons[currMonId];
    struct Sprite *monSprite = &gSprites[gTasks[taskId].tMonSpriteID(currMonId)];

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
    struct HallofFameMon* currMon = &gHofMonsPtr->mons[currPokeID];

    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
    }
    else
    {
        gUnknown_0203BCD4 |= (0x10000 << gSprites[gTasks[taskId].tMonSpriteID(currPokeID)].oam.paletteNum);
        if (gTasks[taskId].tDisplayedMonId <= 4 && currMon[1].species != SPECIES_NONE) // there is another pokemon to display
        {
            gTasks[taskId].tDisplayedMonId++;
            BeginNormalPaletteFade(gUnknown_0203BCD4, 0, 12, 12, 0x63B0);
            gSprites[gTasks[taskId].tMonSpriteID(currPokeID)].oam.priority = 1;
            gTasks[taskId].func = Task_Hof_DisplayMon;
        }
        else
        {
            gTasks[taskId].func = Task_Hof_PaletteFadeAndPrintWelcomeText;
        }
    }
}

static void Task_Hof_PaletteFadeAndPrintWelcomeText(u8 taskID)
{
    u16 i;

    BeginNormalPaletteFade(0xFFFF0000, 0, 0, 0, 0);
    for (i = 0; i < 6; i++)
    {
        if (gTasks[taskID].tMonSpriteID(i) != 0xFF)
            gSprites[gTasks[taskID].tMonSpriteID(i)].oam.priority = 0;
    }

    HallOfFame_PrintWelcomeText(0, 15);
    PlaySE(SE_DENDOU);
    gTasks[taskID].tFrameCount = 400;
    gTasks[taskID].func = sub_8173DC0;
}

static void sub_8173DC0(u8 taskID)
{
    if (gTasks[taskID].tFrameCount != 0)
    {
        gTasks[taskID].tFrameCount--;
        if ((gTasks[taskID].tFrameCount & 3) == 0 && gTasks[taskID].tFrameCount > 110)
            sub_81751FC();
    }
    else
    {
        u16 i;
        for (i = 0; i < 6; i++)
        {
            if (gTasks[taskID].tMonSpriteID(i) != 0xFF)
                gSprites[gTasks[taskID].tMonSpriteID(i)].oam.priority = 1;
        }
        BeginNormalPaletteFade(gUnknown_0203BCD4, 0, 12, 12, 0x63B0);
        FillWindowPixelBuffer(0, 0);
        CopyWindowToVram(0, 3);
        gTasks[taskID].tFrameCount = 7;
        gTasks[taskID].func = sub_8173EA4;
    }
}

static void sub_8173EA4(u8 taskID)
{
    if (gTasks[taskID].tFrameCount >= 16)
    {
        gTasks[taskID].func = sub_8173EE4;
    }
    else
    {
        gTasks[taskID].tFrameCount++;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskID].tFrameCount * 256);
    }
}

extern const struct WindowTemplate gUnknown_085E5380;

static void sub_8173EE4(u8 taskID)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(3);
    gTasks[taskID].tPlayerSpriteID = sub_818D8AC(sub_818D97C(gSaveBlock2Ptr->playerGender, 1), 1, 120, 72, 6, 0xFFFF);
    AddWindow(&gUnknown_085E5380);
    sub_80987D4(1, gSaveBlock2Ptr->optionsWindowFrameType, 0x21D, 0xD0);
    LoadPalette(stdpal_get(1), 0xE0, 0x20);
    gTasks[taskID].tFrameCount = 120;
    gTasks[taskID].func = Task_Hof_WaitAndPrintPlayerInfo;
}

static void Task_Hof_WaitAndPrintPlayerInfo(u8 taskID)
{
    if (gTasks[taskID].tFrameCount != 0)
    {
        gTasks[taskID].tFrameCount--;
    }
    else if (gSprites[gTasks[taskID].tPlayerSpriteID].pos1.x != 192)
    {
        gSprites[gTasks[taskID].tPlayerSpriteID].pos1.x++;
    }
    else
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        HallOfFame_PrintPlayerInfo(1, 2);
        sub_81973C4(0, 0);
        AddTextPrinterParametrized(0, 1, gText_LeagueChamp, 0, NULL, 2, 1, 3);
        CopyWindowToVram(0, 3);
        gTasks[taskID].func = Task_Hof_ExitOnKeyPressed;
    }
}

static void Task_Hof_ExitOnKeyPressed(u8 taskID)
{
    if (gMain.newKeys & A_BUTTON)
    {
        FadeOutBGM(4);
        gTasks[taskID].func = Task_Hof_HandlePaletteOnExit;
    }
}

static void Task_Hof_HandlePaletteOnExit(u8 taskID)
{
    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    BeginNormalPaletteFade(-1, 8, 0, 0x10, 0);
    gTasks[taskID].func = Task_Hof_HandleExit;
}

static void Task_Hof_HandleExit(u8 taskID)
{
    if (!gPaletteFade.active)
    {
        s32 i;

        for (i = 0; i < 6; i++)
        {
            u8 spriteId = gTasks[taskID].tMonSpriteID(i);
            if (spriteId != 0xFF)
            {
                FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
                sub_818D820(spriteId);
            }
        }

        sub_818D8F0(gTasks[taskID].tPlayerSpriteID);
        HideBg(0);
        HideBg(1);
        HideBg(3);
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        ResetBgsAndClearDma3BusyFlags(0);
        DestroyTask(taskID);

        if (gUnknown_0203BCDC != NULL)
            FREE_AND_SET_NULL(gUnknown_0203BCDC);
        if (gHofMonsPtr != NULL)
            FREE_AND_SET_NULL(gHofMonsPtr);

        SetCallback2AfterHallOfFameDisplay();
    }
}

static void SetCallback2AfterHallOfFameDisplay(void)
{
    SetMainCallback2(sub_8175620);
}

#undef tDontSaveData
#undef tDisplayedPoke
#undef tPokesNumber
#undef tFrameCount
#undef tPlayerSpriteID
#undef tMonSpriteID

#define tCurrTeamNo     data[0]
#define tCurrPageNo     data[1]
#define tCurrPokeID     data[2]
#define tPokesNo        data[4]
#define tMonSpriteID(i) data[i + 5]

extern const struct HallofFameMon sDummyFameMon;

void CB2_DoHallOfFamePC(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        sub_8174EC4();
        gUnknown_0203BCDC = AllocZeroed(sizeof(*gUnknown_0203BCDC));
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
            struct HallofFameMons *fameMons = (struct HallofFameMons*)(gDecompressionBuffer);
            fameMons->mons[0] = sDummyFameMon;
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

            SetGpuReg(REG_OFFSET_BLDCNT, 0x3F42);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0x710);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            taskId = CreateTask(Task_HofPC_CopySaveData, 0);

            for (i = 0; i < 6; i++)
            {
                gTasks[taskId].tMonSpriteID(i) = 0xFF;
            }

            gHofMonsPtr = AllocZeroed(0x2000);
            SetMainCallback2(CB2_HallOfFame);
        }
        break;
    }
}

static void Task_HofPC_CopySaveData(u8 taskID)
{
    sub_81980F0(0, 0x1E, 0, 0xC, 0x226);
    if (sub_81534D0(3) != 1)
    {
        gTasks[taskID].func = Task_HofPC_PrintDataIsCorrupted;
    }
    else
    {
        u16 i;
        struct HallofFameMons* savedTeams;

        CpuCopy16(gDecompressionBuffer, gHofMonsPtr, 0x2000);
        savedTeams = gHofMonsPtr;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, savedTeams++)
        {
            if (savedTeams->mons[0].species == SPECIES_NONE)
                break;
        }

        if (i < HALL_OF_FAME_MAX_TEAMS)
            gTasks[taskID].tCurrTeamNo = i - 1;
        else
            gTasks[taskID].tCurrTeamNo = HALL_OF_FAME_MAX_TEAMS - 1;

        gTasks[taskID].tCurrPageNo = GetGameStat(GAME_STAT_ENTERED_HOF);

        gTasks[taskID].func = Task_HofPC_DrawSpritesPrintText;
    }
}

static void Task_HofPC_DrawSpritesPrintText(u8 taskID)
{
    struct HallofFameMons* savedTeams = gHofMonsPtr;
    struct HallofFameMon* currMon;
    u16 i;

    for (i = 0; i < gTasks[taskID].tCurrTeamNo; i++)
        savedTeams++;

    currMon = &savedTeams->mons[0];
    gUnknown_0203BCD4 = 0;
    gTasks[taskID].tCurrPokeID = 0;
    gTasks[taskID].tPokesNo = 0;

    for (i = 0; i < 6; i++, currMon++)
    {
        if (currMon->species != 0)
            gTasks[taskID].tPokesNo++;
    }

    currMon = &savedTeams->mons[0];

    for (i = 0; i < 6; i++, currMon++)
    {
        if (currMon->species != 0)
        {
            u16 spriteID;
            s16 posX, posY;

            if (gTasks[taskID].tPokesNo > 3)
            {
                posX = sHallOfFame_MonsFullTeamPositions[i][2];
                posY = sHallOfFame_MonsFullTeamPositions[i][3];
            }
            else
            {
                posX = sHallOfFame_MonsHalfTeamPositions[i][2];
                posY = sHallOfFame_MonsHalfTeamPositions[i][3];
            }

            if (currMon->species == SPECIES_EGG)
                posY += 10;

            spriteID = sub_818D7D8(currMon->species, currMon->tid, currMon->personality, 1, posX, posY, i, 0xFFFF);
            gSprites[spriteID].oam.priority = 1;
            gTasks[taskID].tMonSpriteID(i) = spriteID;
        }
        else
        {
            gTasks[taskID].tMonSpriteID(i) = 0xFF;
        }
    }

    BlendPalettes(0xFFFF0000, 0xC, 0x63B0);

    ConvertIntToDecimalStringN(gStringVar1, gTasks[taskID].tCurrPageNo, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_HOFNumber);

    if (gTasks[taskID].tCurrTeamNo <= 0)
        sub_8198204(gStringVar4, gText_PickCancel, 0, 0, 1);
    else
        sub_8198204(gStringVar4, gText_PickNextCancel, 0, 0, 1);

    gTasks[taskID].func = Task_HofPC_PrintMonInfo;
}

static void Task_HofPC_PrintMonInfo(u8 taskID)
{
    struct HallofFameMons* savedTeams = gHofMonsPtr;
    struct HallofFameMon* currMon;
    u16 i;
    u16 currMonID;

    for (i = 0; i < gTasks[taskID].tCurrTeamNo; i++)
        savedTeams++;

    for (i = 0; i < 6; i++)
    {
        u16 spriteID = gTasks[taskID].tMonSpriteID(i);
        if (spriteID != 0xFF)
            gSprites[spriteID].oam.priority = 1;
    }

    currMonID = gTasks[taskID].tMonSpriteID(gTasks[taskID].tCurrPokeID);
    gSprites[currMonID].oam.priority = 0;
    gUnknown_0203BCD4 = (0x10000 << gSprites[currMonID].oam.paletteNum) ^ 0xFFFF0000;
    BlendPalettesUnfaded(gUnknown_0203BCD4, 0xC, 0x63B0);

    currMon = &savedTeams->mons[gTasks[taskID].tCurrPokeID];
    if (currMon->species != SPECIES_EGG)
    {
        StopCryAndClearCrySongs();
        PlayCry1(currMon->species, 0);
    }
    HallOfFame_PrintMonInfo(currMon, 0, 14);

    gTasks[taskID].func = Task_HofPC_HandleInput;
}

static void Task_HofPC_HandleInput(u8 taskID)
{
    u16 i;

    if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskID].tCurrTeamNo != 0) // prepare another team to view
        {
            gTasks[taskID].tCurrTeamNo--;
            for (i = 0; i < 6; i++)
            {
                u8 spriteID = gTasks[taskID].tMonSpriteID(i);
                if (spriteID != 0xFF)
                {
                    sub_818D820(spriteID);
                    gTasks[taskID].tMonSpriteID(i) = 0xFF;
                }
            }
            if (gTasks[taskID].tCurrPageNo != 0)
                gTasks[taskID].tCurrPageNo--;
            gTasks[taskID].func = Task_HofPC_DrawSpritesPrintText;
        }
        else // no more teams to view, turn off hall of fame PC
        {
            if (IsCryPlayingOrClearCrySongs())
            {
                StopCryAndClearCrySongs();
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            }
            gTasks[taskID].func = Task_HofPC_HandlePaletteOnExit;
        }
    }
    else if (gMain.newKeys & B_BUTTON) // turn off hall of fame PC
    {
        if (IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        }
        gTasks[taskID].func = Task_HofPC_HandlePaletteOnExit;
    }
    else if (gMain.newKeys & DPAD_UP && gTasks[taskID].tCurrPokeID != 0) // change mon -1
    {
        gTasks[taskID].tCurrPokeID--;
        gTasks[taskID].func = Task_HofPC_PrintMonInfo;
    }
    else if (gMain.newKeys & DPAD_DOWN && gTasks[taskID].tCurrPokeID < gTasks[taskID].tPokesNo - 1) // change mon +1
    {
        gTasks[taskID].tCurrPokeID++;
        gTasks[taskID].func = Task_HofPC_PrintMonInfo;
    }
}

static void Task_HofPC_HandlePaletteOnExit(u8 taskID)
{
    struct HallofFameMons* fameMons;

    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    fameMons = (struct HallofFameMons*)(gDecompressionBuffer);
    fameMons->mons[0] = sDummyFameMon;
    sub_80F9BF4(0, 0, 0);
    gTasks[taskID].func = Task_HofPC_HandleExit;
}

static void Task_HofPC_HandleExit(u8 taskID)
{
    if (!sub_80F9C30())
    {
        u8 i;

        for (i = 0; i < 6; i++)
        {
            u16 spriteId = gTasks[taskID].tMonSpriteID(i);
            if (spriteId != 0xFF)
            {
                sub_818D820(spriteId);
                gTasks[taskID].tMonSpriteID(i) = 0xFF;
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
        DestroyTask(taskID);

        if (gUnknown_0203BCDC != NULL)
            FREE_AND_SET_NULL(gUnknown_0203BCDC);
        if (gHofMonsPtr != NULL)
            FREE_AND_SET_NULL(gHofMonsPtr);

        sub_8137C3C();
    }
}

static void Task_HofPC_PrintDataIsCorrupted(u8 taskId)
{
    sub_8198180(gText_UnkCtrlF800Exit, 8, 1);
    sub_81973C4(0, 0);
    AddTextPrinterParametrized(0, 1, gText_HOFCorrupted, 0, NULL, 2, 1, 3);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_HofPC_ExitOnButtonPress;
}

static void Task_HofPC_ExitOnButtonPress(u8 taskID)
{
    if (gMain.newKeys & A_BUTTON)
        gTasks[taskID].func = Task_HofPC_HandlePaletteOnExit;
}

#undef tCurrTeamNo
#undef tCurrPageNo
#undef tCurrPokeID
#undef tPokesNo
#undef tMonSpriteID
