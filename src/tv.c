
// Includes
#include "global.h"
#include "rng.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "field_message_box.h"
#include "easy_chat.h"
#include "species.h"
#include "moves.h"
#include "battle.h"
#include "contest.h"
#include "items.h"
#include "link.h"
#include "main.h"
#include "tv.h"

// Static type declarations

// Static RAM declarations

extern EWRAM_DATA u8 sTVShowState;
extern s8 sCurTVShowSlot;

// Static ROM declarations

extern const u8 *const gTVBravoTrainerTextGroup[];
extern const u8 *const gTVBravoTrainerBattleTowerTextGroup[];

void ClearPokemonNews(void);
u8 GetTVChannelByShowType(u8);
void CopyContestCategoryToStringVar(u8, u8);
void CopyContestRankToStringVar(u8, u8);
void TV_ConvertNumberToOrdinal(u8, u32);
static u8 FindFirstActiveTVShowThatIsNotAMassOutbreak(void);
u8 CheckForBigMovieOrEmergencyNewsOnTV(void);
static void SetTVMetatilesOnMap(int, int, u16);
u8 FindAnyTVNewsOnTheAir(void);
static bool8 IsTVShowInSearchOfTrainersAiring(void);
void TakeTVShowInSearchOfTrainersOffTheAir(void);

bool8 TV_BernoulliTrial(u16);
s8 FindEmptyTVSlotBeyondFirstFiveShowsOfArray(TVShow *);
bool8 sub_80EF46C(u8, u8);
void tv_store_id_3x(TVShow *);
void DeleteTVShowInArrayByIdx(TVShow *, u8);
s8 FindEmptyTVSlotWithinFirstFiveShowsOfArray(TVShow *);
void FindActiveBroadcastByShowType_SetScriptResult(u8);
void sub_80EF7B4(void);

// .rodata

// .text

void ClearTVShowData(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows); i ++)
    {
        gSaveBlock1Ptr->tvShows[i].common.kind = 0;
        gSaveBlock1Ptr->tvShows[i].common.active = 0;
        for (j = 0; j < sizeof(TVShow) - 2; j ++)
        {
            gSaveBlock1Ptr->tvShows[i].common.pad02[j] = 0;
        }
    }
    ClearPokemonNews();
}

u8 special_0x44(void)
{
    u8 i;
    u8 j;
    u8 selIdx;
    TVShow *show;

    for (i = 5; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 1; i ++)
    {
        if (gSaveBlock1Ptr->tvShows[i].common.kind == 0)
        {
            break;
        }
    }
    j = Random() % i;
    selIdx = j;
    do
    {
        if (GetTVChannelByShowType(gSaveBlock1Ptr->tvShows[j].common.kind) != 4)
        {
            if (gSaveBlock1Ptr->tvShows[j].common.active == TRUE)
            {
                return j;
            }
        }
        else
        {
            show = &gSaveBlock1Ptr->tvShows[j];
            if (show->massOutbreak.var16 == 0 && show->massOutbreak.active == TRUE)
            {
                return j;
            }
        }
        if (j == 0)
        {
            j = ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 2;
        }
        else
        {
            j --;
        }
    } while (j != selIdx);
    return 0xFF;
}

static u8 FindAnyTVShowOnTheAir(void)
{
    u8 response;

    response = special_0x44();
    if (response == 0xFF)
    {
        return 0xFF;
    }
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE && gSaveBlock1Ptr->tvShows[response].common.kind == TVSHOW_MASS_OUTBREAK)
    {
        return FindFirstActiveTVShowThatIsNotAMassOutbreak();
    }
    return response;
}

void UpdateTVScreensOnMap(int width, int height)
{
    FlagSet(SYS_TV_WATCH);
    switch (CheckForBigMovieOrEmergencyNewsOnTV())
    {
        case 1:
            SetTVMetatilesOnMap(width, height, 0x3);
            break;
        case 2:
            break;
        default:
            if (gSaveBlock1Ptr->location.mapGroup == 0x0d && gSaveBlock1Ptr->location.mapNum == 0x00)
            {
                SetTVMetatilesOnMap(width, height, 0x3);
            }
            else if (FlagGet(SYS_TV_START) && (FindAnyTVShowOnTheAir() != 0xff || FindAnyTVNewsOnTheAir() != 0xff || IsTVShowInSearchOfTrainersAiring()))
            {
                FlagReset(SYS_TV_WATCH);
                SetTVMetatilesOnMap(width, height, 0x3);
            }
            break;
    }
}

static void SetTVMetatilesOnMap(int width, int height, u16 tileId)
{
    int x;
    int y;

    for (y = 0; y < height; y ++)
    {
        for (x = 0; x < width; x ++)
        {
            if (MapGridGetMetatileBehaviorAt(x, y) == 0x86) // is this tile a TV?
            {
                MapGridSetMetatileIdAt(x, y, tileId | 0xc00);
            }
        }
    }
}

