#include "global.h"
#include "test/battle.h"
#include "battle_anim_scripts.h"

// These tests are very heavy computationally. Only use them to review animation PRs.

#define ANIM_TEST_START_MOVE 1              //  First move to test
#define ANIM_TEST_END_MOVE   MOVES_COUNT-1  //  Last move to test

static void ParametrizeMovesAndSpecies(u32 j, enum Move *pMove, enum Species *pSpecies, u32 variation)
{
    enum BattleMoveEffects effect = GetMoveEffect(j);
    if (effect == EFFECT_DARK_VOID) // User needs to be Darkrai
    {
        *pMove = j;
        *pSpecies = SPECIES_DARKRAI;
    }
    else if (effect == EFFECT_HYPERSPACE_FURY) // User needs to be Hoopa Unbound
    {
        *pMove = j;
        *pSpecies = SPECIES_HOOPA_UNBOUND;
    }
    else if (effect == EFFECT_AURA_WHEEL) // User needs to be Morpeko
    {
        *pMove = j;
        *pSpecies = SPECIES_MORPEKO_FULL_BELLY;
    }
    else if (effect == EFFECT_ROTOTILLER || effect == EFFECT_FLOWER_SHIELD) // User needs to be Grass-type
    {
        *pMove = j;
        *pSpecies = SPECIES_TANGELA;
    }
    else if (effect == EFFECT_FAIL_IF_NOT_ARG_TYPE && GetMoveArgType(j) == TYPE_FIRE) // User needs to be Fire-type
    {
        *pMove = j;
        *pSpecies = SPECIES_FLAREON;
    }
    else if (effect == EFFECT_FAIL_IF_NOT_ARG_TYPE && GetMoveArgType(j) == TYPE_ELECTRIC) // User needs to be Electric-type
    {
        *pMove = j;
        *pSpecies = SPECIES_JOLTEON;
    }
    else if (effect == EFFECT_STAT_CHANGE_MAGNETIC) // User needs to have Plus
    {
        *pMove = j;
        *pSpecies = SPECIES_KLINKLANG;
    }
    else if (effect == EFFECT_PLACEHOLDER) // Ignore placeholder *pMoves
    {
        *pMove = MOVE_POUND;
        *pSpecies = SPECIES_WOBBUFFET;
    }
    else // Everything else
    {
        *pMove = j;
        *pSpecies = SPECIES_WOBBUFFET;
    }
}

static u32 ParametrizeFriendship(enum Move move, u32 variation)
{
    if (gMovesInfo[move].effect == EFFECT_FRUSTRATION
        || gMovesInfo[move].effect == EFFECT_RETURN
        )
    {
        if (variation == 0)
           return 1;
        else if (variation == 1)
            return 61;
        else if (variation == 2)
            return 101;
        else if (variation == 3)
            return 201;
    }
    return 0;
}

static u32 GetParametrizedHP(enum Move move, u32 variation)
{
    if (gMovesInfo[move].effect == EFFECT_POWER_BASED_ON_USER_HP && variation > 0)
    {
        if (variation == 1)
            return 6000;
        else if (variation == 2)
            return 4000;
        else if (variation == 3)
            return 2000;
    }
    return 9997;
}

static enum Item GetParametrizedItem(enum Move move, u32 variation)
{
    if ((move == MOVE_TECHNO_BLAST) && variation > 0)
    {
        if (variation == 1)
            return ITEM_DOUSE_DRIVE;
        else if (variation == 2)
            return ITEM_SHOCK_DRIVE;
        else if (variation == 3)
            return ITEM_BURN_DRIVE;
        else if (variation == 4)
            return ITEM_CHILL_DRIVE;
    }
    return ITEM_ORAN_BERRY;
}

static u32 GetParametrizedLevel(enum Move move, u32 variation)
{
    if (gMovesInfo[move].effect == EFFECT_LEVEL_DAMAGE && variation > 0)
    {
        if (variation == 1)
            return 50;
        else if (variation == 2)
            return 20;
    }
    return 100;
}

static bool32 GetParametrizedShinyness(enum Move move, u32 variation)
{
    if ((GetMoveAnimationScript(move) == gBattleAnimMove_DragonDarts && variation == 2)
        || (GetMoveAnimationScript(move) == gBattleAnimMove_SyrupBomb && variation == 1)
        )
        return TRUE;
    return FALSE;
}

static bool32 TargetHasToMove(enum Move move) // Opponent needs to hit the player first
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_REFLECT_DAMAGE
     || effect == EFFECT_MIRROR_MOVE
     || effect == EFFECT_CONVERSION_2
     || effect == EFFECT_COPYCAT
     || effect == EFFECT_SUCKER_PUNCH
     || effect == EFFECT_INSTRUCT
     || effect == EFFECT_DISABLE
     || effect == EFFECT_MIMIC
     || effect == EFFECT_SPITE
     || effect == EFFECT_ENCORE)
        return TRUE;
    return FALSE;
}

static bool32 AttackerHasToSwitch(enum Move move) // User needs to send out a different team member
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (IsExplosionMove(move)
     || effect == EFFECT_TELEPORT
     || effect == EFFECT_BATON_PASS
     || effect == EFFECT_MEMENTO
     || effect == EFFECT_HEALING_WISH
     || effect == EFFECT_LUNAR_DANCE
     || effect == EFFECT_HIT_ESCAPE
     || effect == EFFECT_FINAL_GAMBIT
     || effect == EFFECT_PARTING_SHOT
     || effect == EFFECT_SHED_TAIL
     || effect == EFFECT_WEATHER_AND_SWITCH)
        return TRUE;
    return FALSE;
}

static bool32 UserHasToGoFirst(enum Move move) // Player needs to go first
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_PROTECT
     || effect == EFFECT_ENDURE
     || effect == EFFECT_FOLLOW_ME
     || effect == EFFECT_MAGIC_COAT
     || effect == EFFECT_ME_FIRST
     || effect == EFFECT_QUASH
     || effect == EFFECT_MAT_BLOCK
     || effect == EFFECT_ELECTRIFY
     || effect == EFFECT_SHELL_TRAP)
        return TRUE;
    return FALSE;
}

