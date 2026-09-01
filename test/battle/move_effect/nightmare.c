#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Nightmare damages sleeping targets at end of turn")
{
    s16 damage;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NIGHTMARE) == EFFECT_NIGHTMARE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(2)); MaxHP(160); HP(160); }
    } WHEN {
        TURN { MOVE(player, MOVE_NIGHTMARE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NIGHTMARE, player);
        MESSAGE("The opposing Wobbuffet began having a nightmare!");
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 40);
    }
}

SINGLE_BATTLE_TEST("Nightmare affects Pokémon with Comatose")
{
    s16 damage;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NIGHTMARE) == EFFECT_NIGHTMARE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); MaxHP(160); HP(160); }
    } WHEN {
        TURN { MOVE(player, MOVE_NIGHTMARE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NIGHTMARE, player);
        MESSAGE("The opposing Komala began having a nightmare!");
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 40);
    }
}
