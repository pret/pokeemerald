const union AnimCmd gObjectEventImageAnim_StayStill[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpFaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpFaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpFaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpFaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoNorth[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoWest[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoEast[] =
{
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastWest[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastEast[] =
{
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(3, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFasterNorth[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(4, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFasterWest[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFasterEast[] =
{
    ANIMCMD_FRAME(5, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(3, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastestNorth[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(4, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastestWest[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_QuintyPlumpGoFastestEast[] =
{
    ANIMCMD_FRAME(5, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_FaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_FaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_FaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoNorth[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoWest[] =
{
    ANIMCMD_FRAME(7, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoEast[] =
{
    ANIMCMD_FRAME(7, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastNorth[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastWest[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastEast[] =
{
    ANIMCMD_FRAME(7, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFasterNorth[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFasterWest[] =
{
    ANIMCMD_FRAME(7, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFasterEast[] =
{
    ANIMCMD_FRAME(7, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastestNorth[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastestWest[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GoFastestEast[] =
{
    ANIMCMD_FRAME(7, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_RunSouth[] =
{
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(13, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_RunNorth[] =
{
    ANIMCMD_FRAME(14, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_FRAME(15, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_RunWest[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_FRAME(17, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_RunEast[] =
{
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(17, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_FieldMove[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_GetOnOffSurfBlobSouth[] =
{
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GetOnOffSurfBlobNorth[] =
{
    ANIMCMD_FRAME(10, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GetOnOffSurfBlobWest[] =
{
    ANIMCMD_FRAME(11, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_GetOnOffSurfBlobEast[] =
{
    ANIMCMD_FRAME(11, 32, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(20, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BunnyHoppyFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(20, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_StandingWheelieFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_MovingWheelieSouth[] =
{
    ANIMCMD_FRAME(21, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(22, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_MovingWheelieNorth[] =
{
    ANIMCMD_FRAME(23, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_MovingWheelieWest[] =
{
    ANIMCMD_FRAME(25, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_FRAME(26, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_MovingWheelieEast[] =
{
    ANIMCMD_FRAME(25, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(26, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_BerryTreeStage0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BerryTreeStage1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(2, 32),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BerryTreeStage2[] =
{
    ANIMCMD_FRAME(3, 48),
    ANIMCMD_FRAME(4, 48),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BerryTreeStage3[] =
{
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_BerryTreeStage4[] =
{
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_NurseBow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_RockBreak[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_TreeCut[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_TakeOutRodSouth[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_TakeOutRodNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_TakeOutRodWest[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_TakeOutRodEast[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_PutAwayRodSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(9, 6),
    ANIMCMD_FRAME(8, 6),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_PutAwayRodNorth[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(5, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_PutAwayRodWest[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_PutAwayRodEast[] =
{
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_HookedPokemonSouth[] =
{
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(11, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(11, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_HookedPokemonNorth[] =
{
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(7, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(7, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_HookedPokemonWest[] =
{
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_HookedPokemonEast[] =
{
    ANIMCMD_FRAME(2, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 6, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AffineAnimCmd gObjectEventRotScalAnim_8508FD8[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(7),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gObjectEventRotScalAnim_8509008[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gObjectEventRotScalAnim_8509040[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gObjectEventRotScalAnim_8509050[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gObjectEventRotScalAnim_8509060[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gObjectEventRotScalAnim_8509078[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

const union AnimCmd gObjectEventImageAnim_HoOhFlapWings[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_HoOhStayStill[] =
{
    ANIMCMD_FRAME(3, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gObjectEventImageAnimTable_Inanimate[] = {
    gObjectEventImageAnim_StayStill,
};

const union AnimCmd *const gObjectEventImageAnimTable_QuintyPlump[] = {
    gObjectEventImageAnim_QuintyPlumpFaceSouth,
    gObjectEventImageAnim_QuintyPlumpFaceNorth,
    gObjectEventImageAnim_QuintyPlumpFaceWest,
    gObjectEventImageAnim_QuintyPlumpFaceEast,
    gObjectEventImageAnim_QuintyPlumpGoSouth,
    gObjectEventImageAnim_QuintyPlumpGoNorth,
    gObjectEventImageAnim_QuintyPlumpGoWest,
    gObjectEventImageAnim_QuintyPlumpGoEast,
    gObjectEventImageAnim_QuintyPlumpGoFastSouth,
    gObjectEventImageAnim_QuintyPlumpGoFastNorth,
    gObjectEventImageAnim_QuintyPlumpGoFastWest,
    gObjectEventImageAnim_QuintyPlumpGoFastEast,
    gObjectEventImageAnim_QuintyPlumpGoFasterSouth,
    gObjectEventImageAnim_QuintyPlumpGoFasterNorth,
    gObjectEventImageAnim_QuintyPlumpGoFasterWest,
    gObjectEventImageAnim_QuintyPlumpGoFasterEast,
    gObjectEventImageAnim_QuintyPlumpGoFastestSouth,
    gObjectEventImageAnim_QuintyPlumpGoFastestNorth,
    gObjectEventImageAnim_QuintyPlumpGoFastestWest,
    gObjectEventImageAnim_QuintyPlumpGoFastestEast,
};

const union AnimCmd *const gObjectEventImageAnimTable_Standard[] = {
    gObjectEventImageAnim_FaceSouth,
    gObjectEventImageAnim_FaceNorth,
    gObjectEventImageAnim_FaceWest,
    gObjectEventImageAnim_FaceEast,
    gObjectEventImageAnim_GoSouth,
    gObjectEventImageAnim_GoNorth,
    gObjectEventImageAnim_GoWest,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoFastSouth,
    gObjectEventImageAnim_GoFastNorth,
    gObjectEventImageAnim_GoFastWest,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFasterSouth,
    gObjectEventImageAnim_GoFasterNorth,
    gObjectEventImageAnim_GoFasterWest,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFastestSouth,
    gObjectEventImageAnim_GoFastestNorth,
    gObjectEventImageAnim_GoFastestWest,
    gObjectEventImageAnim_GoFastestEast,
};

const union AnimCmd *const gObjectEventImageAnimTable_HoOh[] = {
    gObjectEventImageAnim_FaceSouth,
    gObjectEventImageAnim_FaceNorth,
    gObjectEventImageAnim_FaceWest,
    gObjectEventImageAnim_FaceEast,
    gObjectEventImageAnim_HoOhFlapWings,
    gObjectEventImageAnim_HoOhStayStill,
    gObjectEventImageAnim_GoWest,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoFastSouth,
    gObjectEventImageAnim_GoFastNorth,
    gObjectEventImageAnim_GoFastWest,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFasterSouth,
    gObjectEventImageAnim_GoFasterNorth,
    gObjectEventImageAnim_GoFasterWest,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFastestSouth,
    gObjectEventImageAnim_GoFastestNorth,
    gObjectEventImageAnim_GoFastestWest,
    gObjectEventImageAnim_GoFastestEast,
};

const union AnimCmd *const gObjectEventImageAnimTable_Groudon3[] = {
    gObjectEventImageAnim_FaceSouth,
    gObjectEventImageAnim_FaceNorth,
    gObjectEventImageAnim_FaceWest,
    gObjectEventImageAnim_FaceEast,
    gObjectEventImageAnim_GoSouth,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoWest,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoFastSouth,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFastWest,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFasterSouth,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFasterWest,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFastestSouth,
    gObjectEventImageAnim_GoFastestEast,
    gObjectEventImageAnim_GoFastestWest,
    gObjectEventImageAnim_GoFastestEast,
};

const union AnimCmd gObjectEventImageAnim_85091F0[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_85091F8[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_8509200[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_8509208[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_8509210[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_8509218[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_8509220[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_8509228[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gObjectEventImageAnim_8509230[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gObjectEventImageAnimTable_Rayquaza2[] = {
    gObjectEventImageAnim_8509218,
    gObjectEventImageAnim_8509220,
    gObjectEventImageAnim_8509228,
    gObjectEventImageAnim_8509230,
    gObjectEventImageAnim_8509200,
    gObjectEventImageAnim_85091F8,
    gObjectEventImageAnim_8509208,
    gObjectEventImageAnim_8509210,
    gObjectEventImageAnim_8509200,
    gObjectEventImageAnim_85091F8,
    gObjectEventImageAnim_85091F0,
    gObjectEventImageAnim_8509210,
    gObjectEventImageAnim_8509200,
    gObjectEventImageAnim_85091F8,
    gObjectEventImageAnim_8509208,
    gObjectEventImageAnim_8509210,
    gObjectEventImageAnim_8509200,
    gObjectEventImageAnim_85091F8,
    gObjectEventImageAnim_8509208,
    gObjectEventImageAnim_8509210,
};

const union AnimCmd *const gObjectEventImageAnimTable_BrendanMayNormal[] = {
    gObjectEventImageAnim_FaceSouth,
    gObjectEventImageAnim_FaceNorth,
    gObjectEventImageAnim_FaceWest,
    gObjectEventImageAnim_FaceEast,
    gObjectEventImageAnim_GoSouth,
    gObjectEventImageAnim_GoNorth,
    gObjectEventImageAnim_GoWest,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoFastSouth,
    gObjectEventImageAnim_GoFastNorth,
    gObjectEventImageAnim_GoFastWest,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFasterSouth,
    gObjectEventImageAnim_GoFasterNorth,
    gObjectEventImageAnim_GoFasterWest,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFastestSouth,
    gObjectEventImageAnim_GoFastestNorth,
    gObjectEventImageAnim_GoFastestWest,
    gObjectEventImageAnim_GoFastestEast,
    gObjectEventImageAnim_RunSouth,
    gObjectEventImageAnim_RunNorth,
    gObjectEventImageAnim_RunWest,
    gObjectEventImageAnim_RunEast,
};

const union AnimCmd *const gObjectEventImageAnimTable_AcroBike[] = {
    gObjectEventImageAnim_FaceSouth,
    gObjectEventImageAnim_FaceNorth,
    gObjectEventImageAnim_FaceWest,
    gObjectEventImageAnim_FaceEast,
    gObjectEventImageAnim_GoSouth,
    gObjectEventImageAnim_GoNorth,
    gObjectEventImageAnim_GoWest,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoFastSouth,
    gObjectEventImageAnim_GoFastNorth,
    gObjectEventImageAnim_GoFastWest,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFasterSouth,
    gObjectEventImageAnim_GoFasterNorth,
    gObjectEventImageAnim_GoFasterWest,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFastestSouth,
    gObjectEventImageAnim_GoFastestNorth,
    gObjectEventImageAnim_GoFastestWest,
    gObjectEventImageAnim_GoFastestEast,
    gObjectEventImageAnim_BunnyHoppyBackWheelSouth,
    gObjectEventImageAnim_BunnyHoppyBackWheelNorth,
    gObjectEventImageAnim_BunnyHoppyBackWheelWest,
    gObjectEventImageAnim_BunnyHoppyBackWheelEast,
    gObjectEventImageAnim_BunnyHoppyFrontWheelSouth,
    gObjectEventImageAnim_BunnyHoppyFrontWheelNorth,
    gObjectEventImageAnim_BunnyHoppyFrontWheelWest,
    gObjectEventImageAnim_BunnyHoppyFrontWheelEast,
    gObjectEventImageAnim_StandingWheelieBackWheelSouth,
    gObjectEventImageAnim_StandingWheelieBackWheelNorth,
    gObjectEventImageAnim_StandingWheelieBackWheelWest,
    gObjectEventImageAnim_StandingWheelieBackWheelEast,
    gObjectEventImageAnim_StandingWheelieFrontWheelSouth,
    gObjectEventImageAnim_StandingWheelieFrontWheelNorth,
    gObjectEventImageAnim_StandingWheelieFrontWheelWest,
    gObjectEventImageAnim_StandingWheelieFrontWheelEast,
    gObjectEventImageAnim_MovingWheelieSouth,
    gObjectEventImageAnim_MovingWheelieNorth,
    gObjectEventImageAnim_MovingWheelieWest,
    gObjectEventImageAnim_MovingWheelieEast,
};

const union AnimCmd *const gObjectEventImageAnimTable_Surfing[] = {
    gObjectEventImageAnim_FaceSouth,
    gObjectEventImageAnim_FaceNorth,
    gObjectEventImageAnim_FaceWest,
    gObjectEventImageAnim_FaceEast,
    gObjectEventImageAnim_GoSouth,
    gObjectEventImageAnim_GoNorth,
    gObjectEventImageAnim_GoWest,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoFastSouth,
    gObjectEventImageAnim_GoFastNorth,
    gObjectEventImageAnim_GoFastWest,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFasterSouth,
    gObjectEventImageAnim_GoFasterNorth,
    gObjectEventImageAnim_GoFasterWest,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFastestSouth,
    gObjectEventImageAnim_GoFastestNorth,
    gObjectEventImageAnim_GoFastestWest,
    gObjectEventImageAnim_GoFastestEast,
    gObjectEventImageAnim_GetOnOffSurfBlobSouth,
    gObjectEventImageAnim_GetOnOffSurfBlobNorth,
    gObjectEventImageAnim_GetOnOffSurfBlobWest,
    gObjectEventImageAnim_GetOnOffSurfBlobEast,
};

const union AnimCmd *const gObjectEventImageAnimTable_Nurse[] = {
    gObjectEventImageAnim_FaceSouth,
    gObjectEventImageAnim_FaceNorth,
    gObjectEventImageAnim_FaceWest,
    gObjectEventImageAnim_FaceEast,
    gObjectEventImageAnim_GoSouth,
    gObjectEventImageAnim_GoNorth,
    gObjectEventImageAnim_GoWest,
    gObjectEventImageAnim_GoEast,
    gObjectEventImageAnim_GoFastSouth,
    gObjectEventImageAnim_GoFastNorth,
    gObjectEventImageAnim_GoFastWest,
    gObjectEventImageAnim_GoFastEast,
    gObjectEventImageAnim_GoFasterSouth,
    gObjectEventImageAnim_GoFasterNorth,
    gObjectEventImageAnim_GoFasterWest,
    gObjectEventImageAnim_GoFasterEast,
    gObjectEventImageAnim_GoFastestSouth,
    gObjectEventImageAnim_GoFastestNorth,
    gObjectEventImageAnim_GoFastestWest,
    gObjectEventImageAnim_GoFastestEast,
    gObjectEventImageAnim_NurseBow,
};

const union AnimCmd *const gObjectEventImageAnimTable_FieldMove[] = {
    gObjectEventImageAnim_FieldMove,
};

const union AnimCmd *const gObjectEventImageAnimTable_BerryTree[] = {
    gObjectEventImageAnim_BerryTreeStage0,
    gObjectEventImageAnim_BerryTreeStage1,
    gObjectEventImageAnim_BerryTreeStage2,
    gObjectEventImageAnim_BerryTreeStage3,
    gObjectEventImageAnim_BerryTreeStage4,
};

const union AnimCmd *const gObjectEventImageAnimTable_BreakableRock[] = {
    gObjectEventImageAnim_StayStill,
    gObjectEventImageAnim_RockBreak,
};

const union AnimCmd *const gObjectEventImageAnimTable_CuttableTree[] = {
    gObjectEventImageAnim_StayStill,
    gObjectEventImageAnim_TreeCut,
};

const union AnimCmd *const gObjectEventImageAnimTable_Fishing[] = {
    gObjectEventImageAnim_TakeOutRodSouth,
    gObjectEventImageAnim_TakeOutRodNorth,
    gObjectEventImageAnim_TakeOutRodWest,
    gObjectEventImageAnim_TakeOutRodEast,
    gObjectEventImageAnim_PutAwayRodSouth,
    gObjectEventImageAnim_PutAwayRodNorth,
    gObjectEventImageAnim_PutAwayRodWest,
    gObjectEventImageAnim_PutAwayRodEast,
    gObjectEventImageAnim_HookedPokemonSouth,
    gObjectEventImageAnim_HookedPokemonNorth,
    gObjectEventImageAnim_HookedPokemonWest,
    gObjectEventImageAnim_HookedPokemonEast,
};

const union AffineAnimCmd *const gObjectEventRotScalAnimTable_KyogreGroudon[] = {
    gObjectEventRotScalAnim_8508FD8,
    gObjectEventRotScalAnim_8509008,
    gObjectEventRotScalAnim_8509050,
    gObjectEventRotScalAnim_8509040,
    gObjectEventRotScalAnim_8509078,
    gObjectEventRotScalAnim_8509060,
};

const struct UnkStruct_085094AC gUnknown_085094AC[] = {
    {
        .anims = gObjectEventImageAnimTable_QuintyPlump,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gObjectEventImageAnimTable_Standard,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gObjectEventImageAnimTable_BrendanMayNormal,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gObjectEventImageAnimTable_AcroBike,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gObjectEventImageAnimTable_Surfing,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gObjectEventImageAnimTable_Nurse,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gObjectEventImageAnimTable_Fishing,
        .animPos = {1, 3, 0, 2},
    },
    {
        NULL,
        {0, 0, 0, 0},
    },
};
