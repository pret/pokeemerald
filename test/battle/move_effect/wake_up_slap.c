#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_WAKE_UP_SLAP].additionalEffects->moveEffect == MOVE_EFFECT_REMOVE_STATUS);
    ASSUME(gMovesInfo[MOVE_WAKE_UP_SLAP].argument == STATUS1_SLEEP);
}

SINGLE_BATTLE_TEST("Wake-Up Slap does not cure paralyzed pokemons behind substitutes or get increased power")
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }
    GIVEN {
        PLAYER(SPECIES_CROBAT) { Ability(ability); }
        OPPONENT(SPECIES_SEISMITOAD);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SING); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_WAKE_UP_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WAKE_UP_SLAP, player);
        if (ability == ABILITY_INNER_FOCUS) {
            MESSAGE("The SUBSTITUTE took damage for Foe Seismitoad!");
            NONE_OF
            {
                MESSAGE("Foe Seismitoad's SUBSTITUTE faded!"); // Smelling Salts does 86 damage, the sub has 122 HP, if hitting a sub it shouldn't get boosted damage.
                MESSAGE("Foe Seismitoad woke up!");
                STATUS_ICON(opponent, none: TRUE);
            }
        } else {
            MESSAGE("Foe Seismitoad woke up!");
            STATUS_ICON(opponent, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Wake-Up Slap get incread power vs. sleeping targets")
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_SLEEP; }
    PARAMETRIZE { status1 = STATUS1_NONE; }
    GIVEN {
        PLAYER(SPECIES_CROBAT);
        OPPONENT(SPECIES_LOTAD) { Status1(status1); }
    } WHEN {
        TURN { MOVE(player, MOVE_WAKE_UP_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WAKE_UP_SLAP, player);
        if (status1 == STATUS1_SLEEP) {
            MESSAGE("Foe Lotad fainted!");
        } else {
            NOT MESSAGE("Foe Lotad fainted!");
            MESSAGE("Foe Lotad used Celebrate!");
        }
    }
}
