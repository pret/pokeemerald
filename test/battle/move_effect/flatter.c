#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FLATTER) == EFFECT_SWAGGER);
}

SINGLE_BATTLE_TEST("Flatter increases the target's Sp. Attack by 1 stage and confuses them")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLATTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLATTER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT(opponent->volatiles.confusionTimer > 0);
    }
}

SINGLE_BATTLE_TEST("Flatter on a foe with Own Tempo prevents confusion, changes stats, and does not cause a crash if the opponent uses a stat changing move immediately after")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLATTER); MOVE(opponent, MOVE_CURSE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_OWN_TEMPO);
        MESSAGE("The opposing Slowpoke cannot be confused!");
        MESSAGE("The opposing Slowpoke's Defense rose!");
    }
}

TO_DO_BATTLE_TEST("Flatter raises the target's Sp. Atk even if they're already confused")
TO_DO_BATTLE_TEST("Flatter raises the target's Sp. Atk even when protected by Safeguard")
TO_DO_BATTLE_TEST("Flatter raises the target's Sp. Atk even when protected Own Tempo")
TO_DO_BATTLE_TEST("Flatter confuses the target even when they have their Sp. Atk maxed")
TO_DO_BATTLE_TEST("Flatter confuses the target even when at -6 Sp. Atk and has Contrary")
