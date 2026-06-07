#ifndef GUARD_GLOBAL_TV_H
#define GUARD_GLOBAL_TV_H

#include "constants/tv.h"

typedef union // size = 0x24
{
    // Common
    struct {
        u8 kind;
        bool8 active;
        u8 data[26];
        u8 srcTrainerId3Lo;
        u8 srcTrainerId3Hi;
        u8 srcTrainerId2Lo;
        u8 srcTrainerId2Hi;
        u8 srcTrainerIdLo;
        u8 srcTrainerIdHi;
        u8 trainerIdLo;
        u8 trainerIdHi;
    } common;

    // Common init (used for initialization loop)
    struct {
        u8 kind;
        bool8 active;
        u8 data[34];
    } commonInit;

    // Local shows
    // TVSHOW_FAN_CLUB_LETTER
    struct {
        u8 kind;
        bool8 active;
        u16 species;
        u16 words[6];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 language;
        //u8 padding;
    } fanclubLetter;

    // TVSHOW_RECENT_HAPPENINGS
    struct {
        u8 kind;
        bool8 active;
        u16 species;
        u16 words[6];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 language;
        //u8 padding;
    } recentHappenings;

    // TVSHOW_PKMN_FAN_CLUB_OPINIONS
    struct {
        u8 kind;
        bool8 active;
        u16 species;
        u8 friendshipHighNybble:4;
        u8 questionAsked:4;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 language;
        u8 pokemonNameLanguage;
        u8 filler_0F[1];
        u8 nickname[PLAYER_NAME_LENGTH + 1];
        u16 words18[2];
        u16 words[2];
    } fanclubOpinions;

    // TVSHOW_DUMMY
    struct {
        u8 kind;
        bool8 active;
        u16 words[2];
        u16 species;
        u8 filler_08[3];
        u8 name[12];
        u8 language;
    } dummy;

    // TVSHOW_NAME_RATER_SHOW
    struct {
        u8 kind;
        bool8 active;
        u16 species;
        u8 pokemonName[POKEMON_NAME_LENGTH + 1];
        u8 trainerName[PLAYER_NAME_LENGTH + 1];
        u8 unused[3];
        u8 random;
        u8 random2;
        u16 randomSpecies;
        u8 language;
        u8 pokemonNameLanguage;
    } nameRaterShow;

    // TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE (contest)
    struct {
        u8 kind;
        bool8 active;
        u16 species;
        u16 words[2];
        u8 pokemonNickname[POKEMON_NAME_LENGTH + 1];
        u8 contestCategory:3;
        u8 contestRank:2;
        u8 contestResult:2;
        //u8 padding:1;
        u16 move;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 language;
        u8 pokemonNameLanguage;
    } bravoTrainer;

    // TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE
    struct {
        u8 kind;
        bool8 active;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u16 species;
        u8 opponentName[PLAYER_NAME_LENGTH + 1];
        u16 defeatedSpecies;
        u16 numFights;
        u16 words[1];
        u8 btLevel;
        u8 interviewResponse;
        bool8 wonTheChallenge;
        u8 playerLanguage;
        u8 opponentLanguage;
        //u8 padding;
    } bravoTrainerTower;

    // TVSHOW_CONTEST_LIVE_UPDATES
    struct {
        u8 kind;
        bool8 active;
        u16 losingSpecies;
        u8 losingTrainerName[PLAYER_NAME_LENGTH + 1];
        u8 loserAppealFlag;
        u8 round1Placing;
        u8 round2Placing;
        u8 winnerAppealFlag;
        u16 move;
        u16 winningSpecies;
        u8 winningTrainerName[PLAYER_NAME_LENGTH + 1];
        u8 category;
        u8 winningTrainerLanguage;
        u8 losingTrainerLanguage;
        //u8 padding;
    } contestLiveUpdates;

    // TVSHOW_3_CHEERS_FOR_POKEBLOCKS
    struct {
        u8 kind;
        bool8 active;
        u8 sheen;
        u8 flavor:3;
        u8 color:2;
        //u8 padding:3;
        u8 worstBlenderName[PLAYER_NAME_LENGTH + 1];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 language;
        u8 worstBlenderLanguage;
    } threeCheers;

    // TVSHOW_BATTLE_UPDATE
    struct {
        u8 kind;
        bool8 active;
        u16 speciesOpponent;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 linkOpponentName[PLAYER_NAME_LENGTH + 1];
        u16 move;
        u16 speciesPlayer;
        u8 battleType;
        u8 language;
        u8 linkOpponentLanguage;
        //u8 padding;
    } battleUpdate;

    // TVSHOW_FAN_CLUB_SPECIAL
    struct {
        u8 kind;
        bool8 active;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 idLo;
        u8 idHi;
        u8 idolName[PLAYER_NAME_LENGTH + 1];
        u16 words[1];
        u8 score;
        u8 language;
        u8 idolNameLanguage;
        //u8 padding;
    } fanClubSpecial;

    // TVSHOW_LILYCOVE_CONTEST_LADY
    struct {
        u8 kind;
        bool8 active;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 contestCategory;
        u8 nickname[POKEMON_NAME_LENGTH + 1];
        u8 pokeblockState;
        u8 language;
        u8 pokemonNameLanguage;
    } contestLady;

    // Record Mixing Shows
    // TVSHOW_POKEMON_TODAY_CAUGHT
    struct {
        u8 kind;
        bool8 active;
        u8 language;
        u8 language2;
        u8 nickname[POKEMON_NAME_LENGTH + 1];
        u8 ball;
        u16 species;
        u8 nBallsUsed;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } pokemonToday;

    // TVSHOW_SMART_SHOPPER
    struct {
        u8 kind;
        bool8 active;
        u8 priceReduced;
        u8 language;
        u8 filler_04[2];
        u16 itemIds[SMARTSHOPPER_NUM_ITEMS];
        u16 itemAmounts[SMARTSHOPPER_NUM_ITEMS];
        mapsec_u8_t shopLocation;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } smartshopperShow;

    // TVSHOW_POKEMON_TODAY_FAILED
    struct {
        u8 kind;
        bool8 active;
        u8 language;
        u8 filler_03[9];
        u16 species;
        u16 species2;
        u8 nBallsUsed;
        u8 outcome;
        mapsec_u8_t location;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } pokemonTodayFailed;

    // TVSHOW_FISHING_ADVICE
    struct {
        u8 kind;
        bool8 active;
        u8 nBites;
        u8 nFails;
        u16 species;
        u8 language;
        u8 filler_07[12];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } pokemonAngler;

    // TVSHOW_WORLD_OF_MASTERS
    struct {
        u8 kind;
        bool8 active;
        u16 numPokeCaught;
        u16 caughtPoke;
        u16 steps;
        u16 species;
        mapsec_u8_t location;
        u8 language;
        u8 filler_0C[7];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding2;
    } worldOfMasters;

    // TVSHOW_TODAYS_RIVAL_TRAINER
    struct {
        u8 kind;
        bool8 active;
        u16 dexCount;
        u8 badgeCount;
        u8 nSilverSymbols;
        u8 nGoldSymbols;
        mapsec_u8_t location;
        u16 battlePoints;
        u16 mapLayoutId;
        u8 language;
        u8 filler_0D[6];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding2;
    } rivalTrainer;

    // TVSHOW_TREND_WATCHER
    struct {
        u8 kind;
        bool8 active;
        u8 filler_02[2];
        u16 words[2];
        u8 gender;
        u8 language;
        u8 filler_0a[9];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } trendWatcher;

    // TVSHOW_TREASURE_INVESTIGATORS
    struct {
        u8 kind;
        bool8 active;
        u16 item;
        mapsec_u8_t location;
        u8 language;
        u16 mapLayoutId;
        u8 filler_08[11];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } treasureInvestigators;

    // TVSHOW_FIND_THAT_GAMER
    struct {
        u8 kind;
        bool8 active;
        u8 won;
        u8 whichGame;
        u16 nCoins;
        u8 filler_06[2];
        u8 language;
        u8 filler_09[10];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } findThatGamer;

    // TVSHOW_BREAKING_NEWS
    struct {
        u8 kind;
        bool8 active;
        u16 lastOpponentSpecies;
        mapsec_u8_t location;
        u8 outcome;
        u16 caughtMonBall;
        u16 balls;
        u16 poke1Species;
        u16 lastUsedMove;
        u8 language;
        u8 filler_0f[4];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } breakingNews;

    // TVSHOW_SECRET_BASE_VISIT
    struct {
        u8 kind;
        bool8 active;
        u8 avgLevel;
        u8 numDecorations;
        u8 decorations[4];
        u16 species;
        u16 move;
        u8 language;
        u8 filler_0d[6];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } secretBaseVisit;

    // TVSHOW_LOTTO_WINNER
    struct {
        u8 kind;
        bool8 active;
        u16 item;
        u8 whichPrize;
        u8 language;
        u8 filler_06[13];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } lottoWinner;

    // TVSHOW_BATTLE_SEMINAR
    struct {
        u8 kind;
        bool8 active;
        u16 move;
        u16 foeSpecies;
        u16 species;
        u16 otherMoves[3];
        u16 betterMove;
        u8 nOtherMoves;
        u8 language;
        u8 filler_12[1];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } battleSeminar;

    // TVSHOW_TRAINER_FAN_CLUB
    struct {
        u8 kind;
        bool8 active;
        u8 filler_02[2];
        u16 words[2];
        u8 language;
        u8 filler_09[10];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } trainerFanClub;

    // TVSHOW_CUTIES
    struct {
        u8 kind;
        bool8 active;
        u8 nRibbons;
        u8 selectedRibbon;
        u8 nickname[POKEMON_NAME_LENGTH + 1];
        u8 language;
        u8 pokemonNameLanguage;
        u8 filler_12[2];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
    } cuties;

    // TVSHOW_FRONTIER
    struct {
        u8 kind;
        bool8 active;
        u16 winStreak;
        u16 species1;
        u16 species2;
        u16 species3;
        u16 species4;
        u8 language;
        u8 facilityAndMode;
        u8 filler_0e[5];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } frontier;

    // TVSHOW_NUMBER_ONE
    struct {
        u8 kind;
        bool8 active;
        u16 count;
        u8 actionIdx;
        u8 language;
        u8 filler_06[13];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        //u8 padding;
    } numberOne;

    // TVSHOW_SECRET_BASE_SECRETS
    struct {
        u8 kind;
        bool8 active;
        u16 stepsInBase;
        u8 baseOwnersName[PLAYER_NAME_LENGTH + 1];
        u32 flags;
        u16 item;
        u8 savedState;
        u8 playerName[PLAYER_NAME_LENGTH + 1];
        u8 language;
        u8 baseOwnersNameLanguage;
        //u8 padding[3];
    } secretBaseSecrets;

    // TVSHOW_SAFARI_FAN_CLUB
    struct {
        u8 kind;
        bool8 active;
        u8 monsCaught;
        u8 pokeblocksUsed;
        u8 language;
        u8 filler_05[14];
        u8 playerName[PLAYER_NAME_LENGTH + 1];
    } safariFanClub;

    // Mass Outbreak
    // TVSHOW_MASS_OUTBREAK
    struct {
        u8 kind;
        bool8 active;
        u8 unused1;
        u8 unused3;
        u16 moves[MAX_MON_MOVES];
        u16 species;
        u16 unused2;
        u8 locationMapNum;
        u8 locationMapGroup;
        u8 unused4;
        u8 probability;
        u8 level;
        u8 unused5;
        u16 daysBeforeOutbreak;
        u8 language;
        //u8 padding;
    } massOutbreak;
} TVShow;

typedef struct
{
    u8 kind;
    u8 state;
    u16 dayCountdown;
} PokeNews;

struct GabbyAndTyData
{
    u16 mon1;
    u16 mon2;
    u16 lastMove;
    u16 quote[1];
    mapsec_u8_t mapnum;
    u8 battleNum;
    u8 battleTookMoreThanOneTurn:1;
    u8 playerLostAMon:1;
    u8 playerUsedHealingItem:1;
    u8 playerThrewABall:1;
    u8 onAir:1;
    u8 valA_5:3;
    u8 battleTookMoreThanOneTurn2:1;
    u8 playerLostAMon2:1;
    u8 playerUsedHealingItem2:1;
    u8 playerThrewABall2:1;
    u8 valB_4:4;
};

#endif //GUARD_GLOBAL_TV_H
