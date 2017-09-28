#ifndef GUARD_GLOBAL_TV_H
#define GUARD_GLOBAL_TV_H

enum
{
    TVSHOW_FAN_CLUB_LETTER = 1,
    TVSHOW_RECENT_HAPPENINGS,
    TVSHOW_PKMN_FAN_CLUB_OPINIONS,
    TVSHOW_UNKN_SHOWTYPE_04,
    TVSHOW_NAME_RATER_SHOW,
    TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE,
    TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE,
    TVSHOW_CONTEST_LIVE_UPDATES,
    TVSHOW_3_CHEERS_FOR_POKEBLOCKS,
    TVSHOW_BATTLE_UPDATE,
    TVSHOW_FAN_CLUB_SPECIAL,
    TVSHOW_CONTEST_LIVE_UPDATES_2,

    TVSHOW_POKEMON_TODAY_CAUGHT = 21,
    TVSHOW_SMART_SHOPPER,
    TVSHOW_POKEMON_TODAY_FAILED,
    TVSHOW_FISHING_ADVICE,
    TVSHOW_WORLD_OF_MASTERS,
    TVSHOW_TODAYS_RIVAL_TRAINER,
    TVSHOW_TREND_WATCHER,
    TVSHOW_TREASURE_INVESTIGATORS,
    TVSHOW_FIND_THAT_GAMER,
    TVSHOW_BREAKING_NEWS,
    TVSHOW_SECRET_BASE_VISIT,
    TVSHOW_LOTTO_WINNER,
    TVSHOW_BATTLE_SEMINAR,
    TVSHOW_TRAINER_FAN_CLUB,
    TVSHOW_CUTIES,
    TVSHOW_FRONTIER,
    TVSHOW_NUMBER_ONE,
    TVSHOW_SECRET_BASE_SECRETS,
    TVSHOW_SAFARI_FAN_CLUB,

    TVSHOW_MASS_OUTBREAK = 41,
};

