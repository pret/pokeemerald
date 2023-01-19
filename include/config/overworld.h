#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Movement config
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+, players are allowed to run indoors.

// Overworld flags
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define OW_FLAG_NO_ENCOUNTER        0  // If this flag is set, wild encounters will be disabled.
#define OW_FLAG_NO_TRAINER_SEE      0  // If this flag is set, trainers will not battle the player unless they're talked to.

#endif // GUARD_CONFIG_OVERWORLD_H
