#include "global.h"
#include "bg.h"
#include "window.h"
#include "task.h"
#include "sprite.h"
#include "sound.h"
#include "songs.h"
#include "m4a.h"
#include "bg.h"
#include "palette.h"
#include "decompress.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "text.h"
#include "event_data.h"
#include "main.h"
#include "link.h"
#include "new_menu_helpers.h"
#include "item_menu_icons.h"
#include "berry.h"
#include "items.h"
#include "string_util.h"
#include "international_string_util.h"
#include "rng.h"

// Static type declarations
#define BLENDER_SCORE_BEST      0
#define BLENDER_SCORE_GOOD      1
#define BLENDER_SCORE_MISS      2

#define BLENDER_MAX_PLAYERS     4
#define BLENDER_SCORES_NO       3

struct BlenderBerry
{
    u16 itemId;
    u8 name[BERRY_NAME_COUNT];
    u8 flavours[FLAVOUR_COUNT];
    u8 smoothness;
};

struct BerryBlenderData
{
    u8 mainState;
    u8 loadGfxState;
    u8 field_02;
    u8 field_03;
    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 field_08;
    u8 field_09;
    u8 field_0A;
    u8 field_0B;
    u8 field_0C;
    u8 field_0D;
    u8 field_0E;
    u8 field_0F;

    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 field_19;
    u8 field_1A;
    u8 field_1B;
    u8 field_1C;
    u8 field_1D;
    u8 field_1E;
    u8 field_1F;

    u8 field_20;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    u8 field_24;
    u8 field_25;
    u8 field_26;
    u8 field_27;
    u8 field_28;
    u8 field_29;
    u8 field_2A;
    u8 field_2B;
    u8 field_2C;
    u8 field_2D;
    u8 field_2E;
    u8 field_2F;

    u8 field_30;
    u8 field_31;
    u8 field_32;
    u8 field_33;
    u8 field_34;
    u8 field_35;
    u8 field_36;
    u8 field_37;
    u8 field_38;
    u8 field_39;
    u8 field_3A;
    u8 field_3B;
    u8 field_3C;
    u8 field_3D;
    u8 field_3E;
    u8 field_3F;

    u8 field_40;
    u8 field_41;
    u8 field_42;
    u8 field_43;
    u16 field_44;
    u8 field_46;
    u8 field_47;
    u16 field_48;
    u16 arrowPos;
    s16 field_4C;
    s16 field_4E;

    u8 syncArrowSpriteIds[BLENDER_MAX_PLAYERS];
    u8 syncArrowSprite2Ids[BLENDER_MAX_PLAYERS];
    u8 field_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u8 field_5C;
    u8 field_5D;
    u8 field_5E;
    u8 field_5F;

    u8 field_60;
    u8 field_61;
    u8 field_62;
    u8 field_63;
    u16 field_64[BLENDER_MAX_PLAYERS];
    u8 field_6C;
    u8 field_6D;
    u8 field_6E;
    u8 field_6F;

    u16 field_70;
    u8 field_72;
    u8 field_73;
    u16 chosenItemId[BLENDER_MAX_PLAYERS];
    u8 playersNo;
    u8 field_7D;
    u8 field_7E;
    u8 field_7F;

    u8 field_80;
    u8 field_81;
    u8 field_82;
    u8 field_83;
    u8 field_84;
    u8 field_85;
    u8 field_86;
    u8 field_87;
    u8 field_88;
    u8 field_89;
    u8 field_8A;
    u8 field_8B;
    u8 field_8C;
    u8 field_8D;
    u16 field_8E[BLENDER_MAX_PLAYERS];
    u16 field_96[BLENDER_MAX_PLAYERS];
    u8 field_9E;
    u8 field_9F;

    u8 field_A0;
    u8 field_A1;
    u8 field_A2;
    u8 field_A3;
    u8 field_A4;
    u8 field_A5;
    u8 field_A6;
    u8 field_A7;
    u8 field_A8;
    u8 field_A9;
    u8 field_AA;
    u8 field_AB;
    u8 field_AC;
    u8 field_AD;
    u8 field_AE;
    u8 field_AF;

    u8 field_B0;
    u8 field_B1;
    u8 field_B2;
    u8 field_B3;
    u8 field_B4;
    u8 field_B5;
    u8 field_B6;
    u8 field_B7;
    u8 field_B8;
    u8 field_B9;
    u8 field_BA;
    u8 field_BB;
    u8 field_BC;
    u8 field_BD;
    u8 field_BE;
    u8 field_BF;

    u8 field_C0;
    u8 field_C1;
    u8 field_C2;
    u8 field_C3;
    u8 field_C4;
    u8 field_C5;
    u8 field_C6;
    u8 field_C7;
    u8 field_C8;
    u8 field_C9;
    u8 field_CA;
    u8 field_CB;
    u8 field_CC;
    u8 field_CD;
    u8 field_CE;
    u8 field_CF;

    u8 field_D0;
    u8 field_D1;
    u8 field_D2;
    u8 field_D3;
    u8 field_D4;
    u8 field_D5;
    u8 field_D6;
    u8 field_D7;
    u8 field_D8;
    u8 field_D9;
    u8 field_DA;
    u8 field_DB;
    u8 field_DC;
    u8 field_DD;
    u8 field_DE;
    u8 field_DF;

    u8 field_E0;
    u8 field_E1;
    u8 field_E2;
    u8 field_E3;
    u8 field_E4;
    u8 field_E5;
    u8 field_E6;
    u8 field_E7;
    u8 field_E8;
    u8 field_E9;
    u8 field_EA;
    u8 field_EB;
    u8 field_EC;
    u8 field_ED;
    u8 field_EE;
    u8 field_EF;

    u8 field_F0;
    u8 field_F1;
    u8 field_F2;
    u8 field_F3;
    u8 field_F4;
    u8 field_F5;
    u8 field_F6;
    u8 field_F7;
    u8 field_F8;
    u8 field_F9;
    u8 field_FA;
    u8 field_FB;
    u8 field_FC;
    u8 field_FD;
    u8 field_FE;
    u8 field_FF;

    u8 field_100;
    u8 field_101;
    u8 field_102;
    u8 field_103;
    u32 gameFrameTime;
    s32 framesToWait;
    u32 field_10C;

    u8 field_110;
    u8 field_111;
    u8 field_112;
    u8 field_113;
    u8 field_114;
    u8 field_115;
    u16 field_116;
    u16 field_118;
    u16 field_11A;
    s16 field_11C;
    s16 field_11E;

    u8 field_120[3];
    u8 field_123;
    u16 scores[BLENDER_MAX_PLAYERS][BLENDER_SCORES_NO];
    u8 field_13C;
    u8 field_13D;
    u8 field_13E;
    u8 field_13F;

    struct BgAffineSrcData bgAffineSrc;

    u16 field_154;
    u8 field_156;
    u8 field_157;
    struct BlenderBerry blendedBerries[BLENDER_MAX_PLAYERS];
    u8 field_198;
    u8 field_199;
    u8 field_19A;
    u8 field_19B;
    u8 field_19C;
    u8 field_19D;
    u8 field_19E;
    u8 field_19F;

    u8 field_1A0;
    u8 field_1A1;
    u8 field_1A2;
    u8 field_1A3;
    u8 field_1A4;
    u8 field_1A5;
    u8 field_1A6;
    u8 field_1A7;
    u8 field_1A8;
    u8 field_1A9;
    u8 field_1AA;
    u8 field_1AB;
    u8 field_1AC;
    u8 field_1AD;
    u8 field_1AE;
    u8 field_1AF;

