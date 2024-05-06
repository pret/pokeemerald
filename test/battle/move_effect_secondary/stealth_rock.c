#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_STONE_AXE, MOVE_EFFECT_STEALTH_ROCK) == TRUE);
}

SINGLE_BATTLE_TEST("Stone Axe sets up hazards after hitting the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        MESSAGE("Pointed stones float in the air around the opposing team!");
        MESSAGE("2 sent out Wobbuffet!");
        HP_BAR(opponent, damage: maxHP / 8);
        MESSAGE("Pointed stones dug into Foe Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Stone Axe can set up pointed stones only once")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        MESSAGE("Pointed stones float in the air around the opposing team!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        NOT MESSAGE("Pointed stones float in the air around the opposing team!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        NOT MESSAGE("Pointed stones float in the air around the opposing team!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        NOT MESSAGE("Pointed stones float in the air around the opposing team!");

        MESSAGE("2 sent out Wynaut!");
        HP_BAR(opponent, damage: maxHP / 8);
        MESSAGE("Pointed stones dug into Foe Wynaut!");
    }
}

