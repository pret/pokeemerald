#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Insomnia prevents sleep")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_DROWZEE) { Ability(ABILITY_INSOMNIA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INSOMNIA);
        MESSAGE("Drowzee made it ineffective!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            STATUS_ICON(player, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Insomnia prevents yawn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        PLAYER(SPECIES_DROWZEE) { Ability(ABILITY_INSOMNIA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_YAWN); }
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INSOMNIA);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_YAWN, opponent);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            STATUS_ICON(player, sleep: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Insomnia prevents Rest")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_DROWZEE) { Ability(ABILITY_INSOMNIA); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REST); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INSOMNIA);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, player);
            STATUS_ICON(player, sleep: TRUE);
            HP_BAR(player);
        }
    }
}
