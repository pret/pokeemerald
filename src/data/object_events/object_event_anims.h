static const union AnimCmd sAnim_StayStill[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpFaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpFaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpFaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpFaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(3, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoNorth[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoWest[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoEast[] =
{
    ANIMCMD_FRAME(5, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastWest[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastEast[] =
{
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(3, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFasterNorth[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(4, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFasterWest[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFasterEast[] =
{
    ANIMCMD_FRAME(5, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(3, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastestNorth[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(4, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastestWest[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_QuintyPlumpGoFastestEast[] =
{
    ANIMCMD_FRAME(5, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(6, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceNorth[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceNorth2F[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceWest[] =
{
    ANIMCMD_FRAME(2, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceWest2F[] =
{
    ANIMCMD_FRAME(4, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceEast[] =
{
    ANIMCMD_FRAME(2, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceEast2F[] =
{
    ANIMCMD_FRAME(4, 16, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FaceEast2F_Asym[] =
{
    ANIMCMD_FRAME(6, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoSouth[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoSouth2F[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoNorth[] =
{
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoNorth2F[] =
{
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoWest[] =
{
    ANIMCMD_FRAME(7, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoWest2F[] =
{
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_FRAME(5, 6),
    ANIMCMD_FRAME(5, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoEast[] =
{
    ANIMCMD_FRAME(7, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoEast2F[] =
{
    ANIMCMD_FRAME(4, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 6, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoEast2F_Asym[] =
{
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(7, 6),
    ANIMCMD_FRAME(7, 6),
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastSouth[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastSouth2F[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastNorth[] =
{
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastNorth2F[] =
{
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastWest[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastWest2F[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastEast[] =
{
    ANIMCMD_FRAME(7, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastEast2F[] =
{
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(5, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastEast2F_Asym[] =
{
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFasterSouth[] =
{
    ANIMCMD_FRAME(3, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballSouth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballNorth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballWest[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballEast[] =
{
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballEast_Asym[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_EnterSouth[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFasterNorth[] =
{
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_EnterNorth[] =
{
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFasterWest[] =
{
    ANIMCMD_FRAME(7, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_EnterWest[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFasterEast[] =
{
    ANIMCMD_FRAME(7, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 2, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_EnterEast[] =
{
    ANIMCMD_FRAME(4, 8, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_EnterEast_Asym[] =
{
    ANIMCMD_FRAME(6, 8),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastestSouth[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballFastSouth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballFastNorth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballFastWest[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballFastEast[] =
{
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(4, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(4, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_ExitPokeballFastEast_Asym[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastestNorth[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(6, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastestWest[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GoFastestEast[] =
{
    ANIMCMD_FRAME(7, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(8, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RunSouth[] =
{
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(13, 5),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RunNorth[] =
{
    ANIMCMD_FRAME(14, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_FRAME(15, 5),
    ANIMCMD_FRAME(10, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RunWest[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_FRAME(17, 5),
    ANIMCMD_FRAME(11, 3),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RunEast[] =
{
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(17, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(11, 3, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_FieldMove[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GetOnOffSurfBlobSouth[] =
{
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GetOnOffSurfBlobNorth[] =
{
    ANIMCMD_FRAME(10, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GetOnOffSurfBlobWest[] =
{
    ANIMCMD_FRAME(11, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_GetOnOffSurfBlobEast[] =
{
    ANIMCMD_FRAME(11, 32, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_BunnyHopBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BunnyHopBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BunnyHopBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BunnyHopBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BunnyHopFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BunnyHopFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BunnyHopFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(20, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BunnyHopFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(20, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieBackWheelSouth[] =
{
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieBackWheelNorth[] =
{
    ANIMCMD_FRAME(13, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieBackWheelWest[] =
{
    ANIMCMD_FRAME(17, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieBackWheelEast[] =
{
    ANIMCMD_FRAME(17, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieFrontWheelSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieFrontWheelNorth[] =
{
    ANIMCMD_FRAME(15, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieFrontWheelWest[] =
{
    ANIMCMD_FRAME(19, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_StandingWheelieFrontWheelEast[] =
{
    ANIMCMD_FRAME(19, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MovingWheelieSouth[] =
{
    ANIMCMD_FRAME(21, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(22, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_MovingWheelieNorth[] =
{
    ANIMCMD_FRAME(23, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(14, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_MovingWheelieWest[] =
{
    ANIMCMD_FRAME(25, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_FRAME(26, 4),
    ANIMCMD_FRAME(18, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_MovingWheelieEast[] =
{
    ANIMCMD_FRAME(25, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(26, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(18, 4, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_BerryTreeStage0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BerryTreeStage1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(2, 32),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BerryTreeStage2[] =
{
    ANIMCMD_FRAME(3, 48),
    ANIMCMD_FRAME(4, 48),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BerryTreeStage3[] =
{
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_BerryTreeStage4[] =
{
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(7, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_FRAME(8, 48),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_NurseBow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(9, 32),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_RockBreak[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TreeCut[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TakeOutRodSouth[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(9, 4),
    ANIMCMD_FRAME(10, 4),
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TakeOutRodNorth[] =
{
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TakeOutRodWest[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TakeOutRodEast[] =
{
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PutAwayRodSouth[] =
{
    ANIMCMD_FRAME(11, 4),
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(9, 6),
    ANIMCMD_FRAME(8, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PutAwayRodNorth[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(5, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PutAwayRodWest[] =
{
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_PutAwayRodEast[] =
{
    ANIMCMD_FRAME(3, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(1, 4, .hFlip = TRUE),
    ANIMCMD_FRAME(0, 4, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_HookedPokemonSouth[] =
{
    ANIMCMD_FRAME(10, 6),
    ANIMCMD_FRAME(11, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(11, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_HookedPokemonNorth[] =
{
    ANIMCMD_FRAME(6, 6),
    ANIMCMD_FRAME(7, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(7, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_HookedPokemonWest[] =
{
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_HookedPokemonEast[] =
{
    ANIMCMD_FRAME(2, 6, .hFlip = TRUE),
    ANIMCMD_FRAME(3, 6, .hFlip = TRUE),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME(3, 30, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_KyogreGroudon_GoSouthStart[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(7),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_KyogreGroudon_GoSouth[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 1),
    AFFINEANIMCMD_LOOP(15),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sAffineAnim_KyogreGroudon_AttackEast[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KyogreGroudon_AttackWest[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 10, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KyogreGroudon_DipEast[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_KyogreGroudon_DipWest[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 1, 1),
    AFFINEANIMCMD_LOOP(8),
    AFFINEANIMCMD_END,
};

static const union AnimCmd sAnim_HoOhFlapWings[] =
{
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_HoOhStayStill[] =
{
    ANIMCMD_FRAME(3, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_Inanimate[] = {
    [ANIM_STAY_STILL] = sAnim_StayStill,
};

static const union AnimCmd *const sAnimTable_QuintyPlump[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_QuintyPlumpFaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_QuintyPlumpFaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_QuintyPlumpFaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_QuintyPlumpFaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_QuintyPlumpGoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_QuintyPlumpGoNorth,
    [ANIM_STD_GO_WEST] = sAnim_QuintyPlumpGoWest,
    [ANIM_STD_GO_EAST] = sAnim_QuintyPlumpGoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_QuintyPlumpGoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_QuintyPlumpGoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_QuintyPlumpGoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_QuintyPlumpGoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_QuintyPlumpGoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_QuintyPlumpGoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_QuintyPlumpGoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_QuintyPlumpGoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_QuintyPlumpGoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_QuintyPlumpGoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_QuintyPlumpGoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_QuintyPlumpGoFastestEast,
};

static const union AnimCmd *const sAnimTable_Standard[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_GoNorth,
    [ANIM_STD_GO_WEST] = sAnim_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_GoFastestEast,
};

const union AnimCmd *const sAnimTable_Following[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth2F,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest2F,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast2F,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth2F,
    [ANIM_STD_GO_NORTH] = sAnim_GoNorth2F,
    [ANIM_STD_GO_WEST] = sAnim_GoWest2F,
    [ANIM_STD_GO_EAST] = sAnim_GoEast2F,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth2F,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth2F,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest2F,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast2F,
    // 'Faster' and above used for entering/exiting pokeball
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_EnterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_EnterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_EnterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_EnterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_ExitPokeballSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_ExitPokeballNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_ExitPokeballWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_ExitPokeballEast,
    [ANIM_EXIT_POKEBALL_FAST_SOUTH] = sAnim_ExitPokeballFastSouth,
    [ANIM_EXIT_POKEBALL_FAST_NORTH] = sAnim_ExitPokeballFastNorth,
    [ANIM_EXIT_POKEBALL_FAST_WEST] = sAnim_ExitPokeballFastWest,
    [ANIM_EXIT_POKEBALL_FAST_EAST] = sAnim_ExitPokeballFastEast,
};

// Like the above, but has separate frames for facing right
static const union AnimCmd *const sAnimTable_Following_Asym[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth2F,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest2F,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast2F_Asym,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth2F,
    [ANIM_STD_GO_NORTH] = sAnim_GoNorth2F,
    [ANIM_STD_GO_WEST] = sAnim_GoWest2F,
    [ANIM_STD_GO_EAST] = sAnim_GoEast2F_Asym,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth2F,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth2F,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest2F,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast2F_Asym,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_EnterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_EnterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_EnterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_EnterEast_Asym,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_ExitPokeballSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_ExitPokeballNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_ExitPokeballWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_ExitPokeballEast_Asym,
    [ANIM_EXIT_POKEBALL_FAST_SOUTH] = sAnim_ExitPokeballFastSouth,
    [ANIM_EXIT_POKEBALL_FAST_NORTH] = sAnim_ExitPokeballFastNorth,
    [ANIM_EXIT_POKEBALL_FAST_WEST] = sAnim_ExitPokeballFastWest,
    [ANIM_EXIT_POKEBALL_FAST_EAST] = sAnim_ExitPokeballFastEast_Asym,
};

static const union AnimCmd *const sAnimTable_HoOh[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_HoOhFlapWings,
    [ANIM_STD_GO_NORTH] = sAnim_HoOhStayStill,
    [ANIM_STD_GO_WEST] = sAnim_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_GoFastestEast,
};

// The movements for going up use the animations for going right instead.
static const union AnimCmd *const sAnimTable_GroudonSide[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_GoEast,
    [ANIM_STD_GO_WEST] = sAnim_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastEast,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_GoFastestEast,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_GoFastestEast,
};

static const union AnimCmd sAnim_RayquazaCoiledAwake[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RayquazaFlyUp[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RayquazaCoiledAsleep[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RayquazaCoiledMouthOpen[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_RayquazaNormal[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

// Identical to sAnim_RayquazaCoiledAsleep
static const union AnimCmd sAnim_RayquazaFaceSouth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

// Identical to sAnim_RayquazaCoiledAsleep
static const union AnimCmd sAnim_RayquazaFaceNorth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

// Identical to sAnim_RayquazaCoiledAsleep
static const union AnimCmd sAnim_RayquazaFaceWest[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

// Identical to sAnim_RayquazaNormal
static const union AnimCmd sAnim_RayquazaFaceEast[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_JUMP(0),
};

// Though they correspond to facing/walking movements, Rayquaza doesn't have
// equivalent images aside from flying up. Its other frames aside from the 'normal'
// frame are for the sequence where it awakens on Sky Pillar.
static const union AnimCmd *const sAnimTable_Rayquaza[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_RayquazaFaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_RayquazaFaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_RayquazaFaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_RayquazaFaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_RayquazaCoiledAsleep,
    [ANIM_STD_GO_NORTH] = sAnim_RayquazaFlyUp,
    [ANIM_STD_GO_WEST] = sAnim_RayquazaCoiledMouthOpen,
    [ANIM_STD_GO_EAST] = sAnim_RayquazaNormal,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_RayquazaCoiledAsleep,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_RayquazaFlyUp,
    [ANIM_STD_GO_FAST_WEST] = sAnim_RayquazaCoiledAwake,
    [ANIM_STD_GO_FAST_EAST] = sAnim_RayquazaNormal,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_RayquazaCoiledAsleep,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_RayquazaFlyUp,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_RayquazaCoiledMouthOpen,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_RayquazaNormal,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_RayquazaCoiledAsleep,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_RayquazaFlyUp,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_RayquazaCoiledMouthOpen,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_RayquazaNormal,
};

static const union AnimCmd *const sAnimTable_BrendanMayNormal[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_GoNorth,
    [ANIM_STD_GO_WEST] = sAnim_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_GoFastestEast,
    [ANIM_RUN_SOUTH] = sAnim_RunSouth,
    [ANIM_RUN_NORTH] = sAnim_RunNorth,
    [ANIM_RUN_WEST] = sAnim_RunWest,
    [ANIM_RUN_EAST] = sAnim_RunEast,
};

static const union AnimCmd *const sAnimTable_AcroBike[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_GoNorth,
    [ANIM_STD_GO_WEST] = sAnim_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_GoFastestEast,
    [ANIM_BUNNY_HOP_BACK_WHEEL_SOUTH] = sAnim_BunnyHopBackWheelSouth,
    [ANIM_BUNNY_HOP_BACK_WHEEL_NORTH] = sAnim_BunnyHopBackWheelNorth,
    [ANIM_BUNNY_HOP_BACK_WHEEL_WEST] = sAnim_BunnyHopBackWheelWest,
    [ANIM_BUNNY_HOP_BACK_WHEEL_EAST] = sAnim_BunnyHopBackWheelEast,
    [ANIM_BUNNY_HOP_FRONT_WHEEL_SOUTH] = sAnim_BunnyHopFrontWheelSouth,
    [ANIM_BUNNY_HOP_FRONT_WHEEL_NORTH] = sAnim_BunnyHopFrontWheelNorth,
    [ANIM_BUNNY_HOP_FRONT_WHEEL_WEST] = sAnim_BunnyHopFrontWheelWest,
    [ANIM_BUNNY_HOP_FRONT_WHEEL_EAST] = sAnim_BunnyHopFrontWheelEast,
    [ANIM_STANDING_WHEELIE_BACK_WHEEL_SOUTH] = sAnim_StandingWheelieBackWheelSouth,
    [ANIM_STANDING_WHEELIE_BACK_WHEEL_NORTH] = sAnim_StandingWheelieBackWheelNorth,
    [ANIM_STANDING_WHEELIE_BACK_WHEEL_WEST] = sAnim_StandingWheelieBackWheelWest,
    [ANIM_STANDING_WHEELIE_BACK_WHEEL_EAST] = sAnim_StandingWheelieBackWheelEast,
    [ANIM_STANDING_WHEELIE_FRONT_WHEEL_SOUTH] = sAnim_StandingWheelieFrontWheelSouth,
    [ANIM_STANDING_WHEELIE_FRONT_WHEEL_NORTH] = sAnim_StandingWheelieFrontWheelNorth,
    [ANIM_STANDING_WHEELIE_FRONT_WHEEL_WEST] = sAnim_StandingWheelieFrontWheelWest,
    [ANIM_STANDING_WHEELIE_FRONT_WHEEL_EAST] = sAnim_StandingWheelieFrontWheelEast,
    [ANIM_MOVING_WHEELIE_SOUTH] = sAnim_MovingWheelieSouth,
    [ANIM_MOVING_WHEELIE_NORTH] = sAnim_MovingWheelieNorth,
    [ANIM_MOVING_WHEELIE_WEST] = sAnim_MovingWheelieWest,
    [ANIM_MOVING_WHEELIE_EAST] = sAnim_MovingWheelieEast,
};

static const union AnimCmd *const sAnimTable_Surfing[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_GoNorth,
    [ANIM_STD_GO_WEST] = sAnim_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST] = sAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST] = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_GoFastestEast,
    [ANIM_GET_ON_OFF_POKEMON_SOUTH] = sAnim_GetOnOffSurfBlobSouth,
    [ANIM_GET_ON_OFF_POKEMON_NORTH] = sAnim_GetOnOffSurfBlobNorth,
    [ANIM_GET_ON_OFF_POKEMON_WEST] = sAnim_GetOnOffSurfBlobWest,
    [ANIM_GET_ON_OFF_POKEMON_EAST] = sAnim_GetOnOffSurfBlobEast,
};

static const union AnimCmd *const sAnimTable_Nurse[] = {
    [ANIM_STD_FACE_SOUTH] = sAnim_FaceSouth,
    [ANIM_STD_FACE_NORTH] = sAnim_FaceNorth,
    [ANIM_STD_FACE_WEST] = sAnim_FaceWest,
    [ANIM_STD_FACE_EAST] = sAnim_FaceEast,
    [ANIM_STD_GO_SOUTH] = sAnim_GoSouth,
    [ANIM_STD_GO_NORTH] = sAnim_GoNorth,
    [ANIM_STD_GO_WEST] = sAnim_GoWest,
    [ANIM_STD_GO_EAST] = sAnim_GoEast,
    [ANIM_STD_GO_FAST_SOUTH] = sAnim_GoFastSouth,
    [ANIM_STD_GO_FAST_NORTH] = sAnim_GoFastNorth,
    [ANIM_STD_GO_FAST_WEST] = sAnim_GoFastWest,
    [ANIM_STD_GO_FAST_EAST] = sAnim_GoFastEast,
    [ANIM_STD_GO_FASTER_SOUTH] = sAnim_GoFasterSouth,
    [ANIM_STD_GO_FASTER_NORTH] = sAnim_GoFasterNorth,
    [ANIM_STD_GO_FASTER_WEST]  = sAnim_GoFasterWest,
    [ANIM_STD_GO_FASTER_EAST]  = sAnim_GoFasterEast,
    [ANIM_STD_GO_FASTEST_SOUTH] = sAnim_GoFastestSouth,
    [ANIM_STD_GO_FASTEST_NORTH] = sAnim_GoFastestNorth,
    [ANIM_STD_GO_FASTEST_WEST] = sAnim_GoFastestWest,
    [ANIM_STD_GO_FASTEST_EAST] = sAnim_GoFastestEast,
    [ANIM_NURSE_BOW] = sAnim_NurseBow,
};

static const union AnimCmd *const sAnimTable_FieldMove[] = {
    [ANIM_FIELD_MOVE] = sAnim_FieldMove,
};

static const union AnimCmd *const sAnimTable_BerryTree[] = {
    [BERRY_STAGE_PLANTED - 1] = sAnim_BerryTreeStage0,
    [BERRY_STAGE_SPROUTED - 1] = sAnim_BerryTreeStage1,
    [BERRY_STAGE_TALLER - 1] = sAnim_BerryTreeStage2,
    [BERRY_STAGE_TRUNK - 1] = sAnim_BerryTreeStage2,
    [BERRY_STAGE_BUDDING - 1] = sAnim_BerryTreeStage2,
    [BERRY_STAGE_FLOWERING - 1] = sAnim_BerryTreeStage3,
    [BERRY_STAGE_BERRIES - 1] = sAnim_BerryTreeStage4,
};

static const union AnimCmd *const sAnimTable_BreakableRock[] = {
    [ANIM_STAY_STILL] = sAnim_StayStill,
    [ANIM_REMOVE_OBSTACLE] = sAnim_RockBreak,
};

static const union AnimCmd *const sAnimTable_CuttableTree[] = {
    [ANIM_STAY_STILL] = sAnim_StayStill,
    [ANIM_REMOVE_OBSTACLE] = sAnim_TreeCut,
};

static const union AnimCmd *const sAnimTable_Fishing[] = {
    [ANIM_TAKE_OUT_ROD_SOUTH] = sAnim_TakeOutRodSouth,
    [ANIM_TAKE_OUT_ROD_NORTH] = sAnim_TakeOutRodNorth,
    [ANIM_TAKE_OUT_ROD_WEST] = sAnim_TakeOutRodWest,
    [ANIM_TAKE_OUT_ROD_EAST] = sAnim_TakeOutRodEast,
    [ANIM_PUT_AWAY_ROD_SOUTH] = sAnim_PutAwayRodSouth,
    [ANIM_PUT_AWAY_ROD_NORTH] = sAnim_PutAwayRodNorth,
    [ANIM_PUT_AWAY_ROD_WEST] = sAnim_PutAwayRodWest,
    [ANIM_PUT_AWAY_ROD_EAST] = sAnim_PutAwayRodEast,
    [ANIM_HOOKED_POKEMON_SOUTH] = sAnim_HookedPokemonSouth,
    [ANIM_HOOKED_POKEMON_NORTH] = sAnim_HookedPokemonNorth,
    [ANIM_HOOKED_POKEMON_WEST] = sAnim_HookedPokemonWest,
    [ANIM_HOOKED_POKEMON_EAST] = sAnim_HookedPokemonEast,
};

static const union AffineAnimCmd *const sAffineAnimTable_KyogreGroudon[] = {
    sAffineAnim_KyogreGroudon_GoSouthStart, // Used by Kyogre/Groudon when awakened
    sAffineAnim_KyogreGroudon_GoSouth,      // Used by Kyogre/Groudon when awakened
    sAffineAnim_KyogreGroudon_AttackWest,   // Used by Kyogre during Sootopolis fight
    sAffineAnim_KyogreGroudon_AttackEast,   // Unused
    sAffineAnim_KyogreGroudon_DipWest,      // Unused
    sAffineAnim_KyogreGroudon_DipEast,      // Unused
};

// For animations with alternating steps
static const struct StepAnimTable sStepAnimTables[] = {
    {
        .anims = sAnimTable_QuintyPlump,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = sAnimTable_Standard,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = sAnimTable_Following,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = sAnimTable_BrendanMayNormal,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = sAnimTable_AcroBike,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = sAnimTable_Surfing,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = sAnimTable_Nurse,
        .animPos = {1, 3, 0, 2},
    },
    {
        .anims = sAnimTable_Fishing,
        .animPos = {1, 3, 0, 2},
    },
    {},
};
