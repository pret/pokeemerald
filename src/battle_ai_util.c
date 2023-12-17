#include "global.h"
#include "battle_z_move.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_ai_main.h"
#include "battle_ai_switch_items.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "event_data.h"
#include "data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"
#include "constants/items.h"

#define CHECK_MOVE_FLAG(flag)                                                                                   \
    s32 i;                                                                                                      \
    u16 *moves = GetMovesArray(battler);                                                                        \
    for (i = 0; i < MAX_MON_MOVES; i++)                                                                         \
    {                                                                                                           \
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && gBattleMoves[moves[i]].flag)               \
            return TRUE;                                                                                        \
    }                                                                                                           \
    return FALSE

static u32 AI_GetEffectiveness(uq4_12_t multiplier);

// Const Data
static const s8 sAiAbilityRatings[ABILITIES_COUNT] =
{
    [ABILITY_ADAPTABILITY] = 8,
    [ABILITY_AFTERMATH] = 5,
    [ABILITY_AERILATE] = 8,
    [ABILITY_AIR_LOCK] = 5,
    [ABILITY_ANALYTIC] = 5,
    [ABILITY_ANGER_POINT] = 4,
    [ABILITY_ANTICIPATION] = 2,
    [ABILITY_ARENA_TRAP] = 9,
    [ABILITY_AROMA_VEIL] = 3,
    [ABILITY_AURA_BREAK] = 3,
    [ABILITY_BAD_DREAMS] = 4,
    [ABILITY_BATTERY] = 0,
    [ABILITY_BATTLE_ARMOR] = 2,
    [ABILITY_BATTLE_BOND] = 6,
    [ABILITY_BEAST_BOOST] = 7,
    [ABILITY_BERSERK] = 5,
    [ABILITY_BIG_PECKS] = 1,
    [ABILITY_BLAZE] = 5,
    [ABILITY_BULLETPROOF] = 7,
    [ABILITY_CHEEK_POUCH] = 4,
    [ABILITY_CHLOROPHYLL] = 6,
    [ABILITY_CLEAR_BODY] = 4,
    [ABILITY_CLOUD_NINE] = 5,
    [ABILITY_COLOR_CHANGE] = 2,
    [ABILITY_COMATOSE] = 6,
    [ABILITY_COMPETITIVE] = 5,
    [ABILITY_COMPOUND_EYES] = 7,
    [ABILITY_CONTRARY] = 8,
    [ABILITY_CORROSION] = 5,
    [ABILITY_CURSED_BODY] = 4,
    [ABILITY_CUTE_CHARM] = 2,
    [ABILITY_DAMP] = 2,
    [ABILITY_DANCER] = 5,
    [ABILITY_DARK_AURA] = 6,
    [ABILITY_DAZZLING] = 5,
    [ABILITY_DEFEATIST] = -1,
    [ABILITY_DEFIANT] = 5,
    [ABILITY_DELTA_STREAM] = 10,
    [ABILITY_DESOLATE_LAND] = 10,
    [ABILITY_DISGUISE] = 8,
    [ABILITY_DOWNLOAD] = 7,
    [ABILITY_DRIZZLE] = 9,
    [ABILITY_DROUGHT] = 9,
    [ABILITY_DRY_SKIN] = 6,
    [ABILITY_EARLY_BIRD] = 4,
    [ABILITY_EFFECT_SPORE] = 4,
    [ABILITY_ELECTRIC_SURGE] = 8,
    [ABILITY_EMERGENCY_EXIT] = 3,
    [ABILITY_FAIRY_AURA] = 6,
    [ABILITY_FILTER] = 6,
    [ABILITY_FLAME_BODY] = 4,
    [ABILITY_FLARE_BOOST] = 5,
    [ABILITY_FLASH_FIRE] = 6,
    [ABILITY_FLOWER_GIFT] = 4,
    [ABILITY_FLOWER_VEIL] = 0,
    [ABILITY_FLUFFY] = 5,
    [ABILITY_FORECAST] = 6,
    [ABILITY_FOREWARN] = 2,
    [ABILITY_FRIEND_GUARD] = 0,
    [ABILITY_FRISK] = 3,
    [ABILITY_FULL_METAL_BODY] = 4,
    [ABILITY_FUR_COAT] = 7,
    [ABILITY_GALE_WINGS] = 6,
    [ABILITY_GALVANIZE] = 8,
    [ABILITY_GLUTTONY] = 3,
    [ABILITY_GOOEY] = 5,
    [ABILITY_GRASS_PELT] = 2,
    [ABILITY_GRASSY_SURGE] = 8,
    [ABILITY_GUTS] = 6,
    [ABILITY_HARVEST] = 5,
    [ABILITY_HEALER] = 0,
    [ABILITY_HEATPROOF] = 5,
    [ABILITY_HEAVY_METAL] = -1,
    [ABILITY_HONEY_GATHER] = 0,
    [ABILITY_HUGE_POWER] = 10,
    [ABILITY_HUSTLE] = 7,
    [ABILITY_HYDRATION] = 4,
    [ABILITY_HYPER_CUTTER] = 3,
    [ABILITY_ICE_BODY] = 3,
    [ABILITY_ILLUMINATE] = 0,
    [ABILITY_ILLUSION] = 8,
    [ABILITY_IMMUNITY] = 4,
    [ABILITY_IMPOSTER] = 9,
    [ABILITY_INFILTRATOR] = 6,
    [ABILITY_INNARDS_OUT] = 5,
    [ABILITY_INNER_FOCUS] = 2,
    [ABILITY_INSOMNIA] = 4,
    [ABILITY_INTIMIDATE] = 7,
    [ABILITY_IRON_BARBS] = 6,
    [ABILITY_IRON_FIST] = 6,
    [ABILITY_JUSTIFIED] = 4,
    [ABILITY_KEEN_EYE] = 1,
    [ABILITY_KLUTZ] = -1,
    [ABILITY_LEAF_GUARD] = 2,
    [ABILITY_LEVITATE] = 7,
    [ABILITY_LIGHT_METAL] = 2,
    [ABILITY_LIGHTNING_ROD] = 7,
    [ABILITY_LIMBER] = 3,
    [ABILITY_LIQUID_OOZE] = 3,
    [ABILITY_LIQUID_VOICE] = 5,
    [ABILITY_LONG_REACH] = 3,
    [ABILITY_MAGIC_BOUNCE] = 9,
    [ABILITY_MAGIC_GUARD] = 9,
    [ABILITY_MAGICIAN] = 3,
    [ABILITY_MAGMA_ARMOR] = 1,
    [ABILITY_MAGNET_PULL] = 9,
    [ABILITY_MARVEL_SCALE] = 5,
    [ABILITY_MEGA_LAUNCHER] = 7,
    [ABILITY_MERCILESS] = 4,
    [ABILITY_MINUS] = 0,
    [ABILITY_MISTY_SURGE] = 8,
    [ABILITY_MOLD_BREAKER] = 7,
    [ABILITY_MOODY] = 10,
    [ABILITY_MOTOR_DRIVE] = 6,
    [ABILITY_MOXIE] = 7,
    [ABILITY_MULTISCALE] = 8,
    [ABILITY_MULTITYPE] = 8,
    [ABILITY_MUMMY] = 5,
    [ABILITY_NATURAL_CURE] = 7,
    [ABILITY_NEUROFORCE] = 6,
    [ABILITY_NO_GUARD] = 8,
    [ABILITY_NORMALIZE] = -1,
    [ABILITY_OBLIVIOUS] = 2,
    [ABILITY_OVERCOAT] = 5,
    [ABILITY_OVERGROW] = 5,
    [ABILITY_OWN_TEMPO] = 3,
    [ABILITY_PARENTAL_BOND] = 10,
    [ABILITY_PICKUP] = 1,
    [ABILITY_PICKPOCKET] = 3,
    [ABILITY_PIXILATE] = 8,
    [ABILITY_PLUS] = 0,
    [ABILITY_POISON_HEAL] = 8,
    [ABILITY_POISON_POINT] = 4,
    [ABILITY_POISON_TOUCH] = 4,
    [ABILITY_POWER_CONSTRUCT] = 10,
    [ABILITY_POWER_OF_ALCHEMY] = 0,
    [ABILITY_PRANKSTER] = 8,
    [ABILITY_PRESSURE] = 5,
    [ABILITY_PRIMORDIAL_SEA] = 10,
    [ABILITY_PRISM_ARMOR] = 6,
    [ABILITY_PROTEAN] = 8,
    [ABILITY_PSYCHIC_SURGE] = 8,
    [ABILITY_PURE_POWER] = 10,
    [ABILITY_QUEENLY_MAJESTY] = 6,
    [ABILITY_QUICK_FEET] = 5,
    [ABILITY_RAIN_DISH] = 3,
    [ABILITY_RATTLED] = 3,
    [ABILITY_RECEIVER] = 0,
    [ABILITY_RECKLESS] = 6,
    [ABILITY_REFRIGERATE] = 8,
    [ABILITY_REGENERATOR] = 8,
    [ABILITY_RIVALRY] = 1,
    [ABILITY_RKS_SYSTEM] = 8,
    [ABILITY_ROCK_HEAD] = 5,
    [ABILITY_ROUGH_SKIN] = 6,
    [ABILITY_RUN_AWAY] = 0,
    [ABILITY_SAND_FORCE] = 4,
    [ABILITY_SAND_RUSH] = 6,
    [ABILITY_SAND_STREAM] = 9,
    [ABILITY_SAND_VEIL] = 3,
    [ABILITY_SAP_SIPPER] = 7,
    [ABILITY_SCHOOLING] = 6,
    [ABILITY_SCRAPPY] = 6,
    [ABILITY_SERENE_GRACE] = 8,
    [ABILITY_SHADOW_SHIELD] = 8,
    [ABILITY_SHADOW_TAG] = 10,
    [ABILITY_SHED_SKIN] = 7,
    [ABILITY_SHEER_FORCE] = 8,
    [ABILITY_SHELL_ARMOR] = 2,
    [ABILITY_SHIELD_DUST] = 5,
    [ABILITY_SHIELDS_DOWN] = 6,
    [ABILITY_SIMPLE] = 8,
    [ABILITY_SKILL_LINK] = 7,
    [ABILITY_SLOW_START] = -2,
    [ABILITY_SLUSH_RUSH] = 5,
    [ABILITY_SNIPER] = 3,
    [ABILITY_SNOW_CLOAK] = 3,
    [ABILITY_SNOW_WARNING] = 8,
    [ABILITY_SOLAR_POWER] = 3,
    [ABILITY_SOLID_ROCK] = 6,
    [ABILITY_SOUL_HEART] = 7,
    [ABILITY_SOUNDPROOF] = 4,
    [ABILITY_SPEED_BOOST] = 9,
    [ABILITY_STAKEOUT] = 6,
    [ABILITY_STALL] = -1,
    [ABILITY_STAMINA] = 6,
    [ABILITY_STANCE_CHANGE] = 10,
    [ABILITY_STATIC] = 4,
    [ABILITY_STEADFAST] = 2,
    [ABILITY_STEELWORKER] = 6,
    [ABILITY_STENCH] = 1,
    [ABILITY_STICKY_HOLD] = 3,
    [ABILITY_STORM_DRAIN] = 7,
    [ABILITY_STRONG_JAW] = 6,
    [ABILITY_STURDY] = 6,
    [ABILITY_SUCTION_CUPS] = 2,
    [ABILITY_SUPER_LUCK] = 3,
    [ABILITY_SURGE_SURFER] = 4,
    [ABILITY_SWARM] = 5,
    [ABILITY_SWEET_VEIL] = 4,
    [ABILITY_SWIFT_SWIM] = 6,
    [ABILITY_SYMBIOSIS] = 0,
    [ABILITY_SYNCHRONIZE] = 4,
    [ABILITY_TANGLED_FEET] = 2,
    [ABILITY_TANGLING_HAIR] = 5,
    [ABILITY_TECHNICIAN] = 8,
    [ABILITY_TELEPATHY] = 0,
    [ABILITY_TERAVOLT] = 7,
    [ABILITY_THICK_FAT] = 7,
    [ABILITY_TINTED_LENS] = 7,
    [ABILITY_TORRENT] = 5,
    [ABILITY_TOXIC_BOOST] = 6,
    [ABILITY_TOUGH_CLAWS] = 7,
    [ABILITY_TRACE] = 6,
    [ABILITY_TRIAGE] = 7,
    [ABILITY_TRUANT] = -2,
    [ABILITY_TURBOBLAZE] = 7,
    [ABILITY_UNAWARE] = 6,
    [ABILITY_UNBURDEN] = 7,
    [ABILITY_UNNERVE] = 3,
    [ABILITY_VICTORY_STAR] = 6,
    [ABILITY_VITAL_SPIRIT] = 4,
    [ABILITY_VOLT_ABSORB] = 7,
    [ABILITY_WATER_ABSORB] = 7,
    [ABILITY_WATER_BUBBLE] = 8,
    [ABILITY_WATER_COMPACTION] = 4,
    [ABILITY_WATER_VEIL] = 4,
    [ABILITY_WEAK_ARMOR] = 2,
    [ABILITY_WHITE_SMOKE] = 4,
    [ABILITY_WIMP_OUT] = 3,
    [ABILITY_WONDER_GUARD] = 10,
    [ABILITY_WONDER_SKIN] = 4,
    [ABILITY_ZEN_MODE] = -1,
    [ABILITY_INTREPID_SWORD] = 3,
    [ABILITY_DAUNTLESS_SHIELD] = 3,
    [ABILITY_BALL_FETCH] = 0,
    [ABILITY_COTTON_DOWN] = 3,
    [ABILITY_MIRROR_ARMOR] = 6,
    [ABILITY_GULP_MISSILE] = 3,
    [ABILITY_STALWART] = 2,
    [ABILITY_PROPELLER_TAIL] = 2,
    [ABILITY_STEAM_ENGINE] = 3,
    [ABILITY_PUNK_ROCK] = 2,
    [ABILITY_SAND_SPIT] = 5,
    [ABILITY_ICE_SCALES] = 7,
    [ABILITY_RIPEN] = 4,
    [ABILITY_ICE_FACE] = 4,
    [ABILITY_POWER_SPOT] = 2,
    [ABILITY_MIMICRY] = 2,
    [ABILITY_SCREEN_CLEANER] = 3,
    [ABILITY_NEUTRALIZING_GAS] = 5,
    [ABILITY_HUNGER_SWITCH] = 2,
    [ABILITY_PASTEL_VEIL] = 4,
    [ABILITY_STEELY_SPIRIT] = 2,
    [ABILITY_PERISH_BODY] = -1,
    [ABILITY_WANDERING_SPIRIT] = 2,
    [ABILITY_GORILLA_TACTICS] = 4,
};

static const u16 sEncouragedEncoreEffects[] =
{
    EFFECT_DREAM_EATER,
    EFFECT_ATTACK_UP,
    EFFECT_DEFENSE_UP,
    EFFECT_SPEED_UP,
    EFFECT_SPECIAL_ATTACK_UP,
    EFFECT_HAZE,
    EFFECT_ROAR,
    EFFECT_CONVERSION,
    EFFECT_TOXIC,
    EFFECT_LIGHT_SCREEN,
    EFFECT_REST,
    EFFECT_SUPER_FANG,
    EFFECT_SPECIAL_DEFENSE_UP_2,
    EFFECT_CONFUSE,
    EFFECT_POISON,
    EFFECT_PARALYZE,
    EFFECT_LEECH_SEED,
    EFFECT_DO_NOTHING,
    EFFECT_ATTACK_UP_2,
    EFFECT_ENCORE,
    EFFECT_CONVERSION_2,
    EFFECT_LOCK_ON,
    EFFECT_HEAL_BELL,
    EFFECT_MEAN_LOOK,
    EFFECT_NIGHTMARE,
    EFFECT_PROTECT,
    EFFECT_SKILL_SWAP,
    EFFECT_FORESIGHT,
    EFFECT_PERISH_SONG,
    EFFECT_SANDSTORM,
    EFFECT_ENDURE,
    EFFECT_SWAGGER,
    EFFECT_ATTRACT,
    EFFECT_SAFEGUARD,
    EFFECT_RAIN_DANCE,
    EFFECT_SUNNY_DAY,
    EFFECT_BELLY_DRUM,
    EFFECT_PSYCH_UP,
    EFFECT_FUTURE_SIGHT,
    EFFECT_FAKE_OUT,
    EFFECT_STOCKPILE,
    EFFECT_SPIT_UP,
    EFFECT_SWALLOW,
    EFFECT_HAIL,
    EFFECT_SNOWSCAPE,
    EFFECT_TORMENT,
    EFFECT_WILL_O_WISP,
    EFFECT_FOLLOW_ME,
    EFFECT_CHARGE,
    EFFECT_TRICK,
    EFFECT_ROLE_PLAY,
    EFFECT_INGRAIN,
    EFFECT_RECYCLE,
    EFFECT_KNOCK_OFF,
    EFFECT_SKILL_SWAP,
    EFFECT_IMPRISON,
    EFFECT_REFRESH,
    EFFECT_GRUDGE,
    EFFECT_TEETER_DANCE,
    EFFECT_MUD_SPORT,
    EFFECT_WATER_SPORT,
    EFFECT_DRAGON_DANCE,
    EFFECT_CAMOUFLAGE,
};

// Functions
u32 GetAIChosenMove(u32 battlerId)
{
    return (gBattleMons[battlerId].moves[gBattleStruct->aiMoveOrAction[battlerId]]);
}

bool32 AI_RandLessThan(u32 val)
{
    if ((Random() % 0xFF) < val)
        return TRUE;
    return FALSE;
}

bool32 IsAiVsAiBattle(void)
{
    return (B_FLAG_AI_VS_AI_BATTLE && FlagGet(B_FLAG_AI_VS_AI_BATTLE));
}

