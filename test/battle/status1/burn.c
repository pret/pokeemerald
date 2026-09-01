#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
}

SINGLE_BATTLE_TEST("Burn deals 1/8th damage (Gen2-6) or 1/16th (Gen1 and Gen7+) per turn")
{
    u32 j, config, value;
    PARAMETRIZE { config = GEN_7; value = 16; }
    PARAMETRIZE { config = GEN_6; value = 8; }
    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, config);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < 4; j++)
            TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        for (j = 0; j < 4; j++)
            HP_BAR(player, damage: maxHP / value);
    }
}

SINGLE_BATTLE_TEST("Burn reduces Attack by 50%", s16 damage)
{
    bool32 burned;
    PARAMETRIZE { burned = FALSE; }
    PARAMETRIZE { burned = TRUE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { if (burned) Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Will-O-Wisp burns target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
        MESSAGE("The opposing Wobbuffet was burned!");
        STATUS_ICON(opponent, burn: TRUE);
    }
}


SINGLE_BATTLE_TEST("Will-O-Wisp can't burn a fire type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_WILL_O_WISP); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponent);
            STATUS_ICON(opponent, burn: TRUE);
        }
    }
}
