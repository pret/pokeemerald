#ifndef GUARD_SCRIPT_H
#define GUARD_SCRIPT_H

struct ScriptContext;

typedef bool8 (*ScrCmdFunc)(struct ScriptContext *);
typedef u8 Script[];

struct ScriptContext
{
    u8 stackDepth;
    u8 mode;
    u8 comparisonResult;
    u8 (*nativePtr)(void);
    const u8 *scriptPtr;
    const u8 *stack[20];
    ScrCmdFunc *cmdTable;
    ScrCmdFunc *cmdTableEnd;
    u32 data[4];
};

#define ScriptReadByte(ctx) (*(ctx->scriptPtr++))

void InitScriptContext(struct ScriptContext *ctx, void *cmdTable, void *cmdTableEnd);
u8 SetupBytecodeScript(struct ScriptContext *ctx, const u8 *ptr);
void SetupNativeScript(struct ScriptContext *ctx, bool8 (*ptr)(void));
void StopScript(struct ScriptContext *ctx);
bool8 RunScriptCommand(struct ScriptContext *ctx);
void ScriptJump(struct ScriptContext *ctx, const u8 *ptr);
void ScriptCall(struct ScriptContext *ctx, const u8 *ptr);
void ScriptReturn(struct ScriptContext *ctx);
u16 ScriptReadHalfword(struct ScriptContext *ctx);
u32 ScriptReadWord(struct ScriptContext *ctx);
u32 ScriptPeekWord(struct ScriptContext *ctx);
void LockPlayerFieldControls(void);
void UnlockPlayerFieldControls(void);
bool8 ArePlayerFieldControlsLocked(void);
void ScriptContext_Init(void);
bool8 ScriptContext_IsEnabled(void);
bool8 ScriptContext_RunScript(void);
void ScriptContext_SetupScript(const u8 *ptr);
void ScriptContext_Stop(void);
void ScriptContext_Enable(void);
void RunScriptImmediately(const u8 *ptr);
u8 *MapHeaderGetScriptTable(u8 tag);
void MapHeaderRunScriptType(u8 tag);
u8 *MapHeaderCheckScriptTable(u8 tag);
void RunOnLoadMapScript(void);
void RunOnTransitionMapScript(void);
void RunOnResumeMapScript(void);
void RunOnReturnToFieldMapScript(void);
void RunOnDiveWarpMapScript(void);
bool8 TryRunOnFrameMapScript(void);
void TryRunOnWarpIntoMapScript(void);
u32 CalculateRamScriptChecksum(void);
void ClearRamScript(void);
bool8 InitRamScript(const u8 *script, u16 scriptSize, u8 mapGroup, u8 mapNum, u8 objectId);
const u8 *GetRamScript(u8 objectId, const u8 *script);
bool32 ValidateSavedRamScript(void);
u8 *GetSavedRamScriptIfValid(void);
void InitRamScript_NoObjectEvent(u8 *script, u16 scriptSize);
void WarpToRandomPitArena(void);
void SetRandomBossEncounter(void);
const struct TrainerMon *GetRandomBossEncounterAcePokemon(void);
u16 GetRandomBossEncounterTrainerPic(void);
const u8 *GetRandomBossEncounterBossName(void);
const u8 *GetRandomBossEncounterBossApproachText(void);
const u8 *GetRandomBossEncounterBossDefeatText(void);
const u8 *GetRandomBossEncounterBossAceText(void);
u16 GetRandomMapTerrain(void);
u16 GetCurrentMapConstant(void);
void CreateOverworldHUD(void);

struct RandomTrainerNPC 
{
    u16 gfxid;
    u16 objectflag;
    u16 trainerflag;
    u16 defeatTextVar;
};

#define MAX_RANDOM_TRAINERS 4
#define BOSS_FLOOR_RATE 25

extern const struct RandomTrainerNPC RandomNPCTrainers[];
extern const struct RandomTrainerNPC RandomNPCTrainers_Doubles[];

u16 ReturnAvatarMugshotId(u16 avatarId);
u16 ReturnAvatarGraphicsId(u16 avatarId);
u16 ReturnAvatarTrainerFrontPicId(u16 avatarId);
u16 ReturnAvatarTrainerBackPicId(u16 avatarId);

enum {
    AVATAR_BRENDAN,
    AVATAR_MAY,
    AVATAR_RED,
    AVATAR_LEAF,
    AVATAR_LUCAS,
    AVATAR_DAWN,
    AVATAR_ETHAN,
    AVATAR_LYRA,
    AVATAR_STEVEN,
    AVATAR_CYNTHIA,
    AVATAR_OAK,
    AVATAR_PHOEBE,
    AVATAR_POKEMON_CHOICE,
};

// srccmd.h
void SetMovingNpcId(u16 npcId);
u16 ReturnLastSpokenVarObjGfxId();
void BufferMapFloorString();
#endif // GUARD_SCRIPT_H