static u32 GetVariationsNumber(enum Move move, bool8 isDouble)
{
    u32 variationsNumber;

    if (gMovesInfo[move].effect == EFFECT_WEATHER_BALL
     || gMovesInfo[move].effect == EFFECT_TERRAIN_PULSE
     || move == MOVE_TECHNO_BLAST)
        variationsNumber = 5;
    else if (gMovesInfo[move].effect == EFFECT_FRUSTRATION
          || gMovesInfo[move].effect == EFFECT_RETURN
          || gMovesInfo[move].effect == EFFECT_IVY_CUDGEL
          || move == MOVE_WATER_SPOUT) //we don't use the effect because other moves with the water spout effect don't have animation variations
        variationsNumber = 4;
    else if (gMovesInfo[move].effect == EFFECT_SPIT_UP
          || gMovesInfo[move].effect == EFFECT_SWALLOW
          || GetMoveAnimationScript(move) == gBattleAnimMove_DragonDarts
          || move == MOVE_SEISMIC_TOSS)
        variationsNumber = 3;
    else if (gMovesInfo[move].effect == EFFECT_CURSE
          || gMovesInfo[move].effect == EFFECT_PRESENT
          || gMovesInfo[move].effect == EFFECT_SHELL_SIDE_ARM
          || gMovesInfo[move].effect == EFFECT_FICKLE_BEAM
          || gMovesInfo[move].effect == EFFECT_MAGNITUDE
          || (isDouble && gMovesInfo[move].effect == EFFECT_TERA_STARSTORM)
          || move == MOVE_SYRUP_BOMB)
        variationsNumber = 2;
    else
        variationsNumber = 1;
    return variationsNumber;
}

