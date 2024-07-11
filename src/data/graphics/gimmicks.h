// trigger data
static const u8 ALIGNED(4) sMegaTriggerGfx[] = INCBIN_U8("graphics/battle_interface/mega_trigger.4bpp");
static const u8 ALIGNED(4) sZMoveTriggerGfx[] = INCBIN_U8("graphics/battle_interface/z_move_trigger.4bpp");
static const u8 ALIGNED(4) sBurstTriggerGfx[] = INCBIN_U8("graphics/battle_interface/burst_trigger.4bpp");
static const u8 ALIGNED(4) sDynamaxTriggerGfx[] = INCBIN_U8("graphics/battle_interface/dynamax_trigger.4bpp");
static const u8 ALIGNED(4) sTeraTriggerGfx[] = INCBIN_U8("graphics/battle_interface/tera_trigger.4bpp");

static const u16 sMegaTriggerPal[] = INCBIN_U16("graphics/battle_interface/mega_trigger.gbapal");
static const u16 sZMoveTriggerPal[] = INCBIN_U16("graphics/battle_interface/z_move_trigger.gbapal");
static const u16 sBurstTriggerPal[] = INCBIN_U16("graphics/battle_interface/burst_trigger.gbapal");
static const u16 sDynamaxTriggerPal[] = INCBIN_U16("graphics/battle_interface/dynamax_trigger.gbapal");
static const u16 sTeraTriggerPal[] = INCBIN_U16("graphics/battle_interface/tera_trigger.gbapal");

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
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_GimmickTrigger,
};

// indicator data
static const u8 ALIGNED(4) sMegaIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/mega_indicator.4bpp");
static const u8 ALIGNED(4) sAlphaIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/alpha_indicator.4bpp");
static const u8 ALIGNED(4) sOmegaIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/omega_indicator.4bpp");
static const u8 ALIGNED(4) sDynamaxIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/dynamax_indicator.4bpp");
static const u8 ALIGNED(4) sNormalIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/normal_indicator.4bpp");
static const u8 ALIGNED(4) sFightingIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/fighting_indicator.4bpp");
static const u8 ALIGNED(4) sFlyingIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/flying_indicator.4bpp");
static const u8 ALIGNED(4) sPoisonIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/poison_indicator.4bpp");
static const u8 ALIGNED(4) sGroundIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/ground_indicator.4bpp");
static const u8 ALIGNED(4) sRockIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/rock_indicator.4bpp");
static const u8 ALIGNED(4) sBugIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/bug_indicator.4bpp");
static const u8 ALIGNED(4) sGhostIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/ghost_indicator.4bpp");
static const u8 ALIGNED(4) sSteelIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/steel_indicator.4bpp");
static const u8 ALIGNED(4) sFireIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/fire_indicator.4bpp");
static const u8 ALIGNED(4) sWaterIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/water_indicator.4bpp");
static const u8 ALIGNED(4) sGrassIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/grass_indicator.4bpp");
static const u8 ALIGNED(4) sElectricIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/electric_indicator.4bpp");
static const u8 ALIGNED(4) sPsychicIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/psychic_indicator.4bpp");
static const u8 ALIGNED(4) sIceIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/ice_indicator.4bpp");
static const u8 ALIGNED(4) sDragonIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/dragon_indicator.4bpp");
static const u8 ALIGNED(4) sDarkIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/dark_indicator.4bpp");
static const u8 ALIGNED(4) sFairyIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/fairy_indicator.4bpp");
static const u8 ALIGNED(4) sStellarIndicatorGfx[] = INCBIN_U8("graphics/battle_interface/stellar_indicator.4bpp");

static const u16 sMiscIndicatorPal[] = INCBIN_U16("graphics/battle_interface/misc_indicator.gbapal"); // has room for more colors
static const u16 sMegaIndicatorPal[] = INCBIN_U16("graphics/battle_interface/mega_indicator.gbapal");
static const u16 sTeraIndicatorPal[] = INCBIN_U16("graphics/battle_interface/tera_indicator.gbapal");

