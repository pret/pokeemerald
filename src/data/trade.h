static const u32 sUnref_0832C6A8[] =
{
    0x00000F2C,
    0x00003D88,
    0x0000001C,
    0x00000024,
    0x00000064,
    0x00000528
};
static const u16 gTradeMovesBoxTilemap[] = INCBIN_U16("graphics/trade/moves_box_map.bin");
static const u16 gTradePartyBoxTilemap[] = INCBIN_U16("graphics/trade/party_box_map.bin");
static const u8 gTradeStripesBG2Tilemap[] = INCBIN_U8("graphics/trade/stripes_bg2_map.bin");
static const u8 gTradeStripesBG3Tilemap[] = INCBIN_U8("graphics/trade/stripes_bg3_map.bin");
static const u8 gText_EmptyString7[] = _("");
static const u8 gText_ClrWhtHltTrspntShdwDrkGry[] = _("{COLOR WHITE}{HIGHLIGHT TRANSPARENT}{SHADOW DARK_GREY}");
const u8 gText_MaleSymbol4[] = _("♂");
const u8 gText_FemaleSymbol4[] = _("♀");
const u8 gText_GenderlessSymbol[] = _("");
static const u8 gText_SpaceMove[] = _(" MOVE");
static const u8 gText_NewLine3[] = _("\n");
static const u8 gText_Slash2[] = _("/");
static const u8 gText_Lv2[] = _("Lv. ");
static const u8 gText_ThreeDashes2[] = _("---");
static const u8 gText_FourQuestionMarks[] = _("????");
static const u8 gText_832DAE4[] = _("");
static const u8 gText_IsThisTradeOkay[] = _("Is this trade okay?");
static const u8 gText_Cancel6[] = _("CANCEL");
static const u8 gText_ChooseAPkmn[] = _("Choose a POKéMON.");
static const u8 gText_Summary3[] = _("SUMMARY");
static const u8 gText_Trade2[] = _("TRADE");
static const u8 gText_CancelTrade[] = _("Cancel trade?");
static const u8 gJPText_832DB2E[] = _("Bボタン　で　もどります");
static const u8 gText_Summary4[] = _("SUMMARY");
static const u8 gText_Trade3[] = _("TRADE");
static const u8 gText_CommunicationStandby6[] = _("{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Communication standby…\nPlease wait.");
static const u8 gText_TheTradeHasBeenCanceled[] = _("{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}The trade has\nbeen canceled.");
static const u8 gText_YourOnlyPkmnForBattle[] = _("That's your only\nPOKéMON for battle.");
static const u8 gText_WaitingForYourFriend[] = _("{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Waiting for your friend\nto finish…");
static const u8 gText_YourFriendWantsToTrade[] = _("Your friend wants\nto trade POKéMON.");

static const struct OamData gOamData_832DC14 =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1
};

