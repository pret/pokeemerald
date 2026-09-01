#include "global.h"
#include "event_data.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("SetStartingStatus starts a chosen terrain at the beginning of battle and lasts infinitely long if it's defined as such")
{
    u16 terrain;

    PARAMETRIZE { terrain = STARTING_STATUS_GRASSY_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_PSYCHIC_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_MISTY_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_ELECTRIC_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY; }

    SetStartingStatus(terrain);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        switch (terrain)
        {
        case STARTING_STATUS_GRASSY_TERRAIN:
            MESSAGE("The battlefield is covered with grass!");
            break;
        case STARTING_STATUS_PSYCHIC_TERRAIN:
            MESSAGE("The battlefield seems weird!");
            break;
        case STARTING_STATUS_MISTY_TERRAIN:
            MESSAGE("Mist swirls around the battlefield!");
            break;
        case STARTING_STATUS_ELECTRIC_TERRAIN:
            MESSAGE("An electric current is running across the battlefield!");
            break;
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        if (terrain != STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
                MESSAGE("The weirdness disappeared from the battlefield!");
                MESSAGE("The electricity disappeared from the battlefield.");
                MESSAGE("The mist disappeared from the battlefield.");
                MESSAGE("The grass disappeared from the battlefield.");
            }
        } else {
            MESSAGE("The electricity disappeared from the battlefield.");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        }
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Terrain started after the one which started the battle lasts only 5 turns")
{
    bool32 viaMove;

    PARAMETRIZE { viaMove = TRUE; }
    PARAMETRIZE { viaMove = FALSE; }

    SetStartingStatus(STARTING_STATUS_ELECTRIC_TERRAIN);

    GIVEN {
        PLAYER(SPECIES_TAPU_BULU) { Ability(viaMove == TRUE ? ABILITY_TELEPATHY : ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN { MOVE(player, viaMove == TRUE ? MOVE_GRASSY_TERRAIN : MOVE_CELEBRATE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        // Electric Terrain at battle's start
        MESSAGE("An electric current is running across the battlefield!");
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
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Tapu Bulu used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Tapu Bulu used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("The grass disappeared from the battlefield.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
    } THEN {
        ResetStartingStatuses();
    }
}
