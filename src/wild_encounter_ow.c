#include "global.h"
#include "wild_encounter_ow.h"
#include "battle_setup.h"
#include "battle_main.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "follower_npc.h"
#include "mass_outbreak.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "random.h"
#include "roamer.h"
#include "script.h"
#include "script_movement.h"
#include "sprite.h"
#include "sound.h"
#include "task.h"
#include "trainer_hill.h"
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/layouts.h"
#include "constants/item.h"
#include "constants/map_types.h"
#include "constants/trainer_types.h"
#include "constants/songs.h"
#include "constants/vars.h"
#include "constants/wild_encounter.h"


#define sOverworldEncounterLevel        trainerRange_berryTreeId
#define sOverworldEncounterAge          playerCopyableMovement
#define sOverworldEncounterCategory     warpArrowSpriteId
#define OWE_MAX_ROAMERS                 UINT8_MAX - 3

#define OWE_FLAG_BIT                    (1 << 7)
#define OWE_SAVED_MOVEMENT_STATE_FLAG   OWE_FLAG_BIT
#define OWE_NO_DESPAWN_FLAG             OWE_FLAG_BIT

#define OWE_SPAWN_DISTANCE_LAND         1   // A spawn cannot happen within this many tiles of the player position.
#define OWE_SPAWN_DISTANCE_WATER        3   // A spawn cannot happen within this many tiles of the player position (while surfing).
#define OWE_SPAWN_WIDTH_TOTAL           15  // Width of the on-screen spawn area in tiles.
#define OWE_SPAWN_HEIGHT_TOTAL          9   // Height of the on-screen spawn area in tiles.
#define OWE_SPAWN_WIDTH_RADIUS          (OWE_SPAWN_WIDTH_TOTAL - 1) / 2     // Distance from center to left/right edge (not including center).
#define OWE_SPAWN_HEIGHT_RADIUS         (OWE_SPAWN_HEIGHT_TOTAL - 1) / 2    // Distance from center to top/bottom edge (not including center).

#define OWE_SPAWN_TIME_REPLACEMENT      240 // The number of frames before an existing spawn will be replaced with a new one (requires WE_OWE_SPAWN_REPLACEMENT).
#define OWE_SPAWN_TIME_LURE             0
#define OWE_SPAWN_TIME_MINIMUM          30  // The minimum value the spawn wait time can be reset to. Prevents spawn attempts every frame.
#define OWE_SPAWN_TIME_PER_ACTIVE       30  // The number of frames that will be added to the countdown per currently active spawn.

#define OWE_DEFAULT_CHASE_RANGE         5
#define OWE_RESTORED_MOVEMENT_FUNC_ID   10

#define OWE_NO_ENCOUNTER_SET            0xFF
#define OWE_INVALID_SPAWN_SLOT          0xFF

enum __attribute__((packed)) CategoryOWE
{
    // If Roamers are used, they will exist as values, implicitly, within this enum.
    OWE_CATEGORY_MASS_OUTBREAK = ROAMER_COUNT,
    OWE_CATEGORY_FEEBAS,
    OWE_CATEGORY_WILD,
    OWE_CATEGORY_UNDEFINED
};

struct InfoOWE
{
    enum Species speciesId;
    enum CategoryOWE category;
    u8 localId;
    u8 level;
    bool8 isShiny;
    bool8 isFemale;
    bool8 noDespawn;
};


#if WE_OW_ENCOUNTERS == TRUE && ROAMER_COUNT > OWE_MAX_ROAMERS
#error "ROAMER_COUNT needs to be less than OWE_MAX_ROAMERS due to it being stored in the u8 field warpArrowSpriteId"
#endif

#if OW_POKEMON_OBJECT_EVENTS == FALSE && WE_OW_ENCOUNTERS == TRUE
#error "OW_POKEMON_OBJECT_EVENTS needs to be TRUE in order for WE_OW_ENCOUNTERS to work."
#endif

#if OWE_SPAWN_DISTANCE_LAND >= OWE_SPAWN_WIDTH_RADIUS || OWE_SPAWN_DISTANCE_WATER >= OWE_SPAWN_WIDTH_RADIUS
#error "OWE_SPAWN_DISTANCE_LAND and OWE_SPAWN_DISTANCE_WATER must both be less than OWE_SPAWN_WIDTH_RADIUS."
#endif


static inline u32 GetLocalIdByOWESpawnSlot(u32 spawnSlot)
{
    return LOCALID_OW_ENCOUNTER_END - spawnSlot;
}

static inline u32 GetSpawnSlotByOWELocalId(u32 localId)
{
    return LOCALID_OW_ENCOUNTER_END - localId;
}

static inline u32 GetOWECategory(const struct ObjectEvent *owe)
{
    return owe->sOverworldEncounterCategory & ~OWE_SAVED_MOVEMENT_STATE_FLAG;
}

static inline bool32 HasSavedOWEMovementState(const struct ObjectEvent *owe)
{
    return owe->sOverworldEncounterCategory & OWE_SAVED_MOVEMENT_STATE_FLAG;
}

void SetSavedOWEMovementState(struct ObjectEvent *owe)
{
    owe->sOverworldEncounterCategory |= OWE_SAVED_MOVEMENT_STATE_FLAG;
}

void ClearSavedOWEMovementState(struct ObjectEvent *owe)
{
    owe->sOverworldEncounterCategory &= ~OWE_SAVED_MOVEMENT_STATE_FLAG;
}

static inline bool32 HasOWENoDespawnFlag(const struct ObjectEvent *owe)
{
    return owe->sOverworldEncounterLevel & OWE_NO_DESPAWN_FLAG;
}

static inline bool32 ShouldSpawnWaterOWE(void)
{
    return TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER);
}

// Helper function for IsOverworldWildEncounter and GetOverworldWildEncounterType
static inline bool32 IsObjectActiveOWE(struct ObjectEvent *owe)
{
    return (owe->active && owe->trainerType == TRAINER_TYPE_OW_WILD_ENCOUNTER);
}

static bool32 CreateEnemyPartyOWE(struct InfoOWE *info, s32 x, s32 y);
static bool32 OWE_DoesOWERoamerExist(void);
static bool32 StartWildBattleWithOWE_CheckRoamer(enum CategoryOWE category);
static bool32 StartWildBattleWithOWE_CheckBattleFrontier(u32 headerId);
static bool32 StartWildBattleWithOWE_CheckMassOutbreak(enum CategoryOWE category, enum Species speciesId, u32 level);
static bool32 StartWildBattleWithOWE_CheckDoubleBattle(struct ObjectEvent *owe, u32 headerId);
static bool32 CheckCurrentWildMonHeaderForOWE(bool32 shouldSpawnWaterMons);
static u32 GetOldestActiveOWESlot(bool32 forceRemove);
static u32 GetNextOWESpawnSlot(void);
static enum Species GetSpeciesByOWESpawnSlot(u32 spawnSlot);
static bool32 TrySelectTileForOWE(s32* outX, s32* outY);
static void SetSpeciesInfoForOWE(struct InfoOWE *info, u32 x, u32 y);
static u32 GetGraphicsIdForOWE(const struct InfoOWE *info);
static bool32 CheckCanLoadOWE(enum Species speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y);
static bool32 CheckCanLoadOWE_Palette(enum Species speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y);
static bool32 CheckCanLoadOWE_Tiles(enum Species speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y);
static void SortOWEAges(void);
static bool32 ShouldDespawnGeneratedForNewOWE(struct ObjectEvent *owe);
static void SetNewOWESpawnCountdown(void);
static void DoOWESpawnAnim(struct ObjectEvent *owe);
static void DoOWEDespawnAnim(struct ObjectEvent *owe);
static enum SpawnDespawnTypeOWE GetOWESpawnDespawnAnimType(u32 metatileBehavior);
static void PlayOWECry(struct ObjectEvent *owe);
static struct ObjectEvent *GetRandomOWEObjectEvent(void);
static bool32 OWE_ShouldPlayOWEFleeSound(struct ObjectEvent *owe);
static bool32 CheckRestrictedOWEMovementAtCoords(struct ObjectEvent *owe, s32 xNew, s32 yNew, enum Direction newDirection, enum Direction collisionDirection);
static bool32 CheckRestrictedOWEMovementMetatile(s32 xCurrent, s32 yCurrent, s32 xNew, s32 yNew);
static bool32 CheckRestrictedOWEMovementMap(struct ObjectEvent *owe, s32 xNew, s32 yNew);
static bool32 CanOWEReachPlayer(struct ObjectEvent *owe);
static bool32 IsOWENextToObject(struct ObjectEvent *owe, struct ObjectEvent *object);
static enum Direction CheckOWEPathToPlayerFromCollision(struct ObjectEvent *owe, enum Direction newDirection);
static void Task_OWEApproachForBattle(u8 taskId);
static bool32 CheckValidOWESpecies(enum Species speciesId);

