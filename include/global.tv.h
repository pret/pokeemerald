#ifndef GUARD_GLOBAL_TV_H
#define GUARD_GLOBAL_TV_H

#include "constants/tv.h"

typedef union // size = 0x24
{
    // Common
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 data[26];
        /*0x1C*/ u8 srcTrainerId3Lo;
        /*0x1D*/ u8 srcTrainerId3Hi;
        /*0x1E*/ u8 srcTrainerId2Lo;
        /*0x1F*/ u8 srcTrainerId2Hi;
        /*0x20*/ u8 srcTrainerIdLo;
        /*0x21*/ u8 srcTrainerIdHi;
        /*0x22*/ u8 trainerIdLo;
        /*0x23*/ u8 trainerIdHi;
    } common;

    // Common init (used for initialization loop)
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 data[34];
    } commonInit;

    // Local shows
    // TVSHOW_FAN_CLUB_LETTER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u16 words[6];
        /*0x10*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x18*/ u8 language;
        /*0x19*/ //u8 padding;
    } fanclubLetter;

    // TVSHOW_RECENT_HAPPENINGS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u16 words[6];
        /*0x10*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x18*/ u8 language;
        /*0x19*/ //u8 padding;
    } recentHappenings;

    // TVSHOW_PKMN_FAN_CLUB_OPINIONS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u8 friendshipHighNybble:4;
                 u8 questionAsked:4;
        /*0x05*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x0D*/ u8 language;
        /*0x0E*/ u8 pokemonNameLanguage;
        /*0x0F*/ u8 filler_0F[1];
        /*0x10*/ u8 nickname[PLAYER_NAME_LENGTH + 1];
        /*0x18*/ u16 words18[2];
        /*0x1C*/ u16 words[2];
    } fanclubOpinions;

    // TVSHOW_DUMMY
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 words[2];
        /*0x06*/ u16 species;
        /*0x08*/ u8 filler_08[3];
        /*0x0B*/ u8 name[12];
        /*0x17*/ u8 language;
    } dummy;

    // TVSHOW_NAME_RATER_SHOW
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u8 pokemonName[VANILLA_POKEMON_NAME_LENGTH + 1];
        /*0x0F*/ u8 trainerName[PLAYER_NAME_LENGTH + 1];
        /*0x17*/ u8 unused[3];
        /*0x1A*/ u8 random;
        /*0x1B*/ u8 random2;
        /*0x1C*/ u16 randomSpecies;
        /*0x1E*/ u8 language;
        /*0x1F*/ u8 pokemonNameLanguage;
    } nameRaterShow;

    // TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE (contest)
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u16 words[2];
        /*0x08*/ u8 pokemonNickname[VANILLA_POKEMON_NAME_LENGTH + 1];
        /*0x13*/ u8 contestCategory:3;
                 u8 contestRank:2;
                 u8 contestResult:2;
                 //u8 padding:1;
        /*0x14*/ u16 move;
        /*0x16*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1E*/ u8 language;
        /*0x1F*/ u8 pokemonNameLanguage;
    } bravoTrainer;

    // TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x0A*/ u16 species;
        /*0x0C*/ u8 opponentName[PLAYER_NAME_LENGTH + 1];
        /*0x14*/ u16 defeatedSpecies;
        /*0x16*/ u16 numFights;
        /*0x18*/ u16 words[1];
        /*0x1A*/ u8 btLevel;
        /*0x1B*/ u8 interviewResponse;
        /*0x1C*/ bool8 wonTheChallenge;
        /*0x1D*/ u8 playerLanguage;
        /*0x1E*/ u8 opponentLanguage;
        /*0x1F*/ //u8 padding;
    } bravoTrainerTower;

    // TVSHOW_CONTEST_LIVE_UPDATES
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 losingSpecies;
        /*0x04*/ u8 losingTrainerName[PLAYER_NAME_LENGTH + 1];
        /*0x0C*/ u8 loserAppealFlag;
        /*0x0D*/ u8 round1Placing;
        /*0x0E*/ u8 round2Placing;
        /*0x0F*/ u8 winnerAppealFlag;
        /*0x10*/ u16 move;
        /*0x12*/ u16 winningSpecies;
        /*0x14*/ u8 winningTrainerName[PLAYER_NAME_LENGTH + 1];
        /*0x1C*/ u8 category;
        /*0x1D*/ u8 winningTrainerLanguage;
        /*0x1E*/ u8 losingTrainerLanguage;
        /*0x1F*/ //u8 padding;
    } contestLiveUpdates;

    // TVSHOW_3_CHEERS_FOR_POKEBLOCKS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 sheen;
        /*0x03*/ u8 flavor:3;
                 u8 color:2;
                 //u8 padding:3;
        /*0x04*/ u8 worstBlenderName[PLAYER_NAME_LENGTH + 1];
        /*0x0C*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x14*/ u8 language;
        /*0x15*/ u8 worstBlenderLanguage;
    } threeCheers;

    // TVSHOW_BATTLE_UPDATE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 speciesOpponent;
        /*0x04*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x0C*/ u8 linkOpponentName[PLAYER_NAME_LENGTH + 1];
        /*0x14*/ u16 move;
        /*0x16*/ u16 speciesPlayer;
        /*0x18*/ u8 battleType;
        /*0x19*/ u8 language;
        /*0x1A*/ u8 linkOpponentLanguage;
        /*0x1B*/ //u8 padding;
    } battleUpdate;

    // TVSHOW_FAN_CLUB_SPECIAL
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x0A*/ u8 idLo;
        /*0x0B*/ u8 idHi;
        /*0x0C*/ u8 idolName[PLAYER_NAME_LENGTH + 1];
        /*0x14*/ u16 words[1];
        /*0x16*/ u8 score;
        /*0x17*/ u8 language;
        /*0x18*/ u8 idolNameLanguage;
        /*0x19*/ //u8 padding;
    } fanClubSpecial;

    // TVSHOW_LILYCOVE_CONTEST_LADY
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x0A*/ u8 contestCategory;
        /*0x0B*/ u8 nickname[VANILLA_POKEMON_NAME_LENGTH + 1];
        /*0x16*/ u8 pokeblockState;
        /*0x17*/ u8 language;
        /*0x18*/ u8 pokemonNameLanguage;
    } contestLady;

    // Record Mixing Shows
    // TVSHOW_POKEMON_TODAY_CAUGHT
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 language;
        /*0x03*/ u8 language2;
        /*0x04*/ u8 nickname[VANILLA_POKEMON_NAME_LENGTH + 1];
        /*0x0F*/ u8 ball;
        /*0x10*/ u16 species;
        /*0x12*/ u8 nBallsUsed;
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } pokemonToday;

    // TVSHOW_SMART_SHOPPER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 priceReduced;
        /*0x03*/ u8 language;
        /*0x04*/ u8 filler_04[2];
        /*0x06*/ u16 itemIds[SMARTSHOPPER_NUM_ITEMS];
        /*0x0C*/ u16 itemAmounts[SMARTSHOPPER_NUM_ITEMS];
        /*0x12*/ u8 shopLocation;
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } smartshopperShow;

    // TVSHOW_POKEMON_TODAY_FAILED
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 language;
        /*0x03*/ u8 filler_03[9];
        /*0x0C*/ u16 species;
        /*0x0E*/ u16 species2;
        /*0x10*/ u8 nBallsUsed;
        /*0x11*/ u8 outcome;
        /*0x12*/ u8 location;
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } pokemonTodayFailed;

    // TVSHOW_FISHING_ADVICE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 nBites;
        /*0x03*/ u8 nFails;
        /*0x04*/ u16 species;
        /*0x06*/ u8 language;
        /*0x07*/ u8 filler_07[12];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } pokemonAngler;

    // TVSHOW_WORLD_OF_MASTERS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 numPokeCaught;
        /*0x04*/ u16 caughtPoke;
        /*0x06*/ u16 steps;
        /*0x08*/ u16 species;
        /*0x0A*/ u8 location;
        /*0x0B*/ u8 language;
        /*0x0C*/ u8 filler_0C[7];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding2;
    } worldOfMasters;

    // TVSHOW_TODAYS_RIVAL_TRAINER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 dexCount;
        /*0x04*/ u8 badgeCount;
        /*0x05*/ u8 nSilverSymbols;
        /*0x06*/ u8 nGoldSymbols;
        /*0x07*/ u8 location;
        /*0x08*/ u16 battlePoints;
        /*0x0A*/ u16 mapLayoutId;
        /*0x0C*/ u8 language;
        /*0x0D*/ u8 filler_0D[6];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding2;
    } rivalTrainer;

    // TVSHOW_TREND_WATCHER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 filler_02[2];
        /*0x04*/ u16 words[2];
        /*0x08*/ u8 gender;
        /*0x09*/ u8 language;
        /*0x0A*/ u8 filler_0a[9];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } trendWatcher;

    // TVSHOW_TREASURE_INVESTIGATORS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 item;
        /*0x04*/ u8 location;
        /*0x05*/ u8 language;
        /*0x06*/ u16 mapLayoutId;
        /*0x08*/ u8 filler_08[11];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } treasureInvestigators;

    // TVSHOW_FIND_THAT_GAMER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 won;
        /*0x03*/ u8 whichGame;
        /*0x04*/ u16 nCoins;
        /*0x06*/ u8 filler_06[2];
        /*0x08*/ u8 language;
        /*0x09*/ u8 filler_09[10];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } findThatGamer;

    // TVSHOW_BREAKING_NEWS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 lastOpponentSpecies;
        /*0x04*/ u8 location;
        /*0x05*/ u8 outcome;
        /*0x06*/ u16 caughtMonBall;
        /*0x08*/ u16 balls;
        /*0x0A*/ u16 poke1Species;
        /*0x0C*/ u16 lastUsedMove;
        /*0x0E*/ u8 language;
        /*0x0F*/ u8 filler_0f[4];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } breakingNews;

    // TVSHOW_SECRET_BASE_VISIT
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 avgLevel;
        /*0x03*/ u8 numDecorations;
        /*0x04*/ u8 decorations[4];
        /*0x08*/ u16 species;
        /*0x0A*/ u16 move;
        /*0x0C*/ u8 language;
        /*0x0D*/ u8 filler_0d[6];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } secretBaseVisit;

    // TVSHOW_LOTTO_WINNER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 item;
        /*0x04*/ u8 whichPrize;
        /*0x05*/ u8 language;
        /*0x06*/ u8 filler_06[13];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } lottoWinner;

    // TVSHOW_BATTLE_SEMINAR
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 move;
        /*0x04*/ u16 foeSpecies;
        /*0x06*/ u16 species;
        /*0x08*/ u16 otherMoves[3];
        /*0x0E*/ u16 betterMove;
        /*0x10*/ u8 nOtherMoves;
        /*0x11*/ u8 language;
        /*0x12*/ u8 filler_12[1];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } battleSeminar;

    // TVSHOW_TRAINER_FAN_CLUB
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 filler_02[2];
        /*0x04*/ u16 words[2];
        /*0x08*/ u8 language;
        /*0x09*/ u8 filler_09[10];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } trainerFanClub;

    // TVSHOW_CUTIES
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 nRibbons;
        /*0x03*/ u8 selectedRibbon;
        /*0x04*/ u8 nickname[VANILLA_POKEMON_NAME_LENGTH + 1];
        /*0x0F*/ u8 language;
        /*0x10*/ u8 pokemonNameLanguage;
        /*0x11*/ u8 filler_12[2];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    } cuties;

    // TVSHOW_FRONTIER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 winStreak;
        /*0x04*/ u16 species1;
        /*0x06*/ u16 species2;
        /*0x08*/ u16 species3;
        /*0x0A*/ u16 species4;
        /*0x0C*/ u8 language;
        /*0x0D*/ u8 facilityAndMode;
        /*0x0E*/ u8 filler_0e[5];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } frontier;

    // TVSHOW_NUMBER_ONE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 count;
        /*0x04*/ u8 actionIdx;
        /*0x05*/ u8 language;
        /*0x06*/ u8 filler_06[13];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ //u8 padding;
    } numberOne;

    // TVSHOW_SECRET_BASE_SECRETS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 stepsInBase;
        /*0x04*/ u8 baseOwnersName[PLAYER_NAME_LENGTH + 1];
        /*0x0C*/ u32 flags;
        /*0x10*/ u16 item;
        /*0x12*/ u8 savedState;
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
        /*0x1B*/ u8 language;
        /*0x1C*/ u8 baseOwnersNameLanguage;
        /*0x1D*/ //u8 padding[3];
    } secretBaseSecrets;

    // TVSHOW_SAFARI_FAN_CLUB
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 monsCaught;
        /*0x03*/ u8 pokeblocksUsed;
        /*0x04*/ u8 language;
        /*0x05*/ u8 filler_05[14];
        /*0x13*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    } safariFanClub;

    // Mass Outbreak
    // TVSHOW_MASS_OUTBREAK
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 unused1;
        /*0x03*/ u8 unused3;
        /*0x04*/ u16 moves[MAX_MON_MOVES];
        /*0x0C*/ u16 species;
        /*0x0E*/ u16 unused2;
        /*0x10*/ u8 locationMapNum;
        /*0x11*/ u8 locationMapGroup;
        /*0x12*/ u8 unused4;
        /*0x13*/ u8 probability;
        /*0x14*/ u8 level;
        /*0x15*/ u8 unused5;
        /*0x16*/ u16 daysLeft;
        /*0x18*/ u8 language;
        /*0x19*/ //u8 padding;
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
    /*2BA4*/ u16 mon1;
    /*2BA6*/ u16 mon2;
    /*2BA8*/ u16 lastMove;
    /*2BAA*/ u16 quote[1];
    /*2BAC*/ u8 mapnum;
    /*2BAD*/ u8 battleNum;
    /*2BAE*/ u8 battleTookMoreThanOneTurn:1;
             u8 playerLostAMon:1;
             u8 playerUsedHealingItem:1;
             u8 playerThrewABall:1;
             u8 onAir:1;
             u8 valA_5:3;
    /*2BAF*/ u8 battleTookMoreThanOneTurn2:1;
             u8 playerLostAMon2:1;
             u8 playerUsedHealingItem2:1;
             u8 playerThrewABall2:1;
             u8 valB_4:4;
};

#endif //GUARD_GLOBAL_TV_H
