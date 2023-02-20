#include "global.h"
#include "test_battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
}

SINGLE_BATTLE_TEST("Intimidate (opponent) lowers player's attack after switch out", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_INTIMIDATE; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STARAPTOR) { Ability(ability); };
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        if (ability == ABILITY_INTIMIDATE)
        {
            ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Foe Staraptor's Intimidate cuts Wobbuffet's ATTACK!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Intimidate (opponent) lowers player's attack after KO", s16 damage)
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_INTIMIDATE; }
    PARAMETRIZE { ability = ABILITY_RECKLESS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(1); };
        OPPONENT(SPECIES_STARAPTOR) { Ability(ability); Speed(1); };
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent);
        if (ability == ABILITY_INTIMIDATE)
        {
            ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Foe Staraptor's Intimidate cuts Wobbuffet's ATTACK!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Intimidate doesn't activate on an empty field in a double battle")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_EXPLOSION].effect == EFFECT_EXPLOSION);
        PLAYER(SPECIES_WOBBUFFET) { };
        PLAYER(SPECIES_WOBBUFFET) { HP(1); };
        PLAYER(SPECIES_STARAVIA) { Ability(ABILITY_INTIMIDATE); };
        PLAYER(SPECIES_ABRA);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
        OPPONENT(SPECIES_STARAPTOR) { Ability(ABILITY_INTIMIDATE); };
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPLOSION); SEND_OUT(playerLeft, 2); SEND_OUT(opponentLeft, 2); SEND_OUT(playerRight, 3); SEND_OUT(opponentRight, 3); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE);}
    } SCENE {
        HP_BAR(playerLeft, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        // Everyone faints.

        MESSAGE("Go! Staravia!");
        MESSAGE("2 sent out Staraptor!");
        MESSAGE("Go! Abra!");
        MESSAGE("2 sent out Wynaut!");

        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Staravia's Intimidate cuts Foe Staraptor's ATTACK!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Staravia's Intimidate cuts Foe Wynaut's ATTACK!");

        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Foe Staraptor's Intimidate cuts Staravia's ATTACK!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Foe Staraptor's Intimidate cuts Abra's ATTACK!");
    }
}