static EWRAM_DATA u8 sOWESpawnCountdown = 0;

struct AgeSort
{
    u8 slot:4;
    u8 age:4;
};

const struct FieldEffectInfoOWE gOverworldWildEncounterFieldEffectInfo[] =
{
    [OWE_SPAWN_ANIM_GRASS] =
    {
        .xOffset = 0,
        .yOffset = 8,
        .visual = FLDEFFOBJ_JUMP_TALL_GRASS,
    },

    [OWE_SPAWN_ANIM_LONG_GRASS] =
    {
        .xOffset = 0,
        .yOffset = 0,
        .visual = FLDEFFOBJ_JUMP_LONG_GRASS,
    },

    [OWE_SPAWN_ANIM_WATER] =
    {
        .xOffset = 0,
        .yOffset = 8,
        .visual = FLDEFFOBJ_JUMP_BIG_SPLASH,
    },

    [OWE_SPAWN_ANIM_UNDERWATER] =
    {
        .xOffset = 0,
        .yOffset = 0,
        .visual = FLDEFFOBJ_BUBBLES,
    },

    [OWE_SPAWN_ANIM_CAVE] =
    {
        .xOffset = 0,
        .yOffset = 12,
        .visual = FLDEFFOBJ_GROUND_IMPACT_DUST,
    },

    [OWE_SPAWN_ANIM_SHINY] =
    {
        .xOffset = 0,
        .yOffset = 0,
        .visual = FLDEFFOBJ_SHINY_SPARKLE,
    },
};


void UpdateOverworldWildEncounter(void)
{
    //Check if possible to spawn.

    bool32 shouldSpawnWaterMons = ShouldSpawnWaterOWE();
    
    if (ArePlayerFieldControlsLocked() || FlagGet(DN_FLAG_SEARCHING) || !CheckCurrentWildMonHeaderForOWE(shouldSpawnWaterMons))
        return;

    if (!WE_OW_ENCOUNTERS
     || FlagGet(WE_OWE_FLAG_DISABLED)
     || FlagGet(WE_FLAG_NO_ENCOUNTER)
     || FlagGet(DN_FLAG_SEARCHING)
     || (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && !WE_OWE_BATTLE_PIKE)
     || (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR && !WE_OWE_BATTLE_PYRAMID)
     || InTrainerHillChallenge())
    {
        if (sOWESpawnCountdown != OWE_NO_ENCOUNTER_SET)
        {
            DespawnAllOverworldWildEncounters(OWE_GENERATED, 0);
            sOWESpawnCountdown = OWE_NO_ENCOUNTER_SET;
        }
        return;
    }
    else if (sOWESpawnCountdown == OWE_NO_ENCOUNTER_SET)
    {
        SetMinimumOWESpawnTimer();
    }

    if (sOWESpawnCountdown)
    {
        sOWESpawnCountdown--;
        return;
    }
    
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];
    // Don't spawn if player is mid step.
    if (player->currentCoords.x != player->previousCoords.x || player->currentCoords.y != player->previousCoords.y)
        return;

    // Check for a valid tile.

    u32 spawnSlot = GetNextOWESpawnSlot();
    s32 x, y;
    if (spawnSlot == OWE_INVALID_SPAWN_SLOT
     || (shouldSpawnWaterMons && AreLegendariesInSootopolisPreventingEncounters())
     || !TrySelectTileForOWE(&x, &y))
    {
        SetMinimumOWESpawnTimer();
        return;
    }

    // Check for a valid Pokemon.

    struct InfoOWE infoOWE = {0};

    infoOWE.localId = GetLocalIdByOWESpawnSlot(spawnSlot);
    infoOWE.category = OWE_CATEGORY_UNDEFINED;
    SetSpeciesInfoForOWE(&infoOWE, x, y);

    if (infoOWE.speciesId == SPECIES_NONE
     || (WE_OWE_SPECIAL_ONLY && infoOWE.category >= OWE_CATEGORY_WILD)
     || !IsWildLevelAllowedByRepel(infoOWE.level)
     || !IsAbilityAllowingEncounter(infoOWE.level)
     || !CheckCanLoadOWE(infoOWE.speciesId, infoOWE.isFemale, infoOWE.isShiny, x, y))
    {
        SetMinimumOWESpawnTimer();
        return;
    }

    // Spawn the Pokemon.
    
    struct ObjectEventTemplate objectEventTemplate = {
        .localId = infoOWE.localId,
        .graphicsId = GetGraphicsIdForOWE(&infoOWE),
        .x = x - MAP_OFFSET,
        .y = y - MAP_OFFSET,
        .elevation = MapGridGetElevationAt(x, y),
        .movementType = OWE_GetMovementTypeFromSpecies(infoOWE.speciesId),
        .trainerType = TRAINER_TYPE_OW_WILD_ENCOUNTER,
    };
    u32 objectEventId = GetObjectEventIdByLocalId(infoOWE.localId);
    struct ObjectEvent *owe = &gObjectEvents[objectEventId];
    if (ShouldDespawnGeneratedForNewOWE(owe))
        RemoveObjectEvent(owe);
    objectEventId = SpawnSpecialObjectEvent(&objectEventTemplate);

    assertf(objectEventId < OBJECT_EVENTS_COUNT, "could not spawn generated overworld encounter. too many object events exist")
    {
        SetMinimumOWESpawnTimer();
        return;
    }

    owe = &gObjectEvents[objectEventId];
    owe->disableCoveringGroundEffects = TRUE;
    owe->sOverworldEncounterLevel = infoOWE.noDespawn ? (infoOWE.level | OWE_NO_DESPAWN_FLAG) : infoOWE.level;
    owe->sOverworldEncounterCategory = infoOWE.category;

    ObjectEventTurn(owe, gStandardDirections[Random() & 3]);
    SetNewOWESpawnCountdown();
}

bool32 IsOverworldWildEncounter(struct ObjectEvent *owe, enum TypeOWE oweType)
{
    if (!IsObjectActiveOWE(owe))
        return FALSE;

    switch (oweType)
    {
    default:
    case OWE_ANY:
        return TRUE;
    
    case OWE_GENERATED:
        return IS_LOCALID_GENERATED_OWE(owe->localId);

    case OWE_MANUAL:
        return !IS_LOCALID_GENERATED_OWE(owe->localId);
    }
}

static enum TypeOWE GetOverworldWildEncounterType(struct ObjectEvent *owe)
{
    if (!IsObjectActiveOWE(owe))
        return OWE_NONE;

    if (IS_LOCALID_GENERATED_OWE(owe->localId))
        return OWE_GENERATED;

    return OWE_MANUAL;
}

void StartWildBattleWithOWE(struct ScriptContext *ctx)
{
    u32 localId = VarGet(ScriptReadHalfword(ctx));
    u32 objEventId = GetObjectEventIdByLocalId(localId);
    u32 headerId = GetCurrentMapWildMonHeaderId();
    struct ObjectEvent *owe = &gObjectEvents[objEventId];
    enum CategoryOWE category = GetOWECategory(owe);

    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);

    assertf(objEventId < OBJECT_EVENTS_COUNT && IsOverworldWildEncounter(owe, OWE_ANY), "cannot start overworld wild enocunter as the selected object is invalid.\nlocalId: %d", localId)
    {
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        return;
    }

    if (category < ROAMER_COUNT && StartWildBattleWithOWE_CheckRoamer(category))
        return;

    enum Species speciesId = OW_SPECIES(owe);
    bool32 shiny = OW_SHINY(owe) ? TRUE : FALSE;
    u32 gender = OW_FEMALE(owe) ? MON_FEMALE : MON_MALE;
    u32 level = owe->sOverworldEncounterLevel & ~OWE_NO_DESPAWN_FLAG;
    u32 personality;

    assertf(level >= MIN_LEVEL && level <= MAX_LEVEL, "overworld wild encounter does not have valid level.\nlocalId: %d", localId)
    {
        level = MIN_LEVEL;
    }

    ZeroEnemyPartyMons();
    personality = GetMonPersonality(speciesId, gender, NATURE_RANDOM, RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gParties[B_TRAINER_OPPONENT_A][0], speciesId, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gParties[B_TRAINER_OPPONENT_A][0]);
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_IS_SHINY, &shiny);
    
    if (StartWildBattleWithOWE_CheckBattleFrontier(headerId))
        return;
    
    if (StartWildBattleWithOWE_CheckMassOutbreak(category, speciesId, level))
        return;

    if (StartWildBattleWithOWE_CheckDoubleBattle(owe, headerId))
        return;

    BattleSetup_StartWildBattle();
}

