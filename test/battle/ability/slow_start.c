#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Slow Start halves physical damage during the first five turns", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERCOAT; }
    PARAMETRIZE { ability = ABILITY_SLOW_START; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_VAROOM) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Slow Start does not reduce special damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERCOAT; }
    PARAMETRIZE { ability = ABILITY_SLOW_START; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ECHOED_VOICE) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_VAROOM) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Slow Start lasts five turns and resets after switching out", s16 damageBefore, s16 damageAfter)
{
    bool32 switchOut;
    PARAMETRIZE { switchOut = FALSE; }
    PARAMETRIZE { switchOut = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_VAROOM) { Ability(ABILITY_SLOW_START); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        if (switchOut) {
            TURN { SWITCH(player, 1); }
            TURN { SWITCH(player, 0); }
            TURN { MOVE(player, MOVE_SCRATCH); }
        } else {
            TURN { MOVE(player, MOVE_SCRATCH); }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damageBefore);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damageAfter);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damageBefore, Q_4_12(2.0), results[0].damageAfter);
        EXPECT_EQ(results[1].damageBefore, results[1].damageAfter);
    }
}

SINGLE_BATTLE_TEST("Slow Start halves Body Press damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERCOAT; }
    PARAMETRIZE { ability = ABILITY_SLOW_START; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BODY_PRESS) == EFFECT_BODY_PRESS);
        ASSUME(GetMoveCategory(MOVE_BODY_PRESS) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_VAROOM) { Ability(ability); Defense(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_BODY_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_PRESS, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Slow Start halves Foul Play damage", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_OVERCOAT; }
    PARAMETRIZE { ability = ABILITY_SLOW_START; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOUL_PLAY) == EFFECT_FOUL_PLAY);
        ASSUME(GetMoveCategory(MOVE_FOUL_PLAY) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_VAROOM) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(200); }
    } WHEN {
        TURN { MOVE(player, MOVE_FOUL_PLAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOUL_PLAY, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}
