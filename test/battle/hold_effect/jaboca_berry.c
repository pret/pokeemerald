#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_JABOCA_BERRY].holdEffect == HOLD_EFFECT_JABOCA_BERRY);
    ASSUME(gBattleMoves[MOVE_TACKLE].split == SPLIT_PHYSICAL);
}

SINGLE_BATTLE_TEST("Jaboca Berry causes the attacker to lose 1/8 of its max HP if a physical move was used")
{
    s16 damage;
    u16 move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_TACKLE; }

    GIVEN {
        ASSUME(gBattleMoves[MOVE_SWIFT].split == SPLIT_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_TACKLE) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            HP_BAR(player, captureDamage: &damage);
            MESSAGE("Wobbuffet was hurt by Foe Wobbuffet's Jaboca Berry!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
                MESSAGE("Wobbuffet was hurt by Foe Wobbuffet's Jaboca Berry!");
            }
        }
    } THEN {
        if (move == MOVE_TACKLE)
            EXPECT_EQ(player->maxHP / 8, damage);
    }
}

SINGLE_BATTLE_TEST("Jaboca Berry tirggers before Bug Bite can steal it")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_BUG_BITE].split == SPLIT_PHYSICAL);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        HP_BAR(player);
        MESSAGE("Wyanut was hurt by Foe Wobbuffet's Jaboca Berry!");
        NOT MESSAGE("Wynaut stole and ate Foe Wobbuffet's Jaboca Berry!");
    }
}
