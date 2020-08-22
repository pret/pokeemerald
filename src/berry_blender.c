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

enum {
    SCORE_BEST,
    SCORE_GOOD,
    SCORE_MISS,
    NUM_SCORE_TYPES,
};

// Redundant with the above. Reversed
enum {
    PROXIMITY_MISS,
    PROXIMITY_GOOD,
    PROXIMITY_BEST,
};

enum {
    SCOREANIM_GOOD,
    SCOREANIM_MISS,
    SCOREANIM_BEST_FLASH,
    SCOREANIM_BEST_STATIC,
};

#define MAX_PROGRESS_BAR 1000

#define GFXTAG_COUNTDOWN_NUMBERS 12345
#define GFXTAG_START             12346
#define GFXTAG_PARTICLES         23456
#define GFXTAG_PLAYER_ARROW      46545
#define GFXTAG_SCORE_SYMBOLS     48888

#define PALTAG_PLAYER_ARROW      12312
#define PALTAG_MISC              46546

#define BLENDER_MAX_PLAYERS MAX_LINK_PLAYERS

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
    u16 maxRPM;
};

struct BlenderGameBlock
{
    struct TimeAndRPM timeRPM;
    u16 scores[BLENDER_MAX_PLAYERS][NUM_SCORE_TYPES];
};

struct TvBlenderStruct
{
    u8 name[11];
    u8 pokeblockFlavor;
    u8 pokeblockColor;
    u8 pokeblockSheen;
};

