#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Frostbite reduces the special attack by 50 percent")
{
    s16 reducedDamage;
    s16 normaleDamage;

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWIFT); MOVE(player, MOVE_FLAME_WHEEL); }
        TURN { MOVE(opponent, MOVE_SWIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, opponent);
        HP_BAR(player, captureDamage: &reducedDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAME_WHEEL, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, opponent);
        HP_BAR(player, captureDamage: &normaleDamage);
   } THEN { EXPECT_EQ(reducedDamage * 2, normaleDamage); }
}

SINGLE_BATTLE_TEST("Frostbite deals 1/8th damage (Gen1-6) or 1/16th (Gen7+) per turn")
{
    s16 frostbiteDamage;
    u32 config, value;
    PARAMETRIZE { config = GEN_7; value = 16; }
    PARAMETRIZE { config = GEN_6; value = 8; }
    GIVEN {
        WITH_CONFIG(B_BURN_DAMAGE, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wobbuffet was hurt by its frostbite!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRB, opponent);
        HP_BAR(opponent, captureDamage: &frostbiteDamage);
    } THEN {
        EXPECT_EQ(frostbiteDamage, opponent->maxHP / value);
    }
}

SINGLE_BATTLE_TEST("Frostbite is healed if hit with a thawing move")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_FLAME_WHEEL; }
    PARAMETRIZE { move = MOVE_SACRED_FIRE; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; }
    PARAMETRIZE { move = MOVE_FUSION_FLARE; }
    PARAMETRIZE { move = MOVE_EMBER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_EMBER) {
            NONE_OF {
                MESSAGE("The opposing Wobbuffet's frostbite was cured!");
            }
        } else {
            MESSAGE("The opposing Wobbuffet's frostbite was cured!");
        }
   }
}

SINGLE_BATTLE_TEST("Frostbite is healed when the user uses a thawing move")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_FLAME_WHEEL; }
    PARAMETRIZE { move = MOVE_SACRED_FIRE; }
    PARAMETRIZE { move = MOVE_FLARE_BLITZ; }
    PARAMETRIZE { move = MOVE_FUSION_FLARE; }
    PARAMETRIZE { move = MOVE_EMBER; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_FROSTBITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        if (move == MOVE_EMBER) {
            MESSAGE("Wobbuffet was hurt by its frostbite!");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRB, player);
        } else {
            NONE_OF {
                MESSAGE("Wobbuffet was hurt by its frostbite!");
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRB, player);
            }
        }
   }
}
