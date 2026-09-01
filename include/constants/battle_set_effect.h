#ifndef GUARD_CONSTANTS_BATTLE_SET_EFFECT_H
#define GUARD_CONSTANTS_BATTLE_SET_EFFECT_H

// Explicit numbers until frostbite because those shouldn't be shifted
enum __attribute__((packed)) MoveEffect
{
    MOVE_EFFECT_NONE = 0,
    MOVE_EFFECT_SLEEP = 1,
    MOVE_EFFECT_POISON = 2,
    MOVE_EFFECT_BURN = 3,
    MOVE_EFFECT_FREEZE = 4,
    MOVE_EFFECT_PARALYSIS = 5,
    MOVE_EFFECT_TOXIC = 6,
    MOVE_EFFECT_FROSTBITE = 7,
    MOVE_EFFECT_CONFUSION,
    MOVE_EFFECT_FLINCH,
    MOVE_EFFECT_ABSORB,
    MOVE_EFFECT_RANDOM_FROM_LIST, // Uses randomMoveEffects to determine what to select
    MOVE_EFFECT_UPROAR,
    MOVE_EFFECT_PAYDAY,
    MOVE_EFFECT_WRAP,
    MOVE_EFFECT_STAT_PLUS,
    MOVE_EFFECT_STAT_MINUS,

    MOVE_EFFECT_REMOVE_ARG_TYPE,
    MOVE_EFFECT_RECHARGE,
    MOVE_EFFECT_RAGE,
    MOVE_EFFECT_PREVENT_ESCAPE,
    MOVE_EFFECT_NIGHTMARE,
    MOVE_EFFECT_GLAIVE_RUSH,
    MOVE_EFFECT_REMOVE_STATUS,
    MOVE_EFFECT_THRASH,
    MOVE_EFFECT_CLEAR_SMOG,
    MOVE_EFFECT_FLAME_BURST,
    MOVE_EFFECT_FEINT,
    MOVE_EFFECT_HAPPY_HOUR,
    MOVE_EFFECT_CORE_ENFORCER,
    MOVE_EFFECT_THROAT_CHOP,
    MOVE_EFFECT_INCINERATE,
    MOVE_EFFECT_BUG_BITE,
    MOVE_EFFECT_RECOIL_HP_25,
    MOVE_EFFECT_TRAP_BOTH,
    MOVE_EFFECT_ROUND,
    MOVE_EFFECT_SYRUP_BOMB,
    MOVE_EFFECT_FLORAL_HEALING,
    MOVE_EFFECT_SECRET_POWER,
    MOVE_EFFECT_PSYCHIC_NOISE,
    MOVE_EFFECT_TERA_BLAST,
    MOVE_EFFECT_ORDER_UP,
    MOVE_EFFECT_ION_DELUGE,
    MOVE_EFFECT_HAZE,
    MOVE_EFFECT_LEECH_SEED,
    MOVE_EFFECT_REFLECT,
    MOVE_EFFECT_LIGHT_SCREEN,
    MOVE_EFFECT_SALT_CURE,
    MOVE_EFFECT_EERIE_SPELL,
    MOVE_EFFECT_FLING, // If used without EFFECT_FLING, the move will be a regular damage move with fling as an additional effect without the failure and dmg modifier parts
    MOVE_EFFECT_RAINBOW,
    MOVE_EFFECT_SEA_OF_FIRE,
    MOVE_EFFECT_SWAMP,

    // Max move effects happen earlier in the execution chain.
    // For example stealth rock from G-Max Stonesurge is set up before abilities but from Stone Axe after.
    // Stone Axe can also fail to set up rocks if user faints where as Stonesurge will always go up.
    // This means we need to be careful if we want to re-use those effects for (new) vanilla moves
    MOVE_EFFECT_SUN,
    MOVE_EFFECT_RAIN,
    MOVE_EFFECT_SANDSTORM,
    MOVE_EFFECT_HAIL,
    MOVE_EFFECT_MISTY_TERRAIN,
    MOVE_EFFECT_GRASSY_TERRAIN,
    MOVE_EFFECT_ELECTRIC_TERRAIN,
    MOVE_EFFECT_PSYCHIC_TERRAIN,
    MOVE_EFFECT_VINE_LASH,
    MOVE_EFFECT_WILDFIRE,
    MOVE_EFFECT_CANNONADE,
    MOVE_EFFECT_EFFECT_SPORE_SIDE,
    MOVE_EFFECT_PARALYZE_SIDE,
    MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE,
    MOVE_EFFECT_CRIT_PLUS_SIDE,
    MOVE_EFFECT_PREVENT_ESCAPE_SIDE,
    MOVE_EFFECT_AURORA_VEIL,
    MOVE_EFFECT_INFATUATE_SIDE,
    MOVE_EFFECT_RECYCLE_BERRIES,
    MOVE_EFFECT_POISON_SIDE,
    MOVE_EFFECT_DEFOG,
    MOVE_EFFECT_POISON_PARALYZE_SIDE,
    MOVE_EFFECT_HEAL_TEAM,
    MOVE_EFFECT_SPITE,
    MOVE_EFFECT_GRAVITY,
    MOVE_EFFECT_VOLCALITH,
    MOVE_EFFECT_SANDBLAST_SIDE,
    MOVE_EFFECT_YAWN_FOE,
    MOVE_EFFECT_AROMATHERAPY,
    MOVE_EFFECT_CONFUSE_SIDE,
    MOVE_EFFECT_STEELSURGE, // Steel type rocks
    MOVE_EFFECT_STEALTH_ROCK, // Max Move rocks, not to be confused with rocks set up from Ceasless Edge (same but differ in execution order)
    MOVE_EFFECT_TORMENT_SIDE,
    MOVE_EFFECT_FIRE_SPIN_SIDE,
    MOVE_EFFECT_FIXED_POWER, // This has no real use outside of dmax moves
    // Max move effects end. They can be used for (custom) normal moves.

    // For status stat change moves
    STAT_CHANGE_EFFECT_PLUS,
    STAT_CHANGE_EFFECT_MINUS,

    // Move effects that happen before the move hits. Set in SetPreAttackMoveEffect
    MOVE_EFFECT_BREAK_SCREEN,
    MOVE_EFFECT_STEAL_STATS,
    MOVE_EFFECT_BEAT_UP_MESSAGE, // Handles the message printing for gen2, 3 and 4
    MOVE_EFFECT_ITEM_MESSAGE, // Handles the flung item and attacked by its item messages (Fling, Poltergeist)

    // Only for secret power usage but better to remove/refactor the abstraction
    // renamed so that users don't think those are usable constatns
    SECRET_POWER_ATK_MINUS_1,
    SECRET_POWER_DEF_MINUS_1,
    SECRET_POWER_SPD_MINUS_1,
    SECRET_POWER_SP_ATK_MINUS_1,
    SECRET_POWER_ACC_MINUS_1,

    NUM_MOVE_EFFECTS
};

#if B_USE_FROSTBITE == TRUE
#define MOVE_EFFECT_FREEZE_OR_FROSTBITE MOVE_EFFECT_FROSTBITE
#else
#define MOVE_EFFECT_FREEZE_OR_FROSTBITE MOVE_EFFECT_FREEZE
#endif

enum SetMoveEffectFlags
{
    NO_FLAGS          = 0,
    EFFECT_PRIMARY    = (1 << 0),
    EFFECT_CERTAIN    = (1 << 1),
    EFFECT_ON_SIDE    = (1 << 2),
};

#endif // GUARD_CONSTANTS_BATTLE_SET_EFFECT_H
