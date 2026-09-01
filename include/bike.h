#ifndef GUARD_BIKE_H
#define GUARD_BIKE_H

// the struct below is used for checking button combinations of the last input so that the acro can potentially perform a side/turn jump.
// its possible that at some point Game Freak intended for the acro bike to have more complex tricks: but only the acro jump combinations can be seen in the final ROM.
struct BikeHistoryInputInfo
{
    u32 dirHistoryMatch; // the direction you need to press
    u32 abStartSelectHistoryMatch; // the button you need to press
    u32 dirHistoryMask; // mask applied so that way only the recent nybble (the recent input) is checked
    u32 abStartSelectHistoryMask; // mask applied so that way only the recent nybble (the recent input) is checked
    const u8 *dirTimerHistoryList; // list of timers to check for direction before the button+dir combination can be verified.
    const u8 *abStartSelectHistoryList; // list of timers to check for buttons before the button+dir combination can be verified.
    u32 direction; // direction to jump
};

// Player speeds
enum PlayerSpeed
{
    PLAYER_SPEED_STANDING,
    PLAYER_SPEED_NORMAL,
    PLAYER_SPEED_FAST,
    PLAYER_SPEED_FASTER,
    PLAYER_SPEED_FASTEST,
};

enum {
    BIKE_TRANS_FACE_DIRECTION,
    BIKE_TRANS_TURNING,
    BIKE_TRANS_MOVE,
    BIKE_TRANS_DOWNHILL,
    BIKE_TRANS_UPHILL
};

enum {
    BIKE_STATE_NORMAL,
    BIKE_STATE_TURNING,
    BIKE_STATE_SLOPE
};

// mach bike transitions enum
enum MachTransition
{
    MACH_TRANS_FACE_DIRECTION,
    MACH_TRANS_TURN_DIRECTION,
    MACH_TRANS_KEEP_MOVING,
    MACH_TRANS_START_MOVING
};

// Acro bike states
enum AcroState
{
    ACRO_STATE_NORMAL,
    ACRO_STATE_TURNING,
    ACRO_STATE_WHEELIE_STANDING,
    ACRO_STATE_BUNNY_HOP,
    ACRO_STATE_WHEELIE_MOVING,
    ACRO_STATE_SIDE_JUMP,
    ACRO_STATE_TURN_JUMP,
    ACRO_STATE_SLOPE
};

// Acro bike transitions
enum AcroTransition
{
    ACRO_TRANS_FACE_DIRECTION,
    ACRO_TRANS_TURN_DIRECTION,
    ACRO_TRANS_MOVING,
    ACRO_TRANS_NORMAL_TO_WHEELIE,
    ACRO_TRANS_WHEELIE_TO_NORMAL,
    ACRO_TRANS_WHEELIE_IDLE,
    ACRO_TRANS_WHEELIE_HOPPING_STANDING,
    ACRO_TRANS_WHEELIE_HOPPING_MOVING,
    ACRO_TRANS_SIDE_JUMP,
    ACRO_TRANS_TURN_JUMP,
    ACRO_TRANS_WHEELIE_MOVING,
    ACRO_TRANS_WHEELIE_RISING_MOVING,
    ACRO_TRANS_WHEELIE_LOWERING_MOVING,
    ACRO_TRANS_DOWNHILL,
    ACRO_TRANS_UPHILL
};

// Exported RAM declarations
extern bool8 gUnusedBikeCameraAheadPanback;

// Exported ROM declarations
void MovePlayerOnBike(enum Direction direction, u16 newKeys, u16 heldKeys);
void Bike_TryAcroBikeHistoryUpdate(u16 newKeys, u16 heldKeys);
bool8 IsBikingDisallowedByPlayer(void);
bool8 IsPlayerNotUsingAcroBikeOnBumpySlope(void);
void GetOnOffBike(u8 transitionFlags);
void BikeClearState(int newDirHistory, int newAbStartHistory);
void Bike_UpdateBikeCounterSpeed(u8 counter);
enum PlayerSpeed GetPlayerSpeed(void);
void Bike_HandleBumpySlopeJump(void);
bool32 IsRunningDisallowed(u8 metatile);

#endif // GUARD_BIKE_H
