#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn switches the user out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if the battle ends")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if no replacements")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if replacements fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn does not switch the user out if Wimp Out activates")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WIMPOD) { MaxHP(200); HP(101); Ability(ABILITY_WIMP_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_WIMP_OUT);
        MESSAGE("2 sent out Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn switches the user out if Wimp Out fails to activate")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WIMPOD) { MaxHP(200); HP(101); Ability(ABILITY_WIMP_OUT); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent);
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn switches the user out after Ice Face activates")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_U_TURN) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_BEEDRILL);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_EISCUE) { Ability(ABILITY_ICE_FACE); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        NOT HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_ICE_FACE);
        MESSAGE("The opposing Eiscue transformed!");
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Hit Escape: Held items are consumed immediately after a mon switched in by U-turn: player side")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ELECTRIC_SEED); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ELECTRIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("2 sent out Wynaut!");
        NOT ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: Held items are consumed immediately after a mon switched in by U-turn: opposing side")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_ELECTRIC_SEED); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ELECTRIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        MESSAGE("2 sent out Wynaut!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: Electric Seed boost is received by the right Pokémon after U-turn and Intimidate")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); Item(ITEM_ELECTRIC_SEED); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ELECTRIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn triggers before Eject Pack")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GOODRA_HISUI) { Ability(ABILITY_GOOEY); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn will fail to switch if the user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-Turn switches user out and target activates Pickpocket before replacement enters")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_TINKATON) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
    }
}

SINGLE_BATTLE_TEST("Hit Escape: U-turn will switch if the target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_U_TURN); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, opponent);
    }
}
