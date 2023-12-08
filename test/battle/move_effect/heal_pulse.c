#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_HEAL_PULSE].effect == EFFECT_HEAL_PULSE);
}

SINGLE_BATTLE_TEST("Heal Pulse heals the target by 1/2 of it's maxHP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_PULSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_PULSE, opponent);
        HP_BAR(player, damage: -maxHP / 2);
    }
}

DOUBLE_BATTLE_TEST("Heal Pulse can heal partner")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_HEAL_PULSE, target: playerLeft); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_PULSE, playerRight);
        HP_BAR(playerLeft, damage: -maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Heal Pulse is boosted by Mega Launcher")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); }
        OPPONENT(SPECIES_CLAWITZER);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_PULSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_PULSE, opponent);
        HP_BAR(player, damage: -maxHP * 75 / 100);
    }
}

SINGLE_BATTLE_TEST("Heal Pulse ignores accurace checks")
{
    GIVEN {
        PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); Item(ITEM_BRIGHT_POWDER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_PULSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_PULSE, opponent);
        HP_BAR(player, damage: -maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Heal Pulse is blocked by Substitute")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_SUBSTITUTE].effect == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(50); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_HEAL_PULSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_PULSE, opponent);
            HP_BAR(player, damage: -maxHP / 2);
        }
    }
}

SINGLE_BATTLE_TEST("Floral Healing heals the target by 2/3rd of it's maxHP if Grassy Terrain is on the field")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FLORAL_HEALING].argument == MOVE_EFFECT_FLORAL_HEALING);
        ASSUME(gBattleMoves[MOVE_GRASSY_TERRAIN].effect == EFFECT_GRASSY_TERRAIN);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); MOVE(opponent, MOVE_FLORAL_HEALING); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLORAL_HEALING, opponent);
        HP_BAR(player, damage: -maxHP * 2 / 3);
    }
}
