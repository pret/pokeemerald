#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Steadfast boosts Speed when the user attempts to move but is flinched")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        PLAYER(SPECIES_LUCARIO) { Ability(ABILITY_STEADFAST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_STEADFAST);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("Lucario's Speed rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Steadfast doesn't activate if the user wasn't flinched")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        ASSUME(GetItemHoldEffect(ITEM_COVERT_CLOAK) == HOLD_EFFECT_COVERT_CLOAK);
        PLAYER(SPECIES_LUCARIO) { Ability(ABILITY_STEADFAST); Item(ITEM_COVERT_CLOAK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_STEADFAST);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Steadfast doesn't activate if the user has already moved")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_BITE, MOVE_EFFECT_FLINCH));
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        PLAYER(SPECIES_LUCARIO) { Ability(ABILITY_STEADFAST); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SWORDS_DANCE); MOVE(opponentLeft, MOVE_BITE, target: playerLeft); MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, playerLeft);
        NOT ABILITY_POPUP(playerLeft, ABILITY_STEADFAST);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Steadfast (Ability) test titles")
