#include "global.h"
#include "script.h"
#include "event_data.h"
#include "mystery_gift.h"
#include "util.h"
#include "constants/event_objects.h"
#include "constants/map_scripts.h"
#include "main_menu.h"
#include "main.h"
#include "random.h"
#include "battle_setup.h"
#include "string_util.h"
#include "strings.h"
#include "pokemon_storage_system.h"
#include "ui_birch_case.h"
#include "task.h"
#include "field_weather.h"
#include "new_game.h"
#include "ui_mode_menu.h"
#include "start_menu.h"
#include "constants/metatile_labels.h"
#include "fieldmap.h"
#include "field_screen_effect.h"
#include "overworld.h"
#include "event_scripts.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "data.h"
#include "constants/battle.h"
#include "event_object_movement.h"
#include "script_pokemon_util.h"
#include "palette.h"
#include "decompress.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "gpu_regs.h"

#define RAM_SCRIPT_MAGIC 51

//Autosave defines
#define SAVE_NO         0
#define SAVE_5_FLOORS   1
#define SAVE_EACH_FLOOR 2

enum {
    SCRIPT_MODE_STOPPED,
    SCRIPT_MODE_BYTECODE,
    SCRIPT_MODE_NATIVE,
};

enum {
    CONTEXT_RUNNING,
    CONTEXT_WAITING,
    CONTEXT_SHUTDOWN,
};

extern const u8 *gRamScriptRetAddr;

static u8 sGlobalScriptContextStatus;
static struct ScriptContext sGlobalScriptContext;
static struct ScriptContext sImmediateScriptContext;
static bool8 sLockFieldControls;

extern ScrCmdFunc gScriptCmdTable[];
extern ScrCmdFunc gScriptCmdTableEnd[];
extern void *gNullScriptPtr;

void InitScriptContext(struct ScriptContext *ctx, void *cmdTable, void *cmdTableEnd)
{
    s32 i;

    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
    ctx->stackDepth = 0;
    ctx->nativePtr = NULL;
    ctx->cmdTable = cmdTable;
    ctx->cmdTableEnd = cmdTableEnd;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->data); i++)
        ctx->data[i] = 0;

    for (i = 0; i < (int)ARRAY_COUNT(ctx->stack); i++)
        ctx->stack[i] = NULL;
}

u8 SetupBytecodeScript(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
    ctx->mode = SCRIPT_MODE_BYTECODE;
    return 1;
}

void SetupNativeScript(struct ScriptContext *ctx, bool8 (*ptr)(void))
{
    ctx->mode = SCRIPT_MODE_NATIVE;
    ctx->nativePtr = ptr;
}

void StopScript(struct ScriptContext *ctx)
{
    ctx->mode = SCRIPT_MODE_STOPPED;
    ctx->scriptPtr = NULL;
}

bool8 RunScriptCommand(struct ScriptContext *ctx)
{
    if (ctx->mode == SCRIPT_MODE_STOPPED)
        return FALSE;

    switch (ctx->mode)
    {
    case SCRIPT_MODE_STOPPED:
        return FALSE;
    case SCRIPT_MODE_NATIVE:
        // Try to call a function in C
        // Continue to bytecode if no function or it returns TRUE
        if (ctx->nativePtr)
        {
            if (ctx->nativePtr() == TRUE)
                ctx->mode = SCRIPT_MODE_BYTECODE;
            return TRUE;
        }
        ctx->mode = SCRIPT_MODE_BYTECODE;
        // fallthrough
    case SCRIPT_MODE_BYTECODE:
        while (1)
        {
            u8 cmdCode;
            ScrCmdFunc *func;

            if (!ctx->scriptPtr)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if (ctx->scriptPtr == gNullScriptPtr)
            {
                while (1)
                    asm("svc 2"); // HALT
            }

            cmdCode = *(ctx->scriptPtr);
            ctx->scriptPtr++;
            func = &ctx->cmdTable[cmdCode];

            if (func >= ctx->cmdTableEnd)
            {
                ctx->mode = SCRIPT_MODE_STOPPED;
                return FALSE;
            }

            if ((*func)(ctx) == TRUE)
                return TRUE;
        }
    }

    return TRUE;
}

static bool8 ScriptPush(struct ScriptContext *ctx, const u8 *ptr)
{
    if (ctx->stackDepth + 1 >= (int)ARRAY_COUNT(ctx->stack))
    {
        return TRUE;
    }
    else
    {
        ctx->stack[ctx->stackDepth] = ptr;
        ctx->stackDepth++;
        return FALSE;
    }
}

static const u8 *ScriptPop(struct ScriptContext *ctx)
{
    if (ctx->stackDepth == 0)
        return NULL;

    ctx->stackDepth--;
    return ctx->stack[ctx->stackDepth];
}

void ScriptJump(struct ScriptContext *ctx, const u8 *ptr)
{
    ctx->scriptPtr = ptr;
}

void ScriptCall(struct ScriptContext *ctx, const u8 *ptr)
{
    ScriptPush(ctx, ctx->scriptPtr);
    ctx->scriptPtr = ptr;
}

void ScriptReturn(struct ScriptContext *ctx)
{
    ctx->scriptPtr = ScriptPop(ctx);
}

u16 ScriptReadHalfword(struct ScriptContext *ctx)
{
    u16 value = *(ctx->scriptPtr++);
    value |= *(ctx->scriptPtr++) << 8;
    return value;
}

u32 ScriptReadWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr++);
    u32 value1 = *(ctx->scriptPtr++);
    u32 value2 = *(ctx->scriptPtr++);
    u32 value3 = *(ctx->scriptPtr++);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

u32 ScriptPeekWord(struct ScriptContext *ctx)
{
    u32 value0 = *(ctx->scriptPtr);
    u32 value1 = *(ctx->scriptPtr + 1);
    u32 value2 = *(ctx->scriptPtr + 2);
    u32 value3 = *(ctx->scriptPtr + 3);
    return (((((value3 << 8) + value2) << 8) + value1) << 8) + value0;
}

void LockPlayerFieldControls(void)
{
    sLockFieldControls = TRUE;
}

void UnlockPlayerFieldControls(void)
{
    sLockFieldControls = FALSE;
}

bool8 ArePlayerFieldControlsLocked(void)
{
    return sLockFieldControls;
}

// The ScriptContext_* functions work with the primary script context,
// which yields control back to native code should the script make a wait call.

// Checks if the global script context is able to be run right now.
bool8 ScriptContext_IsEnabled(void)
{
    if (sGlobalScriptContextStatus == CONTEXT_RUNNING)
        return TRUE;
    else
        return FALSE;
}

// Re-initializes the global script context to zero.
void ScriptContext_Init(void)
{
    InitScriptContext(&sGlobalScriptContext, gScriptCmdTable, gScriptCmdTableEnd);
    sGlobalScriptContextStatus = CONTEXT_SHUTDOWN;
}

// Runs the script until the script makes a wait* call, then returns true if
// there's more script to run, or false if the script has hit the end.
// This function also returns false if the context is finished
// or waiting (after a call to _Stop)
bool8 ScriptContext_RunScript(void)
{
    if (sGlobalScriptContextStatus == CONTEXT_SHUTDOWN)
        return FALSE;

    if (sGlobalScriptContextStatus == CONTEXT_WAITING)
        return FALSE;

    LockPlayerFieldControls();

    if (!RunScriptCommand(&sGlobalScriptContext))
    {
        sGlobalScriptContextStatus = CONTEXT_SHUTDOWN;
        UnlockPlayerFieldControls();
        return FALSE;
    }

    return TRUE;
}

// Sets up a new script in the global context and enables the context
void ScriptContext_SetupScript(const u8 *ptr)
{
    InitScriptContext(&sGlobalScriptContext, gScriptCmdTable, gScriptCmdTableEnd);
    SetupBytecodeScript(&sGlobalScriptContext, ptr);
    LockPlayerFieldControls();
    sGlobalScriptContextStatus = CONTEXT_RUNNING;
}

// Puts the script into waiting mode; usually called from a wait* script command.
void ScriptContext_Stop(void)
{
    sGlobalScriptContextStatus = CONTEXT_WAITING;
}

// Puts the script into running mode.
void ScriptContext_Enable(void)
{
    sGlobalScriptContextStatus = CONTEXT_RUNNING;
    LockPlayerFieldControls();
}

