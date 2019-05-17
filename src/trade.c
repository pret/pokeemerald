#include "global.h"
#include "alloc.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "bg.h"
#include "cable_club.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "event_data.h"
#include "evolution_scene.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "mail.h"
#include "main.h"
#include "mevent2.h"
#include "mystery_gift.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "rom_8011DC0.h"
#include "save.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "trade.h"
#include "union_room.h"
#include "util.h"
#include "window.h"
#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define Trade_SendData(ptr) (SendBlock(bitmask_all_link_players_but_self(), ptr->linkData, 20))

struct InGameTrade {
    /*0x00*/ u8 name[11];
    /*0x0C*/ u16 species;
    /*0x0E*/ u8 ivs[6];
    /*0x14*/ bool8 secondAbility;
    /*0x18*/ u32 otId;
    /*0x1C*/ u8 stats[5];
    /*0x24*/ u32 personality;
    /*0x28*/ u16 heldItem;
    /*0x2A*/ u8 mailNum;
    /*0x2B*/ u8 otName[11];
    /*0x36*/ u8 otGender;
    /*0x37*/ u8 sheen;
    /*0x38*/ u16 playerSpecies;
};

static EWRAM_DATA u8 *gUnknown_02032184 = NULL;
static EWRAM_DATA u8 *gUnknown_02032188[14] = {NULL};
EWRAM_DATA struct MailStruct gUnknown_020321C0[PARTY_SIZE] = {0};
EWRAM_DATA u8 gUnknown_02032298[2] = {0};
static EWRAM_DATA struct {
    /*0x0000*/ u8 unk_0;
    /*0x0001*/ u8 unk_1;
    /*0x0002*/ u8 filler_2[0x28 - 2];
    /*0x0028*/ u8 partyIcons[2][PARTY_SIZE];
    /*0x0034*/ u8 tradeMenuCursorSpriteIdx;
    /*0x0035*/ u8 tradeMenuCursorPosition;
    /*0x0036*/ u8 partyCounts[2];
    /*0x0038*/ bool8 tradeMenuOptionsActive[12];
    /*0x0044*/ u8 unk_44;
    /*0x0045*/ u8 unk_45[2][PARTY_SIZE];
    /*0x0051*/ u8 unk_51[2][PARTY_SIZE];
    /*0x005D*/ u8 unk_5D[2][PARTY_SIZE];
    /*0x0069*/ u8 unk_69;
    /*0x006A*/ u8 filler_6A[0x6F - 0x6A];
    /*0x006F*/ u8 unk_6F;
    /*0x0070*/ u8 unk_70;
    /*0x0071*/ u8 filler_71;
    /*0x0072*/ u16 unk_72;
    /*0x0074*/ u8 unk_74[2];
    /*0x0076*/ u8 unk_76[2];
    /*0x0078*/ u8 unk_78;
    /*0x0079*/ u8 unk_79;
    /*0x007A*/ u8 unk_7A;
    /*0x007B*/ u8 unk_7B;
    /*0x007C*/ u8 filler_7C[0x7E - 0x7C];
    /*0x007E*/ u8 unk_7E;
    /*0x007F*/ u8 filler_7F;
    /*0x0080*/ u16 linkData[20];
    /*0x00A8*/ u8 unk_A8;
    /*0x00A9*/ u8 unk_A9[11];
    /*0x00B4*/ u8 filler_B4[0x8D0-0xB4];
    /*0x08D0*/ struct {
        bool8 unk_0;
        u16 unk_2;
        u8 unk_4;
    } unk_8D0[4];
    /*0x08F0*/ u16 tilemapBuffer[0x400];
} *gUnknown_0203229C = {NULL};
static EWRAM_DATA struct {
    /*0x00*/ struct Pokemon mon;
    /*0x64*/ u32 timer;
    /*0x68*/ u32 unk_68[2];
    /*0x70*/ u8 filler_70[2];
    /*0x72*/ u8 unk_72;
    /*0x73*/ u8 unk_73;
    /*0x74*/ u16 linkData[10];
    /*0x88*/ u8 unk_88;
    /*0x89*/ u8 unk_89;
    /*0x8A*/ u16 unk_8A;
    /*0x8C*/ u16 unk_8C;
    /*0x8E*/ u8 pokePicSpriteIdxs[2];
    /*0x90*/ u8 unk_90;
    /*0x91*/ u8 unk_91;
    /*0x92*/ u8 unk_92;
    /*0x93*/ u8 unk_93;
    /*0x94*/ u16 state;
    /*0x96*/ u8 filler_96[0xD2 - 0x96];
    /*0xD2*/ u8 unk_D2;
    /*0xD3*/ u8 unk_D3;
    /*0xD4*/ u16 unk_D4;
    /*0xD6*/ u16 unk_D6;
    /*0xD8*/ u16 unk_D8;
    /*0xDA*/ u16 unk_DA;
    /*0xDC*/ u16 unk_DC;
    /*0xDE*/ u16 unk_DE;
    /*0xE0*/ s16 bg1vofs;
    /*0xE2*/ s16 bg1hofs;
    /*0xE4*/ s16 bg2vofs;
    /*0xE6*/ s16 bg2hofs;
    /*0xE8*/ u16 unk_E8;
    /*0xEA*/ u16 unk_EA;
    /*0xEC*/ u16 unk_EC;
    /*0xEE*/ bool8 isLinkTrade;
    /*0xF0*/ u16 tradeSpecies[2];
    /*0xF4*/ u16 cachedMapMusic;
    /*0xF6*/ u8 unk_F6[3];
    /*0xF9*/ u8 filler_F9;
    /*0xFA*/ u8 unk_FA;
    /*0xFB*/ u8 unk_FB;
    /*0xFC*/ u8 unk_FC;
    /*0xFD*/ u8 unk_FD;
    /*0xFE*/ u8 unk_FE;
} *gUnknown_020322A0 = {NULL};

static bool32 sub_8077260(void);
static void sub_80773D0(void);
static void sub_807811C(void);
static void sub_807825C(void);
static void sub_80782B8(u8);
static void sub_8078388(void);
static bool8 shedinja_maker_maybe(void);
static void sub_8078C34(void);
static void sub_80795AC(void);
static void sub_807967C(u8);
static void sub_80796B4(u8);
static u8 sub_8079A3C(u8 *, u8, u8);
static void sub_8079AA4(u8 *, u8, u8);
static void sub_8079BE0(u8);
static void sub_8079C4C(u8, u8, u8, u8, u8, u8);
static void sub_8079E44(u8);
static void sub_8079F74(void);
static void sub_8079F88(u8);
static void sub_807A000(u8 taskId);
static void sub_807A024(u8 taskId);
static void sub_807A048(u16, u8);
static u32 sub_807A09C(void);
static void sub_807A0C4(void);
static void sub_807A19C(u8);
static bool8 sub_807A1F0(void);
static void sub_807A308(const u8 *, u8 *, u8);
static void sub_807A320(u8);
static void sub_807A468(u8);
static void sub_807A53C(void);
static void sub_807A5B0(void);
static u32 sub_807A5F4(struct Pokemon *, int, int);
static void sub_807AA28(struct Sprite *sprite);
static void sub_807AA7C(struct Sprite *sprite);
static void sub_807AABC(struct Sprite *sprite);
static void sub_807AAE0(struct Sprite *sprite);
static void sub_807AB04(struct Sprite *sprite);
static void sub_807B170(void);
static void sub_807B60C(void);
static void sub_807B62C(u8);
static void sub_807BA94(void);
static void SetTradeSceneStrings(void);
static u8 sub_807BBC8(void);
static u8 sub_807BBEC(void);
static u8 sub_807CFC8(void);
static void sub_807E55C(struct Sprite *sprite);
static void sub_807E5D8(struct Sprite *sprite);
static void sub_807E64C(struct Sprite *sprite);
static void sub_807E6AC(struct Sprite *sprite);
static void sub_807E784(void);
static void sub_807E974(struct MailStruct *mail, const struct InGameTrade *trade);
static void sub_807EA2C(void);
static void sub_807EACC(void);
static void sub_807EB50(void);
static void c2_080543C4(void);
static void sub_807F110(u8);
static void sub_807F14C(void);
static void c3_08054588(u8);
static void c3_0805465C(u8);
static void sub_807F39C(u8);
static void sub_807F464(void);

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
    .data = gUnknown_08DDC6E4,
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

