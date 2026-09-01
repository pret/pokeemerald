#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dancer can copy a dance move immediately after it was used and allow the user of Dancer to still use its move")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_QUIVER_DANCE));
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUIVER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUIVER_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUIVER_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent); // Same turn
    }
}

SINGLE_BATTLE_TEST("Dancer can copy Teeter Dance")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_TEETER_DANCE));
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_TEETER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, opponent);
    }
}

DOUBLE_BATTLE_TEST("Dancer can copy Teeter Dance and confuse both opposing targets")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_TEETER_DANCE));
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_LUM_BERRY); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Item(ITEM_LUM_BERRY); }
        OPPONENT(SPECIES_SLOWPOKE) { Ability(ABILITY_OWN_TEMPO); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TEETER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TEETER_DANCE, opponentLeft);
        MESSAGE("Wobbuffet became confused!");
        MESSAGE("Wynaut became confused!");
    }
}

DOUBLE_BATTLE_TEST("Dancer triggers from fastest to slowest including modifiers (Gen 8+)")
{
    GIVEN {
        WITH_CONFIG(B_DANCER_ORDER, GEN_9);
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(GetItemHoldEffect(ITEM_IRON_BALL) == HOLD_EFFECT_IRON_BALL);
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); Item(ITEM_IRON_BALL); }
        PLAYER(SPECIES_WYNAUT) { Speed(50); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(20); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(7); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Dancer triggers from slowest to fastest Raw Speed (Gen 7)")
{
    GIVEN {
        WITH_CONFIG(B_DANCER_ORDER, GEN_7);
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
        PLAYER(SPECIES_WYNAUT) { Speed(50); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(20); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(3); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Dancer triggers from slowest to fastest during Trick Room (Gen 7)")
{
    GIVEN {
        WITH_CONFIG(B_DANCER_ORDER, GEN_7);
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(20); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(5); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_TRICK_ROOM); }
        TURN { MOVE(playerRight, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK_ROOM, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Dancer triggering ignores Lagging Tail")
{
    GIVEN {
        WITH_CONFIG(B_DANCER_ORDER, GEN_7);
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(gItemsInfo[ITEM_LAGGING_TAIL].holdEffect == HOLD_EFFECT_LAGGING_TAIL);
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); Item(ITEM_LAGGING_TAIL); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(5); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(20); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ABILITY_POPUP(playerLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    }
}

SINGLE_BATTLE_TEST("Dancer doesn't trigger if the original user flinches")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        MESSAGE("Wobbuffet flinched and couldn't move!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Dancer still triggers if another dancer flinches")
{
    GIVEN {
        WITH_CONFIG(B_DANCER_ORDER, GEN_7);
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
        PLAYER(SPECIES_WYNAUT) { Speed(5); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FAKE_OUT, target: playerLeft); MOVE(playerRight, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(playerLeft, ABILITY_DANCER);
        MESSAGE("Oricorio flinched and couldn't move!");
        NONE_OF {
            MESSAGE("Oricorio used Dragon Dance!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        MESSAGE("The opposing Oricorio used Dragon Dance!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    }
}

SINGLE_BATTLE_TEST("Dancer-called attacks have their type updated")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_REVELATION_DANCE));
        ASSUME(GetMoveEffect(MOVE_REVELATION_DANCE) == EFFECT_REVELATION_DANCE);
        PLAYER(SPECIES_TANGROWTH);
        OPPONENT(SPECIES_ORICORIO_BAILE);
    } WHEN {
        TURN { MOVE(player, MOVE_REVELATION_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, player);
        MESSAGE("It's mostly ineffective…");
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, opponent);
        NOT MESSAGE("It's mostly ineffective…");
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Dancer-called attacks do not trigger Life Orb if target is immune")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_REVELATION_DANCE));
        ASSUME(GetMoveEffect(MOVE_REVELATION_DANCE) == EFFECT_REVELATION_DANCE);
        ASSUME(GetMoveEffect(MOVE_ROOST) == EFFECT_ROOST);
        ASSUME(GetItemHoldEffect(ITEM_LIFE_ORB) == HOLD_EFFECT_LIFE_ORB);
        ASSUME(GetSpeciesType(SPECIES_ORICORIO_POM_POM, 0) == TYPE_ELECTRIC || GetSpeciesType(SPECIES_ORICORIO_POM_POM, 1) == TYPE_ELECTRIC);
        PLAYER(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
        OPPONENT(SPECIES_ORICORIO_POM_POM) { Ability(ABILITY_DANCER); Item(ITEM_LIFE_ORB); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROOST); MOVE(player, MOVE_REVELATION_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, opponent);
        ABILITY_POPUP(player, ABILITY_LIGHTNING_ROD);
        NOT HP_BAR(opponent);
    }
}

DOUBLE_BATTLE_TEST("Dancer doesn't trigger on a snatched move")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(GetMoveEffect(MOVE_SNATCH) == EFFECT_SNATCH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ORICORIO);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SNATCH); MOVE(playerRight, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNATCH, opponentRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Dancer doesn't trigger when an ally snatches the move")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(GetMoveEffect(MOVE_SNATCH) == EFFECT_SNATCH);
        ASSUME(MoveCanBeSnatched(MOVE_DRAGON_DANCE));
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SNATCH); MOVE(playerRight, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNATCH, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Dancer doesn't activate if the original move missed")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_DOUBLE_TEAM, evasion: +1);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_DOUBLE_TEAM); MOVE(playerLeft, MOVE_FIERY_DANCE, target: opponentLeft, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DOUBLE_TEAM, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerLeft);
        MESSAGE("The opposing Oricorio avoided the attack!");
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, opponentLeft);
        }
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Dancer doesn't activate after Neutralizing Gas leaves the field")
{
    u32 hp;

    PARAMETRIZE { hp = 1; }
    PARAMETRIZE { hp = 200; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_EJECT_BUTTON) == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(hp); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIERY_DANCE, target: opponentRight); SEND_OUT(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerLeft);
        if (hp == 1) { // target faints
            HP_BAR(opponentRight, hp: 0);
            ABILITY_POPUP(playerRight, ABILITY_INTIMIDATE);
        } else { // target activates eject button
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
            ABILITY_POPUP(playerRight, ABILITY_INTIMIDATE);
        }
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, opponentLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Dancer can activate after Neutralizing Gas enters the field on move execution")
{
    u32 speedPlayerRight;
    PARAMETRIZE { speedPlayerRight = 3; }
    PARAMETRIZE { speedPlayerRight = 7; }

    GIVEN {
        WITH_CONFIG(B_DANCER_ORDER, GEN_7);
        ASSUME(GetItemHoldEffect(ITEM_EJECT_BUTTON) == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(speedPlayerRight); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); Speed(3); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIERY_DANCE, target: opponentRight); SEND_OUT(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        ABILITY_POPUP(opponentRight, ABILITY_NEUTRALIZING_GAS);
        if (speedPlayerRight < 5) {
            ABILITY_POPUP(playerRight, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerRight);
        }
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, opponentLeft);
        if (speedPlayerRight > 5) {
            ABILITY_POPUP(playerRight, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerRight);
        }
    }
}

SINGLE_BATTLE_TEST("Dancer-called moves can be reflected by Magic Bounce")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_FEATHER_DANCE));
        PLAYER(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
    } WHEN {
        TURN { MOVE(player, MOVE_FEATHER_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ABILITY_POPUP(player, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, opponent);
        MESSAGE("The opposing Oricorio's Feather Dance was bounced back!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 4);
    }
}

DOUBLE_BATTLE_TEST("Dancer triggers on Instructed dance moves")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(!IsMoveInstructBanned(MOVE_DRAGON_DANCE));
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ORICORIO);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_DRAGON_DANCE); MOVE(playerLeft, MOVE_INSTRUCT, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Dancer-called move doesn't update move to be Instructed")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(!IsMoveInstructBanned(MOVE_SCRATCH));
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ORICORIO);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_DRAGON_DANCE); MOVE(opponentRight, MOVE_INSTRUCT, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Dancer-called moves do not update move to be called by Mimic")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(GetMoveEffect(MOVE_MIMIC) == EFFECT_MIMIC);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft);
            MOVE(playerRight, MOVE_DRAGON_DANCE);
            MOVE(playerLeft, MOVE_MIMIC, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIMIC, playerLeft);
        MESSAGE("Wobbuffet learned Scratch!");
        NOT MESSAGE("Wobbuffet learned Dragon Dance!");
    }
}