    u8 field_1B0;
    u8 field_1B1;
    u8 field_1B2;
    u8 field_1B3;
    u8 field_1B4;
    u8 field_1B5;
    u8 field_1B6;
    u8 field_1B7;
    u8 tilemapBuffers[2][0x800];
    s16 textState;
    void *tilesBuffer;
    u8 field_11C0[0x20];
};

extern struct MusicPlayerInfo gMPlay_SE2;
extern struct MusicPlayerInfo gMPlay_BGM;
extern u16 gSpecialVar_ItemId;
extern u8 gInGameOpponentsNo;

// graphics
extern const u8 gBerryBlenderArrowTiles[];
extern const u8 gBerryBlenderStartTiles[];
extern const u8 gBerryBlenderMarubatsuTiles[];
extern const u8 gBerryBlenderParticlesTiles[];
extern const u8 gBerryBlenderCountdownNumbersTiles[];
extern const u16 gBerryBlenderMiscPalette[];
extern const u16 gBerryBlenderArrowPalette[];

// text
extern const u8 gText_BerryBlenderStart[];

extern void sub_81978B0(u16);
extern void sub_800A418(void);
extern u8 sub_800A9D8(void);
extern bool8 sub_800A4D8(u8);
extern void sub_8197DF8(u8 windowId, bool8 copyToVram);
extern void sub_809882C(u8, u16, u8);
extern void copy_textbox_border_tile_patterns_to_vram(u8, u16, u8);
extern void sub_81AABF0(void (*callback)(void));
extern void sub_800B4C0(void);

// this file's functions
void BerryBlender_SetGpuRegs(void);
void sub_8080EA4(u8 taskId);
void sub_8080FD0(u8 taskId);
void sub_80810F8(u8 taskId);
void sub_8081224(u8 taskId);
void sub_80833F8(struct Sprite *sprite);
void sub_8082F68(struct Sprite *sprite);
void sub_8083010(struct Sprite *sprite);
void sub_80830C0(struct Sprite *sprite);
void sub_8082F9C(struct Sprite *sprite);
void Blender_SetPlayerNamesLocal(u8 opponentsNum);
void sub_807FAC8(void);
void sub_8082D28(void);
bool32 Blender_PrintText(s16 *textState, const u8 *string, u8 textSpeed);
void sub_807FFA4(void);
void sub_8080018(void);
void sub_80808D4(void);
void Blender_DummiedOutFunc(s16 a0, s16 a1);
void sub_8081898(void);
void sub_8082CB4(struct BgAffineSrcData *bgAffineSrc);
bool8 sub_8083380(void);
void sub_808074C(void);
void Blender_PrintPlayerNames(void);
void sub_8080588(void);
void Blender_SetBankBerryData(u8 bank, u16 itemId);
void Blender_AddTextPrinter(u8 windowId, const u8 *string, u8 width, s8 x, s8 y, s32 state);
void sub_8080DF8(void);
void sub_8082E84(void);
void sub_80832BC(s16* a0, u16 a1);

extern struct BerryBlenderData *sBerryBlenderData;

// Static RAM declarations
IWRAM_DATA void *berry_blender_c_unused_03000de4;
IWRAM_DATA s16 gUnknown_03000DE8[8];
IWRAM_DATA s16 gUnknown_03000DF8[6];
IWRAM_DATA s16 gUnknown_03000E04;
IWRAM_DATA s16 gUnknown_03000E06;

// TODO: make those static once the file is decompiled
const u16 sBlenderCenterPal[] = INCBIN_U16("graphics/berry_blender/center.gbapal");
const u8 sBlenderCenterMap[] = INCBIN_U8("graphics/berry_blender/center_map.bin");
const u16 sBlenderOuterPal[] = INCBIN_U16("graphics/berry_blender/outer.gbapal");

// unreferenced pals?
static const u16 sUnknownPal_0[] = INCBIN_U16("graphics/unknown/unknown_339514.gbapal");
static const u16 sUnknownArray_1[224] = {0};

// unused text?
static const u8 sUnusedText_YesNo[] = _("YES\nNO");
static const u8 sUnusedText_2[] = _("▶");
static const u8 sUnusedText_Space[] = _(" ");
static const u8 sUnusedText_Terminating[] = _("Terminating.");
static const u8 sUnusedText_LinkPartnerNotFound[] = _("Link partner(s) not found.\nPlease try again.\p");

const u8 gText_BerryBlenderStart[] = _("Starting up the BERRY BLENDER.\pPlease select a BERRY from your BAG\nto put in the BERRY BLENDER.\p");
const u8 gText_NewParagraph[] = _("\p");
const u8 gText_WasMade[] = _(" was made!");
static const u8 sText_Mister[] = _("MISTER");
static const u8 sText_Laddie[] = _("LADDIE");
static const u8 sText_Lassie[] = _("LASSIE");
static const u8 sText_Master[] = _("MASTER");
static const u8 sText_Dude[] = _("DUDE");
static const u8 sText_Miss[] = _("MISS");

const u8* const sBlenderOpponentsNames[] =
{
    sText_Mister,
    sText_Laddie,
    sText_Lassie,
    sText_Master,
    sText_Dude,
    sText_Miss
};

enum
{
    BLENDER_MISTER,
    BLENDER_LADDIE,
    BLENDER_LASSIE,
    BLENDER_MASTER,
    BLENDER_DUDE,
    BLENDER_MISS
};

static const u8 sText_PressAToStart[] = _("Press the A Button to start.");
static const u8 sText_PleaseWaitAWhile[] = _("Please wait a while.");
const u8 sText_CommunicationStandby[] = _("Communication standby…");
const u8 sText_WouldLikeToBlendAnotherBerry[] = _("Would you like to blend another BERRY?");
const u8 sText_RunOutOfBerriesForBlending[] = _("You’ve run out of BERRIES for\nblending in the BERRY BLENDER.\p");
const u8 sText_YourPokeblockCaseIsFull[] = _("Your {POKEBLOCK} CASE is full.\p");
const u8 sText_HasNoBerriesToPut[] = _(" has no BERRIES to put in\nthe BERRY BLENDER.");
const u8 sText_ApostropheSPokeblockCaseIsFull[] = _("’s {POKEBLOCK} CASE is full.\p");
const u8 sText_BlendingResults[] = _("RESULTS OF BLENDING");
static const u8 sText_BerryUsed[] = _("BERRY USED");
const u8 sText_SpaceBerry[] = _(" BERRY");
const u8 sText_Time[] = _("Time:");
const u8 sText_Min[] = _(" min. ");
const u8 sText_Sec[] = _(" sec.");
const u8 sText_MaximumSpeed[] = _("MAXIMUM SPEED");
const u8 sText_RPM[] = _(" RPM");
const u8 sText_Dot[] = _(".");
const u8 sText_NewLine[] = _("\n");
static const u8 sText_Space[] = _(" ");
const u8 sText_Ranking[] = _("RANKING");
const u8 sText_TheLevelIs[] = _("The level is ");
const u8 sText_TheFeelIs[] = _(", and the feel is ");
const u8 sText_Dot2[] = _(".");

const struct BgTemplate sBerryBlenderBgTemplates[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 8,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 0,
        .baseTile = 0,
    }
};