static const struct InGameTrade gIngameTrades[] =
{
    {
        _("DOTS"), SPECIES_SEEDOT,
        5, 4, 5, 4, 4, 4,
        TRUE, 38726,
        30, 5, 5, 5, 5,
        0x84,
        ITEM_CHESTO_BERRY, -1,
        _("KOBE"), MALE, 10,
        SPECIES_RALTS
    }, {
        _("PLUSES"), SPECIES_PLUSLE,
        4, 4, 4, 5, 5, 4,
        FALSE, 73996,
        5, 5, 30, 5, 5,
        0x6F,
        ITEM_WOOD_MAIL, 0,
        _("ROMAN"), MALE, 10,
        SPECIES_VOLBEAT
    }, {
        _("SEASOR"),
        SPECIES_HORSEA,
        5, 4, 4, 4, 5, 4,
        FALSE, 46285,
        5, 5, 5, 5, 30,
        0x7F,
        ITEM_WAVE_MAIL, 1,
        _("SKYLAR"), MALE, 10,
        SPECIES_BAGON
    }, {
        _("MEOWOW"),
        SPECIES_MEOWTH,
        4, 5, 4, 5, 4, 4,
        FALSE, 91481,
        5, 5, 5, 30, 5,
        0x8B,
        ITEM_RETRO_MAIL, 2,
        _("ISIS"), FEMALE, 10,
        SPECIES_SKITTY
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
        EC_WORD_FANTASTIC,
        0
    }, {
        EC_WORD_I,
        EC_WORD_WILL,
        EC_WORD_MAKE,
        EC_POKEMON(BAGON),
        EC_WORD_TOUGH,
        EC_WORD_PLEASE,
        EC_WORD_TRAIN,
        EC_POKEMON(HORSEA),
        EC_WORD_WELL,
        0
    }, {
        EC_WORD_THANK_YOU,
        EC_WORD_FOR,
        EC_POKEMON(SKITTY),
        EC_POKEMON2(MEOWTH),
        EC_WORD_CRIES,
        EC_WORD_IN,
        EC_WORD_A,
        EC_WORD_CUTE,
        EC_WORD_WAY,
        0
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

static bool8 sub_8077170(const void *a0, u32 a1)
{
    if (gUnknown_02022C2C == 29)
    {
        rfu_NI_setSendData(gUnknown_03004140.unk_00, 84, a0, a1);
        return TRUE;
    }
    else
    {
        return SendBlock(0, a0, a1);
    }
}

static void sub_80771AC(u8 a0)
{
    sub_800A4D8(a0);
}

static bool32 sub_80771BC(void)
{
    if (gUnknown_02022C2C == 29)
    {
        if (gUnknown_03007880[sub_800E87C(gUnknown_03004140.unk_00)]->unk_0 == 0)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return IsLinkTaskFinished();
    }
}

static u32 _GetBlockReceivedStatus(void)
{
    return GetBlockReceivedStatus();
}

static void sub_8077210(void)
{
    if (sub_8077260())
    {
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    }
    else
    {
        ResetBlockReceivedFlags();
    }
}

static void sub_8077234(u32 a0)
{
    if (sub_8077260())
    {
        rfu_clearSlot(12, gUnknown_03004140.unk_00);
    }
    else
    {
        ResetBlockReceivedFlag(a0);
    }
}

static bool32 sub_8077260(void)
{
    if (gWirelessCommType && gUnknown_02022C2C == 29)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void sub_8077288(u8 unused)
{
    sub_800ADF8();
}

static bool32 _IsLinkTaskFinished(void)
{
    return IsLinkTaskFinished();
}

static void sub_80772A4(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetPaletteFade();

    gPaletteFade.bufferTransferDisabled = TRUE;

    SetVBlankCallback(sub_807811C);
    LoadPalette(gUnknown_0860F074, 0xF0, 20);
    LoadPalette(gUnknown_0860F074, 0xD0, 20);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0832DEE4, ARRAY_COUNT(gUnknown_0832DEE4));
    SetBgTilemapBuffer(1, gUnknown_0203229C->tilemapBuffer);

    if (InitWindows(gUnknown_0832DEF4))
    {
        u32 i;

        DeactivateAllTextPrinters();

        for (i = 0; i < 18; i++)
        {
            ClearWindowTilemap(i);
            FillWindowPixelBuffer(i, PIXEL_FILL(0));
        }

        FillBgTilemapBufferRect(0, 0, 0, 0, 30, 20, 15);
        LoadUserWindowBorderGfx_(0, 20, 0xC0);
        LoadUserWindowBorderGfx(2, 1, 0xE0);
        LoadMonIconPalettes();
        gUnknown_0203229C->unk_69 = 0;
        gUnknown_0203229C->unk_6F = 0;
        gUnknown_0203229C->unk_70 = 0;
        gUnknown_0203229C->unk_74[0] = 0;
        gUnknown_0203229C->unk_74[1] = 0;
        gUnknown_0203229C->unk_7A = 0;
        gUnknown_0203229C->unk_7B = 0;
        gUnknown_0203229C->unk_A8 = 0;
    }
}

void sub_80773AC(void)
{
    SetMainCallback2(sub_80773D0);
    gMain.callback1 = NULL;
    gEnemyPartyCount = 0;
}

static void sub_80773D0(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        gUnknown_0203229C = AllocZeroed(sizeof(*gUnknown_0203229C));
        sub_80772A4();
        gUnknown_02032184 = AllocZeroed(0xE00);

        for (i = 0; i < 14; i++)
        {
            gUnknown_02032188[i] = &gUnknown_02032184[i * 256];
        }

        gMain.state++;
        break;
    case 1:
        gPaletteFade.bufferTransferDisabled = FALSE;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            CreateMon(&gEnemyParty[i], SPECIES_NONE, 0, 0x20, FALSE, 0, 0, 0);
        }

        sub_807A19C(0);
        ShowBg(0);

        if (!gReceivedRemoteLinkPlayers)
        {
            gLinkType = 0x1122;
            gUnknown_0203229C->unk_A8 = 0;

            if (gWirelessCommType)
            {
                sub_800B488();
                OpenLink();
                sub_8011BA4();
            }
            else
            {
                OpenLink();
                gMain.state++;
                CreateTask(task00_08081A90, 1);
            }
        }
        else
        {
            gMain.state = 4;
        }
        break;
    case 2:
        gUnknown_0203229C->unk_A8++;
        if (gUnknown_0203229C->unk_A8 > 11)
        {
            gUnknown_0203229C->unk_A8 = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
        {
            if (IsLinkMaster())
            {
                if (++gUnknown_0203229C->unk_A8 > 30)
                {
                    CheckShouldAdvanceLinkState();
                    gMain.state++;
                }
            }
            else
            {
                gMain.state++;
            }
        }
        break;
    case 4:
        if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
        {
            sub_8011BD0();
            CalculatePlayerPartyCount();
            gMain.state++;
            gUnknown_0203229C->unk_A8 = 0;
            if (gWirelessCommType)
            {
                sub_801048C(TRUE);
                sub_800ADF8();
            }
        }
        break;
    case 5:
        if (gWirelessCommType)
        {
            if (sub_8010500())
            {
                gMain.state++;
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            gMain.state++;
        }
        break;
    case 6:
        if (shedinja_maker_maybe())
        {
            sub_807A5B0();
            gMain.state++;
        }
        break;
    case 7:
        CalculateEnemyPartyCount();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        gUnknown_0203229C->partyCounts[0] = gPlayerPartyCount;
        gUnknown_0203229C->partyCounts[1] = gEnemyPartyCount;

        for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            gUnknown_0203229C->partyIcons[0][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < gUnknown_0203229C->partyCounts[1]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->partyIcons[1][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->partyIcons[0], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->partyIcons[0], 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(gUnknown_0832DE94[0], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(gUnknown_0832DE94[1], gUnknown_02032188[8], 24);
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 11:
        if (sub_807A1F0())
            gMain.state++;
        break;
    case 12:
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 3;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 6;
        CreateSprite(&temp, 215, 152, 1);
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 7;
        CreateSprite(&temp, 247, 152, 1);

        for (i = 0; i < PARTY_SIZE; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 8;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        gUnknown_0203229C->tradeMenuCursorSpriteIdx = CreateSprite(&gSpriteTemplate_832DC94, gTradeMonSpriteCoords[0][0] * 8 + 32, gTradeMonSpriteCoords[0][1] * 8, 2);
        gUnknown_0203229C->tradeMenuCursorPosition = 0;
        gMain.state++;
        rbox_fill_rectangle(0);
        break;
    case 14:
        sub_807A320(0);
        sub_8079BE0(0);
        gUnknown_0203229C->unk_0 = 0;
        gUnknown_0203229C->unk_1 = 0;
        sub_8078388();
        gMain.state++;
        PlayBGM(MUS_P_SCHOOL);
        break;
    case 15:
        sub_807A320(1);
        sub_8079BE0(1);
        gMain.state++;
        // fallthrough
    case 16:
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        gMain.state++;
        break;
    case 18:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        sub_80782B8(2);
        gMain.state++;
        break;
    case 20:
        sub_807A468(0);
        gMain.state++;
        break;
    case 21:
        sub_807A468(1);
        sub_807A53C();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
        {
            gMain.callback1 = sub_8078C34;
            SetMainCallback2(sub_807825C);
        }
        break;
    }

    RunTextPrinters();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_8077B74(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;

    switch (gMain.state)
    {
    case 0:
        sub_80772A4();
        gMain.state++;
        break;
    case 1:
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 2:
        gMain.state++;
        break;
    case 3:
        gMain.state++;
        break;
    case 4:
        CalculatePlayerPartyCount();
        gMain.state++;
        break;
    case 5:
        if (gWirelessCommType)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        gMain.state++;
        break;
    case 6:
        gMain.state++;
        break;
    case 7:
        CalculateEnemyPartyCount();
        gUnknown_0203229C->partyCounts[0] = gPlayerPartyCount;
        gUnknown_0203229C->partyCounts[1] = gEnemyPartyCount;
        ClearWindowTilemap(0);
        sub_8079BE0(0);
        sub_8079BE0(1);

        for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            gUnknown_0203229C->partyIcons[0][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < gUnknown_0203229C->partyCounts[1]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            gUnknown_0203229C->partyIcons[1][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES2, NULL),
                                                         sub_80D3014,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (gTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->partyIcons[0], 0);
        gMain.state++;
        break;
    case 9:
        sub_81B5D4C(&gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->partyIcons[0], 1);
        gMain.state++;
        break;
    case 10:
        sub_80C6D80(gSaveBlock2Ptr->playerName, gUnknown_02032188[0], 0, 0, 3);
        id = GetMultiplayerId();
        sub_80C6D80(gLinkPlayers[id ^ 1].name, gUnknown_02032188[3], 0, 0, 3);
        sub_80C6D80(gUnknown_0832DE94[0], gUnknown_02032188[6], 0, 0, 2);
        sub_807A308(gUnknown_0832DE94[1], gUnknown_02032188[8], 24);
        gMain.state++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 11:
        if (sub_807A1F0())
            gMain.state++;
        break;
    case 12:
        xPos = GetStringCenterAlignXOffset(1, gSaveBlock2Ptr->playerName, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i;
            CreateSprite(&temp, xPos + (i * 32) + 16, 10, 1);
        }

        xPos = GetStringCenterAlignXOffset(1, gLinkPlayers[GetMultiplayerId() ^ 1].name, 120);
        for (i = 0; i < 3; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 3;
            CreateSprite(&temp, xPos + (i * 32) + 136, 10, 1);
        }
        gMain.state++;
        break;
    case 13:
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 6;
        CreateSprite(&temp, 215, 152, 1);
        temp = gSpriteTemplate_832DCAC;
        temp.tileTag += 7;
        CreateSprite(&temp, 247, 152, 1);

        for (i = 0; i < PARTY_SIZE; i++)
        {
            temp = gSpriteTemplate_832DCAC;
            temp.tileTag += i + 8;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        if (gUnknown_0203229C->tradeMenuCursorPosition < PARTY_SIZE)
            gUnknown_0203229C->tradeMenuCursorPosition = gLastViewedMonIndex;
        else
            gUnknown_0203229C->tradeMenuCursorPosition = gLastViewedMonIndex + PARTY_SIZE;

        gUnknown_0203229C->tradeMenuCursorSpriteIdx = CreateSprite(&gSpriteTemplate_832DC94, gTradeMonSpriteCoords[gUnknown_0203229C->tradeMenuCursorPosition][0] * 8 + 32, gTradeMonSpriteCoords[gUnknown_0203229C->tradeMenuCursorPosition][1] * 8, 2);
        gMain.state = 16;
        break;
    case 16:
        sub_80782B8(0);
        gMain.state++;
        break;
    case 17:
        sub_80782B8(1);
        gUnknown_0203229C->unk_0 = 0;
        gUnknown_0203229C->unk_1 = 0;
        sub_8078388();
        gMain.state++;
        break;
    case 18:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        sub_80782B8(2);
        gMain.state++;
        break;
    case 20:
        gMain.state++;
        break;
    case 21:
        sub_807A53C();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(sub_807825C);
        }
        break;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807811C(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_8078130(void)
{
    if (++gUnknown_0203229C->unk_A8 > 15)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gUnknown_0203229C->unk_6F = 10;
    }
}

static void sub_807816C(void)
{
    if (!gPaletteFade.active)
    {
        gUnknown_02032298[0] = gUnknown_0203229C->tradeMenuCursorPosition;
        gUnknown_02032298[1] = gUnknown_0203229C->unk_7E;

        if (gWirelessCommType)
        {
            gUnknown_0203229C->unk_6F = 16;
        }
        else
        {
            sub_800ABF4(32);
            gUnknown_0203229C->unk_6F = 13;
        }
    }
}

static void sub_80781C8(void)
{
    gMain.savedCallback = sub_80773AC;

    if (gWirelessCommType)
    {
        if (sub_8010500())
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(gUnknown_0203229C);
            gMain.callback1 = NULL;
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(sub_807AE50);
        }
    }
    else
    {
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(gUnknown_02032184);
            FreeAllWindowBuffers();
            Free(gUnknown_0203229C);
            gMain.callback1 = NULL;
            SetMainCallback2(sub_807AE50);
        }
    }
}

static void sub_807825C(void)
{
    u8 temp;

    sub_80795AC();
    sub_807A0C4();
    sub_80796B4(0);
    sub_80796B4(1);

    SetGpuReg(REG_OFFSET_BG2HOFS, gUnknown_0203229C->unk_0++);
    SetGpuReg(REG_OFFSET_BG3HOFS, gUnknown_0203229C->unk_1--);

    RunTextPrintersAndIsPrinter0Active();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_80782B8(u8 a0)
{
    int i;

    switch (a0)
    {
    case 0:
        LoadPalette(gUnknown_08DDB3E4, 0, 0x60);
        LoadBgTiles(1, gUnknown_08DDB464, 0x1280, 0);
        CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDCF04, 0, 0, 32, 20, 0);
        LoadBgTilemap(2, gTradeStripesBG2Tilemap, 0x800, 0);
        break;
    case 1:
        LoadBgTilemap(3, gTradeStripesBG3Tilemap, 0x800, 0);
        sub_8079E44(0);
        sub_8079E44(1);
        CopyBgTilemapBufferToVram(1);
        break;
    case 2:
        for (i = 0; i < 4; i++)
        {
            SetGpuReg(REG_OFFSET_BG0HOFS + (i * 2), 0);
        }
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        break;
    }
}

static void sub_8078388(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i < gUnknown_0203229C->partyCounts[0])
        {
            gSprites[gUnknown_0203229C->partyIcons[0][i]].invisible = FALSE;
            gUnknown_0203229C->tradeMenuOptionsActive[i] = TRUE;
        }
        else
        {
            gUnknown_0203229C->tradeMenuOptionsActive[i] = FALSE;
        }

        if (i < gUnknown_0203229C->partyCounts[1])
        {
            gSprites[gUnknown_0203229C->partyIcons[1][i]].invisible = FALSE;
            gUnknown_0203229C->tradeMenuOptionsActive[i + PARTY_SIZE] = TRUE;
        }
        else
        {
            gUnknown_0203229C->tradeMenuOptionsActive[i + PARTY_SIZE] = FALSE;
        }
    }

    gUnknown_0203229C->unk_44 = 1;
}

// why not just use memcpy?
static void Trade_Memcpy(void *dataDest, const void *dataSrc, u32 count)
{
    u8 *dest = dataDest;
    const u8 *src = dataSrc;
    u32 i;

    for (i = 0; i < count; i++)
    {
        dest[i] = src[i];
    }
}

static bool8 shedinja_maker_maybe(void)
{
    u8 id = GetMultiplayerId();
    int i;
    struct Pokemon *mon;

    switch (gUnknown_0203229C->unk_69)
    {
    case 0:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[0], 2 * sizeof(struct Pokemon));
        gUnknown_0203229C->unk_69++;
        gUnknown_0203229C->unk_A8 = 0;
        break;
    case 1:
        if (sub_80771BC())
        {
            if (_GetBlockReceivedStatus() == 0)
            {
                gUnknown_0203229C->unk_69++;
            }
            else
            {
                sub_8077210();
                gUnknown_0203229C->unk_69++;
            }
        }
        break;
    case 3:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 4:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[0], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 5:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[2], 2 * sizeof(struct Pokemon));
        gUnknown_0203229C->unk_69++;
        break;
    case 7:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 8:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[2], gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 9:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[4], 200);
        gUnknown_0203229C->unk_69++;
        break;
    case 11:
        if (id == 0)
        {
            sub_80771AC(1);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 12:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[4], gBlockRecvBuffer[id ^ 1], 200);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 13:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->mail, 220);
        gUnknown_0203229C->unk_69++;
        break;
    case 15:
        if (id == 0)
        {
            sub_80771AC(3);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 16:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(gUnknown_020321C0, gBlockRecvBuffer[id ^ 1], 216);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 17:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->giftRibbons, 11);
        gUnknown_0203229C->unk_69++;
        break;
    case 19:
        if (id == 0)
        {
            sub_80771AC(4);
        }
        gUnknown_0203229C->unk_69++;
        break;
    case 20:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(gUnknown_0203229C->unk_A9, gBlockRecvBuffer[id ^ 1], 11);
            sub_8077210();
            gUnknown_0203229C->unk_69++;
        }
        break;
    case 21:
        for (i = 0, mon = gEnemyParty; i < PARTY_SIZE; mon++, i++)
        {
            u8 name[POKEMON_NAME_LENGTH + 1];
            u16 species = GetMonData(mon, MON_DATA_SPECIES);

            if (species != SPECIES_NONE)
            {
                if (species == SPECIES_SHEDINJA && GetMonData(mon, MON_DATA_LANGUAGE) != LANGUAGE_JAPANESE)
                {
                    GetMonData(mon, MON_DATA_NICKNAME, name);

                    if (!StringCompareWithoutExtCtrlCodes(name, gJPText_Shedinja))
                    {
                        SetMonData(mon, MON_DATA_NICKNAME, gSpeciesNames[SPECIES_SHEDINJA]);
                    }
                }
            }
        }
        return TRUE;
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
        gUnknown_0203229C->unk_A8++;
        if (gUnknown_0203229C->unk_A8 > 10)
        {
            gUnknown_0203229C->unk_A8 = 0;
            gUnknown_0203229C->unk_69++;
        }
        break;
    }
    return FALSE;
}

static void sub_80787B8(void)
{
    sub_807A308(gText_IsThisTradeOkay, (void *)(OBJ_VRAM0 + (gUnknown_0203229C->unk_72 * 32)), 24);
}

static void sub_80787E0(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEAA:
            gUnknown_0203229C->unk_78 = 2;
            break;
        case 0xAABB:
            gUnknown_0203229C->unk_78 = 1;
            break;
        case 0xBBBB:
            gUnknown_0203229C->unk_7A = 1;
            break;
        case 0xBBCC:
            gUnknown_0203229C->unk_7A = 2;
            break;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
    {
        switch (gBlockRecvBuffer[1][0])
        {
        case 0xEEAA:
            gUnknown_0203229C->unk_79 = 2;
            break;
        case 0xAABB:
            gUnknown_0203229C->unk_7E = gBlockRecvBuffer[1][1] + 6;
            gUnknown_0203229C->unk_79 = 1;
            break;
        case 0xBBBB:
            gUnknown_0203229C->unk_7B = 1;
            break;
        case 0xBBCC:
            gUnknown_0203229C->unk_7B = 2;
            break;
        }
        sub_8077234(1);
    }
}

static void sub_8078900(u8 a0, u8 a1)
{
    if (a1 & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case 0xEEBB:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            sub_807A19C(4);
            gUnknown_0203229C->unk_6F = 11;
            break;
        case 0xEECC:
            sub_807A19C(5);
            gUnknown_0203229C->unk_6F = 8;
            break;
        case 0xDDDD:
            gUnknown_0203229C->unk_7E = gBlockRecvBuffer[0][1] + 6;
            rbox_fill_rectangle(0);
            sub_807967C(gUnknown_0203229C->tradeMenuCursorPosition);
            sub_807967C(gUnknown_0203229C->unk_7E);
            gUnknown_0203229C->unk_6F = 7;
            break;
        case 0xCCDD:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 10;
            break;
        case 0xDDEE:
            sub_807A19C(1);
            gUnknown_0203229C->unk_6F = 8;
        }
        sub_8077234(0);
    }

    if (a1 & 2)
        sub_8077234(1);
}

static void sub_80789FC(void)
{
    if (gUnknown_0203229C->unk_78 && gUnknown_0203229C->unk_79)
    {
        if (gUnknown_0203229C->unk_78 == 1 && gUnknown_0203229C->unk_79 == 1)
        {
            gUnknown_0203229C->unk_6F = 6;
            gUnknown_0203229C->linkData[0] = 0xDDDD;
            gUnknown_0203229C->linkData[1] = gUnknown_0203229C->tradeMenuCursorPosition;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
        }
        else if (gUnknown_0203229C->unk_78 == 1 && gUnknown_0203229C->unk_79 == 2)
        {
            sub_807A19C(1);
            gUnknown_0203229C->linkData[0] = 0xEECC;
            gUnknown_0203229C->linkData[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 1)
        {
            sub_807A19C(5);
            gUnknown_0203229C->linkData[0] = 0xDDEE;
            gUnknown_0203229C->linkData[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
        else if (gUnknown_0203229C->unk_78 == 2 && gUnknown_0203229C->unk_79 == 2)
        {
            gUnknown_0203229C->linkData[0] = 0xEEBB;
            gUnknown_0203229C->linkData[1] = 0;
            sub_807A048(5, 0);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_78 = gUnknown_0203229C->unk_79 = 0;
            gUnknown_0203229C->unk_6F = 11;
        }
    }

    if (gUnknown_0203229C->unk_7A && gUnknown_0203229C->unk_7B)
    {
        if (gUnknown_0203229C->unk_7A == 1 && gUnknown_0203229C->unk_7B == 1)
        {
            gUnknown_0203229C->linkData[0] = 0xCCDD;
            gUnknown_0203229C->linkData[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_6F = 9;
        }

        if (gUnknown_0203229C->unk_7A == 2 || gUnknown_0203229C->unk_7B == 2)
        {
            sub_807A19C(1);
            gUnknown_0203229C->linkData[0] = 0xDDEE;
            gUnknown_0203229C->linkData[1] = 0;
            sub_807A048(5, 0);
            gUnknown_0203229C->unk_7A = 0;
            gUnknown_0203229C->unk_7B = 0;
            gUnknown_0203229C->unk_6F = 8;
        }
    }
}

static void sub_8078BFC(u16 *a0, u16 a1, u16 a2)
{
    a0[0] = a1;
    a0[1] = a2;
    sub_807A048(5, 0);
}

static void sub_8078C10(u16 a0, u16 a1)
{
    sub_8078BFC(gUnknown_0203229C->linkData, a0, a1);
}

static void sub_8078C34(void)
{
    u8 mpId = GetMultiplayerId();
    u8 status;

    if ((status = _GetBlockReceivedStatus()))
    {
        if (mpId == 0)
            sub_80787E0(mpId, status);
        else
            sub_8078900(mpId, status);
    }

    if (mpId == 0)
        sub_80789FC();
}

static u8 sub_8078C6C(u8 oldPosition, u8 direction)
{
    int i;
    u8 newPosition = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gUnknown_0203229C->tradeMenuOptionsActive[gTradeNextSelectedMonTable[oldPosition][direction][i]] == TRUE)
        {
            newPosition = gTradeNextSelectedMonTable[oldPosition][direction][i];
            break;
        }
    }

    return newPosition;
}

static void TradeMenuMoveCursor(u8 *tradeMenuCursorPosition, u8 direction)
{
    u8 newPosition = sub_8078C6C(*tradeMenuCursorPosition, direction);

    if (newPosition == 12) // CANCEL
    {
        StartSpriteAnim(&gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx], 1);
        gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].pos1.x = 224;
        gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].pos1.y = 160;
    }
    else
    {
        StartSpriteAnim(&gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx], 0);
        gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].pos1.x = gTradeMonSpriteCoords[newPosition][0] * 8 + 32;
        gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].pos1.y = gTradeMonSpriteCoords[newPosition][1] * 8;
    }

    if (*tradeMenuCursorPosition != newPosition)
    {
        PlaySE(SE_SELECT);
    }

    *tradeMenuCursorPosition = newPosition;
}