void SetOverworldObjectSpecies(struct ScriptContext *ctx)
{
    u32 varId = ScriptReadHalfword(ctx);
    u32 localId = VarGet(ScriptReadHalfword(ctx));
    struct ObjectEvent *object = &gObjectEvents[GetObjectEventIdByLocalId(localId)];
    enum Species speciesId = SPECIES_NONE;

    Script_RequestEffects(SCREFF_V1);
    Script_RequestWriteVar(varId);

    if (IS_OW_MON_OBJ(object))
        speciesId = OW_SPECIES(object);

    assertf(speciesId != SPECIES_NONE, "species was not found for specified object. localid: %d", localId);
    VarSet(varId, speciesId);
}

static bool32 CreateEnemyPartyOWE(struct InfoOWE *info, s32 x, s32 y)
{
    const struct WildPokemonInfo *wildMonInfo;
    enum WildPokemonArea wildArea;
    enum TimeOfDay timeOfDay;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;
            else if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;
            
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            enum Species id = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES);
            GenerateBattlePyramidWildMon(SPECIES_NONE);
            SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_LEVEL, &id);
            return TRUE;
        }

        return FALSE;
    }

    if (MetatileBehavior_IsWaterWildEncounter(metatileBehavior))
    {
        wildArea = WILD_AREA_WATER;
        timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
    }
    else
    {
        wildArea = WILD_AREA_LAND;
        timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
    }

    if (wildMonInfo == NULL)
        return FALSE;

    /*
    These functions perform checks of various encounter types in the following order:
        1. Attempt to generate a Roamer Encounter
        2. Attempt to generate a Feebas Encounter
        3. Attempt to generate a Mass Outbreak Encounter
        4. Attempt to generate a Standard Wild Encounter
    
    The structure of this statement ensures that only one of these encounter types can succeed per call,
    with the resultant wild mon being created in gParties[B_TRAINER_OPPONENT_A][0].
    If none of these checks succeed, speciesId is set to SPECIES_NONE and FALSE is returned.
    */

    if (info->category == OWE_CATEGORY_UNDEFINED)
    {
        if (TryStartRoamerEncounter() && !OWE_DoesOWERoamerExist())
        {
            info->category = gEncounteredRoamerIndex;
            return TRUE;
        }
        else if (WE_OWE_FEEBAS_SPOTS && MetatileBehavior_IsWaterWildEncounter(metatileBehavior) && CheckFeebasAtCoords(x, y))
        {
            CreateWildMon(gWildFeebas.species, ChooseWildMonLevel(&gWildFeebas, 0, WILD_AREA_FISHING));
            info->category = OWE_CATEGORY_FEEBAS;
            if (WE_OWE_PREVENT_FEEBAS_DESPAWN)
                info->noDespawn = TRUE;

            return TRUE;
        }
        else if (DoMassOutbreakEncounterTest() && MetatileBehavior_IsLandWildEncounter(metatileBehavior))
        {
            SetUpMassOutbreakEncounter(0);
            info->category = OWE_CATEGORY_MASS_OUTBREAK;
            return TRUE;
        }
        else
        {
            return TryGenerateWildMon(wildMonInfo, wildArea, 0);
        }
    }

    return TryGenerateWildMon(wildMonInfo, wildArea, 0);
}

static bool32 OWE_DoesOWERoamerExist(void)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        struct ObjectEvent *owe = &gObjectEvents[i];
        if (IsOverworldWildEncounter(owe, OWE_ANY) && GetOWECategory(owe) == gEncounteredRoamerIndex)
            return TRUE;
    }

    return FALSE;
}

static bool32 StartWildBattleWithOWE_CheckRoamer(enum CategoryOWE category)
{
    if (category < ROAMER_COUNT
     && IsRoamerAt(category, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
        CreateRoamerMonInstance(category);
        gEncounteredRoamerIndex = category;
        BattleSetup_StartRoamerBattle();
        return TRUE;
    }

    return FALSE;
}

static bool32 StartWildBattleWithOWE_CheckBattleFrontier(u32 headerId)
{
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            u32 id = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_LEVEL);
            enum Species species = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES);
            SetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES, &id);
            if (!BATTLE_PYRAMID_RANDOM_ENCOUNTERS)
                species = SPECIES_NONE;
            GenerateBattlePyramidWildMon(species);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

static bool32 StartWildBattleWithOWE_CheckMassOutbreak(enum CategoryOWE category, enum Species speciesId, u32 level)
{
    if (category != OWE_CATEGORY_MASS_OUTBREAK)
        return FALSE;

    assertf(gSaveBlock1Ptr->outbreakPokemonSpecies == speciesId && gSaveBlock1Ptr->outbreakPokemonLevel == level, "Outbreak OW encounter is not matching last active outbreak")
    {
        return FALSE;
    }
    ZeroEnemyPartyMons();
    SetUpMassOutbreakEncounter(0);
    BattleSetup_StartWildBattle();
    return TRUE;
}

static bool32 StartWildBattleWithOWE_CheckDoubleBattle(struct ObjectEvent *owe, u32 headerId)
{
    enum WildPokemonArea wildArea;
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *wildMonInfo;
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(owe->currentCoords.x, owe->currentCoords.y);

    if (TryDoDoubleWildBattle())
    {
        struct Pokemon mon1 = gParties[B_TRAINER_OPPONENT_A][0];

        if (MetatileBehavior_IsWaterWildEncounter(metatileBehavior))
        {
            wildArea = WILD_AREA_WATER;
            timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
            wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
        }
        else
        {
            wildArea = WILD_AREA_LAND;
            timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
            wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
        }

        if (TryGenerateWildMon(wildMonInfo, wildArea, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE))
        {
            gParties[B_TRAINER_OPPONENT_A][1] = mon1;
            BattleSetup_StartDoubleWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

void SetMinimumOWESpawnTimer(void)
{
    if (!WE_OW_ENCOUNTERS)
        return;

    sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
    if (LURE_STEP_COUNT && GetNumberOfActiveOWEs(OWE_GENERATED) < OWE_SPAWNS_MAX)
        sOWESpawnCountdown = OWE_SPAWN_TIME_LURE;
}

void TryTriggerOverworldWildEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider)
{
    if (WE_OWE_NO_REPEL_DEXNAV_COLLISION && (FlagGet(DN_FLAG_SEARCHING) || REPEL_STEP_COUNT))
        return;

    bool32 playerFollowerIsColliderOWE = ((collider->isPlayer || collider->localId == OBJ_EVENT_ID_FOLLOWER)
                                          && IsOverworldWildEncounter(obstacle, OWE_ANY));
    bool32 playerFollowerIsObstacleOWE = ((obstacle->isPlayer || obstacle->localId == OBJ_EVENT_ID_FOLLOWER)
                                          && IsOverworldWildEncounter(collider, OWE_ANY));

    if (!playerFollowerIsColliderOWE && !playerFollowerIsObstacleOWE)
        return;

    struct ObjectEvent *wildMon = playerFollowerIsColliderOWE ? obstacle : collider;
    enum CategoryOWE category = GetOWECategory(wildMon);
    if (category < ROAMER_COUNT
     && !IsRoamerAt(category, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
        RemoveObjectEvent(wildMon);
        return;
    }

    gSpecialVar_LastTalked = wildMon->localId;
    gSelectedObjectEvent = GetObjectEventIdByLocalId(wildMon->localId);

    // Stop the bobbing animation.
    if (wildMon->movementActionId >= MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN && wildMon->movementActionId <= MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT)
        ClearObjectEventMovement(wildMon, &gSprites[wildMon->spriteId]);

    ScriptContext_SetupScript(InteractWithOverworldWildEncounter);
}

const u8 *GetOverworlWildEncounterScript(u32 objectEventId)
{
    const u8 *script;
    if (GetOverworldWildEncounterType(&gObjectEvents[objectEventId]) == OWE_MANUAL
     && (script = GetObjectEventScriptPointerByObjectEventId(objectEventId)) != NULL)
        return script;
    
    return InteractWithOverworldWildEncounter;
}

static bool32 CheckCurrentWildMonHeaderForOWE(bool32 shouldSpawnWaterMons)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;

    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            return gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo != NULL;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            return gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo != NULL;
        }
        return FALSE;
    }

    if (shouldSpawnWaterMons)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
        return gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo != NULL;
    }

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    return gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo != NULL;
}

