#ifndef GUARD_EVENT_OBJECT_ANIMS_H
#define GUARD_EVENT_OBJECT_ANIMS_H

const union AnimCmd gFieldObjectImageAnim_StayStill[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpFaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpFaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpFaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpFaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoNorth[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoWest[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoEast[] =
{
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastWest[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastEast[] =
{
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(3, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFasterNorth[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(4, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFasterWest[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFasterEast[] =
{
    ANIMCMD_FRAME(5, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(3, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastestNorth[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(4, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastestWest[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_QuintyPlumpGoFastestEast[] =
{
    ANIMCMD_FRAME(5, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_FaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_FaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_FaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoNorth[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoWest[] =
{
    ANIMCMD_FRAME(7, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoEast[] =
{
    ANIMCMD_FRAME(7, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastNorth[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastWest[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastEast[] =
{
    ANIMCMD_FRAME(7, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFasterNorth[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFasterWest[] =
{
    ANIMCMD_FRAME(7, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFasterEast[] =
{
    ANIMCMD_FRAME(7, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastestNorth[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastestWest[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GoFastestEast[] =
{
    ANIMCMD_FRAME(7, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_RunSouth[] =
{
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(13, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_RunNorth[] =
{
    ANIMCMD_FRAME(14, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_FRAME(15, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_RunWest[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_FRAME(17, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_RunEast[] =
{
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(17, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_FieldMove[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_GetOnOffSurfBlobSouth[] =
{
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GetOnOffSurfBlobNorth[] =
{
    ANIMCMD_FRAME(10, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GetOnOffSurfBlobWest[] =
{
    ANIMCMD_FRAME(11, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_GetOnOffSurfBlobEast[] =
{
    ANIMCMD_FRAME(11, 32, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(20, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BunnyHoppyFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(20, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_StandingWheelieFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_MovingWheelieSouth[] =
{
    ANIMCMD_FRAME(21, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(22, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_MovingWheelieNorth[] =
{
    ANIMCMD_FRAME(23, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_MovingWheelieWest[] =
{
    ANIMCMD_FRAME(25, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_FRAME(26, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_MovingWheelieEast[] =
{
    ANIMCMD_FRAME(25, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(26, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_BerryTreeStage0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BerryTreeStage1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(2, 32),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BerryTreeStage2[] =
{
    ANIMCMD_FRAME(3, 48),
    ANIMCMD_FRAME(4, 48),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BerryTreeStage3[] =
{
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_BerryTreeStage4[] =
{
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_NurseBow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_RockBreak[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_TreeCut[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_TakeOutRodSouth[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_TakeOutRodNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_TakeOutRodWest[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_TakeOutRodEast[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_PutAwayRodSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(9, 6),
    ANIMCMD_FRAME(8, 6),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_PutAwayRodNorth[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(5, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_PutAwayRodWest[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_PutAwayRodEast[] =
{
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_HookedPokemonSouth[] =
{
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(11, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(11, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_HookedPokemonNorth[] =
{
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(7, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(7, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_HookedPokemonWest[] =
{
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_HookedPokemonEast[] =
{
    ANIMCMD_FRAME(2, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 6, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AffineAnimCmd gFieldObjectRotScalAnim_8508FD8[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(7),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gFieldObjectRotScalAnim_8509008[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gFieldObjectRotScalAnim_8509040[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gFieldObjectRotScalAnim_8509050[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gFieldObjectRotScalAnim_8509060[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gFieldObjectRotScalAnim_8509078[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

const union AnimCmd gFieldObjectImageAnim_HoOhFlapWings[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_HoOhStayStill[] =
{
    ANIMCMD_FRAME(3, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gFieldObjectImageAnimTable_Inanimate[] = {
    gFieldObjectImageAnim_StayStill,
};

const union AnimCmd *const gFieldObjectImageAnimTable_QuintyPlump[] = {
    gFieldObjectImageAnim_QuintyPlumpFaceSouth,
    gFieldObjectImageAnim_QuintyPlumpFaceNorth,
    gFieldObjectImageAnim_QuintyPlumpFaceWest,
    gFieldObjectImageAnim_QuintyPlumpFaceEast,
    gFieldObjectImageAnim_QuintyPlumpGoSouth,
    gFieldObjectImageAnim_QuintyPlumpGoNorth,
    gFieldObjectImageAnim_QuintyPlumpGoWest,
    gFieldObjectImageAnim_QuintyPlumpGoEast,
    gFieldObjectImageAnim_QuintyPlumpGoFastSouth,
    gFieldObjectImageAnim_QuintyPlumpGoFastNorth,
    gFieldObjectImageAnim_QuintyPlumpGoFastWest,
    gFieldObjectImageAnim_QuintyPlumpGoFastEast,
    gFieldObjectImageAnim_QuintyPlumpGoFasterSouth,
    gFieldObjectImageAnim_QuintyPlumpGoFasterNorth,
    gFieldObjectImageAnim_QuintyPlumpGoFasterWest,
    gFieldObjectImageAnim_QuintyPlumpGoFasterEast,
    gFieldObjectImageAnim_QuintyPlumpGoFastestSouth,
    gFieldObjectImageAnim_QuintyPlumpGoFastestNorth,
    gFieldObjectImageAnim_QuintyPlumpGoFastestWest,
    gFieldObjectImageAnim_QuintyPlumpGoFastestEast,
};

const union AnimCmd *const gFieldObjectImageAnimTable_Standard[] = {
    gFieldObjectImageAnim_FaceSouth,
    gFieldObjectImageAnim_FaceNorth,
    gFieldObjectImageAnim_FaceWest,
    gFieldObjectImageAnim_FaceEast,
    gFieldObjectImageAnim_GoSouth,
    gFieldObjectImageAnim_GoNorth,
    gFieldObjectImageAnim_GoWest,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoFastSouth,
    gFieldObjectImageAnim_GoFastNorth,
    gFieldObjectImageAnim_GoFastWest,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFasterSouth,
    gFieldObjectImageAnim_GoFasterNorth,
    gFieldObjectImageAnim_GoFasterWest,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFastestSouth,
    gFieldObjectImageAnim_GoFastestNorth,
    gFieldObjectImageAnim_GoFastestWest,
    gFieldObjectImageAnim_GoFastestEast,
};

const union AnimCmd *const gFieldObjectImageAnimTable_HoOh[] = {
    gFieldObjectImageAnim_FaceSouth,
    gFieldObjectImageAnim_FaceNorth,
    gFieldObjectImageAnim_FaceWest,
    gFieldObjectImageAnim_FaceEast,
    gFieldObjectImageAnim_HoOhFlapWings,
    gFieldObjectImageAnim_HoOhStayStill,
    gFieldObjectImageAnim_GoWest,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoFastSouth,
    gFieldObjectImageAnim_GoFastNorth,
    gFieldObjectImageAnim_GoFastWest,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFasterSouth,
    gFieldObjectImageAnim_GoFasterNorth,
    gFieldObjectImageAnim_GoFasterWest,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFastestSouth,
    gFieldObjectImageAnim_GoFastestNorth,
    gFieldObjectImageAnim_GoFastestWest,
    gFieldObjectImageAnim_GoFastestEast,
};

const union AnimCmd *const gFieldObjectImageAnimTable_Groudon3[] = {
    gFieldObjectImageAnim_FaceSouth,
    gFieldObjectImageAnim_FaceNorth,
    gFieldObjectImageAnim_FaceWest,
    gFieldObjectImageAnim_FaceEast,
    gFieldObjectImageAnim_GoSouth,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoWest,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoFastSouth,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFastWest,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFasterSouth,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFasterWest,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFastestSouth,
    gFieldObjectImageAnim_GoFastestEast,
    gFieldObjectImageAnim_GoFastestWest,
    gFieldObjectImageAnim_GoFastestEast,
};

const union AnimCmd gFieldObjectImageAnim_85091F0[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_85091F8[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_8509200[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_8509208[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_8509210[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_8509218[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_8509220[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_8509228[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gFieldObjectImageAnim_8509230[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gFieldObjectImageAnimTable_Rayquaza2[] = {
    gFieldObjectImageAnim_8509218,
    gFieldObjectImageAnim_8509220,
    gFieldObjectImageAnim_8509228,
    gFieldObjectImageAnim_8509230,
    gFieldObjectImageAnim_8509200,
    gFieldObjectImageAnim_85091F8,
    gFieldObjectImageAnim_8509208,
    gFieldObjectImageAnim_8509210,
    gFieldObjectImageAnim_8509200,
    gFieldObjectImageAnim_85091F8,
    gFieldObjectImageAnim_85091F0,
    gFieldObjectImageAnim_8509210,
    gFieldObjectImageAnim_8509200,
    gFieldObjectImageAnim_85091F8,
    gFieldObjectImageAnim_8509208,
    gFieldObjectImageAnim_8509210,
    gFieldObjectImageAnim_8509200,
    gFieldObjectImageAnim_85091F8,
    gFieldObjectImageAnim_8509208,
    gFieldObjectImageAnim_8509210,
};

const union AnimCmd *const gFieldObjectImageAnimTable_BrendanMayNormal[] = {
    gFieldObjectImageAnim_FaceSouth,
    gFieldObjectImageAnim_FaceNorth,
    gFieldObjectImageAnim_FaceWest,
    gFieldObjectImageAnim_FaceEast,
    gFieldObjectImageAnim_GoSouth,
    gFieldObjectImageAnim_GoNorth,
    gFieldObjectImageAnim_GoWest,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoFastSouth,
    gFieldObjectImageAnim_GoFastNorth,
    gFieldObjectImageAnim_GoFastWest,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFasterSouth,
    gFieldObjectImageAnim_GoFasterNorth,
    gFieldObjectImageAnim_GoFasterWest,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFastestSouth,
    gFieldObjectImageAnim_GoFastestNorth,
    gFieldObjectImageAnim_GoFastestWest,
    gFieldObjectImageAnim_GoFastestEast,
    gFieldObjectImageAnim_RunSouth,
    gFieldObjectImageAnim_RunNorth,
    gFieldObjectImageAnim_RunWest,
    gFieldObjectImageAnim_RunEast,
};

const union AnimCmd *const gFieldObjectImageAnimTable_AcroBike[] = {
    gFieldObjectImageAnim_FaceSouth,
    gFieldObjectImageAnim_FaceNorth,
    gFieldObjectImageAnim_FaceWest,
    gFieldObjectImageAnim_FaceEast,
    gFieldObjectImageAnim_GoSouth,
    gFieldObjectImageAnim_GoNorth,
    gFieldObjectImageAnim_GoWest,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoFastSouth,
    gFieldObjectImageAnim_GoFastNorth,
    gFieldObjectImageAnim_GoFastWest,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFasterSouth,
    gFieldObjectImageAnim_GoFasterNorth,
    gFieldObjectImageAnim_GoFasterWest,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFastestSouth,
    gFieldObjectImageAnim_GoFastestNorth,
    gFieldObjectImageAnim_GoFastestWest,
    gFieldObjectImageAnim_GoFastestEast,
    gFieldObjectImageAnim_BunnyHoppyBackWheelSouth,
    gFieldObjectImageAnim_BunnyHoppyBackWheelNorth,
    gFieldObjectImageAnim_BunnyHoppyBackWheelWest,
    gFieldObjectImageAnim_BunnyHoppyBackWheelEast,
    gFieldObjectImageAnim_BunnyHoppyFrontWheelSouth,
    gFieldObjectImageAnim_BunnyHoppyFrontWheelNorth,
    gFieldObjectImageAnim_BunnyHoppyFrontWheelWest,
    gFieldObjectImageAnim_BunnyHoppyFrontWheelEast,
    gFieldObjectImageAnim_StandingWheelieBackWheelSouth,
    gFieldObjectImageAnim_StandingWheelieBackWheelNorth,
    gFieldObjectImageAnim_StandingWheelieBackWheelWest,
    gFieldObjectImageAnim_StandingWheelieBackWheelEast,
    gFieldObjectImageAnim_StandingWheelieFrontWheelSouth,
    gFieldObjectImageAnim_StandingWheelieFrontWheelNorth,
    gFieldObjectImageAnim_StandingWheelieFrontWheelWest,
    gFieldObjectImageAnim_StandingWheelieFrontWheelEast,
    gFieldObjectImageAnim_MovingWheelieSouth,
    gFieldObjectImageAnim_MovingWheelieNorth,
    gFieldObjectImageAnim_MovingWheelieWest,
    gFieldObjectImageAnim_MovingWheelieEast,
};

const union AnimCmd *const gFieldObjectImageAnimTable_Surfing[] = {
    gFieldObjectImageAnim_FaceSouth,
    gFieldObjectImageAnim_FaceNorth,
    gFieldObjectImageAnim_FaceWest,
    gFieldObjectImageAnim_FaceEast,
    gFieldObjectImageAnim_GoSouth,
    gFieldObjectImageAnim_GoNorth,
    gFieldObjectImageAnim_GoWest,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoFastSouth,
    gFieldObjectImageAnim_GoFastNorth,
    gFieldObjectImageAnim_GoFastWest,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFasterSouth,
    gFieldObjectImageAnim_GoFasterNorth,
    gFieldObjectImageAnim_GoFasterWest,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFastestSouth,
    gFieldObjectImageAnim_GoFastestNorth,
    gFieldObjectImageAnim_GoFastestWest,
    gFieldObjectImageAnim_GoFastestEast,
    gFieldObjectImageAnim_GetOnOffSurfBlobSouth,
    gFieldObjectImageAnim_GetOnOffSurfBlobNorth,
    gFieldObjectImageAnim_GetOnOffSurfBlobWest,
    gFieldObjectImageAnim_GetOnOffSurfBlobEast,
};

const union AnimCmd *const gFieldObjectImageAnimTable_Nurse[] = {
    gFieldObjectImageAnim_FaceSouth,
    gFieldObjectImageAnim_FaceNorth,
    gFieldObjectImageAnim_FaceWest,
    gFieldObjectImageAnim_FaceEast,
    gFieldObjectImageAnim_GoSouth,
    gFieldObjectImageAnim_GoNorth,
    gFieldObjectImageAnim_GoWest,
    gFieldObjectImageAnim_GoEast,
    gFieldObjectImageAnim_GoFastSouth,
    gFieldObjectImageAnim_GoFastNorth,
    gFieldObjectImageAnim_GoFastWest,
    gFieldObjectImageAnim_GoFastEast,
    gFieldObjectImageAnim_GoFasterSouth,
    gFieldObjectImageAnim_GoFasterNorth,
    gFieldObjectImageAnim_GoFasterWest,
    gFieldObjectImageAnim_GoFasterEast,
    gFieldObjectImageAnim_GoFastestSouth,
    gFieldObjectImageAnim_GoFastestNorth,
    gFieldObjectImageAnim_GoFastestWest,
    gFieldObjectImageAnim_GoFastestEast,
    gFieldObjectImageAnim_NurseBow,
};

const union AnimCmd *const gFieldObjectImageAnimTable_FieldMove[] = {
    gFieldObjectImageAnim_FieldMove,
};

const union AnimCmd *const gFieldObjectImageAnimTable_BerryTree[] = {
    gFieldObjectImageAnim_BerryTreeStage0,
    gFieldObjectImageAnim_BerryTreeStage1,
    gFieldObjectImageAnim_BerryTreeStage2,
    gFieldObjectImageAnim_BerryTreeStage3,
    gFieldObjectImageAnim_BerryTreeStage4,
};

const union AnimCmd *const gFieldObjectImageAnimTable_BreakableRock[] = {
    gFieldObjectImageAnim_StayStill,
    gFieldObjectImageAnim_RockBreak,
};

const union AnimCmd *const gFieldObjectImageAnimTable_CuttableTree[] = {
    gFieldObjectImageAnim_StayStill,
    gFieldObjectImageAnim_TreeCut,
};

const union AnimCmd *const gFieldObjectImageAnimTable_Fishing[] = {
    gFieldObjectImageAnim_TakeOutRodSouth,
    gFieldObjectImageAnim_TakeOutRodNorth,
    gFieldObjectImageAnim_TakeOutRodWest,
    gFieldObjectImageAnim_TakeOutRodEast,
    gFieldObjectImageAnim_PutAwayRodSouth,
    gFieldObjectImageAnim_PutAwayRodNorth,
    gFieldObjectImageAnim_PutAwayRodWest,
    gFieldObjectImageAnim_PutAwayRodEast,
    gFieldObjectImageAnim_HookedPokemonSouth,
    gFieldObjectImageAnim_HookedPokemonNorth,
    gFieldObjectImageAnim_HookedPokemonWest,
    gFieldObjectImageAnim_HookedPokemonEast,
};

const union AffineAnimCmd *const gFieldObjectRotScalAnimTable_KyogreGroudon[] = {
    gFieldObjectRotScalAnim_8508FD8,
    gFieldObjectRotScalAnim_8509008,
    gFieldObjectRotScalAnim_8509050,
    gFieldObjectRotScalAnim_8509040,
    gFieldObjectRotScalAnim_8509078,
    gFieldObjectRotScalAnim_8509060,
};

const struct UnkStruct_085094AC gUnknown_085094AC[] = {
    {
        .anims = gFieldObjectImageAnimTable_QuintyPlump,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gFieldObjectImageAnimTable_Standard,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gFieldObjectImageAnimTable_BrendanMayNormal,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gFieldObjectImageAnimTable_AcroBike,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gFieldObjectImageAnimTable_Surfing,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gFieldObjectImageAnimTable_Nurse,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gFieldObjectImageAnimTable_Fishing,
        .animPos = {1, 3, 0, 2},
    },
    {
        NULL,
        {0, 0, 0, 0},
    },
};

#endif //GUARD_EVENT_OBJECT_ANIMS_H
