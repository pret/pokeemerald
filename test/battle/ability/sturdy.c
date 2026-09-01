#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sturdy prevents OHKO moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        PLAYER(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Fissure!");
        ABILITY_POPUP(player, ABILITY_STURDY);
        MESSAGE("It doesn't affect Geodude…");
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Sturdy prevents OHKOs (Gen5+)")
{
    u32 config;
    PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_STURDY, config);
        PLAYER(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); MaxHP(100); HP(100); }
        PLAYER(SPECIES_GEODUDE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_SEISMIC_TOSS);
            if (config < GEN_5) {
                SEND_OUT(player, 1);
            }
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponent);
        if (config >= GEN_5) {
            HP_BAR(player, hp: 1);
            ABILITY_POPUP(player, ABILITY_STURDY);
            MESSAGE("Geodude endured the hit!");
        } else {
            HP_BAR(player, hp: 0);
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_STURDY);
                MESSAGE("Geodude endured the hit!");
            }
            SEND_IN_MESSAGE("Geodude");
        }
    }
}

SINGLE_BATTLE_TEST("Sturdy does not prevent non-OHKOs")
{
    GIVEN {
        PLAYER(SPECIES_GEODUDE) { Ability(ABILITY_STURDY); MaxHP(100); HP(99); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, opponent);
        HP_BAR(player, hp: 0);
    }
}
