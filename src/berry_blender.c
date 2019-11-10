#include "global.h"
#include "constants/game_stat.h"
#include "overworld.h"
#include "berry_blender.h"
#include "bg.h"
#include "window.h"
#include "task.h"
#include "sprite.h"
#include "sound.h"
#include "constants/songs.h"
#include "m4a.h"
#include "bg.h"
#include "palette.h"
#include "decompress.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "text.h"
#include "text_window.h"
#include "event_data.h"
#include "main.h"
#include "link.h"
#include "item_menu_icons.h"
#include "berry.h"
#include "item.h"
#include "constants/items.h"
#include "string_util.h"
#include "international_string_util.h"
#include "random.h"
#include "menu.h"
#include "pokeblock.h"
#include "trig.h"
#include "tv.h"
#include "item_menu.h"
#include "battle_records.h"
#include "graphics.h"
#include "new_game.h"
#include "save.h"
#include "link.h"
#include "constants/berry.h"
#include "constants/rgb.h"

#define BLENDER_SCORE_BEST      0
#define BLENDER_SCORE_GOOD      1
#define BLENDER_SCORE_MISS      2

#define BLENDER_MAX_PLAYERS     4
#define BLENDER_SCORES_NO       3

enum
{
    PLAY_AGAIN_OK,
    DONT_PLAY_AGAIN,
    CANT_PLAY_NO_BERRIES,
    CANT_PLAY_NO_PKBLCK_SPACE
};

struct BlenderBerry
{
    u16 itemId;
    u8 name[BERRY_NAME_LENGTH + 1];
    u8 flavors[FLAVOR_COUNT];
    u8 smoothness;
};

struct TimeAndRPM
{
    u32 time;
    u16 max_RPM;
};

struct BlenderGameBlock
{
    struct TimeAndRPM timeRPM;
    u16 scores[BLENDER_MAX_PLAYERS][BLENDER_SCORES_NO];
};

struct TvBlenderStruct
{
    u8 name[11];
    u8 pokeblockFlavor;
    u8 pokeblockColor;
    u8 pokeblockSheen;
};

struct BerryBlenderData
{
    u8 mainState;
    u8 loadGfxState;
    u8 unused_02[0x42];
    u16 field_44;
    u8 scoreIconIds[BLENDER_SCORES_NO];
    u16 arrowPos;
    s16 field_4C;
    u16 max_RPM;
    u8 syncArrowSpriteIds[BLENDER_MAX_PLAYERS];
    u8 syncArrowSprite2Ids[BLENDER_MAX_PLAYERS];
    u8 unused_57[0xB];
    u8 gameEndState;
    u16 field_64[BLENDER_MAX_PLAYERS];
    u16 field_6C;
    u16 field_6E;
    u16 playAgainState;
    u8 field_72;
    u16 chosenItemId[BLENDER_MAX_PLAYERS];
    u8 playersNo;
    u8 unused_7D[0x10];
    u16 field_8E[BLENDER_MAX_PLAYERS];
    u16 field_96[BLENDER_MAX_PLAYERS];
    u8 yesNoAnswer;
    u8 stringVar[100];
    u32 gameFrameTime;
    s32 framesToWait;
    u32 field_10C;
    u8 unused_110[4];
    u8 field_114;
    u16 field_116;
    u16 field_118;
    u16 field_11A;
    u16 bg_X;
    u16 bg_Y;
    u8 field_120[3];
    u8 field_123;
    u16 scores[BLENDER_MAX_PLAYERS][BLENDER_SCORES_NO];
    u8 playerPlaces[BLENDER_MAX_PLAYERS];
    struct BgAffineSrcData bgAffineSrc;
    u16 field_154;
    struct BlenderBerry blendedBerries[BLENDER_MAX_PLAYERS];
    struct TimeAndRPM smallBlock;
    u32 field_1A0;
    u8 field_1A4;
    struct TvBlenderStruct tvBlender;
    u8 tilemapBuffers[2][0x800];
    s16 textState;
    void *tilesBuffer;
    struct BlenderGameBlock gameBlock;
};

extern struct MusicPlayerInfo gMPlayInfo_SE2;
extern struct MusicPlayerInfo gMPlayInfo_BGM;

// text
extern const u8 gText_SavingDontTurnOff2[];
extern const u8 gText_Space[];
extern const u8 gText_BlenderMaxSpeedRecord[];
extern const u8 gText_234Players[];

// this file's functions
static void BerryBlender_SetBackgroundsPos(void);
static void sub_8080EA4(u8 taskId);
static void sub_8080FD0(u8 taskId);
static void sub_80810F8(u8 taskId);
static void sub_8081224(u8 taskId);
static void sub_8083F3C(u8 taskId);
static void sub_80833F8(struct Sprite *sprite);
static void sub_8082F68(struct Sprite *sprite);
static void sub_8083010(struct Sprite *sprite);
static void sub_80830C0(struct Sprite *sprite);
static void sub_8082F9C(struct Sprite *sprite);
static void Blender_SetPlayerNamesLocal(u8 opponentsNum);
static void sub_807FAC8(void);
static void sub_8082D28(void);
static bool32 Blender_PrintText(s16 *textState, const u8 *string, s32 textSpeed);
static void sub_807FFA4(void);
static void sub_8080018(void);
static void sub_80808D4(void);
static void Blender_DummiedOutFunc(s16 a0, s16 a1);
static void sub_8081898(void);
static void sub_8082CB4(struct BgAffineSrcData *bgAffineSrc);
static bool8 sub_8083380(void);
static void sub_808074C(void);
static void Blender_PrintPlayerNames(void);
static void sub_8080588(void);
static void Blender_SetParticipantBerryData(u8 participantId, u16 itemId);
static void Blender_AddTextPrinter(u8 windowId, const u8 *string, u8 x, u8 y, s32 speed, s32 caseId);
static void sub_8080DF8(void);
static void sub_8082E84(void);
static void sub_80832BC(s16* a0, u16 a1);
static void sub_8083140(u16 a0, u16 a2);
static void sub_8083230(u16 a0);
static void sub_808330C(void);
static void sub_8082AD4(void);
static void CB2_HandleBlenderEndGame(void);
static bool8 Blender_PrintBlendingRanking(void);
static bool8 Blender_PrintBlendingResults(void);
static void CB2_HandlePlayerPlayAgainChoice(void);
static void CB2_HandlePlayerLinkPlayAgainChoice(void);
static void sub_8083170(u16 a0, u16 a1);
static void Blender_PrintMadePokeblockString(struct Pokeblock *pokeblock, u8 *dst);
static bool32 TryAddContestLinkTvShow(struct Pokeblock *pokeblock, struct TvBlenderStruct *a1);

// EWRAM
EWRAM_DATA static struct BerryBlenderData *sBerryBlenderData = NULL;
EWRAM_DATA static s32 sUnknown_020322A8[5] = {0};
EWRAM_DATA static s32 sUnknown_020322BC[5] = {0};
EWRAM_DATA static u32 sUnknown_020322D0 = 0;

// IWRAM bss
static s16 sUnknown_03000DE8[8];
static s16 sUnknown_03000DF8[6];
static s16 sUnknown_03000E04;
static s16 sUnknown_03000E06;

// IWRAM common
u8 gInGameOpponentsNo;

// rom

static const u16 sBlenderCenterPal[] = INCBIN_U16("graphics/berry_blender/center.gbapal");
static const u8 sBlenderCenterMap[] = INCBIN_U8("graphics/berry_blender/center_map.bin");
static const u16 sBlenderOuterPal[] = INCBIN_U16("graphics/berry_blender/outer.gbapal");

// unreferenced pals?
static const u16 sUnknownPal_0[] = INCBIN_U16("graphics/unknown/unknown_339514.gbapal");
static const u16 sUnknownArray_1[224] = {0};

// unused text?
static const u8 sUnusedText_YesNo[] = _("YES\nNO");
static const u8 sUnusedText_2[] = _("▶");
static const u8 sUnusedText_Space[] = _(" ");
static const u8 sUnusedText_Terminating[] = _("Terminating.");
static const u8 sUnusedText_LinkPartnerNotFound[] = _("Link partner(s) not found.\nPlease try again.\p");

static const u8 sText_BerryBlenderStart[] = _("Starting up the BERRY BLENDER.\pPlease select a BERRY from your BAG\nto put in the BERRY BLENDER.\p");
static const u8 sText_NewParagraph[] = _("\p");
static const u8 sText_WasMade[] = _(" was made!");
static const u8 sText_Mister[] = _("MISTER");
static const u8 sText_Laddie[] = _("LADDIE");
static const u8 sText_Lassie[] = _("LASSIE");
static const u8 sText_Master[] = _("MASTER");
static const u8 sText_Dude[] = _("DUDE");
static const u8 sText_Miss[] = _("MISS");

static const u8* const sBlenderOpponentsNames[] =
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
static const u8 sText_CommunicationStandby[] = _("Communication standby…");
static const u8 sText_WouldLikeToBlendAnotherBerry[] = _("Would you like to blend another BERRY?");
static const u8 sText_RunOutOfBerriesForBlending[] = _("You've run out of BERRIES for\nblending in the BERRY BLENDER.\p");
static const u8 sText_YourPokeblockCaseIsFull[] = _("Your {POKEBLOCK} CASE is full.\p");
static const u8 sText_HasNoBerriesToPut[] = _(" has no BERRIES to put in\nthe BERRY BLENDER.");
static const u8 sText_ApostropheSPokeblockCaseIsFull[] = _("'s {POKEBLOCK} CASE is full.\p");
static const u8 sText_BlendingResults[] = _("RESULTS OF BLENDING");
static const u8 sText_BerryUsed[] = _("BERRY USED");
static const u8 sText_SpaceBerry[] = _(" BERRY");
static const u8 sText_Time[] = _("Time:");
static const u8 sText_Min[] = _(" min. ");
static const u8 sText_Sec[] = _(" sec.");
static const u8 sText_MaximumSpeed[] = _("MAXIMUM SPEED");
static const u8 sText_RPM[] = _(" RPM");
static const u8 sText_Dot[] = _(".");
static const u8 sText_NewLine[] = _("\n");
static const u8 sText_Space[] = _(" ");
static const u8 sText_Ranking[] = _("RANKING");
static const u8 sText_TheLevelIs[] = _("The level is ");
static const u8 sText_TheFeelIs[] = _(", and the feel is ");
static const u8 sText_Dot2[] = _(".");

static const struct BgTemplate sBerryBlenderBgTemplates[3] =
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
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 6,
        .width = 7,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 0x28,
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 6,
        .width = 7,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 0x36,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 12,
        .width = 7,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 0x44,
    },
    {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 12,
        .width = 7,
        .height = 2,
        .paletteNum = 14,
        .baseBlock = 0x52,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x60,
    },
    {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 3,
        .width = 21,
        .height = 14,
        .paletteNum = 14,
        .baseBlock = 0x60,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sBlender_YesNoWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 14,
    .baseBlock = 0xCC
};

static const s8 sUnknown_083399C0[][2] =
{
    {-1, -1}, {1, -1}, {-1, 1}, {1, 1}
};

static const u8 sBlenderSyncArrowsPos[BLENDER_MAX_PLAYERS][2] =
{
    {72, 32}, {168, 32}, {72, 128}, {168, 128}
};