// Sets up and runs a script in its own context immediately. The script will be
// finished when this function returns. Used mainly by all of the map header
// scripts (except the frame table scripts).
void RunScriptImmediately(const u8 *ptr)
{
    InitScriptContext(&sImmediateScriptContext, gScriptCmdTable, gScriptCmdTableEnd);
    SetupBytecodeScript(&sImmediateScriptContext, ptr);
    while (RunScriptCommand(&sImmediateScriptContext) == TRUE);
}

u8 *MapHeaderGetScriptTable(u8 tag)
{
    const u8 *mapScripts = gMapHeader.mapScripts;

    if (!mapScripts)
        return NULL;

    while (1)
    {
        if (!*mapScripts)
            return NULL;
        if (*mapScripts == tag)
        {
            mapScripts++;
            return T2_READ_PTR(mapScripts);
        }
        mapScripts += 5;
    }
}

void MapHeaderRunScriptType(u8 tag)
{
    u8 *ptr = MapHeaderGetScriptTable(tag);
    if (ptr)
        RunScriptImmediately(ptr);
}

u8 *MapHeaderCheckScriptTable(u8 tag)
{
    u8 *ptr = MapHeaderGetScriptTable(tag);

    if (!ptr)
        return NULL;

    while (1)
    {
        u16 varIndex1;
        u16 varIndex2;

        // Read first var (or .2byte terminal value)
        varIndex1 = T1_READ_16(ptr);
        if (!varIndex1)
            return NULL; // Reached end of table
        ptr += 2;

        // Read second var
        varIndex2 = T1_READ_16(ptr);
        ptr += 2;

        // Run map script if vars are equal
        if (VarGet(varIndex1) == VarGet(varIndex2))
            return T2_READ_PTR(ptr);
        ptr += 4;
    }
}

void RunOnLoadMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_LOAD);
}

void RunOnTransitionMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_TRANSITION);
}

void RunOnResumeMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RESUME);
}

void RunOnReturnToFieldMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_RETURN_TO_FIELD);
}

void RunOnDiveWarpMapScript(void)
{
    MapHeaderRunScriptType(MAP_SCRIPT_ON_DIVE_WARP);
}

bool8 TryRunOnFrameMapScript(void)
{
    u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_FRAME_TABLE);

    if (!ptr)
        return FALSE;

    ScriptContext_SetupScript(ptr);
    return TRUE;
}

void TryRunOnWarpIntoMapScript(void)
{
    u8 *ptr = MapHeaderCheckScriptTable(MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE);
    if (ptr)
        RunScriptImmediately(ptr);
}