static const struct SpriteSheet sSpriteSheet_MegaIndicator = {sMegaIndicatorGfx, sizeof(sMegaIndicatorGfx), TAG_MEGA_INDICATOR_TILE};
static const struct SpriteSheet sSpriteSheet_AlphaIndicator = {sAlphaIndicatorGfx, sizeof(sAlphaIndicatorGfx), TAG_ALPHA_INDICATOR_TILE};
static const struct SpriteSheet sSpriteSheet_OmegaIndicator = {sOmegaIndicatorGfx, sizeof(sOmegaIndicatorGfx), TAG_OMEGA_INDICATOR_TILE};
static const struct SpriteSheet sSpriteSheet_DynamaxIndicator = {sDynamaxIndicatorGfx, sizeof(sDynamaxIndicatorGfx), TAG_DYNAMAX_INDICATOR_TILE};
static const struct SpriteSheet sTeraIndicatorSpriteSheets[NUMBER_OF_MON_TYPES + 1] =
{
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), TAG_NORMAL_INDICATOR_TILE},
    {sFightingIndicatorGfx, sizeof(sFightingIndicatorGfx), TAG_FIGHTING_INDICATOR_TILE},
    {sFlyingIndicatorGfx, sizeof(sFlyingIndicatorGfx), TAG_FLYING_INDICATOR_TILE},
    {sPoisonIndicatorGfx, sizeof(sPoisonIndicatorGfx), TAG_POISON_INDICATOR_TILE},
    {sGroundIndicatorGfx, sizeof(sGroundIndicatorGfx), TAG_GROUND_INDICATOR_TILE},
    {sRockIndicatorGfx, sizeof(sRockIndicatorGfx), TAG_ROCK_INDICATOR_TILE},
    {sBugIndicatorGfx, sizeof(sBugIndicatorGfx), TAG_BUG_INDICATOR_TILE},
    {sGhostIndicatorGfx, sizeof(sGhostIndicatorGfx), TAG_GHOST_INDICATOR_TILE},
    {sSteelIndicatorGfx, sizeof(sSteelIndicatorGfx), TAG_STEEL_INDICATOR_TILE},
    {sNormalIndicatorGfx, sizeof(sNormalIndicatorGfx), TAG_NORMAL_INDICATOR_TILE}, // TYPE_MYSTERY
    {sFireIndicatorGfx, sizeof(sFireIndicatorGfx), TAG_FIRE_INDICATOR_TILE},
    {sWaterIndicatorGfx, sizeof(sWaterIndicatorGfx), TAG_WATER_INDICATOR_TILE},
    {sGrassIndicatorGfx, sizeof(sGrassIndicatorGfx), TAG_GRASS_INDICATOR_TILE},
    {sElectricIndicatorGfx, sizeof(sElectricIndicatorGfx), TAG_ELECTRIC_INDICATOR_TILE},
    {sPsychicIndicatorGfx, sizeof(sPsychicIndicatorGfx), TAG_PSYCHIC_INDICATOR_TILE},
    {sIceIndicatorGfx, sizeof(sIceIndicatorGfx), TAG_ICE_INDICATOR_TILE},
    {sDragonIndicatorGfx, sizeof(sDragonIndicatorGfx), TAG_DRAGON_INDICATOR_TILE},
    {sDarkIndicatorGfx, sizeof(sDarkIndicatorGfx), TAG_DARK_INDICATOR_TILE},
    {sFairyIndicatorGfx, sizeof(sFairyIndicatorGfx), TAG_FAIRY_INDICATOR_TILE},
    {sStellarIndicatorGfx, sizeof(sStellarIndicatorGfx), TAG_STELLAR_INDICATOR_TILE},
    {0}
};

static const struct SpritePalette sSpritePalette_MiscIndicator = {sMiscIndicatorPal, TAG_MISC_INDICATOR_PAL};
static const struct SpritePalette sSpritePalette_MegaIndicator = {sMegaIndicatorPal, TAG_MEGA_INDICATOR_PAL};
static const struct SpritePalette sSpritePalette_TeraIndicator = {sTeraIndicatorPal, TAG_TERA_INDICATOR_PAL};

static const struct OamData sOamData_GimmickIndicator =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static void SpriteCb_GimmickIndicator(struct Sprite *sprite);
static const struct SpriteTemplate sSpriteTemplate_GimmickIndicator =
{
    .tileTag = TAG_NORMAL_INDICATOR_TILE,   // updated dynamically
    .paletteTag = TAG_TERA_INDICATOR_PAL,   // updated dynamically
    .oam = &sOamData_GimmickIndicator,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCb_GimmickIndicator,
};