static void DoublesWhen(enum Move move, struct BattlePokemon *attacker, struct BattlePokemon *target, struct BattlePokemon *ignore1, struct BattlePokemon *ignore2, u32 variation)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    // Setup turn
    if (effect == EFFECT_SNORE
     || effect == EFFECT_SLEEP_TALK)
    {  // Player needs to be asleep
        TURN { MOVE(attacker, MOVE_REST); }
    }
    else if (effect == EFFECT_SPIT_UP
            || effect == EFFECT_SWALLOW)
    { // Player needs to have used Stockpile
        for (u32 i = 0; i <= variation; i++)
        {
            TURN { MOVE(attacker, MOVE_STOCKPILE); }
        }
    }
    else if ((effect == EFFECT_DOUBLE_POWER_ON_ARG_STATUS && GetMoveEffectArg_Status(move) == STATUS1_PARALYSIS))
    { // Opponent needs to be paralyzed
        TURN { MOVE(attacker, MOVE_THUNDER_WAVE, target: target); }
    }
    else if (effect == EFFECT_RECYCLE
          || effect == EFFECT_BELCH)
    { // Player needs to have eaten its Berry
        TURN { MOVE(attacker, MOVE_STUFF_CHEEKS); }
    }
    else if (effect == EFFECT_REFRESH
          || effect == EFFECT_PSYCHO_SHIFT)
    { // Player needs to be paralyzed
        TURN { MOVE(target, MOVE_THUNDER_WAVE, target: attacker); }
    }
    else if (effect == EFFECT_LAST_RESORT)
    { // Player needs to have used all other moves
        TURN { MOVE(attacker, MOVE_POUND, target: target); }
    }
    else if (effect == EFFECT_DREAM_EATER
          || effect == EFFECT_NIGHTMARE)
    { // Opponent needs to be asleep
        TURN { MOVE(target, MOVE_REST); }
    }
    else if (effect == EFFECT_STAT_CHANGE_ON_STATUS
          || effect == EFFECT_PURIFY)
    { // Opponent needs to be poisoned
        TURN { MOVE(attacker, MOVE_POISON_POWDER, target: target); }
    }
    else if (effect == EFFECT_TOPSY_TURVY)
    { // Opponent needs to have its stats buffed
        TURN { MOVE(target, MOVE_SWORDS_DANCE); }
    }
    else if (effect == EFFECT_AURORA_VEIL)
    { // Has to be hailing
        TURN { MOVE(attacker, MOVE_HAIL); }
    }
    else if (effect == EFFECT_STEEL_ROLLER)
    { // Needs a terrain
        TURN { MOVE(attacker, MOVE_ELECTRIC_TERRAIN); }
    }
    else if (gMovesInfo[move].effect == EFFECT_WEATHER_BALL && variation > 0)
    {
        if (variation == 1)
            TURN { MOVE(attacker, MOVE_SUNNY_DAY); }
        else if (variation == 2)
            TURN { MOVE(attacker, MOVE_RAIN_DANCE); }
        else if (variation == 3)
            TURN { MOVE(attacker, MOVE_SANDSTORM); }
        else
            TURN { MOVE(attacker, MOVE_HAIL); }
    }
    else if (gMovesInfo[move].effect == EFFECT_TERRAIN_PULSE && variation > 0)
    {
        if (variation == 1)
            TURN { MOVE(attacker, MOVE_ELECTRIC_TERRAIN); }
        else if (variation == 2)
            TURN { MOVE(attacker, MOVE_GRASSY_TERRAIN); }
        else if (variation == 3)
            TURN { MOVE(attacker, MOVE_PSYCHIC_TERRAIN); }
        else if (variation == 4)
            TURN { MOVE(attacker, MOVE_MISTY_TERRAIN); }
    }
    else if (gBattleMoveEffects[gMovesInfo[move].effect].twoTurnEffect)
    {
        TURN { MOVE(attacker, move, target: target); }
    }
    // Effective turn
    TURN {
        if (effect == EFFECT_REFLECT_DAMAGE)
        {
            bool32 useSpecialMove = GetMoveReflectDamage_DamageCategories(move) == 1u << DAMAGE_CATEGORY_SPECIAL;
            MOVE(target, useSpecialMove ? MOVE_SWIFT : MOVE_POUND, target: attacker);
            MOVE(attacker, move);
        }
        else if (TargetHasToMove(move))
        {
            MOVE(target, MOVE_POUND, target: attacker);
            MOVE(attacker, move, target: target);
        }
        else if (effect == EFFECT_SNATCH)
        { // Opponent needs to steal the opponent's buffing move
            MOVE(attacker, move, target: target);
            MOVE(target, MOVE_SWORDS_DANCE);
        }
        else if (effect == EFFECT_OHKO)
        { // Opponent needs to send out a different team member
            MOVE(attacker, move, target: target);
            SEND_OUT(target, 2);
        }
        else if (AttackerHasToSwitch(move))
        { // Player needs to send out a different team member
            MOVE(attacker, move, target: target);
            SEND_OUT(attacker, 2);
        }
        else if (UserHasToGoFirst(move))
        { // Player needs to go first
            MOVE(attacker, move, target: target);
            MOVE(target, MOVE_POUND, target: attacker);
        }
        else if (effect == EFFECT_AFTER_YOU)
        { // Player goes first, opponent third
            MOVE(attacker, move, target: target);
            MOVE(ignore1, MOVE_CELEBRATE);
            MOVE(target, MOVE_POUND, target: attacker);
            MOVE(ignore2, MOVE_CELEBRATE);
        }
        else if (effect == EFFECT_REVIVAL_BLESSING)
        { // Player selects party member
            MOVE(attacker, move, partyIndex: 2);
            MOVE(target, MOVE_LAST_RESORT, target: attacker); // Last Resort, so there's no anim on the opponent's side.
        }
        else if (effect == EFFECT_UPPER_HAND)
        { // Opponent needs to choose priority move
            MOVE(attacker, move, target: target);
            MOVE(target, MOVE_QUICK_ATTACK, target: attacker);
        }
        else if (effect == EFFECT_ACUPRESSURE)
        {
            MOVE(attacker, move, target: attacker);
        }
        else if (gBattleMoveEffects[gMovesInfo[move].effect].twoTurnEffect)
        {
            MOVE(target, MOVE_LAST_RESORT, target: attacker);
            SKIP_TURN(attacker);
        }
        else if (gMovesInfo[move].effect == EFFECT_PRESENT)
        {
            if (variation == 0)
                MOVE(attacker, move, target: target, WITH_RNG(RNG_PRESENT, 1));
            else if (variation == 1)
                MOVE(attacker, move, target: target, WITH_RNG(RNG_PRESENT, 254));
        }
        else if (gMovesInfo[move].effect == EFFECT_MAGNITUDE)
        {
            if (variation == 0)
                MOVE(attacker, move, WITH_RNG(RNG_MAGNITUDE, 50));
            else if (variation == 1)
                MOVE(attacker, move, WITH_RNG(RNG_MAGNITUDE, 99));
        }
        else if (gMovesInfo[move].effect == EFFECT_FICKLE_BEAM)
        {
            if (variation == 0)
                MOVE(attacker, move, target: target, WITH_RNG(RNG_FICKLE_BEAM, FALSE));
            else if (variation == 1)
                MOVE(attacker, move, target: target, WITH_RNG(RNG_FICKLE_BEAM, TRUE));
        }
        else if (gMovesInfo[move].effect == EFFECT_SHELL_SIDE_ARM)
        {
            if (variation == 0)
                MOVE(attacker, move, target: target, WITH_RNG(RNG_SHELL_SIDE_ARM, FALSE));
            else if (variation == 1)
                MOVE(attacker, move, target: target, WITH_RNG(RNG_SHELL_SIDE_ARM, TRUE));
        }
        else
        { // All other moves
            MOVE(target, MOVE_LAST_RESORT, target: attacker); // Last Resort, so there's no anim on the opponent's side.
            MOVE(attacker, move, target: target);
        }
        if (effect != EFFECT_AFTER_YOU)
        {
            // Actions for the remaining battlers
            MOVE(ignore1, MOVE_CELEBRATE);
            MOVE(ignore2, MOVE_CELEBRATE);
        }
    }
    if (gMovesInfo[move].effect == EFFECT_WISH)
    {
        TURN {};
    }
    else if (gMovesInfo[move].effect == EFFECT_FUTURE_SIGHT)
    {
        TURN {};
        TURN {};
    }
    else if (gMovesInfo[move].effect == EFFECT_ROLLOUT)
    {
        TURN { MOVE(attacker, move, target: target); }
        TURN { MOVE(attacker, move, target: target); }
        TURN { MOVE(attacker, move, target: target); }
        TURN { MOVE(attacker, move, target: target); }
        TURN { MOVE(attacker, MOVE_LAST_RESORT, target: attacker); }
    }
    else if (gMovesInfo[move].effect == EFFECT_REFRESH || gMovesInfo[move].effect == EFFECT_PSYCHO_SHIFT)
    {
        TURN { MOVE(attacker, move, target: target, WITH_RNG(RNG_PARALYSIS, FALSE)); }
    }
}

static void DoublesScene(enum Move move, struct BattlePokemon *attacker)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_STAT_CHANGE_MAGNETIC) // For some reason, Magnetic Flux and Gear Up are failing in Double Battles here
    {
        // Moves that fail in Double Battles
    }
    else if (effect == EFFECT_MIRROR_MOVE)
    { // Copy the opponent's move
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, attacker);
    }
    else if (effect == EFFECT_NATURE_POWER)
    { // Recorded battles always use BATTLE_ENVIRONMENT_BUILDING
        ANIMATION(ANIM_TYPE_MOVE, B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT, attacker);
    }
    else
    { // All other moves
        ANIMATION(ANIM_TYPE_MOVE, move, attacker);
    }
}

#if T_SHOULD_RUN_MOVE_ANIM