u32 CalculateRamScriptChecksum(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    return CalcCRC16WithTable((u8 *)(&gSaveBlock1Ptr->ramScript.data), sizeof(gSaveBlock1Ptr->ramScript.data));
#else
    return 0;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

void ClearRamScript(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    CpuFill32(0, &gSaveBlock1Ptr->ramScript, sizeof(struct RamScript));
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

bool8 InitRamScript(const u8 *script, u16 scriptSize, u8 mapGroup, u8 mapNum, u8 objectId)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;

    ClearRamScript();

    if (scriptSize > sizeof(scriptData->script))
        return FALSE;

    scriptData->magic = RAM_SCRIPT_MAGIC;
    scriptData->mapGroup = mapGroup;
    scriptData->mapNum = mapNum;
    scriptData->objectId = objectId;
    memcpy(scriptData->script, script, scriptSize);
    gSaveBlock1Ptr->ramScript.checksum = CalculateRamScriptChecksum();
    return TRUE;
#else
    return FALSE;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

const u8 *GetRamScript(u8 objectId, const u8 *script)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    gRamScriptRetAddr = NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return script;
    if (scriptData->mapGroup != gSaveBlock1Ptr->location.mapGroup)
        return script;
    if (scriptData->mapNum != gSaveBlock1Ptr->location.mapNum)
        return script;
    if (scriptData->objectId != objectId)
        return script;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return script;
    }
    else
    {
        gRamScriptRetAddr = script;
        return scriptData->script;
    }
#else
    return script;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

#define NO_OBJECT OBJ_EVENT_ID_PLAYER

bool32 ValidateSavedRamScript(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return FALSE;
    if (scriptData->mapGroup != MAP_GROUP(UNDEFINED))
        return FALSE;
    if (scriptData->mapNum != MAP_NUM(UNDEFINED))
        return FALSE;
    if (scriptData->objectId != NO_OBJECT)
        return FALSE;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
        return FALSE;
    return TRUE;
#else
    return FALSE;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

u8 *GetSavedRamScriptIfValid(void)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    struct RamScriptData *scriptData = &gSaveBlock1Ptr->ramScript.data;
    if (!ValidateSavedWonderCard())
        return NULL;
    if (scriptData->magic != RAM_SCRIPT_MAGIC)
        return NULL;
    if (scriptData->mapGroup != MAP_GROUP(UNDEFINED))
        return NULL;
    if (scriptData->mapNum != MAP_NUM(UNDEFINED))
        return NULL;
    if (scriptData->objectId != NO_OBJECT)
        return NULL;
    if (CalculateRamScriptChecksum() != gSaveBlock1Ptr->ramScript.checksum)
    {
        ClearRamScript();
        return NULL;
    }
    else
    {
        return scriptData->script;
    }
#else
    return NULL;
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

void InitRamScript_NoObjectEvent(u8 *script, u16 scriptSize)
{
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    if (scriptSize > sizeof(gSaveBlock1Ptr->ramScript.data.script))
        scriptSize = sizeof(gSaveBlock1Ptr->ramScript.data.script);
    InitRamScript(script, scriptSize, MAP_GROUP(UNDEFINED), MAP_NUM(UNDEFINED), NO_OBJECT);
#endif //FREE_MYSTERY_EVENT_BUFFERS
}

void InitTrainerIdAndNameData()
{
    u32 trainerId = 0;
    SeedRngWithRtc();
    trainerId = (Random() << 16) | Random();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
    NewGameBirchSpeech_SetDefaultPlayerName(Random() % 19);
}

const struct RandomTrainerNPC RandomNPCTrainers[MAX_RANDOM_TRAINERS] = 
{
    [0] = {VAR_OBJ_GFX_ID_0, FLAG_TRAINER_0, TRAINER_RANDOM_BATTLE_0, VAR_TRAINER_0_DEFEAT_TEXT},
    [1] = {VAR_OBJ_GFX_ID_1, FLAG_TRAINER_1, TRAINER_RANDOM_BATTLE_1, VAR_TRAINER_1_DEFEAT_TEXT},
    [2] = {VAR_OBJ_GFX_ID_2, FLAG_TRAINER_2, TRAINER_RANDOM_BATTLE_2, VAR_TRAINER_2_DEFEAT_TEXT},
    [3] = {VAR_OBJ_GFX_ID_3, FLAG_TRAINER_3, TRAINER_RANDOM_BATTLE_3, VAR_TRAINER_3_DEFEAT_TEXT},
};

const struct RandomTrainerNPC RandomNPCTrainers_Doubles[MAX_RANDOM_TRAINERS] = 
{
    [0] = {VAR_OBJ_GFX_ID_0, FLAG_TRAINER_4, TRAINER_RANDOM_BATTLE_4, VAR_TRAINER_4_DEFEAT_TEXT},
    [1] = {VAR_OBJ_GFX_ID_1, FLAG_TRAINER_5, TRAINER_RANDOM_BATTLE_5, VAR_TRAINER_5_DEFEAT_TEXT},
    [2] = {VAR_OBJ_GFX_ID_2, FLAG_TRAINER_6, TRAINER_RANDOM_BATTLE_6, VAR_TRAINER_6_DEFEAT_TEXT},
    [3] = {VAR_OBJ_GFX_ID_3, FLAG_TRAINER_7, TRAINER_RANDOM_BATTLE_7, VAR_TRAINER_7_DEFEAT_TEXT},
};

u16 ReturnLastSpokenVarObjGfxId()
{   
    if(gSpecialVar_LastTalked > 4)
        return VarGet(RandomNPCTrainers_Doubles[gSpecialVar_LastTalked - 5].gfxid);
    else
        return VarGet(RandomNPCTrainers[gSpecialVar_LastTalked - 1].gfxid);
}

u16 ReturnNumberOfTrainersForFloor()
{
    if(VarGet(VAR_LAST_FLOOR_TRAINER_NUMBER) == 4)
        return 1;

    if(VarGet(VAR_PIT_FLOOR) < 5)
        return 1;

    u16 randomValue = Random() % 100;
    if(VarGet(VAR_PIT_FLOOR) < 25) // first 25 floor rates
    {
        if(randomValue < 65)
            return 1;
        if(randomValue < 95)
            return 2;
        if(randomValue < 99)
            return 3;
        if(randomValue < 100)
            return 4;
        return 0;
    }
    else if(VarGet(VAR_PIT_FLOOR) < 50) // second 25 floor rates
    {
        if(randomValue < 45)
            return 1;
        if(randomValue < 75)
            return 2;
        if(randomValue < 95)
            return 3;
        if(randomValue < 100)
            return 4;
        return 0;
    }
    else if(VarGet(VAR_PIT_FLOOR) < 75)  // third 25 floor rates
    {
        if(randomValue < 30)
            return 1;
        if(randomValue < 60)
            return 2;
        if(randomValue < 90)
            return 3;
        if(randomValue < 100)
            return 4;
        return 0;
    }
    else  // last 25 floor rates and post level 100 rates
    {
        if(randomValue < 20)
            return 1;
        if(randomValue < 40)
            return 2;
        if(randomValue < 80)
            return 3;
        if(randomValue < 100)
            return 4;
        return 0;
    }   
    return 0;
}

void PlayerPartyCountToResultVar()
{
    VarSet(VAR_RESULT, gPlayerPartyCount);
}

void RemovePartyPokemon(void)
{
    ZeroMonData(&gPlayerParty[VarGet(VAR_RESULT)]);
    CompactPartySlots();
    CalculatePlayerPartyCount();
}

void SetRandomTrainersMixedDoubles(void);
void SetRandomTrainers(void)
{
    u16 iterator = 0;
    u16 trainerCount = 0;
    u16 trainers[4] = {0, 0, 0, 0};

    if(FlagGet(FLAG_MIXED_DOUBLES_MODE))
    {
        SetRandomTrainersMixedDoubles();
        return;
    }

    trainerCount = ReturnNumberOfTrainersForFloor();

    VarSet(VAR_LAST_FLOOR_TRAINER_NUMBER, trainerCount);

    // Handle Random Trainers That Are Spawned
    for (iterator = 0; iterator < trainerCount; iterator++)
    {
        u16 newTrainer = (Random() % 4);
        while(trainers[newTrainer])
        {
            newTrainer = (Random() % 4);
        }
        trainers[newTrainer] = 1;
        if(FlagGet(FLAG_DOUBLES_MODE))
        {
            VarSet(RandomNPCTrainers_Doubles[newTrainer].gfxid, (Random() % 53) + 5);
            VarSet(RandomNPCTrainers_Doubles[newTrainer].defeatTextVar, Random() % 77);
            ClearTrainerFlag(RandomNPCTrainers_Doubles[newTrainer].trainerflag); 
            FlagClear(RandomNPCTrainers_Doubles[newTrainer].objectflag); 
        }
        else
        {
            VarSet(RandomNPCTrainers[newTrainer].gfxid, (Random() % 53) + 5);
            VarSet(RandomNPCTrainers[newTrainer].defeatTextVar, Random() % 77);
            ClearTrainerFlag(RandomNPCTrainers[newTrainer].trainerflag); 
            FlagClear(RandomNPCTrainers[newTrainer].objectflag); 
        }
        
    }

    // Handle Random Trainer Objects That Aren't Spawned
    for (iterator = 0; iterator < 4; iterator++)
    {
        if (!trainers[iterator])
        {
            if(FlagGet(FLAG_DOUBLES_MODE))
            {
                FlagSet(RandomNPCTrainers_Doubles[iterator].objectflag);
                SetTrainerFlag(RandomNPCTrainers_Doubles[iterator].trainerflag);
            }
            else
            {
                FlagSet(RandomNPCTrainers[iterator].objectflag);
                SetTrainerFlag(RandomNPCTrainers[iterator].trainerflag);
            }
        }
        if(FlagGet(FLAG_DOUBLES_MODE))
        {
            FlagSet(RandomNPCTrainers[iterator].objectflag);
            SetTrainerFlag(RandomNPCTrainers[iterator].trainerflag);
        }
        else
        {
            FlagSet(RandomNPCTrainers_Doubles[iterator].objectflag);
            SetTrainerFlag(RandomNPCTrainers_Doubles[iterator].trainerflag);
        }
    }
}

void SetRandomTrainersMixedDoubles(void)
{
    u16 iterator = 0;
    u16 trainerCount = ReturnNumberOfTrainersForFloor();
    u16 trainers[4] = {0, 0, 0, 0};

    VarSet(VAR_LAST_FLOOR_TRAINER_NUMBER, trainerCount);

    // Handle Random Trainer Objects That Aren't Spawned
    for (iterator = 0; iterator < 4; iterator++)
    {
        FlagSet(RandomNPCTrainers_Doubles[iterator].objectflag);
        SetTrainerFlag(RandomNPCTrainers_Doubles[iterator].trainerflag);

        FlagSet(RandomNPCTrainers[iterator].objectflag);
        SetTrainerFlag(RandomNPCTrainers[iterator].trainerflag);

    }

    // Handle Random Trainers That Are Spawned
    for (iterator = 0; iterator < trainerCount; iterator++)
    {
        u16 newTrainer = (Random() % 4);
        u8 reroll = FALSE;

        while(trainers[newTrainer] || reroll)
        {
            newTrainer = (Random() % 4);

            if(trainers[newTrainer] == 1)
            {
                reroll = TRUE;
            }
            else
            {
                reroll = FALSE;
            }
        }

        trainers[newTrainer] = 1;

        if(Random() % 2)
        {
            VarSet(RandomNPCTrainers_Doubles[newTrainer].gfxid, (Random() % 53) + 5);
            VarSet(RandomNPCTrainers_Doubles[newTrainer].defeatTextVar, Random() % 77);
            ClearTrainerFlag(RandomNPCTrainers_Doubles[newTrainer].trainerflag); 
            FlagClear(RandomNPCTrainers_Doubles[newTrainer].objectflag); 
        }
        else
        {
            VarSet(RandomNPCTrainers[newTrainer].gfxid, (Random() % 53) + 5);
            VarSet(RandomNPCTrainers[newTrainer].defeatTextVar, Random() % 77);
            ClearTrainerFlag(RandomNPCTrainers[newTrainer].trainerflag); 
            FlagClear(RandomNPCTrainers[newTrainer].objectflag); 
        }
    }
}

void CheckFloorCleared()
{
    u16 iterator = 0;
    u16 trainerDefeated = 0;
    for (iterator = 0; iterator < 8; iterator++)
    {
        if(iterator > 3)
            trainerDefeated = (u8) FlagGet(TRAINER_FLAGS_START + RandomNPCTrainers_Doubles[iterator - 4].trainerflag) + trainerDefeated;
        else
            trainerDefeated = (u8) FlagGet(TRAINER_FLAGS_START + RandomNPCTrainers[iterator].trainerflag) + trainerDefeated;
    }
    if (trainerDefeated == 8)
        FlagSet(FLAG_FLOOR_CLEARED);
    return;
}
u16 ReturnTrainersRemaining()
{
    u16 iterator = 0;
    u16 trainerDefeated = 0;
    for (iterator = 0; iterator < 8; iterator++)
    {
        if(iterator > 3)
            trainerDefeated = (u8) FlagGet(TRAINER_FLAGS_START + RandomNPCTrainers_Doubles[iterator - 4].trainerflag) + trainerDefeated;
        else
            trainerDefeated = (u8) FlagGet(TRAINER_FLAGS_START + RandomNPCTrainers[iterator].trainerflag) + trainerDefeated;
    }
    return 8 - trainerDefeated;
}

void BufferMapFloorString()
{
    ConvertIntToDecimalStringN(gStringVar1, VarGet(VAR_PIT_FLOOR), STR_CONV_MODE_LEFT_ALIGN, 3);
}

void StartNewPokeballCaseUI(void)
{
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_OpenBirchCase, 0);
}

void CallModeMenu(void)
{
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_OpenModeMenu, 0);
}

void AutoSave(void)
{
    ScriptContext_Stop();
    AutoSaveDoSaveCallback();
    FlagSet(FLAG_SAVING_FIELD_EFFECT);
    ScriptContext_Enable();
}

