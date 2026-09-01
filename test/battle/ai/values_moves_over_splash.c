#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

// All tests here compare the move to Splash, a move that does nothing and scores 90: the same as Thundershock on a ground type.
// The switch case for effects skips moves that have been human reviewed in three categories: something is wrong in some way; the move is equivalent to Splash for a good reason but a test is not known to exist; a test is known to exist.
// Jump to "TODO: AI HANDLING" and "TODO: AI TESTS"
// In many cases, AI handling exists but is likely insufficient in some way.

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 1-100")
{
    enum Move moveStart = MOVE_NONE;
    enum Move moveCap = 100;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_MIST:
        case EFFECT_TELEPORT:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_DISABLE:

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_GROWTH:
            break;

        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_DISABLE:
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;
        case EFFECT_OHKO:
            TURN { EXPECT_MOVE(opponentLeft, move); SEND_OUT(playerLeft, 2); }
            break;
        case EFFECT_CONFUSE:
            TURN { EXPECT_MOVE(opponentRight, move); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 101-200")
{
    enum Move moveStart = 100;
    enum Move moveCap = 200;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_LIGHT_SCREEN:
        case EFFECT_REFLECT:
        case EFFECT_BIDE:
        case EFFECT_NIGHTMARE:
        case EFFECT_SKETCH:
        case EFFECT_STAT_CHANGE_HALF_HP:
        case EFFECT_BELLY_DRUM:
        case EFFECT_DESTINY_BOND:
        case EFFECT_MIRROR_MOVE:
        case EFFECT_SUBSTITUTE:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_MIMIC:
        case EFFECT_SOFTBOILED:
        case EFFECT_DREAM_EATER:
        case EFFECT_CONVERSION:
        case EFFECT_PERISH_SONG:
        case EFFECT_FOCUS_ENERGY:
        case EFFECT_SPITE:

        // tests exist elsewhere
        case EFFECT_DEFENSE_CURL:
        case EFFECT_STAT_CHANGE:
        case EFFECT_HAZE:
        case EFFECT_REST:
        case EFFECT_SNORE:
        case EFFECT_MINIMIZE:

        // Skipped on purpose.
        case EFFECT_PROTECT:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_DO_NOTHING:
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;
        case EFFECT_OHKO:
            TURN { EXPECT_MOVE(opponentLeft, move); SEND_OUT(playerLeft, 2); }
            break;
        case EFFECT_CONFUSE:
            TURN { EXPECT_MOVE(opponentRight, move); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 201-300")
{
    enum Move moveStart = 200;
    enum Move moveCap = 300;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_SAFEGUARD:
        case EFFECT_FOLLOW_ME:
        case EFFECT_SNATCH:
        case EFFECT_GRUDGE:
        case EFFECT_CAMOUFLAGE:
        case EFFECT_IMPRISON:
        case EFFECT_INGRAIN:
        case EFFECT_MAGIC_COAT:
        case EFFECT_MUD_SPORT:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_SOFTBOILED:
        case EFFECT_ENDURE:
        case EFFECT_BATON_PASS:
        case EFFECT_ENCORE:
        case EFFECT_MORNING_SUN:
        case EFFECT_MOONLIGHT:
        case EFFECT_SYNTHESIS:
        case EFFECT_SPIT_UP:
        case EFFECT_SWALLOW:
        case EFFECT_WISH:

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_CHARGE:
        case EFFECT_STOCKPILE:
        case EFFECT_HEAL_BELL:
        case EFFECT_WEATHER:
        case EFFECT_ROLE_PLAY:
        case EFFECT_REFRESH:

        // Skipped on purpose.
        case EFFECT_PROTECT:
        case EFFECT_NON_VOLATILE_STATUS:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_RECYCLE:
        case EFFECT_SLEEP_TALK:
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;
        case EFFECT_SWAGGER:
            TURN { SCORE_LT_VAL(opponentRight, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 301-400")
{
    enum Move moveStart = 300;
    enum Move moveCap = 400;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_WATER_SPORT:
        case EFFECT_LUCKY_CHANT:
        case EFFECT_ME_FIRST:
        case EFFECT_PSYCHO_SHIFT:
        case EFFECT_COPYCAT:
        case EFFECT_LAST_RESORT:
        case EFFECT_AQUA_RING:
        case EFFECT_HEALING_WISH:
        case EFFECT_LUNAR_DANCE:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_ROOST:
        case EFFECT_TAILWIND:
        case EFFECT_POWER_TRICK:
        case EFFECT_MAGNET_RISE:

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_GRAVITY:
        case EFFECT_HEAL_BELL:

        // Skipped on purpose.
        case EFFECT_PROTECT:
        case EFFECT_NON_VOLATILE_STATUS:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_GUARD_SWAP:
        case EFFECT_POWER_SWAP:
        case EFFECT_HEART_SWAP:
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;
        case EFFECT_OHKO:
            TURN { EXPECT_MOVE(opponentLeft, move); SEND_OUT(playerLeft, 2); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 401-500")
{
    enum Move moveStart = 400;
    enum Move moveCap = 500;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_HEALING_WISH:
        case EFFECT_LUNAR_DANCE:
        case EFFECT_WONDER_ROOM:
        case EFFECT_FOLLOW_ME:
        case EFFECT_MAGIC_ROOM:
        case EFFECT_AFTER_YOU:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_DARK_VOID: // Gen 4-6's case is not being handled

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_AUTOTOMIZE:
        case EFFECT_TRICK_ROOM:
        case EFFECT_GUARD_SPLIT:
        case EFFECT_POWER_SPLIT:

        // Skipped on purpose.
        case EFFECT_PROTECT:
        case EFFECT_NON_VOLATILE_STATUS:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_CAPTIVATE:
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 501-600")
{
    enum Move moveStart = 515;
    enum Move moveCap = 600;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_ALLY_SWITCH:
        case EFFECT_QUASH:
        case EFFECT_REFLECT_TYPE:
        case EFFECT_SKY_DROP:
        case EFFECT_MAT_BLOCK:
        case EFFECT_ION_DELUGE:
        case EFFECT_POWDER:
        case EFFECT_ELECTRIFY:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_HEAL_PULSE:
        case EFFECT_BELCH:
        case EFFECT_TOPSY_TURVY:
        case EFFECT_FAIRY_LOCK:

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_ROTOTILLER:
        case EFFECT_FLOWER_SHIELD:
        case EFFECT_TERRAIN:

        // Skipped on purpose.
        case EFFECT_PROTECT:
        case EFFECT_NON_VOLATILE_STATUS:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_FINAL_GAMBIT:
            TURN { EXPECT_MOVE(opponentLeft, move); SEND_OUT(playerLeft, 2); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 601-700")
{
    enum Move moveStart = 600;
    enum Move moveCap = 700;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_NO_RETREAT:
        case EFFECT_TEATIME:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_SHORE_UP:
        case EFFECT_HEAL_PULSE:
        case EFFECT_LASER_FOCUS:
        case EFFECT_PURIFY:
        case EFFECT_INSTRUCT:
        case EFFECT_SOAK:

        // Needs Snow / Hail on the field
        case EFFECT_AURORA_VEIL:

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_STUFF_CHEEKS:
        case EFFECT_GEOMANCY:
        case EFFECT_TERRAIN:

        // Skipped on purpose.
        case EFFECT_PROTECT:
        case EFFECT_NON_VOLATILE_STATUS:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_DO_NOTHING:
        case EFFECT_HOLD_HANDS:
        case EFFECT_CELEBRATE:
        case EFFECT_HAPPY_HOUR:
        case EFFECT_STAT_CHANGE_MAGNETIC:
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;

        case EFFECT_FAIL_IF_NOT_ARG_TYPE:
            TURN { NOT_EXPECT_MOVE(opponentLeft, move); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 701-800")
{
    enum Move moveStart = 700;
    enum Move moveCap = 800;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_CLANGOROUS_SOUL:
        case EFFECT_POLTERGEIST:
        case EFFECT_REVIVAL_BLESSING:

        //TODO: AI TESTS
        case EFFECT_RESTORE_HP:
        case EFFECT_JUNGLE_HEALING:
        case EFFECT_POWER_TRICK:
        case EFFECT_TAKE_HEART:

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_STAT_CHANGE_HALF_HP:
        case EFFECT_COURT_CHANGE:
        case EFFECT_DOODLE:
        case EFFECT_LIFE_DEW:

        // Skipped on purpose.
        case EFFECT_PROTECT:
        case EFFECT_NON_VOLATILE_STATUS:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        switch (GetMoveEffect(move))
        {
        case EFFECT_STEEL_ROLLER:
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: playerLeft); }
            break;
        default:
            TURN { EXPECT_MOVE(opponentLeft, move); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI values moves above Splash, 801-900")
{
    enum Move moveStart = 800;
    enum Move moveCap = 900;

    if (moveCap > MOVES_COUNT)
        moveCap = MOVES_COUNT - 1;

    enum Move move = MOVE_NONE;

    enum BattleMoveEffects effect;

    for (u32 j = moveStart + 1; j <= moveCap; j++)
    {
        effect = GetMoveEffect(j);

        switch (effect)
        {
        //TODO: AI HANDLING
        case EFFECT_SHED_TAIL:
        case EFFECT_FAIL_IF_NOT_ARG_TYPE:

        //TODO: AI TESTS
        case EFFECT_WEATHER_AND_SWITCH:
        case EFFECT_TIDY_UP:

        // tests exist elsewhere
        case EFFECT_STAT_CHANGE:
        case EFFECT_DRAGON_CHEER:
            break;
        case EFFECT_WEATHER:
            if (GetMoveWeatherType(j) == BATTLE_WEATHER_SNOW)
                break;
            else
                PARAMETRIZE { move = j; }
            break;
        // Skipped on purpose.
        case EFFECT_PROTECT:
        case EFFECT_NON_VOLATILE_STATUS:
            break;
        default:
            PARAMETRIZE { move = j; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, move); Status1(STATUS1_BURN); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, move); Item(ITEM_STARF_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, move); }
    }
}