void TurnOffTVScreen(void)
{
    SetTVMetatilesOnMap(gUnknown_03005DC0.width, gUnknown_03005DC0.height, 0x0002);
    DrawWholeMapView();
}

void TurnOnTVScreen(void)
{
    SetTVMetatilesOnMap(gUnknown_03005DC0.width, gUnknown_03005DC0.height, 0x0003);
    DrawWholeMapView();
}

u8 special_0x45(void)
{
    return gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].common.kind;
}

static u8 FindFirstActiveTVShowThatIsNotAMassOutbreak(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows) - 1; i ++)
    {
        if (gSaveBlock1Ptr->tvShows[i].common.kind != 0 && gSaveBlock1Ptr->tvShows[i].common.kind != TVSHOW_MASS_OUTBREAK && gSaveBlock1Ptr->tvShows[i].common.active == TRUE)
        {
            return i;
        }
    }
    return 0xFF;
}

u8 special_0x4a(void)
{
    TVShow *tvShow;

    tvShow = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004];
    if (tvShow->common.kind == TVSHOW_MASS_OUTBREAK && gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE)
    {
        return FindFirstActiveTVShowThatIsNotAMassOutbreak();
    }
    return gSpecialVar_0x8004;
}

// IN SEARCH OF TRAINERS

void ResetGabbyAndTy(void)
{
    gSaveBlock1Ptr->gabbyAndTyData.mon1 = SPECIES_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.mon2 = SPECIES_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.lastMove = MOVE_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.quote[0] = -1;
    gSaveBlock1Ptr->gabbyAndTyData.valA_0 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.not_total_victory = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_2 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_3 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.onAir = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_5 = 0;
    gSaveBlock1Ptr->gabbyAndTyData.valB_0 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_1 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_2 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_3 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_4 = 0;
    gSaveBlock1Ptr->gabbyAndTyData.mapnum = 0;
    gSaveBlock1Ptr->gabbyAndTyData.battleNum = 0;
}

void GabbyAndTyBeforeInterview(void)
{
    u8 i;

    gSaveBlock1Ptr->gabbyAndTyData.mon1 = gBattleResults.poke1Species;
    gSaveBlock1Ptr->gabbyAndTyData.mon2 = gBattleResults.opponentSpecies;
    gSaveBlock1Ptr->gabbyAndTyData.lastMove = gBattleResults.lastUsedMove;
    if (gSaveBlock1Ptr->gabbyAndTyData.battleNum != 0xFF)
    {
        gSaveBlock1Ptr->gabbyAndTyData.battleNum ++;
    }
    gSaveBlock1Ptr->gabbyAndTyData.valA_0 = gBattleResults.unk5_0;
    if (gBattleResults.playerFaintCounter != 0)
    {
        gSaveBlock1Ptr->gabbyAndTyData.not_total_victory = TRUE;
    }
    else
    {
        gSaveBlock1Ptr->gabbyAndTyData.not_total_victory = FALSE;
    }
    if (gBattleResults.unk3 != 0)
    {
        gSaveBlock1Ptr->gabbyAndTyData.valA_2 = TRUE;
    }
    else
    {
        gSaveBlock1Ptr->gabbyAndTyData.valA_2 = FALSE;
    }
    if (!gBattleResults.usedMasterBall)
    {
        for (i = 0; i < 11; i ++)
        {
            if (gBattleResults.unk36[i])
            {
                gSaveBlock1Ptr->gabbyAndTyData.valA_3 = TRUE;
                break;
            }
        }
    }
    else
    {
        gSaveBlock1Ptr->gabbyAndTyData.valA_3 = TRUE;
    }
    TakeTVShowInSearchOfTrainersOffTheAir();
    if (gSaveBlock1Ptr->gabbyAndTyData.lastMove == MOVE_NONE)
    {
        FlagSet(0x0001);
    }
}

void GabbyAndTyAfterInterview(void)
{
    gSaveBlock1Ptr->gabbyAndTyData.valB_0 = gSaveBlock1Ptr->gabbyAndTyData.valA_0;
    gSaveBlock1Ptr->gabbyAndTyData.valB_1 = gSaveBlock1Ptr->gabbyAndTyData.not_total_victory;
    gSaveBlock1Ptr->gabbyAndTyData.valB_2 = gSaveBlock1Ptr->gabbyAndTyData.valA_2;
    gSaveBlock1Ptr->gabbyAndTyData.valB_3 = gSaveBlock1Ptr->gabbyAndTyData.valA_3;
    gSaveBlock1Ptr->gabbyAndTyData.onAir = TRUE;
    gSaveBlock1Ptr->gabbyAndTyData.mapnum = gMapHeader.regionMapSectionId;
    IncrementGameStat(GAME_STAT_GOT_INTERVIEWED);
}

void TakeTVShowInSearchOfTrainersOffTheAir(void)
{
    gSaveBlock1Ptr->gabbyAndTyData.onAir = FALSE;
}

