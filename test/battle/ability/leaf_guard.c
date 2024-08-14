#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Leaf Guard prevents non-volatile status conditions in sun")
{
    u32 move;
    u16 status;
    PARAMETRIZE { move = MOVE_WILL_O_WISP; status = STATUS1_BURN; }
    PARAMETRIZE { move = MOVE_HYPNOSIS; status = STATUS1_SLEEP; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; status = STATUS1_PARALYSIS; }
    PARAMETRIZE { move = MOVE_TOXIC; status = STATUS1_TOXIC_POISON; }
    // PARAMETRIZE { move = MOVE_POWDER_SNOW; status = STATUS1_FREEZE; } // Pointless since you can't freeze in sunlight anyway
    GIVEN {
        ASSUME(gMovesInfo[MOVE_WILL_O_WISP].effect == EFFECT_WILL_O_WISP);
        ASSUME(gMovesInfo[MOVE_HYPNOSIS].effect == EFFECT_SLEEP);
        ASSUME(gMovesInfo[MOVE_THUNDER_WAVE].effect == EFFECT_PARALYZE);
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ABILITY_POPUP(player, ABILITY_LEAF_GUARD);
        MESSAGE("It doesn't affect Leafeon…");
        NOT STATUS_ICON(player, status);
    }
}

TO_DO_BATTLE_TEST("Leaf Guard doesn't prevent non-volatile status conditions if Cloud Nine/Air Lock is on the field");

SINGLE_BATTLE_TEST("Leaf Guard prevents status conditions from Flame Orb and Toxic Orb")
{
    u32 item;
    PARAMETRIZE { item = ITEM_FLAME_ORB; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        if (item == ITEM_FLAME_ORB) {
            NONE_OF { MESSAGE("Leafeon was burned!"); STATUS_ICON(player, burn: TRUE); }
        }
        else {
            NONE_OF { MESSAGE("Leafeon is badly poisoned!"); STATUS_ICON(player, poison: TRUE); }
        }
    }
}

TO_DO_BATTLE_TEST("Leaf Guard doesn't prevent status conditions from Flame Orb and Toxic Orb if Cloud Nine/Air Lock is on the field");

SINGLE_BATTLE_TEST("Leaf Guard prevents Rest during sun")
{
    GIVEN {
        ASSUME(B_LEAF_GUARD_PREVENTS_REST >= GEN_5);
        ASSUME(gMovesInfo[MOVE_REST].effect == EFFECT_REST);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_REST); }
    } SCENE {
        MESSAGE("But it failed!");
        NONE_OF {
            STATUS_ICON(player, sleep: TRUE);
            HP_BAR(player);
        }
    }
}

TO_DO_BATTLE_TEST("Leaf Guard doesn't prevent Rest if Cloud Nine/Air Lock is on the field");
