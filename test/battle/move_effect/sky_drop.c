#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SKY_DROP) == EFFECT_SKY_DROP);
}

SINGLE_BATTLE_TEST("Sky Drop does no damage to Flying type Pokémon")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_PIDGEY].weight < 2000);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(player, MOVE_SKY_DROP); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        MESSAGE("Wobbuffet took the opposing Pidgey into the sky!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Sky Drop fails if target is behind a substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SKY_DROP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
    }
}

SINGLE_BATTLE_TEST("Sky Drop fails if target is in a Semi-Invulnerable state")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLY); MOVE(player, MOVE_SKY_DROP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
    }
}

DOUBLE_BATTLE_TEST("Sky Drop is cancelled if Gravity activated")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft);
            MOVE(playerRight, MOVE_GRAVITY);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAVITY, playerRight);
        MESSAGE("Wobbuffet fell from the sky due to the gravity!");
    }
}

SINGLE_BATTLE_TEST("Sky Drop fails on targets heavier or equal than 200kg")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_METAGROSS].weight >= 2000);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_METAGROSS);
    } WHEN {
        TURN { MOVE(player, MOVE_SKY_DROP); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
        MESSAGE("The opposing Metagross is too heavy to be lifted!");
    }
}

SINGLE_BATTLE_TEST("Sky Drop cancels targets two turn moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_SOLAR_BEAM);
            MOVE(player, MOVE_SKY_DROP);
        }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, opponent);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Sky Drop stops the confusion count until the target is dropped")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); }
        TURN { SKIP_TURN(player); }
        TURN { SKIP_TURN(player); }
        TURN { MOVE(opponent, MOVE_SKY_DROP); }
        TURN { SKIP_TURN(opponent); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
    }
}

SINGLE_BATTLE_TEST("Sky Drop fails if the targe is in a semi-invulnerable state")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLY); MOVE(player, MOVE_SKY_DROP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
    }
}

DOUBLE_BATTLE_TEST("Sky Drop will be canceled if it is electrified and holding a target with Volt Absorb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, target: playerLeft); MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft); }
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); SKIP_TURN(playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponentRight);
        ABILITY_POPUP(opponentLeft, ABILITY_VOLT_ABSORB);
        NOT HP_BAR(opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Sky Drop fails if the target fainted while it was held on air")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SKY_DROP); SEND_OUT(opponent, 1); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
    }
}

DOUBLE_BATTLE_TEST("Sky Drop will be canceled if it is electrified and holding a target with Volt Absorb before checking if it is a flying Type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WATTREL) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, target: playerLeft); MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft); }
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); SKIP_TURN(playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponentRight);
        NOT MESSAGE("It doesn't affect the opposing Wattrel…");
        ABILITY_POPUP(opponentLeft, ABILITY_VOLT_ABSORB);
        NOT HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Sky Drop does not trigger Volt Absorb on it's charge turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIFY, target: playerLeft); MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft); }
        TURN { SKIP_TURN(playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIFY, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        NOT ABILITY_POPUP(opponentLeft, ABILITY_VOLT_ABSORB);
        HP_BAR(opponentLeft); // Drop turn. Not affected by electrify anymore
    }
}


SINGLE_BATTLE_TEST("Sky Drop: If target was locked into a move that would confuse, the target will be freed and confusion occurs immediately")
{
    GIVEN {
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THRASH); MOVE(opponent, MOVE_SKY_DROP);}
        TURN { SKIP_TURN(opponent); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DROUGHT);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        MESSAGE("The sunlight is strong.");
    }
}

DOUBLE_BATTLE_TEST("Sky Drop: If target was locked into a move that would confuse, the target will be freed and confusion occurs immediately (attacker faints due to status)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(2); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_THRASH, target: opponentRight);
            MOVE(opponentLeft, MOVE_SKY_DROP, target: playerLeft);
            SEND_OUT(opponentLeft, 2);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Sky Drop: If target was locked into a move that would confuse, the target will be freed and confusion occurs immediately (attacker faints due to target ability)")
{
    GIVEN {
        PLAYER(SPECIES_SHARPEDO) { Ability(ABILITY_ROUGH_SKIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(2); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_THRASH, target: opponentRight);
            MOVE(opponentLeft, MOVE_SKY_DROP, target: playerLeft);
        }
        TURN {
            SKIP_TURN(opponentLeft);
            SEND_OUT(opponentLeft, 2);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft); // 1st turn
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, opponentLeft); // 2nd turn
        ABILITY_POPUP(playerLeft, ABILITY_ROUGH_SKIN);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Sky Drop: Flying types will still get confused if they rampaged before being dropped")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_PIDGEY].weight < 2000);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THRASH); MOVE(player, MOVE_SKY_DROP); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THRASH, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
        NOT HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponent);
    }
}

DOUBLE_BATTLE_TEST("Sky Drop user and target can't activate Eject items while the move is being used")
{
    enum Item item;

    PARAMETRIZE { item = ITEM_EJECT_BUTTON; }
    PARAMETRIZE { item = ITEM_EJECT_PACK; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_EJECT_BUTTON) == HOLD_EFFECT_EJECT_BUTTON);
        ASSUME(GetItemHoldEffect(ITEM_EJECT_PACK) == HOLD_EFFECT_EJECT_PACK);
        ASSUME(gSpeciesInfo[SPECIES_VULLABY].weight < 2000);
        ASSUME(GetSpeciesType(SPECIES_VULLABY, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_VULLABY, 1) == TYPE_FLYING);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_BREAKING_SWIPE, MOVE_EFFECT_STAT_MINUS, 100));
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VULLABY) { Item(item); } // Flying type used here so Sky Drop doesn't damage
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft);
               MOVE(opponentRight, MOVE_BREAKING_SWIPE);
               MOVE(playerRight, MOVE_BREAKING_SWIPE); }
        TURN { SKIP_TURN(playerLeft);
               MOVE(opponentRight, MOVE_BREAKING_SWIPE);
               MOVE(playerRight, MOVE_BREAKING_SWIPE);
               SEND_OUT(playerLeft, 2);
               SEND_OUT(opponentLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKING_SWIPE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKING_SWIPE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKING_SWIPE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKING_SWIPE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Sky Drop does not mistake a replacement using Fly for its original target")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        ASSUME(GetTwoTurnMoveSemiInvulnerability(MOVE_FLY) == STATE_ON_AIR);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); HP(1); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(player, MOVE_SKY_DROP); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_FLY); SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->hp, opponent->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Sky Drop does not mistake a replacement being held by another battler's Sky Drop for its original target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); HP(1); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SKY_DROP, target: opponentLeft); SEND_OUT(opponentLeft, 2); }
        TURN { MOVE(playerRight, MOVE_SKY_DROP, target: opponentLeft); SKIP_TURN(playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SKY_DROP, playerLeft);
            HP_BAR(opponentLeft);
        }
    } THEN {
        EXPECT_EQ(opponentLeft->hp, opponentLeft->maxHP);
    }
}
