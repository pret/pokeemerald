#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_WHITE_HERB].holdEffect == HOLD_EFFECT_RESTORE_STATS);
}

SINGLE_BATTLE_TEST("White Herb restores stats when they're lowered")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_LEER].effect == EFFECT_DEFENSE_DOWN);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet's White Herb restored its status!");
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
        TURN { ; }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet's White Herb restored its status!");
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
        TURN { ; }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("Foe Wobbuffet's White Herb restored its status!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        MESSAGE("Foe Wynaut's White Herb restored its status!");
    } THEN {
        EXPECT(opponentLeft->item == ITEM_NONE);
        EXPECT(opponentLeft->statStages[STAT_DEF] = DEFAULT_STAT_STAGE);
        EXPECT(opponentRight->item == ITEM_NONE);
        EXPECT(opponentRight->statStages[STAT_DEF] = DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("White Herb restores stats after Attack was lowered by Intimidate while switching in")
{
    KNOWN_FAILING;
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
        MESSAGE("Wobbuffet's White Herb restored its status!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLOSE_COMBAT, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet's White Herb restored its status!");
        }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE - 1);
        EXPECT(player->statStages[STAT_SPDEF] = DEFAULT_STAT_STAGE - 1);
    }
}


SINGLE_BATTLE_TEST("White Herb restores stats after all hits of a multi hit move happened")
{
    u16 species;
    u16 ability;

    PARAMETRIZE { species = SPECIES_SLIGGOO_HISUIAN; ability = ABILITY_GOOEY; }
    PARAMETRIZE { species = SPECIES_DUGTRIO_ALOLAN; ability = ABILITY_TANGLING_HAIR; }

    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_DUAL_WINGBEAT].strikeCount == 2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_WHITE_HERB); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_DUAL_WINGBEAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DUAL_WINGBEAT, player);
        ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet's Speed fell!");
        ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet's White Herb restored its status!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT(player->statStages[STAT_SPEED] = DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("White Herb wont have time to activate if it is knocked off or stolen by Thief")
{
    u16 move;

    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_KNOCK_OFF; }

    KNOWN_FAILING; // Knock off fails, Thief is fine
    GIVEN {
        ASSUME(gBattleMoves[MOVE_THIEF].effect == EFFECT_THIEF);
        ASSUME(gBattleMoves[MOVE_KNOCK_OFF].effect == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_SLUGMA) {  Ability(ABILITY_WEAK_ARMOR); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_THIEF)
            MESSAGE("Foe Wobbuffet stole Slugma's White Herb!");
        else
            MESSAGE("Foe Wobbuffet knocked off Slugma's White Herb!");
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Slugma's Weak Armor lowered its Defense!");
        MESSAGE("Slugma's Weak Armor raised its Speed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet's White Herb restored its status!");
        }
    } THEN {
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE - 1);
        EXPECT(player->statStages[STAT_SPEED] = DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("White Herb wont have time to activate if Magician steals it")
{
    KNOWN_FAILING; // White Herb is activated
    GIVEN {
        ASSUME(P_GEN_6_POKEMON == TRUE);
        PLAYER(SPECIES_SLUGMA) {  Ability(ABILITY_WEAK_ARMOR); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_FENNEKIN) { Ability(ABILITY_MAGICIAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        ABILITY_POPUP(opponent, ABILITY_MAGICIAN);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Slugma's Weak Armor lowered its Defense!");
        MESSAGE("Slugma's Weak Armor raised its Speed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet's White Herb restored its status!");
        }
    } THEN {
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE - 1);
        EXPECT(player->statStages[STAT_SPEED] = DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("White Herb wont have time to activate if Pickpocket steals it")
{
    KNOWN_FAILING; // White Herb is activated
    GIVEN {
        ASSUME(gBattleMoves[MOVE_LEAF_STORM].effect == EFFECT_OVERHEAT);
        PLAYER(SPECIES_SLUGMA) {  Ability(ABILITY_WEAK_ARMOR); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEAF_STORM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEAF_STORM, player);
        ABILITY_POPUP(player, ABILITY_PICKPOCKET);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Slugma's Weak Armor lowered its Defense!");
        MESSAGE("Slugma's Weak Armor raised its Speed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet's White Herb restored its status!");
        }
    } THEN {
        EXPECT(player->statStages[STAT_DEF] = DEFAULT_STAT_STAGE - 1);
        EXPECT(player->statStages[STAT_SPEED] = DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("White Herb restores stats after Defiant or Competitive were triggered")
{
    u16 species;
    u16 ability;

    PARAMETRIZE { species = SPECIES_IGGLYBUFF; ability = ABILITY_COMPETITIVE; }
    PARAMETRIZE { species = SPECIES_MANKEY; ability = ABILITY_DEFIANT; }

    KNOWN_FAILING;
    GIVEN {
        PLAYER(species) { Ability(ability); Item(ITEM_WHITE_HERB); }
        OPPONENT(SPECIES_ARBOK) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { ; }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ABILITY_POPUP(player, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet's White Herb restored its status!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        if (species == SPECIES_IGGLYBUFF)
        {
            EXPECT(player->statStages[STAT_ATK] = DEFAULT_STAT_STAGE);
            EXPECT(player->statStages[STAT_SPATK] = DEFAULT_STAT_STAGE + 2);
        }
        else
            EXPECT(player->statStages[STAT_ATK] = DEFAULT_STAT_STAGE + 3);
    }
}
