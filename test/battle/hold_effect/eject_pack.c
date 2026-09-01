#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
}

SINGLE_BATTLE_TEST("Eject Pack does not cause the new Pokémon to lose HP due to it's held Life Orb")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OVERHEAT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        SEND_IN_MESSAGE("Wynaut");
        NOT HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Eject Pack does not activate if there are no Pokémon left to battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET) { HP(0); }
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        }
    }
}

SINGLE_BATTLE_TEST("Eject Pack is triggered by self-inflicting stat decreases")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET)  { Item(ITEM_EJECT_PACK); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_OVERHEAT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        SEND_IN_MESSAGE("Wynaut");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
}

SINGLE_BATTLE_TEST("Eject Pack switches the user out even if rooted by Ingrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_INGRAIN) == EFFECT_INGRAIN);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_INGRAIN); }
        TURN { MOVE(player, MOVE_OVERHEAT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INGRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Eject Pack will miss timing to switch out user if Emergency Exit was activated on target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(133); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_OVERHEAT); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        }
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    } THEN {
        EXPECT(player->species == SPECIES_WOBBUFFET);
        EXPECT(opponent->species == SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Eject Pack activates once intimidate mon switches in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponent, 1); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Pack!");
    }
}

SINGLE_BATTLE_TEST("Eject Pack will not activate if Parting Shot user can switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        }
    }
}

DOUBLE_BATTLE_TEST("Eject Pack will not trigger if the conditions are not met")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
        PLAYER(SPECIES_RALTS) { Ability(ABILITY_TRACE); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { SWITCH(opponentLeft, 2); SEND_OUT(playerLeft, 2); }
    } SCENE {

    }
}

SINGLE_BATTLE_TEST("Eject Pack will miss timing to switch out user if Eject Button was activated on target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_OVERHEAT); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OVERHEAT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Wobbuffet is switched out with the Eject Pack!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT(player->species == SPECIES_WOBBUFFET);
        EXPECT(opponent->species == SPECIES_WYNAUT);
    }
}

DOUBLE_BATTLE_TEST("Eject Pack: Only the fastest Eject Pack will activate after an ability stat drop")
{
    u32 speed;
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_EKANS; ability = ABILITY_INTIMIDATE; speed = 1; }
    PARAMETRIZE { species = SPECIES_EKANS; ability = ABILITY_INTIMIDATE; speed = 11; }

    PARAMETRIZE { species = SPECIES_DIPPLIN; ability = ABILITY_SUPERSWEET_SYRUP; speed = 1; }
    PARAMETRIZE { species = SPECIES_DIPPLIN; ability = ABILITY_SUPERSWEET_SYRUP; speed = 11; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT) { Speed(speed); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT)  { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET)  { Speed(5); }
        OPPONENT(species) { Speed(6); Ability(ability); }
    } WHEN {
        TURN {
            SWITCH(opponentLeft, 2);
            if (speed == 11)
                SEND_OUT(playerRight, 2);
            else
                SEND_OUT(playerLeft, 2);
        }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        if (speed == 11) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            }
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Eject Pack: Only the fastest Eject Pack will activate after a move stat drop")
{
    u32 speed;

    PARAMETRIZE { speed = 1; }
    PARAMETRIZE { speed = 11; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT) { Speed(speed); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT)  { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET)  { Speed(5); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_BUBBLE);
            if (speed == 11)
                SEND_OUT(playerRight, 2);
            else
                SEND_OUT(playerLeft, 2);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUBBLE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        if (speed == 11) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Eject Pack: Only the fastest Eject Pack will activate after intimidate (switch in after fainting)")
{
    u32 speed;

    PARAMETRIZE { speed = 1; }
    PARAMETRIZE { speed = 11; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT) { Speed(speed); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WYNAUT)  { HP(1); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET)  { Speed(5); }
        OPPONENT(SPECIES_EKANS) { Speed(6); Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_POUND, target: opponentLeft);
            SEND_OUT(opponentLeft, 2);
            if (speed == 11)
                SEND_OUT(playerRight, 2);
            else
                SEND_OUT(playerLeft, 2);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        if (speed == 11) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Eject Pack: Only the fastest Eject Pack will activate after intimidate (switch in after 2 mons fainted)")
{
    u32 speed;

    PARAMETRIZE { speed = 1; }
    PARAMETRIZE { speed = 11; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT) { Speed(speed); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WYNAUT)  { HP(1); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET)  { Speed(5); }
        OPPONENT(SPECIES_WYNAUT)  { Speed(4); }
        OPPONENT(SPECIES_EKANS) { Speed(6); Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_HYPER_VOICE);
            SEND_OUT(opponentLeft, 3);
            SEND_OUT(opponentRight, 2);
            if (speed == 11)
                SEND_OUT(playerRight, 2);
            else
                SEND_OUT(playerLeft, 2);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        if (speed == 11) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        }
    }
}

SINGLE_BATTLE_TEST("Eject Pack does not activate if mon is switched in due to Eject Button")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_ARENA_TRAP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_BULLDOZE);
            SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        MESSAGE("2 sent out Wobbuffet!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    }
}

DOUBLE_BATTLE_TEST("Eject Pack will trigger on the fastest mon at the end of the turn")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SYRUP_BOMB, MOVE_EFFECT_SYRUP_BOMB) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SYRUP_BOMB, target: playerLeft);
            MOVE(opponentRight, MOVE_SYRUP_BOMB, target: playerRight);
            SEND_OUT(playerRight, 2);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Eject Pack will trigger after a Mega Evolution")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_PACK); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MANECTRIC) { Item(ITEM_MANECTITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    }
}

