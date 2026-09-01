#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ENDURE) == EFFECT_ENDURE);
}

TO_DO_BATTLE_TEST("Endure allows the user to survive any attack with 1 HP left");

SINGLE_BATTLE_TEST("Endure does not prevent multiple hits and stat changes occur at the end of the turn")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_SCALE_SHOT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_SCALE_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCALE_SHOT, player);
        MESSAGE("The Pokémon was hit 5 times!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Wobbuffet's Speed rose!");
    }
}

DOUBLE_BATTLE_TEST("Endure is not transferred to a mon that is switched in due to Eject Button")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_SQUIRTLE) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_ENDURE);
            MOVE(playerLeft, MOVE_POUND, target: opponentRight);
            SEND_OUT(opponentRight, 2);
            MOVE(playerRight, MOVE_POUND, target: opponentRight);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        MESSAGE("The opposing Wynaut endured the hit!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        NOT MESSAGE("The opposing Squirtle endured the hit!");
    }
}

SINGLE_BATTLE_TEST("Endure only lasts for one turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_POUND); }
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        MESSAGE("The opposing Wobbuffet endured the hit!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        NOT MESSAGE("The opposing Wobbuffet endured the hit!");
    }
}

SINGLE_BATTLE_TEST("Endure takes precedence over False Swipe (Gen 5+)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_FALSE_SWIPE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, player);
        MESSAGE("The opposing Wobbuffet endured the hit!");
        // No message for False Swipe, but Endure message should still happen
    }
}

SINGLE_BATTLE_TEST("Endure takes precedence over Sturdy (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_STURDY, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARON) { HP(1); MaxHP(1); Ability(ABILITY_STURDY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        MESSAGE("The opposing Aron endured the hit!");
        NOT ABILITY_POPUP(opponent, ABILITY_STURDY);
    }
}

SINGLE_BATTLE_TEST("Endure takes precedence over Focus Sash/Focus Band")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(1); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDURE); MOVE(player, MOVE_POUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        MESSAGE("The opposing Wobbuffet endured the hit!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    }
}

TO_DO_BATTLE_TEST("Endure's success rate decreases for every consecutively used turn");
TO_DO_BATTLE_TEST("Endure uses the same counter as Protect");
TO_DO_BATTLE_TEST("Endure doesn't trigger effects that require damage to be done to the Pokémon (Gen 2-4)"); // Eg. Rough Skin
TO_DO_BATTLE_TEST("Endure triggers effects that require damage to be done to the Pokémon (Gen 5+)"); // Eg. Rough Skin
TO_DO_BATTLE_TEST("Endure doesn't protect against Future Sight (Gen 2-4)");
TO_DO_BATTLE_TEST("Endure protects against Future Sight (Gen 5+)");
