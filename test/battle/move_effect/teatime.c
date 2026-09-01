#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TEATIME) == EFFECT_TEATIME);
    ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].holdEffect == HOLD_EFFECT_ATTACK_UP);
}

SINGLE_BATTLE_TEST("Teatime causes the user to consume its Berry, ignoring HP requirements")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NONE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEATIME); }
    } SCENE {
        MESSAGE("Wobbuffet used Teatime!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, player);
        MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
    }
}

SINGLE_BATTLE_TEST("Teatime causes the user to consume its Berry, even in the pressence of Unnerve")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_UNNERVE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEATIME); }
    } SCENE {
        MESSAGE("Wobbuffet used Teatime!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, player);
        MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
    }
}

SINGLE_BATTLE_TEST("Teatime causes the user to consume its Berry, even under the effects of Magic Room")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_MAGIC_ROOM);
            MOVE(player, MOVE_TEATIME);
        }
    } SCENE {
        MESSAGE("Wobbuffet used Teatime!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, player);
        MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
    }
}

SINGLE_BATTLE_TEST("Teatime causes the user to consume its Berry, ignoring HP requirements, when not used by the Player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TEATIME); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Teatime!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, opponent);
        MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
    }
}

SINGLE_BATTLE_TEST("Teatime causes other Pokemon to consume their Berry even if the user doesn't have a Berry as its held item")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEATIME); }
    } SCENE {
        MESSAGE("Wobbuffet used Teatime!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, player);
        MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
    }
}

SINGLE_BATTLE_TEST("Teatime causes other Pokemon to consume their Berry even if the user doesn't have a Berry as its held item, when not used by the Player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NONE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TEATIME); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Teatime!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, opponent);
        MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
    }
}

DOUBLE_BATTLE_TEST("Teatime causes all Pokémon to consume their berry")
{
    struct BattlePokemon *user = NULL;
    PARAMETRIZE { user = playerLeft; }
    PARAMETRIZE { user = playerRight; }
    PARAMETRIZE { user = opponentLeft; }
    PARAMETRIZE { user = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_LIECHI_BERRY); }
    } WHEN {
        TURN { MOVE(user, MOVE_TEATIME); }
    } SCENE {
        if (user == playerLeft) {
            MESSAGE("Wobbuffet used Teatime!");
        } else if (user == playerRight) {
            MESSAGE("Wynaut used Teatime!");
        } else if (user == opponentLeft) {
            MESSAGE("The opposing Wobbuffet used Teatime!");
        } else {
            MESSAGE("The opposing Wynaut used Teatime!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, user);
        if (user == playerLeft) {
            MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted Wynaut's Attack!");
            MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted the opposing Wynaut's Attack!");
        } else if (user == playerRight) {
            MESSAGE("The Liechi Berry boosted Wynaut's Attack!");
            MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted the opposing Wynaut's Attack!");
        } else if (user == opponentLeft) {
            MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted the opposing Wynaut's Attack!");
            MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted Wynaut's Attack!");
        } else if (user == opponentRight) {
            MESSAGE("The Liechi Berry boosted the opposing Wynaut's Attack!");
            MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
            MESSAGE("The Liechi Berry boosted Wynaut's Attack!");
        }
    }
}

SINGLE_BATTLE_TEST("Teatime fails if no Pokémon is holding a Berry")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NONE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEATIME); }
    } SCENE {
        MESSAGE("Wobbuffet used Teatime!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, player);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Teatime does not affect Pokémon in the semi-invulnerable turn of a move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NONE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_FLY);
            MOVE(player, MOVE_TEATIME);
        }
    } SCENE {
        MESSAGE("Wobbuffet used Teatime!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, player);
            MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
        }
    }
}

