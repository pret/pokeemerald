#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("End Turn Effects: First Event Block is executed correctly (double battle)")
{
    s16 healed;
    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(100); Speed(1); }
        PLAYER(SPECIES_EKANS) { HP(100); Ability(ABILITY_SHED_SKIN); Status1(STATUS1_BURN); Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { HP(100); Item(ITEM_LEFTOVERS); Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(100); Item(ITEM_BLACK_SLUDGE); Speed(4); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is healed by the grassy terrain!");
        HP_BAR(opponentRight, captureDamage: &healed);
        HP_BAR(opponentRight, captureDamage: &damage);
        MESSAGE("The opposing Wobbuffet was hurt by the Black Sludge!");
        MESSAGE("The opposing Wynaut is healed by the grassy terrain!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("Ekans is healed by the grassy terrain!");
        MESSAGE("Ekans's burn was cured!");
        MESSAGE("Wynaut is healed by the grassy terrain!");
    } THEN {
        EXPECT_GT(0, healed);
        EXPECT_GT(damage, 0);
    }
}

DOUBLE_BATTLE_TEST("End Turn Effects: Effects are applied by Speed Order")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT)      { MaxHP(200); HP(100); Speed(3); }
        PLAYER(SPECIES_RILLABOOM)   { MaxHP(200); HP(100); Speed(1); Ability(ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_MEWTWO)    { MaxHP(200); HP(100); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(200); HP(100); Speed(4); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_FAKE_OUT, target: playerLeft);
            MOVE(playerRight, MOVE_FAKE_OUT, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, playerRight);
        HP_BAR(opponentRight);

        HP_BAR(opponentRight);
        HP_BAR(playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
    }
}

MULTI_BATTLE_TEST("End Turn Effects: First Event Block is executed correctly (multibattle)")
{
    s16 healed;
    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(100); Speed(1); }
        PARTNER(SPECIES_EKANS) { HP(100); Ability(ABILITY_SHED_SKIN); Status1(STATUS1_BURN); Speed(2); }
        OPPONENT_A(SPECIES_WYNAUT) { HP(100); Item(ITEM_LEFTOVERS); Speed(3); }
        OPPONENT_B(SPECIES_WOBBUFFET) { HP(100); Item(ITEM_BLACK_SLUDGE); Speed(4); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is healed by the grassy terrain!");
        HP_BAR(opponentRight, captureDamage: &healed);
        HP_BAR(opponentRight, captureDamage: &damage);
        MESSAGE("The opposing Wobbuffet was hurt by the Black Sludge!");
        MESSAGE("The opposing Wynaut is healed by the grassy terrain!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("Ekans is healed by the grassy terrain!");
        MESSAGE("Ekans's burn was cured!");
        MESSAGE("Wynaut is healed by the grassy terrain!");
    } THEN {
        EXPECT_GT(0, healed);
        EXPECT_GT(damage, 0);
    }
}


TWO_VS_ONE_BATTLE_TEST("End Turn Effects: First Event Block is executed correctly (2v1)")
{
    s16 healed;
    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(100); Speed(1); }
        PARTNER(SPECIES_EKANS) { HP(100); Ability(ABILITY_SHED_SKIN); Status1(STATUS1_BURN); Speed(2); }
        OPPONENT_A(SPECIES_WYNAUT) { HP(100); Item(ITEM_LEFTOVERS); Speed(3); }
        OPPONENT_A(SPECIES_WOBBUFFET) { HP(100); Item(ITEM_BLACK_SLUDGE); Speed(4); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is healed by the grassy terrain!");
        HP_BAR(opponentRight, captureDamage: &healed);
        HP_BAR(opponentRight, captureDamage: &damage);
        MESSAGE("The opposing Wobbuffet was hurt by the Black Sludge!");
        MESSAGE("The opposing Wynaut is healed by the grassy terrain!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("Ekans is healed by the grassy terrain!");
        MESSAGE("Ekans's burn was cured!");
        MESSAGE("Wynaut is healed by the grassy terrain!");
    } THEN {
        EXPECT_GT(0, healed);
        EXPECT_GT(damage, 0);
    }
}


ONE_VS_TWO_BATTLE_TEST("End Turn Effects: First Event Block is executed correctly (1v2)")
{
    s16 healed;
    s16 damage;

    GIVEN {
        PLAYER(SPECIES_WYNAUT) { HP(100); Speed(1); }
        PLAYER(SPECIES_EKANS) { HP(100); Ability(ABILITY_SHED_SKIN); Status1(STATUS1_BURN); Speed(2); }
        OPPONENT_A(SPECIES_WYNAUT) { HP(100); Item(ITEM_LEFTOVERS); Speed(3); }
        OPPONENT_B(SPECIES_WOBBUFFET) { HP(100); Item(ITEM_BLACK_SLUDGE); Speed(4); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is healed by the grassy terrain!");
        HP_BAR(opponentRight, captureDamage: &healed);
        HP_BAR(opponentRight, captureDamage: &damage);
        MESSAGE("The opposing Wobbuffet was hurt by the Black Sludge!");
        MESSAGE("The opposing Wynaut is healed by the grassy terrain!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("Ekans is healed by the grassy terrain!");
        MESSAGE("Ekans's burn was cured!");
        MESSAGE("Wynaut is healed by the grassy terrain!");
    } THEN {
        EXPECT_GT(0, healed);
        EXPECT_GT(damage, 0);
    }
}

DOUBLE_BATTLE_TEST("End Turn Effects: New mons will switch in after if previous mons died due to hazards")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
        OPPONENT(SPECIES_WYNAUT) { HP(1); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SPIKES);
            MOVE(playerRight, MOVE_HYPER_VOICE);
            SEND_OUT(opponentLeft, 2);
            SEND_OUT(opponentRight, 3);
            SEND_OUT(opponentLeft, 4);
            SEND_OUT(opponentRight, 5);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerRight);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}