u8 GabbyAndTyGetBattleNum(void)
{
    if (gSaveBlock1Ptr->gabbyAndTyData.battleNum > 5)
    {
        return (gSaveBlock1Ptr->gabbyAndTyData.battleNum % 3) + 6;
    }
    return gSaveBlock1Ptr->gabbyAndTyData.battleNum;
}

static bool8 IsTVShowInSearchOfTrainersAiring(void)
{
    return gSaveBlock1Ptr->gabbyAndTyData.onAir;
}

bool8 GabbyAndTyGetLastQuote(void)
{
    if (gSaveBlock1Ptr->gabbyAndTyData.quote[0] == 0xFFFF)
    {
        return FALSE;
    }
    CopyEasyChatWord(gStringVar1, gSaveBlock1Ptr->gabbyAndTyData.quote[0]);
    gSaveBlock1Ptr->gabbyAndTyData.quote[0] = -1;
    return TRUE;
}

u8 GabbyAndTyGetLastBattleTrivia(void)
{
    if (!gSaveBlock1Ptr->gabbyAndTyData.valB_0)
    {
        return 1;
    }
    if (gSaveBlock1Ptr->gabbyAndTyData.valB_3)
    {
        return 2;
    }
    if (gSaveBlock1Ptr->gabbyAndTyData.valB_2)
    {
        return 3;
    }
    if (gSaveBlock1Ptr->gabbyAndTyData.valB_1)
    {
        return 4;
    }
    return 0;
}

void GabbyAndTySetScriptVarsToFieldObjectLocalIds(void)
{
    switch (GabbyAndTyGetBattleNum())
    {
        case 1:
            gSpecialVar_0x8004 = 14;
            gSpecialVar_0x8005 = 13;
            break;
        case 2:
            gSpecialVar_0x8004 = 5;
            gSpecialVar_0x8005 = 6;
            break;
        case 3:
            gSpecialVar_0x8004 = 18;
            gSpecialVar_0x8005 = 17;
            break;
        case 4:
            gSpecialVar_0x8004 = 21;
            gSpecialVar_0x8005 = 22;
            break;
        case 5:
            gSpecialVar_0x8004 = 8;
            gSpecialVar_0x8005 = 9;
            break;
        case 6:
            gSpecialVar_0x8004 = 19;
            gSpecialVar_0x8005 = 20;
            break;
        case 7:
            gSpecialVar_0x8004 = 23;
            gSpecialVar_0x8005 = 24;
            break;
        case 8:
            gSpecialVar_0x8004 = 10;
            gSpecialVar_0x8005 = 11;
            break;
    }
}

void InterviewAfter(void)
{
    void InterviewAfter_FanClubLetter(void);
    void InterviewAfter_RecentHappenings(void);
    void InterviewAfter_PkmnFanClubOpinions(void);
    void InterviewAfter_DummyShow4(void);
    static void InterviewAfter_BravoTrainerPokemonProfile(void);
    void InterviewAfter_BravoTrainerBattleTowerProfile(void);
    static void InterviewAfter_ContestLiveUpdates(void);

    switch (gSpecialVar_0x8005)
    {
        case TVSHOW_FAN_CLUB_LETTER:
            InterviewAfter_FanClubLetter();
            break;
        case TVSHOW_RECENT_HAPPENINGS:
            InterviewAfter_RecentHappenings();
            break;
        case TVSHOW_PKMN_FAN_CLUB_OPINIONS:
            InterviewAfter_PkmnFanClubOpinions();
            break;
        case TVSHOW_UNKN_SHOWTYPE_04:
            InterviewAfter_DummyShow4();
            break;
        case TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE:
            InterviewAfter_BravoTrainerPokemonProfile();
            break;
        case TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE:
            InterviewAfter_BravoTrainerBattleTowerProfile();
            break;
        case TVSHOW_CONTEST_LIVE_UPDATES:
            InterviewAfter_ContestLiveUpdates();
            break;
    }
}

