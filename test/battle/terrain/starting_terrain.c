#include "global.h"
#include "event_data.h"
#include "test/battle.h"

#if B_VAR_STARTING_STATUS != 0

SINGLE_BATTLE_TEST("B_VAR_STARTING_STATUS starts a chosen terrain at the beginning of battle and lasts infinitely long")
{
    u16 terrain;

    PARAMETRIZE { terrain = STARTING_STATUS_GRASSY_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_PSYCHIC_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_MISTY_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_ELECTRIC_TERRAIN; }

    VarSet(B_VAR_STARTING_STATUS, terrain);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN { ; }
        TURN { ; }
        TURN { ; }
        TURN { ; }
        TURN { ; }
        TURN { ; }
        TURN { ; }
    } SCENE {
        switch (terrain) {
            case STARTING_STATUS_GRASSY_TERRAIN:
                MESSAGE("Grass grew to cover the battlefield!");
                break;
            case STARTING_STATUS_PSYCHIC_TERRAIN:
                MESSAGE("The battlefield got weird!");
                break;
            case STARTING_STATUS_MISTY_TERRAIN:
                MESSAGE("Mist swirled about the battlefield!");
                break;
            case STARTING_STATUS_ELECTRIC_TERRAIN:
                MESSAGE("An electric current runs across the battlefield!");
                break;
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
            MESSAGE("The weirdness disappeared from the battlefield.");
            MESSAGE("The electricity disappeared from the battlefield.");
            MESSAGE("The mist disappeared from the battlefield.");
            MESSAGE("The grass disappeared from the battlefield.");
        }
    } THEN {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

SINGLE_BATTLE_TEST("Terrain started after the one which started the battle lasts only 5 turns")
{
    bool32 viaMove;

    PARAMETRIZE { viaMove = TRUE; }
    PARAMETRIZE { viaMove = FALSE; }

    VarSet(B_VAR_STARTING_STATUS, STARTING_STATUS_ELECTRIC_TERRAIN);
    VarSet(B_VAR_STARTING_STATUS_TIMER, 0);

    GIVEN {
        PLAYER(SPECIES_TAPU_BULU) { Ability(viaMove == TRUE ? ABILITY_TELEPATHY : ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN { MOVE(player, viaMove == TRUE ? MOVE_GRASSY_TERRAIN : MOVE_CELEBRATE); }
        TURN { ; }
        TURN { ; }
        TURN { ; }
        TURN { ; }
        TURN { ; }
        TURN { ; }
    } SCENE {
        // Electric Terrain at battle's start
        MESSAGE("An electric current runs across the battlefield!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        // Player uses Grassy Terrain
        if (viaMove) {
            MESSAGE("Tapu Bulu used Grassy Terrain!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
            MESSAGE("Grass grew to cover the battlefield!");
        } else {
            ABILITY_POPUP(player, ABILITY_GRASSY_SURGE);
            MESSAGE("Grass grew to cover the battlefield!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        }

        // 5 turns
        MESSAGE("Tapu Bulu used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");

        MESSAGE("Tapu Bulu used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");

        MESSAGE("Tapu Bulu used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");

        MESSAGE("The grass disappeared from the battlefield.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
    } THEN {
        VarSet(B_VAR_STARTING_STATUS, 0);
    }
}

#endif // B_VAR_STARTING_STATUS