DOUBLE_BATTLE_TEST("Dancer-called moves doesn't update move to be called by Mirror Move")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(GetMoveEffect(MOVE_MIRROR_MOVE) == EFFECT_MIRROR_MOVE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_DRAGON_DANCE); }
        TURN { MOVE(playerLeft, MOVE_MIRROR_MOVE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Wobbuffet used Mirror Move!");
        MESSAGE("Wobbuffet used Scratch!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        NOT MESSAGE("Wobbuffet used Dragon Dance!");
    }
}

DOUBLE_BATTLE_TEST("Dancer doesn't call a move that didn't execute due to Powder")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_FIERY_DANCE));
        ASSUME(GetMoveType(MOVE_FIERY_DANCE) == TYPE_FIRE);
        PLAYER(SPECIES_VOLCARONA);
        PLAYER(SPECIES_ORICORIO);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(playerLeft, MOVE_FIERY_DANCE, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerLeft);
            HP_BAR(opponentLeft);
            ABILITY_POPUP(playerRight, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Dancer still activates after Red Card")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) ;
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
        PLAYER(SPECIES_CHANSEY);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_SHUCKLE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIERY_DANCE, target: opponentLeft); }
    } SCENE {
        MESSAGE("Wobbuffet used Fiery Dance!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerLeft);
        HP_BAR(opponentLeft);
        // Red card trigger
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("The opposing Wobbuffet held up its Red Card against Wobbuffet!");
        MESSAGE("Chansey was dragged out!");
        // Dancer
        ABILITY_POPUP(playerRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerRight);
        HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Dancer still activates after Red Card even if blocked by Suction Cups")
{
    GIVEN {
        PLAYER(SPECIES_OCTILLERY) { Ability(ABILITY_SUCTION_CUPS); }
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
        PLAYER(SPECIES_CHANSEY);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_SHUCKLE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIERY_DANCE, target: opponentLeft); }
    } SCENE {
        MESSAGE("Octillery used Fiery Dance!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerLeft);
        HP_BAR(opponentLeft);
        // red card trigger
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        MESSAGE("The opposing Wobbuffet held up its Red Card against Octillery!");
        MESSAGE("Octillery is anchored in place with its suction cups!");
        NOT MESSAGE("Chansey was dragged out!");
        // Dancer
        ABILITY_POPUP(playerRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerRight);
        HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Dancer correctly restores move targets")
{
    GIVEN {
        WITH_CONFIG(B_DANCER_ORDER, GEN_7);
        ASSUME(IsDanceMove(MOVE_REVELATION_DANCE));
        PLAYER(SPECIES_ORICORIO) { Speed(10); }
        PLAYER(SPECIES_ORICORIO) { Speed(3); }
        OPPONENT(SPECIES_ORICORIO) { Speed(1); }
        OPPONENT(SPECIES_ORICORIO) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_REVELATION_DANCE, target: opponentLeft);
               MOVE(opponentRight, MOVE_SCRATCH, target: playerRight);
               MOVE(playerRight, MOVE_SCRATCH, target: opponentRight);
               MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, playerLeft);
        HP_BAR(opponentLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, opponentLeft);
        HP_BAR(playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, playerRight);
        HP_BAR(opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVELATION_DANCE, opponentRight);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentRight);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Dancer-called damaging moves are considered for Counter/Mirror Coat/Metal Burst")
{
    u32 danceMove, retaliateMove;

    PARAMETRIZE { danceMove = MOVE_AQUA_STEP; retaliateMove = MOVE_COUNTER; }
    PARAMETRIZE { danceMove = MOVE_FIERY_DANCE; retaliateMove = MOVE_MIRROR_COAT; }
    PARAMETRIZE { danceMove = MOVE_FIERY_DANCE; retaliateMove = MOVE_METAL_BURST; }

    GIVEN {
        ASSUME(IsDanceMove(danceMove));
        if (retaliateMove == MOVE_COUNTER)
            ASSUME(GetMoveCategory(danceMove) == DAMAGE_CATEGORY_PHYSICAL);
        else if (retaliateMove == MOVE_MIRROR_COAT)
            ASSUME(GetMoveCategory(danceMove) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(playerLeft, danceMove, target: opponentLeft); MOVE(opponentLeft, retaliateMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, danceMove, playerLeft);
        HP_BAR(opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, danceMove, playerRight);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, retaliateMove, opponentLeft);
        HP_BAR(playerRight);
        NOT HP_BAR(playerLeft);
    }
}

SINGLE_BATTLE_TEST("Dancer copies a status Z-Move's base move without gaining an additional Z-Power effect")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_SWORDS_DANCE));
        ASSUME_STAT_CHANGE(MOVE_SCREECH, defense: -2);
        ASSUME(GetMoveZEffect(MOVE_SWORDS_DANCE) == Z_EFFECT_RESET_STATS);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCREECH); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Dancer user may hit itself in confusion instead of copying a move if it's confused")
{
    u32 genConfig, pctChance;

    PARAMETRIZE { genConfig = GEN_6; pctChance = 50; }
    PARAMETRIZE { genConfig = GEN_7; pctChance = 33; }
    PASSES_RANDOMLY(pctChance, 100, RNG_CONFUSION);
    GIVEN {
        WITH_CONFIG(B_CONFUSION_SELF_DMG_CHANCE, genConfig);
        ASSUME(IsDanceMove(MOVE_DRAGON_DANCE));
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
        TURN { MOVE(player, MOVE_DRAGON_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("The opposing Oricorio became confused!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        MESSAGE("The opposing Oricorio is confused!");
        MESSAGE("It hurt itself in its confusion!");
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DANCE, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Dancer can still copy a move even if it's being forced into a different move - Rampage move")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_SWORDS_DANCE));
        ASSUME(IsDanceMove(MOVE_PETAL_DANCE));
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_PETAL_DANCE, MOVE_EFFECT_THRASH));
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PETAL_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); FORCED_MOVE(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PETAL_DANCE, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Dancer can still copy a move even if it's being forced into a different move - Rollout")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_SWORDS_DANCE));
        ASSUME(GetMoveEffect(MOVE_ROLLOUT) == EFFECT_ROLLOUT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROLLOUT); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); FORCED_MOVE(opponent); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLLOUT, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Dancer can still copy a move even if it's being forced into a different move - Choice items")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_SWORDS_DANCE));
        ASSUME(GetItemHoldEffect(ITEM_CHOICE_BAND) == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); Item(ITEM_CHOICE_BAND); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Dancer can still copy a move even if it's being forced into a different move - Encore")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_SWORDS_DANCE));
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_ENCORE, target: opponent); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, player);
        MESSAGE("The opposing Oricorio must do an encore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Dancer tries to copy a status move but fails if it's under Taunt's effect")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_SWORDS_DANCE));
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAUNT); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Dancer can still copy status moves if the user is holding an Assault Vest")
{
    GIVEN {
        ASSUME(IsDanceMove(MOVE_SWORDS_DANCE));
        ASSUME(GetItemHoldEffect(ITEM_ASSAULT_VEST) == HOLD_EFFECT_ASSAULT_VEST);
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(10); Item(ITEM_ASSAULT_VEST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Dancer copies Lunar Dance after the original user faints, but before the replacement is sent out")
{
    GIVEN {
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_7);
        ASSUME(GetMoveEffect(MOVE_LUNAR_DANCE) == EFFECT_LUNAR_DANCE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        PLAYER(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(20); }
        PLAYER(SPECIES_WYNAUT) { Speed(5); }
        PLAYER(SPECIES_CHANSEY) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LUNAR_DANCE); SEND_OUT(playerLeft, 2); SEND_OUT(playerRight, 3); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LUNAR_DANCE, playerLeft);
        HP_BAR(playerLeft, hp: 0);
        MESSAGE("Wobbuffet fainted!");
        ABILITY_POPUP(playerRight, ABILITY_DANCER);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LUNAR_DANCE, playerRight);
        HP_BAR(playerRight, hp: 0);
        MESSAGE("Oricorio fainted!");
        SEND_IN_MESSAGE("Wynaut");
        SEND_IN_MESSAGE("Chansey");
    }
}

DOUBLE_BATTLE_TEST("Dancer doesn't activate Feather Dance if it was reflected by Magic Bounce/Coat")
{
    bool32 useMagicCoat;

    PARAMETRIZE { useMagicCoat = FALSE; }
    PARAMETRIZE { useMagicCoat = TRUE; }
    GIVEN {
        ASSUME(IsDanceMove(MOVE_FEATHER_DANCE));
        ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        if (useMagicCoat)
            OPPONENT(SPECIES_WOBBUFFET) { Speed(30); }
        else
            OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); Speed(30); }
        OPPONENT(SPECIES_ORICORIO) { Ability(ABILITY_DANCER); Speed(5); }
    } WHEN {
        if (useMagicCoat)
            TURN { MOVE(opponentLeft, MOVE_MAGIC_COAT); MOVE(playerLeft, MOVE_FEATHER_DANCE, target: opponentLeft); }
        else
            TURN { MOVE(playerLeft, MOVE_FEATHER_DANCE, target: opponentLeft); }
    } SCENE {
        if (useMagicCoat)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, opponentLeft);
        else
            ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        NONE_OF {
            ABILITY_POPUP(opponentRight, ABILITY_DANCER);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FEATHER_DANCE, opponentRight);
        }
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
    }
}