bool32 BattlerHasAi(u32 battlerId)
{
    switch (GetBattlerPosition(battlerId))
    {
    case B_POSITION_PLAYER_LEFT:
        if (IsAiVsAiBattle())
            return TRUE;
    default:
        return FALSE;
    case B_POSITION_OPPONENT_LEFT:
        return TRUE;
    case B_POSITION_PLAYER_RIGHT:
        if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) || IsAiVsAiBattle())
            return TRUE;
        else
            return FALSE;
    case B_POSITION_OPPONENT_RIGHT:
        return TRUE;
    }
}

bool32 IsAiBattlerAware(u32 battlerId)
{
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_OMNISCIENT)
        return TRUE;

    return BattlerHasAi(battlerId);
}

void ClearBattlerMoveHistory(u32 battlerId)
{
    memset(BATTLE_HISTORY->usedMoves[battlerId], 0, sizeof(BATTLE_HISTORY->usedMoves[battlerId]));
    memset(BATTLE_HISTORY->moveHistory[battlerId], 0, sizeof(BATTLE_HISTORY->moveHistory[battlerId]));
    BATTLE_HISTORY->moveHistoryIndex[battlerId] = 0;
}

void RecordLastUsedMoveBy(u32 battlerId, u32 move)
{
    u8 *index = &BATTLE_HISTORY->moveHistoryIndex[battlerId];

    if (++(*index) >= AI_MOVE_HISTORY_COUNT)
        *index = 0;
    BATTLE_HISTORY->moveHistory[battlerId][*index] = move;
}

void RecordKnownMove(u32 battlerId, u32 move)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (BATTLE_HISTORY->usedMoves[battlerId][i] == move)
            break;
        if (BATTLE_HISTORY->usedMoves[battlerId][i] == MOVE_NONE)
        {
            BATTLE_HISTORY->usedMoves[battlerId][i] = move;
            AI_PARTY->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].moves[i] = move;
            break;
        }
    }
}

void RecordAllMoves(u32 battler)
{
    memcpy(AI_PARTY->mons[GetBattlerSide(battler)][gBattlerPartyIndexes[battler]].moves, gBattleMons[battler].moves, MAX_MON_MOVES * sizeof(u16));
}

void RecordAbilityBattle(u32 battlerId, u32 abilityId)
{
    BATTLE_HISTORY->abilities[battlerId] = abilityId;
    AI_PARTY->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].ability = abilityId;
}

void ClearBattlerAbilityHistory(u32 battlerId)
{
    BATTLE_HISTORY->abilities[battlerId] = ABILITY_NONE;
}

void RecordItemEffectBattle(u32 battlerId, u32 itemEffect)
{
    BATTLE_HISTORY->itemEffects[battlerId] = itemEffect;
    AI_PARTY->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].heldEffect = itemEffect;
}

void ClearBattlerItemEffectHistory(u32 battlerId)
{
    BATTLE_HISTORY->itemEffects[battlerId] = 0;
}

void SaveBattlerData(u32 battlerId)
{
    if (!BattlerHasAi(battlerId))
    {
        u32 i;

        AI_THINKING_STRUCT->saved[battlerId].ability = gBattleMons[battlerId].ability;
        AI_THINKING_STRUCT->saved[battlerId].heldItem = gBattleMons[battlerId].item;
        AI_THINKING_STRUCT->saved[battlerId].species = gBattleMons[battlerId].species;
        for (i = 0; i < 4; i++)
            AI_THINKING_STRUCT->saved[battlerId].moves[i] = gBattleMons[battlerId].moves[i];
    }
    // Save and restore types even for AI controlled battlers in case it gets changed during move evaluation process.
    AI_THINKING_STRUCT->saved[battlerId].types[0] = gBattleMons[battlerId].type1;
    AI_THINKING_STRUCT->saved[battlerId].types[1] = gBattleMons[battlerId].type2;
}

static bool32 ShouldFailForIllusion(u32 illusionSpecies, u32 battlerId)
{
    u32 i, j;
    const struct LevelUpMove *learnset;

    if (BATTLE_HISTORY->abilities[battlerId] == ABILITY_ILLUSION)
        return FALSE;

    // Don't fall for Illusion if the mon used a move it cannot know.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 move = BATTLE_HISTORY->usedMoves[battlerId][i];
        if (move == MOVE_NONE)
            continue;

        learnset = GetSpeciesLevelUpLearnset(illusionSpecies);
        for (j = 0; learnset[j].move != MOVE_UNAVAILABLE; j++)
        {
            if (learnset[j].move == move)
                break;
        }
        // The used move is in the learnsets of the fake species.
        if (learnset[j].move != MOVE_UNAVAILABLE)
            continue;

        // The used move can be learned from Tm/Hm or Move Tutors.
        if (CanLearnTeachableMove(illusionSpecies, move))
            continue;

        // 'Illegal move', AI won't fail for the illusion.
        return FALSE;
    }

    return TRUE;
}

void SetBattlerData(u32 battlerId)
{
    if (!BattlerHasAi(battlerId))
    {
        u32 i, species, illusionSpecies, side;
        side = GetBattlerSide(battlerId);

        // Simulate Illusion
        species = gBattleMons[battlerId].species;
        illusionSpecies = GetIllusionMonSpecies(battlerId);
        if (illusionSpecies != SPECIES_NONE && ShouldFailForIllusion(illusionSpecies, battlerId))
        {
            // If the battler's type has not been changed, AI assumes the types of the illusion mon.
            if (gBattleMons[battlerId].type1 == gSpeciesInfo[species].types[0]
                && gBattleMons[battlerId].type2 == gSpeciesInfo[species].types[1])
            {
                gBattleMons[battlerId].type1 = gSpeciesInfo[illusionSpecies].types[0];
                gBattleMons[battlerId].type2 = gSpeciesInfo[illusionSpecies].types[1];
            }
            species = illusionSpecies;
        }

        // Use the known battler's ability.
        if (AI_PARTY->mons[side][gBattlerPartyIndexes[battlerId]].ability != ABILITY_NONE)
            gBattleMons[battlerId].ability = AI_PARTY->mons[side][gBattlerPartyIndexes[battlerId]].ability;
        // Check if mon can only have one ability.
        else if (gSpeciesInfo[species].abilities[1] == ABILITY_NONE
                || gSpeciesInfo[species].abilities[1] == gSpeciesInfo[species].abilities[0])
            gBattleMons[battlerId].ability = gSpeciesInfo[species].abilities[0];
        // The ability is unknown.
        else
            gBattleMons[battlerId].ability = ABILITY_NONE;

        if (AI_PARTY->mons[side][gBattlerPartyIndexes[battlerId]].heldEffect == 0)
            gBattleMons[battlerId].item = 0;

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (AI_PARTY->mons[side][gBattlerPartyIndexes[battlerId]].moves[i] == 0)
                gBattleMons[battlerId].moves[i] = 0;
        }
    }
}

void RestoreBattlerData(u32 battlerId)
{
    if (!BattlerHasAi(battlerId))
    {
        u32 i;

        gBattleMons[battlerId].ability = AI_THINKING_STRUCT->saved[battlerId].ability;
        gBattleMons[battlerId].item = AI_THINKING_STRUCT->saved[battlerId].heldItem;
        gBattleMons[battlerId].species = AI_THINKING_STRUCT->saved[battlerId].species;
        for (i = 0; i < 4; i++)
            gBattleMons[battlerId].moves[i] = AI_THINKING_STRUCT->saved[battlerId].moves[i];
    }
    gBattleMons[battlerId].type1 = AI_THINKING_STRUCT->saved[battlerId].types[0];
    gBattleMons[battlerId].type2 = AI_THINKING_STRUCT->saved[battlerId].types[1];
}

u32 GetHealthPercentage(u32 battlerId)
{
    return (u32)((100 * gBattleMons[battlerId].hp) / gBattleMons[battlerId].maxHP);
}

bool32 AtMaxHp(u32 battlerId)
{
    if (AI_DATA->hpPercents[battlerId] == 100)
        return TRUE;
    return FALSE;
}

bool32 IsBattlerTrapped(u32 battler, bool32 checkSwitch)
{
    u32 holdEffect = AI_DATA->holdEffects[battler];

    if (B_GHOSTS_ESCAPE >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GHOST))
        return FALSE;
    if (checkSwitch && holdEffect == HOLD_EFFECT_SHED_SHELL)
        return FALSE;
    else if (!checkSwitch && GetBattlerAbility(battler) == ABILITY_RUN_AWAY)
        return FALSE;
    else if (!checkSwitch && holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN)
        return FALSE;
    else if (gBattleMons[battler].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED))
        return TRUE;
    else if (gStatuses3[battler] & (STATUS3_ROOTED | STATUS3_SKY_DROPPED))
        return TRUE;
    else if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        return TRUE;
    else if (IsAbilityPreventingEscape(battler))
        return TRUE;

    return FALSE;
}

u32 GetTotalBaseStat(u32 species)
{
    return gSpeciesInfo[species].baseHP
        + gSpeciesInfo[species].baseAttack
        + gSpeciesInfo[species].baseDefense
        + gSpeciesInfo[species].baseSpeed
        + gSpeciesInfo[species].baseSpAttack
        + gSpeciesInfo[species].baseSpDefense;
}

bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler)
{
    int i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 move = gBattleResources->battleHistory->usedMoves[opposingBattler][i];
        if (gBattleMoves[move].effect == EFFECT_PROTECT && move != MOVE_ENDURE)
            return TRUE;
        if (gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE && AI_WhoStrikesFirst(battlerAI, opposingBattler, GetAIChosenMove(battlerAI)) == AI_IS_SLOWER)
            return TRUE;
    }
    return FALSE;
}

// move checks
bool32 IsAffectedByPowder(u32 battler, u32 ability, u32 holdEffect)
{
    if (ability == ABILITY_OVERCOAT
        || (B_POWDER_GRASS >= GEN_6 && IS_BATTLER_OF_TYPE(battler, TYPE_GRASS))
        || holdEffect == HOLD_EFFECT_SAFETY_GOGGLES)
        return FALSE;
    return TRUE;
}

// This function checks if all physical/special moves are either unusable or unreasonable to use.
// Consider a pokemon boosting their attack against a ghost pokemon having only normal-type physical attacks.
bool32 MovesWithSplitUnusable(u32 attacker, u32 target, u32 split)
{
    s32 i, moveType;
    u32 usable = 0;
    u32 unusable = AI_DATA->moveLimitations[attacker];
    u16 *moves = GetMovesArray(attacker);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE
            && moves[i] != MOVE_UNAVAILABLE
            && GetBattleMoveSplit(moves[i]) == split
            && !(unusable & gBitTable[i]))
        {
            SetTypeBeforeUsingMove(moves[i], attacker);
            GET_MOVE_TYPE(moves[i], moveType);
            if (CalcTypeEffectivenessMultiplier(moves[i], moveType, attacker, target, AI_DATA->abilities[target], FALSE) != 0)
                usable |= gBitTable[i];
        }
    }

    return (usable == 0);
}

// To save computation time this function has 2 variants. One saves, sets and restores battlers, while the other doesn't.
s32 AI_CalcDamageSaveBattlers(u32 move, u32 battlerAtk, u32 battlerDef, u8 *typeEffectiveness, bool32 considerZPower)
{
    SaveBattlerData(battlerAtk);
    SaveBattlerData(battlerDef);
    return AI_CalcDamage(move, battlerAtk, battlerDef, typeEffectiveness, considerZPower, AI_GetWeather(AI_DATA));
}

static inline s32 LowestRollDmg(s32 dmg)
{
    dmg *= 100 - 15;
    dmg /= 100;
    return dmg;
}

s32 AI_CalcDamage(u32 move, u32 battlerAtk, u32 battlerDef, u8 *typeEffectiveness, bool32 considerZPower, u32 weather)
{
    s32 dmg, moveType;
    uq4_12_t effectivenessMultiplier;
    struct AiLogicData *aiData = AI_DATA;

    SetBattlerData(battlerAtk);
    SetBattlerData(battlerDef);

    if (considerZPower && IsViableZMove(battlerAtk, move))
    {
        //temporarily enable z moves for damage calcs
        gBattleStruct->zmove.baseMoves[battlerAtk] = move;
        gBattleStruct->zmove.active = TRUE;
    }

    gBattleStruct->dynamicMoveType = 0;

    if (move == MOVE_NATURE_POWER)
        move = GetNaturePowerMove();

    SetTypeBeforeUsingMove(move, battlerAtk);
    GET_MOVE_TYPE(move, moveType);

    effectivenessMultiplier = CalcTypeEffectivenessMultiplier(move, moveType, battlerAtk, battlerDef, aiData->abilities[battlerDef], FALSE);
    if (gBattleMoves[move].power)
    {
        s32 critChanceIndex, normalDmg, fixedBasePower, n;

        ProteanTryChangeType(battlerAtk, aiData->abilities[battlerAtk], move, moveType);
        // Certain moves like Rollout calculate damage based on values which change during the move execution, but before calling dmg calc.
        switch (gBattleMoves[move].effect)
        {
        case EFFECT_ROLLOUT:
            n = gDisableStructs[battlerAtk].rolloutTimer - 1;
            fixedBasePower = CalcRolloutBasePower(battlerAtk, gBattleMoves[move].power, n < 0 ? 5 : n);
            break;
        case EFFECT_FURY_CUTTER:
            fixedBasePower = CalcFuryCutterBasePower(gBattleMoves[move].power, min(gDisableStructs[battlerAtk].furyCutterCounter + 1, 5));
            break;
        default:
            fixedBasePower = 0;
            break;
        }
        normalDmg = CalculateMoveDamageVars(move, battlerAtk, battlerDef, moveType, fixedBasePower,
                                             effectivenessMultiplier, weather, FALSE,
                                             aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef],
                                             aiData->abilities[battlerAtk], aiData->abilities[battlerDef]);

        critChanceIndex = CalcCritChanceStageArgs(battlerAtk, battlerDef, move, FALSE, aiData->abilities[battlerAtk], aiData->abilities[battlerDef], aiData->holdEffects[battlerAtk]);
        if (critChanceIndex > 1) // Consider crit damage only if a move has at least +1 crit chance
        {
            s32 critDmg = CalculateMoveDamageVars(move, battlerAtk, battlerDef, moveType, fixedBasePower,
                                             effectivenessMultiplier, weather, TRUE,
                                             aiData->holdEffects[battlerAtk], aiData->holdEffects[battlerDef],
                                             aiData->abilities[battlerAtk], aiData->abilities[battlerDef]);
            u32 critChance = GetCritHitChance(critChanceIndex);
            // With critChance getting closer to 1, dmg gets closer to critDmg.
            dmg = LowestRollDmg((critDmg + normalDmg * (critChance - 1)) / (critChance));
        }
        else
        {
            dmg = LowestRollDmg(normalDmg);
        }

        if (!gBattleStruct->zmove.active)
        {
            // Handle dynamic move damage
            switch (gBattleMoves[move].effect)
            {
            case EFFECT_LEVEL_DAMAGE:
            case EFFECT_PSYWAVE:
                dmg = gBattleMons[battlerAtk].level * (aiData->abilities[battlerAtk] == ABILITY_PARENTAL_BOND ? 2 : 1);
                break;
            case EFFECT_DRAGON_RAGE:
                dmg = 40 * (aiData->abilities[battlerAtk] == ABILITY_PARENTAL_BOND ? 2 : 1);
                break;
            case EFFECT_SONICBOOM:
                dmg = 20 * (aiData->abilities[battlerAtk] == ABILITY_PARENTAL_BOND ? 2 : 1);
                break;
            case EFFECT_MULTI_HIT:
                dmg *= (aiData->abilities[battlerAtk] == ABILITY_SKILL_LINK ? 5 : 3);
                break;
            case EFFECT_ENDEAVOR:
                // If target has less HP than user, Endeavor does no damage
                dmg = max(0, gBattleMons[battlerDef].hp - gBattleMons[battlerAtk].hp);
                break;
            case EFFECT_SUPER_FANG:
                dmg = (aiData->abilities[battlerAtk] == ABILITY_PARENTAL_BOND
                    ? max(2, gBattleMons[battlerDef].hp * 3 / 4)
                    : max(1, gBattleMons[battlerDef].hp / 2));
                break;
            case EFFECT_FINAL_GAMBIT:
                dmg = gBattleMons[battlerAtk].hp;
                break;
            case EFFECT_BEAT_UP:
                if (B_BEAT_UP >= GEN_5)
                {
                    u32 partyCount = CalculatePartyCount(GetBattlerParty(battlerAtk));
                    u32 i;
                    gBattleStruct->beatUpSlot = 0;
                    dmg = 0;
                    for (i = 0; i < partyCount; i++) {
                        dmg += CalculateMoveDamage(move, battlerAtk, battlerDef, moveType, 0, FALSE, FALSE, FALSE);
                    }
                    gBattleStruct->beatUpSlot = 0;
                }
                break;
            }

            // Handle other multi-strike moves
            if (gBattleMoves[move].strikeCount > 1 && gBattleMoves[move].effect != EFFECT_TRIPLE_KICK)
                dmg *= gBattleMoves[move].strikeCount;
            else if (move == MOVE_WATER_SHURIKEN && gBattleMons[battlerAtk].species == SPECIES_GRENINJA_ASH)
                dmg *= 3;

            if (dmg == 0)
                dmg = 1;
        }
    }
    else
    {
        dmg = 0;
    }

    RestoreBattlerData(battlerAtk);
    RestoreBattlerData(battlerDef);

    // convert multiper to AI_EFFECTIVENESS_xX
    *typeEffectiveness = AI_GetEffectiveness(effectivenessMultiplier);

    gBattleStruct->zmove.active = FALSE;
    gBattleStruct->zmove.baseMoves[battlerAtk] = MOVE_NONE;
    return dmg;
}

bool32 AI_IsDamagedByRecoil(u32 battler)
{
    u32 ability = AI_DATA->abilities[battler];
    if (ability == ABILITY_MAGIC_GUARD || ability == ABILITY_ROCK_HEAD)
        return FALSE;
    return TRUE;
}

