#include "global.h"
#include "test/battle.h"

// IV combinations sourced from https://www.smogon.com/forums/threads/hidden-power-iv-combinations.78083/
SINGLE_BATTLE_TEST("Hidden Power's type is determined by IVs")
{
    u32 type, j, foeType, foeSpecies;
    u32 hp, atk, def, spAtk, spDef, speed;
    bool32 hidden;

    PARAMETRIZE { type = TYPE_NONE;     hidden = FALSE; }
    PARAMETRIZE { type = TYPE_NORMAL;   hidden = FALSE; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_PSYCHIC;   foeSpecies = SPECIES_WOBBUFFET; hp = 30; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_PSYCHIC;   foeSpecies = SPECIES_WOBBUFFET; hp = 31; atk = 15; def = 30; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_PSYCHIC;   foeSpecies = SPECIES_WOBBUFFET; hp = 30; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_PSYCHIC;   foeSpecies = SPECIES_WOBBUFFET; hp = 31; atk = 31; def = 30; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_REGISTEEL; hp = 31; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_REGISTEEL; hp = 31; atk = 15; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_REGISTEEL; hp = 31; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_REGISTEEL; hp = 31; atk = 31; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_POISON;    foeSpecies = SPECIES_ARBOK;     hp = 30; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_POISON;    foeSpecies = SPECIES_ARBOK;     hp = 31; atk = 15; def = 30; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_POISON;    foeSpecies = SPECIES_ARBOK;     hp = 30; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_POISON;    foeSpecies = SPECIES_ARBOK;     hp = 31; atk = 31; def = 30; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 31; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 31; atk = 15; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 31; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 31; atk = 31; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk =  2; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 15; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 22; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 31; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk =  2; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 15; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 22; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 31; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk =  2; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk = 15; def = 30; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk = 22; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk = 31; def = 30; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk =  2; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 15; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 22; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 31; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk =  2; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk = 15; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk = 22; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk = 31; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk =  2; def = 30; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk = 15; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk = 22; def = 30; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_WATER;     foeSpecies = SPECIES_BLASTOISE; hp = 31; atk = 31; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk =  2; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 15; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 22; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 31; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 31; atk =  2; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 30; atk = 15; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 31; atk = 22; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_GRASS;     foeSpecies = SPECIES_TANGELA;   hp = 30; atk = 31; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk =  2; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 15; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 31; atk = 22; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 31; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk =  2; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 15; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 22; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 31; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_MYSTERY;  hidden = FALSE; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk =  2; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 15; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 22; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_STEEL;     foeSpecies = SPECIES_KLINK;     hp = 30; atk = 31; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk =  3; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk = 15; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk = 23; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_DARK;      foeSpecies = SPECIES_UMBREON;   hp = 31; atk = 31; def = 31; spAtk = 31; spDef = 31; speed = 31; }

    // Any type after Dark shouldn't be part of Hidden Power officially.
    for (j = TYPE_DARK + 1; j < NUMBER_OF_MON_TYPES; j++) {
        PARAMETRIZE { type = j; hidden = FALSE; }
    }

    GIVEN {
        if (hidden) {
            ASSUME(gTypeEffectivenessTable[type][foeType] == UQ_4_12(0.5));                 // Foe's Type resists
            ASSUME(gSpeciesInfo[foeSpecies].types[0] == gSpeciesInfo[foeSpecies].types[1]); // Foe's pure type
            ASSUME(gSpeciesInfo[foeSpecies].types[0] == foeType);                           // Foe is the resisted type
            PLAYER(SPECIES_DUNSPARCE) { HPIV(hp); AttackIV(atk); DefenseIV(def); SpAttackIV(spAtk); SpDefenseIV(spDef); SpeedIV(speed); }
        } else {
            PLAYER(SPECIES_DUNSPARCE);
        }
        OPPONENT(foeSpecies);
    } WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER); }
    } SCENE {
        // Only test valid Hidden Power types
        if (hidden) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, player);
            HP_BAR(opponent);
            MESSAGE("It's not very effective…");
        }
    }
}

TO_DO_BATTLE_TEST("Hidden Power's power is determined by IVs before Gen6");
