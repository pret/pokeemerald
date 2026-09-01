#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_DARK_VOID) == EFFECT_DARK_VOID);
}

SINGLE_BATTLE_TEST("Dark Void inflicts 1-3 turns of sleep (Gen9-)")
{
    u32 turns, count;
    ASSUME(B_SLEEP_TURNS >= GEN_5);
    PARAMETRIZE { turns = 1; }
    PARAMETRIZE { turns = 2; }
    PARAMETRIZE { turns = 3; }
    PASSES_RANDOMLY(1, 3, RNG_SLEEP_TURNS);
    GIVEN {
        WITH_CONFIG(B_SLEEP_TURNS, GEN_9);
        PLAYER(SPECIES_DARKRAI);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DARK_VOID); MOVE(opponent, MOVE_CELEBRATE); }
        for (count = 0; count < turns; ++count)
            TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DARK_VOID, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Wobbuffet fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        for (count = 0; count < turns; ++count)
        {
            if (count < turns - 1)
                MESSAGE("The opposing Wobbuffet is fast asleep.");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        }
        MESSAGE("The opposing Wobbuffet woke up!");
        STATUS_ICON(opponent, none: TRUE);
    }
}

TO_DO_BATTLE_TEST("Dark Void can only be used by Darkrai (Gen7+)");
TO_DO_BATTLE_TEST("Dark Void can be used by Pokémon other than Darkrai (Gen4-6)");
TO_DO_BATTLE_TEST("Dark Void can be used by a Pokémon transformed into Darkrai");
