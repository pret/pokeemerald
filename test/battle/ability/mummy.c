#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mummy/Lingering Aroma replace the attacker's ability on contact")
{
    enum Move move;
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { move = MOVE_AQUA_JET; ability = ABILITY_MUMMY; species = SPECIES_YAMASK; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_MUMMY; species = SPECIES_YAMASK; }
    PARAMETRIZE { move = MOVE_AQUA_JET; ability = ABILITY_LINGERING_AROMA; species = SPECIES_OINKOLOGNE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; ability = ABILITY_LINGERING_AROMA; species = SPECIES_OINKOLOGNE; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_AQUA_JET));
        ASSUME(!MoveMakesContact(MOVE_WATER_GUN));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (MoveMakesContact(move)) {
            ABILITY_POPUP(opponent, ability);
            if (ability == ABILITY_MUMMY)
                MESSAGE("Wobbuffet acquired Mummy!");
            else
                MESSAGE("Wobbuffet acquired Lingering Aroma!");
        } else {
            NONE_OF {
                ABILITY_POPUP(opponent, ability);
                if (ability == ABILITY_MUMMY)
                    MESSAGE("Wobbuffet acquired Mummy!");
                else
                    MESSAGE("Wobbuffet acquired Lingering Aroma!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Mummy and Lingering Aroma don't replace each other")
{
    enum Species species1, species2;
    enum Ability ability1, ability2; 

    PARAMETRIZE { ability1 = ability2 = ABILITY_MUMMY; species1 = species2 = SPECIES_YAMASK; }
    PARAMETRIZE { ability1 = ABILITY_MUMMY; species1 = SPECIES_YAMASK; ability2 = ABILITY_LINGERING_AROMA; species2 = SPECIES_OINKOLOGNE; }
    PARAMETRIZE { ability1 = ability2 = ABILITY_LINGERING_AROMA; species1 = species2 = SPECIES_OINKOLOGNE; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_AQUA_JET));
        PLAYER(species1) { Ability(ability1); Speed(2); }
        OPPONENT(species2) { Ability(ability2); Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_AQUA_JET); MOVE(opponent, MOVE_AQUA_JET); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_JET, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_JET, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ability1);
            ABILITY_POPUP(player, ability2);
            ABILITY_POPUP(opponent, ability1);
            ABILITY_POPUP(opponent, ability2);
            MESSAGE("Yamask acquired Mummy!");
            MESSAGE("Yamask acquired Lingering Aroma!");
            MESSAGE("Oinkologne acquired Mummy!");
            MESSAGE("Oinkologne acquired Lingering Aroma!");
        }
    }
}

SINGLE_BATTLE_TEST("Mummy doesn't replace abilities that can't be suppressed")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_ARCEUS; ability = ABILITY_MULTITYPE; }
    PARAMETRIZE { species = SPECIES_AEGISLASH; ability = ABILITY_STANCE_CHANGE; }
    PARAMETRIZE { species = SPECIES_MINIOR; ability = ABILITY_SHIELDS_DOWN; }
    PARAMETRIZE { species = SPECIES_WISHIWASHI; ability = ABILITY_SCHOOLING; }
    PARAMETRIZE { species = SPECIES_MIMIKYU; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_GRENINJA_BATTLE_BOND; ability = ABILITY_BATTLE_BOND; }
    PARAMETRIZE { species = SPECIES_ZYGARDE; ability = ABILITY_POWER_CONSTRUCT; }
    PARAMETRIZE { species = SPECIES_KOMALA; ability = ABILITY_COMATOSE; }
    PARAMETRIZE { species = SPECIES_SILVALLY; ability = ABILITY_RKS_SYSTEM; }
    PARAMETRIZE { species = SPECIES_CRAMORANT; ability = ABILITY_GULP_MISSILE; }
    PARAMETRIZE { species = SPECIES_EISCUE; ability = ABILITY_ICE_FACE; }
    PARAMETRIZE { species = SPECIES_CALYREX_ICE; ability = ABILITY_AS_ONE_ICE_RIDER; }
    PARAMETRIZE { species = SPECIES_CALYREX_SHADOW; ability = ABILITY_AS_ONE_SHADOW_RIDER; }
    PARAMETRIZE { species = SPECIES_PALAFIN_ZERO; ability = ABILITY_ZERO_TO_HERO; }

    GIVEN {
        PLAYER(SPECIES_YAMASK) { Ability(ABILITY_MUMMY); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_AQUA_JET); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AQUA_JET, opponent);
        NOT ABILITY_POPUP(player, ABILITY_MUMMY);
    } THEN {
        EXPECT(opponent->ability == ability);
    }
}
