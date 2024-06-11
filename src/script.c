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

void StartTimer1Script()
{
    StartTimer1();
}

struct RandomTrainerNPC 
{
    u16 gfxid;
    u16 objectflag;
    u16 trainerflag;
};

static const struct RandomTrainerNPC RandomNPCTrainers[] = 
{
    [0] = {VAR_OBJ_GFX_ID_0, FLAG_TRAINER_0, TRAINER_RANDOM_BATTLE_0},
    [1] = {VAR_OBJ_GFX_ID_1, FLAG_TRAINER_1, TRAINER_RANDOM_BATTLE_1},
    [2] = {VAR_OBJ_GFX_ID_2, FLAG_TRAINER_2, TRAINER_RANDOM_BATTLE_2},
    [3] = {VAR_OBJ_GFX_ID_3, FLAG_TRAINER_3, TRAINER_RANDOM_BATTLE_3},
};

static const struct RandomTrainerNPC RandomNPCTrainers_Doubles[] = 
{
    [0] = {VAR_OBJ_GFX_ID_0, FLAG_TRAINER_4, TRAINER_RANDOM_BATTLE_4},
    [1] = {VAR_OBJ_GFX_ID_1, FLAG_TRAINER_5, TRAINER_RANDOM_BATTLE_5},
    [2] = {VAR_OBJ_GFX_ID_2, FLAG_TRAINER_6, TRAINER_RANDOM_BATTLE_6},
    [3] = {VAR_OBJ_GFX_ID_3, FLAG_TRAINER_7, TRAINER_RANDOM_BATTLE_7},
};

u16 ReturnLastSpokenVarObjGfxId()
{   
    if(FlagGet(FLAG_DOUBLES_MODE))
        return VarGet(RandomNPCTrainers_Doubles[gSpecialVar_LastTalked - 15].gfxid);
    else
        return VarGet(RandomNPCTrainers[gSpecialVar_LastTalked - 1].gfxid);
}

u16 ReturnNumberOfTrainersForFloor()
{

    FlagSet(FLAG_MOVER_OBJECT);

    if(VarGet(VAR_PIT_FLOOR) == 100)
    {
        FlagClear(FLAG_END_GAME_ARCHIE);
        //FlagClear(FLAG_END_GAME_STATUE);
    }
    else
    {
        FlagSet(FLAG_END_GAME_ARCHIE);
        FlagSet(FLAG_END_GAME_STATUE);
    }
        

    if((VarGet(VAR_PIT_FLOOR) % 5) == 0) // Heal Floor
    {
        FlagClear(FLAG_HEAL_NPC);
        FlagClear(FLAG_SHOP_NPC);

        if(FlagGet(FLAG_RANDOM_MODE))
        {
            if((VarGet(VAR_PIT_FLOOR) % 20) == 0) // Move Relearner/Tutor Floor
            {
                FlagClear(FLAG_MOVE_RELEARNER);
            }
        }
        else
        {
            if(((VarGet(VAR_PIT_FLOOR) % 10) == 0) && !((VarGet(VAR_PIT_FLOOR) % 25) == 0)) // Move Relearner/Tutor Floor
            {
                FlagClear(FLAG_MOVE_RELEARNER);
            }
        }
        
        if((VarGet(VAR_PIT_FLOOR) % 25) == 0) // New Mon Floor
        {
            FlagClear(FLAG_GIVE_POKEMON);
            FlagSet(FLAG_MOVE_RELEARNER);
        }
        return 0;
    }

    FlagSet(FLAG_HEAL_NPC);
    FlagSet(FLAG_SHOP_NPC);
    FlagSet(FLAG_MOVE_RELEARNER);
    FlagSet(FLAG_MOVER_OBJECT);
    FlagSet(FLAG_GIVE_POKEMON);

    if((VarGet(VAR_PIT_FLOOR) > 25) && ((VarGet(VAR_PIT_FLOOR) < 95) || (VarGet(VAR_PIT_FLOOR) > 101)))
    {
        if(!(Random() % 20))
        {
            FlagClear(FLAG_MOVER_OBJECT);
            return 0;
        }
    }

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
        if(randomValue < 55)
            return 1;
        if(randomValue < 85)
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

void RemovePartyPokemon()
{
    ZeroMonData(&gPlayerParty[VarGet(VAR_RESULT)]);
    CompactPartySlots();
    CalculatePlayerPartyCount();
}

void SetRandomTrainers()
{
    u16 iterator = 0;
    u16 trainerCount = ReturnNumberOfTrainersForFloor();
    u16 trainers[4] = {0, 0, 0, 0};

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
            ClearTrainerFlag(RandomNPCTrainers_Doubles[newTrainer].trainerflag); 
            FlagClear(RandomNPCTrainers_Doubles[newTrainer].objectflag); 
        }
        else
        {
            VarSet(RandomNPCTrainers[newTrainer].gfxid, (Random() % 53) + 5);
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

void CheckFloorCleared()
{
    u16 iterator = 0;
    u16 trainerDefeated = 0;
    for (iterator = 0; iterator < 4; iterator++)
    {
        if(FlagGet(FLAG_DOUBLES_MODE))
            trainerDefeated = (u8) FlagGet(TRAINER_FLAGS_START + RandomNPCTrainers_Doubles[iterator].trainerflag) + trainerDefeated;
        else
            trainerDefeated = (u8) FlagGet(TRAINER_FLAGS_START + RandomNPCTrainers[iterator].trainerflag) + trainerDefeated;
    }
    if (trainerDefeated == 4)
        FlagSet(FLAG_FLOOR_CLEARED);
    return;
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
    switch(gSaveBlock2Ptr->modeAutosave)
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

void SetPlayerAvatar(void)
{
    switch(VarGet(VAR_RESULT))
    {
        case 0:
            gSaveBlock2Ptr->playerGender = MALE;
            gSaveBlock2Ptr->playerGfxType = 0;
            break;
        case 1:
            gSaveBlock2Ptr->playerGender = FEMALE;
            gSaveBlock2Ptr->playerGfxType = 0;
            break;
        case 2:
            gSaveBlock2Ptr->playerGender = MALE;
            gSaveBlock2Ptr->playerGfxType = 1;
            break;
        case 3:
            gSaveBlock2Ptr->playerGender = FEMALE;
            gSaveBlock2Ptr->playerGfxType = 1;
            break;
        case 4:
            gSaveBlock2Ptr->playerGender = MALE;
            gSaveBlock2Ptr->playerGfxType = 2;
            break;
        case 5:
            gSaveBlock2Ptr->playerGender = FEMALE;
            gSaveBlock2Ptr->playerGfxType = 2;
            break;
        case 6:
            gSaveBlock2Ptr->playerGender = MALE;
            gSaveBlock2Ptr->playerGfxType = 3;
            break;
        case 7:
            gSaveBlock2Ptr->playerGender = FEMALE;
            gSaveBlock2Ptr->playerGfxType = 3;
            break;
        case 8:
            gSaveBlock2Ptr->playerGender = MALE;
            gSaveBlock2Ptr->playerGfxType = 4;
            break;
        case 9:
            gSaveBlock2Ptr->playerGender = FEMALE;
            gSaveBlock2Ptr->playerGfxType = 4;
            break;
        case 10:
            gSaveBlock2Ptr->playerGender = MALE;
            gSaveBlock2Ptr->playerGfxType = 5;
            break;
        case 11:
            gSaveBlock2Ptr->playerGender = FEMALE;
            gSaveBlock2Ptr->playerGfxType = 5;
            break;
    }
}