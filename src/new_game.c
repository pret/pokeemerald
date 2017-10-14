#include "global.h"
#include "new_game.h"
#include "rng.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "tv.h"
#include "coins.h"
#include "text.h"

extern u8 gPlayerPartyCount;
extern u8 gDifferentSaveFile;
extern u16 gSaveFileStatus;
extern u8 gUnknown_030060B0;

// TODO: replace those declarations with file headers
extern u16 GetGeneratedTrainerIdLower(void);
extern void ClearContestWinnerPicsInContestHall(void);
extern void Overworld_SetWarpDestination(s8 mapBank, s8 mapNo, s8 warpNo, s8 xPos, s8 yPos);
extern void warp_in(void);
extern void sub_80BB358(void);
extern void ResetBagScrollPositions(void);
extern void sub_813624C(void); // clears something pokeblock related
extern void ResetPokedex(void);
extern void sub_8084400(void);
extern void ClearMailData(void);
extern void ResetGabbyAndTy(void);
extern void ResetSecretBases(void);
extern void ResetLinkContestBoolean(void);
extern void ResetGameStats(void);
extern void sub_8052DA8(void);
extern void InitLinkBattleRecords(void);
extern void ResetPokemonStorageSystem(void);
extern void ClearBag(void);
extern void NewGameInitPCItems(void);
extern void ClearDecorationInventories(void);
extern void ResetFanClub(void);
extern void copy_strings_to_sav1(void);
extern void sub_819FAA0(void);
extern void sub_81A4B14(void);
extern void sub_8195E10(void);
extern void sub_801AFD8(void);
extern void sub_800E5AC(void);
extern void sub_81D54BC(void);
extern void ResetContestLinkResults(void);
extern void ResetPokeJumpResults(void);
extern void SetBerryPowder(u32* powder, u32 newValue);

extern u8 gUnknown_082715DE[];

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

const struct ContestWinner gContestWinnerPicDummy = {
    .monName = _(""),
    .trainerName = _("")
};

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
    Overworld_SetWarpDestination(25, 40, -1, -1, -1); // inside of truck
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

void NewGameInitData(void)
{
    if (gSaveFileStatus == 0 || gSaveFileStatus == 2)
        RtcReset();

    gDifferentSaveFile = 1;
    gSaveBlock2Ptr->encryptionKey = 0;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetPokedex();
    sub_8084400();
    ClearSav1();
    ClearMailData();
    gSaveBlock2Ptr->specialSaveWarp = 0;
    gSaveBlock2Ptr->field_A8 = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    ClearPokedexFlags();
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ResetSecretBases();
    ClearBerryTrees();
    SetMoney(&gSaveBlock1Ptr->money, 3000);
    SetCoins(0);
    ResetLinkContestBoolean();
    ResetGameStats();
    ClearAllContestWinnerPics();
    InitLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    gPlayerPartyCount = 0;
    ZeroPlayerPartyMons();
    ResetPokemonStorageSystem();
    ClearRoamerData();
    ClearRoamerLocationData();
    gSaveBlock1Ptr->registeredItem = 0;
    ClearBag();
    NewGameInitPCItems();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    WarpToTruck();
    ScriptContext2_RunNewScript(gUnknown_082715DE);
    ResetMiniGamesResults();
    copy_strings_to_sav1();
	SetLilycoveLady();
	sub_819FAA0();
	sub_81A4B14();
	sub_8195E10();
	sub_801AFD8();
	sub_800E5AC();
	sub_81D54BC();
	ResetContestLinkResults();
}

void ResetMiniGamesResults(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokeJumpResults();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}
