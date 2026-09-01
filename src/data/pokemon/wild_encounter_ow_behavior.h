#ifndef GUARD_WILD_ENCOUNTER_OW_SPECIES_BEHAVIOR_H
#define GUARD_WILD_ENCOUNTER_OW_SPECIES_BEHAVIOR_H

#include "wild_encounter_ow.h"
#include "constants/event_object_movement.h"

const struct BehaviorOWE gOWESpeciesBehavior[OWE_SPECIES_BEHAVIOR_COUNT] =
{
    [OWE_IGNORE_PLAYER] =
    {
        .movementType = MOVEMENT_TYPE_WANDER_AROUND_OWE,
        .viewDistance = 4,
        .viewWidth = 3,
        .activeDistance = 5,
        .idleSpeed = OWE_SPEED_NORMAL,
        .activeSpeed = OWE_SPEED_SLOW,
        .returnToIdle = PLAYER_OUTSIDE_ACTIVE_RANGE,
    },

    [OWE_CHASE_PLAYER_SLOW] =
    {
        .movementType = MOVEMENT_TYPE_CHASE_PLAYER_OWE,
        .viewDistance = 4,
        .viewWidth = 3,
        .activeDistance = 5,
        .idleSpeed = OWE_SPEED_SLOW,
        .activeSpeed = OWE_SPEED_SLOW,
        .returnToIdle = PLAYER_OUTSIDE_ACTIVE_RANGE,
    },

    [OWE_FLEE_PLAYER_NORMAL] =
    {
        .movementType = MOVEMENT_TYPE_FLEE_PLAYER_OWE,
        .viewDistance = 4,
        .viewWidth = 3,
        .activeDistance = 5,
        .idleSpeed = OWE_SPEED_NORMAL,
        .activeSpeed = OWE_SPEED_NORMAL,
        .returnToIdle = PLAYER_OUTSIDE_ACTIVE_RANGE,
    },

    [OWE_WATCH_PLAYER_NORMAL] =
    {
        .movementType = MOVEMENT_TYPE_WATCH_PLAYER_OWE,
        .viewDistance = 4,
        .viewWidth = 3,
        .activeDistance = 5,
        .idleSpeed = OWE_SPEED_NORMAL,
        .returnToIdle = PLAYER_OUTSIDE_ACTIVE_RANGE,
    },

    [OWE_APPROACH_PLAYER_SLOW] =
    {
        .movementType = MOVEMENT_TYPE_APPROACH_PLAYER_OWE,
        .viewDistance = 4,
        .viewWidth = 3,
        .activeDistance = 5,
        .idleSpeed = OWE_SPEED_NORMAL,
        .activeSpeed = OWE_SPEED_SLOW,
        .returnToIdle = PLAYER_OUTSIDE_ACTIVE_RANGE,
    },

    [OWE_DESPAWN_ON_NOTICE] =
    {
        .movementType = MOVEMENT_TYPE_DESPAWN_OWE,
        .viewDistance = 4,
        .viewWidth = 3,
        .activeDistance = 5,
        .idleSpeed = OWE_SPEED_NORMAL,
        .returnToIdle = PLAYER_OUTSIDE_ACTIVE_RANGE,
    }
};

#endif // GUARD_WILD_ENCOUNTER_OW_SPECIES_BEHAVIOR_H
