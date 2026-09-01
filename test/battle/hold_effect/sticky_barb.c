#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_STICKY_BARB) == HOLD_EFFECT_STICKY_BARB);
}

SINGLE_BATTLE_TEST("Sticky Barb hurts its holder at the end of the turn")
{
    s16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_STICKY_BARB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, player->maxHP / 8);
    }
}

SINGLE_BATTLE_TEST("Sticky Barb gets transferred if its holder is hit by a contact move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_GROWL; }
    PARAMETRIZE { move = MOVE_HYPER_VOICE; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_GROWL));
        ASSUME(!MoveMakesContact(MOVE_HYPER_VOICE));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_STICKY_BARB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (MoveMakesContact(move))
        {
            MESSAGE("The Sticky Barb attached itself to the opposing Wobbuffet!");
            MESSAGE("The opposing Wobbuffet was hurt by the Sticky Barb!");
        }
        else
        {
            NOT MESSAGE("The Sticky Barb attached itself to the opposing Wobbuffet!");
            MESSAGE("Wobbuffet was hurt by the Sticky Barb!");
        }
    }
}
