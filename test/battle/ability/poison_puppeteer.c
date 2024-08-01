#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
}

SINGLE_BATTLE_TEST("Poison Puppeteer confuses target if it was poisoned by a damaging move")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        MESSAGE("Foe Wobbuffet became confused!");
    }
}

SINGLE_BATTLE_TEST("Poison Puppeteer confuses target if it was (badly) poisoned by a status move")
{
    u32 move;

    PARAMETRIZE { move = MOVE_POISON_POWDER; }
    PARAMETRIZE { move = MOVE_TOXIC; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        if (move == MOVE_POISON_POWDER)
            STATUS_ICON(opponent, poison: TRUE);
        else
            STATUS_ICON(opponent, badPoison: TRUE);
        ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
        MESSAGE("Foe Wobbuffet became confused!");
    }
}

SINGLE_BATTLE_TEST("Poison Puppeteer does not trigger if poison is Toxic Spikes induced")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC_SPIKES].effect == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_PECHARUNT) { Ability(ABILITY_POISON_PUPPETEER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES);}
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        STATUS_ICON(opponent, poison: TRUE);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_POISON_PUPPETEER);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
            MESSAGE("Foe Wobbuffet became confused!");
        }
    }
}
