#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TOXIC_THREAD) == EFFECT_TOXIC_THREAD);
}

SINGLE_BATTLE_TEST("Toxic Thread both reduces speed and inflicts Poison")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    } THEN {
        EXPECT_LT(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Toxic Thread still inflicts Poison if speed can't go lower")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SCARY_FACE, speed: -2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    } THEN {
        EXPECT_LT(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Toxic Thread still inflicts Poison if speed can't be lowered")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGICE) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Toxic Thread still lowers speed if the target can't be Poisoned")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_BRONZOR].types[0] == TYPE_STEEL || gSpeciesInfo[SPECIES_BRONZOR].types[1] == TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BRONZOR);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
    } THEN {
        EXPECT_LT(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Toxic Thread still lowers speed if the target is already Poisoned")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_POWDER); }
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_LT(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Toxic Thread fails if speed can't be lowered and status can't be inflicted")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_POISON_POWDER); }
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
    }
}

SINGLE_BATTLE_TEST("Toxic Thread fails if speed can't be lowered due to Clear Body and status can't be inflicted")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_REGICE) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_POWDER); }
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
    }
}

SINGLE_BATTLE_TEST("Toxic Thread fails if speed can't be lowered and target is a poison type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        ASSUME(gSpeciesInfo[SPECIES_ODDISH].types[0] == TYPE_POISON || gSpeciesInfo[SPECIES_ODDISH].types[1] == TYPE_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ODDISH);
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_TOXIC_THREAD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_THREAD, player);
    }
}
