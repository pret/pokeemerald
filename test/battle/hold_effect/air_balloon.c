#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
    ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
    ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_GROUND);
}

SINGLE_BATTLE_TEST("Air Balloon prevents the holder from taking damage from ground type moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        MESSAGE("It doesn't affect Wobbuffet…");
    }
}

SINGLE_BATTLE_TEST("Air Balloon only displays entry message when user switches in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        NOT MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops when the holder is hit by a move that is not ground type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet's Air Balloon popped!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon no longer prevents the holder from taking damage from ground type moves once it has been popped")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet's Air Balloon popped!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        NOT MESSAGE("It doesn't affect Wobbuffet…");
    }
}

SINGLE_BATTLE_TEST("Air Balloon can not be restored with Recycle after it has been popped")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_SCRATCH);
            MOVE(player, MOVE_RECYCLE);
        }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet's Air Balloon popped!");
        MESSAGE("Wobbuffet used Recycle!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon prevents the user from being healed by Grassy Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); MaxHP(100); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
        NOT MESSAGE("Wobbuffet is healed by the Grassy Terrain!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops before it can be stolen with Magician")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet's Air Balloon popped!");
        NOT ABILITY_POPUP(opponent, ABILITY_MAGICIAN);
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops before it can be stolen by Thief")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THIEF); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THIEF, opponent);
        MESSAGE("Wobbuffet's Air Balloon popped!");
        NOT MESSAGE("The opposing Wobbuffet stole Wobbuffet's Air Balloon!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops if a damaging move hits the holder's Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_EMBER);}
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("Wobbuffet's Air Balloon popped!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops when Disguise is broken")
{
    enum Species species, newSpecies;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED;       newSpecies = SPECIES_MIMIKYU_BUSTED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; newSpecies = SPECIES_MIMIKYU_BUSTED_TOTEM; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_DISGUISE); Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        MESSAGE("Mimikyu floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        HP_BAR(player);
        MESSAGE("Mimikyu's Air Balloon popped!");
    } THEN {
        EXPECT_EQ(player->species, newSpecies);
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops when the holder faints from a damaging move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet's Air Balloon popped!");
        MESSAGE("Wobbuffet fainted!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}
