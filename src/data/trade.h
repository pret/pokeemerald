#define GFXTAG_MENU_TEXT       200 // Used as a base tag in CB2_CreateTradeMenu and CB2_ReturnToTradeMenu
#define GFXTAG_CURSOR          300
#define GFXTAG_LINK_MON_GLOW   5550
#define GFXTAG_LINK_MON_SHADOW 5552
#define GFXTAG_CABLE_END       5554
#define GFXTAG_GBA_SCREEN      5556
#define GFXTAG_POKEBALL        5557

#define PALTAG_CURSOR    2345
#define PALTAG_MENU_TEXT 4925
#define PALTAG_LINK_MON  5551
#define PALTAG_GBA       5555
#define PALTAG_POKEBALL  5558

// Exists unused in RS as well
static const u32 sUnusedStructSizes[] =
{
    sizeof(struct SaveBlock2),
    sizeof(struct SaveBlock1),
    sizeof(struct MapHeader),
 // 0x00000530, in RS
    sizeof(struct Mail),        //or ObjectEvent / ObjectEventGraphicsInfo
    sizeof(struct Pokemon),     //or TrainerCard
    0x00000528  // 0x000004D8, in RS
};

static const u16 sTradeMovesBoxTilemap[] = INCBIN_U16("graphics/trade/moves_box_map.bin");
static const u16 sTradePartyBoxTilemap[] = INCBIN_U16("graphics/trade/party_box_map.bin");
static const u8 sTradeStripesBG2Tilemap[] = INCBIN_U8("graphics/trade/stripes_bg2_map.bin");
static const u8 sTradeStripesBG3Tilemap[] = INCBIN_U8("graphics/trade/stripes_bg3_map.bin");
static const u8 sText_EmptyString[] = _("");
static const u8 sText_UnusedTextFormat[] = _("{COLOR WHITE}{HIGHLIGHT TRANSPARENT}{SHADOW DARK_GRAY}");
const u8 gText_MaleSymbol4[] = _("♂");
const u8 gText_FemaleSymbol4[] = _("♀");
const u8 gText_GenderlessSymbol[] = _("");
static const u8 sText_SpaceMove[] = _(" MOVE"); // unused
static const u8 sText_NewLine[] = _("\n");
static const u8 sText_Slash[] = _("/");
static const u8 sText_Lv[] = _("Lv. ");
static const u8 sText_ThreeDashes[] = _("---");
static const u8 sText_FourQuestionMarks[] = _("????");
static const u8 sText_UnusedEmpty[] = _("");
static const u8 sText_IsThisTradeOkay[] = _("Is this trade okay?");
static const u8 sText_Cancel[] = _("CANCEL");
static const u8 sText_ChooseAPkmn[] = _("Choose a POKéMON.");
static const u8 sText_Summary[] = _("SUMMARY");
static const u8 sText_Trade[] = _("TRADE");
static const u8 sText_CancelTrade[] = _("Cancel trade?");
static const u8 sJPText_PressBButtonToQuit[] = _("Bボタン　で　もどります");
static const u8 sText_Summary2[] = _("SUMMARY");
static const u8 sText_Trade2[] = _("TRADE");
static const u8 sText_CommunicationStandby[] = _("{COLOR DARK_GRAY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GRAY}Communication standby…\nPlease wait.");
static const u8 sText_TheTradeHasBeenCanceled[] = _("{COLOR DARK_GRAY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GRAY}The trade has\nbeen canceled.");
static const u8 sText_OnlyPkmnForBattle[] = _("That's your only\nPOKéMON for battle.");
static const u8 sText_WaitingForYourFriend[] = _("{COLOR DARK_GRAY}{HIGHLIGHT WHITE}{SHADOW LIGHT_GRAY}Waiting for your friend\nto finish…");
static const u8 sText_YourFriendWantsToTrade[] = _("Your friend wants\nto trade POKéMON.");

static const struct OamData sTradeOamData_32x16 =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1
};

