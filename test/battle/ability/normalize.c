#include "global.h"
#include "test/battle.h"
#include "berry.h"

ASSUMPTIONS
{
    ASSUME(GetMoveType(MOVE_TACKLE) == TYPE_NORMAL);
    ASSUME(GetMovePower(MOVE_TACKLE) > 0);
    ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
    ASSUME(GetMovePower(MOVE_WATER_GUN) > 0);
}

SINGLE_BATTLE_TEST("Normalize turns a move into a Normal-type move")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_GASTLY, 0) == TYPE_GHOST);
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_SKITTY) { Ability(ability); Moves(MOVE_WATER_GUN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        if (ability == ABILITY_CUTE_CHARM)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
            NOT { MESSAGE("It doesn't affect Gastly…"); }
        }
        else
        {
            NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent); }
            MESSAGE("It doesn't affect Gastly…");
        }
    }
}

#define FAILURE_MESSAGE MESSAGE("It doesn't affect Drilbur…")
SINGLE_BATTLE_TEST("Normalize affects status moves")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_WAVE) == TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_DRILBUR, 0) == TYPE_GROUND);
        PLAYER(SPECIES_DRILBUR);
        OPPONENT(SPECIES_SKITTY) { Ability(ability); Moves(MOVE_THUNDER_WAVE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_WAVE); }
    } SCENE {
        if (ability == ABILITY_CUTE_CHARM)
        {
            NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, opponent); }
            FAILURE_MESSAGE;
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, opponent);
            NOT FAILURE_MESSAGE;
        }
    }
}
#undef FAILURE_MESSAGE

SINGLE_BATTLE_TEST("Normalize still makes Freeze-Dry do super effective damage to Water-type Pokémon", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_FREEZE_DRY) == TYPE_ICE);
        ASSUME(GetMoveEffect(MOVE_FREEZE_DRY) == EFFECT_SUPER_EFFECTIVE_ON_ARG);
        ASSUME(GetSpeciesType(SPECIES_MUDKIP, 0) == TYPE_WATER);
        PLAYER(SPECIES_MUDKIP);
        OPPONENT(SPECIES_SKITTY) { Ability(ability); Moves(MOVE_FREEZE_DRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FREEZE_DRY); }
    } SCENE {
        MESSAGE("It's super effective!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.8), results[1].damage); // STAB + Ate
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't boost power of unaffected moves by 20% (< Gen7)", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, GEN_6);
        PLAYER(SPECIES_DELCATTY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage); // No boost
    }
}

SINGLE_BATTLE_TEST("Normalize boosts power of unaffected moves by 20% (Gen7+)", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, GEN_7);
        PLAYER(SPECIES_DELCATTY) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POUND); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.2), results[1].damage); // Ate
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't boost power of affected moves by 20% (< Gen7)", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, GEN_6);
        PLAYER(SPECIES_SKITTY) { Ability(ability); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage); // STAB + no ate
    }
}

SINGLE_BATTLE_TEST("Normalize boosts power of affected moves by 20% (Gen7+)", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }

    GIVEN {
        WITH_CONFIG(B_ATE_MULTIPLIER, GEN_7);
        PLAYER(SPECIES_SKITTY) { Ability(ability); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.8), results[1].damage); // STAB + ate
    }
}

SINGLE_BATTLE_TEST("Normalize-affected moves become Electric-type under Electrify's effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ELECTRIFY) == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); }
        OPPONENT(SPECIES_ROOKIDEE) { Item(ITEM_WACAN_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIFY); MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    }
}

