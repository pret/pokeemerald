#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Inner Focus doesn't prevent intimidate (Gen3-7)")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_7);
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_ZUBAT) { Ability(ABILITY_INNER_FOCUS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SCRATCH); }

    } SCENE {
        // Turn 1
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Zubat's Attack fell!");
        // Turn 2
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_GT(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Inner Focus prevents intimidate (Gen8+)")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        WITH_CONFIG(B_UPDATED_INTIMIDATE, GEN_8);
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); }
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_ZUBAT) { Ability(ABILITY_INNER_FOCUS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SCRATCH); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent); }
        ABILITY_POPUP(opponent, ABILITY_INNER_FOCUS);
        MESSAGE("The opposing Zubat's Attack was not lowered!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Inner Focus prevents flinching")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZUBAT) { Ability(ABILITY_INNER_FOCUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_FAKE_OUT);
               MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, player);
        NONE_OF { MESSAGE("The opposing Zubat flinched and couldn't move!"); }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Mold Breaker ignores Inner Focus")
{
    GIVEN {
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_ZUBAT) { Ability(ABILITY_INNER_FOCUS); }
    } WHEN {
        TURN { MOVE(player, MOVE_FAKE_OUT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, player);
        MESSAGE("The opposing Zubat flinched and couldn't move!");
    }
}
