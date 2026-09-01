#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Life Dew fails if user and partner are both at full hp")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LIFE_DEW); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LIFE_DEW, playerLeft);
        MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("Life Dew recovers 25% of hp for both user and partner")
{
    s16 healing[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LIFE_DEW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIFE_DEW, playerLeft);
        HP_BAR(playerLeft, captureDamage: &healing[0]);
        MESSAGE("Wobbuffet's HP was restored.");
        HP_BAR(playerRight, captureDamage: &healing[1]);
        MESSAGE("Wynaut's HP was restored.");
    } THEN {
        EXPECT_EQ(playerLeft->maxHP / 4, -healing[0]);
        EXPECT_EQ(playerRight->maxHP / 4, -healing[1]);
    }
}

SINGLE_BATTLE_TEST("Life Dew works in singles on user")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LIFE_DEW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIFE_DEW, player);
        HP_BAR(player);
        NOT HP_BAR(opponent);
    }
}

DOUBLE_BATTLE_TEST("Life Dew only works on user if partner is at full hp")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LIFE_DEW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIFE_DEW, playerLeft);
        HP_BAR(playerLeft);
        NOT HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Life Dew only works on partner if user is at full hp")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LIFE_DEW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIFE_DEW, playerLeft);
        NOT HP_BAR(playerLeft);
        HP_BAR(playerRight);
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Life Dew if it outheals your damage and outspeeds (singles)")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SHOULD_RECOVER);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Moves(MOVE_SCALD, MOVE_LIFE_DEW); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_LIFE_DEW); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Life Dew if it outheals your damage and outspeeds (doubles)")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SHOULD_RECOVER);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_TACKLE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Moves(MOVE_SCALD, MOVE_LIFE_DEW); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Moves(MOVE_SCALD); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE); MOVE(playerRight, MOVE_TACKLE); EXPECT_MOVE(opponentLeft, MOVE_LIFE_DEW); }
    }
}