static void WhenSingles(enum Move move, struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 variation)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    // Setup turn
    if (effect == EFFECT_SNORE
     || effect == EFFECT_SLEEP_TALK)
    {  // attacker needs to be asleep
        TURN { MOVE(attacker, MOVE_REST); }
    }
    else if (effect == EFFECT_SPIT_UP
          || effect == EFFECT_SWALLOW)
    { // attacker needs to have used Stockpile
        for (u32 i = 0; i <= variation; i++)
        {
            TURN { MOVE(attacker, MOVE_STOCKPILE); }
        }
    }
    else if ((effect == EFFECT_DOUBLE_POWER_ON_ARG_STATUS && GetMoveEffectArg_Status(move) == STATUS1_PARALYSIS))
    { // defender needs to be paralyzed
        TURN { MOVE(attacker, MOVE_THUNDER_WAVE); }
    }
    else if (effect == EFFECT_RECYCLE
          || effect == EFFECT_BELCH)
    { // attacker needs to have eaten its Berry
        TURN { MOVE(attacker, MOVE_STUFF_CHEEKS); }
    }
    else if (effect == EFFECT_REFRESH
          || effect == EFFECT_PSYCHO_SHIFT)
    { // attacker needs to be paralyzed
        TURN { MOVE(defender, MOVE_THUNDER_WAVE); }
    }
    else if (effect == EFFECT_LAST_RESORT)
    { // attacker needs to have used all other moves
        TURN { MOVE(attacker, MOVE_POUND); }
    }
    else if (effect == EFFECT_DREAM_EATER
          || effect == EFFECT_NIGHTMARE)
    { // defender needs to be asleep
        TURN { MOVE(defender, MOVE_REST); }
    }
    else if (effect == EFFECT_STAT_CHANGE_ON_STATUS
          || effect == EFFECT_PURIFY)
    { // defender needs to be poisoned
        TURN { MOVE(attacker, MOVE_POISON_POWDER); }
    }
    else if (effect == EFFECT_TOPSY_TURVY)
    { // defender needs to have its stats buffed
        TURN { MOVE(defender, MOVE_SWORDS_DANCE); }
    }
    else if (effect == EFFECT_AURORA_VEIL)
    { // Has to be hailing
        TURN { MOVE(attacker, MOVE_HAIL); }
    }
    else if (effect == EFFECT_STEEL_ROLLER)
    { // Needs a terrain
        TURN { MOVE(attacker, MOVE_ELECTRIC_TERRAIN); }
    }
    else if (gMovesInfo[move].effect == EFFECT_WEATHER_BALL && variation > 0)
    {
        if (variation == 1)
            TURN { MOVE(attacker, MOVE_SUNNY_DAY); }
        else if (variation == 2)
            TURN { MOVE(attacker, MOVE_RAIN_DANCE); }
        else if (variation == 3)
            TURN { MOVE(attacker, MOVE_SANDSTORM); }
        else
            TURN { MOVE(attacker, MOVE_HAIL); }
    }
    else if (gMovesInfo[move].effect == EFFECT_TERRAIN_PULSE && variation > 0)
    {
        if (variation == 1)
            TURN { MOVE(attacker, MOVE_ELECTRIC_TERRAIN); }
        else if (variation == 2)
            TURN { MOVE(attacker, MOVE_GRASSY_TERRAIN); }
        else if (variation == 3)
            TURN { MOVE(attacker, MOVE_PSYCHIC_TERRAIN); }
        else if (variation == 4)
            TURN { MOVE(attacker, MOVE_MISTY_TERRAIN); }
    }
    else if (gBattleMoveEffects[gMovesInfo[move].effect].twoTurnEffect)
    {
        TURN { MOVE(attacker, move); }
    }
    // Effective turn
    TURN {
        if (effect == EFFECT_REFLECT_DAMAGE)
        {
            bool32 useSpecialMove = GetMoveReflectDamage_DamageCategories(move) == 1u << DAMAGE_CATEGORY_SPECIAL;
            MOVE(defender, useSpecialMove ? MOVE_SWIFT : MOVE_POUND);
            MOVE(attacker, move);
        }
        else if (TargetHasToMove(move))
        {
            MOVE(defender, MOVE_POUND);
            MOVE(attacker, move);
        }
        else if (effect == EFFECT_SNATCH)
        { // defender needs to steal the defender's buffing move
            MOVE(attacker, move);
            MOVE(defender, MOVE_SWORDS_DANCE);
        }
        else if (effect == EFFECT_OHKO)
        { // defender needs to send out a different team member
            MOVE(attacker, move);
            SEND_OUT(defender, 1);
        }
        else if (AttackerHasToSwitch(move))
        { // attacker needs to send out a different team member
            MOVE(attacker, move);
            SEND_OUT(attacker, 1);
        }
        else if (UserHasToGoFirst(move))
        { // attacker needs to go first
            MOVE(attacker, move);
            MOVE(defender, MOVE_POUND);
        }
        else if (effect == EFFECT_REVIVAL_BLESSING)
        { // attacker selects party member
            MOVE(attacker, move, partyIndex: 1);
            MOVE(defender, MOVE_HELPING_HAND);
        }
        else if (effect == EFFECT_UPPER_HAND)
        { // defender needs to choose priority move
            MOVE(attacker, move);
            MOVE(defender, MOVE_QUICK_ATTACK);
        }
        else if (effect == EFFECT_ACUPRESSURE)
        {
            MOVE(attacker, move, target: attacker);
        }
        else if (gBattleMoveEffects[gMovesInfo[move].effect].twoTurnEffect)
        {
            MOVE(defender, MOVE_HELPING_HAND);
            SKIP_TURN(attacker);
        }
        else if (gMovesInfo[move].effect == EFFECT_PRESENT)
        {
            if (variation == 0)
                MOVE(attacker, move, WITH_RNG(RNG_PRESENT, 1));
            else if (variation == 1)
                MOVE(attacker, move, WITH_RNG(RNG_PRESENT, 254));
        }
        else if (gMovesInfo[move].effect == EFFECT_MAGNITUDE)
        {
            if (variation == 0)
                MOVE(attacker, move, WITH_RNG(RNG_MAGNITUDE, 50));
            else if (variation == 1)
                MOVE(attacker, move, WITH_RNG(RNG_MAGNITUDE, 99));
        }
        else if (gMovesInfo[move].effect == EFFECT_FICKLE_BEAM)
        {
            if (variation == 0)
                MOVE(attacker, move, WITH_RNG(RNG_FICKLE_BEAM, FALSE));
            else if (variation == 1)
                MOVE(attacker, move, WITH_RNG(RNG_FICKLE_BEAM, TRUE));
        }
        else if (gMovesInfo[move].effect == EFFECT_SHELL_SIDE_ARM)
        {
            if (variation == 0)
                MOVE(attacker, move, WITH_RNG(RNG_SHELL_SIDE_ARM, FALSE));
            else if (variation == 1)
                MOVE(attacker, move, WITH_RNG(RNG_SHELL_SIDE_ARM, TRUE));
        }
        else
        { // All other moves
            MOVE(defender, MOVE_HELPING_HAND); // Helping Hand, so there's no anim on the defender's side.
            MOVE(attacker, move);
        }
    }
    if (gMovesInfo[move].effect == EFFECT_WISH)
    {
        TURN {};
    }
    else if (gMovesInfo[move].effect == EFFECT_FUTURE_SIGHT)
    {
        TURN {};
        TURN {};
    }
    else if (gMovesInfo[move].effect == EFFECT_ROLLOUT)
    {
        TURN { MOVE(attacker, move); }
        TURN { MOVE(attacker, move); }
        TURN { MOVE(attacker, move); }
        TURN { MOVE(attacker, move); }
        TURN { MOVE(attacker, MOVE_HELPING_HAND); }
    }
}

