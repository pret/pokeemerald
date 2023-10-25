#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
}

SINGLE_BATTLE_TEST("Clear Amulet prevents Intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); };
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Foe Wobbuffet's Clear Amulet prevents its stats from being lowered!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Clear Amulet prevents stat reducing effects")
{
    u32 move;

    PARAMETRIZE { move = MOVE_GROWL; }
    PARAMETRIZE { move = MOVE_LEER; }
    PARAMETRIZE { move = MOVE_CONFIDE; }
    PARAMETRIZE { move = MOVE_FAKE_TEARS; }
    PARAMETRIZE { move = MOVE_SCARY_FACE; }
    PARAMETRIZE { move = MOVE_SWEET_SCENT; }
    PARAMETRIZE { move = MOVE_SAND_ATTACK; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_GROWL].effect == EFFECT_ATTACK_DOWN);
        ASSUME(gBattleMoves[MOVE_LEER].effect == EFFECT_DEFENSE_DOWN);
        ASSUME(gBattleMoves[MOVE_CONFIDE].effect == EFFECT_SPECIAL_ATTACK_DOWN);
        ASSUME(gBattleMoves[MOVE_FAKE_TEARS].effect == EFFECT_SPECIAL_DEFENSE_DOWN_2);
        ASSUME(gBattleMoves[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(B_UPDATED_MOVE_DATA >= GEN_6);
        ASSUME(gBattleMoves[MOVE_SWEET_SCENT].effect == EFFECT_EVASION_DOWN_2);
        ASSUME(gBattleMoves[MOVE_SAND_ATTACK].effect == EFFECT_ACCURACY_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); };
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Clear Amulet prevents its stats from being lowered!");
    }
}

SINGLE_BATTLE_TEST("Clear Amulet prevents secondary effects that reduce stats")
{
    u32 move;

    PARAMETRIZE { move = MOVE_AURORA_BEAM; }
    PARAMETRIZE { move = MOVE_ROCK_SMASH; }
    PARAMETRIZE { move = MOVE_SNARL; }
    PARAMETRIZE { move = MOVE_PSYCHIC; }
    PARAMETRIZE { move = MOVE_BUBBLE_BEAM; }
    PARAMETRIZE { move = MOVE_MUD_SLAP; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_AURORA_BEAM].effect == EFFECT_ATTACK_DOWN_HIT);
        ASSUME(gBattleMoves[MOVE_ROCK_SMASH].effect == EFFECT_DEFENSE_DOWN_HIT);
        ASSUME(gBattleMoves[MOVE_SNARL].effect == EFFECT_SPECIAL_ATTACK_DOWN_HIT);
        ASSUME(gBattleMoves[MOVE_PSYCHIC].effect == EFFECT_SPECIAL_DEFENSE_DOWN_HIT);
        ASSUME(gBattleMoves[MOVE_BUBBLE_BEAM].effect == EFFECT_SPEED_DOWN_HIT);
        ASSUME(gBattleMoves[MOVE_MUD_SLAP].effect == EFFECT_ACCURACY_DOWN_HIT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); };
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Wobbuffet's Clear Amulet prevents its stats from being lowered!");
        }
    }
}
