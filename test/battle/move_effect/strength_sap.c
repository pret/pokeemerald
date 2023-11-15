#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_STRENGTH_SAP].effect == EFFECT_STRENGTH_SAP);
}

SINGLE_BATTLE_TEST("Strength Sap lowers Attack by 1 and restores HP based on target's Attack Stat", s16 hp)
{
    u32 atkStat = 0;

    PARAMETRIZE{ atkStat = 100; }
    PARAMETRIZE{ atkStat = 50; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(atkStat); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Attack fell!");
        HP_BAR(player, captureDamage: &results[i].hp);
        MESSAGE("Foe Wobbuffet had its energy drained!");
    } THEN {
        EXPECT_EQ(results[i].hp * -1, atkStat);
    }
}

// Same as above, but Substitute is used before Strength Sap.
SINGLE_BATTLE_TEST("Strength Sap works exactly the same when attacker is behind substitute", s16 hp)
{
    u32 atkStat = 0;

    PARAMETRIZE{ atkStat = 100; }
    PARAMETRIZE{ atkStat = 50; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(atkStat); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_STRENGTH_SAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Attack fell!");
        HP_BAR(player, captureDamage: &results[i].hp);
        NOT MESSAGE("The SUBSTITUTE took damage for Foe Wobbuffet!");
        MESSAGE("Foe Wobbuffet had its energy drained!");
    } THEN {
        EXPECT_EQ(results[i].hp * -1, atkStat);
    }
}
