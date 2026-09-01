#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Water Compaction raises Defense 2 stages when hit by a water type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_SANDYGAST) { Ability(ABILITY_WATER_COMPACTION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        ABILITY_POPUP(player, ABILITY_WATER_COMPACTION);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Water Compaction raises Defense 2 stages on each hit of a multi-hit Water type move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SURGING_STRIKES) == TYPE_WATER);
        ASSUME(GetMoveStrikeCount(MOVE_SURGING_STRIKES) == 3);
        PLAYER(SPECIES_SANDYGAST) { Ability(ABILITY_WATER_COMPACTION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SURGING_STRIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponent);
        ABILITY_POPUP(player, ABILITY_WATER_COMPACTION);
        MESSAGE("Sandygast's Defense rose sharply!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponent);
        ABILITY_POPUP(player, ABILITY_WATER_COMPACTION);
        MESSAGE("Sandygast's Defense rose sharply!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponent);
        ABILITY_POPUP(player, ABILITY_WATER_COMPACTION);
        MESSAGE("Sandygast's Defense rose sharply!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 6);
    }
}

SINGLE_BATTLE_TEST("Water Compaction does not affect damage taken from Water type moves", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_SAND_VEIL; }
    PARAMETRIZE { ability = ABILITY_WATER_COMPACTION; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        PLAYER(SPECIES_SANDYGAST) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