void SetAutosaveFlag(void)
{
    switch(gSaveBlock2Ptr->optionsAutosave)
    {
        case SAVE_NO:
            FlagClear(FLAG_AUTO_SAVE);
            break;
        case SAVE_5_FLOORS:
            if((VarGet(VAR_PIT_FLOOR) % 5) == 0) //every fifth floor
                FlagSet(FLAG_AUTO_SAVE);
            else
                FlagClear(FLAG_AUTO_SAVE);
            break;
        case SAVE_EACH_FLOOR:
            FlagSet(FLAG_AUTO_SAVE);
            break;
    }
    
}

// Avatar Code

struct PitAvatarInfo {
    u16 mugshotId;
    u16 graphicsId;
    u16 trainerFrontPicId;
    u16 trainerBackPicId;
};

#define PIT_AVATAR_COUNT ARRAY_COUNT(sPitAvatars)
static const struct PitAvatarInfo sPitAvatars[] = {
    {
        .mugshotId = AVATAR_BRENDAN,
        .graphicsId = OBJ_EVENT_GFX_BRENDAN_NORMAL,
        .trainerFrontPicId = TRAINER_PIC_BRENDAN,
        .trainerBackPicId = TRAINER_BACK_PIC_BRENDAN,
    },
    {
        .mugshotId = AVATAR_MAY,
        .graphicsId = OBJ_EVENT_GFX_MAY_NORMAL,
        .trainerFrontPicId = TRAINER_PIC_MAY,
        .trainerBackPicId = TRAINER_BACK_PIC_MAY,
    },

    {
        .mugshotId = AVATAR_RED,
        .graphicsId = OBJ_EVENT_GFX_RED,
        .trainerFrontPicId = TRAINER_PIC_RED,
        .trainerBackPicId = TRAINER_BACK_PIC_RED,
    },
    {
        .mugshotId = AVATAR_LEAF,
        .graphicsId = OBJ_EVENT_GFX_LEAF,
        .trainerFrontPicId = TRAINER_PIC_LEAF,
        .trainerBackPicId = TRAINER_BACK_PIC_LEAF,
    },

    {
        .mugshotId = AVATAR_LUCAS,
        .graphicsId = OBJ_EVENT_GFX_LUCAS,
        .trainerFrontPicId = TRAINER_PIC_LUCAS,
        .trainerBackPicId = TRAINER_BACK_PIC_LUCAS,
    },
    {
        .mugshotId = AVATAR_DAWN,
        .graphicsId = OBJ_EVENT_GFX_DAWN,
        .trainerFrontPicId = TRAINER_PIC_DAWN,
        .trainerBackPicId = TRAINER_BACK_PIC_DAWN,
    },

    {
        .mugshotId = AVATAR_ETHAN,
        .graphicsId = OBJ_EVENT_GFX_ETHAN,
        .trainerFrontPicId = TRAINER_PIC_ETHAN,
        .trainerBackPicId = TRAINER_BACK_PIC_ETHAN,
    },
    {
        .mugshotId = AVATAR_LYRA,
        .graphicsId = OBJ_EVENT_GFX_LYRA,
        .trainerFrontPicId = TRAINER_PIC_LYRA,
        .trainerBackPicId = TRAINER_BACK_PIC_LYRA,
    },

    {
        .mugshotId = AVATAR_STEVEN,
        .graphicsId = OBJ_EVENT_GFX_STEVEN,
        .trainerFrontPicId = TRAINER_PIC_STEVEN,
        .trainerBackPicId = TRAINER_BACK_PIC_STEVEN,
    },
    {
        .mugshotId = AVATAR_CYNTHIA,
        .graphicsId = OBJ_EVENT_GFX_CYNTHIA,
        .trainerFrontPicId = TRAINER_PIC_CYNTHIA,
        .trainerBackPicId = TRAINER_BACK_PIC_CYNTHIA,
    },

    {
        .mugshotId = AVATAR_OAK,
        .graphicsId = OBJ_EVENT_GFX_OAK,
        .trainerFrontPicId = TRAINER_PIC_OAK,
        .trainerBackPicId = TRAINER_BACK_PIC_OAK,
    },
    {
        .mugshotId = AVATAR_PHOEBE,
        .graphicsId = OBJ_EVENT_GFX_PHOEBE,
        .trainerFrontPicId = TRAINER_PIC_ELITE_FOUR_PHOEBE,
        .trainerBackPicId = TRAINER_BACK_PIC_PHOEBE,
    },

    {
        .mugshotId = AVATAR_POKEMON_CHOICE,
        .graphicsId = 0xFFFF,
        .trainerFrontPicId = TRAINER_PIC_BRENDAN,
        .trainerBackPicId = TRAINER_BACK_PIC_BRENDAN,
    },

};

u16 ReturnAvatarMugshotId(u16 avatarId)
{
    return sPitAvatars[avatarId].mugshotId;
}

u16 ReturnAvatarGraphicsId(u16 avatarId)
{
    u16 graphicsId = sPitAvatars[avatarId].graphicsId;
    if(graphicsId == 0xFFFF)
    {
        graphicsId = OBJ_EVENT_GFX_VAR_D;
        VarSet(VAR_AVATAR_POKEMON_CHOICE, SPECIES_LOTAD);
        VarSet(VAR_OBJ_GFX_ID_D, VarGet(VAR_AVATAR_POKEMON_CHOICE) + OBJ_EVENT_GFX_MON_BASE);
    }
    return graphicsId;
}

u16 ReturnAvatarTrainerFrontPicId(u16 avatarId)
{
    return sPitAvatars[avatarId].trainerFrontPicId;
}

u16 ReturnAvatarTrainerBackPicId(u16 avatarId)
{
    return sPitAvatars[avatarId].trainerBackPicId;
}

void SetPlayerAvatar(void)
{
    gSaveBlock2Ptr->playerGfxType = VarGet(VAR_RESULT);
    gSaveBlock2Ptr->playerGender  = VarGet(VAR_RESULT) % 2;
}

void LevelUpParty(void)
{   
    if(!(FlagGet(FLAG_NO_EXP_MODE)))
        return;

    if(VarGet(VAR_PIT_FLOOR) <= 5)
        return;

    u32 i = 0;
    for(i = 0; i < 6; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        ForceIncrementMonLevel(mon);
        MonTryLearningNewMove(mon, TRUE);
    }
    return;
}

struct sRandomMap {
    u16 mapConstant;
    u16 warpMetatileId;
    u16 battleTerrainId;
    u16 dest_x;
    u16 dest_y;
    u16 warp_x;
    u16 warp_y;
};

// Default Coords for Random Maps size 20x20 with the warp in the center at 9x9
#define DEFAULT_RANDOM_MAP_COORDS           .dest_x = 9,    \
                                            .dest_y = 8,    \
                                            .warp_x = 9,    \
                                            .warp_y = 9,

#define RANDOM_MAP_COUNT    ARRAY_COUNT(sRandomMapArray)
static const struct sRandomMap sRandomMapArray[] = {
    {
        .mapConstant = MAP_PIT_ARENA,
        .warpMetatileId = METATILE_Cave_FLOOR_COMPLETE,
        .battleTerrainId = BATTLE_TERRAIN_CAVE,
        DEFAULT_RANDOM_MAP_COORDS
    },     
    {
        .mapConstant = MAP_PIT_ARENA_BEACH,
        .warpMetatileId = METATILE_PitArenaBeach_BEACH_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_SAND,
        DEFAULT_RANDOM_MAP_COORDS
    },  
    {
        .mapConstant = MAP_PIT_ARENA_WATER,
        .warpMetatileId = METATILE_PitWaterTheme_WATER_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_WATER,
        DEFAULT_RANDOM_MAP_COORDS
    },  
    {
        .mapConstant = MAP_PIT_ARENA_DESERT,
        .warpMetatileId = METATILE_PitArenaDesert_DESERT_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_SAND,
        DEFAULT_RANDOM_MAP_COORDS
    },  
    {
        .mapConstant = MAP_PIT_ARENA_SNOW,
        .warpMetatileId = METATILE_PitArenaSnow_SNOW_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_MOUNTAIN,
        DEFAULT_RANDOM_MAP_COORDS
    },  
    {
        .mapConstant = MAP_PIT_ARENA_MUSHROOM_WOODS,
        .warpMetatileId = METATILE_PitArenaMushroomWoods_MUSHROOM_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_GRASS,
        DEFAULT_RANDOM_MAP_COORDS
    },        
    {
        .mapConstant = MAP_PIT_ARENA_DIRT_PATH,
        .warpMetatileId = METATILE_PitArenaDirtPath_DIRT_PATH_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_MOUNTAIN,
        DEFAULT_RANDOM_MAP_COORDS
    },    
    {
        .mapConstant = MAP_PIT_ARENA_SPIDER_WOODS,
        .warpMetatileId = METATILE_PitArenaSpiderWoods_SPIDER_WOODS_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_GRASS,
        DEFAULT_RANDOM_MAP_COORDS
    },    
    {
        .mapConstant = MAP_PIT_ARENA_UNDERWATER,
        .warpMetatileId = METATILE_PitArenaUnderwater_UNDERWATER_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_UNDERWATER,
        DEFAULT_RANDOM_MAP_COORDS
    },    
    {
        .mapConstant = MAP_PIT_ARENA_MINE,
        .warpMetatileId = METATILE_PitArenaMine_MINE_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_CAVE,
        DEFAULT_RANDOM_MAP_COORDS
    },    
    {
        .mapConstant = MAP_PIT_ARENA_WHITE_BARK,
        .warpMetatileId = METATILE_PitArenaWhiteBark_WHITEBARK_WARP_ACTIVE,
        .battleTerrainId = BATTLE_TERRAIN_GRASS,
        DEFAULT_RANDOM_MAP_COORDS
    },                   
};

