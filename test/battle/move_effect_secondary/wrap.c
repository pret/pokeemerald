#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_WRAP, MOVE_EFFECT_WRAP));
}

SINGLE_BATTLE_TEST("Wrap can damage the wrapped mon for 5 turns 25% (Gen3-4) or 50% (Gen5+) of the time")
{
    u32 config, passes, trials;
    PARAMETRIZE { config = GEN_4; passes = 25; trials = 100; }
    PARAMETRIZE { config = GEN_5; passes = 50; trials = 100; }
    PASSES_RANDOMLY(passes, trials, RNG_WRAP);
    GIVEN {
        WITH_CONFIG(B_BINDING_TURNS, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WRAP); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WRAP, player);
        HP_BAR(opponent); // Direct damage

        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        NOT HP_BAR(opponent); // Residual Damage
    }
}

SINGLE_BATTLE_TEST("Wrap can damage the wrapped mon for 4 turns 25% (Gen3-4) or 50% (Gen5+) of the time")
{
    u32 config, passes, trials;
    PARAMETRIZE { config = GEN_4; passes = 25; trials = 100; }
    PARAMETRIZE { config = GEN_5; passes = 50; trials = 100; }
    PASSES_RANDOMLY(passes, trials, RNG_WRAP);
    GIVEN {
        WITH_CONFIG(B_BINDING_TURNS, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WRAP); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WRAP, player);
        HP_BAR(opponent); // Direct damage

        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        NOT HP_BAR(opponent); // Residual Damage
    }
}

SINGLE_BATTLE_TEST("Wrap can damage the wrapped mon 5 turns (Gen4) or 7 turns (Gen5+) while holding a Grip Claw")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_BINDING_TURNS, config);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_GRIP_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WRAP); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WRAP, player);
        HP_BAR(opponent); // Direct damage

        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        HP_BAR(opponent); // Residual Damage
        if (config >= GEN_5) {
            HP_BAR(opponent); // Residual Damage
            HP_BAR(opponent); // Residual Damage
        }
        NOT HP_BAR(opponent); // Residual Damage
    }
}