static u32 GetOldestActiveOWESlot(bool32 forceRemove)
{
    struct ObjectEvent *slotMon, *oldest = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END)];
    u32 spawnSlot;

    for (spawnSlot = 0; spawnSlot < OWE_SPAWNS_MAX; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(spawnSlot))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && (!HasOWENoDespawnFlag(slotMon) || forceRemove == TRUE))
        {
            oldest = slotMon;
            break;
        }
    }

    if (spawnSlot >= OWE_SPAWNS_MAX)
        return OWE_INVALID_SPAWN_SLOT;

    for (u32 i = spawnSlot; i < OWE_SPAWNS_MAX; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(i))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && (!HasOWENoDespawnFlag(slotMon) || forceRemove == TRUE))
        {
            if (slotMon->sOverworldEncounterAge > oldest->sOverworldEncounterAge)
                oldest = slotMon;
        }
    }

    return GetSpawnSlotByOWELocalId(oldest->localId);
}

static u32 GetNextOWESpawnSlot(void)
{
    u32 spawnSlot;

    // All mon slots are in use
    if (GetNumberOfActiveOWEs(OWE_GENERATED) >= OWE_SPAWNS_MAX)
    {
        if (WE_OWE_SPAWN_REPLACEMENT)
        {
            // Cycle through so we remove the oldest mon first
            return GetOldestActiveOWESlot(FALSE); 
        }
        return OWE_INVALID_SPAWN_SLOT;
    }
    for (spawnSlot = 0; spawnSlot < OWE_SPAWNS_MAX; spawnSlot++)
    {
        if (GetSpeciesByOWESpawnSlot(spawnSlot) == SPECIES_NONE)
            break;
    }

    return spawnSlot;
}

static enum Species GetSpeciesByOWESpawnSlot(u32 spawnSlot)
{
    u32 objEventId = GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(spawnSlot));
    struct ObjectEvent *owe = &gObjectEvents[objEventId];

    if (objEventId >= OBJECT_EVENTS_COUNT)
        return SPECIES_NONE;

    return OW_SPECIES(owe);
}

static bool32 TrySelectTileForOWE(s32* outX, s32* outY)
{
    u32 elevation;
    u32 tileBehavior;
    s16 playerX, playerY;
    s16 x, y;
    u32 closeDistance;
    bool32 isEncounterTile = FALSE;

    // Spawn further away when surfing
    if (ShouldSpawnWaterOWE())
        closeDistance = OWE_SPAWN_DISTANCE_WATER;
    else
        closeDistance = OWE_SPAWN_DISTANCE_LAND;

    // Select a random tile in [-OWE_SPAWN_WIDTH_RADIUS, -OWE_SPAWN_HEIGHT_RADIUS] [OWE_SPAWN_WIDTH_RADIUS, OWE_SPAWN_HEIGHT_RADIUS]
    // range while excluding tiles that are less than closeDistance away from the player.
    x = (s16)(Random() % (OWE_SPAWN_WIDTH_TOTAL - 2 * closeDistance) ) - (OWE_SPAWN_WIDTH_RADIUS - closeDistance);
    if (x < 0)
        x -= closeDistance;
    else
        x += closeDistance;

    y = (s16)(Random() % (OWE_SPAWN_HEIGHT_TOTAL - 2 * closeDistance) ) - (OWE_SPAWN_HEIGHT_RADIUS - closeDistance);
    if (y < 0)
        y -= closeDistance;
    else
        y += closeDistance;
    
    PlayerGetDestCoords(&playerX, &playerY);
    x += playerX;
    y += playerY;

    elevation = MapGridGetElevationAt(x, y);

    if (!AreCoordsInsidePlayerMap(x, y))
        return FALSE;

    // These elevations cause weird interactions, so spawns are prevented.
    if (elevation == ELEVATION_TRANSITION || elevation == ELEVATION_MULTI_LEVEL)
        return FALSE;

    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (ShouldSpawnWaterOWE() && MetatileBehavior_IsWaterWildEncounter(tileBehavior))
        isEncounterTile = TRUE;

    if (!ShouldSpawnWaterOWE() && MetatileBehavior_IsLandWildEncounter(tileBehavior))
        isEncounterTile = TRUE;

    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS
     || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        isEncounterTile = TRUE;

    if (isEncounterTile && !MapGridGetCollisionAt(x, y))
    {
        *outX = x;
        *outY = y;

        if (GetObjectEventIdByPosition(x, y, 0) == OBJECT_EVENTS_COUNT)
            return TRUE;
    }

    return FALSE;
}

static void SetSpeciesInfoForOWE(struct InfoOWE *info, u32 x, u32 y)
{
    u32 personality;

    if (!CreateEnemyPartyOWE(info, x, y))
    {
        ZeroEnemyPartyMons();
        info->speciesId = SPECIES_NONE;
        return;
    }
 
    info->speciesId = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES);
    info->level = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_LEVEL);
    personality = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_PERSONALITY);

    if (info->speciesId == SPECIES_UNOWN)
        info->speciesId = GetUnownSpeciesId(personality);

    info->isShiny = ComputePlayerShinyOdds(personality, READ_OTID_FROM_SAVE);
    if (GetGenderFromSpeciesAndPersonality(info->speciesId, personality) == MON_FEMALE)
        info->isFemale = TRUE;
    else
        info->isFemale = FALSE;

    if (WE_OWE_PREVENT_SHINY_DESPAWN && info->isShiny)
        info->noDespawn = TRUE;

    if (info->category == OWE_CATEGORY_UNDEFINED)
        info->category = OWE_CATEGORY_WILD;

    ZeroEnemyPartyMons();
}

static u32 GetGraphicsIdForOWE(const struct InfoOWE *info)
{
    assertf(CheckValidOWESpecies(info->speciesId), "invalid generated overworld encounter\nspecies: %d\ncheck if valid wild mon header exists", info->speciesId);
    return GetGraphicsIdForMon(info->speciesId, info->isShiny, info->isFemale);
}

static bool32 CheckCanLoadOWE(enum Species speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y)
{
    assertf(CheckCanLoadOWE_Palette(speciesId, isFemale, isShiny, x, y), "could not load palette for overworld encounter\nspecies: %d\nfemale: %d\nshiny: %d\ncoords: %d %d", speciesId, isFemale, isShiny, x, y)
    {
        return FALSE;
    }

    assertf(CheckCanLoadOWE_Tiles(speciesId, isFemale, isShiny, x, y), "could not load sprite tiles for overworld encounter\nspecies: %d\nfemale: %d\nshiny: %d\ncoords: %d %d", speciesId, isFemale, isShiny, x, y)
    {
        return FALSE;
    }

    return TRUE;
}

