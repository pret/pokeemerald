#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TRANSFORM) == EFFECT_TRANSFORM);
}

SINGLE_BATTLE_TEST("Transform fails on semi-invulnerable target in Gen2+")
{
    u32 genConfig;
    bool32 expectFail;

    // PARAMETRIZE { genConfig = GEN_1; expectFail = FALSE; } // Gen1 Setting broken by #9170
    PARAMETRIZE { genConfig = GEN_2; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_SEMI_INV_FAIL, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_DIG); }
        OPPONENT(SPECIES_DITTO) { Speed(10); Moves(MOVE_TRANSFORM); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIG); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        if (expectFail)
            MESSAGE("Wobbuffet avoided the attack!");
        else
            MESSAGE("The opposing Ditto transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transform fails on transformed target in Gen2+")
{
    u32 genConfig;
    bool32 expectFail;

    PARAMETRIZE { genConfig = GEN_1; expectFail = FALSE; }
    PARAMETRIZE { genConfig = GEN_2; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_TARGET_FAIL, genConfig);
        PLAYER(SPECIES_DITTO) { Speed(50); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        MESSAGE("Ditto transformed into Wobbuffet!");
        if (expectFail)
            MESSAGE("But it failed!");
        else
            MESSAGE("The opposing Wobbuffet transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transform fails when the user is already transformed in Gen5+")
{
    u32 genConfig;
    bool32 expectFail;

    PARAMETRIZE { genConfig = GEN_4; expectFail = FALSE; }
    PARAMETRIZE { genConfig = GEN_5; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_USER_FAIL, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_DITTO) { Speed(10); Moves(MOVE_TRANSFORM, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        MESSAGE("The opposing Ditto transformed into Wobbuffet!");
        if (expectFail)
            MESSAGE("But it failed!");
        else
            MESSAGE("The opposing Ditto transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transform fails on target behind substitute in Gen5+")
{
    u32 genConfig;
    bool32 expectFail;

    PARAMETRIZE { genConfig = GEN_4; expectFail = FALSE; }
    PARAMETRIZE { genConfig = GEN_5; expectFail = TRUE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_SUBSTITUTE_FAIL, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_SUBSTITUTE); }
        OPPONENT(SPECIES_DITTO) { Speed(10); Moves(MOVE_TRANSFORM); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        if (expectFail)
            MESSAGE("But it failed!");
        else
            MESSAGE("The opposing Ditto transformed into Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Transformed Pokemon cannot change forms in Gen5+")
{
    u32 genConfig;
    bool32 expectFormChange;

    PARAMETRIZE { genConfig = GEN_4; expectFormChange = TRUE; }
    PARAMETRIZE { genConfig = GEN_5; expectFormChange = FALSE; }

    GIVEN {
        WITH_CONFIG(B_TRANSFORM_FORM_CHANGES, genConfig);
        PLAYER(SPECIES_AEGISLASH) { Moves(MOVE_TACKLE, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_DITTO) { Moves(MOVE_TACKLE, MOVE_TRANSFORM); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        if (expectFormChange) {
            ABILITY_POPUP(opponent, ABILITY_STANCE_CHANGE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_STANCE_CHANGE);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, opponent);
            }
        }
    } THEN {
        if (expectFormChange)
            EXPECT_EQ(opponent->species, SPECIES_AEGISLASH_BLADE);
        else
            EXPECT_EQ(opponent->species, SPECIES_AEGISLASH);
    }
}

SINGLE_BATTLE_TEST("(TERA) Transform does not copy the target's Tera Type, and if the user is Terastallized it keeps its own Tera Type")
{
    u32 playerDoTera;
    PARAMETRIZE { playerDoTera = GIMMICK_TERA; }
    PARAMETRIZE { playerDoTera = GIMMICK_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_EARTHQUAKE); TeraType(TYPE_GHOST); }
        OPPONENT(SPECIES_DITTO) { TeraType(TYPE_FLYING); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: playerDoTera); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, moveSlot: 0); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); MOVE(opponent, moveSlot: 0, gimmick: GIMMICK_TERA); }
    } SCENE {
        // turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        // turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // turn 3
        MESSAGE("Wobbuffet used Earthquake!");
        MESSAGE("It doesn't affect the opposing Ditto…");
        NOT { HP_BAR(opponent); }
    }
}

SINGLE_BATTLE_TEST("Transform returns the user to normal at the end of the battle after fainting")
{
    GIVEN {
        PLAYER(SPECIES_DITTO) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEOT) { Item(ITEM_PIDGEOTITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_TRANSFORM); }
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_DITTO);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Transform (Move Effect) test titles")
