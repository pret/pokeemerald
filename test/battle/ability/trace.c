#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Trace copies opponents ability")
{
    GIVEN {
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
    }
}

SINGLE_BATTLE_TEST("Trace copies opponents ability on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
    }
}

SINGLE_BATTLE_TEST("Trace copies opponents ability on switch-in even if opponent switched in at the same time")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_TREECKO) { HP(1); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MISTY_EXPLOSION); SEND_OUT(opponent, 1); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_EXPLOSION);
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
    }
}

DOUBLE_BATTLE_TEST("Trace copies opponents ability randomly")
{
    enum Ability ability1, ability2;

    PARAMETRIZE { ability1 = ABILITY_SPEED_BOOST; ability2 = ABILITY_BLAZE; }
    PARAMETRIZE { ability1 = ABILITY_BLAZE; ability2 = ABILITY_SPEED_BOOST; }

    PASSES_RANDOMLY(1, 2, RNG_TRACE);
    GIVEN {
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TORCHIC) { Ability(ability1); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ability2); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
    }
}

SINGLE_BATTLE_TEST("Trace will copy an opponent's ability whenever it has the chance but only once")
{
    GIVEN {
        ASSUME(gAbilitiesInfo[ABILITY_FLOWER_GIFT].cantBeTraced);
        ASSUME(!gAbilitiesInfo[ABILITY_BLAZE].cantBeTraced);
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        // After switching
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
    }
}

SINGLE_BATTLE_TEST("Trace will copy an opponent's ability after obtaining it via Skill Swap even if it Traced a different ability before")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME(gAbilitiesInfo[ABILITY_FLOWER_GIFT].cantBeTraced);
        ASSUME(!gAbilitiesInfo[ABILITY_BLAZE].cantBeTraced);
        ASSUME(!gAbilitiesInfo[ABILITY_FLOWER_GIFT].cantBeSwapped);
        ASSUME(!gAbilitiesInfo[ABILITY_TRACE].cantBeSwapped);
        ASSUME(!gAbilitiesInfo[ABILITY_BLAZE].cantBeSwapped);
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); }
        OPPONENT(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_SKILL_SWAP); }
        TURN { SWITCH(opponent, 2); MOVE(player, MOVE_SKILL_SWAP); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        // Player now has Flower Gift
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        // Player now has Trace
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
    }
}

SINGLE_BATTLE_TEST("Trace doesn't try to reactivate if activation was prevented by Ability Shield")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        ASSUME(GetItemHoldEffect(ITEM_ABILITY_SHIELD) == HOLD_EFFECT_ABILITY_SHIELD);
        ASSUME(!gAbilitiesInfo[ABILITY_BLAZE].cantBeTraced);
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); Item(ITEM_ABILITY_SHIELD); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        // Can't activate even when no longer holding Ability Shield
        NOT ABILITY_POPUP(player, ABILITY_TRACE);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Trace can activate if it couldn't copy opponent's ability even with an Ability Shield")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        ASSUME(GetItemHoldEffect(ITEM_ABILITY_SHIELD) == HOLD_EFFECT_ABILITY_SHIELD);
        ASSUME(gAbilitiesInfo[ABILITY_FLOWER_GIFT].cantBeTraced);
        ASSUME(!gAbilitiesInfo[ABILITY_BLAZE].cantBeTraced);
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); Item(ITEM_ABILITY_SHIELD); }
        OPPONENT(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_BLAZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        // After switching
        ABILITY_POPUP(player, ABILITY_TRACE);
        MESSAGE("It traced the opposing Torchic's Blaze!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Trace copies opponent's Intimidate and triggers it immediately")
{
    GIVEN {
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_MASQUERAIN) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TRACE);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    }
}

DOUBLE_BATTLE_TEST("Trace respects the turn order")
{
    GIVEN {
        PLAYER(SPECIES_DEOXYS_SPEED) { Speed(40); Ability(ABILITY_PRESSURE); }
        PLAYER(SPECIES_GARDEVOIR) { Speed(20); Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_HIPPOWDON) { Speed(10); Ability(ABILITY_SAND_STREAM); }
        OPPONENT(SPECIES_DEOXYS_SPEED) { Speed(30); Ability(ABILITY_PRESSURE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_PRESSURE);
        ABILITY_POPUP(opponentRight, ABILITY_PRESSURE);
        ABILITY_POPUP(playerRight, ABILITY_TRACE);
        ABILITY_POPUP(opponentLeft, ABILITY_SAND_STREAM);
    }
}
