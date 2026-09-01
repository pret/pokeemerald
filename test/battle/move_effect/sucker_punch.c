#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SUCKER_PUNCH) == EFFECT_SUCKER_PUNCH);
}

SINGLE_BATTLE_TEST("Sucker Punch hits targets that are about to attack")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUCKER_PUNCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Sucker Punch doesn't hit targets using status moves")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_GROWL) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUCKER_PUNCH); MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, player);
            HP_BAR(opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
    }
}

SINGLE_BATTLE_TEST("Sucker Punch hits targets using Me First")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ME_FIRST) == EFFECT_ME_FIRST);
        ASSUME(GetMovePriority(MOVE_SUCKER_PUNCH) > GetMovePriority(MOVE_ME_FIRST));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUCKER_PUNCH); MOVE(opponent, MOVE_ME_FIRST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ME_FIRST, opponent);
            HP_BAR(player);
        }        
    }
}

SINGLE_BATTLE_TEST("Sucker Punch doesn't hit targets that has already moved")
{
    GIVEN {
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == GetMovePriority(MOVE_SUCKER_PUNCH));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_QUICK_ATTACK); MOVE(player, MOVE_SUCKER_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, opponent);
        HP_BAR(player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, player);
            HP_BAR(opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Sucker Punch fails if the target has attempted to act even if previously successful")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(playerLeft, MOVE_SUCKER_PUNCH, target: opponentLeft); MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SUCKER_PUNCH, playerLeft);
    }
}