static const struct WindowTemplate sBerryBlender_WindowTemplates[] =
{
    {0, 1, 6, 7, 2, 0xE, 0x28},
    {0, 0x16, 6, 7, 2, 0xE, 0x36},
    {0, 1, 0xC, 7, 2, 0xE, 0x44},
    {0, 0x16, 0xC, 7, 2, 0xE, 0x52},
    {0, 2, 0xF, 0x1B, 4, 0xE, 0x60},
    {0, 5, 3, 0x15, 0xE, 0xE, 0x60},
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_083399B8 =
{
    0, 0x15, 9, 5, 4, 0xE, 0xCC
};

const s8 gUnknown_083399C0[][2] =
{
    {-1, -1}, {1, -1}, {-1, 1}, {1, 1}
};

const u8 sBlenderSyncArrowsPos[BLENDER_MAX_PLAYERS][2] =
{
    {72, 32}, {168, 32}, {72, 128}, {168, 128}
};

const u8 gUnknown_083399D0[3][4] =
{
    {-1, 0, 1, -1}, {-1, 0, 1, 2}, {0, 1, 2, 3}
};

const u16 gUnknown_083399DC[] = {0, 0xC000, 0x4000, 0x8000};
const u8 gUnknown_083399E4[] = {1, 1, 0};
const u8 gUnknown_083399E7[] = {32, 224, 96, 160, 0};

const TaskFunc gUnknown_083399EC[] =
{
    sub_8080EA4, sub_8080FD0, sub_80810F8
};

static const struct OamData sOamData_8216314 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_821631C[] =
{
    ANIMCMD_FRAME(16, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216324[] =
{
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821632C[] =
{
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216334[] =
{
    ANIMCMD_FRAME(16, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821633C[] =
{
    ANIMCMD_FRAME(48, 2, 1, 1),
    ANIMCMD_FRAME(32, 5, 1, 1),
    ANIMCMD_FRAME(48, 3, 1, 1),
    ANIMCMD_FRAME(16, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216350[] =
{
    ANIMCMD_FRAME(48, 2, .vFlip = TRUE),
    ANIMCMD_FRAME(32, 5, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .vFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216364[] =
{
    ANIMCMD_FRAME(48, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216378[] =
{
    ANIMCMD_FRAME(48, 2, 0, 0),
    ANIMCMD_FRAME(32, 5, 0, 0),
    ANIMCMD_FRAME(48, 3, 0, 0),
    ANIMCMD_FRAME(16, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821638C[] =
{
    ANIMCMD_FRAME(0, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216394[] =
{
    ANIMCMD_FRAME(0, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821639C[] =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82163A4[] =
{
    ANIMCMD_FRAME(0, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_82163AC[] =
{
    sSpriteAnim_821631C,
    sSpriteAnim_8216324,
    sSpriteAnim_821632C,
    sSpriteAnim_8216334,
    sSpriteAnim_821633C,
    sSpriteAnim_8216350,
    sSpriteAnim_8216364,
    sSpriteAnim_8216378,
    sSpriteAnim_821638C,
    sSpriteAnim_8216394,
    sSpriteAnim_821639C,
    sSpriteAnim_82163A4
};

const struct SpriteSheet sSpriteSheet_BlenderArrow =
{
    gBerryBlenderArrowTiles, 0x800, 46545
};

const struct SpritePalette sSpritePal_BlenderMisc =
{
    gBerryBlenderMiscPalette, 46546
};

const struct SpritePalette sSpritePal_BlenderArrow =
{
    gBerryBlenderArrowPalette, 12312
};

const struct SpriteTemplate sBlenderSyncArrow_SpriteTemplate =
{
    .tileTag = 46545,
    .paletteTag = 12312,
    .oam = &sOamData_8216314,
    .anims = sSpriteAnimTable_82163AC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80833F8
};

static const struct OamData sOamData_821640C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_8216414[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821641C[] =
{
    ANIMCMD_FRAME(4, 20, 1, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216424[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821643C[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8216444[] =
{
    sSpriteAnim_8216414,
    sSpriteAnim_821641C,
    sSpriteAnim_8216424,
    sSpriteAnim_821643C,
};

const struct SpriteSheet gUnknown_08339B38 =
{
    gBerryBlenderMarubatsuTiles, 0x200, 48888
};

const struct SpriteTemplate gUnknown_08339B40 =
{
    .tileTag = 48888,
    .paletteTag = 46546,
    .oam = &sOamData_821640C,
    .anims = sSpriteAnimTable_8216444,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8082F68
};

static const struct OamData sOamData_8216474 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_821647C[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216494[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82164AC[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(3, 3),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82164D0[] =
{
    ANIMCMD_FRAME(5, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82164D8[] =
{
    ANIMCMD_FRAME(6, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_82164E0[] =
{
    sSpriteAnim_821647C,
    sSpriteAnim_8216494,
    sSpriteAnim_82164AC,
    sSpriteAnim_82164D0,
    sSpriteAnim_82164D8,
};

const struct SpriteSheet gUnknown_08339BD8 =
{
    gBerryBlenderParticlesTiles, 0xE0, 23456
};

const struct SpriteTemplate gUnknown_08339BE0 =
{
    .tileTag = 23456,
    .paletteTag = 46546,
    .oam = &sOamData_8216474,
    .anims = sSpriteAnimTable_82164E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_8216514 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_821651C[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216524[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821652C[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8216534[] =
{
    sSpriteAnim_821651C,
    sSpriteAnim_8216524,
    sSpriteAnim_821652C,
};

const struct SpriteSheet gUnknown_08339C24 =
{
    gBerryBlenderCountdownNumbersTiles, 0x600, 12345
};

const struct SpriteTemplate gUnknown_08339C2C =
{
    .tileTag = 12345,
    .paletteTag = 46546,
    .oam = &sOamData_8216514,
    .anims = sSpriteAnimTable_8216534,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8083010
};

static const struct OamData sOamData_8216560 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_8216568[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8216570[] =
{
    sSpriteAnim_8216568,
};

const struct SpriteSheet gUnknown_08339C58 =
{
    gBerryBlenderStartTiles, 0x400, 12346
};

const struct SpriteTemplate gUnknown_08339C60 =
{
    .tileTag = 12346,
    .paletteTag = 46546,
    .oam = &sOamData_8216560,
    .anims = sSpriteAnimTable_8216570,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80830C0
};

const s16 gUnknown_08339C78[][5] =
{
    {-10,  20,  10,   2,   1},
    {250,  20,  10,  -2,   1},
    {-10, 140,  10,   2,  -1},
    {250, 140,  10,  -2,  -1},
};

static const u8 sOpponentBerrySets[][3] =
{
    {4, 3, 2}, {0, 4, 3}, {1, 0, 4}, {2, 1, 0}, {3, 2, 1}, {0, 2, 3}, {1, 3, 4}, {2, 4, 0}, {3, 0, 1}, {4, 1, 2},
};

static const u8 sSpecialOpponentBerrySets[] = {30, 31, 32, 33, 34};

const u8 gUnknown_08339CC3[] = {1, 1, 2, 3, 4};

const u8 gUnknown_08339CC8[] = {0x1C, 0x16, 0x13, 0x1A, 0x19, 0x0E, 0x0D, 0x0B, 0x07, 0x15};

static const u8 gUnknown_08339CD2[] =
{
    0xfe, 0x02, 0x02, 0xce, 0xd0, 0x37, 0x44, 0x07, 0x1f, 0x0c, 0x10,
    0x00, 0xff, 0xfe, 0x91, 0x72, 0xce, 0xd0, 0x37, 0x44, 0x07, 0x1f,
    0x0c, 0x10, 0x00, 0xff, 0x06, 0x27, 0x02, 0xff, 0x00, 0x0c, 0x48,
    0x02, 0xff, 0x00, 0x01, 0x1f, 0x02, 0xff, 0x00, 0x16, 0x37, 0x02,
    0xff, 0x00, 0x0d, 0x50, 0x4b, 0x02, 0xff, 0x06, 0x06, 0x06, 0x06,
    0x05, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02
};

const struct WindowTemplate gUnknown_08339D14[] = {0, 6, 4, 0x12, 0xB, 0xF, 8};

// code

void Blender_ControlHitPitch(void)
{
    m4aMPlayPitchControl(&gMPlay_SE2, 0xFFFF, 2 * (sBerryBlenderData->field_4C - 128));
}

void VBlankCB0_BerryBlender(void)
{
    BerryBlender_SetGpuRegs();
    SetBgAffine(2, sBerryBlenderData->bgAffineSrc.texX, sBerryBlenderData->bgAffineSrc.texY,
                sBerryBlenderData->bgAffineSrc.scrX, sBerryBlenderData->bgAffineSrc.scrY,
                sBerryBlenderData->bgAffineSrc.sx, sBerryBlenderData->bgAffineSrc.sy,
                sBerryBlenderData->bgAffineSrc.alpha);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

extern const u8 sBlenderCenterGfx[];
extern const u8 gUnknown_08D91DB8[];
extern const u8 gUnknown_08D927EC[];

bool8 LoadBerryBlenderGfx(void)
{
    switch (sBerryBlenderData->loadGfxState)
    {
    case 0:
        sBerryBlenderData->tilesBuffer = AllocZeroed(sub_8034974(sBlenderCenterGfx) + 100);
        LZDecompressWram(sBlenderCenterGfx, sBerryBlenderData->tilesBuffer);
        sBerryBlenderData->loadGfxState++;
        break;
    case 1:
        CopyToBgTilemapBuffer(2, sBlenderCenterMap, 0x400, 0);
        CopyBgTilemapBufferToVram(2);
        LoadPalette(sBlenderCenterPal, 0, 0x100);
        sBerryBlenderData->loadGfxState++;
        break;
    case 2:
        LoadBgTiles(2, sBerryBlenderData->tilesBuffer, sub_8034974(sBlenderCenterGfx), 0);
        sBerryBlenderData->loadGfxState++;
        break;
    case 3:
        LZDecompressWram(gUnknown_08D91DB8, sBerryBlenderData->tilesBuffer);
        sBerryBlenderData->loadGfxState++;
        break;
    case 4:
        LoadBgTiles(1, sBerryBlenderData->tilesBuffer, sub_8034974(gUnknown_08D91DB8), 0);
        sBerryBlenderData->loadGfxState++;
        break;
    case 5:
        LZDecompressWram(gUnknown_08D927EC, sBerryBlenderData->tilesBuffer);
        sBerryBlenderData->loadGfxState++;
        break;
    case 6:
        CopyToBgTilemapBuffer(1, sBerryBlenderData->tilesBuffer, sub_8034974(gUnknown_08D927EC), 0);
        CopyBgTilemapBufferToVram(1);
        sBerryBlenderData->loadGfxState++;
        break;
    case 7:
        LoadPalette(sBlenderOuterPal, 0x80, 0x20);
        sBerryBlenderData->loadGfxState++;
        break;
    case 8:
        LoadSpriteSheet(&sSpriteSheet_BlenderArrow);
        LoadSpriteSheet(&gUnknown_08339BD8);
        LoadSpriteSheet(&gUnknown_08339B38);
        sBerryBlenderData->loadGfxState++;
        break;
    case 9:
        LoadSpriteSheet(&gUnknown_08339C24);
        LoadSpriteSheet(&gUnknown_08339C58);
        LoadSpritePalette(&sSpritePal_BlenderArrow);
        LoadSpritePalette(&sSpritePal_BlenderMisc);
        Free(sBerryBlenderData->tilesBuffer);
        sBerryBlenderData->loadGfxState = 0;
        return TRUE;
    }

    return FALSE;
}

void sub_807F9D0(void)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
    CopyBgTilemapBufferToVram(0);
    ShowBg(0);
    ShowBg(1);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
}

void InitBerryBlenderWindows(void)
{
    if (InitWindows(sBerryBlender_WindowTemplates))
    {
        s32 i;

        DeactivateAllTextPrinters();
        for (i = 0; i < 5; i++)
            FillWindowPixelBuffer(i, 0);

        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
        sub_81978B0(0xE0);
    }
}

void DoBerryBlending(void)
{
    if (sBerryBlenderData == NULL)
        sBerryBlenderData = AllocZeroed(sizeof(*sBerryBlenderData));

    sBerryBlenderData->field_63 = 0;
    sBerryBlenderData->mainState = 0;
    sBerryBlenderData->field_63 = 0;

    Blender_SetPlayerNamesLocal(gSpecialVar_0x8004);
    SetMainCallback2(sub_807FAC8);
}

void sub_807FAC8(void)
{
    s32 i;

    switch (sBerryBlenderData->mainState)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(NULL);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sBerryBlenderBgTemplates, ARRAY_COUNT(sBerryBlenderBgTemplates));
        SetBgTilemapBuffer(1, sBerryBlenderData->tilemapBuffers[0]);
        SetBgTilemapBuffer(2, sBerryBlenderData->tilemapBuffers[1]);
        sub_809882C(0, 1, 0xD0);
        copy_textbox_border_tile_patterns_to_vram(0, 0x14, 0xF0);
        InitBerryBlenderWindows();

        sBerryBlenderData->mainState++;
        sBerryBlenderData->field_118 = 0;
        sBerryBlenderData->field_116 = 0;
        sBerryBlenderData->field_11A = 0x50;
        sBerryBlenderData->field_11C = 0;
        sBerryBlenderData->field_11E = 0;
        sBerryBlenderData->loadGfxState = 0;

        sub_8082D28();
        break;
    case 1:
        if (LoadBerryBlenderGfx())
        {
            for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
            {
                sBerryBlenderData->syncArrowSpriteIds[i] = CreateSprite(&sBlenderSyncArrow_SpriteTemplate, sBlenderSyncArrowsPos[i][0], sBlenderSyncArrowsPos[i][1], 1);
                StartSpriteAnim(&gSprites[sBerryBlenderData->syncArrowSpriteIds[i]], i + 8);
            }
            if (gReceivedRemoteLinkPlayers != 0 && gLinkVSyncDisabled)
            {
                sub_800E0E8();
                sub_800DFB4(0, 0);
            }
            SetVBlankCallback(VBlankCB0_BerryBlender);
            sBerryBlenderData->mainState++;
        }
        break;
    case 2:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        sub_8082D28();
        sBerryBlenderData->mainState++;
        break;
    case 3:
        sub_807F9D0();
        if (!gPaletteFade.active)
            sBerryBlenderData->mainState++;
        break;
    case 4:
        if (Blender_PrintText(&sBerryBlenderData->textState, gText_BerryBlenderStart, GetPlayerTextSpeed()))
            sBerryBlenderData->mainState++;
        break;
    case 5:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        sBerryBlenderData->mainState++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            UnsetBgTilemapBuffer(2);
            UnsetBgTilemapBuffer(1);
            SetVBlankCallback(NULL);
            sub_81AABF0(sub_807FFA4);

            sBerryBlenderData->mainState = 0;
        }
        break;
    }

    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

void sub_807FD08(struct Sprite* sprite)
{
    sprite->data1 += sprite->data6;
    sprite->data2 -= sprite->data4;
    sprite->data2 += sprite->data7;
    sprite->data0 += sprite->data7;
    sprite->data4--;

    if (sprite->data0 < sprite->data2)
    {
        sprite->data3 = sprite->data4 = sprite->data3 - 1;

        if (++sprite->data5 > 3)
            DestroySprite(sprite);
        else
            PlaySE(SE_TB_KARA);
    }
    sprite->pos1.x = sprite->data1;
    sprite->pos1.y = sprite->data2;
}

void sub_807FD64(struct Sprite* sprite, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    sprite->data0 = a3;
    sprite->data1 = a2;
    sprite->data2 = a3;
    sprite->data3 = a4;
    sprite->data4 = 10;
    sprite->data5 = 0;
    sprite->data6 = a5;
    sprite->data7 = a6;
    sprite->callback = sub_807FD08;
}

void sub_807FD90(u16 a0, u8 a1)
{
    u8 spriteId = sub_80D511C(a0 + 123, 0, 80, a1 & 1);
    sub_807FD64(&gSprites[spriteId], gUnknown_08339C78[a1][0], gUnknown_08339C78[a1][1], gUnknown_08339C78[a1][2], gUnknown_08339C78[a1][3], gUnknown_08339C78[a1][4]);
}

void Blender_CopyBerryData(struct BlenderBerry* berry, u16 itemId)
{
    const struct Berry *berryInfo = GetBerryInfo(ITEM_TO_BERRY(itemId));

    berry->itemId = itemId;
    StringCopy(berry->name, berryInfo->name);
    berry->flavours[FLAVOUR_SPICY] = berryInfo->spicy;
    berry->flavours[FLAVOUR_DRY] = berryInfo->dry;
    berry->flavours[FLAVOUR_SWEET] = berryInfo->sweet;
    berry->flavours[FLAVOUR_BITTER] = berryInfo->bitter;
    berry->flavours[FLAVOUR_SOUR] = berryInfo->sour;
    berry->smoothness = berryInfo->smoothness;
}

void Blender_SetPlayerNamesLocal(u8 opponentsNum)
{
    switch (opponentsNum)
    {
    case 0:
        gInGameOpponentsNo = 0;
        break;
    case 1:
        gInGameOpponentsNo = 1;
        sBerryBlenderData->playersNo = 2;
        StringCopy(gLinkPlayers[0].name, gSaveBlock2Ptr->playerName);

        if (!FlagGet(FLAG_340))
            StringCopy(gLinkPlayers[1].name, sBlenderOpponentsNames[BLENDER_MASTER]);
        else
            StringCopy(gLinkPlayers[1].name, sBlenderOpponentsNames[BLENDER_MISTER]);

        gLinkPlayers[0].language = GAME_LANGUAGE;
        gLinkPlayers[1].language = GAME_LANGUAGE;
        break;
    case 2:
        gInGameOpponentsNo = 2;
        sBerryBlenderData->playersNo = 3;
        StringCopy(gLinkPlayers[0].name, gSaveBlock2Ptr->playerName);
        StringCopy(gLinkPlayers[1].name, sBlenderOpponentsNames[BLENDER_DUDE]);
        StringCopy(gLinkPlayers[2].name, sBlenderOpponentsNames[BLENDER_LASSIE]);

        gLinkPlayers[0].language = GAME_LANGUAGE;
        gLinkPlayers[1].language = GAME_LANGUAGE;
        gLinkPlayers[2].language = GAME_LANGUAGE;
        break;
    case 3:
        gInGameOpponentsNo = 3;
        sBerryBlenderData->playersNo = 4;
        StringCopy(gLinkPlayers[0].name, gSaveBlock2Ptr->playerName);
        StringCopy(gLinkPlayers[1].name, sBlenderOpponentsNames[BLENDER_MISS]);
        StringCopy(gLinkPlayers[2].name, sBlenderOpponentsNames[BLENDER_LADDIE]);
        StringCopy(gLinkPlayers[3].name, sBlenderOpponentsNames[BLENDER_LASSIE]);

        gLinkPlayers[0].language = GAME_LANGUAGE;
        gLinkPlayers[1].language = GAME_LANGUAGE;
        gLinkPlayers[2].language = GAME_LANGUAGE;
        gLinkPlayers[3].language = GAME_LANGUAGE;
        break;
    }
}

void sub_807FFA4(void)
{
    s32 i;

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    if (sBerryBlenderData == NULL)
        sBerryBlenderData = AllocZeroed(sizeof(*sBerryBlenderData));

    sBerryBlenderData->mainState = 0;
    sBerryBlenderData->field_10C = 0;

    for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        sBerryBlenderData->chosenItemId[i] = ITEM_NONE;

    Blender_SetPlayerNamesLocal(gSpecialVar_0x8004);

    if (gSpecialVar_0x8004 == 0)
        SetMainCallback2(sub_8080018);
    else
        SetMainCallback2(sub_80808D4);
}

void sub_8080018(void)
{
    s32 i, j;

    switch (sBerryBlenderData->mainState)
    {
    case 0:
        sub_8080588();
        gLinkType = 0x4422;
        sBerryBlenderData->field_72 = 0;
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlenderData->field_64[i] = 0;
            for (j = 0; j < 3; j++)
            {
                sBerryBlenderData->scores[i][j] = 0;
            }
        }
        sBerryBlenderData->field_70 = 0;
        sBerryBlenderData->field_4E = 0;
        sBerryBlenderData->loadGfxState = 0;
        sBerryBlenderData->mainState++;
        break;
    case 1:
        if (LoadBerryBlenderGfx())
        {
            sBerryBlenderData->mainState++;
            sub_8082D28();
        }
        break;
    case 2:
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlenderData->syncArrowSprite2Ids[i] = CreateSprite(&sBlenderSyncArrow_SpriteTemplate, sBlenderSyncArrowsPos[i][0], sBlenderSyncArrowsPos[i][1], 1);
            StartSpriteAnim(&gSprites[sBerryBlenderData->syncArrowSprite2Ids[i]], i + 8);
        }
        if (gReceivedRemoteLinkPlayers != 0 && gLinkVSyncDisabled)
        {
            sub_800E0E8();
            sub_800DFB4(0, 0);
        }
        sBerryBlenderData->mainState++;
        break;
    case 3:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        sBerryBlenderData->mainState++;
        break;
    case 4:
        sub_807F9D0();
        if (!gPaletteFade.active)
        {
            sBerryBlenderData->mainState++;
        }
        break;
    case 5:
        Blender_PrintText(&sBerryBlenderData->textState, sText_CommunicationStandby, 0);
        sBerryBlenderData->mainState = 8;
        sBerryBlenderData->framesToWait = 0;
        break;
    case 8:
        sBerryBlenderData->mainState++;
        sBerryBlenderData->field_114 = 0;
        Blender_CopyBerryData(&sBerryBlenderData->blendedBerries[0], gSpecialVar_ItemId);
        memcpy(gBlockSendBuffer, &sBerryBlenderData->blendedBerries[0], sizeof(struct BlenderBerry));
        sub_800ADF8();
        sBerryBlenderData->framesToWait = 0;
        break;
    case 9:
        if (sub_800A520())
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() == 0)
                sub_800A4D8(4);
            sBerryBlenderData->mainState++;
        }
        break;
    case 10:
        if (++sBerryBlenderData->framesToWait > 20)
        {
            sub_8197DF8(4, TRUE);
            if (GetBlockReceivedStatus() == sub_800A9D8())
            {
                for (i = 0; i < GetLinkPlayerCount(); i++)
                {
                    memcpy(&sBerryBlenderData->blendedBerries[i], &gBlockRecvBuffer[i][0], sizeof(struct BlenderBerry));
                    sBerryBlenderData->chosenItemId[i] = sBerryBlenderData->blendedBerries[i].itemId;
                }

                ResetBlockReceivedFlags();
                sBerryBlenderData->mainState++;
            }
        }
        break;
    case 11:
        sBerryBlenderData->playersNo = GetLinkPlayerCount();

        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            if (sBerryBlenderData->field_114 == gUnknown_083399D0[sBerryBlenderData->playersNo - 2][i])
            {
                sub_807FD90(sBerryBlenderData->chosenItemId[sBerryBlenderData->field_114], i);
                break;
            }
        }

        sBerryBlenderData->framesToWait = 0;
        sBerryBlenderData->mainState++;
        sBerryBlenderData->field_114++;
        break;
    case 12:
        if (++sBerryBlenderData->framesToWait > 60)
        {
            if (sBerryBlenderData->field_114 >= sBerryBlenderData->playersNo)
            {
                sBerryBlenderData->mainState++;
                sBerryBlenderData->arrowPos = gUnknown_083399DC[gUnknown_083399E4[sBerryBlenderData->playersNo - 2]] - 22528;
            }
            else
            {
                sBerryBlenderData->mainState--;
            }
            sBerryBlenderData->framesToWait = 0;
        }
        break;
    case 13:
        if (sub_800A520())
        {
            sBerryBlenderData->mainState++;
            sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
            PlaySE(SE_RU_HYUU);
            ShowBg(2);
        }
        break;
    case 14:
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        sBerryBlenderData->arrowPos += 0x200;
        sBerryBlenderData->field_11A += 4;
        if (sBerryBlenderData->field_11A > 255)
        {
            SetGpuRegBits(REG_OFFSET_BG2CNT, 2);
            sBerryBlenderData->mainState++;
            sBerryBlenderData->field_11A = 256;
            sBerryBlenderData->arrowPos = gUnknown_083399DC[gUnknown_083399E4[sBerryBlenderData->playersNo - 2]];
            sBerryBlenderData->framesToWait = 0;
            PlaySE(SE_TRACK_DOOR);
            sub_808074C();
            Blender_PrintPlayerNames();
        }
        sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
        break;
    case 15:
        if (sub_8083380())
        {
            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->mainState++;
        }
        sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
        break;
    case 16:
        CreateSprite(&gUnknown_08339C2C, 120, -16, 3);
        sBerryBlenderData->mainState++;
        break;
    case 18:
        sBerryBlenderData->mainState++;
        break;
    case 19:
        sub_800ADF8();
        sBerryBlenderData->mainState++;
        break;
    case 20:
        if (sub_800A520())
        {
            sub_800A418();
            sBerryBlenderData->mainState++;
        }
        break;
    case 21:
        sBerryBlenderData->field_4C = 128;
        sBerryBlenderData->gameFrameTime = 0;
        SetMainCallback2(sub_8081898);
        if (GetCurrentMapMusic() != BGM_CYCLING)
        {
            sBerryBlenderData->field_154 = GetCurrentMapMusic();
        }
        PlayBGM(BGM_CYCLING);
        break;
    }

    Blender_DummiedOutFunc(sBerryBlenderData->field_11C, sBerryBlenderData->field_11E);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

void sub_8080588(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();

    SetVBlankCallback(VBlankCB0_BerryBlender);

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sBerryBlenderBgTemplates, ARRAY_COUNT(sBerryBlenderBgTemplates));

    SetBgTilemapBuffer(1, sBerryBlenderData->tilemapBuffers[0]);
    SetBgTilemapBuffer(2, sBerryBlenderData->tilemapBuffers[1]);

    sub_809882C(0, 1, 0xD0);
    copy_textbox_border_tile_patterns_to_vram(0, 0x14, 0xF0);
    InitBerryBlenderWindows();

    sBerryBlenderData->field_44 = 0;
    sBerryBlenderData->field_4C = 0;
    sBerryBlenderData->arrowPos = 0;
    sBerryBlenderData->field_4E = 0;
    sBerryBlenderData->field_11C = 0;
    sBerryBlenderData->field_11E = 0;
}

u8 sub_8080624(u16 arrowPos, u8 playerId)
{
    u32 var1 = (arrowPos / 256) + 24;
    u8 arrID = sBerryBlenderData->field_96[playerId];
    u32 var2 = gUnknown_083399E7[arrID];

    if (var1 >= var2 && var1 < var2 + 48)
    {
        if (var1 >= var2 + 20 && var1 < var2 + 28)
            return 2;
        else
            return 1;
    }

    return 0;
}

void Blender_SetOpponentsBerryData(u16 playerBerryItemId, u8 playersNum, struct BlenderBerry* playerBerry)
{
    u16 opponentSetId = 0;
    u16 opponentBerryId;
    u16 var;
    u16 i;

    if (playerBerryItemId == ITEM_ENIGMA_BERRY)
    {
        for (i = 0; i < FLAVOUR_COUNT; i++)
        {
            if (playerBerry->flavours[opponentSetId] > playerBerry->flavours[i])
                opponentSetId = i;
        }
        opponentSetId += 5;
    }
    else
    {
        opponentSetId = playerBerryItemId - FIRST_BERRY_INDEX;
        if (opponentSetId >= 5)
            opponentSetId = (opponentSetId % 5) + 5;
    }
    for (i = 0; i < playersNum - 1; i++)
    {
        opponentBerryId = sOpponentBerrySets[opponentSetId][i];
        var = playerBerryItemId - 163;
        if (!FlagGet(0x340) && gSpecialVar_0x8004 == 1)
        {
            opponentSetId %= 5;
            opponentBerryId = sSpecialOpponentBerrySets[opponentSetId];
            if (var <= 4)
                opponentBerryId -= 5;
        }
        Blender_SetBankBerryData(i + 1, opponentBerryId + FIRST_BERRY_INDEX);
    }
}

void sub_808074C(void)
{
    s32 i, j;

    for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
    {
        sBerryBlenderData->field_96[i] = 0xFF;
        sBerryBlenderData->field_8E[i] = gUnknown_083399D0[sBerryBlenderData->playersNo - 2][i];
    }
    for (j = 0; j < BLENDER_MAX_PLAYERS; j++)
    {
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            if (sBerryBlenderData->field_8E[i] == j)
                sBerryBlenderData->field_96[j] = i;
        }
    }
}

void Blender_PrintPlayerNames(void)
{
    s32 i, width;
    u32 multiplayerId = 0;
    u8 text[20];

    if (gReceivedRemoteLinkPlayers)
        multiplayerId = GetMultiplayerId();

    for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
    {
        if (sBerryBlenderData->field_8E[i] != 0xFF)
        {
            sBerryBlenderData->syncArrowSpriteIds[sBerryBlenderData->field_8E[i]] = sBerryBlenderData->syncArrowSprite2Ids[i];
            StartSpriteAnim(&gSprites[sBerryBlenderData->syncArrowSpriteIds[sBerryBlenderData->field_8E[i]]], i);

            text[0] = EOS;
            StringCopy(text, gLinkPlayers[sBerryBlenderData->field_8E[i]].name);
            width = GetStringCenterAlignXOffset(1, text, 0x38);

            if (multiplayerId == sBerryBlenderData->field_8E[i])
                Blender_AddTextPrinter(i, text, width, 1, 0, 2);
            else
                Blender_AddTextPrinter(i, text, width, 1, 0, 1);

            PutWindowTilemap(i);
            CopyWindowToVram(i, 3);
        }
    }
}

void sub_80808D4(void)
{
    s32 i, j;

    switch (sBerryBlenderData->mainState)
    {
    case 0:
        sub_800B4C0();
        sub_8080588();
        Blender_SetBankBerryData(0, gSpecialVar_ItemId);
        Blender_CopyBerryData(&sBerryBlenderData->blendedBerries[0], gSpecialVar_ItemId);
        Blender_SetOpponentsBerryData(gSpecialVar_ItemId, sBerryBlenderData->playersNo, &sBerryBlenderData->blendedBerries[0]);

        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlenderData->field_64[i] = 0;
            for (j = 0; j < 3; j++)
            {
                sBerryBlenderData->scores[i][j] = 0;
            }
        }

        sBerryBlenderData->field_70 = 0;
        sBerryBlenderData->loadGfxState = 0;
        gLinkType = 0x4422;
        sBerryBlenderData->mainState++;
        break;
    case 1:
        if (LoadBerryBlenderGfx())
        {
            sBerryBlenderData->mainState++;
            sub_8082D28();
        }
        break;
    case 2:
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlenderData->syncArrowSprite2Ids[i] = CreateSprite(&sBlenderSyncArrow_SpriteTemplate, sBlenderSyncArrowsPos[i][0], sBlenderSyncArrowsPos[i][1], 1);
            StartSpriteAnim(&gSprites[sBerryBlenderData->syncArrowSprite2Ids[i]], i + 8);
        }
        sBerryBlenderData->mainState++;
        break;
    case 3:
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        sBerryBlenderData->mainState++;
        sBerryBlenderData->framesToWait = 0;
        break;
    case 4:
        if (++sBerryBlenderData->framesToWait == 2)
            sub_807F9D0();
        if (!gPaletteFade.active)
            sBerryBlenderData->mainState = 8;
        break;
    case 8:
        sBerryBlenderData->mainState = 11;
        sBerryBlenderData->field_114 = 0;
        break;
    case 11:
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            u32 var = gUnknown_083399D0[sBerryBlenderData->playersNo - 2][i];
            if (sBerryBlenderData->field_114 == var)
            {
                sub_807FD90(sBerryBlenderData->chosenItemId[sBerryBlenderData->field_114], i);
                break;
            }
        }
        sBerryBlenderData->framesToWait = 0;
        sBerryBlenderData->mainState++;
        sBerryBlenderData->field_114++;
        break;
    case 12:
        if (++sBerryBlenderData->framesToWait > 60)
        {
            if (sBerryBlenderData->field_114 >= sBerryBlenderData->playersNo)
            {
                sBerryBlenderData->arrowPos = gUnknown_083399DC[gUnknown_083399E4[sBerryBlenderData->playersNo - 2]] - 22528;
                sBerryBlenderData->mainState++;
            }
            else
            {
                sBerryBlenderData->mainState--;
            }
            sBerryBlenderData->framesToWait = 0;
        }
        break;
    case 13:
        sBerryBlenderData->mainState++;
        sub_808074C();
        PlaySE(SE_RU_HYUU);
        sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
        ShowBg(2);
        break;
    case 14:
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        sBerryBlenderData->arrowPos += 0x200;
        sBerryBlenderData->field_11A += 4;
        if (sBerryBlenderData->field_11A > 255)
        {
            sBerryBlenderData->mainState++;
            sBerryBlenderData->field_11A = 256;
            sBerryBlenderData->arrowPos = gUnknown_083399DC[gUnknown_083399E4[sBerryBlenderData->playersNo - 2]];
            SetGpuRegBits(REG_OFFSET_BG2CNT, 2);
            sBerryBlenderData->framesToWait = 0;
            PlaySE(SE_TRACK_DOOR);
            Blender_PrintPlayerNames();
        }
        sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
        break;
    case 15:
        if (sub_8083380())
        {
            sBerryBlenderData->mainState++;
        }
        sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
        break;
    case 16:
        CreateSprite(&gUnknown_08339C2C, 120, -16, 3);
        sBerryBlenderData->mainState++;
        break;
    case 18:
        sBerryBlenderData->mainState++;
        break;
    case 19:
        sBerryBlenderData->mainState++;
        break;
    case 20:
        sBerryBlenderData->mainState++;
        break;
    case 21:
        sub_8080DF8();
        sBerryBlenderData->field_4C = 128;
        sBerryBlenderData->gameFrameTime = 0;
        sBerryBlenderData->field_123 = 0;
        sBerryBlenderData->field_72 = 0;
        SetMainCallback2(sub_8081898);

        if (gSpecialVar_0x8004 == 1)
        {
            if (!FlagGet(FLAG_340))
                sBerryBlenderData->field_120[0] = CreateTask(sub_8081224, 10);
            else
                sBerryBlenderData->field_120[0] = CreateTask(gUnknown_083399EC[0], 10);
        }

        if (gSpecialVar_0x8004 > 1)
        {
            for (i = 0; i < gSpecialVar_0x8004; i++)
                sBerryBlenderData->field_120[i] = CreateTask(gUnknown_083399EC[i], 10 + i);
        }

        if (GetCurrentMapMusic() != BGM_CYCLING)
            sBerryBlenderData->field_154 = GetCurrentMapMusic();

        PlayBGM(BGM_CYCLING);
        PlaySE(SE_MOTER);
        Blender_ControlHitPitch();
        break;
    }

    Blender_DummiedOutFunc(sBerryBlenderData->field_11C, sBerryBlenderData->field_11E);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

void sub_8080DF8(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        gSendCmd[0] = 0;
        gSendCmd[2] = 0;
        gRecvCmds[i][0] = 0;
        gRecvCmds[i][2] = 0;
    }
}

void sub_8080E20(u8 taskId)
{
   if(++gTasks[taskId].data[0] > gTasks[taskId].data[1])
   {
        gRecvCmds[gTasks[taskId].data[2]][2] = 0x2345;
        DestroyTask(taskId);
   }
}

void sub_8080E6C(u8 a0, u8 a1)
{
    u8 taskId = CreateTask(sub_8080E20, 80);
    gTasks[taskId].data[1] = a1;
    gTasks[taskId].data[2] = a0;
}

void sub_8080EA4(u8 taskId)
{
    if (sub_8080624(sBerryBlenderData->arrowPos, 1) == 2)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            if (sBerryBlenderData->field_123 == 0)
            {
                u8 rand = Random() / 655;
                if (sBerryBlenderData->field_4C < 500)
                {
                    if (rand > 75)
                        gRecvCmds[1][2] = 0x4523;
                    else
                        gRecvCmds[1][2] = 0x5432;

                    gRecvCmds[1][2] = 0x5432;
                }
                else if (sBerryBlenderData->field_4C < 1500)
                {
                    if (rand > 80)
                    {
                        gRecvCmds[1][2] = 0x4523;
                    }
                    else
                    {
                        u8 value = rand - 21;
                        if (value < 60)
                            gRecvCmds[1][2] = 0x5432;
                        else if (rand < 10)
                            sub_8080E6C(1, 5);
                    }
                }
                else if (rand <= 90)
                {
                    u8 value = rand - 71;
                    if (value < 20)
                        gRecvCmds[1][2] = 0x5432;
                    else if (rand < 30)
                        sub_8080E6C(1, 5);
                }
                else
                {
                    gRecvCmds[1][2] = 0x4523;
                }
            }
            else
            {
                gRecvCmds[1][2] = 0x4523;
            }

            gTasks[taskId].data[0] = 1;
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

void sub_8080FD0(u8 taskId)
{
    u32 var1 = (sBerryBlenderData->arrowPos + 0x1800) & 0xFFFF;
    u32 var2 = sBerryBlenderData->field_96[2] & 0xFF;
    if ((var1 >> 8) > gUnknown_083399E7[var2] + 20 && (var1 >> 8) < gUnknown_083399E7[var2] + 40)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            if (sBerryBlenderData->field_123 == 0)
            {
                u8 rand = Random() / 655;
                if (sBerryBlenderData->field_4C < 500)
                {
                    if (rand > 66)
                        gRecvCmds[2][2] = 0x4523;
                    else
                        gRecvCmds[2][2] = 0x5432;
                }
                else
                {
                    u8 value;
                    if (rand > 65)
                        gRecvCmds[2][2] = 0x4523;
                    value = rand - 41;
                    if (value < 25)
                        gRecvCmds[2][2] = 0x5432;
                    if (rand < 10)
                        sub_8080E6C(2, 5);
                }

                gTasks[taskId].data[0] = 1;
            }
            else
            {
                gRecvCmds[2][2] = 0x4523;
                gTasks[taskId].data[0] = 1;
            }
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

void sub_80810F8(u8 taskId)
{
    u32 var1, var2;

    var1 = (sBerryBlenderData->arrowPos + 0x1800) & 0xFFFF;
    var2 = sBerryBlenderData->field_96[3] & 0xFF;
    if ((var1 >> 8) > gUnknown_083399E7[var2] + 20 && (var1 >> 8) < gUnknown_083399E7[var2] + 40)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            if (sBerryBlenderData->field_123 == 0)
            {
                u8 rand = (Random() / 655);
                if (sBerryBlenderData->field_4C < 500)
                {
                    if (rand > 88)
                        gRecvCmds[3][2] = 0x4523;
                    else
                        gRecvCmds[3][2] = 0x5432;
                }
                else
                {
                    if (rand > 60)
                    {
                        gRecvCmds[3][2] = 0x4523;
                    }
                    else
                    {
                        s8 value = rand - 56; // makes me wonder what the original code was
                        u8 value2 = value;
                        if (value2 < 5)
                            gRecvCmds[3][2] = 0x5432;
                    }
                    if (rand < 5)
                        sub_8080E6C(3, 5);
                }
                gTasks[taskId].data[0] = 1;
            }
            else
            {
                gRecvCmds[3][2] = 0x4523;
                gTasks[taskId].data[0] = 1;
            }
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

void sub_8081224(u8 taskId)
{
    if (sub_8080624(sBerryBlenderData->arrowPos, 1) == 2)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            gRecvCmds[1][2] = 0x4523;
            gTasks[taskId].data[0] = 1;
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

void sub_8081288(u16 a0, u8 a1)
{
    u8 spriteId;

    spriteId = CreateSprite(&gUnknown_08339B40,
                            sBlenderSyncArrowsPos[a1][0] - (10 * gUnknown_083399C0[a1][0]),
                            sBlenderSyncArrowsPos[a1][1] - (10 * gUnknown_083399C0[a1][1]),
                            1);
    if (a0 == 0x4523)
    {
        StartSpriteAnim(&gSprites[spriteId], 2);
        gSprites[spriteId].callback = sub_8082F9C;
        PlaySE(SE_RU_GASHIN);
    }
    else if (a0 == 0x5432)
    {
        StartSpriteAnim(&gSprites[spriteId], 0);
        PlaySE(SE_SEIKAI);
    }
    else if (a0 == 0x2345)
    {
        StartSpriteAnim(&gSprites[spriteId], 1);
        PlaySE(SE_HAZURE);
    }
    sub_8082E84();
}

void sub_8081370(u16 a0)
{
    Blender_ControlHitPitch();
    switch (a0)
    {
    case 0x4523:
        if (sBerryBlenderData->field_4C < 1500)
            sBerryBlenderData->field_4C += (384 / gUnknown_08339CC3[sBerryBlenderData->playersNo]);
        else
        {
            sBerryBlenderData->field_4C += (128 / gUnknown_08339CC3[sBerryBlenderData->playersNo]);
            sub_80832BC(&sBerryBlenderData->field_11C, (sBerryBlenderData->field_4C / 100) - 10);
            sub_80832BC(&sBerryBlenderData->field_11E, (sBerryBlenderData->field_4C / 100) - 10);
        }
        break;
    case 0x5432:
        if (sBerryBlenderData->field_4C < 1500)
            sBerryBlenderData->field_4C += (256 / gUnknown_08339CC3[sBerryBlenderData->playersNo]);
        break;
    case 0x2345:
        sBerryBlenderData->field_4C -= (256 / gUnknown_08339CC3[sBerryBlenderData->playersNo]);
        if (sBerryBlenderData->field_4C < 128)
            sBerryBlenderData->field_4C = 128;
        break;
    }
}

bool32 sub_80814B0(u16 arg0, u16 arg1, u16 arg2)
{
    if (gReceivedRemoteLinkPlayers != 0 && gLinkVSyncDisabled)
    {
        if ((arg0 & 0xFF00) == arg2)
            return TRUE;
    }
    else
    {
        if (arg0 == arg1)
            return TRUE;
    }

    return FALSE;
}

/*
void sub_80814B0(void)
{
    s32 i;

    if (gSpecialVar_0x8004 != 0)
    {
        if (gSendCmd[2] != 0)
        {
            gRecvCmds[2][0] = gSendCmd[2];
            gRecvCmds[0][0] = 0x4444;
            gSendCmd[2] = 0;
        }
        for (i = 1; i < 4; i++)
        {
            if (gRecvCmds[2][i] != 0)
                gRecvCmds[0][i] = 0x4444;
        }
    }
    for (i = 0; i < gBerryBlenderData->playersNo; i++)
    {
        if (gRecvCmds[0][i] == 0x4444)
        {
            u32 var = gBerryBlenderData->field_A2[i];
            if (gRecvCmds[2][i] == 0x4523)
            {
                sub_804FD30(0x4523);
                gBerryBlenderData->field_13E += (gBerryBlenderData->field_56 / 55);
                if (gBerryBlenderData->field_13E >= 1000)
                    gBerryBlenderData->field_13E = 1000;
                sub_804FC48(0x4523, var);
                gBerryBlenderData->scores[i][BLENDER_SCORE_BEST]++;
            }
            else if (gRecvCmds[2][i] == 0x5432)
            {
                sub_804FD30(0x5432);
                gBerryBlenderData->field_13E += (gBerryBlenderData->field_56 / 70);
                sub_804FC48(0x5432, var);
                gBerryBlenderData->scores[i][BLENDER_SCORE_GOOD]++;
            }
            else if (gRecvCmds[2][i] == 0x2345)
            {
                sub_804FC48(0x2345, var);
                sub_804FD30(0x2345);
                if (gBerryBlenderData->field_4.win_field_F > 1000)
                    gBerryBlenderData->field_13E = 1000;
                if (gBerryBlenderData->scores[i][BLENDER_SCORE_MISS] < 999)
                    gBerryBlenderData->scores[i][BLENDER_SCORE_MISS]++;
            }
            if (gRecvCmds[2][i] == 0x2345 || gRecvCmds[2][i] == 0x4523 || gRecvCmds[2][i] == 0x5432)
            {
                if (gBerryBlenderData->field_56 > 1500)
                    m4aMPlayTempoControl(&gMPlay_BGM, ((gBerryBlenderData->field_56 - 750) / 20) + 256);
                else
                    m4aMPlayTempoControl(&gMPlay_BGM, 256);
            }
        }
    }
    if (gSpecialVar_0x8004 != 0)
    {
        for (i = 0; i < gBerryBlenderData->playersNo; i++)
        {
            gRecvCmds[0][i] = 0;
            gRecvCmds[2][i] = 0;
        }
    }
}*/