void WarpToRandomPitArena(void)
{
    u16 index;
    u16 indexCurrentMap = VarGet(VAR_PIT_CURRENT_MAP_INDEX_IN_ARRAY);

    do
    {
        index = Random() % RANDOM_MAP_COUNT;
    }
    while (index == indexCurrentMap); //don't roll the current map again

     //return default map if randomization is turned off
    if (!FlagGet(FLAG_RANDOM_MAPS))
        index = 0;
    
    VarSet(VAR_PIT_CURRENT_MAP_INDEX_IN_ARRAY, index);
    SetWarpDestination(0, (u8)(sRandomMapArray[index].mapConstant & 0x00FF), WARP_ID_NONE, sRandomMapArray[index].dest_x, sRandomMapArray[index].dest_y);
    DoTeleportTileWarp();
    ResetInitialPlayerAvatarState();
    return;
}

void SetWarpTileActive(void)
{
    u16 currentIndex = VarGet(VAR_PIT_CURRENT_MAP_INDEX_IN_ARRAY);
    if(currentIndex != 0xFF)
        MapGridSetMetatileIdAt(sRandomMapArray[currentIndex].warp_x + MAP_OFFSET, sRandomMapArray[currentIndex].warp_y + MAP_OFFSET, sRandomMapArray[currentIndex].warpMetatileId);
}

u16 GetRandomMapTerrain(void)
{   
    u16 currentIndex = VarGet(VAR_PIT_CURRENT_MAP_INDEX_IN_ARRAY);
    if(currentIndex != 0xFF)
    {
        return sRandomMapArray[currentIndex].battleTerrainId;
    }
    return BATTLE_TERRAIN_CAVE;
}

u16 GetCurrentMapConstant(void)
{
    u16 currentIndex = VarGet(VAR_PIT_CURRENT_MAP_INDEX_IN_ARRAY);
    if(currentIndex != 0xFF)
    {
        return sRandomMapArray[currentIndex].mapConstant;
    }
    return MAP_PIT_ARENA;
}

struct RandomMonEncounters {
    u16 species;
    u16 flagId; // id into gSaveBlock2Ptr->randomMonEncounters not normal flags
    const u8 *monScript;
};

#define RANDOM_ENCOUNTER_COUNT ARRAY_COUNT(sRandomEncounterArray)
static const struct RandomMonEncounters sRandomEncounterArray[] = {
    {
        .species = SPECIES_ABRA,
        .flagId = 0,
        .monScript = PitEncounter_Mover,
    },
    {
        .species = SPECIES_JIRACHI,
        .flagId = 1,
        .monScript = PitEncounter_HealOneMon,
    },
    {
        .species = SPECIES_SHEDINJA,
        .flagId = 2,
        .monScript = PitEncounter_ReviveOneMon,
    },
    {
        .species = SPECIES_CHANSEY,
        .flagId = 3,
        .monScript = PitEncounter_LuckyEggDrop,
    },
    {
        .species = SPECIES_MEOWTH,
        .flagId = 4,
        .monScript = PitEncounter_AmuletCoinDrop,
    },
    {
        .species = SPECIES_DELIBIRD,
        .flagId = 5,
        .monScript = PitEncounter_NuggetDrop,
    },
    {
        .species = SPECIES_ZIGZAGOON,
        .flagId = 6,
        .monScript = PitEncounter_WonderTrade,
    },
    {
        .species = SPECIES_MILTANK,
        .flagId = 7,
        .monScript = PitEncounter_MooMooMilkDrop,
    },
    {
        .species = SPECIES_CHIMECHO,
        .flagId = 8,
        .monScript = PitEncounter_CureAllStatus,
    },
    {
        .species = SPECIES_MUNCHLAX,
        .flagId = 9,
        .monScript = PitEncounter_RareCandyDrop,
    },
};

u8 *GetEncounterFlagPointer(u16 id)
{
    return &gSaveBlock2Ptr->randomMonEncounters[id / 8];
}

u8 EncounterFlagSet(u16 id)
{
    u8 *ptr = GetEncounterFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
    return 0;
}

u8 EncounterFlagClear(u16 id)
{
    u8 *ptr = GetEncounterFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
    return 0;
}

bool8 EncounterFlagGet(u16 id)
{
    u8 *ptr = GetEncounterFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}

bool8 RemainingEncounters(void)
{
    u8 i = 0;
    for(i = 0; i < RANDOM_ENCOUNTER_COUNT; i++)
    {
        if(!EncounterFlagGet(i))
            return TRUE;
    }
    return FALSE;
}

void ClearAllRandomEncounters(void)
{
    u8 i = 0;
    for(i = 0; i < RANDOM_ENCOUNTER_COUNT; i++)
    {
        EncounterFlagClear(i);
    }
}

void SetRandomMonEncounter(void)
{
    bool8 reroll = FALSE;
    FlagSet(FLAG_OVERWORLD_MON_ENCOUNTER);

    if (Random() % 5) // Odds of A Random Encounter On Each Floor
        return;

    if(VarGet(VAR_PIT_FLOOR) <= 5)
        return;

    if(!RemainingEncounters()) // Cancel if All Random Encounters have been done
        return;

    do {
        u16 index = Random() % RANDOM_ENCOUNTER_COUNT;
        if(EncounterFlagGet(index))
        {
            reroll = TRUE;
        }
        else
        {
            reroll = FALSE;
            EncounterFlagSet(index);
            VarSet(VAR_OVERWORLD_MON_SPECIES, sRandomEncounterArray[index].species);
            VarSet(VAR_CURRENT_OVERWORLD_ENCOUNTER_INDEX, index);
            FlagClear(FLAG_OVERWORLD_MON_ENCOUNTER);
            FlagClear(FLAG_USED_RANDOM_ENCOUNTER_THIS_FLOOR);
            return;
        }
    } while (reroll);

}

void CallRandomMonEncounterScript(void)
{
    if(FlagGet(FLAG_USED_RANDOM_ENCOUNTER_THIS_FLOOR))
    {
        ScriptContext_SetupScript(PitEncounter_Common_AlreadyUsedEffect); // Can Swap for a Mon Specific Post Script From the Struct if we want
    }
    else
    {
        ScriptContext_SetupScript(sRandomEncounterArray[VarGet(VAR_CURRENT_OVERWORLD_ENCOUNTER_INDEX)].monScript);
    }
}

void HealPlayerPokemon(void)
{
    HealPokemon(&gPlayerParty[VarGet(VAR_0x8005)]);
}

void CheckMonFainted(void)
{
    struct Pokemon *pokemon = &gPlayerParty[VarGet(VAR_0x8005)];
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES_OR_EGG);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
    {
        VarSet(VAR_RESULT, FALSE);
        return;
    }
    if ((GetMonData(pokemon, MON_DATA_HP) == 0))
        VarSet(VAR_RESULT, TRUE);
    else
        VarSet(VAR_RESULT, FALSE);
}

void HealAllStatus(void)
{
    u32 status = 0;
    for(u8 i = 0; i < 6; i++)
    {
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, &status);
    }
}

