#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_transition.h"
#include "main.h"
#include "task.h"
#include "pokemon_3.h"
#include "safari_zone.h"
#include "script.h"
#include "game_stat.h"
#include "event_data.h"
#include "species.h"
#include "songs.h"
#include "metatile_behavior.h"
#include "map_constants.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "trainer_classes.h"
#include "trainer_ids.h"

extern bool8 InBattlePyramid(void);
extern bool8 InBattlePike(void);
extern bool32 FieldPoisonEffectIsRunning(void);
extern void overworld_free_bg_tilemaps(void);
extern void prev_quest_postbuffer_cursor_backup_reset(void);
extern void ResetPoisonStepCounter(void);
extern void sub_81BE72C(void);
extern void FreezeMapObjects(void);
extern void sub_808BCF4(void);
extern void sub_80EECC8(void);
extern void c2_exit_to_overworld_1_continue_scripts_restart_music(void);
extern void c2_exit_to_overworld_2_switch(void);
extern void CB2_WhiteOut(void);
extern void sub_80AF6F0(void);
extern u8 GetSav1Weather(void);
extern u8 Overworld_GetFlashLevel(void);

extern u32 gBattleTypeFlags;
extern u8 gBattleOutcome;
extern void (*gFieldCallback)(void);
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;

// this file's functions
void DoBattlePikeWildBattle(void);
void DoSafariBattle(void);
void DoStandardWildBattle(void);
void CB2_EndWildBattle(void);
void CB2_EndScriptedWildBattle(void);
u8 GetWildBattleTransition(void);
u8 GetTrainerBattleTransition(void);
u8 sub_80B100C(u8 arg0);
void sub_80B1218(void);
void sub_80B1234(void);
bool32 IsPlayerDefeated(u8 battleOutcome);

// const rom data

// The first transition is used if the enemy pokemon are lower level than our pokemon.
// Otherwise, the second transition is used.
static const u8 sBattleTransitionTable_Wild[][2] =
{
    {B_TRANSITION_SLICE,               B_TRANSITION_WHITEFADE},     // Normal
    {B_TRANSITION_CLOCKWISE_BLACKFADE, B_TRANSITION_GRID_SQUARES},  // Cave
    {B_TRANSITION_BLUR,                B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_WAVE,                B_TRANSITION_RIPPLE},        // Water
};

static const u8 sBattleTransitionTable_Trainer[][2] =
{
    {B_TRANSITION_POKEBALLS_TRAIL, B_TRANSITION_SHARDS},        // Normal
    {B_TRANSITION_SHUFFLE,         B_TRANSITION_BIG_POKEBALL},  // Cave
    {B_TRANSITION_BLUR,            B_TRANSITION_GRID_SQUARES},  // Cave with flash used
    {B_TRANSITION_SWIRL,           B_TRANSITION_RIPPLE},        // Water
};

#define tState data[0]
#define tTransition data[1]

void Task_BattleStart(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!FieldPoisonEffectIsRunning()) // is poison not active?
        {
            BattleTransition_StartOnField(tTransition);
            sub_81BE72C();
            tState++; // go to case 1.
        }
        break;
    case 1:
        if (IsBattleTransitionDone() == TRUE)
        {
            overworld_free_bg_tilemaps();
            SetMainCallback2(CB2_InitBattle);
            prev_quest_postbuffer_cursor_backup_reset();
            ResetPoisonStepCounter();
            DestroyTask(taskId);
        }
        break;
    }
}

void CreateBattleStartTask(u8 transition, u16 song)
{
    u8 taskId = CreateTask(Task_BattleStart, 1);

    gTasks[taskId].tTransition = transition;
    PlayMapChosenOrBattleBGM(song);
}

#undef tState
#undef tTransition

void BattleSetup_StartWildBattle(void)
{
    if (GetSafariZoneFlag())
        DoSafariBattle();
    else
        DoStandardWildBattle();
}

void BattleSetup_StartBattlePikeWildBattle(void)
{
    DoBattlePikeWildBattle();
}

void DoStandardWildBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = 0;
    if (InBattlePyramid())
    {
        VarSet(VAR_0x400E, 0);
        gBattleTypeFlags |= BATTLE_TYPE_PYRAMID;
    }
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void BattleSetup_StartRoamerBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_ROAMER;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void DoSafariBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndSafariBattle;
    gBattleTypeFlags = BATTLE_TYPE_SAFARI;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
}

void DoBattlePikeWildBattle(void)
{
    ScriptContext2_Enable();
    FreezeMapObjects();
    sub_808BCF4();
    gMain.savedCallback = CB2_EndWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_PIKE;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void DoTrainerBattle(void)
{
    CreateBattleStartTask(GetTrainerBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
    sub_80B1234();
}

void sub_80B0828(void)
{
    if (InBattlePyramid())
        CreateBattleStartTask(sub_80B100C(10), 0);
    else
        CreateBattleStartTask(sub_80B100C(11), 0);

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_TRAINER_BATTLES);
    sub_80B1234();
}

// Initiates battle where Wally catches Ralts
void StartWallyTutorialBattle(void)
{
    CreateMaleMon(&gEnemyParty[0], SPECIES_RALTS, 5);
    ScriptContext2_Enable();
    gMain.savedCallback = c2_exit_to_overworld_1_continue_scripts_restart_music;
    gBattleTypeFlags = BATTLE_TYPE_WALLY_TUTORIAL;
    CreateBattleStartTask(B_TRANSITION_SLICE, 0);
}

void BattleSetup_StartScriptedWildBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = 0;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void BattleSetup_StartLatiBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;
    CreateBattleStartTask(GetWildBattleTransition(), 0);
    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void BattleSetup_StartLegendaryBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY;

    switch (GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL))
    {
    default:
    case SPECIES_GROUDON:
        gBattleTypeFlags |= BATTLE_TYPE_GROUDON;
        CreateBattleStartTask(B_TRANSITION_GROUDON, BGM_BATTLE34);
        break;
    case SPECIES_KYOGRE:
        gBattleTypeFlags |= BATTLE_TYPE_KYORGE;
        CreateBattleStartTask(B_TRANSITION_KYORGE, BGM_BATTLE34);
        break;
    case SPECIES_RAYQUAZA:
        gBattleTypeFlags |= BATTLE_TYPE_RAYQUAZA;
        CreateBattleStartTask(B_TRANSITION_RAYQUAZA, BGM_BATTLE_LEGENDARY);
        break;
    case SPECIES_DEOXYS:
        CreateBattleStartTask(B_TRANSITION_BLUR, BGM_FRLG_BATTLE_DEOXYS);
        break;
    case SPECIES_LUGIA:
    case SPECIES_HO_OH:
        CreateBattleStartTask(B_TRANSITION_BLUR, BGM_FRLG_BATTLE_LEGENDARY);
        break;
    case SPECIES_MEW:
        CreateBattleStartTask(B_TRANSITION_GRID_SQUARES, BGM_BATTLE_MEW);
        break;
    }

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void StartGroudonKyogreBattle(void)
{
    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_KYOGRE_GROUDON;

    if (gGameVersion == VERSION_RUBY)
        CreateBattleStartTask(B_TRANSITION_SHARDS, BGM_BATTLE34); // GROUDON
    else
        CreateBattleStartTask(B_TRANSITION_RIPPLE, BGM_BATTLE34); // KYOGRE

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void StartRegiBattle(void)
{
    u8 transitionId;
    u16 species;

    ScriptContext2_Enable();
    gMain.savedCallback = CB2_EndScriptedWildBattle;
    gBattleTypeFlags = BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_REGI;

    species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    switch (species)
    {
    case SPECIES_REGIROCK:
        transitionId = B_TRANSITION_REGIROCK;
        break;
    case SPECIES_REGICE:
        transitionId = B_TRANSITION_REGICE;
        break;
    case SPECIES_REGISTEEL:
        transitionId = B_TRANSITION_REGISTEEL;
        break;
    default:
        transitionId = B_TRANSITION_GRID_SQUARES;
        break;
    }
    CreateBattleStartTask(transitionId, BGM_BATTLE36);

    IncrementGameStat(GAME_STAT_TOTAL_BATTLES);
    IncrementGameStat(GAME_STAT_WILD_BATTLES);
    sub_80EECC8();
    sub_80B1218();
}

void CB2_EndWildBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE && !InBattlePyramid() && !InBattlePike())
    {
        SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_2_switch);
        gFieldCallback = sub_80AF6F0;
    }
}

