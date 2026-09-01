const struct SpritePalette gSpritePalette_GeneralFieldEffect0 = {gFieldEffectObjectPalette0, FLDEFF_PAL_TAG_GENERAL_0};
const struct SpritePalette gSpritePalette_GeneralFieldEffect1 = {gFieldEffectObjectPalette1, FLDEFF_PAL_TAG_GENERAL_1};

static const union AnimCmd sAnim_Shadow[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Shadow[] =
{
    sAnim_Shadow,
};

static const struct SpriteFrameImage sPicTable_ShadowSmall[] = {
    obj_frame_tiles(gFieldEffectObjectPic_ShadowSmall),
};

static const struct SpriteFrameImage sPicTable_ShadowMedium[] = {
    obj_frame_tiles(gFieldEffectObjectPic_ShadowMedium),
};

static const struct SpriteFrameImage sPicTable_ShadowLarge[] = {
    obj_frame_tiles(gFieldEffectObjectPic_ShadowLarge),
};

static const struct SpriteFrameImage sPicTable_ShadowExtraLarge[] = {
    obj_frame_tiles(gFieldEffectObjectPic_ShadowExtraLarge),
};

const struct SpriteFrameImage gFieldEffectObjectPicTable_BallLight[] = {
    obj_frame_tiles(gFieldEffectObjectPic_BallLight),
};

const struct SpriteFrameImage gFieldEffectObjectPicTable_PokeCenterLight[] = {
    obj_frame_tiles(gFieldEffectObjectPic_PokeCenterLight),
};

const struct SpriteFrameImage gFieldEffectObjectPicTable_MartLight[] = {
    obj_frame_tiles(gFieldEffectObjectPic_MartLight),
};

const struct SpriteTemplate gFieldEffectObjectTemplate_BallLight = {
    .tileTag = OBJ_EVENT_PAL_TAG_LIGHT,
    .paletteTag = OBJ_EVENT_PAL_TAG_LIGHT,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sAnimTable_Inanimate,
    .images = gFieldEffectObjectPicTable_BallLight,
    .callback = UpdateLightSprite,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_PokeCenterLight = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_NEON_LIGHT,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_Inanimate,
    .images = gFieldEffectObjectPicTable_PokeCenterLight,
    .callback = UpdateLightSprite,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_MartLight = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_NEON_LIGHT,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_Inanimate,
    .images = gFieldEffectObjectPicTable_MartLight,
    .callback = UpdateLightSprite,
};

const struct SpriteTemplate *const gFieldEffectLightTemplates[] = {
    &gFieldEffectObjectTemplate_BallLight,
    &gFieldEffectObjectTemplate_PokeCenterLight,
    &gFieldEffectObjectTemplate_MartLight,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_ShadowSmall = {
    .tileTag = FLDEFF_TILE_TAG_SHADOW_SMALL,
    .paletteTag = TAG_WEATHER_START,
    .oam = &gObjectEventBaseOam_8x8,
    .anims = sAnimTable_Shadow,
    .images = sPicTable_ShadowSmall,
    .callback = UpdateShadowFieldEffect,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_ShadowMedium = {
    .tileTag = FLDEFF_TILE_TAG_SHADOW_MEDIUM,
    .paletteTag = TAG_WEATHER_START,
    .oam = &gObjectEventBaseOam_16x8,
    .anims = sAnimTable_Shadow,
    .images = sPicTable_ShadowMedium,
    .callback = UpdateShadowFieldEffect,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_ShadowLarge = {
    .tileTag = FLDEFF_TILE_TAG_SHADOW_LARGE,
    .paletteTag = TAG_WEATHER_START,
    .oam = &gObjectEventBaseOam_32x8,
    .anims = sAnimTable_Shadow,
    .images = sPicTable_ShadowLarge,
    .callback = UpdateShadowFieldEffect,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_ShadowExtraLarge = {
    .tileTag = FLDEFF_TILE_TAG_SHADOW_EXTRA_LARGE,
    .paletteTag = TAG_WEATHER_START,
    .oam = &gObjectEventBaseOam_64x32,
    .anims = sAnimTable_Shadow,
    .images = sPicTable_ShadowExtraLarge,
    .callback = UpdateShadowFieldEffect,
};

static const struct SpriteFrameImage sPicTable_TallGrass[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_TallGrass, 2, 2),
};

static const union AnimCmd sAnim_TallGrass[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(2, 10),
    ANIMCMD_FRAME(3, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_TallGrass[] =
{
    sAnim_TallGrass,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_TallGrass = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_TallGrass,
    .images = sPicTable_TallGrass,
    .callback = UpdateTallGrassFieldEffect,
};

static const struct SpriteFrameImage sPicTable_Ripple[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_Ripple, 2, 2),
};

static const union AnimCmd sAnim_Ripple[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 9),
    ANIMCMD_FRAME(3, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 11),
    ANIMCMD_FRAME(4, 11),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Ripple[] =
{
    sAnim_Ripple,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Ripple = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_Ripple,
    .images = sPicTable_Ripple,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpriteFrameImage sPicTable_Ash[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_Ash, 2, 2),
};

static const union AnimCmd sAnim_Ash[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 12),
    ANIMCMD_FRAME(4, 12),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Ash[] =
{
    sAnim_Ash,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Ash = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_Ash,
    .images = sPicTable_Ash,
    .callback = UpdateAshFieldEffect,
};

static const struct SpriteFrameImage sPicTable_SurfBlob[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_SurfBlob, 4, 4),
};

static const union AnimCmd sSurfBlobAnim_FaceSouth[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfBlobAnim_FaceNorth[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfBlobAnim_FaceWest[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSurfBlobAnim_FaceEast[] =
{
    ANIMCMD_FRAME(2, 1, .hFlip = TRUE),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_SurfBlob[] =
{
    sSurfBlobAnim_FaceSouth,
    sSurfBlobAnim_FaceNorth,
    sSurfBlobAnim_FaceWest,
    sSurfBlobAnim_FaceEast,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_SurfBlob = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sAnimTable_SurfBlob,
    .images = sPicTable_SurfBlob,
    .callback = UpdateSurfBlobFieldEffect,
};

static const struct SpriteFrameImage sPicTable_Arrow[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_Arrow, 2, 2),
};

static const union AnimCmd sArrowAnim_South[] =
{
    ANIMCMD_FRAME(3, 32),
    ANIMCMD_FRAME(7, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sArrowAnim_North[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(4, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sArrowAnim_West[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(5, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sArrowAnim_East[] =
{
    ANIMCMD_FRAME(2, 32),
    ANIMCMD_FRAME(6, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_Arrow[] =
{
    sArrowAnim_South,
    sArrowAnim_North,
    sArrowAnim_West,
    sArrowAnim_East,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Arrow = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_Arrow,
    .images = sPicTable_Arrow,
};

static const struct SpriteFrameImage sPicTable_GroundImpactDust[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_GroundImpactDust, 2, 1),
};

static const union AnimCmd sAnim_GroundImpactDust[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_GroundImpactDust[] =
{
    sAnim_GroundImpactDust,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_GroundImpactDust = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x8,
    .anims = sAnimTable_GroundImpactDust,
    .images = sPicTable_GroundImpactDust,
    .callback = UpdateJumpImpactEffect,
};

static const struct SpriteFrameImage sPicTable_JumpTallGrass[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_JumpTallGrass, 2, 1),
};

static const union AnimCmd sAnim_JumpTallGrass[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_JumpTallGrass[] =
{
    sAnim_JumpTallGrass,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_JumpTallGrass = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x8,
    .anims = sAnimTable_JumpTallGrass,
    .images = sPicTable_JumpTallGrass,
    .callback = UpdateJumpImpactEffect,
};

static const struct SpriteFrameImage sPicTable_SandFootprints[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_SandFootprints, 2, 2),
};

static const union AnimCmd sSandFootprintsAnim_South[] =
{
    ANIMCMD_FRAME(0, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sSandFootprintsAnim_North[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sSandFootprintsAnim_West[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sSandFootprintsAnim_East[] =
{
    ANIMCMD_FRAME(1, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_SandFootprints[] =
{
    sSandFootprintsAnim_South,
    sSandFootprintsAnim_South,
    sSandFootprintsAnim_North,
    sSandFootprintsAnim_West,
    sSandFootprintsAnim_East,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_SandFootprints = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_SandFootprints,
    .images = sPicTable_SandFootprints,
    .callback = UpdateFootprintsTireTracksFieldEffect,
};

static const struct SpriteFrameImage sPicTable_DeepSandFootprints[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_DeepSandFootprints, 2, 2),
};

static const union AnimCmd sDeepSandFootprintsAnim_South[] =
{
    ANIMCMD_FRAME(0, 1, .vFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sDeepSandFootprintsAnim_North[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sDeepSandFootprintsAnim_West[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sDeepSandFootprintsAnim_East[] =
{
    ANIMCMD_FRAME(1, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_DeepSandFootprints[] =
{
    sDeepSandFootprintsAnim_South,
    sDeepSandFootprintsAnim_South,
    sDeepSandFootprintsAnim_North,
    sDeepSandFootprintsAnim_West,
    sDeepSandFootprintsAnim_East,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_DeepSandFootprints = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_DeepSandFootprints,
    .images = sPicTable_DeepSandFootprints,
    .callback = UpdateFootprintsTireTracksFieldEffect,
};

static const struct SpriteFrameImage sPicTable_BugTracks[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_BugTracks, 2, 2),
};

static const struct SpriteFrameImage sPicTable_SpotTracks[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_SpotTracks, 2, 2),
};

const struct SpriteTemplate gFieldEffectObjectTemplate_BugTracks = {
    .tileTag = 0xFFFF,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_DeepSandFootprints,
    .images = sPicTable_BugTracks,
    .callback = UpdateFootprintsTireTracksFieldEffect,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_SpotTracks = {
    .tileTag = 0xFFFF,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_DeepSandFootprints,
    .images = sPicTable_SpotTracks,
    .callback = UpdateFootprintsTireTracksFieldEffect,
};

static const struct SpriteFrameImage sPicTable_BikeTireTracks[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_BikeTireTracks, 2, 2),
};

static const struct SpriteFrameImage sPicTable_SlitherTracks[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_SlitherTracks, 2, 2),
};

static const union AnimCmd sBikeTireTracksAnim_South[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END,
};

static const union AnimCmd sBikeTireTracksAnim_North[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END,
};

static const union AnimCmd sBikeTireTracksAnim_West[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sBikeTireTracksAnim_East[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd sBikeTireTracksAnim_SECornerTurn[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sBikeTireTracksAnim_SWCornerTurn[] =
{
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sBikeTireTracksAnim_NWCornerTurn[] =
{
    ANIMCMD_FRAME(3, 1, .hFlip = TRUE),
    ANIMCMD_END,
};

static const union AnimCmd sBikeTireTracksAnim_NECornerTurn[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_BikeTireTracks[] =
{
    sBikeTireTracksAnim_South,
    sBikeTireTracksAnim_South,
    sBikeTireTracksAnim_North,
    sBikeTireTracksAnim_West,
    sBikeTireTracksAnim_East,
    sBikeTireTracksAnim_SECornerTurn,
    sBikeTireTracksAnim_SWCornerTurn,
    sBikeTireTracksAnim_NWCornerTurn,
    sBikeTireTracksAnim_NECornerTurn,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_BikeTireTracks = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_BikeTireTracks,
    .images = sPicTable_BikeTireTracks,
    .callback = UpdateFootprintsTireTracksFieldEffect,
};


const struct SpriteTemplate gFieldEffectObjectTemplate_SlitherTracks = {
    .tileTag = 0xFFFF,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_BikeTireTracks,
    .images = sPicTable_SlitherTracks,
    .callback = UpdateFootprintsTireTracksFieldEffect,
};

static const struct SpriteFrameImage sPicTable_JumpBigSplash[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_JumpBigSplash, 2, 2),
};

static const union AnimCmd sAnim_JumpBigSplash[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_JumpBigSplash[] =
{
    sAnim_JumpBigSplash,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_JumpBigSplash = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_JumpBigSplash,
    .images = sPicTable_JumpBigSplash,
    .callback = UpdateJumpImpactEffect,
};

static const struct SpriteFrameImage sPicTable_Splash[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_Splash, 2, 1),
};

static const union AnimCmd sAnim_Splash_0[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Splash_1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_Splash[] =
{
    sAnim_Splash_0,
    sAnim_Splash_1,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Splash = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x8,
    .anims = sAnimTable_Splash,
    .images = sPicTable_Splash,
    .callback = UpdateSplashFieldEffect,
};

static const struct SpriteFrameImage sPicTable_JumpSmallSplash[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_JumpSmallSplash, 2, 1),
};

static const union AnimCmd sAnim_JumpSmallSplash[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_JumpSmallSplash[] =
{
    sAnim_JumpSmallSplash,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_JumpSmallSplash = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x8,
    .anims = sAnimTable_JumpSmallSplash,
    .images = sPicTable_JumpSmallSplash,
    .callback = UpdateJumpImpactEffect,
};

static const struct SpriteFrameImage sPicTable_LongGrass[] = {
    overworld_frame(gFieldEffectObjectPic_LongGrass, 2, 2, 0),
    overworld_frame(gFieldEffectObjectPic_LongGrass, 2, 2, 1),
    overworld_frame(gFieldEffectObjectPic_LongGrass, 2, 2, 2),
    overworld_frame(gFieldEffectObjectPic_LongGrass, 2, 2, 3),
};

static const union AnimCmd sAnim_LongGrass[] =
{
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(2, 3),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_LongGrass[] =
{
    sAnim_LongGrass,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_LongGrass = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_LongGrass,
    .images = sPicTable_LongGrass,
    .callback = UpdateLongGrassFieldEffect,
};

static const struct SpriteFrameImage sPicTable_JumpLongGrass[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_JumpLongGrass, 2, 2),
};

static const union AnimCmd sAnim_JumpLongGrass[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_JumpLongGrass[] =
{
    sAnim_JumpLongGrass,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_JumpLongGrass = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_JumpLongGrass,
    .images = sPicTable_JumpLongGrass,
    .callback = UpdateJumpImpactEffect,
};

static const struct SpriteFrameImage sPicTable_UnusedGrass[] = {
    overworld_frame(gFieldEffectObjectPic_JumpLongGrass, 2, 2, 6),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 0),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 1),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 2),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 3),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 4),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 5),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 6),
    overworld_frame(gFieldEffectObjectPic_Unknown17, 2, 2, 7),
};

static const union AnimCmd sAnim_UnusedGrass[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_JUMP(7),
};

static const union AnimCmd *const sAnimTable_UnusedGrass[] =
{
    sAnim_UnusedGrass,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_UnusedGrass = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_UnusedGrass,
    .images = sPicTable_UnusedGrass,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpriteFrameImage sPicTable_UnusedGrass2[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_UnusedGrass2, 2, 2),
};

static const union AnimCmd sAnim_UnusedGrass2[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_UnusedGrass2[] =
{
    sAnim_UnusedGrass2,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_UnusedGrass2 = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_UnusedGrass2,
    .images = sPicTable_UnusedGrass2,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpriteFrameImage sPicTable_UnusedSand[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_UnusedSand, 2, 2),
};

static const union AnimCmd sAnim_UnusedSand[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_UnusedSand[] =
{
    sAnim_UnusedSand,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_UnusedSand = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_UnusedSand,
    .images = sPicTable_UnusedSand,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpriteFrameImage sPicTable_SandPile[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_SandPile, 2, 1),
};

static const union AnimCmd sAnim_SandPile[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_SandPile[] =
{
    sAnim_SandPile,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_SandPile = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x8,
    .anims = sAnimTable_SandPile,
    .images = sPicTable_SandPile,
    .callback = UpdateSandPileFieldEffect,
};

static const struct SpriteFrameImage sPicTable_WaterSurfacing[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_WaterSurfacing, 2, 2),
};

static const union AnimCmd sAnim_WaterSurfacing[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimTable_WaterSurfacing[] =
{
    sAnim_WaterSurfacing,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_WaterSurfacing = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_WaterSurfacing,
    .images = sPicTable_WaterSurfacing,
    .callback = WaitFieldEffectSpriteAnim,
};

static const union AffineAnimCmd sAffineAnim_ReflectionDistortion_0[] =
{
    AFFINEANIMCMD_FRAME(0xFF00, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0x1, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFFF, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFFF, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0x1, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd sAffineAnim_ReflectionDistortion_1[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0xFFFF, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0x1, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0x1, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(0xFFFF, 0x0, 0, 4),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 8),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd *const sAffineAnims_ReflectionDistortion[] =
{
    sAffineAnim_ReflectionDistortion_0,
    sAffineAnim_ReflectionDistortion_1,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_ReflectionDistortion = {
    .tileTag = 0x0,
    .paletteTag = TAG_NONE,
    .oam = &gDummyOamData,
    .affineAnims = sAffineAnims_ReflectionDistortion,
};

static const struct SpriteFrameImage sPicTable_Sparkle[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_Sparkle, 2, 2),
};

static const union AnimCmd sAnim_Sparkle[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_LOOP(0),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_LOOP(3),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(5, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Sparkle[] =
{
    sAnim_Sparkle,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Sparkle = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_NPC_2,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_Sparkle,
    .images = sPicTable_Sparkle,
    .callback = WaitFieldEffectSpriteAnim,
};

static const struct SpriteFrameImage sPicTable_TreeDisguise[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_TreeDisguise, 2, 4),
};

static const union AnimCmd sAnim_TreeDisguise[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_TreeDisguiseReveal[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_TreeDisguise[] =
{
    sAnim_TreeDisguise,
    sAnim_TreeDisguiseReveal,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_TreeDisguise = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_NPC_3,
    .oam = &gObjectEventBaseOam_16x32,
    .anims = sAnimTable_TreeDisguise,
    .images = sPicTable_TreeDisguise,
    .callback = UpdateDisguiseFieldEffect,
};

static const struct SpriteFrameImage sPicTable_MountainDisguise[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_MountainDisguise, 2, 4),
};

static const union AnimCmd sAnim_MountainDisguise[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MountainDisguiseReveal[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_MountainDisguise[] =
{
    sAnim_MountainDisguise,
    sAnim_MountainDisguiseReveal,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_MountainDisguise = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_NPC_2,
    .oam = &gObjectEventBaseOam_16x32,
    .anims = sAnimTable_MountainDisguise,
    .images = sPicTable_MountainDisguise,
    .callback = UpdateDisguiseFieldEffect,
};

static const struct SpriteFrameImage sPicTable_SandDisguisePlaceholder[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_SandDisguisePlaceholder, 2, 4),
};

const struct SpriteTemplate gFieldEffectObjectTemplate_SandDisguisePlaceholder = {
    .tileTag = TAG_NONE,
    .paletteTag = TAG_NONE,
    .oam = &gObjectEventBaseOam_16x32,
    .anims = sAnimTable_TreeDisguise,
    .images = sPicTable_SandDisguisePlaceholder,
    .callback = UpdateDisguiseFieldEffect,
};

static const struct SpriteFrameImage sPicTable_Bird[] = {
    obj_frame_tiles(gFieldEffectObjectPic_Bird),
};

static const union AnimCmd sAnim_Bird[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Bird[] =
{
    sAnim_Bird,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Bird = {
    .tileTag = TAG_NONE,
    .paletteTag = OBJ_EVENT_PAL_TAG_MAY,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sAnimTable_Bird,
    .images = sPicTable_Bird,
};

static const struct SpriteFrameImage sPicTable_ShortGrass[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_ShortGrass, 2, 2),
};

static const union AnimCmd sAnim_ShortGrass[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_ShortGrass[] =
{
    sAnim_ShortGrass,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_ShortGrass = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_ShortGrass,
    .images = sPicTable_ShortGrass,
    .callback = UpdateShortGrassFieldEffect,
};

static const struct SpriteFrameImage sPicTable_HotSpringsWater[] = {
    obj_frame_tiles(gFieldEffectObjectPic_HotSpringsWater),
};

static const union AnimCmd sAnim_HotSpringsWater[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_HotSpringsWater[] =
{
    sAnim_HotSpringsWater,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_HotSpringsWater = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_1,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_HotSpringsWater,
    .images = sPicTable_HotSpringsWater,
    .callback = UpdateHotSpringsWaterFieldEffect,
};

static const struct SpriteFrameImage sPicTable_AshPuff[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_AshPuff, 2, 2),
};

static const union AnimCmd sAnim_AshPuff[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_AshPuff[] =
{
    sAnim_AshPuff,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_AshPuff =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_ASH,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_AshPuff,
    .images = sPicTable_AshPuff,
    .callback = SpriteCB_AshPuff
};

const struct SpritePalette gSpritePalette_Ash = {gFieldEffectPal_Ash, FLDEFF_PAL_TAG_ASH};

static const struct SpriteFrameImage sPicTable_AshLaunch[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_AshLaunch, 2, 2),
};

static const union AnimCmd sAnim_AshLaunch[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_AshLaunch[] =
{
    sAnim_AshLaunch,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_AshLaunch =
{
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_ASH,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_AshLaunch,
    .images = sPicTable_AshLaunch,
    .callback = SpriteCB_AshLaunch
};

static const struct SpriteFrameImage sPicTable_Bubbles[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_Bubbles, 2, 4),
};

static const union AnimCmd sAnim_Bubbles[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_Bubbles[] =
{
    sAnim_Bubbles,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Bubbles = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x32,
    .anims = sAnimTable_Bubbles,
    .images = sPicTable_Bubbles,
    .callback = UpdateBubblesFieldEffect,
};

static const struct SpriteFrameImage sPicTable_SmallSparkle[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_SmallSparkle, 2, 2),
};

static const union AnimCmd sAnim_SmallSparkle[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_SmallSparkle[] =
{
    sAnim_SmallSparkle,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_SmallSparkle = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_SMALL_SPARKLE,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_SmallSparkle,
    .images = sPicTable_SmallSparkle,
    .callback = UpdateSparkleFieldEffect,
};

const struct SpritePalette gSpritePalette_SmallSparkle = {gFieldEffectPal_SmallSparkle, FLDEFF_PAL_TAG_SMALL_SPARKLE};

static const union AnimCmd sAnim_RayquazaSpotlightEffect[] = {
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_RayquazaSpotlightEffect[] = {
    sAnim_RayquazaSpotlightEffect,
};

static const struct SpriteFrameImage sPicTable_RayquazaSpotlightEffect[] = {
    overworld_frame(gObjectEventPic_RayquazaCutscene, 4, 4, 0),
};

const struct SpriteTemplate gFieldEffectObjectTemplate_Rayquaza = {
    .tileTag = TAG_NONE,
    .paletteTag = TAG_NONE,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sAnimTable_RayquazaSpotlightEffect,
    .images = sPicTable_RayquazaSpotlightEffect,
    .callback = UpdateRayquazaSpotlightEffect,
};

static const struct SpritePalette sSpritePalette_Unused = {gObjectEventPal_Npc3, FLDEFF_PAL_TAG_UNKNOWN};

// cave dust
static const struct SpriteFrameImage sPicTable_CaveDust[] =
{
    overworld_ascending_frames(gFieldEffectObjectPic_CaveDust, 2, 2),
};
const struct SpriteTemplate gFieldEffectObjectTemplate_CaveDust = {
    .tileTag = 0xFFFF,
    .paletteTag = FLDEFF_PAL_TAG_CAVE_DUST,
    .oam = &gObjectEventBaseOam_16x16,
    .anims = sAnimTable_WaterSurfacing,
    .images = sPicTable_CaveDust,
    .callback = WaitFieldEffectSpriteAnim,
};

const struct SpritePalette gSpritePalette_CaveDust = {gFieldEffectObjectPalette_CaveDust, FLDEFF_PAL_TAG_CAVE_DUST};
static const struct SpriteFrameImage sPicTable_RockClimbBlob[] = {
    overworld_frame(gFieldEffectObjectPic_RockClimbBlob, 4, 4, 1),
    overworld_frame(gFieldEffectObjectPic_RockClimbBlob, 4, 4, 0),
    overworld_frame(gFieldEffectObjectPic_RockClimbBlob, 4, 4, 2),
};

const struct SpriteTemplate gFieldEffectObjectTemplate_RockClimbBlob = {
    .tileTag = 0xFFFF,
    .paletteTag = 0xFFFF,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sAnimTable_SurfBlob,
    .images = sPicTable_RockClimbBlob,
    .callback = UpdateSurfBlobFieldEffect,
};


static const union AnimCmd sAnim_RockClimbDust[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnimTable_RockClimbDust[] =
{
    sAnim_RockClimbDust,
};
static const struct SpriteFrameImage sPicTable_RockClimbDust[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_RockClimbDust, 4, 4),
};
const struct SpriteTemplate gFieldEffectObjectTemplate_RockClimbDust = {
    .tileTag = 0xFFFF,
    .paletteTag = FLDEFF_PAL_TAG_DUST_CLOUD,
    .oam = &gObjectEventBaseOam_32x32,
    .anims = sAnimTable_RockClimbDust,
    .images = sPicTable_RockClimbDust,
    .callback = UpdateJumpImpactEffect,
};

const struct SpritePalette gSpritePalette_BigDust = {gFieldEffectPal_DustCloud, FLDEFF_PAL_TAG_DUST_CLOUD};

static const struct SpriteFrameImage sPicTable_ShinySparkle[] = {
    overworld_ascending_frames(gFieldEffectObjectPic_ShinySparkle, 2, 4),
};

static const union AnimCmd sAnim_ShinySparkle[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 6),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimTable_ShinySparkle[] =
{
    sAnim_ShinySparkle,
};

const struct SpriteTemplate gFieldEffectObjectTemplate_ShinySparkle = {
    .tileTag = TAG_NONE,
    .paletteTag = FLDEFF_PAL_TAG_GENERAL_0,
    .oam = &gObjectEventBaseOam_16x32,
    .anims = sAnimTable_ShinySparkle,
    .images = sPicTable_ShinySparkle,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateBubblesFieldEffect,
};
