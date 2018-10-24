#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

#define BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID 300
#define BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID 400
#define BATTLE_TOWER_EREADER_TRAINER_ID 500

struct RSBattleTowerRecord
{
    /*0x00*/ u8 lvlMode; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 facilityClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[PLAYER_NAME_LENGTH + 1];
    /*0x0C*/ u8 trainerId[4];
    /*0x10*/ u16 greeting[6];
    /*0x1C*/ struct UnknownPokemonStruct party[3];
    /*0xA0*/ u32 checksum;
};

union BattleTowerRecord
{
    struct RSBattleTowerRecord ruby_sapphire;
    struct EmeraldBattleTowerRecord emerald;
};

struct BattleFrontierTrainer
{
    u8 facilityClass;
    u8 filler1[3];
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u16 speechBefore[6];
    u16 speechWin[6];
    u16 speechLose[6];
    const u16 *bfMonPool;
};

struct FacilityMon
{
    u16 species;
    u16 moves[4];
    u8 itemTableId;
    u8 evSpread;
    u8 nature;
};

extern const u8 gTowerMaleFacilityClasses[30];
extern const u8 gTowerMaleTrainerGfxIds[30];
extern const u8 gTowerFemaleFacilityClasses[20];
extern const u8 gTowerFemaleTrainerGfxIds[20];

extern const struct BattleFrontierTrainer *gFacilityTrainers;
extern const struct FacilityMon *gFacilityTrainerMons;

u16 GetCurrentBattleTowerWinStreak(u8, u8);
bool32 EmeraldBattleTowerRecordToRuby(struct EmeraldBattleTowerRecord *src, struct RSBattleTowerRecord *dst);
bool32 RubyBattleTowerRecordToEmerald(struct RSBattleTowerRecord *src, struct EmeraldBattleTowerRecord *dst);
void CalcEmeraldBattleTowerChecksum(struct EmeraldBattleTowerRecord *);
void PutNewBattleTowerRecord(struct EmeraldBattleTowerRecord *newRecordEm);
void SetBattleFacilityTrainerGfxId(u16 trainerId, u8 tempVarId);
void FrontierSpeechToString(const u16 *words);
void GetFrontierTrainerName(u8 *dest, u16 trainerIdx);
void GetEreaderTrainerName(u8 *dest);
void FillFrontierTrainerParty(u8 monsCount);
void FillFrontierTrainersParties(u8 monsCount);

#endif //GUARD_BATTLE_TOWER_H
