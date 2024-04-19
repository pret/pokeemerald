#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Insomnia prevents sleep")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SPORE].effect == EFFECT_SLEEP);
        PLAYER(SPECIES_DROWZEE) { Ability(ABILITY_INSOMNIA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INSOMNIA);
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
        ASSUME(gMovesInfo[MOVE_YAWN].effect == EFFECT_YAWN);
        PLAYER(SPECIES_DROWZEE) { Ability(ABILITY_INSOMNIA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPORE); }
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

SINGLE_BATTLE_TEST("Insomnia prevents rest")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_REST].effect == EFFECT_REST);
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
