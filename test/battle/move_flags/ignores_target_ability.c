#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveIgnoresTargetAbility(MOVE_SUNSTEEL_STRIKE));
    ASSUME(MoveIgnoresTargetAbility(MOVE_MOONGEIST_BEAM));
    ASSUME(MoveIgnoresTargetAbility(MOVE_PHOTON_GEYSER));
}

SINGLE_BATTLE_TEST("ignoresTargetAbility moves do not ignore the attacker's own ability", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { move = MOVE_SUNSTEEL_STRIKE; ability = ABILITY_MAGIC_GUARD; }
    PARAMETRIZE { move = MOVE_SUNSTEEL_STRIKE; ability = ABILITY_UNAWARE; }
    PARAMETRIZE { move = MOVE_MOONGEIST_BEAM; ability = ABILITY_MAGIC_GUARD; }
    PARAMETRIZE { move = MOVE_MOONGEIST_BEAM; ability = ABILITY_UNAWARE; }
    PARAMETRIZE { move = MOVE_PHOTON_GEYSER; ability = ABILITY_MAGIC_GUARD; }
    PARAMETRIZE { move = MOVE_PHOTON_GEYSER; ability = ABILITY_UNAWARE; }

    ASSUME(gAbilitiesInfo[ABILITY_UNAWARE].breakable);
    ASSUME_STAT_CHANGE(MOVE_IRON_DEFENSE, defense: +2);
    ASSUME_STAT_CHANGE(MOVE_AMNESIA, spDef: +2);

    GIVEN {
        PLAYER(SPECIES_CLEFABLE) { Speed(1); Ability(ability); }
        OPPONENT(SPECIES_ARON) { Speed(2); }
    } WHEN {
        if (GetMoveCategory(move) == DAMAGE_CATEGORY_PHYSICAL)
            TURN { MOVE(opponent, MOVE_IRON_DEFENSE); MOVE(player, move); }
        else
            TURN { MOVE(opponent, MOVE_AMNESIA); MOVE(player, move); }
    } SCENE {
        if (GetMoveCategory(move) == DAMAGE_CATEGORY_PHYSICAL)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_IRON_DEFENSE, opponent);
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_AMNESIA, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, UQ_4_12(2.0), results[3].damage);
        EXPECT_MUL_EQ(results[4].damage, UQ_4_12(2.0), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("ignoresTargetAbility moves do ignore target's abilities", s16 damage)
{
    enum Ability ability;
    enum Move move;

    PARAMETRIZE { move = MOVE_SUNSTEEL_STRIKE; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_SUNSTEEL_STRIKE; ability = ABILITY_MULTISCALE; }
    PARAMETRIZE { move = MOVE_MOONGEIST_BEAM; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_MOONGEIST_BEAM; ability = ABILITY_MULTISCALE; }
    PARAMETRIZE { move = MOVE_PHOTON_GEYSER; ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { move = MOVE_PHOTON_GEYSER; ability = ABILITY_MULTISCALE; }

    ASSUME(gAbilitiesInfo[ABILITY_MULTISCALE].breakable);

    GIVEN {
        PLAYER(SPECIES_AZUMARILL);
        OPPONENT(SPECIES_DRAGONITE) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
        EXPECT_EQ(results[4].damage, results[5].damage);
    }
}

SINGLE_BATTLE_TEST("ignoresTargetAbility allows Pokémon with Battle Armor and Shell Armor to receive critical hits")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_KINGLER; ability = ABILITY_SHELL_ARMOR; }
    PARAMETRIZE { species = SPECIES_ARMALDO; ability = ABILITY_BATTLE_ARMOR; }

    GIVEN {
        ASSUME(MoveIgnoresTargetAbility(MOVE_SUNSTEEL_STRIKE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNSTEEL_STRIKE, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNSTEEL_STRIKE, player);
        MESSAGE("A critical hit!");
    }
}
