#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_SMELLING_SALTS, MOVE_EFFECT_REMOVE_STATUS) == TRUE);
    ASSUME(gMovesInfo[MOVE_SMELLING_SALTS].argument == STATUS1_PARALYSIS);
}

SINGLE_BATTLE_TEST("Smelling Salts does not cure paralyzed pokemons behind substitutes or get increased power")
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }
    GIVEN {
        PLAYER(SPECIES_CROBAT) { Ability(ability); }
        OPPONENT(SPECIES_SEISMITOAD) { Status1(STATUS1_PARALYSIS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SMELLING_SALTS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMELLING_SALTS, player);
        if (ability == ABILITY_INNER_FOCUS)
        {
            MESSAGE("The SUBSTITUTE took damage for Foe Seismitoad!");
            NONE_OF
            {
                MESSAGE("Foe Seismitoad's SUBSTITUTE faded!"); // Smelling Salts does 86 damage, the sub has 122 HP, if hitting a sub it shouldn't get boosted damage.
                MESSAGE("Foe Seismitoad was healed of paralysis!");
                STATUS_ICON(opponent, none: TRUE);
            }
        }
        else
        {
            MESSAGE("Foe Seismitoad was healed of paralysis!");
            STATUS_ICON(opponent, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Smelling Salts get incread power vs. paralyzed targets")
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { status1 = STATUS1_NONE; }
    GIVEN {
        PLAYER(SPECIES_CROBAT);
        OPPONENT(SPECIES_LOTAD) { Status1(status1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SMELLING_SALTS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMELLING_SALTS, player);
        if (status1 == STATUS1_PARALYSIS)
        {
            MESSAGE("Foe Lotad fainted!");
        }
        else
        {
            NOT MESSAGE("Foe Lotad fainted!");
            MESSAGE("Foe Lotad used Celebrate!");
        }
    }
}