static void sub_8078D78(void)
{
    sub_807A19C(0);
    gUnknown_0203229C->unk_6F = 100;

    if (GetMultiplayerId() == 1)
    {
        sub_8078C10(0xAABB, gUnknown_0203229C->tradeMenuCursorPosition);
    }
    else
    {
        gUnknown_0203229C->unk_78 = 1;
    }
}

static void sub_8078DBC(void)
{
    if (gMain.newAndRepeatedKeys & DPAD_UP)
    {
        TradeMenuMoveCursor(&gUnknown_0203229C->tradeMenuCursorPosition, 0);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN)
    {
        TradeMenuMoveCursor(&gUnknown_0203229C->tradeMenuCursorPosition, 1);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT)
    {
        TradeMenuMoveCursor(&gUnknown_0203229C->tradeMenuCursorPosition, 2);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
    {
        TradeMenuMoveCursor(&gUnknown_0203229C->tradeMenuCursorPosition, 3);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);

        if (gUnknown_0203229C->tradeMenuCursorPosition < 6)
        {
            DrawTextBorderOuter(1, 1, 14);
            FillWindowPixelBuffer(1, PIXEL_FILL(1));
            PrintMenuTable(1, 2, gUnknown_0832DEAC);
            InitMenuInUpperLeftCornerPlaySoundWhenAPressed(1, 2, 0);
            PutWindowTilemap(1);
            CopyWindowToVram(1, 3);
            gUnknown_0203229C->unk_6F = 1;
        }
        else if (gUnknown_0203229C->tradeMenuCursorPosition < 12)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 2;
        }
        else if (gUnknown_0203229C->tradeMenuCursorPosition == 12)
        {
            CreateYesNoMenu(&gUnknown_0832DF8C, 1, 14, 0);
            gUnknown_0203229C->unk_6F = 4;
            sub_807A308(gUnknown_0832DE94[4], (void *)(OBJ_VRAM0 + gUnknown_0203229C->unk_72 * 32), 24);
        }
    }
}

static void sub_8078EF8(void)
{
    sub_8079F74();
    gUnknown_0203229C->unk_6F = 0;
    gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].invisible = FALSE;
    sub_807A308(gUnknown_0832DE94[1], (void *)(OBJ_VRAM0 + gUnknown_0203229C->unk_72 * 32), 24);
}

static void sub_8078F50(void)
{
    switch (Menu_ProcessInputNoWrap())
    {
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
        case MENU_NOTHING_CHOSEN:
            break;
        case 0:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_0203229C->unk_6F = 2;
            break;
        case 1:
            switch (sub_807A5F4(gPlayerParty, gPlayerPartyCount, gUnknown_0203229C->tradeMenuCursorPosition))
            {
                case 0:
                    sub_8078D78();
                    gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].invisible = TRUE;
                    break;
                case 1:
                    sub_807A048(3, 3);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
                case 2:
                case 4:
                    sub_807A048(3, 6);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
                case 3:
                case 5:
                    sub_807A048(3, 7);
                    gUnknown_0203229C->unk_6F = 8;
                    break;
            }
            break;
    }
}

static void sub_8079034(void)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys & B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sub_8078EF8();
    }
}

static void sub_807905C(void)
{
    if (!gPaletteFade.active)
    {
        if (gUnknown_0203229C->tradeMenuCursorPosition < PARTY_SIZE)
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gPlayerParty, gUnknown_0203229C->tradeMenuCursorPosition, gUnknown_0203229C->partyCounts[0] - 1, sub_8077B74);
        }
        else
        {
            ShowPokemonSummaryScreen(PSS_MODE_UNK1, gEnemyParty, gUnknown_0203229C->tradeMenuCursorPosition - PARTY_SIZE, gUnknown_0203229C->partyCounts[1] - 1, sub_8077B74);
        }
        FreeAllWindowBuffers();
    }
}

static u8 sub_80790D4(u8 *a0, u8 a1, u8 a2, u8 a3)
{
    int i;
    u16 species;
    u8 res = 0;

    for (i = 0; i < a1; i++)
    {
        if (a2 != i)
        {
            res += a0[i];
        }
    }

    a3 %= PARTY_SIZE;
    species = GetMonData(&gEnemyParty[a3], MON_DATA_SPECIES);

    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!GetMonData(&gEnemyParty[a3], MON_DATA_OBEDIENCE))
        {
            return 2;
        }
    }

    if (!IsNationalPokedexEnabled())
    {
        if (gUnknown_0203229C->unk_51[1][a3] || !IsSpeciesInHoennDex(species))
        {
            return 2;
        }
    }

    if (res)
    {
        res = 1;
    }

    return res;
}

static bool32 sub_8079174(void)
{
    int i;
    u8 arr[12];

    for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
    {
        arr[i] = gUnknown_0203229C->unk_45[0][i];
    }

    switch (sub_80790D4(arr, gUnknown_0203229C->partyCounts[0], gUnknown_0203229C->tradeMenuCursorPosition, gUnknown_0203229C->unk_7E))
    {
        case 0:
            sub_807A048(3, 3);
            sub_8078C10(0xBBCC, 0);
            break;
        case 1:
            sub_807A048(3, 1);
            sub_8078C10(0xBBBB, 0);
            break;
        case 2:
            sub_807A048(3, 8);
            return TRUE;
    }

    return FALSE;
}

static void sub_8079218(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            if (!sub_8079174())
            {
                gUnknown_0203229C->unk_6F = 100;
            }
            else
            {
                gUnknown_0203229C->unk_6F = 17;
            }
            PutWindowTilemap(17);
            break;
        case 1:
        case MENU_B_PRESSED:
            sub_807A048(3, 1);
            if (sub_80771BC())
                sub_8078C10(0xBBCC, 0);
            gUnknown_0203229C->unk_6F = 100;
            PutWindowTilemap(17);
            break;
    }
}

static void sub_807929C(void)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->partyCounts[1] - 4; i++)
    {
        PutWindowTilemap(i + 12);
        CopyWindowToVram(i + 12, 1);
    }
}

static void sub_80792E4(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            sub_807A19C(4);
            sub_8078C10(0xEEAA, 0);
            gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].invisible = TRUE;
            gUnknown_0203229C->unk_6F = 100;
            sub_807929C();
            break;
        case 1:
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sub_8078EF8();
            break;
    }
}

static void sub_807935C(void)
{
    if (GetMultiplayerId() == 0)
    {
        rbox_fill_rectangle(0);
        sub_807967C(gUnknown_0203229C->tradeMenuCursorPosition);
        sub_807967C(gUnknown_0203229C->unk_7E);
    }
    gUnknown_0203229C->unk_6F = 7;
}

static void sub_8079398(void)
{
    if (gUnknown_0203229C->unk_74[0] == 5 && gUnknown_0203229C->unk_74[1] == 5)
    {
        sub_80787B8();
        gUnknown_0203229C->unk_6F = 14;
    }
}

static void DisplayMessageAndContinueTask(void)
{
    gUnknown_0203229C->unk_A8++;

    if (gUnknown_0203229C->unk_A8 > 120)
    {
        CreateYesNoMenu(&gUnknown_0832DF8C, 1, 14, 0);
        gUnknown_0203229C->unk_A8 = 0;
        gUnknown_0203229C->unk_6F = 3;
    }
}

static void sub_8079408(void)
{
    int i;

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(0);
        rbox_fill_rectangle(1);

        for (i = 0; i < 4; i++)
        {
            FillWindowPixelBuffer(i + 14, PIXEL_FILL(0));
            rbox_fill_rectangle(i + 14);
        }

        sub_8079F88(0);
        sub_8079F88(1);
        gUnknown_0203229C->unk_6F = 0;
        gSprites[gUnknown_0203229C->tradeMenuCursorSpriteIdx].invisible = FALSE;
    }
}

static void sub_8079490(void)
{
    if (!gPaletteFade.active)
    {
        if (gWirelessCommType)
        {
            sub_800ADF8();
        }
        else
        {
            sub_800ABF4(12);
        }

        gUnknown_0203229C->unk_6F = 12;
    }
}

static void sub_80794CC(void)
{
    if (gWirelessCommType)
    {
        if (sub_80771BC() && sub_807A09C() == 0)
        {
            Free(gUnknown_02032184);
            Free(gUnknown_0203229C);
            FreeAllWindowBuffers();
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
    else
    {
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(gUnknown_02032184);
            Free(gUnknown_0203229C);
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
}

static void sub_8079550(void)
{
    if (!sub_801048C(FALSE) && sub_807A09C() == 0)
    {
        sub_800ADF8();
        gUnknown_0203229C->unk_6F = 13;
    }
}

static void sub_807957C(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        sub_8078C10(0xBBCC, 0);
        gUnknown_0203229C->unk_6F = 100;
    }
}

static void sub_80795AC(void)
{
    switch (gUnknown_0203229C->unk_6F)
    {
        case 0:
            sub_8078DBC();
            break;
        case 1:
            sub_8078F50();
            break;
        case 2:
            sub_807905C();
            break;
        case 3:
            sub_8079218();
            break;
        case 4:
            sub_80792E4();
            break;
        case 6:
            sub_807935C();
            break;
        case 7:
            sub_8079398();
            break;
        case 8:
            sub_8079408();
            break;
        case 9:
            sub_8078130();
            break;
        case 10:
            sub_807816C();
            break;
        case 11:
            sub_8079490();
            break;
        case 12:
            sub_80794CC();
            break;
        case 13:
            sub_80781C8();
            break;
        case 14:
            DisplayMessageAndContinueTask();
            break;
        case 15:
            sub_8079034();
            break;
        case 16:
            sub_8079550();
            break;
        case 17:
            sub_807957C();
            break;
    }
}

static void sub_807967C(u8 a0)
{
    u8 whichParty = a0 / PARTY_SIZE;

    if (gUnknown_0203229C->unk_74[whichParty] == 0)
    {
        gUnknown_0203229C->unk_74[whichParty] = 1;
        gUnknown_0203229C->unk_76[whichParty] = a0;
    }
}

static void sub_80796B4(u8 a0)
{
    s8 nameStringWidth;
    u8 nickname[20];
    u8 movesString[56];
    u8 i;
    u8 partyIdx;
    u8 whichParty;
    u8 monIdx = gUnknown_0203229C->unk_76[a0];

    whichParty = 1;
    if (gUnknown_0203229C->unk_76[a0] < PARTY_SIZE)
        whichParty = 0;
    partyIdx = monIdx % PARTY_SIZE;
    nameStringWidth = 0;

    switch (gUnknown_0203229C->unk_74[a0])
    {
    case 1:
        for (i = 0; i < gUnknown_0203229C->partyCounts[a0]; i++)
        {
            gSprites[gUnknown_0203229C->partyIcons[0][i + (whichParty * PARTY_SIZE)]].invisible = TRUE;
        }

        for (i = 0; i < 6; i++)
        {
            ClearWindowTilemap(i + (a0 * 6 + 2));
        }

        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].invisible = FALSE;
        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].data[0] = 20;
        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].data[2] = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][0] + gTradeMonSpriteCoords[whichParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].data[4] = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][1] * 8) - 12;
        StoreSpriteCallbackInData6(&gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]], sub_80D3014);
        gUnknown_0203229C->unk_74[a0]++;
        sub_80A6DEC(&gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]]);
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(0);

        if (whichParty == 0)
            sub_8079F74();
        break;
    case 2:
        if (gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].callback == sub_80D3014)
            gUnknown_0203229C->unk_74[a0] = 3;
        break;
    case 3:
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMovesBoxTilemap, whichParty * 15, 0, 15, 17, 0);
        CopyBgTilemapBufferToVram(1);
        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos1.x = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][0] + gTradeMonSpriteCoords[whichParty * PARTY_SIZE + 1][0]) / 2 * 8 + 14;
        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos1.y = (gTradeMonSpriteCoords[whichParty * PARTY_SIZE][1] * 8) - 12;
        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos2.x = 0;
        gSprites[gUnknown_0203229C->partyIcons[0][partyIdx + (whichParty * PARTY_SIZE)]].pos2.y = 0;
        nameStringWidth = sub_8079A3C(nickname, whichParty, partyIdx);
        AddTextPrinterParameterized3((a0 * 2) + 14, 0, (80 - nameStringWidth) / 2, 4, gUnknown_0832DEE0, 0, nickname);
        sub_8079AA4(movesString, whichParty, partyIdx);
        AddTextPrinterParameterized4((a0 * 2) + 15, 1, 0, 0, 0, 0, gUnknown_0832DEE0, 0, movesString);
        PutWindowTilemap((a0 * 2) + 14);
        CopyWindowToVram((a0 * 2) + 14, 3);
        PutWindowTilemap((a0 * 2) + 15);
        CopyWindowToVram((a0 * 2) + 15, 3);
        gUnknown_0203229C->unk_74[a0]++;
        break;
    case 4:
        sub_8079C4C(a0, partyIdx, gUnknown_0832DF99[a0][0] + 4, gUnknown_0832DF99[a0][1] + 1, gUnknown_0832DF99[a0][0], gUnknown_0832DF99[a0][1]);
        gUnknown_0203229C->unk_74[a0]++;
        break;
    }
}

static u8 sub_8079A3C(u8 *str, u8 whichParty, u8 monIdx)
{
    u8 nickname[12];

    if (whichParty == 0)
        GetMonData(&gPlayerParty[monIdx], MON_DATA_NICKNAME, nickname);
    else
        GetMonData(&gEnemyParty[monIdx], MON_DATA_NICKNAME, nickname);

    StringCopy10(str, nickname);
    return GetStringWidth(0, str, GetFontAttribute(0, FONTATTR_LETTER_SPACING));
}

static void sub_8079AA4(u8 *a0, u8 a1, u8 a2)
{
    u16 arr[4];
    u16 i;

    if (!gUnknown_0203229C->unk_51[a1][a2])
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (!a1)
            {
                arr[i] = GetMonData(&gPlayerParty[a2], i + MON_DATA_MOVE1, NULL);
            }
            else
            {
                arr[i] = GetMonData(&gEnemyParty[a2], i + MON_DATA_MOVE1, NULL);
            }
        }

        StringCopy(a0, gText_EmptyString7);

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (arr[i] != MOVE_NONE)
            {
                StringAppend(a0, gMoveNames[arr[i]]);
            }

            StringAppend(a0, gText_NewLine3);
        }
    }
    else
    {
        StringCopy(a0, gText_EmptyString7);
        StringAppend(a0, gText_FourQuestionMarks);
    }
}

