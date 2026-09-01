#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_DOUBLE_BATTLE_TEST("AI won't use a Weather changing move if partner already chose such move")
{
    enum Move j, k;
    static const enum Move weatherMoves[] = {MOVE_SUNNY_DAY, MOVE_HAIL, MOVE_RAIN_DANCE, MOVE_SANDSTORM, MOVE_SNOWSCAPE};
    enum Move weatherMoveLeft = MOVE_NONE, weatherMoveRight = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(weatherMoves); j++)
    {
        for (k = 0; k < ARRAY_COUNT(weatherMoves); k++)
        {
            PARAMETRIZE { weatherMoveLeft = weatherMoves[j]; weatherMoveRight = weatherMoves[k]; }
        }
    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(weatherMoveLeft); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH, weatherMoveRight); }
    } WHEN {
        TURN {
            NOT_EXPECT_MOVE(opponentRight, weatherMoveRight);
            SCORE_LT_VAL(opponentRight, weatherMoveRight, AI_SCORE_DEFAULT, target:playerLeft);
            SCORE_LT_VAL(opponentRight, weatherMoveRight, AI_SCORE_DEFAULT, target:playerRight);
            SCORE_LT_VAL(opponentRight, weatherMoveRight, AI_SCORE_DEFAULT, target:opponentLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not use Helping Hand if partner does not have any damage moves")
{
    enum Move move1 = MOVE_NONE, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE;

    PARAMETRIZE { move1 = MOVE_LEER; move2 = MOVE_TOXIC; }
    PARAMETRIZE { move1 = MOVE_ACUPRESSURE; move2 = MOVE_DOUBLE_TEAM; move3 = MOVE_TOXIC; move4 = MOVE_PROTECT; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HELPING_HAND, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move1, move2, move3, move4); }
    } WHEN {
        TURN {
            NOT_EXPECT_MOVE(opponentLeft, MOVE_HELPING_HAND);
            SCORE_LT_VAL(opponentLeft, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:playerLeft);
            SCORE_LT_VAL(opponentLeft, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:playerRight);
            SCORE_LT_VAL(opponentLeft, MOVE_HELPING_HAND, AI_SCORE_DEFAULT, target:opponentLeft);
        }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet used Helping Hand!");
    }
}

AI_DOUBLE_BATTLE_TEST("AI skips Trick/Bestow when items are missing or target already holds one")
{
    enum Move move = MOVE_NONE;
    enum Item atkItem = ITEM_NONE, targetItem = ITEM_NONE;

    PARAMETRIZE { move = MOVE_TRICK;  atkItem = ITEM_NONE;        targetItem = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_BESTOW; atkItem = ITEM_NONE;        targetItem = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_BESTOW; atkItem = ITEM_ORAN_BERRY;  targetItem = ITEM_LEFTOVERS; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Item(targetItem); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_SCRATCH); Item(atkItem); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponentLeft, move); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI skips Trick/Bestow with unexchangeable items")
{
    enum Move move = MOVE_NONE;
    enum Item atkItem = ITEM_NONE, targetItem = ITEM_NONE;

    PARAMETRIZE { move = MOVE_TRICK;  atkItem = ITEM_ORANGE_MAIL; targetItem = ITEM_NONE; }
    PARAMETRIZE { move = MOVE_TRICK;  atkItem = ITEM_ORAN_BERRY;  targetItem = ITEM_ORANGE_MAIL; }
    PARAMETRIZE { move = MOVE_BESTOW; atkItem = ITEM_ORANGE_MAIL; targetItem = ITEM_NONE; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Item(targetItem); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_SCRATCH); Item(atkItem); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponentLeft, move); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI skips Trick around Sticky Hold")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_LEFTOVERS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_PRESSURE); Item(ITEM_ORAN_BERRY); Moves(MOVE_TRICK, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_TRICK); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI skips Trick/Bestow if the target has a Substitute")
{
    enum Move move = MOVE_NONE;
    enum Item atkItem = ITEM_NONE, targetItem = ITEM_NONE;

    PARAMETRIZE { move = MOVE_TRICK;  atkItem = ITEM_ORAN_BERRY; targetItem = ITEM_LEFTOVERS; }
    PARAMETRIZE { move = MOVE_BESTOW; atkItem = ITEM_ORAN_BERRY; targetItem = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SUBSTITUTE, MOVE_CELEBRATE); Item(targetItem); Speed(20); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_SCRATCH); Item(atkItem); Speed(1); Attack(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SUBSTITUTE);
            MOVE(playerRight, MOVE_CELEBRATE);
        }
        TURN { NOT_EXPECT_MOVE(opponentLeft, move); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI considers status orbs and abilities for Trick/Bestow")
{
    enum Move move = MOVE_NONE;
    enum Item item = ITEM_NONE;
    u16 status = STATUS1_NONE;
    enum Species species = SPECIES_NONE;
    enum Ability ability = ABILITY_NONE;
    u8 turnToTrick = 0;

    PARAMETRIZE { move = MOVE_TRICK;  item = ITEM_TOXIC_ORB; status = STATUS1_NONE;   species = SPECIES_WAILMER; ability = ABILITY_PRESSURE;    turnToTrick = 1; }
    PARAMETRIZE { move = MOVE_TRICK;  item = ITEM_FLAME_ORB; status = STATUS1_NONE;   species = SPECIES_WAILMER; ability = ABILITY_PRESSURE;    turnToTrick = 1; }
    PARAMETRIZE { move = MOVE_BESTOW; item = ITEM_TOXIC_ORB; status = STATUS1_NONE;   species = SPECIES_GLISCOR; ability = ABILITY_POISON_HEAL; turnToTrick = 2; }
    PARAMETRIZE { move = MOVE_BESTOW; item = ITEM_FLAME_ORB; status = STATUS1_NONE;   species = SPECIES_RATTATA; ability = ABILITY_GUTS;        turnToTrick = 2; }
    PARAMETRIZE { move = MOVE_TRICK;  item = ITEM_TOXIC_ORB; status = STATUS1_POISON; species = SPECIES_GLISCOR; ability = ABILITY_POISON_HEAL; turnToTrick = 1; }
    PARAMETRIZE { move = MOVE_TRICK;  item = ITEM_FLAME_ORB; status = STATUS1_BURN;   species = SPECIES_RATTATA; ability = ABILITY_GUTS;        turnToTrick = 1; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); Item(item); Moves(move, MOVE_SCRATCH); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        if (turnToTrick == 1)
        {
            TURN { EXPECT_MOVE(opponentLeft, move, target: playerLeft); }
        }
        else if (turnToTrick == 2)
        {
            TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
            TURN { EXPECT_MOVE(opponentLeft, move, target: playerLeft); }
        }
        else
        {
            TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI gifts Utility Umbrella only when it removes the foe's weather benefit")
{
    enum Species weatherSpecies = SPECIES_NONE, targetSpecies = SPECIES_NONE, attackerSpecies = SPECIES_NONE;
    enum Ability weatherAbility = ABILITY_NONE, targetAbility = ABILITY_NONE, attackerAbility = ABILITY_NONE;
    bool32 expectTrick = FALSE;

    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_EXEGGCUTE; targetAbility = ABILITY_CHLOROPHYLL;      attackerSpecies = SPECIES_PARAS;   attackerAbility = ABILITY_DRY_SKIN; expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_FOMANTIS;  targetAbility = ABILITY_LEAF_GUARD;       attackerSpecies = SPECIES_WAILMER; attackerAbility = ABILITY_PRESSURE; expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_CHERRIM;   targetAbility = ABILITY_FLOWER_GIFT;      attackerSpecies = SPECIES_WAILMER; attackerAbility = ABILITY_PRESSURE; expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_TROPIUS;   targetAbility = ABILITY_SOLAR_POWER;      attackerSpecies = SPECIES_WAILMER; attackerAbility = ABILITY_PRESSURE; expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_KORAIDON;  targetAbility = ABILITY_ORICHALCUM_PULSE; attackerSpecies = SPECIES_WAILMER; attackerAbility = ABILITY_PRESSURE; expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_LOTAD;     targetAbility = ABILITY_SWIFT_SWIM;       attackerSpecies = SPECIES_PARAS;   attackerAbility = ABILITY_DRY_SKIN; expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_LOTAD;     targetAbility = ABILITY_RAIN_DISH;        attackerSpecies = SPECIES_WAILMER; attackerAbility = ABILITY_PRESSURE; expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_PARAS;     targetAbility = ABILITY_DRY_SKIN;         attackerSpecies = SPECIES_WAILMER; attackerAbility = ABILITY_PRESSURE; expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_WINGULL;   targetAbility = ABILITY_HYDRATION;        attackerSpecies = SPECIES_WAILMER; attackerAbility = ABILITY_PRESSURE; expectTrick = TRUE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(targetSpecies) { Ability(targetAbility); }
        PLAYER(weatherSpecies) { Ability(weatherAbility); }
        OPPONENT(attackerSpecies) { Ability(attackerAbility); Item(ITEM_UTILITY_UMBRELLA); Moves(MOVE_TRICK, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        if (expectTrick)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_TRICK, target: playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI steals Utility Umbrella to handle sun and Dry Skin but keeps its own weather perks")
{
    enum Species weatherSpecies = SPECIES_NONE, targetSpecies = SPECIES_NONE, attackerSpecies = SPECIES_NONE;
    enum Ability weatherAbility = ABILITY_NONE, targetAbility = ABILITY_NONE, attackerAbility = ABILITY_NONE;
    bool32 expectTrick = FALSE;

    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_PARAS;     attackerAbility = ABILITY_DRY_SKIN;         expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_PARAS;   targetAbility = ABILITY_DRY_SKIN; attackerSpecies = SPECIES_WAILMER;   attackerAbility = ABILITY_PRESSURE;         expectTrick = TRUE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_EXEGGCUTE; attackerAbility = ABILITY_CHLOROPHYLL;      expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_CHERRIM;   attackerAbility = ABILITY_FLOWER_GIFT;      expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_FOMANTIS;  attackerAbility = ABILITY_LEAF_GUARD;       expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_TROPIUS;   attackerAbility = ABILITY_SOLAR_POWER;      expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_TORKOAL;  weatherAbility = ABILITY_DROUGHT; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_KORAIDON;  attackerAbility = ABILITY_ORICHALCUM_PULSE; expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_LOTAD;     attackerAbility = ABILITY_SWIFT_SWIM;       expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_LOTAD;     attackerAbility = ABILITY_RAIN_DISH;        expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_WINGULL;   attackerAbility = ABILITY_HYDRATION;        expectTrick = FALSE; }
    PARAMETRIZE { weatherSpecies = SPECIES_POLITOED; weatherAbility = ABILITY_DRIZZLE; targetSpecies = SPECIES_WAILMER; targetAbility = ABILITY_PRESSURE; attackerSpecies = SPECIES_PARAS;     attackerAbility = ABILITY_DRY_SKIN;         expectTrick = FALSE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(targetSpecies) { Ability(targetAbility); Item(ITEM_UTILITY_UMBRELLA); }
        PLAYER(weatherSpecies) { Ability(weatherAbility); }
        OPPONENT(attackerSpecies) { Ability(attackerAbility); Item(ITEM_NONE); Moves(MOVE_TRICK, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        if (expectTrick)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_TRICK, target: playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI treats Harvest as a sun benefit only when a berry is involved")
{
    enum Item targetItem = ITEM_NONE;
    bool32 expectTrick = FALSE;

    PARAMETRIZE { targetItem = ITEM_ORAN_BERRY; expectTrick = TRUE; }
    PARAMETRIZE { targetItem = ITEM_LEFTOVERS;  expectTrick = FALSE; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        ASSUME(GetItemPocket(ITEM_ORAN_BERRY) == POCKET_BERRIES);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_EXEGGCUTE) { Ability(ABILITY_HARVEST); Item(targetItem); }
        PLAYER(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); }
        OPPONENT(SPECIES_WAILMER) { Ability(ABILITY_PRESSURE); Item(ITEM_UTILITY_UMBRELLA); Moves(MOVE_TRICK, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
    } WHEN {
        if (expectTrick)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_TRICK, target: playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not use a status move if partner already chose Helping Hand")
{
    enum Move j;
    enum Move statusMove = MOVE_NONE;

    for (j = MOVE_NONE + 1; j < MOVES_COUNT; j++)
    {
        if (GetMoveCategory(j) == DAMAGE_CATEGORY_STATUS) {
            PARAMETRIZE { statusMove = j; }
        }
    }

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, statusMove, MOVE_WATER_GUN); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, statusMove, MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HELPING_HAND, MOVE_EXPLOSION); }
        OPPONENT(SPECIES_BIBAREL) { Moves(MOVE_SCRATCH, statusMove, MOVE_WATER_GUN); Ability(ABILITY_SIMPLE); Item(ITEM_WHITE_HERB); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_HELPING_HAND);
            NOT_EXPECT_MOVE(opponentRight, statusMove);
            SCORE_LT_VAL(opponentRight, statusMove, AI_SCORE_DEFAULT, target:playerLeft);
            SCORE_LT_VAL(opponentRight, statusMove, AI_SCORE_DEFAULT, target:playerRight);
            SCORE_LT_VAL(opponentRight, statusMove, AI_SCORE_DEFAULT, target:opponentLeft);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Helping Hand!");
    }
}

TO_DO_BATTLE_TEST("AI understands Instruct")
TO_DO_BATTLE_TEST("AI understands Quick Guard")
TO_DO_BATTLE_TEST("AI understands Wide Guard")

AI_DOUBLE_BATTLE_TEST("AI won't use the same nondamaging move as its partner for no reason")
{
    u32 chance = 0;

    PARAMETRIZE { chance = 0; }
    PARAMETRIZE { chance = 100; }

    enum Move move;
    PARAMETRIZE { move = MOVE_AROMATHERAPY; }
    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_FOLLOW_ME; }
    PARAMETRIZE { move = MOVE_GRASSY_TERRAIN; }
    PARAMETRIZE { move = MOVE_GRAVITY; }
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_HEAL_BELL; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; }
    PARAMETRIZE { move = MOVE_LUCKY_CHANT; }
    PARAMETRIZE { move = MOVE_MAGIC_ROOM; }
    PARAMETRIZE { move = MOVE_MISTY_TERRAIN; }
    PARAMETRIZE { move = MOVE_MUD_SPORT; }
    PARAMETRIZE { move = MOVE_PSYCHIC_TERRAIN; }
    PARAMETRIZE { move = MOVE_RAIN_DANCE; }
    PARAMETRIZE { move = MOVE_REFLECT; }
    PARAMETRIZE { move = MOVE_SAFEGUARD; }
    PARAMETRIZE { move = MOVE_SANDSTORM; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PARAMETRIZE { move = MOVE_SPOTLIGHT; }
    PARAMETRIZE { move = MOVE_STEALTH_ROCK; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; }
    PARAMETRIZE { move = MOVE_TAILWIND; }
    PARAMETRIZE { move = MOVE_TEETER_DANCE; }
    PARAMETRIZE { move = MOVE_TRICK_ROOM; }
    PARAMETRIZE { move = MOVE_WATER_SPORT; }
    PARAMETRIZE { move = MOVE_COURT_CHANGE; }
    PARAMETRIZE { move = MOVE_PERISH_SONG; }
    PARAMETRIZE { move = MOVE_STICKY_WEB; }
    PARAMETRIZE { move = MOVE_TEATIME; }
    PARAMETRIZE { move = MOVE_WONDER_ROOM; }
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, chance);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_TACKLE); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_TACKLE); }
    } WHEN {
        TURN {
            if (chance == 100) {
                EXPECT_MOVE(opponentLeft, move);
                EXPECT_MOVE(opponentRight, MOVE_TACKLE);
            } else {
                EXPECT_MOVE(opponentLeft, MOVE_TACKLE);
                EXPECT_MOVE(opponentRight, move);
            }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Heal Bell and Jungle Healing skip curing a partner that benefits from burn")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HEAL_BELL; }
    PARAMETRIZE { move = MOVE_JUNGLE_HEALING; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BELL) == EFFECT_HEAL_BELL);
        ASSUME(GetMoveEffect(MOVE_JUNGLE_HEALING) == EFFECT_JUNGLE_HEALING);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_MEMENTO); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_MEMENTO); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_SCRATCH); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_GUTS); Moves(MOVE_TACKLE); Status1(STATUS1_BURN); MaxHP(200); HP(200); Speed(10); }
    } WHEN {
        TURN {
            NOT_EXPECT_MOVE(opponentLeft, move);
            EXPECT_MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_TACKLE, target: playerLeft);
            MOVE(playerLeft, MOVE_MEMENTO);
            MOVE(playerRight, MOVE_MEMENTO);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not choose Earthquake if it damages the partner without a positive effect")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_CHARIZARD; }
    PARAMETRIZE { species = SPECIES_CHARMANDER; }
    PARAMETRIZE { species = SPECIES_CHIKORITA; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PHANPY) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(species) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        if (species == SPECIES_CHARIZARD)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not choose Earthquake if its ally has Levitate but both foes are immune to Ground")
{
    GIVEN {
        ASSUME(IsSpeciesOfType(SPECIES_CHARIZARD, TYPE_FLYING));
        ASSUME(IsSpeciesOfType(SPECIES_ZAPDOS, TYPE_FLYING));
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_CHARIZARD);
        PLAYER(SPECIES_ZAPDOS);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_KOFFING) { Ability(ABILITY_LEVITATE); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI only rewards spread moves when an ally's absorbing ability provides a useful benefit")
{
    enum Ability ability;
    enum Move move, partnerMove;
    u32 partnerHP;
    bool32 shouldReward;

    PARAMETRIZE { ability = ABILITY_LEVITATE;      move = MOVE_EARTHQUAKE; partnerMove = MOVE_CELEBRATE; partnerHP = 100; shouldReward = FALSE; }
    PARAMETRIZE { ability = ABILITY_EARTH_EATER;   move = MOVE_EARTHQUAKE; partnerMove = MOVE_CELEBRATE; partnerHP = 100; shouldReward = FALSE; }
    PARAMETRIZE { ability = ABILITY_EARTH_EATER;   move = MOVE_EARTHQUAKE; partnerMove = MOVE_CELEBRATE; partnerHP = 20;  shouldReward = TRUE; }
    PARAMETRIZE { ability = ABILITY_VOLT_ABSORB;   move = MOVE_DISCHARGE;  partnerMove = MOVE_CELEBRATE; partnerHP = 100; shouldReward = FALSE; }
    PARAMETRIZE { ability = ABILITY_VOLT_ABSORB;   move = MOVE_DISCHARGE;  partnerMove = MOVE_CELEBRATE; partnerHP = 20;  shouldReward = TRUE; }
    PARAMETRIZE { ability = ABILITY_WATER_ABSORB;  move = MOVE_SURF;       partnerMove = MOVE_CELEBRATE; partnerHP = 100; shouldReward = FALSE; }
    PARAMETRIZE { ability = ABILITY_WATER_ABSORB;  move = MOVE_SURF;       partnerMove = MOVE_CELEBRATE; partnerHP = 20;  shouldReward = TRUE; }
    PARAMETRIZE { ability = ABILITY_FLASH_FIRE;    move = MOVE_LAVA_PLUME; partnerMove = MOVE_CELEBRATE; partnerHP = 100; shouldReward = FALSE; }
    PARAMETRIZE { ability = ABILITY_FLASH_FIRE;    move = MOVE_LAVA_PLUME; partnerMove = MOVE_EMBER;     partnerHP = 100; shouldReward = TRUE; }
    PARAMETRIZE { ability = ABILITY_LIGHTNING_ROD; move = MOVE_DISCHARGE;  partnerMove = MOVE_CELEBRATE; partnerHP = 100; shouldReward = FALSE; }
    PARAMETRIZE { ability = ABILITY_LIGHTNING_ROD; move = MOVE_DISCHARGE;  partnerMove = MOVE_EMBER;     partnerHP = 100; shouldReward = TRUE; }
    PARAMETRIZE { ability = ABILITY_STORM_DRAIN;   move = MOVE_SURF;       partnerMove = MOVE_CELEBRATE; partnerHP = 100; shouldReward = FALSE; }
    PARAMETRIZE { ability = ABILITY_STORM_DRAIN;   move = MOVE_SURF;       partnerMove = MOVE_EMBER;     partnerHP = 100; shouldReward = TRUE; }

    GIVEN {
        ASSUME(GetMoveTarget(move) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_DRAGON_RAGE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(90); Moves(move, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); HP(partnerHP); MaxHP(100); Speed(100); Moves(partnerMove); }
    } WHEN {
        if (shouldReward)
            TURN { SCORE_GT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: opponentRight); }
        else
            TURN { SCORE_LT_VAL(opponentLeft, move, AI_SCORE_DEFAULT, target: opponentRight); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI recognizes its ally's Telepathy")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PHANPY) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_ELGYEM) { Level(1); Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will choose Bulldoze if it triggers its ally's ability but will not KO the ally needlessly")
{
    enum Species species;
    enum Ability ability;
    u32 currentHP;

    PARAMETRIZE { species = SPECIES_KINGAMBIT; ability = ABILITY_DEFIANT;  currentHP = 400; }
    PARAMETRIZE { species = SPECIES_SHUCKLE;   ability = ABILITY_CONTRARY; currentHP = 400; }
    PARAMETRIZE { species = SPECIES_PAWNIARD;  ability = ABILITY_PRESSURE; currentHP = 1; }
    PARAMETRIZE { species = SPECIES_PAWNIARD;  ability = ABILITY_DEFIANT;  currentHP = 1; }
    PARAMETRIZE { species = SPECIES_SHUCKLE;   ability = ABILITY_CONTRARY; currentHP = 1; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_BULLDOZE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_BULLDOZE) == TYPE_GROUND);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_BULLDOZE, speed: -1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PHANPY) { Moves(MOVE_BULLDOZE, MOVE_HIGH_HORSEPOWER); }
        OPPONENT(species) { Moves(MOVE_CELEBRATE, MOVE_POUND); HP(currentHP); Ability(ability); }
    } WHEN {
        if (currentHP != 1)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_BULLDOZE); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_HIGH_HORSEPOWER); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Spicy Extract if its ally holds Clear Amulet and has a physical move")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SPICY_EXTRACT, attack: +2, defense: -2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_CLEAR_AMULET); Moves(move); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_SCRATCH, MOVE_SPICY_EXTRACT); }
    } WHEN {
        TURN {
            if (move == MOVE_SCRATCH)
                EXPECT_MOVE(opponentRight, MOVE_SPICY_EXTRACT, target: opponentLeft);
            else
                EXPECT_MOVE(opponentRight, MOVE_SCRATCH);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI does not use Spicy Extract if its ally would not benefit")
{
    u32 species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GHOLDENGO; ability = ABILITY_GOOD_AS_GOLD; }
    PARAMETRIZE { species = SPECIES_SNIVY;     ability = ABILITY_CONTRARY; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SPICY_EXTRACT, attack: +2, defense: -2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_SCRATCH); }
        OPPONENT(species) { Speed(20); Ability(ability); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_SCRATCH, MOVE_SPICY_EXTRACT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentRight, MOVE_SCRATCH); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will choose Beat Up on an ally with Justified if it will benefit the ally")
{
    enum Ability defAbility, atkAbility, currentHP;

    PARAMETRIZE { defAbility = ABILITY_FLASH_FIRE; atkAbility = ABILITY_SCRAPPY;        currentHP = 400; }
    PARAMETRIZE { defAbility = ABILITY_JUSTIFIED;  atkAbility = ABILITY_SCRAPPY;        currentHP = 400; }
    PARAMETRIZE { defAbility = ABILITY_JUSTIFIED;  atkAbility = ABILITY_MOLD_BREAKER;   currentHP = 400; }
    PARAMETRIZE { defAbility = ABILITY_JUSTIFIED;  atkAbility = ABILITY_SCRAPPY;        currentHP = 1; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BEAT_UP) == EFFECT_BEAT_UP);
        ASSUME(GetMoveType(MOVE_BEAT_UP) == TYPE_DARK);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CLEFABLE);
        OPPONENT(SPECIES_PANGORO)   { Ability(atkAbility); Moves(MOVE_BEAT_UP); }
        OPPONENT(SPECIES_GROWLITHE) { Moves(MOVE_CELEBRATE, MOVE_TACKLE); HP(currentHP); Ability(defAbility); }
    } WHEN {
        if (!(currentHP == 1) && (defAbility == ABILITY_JUSTIFIED) && (atkAbility != ABILITY_MOLD_BREAKER))
            TURN { EXPECT_MOVE(opponentLeft, MOVE_BEAT_UP, target: opponentRight); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_BEAT_UP, target: playerLeft); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not use Protect if its left ally is about to trigger Justified with Beat Up")
{
    ASSUME(GetMoveEffect(MOVE_BEAT_UP) == EFFECT_BEAT_UP);
    ASSUME(GetMoveType(MOVE_BEAT_UP) == TYPE_DARK);

    KNOWN_FAILING; // partner is protecting
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_CLEFABLE) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_PANGORO)   { Ability(ABILITY_SCRAPPY); Moves(MOVE_BEAT_UP); }
        OPPONENT(SPECIES_GROWLITHE) { Ability(ABILITY_JUSTIFIED); Moves(MOVE_PROTECT, MOVE_TACKLE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
            MOVE(playerRight, MOVE_SCRATCH, target: opponentRight);
            EXPECT_MOVE(opponentLeft, MOVE_BEAT_UP, target: opponentRight);
            NOT_EXPECT_MOVE(opponentRight, MOVE_PROTECT);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not use Protect if its right ally is about to trigger Justified with Beat Up")
{
    ASSUME(GetMoveEffect(MOVE_BEAT_UP) == EFFECT_BEAT_UP);
    ASSUME(GetMoveType(MOVE_BEAT_UP) == TYPE_DARK);

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        TIE_BREAK_SCORE(RNG_AI_SCORE_TIE_DOUBLES_MOVE, SCORE_TIE_LO, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_CLEFABLE) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GROWLITHE) { Ability(ABILITY_JUSTIFIED); Moves(MOVE_TACKLE, MOVE_PROTECT); }
        OPPONENT(SPECIES_PANGORO)   { Ability(ABILITY_SCRAPPY); Moves(MOVE_BEAT_UP); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
            MOVE(playerRight, MOVE_SCRATCH, target: opponentRight);
            EXPECT_MOVE(opponentRight, MOVE_BEAT_UP, target: opponentLeft);
            NOT_EXPECT_MOVE(opponentLeft, MOVE_PROTECT);
            SCORE_LT_VAL(opponentLeft, MOVE_PROTECT, AI_SCORE_DEFAULT, target: playerLeft);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI does not penalize Protect if its ally switches instead of triggering Weakness Policy")
{
    ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
    ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
    ASSUME(GetItemHoldEffect(ITEM_WEAKNESS_POLICY) == HOLD_EFFECT_WEAKNESS_POLICY);

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        WITH_CONFIG(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_CHARIZARD) { Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_CHARIZARD) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GIBLE)   { Level(1); Attack(1); Moves(MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_PIKACHU) { Level(100); HP(400); Defense(400); Item(ITEM_WEAKNESS_POLICY); Moves(MOVE_PROTECT, MOVE_TACKLE); }
        OPPONENT(SPECIES_RAMPARDOS) { Level(100); Moves(MOVE_ROCK_SLIDE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft);
            MOVE(playerRight, MOVE_SCRATCH, target: opponentRight);
            EXPECT_SWITCH(opponentLeft, 2);
            SCORE_GT_VAL(opponentRight, MOVE_PROTECT, AI_SCORE_DEFAULT + WORST_EFFECT, target: playerRight);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will choose Beat Up on an ally with Rage Fist if it will benefit the ally")
{
    u32 currentHP, movePP;
    enum Move move;
    bool32 shouldBeatUp;

    PARAMETRIZE { move = MOVE_DRAIN_PUNCH; currentHP = 400; movePP = 10; shouldBeatUp = FALSE; }
    PARAMETRIZE { move = MOVE_RAGE_FIST;   currentHP = 400; movePP = 10; shouldBeatUp = TRUE; }
    PARAMETRIZE { move = MOVE_RAGE_FIST;   currentHP = 400; movePP = 0;  shouldBeatUp = FALSE; }
    PARAMETRIZE { move = MOVE_RAGE_FIST;   currentHP = 1;   movePP = 10; shouldBeatUp = FALSE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BEAT_UP) == EFFECT_BEAT_UP);
        ASSUME(GetMoveEffect(MOVE_RAGE_FIST) == EFFECT_RAGE_FIST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WHIMSICOTT) { Moves(MOVE_BEAT_UP); }
        OPPONENT(SPECIES_ANNIHILAPE) { MovesWithPP({move, movePP}, {MOVE_CELEBRATE, 10}); HP(currentHP); }
    } WHEN {
        if (shouldBeatUp)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_BEAT_UP, target: opponentRight); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_BEAT_UP, target: playerLeft); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will only Beat Up for Rage Fist if it can hit at least one opponent")
{
    enum Species species;
    bool32 shouldBeatUp;

    PARAMETRIZE { species = SPECIES_MEOWTH;    shouldBeatUp = FALSE; }
    PARAMETRIZE { species = SPECIES_WOBBUFFET; shouldBeatUp = TRUE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BEAT_UP) == EFFECT_BEAT_UP);
        ASSUME(GetMoveEffect(MOVE_RAGE_FIST) == EFFECT_RAGE_FIST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_MEOWTH);
        PLAYER(species);
        OPPONENT(SPECIES_WHIMSICOTT) { Moves(MOVE_BEAT_UP); }
        OPPONENT(SPECIES_ANNIHILAPE) { MovesWithPP({MOVE_RAGE_FIST, 10}, {MOVE_CELEBRATE, 10}); HP(400); }
    } WHEN {
        if (shouldBeatUp)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_BEAT_UP, target: opponentRight); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_BEAT_UP, target: playerLeft); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will choose Earthquake if partner is not alive")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_PIKACHU) { HP(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight); }
        TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will choose Earthquake if it kills one opposing mon and does not kill the partner needlessly")
{
    u32 currentHP;
    PARAMETRIZE { currentHP = 1; }
    PARAMETRIZE { currentHP = 200; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_PARAS) { Moves(MOVE_CELEBRATE); HP(currentHP); }
    } WHEN {
        if (currentHP == 1)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will choose Earthquake if it kills one opposing mon and a partner it believes is about to die")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_PARAS) { Moves(MOVE_CELEBRATE); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH); }
        TURN { MOVE(playerRight, MOVE_SCRATCH); }
        TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will choose Earthquake if it kills both opposing mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_PARAS) { Moves(MOVE_CELEBRATE); HP(1); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will trigger its ally's Weakness Policy")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_INCINEROAR; }
    PARAMETRIZE { species = SPECIES_CLEFFA; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_WEAKNESS_POLICY].holdEffect == HOLD_EFFECT_WEAKNESS_POLICY);
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EARTHQUAKE, MOVE_STOMPING_TANTRUM); }
        OPPONENT(species) { Moves(MOVE_CELEBRATE); Item(ITEM_WEAKNESS_POLICY); }
    } WHEN {
        if (species == SPECIES_INCINEROAR)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will trigger its ally's Spicy Spray if burn benefits it")
{
    enum Ability atkAbility;
    bool32 shouldTrigger;

    PARAMETRIZE { atkAbility = ABILITY_GUTS;  shouldTrigger = TRUE;  }
    PARAMETRIZE { atkAbility = ABILITY_SWARM; shouldTrigger = FALSE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_HERACROSS) { Ability(atkAbility); Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_SCOVILLAIN_MEGA) { Ability(ABILITY_SPICY_SPRAY); Moves(MOVE_CELEBRATE); MaxHP(400); HP(400); }
    } WHEN {
        if (shouldTrigger)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will trigger its ally's Spicy Spray if the ally is about to faint")
{
    enum Ability atkAbility;
    bool32 shouldTrigger;

    PARAMETRIZE { atkAbility = ABILITY_GUTS;  shouldTrigger = TRUE;  }
    PARAMETRIZE { atkAbility = ABILITY_SWARM; shouldTrigger = FALSE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_HERACROSS) { Ability(atkAbility); Moves(MOVE_EARTHQUAKE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_SCOVILLAIN_MEGA) { Ability(ABILITY_SPICY_SPRAY); Moves(MOVE_CELEBRATE); MaxHP(400); HP(1); }
    } WHEN {
        if (shouldTrigger)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will only explode and kill everything on the field with Risky or Will Suicide (doubles)")
{
    u32 aiFlags;

    PARAMETRIZE { aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }
    PARAMETRIZE { aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_RISKY; }
    PARAMETRIZE { aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_WILL_SUICIDE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        AI_FLAGS(aiFlags);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_ELECTRODE) { Moves(MOVE_EXPLOSION, MOVE_ELECTRO_BALL); }
        OPPONENT(SPECIES_ELECTRODE) { Moves(MOVE_CELEBRATE); HP(1); }
    } WHEN {
        if (aiFlags == (AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT))
            TURN { EXPECT_MOVE(opponentLeft, MOVE_ELECTRO_BALL); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_EXPLOSION); }
    }
}

AI_DOUBLE_BATTLE_TEST("Battler 3 has Battler 1 AI flags set correctly (doubles)")
{
    u32 aiFlags;
    struct BattlePokemon *battler = NULL;

    PARAMETRIZE { aiFlags = 0; battler = opponentLeft; }
    PARAMETRIZE { aiFlags = 0; battler = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentRight; }
    PARAMETRIZE { aiFlags = AI_FLAG_RISKY; battler = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentLeft; }
    PARAMETRIZE { aiFlags = AI_FLAG_WILL_SUICIDE; battler = opponentRight; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        BATTLER_AI_FLAGS(battler, aiFlags);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_VOLTORB) { Moves(MOVE_EXPLOSION, MOVE_ELECTRO_BALL); HP(1); }
        OPPONENT(SPECIES_ELECTRODE) { Moves(MOVE_EXPLOSION, MOVE_ELECTRO_BALL); HP(1); }
    } WHEN {
        if (aiFlags == 0 || battler == opponentRight)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_ELECTRO_BALL, target: playerLeft); EXPECT_MOVE(opponentRight, MOVE_ELECTRO_BALL, target: playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_EXPLOSION, target: playerLeft); EXPECT_MOVE(opponentRight, MOVE_EXPLOSION); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI sees corresponding absorbing abilities on partners")
{
    enum Ability ability;
    enum Move move;
    enum Species species;

    PARAMETRIZE { species = SPECIES_PSYDUCK;    ability = ABILITY_CLOUD_NINE;         move = MOVE_DISCHARGE; }
    PARAMETRIZE { species = SPECIES_PIKACHU;    ability = ABILITY_LIGHTNING_ROD;      move = MOVE_DISCHARGE; }
    PARAMETRIZE { species = SPECIES_LANTURN;    ability = ABILITY_VOLT_ABSORB;        move = MOVE_DISCHARGE; }
    PARAMETRIZE { species = SPECIES_EMOLGA;     ability = ABILITY_MOTOR_DRIVE;        move = MOVE_DISCHARGE; }
    PARAMETRIZE { species = SPECIES_SEAKING;    ability = ABILITY_LIGHTNING_ROD;      move = MOVE_DISCHARGE; }
    PARAMETRIZE { species = SPECIES_GROWLITHE;  ability = ABILITY_FLASH_FIRE;         move = MOVE_LAVA_PLUME; }
    PARAMETRIZE { species = SPECIES_DACHSBUN;   ability = ABILITY_WELL_BAKED_BODY;    move = MOVE_LAVA_PLUME; }
    PARAMETRIZE { species = SPECIES_QUAGSIRE;   ability = ABILITY_WATER_ABSORB;       move = MOVE_SURF; }
    PARAMETRIZE { species = SPECIES_SHELLOS;    ability = ABILITY_STORM_DRAIN;        move = MOVE_SURF; }
    PARAMETRIZE { species = SPECIES_UNOWN;      ability = ABILITY_LEVITATE;           move = MOVE_EARTHQUAKE; }
    PARAMETRIZE { species = SPECIES_ORTHWORM;   ability = ABILITY_EARTH_EATER;        move = MOVE_EARTHQUAKE; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        ASSUME(GetMoveTarget(MOVE_LAVA_PLUME) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_LAVA_PLUME) == TYPE_FIRE);
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_SLAKING) { Moves(move, MOVE_CONSTRICT); }
        OPPONENT(species) { HP(1); Ability(ability); Moves(MOVE_POUND, MOVE_EMBER, MOVE_ROUND); }
    } WHEN {
        if (ability != ABILITY_CLOUD_NINE)
            TURN { EXPECT_MOVE(opponentLeft, move); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_CONSTRICT); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI sees random rolls correctly")
{
    PASSES_RANDOMLY(3, 15, RNG_AI_DMG_ROLL_RANDOM); // Slaking KOs with 3 rolls
    GIVEN {
        WITH_CONFIG(AI_ROLL_ATTACKING, AI_ROLL_RANDOM);
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_SLAKING) { Moves(MOVE_DISCHARGE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_PIKACHU) { HP(1); Ability(ABILITY_LIGHTNING_ROD); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_SCRATCH); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI treats an ally's redirection ability appropriately (gen 4)")
{
    enum Ability ability;
    enum Move move;
    enum Species species;

    PARAMETRIZE { species = SPECIES_SEAKING;    ability = ABILITY_LIGHTNING_ROD;    move = MOVE_DISCHARGE; }
    PARAMETRIZE { species = SPECIES_SHELLOS;    ability = ABILITY_STORM_DRAIN;      move = MOVE_SURF; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_HP_AWARE);
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_HEADBUTT); }
        OPPONENT(species) { HP(1); Ability(ability); Moves(MOVE_ROUND); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_HEADBUTT); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI treats an ally's redirection ability appropriately (gen 5+)")
{
    enum Move move, expectedMove;
    enum Species species;
    u32 config;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_SEAKING; ability = ABILITY_LIGHTNING_ROD; move = MOVE_DISCHARGE; config = GEN_4; expectedMove = MOVE_HEADBUTT; }
    PARAMETRIZE { species = SPECIES_SHELLOS; ability = ABILITY_STORM_DRAIN;   move = MOVE_SURF;      config = GEN_4; expectedMove = MOVE_HEADBUTT; }
    PARAMETRIZE { species = SPECIES_SEAKING; ability = ABILITY_LIGHTNING_ROD; move = MOVE_DISCHARGE; config = GEN_5; expectedMove = MOVE_DISCHARGE; }
    PARAMETRIZE { species = SPECIES_SHELLOS; ability = ABILITY_STORM_DRAIN;   move = MOVE_SURF;      config = GEN_5; expectedMove = MOVE_SURF; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_HP_AWARE);
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, config);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(move, MOVE_HEADBUTT); }
        OPPONENT(species) { HP(1); Ability(ability); Moves(MOVE_ROUND); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, expectedMove); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI recognizes Volt Absorb received from Trace")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_MAGNETON);
        PLAYER(SPECIES_GARDEVOIR) { Ability(ABILITY_TRACE); }
        OPPONENT(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); Moves(MOVE_THUNDER_WAVE, MOVE_THUNDERSHOCK, MOVE_WATER_GUN); }
        OPPONENT(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); Moves(MOVE_THUNDER_WAVE, MOVE_THUNDERSHOCK, MOVE_WATER_GUN); }
    } WHEN {
        TURN { NOT_EXPECT_MOVES(opponentLeft, MOVE_THUNDERSHOCK, MOVE_THUNDER_WAVE); NOT_EXPECT_MOVE(opponentRight, MOVE_THUNDER_WAVE); }
    } THEN {
        EXPECT(gAiLogicData->abilities[B_POSITION_PLAYER_RIGHT] == ABILITY_VOLT_ABSORB);
    }
}

