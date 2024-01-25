#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
    ASSUME(gBattleMoves[MOVE_EARTHQUAKE].type == TYPE_GROUND);
    ASSUME(gBattleMoves[MOVE_TACKLE].type != TYPE_GROUND);
    ASSUME(gBattleMoves[MOVE_RECYCLE].effect == EFFECT_RECYCLE);
}

SINGLE_BATTLE_TEST("Air Balloon prevents the holder from taking damage from ground type moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        MESSAGE("Foe Wobbuffet used Earthquake!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        MESSAGE("It doesn't affect Wobbuffet…");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops when the holder is hit by a move that is not ground type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet's Air Balloon popped!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon no longer prevents the holder from taking damage from ground type moves once it has been popped")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet's Air Balloon popped!");
        MESSAGE("Foe Wobbuffet used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        NOT MESSAGE("It doesn't affect Wobbuffet…");
    }
}

SINGLE_BATTLE_TEST("Air Balloon can not be restored with Recycle after it has been popped")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_TACKLE);
            MOVE(player, MOVE_RECYCLE);
        }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet's Air Balloon popped!");
        MESSAGE("Wobbuffet used Recycle!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon prevents the user from being healed by Grassy Terrain")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); MaxHP(100); HP(1); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        NOT MESSAGE("Wobbuffet is healed by the Grassy Terrain!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops before it can be stolen with Magician")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        MESSAGE("Wobbuffet's Air Balloon popped!");
        NOT ABILITY_POPUP(opponent, ABILITY_MAGICIAN);
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops before it can be stolen with Thief or Covet")
{
    u32 move;
    KNOWN_FAILING;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        ASSUME(gBattleMoves[move].effect == EFFECT_THIEF);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        MESSAGE("Wobbuffet's Air Balloon popped!");
        NOT MESSAGE("Foe Wobbuffet stole Wobbuffet's Air Balloon!");
    }
}
