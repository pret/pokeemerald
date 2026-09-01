#include "global.h"
#include "test/battle.h"

// TODO: Beat Up's strikes have each an independent chance of a critical hit
// Unconfirmed by Bulbapedia
// - Technician interacion

SINGLE_BATTLE_TEST("Beat Up hits the target for each non-fainted, non-statused member in the party")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_3; }
    PARAMETRIZE { gen = GEN_5; }

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, gen);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_PICHU)
        PLAYER(SPECIES_PIKACHU) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_RAICHU)
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        MESSAGE("The Pokémon was hit 4 times!");
    } THEN {
        if (gen == GEN_5) {
            EXPECT_EQ(gBattleStruct->beatUpSpecies[0], SPECIES_WOBBUFFET);
            EXPECT_EQ(gBattleStruct->beatUpSpecies[1], SPECIES_WYNAUT);
            EXPECT_EQ(gBattleStruct->beatUpSpecies[2], SPECIES_PICHU);
            EXPECT_EQ(gBattleStruct->beatUpSpecies[3], SPECIES_RAICHU);
        }
        else {
            EXPECT_EQ(gBattleStruct->beatUpSpecies[0], 0);
            EXPECT_EQ(gBattleStruct->beatUpSpecies[1], 1);
            EXPECT_EQ(gBattleStruct->beatUpSpecies[2], 2);
            EXPECT_EQ(gBattleStruct->beatUpSpecies[3], 4);
        }
    }
}

SINGLE_BATTLE_TEST("Beat Up doesn't consider Comatose as a status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_KOMALA) { Ability(ABILITY_COMATOSE); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        MESSAGE("The Pokémon was hit 2 times!");
    }
}

SINGLE_BATTLE_TEST("Beat Up doesn't list party member's name (Gen5+)")
{
    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        NONE_OF {
            MESSAGE("Wobbuffet's attack!");
            MESSAGE("Wynaut's attack!");
        }
        MESSAGE("The Pokémon was hit 2 times!");
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage is Dark-typed (Gen5+)", s16 damage)
{
    bool32 targetIsFairy;
    PARAMETRIZE { targetIsFairy = FALSE; }
    PARAMETRIZE { targetIsFairy = TRUE; }

    ASSUME(GetMoveType(MOVE_BEAT_UP) == TYPE_DARK);
    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(targetIsFairy ? SPECIES_SYLVEON : SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (targetIsFairy)
            EXPECT_LT(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up's base power is determined by each striking Pokémon (Gen5+)")
{
    s16 firstHit, secondHit;

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_5);
        PLAYER(SPECIES_SHUCKLE);
        PLAYER(SPECIES_DEOXYS_ATTACK);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_BLISSEY);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &secondHit);
    } THEN {
        EXPECT_LT(firstHit, secondHit);
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage considers stat stage changes (Gen5+)", s16 damage)
{
    bool32 boosted;
    PARAMETRIZE { boosted = FALSE; }
    PARAMETRIZE { boosted = TRUE; }

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_5);
        PLAYER(SPECIES_UMBREON);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { if (boosted) { MOVE(player, MOVE_SWORDS_DANCE); } else { MOVE(player, MOVE_CELEBRATE); } }
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        if (boosted)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (boosted)
            EXPECT_GT(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage considers Huge Power and Choice Band (Gen5+)", s16 damage)
{
    enum Ability ability;
    enum Item item;

    PARAMETRIZE { ability = ABILITY_THICK_FAT;   item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER;  item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_THICK_FAT;   item = ITEM_CHOICE_BAND; }

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_5);
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Item(item); Moves(MOVE_BEAT_UP); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (i == 1)
            EXPECT_GT(results[i].damage, results[0].damage);
        if (i == 2)
            EXPECT_GT(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up lists each party member's name")
{
    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_3);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        MESSAGE("Wobbuffet's attack!");
        MESSAGE("Wynaut's attack!");
        NOT MESSAGE("Wynaut's attack!");
        MESSAGE("Pikachu's attack!");
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage is typeless (up to Gen4)", s16 damage)
{
    enum Species defender = SPECIES_WOBBUFFET;
    enum Type type1, type2;

    PARAMETRIZE { defender = SPECIES_BLISSEY; }   // Normal
    PARAMETRIZE { defender = SPECIES_MACHAMP; }     // Fighting
    PARAMETRIZE { defender = SPECIES_TORNADUS; }    // Flying
    PARAMETRIZE { defender = SPECIES_GRIMER; }      // Poison
    PARAMETRIZE { defender = SPECIES_SANDSHREW; }   // Ground
    PARAMETRIZE { defender = SPECIES_NOSEPASS; }    // Rock
    PARAMETRIZE { defender = SPECIES_CATERPIE; }    // Bug
    PARAMETRIZE { defender = SPECIES_DUSKULL; }     // Ghost
    PARAMETRIZE { defender = SPECIES_REGISTEEL; }   // Steel
    PARAMETRIZE { defender = SPECIES_CHIMCHAR; }    // Fire
    PARAMETRIZE { defender = SPECIES_WARTORTLE; }   // Water
    PARAMETRIZE { defender = SPECIES_TANGELA; }     // Grass
    PARAMETRIZE { defender = SPECIES_PIKACHU; }     // Electric
    PARAMETRIZE { defender = SPECIES_ABRA; }        // Psychic
    PARAMETRIZE { defender = SPECIES_SNORUNT; }     // Ice
    PARAMETRIZE { defender = SPECIES_BAGON; }       // Dragon
    PARAMETRIZE { defender = SPECIES_UMBREON; }     // Dark
    PARAMETRIZE { defender = SPECIES_SYLVEON; }     // Fairy

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_4);
        type1 = GetSpeciesType(defender, 0);
        type2 = GetSpeciesType(defender, 1);
        ASSUME(type2 == type1 || type2 == TYPE_MYSTERY); // Ensure monotype targets
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(defender);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        EFFECTIVENESS_SE(opponent, SE_EFFECTIVE);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        EXPECT_GT(results[i].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage doesn't consider STAB")
{
    s16 damage;
    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_3);
        damage = 0;
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        // Raw damage: baseAtk 33 * basePower 1 * levelFactor ((100 * 2 / 5) + 2 = 42) = 1386
        // Divide by baseDef 58 -> 23 (floor); 23/50 + 2 = 2;
        u16 expected = 2;
        EXPECT_EQ(damage, expected);
    }
}

SINGLE_BATTLE_TEST("Beat Up's base power is the same for each strike")
{
    s16 firstHit, secondHit;
    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_3);
        firstHit = 0;
        secondHit = 0;
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &firstHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &secondHit);
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
    }
}

