#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PRESENT) == EFFECT_PRESENT);
}

SINGLE_BATTLE_TEST("Present healing through Wonder Guard is still considered to have affected the target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIRROR_MOVE) == EFFECT_MIRROR_MOVE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); HP(1); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_PRESENT, WITH_RNG(RNG_PRESENT, 254)); }
        TURN { MOVE(opponent, MOVE_MIRROR_MOVE, WITH_RNG(RNG_PRESENT, 1)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_MOVE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, opponent);
        HP_BAR(player);
    }
}

DOUBLE_BATTLE_TEST("Present healing is blocked by Telepathy on an ally target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PRESENT, target: playerRight, WITH_RNG(RNG_PRESENT, 254)); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, playerLeft);
            HP_BAR(playerRight);
        }
    } THEN {
        EXPECT_EQ(playerRight->hp, 50);
    }
}

SINGLE_BATTLE_TEST("Present with Parental Bond hits twice when damaging, but only once when healing")
{
    GIVEN {
        ASSUME(GetSpeciesAbility(SPECIES_KANGASKHAN_MEGA, 0) == ABILITY_PARENTAL_BOND);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PRESENT, gimmick: GIMMICK_MEGA, WITH_RNG(RNG_PRESENT, 1)); }
        TURN { MOVE(player, MOVE_PRESENT, WITH_RNG(RNG_PRESENT, 254)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRESENT, player);
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    }
}