struct BerryBlender
{
    u8 mainState;
    u8 loadGfxState;
    u8 unused_02[0x42];
    u16 field_44;
    u8 scoreIconIds[NUM_SCORE_TYPES];
    u16 arrowPos;
    s16 speed;
    u16 maxRPM;
    u8 playerArrowSpriteIds[BLENDER_MAX_PLAYERS];
    u8 playerArrowSpriteIds2[BLENDER_MAX_PLAYERS];
    u8 unused_57[0xB];
    u8 gameEndState;
    u16 field_64[BLENDER_MAX_PLAYERS];
    u16 field_6C;
    u16 field_6E;
    u16 playAgainState;
    u8 field_72;
    u16 chosenItemId[BLENDER_MAX_PLAYERS];
    u8 numPlayers;
    u8 unused_7D[0x10];
    u16 field_8E[BLENDER_MAX_PLAYERS];
    u16 field_96[BLENDER_MAX_PLAYERS];
    u8 yesNoAnswer;
    u8 stringVar[100];
    u32 gameFrameTime;
    s32 framesToWait;
    u32 field_10C;
    u8 unused_110[4];
    u8 playerToThrowBerry;
    u16 progressBarValue;
    u16 maxProgressBarValue;
    u16 field_11A;
    s16 bg_X;
    s16 bg_Y;
    u8 opponentTaskIds[BLENDER_MAX_PLAYERS - 1];
    u8 field_123;
    u16 scores[BLENDER_MAX_PLAYERS][NUM_SCORE_TYPES];
    u8 playerPlaces[BLENDER_MAX_PLAYERS];
    struct BgAffineSrcData bgAffineSrc;
    u16 savedMusic;
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
static void Task_HandleOpponent1(u8);
static void Task_HandleOpponent2(u8);
static void Task_HandleOpponent3(u8);
static void Task_HandleBerryMaster(u8);
static void sub_8083F3C(u8);
static void SpriteCB_PlayerArrow(struct Sprite *);
static void SpriteCB_ScoreSymbol(struct Sprite *);
static void SpriteCB_CountdownNumber(struct Sprite *);
static void SpriteCB_Start(struct Sprite *);
static void SpriteCB_ScoreSymbolBest(struct Sprite *);
static void Blender_SetPlayerNamesLocal(u8);
static void sub_807FAC8(void);
static void sub_8082D28(void);
static bool32 Blender_PrintText(s16 *, const u8 *, s32 );
static void StartBlender(void);
static void CB2_StartBlenderLink(void);
static void CB2_StartBlenderLocal(void);
static void Blender_DummiedOutFunc(s16, s16);
static void CB2_PlayBlender(void);
static void DrawBlenderCenter(struct BgAffineSrcData *);
static bool8 sub_8083380(void);
static void sub_808074C(void);
static void Blender_PrintPlayerNames(void);
static void InitBlenderBgs(void);
static void Blender_SetParticipantBerryData(u8, u16);
static void Blender_AddTextPrinter(u8, const u8 *, u8, u8, s32, s32);
static void sub_8080DF8(void);
static void CreateParticleSprites(void);
static void sub_80832BC(s16*, u16);
static void TryUpdateProgressBar(u16, u16);
static void UpdateRPM(u16);
static void sub_808330C(void);
static void sub_8082AD4(void);
static void CB2_HandleBlenderEndGame(void);
static bool8 PrintBlendingRanking(void);
static bool8 PrintBlendingResults(void);
static void CB2_HandlePlayerPlayAgainChoice(void);
static void CB2_HandlePlayerLinkPlayAgainChoice(void);
static void UpdateProgressBar(u16, u16);
static void Blender_PrintMadePokeblockString(struct Pokeblock *, u8 *);
static bool32 TryAddContestLinkTvShow(struct Pokeblock *, struct TvBlenderStruct *);

// EWRAM
EWRAM_DATA static struct BerryBlender *sBerryBlender = NULL;
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

static const u16 sBlenderCenter_Pal[] = INCBIN_U16("graphics/berry_blender/center.gbapal");
static const u8 sBlenderCenter_Tilemap[] = INCBIN_U8("graphics/berry_blender/center_map.bin");
static const u16 sBlenderOuter_Pal[] = INCBIN_U16("graphics/berry_blender/outer.gbapal");

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

static const struct BgTemplate sBgTemplates[3] =
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

static const struct WindowTemplate sWindowTemplates[] =
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

static const s8 sPlayerArrowQuadrant[BLENDER_MAX_PLAYERS][2] =
{
    {-1, -1}, {1, -1}, {-1, 1}, {1, 1}
};

static const u8 sPlayerArrowPos[BLENDER_MAX_PLAYERS][2] =
{
    {72, 32}, {168, 32}, {72, 128}, {168, 128}
};

// -1 indicates no player at this position
static const u8 sPlayerIdMap[BLENDER_MAX_PLAYERS - 1][BLENDER_MAX_PLAYERS] =
{
    {-1, 0, 1, -1}, // 2 Players
    {-1, 0, 1, 2},  // 3 Players
    {0, 1, 2, 3}    // 4 Players
};

static const u16 sArrowStartPos[] = {0, 0xC000, 0x4000, 0x8000};
static const u8 sArrowStartPosIds[BLENDER_MAX_PLAYERS - 1] = {1, 1, 0};
static const u8 sUnknown_083399E7[] = {32, 224, 96, 160, 0};

static const TaskFunc sLocalOpponentTasks[] =
{
    Task_HandleOpponent1, 
    Task_HandleOpponent2, 
    Task_HandleOpponent3
};

static const struct OamData sOam_PlayerArrow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PlayerArrow_TopLeft[] =
{
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_TopRight[] =
{
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_BottomLeft[] =
{
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_BottomRight[] =
{
    ANIMCMD_FRAME(16, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_TopLeft_Flash[] =
{
    ANIMCMD_FRAME(48, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_TopRight_Flash[] =
{
    ANIMCMD_FRAME(48, 2, .vFlip = TRUE),
    ANIMCMD_FRAME(32, 5, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .vFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_BottomLeft_Flash[] =
{
    ANIMCMD_FRAME(48, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_BottomRight_Flash[] =
{
    ANIMCMD_FRAME(48, 2, 0, 0),
    ANIMCMD_FRAME(32, 5, 0, 0),
    ANIMCMD_FRAME(48, 3, 0, 0),
    ANIMCMD_FRAME(16, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_TopLeft_Off[] =
{
    ANIMCMD_FRAME(0, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_TopRight_Off[] =
{
    ANIMCMD_FRAME(0, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_BottomLeft_Off[] =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerArrow_BottomRight_Off[] =
{
    ANIMCMD_FRAME(0, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_PlayerArrow[] =
{
    sAnim_PlayerArrow_TopLeft,
    sAnim_PlayerArrow_TopRight,
    sAnim_PlayerArrow_BottomLeft,
    sAnim_PlayerArrow_BottomRight,
    sAnim_PlayerArrow_TopLeft_Flash,
    sAnim_PlayerArrow_TopRight_Flash,
    sAnim_PlayerArrow_BottomLeft_Flash,
    sAnim_PlayerArrow_BottomRight_Flash,
    sAnim_PlayerArrow_TopLeft_Off,
    sAnim_PlayerArrow_TopRight_Off,
    sAnim_PlayerArrow_BottomLeft_Off,
    sAnim_PlayerArrow_BottomRight_Off
};

static const struct SpriteSheet sSpriteSheet_PlayerArrow =
{
    gBerryBlenderPlayerArrow_Gfx, 0x800, GFXTAG_PLAYER_ARROW
};

static const struct SpritePalette sSpritePal_BlenderMisc =
{
    gBerryBlenderMiscPalette, PALTAG_MISC
};

static const struct SpritePalette sSpritePal_PlayerArrow =
{
    gBerryBlenderArrowPalette, PALTAG_PLAYER_ARROW
};

static const struct SpriteTemplate sSpriteTemplate_PlayerArrow =
{
    .tileTag = GFXTAG_PLAYER_ARROW,
    .paletteTag = PALTAG_PLAYER_ARROW,
    .oam = &sOam_PlayerArrow,
    .anims = sAnims_PlayerArrow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PlayerArrow
};

static const struct OamData sOam_ScoreSymbols =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_ScoreSymbols_Good[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ScoreSymbols_Miss[] =
{
    ANIMCMD_FRAME(4, 20, 1, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ScoreSymbols_BestFlash[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ScoreSymbols_BestStatic[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_ScoreSymbols[] =
{
    [SCOREANIM_GOOD]        = sAnim_ScoreSymbols_Good,
    [SCOREANIM_MISS]        = sAnim_ScoreSymbols_Miss,
    [SCOREANIM_BEST_FLASH]  = sAnim_ScoreSymbols_BestFlash,
    [SCOREANIM_BEST_STATIC] = sAnim_ScoreSymbols_BestStatic,
};

static const struct SpriteSheet sSpriteSheet_ScoreSymbols =
{
    gBerryBlenderScoreSymbols_Gfx, 0x200, GFXTAG_SCORE_SYMBOLS
};

static const struct SpriteTemplate sSpriteTemplate_ScoreSymbols =
{
    .tileTag = GFXTAG_SCORE_SYMBOLS,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_ScoreSymbols,
    .anims = sAnims_ScoreSymbols,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ScoreSymbol
};

static const struct OamData sOam_Particles =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
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

static const union AnimCmd *const sAnims_Particles[] =
{
    sSpriteAnim_821647C,
    sSpriteAnim_8216494,
    sSpriteAnim_82164AC,
    sSpriteAnim_82164D0,
    sSpriteAnim_82164D8,
};

static const struct SpriteSheet sSpriteSheet_Particles =
{
    gBerryBlenderParticles_Gfx, 0xE0, GFXTAG_PARTICLES
};

static const struct SpriteTemplate sSpriteTemplate_Particles =
{
    .tileTag = GFXTAG_PARTICLES,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_Particles,
    .anims = sAnims_Particles,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_CountdownNumbers =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_CountdownNumbers_3[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_CountdownNumbers_2[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_CountdownNumbers_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_CountdownNumbers[] =
{
    sAnim_CountdownNumbers_3,
    sAnim_CountdownNumbers_2,
    sAnim_CountdownNumbers_1,
};

static const struct SpriteSheet sSpriteSheet_CountdownNumbers =
{
    gBerryBlenderCountdownNumbers_Gfx, 0x600, GFXTAG_COUNTDOWN_NUMBERS
};

static const struct SpriteTemplate sSpriteTemplate_CountdownNumbers =
{
    .tileTag = GFXTAG_COUNTDOWN_NUMBERS,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_CountdownNumbers,
    .anims = sAnims_CountdownNumbers,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CountdownNumber
};

static const struct OamData sOam_Start =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_Start[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Start[] =
{
    sAnim_Start,
};

static const struct SpriteSheet sSpriteSheet_Start =
{
    gBerryBlenderStart_Gfx, 0x400, GFXTAG_START
};

static const struct SpriteTemplate sSpriteTemplate_Start =
{
    .tileTag = GFXTAG_START,
    .paletteTag = PALTAG_MISC,
    .oam = &sOam_Start,
    .anims = sAnims_Start,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Start
};

// Data for throwing the berries in at the start
// x, y, bounce speed, x speed, y speed
static const s16 sBerrySpriteData[][5] =
{
    {-10,  20,  10,   2,   1},
    {250,  20,  10,  -2,   1},
    {-10, 140,  10,   2,  -1},
    {250, 140,  10,  -2,  -1},
};

static const u8 sOpponentBerrySets[][3] =
{
    {4, 3, 2}, 
    {0, 4, 3}, 
    {1, 0, 4}, 
    {2, 1, 0}, 
    {3, 2, 1}, 
    {0, 2, 3}, 
    {1, 3, 4}, 
    {2, 4, 0}, 
    {3, 0, 1}, 
    {4, 1, 2},
};

static const u8 sSpecialOpponentBerrySets[] = {30, 31, 32, 33, 34};

// "0 players" is link 
static const u8 sNumPlayersToSpeedDivisor[] = {1, 1, 2, 3, 4};

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
    m4aMPlayPitchControl(&gMPlayInfo_SE2, 0xFFFF, 2 * (sBerryBlender->speed - 128));
}

static void VBlankCB_BerryBlender(void)
{
    BerryBlender_SetBackgroundsPos();
    SetBgAffine(2, sBerryBlender->bgAffineSrc.texX, sBerryBlender->bgAffineSrc.texY,
                sBerryBlender->bgAffineSrc.scrX, sBerryBlender->bgAffineSrc.scrY,
                sBerryBlender->bgAffineSrc.sx, sBerryBlender->bgAffineSrc.sy,
                sBerryBlender->bgAffineSrc.alpha);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 LoadBerryBlenderGfx(void)
{
    switch (sBerryBlender->loadGfxState)
    {
    case 0:
        sBerryBlender->tilesBuffer = AllocZeroed(GetDecompressedDataSize(gBerryBlenderCenter_Gfx) + 100);
        LZDecompressWram(gBerryBlenderCenter_Gfx, sBerryBlender->tilesBuffer);
        sBerryBlender->loadGfxState++;
        break;
    case 1:
        CopyToBgTilemapBuffer(2, sBlenderCenter_Tilemap, 0x400, 0);
        CopyBgTilemapBufferToVram(2);
        LoadPalette(sBlenderCenter_Pal, 0, 0x100);
        sBerryBlender->loadGfxState++;
        break;
    case 2:
        LoadBgTiles(2, sBerryBlender->tilesBuffer, GetDecompressedDataSize(gBerryBlenderCenter_Gfx), 0);
        sBerryBlender->loadGfxState++;
        break;
    case 3:
        LZDecompressWram(gBerryBlenderOuter_Gfx, sBerryBlender->tilesBuffer);
        sBerryBlender->loadGfxState++;
        break;
    case 4:
        LoadBgTiles(1, sBerryBlender->tilesBuffer, GetDecompressedDataSize(gBerryBlenderOuter_Gfx), 0);
        sBerryBlender->loadGfxState++;
        break;
    case 5:
        LZDecompressWram(gBerryBlenderOuter_Tilemap, sBerryBlender->tilesBuffer);
        sBerryBlender->loadGfxState++;
        break;
    case 6:
        CopyToBgTilemapBuffer(1, sBerryBlender->tilesBuffer, GetDecompressedDataSize(gBerryBlenderOuter_Tilemap), 0);
        CopyBgTilemapBufferToVram(1);
        sBerryBlender->loadGfxState++;
        break;
    case 7:
        LoadPalette(sBlenderOuter_Pal, 0x80, 0x20);
        sBerryBlender->loadGfxState++;
        break;
    case 8:
        LoadSpriteSheet(&sSpriteSheet_PlayerArrow);
        LoadSpriteSheet(&sSpriteSheet_Particles);
        LoadSpriteSheet(&sSpriteSheet_ScoreSymbols);
        sBerryBlender->loadGfxState++;
        break;
    case 9:
        LoadSpriteSheet(&sSpriteSheet_CountdownNumbers);
        LoadSpriteSheet(&sSpriteSheet_Start);
        LoadSpritePalette(&sSpritePal_PlayerArrow);
        LoadSpritePalette(&sSpritePal_BlenderMisc);
        Free(sBerryBlender->tilesBuffer);
        sBerryBlender->loadGfxState = 0;
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
    if (InitWindows(sWindowTemplates))
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
    if (sBerryBlender == NULL)
        sBerryBlender = AllocZeroed(sizeof(*sBerryBlender));

    sBerryBlender->gameEndState = 0;
    sBerryBlender->mainState = 0;
    sBerryBlender->gameEndState = 0;

    Blender_SetPlayerNamesLocal(gSpecialVar_0x8004);
    SetMainCallback2(sub_807FAC8);
}

static void sub_807FAC8(void)
{
    s32 i;

    switch (sBerryBlender->mainState)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(NULL);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(1, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        SetBgTilemapBuffer(1, sBerryBlender->tilemapBuffers[0]);
        SetBgTilemapBuffer(2, sBerryBlender->tilemapBuffers[1]);
        LoadUserWindowBorderGfx(0, 1, 0xD0);
        LoadMessageBoxGfx(0, 0x14, 0xF0);
        InitBerryBlenderWindows();

        sBerryBlender->mainState++;
        sBerryBlender->maxProgressBarValue = 0;
        sBerryBlender->progressBarValue = 0;
        sBerryBlender->field_11A = 80;
        sBerryBlender->bg_X = 0;
        sBerryBlender->bg_Y = 0;
        sBerryBlender->loadGfxState = 0;

        sub_8082D28();
        break;
    case 1:
        if (LoadBerryBlenderGfx())
        {
            for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
            {
                sBerryBlender->playerArrowSpriteIds[i] = CreateSprite(&sSpriteTemplate_PlayerArrow, sPlayerArrowPos[i][0], sPlayerArrowPos[i][1], 1);
                StartSpriteAnim(&gSprites[sBerryBlender->playerArrowSpriteIds[i]], i + 8);
            }
            if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
            {
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
            SetVBlankCallback(VBlankCB_BerryBlender);
            sBerryBlender->mainState++;
        }
        break;
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        sub_8082D28();
        sBerryBlender->mainState++;
        break;
    case 3:
        sub_807F9D0();
        if (!gPaletteFade.active)
            sBerryBlender->mainState++;
        break;
    case 4:
        if (Blender_PrintText(&sBerryBlender->textState, sText_BerryBlenderStart, GetPlayerTextSpeedDelay()))
            sBerryBlender->mainState++;
        break;
    case 5:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        sBerryBlender->mainState++;
        break;
    case 6:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            UnsetBgTilemapBuffer(2);
            UnsetBgTilemapBuffer(1);
            SetVBlankCallback(NULL);
            ChooseBerryForMachine(StartBlender);

            sBerryBlender->mainState = 0;
        }
        break;
    }

    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

#define sTargetY       data[0]
#define sX             data[1]
#define sY             data[2]
#define sBounceSpeed   data[3]
#define sYUpSpeed      data[4]
#define sBounces       data[5]
#define sXSpeed        data[6]
#define sYDownSpeed    data[7]

// For throwing berries into the machine
static void SpriteCB_Berry(struct Sprite* sprite)
{
    sprite->sX += sprite->sXSpeed;
    sprite->sY -= sprite->sYUpSpeed;
    sprite->sY += sprite->sYDownSpeed;
    sprite->sTargetY += sprite->sYDownSpeed;
    sprite->sYUpSpeed--;

    if (sprite->sTargetY < sprite->sY)
    {
        sprite->sBounceSpeed = sprite->sYUpSpeed = sprite->sBounceSpeed - 1;

        if (++sprite->sBounces > 3)
            DestroySprite(sprite);
        else
            PlaySE(SE_TB_KARA);
    }
    sprite->pos1.x = sprite->sX;
    sprite->pos1.y = sprite->sY;
}

static void SetBerrySpriteData(struct Sprite* sprite, s16 x, s16 y, s16 bounceSpeed, s16 xSpeed, s16 ySpeed)
{
    sprite->sTargetY = y;
    sprite->sX = x;
    sprite->sY = y;
    sprite->sBounceSpeed = bounceSpeed;
    sprite->sYUpSpeed = 10;
    sprite->sBounces = 0;
    sprite->sXSpeed = xSpeed;
    sprite->sYDownSpeed = ySpeed;
    sprite->callback = SpriteCB_Berry;
}

#undef sTargetY
#undef sX
#undef sY
#undef sBounceSpeed
#undef sYUpSpeed
#undef sBounces
#undef sXSpeed
#undef sYDownSpeed

static void CreateBerrySprite(u16 a0, u8 playerId)
{
    u8 spriteId = CreateSpinningBerrySprite(a0 + FIRST_BERRY_INDEX - 10, 0, 80, playerId & 1);
    SetBerrySpriteData(&gSprites[spriteId], 
                        sBerrySpriteData[playerId][0], 
                        sBerrySpriteData[playerId][1], 
                        sBerrySpriteData[playerId][2], 
                        sBerrySpriteData[playerId][3], 
                        sBerrySpriteData[playerId][4]);
}

static void ConvertItemToBlenderBerry(struct BlenderBerry* berry, u16 itemId)
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
    case 0: // Link games have 0 in-game opponents
        gInGameOpponentsNo = 0;
        break;
    case 1:
        gInGameOpponentsNo = 1;
        sBerryBlender->numPlayers = 2;
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
        sBerryBlender->numPlayers = 3;
        StringCopy(gLinkPlayers[0].name, gSaveBlock2Ptr->playerName);
        StringCopy(gLinkPlayers[1].name, sBlenderOpponentsNames[BLENDER_DUDE]);
        StringCopy(gLinkPlayers[2].name, sBlenderOpponentsNames[BLENDER_LASSIE]);

        gLinkPlayers[0].language = GAME_LANGUAGE;
        gLinkPlayers[1].language = GAME_LANGUAGE;
        gLinkPlayers[2].language = GAME_LANGUAGE;
        break;
    case 3:
        gInGameOpponentsNo = 3;
        sBerryBlender->numPlayers = 4;
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

static void StartBlender(void)
{
    s32 i;

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    if (sBerryBlender == NULL)
        sBerryBlender = AllocZeroed(sizeof(*sBerryBlender));

    sBerryBlender->mainState = 0;
    sBerryBlender->field_10C = 0;

    for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        sBerryBlender->chosenItemId[i] = ITEM_NONE;

    Blender_SetPlayerNamesLocal(gSpecialVar_0x8004);

    if (gSpecialVar_0x8004 == 0)
        SetMainCallback2(CB2_StartBlenderLink);
    else
        SetMainCallback2(CB2_StartBlenderLocal);
}

static void CB2_StartBlenderLink(void)
{
    s32 i, j;

    switch (sBerryBlender->mainState)
    {
    case 0:
        InitBlenderBgs();
        gLinkType = LINKTYPE_BERRY_BLENDER;
        sBerryBlender->field_72 = 0;
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlender->field_64[i] = 0;
            for (j = 0; j < NUM_SCORE_TYPES; j++)
            {
                sBerryBlender->scores[i][j] = 0;
            }
        }
        sBerryBlender->playAgainState = 0;
        sBerryBlender->maxRPM = 0;
        sBerryBlender->loadGfxState = 0;
        sBerryBlender->mainState++;
        break;
    case 1:
        if (LoadBerryBlenderGfx())
        {
            sBerryBlender->mainState++;
            sub_8082D28();
        }
        break;
    case 2:
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlender->playerArrowSpriteIds2[i] = CreateSprite(&sSpriteTemplate_PlayerArrow, sPlayerArrowPos[i][0], sPlayerArrowPos[i][1], 1);
            StartSpriteAnim(&gSprites[sBerryBlender->playerArrowSpriteIds2[i]], i + 8);
        }
        if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        sBerryBlender->mainState++;
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        sBerryBlender->mainState++;
        break;
    case 4:
        sub_807F9D0();
        if (!gPaletteFade.active)
        {
            sBerryBlender->mainState++;
        }
        break;
    case 5:
        Blender_PrintText(&sBerryBlender->textState, sText_CommunicationStandby, 0);
        sBerryBlender->mainState = 8;
        sBerryBlender->framesToWait = 0;
        break;
    case 8:
        sBerryBlender->mainState++;
        sBerryBlender->playerToThrowBerry = 0;
        ConvertItemToBlenderBerry(&sBerryBlender->blendedBerries[0], gSpecialVar_ItemId);
        memcpy(gBlockSendBuffer, &sBerryBlender->blendedBerries[0], sizeof(struct BlenderBerry));
        SetLinkStandbyCallback();
        sBerryBlender->framesToWait = 0;
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() == 0)
                SendBlockRequest(4);
            sBerryBlender->mainState++;
        }
        break;
    case 10:
        if (++sBerryBlender->framesToWait > 20)
        {
            ClearDialogWindowAndFrameToTransparent(4, TRUE);
            if (GetBlockReceivedStatus() == GetLinkPlayerCountAsBitFlags())
            {
                for (i = 0; i < GetLinkPlayerCount(); i++)
                {
                    memcpy(&sBerryBlender->blendedBerries[i], &gBlockRecvBuffer[i][0], sizeof(struct BlenderBerry));
                    sBerryBlender->chosenItemId[i] = sBerryBlender->blendedBerries[i].itemId;
                }

                ResetBlockReceivedFlags();
                sBerryBlender->mainState++;
            }
        }
        break;
    case 11:
        sBerryBlender->numPlayers = GetLinkPlayerCount();

        // Check each player, throw 1 berry in
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            if (sBerryBlender->playerToThrowBerry == sPlayerIdMap[sBerryBlender->numPlayers - 2][i])
            {
                CreateBerrySprite(sBerryBlender->chosenItemId[sBerryBlender->playerToThrowBerry], i);
                break;
            }
        }

        sBerryBlender->framesToWait = 0;
        sBerryBlender->mainState++;
        sBerryBlender->playerToThrowBerry++;
        break;
    case 12:
        if (++sBerryBlender->framesToWait > 60)
        {
            if (sBerryBlender->playerToThrowBerry >= sBerryBlender->numPlayers)
            {
                // Finished throwing berries in
                sBerryBlender->mainState++;
                sBerryBlender->arrowPos = sArrowStartPos[sArrowStartPosIds[sBerryBlender->numPlayers - 2]] - 0x5800;
            }
            else
            {
                // Haven't finished throwing berries in, go back to prev step
                sBerryBlender->mainState--;
            }
            sBerryBlender->framesToWait = 0;
        }
        break;
    case 13:
        if (IsLinkTaskFinished())
        {
            sBerryBlender->mainState++;
            DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
            PlaySE(SE_RU_HYUU);
            ShowBg(2);
        }
        break;
    case 14:
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        sBerryBlender->arrowPos += 0x200;
        sBerryBlender->field_11A += 4;
        if (sBerryBlender->field_11A > 255)
        {
            SetGpuRegBits(REG_OFFSET_BG2CNT, 2);
            sBerryBlender->mainState++;
            sBerryBlender->field_11A = 256;
            sBerryBlender->arrowPos = sArrowStartPos[sArrowStartPosIds[sBerryBlender->numPlayers - 2]];
            sBerryBlender->framesToWait = 0;
            PlaySE(SE_TRACK_DOOR);
            sub_808074C();
            Blender_PrintPlayerNames();
        }
        DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
        break;
    case 15:
        if (sub_8083380())
        {
            sBerryBlender->framesToWait = 0;
            sBerryBlender->mainState++;
        }
        DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
        break;
    case 16:
        CreateSprite(&sSpriteTemplate_CountdownNumbers, 120, -16, 3);
        sBerryBlender->mainState++;
        break;
    case 18:
        sBerryBlender->mainState++;
        break;
    case 19:
        SetLinkStandbyCallback();
        sBerryBlender->mainState++;
        break;
    case 20:
        if (IsLinkTaskFinished())
        {
            sub_800A418();
            sBerryBlender->mainState++;
        }
        break;
    case 21:
        sBerryBlender->speed = 128;
        sBerryBlender->gameFrameTime = 0;
        SetMainCallback2(CB2_PlayBlender);
        if (GetCurrentMapMusic() != MUS_CYCLING)
        {
            sBerryBlender->savedMusic = GetCurrentMapMusic();
        }
        PlayBGM(MUS_CYCLING);
        break;
    }

    Blender_DummiedOutFunc(sBerryBlender->bg_X, sBerryBlender->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void InitBlenderBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();

    SetVBlankCallback(VBlankCB_BerryBlender);

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sBgTemplates, ARRAY_COUNT(sBgTemplates));

    SetBgTilemapBuffer(1, sBerryBlender->tilemapBuffers[0]);
    SetBgTilemapBuffer(2, sBerryBlender->tilemapBuffers[1]);
    LoadUserWindowBorderGfx(0, 1, 0xD0);
    LoadMessageBoxGfx(0, 0x14, 0xF0);
    InitBerryBlenderWindows();

    sBerryBlender->field_44 = 0;
    sBerryBlender->speed = 0;
    sBerryBlender->arrowPos = 0;
    sBerryBlender->maxRPM = 0;
    sBerryBlender->bg_X = 0;
    sBerryBlender->bg_Y = 0;
}

static u8 GetArrowProximity(u16 arrowPos, u8 playerId)
{
    u32 pos = (arrowPos / 256) + 24;
    u8 arrID = sBerryBlender->field_96[playerId];
    u32 var2 = sUnknown_083399E7[arrID];

    if (pos >= var2 && pos < var2 + 48)
    {
        if (pos >= var2 + 20 && pos < var2 + 28)
            return PROXIMITY_BEST;
        else
            return PROXIMITY_GOOD;
    }

    return PROXIMITY_MISS;
}

static void SetOpponentsBerryData(u16 playerBerryItemId, u8 playersNum, struct BlenderBerry* playerBerry)
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
        opponentSetId = ITEM_TO_BERRY(playerBerryItemId) - 1;
        if (opponentSetId >= 5)
            opponentSetId = (opponentSetId % 5) + 5;
    }
    for (i = 0; i < playersNum - 1; i++)
    {
        opponentBerryId = sOpponentBerrySets[opponentSetId][i];
        var = ITEM_TO_BERRY(playerBerryItemId) - 31;
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
        sBerryBlender->field_96[i] = 0xFF;
        sBerryBlender->field_8E[i] = sPlayerIdMap[sBerryBlender->numPlayers - 2][i];
    }
    for (j = 0; j < BLENDER_MAX_PLAYERS; j++)
    {
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            if (sBerryBlender->field_8E[i] == j)
                sBerryBlender->field_96[j] = i;
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
        if (sBerryBlender->field_8E[i] != 0xFF)
        {
            sBerryBlender->playerArrowSpriteIds[sBerryBlender->field_8E[i]] = sBerryBlender->playerArrowSpriteIds2[i];
            StartSpriteAnim(&gSprites[sBerryBlender->playerArrowSpriteIds[sBerryBlender->field_8E[i]]], i);

            text[0] = EOS;
            StringCopy(text, gLinkPlayers[sBerryBlender->field_8E[i]].name);
            xPos = GetStringCenterAlignXOffset(1, text, 0x38);

            if (multiplayerId == sBerryBlender->field_8E[i])
                Blender_AddTextPrinter(i, text, xPos, 1, 0, 2);
            else
                Blender_AddTextPrinter(i, text, xPos, 1, 0, 1);

            PutWindowTilemap(i);
            CopyWindowToVram(i, 3);
        }
    }
}

static void CB2_StartBlenderLocal(void)
{
    s32 i, j;

    switch (sBerryBlender->mainState)
    {
    case 0:
        SetWirelessCommType0();
        InitBlenderBgs();
        Blender_SetParticipantBerryData(0, gSpecialVar_ItemId);
        ConvertItemToBlenderBerry(&sBerryBlender->blendedBerries[0], gSpecialVar_ItemId);
        SetOpponentsBerryData(gSpecialVar_ItemId, sBerryBlender->numPlayers, &sBerryBlender->blendedBerries[0]);

        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlender->field_64[i] = 0;
            for (j = 0; j < NUM_SCORE_TYPES; j++)
            {
                sBerryBlender->scores[i][j] = 0;
            }
        }

        sBerryBlender->playAgainState = 0;
        sBerryBlender->loadGfxState = 0;
        gLinkType = LINKTYPE_BERRY_BLENDER;
        sBerryBlender->mainState++;
        break;
    case 1:
        if (LoadBerryBlenderGfx())
        {
            sBerryBlender->mainState++;
            sub_8082D28();
        }
        break;
    case 2:
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            sBerryBlender->playerArrowSpriteIds2[i] = CreateSprite(&sSpriteTemplate_PlayerArrow, sPlayerArrowPos[i][0], sPlayerArrowPos[i][1], 1);
            StartSpriteAnim(&gSprites[sBerryBlender->playerArrowSpriteIds2[i]], i + 8);
        }
        sBerryBlender->mainState++;
        break;
    case 3:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        sBerryBlender->mainState++;
        sBerryBlender->framesToWait = 0;
        break;
    case 4:
        if (++sBerryBlender->framesToWait == 2)
            sub_807F9D0();
        if (!gPaletteFade.active)
            sBerryBlender->mainState = 8;
        break;
    case 8:
        sBerryBlender->mainState = 11;
        sBerryBlender->playerToThrowBerry = 0;
        break;
    case 11:
        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            u32 posId = sPlayerIdMap[sBerryBlender->numPlayers - 2][i];
            if (sBerryBlender->playerToThrowBerry == posId)
            {
                CreateBerrySprite(sBerryBlender->chosenItemId[sBerryBlender->playerToThrowBerry], i);
                break;
            }
        }
        sBerryBlender->framesToWait = 0;
        sBerryBlender->mainState++;
        sBerryBlender->playerToThrowBerry++;
        break;
    case 12:
        if (++sBerryBlender->framesToWait > 60)
        {
            if (sBerryBlender->playerToThrowBerry >= sBerryBlender->numPlayers)
            {
                sBerryBlender->arrowPos = sArrowStartPos[sArrowStartPosIds[sBerryBlender->numPlayers - 2]] - 0x5800;
                sBerryBlender->mainState++;
            }
            else
            {
                sBerryBlender->mainState--;
            }
            sBerryBlender->framesToWait = 0;
        }
        break;
    case 13:
        sBerryBlender->mainState++;
        sub_808074C();
        PlaySE(SE_RU_HYUU);
        DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
        ShowBg(2);
        break;
    case 14:
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG2_ON);
        sBerryBlender->arrowPos += 0x200;
        sBerryBlender->field_11A += 4;
        if (sBerryBlender->field_11A > 255)
        {
            sBerryBlender->mainState++;
            sBerryBlender->field_11A = 256;
            sBerryBlender->arrowPos = sArrowStartPos[sArrowStartPosIds[sBerryBlender->numPlayers - 2]];
            SetGpuRegBits(REG_OFFSET_BG2CNT, 2);
            sBerryBlender->framesToWait = 0;
            PlaySE(SE_TRACK_DOOR);
            Blender_PrintPlayerNames();
        }
        DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
        break;
    case 15:
        if (sub_8083380())
        {
            sBerryBlender->mainState++;
        }
        DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
        break;
    case 16:
        CreateSprite(&sSpriteTemplate_CountdownNumbers, 120, -16, 3);
        sBerryBlender->mainState++;
        break;
    case 18:
        sBerryBlender->mainState++;
        break;
    case 19:
        sBerryBlender->mainState++;
        break;
    case 20:
        sBerryBlender->mainState++;
        break;
    case 21:
        sub_8080DF8();
        sBerryBlender->speed = 128;
        sBerryBlender->gameFrameTime = 0;
        sBerryBlender->field_123 = 0;
        sBerryBlender->field_72 = 0;
        SetMainCallback2(CB2_PlayBlender);

        if (gSpecialVar_0x8004 == 1)
        {
            if (!FlagGet(FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER))
                sBerryBlender->opponentTaskIds[0] = CreateTask(Task_HandleBerryMaster, 10);
            else
                sBerryBlender->opponentTaskIds[0] = CreateTask(sLocalOpponentTasks[0], 10);
        }

        if (gSpecialVar_0x8004 > 1)
        {
            for (i = 0; i < gSpecialVar_0x8004; i++)
                sBerryBlender->opponentTaskIds[i] = CreateTask(sLocalOpponentTasks[i], 10 + i);
        }

        if (GetCurrentMapMusic() != MUS_CYCLING)
            sBerryBlender->savedMusic = GetCurrentMapMusic();

        PlayBGM(MUS_CYCLING);
        PlaySE(SE_MOTER);
        Blender_ControlHitPitch();
        break;
    }

    Blender_DummiedOutFunc(sBerryBlender->bg_X, sBerryBlender->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void sub_8080DF8(void)
{
    s32 i;
    for (i = 0; i < CMD_LENGTH / 2; i++)
    {
        gSendCmd[0] = 0;
        gSendCmd[2] = 0;
        gRecvCmds[i][0] = 0;
        gRecvCmds[i][2] = 0;
    }
}

#define tTimer    data[0]
#define tDelay    data[1]
#define tPlayerId data[2]

static void Task_OpponentMiss(u8 taskId)
{
   if(++gTasks[taskId].tTimer > gTasks[taskId].tDelay)
   {
        gRecvCmds[gTasks[taskId].tPlayerId][2] = LINKCMD_BLENDER_SCORE_MISS;
        DestroyTask(taskId);
   }
}

static void CreateOpponentMissTask(u8 playerId, u8 delay)
{
    u8 taskId = CreateTask(Task_OpponentMiss, 80);
    gTasks[taskId].tDelay = delay;
    gTasks[taskId].tPlayerId = playerId;
}

#undef tTimer
#undef tDelay
#undef tPlayerId

static void Task_HandleOpponent1(u8 taskId)
{
    if (GetArrowProximity(sBerryBlender->arrowPos, 1) == PROXIMITY_BEST)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            if (sBerryBlender->field_123 == 0)
            {
                u8 rand = Random() / 655;
                if (sBerryBlender->speed < 500)
                {
                    if (rand > 75)
                        gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_BEST;
                    else
                        gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_GOOD;

                    gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_GOOD;
                }
                else if (sBerryBlender->speed < 1500)
                {
                    if (rand > 80)
                    {
                        gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_BEST;
                    }
                    else
                    {
                        u8 value = rand - 21;
                        if (value < 60)
                            gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_GOOD;
                        else if (rand < 10)
                            CreateOpponentMissTask(1, 5);
                    }
                }
                else if (rand <= 90)
                {
                    u8 value = rand - 71;
                    if (value < 20)
                        gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_GOOD;
                    else if (rand < 30)
                        CreateOpponentMissTask(1, 5);
                }
                else
                {
                    gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_BEST;
                }
            }
            else
            {
                gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_BEST;
            }

            gTasks[taskId].data[0] = 1;
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

static void Task_HandleOpponent2(u8 taskId)
{
    u32 var1 = (sBerryBlender->arrowPos + 0x1800) & 0xFFFF;
    u32 var2 = sBerryBlender->field_96[2] & 0xFF;
    if ((var1 >> 8) > sUnknown_083399E7[var2] + 20 && (var1 >> 8) < sUnknown_083399E7[var2] + 40)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            if (sBerryBlender->field_123 == 0)
            {
                u8 rand = Random() / 655;
                if (sBerryBlender->speed < 500)
                {
                    if (rand > 66)
                        gRecvCmds[2][2] = LINKCMD_BLENDER_SCORE_BEST;
                    else
                        gRecvCmds[2][2] = LINKCMD_BLENDER_SCORE_GOOD;
                }
                else
                {
                    u8 value;
                    if (rand > 65)
                        gRecvCmds[2][2] = LINKCMD_BLENDER_SCORE_BEST;
                    value = rand - 41;
                    if (value < 25)
                        gRecvCmds[2][2] = LINKCMD_BLENDER_SCORE_GOOD;
                    if (rand < 10)
                        CreateOpponentMissTask(2, 5);
                }

                gTasks[taskId].data[0] = 1;
            }
            else
            {
                gRecvCmds[2][2] = LINKCMD_BLENDER_SCORE_BEST;
                gTasks[taskId].data[0] = 1;
            }
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

static void Task_HandleOpponent3(u8 taskId)
{
    u32 var1, var2;

    var1 = (sBerryBlender->arrowPos + 0x1800) & 0xFFFF;
    var2 = sBerryBlender->field_96[3] & 0xFF;
    if ((var1 >> 8) > sUnknown_083399E7[var2] + 20 && (var1 >> 8) < sUnknown_083399E7[var2] + 40)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            if (sBerryBlender->field_123 == 0)
            {
                u8 rand = (Random() / 655);
                if (sBerryBlender->speed < 500)
                {
                    if (rand > 88)
                        gRecvCmds[3][2] = LINKCMD_BLENDER_SCORE_BEST;
                    else
                        gRecvCmds[3][2] = LINKCMD_BLENDER_SCORE_GOOD;
                }
                else
                {
                    if (rand > 60)
                    {
                        gRecvCmds[3][2] = LINKCMD_BLENDER_SCORE_BEST;
                    }
                    else
                    {
                        s8 value = rand - 56; // makes me wonder what the original code was
                        u8 value2 = value;
                        if (value2 < 5)
                            gRecvCmds[3][2] = LINKCMD_BLENDER_SCORE_GOOD;
                    }
                    if (rand < 5)
                        CreateOpponentMissTask(3, 5);
                }
                gTasks[taskId].data[0] = 1;
            }
            else
            {
                gRecvCmds[3][2] = LINKCMD_BLENDER_SCORE_BEST;
                gTasks[taskId].data[0] = 1;
            }
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

static void Task_HandleBerryMaster(u8 taskId)
{
    if (GetArrowProximity(sBerryBlender->arrowPos, 1) == PROXIMITY_BEST)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            gRecvCmds[1][2] = LINKCMD_BLENDER_SCORE_BEST;
            gTasks[taskId].data[0] = 1;
        }
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}

static void CreateScoreSymbolSprite(u16 cmd, u8 arrowId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_ScoreSymbols,
                            sPlayerArrowPos[arrowId][0] - (10 * sPlayerArrowQuadrant[arrowId][0]),
                            sPlayerArrowPos[arrowId][1] - (10 * sPlayerArrowQuadrant[arrowId][1]),
                            1);
    if (cmd == LINKCMD_BLENDER_SCORE_BEST)
    {
        StartSpriteAnim(&gSprites[spriteId], SCOREANIM_BEST_FLASH);
        gSprites[spriteId].callback = SpriteCB_ScoreSymbolBest;
        PlaySE(SE_RU_GASHIN);
    }
    else if (cmd == LINKCMD_BLENDER_SCORE_GOOD)
    {
        StartSpriteAnim(&gSprites[spriteId], SCOREANIM_GOOD);
        PlaySE(SE_SEIKAI);
    }
    else if (cmd == LINKCMD_BLENDER_SCORE_MISS)
    {
        StartSpriteAnim(&gSprites[spriteId], SCOREANIM_MISS);
        PlaySE(SE_HAZURE);
    }
    CreateParticleSprites();
}

static void sub_8081370(u16 cmd)
{
    Blender_ControlHitPitch();
    switch (cmd)
    {
    case LINKCMD_BLENDER_SCORE_BEST:
        if (sBerryBlender->speed < 1500) {
            sBerryBlender->speed += (384 / sNumPlayersToSpeedDivisor[sBerryBlender->numPlayers]);
        }
        else
        {
            sBerryBlender->speed += (128 / sNumPlayersToSpeedDivisor[sBerryBlender->numPlayers]);
            sub_80832BC(&sBerryBlender->bg_X, (sBerryBlender->speed / 100) - 10);
            sub_80832BC(&sBerryBlender->bg_Y, (sBerryBlender->speed / 100) - 10);
        }
        break;
    case LINKCMD_BLENDER_SCORE_GOOD:
        if (sBerryBlender->speed < 1500)
            sBerryBlender->speed += (256 / sNumPlayersToSpeedDivisor[sBerryBlender->numPlayers]);
        break;
    case LINKCMD_BLENDER_SCORE_MISS:
        sBerryBlender->speed -= (256 / sNumPlayersToSpeedDivisor[sBerryBlender->numPlayers]);
        if (sBerryBlender->speed < 128)
            sBerryBlender->speed = 128;
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

static void UpdateOpponentScores(void)
{
    s32 i;

    if (gSpecialVar_0x8004 != 0)
    {
        // Local game, simulate NPCs sending link commands
        if (gSendCmd[2] != 0)
        {
            gRecvCmds[0][2] = gSendCmd[2];
            gRecvCmds[0][0] = LINKCMD_SEND_HELD_KEYS;
            gSendCmd[2] = 0;
        }
        for (i = 1; i < BLENDER_MAX_PLAYERS; i++)
        {
            if (gRecvCmds[i][2] != 0)
                gRecvCmds[i][0] = LINKCMD_SEND_HELD_KEYS;
        }
    }
    for (i = 0; i < sBerryBlender->numPlayers; i++)
    {
        if (sub_80814B0(gRecvCmds[i][0], LINKCMD_SEND_HELD_KEYS, LINKCMD_0x4400))
        {
            u32 arrowId = sBerryBlender->field_96[i];
            if (gRecvCmds[i][2] == LINKCMD_BLENDER_SCORE_BEST)
            {
                sub_8081370(LINKCMD_BLENDER_SCORE_BEST);
                sBerryBlender->progressBarValue += (sBerryBlender->speed / 55);
                if (sBerryBlender->progressBarValue >= MAX_PROGRESS_BAR)
                    sBerryBlender->progressBarValue = MAX_PROGRESS_BAR;
                CreateScoreSymbolSprite(LINKCMD_BLENDER_SCORE_BEST, arrowId);
                sBerryBlender->scores[i][SCORE_BEST]++;
            }
            else if (gRecvCmds[i][2] == LINKCMD_BLENDER_SCORE_GOOD)
            {
                sub_8081370(LINKCMD_BLENDER_SCORE_GOOD);
                sBerryBlender->progressBarValue += (sBerryBlender->speed / 70);
                CreateScoreSymbolSprite(LINKCMD_BLENDER_SCORE_GOOD, arrowId);
                sBerryBlender->scores[i][SCORE_GOOD]++;
            }
            else if (gRecvCmds[i][2] == LINKCMD_BLENDER_SCORE_MISS)
            {
                CreateScoreSymbolSprite(LINKCMD_BLENDER_SCORE_MISS, arrowId);
                sub_8081370(LINKCMD_BLENDER_SCORE_MISS);
                if (sBerryBlender->scores[i][SCORE_MISS] < 999)
                    sBerryBlender->scores[i][SCORE_MISS]++;
            }
            if (gRecvCmds[i][2] == LINKCMD_BLENDER_SCORE_MISS 
             || gRecvCmds[2][i] == LINKCMD_BLENDER_SCORE_BEST 
             || gRecvCmds[2][i] == LINKCMD_BLENDER_SCORE_GOOD) // could be a bug, 2 and i are reversed
            {
                if (sBerryBlender->speed > 1500)
                    m4aMPlayTempoControl(&gMPlayInfo_BGM, ((sBerryBlender->speed - 750) / 20) + 256);
                else
                    m4aMPlayTempoControl(&gMPlayInfo_BGM, 0x100);
            }
        }
    }
    if (gSpecialVar_0x8004 != 0)
    {
        for (i = 0; i < sBerryBlender->numPlayers; i++)
        {
            gRecvCmds[i][0] = 0;
            gRecvCmds[i][2] = 0;
        }
    }
}

static void HandlePlayerInput(void)
{
    u8 arrowId;
    bool8 pressedA = FALSE;
    u8 playerId = 0;

    if (gReceivedRemoteLinkPlayers)
        playerId = GetMultiplayerId();

    arrowId = sBerryBlender->field_96[playerId];

    if (sBerryBlender->gameEndState == 0)
    {
        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A && gMain.newKeys & A_BUTTON)
        {
            if ((gMain.heldKeysRaw & (A_BUTTON | L_BUTTON)) != (A_BUTTON | L_BUTTON))
                pressedA = TRUE;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            pressedA = TRUE;
        }

        if (pressedA)
        {
            u8 proximity;
            StartSpriteAnim(&gSprites[sBerryBlender->playerArrowSpriteIds[sBerryBlender->field_8E[arrowId]]], arrowId + 4);
            proximity = GetArrowProximity(sBerryBlender->arrowPos, playerId);

            if (proximity == PROXIMITY_BEST)
                gSendCmd[2] = LINKCMD_BLENDER_SCORE_BEST;
            else if (proximity == PROXIMITY_GOOD)
                gSendCmd[2] = LINKCMD_BLENDER_SCORE_GOOD;
            else
                gSendCmd[2] = LINKCMD_BLENDER_SCORE_MISS;
        }
    }
    if (++sBerryBlender->field_72 > 5)
    {
        if (sBerryBlender->speed > 128)
            sBerryBlender->speed--;
        sBerryBlender->field_72 = 0;
    }
    if (gEnableContestDebugging && gMain.newKeys & L_BUTTON)
        sBerryBlender->field_123 ^= 1;
}

static void CB2_PlayBlender(void)
{
    sub_8082D28();

    if (sBerryBlender->gameFrameTime < (99 * 60 * 60) + (59 * 60)) // game time can't be longer than 99 minutes and 59 seconds, can't print 3 digits
        sBerryBlender->gameFrameTime++;

    HandlePlayerInput();
    SetLinkDebugValues((u16)(sBerryBlender->speed), sBerryBlender->progressBarValue);
    UpdateOpponentScores();
    TryUpdateProgressBar(sBerryBlender->progressBarValue, MAX_PROGRESS_BAR);
    UpdateRPM(sBerryBlender->speed);
    sub_808330C();
    sub_8082AD4();
    if (sBerryBlender->gameEndState == 0 && sBerryBlender->maxProgressBarValue >= MAX_PROGRESS_BAR)
    {
        sBerryBlender->progressBarValue = MAX_PROGRESS_BAR;
        sBerryBlender->gameEndState = 1;
        SetMainCallback2(CB2_HandleBlenderEndGame);
    }

    Blender_DummiedOutFunc(sBerryBlender->bg_X, sBerryBlender->bg_Y);
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

static u32 Blender_GetPokeblockColor(struct BlenderBerry* berries, s16* a1, u8 numPlayers, u8 a3)
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
    for (i = 0; i < numPlayers; i++)
    {
        for (r6 = 0; r6 < numPlayers; r6++)
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

#if MODERN
// TODO remove this as soon as the code below is understood
// add a UBFIX if required (code buggy?)
__attribute__((optimize("no-aggressive-loop-optimizations")))
#endif
static void Blender_CalculatePokeblock(struct BlenderBerry *berries, struct Pokeblock *pokeblock, u8 numPlayers, u8 *flavors, u16 maxRPM)
{
    s32 i, j;
    s32 multiuseVar, var2;
    u8 var3;

    for (i = 0; i < 6; i++)
        sUnknown_03000DE8[i] = 0;

    for (i = 0; i < numPlayers; i++)
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

    pokeblock->color = Blender_GetPokeblockColor(berries, &sUnknown_03000DE8[0], numPlayers, var3);
    sUnknown_03000DE8[5] = (sUnknown_03000DE8[5] / numPlayers) - numPlayers;

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

static void BlenderDebug_CalculatePokeblock(struct BlenderBerry* berries, struct Pokeblock* pokeblock, u8 numPlayers, u8* flavors, u16 maxRPM)
{
    Blender_CalculatePokeblock(berries, pokeblock, numPlayers, flavors, maxRPM);
}

static void sub_8081E20(void)
{
    u32 frames = (u16)(sBerryBlender->gameFrameTime);
    u16 maxRPM = sBerryBlender->maxRPM;
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
    if (maxRPM <= 64)
    {
        if (maxRPM >= 50 && maxRPM < 100)
            var = -1;
        else if (maxRPM >= 100 && maxRPM < 150)
            var = -2;
        else if (maxRPM >= 150 && maxRPM < 200)
            var = -3;
        else if (maxRPM >= 200 && maxRPM < 250)
            var = -4;
        else if (maxRPM >= 250 && maxRPM < 300)
            var = -5;
        else if (maxRPM >= 350 && maxRPM < 400)
            var = -6;
        else if (maxRPM >= 400 && maxRPM < 450)
            var = -7;
        else if (maxRPM >= 500 && maxRPM < 550)
            var = -8;
        else if (maxRPM >= 550 && maxRPM < 600)
            var = -9;
        else if (maxRPM >= 600)
            var = -10;
    }

    sub_8081BB0(var);
}

static void sub_8081F94(u16 *a0)
{
    if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
        *a0 = LINKCMD_0x2F00;
    else
        *a0 = LINKCMD_0x2FFF;
}

static void CB2_HandleBlenderEndGame(void)
{
    u8 i, j;

    if (sBerryBlender->gameEndState < 3)
        sub_8082D28();

    GetMultiplayerId(); // unused return value

    switch (sBerryBlender->gameEndState)
    {
    case 1:
        m4aMPlayTempoControl(&gMPlayInfo_BGM, 256);
        for (i = 0; i < gSpecialVar_0x8004; i++)
        {
            DestroyTask(sBerryBlender->opponentTaskIds[i]);
        }
        sBerryBlender->gameEndState++;
        break;
    case 2:
        sBerryBlender->speed -= 32;
        if (sBerryBlender->speed <= 0)
        {
            ClearLinkCallback();
            sBerryBlender->speed = 0;

            if (gReceivedRemoteLinkPlayers != 0)
                sBerryBlender->gameEndState++;
            else
                sBerryBlender->gameEndState = 5;

            sBerryBlender->mainState = 0;
            m4aMPlayStop(&gMPlayInfo_SE2);
        }
        Blender_ControlHitPitch();
        break;
    case 3:
        if (GetMultiplayerId() != 0)
        {
            sBerryBlender->gameEndState++;
        }
        else if (IsLinkTaskFinished())
        {
            if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
            {
                sBerryBlender->gameBlock.timeRPM.time = sBerryBlender->gameFrameTime;
                sBerryBlender->gameBlock.timeRPM.maxRPM = sBerryBlender->maxRPM;

                for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
                {
                    for (j = 0; j < NUM_SCORE_TYPES; j++)
                        sBerryBlender->gameBlock.scores[i][j] = sBerryBlender->scores[i][j];
                }

                if (SendBlock(0, &sBerryBlender->gameBlock, sizeof(sBerryBlender->gameBlock)))
                    sBerryBlender->gameEndState++;
            }
            else
            {
                sBerryBlender->smallBlock.time = sBerryBlender->gameFrameTime;
                sBerryBlender->smallBlock.maxRPM = sBerryBlender->maxRPM;
                if (SendBlock(0, &sBerryBlender->smallBlock, sizeof(sBerryBlender->smallBlock) + 32))
                    sBerryBlender->gameEndState++;
            }
        }
        break;
    case 4:
        if (GetBlockReceivedStatus())
        {
            ResetBlockReceivedFlags();
            sBerryBlender->gameEndState++;

            if (gReceivedRemoteLinkPlayers != 0 && gWirelessCommType)
            {
                struct BlenderGameBlock *receivedBlock = (struct BlenderGameBlock*)(&gBlockRecvBuffer);

                sBerryBlender->maxRPM = receivedBlock->timeRPM.maxRPM;
                sBerryBlender->gameFrameTime = receivedBlock->timeRPM.time;

                for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
                {
                    for (j = 0; j < NUM_SCORE_TYPES; j++)
                        sBerryBlender->scores[i][j] = receivedBlock->scores[i][j];
                }
            }
            else
            {
                struct TimeAndRPM *receivedBlock = (struct TimeAndRPM*)(&gBlockRecvBuffer);

                sBerryBlender->maxRPM = receivedBlock->maxRPM;
                sBerryBlender->gameFrameTime = receivedBlock->time;
            }
        }
        break;
    case 5:
        if (PrintBlendingRanking())
            sBerryBlender->gameEndState++;
        break;
    case 6:
        if (PrintBlendingResults())
        {
            if (gInGameOpponentsNo == 0)
                IncrementGameStat(GAME_STAT_POKEBLOCKS_WITH_FRIENDS);
            else
                IncrementGameStat(GAME_STAT_POKEBLOCKS);

            sBerryBlender->gameEndState++;
        }
        break;
    case 7:
        if (Blender_PrintText(&sBerryBlender->textState, sText_WouldLikeToBlendAnotherBerry, GetPlayerTextSpeedDelay()))
            sBerryBlender->gameEndState++;
        break;
    case 9:
        sBerryBlender->yesNoAnswer = 0;
        CreateYesNoMenu(&sBlender_YesNoWindowTemplate, 1, 0xD, 0);
        sBerryBlender->gameEndState++;
        break;
    case 10:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 1:
        case -1:
            sBerryBlender->yesNoAnswer = 1;
            sBerryBlender->gameEndState++;
            for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
            {
                if (sBerryBlender->field_8E[i] != 0xFF)
                {
                    PutWindowTilemap(i);
                    CopyWindowToVram(i, 3);
                }
            }
            break;
        case 0:
            sBerryBlender->yesNoAnswer = 0;
            sBerryBlender->gameEndState++;
            for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
            {
                if (sBerryBlender->field_8E[i] != 0xFF)
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
        if (sBerryBlender->yesNoAnswer == 0)
        {
            if (IsBagPocketNonEmpty(POCKET_BERRIES) == FALSE) // no berries
            {
                sBerryBlender->playAgainState = CANT_PLAY_NO_BERRIES;
                gSendCmd[1] = LINKCMD_0x9999;
            }
            else if (GetFirstFreePokeblockSlot() == -1) // no space for pokeblocks
            {
                sBerryBlender->playAgainState = CANT_PLAY_NO_PKBLCK_SPACE;
                gSendCmd[1] = LINKCMD_0xAAAA;
            }
            else
            {
                sBerryBlender->playAgainState = PLAY_AGAIN_OK;
                gSendCmd[1] = LINKCMD_0x7779;
            }
            sBerryBlender->gameEndState++;
        }
        else
        {
            sBerryBlender->playAgainState = DONT_PLAY_AGAIN;
            gSendCmd[1] = LINKCMD_CONT_BLOCK;
            sBerryBlender->gameEndState++;
        }
        break;
    case 12:
        if (gInGameOpponentsNo)
        {
            SetMainCallback2(CB2_HandlePlayerPlayAgainChoice);
            sBerryBlender->gameEndState = 0;
            sBerryBlender->mainState = 0;
        }
        else
        {
            sBerryBlender->gameEndState++;
        }
        break;
    case 8:
        sBerryBlender->gameEndState++;
        break;
    case 13:
        if (Blender_PrintText(&sBerryBlender->textState, sText_CommunicationStandby, GetPlayerTextSpeedDelay()))
        {
            SetMainCallback2(CB2_HandlePlayerLinkPlayAgainChoice);
            sBerryBlender->gameEndState = 0;
            sBerryBlender->mainState = 0;
        }
        break;
    }

    sub_808330C();
    UpdateRPM(sBerryBlender->speed);
    sub_8082AD4();
    Blender_DummiedOutFunc(sBerryBlender->bg_X, sBerryBlender->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static bool8 LinkPlayAgainHandleSaving(void)
{
    switch (sBerryBlender->field_1A0)
    {
    case 0:
        SetLinkStandbyCallback();
        sBerryBlender->field_1A0 = 1;
        sBerryBlender->framesToWait = 0;
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            sBerryBlender->field_1A0++;
            gSoftResetDisabled = TRUE;
        }
        break;
    case 2:
        FullSaveGame();
        sBerryBlender->field_1A0++;
        sBerryBlender->framesToWait = 0;
        break;
    case 3:
        if (++sBerryBlender->framesToWait == 10)
        {
            SetLinkStandbyCallback();
            sBerryBlender->field_1A0++;
        }
        break;
    case 4:
        if (IsLinkTaskFinished())
        {
            if (CheckSaveFile())
            {
                sBerryBlender->field_1A0 = 5;
            }
            else
            {
                sBerryBlender->framesToWait = 0;
                sBerryBlender->field_1A0 = 3;
            }
        }
        break;
    case 5:
        sBerryBlender->field_1A0++;
        sBerryBlender->framesToWait = 0;
        break;
    case 6:
        if (++sBerryBlender->framesToWait > 5)
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
    switch (sBerryBlender->gameEndState)
    {
    case 0:
        if (sBerryBlender->field_64[0] == LINKCMD_SEND_LINK_TYPE)
        {
            sBerryBlender->gameEndState = 5;
        }
        else if (sBerryBlender->field_64[0] == LINKCMD_0x1111)
        {
            if (sBerryBlender->field_6C == LINKCMD_0x9999)
                sBerryBlender->gameEndState = 2;
            else if (sBerryBlender->field_6C == LINKCMD_0xAAAA)
                sBerryBlender->gameEndState = 1;
            else
                sBerryBlender->gameEndState = 5;
        }
        break;
    case 1:
        sBerryBlender->gameEndState = 3;
        StringCopy(gStringVar4, gLinkPlayers[sBerryBlender->field_6E].name);
        StringAppend(gStringVar4, sText_ApostropheSPokeblockCaseIsFull);
        break;
    case 2:
        sBerryBlender->gameEndState++;
        StringCopy(gStringVar4, gLinkPlayers[sBerryBlender->field_6E].name);
        StringAppend(gStringVar4, sText_HasNoBerriesToPut);
        break;
    case 3:
        if (Blender_PrintText(&sBerryBlender->textState, gStringVar4, GetPlayerTextSpeedDelay()))
        {
            sBerryBlender->framesToWait = 0;
            sBerryBlender->gameEndState++;
        }
        break;
    case 4:
        if (++sBerryBlender->framesToWait > 60)
            sBerryBlender->gameEndState = 5;
        break;
    case 5:
        Blender_PrintText(&sBerryBlender->textState, gText_SavingDontTurnOff2, 0);
        SetLinkStandbyCallback();
        sBerryBlender->gameEndState++;
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            sBerryBlender->framesToWait = 0;
            sBerryBlender->gameEndState++;
            sBerryBlender->field_1A0 = 0;
        }
        break;
    case 7:
        if (LinkPlayAgainHandleSaving())
        {
            PlaySE(SE_SAVE);
            sBerryBlender->gameEndState++;
        }
        break;
    case 8:
        sBerryBlender->gameEndState++;
        SetLinkStandbyCallback();
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
            sBerryBlender->gameEndState++;
        }
        break;
    case 10:
        if (!gPaletteFade.active)
        {
            if (sBerryBlender->field_64[0] == LINKCMD_SEND_LINK_TYPE)
            {
                FreeAllWindowBuffers();
                UnsetBgTilemapBuffer(2);
                UnsetBgTilemapBuffer(1);
                FREE_AND_SET_NULL(sBerryBlender);
                SetMainCallback2(DoBerryBlending);
            }
            else
            {
                sBerryBlender->framesToWait = 0;
                sBerryBlender->gameEndState++;
            }
        }
        break;
    case 11:
        if (++sBerryBlender->framesToWait > 30)
        {
            SetCloseLinkCallback();
            sBerryBlender->gameEndState++;
        }
        break;
    case 12:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            FREE_AND_SET_NULL(sBerryBlender);
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        }
        break;
    }

    sub_8082AD4();
    Blender_DummiedOutFunc(sBerryBlender->bg_X, sBerryBlender->bg_Y);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void CB2_HandlePlayerPlayAgainChoice(void)
{
    switch (sBerryBlender->gameEndState)
    {
    case 0:
        if (sBerryBlender->playAgainState == PLAY_AGAIN_OK || sBerryBlender->playAgainState == DONT_PLAY_AGAIN)
            sBerryBlender->gameEndState = 9;
        if (sBerryBlender->playAgainState == CANT_PLAY_NO_BERRIES)
            sBerryBlender->gameEndState = 2;
        if (sBerryBlender->playAgainState == CANT_PLAY_NO_PKBLCK_SPACE)
            sBerryBlender->gameEndState = 1;
        break;
    case 1:
        sBerryBlender->gameEndState = 3;
        sBerryBlender->textState = 0;
        StringCopy(gStringVar4, sText_YourPokeblockCaseIsFull);
        break;
    case 2:
        sBerryBlender->gameEndState++;
        sBerryBlender->textState = 0;
        StringCopy(gStringVar4, sText_RunOutOfBerriesForBlending);
        break;
    case 3:
        if (Blender_PrintText(&sBerryBlender->textState, gStringVar4, GetPlayerTextSpeedDelay()))
            sBerryBlender->gameEndState = 9;
        break;
    case 9:
        BeginFastPaletteFade(3);
        sBerryBlender->gameEndState++;
        break;
    case 10:
        if (!gPaletteFade.active)
        {
            if (sBerryBlender->playAgainState == PLAY_AGAIN_OK)
                SetMainCallback2(DoBerryBlending);
            else
                SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);

            FreeAllWindowBuffers();
            UnsetBgTilemapBuffer(2);
            UnsetBgTilemapBuffer(1);
            FREE_AND_SET_NULL(sBerryBlender);
        }
        break;
    }

    sub_8082AD4();
    Blender_DummiedOutFunc(sBerryBlender->bg_X, sBerryBlender->bg_Y);
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
        if (sub_80814B0(gRecvCmds[0][0], LINKCMD_0x2FFF, LINKCMD_0x2F00))
        {
            if (gRecvCmds[0][1] == LINKCMD_0x1111)
            {
                switch (gRecvCmds[0][2])
                {
                case LINKCMD_CONT_BLOCK:
                    sBerryBlender->field_6C = LINKCMD_CONT_BLOCK;
                    sBerryBlender->field_6E = gRecvCmds[0][3];
                    break;
                case LINKCMD_0x9999:
                    sBerryBlender->field_6C = LINKCMD_0x9999;
                    sBerryBlender->field_6E = gRecvCmds[0][3];
                    break;
                case LINKCMD_0xAAAA:
                    sBerryBlender->field_6C = LINKCMD_0xAAAA;
                    sBerryBlender->field_6E = gRecvCmds[0][3];
                    break;
                }

                sBerryBlender->field_64[0] = LINKCMD_0x1111;
            }
            else if (gRecvCmds[0][1] == LINKCMD_SEND_LINK_TYPE)
            {
                sBerryBlender->field_64[0] = LINKCMD_SEND_LINK_TYPE;
            }
        }
        if (GetMultiplayerId() == 0 && sBerryBlender->field_64[0] != LINKCMD_0x1111 && sBerryBlender->field_64[0] != LINKCMD_SEND_LINK_TYPE)
        {
            u8 i;
            for (i = 0; i < GetLinkPlayerCount(); i++)
            {
                if (sub_80814B0(gRecvCmds[i][0], LINKCMD_0x2FFF, LINKCMD_0x2F00))
                {
                    switch (gRecvCmds[i][1])
                    {
                    case LINKCMD_CONT_BLOCK:
                        sBerryBlender->field_64[i] = LINKCMD_CONT_BLOCK;
                        break;
                    case LINKCMD_0x7779:
                        sBerryBlender->field_64[i] = LINKCMD_0x7779;
                        break;
                    case LINKCMD_0x9999:
                        sBerryBlender->field_64[i] = LINKCMD_0x9999;
                        break;
                    case LINKCMD_0xAAAA:
                        sBerryBlender->field_64[i] = LINKCMD_0xAAAA;
                        break;
                    }
                }
            }
            for (i = 0; i < GetLinkPlayerCount(); i++)
            {
                if (sBerryBlender->field_64[i] == 0)
                    break;
            }
            if (i == GetLinkPlayerCount())
            {
                for (i = 0; i < GetLinkPlayerCount(); i++)
                {
                    if (sBerryBlender->field_64[i] != LINKCMD_0x7779)
                        break;
                }
                sub_8081F94(&gSendCmd[0]);
                if (i == GetLinkPlayerCount())
                {
                    gSendCmd[1] = LINKCMD_SEND_LINK_TYPE;
                }
                else
                {
                    gSendCmd[1] = LINKCMD_0x1111;
                    gSendCmd[2] = sBerryBlender->field_64[i];
                    gSendCmd[3] = i;
                }
            }
        }
    }
}

static void DrawBlenderCenter(struct BgAffineSrcData *dest)
{
    struct BgAffineSrcData affineSrc;

    affineSrc.texX = 0x7800;
    affineSrc.texY = 0x5000;
    affineSrc.scrX = 0x78 - sBerryBlender->bg_X;
    affineSrc.scrY = 0x50 - sBerryBlender->bg_Y;
    affineSrc.sx = sBerryBlender->field_11A;
    affineSrc.sy = sBerryBlender->field_11A;
    affineSrc.alpha = sBerryBlender->arrowPos;

    *dest = affineSrc;
}

u16 GetBlenderArrowPosition(void)
{
    return sBerryBlender->arrowPos;
}

static void sub_8082D28(void)
{
    u8 playerId = 0;

    if (gReceivedRemoteLinkPlayers)
        playerId = GetMultiplayerId();

    if (gWirelessCommType && gReceivedRemoteLinkPlayers != 0)
    {
        if (playerId == 0)
        {
            sBerryBlender->arrowPos += sBerryBlender->speed;
            gSendCmd[5] = sBerryBlender->progressBarValue;
            gSendCmd[6] = sBerryBlender->arrowPos;
            DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
        }
        else
        {
            if ((gRecvCmds[0][0] & 0xFF00) == LINKCMD_0x4400)
            {
                sBerryBlender->progressBarValue = gRecvCmds[0][5];
                sBerryBlender->arrowPos = gRecvCmds[0][6];
                DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
            }
        }
    }
    else
    {
        sBerryBlender->arrowPos += sBerryBlender->speed;
        DrawBlenderCenter(&sBerryBlender->bgAffineSrc);
    }
}

static void BerryBlender_SetBackgroundsPos(void)
{
    SetGpuReg(REG_OFFSET_BG1HOFS, sBerryBlender->bg_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, sBerryBlender->bg_Y);

    SetGpuReg(REG_OFFSET_BG0HOFS, sBerryBlender->bg_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, sBerryBlender->bg_Y);
}

static void SpriteCB_Particle(struct Sprite* sprite)
{
    sprite->data[2] += sprite->data[0];
    sprite->data[3] += sprite->data[1];
    sprite->pos2.x = sprite->data[2] / 8;
    sprite->pos2.y = sprite->data[3] / 8;

    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void CreateParticleSprites(void)
{
    s32 limit = (Random() % 2) + 1;
    s32 i;

    for (i = 0; i < limit; i++)
    {
        u16 rand;
        s32 x, y;
        u8 spriteId;

        rand = sBerryBlender->arrowPos + (Random() % 20);

        x = gSineTable[(rand & 0xFF) + 64] / 4;
        y = gSineTable[(rand & 0xFF)] / 4;

        spriteId = CreateSprite(&sSpriteTemplate_Particles, x + 120, y + 80, 1);
        gSprites[spriteId].data[0] = 16 - (Random() % 32);
        gSprites[spriteId].data[1] = 16 - (Random() % 32);

        gSprites[spriteId].callback = SpriteCB_Particle;
    }
}

static void SpriteCB_ScoreSymbol(struct Sprite* sprite)
{
    sprite->data[0]++;
    sprite->pos2.y = -(sprite->data[0] / 3);

    if (sprite->animEnded)
        DestroySprite(sprite);
}

static void SpriteCB_ScoreSymbolBest(struct Sprite* sprite)
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
    sBerryBlender->chosenItemId[participantId] = itemId;
    ConvertItemToBlenderBerry(&sBerryBlender->blendedBerries[participantId], itemId);
}

#define sState  data[0]
#define sYPos   data[1]
#define sDelay  data[2]
#define sAnimId data[3]

static void SpriteCB_CountdownNumber(struct Sprite* sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->sYPos += 8;
        if (sprite->sYPos > DISPLAY_HEIGHT / 2 + 8)
        {
            sprite->sYPos = DISPLAY_HEIGHT / 2 + 8;
            sprite->sState++;
            PlaySE(SE_KON);
        }
        break;
    case 1:
        if (++sprite->sDelay > 20)
        {
            sprite->sState++;
            sprite->sDelay = 0;
        }
        break;
    case 2:
        sprite->sYPos += 4;
        if (sprite->sYPos > DISPLAY_HEIGHT + 16)
        {
            if (++sprite->sAnimId == 3)
            {
                DestroySprite(sprite);
                CreateSprite(&sSpriteTemplate_Start, 120, -20, 2);
            }
            else
            {
                sprite->sState = 0;
                sprite->sYPos = -16;
                StartSpriteAnim(sprite, sprite->sAnimId);
            }
        }
        break;
    }

    sprite->pos2.y = sprite->sYPos;
}

#undef sState
#undef sYPos
#undef sDelay
#undef sAnimId

static void SpriteCB_Start(struct Sprite* sprite)
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
        if (sprite->data[1] > DISPLAY_HEIGHT + 16)
        {
            sBerryBlender->mainState++;
            DestroySprite(sprite);
        }
        break;
    }

    sprite->pos2.y = sprite->data[1];
}

static void TryUpdateProgressBar(u16 current, u16 limit)
{
    // Progress bar doesn't move unless it's going up
    if (sBerryBlender->maxProgressBarValue < current)
    {
        sBerryBlender->maxProgressBarValue += 2;
        UpdateProgressBar(sBerryBlender->maxProgressBarValue, limit);
    }
}

static void UpdateProgressBar(u16 value, u16 limit)
{
    s32 var1, var2, var3, i;
    u16 *vram;

    vram = (u16*)(BG_SCREEN_ADDR(12));
    var1 = (value * 64) / limit;
    var2 = var1 / 8;
    for (i = 0; i < var2; i++)
    {
        vram[11 + i] = 0x80E9;
        vram[43 + i] = 0x80F9;
    }
    var3 = var1 % 8;
    if (var3 != 0)
    {
        vram[11 + i] = var3 + 0x80E1;
        vram[43 + i] = var3 + 0x80F1;
        i++;
    }
    for (; i < 8; i++)
    {
        vram[11 + i] = 0x80E1;
        vram[43 + i] = 0x80F1;
    }
}

static u32 ArrowSpeedToRPM(u16 speed)
{
    return 60 * 60 * 100 * speed / 65536;
}

static void UpdateRPM(u16 speed)
{
    u8 i;
    u8 digits[5];

    // Check if new max RPM has been reached
    u32 currentRPM = ArrowSpeedToRPM(speed);
    if (sBerryBlender->maxRPM < currentRPM)
        sBerryBlender->maxRPM = currentRPM;

    // Draw the current RPM number at the bottom of the screen
    for (i = 0; i < 5; i++)
    {
        digits[i] = currentRPM % 10;
        currentRPM /= 10;
    }
    *((u16*)(VRAM + 0x6458)) = digits[4] + 0x8072;
    *((u16*)(VRAM + 0x645A)) = digits[3] + 0x8072;
    *((u16*)(VRAM + 0x645C)) = digits[2] + 0x8072;
    *((u16*)(VRAM + 0x6460)) = digits[1] + 0x8072;
    *((u16*)(VRAM + 0x6462)) = digits[0] + 0x8072;
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
    sub_80832E8((s16 *)&sBerryBlender->bg_X);
    sub_80832E8((s16 *)&sBerryBlender->bg_Y);
}

static void sub_8083334(s16* a0, u16 a1)
{
    u8 var;

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
    if (sBerryBlender->framesToWait == 0)
    {
        sBerryBlender->bg_X = 0;
        sBerryBlender->bg_Y = 0;
    }

    sBerryBlender->framesToWait++;
    sub_8083334(&sBerryBlender->bg_X, sBerryBlender->framesToWait);
    sub_8083334(&sBerryBlender->bg_Y, sBerryBlender->framesToWait);

    if (sBerryBlender->framesToWait == 20)
    {
        sBerryBlender->bg_X = 0;
        sBerryBlender->bg_Y = 0;
        return TRUE;
    }

    return FALSE;
}

static void SpriteCB_PlayerArrow(struct Sprite* sprite)
{
   sprite->pos2.x = -(sBerryBlender->bg_X);
   sprite->pos2.y = -(sBerryBlender->bg_Y);
}

static void TryUpdateBerryBlenderRecord(void)
{
    if (gSaveBlock1Ptr->berryBlenderRecords[sBerryBlender->numPlayers - 2] < sBerryBlender->maxRPM)
        gSaveBlock1Ptr->berryBlenderRecords[sBerryBlender->numPlayers - 2] = sBerryBlender->maxRPM;
}

static bool8 PrintBlendingResults(void)
{
    u16 i;
    s32 xPos, yPos;

    struct Pokeblock pokeblock;
    u8 flavors[6];
    u8 text[40];
    u16 berryIds[4]; // unused

    switch (sBerryBlender->mainState)
    {
    case 0:
        sBerryBlender->mainState++;
        sBerryBlender->framesToWait = 17;
        break;
    case 1:
        sBerryBlender->framesToWait -= 10;
        if (sBerryBlender->framesToWait < 0)
        {
            sBerryBlender->framesToWait = 0;
            sBerryBlender->mainState++;
        }
        break;
    case 2:
        if (++sBerryBlender->framesToWait > 20)
        {
            for (i = 0; i < NUM_SCORE_TYPES; i++)
                DestroySprite(&gSprites[sBerryBlender->scoreIconIds[i]]);

            sBerryBlender->framesToWait = 0;
            sBerryBlender->mainState++;
        }
        break;
    case 3:
        {
            u16 minutes, seconds;
            u8 *txtPtr;

            xPos = GetStringCenterAlignXOffset(1, sText_BlendingResults, 0xA8);
            Blender_AddTextPrinter(5, sText_BlendingResults, xPos, 1, TEXT_SPEED_FF, 0);

            if (sBerryBlender->numPlayers == BLENDER_MAX_PLAYERS)
                yPos = 17;
            else
                yPos = 21;

            for (i = 0; i < sBerryBlender->numPlayers; yPos += 16, i++)
            {
                u8 place = sBerryBlender->playerPlaces[i];

                ConvertIntToDecimalStringN(sBerryBlender->stringVar, i + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                StringAppend(sBerryBlender->stringVar, sText_Dot);
                StringAppend(sBerryBlender->stringVar, gText_Space);
                StringAppend(sBerryBlender->stringVar, gLinkPlayers[place].name);
                Blender_AddTextPrinter(5, sBerryBlender->stringVar, 8, yPos, TEXT_SPEED_FF, 3);

                StringCopy(sBerryBlender->stringVar, sBerryBlender->blendedBerries[place].name);
                ConvertInternationalString(sBerryBlender->stringVar, gLinkPlayers[place].language);
                StringAppend(sBerryBlender->stringVar, sText_SpaceBerry);
                Blender_AddTextPrinter(5, sBerryBlender->stringVar, 0x54, yPos, TEXT_SPEED_FF, 3);
            }

            Blender_AddTextPrinter(5, sText_MaximumSpeed, 0, 0x51, TEXT_SPEED_FF, 3);
            ConvertIntToDecimalStringN(sBerryBlender->stringVar, sBerryBlender->maxRPM / 100, STR_CONV_MODE_RIGHT_ALIGN, 3);
            StringAppend(sBerryBlender->stringVar, sText_Dot);

            ConvertIntToDecimalStringN(text, sBerryBlender->maxRPM % 100, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringAppend(sBerryBlender->stringVar, text);
            StringAppend(sBerryBlender->stringVar, sText_RPM);

            xPos = GetStringRightAlignXOffset(1, sBerryBlender->stringVar, 0xA8);
            Blender_AddTextPrinter(5, sBerryBlender->stringVar, xPos, 0x51, TEXT_SPEED_FF, 3);
            Blender_AddTextPrinter(5, sText_Time, 0, 0x61, TEXT_SPEED_FF, 3);

            seconds = (sBerryBlender->gameFrameTime / 60) % 60;
            minutes = (sBerryBlender->gameFrameTime / (60 * 60));

            ConvertIntToDecimalStringN(sBerryBlender->stringVar, minutes, STR_CONV_MODE_LEADING_ZEROS, 2);
            txtPtr = StringAppend(sBerryBlender->stringVar, sText_Min);

            ConvertIntToDecimalStringN(txtPtr, seconds, STR_CONV_MODE_LEADING_ZEROS, 2);
            StringAppend(sBerryBlender->stringVar, sText_Sec);

            xPos = GetStringRightAlignXOffset(1, sBerryBlender->stringVar, 0xA8);
            Blender_AddTextPrinter(5, sBerryBlender->stringVar, xPos, 0x61, TEXT_SPEED_FF, 3);

            sBerryBlender->framesToWait = 0;
            sBerryBlender->mainState++;

            CopyWindowToVram(5, 2);
        }
        break;
    case 4:
        if (gMain.newKeys & A_BUTTON)
            sBerryBlender->mainState++;
        break;
    case 5:
        ClearStdWindowAndFrameToTransparent(5, 1);

        for (i = 0; i < BLENDER_MAX_PLAYERS; i++)
        {
            if (sBerryBlender->chosenItemId[i] != 0)
                berryIds[i] = sBerryBlender->chosenItemId[i] - FIRST_BERRY_INDEX;
            if (sBerryBlender->field_8E[i] != 0xFF)
            {
                PutWindowTilemap(i);
                CopyWindowToVram(i, 3);
            }
        }

        sub_8081E20();

        Blender_CalculatePokeblock(sBerryBlender->blendedBerries, &pokeblock, sBerryBlender->numPlayers, flavors, sBerryBlender->maxRPM);
        Blender_PrintMadePokeblockString(&pokeblock, sBerryBlender->stringVar);
        TryAddContestLinkTvShow(&pokeblock, &sBerryBlender->tvBlender);

        CreateTask(sub_8083F3C, 6);
        IncrementDailyBerryBlender();

        RemoveBagItem(gSpecialVar_ItemId, 1);
        AddPokeblock(&pokeblock);

        sBerryBlender->textState = 0;
        sBerryBlender->mainState++;
        break;
    case 6:
        if (Blender_PrintText(&sBerryBlender->textState, sBerryBlender->stringVar, GetPlayerTextSpeedDelay()))
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

    for (i = 0; i < sBerryBlender->numPlayers; i++)
        places[i] = i;
    for (i = 0; i < sBerryBlender->numPlayers; i++)
    {
        points[i] = 1000000 * sBerryBlender->scores[i][SCORE_BEST];
        points[i] += 1000 * sBerryBlender->scores[i][SCORE_GOOD];
        points[i] += 1000 - sBerryBlender->scores[i][SCORE_MISS];
    }
    Blender_SortBasedOnPoints(places, sBerryBlender->numPlayers, points);
    for (i = 0; i < sBerryBlender->numPlayers; i++)
        sBerryBlender->playerPlaces[i] = places[i];

    if (gReceivedRemoteLinkPlayers == 0)
        playerId = 0;
    else
        playerId = GetMultiplayerId();

    for (i = 0; i < sBerryBlender->numPlayers; i++)
    {
        if (sBerryBlender->playerPlaces[i] == playerId)
            sBerryBlender->field_1A4 = i;
    }
}

static bool8 PrintBlendingRanking(void)
{
    u16 i;
    s32 xPos, yPos;

    switch (sBerryBlender->mainState)
    {
    case 0:
        sBerryBlender->mainState++;
        sBerryBlender->framesToWait = 255;
        break;
    case 1:
        sBerryBlender->framesToWait -= 10;
        if (sBerryBlender->framesToWait < 0)
        {
            sBerryBlender->framesToWait = 0;
            sBerryBlender->mainState++;
        }
        break;
    case 2:
        if (++sBerryBlender->framesToWait > 20)
        {
            sBerryBlender->framesToWait = 0;
            sBerryBlender->mainState++;
        }
        break;
    case 3:
        DrawStdFrameWithCustomTileAndPalette(5, 0, 1, 0xD);
        xPos = GetStringCenterAlignXOffset(1, sText_Ranking, 0xA8);
        Blender_AddTextPrinter(5, sText_Ranking, xPos, 1, TEXT_SPEED_FF, 0);

        sBerryBlender->scoreIconIds[SCORE_BEST] = CreateSprite(&sSpriteTemplate_ScoreSymbols, 128, 52, 0);
        StartSpriteAnim(&gSprites[sBerryBlender->scoreIconIds[SCORE_BEST]], SCOREANIM_BEST_STATIC);
        gSprites[sBerryBlender->scoreIconIds[SCORE_BEST]].callback = SpriteCallbackDummy;

        sBerryBlender->scoreIconIds[SCORE_GOOD] = CreateSprite(&sSpriteTemplate_ScoreSymbols, 160, 52, 0);
        // implicitly uses SCOREANIM_GOOD, no need to assign
        gSprites[sBerryBlender->scoreIconIds[SCORE_GOOD]].callback = SpriteCallbackDummy;

        sBerryBlender->scoreIconIds[SCORE_MISS] = CreateSprite(&sSpriteTemplate_ScoreSymbols, 192, 52, 0);
        StartSpriteAnim(&gSprites[sBerryBlender->scoreIconIds[SCORE_MISS]], SCOREANIM_MISS);
        gSprites[sBerryBlender->scoreIconIds[SCORE_MISS]].callback = SpriteCallbackDummy;

        Blender_SortScores();

        for (yPos = 0x29, i = 0; i < sBerryBlender->numPlayers; yPos += 0x10, i++)
        {
            u8 place = sBerryBlender->playerPlaces[i];

            ConvertIntToDecimalStringN(sBerryBlender->stringVar, i + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
            StringAppend(sBerryBlender->stringVar, sText_Dot);
            StringAppend(sBerryBlender->stringVar, gText_Space);
            StringAppend(sBerryBlender->stringVar, gLinkPlayers[place].name);
            Blender_AddTextPrinter(5, sBerryBlender->stringVar, 0, yPos, TEXT_SPEED_FF, 3);

            ConvertIntToDecimalStringN(sBerryBlender->stringVar, sBerryBlender->scores[place][SCORE_BEST], STR_CONV_MODE_RIGHT_ALIGN, 3);
            Blender_AddTextPrinter(5, sBerryBlender->stringVar, 0x4E, yPos, TEXT_SPEED_FF, 3);

            ConvertIntToDecimalStringN(sBerryBlender->stringVar, sBerryBlender->scores[place][SCORE_GOOD], STR_CONV_MODE_RIGHT_ALIGN, 3);
            Blender_AddTextPrinter(5, sBerryBlender->stringVar, 0x6E, yPos, TEXT_SPEED_FF, 3);

            ConvertIntToDecimalStringN(sBerryBlender->stringVar, sBerryBlender->scores[place][SCORE_MISS], STR_CONV_MODE_RIGHT_ALIGN, 3);
            Blender_AddTextPrinter(5, sBerryBlender->stringVar, 0x8E, yPos, TEXT_SPEED_FF, 3);
        }

        PutWindowTilemap(5);
        CopyWindowToVram(5, 3);

        sBerryBlender->framesToWait = 0;
        sBerryBlender->mainState++;
        break;
    case 4:
        if (++sBerryBlender->framesToWait > 20)
            sBerryBlender->mainState++;
        break;
    case 5:
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sBerryBlender->mainState++;
        }
        break;
    case 6:
        sBerryBlender->mainState = 0;
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

    for (i = 0, yPos = 0x29; i < NUM_SCORE_TYPES; i++)
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
        PlayBGM(sBerryBlender->savedMusic);
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
        if (sBerryBlender->field_1A4 == 0 && sheen > 20)
        {
            StringCopy(tvBlender->name, gLinkPlayers[sBerryBlender->playerPlaces[sBerryBlender->numPlayers - 1]].name);
            tvBlender->pokeblockFlavor = GetPokeblocksFlavor(pokeblock);
            if (Put3CheersForPokeblocksOnTheAir(tvBlender->name, tvBlender->pokeblockFlavor,
                                            tvBlender->pokeblockColor, tvBlender->pokeblockSheen,
                                            gLinkPlayers[sBerryBlender->playerPlaces[sBerryBlender->numPlayers - 1]].language))
            {
                return TRUE;
            }

            return FALSE;
        }
        else if (sBerryBlender->field_1A4 == sBerryBlender->numPlayers - 1 && sheen <= 20)
        {
            StringCopy(tvBlender->name, gLinkPlayers[sBerryBlender->playerPlaces[0]].name);
            tvBlender->pokeblockFlavor = GetPokeblocksFlavor(pokeblock);
            if (Put3CheersForPokeblocksOnTheAir(tvBlender->name, tvBlender->pokeblockFlavor,
                                            tvBlender->pokeblockColor, tvBlender->pokeblockSheen,
                                            gLinkPlayers[sBerryBlender->playerPlaces[0]].language))
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
