#ifndef GUARD_BATTLE_SETUP_H
#define GUARD_BATTLE_SETUP_H

#include "battle_transition.h"
#include "data.h"
#include "gym_leader_rematch.h"
#include "script.h"
#include "trainer_see.h"

#define REMATCHES_COUNT 5

#define TRAINERBATTLE_OPCODE_OFFSET 1  // 1 byte trainerbattle opcode
#define FACILITYBATTLE_OPCODE_OFFSET 5 // 1 byte callnative opcode, 4 bytes func ptr

struct RematchTrainer
{
    u16 trainerIds[REMATCHES_COUNT];
    u16 mapGroup;
    u16 mapNum;
};

/*
the layout of the first byte can be confusing here
isDoubleBattle is the least lsb. msb is in the mode.
*/
typedef union PACKED TrainerBattleParameter
{
    struct PACKED _TrainerBattleParameter
    {
        u8 isDoubleBattle:1;
        u8 isRematch:1;
        u8 playMusicA:1;
        u8 playMusicB:1;
        u8 continueScript:1;
        u8 facePlayer:1;
        u8 earlyRival:1;
        u8 skipFlagCheck:1;
        u8 objEventLocalIdA;
        u16 opponentA;
        u8 *introTextA;
        u8 *defeatTextA;
        u8 *battleScriptRetAddrA;
        u8 objEventLocalIdB;
        u16 opponentB;
        u8 *introTextB;
        u8 *defeatTextB;
        u8 *battleScriptRetAddrB;
        u8 *victoryText;
        u8 *cannotBattleText;
        u8 rivalBattleFlags;
    } params;
    u8 data[sizeof(struct _TrainerBattleParameter)];
} TrainerBattleParameter;

extern const struct RematchTrainer gRematchTable[REMATCH_TABLE_ENTRIES];

extern TrainerBattleParameter gTrainerBattleParameter;
extern u16 gPartnerTrainerId;

#define TRAINER_BATTLE_PARAM gTrainerBattleParameter.params

#define DebugPrintTrainerParams(battleParameter) DebugPrintfLevel(MGBA_LOG_DEBUG, "\nisDouble: %d\nisRematch: %d\nplayMusicA: %d\nplayMusicB: %d\ncotinueScript: %d\nfacePlayer: %d\nearlyRival: %d\npadding: %d\nlocalIdA: %d\ntrainerA: %d\nintroA: %x\ndefeatA: %x\neventA: %x\nlocalIdB: %d\ntrainerB: %d\nintroB: %x\ndefeatB: %x\neventB: %x\nvictory: %x\nnotBattle:%x\n", \
        battleParameter->params.isDoubleBattle, \
        battleParameter->params.isRematch, \
        battleParameter->params.playMusicA, \
        battleParameter->params.playMusicB, \
        battleParameter->params.continueScript, \
        battleParameter->params.facePlayer, \
        battleParameter->params.earlyRival, \
        battleParameter->params.padding, \
        battleParameter->params.objEventLocalIdA, \
        battleParameter->params.opponentA, \
        battleParameter->params.introTextA, \
        battleParameter->params.defeatTextA, \
        battleParameter->params.battleScriptRetAddrA, \
        battleParameter->params.objEventLocalIdB, \
        battleParameter->params.opponentB, \
        battleParameter->params.introTextB, \
        battleParameter->params.defeatTextB, \
        battleParameter->params.battleScriptRetAddrB, \
        battleParameter->params.victoryText, \
        battleParameter->params.cannotBattleText)

void BattleSetup_StartWildBattle(void);
void BattleSetup_StartDoubleWildBattle(void);
void BattleSetup_StartBattlePikeWildBattle(void);
void BattleSetup_StartRoamerBattle(void);
void StartWallyTutorialBattle(void);
void BattleSetup_StartScriptedWildBattle(void);
void BattleSetup_StartScriptedDoubleWildBattle(void);
void BattleSetup_StartLatiBattle(void);
void BattleSetup_StartLegendaryBattle(void);
void StartGroudonKyogreBattle(void);
void StartRegiBattle(void);
enum BattleEnvironments BattleSetup_GetEnvironmentId(void);
enum BattleTransition GetWildBattleTransition(void);
enum BattleTransition GetTrainerBattleTransition(void);
enum BattleTransition GetSpecialBattleTransition(enum BattleTransitionGroup id);
void ChooseStarter(void);
void SetMapVarsToTrainerA(void);
void SetMapVarsToTrainerB(void);
void ConfigureTrainerBattle(struct ScriptContext *ctx);
void ConfigureFacilityTrainerBattle(u8 facility, const u8 *scriptEndPtr);
void ConfigureApproachingTrainerBattle(struct ApproachingTrainer *approachingTrainer);
void ConfigureApproachingFacilityTrainerBattle(struct ApproachingTrainer *ApproachingTrainer);
bool32 GetTrainerFlagFromScriptPointer(const u8 *data);
bool32 GetRematchFromScriptPointer(const u8 *data);
void SetTrainerFacingDirection(void);
bool8 GetTrainerFlag(void);
bool8 HasTrainerBeenFought(u16 trainerId);
void SetTrainerFlag(u16 trainerId);
void ClearTrainerFlag(u16 trainerId);
void BattleSetup_StartTrainerBattle(void);
void BattleSetup_StartRematchBattle(void);
void ShowTrainerIntroSpeech(void);
const u8 *BattleSetup_GetScriptAddrAfterBattle(void);
const u8 *BattleSetup_GetTrainerPostBattleScript(void);
void ShowTrainerCantBattleSpeech(void);
void PlayTrainerEncounterMusic(void);
const u8 *GetTrainerALoseText(void);
const u8 *GetTrainerBLoseText(void);
const u8 *GetTrainerWonSpeech(void);
void UpdateRematchIfDefeated(s32 rematchTableId);
void ClearCurrentTrainerWantRematchVsSeeker(void);
void IncrementRematchStepCounter(void);
void TryUpdateRandomTrainerRematches(u16 mapGroup, u16 mapNum);
u16 GetLastBeatenRematchTrainerId(u16 trainerId);
bool8 ShouldTryRematchBattle(void);
bool8 ShouldTryRematchBattleForTrainerId(u16 trainerId);
bool8 IsTrainerReadyForRematch(void);
void ShouldTryGetTrainerScript(void);
u16 CountMaxPossibleRematch(u16 trainerId);
u16 CountBattledRematchTeams(u16 trainerId);
void TrainerBattleLoadArgs(const u8 *data);
void TrainerBattleLoadArgsSecondTrainer(const u8 *data);
void InitTrainerBattleParameter(void);

void DoStandardWildBattle_Debug(void);
void BattleSetup_StartTrainerBattle_Debug(void);
s32 TrainerIdToRematchTableId(const struct RematchTrainer *table, u16 trainerId);
s32 FirstBattleTrainerIdToRematchTableId(const struct RematchTrainer *table, u16 trainerId);
u16 GetRematchTrainerIdFromTable(const struct RematchTrainer *table, u16 firstBattleTrainerId);
u8 GetRivalBattleFlags(void);

void CreateNPCTrainerPartyFromTrainer(struct Pokemon *party, const struct Trainer *trainer);

#endif // GUARD_BATTLE_SETUP_H
