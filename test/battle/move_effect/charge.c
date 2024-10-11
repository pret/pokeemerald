#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_THUNDERBOLT].power != 0);
    ASSUME(gMovesInfo[MOVE_THUNDERBOLT].type == TYPE_ELECTRIC);
}

SINGLE_BATTLE_TEST("Charge doubles the damage of the next Electric move of the user")
{
    s16 normalDamage = 0;
    s16 chargedUpDamage = 0;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &normalDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &chargedUpDamage);
    } THEN {
        EXPECT_MUL_EQ(normalDamage, Q_4_12(2.0), chargedUpDamage);
    }
}

SINGLE_BATTLE_TEST("Charge's effect is kept until the user uses an Electric move (Gen 9+)")
{
    s16 normalDamage = 0;
    s16 chargedUpDamage = 0;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &normalDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &chargedUpDamage);
    } THEN {
        EXPECT_MUL_EQ(normalDamage, Q_4_12(2.0), chargedUpDamage);
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
    u32 species, ability;
    s16 normalDamage = 0;
    s16 chargedUpDamage = 0;

    PARAMETRIZE { species = SPECIES_WATTREL; ability = ABILITY_WIND_POWER; }
    PARAMETRIZE { species = SPECIES_TADBULB; ability = ABILITY_ELECTROMORPHOSIS; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_AIR_CUTTER].windMove == TRUE);
        PLAYER(species) { Ability(ability);  }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); MOVE(opponent, MOVE_AIR_CUTTER); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &normalDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AIR_CUTTER, opponent);
        ABILITY_POPUP(player, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &chargedUpDamage);
    } THEN {
        EXPECT_MUL_EQ(normalDamage, Q_4_12(2.0), chargedUpDamage);
    }
}

SINGLE_BATTLE_TEST("Charge's effect is removed regardless if the next move is Electric or not (Gen 3-8)")
{
    s16 normalDamage = 0;
    s16 chargedUpDamage = 0;

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].type != TYPE_ELECTRIC);
        ASSUME(gMovesInfo[MOVE_TACKLE].power != 0);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
        TURN { MOVE(player, MOVE_CHARGE); }
        TURN { MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_THUNDERBOLT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &normalDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
        HP_BAR(opponent, captureDamage: &chargedUpDamage);
    } THEN {
        if (B_CHARGE < GEN_9)
            EXPECT_EQ(normalDamage, chargedUpDamage);
        else
            EXPECT_MUL_EQ(normalDamage, Q_4_12(2.0), chargedUpDamage);
    }
}

SINGLE_BATTLE_TEST("Charge will not expire if it flinches twice in a row")
{
    s16 normalDamage = 0;
    s16 chargedUpDamage = 0;

    GIVEN {
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
         HP_BAR(opponent, captureDamage: &normalDamage);
         ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARGE, player);
         ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDERBOLT, player);
         HP_BAR(opponent, captureDamage: &chargedUpDamage);
    } THEN {
        if (B_CHARGE < GEN_9)
            EXPECT_EQ(normalDamage, chargedUpDamage);
        else
            EXPECT_MUL_EQ(normalDamage, Q_4_12(2.0), chargedUpDamage);
    }
}
