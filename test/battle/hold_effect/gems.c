#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_NORMAL_GEM].holdEffect == HOLD_EFFECT_GEMS);
}

SINGLE_BATTLE_TEST("Gem is consumed when it corresponds to the type of a move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Fire Gem strengthened Wobbuffet's power!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Normal Gem strengthened Wobbuffet's power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("Gem boost is only applied once")
{
    s16 boostedHit;
    s16 normalHit;

    GIVEN {
        ASSUME(I_GEM_BOOST_POWER >= GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Normal Gem strengthened Wobbuffet's power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &boostedHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        HP_BAR(opponent, captureDamage: &normalHit);
    } THEN {
        EXPECT_MUL_EQ(normalHit, Q_4_12(1.3), boostedHit);
    }
}

SINGLE_BATTLE_TEST("Gem modifier is used for all hits of Multi Hit Moves")
{
    s16 firstHit;
    s16 secondHit;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMAL_GEM); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_DOUBLE_HIT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_HIT, player);
        HP_BAR(opponent, captureDamage: &secondHit);
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
    }
}

SINGLE_BATTLE_TEST("Gem is consumed if the move type is changed")
{
    GIVEN {
        PLAYER(SPECIES_DELCATTY) { Ability(ABILITY_NORMALIZE); Item(ITEM_NORMAL_GEM); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_FEINT_ATTACK);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Normal Gem strengthened Delcatty's power!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FEINT_ATTACK, player);
    }
}
