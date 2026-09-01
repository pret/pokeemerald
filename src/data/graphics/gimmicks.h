// trigger data
static const u8 ALIGNED(4) sMegaTriggerGfx[] = INCGFX_U8("graphics/battle_interface/mega_trigger.png", ".4bpp");
static const u8 ALIGNED(4) sZMoveTriggerGfx[] = INCGFX_U8("graphics/battle_interface/z_move_trigger.png", ".4bpp");
static const u8 ALIGNED(4) sBurstTriggerGfx[] = INCGFX_U8("graphics/battle_interface/burst_trigger.png", ".4bpp");
static const u8 ALIGNED(4) sDynamaxTriggerGfx[] = INCGFX_U8("graphics/battle_interface/dynamax_trigger.png", ".4bpp");
static const u8 ALIGNED(4) sTeraTriggerGfx[] = INCGFX_U8("graphics/battle_interface/tera_trigger.png", ".4bpp");

static const u16 sMegaTriggerPal[] = INCGFX_U16("graphics/battle_interface/mega_trigger.png", ".gbapal");
static const u16 sZMoveTriggerPal[] = INCGFX_U16("graphics/battle_interface/z_move_trigger.png", ".gbapal");
static const u16 sBurstTriggerPal[] = INCGFX_U16("graphics/battle_interface/burst_trigger.png", ".gbapal");
static const u16 sDynamaxTriggerPal[] = INCGFX_U16("graphics/battle_interface/dynamax_trigger.png", ".gbapal");
static const u16 sTeraTriggerPal[] = INCGFX_U16("graphics/battle_interface/tera_trigger.png", ".gbapal");

static const struct SpriteSheet sSpriteSheet_MegaTrigger = {sMegaTriggerGfx, sizeof(sMegaTriggerGfx), TAG_GIMMICK_TRIGGER_TILE};
static const struct SpriteSheet sSpriteSheet_ZMoveTrigger = {sZMoveTriggerGfx, sizeof(sZMoveTriggerGfx), TAG_GIMMICK_TRIGGER_TILE};
static const struct SpriteSheet sSpriteSheet_BurstTrigger = {sBurstTriggerGfx, sizeof(sBurstTriggerGfx), TAG_GIMMICK_TRIGGER_TILE};
static const struct SpriteSheet sSpriteSheet_DynamaxTrigger = {sDynamaxTriggerGfx, sizeof(sDynamaxTriggerGfx), TAG_GIMMICK_TRIGGER_TILE};
static const struct SpriteSheet sSpriteSheet_TeraTrigger = {sTeraTriggerGfx, sizeof(sTeraTriggerGfx), TAG_GIMMICK_TRIGGER_TILE};

static const struct SpritePalette sSpritePalette_MegaTrigger = {sMegaTriggerPal, TAG_GIMMICK_TRIGGER_TILE};
static const struct SpritePalette sSpritePalette_ZMoveTrigger = {sZMoveTriggerPal, TAG_GIMMICK_TRIGGER_PAL};
static const struct SpritePalette sSpritePalette_BurstTrigger = {sBurstTriggerPal, TAG_GIMMICK_TRIGGER_TILE};
static const struct SpritePalette sSpritePalette_DynamaxTrigger = {sDynamaxTriggerPal, TAG_GIMMICK_TRIGGER_PAL};
static const struct SpritePalette sSpritePalette_TeraTrigger = {sTeraTriggerPal, TAG_GIMMICK_TRIGGER_TILE};

