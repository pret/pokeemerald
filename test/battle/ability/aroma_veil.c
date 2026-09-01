#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Taunt")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        ASSUME(GetMoveCategory(MOVE_HARDEN) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TAUNT, target: moveTarget); MOVE(moveTarget, MOVE_HARDEN); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, moveTarget);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from ally Taunt")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        ASSUME(GetMoveCategory(MOVE_HARDEN) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Speed(4); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TAUNT, target: playerLeft); MOVE(playerLeft, MOVE_HARDEN); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, playerRight);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Torment")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TORMENT) == EFFECT_TORMENT);
        ASSUME(GetMoveCategory(MOVE_HARDEN) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_TORMENT, target: moveTarget); MOVE(moveTarget, MOVE_HARDEN); }
        TURN { MOVE(moveTarget, MOVE_HARDEN); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, moveTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, moveTarget);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Encore")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        ASSUME(GetMoveCategory(MOVE_HARDEN) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ENCORE, target: moveTarget); MOVE(moveTarget, MOVE_HARDEN); }
        TURN { MOVE(moveTarget, MOVE_CELEBRATE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, moveTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, moveTarget);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Disable")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DISABLE) == EFFECT_DISABLE);
        ASSUME(GetMoveCategory(MOVE_HARDEN) == DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DISABLE, target: moveTarget); MOVE(moveTarget, MOVE_HARDEN); }
        TURN { MOVE(moveTarget, MOVE_HARDEN); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, moveTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HARDEN, moveTarget);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Cursed Body")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_PECK));
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_JELLICENT) { Ability(ABILITY_CURSED_BODY); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PECK, target: opponentLeft); MOVE(playerRight, MOVE_PECK, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_PECK, target: opponentLeft); MOVE(playerRight, MOVE_PECK, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PECK, playerLeft);
        NOT ABILITY_POPUP(opponentLeft, ABILITY_CURSED_BODY);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PECK, playerRight);
        NOT ABILITY_POPUP(opponentLeft, ABILITY_CURSED_BODY);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PECK, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PECK, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Heal Block")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        ASSUME(GetMoveEffect(MOVE_RECOVER) == EFFECT_RESTORE_HP);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_HEAL_BLOCK, target: moveTarget); MOVE(moveTarget, MOVE_RECOVER); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BLOCK, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, moveTarget);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Infatuation")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ATTRACT, target: moveTarget); MOVE(moveTarget, MOVE_CELEBRATE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, moveTarget);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil protects the Pokémon's side from Destiny Knot infatuation")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
        ASSUME(gItemsInfo[ITEM_DESTINY_KNOT].holdEffect == HOLD_EFFECT_DESTINY_KNOT);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); Gender(MON_MALE); }
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_MALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_DESTINY_KNOT); Gender(MON_FEMALE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(moveTarget, MOVE_ATTRACT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, moveTarget);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        MESSAGE("But it failed!");
    } THEN {
        EXPECT(!moveTarget->volatiles.infatuation);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil does not protect the Pokémon's side from Imprison")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_IMPRISON) == EFFECT_IMPRISON);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_IMPRISON, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_IMPRISON); MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IMPRISON, opponentLeft);
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLASH, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Aroma Veil prevents Psychic Noise's effect")
{
    struct BattlePokemon *moveTarget = NULL;
    PARAMETRIZE { moveTarget = playerLeft; }
    PARAMETRIZE { moveTarget = playerRight; }
    GIVEN {
        ASSUME(GetMoveAdditionalEffectById(MOVE_PSYCHIC_NOISE, 0)->moveEffect == MOVE_EFFECT_PSYCHIC_NOISE);
        PLAYER(SPECIES_AROMATISSE) { Ability(ABILITY_AROMA_VEIL); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PSYCHIC_NOISE, target: moveTarget); MOVE(moveTarget, MOVE_RECOVER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_NOISE, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_AROMA_VEIL);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, moveTarget);
    }
}

// Marked in Bulbapedia as need of research
//TO_DO_BATTLE_TEST("Aroma Veil prevents G-Max Meltdown's effect");
