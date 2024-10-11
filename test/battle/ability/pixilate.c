#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].type == TYPE_NORMAL);
    ASSUME(gMovesInfo[MOVE_TACKLE].power > 0);
}

SINGLE_BATTLE_TEST("Pixilate turns a Normal-type move into a Fairy-type move")
{
    GIVEN {
        PLAYER(SPECIES_DRAGONITE);
        OPPONENT(SPECIES_ALTARIA) { Item(ITEM_ALTARIANITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("It's super effective!");
    }
}

TO_DO_BATTLE_TEST("Pixilate can not turn certain moves into Fairy type moves");
TO_DO_BATTLE_TEST("Pixilate boosts power of affected moves by 20% (Gen7+)");
TO_DO_BATTLE_TEST("Pixilate boosts power of affected moves by 30% (Gen6)");
TO_DO_BATTLE_TEST("(DYNAMAX) Pixilate turns Max Strike into Max Starfall when not used by Gigantamax Alcremie");
TO_DO_BATTLE_TEST("(DYNAMAX) Pixilate doesn't turn Max Strike into Max Starfall when used by Gigantamax Alcremie, instead becoming G-Max Finale");

// Gen 6-7
TO_DO_BATTLE_TEST("Pixilate overrides Electrify (Gen6-7)");
TO_DO_BATTLE_TEST("Pixilate overrides Ion Deluge (Gen6-7)");
// Gen 8+
TO_DO_BATTLE_TEST("Pixilate doesn't override Electrify (Gen8+)");
//TO_DO_BATTLE_TEST("Pixilate doesn't override Ion Deluge (Gen8+)"); // Ion Deluge doesn't exist in Gen 8+, but we probably could assume it behaves similar to under Electrify. TODO: Test by hacking SV.