static const u16 sRandomOverworldSongs[] = {
    MUS_C_COMM_CENTER,
    MUS_ROUTE101,
    MUS_ROUTE110,
    MUS_ROUTE120,
    MUS_PETALBURG,
    MUS_OLDALE,
    MUS_GYM,
    MUS_SURF,
    MUS_PETALBURG_WOODS,
    MUS_LILYCOVE_MUSEUM,
    MUS_ROUTE122,
    MUS_OCEANIC_MUSEUM,
    MUS_ABANDONED_SHIP,
    MUS_FORTREE,
    MUS_BIRCH_LAB,
    MUS_B_TOWER_RS,
    MUS_CAVE_OF_ORIGIN,
    MUS_AWAKEN_LEGEND,
    MUS_VERDANTURF,
    MUS_RUSTBORO,
    MUS_POKE_CENTER,
    MUS_ROUTE104,
    MUS_ROUTE119,
    MUS_CYCLING,
    MUS_POKE_MART,
    MUS_LITTLEROOT,
    MUS_MT_CHIMNEY,
    MUS_LILYCOVE,
    MUS_ROUTE111,
    MUS_UNDERWATER,
    MUS_ROUTE113,
    MUS_EVER_GRANDE,
    MUS_CABLE_CAR,
    MUS_GAME_CORNER,
    MUS_DEWFORD,
    MUS_SAFARI_ZONE,
    MUS_VICTORY_ROAD,
    MUS_AQUA_MAGMA_HIDEOUT,
    MUS_SAILING,
    MUS_MT_PYRE,
    MUS_SLATEPORT,
    MUS_MT_PYRE_EXTERIOR,
    MUS_SCHOOL,
    MUS_FALLARBOR,
    MUS_SEALED_CHAMBER,
    MUS_CONTEST,
    MUS_WEATHER_KYOGRE,
    MUS_SOOTOPOLIS,
    MUS_HALL_OF_FAME_ROOM,
    MUS_TRICK_HOUSE,
    MUS_CONTEST_LOBBY,
    MUS_RG_GAME_CORNER,
    MUS_RG_ROCKET_HIDEOUT,
    MUS_RG_GYM,
    MUS_RG_CINNABAR,
    MUS_RG_LAVENDER,
    MUS_RG_CYCLING,
    MUS_RG_HALL_OF_FAME,
    MUS_RG_VIRIDIAN_FOREST,
    MUS_RG_MT_MOON,
    MUS_RG_POKE_MANSION,
    MUS_RG_ROUTE1,
    MUS_RG_ROUTE24,
    MUS_RG_ROUTE3,
    MUS_RG_ROUTE11,
    MUS_RG_VICTORY_ROAD,
    MUS_RG_PALLET,
    MUS_RG_OAK_LAB,
    MUS_RG_POKE_CENTER,
    MUS_RG_SS_ANNE,
    MUS_RG_SURF,
    MUS_RG_POKE_TOWER,
    MUS_RG_SILPH,
    MUS_RG_FUCHSIA,
    MUS_RG_CELADON,
    MUS_RG_VERMILLION,
    MUS_RG_PEWTER,
    MUS_RG_SEVII_ROUTE,
    MUS_ABNORMAL_WEATHER,
    MUS_B_FRONTIER,
    MUS_B_ARENA,
    MUS_B_PYRAMID,
    MUS_B_PALACE,
    MUS_B_TOWER,
    MUS_B_DOME,
    MUS_B_PIKE,
    MUS_B_FACTORY,
    MUS_DP_TWINLEAF_DAY,
    MUS_DP_SANDGEM_DAY,
    MUS_DP_FLOAROMA_DAY,
    MUS_DP_SOLACEON_DAY,
    MUS_DP_ROUTE225_DAY,
    MUS_DP_VALOR_LAKEFRONT_DAY,
    MUS_DP_JUBILIFE_DAY,
    MUS_DP_CANALAVE_DAY,
    MUS_DP_OREBURGH_DAY,
    MUS_DP_ETERNA_DAY,
    MUS_DP_HEARTHOME_DAY,
    MUS_DP_VEILSTONE_DAY,
    MUS_DP_SUNYSHORE_DAY,
    MUS_DP_SNOWPOINT_DAY,
    MUS_DP_FIGHT_AREA_DAY,
    MUS_DP_ROUTE201_DAY,
    MUS_DP_ROUTE203_DAY,
    MUS_DP_ROUTE205_DAY,
    MUS_DP_ROUTE206_DAY,
    MUS_DP_ROUTE209_DAY,
    MUS_DP_ROUTE210_DAY,
    MUS_DP_ROUTE216_DAY,
    MUS_DP_ROUTE228_DAY,
    MUS_DP_UNDERGROUND,
    MUS_DP_VICTORY_ROAD,
    MUS_DP_ETERNA_FOREST,
    MUS_DP_OLD_CHATEAU,
    MUS_DP_LAKE_CAVERNS,
    MUS_DP_AMITY_SQUARE,
    MUS_DP_GALACTIC_HQ,
    MUS_DP_GALACTIC_ETERNA_BUILDING,
    MUS_DP_GREAT_MARSH,
    MUS_DP_LAKE,
    MUS_DP_MT_CORONET,
    MUS_DP_SPEAR_PILLAR,
    MUS_DP_STARK_MOUNTAIN,
    MUS_DP_OREBURGH_GATE,
    MUS_DP_OREBURGH_MINE,
    MUS_DP_INSIDE_POKEMON_LEAGUE,
    MUS_DP_HALL_OF_FAME_ROOM,
    MUS_DP_POKE_CENTER_DAY,
    MUS_DP_GYM,
    MUS_DP_ROWAN_LAB,
    MUS_DP_CONTEST_LOBBY,
    MUS_DP_POKE_MART,
    MUS_DP_GAME_CORNER,
    MUS_DP_B_TOWER,
    MUS_DP_TV_STATION,
    MUS_DP_GTS,
    MUS_DP_SURF,
    MUS_DP_CYCLING,
    MUS_PL_B_ARCADE,
    MUS_PL_B_HALL,
    MUS_PL_B_CASTLE,
    MUS_PL_B_FACTORY,
    MUS_PL_LILYCOVE_BOSSA_NOVA,
    MUS_HG_CYCLING,
    MUS_HG_SURF,
    MUS_HG_NEW_BARK,
    MUS_HG_CHERRYGROVE,
    MUS_HG_VIOLET,
    MUS_HG_AZALEA,
    MUS_HG_GOLDENROD,
    MUS_HG_ECRUTEAK,
    MUS_HG_CIANWOOD,
    MUS_HG_ROUTE29,
    MUS_HG_ROUTE30,
    MUS_HG_ROUTE34,
    MUS_HG_ROUTE38,
    MUS_HG_ROUTE42,
    MUS_HG_VERMILION,
    MUS_HG_PEWTER,
    MUS_HG_CERULEAN,
    MUS_HG_LAVENDER,
    MUS_HG_CELADON,
    MUS_HG_PALLET,
    MUS_HG_CINNABAR,
    MUS_HG_ROUTE1,
    MUS_HG_ROUTE3,
    MUS_HG_ROUTE11,
    MUS_HG_ROUTE24,
    MUS_HG_ROUTE26,
    MUS_HG_POKE_CENTER,
    MUS_HG_POKE_MART,
    MUS_HG_GYM,
    MUS_HG_ELM_LAB,
    MUS_HG_DANCE_THEATER,
    MUS_HG_GAME_CORNER,
    MUS_HG_B_TOWER,
    MUS_HG_SPROUT_TOWER,
    MUS_HG_UNION_CAVE,
    MUS_HG_RUINS_OF_ALPH,
    MUS_HG_NATIONAL_PARK,
    MUS_HG_BURNED_TOWER,
    MUS_HG_BELL_TOWER,
    MUS_HG_LIGHTHOUSE,
    MUS_HG_TEAM_ROCKET_HQ,
    MUS_HG_ICE_PATH,
    MUS_HG_DRAGONS_DEN,
    MUS_HG_ROCK_TUNNEL,
    MUS_HG_VIRIDIAN_FOREST,
    MUS_HG_VICTORY_ROAD,
    MUS_HG_POKEMON_LEAGUE,
    MUS_HG_POKEATHLON_LOBBY,
    MUS_HG_B_FACTORY,
    MUS_HG_B_HALL,
    MUS_HG_B_ARCADE,
    MUS_HG_B_CASTLE,
    MUS_HG_ROUTE47,
    MUS_HG_SAFARI_ZONE_GATE,
    MUS_HG_SAFARI_ZONE,
};