static bool32 CheckCanLoadOWE_Palette(enum Species speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y)
{
    u32 numFreePalSlots = CountFreePaletteSlots();
    u32 tag = speciesId + OBJ_EVENT_MON + (isShiny ? OBJ_EVENT_MON_SHINY : 0);

#if P_GENDER_DIFFERENCES
    if (isFemale && gSpeciesInfo[speciesId].overworldShinyPaletteFemale != NULL)
        tag += OBJ_EVENT_MON_FEMALE;
#endif

    // We need at least 2 pal slots open. One for the object and one for the spawn field effect.
    // Add this and tiles to seperate graphics check function
    if (numFreePalSlots == 1)
    {
        u32 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
        struct SpritePalette palette = GetOWESpawnDespawnAnimFldEffPalette(GetOWESpawnDespawnAnimType(metatileBehavior));
        // If the mon's palette or field effect palette isn't already loaded, don't spawn.
        // Include check if female or shiny mon is loaded and use that tag if possible
        if (IndexOfSpritePaletteTag(tag) == 0xFF && IndexOfSpritePaletteTag(palette.tag) == 0xFF)
            return FALSE;
    }
    else if (numFreePalSlots == 0)
    {
        return FALSE;
    }

    return TRUE;
}

static u32 GetNumberOfSpawnAnimTiles(s32 x, s32 y)
{
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    enum SpawnDespawnTypeOWE spawnAnimType = GetOWESpawnDespawnAnimType(metatileBehavior);
    u32 visual = gOverworldWildEncounterFieldEffectInfo[spawnAnimType].visual;

    return gFieldEffectObjectTemplatePointers[visual]->images->size / TILE_SIZE_4BPP;
}

static bool32 CheckCanLoadOWE_Tiles(enum Species speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y)
{
    u32 graphicsId = GetGraphicsIdForMon(speciesId, isShiny, isFemale);
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
    u32 tileCount = graphicsInfo->size / TILE_SIZE_4BPP;
    if (OW_GFX_COMPRESS)
    {
        u32 tag = graphicsInfo->tileTag;
        u32 frames;
        if (graphicsInfo->tileTag == TAG_NONE)
            tag = COMP_OW_TILE_TAG_BASE + graphicsId;
        
        // The entire spritesheet is loaded when compressed, so if tiles exist, return early.
        if (IndexOfSpriteTileTag(tag) != 0xFF)
            return TRUE;
        
        // Custom Pokémon Object Anims will need to be accounted for.
        frames = graphicsInfo->anims == sAnimTable_Following_Asym ? 8 : 6;
        frames++; // Add an extra frame to equate offset of TILE_SIZE_4BPP << sheetSpan
        tileCount *= frames;
    }
    
    tileCount += GetNumberOfSpawnAnimTiles(x, y);
    if (!CanAllocSpriteTiles(tileCount))
        return FALSE;
    
    return TRUE;
}

static void SortOWEAges(void)
{
    struct ObjectEvent *slotMon;
    struct AgeSort array[OWE_SPAWNS_MAX];
    struct AgeSort current;
    u32 numActive = GetNumberOfActiveOWEs(OWE_GENERATED);
    u32 count = 0;
    s32 i, j;

    if (OWE_SPAWNS_MAX <= 1)
        return;

    for (i = 0; i < OWE_SPAWNS_MAX; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(i))];
        // OWE_ANY can be used here as localId is guarenteed to be in the OWE_GENERATED range by GetLocalIdByOWESpawnSlot.
        if (IsOverworldWildEncounter(slotMon, OWE_ANY) && OW_SPECIES(slotMon) != SPECIES_NONE)
        {
            array[count].slot = i;
            array[count].age = slotMon->sOverworldEncounterAge;
            count++;
        }
        if (count == numActive)
            break;
    }

    for (i = 1; i < numActive; i++)
    {
        current = array[i];
        j = i - 1;

        while (j >= 0 && array[j].age < current.age)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = current;
    }
    
    for (i = 0; i < numActive; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(array[i].slot))];
        slotMon->sOverworldEncounterAge = numActive - i;
    }
}

void OnOverworldWildEncounterSpawn(struct ObjectEvent *owe)
{
    enum TypeOWE type = GetOverworldWildEncounterType(owe);
    if (type == OWE_NONE)
        return;

    if (type == OWE_MANUAL)
        owe->sOverworldEncounterCategory = OWE_CATEGORY_WILD;
    
    if (type == OWE_GENERATED)
        SortOWEAges();

    DoOWESpawnAnim(owe);
}

void OnOverworldWildEncounterDespawn(struct ObjectEvent *owe)
{
    enum TypeOWE type = GetOverworldWildEncounterType(owe);
    if (type == OWE_NONE)
        return;

    if (owe->sOverworldEncounterCategory < ROAMER_COUNT)
        RoamerMove(owe->sOverworldEncounterCategory);

    owe->sOverworldEncounterLevel = 0;
    owe->sOverworldEncounterAge = 0;
    owe->sOverworldEncounterCategory = 0;
    
    DoOWEDespawnAnim(owe);
}

bool32 IsOWEDespawnExempt(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return FALSE;

    if (HasOWENoDespawnFlag(owe) && AreCoordsInsidePlayerMap(owe->currentCoords.x, owe->currentCoords.y))
        return TRUE;

    return FALSE;
}

bool32 DespawnOWEDueToNPCCollision(struct ObjectEvent *obstacle, struct ObjectEvent *activeObject)
{
    if (activeObject->isPlayer)
        return FALSE;

    if (IsOverworldWildEncounter(activeObject, OWE_ANY))
        return FALSE;
    
    if (!IsOverworldWildEncounter(obstacle, OWE_GENERATED))
        return FALSE;

    RemoveObjectEvent(obstacle);
    return TRUE;
}

void DespawnAllOverworldWildEncounters(enum TypeOWE oweType, u32 flags)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        struct ObjectEvent *owe = &gObjectEvents[i];

        if (!owe->active)
            continue;

        if (!IsOverworldWildEncounter(owe, oweType))
            continue;

        if (flags & WILD_CHECK_REPEL)
        {
            if (!REPEL_STEP_COUNT)
                continue;

            if (HasOWENoDespawnFlag(owe))
                continue;

            if (IsWildLevelAllowedByRepel(owe->sOverworldEncounterLevel & ~OWE_NO_DESPAWN_FLAG))
                continue;
        }

        RemoveObjectEvent(owe);
    }
}

u32 TryAndDespawnOldestGeneratedOWE_ToFreeObject(void)
{
    if (!WE_OW_ENCOUNTERS)
        return OBJECT_EVENTS_COUNT;

    return RemoveOldestGeneratedOWE();
}

void DespawnOWEOnBattleStart(void)
{
    struct ObjectEvent *owe = &gObjectEvents[GetObjectEventIdByLocalId(gSpecialVar_LastTalked)];
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return;

    if (IsOverworldWildEncounter(owe, OWE_MANUAL))
        FlagSet(GetObjectEventFlagIdByLocalIdAndMap(owe->localId, owe->mapNum, owe->mapGroup));

    ClearObjectEvent(owe);
    SetNewOWESpawnCountdown();
    gSpecialVar_LastTalked = LOCALID_NONE;
}

void TryDespawnOWEsCrossingMapConnection(void)
{
    if (!WE_OWE_DESPAWN_ON_ENTER_TOWN)
        return;

    if (gMapHeader.mapType != MAP_TYPE_CITY && gMapHeader.mapType != MAP_TYPE_TOWN)
        return;

    if (WE_OWE_DESPAWN_SOUND)
        PlaySE(SE_FLEE);
        
    DespawnAllOverworldWildEncounters(OWE_GENERATED, 0);
}

u32 RemoveOldestGeneratedOWE(void)
{
    u32 oldestSlot = GetOldestActiveOWESlot(TRUE);

    if (oldestSlot == OWE_INVALID_SPAWN_SLOT)
        return OBJECT_EVENTS_COUNT;

    u32 objectEventId = GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(oldestSlot));
    RemoveObjectEvent(&gObjectEvents[objectEventId]);
    return objectEventId;
}

static bool32 ShouldDespawnGeneratedForNewOWE(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_GENERATED))
        return FALSE;

    return WE_OWE_SPAWN_REPLACEMENT && GetNumberOfActiveOWEs(OWE_GENERATED) >= OWE_SPAWNS_MAX;
}

static void SetNewOWESpawnCountdown(void)
{
    u32 numActive = GetNumberOfActiveOWEs(OWE_GENERATED);

    if (WE_OWE_SPAWN_REPLACEMENT && numActive >= OWE_SPAWNS_MAX)
        sOWESpawnCountdown = OWE_SPAWN_TIME_REPLACEMENT;
    else if (LURE_STEP_COUNT && numActive < OWE_SPAWNS_MAX)
        sOWESpawnCountdown = OWE_SPAWN_TIME_LURE;
    else
        sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM + (OWE_SPAWN_TIME_PER_ACTIVE * numActive);
}

