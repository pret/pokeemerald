// Exists unused in RS as well
static const u32 sUnusedStructSizes[] =
{
    sizeof(struct SaveBlock2),
    sizeof(struct SaveBlock1),
    sizeof(struct MapHeader),
 // 0x00000530, in RS
    sizeof(struct MailStruct),  //or ObjectEvent / ObjectEventGraphicsInfo
    sizeof(struct Pokemon),     //or TrainerCard
    0x00000528  // 0x000004D8, in RS
};

static const u16 sTradeMovesBoxTilemap[] = INCBIN_U16("graphics/trade/moves_box_map.bin");
static const u16 sTradePartyBoxTilemap[] = INCBIN_U16("graphics/trade/party_box_map.bin");
static const u8 sTradeStripesBG2Tilemap[] = INCBIN_U8("graphics/trade/stripes_bg2_map.bin");
static const u8 sTradeStripesBG3Tilemap[] = INCBIN_U8("graphics/trade/stripes_bg3_map.bin");
static const u8 sText_EmptyString[] = _("");
static const u8 sText_UnusedTextFormat[] = _("{COLOR WHITE}{HIGHLIGHT TRANSPARENT}{SHADOW DARK_GREY}");
const u8 gText_MaleSymbol4[] = _("♂");
const u8 gText_FemaleSymbol4[] = _("♀");
const u8 gText_GenderlessSymbol[] = _("");
static const u8 sText_SpaceMove[] = _(" MOVE"); // unused
static const u8 sText_NewLine[] = _("\n");
static const u8 sText_Slash[] = _("/");
static const u8 sText_Lv[] = _("Lv. ");
static const u8 sText_ThreeDashes[] = _("---");
static const u8 sText_FourQuestionMarks[] = _("????");
static const u8 sText_832DAE4[] = _("");
static const u8 sText_IsThisTradeOkay[] = _("Is this trade okay?");
static const u8 sText_Cancel[] = _("CANCEL");
static const u8 sText_ChooseAPkmn[] = _("Choose a POKéMON.");
static const u8 sText_Summary[] = _("SUMMARY");
static const u8 sText_Trade[] = _("TRADE");
static const u8 sText_CancelTrade[] = _("Cancel trade?");
static const u8 sJPText_PressBButtonToQuit[] = _("Bボタン　で　もどります");
static const u8 sText_Summary2[] = _("SUMMARY");
static const u8 sText_Trade2[] = _("TRADE");
static const u8 sText_CommunicationStandby[] = _("{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Communication standby…\nPlease wait.");
static const u8 sText_TheTradeHasBeenCanceled[] = _("{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}The trade has\nbeen canceled.");
static const u8 sText_OnlyPkmnForBattle[] = _("That's your only\nPOKéMON for battle.");
static const u8 sText_WaitingForYourFriend[] = _("{COLOR DARK_GREY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GREY}Waiting for your friend\nto finish…");
static const u8 sText_YourFriendWantsToTrade[] = _("Your friend wants\nto trade POKéMON.");

static const struct OamData sTradeOamData_32x16 =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1
};

static const struct OamData sTradeOamData_64x32 =
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

