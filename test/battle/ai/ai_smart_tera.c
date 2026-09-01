#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_TERA: AI will tera if it enables a ko")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        ASSUME(GetMovePower(MOVE_AQUA_TAIL) == 90);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_TERA);
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_AQUA_TAIL, MOVE_SEED_BOMB); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SEED_BOMB, gimmick: GIMMICK_TERA); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet terastallized into the Grass type!");
        MESSAGE("Wobbuffet fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_TERA: AI will not tera if it gets outsped and ko'd")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        ASSUME(GetMovePower(MOVE_FLAMETHROWER) == 90);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_TERA | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(100); Moves(MOVE_FLAMETHROWER, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(60); Speed(1); Moves(MOVE_SEED_BOMB); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN {}
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet terastallized into the Grass type!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_TERA: AI will not tera if it gets ko'd by priority")
{
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_TERA | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(1); Moves(MOVE_QUICK_ATTACK, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); Moves(MOVE_SEED_BOMB, MOVE_AQUA_TAIL); TeraType(TYPE_GRASS); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN {  }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet terastallized into the Grass type!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_TERA: AI might tera if it gets saved from a ko")
{
    PASSES_RANDOMLY(90, 100, RNG_AI_CONSERVE_TERA);
    GIVEN {
        ASSUME(GetMovePower(MOVE_SEED_BOMB) == 80);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_TERA | AI_FLAG_OMNISCIENT );
        PLAYER(SPECIES_WOBBUFFET) { HP(47); Speed(100); Moves(MOVE_SEED_BOMB); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); HP(30); Moves(MOVE_SEED_BOMB); TeraType(TYPE_FIRE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); TeraType(TYPE_FIRE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEED_BOMB); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet terastallized into the Fire type!");
    }
}
