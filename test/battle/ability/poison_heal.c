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
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_POISON_HEAL);
        HP_BAR(player, captureDamage: &turnOneHit);

        ABILITY_POPUP(player, ABILITY_POISON_HEAL);
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

SINGLE_BATTLE_TEST("Bad poison counter still increases each turn if the Pokemon has Poison Heal")
{
    s16 poisonDamage;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_SHROOMISH) { Ability(ABILITY_POISON_HEAL); Status1(STATUS1_TOXIC_POISON); HP(80); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (u32 turn = 0; turn < 4; turn++)
            TURN {}
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        for (u32 turn = 0; turn < 4; turn++)
        {
            ABILITY_POPUP(player, ABILITY_POISON_HEAL);
            HP_BAR(player, damage: -(160 / 8));
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        NOT ABILITY_POPUP(player, ABILITY_POISON_HEAL);
        HP_BAR(player, captureDamage: &poisonDamage);
    } THEN {
        EXPECT_EQ(poisonDamage, 160 * 5 / 16);
    }
}

SINGLE_BATTLE_TEST("Bad poison counter still increases each turn even if the Pokemon has Magic Guard")
{
    s16 poisonDamage;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_CLEFABLE) { Ability(ABILITY_MAGIC_GUARD); Status1(STATUS1_TOXIC_POISON); HP(160); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (u32 turn = 0; turn < 5; turn++)
            TURN {}
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        NOT HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        HP_BAR(player, captureDamage: &poisonDamage);
    } THEN {
        EXPECT_EQ(poisonDamage, 160 * 6 / 16);
    }
}
