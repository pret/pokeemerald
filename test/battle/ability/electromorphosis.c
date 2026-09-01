#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Electromorphosis sets up Charge when hit by any move")
{
    s16 dmgBefore, dmgAfter;
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_GUST; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_GUST) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_THUNDER_SHOCK) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);

        PLAYER(SPECIES_BELLIBOLT) { Ability(ABILITY_ELECTROMORPHOSIS); Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_LIMBER); Speed(5); } // Limber, so it doesn't get paralyzed.
    }
    WHEN {
        TURN { MOVE(player, MOVE_THUNDER_SHOCK), MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_THUNDER_SHOCK), MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent, captureDamage: &dmgBefore);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_ELECTROMORPHOSIS);
        if (move == MOVE_SCRATCH) {
            MESSAGE("Being hit by Scratch charged Bellibolt with power!");
        }
        else {
            MESSAGE("Being hit by Gust charged Bellibolt with power!");
        }

        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent, captureDamage: &dmgAfter);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_ELECTROMORPHOSIS);
        if (move == MOVE_SCRATCH) {
            MESSAGE("Being hit by Scratch charged Bellibolt with power!");
        }
        else {
            MESSAGE("Being hit by Gust charged Bellibolt with power!");
        }
    }
    THEN {
        EXPECT_MUL_EQ(dmgBefore, Q_4_12(2.0), dmgAfter);
    }
}

SINGLE_BATTLE_TEST("Electromorphosis displays its message before fainting when triggered")
{
    GIVEN {
        PLAYER(SPECIES_BELLIBOLT) { Ability(ABILITY_ELECTROMORPHOSIS); HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_ELECTROMORPHOSIS);
        MESSAGE("Being hit by Scratch charged Bellibolt with power!");
        MESSAGE("Bellibolt fainted!");
    }
}

SINGLE_BATTLE_TEST("Electromorphosis triggers on each multistrike hit but Charge does not stack")
{
    s16 dmgBefore, dmgAfterSingleHit, dmgAfterMultiHit;
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_DOUBLE_HIT) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_THUNDER_SHOCK) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        PLAYER(SPECIES_BELLIBOLT) { Ability(ABILITY_ELECTROMORPHOSIS); Speed(10); }
        OPPONENT(SPECIES_PERSIAN) { Ability(ABILITY_LIMBER); Speed(20); MaxHP(500); HP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
        TURN { MOVE(opponent, MOVE_DOUBLE_HIT); }
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent, captureDamage: &dmgBefore);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_ELECTROMORPHOSIS);
        MESSAGE("Being hit by Scratch charged Bellibolt with power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent, captureDamage: &dmgAfterSingleHit);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, opponent);
        ABILITY_POPUP(player, ABILITY_ELECTROMORPHOSIS);
        MESSAGE("Being hit by Double Hit charged Bellibolt with power!");
        ABILITY_POPUP(player, ABILITY_ELECTROMORPHOSIS);
        MESSAGE("Being hit by Double Hit charged Bellibolt with power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent, captureDamage: &dmgAfterMultiHit);
    } THEN {
        EXPECT_MUL_EQ(dmgBefore, Q_4_12(2.0), dmgAfterSingleHit);
        EXPECT_EQ(dmgAfterSingleHit, dmgAfterMultiHit);
    }
}
