const union AnimCmd gEventObjectImageAnim_StayStill[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpFaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpFaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpFaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpFaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoNorth[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoWest[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoEast[] =
{
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastWest[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastEast[] =
{
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(3, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFasterNorth[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(4, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFasterWest[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFasterEast[] =
{
    ANIMCMD_FRAME(5, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(3, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastestNorth[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(4, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastestWest[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_QuintyPlumpGoFastestEast[] =
{
    ANIMCMD_FRAME(5, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_FaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_FaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_FaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoNorth[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoWest[] =
{
    ANIMCMD_FRAME(7, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoEast[] =
{
    ANIMCMD_FRAME(7, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastNorth[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastWest[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastEast[] =
{
    ANIMCMD_FRAME(7, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFasterNorth[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFasterWest[] =
{
    ANIMCMD_FRAME(7, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFasterEast[] =
{
    ANIMCMD_FRAME(7, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastestNorth[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastestWest[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GoFastestEast[] =
{
    ANIMCMD_FRAME(7, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_RunSouth[] =
{
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(13, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_RunNorth[] =
{
    ANIMCMD_FRAME(14, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_FRAME(15, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_RunWest[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_FRAME(17, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_RunEast[] =
{
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(17, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_FieldMove[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_GetOnOffSurfBlobSouth[] =
{
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GetOnOffSurfBlobNorth[] =
{
    ANIMCMD_FRAME(10, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GetOnOffSurfBlobWest[] =
{
    ANIMCMD_FRAME(11, 32),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_GetOnOffSurfBlobEast[] =
{
    ANIMCMD_FRAME(11, 32, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(20, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BunnyHoppyFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(20, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_StandingWheelieFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_MovingWheelieSouth[] =
{
    ANIMCMD_FRAME(21, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(22, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_MovingWheelieNorth[] =
{
    ANIMCMD_FRAME(23, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_MovingWheelieWest[] =
{
    ANIMCMD_FRAME(25, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_FRAME(26, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_MovingWheelieEast[] =
{
    ANIMCMD_FRAME(25, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(26, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_BerryTreeStage0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BerryTreeStage1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(2, 32),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BerryTreeStage2[] =
{
    ANIMCMD_FRAME(3, 48),
    ANIMCMD_FRAME(4, 48),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BerryTreeStage3[] =
{
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_BerryTreeStage4[] =
{
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_NurseBow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_RockBreak[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_TreeCut[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_TakeOutRodSouth[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_TakeOutRodNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_TakeOutRodWest[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_TakeOutRodEast[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_PutAwayRodSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(9, 6),
    ANIMCMD_FRAME(8, 6),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_PutAwayRodNorth[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(5, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_PutAwayRodWest[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_PutAwayRodEast[] =
{
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_HookedPokemonSouth[] =
{
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(11, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(11, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_HookedPokemonNorth[] =
{
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(7, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(7, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_HookedPokemonWest[] =
{
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_HookedPokemonEast[] =
{
    ANIMCMD_FRAME(2, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 6, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

const union AffineAnimCmd gEventObjectRotScalAnim_8508FD8[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(7),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gEventObjectRotScalAnim_8509008[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_JUMP(0),
};

const union AffineAnimCmd gEventObjectRotScalAnim_8509040[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gEventObjectRotScalAnim_8509050[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gEventObjectRotScalAnim_8509060[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gEventObjectRotScalAnim_8509078[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

const union AnimCmd gEventObjectImageAnim_HoOhFlapWings[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_HoOhStayStill[] =
{
    ANIMCMD_FRAME(3, 16),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gEventObjectImageAnimTable_Inanimate[] = {
    gEventObjectImageAnim_StayStill,
};

const union AnimCmd *const gEventObjectImageAnimTable_QuintyPlump[] = {
    gEventObjectImageAnim_QuintyPlumpFaceSouth,
    gEventObjectImageAnim_QuintyPlumpFaceNorth,
    gEventObjectImageAnim_QuintyPlumpFaceWest,
    gEventObjectImageAnim_QuintyPlumpFaceEast,
    gEventObjectImageAnim_QuintyPlumpGoSouth,
    gEventObjectImageAnim_QuintyPlumpGoNorth,
    gEventObjectImageAnim_QuintyPlumpGoWest,
    gEventObjectImageAnim_QuintyPlumpGoEast,
    gEventObjectImageAnim_QuintyPlumpGoFastSouth,
    gEventObjectImageAnim_QuintyPlumpGoFastNorth,
    gEventObjectImageAnim_QuintyPlumpGoFastWest,
    gEventObjectImageAnim_QuintyPlumpGoFastEast,
    gEventObjectImageAnim_QuintyPlumpGoFasterSouth,
    gEventObjectImageAnim_QuintyPlumpGoFasterNorth,
    gEventObjectImageAnim_QuintyPlumpGoFasterWest,
    gEventObjectImageAnim_QuintyPlumpGoFasterEast,
    gEventObjectImageAnim_QuintyPlumpGoFastestSouth,
    gEventObjectImageAnim_QuintyPlumpGoFastestNorth,
    gEventObjectImageAnim_QuintyPlumpGoFastestWest,
    gEventObjectImageAnim_QuintyPlumpGoFastestEast,
};

const union AnimCmd *const gEventObjectImageAnimTable_Standard[] = {
    gEventObjectImageAnim_FaceSouth,
    gEventObjectImageAnim_FaceNorth,
    gEventObjectImageAnim_FaceWest,
    gEventObjectImageAnim_FaceEast,
    gEventObjectImageAnim_GoSouth,
    gEventObjectImageAnim_GoNorth,
    gEventObjectImageAnim_GoWest,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoFastSouth,
    gEventObjectImageAnim_GoFastNorth,
    gEventObjectImageAnim_GoFastWest,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFasterSouth,
    gEventObjectImageAnim_GoFasterNorth,
    gEventObjectImageAnim_GoFasterWest,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFastestSouth,
    gEventObjectImageAnim_GoFastestNorth,
    gEventObjectImageAnim_GoFastestWest,
    gEventObjectImageAnim_GoFastestEast,
};

const union AnimCmd *const gEventObjectImageAnimTable_HoOh[] = {
    gEventObjectImageAnim_FaceSouth,
    gEventObjectImageAnim_FaceNorth,
    gEventObjectImageAnim_FaceWest,
    gEventObjectImageAnim_FaceEast,
    gEventObjectImageAnim_HoOhFlapWings,
    gEventObjectImageAnim_HoOhStayStill,
    gEventObjectImageAnim_GoWest,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoFastSouth,
    gEventObjectImageAnim_GoFastNorth,
    gEventObjectImageAnim_GoFastWest,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFasterSouth,
    gEventObjectImageAnim_GoFasterNorth,
    gEventObjectImageAnim_GoFasterWest,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFastestSouth,
    gEventObjectImageAnim_GoFastestNorth,
    gEventObjectImageAnim_GoFastestWest,
    gEventObjectImageAnim_GoFastestEast,
};

const union AnimCmd *const gEventObjectImageAnimTable_Groudon3[] = {
    gEventObjectImageAnim_FaceSouth,
    gEventObjectImageAnim_FaceNorth,
    gEventObjectImageAnim_FaceWest,
    gEventObjectImageAnim_FaceEast,
    gEventObjectImageAnim_GoSouth,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoWest,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoFastSouth,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFastWest,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFasterSouth,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFasterWest,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFastestSouth,
    gEventObjectImageAnim_GoFastestEast,
    gEventObjectImageAnim_GoFastestWest,
    gEventObjectImageAnim_GoFastestEast,
};

const union AnimCmd gEventObjectImageAnim_85091F0[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_85091F8[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_8509200[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_8509208[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_8509210[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_8509218[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_8509220[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_8509228[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd gEventObjectImageAnim_8509230[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gEventObjectImageAnimTable_Rayquaza2[] = {
    gEventObjectImageAnim_8509218,
    gEventObjectImageAnim_8509220,
    gEventObjectImageAnim_8509228,
    gEventObjectImageAnim_8509230,
    gEventObjectImageAnim_8509200,
    gEventObjectImageAnim_85091F8,
    gEventObjectImageAnim_8509208,
    gEventObjectImageAnim_8509210,
    gEventObjectImageAnim_8509200,
    gEventObjectImageAnim_85091F8,
    gEventObjectImageAnim_85091F0,
    gEventObjectImageAnim_8509210,
    gEventObjectImageAnim_8509200,
    gEventObjectImageAnim_85091F8,
    gEventObjectImageAnim_8509208,
    gEventObjectImageAnim_8509210,
    gEventObjectImageAnim_8509200,
    gEventObjectImageAnim_85091F8,
    gEventObjectImageAnim_8509208,
    gEventObjectImageAnim_8509210,
};

const union AnimCmd *const gEventObjectImageAnimTable_BrendanMayNormal[] = {
    gEventObjectImageAnim_FaceSouth,
    gEventObjectImageAnim_FaceNorth,
    gEventObjectImageAnim_FaceWest,
    gEventObjectImageAnim_FaceEast,
    gEventObjectImageAnim_GoSouth,
    gEventObjectImageAnim_GoNorth,
    gEventObjectImageAnim_GoWest,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoFastSouth,
    gEventObjectImageAnim_GoFastNorth,
    gEventObjectImageAnim_GoFastWest,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFasterSouth,
    gEventObjectImageAnim_GoFasterNorth,
    gEventObjectImageAnim_GoFasterWest,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFastestSouth,
    gEventObjectImageAnim_GoFastestNorth,
    gEventObjectImageAnim_GoFastestWest,
    gEventObjectImageAnim_GoFastestEast,
    gEventObjectImageAnim_RunSouth,
    gEventObjectImageAnim_RunNorth,
    gEventObjectImageAnim_RunWest,
    gEventObjectImageAnim_RunEast,
};

const union AnimCmd *const gEventObjectImageAnimTable_AcroBike[] = {
    gEventObjectImageAnim_FaceSouth,
    gEventObjectImageAnim_FaceNorth,
    gEventObjectImageAnim_FaceWest,
    gEventObjectImageAnim_FaceEast,
    gEventObjectImageAnim_GoSouth,
    gEventObjectImageAnim_GoNorth,
    gEventObjectImageAnim_GoWest,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoFastSouth,
    gEventObjectImageAnim_GoFastNorth,
    gEventObjectImageAnim_GoFastWest,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFasterSouth,
    gEventObjectImageAnim_GoFasterNorth,
    gEventObjectImageAnim_GoFasterWest,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFastestSouth,
    gEventObjectImageAnim_GoFastestNorth,
    gEventObjectImageAnim_GoFastestWest,
    gEventObjectImageAnim_GoFastestEast,
    gEventObjectImageAnim_BunnyHoppyBackWheelSouth,
    gEventObjectImageAnim_BunnyHoppyBackWheelNorth,
    gEventObjectImageAnim_BunnyHoppyBackWheelWest,
    gEventObjectImageAnim_BunnyHoppyBackWheelEast,
    gEventObjectImageAnim_BunnyHoppyFrontWheelSouth,
    gEventObjectImageAnim_BunnyHoppyFrontWheelNorth,
    gEventObjectImageAnim_BunnyHoppyFrontWheelWest,
    gEventObjectImageAnim_BunnyHoppyFrontWheelEast,
    gEventObjectImageAnim_StandingWheelieBackWheelSouth,
    gEventObjectImageAnim_StandingWheelieBackWheelNorth,
    gEventObjectImageAnim_StandingWheelieBackWheelWest,
    gEventObjectImageAnim_StandingWheelieBackWheelEast,
    gEventObjectImageAnim_StandingWheelieFrontWheelSouth,
    gEventObjectImageAnim_StandingWheelieFrontWheelNorth,
    gEventObjectImageAnim_StandingWheelieFrontWheelWest,
    gEventObjectImageAnim_StandingWheelieFrontWheelEast,
    gEventObjectImageAnim_MovingWheelieSouth,
    gEventObjectImageAnim_MovingWheelieNorth,
    gEventObjectImageAnim_MovingWheelieWest,
    gEventObjectImageAnim_MovingWheelieEast,
};

const union AnimCmd *const gEventObjectImageAnimTable_Surfing[] = {
    gEventObjectImageAnim_FaceSouth,
    gEventObjectImageAnim_FaceNorth,
    gEventObjectImageAnim_FaceWest,
    gEventObjectImageAnim_FaceEast,
    gEventObjectImageAnim_GoSouth,
    gEventObjectImageAnim_GoNorth,
    gEventObjectImageAnim_GoWest,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoFastSouth,
    gEventObjectImageAnim_GoFastNorth,
    gEventObjectImageAnim_GoFastWest,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFasterSouth,
    gEventObjectImageAnim_GoFasterNorth,
    gEventObjectImageAnim_GoFasterWest,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFastestSouth,
    gEventObjectImageAnim_GoFastestNorth,
    gEventObjectImageAnim_GoFastestWest,
    gEventObjectImageAnim_GoFastestEast,
    gEventObjectImageAnim_GetOnOffSurfBlobSouth,
    gEventObjectImageAnim_GetOnOffSurfBlobNorth,
    gEventObjectImageAnim_GetOnOffSurfBlobWest,
    gEventObjectImageAnim_GetOnOffSurfBlobEast,
};

const union AnimCmd *const gEventObjectImageAnimTable_Nurse[] = {
    gEventObjectImageAnim_FaceSouth,
    gEventObjectImageAnim_FaceNorth,
    gEventObjectImageAnim_FaceWest,
    gEventObjectImageAnim_FaceEast,
    gEventObjectImageAnim_GoSouth,
    gEventObjectImageAnim_GoNorth,
    gEventObjectImageAnim_GoWest,
    gEventObjectImageAnim_GoEast,
    gEventObjectImageAnim_GoFastSouth,
    gEventObjectImageAnim_GoFastNorth,
    gEventObjectImageAnim_GoFastWest,
    gEventObjectImageAnim_GoFastEast,
    gEventObjectImageAnim_GoFasterSouth,
    gEventObjectImageAnim_GoFasterNorth,
    gEventObjectImageAnim_GoFasterWest,
    gEventObjectImageAnim_GoFasterEast,
    gEventObjectImageAnim_GoFastestSouth,
    gEventObjectImageAnim_GoFastestNorth,
    gEventObjectImageAnim_GoFastestWest,
    gEventObjectImageAnim_GoFastestEast,
    gEventObjectImageAnim_NurseBow,
};

const union AnimCmd *const gEventObjectImageAnimTable_FieldMove[] = {
    gEventObjectImageAnim_FieldMove,
};

const union AnimCmd *const gEventObjectImageAnimTable_BerryTree[] = {
    gEventObjectImageAnim_BerryTreeStage0,
    gEventObjectImageAnim_BerryTreeStage1,
    gEventObjectImageAnim_BerryTreeStage2,
    gEventObjectImageAnim_BerryTreeStage3,
    gEventObjectImageAnim_BerryTreeStage4,
};

const union AnimCmd *const gEventObjectImageAnimTable_BreakableRock[] = {
    gEventObjectImageAnim_StayStill,
    gEventObjectImageAnim_RockBreak,
};

const union AnimCmd *const gEventObjectImageAnimTable_CuttableTree[] = {
    gEventObjectImageAnim_StayStill,
    gEventObjectImageAnim_TreeCut,
};

const union AnimCmd *const gEventObjectImageAnimTable_Fishing[] = {
    gEventObjectImageAnim_TakeOutRodSouth,
    gEventObjectImageAnim_TakeOutRodNorth,
    gEventObjectImageAnim_TakeOutRodWest,
    gEventObjectImageAnim_TakeOutRodEast,
    gEventObjectImageAnim_PutAwayRodSouth,
    gEventObjectImageAnim_PutAwayRodNorth,
    gEventObjectImageAnim_PutAwayRodWest,
    gEventObjectImageAnim_PutAwayRodEast,
    gEventObjectImageAnim_HookedPokemonSouth,
    gEventObjectImageAnim_HookedPokemonNorth,
    gEventObjectImageAnim_HookedPokemonWest,
    gEventObjectImageAnim_HookedPokemonEast,
};

const union AffineAnimCmd *const gEventObjectRotScalAnimTable_KyogreGroudon[] = {
    gEventObjectRotScalAnim_8508FD8,
    gEventObjectRotScalAnim_8509008,
    gEventObjectRotScalAnim_8509050,
    gEventObjectRotScalAnim_8509040,
    gEventObjectRotScalAnim_8509078,
    gEventObjectRotScalAnim_8509060,
};

const struct UnkStruct_085094AC gUnknown_085094AC[] = {
    {
        .anims = gEventObjectImageAnimTable_QuintyPlump,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gEventObjectImageAnimTable_Standard,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gEventObjectImageAnimTable_BrendanMayNormal,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gEventObjectImageAnimTable_AcroBike,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gEventObjectImageAnimTable_Surfing,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gEventObjectImageAnimTable_Nurse,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = gEventObjectImageAnimTable_Fishing,
        .animPos = {1, 3, 0, 2},
    },
    {
        NULL,
        {0, 0, 0, 0},
    },
};
