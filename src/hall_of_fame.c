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

#define HALL_OF_FAME_MAX_TEAMS 50

// strings
extern const u8 gText_SavingDontTurnOffPower[];

extern void sub_81973C4(u8, u8);
extern u16 AddTextPrinterParametrized(u8 windowId, u8 fontId, const u8 *str, u8 speed, void ( *callback)(u16, struct TextPrinter *), u8 fgColor, u8 bgColor, u8 shadowColor);

// this file's functions
void sub_8174EC4(void);
void sub_8174F70(void);
void sub_8174FAC(void);
bool8 sub_8175024(void);
void sub_817371C(u8 taskId);
void sub_81738BC(u8 taskId);
void sub_8173A8C(u8 taskId);
void sub_81739C4(u8 taskId);
void sub_8173A5C(u8 taskId);
void sub_8173AA8(u8 taskId);
void sub_8173BC0(u8 taskId);
void sub_8175120(struct Sprite *sprite);

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

bool8 sub_817357C(void)
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

#define tData0              data[0]
#define tDisplayedPoke      data[1]
#define tPokesNumber        data[2]
#define tFrameCount         data[3]
#define tPlayerSpriteID     data[4]
#define tMonSpriteID(i)     data[i + 5]

void sub_8173694(void)
{
    if (!sub_817357C())
    {
        u8 taskId = CreateTask(sub_817371C, 0);
        gTasks[taskId].tData0 = 0;
        gHofMonsPtr = AllocZeroed(sizeof(*gHofMonsPtr));
    }
}

void sub_81736D8(void)
{
    if (!sub_817357C())
    {
        u8 taskId = CreateTask(sub_817371C, 0);
        gTasks[taskId].tData0 = 1;
        gHofMonsPtr = AllocZeroed(sizeof(*gHofMonsPtr));
    }
}

void sub_817371C(u8 taskId)
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
    gTasks[taskId].tDisplayedPoke = 0;
    gTasks[taskId].tPlayerSpriteID = 0xFF;

    for (i = 0; i < 6; i++)
    {
        gTasks[taskId].tMonSpriteID(i) = 0xFF;
    }

    if (gTasks[taskId].tData0)
        gTasks[taskId].func = sub_8173A8C;
    else
        gTasks[taskId].func = sub_81738BC;
}

void sub_81738BC(u8 taskId)
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
    gTasks[taskId].func = sub_81739C4;
}

extern u8 TrySavingData(u8);
extern MainCallback gGameContinueCallback;
extern u32 gDamagedSaveSectors;

void sub_81739C4(u8 taskId)
{
    gGameContinueCallback = sub_81736D8;
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
        gTasks[taskId].func = sub_8173A5C;
        gTasks[taskId].tFrameCount = 32;
    }
}

void sub_8173A5C(u8 taskId)
{
    if (gTasks[taskId].tFrameCount)
        gTasks[taskId].tFrameCount--;
    else
        gTasks[taskId].func = sub_8173A8C;
}

void sub_8173A8C(u8 taskId)
{
    gTasks[taskId].func = sub_8173AA8;
}

extern const s16 sHallOfFame_MonsFullTeamPositions[][4];
extern const s16 sHallOfFame_MonsHalfTeamPositions[][4];

extern u8 sub_818D3E4(u16 species, u32 trainerId, u32 personality, u8 flags, s16 x, s16 y, u8, u16);
extern void sub_8197434(u8, u8);

void sub_8173AA8(u8 taskId)
{
    u8 spriteId;
    s16 xPos, yPos, field4, field6;

    u16 currPokeID = gTasks[taskId].tDisplayedPoke;
    struct HallofFameMon* currMon = &gHofMonsPtr->mons[currPokeID];

    if (gTasks[taskId].tPokesNumber > 3)
    {
        xPos = sHallOfFame_MonsFullTeamPositions[currPokeID][0];
        yPos = sHallOfFame_MonsFullTeamPositions[currPokeID][1];
        field4 = sHallOfFame_MonsFullTeamPositions[currPokeID][2];
        field6 = sHallOfFame_MonsFullTeamPositions[currPokeID][3];
    }
    else
    {
        xPos = sHallOfFame_MonsHalfTeamPositions[currPokeID][0];
        yPos = sHallOfFame_MonsHalfTeamPositions[currPokeID][1];
        field4 = sHallOfFame_MonsHalfTeamPositions[currPokeID][2];
        field6 = sHallOfFame_MonsHalfTeamPositions[currPokeID][3];
    }

    if (currMon->species == SPECIES_EGG)
        field6 += 10;

    spriteId = sub_818D3E4(currMon->species, currMon->tid, currMon->personality, 1, xPos, yPos, currPokeID, 0xFFFF);
    gSprites[spriteId].data1 = field4;
    gSprites[spriteId].data2 = field6;
    gSprites[spriteId].data0 = 0;
    gSprites[spriteId].data7 = currMon->species;
    gSprites[spriteId].callback = sub_8175120;
    gTasks[taskId].tMonSpriteID(currPokeID) = spriteId;
    sub_8197434(0, 1);
    gTasks[taskId].func = sub_8173BC0;
}