// Decide whether move having an additional effect for .
static bool32 AI_IsMoveEffectInPlus(u32 battlerAtk, u32 battlerDef, u32 move, s32 noOfHitsToKo)
{
    u32 i;
    u32 abilityDef = AI_DATA->abilities[battlerDef];
    u32 abilityAtk = AI_DATA->abilities[battlerAtk];

    switch (gBattleMoves[move].effect)
    {
    case EFFECT_HIT:
    default:
        return FALSE;
    case EFFECT_PARALYZE_HIT:
        if (AI_CanParalyze(battlerAtk, battlerDef, abilityDef, move, MOVE_NONE))
            return TRUE;
        break;
    case EFFECT_BURN_HIT:
        if (AI_CanBurn(battlerAtk, battlerDef, abilityDef, BATTLE_PARTNER(battlerAtk), move, MOVE_NONE))
            return TRUE;
        break;
    case EFFECT_POISON_HIT:
    case EFFECT_POISON_FANG:
        if (AI_CanPoison(battlerAtk, battlerDef, abilityDef, move, MOVE_NONE))
            return TRUE;
        break;
    case EFFECT_FREEZE_HIT:
        if (AI_CanGetFrostbite(battlerDef, abilityDef))
            return TRUE;
        break;
    case EFFECT_CONFUSE_HIT:
        if (AI_CanConfuse(battlerAtk, battlerDef, abilityDef, BATTLE_PARTNER(battlerAtk), move, MOVE_NONE))
            return TRUE;
        break;
    case EFFECT_FLINCH_STATUS:
        switch (gBattleMoves[move].argument)
        {
        case STATUS1_PARALYSIS:
            if (AI_CanParalyze(battlerAtk, battlerDef, abilityDef, move, MOVE_NONE))
                return TRUE;
            break;
        case STATUS1_BURN:
            if (AI_CanBurn(battlerAtk, battlerDef, abilityDef, BATTLE_PARTNER(battlerAtk), move, MOVE_NONE))
                return TRUE;
            break;
        case STATUS1_FREEZE:
            if (AI_CanGetFrostbite(battlerDef, abilityDef))
                return TRUE;
            break;
        }
        // fallthrough
    case EFFECT_FLINCH_HIT:
        if (ShouldTryToFlinch(battlerAtk, battlerDef, abilityAtk, abilityDef, move))
            return TRUE;
        break;
    case EFFECT_HIT_ESCAPE:
        if (CountUsablePartyMons(battlerAtk) != 0 && ShouldPivot(battlerAtk, battlerDef, abilityDef, move, AI_THINKING_STRUCT->movesetIndex))
            return TRUE;
        break;
    case EFFECT_ATTACK_UP_HIT:
    case EFFECT_FELL_STINGER:
        if (BattlerStatCanRise(battlerAtk, abilityAtk, STAT_ATK))
            return TRUE;
        break;
    case EFFECT_DEFENSE_UP2_HIT:
    case EFFECT_DEFENSE_UP_HIT:
        if (BattlerStatCanRise(battlerAtk, abilityAtk, STAT_DEF))
            return TRUE;
        break;
    case EFFECT_SPEED_UP_HIT:
        if (BattlerStatCanRise(battlerAtk, abilityAtk, STAT_SPEED))
            return TRUE;
        break;
    case EFFECT_SPECIAL_ATTACK_UP_HIT:
        if (BattlerStatCanRise(battlerAtk, abilityAtk, STAT_SPATK))
            return TRUE;
        break;
    case EFFECT_ATTACK_DOWN_HIT:
        if (ShouldLowerStat(battlerDef, abilityDef, STAT_ATK) && abilityDef != ABILITY_HYPER_CUTTER && noOfHitsToKo != 1)
            return TRUE;
        break;
    case EFFECT_DEFENSE_DOWN_HIT:
        if (ShouldLowerStat(battlerDef, abilityDef, STAT_DEF) && noOfHitsToKo != 1)
            return TRUE;
        break;
    case EFFECT_SPEED_DOWN_HIT:
        if (ShouldLowerStat(battlerDef, abilityDef, STAT_SPEED) && noOfHitsToKo != 1)
            return TRUE;
        break;
    case EFFECT_SPECIAL_ATTACK_DOWN_HIT:
        if (ShouldLowerStat(battlerDef, abilityDef, STAT_SPATK) && noOfHitsToKo != 1)
            return TRUE;
        break;
    case EFFECT_SPECIAL_DEFENSE_DOWN_HIT:
    case EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2:
        if (ShouldLowerStat(battlerDef, abilityDef, STAT_SPDEF) && noOfHitsToKo != 1)
            return TRUE;
        break;
    case EFFECT_ACCURACY_DOWN_HIT:
        if (ShouldLowerStat(battlerDef, abilityDef, STAT_ACC) && noOfHitsToKo != 1)
            return TRUE;
        break;
    case EFFECT_EVASION_DOWN_HIT:
        if (ShouldLowerStat(battlerDef, abilityDef, STAT_EVASION) && noOfHitsToKo != 1)
            return TRUE;
        break;
    case EFFECT_ALL_STATS_UP_HIT:
        for (i = STAT_ATK; i <= NUM_STATS; i++)
        {
            if (BattlerStatCanRise(battlerAtk, abilityAtk, i))
                return TRUE;
        }
        break;
    }

    return FALSE;
}

static bool32 AI_IsMoveEffectInMinus(u32 battlerAtk, u32 battlerDef, u32 move, s32 noOfHitsToKo)
{
    u32 abilityAtk = AI_DATA->abilities[battlerAtk];
    u32 abilityDef = AI_DATA->abilities[battlerDef];

    switch (gBattleMoves[move].effect)
    {
    case EFFECT_RECHARGE:
    case EFFECT_SUPERPOWER:
    case EFFECT_OVERHEAT:
    case EFFECT_MAKE_IT_RAIN:
    case EFFECT_MIND_BLOWN:
    case EFFECT_STEEL_BEAM:
        return TRUE;
    case EFFECT_RECOIL_25:
    case EFFECT_RECOIL_IF_MISS:
    case EFFECT_RECOIL_50:
    case EFFECT_RECOIL_33:
    case EFFECT_RECOIL_33_STATUS:
        if (AI_IsDamagedByRecoil(battlerAtk))
            return TRUE;
        break;
    case EFFECT_SPEED_DOWN_HIT:
    case EFFECT_ATTACK_DOWN_HIT:
    case EFFECT_DEFENSE_DOWN_HIT:
    case EFFECT_SPECIAL_ATTACK_DOWN_HIT:
    case EFFECT_SPECIAL_DEFENSE_DOWN_HIT:
    case EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2:
        if (noOfHitsToKo != 1 && abilityDef == ABILITY_CONTRARY && !IsMoldBreakerTypeAbility(abilityAtk))
            return TRUE;
        break;
    }
    return FALSE;
}

// Checks if one of the moves has side effects or perks, assuming equal dmg or equal no of hits to KO
u32 AI_WhichMoveBetter(u32 move1, u32 move2, u32 battlerAtk, u32 battlerDef, s32 noOfHitsToKo)
{
    bool32 effect1, effect2;
    s32 defAbility = AI_DATA->abilities[battlerDef];

    // Check if physical moves hurt.
    if (AI_DATA->holdEffects[battlerAtk] != HOLD_EFFECT_PROTECTIVE_PADS
        && (AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_ROCKY_HELMET
        || defAbility == ABILITY_IRON_BARBS || defAbility == ABILITY_ROUGH_SKIN))
    {
        if (IS_MOVE_PHYSICAL(move1) && !IS_MOVE_PHYSICAL(move2))
            return 1;
        if (IS_MOVE_PHYSICAL(move2) && !IS_MOVE_PHYSICAL(move1))
            return 0;
    }

    // Check additional effects.
    effect1 = AI_IsMoveEffectInMinus(battlerAtk, battlerDef, move1, noOfHitsToKo);
    effect2 = AI_IsMoveEffectInMinus(battlerAtk, battlerDef, move2, noOfHitsToKo);
    if (effect2 && !effect1)
        return 0;
    if (effect1 && !effect2)
        return 1;

    effect1 = AI_IsMoveEffectInPlus(battlerAtk, battlerDef, move1, noOfHitsToKo);
    effect2 = AI_IsMoveEffectInPlus(battlerAtk, battlerDef, move2, noOfHitsToKo);
    if (effect2 && !effect1)
        return 1;
    if (effect1 && !effect2)
        return 0;

    return 2;
}

u32 GetNoOfHitsToKO(u32 dmg, s32 hp)
{
    if (dmg == 0)
        return 0;
    return hp / (dmg + 1) + 1;
}

u32 GetNoOfHitsToKOBattlerDmg(u32 dmg, u32 battlerDef)
{
    return GetNoOfHitsToKO(dmg, gBattleMons[battlerDef].hp);
}

u32 GetNoOfHitsToKOBattler(u32 battlerAtk, u32 battlerDef, u32 moveIndex)
{
    return GetNoOfHitsToKOBattlerDmg(AI_DATA->simulatedDmg[battlerAtk][battlerDef][moveIndex], battlerDef);
}

u32 GetCurrDamageHpPercent(u32 battlerAtk, u32 battlerDef)
{
    int bestDmg = AI_DATA->simulatedDmg[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex];

    return (bestDmg * 100) / gBattleMons[battlerDef].maxHP;
}

uq4_12_t AI_GetTypeEffectiveness(u32 move, u32 battlerAtk, u32 battlerDef)
{
    uq4_12_t typeEffectiveness;
    u32 moveType;

    SaveBattlerData(battlerAtk);
    SaveBattlerData(battlerDef);

    SetBattlerData(battlerAtk);
    SetBattlerData(battlerDef);

    gBattleStruct->dynamicMoveType = 0;
    SetTypeBeforeUsingMove(move, battlerAtk);
    GET_MOVE_TYPE(move, moveType);
    typeEffectiveness = CalcTypeEffectivenessMultiplier(move, moveType, battlerAtk, battlerDef, AI_DATA->abilities[battlerDef], FALSE);

    RestoreBattlerData(battlerAtk);
    RestoreBattlerData(battlerDef);

    return typeEffectiveness;
}

u32 AI_GetMoveEffectiveness(u32 move, u32 battlerAtk, u32 battlerDef)
{
    gMoveResultFlags = 0;
    return AI_GetEffectiveness(AI_GetTypeEffectiveness(move, battlerAtk, battlerDef));
}

static u32 AI_GetEffectiveness(uq4_12_t multiplier)
{
    switch (multiplier)
    {
    case UQ_4_12(0.0):
        return AI_EFFECTIVENESS_x0;
    case UQ_4_12(0.125):
        return AI_EFFECTIVENESS_x0_125;
    case UQ_4_12(0.25):
        return AI_EFFECTIVENESS_x0_25;
    case UQ_4_12(0.5):
        return AI_EFFECTIVENESS_x0_5;
    case UQ_4_12(1.0):
    default:
        return AI_EFFECTIVENESS_x1;
    case UQ_4_12(2.0):
        return AI_EFFECTIVENESS_x2;
    case UQ_4_12(4.0):
        return AI_EFFECTIVENESS_x4;
    case UQ_4_12(8.0):
        return AI_EFFECTIVENESS_x8;
    }
}

/* Checks to see if AI will move ahead of another battler
 * Output:
    * AI_IS_FASTER: is user(ai) faster
    * AI_IS_SLOWER: is target faster
*/
u32 AI_WhoStrikesFirst(u32 battlerAI, u32 battler2, u32 moveConsidered)
{
    u32 fasterAI = 0, fasterPlayer = 0, i;
    s8 prioAI = 0;
    s8 prioBattler2 = 0;
    u16 *battler2Moves = GetMovesArray(battler2);

    // Check move priorities first.
    prioAI = GetMovePriority(battlerAI, moveConsidered);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        prioBattler2 = GetMovePriority(battler2, battler2Moves[i]);
        if (battler2Moves[i] == MOVE_NONE || battler2Moves[i] == MOVE_UNAVAILABLE
            || (prioBattler2 > prioAI && !CanIndexMoveFaintTarget(battler2, battlerAI, i , 2)))
            continue;

        if (prioAI > prioBattler2)
            fasterAI++;
        else if (prioBattler2 > prioAI)
            fasterPlayer++;
    }

    if (fasterAI > fasterPlayer)
    {
        return AI_IS_FASTER;
    }
    else if (fasterAI < fasterPlayer)
    {
        return AI_IS_SLOWER;
    }
    else
    {
        if (prioAI > prioBattler2)
            return AI_IS_FASTER;    // if we didn't know any of battler 2's moves to compare priorities, assume they don't have a prio+ move
        // Priorities are the same(at least comparing to moves the AI is aware of), decide by speed.
        if (GetWhichBattlerFasterArgs(battlerAI, battler2, TRUE,
                                      AI_DATA->abilities[battlerAI], AI_DATA->abilities[battler2],
                                      AI_DATA->holdEffects[battlerAI], AI_DATA->holdEffects[battler2],
                                      AI_DATA->speedStats[battlerAI], AI_DATA->speedStats[battler2],
                                      prioAI, prioBattler2) == 0)
            return AI_IS_FASTER;
        else
            return AI_IS_SLOWER;
    }
}

// Check if target has means to faint ai mon.
bool32 CanTargetFaintAi(u32 battlerDef, u32 battlerAtk)
{
    s32 i;
    u32 unusable = AI_DATA->moveLimitations[battlerDef];
    u16 *moves = GetMovesArray(battlerDef);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && !(unusable & gBitTable[i])
            && AI_DATA->simulatedDmg[battlerDef][battlerAtk][i] >= gBattleMons[battlerAtk].hp)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// Check if AI mon has the means to faint the target with any of its moves.
// If numHits > 1, check if the target will be KO'ed by that number of hits (ignoring healing effects)
bool32 CanAIFaintTarget(u32 battlerAtk, u32 battlerDef, u32 numHits)
{
    s32 i, dmg;
    u32 moveLimitations = AI_DATA->moveLimitations[battlerAtk];
    u16 *moves = gBattleMons[battlerAtk].moves;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && !(moveLimitations & gBitTable[i]))
        {
            // Use the pre-calculated value in simulatedDmg instead of re-calculating it
            dmg = AI_DATA->simulatedDmg[battlerAtk][battlerDef][i];

            if (numHits)
                dmg *= numHits;

            if (gBattleMons[battlerDef].hp <= dmg)
                return TRUE;
        }
    }

    return FALSE;
}

bool32 CanTargetMoveFaintAi(u32 move, u32 battlerDef, u32 battlerAtk, u32 nHits)
{
    u32 indexSlot = GetMoveSlot(GetMovesArray(battlerDef), move);
    if (indexSlot < MAX_MON_MOVES)
    {
        if (GetNoOfHitsToKO(AI_DATA->simulatedDmg[battlerDef][battlerAtk][indexSlot], gBattleMons[battlerAtk].hp) <= nHits)
            return TRUE;
    }
    return FALSE;
}

// Check if target has means to faint ai mon after modding hp/dmg
bool32 CanTargetFaintAiWithMod(u32 battlerDef, u32 battlerAtk, s32 hpMod, s32 dmgMod)
{
    u32 i;
    u32 unusable = AI_DATA->moveLimitations[battlerDef];
    s32 dmg;
    u16 *moves = gBattleResources->battleHistory->usedMoves[battlerDef];
    u32 hpCheck = gBattleMons[battlerAtk].hp + hpMod;

    if (hpCheck > gBattleMons[battlerAtk].maxHP)
        hpCheck = gBattleMons[battlerAtk].maxHP;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        dmg = AI_DATA->simulatedDmg[battlerAtk][battlerDef][i];
        if (dmgMod)
            dmg *= dmgMod;

        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && !(unusable & gBitTable[i]) && dmg >= hpCheck)
        {
            return TRUE;
        }
    }

    return FALSE;
}

bool32 AI_IsAbilityOnSide(u32 battlerId, u32 ability)
{
    if (IsBattlerAlive(battlerId) && AI_DATA->abilities[battlerId] == ability)
        return TRUE;
    else if (IsBattlerAlive(BATTLE_PARTNER(battlerId)) && AI_DATA->abilities[BATTLE_PARTNER(battlerId)] == ability)
        return TRUE;
    else
        return FALSE;
}

// does NOT include ability suppression checks
s32 AI_DecideKnownAbilityForTurn(u32 battlerId)
{
    u32 knownAbility = GetBattlerAbility(battlerId);

    // We've had ability overwritten by e.g. Worry Seed. It is not part of AI_PARTY in case of switching
    if (gBattleStruct->overwrittenAbilities[battlerId])
        return gBattleStruct->overwrittenAbilities[battlerId];

    // The AI knows its own ability.
    if (IsAiBattlerAware(battlerId))
        return knownAbility;

    // Check neutralizing gas, gastro acid
    if (knownAbility == ABILITY_NONE)
        return knownAbility;

    if (AI_PARTY->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].ability != ABILITY_NONE)
        return AI_PARTY->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].ability;

    // Abilities that prevent fleeing - treat as always known
    if (knownAbility == ABILITY_SHADOW_TAG || knownAbility == ABILITY_MAGNET_PULL || knownAbility == ABILITY_ARENA_TRAP)
        return knownAbility;

    // Else, guess the ability
    if (gSpeciesInfo[gBattleMons[battlerId].species].abilities[0] != ABILITY_NONE)
    {
        u32 abilityGuess = ABILITY_NONE;
        while (abilityGuess == ABILITY_NONE)
        {
            abilityGuess = gSpeciesInfo[gBattleMons[battlerId].species].abilities[Random() % NUM_ABILITY_SLOTS];
        }

        return abilityGuess;
    }

    return ABILITY_NONE; // Unknown.
}

u32 AI_DecideHoldEffectForTurn(u32 battlerId)
{
    u32 holdEffect;

    if (!IsAiBattlerAware(battlerId))
        holdEffect = AI_PARTY->mons[GetBattlerSide(battlerId)][gBattlerPartyIndexes[battlerId]].heldEffect;
    else
        holdEffect = GetBattlerHoldEffect(battlerId, FALSE);

    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_UNAWARE)
        return holdEffect;

    if (gStatuses3[battlerId] & STATUS3_EMBARGO)
        return HOLD_EFFECT_NONE;
    if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        return HOLD_EFFECT_NONE;
    if (AI_DATA->abilities[battlerId] == ABILITY_KLUTZ && !(gStatuses3[battlerId] & STATUS3_GASTRO_ACID))
        return HOLD_EFFECT_NONE;

    return holdEffect;
}

