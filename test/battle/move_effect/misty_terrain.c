#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Misty Terrain protects grounded battlers from non-volatile status conditions")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLAYDOL) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MISTY_TERRAIN); MOVE(opponent, MOVE_TOXIC); }
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        MESSAGE("The opposing Claydol used Toxic!");
        MESSAGE("Wobbuffet surrounds itself with a protective mist!");
        NOT { STATUS_ICON(opponent, badPoison: TRUE); }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain does not increase the power of Fairy-type moves", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_MOONBLAST) == TYPE_FAIRY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_MOONBLAST); }
    } SCENE {
        if (terrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MOONBLAST, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain decreases power of Dragon-type moves by 50 percent", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_DRAGON_CLAW); }
    } SCENE {
        if (terrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CLAW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain uses the defender's ability when checking if it is grounded", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        PLAYER(SPECIES_ROTOM) { Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_DRAGON_CLAW); }
    } SCENE {
        if (terrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CLAW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain lasts for 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        MESSAGE("Mist swirled around the battlefield!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("The mist disappeared from the battlefield.");
    }
}

SINGLE_BATTLE_TEST("Misty Terrain will fail if there is one already on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MISTY_TERRAIN); MOVE(opponent, MOVE_MISTY_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, opponent);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain does not decrease the power of Dragon-type moves against flying targets", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_HEATPROOF; }
    PARAMETRIZE { ability = ABILITY_LEVITATE; }
    GIVEN {
        PLAYER(SPECIES_BRONZONG) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(opponent, MOVE_DRAGON_CLAW); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Dragon Claw!");
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}