void PutPokemonTodayCaughtOnAir(void)
{
    static void UpdateWorldOfMastersAndPutItOnTheAir(void);
    static void PutPokemonTodayFailedOnTheAir(void);
    void sub_80ED718(void);
    void sub_80EED88(void);
    u8 i;
    u16 ct;
    TVShow *show;
    u32 language2;
    u16 itemLastUsed;

    ct = 0;
    sub_80EED88();
    sub_80ED718();
    if (gBattleResults.caughtPoke == SPECIES_NONE)
    {
        PutPokemonTodayFailedOnTheAir();
    }
    else
    {
        UpdateWorldOfMastersAndPutItOnTheAir();
        if (!TV_BernoulliTrial(-1) && StringCompare(gSpeciesNames[gBattleResults.caughtPoke], gBattleResults.caughtNick))
        {
            sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
            if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_POKEMON_TODAY_CAUGHT, 0) != TRUE)
            {
                for (i = 0; i < 11; i ++)
                {
                    ct += gBattleResults.unk36[i];
                }
                if (ct != 0 || gBattleResults.usedMasterBall)
                {
                    ct = 0;
                    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
                    show->pokemonToday.kind = TVSHOW_POKEMON_TODAY_CAUGHT;
                    show->pokemonToday.active = FALSE;
                    if (gBattleResults.usedMasterBall)
                    {
                        ct = 1;
                        itemLastUsed = ITEM_MASTER_BALL;
                    }
                    else
                    {
                        for (i = 0; i < 11; i ++)
                        {
                            ct += gBattleResults.unk36[i];
                        }
                        if (ct > 0xFF)
                        {
                            ct = 0xFF;
                        }
                        itemLastUsed = gLastUsedItem;
                    }
                    show->pokemonToday.var12 = ct;
                    show->pokemonToday.ball = itemLastUsed;
                    StringCopy(show->pokemonToday.playerName, gSaveBlock2Ptr->playerName);
                    StringCopy(show->pokemonToday.nickname, gBattleResults.caughtNick);
                    language2 = sub_81DB604(show->pokemonToday.nickname);
                    StripExtCtrlCodes(show->pokemonToday.nickname);
                    show->pokemonToday.species = gBattleResults.caughtPoke;
                    tv_store_id_3x(show);
                    show->pokemonToday.language = gGameLanguage;
                    show->pokemonToday.language2 = language2;
                }
            }
        }
    }
}

static void UpdateWorldOfMastersAndPutItOnTheAir(void)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (show->worldOfMasters.kind != TVSHOW_WORLD_OF_MASTERS)
    {
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
        show->worldOfMasters.steps = GetGameStat(GAME_STAT_STEPS);
        show->worldOfMasters.kind = TVSHOW_WORLD_OF_MASTERS;
    }
    show->worldOfMasters.var02 ++;
    show->worldOfMasters.caughtPoke = gBattleResults.caughtPoke;
    show->worldOfMasters.species = gBattleResults.poke1Species;
    show->worldOfMasters.location = gMapHeader.regionMapSectionId;
}

static void PutPokemonTodayFailedOnTheAir(void)
{
    u16 ct;
    u8 i;
    TVShow *show;

    if (!TV_BernoulliTrial(-1))
    {
        for (i = 0, ct = 0; i < 11; i ++)
        {
            ct += gBattleResults.unk36[i];
        }
        if (ct > 0xFF)
        {
            ct = 0xFF;
        }
        if (ct > 2 && (gBattleOutcome == 6 || gBattleOutcome == 1))
        {
            sCurTVShowSlot = FindEmptyTVSlotBeyondFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
            if (sCurTVShowSlot != -1 && sub_80EF46C(TVSHOW_POKEMON_TODAY_FAILED, 0) != TRUE)
            {
                show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
                show->pokemonTodayFailed.kind = TVSHOW_POKEMON_TODAY_FAILED;
                show->pokemonTodayFailed.active = FALSE;
                show->pokemonTodayFailed.species = gBattleResults.poke1Species;
                show->pokemonTodayFailed.species2 = gBattleResults.lastOpponentSpecies;
                show->pokemonTodayFailed.var10 = ct;
                show->pokemonTodayFailed.var11 = gBattleOutcome;
                show->pokemonTodayFailed.var12 = gMapHeader.regionMapSectionId;
                StringCopy(show->pokemonTodayFailed.playerName, gSaveBlock2Ptr->playerName);
                tv_store_id_3x(show);
                show->pokemonTodayFailed.language = gGameLanguage;
            }
        }
    }
}

void tv_store_id_3x(TVShow *show)
{
    u32 id;

    id = player_id_to_dword();
    show->common.srcTrainerId2Lo = id;
    show->common.srcTrainerId2Hi = id >> 8;
    show->common.srcTrainerIdLo = id;
    show->common.srcTrainerIdHi = id >> 8;
    show->common.trainerIdLo = id;
    show->common.trainerIdHi = id >> 8;
}

void tv_store_id_2x(TVShow *show)
{
    u32 id;

    id = player_id_to_dword();
    show->common.srcTrainerIdLo = id;
    show->common.srcTrainerIdHi = id >> 8;
    show->common.trainerIdLo = id;
    show->common.trainerIdHi = id >> 8;
}

static void InterviewAfter_ContestLiveUpdates(void)
{
    TVShow *show;
    TVShow *show2;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (show->contestLiveUpdates.kind == TVSHOW_CONTEST_LIVE_UPDATES)
    {
        show2 = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show2->contestLiveUpdates.kind = TVSHOW_CONTEST_LIVE_UPDATES;
        show2->contestLiveUpdates.active = TRUE;
        StringCopy(show2->contestLiveUpdates.playerName, gSaveBlock2Ptr->playerName);
        show2->contestLiveUpdates.unk_1c = gUnknown_02039F2C;
        show2->contestLiveUpdates.species = GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_SPECIES, NULL);
        show2->contestLiveUpdates.unk_02 = show->contestLiveUpdates.unk_02;
        show2->contestLiveUpdates.unk_0c = show->contestLiveUpdates.unk_0c;
        show2->contestLiveUpdates.unk_0d = show->contestLiveUpdates.unk_0d;
        show2->contestLiveUpdates.unk_0e = show->contestLiveUpdates.unk_0e;
        show2->contestLiveUpdates.unk_10 = show->contestLiveUpdates.unk_10;
        show2->contestLiveUpdates.unk_0f = show->contestLiveUpdates.unk_0f;
        StringCopy(show2->contestLiveUpdates.unk_04, show->contestLiveUpdates.unk_04);
        tv_store_id_2x(show2);
        show2->contestLiveUpdates.language = gGameLanguage;
        show2->contestLiveUpdates.unk_1e = show->contestLiveUpdates.unk_1e;
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
    }
}

