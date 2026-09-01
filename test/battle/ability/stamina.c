#include "global.h"
#include "test/battle.h"

#define STAMINA_STAT_RAISE(target, msg)                         \
{                                                               \
    ABILITY_POPUP(target, ABILITY_STAMINA);                     \
    ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, target);  \
    MESSAGE(msg);                                               \
}

#define STAMINA_HIT(attacker, target, move, msg, dmgVar)        \
{                                                               \
    ANIMATION(ANIM_TYPE_MOVE, move, attacker);                  \
    HP_BAR(target, captureDamage: &dmgVar);                     \
    STAMINA_STAT_RAISE(target, msg);                            \
}

SINGLE_BATTLE_TEST("Stamina raises Defense by 1 when hit by a move")
{
    s16 turnOneHit, turnTwoHit;
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_GUST; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_GUST) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STAMINA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, move); }
    } SCENE {
        STAMINA_HIT(opponent, player, move, "Wobbuffet's Defense rose!", turnOneHit);
        STAMINA_HIT(opponent, player, move, "Wobbuffet's Defense rose!", turnTwoHit);
    }
    THEN {
        if (move == MOVE_SCRATCH) {
            EXPECT_MUL_EQ(turnTwoHit, Q_4_12(1.5), turnOneHit);
        }
        else {
            EXPECT_EQ(turnTwoHit, turnOneHit);
        }
    }
}

DOUBLE_BATTLE_TEST("Stamina activates correctly for every battler with the ability when hit by a multi target move")
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_NONE, abilityRight = ABILITY_STAMINA; }
    PARAMETRIZE { abilityLeft = ABILITY_STAMINA, abilityRight = ABILITY_NONE; }
    PARAMETRIZE { abilityLeft = ABILITY_STAMINA, abilityRight = ABILITY_STAMINA; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET) { Ability(abilityLeft); Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(abilityRight); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(15); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);

        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Stamina's stat raise.
        HP_BAR(opponentRight);

        if (abilityLeft == ABILITY_STAMINA) {
            STAMINA_STAT_RAISE(playerLeft, "Wobbuffet's Defense rose!");
        }

        if (abilityRight == ABILITY_STAMINA) {
            STAMINA_STAT_RAISE(playerRight, "Wobbuffet's Defense rose!");
        }

        NOT HP_BAR(opponentLeft); // We need to check the attacker itself does NOT get damaged. There was an issue when the targets would get overwritten by the Stamina's stat raise.
    }
    THEN {
        EXPECT_NE(playerLeft->hp, playerLeft->maxHP);
        EXPECT_NE(playerRight->hp, playerRight->maxHP);
        EXPECT_NE(opponentRight->hp, opponentRight->maxHP);
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}

SINGLE_BATTLE_TEST("Stamina activates for every hit of a multi hit move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MUDBRAY) { Ability(ABILITY_STAMINA); }
    } WHEN {
        TURN { MOVE(player, MOVE_DOUBLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, player);
        HP_BAR(opponent);
        STAMINA_STAT_RAISE(opponent, "The opposing Mudbray's Defense rose!");
        STAMINA_STAT_RAISE(opponent, "The opposing Mudbray's Defense rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Stamina is not activated by users own Substitute")
{
    GIVEN {
        PLAYER(SPECIES_MUDBRAY) { Ability(ABILITY_STAMINA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Mudbray put in a substitute!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_STAMINA);
            MESSAGE("Mudbray's Defense rose!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}
