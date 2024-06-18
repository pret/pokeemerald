#include "global.h"
#include "new_game.h"
#include "random.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "match_call.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "tv.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "pokedex.h"
#include "save.h"
#include "link_rfu.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_jump.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "player_pc.h"
#include "field_specials.h"
#include "berry_powder.h"
#include "mystery_gift.h"
#include "union_room_chat.h"
#include "constants/items.h"
#include "gba/isagbprint.h"

extern const u8 EventScript_ResetAllMapFlags[];

static void ClearFrontierRecord(void);
static void WarpToTruck(void);
static void ResetMiniGamesRecords(void);

EWRAM_DATA bool8 gDifferentSaveFile = FALSE;
EWRAM_DATA bool8 gEnableContestDebugging = FALSE;

EWRAM_DATA u8 newGameDexSeen[NUM_DEX_FLAG_BYTES];
EWRAM_DATA u8 newGameDexCaught[NUM_DEX_FLAG_BYTES];

void SavePokedexFlags(void)
{
    u16 i;
    for (i = 0; i < NUM_DEX_FLAG_BYTES; i++)
    {
        newGameDexCaught[i] = gSaveBlock1Ptr->dexCaught[i];
        newGameDexSeen[i] = gSaveBlock1Ptr->dexSeen[i];
    }
}

void ReloadPokedexFlags(void)
{
    u16 i;
    for (i = 0; i < NUM_DEX_FLAG_BYTES; i++)
    {
        gSaveBlock1Ptr->dexCaught[i] = newGameDexCaught[i];
        gSaveBlock1Ptr->dexSeen[i] = newGameDexSeen[i];
    }
}


static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

void SetTrainerId(u32 trainerId, u8 *dst)
{
    dst[0] = trainerId;
    dst[1] = trainerId >> 8;
    dst[2] = trainerId >> 16;
    dst[3] = trainerId >> 24;
}

u32 GetTrainerId(u8 *trainerId)
{
    return (trainerId[3] << 24) | (trainerId[2] << 16) | (trainerId[1] << 8) | (trainerId[0]);
}

void CopyTrainerId(u8 *dst, u8 *src)
{
    s32 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        dst[i] = src[i];
}

static void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 16) | Random();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
void SetDefaultOptions(void)
{
    int i, counter;

    //options
    if (GetNationalPokedexCount(FLAG_GET_CAUGHT) < 1)
    {
        gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_INSTANT;
        gSaveBlock2Ptr->optionsWindowFrameType = 0;

        gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_STEREO;
        gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SET;

        gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
        gSaveBlock2Ptr->regionMapZoom = FALSE;

        gSaveBlock2Ptr->optionsFollowMonsOff = FALSE;
    }
    
    //game modes
    if (GetNationalPokedexCount(FLAG_GET_CAUGHT) < 1)
    {
        gSaveBlock2Ptr->modeDefault = 0;
        gSaveBlock2Ptr->modeAutosave = 1;
        gSaveBlock2Ptr->modeBattleMode = 0;
        gSaveBlock2Ptr->modeRandomizer = 0;
        gSaveBlock2Ptr->modeXPShare = 0;
        gSaveBlock2Ptr->modeStatChanger = 0;
        gSaveBlock2Ptr->modeLegendaries = 0;
        gSaveBlock2Ptr->modeDuplicates = 1;
        gSaveBlock2Ptr->modeMegas = 1;
    }

    //set flags
    if (gSaveBlock2Ptr->optionsFollowMonsOff)
        FlagSet(FLAG_FOLLOWERS_OFF);
    else
        FlagClear(FLAG_FOLLOWERS_OFF);
}

static void ClearPokedexFlags(void)
{
    //gUnusedPokedexU8 = 0;
    //memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    //memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();

    // Clear Museum paintings
    for (i = MUSEUM_CONTEST_WINNERS_START; i < NUM_CONTEST_WINNERS; i++)
        gSaveBlock1Ptr->contestWinners[i] = sContestWinnerPicDummy;
}

static void ClearFrontierRecord(void)
{
    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = EOS;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = EOS;
}

static void WarpToTruck(void)
{
    SetWarpDestination(MAP_GROUP(PIT_ENTRANCE), MAP_NUM(PIT_ENTRANCE), WARP_ID_NONE, 9, 9);
    WarpIntoMap();
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
}

void ResetMenuAndMonGlobals(void)
{
    gDifferentSaveFile = FALSE;
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

void NewGameInitData(void)
{
    RtcReset();
    gDifferentSaveFile = TRUE;
    gSaveBlock2Ptr->encryptionKey = 0;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    SavePokedexFlags();
    //ResetPokedex();
    ClearFrontierRecord();
    ClearSav1();
    ClearSav3();
    ClearAllMail();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    //ClearPokedexFlags();
    InitEventData();
    ClearTVShowData();
    ResetGabbyAndTy();
    ClearSecretBases();
    ClearBerryTrees();
    SetMoney(&gSaveBlock1Ptr->money, 0);
    SetCoins(0);
    ResetLinkContestBoolean();
    ResetGameStats();
    ClearAllContestWinnerPics();
    ClearPlayerLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    gPlayerPartyCount = 0;
    ZeroPlayerPartyMons();
    ResetPokemonStorageSystem();
    ClearRoamerData();
    ClearRoamerLocationData();
    gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    ClearBag();
    NewGameInitPCItems();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    ReloadPokedexFlags();
    WarpToTruck();
    RunScriptImmediately(EventScript_ResetAllMapFlags);
    ResetMiniGamesRecords();
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    ClearMysteryGift();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetContestLinkResults();
}

static void ResetMiniGamesRecords(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokemonJumpRecords();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}
