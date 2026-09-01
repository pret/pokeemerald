#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_WHITE_HERB].holdEffect == HOLD_EFFECT_WHITE_HERB);
}

SINGLE_BATTLE_TEST("White Herb restores stats when they're lowered")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_LEER, defense: -1);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet returned its stats to normal using its White Herb!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("White Herb restores stats after Attack was lowered by Intimidate in singles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet returned its stats to normal using its White Herb!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("White Herb restores stats after Attack was lowered by Intimidate in doubles")
{
    GIVEN {
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_WHITE_HERB); }
        PLAYER(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("The opposing Wobbuffet returned its stats to normal using its White Herb!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        MESSAGE("The opposing Wynaut returned its stats to normal using its White Herb!");
    } THEN {
        EXPECT(opponentLeft->item == ITEM_NONE);
        EXPECT(opponentLeft->statStages[STAT_DEF] = DEFAULT_STAT_STAGE);
        EXPECT(opponentRight->item == ITEM_NONE);
        EXPECT(opponentRight->statStages[STAT_DEF] = DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("White Herb restores stats after Attack was lowered by Intimidate while switching in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_CLOSE_COMBAT); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet returned its stats to normal using its White Herb!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLOSE_COMBAT, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet returned its stats to normal using its White Herb!");
        }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE - 1);
        EXPECT(player->statStages[STAT_SPDEF] = DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("White Herb restores stats after all hits of a multi hit move happened")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_SLIGGOO_HISUI; ability = ABILITY_GOOEY; }
    PARAMETRIZE { species = SPECIES_DUGTRIO_ALOLA; ability = ABILITY_TANGLING_HAIR; }

    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_DUAL_WINGBEAT) == 2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_DUAL_WINGBEAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DUAL_WINGBEAT, player);
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed fell!");
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet returned its stats to normal using its White Herb!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(player->statStages[STAT_SPEED] = DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("White Herb wont have time to activate if it is knocked off or stolen by Thief")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_KNOCK_OFF; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);
        PLAYER(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Slugma's Defense fell!");
        MESSAGE("Slugma's Speed rose sharply!");
        if (move == MOVE_KNOCK_OFF) {
            MESSAGE("The opposing Wobbuffet knocked off Slugma's White Herb!");
        } else if (move == MOVE_THIEF) {
            MESSAGE("The opposing Wobbuffet stole Slugma's White Herb!");
        }
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Slugma returned its stats to normal using its White Herb!");
        }
    } THEN {
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE - 1);
        EXPECT(player->statStages[STAT_SPEED] = DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("White Herb wont have time to activate if Magician steals it")
{
    GIVEN {
        PLAYER(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_FENNEKIN) { Ability(ABILITY_MAGICIAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Slugma's Defense fell!");
        MESSAGE("Slugma's Speed rose sharply!");
        ABILITY_POPUP(opponent, ABILITY_MAGICIAN);
        MESSAGE("The opposing Fennekin stole Slugma's White Herb!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Slugma returned its stats to normal using its White Herb!");
        }
    } THEN {
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE - 1);
        EXPECT(player->statStages[STAT_SPEED] = DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("White Herb has correct interactions with Intimidate triggered Defiant and Competitive")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_IGGLYBUFF; ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { species = SPECIES_MANKEY; ability = ABILITY_DEFIANT; }

    GIVEN {
        PLAYER(species) { Ability(ability); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ABILITY_POPUP(player, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        // Defiant activates first, so White Herb doesn't have a chance to trigger.
        if (ability == ABILITY_COMPETITIVE) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Igglybuff returned its stats to normal using its White Herb!");
        }
    } THEN {
        if (ability == ABILITY_COMPETITIVE) {
            EXPECT(player->item == ITEM_NONE);
            EXPECT(player->statStages[STAT_ATK] = DEFAULT_STAT_STAGE);
            EXPECT(player->statStages[STAT_SPATK] = DEFAULT_STAT_STAGE + 2);
        } else {
            EXPECT(player->statStages[STAT_ATK] = DEFAULT_STAT_STAGE + 1);
        }
    }
}

DOUBLE_BATTLE_TEST("White Herb is correctly displayed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SUPERPOWER, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
        MESSAGE("Wynaut returned its stats to normal using its White Herb!");
    } THEN {
        EXPECT(playerLeft->item == ITEM_NONE);
        EXPECT(playerLeft->statStages[STAT_DEF] = DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("White Herb activates after a Mega Evolution")
{
    GIVEN {
        PLAYER(SPECIES_MANECTRIC) { Item(ITEM_MANECTITE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT(opponent->item == ITEM_NONE);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