static void SceneSingles(enum Move move, struct BattlePokemon *mon)
{
    enum BattleMoveEffects effect = GetMoveEffect(move);
    if (effect == EFFECT_FOLLOW_ME
     || effect == EFFECT_HELPING_HAND
     || effect == EFFECT_AFTER_YOU
     || effect == EFFECT_ALLY_SWITCH
     || effect == EFFECT_DRAGON_CHEER
     || GetMoveTarget(move) == TARGET_ALLY)
    {
        // Moves that fail in Single Battles
    }
    else if (effect == EFFECT_MIRROR_MOVE) // Copy the opponent's move
    {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, mon);
    }
    else if (effect == EFFECT_NATURE_POWER) // Recorded battles always use BATTLE_ENVIRONMENT_BUILDING
    {
        ANIMATION(ANIM_TYPE_MOVE, B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT, mon);
    }
    else // All other moves
    {
        ANIMATION(ANIM_TYPE_MOVE, move, mon);
    }
}

//static void SameSideTargeting(enum Move move, struct BattlePokemon *attacker)
//{
//    //  Don't know how to make sure this is correct, some moves don't display
//}

SINGLE_BATTLE_TEST("Move Animations don't leak when used - Singles (player to opponent)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, FALSE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
            if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
            if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            if (friendship) Friendship(friendship);
            if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
        }
        PLAYER(SPECIES_WOBBUFFET)   {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        WhenSingles(move, player, opponent, variation);
    } SCENE {
        SceneSingles(move, player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

SINGLE_BATTLE_TEST("Move Animations don't leak when used - Singles (opponent to player)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, FALSE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
            if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
            if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            if (friendship) Friendship(friendship);
            if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
        }
        OPPONENT(SPECIES_WOBBUFFET)   {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        WhenSingles(move, opponent, player, variation);
    } SCENE {
        SceneSingles(move, opponent);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (playerLeft to opponentLeft)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerLeft;
    struct BattlePokemon *target = opponentLeft;
    struct BattlePokemon *ignore1 = playerRight;
    struct BattlePokemon *ignore2 = opponentRight;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight)
            {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (opponentLeft to playerLeft)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = opponentLeft;
    struct BattlePokemon *target = playerLeft;
    struct BattlePokemon *ignore1 = opponentRight;
    struct BattlePokemon *ignore2 = playerRight;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (playerLeft to opponentRight)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerLeft;
    struct BattlePokemon *target = opponentRight;
    struct BattlePokemon *ignore1 = playerRight;
    struct BattlePokemon *ignore2 = opponentLeft;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (opponentRight to playerLeft)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = opponentRight;
    struct BattlePokemon *target = playerLeft;
    struct BattlePokemon *ignore1 = opponentLeft;
    struct BattlePokemon *ignore2 = playerRight;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (playerRight to opponentLeft)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerRight;
    struct BattlePokemon *target = opponentLeft;
    struct BattlePokemon *ignore1 = playerLeft;
    struct BattlePokemon *ignore2 = opponentRight;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (opponentLeft to playerRight)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = opponentLeft;
    struct BattlePokemon *target = playerRight;
    struct BattlePokemon *ignore1 = playerLeft;
    struct BattlePokemon *ignore2 = opponentRight;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (playerRight to opponentRight)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerRight;
    struct BattlePokemon *target = opponentRight;
    struct BattlePokemon *ignore1 = playerLeft;
    struct BattlePokemon *ignore2 = opponentLeft;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (opponentRight to playerRight)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = opponentRight;
    struct BattlePokemon *target = playerRight;
    struct BattlePokemon *ignore1 = playerLeft;
    struct BattlePokemon *ignore2 = opponentLeft;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

/*
DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (playerLeft to playerRight)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerLeft;
    struct BattlePokemon *target = playerRight;
    struct BattlePokemon *ignore1 = opponentRight;
    struct BattlePokemon *ignore2 = opponentLeft;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, 0);
        PARAMETRIZE { move = tempMove; species = tempSpecies; }
    }
    GIVEN {
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2);
    } SCENE {
        SameSideTargeting(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (playerRight to playerLeft)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerRight;
    struct BattlePokemon *target = playerLeft;
    struct BattlePokemon *ignore1 = opponentRight;
    struct BattlePokemon *ignore2 = opponentLeft;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, 0);
        PARAMETRIZE { move = tempMove; species = tempSpecies; }
    }
    GIVEN {
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2);
    } SCENE {
        SameSideTargeting(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (opponentleft to opponentRight)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = opponentLeft;
    struct BattlePokemon *target = opponentRight;
    struct BattlePokemon *ignore1 = playerLeft;
    struct BattlePokemon *ignore2 = playerRight;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, 0);
        PARAMETRIZE { move = tempMove; species = tempSpecies; }
    }
    GIVEN {
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2);
    } SCENE {
        SameSideTargeting(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
    }
}

DOUBLE_BATTLE_TEST("Move Animations don't leak when used - Doubles (opponentRight to opponentLeft)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = opponentRight;
    struct BattlePokemon *target = opponentLeft;
    struct BattlePokemon *ignore1 = playerLeft;
    struct BattlePokemon *ignore2 = playerRight;
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, 0);
        PARAMETRIZE { move = tempMove; species = tempSpecies; }
    }
    GIVEN {
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(species) {
            HP(9997); MaxHP(9999); Item(ITEM_ORAN_BERRY);
            if (attacker == opponentRight) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            }
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW) {
                Item(ITEM_ORAN_BERRY);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2);
    } SCENE {
        SameSideTargeting(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
    }
}
*/

SINGLE_BATTLE_TEST("Move Animations occur before their stat change animations - Singles (player to opponent)")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    for (; j <= ANIM_TEST_END_MOVE; j++) {
        variationsNumber = GetVariationsNumber(j, FALSE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
            if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
            if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
            if (friendship) Friendship(friendship);
            if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
        }
        PLAYER(SPECIES_WOBBUFFET)   {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        WhenSingles(move, player, opponent, variation);
    } SCENE {
        if (!(GetMoveEffect(move) == EFFECT_RECYCLE
          || GetMoveEffect(move) == EFFECT_BELCH
          || GetMoveEffect(move) == EFFECT_SPIT_UP
          || GetMoveEffect(move) == EFFECT_SWALLOW
          || GetMoveEffect(move) == EFFECT_TOPSY_TURVY)) // require a move that boosts stats before using this move
        {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            }
        }
        SceneSingles(move, player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

#endif // T_SHOULD_RUN_MOVE_ANIM

//  Z-Moves
#define Z_MOVE_PARAMETERS PARAMETRIZE { zmove = MOVE_BREAKNECK_BLITZ; species = SPECIES_WOBBUFFET; move = MOVE_TACKLE; item = ITEM_NORMALIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_INFERNO_OVERDRIVE; species = SPECIES_WOBBUFFET; move = MOVE_EMBER; item = ITEM_FIRIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_HYDRO_VORTEX; species = SPECIES_WOBBUFFET; move = MOVE_BUBBLE; item = ITEM_WATERIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_GIGAVOLT_HAVOC; species = SPECIES_WOBBUFFET; move = MOVE_THUNDERBOLT; item = ITEM_ELECTRIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_BLOOM_DOOM; species = SPECIES_WOBBUFFET; move = MOVE_RAZOR_LEAF; item = ITEM_GRASSIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SUBZERO_SLAMMER; species = SPECIES_WOBBUFFET; move = MOVE_ICE_BEAM; item = ITEM_ICIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_ALL_OUT_PUMMELING; species = SPECIES_WOBBUFFET; move = MOVE_KARATE_CHOP; item = ITEM_FIGHTINIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_ACID_DOWNPOUR; species = SPECIES_WOBBUFFET; move = MOVE_SLUDGE_BOMB; item = ITEM_POISONIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_TECTONIC_RAGE; species = SPECIES_WOBBUFFET; move = MOVE_MUD_SLAP; item = ITEM_GROUNDIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SUPERSONIC_SKYSTRIKE; species = SPECIES_WOBBUFFET; move = MOVE_AERIAL_ACE; item = ITEM_FLYINIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SHATTERED_PSYCHE; species = SPECIES_WOBBUFFET; move = MOVE_CONFUSION; item = ITEM_PSYCHIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SAVAGE_SPIN_OUT; species = SPECIES_WOBBUFFET; move = MOVE_BUG_BUZZ; item = ITEM_BUGINIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_CONTINENTAL_CRUSH; species = SPECIES_WOBBUFFET; move = MOVE_ROCK_SLIDE; item = ITEM_ROCKIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_NEVER_ENDING_NIGHTMARE; species = SPECIES_WOBBUFFET; move = MOVE_SHADOW_BALL; item = ITEM_GHOSTIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_DEVASTATING_DRAKE; species = SPECIES_WOBBUFFET; move = MOVE_DRAGON_PULSE; item = ITEM_DRAGONIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_BLACK_HOLE_ECLIPSE; species = SPECIES_WOBBUFFET; move = MOVE_BITE; item = ITEM_DARKINIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_CORKSCREW_CRASH; species = SPECIES_WOBBUFFET; move = MOVE_METAL_CLAW; item = ITEM_STEELIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_TWINKLE_TACKLE; species = SPECIES_WOBBUFFET; move = MOVE_MOONBLAST; item = ITEM_FAIRIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_CATASTROPIKA; species = SPECIES_PIKACHU; move = MOVE_VOLT_TACKLE; item = ITEM_PIKANIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_EXTREME_EVOBOOST; species = SPECIES_EEVEE; move = MOVE_LAST_RESORT; item = ITEM_EEVIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_PULVERIZING_PANCAKE; species = SPECIES_SNORLAX; move = MOVE_GIGA_IMPACT; item = ITEM_SNORLIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_GENESIS_SUPERNOVA; species = SPECIES_MEW; move = MOVE_PSYCHIC; item = ITEM_MEWNIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SINISTER_ARROW_RAID; species = SPECIES_DECIDUEYE; move = MOVE_SPIRIT_SHACKLE; item = ITEM_DECIDIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_MALICIOUS_MOONSAULT; species = SPECIES_INCINEROAR; move = MOVE_DARKEST_LARIAT; item = ITEM_INCINIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_OCEANIC_OPERETTA; species = SPECIES_PRIMARINA; move = MOVE_SPARKLING_ARIA; item = ITEM_PRIMARIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SPLINTERED_STORMSHARDS; species = SPECIES_LYCANROC_MIDNIGHT; move = MOVE_STONE_EDGE; item = ITEM_LYCANIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SPLINTERED_STORMSHARDS; species = SPECIES_LYCANROC_MIDDAY; move = MOVE_STONE_EDGE; item = ITEM_LYCANIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SPLINTERED_STORMSHARDS; species = SPECIES_LYCANROC_DUSK; move = MOVE_STONE_EDGE; item = ITEM_LYCANIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_LETS_SNUGGLE_FOREVER; species = SPECIES_MIMIKYU; move = MOVE_PLAY_ROUGH; item = ITEM_MIMIKIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_CLANGOROUS_SOULBLAZE; species = SPECIES_KOMMO_O; move = MOVE_CLANGING_SCALES; item = ITEM_KOMMONIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_GUARDIAN_OF_ALOLA; species = SPECIES_TAPU_KOKO; move = MOVE_NATURES_MADNESS; item = ITEM_TAPUNIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SEARING_SUNRAZE_SMASH; species = SPECIES_SOLGALEO; move = MOVE_SUNSTEEL_STRIKE; item = ITEM_SOLGANIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_MENACING_MOONRAZE_MAELSTROM; species = SPECIES_LUNALA; move = MOVE_MOONGEIST_BEAM; item = ITEM_LUNALIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_SOUL_STEALING_7_STAR_STRIKE; species = SPECIES_MARSHADOW; move = MOVE_SPECTRAL_THIEF; item = ITEM_MARSHADIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_STOKED_SPARKSURFER; species = SPECIES_RAICHU_ALOLA; move = MOVE_THUNDERBOLT; item = ITEM_ALORAICHIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_10_000_000_VOLT_THUNDERBOLT; species = SPECIES_PIKACHU_ALOLA; move = MOVE_THUNDERBOLT; item = ITEM_PIKASHUNIUM_Z; } \
    PARAMETRIZE { zmove = MOVE_LIGHT_THAT_BURNS_THE_SKY; species = SPECIES_NECROZMA_DAWN_WINGS; move = MOVE_PHOTON_GEYSER; item = ITEM_ULTRANECROZIUM_Z; }

#if T_SHOULD_RUN_MOVE_ANIM

SINGLE_BATTLE_TEST("Z-Moves don't leak when used - Singles (player to opponent)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(player, move, gimmick: GIMMICK_Z_MOVE); }
        }
        else
        {
            TURN { MOVE(player, move, gimmick: GIMMICK_Z_MOVE); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, zmove, player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

SINGLE_BATTLE_TEST("Z-Moves don't leak when used - Singles (opponent to player)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(species) { Item(item); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(opponent, move, gimmick: GIMMICK_Z_MOVE); }
        }
        else
        {
            TURN { MOVE(opponent, move, gimmick: GIMMICK_Z_MOVE); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, zmove, opponent);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (playerLeft to opponentLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(species) { Item(item); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(playerLeft, move, gimmick: GIMMICK_Z_MOVE, target: opponentLeft); }
        }
        else
        {
            TURN { MOVE(playerLeft, move, gimmick: GIMMICK_Z_MOVE, target: opponentLeft); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, zmove, playerLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (playerLeft to opponentRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(species) { Item(item); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(playerLeft, move, gimmick: GIMMICK_Z_MOVE, target: opponentRight); }
        }
        else
        {
            TURN { MOVE(playerLeft, move, gimmick: GIMMICK_Z_MOVE, target: opponentRight); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, zmove, playerLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (playerRight to opponentLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(playerRight, move, gimmick: GIMMICK_Z_MOVE, target: opponentLeft); }
        }
        else
        {
            TURN { MOVE(playerRight, move, gimmick: GIMMICK_Z_MOVE, target: opponentLeft); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, zmove, playerRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (playerRight to opponentRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(playerRight, move, gimmick: GIMMICK_Z_MOVE, target: opponentRight); }
        }
        else
        {
            TURN { MOVE(playerRight, move, gimmick: GIMMICK_Z_MOVE, target: opponentRight); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, zmove, playerRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (opponentLeft to playerLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(species) { Item(item); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(opponentLeft, move, gimmick: GIMMICK_Z_MOVE, target: playerLeft); }
        }
        else
        {
            TURN { MOVE(opponentLeft, move, gimmick: GIMMICK_Z_MOVE, target: playerLeft); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, zmove, opponentLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (opponentLeft to playerRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(species) { Item(item); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(opponentLeft, move, gimmick: GIMMICK_Z_MOVE, target: playerRight); }
        }
        else
        {
            TURN { MOVE(opponentLeft, move, gimmick: GIMMICK_Z_MOVE, target: playerRight); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, zmove, opponentLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (opponentRight to playerLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(species) { Item(item); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(opponentRight, move, gimmick: GIMMICK_Z_MOVE, target: playerLeft); }
        }
        else
        {
            TURN { MOVE(opponentRight, move, gimmick: GIMMICK_Z_MOVE, target: playerLeft); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, zmove, opponentRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Z-Moves don't leak when used - Doubles (opponentRight to playerRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(species) { Item(item); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(opponentRight, move, gimmick: GIMMICK_Z_MOVE, target: playerRight); }
        }
        else
        {
            TURN { MOVE(opponentRight, move, gimmick: GIMMICK_Z_MOVE, target: playerRight); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, zmove, opponentRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

#endif // T_SHOULD_RUN_MOVE_ANIM

//  Max Moves

// Tera Blast and all type variants
#define TERA_BLAST_PARAMETERS PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_NORMAL; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_FIGHTING; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_FLYING; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_POISON; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_GROUND; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_ROCK; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_BUG; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_GHOST; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_STEEL; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_WATER; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_FIRE; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_GRASS; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_ELECTRIC; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_PSYCHIC; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_ICE; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_DRAGON; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_DARK; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_FAIRY; } \
    PARAMETRIZE { species = SPECIES_WOBBUFFET; move = MOVE_TERA_BLAST; type = TYPE_STELLAR; }

#if T_SHOULD_RUN_MOVE_ANIM

SINGLE_BATTLE_TEST("Tera Blast doesn't leak when used - Singles (player to opponent)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { TeraType(type); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

SINGLE_BATTLE_TEST("Tera Blast doesn't leak when used - Singles (opponent to player)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(species) { TeraType(type); }
    } WHEN {
        TURN { MOVE(opponent, move, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (playerLeft to opponentLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { TeraType(type); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(playerLeft, move, gimmick: GIMMICK_TERA, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (playerLeft to opponentRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { TeraType(type); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(playerLeft, move, gimmick: GIMMICK_TERA, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (playerRight to opponentLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(species) { TeraType(type); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(playerRight, move, gimmick: GIMMICK_TERA, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (playerRight to opponentRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(species) { TeraType(type); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(playerRight, move, gimmick: GIMMICK_TERA, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (opponentLeft to playerLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET) { TeraType(type); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, move, gimmick: GIMMICK_TERA, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (opponentLeft to playerRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET) { TeraType(type); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, move, gimmick: GIMMICK_TERA, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (opponentRight to playerLeft)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { TeraType(type); }
    } WHEN {
        TURN { MOVE(opponentRight, move, gimmick: GIMMICK_TERA, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Tera Blast doesn't leak when used - Doubles (opponentRight to playerRight)")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { Item(ITEM_FOCUS_SASH); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { TeraType(type); }
    } WHEN {
        TURN { MOVE(opponentRight, move, gimmick: GIMMICK_TERA, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentRight);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

#else // T_SHOULD_RUN_MOVE_ANIM

#define DISABLE_SELECTABLE_PARAMETERS \
    WITH_CONFIG(B_BELCH_SELECTABLE, GEN_9); \
    WITH_CONFIG(B_STUFF_CHEEKS_SELECTABLE, GEN_9); \
    WITH_CONFIG(B_SPIT_UP_SELECTABLE, GEN_9); \
    WITH_CONFIG(B_LAST_RESORT_SELECTABLE, GEN_9); \

DOUBLE_BATTLE_TEST("Move Animations work 1")
{
    u32 j = ANIM_TEST_START_MOVE;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerLeft;
    struct BattlePokemon *target = opponentLeft;
    struct BattlePokemon *ignore1 = playerRight;
    struct BattlePokemon *ignore2 = opponentRight;
    for (; j <= ANIM_TEST_END_MOVE; j += 4) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        DISABLE_SELECTABLE_PARAMETERS;
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight)
            {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations work 2")
{
    u32 j = ANIM_TEST_START_MOVE + 1;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerLeft;
    struct BattlePokemon *target = opponentLeft;
    struct BattlePokemon *ignore1 = playerRight;
    struct BattlePokemon *ignore2 = opponentRight;
    for (; j <= ANIM_TEST_END_MOVE; j += 4) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        DISABLE_SELECTABLE_PARAMETERS;
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight)
            {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations work 3")
{
    u32 j = ANIM_TEST_START_MOVE + 2;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerLeft;
    struct BattlePokemon *target = opponentLeft;
    struct BattlePokemon *ignore1 = playerRight;
    struct BattlePokemon *ignore2 = opponentRight;
    for (; j <= ANIM_TEST_END_MOVE; j += 4) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        DISABLE_SELECTABLE_PARAMETERS;
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight)
            {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Move Animations work 4")
{
    u32 j = ANIM_TEST_START_MOVE + 3;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    u32 k = 0, variation = 0, variationsNumber;
    u32 friendship = 0, tempFriendship;
    enum Move tempMove;
    enum Species tempSpecies;
    FORCE_MOVE_ANIM(TRUE);
    struct BattlePokemon *attacker = playerLeft;
    struct BattlePokemon *target = opponentLeft;
    struct BattlePokemon *ignore1 = playerRight;
    struct BattlePokemon *ignore2 = opponentRight;
    for (; j <= ANIM_TEST_END_MOVE; j += 4) {
        variationsNumber = GetVariationsNumber(j, TRUE);
        for (k = 0; k < variationsNumber; k++) {
            ParametrizeMovesAndSpecies(j, &tempMove, &tempSpecies, k);
            tempFriendship = ParametrizeFriendship(j, k);
            PARAMETRIZE { move = tempMove; species = tempSpecies; variation = k; friendship = tempFriendship; }
        }
    }
    GIVEN {
        DISABLE_SELECTABLE_PARAMETERS;
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerLeft) {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(species) {
            Level(GetParametrizedLevel(move, variation));
            HP(GetParametrizedHP(move, variation)); MaxHP(9999); Item(GetParametrizedItem(move, variation));
            if (attacker == playerRight)
            {
                if (species == SPECIES_WOBBUFFET) Gender(MON_FEMALE);
                if (GetMoveEffect(move) == EFFECT_LAST_RESORT) Moves(move, MOVE_POUND);
                if (species == SPECIES_KLINKLANG) Ability(ABILITY_PLUS);
                if (friendship) Friendship(friendship);
                if (GetParametrizedShinyness(move, variation)) Shiny(TRUE);
            }
        }
        PLAYER(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); MaxHP(9999); Moves(MOVE_POUND, MOVE_CELEBRATE);
            HP(GetMoveEffect(move) == EFFECT_REVIVAL_BLESSING ? 0 : 9998);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) {
            Gender(MON_MALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); Ability(ABILITY_TELEPATHY);
            if (GetMoveEffect(move) != EFFECT_BESTOW)
                Item(ITEM_ORAN_BERRY);
        }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); HP(9998); MaxHP(9999); SpDefense(9999); Defense(9999); }
    } WHEN {
        DoublesWhen(move, attacker, target, ignore1, ignore2, variation);
    } SCENE {
        DoublesScene(move, attacker);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

SINGLE_BATTLE_TEST("Z-Moves animations work")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move, zmove;
    enum Item item;
    Z_MOVE_PARAMETERS;
    GIVEN {
        DISABLE_SELECTABLE_PARAMETERS;
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        if (species == SPECIES_NECROZMA_DAWN_WINGS)
        {
            TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST); }
            TURN { MOVE(player, move, gimmick: GIMMICK_Z_MOVE); }
        }
        else
        {
            TURN { MOVE(player, move, gimmick: GIMMICK_Z_MOVE); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, zmove, player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

SINGLE_BATTLE_TEST("Tera Blast animations work")
{
    FORCE_MOVE_ANIM(TRUE);
    enum Species species;
    enum Move move;
    enum Type type;
    TERA_BLAST_PARAMETERS;
    GIVEN {
        PLAYER(species) { TeraType(type); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        if (gLoadFail || gSpriteAllocs != 0)
            DebugPrintf("Move failed: %S (%u)", GetMoveName(move), move);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

DOUBLE_BATTLE_TEST("Gimmick Form Change animations work")
{
    FORCE_MOVE_ANIM(TRUE);
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); Speed(2); }
        PLAYER(SPECIES_GROUDON) { Item(ITEM_RED_ORB); Speed(4); }
        OPPONENT(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); Speed(1); };
        OPPONENT(SPECIES_KYOGRE) { Item(ITEM_BLUE_ORB); Speed(3); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_ULTRA_BURST);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, opponentLeft);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        EXPECT_EQ(gLoadFail, FALSE);
        EXPECT_EQ(gSpriteAllocs, 0);
    }
}

#endif // !T_SHOULD_RUN_MOVE_ANIM
