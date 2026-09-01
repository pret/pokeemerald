#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Volt Absorb heals 25% when hit by electric type moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_SHOCK); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_VOLT_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Jolteon had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Volt Absorb does not activate if protected")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_THUNDER_SHOCK); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(player, ABILITY_VOLT_ABSORB); HP_BAR(player); MESSAGE("Jolteon had its HP restored."); }
    }
}

SINGLE_BATTLE_TEST("Volt Absorb activates on status moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_WAVE) == TYPE_ELECTRIC);
        ASSUME(GetMoveCategory(MOVE_THUNDER_WAVE) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_WAVE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_VOLT_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Jolteon had its HP restored.");
    }
}

SINGLE_BATTLE_TEST("Volt Absorb is only triggered once on multi strike moves")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_FURY_SWIPES) == TYPE_NORMAL);
        ASSUME(IsMultiHitMove(MOVE_FURY_SWIPES));
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); HP(1); MaxHP(100); }
        OPPONENT(SPECIES_GRAVELER_ALOLA) { Ability(ABILITY_GALVANIZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FURY_SWIPES); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_VOLT_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Jolteon had its HP restored.");
    }
}

DOUBLE_BATTLE_TEST("Volt Absorb does not stop Electric Typed Explosion from damaging other Pokémon") // Fixed issue #1961
{
    s16 damage1, damage2;
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        ASSUME(GetMoveType(MOVE_EXPLOSION) == TYPE_NORMAL);
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); HP(1); MaxHP(100); }
        PLAYER(SPECIES_ABRA);
        OPPONENT(SPECIES_GRAVELER_ALOLA) { Ability(ABILITY_GALVANIZE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EXPLOSION); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_VOLT_ABSORB);
        HP_BAR(playerLeft, damage: -25);
        MESSAGE("Jolteon had its HP restored.");
        HP_BAR(playerRight, captureDamage: &damage1);
        HP_BAR(opponentRight, captureDamage: &damage2);
    } THEN {
        EXPECT_NE(damage1, 0);
        EXPECT_NE(damage2, 0);
    }
}

SINGLE_BATTLE_TEST("Volt Absorb prevents Cell Battery from activating")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); HP(1); MaxHP(100); Item(ITEM_CELL_BATTERY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_SHOCK); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_VOLT_ABSORB);
        HP_BAR(player, damage: -25);
        MESSAGE("Jolteon had its HP restored.");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("The Cell Battery boosted Jolteon's Attack!");
        }
    }
}