SINGLE_BATTLE_TEST("Normalize-affected moves become Electric-type under Ion Deluge's effect")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ION_DELUGE) == EFFECT_ION_DELUGE);
        PLAYER(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ROOKIDEE) { Item(ITEM_WACAN_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ION_DELUGE); MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't affect Weather Ball's type", s16 damage)
{
    enum Move move;
    enum Ability ability;
    PARAMETRIZE { move = MOVE_CELEBRATE; ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { move = MOVE_CELEBRATE; ability = ABILITY_NORMALIZE; }
    PARAMETRIZE { move = MOVE_SUNNY_DAY; ability = ABILITY_NORMALIZE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        ASSUME(GetMoveType(MOVE_WEATHER_BALL) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_MEGANIUM, 0) == TYPE_GRASS);
        PLAYER(SPECIES_SKITTY) { Ability(ability); }
        OPPONENT(SPECIES_MEGANIUM);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
        if (move == MOVE_SUNNY_DAY)
            MESSAGE("It's super effective!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4.0), results[1].damage); // double base power + type effectiveness + sun 50% boost - STAB
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(4.0), results[3].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
        EXPECT_EQ(results[1].damage, results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't affect Natural Gift's type")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        ASSUME(gBerries[ItemIdToBerryType(ITEM_ORAN_BERRY)].naturalGiftType == TYPE_POISON);
        ASSUME(GetSpeciesType(SPECIES_BELDUM, 0) == TYPE_STEEL);
        PLAYER(SPECIES_SKITTY) { Ability(ability); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_BELDUM);
    } WHEN {
        TURN { MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player); }
        MESSAGE("It doesn't affect the opposing Beldum…");
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't affect Judgment / Techno Blast / Multi-Attack's type")
{
    enum Move move;
    enum Item item;
    PARAMETRIZE { move = MOVE_JUDGMENT; item = ITEM_ZAP_PLATE; }
    PARAMETRIZE { move = MOVE_TECHNO_BLAST; item = ITEM_SHOCK_DRIVE; }
    PARAMETRIZE { move = MOVE_MULTI_ATTACK; item = ITEM_ELECTRIC_MEMORY; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_JUDGMENT) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(GetMoveEffect(MOVE_TECHNO_BLAST) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(GetMoveEffect(MOVE_MULTI_ATTACK) == EFFECT_CHANGE_TYPE_ON_ITEM);
        ASSUME(gItemsInfo[ITEM_ZAP_PLATE].holdEffect == HOLD_EFFECT_PLATE);
        ASSUME(gItemsInfo[ITEM_ZAP_PLATE].secondaryId == TYPE_ELECTRIC);
        ASSUME(gItemsInfo[ITEM_SHOCK_DRIVE].holdEffect == HOLD_EFFECT_DRIVE);
        ASSUME(gItemsInfo[ITEM_SHOCK_DRIVE].secondaryId == TYPE_ELECTRIC);
        ASSUME(gItemsInfo[ITEM_ELECTRIC_MEMORY].holdEffect == HOLD_EFFECT_MEMORY);
        ASSUME(gItemsInfo[ITEM_ELECTRIC_MEMORY].secondaryId == TYPE_ELECTRIC);
        ASSUME(GetSpeciesType(SPECIES_DIGLETT, 0) == TYPE_GROUND);
        PLAYER(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); Item(item); }
        OPPONENT(SPECIES_DIGLETT);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NOT { ANIMATION(ANIM_TYPE_MOVE, move, player); }
        MESSAGE("It doesn't affect the opposing Diglett…");
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't affect Hidden Power's type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER) == EFFECT_HIDDEN_POWER);
        ASSUME(gTypesInfo[TYPE_ELECTRIC].isHiddenPowerType == TRUE);
        ASSUME(GetSpeciesType(SPECIES_DIGLETT, 0) == TYPE_GROUND);
        PLAYER(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); HPIV(31); AttackIV(31); DefenseIV(31); SpAttackIV(30); SpDefenseIV(31); SpeedIV(31); } // HP Electric
        OPPONENT(SPECIES_DIGLETT);
    } WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER); }
    } SCENE {
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, player); }
        MESSAGE("It doesn't affect the opposing Diglett…");
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't change Tera Blast's type when Terastallized")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERA_BLAST) == EFFECT_TERA_BLAST);
        ASSUME(GetMoveType(MOVE_TERA_BLAST) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_MISDREAVUS, 0) == TYPE_GHOST);
        PLAYER(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); TeraType(TYPE_DARK); }
        OPPONENT(SPECIES_MISDREAVUS);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("Normalize makes Flying Press do Normal/Flying damage")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_CUTE_CHARM; }
    PARAMETRIZE { ability = ABILITY_NORMALIZE; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 0) == TYPE_ROCK || GetSpeciesType(SPECIES_GOLEM, 1) == TYPE_ROCK);
        PLAYER(SPECIES_SKITTY) { Ability(ability); Moves(MOVE_FLYING_PRESS); }
        OPPONENT(SPECIES_GOLEM);
    } WHEN {
        TURN { MOVE(player, MOVE_FLYING_PRESS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLYING_PRESS, player);
        if (ability == ABILITY_NORMALIZE)
            MESSAGE("It's mostly ineffective…");
        else
            NOT { MESSAGE("It's mostly ineffective…"); }
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't affect Terrain Pulse's type")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TERRAIN_PULSE) == EFFECT_TERRAIN_PULSE);
        ASSUME(GetMoveType(MOVE_TERRAIN_PULSE) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SANDSHREW, 0) == TYPE_GROUND || GetSpeciesType(SPECIES_SANDSHREW, 1) == TYPE_GROUND);
        PLAYER(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); }
        OPPONENT(SPECIES_SANDSHREW);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TERRAIN_PULSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_TERRAIN_PULSE, player); }
        MESSAGE("It doesn't affect the opposing Sandshrew…");
    }
}

SINGLE_BATTLE_TEST("Normalize doesn't affect damaging Z-Move types")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 0) == TYPE_ROCK || GetSpeciesType(SPECIES_GOLEM, 1) == TYPE_ROCK);
        PLAYER(SPECIES_SKITTY) { Ability(ABILITY_NORMALIZE); Item(ITEM_WATERIUM_Z); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_GOLEM);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYDRO_VORTEX, player);
        MESSAGE("It's extremely effective!");
    }
}
