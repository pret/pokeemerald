#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FINAL_GAMBIT) == EFFECT_FINAL_GAMBIT);
}

SINGLE_BATTLE_TEST("Final Gambit faints the user, and the target receives damage equal to the user's HP")
{
    u32 hp;
    PARAMETRIZE { hp = 32; }
    PARAMETRIZE { hp = 40; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(400); HP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_EQ(opponent->hp, 400 - hp);
    }
}

SINGLE_BATTLE_TEST("Final Gambit faints user and target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
        HP_BAR(opponent);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not faint user if target protects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_FINAL_GAMBIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
    } THEN {
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not faint user if attacker fails to attack")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_FINAL_GAMBIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
    } THEN {
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

SINGLE_BATTLE_TEST("Final Gambit does not faint user if target is immune")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FINAL_GAMBIT, player);
    } THEN {
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP), 0);
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_HP), 0);
    }
}

// Using CONFIG_UPDATED_MOVE_FLAGS doesn't work yet, commented out so they don't cause surprise failures

// SINGLE_BATTLE_TEST("Final Gambit faints the user before abilities can activate (Gen 5)")
// {
//     GIVEN {
//         WITH_CONFIG(B_UPDATED_MOVE_FLAGS, GEN_5);
//         PLAYER(SPECIES_WOBBUFFET);
//         OPPONENT(SPECIES_PYUKUMUKU) { Ability(ABILITY_INNARDS_OUT); HP(1); }
//     } WHEN {
//         TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
//     } SCENE {
//         NOT ABILITY_POPUP(opponent, ABILITY_INNARDS_OUT);
//         MESSAGE("Wobbuffet fainted!");
//         NOT ABILITY_POPUP(opponent, ABILITY_INNARDS_OUT);
//     }
// }

// SINGLE_BATTLE_TEST("Final Gambit faints the user after abilities can activate (Gen 6+)")
// {
//     GIVEN {
//         WITH_CONFIG(B_UPDATED_MOVE_FLAGS, GEN_6);
//         PLAYER(SPECIES_WOBBUFFET);
//         OPPONENT(SPECIES_PYUKUMUKU) { Ability(ABILITY_INNARDS_OUT); HP(1); }
//     } WHEN {
//         TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
//     } SCENE {
//         ABILITY_POPUP(opponent, ABILITY_INNARDS_OUT);
//         MESSAGE("Wobbuffet fainted!");
//     }
// }

TO_DO_BATTLE_TEST("Final Gambit doesn't faint the user if it misses")
TO_DO_BATTLE_TEST("Final Gambit doesn't trigger the user's Focus Band")
TO_DO_BATTLE_TEST("Final Gambit doesn't trigger the user's Focus Sash")
TO_DO_BATTLE_TEST("Final Gambit doesn't trigger the user's Sturdy")
TO_DO_BATTLE_TEST("Final Gambit triggers the target's Focus Band")
TO_DO_BATTLE_TEST("Final Gambit triggers the target's Focus Sash")
TO_DO_BATTLE_TEST("Final Gambit triggers the target's Sturdy")
TO_DO_BATTLE_TEST("Final Gambit triggers the target's Endure")
TO_DO_BATTLE_TEST("Final Gambit fails in Max Raids")
TO_DO_BATTLE_TEST("Final Gambit fails in Tera Raids")
