#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_DESTINY_BOND) == EFFECT_DESTINY_BOND);
}

SINGLE_BATTLE_TEST("Destiny Bond faints the opposing mon if it fainted from the attack")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_DESTINY_BOND);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Wobbuffet took its attacker down with it!");
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Destiny Bond doesn't fail if used sequentially (Gen2-6)")
{
    GIVEN {
        WITH_CONFIG(B_DESTINY_BOND_FAIL, GEN_6);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        MESSAGE("2 sent out Zigzagoon!");
        NOT { MESSAGE("But it failed!"); }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
    }
}

SINGLE_BATTLE_TEST("Destiny Bond fails if used sequentially (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_DESTINY_BOND_FAIL, GEN_7);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        MESSAGE("2 sent out Zigzagoon!");
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player); }
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Destiny Bond does not fail if used repeatedly separated by other moves (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_DESTINY_BOND_FAIL, GEN_7);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
        TURN { MOVE(player, MOVE_GROWL); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        MESSAGE("2 sent out Zigzagoon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        NOT { MESSAGE("But it failed!"); }
    }
}

SINGLE_BATTLE_TEST("Destiny Bond does not fail if used after failing (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_DESTINY_BOND_FAIL, GEN_7);
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_DESTINY_BOND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
        MESSAGE("2 sent out Zigzagoon!");
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player); }
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, player);
    }
}

// can't be used at all in Raid, see "Documenting Dynamax"
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by Destiny Bond")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DESTINY_BOND); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Destiny Bond!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet fainted!");
        NONE_OF { HP_BAR(player); }
    }
}

TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Move");
TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Sleep");
TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Paralysis");
TO_DO_BATTLE_TEST("Destiny Bond's effect disappears if the user takes a new turn - Flinching");
TO_DO_BATTLE_TEST("Destiny Bond's effect doesn't trigger on indirect damage - Sandstorm");
TO_DO_BATTLE_TEST("Destiny Bond's effect doesn't trigger on indirect damage - Leech Seed");
TO_DO_BATTLE_TEST("Destiny Bond's effect doesn't trigger on indirect damage - Future Sight");
TO_DO_BATTLE_TEST("Destiny Bond's effect bypasses Focus Sash");
TO_DO_BATTLE_TEST("Destiny Bond's effect bypasses Sturdy");
TO_DO_BATTLE_TEST("Destiny Bond's effect bypasses Magic Guard");
TO_DO_BATTLE_TEST("Destiny Bond's effect can trigger on the next turn if the user hasn't moved yet");
TO_DO_BATTLE_TEST("Destiny Bond can be used multiple times in a row (Gen 2-6)");
TO_DO_BATTLE_TEST("Destiny Bond always fails if it was successfully used the previous turn (Gen 7+)");
TO_DO_BATTLE_TEST("Destiny Bond cannot be used in Raids");
