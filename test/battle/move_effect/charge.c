#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_THUNDERBOLT) != DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
}

SINGLE_BATTLE_TEST("Charge doubles the damage of the next Electric move of the user")
{
    s16 damage[2] = {0};
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Charge's effect is kept until the user uses an Electric move (Gen 9+)")
{
    s16 damage[2] = {0};
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Charge's effect is removed if the user fails using an Electric move (Gen 9+)")
{
    s16 damage[2];
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER); }
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_THUNDER, hit: FALSE); }
        TURN { MOVE(player, MOVE_THUNDER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Charge's effect does not stack with Electromorphosis or Wind Power")
{
    enum Species species;
    enum Ability ability;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_WATTREL; ability = ABILITY_WIND_POWER; }
    PARAMETRIZE { species = SPECIES_TADBULB; ability = ABILITY_ELECTROMORPHOSIS; }

    GIVEN {
        ASSUME(IsWindMove(MOVE_AIR_CUTTER));
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); MOVE(opponent, MOVE_AIR_CUTTER, WITH_RNG(RNG_PARALYSIS, FALSE)); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AIR_CUTTER, opponent);
        ABILITY_POPUP(player, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Charge's effect is removed regardless if the next move is Electric or not (Gen 3-8)")
{
    s16 damage[2];
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_ELECTRIC);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        if (B_CHARGE < GEN_9)
            EXPECT_EQ(damage[0], damage[1]);
        else
            EXPECT_MUL_EQ(damage[0], Q_4_12(2.0), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Charge will expire if user flinches while using an electric move")
{
    s16 damage[2];
    GIVEN {
         ASSUME(GetMoveAdditionalEffectById(MOVE_IRON_HEAD, 0)->moveEffect == MOVE_EFFECT_FLINCH);
         PLAYER(SPECIES_WOBBUFFET);
         OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
    } WHEN {
         TURN { MOVE(player, MOVE_THUNDERBOLT); }
         TURN { MOVE(player, MOVE_CHARGE); }
         TURN { MOVE(opponent, MOVE_IRON_HEAD); MOVE(player, MOVE_THUNDERBOLT); }
         TURN { MOVE(opponent, MOVE_IRON_HEAD); MOVE(player, MOVE_THUNDERBOLT); }
         TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
         ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
         HP_BAR(opponent, captureDamage: &damage[0]);
         ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
         ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
         HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Charge does not apply its damage boost to Electro Shot on its second turn charge")
{
    s16 dmgBefore, dmgAfter;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_ELECTRO_SHOT); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_HAZE); }
        TURN { MOVE(player, MOVE_CHARGE); MOVE(opponent, MOVE_RAIN_DANCE); }
        TURN { MOVE(player, MOVE_ELECTRO_SHOT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, player);
        HP_BAR(opponent, captureDamage: &dmgBefore);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRO_SHOT, player);
        HP_BAR(opponent, captureDamage: &dmgAfter);
    } THEN {
        EXPECT_MUL_EQ(dmgBefore, Q_4_12(2.0), dmgAfter);
    }
}