SINGLE_BATTLE_TEST("Beat Up's damage is determined by each striking Pokémon's base attack and level and the target's defense")
{
    s16 shuckleHit, deoxysHit;
    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_3);
        shuckleHit = 0;
        deoxysHit = 0;
        PLAYER(SPECIES_SHUCKLE);
        PLAYER(SPECIES_DEOXYS_ATTACK);
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_BLISSEY);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &shuckleHit);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &deoxysHit);
    } THEN {
        // Shuckle: baseAtk 10 * basePower 1 * levelFactor 42 = 420; / baseDef 10 -> 42; 42/50 + 2 = 2
        u16 shuckleDmg = 2;
        // Deoxys-A: baseAtk 180 * basePower 1 * levelFactor 42 = 7560; / baseDef 10 -> 756; 756/50 + 2 = 17
        u16 deoxysDmg = 17;
        EXPECT_EQ(shuckleHit, shuckleDmg);
        EXPECT_EQ(deoxysHit, deoxysDmg);
        EXPECT_LT(shuckleHit, deoxysHit);
    }
}

SINGLE_BATTLE_TEST("Beat Up ignores stat stage changes", s16 damage)
{
    bool32 boosted;
    PARAMETRIZE { boosted = FALSE; }
    PARAMETRIZE { boosted = TRUE; }

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_3);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { if (boosted) { MOVE(player, MOVE_SWORDS_DANCE); } else { MOVE(player, MOVE_CELEBRATE); } }
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        if (boosted)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (boosted)
            EXPECT_EQ(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up ignores Huge Power", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_THICK_FAT; }
    PARAMETRIZE { ability = ABILITY_HUGE_POWER; }

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_3);
        PLAYER(SPECIES_AZUMARILL) { Ability(ability); Moves(MOVE_BEAT_UP); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (ability == ABILITY_HUGE_POWER)
            EXPECT_EQ(results[i].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Beat Up ignores Choice Band", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }

    GIVEN {
        WITH_CONFIG(B_BEAT_UP, GEN_3);
        PLAYER(SPECIES_URSARING) { Item(item); Moves(MOVE_BEAT_UP); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BEAT_UP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BEAT_UP, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (item == ITEM_CHOICE_BAND)
            EXPECT_EQ(results[i].damage, results[0].damage);
    }
}
