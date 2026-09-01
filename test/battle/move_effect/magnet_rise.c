#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MAGNET_RISE) == EFFECT_MAGNET_RISE);
}

SINGLE_BATTLE_TEST("Magnet Rise rises the user into the air, avoiding Ground-type attacks")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGNET_RISE); MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Magnet Rise fails if the user is Rooted")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_INGRAIN) == EFFECT_INGRAIN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
        TURN { MOVE(player, MOVE_MAGNET_RISE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, player);
    }
}

SINGLE_BATTLE_TEST("Magnet Rise fails if the user is Grounded by Smack Down")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SMACK_DOWN) == EFFECT_SMACK_DOWN);
        ASSUME(gSpeciesInfo[SPECIES_XATU].types[0] == TYPE_FLYING || gSpeciesInfo[SPECIES_XATU].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_XATU);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SMACK_DOWN); MOVE(player, MOVE_MAGNET_RISE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, opponent);
        MESSAGE("Xatu fell straight down!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, player);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Magnet Rise (Move Effect) test titles")
