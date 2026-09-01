#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Liquid Ooze causes Absorb users to lose HP instead of heal")
{
    s16 damage;
    s16 healed;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &healed);
        MESSAGE("Wobbuffet sucked up the liquid ooze!");
    } THEN {
        EXPECT_MUL_EQ(damage, Q_4_12(0.5), healed);
    }
}

SINGLE_BATTLE_TEST("Liquid Ooze causes Leech Seed users to lose HP instead of heal")
{
    s16 damage;
    s16 healed;

    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        HP_BAR(opponent, captureDamage: &damage);
        HP_BAR(player, captureDamage: &healed);
    } THEN {
        EXPECT_EQ(damage, healed);
    }
}

DOUBLE_BATTLE_TEST("Liquid Ooze causes Matcha Gatcha users to lose HP instead of heal")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MATCHA_GOTCHA, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MATCHA_GOTCHA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MATCHA_GOTCHA, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Wobbuffet sucked up the liquid ooze!");
        MESSAGE("Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Liquid Ooze will faint Matcha Gatcha users if it deals enough damage")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MATCHA_GOTCHA, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MATCHA_GOTCHA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MATCHA_GOTCHA, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(playerLeft);
        MESSAGE("Wobbuffet sucked up the liquid ooze!");
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Liquid Ooze causes Strength Sap users to lose HP instead of heal")
{
    s16 lostHp;
    s32 atkStat;

    PARAMETRIZE { atkStat = 100; }
    PARAMETRIZE { atkStat = 490; } // Checks that attacker can faint with no problems.

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACOOL) { Attack(atkStat); Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRENGTH_SAP); if (atkStat == 490) { SEND_OUT(player, 1); } }
    } SCENE {
        MESSAGE("Wobbuffet used Strength Sap!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRENGTH_SAP, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Tentacool's Attack fell!");
        ABILITY_POPUP(opponent, ABILITY_LIQUID_OOZE);
        HP_BAR(player, captureDamage: &lostHp);
        MESSAGE("Wobbuffet sucked up the liquid ooze!");
        if (atkStat >= 490) {
            MESSAGE("Wobbuffet fainted!");
            SEND_IN_MESSAGE("Wobbuffet");
        }
    } THEN {
        EXPECT_EQ(lostHp, atkStat);
    }
}

/* * https://bulbapedia.bulbagarden.net/wiki/Liquid_Ooze_(Ability)#In_battle:
   * If the recipient of Leech Seed's effect were to faint due to Liquid Ooze on the same turn as the victim of Leech Seed, then the victim faints before the recipient. This means that the victim's team loses the battle if both teams had their final Pokémon sent out.
 */
SINGLE_BATTLE_TEST("Liquid Ooze causes leech seed victim to faint before seeder")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_LIQUID_OOZE; }
    GIVEN {
        PLAYER(SPECIES_BULBASAUR)   { HP(1); }
        OPPONENT(SPECIES_TENTACOOL) { HP(1); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        // Player seeds opponent
        MESSAGE("Bulbasaur used Leech Seed!");
        // Drain at end of turn
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_LEECH_SEED_DRAIN, opponent);
        if (ability != ABILITY_LIQUID_OOZE) {
            MESSAGE("The opposing Tentacool fainted!");
            MESSAGE("The opposing Tentacool's health is sapped by Leech Seed!");
        } else {
            MESSAGE("The opposing Tentacool fainted!");
            ABILITY_POPUP(opponent, ABILITY_LIQUID_OOZE);
            MESSAGE("Bulbasaur sucked up the liquid ooze!");
            MESSAGE("Bulbasaur fainted!");
        }
    }
}

SINGLE_BATTLE_TEST("Liquid Ooze causes Dream Eater users to lose HP instead of heal (Gen 5+)")
{
    s16 damage;
    GIVEN {
        WITH_CONFIG(B_DREAM_EATER_LIQUID_OOZE, GEN_5);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_DREAM_EATER) == EFFECT_DREAM_EATER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACRUEL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_DREAM_EATER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DREAM_EATER, player);
        HP_BAR(opponent);
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_GT(damage, 0); // Positive damage
    }
}

SINGLE_BATTLE_TEST("Liquid Ooze does not cause Dream Eater users to lose HP instead of heal (Gen 3-4)")
{
    s16 damage;
    GIVEN {
        WITH_CONFIG(B_DREAM_EATER_LIQUID_OOZE, GEN_3);
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_DREAM_EATER) == EFFECT_DREAM_EATER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACRUEL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_DREAM_EATER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DREAM_EATER, player);
        HP_BAR(opponent);
        HP_BAR(player, captureDamage: &damage);
    } THEN {
        EXPECT_LT(damage, 0); // Negative damage = Heal
    }
}

SINGLE_BATTLE_TEST("Liquid Ooze HP loss from Absorb is blocked by Magic Guard")
{
    GIVEN {
        PLAYER(SPECIES_CLEFFA) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(opponent);
        NONE_OF {
            HP_BAR(player);
            MESSAGE("Wobbuffet sucked up the liquid ooze!");
        }
    }
}

SINGLE_BATTLE_TEST("Liquid Ooze HP loss from Leech Seed is blocked by Magic Guard")
{
    GIVEN {
        PLAYER(SPECIES_CLEFFA) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}