static void sub_8079B84(u8 whichParty, u8 windowId, u8 *str)
{
    u8 xPos;
    windowId += (whichParty * PARTY_SIZE) + 2;
    xPos = GetStringCenterAlignXOffset(0, str, 64);
    AddTextPrinterParameterized3(windowId, 0, xPos, 4, gUnknown_0832DEE0, 0, str);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void sub_8079BE0(u8 whichParty)
{
    u8 i;
    u8 sp[20];
    u8 sp14[32];
    struct Pokemon *mons = whichParty == 0 ? gPlayerParty : gEnemyParty;

    for (i = 0; i < gUnknown_0203229C->partyCounts[whichParty]; i++)
    {
        GetMonData(&mons[i], MON_DATA_NICKNAME, sp);
        StringCopy10(sp14, sp);
        sub_8079B84(whichParty, i, sp14);
    }
}

static void sub_8079C4C(u8 whichParty, u8 monIdx, u8 a2, u8 a3, u8 a4, u8 a5)
{
    u8 level;
    u32 r2;
    u8 gender;
    u8 nickname[12];

    CopyToBgTilemapBufferRect_ChangePalette(1, gUnknown_08DDD704, a4, a5, 6, 3, 0);
    CopyBgTilemapBufferToVram(1);

    if (whichParty == 0)
        level = GetMonData(&gPlayerParty[monIdx], MON_DATA_LEVEL, NULL);
    else
        level = GetMonData(&gEnemyParty[monIdx], MON_DATA_LEVEL, NULL);

    if (gUnknown_0203229C->unk_51[whichParty][monIdx] == 0)
    {
        if (level / 10 != 0)
            gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32)] = (level / 10) + 0x60;

        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) + 1] = (level % 10) + 0x70;
    }
    else
    {
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 32] = gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 33];
        gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 31] = gUnknown_0203229C->tilemapBuffer[a2 + (a3 * 32) - 36] | 0x400;
    }

    if (gUnknown_0203229C->unk_51[whichParty][monIdx] != 0)
    {
        r2 = 0x480;
    }
    else
    {
        if (whichParty == 0)
        {
            gender = GetMonGender(&gPlayerParty[monIdx]);
            GetMonData(&gPlayerParty[monIdx], MON_DATA_NICKNAME, nickname);
        }
        else
        {
            gender = GetMonGender(&gEnemyParty[monIdx]);
            GetMonData(&gEnemyParty[monIdx], MON_DATA_NICKNAME, nickname);
        }

        switch (gender)
        {
            case MON_MALE:
                r2 = !NameHasGenderSymbol(nickname, MON_MALE) ? 0x84 : 0x83;
                break;
            case MON_FEMALE:
                r2 = !NameHasGenderSymbol(nickname, MON_FEMALE) ? 0x85 : 0x83;
                break;
            default:
                r2 = 0x83;
                break;
        }
    }
    gUnknown_0203229C->tilemapBuffer[(a3 - 1) * 32 + a2 + 1] = r2;
}

// Very close but loop preamble not working.
#ifdef NONMATCHING
static void sub_8079E44(u8 whichParty)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->partyCounts[whichParty]; i++)
    {
        sub_8079C4C(whichParty, i, gTradeLevelDisplayCoords[whichParty][i][0], gTradeLevelDisplayCoords[whichParty][i][1], gTradeMonBoxCoords[whichParty][i][0], gTradeMonBoxCoords[whichParty][i][1]);
    }
}
#else
NAKED
static void sub_8079E44(u8 whichParty)
{
    asm_unified("push {r4-r7,lr}\n\
    sub sp, 0x8\n\
    lsls r0, 24\n\
    lsrs r6, r0, 24\n\
    movs r7, 0\n\
    ldr r0, =gUnknown_0203229C\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    bge _08079E94\n\
    lsls r0, r6, 1\n\
    adds r0, r6\n\
    ldr r1, =gTradeLevelDisplayCoords\n\
    lsls r0, 2\n\
    adds r5, r0, r1\n\
    ldr r1, =gTradeMonBoxCoords\n\
    adds r4, r0, r1\n\
_08079E6A:\n\
    lsls r1, r7, 24\n\
    lsrs r1, 24\n\
    ldrb r2, [r5]\n\
    ldrb r3, [r5, 0x1]\n\
    ldrb r0, [r4]\n\
    str r0, [sp]\n\
    ldrb r0, [r4, 0x1]\n\
    str r0, [sp, 0x4]\n\
    adds r0, r6, 0\n\
    bl sub_8079C4C\n\
    adds r5, 0x2\n\
    adds r4, 0x2\n\
    adds r7, 0x1\n\
    ldr r0, =gUnknown_0203229C\n\
    ldr r0, [r0]\n\
    adds r0, 0x36\n\
    adds r0, r6\n\
    ldrb r0, [r0]\n\
    cmp r7, r0\n\
    blt _08079E6A\n\
_08079E94:\n\
    add sp, 0x8\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool");
}
#endif // NONMATCHING

static void sub_8079EA8(u8 whichParty)
{
    int i;

    for (i = 0; i < gUnknown_0203229C->partyCounts[whichParty]; i++)
    {
        gSprites[gUnknown_0203229C->partyIcons[whichParty][i]].invisible = FALSE;
        gSprites[gUnknown_0203229C->partyIcons[whichParty][i]].pos1.x = gTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][0] * 8 + 14;
        gSprites[gUnknown_0203229C->partyIcons[whichParty][i]].pos1.y = gTradeMonSpriteCoords[(whichParty * PARTY_SIZE) + i][1] * 8 - 12;
        gSprites[gUnknown_0203229C->partyIcons[whichParty][i]].pos2.x = 0;
        gSprites[gUnknown_0203229C->partyIcons[whichParty][i]].pos2.y = 0;
    }
}

static void sub_8079F74(void)
{
    rbox_fill_rectangle(1);
    sub_8079BE0(1);
}

static void sub_8079F88(u8 a0)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, gTradePartyBoxTilemap, a0 * 15, 0, 15, 17, 0);
    CopyBgTilemapBufferToVram(1);
    sub_8079E44(a0);
    sub_8079BE0(a0);
    sub_8079EA8(a0);
    sub_807A308(gUnknown_0832DE94[1], (void *)(OBJ_VRAM0 + (gUnknown_0203229C->unk_72 * 32)), 24);
    gUnknown_0203229C->unk_74[a0] = 0;
}

static void sub_807A000(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

static void sub_807A024(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
}

static void sub_807A048(u16 a0, u8 a1)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (!gUnknown_0203229C->unk_8D0[i].unk_0)
        {
            gUnknown_0203229C->unk_8D0[i].unk_2 = a0;
            gUnknown_0203229C->unk_8D0[i].unk_4 = a1;
            gUnknown_0203229C->unk_8D0[i].unk_0 = TRUE;
            break;
        }
    }
}

static u32 sub_807A09C(void)
{
    u32 acc = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        acc += gUnknown_0203229C->unk_8D0[i].unk_0;
    }

    return acc;
}

static void sub_807A0C4(void)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_0203229C->unk_8D0[i].unk_0)
        {
            if (gUnknown_0203229C->unk_8D0[i].unk_2)
            {
                gUnknown_0203229C->unk_8D0[i].unk_2--;
            }
            else
            {
                switch (gUnknown_0203229C->unk_8D0[i].unk_4)
                {
                    case 0:
                        sub_8077170(gUnknown_0203229C->linkData, 20);
                        break;
                    case 1:
                        sub_807A19C(0);
                        break;
                    case 2:
                        sub_807A19C(2);
                        break;
                    case 3:
                    case 4:
                    case 5:
                        sub_807A19C(3);
                        break;
                    case 6:
                        sub_807A19C(6);
                        break;
                    case 7:
                        sub_807A19C(7);
                        break;
                    case 8:
                        sub_807A19C(8);
                        break;
                }
                gUnknown_0203229C->unk_8D0[i].unk_0 = 0;
            }
        }
    }
}

static void sub_807A19C(u8 a0)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, 1, gUnknown_0832DEBC[a0], 0, 1, TEXT_SPEED_FF, NULL);
    DrawTextBorderOuter(0, 20, 12);
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static bool8 sub_807A1F0(void)
{
    struct SpriteSheet sheet;

    if (gUnknown_0203229C->unk_A8 < 14)
    {
        sheet.data = gUnknown_02032188[gUnknown_0203229C->unk_A8];
        sheet.size = 0x100;
        sheet.tag = 200 + gUnknown_0203229C->unk_A8;
    }

    switch (gUnknown_0203229C->unk_A8)
    {
        case 0 ... 7:
            LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 8:
            gUnknown_0203229C->unk_72 = LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 9 ... 13:
            LoadSpriteSheet(&sheet);
            gUnknown_0203229C->unk_A8++;
            break;
        case 14:
            LoadSpritePalette(&gSpritePalette_TradeScreenText);
            gUnknown_0203229C->unk_A8++;
            break;
        case 15:
            LoadSpritePalette(&gUnknown_0832DC44);
            gUnknown_0203229C->unk_A8++;
            break;
        case 16:
            LoadSpriteSheet(&gUnknown_0832DC3C);
            gUnknown_0203229C->unk_A8++;
            break;
        case 17:
            gUnknown_0203229C->unk_A8 = 0;
            return TRUE;
    }

    return FALSE;
}

static void sub_807A308(const u8 *a0, u8 *a1, u8 unused)
{
    sub_80C6D80(a0, a1, 0, 0, 6);
}

static void sub_807A320(u8 who)
{
    int i;

    switch (who)
    {
        case 0:
            for (i = 0; i < gUnknown_0203229C->partyCounts[who]; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == TRUE)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 1;
                }
                else if (GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
                else
                {
                    gUnknown_0203229C->unk_45[who][i] = 1;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
            }
            break;
        case 1:
            for (i = 0; i < gUnknown_0203229C->partyCounts[who]; i++)
            {
                if (GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG) == TRUE)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 1;
                }
                else if (GetMonData(&gEnemyParty[i], MON_DATA_HP) == 0)
                {
                    gUnknown_0203229C->unk_45[who][i] = 0;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
                else
                {
                    gUnknown_0203229C->unk_45[who][i] = 1;
                    gUnknown_0203229C->unk_51[who][i] = 0;
                }
            }
            break;
    }
}

static void sub_807A468(u8 who)
{
    u16 i, curHp, maxHp;

    switch (who)
    {
        case 0:
            for (i = 0; i < gUnknown_0203229C->partyCounts[0]; i++)
            {
                curHp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
                gUnknown_0203229C->unk_5D[0][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
        case 1:
            for (i = 0; i < gUnknown_0203229C->partyCounts[1]; i++)
            {
                curHp = GetMonData(&gEnemyParty[i], MON_DATA_HP);
                maxHp = GetMonData(&gEnemyParty[i], MON_DATA_MAX_HP);
                gUnknown_0203229C->unk_5D[1][i] = GetHPBarLevel(curHp, maxHp);
            }
            break;
    }
}

static void sub_807A53C(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < gUnknown_0203229C->partyCounts[i]; j++)
        {
            sub_80D32C8(&gSprites[gUnknown_0203229C->partyIcons[i][j]], 4 - gUnknown_0203229C->unk_5D[i][j]);
        }
    }
}

static void sub_807A5B0(void)
{
    int i;

    for (i = 0; i < 11; i++)
    {
        if (gSaveBlock1Ptr->giftRibbons[i] == 0 && gUnknown_0203229C->unk_A9[i] != 0)
        {
            if (gUnknown_0203229C->unk_A9[i] < 64)
                gSaveBlock1Ptr->giftRibbons[i] = gUnknown_0203229C->unk_A9[i];
        }
    }
}

