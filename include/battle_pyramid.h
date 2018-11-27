#ifndef GUARD_BATTLE_PYRAMID_H
#define GUARD_BATTLE_PYRAMID_H

#define TOTAL_ROUNDS 20
#define PICKUP_ITEMS_PER_ROUND 10

struct PyramidWildMon
{
    u16 species;
    u8 lvl;
    u8 abilityBit;
    u16 moves[4];
};

struct Struct_08613650
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 runMultiplier;
    u8 unk5[8];
};

struct ClassMusic
{
    u8 class;
    u8 music;
};

void CallBattlePyramidFunction(void);
u16 LocalIdToPyramidTrainerId(u8 localId);
bool8 GetBattlePyramidTrainerFlag(u8 eventId);
void sub_81A9B04(void);
void GenerateBattlePyramidWildMon(void);
u8 GetPyramidRunMultiplier(void);
u8 InBattlePyramid(void);
bool8 InBattlePyramid_(void);
void sub_81A9E90(void);
void sub_81A9EC8(void);
void CopyPyramidTrainerSpeechBefore(u16 trainerId);
void CopyPyramidTrainerWinSpeech(u16 trainerId);
void CopyPyramidTrainerLoseSpeech(u16 trainerId);
u8 GetTrainerEncounterMusicIdInBattlePyramind(u16 trainerId);
void sub_81AA078(u16 *mapArg, u8 arg1);
void sub_81AA1D8(void);
void sub_81AA2F8(void);
u8 sub_81AAA40(void);
u16 GetBattlePyramidPickupItemId(void);

// Const rom data.
extern const u16 sPickupItemsLvl50[TOTAL_ROUNDS][PICKUP_ITEMS_PER_ROUND];
extern const u16 sPickupItemsLvlOpen[TOTAL_ROUNDS][PICKUP_ITEMS_PER_ROUND];
extern const u8 gUnknown_08613ABC[63][2];
extern const u8 gUnknown_08613B3A[];
extern const u16 gUnknown_08D856C8[][16];
extern const u8 gUnknown_08613C1C[50][2];
extern const u8 *const *const *const gUnknown_08613EC0[];
extern const struct ClassMusic gUnknown_08613B44[54];
extern const struct PyramidWildMon *const gBattlePyramidOpenLevelWildMonPointers[];
extern const struct PyramidWildMon *const gBattlePyramidLevel50WildMonPointers[];
extern const struct Struct_08613650 gUnknown_08613650[];
extern const u8 gUnknown_08613750[34][2];
extern const u8 gUnknown_08613794[];

#endif // GUARD_BATTLE_PYRAMID_H