void PutBattleUpdateOnTheAir(u8 a0, u16 a1, u16 a2, u16 a3)
{
    TVShow *show;
    u8 name[32];

    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        FindActiveBroadcastByShowType_SetScriptResult(TVSHOW_BATTLE_UPDATE);
        if (gScriptResult != 1)
        {
            show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
            show->battleUpdate.kind = TVSHOW_BATTLE_UPDATE;
            show->battleUpdate.active = TRUE;
            StringCopy(show->battleUpdate.playerName, gSaveBlock2Ptr->playerName);
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                show->battleUpdate.battleType = 2;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                show->battleUpdate.battleType = 1;
            }
            else
            {
                show->battleUpdate.battleType = 0;
            }
            show->battleUpdate.unk_14 = a1;
            show->battleUpdate.unk_16 = a2;
            show->battleUpdate.unk_02 = a3;
            StringCopy(name, gLinkPlayers[a0].name);
            StripExtCtrlCodes(name);
            StringCopy(show->battleUpdate.linkOpponentName, name);
            tv_store_id_2x(show);
            show->battleUpdate.language = gGameLanguage;
            if (show->battleUpdate.language == LANGUAGE_JAPANESE || gLinkPlayers[a0].language == LANGUAGE_JAPANESE)
            {
                show->battleUpdate.unk_1a = LANGUAGE_JAPANESE;
            }
            else
            {
                show->battleUpdate.unk_1a = gLinkPlayers[a0].language;
            }
        }
    }
}

bool8 Put3CheersForPokeblocksOnTheAir(const u8 *a0, u8 a1, u8 a2, u8 a3, u8 language)
{
    TVShow *show;
    u8 name[32];

    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot == -1)
    {
        return FALSE;
    }
    FindActiveBroadcastByShowType_SetScriptResult(TVSHOW_3_CHEERS_FOR_POKEBLOCKS);
    if (gScriptResult == 1)
    {
        return FALSE;
    }
    show = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
    show->threeCheers.kind = TVSHOW_3_CHEERS_FOR_POKEBLOCKS;
    show->threeCheers.active = TRUE;
    StringCopy(show->threeCheers.playerName, gSaveBlock2Ptr->playerName);
    StringCopy(name, a0);
    StripExtCtrlCodes(name);
    StringCopy(show->threeCheers.unk_04, name);
    show->threeCheers.unk_03_0 = a1;
    show->threeCheers.unk_03_3 = a2;
    show->threeCheers.unk_02 = a3;
    tv_store_id_2x(show);
    show->threeCheers.language = gGameLanguage;
    if (show->threeCheers.language == LANGUAGE_JAPANESE || language == LANGUAGE_JAPANESE)
    {
        show->threeCheers.unk_15 = LANGUAGE_JAPANESE;
    }
    else
    {
        show->threeCheers.unk_15 = language;
    }
    return TRUE;
}

void PutFanClubSpecialOnTheAir(void)
{
    TVShow *show;
    u8 name[32];
    u32 id;

    show = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8006];
    show->fanClubSpecial.unk_16 = gSpecialVar_0x8005 * 10;
    StringCopy(show->fanClubSpecial.playerName, gSaveBlock2Ptr->playerName);
    show->fanClubSpecial.kind = TVSHOW_FAN_CLUB_SPECIAL;
    show->fanClubSpecial.active = TRUE;
    id = player_id_to_dword();
    show->fanClubSpecial.idLo = id;
    show->fanClubSpecial.idHi = id >> 8;
    StringCopy(name, gStringVar1);
    StripExtCtrlCodes(name);
    StringCopy(show->fanClubSpecial.unk_0c, name);
    tv_store_id_2x(show);
    show->fanClubSpecial.language = gGameLanguage;
    if (show->fanClubSpecial.language == LANGUAGE_JAPANESE || gSaveBlock1Ptr->unk_31A0 == LANGUAGE_JAPANESE)
    {
        show->fanClubSpecial.unk_18 = LANGUAGE_JAPANESE;
    }
    else
    {
        show->fanClubSpecial.unk_18 = gSaveBlock1Ptr->unk_31A0;
    }
}

void ContestLiveUpdates_BeforeInterview_1(u8 a0)
{
    TVShow *show;

    DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show = &gSaveBlock1Ptr->tvShows[24];
        show->contestLiveUpdates.unk_0d = a0;
        show->contestLiveUpdates.kind = TVSHOW_CONTEST_LIVE_UPDATES;
    }
}