#define NUM_OVERWORLD_SONGS 198

void TrySetRandomMusic(void)
{
    if (!gSaveBlock2Ptr->optionsRandomMusic)
        return;

    u16 songIndex = Random() % NUM_OVERWORLD_SONGS;
    Overworld_SetSavedMusic(sRandomOverworldSongs[songIndex]);
    PlayNewMapMusic(sRandomOverworldSongs[songIndex]);
}


// Boss Encounter Code

struct RandomBossEncounters {
    u16 graphicsId;
    u16 trainerPic;
    u16 flagId; // id into gSaveBlock2Ptr->randomBossEncounters not normal flags
    const u8 *bossName;
    const u8 *bossApproachText;
    const u8 *bossLoseText;
    const u8 *bossAceText;
    const struct TrainerMon trainerAce;
};

#define RANDOM_BOSS_ENCOUNTER_COUNT ARRAY_COUNT(sRandomBossEncounterArray)
static const struct RandomBossEncounters sRandomBossEncounterArray[] = {
    {
        .graphicsId = OBJ_EVENT_GFX_ARCHIE,
        .trainerPic = TRAINER_PIC_AQUA_LEADER_ARCHIE,
        .flagId = 0,
        .bossName = COMPOUND_STRING("Archie"),
        .bossApproachText =  COMPOUND_STRING("You've made it quite far...\n"
                                            "But your run ends here!$"),
        .bossLoseText =     COMPOUND_STRING("Well... That went about as\n"
                                            "well as dry land.$"),
        .bossAceText =      COMPOUND_STRING("You have proven yourself worthy!\p"
                                            "But I have one more trick\n"
                                            "up my sleeve.\p"
                                            "Welcome the GOD OF THE SEAS...$"),
        .trainerAce =   {
                            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
                            .ev = TRAINER_PARTY_EVS(0, 0, 4, 252, 252, 0),
                            .lvl = 100,
                            .species = SPECIES_KYOGRE,
                            .heldItem = ITEM_LEFTOVERS,
                            .ability = 0,
                            .nature = NATURE_MODEST,
                            .moves = {MOVE_LIQUIDATION, MOVE_THUNDER, MOVE_ORIGIN_PULSE, MOVE_ICE_BEAM}
                        },
    },
    {
        .graphicsId = OBJ_EVENT_GFX_MAXIE,
        .trainerPic = TRAINER_PIC_MAGMA_LEADER_MAXIE,
        .flagId = 1,
        .bossName = COMPOUND_STRING("Maxie"),
        .bossApproachText =  COMPOUND_STRING("You've made it quite far...\n"
                                            "But your run ends here!$"),
        .bossLoseText =     COMPOUND_STRING("Well... That went about as\n"
                                            "well as the ocean.$"),
        .bossAceText =      COMPOUND_STRING("You have proven yourself worthy!\p"
                                            "But I have one more trick\n"
                                            "up my sleeve.\p"
                                            "Welcome the GOD OF THE EARTH...$"),
        .trainerAce =   {
                            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
                            .ev = TRAINER_PARTY_EVS(0, 0, 4, 252, 252, 0),
                            .lvl = 100,
                            .species = SPECIES_GROUDON,
                            .heldItem = ITEM_LEFTOVERS,
                            .ability = 0,
                            .nature = NATURE_MODEST,
                            .moves = {MOVE_LIQUIDATION, MOVE_THUNDER, MOVE_ORIGIN_PULSE, MOVE_ICE_BEAM}
                        },
    },
    {
        .graphicsId = OBJ_EVENT_GFX_WATTSON,
        .trainerPic = TRAINER_PIC_LEADER_WATTSON,
        .flagId = 2,
        .bossName = COMPOUND_STRING("Watson"),
        .bossApproachText =  COMPOUND_STRING("You've made it quite far...\n"
                                            "But your run ends here!$"),
        .bossLoseText =     COMPOUND_STRING("Well... That went about as\n"
                                            "well as the ground.$"),
        .bossAceText =      COMPOUND_STRING("You have proven yourself worthy!\p"
                                            "But I have one more trick\n"
                                            "up my sleeve.\p"
                                            "Welcome the GOD OF THE LIGHTNING...$"),
        .trainerAce =   {
                            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
                            .ev = TRAINER_PARTY_EVS(0, 0, 4, 252, 252, 0),
                            .lvl = 100,
                            .species = SPECIES_MANECTRIC,
                            .heldItem = ITEM_LEFTOVERS,
                            .ability = 0,
                            .nature = NATURE_MODEST,
                            .moves = {MOVE_LIQUIDATION, MOVE_THUNDER, MOVE_ORIGIN_PULSE, MOVE_ICE_BEAM}
                        },
    },
    {
        .graphicsId = OBJ_EVENT_GFX_NORMAN,
        .trainerPic = TRAINER_PIC_LEADER_NORMAN,
        .flagId = 3,
        .bossName = COMPOUND_STRING("Norman"),
        .bossApproachText =  COMPOUND_STRING("You've made it quite far...\n"
                                            "But your run ends here!$"),
        .bossLoseText =     COMPOUND_STRING("Well... That went about as\n"
                                            "well as the ground.$"),
        .bossAceText =      COMPOUND_STRING("You have proven yourself worthy!\p"
                                            "But I have one more trick\n"
                                            "up my sleeve.\p"
                                            "Welcome the GOD OF THE LIGHTNING...$"),
        .trainerAce =   {
                            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
                            .ev = TRAINER_PARTY_EVS(0, 0, 4, 252, 252, 0),
                            .lvl = 100,
                            .species = SPECIES_SLAKING,
                            .heldItem = ITEM_LEFTOVERS,
                            .ability = 0,
                            .nature = NATURE_MODEST,
                            .moves = {MOVE_LIQUIDATION, MOVE_THUNDER, MOVE_ORIGIN_PULSE, MOVE_ICE_BEAM}
                        },
    },
};

u8 *GetBossEncounterFlagPointer(u16 id)
{
    return &gSaveBlock2Ptr->randomBossEncounters[id / 8];
}

u8 BossEncounterFlagSet(u16 id)
{
    u8 *ptr = GetBossEncounterFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
    return 0;
}

u8 BossEncounterFlagClear(u16 id)
{
    u8 *ptr = GetBossEncounterFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
    return 0;
}

bool8 BossEncounterFlagGet(u16 id)
{
    u8 *ptr = GetBossEncounterFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}

bool8 RemainingBossEncounters(void)
{
    u8 i = 0;
    for(i = 0; i < RANDOM_ENCOUNTER_COUNT; i++)
    {
        if(!BossEncounterFlagGet(i))
            return TRUE;
    }
    return FALSE;
}

void ClearAllRandomBossEncounters(void)
{
    u8 i = 0;
    for(i = 0; i < RANDOM_ENCOUNTER_COUNT; i++)
    {
        BossEncounterFlagClear(i);
    }
}

void SetRandomBossEncounter(void)
{
    bool8 reroll = FALSE;
        
    do {
        u16 index = Random() % RANDOM_BOSS_ENCOUNTER_COUNT;
        if(BossEncounterFlagGet(index))
        {
            reroll = TRUE;
        }
        else
        {
            reroll = FALSE;
            BossEncounterFlagSet(index);
            VarSet(VAR_OBJ_GFX_ID_F, sRandomBossEncounterArray[index].graphicsId);
            VarSet(VAR_CURRENT_BOSS, index);
            FlagClear(FLAG_BOSS_ENCOUNTER);
            return;
        }
    } while (reroll);

}

const struct TrainerMon *GetRandomBossEncounterAcePokemon(void)
{
    return &sRandomBossEncounterArray[VarGet(VAR_CURRENT_BOSS)].trainerAce;
}

u16 GetRandomBossEncounterTrainerPic(void)
{
    return sRandomBossEncounterArray[VarGet(VAR_CURRENT_BOSS)].trainerPic;
}

const u8 *GetRandomBossEncounterBossName(void)
{
    return sRandomBossEncounterArray[VarGet(VAR_CURRENT_BOSS)].bossName;
}

const u8 *GetRandomBossEncounterBossApproachText(void)
{
    return sRandomBossEncounterArray[VarGet(VAR_CURRENT_BOSS)].bossApproachText;
}

const u8 *GetRandomBossEncounterBossDefeatText(void)
{
    return sRandomBossEncounterArray[VarGet(VAR_CURRENT_BOSS)].bossLoseText;
}

