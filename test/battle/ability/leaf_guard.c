#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Leaf Guard prevents non-volatile status conditions in sun")
{
    u32 move;
    PARAMETRIZE { move = MOVE_WILL_O_WISP; }
    PARAMETRIZE { move = MOVE_HYPNOSIS; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; }
    PARAMETRIZE { move = MOVE_TOXIC; }
    PARAMETRIZE { move = MOVE_POWDER_SNOW; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_WILL_O_WISP].effect == EFFECT_WILL_O_WISP);
        ASSUME(gBattleMoves[MOVE_HYPNOSIS].effect == EFFECT_SLEEP);
        ASSUME(gBattleMoves[MOVE_THUNDER_WAVE].effect == EFFECT_PARALYZE);
        ASSUME(gBattleMoves[MOVE_TOXIC].effect == EFFECT_TOXIC);
        ASSUME(gBattleMoves[MOVE_POWDER_SNOW].effect == EFFECT_FREEZE_HIT);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, move); }
    } SCENE {
        switch (move)
        {
            case MOVE_WILL_O_WISP:
                MESSAGE("Foe Wobbuffet used Will-o-Wisp!");
                NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, opponent);
                ABILITY_POPUP(player, ABILITY_LEAF_GUARD);
                MESSAGE("It doesn't affect Leafeon…");
                break;
            case MOVE_HYPNOSIS:
                MESSAGE("Foe Wobbuffet used Hypnosis!");
                NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPNOSIS, opponent);
                ABILITY_POPUP(player, ABILITY_LEAF_GUARD);
                MESSAGE("It doesn't affect Leafeon…");
                break;
            case MOVE_THUNDER_WAVE:
                MESSAGE("Foe Wobbuffet used Thunder Wave!");
                NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, opponent);
                ABILITY_POPUP(player, ABILITY_LEAF_GUARD);
                MESSAGE("It doesn't affect Leafeon…");
                break;
            case MOVE_TOXIC:
                MESSAGE("Foe Wobbuffet used Toxic!");
                NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
                ABILITY_POPUP(player, ABILITY_LEAF_GUARD);
                MESSAGE("It doesn't affect Leafeon…");
                break;
            case MOVE_POWDER_SNOW:
                MESSAGE("Foe Wobbuffet used Powder Snow!");
                ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER_SNOW, opponent);
                MESSAGE("It's super effective!");
                break;
        }
        NONE_OF { STATUS_ICON(player, status1: TRUE); }
    }
}

SINGLE_BATTLE_TEST("Leaf Guard prevents status conditions from Flame Orb and Toxic Orb")
{
    u32 item;
    PARAMETRIZE { item = ITEM_FLAME_ORB; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; }
    GIVEN {
        ASSUME(gItems[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(gItems[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
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

SINGLE_BATTLE_TEST("Leaf Guard prevents Rest during sun")
{
    GIVEN {
        ASSUME(B_LEAF_GUARD_PREVENTS_REST >= GEN_5);
        ASSUME(gBattleMoves[MOVE_REST].effect == EFFECT_REST);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_REST); }
    } SCENE {
        MESSAGE("But it failed!");
        NOT STATUS_ICON(player, sleep: TRUE);
        NONE_OF { HP_BAR(player); }
    }
}