void ContestLiveUpdates_BeforeInterview_2(u8 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_0e = a0;
    }
}

void ContestLiveUpdates_BeforeInterview_3(u8 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_0f = a0;
    }
}

void ContestLiveUpdates_BeforeInterview_4(u16 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_10 = a0;
    }
}

void ContestLiveUpdates_BeforeInterview_5(u8 a0, u8 a1)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->contestLiveUpdates.unk_02 = gUnknown_02039E00[a1].unk_00;
        StringCopy(show->contestLiveUpdates.unk_04, gUnknown_02039E00[a1].unk_0d);
        StripExtCtrlCodes(show->contestLiveUpdates.unk_04);
        show->contestLiveUpdates.unk_0c = a0;
        if (a1 + 1 > gUnknown_02039F30)
        {
            show->contestLiveUpdates.unk_1e = gLinkPlayers[0].language;
        }
        else if (gGameLanguage == LANGUAGE_JAPANESE || gLinkPlayers[a1].language == LANGUAGE_JAPANESE)
        {
            show->contestLiveUpdates.unk_1e = LANGUAGE_JAPANESE;
        }
        else
        {
            show->contestLiveUpdates.unk_1e = gLinkPlayers[a1].language;
        }
    }
}

static void InterviewAfter_BravoTrainerPokemonProfile(void)
{
    TVShow *show;
    TVShow *show2;

    show = &gSaveBlock1Ptr->tvShows[24];
    if (show->bravoTrainer.kind == TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE)
    {
        show2 = &gSaveBlock1Ptr->tvShows[sCurTVShowSlot];
        show2->bravoTrainer.kind = TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE;
        show2->bravoTrainer.active = TRUE;
        show2->bravoTrainer.species = show->bravoTrainer.species;
        StringCopy(show2->bravoTrainer.playerName, gSaveBlock2Ptr->playerName);
        StringCopy(show2->bravoTrainer.pokemonNickname, show->bravoTrainer.pokemonNickname);
        show2->bravoTrainer.contestCategory = show->bravoTrainer.contestCategory;
        show2->bravoTrainer.contestRank = show->bravoTrainer.contestRank;
        show2->bravoTrainer.move = show->bravoTrainer.move;
        show2->bravoTrainer.contestResult = show->bravoTrainer.contestResult;
        show2->bravoTrainer.contestCategory = show->bravoTrainer.contestCategory;
        tv_store_id_2x(show2);
        show2->bravoTrainer.language = gGameLanguage;
        if (show2->bravoTrainer.language == LANGUAGE_JAPANESE || show->bravoTrainer.pokemonNameLanguage == LANGUAGE_JAPANESE)
        {
            show2->bravoTrainer.pokemonNameLanguage = LANGUAGE_JAPANESE;
        }
        else
        {
            show2->bravoTrainer.pokemonNameLanguage = show->bravoTrainer.pokemonNameLanguage;
        }
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
    }
}

void BravoTrainerPokemonProfile_BeforeInterview1(u16 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sub_80EF7B4();
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        DeleteTVShowInArrayByIdx(gSaveBlock1Ptr->tvShows, 24);
        show->bravoTrainer.move = a0;
        show->bravoTrainer.kind = TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE;
    }
}

void BravoTrainerPokemonProfile_BeforeInterview2(u8 a0)
{
    TVShow *show;

    show = &gSaveBlock1Ptr->tvShows[24];
    sCurTVShowSlot = FindEmptyTVSlotWithinFirstFiveShowsOfArray(gSaveBlock1Ptr->tvShows);
    if (sCurTVShowSlot != -1)
    {
        show->bravoTrainer.contestResult = a0;
        show->bravoTrainer.contestCategory = gUnknown_02039F2C;
        show->bravoTrainer.contestRank = gUnknown_02039F2E;
        show->bravoTrainer.species = GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_SPECIES, NULL);
        GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_NICKNAME, show->bravoTrainer.pokemonNickname);
        StripExtCtrlCodes(show->bravoTrainer.pokemonNickname);
        show->bravoTrainer.pokemonNameLanguage = GetMonData(&gPlayerParty[gUnknown_02039F24], MON_DATA_LANGUAGE);
    }
}

asm(".section .text.dotvshow");

void TVShowDone(void);

