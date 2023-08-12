#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sturdy prevents OHKO moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FISSURE].effect == EFFECT_OHKO);
        PLAYER(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Fissure!");
        ABILITY_POPUP(player, ABILITY_STURDY);
        MESSAGE("Geodude was protected by Sturdy!");
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Sturdy prevents OHKOs")
{
    GIVEN {
        PLAYER(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); MaxHP(100); HP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponent);
        HP_BAR(player, hp: 1);
        ABILITY_POPUP(player, ABILITY_STURDY);
        MESSAGE("Geodude endured the hit using Sturdy!");
    }
}

SINGLE_BATTLE_TEST("Sturdy does not prevent non-OHKOs")
{
    GIVEN {
        PLAYER(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); MaxHP(100); HP(99); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponent);
        HP_BAR(player, hp: 0);
    }
}
