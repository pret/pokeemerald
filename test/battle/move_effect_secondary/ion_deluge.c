#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_PLASMA_FISTS, MOVE_EFFECT_ION_DELUGE) == TRUE);
}

SINGLE_BATTLE_TEST("Ion Duldge turns normal moves into electric for the remainder of the current turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ION_DELUGE) == EFFECT_ION_DELUGE);
        PLAYER(SPECIES_KRABBY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ION_DELUGE); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Krabby used Ion Deluge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ION_DELUGE, player);
        MESSAGE("A deluge of ions showers the battlefield!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("It's super effective!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Plasma Fists turns normal moves into electric for the remainder of the current turn")
{
    GIVEN {
        PLAYER(SPECIES_KRABBY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PLASMA_FISTS); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Krabby used Plasma Fists!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLASMA_FISTS, player);
        MESSAGE("A deluge of ions showers the battlefield!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("It's super effective!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Plasma Fists does not set up Ion Deluge if it does not connect")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_PHANPY, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_PHANPY, 1) == TYPE_GROUND);
        PLAYER(SPECIES_KRABBY);
        OPPONENT(SPECIES_PHANPY);
    } WHEN {
        TURN { MOVE(player, MOVE_PLASMA_FISTS); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Krabby used Plasma Fists!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PLASMA_FISTS, player);
            MESSAGE("A deluge of ions showers the battlefield!");
        }
        MESSAGE("The opposing Phanpy used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Plasma Fists type-changing effect does not override Pixilate")
{
    GIVEN {
        PLAYER(SPECIES_KRABBY) { Speed(300); }
        OPPONENT(SPECIES_SYLVEON) { Speed(1); Ability(ABILITY_PIXILATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PLASMA_FISTS); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Krabby used Plasma Fists!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLASMA_FISTS, player);
        MESSAGE("A deluge of ions showers the battlefield!");
        MESSAGE("The opposing Sylveon used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Plasma Fists type-changing effect is applied after Normalize")
{
    GIVEN {
        PLAYER(SPECIES_KRABBY);
        OPPONENT(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PLASMA_FISTS); MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        MESSAGE("Krabby used Plasma Fists!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLASMA_FISTS, player);
        MESSAGE("A deluge of ions showers the battlefield!");
        MESSAGE("The opposing Skitty used Ember!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Plasma Fists turns normal type dynamax-moves into electric type moves")
{
    GIVEN {
        PLAYER(SPECIES_KRABBY) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_PLASMA_FISTS); MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Krabby used Plasma Fists!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLASMA_FISTS, player);
        MESSAGE("A deluge of ions showers the battlefield!");
        MESSAGE("The opposing Wobbuffet used Max Lightning!");
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Plasma Fists turns normal moves into electric moves even if it hits a substitute")
{
    GIVEN {
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_PLASMA_FISTS); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PLASMA_FISTS, player);
        SUB_HIT(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player);
        }
    }
}
