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
        MESSAGE("Wobbuffet used MistyTerrain!");
        MESSAGE("Foe Claydol used Toxic!");
        MESSAGE("Wobbuffet surrounds itself with a protective mist!");
        NOT { STATUS_ICON(opponent, badPoison: TRUE); }
        MESSAGE("Wobbuffet used Toxic!");
        STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain activates Misty Seed and Mimicry")
{
    GIVEN {
        ASSUME(gItems[ITEM_MISTY_SEED].holdEffect == HOLD_EFFECT_SEEDS);
        ASSUME(gItems[ITEM_MISTY_SEED].holdEffectParam == HOLD_EFFECT_PARAM_MISTY_TERRAIN);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MISTY_SEED); }
        OPPONENT(SPECIES_STUNFISK_GALARIAN) { Ability(ABILITY_MIMICRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Using Misty Seed, the Sp. Def of Wobbuffet rose!");
        ABILITY_POPUP(opponent);
        MESSAGE("Foe Stunfisk's type changed to Fairy!");
    } THEN {
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].type1, TYPE_FAIRY);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain does not increase the power of Fairy-type moves", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_MOONBLAST); }
    } SCENE {
        MESSAGE("Wobbuffet used Moonblast!");
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
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_DRAGON_CLAW); }
    } SCENE {
        MESSAGE("Wobbuffet used Dragon Claw!");
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
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        MESSAGE("Mist swirled about the battlefield!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");

        MESSAGE("The mist disappeared from the battlefield.");
    }
}
