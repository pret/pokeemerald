#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Heal heals from (Toxic) Poison damage")
{
    u8 status;
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }

    GIVEN {
        PLAYER(SPECIES_SHROOMISH) { Ability(ABILITY_POISON_HEAL); Status1(status);  HP(1), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_POISON_HEAL);
        MESSAGE("The poisoning healed Shroomish a little bit!");
        HP_BAR(player, damage: -50);
    }
}

SINGLE_BATTLE_TEST("Poison Heal heals from Toxic Poison damage are constant")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        PLAYER(SPECIES_SHROOMISH) { Ability(ABILITY_POISON_HEAL); Status1(STATUS1_TOXIC_POISON);  HP(1), MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_POISON_HEAL);
        MESSAGE("The poisoning healed Shroomish a little bit!");
        HP_BAR(player, captureDamage: &turnOneHit);

        ABILITY_POPUP(player, ABILITY_POISON_HEAL);
        MESSAGE("The poisoning healed Shroomish a little bit!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
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
            HP_BAR(player, damage: 50);
        }
    }
}
