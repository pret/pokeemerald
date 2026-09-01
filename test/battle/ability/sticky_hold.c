#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sticky Hold prevents item theft")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);
        PLAYER(SPECIES_URSALUNA) { Item(ITEM_NONE); }
        OPPONENT(SPECIES_GASTRODON) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_LIFE_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_THIEF); }
    } SCENE {
        MESSAGE("Ursaluna used Thief!");
        ABILITY_POPUP(opponent, ABILITY_STICKY_HOLD);
        MESSAGE("The opposing Gastrodon's item cannot be removed!");
    }
}

SINGLE_BATTLE_TEST("Sticky Hold prevents Incinerate from destroying berries")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_INCINERATE); }
        OPPONENT(SPECIES_GASTRODON) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_CHERI_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } THEN {
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].item, ITEM_CHERI_BERRY);
    }
}

SINGLE_BATTLE_TEST("Sticky Hold prevents Incinerate from destroying gems")
{
    GIVEN {
        WITH_CONFIG(B_INCINERATE_GEMS, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_INCINERATE); }
        OPPONENT(SPECIES_GASTRODON) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_GHOST_GEM); }
    } WHEN {
        TURN { MOVE(player, MOVE_INCINERATE); }
    } THEN {
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].item, ITEM_GHOST_GEM);
    }
}