static u32 sub_807A5F4(struct Pokemon *monList, int a1, int monIdx)
{
    int i, sum;
    struct LinkPlayer *player;
    u32 species[6];
    u32 species2[6];

    for (i = 0; i < a1; i++)
    {
        species2[i] = GetMonData(&monList[i], MON_DATA_SPECIES2);
        species[i] = GetMonData(&monList[i], MON_DATA_SPECIES);
    }

    if (!IsNationalPokedexEnabled())
    {
        if (species2[monIdx] == SPECIES_EGG)
        {
            return 3;
        }

        if (!IsSpeciesInHoennDex(species2[monIdx]))
        {
            return 2;
        }
    }

    player = &gLinkPlayers[GetMultiplayerId() ^ 1];
    if ((player->version & 0xFF) != VERSION_RUBY &&
        (player->version & 0xFF) != VERSION_SAPPHIRE)
    {
        if ((player->name[10] & 0xF) == 0)
        {
            if (species2[monIdx] == SPECIES_EGG)
            {
                return 5;
            }

            if (!IsSpeciesInHoennDex(species2[monIdx]))
            {
                return 4;
            }
        }
    }

    if (species[monIdx] == SPECIES_DEOXYS || species[monIdx] == SPECIES_MEW)
    {
        if (!GetMonData(&monList[monIdx], MON_DATA_OBEDIENCE))
        {
            return 4;
        }
    }

    for (i = 0; i < a1; i++)
    {
        if (species2[i] == SPECIES_EGG)
        {
            species2[i] = SPECIES_NONE;
        }
    }

    for (sum = 0, i = 0; i < a1; i++)
    {
        if (i != monIdx)
        {
            sum += species2[i];
        }
    }

    if (sum != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

s32 sub_807A728(void)
{
    s32 val;
    u16 version;

    if (gReceivedRemoteLinkPlayers != 0)
    {
        val = 0;
        version = (gLinkPlayers[GetMultiplayerId() ^ 1].version & 0xFF);

        if (version == VERSION_RUBY || version == VERSION_SAPPHIRE || version == VERSION_EMERALD)
        {
            // this value could actually be anything 0 or less
            val = 0;
        }
        else if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
        {
            val = 2;
        }

        if (val > 0)
        {
            if (gLinkPlayers[GetMultiplayerId()].name[10] & 0xF0)
            {
                if (val == 2)
                {
                    if (gLinkPlayers[GetMultiplayerId() ^ 1].name[10] & 0xF0)
                    {
                        return 0;
                    }
                    else
                    {
                        return 2;
                    }
                }
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

static bool32 IsDeoxysOrMewUntradable(u16 species, bool8 isObedientBitSet)
{
    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!isObedientBitSet)
            return TRUE;
    }
    return FALSE;
}

int sub_807A7E0(struct UnkLinkRfuStruct_02022B14Substruct a0, struct UnkLinkRfuStruct_02022B14Substruct a1, u16 species1, u16 species2, u8 type, u16 species3, u8 isObedientBitSet)
{
    u8 r9 = a0.unk_01_0;
    u8 r2 = a0.unk_00_7;
    u8 r10 = a1.unk_01_0;
    u8 r0 = a1.unk_00_7;
    u8 r1 = a1.unk_01_2;

    if (r1 != 3)
    {
        if (!r2)
        {
            return 8;
        }
        else if (!r0)
        {
            return 9;
        }
    }

    if (IsDeoxysOrMewUntradable(species3, isObedientBitSet))
    {
        return 4;
    }

    if (species2 == SPECIES_EGG)
    {
        if (species1 != species2)
        {
            return 2;
        }
    }
    else
    {
        if (gBaseStats[species1].type1 != type && gBaseStats[species1].type2 != type)
        {
            return 1;
        }
    }

    if (species1 == SPECIES_EGG && species1 != species2)
    {
        return 3;
    }

    if (!r9)
    {
        if (species1 == SPECIES_EGG)
        {
            return 6;
        }

        if (!IsSpeciesInHoennDex(species1))
        {
            return 4;
        }

        if (!IsSpeciesInHoennDex(species2))
        {
            return 5;
        }
    }

    if (!r10 && !IsSpeciesInHoennDex(species1))
    {
        return 7;
    }

    return 0;
}

int sub_807A8D0(struct UnkLinkRfuStruct_02022B14Substruct a0, u16 species, u16 a2, u8 a3)
{
    u8 unk = a0.unk_01_0;

    if (IsDeoxysOrMewUntradable(a2, a3))
    {
        return 1;
    }

    if (unk)
    {
        return 0;
    }

    if (species == SPECIES_EGG)
    {
        return 2;
    }

    if (IsSpeciesInHoennDex(species))
    {
        return 0;
    }

    return 1;
}

// r6/r7 flip. Ugh.
#ifdef NONMATCHING
int sub_807A918(struct Pokemon *mon, u16 monIdx)
{
    int i, version, versions, unk, unk2;
    int speciesArray[PARTY_SIZE];

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        speciesArray[i] = GetMonData(&mon[i], MON_DATA_SPECIES2);
        if (speciesArray[i] == SPECIES_EGG)
        {
            speciesArray[i] = 0;
        }
    }

    versions = 0;
    unk = 1;
    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        version = gLinkPlayers[i].version & 0xFF;
        if (version == VERSION_FIRE_RED ||
            version == VERSION_LEAF_GREEN)
        {
            versions = 0;
        }
        else
        {
            versions |= 1;
        }
    }

    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        struct LinkPlayer *player = &gLinkPlayers[i];
        if ((player->name[8] & 0xF) == 0)
        {
            unk = 0;
        }

        if (versions && (player->name[8] / 16))
        {
            unk = 0;
        }
    }

    if (unk == 0)
    {
        if (!IsSpeciesInHoennDex(speciesArray[monIdx]))
        {
            return 2;
        }

        if (speciesArray[monIdx] == SPECIES_NONE)
        {
            return 3;
        }
    }

    unk2 = 0;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (monIdx != i)
        {
            unk2 += speciesArray[i];
        }
    }

    if (!unk2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#else
NAKED
int sub_807A918(struct Pokemon *mon, u16 a1)
{
    asm_unified("push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	sub sp, 0x18\n\
	adds r6, r0, 0\n\
	lsls r1, 16\n\
	lsrs r1, 16\n\
	mov r8, r1\n\
	movs r5, 0\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	bge _0807A95A\n\
	mov r4, sp\n\
_0807A934:\n\
	movs r0, 0x64\n\
	muls r0, r5\n\
	adds r0, r6, r0\n\
	movs r1, 0x41\n\
	bl GetMonData\n\
	str r0, [r4]\n\
	movs r1, 0xCE\n\
	lsls r1, 1\n\
	cmp r0, r1\n\
	bne _0807A94E\n\
	movs r0, 0\n\
	str r0, [r4]\n\
_0807A94E:\n\
	adds r4, 0x4\n\
	adds r5, 0x1\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r5, r0\n\
	blt _0807A934\n\
_0807A95A:\n\
	movs r7, 0\n\
	movs r6, 0x1\n\
	movs r5, 0\n\
	ldr r4, =gLinkPlayers\n\
	b _0807A980\n\
	.pool\n\
_0807A96C:\n\
	ldrb r0, [r4]\n\
	subs r0, 0x4\n\
	cmp r0, 0x1\n\
	bhi _0807A978\n\
	movs r7, 0\n\
	b _0807A97C\n\
_0807A978:\n\
	movs r0, 0x1\n\
	orrs r7, r0\n\
_0807A97C:\n\
	adds r4, 0x1C\n\
	adds r5, 0x1\n\
_0807A980:\n\
	bl GetLinkPlayerCount\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r5, r0\n\
	blt _0807A96C\n\
	movs r5, 0\n\
	movs r4, 0\n\
	b _0807A9B4\n\
_0807A992:\n\
	ldr r0, =gLinkPlayers\n\
	adds r2, r4, r0\n\
	ldrb r1, [r2, 0x10]\n\
	movs r0, 0xF\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	bne _0807A9A2\n\
	movs r6, 0\n\
_0807A9A2:\n\
	cmp r7, 0\n\
	beq _0807A9B0\n\
	ldrb r0, [r2, 0x10]\n\
	lsrs r0, 4\n\
	cmp r0, 0\n\
	beq _0807A9B0\n\
	movs r6, 0\n\
_0807A9B0:\n\
	adds r4, 0x1C\n\
	adds r5, 0x1\n\
_0807A9B4:\n\
	bl GetLinkPlayerCount\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	cmp r5, r0\n\
	blt _0807A992\n\
	cmp r6, 0\n\
	bne _0807A9EA\n\
	mov r1, r8\n\
	lsls r0, r1, 2\n\
	mov r1, sp\n\
	adds r4, r1, r0\n\
	ldrh r0, [r4]\n\
	bl IsSpeciesInHoennDex\n\
	cmp r0, 0\n\
	bne _0807A9E0\n\
	movs r0, 0x2\n\
	b _0807AA1A\n\
	.pool\n\
_0807A9E0:\n\
	ldr r0, [r4]\n\
	cmp r0, 0\n\
	bne _0807A9EA\n\
	movs r0, 0x3\n\
	b _0807AA1A\n\
_0807A9EA:\n\
	movs r2, 0\n\
	movs r5, 0\n\
	ldr r0, =gPlayerPartyCount\n\
	ldrb r0, [r0]\n\
	cmp r2, r0\n\
	bge _0807AA0A\n\
	adds r3, r0, 0\n\
	mov r1, sp\n\
_0807A9FA:\n\
	cmp r8, r5\n\
	beq _0807AA02\n\
	ldr r0, [r1]\n\
	adds r2, r0\n\
_0807AA02:\n\
	adds r1, 0x4\n\
	adds r5, 0x1\n\
	cmp r5, r3\n\
	blt _0807A9FA\n\
_0807AA0A:\n\
	cmp r2, 0\n\
	beq _0807AA18\n\
	movs r0, 0\n\
	b _0807AA1A\n\
	.pool\n\
_0807AA18:\n\
	movs r0, 0x1\n\
_0807AA1A:\n\
	add sp, 0x18\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r1}\n\
	bx r1");
}
#endif // NONMATCHING

static void sub_807AA28(struct Sprite *sprite)
{
    if (++sprite->data[0] == 10)
    {
        PlaySE(SE_BOWA);
        sprite->data[0] = 0;
    }
}

static void sub_807AA4C(struct Sprite *sprite)
{
    if (!sprite->invisible && ++sprite->data[0] == 10)
    {
        PlaySE(SE_W207B);
        sprite->data[0] = 0;
    }
}

static void sub_807AA7C(struct Sprite *sprite)
{
    if (!sprite->data[1])
    {
        if (++sprite->data[0] == 12)
            sprite->data[0] = 0;

        LoadPalette(&gUnknown_08338EA4[sprite->data[0]], (sprite->oam.paletteNum + 16) * 16 + 4, 2);
    }
}

static void sub_807AABC(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->pos2.y++;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

static void sub_807AAE0(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->pos2.y--;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

static void sub_807AB04(struct Sprite *sprite)
{
    if (++sprite->data[0] == 15)
    {
        PlaySE(SE_W107);
        sprite->data[0] = 0;
    }
}

static void sub_807AB28(void)
{
    struct BgAffineDstData affine;

    DoBgAffineSet(&affine, gUnknown_020322A0->unk_D4 * 0x100, gUnknown_020322A0->unk_D6 * 0x100, gUnknown_020322A0->unk_DC, gUnknown_020322A0->unk_DE, gUnknown_020322A0->unk_E8, gUnknown_020322A0->unk_E8, gUnknown_020322A0->unk_EC);
    SetGpuReg(REG_OFFSET_BG2PA, affine.pa);
    SetGpuReg(REG_OFFSET_BG2PB, affine.pb);
    SetGpuReg(REG_OFFSET_BG2PC, affine.pc);
    SetGpuReg(REG_OFFSET_BG2PD, affine.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, affine.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, affine.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, affine.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, affine.dy >> 16);
}

static void sub_807ABCC(void)
{
    u16 dispcnt;

    SetGpuReg(REG_OFFSET_BG1VOFS, gUnknown_020322A0->bg1vofs);
    SetGpuReg(REG_OFFSET_BG1HOFS, gUnknown_020322A0->bg1hofs);

    dispcnt = GetGpuReg(REG_OFFSET_DISPCNT);
    if ((dispcnt & 7) == DISPCNT_MODE_0)
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, gUnknown_020322A0->bg2vofs);
        SetGpuReg(REG_OFFSET_BG2HOFS, gUnknown_020322A0->bg2hofs);
    }
    else
    {
        sub_807AB28();
    }
}

static void sub_807AC24(void)
{
    sub_807ABCC();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_807AC3C(void)
{
    gUnknown_020322A0->unk_8A = 0;
    gUnknown_020322A0->unk_88 = 0;
    gUnknown_020322A0->unk_89 = 0;
}

static void sub_807AC64(void)
{
    if (gUnknown_020322A0->unk_88 == gUnknown_020322A0->unk_89)
        gUnknown_020322A0->unk_8A++;
    else
        gUnknown_020322A0->unk_8A = 0;

    if (gUnknown_020322A0->unk_8A > 300)
    {
        CloseLink();
        SetMainCallback2(CB2_LinkError);
        gUnknown_020322A0->unk_8A = 0;
        gUnknown_020322A0->unk_89 = 0;
        gUnknown_020322A0->unk_88 = 0;
    }

    gUnknown_020322A0->unk_89 = gUnknown_020322A0->unk_88;
}

static u32 sub_807ACDC(void)
{
    if (gReceivedRemoteLinkPlayers)
        return GetMultiplayerId();
    return 0;
}

static void sub_807ACFC(u8 whichParty, u8 a1)
{
    int pos = 0;
    struct Pokemon *mon = NULL;
    u16 species;
    u32 personality;

    if (whichParty == 0)
    {
        mon = &gPlayerParty[gUnknown_02032298[0]];
        pos = 1;
    }

    if (whichParty == 1)
    {
        mon = &gEnemyParty[gUnknown_02032298[1] % PARTY_SIZE];
        pos = 3;
    }

    switch (a1)
    {
        case 0:
            species = GetMonData(mon, MON_DATA_SPECIES2);
            personality = GetMonData(mon, MON_DATA_PERSONALITY);

            if (whichParty == 0)
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[1], species, personality);
            else
                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites[whichParty * 2 + 1], species, personality);

            LoadCompressedSpritePalette(GetMonSpritePalStruct(mon));
            gUnknown_020322A0->tradeSpecies[whichParty] = species;
            gUnknown_020322A0->unk_68[whichParty] = personality;
            break;
        case 1:
            SetMultiuseSpriteTemplateToPokemon(GetMonSpritePalStruct(mon)->tag, pos);
            gUnknown_020322A0->pokePicSpriteIdxs[whichParty] = CreateSprite(&gMultiuseSpriteTemplate, 120, 60, 6);
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[whichParty]].invisible = TRUE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[whichParty]].callback = SpriteCallbackDummy;
            break;
    }
}

void sub_807AE50(void)
{
    switch (gMain.state)
    {
        case 0:
            if (!gReceivedRemoteLinkPlayers)
            {
                gLinkType = 0x1144;
                CloseLink();
            }
            gUnknown_020322A0 = AllocZeroed(sizeof(*gUnknown_020322A0));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(sub_807AC24);
            sub_807B170();
            sub_807AC3C();
            gMain.state++;
            gUnknown_020322A0->unk_8C = 0;
            gUnknown_020322A0->state = 0;
            gUnknown_020322A0->isLinkTrade = TRUE;
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 64;
            gUnknown_020322A0->unk_D8 = 0;
            gUnknown_020322A0->unk_DA = 0;
            gUnknown_020322A0->unk_DC = 120;
            gUnknown_020322A0->unk_DE = 80;
            gUnknown_020322A0->unk_E8 = 256;
            gUnknown_020322A0->unk_EC = 0;
            break;
        case 1:
            if (!gReceivedRemoteLinkPlayers)
            {
                gUnknown_020322A0->unk_FA = 1;
                OpenLink();
                gMain.state++;
                gUnknown_020322A0->timer = 0;
            }
            else
            {
                gMain.state = 4;
            }
            break;
        case 2:
            if (++gUnknown_020322A0->timer > 60)
            {
                gUnknown_020322A0->timer = 0;
                gMain.state++;
            }
            break;
        case 3:
            if (IsLinkMaster())
            {
                if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
                {
                    if (++gUnknown_020322A0->timer > 30)
                    {
                        CheckShouldAdvanceLinkState();
                        gMain.state++;
                    }
                }
                else
                {
                    sub_807AC64();
                }
            }
            else
            {
                gMain.state++;
            }
            break;
        case 4:
            sub_807AC64();
            if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
                gMain.state++;
            break;
        case 5:
            gUnknown_020322A0->unk_72 = 0;
            gUnknown_020322A0->unk_73 = 0;
            gUnknown_020322A0->unk_93 = 0;
            sub_807ACFC(0, 0);
            gMain.state++;
            break;
        case 6:
            sub_807ACFC(0, 1);
            gMain.state++;
            break;
        case 7:
            sub_807ACFC(1, 0);
            gMain.state++;
            break;
        case 8:
            sub_807ACFC(1, 1);
            sub_807B154();
            gMain.state++;
            break;
        case 9:
            sub_807BA94();
            LoadSpriteSheet(&gUnknown_08338D18);
            LoadSpritePalette(&gUnknown_08338D20);
            gMain.state++;
            break;
        case 10:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            ShowBg(0);
            gMain.state++;
            break;
        case 11:
            sub_807B140();
            SetTradeSceneStrings();
            gMain.state++;
            break;
        case 12:
            if (!gPaletteFade.active)
            {
                if (gWirelessCommType)
                {
                    LoadWirelessStatusIndicatorSpriteGfx();
                    CreateWirelessStatusIndicatorSprite(0, 0);
                }
                SetMainCallback2(sub_807EA2C);
            }
            break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_807B140(void)
{
    sub_807B62C(5);
    sub_807B62C(0);
}

void sub_807B154(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
}

static void sub_807B170(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08339014, ARRAY_COUNT(gUnknown_08339014));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    SetBgTilemapBuffer(0, Alloc(0x800));
    SetBgTilemapBuffer(1, Alloc(0x800));
    SetBgTilemapBuffer(3, Alloc(0x800));
    DeactivateAllTextPrinters();
    DecompressAndLoadBgGfxUsingHeap(0, gBattleTextboxTiles, 0, 0, 0);
    LZDecompressWram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, 0x800, 0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x20);
    InitWindows(gUnknown_08338FFC);
    DecompressAndLoadBgGfxUsingHeap(0, gBattleTextboxTiles, 0, 0, 0);
    LZDecompressWram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, 0x800, 0);
    LoadCompressedPalette(gBattleTextboxPalette, 0, 0x20);
}

