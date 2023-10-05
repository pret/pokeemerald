#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Heal heals from Poison damage")
{
    GIVEN {
        PLAYER(SPECIES_SHROOMISH) { Ability(ABILITY_POISON_HEAL); Status1(STATUS1_POISON);  HP(1), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_POISON_HEAL);
        MESSAGE("The poisoning healed Shroomish a little bit!");
        HP_BAR(player, damage: -50);
    }
}

SINGLE_BATTLE_TEST("Poison Heal heals from Toxic Poison damage")
{
    GIVEN {
        PLAYER(SPECIES_SHROOMISH) { Ability(ABILITY_POISON_HEAL); Status1(STATUS1_TOXIC_POISON);  HP(1), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_POISON_HEAL);
        MESSAGE("The poisoning healed Shroomish a little bit!");
        HP_BAR(player, damage: -50);
    }
}

SINGLE_BATTLE_TEST("Poison Heal does not heal or cause damage when under Heal Block")
{
    GIVEN {
        PLAYER(SPECIES_SHROOMISH) { Ability(ABILITY_POISON_HEAL); Status1(STATUS1_POISON);  HP(1), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_HEAL);
            MESSAGE("The poisoning healed Shroomish a little bit!");
            HP_BAR(player, damage: -50);
        }
    }
}

SINGLE_BATTLE_TEST("Poison Heal activates before Toxic Orb")
{
    GIVEN {
        PLAYER(SPECIES_SHROOMISH) { Ability(ABILITY_POISON_HEAL); Item(ITEM_TOXIC_ORB);  HP(1), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_HEAL);
            MESSAGE("The poisoning healed Shroomish a little bit!");
            HP_BAR(player, damage: -50);
        }
    }
}