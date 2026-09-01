#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FOLLOW_ME) == EFFECT_FOLLOW_ME);
    ASSUME(GetMoveEffect(MOVE_SPOTLIGHT) == EFFECT_FOLLOW_ME);
}

DOUBLE_BATTLE_TEST("Follow Me redirects single target moves used by opponents to user")
{
    struct BattlePokemon *moveUser = NULL;
    struct BattlePokemon *partner = NULL;
    PARAMETRIZE { moveUser = opponentLeft; partner = opponentRight; }
    PARAMETRIZE { moveUser = opponentRight; partner = opponentLeft; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: moveUser);
               MOVE(playerRight, MOVE_SCRATCH, target: partner);
               MOVE(moveUser, MOVE_FOLLOW_ME);
               MOVE(partner, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, moveUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(moveUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(moveUser);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, partner);
        HP_BAR(playerLeft);
    }
}

TO_DO_BATTLE_TEST("Follow Me doesn't redirect opponent moves that can't affect opponents") //Eg. Helping Hand
TO_DO_BATTLE_TEST("Follow Me no longer redirects if the center of attention faints mid-turn")
TO_DO_BATTLE_TEST("Follow Me can only redirect charging moves on the turn that they would hit")
TO_DO_BATTLE_TEST("Follow Me can only redirect Future Sight/Doom Desire on the turn they were selected (Gen3-5)")
TO_DO_BATTLE_TEST("Follow Me does not redirect Future Sight/Doom Desire (Gen 6+)")
TO_DO_BATTLE_TEST("Follow Me draws Electric/Water moves even if there's a Pokémon with Lightning Rod/Storm Drain")
TO_DO_BATTLE_TEST("Follow Me prioritizes the first Pokémon that used it") // There can be 2 centers of attention. If the first is gone, the 2nd is used
//TO_DO_BATTLE_TEST("Triples: Follow Me can only draw non-adjacent moves if they use a long-range move")
TO_DO_BATTLE_TEST("Follow Me can be used in Single Battles (Gen3-SwSh)")
TO_DO_BATTLE_TEST("Follow Me fails in Single Battles (BDSP+)")
TO_DO_BATTLE_TEST("Follow Me cannot redirect Sky Drop")
TO_DO_BATTLE_TEST("Follow Me does not draw attack when the user is being Sky-Dropped")

DOUBLE_BATTLE_TEST("Spotlight redirects single target moves used by the opposing side to Spotlight's target")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerRight; }
    PARAMETRIZE { moveTarget = opponentLeft; }
    PARAMETRIZE { moveTarget = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SPOTLIGHT, target: moveTarget);
               MOVE(playerRight, MOVE_SCRATCH, target: opponentRight);
               MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
               MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPOTLIGHT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        if (moveTarget != playerRight)
            HP_BAR(moveTarget);
        else
            HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        if (moveTarget == playerRight)
            HP_BAR(moveTarget);
        else
            HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        if (moveTarget == playerRight)
            HP_BAR(moveTarget);
        else
            HP_BAR(playerLeft);
    }
}