// In-game trade init
static void sub_807B270(void)
{
    u8 otName[11];

    switch (gMain.state)
    {
        case 0:
            gUnknown_02032298[0] = gSpecialVar_0x8005;
            gUnknown_02032298[1] = 6;
            StringCopy(gLinkPlayers[0].name, gSaveBlock2Ptr->playerName);
            GetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, otName);
            StringCopy(gLinkPlayers[1].name, otName);
            gLinkPlayers[0].language = LANGUAGE_ENGLISH;
            gLinkPlayers[1].language = GetMonData(&gEnemyParty[0], MON_DATA_LANGUAGE);
            gUnknown_020322A0 = AllocZeroed(sizeof(*gUnknown_020322A0));
            AllocateMonSpritesGfx();
            ResetTasks();
            ResetSpriteData();
            FreeAllSpritePalettes();
            SetVBlankCallback(sub_807AC24);
            sub_807B170();
            gUnknown_020322A0->isLinkTrade = FALSE;
            gUnknown_020322A0->unk_8C = 0;
            gUnknown_020322A0->state = 0;
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 64;
            gUnknown_020322A0->unk_D8 = 0;
            gUnknown_020322A0->unk_DA = 0;
            gUnknown_020322A0->unk_DC = 120;
            gUnknown_020322A0->unk_DE = 80;
            gUnknown_020322A0->unk_E8 = 256;
            gUnknown_020322A0->unk_EC = 0;
            gUnknown_020322A0->timer = 0;
            gMain.state = 5;
            break;
        case 5:
            sub_807ACFC(0, 0);
            gMain.state++;
            break;
        case 6:
            sub_807ACFC(0, 1);
            gMain.state++;
            break;
        case 7:
            sub_807ACFC(1, 0);
            ShowBg(0);
            gMain.state++;
            break;
        case 8:
            sub_807ACFC(1, 1);
            FillWindowPixelBuffer(0, PIXEL_FILL(15));
            PutWindowTilemap(0);
            CopyWindowToVram(0, 3);
            gMain.state++;
            break;
        case 9:
            sub_807BA94();
            LoadSpriteSheet(&gUnknown_08338D18);
            LoadSpritePalette(&gUnknown_08338D20);
            gMain.state++;
            break;
        case 10:
            ShowBg(0);
            gMain.state++;
            break;
        case 11:
            sub_807B62C(5);
            sub_807B62C(0);
            SetTradeSceneStrings();
            gMain.state++;
            break;
        case 12:
            SetMainCallback2(sub_807B60C);
            break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807B464(u8 partyIdx)
{
    struct Pokemon *mon = &gPlayerParty[partyIdx];

    if (!GetMonData(mon, MON_DATA_IS_EGG))
    {
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
        species = SpeciesToNationalPokedexNum(species);
        GetSetPokedexFlag(species, FLAG_SET_SEEN);
        HandleSetPokedexFlag(species, FLAG_SET_CAUGHT, personality);
    }
}

static void sub_807B4C4(void)
{
    u8 mpId = GetMultiplayerId();
    // Originally in Ruby but commented out
    /*if (gLinkPlayers[mpId ^ 1].lp_field_2 == 0x8000)
        EnableNationalPokedex();*/
}

static void sub_807B4D0(u8 a0, u8 a1)
{
    u8 friendship;

    struct Pokemon *playerMon = &gPlayerParty[a0];
    u16 playerMail = GetMonData(playerMon, MON_DATA_MAIL);

    struct Pokemon *partnerMon = &gEnemyParty[a1];
    u16 partnerMail = GetMonData(partnerMon, MON_DATA_MAIL);

    if (playerMail != 0xFF)
        ClearMailStruct(&gSaveBlock1Ptr->mail[playerMail]);

    // This is where the actual trade happens!!
    gUnknown_020322A0->mon = *playerMon;
    *playerMon = *partnerMon;
    *partnerMon = gUnknown_020322A0->mon;

    friendship = 70;
    if (!GetMonData(playerMon, MON_DATA_IS_EGG))
        SetMonData(playerMon, MON_DATA_FRIENDSHIP, &friendship);

    if (partnerMail != 0xFF)
        GiveMailToMon2(playerMon, &gUnknown_020321C0[partnerMail]);

    sub_807B464(a0);
    if (gReceivedRemoteLinkPlayers)
        sub_807B4C4();
}

static void sub_807B5B8(void)
{
    switch (gUnknown_020322A0->unk_93)
    {
        case 1:
            if (IsLinkTaskFinished())
            {
                Trade_SendData(gUnknown_020322A0);
                gUnknown_020322A0->unk_93++;
            }
            // fallthrough
        case 2:
            gUnknown_020322A0->unk_93 = 0;
            break;
    }
}

static void sub_807B60C(void)
{
    sub_807BBC8();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807B62C(u8 a0)
{
    switch (a0)
    {
        case 0:
            gUnknown_020322A0->bg2vofs = 0;
            gUnknown_020322A0->bg2hofs = 180;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT512x256);
            LoadPalette(gTradeGba2_Pal, 16, 0x60);
            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
            DmaCopy16Defvars(3, gUnknown_08331F60, (void *) BG_SCREEN_ADDR(18), 0x1000);
            break;
        case 1:
            gUnknown_020322A0->bg1hofs = 0;
            gUnknown_020322A0->bg1vofs = 348;
            SetGpuReg(REG_OFFSET_BG1VOFS, 348);
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(0) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(5) |
                                         BGCNT_TXT256x512);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT256x512);

            if (gUnknown_020322A0->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083369A0, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083359A0, (void *) BG_SCREEN_ADDR(5), 0x1000);
            }

            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(0), 0x1420, 0x1000);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 2:
            gUnknown_020322A0->bg1vofs = 0;
            gUnknown_020322A0->bg1hofs = 0;
            if (!gUnknown_020322A0->unk_FA)
            {
                SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                              DISPCNT_OBJ_1D_MAP |
                                              DISPCNT_BG1_ON |
                                              DISPCNT_OBJ_ON);
                LZ77UnCompVram(gUnknown_083379A0, (void *) BG_SCREEN_ADDR(5));
                BlendPalettes(0x8, 16, RGB_BLACK);
            }
            else
            {
                SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                              DISPCNT_OBJ_1D_MAP |
                                              DISPCNT_BG1_ON |
                                              DISPCNT_OBJ_ON);
                DmaCopy16Defvars(3, gUnknown_0832FFC0, (void *) BG_SCREEN_ADDR(5), 0x800);
                BlendPalettes(0x1, 16, RGB_BLACK);
            }
            break;
        case 3:
            LoadPalette(gUnknown_08337EA0, 48, 0x20);
            LZ77UnCompVram(gUnknown_08337EC0, (void *) BG_CHAR_ADDR(1));
            LZ77UnCompVram(gUnknown_08338550, (void *) BG_SCREEN_ADDR(18));
            gUnknown_020322A0->bg2vofs = 80;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 4:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_256COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_AFF128x128);
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 92;
            gUnknown_020322A0->unk_E8 = 32;
            gUnknown_020322A0->unk_EA = 1024;
            gUnknown_020322A0->unk_EC = 0;

            DmaCopyLarge16(3, gUnknown_08332F60, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

            if (gUnknown_020322A0->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083357A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083358A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 5:
            gUnknown_020322A0->bg1vofs = 0;
            gUnknown_020322A0->bg1hofs = 0;
            break;
        case 6:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_256COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_AFF128x128);
            gUnknown_020322A0->unk_D4 = 64;
            gUnknown_020322A0->unk_D6 = 92;
            gUnknown_020322A0->unk_E8 = 256;
            gUnknown_020322A0->unk_EA = 128;
            gUnknown_020322A0->unk_DC = 120;
            gUnknown_020322A0->unk_DE = 80;
            gUnknown_020322A0->unk_EC = 0;

            DmaCopyLarge16(3, gUnknown_08332F60, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

            if (gUnknown_020322A0->unk_FA)
            {
                DmaCopy16Defvars(3, gUnknown_083357A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            else
            {
                DmaCopy16Defvars(3, gUnknown_083358A0, (void *) BG_SCREEN_ADDR(18), 0x100);
            }
            break;
        case 7:
            gUnknown_020322A0->bg2vofs = 0;
            gUnknown_020322A0->bg2hofs = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) |
                                         BGCNT_CHARBASE(1) |
                                         BGCNT_16COLOR |
                                         BGCNT_SCREENBASE(18) |
                                         BGCNT_TXT512x256);
            LoadPalette(gTradeGba2_Pal, 16, 0x60);
            DmaCopyLarge16(3, gTradeGba_Gfx, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
            DmaCopy16Defvars(3, gUnknown_08331F60, (void *) BG_SCREEN_ADDR(18), 0x1000);
            break;
    }
}

static void sub_807BA94(void)
{
    LoadSpriteSheet(&gUnknown_08338D70);
    LoadSpriteSheet(&gUnknown_08338DC0);
    LoadSpriteSheet(&gUnknown_08338DF4);
    LoadSpriteSheet(&gUnknown_08338E6C);
    LoadSpritePalette(&gUnknown_08338D78);
    LoadSpritePalette(&gUnknown_08338D80);
}

static void SetTradeSceneStrings(void)
{
    /*Sets the variable strings printed on the
     *actual trading screen. For use in strings
     *like "[Pokemon] will be sent to [Trainer]."
     */
    u8 mpId;
    u8 name[20];
    const struct InGameTrade *ingameTrade;

    if (gUnknown_020322A0->isLinkTrade)
    {
        mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData(&gEnemyParty[gUnknown_02032298[1] % PARTY_SIZE], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar3, name);
        GetMonData(&gPlayerParty[gUnknown_02032298[0]], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
    else
    {
        ingameTrade = &gIngameTrades[gSpecialVar_0x8004];
        StringCopy(gStringVar1, ingameTrade->otName);
        StringCopy10(gStringVar3, ingameTrade->name);
        GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
}

static u8 sub_807BBC8(void)
{
    if (gUnknown_020322A0->unk_FA)
    {
        return sub_807BBEC();
    }
    else
    {
        return sub_807CFC8();
    }
}

static bool8 sub_807BBEC(void)
{
    u16 evoTarget;

    switch (gUnknown_020322A0->state)
    {
        case 0:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = -180;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[0]].y_offset;
            gUnknown_020322A0->state++;
            gUnknown_020322A0->cachedMapMusic = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (gUnknown_020322A0->bg2hofs > 0)
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x += 3;
                gUnknown_020322A0->bg2hofs -= 3;
            }
            else
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = 0;
                gUnknown_020322A0->bg2hofs = 0;
                gUnknown_020322A0->state = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            sub_807F1A8(0, gStringVar4, 0);

            if (gUnknown_020322A0->tradeSpecies[0] != SPECIES_EGG)
            {
                PlayCry1(gUnknown_020322A0->tradeSpecies[0], 0);
            }

            gUnknown_020322A0->state = 11;
            gUnknown_020322A0->timer = 0;
            break;
        case 11:
            if (++gUnknown_020322A0->timer == 80)
            {
                gUnknown_020322A0->unk_D2 = sub_807671C(gUnknown_020322A0->pokePicSpriteIdxs[0], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                gUnknown_020322A0->state++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                sub_807F1A8(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[gUnknown_020322A0->unk_D2].callback == SpriteCallbackDummy)
            {
                gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_D2]);
                gUnknown_020322A0->state++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, PIXEL_FILL(15));
                CopyWindowToVram(0, 3);
                gUnknown_020322A0->state++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state = 23;
            }
            break;
        case 23:
            if (gUnknown_020322A0->unk_EA > 0x100)
            {
                gUnknown_020322A0->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                gUnknown_020322A0->unk_EA = 0x80;
                gUnknown_020322A0->state++;
                gUnknown_020322A0->timer = 0;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 24:
            if (++gUnknown_020322A0->timer > 20)
            {
                sub_807AB28();
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
                gUnknown_020322A0->state++;
            }
            break;
        case 25:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG1 |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 4));
                gUnknown_020322A0->state++;
            }
            break;
        case 26:
            if (--gUnknown_020322A0->bg1vofs == 316)
            {
                gUnknown_020322A0->state++;
            }
            if (gUnknown_020322A0->bg1vofs == 328)
            {
                gUnknown_020322A0->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
            }
            break;
        case 27:
            gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 128, 80, 3);
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, 80, 0);
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            gUnknown_020322A0->state++;
            break;
        case 28:
            if ((gUnknown_020322A0->bg1vofs -= 2) == 166)
            {
                gUnknown_020322A0->state = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[gUnknown_020322A0->unk_90].pos1.y -= 2;
            gSprites[gUnknown_020322A0->unk_91].pos1.y -= 2;
            if (gSprites[gUnknown_020322A0->unk_90].pos1.y < -8)
            {
                gUnknown_020322A0->state = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(2);
                gUnknown_020322A0->state++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            gUnknown_020322A0->state++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                gUnknown_020322A0->state++;
            }
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -90)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 1;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 1;
                gUnknown_020322A0->state++;
            }
            break;
        case 34:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 35:
            BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 36:
            BlendPalettes(0x1, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(gUnknown_020322A0->tradeSpecies[0]))
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.x = 60;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 180;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.y = 192;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = -32;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = FALSE;
            gUnknown_020322A0->state++;
            break;
        case 38:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y -= 3;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -160 && gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -222)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 0;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 0;
                gUnknown_020322A0->state++;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = TRUE;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = TRUE;
                BlendPalettes(0x1, 0, RGB_WHITEALPHA);
            }
            break;
        case 39:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                gUnknown_020322A0->state++;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state++;
                sub_807B62C(1);
                gUnknown_020322A0->bg1vofs = 166;
                gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 128, -20, 3);
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 128, -20, 0);
                StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 43:
            gSprites[gUnknown_020322A0->unk_90].pos2.y += 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y + gSprites[gUnknown_020322A0->unk_90].pos1.y == 64)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 44:
            if ((gUnknown_020322A0->bg1vofs += 2) > 316)
            {
                gUnknown_020322A0->bg1vofs = 316;
                gUnknown_020322A0->state++;
            }
            break;
        case 45:
            DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            gUnknown_020322A0->state++;
            gUnknown_020322A0->timer = 0;
            break;
        case 46:
            if (++gUnknown_020322A0->timer == 10)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 47:
            if (++gUnknown_020322A0->bg1vofs > 348)
            {
                gUnknown_020322A0->bg1vofs = 348;
                gUnknown_020322A0->state++;
            }
            if (gUnknown_020322A0->bg1vofs == 328 && gUnknown_020322A0->unk_FA)
            {
                gUnknown_020322A0->unk_92 = CreateSprite(&gSpriteTemplate_8338DFC, 128, 65, 0);
                gSprites[gUnknown_020322A0->unk_92].callback = sub_807AAE0;
            }
            break;
        case 48:
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            gUnknown_020322A0->state = 50;
            break;
        case 50:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(6);
                gUnknown_020322A0->state++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (gUnknown_020322A0->unk_EA < 0x400)
            {
                gUnknown_020322A0->unk_EA += 0x34;
            }
            else
            {
                gUnknown_020322A0->unk_EA = 0x400;
                gUnknown_020322A0->state++;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state = 60;
            break;

        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                gUnknown_020322A0->state++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 63:
            gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[gUnknown_020322A0->unk_D3].data[3] = 74;
            gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            gUnknown_020322A0->timer = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 65:
            if (gSprites[gUnknown_020322A0->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[gUnknown_020322A0->tradeSpecies[1]], gMonSpritesGfxPtr->sprites[3], gUnknown_020322A0->tradeSpecies[1], gUnknown_020322A0->unk_68[1]);
                gUnknown_020322A0->state++;
            }
            break;
        case 66:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 120;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[1]].y_offset + 60;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.x = 0;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y = 0;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            CreatePokeballSpriteToReleaseMon(gUnknown_020322A0->pokePicSpriteIdxs[1], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, gUnknown_020322A0->tradeSpecies[1]);
            FreeSpriteOamMatrix(&gSprites[gUnknown_020322A0->unk_D3]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_D3]);
            gUnknown_020322A0->state++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            sub_807F1A8(0, gStringVar4, 0);
            gUnknown_020322A0->state = 167;
            gUnknown_020322A0->timer = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++gUnknown_020322A0->timer > 60)
            {
                gUnknown_020322A0->state = 267;
                gUnknown_020322A0->timer = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                gUnknown_020322A0->state = 68;
            }
            break;
        case 68:
            if (++gUnknown_020322A0->timer == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (gUnknown_020322A0->timer == 250)
            {
                gUnknown_020322A0->state++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                sub_807F1A8(0, gStringVar4, 0);
                gUnknown_020322A0->timer = 0;
            }
            break;
        case 69:
            if (++gUnknown_020322A0->timer == 60)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 70:
            sub_807F14C();
            gUnknown_020322A0->state++;
            break;
        case 71:
            if (gUnknown_020322A0->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 72: // Only if in-game trade
            sub_807B4D0(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gUnknown_02032298[0]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gUnknown_02032298[0]], evoTarget, gUnknown_020322A0->pokePicSpriteIdxs[1], gUnknown_02032298[0]);
            }
            gUnknown_020322A0->state++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(gUnknown_020322A0->cachedMapMusic);
                if (gUnknown_020322A0)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(gUnknown_020322A0);
                }
                SetMainCallback2(CB2_ReturnToField);
                sub_807E784();
            }
            break;
    }
    return FALSE;
}

