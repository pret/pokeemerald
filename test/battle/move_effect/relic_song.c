#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_RELIC_SONG].effect == EFFECT_RELIC_SONG);
    ASSUME(MoveHasAdditionalEffect(MOVE_RELIC_SONG, MOVE_EFFECT_SLEEP) == TRUE);
}

SINGLE_BATTLE_TEST("Relic Song has a 10% chance to put the target to sleep")
{
    PASSES_RANDOMLY(10, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Relic Song is prevented by Soundproof")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SOUNDPROOF);
        MESSAGE("Foe Voltorb's Soundproof blocks Relic Song!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Relic Song will become a Water-type move when used by a Pokémon with the Ability Liquid Voice")
{
    GIVEN {
        PLAYER(SPECIES_VULPIX);
        OPPONENT(SPECIES_POPPLIO) { Ability(ABILITY_LIQUID_VOICE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, opponent);
        HP_BAR(player);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Relic Song is blocked by Throat Chop")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THROAT_CHOP); MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, opponent);
        HP_BAR(player);
        MESSAGE("Wobbuffet can't use Relic Song due to Throat Chop!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
    }
}

SINGLE_BATTLE_TEST("Relic Song transforms Meloetta if used successfully")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_PIROUETTE);
    }
}

SINGLE_BATTLE_TEST("Relic Song transforms Meloetta twice if used successfully")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_ARIA);
    }
}

SINGLE_BATTLE_TEST("Relic Song transformation is the last thing that happens after it hits")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_GOSSIFLEUR) { HP(1); Ability(ABILITY_COTTON_DOWN); }
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Foe Gossifleur fainted!");
        ABILITY_POPUP(opponent, ABILITY_COTTON_DOWN);
        MESSAGE("Meloetta's Speed fell!");
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_PIROUETTE);
    }
}

DOUBLE_BATTLE_TEST("Relic Song transforms once Meloetta in a double battle")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_MELOETTA_PIROUETTE);
    }
}

SINGLE_BATTLE_TEST("Relic Song loses the form-changing effect with Sheer Force")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        NOT MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_ARIA);
    }
}

SINGLE_BATTLE_TEST("Relic Song transforms Meloetta after Magician was activated")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); Item(ITEM_POTION); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_MAGICIAN);
        MESSAGE("Meloetta stole Foe Delphox's Potion!");
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_PIROUETTE);
    }
}