bool32 AI_IsTerrainAffected(u32 battlerId, u32 flags)
{
    if (gStatuses3[battlerId] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;
    else if (!(gFieldStatuses & flags))
        return FALSE;
    return AI_IsBattlerGrounded(battlerId);
}

// different from IsBattlerGrounded in that we don't always know battler's hold effect or ability
bool32 AI_IsBattlerGrounded(u32 battlerId)
{
    u32 holdEffect = AI_DATA->holdEffects[battlerId];

    if (holdEffect == HOLD_EFFECT_IRON_BALL)
        return TRUE;
    else if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_ROOTED)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_SMACKED_DOWN)
        return TRUE;
    else if (gStatuses3[battlerId] & STATUS3_TELEKINESIS)
        return FALSE;
    else if (gStatuses3[battlerId] & STATUS3_MAGNET_RISE)
        return FALSE;
    else if (holdEffect == HOLD_EFFECT_AIR_BALLOON)
        return FALSE;
    else if (AI_DATA->abilities[battlerId] == ABILITY_LEVITATE)
        return FALSE;
    else if (IS_BATTLER_OF_TYPE(battlerId, TYPE_FLYING))
        return FALSE;
    else
        return TRUE;
}

bool32 DoesBattlerIgnoreAbilityChecks(u32 atkAbility, u32 move)
{
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_UNAWARE)
        return FALSE;   // AI handicap flag: doesn't understand ability suppression concept

    if (IsMoldBreakerTypeAbility(atkAbility) || gBattleMoves[move].ignoresTargetAbility)
        return TRUE;

    return FALSE;
}

static inline bool32 AI_WeatherHasEffect(struct AiLogicData *aiData)
{
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_UNAWARE)
        return TRUE;   // AI doesn't understand weather supression (handicap)

    return aiData->weatherHasEffect;  // weather damping abilities are announced
}

u32 AI_GetWeather(struct AiLogicData *aiData)
{
    if (gBattleWeather == B_WEATHER_NONE)
        return B_WEATHER_NONE;
    if (!AI_WeatherHasEffect(aiData))
        return B_WEATHER_NONE;
    return gBattleWeather;
}

u32 AI_GetBattlerMoveTargetType(u32 battlerId, u32 move)
{
    if (gBattleMoves[move].effect == EFFECT_EXPANDING_FORCE && AI_IsTerrainAffected(battlerId, STATUS_FIELD_PSYCHIC_TERRAIN))
        return MOVE_TARGET_BOTH;
    else
        return gBattleMoves[move].target;
}

bool32 IsAromaVeilProtectedMove(u32 move)
{
    switch (move)
    {
    case MOVE_DISABLE:
    case MOVE_ATTRACT:
    case MOVE_ENCORE:
    case MOVE_TORMENT:
    case MOVE_TAUNT:
    case MOVE_HEAL_BLOCK:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsNonVolatileStatusMoveEffect(u32 moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_SLEEP:
    case EFFECT_TOXIC:
    case EFFECT_POISON:
    case EFFECT_PARALYZE:
    case EFFECT_WILL_O_WISP:
    case EFFECT_YAWN:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsConfusionMoveEffect(u32 moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_CONFUSE:
    case EFFECT_SWAGGER:
    case EFFECT_FLATTER:
    case EFFECT_TEETER_DANCE:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsHazardMoveEffect(u32 moveEffect)
{
    switch (moveEffect)
    {
    case EFFECT_SPIKES:
    case EFFECT_TOXIC_SPIKES:
    case EFFECT_STICKY_WEB:
    case EFFECT_STEALTH_ROCK:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsMoveRedirectionPrevented(u32 move, u32 atkAbility)
{
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_NEGATE_UNAWARE)
        return FALSE;

    if (move == MOVE_SKY_DROP
      || move == MOVE_SNIPE_SHOT
      || atkAbility == ABILITY_PROPELLER_TAIL
      || atkAbility == ABILITY_STALWART)
        return TRUE;
    return FALSE;
}

bool32 IsSemiInvulnerable(u32 battlerDef, u32 move)
{
    if (gStatuses3[battlerDef] & STATUS3_PHANTOM_FORCE)
        return TRUE;
    else if (!gBattleMoves[move].damagesAirborne && gStatuses3[battlerDef] & STATUS3_ON_AIR)
        return TRUE;
    else if (!gBattleMoves[move].damagesUnderwater && gStatuses3[battlerDef] & STATUS3_UNDERWATER)
        return TRUE;
    else if (!gBattleMoves[move].damagesUnderground && gStatuses3[battlerDef] & STATUS3_UNDERGROUND)
        return TRUE;
    else
        return FALSE;
}

bool32 IsMoveEncouragedToHit(u32 battlerAtk, u32 battlerDef, u32 move)
{
    u32 weather;
    if (IsSemiInvulnerable(battlerDef, move))
        return FALSE;

    //TODO - anticipate protect move?

    // always hits
    if (gStatuses3[battlerDef] & STATUS3_ALWAYS_HITS || gDisableStructs[battlerDef].battlerWithSureHit == battlerAtk)
        return TRUE;

    if (AI_DATA->abilities[battlerDef] == ABILITY_NO_GUARD || AI_DATA->abilities[battlerAtk] == ABILITY_NO_GUARD)
        return TRUE;

    if (B_TOXIC_NEVER_MISS >= GEN_6 && gBattleMoves[move].effect == EFFECT_TOXIC && IS_BATTLER_OF_TYPE(battlerAtk, TYPE_POISON))
        return TRUE;

    // discouraged from hitting
    weather = AI_GetWeather(AI_DATA);
    if ((weather & B_WEATHER_SUN)
      && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
        return FALSE;

    // increased accuracy but don't always hit
    if ((((weather & B_WEATHER_RAIN) && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
            || (((weather & (B_WEATHER_HAIL | B_WEATHER_SNOW)) && move == MOVE_BLIZZARD)))
        || (gBattleMoves[move].effect == EFFECT_VITAL_THROW)
        || (B_MINIMIZE_DMG_ACC >= GEN_6 && (gStatuses3[battlerDef] & STATUS3_MINIMIZED) && gBattleMoves[move].minimizeDoubleDamage)
        || (gBattleMoves[move].accuracy == 0))
    {
        return TRUE;
    }

    return FALSE;
}

bool32 ShouldTryOHKO(u32 battlerAtk, u32 battlerDef, u32 atkAbility, u32 defAbility, u32 move)
{
    u32 holdEffect = AI_DATA->holdEffects[battlerDef];
    u32 accuracy = AI_DATA->moveAccuracy[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex];

    gPotentialItemEffectBattler = battlerDef;
    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < AI_DATA->holdEffectParams[battlerDef])
        return FALSE;   //probabilistically speaking, focus band should activate so dont OHKO
    else if (holdEffect == HOLD_EFFECT_FOCUS_SASH && AtMaxHp(battlerDef))
        return FALSE;

    if (!DoesBattlerIgnoreAbilityChecks(atkAbility, move) && defAbility == ABILITY_STURDY)
        return FALSE;

    if ((((gStatuses3[battlerDef] & STATUS3_ALWAYS_HITS)
        && gDisableStructs[battlerDef].battlerWithSureHit == battlerAtk)
        || atkAbility == ABILITY_NO_GUARD || defAbility == ABILITY_NO_GUARD)
        && gBattleMons[battlerAtk].level >= gBattleMons[battlerDef].level)
    {
        return TRUE;
    }
    else    // test the odds
    {
        u32 odds = accuracy + (gBattleMons[battlerAtk].level - gBattleMons[battlerDef].level);
        if (B_SHEER_COLD_ACC >= GEN_7 && move == MOVE_SHEER_COLD && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_ICE))
            odds -= 10;
        if (Random() % 100 + 1 < odds && gBattleMons[battlerAtk].level >= gBattleMons[battlerDef].level)
            return TRUE;
    }
    return FALSE;
}

bool32 ShouldSetSandstorm(u32 battler, u32 ability, u32 holdEffect)
{
    u32 weather = AI_GetWeather(AI_DATA);
    if (weather & B_WEATHER_SANDSTORM)
        return FALSE;

    if (ability == ABILITY_SAND_VEIL
      || ability == ABILITY_SAND_RUSH
      || ability == ABILITY_SAND_FORCE
      || ability == ABILITY_OVERCOAT
      || ability == ABILITY_MAGIC_GUARD
      || holdEffect == HOLD_EFFECT_SAFETY_GOGGLES
      || IS_BATTLER_OF_TYPE(battler, TYPE_ROCK)
      || IS_BATTLER_OF_TYPE(battler, TYPE_STEEL)
      || IS_BATTLER_OF_TYPE(battler, TYPE_GROUND)
      || HasMoveEffect(battler, EFFECT_SHORE_UP)
      || HasMoveEffect(battler, EFFECT_WEATHER_BALL))
    {
        return TRUE;
    }
    return FALSE;
}

bool32 ShouldSetHail(u32 battler, u32 ability, u32 holdEffect)
{
    u32 weather = AI_GetWeather(AI_DATA);
    if (weather & (B_WEATHER_HAIL | B_WEATHER_SNOW))
        return FALSE;

    if (ability == ABILITY_SNOW_CLOAK
      || ability == ABILITY_ICE_BODY
      || ability == ABILITY_FORECAST
      || ability == ABILITY_SLUSH_RUSH
      || ability == ABILITY_MAGIC_GUARD
      || ability == ABILITY_OVERCOAT
      || holdEffect == HOLD_EFFECT_SAFETY_GOGGLES
      || IS_BATTLER_OF_TYPE(battler, TYPE_ICE)
      || HasMove(battler, MOVE_BLIZZARD)
      || HasMoveEffect(battler, EFFECT_AURORA_VEIL)
      || HasMoveEffect(battler, EFFECT_WEATHER_BALL))
    {
        return TRUE;
    }
    return FALSE;
}

bool32 ShouldSetRain(u32 battlerAtk, u32 atkAbility, u32 holdEffect)
{
    u32 weather = AI_GetWeather(AI_DATA);
    if (weather & B_WEATHER_RAIN)
        return FALSE;

    if (holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA
     && (atkAbility == ABILITY_SWIFT_SWIM
      || atkAbility == ABILITY_FORECAST
      || atkAbility == ABILITY_HYDRATION
      || atkAbility == ABILITY_RAIN_DISH
      || atkAbility == ABILITY_DRY_SKIN
      || HasMoveEffect(battlerAtk, EFFECT_THUNDER)
      || HasMoveEffect(battlerAtk, EFFECT_HURRICANE)
      || HasMoveEffect(battlerAtk, EFFECT_WEATHER_BALL)
      || HasMoveWithType(battlerAtk, TYPE_WATER)))
    {
        return TRUE;
    }
    return FALSE;
}

bool32 ShouldSetSun(u32 battlerAtk, u32 atkAbility, u32 holdEffect)
{
    u32 weather = AI_GetWeather(AI_DATA);
    if (weather & B_WEATHER_SUN)
        return FALSE;

    if (holdEffect != HOLD_EFFECT_UTILITY_UMBRELLA
     && (atkAbility == ABILITY_CHLOROPHYLL
      || atkAbility == ABILITY_FLOWER_GIFT
      || atkAbility == ABILITY_FORECAST
      || atkAbility == ABILITY_LEAF_GUARD
      || atkAbility == ABILITY_SOLAR_POWER
      || atkAbility == ABILITY_HARVEST
      || HasMoveEffect(battlerAtk, EFFECT_SOLAR_BEAM)
      || HasMoveEffect(battlerAtk, EFFECT_MORNING_SUN)
      || HasMoveEffect(battlerAtk, EFFECT_SYNTHESIS)
      || HasMoveEffect(battlerAtk, EFFECT_MOONLIGHT)
      || HasMoveEffect(battlerAtk, EFFECT_WEATHER_BALL)
      || HasMoveEffect(battlerAtk, EFFECT_GROWTH)
      || HasMoveWithType(battlerAtk, TYPE_FIRE)))
    {
        return TRUE;
    }
    return FALSE;
}

bool32 ShouldSetSnow(u32 battler, u32 ability, u32 holdEffect)
{
    u32 weather = AI_GetWeather(AI_DATA);
    if (weather & (B_WEATHER_SNOW | B_WEATHER_HAIL))
        return FALSE;

    if (ability == ABILITY_SNOW_CLOAK
      || ability == ABILITY_ICE_BODY
      || ability == ABILITY_FORECAST
      || ability == ABILITY_SLUSH_RUSH
      || IS_BATTLER_OF_TYPE(battler, TYPE_ICE)
      || HasMove(battler, MOVE_BLIZZARD)
      || HasMoveEffect(battler, EFFECT_AURORA_VEIL)
      || HasMoveEffect(battler, EFFECT_WEATHER_BALL))
    {
        return TRUE;
    }
    return FALSE;
}

void ProtectChecks(u32 battlerAtk, u32 battlerDef, u32 move, u32 predictedMove, s32 *score)
{
    // TODO more sophisticated logic
    u32 uses = gDisableStructs[battlerAtk].protectUses;

    /*if (GetMoveResultFlags(predictedMove) & (MOVE_RESULT_NO_EFFECT | MOVE_RESULT_MISSED))
    {
        ADJUST_SCORE_PTR(-5);
        return;
    }*/

    if (uses == 0)
    {
        if (predictedMove != MOVE_NONE && predictedMove != 0xFFFF && !IS_MOVE_STATUS(predictedMove))
            ADJUST_SCORE_PTR(2);
        else if (Random() % 256 < 100)
            ADJUST_SCORE_PTR(1);
    }
    else
    {
        if (IsDoubleBattle())
            ADJUST_SCORE_PTR(-(2 * min(uses, 3)));
        else
            ADJUST_SCORE_PTR(-(min(uses, 3)));
    }

    if (gBattleMons[battlerAtk].status1 & (STATUS1_PSN_ANY | STATUS1_BURN | STATUS1_FROSTBITE)
     || gBattleMons[battlerAtk].status2 & (STATUS2_CURSED | STATUS2_INFATUATION)
     || gStatuses3[battlerAtk] & (STATUS3_PERISH_SONG | STATUS3_LEECHSEED | STATUS3_YAWN))
    {
        ADJUST_SCORE_PTR(-1);
    }

    if (gBattleMons[battlerDef].status1 & STATUS1_TOXIC_POISON
      || gBattleMons[battlerDef].status2 & (STATUS2_CURSED | STATUS2_INFATUATION)
      || gStatuses3[battlerDef] & (STATUS3_PERISH_SONG | STATUS3_LEECHSEED | STATUS3_YAWN))
        ADJUST_SCORE_PTR(2);
}

// stat stages
bool32 ShouldLowerStat(u32 battler, u32 battlerAbility, u32 stat)
{
    if (gBattleMons[battler].statStages[stat] > MIN_STAT_STAGE && battlerAbility != ABILITY_CONTRARY)
    {
        if (AI_DATA->holdEffects[battler] == HOLD_EFFECT_CLEAR_AMULET
         || battlerAbility == ABILITY_CLEAR_BODY
         || battlerAbility == ABILITY_WHITE_SMOKE
         || battlerAbility == ABILITY_FULL_METAL_BODY)
            return FALSE;

        // If AI is faster and doesn't have any mons left, lowering speed doesn't give any
        if (stat == STAT_SPEED)
        {
            if (AI_WhoStrikesFirst(sBattler_AI, battler, AI_THINKING_STRUCT->moveConsidered) == AI_IS_FASTER
                && CountUsablePartyMons(sBattler_AI) == 0
                && !HasMoveEffect(sBattler_AI, EFFECT_ELECTRO_BALL))
                return FALSE;
        }
        return TRUE;
    }

    return FALSE;
}

bool32 BattlerStatCanRise(u32 battler, u32 battlerAbility, u32 stat)
{
    if ((gBattleMons[battler].statStages[stat] < MAX_STAT_STAGE && battlerAbility != ABILITY_CONTRARY)
      || (battlerAbility == ABILITY_CONTRARY && gBattleMons[battler].statStages[stat] > MIN_STAT_STAGE))
        return TRUE;
    return FALSE;
}

bool32 AreBattlersStatsMaxed(u32 battlerId)
{
    u32 i;
    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] < MAX_STAT_STAGE)
            return FALSE;
    }
    return TRUE;
}

bool32 AnyStatIsRaised(u32 battlerId)
{
    u32 i;

    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] > DEFAULT_STAT_STAGE)
            return TRUE;
    }
    return FALSE;
}

u32 CountPositiveStatStages(u32 battlerId)
{
    u32 count = 0;
    u32 i;
    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] > DEFAULT_STAT_STAGE)
            count++;
    }
    return count;
}

u32 CountNegativeStatStages(u32 battlerId)
{
    u32 count = 0;
    u32 i;
    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battlerId].statStages[i] < DEFAULT_STAT_STAGE)
            count++;
    }
    return count;
}

bool32 ShouldLowerAttack(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if (AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered) && (AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return FALSE; // Don't bother lowering stats if can kill enemy.

    if (gBattleMons[battlerDef].statStages[STAT_ATK] > 4
      && HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL)
      && defAbility != ABILITY_CONTRARY
      && defAbility != ABILITY_CLEAR_BODY
      && defAbility != ABILITY_WHITE_SMOKE
      && defAbility != ABILITY_FULL_METAL_BODY
      && defAbility != ABILITY_HYPER_CUTTER
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CLEAR_AMULET)
        return TRUE;
    return FALSE;
}

