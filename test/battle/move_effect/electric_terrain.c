#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Electric Terrain protects grounded battlers from falling asleep")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLAYDOL) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Wobbuffet used Electric Terrain!");
        MESSAGE("The opposing Claydol used Spore!");
        MESSAGE("Wobbuffet surrounds itself with electrified terrain!");
        MESSAGE("Wobbuffet used Spore!");
        MESSAGE("The opposing Claydol fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Electric Terrain increases power of Electric-type moves by 30/50 percent", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        MESSAGE("Wobbuffet used Thunder Shock!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_TERRAIN_TYPE_BOOST >= GEN_8)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
        else
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Electric Terrain lasts for 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        MESSAGE("An electric current ran across the battlefield!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("The electricity disappeared from the battlefield.");
    }
}
