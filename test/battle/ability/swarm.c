#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Swarm boosts Bug-type moves in a pinch", s16 damage)
{
    u16 hp;
    PARAMETRIZE { hp = 99; }
    PARAMETRIZE { hp = 33; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_BUG_BITE) == TYPE_BUG);
        ASSUME(GetMovePower(MOVE_BUG_BITE) == 60);
        ASSUME(GetMoveCategory(MOVE_BUG_BITE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetSpeciesType(SPECIES_LEDYBA, 0) == TYPE_BUG);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) == TYPE_PSYCHIC);
        PLAYER(SPECIES_LEDYBA) { Ability(ABILITY_SWARM); MaxHP(99); HP(hp); Attack(45); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(121); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // Due to numerics related to rounding on each applied multiplier,
        // the 50% move power increase doesn't manifest as a 50% damage increase, but as a 44% damage increase in this case.
        // Values obtained from https://calc.pokemonshowdown.com (Neutral nature and 0 IVs on both sides)
        EXPECT_EQ(results[0].damage, 50);
        EXPECT_EQ(results[1].damage, 72);
    }
}