static const struct SpriteSheet sTradeButtonsSpriteSheet =
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
    .oam = &sTradeOamData_64x32,
    .anims = gSpriteAnimTable_832DC34,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteTemplate_832DCAC =
{
    .tileTag = 200,
    .paletteTag = 4925,
    .oam = &sTradeOamData_32x16,
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
// 1st array is the current positions
// 2nd array is directions of input
// 3rd array is the next positions to go to (unoccupied spaces are skipped over)
static const u8 sTradeNextSelectedMonTable[(PARTY_SIZE * 2) + 1][4][PARTY_SIZE] =
{
    {
        {4,  2,  12, 12, 0,  0}, // UP
        {2,  4,  12, 12, 0,  0}, // DOWN
        {7,  6,  1,  0,  0,  0}, // LEFT
        {1,  6,  7,  0,  0,  0}  // RIGHT
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

static const u8 sTradeMonSpriteCoords[(PARTY_SIZE * 2) + 1][2] =
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

static const u8 sTradeMonLevelCoords[][2][2] =
{
    // Your party
    {
        {5, 4},
        {12, 4},
    },
    {
        {5, 9},
        {12, 9},
    },
    {
        {5, 14},
        {12, 14},
    },
    // Friend's party
    {

        {20, 4},
        {27, 4},
    },
    {
        {20, 9},
        {27, 9},
    },
    {
        {20, 14},
        {27, 14},
    },
};

static const u8 sTradeMonBoxCoords[][2][2] =
{
    // Your party
    {
        {1, 3},
        {8, 3},
    },
    {
        {1, 8},
        {8, 8},
    },
    {
        {1, 13},
        {8, 13},
    },
    // Friend's party
    {
        {16, 3},
        {23, 3},
    },
    {
        {16, 8},
        {23, 8},
    },
    {
        {16, 13},
        {23, 13},
    },
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

static const u8 *const sTradeActionTexts[] =
{
    [TRADE_TEXT_CANCEL]       = sText_Cancel,
    [TRADE_TEXT_CHOOSE_MON]   = sText_ChooseAPkmn,
    [TRADE_TEXT_SUMMARY]      = sText_Summary,
    [TRADE_TEXT_TRADE]        = sText_Trade,
    [TRADE_TEXT_CANCEL_TRADE] = sText_CancelTrade,
    [TRADE_TEXT_JP_QUIT]      = sJPText_PressBButtonToQuit
};

static const struct MenuAction sSelectTradeMonActions[] =
{
    {sText_Summary2, Task_DrawSelectionSummary},
    {sText_Trade2,   Task_DrawSelectionTrade}
};

static const u8 *const sTradeMessages[] = 
{
    [TRADE_MSG_STANDBY]                    = sText_CommunicationStandby,
    [TRADE_MSG_CANCELED]                   = sText_TheTradeHasBeenCanceled,
    [TRADE_MSG_ONLY_MON1]                  = sText_OnlyPkmnForBattle,
    [TRADE_MSG_ONLY_MON2]                  = gText_OnlyPkmnForBattle, //identical text to above
    [TRADE_MSG_WAITING_FOR_FRIEND]         = sText_WaitingForYourFriend,
    [TRADE_MSG_FRIEND_WANTS_TO_TRADE]      = sText_YourFriendWantsToTrade,
    [TRADE_MSG_MON_CANT_BE_TRADED]         = gText_PkmnCantBeTradedNow,
    [TRADE_MSG_EGG_CANT_BE_TRADED]         = gText_EggCantBeTradedNow,
    [TRADE_MSG_FRIENDS_MON_CANT_BE_TRADED] = gText_OtherTrainersPkmnCantBeTraded
};

static const u8 sTradeTextColors[] = 
{ 
    TEXT_COLOR_TRANSPARENT, //bg color
    TEXT_COLOR_WHITE,       //fg color
    TEXT_COLOR_DARK_GREY    //shadow color
};

static const struct BgTemplate sTradeMenuBgTemplates[] =
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

static const struct WindowTemplate sTradeMenuWindowTemplates[] =
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

static const struct WindowTemplate sTradeYesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 13,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 582
};

static const u8 sJPText_Shedinja[] = _("ヌケニン");
static const u8 sTradeMenuPartyMonBoxDimensions[3][2] =
{
    [TRADE_PLAYER]  = {4,  3},
    [TRADE_PARTNER] = {19, 3}
};

static const u16 sTradePal_PokeBall[] = INCBIN_U16("graphics/trade/pokeball.gbapal");
static const u8 sTradeGfx_PokeBall[] = INCBIN_U8("graphics/trade/pokeball.4bpp");
static const u8 sTradeGfx_PokeBallSymbol[] = INCBIN_U8("graphics/trade/pokeball_symbol.8bpp"); // unused?
static const u16 sTradeTilemap_Cable[] = INCBIN_U16("graphics/trade/cable_closeup_map.bin");
static const u16 sTradeTilemap_PokeBallSymbol[] = INCBIN_U16("graphics/trade/pokeball_symbol_map.bin"); // unused?
static const u16 sUnref_083308C0[] = INCBIN_U16("graphics/trade/unknown_3308C0.gbapal");
static const u16 sTradePal_Gba[] = INCBIN_U16("graphics/trade/gba.gbapal");
static const u16 sTradePal_ShadowUnused[] = INCBIN_U16("graphics/trade/shadow.gbapal");
static const u16 sTradePal_BlackUnused[] = INCBIN_U16("graphics/trade/black.gbapal");
static const u16 sTradePal_Misc[] = INCBIN_U16("graphics/trade/misc.gbapal");
static const u8 sTradeGfx_Glow1[] = INCBIN_U8("graphics/trade/glow1.4bpp");
static const u8 sTradeGfx_Glow2[] = INCBIN_U8("graphics/trade/glow2.4bpp");
static const u8 sTradeGfx_CableEnd[] = INCBIN_U8("graphics/trade/cable_end.4bpp");
static const u8 sTradeGfx_GbaScreen[] = INCBIN_U8("graphics/trade/gba_screen.4bpp");
const u16 gUnknown_08331F60[] = INCBIN_U16("graphics/trade/shadow_map.bin");
static const u8 sTradeAffine_Gba[] = INCBIN_U8("graphics/trade/gba_affine.8bpp");
static const u8 sFiller_08335760[64] = {};
static const u8 sTradeAffineMap_GbaCable[] = INCBIN_U8("graphics/trade/gba_affine_map_cable.bin");
static const u8 sTradeAffineMap_GbaWireless[] = INCBIN_U8("graphics/trade/gba_affine_map_wireless.bin");
static const u16 sTradeTilemap_GbaWireless[] = INCBIN_U16("graphics/trade/gba_map_wireless.bin");
static const u16 sTradeTilemap_GbaCable[] = INCBIN_U16("graphics/trade/gba_map_cable.bin");
static const u32 gUnknown_083379A0[] = INCBIN_U32("graphics/trade/unknown_3379A0.bin.lz"); //some wireless tilemap
static const u16 sTradePal_WirelessSignalSend[] = INCBIN_U16("graphics/trade/wireless_signal_send.gbapal");
static const u16 sTradePal_WirelessSignalReceive[] = INCBIN_U16("graphics/trade/wireless_signal_receive.gbapal");
static const u16 sTradePal_Black[] = INCBIN_U16("graphics/trade/black.gbapal");
static const u32 sTradeGfx_WirelessSignal[] = INCBIN_U32("graphics/trade/wireless_signal.4bpp.lz");
static const u32 sTradeTilemap_WirelessSignal[] = INCBIN_U32("graphics/trade/wireless_signal.bin.lz");

static const struct OamData sTradeOamData_16x16 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
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

static const struct SpriteSheet sPokeBallSpriteSheet =
{
    .data = sTradeGfx_PokeBall,
    .size = 0x600,
    .tag = 5557
};

static const struct SpritePalette sPokeBallSpritePalette =
{
    .data = sTradePal_PokeBall,
    .tag = 5558
};

static const struct SpriteTemplate gSpriteTemplate_8338D28 =
{
    .tileTag = 5557,
    .paletteTag = 5558,
    .oam = &sTradeOamData_16x16,
    .anims = gSpriteAnimTable_8338C88,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_8338D0C,
    .callback = sub_807E55C
};

static const struct OamData sTradeOamData_32x32 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
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

static const struct SpriteSheet sGlow1SpriteSheet =
{
    .data = sTradeGfx_Glow1,
    .size = 0x200,
    .tag = 5550
};

static const struct SpritePalette sMiscTradeSpritePalette =
{
    .data = sTradePal_Misc,
    .tag = 5551
};

static const struct SpritePalette sGbaSpritePalette =
{
    .data = sTradePal_Gba,
    .tag = 5555
};

static const struct SpriteTemplate gUnknown_08338D88 =
{
    .tileTag = 5550,
    .paletteTag = 5551,
    .oam = &sTradeOamData_32x32,
    .anims = gSpriteAnimTable_8338D50,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_8338D6C,
    .callback = sub_807AA28
};

static const struct OamData sTradeOamData_16x32 =
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

static const struct SpriteSheet sGlow2SpriteSheet =
{
    .data = sTradeGfx_Glow2,
    .size = 0x300,
    .tag = 5552
};

static const struct SpriteTemplate sGlowBallSpriteTemplate =
{
    .tileTag = 5552,
    .paletteTag = 5551,
    .oam = &sTradeOamData_16x32,
    .anims = gSpriteAnimTable_8338DB8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807AA7C
};

static const struct OamData sTradeOamData_16x32_2 =
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

static const struct SpriteSheet sCableEndSpriteSheet =
{
    .data = sTradeGfx_CableEnd,
    .size = 0x100,
    .tag = 5554
};

static const struct SpriteTemplate gSpriteTemplate_8338DFC =
{
    .tileTag = 5554,
    .paletteTag = 5555,
    .oam = &sTradeOamData_16x32_2,
    .anims = gSpriteAnimTable_8338DF0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807AABC
};

static const struct OamData sTradeOamData_64x32_2 =
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

static const struct SpriteSheet sGbaScreenSpriteSheet =
{
    .data = sTradeGfx_GbaScreen,
    .size = 0x1000,
    .tag = 5556
};

static const struct SpriteTemplate gSpriteTemplate_8338E74 =
{
    .tileTag = 5556,
    .paletteTag = 5555,
    .oam = &sTradeOamData_64x32_2,
    .anims = gSpriteAnimTable_8338E64,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807AB04
};

static const struct SpriteTemplate gSpriteTemplate_8338E8C =
{
    .tileTag = 5556,
    .paletteTag = 5555,
    .oam = &sTradeOamData_64x32_2,
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

static const u16 sIngameTradeMail[][MAIL_WORDS_COUNT + 1] =
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

static const struct WindowTemplate sTradeSequenceWindowTemplates[] =
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

const struct WindowTemplate gTradeEvolutionSceneYesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 188
};

static const struct BgTemplate sTradeSequenceBgTemplates[] =
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

static const s8 sTradeBallVerticalVelocityTable[] =
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

static const u8 sWirelessSignalTiming[][2] =
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
    {16, 255},
    {0,  0}
};
