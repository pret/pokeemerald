#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_ROWAP_BERRY].holdEffect == HOLD_EFFECT_ROWAP_BERRY);
}

SINGLE_BATTLE_TEST("Rowap Berry causes the attacker to lose 1/8 of its max HP if a special move was used")
{
    s16 damage;
    u16 move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_TACKLE; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_SWIFT].split == SPLIT_SPECIAL);
        ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_SWIFT) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            HP_BAR(player, captureDamage: &damage);
            MESSAGE("Wobbuffet was hurt by Foe Wobbuffet's Rowap Berry!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
                MESSAGE("Wobbuffet was hurt by Foe Wobbuffet's Rowap Berry!");
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
        ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("Wobbuffet was hurt by Foe Wobbuffet's Rowap Berry!");
        }
    }
}
