#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_ENTRAINMENT].effect == EFFECT_ENTRAINMENT);
}

SINGLE_BATTLE_TEST("Tablets of Ruin reduces Attack if opposing mon's ability doesn't match")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_WO_CHIEN) { Ability(ABILITY_TABLETS_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_ENTRAINMENT); }
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_TABLETS_OF_RUIN);
        MESSAGE("Wo-Chien's Tablets of Ruin weakened the Attack of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENTRAINMENT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.33), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Tablets of Ruin's message displays correctly after all battlers fainted - Player")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EXPLOSION].effect == EFFECT_EXPLOSION);
        PLAYER(SPECIES_WOBBUFFET) { HP(1);}
        PLAYER(SPECIES_WO_CHIEN);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_RUINATION); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
        // Everyone faints.
        MESSAGE("Go! Wo-Chien!");
        ABILITY_POPUP(player, ABILITY_TABLETS_OF_RUIN);
        MESSAGE("Wo-Chien's Tablets of Ruin weakened the Attack of all surrounding Pokémon!");
        MESSAGE("2 sent out Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Tablets of Ruin's message displays correctly after all battlers fainted - Opponent")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_EXPLOSION].effect == EFFECT_EXPLOSION);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1);}
        OPPONENT(SPECIES_WO_CHIEN);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_RUINATION); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        // Everyone faints.
        MESSAGE("Go! Wobbuffet!");
        MESSAGE("2 sent out Wo-Chien!");
        ABILITY_POPUP(opponent, ABILITY_TABLETS_OF_RUIN);
        MESSAGE("Foe Wo-Chien's Tablets of Ruin weakened the Attack of all surrounding Pokémon!");
    }
}
