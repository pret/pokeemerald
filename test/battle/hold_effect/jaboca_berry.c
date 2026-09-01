#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_JABOCA_BERRY].holdEffect == HOLD_EFFECT_JABOCA_BERRY);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Jaboca Berry causes the attacker to lose 1/8 of its max HP if a physical move was used")
{
    s16 damage;
    enum Move move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_SCRATCH; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_SCRATCH) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
            HP_BAR(player, captureDamage: &damage);
            MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Jaboca Berry!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
                MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Jaboca Berry!");
            }
        }
    } THEN {
        if (move == MOVE_SCRATCH)
            EXPECT_EQ(player->maxHP / 8, damage);
    }
}

SINGLE_BATTLE_TEST("Jaboca Berry triggers before Bug Bite can steal it")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_BUG_BITE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        HP_BAR(player);
        MESSAGE("Wynaut was hurt by the opposing Wobbuffet's Jaboca Berry!");
        NOT MESSAGE("Wynaut stole and ate the opposing Wobbuffet's Jaboca Berry!");
    }
}

SINGLE_BATTLE_TEST("Jaboca Berry is triggered even if berry user faints")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(player);
        MESSAGE("Wobbuffet was hurt by the opposing Wobbuffet's Jaboca Berry!");
    }
}
