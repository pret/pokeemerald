#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Arena Trap prevents grounded adjacent opponents from switching out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId trapper = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        EXPECT_EQ(IsAbilityPreventingEscape(battler), trapper + 1);
    }
}

SINGLE_BATTLE_TEST("Arena Trap doesn't prevent switch outs if the Pokémon is switched in the same turn the opponent decided to switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); Speed(5); }
    } WHEN {
        TURN { SWITCH(player, 1); SWITCH(opponent, 1); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(opponent->species, SPECIES_DIGLETT);
    }
}

SINGLE_BATTLE_TEST("Arena Trap doesn't prevent switch outs via moves that switch out")
{
    enum Move move;
    enum BattleMoveEffects effect;
    PARAMETRIZE { move = MOVE_BATON_PASS; effect = EFFECT_BATON_PASS; }
    PARAMETRIZE { move = MOVE_U_TURN; effect = EFFECT_HIT_ESCAPE; }
    PARAMETRIZE { move = MOVE_VOLT_SWITCH; effect = EFFECT_HIT_ESCAPE; }
    PARAMETRIZE { move = MOVE_FLIP_TURN; effect = EFFECT_HIT_ESCAPE; }
    PARAMETRIZE { move = MOVE_PARTING_SHOT; effect = EFFECT_PARTING_SHOT; }
    PARAMETRIZE { move = MOVE_TELEPORT; effect = EFFECT_TELEPORT; }
    PARAMETRIZE { move = MOVE_SHED_TAIL; effect = EFFECT_SHED_TAIL; }
    PARAMETRIZE { move = MOVE_CHILLY_RECEPTION; effect = EFFECT_WEATHER_AND_SWITCH; }
    GIVEN {
        ASSUME(GetMoveEffect(move) == effect);
        ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        if (move == MOVE_VOLT_SWITCH)
            TURN { MOVE(player, MOVE_SOAK); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, move); SEND_OUT(player, 1); }
    } SCENE {
        if (move == MOVE_VOLT_SWITCH)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Arena Trap doesn't prevent switch outs via Shed Shell")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SHED_SHELL].holdEffect == HOLD_EFFECT_SHED_SHELL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SHED_SHELL); } // Grounded
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Wynaut");
    }
}

WILD_BATTLE_TEST("Arena Trap prevents switching but Run Away allows fleeing")
{
    GIVEN {
        PLAYER(SPECIES_RATTATA) { Ability(ABILITY_RUN_AWAY); }
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId trapper = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        EXPECT_EQ(IsAbilityPreventingEscape(battler), trapper + 1);
        EXPECT_EQ(IsRunningFromBattleImpossible(battler), BATTLE_RUN_SUCCESS);
    }
}

WILD_BATTLE_TEST("Arena Trap prevents switching but Smoke Ball allows fleeing")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SMOKE_BALL].holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SMOKE_BALL); }
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId trapper = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        EXPECT_EQ(IsAbilityPreventingEscape(battler), trapper + 1);
        EXPECT_EQ(IsRunningFromBattleImpossible(battler), BATTLE_RUN_SUCCESS);
    }
}

SINGLE_BATTLE_TEST("Arena Trap prevents switch outs from Ghost-type Pokémon (Gen3-5)")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SHUPPET, 0) == TYPE_GHOST);
        WITH_CONFIG(B_GHOSTS_ESCAPE, GEN_5);
        PLAYER(SPECIES_SHUPPET);
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        enum BattlerId trapper = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        EXPECT_EQ(IsAbilityPreventingEscape(battler), trapper + 1);
    }
}

SINGLE_BATTLE_TEST("Arena Trap doesn't prevent switch outs from Ghost-type Pokémon (Gen6+)")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SHUPPET, 0) == TYPE_GHOST);
        WITH_CONFIG(B_GHOSTS_ESCAPE, GEN_6);
        PLAYER(SPECIES_SHUPPET);
        OPPONENT(SPECIES_DIGLETT) { Ability(ABILITY_ARENA_TRAP); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        EXPECT_EQ(IsAbilityPreventingEscape(battler), 0);
    }
}
