#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_ROWAP_BERRY].holdEffect == HOLD_EFFECT_ROWAP_BERRY);
}

SINGLE_BATTLE_TEST("Rowap Berry causes the attacker to lose 1/8 of its max HP if a special move was used")
{
    s16 damage;
    enum Move move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_SCRATCH; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_SWIFT) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
            HP_BAR(player, captureDamage: &damage);
            MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Rowap Berry!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
                MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Rowap Berry!");
            }
        }
    } THEN {
        if (move == MOVE_SWIFT)
            EXPECT_EQ(player->maxHP / 8, damage);
    }
}

SINGLE_BATTLE_TEST("Rowap Berry is not triggered by a physical move")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
            MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Rowap Berry!");
        }
    }
}

SINGLE_BATTLE_TEST("Rowap Berry is triggered even if berry user faints")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_TACKLE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(player);
        MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Rowap Berry!");
    }
}