static const u8 sUnknown_083399D0[3][4] =
{
    {-1, 0, 1, -1}, {-1, 0, 1, 2}, {0, 1, 2, 3}
};

static const u16 sUnknown_083399DC[] = {0, 0xC000, 0x4000, 0x8000};
static const u8 sUnknown_083399E4[] = {1, 1, 0};
static const u8 sUnknown_083399E7[] = {32, 224, 96, 160, 0};

static const TaskFunc sUnknown_083399EC[] =
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
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
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

static const struct SpriteSheet sSpriteSheet_BlenderArrow =
{
    gBerryBlenderArrowTiles, 0x800, 46545
};

static const struct SpritePalette sSpritePal_BlenderMisc =
{
    gBerryBlenderMiscPalette, 46546
};

static const struct SpritePalette sSpritePal_BlenderArrow =
{
    gBerryBlenderArrowPalette, 12312
};

static const struct SpriteTemplate sBlenderSyncArrow_SpriteTemplate =
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
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
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

static const struct SpriteSheet sUnknown_08339B38 =
{
    gBerryBlenderMarubatsuTiles, 0x200, 48888
};

static const struct SpriteTemplate sUnknown_08339B40 =
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
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
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

static const struct SpriteSheet sUnknown_08339BD8 =
{
    gBerryBlenderParticlesTiles, 0xE0, 23456
};

static const struct SpriteTemplate sUnknown_08339BE0 =
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
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
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

static const struct SpriteSheet sUnknown_08339C24 =
{
    gBerryBlenderCountdownNumbersTiles, 0x600, 12345
};

static const struct SpriteTemplate sUnknown_08339C2C =
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
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
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

static const struct SpriteSheet sUnknown_08339C58 =
{
    gBerryBlenderStartTiles, 0x400, 12346
};

static const struct SpriteTemplate sUnknown_08339C60 =
{
    .tileTag = 12346,
    .paletteTag = 46546,
    .oam = &sOamData_8216560,
    .anims = sSpriteAnimTable_8216570,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80830C0
};

static const s16 sUnknown_08339C78[][5] =
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

static const u8 sUnknown_08339CC3[] = {1, 1, 2, 3, 4};

static const u8 sUnknown_08339CC8[] = {0x1C, 0x16, 0x13, 0x1A, 0x19, 0x0E, 0x0D, 0x0B, 0x07, 0x15};

static const u8 sUnknown_08339CD2[] =
{
    0xfe, 0x02, 0x02, 0xce, 0xd0, 0x37, 0x44, 0x07, 0x1f, 0x0c, 0x10,
    0x00, 0xff, 0xfe, 0x91, 0x72, 0xce, 0xd0, 0x37, 0x44, 0x07, 0x1f,
    0x0c, 0x10, 0x00, 0xff, 0x06, 0x27, 0x02, 0xff, 0x00, 0x0c, 0x48,
    0x02, 0xff, 0x00, 0x01, 0x1f, 0x02, 0xff, 0x00, 0x16, 0x37, 0x02,
    0xff, 0x00, 0x0d, 0x50, 0x4b, 0x02, 0xff, 0x06, 0x06, 0x06, 0x06,
    0x05, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02
};

static const struct WindowTemplate sBlenderRecordWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 6,
    .tilemapTop = 4,
    .width = 18,
    .height = 11,
    .paletteNum = 15,
    .baseBlock = 8
};

// code

static void Blender_ControlHitPitch(void)
{
    m4aMPlayPitchControl(&gMPlayInfo_SE2, 0xFFFF, 2 * (sBerryBlenderData->field_4C - 128));
}

static void VBlankCB0_BerryBlender(void)
{
    BerryBlender_SetBackgroundsPos();
    SetBgAffine(2, sBerryBlenderData->bgAffineSrc.texX, sBerryBlenderData->bgAffineSrc.texY,
                sBerryBlenderData->bgAffineSrc.scrX, sBerryBlenderData->bgAffineSrc.scrY,
                sBerryBlenderData->bgAffineSrc.sx, sBerryBlenderData->bgAffineSrc.sy,
                sBerryBlenderData->bgAffineSrc.alpha);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 LoadBerryBlenderGfx(void)
{
    switch (sBerryBlenderData->loadGfxState)
    {
    case 0:
        sBerryBlenderData->tilesBuffer = AllocZeroed(GetDecompressedDataSize(sBlenderCenterGfx) + 100);
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
        LoadBgTiles(2, sBerryBlenderData->tilesBuffer, GetDecompressedDataSize(sBlenderCenterGfx), 0);
        sBerryBlenderData->loadGfxState++;
        break;
    case 3:
        LZDecompressWram(gUnknown_08D91DB8, sBerryBlenderData->tilesBuffer);
        sBerryBlenderData->loadGfxState++;
        break;
    case 4:
        LoadBgTiles(1, sBerryBlenderData->tilesBuffer, GetDecompressedDataSize(gUnknown_08D91DB8), 0);
        sBerryBlenderData->loadGfxState++;
        break;
    case 5:
        LZDecompressWram(gUnknown_08D927EC, sBerryBlenderData->tilesBuffer);
        sBerryBlenderData->loadGfxState++;
        break;
    case 6:
        CopyToBgTilemapBuffer(1, sBerryBlenderData->tilesBuffer, GetDecompressedDataSize(gUnknown_08D927EC), 0);
        CopyBgTilemapBufferToVram(1);
        sBerryBlenderData->loadGfxState++;
        break;
    case 7:
        LoadPalette(sBlenderOuterPal, 0x80, 0x20);
        sBerryBlenderData->loadGfxState++;
        break;
    case 8:
        LoadSpriteSheet(&sSpriteSheet_BlenderArrow);
        LoadSpriteSheet(&sUnknown_08339BD8);
        LoadSpriteSheet(&sUnknown_08339B38);
        sBerryBlenderData->loadGfxState++;
        break;
    case 9:
        LoadSpriteSheet(&sUnknown_08339C24);
        LoadSpriteSheet(&sUnknown_08339C58);
        LoadSpritePalette(&sSpritePal_BlenderArrow);
        LoadSpritePalette(&sSpritePal_BlenderMisc);
        Free(sBerryBlenderData->tilesBuffer);
        sBerryBlenderData->loadGfxState = 0;
        return TRUE;
    }

    return FALSE;
}

static void sub_807F9D0(void)
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

static void InitBerryBlenderWindows(void)
{
    if (InitWindows(sBerryBlender_WindowTemplates))
    {
        s32 i;

        DeactivateAllTextPrinters();
        for (i = 0; i < 5; i++)
            FillWindowPixelBuffer(i, PIXEL_FILL(0));

        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
        Menu_LoadStdPalAt(0xE0);
    }
}

void DoBerryBlending(void)
{
    if (sBerryBlenderData == NULL)
        sBerryBlenderData = AllocZeroed(sizeof(*sBerryBlenderData));

    sBerryBlenderData->gameEndState = 0;
    sBerryBlenderData->mainState = 0;
    sBerryBlenderData->gameEndState = 0;

    Blender_SetPlayerNamesLocal(gSpecialVar_0x8004);
    SetMainCallback2(sub_807FAC8);
}

static void sub_807FAC8(void)
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
        LoadUserWindowBorderGfx(0, 1, 0xD0);
        LoadMessageBoxGfx(0, 0x14, 0xF0);
        InitBerryBlenderWindows();

        sBerryBlenderData->mainState++;
        sBerryBlenderData->field_118 = 0;
        sBerryBlenderData->field_116 = 0;
        sBerryBlenderData->field_11A = 0x50;
        sBerryBlenderData->bg_X = 0;
        sBerryBlenderData->bg_Y = 0;
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
            if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
            {
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
            SetVBlankCallback(VBlankCB0_BerryBlender);
            sBerryBlenderData->mainState++;
        }
        break;
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        sub_8082D28();
        sBerryBlenderData->mainState++;
        break;
    case 3:
        sub_807F9D0();
        if (!gPaletteFade.active)
            sBerryBlenderData->mainState++;
        break;
    case 4:
        if (Blender_PrintText(&sBerryBlenderData->textState, sText_BerryBlenderStart, GetPlayerTextSpeedDelay()))
            sBerryBlenderData->mainState++;
        break;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        sBerryBlenderData->mainState++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            UnsetBgTilemapBuffer(2);
            UnsetBgTilemapBuffer(1);
            SetVBlankCallback(NULL);
            ChooseBerrySetCallback(sub_807FFA4);

            sBerryBlenderData->mainState = 0;
        }
        break;
    }

    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void sub_807FD08(struct Sprite* sprite)
{
    sprite->data[1] += sprite->data[6];
    sprite->data[2] -= sprite->data[4];
    sprite->data[2] += sprite->data[7];
    sprite->data[0] += sprite->data[7];
    sprite->data[4]--;

    if (sprite->data[0] < sprite->data[2])
    {
        sprite->data[3] = sprite->data[4] = sprite->data[3] - 1;

        if (++sprite->data[5] > 3)
            DestroySprite(sprite);
        else
            PlaySE(SE_TB_KARA);
    }
    sprite->pos1.x = sprite->data[1];
    sprite->pos1.y = sprite->data[2];
}

static void sub_807FD64(struct Sprite* sprite, s16 a2, s16 a3, s16 a4, s16 a5, s16 a6)
{
    sprite->data[0] = a3;
    sprite->data[1] = a2;
    sprite->data[2] = a3;
    sprite->data[3] = a4;
    sprite->data[4] = 10;
    sprite->data[5] = 0;
    sprite->data[6] = a5;
    sprite->data[7] = a6;
    sprite->callback = sub_807FD08;
}

static void sub_807FD90(u16 a0, u8 a1)
{
    u8 spriteId = LoadSpinningBerryPicGfx(a0 + 123, 0, 80, a1 & 1);
    sub_807FD64(&gSprites[spriteId], sUnknown_08339C78[a1][0], sUnknown_08339C78[a1][1], sUnknown_08339C78[a1][2], sUnknown_08339C78[a1][3], sUnknown_08339C78[a1][4]);
}

static void Blender_CopyBerryData(struct BlenderBerry* berry, u16 itemId)
{
    const struct Berry *berryInfo = GetBerryInfo(ITEM_TO_BERRY(itemId));

    berry->itemId = itemId;
    StringCopy(berry->name, berryInfo->name);
    berry->flavors[FLAVOR_SPICY] = berryInfo->spicy;
    berry->flavors[FLAVOR_DRY] = berryInfo->dry;
    berry->flavors[FLAVOR_SWEET] = berryInfo->sweet;
    berry->flavors[FLAVOR_BITTER] = berryInfo->bitter;
    berry->flavors[FLAVOR_SOUR] = berryInfo->sour;
    berry->smoothness = berryInfo->smoothness;
}

static void Blender_SetPlayerNamesLocal(u8 opponentsNum)
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

        if (!FlagGet(FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER))
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

static void sub_807FFA4(void)
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

