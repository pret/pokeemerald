#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].type == TYPE_NORMAL);
    ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);
}

SINGLE_BATTLE_TEST("Aerilate turns a Normal-type move into Flying-type move")
{
    GIVEN {
        PLAYER(SPECIES_MEGANIUM);
        OPPONENT(SPECIES_SALAMENCE) { Item(ITEM_SALAMENCITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("It's super effective!");
    }
}

TO_DO_BATTLE_TEST("Aerilate can not turn certain moves into Flying type moves");
TO_DO_BATTLE_TEST("Aerilate boosts power of affected moves by 20% (Gen7+)");
TO_DO_BATTLE_TEST("Aerilate boosts power of affected moves by 30% (Gen6)");

// Gen 6-7
TO_DO_BATTLE_TEST("Aerilate overrides Electrify (Gen6-7)");
TO_DO_BATTLE_TEST("Aerilate overrides Ion Deluge (Gen6-7)");
// Gen 8+
//TO_DO_BATTLE_TEST("Aerilate doesn't override Electrify (Gen8+)");  // No mon with Aerilate exists in Gen8+, but probably behaves similar to Pixilate, which does.
//TO_DO_BATTLE_TEST("Aerilate doesn't override Ion Deluge (Gen8+)"); // Ion Deluge doesn't exist in Gen 8+, but we probably could assume it behaves similar to under Electrify. TODO: Test by hacking SV.
