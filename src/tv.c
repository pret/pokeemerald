
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
#include "tv.h"

// Static type declarations

// Static RAM declarations

extern EWRAM_DATA u8 sTVShowState;

// Static ROM declarations

extern const u8 *const gTVBravoTrainerTextGroup[];
extern const u8 *const gTVBravoTrainerBattleTowerTextGroup[];

void sub_80EEE5C(void);
u8 sub_80EFFE0(u8);
void CopyContestCategoryToStringVar(u8, u8);
void CopyContestRankToStringVar(u8, u8);
void TV_ConvertNumberToOrdinal(u8, u32);
u8 sub_80EC18C(void);
u8 CheckForBigMovieOrEmergencyNewsOnTV(void);
void SetTVMetatilesOnMap(int, int, u16);
bool8 sub_80EEF20(void);
bool8 IsTVShowInSearchOfTrainersAiring(void);

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
    sub_80EEE5C();
}

u8 special_0x44(void)
{
    u8 i;
    u8 j;
    u8 selIdx;
    struct TVShowMassOutbreak *massOutbreak;

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
        if (sub_80EFFE0(gSaveBlock1Ptr->tvShows[j].common.kind) != 4)
        {
            if (gSaveBlock1Ptr->tvShows[j].common.active == TRUE)
            {
                return j;
            }
        }
        else
        {
            massOutbreak = &gSaveBlock1Ptr->tvShows[j].massOutbreak;
            if (massOutbreak->var16 == 0 && massOutbreak->active == TRUE)
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

u8 sub_80EBFF4(void)
{
    u8 response;

    response = special_0x44();
    if (response == 0xFF)
    {
        return 0xFF;
    }
    if (gSaveBlock1Ptr->outbreakPokemonSpecies != SPECIES_NONE && gSaveBlock1Ptr->tvShows[response].common.kind == TVSHOW_MASS_OUTBREAK)
    {
        return sub_80EC18C();
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
            else if (FlagGet(SYS_TV_START) && (sub_80EBFF4() != 0xff || sub_80EEF20() != 0xff || IsTVShowInSearchOfTrainersAiring()))
            {
                FlagReset(SYS_TV_WATCH);
                SetTVMetatilesOnMap(width, height, 0x3);
            }
            break;
    }
}

void SetTVMetatilesOnMap(int width, int height, u16 tileId)
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

u8 sub_80EC18C(void)
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
        return sub_80EC18C();
    }
    return gSpecialVar_0x8004;
}

void ResetGabbyAndTy(void)
{
    gSaveBlock1Ptr->gabbyAndTyData.mon1 = SPECIES_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.mon2 = SPECIES_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.lastMove = MOVE_NONE;
    gSaveBlock1Ptr->gabbyAndTyData.quote[0] = -1;
    gSaveBlock1Ptr->gabbyAndTyData.valA_0 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_1 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_2 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_3 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_4 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valA_5 = 0;
    gSaveBlock1Ptr->gabbyAndTyData.valB_0 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_1 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_2 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_3 = FALSE;
    gSaveBlock1Ptr->gabbyAndTyData.valB_4 = 0;
    gSaveBlock1Ptr->gabbyAndTyData.mapnum = 0;
    gSaveBlock1Ptr->gabbyAndTyData.battleNum = 0;
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
    struct TVShowBravoTrainerPokemonProfiles *bravoTrainer;
    u8 state;

    bravoTrainer = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].bravoTrainer;
    gScriptResult = 0;
    state = sTVShowState;
    switch (state)
    {
        case 0:
            TVShowConvertInternationalString(gStringVar1, bravoTrainer->playerName, bravoTrainer->language);
            CopyContestCategoryToStringVar(1, bravoTrainer->contestCategory);
            CopyContestRankToStringVar(2, bravoTrainer->contestRank);
            if (!StringCompare(gSpeciesNames[bravoTrainer->species], bravoTrainer->pokemonNickname))
                sTVShowState = 8;
            else
                sTVShowState = 1;
            break;
        case 1:
            StringCopy(gStringVar1, gSpeciesNames[bravoTrainer->species]);
            TVShowConvertInternationalString(gStringVar2, bravoTrainer->pokemonNickname, bravoTrainer->pokemonNameLanguage);
            CopyContestCategoryToStringVar(2, bravoTrainer->contestCategory);
            sTVShowState = 2;
            break;
        case 2:
            TVShowConvertInternationalString(gStringVar1, bravoTrainer->playerName, bravoTrainer->language);
            if (bravoTrainer->contestResult == 0) // placed first
                sTVShowState = 3;
            else
                sTVShowState = 4;
            break;
        case 3:
            TVShowConvertInternationalString(gStringVar1, bravoTrainer->playerName, bravoTrainer->language);
            CopyEasyChatWord(gStringVar2, bravoTrainer->ecWords[0]);
            TV_ConvertNumberToOrdinal(2, bravoTrainer->contestResult + 1);
            sTVShowState = 5;
            break;
        case 4:
            TVShowConvertInternationalString(gStringVar1, bravoTrainer->playerName, bravoTrainer->language);
            CopyEasyChatWord(gStringVar2, bravoTrainer->ecWords[0]);
            TV_ConvertNumberToOrdinal(2, bravoTrainer->contestResult + 1);
            sTVShowState = 5;
            break;
        case 5:
            TVShowConvertInternationalString(gStringVar1, bravoTrainer->playerName, bravoTrainer->language);
            CopyContestCategoryToStringVar(1, bravoTrainer->contestCategory);
            CopyEasyChatWord(gStringVar3, bravoTrainer->ecWords[1]);
            if (bravoTrainer->move)
                sTVShowState = 6;
            else
                sTVShowState = 7;
            break;
        case 6:
            StringCopy(gStringVar1, gSpeciesNames[bravoTrainer->species]);
            StringCopy(gStringVar2, gMoveNames[bravoTrainer->move]);
            CopyEasyChatWord(gStringVar3, bravoTrainer->ecWords[1]);
            sTVShowState = 7;
            break;
        case 7:
            TVShowConvertInternationalString(gStringVar1, bravoTrainer->playerName, bravoTrainer->language);
            StringCopy(gStringVar2, gSpeciesNames[bravoTrainer->species]);
            TVShowDone();
            break;
        case 8:
            StringCopy(gStringVar1, gSpeciesNames[bravoTrainer->species]);
            sTVShowState = 2;
            break;
    }
    ShowFieldMessage(gTVBravoTrainerTextGroup[state]);
}

