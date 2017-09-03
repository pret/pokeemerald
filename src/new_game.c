#include "global.h"
#include "new_game.h"
#include "rng.h"

extern u8 gPlayerPartyCount;
extern u8 gDifferentSaveFile;
extern u16 gSaveFileStatus;
extern u8 gUnknown_030060B0;

extern u16 GetGeneratedTrainerIdLower(void);
extern void ClearContestWinnerPicsInContestHall(void);
extern void warp1_set(s8 mapBank, s8 mapNo, s8 warpNo, s8 xPos, s8 yPos);
extern void warp_in(void);
extern void sub_80BB358(void);
extern void ZeroPlayerPartyMons(void);
extern void ZeroEnemyPartyMons(void);
extern void ResetBagScrollPositions(void);
extern void sub_813624C(void); // clears something pokeblock related
extern void ClearSav2(void); // clears something pokeblock related

void WriteUnalignedWord(u32 var, u8 *dataPtr)
{
    dataPtr[0] = var;
    dataPtr[1] = var >> 8;
    dataPtr[2] = var >> 16;
    dataPtr[3] = var >> 24;
}

u32 ReadUnalignedWord(u8* dataPtr)
{
    return (dataPtr[3] << 24) | (dataPtr[2] << 16) | (dataPtr[1] << 8) | (dataPtr[0]);
}

void CopyUnalignedWord(u8 *copyTo, u8 *copyFrom)
{
    s32 i;
    for (i = 0; i < 4; i++)
        copyTo[i] = copyFrom[i];
}

void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 0x10) | GetGeneratedTrainerIdLower();
    WriteUnalignedWord(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
void SetDefaultOptions(void)
{
    gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_MID;
    gSaveBlock2Ptr->optionsWindowFrameType = 0;
    gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_MONO;
    gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
}

void ClearPokedexFlags(void)
{
    gUnknown_030060B0 = 0;
    memset(&gSaveBlock2Ptr->pokedex.owned, 0, sizeof(gSaveBlock2Ptr->pokedex.owned));
    memset(&gSaveBlock2Ptr->pokedex.seen, 0, sizeof(gSaveBlock2Ptr->pokedex.seen));
}

extern const struct ContestWinner gContestWinnerPicDummy;

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();
    for (i = 8; i < 13; i++)
        gSaveBlock1Ptr->contestWinners[i] = gContestWinnerPicDummy;
}

void sub_8084400(void)
{
    // probably clearing one struct for battle frontier
    CpuFill32(0, gSaveBlock2Ptr->field_64C, 2272);

    // those look like strings
    gSaveBlock2Ptr->field_EE1 = 0xFF;
    gSaveBlock2Ptr->field_EE9 = 0xFF;
}

void WarpToTruck(void)
{
    warp1_set(25, 40, -1, -1, -1); // inside of truck
    warp_in();
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
}

void sub_808447C(void)
{
    gDifferentSaveFile = 0;
    sub_80BB358();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    sub_813624C();
}
/*
void NewGameInitData(void)
{
    Finish when more header files are available
}*/
