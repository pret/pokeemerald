#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Innards Out deal dmg on fainting equal to the amount of dmg inflicted on the Innards Out mon")
{
    u16 hp = 0;
    PARAMETRIZE { hp = 5; }
    PARAMETRIZE { hp = 15; }
    PARAMETRIZE { hp = 50; }
    PARAMETRIZE { hp = 100; } // This takes out Wobbuffet.

    GIVEN {
        PLAYER(SPECIES_PYUKUMUKU) { HP(hp); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(70); SpAttack(1000); }
        OPPONENT(SPECIES_WOBBUFFET);
        ASSUME(gMovesInfo[MOVE_PSYCHIC].power != 0);
        ASSUME(gMovesInfo[MOVE_PSYCHIC].category == DAMAGE_CATEGORY_SPECIAL);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC); SEND_OUT(player, 1); if (hp == 100) { SEND_OUT(opponent, 1); } }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Psychic!");
        HP_BAR(player, hp);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        HP_BAR(opponent, hp);
    }
}

SINGLE_BATTLE_TEST("Innards Out does not trigger after Gastro Acid has been used")
{
    GIVEN {
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        ASSUME(gMovesInfo[MOVE_PSYCHIC].power != 0);
        ASSUME(gMovesInfo[MOVE_GASTRO_ACID].effect == EFFECT_GASTRO_ACID);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
        TURN { MOVE(opponent, MOVE_PSYCHIC); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Gastro Acid!");
        MESSAGE("Foe Wobbuffet used Psychic!");
        HP_BAR(player);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
            HP_BAR(opponent);
        }
    }
}

// According to Showdown Innards Out triggers, but does nothing.
SINGLE_BATTLE_TEST("Innards Out does not damage Magic Guard Pokemon")
{
    GIVEN {
        PLAYER(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); }
        ASSUME(gMovesInfo[MOVE_PSYCHIC].power != 0);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PSYCHIC); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Foe Clefable used Psychic!");
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_INNARDS_OUT);
        NOT HP_BAR(opponent);
    }
}
