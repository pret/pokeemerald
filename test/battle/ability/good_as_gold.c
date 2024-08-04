#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Good as Gold protects from status moves")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].category == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GHOLDENGO) { Ability(ABILITY_GOOD_AS_GOLD); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        ABILITY_POPUP(opponent, ABILITY_GOOD_AS_GOLD);
        MESSAGE("It doesn't affect Foe Gholdengo…");
    }
}

SINGLE_BATTLE_TEST("Good as Gold doesn't protect the user from it's own moves")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_NASTY_PLOT].category == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GHOLDENGO) { Ability(ABILITY_GOOD_AS_GOLD); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_NASTY_PLOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NASTY_PLOT, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_GOOD_AS_GOLD);
            MESSAGE("It doesn't affect Foe Gholdengo…");
        }
    }
}

SINGLE_BATTLE_TEST("Good as Gold doesn't protect from moves that target the field")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_STEALTH_ROCK].category == DAMAGE_CATEGORY_STATUS);
        ASSUME(gMovesInfo[MOVE_STEALTH_ROCK].target == MOVE_TARGET_OPPONENTS_FIELD);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GHOLDENGO) { Ability(ABILITY_GOOD_AS_GOLD); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_GOOD_AS_GOLD);
            MESSAGE("It doesn't affect Foe Gholdengo…");
        }
    }
}

DOUBLE_BATTLE_TEST("Good as Gold protects from partner's status moves")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_HELPING_HAND].category == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GHOLDENGO) { Ability(ABILITY_GOOD_AS_GOLD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_HELPING_HAND); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HELPING_HAND, opponentRight);
        ABILITY_POPUP(opponentLeft, ABILITY_GOOD_AS_GOLD);
        MESSAGE("It doesn't affect Foe Gholdengo…");
    }
}