static void DoOWESpawnAnim(struct ObjectEvent *owe)
{
    bool32 isShiny = OW_SHINY(owe) ? TRUE : FALSE;
    enum SpawnDespawnTypeOWE spawnAnimType;

    if (WE_OWE_SHINY_SPARKLE && isShiny)
    {
        PlaySE(SE_SHINY);
        spawnAnimType = OWE_SPAWN_ANIM_SHINY;
    }
    else
    {
        PlayOWECry(owe);
        u32 metatileBehavior = MapGridGetMetatileBehaviorAt(owe->currentCoords.x, owe->currentCoords.y);
        spawnAnimType = GetOWESpawnDespawnAnimType(metatileBehavior);
    }

    MovementAction_OverworldEncounterSpawn(spawnAnimType, owe);
}

static void DoOWEDespawnAnim(struct ObjectEvent *owe)
{
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(owe->currentCoords.x, owe->currentCoords.y);
    enum SpawnDespawnTypeOWE spawnAnimType = GetOWESpawnDespawnAnimType(metatileBehavior);
    MovementAction_OverworldEncounterSpawn(spawnAnimType, owe);
    if (OWE_ShouldPlayOWEFleeSound(owe))
        PlaySE(SE_FLEE);
}

static enum SpawnDespawnTypeOWE GetOWESpawnDespawnAnimType(u32 metatileBehavior)
{
    if (MetatileBehavior_IsPokeGrass(metatileBehavior) || MetatileBehavior_IsAshGrass(metatileBehavior))
        return OWE_SPAWN_ANIM_GRASS;
    else if (MetatileBehavior_IsLongGrass(metatileBehavior))
        return OWE_SPAWN_ANIM_LONG_GRASS;
    else if (MetatileBehavior_IsSurfableFishableWater(metatileBehavior) && gMapHeader.mapType != MAP_TYPE_UNDERWATER)
        return OWE_SPAWN_ANIM_WATER;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        return OWE_SPAWN_ANIM_UNDERWATER;
    else
        return OWE_SPAWN_ANIM_CAVE;
}

static void PlayOWECry(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return;
    
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    enum Species speciesId = OW_SPECIES(owe);
    s32 distanceX = owe->currentCoords.x - player->currentCoords.x;
    s32 distanceY = owe->currentCoords.y - player->currentCoords.y;
    u32 distanceMax = OWE_SPAWN_WIDTH_RADIUS + OWE_SPAWN_HEIGHT_RADIUS;
    u32 distance;
    u32 volume;
    s32 pan;

    if (distanceX > OWE_SPAWN_WIDTH_RADIUS)
        distanceX = OWE_SPAWN_WIDTH_RADIUS;
    else if (distanceX < -OWE_SPAWN_WIDTH_RADIUS)
        distanceX = -OWE_SPAWN_WIDTH_RADIUS;

    distanceY = abs(distanceY);
    if (distanceY > OWE_SPAWN_HEIGHT_RADIUS)
        distanceY = OWE_SPAWN_HEIGHT_RADIUS;

    distance = abs(distanceX) + distanceY;
    if (distance > distanceMax)
        distance = distanceMax;

    volume = 80 - (distance * (80 - 50)) / distanceMax;
    pan = 212 + ((distanceX + OWE_SPAWN_WIDTH_RADIUS) * (300 - 212)) / (2 * OWE_SPAWN_WIDTH_RADIUS);
    
    PlayCry_NormalNoDucking(speciesId, pan, volume, CRY_PRIORITY_AMBIENT);
}

static struct ObjectEvent *GetRandomOWEObjectEvent(void)
{
    u32 counter = 0;
    struct ObjectEvent *owe;
    u32 tmpArray[OBJECT_EVENTS_COUNT] = {0};

    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        owe = &gObjectEvents[i];
        if (IsOverworldWildEncounter(owe, OWE_ANY))
        {
            tmpArray[counter] = i;
            counter++;
        }
    }
    if (counter > 0)
        return &gObjectEvents[tmpArray[(Random() % counter)]];
        
    return NULL;
}

static bool32 OWE_ShouldPlayOWEFleeSound(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY) || OW_SPECIES(owe) == SPECIES_NONE)
        return FALSE;

    if (!AreCoordsInsidePlayerMap(owe->currentCoords.x, owe->currentCoords.y))
        return FALSE;

    if (ShouldDespawnGeneratedForNewOWE(owe))
        return FALSE;

    if (owe->offScreen)
        return FALSE;

    return WE_OWE_DESPAWN_SOUND;
}

#define sTypeFuncId data[1] // Same as in src/event_object_movement.c
#define sJumpTimer  sprite->data[7] // Same as in src/event_object_movement.c
void RestoreSavedOWEBehaviorState(struct ObjectEvent *owe, struct Sprite *sprite)
{
    if (IsOverworldWildEncounter(owe, OWE_ANY) && HasSavedOWEMovementState(owe))
    {
        sprite->sTypeFuncId = OWE_RESTORED_MOVEMENT_FUNC_ID;
        if (owe->movementType == MOVEMENT_TYPE_APPROACH_PLAYER_OWE)
            sJumpTimer = RandomUniform(RNG_NONE, OWE_APPROACH_JUMP_TIMER_MIN, OWE_APPROACH_JUMP_TIMER_MAX);
    }
}
#undef sTypeFuncId
#undef sJumpTimer

// Returns TRUE if movement is restricted.
bool32 CheckRestrictedOWEMovement(struct ObjectEvent *owe, enum Direction direction)
{
    if (GetCollisionInDirection(owe, direction))
        return TRUE;

    if (WE_OWE_UNRESTRICT_SIGHT
     && owe->movementType != MOVEMENT_TYPE_WANDER_AROUND_OWE
     && CanAwareOWESeePlayer(owe))
        return FALSE;

    s32 xCurrent = owe->currentCoords.x;
    s32 yCurrent = owe->currentCoords.y;
    s32 xNew = xCurrent + gDirectionToVectors[direction].x;
    s32 yNew = yCurrent + gDirectionToVectors[direction].y;

    if (CheckRestrictedOWEMovementMetatile(xCurrent, yCurrent, xNew, yNew))
        return TRUE;
    
    if (CheckRestrictedOWEMovementMap(owe, xNew, yNew))
        return TRUE;

    return FALSE;
}

static bool32 CheckRestrictedOWEMovementAtCoords(struct ObjectEvent *owe, s32 xNew, s32 yNew, enum Direction newDirection, enum Direction collisionDirection)
{
    if (CheckRestrictedOWEMovementMetatile(owe->currentCoords.x, owe->currentCoords.y, xNew, yNew))
        return FALSE;

    if (CheckRestrictedOWEMovementMap(owe, xNew, yNew))
        return FALSE;

    if (GetCollisionAtCoords(owe, xNew, yNew, collisionDirection))
        return FALSE;

    return TRUE;
}

static bool32 CheckRestrictedOWEMovementMetatile(s32 xCurrent, s32 yCurrent, s32 xNew, s32 yNew)
{
    if (!WE_OWE_RESTRICT_METATILE)
        return FALSE;

    u32 metatileBehaviourCurrent = MapGridGetMetatileBehaviorAt(xCurrent, yCurrent);
    u32 metatileBehaviourNew = MapGridGetMetatileBehaviorAt(xNew, yNew);

    if (MetatileBehavior_IsLandWildEncounter(metatileBehaviourCurrent)
     && MetatileBehavior_IsLandWildEncounter(metatileBehaviourNew))
        return FALSE;

    if (MetatileBehavior_IsWaterWildEncounter(metatileBehaviourCurrent)
     && MetatileBehavior_IsWaterWildEncounter(metatileBehaviourNew))
        return FALSE;

    if (!MetatileBehavior_IsLandWildEncounter(metatileBehaviourCurrent)
     && !MetatileBehavior_IsWaterWildEncounter(metatileBehaviourCurrent))
        return FALSE;

    return TRUE;
}