static const struct OamData sOamData_Cursor =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd sAnim_Cursor_Normal[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cursor_OnCancel[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

enum {
    CURSOR_ANIM_NORMAL,
    CURSOR_ANIM_ON_CANCEL,
};

static const union AnimCmd *const sAnims_Cursor[] =
{
    [CURSOR_ANIM_NORMAL]    = sAnim_Cursor_Normal,
    [CURSOR_ANIM_ON_CANCEL] = sAnim_Cursor_OnCancel
};

static const struct SpriteSheet sCursor_SpriteSheet =
{
    .data = gTradeCursor_Gfx,
    .size = 0x800,
    .tag = GFXTAG_CURSOR
};

static const struct SpritePalette sCursor_SpritePalette =
{
    .data = gTradeCursor_Pal,
    .tag = PALTAG_CURSOR
};

static const union AnimCmd sAnim_MenuText_0[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MenuText_1[] =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MenuText_2[] =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MenuText_3[] =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MenuText_4[] =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MenuText_5[] =
{
    ANIMCMD_FRAME(40, 5),
    ANIMCMD_END
};

// These anims are not used
static const union AnimCmd *const sAnims_MenuText[] =
{
    sAnim_MenuText_0,
    sAnim_MenuText_1,
    sAnim_MenuText_2,
    sAnim_MenuText_3,
    sAnim_MenuText_4,
    sAnim_MenuText_5
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .oam = &sOamData_Cursor,
    .anims = sAnims_Cursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_MenuText =
{
    .tileTag = GFXTAG_MENU_TEXT,
    .paletteTag = PALTAG_MENU_TEXT,
    .oam = &sTradeOamData_32x16,
    .anims = sAnims_MenuText,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u16 TradeScreenTextPalette[] = INCBIN_U16("graphics/trade/text.gbapal");
static const struct SpritePalette gSpritePalette_TradeScreenText =
{
    .data = TradeScreenTextPalette,
    .tag = PALTAG_MENU_TEXT
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

static const u8 sUnusedCoords[][2] =
{
    { 0, 14},
    {15, 29},
    { 3,  5},
    { 3,  7},
    {18,  5},
    {18,  7},
    { 8,  7},
    {22, 12},
    { 8,  7},
    {22, 12},
    { 6,  7},
    {24, 12},
    { 6,  7},
    {24, 12},
    { 8,  7},
    {22, 12},
    { 7,  7},
    {23, 12}
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
    TEXT_COLOR_DARK_GRAY    //shadow color
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

static const u16 sPokeball_Pal[] = INCBIN_U16("graphics/trade/pokeball.gbapal");
static const u8 sPokeball_Gfx[] = INCBIN_U8("graphics/trade/pokeball.4bpp");
static const u8 sPokeballSymbol_Gfx[] = INCBIN_U8("graphics/trade/pokeball_symbol.8bpp"); // unused
static const u16 sCrossingHighlightCable_Tilemap[] = INCBIN_U16("graphics/trade/crossing_highlight_cable.bin");
static const u16 sTradeTilemap_PokeBallSymbol[] = INCBIN_U16("graphics/trade/pokeball_symbol_map.bin"); // unused?
static const u16 sUnusedPal1[] = INCBIN_U16("graphics/trade/unused1.gbapal");
static const u16 sGba_Pal[] = INCBIN_U16("graphics/trade/gba.gbapal");
static const u16 sUnusedPal2[] = INCBIN_U16("graphics/trade/unused2.gbapal");
static const u16 sWirelessSignalNone_Pal_Unused[] = INCBIN_U16("graphics/trade/wireless_signal_none.gbapal");
static const u16 sLinkMon_Pal[] = INCBIN_U16("graphics/trade/link_mon.gbapal");
static const u8 sLinkMonGlow_Gfx[] = INCBIN_U8("graphics/trade/link_mon_glow.4bpp");
static const u8 sLinkMonShadow_Gfx[] = INCBIN_U8("graphics/trade/link_mon_shadow.4bpp");
static const u8 sCableEnd_Gfx[] = INCBIN_U8("graphics/trade/cable_end.4bpp");
static const u8 sGbaScreen_Gfx[] = INCBIN_U8("graphics/trade/gba_screen.4bpp");
const u16 gTradePlatform_Tilemap[] = INCBIN_U16("graphics/trade/platform.bin");
static const u8 sGbaAffine_Gfx[] = INCBIN_U8("graphics/trade/gba_affine.8bpp"); // Only the gfx for when the GBA is zooming in/out
static const u8 sEmptyGfx[64] = {};
static const u8 sGbaCable_AffineTilemap[] = INCBIN_U8("graphics/trade/gba_affine_map_cable.bin");
static const u8 sGbaWireless_AffineTilemap[] = INCBIN_U8("graphics/trade/gba_affine_map_wireless.bin");
static const u16 sGbaWireless_Tilemap[] = INCBIN_U16("graphics/trade/gba_map_wireless.bin");
static const u16 sGbaCable_Tilemap[] = INCBIN_U16("graphics/trade/gba_map_cable.bin");
static const u32 sCrossingHighlightWireless_Tilemap[] = INCBIN_U32("graphics/trade/crossing_highlight_wireless.bin.lz");
static const u16 sWirelessSignalSend_Pal[] = INCBIN_U16("graphics/trade/wireless_signal_send.gbapal");
static const u16 sWirelessSignalRecv_Pal[] = INCBIN_U16("graphics/trade/wireless_signal_receive.gbapal");
static const u16 sWirelessSignalNone_Pal[] = INCBIN_U16("graphics/trade/wireless_signal_none.gbapal");
static const u32 sWirelessSignal_Gfx[] = INCBIN_U32("graphics/trade/wireless_signal.4bpp.lz");
static const u32 sWirelessSignal_Tilemap[] = INCBIN_U32("graphics/trade/wireless_signal.bin.lz");

static const struct OamData sOamData_Pokeball =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16)
};

static const union AnimCmd sAnim_Pokeball_SpinOnce[] =
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

static const union AnimCmd sAnim_Pokeball_SpinTwice[] =
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

static const union AnimCmd *const sAnims_Pokeball[] =
{
    sAnim_Pokeball_SpinOnce,
    sAnim_Pokeball_SpinTwice
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Normal[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Squish[] =
{
    AFFINEANIMCMD_FRAME(-8, 0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Unsquish[] =
{
    AFFINEANIMCMD_FRAME(0x60, 0x100, 0,  0),
    AFFINEANIMCMD_FRAME(   0,     0, 0,  5),
    AFFINEANIMCMD_FRAME(   8,     0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Pokeball[] =
{
    sAffineAnim_Pokeball_Normal,
    sAffineAnim_Pokeball_Squish,
    sAffineAnim_Pokeball_Unsquish
};

static const struct SpriteSheet sPokeBallSpriteSheet =
{
    .data = sPokeball_Gfx,
    .size = 0x600,
    .tag = GFXTAG_POKEBALL
};

static const struct SpritePalette sPokeBallSpritePalette =
{
    .data = sPokeball_Pal,
    .tag = PALTAG_POKEBALL
};

static const struct SpriteTemplate sSpriteTemplate_Pokeball =
{
    .tileTag = GFXTAG_POKEBALL,
    .paletteTag = PALTAG_POKEBALL,
    .oam = &sOamData_Pokeball,
    .anims = sAnims_Pokeball,
    .images = NULL,
    .affineAnims = sAffineAnims_Pokeball,
    .callback = SpriteCB_BouncingPokeball
};

static const struct OamData sOamData_LinkMonGlow =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1
};

static const union AnimCmd sAnim_LinkMonGlow[] =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE, .vFlip = TRUE), // ? The graphic is a perfect circle, no need to flip
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_LinkMonGlow[] =
{
    sAnim_LinkMonGlow
};

static const union AffineAnimCmd sAffineAnim_LinkMonGlow[] =
{
    AFFINEANIMCMD_FRAME(-10, -10, 0, 5),
    AFFINEANIMCMD_FRAME(10, 10, 0, 5),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sAffineAnims_LinkMonGlow[] =
{
    sAffineAnim_LinkMonGlow
};

static const struct SpriteSheet sSpriteSheet_LinkMonGlow =
{
    .data = sLinkMonGlow_Gfx,
    .size = 0x200,
    .tag = GFXTAG_LINK_MON_GLOW
};

static const struct SpritePalette sSpritePalette_LinkMon =
{
    .data = sLinkMon_Pal,
    .tag = PALTAG_LINK_MON
};

static const struct SpritePalette sSpritePalette_Gba =
{
    .data = sGba_Pal,
    .tag = PALTAG_GBA
};

static const struct SpriteTemplate sSpriteTemplate_LinkMonGlow =
{
    .tileTag = GFXTAG_LINK_MON_GLOW,
    .paletteTag = PALTAG_LINK_MON,
    .oam = &sOamData_LinkMonGlow,
    .anims = sAnims_LinkMonGlow,
    .images = NULL,
    .affineAnims = sAffineAnims_LinkMonGlow,
    .callback = SpriteCB_LinkMonGlow
};

static const struct OamData sOamData_LinkMonShadow =
{
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 1
};

static const union AnimCmd sAnim_LinkMonShadow_Big[] =
{
    ANIMCMD_FRAME(0, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_LinkMonShadow_Small[] =
{
    ANIMCMD_FRAME(8, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

enum {
    ANIM_LINKMON_BIG,
    ANIM_LINKMON_SMALL,
};

static const union AnimCmd *const sAnims_LinkMonShadow[] =
{
    [ANIM_LINKMON_BIG]   = sAnim_LinkMonShadow_Big,
    [ANIM_LINKMON_SMALL] = sAnim_LinkMonShadow_Small
};

static const struct SpriteSheet sSpriteSheet_LinkMonShadow =
{
    .data = sLinkMonShadow_Gfx,
    .size = 0x300,
    .tag = GFXTAG_LINK_MON_SHADOW
};

static const struct SpriteTemplate sSpriteTemplate_LinkMonShadow =
{
    .tileTag = GFXTAG_LINK_MON_SHADOW,
    .paletteTag = PALTAG_LINK_MON,
    .oam = &sOamData_LinkMonShadow,
    .anims = sAnims_LinkMonShadow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_LinkMonShadow
};

static const struct OamData sOamData_CableEnd =
{
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 1
};

static const union AnimCmd sAnim_CableEnd[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_CableEnd[] =
{
    sAnim_CableEnd
};

static const struct SpriteSheet sSpriteSheet_CableEnd =
{
    .data = sCableEnd_Gfx,
    .size = 0x100,
    .tag = GFXTAG_CABLE_END
};

static const struct SpriteTemplate sSpriteTemplate_CableEnd =
{
    .tileTag = GFXTAG_CABLE_END,
    .paletteTag = PALTAG_GBA,
    .oam = &sOamData_CableEnd,
    .anims = sAnims_CableEnd,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CableEndSending
};

static const struct OamData sOamData_GbaScreen =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd sAnim_GbaScreen_Long[] =
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

static const union AnimCmd sAnim_GbaScreen_Short[] =
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

static const union AnimCmd *const sAnims_GbaScreen_Long[] =
{
    sAnim_GbaScreen_Long
};

static const union AnimCmd *const sAnims_GbaScreen_Short[] =
{
    sAnim_GbaScreen_Short
};

static const struct SpriteSheet sSpriteSheet_GbaScreen =
{
    .data = sGbaScreen_Gfx,
    .size = 0x1000,
    .tag = GFXTAG_GBA_SCREEN
};

static const struct SpriteTemplate sSpriteTemplate_GbaScreenFlash_Long =
{
    .tileTag = GFXTAG_GBA_SCREEN,
    .paletteTag = PALTAG_GBA,
    .oam = &sOamData_GbaScreen,
    .anims = sAnims_GbaScreen_Long,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GbaScreen
};

static const struct SpriteTemplate sSpriteTemplate_GbaScreenFlash_Short =
{
    .tileTag = GFXTAG_GBA_SCREEN,
    .paletteTag = PALTAG_GBA,
    .oam = &sOamData_GbaScreen,
    .anims = sAnims_GbaScreen_Short,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GbaScreen
};

static const u16 sLinkMonShadow_Pal[] = INCBIN_U16("graphics/trade/link_mon_shadow.gbapal");

static const union AffineAnimCmd sAffineAnim_CrossingMonPic[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sAffineAnims_CrossingMonPics[] =
{
    sAffineAnim_CrossingMonPic
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
        EC_POKEMON_NATIONAL(MEOWTH),
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
     0,  0,  1,  0,  1,  0,  1,  1,  1,
     1,  2,  2,  2,  2,  3,  3,  3,  3,
     4,  4,  4,  4, -4, -4, -4, -3, -3,
    -3, -3, -2, -2, -2, -2, -1, -1, -1,
    -1,  0, -1,  0, -1,  0,  0,  0,  0,
     0,  1,  0,  1,  0,  1,  1,  1,  1,
     2,  2,  2,  2,  3,  3,  3,  3,  4,
     4,  4,  4, -4, -3, -3, -2, -2, -1,
    -1, -1,  0, -1,  0,  0,  0,  0,  0,
     0,  1,  0,  1,  1,  1,  2,  2,  3,
     3,  4, -4, -3, -2, -1, -1, -1,  0,
     0,  0,  0,  1,  0,  1,  1,  2,  3
};

static const u8 sWirelessSignalTiming[][2] =
{
    { 0,  1},
    { 1,  1},
    { 2,  1},
    { 3,  1},
    { 4,  1},
    { 5,  2},
    { 6,  2},
    { 7,  2},
    { 8,  2},
    { 9,  2},
    {10,  3},
    {11,  3},
    {12,  3},
    {13,  4},
    {14,  5},
    {15,  2},
    { 0,  1},
    { 1,  1},
    { 2,  1},
    { 3,  1},
    { 4,  1},
    { 5,  2},
    { 6,  2},
    { 7,  2},
    { 8,  2},
    { 9,  2},
    {10,  3},
    {11,  3},
    {12,  3},
    {13,  4},
    {14,  5},
    {16,  1},
    {16, -1},
    {}
};
