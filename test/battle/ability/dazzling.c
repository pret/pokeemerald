#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) > 0);
}

DOUBLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail protect the user from priority moves")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_QUICK_ATTACK, target: opponentLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponentRight);
        ABILITY_POPUP(opponentLeft, ability);
        MESSAGE("Wobbuffet cannot use Quick Attack!");
    }
}

DOUBLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail protect users partner from priority moves")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_QUICK_ATTACK, target: opponentRight); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponentRight);
        ABILITY_POPUP(opponentLeft, ability);
        MESSAGE("Wobbuffet cannot use Quick Attack!");
    }
}

DOUBLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail don't protect the user from negative priority")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AVALANCHE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AVALANCHE, playerLeft);
        NOT ABILITY_POPUP(opponentLeft, ability);
    }
}

SINGLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail protect from all multi hit hits with one activation")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_SHURIKEN); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_SHURIKEN, opponent);
        ABILITY_POPUP(opponent, ability);
        NONE_OF {
            ABILITY_POPUP(opponent, ability);
            ABILITY_POPUP(opponent, ability);
            ABILITY_POPUP(opponent, ability);
            ABILITY_POPUP(opponent, ability);
        }
    }
}

SINGLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail prevent Protean activation")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        PLAYER(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_SHURIKEN); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_SHURIKEN, player);
            ABILITY_POPUP(player, ABILITY_PROTEAN);
        }
        ABILITY_POPUP(opponent, ability);
    }
}

// Moves that target the field don't get blocked
SINGLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail do not block Haze")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAZE) == EFFECT_HAZE);
        ASSUME(GetMoveTarget(MOVE_HAZE) == TARGET_FIELD);
        PLAYER(SPECIES_MURKROW) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_HAZE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NOT ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAZE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

// Moves that target all battlers are blocked
SINGLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail on opponents block Teatime")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TEATIME) == EFFECT_TEATIME);
        ASSUME(GetMoveTarget(MOVE_TEATIME) == TARGET_ALL_BATTLERS);
        ASSUME(GetItemHoldEffect(ITEM_ORAN_BERRY) == HOLD_EFFECT_RESTORE_HP);
        PLAYER(SPECIES_MURKROW) { Ability(ABILITY_PRANKSTER); Item(ITEM_ORAN_BERRY); HP(75); MaxHP(100); }
        OPPONENT(species) { Ability(ability); Item(ITEM_ORAN_BERRY); HP(75); MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEATIME); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, player);
        ABILITY_POPUP(opponent, ability);
    } THEN {
        EXPECT_NE(player->item, ITEM_NONE);
        EXPECT_NE(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail do not block a move's Z-Status effect")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        ASSUME(GetMoveZEffect(MOVE_BABY_DOLL_EYES) == Z_EFFECT_DEF_UP_1);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FAIRIUM_Z); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_BABY_DOLL_EYES, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BABY_DOLL_EYES, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Mold Breaker ignores Dazzling, Queenly Majesty and Armor Tail")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent, ability);
    }
}

DOUBLE_BATTLE_TEST("Instruct-called moves keep their priority, which is considered for Dazzling, Queenly Majesty and Armor Tail")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        ASSUME(GetItemHoldEffect(ITEM_EJECT_BUTTON) == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(species) { Ability(ability); Speed(15); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); SEND_OUT(opponentLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ABILITY_POPUP(opponentLeft, ability);
        MESSAGE("Wobbuffet cannot use Quick Attack!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerRight);
    }
}

SINGLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail do not block high-priority moves called by other moves")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_METRONOME) == EFFECT_METRONOME);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_QUICK_ATTACK)); }
    } SCENE {
        MESSAGE("Wobbuffet used Metronome!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METRONOME, player);
        MESSAGE("Waggling a finger let it use Quick Attack!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent, ability);
    }
}

DOUBLE_BATTLE_TEST("Dazzling, Queenly Majesty and Armor Tail from partner don't block priority moves that target it")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BRUXISH; ability = ABILITY_DAZZLING; }
    PARAMETRIZE { species = SPECIES_FARIGIRAF; ability = ABILITY_ARMOR_TAIL; }
    PARAMETRIZE { species = SPECIES_TSAREENA; ability = ABILITY_QUEENLY_MAJESTY; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_COACHING) == TARGET_ALLY);
        PLAYER(SPECIES_MURKROW) { Ability(ABILITY_PRANKSTER); }
        PLAYER(species) { Ability(ability); }
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_COACHING, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COACHING, playerLeft);
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ability);
            ABILITY_POPUP(playerRight, ability);
        }
    }
}
