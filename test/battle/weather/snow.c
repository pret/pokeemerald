#include "global.h"
#include "test/battle.h"

// Please add Snow interactions with move, item and ability effects on their respective files.
ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SNOWSCAPE].effect == EFFECT_SNOWSCAPE);
    ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_ICE && gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_ICE);
    ASSUME(gSpeciesInfo[SPECIES_GLALIE].types[0] == TYPE_ICE || gSpeciesInfo[SPECIES_GLALIE].types[1] == TYPE_ICE);
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Snow multiplies the defense of Ice-types by 1.5x", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Snowscape fails if Desolate Land or Primordial Sea are active")
{
    u32 species;
    u32 item;

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
