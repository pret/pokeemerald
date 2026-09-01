#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mirror Armor lowers a stat of the attacking Pokémon")
{
    enum Move move;
    u32 statId;

    PARAMETRIZE { move = MOVE_LEER;        statId = STAT_DEF; }
    PARAMETRIZE { move = MOVE_GROWL;       statId = STAT_ATK; }
    PARAMETRIZE { move = MOVE_SWEET_SCENT; statId = STAT_EVASION; }
    PARAMETRIZE { move = MOVE_SAND_ATTACK; statId = STAT_ACC; }
    PARAMETRIZE { move = MOVE_CONFIDE;     statId = STAT_SPATK; }
    PARAMETRIZE { move = MOVE_FAKE_TEARS;  statId = STAT_SPDEF; }

    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[statId], DEFAULT_STAT_STAGE);
        EXPECT(opponent->statStages[statId] < DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor triggers even if the attacking Pokemon also has Mirror Armor ability")
{
    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEER); }
    } SCENE {
        MESSAGE("The opposing Corviknight used Leer!");
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Corviknight's Defense fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor doesn't lower the stats of an attacking Pokemon with the Clear Body ability")
{
    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_WYNAUT) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEER); }
    } SCENE {
        MESSAGE("The opposing Wynaut used Leer!");
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
        MESSAGE("The opposing Wynaut's stats were not lowered!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor lowers the Attack of Pokemon with Intimidate")
{
    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_GYARADOS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Gyarados's Attack fell!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor doesn't lower the stats of an attacking Pokemon behind Substitute")
{
    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_LEER); }
    } SCENE {
        MESSAGE("The opposing Wynaut used Substitute!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        MESSAGE("The opposing Wynaut used Leer!");
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor raises the stat of an attacking Pokemon with Contrary")
{
    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_SHUCKLE) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEER); }
    } SCENE {
        MESSAGE("The opposing Shuckle used Leer!");
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Shuckle's Defense rose!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor doesn't lower the stat of the attacking Pokemon if it is already at -6")
{
    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SCREECH); }
        TURN { MOVE(player, MOVE_SCREECH); }
        TURN { MOVE(player, MOVE_SCREECH); }
        TURN { MOVE(opponent, MOVE_LEER); }
    } SCENE {
        MESSAGE("Corviknight used Screech!");
        MESSAGE("Corviknight used Screech!");
        MESSAGE("Corviknight used Screech!");
        MESSAGE("The opposing Wynaut used Leer!");
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wynaut's Defense won't go any lower!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], MIN_STAT_STAGE);
    }
}

// This behaviour needs to be verified in the actual games. Currently it's written to follow Showdown's logic.
DOUBLE_BATTLE_TEST("Mirror Armor lowers Speed of the partner Pokemon after Court Change was used by the opponent after it set up Sticky Web")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        ASSUME(GetMoveEffect(MOVE_COURT_CHANGE) == EFFECT_COURT_CHANGE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); Item(ITEM_IRON_BALL); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STICKY_WEB); }
        TURN { MOVE(opponentLeft, MOVE_COURT_CHANGE); }
        TURN { SWITCH(playerRight, 2); }
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Sticky Web!");
        MESSAGE("The opposing Wynaut used Court Change!");
        MESSAGE("The opposing Wynaut swapped the battle effects affecting each side of the field!");
        SEND_IN_MESSAGE("Corviknight");
        MESSAGE("Corviknight was caught in a sticky web!");
        ABILITY_POPUP(playerRight, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Speed fell!");
    }
}

SINGLE_BATTLE_TEST("Mirror Armor reflects Tangling Hair speed drop")
{
    GIVEN {
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); }
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor reflects Obstruct defense drop")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_OBSTRUCT); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OBSTRUCT, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    }
}

// Is there really an ability pop up?
SINGLE_BATTLE_TEST("Mirror Armor does not trigger if the user is behind a Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_TANGLING_HAIR); }
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(player, ABILITY_TANGLING_HAIR);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Mirror Armor reflects stat drops triggered by a damaging move")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_ICY_WIND, speed: -1);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_ICY_WIND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICY_WIND, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Mirror Armor does not trigger ally's Defiant")
{
    GIVEN {
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
        PLAYER(SPECIES_PRIMEAPE) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FAKE_TEARS, target: playerLeft); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_TEARS, playerRight);
        ABILITY_POPUP(playerLeft, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        NOT ABILITY_POPUP(playerRight, ABILITY_DEFIANT);
    }
}

SINGLE_BATTLE_TEST("Mirror Armor does not reflect Sticky Web stat drops (Gen9+) / reflects onto Sticky Web setter (Gen 8)")
{
    u32 config;

    PARAMETRIZE { config = GEN_8; }
    PARAMETRIZE { config = GEN_9; }

    GIVEN {
        WITH_CONFIG(B_MIRROR_ARMOR_STICKY_WEB, config);
        ASSUME(gItemsInfo[ITEM_IRON_BALL].holdEffect == HOLD_EFFECT_IRON_BALL);
        ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); Item(ITEM_IRON_BALL); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        ABILITY_POPUP(player, ABILITY_MIRROR_ARMOR);
        if (config == GEN_8) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            }
        }
    }
}
