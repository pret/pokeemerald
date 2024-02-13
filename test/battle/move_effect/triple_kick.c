#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TRIPLE_KICK].effect == EFFECT_TRIPLE_KICK);
}

SINGLE_BATTLE_TEST("Triple Kick damage is increased by its base damage for each hit")
{
    s16 firstHit;
    s16 secondHit;
    s16 thirdHit;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
        HP_BAR(opponent, captureDamage: &secondHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
        HP_BAR(opponent, captureDamage: &thirdHit);
    } THEN {
        EXPECT_MUL_EQ(firstHit, Q_4_12(2.0), secondHit);
        EXPECT_MUL_EQ(firstHit, Q_4_12(3.0), thirdHit);
    }
}

TO_DO_BATTLE_TEST("Accuracy for Triple Kick is checked independently for each hit")
TO_DO_BATTLE_TEST("Accuracy for Triple Kick is only checked for the first hit with Skill Link")
TO_DO_BATTLE_TEST("Accuracy for Triple Kick is only checked for the first hit with Loaded Dice")