static const struct OamData sOamData_GimmickTrigger =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_GimmickTriggerOff[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_GimmickTriggerOn[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_GimmickTrigger[] =
{
    sSpriteAnim_GimmickTriggerOff,
    sSpriteAnim_GimmickTriggerOn,
};

static void SpriteCb_GimmickTrigger(struct Sprite *sprite);
static const struct SpriteTemplate sSpriteTemplate_GimmickTrigger =
{
    .tileTag = TAG_GIMMICK_TRIGGER_TILE,
    .paletteTag = TAG_GIMMICK_TRIGGER_PAL,
    .oam = &sOamData_GimmickTrigger,
    .anims = sSpriteAnimTable_GimmickTrigger,
    .callback = SpriteCb_GimmickTrigger,
};

// indicator data
static const u8 ALIGNED(4) sMegaIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/mega_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sAlphaIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/alpha_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sOmegaIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/omega_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sDynamaxIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/dynamax_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sNormalIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/normal_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sFightingIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/fighting_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sFlyingIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/flying_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sPoisonIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/poison_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sGroundIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/ground_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sRockIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/rock_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sBugIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/bug_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sGhostIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/ghost_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sSteelIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/steel_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sFireIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/fire_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sWaterIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/water_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sGrassIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/grass_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sElectricIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/electric_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sPsychicIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/psychic_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sIceIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/ice_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sDragonIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/dragon_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sDarkIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/dark_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sFairyIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/fairy_indicator.png", ".4bpp");
static const u8 ALIGNED(4) sStellarIndicatorGfx[] = INCGFX_U8("graphics/battle_interface/stellar_indicator.png", ".4bpp");

static const u16 sMiscIndicatorPal[] = INCGFX_U16("graphics/battle_interface/misc_indicator.pal", ".gbapal"); // has room for more colors
static const u16 sMegaIndicatorPal[] = INCGFX_U16("graphics/battle_interface/mega_indicator.png", ".gbapal");
static const u16 sTeraIndicatorPal[] = INCGFX_U16("graphics/battle_interface/tera_indicator.pal", ".gbapal");

static const u8 *const sTeraIndicatorDataPtrs[] =
{
    sNormalIndicatorGfx,
    sNormalIndicatorGfx,
    sFightingIndicatorGfx,
    sFlyingIndicatorGfx,
    sPoisonIndicatorGfx,
    sGroundIndicatorGfx,
    sRockIndicatorGfx,
    sBugIndicatorGfx,
    sGhostIndicatorGfx,
    sSteelIndicatorGfx,
    sNormalIndicatorGfx,
    sFireIndicatorGfx,
    sWaterIndicatorGfx,
    sGrassIndicatorGfx,
    sElectricIndicatorGfx,
    sPsychicIndicatorGfx,
    sIceIndicatorGfx,
    sDragonIndicatorGfx,
    sDarkIndicatorGfx,
    sFairyIndicatorGfx,
    sStellarIndicatorGfx,
};

static const struct SpritePalette sSpritePalette_MiscIndicator = {sMiscIndicatorPal, TAG_MISC_INDICATOR_PAL};
static const struct SpritePalette sSpritePalette_MegaIndicator = {sMegaIndicatorPal, TAG_MEGA_INDICATOR_PAL};
static const struct SpritePalette sSpritePalette_TeraIndicator = {sTeraIndicatorPal, TAG_TERA_INDICATOR_PAL};

static const struct OamData sOamData_GimmickIndicator =
{
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 1,
};

static void SpriteCb_GimmickIndicator(struct Sprite *sprite);

#define BATTLER_INDICATOR_TAG 0xDEDE
static const struct SpriteSheet sBattler_GimmickSpritesheets[] =
{
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), BATTLER_INDICATOR_TAG},
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), BATTLER_INDICATOR_TAG+1},
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), BATTLER_INDICATOR_TAG+2},
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), BATTLER_INDICATOR_TAG+3},
};

static const struct SpriteTemplate sSpriteTemplate_BattlerIndicators[] =
{
    [0] =
    {
        .tileTag = BATTLER_INDICATOR_TAG,   // updated dynamically
        .paletteTag = TAG_TERA_INDICATOR_PAL,   // updated dynamically
        .oam = &sOamData_GimmickIndicator,
        .callback = SpriteCb_GimmickIndicator,
    },
    [1] =
    {
        .tileTag = BATTLER_INDICATOR_TAG + 1,   // updated dynamically
        .paletteTag = TAG_TERA_INDICATOR_PAL,   // updated dynamically
        .oam = &sOamData_GimmickIndicator,
        .callback = SpriteCb_GimmickIndicator,
    },
    [2] =
    {
        .tileTag = BATTLER_INDICATOR_TAG + 2,   // updated dynamically
        .paletteTag = TAG_TERA_INDICATOR_PAL,   // updated dynamically
        .oam = &sOamData_GimmickIndicator,
        .callback = SpriteCb_GimmickIndicator,
    },
    [3] =
    {
        .tileTag = BATTLER_INDICATOR_TAG + 3,   // updated dynamically
        .paletteTag = TAG_TERA_INDICATOR_PAL,   // updated dynamically
        .oam = &sOamData_GimmickIndicator,
        .callback = SpriteCb_GimmickIndicator,
    },
};