static void sub_8080018(void)
{
    s32 i, j;

    switch (sBerryBlenderData->mainState)
    {
    case 0:
        sub_8080588();
        gLinkType = LINKTYPE_BERRY_BLENDER;
        sBerryBlenderData->field_72 = 0;
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlenderData->field_64[i] = 0;
            for (j = 0; j < 3; j++)
            {
                sBerryBlenderData->scores[i][j] = 0;
            }
        }
        sBerryBlenderData->playAgainState = 0;
        sBerryBlenderData->max_RPM = 0;
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
        if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        sBerryBlenderData->mainState++;
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
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
        if (IsLinkTaskFinished())
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
            ClearDialogWindowAndFrameToTransparent(4, TRUE);
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
            if (sBerryBlenderData->field_114 == sUnknown_083399D0[sBerryBlenderData->playersNo - 2][i])
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
                sBerryBlenderData->arrowPos = sUnknown_083399DC[sUnknown_083399E4[sBerryBlenderData->playersNo - 2]] - 22528;
            }
            else
            {
                sBerryBlenderData->mainState--;
            }
            sBerryBlenderData->framesToWait = 0;
        }
        break;
    case 13:
        if (IsLinkTaskFinished())
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
        if (sBerryBlenderData->field_11A > 0xFF)
        {
            SetGpuRegBits(REG_OFFSET_BG2CNT, 2);
            sBerryBlenderData->mainState++;
            sBerryBlenderData->field_11A = 0x100;
            sBerryBlenderData->arrowPos = sUnknown_083399DC[sUnknown_083399E4[sBerryBlenderData->playersNo - 2]];
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
        CreateSprite(&sUnknown_08339C2C, 120, -16, 3);
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
        if (IsLinkTaskFinished())
        {
            sub_800A418();
            sBerryBlenderData->mainState++;
        }
        break;
    case 21:
        sBerryBlenderData->field_4C = 128;
        sBerryBlenderData->gameFrameTime = 0;
        SetMainCallback2(sub_8081898);
        if (GetCurrentMapMusic() != MUS_CYCLING)
        {
            sBerryBlenderData->field_154 = GetCurrentMapMusic();
        }
        PlayBGM(MUS_CYCLING);
        break;
    }

    Blender_DummiedOutFunc(sBerryBlenderData->bg_X, sBerryBlenderData->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void sub_8080588(void)
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
    LoadUserWindowBorderGfx(0, 1, 0xD0);
    LoadMessageBoxGfx(0, 0x14, 0xF0);
    InitBerryBlenderWindows();

    sBerryBlenderData->field_44 = 0;
    sBerryBlenderData->field_4C = 0;
    sBerryBlenderData->arrowPos = 0;
    sBerryBlenderData->max_RPM = 0;
    sBerryBlenderData->bg_X = 0;
    sBerryBlenderData->bg_Y = 0;
}

static u8 sub_8080624(u16 arrowPos, u8 playerId)
{
    u32 var1 = (arrowPos / 0x100) + 0x18;
    u8 arrID = sBerryBlenderData->field_96[playerId];
    u32 var2 = sUnknown_083399E7[arrID];

    if (var1 >= var2 && var1 < var2 + 0x30)
    {
        if (var1 >= var2 + 20 && var1 < var2 + 28)
            return 2;
        else
            return 1;
    }

    return 0;
}