static bool8 sub_807CFC8(void)
{
    u16 evoTarget;

    switch (gUnknown_020322A0->state)
    {
        case 0:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = -180;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[0]].y_offset;
            gUnknown_020322A0->state++;
            gUnknown_020322A0->cachedMapMusic = GetCurrentMapMusic();
            PlayNewMapMusic(MUS_SHINKA);
            break;
        case 1:
            if (gUnknown_020322A0->bg2hofs > 0)
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x += 3;
                gUnknown_020322A0->bg2hofs -= 3;
            }
            else
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.x = 0;
                gUnknown_020322A0->bg2hofs = 0;
                gUnknown_020322A0->state = 10;
            }
            break;
        case 10:
            StringExpandPlaceholders(gStringVar4, gText_XWillBeSentToY);
            sub_807F1A8(0, gStringVar4, 0);

            if (gUnknown_020322A0->tradeSpecies[0] != SPECIES_EGG)
            {
                PlayCry1(gUnknown_020322A0->tradeSpecies[0], 0);
            }

            gUnknown_020322A0->state = 11;
            gUnknown_020322A0->timer = 0;
            break;
        case 11:
            if (++gUnknown_020322A0->timer == 80)
            {
                gUnknown_020322A0->unk_D2 = sub_807671C(gUnknown_020322A0->pokePicSpriteIdxs[0], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
                gUnknown_020322A0->state++;
                StringExpandPlaceholders(gStringVar4, gText_ByeByeVar1);
                sub_807F1A8(0, gStringVar4, 0);
            }
            break;
        case 12:
            if (gSprites[gUnknown_020322A0->unk_D2].callback == SpriteCallbackDummy)
            {
                gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, 32, 0);
                gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E5D8;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_D2]);
                gUnknown_020322A0->state++;
            }
            break;
        case 13:
            // The game waits here for the sprite to finish its animation sequence.
            break;
        case 14:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state = 20;
            break;
        case 20:
            if (!gPaletteFade.active)
            {
                sub_807B62C(4);
                FillWindowPixelBuffer(0, PIXEL_FILL(15));
                CopyWindowToVram(0, 3);
                gUnknown_020322A0->state++;
            }
            break;
        case 21:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 22:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state = 23;
            }
            break;
        case 23:
            if (gUnknown_020322A0->unk_EA > 0x100)
            {
                gUnknown_020322A0->unk_EA -= 0x34;
            }
            else
            {
                sub_807B62C(1);
                gUnknown_020322A0->unk_EA = 0x80;
                gUnknown_020322A0->state = 124;
                gUnknown_020322A0->timer = 0;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 124:
            if (++gUnknown_020322A0->timer > 20)
            {
                sub_807B62C(3);
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E8C, 120, 80, 0);
                gUnknown_020322A0->state++;
            }
            break;
        case 125:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 |
                                             BLDCNT_TGT1_OBJ |
                                             BLDCNT_EFFECT_BLEND |
                                             BLDCNT_TGT2_BG2);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 4));
                CreateTask(c3_08054588, 5);
                gUnknown_020322A0->state++;
            }
            break;
        case 126:
            if (!FuncIsActiveTask(c3_08054588))
            {
                gUnknown_020322A0->state = 26;
            }
            break;
        case 26:
            if (--gUnknown_020322A0->bg1vofs == 316)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 27:
            gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 120, 80, 3);
            gSprites[gUnknown_020322A0->unk_90].callback = sub_807AA4C;
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, 80, 0);
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            gUnknown_020322A0->state++;
            break;
        case 28:
            if ((gUnknown_020322A0->bg1vofs -= 3) == 166)
            {
                gUnknown_020322A0->state = 200;
            }
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            break;
        case 200:
            gSprites[gUnknown_020322A0->unk_90].pos1.y -= 2;
            gSprites[gUnknown_020322A0->unk_91].pos1.y -= 2;
            if (gSprites[gUnknown_020322A0->unk_90].pos1.y < -8)
            {
                gUnknown_020322A0->state = 29;
            }
            break;
        case 29:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state = 30;
            break;
        case 30:
            if (!gPaletteFade.active)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(2);
                gUnknown_020322A0->state++;
            }
            break;
        case 31:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->unk_90 = CreateSprite(&gSpriteTemplate_8338DC8, 111, 170, 0);
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 129, -10, 0);
            gUnknown_020322A0->state++;
            break;
        case 32:
            if (!gPaletteFade.active)
            {
                PlaySE(SE_TK_WARPOUT);
                gUnknown_020322A0->state++;
            }
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            break;
        case 33:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -90)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 1;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 1;
                gUnknown_020322A0->state++;
                CreateTask(c3_0805465C, 5);
            }
            break;
        case 34:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 35:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 36:
            BlendPalettes(0x8, 16, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 37:
            if (!IsMonSpriteNotFlipped(gUnknown_020322A0->tradeSpecies[0]))
            {
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].affineAnims = gSpriteAffineAnimTable_8338ECC;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].oam.affineMode = 3;
                CalcCenterToCornerVec(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0, 3, 3);
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            else
            {
                StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]], 0);
            }
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.x = 40;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 200;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos1.y = 192;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = -32;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = FALSE;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = FALSE;
            gUnknown_020322A0->state++;
            break;
        case 38:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y -= 3;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -160 && gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y >= -163)
            {
                PlaySE(SE_TK_WARPIN);
            }
            if (gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].pos2.y < -222)
            {
                gSprites[gUnknown_020322A0->unk_90].data[1] = 0;
                gSprites[gUnknown_020322A0->unk_91].data[1] = 0;
                gUnknown_020322A0->state++;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]].invisible = TRUE;
                gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].invisible = TRUE;
                CreateTask(sub_807F39C, 5);
            }
            break;
        case 39:
            gSprites[gUnknown_020322A0->unk_90].pos2.y -= 3;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 3;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y <= -222)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
                gUnknown_020322A0->state++;
                DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            }
            break;
        case 40:
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state++;
                sub_807B62C(1);
                gUnknown_020322A0->bg1vofs = 166;
                sub_807B62C(3);
                gUnknown_020322A0->bg2vofs = 412;
                gUnknown_020322A0->unk_90 = CreateSprite(&gUnknown_08338D88, 120, -20, 3);
                gSprites[gUnknown_020322A0->unk_90].callback = sub_807AA4C;
                gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338DC8, 120, -20, 0);
                StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_91], 1);
            }
            break;
        case 41:
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 42:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 43:
            gSprites[gUnknown_020322A0->unk_90].pos2.y += 4;
            gSprites[gUnknown_020322A0->unk_91].pos2.y += 4;
            if (gSprites[gUnknown_020322A0->unk_90].pos2.y + gSprites[gUnknown_020322A0->unk_90].pos1.y == 64)
            {
                gUnknown_020322A0->state = 144;
                gUnknown_020322A0->timer = 0;
            }
            break;
        case 144:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG1_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            gUnknown_020322A0->bg1vofs += 3;
            gUnknown_020322A0->bg2vofs += 3;
            if (++gUnknown_020322A0->timer == 10)
            {
                u8 taskId = CreateTask(c3_08054588, 5);
                gTasks[taskId].data[2] = 1;
            }
            if (gUnknown_020322A0->bg1vofs > 316)
            {
                gUnknown_020322A0->bg1vofs = 316;
                gUnknown_020322A0->state++;
            }
            break;
        case 145:
            DestroySprite(&gSprites[gUnknown_020322A0->unk_90]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
            gUnknown_020322A0->state++;
            gUnknown_020322A0->timer = 0;
            break;
        case 146:
            if (!FuncIsActiveTask(c3_08054588))
            {
                gUnknown_020322A0->state = 46;
                gUnknown_020322A0->timer = 0;
            }
            break;
        case 46:
            if (++gUnknown_020322A0->timer == 10)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 47:
            if (++gUnknown_020322A0->bg1vofs > 348)
            {
                gUnknown_020322A0->bg1vofs = 348;
                gUnknown_020322A0->state++;
            }
            break;
        case 48:
            gUnknown_020322A0->unk_91 = CreateSprite(&gSpriteTemplate_8338E74, 120, 80, 0);
            gUnknown_020322A0->state = 50;
            break;
        case 50:
            if (gSprites[gUnknown_020322A0->unk_91].animEnded)
            {
                DestroySprite(&gSprites[gUnknown_020322A0->unk_91]);
                sub_807B62C(6);
                gUnknown_020322A0->state++;
                PlaySE(SE_W028);
            }
            break;
        case 51:
            if (gUnknown_020322A0->unk_EA < 0x400)
            {
                gUnknown_020322A0->unk_EA += 0x34;
            }
            else
            {
                gUnknown_020322A0->unk_EA = 0x400;
                gUnknown_020322A0->state++;
            }
            gUnknown_020322A0->unk_E8 = 0x8000 / gUnknown_020322A0->unk_EA;
            break;
        case 52:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state = 60;
            break;
        case 60:
            if (!gPaletteFade.active)
            {
                sub_807B62C(5);
                sub_807B62C(7);
                gPaletteFade.bufferTransferDisabled = TRUE;
                gUnknown_020322A0->state++;
            }
            break;
        case 61:
            gPaletteFade.bufferTransferDisabled = FALSE;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 62:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            if (!gPaletteFade.active)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 63:
            gUnknown_020322A0->unk_D3 = CreateSprite(&gSpriteTemplate_8338D28, 120, -8, 0);
            gSprites[gUnknown_020322A0->unk_D3].data[3] = 74;
            gSprites[gUnknown_020322A0->unk_D3].callback = sub_807E6AC;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->unk_D3], 1);
            StartSpriteAffineAnim(&gSprites[gUnknown_020322A0->unk_D3], 2);
            BlendPalettes(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 16, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            gUnknown_020322A0->timer = 0;
            break;
        case 64:
            BeginNormalPaletteFade(1 << (16 + gSprites[gUnknown_020322A0->unk_D3].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
            gUnknown_020322A0->state++;
            break;
        case 65:
            if (gSprites[gUnknown_020322A0->unk_D3].callback == SpriteCallbackDummy)
            {
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[gUnknown_020322A0->tradeSpecies[1]], gMonSpritesGfxPtr->sprites[3], gUnknown_020322A0->tradeSpecies[1], gUnknown_020322A0->unk_68[1]);
                gUnknown_020322A0->state++;
            }
            break;
        case 66:
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.x = 120;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos1.y = gMonFrontPicCoords[gUnknown_020322A0->tradeSpecies[1]].y_offset + 60;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.x = 0;
            gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].pos2.y = 0;
            StartSpriteAnim(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]], 0);
            CreatePokeballSpriteToReleaseMon(gUnknown_020322A0->pokePicSpriteIdxs[1], gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]].oam.paletteNum, 120, 84, 2, 1, 20, 0xFFFFF, gUnknown_020322A0->tradeSpecies[1]);
            FreeSpriteOamMatrix(&gSprites[gUnknown_020322A0->unk_D3]);
            DestroySprite(&gSprites[gUnknown_020322A0->unk_D3]);
            gUnknown_020322A0->state++;
            break;
        case 67:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                          DISPCNT_OBJ_1D_MAP |
                                          DISPCNT_BG0_ON |
                                          DISPCNT_BG2_ON |
                                          DISPCNT_OBJ_ON);
            StringExpandPlaceholders(gStringVar4, gText_XSentOverY);
            sub_807F1A8(0, gStringVar4, 0);
            gUnknown_020322A0->state = 167;
            gUnknown_020322A0->timer = 0;
            break;
        // 167 and 267 are extra cases added in for animations
        case 167:
            if (++gUnknown_020322A0->timer > 60)
            {
                gUnknown_020322A0->state = 267;
                gUnknown_020322A0->timer = 0;
            }
            break;
        case 267:
            if (IsCryFinished())
            {
                gUnknown_020322A0->state = 68;
            }
            break;
        case 68:
            if (++gUnknown_020322A0->timer == 10)
            {
                PlayFanfare(MUS_FANFA5);
            }
            if (gUnknown_020322A0->timer == 250)
            {
                gUnknown_020322A0->state++;
                StringExpandPlaceholders(gStringVar4, gText_TakeGoodCareOfX);
                sub_807F1A8(0, gStringVar4, 0);
                gUnknown_020322A0->timer = 0;
            }
            break;
        case 69:
            if (++gUnknown_020322A0->timer == 60)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 70:
            sub_807F14C();
            gUnknown_020322A0->state++;
            break;
        case 71:
            if (gUnknown_020322A0->isLinkTrade)
            {
                return TRUE;
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                gUnknown_020322A0->state++;
            }
            break;
        case 72: // Only if in-game trade
            sub_807B4D0(gSpecialVar_0x8005, 0);
            gCB2_AfterEvolution = sub_807B60C;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gUnknown_02032298[0]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
            {
                TradeEvolutionScene(&gPlayerParty[gUnknown_02032298[0]], evoTarget, gUnknown_020322A0->pokePicSpriteIdxs[1], gUnknown_02032298[0]);
            }
            gUnknown_020322A0->state++;
            break;
        case 73:
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gUnknown_020322A0->state++;
            break;
        case 74:
            if (!gPaletteFade.active)
            {
                PlayNewMapMusic(gUnknown_020322A0->cachedMapMusic);
                if (gUnknown_020322A0)
                {
                    FreeAllWindowBuffers();
                    Free(GetBgTilemapBuffer(3));
                    Free(GetBgTilemapBuffer(1));
                    Free(GetBgTilemapBuffer(0));
                    FreeMonSpritesGfx();
                    FREE_AND_SET_NULL(gUnknown_020322A0);
                }
                SetMainCallback2(CB2_ReturnToField);
                sub_807E784();
            }
            break;
    }
    return FALSE;
}

static void c2_08053788(void)
{
    u16 evoTarget;
    switch (gMain.state)
    {
        case 0:
            gMain.state = 4;
            gSoftResetDisabled = TRUE;
            break;
        case 4:
            gCB2_AfterEvolution = sub_807EB50;
            evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gUnknown_02032298[0]], TRUE, ITEM_NONE);
            if (evoTarget != SPECIES_NONE)
                TradeEvolutionScene(&gPlayerParty[gUnknown_02032298[0]], evoTarget, gUnknown_020322A0->pokePicSpriteIdxs[1], gUnknown_02032298[0]);
            else if (sub_8077260())
                SetMainCallback2(sub_807F464);
            else
                SetMainCallback2(sub_807EB50);
            gUnknown_02032298[0] = 255;
            break;
    }
    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807E4DC(void)
{
    u8 blockReceivedStatus;
    sub_807ACDC();
    blockReceivedStatus = GetBlockReceivedStatus();
    if (blockReceivedStatus & 0x01)
    {
        if (gBlockRecvBuffer[0][0] == 0xDCBA)
        {
            SetMainCallback2(c2_08053788);
        }
        if (gBlockRecvBuffer[0][0] == 0xABCD)
        {
            gUnknown_020322A0->unk_72 = 1;
        }
        ResetBlockReceivedFlag(0);
    }
    if (blockReceivedStatus & 0x02)
    {
        if (gBlockRecvBuffer[1][0] == 0xABCD)
        {
            gUnknown_020322A0->unk_73 = 1;
        }
        ResetBlockReceivedFlag(1);
    }
}

static void sub_807E55C(struct Sprite *sprite)
{
    sprite->pos1.y += sprite->data[0] / 10;
    sprite->data[5] += sprite->data[1];
    sprite->pos1.x = sprite->data[5] / 10;
    if (sprite->pos1.y > 0x4c)
    {
        sprite->pos1.y = 0x4c;
        sprite->data[0] = -(sprite->data[0] * sprite->data[2]) / 100;
        sprite->data[3] ++;
    }
    if (sprite->pos1.x == 0x78)
        sprite->data[1] = 0;
    sprite->data[0] += sprite->data[4];
    if (sprite->data[3] == 4)
    {
        sprite->data[7] = 1;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void sub_807E5D8(struct Sprite *sprite)
{
    sprite->pos2.y += gTradeBallVerticalVelocityTable[sprite->data[0]];
    if (sprite->data[0] == 22)
        PlaySE(SE_KON);
    if (++ sprite->data[0] == 44)
    {
        PlaySE(SE_W025);
        sprite->callback = sub_807E64C;
        sprite->data[0] = 0;
        BeginNormalPaletteFade(1 << (16 + sprite->oam.paletteNum), -1, 0, 16, RGB_WHITEALPHA);
    }
}

static void sub_807E64C(struct Sprite *sprite)
{
    if (sprite->data[1] == 20)
        StartSpriteAffineAnim(sprite, 1);
    if (++ sprite->data[1] > 20)
    {
        sprite->pos2.y -= gTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++ sprite->data[0] == 23)
        {
            DestroySprite(sprite);
            gUnknown_020322A0->state = 14; // Resume the master trade animation
        }
    }
}

static void sub_807E6AC(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        if ((sprite->pos1.y += 4) > sprite->data[3])
        {
            sprite->data[2] ++;
            sprite->data[0] = 0x16;
            PlaySE(SE_KON);
        }
    }
    else
    {
        if (sprite->data[0] == 0x42)
            PlaySE(SE_KON2);
        if (sprite->data[0] == 0x5c)
            PlaySE(SE_KON3);
        if (sprite->data[0] == 0x6b)
            PlaySE(SE_KON4);
        sprite->pos2.y += gTradeBallVerticalVelocityTable[sprite->data[0]];
        if (++sprite->data[0] == 0x6c)
            sprite->callback = SpriteCallbackDummy;
    }
}

