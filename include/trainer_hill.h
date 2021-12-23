#ifndef GUARD_TRAINER_HILL_H
#define GUARD_TRAINER_HILL_H

#define HILL_TRAINER_NAME_LENGTH 11

struct TrainerHillTrainer
{
    u8 name[HILL_TRAINER_NAME_LENGTH];
    u8 facilityClass;
    u32 unused;
    u16 speechBefore[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechWin[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechLose[EASY_CHAT_BATTLE_WORDS_COUNT];
    u16 speechAfter[EASY_CHAT_BATTLE_WORDS_COUNT];
    struct BattleTowerPokemon mons[PARTY_SIZE];
};

struct TrHillRoomTrainers
{
    u8 name[2][HILL_TRAINER_NAME_LENGTH];
    u8 facilityClass[2];
};

struct TrHillDisplay
{
    // Metatile data. Add 0x200 to the values in this array to get metatiles.
    // This data then overwrites the metatiles in the map starting at (0,5)
    u8 metatileData[0x100];
    // Collision data. One bit for each tile in column-major order,
    // so every array entry is one row. 1 = impassable, 0 = passable
    u16 collisionData[16];
    // Trainer coordinates, starting at (0,6). Format is 0bYYYYXXXX.
    u8 coords[2];
    // Trainer facing directions. Same as (DIR_* - 1).
    // Effectively an array of nibbles, one for each trainer.
    u8 direction;
    // Trainer sight ranges. Effectively an array of nibbles, one for each trainer.
    u8 range;
};

struct TrHillFloor
{
    u8 trainerNum1;
    u8 trainerNum2;
    struct TrainerHillTrainer trainers[2];
    struct TrHillDisplay display;
};

struct TrHillTag
{
    u8 numTrainers;
    u8 unused1;
    u8 numFloors;
    u32 checksum;
    struct TrHillFloor floors[0];
};

extern u32 *gTrainerHillVBlankCounter;

void CallTrainerHillFunction(void);
void ResetTrainerHillResults(void);
u8 GetTrainerHillOpponentClass(u16 trainerId);
void GetTrainerHillTrainerName(u8 *dst, u16 trainerId);
u8 GetTrainerHillTrainerFrontSpriteId(u16 trainerId);
void InitTrainerHillBattleStruct(void);
void FreeTrainerHillBattleStruct(void);
void CopyTrainerHillTrainerText(u8 which, u16 trainerId);
bool8 InTrainerHillChallenge(void);
void PrintOnTrainerHillRecordsWindow(void);
void LoadTrainerHillObjectEventTemplates(void);
bool32 LoadTrainerHillFloorObjectEventScripts(void);
void GenerateTrainerHillFloorLayout(u16 *mapArg);
bool32 InTrainerHill(void);
u8 GetCurrentTrainerHillMapId(void);
const struct WarpEvent* SetWarpDestinationTrainerHill4F(void);
const struct WarpEvent* SetWarpDestinationTrainerHillFinalFloor(u8 warpEventId);
u16 LocalIdToHillTrainerId(u8 localId);
bool8 GetHillTrainerFlag(u8 objectEventId);
void SetHillTrainerFlag(void);
const u8 *GetTrainerHillTrainerScript(void);
void FillHillTrainerParty(void);
void FillHillTrainersParties(void);
u8 GetTrainerEncounterMusicIdInTrainerHill(u16 trainerId);
u8 GetNumFloorsInTrainerHillChallenge(void);
void TryLoadTrainerHillEReaderPalette(void);
bool32 OnTrainerHillEReaderChallengeFloor(void);

#endif // GUARD_TRAINER_HILL_H
