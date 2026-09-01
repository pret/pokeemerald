#include "global.h"
#include "test/battle.h"

// Please add Snow interactions with move, item and ability effects on their respective files.
ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SNOWSCAPE) == EFFECT_WEATHER);
    ASSUME(GetMoveWeatherType(MOVE_SNOWSCAPE) == BATTLE_WEATHER_SNOW);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_ICE && GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_ICE);
    ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE || GetSpeciesType(SPECIES_GLALIE, 1) == TYPE_ICE);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Snow multiplies the defense of Ice-types by 1.5x", s16 damage)
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Snowscape fails if Desolate Land or Primordial Sea are active")
{
    enum Species species;
    enum Item item;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_GROUDON; item = ITEM_RED_ORB; }
    PARAMETRIZE { species = SPECIES_KYOGRE; item = ITEM_BLUE_ORB; }

    GIVEN {
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SNOWSCAPE); }
    } SCENE {
        if (item == ITEM_RED_ORB || item == ITEM_BLUE_ORB) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, player);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponent);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SNOWSCAPE, opponent);
        }
    }
}