typedef union TVShow // size = 0x24
{
    // Common
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 pad02[20];
        /*0x16*/ u16 var16[3];
        /*0x1C*/ u8 srcTrainerId3Lo;
        /*0x1D*/ u8 srcTrainerId3Hi;
        /*0x1E*/ u8 srcTrainerId2Lo;
        /*0x1F*/ u8 srcTrainerId2Hi;
        /*0x20*/ u8 srcTrainerIdLo;
        /*0x21*/ u8 srcTrainerIdHi;
        /*0x22*/ u8 trainerIdLo;
        /*0x23*/ u8 trainerIdHi;
    } common;

    // TVSHOW_FAN_CLUB_LETTER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u16 pad04[6];
        /*0x10*/ u8 playerName[8];
        /*0x18*/ u8 language;
    } fanclubLetter;

    // TVSHOW_RECENT_HAPPENINGS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 var02;
        /*0x04*/ u16 var04[6];
        /*0x10*/ u8 playerName[8];
        /*0x18*/ u8 language;
        /*0x19*/ u8 pad19[10];
    } recentHappenings;

    // TVSHOW_PKMN_FAN_CLUB_OPINIONS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u8 friendshipHighNybble:4;
        /*0x04*/ u8 var04B:4;
        /*0x05*/ u8 playerName[8];
        /*0x0D*/ u8 language;
        /*0x0E*/ u8 var0E;
        /*0x0F*/ u8 var0F;
        /*0x10*/ u8 nickname[8];
        /*0x18*/ u16 var18[2];
        /*0x1C*/ u16 var1C[4];
    } fanclubOpinions;

    // TVSHOW_UNKN_SHOWTYPE_04 (dummied out)
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 pad02[4];
        /*0x06*/ u16 var06;
    } unkShow04;

    // TVSHOW_NAME_RATER_SHOW
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u8 pokemonName[11];
        /*0x0F*/ u8 trainerName[11];
        /*0x1A*/ u8 random;
        /*0x1B*/ u8 random2;
        /*0x1C*/ u16 var1C;
        /*0x1E*/ u8 language;
        /*0x1F*/ u8 pokemonNameLanguage;
    } nameRaterShow;

    // TVSHOW_BRAVO_TRAINER_POKEMON_PROFILE (contest)
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 species;
        /*0x04*/ u16 ecWords[2];
        /*0x08*/ u8 pokemonNickname[11];
        /*0x13*/ u8 contestCategory:3;
        /*0x13*/ u8 contestRank:2;
        /*0x13*/ u8 contestResult:2;
        /*0x14*/ u16 move;
        /*0x16*/ u8 playerName[8];
        /*0x1E*/ u8 language;
        /*0x1F*/ u8 pokemonNameLanguage;
    } bravoTrainer;

    // TVSHOW_BRAVO_TRAINER_BATTLE_TOWER_PROFILE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 trainerName[8];
        /*0x0A*/ u16 species;
        /*0x0C*/ u8 pokemonName[8];
        /*0x14*/ u16 defeatedSpecies;
        /*0x16*/ u16 numFights;
        /*0x18*/ u16 var18[1];
        /*0x1A*/ u8 btLevel;
        /*0x1B*/ u8 var1b;
        /*0x1C*/ u8 var1c;
        /*0x1D*/ u8 language;
        /*0x1E*/ u8 pokemonNameLanguage;
    } bravoTrainerTower;

    // TVSHOW_CONTEST_LIVE_UPDATES
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 unk_02;
        /*0x04*/ u8 unk_04[8];
        /*0x0C*/ u8 unk_0c;
        /*0x0D*/ u8 unk_0d;
        /*0x0e*/ u8 unk_0e;
        /*0x0f*/ u8 unk_0f;
        /*0x10*/ u16 unk_10;
        /*0x12*/ u16 species;
        /*0x14*/ u8 playerName[8];
        /*0x1C*/ u8 unk_1c;
        /*0x1D*/ u8 language;
        /*0x1E*/ u8 unk_1e;
    } contestLiveUpdates;

    // TVSHOW_3_CHEERS_FOR_POKEBLOCKS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 unk_02;
        /*0x03*/ u8 unk_03_0:3;
        /*0x03*/ u8 unk_03_3:2;
        /*0x04*/ u8 unk_04[8];
        /*0x0C*/ u8 playerName[8];
        /*0x14*/ u8 language;
        /*0x15*/ u8 unk_15;
    } threeCheers;

    // TVSHOW_BATTLE_UPDATE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 unk_02;
        /*0x04*/ u8 playerName[8];
        /*0x0C*/ u8 linkOpponentName[8];
        /*0x14*/ u16 unk_14;
        /*0x16*/ u16 unk_16;
        /*0x18*/ u8 battleType;
        /*0x19*/ u8 language;
        /*0x1A*/ u8 unk_1a;
    } battleUpdate;

    // TVSHOW_FAN_CLUB_SPECIAL
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 playerName[8];
        /*0x0a*/ u8 idLo;
        /*0x0b*/ u8 idHi;
        /*0x0c*/ u8 unk_0c[10];
        /*0x16*/ u8 unk_16;
        /*0x17*/ u8 language;
        /*0x18*/ u8 unk_18;
    } fanClubSpecial;

    // TVSHOW_CONTEST_LIVE_UPDATES_2
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 playerName[8];
        /*0x0a*/ u8 contestCategory;
        /*0x0b*/ u8 categoryName[11];
        /*0x16*/ u8 pokeblockState;
        /*0x17*/ u8 language;
        /*0x18*/ u8 unk_18;
    } contestLiveUpdates2;

    // TVSHOW_POKEMON_TODAY_CAUGHT
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 language;
        /*0x03*/ u8 language2;
        /*0x04*/ u8 nickname[11];
        /*0x0F*/ u8 ball;
        /*0x10*/ u16 species;
        /*0x12*/ u8 var12;
        /*0x13*/ u8 playerName[8];
    } pokemonToday;

    // TVSHOW_SMART_SHOPPER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 priceReduced;
        /*0x03*/ u8 language;
        /*0x04*/ u8 pad04[2];
        /*0x06*/ u16 itemIds[3];
        /*0x0C*/ u16 itemAmounts[3];
        /*0x12*/ u8 shopLocation;
        /*0x13*/ u8 playerName[8];
    } smartshopperShow;

    // TVSHOW_POKEMON_TODAY_FAILED
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 language;
        /*0x03*/ u8 pad03[9];
        /*0x0c*/ u16 species;
        /*0x0e*/ u16 species2;
        /*0x10*/ u8 var10;
        /*0x11*/ u8 var11;
        /*0x12*/ u8 var12;
        /*0x13*/ u8 playerName[8];
    } pokemonTodayFailed;

    // TVSHOW_FISHING_ADVICE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 var02;
        /*0x03*/ u8 var03;
        /*0x04*/ u16 species;
        /*0x06*/ u8 language;
        u8 pad07[12];
        /*0x13*/ u8 playerName[8];
    } pokemonAngler;

    // TVSHOW_WORLD_OF_MASTERS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u16 var02;
        /*0x04*/ u16 caughtPoke;
        /*0x06*/ u16 steps;
        /*0x08*/ u16 species;
        /*0x0a*/ u8 location;
        /*0x0b*/ u8 language;
        u8 pad0c[7];
        /*0x13*/ u8 playerName[8];
    } worldOfMasters;

    // TVSHOW_TODAYS_RIVAL_TRAINER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } rivalTrainer;

    // TVSHOW_TREND_WATCHER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } trendWatcher;

    // TVSHOW_TREASURE_INVESTIGATORS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } treasureInvestigators;

    // TVSHOW_FIND_THAT_GAMER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } findThatGamer;

    // TVSHOW_BREAKING_NEWS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } breakingNews;

    // TVSHOW_SECRET_BASE_VISIT
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } secretBaseVisit;

    // TVSHOW_LOTTO_WINNER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } lottoWinner;

    // TVSHOW_BATTLE_SEMINAR
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } battleSeminar;

    // TVSHOW_TRAINER_FAN_CLUB
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } trainerFanClub;

    // TVSHOW_CUTIES
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } cuties;

    // TVSHOW_FRONTIER
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } frontier;

    // TVSHOW_NUMBER_ONE
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } numberOne;

    // TVSHOW_SECRET_BASE_SECRETS
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } secretBaseSecrets;

    // TVSHOW_SAFARI_FAN_CLUB
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        // TODO: flesh this out
    } safariFanClub;

    // TVSHOW_MASS_OUTBREAK
    struct {
        /*0x00*/ u8 kind;
        /*0x01*/ bool8 active;
        /*0x02*/ u8 var02;
        /*0x03*/ u8 var03;
        /*0x04*/ u16 moves[4];
        /*0x0C*/ u16 species;
        /*0x0E*/ u16 var0E;
        /*0x10*/ u8 locationMapNum;
        /*0x11*/ u8 locationMapGroup;
        /*0x12*/ u8 var12;
        /*0x13*/ u8 probability;
        /*0x14*/ u8 level;
        /*0x15*/ u8 var15;
        /*0x16*/ u16 daysLeft;
        /*0x18*/ u8 language;
        u8 pad19[11];
    } massOutbreak;
} TVShow;

struct PokemonNewsData // 2b50
{
    u8 val0;
    u8 val1;
    u16 val2;
};

struct GabbyAndTyData
{
    /*2ba4*/ u16 mon1;
    /*2ba6*/ u16 mon2;
    /*2ba8*/ u16 lastMove;
    /*2baa*/ u16 quote[1];
    /*2bac*/ u8 mapnum;
    /*2bad*/ u8 battleNum;
    /*2bae*/ u8 valA_0:1;
    /*2bae*/ u8 not_total_victory:1; // TRUE if at least one of the player's pokemon fainted during the battle
    /*2bae*/ u8 valA_2:1;
    /*2bae*/ u8 valA_3:1;
    /*2bae*/ u8 onAir:1;
    /*2bae*/ u8 valA_5:3;
    /*2baf*/ u8 valB_0:1;
    /*2baf*/ u8 valB_1:1;
    /*2baf*/ u8 valB_2:1;
    /*2baf*/ u8 valB_3:1;
    /*2baf*/ u8 valB_4:4;
};

#endif //GUARD_GLOBAL_TV_H
