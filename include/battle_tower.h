#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

struct RSBattleTowerRecord
{
    /*0x00*/ u8 lvlMode; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 facilityClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[PLAYER_NAME_LENGTH + 1];
    /*0x0C*/ u8 trainerId[TRAINER_ID_LENGTH];
    /*0x10*/ u16 greeting[6];
    /*0x1C*/ struct BattleTowerPokemon party[3];
    /*0xA0*/ u32 checksum;
};

struct BattleFrontierTrainer
{
    u8 facilityClass;
    u8 filler1[3];
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u16 speechBefore[6];
    u16 speechWin[6];
    u16 speechLose[6];
    const u16 *monSets;
};

struct FacilityMon
{
    u16 species;
    u16 moves[MAX_MON_MOVES];
    u8 itemTableId;
    u8 evSpread;
    u8 nature;
};

extern const u8 gTowerMaleFacilityClasses[30];
extern const u8 gTowerMaleTrainerGfxIds[30];
extern const u8 gTowerFemaleFacilityClasses[20];
extern const u8 gTowerFemaleTrainerGfxIds[20];
extern const u16 gBattleFrontierHeldItems[];
extern const struct FacilityMon gBattleFrontierMons[];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];
extern const struct FacilityMon gSlateportBattleTentMons[];
extern const struct BattleFrontierTrainer gSlateportBattleTentTrainers[];

extern u16 gUnknown_03006298[];

extern const struct BattleFrontierTrainer *gFacilityTrainers;
extern const struct FacilityMon *gFacilityTrainerMons;

void sub_8161F74(void);
u16 sub_8162548(u8 challengeNum, u8 battleNum);
void SetBattleFacilityTrainerGfxId(u16 trainerId, u8 tempVarId);
void SetEReaderTrainerGfxId(void);
u8 GetBattleFacilityTrainerGfxId(u16 trainerId);
void PutNewBattleTowerRecord(struct EmeraldBattleTowerRecord *newRecordEm);
u8 GetFrontierTrainerFrontSpriteId(u16 trainerId);
u8 GetFrontierOpponentClass(u16 trainerId);
void GetFrontierTrainerName(u8 *dst, u16 trainerId);
void FillFrontierTrainerParty(u8 monsCount);
void FillFrontierTrainersParties(u8 monsCount);
u16 RandomizeFacilityTrainerMonSet(u16 trainerId);
void FrontierSpeechToString(const u16 *words);
void DoSpecialTrainerBattle(void);
void CalcEmeraldBattleTowerChecksum(struct EmeraldBattleTowerRecord *record);
void CalcRubyBattleTowerChecksum(struct RSBattleTowerRecord *record);
u16 GetCurrentBattleTowerWinStreak(u8 lvlMode, u8 battleMode);
u8 GetEreaderTrainerFrontSpriteId(void);
u8 GetEreaderTrainerClassId(void);
void GetEreaderTrainerName(u8 *dst);
void ValidateEReaderTrainer(void);
void ClearEReaderTrainer(struct BattleTowerEReaderTrainer *ereaderTrainer);
void CopyEReaderTrainerGreeting(void);
void sub_81653CC(void);
bool32 RubyBattleTowerRecordToEmerald(struct RSBattleTowerRecord *src, struct EmeraldBattleTowerRecord *dst);
bool32 EmeraldBattleTowerRecordToRuby(struct EmeraldBattleTowerRecord *src, struct RSBattleTowerRecord *dst);
void CalcApprenticeChecksum(struct Apprentice *apprentice);
void GetBattleTowerTrainerLanguage(u8 *dst, u16 trainerId);
u8 SetFacilityPtrsGetLevel(void);
u8 GetFrontierEnemyMonLevel(u8 lvlMode);
s32 GetHighestLevelInPlayerParty(void);
u8 FacilityClassToGraphicsId(u8 facilityClass);
bool32 ValidateBattleTowerRecord(u8 recordId); // unused
void sub_8166188(void);

#endif //GUARD_BATTLE_TOWER_H
