u8 (*const gMovementTypeFuncs_WanderAround[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WanderAround_Step0,
    MovementType_WanderAround_Step1,
    MovementType_WanderAround_Step2,
    MovementType_Wander_Step3,
    MovementType_WanderAround_Step4,
    MovementType_WanderAround_Step5,
    MovementType_WanderAround_Step6,
};

u8 (*const gMovementTypeFuncs_WanderAroundSlower[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WanderAround_Step0,
    MovementType_WanderAround_Step1,
    MovementType_WanderAround_Step2,
    MovementType_Wander_Step3,
    MovementType_WanderAround_Step4,
    MovementType_WanderAround_Step5Slower,
    MovementType_WanderAround_Step6,
};

const enum Direction gStandardDirections[] = {DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST};

enum Direction (*const gGetVectorDirectionFuncs[])(s16, s16, s16, s16) = {
    GetVectorDirection,
    GetLimitedVectorDirection_SouthNorth,
    GetLimitedVectorDirection_WestEast,
    GetLimitedVectorDirection_WestNorth,
    GetLimitedVectorDirection_EastNorth,
    GetLimitedVectorDirection_WestSouth,
    GetLimitedVectorDirection_EastSouth,
    GetLimitedVectorDirection_SouthNorthWest,
    GetLimitedVectorDirection_SouthNorthEast,
    GetLimitedVectorDirection_NorthWestEast,
    GetLimitedVectorDirection_SouthWestEast,
};

u8 (*const gMovementTypeFuncs_LookAround[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_LookAround_Step0,
    MovementType_LookAround_Step1,
    MovementType_LookAround_Step2,
    MovementType_LookAround_Step3,
    MovementType_LookAround_Step4,
};

u8 (*const gMovementTypeFuncs_WanderUpAndDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WanderUpAndDown_Step0,
    MovementType_WanderUpAndDown_Step1,
    MovementType_WanderUpAndDown_Step2,
    MovementType_Wander_Step3,
    MovementType_WanderUpAndDown_Step4,
    MovementType_WanderUpAndDown_Step5,
    MovementType_WanderUpAndDown_Step6,
};

const enum Direction gUpAndDownDirections[] = {DIR_SOUTH, DIR_NORTH};

u8 (*const gMovementTypeFuncs_WanderLeftAndRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WanderLeftAndRight_Step0,
    MovementType_WanderLeftAndRight_Step1,
    MovementType_WanderLeftAndRight_Step2,
    MovementType_Wander_Step3,
    MovementType_WanderLeftAndRight_Step4,
    MovementType_WanderLeftAndRight_Step5,
    MovementType_WanderLeftAndRight_Step6,
};

const enum Direction gLeftAndRightDirections[] = {DIR_WEST, DIR_EAST};

u8 (*const gMovementTypeFuncs_FaceDirection[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceDirection_Step0,
    MovementType_FaceDirection_Step1,
    MovementType_FaceDirection_Step2,
};

u8 (*const gMovementTypeFuncs_BerryTreeGrowth[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_BerryTreeGrowth_Normal,
    MovementType_BerryTreeGrowth_Move,
    MovementType_BerryTreeGrowth_SparkleStart,
    MovementType_BerryTreeGrowth_Sparkle,
    MovementType_BerryTreeGrowth_SparkleEnd,
};

u8 (*const gMovementTypeFuncs_FaceDownAndUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceDownAndUp_Step0,
    MovementType_FaceDownAndUp_Step1,
    MovementType_FaceDownAndUp_Step2,
    MovementType_FaceDownAndUp_Step3,
    MovementType_FaceDownAndUp_Step4,
};

u8 (*const gMovementTypeFuncs_FaceLeftAndRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceLeftAndRight_Step0,
    MovementType_FaceLeftAndRight_Step1,
    MovementType_FaceLeftAndRight_Step2,
    MovementType_FaceLeftAndRight_Step3,
    MovementType_FaceLeftAndRight_Step4,
};

u8 (*const gMovementTypeFuncs_FaceUpAndLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceUpAndLeft_Step0,
    MovementType_FaceUpAndLeft_Step1,
    MovementType_FaceUpAndLeft_Step2,
    MovementType_FaceUpAndLeft_Step3,
    MovementType_FaceUpAndLeft_Step4,
};

const enum Direction gUpAndLeftDirections[] = {DIR_NORTH, DIR_WEST};

u8 (*const gMovementTypeFuncs_FaceUpAndRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceUpAndRight_Step0,
    MovementType_FaceUpAndRight_Step1,
    MovementType_FaceUpAndRight_Step2,
    MovementType_FaceUpAndRight_Step3,
    MovementType_FaceUpAndRight_Step4,
};

const enum Direction gUpAndRightDirections[] = {DIR_NORTH, DIR_EAST};

u8 (*const gMovementTypeFuncs_FaceDownAndLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceDownAndLeft_Step0,
    MovementType_FaceDownAndLeft_Step1,
    MovementType_FaceDownAndLeft_Step2,
    MovementType_FaceDownAndLeft_Step3,
    MovementType_FaceDownAndLeft_Step4,
};

const enum Direction gDownAndLeftDirections[] = {DIR_SOUTH, DIR_WEST};

u8 (*const gMovementTypeFuncs_FaceDownAndRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceDownAndRight_Step0,
    MovementType_FaceDownAndRight_Step1,
    MovementType_FaceDownAndRight_Step2,
    MovementType_FaceDownAndRight_Step3,
    MovementType_FaceDownAndRight_Step4,
};

const enum Direction gDownAndRightDirections[] = {DIR_SOUTH, DIR_EAST};

u8 (*const gMovementTypeFuncs_FaceDownUpAndLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceDownUpAndLeft_Step0,
    MovementType_FaceDownUpAndLeft_Step1,
    MovementType_FaceDownUpAndLeft_Step2,
    MovementType_FaceDownUpAndLeft_Step3,
    MovementType_FaceDownUpAndLeft_Step4,
};

const enum Direction gDownUpAndLeftDirections[] = {DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_FaceDownUpAndRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceDownUpAndRight_Step0,
    MovementType_FaceDownUpAndRight_Step1,
    MovementType_FaceDownUpAndRight_Step2,
    MovementType_FaceDownUpAndRight_Step3,
    MovementType_FaceDownUpAndRight_Step4,
};

const enum Direction gDownUpAndRightDirections[] = {DIR_SOUTH, DIR_NORTH, DIR_EAST, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_FaceUpLeftAndRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceUpLeftAndRight_Step0,
    MovementType_FaceUpLeftAndRight_Step1,
    MovementType_FaceUpLeftAndRight_Step2,
    MovementType_FaceUpLeftAndRight_Step3,
    MovementType_FaceUpLeftAndRight_Step4,
};

const enum Direction gUpLeftAndRightDirections[] = {DIR_NORTH, DIR_WEST, DIR_EAST, DIR_NORTH};

u8 (*const gMovementTypeFuncs_FaceDownLeftAndRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FaceDownLeftAndRight_Step0,
    MovementType_FaceDownLeftAndRight_Step1,
    MovementType_FaceDownLeftAndRight_Step2,
    MovementType_FaceDownLeftAndRight_Step3,
    MovementType_FaceDownLeftAndRight_Step4,
};

const enum Direction gDownLeftAndRightDirections[] = {DIR_WEST, DIR_EAST, DIR_SOUTH, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_RotateCounterclockwise[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_RotateCounterclockwise_Step0,
    MovementType_RotateCounterclockwise_Step1,
    MovementType_RotateCounterclockwise_Step2,
    MovementType_RotateCounterclockwise_Step3,
};

const enum Direction gCounterclockwiseDirections[] = {DIR_SOUTH, DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH};

u8 (*const gMovementTypeFuncs_RotateClockwise[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_RotateClockwise_Step0,
    MovementType_RotateClockwise_Step1,
    MovementType_RotateClockwise_Step2,
    MovementType_RotateClockwise_Step3,
};

const enum Direction gClockwiseDirections[] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_WalkBackAndForth[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkBackAndForth_Step0,
    MovementType_WalkBackAndForth_Step1,
    MovementType_WalkBackAndForth_Step2,
    MovementType_WalkBackAndForth_Step3,
};

u8 (*const gMovementTypeFuncs_WalkSequenceUpRightLeftDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpRightLeftDown_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gUpRightLeftDownDirections[] = {DIR_NORTH, DIR_EAST, DIR_WEST, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_WalkSequenceRightLeftDownUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightLeftDownUp_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gRightLeftDownUpDirections[] = {DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH};

u8 (*const gMovementTypeFuncs_WalkSequenceDownUpRightLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownUpRightLeft_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gDownUpRightLeftDirections[] = {DIR_SOUTH, DIR_NORTH, DIR_EAST, DIR_WEST};

u8 (*const gMovementTypeFuncs_WalkSequenceLeftDownUpRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftDownUpRight_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gLeftDownUpRightDirections[] = {DIR_WEST, DIR_SOUTH, DIR_NORTH, DIR_EAST};

u8 (*const gMovementTypeFuncs_WalkSequenceUpLeftRightDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpLeftRightDown_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gUpLeftRightDownDirections[] = {DIR_NORTH, DIR_WEST, DIR_EAST, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_WalkSequenceLeftRightDownUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftRightDownUp_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gLeftRightDownUpDirections[] = {DIR_WEST, DIR_EAST, DIR_SOUTH, DIR_NORTH};

u8 (*const gMovementTypeFuncs_WalkSequenceDownUpLeftRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownUpLeftRight_Step1,
    MovementType_WalkSequence_Step2,
};

u8 (*const gMovementTypeFuncs_WalkSequenceRightDownUpLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightDownUpLeft_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gRightDownUpLeftDirections[] = {DIR_EAST, DIR_SOUTH, DIR_NORTH, DIR_WEST};

u8 (*const gMovementTypeFuncs_WalkSequenceLeftUpDownRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftUpDownRight_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gLeftUpDownRightDirections[] = {DIR_WEST, DIR_NORTH, DIR_SOUTH, DIR_EAST};

u8 (*const gMovementTypeFuncs_WalkSequenceUpDownRightLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpDownRightLeft_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gUpDownRightLeftDirections[] = {DIR_NORTH, DIR_SOUTH, DIR_EAST, DIR_WEST};

u8 (*const gMovementTypeFuncs_WalkSequenceRightLeftUpDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightLeftUpDown_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gRightLeftUpDownDirections[] = {DIR_EAST, DIR_WEST, DIR_NORTH, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_WalkSequenceDownRightLeftUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownRightLeftUp_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gDownRightLeftUpDirections[] = {DIR_SOUTH, DIR_EAST, DIR_WEST, DIR_NORTH};

u8 (*const gMovementTypeFuncs_WalkSequenceRightUpDownLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightUpDownLeft_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gRightUpDownLeftDirections[] = {DIR_EAST, DIR_NORTH, DIR_SOUTH, DIR_WEST};

u8 (*const gMovementTypeFuncs_WalkSequenceUpDownLeftRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpDownLeftRight_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gUpDownLeftRightDirections[] = {DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_EAST};

u8 (*const gMovementTypeFuncs_WalkSequenceLeftRightUpDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftRightUpDown_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gLeftRightUpDownDirections[] = {DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_WalkSequenceDownLeftRightUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownLeftRightUp_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gDownLeftRightUpDirections[] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH};

u8 (*const gMovementTypeFuncs_WalkSequenceUpLeftDownRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpLeftDownRight_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gUpLeftDownRightDirections[] = {DIR_NORTH, DIR_WEST, DIR_SOUTH, DIR_EAST};

u8 (*const gMovementTypeFuncs_WalkSequenceDownRightUpLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownRightUpLeft_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gDownRightUpLeftDirections[] = {DIR_SOUTH, DIR_EAST, DIR_NORTH, DIR_WEST};

u8 (*const gMovementTypeFuncs_WalkSequenceLeftDownRightUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftDownRightUp_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gLeftDownRightUpDirections[] = {DIR_WEST, DIR_SOUTH, DIR_EAST, DIR_NORTH};

u8 (*const gMovementTypeFuncs_WalkSequenceRightUpLeftDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightUpLeftDown_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gRightUpLeftDownDirections[] = {DIR_EAST, DIR_NORTH, DIR_WEST, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_WalkSequenceUpRightDownLeft[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpRightDownLeft_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gUpRightDownLeftDirections[] = {DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST};

u8 (*const gMovementTypeFuncs_WalkSequenceDownLeftUpRight[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownLeftUpRight_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gDownLeftUpRightDirections[] = {DIR_SOUTH, DIR_WEST, DIR_NORTH, DIR_EAST};

u8 (*const gMovementTypeFuncs_WalkSequenceLeftUpRightDown[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftUpRightDown_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gLeftUpRightDownDirections[] = {DIR_WEST, DIR_NORTH, DIR_EAST, DIR_SOUTH};

u8 (*const gMovementTypeFuncs_WalkSequenceRightDownLeftUp[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightDownLeftUp_Step1,
    MovementType_WalkSequence_Step2,
};

const enum Direction gRightDownLeftUpDirections[] = {DIR_EAST, DIR_SOUTH, DIR_WEST, DIR_NORTH};

u8 (*const gMovementTypeFuncs_CopyPlayer[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_CopyPlayer_Step0,
    MovementType_CopyPlayer_Step1,
    MovementType_CopyPlayer_Step2,
};

bool8 (*const gCopyPlayerMovementFuncs[])(struct ObjectEvent *, struct Sprite *, enum Direction, bool8(u8)) = {
    [COPY_MOVE_NONE]                = CopyablePlayerMovement_None,
    [COPY_MOVE_FACE]                = CopyablePlayerMovement_FaceDirection,
    [COPY_MOVE_WALK]                = CopyablePlayerMovement_WalkNormal,
    [COPY_MOVE_WALK_FAST]           = CopyablePlayerMovement_WalkFast,
    [COPY_MOVE_WALK_FASTER]         = CopyablePlayerMovement_WalkFaster,
    [COPY_MOVE_SLIDE]               = CopyablePlayerMovement_Slide,
    [COPY_MOVE_JUMP_IN_PLACE]       = CopyablePlayerMovement_JumpInPlace,
    [COPY_MOVE_JUMP]                = CopyablePlayerMovement_Jump,
    [COPY_MOVE_JUMP2]               = CopyablePlayerMovement_Jump2,
    [COPY_MOVE_WALK_COLLIDE]        = CopyablePlayerMovement_WalkNormal,
    [COPY_MOVE_WALK_COLLIDE_SLOW]   = CopyablePlayerMovement_WalkSlow,
};

u8 (*const gMovementTypeFuncs_FollowPlayer[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_FollowPlayer_Shadow,
    MovementType_FollowPlayer_Active,
    MovementType_FollowPlayer_Moving,
};

bool8 (*const gFollowPlayerMovementFuncs[])(struct ObjectEvent *, struct Sprite *, enum Direction, bool8(u8)) = {
    [COPY_MOVE_NONE] = FollowablePlayerMovement_Idle,
    [COPY_MOVE_FACE] = FollowablePlayerMovement_Idle,
    [COPY_MOVE_WALK] = FollowablePlayerMovement_Step,
    [COPY_MOVE_WALK_FAST] = FollowablePlayerMovement_GoSpeed1,
    [COPY_MOVE_WALK_FASTER] = FollowablePlayerMovement_GoSpeed2,
    [COPY_MOVE_SLIDE] = FollowablePlayerMovement_Slide,
    [COPY_MOVE_JUMP_IN_PLACE] = FollowablePlayerMovement_JumpInPlace,
    [COPY_MOVE_JUMP] = FollowablePlayerMovement_GoSpeed4,
    [COPY_MOVE_JUMP2] = FollowablePlayerMovement_Step,
    [COPY_MOVE_WALK_COLLIDE] = FollowablePlayerMovement_Idle,
    [COPY_MOVE_WALK_COLLIDE_SLOW] = FollowablePlayerMovement_Idle,
};

u8 (*const gMovementTypeFuncs_CopyPlayerInGrass[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_CopyPlayer_Step0,
    MovementType_CopyPlayerInGrass_Step1,
    MovementType_CopyPlayer_Step2,
};

u8 (*const gMovementTypeFuncs_Buried[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_Buried_Step0,
};

u8 (*const gMovementTypeFuncs_WalkInPlace[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkInPlace_Step0,
    MovementType_MoveInPlace_Step1,
};

u8 (*const gMovementTypeFuncs_WalkSlowlyInPlace[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_WalkSlowlyInPlace_Step0,
    MovementType_MoveInPlace_Step1,
};

u8 (*const gMovementTypeFuncs_JogInPlace[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_JogInPlace_Step0,
    MovementType_MoveInPlace_Step1,
};

u8 (*const gMovementTypeFuncs_RunInPlace[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_RunInPlace_Step0,
    MovementType_MoveInPlace_Step1,
};

u8 (*const gMovementTypeFuncs_Invisible[])(struct ObjectEvent *, struct Sprite *) = {
    MovementType_Invisible_Step0,
    MovementType_Invisible_Step1,
    MovementType_Invisible_Step2,
};
