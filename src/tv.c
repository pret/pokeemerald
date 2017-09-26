
// Includes
#include "global.h"
#include "rng.h"
#include "event_data.h"
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

void sub_80EEE5C(void);
u8 sub_80EFFE0(u8);
void CopyContestCategoryToStringVar(u8, u8);
void CopyContestRankToStringVar(u8, u8);
void CopyContestResultToStringVar(u8, u8);

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
            CopyContestResultToStringVar(2, bravoTrainer->contestResult + 1);
            sTVShowState = 5;
            break;
        case 4:
            TVShowConvertInternationalString(gStringVar1, bravoTrainer->playerName, bravoTrainer->language);
            CopyEasyChatWord(gStringVar2, bravoTrainer->ecWords[0]);
            CopyContestResultToStringVar(2, bravoTrainer->contestResult + 1);
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
