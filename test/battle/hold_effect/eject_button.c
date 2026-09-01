#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
}

SINGLE_BATTLE_TEST("Eject Button is not triggered when there is nothing to switch in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(0); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_QUICK_ATTACK);
            MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Eject Button is not activated by a Sheer Force boosted move")
{
    GIVEN {
        PLAYER(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_FLAMETHROWER);
            MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAMETHROWER, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Eject Button will not activate under Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
               MOVE(opponent, MOVE_SUBSTITUTE);
               MOVE(player, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        MESSAGE("The opposing Raichu put in a substitute!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("The substitute took damage for the opposing Raichu!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Raichu is switched out with the Eject Button!");
        }
    }
}

SINGLE_BATTLE_TEST("Eject Button is not blocked by trapping abilities or moves")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_ARENA_TRAP); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_SCRATCH);
            SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        MESSAGE("2 sent out Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Eject Button is not triggered after the mon loses Eject Button")
{
    GIVEN {
        PLAYER(SPECIES_RAICHU);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_KNOCK_OFF);
            MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Eject Button is not triggered after given to player by Picketpocket")
{
    GIVEN {
        PLAYER(SPECIES_REGIELEKI) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_SCRATCH);
            MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Regieleki's Eject Button!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

SINGLE_BATTLE_TEST("Eject Button has no chance to activate after Dragon Tail")
{
    GIVEN {
        PLAYER(SPECIES_KOMMO_O);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_CHANSEY);
    } WHEN {
        TURN {
            MOVE(player, MOVE_DRAGON_TAIL);
            MOVE(opponent, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        MESSAGE("The opposing Chansey was dragged out!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Chansey is switched out with the Eject Button!");
        }
    }
}

SINGLE_BATTLE_TEST("Eject Button prevents Volt Switch / U-Turn from activating")
{
    GIVEN {
        PLAYER(SPECIES_MANECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(player, MOVE_VOLT_SWITCH);
            SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VOLT_SWITCH, player);
        MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
    }
}

SINGLE_BATTLE_TEST("Eject Button is activated before Emergency Exit")
{
    GIVEN {
        PLAYER(SPECIES_LATIAS);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_THUNDERBOLT);
            SEND_OUT(opponent, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Golisopod is switched out with the Eject Button!");
    }
}

SINGLE_BATTLE_TEST("Eject Button is not triggered after High Jump Kick crash damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_PROTECT);
            MOVE(opponent, MOVE_HIGH_JUMP_KICK);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        MESSAGE("The opposing Wobbuffet kept going and crashed!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
            MESSAGE("The opposing Wobbuffet is switched out with the Eject Button!");
        }
    }
}

SINGLE_BATTLE_TEST("Eject Button activates after Wandering Spirit")
{
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_YAMASK_GALAR) { Item(ITEM_EJECT_BUTTON); Ability(ABILITY_WANDERING_SPIRIT); }
    } WHEN {
        TURN {
            SWITCH(opponent, 1);
            MOVE(player, MOVE_DRAGON_CLAW);
            SEND_OUT(opponent, 0);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CLAW, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    }
}

DOUBLE_BATTLE_TEST("Eject Button will activate before Red Card if holder is faster")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WYNAUT) { Speed(25); Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_HYPER_VOICE);
            SEND_OUT(opponentLeft, 2);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
    }
}

SINGLE_BATTLE_TEST("Eject Button activates and the attacker takes Life Orb recoil before replacement comes out")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_LIFE_ORB) == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        HP_BAR(player);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
    }
}