bool32 ShouldLowerDefense(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if (AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered) && (AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return FALSE; // Don't bother lowering stats if can kill enemy.

    if (gBattleMons[battlerDef].statStages[STAT_DEF] > 4
      && HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL)
      && defAbility != ABILITY_CONTRARY
      && defAbility != ABILITY_CLEAR_BODY
      && defAbility != ABILITY_WHITE_SMOKE
      && defAbility != ABILITY_FULL_METAL_BODY
      && defAbility != ABILITY_BIG_PECKS
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CLEAR_AMULET)
        return TRUE;
    return FALSE;
}

bool32 ShouldLowerSpeed(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if (AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered) && (AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return FALSE; // Don't bother lowering stats if can kill enemy.

    if (!AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered)
      && defAbility != ABILITY_CONTRARY
      && defAbility != ABILITY_CLEAR_BODY
      && defAbility != ABILITY_FULL_METAL_BODY
      && defAbility != ABILITY_WHITE_SMOKE
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CLEAR_AMULET)
        return TRUE;
    return FALSE;
}

bool32 ShouldLowerSpAtk(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if (AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered) && (AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return FALSE; // Don't bother lowering stats if can kill enemy.

    if (gBattleMons[battlerDef].statStages[STAT_SPATK] > 4
      && HasMoveWithSplit(battlerDef, SPLIT_SPECIAL)
      && defAbility != ABILITY_CONTRARY
      && defAbility != ABILITY_CLEAR_BODY
      && defAbility != ABILITY_FULL_METAL_BODY
      && defAbility != ABILITY_WHITE_SMOKE
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CLEAR_AMULET)
        return TRUE;
    return FALSE;
}

bool32 ShouldLowerSpDef(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if (AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered) && (AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return FALSE; // Don't bother lowering stats if can kill enemy.

    if (gBattleMons[battlerDef].statStages[STAT_SPDEF] > 4
      && HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL)
      && defAbility != ABILITY_CONTRARY
      && defAbility != ABILITY_CLEAR_BODY
      && defAbility != ABILITY_FULL_METAL_BODY
      && defAbility != ABILITY_WHITE_SMOKE
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CLEAR_AMULET)
        return TRUE;
    return FALSE;
}

bool32 ShouldLowerAccuracy(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if (AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered) && (AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return FALSE; // Don't bother lowering stats if can kill enemy.

    if (defAbility != ABILITY_CONTRARY
      && defAbility != ABILITY_CLEAR_BODY
      && defAbility != ABILITY_WHITE_SMOKE
      && defAbility != ABILITY_FULL_METAL_BODY
      && defAbility != ABILITY_KEEN_EYE
      && (B_ILLUMINATE_EFFECT >= GEN_9 && defAbility != ABILITY_ILLUMINATE)
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CLEAR_AMULET)
        return TRUE;
    return FALSE;
}

bool32 ShouldLowerEvasion(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if (AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered) && (AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return FALSE; // Don't bother lowering stats if can kill enemy.

    if (gBattleMons[battlerDef].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE
      && defAbility != ABILITY_CONTRARY
      && defAbility != ABILITY_CLEAR_BODY
      && defAbility != ABILITY_FULL_METAL_BODY
      && defAbility != ABILITY_WHITE_SMOKE
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CLEAR_AMULET)
        return TRUE;
    return FALSE;
}

bool32 CanIndexMoveFaintTarget(u32 battlerAtk, u32 battlerDef, u32 index, u32 numHits)
{
    s32 dmg = AI_DATA->simulatedDmg[battlerAtk][battlerDef][index];

    if (numHits)
        dmg *= numHits;

    if (gBattleMons[battlerDef].hp <= dmg)
        return TRUE;
    return FALSE;
}

u16 *GetMovesArray(u32 battler)
{
    if (IsAiBattlerAware(battler) || IsAiBattlerAware(BATTLE_PARTNER(battler)))
        return gBattleMons[battler].moves;
    else
        return gBattleResources->battleHistory->usedMoves[battler];
}

bool32 HasOnlyMovesWithSplit(u32 battlerId, u32 split, bool32 onlyOffensive)
{
    u32 i;
    u16 *moves = GetMovesArray(battlerId);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (onlyOffensive && IS_MOVE_STATUS(moves[i]))
            continue;
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && GetBattleMoveSplit(moves[i]) != split)
            return FALSE;
    }

    return TRUE;
}

bool32 HasMoveWithSplit(u32 battler, u32 split)
{
    u32 i;
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && GetBattleMoveSplit(moves[i]) == split)
            return TRUE;
    }
    return FALSE;
}

bool32 HasMoveWithType(u32 battler, u32 type)
{
    s32 i;
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && gBattleMoves[moves[i]].type == type)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveEffect(u32 battlerId, u32 moveEffect)
{
    s32 i;
    u16 *moves = GetMovesArray(battlerId);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && gBattleMoves[moves[i]].effect == moveEffect)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMove(u32 battlerId, u32 move)
{
    s32 i;
    u16 *moves = GetMovesArray(battlerId);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && moves[i] == move)
            return TRUE;
    }

    return FALSE;
}

bool32 HasMoveWithLowAccuracy(u32 battlerAtk, u32 battlerDef, u32 accCheck, bool32 ignoreStatus, u32 atkAbility, u32 defAbility, u32 atkHoldEffect, u32 defHoldEffect)
{
    s32 i;
    u16 *moves = GetMovesArray(battlerAtk);
    u32 moveLimitations = AI_DATA->moveLimitations[battlerAtk];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] == MOVE_NONE || moves[i] == MOVE_UNAVAILABLE)
            continue;

        if (!(gBitTable[i] & moveLimitations))
        {
            if (ignoreStatus && IS_MOVE_STATUS(moves[i]))
                continue;
            else if ((!IS_MOVE_STATUS(moves[i]) && gBattleMoves[moves[i]].accuracy == 0)
              || AI_GetBattlerMoveTargetType(battlerAtk, moves[i]) & (MOVE_TARGET_USER | MOVE_TARGET_OPPONENTS_FIELD))
                continue;

            if (AI_DATA->moveAccuracy[battlerAtk][battlerDef][i] <= accCheck)
                return TRUE;
        }
    }

    return FALSE;
}

bool32 HasSleepMoveWithLowAccuracy(u32 battlerAtk, u32 battlerDef)
{
    u32 moveLimitations = AI_DATA->moveLimitations[battlerAtk];
    u32 i;
    u16 *moves = GetMovesArray(battlerAtk);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] == MOVE_NONE)
            break;
        if (!(gBitTable[i] & moveLimitations))
        {
            if (gBattleMoves[moves[i]].effect == EFFECT_SLEEP
              && AI_DATA->moveAccuracy[battlerAtk][battlerDef][i] < 85)
                return TRUE;
        }
    }
    return FALSE;
}

bool32 IsHealingMoveEffect(u32 effect)
{
    switch (effect)
    {
    case EFFECT_RESTORE_HP:
    case EFFECT_MORNING_SUN:
    case EFFECT_SYNTHESIS:
    case EFFECT_MOONLIGHT:
    case EFFECT_SOFTBOILED:
    case EFFECT_ROOST:
    case EFFECT_SWALLOW:
    case EFFECT_WISH:
    case EFFECT_HEALING_WISH:
    case EFFECT_HEAL_PULSE:
    case EFFECT_REST:
    case EFFECT_JUNGLE_HEALING:
    case EFFECT_ABSORB:
    case EFFECT_DREAM_EATER:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 HasHealingEffect(u32 battlerId)
{
    s32 i;
    u16 *moves = GetMovesArray(battlerId);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && IsHealingMoveEffect(gBattleMoves[moves[i]].effect))
            return TRUE;
    }

    return FALSE;
}

bool32 IsTrappingMoveEffect(u32 effect)
{
    switch (effect)
    {
    case EFFECT_MEAN_LOOK:
    case EFFECT_TRAP:
    case EFFECT_HIT_PREVENT_ESCAPE:
    case EFFECT_FAIRY_LOCK:
    //case EFFECT_NO_RETREAT:   // TODO
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 HasTrappingMoveEffect(u32 battler)
{
    s32 i;
    u16 *moves = GetMovesArray(battler);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && IsTrappingMoveEffect(gBattleMoves[moves[i]].effect))
            return TRUE;
    }

    return FALSE;
}

bool32 HasThawingMove(u32 battler)
{
    CHECK_MOVE_FLAG(thawsUser);
}

bool32 IsUngroundingEffect(u32 effect)
{
    switch (effect)
    {
    case EFFECT_MAGNET_RISE:
        return TRUE;
    default:
        return FALSE;
    }
}

// for anger point
bool32 IsAttackBoostMoveEffect(u32 effect)
{
    switch (effect)
    {
    case EFFECT_ATTACK_UP:
	case EFFECT_ATTACK_UP_2:
    case EFFECT_ATTACK_ACCURACY_UP:
    case EFFECT_ATTACK_SPATK_UP:
    case EFFECT_DRAGON_DANCE:
    case EFFECT_COIL:
    case EFFECT_BELLY_DRUM:
    case EFFECT_BULK_UP:
    case EFFECT_GROWTH:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsStatRaisingEffect(u32 effect)
{
    switch (effect)
    {
    case EFFECT_ATTACK_UP:
	case EFFECT_ATTACK_UP_2:
	case EFFECT_DEFENSE_UP:
	case EFFECT_DEFENSE_UP_2:
    case EFFECT_DEFENSE_UP_3:
	case EFFECT_SPEED_UP:
	case EFFECT_SPEED_UP_2:
	case EFFECT_SPECIAL_ATTACK_UP:
	case EFFECT_SPECIAL_ATTACK_UP_2:
    case EFFECT_SPECIAL_ATTACK_UP_3:
	case EFFECT_SPECIAL_DEFENSE_UP:
	case EFFECT_SPECIAL_DEFENSE_UP_2:
    case EFFECT_ACCURACY_UP:
    case EFFECT_ACCURACY_UP_2:
    case EFFECT_EVASION_UP:
    case EFFECT_EVASION_UP_2:
    case EFFECT_MINIMIZE:
    case EFFECT_DEFENSE_CURL:
	case EFFECT_CALM_MIND:
    case EFFECT_COSMIC_POWER:
	case EFFECT_DRAGON_DANCE:
	case EFFECT_ACUPRESSURE:
	case EFFECT_SHELL_SMASH:
	case EFFECT_SHIFT_GEAR:
	case EFFECT_ATTACK_ACCURACY_UP:
	case EFFECT_ATTACK_SPATK_UP:
	case EFFECT_GROWTH:
	case EFFECT_COIL:
	case EFFECT_QUIVER_DANCE:
    case EFFECT_BULK_UP:
    case EFFECT_GEOMANCY:
    case EFFECT_STOCKPILE:
    case EFFECT_VICTORY_DANCE:
        return TRUE;
    case EFFECT_CHARGE:
        return B_CHARGE_SPDEF_RAISE >= GEN_5;
    default:
        return FALSE;
    }
}

bool32 IsStatLoweringEffect(u32 effect)
{
    // ignore other potentially-beneficial effects like defog, gravity
    switch (effect)
    {
    case EFFECT_ATTACK_DOWN:
    case EFFECT_DEFENSE_DOWN:
    case EFFECT_SPEED_DOWN:
    case EFFECT_SPECIAL_ATTACK_DOWN:
    case EFFECT_SPECIAL_DEFENSE_DOWN:
    case EFFECT_ACCURACY_DOWN:
    case EFFECT_EVASION_DOWN:
    case EFFECT_ATTACK_DOWN_2:
    case EFFECT_DEFENSE_DOWN_2:
    case EFFECT_SPEED_DOWN_2:
    case EFFECT_SPECIAL_ATTACK_DOWN_2:
    case EFFECT_SPECIAL_DEFENSE_DOWN_2:
    case EFFECT_ACCURACY_DOWN_2:
    case EFFECT_EVASION_DOWN_2:
    case EFFECT_TICKLE:
    case EFFECT_CAPTIVATE:
    case EFFECT_NOBLE_ROAR:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 HasDamagingMove(u32 battlerId)
{
    u32 i;
    u16 *moves = GetMovesArray(battlerId);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE && gBattleMoves[moves[i]].power != 0)
            return TRUE;
    }

    return FALSE;
}

bool32 HasDamagingMoveOfType(u32 battlerId, u32 type)
{
    s32 i;
    u16 *moves = GetMovesArray(battlerId);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && moves[i] != MOVE_UNAVAILABLE
          && gBattleMoves[moves[i]].type == type && gBattleMoves[moves[i]].power != 0)
            return TRUE;
    }

    return FALSE;
}

bool32 HasSubstituteIgnoringMove(u32 battler)
{
    CHECK_MOVE_FLAG(ignoresSubstitute);
}

bool32 HasSoundMove(u32 battler)
{
    CHECK_MOVE_FLAG(soundMove);
}

bool32 HasHighCritRatioMove(u32 battler)
{
    CHECK_MOVE_FLAG(highCritRatio);
}

bool32 HasMagicCoatAffectedMove(u32 battler)
{
    CHECK_MOVE_FLAG(magicCoatAffected);
}

bool32 HasSnatchAffectedMove(u32 battler)
{
    CHECK_MOVE_FLAG(snatchAffected);
}

bool32 IsEncoreEncouragedEffect(u32 moveEffect)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sEncouragedEncoreEffects); i++)
    {
        if (moveEffect == sEncouragedEncoreEffects[i])
            return TRUE;
    }
    return FALSE;
}

bool32 IsChargingMove(u32 battlerAtk, u32 effect)
{
    switch (effect)
    {
    case EFFECT_SOLAR_BEAM:
        if (AI_GetWeather(AI_DATA) & B_WEATHER_SUN)
            return FALSE;
    case EFFECT_SKULL_BASH:
    case EFFECT_METEOR_BEAM:
    case EFFECT_TWO_TURNS_ATTACK:
        if (AI_DATA->holdEffects[battlerAtk] == HOLD_EFFECT_POWER_HERB)
            return FALSE;
        return TRUE;
    default:
        return FALSE;
    }
}

static u32 GetLeechSeedDamage(u32 battlerId)
{
    u32 damage = 0;
    if ((gStatuses3[battlerId] & STATUS3_LEECHSEED)
     && gBattleMons[gStatuses3[battlerId] & STATUS3_LEECHSEED_BATTLER].hp != 0)
     {
        damage = GetNonDynamaxMaxHP(battlerId) / 8;
        if (damage == 0)
            damage = 1;
     }
     return damage;
}