static void Blender_SetOpponentsBerryData(u16 playerBerryItemId, u8 playersNum, struct BlenderBerry* playerBerry)
{
    u16 opponentSetId = 0;
    u16 opponentBerryId;
    u16 var;
    u16 i;

    if (playerBerryItemId == ITEM_ENIGMA_BERRY)
    {
        for (i = 0; i < FLAVOR_COUNT; i++)
        {
            if (playerBerry->flavors[opponentSetId] > playerBerry->flavors[i])
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
        if (!FlagGet(FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER) && gSpecialVar_0x8004 == 1)
        {
            opponentSetId %= 5;
            opponentBerryId = sSpecialOpponentBerrySets[opponentSetId];
            if (var <= 4)
                opponentBerryId -= 5;
        }
        Blender_SetParticipantBerryData(i + 1, opponentBerryId + FIRST_BERRY_INDEX);
    }
}

static void sub_808074C(void)
{
    s32 i, j;

    for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
    {
        sBerryBlenderData->field_96[i] = 0xFF;
        sBerryBlenderData->field_8E[i] = sUnknown_083399D0[sBerryBlenderData->playersNo - 2][i];
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

static void Blender_PrintPlayerNames(void)
{
    s32 i, xPos;
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
            xPos = GetStringCenterAlignXOffset(1, text, 0x38);

            if (multiplayerId == sBerryBlenderData->field_8E[i])
                Blender_AddTextPrinter(i, text, xPos, 1, 0, 2);
            else
                Blender_AddTextPrinter(i, text, xPos, 1, 0, 1);

            PutWindowTilemap(i);
            CopyWindowToVram(i, 3);
        }
    }
}

static void sub_80808D4(void)
{
    s32 i, j;

    switch (sBerryBlenderData->mainState)
    {
    case 0:
        sub_800B4C0();
        sub_8080588();
        Blender_SetParticipantBerryData(0, gSpecialVar_ItemId);
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

        sBerryBlenderData->playAgainState = 0;
        sBerryBlenderData->loadGfxState = 0;
        gLinkType = LINKTYPE_BERRY_BLENDER;
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
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
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
            u32 var = sUnknown_083399D0[sBerryBlenderData->playersNo - 2][i];
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
                sBerryBlenderData->arrowPos = sUnknown_083399DC[sUnknown_083399E4[sBerryBlenderData->playersNo - 2]] - 22528;
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
        if (sBerryBlenderData->field_11A > 0xFF)
        {
            sBerryBlenderData->mainState++;
            sBerryBlenderData->field_11A = 0x100;
            sBerryBlenderData->arrowPos = sUnknown_083399DC[sUnknown_083399E4[sBerryBlenderData->playersNo - 2]];
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
        CreateSprite(&sUnknown_08339C2C, 120, -16, 3);
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
        sBerryBlenderData->field_4C = 0x80;
        sBerryBlenderData->gameFrameTime = 0;
        sBerryBlenderData->field_123 = 0;
        sBerryBlenderData->field_72 = 0;
        SetMainCallback2(sub_8081898);

        if (gSpecialVar_0x8004 == 1)
        {
            if (!FlagGet(FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER))
                sBerryBlenderData->field_120[0] = CreateTask(sub_8081224, 10);
            else
                sBerryBlenderData->field_120[0] = CreateTask(sUnknown_083399EC[0], 10);
        }

        if (gSpecialVar_0x8004 > 1)
        {
            for (i = 0; i < gSpecialVar_0x8004; i++)
                sBerryBlenderData->field_120[i] = CreateTask(sUnknown_083399EC[i], 10 + i);
        }

        if (GetCurrentMapMusic() != MUS_CYCLING)
            sBerryBlenderData->field_154 = GetCurrentMapMusic();

        PlayBGM(MUS_CYCLING);
        PlaySE(SE_MOTER);
        Blender_ControlHitPitch();
        break;
    }

    Blender_DummiedOutFunc(sBerryBlenderData->bg_X, sBerryBlenderData->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void sub_8080DF8(void)
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

static void sub_8080E20(u8 taskId)
{
   if(++gTasks[taskId].data[0] > gTasks[taskId].data[1])
   {
        gRecvCmds[gTasks[taskId].data[2]][2] = 0x2345;
        DestroyTask(taskId);
   }
}

static void sub_8080E6C(u8 a0, u8 a1)
{
    u8 taskId = CreateTask(sub_8080E20, 80);
    gTasks[taskId].data[1] = a1;
    gTasks[taskId].data[2] = a0;
}

static void sub_8080EA4(u8 taskId)
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

static void sub_8080FD0(u8 taskId)
{
    u32 var1 = (sBerryBlenderData->arrowPos + 0x1800) & 0xFFFF;
    u32 var2 = sBerryBlenderData->field_96[2] & 0xFF;
    if ((var1 >> 8) > sUnknown_083399E7[var2] + 20 && (var1 >> 8) < sUnknown_083399E7[var2] + 40)
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

static void sub_80810F8(u8 taskId)
{
    u32 var1, var2;

    var1 = (sBerryBlenderData->arrowPos + 0x1800) & 0xFFFF;
    var2 = sBerryBlenderData->field_96[3] & 0xFF;
    if ((var1 >> 8) > sUnknown_083399E7[var2] + 20 && (var1 >> 8) < sUnknown_083399E7[var2] + 40)
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

static void sub_8081224(u8 taskId)
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

static void sub_8081288(u16 a0, u8 a1)
{
    u8 spriteId;

    spriteId = CreateSprite(&sUnknown_08339B40,
                            sBlenderSyncArrowsPos[a1][0] - (10 * sUnknown_083399C0[a1][0]),
                            sBlenderSyncArrowsPos[a1][1] - (10 * sUnknown_083399C0[a1][1]),
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

static void sub_8081370(u16 a0)
{
    Blender_ControlHitPitch();
    switch (a0)
    {
    case 0x4523:
        if (sBerryBlenderData->field_4C < 1500)
            sBerryBlenderData->field_4C += (0x180 / sUnknown_08339CC3[sBerryBlenderData->playersNo]);
        else
        {
            sBerryBlenderData->field_4C += (128 / sUnknown_08339CC3[sBerryBlenderData->playersNo]);
            sub_80832BC(&sBerryBlenderData->bg_X, (sBerryBlenderData->field_4C / 100) - 10);
            sub_80832BC(&sBerryBlenderData->bg_Y, (sBerryBlenderData->field_4C / 100) - 10);
        }
        break;
    case 0x5432:
        if (sBerryBlenderData->field_4C < 1500)
            sBerryBlenderData->field_4C += (0x100 / sUnknown_08339CC3[sBerryBlenderData->playersNo]);
        break;
    case 0x2345:
        sBerryBlenderData->field_4C -= (0x100 / sUnknown_08339CC3[sBerryBlenderData->playersNo]);
        if (sBerryBlenderData->field_4C < 0x80)
            sBerryBlenderData->field_4C = 0x80;
        break;
    }
}

static bool32 sub_80814B0(u16 arg0, u16 arg1, u16 arg2)
{
    if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
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

static void sub_80814F4(void)
{
    s32 i;

    if (gSpecialVar_0x8004 != 0)
    {
        if (gSendCmd[2] != 0)
        {
            gRecvCmds[0][2] = gSendCmd[2];
            gRecvCmds[0][0] = 0x4444;
            gSendCmd[2] = 0;
        }
        for (i = 1; i < 4; i++)
        {
            if (gRecvCmds[i][2] != 0)
                gRecvCmds[i][0] = 0x4444;
        }
    }
    for (i = 0; i < sBerryBlenderData->playersNo; i++)
    {
        if (sub_80814B0(gRecvCmds[i][0], 0x4444, 0x4400))
        {
            u32 var = sBerryBlenderData->field_96[i];
            if (gRecvCmds[i][2] == 0x4523)
            {
                sub_8081370(0x4523);
                sBerryBlenderData->field_116 += (sBerryBlenderData->field_4C / 55);
                if (sBerryBlenderData->field_116 >= 1000)
                    sBerryBlenderData->field_116 = 1000;
                sub_8081288(0x4523, var);
                sBerryBlenderData->scores[i][BLENDER_SCORE_BEST]++;
            }
            else if (gRecvCmds[i][2] == 0x5432)
            {
                sub_8081370(0x5432);
                sBerryBlenderData->field_116 += (sBerryBlenderData->field_4C / 70);
                sub_8081288(0x5432, var);
                sBerryBlenderData->scores[i][BLENDER_SCORE_GOOD]++;
            }
            else if (gRecvCmds[i][2] == 0x2345)
            {
                sub_8081288(0x2345, var);
                sub_8081370(0x2345);
                if (sBerryBlenderData->scores[i][BLENDER_SCORE_MISS] < 999)
                    sBerryBlenderData->scores[i][BLENDER_SCORE_MISS]++;
            }
            if (gRecvCmds[i][2] == 0x2345 || gRecvCmds[2][i] == 0x4523 || gRecvCmds[2][i] == 0x5432) // could be a bug, 2 and i are reversed
            {
                if (sBerryBlenderData->field_4C > 1500)
                    m4aMPlayTempoControl(&gMPlayInfo_BGM, ((sBerryBlenderData->field_4C - 750) / 20) + 256);
                else
                    m4aMPlayTempoControl(&gMPlayInfo_BGM, 0x100);
            }
        }
    }
    if (gSpecialVar_0x8004 != 0)
    {
        for (i = 0; i < sBerryBlenderData->playersNo; i++)
        {
            gRecvCmds[i][0] = 0;
            gRecvCmds[i][2] = 0;
        }
    }
}

static void sub_8081744(void)
{
    u8 var2;
    bool8 A_pressed = FALSE;
    u8 playerId = 0;

    if (gReceivedRemoteLinkPlayers != 0)
        playerId = GetMultiplayerId();

    var2 = sBerryBlenderData->field_96[playerId];

    if (sBerryBlenderData->gameEndState == 0)
    {
        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A && gMain.newKeys & A_BUTTON)
        {
            if ((gMain.heldKeysRaw & (A_BUTTON | L_BUTTON)) != (A_BUTTON | L_BUTTON))
                A_pressed = TRUE;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            A_pressed = TRUE;
        }

        if (A_pressed)
        {
            u8 var3;
            StartSpriteAnim(&gSprites[sBerryBlenderData->syncArrowSpriteIds[sBerryBlenderData->field_8E[var2]]], var2 + 4);
            var3 = sub_8080624(sBerryBlenderData->arrowPos, playerId);

            if (var3 == 2)
                gSendCmd[2] = 0x4523;
            else if (var3 == 1)
                gSendCmd[2] = 0x5432;
            else
                gSendCmd[2] = 0x2345;
        }
    }
    if (++sBerryBlenderData->field_72 > 5)
    {
        if (sBerryBlenderData->field_4C > 128)
            sBerryBlenderData->field_4C--;
        sBerryBlenderData->field_72 = 0;
    }
    if (gEnableContestDebugging && gMain.newKeys & L_BUTTON)
        sBerryBlenderData->field_123 ^= 1;
}

static void sub_8081898(void)
{
    sub_8082D28();

    if (sBerryBlenderData->gameFrameTime < (99 * 60 * 60) + (59 * 60)) // game time can't be longer than 99 minutes and 59 seconds, can't print 3 digits
        sBerryBlenderData->gameFrameTime++;

    sub_8081744();
    SetLinkDebugValues((u16)(sBerryBlenderData->field_4C), sBerryBlenderData->field_116);
    sub_80814F4();
    sub_8083140(sBerryBlenderData->field_116, 1000);
    sub_8083230(sBerryBlenderData->field_4C);
    sub_808330C();
    sub_8082AD4();
    if (sBerryBlenderData->gameEndState == 0 && sBerryBlenderData->field_118 >= 1000)
    {
        sBerryBlenderData->field_116 = 1000;
        sBerryBlenderData->gameEndState = 1;
        SetMainCallback2(CB2_HandleBlenderEndGame);
    }

    Blender_DummiedOutFunc(sBerryBlenderData->bg_X, sBerryBlenderData->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void Blender_DummiedOutFunc(s16 a0, s16 a1)
{

}

static bool8 sub_8081964(struct BlenderBerry* berries, u8 index1, u8 index2)
{
    if (berries[index1].itemId != berries[index2].itemId
     || (StringCompare(berries[index1].name, berries[index2].name) == 0
      && (berries[index1].flavors[FLAVOR_SPICY] == berries[index2].flavors[FLAVOR_SPICY]
       && berries[index1].flavors[FLAVOR_DRY] == berries[index2].flavors[FLAVOR_DRY]
       && berries[index1].flavors[FLAVOR_SWEET] == berries[index2].flavors[FLAVOR_SWEET]
       && berries[index1].flavors[FLAVOR_BITTER] == berries[index2].flavors[FLAVOR_BITTER]
       && berries[index1].flavors[FLAVOR_SOUR] == berries[index2].flavors[FLAVOR_SOUR]
       && berries[index1].smoothness == berries[index2].smoothness)))
        return TRUE;
    else
        return FALSE;
}

static u32 Blender_GetPokeblockColor(struct BlenderBerry* berries, s16* a1, u8 playersNo, u8 a3)
{
    s16 vars[6];
    s32 i;
    s32 r6;
    u8 r2;

    for (i = 0; i < 6; i++)
        vars[i] = a1[i];

    r6 = 0;
    for (i = 0; i < 5; i++)
    {
        if (vars[i] == 0)
            r6++;
    }
    if (r6 == 5 || a3 > 3)
        return 12;
    for (i = 0; i < playersNo; i++)
    {
        for (r6 = 0; r6 < playersNo; r6++)
        {
            if (berries[i].itemId == berries[r6].itemId && i != r6
                && (berries[i].itemId != ITEM_ENIGMA_BERRY || sub_8081964(berries, i, r6)))
                    return 12;
        }
    }
    r2 = 0;
    for (r2 = 0, i = 0; i < 5; i++)
    {
        if (vars[i] > 0)
            r2++;
    }
    if (r2 > 3)
        return 13;
    if (r2 == 3)
        return 11;
    for (i = 0; i < 5; i++)
    {
        if (vars[i] > 50)
            return 14;
    }
    if (r2 == 1 && vars[0] > 0)
        return 1;
    if (r2 == 1 && vars[1] > 0)
        return 2;
    if (r2 == 1 && vars[2] > 0)
        return 3;
    if (r2 == 1 && vars[3] > 0)
        return 4;
    if (r2 == 1 && vars[4] > 0)
        return 5;
    if (r2 == 2)
    {
        s32 var = 0;
        for (i = 0; i < 5; i++)
        {
            if (vars[i] > 0)
                sUnknown_03000DF8[var++] = i;
        }
        if (vars[sUnknown_03000DF8[0]] >= vars[sUnknown_03000DF8[1]])
        {
            if (sUnknown_03000DF8[0] == 0)
                return (sUnknown_03000DF8[1] << 16) | 6;
            if (sUnknown_03000DF8[0] == 1)
                return (sUnknown_03000DF8[1] << 16) | 7;
            if (sUnknown_03000DF8[0] == 2)
                return (sUnknown_03000DF8[1] << 16) | 8;
            if (sUnknown_03000DF8[0] == 3)
                return (sUnknown_03000DF8[1] << 16) | 9;
            if (sUnknown_03000DF8[0] == 4)
                return (sUnknown_03000DF8[1] << 16) | 10;
        }
        else
        {
            if (sUnknown_03000DF8[1] == 0)
                return (sUnknown_03000DF8[0] << 16) | 6;
            if (sUnknown_03000DF8[1] == 1)
                return (sUnknown_03000DF8[0] << 16) | 7;
            if (sUnknown_03000DF8[1] == 2)
                return (sUnknown_03000DF8[0] << 16) | 8;
            if (sUnknown_03000DF8[1] == 3)
                return (sUnknown_03000DF8[0] << 16) | 9;
            if (sUnknown_03000DF8[1] == 4)
                return (sUnknown_03000DF8[0] << 16) | 10;
        }
    }
    return 0;
}

static void sub_8081BB0(s16 value)
{
    sUnknown_03000E04 = value;
}

static s16 sub_8081BBC(void)
{
    return sUnknown_03000E04;
}

static void sub_8081BC8(s16 value)
{
    sUnknown_03000E06 = value;
}

static s16 sub_8081BD4(void)
{
    return sUnknown_03000E06;
}

static void Blender_CalculatePokeblock(struct BlenderBerry *berries, struct Pokeblock *pokeblock, u8 playersNo, u8 *flavors, u16 maxRPM)
{
    s32 i, j;
    s32 multiuseVar, var2;
    u8 var3;

    for (i = 0; i < 6; i++)
        sUnknown_03000DE8[i] = 0;

    for (i = 0; i < playersNo; i++)
    {
        for (j = 0; j < 6; j++)
            sUnknown_03000DE8[j] += berries[i].flavors[j];
    }

    multiuseVar = sUnknown_03000DE8[0];
    sUnknown_03000DE8[0] -= sUnknown_03000DE8[1];
    sUnknown_03000DE8[1] -= sUnknown_03000DE8[2];
    sUnknown_03000DE8[2] -= sUnknown_03000DE8[3];
    sUnknown_03000DE8[3] -= sUnknown_03000DE8[4];
    sUnknown_03000DE8[4] -= multiuseVar;

    multiuseVar = 0;
    for (i = 0; i < 5; i++)
    {
        if (sUnknown_03000DE8[i] < 0)
        {
            sUnknown_03000DE8[i] = 0;
            multiuseVar++;
        }
    }
    var3 = multiuseVar;
    for (i = 0; i < 5; i++)
    {
        if (sUnknown_03000DE8[i] > 0)
        {
            if (sUnknown_03000DE8[i] < multiuseVar)
                sUnknown_03000DE8[i] = 0;
            else
                sUnknown_03000DE8[i] -= multiuseVar;
        }
    }
    for (i = 0; i < 5; i++)
    {
        sUnknown_020322A8[i] = sUnknown_03000DE8[i];
    }

    multiuseVar = maxRPM / 333 + 100;
    sUnknown_020322D0 = multiuseVar;

    for (i = 0; i < 5; i++)
    {
        s32 r4;
        s32 r5 = sUnknown_03000DE8[i];
        r5 = (r5 * multiuseVar) / 10;
        r4 = r5 % 10;
        r5 /= 10;
        if (r4 > 4)
            r5++;
        sUnknown_03000DE8[i] = r5;
    }
    for (i = 0; i < 5; i++)
    {
        sUnknown_020322BC[i] = sUnknown_03000DE8[i];
    }

    pokeblock->color = Blender_GetPokeblockColor(berries, &sUnknown_03000DE8[0], playersNo, var3);
    sUnknown_03000DE8[5] = (sUnknown_03000DE8[5] / playersNo) - playersNo;

    if (sUnknown_03000DE8[5] < 0)
        sUnknown_03000DE8[5] = 0;

    if (pokeblock->color == 12)
    {
        multiuseVar = Random() % 10;
        for (i = 0; i < 5; i++)
        {
            if ((sUnknown_08339CC8[multiuseVar] >> i) & 1)
                sUnknown_03000DE8[i] = 2;
            else
                sUnknown_03000DE8[i] = 0;
        }
    }

    for (i = 0; i < 6; i++)
    {
        if (sUnknown_03000DE8[i] > 255)
            sUnknown_03000DE8[i] = 255;
    }

    pokeblock->spicy = sUnknown_03000DE8[0];
    pokeblock->dry = sUnknown_03000DE8[1];
    pokeblock->sweet = sUnknown_03000DE8[2];
    pokeblock->bitter = sUnknown_03000DE8[3];
    pokeblock->sour = sUnknown_03000DE8[4];
    pokeblock->feel = sUnknown_03000DE8[5];

    for (i = 0; i < 6; i++)
    {
        flavors[i] = sUnknown_03000DE8[i];
    }
}

static void BlenderDebug_CalculatePokeblock(struct BlenderBerry* berries, struct Pokeblock* pokeblock, u8 playersNo, u8* flavors, u16 a4)
{
    Blender_CalculatePokeblock(berries, pokeblock, playersNo, flavors, a4);
}

static void sub_8081E20(void)
{
    u32 frames = (u16)(sBerryBlenderData->gameFrameTime);
    u16 max_RPM = sBerryBlenderData->max_RPM;
    s16 var = 0;

    if (frames < 900)
        var = 5;
    else if ((u16)(frames - 900) < 600)
        var = 4;
    else if ((u16)(frames - 1500) < 600)
        var = 3;
    else if ((u16)(frames - 2100) < 900)
        var = 2;
    else if ((u16)(frames - 3300) < 300)
        var = 1;

    sub_8081BC8(var);

    var = 0;
    if (max_RPM <= 64)
    {
        if (max_RPM >= 50 && max_RPM < 100)
            var = -1;
        else if (max_RPM >= 100 && max_RPM < 150)
            var = -2;
        else if (max_RPM >= 150 && max_RPM < 200)
            var = -3;
        else if (max_RPM >= 200 && max_RPM < 250)
            var = -4;
        else if (max_RPM >= 250 && max_RPM < 300)
            var = -5;
        else if (max_RPM >= 350 && max_RPM < 400)
            var = -6;
        else if (max_RPM >= 400 && max_RPM < 450)
            var = -7;
        else if (max_RPM >= 500 && max_RPM < 550)
            var = -8;
        else if (max_RPM >= 550 && max_RPM < 600)
            var = -9;
        else if (max_RPM >= 600)
            var = -10;
    }

    sub_8081BB0(var);
}

static void sub_8081F94(u16 *a0)
{
    if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
        *a0 = 0x2F00;
    else
        *a0 = 0x2FFF;
}

static void CB2_HandleBlenderEndGame(void)
{
    u8 i, j;

    if (sBerryBlenderData->gameEndState < 3)
        sub_8082D28();

    GetMultiplayerId(); // unused return value

    switch (sBerryBlenderData->gameEndState)
    {
    case 1:
        m4aMPlayTempoControl(&gMPlayInfo_BGM, 256);
        for (i = 0; i < gSpecialVar_0x8004; i++)
        {
            DestroyTask(sBerryBlenderData->field_120[i]);
        }
        sBerryBlenderData->gameEndState++;
        break;
    case 2:
        sBerryBlenderData->field_4C -= 32;
        if (sBerryBlenderData->field_4C <= 0)
        {
            ClearLinkCallback();
            sBerryBlenderData->field_4C = 0;

            if (gReceivedRemoteLinkPlayers != 0)
                sBerryBlenderData->gameEndState++;
            else
                sBerryBlenderData->gameEndState = 5;

            sBerryBlenderData->mainState = 0;
            m4aMPlayStop(&gMPlayInfo_SE2);
        }
        Blender_ControlHitPitch();
        break;
    case 3:
        if (GetMultiplayerId() != 0)
        {
            sBerryBlenderData->gameEndState++;
        }
        else if (IsLinkTaskFinished())
        {
            if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
            {
                sBerryBlenderData->gameBlock.timeRPM.time = sBerryBlenderData->gameFrameTime;
                sBerryBlenderData->gameBlock.timeRPM.max_RPM = sBerryBlenderData->max_RPM;

                for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
                {
                    for (j = 0; j < BLENDER_SCORES_NO; j++)
                        sBerryBlenderData->gameBlock.scores[i][j] = sBerryBlenderData->scores[i][j];
                }

                if (SendBlock(0, &sBerryBlenderData->gameBlock, sizeof(sBerryBlenderData->gameBlock)))
                    sBerryBlenderData->gameEndState++;
            }
            else
            {
                sBerryBlenderData->smallBlock.time = sBerryBlenderData->gameFrameTime;
                sBerryBlenderData->smallBlock.max_RPM = sBerryBlenderData->max_RPM;
                if (SendBlock(0, &sBerryBlenderData->smallBlock, sizeof(sBerryBlenderData->smallBlock) + 32))
                    sBerryBlenderData->gameEndState++;
            }
        }
        break;
    case 4:
        if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            sBerryBlenderData->gameEndState++;

            if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
            {
                struct BlenderGameBlock *receivedBlock = (struct BlenderGameBlock*)(&gBlockRecvBuffer);

                sBerryBlenderData->max_RPM = receivedBlock->timeRPM.max_RPM;
                sBerryBlenderData->gameFrameTime = receivedBlock->timeRPM.time;

                for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
                {
                    for (j = 0; j < BLENDER_SCORES_NO; j++)
                        sBerryBlenderData->scores[i][j] = receivedBlock->scores[i][j];
                }
            }
            else
            {
                struct TimeAndRPM *receivedBlock = (struct TimeAndRPM*)(&gBlockRecvBuffer);

                sBerryBlenderData->max_RPM = receivedBlock->max_RPM;
                sBerryBlenderData->gameFrameTime = receivedBlock->time;
            }
        }
        break;
    case 5:
        if (Blender_PrintBlendingRanking())
            sBerryBlenderData->gameEndState++;
        break;
    case 6:
        if (Blender_PrintBlendingResults())
        {
            if (gInGameOpponentsNo == 0)
                IncrementGameStat(GAME_STAT_POKEBLOCKS_WITH_FRIENDS);
            else
                IncrementGameStat(GAME_STAT_POKEBLOCKS);

            sBerryBlenderData->gameEndState++;
        }
        break;
    case 7:
        if (Blender_PrintText(&sBerryBlenderData->textState, sText_WouldLikeToBlendAnotherBerry, GetPlayerTextSpeedDelay()))
            sBerryBlenderData->gameEndState++;
        break;
    case 9:
        sBerryBlenderData->yesNoAnswer = 0;
        CreateYesNoMenu(&sBlender_YesNoWindowTemplate, 1, 0xD, 0);
        sBerryBlenderData->gameEndState++;
        break;
    case 10:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 1:
        case -1:
            sBerryBlenderData->yesNoAnswer = 1;
            sBerryBlenderData->gameEndState++;
            for (i = 0; i <BLENDER_MAX_PLAYERS; i++)
            {
                if (sBerryBlenderData->field_8E[i] != 0xFF)
                {
                    PutWindowTilemap(i);
                    CopyWindowToVram(i, 3);
                }
            }
            break;
        case 0:
            sBerryBlenderData->yesNoAnswer = 0;
            sBerryBlenderData->gameEndState++;
            for (i = 0; i <BLENDER_MAX_PLAYERS; i++)
            {
                if (sBerryBlenderData->field_8E[i] != 0xFF)
                {
                    PutWindowTilemap(i);
                    CopyWindowToVram(i, 3);
                }
            }
            break;
        }
        break;
    case 11:
        sub_8081F94(&gSendCmd[0]);
        if (sBerryBlenderData->yesNoAnswer == 0)
        {
            if (IsBagPocketNonEmpty(POCKET_BERRIES) == FALSE) // no berries
            {
                sBerryBlenderData->playAgainState = CANT_PLAY_NO_BERRIES;
                gSendCmd[1] = 0x9999;
            }
            else if (GetFirstFreePokeblockSlot() == -1) // no space for pokeblocks
            {
                sBerryBlenderData->playAgainState = CANT_PLAY_NO_PKBLCK_SPACE;
                gSendCmd[1] = 0xAAAA;
            }
            else
            {
                sBerryBlenderData->playAgainState = PLAY_AGAIN_OK;
                gSendCmd[1] = 0x7779;
            }
            sBerryBlenderData->gameEndState++;
        }
        else
        {
            sBerryBlenderData->playAgainState = DONT_PLAY_AGAIN;
            gSendCmd[1] = 0x8888;
            sBerryBlenderData->gameEndState++;
        }
        break;
    case 12:
        if (gInGameOpponentsNo)
        {
            SetMainCallback2(CB2_HandlePlayerPlayAgainChoice);
            sBerryBlenderData->gameEndState = 0;
            sBerryBlenderData->mainState = 0;
        }
        else
        {
            sBerryBlenderData->gameEndState++;
        }
        break;
    case 8:
        sBerryBlenderData->gameEndState++;
        break;
    case 13:
        if (Blender_PrintText(&sBerryBlenderData->textState, sText_CommunicationStandby, GetPlayerTextSpeedDelay()))
        {
            SetMainCallback2(CB2_HandlePlayerLinkPlayAgainChoice);
            sBerryBlenderData->gameEndState = 0;
            sBerryBlenderData->mainState = 0;
        }
        break;
    }

    sub_808330C();
    sub_8083230(sBerryBlenderData->field_4C);
    sub_8082AD4();
    Blender_DummiedOutFunc(sBerryBlenderData->bg_X, sBerryBlenderData->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static bool8 LinkPlayAgainHandleSaving(void)
{
    switch (sBerryBlenderData->field_1A0)
    {
    case 0:
        sub_800ADF8();
        sBerryBlenderData->field_1A0 = 1;
        sBerryBlenderData->framesToWait = 0;
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            sBerryBlenderData->field_1A0++;
            gSoftResetDisabled = TRUE;
        }
        break;
    case 2:
        FullSaveGame();
        sBerryBlenderData->field_1A0++;
        sBerryBlenderData->framesToWait = 0;
        break;
    case 3:
        if (++sBerryBlenderData->framesToWait == 10)
        {
            sub_800ADF8();
            sBerryBlenderData->field_1A0++;
        }
        break;
    case 4:
        if (IsLinkTaskFinished())
        {
            if (CheckSaveFile())
            {
                sBerryBlenderData->field_1A0 = 5;
            }
            else
            {
                sBerryBlenderData->framesToWait = 0;
                sBerryBlenderData->field_1A0 = 3;
            }
        }
        break;
    case 5:
        sBerryBlenderData->field_1A0++;
        sBerryBlenderData->framesToWait = 0;
        break;
    case 6:
        if (++sBerryBlenderData->framesToWait > 5)
        {
            gSoftResetDisabled = FALSE;
            return TRUE;
        }
        break;
    }

    return FALSE;
}

static void CB2_HandlePlayerLinkPlayAgainChoice(void)
{
    switch (sBerryBlenderData->gameEndState)
    {
    case 0:
        if (sBerryBlenderData->field_64[0] == 0x2222)
        {
            sBerryBlenderData->gameEndState = 5;
        }
        else if (sBerryBlenderData->field_64[0] == 0x1111)
        {
            if (sBerryBlenderData->field_6C == 0x9999)
                sBerryBlenderData->gameEndState = 2;
            else if (sBerryBlenderData->field_6C == 0xAAAA)
                sBerryBlenderData->gameEndState = 1;
            else
                sBerryBlenderData->gameEndState = 5;
        }
        break;
    case 1:
        sBerryBlenderData->gameEndState = 3;
        StringCopy(gStringVar4, gLinkPlayers[sBerryBlenderData->field_6E].name);
        StringAppend(gStringVar4, sText_ApostropheSPokeblockCaseIsFull);
        break;
    case 2:
        sBerryBlenderData->gameEndState++;
        StringCopy(gStringVar4, gLinkPlayers[sBerryBlenderData->field_6E].name);
        StringAppend(gStringVar4, sText_HasNoBerriesToPut);
        break;
    case 3:
        if (Blender_PrintText(&sBerryBlenderData->textState, gStringVar4, GetPlayerTextSpeedDelay()))
        {
            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->gameEndState++;
        }
        break;
    case 4:
        if (++sBerryBlenderData->framesToWait > 60)
            sBerryBlenderData->gameEndState = 5;
        break;
    case 5:
        Blender_PrintText(&sBerryBlenderData->textState, gText_SavingDontTurnOff2, 0);
        sub_800ADF8();
        sBerryBlenderData->gameEndState++;
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->gameEndState++;
            sBerryBlenderData->field_1A0 = 0;
        }
        break;
    case 7:
        if (LinkPlayAgainHandleSaving())
        {
            PlaySE(SE_SAVE);
            sBerryBlenderData->gameEndState++;
        }
        break;
    case 8:
        sBerryBlenderData->gameEndState++;
        sub_800ADF8();
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            sBerryBlenderData->gameEndState++;
        }
        break;
    case 10:
        if (!gPaletteFade.active)
        {
            if (sBerryBlenderData->field_64[0] == 0x2222)
            {
                FreeAllWindowBuffers();
                UnsetBgTilemapBuffer(2);
                UnsetBgTilemapBuffer(1);
                FREE_AND_SET_NULL(sBerryBlenderData);
                SetMainCallback2(DoBerryBlending);
            }
            else
            {
                sBerryBlenderData->framesToWait = 0;
                sBerryBlenderData->gameEndState++;
            }
        }
        break;
    case 11:
        if (++sBerryBlenderData->framesToWait > 30)
        {
            sub_800AC34();
            sBerryBlenderData->gameEndState++;
        }
        break;
    case 12:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            FREE_AND_SET_NULL(sBerryBlenderData);
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        }
        break;
    }

    sub_8082AD4();
    Blender_DummiedOutFunc(sBerryBlenderData->bg_X, sBerryBlenderData->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void CB2_HandlePlayerPlayAgainChoice(void)
{
    switch (sBerryBlenderData->gameEndState)
    {
    case 0:
        if (sBerryBlenderData->playAgainState == PLAY_AGAIN_OK || sBerryBlenderData->playAgainState == DONT_PLAY_AGAIN)
            sBerryBlenderData->gameEndState = 9;
        if (sBerryBlenderData->playAgainState == CANT_PLAY_NO_BERRIES)
            sBerryBlenderData->gameEndState = 2;
        if (sBerryBlenderData->playAgainState == CANT_PLAY_NO_PKBLCK_SPACE)
            sBerryBlenderData->gameEndState = 1;
        break;
    case 1:
        sBerryBlenderData->gameEndState = 3;
        sBerryBlenderData->textState = 0;
        StringCopy(gStringVar4, sText_YourPokeblockCaseIsFull);
        break;
    case 2:
        sBerryBlenderData->gameEndState++;
        sBerryBlenderData->textState = 0;
        StringCopy(gStringVar4, sText_RunOutOfBerriesForBlending);
        break;
    case 3:
        if (Blender_PrintText(&sBerryBlenderData->textState, gStringVar4, GetPlayerTextSpeedDelay()))
            sBerryBlenderData->gameEndState = 9;
        break;
    case 9:
        BeginFastPaletteFade(3);
        sBerryBlenderData->gameEndState++;
        break;
    case 10:
        if (!gPaletteFade.active)
        {
            if (sBerryBlenderData->playAgainState == PLAY_AGAIN_OK)
                SetMainCallback2(DoBerryBlending);
            else
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);

            FreeAllWindowBuffers();
            UnsetBgTilemapBuffer(2);
            UnsetBgTilemapBuffer(1);
            FREE_AND_SET_NULL(sBerryBlenderData);
        }
        break;
    }

    sub_8082AD4();
    Blender_DummiedOutFunc(sBerryBlenderData->bg_X, sBerryBlenderData->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void sub_8082AD4(void)
{
    if (gReceivedRemoteLinkPlayers)
    {
        if (sub_80814B0(gRecvCmds[0][0], 0x2FFF, 0x2F00))
        {
            if (gRecvCmds[0][1] == 0x1111)
            {
                switch (gRecvCmds[0][2])
                {
                case 0x8888:
                    sBerryBlenderData->field_6C = 0x8888;
                    sBerryBlenderData->field_6E = gRecvCmds[0][3];
                    break;
                case 0x9999:
                    sBerryBlenderData->field_6C = 0x9999;
                    sBerryBlenderData->field_6E = gRecvCmds[0][3];
                    break;
                case 0xAAAA:
                    sBerryBlenderData->field_6C = 0xAAAA;
                    sBerryBlenderData->field_6E = gRecvCmds[0][3];
                    break;
                }

                sBerryBlenderData->field_64[0] = 0x1111;
            }
            else if (gRecvCmds[0][1] == 0x2222)
            {
                sBerryBlenderData->field_64[0] = 0x2222;
            }
        }
        if (GetMultiplayerId() == 0 && sBerryBlenderData->field_64[0] != 0x1111 && sBerryBlenderData->field_64[0] != 0x2222)
        {
            u8 i;
            for (i = 0; i < GetLinkPlayerCount(); i++)
            {
                if (sub_80814B0(gRecvCmds[i][0], 0x2FFF, 0x2F00))
                {
                    switch (gRecvCmds[i][1])
                    {
                    case 0x8888:
                        sBerryBlenderData->field_64[i] = 0x8888;
                        break;
                    case 0x7779:
                        sBerryBlenderData->field_64[i] = 0x7779;
                        break;
                    case 0x9999:
                        sBerryBlenderData->field_64[i] = 0x9999;
                        break;
                    case 0xAAAA:
                        sBerryBlenderData->field_64[i] = 0xAAAA;
                        break;
                    }
                }
            }
            for (i = 0; i < GetLinkPlayerCount(); i++)
            {
                if (sBerryBlenderData->field_64[i] == 0)
                    break;
            }
            if (i == GetLinkPlayerCount())
            {
                for (i = 0; i < GetLinkPlayerCount(); i++)
                {
                    if (sBerryBlenderData->field_64[i] != 0x7779)
                        break;
                }
                sub_8081F94(&gSendCmd[0]);
                if (i == GetLinkPlayerCount())
                {
                    gSendCmd[1] = 0x2222;
                }
                else
                {
                    gSendCmd[1] = 0x1111;
                    gSendCmd[2] = sBerryBlenderData->field_64[i];
                    gSendCmd[3] = i;
                }
            }
        }
    }
}

static void sub_8082CB4(struct BgAffineSrcData *dest)
{
    struct BgAffineSrcData affineSrc;

    affineSrc.texX = 0x7800;
    affineSrc.texY = 0x5000;
    affineSrc.scrX = 0x78 - sBerryBlenderData->bg_X;
    affineSrc.scrY = 0x50 - sBerryBlenderData->bg_Y;
    affineSrc.sx = sBerryBlenderData->field_11A;
    affineSrc.sy = sBerryBlenderData->field_11A;
    affineSrc.alpha = sBerryBlenderData->arrowPos;

    *dest = affineSrc;
}

u16 GetBlenderArrowPosition(void)
{
    return sBerryBlenderData->arrowPos;
}

static void sub_8082D28(void)
{
    u8 playerId = 0;

    if (gReceivedRemoteLinkPlayers != 0)
        playerId = GetMultiplayerId();

    if (gWirelessCommType && gReceivedRemoteLinkPlayers != 0)
    {
        if (playerId == 0)
        {
            sBerryBlenderData->arrowPos += sBerryBlenderData->field_4C;
            gSendCmd[5] = sBerryBlenderData->field_116;
            gSendCmd[6] = sBerryBlenderData->arrowPos;
            sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
        }
        else
        {
            if ((gRecvCmds[0][0] & 0xFF00) == 0x4400)
            {
                sBerryBlenderData->field_116 = gRecvCmds[0][5];
                sBerryBlenderData->arrowPos = gRecvCmds[0][6];
                sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
            }
        }
    }
    else
    {
        sBerryBlenderData->arrowPos += sBerryBlenderData->field_4C;
        sub_8082CB4(&sBerryBlenderData->bgAffineSrc);
    }
}

static void BerryBlender_SetBackgroundsPos(void)
{
    SetGpuReg(REG_OFFSET_BG1HOFS, sBerryBlenderData->bg_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, sBerryBlenderData->bg_Y);

    SetGpuReg(REG_OFFSET_BG0HOFS, sBerryBlenderData->bg_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, sBerryBlenderData->bg_Y);
}

static void sub_8082E3C(struct Sprite* sprite)
{
    sprite->data[2] += sprite->data[0];
    sprite->data[3] += sprite->data[1];
    sprite->pos2.x = sprite->data[2] / 8;
    sprite->pos2.y = sprite->data[3] / 8;

    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void sub_8082E84(void)
{
    s32 limit = (Random() % 2) + 1;
    s32 i;

    for (i = 0; i < limit; i++)
    {
        u16 rand;
        s32 x, y;
        u8 spriteId;

        rand = sBerryBlenderData->arrowPos + (Random() % 20);

        x = gSineTable[(rand & 0xFF) + 64] / 4;
        y = gSineTable[(rand & 0xFF)] / 4;

        spriteId = CreateSprite(&sUnknown_08339BE0, x + 120, y + 80, 1);
        gSprites[spriteId].data[0] = 16 - (Random() % 32);
        gSprites[spriteId].data[1] = 16 - (Random() % 32);

        gSprites[spriteId].callback = sub_8082E3C;
    }
}

static void sub_8082F68(struct Sprite* sprite)
{
    sprite->data[0]++;
    sprite->pos2.y = -(sprite->data[0] / 3);

    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void sub_8082F9C(struct Sprite* sprite)
{
    sprite->data[0]++;
    sprite->pos2.y = -(sprite->data[0] * 2);

    if (sprite->pos2.y < -12)
        sprite->pos2.y = -12;
    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void Blender_SetParticipantBerryData(u8 participantId, u16 itemId)
{
    sBerryBlenderData->chosenItemId[participantId] = itemId;
    Blender_CopyBerryData(&sBerryBlenderData->blendedBerries[participantId], itemId);
}

static void sub_8083010(struct Sprite* sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] += 8;
        if (sprite->data[1] > 88)
        {
            sprite->data[1] = 88;
            sprite->data[0]++;
            PlaySE(SE_KON);
        }
        break;
    case 1:
        sprite->data[2] += 1;
        if (sprite->data[2] > 20)
        {
            sprite->data[0]++;
            sprite->data[2] = 0;
        }
        break;
    case 2:
        sprite->data[1] += 4;
        if (sprite->data[1] > 176)
        {
            if (++sprite->data[3] == 3)
            {
                DestroySprite(sprite);
                CreateSprite(&sUnknown_08339C60, 120, -20, 2);
            }
            else
            {
                sprite->data[0] = 0;
                sprite->data[1] = -16;
                StartSpriteAnim(sprite, sprite->data[3]);
            }
        }
        break;
    }

    sprite->pos2.y = sprite->data[1];
}

static void sub_80830C0(struct Sprite* sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] += 8;
        if (sprite->data[1] > 92)
        {
            sprite->data[1] = 92;
            sprite->data[0]++;
            PlaySE(SE_PIN);
        }
        break;
    case 1:
        sprite->data[2] += 1;
        if (sprite->data[2] > 20)
            sprite->data[0]++;
        break;
    case 2:
        sprite->data[1] += 4;
        if (sprite->data[1] > 176)
        {
            sBerryBlenderData->mainState++;
            DestroySprite(sprite);
        }
        break;
    }

    sprite->pos2.y = sprite->data[1];
}

static void sub_8083140(u16 a0, u16 a1)
{
    if (sBerryBlenderData->field_118 < a0)
    {
        sBerryBlenderData->field_118 += 2;
        sub_8083170(sBerryBlenderData->field_118, a1);
    }
}

static void sub_8083170(u16 a0, u16 a1)
{
    s32 var1, var2, var3, var4;
    u16 *vram;

    vram = (u16*)(BG_SCREEN_ADDR(12));
    var1 = (a0 * 64) / a1;
    var2 = var1 / 8;
    for (var4 = 0; var4 < var2; var4++)
    {
        vram[11 + var4] = 0x80E9;
        vram[43 + var4] = 0x80F9;
    }
    var3 = var1 % 8;
    if (var3 != 0)
    {
        vram[11 + var4] = var3 + 0x80E1;
        vram[43 + var4] = var3 + 0x80F1;
        var4++;
    }
    for (; var4 < 8; var4++)
    {
        vram[11 + var4] = 0x80E1;
        vram[43 + var4] = 0x80F1;
    }
}

static u32 sub_8083210(u16 a0)
{
    return 0x57E40 * a0 / 0x10000;
}

static void sub_8083230(u16 a0)
{
    u8 i;
    u8 palAdders[5];

    u32 var = sub_8083210(a0);
    if (sBerryBlenderData->max_RPM < var)
        sBerryBlenderData->max_RPM = var;
    for (i = 0; i < 5; i++)
    {
        palAdders[i] = var % 10;
        var /= 10;
    }
    *((u16*)(VRAM + 0x6458)) = palAdders[4] + 0x8072;
    *((u16*)(VRAM + 0x645A)) = palAdders[3] + 0x8072;
    *((u16*)(VRAM + 0x645C)) = palAdders[2] + 0x8072;
    *((u16*)(VRAM + 0x6460)) = palAdders[1] + 0x8072;
    *((u16*)(VRAM + 0x6462)) = palAdders[0] + 0x8072;
}

static void sub_80832BC(s16* a0, u16 a1)
{
    if (*a0 == 0)
        *a0 = (Random() % a1) - (a1 / 2);
}

static void sub_80832E8(s16* a0)
{
    if (*a0 < 0)
        (*a0)++;
    if (*a0 > 0)
        (*a0)--;
}

static void sub_808330C(void)
{
    sub_80832E8(&sBerryBlenderData->bg_X);
    sub_80832E8(&sBerryBlenderData->bg_Y);
}

static void sub_8083334(s16* a0, u16 a1)
{
    s32 var;

    if (a1 < 10)
        var = 16;
    else
        var = 8;

    if (*a0 == 0)
    {
        *a0 = (Random() % var) - (var / 2);
    }
    else
    {
        if (*a0 < 0)
            (*a0)++;
        if (*a0 > 0)
            (*a0)--;
    }
}

static bool8 sub_8083380(void)
{
    if (sBerryBlenderData->framesToWait == 0)
    {
        sBerryBlenderData->bg_X = 0;
        sBerryBlenderData->bg_Y = 0;
    }

    sBerryBlenderData->framesToWait++;
    sub_8083334(&sBerryBlenderData->bg_X, sBerryBlenderData->framesToWait);
    sub_8083334(&sBerryBlenderData->bg_Y, sBerryBlenderData->framesToWait);

    if (sBerryBlenderData->framesToWait == 20)
    {
        sBerryBlenderData->bg_X = 0;
        sBerryBlenderData->bg_Y = 0;
        return TRUE;
    }

    return FALSE;
}

static void sub_80833F8(struct Sprite* sprite)
{
   sprite->pos2.x = -(sBerryBlenderData->bg_X);
   sprite->pos2.y = -(sBerryBlenderData->bg_Y);
}

static void TryUpdateBerryBlenderRecord(void)
{
    if (gSaveBlock1Ptr->berryBlenderRecords[sBerryBlenderData->playersNo - 2] < sBerryBlenderData->max_RPM)
        gSaveBlock1Ptr->berryBlenderRecords[sBerryBlenderData->playersNo - 2] = sBerryBlenderData->max_RPM;
}

static bool8 Blender_PrintBlendingResults(void)
{
    u16 i;
    s32 xPos, yPos;

    struct Pokeblock pokeblock;
    u8 flavors[6];
    u8 text[40];
    u16 berryIds[4]; // unused

    switch (sBerryBlenderData->mainState)
    {
    case 0:
        sBerryBlenderData->mainState++;
        sBerryBlenderData->framesToWait = 17;
        break;
    case 1:
        sBerryBlenderData->framesToWait -= 10;
        if (sBerryBlenderData->framesToWait < 0)
        {
            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->mainState++;
        }
        break;
    case 2:
        if (++sBerryBlenderData->framesToWait > 20)
        {
            for (i = 0; i < BLENDER_SCORES_NO; i++)
                DestroySprite(&gSprites[sBerryBlenderData->scoreIconIds[i]]);

            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->mainState++;
        }
        break;
    case 3:
        {
            u16 minutes, seconds;
            u8 *txtPtr;

            xPos = GetStringCenterAlignXOffset(1, sText_BlendingResults, 0xA8);
            Blender_AddTextPrinter(5, sText_BlendingResults, xPos, 1, TEXT_SPEED_FF, 0);

            if (sBerryBlenderData->playersNo == 4)
                yPos = 17;
            else
                yPos = 21;

            for (i = 0; i < sBerryBlenderData->playersNo; yPos += 16, i++)
            {
                u8 place = sBerryBlenderData->playerPlaces[i];

                ConvertIntToDecimalStringN(sBerryBlenderData->stringVar, i + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                StringAppend(sBerryBlenderData->stringVar, sText_Dot);
                StringAppend(sBerryBlenderData->stringVar, gText_Space);
                StringAppend(sBerryBlenderData->stringVar, gLinkPlayers[place].name);
                Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, 8, yPos, TEXT_SPEED_FF, 3);

                StringCopy(sBerryBlenderData->stringVar, sBerryBlenderData->blendedBerries[place].name);
                ConvertInternationalString(sBerryBlenderData->stringVar, gLinkPlayers[place].language);
                StringAppend(sBerryBlenderData->stringVar, sText_SpaceBerry);
                Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, 0x54, yPos, TEXT_SPEED_FF, 3);
            }

            Blender_AddTextPrinter(5, sText_MaximumSpeed, 0, 0x51, TEXT_SPEED_FF, 3);
            ConvertIntToDecimalStringN(sBerryBlenderData->stringVar, sBerryBlenderData->max_RPM / 100, STR_CONV_MODE_RIGHT_ALIGN, 3);
            StringAppend(sBerryBlenderData->stringVar, sText_Dot);

            ConvertIntToDecimalStringN(text, sBerryBlenderData->max_RPM % 100, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringAppend(sBerryBlenderData->stringVar, text);
            StringAppend(sBerryBlenderData->stringVar, sText_RPM);

            xPos = GetStringRightAlignXOffset(1, sBerryBlenderData->stringVar, 0xA8);
            Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, xPos, 0x51, TEXT_SPEED_FF, 3);
            Blender_AddTextPrinter(5, sText_Time, 0, 0x61, TEXT_SPEED_FF, 3);

            seconds = (sBerryBlenderData->gameFrameTime / 60) % 60;
            minutes = (sBerryBlenderData->gameFrameTime / (60 * 60));

            ConvertIntToDecimalStringN(sBerryBlenderData->stringVar, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
            txtPtr = StringAppend(sBerryBlenderData->stringVar, sText_Min);

            ConvertIntToDecimalStringN(txtPtr, seconds, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringAppend(sBerryBlenderData->stringVar, sText_Sec);

            xPos = GetStringRightAlignXOffset(1, sBerryBlenderData->stringVar, 0xA8);
            Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, xPos, 0x61, TEXT_SPEED_FF, 3);

            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->mainState++;

            CopyWindowToVram(5, 2);
        }
        break;
    case 4:
        if (gMain.newKeys & A_BUTTON)
            sBerryBlenderData->mainState++;
        break;
    case 5:
        ClearStdWindowAndFrameToTransparent(5, 1);

        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            if (sBerryBlenderData->chosenItemId[i] != 0)
                berryIds[i] = sBerryBlenderData->chosenItemId[i] - FIRST_BERRY_INDEX;
            if (sBerryBlenderData->field_8E[i] != 0xFF)
            {
                PutWindowTilemap(i);
                CopyWindowToVram(i, 3);
            }
        }

        sub_8081E20();

        Blender_CalculatePokeblock(sBerryBlenderData->blendedBerries, &pokeblock, sBerryBlenderData->playersNo, flavors, sBerryBlenderData->max_RPM);
        Blender_PrintMadePokeblockString(&pokeblock, sBerryBlenderData->stringVar);
        TryAddContestLinkTvShow(&pokeblock, &sBerryBlenderData->tvBlender);

        CreateTask(sub_8083F3C, 6);
        IncrementDailyBerryBlender();

        RemoveBagItem(gSpecialVar_ItemId, 1);
        AddPokeblock(&pokeblock);

        sBerryBlenderData->textState = 0;
        sBerryBlenderData->mainState++;
        break;
    case 6:
        if (Blender_PrintText(&sBerryBlenderData->textState, sBerryBlenderData->stringVar, GetPlayerTextSpeedDelay()))
        {
            TryUpdateBerryBlenderRecord();
            return TRUE;
        }
        break;
    }

    return FALSE;
}

static void Blender_PrintMadePokeblockString(struct Pokeblock *pokeblock, u8 *dst)
{
    u8 text[12];
    u8 flavorLvl, feel;

    dst[0] = EOS;
    StringCopy(dst, gPokeblockNames[pokeblock->color]);
    StringAppend(dst, sText_WasMade);
    StringAppend(dst, sText_NewLine);

    flavorLvl = GetHighestPokeblocksFlavorLevel(pokeblock);
    feel = GetPokeblocksFeel(pokeblock);

    StringAppend(dst, sText_TheLevelIs);
    ConvertIntToDecimalStringN(text, flavorLvl, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(dst, text);

    StringAppend(dst, sText_TheFeelIs);
    ConvertIntToDecimalStringN(text, feel, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(dst, text);

    StringAppend(dst, sText_Dot2);
    StringAppend(dst, sText_NewParagraph);
}

static void Blender_SortBasedOnPoints(u8 *places, u8 playersNum, u32 *scores)
{
    s32 i, j;

    for (i = 0; i < playersNum; i++)
    {
        for (j = 0; j < playersNum; j++)
        {
            if (scores[places[i]] > scores[places[j]])
            {
                u8 temp = places[i];
                places[i] = places[j];
                places[j] = temp;
            }
        }
    }
}

static void Blender_SortScores(void)
{
    u8 playerId;
    u8 i;
    u8 places[BLENDER_MAX_PLAYERS];
    u32 points[BLENDER_MAX_PLAYERS];

    for (i = 0; i < sBerryBlenderData->playersNo; i++)
        places[i] = i;
    for (i = 0; i < sBerryBlenderData->playersNo; i++)
    {
        points[i] = 1000000 * sBerryBlenderData->scores[i][BLENDER_SCORE_BEST];
        points[i] += 1000 * sBerryBlenderData->scores[i][BLENDER_SCORE_GOOD];
        points[i] += 1000 - sBerryBlenderData->scores[i][BLENDER_SCORE_MISS];
    }
    Blender_SortBasedOnPoints(places, sBerryBlenderData->playersNo, points);
    for (i = 0; i < sBerryBlenderData->playersNo; i++)
        sBerryBlenderData->playerPlaces[i] = places[i];

    if (gReceivedRemoteLinkPlayers == 0)
        playerId = 0;
    else
        playerId = GetMultiplayerId();

    for (i = 0; i < sBerryBlenderData->playersNo; i++)
    {
        if (sBerryBlenderData->playerPlaces[i] == playerId)
            sBerryBlenderData->field_1A4 = i;
    }
}

static bool8 Blender_PrintBlendingRanking(void)
{
    u16 i;
    s32 xPos, yPos;

    switch (sBerryBlenderData->mainState)
    {
    case 0:
        sBerryBlenderData->mainState++;
        sBerryBlenderData->framesToWait = 255;
        break;
    case 1:
        sBerryBlenderData->framesToWait -= 10;
        if (sBerryBlenderData->framesToWait < 0)
        {
            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->mainState++;
        }
        break;
    case 2:
        if (++sBerryBlenderData->framesToWait > 20)
        {
            sBerryBlenderData->framesToWait = 0;
            sBerryBlenderData->mainState++;
        }
        break;
    case 3:
        DrawStdFrameWithCustomTileAndPalette(5, 0, 1, 0xD);
        xPos = GetStringCenterAlignXOffset(1, sText_Ranking, 0xA8);
        Blender_AddTextPrinter(5, sText_Ranking, xPos, 1, TEXT_SPEED_FF, 0);

        sBerryBlenderData->scoreIconIds[BLENDER_SCORE_BEST] = CreateSprite(&sUnknown_08339B40, 128, 52, 0);
        StartSpriteAnim(&gSprites[sBerryBlenderData->scoreIconIds[BLENDER_SCORE_BEST]], 3);
        gSprites[sBerryBlenderData->scoreIconIds[BLENDER_SCORE_BEST]].callback = SpriteCallbackDummy;

        sBerryBlenderData->scoreIconIds[BLENDER_SCORE_GOOD] = CreateSprite(&sUnknown_08339B40, 160, 52, 0);
        gSprites[sBerryBlenderData->scoreIconIds[BLENDER_SCORE_GOOD]].callback = SpriteCallbackDummy;

        sBerryBlenderData->scoreIconIds[BLENDER_SCORE_MISS] = CreateSprite(&sUnknown_08339B40, 192, 52, 0);
        StartSpriteAnim(&gSprites[sBerryBlenderData->scoreIconIds[BLENDER_SCORE_MISS]], 1);
        gSprites[sBerryBlenderData->scoreIconIds[BLENDER_SCORE_MISS]].callback = SpriteCallbackDummy;

        Blender_SortScores();

        for (yPos = 0x29, i = 0; i < sBerryBlenderData->playersNo; yPos += 0x10, i++)
        {
            u8 place = sBerryBlenderData->playerPlaces[i];

            ConvertIntToDecimalStringN(sBerryBlenderData->stringVar, i + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
            StringAppend(sBerryBlenderData->stringVar, sText_Dot);
            StringAppend(sBerryBlenderData->stringVar, gText_Space);
            StringAppend(sBerryBlenderData->stringVar, gLinkPlayers[place].name);
            Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, 0, yPos, TEXT_SPEED_FF, 3);

            ConvertIntToDecimalStringN(sBerryBlenderData->stringVar, sBerryBlenderData->scores[place][BLENDER_SCORE_BEST], STR_CONV_MODE_RIGHT_ALIGN, 3);
            Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, 0x4E, yPos, TEXT_SPEED_FF, 3);

            ConvertIntToDecimalStringN(sBerryBlenderData->stringVar, sBerryBlenderData->scores[place][BLENDER_SCORE_GOOD], STR_CONV_MODE_RIGHT_ALIGN, 3);
            Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, 0x6E, yPos, TEXT_SPEED_FF, 3);

            ConvertIntToDecimalStringN(sBerryBlenderData->stringVar, sBerryBlenderData->scores[place][BLENDER_SCORE_MISS], STR_CONV_MODE_RIGHT_ALIGN, 3);
            Blender_AddTextPrinter(5, sBerryBlenderData->stringVar, 0x8E, yPos, TEXT_SPEED_FF, 3);
        }

        PutWindowTilemap(5);
        CopyWindowToVram(5, 3);

        sBerryBlenderData->framesToWait = 0;
        sBerryBlenderData->mainState++;
        break;
    case 4:
        if (++sBerryBlenderData->framesToWait > 20)
            sBerryBlenderData->mainState++;
        break;
    case 5:
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sBerryBlenderData->mainState++;
        }
        break;
    case 6:
        sBerryBlenderData->mainState = 0;
        return TRUE;
    }

    return FALSE;
}

void ShowBerryBlenderRecordWindow(void)
{
    s32 i;
    s32 xPos, yPos;
    struct WindowTemplate winTemplate;
    u8 text[32];

    winTemplate = sBlenderRecordWindowTemplate;
    gRecordsWindowId = AddWindow(&winTemplate);
    DrawStdWindowFrame(gRecordsWindowId, 0);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));

    xPos = GetStringCenterAlignXOffset(1, gText_BlenderMaxSpeedRecord, 0x90);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_BlenderMaxSpeedRecord, xPos, 1, 0, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_234Players, 4, 0x29, 0, NULL);

    for (i = 0, yPos = 0x29; i < BLENDER_SCORES_NO; i++)
    {
        u8 *txtPtr;
        u32 record;

        record = gSaveBlock1Ptr->berryBlenderRecords[i];

        txtPtr = ConvertIntToDecimalStringN(text, record / 100, STR_CONV_MODE_RIGHT_ALIGN, 3);
        txtPtr = StringAppend(txtPtr, sText_Dot);
        txtPtr = ConvertIntToDecimalStringN(txtPtr, record % 100, STR_CONV_MODE_LEADING_ZEROS, 2);
        txtPtr = StringAppend(txtPtr, sText_RPM);

        xPos = GetStringRightAlignXOffset(1, text, 0x8C);
        AddTextPrinterParameterized(gRecordsWindowId, 1, text, xPos, yPos + (i * 16), 0, NULL);
    }

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

static void sub_8083F3C(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        PlayFanfare(MUS_FANFA1);
        gTasks[taskId].data[0]++;
    }
    if (IsFanfareTaskInactive())
    {
        PlayBGM(sBerryBlenderData->field_154);
        DestroyTask(taskId);
    }
}

static bool32 TryAddContestLinkTvShow(struct Pokeblock *pokeblock, struct TvBlenderStruct *tvBlender)
{
    u8 flavorLevel = GetHighestPokeblocksFlavorLevel(pokeblock);
    u16 sheen = (flavorLevel * 10) / GetPokeblocksFeel(pokeblock);

    tvBlender->pokeblockSheen = sheen;
    tvBlender->pokeblockColor = pokeblock->color;
    tvBlender->name[0] = EOS;

    if (gReceivedRemoteLinkPlayers != 0)
    {
        if (sBerryBlenderData->field_1A4 == 0 && sheen > 20)
        {
            StringCopy(tvBlender->name, gLinkPlayers[sBerryBlenderData->playerPlaces[sBerryBlenderData->playersNo - 1]].name);
            tvBlender->pokeblockFlavor = GetPokeblocksFlavor(pokeblock);
            if (Put3CheersForPokeblocksOnTheAir(tvBlender->name, tvBlender->pokeblockFlavor,
                                            tvBlender->pokeblockColor, tvBlender->pokeblockSheen,
                                            gLinkPlayers[sBerryBlenderData->playerPlaces[sBerryBlenderData->playersNo - 1]].language))
            {
                return TRUE;
            }

            return FALSE;
        }
        else if (sBerryBlenderData->field_1A4 == sBerryBlenderData->playersNo - 1 && sheen <= 20)
        {
            StringCopy(tvBlender->name, gLinkPlayers[sBerryBlenderData->playerPlaces[0]].name);
            tvBlender->pokeblockFlavor = GetPokeblocksFlavor(pokeblock);
            if (Put3CheersForPokeblocksOnTheAir(tvBlender->name, tvBlender->pokeblockFlavor,
                                            tvBlender->pokeblockColor, tvBlender->pokeblockSheen,
                                            gLinkPlayers[sBerryBlenderData->playerPlaces[0]].language))
            {
                return TRUE;
            }

            return FALSE;
        }
    }

    return FALSE;
}

static void Blender_AddTextPrinter(u8 windowId, const u8 *string, u8 x, u8 y, s32 speed, s32 caseId)
{
    u8 txtColor[3];
    u32 letterSpacing = 0;

    switch (caseId)
    {
    case 0:
    case 3:
        txtColor[0] = 1;
        txtColor[1] = 2;
        txtColor[2] = 3;
        break;
    case 1:
        txtColor[0] = 0;
        txtColor[1] = 2;
        txtColor[2] = 3;
        break;
    case 2:
        txtColor[0] = 0;
        txtColor[1] = 4;
        txtColor[2] = 5;
        break;
    }

    if (caseId != 3)
    {
        FillWindowPixelBuffer(windowId, PIXEL_FILL(txtColor[0]));
    }

    AddTextPrinterParameterized4(windowId, 1, x, y, letterSpacing, 1, txtColor, speed, string);
}

static bool32 Blender_PrintText(s16 *textState, const u8 *string, s32 textSpeed)
{
    switch (*textState)
    {
    case 0:
        DrawDialogFrameWithCustomTileAndPalette(4, FALSE, 0x14, 0xF);
        Blender_AddTextPrinter(4, string, 0, 1, textSpeed, 0);
        PutWindowTilemap(4);
        CopyWindowToVram(4, 3);
        (*textState)++;
        break;
    case 1:
        if (!IsTextPrinterActive(4))
        {
            *textState = 0;
            return TRUE;
        }
        break;
    }

    return FALSE;
}
