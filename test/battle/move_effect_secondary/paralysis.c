#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_THUNDER_SHOCK, MOVE_EFFECT_PARALYSIS) == TRUE);
}

SINGLE_BATTLE_TEST("Thunder Shock inflicts paralysis")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Thunder Shock cannot paralyze an Electric-type (Gen6+)")
{
    u32 gen = 0;
    PARAMETRIZE { gen = GEN_5; }
    PARAMETRIZE { gen = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_PARALYZE_ELECTRIC, gen);
        ASSUME(GetSpeciesType(SPECIES_PIKACHU, 0) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_SHOCK, secondaryEffect: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, player);
        HP_BAR(opponent);
        if (gen == GEN_6) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        } else {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    }
}

#if B_STATUS_TYPE_IMMUNITY > GEN_1
SINGLE_BATTLE_TEST("Body Slam should paralyze Normal-types")
#else
SINGLE_BATTLE_TEST("Body Slam shouldn't paralyze Normal-types")
#endif
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_TAUROS, 0) == TYPE_NORMAL);
        ASSUME(MoveHasAdditionalEffect(MOVE_BODY_SLAM, MOVE_EFFECT_PARALYSIS) == TRUE);
        ASSUME(GetMoveType(MOVE_BODY_SLAM) == TYPE_NORMAL);
        PLAYER(SPECIES_TAUROS);
        OPPONENT(SPECIES_TAUROS);
    } WHEN {
        TURN { MOVE(player, MOVE_BODY_SLAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BODY_SLAM, player);
        HP_BAR(opponent);
        #if B_STATUS_TYPE_IMMUNITY > GEN_1
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        #else
            NONE_OF {
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
                STATUS_ICON(opponent, paralysis: TRUE);
            }
        #endif
    }
}