void DoTVShowBravoTrainerBattleTower(void)
{
    struct TVShowBravoTrainerBattleTowerSpotlight *bravoTrainerTower = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8004].bravoTrainerTower;
    u8 state;

    gScriptResult = 0;
    state = sTVShowState;
    switch(state)
    {
        case 0:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->trainerName, bravoTrainerTower->language);
            StringCopy(gStringVar2, gSpeciesNames[bravoTrainerTower->species]);
            if (bravoTrainerTower->numFights >= 7)
                sTVShowState = 1;
            else
                sTVShowState = 2;
            break;
        case 1:
            if (bravoTrainerTower->btLevel == 50)
            {
                StringCopy(gStringVar1, gText_Lv50);
            }
            else
            {
                StringCopy(gStringVar1, gText_OpenLevel);
            }
            TV_ConvertNumberToOrdinal(1, bravoTrainerTower->numFights);
            if (bravoTrainerTower->var1c == 1)
                sTVShowState = 3;
            else
                sTVShowState = 4;
            break;
        case 2:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->pokemonName, bravoTrainerTower->pokemonNameLanguage);
            TV_ConvertNumberToOrdinal(1, bravoTrainerTower->numFights + 1);
            if (bravoTrainerTower->var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 3:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->pokemonName, bravoTrainerTower->pokemonNameLanguage);
            StringCopy(gStringVar2, gSpeciesNames[bravoTrainerTower->defeatedSpecies]);
            if (bravoTrainerTower->var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 4:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->pokemonName, bravoTrainerTower->pokemonNameLanguage);
            StringCopy(gStringVar2, gSpeciesNames[bravoTrainerTower->defeatedSpecies]);
            if (bravoTrainerTower->var1b == 0)
                sTVShowState = 5;
            else
                sTVShowState = 6;
            break;
        case 5:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->pokemonName, bravoTrainerTower->pokemonNameLanguage);
            sTVShowState = 11;
            break;
        case 6:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->pokemonName, bravoTrainerTower->pokemonNameLanguage);
            sTVShowState = 11;
            break;
        case 7:
            sTVShowState = 11;
            break;
        case 8:
        case 9:
        case 10:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->trainerName, bravoTrainerTower->language);
            sTVShowState = 11;
            break;
        case 11:
            CopyEasyChatWord(gStringVar1, bravoTrainerTower->var18[0]);
            if (bravoTrainerTower->var1b == 0)
                sTVShowState = 12;
            else
                sTVShowState = 13;
            break;
        case 12:
        case 13:
            CopyEasyChatWord(gStringVar1, bravoTrainerTower->var18[0]);
            TVShowConvertInternationalString(gStringVar2, bravoTrainerTower->trainerName, bravoTrainerTower->language);
            TVShowConvertInternationalString(gStringVar3, bravoTrainerTower->pokemonName, bravoTrainerTower->pokemonNameLanguage);
            sTVShowState = 14;
            break;
        case 14:
            TVShowConvertInternationalString(gStringVar1, bravoTrainerTower->trainerName, bravoTrainerTower->language);
            StringCopy(gStringVar2, gSpeciesNames[bravoTrainerTower->species]);
            TVShowDone();
            break;
    }
    ShowFieldMessage(gTVBravoTrainerBattleTowerTextGroup[state]);
}