static const struct OamData gOamData_832DC1C =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd gSpriteAnim_832DC24[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_832DC2C[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_832DC34[] =
{
    gSpriteAnim_832DC24,
    gSpriteAnim_832DC2C
};

static const struct SpriteSheet gUnknown_0832DC3C =
{
    .data = gTradeButtons_Gfx,
    .size = 0x800,
    .tag = 300
};

static const struct SpritePalette gUnknown_0832DC44 =
{
    .data = gUnknown_08DDB444,
    .tag = 2345
};

static const union AnimCmd gSpriteAnim_832DC4C[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_832DC54[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_832DC5C[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_832DC64[] =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_832DC6C[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_832DC74[] =
{
    ANIMCMD_FRAME(40, 5),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_832DC7C[] =
{
    gSpriteAnim_832DC4C,
    gSpriteAnim_832DC54,
    gSpriteAnim_832DC5C,
    gSpriteAnim_832DC64,
    gSpriteAnim_832DC6C,
    gSpriteAnim_832DC74
};

static const struct SpriteTemplate gSpriteTemplate_832DC94 =
{
    .tileTag = 300,
    .paletteTag = 2345,
    .oam = &gOamData_832DC1C,
    .anims = gSpriteAnimTable_832DC34,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteTemplate_832DCAC =
{
    .tileTag = 200,
    .paletteTag = 4925,
    .oam = &gOamData_832DC14,
    .anims = gSpriteAnimTable_832DC7C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u16 TradeScreenTextPalette[] = INCBIN_U16("graphics/trade/text.gbapal");
static const struct SpritePalette gSpritePalette_TradeScreenText =
{
    .data = TradeScreenTextPalette,
    .tag = 4925
};

// This is used to determine the next mon to select when the D-Pad is
// pressed in a given direction.
// Note that the mons are laid out like this.
// 0-5 are the player's party and 6-11 are the trading partner's party.
// 12 is the cancel button.
//  0  1  6  7
//  2  3  8  9
//  4  5 10 11
//          12
static const u8 gTradeNextSelectedMonTable[][4][6] =
{
    {
        {4,  2,  12, 12, 0,  0},
        {2,  4,  12, 12, 0,  0},
        {7,  6,  1,  0,  0,  0},
        {1,  6,  7,  0,  0,  0}
    },
    {
        {5,  3,  12, 12, 0,  0},
        {3,  5,  12, 12, 0,  0},
        {0,  7,  6,  1,  0,  0},
        {6,  7,  0,  1,  0,  0}
    },
    {
        {0,  0,  0,  0,  0,  0},
        {4,  0,  0,  0,  0,  0},
        {9,  8,  7,  6,  0,  0},
        {3,  1,  0,  0,  0,  0}
    },
    {
        {1,  1,  1,  1,  0,  0},
        {5,  1,  1,  1,  0,  0},
        {2,  9,  8,  7,  0,  0},
        {8,  9,  6,  6,  0,  0}
    },
    {
        {2,  2,  2,  2,  0,  0},
        {0,  0,  0,  0,  0,  0},
        {11, 10, 9,  8,  7,  6},
        {5,  3,  1,  0,  0,  0}
    },
    {
        {3,  3,  3,  3,  0,  0},
        {1,  1,  1,  1,  0,  0},
        {4,  4,  4,  4,  0,  0},
        {10, 8,  6,  0,  0,  0}
    },
    {
        {10, 8,  12, 0,  0,  0},
        {8,  10, 12, 0,  0,  0},
        {1,  0,  0,  0,  0,  0},
        {7,  0,  1,  0,  0,  0}
    },
    {
        {12, 0,  0,  0,  0,  0},
        {9,  12, 0,  0,  0,  0},
        {6,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0}
    },
    {
        {6,  0,  0,  0,  0,  0},
        {10, 6,  0,  0,  0,  0},
        {3,  2,  1,  0,  0,  0},
        {9,  7,  0,  0,  0,  0}
    },
    {
        {7,  0,  0,  0,  0,  0},
        {11, 12, 0,  0,  0,  0},
        {8,  0,  0,  0,  0,  0},
        {2,  1,  0,  0,  0,  0}
    },
    {
        {8,  0,  0,  0,  0,  0},
        {6,  0,  0,  0,  0,  0},
        {5,  4,  3,  2,  1,  0},
        {11, 9,  7,  0,  0,  0}
    },
    {
        {9,  0,  0,  0,  0,  0},
        {12, 0,  0,  0,  0,  0},
        {10, 0,  0,  0,  0,  0},
        {4,  2,  0,  0,  0,  0}
    },
    {
        {11, 9,  7,  6,  0,  0},
        {7,  6,  0,  0,  0,  0},
        {12, 0,  0,  0,  0,  0},
        {12, 0,  0,  0,  0,  0}
    }
};

static const u8 gTradeMonSpriteCoords[][2] =
{
    // Your party
    {1,  5 },
    {8,  5 },
    {1,  10},
    {8,  10},
    {1,  15},
    {8,  15},

    // Friend's party
    {16, 5 },
    {23, 5 },
    {16, 10},
    {23, 10},
    {16, 15},
    {23, 15},

    {23, 18} // CANCEL
};

static const u8 gTradeLevelDisplayCoords[][6][2] =
{
    {
        // Your party
        {5, 4},
        {12, 4},
        {5, 9},
        {12, 9},
        {5, 14},
        {12, 14},
    },
    {
        // Friend's party
        {20, 4},
        {27, 4},
        {20, 9},
        {27, 9},
        {20, 14},
        {27, 14}
    }
};

static const u8 gTradeMonBoxCoords[][6][2] =
{
    {
        // Your party
        {1, 3},
        {8, 3},
        {1, 8},
        {8, 8},
        {1, 13},
        {8, 13},
    },
    {
        // Friend's party
        {16, 3},
        {23, 3},
        {16, 8},
        {23, 8},
        {16, 13},
        {23, 13}
    }
};

static const u8 sUnref_0832DE6E[] =
{
    0x00, 0x0e,
    0x0f, 0x1d,
    0x03, 0x05,
    0x03, 0x07,
    0x12, 0x05,
    0x12, 0x07,
    0x08, 0x07,
    0x16, 0x0c,
    0x08, 0x07,
    0x16, 0x0c,
    0x06, 0x07,
    0x18, 0x0c,
    0x06, 0x07,
    0x18, 0x0c,
    0x08, 0x07,
    0x16, 0x0c,
    0x07, 0x07,
    0x17, 0x0c
};

static const u8 *const gUnknown_0832DE94[] =
{
    gText_Cancel6,
    gText_ChooseAPkmn,
    gText_Summary3,
    gText_Trade2,
    gText_CancelTrade,
    gJPText_832DB2E
};

static const struct MenuAction gUnknown_0832DEAC[] =
{
    {gText_Summary4, sub_807A000},
    {gText_Trade3, sub_807A024}
};

static const u8 *const gUnknown_0832DEBC[] = {
    gText_CommunicationStandby6,
    gText_TheTradeHasBeenCanceled,
    gText_YourOnlyPkmnForBattle,
    gText_OnlyPkmnForBattle,
    gText_WaitingForYourFriend,
    gText_YourFriendWantsToTrade,
    gText_PkmnCantBeTradedNow,
    gText_EggCantBeTradedNow,
    gText_OtherTrainersPkmnCantBeTraded
};

static const u8 gUnknown_0832DEE0[] = { 0, 1, 2 };

static const struct BgTemplate gUnknown_0832DEE4[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const struct WindowTemplate gUnknown_0832DEF4[] =
{
    {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 7,
        .width = 22,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 30
    },
    {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 15,
        .width = 10,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 118
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 158
    },
    {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 174
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 190
    },
    {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 206
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 15,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 222
    },
    {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 15,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 238
    },
    {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 254
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 5,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 270
    },
    {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 286
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 10,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 302
    },
    {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 15,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 318
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 15,
        .width = 8,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 334
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 14,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 350
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 8,
        .width = 11,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 378
    },
    {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 5,
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 466
    },
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 8,
        .width = 11,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 494
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate gUnknown_0832DF8C =
{
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 13,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 582
};

static const u8 gJPText_Shedinja[] = _("ヌケニン");
static const u8 gUnknown_0832DF99[][2] =
{
    {4,  3},
    {19, 3},
    {0,  0}
};

static const u16 gTradeBallPalette[] = INCBIN_U16("graphics/trade/ball.gbapal");
static const u8 gTradeBallTiles[] = INCBIN_U8("graphics/trade/ball.4bpp");
static const u8 gUnknown_832E5C0[] = INCBIN_U8("graphics/trade/pokeball_symbol.8bpp");
static const u16 gUnknown_0832FFC0[] = INCBIN_U16("graphics/trade/cable_closeup_map.bin");
static const u16 gUnknown_083307C0[] = INCBIN_U16("graphics/trade/pokeball_symbol_map.bin");
static const u16 sUnref_083308C0[] = INCBIN_U16("graphics/trade/unknown_3308C0.gbapal");
static const u16 gUnknown_083308E0[] = INCBIN_U16("graphics/trade/gba.gbapal");
static const u16 gUnref_08330900[] = INCBIN_U16("graphics/trade/shadow.gbapal");
static const u16 gUnref_08330920[] = INCBIN_U16("graphics/trade/black.gbapal");
static const u16 gUnknown_08330940[] = INCBIN_U16("graphics/trade/misc.gbapal");
static const u8 gTradeGlow1Tiles[] = INCBIN_U8("graphics/trade/glow1.4bpp");
static const u8 gTradeGlow2Tiles[] = INCBIN_U8("graphics/trade/glow2.4bpp");
static const u8 gTradeCableEndTiles[] = INCBIN_U8("graphics/trade/cable_end.4bpp");
static const u8 gTradeGBAScreenTiles[] = INCBIN_U8("graphics/trade/gba_screen.4bpp");
const u16 gUnknown_08331F60[] = INCBIN_U16("graphics/trade/shadow_map.bin");
static const u8 gUnknown_08332F60[] = INCBIN_U8("graphics/trade/gba_affine.8bpp");
static const u8 sFiller_08335760[64] = {};
static const u8 gUnknown_083357A0[] = INCBIN_U8("graphics/trade/gba_affine_map_cable.bin");
static const u8 gUnknown_083358A0[] = INCBIN_U8("graphics/trade/gba_affine_map_wireless.bin");
static const u16 gUnknown_083359A0[] = INCBIN_U16("graphics/trade/gba_map_wireless.bin");
static const u16 gUnknown_083369A0[] = INCBIN_U16("graphics/trade/gba_map_cable.bin");
static const u32 gUnknown_083379A0[] = INCBIN_U32("graphics/trade/unknown_3379A0.bin.lz");
static const u16 gUnknown_08337AA0[] = INCBIN_U16("graphics/trade/wireless_signal_send.gbapal");
static const u16 gUnknown_08337CA0[] = INCBIN_U16("graphics/trade/wireless_signal_receive.gbapal");
static const u16 gUnknown_08337EA0[] = INCBIN_U16("graphics/trade/black.gbapal");
static const u32 gUnknown_08337EC0[] = INCBIN_U32("graphics/trade/wireless_signal.4bpp.lz");
static const u32 gUnknown_08338550[] = INCBIN_U32("graphics/trade/wireless_signal.bin.lz");

static const struct OamData gOamData_8338C44 =
{
    .affineMode = 1,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16)
};

static const union AnimCmd gSpriteAnim_8338C4C[] =
{
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_FRAME( 4, 3),
    ANIMCMD_FRAME( 8, 3),
    ANIMCMD_FRAME(12, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(20, 3),
    ANIMCMD_FRAME(24, 3),
    ANIMCMD_FRAME(28, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(36, 3),
    ANIMCMD_FRAME(40, 3),
    ANIMCMD_FRAME(44, 3),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_8338C88[] =
{
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_FRAME( 4, 3),
    ANIMCMD_FRAME( 8, 3),
    ANIMCMD_FRAME(12, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(20, 3),
    ANIMCMD_FRAME(24, 3),
    ANIMCMD_FRAME(28, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(36, 3),
    ANIMCMD_FRAME(40, 3),
    ANIMCMD_FRAME(44, 3),
    ANIMCMD_LOOP(2),
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_8338C88[] =
{
    gSpriteAnim_8338C4C,
    gSpriteAnim_8338C88
};

static const union AffineAnimCmd gSpriteAffineAnim_8338CCC[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd gSpriteAffineAnim_8338CDC[] =
{
    AFFINEANIMCMD_FRAME(-8, 0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd gSpriteAffineAnim_8338CEC[] =
{
    AFFINEANIMCMD_FRAME(0x60, 0x100, 0,  0),
    AFFINEANIMCMD_FRAME(   0,     0, 0,  5),
    AFFINEANIMCMD_FRAME(   8,     0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_8338D0C[] =
{
    gSpriteAffineAnim_8338CCC,
    gSpriteAffineAnim_8338CDC,
    gSpriteAffineAnim_8338CEC
};

static const struct SpriteSheet gUnknown_08338D18 =
{
    .data = gTradeBallTiles,
    .size = 0x600,
    .tag = 5557
};

static const struct SpritePalette gUnknown_08338D20 =
{
    .data = gTradeBallPalette,
    .tag = 5558
};

static const struct SpriteTemplate gSpriteTemplate_8338D28 =
{
    .tileTag = 5557,
    .paletteTag = 5558,
    .oam = &gOamData_8338C44,
    .anims = gSpriteAnimTable_8338C88,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_8338D0C,
    .callback = sub_807E55C
};

static const struct OamData gOamData_8338D40 =
{
    .affineMode = 1,
    .objMode = 1,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1
};

static const union AnimCmd gSpriteAnim_8338D48[] =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_8338D50[] =
{
    gSpriteAnim_8338D48
};

static const union AffineAnimCmd gSpriteAffineAnim_8338D54[] =
{
    AFFINEANIMCMD_FRAME(-10, -10, 0, 5),
    AFFINEANIMCMD_FRAME(10, 10, 0, 5),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_8338D6C[] =
{
    gSpriteAffineAnim_8338D54
};

static const struct SpriteSheet gUnknown_08338D70 =
{
    .data = gTradeGlow1Tiles,
    .size = 0x200,
    .tag = 5550
};

static const struct SpritePalette gUnknown_08338D78 =
{
    .data = gUnknown_08330940,
    .tag = 5551
};

static const struct SpritePalette gUnknown_08338D80 =
{
    .data = gUnknown_083308E0,
    .tag = 5555
};

static const struct SpriteTemplate gUnknown_08338D88 =
{
    .tileTag = 5550,
    .paletteTag = 5551,
    .oam = &gOamData_8338D40,
    .anims = gSpriteAnimTable_8338D50,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_8338D6C,
    .callback = sub_807AA28
};

static const struct OamData gOamData_8338DA0 =
{
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 1
};

static const union AnimCmd gSpriteAnim_8338DA8[] =
{
    ANIMCMD_FRAME(0, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_8338DB0[] =
{
    ANIMCMD_FRAME(8, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_8338DB8[] =
{
    gSpriteAnim_8338DA8,
    gSpriteAnim_8338DB0
};

static const struct SpriteSheet gUnknown_08338DC0 =
{
    .data = gTradeGlow2Tiles,
    .size = 0x300,
    .tag = 5552
};

static const struct SpriteTemplate gSpriteTemplate_8338DC8 =
{
    .tileTag = 5552,
    .paletteTag = 5551,
    .oam = &gOamData_8338DA0,
    .anims = gSpriteAnimTable_8338DB8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807AA7C
};

static const struct OamData gOamData_8338DE0 =
{
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 1
};

static const union AnimCmd gSpriteAnim_8338DE8[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_8338DF0[] =
{
    gSpriteAnim_8338DE8
};

static const struct SpriteSheet gUnknown_08338DF4 =
{
    .data = gTradeCableEndTiles,
    .size = 0x100,
    .tag = 5554
};

static const struct SpriteTemplate gSpriteTemplate_8338DFC =
{
    .tileTag = 5554,
    .paletteTag = 5555,
    .oam = &gOamData_8338DE0,
    .anims = gSpriteAnimTable_8338DF0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807AABC
};

static const struct OamData gOamData_8338E14 =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd gSpriteAnim_8338E1C[] =
{
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_LOOP(8),
    ANIMCMD_END
};

static const union AnimCmd gSpriteAnim_8338E40[] =
{
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_LOOP(2),
    ANIMCMD_END
};

static const union AnimCmd *const gSpriteAnimTable_8338E64[] =
{
    gSpriteAnim_8338E1C
};

static const union AnimCmd *const gSpriteAnimTable_8338E68[] =
{
    gSpriteAnim_8338E40
};

static const struct SpriteSheet gUnknown_08338E6C =
{
    .data = gTradeGBAScreenTiles,
    .size = 0x1000,
    .tag = 5556
};

static const struct SpriteTemplate gSpriteTemplate_8338E74 =
{
    .tileTag = 5556,
    .paletteTag = 5555,
    .oam = &gOamData_8338E14,
    .anims = gSpriteAnimTable_8338E64,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807AB04
};

static const struct SpriteTemplate gSpriteTemplate_8338E8C =
{
    .tileTag = 5556,
    .paletteTag = 5555,
    .oam = &gOamData_8338E14,
    .anims = gSpriteAnimTable_8338E68,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807AB04
};

static const u16 gUnknown_08338EA4[] = INCBIN_U16("graphics/trade/unknown_338EA4.gbapal");

static const union AffineAnimCmd gSpriteAffineAnim_8338EBC[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_8338ECC[] =
{
    gSpriteAffineAnim_8338EBC
};

static const struct InGameTrade sIngameTrades[] =
{
    [INGAME_TRADE_SEEDOT] = 
    {
        .nickname = _("DOTS"), 
        .species = SPECIES_SEEDOT,
        .ivs = {5, 4, 5, 4, 4, 4},
        .abilityNum = 1, 
        .otId = 38726,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x84,
        .heldItem = ITEM_CHESTO_BERRY, 
        .mailNum = -1,
        .otName = _("KOBE"), 
        .otGender = MALE, 
        .sheen = 10,
        .requestedSpecies = SPECIES_RALTS
    }, 
    [INGAME_TRADE_PLUSLE] = 
    {
        .nickname = _("PLUSES"), 
        .species = SPECIES_PLUSLE,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0, 
        .otId = 73996,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x6F,
        .heldItem = ITEM_WOOD_MAIL, 
        .mailNum = 0,
        .otName = _("ROMAN"), 
        .otGender = MALE, 
        .sheen = 10,
        .requestedSpecies = SPECIES_VOLBEAT
    }, 
    [INGAME_TRADE_HORSEA] = 
    {
        .nickname = _("SEASOR"),
        .species = SPECIES_HORSEA,
        .ivs = {5, 4, 4, 4, 5, 4},
        .abilityNum = 0, 
        .otId = 46285,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x7F,
        .heldItem = ITEM_WAVE_MAIL, 
        .mailNum = 1,
        .otName = _("SKYLAR"), 
        .otGender = MALE, 
        .sheen = 10,
        .requestedSpecies = SPECIES_BAGON
    }, 
    [INGAME_TRADE_MEOWTH] = 
    {
        .nickname = _("MEOWOW"),
        .species = SPECIES_MEOWTH,
        .ivs = {4, 5, 4, 5, 4, 4},
        .abilityNum = 0, 
        .otId = 91481,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 0x8B,
        .heldItem = ITEM_RETRO_MAIL, 
        .mailNum = 2,
        .otName = _("ISIS"), 
        .otGender = FEMALE, 
        .sheen = 10,
        .requestedSpecies = SPECIES_SKITTY
    }
};

static const u16 gIngameTradeMail[][10] =
{
    {
        EC_WORD_BE,
        EC_WORD_NICE,
        EC_WORD_TO,
        EC_POKEMON(PLUSLE),
        EC_WORD_EXCL,
        EC_POKEMON(VOLBEAT),
        EC_WORD_WILL,
        EC_WORD_BE,
        EC_WORD_FANTASTIC
    }, {
        EC_WORD_I,
        EC_WORD_WILL,
        EC_WORD_MAKE,
        EC_POKEMON(BAGON),
        EC_WORD_TOUGH,
        EC_WORD_PLEASE,
        EC_WORD_TRAIN,
        EC_POKEMON(HORSEA),
        EC_WORD_WELL
    }, {
        EC_WORD_THANK_YOU,
        EC_WORD_FOR,
        EC_POKEMON(SKITTY),
        EC_POKEMON2(MEOWTH),
        EC_WORD_CRIES,
        EC_WORD_IN,
        EC_WORD_A,
        EC_WORD_CUTE,
        EC_WORD_WAY
    }
};

static const struct WindowTemplate gUnknown_08338FFC[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 64
    },
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_0833900C =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 188
};

static const struct BgTemplate gUnknown_08339014[] =
{
    {
        .bg = 0,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 18,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const s8 gTradeBallVerticalVelocityTable[] =
{
    0,  0,  1,  0,
    1,  0,  1,  1,
    1,  1,  2,  2,
    2,  2,  3,  3,
    3,  3,  4,  4,
    4,  4, -4, -4,
    -4, -3, -3, -3,
    -3, -2, -2, -2,
    -2, -1, -1, -1,
    -1,  0, -1,  0,
    -1,  0,  0,  0,
    0,  0,  1,  0,
    1,  0,  1,  1,
    1,  1,  2,  2,
    2,  2,  3,  3,
    3,  3,  4,  4,
    4,  4, -4, -3,
    -3, -2, -2, -1,
    -1, -1,  0, -1,
    0,  0,  0,  0,
    0,  0,  1,  0,
    1,  1,  1,  2,
    2,  3,  3,  4,
    -4, -3, -2, -1,
    -1, -1,  0,  0,
    0,  0,  1,  0,
    1,  1,  2,  3
};

static const u8 gUnknown_08339090[][2] =
{
    {0,  1},
    {1,  1},
    {2,  1},
    {3,  1},
    {4,  1},
    {5,  2},
    {6,  2},
    {7,  2},
    {8,  2},
    {9,  2},
    {10, 3},
    {11, 3},
    {12, 3},
    {13, 4},
    {14, 5},
    {15, 2},
    {0,  1},
    {1,  1},
    {2,  1},
    {3,  1},
    {4,  1},
    {5,  2},
    {6,  2},
    {7,  2},
    {8,  2},
    {9,  2},
    {10, 3},
    {11, 3},
    {12, 3},
    {13, 4},
    {14, 5},
    {16, 1},
    {16, -1},
    {0,  0}
};