void CB2_EndScriptedWildBattle(void)
{
    CpuFill16(0, (void*)(BG_PLTT), BG_PLTT_SIZE);
    ResetOamRange(0, 128);

    if (IsPlayerDefeated(gBattleOutcome) == TRUE)
    {
        if (InBattlePyramid())
            SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
        else
            SetMainCallback2(CB2_WhiteOut);
    }
    else
    {
        SetMainCallback2(c2_exit_to_overworld_1_continue_scripts_restart_music);
    }
}

u8 BattleSetup_GetTerrainId(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsTallGrass(tileBehavior))
        return BATTLE_TERRAIN_GRASS;
    if (MetatileBehavior_IsLongGrass(tileBehavior))
        return BATTLE_TERRAIN_LONG_GRASS;
    if (MetatileBehavior_IsSandOrDeepSand(tileBehavior))
        return BATTLE_TERRAIN_SAND;

    switch (gMapHeader.mapType)
    {
    case MAP_TYPE_TOWN:
    case MAP_TYPE_CITY:
    case MAP_TYPE_ROUTE:
        break;
    case MAP_TYPE_UNDERGROUND:
        if (MetatileBehavior_IsMB_0B(tileBehavior))
            return BATTLE_TERRAIN_BUILDING;
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_POND;
        return BATTLE_TERRAIN_CAVE;
    case MAP_TYPE_INDOOR:
    case MAP_TYPE_SECRET_BASE:
        return BATTLE_TERRAIN_BUILDING;
    case MAP_TYPE_UNDERWATER:
        return BATTLE_TERRAIN_UNDERWATER;
    case MAP_TYPE_6:
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
            return BATTLE_TERRAIN_WATER;
        return BATTLE_TERRAIN_PLAIN;
    }
    if (MetatileBehavior_IsDeepOrOceanWater(tileBehavior))
        return BATTLE_TERRAIN_WATER;
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
        return BATTLE_TERRAIN_POND;
    if (MetatileBehavior_IsMountain(tileBehavior))
        return BATTLE_TERRAIN_MOUNTAIN;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        if (MetatileBehavior_GetBridgeSth(tileBehavior))
            return BATTLE_TERRAIN_POND;
        if (MetatileBehavior_IsBridge(tileBehavior) == TRUE)
            return BATTLE_TERRAIN_WATER;
    }
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP_ROUTE113 && gSaveBlock1Ptr->location.mapNum == MAP_ID_ROUTE113)
        return BATTLE_TERRAIN_SAND;
    if (GetSav1Weather() == 8)
        return BATTLE_TERRAIN_SAND;

    return BATTLE_TERRAIN_PLAIN;
}

u8 GetBattleTransitionTypeByMap(void)
{
    u16 tileBehavior;
    s16 x, y;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (Overworld_GetFlashLevel())
        return B_TRANSITION_SHUFFLE;
    if (!MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_UNDERGROUND:
            return B_TRANSITION_SWIRL;
        case MAP_TYPE_UNDERWATER:
            return B_TRANSITION_BIG_POKEBALL;
        default:
            return B_TRANSITION_BLUR;
        }
    }
    return B_TRANSITION_BIG_POKEBALL;
}

u16 GetSumOfPlayerPartyLevel(u8 numMons)
{
    u8 sum = 0;
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);

        if (species != SPECIES_EGG && species != SPECIES_NONE && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            sum += GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            if (--numMons == 0)
                break;
        }
    }
    return sum;
}

