#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
}

SINGLE_BATTLE_TEST("Red Card switches the attacker with a random non-fainted replacement")
{
    PASSES_RANDOMLY(1, 2, RNG_FORCE_RANDOM_SWITCH);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_SQUIRTLE) { HP(0); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        MESSAGE("The opposing Bulbasaur was dragged out!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card does not let a switched-out attacker reuse its Z-Move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
        TURN { SWITCH(player, 0); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    }
}

DOUBLE_BATTLE_TEST("Red Card switches the target with a random non-battler, non-fainted replacement")
{
    PASSES_RANDOMLY(1, 2, RNG_FORCE_RANDOM_SWITCH);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_SQUIRTLE) { HP(0); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        MESSAGE("The opposing Bulbasaur was dragged out!");
    } THEN {
        EXPECT(playerLeft->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if holder faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if attacker faints from recoil")
{
    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_FLARE_BLITZ) > 0);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLARE_BLITZ); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLARE_BLITZ, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        }
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_RED_CARD);
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        }
    } THEN {
        EXPECT(player->item == ITEM_RED_CARD); // Not activated, so still has the item.
    }
}

SINGLE_BATTLE_TEST("Red Card activates after the last hit of a multi-hit move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DOUBLE_KICK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_KICK, opponent);
        HP_BAR(player);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if no replacements")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        }
    } THEN {
        EXPECT(player->item == ITEM_RED_CARD); // Not activated, so still has the item.
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if replacements fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(0); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        }
    } THEN {
        EXPECT(player->item == ITEM_RED_CARD); // Not activated, so still has the item.
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if knocked off")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_KNOCK_OFF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if stolen by a move")
{
    enum Item item;
    bool32 activate;
    PARAMETRIZE { item = ITEM_NONE; activate = FALSE; }
    PARAMETRIZE { item = ITEM_POTION; activate = TRUE; }
    ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THIEF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THIEF, opponent);
        if (activate) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
            }
        }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if stolen by Magician")
{
    enum Item item;
    bool32 activate;
    PARAMETRIZE { item = ITEM_NONE; activate = FALSE; }
    PARAMETRIZE { item = ITEM_POTION; activate = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_FENNEKIN) { Ability(ABILITY_MAGICIAN); Item(item); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        if (activate) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Fennekin!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Wobbuffet held up its Red Card against the opposing Fennekin!");
            }
        }
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Red Card activates for only the fastest target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_UNOWN) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROCK_SLIDE);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerRight);
        }
    } SCENE {
        // Fastest target's Red Card activates.
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        MESSAGE("The opposing Unown was dragged out!");

        // Slower target's Red Card still able to activate on other battler.
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
        MESSAGE("Wynaut held up its Red Card against the opposing Wynaut!");
        MESSAGE("The opposing Wobbuffet was dragged out!");
    } THEN {
        EXPECT(playerLeft->item == ITEM_NONE);
        EXPECT(playerRight->item == ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Red Card activates but fails if the attacker is rooted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_UNOWN);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_INGRAIN); }
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        MESSAGE("The opposing Wobbuffet is anchored in place with its roots!");
        NOT MESSAGE("The opposing Unown was dragged out!");

        // Red Card already consumed so cannot activate.
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wynaut!");
        }
    }
}

DOUBLE_BATTLE_TEST("Red Card activates but fails if the attacker has Suction Cups")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_OCTILLERY) { Ability(ABILITY_SUCTION_CUPS); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_UNOWN);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Octillery!");
        MESSAGE("The opposing Octillery is anchored in place with its suction cups!");
        NOT MESSAGE("The opposing Unown was dragged out!");

        // Red Card already consumed so cannot activate.
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wynaut!");
        }
    }
}

DOUBLE_BATTLE_TEST("Red Card activates but fails if the attacker has Guard Dog")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_OKIDOGI) { Ability(ABILITY_GUARD_DOG); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_UNOWN);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Okidogi!");
        NOT MESSAGE("The opposing Unown was dragged out!");

        // Red Card already consumed so cannot activate.
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wynaut!");
        }
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if switched by Dragon Tail")
{
    bool32 hasWynaut, activate;
    PARAMETRIZE { hasWynaut = TRUE; activate = FALSE; }
    PARAMETRIZE { hasWynaut = FALSE; activate = TRUE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        if (hasWynaut) PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, opponent);
        if (activate) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Red Card activates and overrides U-turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_U_TURN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if attacker's Sheer Force applied")
{
    enum Move move;
    bool32 activate;
    PARAMETRIZE { move = MOVE_SCRATCH; activate = TRUE; }
    PARAMETRIZE { move = MOVE_STOMP; activate = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (activate) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Tauros!");
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
                MESSAGE("Wobbuffet held up its Red Card against the opposing Tauros!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Red Card is consumed after dragged out replacement has its Speed lowered by Sticky Web")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        // 1st turn Sticky Web
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        // 2nd turn Red Card activation
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        MESSAGE("Wynaut was dragged out!");
        MESSAGE("Wynaut was caught in a sticky web!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        // 3rd turn, Red Card was consumed, it can't trigger again
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Wobbuffet held up its Red Card against Wynaut!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT(opponent->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card does not cause the dragged out mon to lose hp due to it's held Life Orb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        MESSAGE("Wynaut was dragged out!");
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Red Card does not activate if holder is switched in mid-turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_ENDURE); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Button!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet held up its Red Card against the opposing Wobbuffet!");
        }
    }
}

SINGLE_BATTLE_TEST("Red Card doesn't prevent Emergency Exit activation when triggered")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GOLISOPOD) { Item(ITEM_RED_CARD); Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(262); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Red Card activates and is consumed but fails if the attacker is Dynamaxed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_SCRATCH);
            MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        NOT MESSAGE("Wobbuffet is switched out with the Eject Button!");
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Red Card activates before Eject Pack")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_OVERHEAT, self: TRUE, spAtk: -2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_OVERHEAT); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet is switched out with the Eject Button!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

DOUBLE_BATTLE_TEST("Red Card will activate before Eject Button if holder is faster")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WYNAUT) { Speed(35); Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
    }
}