SINGLE_BATTLE_TEST("Teatime triggers Volt Absorb if it has been affected by Electrify or Plasma Fists, even when not holding a Berry")
{
    enum Move move;
    enum Item item = ITEM_LIECHI_BERRY;
    bool32 shouldTriggerAbility = TRUE;

    PARAMETRIZE { move = MOVE_CELEBRATE; shouldTriggerAbility = FALSE; }
    PARAMETRIZE { move = MOVE_ELECTRIFY; }
    PARAMETRIZE { move = MOVE_PLASMA_FISTS; }
    PARAMETRIZE { move = MOVE_ELECTRIFY; item = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_PLASMA_FISTS; item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); Item(item); HP(55); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
    } WHEN {
        TURN {
            MOVE(player, move);
            MOVE(opponent, MOVE_TEATIME);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Teatime!");
        if (shouldTriggerAbility) {
            ABILITY_POPUP(player, ABILITY_VOLT_ABSORB);
            HP_BAR(player, damage: -25);
        } else {
            NOT ABILITY_POPUP(player, ABILITY_VOLT_ABSORB);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, opponent);
        MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
        if (shouldTriggerAbility) {
            NOT MESSAGE("The Liechi Berry boosted Jolteon's Attack!");
        } else {
            MESSAGE("The Liechi Berry boosted Jolteon's Attack!");
        }
    }
}

SINGLE_BATTLE_TEST("Teatime triggers Lightning Rod if it has been affected by Electrify or Plasma Fists, even when not holding a Berry")
{
    enum Move move;
    enum Item item = ITEM_LIECHI_BERRY;
    bool32 shouldTriggerAbility = TRUE;

    PARAMETRIZE { move = MOVE_CELEBRATE; shouldTriggerAbility = FALSE; }
    PARAMETRIZE { move = MOVE_ELECTRIFY; }
    PARAMETRIZE { move = MOVE_PLASMA_FISTS; }
    PARAMETRIZE { move = MOVE_ELECTRIFY; item = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_PLASMA_FISTS; item = ITEM_NONE; }

    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        PLAYER(SPECIES_PIKACHU) { Ability(ABILITY_LIGHTNING_ROD); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
    } WHEN {
        TURN {
            MOVE(player, move);
            MOVE(opponent, MOVE_TEATIME);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Teatime!");
        if (shouldTriggerAbility) {
            ABILITY_POPUP(player, ABILITY_LIGHTNING_ROD);
            MESSAGE("Pikachu's Sp. Atk rose!");
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_LIGHTNING_ROD);
                MESSAGE("Pikachu's Sp. Atk rose!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, opponent);
        MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
        if (shouldTriggerAbility) {
            NOT MESSAGE("The Liechi Berry boosted Pikachu's Attack!");
        } else {
            MESSAGE("The Liechi Berry boosted Pikachu's Attack!");
        }
    }
}

SINGLE_BATTLE_TEST("Teatime triggers Motor Drive if it has been affected by Electrify or Plasma Fists, even when not holding a Berry")
{
    enum Move move;
    enum Item item = ITEM_LIECHI_BERRY;
    bool32 shouldTriggerAbility = TRUE;

    PARAMETRIZE { move = MOVE_CELEBRATE; shouldTriggerAbility = FALSE; }
    PARAMETRIZE { move = MOVE_ELECTRIFY; }
    PARAMETRIZE { move = MOVE_PLASMA_FISTS; }
    PARAMETRIZE { move = MOVE_ELECTRIFY; item = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_PLASMA_FISTS; item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_ELECTIVIRE) { Ability(ABILITY_MOTOR_DRIVE); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIECHI_BERRY); }
    } WHEN {
        TURN {
            MOVE(player, move);
            MOVE(opponent, MOVE_TEATIME);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Teatime!");
        if (shouldTriggerAbility) {
            ABILITY_POPUP(player, ABILITY_MOTOR_DRIVE);
            MESSAGE("Electivire's Speed rose!");
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_MOTOR_DRIVE);
                MESSAGE("Electivire's Speed rose!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEATIME, opponent);
        MESSAGE("The Liechi Berry boosted the opposing Wobbuffet's Attack!");
        if (shouldTriggerAbility) {
            NOT MESSAGE("The Liechi Berry boosted Electivire's Attack!");
        } else {
            MESSAGE("The Liechi Berry boosted Electivire's Attack!");
        }
    }
}
