#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_THOUSAND_ARROWS, MOVE_EFFECT_SMACK_DOWN) == TRUE);
    ASSUME(gMovesInfo[MOVE_THOUSAND_ARROWS].ignoreTypeIfFlyingAndUngrounded == TRUE);
}

SINGLE_BATTLE_TEST("Thousand Arrows does not ground mons behind substitutes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_THOUSAND_ARROWS); }
    } SCENE {
        NOT MESSAGE("Foe Skarmory fell straight down!");
    }
}

SINGLE_BATTLE_TEST("Thousand Arrows does neutral damage to non-grounded Flying types regardless of other typings")
{
    u32 pokemon;
    PARAMETRIZE { pokemon = SPECIES_SKARMORY; }
    PARAMETRIZE { pokemon = SPECIES_SCYTHER; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(pokemon);
    } WHEN {
        TURN { MOVE(player, MOVE_THOUSAND_ARROWS); }
        TURN { MOVE(player, MOVE_THOUSAND_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THOUSAND_ARROWS, player);
        if (pokemon == SPECIES_SKARMORY) {
            MESSAGE("Foe Skarmory fell straight down!");
            MESSAGE("Foe Skarmory used Celebrate!");
        } else {
            MESSAGE("Foe Scyther fell straight down!");
            MESSAGE("Foe Scyther used Celebrate!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("Congratulations, 1!");
        MESSAGE("Wobbuffet used ThousndArrws!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THOUSAND_ARROWS, player);
        if (pokemon == SPECIES_SKARMORY)
        {
            MESSAGE("It's super effective!");
        }
        else
        {
            MESSAGE("It's not very effective…");
        }
    }
}