void DoTVShow(void)
{
    void DoTVShowPokemonFanClubLetter(void);
    void DoTVShowRecentHappenings(void);
    void DoTVShowPokemonFanClubOpinions(void);
    void DoTVShowDummiedOut(void);
    void DoTVShowPokemonNewsMassOutbreak(void);
    void DoTVShowBravoTrainerPokemonProfile(void);
    void DoTVShowBravoTrainerBattleTower(void);
    void DoTVShowPokemonTodaySuccessfulCapture(void);
    void DoTVShowTodaysSmartShopper(void);
    void DoTVShowTheNameRaterShow(void);
    void DoTVShowPokemonContestLiveUpdates(void);
    void DoTVShowPokemonBattleUpdate(void);
    void DoTVShow3CheersForPokeblocks(void);
    void DoTVShowPokemonTodayFailedCapture(void);
    void DoTVShowPokemonAngler(void);
    void DoTVShowTheWorldOfMasters(void);
    void DoTVShowTodaysRivalTrainer(void);
    void DoTVShowDewfordTrendWatcherNetwork(void);
    void DoTVShowHoennTreasureInvestigators(void);
    void DoTVShowFindThatGamer(void);
    void DoTVShowBreakingNewsTV(void);
    void DoTVShowSecretBaseVisit(void);
    void DoTVShowPokemonLotterWinnerFlashReport(void);
    void DoTVShowThePokemonBattleSeminar(void);
    void DoTVShowTrainerFanClubSpecial(void);
    void DoTVShowTrainerFanClub(void);
    void DoTVShowSpotTheCuties(void);
    void DoTVShowPokemonNewsBattleFrontier(void);
    void DoTVShowWhatsNo1InHoennToday(void);
    void DoTVShowSecretBaseSecrets(void);
    void DoTVShowSafariFanClub(void);
    void DoTVShowPokemonContestLiveUpdates2(void);

    if (gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].common.active)
    {
        switch (gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].common.kind)
        {
            case TVSHOW_FAN_CLUB_LETTER:
                DoTVShowPokemonFanClubLetter();
                break;
            case TVSHOW_RECENT_HAPPENINGS:
                DoTVShowRecentHappenings();
                break;
            case TVSHOW_PKMN_FAN_CLUB_OPINIONS:
                DoTVShowPokemonFanClubOpinions();
                break;
            case TVSHOW_UNKN_SHOWTYPE_04:
                DoTVShowDummiedOut();
                break;
            case TVSHOW_MASS_OUTBREAK:
                DoTVShowPokemonNewsMassOutbreak();
                break;
            case TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE:
                DoTVShowBravoTrainerPokemonProfile();
                break;
            case TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE:
                DoTVShowBravoTrainerBattleTower();
                break;
            case TVSHOW_POKEMON_TODAY_CAUGHT:
                DoTVShowPokemonTodaySuccessfulCapture();
                break;
            case TVSHOW_SMART_SHOPPER:
                DoTVShowTodaysSmartShopper();
                break;
            case TVSHOW_NAME_RATER_SHOW:
                DoTVShowTheNameRaterShow();
                break;
            case TVSHOW_CONTEST_LIVE_UPDATES:
                DoTVShowPokemonContestLiveUpdates();
                break;
            case TVSHOW_BATTLE_UPDATE:
                DoTVShowPokemonBattleUpdate();
                break;
            case TVSHOW_3_CHEERS_FOR_POKEBLOCKS:
                DoTVShow3CheersForPokeblocks();
                break;
            case TVSHOW_POKEMON_TODAY_FAILED:
                DoTVShowPokemonTodayFailedCapture();
                break;
            case TVSHOW_FISHING_ADVICE:
                DoTVShowPokemonAngler();
                break;
            case TVSHOW_WORLD_OF_MASTERS:
                DoTVShowTheWorldOfMasters();
                break;
            case TVSHOW_TODAYS_RIVAL_TRAINER:
                DoTVShowTodaysRivalTrainer();
                break;
            case TVSHOW_TREND_WATCHER:
                DoTVShowDewfordTrendWatcherNetwork();
                break;
            case TVSHOW_TREASURE_INVESTIGATORS:
                DoTVShowHoennTreasureInvestigators();
                break;
            case TVSHOW_FIND_THAT_GAMER:
                DoTVShowFindThatGamer();
                break;
            case TVSHOW_BREAKING_NEWS:
                DoTVShowBreakingNewsTV();
                break;
            case TVSHOW_SECRET_BASE_VISIT:
                DoTVShowSecretBaseVisit();
                break;
            case TVSHOW_LOTTO_WINNER:
                DoTVShowPokemonLotterWinnerFlashReport();
                break;
            case TVSHOW_BATTLE_SEMINAR:
                DoTVShowThePokemonBattleSeminar();
                break;
            case TVSHOW_FAN_CLUB_SPECIAL:
                DoTVShowTrainerFanClubSpecial();
                break;
            case TVSHOW_TRAINER_FAN_CLUB:
                DoTVShowTrainerFanClub();
                break;
            case TVSHOW_CUTIES:
                DoTVShowSpotTheCuties();
                break;
            case TVSHOW_FRONTIER:
                DoTVShowPokemonNewsBattleFrontier();
                break;
            case TVSHOW_NUMBER_ONE:
                DoTVShowWhatsNo1InHoennToday();
                break;
            case TVSHOW_SECRET_BASE_SECRETS:
                DoTVShowSecretBaseSecrets();
                break;
            case TVSHOW_SAFARI_FAN_CLUB:
                DoTVShowSafariFanClub();
                break;
            case TVSHOW_CONTEST_LIVE_UPDATES_2:
                DoTVShowPokemonContestLiveUpdates2();
                break;
        }
    }
}

