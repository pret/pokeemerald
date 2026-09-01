#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ABILITY_SHIELD].holdEffect == HOLD_EFFECT_ABILITY_SHIELD);
}

SINGLE_BATTLE_TEST("Ability Shield protects against Neutralizing Gas")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); Item(item); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        if (item == ITEM_ABILITY_SHIELD) {
            MESSAGE("Torkoal's Ability is protected by the effects of its Ability Shield!");
            ABILITY_POPUP(player, ABILITY_DROUGHT);
        } else {
            NONE_OF {
                MESSAGE("Torkoal's Ability is protected by the effects of its Ability Shield!");
                ABILITY_POPUP(player, ABILITY_DROUGHT);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Ability Shield prevents Intimidate from reactivating after Neutralizing Gas ends")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); Speed(1); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ABILITY_SHIELD); Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        MESSAGE("The opposing Gyarados's Ability is protected by the effects of its Ability Shield!");
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft);
        MESSAGE("The effects of the neutralizing gas wore off!");
        NONE_OF {
            ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        }
        MESSAGE("The opposing Koffing fainted!");
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Mold Breaker (no message)")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_FLYGON) { Ability(ABILITY_LEVITATE); Item(item); }
        OPPONENT(SPECIES_EXCADRILL) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Flygon's Ability is protected by the effects of its Ability Shield!");
                HP_BAR(player);
            }
            ABILITY_POPUP(player, ABILITY_LEVITATE);
        } else {
            HP_BAR(player);
            NOT ABILITY_POPUP(player, ABILITY_LEVITATE);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Mycelium Might (no message)")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_VIGOROTH) { Ability(ABILITY_VITAL_SPIRIT); Item(item); }
        OPPONENT(SPECIES_TOEDSCOOL) { Ability(ABILITY_MYCELIUM_MIGHT); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
    } SCENE {

        if (item == ITEM_ABILITY_SHIELD) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
                STATUS_ICON(player, sleep: TRUE);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Vigoroth's Ability is protected by the effects of its Ability Shield!");
            }
            ABILITY_POPUP(player, ABILITY_VITAL_SPIRIT);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
            STATUS_ICON(player, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Sunsteel Strike (no message)")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(MoveIgnoresTargetAbility(MOVE_SUNSTEEL_STRIKE));
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNSTEEL_STRIKE); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Shedinja's Ability is protected by the effects of its Ability Shield!");
                MESSAGE("Shedinja fainted!");
            }
            ABILITY_POPUP(player, ABILITY_WONDER_GUARD);
        } else {
            MESSAGE("Shedinja fainted!");
            NOT ABILITY_POPUP(player, ABILITY_WONDER_GUARD);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield activates a previously suppressed ability when obtained")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_POTION); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); Item(ITEM_ABILITY_SHIELD); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); MOVE(opponent, MOVE_TRICK); }
        TURN { MOVE(opponent, MOVE_TRICK); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Gyarados's Ability is protected by the effects of its Ability Shield!");
            ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
        MESSAGE("Gyarados's Ability is protected by the effects of its Ability Shield!");
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
        MESSAGE("Gyarados's Ability is protected by the effects of its Ability Shield!");
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    }
}

SINGLE_BATTLE_TEST("Ability Shield doesn't reactivate an ability when receiving if user already had an Ability Shield")
{

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ABILITY_SHIELD); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_NEUTRALIZING_GAS); Item(ITEM_ABILITY_SHIELD); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRICK); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        MESSAGE("Gyarados's Ability is protected by the effects of its Ability Shield!");
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Gyarados's Ability is protected by the effects of its Ability Shield!");
            ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects the user from having its ability suppressed by Gastro Acid")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_BLAZIKEN) { Ability(ABILITY_SPEED_BOOST); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
            ABILITY_POPUP(player, ABILITY_SPEED_BOOST);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
            NOT ABILITY_POPUP(player, ABILITY_SPEED_BOOST);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield doesn't protect the user's ability from being suppressed by Gastro Acid")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        PLAYER(SPECIES_BLAZIKEN) { Ability(ABILITY_SPEED_BOOST); Item(ITEM_POTION); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ABILITY_SHIELD); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); MOVE(player, MOVE_TRICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, player);
        NOT ABILITY_POPUP(player, ABILITY_SPEED_BOOST);
    } THEN {
        EXPECT_EQ(player->item, ITEM_ABILITY_SHIELD);
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Skill Swap")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
                ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
            }
            MESSAGE("Gyarados's Ability is protected by the effects of its Ability Shield!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
            ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        }
    }
}

SINGLE_BATTLE_TEST("Ability Shield protects against Skill Swap even if user has Klutz")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ABILITY_SHIELD; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_LOPUNNY) { Ability(ABILITY_KLUTZ); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        if (item == ITEM_ABILITY_SHIELD) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
            MESSAGE("Lopunny's Ability is protected by the effects of its Ability Shield!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Ability Shield prevents Receiver/Power of Alchemy holder from copying ally's ability")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PASSIMIAN; ability = ABILITY_RECEIVER; }
    PARAMETRIZE { species = SPECIES_MUK_ALOLA; ability = ABILITY_POWER_OF_ALCHEMY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); Item(ITEM_ABILITY_SHIELD); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        MESSAGE("The opposing Gyarados fainted!");
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ability);
            ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        }
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ability);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Ability Shield on fainted ally does not block Receiver/Power of Alchemy")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_PASSIMIAN; ability = ABILITY_RECEIVER; }
    PARAMETRIZE { species = SPECIES_MUK_ALOLA; ability = ABILITY_POWER_OF_ALCHEMY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ABILITY_SHIELD); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentRight, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        MESSAGE("The opposing Gyarados fainted!");
        ABILITY_POPUP(opponentLeft, ability);
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(opponentLeft->ability, ABILITY_INTIMIDATE);
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}

// These currently do not activate, but probably should do held item animation + message
TO_DO_BATTLE_TEST("Ability Shield prevents the user's Trace from changing its ability");
TO_DO_BATTLE_TEST("Ability Shield protects against Wandering Spirit");
TO_DO_BATTLE_TEST("Ability Shield protects against Mummy/Lingering Aroma");