static u32 GetNightmareDamage(u32 battlerId)
{
    u32 damage = 0;
    if ((gBattleMons[battlerId].status2 & STATUS2_NIGHTMARE) && gBattleMons[battlerId].status1 & STATUS1_SLEEP)
    {
        damage = GetNonDynamaxMaxHP(battlerId) / 4;
        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetCurseDamage(u32 battlerId)
{
    u32 damage = 0;
    if (gBattleMons[battlerId].status2 & STATUS2_CURSED)
    {
        damage = GetNonDynamaxMaxHP(battlerId) / 4;
        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetTrapDamage(u32 battlerId)
{
    // ai has no knowledge about turns remaining
    u32 damage = 0;
    u32 holdEffect = AI_DATA->holdEffects[gBattleStruct->wrappedBy[battlerId]];
    if (gBattleMons[battlerId].status2 & STATUS2_WRAPPED)
    {
        if (holdEffect == HOLD_EFFECT_BINDING_BAND)
            damage = GetNonDynamaxMaxHP(battlerId) / (B_BINDING_DAMAGE >= GEN_6 ? 6 : 8);
        else
            damage = GetNonDynamaxMaxHP(battlerId) / (B_BINDING_DAMAGE >= GEN_6 ? 8 : 16);

        if (damage == 0)
            damage = 1;
    }
    return damage;
}

static u32 GetPoisonDamage(u32 battlerId)
{
    u32 damage = 0;

    if (AI_DATA->abilities[battlerId] == ABILITY_POISON_HEAL)
        return damage;

    if (gBattleMons[battlerId].status1 & STATUS1_POISON)
    {
        damage = gBattleMons[battlerId].maxHP / 8;
        if (damage == 0)
            damage = 1;
    }
    else if (gBattleMons[battlerId].status1 & STATUS1_TOXIC_POISON)
    {
        damage = gBattleMons[battlerId].maxHP / 16;
        if (damage == 0)
            damage = 1;
        if ((gBattleMons[battlerId].status1 & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
            gBattleMons[battlerId].status1 += STATUS1_TOXIC_TURN(1);
        damage *= (gBattleMons[battlerId].status1 & STATUS1_TOXIC_COUNTER) >> 8;
    }
    return damage;
}

static bool32 BattlerAffectedBySandstorm(u32 battlerId, u32 ability)
{
    if (!IS_BATTLER_OF_TYPE(battlerId, TYPE_ROCK)
      && !IS_BATTLER_OF_TYPE(battlerId, TYPE_GROUND)
      && !IS_BATTLER_OF_TYPE(battlerId, TYPE_STEEL)
      && ability != ABILITY_SAND_VEIL
      && ability != ABILITY_SAND_FORCE
      && ability != ABILITY_SAND_RUSH
      && ability != ABILITY_OVERCOAT)
        return TRUE;
    return FALSE;
}

static bool32 BattlerAffectedByHail(u32 battlerId, u32 ability)
{
    if (!IS_BATTLER_OF_TYPE(battlerId, TYPE_ICE)
      && ability != ABILITY_SNOW_CLOAK
      && ability != ABILITY_OVERCOAT
      && ability != ABILITY_ICE_BODY)
        return TRUE;
    return FALSE;
}

static u32 GetWeatherDamage(u32 battlerId)
{
    u32 ability = AI_DATA->abilities[battlerId];
    u32 holdEffect = AI_DATA->holdEffects[battlerId];
    u32 damage = 0;
    u32 weather = AI_GetWeather(AI_DATA);
    if (!weather)
        return 0;

    if (weather & B_WEATHER_SANDSTORM)
    {
        if (BattlerAffectedBySandstorm(battlerId, ability)
          && !(gStatuses3[battlerId] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
          && holdEffect != HOLD_EFFECT_SAFETY_GOGGLES)
        {
            damage = GetNonDynamaxMaxHP(battlerId) / 16;
            if (damage == 0)
                damage = 1;
        }
    }
    if ((weather & B_WEATHER_HAIL) && ability != ABILITY_ICE_BODY)
    {
        if (BattlerAffectedByHail(battlerId, ability)
          && !(gStatuses3[battlerId] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
          && holdEffect != HOLD_EFFECT_SAFETY_GOGGLES)
        {
            damage = GetNonDynamaxMaxHP(battlerId) / 16;
            if (damage == 0)
                damage = 1;
        }
    }
    return damage;
}

u32 GetBattlerSecondaryDamage(u32 battlerId)
{
    u32 secondaryDamage;

    if (AI_DATA->abilities[battlerId] == ABILITY_MAGIC_GUARD)
        return FALSE;

    secondaryDamage = GetLeechSeedDamage(battlerId)
     + GetNightmareDamage(battlerId)
     + GetCurseDamage(battlerId)
     + GetTrapDamage(battlerId)
     + GetPoisonDamage(battlerId)
     + GetWeatherDamage(battlerId);

    return secondaryDamage;
}

bool32 BattlerWillFaintFromWeather(u32 battler, u32 ability)
{
    if ((BattlerAffectedBySandstorm(battler, ability) || BattlerAffectedByHail(battler, ability))
      && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 16)
        return TRUE;

    return FALSE;
}

bool32 BattlerWillFaintFromSecondaryDamage(u32 battler, u32 ability)
{
    if (GetBattlerSecondaryDamage(battler) != 0
      && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 16)
        return TRUE;
    return FALSE;
}

static bool32 AnyUsefulStatIsRaised(u32 battler)
{
    u32 statId;

    for (statId = STAT_ATK; statId < NUM_BATTLE_STATS; statId++)
    {
        if (gBattleMons[battler].statStages[statId] > DEFAULT_STAT_STAGE)
        {
            switch (statId)
            {
            case STAT_ATK:
                if (HasMoveWithSplit(battler, SPLIT_PHYSICAL))
                    return TRUE;
                break;
            case STAT_SPATK:
                if (HasMoveWithSplit(battler, SPLIT_SPECIAL))
                    return TRUE;
                break;
            case STAT_SPEED:
                return TRUE;
            }
        }
    }

    return FALSE;
}

struct Pokemon *GetPartyBattlerPartyData(u32 battlerId, u32 switchBattler)
{
    struct Pokemon *mon;
    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        mon = &gPlayerParty[switchBattler];
    else
        mon = &gEnemyParty[switchBattler];
    return mon;
}

static bool32 PartyBattlerShouldAvoidHazards(u32 currBattler, u32 switchBattler)
{
    struct Pokemon *mon = GetPartyBattlerPartyData(currBattler, switchBattler);
    u32 ability = GetMonAbility(mon);   // we know our own party data
    u32 holdEffect;
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 flags = gSideStatuses[GetBattlerSide(currBattler)] & (SIDE_STATUS_SPIKES | SIDE_STATUS_STEALTH_ROCK | SIDE_STATUS_STICKY_WEB | SIDE_STATUS_TOXIC_SPIKES);
    s32 hazardDamage = 0;
    u32 type1 = gSpeciesInfo[species].types[0];
    u32 type2 = gSpeciesInfo[species].types[1];
    u32 maxHp = GetMonData(mon, MON_DATA_MAX_HP);

    if (flags == 0)
        return FALSE;

    if (ability == ABILITY_MAGIC_GUARD)
        return FALSE;
    if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM || ability == ABILITY_KLUTZ)
        holdEffect = HOLD_EFFECT_NONE;
    else
        holdEffect = gItems[GetMonData(mon, MON_DATA_HELD_ITEM)].holdEffect;
    if (holdEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS)
        return FALSE;

    if (flags & SIDE_STATUS_STEALTH_ROCK)
        hazardDamage += GetStealthHazardDamageByTypesAndHP(gBattleMoves[MOVE_STEALTH_ROCK].type, type1, type2, maxHp);

    if (flags & SIDE_STATUS_SPIKES && ((type1 != TYPE_FLYING && type2 != TYPE_FLYING
        && ability != ABILITY_LEVITATE && holdEffect != HOLD_EFFECT_AIR_BALLOON)
        || holdEffect == HOLD_EFFECT_IRON_BALL || gFieldStatuses & STATUS_FIELD_GRAVITY))
    {
        s32 spikesDmg = maxHp / ((5 - gSideTimers[GetBattlerSide(currBattler)].spikesAmount) * 2);
        if (spikesDmg == 0)
            spikesDmg = 1;
        hazardDamage += spikesDmg;
    }

    if (hazardDamage >= GetMonData(mon, MON_DATA_HP))
        return TRUE;
    return FALSE;
}

enum {
    DONT_PIVOT,
    CAN_TRY_PIVOT,
    PIVOT,
};
bool32 ShouldPivot(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 move, u32 moveIndex)
{
    bool32 hasStatBoost = AnyUsefulStatIsRaised(battlerAtk) || gBattleMons[battlerDef].statStages[STAT_EVASION] >= 9; //Significant boost in evasion for any class
    bool32 shouldSwitch;
    u32 battlerToSwitch;

    shouldSwitch = ShouldSwitch(battlerAtk);
    battlerToSwitch = *(gBattleStruct->AI_monToSwitchIntoId + battlerAtk);

    if (PartyBattlerShouldAvoidHazards(battlerAtk, battlerToSwitch))
        return DONT_PIVOT;

    if (!IsDoubleBattle())
    {
        if (CountUsablePartyMons(battlerAtk) == 0)
            return CAN_TRY_PIVOT; // can't switch, but attack might still be useful

        //TODO - predict opponent switching
        /*if (IsPredictedToSwitch(battlerDef, battlerAtk) && !hasStatBoost)
            return PIVOT; // Try pivoting so you can switch to a better matchup to counter your new opponent*/

        if (AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER) // Attacker goes first
        {
            if (!CanAIFaintTarget(battlerAtk, battlerDef, 0)) // Can't KO foe otherwise
            {
                if (CanAIFaintTarget(battlerAtk, battlerDef, 2))
                {
                    // attacker can kill target in two hits (theoretically)
                    if (CanTargetFaintAi(battlerDef, battlerAtk))
                        return PIVOT;   // Won't get the two turns, pivot

                    if (!IS_MOVE_STATUS(move) && (shouldSwitch
                        || (AtMaxHp(battlerDef) && (AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_FOCUS_SASH
                        || (B_STURDY >= GEN_5 && defAbility == ABILITY_STURDY)
                        || defAbility == ABILITY_MULTISCALE
                        || defAbility == ABILITY_SHADOW_SHIELD))))
                        return PIVOT;   // pivot to break sash/sturdy/multiscale
                }
                else if (!hasStatBoost)
                {
                    if (!IS_MOVE_STATUS(move) && (AtMaxHp(battlerDef) && (AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_FOCUS_SASH
                        || (B_STURDY >= GEN_5 && defAbility == ABILITY_STURDY)
                        || defAbility == ABILITY_MULTISCALE
                        || defAbility == ABILITY_SHADOW_SHIELD)))
                        return PIVOT;   // pivot to break sash/sturdy/multiscale

                    if (shouldSwitch)
                        return PIVOT;

                    /* TODO - check if switchable mon unafffected by/will remove hazards
                    if (gSideStatuses[battlerAtk] & SIDE_STATUS_SPIKES && switchScore >= SWITCHING_INCREASE_CAN_REMOVE_HAZARDS)
                        return PIVOT;*/

                    /*if (BattlerWillFaintFromSecondaryDamage(battlerAtk, AI_DATA->abilities[battlerAtk]) && switchScore >= SWITCHING_INCREASE_WALLS_FOE)
                        return PIVOT;*/

                    /*if (IsClassDamager(class) && switchScore >= SWITCHING_INCREASE_HAS_SUPER_EFFECTIVE_MOVE)
                    {
                        bool32 physMoveInMoveset = PhysicalMoveInMoveset(battlerAtk);
                        bool32 specMoveInMoveset = SpecialMoveInMoveset(battlerAtk);

                        //Pivot if attacking stats are bad
                        if (physMoveInMoveset && !specMoveInMoveset)
                        {
                            if (STAT_STAGE_ATK < 6)
                                return PIVOT;
                        }
                        else if (!physMoveInMoveset && specMoveInMoveset)
                        {
                            if (STAT_STAGE_SPATK < 6)
                                return PIVOT;
                        }
                        else if (physMoveInMoveset && specMoveInMoveset)
                        {
                            if (STAT_STAGE_ATK < 6 && STAT_STAGE_SPATK < 6)
                                return PIVOT;
                        }

                        return CAN_TRY_PIVOT;
                    }*/
                }
            }
        }
        else // Opponent Goes First
        {
            if (CanTargetFaintAi(battlerDef, battlerAtk))
            {
                if (gBattleMoves[move].effect == EFFECT_TELEPORT)
                    return DONT_PIVOT; // If you're going to faint because you'll go second, use a different move
                else
                    return CAN_TRY_PIVOT; // You're probably going to faint anyways so if for some reason you don't, better switch
            }
            else if (CanTargetFaintAiWithMod(battlerDef, battlerAtk, 0, 2)) // Foe can 2HKO AI
            {
                if (CanAIFaintTarget(battlerAtk, battlerDef, 0))
                {
                    if (!BattlerWillFaintFromSecondaryDamage(battlerAtk, AI_DATA->abilities[battlerAtk]))
                        return CAN_TRY_PIVOT; // Use this move to KO if you must
                }
                else // Can't KO the foe
                {
                    return PIVOT;
                }
            }
            else // Foe can 3HKO+ AI
            {
                if (CanAIFaintTarget(battlerAtk, battlerDef, 0))
                {
                    if (!BattlerWillFaintFromSecondaryDamage(battlerAtk, AI_DATA->abilities[battlerAtk]) // This is the only move that can KO
                      && !hasStatBoost) //You're not wasting a valuable stat boost
                    {
                        return CAN_TRY_PIVOT;
                    }
                }
                else if (CanAIFaintTarget(battlerAtk, battlerDef, 2))
                {
                    // can knock out foe in 2 hits
                    if (IS_MOVE_STATUS(move) && (shouldSwitch //Damaging move
                      //&& (switchScore >= SWITCHING_INCREASE_RESIST_ALL_MOVES + SWITCHING_INCREASE_KO_FOE //remove hazards
                     || (AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_FOCUS_SASH && AtMaxHp(battlerDef))))
                        return DONT_PIVOT; // Pivot to break the sash
                    else
                        return CAN_TRY_PIVOT;
                }
                else
                {
                    //if (IsClassDamager(class) && switchScore >= SWITCHING_INCREASE_KO_FOE)
                        //return PIVOT; //Only switch if way better matchup

                    if (!hasStatBoost)
                    {
                        // TODO - check if switching prevents/removes hazards
                        //if (gSideStatuses[battlerAtk] & SIDE_STATUS_SPIKES && switchScore >= SWITCHING_INCREASE_CAN_REMOVE_HAZARDS)
                            //return PIVOT;

                        // TODO - not always a good idea
                        //if (BattlerWillFaintFromSecondaryDamage(battlerAtk) && switchScore >= SWITCHING_INCREASE_HAS_SUPER_EFFECTIVE_MOVE)
                            //return PIVOT;

                        /*if (IsClassDamager(class) && switchScore >= SWITCHING_INCREASE_HAS_SUPER_EFFECTIVE_MOVE)
                        {
                            bool32 physMoveInMoveset = PhysicalMoveInMoveset(battlerAtk);
                            bool32 specMoveInMoveset = SpecialMoveInMoveset(battlerAtk);

                            //Pivot if attacking stats are bad
                            if (physMoveInMoveset && !specMoveInMoveset)
                            {
                                if (STAT_STAGE_ATK < 6)
                                    return PIVOT;
                            }
                            else if (!physMoveInMoveset && specMoveInMoveset)
                            {
                                if (STAT_STAGE_SPATK < 6)
                                    return PIVOT;
                            }
                            else if (physMoveInMoveset && specMoveInMoveset)
                            {
                                if (STAT_STAGE_ATK < 6 && STAT_STAGE_SPATK < 6)
                                    return PIVOT;
                            }
                        }*/

                        return CAN_TRY_PIVOT;
                    }
                }
            }
        }
    }

    return DONT_PIVOT;
}

bool32 CanKnockOffItem(u32 battler, u32 item)
{
    if (item == ITEM_NONE)
        return FALSE;

    if (!(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
      | BATTLE_TYPE_FRONTIER
      | BATTLE_TYPE_LINK
      | BATTLE_TYPE_RECORDED_LINK
      | BATTLE_TYPE_SECRET_BASE
      | (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE ? BATTLE_TYPE_TRAINER : 0)
      )) && GetBattlerSide(battler) == B_SIDE_PLAYER)
        return FALSE;

    if (AI_DATA->abilities[battler] == ABILITY_STICKY_HOLD)
        return FALSE;

    if (!CanBattlerGetOrLoseItem(battler, item))
        return FALSE;

    return TRUE;
}

// status checks
bool32 IsBattlerIncapacitated(u32 battler, u32 ability)
{
    if ((gBattleMons[battler].status1 & STATUS1_FREEZE) && !HasThawingMove(battler))
        return TRUE;    // if battler has thawing move we assume they will definitely use it, and thus being frozen should be neglected

    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
        return TRUE;

    if (gBattleMons[battler].status2 & STATUS2_RECHARGE || (ability == ABILITY_TRUANT && gDisableStructs[battler].truantCounter != 0))
        return TRUE;

    return FALSE;
}

bool32 AI_CanSleep(u32 battler, u32 ability)
{
    if (ability == ABILITY_INSOMNIA
      || ability == ABILITY_VITAL_SPIRIT
      || ability == ABILITY_COMATOSE
      || gBattleMons[battler].status1 & STATUS1_ANY
      || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD
      || (gFieldStatuses & (STATUS_FIELD_MISTY_TERRAIN | STATUS_FIELD_ELECTRIC_TERRAIN))
      || IsAbilityStatusProtected(battler))
        return FALSE;
    return TRUE;
}

bool32 AI_CanPutToSleep(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 move, u32 partnerMove)
{
    if (!AI_CanSleep(battlerDef, defAbility)
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(BATTLE_PARTNER(battlerAtk), battlerDef, partnerMove))   // shouldn't try to sleep mon that partner is trying to make sleep
        return FALSE;
    return TRUE;
}

static bool32 AI_CanPoisonType(u32 battlerAttacker, u32 battlerTarget, u32 move)
{
    return ((AI_DATA->abilities[battlerAttacker] == ABILITY_CORROSION && gBattleMoves[move].split == SPLIT_STATUS)
            || !(IS_BATTLER_OF_TYPE(battlerTarget, TYPE_POISON) || IS_BATTLER_OF_TYPE(battlerTarget, TYPE_STEEL)));
}

static bool32 AI_CanBePoisoned(u32 battlerAtk, u32 battlerDef, u32 move)
{
    u32 ability = AI_DATA->abilities[battlerDef];

    if (!(AI_CanPoisonType(battlerAtk, battlerDef, move))
     || gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SAFEGUARD
     || gBattleMons[battlerDef].status1 & STATUS1_ANY
     || ability == ABILITY_IMMUNITY
     || ability == ABILITY_COMATOSE
     || AI_IsAbilityOnSide(battlerDef, ABILITY_PASTEL_VEIL)
     || gBattleMons[battlerDef].status1 & STATUS1_ANY
     || IsAbilityStatusProtected(battlerDef)
     || AI_IsTerrainAffected(battlerDef, STATUS_FIELD_MISTY_TERRAIN))
        return FALSE;
    return TRUE;
}

bool32 ShouldPoisonSelf(u32 battler, u32 ability)
{
    if (AI_CanBePoisoned(battler, battler, 0) && (
     ability == ABILITY_MARVEL_SCALE
      || ability == ABILITY_POISON_HEAL
      || ability == ABILITY_QUICK_FEET
      || ability == ABILITY_MAGIC_GUARD
      || (ability == ABILITY_TOXIC_BOOST && HasMoveWithSplit(battler, SPLIT_PHYSICAL))
      || (ability == ABILITY_GUTS && HasMoveWithSplit(battler, SPLIT_PHYSICAL))
      || HasMoveEffect(battler, EFFECT_FACADE)
      || HasMoveEffect(battler, EFFECT_PSYCHO_SHIFT)))
        return TRUE;    // battler can be poisoned and has move/ability that synergizes with being poisoned
    return FALSE;
}

bool32 AI_CanPoison(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 move, u32 partnerMove)
{
    if (!AI_CanBePoisoned(battlerAtk, battlerDef, move)
      || AI_GetMoveEffectiveness(move, battlerAtk, battlerDef) == AI_EFFECTIVENESS_x0
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(BATTLE_PARTNER(battlerAtk), battlerDef, partnerMove))
        return FALSE;
    else if (defAbility != ABILITY_CORROSION && (IS_BATTLER_OF_TYPE(battlerDef, TYPE_POISON) || IS_BATTLER_OF_TYPE(battlerDef, TYPE_STEEL)))
        return FALSE;
    else if (IsValidDoubleBattle(battlerAtk) && AI_DATA->abilities[BATTLE_PARTNER(battlerDef)] == ABILITY_PASTEL_VEIL)
        return FALSE;

    return TRUE;
}

static bool32 AI_CanBeParalyzed(u32 battler, u32 ability)
{
    if (ability == ABILITY_LIMBER
      || ability == ABILITY_COMATOSE
      || IS_BATTLER_OF_TYPE(battler, TYPE_ELECTRIC)
      || gBattleMons[battler].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battler))
        return FALSE;
    return TRUE;
}

bool32 AI_CanParalyze(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 move, u32 partnerMove)
{
    if (!AI_CanBeParalyzed(battlerDef, defAbility)
      || AI_GetMoveEffectiveness(move, battlerAtk, battlerDef) == AI_EFFECTIVENESS_x0
      || gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SAFEGUARD
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(BATTLE_PARTNER(battlerAtk), battlerDef, partnerMove))
        return FALSE;
    return TRUE;
}

bool32 AI_CanBeConfused(u32 battler, u32 ability)
{
    if ((gBattleMons[battler].status2 & STATUS2_CONFUSION)
      || (ability == ABILITY_OWN_TEMPO)
      || (IsBattlerGrounded(battler) && (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)))
        return FALSE;
    return TRUE;
}

bool32 AI_CanConfuse(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 battlerAtkPartner, u32 move, u32 partnerMove)
{
    if (!AI_CanBeConfused(battlerDef, defAbility)
      || AI_GetMoveEffectiveness(move, battlerAtk, battlerDef) == AI_EFFECTIVENESS_x0
      || gSideStatuses[GetBattlerSide(battlerDef)] & SIDE_STATUS_SAFEGUARD
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || DoesPartnerHaveSameMoveEffect(battlerAtkPartner, battlerDef, move, partnerMove))
    {
        return FALSE;
    }

    return TRUE;
}

bool32 AI_CanBeBurned(u32 battler, u32 ability)
{
    if (ability == ABILITY_WATER_VEIL
      || ability == ABILITY_WATER_BUBBLE
      || ability == ABILITY_COMATOSE
      || IS_BATTLER_OF_TYPE(battler, TYPE_FIRE)
      || gBattleMons[battler].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battler)
      || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD)
        return FALSE;
    return TRUE;
}

bool32 AI_CanGetFrostbite(u32 battler, u32 ability)
{
    if (ability == ABILITY_MAGMA_ARMOR
      || ability == ABILITY_COMATOSE
      || IS_BATTLER_OF_TYPE(battler, TYPE_ICE)
      || gBattleMons[battler].status1 & STATUS1_ANY
      || IsAbilityStatusProtected(battler)
      || gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD)
        return FALSE;
    return TRUE;
}

bool32 ShouldBurnSelf(u32 battler, u32 ability)
{
    if (AI_CanBeBurned(battler, ability) && (
     ability == ABILITY_QUICK_FEET
      || ability == ABILITY_HEATPROOF
      || ability == ABILITY_MAGIC_GUARD
      || (ability == ABILITY_FLARE_BOOST && HasMoveWithSplit(battler, SPLIT_SPECIAL))
      || (ability == ABILITY_GUTS && HasMoveWithSplit(battler, SPLIT_PHYSICAL))
      || HasMoveEffect(battler, EFFECT_FACADE)
      || HasMoveEffect(battler, EFFECT_PSYCHO_SHIFT)))
        return TRUE;
    return FALSE;
}

bool32 AI_CanBurn(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 battlerAtkPartner, u32 move, u32 partnerMove)
{
    if (!AI_CanBeBurned(battlerDef, defAbility)
      || AI_GetMoveEffectiveness(move, battlerAtk, battlerDef) == AI_EFFECTIVENESS_x0
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(battlerAtkPartner, battlerDef, partnerMove))
    {
        return FALSE;
    }
    return TRUE;
}

bool32 AI_CanGiveFrostbite(u32 battlerAtk, u32 battlerDef, u32 defAbility, u32 battlerAtkPartner, u32 move, u32 partnerMove)
{
    if (!AI_CanGetFrostbite(battlerDef, defAbility)
      || AI_GetMoveEffectiveness(move, battlerAtk, battlerDef) == AI_EFFECTIVENESS_x0
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || PartnerMoveEffectIsStatusSameTarget(battlerAtkPartner, battlerDef, partnerMove))
    {
        return FALSE;
    }
    return TRUE;
}

bool32 AI_CanBeInfatuated(u32 battlerAtk, u32 battlerDef, u32 defAbility)
{
    if ((gBattleMons[battlerDef].status2 & STATUS2_INFATUATION)
      || AI_GetMoveEffectiveness(AI_THINKING_STRUCT->moveConsidered, battlerAtk, battlerDef) == AI_EFFECTIVENESS_x0
      || defAbility == ABILITY_OBLIVIOUS
      || !AreBattlersOfOppositeGender(battlerAtk, battlerDef)
      || AI_IsAbilityOnSide(battlerDef, ABILITY_AROMA_VEIL))
        return FALSE;
    return TRUE;
}

u32 ShouldTryToFlinch(u32 battlerAtk, u32 battlerDef, u32 atkAbility, u32 defAbility, u32 move)
{
    if (((AI_DATA->abilities[battlerAtk] != ABILITY_MOLD_BREAKER && (defAbility == ABILITY_SHIELD_DUST || defAbility == ABILITY_INNER_FOCUS))
      || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_COVERT_CLOAK
      || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
      || AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_SLOWER)) // Opponent goes first
    {
        return 0;
    }
    else if ((atkAbility == ABILITY_SERENE_GRACE
      || gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS
      || gBattleMons[battlerDef].status2 & STATUS2_INFATUATION
      || gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
      || ((AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER) && CanTargetFaintAi(battlerDef, battlerAtk)))
    {
        return 2;   // good idea to flinch
    }

    return 0;   // don't try to flinch
}

bool32 ShouldTrap(u32 battlerAtk, u32 battlerDef, u32 move)
{
    if (BattlerWillFaintFromSecondaryDamage(battlerDef, AI_DATA->abilities[battlerDef]))
        return TRUE;    // battler is taking secondary damage with low HP

    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_STALL)
    {
        if (!CanTargetFaintAi(battlerDef, battlerAtk))
            return TRUE;    // attacker goes first and opponent can't kill us
    }

    return FALSE;
}

bool32 ShouldFakeOut(u32 battlerAtk, u32 battlerDef, u32 move)
{
    if (!gDisableStructs[battlerAtk].isFirstTurn
    || AI_DATA->abilities[battlerAtk] == ABILITY_GORILLA_TACTICS
    || AI_DATA->holdEffects[battlerAtk] == HOLD_EFFECT_CHOICE_BAND
    || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_COVERT_CLOAK
    || DoesSubstituteBlockMove(battlerAtk, battlerDef, move)
    || (AI_DATA->abilities[battlerAtk] != ABILITY_MOLD_BREAKER
    && (AI_DATA->abilities[battlerDef] == ABILITY_SHIELD_DUST || AI_DATA->abilities[battlerDef] == ABILITY_INNER_FOCUS)))
        return FALSE;

    return TRUE;
}

static u32 FindMoveUsedXTurnsAgo(u32 battlerId, u32 x)
{
    s32 i, index = BATTLE_HISTORY->moveHistoryIndex[battlerId];
    for (i = 0; i < x; i++)
    {
        if (--index < 0)
            index = AI_MOVE_HISTORY_COUNT - 1;
    }
    return BATTLE_HISTORY->moveHistory[battlerId][index];
}

bool32 IsWakeupTurn(u32 battler)
{
    // Check if rest was used 2 turns ago
    if ((gBattleMons[battler].status1 & STATUS1_SLEEP) == 1 && FindMoveUsedXTurnsAgo(battler, 2) == MOVE_REST)
        return TRUE;
    else // no way to know
        return FALSE;
}

bool32 AnyPartyMemberStatused(u32 battlerId, bool32 checkSoundproof)
{
    struct Pokemon *party;
    u32 i;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (checkSoundproof && GetMonAbility(&party[i]) == ABILITY_SOUNDPROOF)
            continue;

        if (GetMonData(&party[i], MON_DATA_STATUS) != STATUS1_NONE)
            return TRUE;
    }

    return FALSE;
}

u32 GetBattlerSideSpeedAverage(u32 battler)
{
    u32 speed1 = 0;
    u32 speed2 = 0;
    u32 numBattlersAlive = 0;

    if (IsBattlerAlive(battler))
    {
        speed1 = AI_DATA->speedStats[battler];
        numBattlersAlive++;
    }

    if (IsDoubleBattle() && IsBattlerAlive(BATTLE_PARTNER(battler)))
    {
        speed2 = AI_DATA->speedStats[BATTLE_PARTNER(battler)];
        numBattlersAlive++;
    }

    return (speed1 + speed2) / numBattlersAlive;
}

bool32 ShouldUseRecoilMove(u32 battlerAtk, u32 battlerDef, u32 recoilDmg, u32 moveIndex)
{
    if (recoilDmg >= gBattleMons[battlerAtk].hp //Recoil kills attacker
      && CountUsablePartyMons(battlerDef) != 0) //Foe has more than 1 target left
    {
        if (recoilDmg >= gBattleMons[battlerDef].hp && !CanAIFaintTarget(battlerAtk, battlerDef, 0))
            return TRUE; //If it's the only KO move then just use it
        else
            return FALSE; //Not as good to use move if you'll faint and not win
    }

    return TRUE;
}

bool32 ShouldAbsorb(u32 battlerAtk, u32 battlerDef, u32 move, s32 damage)
{
    if (move == 0xFFFF || AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER)
    {
        // using item or user goes first
        u32 healPercent = (gBattleMoves[move].argument == 0) ? 50 : gBattleMoves[move].argument;
        s32 healDmg = (healPercent * damage) / 100;

        if (gStatuses3[battlerAtk] & STATUS3_HEAL_BLOCK)
            healDmg = 0;

        if (CanTargetFaintAi(battlerDef, battlerAtk)
          && !CanTargetFaintAiWithMod(battlerDef, battlerAtk, healDmg, 0))
            return TRUE;    // target can faint attacker unless they heal
        else if (!CanTargetFaintAi(battlerDef, battlerAtk) && AI_DATA->hpPercents[battlerAtk] < 60 && (Random() % 3))
            return TRUE;    // target can't faint attacker at all, attacker health is about half, 2/3rds rate of encouraging healing
    }
    else
    {
        // opponent goes first
        if (!CanTargetFaintAi(battlerDef, battlerAtk))
            return TRUE;
    }

    return FALSE;
}

bool32 ShouldRecover(u32 battlerAtk, u32 battlerDef, u32 move, u32 healPercent)
{
    if (move == 0xFFFF || AI_WhoStrikesFirst(battlerAtk, battlerDef, move) == AI_IS_FASTER)
    {
        // using item or user going first
        s32 damage = AI_DATA->simulatedDmg[battlerAtk][battlerDef][AI_THINKING_STRUCT->movesetIndex];
        s32 healAmount = (healPercent * damage) / 100;
        if (gStatuses3[battlerAtk] & STATUS3_HEAL_BLOCK)
            healAmount = 0;

        if (CanTargetFaintAi(battlerDef, battlerAtk)
          && !CanTargetFaintAiWithMod(battlerDef, battlerAtk, healAmount, 0))
            return TRUE;    // target can faint attacker unless they heal
        else if (!CanTargetFaintAi(battlerDef, battlerAtk) && AI_DATA->hpPercents[battlerAtk] < 60 && (Random() % 3))
            return TRUE;    // target can't faint attacker at all, attacker health is about half, 2/3rds rate of encouraging healing
    }
    return FALSE;
}

bool32 ShouldSetScreen(u32 battlerAtk, u32 battlerDef, u32 moveEffect)
{
    u32 atkSide = GetBattlerSide(battlerAtk);
    switch (moveEffect)
    {
    case EFFECT_AURORA_VEIL:
        // Use only in Hail and only if AI doesn't already have Reflect, Light Screen or Aurora Veil itself active.
        if ((AI_GetWeather(AI_DATA) & (B_WEATHER_HAIL | B_WEATHER_SNOW))
            && !(gSideStatuses[atkSide] & (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL)))
            return TRUE;
        break;
    case EFFECT_REFLECT:
        // Use only if the player has a physical move and AI doesn't already have Reflect itself active.
        if (HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL)
            && !(gSideStatuses[atkSide] & SIDE_STATUS_REFLECT))
            return TRUE;
        break;
    case EFFECT_LIGHT_SCREEN:
        // Use only if the player has a special move and AI doesn't already have Light Screen itself active.
        if (HasMoveWithSplit(battlerDef, SPLIT_SPECIAL)
            && !(gSideStatuses[atkSide] & SIDE_STATUS_LIGHTSCREEN))
            return TRUE;
        break;
    }

    return FALSE;
}

// Partner Logic
bool32 IsValidDoubleBattle(u32 battlerAtk)
{
    if (IsDoubleBattle()
      && ((IsBattlerAlive(BATTLE_OPPOSITE(battlerAtk)) && IsBattlerAlive(BATTLE_PARTNER(BATTLE_OPPOSITE(battlerAtk)))) || IsBattlerAlive(BATTLE_PARTNER(battlerAtk))))
        return TRUE;
    return FALSE;
}

u32 GetAllyChosenMove(u32 battlerId)
{
    u32 partnerBattler = BATTLE_PARTNER(battlerId);

    if (!IsBattlerAlive(partnerBattler) || !IsAiBattlerAware(partnerBattler))
        return MOVE_NONE;
    else if (partnerBattler > battlerId) // Battler with the lower id chooses the move first.
        return gLastMoves[partnerBattler];
    else
        return gBattleMons[partnerBattler].moves[gBattleStruct->chosenMovePositions[partnerBattler]];
}

//PARTNER_MOVE_EFFECT_IS_SAME
bool32 DoesPartnerHaveSameMoveEffect(u32 battlerAtkPartner, u32 battlerDef, u32 move, u32 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;

    if (gBattleMoves[move].effect == gBattleMoves[partnerMove].effect
      && partnerMove != MOVE_NONE
      && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef)
    {
        return TRUE;
    }
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_SAME_NO_TARGET
bool32 PartnerHasSameMoveEffectWithoutTarget(u32 battlerAtkPartner, u32 move, u32 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;

    if (gBattleMoves[move].effect == gBattleMoves[partnerMove].effect
      && partnerMove != MOVE_NONE)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_STATUS_SAME_TARGET
bool32 PartnerMoveEffectIsStatusSameTarget(u32 battlerAtkPartner, u32 battlerDef, u32 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;

    if (partnerMove != MOVE_NONE
     && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef
     && (gBattleMoves[partnerMove].effect == EFFECT_SLEEP
       || gBattleMoves[partnerMove].effect == EFFECT_POISON
       || gBattleMoves[partnerMove].effect == EFFECT_TOXIC
       || gBattleMoves[partnerMove].effect == EFFECT_PARALYZE
       || gBattleMoves[partnerMove].effect == EFFECT_WILL_O_WISP
       || gBattleMoves[partnerMove].effect == EFFECT_YAWN))
        return TRUE;
    return FALSE;
}

bool32 IsMoveEffectWeather(u32 move)
{
    if (move != MOVE_NONE
     && (gBattleMoves[move].effect == EFFECT_SUNNY_DAY
      || gBattleMoves[move].effect == EFFECT_RAIN_DANCE
      || gBattleMoves[move].effect == EFFECT_SANDSTORM
      || gBattleMoves[move].effect == EFFECT_HAIL
      || gBattleMoves[move].effect == EFFECT_SNOWSCAPE))
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_EFFECT_IS_TERRAIN
bool32 PartnerMoveEffectIsTerrain(u32 battlerAtkPartner, u32 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;

    if (partnerMove != MOVE_NONE
     && (gBattleMoves[partnerMove].effect == EFFECT_GRASSY_TERRAIN
      || gBattleMoves[partnerMove].effect == EFFECT_MISTY_TERRAIN
      || gBattleMoves[partnerMove].effect == EFFECT_ELECTRIC_TERRAIN
      || gBattleMoves[partnerMove].effect == EFFECT_PSYCHIC_TERRAIN))
        return TRUE;

    return FALSE;
}

//PARTNER_MOVE_IS_TAILWIND_TRICKROOM
bool32 PartnerMoveIs(u32 battlerAtkPartner, u32 partnerMove, u32 moveCheck)
{
    if (!IsDoubleBattle())
        return FALSE;

    if (partnerMove != MOVE_NONE && partnerMove == moveCheck)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_IS_SAME
bool32 PartnerMoveIsSameAsAttacker(u32 battlerAtkPartner, u32 battlerDef, u32 move, u32 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;

    if (partnerMove != MOVE_NONE && move == partnerMove && gBattleStruct->moveTarget[battlerAtkPartner] == battlerDef)
        return TRUE;
    return FALSE;
}

//PARTNER_MOVE_IS_SAME_NO_TARGET
bool32 PartnerMoveIsSameNoTarget(u32 battlerAtkPartner, u32 move, u32 partnerMove)
{
    if (!IsDoubleBattle())
        return FALSE;
    if (partnerMove != MOVE_NONE && move == partnerMove)
        return TRUE;
    return FALSE;
}

bool32 ShouldUseWishAromatherapy(u32 battlerAtk, u32 battlerDef, u32 move)
{
    u32 i;
    s32 firstId, lastId;
    struct Pokemon* party;
    bool32 hasStatus = FALSE;
    bool32 needHealing = FALSE;

    GetAIPartyIndexes(battlerAtk, &firstId, &lastId);

    if (GetBattlerSide(battlerAtk) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (CountUsablePartyMons(battlerAtk) == 0
      && (CanTargetFaintAi(battlerDef, battlerAtk) || BattlerWillFaintFromSecondaryDamage(battlerAtk, AI_DATA->abilities[battlerAtk])))
        return FALSE; // Don't heal if last mon and will faint

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 currHp = GetMonData(&party[i], MON_DATA_HP);
        u32 maxHp = GetMonData(&party[i], MON_DATA_MAX_HP);

        if (!GetMonData(&party[i], MON_DATA_IS_EGG, NULL) && currHp > 0)
        {
            if ((currHp * 100) / maxHp < 65 // Less than 65% health remaining
              && i >= firstId && i < lastId) // Can only switch to mon on your team
            {
                needHealing = TRUE;
            }

            if (GetMonData(&party[i], MON_DATA_STATUS, NULL) != STATUS1_NONE)
            {
                if (move != MOVE_HEAL_BELL || GetMonAbility(&party[i]) != ABILITY_SOUNDPROOF)
                    hasStatus = TRUE;
            }
        }
    }

    if (!IsDoubleBattle())
    {
        switch (gBattleMoves[move].effect)
        {
        case EFFECT_WISH:
            if (needHealing)
                return TRUE;
            break;
        case EFFECT_HEAL_BELL:
            if (hasStatus)
                return TRUE;
        }
    }
    else
    {
        switch (gBattleMoves[move].effect)
        {
        case EFFECT_WISH:
            return ShouldRecover(battlerAtk, battlerDef, move, 50); // Switch recovery isn't good idea in doubles
        case EFFECT_HEAL_BELL:
            if (hasStatus)
                return TRUE;
        }
    }

    return FALSE;
}

#define SIZE_G_BATTLE_MONS (sizeof(struct BattlePokemon) * MAX_BATTLERS_COUNT)

struct BattlePokemon *AllocSaveBattleMons(void)
{
    struct BattlePokemon *savedBattleMons = Alloc(SIZE_G_BATTLE_MONS);
    memcpy(savedBattleMons, gBattleMons, SIZE_G_BATTLE_MONS);
    return savedBattleMons;
}

void FreeRestoreBattleMons(struct BattlePokemon *savedBattleMons)
{
    memcpy(gBattleMons, savedBattleMons, SIZE_G_BATTLE_MONS);
    Free(savedBattleMons);
}

// party logic
s32 AI_CalcPartyMonDamage(u32 move, u32 battlerAtk, u32 battlerDef, struct BattlePokemon switchinCandidate, bool8 isPartyMonAttacker)
{
    s32 dmg;
    u8 effectiveness;
    struct BattlePokemon *savedBattleMons = AllocSaveBattleMons();
    if(isPartyMonAttacker)
        gBattleMons[battlerAtk] = switchinCandidate;
    else
        gBattleMons[battlerDef] = switchinCandidate;
    dmg = AI_CalcDamage(move, battlerAtk, battlerDef, &effectiveness, FALSE, AI_GetWeather(AI_DATA));
    FreeRestoreBattleMons(savedBattleMons);
    return dmg;
}

s32 CountUsablePartyMons(u32 battlerId)
{
    s32 battlerOnField1, battlerOnField2, i, ret;
    struct Pokemon *party;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battlerId)))];
    }
    else // In singles there's only one battlerId by side.
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[battlerId];
    }

    ret = 0;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != battlerOnField1 && i != battlerOnField2
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
        {
            ret++;
        }
    }

    return ret;
}