u8 GetSumOfEnemyPartyLevel(u16 opponentId, u8 numMons)
{
    u8 i;
    u8 sum;
    u32 count = numMons;

    if (gTrainers[opponentId].partySize < count)
        count = gTrainers[opponentId].partySize;

    sum = 0;

    switch (gTrainers[opponentId].partyFlags)
    {
    case 0:
        {
            const struct TrainerMonNoItemDefaultMoves *party;
            party = gTrainers[opponentId].party.NoItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case PARTY_FLAG_CUSTOM_MOVES:
        {
            const struct TrainerMonNoItemCustomMoves *party;
            party = gTrainers[opponentId].party.NoItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case PARTY_FLAG_HAS_ITEM:
        {
            const struct TrainerMonItemDefaultMoves *party;
            party = gTrainers[opponentId].party.ItemDefaultMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    case PARTY_FLAG_CUSTOM_MOVES | PARTY_FLAG_HAS_ITEM:
        {
            const struct TrainerMonItemCustomMoves *party;
            party = gTrainers[opponentId].party.ItemCustomMoves;
            for (i = 0; i < count; i++)
                sum += party[i].lvl;
        }
        break;
    }

    return sum;
}

u8 GetWildBattleTransition(void)
{
    u8 transitionType = GetBattleTransitionTypeByMap();
    u8 enemyLevel = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    u8 playerLevel = GetSumOfPlayerPartyLevel(1);

    if (enemyLevel < playerLevel)
    {
        if (InBattlePyramid())
            return B_TRANSITION_BLUR;
        else
            return sBattleTransitionTable_Wild[transitionType][0];
    }
    else
    {
        if (InBattlePyramid())
            return B_TRANSITION_GRID_SQUARES;
        else
            return sBattleTransitionTable_Wild[transitionType][1];
    }
}

u8 GetTrainerBattleTransition(void)
{
    u8 minPartyCount;
    u8 transitionType;
    u8 enemyLevel;
    u8 playerLevel;

    if (gTrainerBattleOpponent_A == SECRET_BASE_OPPONENT)
        return B_TRANSITION_STEVEN;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_ELITE_FOUR)
    {
        if (gTrainerBattleOpponent_A == TRAINER_ID_SIDNEY)
            return B_TRANSITION_SYDNEY;
        if (gTrainerBattleOpponent_A == TRAINER_ID_PHOEBE)
            return B_TRANSITION_PHOEBE;
        if (gTrainerBattleOpponent_A == TRAINER_ID_GLACIA)
            return B_TRANSITION_GLACIA;
        if (gTrainerBattleOpponent_A == TRAINER_ID_DRAKE)
            return B_TRANSITION_DRAKE;
        return B_TRANSITION_STEVEN;
    }

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_CHAMPION)
        return B_TRANSITION_STEVEN;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_TEAM_MAGMA
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_MAGMA_LEADER
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_MAGMA_ADMIN)
        return B_TRANSITION_MAGMA;

    if (gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_TEAM_AQUA
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_AQUA_LEADER
        || gTrainers[gTrainerBattleOpponent_A].trainerClass == CLASS_AQUA_ADMIN)
        return B_TRANSITION_AQUA;

    if (gTrainers[gTrainerBattleOpponent_A].doubleBattle == TRUE)
        minPartyCount = 2; // double battles always at least have 2 pokemon.
    else
        minPartyCount = 1;

    transitionType = GetBattleTransitionTypeByMap();
    enemyLevel = GetSumOfEnemyPartyLevel(gTrainerBattleOpponent_A, minPartyCount);
    playerLevel = GetSumOfPlayerPartyLevel(minPartyCount);
    if (enemyLevel < playerLevel) // is wild mon level than the player's mon level?
        return sBattleTransitionTable_Trainer[transitionType][0];
    else
        return sBattleTransitionTable_Trainer[transitionType][1];
}