AI_DOUBLE_BATTLE_TEST("AI prioritizes Skill Swapping Contrary to allied mons that would benefit from it")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_OVERHEAT, self: TRUE, spAtk: -2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_SPINDA) { Ability(ABILITY_CONTRARY); Speed(5); Moves(MOVE_SKILL_SWAP, MOVE_ENCORE, MOVE_FAKE_TEARS, MOVE_SWAGGER); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Speed(4); Moves (MOVE_OVERHEAT); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_SKILL_SWAP, target:opponentRight); EXPECT_MOVE(opponentRight, MOVE_OVERHEAT); }
    }
}

// Sandstorm is omitted on purpose.
// Tornadus is currently not willing to set up Sandstorm for its ally, but the actual purpose of this test is to demonstrate that Tornadus or Whimsicott will perform standard VGC openers.
// Rain Dance, Sunny Day, and Snowscape are the actually important ones; setting up a good Sandstorm test + functionality is less important and will be done in later PRs.
AI_DOUBLE_BATTLE_TEST("AI sets up weather for its ally")
{
    u32 goodWeather, badWeather, weatherTrigger;
    u64 aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT;

    PARAMETRIZE { goodWeather = MOVE_SUNNY_DAY; badWeather = MOVE_RAIN_DANCE; weatherTrigger = MOVE_SOLAR_BEAM; }
    PARAMETRIZE { goodWeather = MOVE_RAIN_DANCE; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_THUNDER; }
    PARAMETRIZE { goodWeather = MOVE_HAIL; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_BLIZZARD; }
    PARAMETRIZE { goodWeather = MOVE_SNOWSCAPE; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_BLIZZARD; }
    PARAMETRIZE { goodWeather = MOVE_SANDSTORM; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_SHORE_UP; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodWeather = MOVE_SUNNY_DAY; badWeather = MOVE_RAIN_DANCE; weatherTrigger = MOVE_SOLAR_BEAM; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodWeather = MOVE_RAIN_DANCE; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_THUNDER; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodWeather = MOVE_HAIL; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_BLIZZARD; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodWeather = MOVE_SNOWSCAPE; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_BLIZZARD; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodWeather = MOVE_SANDSTORM; badWeather = MOVE_SUNNY_DAY; weatherTrigger = MOVE_SHORE_UP; }

    GIVEN {
        AI_FLAGS(aiFlags);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TORNADUS) { Item(ITEM_SAFETY_GOGGLES); Ability(ABILITY_PRANKSTER); Moves(goodWeather, badWeather, MOVE_RETURN, MOVE_TAUNT); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_SAFETY_GOGGLES); Moves(weatherTrigger, MOVE_EARTH_POWER); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, goodWeather); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI sets up terrain for its ally")
{
    u32 goodTerrain, badTerrain, terrainTrigger;
    u64 aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT;

    PARAMETRIZE { goodTerrain = MOVE_ELECTRIC_TERRAIN; badTerrain = MOVE_PSYCHIC_TERRAIN; terrainTrigger = MOVE_RISING_VOLTAGE; }
    PARAMETRIZE { goodTerrain = MOVE_GRASSY_TERRAIN; badTerrain = MOVE_PSYCHIC_TERRAIN; terrainTrigger = MOVE_GRASSY_GLIDE; }
    PARAMETRIZE { goodTerrain = MOVE_MISTY_TERRAIN; badTerrain = MOVE_PSYCHIC_TERRAIN; terrainTrigger = MOVE_MISTY_EXPLOSION; }
    PARAMETRIZE { goodTerrain = MOVE_PSYCHIC_TERRAIN; badTerrain = MOVE_ELECTRIC_TERRAIN; terrainTrigger = MOVE_EXPANDING_FORCE; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodTerrain = MOVE_ELECTRIC_TERRAIN; badTerrain = MOVE_PSYCHIC_TERRAIN; terrainTrigger = MOVE_RISING_VOLTAGE; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodTerrain = MOVE_GRASSY_TERRAIN; badTerrain = MOVE_PSYCHIC_TERRAIN; terrainTrigger = MOVE_GRASSY_GLIDE; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodTerrain = MOVE_MISTY_TERRAIN; badTerrain = MOVE_PSYCHIC_TERRAIN; terrainTrigger = MOVE_MISTY_EXPLOSION; }
    PARAMETRIZE { aiFlags |= AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_PP_STALL_PREVENTION;
                  goodTerrain = MOVE_PSYCHIC_TERRAIN; badTerrain = MOVE_ELECTRIC_TERRAIN; terrainTrigger = MOVE_EXPANDING_FORCE; }

    GIVEN {
        AI_FLAGS(aiFlags);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(goodTerrain, badTerrain, MOVE_RETURN, MOVE_TAUNT); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(terrainTrigger, MOVE_EARTH_POWER); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, goodTerrain); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses After You to set up Trick Room")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_TRICK_ROOM; }
    PARAMETRIZE { move = MOVE_MOONBLAST; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AFTER_YOU) == EFFECT_AFTER_YOU);
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(IsHealingMove(MOVE_DRAINING_KISS)); // Doesn't have the Healing Move flag in Gen 5
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_TRIAGE); Speed(5); Moves(MOVE_AFTER_YOU, MOVE_DRAINING_KISS); }
        OPPONENT(SPECIES_CLEFAIRY) { Speed(3); Moves(move, MOVE_PSYCHIC); }
    } WHEN {
        if (move == MOVE_TRICK_ROOM)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_AFTER_YOU, target:opponentRight); EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_AFTER_YOU); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Trick Room intelligently")
{
    enum Move move;
    enum Ability ability;
    u32 speed;

    PARAMETRIZE { move = MOVE_DRAINING_KISS; ability = ABILITY_SYNCHRONIZE; speed = 4; }
    // PARAMETRIZE { move = MOVE_DAZZLING_GLEAM; ability = ABILITY_SYNCHRONIZE; speed = 4; }
    // PARAMETRIZE { move = MOVE_DRAINING_KISS; ability = ABILITY_PSYCHIC_SURGE; speed = 4; }
    PARAMETRIZE { move = MOVE_DRAINING_KISS; ability = ABILITY_SYNCHRONIZE; speed = 2; }
    PARAMETRIZE { move = MOVE_DAZZLING_GLEAM; ability = ABILITY_SYNCHRONIZE; speed = 2; }
    PARAMETRIZE { move = MOVE_DRAINING_KISS; ability = ABILITY_PSYCHIC_SURGE; speed = 2; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AFTER_YOU) == EFFECT_AFTER_YOU);
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(IsHealingMove(MOVE_DRAINING_KISS)); // Doesn't have the Healing Move flag in Gen 5
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(speed); }
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_TRIAGE); Speed(5); Moves(move); }
        OPPONENT(SPECIES_INDEEDEE) { Ability(ability); Speed(3); Moves(MOVE_TRICK_ROOM, MOVE_PSYCHIC); }
    } WHEN {
        if (move == MOVE_DRAINING_KISS && ability != ABILITY_PSYCHIC_SURGE && speed > 3)
            TURN { EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
        else
            TURN { NOT_EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Trick Room with both battlers on the turn it expires in line with the double Trick Room config")
{
    PASSES_RANDOMLY(DOUBLE_TRICK_ROOM_ON_LAST_TURN_CHANCE, 100, RNG_AI_REFRESH_TRICK_ROOM_ON_LAST_TURN);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_TRICK_ROOM, MOVE_PSYCHIC); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TRICK_ROOM, MOVE_PSYCHIC); Speed(1); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_TRICK_ROOM); NOT_EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
        TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_TRICK_ROOM); NOT_EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
        TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_TRICK_ROOM); NOT_EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
        TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_TRICK_ROOM); NOT_EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
        TURN { EXPECT_MOVE(opponentLeft, MOVE_TRICK_ROOM); EXPECT_MOVE(opponentRight, MOVE_TRICK_ROOM); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Helping Hand if it's about to die")
{
    u32 hp;

    PARAMETRIZE { hp = 1; }
    PARAMETRIZE { hp = 500; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HELPING_HAND) == EFFECT_HELPING_HAND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); Moves(MOVE_HELPING_HAND, MOVE_MUDDY_WATER); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MUDDY_WATER); }
    } WHEN {
        if (hp == 1)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_HELPING_HAND); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_HELPING_HAND); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Helping Hand if the ally does notably more damage")
{
    KNOWN_FAILING;  // Failure was masked by test runner issues
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HELPING_HAND) == EFFECT_HELPING_HAND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HELPING_HAND, MOVE_MUD_SLAP); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MUDDY_WATER); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_HELPING_HAND); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI does not use Helping Hand on Good as Gold ally")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HELPING_HAND) == EFFECT_HELPING_HAND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HELPING_HAND, MOVE_MUD_SLAP); }
        OPPONENT(SPECIES_GHOLDENGO) { Ability(ABILITY_GOOD_AS_GOLD); Moves(MOVE_MUDDY_WATER); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_MUD_SLAP); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Tailwind based on speed matchups")
{
    u32 speed1, speed2, speed3, speed4;
    bool32 expectTailwind;

    // All four comparisons qualify -> tailwindScore = 5
    PARAMETRIZE { speed1 = 20; speed2 = 20; speed3 = 20; speed4 = 20; expectTailwind = TRUE; }
    // Only the attacker flips one foe matchup -> tailwindScore = 2
    PARAMETRIZE { speed1 = 20; speed2 = 40; speed3 = 20; speed4 = 50; expectTailwind = TRUE; }
    // Only the partner flips one foe matchup -> tailwindScore = 2
    PARAMETRIZE { speed1 = 10; speed2 = 29; speed3 = 50; speed4 = 15; expectTailwind = TRUE; }
    // Too slow: even after doubling, still slower than both foes -> tailwindScore = 0.
    PARAMETRIZE { speed1 = 40; speed2 = 40; speed3 = 10; speed4 = 10; expectTailwind = FALSE; }
    // Already faster: Tailwind doesn't improve matchups -> tailwindScore = 0.
    PARAMETRIZE { speed1 =  5; speed2 =  5; speed3 = 10; speed4 = 10; expectTailwind = FALSE; }
    // Boundary: speed*2 == foe speed does not count -> tailwindScore = 0.
    PARAMETRIZE { speed1 = 20; speed2 = 20; speed3 = 10; speed4 = 30; expectTailwind = FALSE; }

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        ASSUME(GetMoveEffect(MOVE_TAILWIND) == EFFECT_TAILWIND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(speed1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(speed2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speed3); Moves(MOVE_TAILWIND, MOVE_HEADBUTT); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speed4); Moves(MOVE_TAILWIND, MOVE_HEADBUTT); }
    } WHEN {
        if (expectTailwind)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_TAILWIND); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_TAILWIND); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Tailwind to trigger Wind Rider (Doubles)")
{
    bool32 expectTailwind;
    enum Species tailwindSpecies, partnerSpecies;
    enum Ability tailwindAbility, partnerAbility;

    PARAMETRIZE { tailwindSpecies = SPECIES_BRAMBLEGHAST; tailwindAbility = ABILITY_WIND_RIDER;  partnerSpecies = SPECIES_BRAMBLEGHAST; partnerAbility = ABILITY_WIND_RIDER;  expectTailwind = TRUE; }
    PARAMETRIZE { tailwindSpecies = SPECIES_BRAMBLEGHAST; tailwindAbility = ABILITY_WIND_RIDER;  partnerSpecies = SPECIES_BRAMBLEGHAST; partnerAbility = ABILITY_INFILTRATOR; expectTailwind = TRUE; }
    PARAMETRIZE { tailwindSpecies = SPECIES_BRAMBLEGHAST; tailwindAbility = ABILITY_INFILTRATOR; partnerSpecies = SPECIES_BRAMBLEGHAST; partnerAbility = ABILITY_WIND_RIDER;  expectTailwind = TRUE; }
    PARAMETRIZE { tailwindSpecies = SPECIES_BRAMBLEGHAST; tailwindAbility = ABILITY_INFILTRATOR; partnerSpecies = SPECIES_BRAMBLEGHAST; partnerAbility = ABILITY_INFILTRATOR; expectTailwind = FALSE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAILWIND) == EFFECT_TAILWIND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(tailwindSpecies) { Ability(tailwindAbility); Speed(9); Moves(MOVE_TAILWIND, MOVE_HEADBUTT); }
        OPPONENT(partnerSpecies) { Ability(partnerAbility); Speed(9); Moves(MOVE_HEADBUTT); }
    } WHEN {
        if (expectTailwind)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_TAILWIND); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_TAILWIND); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Tailwind to trigger Wind Power (Doubles)")
{
    bool32 expectTailwind;
    enum Species tailwindSpecies, partnerSpecies;
    enum Ability tailwindAbility, partnerAbility;

    PARAMETRIZE { tailwindSpecies = SPECIES_KILOWATTREL; tailwindAbility = ABILITY_WIND_POWER;  partnerSpecies = SPECIES_KILOWATTREL; partnerAbility = ABILITY_WIND_POWER;  expectTailwind = TRUE; }
    PARAMETRIZE { tailwindSpecies = SPECIES_KILOWATTREL; tailwindAbility = ABILITY_WIND_POWER;  partnerSpecies = SPECIES_KILOWATTREL; partnerAbility = ABILITY_COMPETITIVE; expectTailwind = TRUE; }
    PARAMETRIZE { tailwindSpecies = SPECIES_KILOWATTREL; tailwindAbility = ABILITY_COMPETITIVE; partnerSpecies = SPECIES_KILOWATTREL; partnerAbility = ABILITY_WIND_POWER;  expectTailwind = TRUE; }
    PARAMETRIZE { tailwindSpecies = SPECIES_KILOWATTREL; tailwindAbility = ABILITY_COMPETITIVE; partnerSpecies = SPECIES_KILOWATTREL; partnerAbility = ABILITY_COMPETITIVE; expectTailwind = FALSE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAILWIND) == EFFECT_TAILWIND);
        ASSUME(GetMoveType(MOVE_THUNDERSHOCK) == TYPE_ELECTRIC);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(tailwindSpecies) { Ability(tailwindAbility); Speed(21); Moves(MOVE_TAILWIND, MOVE_THUNDERSHOCK); }
        OPPONENT(partnerSpecies) { Ability(partnerAbility); Speed(21); Moves(MOVE_THUNDERSHOCK); }
    } WHEN {
        if (expectTailwind)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_TAILWIND); }
        else
            TURN { NOT_EXPECT_MOVE(opponentLeft, MOVE_TAILWIND); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Guard Split to improve its stats")
{
    u32 player, opponent;

    PARAMETRIZE { player = SPECIES_SHUCKLE; opponent = SPECIES_PHEROMOSA; }
    PARAMETRIZE { player = SPECIES_PHEROMOSA; opponent = SPECIES_SHUCKLE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GUARD_SPLIT) == EFFECT_GUARD_SPLIT);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseDefense < gSpeciesInfo[SPECIES_WOBBUFFET].baseDefense);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseDefense < gSpeciesInfo[SPECIES_SHUCKLE].baseDefense);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseSpDefense < gSpeciesInfo[SPECIES_WOBBUFFET].baseSpDefense);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseSpDefense < gSpeciesInfo[SPECIES_SHUCKLE].baseSpDefense);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(player);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_GUARD_SPLIT, MOVE_NIGHT_SHADE); }
        OPPONENT(opponent);
    } WHEN {
        if (player == SPECIES_SHUCKLE)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_GUARD_SPLIT, target:playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_GUARD_SPLIT, target:opponentRight); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Power Split to improve its stats")
{
    u32 player, opponent;

    PARAMETRIZE { player = SPECIES_SHUCKLE; opponent = SPECIES_PHEROMOSA; }
    PARAMETRIZE { player = SPECIES_PHEROMOSA; opponent = SPECIES_SHUCKLE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POWER_SPLIT) == EFFECT_POWER_SPLIT);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseAttack > gSpeciesInfo[SPECIES_WOBBUFFET].baseAttack);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseAttack > gSpeciesInfo[SPECIES_SHUCKLE].baseAttack);
        ASSUME(gSpeciesInfo[SPECIES_PHEROMOSA].baseSpAttack > gSpeciesInfo[SPECIES_WOBBUFFET].baseSpAttack);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].baseSpAttack > gSpeciesInfo[SPECIES_SHUCKLE].baseSpAttack);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE);
        PLAYER(player);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_POWER_SPLIT, MOVE_TACKLE, MOVE_MAGICAL_LEAF); }
        OPPONENT(opponent) { Moves(MOVE_TACKLE, MOVE_MAGICAL_LEAF); }
    } WHEN {
        if (player == SPECIES_PHEROMOSA)
            TURN { EXPECT_MOVE(opponentLeft, MOVE_POWER_SPLIT, target:playerLeft); }
        else
            TURN { EXPECT_MOVE(opponentLeft, MOVE_POWER_SPLIT, target:opponentRight); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI prefers to Fake Out the opponent vulnerable to flinching.")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_DOUBLE_BATTLE | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZUBAT) { Ability(ABILITY_INNER_FOCUS); }
        PLAYER(SPECIES_BRAIXEN) { Ability(ABILITY_BLAZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_FAKE_OUT, MOVE_BRANCH_POKE, MOVE_ROCK_SMASH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_FAKE_OUT, target:playerRight); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Gear Up")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_KLINKLANG) { Ability(ABILITY_PLUS); Moves(MOVE_GEAR_UP, MOVE_WATER_GUN, MOVE_POUND); }
        OPPONENT(SPECIES_KLINKLANG) { Ability(ABILITY_PLUS); Moves(MOVE_GEAR_UP, MOVE_WATER_GUN, MOVE_POUND); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_GEAR_UP); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI uses Magnetic Flux")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_SWIFT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_POUND, MOVE_SWIFT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_KLINK) { Ability(ABILITY_PLUS); Moves(MOVE_MAGNETIC_FLUX, MOVE_POUND); }
        OPPONENT(SPECIES_KLINK) { Ability(ABILITY_PLUS); Moves(MOVE_MAGNETIC_FLUX, MOVE_POUND); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_MAGNETIC_FLUX); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI can choose a status move that boosts the attack by two (doubles)")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_STRENGTH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_HORN_ATTACK) == DAMAGE_CATEGORY_PHYSICAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(277); }
        PLAYER(SPECIES_WOBBUFFET) { HP(277); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KANGASKHAN) { Moves(MOVE_STRENGTH, MOVE_HORN_ATTACK, MOVE_SWORDS_DANCE); }
        OPPONENT(SPECIES_KANGASKHAN) { Moves(MOVE_STRENGTH, MOVE_HORN_ATTACK, MOVE_SWORDS_DANCE); }
    } WHEN {
        TURN {
            EXPECT_MOVES(opponentLeft, MOVE_STRENGTH, MOVE_SWORDS_DANCE);
            EXPECT_MOVES(opponentRight, MOVE_STRENGTH, MOVE_SWORDS_DANCE);
        }
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_STRENGTH);
            EXPECT_MOVE(opponentRight, MOVE_STRENGTH);
            SEND_OUT(playerLeft, 2);
            SEND_OUT(playerRight, 3);
        }
    }
}