bool32 IsPartyFullyHealedExceptBattler(u32 battlerId)
{
    struct Pokemon *party;
    u32 i;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != gBattlerPartyIndexes[battlerId]
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
         && GetMonData(&party[i], MON_DATA_HP) < GetMonData(&party[i], MON_DATA_MAX_HP))
            return FALSE;
    }
    return TRUE;
}

bool32 PartyHasMoveSplit(u32 battlerId, u32 split)
{
    struct Pokemon *party = GetBattlerParty(battlerId);
    u32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP, NULL) == 0)
            continue;

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            u32 move = GetMonData(&party[i], MON_DATA_MOVE1 + j, NULL);
            u32 pp = GetMonData(&party[i], MON_DATA_PP1 + j, NULL);

            if (pp > 0 && move != MOVE_NONE)
            {
                //TODO - handle photon geyser, light that burns the sky
                if (gBattleMoves[move].split == split)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

bool32 SideHasMoveSplit(u32 battlerId, u32 split)
{
    if (IsDoubleBattle())
    {
        if (HasMoveWithSplit(battlerId, split) || HasMoveWithSplit(BATTLE_PARTNER(battlerId), split))
            return TRUE;
    }
    else
    {
        if (HasMoveWithSplit(battlerId, split))
            return TRUE;
    }
    return FALSE;
}

bool32 IsAbilityOfRating(u32 ability, s8 rating)
{
    if (sAiAbilityRatings[ability] >= rating)
        return TRUE;
    return FALSE;
}

s8 GetAbilityRating(u32 ability)
{
    return sAiAbilityRatings[ability];
}

static const u16 sRecycleEncouragedItems[] =
{
    ITEM_CHESTO_BERRY,
    ITEM_LUM_BERRY,
    ITEM_STARF_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_MICLE_BERRY,
    ITEM_CUSTAP_BERRY,
    ITEM_MENTAL_HERB,
    ITEM_FOCUS_SASH,
    // TODO expand this
};

// Its assumed that the berry is strategically given, so no need to check benefits of the berry
bool32 IsStatBoostingBerry(u32 item)
{
    switch (item)
    {
    case ITEM_LIECHI_BERRY:
    case ITEM_GANLON_BERRY:
    case ITEM_SALAC_BERRY:
    case ITEM_PETAYA_BERRY:
    case ITEM_APICOT_BERRY:
    //case ITEM_LANSAT_BERRY:
    case ITEM_STARF_BERRY:
    case ITEM_MICLE_BERRY:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 ShouldRestoreHpBerry(u32 battlerAtk, u32 item)
{
    switch (item)
    {
    case ITEM_ORAN_BERRY:
        if (gBattleMons[battlerAtk].maxHP <= 50)
            return TRUE;    // Only worth it in the early game
        return FALSE;
    case ITEM_SITRUS_BERRY:
    case ITEM_FIGY_BERRY:
    case ITEM_WIKI_BERRY:
    case ITEM_MAGO_BERRY:
    case ITEM_AGUAV_BERRY:
    case ITEM_IAPAPA_BERRY:
        return TRUE;
    default:
        return FALSE;
    }
}

bool32 IsRecycleEncouragedItem(u32 item)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRecycleEncouragedItems); i++)
    {
        if (item == sRecycleEncouragedItems[i])
            return TRUE;
    }
    return FALSE;
}

