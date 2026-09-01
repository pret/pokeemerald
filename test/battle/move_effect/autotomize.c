#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Autotomize increases Speed by 2 stages")

SINGLE_BATTLE_TEST("Autotomize decreases weight by 100kg (220 lbs.) each time it's used")
{
    s16 damage[3];

    GIVEN {
        ASSUME(GetSpeciesWeight(SPECIES_METANG) == 2025);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_METANG);
    } WHEN {
        TURN { MOVE(player, MOVE_LOW_KICK); }
        TURN { MOVE(opponent, MOVE_AUTOTOMIZE); MOVE(player, MOVE_LOW_KICK); }
        TURN { MOVE(opponent, MOVE_AUTOTOMIZE); MOVE(player, MOVE_LOW_KICK); }
    } SCENE {
        // 200.0 kg or more (120 power)
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        // 100.0 - 199.9 kg (100 power)
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &damage[1]);

        //   0.1 - 9.9 kg   (20 power)
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AUTOTOMIZE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LOW_KICK, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[2], Q_4_12(6.0), damage[0]);
        EXPECT_MUL_EQ(damage[2], Q_4_12(5.0), damage[0]);
    }
}


TO_DO_BATTLE_TEST("Autotomize cannot decrease weight below 0.1kg (0.2 lbs)");
TO_DO_BATTLE_TEST("Autotomize's weight reduction cannot be Baton Passed");
TO_DO_BATTLE_TEST("Autotomize's weight reduction cannot be removed by Haze");
TO_DO_BATTLE_TEST("Autotomize's weight reduction is reset upon form change (Gen6+)");
TO_DO_BATTLE_TEST("Autotomize's weight reduction is reset upon switch");
TO_DO_BATTLE_TEST("Autotomize's weight reduction is reset upon fainting");
TO_DO_BATTLE_TEST("Autotomize doesn't affect Heavy Ball's multiplier")