static bool32 CheckRestrictedOWEMovementMap(struct ObjectEvent *owe, s32 xNew, s32 yNew)
{
    if (!WE_OWE_RESTRICT_MAP)
        return FALSE;
    
    if (owe->mapGroup == gSaveBlock1Ptr->location.mapGroup
     && owe->mapNum == gSaveBlock1Ptr->location.mapNum)
        return !AreCoordsInsidePlayerMap(xNew, yNew);
    else
        return AreCoordsInsidePlayerMap(xNew, yNew);
}

bool32 CanAwareOWESeePlayer(struct ObjectEvent *owe)
{
    if (owe->movementType == MOVEMENT_TYPE_WANDER_AROUND_OWE)
        return FALSE;

    if (gPlayerAvatar.runningState == MOVING
     && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_BIKE)
     && IsPlayerInsideOWEActiveDistance(owe))
        return TRUE;

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    enum Species speciesId = OW_SPECIES(owe);
    u32 viewDistance = OWE_GetViewDistanceFromSpecies(speciesId);
    u32 viewWidth = OWE_GetViewWidthFromSpecies(speciesId);
    s32 halfWidth = (viewWidth - 1) / 2;
    enum Direction direction = owe->facingDirection;

    switch (direction)
    {
    case DIR_NORTH:
        if (!(player->currentCoords.y <= owe->currentCoords.y
         && owe->currentCoords.y - player->currentCoords.y <= viewDistance
         && player->currentCoords.x >= owe->currentCoords.x - halfWidth
         && player->currentCoords.x <= owe->currentCoords.x + halfWidth))
            return FALSE;
        break;

    case DIR_SOUTH:
        if (!(player->currentCoords.y >= owe->currentCoords.y
         && player->currentCoords.y - owe->currentCoords.y <= viewDistance
         && player->currentCoords.x >= owe->currentCoords.x - halfWidth
         && player->currentCoords.x <= owe->currentCoords.x + halfWidth))
            return FALSE;
        break;

    case DIR_EAST:
        if (!(player->currentCoords.x >= owe->currentCoords.x
         && player->currentCoords.x - owe->currentCoords.x <= viewDistance
         && player->currentCoords.y >= owe->currentCoords.y - halfWidth
         && player->currentCoords.y <= owe->currentCoords.y + halfWidth))
            return FALSE;
        break;

    case DIR_WEST:
        if (!(player->currentCoords.x <= owe->currentCoords.x
         && owe->currentCoords.x - player->currentCoords.x <= viewDistance
         && player->currentCoords.y >= owe->currentCoords.y - halfWidth
         && player->currentCoords.y <= owe->currentCoords.y + halfWidth))
            return FALSE;
        break;

    default:
        return FALSE;
    }

    return CanOWEReachPlayer(owe);
}

static bool32 CanOWEReachPlayer(struct ObjectEvent *owe)
{
    // In future, checks similar to trainer_see.c can be included.
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    return !IsElevationMismatchAt(owe->currentElevation, player->currentCoords.x, player->currentCoords.y);
}

bool32 IsPlayerInsideOWEActiveDistance(struct ObjectEvent *owe)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 distance = OWE_DEFAULT_CHASE_RANGE;
    enum Species speciesId = OW_SPECIES(owe);

    if (speciesId != SPECIES_NONE)
        distance = OWE_GetViewActiveDistanceFromSpecies(speciesId);

    s32 absX = abs(player->currentCoords.x - owe->currentCoords.x);
    s32 absY = abs(player->currentCoords.y - owe->currentCoords.y);

    if (absX > distance || absY > distance)
        return FALSE;

    s32 diagonalDistance = (distance * 362) >> 8; // binary approximation of multiplying distance by sqrt(2)
    if ((absX + absY) > diagonalDistance)
        return FALSE;

    return TRUE;
}

bool32 IsOWENextToPlayer(struct ObjectEvent *owe)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    return IsOWENextToObject(owe, player);
}

static bool32 IsOWENextToObject(struct ObjectEvent *owe, struct ObjectEvent *object)
{
    if ((owe->currentCoords.x != object->currentCoords.x && owe->currentCoords.y != object->currentCoords.y) || (owe->currentCoords.x < object->currentCoords.x - 1 || owe->currentCoords.x > object->currentCoords.x + 1 || owe->currentCoords.y < object->currentCoords.y - 1 || owe->currentCoords.y > object->currentCoords.y + 1))
        return FALSE;

    return TRUE;
}

enum Direction DirectionOfOWEToPlayerFromCollision(struct ObjectEvent *owe)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    switch (owe->movementDirection)
    {
    case DIR_NORTH:
    case DIR_SOUTH:
        if (player->currentCoords.x < owe->currentCoords.x)
            return DIR_WEST;
        else if (player->currentCoords.x == owe->currentCoords.x)
            return CheckOWEPathToPlayerFromCollision(owe, (Random() & 1)  ? DIR_EAST : DIR_WEST);
        else
            return DIR_EAST;
    case DIR_EAST:
    case DIR_WEST:
        if (player->currentCoords.y < owe->currentCoords.y)
            return DIR_NORTH;
        else if (player->currentCoords.y == owe->currentCoords.y)
            return CheckOWEPathToPlayerFromCollision(owe, (Random() & 1)  ? DIR_NORTH : DIR_SOUTH);
        else
            return DIR_SOUTH;
    }

    return owe->movementDirection;
}

u32 GetApproachingOWEDistanceToPlayer(struct ObjectEvent *owe, bool32 *equalDistances)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    s32 absX, absY;
    s32 distanceX = player->currentCoords.x - owe->currentCoords.x;
    s32 distanceY = player->currentCoords.y - owe->currentCoords.y;

    if (distanceX < 0)
        absX = distanceX * -1;
    else
        absX = distanceX;

    if (distanceY < 0)
        absY = distanceY * -1;
    else
        absY = distanceY;

    if (absY == absX)
        *equalDistances = TRUE;

    if (absY > absX)
        return absY;
    else
        return absX;
}

u32 GetOWEWalkMovementActionInDirectionWithSpeed(enum Direction direction, enum SpeedOWE speed)
{
    switch (speed)
    {
    case OWE_SPEED_SLOW:
        return GetWalkSlowMovementAction(direction);
    case OWE_SPEED_FAST:
        return GetWalkFastMovementAction(direction);
    case OWE_SPEED_FASTER:
        return GetWalkFasterMovementAction(direction);
    case OWE_SPEED_NORMAL:
    default:
        return GetWalkNormalMovementAction(direction);
    }
}

static enum Direction CheckOWEPathToPlayerFromCollision(struct ObjectEvent *owe, enum Direction newDirection)
{
    s16 x = owe->currentCoords.x;
    s16 y = owe->currentCoords.y;

    MoveCoords(newDirection, &x, &y);
    if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, newDirection))
    {
        if (owe->movementType == MOVEMENT_TYPE_FLEE_PLAYER_OWE)
            return GetOppositeDirection(newDirection);

        MoveCoords(owe->movementDirection, &x, &y);
        if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, owe->movementDirection))
            return newDirection;
    }

    x = owe->currentCoords.x;
    y = owe->currentCoords.y;
    MoveCoords(GetOppositeDirection(newDirection), &x, &y);
    if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, newDirection))
    {
        if (owe->movementType == MOVEMENT_TYPE_FLEE_PLAYER_OWE)
            return newDirection;

        MoveCoords(owe->movementDirection, &x, &y);
        if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, owe->movementDirection))
            return GetOppositeDirection(newDirection);
    }

    return owe->movementDirection;
}

#define tObjectId data[0]
void OWEApproachForBattle(struct ScriptContext *ctx)
{
    u32 localId = VarGet(ScriptReadHalfword(ctx));
    u32 objectEventId = GetObjectEventIdByLocalId(localId);
    struct ObjectEvent *owe = &gObjectEvents[objectEventId];

    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    
    if (!WE_OWE_APPROACH_FOR_BATTLE || !IsOverworldWildEncounter(owe, OWE_ANY))
    {
        FreezeObjectEvent(owe);
        return;
    }
    
    u32 taskId = CreateTask(Task_OWEApproachForBattle, 2);
    if (FindTaskIdByFunc(Task_OWEApproachForBattle) == TASK_NONE)
    {
        FreezeObjectEvent(owe);
        return;
    }
    
    ScriptContext_Stop();
    gTasks[taskId].tObjectId = objectEventId;
}