// score increases
#define STAT_UP_2_STAGE     8
#define STAT_UP_STAGE       10
void IncreaseStatUpScore(u32 battlerAtk, u32 battlerDef, u32 statId, s32 *score)
{
    if (AI_DATA->abilities[battlerAtk] == ABILITY_CONTRARY)
        return;

    if (AI_DATA->hpPercents[battlerAtk] < 80 && AI_RandLessThan(128))
        return;

    if ((AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return; // Damaging moves would get a score boost from AI_TryToFaint or PreferStrongestMove so we don't consider them here

    switch (statId)
    {
    case STAT_ATK:
        if (HasMoveWithSplit(battlerAtk, SPLIT_PHYSICAL) && AI_DATA->hpPercents[battlerAtk] > 40)
        {
            if (gBattleMons[battlerAtk].statStages[STAT_ATK] < STAT_UP_2_STAGE)
                ADJUST_SCORE_PTR(2);
            else if (gBattleMons[battlerAtk].statStages[STAT_ATK] < STAT_UP_STAGE)
                ADJUST_SCORE_PTR(1);
        }
        if (HasMoveEffect(battlerAtk, EFFECT_FOUL_PLAY))
            ADJUST_SCORE_PTR(1);
        break;
    case STAT_DEF:
        if ((HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL)|| IS_MOVE_PHYSICAL(gLastMoves[battlerDef]))
          && AI_DATA->hpPercents[battlerAtk] > 70)
        {
            if (gBattleMons[battlerAtk].statStages[STAT_DEF] < STAT_UP_2_STAGE)
                ADJUST_SCORE_PTR(2); // seems better to raise def at higher HP
            else if (gBattleMons[battlerAtk].statStages[STAT_DEF] < STAT_UP_STAGE)
                ADJUST_SCORE_PTR(1);
        }
        break;
    case STAT_SPEED:
        if (!AI_STRIKES_FIRST(battlerAtk, battlerDef, AI_THINKING_STRUCT->moveConsidered))
        {
            if (gBattleMons[battlerAtk].statStages[STAT_SPEED] < STAT_UP_2_STAGE)
                ADJUST_SCORE_PTR(2);
            else if (gBattleMons[battlerAtk].statStages[STAT_SPEED] < STAT_UP_STAGE)
                ADJUST_SCORE_PTR(1);
        }
        break;
    case STAT_SPATK:
        if (HasMoveWithSplit(battlerAtk, SPLIT_SPECIAL) && AI_DATA->hpPercents[battlerAtk] > 40)
        {
            if (gBattleMons[battlerAtk].statStages[STAT_SPATK] < STAT_UP_2_STAGE)
                ADJUST_SCORE_PTR(2);
            else if (gBattleMons[battlerAtk].statStages[STAT_SPATK] < STAT_UP_STAGE)
                ADJUST_SCORE_PTR(1);
        }
        break;
    case STAT_SPDEF:
        if ((HasMoveWithSplit(battlerDef, SPLIT_SPECIAL) || IS_MOVE_SPECIAL(gLastMoves[battlerDef]))
          && AI_DATA->hpPercents[battlerAtk] > 70)
        {
            if (gBattleMons[battlerAtk].statStages[STAT_SPDEF] < STAT_UP_2_STAGE)
                ADJUST_SCORE_PTR(2); // seems better to raise spdef at higher HP
            else if (gBattleMons[battlerAtk].statStages[STAT_SPDEF] < STAT_UP_STAGE)
                ADJUST_SCORE_PTR(1);
        }
        break;
    case STAT_ACC:
        if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 80, TRUE, AI_DATA->abilities[battlerAtk], AI_DATA->abilities[battlerDef], AI_DATA->holdEffects[battlerAtk], AI_DATA->holdEffects[battlerDef]))
            ADJUST_SCORE_PTR(2); // has moves with less than 80% accuracy
        else if (HasMoveWithLowAccuracy(battlerAtk, battlerDef, 90, TRUE, AI_DATA->abilities[battlerAtk], AI_DATA->abilities[battlerDef], AI_DATA->holdEffects[battlerAtk], AI_DATA->holdEffects[battlerDef]))
            ADJUST_SCORE_PTR(1);
        break;
    case STAT_EVASION:
        if (!BattlerWillFaintFromWeather(battlerAtk, AI_DATA->abilities[battlerAtk]))
        {
            if (!GetBattlerSecondaryDamage(battlerAtk) && !(gStatuses3[battlerAtk] & STATUS3_ROOTED))
                ADJUST_SCORE_PTR(2);
            else
                ADJUST_SCORE_PTR(1);
        }
        break;
    }
}

void IncreasePoisonScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score)
{
    if (((AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
    || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_PSN || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanPoison(battlerAtk, battlerDef, AI_DATA->abilities[battlerDef], move, AI_DATA->partnerMove) && AI_DATA->hpPercents[battlerDef] > 20)
    {
        if (!HasDamagingMove(battlerDef))
            ADJUST_SCORE_PTR(2);

        if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_STALL && HasMoveEffect(battlerAtk, EFFECT_PROTECT))
            ADJUST_SCORE_PTR(1);    // stall tactic

        if (HasMoveEffect(battlerAtk, EFFECT_VENOSHOCK)
          || HasMoveEffect(battlerAtk, EFFECT_HEX)
          || HasMoveEffect(battlerAtk, EFFECT_VENOM_DRENCH)
          || AI_DATA->abilities[battlerAtk] == ABILITY_MERCILESS)
            ADJUST_SCORE_PTR(2);
        else
            ADJUST_SCORE_PTR(1);
    }
}

void IncreaseBurnScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score)
{
    if (((AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
    || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_BRN || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanBurn(battlerAtk, battlerDef, AI_DATA->abilities[battlerDef], BATTLE_PARTNER(battlerAtk), move, AI_DATA->partnerMove))
    {
        ADJUST_SCORE_PTR(1); // burning is good
        if (HasMoveWithSplit(battlerDef, SPLIT_PHYSICAL))
        {
            if (CanTargetFaintAi(battlerDef, battlerAtk))
                ADJUST_SCORE_PTR(2); // burning the target to stay alive is cool
        }

        if (HasMoveEffect(battlerAtk, EFFECT_HEX) || HasMoveEffect(BATTLE_PARTNER(battlerAtk), EFFECT_HEX))
            ADJUST_SCORE_PTR(1);
    }
}

void IncreaseParalyzeScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score)
{
    if (((AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
    || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_PAR || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanParalyze(battlerAtk, battlerDef, AI_DATA->abilities[battlerDef], move, AI_DATA->partnerMove))
    {
        u32 atkSpeed = AI_DATA->speedStats[battlerAtk];
        u32 defSpeed = AI_DATA->speedStats[battlerDef];

        if ((defSpeed >= atkSpeed && defSpeed / 2 < atkSpeed) // You'll go first after paralyzing foe
          || HasMoveEffect(battlerAtk, EFFECT_HEX)
          || HasMoveEffect(battlerAtk, EFFECT_FLINCH_HIT)
          || gBattleMons[battlerDef].status2 & STATUS2_INFATUATION
          || gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
            ADJUST_SCORE_PTR(4);
        else
            ADJUST_SCORE_PTR(2);
    }
}

void IncreaseSleepScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score)
{
    if (((AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
    || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_SLP || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanPutToSleep(battlerAtk, battlerDef, AI_DATA->abilities[battlerDef], move, AI_DATA->partnerMove))
        ADJUST_SCORE_PTR(2);
    else
        return;

    if ((HasMoveEffect(battlerAtk, EFFECT_DREAM_EATER) || HasMoveEffect(battlerAtk, EFFECT_NIGHTMARE))
      && !(HasMoveEffect(battlerDef, EFFECT_SNORE) || HasMoveEffect(battlerDef, EFFECT_SLEEP_TALK)))
        ADJUST_SCORE_PTR(1);

    if (HasMoveEffect(battlerAtk, EFFECT_HEX) || HasMoveEffect(BATTLE_PARTNER(battlerAtk), EFFECT_HEX))
        ADJUST_SCORE_PTR(1);
}

void IncreaseConfusionScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score)
{
    if (((AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
    || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_CONFUSION || AI_DATA->holdEffects[battlerDef] == HOLD_EFFECT_CURE_STATUS)
        return;

    if (AI_CanConfuse(battlerAtk, battlerDef, AI_DATA->abilities[battlerDef], BATTLE_PARTNER(battlerAtk), move, AI_DATA->partnerMove)
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CURE_CONFUSION
      && AI_DATA->holdEffects[battlerDef] != HOLD_EFFECT_CURE_STATUS)
    {
        if (gBattleMons[battlerDef].status1 & STATUS1_PARALYSIS
          || gBattleMons[battlerDef].status2 & STATUS2_INFATUATION
          || (AI_DATA->abilities[battlerAtk] == ABILITY_SERENE_GRACE && HasMoveEffect(battlerAtk, EFFECT_FLINCH_HIT)))
            ADJUST_SCORE_PTR(3);
        else
            ADJUST_SCORE_PTR(2);
    }
}

void IncreaseFrostbiteScore(u32 battlerAtk, u32 battlerDef, u32 move, s32 *score)
{
    if ((AI_THINKING_STRUCT->aiFlags & AI_FLAG_TRY_TO_FAINT) && CanAIFaintTarget(battlerAtk, battlerDef, 0))
        return;

    if (AI_CanGiveFrostbite(battlerAtk, battlerDef, AI_DATA->abilities[battlerDef], BATTLE_PARTNER(battlerAtk), move, AI_DATA->partnerMove))
    {
        ADJUST_SCORE_PTR(1); // frostbite is good
        if (HasMoveWithSplit(battlerDef, SPLIT_SPECIAL))
        {
            if (CanTargetFaintAi(battlerDef, battlerAtk))
                ADJUST_SCORE_PTR(2); // frostbiting the target to stay alive is cool
        }

        if (HasMoveEffect(battlerAtk, EFFECT_HEX) || HasMoveEffect(BATTLE_PARTNER(battlerAtk), EFFECT_HEX))
            ADJUST_SCORE_PTR(1);
    }
}

bool32 AI_MoveMakesContact(u32 ability, u32 holdEffect, u32 move)
{
    if (gBattleMoves[move].makesContact
      && ability != ABILITY_LONG_REACH
      && holdEffect != HOLD_EFFECT_PROTECTIVE_PADS)
        return TRUE;
    return FALSE;
}

//TODO - this could use some more sophisticated logic
bool32 ShouldUseZMove(u32 battlerAtk, u32 battlerDef, u32 chosenMove)
{
    // simple logic. just upgrades chosen move to z move if possible, unless regular move would kill opponent
    if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && battlerDef == BATTLE_PARTNER(battlerAtk))
        return FALSE; //don't use z move on partner
    if (gBattleStruct->zmove.used[battlerAtk])
        return FALSE;   //cant use z move twice

    if (IsViableZMove(battlerAtk, chosenMove))
    {
        u8 effectiveness;

        if (gBattleMons[battlerDef].ability == ABILITY_DISGUISE && gBattleMons[battlerDef].species == SPECIES_MIMIKYU_DISGUISED)
            return FALSE; // Don't waste a Z-Move busting disguise
        if (gBattleMons[battlerDef].ability == ABILITY_ICE_FACE && gBattleMons[battlerDef].species == SPECIES_EISCUE_ICE_FACE && IS_MOVE_PHYSICAL(chosenMove))
            return FALSE; // Don't waste a Z-Move busting Ice Face

        if (IS_MOVE_STATUS(chosenMove) && !IS_MOVE_STATUS(gBattleStruct->zmove.chosenZMove))
            return FALSE;
        else if (!IS_MOVE_STATUS(chosenMove) && IS_MOVE_STATUS(gBattleStruct->zmove.chosenZMove))
            return FALSE;

        if (!IS_MOVE_STATUS(chosenMove) && AI_CalcDamageSaveBattlers(chosenMove, battlerAtk, battlerDef, &effectiveness, FALSE) >= gBattleMons[battlerDef].hp)
            return FALSE;   // don't waste damaging z move if can otherwise faint target

        return TRUE;
    }

    return FALSE;
}

bool32 AI_IsBattlerAsleepOrComatose(u32 battlerId)
{
    return (gBattleMons[battlerId].status1 & STATUS1_SLEEP) || AI_DATA->abilities[battlerId] == ABILITY_COMATOSE;
}

u32 AI_CalcSecondaryEffectChance(u32 battler, u32 secondaryEffectChance)
{
    if (AI_DATA->abilities[battler] == ABILITY_SERENE_GRACE)
        secondaryEffectChance *= 2;

    return secondaryEffectChance;
}
