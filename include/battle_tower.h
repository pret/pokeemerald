#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

#define BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID 300
#define BATTLE_TOWER_RECORD_APPRENTICE_BASE_ID 400
#define BATTLE_TOWER_EREADER_TRAINER_ID 500

struct RSBattleTowerRecord
{
    /*0x00*/ u8 battleTowerLevelType; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[PLAYER_NAME_LENGTH + 1];
    /*0x0C*/ u8 trainerId[4];
    /*0x10*/ u16 greeting[6];
    /*0x1C*/ struct UnknownPokemonStruct party[3];
    /*0xA0*/ u32 checksum;
    /*0xA4*/ u16 unk_11c8;
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
void sub_81659DC(struct RSBattleTowerRecord *a0, struct RSBattleTowerRecord *a1);
bool32 sub_816587C(union BattleTowerRecord *, union BattleTowerRecord *);
void CalcEmeraldBattleTowerChecksum(struct EmeraldBattleTowerRecord *);
void PutNewBattleTowerRecord(union BattleTowerRecord *);
void SetBattleFacilityTrainerGfxId(u16 trainerId, u8 tempVarId);
void ConvertBattleFrontierTrainerSpeechToString(const u16 *words);
void GetFrontierTrainerName(u8 *dest, u16 trainerIdx);
void GetEreaderTrainerName(u8 *dest);

#endif //GUARD_BATTLE_TOWER_H