const u8 *GetRandomBossEncounterBossAceText(void)
{
    return sRandomBossEncounterArray[VarGet(VAR_CURRENT_BOSS)].bossAceText;
}


//
//  Random GiveMon Reward Encounters Post Boss Fight 
//

const u16 variableGraphicsIdsForEncounters[9] = {VAR_OBJ_GFX_ID_4, VAR_OBJ_GFX_ID_5, VAR_OBJ_GFX_ID_6, VAR_OBJ_GFX_ID_7,
                                            VAR_OBJ_GFX_ID_8, VAR_OBJ_GFX_ID_9, VAR_OBJ_GFX_ID_A, VAR_OBJ_GFX_ID_B, VAR_OBJ_GFX_ID_C};
static EWRAM_DATA u16 loadedEncounters[9] = {0};

void DebugPrintAllSpecies(void)
{
    for(u8 i = 0; i < 9; i++)
    {
        DebugPrintf("Species: %d", loadedEncounters[i]);
    }
}

void SetRandomGiveMonRewardEncounters(void)
{
    bool8 reroll = FALSE;

    for(u8 i = 0; i < 9; i++)
    {
        do {
            u16 species = GetRandomSpeciesFlattenedCurve();
            VarSet(variableGraphicsIdsForEncounters[i], species + OBJ_EVENT_GFX_MON_BASE);
            loadedEncounters[i] = species;
        } while (reroll);
    }
}

void GiveRandomMonRewardEncounter(void)
{
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u16 species = loadedEncounters[gSpecialVar_LastTalked - 1];
    u16 level = VarGet(VAR_PIT_FLOOR) <= 100 ? VarGet(VAR_PIT_FLOOR) : 100;
    u8 evs[] = {0, 0, 0, 0, 0, 0};
    u8 ivs[] = {31, 31, 31, 31, 31, 31};
    u16 moves[] = {0, 0, 0, 0};
    gSpecialVar_Result = ScriptGiveMonParameterized(species, level, ITEM_NONE, 0, NUM_NATURES, 3, 0, (u8 *) &evs, (u8 *) &ivs, (u16 *) &moves, 0, NUMBER_OF_MON_TYPES, 0);
}

void BufferNameText_RandomMonRewardEncounter(void)
{
    u16 species = loadedEncounters[gSpecialVar_LastTalked - 1];

#ifdef POKEMON_EXPANSION
    StringCopy(gStringVar2, GetSpeciesName(species));
#else
    StringCopy(gStringVar2, &gSpeciesNames[species][0]);
#endif
}


//
//  Overworld Trainers Left HUD
//

static void Task_DelayPrintOverworldHUD(u8 taskId);
static void PrintWarpPriceOnTrainerCount(u32 spriteId, u32 bgColor, u32 startTile);

static EWRAM_DATA u8 gOWHUDSprite;
static EWRAM_DATA u8 gOWHUDSpriteMask;
static const u32 sTrainerCountGfx[] = INCBIN_U32("graphics/interface/trainercount_hud.4bpp.lz");
static const u16 sTrainerCountPal[] = INCBIN_U16("graphics/interface/trainercount_hud.gbapal");

#define TRAINER_COUNT_PAL_TAG       OBJ_EVENT_PAL_TAG_NPC_4 // Shares the same pal as the trainer it uses
#define TAG_TRAINER_COUNT_GFX 30050

static const struct SpritePalette sSpritePal_TrainerCountHUD =
{
    .data = sTrainerCountPal,
    .tag = TRAINER_COUNT_PAL_TAG,
};

static const struct CompressedSpriteSheet sSpriteSheet_TrainerCountHUD = 
{
    .data = sTrainerCountGfx,
    .size = 32*32*1/2,
    .tag = TAG_TRAINER_COUNT_GFX,
};

static const union AnimCmd sSpriteAnim_TrainerCountHUD0[] =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_TrainerCountHUD[] =
{
    sSpriteAnim_TrainerCountHUD0,
};

static const struct OamData sOamData_TrainerCountHUD =
{
    .size = SPRITE_SIZE(32x32),
    .shape = SPRITE_SHAPE(32x32),
    .priority = 0,
};

static const struct SpriteTemplate sSpriteTemplate_TrainerCountHUD =
{
    .tileTag = TAG_TRAINER_COUNT_GFX,
    .paletteTag = TRAINER_COUNT_PAL_TAG,
    .oam = &sOamData_TrainerCountHUD,
    .anims = sSpriteAnimTable_TrainerCountHUD,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

void CreateOverworldHUD(void)
{
    if(FuncIsActiveTask(Task_DelayPrintOverworldHUD))
        return;
    u16 remainingTrainers = ReturnTrainersRemaining();
    if ((remainingTrainers == 0) || (VarGet(VAR_PIT_FLOOR) == 0) || ((VarGet(VAR_PIT_FLOOR) % BOSS_FLOOR_RATE) == 0) || ((VarGet(VAR_PIT_FLOOR) % (gSaveBlock2Ptr->modeHealFloors10 ? 10 : 5)) == 0))
        return;
    CreateTask(Task_DelayPrintOverworldHUD, 15);
}

static void Task_DelayPrintOverworldHUD(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        LoadCompressedSpriteSheet(&sSpriteSheet_TrainerCountHUD);
        LoadSpritePalette(&sSpritePal_TrainerCountHUD);
        gOWHUDSprite = SPRITE_NONE;
        gOWHUDSprite = CreateSprite(&sSpriteTemplate_TrainerCountHUD, 224, 16, 0);
        gSprites[gOWHUDSprite].invisible = FALSE;

        PrintWarpPriceOnTrainerCount(gOWHUDSprite, 0, gSprites[gOWHUDSprite].oam.tileNum + 6);

        if (GetFlashLevel() > 0)
        {
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
            SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
            gOWHUDSpriteMask = SPRITE_NONE;
            gOWHUDSpriteMask = CreateSprite(&sSpriteTemplate_TrainerCountHUD, 224, 16, 0);
            gSprites[gOWHUDSpriteMask].invisible = FALSE;
            gSprites[gOWHUDSpriteMask].oam.objMode = ST_OAM_OBJ_WINDOW;
        }
        DestroyTask(taskId);
    }
}
static const struct WindowTemplate sTrainerCountWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 2,
    .height = 2,
    .paletteNum = 0,
    .baseBlock = 1 + 120
};

static u8 *AddTextPrinterAndCreateWindowOnTrainerCount(const u8 *str, u32 x, u32 y, u32 bgColor, u32 *windowId)
{
    u16 winId;
    u8 color[3];
    struct WindowTemplate winTemplate = sTrainerCountWindowTemplate;

    winId = AddWindow(&winTemplate);
    FillWindowPixelBuffer(winId, PIXEL_FILL(bgColor));

    color[0] = bgColor;
    color[1] = 14;
    color[2] = 15;

    AddTextPrinterParameterized4(winId, FONT_SMALL_NARROW, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);

    *windowId = winId;
    return (u8 *)(GetWindowAttribute(winId, WINDOW_TILE_DATA));
}

static void WarpPriceTextIntoTrainerCountObject(void *dest, u8 *windowTileData, u32 windowWidth)
{
    CpuCopy32(windowTileData, dest, windowWidth * TILE_SIZE_4BPP);
    CpuCopy32(windowTileData + (2 * TILE_SIZE_4BPP), dest + (4 * TILE_SIZE_4BPP), windowWidth * TILE_SIZE_4BPP);
}

static const u8 sText_TrainerCountPrefix[]         = _("x{STR_VAR_3}");
static void PrintWarpPriceOnTrainerCount(u32 spriteId, u32 bgColor, u32 startTile) // 0xbc0 for one part of the TrainerCount
{
    u8 *windowTileData;
    u32 windowId;

    void *objVram = (void *)(OBJ_VRAM0);
    ConvertIntToDecimalStringN(gStringVar3, ReturnTrainersRemaining(), STR_CONV_MODE_LEFT_ALIGN, 1);
    StringExpandPlaceholders(gStringVar4, sText_TrainerCountPrefix);

    windowTileData = AddTextPrinterAndCreateWindowOnTrainerCount(gStringVar4, 2, 0, bgColor, &windowId);
    WarpPriceTextIntoTrainerCountObject(objVram + (startTile * TILE_SIZE_4BPP), windowTileData, 2);
    RemoveWindow(windowId);
}