static void Task_OWEApproachForBattle(u8 taskId)
{
    struct ObjectEvent *OWE = &gObjectEvents[gTasks[taskId].tObjectId];

    // Let the mon continue to take steps until right next to the player.
    if (ObjectEventClearHeldMovementIfFinished(OWE))
    {
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
        struct ObjectEvent *followerMon = GetFollowerObject();
        bool32 oweNextToPlayer = IsOWENextToPlayer(OWE);
        bool32 oweNextToFollowerMon = IsOWENextToObject(OWE, followerMon);

        if (oweNextToPlayer || oweNextToFollowerMon)
        {
            if (oweNextToPlayer)
            {
                ObjectEventsTurnToEachOther(player, OWE);
            }
            else
            {
                ObjectEventTurn(player, DetermineObjectEventDirectionFromObject(followerMon, player));
                ObjectEventsTurnToEachOther(followerMon, OWE);
            }
            ScriptContext_Enable();
            DestroyTask(taskId);
            return;
        }

        enum Species speciesId = OW_SPECIES(OWE);
        enum Direction direction = DetermineObjectEventDirectionFromObject(player, OWE);
        u32 movementActionId;
    
        SetObjectEventDirection(OWE, direction);
        movementActionId = GetOWEWalkMovementActionInDirectionWithSpeed(OWE->movementDirection, OWE_GetActiveSpeedFromSpecies(speciesId));
        
        if (CheckRestrictedOWEMovement(OWE, OWE->movementDirection))
        {
            u32 idFollowerNPC = GetFollowerNPCObjectId();
            struct ObjectEvent *followerNPC = &gObjectEvents[idFollowerNPC];
            s16 x = OWE->currentCoords.x;
            s16 y = OWE->currentCoords.y;
            u32 collidingObject;

            MoveCoords(OWE->movementDirection, &x, &y);
            collidingObject = GetObjectObjectCollidesWith(OWE, x, y, FALSE);

            if (collidingObject == GetObjectEventIdByLocalId(followerMon->localId) && followerMon != NULL && !followerMon->invisible)
            {
                ClearObjectEventMovement(followerMon, &gSprites[followerMon->spriteId]);
                gSprites[followerMon->spriteId].animCmdIndex = 0;
                ObjectEventSetHeldMovement(followerMon, MOVEMENT_ACTION_ENTER_POKEBALL);
            }
            else if (collidingObject == idFollowerNPC && FNPC_ENABLE_NPC_FOLLOWERS && PlayerHasFollowerNPC() && !followerNPC->invisible)
            {
                enum Direction direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], followerNPC);
                ClearObjectEventMovement(followerNPC, &gSprites[followerNPC->spriteId]);
                gSprites[followerNPC->spriteId].animCmdIndex = 0;
                ObjectEventSetHeldMovement(followerNPC, GetWalkNormalMovementAction(direction));
                CreateTask(Task_HideNPCFollowerAfterMovementFinish, 2);
            }
            else if (collidingObject == gPlayerAvatar.objectEventId)
            {
                movementActionId = GetFaceDirectionMovementAction(OWE->facingDirection);
            }
            else
            {
                direction = DirectionOfOWEToPlayerFromCollision(OWE);
                SetObjectEventDirection(OWE, direction);
                movementActionId = GetOWEWalkMovementActionInDirectionWithSpeed(OWE->movementDirection, OWE_GetActiveSpeedFromSpecies(speciesId));
            }
        }
        ObjectEventSetHeldMovement(OWE, movementActionId);
    }
    
}
#undef tObjectId

bool32 TryPlayAmbientCryOWE(void)
{
    struct ObjectEvent *owe = GetRandomOWEObjectEvent();
    if (owe == NULL)
        return FALSE;
    
    PlayOWECry(owe);
    return TRUE;
}

u32 GetNumberOfActiveOWEs(enum TypeOWE oweType)
{
    u32 numActive = 0;
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (IsOverworldWildEncounter(&gObjectEvents[i], oweType))
            numActive++;
    }
    return numActive;
}

const struct ObjectEventTemplate TryGetObjectEventTemplateForOWE(const struct ObjectEventTemplate *template)
{
    if (template->trainerType != TRAINER_TYPE_OW_WILD_ENCOUNTER
     || IS_LOCALID_GENERATED_OWE(template->localId))
        return *template;

    struct ObjectEventTemplate templateOWE = *template;
    struct InfoOWE info = {0};
    info.category = OWE_CATEGORY_WILD;
    
    enum Species speciesTemplate = SanitizeSpeciesId(templateOWE.graphicsId & OBJ_EVENT_MON_SPECIES_MASK);
    bool32 isShinyTemplate = (templateOWE.graphicsId & OBJ_EVENT_MON_SHINY) ? TRUE : FALSE;
    u32 levelTemplate = templateOWE.sOverworldEncounterLevel;
    u32 x = template->x;
    u32 y = template->y;

    SetSpeciesInfoForOWE(&info, x, y);
    if (speciesTemplate)
        info.speciesId = speciesTemplate;

    if (levelTemplate)
        info.level = levelTemplate;

    assertf((CheckValidOWESpecies(info.speciesId)
        && info.level >= MIN_LEVEL
        && info.level <= MAX_LEVEL)
        || gObjectEvents[GetObjectEventIdByLocalId(template->localId)].active,
        "invalid manual overworld encounter template\nspecies: %d\nlevel: %d\ntemplate x: %d\ntemplate y: %d\ncheck if valid wild mon header exists", info.speciesId, info.level, x, y)
    {
        if (!CheckValidOWESpecies(info.speciesId))
        {
            templateOWE.graphicsId = OBJ_EVENT_GFX_BOY_1;
            templateOWE.trainerType = TRAINER_TYPE_NONE;
            templateOWE.sOverworldEncounterLevel = 0;
            templateOWE.movementType = MOVEMENT_TYPE_NONE;
            return templateOWE;
        }
        else if (!(info.level >= MIN_LEVEL && info.level <= MAX_LEVEL))
        {
            info.level = MIN_LEVEL;
        }
    }

    if (isShinyTemplate)
        info.isShiny = isShinyTemplate;

    if (templateOWE.graphicsId & OBJ_EVENT_MON && templateOWE.graphicsId & OBJ_EVENT_MON_FEMALE)
        info.isFemale = TRUE;
    else if (templateOWE.graphicsId & OBJ_EVENT_MON)
        info.isFemale = FALSE;
    else
        info.isFemale = GetGenderFromSpeciesAndPersonality(info.speciesId, Random32()) == MON_FEMALE;

    if (templateOWE.movementType == MOVEMENT_TYPE_NONE)
        templateOWE.movementType = OWE_GetMovementTypeFromSpecies(info.speciesId);

    templateOWE.graphicsId = GetGraphicsIdForOWE(&info);
    templateOWE.sOverworldEncounterLevel = info.level;
    
    return templateOWE;
}

struct SpritePalette GetOWESpawnDespawnAnimFldEffPalette(enum SpawnDespawnTypeOWE spawnAnim)
{
    struct SpritePalette palette = gSpritePalette_GeneralFieldEffect0;
    switch (spawnAnim)
    {
    case OWE_SPAWN_ANIM_GRASS:
    case OWE_SPAWN_ANIM_LONG_GRASS:
        palette = gSpritePalette_GeneralFieldEffect1;
        break;

    case OWE_SPAWN_ANIM_WATER:
    case OWE_SPAWN_ANIM_UNDERWATER:
    case OWE_SPAWN_ANIM_CAVE:
    case OWE_SPAWN_ANIM_SHINY:
    default:
        break;
    }

    return palette;
}

static bool32 CheckValidOWESpecies(enum Species speciesId)
{
    if (speciesId == SPECIES_NONE)
        return FALSE;

    if (speciesId >= NUM_SPECIES)
        return FALSE;

    if (!IsSpeciesEnabled(speciesId))
        return FALSE;

    return TRUE;
}

bool32 CanRemoveObjectForOWEMovement(struct ObjectEvent *objectEvent)
{
    if (WE_OWE_PREVENT_SPECIAL_MOVEMENT_DESPAWN && IsObjectActiveOWE(objectEvent) && HasOWENoDespawnFlag(objectEvent))
        return FALSE;

    return TRUE;
}

#undef sOverworldEncounterLevel
#undef sOverworldEncounterAge
#undef sOverworldEncounterCategory
