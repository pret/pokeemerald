#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SUNSTEEL_STRIKE].ignoresTargetAbility);
    ASSUME(gMovesInfo[MOVE_MOONGEIST_BEAM].ignoresTargetAbility);
    ASSUME(gMovesInfo[MOVE_PHOTON_GEYSER].ignoresTargetAbility);
}

SINGLE_BATTLE_TEST("ignoresTargetAbility moves do not ignore the attacker's own ability", s16 damage)
{
    u32 ability, move;

    PARAMETRIZE { move = MOVE_SUNSTEEL_STRIKE; ability = ABILITY_MAGIC_GUARD; }
    PARAMETRIZE { move = MOVE_SUNSTEEL_STRIKE; ability = ABILITY_UNAWARE; }
    PARAMETRIZE { move = MOVE_MOONGEIST_BEAM; ability = ABILITY_MAGIC_GUARD; }
    PARAMETRIZE { move = MOVE_MOONGEIST_BEAM; ability = ABILITY_UNAWARE; }
    PARAMETRIZE { move = MOVE_PHOTON_GEYSER; ability = ABILITY_MAGIC_GUARD; }
    PARAMETRIZE { move = MOVE_PHOTON_GEYSER; ability = ABILITY_UNAWARE; }

    ASSUME(gAbilitiesInfo[ABILITY_UNAWARE].breakable);
    ASSUME(gMovesInfo[MOVE_IRON_DEFENSE].effect == EFFECT_DEFENSE_UP_2);
    ASSUME(gMovesInfo[MOVE_AMNESIA].effect == EFFECT_SPECIAL_DEFENSE_UP_2);

    GIVEN {
        PLAYER(SPECIES_CLEFABLE) { Speed(1); Ability(ability); }
        OPPONENT(SPECIES_ARON) { Speed(2); }
    } WHEN {
        if (gMovesInfo[move].category == DAMAGE_CATEGORY_PHYSICAL)
            TURN { MOVE(opponent, MOVE_IRON_DEFENSE); MOVE(player, move); }
        else
            TURN { MOVE(opponent, MOVE_AMNESIA); MOVE(player, move); }
    } SCENE {
        if (gMovesInfo[move].category == DAMAGE_CATEGORY_PHYSICAL)
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
    u32 ability, move;

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