u16 GetInGameTradeSpeciesInfo(void)
{
    const struct InGameTrade *inGameTrade = &gIngameTrades[gSpecialVar_0x8004];
    StringCopy(gStringVar1, gSpeciesNames[inGameTrade->playerSpecies]);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
    return inGameTrade->playerSpecies;
}

static void sub_807E784(void)
{
    u8 nickname[32];
    const struct InGameTrade *inGameTrade = &gIngameTrades[gSpecialVar_0x8004];
    GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, nickname);
    StringCopy10(gStringVar1, nickname);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
}

static void _CreateInGameTradePokemon(u8 whichPlayerMon, u8 whichInGameTrade)
{
    const struct InGameTrade *inGameTrade = &gIngameTrades[whichInGameTrade];
    u8 level = GetMonData(&gPlayerParty[whichPlayerMon], MON_DATA_LEVEL);

    struct MailStruct mail;
    u8 metLocation = 0xFE;
    u8 isMail;
    struct Pokemon *pokemon = &gEnemyParty[0];

    CreateMon(pokemon, inGameTrade->species, level, 32, TRUE, inGameTrade->personality, TRUE, inGameTrade->otId);

    SetMonData(pokemon, MON_DATA_HP_IV, &inGameTrade->ivs[0]);
    SetMonData(pokemon, MON_DATA_ATK_IV, &inGameTrade->ivs[1]);
    SetMonData(pokemon, MON_DATA_DEF_IV, &inGameTrade->ivs[2]);
    SetMonData(pokemon, MON_DATA_SPEED_IV, &inGameTrade->ivs[3]);
    SetMonData(pokemon, MON_DATA_SPATK_IV, &inGameTrade->ivs[4]);
    SetMonData(pokemon, MON_DATA_SPDEF_IV, &inGameTrade->ivs[5]);
    SetMonData(pokemon, MON_DATA_NICKNAME, inGameTrade->name);
    SetMonData(pokemon, MON_DATA_OT_NAME, inGameTrade->otName);
    SetMonData(pokemon, MON_DATA_OT_GENDER, &inGameTrade->otGender);
    SetMonData(pokemon, MON_DATA_ABILITY_NUM, &inGameTrade->secondAbility);
    SetMonData(pokemon, MON_DATA_BEAUTY, &inGameTrade->stats[1]);
    SetMonData(pokemon, MON_DATA_CUTE, &inGameTrade->stats[2]);
    SetMonData(pokemon, MON_DATA_COOL, &inGameTrade->stats[0]);
    SetMonData(pokemon, MON_DATA_SMART, &inGameTrade->stats[3]);
    SetMonData(pokemon, MON_DATA_TOUGH, &inGameTrade->stats[4]);
    SetMonData(pokemon, MON_DATA_SHEEN, &inGameTrade->sheen);
    SetMonData(pokemon, MON_DATA_MET_LOCATION, &metLocation);

    isMail = FALSE;
    if (inGameTrade->heldItem != ITEM_NONE)
    {
        if (ItemIsMail(inGameTrade->heldItem))
        {
            sub_807E974(&mail, inGameTrade);
            gUnknown_020321C0[0] = mail;
            SetMonData(pokemon, MON_DATA_MAIL, &isMail);
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
        else
        {
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
    }
    CalculateMonStats(&gEnemyParty[0]);
}

static void sub_807E974(struct MailStruct *mail, const struct InGameTrade *trade) {
    s32 i;

    for (i = 0; i < 9; i++)
    {
        mail->words[i] = gIngameTradeMail[trade->mailNum][i];
    }

    StringCopy(mail->playerName, trade->otName);
    PadNameString(mail->playerName, CHAR_SPACE);

    mail->trainerId[0] = trade->otId >> 24;
    mail->trainerId[1] = trade->otId >> 16;
    mail->trainerId[2] = trade->otId >> 8;
    mail->trainerId[3] = trade->otId;
    mail->species = trade->species;
    mail->itemId = trade->heldItem;
}

u16 GetTradeSpecies(void)
{
    if (GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_IS_EGG))
        return SPECIES_NONE;
    return GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_SPECIES);
}

void CreateInGameTradePokemon(void)
{
    _CreateInGameTradePokemon(gSpecialVar_0x8005, gSpecialVar_0x8004);
}

static void sub_807EA2C(void)
{
    if (sub_807BBC8() == TRUE)
    {
        DestroySprite(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[0]]);
        FreeSpriteOamMatrix(&gSprites[gUnknown_020322A0->pokePicSpriteIdxs[1]]);
        sub_807B4D0(gUnknown_02032298[0], gUnknown_02032298[1] % 6);
        if (!sub_8077260())
        {
            gUnknown_020322A0->linkData[0] = 0xABCD;
            gUnknown_020322A0->unk_93 = 1;
        }
        SetMainCallback2(sub_807EACC);
    }
    sub_807B5B8();
    sub_807E4DC();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807EACC(void)
{
    u8 mpId = sub_807ACDC();
    if (sub_8077260())
    {
        SetMainCallback2(c2_08053788);
    }
    else
    {
        sub_807E4DC();
        if (mpId == 0 && gUnknown_020322A0->unk_72 == 1 && gUnknown_020322A0->unk_73 == 1)
        {
            gUnknown_020322A0->linkData[0] = 0xDCBA;
            Trade_SendData(gUnknown_020322A0);
            gUnknown_020322A0->unk_72 = 2;
            gUnknown_020322A0->unk_73 = 2;
        }
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_807EB50(void)
{
    switch (gMain.state)
    {
        case 0:
            gMain.state++;
            StringExpandPlaceholders(gStringVar4, gText_CommunicationStandby5);
            sub_807F1A8(0, gStringVar4, 0);
            break;
        case 1:
            sub_8077288(0);
            gMain.state = 100;
            gUnknown_020322A0->timer = 0;
            break;
        case 100:
            if (++gUnknown_020322A0->timer > 180)
            {
                gMain.state = 101;
                gUnknown_020322A0->timer = 0;
            }
            if (_IsLinkTaskFinished())
            {
                gMain.state = 2;
            }
            break;
        case 101:
            if (_IsLinkTaskFinished())
            {
                gMain.state = 2;
            }
            break;
        case 2:
            gMain.state = 50;
            StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
            sub_807F1A8(0, gStringVar4, 0);
            break;
        case 50:
            if (!InUnionRoom())
                IncrementGameStat(GAME_STAT_POKEMON_TRADES);
            if (gWirelessCommType)
            {
                sub_801B990(2, gLinkPlayers[GetMultiplayerId() ^ 1].trainerId);
            }
            SetContinueGameWarpStatusToDynamicWarp();
            sub_8153380();
            gMain.state++;
            gUnknown_020322A0->timer = 0;
            break;
        case 51:
            if (++gUnknown_020322A0->timer == 5)
            {
                gMain.state++;
            }
            break;
        case 52:
            if (sub_81533AC())
            {
                ClearContinueGameWarpStatus2();
                gMain.state = 4;
            }
            else
            {
                gUnknown_020322A0->timer = 0;
                gMain.state = 51;
            }
            break;
        case 4:
            sub_81533E0();
            gMain.state = 40;
            gUnknown_020322A0->timer = 0;
            break;
        case 40:
            if (++gUnknown_020322A0->timer > 50)
            {
                if (GetMultiplayerId() == 0)
                {
                    gUnknown_020322A0->timer = Random() % 30;
                }
                else
                {
                    gUnknown_020322A0->timer = 0;
                }
                gMain.state = 41;
            }
            break;
        case 41:
            if (gUnknown_020322A0->timer == 0)
            {
                sub_8077288(1);
                gMain.state = 42;
            }
            else
            {
                gUnknown_020322A0->timer--;
            }
            break;
        case 42:
            if (_IsLinkTaskFinished())
            {
                sub_8153408();
                gMain.state = 5;
            }
            break;
        case 5:
            if (++gUnknown_020322A0->timer > 60)
            {
                gMain.state++;
                sub_8077288(2);
            }
            break;
        case 6:
            if (_IsLinkTaskFinished())
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gMain.state ++;
            }
            break;
        case 7:
            if (!gPaletteFade.active)
            {
                FadeOutBGM(3);
                gMain.state++;
            }
            break;
        case 8:
            if (IsBGMStopped() == TRUE)
            {
                if (gWirelessCommType && gMain.savedCallback == sub_80773AC)
                {
                    sub_8077288(3);
                }
                else
                {
                    sub_800AC34();
                }
                gMain.state++;
            }
            break;
        case 9:
            if (gWirelessCommType && gMain.savedCallback == sub_80773AC)
            {
                if (_IsLinkTaskFinished())
                {
                    gSoftResetDisabled = FALSE;
                    SetMainCallback2(c2_080543C4);
                }
            }
            else if (!gReceivedRemoteLinkPlayers)
            {
                gSoftResetDisabled = FALSE;
                SetMainCallback2(c2_080543C4);
            }
            break;
    }
    if (!HasLinkErrorOccurred())
    {
        RunTasks();
    }
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void c2_080543C4(void)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        Free(GetBgTilemapBuffer(3));
        Free(GetBgTilemapBuffer(1));
        Free(GetBgTilemapBuffer(0));
        FreeMonSpritesGfx();
        FREE_AND_SET_NULL(gUnknown_020322A0);
        if (gWirelessCommType)
            DestroyWirelessStatusIndicatorSprite();
        SetMainCallback2(gMain.savedCallback);
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DoInGameTradeScene(void)
{
    ScriptContext2_Enable();
    CreateTask(sub_807F110, 10);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
}

static void sub_807F110(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sub_807B270);
        gFieldCallback = FieldCallback_ReturnToEventScript2;
        DestroyTask(taskId);
    }
}

static void sub_807F14C(void)
{
    u8 i;
    u8 numRibbons = 0;
    for (i = 0; i < 12; i ++)
    {
        numRibbons += GetMonData(&gEnemyParty[gUnknown_02032298[1] % 6], MON_DATA_CHAMPION_RIBBON + i);
    }
    if (numRibbons != 0)
        FlagSet(FLAG_SYS_RIBBON_GET);
}

void sub_807F19C(void)
{
    sub_807B170();
}

void sub_807F1A8(u8 windowId, const u8 *str, u8 speed)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(15));
    gUnknown_020322A0->unk_F6[0] = 15;
    gUnknown_020322A0->unk_F6[1] = 1;
    gUnknown_020322A0->unk_F6[2] = 6;
    AddTextPrinterParameterized4(windowId, 1, 0, 2, 0, 0, gUnknown_020322A0->unk_F6, speed, str);
    CopyWindowToVram(windowId, 3);
}

static void c3_08054588(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 unk = gUnknown_08339090[data[0]][0] * 16;

    if (!data[2])
    {
        if (unk == 0x100)
            LoadPalette(gUnknown_08337EA0, 0x30, 32);
        else
            LoadPalette(&gUnknown_08337AA0[unk], 0x30, 32);
    }
    else
    {
        if (unk == 0x100)
            LoadPalette(gUnknown_08337EA0, 0x30, 32);
        else
            LoadPalette(&gUnknown_08337CA0[unk], 0x30, 32);
    }

    if (gUnknown_08339090[data[0]][0] == 0 && data[1] == 0)
        PlaySE(SE_W215);

    if (data[1] == gUnknown_08339090[data[0]][1])
    {
        data[0]++;
        data[1] = 0;
        if (gUnknown_08339090[data[0]][1] == 0xFF)
        {
            DestroyTask(taskId);
        }
    }
    else
    {
        data[1]++;
    }
}

static void c3_0805465C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        gUnknown_020322A0->unk_FB = gUnknown_020322A0->unk_FD = 120;
        gUnknown_020322A0->unk_FC = 0;
        gUnknown_020322A0->unk_FE = 160;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(gUnknown_020322A0->unk_FB, gUnknown_020322A0->unk_FD));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(gUnknown_020322A0->unk_FC, gUnknown_020322A0->unk_FE));

    data[0]++;
    gUnknown_020322A0->unk_FB -= 5;
    gUnknown_020322A0->unk_FD += 5;

    if (gUnknown_020322A0->unk_FB < 80)
    {
        DestroyTask(taskId);
    }
}

static void sub_807F39C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        gUnknown_020322A0->unk_FB = 80;
        gUnknown_020322A0->unk_FD = 160;
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 |
                                    WININ_WIN0_BG1 |
                                    WININ_WIN0_OBJ);
    }

    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE2(gUnknown_020322A0->unk_FB, gUnknown_020322A0->unk_FD));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE2(gUnknown_020322A0->unk_FC, gUnknown_020322A0->unk_FE));

    if (gUnknown_020322A0->unk_FB != 120)
    {
        data[0]++;
        gUnknown_020322A0->unk_FB += 5;
        gUnknown_020322A0->unk_FD -= 5;

        if (gUnknown_020322A0->unk_FB >= 116)
            BlendPalettes(0x8, 0, RGB_WHITEALPHA);
    }
    else
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        DestroyTask(taskId);
    }
}

static void sub_807F464(void)
{
    switch (gMain.state)
    {
        case 0:
            gMain.state = 1;
            StringExpandPlaceholders(gStringVar4, gText_CommunicationStandby5);
            sub_807F1A8(0, gStringVar4, 0);
            break;
        case 1:
            sub_8077288(0);
            gMain.state = 2;
            gUnknown_020322A0->timer = 0;
            break;
        case 2:
            if (_IsLinkTaskFinished())
            {
                gMain.state = 3;
                StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
                sub_807F1A8(0, gStringVar4, 0);
                IncrementGameStat(GAME_STAT_POKEMON_TRADES);
                sub_8153380();
                gUnknown_020322A0->timer = 0;
            }
            break;
        case 3:
            if (++gUnknown_020322A0->timer == 5)
            {
                gMain.state = 4;
            }
            break;
        case 4:
            if (sub_81533AC())
            {
                gMain.state = 5;
            }
            else
            {
                gUnknown_020322A0->timer = 0;
                gMain.state = 3;
            }
            break;
        case 5:
            sub_81533E0();
            gMain.state = 6;
            gUnknown_020322A0->timer = 0;
            break;
        case 6:
            if (++gUnknown_020322A0->timer > 10)
            {
                if (GetMultiplayerId() == 0)
                {
                    gUnknown_020322A0->timer = Random() % 30;
                }
                else
                {
                    gUnknown_020322A0->timer = 0;
                }
                gMain.state = 7;
            }
            break;
        case 7:
            if (gUnknown_020322A0->timer == 0)
            {
                sub_8077288(1);
                gMain.state = 8;
            }
            else
            {
                gUnknown_020322A0->timer--;
            }
            break;
        case 8:
            if (_IsLinkTaskFinished())
            {
                sub_8153408();
                gMain.state = 9;
            }
            break;
        case 9:
            if (++gUnknown_020322A0->timer > 60)
            {
                gMain.state++;
                sub_8077288(2);
            }
            break;
        case 10:
            if (_IsLinkTaskFinished())
            {
                FadeOutBGM(3);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gMain.state = 11;
            }
            break;
        case 11:
            if (!gPaletteFade.active && IsBGMStopped() == TRUE)
            {
                sub_8077288(3);
                gMain.state = 12;
            }
            break;
        case 12:
            if (_IsLinkTaskFinished())
            {
                gSoftResetDisabled = FALSE;
                SetMainCallback2(c2_080543C4);
            }
            break;
    }

    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}