void DoTVShowBravoTrainerPokemonProfile(void)
{
    TVShow *show;
    u8 state;

    show = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004];
    gScriptResult = 0;
    state = sTVShowState;
    switch (state)
    {
        case 0:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyContestCategoryToStringVar(1, show->bravoTrainer.contestCategory);
            CopyContestRankToStringVar(2, show->bravoTrainer.contestRank);
            if (!StringCompare(gSpeciesNames[show->bravoTrainer.species], show->bravoTrainer.pokemonNickname))
                sTVShowState = 8;
            else
                sTVShowState = 1;
            break;
        case 1:
            StringCopy(gStringVar1, gSpeciesNames[show->bravoTrainer.species]);
            TVShowConvertInternationalString(gStringVar2, show->bravoTrainer.pokemonNickname, show->bravoTrainer.pokemonNameLanguage);
            CopyContestCategoryToStringVar(2, show->bravoTrainer.contestCategory);
            sTVShowState = 2;
            break;
        case 2:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            if (show->bravoTrainer.contestResult == 0) // placed first
                sTVShowState = 3;
            else
                sTVShowState = 4;
            break;
        case 3:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyEasyChatWord(gStringVar2, show->bravoTrainer.ecWords[0]);
            TV_ConvertNumberToOrdinal(2, show->bravoTrainer.contestResult + 1);
            sTVShowState = 5;
            break;
        case 4:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyEasyChatWord(gStringVar2, show->bravoTrainer.ecWords[0]);
            TV_ConvertNumberToOrdinal(2, show->bravoTrainer.contestResult + 1);
            sTVShowState = 5;
            break;
        case 5:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            CopyContestCategoryToStringVar(1, show->bravoTrainer.contestCategory);
            CopyEasyChatWord(gStringVar3, show->bravoTrainer.ecWords[1]);
            if (show->bravoTrainer.move)
                sTVShowState = 6;
            else
                sTVShowState = 7;
            break;
        case 6:
            StringCopy(gStringVar1, gSpeciesNames[show->bravoTrainer.species]);
            StringCopy(gStringVar2, gMoveNames[show->bravoTrainer.move]);
            CopyEasyChatWord(gStringVar3, show->bravoTrainer.ecWords[1]);
            sTVShowState = 7;
            break;
        case 7:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainer.playerName, show->bravoTrainer.language);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainer.species]);
            TVShowDone();
            break;
        case 8:
            StringCopy(gStringVar1, gSpeciesNames[show->bravoTrainer.species]);
            sTVShowState = 2;
            break;
    }
    ShowFieldMessage(gTVBravoTrainerTextGroup[state]);
}

void DoTVShowBravoTrainerBattleTower(void)
{
    TVShow *show;
    u8 state;

    show = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004];
    gScriptResult = 0;
    state = sTVShowState;
    switch(state)
    {
        case 0:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.species]);
            if (show->bravoTrainerTower.numFights >= 7)
                sTVShowState = 1;
            else
                sTVShowState = 2;
            break;
        case 1:
            if (show->bravoTrainerTower.btLevel == 50)
            {
                StringCopy(gStringVar1, gText_Lv50);
            }
            else
            {
                StringCopy(gStringVar1, gText_OpenLevel);
            }
            TV_ConvertNumberToOrdinal(1, show->bravoTrainerTower.numFights);
            if (show->bravoTrainerTower.var1c == 1)
                sTVShowState = 3;
            else
                sTVShowState = 4;
            break;
        case 2:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            TV_ConvertNumberToOrdinal(1, show->bravoTrainerTower.numFights + 1);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 3:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.defeatedSpecies]);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 4:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.defeatedSpecies]);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 5:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            sTVShowState = 11;
            break;
        case 6:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            sTVShowState = 11;
            break;
        case 7:
            sTVShowState = 11;
            break;
        case 8:
        case 9:
        case 10:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            sTVShowState = 11;
            break;
        case 11:
            CopyEasyChatWord(gStringVar1, show->bravoTrainerTower.var18[0]);
            if (show->bravoTrainerTower.var1b == 0)
                sTVShowState = 12;
            else
                sTVShowState = 13;
            break;
        case 12:
        case 13:
            CopyEasyChatWord(gStringVar1, show->bravoTrainerTower.var18[0]);
            TVShowConvertInternationalString(gStringVar2, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            TVShowConvertInternationalString(gStringVar3, show->bravoTrainerTower.pokemonName, show->bravoTrainerTower.pokemonNameLanguage);
            sTVShowState = 14;
            break;
        case 14:
            TVShowConvertInternationalString(gStringVar1, show->bravoTrainerTower.trainerName, show->bravoTrainerTower.language);
            StringCopy(gStringVar2, gSpeciesNames[show->bravoTrainerTower.species]);
            TVShowDone();
            break;
    }
    ShowFieldMessage(gTVBravoTrainerBattleTowerTextGroup[state]);
}
