#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Stench has a 10% chance to flinch")
{
    PASSES_RANDOMLY(1, 10, RNG_STENCH);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_STENCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet flinched!");
    }
}

SINGLE_BATTLE_TEST("Stench does not stack with King's Rock")
{
    PASSES_RANDOMLY(1, 10, RNG_STENCH);
    GIVEN {
        ASSUME(gItemsInfo[ITEM_KINGS_ROCK].holdEffect == HOLD_EFFECT_FLINCH);
        ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);

        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_STENCH); Item(ITEM_KINGS_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet flinched!");
    }
}

DOUBLE_BATTLE_TEST("Stench only triggers if target takes damage")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GRIMER) { Ability(ABILITY_STENCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_FAKE_OUT, target: opponentLeft);
            MOVE(opponentLeft, MOVE_TACKLE, WITH_RNG(RNG_STENCH, TRUE),  target: playerRight);
            MOVE(playerRight, MOVE_TACKLE, target: opponentRight);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SCARY_FACE, WITH_RNG(RNG_STENCH, TRUE),  target: playerRight);
            MOVE(playerRight, MOVE_TACKLE, target: opponentRight);
        }
    } SCENE {
        NONE_OF { MESSAGE("Wynaut flinched!"); }
    }
}

DOUBLE_BATTLE_TEST("Stench doesn't trigger if partner uses a move")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_GRIMER) { Speed(100); Ability(ABILITY_STENCH); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(50); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_FAKE_OUT, target: opponentLeft);
            MOVE(opponentRight, MOVE_TACKLE, target: playerRight);
            MOVE(playerRight, MOVE_TACKLE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, playerLeft);
        MESSAGE("Foe Grimer flinched!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponentRight);
        NOT MESSAGE("Wynaut flinched!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
    }
}

// TODO: Test against interaction with multi hits
