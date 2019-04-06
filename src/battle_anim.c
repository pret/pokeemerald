#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "bg.h"
#include "contest.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/battle_anim.h"

#define ANIM_SPRITE_INDEX_COUNT 8

extern struct MusicPlayerInfo gMPlayInfo_BGM;
extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;

extern const u16 gMovesWithQuietBGM[];
extern const u8 *const gBattleAnims_Moves[];
extern const struct BattleAnimBackground gBattleAnimBackgroundTable[];

// this file's functions
static void ScriptCmd_loadspritegfx(void);
static void ScriptCmd_unloadspritegfx(void);
static void ScriptCmd_createsprite(void);
static void ScriptCmd_createvisualtask(void);
static void ScriptCmd_delay(void);
static void ScriptCmd_waitforvisualfinish(void);
static void ScriptCmd_hang1(void);
static void ScriptCmd_hang2(void);
static void ScriptCmd_end(void);
static void ScriptCmd_playse(void);
static void ScriptCmd_monbg(void);
static void ScriptCmd_clearmonbg(void);
static void ScriptCmd_setalpha(void);
static void ScriptCmd_blendoff(void);
static void ScriptCmd_call(void);
static void ScriptCmd_return(void);
static void ScriptCmd_setarg(void);
static void ScriptCmd_choosetwoturnanim(void);
static void ScriptCmd_jumpifmoveturn(void);
static void ScriptCmd_goto(void);
static void ScriptCmd_fadetobg(void);
static void ScriptCmd_restorebg(void);
static void ScriptCmd_waitbgfadeout(void);
static void ScriptCmd_waitbgfadein(void);
static void ScriptCmd_changebg(void);
static void ScriptCmd_playsewithpan(void);
static void ScriptCmd_setpan(void);
static void ScriptCmd_panse_1B(void);
static void ScriptCmd_loopsewithpan(void);
static void ScriptCmd_waitplaysewithpan(void);
static void ScriptCmd_setbldcnt(void);
static void ScriptCmd_createsoundtask(void);
static void ScriptCmd_waitsound(void);
static void ScriptCmd_jumpargeq(void);
static void ScriptCmd_monbg_22(void);
static void ScriptCmd_clearmonbg_23(void);
static void ScriptCmd_jumpifcontest(void);
static void ScriptCmd_fadetobgfromset(void);
static void ScriptCmd_panse_26(void);
static void ScriptCmd_panse_27(void);
static void ScriptCmd_monbgprio_28(void);
static void ScriptCmd_monbgprio_29(void);
static void ScriptCmd_monbgprio_2A(void);
static void ScriptCmd_invisible(void);
static void ScriptCmd_visible(void);
static void ScriptCmd_doublebattle_2D(void);
static void ScriptCmd_doublebattle_2E(void);
static void ScriptCmd_stopsound(void);

static void RunAnimScriptCommand(void);
static void task_pA_ma0A_obj_to_bg_pal(u8 taskId);
static void sub_80A46A0(void);
static void sub_80A4980(u8 taskId);
static void sub_80A4BB0(u8 taskId);
static void Task_FadeToBg(u8 taskId);
static void Task_PanFromInitialToTarget(u8 taskId);
static void Task_LoopAndPlaySE(u8 taskId);
static void Task_WaitAndPlaySE(u8 taskId);
static void LoadDefaultBg(void);
static void LoadMoveBg(u16 bgId);

// ewram
EWRAM_DATA static const u8 *sBattleAnimScriptPtr = NULL;
EWRAM_DATA static const u8 *sBattleAnimScriptRetAddr = NULL;
EWRAM_DATA void (*gAnimScriptCallback)(void) = NULL;
EWRAM_DATA static s8 gAnimFramesToWait = 0;
EWRAM_DATA bool8 gAnimScriptActive = FALSE;
EWRAM_DATA u8 gAnimVisualTaskCount = 0;
EWRAM_DATA u8 gAnimSoundTaskCount = 0;
EWRAM_DATA struct DisableStruct *gAnimDisableStructPtr = NULL;
EWRAM_DATA s32 gAnimMoveDmg = 0;
EWRAM_DATA u16 gAnimMovePower = 0;
EWRAM_DATA static u16 sAnimSpriteIndexArray[ANIM_SPRITE_INDEX_COUNT] = {0};
EWRAM_DATA u8 gAnimFriendship = 0;
EWRAM_DATA u16 gWeatherMoveAnim = 0;
EWRAM_DATA s16 gBattleAnimArgs[ANIM_ARGS_COUNT] = {0};
EWRAM_DATA static u16 sSoundAnimFramesToWait = 0;
EWRAM_DATA static u8 sMonAnimTaskIdArray[2] = {0};
EWRAM_DATA u8 gAnimMoveTurn = 0;
EWRAM_DATA static u8 sAnimBackgroundFadeState = 0;
EWRAM_DATA static u16 sAnimMoveIndex = 0; // Set but unused.
EWRAM_DATA u8 gBattleAnimAttacker = 0;
EWRAM_DATA u8 gBattleAnimTarget = 0;
EWRAM_DATA u16 gAnimBattlerSpecies[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA u8 gUnknown_02038440 = 0;

const struct OamData gUnknown_08524904 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};


const struct OamData gUnknown_0852490C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524914 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852491C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524924 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852492C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524934 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852493C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524944 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852494C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524954 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852495C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524964 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852496C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524974 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852497C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524984 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852498C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524994 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_0852499C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249A4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249AC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249B4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249BC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249C4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249CC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249D4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249DC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249E4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249EC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249F4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_085249FC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A04 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A0C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A14 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A1C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A24 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A2C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A34 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A3C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A44 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A4C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A54 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A5C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A6C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A74 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A7C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A84 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A8C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A94 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524A9C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AA4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AAC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AB4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524ABC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AC4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524ACC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AD4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524ADC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AE4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AEC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AF4 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524AFC =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B04 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B0C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B14 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B1C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B24 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B2C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x32),
    .x = 0,
    .size = SPRITE_SIZE(8x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B34 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct OamData gUnknown_08524B3C =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct CompressedSpriteSheet gBattleAnimPicTable[] =
{
    {gBattleAnimSpriteSheet_Bone, 0x0200, ANIM_TAG_BONE},
    {gBattleAnimSpriteSheet_Spark, 0x0300, ANIM_TAG_SPARK},
    {gBattleAnimSpriteSheet_Pencil, 0x0200, ANIM_TAG_PENCIL},
    {gBattleAnimSpriteSheet_AirWave, 0x0100, ANIM_TAG_AIR_WAVE},
    {gBattleAnimSpriteSheet_Orb, 0x0200, ANIM_TAG_ORB},
    {gBattleAnimSpriteSheet_Sword, 0x0400, ANIM_TAG_SWORD},
    {gBattleAnimSpriteSheet_Seed, 0x0180, ANIM_TAG_SEED},
    {gBattleAnimSpriteSheet_Explosion6, 0x0800, ANIM_TAG_EXPLOSION_6},
    {gBattleAnimSpriteSheet_PinkOrb, 0x0020, ANIM_TAG_PINK_ORB},
    {gBattleAnimSpriteSheet_Gust, 0x0400, ANIM_TAG_GUST},
    {gBattleAnimSpriteSheet_IceCube, 0x1200, ANIM_TAG_ICE_CUBE},
    {gBattleAnimSpriteSheet_Spark2, 0x0180, ANIM_TAG_SPARK_2},
    {gBattleAnimSpriteSheet_Orange, 0x0080, ANIM_TAG_ORANGE},
    {gBattleAnimSpriteSheet_YellowBall, 0x0080, ANIM_TAG_YELLOW_BALL},
    {gBattleAnimSpriteSheet_LockOn, 0x0280, ANIM_TAG_LOCK_ON},
    {gBattleAnimSpriteSheet_TiedBag, 0x0080, ANIM_TAG_TIED_BAG},
    {gBattleAnimSpriteSheet_BlackSmoke, 0x0100, ANIM_TAG_BLACK_SMOKE},
    {gBattleAnimSpriteSheet_BlackBall, 0x0020, ANIM_TAG_BLACK_BALL},
    {gBattleAnimSpriteSheet_Conversion, 0x0080, ANIM_TAG_CONVERSION},
    {gBattleAnimSpriteSheet_Glass, 0x0400, ANIM_TAG_GLASS},
    {gBattleAnimSpriteSheet_HornHit, 0x0200, ANIM_TAG_HORN_HIT},
    {gBattleAnimSpriteSheet_Hit, 0x0A00, ANIM_TAG_HIT},
    {gBattleAnimSpriteSheet_Hit, 0x0A00, ANIM_TAG_HIT_2},
    {gBattleAnimSpriteSheet_BlueShards, 0x0380, ANIM_TAG_BLUE_SHARDS},
    {gBattleAnimSpriteSheet_ClosingEye, 0x0300, ANIM_TAG_CLOSING_EYE},
    {gBattleAnimSpriteSheet_WavingHand, 0x0A00, ANIM_TAG_WAVING_HAND},
    {gBattleAnimSpriteSheet_HitDuplicate, 0x0A00, ANIM_TAG_HIT_DUPLICATE},
    {gBattleAnimSpriteSheet_Leer, 0x0A00, ANIM_TAG_LEER},
    {gBattleAnimSpriteSheet_BlueBurst, 0x0A00, ANIM_TAG_BLUE_BURST},
    {gBattleAnimSpriteSheet_SmallEmber, 0x0A00, ANIM_TAG_SMALL_EMBER},
    {gBattleAnimSpriteSheet_GraySmoke, 0x0A00, ANIM_TAG_GRAY_SMOKE},
    {gBattleAnimSpriteSheet_BlueStar, 0x0E00, ANIM_TAG_BLUE_STAR},
    {gBattleAnimSpriteSheet_BubbleBurst, 0x0380, ANIM_TAG_BUBBLE_BURST},
    {gBattleAnimSpriteSheet_Fire, 0x1000, ANIM_TAG_FIRE},
    {gBattleAnimSpriteSheet_SpinningFire, 0x0800, ANIM_TAG_SPINNING_FIRE},
    {gBattleAnimSpriteSheet_FirePlume, 0x0A00, ANIM_TAG_FIRE_PLUME},
    {gBattleAnimSpriteSheet_Lightning2, 0x0800, ANIM_TAG_LIGHTNING_2},
    {gBattleAnimSpriteSheet_Lightning, 0x0A00, ANIM_TAG_LIGHTNING},
    {gBattleAnimSpriteSheet_ClawSlash2, 0x0A00, ANIM_TAG_CLAW_SLASH_2},
    {gBattleAnimSpriteSheet_ClawSlash, 0x0A00, ANIM_TAG_CLAW_SLASH},
    {gBattleAnimSpriteSheet_Scratch3, 0x0A00, ANIM_TAG_SCRATCH_3},
    {gBattleAnimSpriteSheet_Scratch2, 0x0A00, ANIM_TAG_SCRATCH_2},
    {gBattleAnimSpriteSheet_BubbleBurst2, 0x0A00, ANIM_TAG_BUBBLE_BURST_2},
    {gBattleAnimSpriteSheet_IceChunk, 0x0A00, ANIM_TAG_ICE_CHUNK},
    {gBattleAnimSpriteSheet_Glass2, 0x0A00, ANIM_TAG_GLASS_2},
    {gBattleAnimSpriteSheet_PinkHeart2, 0x0A00, ANIM_TAG_PINK_HEART_2},
    {gBattleAnimSpriteSheet_SapDrip, 0x1000, ANIM_TAG_SAP_DRIP},
    {gBattleAnimSpriteSheet_SapDrip, 0x1000, ANIM_TAG_SAP_DRIP_2},
    {gBattleAnimSpriteSheet_Sparkle1, 0x1000, ANIM_TAG_SPARKLE_1},
    {gBattleAnimSpriteSheet_Sparkle1, 0x1000, ANIM_TAG_SPARKLE_2},
    {gBattleAnimSpriteSheet_HumanoidFoot, 0x0200, ANIM_TAG_HUMANOID_FOOT},
    {gBattleAnimSpriteSheet_MonsterFoot, 0x0200, ANIM_TAG_MONSTER_FOOT},
    {gBattleAnimSpriteSheet_HumanoidHand, 0x0200, ANIM_TAG_HUMANOID_HAND},
    {gBattleAnimSpriteSheet_NoiseLine, 0x0800, ANIM_TAG_NOISE_LINE},
    {gBattleAnimSpriteSheet_YellowUnk, 0x0080, ANIM_TAG_YELLOW_UNK},
    {gBattleAnimSpriteSheet_RedFist, 0x0200, ANIM_TAG_RED_FIST},
    {gBattleAnimSpriteSheet_SlamHit, 0x1000, ANIM_TAG_SLAM_HIT},
    {gBattleAnimSpriteSheet_Ring, 0x0180, ANIM_TAG_RING},
    {gBattleAnimSpriteSheet_Rocks, 0x0C00, ANIM_TAG_ROCKS},
    {gBattleAnimSpriteSheet_Z, 0x0100, ANIM_TAG_Z},
    {gBattleAnimSpriteSheet_YellowUnk2, 0x0040, ANIM_TAG_YELLOW_UNK_2},
    {gBattleAnimSpriteSheet_AirSlash, 0x0180, ANIM_TAG_AIR_SLASH},
    {gBattleAnimSpriteSheet_SpinningGreenOrbs, 0x0800, ANIM_TAG_SPINNING_GREEN_ORBS},
    {gBattleAnimSpriteSheet_Leaf, 0x0480, ANIM_TAG_LEAF},
    {gBattleAnimSpriteSheet_Finger, 0x0200, ANIM_TAG_FINGER},
    {gBattleAnimSpriteSheet_PoisonPowder, 0x0200, ANIM_TAG_POISON_POWDER},
    {gBattleAnimSpriteSheet_BrownTriangle, 0x0100, ANIM_TAG_BROWN_TRIANGLE},
    {gBattleAnimSpriteSheet_PoisonPowder, 0x0200, ANIM_TAG_SLEEP_POWDER},
    {gBattleAnimSpriteSheet_PoisonPowder, 0x0200, ANIM_TAG_STUN_SPORE},
    {gBattleAnimSpriteSheet_PoisonPowder, 0x0200, ANIM_TAG_POWDER},
    {gBattleAnimSpriteSheet_Sparkle3, 0x0200, ANIM_TAG_SPARKLE_3},
    {gBattleAnimSpriteSheet_Sparkle4, 0x0A00, ANIM_TAG_SPARKLE_4},
    {gBattleAnimSpriteSheet_MusicNotes, 0x0300, ANIM_TAG_MUSIC_NOTES},
    {gBattleAnimSpriteSheet_Duck, 0x0180, ANIM_TAG_DUCK},
    {gBattleAnimSpriteSheet_MudSand, 0x00A0, ANIM_TAG_MUD_SAND},
    {gBattleAnimSpriteSheet_Alert, 0x0700, ANIM_TAG_ALERT},
    {gBattleAnimSpriteSheet_BlueFlames, 0x0400, ANIM_TAG_BLUE_FLAMES},
    {gBattleAnimSpriteSheet_BlueFlames2, 0x0200, ANIM_TAG_BLUE_FLAMES_2},
    {gBattleAnimSpriteSheet_Shock4, 0x0300, ANIM_TAG_SHOCK_4},
    {gBattleAnimSpriteSheet_Shock, 0x0C00, ANIM_TAG_SHOCK},
    {gBattleAnimSpriteSheet_Bell2, 0x0A00, ANIM_TAG_BELL_2},
    {gBattleAnimSpriteSheet_PinkGlove, 0x0080, ANIM_TAG_PINK_GLOVE},
    {gBattleAnimSpriteSheet_BlueLines, 0x0040, ANIM_TAG_BLUE_LINES},
    {gBattleAnimSpriteSheet_Impact3, 0x0E00, ANIM_TAG_IMPACT_3},
    {gBattleAnimSpriteSheet_Impact2, 0x0E00, ANIM_TAG_IMPACT_2},
    {gBattleAnimSpriteSheet_Reticle, 0x0280, ANIM_TAG_RETICLE},
    {gBattleAnimSpriteSheet_Breath, 0x0200, ANIM_TAG_BREATH},
    {gBattleAnimSpriteSheet_Anger, 0x0080, ANIM_TAG_ANGER},
    {gBattleAnimSpriteSheet_Snowball, 0x00C0, ANIM_TAG_SNOWBALL},
    {gBattleAnimSpriteSheet_Vine, 0x0A00, ANIM_TAG_VINE},
    {gBattleAnimSpriteSheet_Sword2, 0x0200, ANIM_TAG_SWORD_2},
    {gBattleAnimSpriteSheet_Clapping, 0x0180, ANIM_TAG_CLAPPING},
    {gBattleAnimSpriteSheet_RedTube, 0x0080, ANIM_TAG_RED_TUBE},
    {gBattleAnimSpriteSheet_Amnesia, 0x1000, ANIM_TAG_AMNESIA},
    {gBattleAnimSpriteSheet_String2, 0x0A00, ANIM_TAG_STRING_2},
    {gBattleAnimSpriteSheet_Pencil2, 0x0180, ANIM_TAG_PENCIL_2},
    {gBattleAnimSpriteSheet_Petal, 0x0380, ANIM_TAG_PETAL},
    {gBattleAnimSpriteSheet_BentSpoon, 0x0C00, ANIM_TAG_BENT_SPOON},
    {gBattleAnimSpriteSheet_Web, 0x0200, ANIM_TAG_WEB},
    {gBattleAnimSpriteSheet_MilkBottle, 0x0200, ANIM_TAG_MILK_BOTTLE},
    {gBattleAnimSpriteSheet_Coin, 0x0200, ANIM_TAG_COIN},
    {gBattleAnimSpriteSheet_CrackedEgg, 0x0200, ANIM_TAG_CRACKED_EGG},
    {gBattleAnimSpriteSheet_HatchedEgg, 0x0400, ANIM_TAG_HATCHED_EGG},
    {gBattleAnimSpriteSheet_FreshEgg, 0x0080, ANIM_TAG_FRESH_EGG},
    {gBattleAnimSpriteSheet_Fangs, 0x0400, ANIM_TAG_FANGS},
    {gBattleAnimSpriteSheet_Explosion2, 0x0c00, ANIM_TAG_EXPLOSION_2},
    {gBattleAnimSpriteSheet_Explosion3, 0x0200, ANIM_TAG_EXPLOSION_3},
    {gBattleAnimSpriteSheet_WaterDroplet, 0x1000, ANIM_TAG_WATER_DROPLET},
    {gBattleAnimSpriteSheet_WaterDroplet2, 0x0a00, ANIM_TAG_WATER_DROPLET_2},
    {gBattleAnimSpriteSheet_Seed2, 0x0020, ANIM_TAG_SEED_2},
    {gBattleAnimSpriteSheet_Sprout, 0x0e00, ANIM_TAG_SPROUT},
    {gBattleAnimSpriteSheet_RedWand, 0x0080, ANIM_TAG_RED_WAND},
    {gBattleAnimSpriteSheet_PurpleGreenUnk, 0x0a00, ANIM_TAG_PURPLE_GREEN_UNK},
    {gBattleAnimSpriteSheet_WaterColumn, 0x0400, ANIM_TAG_WATER_COLUMN},
    {gBattleAnimSpriteSheet_MudUnk, 0x0200, ANIM_TAG_MUD_UNK},
    {gBattleAnimSpriteSheet_RainDrops, 0x0700, ANIM_TAG_RAIN_DROPS},
    {gBattleAnimSpriteSheet_FurySwipes, 0x0800, ANIM_TAG_FURY_SWIPES},
    {gBattleAnimSpriteSheet_Vine2, 0x0a00, ANIM_TAG_VINE_2},
    {gBattleAnimSpriteSheet_Teeth, 0x0600, ANIM_TAG_TEETH},
    {gBattleAnimSpriteSheet_Bone2, 0x0800, ANIM_TAG_BONE_2},
    {gBattleAnimSpriteSheet_WhiteBag, 0x0200, ANIM_TAG_WHITE_BAG},
    {gBattleAnimSpriteSheet_Unknown, 0x0040, ANIM_TAG_UNKNOWN},
    {gBattleAnimSpriteSheet_PurpleCoral, 0x0180, ANIM_TAG_PURPLE_CORAL},
    {gBattleAnimSpriteSheet_PurpleDroplet, 0x0600, ANIM_TAG_PURPLE_DROPLET},
    {gBattleAnimSpriteSheet_Shock2, 0x0600, ANIM_TAG_SHOCK_2},
    {gBattleAnimSpriteSheet_ClosingEye2, 0x0200, ANIM_TAG_CLOSING_EYE_2},
    {gBattleAnimSpriteSheet_MetalBall, 0x0080, ANIM_TAG_METAL_BALL},
    {gBattleAnimSpriteSheet_MonsterDoll, 0x0200, ANIM_TAG_MONSTER_DOLL},
    {gBattleAnimSpriteSheet_Whirlwind, 0x0800, ANIM_TAG_WHIRLWIND},
    {gBattleAnimSpriteSheet_Whirlwind2, 0x0080, ANIM_TAG_WHIRLWIND_2},
    {gBattleAnimSpriteSheet_Explosion4, 0x0a00, ANIM_TAG_EXPLOSION_4},
    {gBattleAnimSpriteSheet_Explosion5, 0x0280, ANIM_TAG_EXPLOSION_5},
    {gBattleAnimSpriteSheet_Tongue, 0x0280, ANIM_TAG_TONGUE},
    {gBattleAnimSpriteSheet_Smoke, 0x0100, ANIM_TAG_SMOKE},
    {gBattleAnimSpriteSheet_Smoke2, 0x0200, ANIM_TAG_SMOKE_2},
    {gBattleAnimSpriteSheet_Impact, 0x0200, ANIM_TAG_IMPACT},
    {gBattleAnimSpriteSheet_CircleImpact, 0x0020, ANIM_TAG_CIRCLE_IMPACT},
    {gBattleAnimSpriteSheet_Scratch, 0x0a00, ANIM_TAG_SCRATCH},
    {gBattleAnimSpriteSheet_Cut, 0x0800, ANIM_TAG_CUT},
    {gBattleAnimSpriteSheet_SharpTeeth, 0x0800, ANIM_TAG_SHARP_TEETH},
    {gBattleAnimSpriteSheet_RainbowRings, 0x00c0, ANIM_TAG_RAINBOW_RINGS},
    {gBattleAnimSpriteSheet_IceCrystals, 0x01c0, ANIM_TAG_ICE_CRYSTALS},
    {gBattleAnimSpriteSheet_IceSpikes, 0x0100, ANIM_TAG_ICE_SPIKES},
    {gBattleAnimSpriteSheet_HandsAndFeet, 0x0800, ANIM_TAG_HANDS_AND_FEET},
    {gBattleAnimSpriteSheet_MistCloud, 0x0200, ANIM_TAG_MIST_CLOUD},
    {gBattleAnimSpriteSheet_Clamp, 0x0800, ANIM_TAG_CLAMP},
    {gBattleAnimSpriteSheet_Bubble, 0x0180, ANIM_TAG_BUBBLE},
    {gBattleAnimSpriteSheet_Orbs, 0x0180, ANIM_TAG_ORBS},
    {gBattleAnimSpriteSheet_WaterImpact, 0x0200, ANIM_TAG_WATER_IMPACT},
    {gBattleAnimSpriteSheet_WaterOrb, 0x0200, ANIM_TAG_WATER_ORB},
    {gBattleAnimSpriteSheet_PoisonBubble, 0x0180, ANIM_TAG_POISON_BUBBLE},
    {gBattleAnimSpriteSheet_ToxicBubble, 0x0400, ANIM_TAG_TOXIC_BUBBLE},
    {gBattleAnimSpriteSheet_Spikes, 0x0080, ANIM_TAG_SPIKES},
    {gBattleAnimSpriteSheet_HornHit2, 0x0100, ANIM_TAG_HORN_HIT_2},
    {gBattleAnimSpriteSheet_AirWave2, 0x0100, ANIM_TAG_AIR_WAVE_2},
    {gBattleAnimSpriteSheet_SmallBubbles, 0x0140, ANIM_TAG_SMALL_BUBBLES},
    {gBattleAnimSpriteSheet_RoundShadow, 0x0800, ANIM_TAG_ROUND_SHADOW},
    {gBattleAnimSpriteSheet_Sunlight, 0x0200, ANIM_TAG_SUNLIGHT},
    {gBattleAnimSpriteSheet_Spore, 0x0100, ANIM_TAG_SPORE},
    {gBattleAnimSpriteSheet_Flower, 0x00a0, ANIM_TAG_FLOWER},
    {gBattleAnimSpriteSheet_RazorLeaf, 0x0100, ANIM_TAG_RAZOR_LEAF},
    {gBattleAnimSpriteSheet_Needle, 0x0080, ANIM_TAG_NEEDLE},
    {gBattleAnimSpriteSheet_WhirlwindLines, 0x0300, ANIM_TAG_WHIRLWIND_LINES},
    {gBattleAnimSpriteSheet_GoldRing, 0x0100, ANIM_TAG_GOLD_RING},
    {gBattleAnimSpriteSheet_GoldRing, 0x0100, ANIM_TAG_PURPLE_RING},
    {gBattleAnimSpriteSheet_GoldRing, 0x0100, ANIM_TAG_BLUE_RING},
    {gBattleAnimSpriteSheet_GreenLightWall, 0x0800, ANIM_TAG_GREEN_LIGHT_WALL},
    {gBattleAnimSpriteSheet_GreenLightWall, 0x0800, ANIM_TAG_BLUE_LIGHT_WALL},
    {gBattleAnimSpriteSheet_GreenLightWall, 0x0800, ANIM_TAG_RED_LIGHT_WALL},
    {gBattleAnimSpriteSheet_GreenLightWall, 0x0800, ANIM_TAG_GRAY_LIGHT_WALL},
    {gBattleAnimSpriteSheet_GreenLightWall, 0x0800, ANIM_TAG_ORANGE_LIGHT_WALL},
    {gBattleAnimSpriteSheet_BlackBall2, 0x0080, ANIM_TAG_BLACK_BALL_2},
    {gBattleAnimSpriteSheet_MistCloud, 0x0200, ANIM_TAG_PURPLE_GAS_CLOUD},
    {gBattleAnimSpriteSheet_SparkH, 0x0200, ANIM_TAG_SPARK_H},
    {gBattleAnimSpriteSheet_YellowStar, 0x0200, ANIM_TAG_YELLOW_STAR},
    {gBattleAnimSpriteSheet_LargeFreshEgg, 0x0080, ANIM_TAG_LARGE_FRESH_EGG},
    {gBattleAnimSpriteSheet_ShadowBall, 0x0200, ANIM_TAG_SHADOW_BALL},
    {gBattleAnimSpriteSheet_Lick, 0x0500, ANIM_TAG_LICK},
    {gBattleAnimSpriteSheet_VoidLines, 0x0800, ANIM_TAG_VOID_LINES},
    {gBattleAnimSpriteSheet_String, 0x0400, ANIM_TAG_STRING},
    {gBattleAnimSpriteSheet_WebThread, 0x0020, ANIM_TAG_WEB_THREAD},
    {gBattleAnimSpriteSheet_SpiderWeb, 0x0800, ANIM_TAG_SPIDER_WEB},
    {gBattleAnimSpriteSheet_Lightbulb, 0x0100, ANIM_TAG_LIGHTBULB},
    {gBattleAnimSpriteSheet_Slash, 0x0800, ANIM_TAG_SLASH},
    {gBattleAnimSpriteSheet_FocusEnergy, 0x0400, ANIM_TAG_FOCUS_ENERGY},
    {gBattleAnimSpriteSheet_SphereToCube, 0x0a00, ANIM_TAG_SPHERE_TO_CUBE},
    {gBattleAnimSpriteSheet_Tendrils, 0x1000, ANIM_TAG_TENDRILS},
    {gBattleAnimSpriteSheet_Eye, 0x0800, ANIM_TAG_EYE},
    {gBattleAnimSpriteSheet_WhiteShadow, 0x0400, ANIM_TAG_WHITE_SHADOW},
    {gBattleAnimSpriteSheet_TealAlert, 0x0200, ANIM_TAG_TEAL_ALERT},
    {gBattleAnimSpriteSheet_OpeningEye, 0x0800, ANIM_TAG_OPENING_EYE},
    {gBattleAnimSpriteSheet_RoundWhiteHalo, 0x0800, ANIM_TAG_ROUND_WHITE_HALO},
    {gBattleAnimSpriteSheet_FangAttack, 0x0800, ANIM_TAG_FANG_ATTACK},
    {gBattleAnimSpriteSheet_PurpleHandOutline, 0x0200, ANIM_TAG_PURPLE_HAND_OUTLINE},
    {gBattleAnimSpriteSheet_Moon, 0x0800, ANIM_TAG_MOON},
    {gBattleAnimSpriteSheet_GreenSparkle, 0x0200, ANIM_TAG_GREEN_SPARKLE},
    {gBattleAnimSpriteSheet_Spiral, 0x0800, ANIM_TAG_SPIRAL},
    {gBattleAnimSpriteSheet_SnoreZ, 0x0200, ANIM_TAG_SNORE_Z},
    {gBattleAnimSpriteSheet_Explosion, 0x0800, ANIM_TAG_EXPLOSION},
    {gBattleAnimSpriteSheet_Nail, 0x0400, ANIM_TAG_NAIL},
    {gBattleAnimSpriteSheet_GhostlySpirit, 0x0200, ANIM_TAG_GHOSTLY_SPIRIT},
    {gBattleAnimSpriteSheet_WarmRock, 0x0a80, ANIM_TAG_WARM_ROCK},
    {gBattleAnimSpriteSheet_BreakingEgg, 0x0600, ANIM_TAG_BREAKING_EGG},
    {gBattleAnimSpriteSheet_ThinRing, 0x0800, ANIM_TAG_THIN_RING},
    {gBattleAnimSpriteSheet_PunchImpact, 0x0200, ANIM_TAG_PUNCH_IMPACT},
    {gBattleAnimSpriteSheet_Bell, 0x0600, ANIM_TAG_BELL},
    {gBattleAnimSpriteSheet_MusicNotes2, 0x0800, ANIM_TAG_MUSIC_NOTES_2},
    {gBattleAnimSpriteSheet_SpeedDust, 0x0180, ANIM_TAG_SPEED_DUST},
    {gBattleAnimSpriteSheet_TornMetal, 0x0800, ANIM_TAG_TORN_METAL},
    {gBattleAnimSpriteSheet_ThoughtBubble, 0x0800, ANIM_TAG_THOUGHT_BUBBLE},
    {gBattleAnimSpriteSheet_MagentaHeart, 0x0080, ANIM_TAG_MAGENTA_HEART},
    {gBattleAnimSpriteSheet_ElectricOrbs, 0x0080, ANIM_TAG_ELECTRIC_ORBS},
    {gBattleAnimSpriteSheet_CircleOfLight, 0x0800, ANIM_TAG_CIRCLE_OF_LIGHT},
    {gBattleAnimSpriteSheet_Electricity, 0x0800, ANIM_TAG_ELECTRICITY},
    {gBattleAnimSpriteSheet_Finger2, 0x0600, ANIM_TAG_FINGER_2},
    {gBattleAnimSpriteSheet_MovementWaves, 0x0600, ANIM_TAG_MOVEMENT_WAVES},
    {gBattleAnimSpriteSheet_MagentaHeart, 0x0080, ANIM_TAG_RED_HEART},
    {gBattleAnimSpriteSheet_RedOrb, 0x0080, ANIM_TAG_RED_ORB},
    {gBattleAnimSpriteSheet_EyeSparkle, 0x0180, ANIM_TAG_EYE_SPARKLE},
    {gBattleAnimSpriteSheet_MagentaHeart, 0x0080, ANIM_TAG_PINK_HEART},
    {gBattleAnimSpriteSheet_Angel, 0x0200, ANIM_TAG_ANGEL},
    {gBattleAnimSpriteSheet_Devil, 0x0400, ANIM_TAG_DEVIL},
    {gBattleAnimSpriteSheet_Swipe, 0x0a00, ANIM_TAG_SWIPE},
    {gBattleAnimSpriteSheet_Roots, 0x0800, ANIM_TAG_ROOTS},
    {gBattleAnimSpriteSheet_ItemBag, 0x0200, ANIM_TAG_ITEM_BAG},
    {gBattleAnimSpriteSheet_JaggedMusicNote, 0x0400, ANIM_TAG_JAGGED_MUSIC_NOTE},
    {gBattleAnimSpriteSheet_Pokeball, 0x0080, ANIM_TAG_POKEBALL},
    {gBattleAnimSpriteSheet_Spotlight, 0x0800, ANIM_TAG_SPOTLIGHT},
    {gBattleAnimSpriteSheet_LetterZ, 0x0200, ANIM_TAG_LETTER_Z},
    {gBattleAnimSpriteSheet_RapidSpin, 0x0300, ANIM_TAG_RAPID_SPIN},
    {gBattleAnimSpriteSheet_TriForceTriangle, 0x0800, ANIM_TAG_TRI_FORCE_TRIANGLE},
    {gBattleAnimSpriteSheet_WispOrb, 0x0380, ANIM_TAG_WISP_ORB},
    {gBattleAnimSpriteSheet_WispFire, 0x0800, ANIM_TAG_WISP_FIRE},
    {gBattleAnimSpriteSheet_GoldStars, 0x00c0, ANIM_TAG_GOLD_STARS},
    {gBattleAnimSpriteSheet_EclipsingOrb, 0x0800, ANIM_TAG_ECLIPSING_ORB},
    {gBattleAnimSpriteSheet_GrayOrb, 0x0060, ANIM_TAG_GRAY_ORB},
    {gBattleAnimSpriteSheet_GrayOrb, 0x0060, ANIM_TAG_BLUE_ORB},
    {gBattleAnimSpriteSheet_GrayOrb, 0x0060, ANIM_TAG_RED_ORB_2},
    {gBattleAnimSpriteSheet_PinkPetal, 0x0080, ANIM_TAG_PINK_PETAL},
    {gBattleAnimSpriteSheet_PainSplit, 0x0180, ANIM_TAG_PAIN_SPLIT},
    {gBattleAnimSpriteSheet_Confetti, 0x0180, ANIM_TAG_CONFETTI},
    {gBattleAnimSpriteSheet_GreenStar, 0x0200, ANIM_TAG_GREEN_STAR},
    {gBattleAnimSpriteSheet_PinkCloud, 0x0200, ANIM_TAG_PINK_CLOUD},
    {gBattleAnimSpriteSheet_SweatDrop, 0x0020, ANIM_TAG_SWEAT_DROP},
    {gBattleAnimSpriteSheet_GuardRing, 0x0400, ANIM_TAG_GUARD_RING},
    {gBattleAnimSpriteSheet_PurpleScratch, 0x0600, ANIM_TAG_PURPLE_SCRATCH},
    {gBattleAnimSpriteSheet_PurpleSwipe, 0x1000, ANIM_TAG_PURPLE_SWIPE},
    {gBattleAnimSpriteSheet_TagHand, 0x0400, ANIM_TAG_TAG_HAND},
    {gBattleAnimSpriteSheet_SmallRedEye, 0x0020, ANIM_TAG_SMALL_RED_EYE},
    {gBattleAnimSpriteSheet_HollowOrb, 0x0080, ANIM_TAG_HOLLOW_ORB},
    {gBattleAnimSpriteSheet_XSign, 0x0800, ANIM_TAG_X_SIGN},
    {gBattleAnimSpriteSheet_BluegreenOrb, 0x0080, ANIM_TAG_BLUEGREEN_ORB},
    {gBattleAnimSpriteSheet_PawPrint, 0x0200, ANIM_TAG_PAW_PRINT},
    {gBattleAnimSpriteSheet_PurpleFlame, 0x0400, ANIM_TAG_PURPLE_FLAME},
    {gBattleAnimSpriteSheet_RedBall, 0x0200, ANIM_TAG_RED_BALL},
    {gBattleAnimSpriteSheet_SmellingsaltEffect, 0x0200, ANIM_TAG_SMELLINGSALT_EFFECT},
    {gBattleAnimSpriteSheet_Meteor, 0x0800, ANIM_TAG_METEOR},
    {gBattleAnimSpriteSheet_FlatRock, 0x0280, ANIM_TAG_FLAT_ROCK},
    {gBattleAnimSpriteSheet_MagnifyingGlass, 0x0200, ANIM_TAG_MAGNIFYING_GLASS},
    {gBattleAnimSpriteSheet_WaterOrb, 0x0200, ANIM_TAG_BROWN_ORB},
    {gBattleAnimSpriteSheet_MetalSoundWaves, 0x0400, ANIM_TAG_METAL_SOUND_WAVES},
    {gBattleAnimSpriteSheet_FlyingDirt, 0x0200, ANIM_TAG_FLYING_DIRT},
    {gBattleAnimSpriteSheet_IcicleSpear, 0x0200, ANIM_TAG_ICICLE_SPEAR},
    {gBattleAnimSpriteSheet_Hail, 0x0080, ANIM_TAG_HAIL},
    {gBattleAnimSpriteSheet_GlowyRedOrb, 0x0020, ANIM_TAG_GLOWY_RED_ORB},
    {gBattleAnimSpriteSheet_GlowyRedOrb, 0x0020, ANIM_TAG_GLOWY_GREEN_ORB},
    {gBattleAnimSpriteSheet_GreenSpike, 0x0080, ANIM_TAG_GREEN_SPIKE},
    {gBattleAnimSpriteSheet_CircleOfLight, 0x0800, ANIM_TAG_WHITE_CIRCLE_OF_LIGHT},
    {gBattleAnimSpriteSheet_GlowyRedOrb, 0x0020, ANIM_TAG_GLOWY_BLUE_ORB},
    {gBattleAnimSpriteSheet_RedBrick, 0x0080, ANIM_TAG_RED_BRICK},
    {gBattleAnimSpriteSheet_WhiteFeather, 0x0400, ANIM_TAG_WHITE_FEATHER},
    {gBattleAnimSpriteSheet_Sparkle6, 0x0080, ANIM_TAG_SPARKLE_6},
    {gBattleAnimSpriteSheet_Splash, 0x0800, ANIM_TAG_SPLASH},
    {gBattleAnimSpriteSheet_SweatBead, 0x0020, ANIM_TAG_SWEAT_BEAD},
    {gBattleAnimSpriteSheet_Gem1, 0x0800, ANIM_TAG_GEM_1},
    {gBattleAnimSpriteSheet_Gem2, 0x0800, ANIM_TAG_GEM_2},
    {gBattleAnimSpriteSheet_Gem3, 0x0800, ANIM_TAG_GEM_3},
    {gBattleAnimSpriteSheet_SlamHit2, 0x1000, ANIM_TAG_SLAM_HIT_2},
    {gBattleAnimSpriteSheet_Recycle, 0x0800, ANIM_TAG_RECYCLE},
    {gBattleAnimSpriteSheet_RedParticles, 0x00a0, ANIM_TAG_RED_PARTICLES},
    {gBattleAnimSpriteSheet_Protect, 0x0800, ANIM_TAG_PROTECT},
    {gBattleAnimSpriteSheet_DirtMound, 0x0200, ANIM_TAG_DIRT_MOUND},
    {gBattleAnimSpriteSheet_Shock3, 0x0600, ANIM_TAG_SHOCK_3},
    {gBattleAnimSpriteSheet_WeatherBall, 0x0200, ANIM_TAG_WEATHER_BALL},
    {gBattleAnimSpriteSheet_Bird, 0x0800, ANIM_TAG_BIRD},
    {gBattleAnimSpriteSheet_CrossImpact, 0x0200, ANIM_TAG_CROSS_IMPACT},
    {gBattleAnimSpriteSheet_Slash, 0x0800, ANIM_TAG_SLASH_2},
    {gBattleAnimSpriteSheet_SlamHit, 0x1000, ANIM_TAG_WHIP_HIT},
    {gBattleAnimSpriteSheet_GoldRing, 0x0100, ANIM_TAG_BLUE_RING_2},
};

const struct CompressedSpritePalette gBattleAnimPaletteTable[] =
{
    {gBattleAnimSpritePalette_Bone, ANIM_TAG_BONE},
    {gBattleAnimSpritePalette_Spark, ANIM_TAG_SPARK},
    {gBattleAnimSpritePalette_Pencil, ANIM_TAG_PENCIL},
    {gBattleAnimSpritePalette_AirWave, ANIM_TAG_AIR_WAVE},
    {gBattleAnimSpritePalette_Orb, ANIM_TAG_ORB},
    {gBattleAnimSpritePalette_Sword, ANIM_TAG_SWORD},
    {gBattleAnimSpritePalette_Seed, ANIM_TAG_SEED},
    {gBattleAnimSpritePalette_Explosion6, ANIM_TAG_EXPLOSION_6},
    {gBattleAnimSpritePalette_PinkOrb, ANIM_TAG_PINK_ORB},
    {gBattleAnimSpritePalette_Gust, ANIM_TAG_GUST},
    {gBattleAnimSpritePalette_IceCube, ANIM_TAG_ICE_CUBE},
    {gBattleAnimSpritePalette_Spark2, ANIM_TAG_SPARK_2},
    {gBattleAnimSpritePalette_Orange, ANIM_TAG_ORANGE},
    {gBattleAnimSpritePalette_YellowBall, ANIM_TAG_YELLOW_BALL},
    {gBattleAnimSpritePalette_LockOn, ANIM_TAG_LOCK_ON},
    {gBattleAnimSpritePalette_TiedBag, ANIM_TAG_TIED_BAG},
    {gBattleAnimSpritePalette_BlackSmoke, ANIM_TAG_BLACK_SMOKE},
    {gBattleAnimSpritePalette_BlackSmoke, ANIM_TAG_BLACK_BALL},
    {gBattleAnimSpritePalette_Conversion, ANIM_TAG_CONVERSION},
    {gBattleAnimSpritePalette_Glass, ANIM_TAG_GLASS},
    {gBattleAnimSpritePalette_HornHit, ANIM_TAG_HORN_HIT},
    {gBattleAnimSpritePalette_Hit, ANIM_TAG_HIT},
    {gBattleAnimSpritePalette_Hit2, ANIM_TAG_HIT_2},
    {gBattleAnimSpritePalette_BlueShards, ANIM_TAG_BLUE_SHARDS},
    {gBattleAnimSpritePalette_ClosingEye, ANIM_TAG_CLOSING_EYE},
    {gBattleAnimSpritePalette_WavingHand, ANIM_TAG_WAVING_HAND},
    {gBattleAnimSpritePalette_HitDuplicate, ANIM_TAG_HIT_DUPLICATE},
    {gBattleAnimSpritePalette_Leer, ANIM_TAG_LEER},
    {gBattleAnimSpritePalette_BlueBurst, ANIM_TAG_BLUE_BURST},
    {gBattleAnimSpritePalette_SmallEmber, ANIM_TAG_SMALL_EMBER},
    {gBattleAnimSpritePalette_GraySmoke, ANIM_TAG_GRAY_SMOKE},
    {gBattleAnimSpritePalette_BlueStar, ANIM_TAG_BLUE_STAR},
    {gBattleAnimSpritePalette_BubbleBurst, ANIM_TAG_BUBBLE_BURST},
    {gBattleAnimSpritePalette_Fire, ANIM_TAG_FIRE},
    {gBattleAnimSpritePalette_Fire, ANIM_TAG_SPINNING_FIRE},
    {gBattleAnimSpritePalette_Fire, ANIM_TAG_FIRE_PLUME},
    {gBattleAnimSpritePalette_Lightning2, ANIM_TAG_LIGHTNING_2},
    {gBattleAnimSpritePalette_Lightning2, ANIM_TAG_LIGHTNING},
    {gBattleAnimSpritePalette_ClawSlash2, ANIM_TAG_CLAW_SLASH_2},
    {gBattleAnimSpritePalette_ClawSlash, ANIM_TAG_CLAW_SLASH},
    {gBattleAnimSpritePalette_ClawSlash2, ANIM_TAG_SCRATCH_3},
    {gBattleAnimSpritePalette_ClawSlash2, ANIM_TAG_SCRATCH_2},
    {gBattleAnimSpritePalette_BubbleBurst2, ANIM_TAG_BUBBLE_BURST_2},
    {gBattleAnimSpritePalette_IceChunk, ANIM_TAG_ICE_CHUNK},
    {gBattleAnimSpritePalette_Glass2, ANIM_TAG_GLASS_2},
    {gBattleAnimSpritePalette_PinkHeart2, ANIM_TAG_PINK_HEART_2},
    {gBattleAnimSpritePalette_SapDrip, ANIM_TAG_SAP_DRIP},
    {gBattleAnimSpritePalette_SapDrip2, ANIM_TAG_SAP_DRIP},
    {gBattleAnimSpritePalette_Sparkle1, ANIM_TAG_SPARKLE_1},
    {gBattleAnimSpritePalette_Sparkle2, ANIM_TAG_SPARKLE_2},
    {gBattleAnimSpritePalette_HumanoidFoot, ANIM_TAG_HUMANOID_FOOT},
    {gBattleAnimSpritePalette_HumanoidFoot, ANIM_TAG_MONSTER_FOOT},
    {gBattleAnimSpritePalette_HumanoidFoot, ANIM_TAG_HUMANOID_HAND},
    {gBattleAnimSpritePalette_HitDuplicate, ANIM_TAG_NOISE_LINE},
    {gBattleAnimSpritePalette_YellowUnk, ANIM_TAG_YELLOW_UNK},
    {gBattleAnimSpritePalette_HumanoidFoot, ANIM_TAG_RED_FIST},
    {gBattleAnimSpritePalette_SlamHit, ANIM_TAG_SLAM_HIT},
    {gBattleAnimSpritePalette_Ring, ANIM_TAG_RING},
    {gBattleAnimSpritePalette_Rocks, ANIM_TAG_ROCKS},
    {gBattleAnimSpritePalette_Z, ANIM_TAG_Z},
    {gBattleAnimSpritePalette_YellowUnk2, ANIM_TAG_YELLOW_UNK_2},
    {gBattleAnimSpritePalette_AirSlash, ANIM_TAG_AIR_SLASH},
    {gBattleAnimSpritePalette_SpinningGreenOrbs, ANIM_TAG_SPINNING_GREEN_ORBS},
    {gBattleAnimSpritePalette_Leaf, ANIM_TAG_LEAF},
    {gBattleAnimSpritePalette_Finger, ANIM_TAG_FINGER},
    {gBattleAnimSpritePalette_PoisonPowder, ANIM_TAG_POISON_POWDER},
    {gBattleAnimSpritePalette_BrownTriangle, ANIM_TAG_BROWN_TRIANGLE},
    {gBattleAnimSpritePalette_SleepPowder, ANIM_TAG_SLEEP_POWDER},
    {gBattleAnimSpritePalette_StunSpore, ANIM_TAG_STUN_SPORE},
    {gBattleAnimSpritePalette_PoisonPowder, ANIM_TAG_POWDER},
    {gBattleAnimSpritePalette_Sparkle3, ANIM_TAG_SPARKLE_3},
    {gBattleAnimSpritePalette_Sparkle3, ANIM_TAG_SPARKLE_4},
    {gBattleAnimSpritePalette_MusicNotes, ANIM_TAG_MUSIC_NOTES},
    {gBattleAnimSpritePalette_Duck, ANIM_TAG_DUCK},
    {gBattleAnimSpritePalette_MudSand, ANIM_TAG_MUD_SAND},
    {gBattleAnimSpritePalette_Alert, ANIM_TAG_ALERT},
    {gBattleAnimSpritePalette_BlueFlames, ANIM_TAG_BLUE_FLAMES},
    {gBattleAnimSpritePalette_BlueFlames, ANIM_TAG_BLUE_FLAMES_2},
    {gBattleAnimSpritePalette_Shock4, ANIM_TAG_SHOCK_4},
    {gBattleAnimSpritePalette_Shock4, ANIM_TAG_SHOCK},
    {gBattleAnimSpritePalette_Bell2, ANIM_TAG_BELL_2},
    {gBattleAnimSpritePalette_PinkGlove, ANIM_TAG_PINK_GLOVE},
    {gBattleAnimSpritePalette_BlueLines, ANIM_TAG_BLUE_LINES},
    {gBattleAnimSpritePalette_Impact3, ANIM_TAG_IMPACT_3},
    {gBattleAnimSpritePalette_Impact2, ANIM_TAG_IMPACT_2},
    {gBattleAnimSpritePalette_Reticle, ANIM_TAG_RETICLE},
    {gBattleAnimSpritePalette_Breath, ANIM_TAG_BREATH},
    {gBattleAnimSpritePalette_Anger, ANIM_TAG_ANGER},
    {gBattleAnimSpritePalette_Snowball, ANIM_TAG_SNOWBALL},
    {gBattleAnimSpritePalette_Vine, ANIM_TAG_VINE},
    {gBattleAnimSpritePalette_Sword2, ANIM_TAG_SWORD_2},
    {gBattleAnimSpritePalette_Clapping, ANIM_TAG_CLAPPING},
    {gBattleAnimSpritePalette_RedTube, ANIM_TAG_RED_TUBE},
    {gBattleAnimSpritePalette_Amnesia, ANIM_TAG_AMNESIA},
    {gBattleAnimSpritePalette_String2, ANIM_TAG_STRING_2},
    {gBattleAnimSpritePalette_Pencil2, ANIM_TAG_PENCIL_2},
    {gBattleAnimSpritePalette_Petal, ANIM_TAG_PETAL},
    {gBattleAnimSpritePalette_BentSpoon, ANIM_TAG_BENT_SPOON},
    {gBattleAnimSpritePalette_String2, ANIM_TAG_WEB},
    {gBattleAnimSpritePalette_MilkBottle, ANIM_TAG_MILK_BOTTLE},
    {gBattleAnimSpritePalette_Coin, ANIM_TAG_COIN},
    {gBattleAnimSpritePalette_CrackedEgg, ANIM_TAG_CRACKED_EGG},
    {gBattleAnimSpritePalette_CrackedEgg, ANIM_TAG_HATCHED_EGG},
    {gBattleAnimSpritePalette_FreshEgg, ANIM_TAG_FRESH_EGG},
    {gBattleAnimSpritePalette_Fangs, ANIM_TAG_FANGS},
    {gBattleAnimSpritePalette_Explosion2, ANIM_TAG_EXPLOSION_2},
    {gBattleAnimSpritePalette_Explosion2, ANIM_TAG_EXPLOSION_3},
    {gBattleAnimSpritePalette_WaterDroplet, ANIM_TAG_WATER_DROPLET},
    {gBattleAnimSpritePalette_WaterDroplet, ANIM_TAG_WATER_DROPLET_2},
    {gBattleAnimSpritePalette_Seed2, ANIM_TAG_SEED_2},
    {gBattleAnimSpritePalette_Seed2, ANIM_TAG_SPROUT},
    {gBattleAnimSpritePalette_RedWand, ANIM_TAG_RED_WAND},
    {gBattleAnimSpritePalette_PurpleGreenUnk, ANIM_TAG_PURPLE_GREEN_UNK},
    {gBattleAnimSpritePalette_WaterColumn, ANIM_TAG_WATER_COLUMN},
    {gBattleAnimSpritePalette_MudUnk, ANIM_TAG_MUD_UNK},
    {gBattleAnimSpritePalette_RainDrops, ANIM_TAG_RAIN_DROPS},
    {gBattleAnimSpritePalette_FurySwipes, ANIM_TAG_FURY_SWIPES},
    {gBattleAnimSpritePalette_Vine2, ANIM_TAG_VINE_2},
    {gBattleAnimSpritePalette_Teeth, ANIM_TAG_TEETH},
    {gBattleAnimSpritePalette_Bone2, ANIM_TAG_BONE_2},
    {gBattleAnimSpritePalette_WhiteBag, ANIM_TAG_WHITE_BAG},
    {gBattleAnimSpritePalette_Unknown, ANIM_TAG_UNKNOWN},
    {gBattleAnimSpritePalette_PurpleCoral, ANIM_TAG_PURPLE_CORAL},
    {gBattleAnimSpritePalette_PurpleCoral, ANIM_TAG_PURPLE_DROPLET},
    {gBattleAnimSpritePalette_Shock2, ANIM_TAG_SHOCK_2},
    {gBattleAnimSpritePalette_ClosingEye2, ANIM_TAG_CLOSING_EYE_2},
    {gBattleAnimSpritePalette_MetalBall, ANIM_TAG_METAL_BALL},
    {gBattleAnimSpritePalette_MonsterDoll, ANIM_TAG_MONSTER_DOLL},
    {gBattleAnimSpritePalette_Whirlwind, ANIM_TAG_WHIRLWIND},
    {gBattleAnimSpritePalette_Whirlwind, ANIM_TAG_WHIRLWIND_2},
    {gBattleAnimSpritePalette_Explosion4, ANIM_TAG_EXPLOSION_4},
    {gBattleAnimSpritePalette_Explosion4, ANIM_TAG_EXPLOSION_5},
    {gBattleAnimSpritePalette_Tongue, ANIM_TAG_TONGUE},
    {gBattleAnimSpritePalette_Smoke, ANIM_TAG_SMOKE},
    {gBattleAnimSpritePalette_Smoke, ANIM_TAG_SMOKE_2},
    {gBattleAnimSpritePalette_Impact, ANIM_TAG_IMPACT},
    {gBattleAnimSpritePalette_CircleImpact, ANIM_TAG_CIRCLE_IMPACT},
    {gBattleAnimSpritePalette_Impact, ANIM_TAG_SCRATCH},
    {gBattleAnimSpritePalette_Impact, ANIM_TAG_CUT},
    {gBattleAnimSpritePalette_SharpTeeth, ANIM_TAG_SHARP_TEETH},
    {gBattleAnimSpritePalette_RainbowRings, ANIM_TAG_RAINBOW_RINGS},
    {gBattleAnimSpritePalette_IceCrystals, ANIM_TAG_ICE_CRYSTALS},
    {gBattleAnimSpritePalette_IceCrystals, ANIM_TAG_ICE_SPIKES},
    {gBattleAnimSpritePalette_HandsAndFeet, ANIM_TAG_HANDS_AND_FEET},
    {gBattleAnimSpritePalette_MistCloud, ANIM_TAG_MIST_CLOUD},
    {gBattleAnimSpritePalette_SharpTeeth, ANIM_TAG_CLAMP},
    {gBattleAnimSpritePalette_RainDrops, ANIM_TAG_BUBBLE},
    {gBattleAnimSpritePalette_Orbs, ANIM_TAG_ORBS},
    {gBattleAnimSpritePalette_WaterImpact, ANIM_TAG_WATER_IMPACT},
    {gBattleAnimSpritePalette_WaterImpact, ANIM_TAG_WATER_ORB},
    {gBattleAnimSpritePalette_PoisonBubble, ANIM_TAG_POISON_BUBBLE},
    {gBattleAnimSpritePalette_PoisonBubble, ANIM_TAG_TOXIC_BUBBLE},
    {gBattleAnimSpritePalette_Spikes, ANIM_TAG_SPIKES},
    {gBattleAnimSpritePalette_HornHit2, ANIM_TAG_HORN_HIT_2},
    {gBattleAnimSpritePalette_AirWave2, ANIM_TAG_AIR_WAVE_2},
    {gBattleAnimSpritePalette_SmallBubbles, ANIM_TAG_SMALL_BUBBLES},
    {gBattleAnimSpritePalette_RoundShadow, ANIM_TAG_ROUND_SHADOW},
    {gBattleAnimSpritePalette_Sunlight, ANIM_TAG_SUNLIGHT},
    {gBattleAnimSpritePalette_Spore, ANIM_TAG_SPORE},
    {gBattleAnimSpritePalette_Flower, ANIM_TAG_FLOWER},
    {gBattleAnimSpritePalette_RazorLeaf, ANIM_TAG_RAZOR_LEAF},
    {gBattleAnimSpritePalette_Needle, ANIM_TAG_NEEDLE},
    {gBattleAnimSpritePalette_WhirlwindLines, ANIM_TAG_WHIRLWIND_LINES},
    {gBattleAnimSpritePalette_GoldRing, ANIM_TAG_GOLD_RING},
    {gBattleAnimSpritePalette_PurpleRing, ANIM_TAG_PURPLE_RING},
    {gBattleAnimSpritePalette_BlueRing, ANIM_TAG_BLUE_RING},
    {gBattleAnimSpritePalette_GreenLightWall, ANIM_TAG_GREEN_LIGHT_WALL},
    {gBattleAnimSpritePalette_BlueLightWall, ANIM_TAG_BLUE_LIGHT_WALL},
    {gBattleAnimSpritePalette_RedLightWall, ANIM_TAG_RED_LIGHT_WALL},
    {gBattleAnimSpritePalette_GrayLightWall, ANIM_TAG_GRAY_LIGHT_WALL},
    {gBattleAnimSpritePalette_OrangeLightWall, ANIM_TAG_ORANGE_LIGHT_WALL},
    {gBattleAnimSpritePalette_BlackBall2, ANIM_TAG_BLACK_BALL_2},
    {gBattleAnimSpritePalette_PurpleGasCloud, ANIM_TAG_PURPLE_GAS_CLOUD},
    {gBattleAnimSpritePalette_Spark, ANIM_TAG_SPARK_H},
    {gBattleAnimSpritePalette_YellowStar, ANIM_TAG_YELLOW_STAR},
    {gBattleAnimSpritePalette_LargeFreshEgg, ANIM_TAG_LARGE_FRESH_EGG},
    {gBattleAnimSpritePalette_ShadowBall, ANIM_TAG_SHADOW_BALL},
    {gBattleAnimSpritePalette_Lick, ANIM_TAG_LICK},
    {gBattleAnimSpritePalette_VoidLines, ANIM_TAG_VOID_LINES},
    {gBattleAnimSpritePalette_String, ANIM_TAG_STRING},
    {gBattleAnimSpritePalette_String, ANIM_TAG_WEB_THREAD},
    {gBattleAnimSpritePalette_String, ANIM_TAG_SPIDER_WEB},
    {gBattleAnimSpritePalette_Lightbulb, ANIM_TAG_LIGHTBULB},
    {gBattleAnimSpritePalette_Slash, ANIM_TAG_SLASH},
    {gBattleAnimSpritePalette_FocusEnergy, ANIM_TAG_FOCUS_ENERGY},
    {gBattleAnimSpritePalette_SphereToCube, ANIM_TAG_SPHERE_TO_CUBE},
    {gBattleAnimSpritePalette_Tendrils, ANIM_TAG_TENDRILS},
    {gBattleAnimSpritePalette_Eye, ANIM_TAG_EYE},
    {gBattleAnimSpritePalette_WhiteShadow, ANIM_TAG_WHITE_SHADOW},
    {gBattleAnimSpritePalette_TealAlert, ANIM_TAG_TEAL_ALERT},
    {gBattleAnimSpritePalette_OpeningEye, ANIM_TAG_OPENING_EYE},
    {gBattleAnimSpritePalette_RoundWhiteHalo, ANIM_TAG_ROUND_WHITE_HALO},
    {gBattleAnimSpritePalette_FangAttack, ANIM_TAG_FANG_ATTACK},
    {gBattleAnimSpritePalette_PurpleHandOutline, ANIM_TAG_PURPLE_HAND_OUTLINE},
    {gBattleAnimSpritePalette_Moon, ANIM_TAG_MOON},
    {gBattleAnimSpritePalette_GreenSparkle, ANIM_TAG_GREEN_SPARKLE},
    {gBattleAnimSpritePalette_Spiral, ANIM_TAG_SPIRAL},
    {gBattleAnimSpritePalette_SnoreZ, ANIM_TAG_SNORE_Z},
    {gBattleAnimSpritePalette_Explosion, ANIM_TAG_EXPLOSION},
    {gBattleAnimSpritePalette_Nail, ANIM_TAG_NAIL},
    {gBattleAnimSpritePalette_GhostlySpirit, ANIM_TAG_GHOSTLY_SPIRIT},
    {gBattleAnimSpritePalette_WarmRock, ANIM_TAG_WARM_ROCK},
    {gBattleAnimSpritePalette_BreakingEgg, ANIM_TAG_BREAKING_EGG},
    {gBattleAnimSpritePalette_ThinRing, ANIM_TAG_THIN_RING},
    {gBattleAnimSpritePalette_PunchImpact, ANIM_TAG_PUNCH_IMPACT},
    {gBattleAnimSpritePalette_Bell, ANIM_TAG_BELL},
    {gBattleAnimSpritePalette_MusicNotes2, ANIM_TAG_MUSIC_NOTES_2},
    {gBattleAnimSpritePalette_SpeedDust, ANIM_TAG_SPEED_DUST},
    {gBattleAnimSpritePalette_BlueLightWall, ANIM_TAG_TORN_METAL},
    {gBattleAnimSpritePalette_ThoughtBubble, ANIM_TAG_THOUGHT_BUBBLE},
    {gBattleAnimSpritePalette_MagentaHeart, ANIM_TAG_MAGENTA_HEART},
    {gBattleAnimSpritePalette_ElectricOrbs, ANIM_TAG_ELECTRIC_ORBS},
    {gBattleAnimSpritePalette_ElectricOrbs, ANIM_TAG_CIRCLE_OF_LIGHT},
    {gBattleAnimSpritePalette_ElectricOrbs, ANIM_TAG_ELECTRICITY},
    {gBattleAnimSpritePalette_Finger, ANIM_TAG_FINGER_2},
    {gBattleAnimSpritePalette_MovementWaves, ANIM_TAG_MOVEMENT_WAVES},
    {gBattleAnimSpritePalette_RedHeart, ANIM_TAG_RED_HEART},
    {gBattleAnimSpritePalette_RedOrb, ANIM_TAG_RED_ORB},
    {gBattleAnimSpritePalette_EyeSparkle, ANIM_TAG_EYE_SPARKLE},
    {gBattleAnimSpritePalette_PinkHeart, ANIM_TAG_PINK_HEART},
    {gBattleAnimSpritePalette_Angel, ANIM_TAG_ANGEL},
    {gBattleAnimSpritePalette_Devil, ANIM_TAG_DEVIL},
    {gBattleAnimSpritePalette_Swipe, ANIM_TAG_SWIPE},
    {gBattleAnimSpritePalette_Roots, ANIM_TAG_ROOTS},
    {gBattleAnimSpritePalette_ItemBag, ANIM_TAG_ITEM_BAG},
    {gBattleAnimSpritePalette_JaggedMusicNote, ANIM_TAG_JAGGED_MUSIC_NOTE},
    {gBattleAnimSpritePalette_Pokeball, ANIM_TAG_POKEBALL},
    {gBattleAnimSpritePalette_Pokeball, ANIM_TAG_SPOTLIGHT},
    {gBattleAnimSpritePalette_LetterZ, ANIM_TAG_LETTER_Z},
    {gBattleAnimSpritePalette_RapidSpin, ANIM_TAG_RAPID_SPIN},
    {gBattleAnimSpritePalette_TriForceTriangle, ANIM_TAG_TRI_FORCE_TRIANGLE},
    {gBattleAnimSpritePalette_WispOrb, ANIM_TAG_WISP_ORB},
    {gBattleAnimSpritePalette_WispOrb, ANIM_TAG_WISP_FIRE},
    {gBattleAnimSpritePalette_GoldStars, ANIM_TAG_GOLD_STARS},
    {gBattleAnimSpritePalette_EclipsingOrb, ANIM_TAG_ECLIPSING_ORB},
    {gBattleAnimSpritePalette_GrayOrb, ANIM_TAG_GRAY_ORB},
    {gBattleAnimSpritePalette_BlueOrb, ANIM_TAG_BLUE_ORB},
    {gBattleAnimSpritePalette_RedOrb2, ANIM_TAG_RED_ORB_2},
    {gBattleAnimSpritePalette_PinkPetal, ANIM_TAG_PINK_PETAL},
    {gBattleAnimSpritePalette_PainSplit, ANIM_TAG_PAIN_SPLIT},
    {gBattleAnimSpritePalette_Confetti, ANIM_TAG_CONFETTI},
    {gBattleAnimSpritePalette_GreenStar, ANIM_TAG_GREEN_STAR},
    {gBattleAnimSpritePalette_PinkCloud, ANIM_TAG_PINK_CLOUD},
    {gBattleAnimSpritePalette_SweatDrop, ANIM_TAG_SWEAT_DROP},
    {gBattleAnimSpritePalette_GuardRing, ANIM_TAG_GUARD_RING},
    {gBattleAnimSpritePalette_PurpleScratch, ANIM_TAG_PURPLE_SCRATCH},
    {gBattleAnimSpritePalette_PurpleScratch, ANIM_TAG_PURPLE_SWIPE},
    {gBattleAnimSpritePalette_Finger, ANIM_TAG_TAG_HAND},
    {gBattleAnimSpritePalette_SmallRedEye, ANIM_TAG_SMALL_RED_EYE},
    {gBattleAnimSpritePalette_HollowOrb, ANIM_TAG_HOLLOW_ORB},
    {gBattleAnimSpritePalette_HollowOrb, ANIM_TAG_X_SIGN},
    {gBattleAnimSpritePalette_BluegreenOrb, ANIM_TAG_BLUEGREEN_ORB},
    {gBattleAnimSpritePalette_PawPrint, ANIM_TAG_PAW_PRINT},
    {gBattleAnimSpritePalette_PurpleFlame, ANIM_TAG_PURPLE_FLAME},
    {gBattleAnimSpritePalette_RedBall, ANIM_TAG_RED_BALL},
    {gBattleAnimSpritePalette_SmellingsaltEffect, ANIM_TAG_SMELLINGSALT_EFFECT},
    {gBattleAnimSpritePalette_Meteor, ANIM_TAG_METEOR},
    {gBattleAnimSpritePalette_FlatRock, ANIM_TAG_FLAT_ROCK},
    {gBattleAnimSpritePalette_MagnifyingGlass, ANIM_TAG_MAGNIFYING_GLASS},
    {gBattleAnimSpritePalette_BrownOrb, ANIM_TAG_BROWN_ORB},
    {gBattleAnimSpritePalette_MetalSoundWaves, ANIM_TAG_METAL_SOUND_WAVES},
    {gBattleAnimSpritePalette_FlyingDirt, ANIM_TAG_FLYING_DIRT},
    {gBattleAnimSpritePalette_IcicleSpear, ANIM_TAG_ICICLE_SPEAR},
    {gBattleAnimSpritePalette_Hail, ANIM_TAG_HAIL},
    {gBattleAnimSpritePalette_GlowyRedOrb, ANIM_TAG_GLOWY_RED_ORB},
    {gBattleAnimSpritePalette_GlowyGreenOrb, ANIM_TAG_GLOWY_GREEN_ORB},
    {gBattleAnimSpritePalette_GreenSpike, ANIM_TAG_GREEN_SPIKE},
    {gBattleAnimSpritePalette_WhiteCircleOfLight, ANIM_TAG_WHITE_CIRCLE_OF_LIGHT},
    {gBattleAnimSpritePalette_GlowyBlueOrb, ANIM_TAG_GLOWY_BLUE_ORB},
    {gBattleAnimSpritePalette_RedBrick, ANIM_TAG_RED_BRICK},
    {gBattleAnimSpritePalette_WhiteFeather, ANIM_TAG_WHITE_FEATHER},
    {gBattleAnimSpritePalette_Sparkle6, ANIM_TAG_SPARKLE_6},
    {gBattleAnimSpritePalette_Splash, ANIM_TAG_SPLASH},
    {gBattleAnimSpritePalette_Splash, ANIM_TAG_SWEAT_BEAD},
    {gBattleAnimSpritePalette_Gem1, ANIM_TAG_GEM_1},
    {gBattleAnimSpritePalette_Gem1, ANIM_TAG_GEM_2},
    {gBattleAnimSpritePalette_Gem1, ANIM_TAG_GEM_3},
    {gBattleAnimSpritePalette_SlamHit2, ANIM_TAG_SLAM_HIT_2},
    {gBattleAnimSpritePalette_Recycle, ANIM_TAG_RECYCLE},
    {gBattleAnimSpritePalette_RedParticles, ANIM_TAG_RED_PARTICLES},
    {gBattleAnimSpritePalette_Protect, ANIM_TAG_PROTECT},
    {gBattleAnimSpritePalette_DirtMound, ANIM_TAG_DIRT_MOUND},
    {gBattleAnimSpritePalette_Shock3, ANIM_TAG_SHOCK_3},
    {gBattleAnimSpritePalette_WeatherBall, ANIM_TAG_WEATHER_BALL},
    {gBattleAnimSpritePalette_Bird, ANIM_TAG_BIRD},
    {gBattleAnimSpritePalette_CrossImpact, ANIM_TAG_CROSS_IMPACT},
    {gBattleAnimSpritePalette_Slash2, ANIM_TAG_SLASH_2},
    {gBattleAnimSpritePalette_WhipHit, ANIM_TAG_WHIP_HIT},
    {gBattleAnimSpritePalette_BlueRing2, ANIM_TAG_BLUE_RING_2},
};

const struct BattleAnimBackground gBattleAnimBackgroundTable[] =
{
    {gBattleAnimBackgroundImage_00, gBattleAnimBackgroundPalette_00, gBattleAnimBackgroundTilemap_00},
    {gBattleAnimBackgroundImage_00, gBattleAnimBackgroundPalette_00, gBattleAnimBackgroundTilemap_00},
    {gBattleAnimBackgroundImage_02, gBattleAnimBackgroundPalette_02, gBattleAnimBackgroundTilemap_02},
    {gBattleAnimBackgroundImage_03, gBattleAnimBackgroundPalette_03, gBattleAnimBackgroundTilemap_03},
    {gBattleAnimBackgroundImage_04, gBattleAnimBackgroundPalette_04, gBattleAnimBackgroundTilemap_04},
    {gBattleAnimBackgroundImage_04, gBattleAnimBackgroundPalette_04, gBattleAnimBackgroundTilemap_05},
    {gBattleAnimBackgroundImage_04, gBattleAnimBackgroundPalette_04, gBattleAnimBackgroundTilemap_06},
    {gBattleAnimBackgroundImage_07, gBattleAnimBackgroundPalette_07, gBattleAnimBackgroundTilemap_07},
    {gBattleAnimBackgroundImage_07, gBattleAnimBackgroundPalette_07, gBattleAnimBackgroundTilemap_08},
    {gBattleAnimBackgroundImage_09, gBattleAnimBackgroundPalette_09, gBattleAnimBackgroundTilemap_09},
    {gBattleAnimBackgroundImage_09, gBattleAnimBackgroundPalette_09, gBattleAnimBackgroundTilemap_10},
    {gBattleAnimBackgroundImage_11, gBattleAnimBackgroundPalette_11, gBattleAnimBackgroundTilemap_11},
    {gBattleAnimBackgroundImage_12, gBattleAnimBackgroundPalette_12, gBattleAnimBackgroundTilemap_12},
    {gBattleAnimBackgroundImage_12, gBattleAnimBackgroundPalette_12, gBattleAnimBackgroundTilemap_13},
    {gBattleAnimBackgroundImage_12, gBattleAnimBackgroundPalette_12, gBattleAnimBackgroundTilemap_14},
    {gBattleAnimBackgroundImage_15, gBattleAnimBackgroundPalette_15, gBattleAnimBackgroundTilemap_15},
    {gBattleAnimBackgroundImage_16, gBattleAnimBackgroundPalette_16, gBattleAnimBackgroundTilemap_16},
    {gBattleAnimBackgroundImage_17, gBattleAnimBackgroundPalette_17, gBattleAnimBackgroundTilemap_17},
    {gBattleAnimBackgroundImage_07, gBattleAnimBackgroundPalette_18, gBattleAnimBackgroundTilemap_07},
    {gBattleAnimBackgroundImage_07, gBattleAnimBackgroundPalette_18, gBattleAnimBackgroundTilemap_08},
    {gBattleAnimBackgroundImage_20, gBattleAnimBackgroundPalette_20, gBattleAnimBackgroundTilemap_20},
    {gBattleAnimBackgroundImage_21, gBattleAnimBackgroundPalette_21, gBattleAnimBackgroundTilemap_21},
    {gBattleAnimBackgroundImage_09, gBattleAnimBackgroundPalette_22, gBattleAnimBackgroundTilemap_09},
    {gBattleAnimBackgroundImage_09, gBattleAnimBackgroundPalette_22, gBattleAnimBackgroundTilemap_10},
    {gBattleAnimBackgroundImage_04, gBattleAnimBackgroundPalette_24, gBattleAnimBackgroundTilemap_04},
    {gBattleAnimBackgroundImage_04, gBattleAnimBackgroundPalette_24, gBattleAnimBackgroundTilemap_05},
    {gBattleAnimBackgroundImage_04, gBattleAnimBackgroundPalette_24, gBattleAnimBackgroundTilemap_06},
};

static void (* const sScriptCmdTable[])(void) =
{
    ScriptCmd_loadspritegfx,
    ScriptCmd_unloadspritegfx,
    ScriptCmd_createsprite,
    ScriptCmd_createvisualtask,
    ScriptCmd_delay,
    ScriptCmd_waitforvisualfinish,
    ScriptCmd_hang1,
    ScriptCmd_hang2,
    ScriptCmd_end,
    ScriptCmd_playse,
    ScriptCmd_monbg,
    ScriptCmd_clearmonbg,
    ScriptCmd_setalpha,
    ScriptCmd_blendoff,
    ScriptCmd_call,
    ScriptCmd_return,
    ScriptCmd_setarg,
    ScriptCmd_choosetwoturnanim,
    ScriptCmd_jumpifmoveturn,
    ScriptCmd_goto,
    ScriptCmd_fadetobg,
    ScriptCmd_restorebg,
    ScriptCmd_waitbgfadeout,
    ScriptCmd_waitbgfadein,
    ScriptCmd_changebg,
    ScriptCmd_playsewithpan,
    ScriptCmd_setpan,
    ScriptCmd_panse_1B,
    ScriptCmd_loopsewithpan,
    ScriptCmd_waitplaysewithpan,
    ScriptCmd_setbldcnt,
    ScriptCmd_createsoundtask,
    ScriptCmd_waitsound,
    ScriptCmd_jumpargeq,
    ScriptCmd_monbg_22,
    ScriptCmd_clearmonbg_23,
    ScriptCmd_jumpifcontest,
    ScriptCmd_fadetobgfromset,
    ScriptCmd_panse_26,
    ScriptCmd_panse_27,
    ScriptCmd_monbgprio_28,
    ScriptCmd_monbgprio_29,
    ScriptCmd_monbgprio_2A,
    ScriptCmd_invisible,
    ScriptCmd_visible,
    ScriptCmd_doublebattle_2D,
    ScriptCmd_doublebattle_2E,
    ScriptCmd_stopsound
};

// code
void ClearBattleAnimationVars(void)
{
    s32 i;

    gAnimFramesToWait = 0;
    gAnimScriptActive = FALSE;
    gAnimVisualTaskCount = 0;
    gAnimSoundTaskCount = 0;
    gAnimDisableStructPtr = NULL;
    gAnimMoveDmg = 0;
    gAnimMovePower = 0;
    gAnimFriendship = 0;

    // Clear index array.
    for (i = 0; i < ANIM_SPRITE_INDEX_COUNT; i++)
        sAnimSpriteIndexArray[i] = 0xFFFF;

    // Clear anim args.
    for (i = 0; i < ANIM_ARGS_COUNT; i++)
        gBattleAnimArgs[i] = 0;

    sMonAnimTaskIdArray[0] = 0xFF;
    sMonAnimTaskIdArray[1] = 0xFF;
    gAnimMoveTurn = 0;
    sAnimBackgroundFadeState = 0;
    sAnimMoveIndex = 0;
    gBattleAnimAttacker = 0;
    gBattleAnimTarget = 0;
    gUnknown_02038440 = 0;
}

void DoMoveAnim(u16 move)
{
    gBattleAnimAttacker = gBattlerAttacker;
    gBattleAnimTarget = gBattlerTarget;
    LaunchBattleAnimation(gBattleAnims_Moves, move, TRUE);
}

void LaunchBattleAnimation(const u8 *const animsTable[], u16 tableId, bool8 isMoveAnim)
{
    s32 i;

    if (!IsContest())
    {
        sub_80A8278();
        UpdateOamPriorityInAllHealthboxes(0);
        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (GetBattlerSide(i) != 0)
                gAnimBattlerSpecies[i] = GetMonData(&gEnemyParty[gBattlerPartyIndexes[i]], MON_DATA_SPECIES);
            else
                gAnimBattlerSpecies[i] = GetMonData(&gPlayerParty[gBattlerPartyIndexes[i]], MON_DATA_SPECIES);
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
            gAnimBattlerSpecies[i] = gContestResources->field_18->species;
    }

    if (!isMoveAnim)
        sAnimMoveIndex = 0;
    else
        sAnimMoveIndex = tableId;

    for (i = 0; i < ANIM_ARGS_COUNT; i++)
        gBattleAnimArgs[i] = 0;

    sMonAnimTaskIdArray[0] = 0xFF;
    sMonAnimTaskIdArray[1] = 0xFF;
    sBattleAnimScriptPtr = animsTable[tableId];
    gAnimScriptActive = TRUE;
    gAnimFramesToWait = 0;
    gAnimScriptCallback = RunAnimScriptCommand;

    for (i = 0; i < ANIM_SPRITE_INDEX_COUNT; i++)
        sAnimSpriteIndexArray[i] = 0xFFFF;

    if (isMoveAnim)
    {
        for (i = 0; gMovesWithQuietBGM[i] != 0xFFFF; i++)
        {
            if (tableId == gMovesWithQuietBGM[i])
            {
                m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 128);
                break;
            }
        }
    }

    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
}

void DestroyAnimSprite(struct Sprite *sprite)
{
    FreeSpriteOamMatrix(sprite);
    DestroySprite(sprite);
    gAnimVisualTaskCount--;
}

void DestroyAnimVisualTask(u8 taskId)
{
    DestroyTask(taskId);
    gAnimVisualTaskCount--;
}

void DestroyAnimSoundTask(u8 taskId)
{
    DestroyTask(taskId);
    gAnimSoundTaskCount--;
}

static void AddSpriteIndex(u16 index)
{
    s32 i;

    for (i = 0; i < ANIM_SPRITE_INDEX_COUNT; i++)
    {
        if (sAnimSpriteIndexArray[i] == 0xFFFF)
        {
            sAnimSpriteIndexArray[i] = index;
            return;
        }
    }
}

static void ClearSpriteIndex(u16 index)
{
    s32 i;

    for (i = 0; i < ANIM_SPRITE_INDEX_COUNT; i++)
    {
        if (sAnimSpriteIndexArray[i] == index)
        {
            sAnimSpriteIndexArray[i] = 0xFFFF;
            return;
        }
    }
}

static void WaitAnimFrameCount(void)
{
    if (gAnimFramesToWait <= 0)
    {
        gAnimScriptCallback = RunAnimScriptCommand;
        gAnimFramesToWait = 0;
    }
    else
    {
        gAnimFramesToWait--;
    }
}

static void RunAnimScriptCommand(void)
{
    do
    {
        sScriptCmdTable[sBattleAnimScriptPtr[0]]();
    } while (gAnimFramesToWait == 0 && gAnimScriptActive);
}

static void ScriptCmd_loadspritegfx(void)
{
    u16 index;

    sBattleAnimScriptPtr++;
    index = T1_READ_16(sBattleAnimScriptPtr);
    LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(index)]);
    LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[GET_TRUE_SPRITE_INDEX(index)]);
    sBattleAnimScriptPtr += 2;
    AddSpriteIndex(GET_TRUE_SPRITE_INDEX(index));
    gAnimFramesToWait = 1;
    gAnimScriptCallback = WaitAnimFrameCount;
}

static void ScriptCmd_unloadspritegfx(void)
{
    u16 index;

    sBattleAnimScriptPtr++;
    index = T1_READ_16(sBattleAnimScriptPtr);
    FreeSpriteTilesByTag(gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(index)].tag);
    FreeSpritePaletteByTag(gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(index)].tag);
    sBattleAnimScriptPtr += 2;
    ClearSpriteIndex(GET_TRUE_SPRITE_INDEX(index));
}

static void ScriptCmd_createsprite(void)
{
    s32 i;
    const struct SpriteTemplate *template;
    u8 argVar;
    u8 argsCount;
    s16 subpriority;

    sBattleAnimScriptPtr++;
    template = (const struct SpriteTemplate *)(T2_READ_32(sBattleAnimScriptPtr));
    sBattleAnimScriptPtr += 4;

    argVar = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    argsCount = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    for (i = 0; i < argsCount; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }

    if (argVar & 0x80)
    {
        argVar ^= 0x80;
        if (argVar >= 0x40)
            argVar -= 0x40;
        else
            argVar *= -1;

        subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + (s8)(argVar);
    }
    else
    {
        if (argVar >= 0x40)
            argVar -= 0x40;
        else
            argVar *= -1;

        subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) + (s8)(argVar);
    }

    if (subpriority < 3)
        subpriority = 3;

    CreateSpriteAndAnimate(
        template,
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2),
        GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET),
        subpriority);
    gAnimVisualTaskCount++;
}

static void ScriptCmd_createvisualtask(void)
{
    TaskFunc taskFunc;
    u8 taskPriority;
    u8 taskId;
    u8 numArgs;
    s32 i;

    sBattleAnimScriptPtr++;

    taskFunc = (TaskFunc)T2_READ_32(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr += 4;

    taskPriority = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    numArgs = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    for (i = 0; i < numArgs; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }

    taskId = CreateTask(taskFunc, taskPriority);
    taskFunc(taskId);
    gAnimVisualTaskCount++;
}

static void ScriptCmd_delay(void)
{
    sBattleAnimScriptPtr++;
    gAnimFramesToWait = sBattleAnimScriptPtr[0];
    if (gAnimFramesToWait == 0)
        gAnimFramesToWait = -1;
    sBattleAnimScriptPtr++;
    gAnimScriptCallback = WaitAnimFrameCount;
}

// Wait for visual tasks to finish.
static void ScriptCmd_waitforvisualfinish(void)
{
    if (gAnimVisualTaskCount == 0)
    {
        sBattleAnimScriptPtr++;
        gAnimFramesToWait = 0;
    }
    else
    {
        gAnimFramesToWait = 1;
    }
}

static void ScriptCmd_hang1(void)
{
}

static void ScriptCmd_hang2(void)
{
}

static void ScriptCmd_end(void)
{
    s32 i;
    bool32 continuousAnim = FALSE;

    // Keep waiting as long as there are animations to be done.
    if (gAnimVisualTaskCount != 0 || gAnimSoundTaskCount != 0
     || sMonAnimTaskIdArray[0] != 0xFF || sMonAnimTaskIdArray[1] != 0xFF)
    {
        sSoundAnimFramesToWait = 0;
        gAnimFramesToWait = 1;
        return;
    }

    // Finish the sound effects.
    if (IsSEPlaying())
    {
        if (++sSoundAnimFramesToWait <= 90) // Wait 90 frames, then halt the sound effect.
        {
            gAnimFramesToWait = 1;
            return;
        }
        else
        {
            m4aMPlayStop(&gMPlayInfo_SE1);
            m4aMPlayStop(&gMPlayInfo_SE2);
        }
    }

    // The SE has halted, so set the SE Frame Counter to 0 and continue.
    sSoundAnimFramesToWait = 0;

    for (i = 0; i < ANIM_SPRITE_INDEX_COUNT; i++)
    {
        if (sAnimSpriteIndexArray[i] != 0xFFFF)
        {
            FreeSpriteTilesByTag(gBattleAnimPicTable[sAnimSpriteIndexArray[i]].tag);
            FreeSpritePaletteByTag(gBattleAnimPicTable[sAnimSpriteIndexArray[i]].tag);
            sAnimSpriteIndexArray[i] = 0xFFFF; // set terminator.
        }
    }

    if (!continuousAnim) // May have been used for debug?
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 256);
        if (!IsContest())
        {
            sub_80A8278();
            UpdateOamPriorityInAllHealthboxes(1);
        }
        gAnimScriptActive = FALSE;
    }
}

static void ScriptCmd_playse(void)
{
    sBattleAnimScriptPtr++;
    PlaySE(T1_READ_16(sBattleAnimScriptPtr));
    sBattleAnimScriptPtr += 2;
}

#define t1_MONBG_BATTLER        0
#define t1_MON_IN_BG2           1
#define t1_CREATE_ANOTHER_TASK  2
#define t1_IS_SECONDMON_BG      3

#define t2_BATTLER_SPRITE_ID    0
#define t2_MON_IN_BG2           5
#define t2_MONBG_BATTLER        6

static void sub_80A40F4(u8 taskId)
{
    u8 newTaskId;

    s16 *selfData = gTasks[taskId].data;
    u8 battlerSpriteId = gBattlerSpriteIds[selfData[t1_MONBG_BATTLER]];
    gSprites[battlerSpriteId].invisible = TRUE;

    if (!selfData[t1_CREATE_ANOTHER_TASK])
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    newTaskId = CreateTask(task_pA_ma0A_obj_to_bg_pal, 10);
    gTasks[newTaskId].data[t2_BATTLER_SPRITE_ID] = battlerSpriteId;
    gTasks[newTaskId].data[1] = gSprites[battlerSpriteId].pos1.x + gSprites[battlerSpriteId].pos2.x;
    gTasks[newTaskId].data[2] = gSprites[battlerSpriteId].pos1.y + gSprites[battlerSpriteId].pos2.y;

    if (!selfData[t1_MON_IN_BG2])
    {
        gTasks[newTaskId].data[3] = gBattle_BG1_X;
        gTasks[newTaskId].data[4] = gBattle_BG1_Y;
    }
    else
    {
        gTasks[newTaskId].data[3] = gBattle_BG2_X;
        gTasks[newTaskId].data[4] = gBattle_BG2_Y;
    }

    gTasks[newTaskId].data[t2_MON_IN_BG2] = selfData[t1_MON_IN_BG2];
    gTasks[newTaskId].data[t2_MONBG_BATTLER] = selfData[t1_MONBG_BATTLER];
    sMonAnimTaskIdArray[selfData[t1_IS_SECONDMON_BG]] = newTaskId;
    DestroyAnimVisualTask(taskId);
}

static void ScriptCmd_monbg(void)
{
    bool8 toBG_2;
    u8 taskId;
    u8 battlerId;
    u8 animBattler;

    sBattleAnimScriptPtr++;

    animBattler = sBattleAnimScriptPtr[0];
    if (animBattler & ANIM_TARGET)
        battlerId = gBattleAnimTarget;
    else
        battlerId = gBattleAnimAttacker;

    if (IsBattlerSpriteVisible(battlerId))
    {
        u8 position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battlerId, toBG_2, FALSE);
        taskId = CreateTask(sub_80A40F4, 10);
        gAnimVisualTaskCount++;
        gTasks[taskId].data[t1_MONBG_BATTLER] = battlerId;
        gTasks[taskId].data[t1_MON_IN_BG2] = toBG_2;
        gTasks[taskId].data[t1_CREATE_ANOTHER_TASK] = TRUE;
        gTasks[taskId].data[t1_IS_SECONDMON_BG] = 0;

    }

    battlerId ^= BIT_FLANK;
    if (IsBattlerSpriteVisible(battlerId))
    {
        u8 position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battlerId, toBG_2, FALSE);
        taskId = CreateTask(sub_80A40F4, 10);
        gAnimVisualTaskCount++;
        gTasks[taskId].data[0] = battlerId;
        gTasks[taskId].data[1] = toBG_2;
        gTasks[taskId].data[t1_CREATE_ANOTHER_TASK] = TRUE;
        gTasks[taskId].data[t1_IS_SECONDMON_BG] = 1;
    }

    sBattleAnimScriptPtr++;
    gAnimFramesToWait = 1;
    gAnimScriptCallback = WaitAnimFrameCount;
}

bool8 IsBattlerSpriteVisible(u8 battlerId)
{
    if (IsContest())
    {
        if (battlerId == gBattleAnimAttacker)
            return TRUE;
        else
            return FALSE;
    }
    if (!IsBattlerSpritePresent(battlerId))
        return FALSE;
    if (IsContest())
        return TRUE; // This line won't ever be reached.
    if (!gBattleSpritesDataPtr->battlerData[battlerId].invisible || !gSprites[gBattlerSpriteIds[battlerId]].invisible)
        return TRUE;

    return FALSE;
}

void MoveBattlerSpriteToBG(u8 battlerId, bool8 toBG_2, bool8 setSpriteInvisible)
{
    struct BattleAnimBgData animBg;
    u8 battlerSpriteId;

    if (!toBG_2)
    {
        u8 battlerPosition;

        if (IsContest() == TRUE)
        {
            RequestDma3Fill(0, (void*)(BG_SCREEN_ADDR(16)), 0x2000, 1);
            RequestDma3Fill(0xFF, (void*)(BG_SCREEN_ADDR(30)), 0x1000, 0);
        }
        else
        {
            RequestDma3Fill(0, (void*)(BG_SCREEN_ADDR(8)), 0x2000, 1);
            RequestDma3Fill(0xFF, (void*)(BG_SCREEN_ADDR(28)), 0x1000, 0);
        }

        sub_80A6B30(&animBg);
        CpuFill16(0, animBg.bgTiles, 0x1000);
        CpuFill16(0xFF, animBg.bgTilemap, 0x800);

        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 2);
        SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 1);
        SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 0);

        battlerSpriteId = gBattlerSpriteIds[battlerId];

        gBattle_BG1_X =  -(gSprites[battlerSpriteId].pos1.x + gSprites[battlerSpriteId].pos2.x) + 0x20;
        if (IsContest() && IsSpeciesNotUnown(gContestResources->field_18->species))
            gBattle_BG1_X--;

        gBattle_BG1_Y =  -(gSprites[battlerSpriteId].pos1.y + gSprites[battlerSpriteId].pos2.y) + 0x20;
        if (setSpriteInvisible)
            gSprites[gBattlerSpriteIds[battlerId]].invisible = TRUE;

        SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
        SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

        LoadPalette(&gPlttBufferUnfaded[0x100 + battlerId * 16], animBg.paletteId * 16, 0x20);
        CpuCopy32(&gPlttBufferUnfaded[0x100 + battlerId * 16], (void*)(BG_PLTT + animBg.paletteId * 32), 0x20);

        if (IsContest())
            battlerPosition = 0;
        else
            battlerPosition = GetBattlerPosition(battlerId);

        sub_8118FBC(1, 0, 0, battlerPosition, animBg.paletteId, animBg.bgTiles, animBg.bgTilemap, animBg.tilesOffset);

        if (IsContest())
            sub_80A46A0();
    }
    else
    {
        RequestDma3Fill(0, (void*)(BG_SCREEN_ADDR(12)), 0x2000, 1);
        RequestDma3Fill(0, (void*)(BG_SCREEN_ADDR(30)), 0x1000, 1);
        sub_80A6B90(&animBg, 2);
        CpuFill16(0, animBg.bgTiles + 0x1000, 0x1000);
        CpuFill16(0, animBg.bgTilemap + 0x400, 0x800);
        SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
        SetAnimBgAttribute(2, BG_ANIM_SCREEN_SIZE, 1);
        SetAnimBgAttribute(2, BG_ANIM_AREA_OVERFLOW_MODE, 0);

        battlerSpriteId = gBattlerSpriteIds[battlerId];

        gBattle_BG2_X =  -(gSprites[battlerSpriteId].pos1.x + gSprites[battlerSpriteId].pos2.x) + 0x20;
        gBattle_BG2_Y =  -(gSprites[battlerSpriteId].pos1.y + gSprites[battlerSpriteId].pos2.y) + 0x20;

        if (setSpriteInvisible)
            gSprites[gBattlerSpriteIds[battlerId]].invisible = TRUE;

        SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
        SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);

        LoadPalette(&gPlttBufferUnfaded[0x100 + battlerId * 16], 0x90, 0x20);
        CpuCopy32(&gPlttBufferUnfaded[0x100 + battlerId * 16], (void*)(BG_PLTT + 0x120), 0x20);

        sub_8118FBC(2, 0, 0, GetBattlerPosition(battlerId), animBg.paletteId, animBg.bgTiles + 0x1000, animBg.bgTilemap + 0x400, animBg.tilesOffset);
    }
}

static void sub_80A46A0(void)
{
    s32 i, j;
    struct BattleAnimBgData animBg;
    u16 *ptr;

    if (IsSpeciesNotUnown(gContestResources->field_18->species))
    {
        sub_80A6B30(&animBg);
        ptr = animBg.bgTilemap;
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 4; j++)
            {
                u16 temp = ptr[j + i * 32];

                ptr[j + i * 32] = ptr[7 - j + i * 32];
                ptr[7 - j + i * 32] = temp;
            }
        }
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
                ptr[j + i * 32] ^= 0x400;
        }
    }
}

void sub_80A4720(u16 a, u16 *b, u32 c, u8 d)
{
    s32 i, j;
    s32 var;

    if (d == 0)
        var = 32;
    else
        var = 64;
    a <<= 12;
    for (i = 0; i < var; i++)
    {
        for (j = 0; j < 32; j++)
            b[j + i * 32] = ((b[j + i * 32] & 0xFFF) | a) + c;
    }
}

void sub_80A477C(bool8 to_BG2)
{
    struct BattleAnimBgData animBg;
    sub_80A6B30(&animBg);

    if (!to_BG2 || IsContest())
    {
        sub_80A6C68(1);
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
    }
    else
    {
        sub_80A6C68(2);
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
    }
}

static void task_pA_ma0A_obj_to_bg_pal(u8 taskId)
{
    u8 spriteId, palIndex;
    s16 x, y;
    struct BattleAnimBgData animBg;

    spriteId = gTasks[taskId].data[0];
    palIndex = gTasks[taskId].data[6];
    sub_80A6B30(&animBg);
    x = gTasks[taskId].data[1] - (gSprites[spriteId].pos1.x + gSprites[spriteId].pos2.x);
    y = gTasks[taskId].data[2] - (gSprites[spriteId].pos1.y + gSprites[spriteId].pos2.y);

    if (gTasks[taskId].data[5] == 0)
    {
        u16 *src;
        u16 *dst;

        gBattle_BG1_X = x + gTasks[taskId].data[3];
        gBattle_BG1_Y = y + gTasks[taskId].data[4];
        src = gPlttBufferFaded + 0x100 + palIndex * 16;
        dst = gPlttBufferFaded + 0x100 + animBg.paletteId * 16 - 256;
        CpuCopy32(src, dst, 0x20);
    }
    else
    {
        u16 *src;
        u16 *dst;

        gBattle_BG2_X = x + gTasks[taskId].data[3];
        gBattle_BG2_Y = y + gTasks[taskId].data[4];
        src = gPlttBufferFaded + 0x100 + palIndex * 16;
        dst = gPlttBufferFaded + 0x100 - 112;
        CpuCopy32(src, dst, 0x20);
    }
}

static void ScriptCmd_clearmonbg(void)
{
    u8 animBattlerId;
    u8 battlerId;
    u8 taskId;

    sBattleAnimScriptPtr++;
    animBattlerId = sBattleAnimScriptPtr[0];

    if (animBattlerId == ANIM_ATTACKER)
        animBattlerId = ANIM_ATK_PARTNER;
    else if (animBattlerId == ANIM_TARGET)
        animBattlerId = ANIM_DEF_PARTNER;

    if (animBattlerId == ANIM_ATTACKER || animBattlerId == ANIM_ATK_PARTNER)
        battlerId = gBattleAnimAttacker;
    else
        battlerId = gBattleAnimTarget;

    if (sMonAnimTaskIdArray[0] != 0xFF)
        gSprites[gBattlerSpriteIds[battlerId]].invisible = FALSE;
    if (animBattlerId > 1 && sMonAnimTaskIdArray[1] != 0xFF)
        gSprites[gBattlerSpriteIds[battlerId ^ BIT_FLANK]].invisible = FALSE;
    else
        animBattlerId = 0;

    taskId = CreateTask(sub_80A4980, 5);
    gTasks[taskId].data[0] = animBattlerId;
    gTasks[taskId].data[2] = battlerId;

    sBattleAnimScriptPtr++;
}

static void sub_80A4980(u8 taskId)
{
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] != 1)
    {
        u8 to_BG2;
        u8 position = GetBattlerPosition(gTasks[taskId].data[2]);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            to_BG2 = FALSE;
        else
            to_BG2 = TRUE;

        if (sMonAnimTaskIdArray[0] != 0xFF)
        {
            sub_80A477C(to_BG2);
            DestroyTask(sMonAnimTaskIdArray[0]);
            sMonAnimTaskIdArray[0] = 0xFF;
        }
        if (gTasks[taskId].data[0] > 1)
        {
            sub_80A477C(to_BG2 ^ 1);
            DestroyTask(sMonAnimTaskIdArray[1]);
            sMonAnimTaskIdArray[1] = 0xFF;
        }
        DestroyTask(taskId);
    }
}

static void ScriptCmd_monbg_22(void)
{
    bool8 toBG_2;
    u8 battlerId;
    u8 animBattlerId;

    sBattleAnimScriptPtr++;

    animBattlerId = sBattleAnimScriptPtr[0];

    if (animBattlerId == ANIM_ATTACKER)
        animBattlerId = ANIM_ATK_PARTNER;
    else if (animBattlerId == ANIM_TARGET)
        animBattlerId = ANIM_DEF_PARTNER;

    if (animBattlerId == ANIM_ATTACKER || animBattlerId == ANIM_ATK_PARTNER)
        battlerId = gBattleAnimAttacker;
    else
        battlerId = gBattleAnimTarget;

    if (IsBattlerSpriteVisible(battlerId))
    {
        u8 position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battlerId, toBG_2, FALSE);
    }

    battlerId ^= BIT_FLANK;
    if (animBattlerId > 1 && IsBattlerSpriteVisible(battlerId))
    {
        u8 position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        MoveBattlerSpriteToBG(battlerId, toBG_2, FALSE);
    }

    sBattleAnimScriptPtr++;
}

static void ScriptCmd_clearmonbg_23(void)
{
    u8 animBattlerId;
    u8 battlerId;
    u8 taskId;

    sBattleAnimScriptPtr++;
    animBattlerId = sBattleAnimScriptPtr[0];

    if (animBattlerId == ANIM_ATTACKER)
        animBattlerId = ANIM_ATK_PARTNER;
    else if (animBattlerId == ANIM_TARGET)
        animBattlerId = ANIM_DEF_PARTNER;

    if (animBattlerId == ANIM_ATTACKER || animBattlerId == ANIM_ATK_PARTNER)
        battlerId = gBattleAnimAttacker;
    else
        battlerId = gBattleAnimTarget;

    if (IsBattlerSpriteVisible(battlerId))
        gSprites[gBattlerSpriteIds[battlerId]].invisible = FALSE;
    if (animBattlerId > 1 && IsBattlerSpriteVisible(battlerId ^ BIT_FLANK))
        gSprites[gBattlerSpriteIds[battlerId ^ BIT_FLANK]].invisible = FALSE;
    else
        animBattlerId = 0;

    taskId = CreateTask(sub_80A4BB0, 5);
    gTasks[taskId].data[0] = animBattlerId;
    gTasks[taskId].data[2] = battlerId;

    sBattleAnimScriptPtr++;
}

static void sub_80A4BB0(u8 taskId)
{
    gTasks[taskId].data[1]++;
    if (gTasks[taskId].data[1] != 1)
    {
        bool8 toBG_2;
        u8 battlerId = gTasks[taskId].data[2];
        u8 position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        if (IsBattlerSpriteVisible(battlerId))
            sub_80A477C(toBG_2);
        if (gTasks[taskId].data[0] > 1 && IsBattlerSpriteVisible(battlerId ^ BIT_FLANK))
            sub_80A477C(toBG_2 ^ 1);

        DestroyTask(taskId);
    }
}

#undef t1_MONBG_BATTLER
#undef t1_MON_IN_BG2
#undef t1_CREATE_ANOTHER_TASK
#undef t1_IS_SECONDMON_BG

#undef t2_BATTLER_SPRITE_ID
#undef t2_MON_IN_BG2
#undef t2_MONBG_BATTLER

static void ScriptCmd_setalpha(void)
{
    u16 half1, half2;

    sBattleAnimScriptPtr++;
    half1 = *(sBattleAnimScriptPtr++);
    half2 = *(sBattleAnimScriptPtr++) << 8;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, half1 | half2);
}

static void ScriptCmd_setbldcnt(void)
{
    u16 half1, half2;

    sBattleAnimScriptPtr++;
    half1 = *(sBattleAnimScriptPtr++);
    half2 = *(sBattleAnimScriptPtr++) << 8;
    SetGpuReg(REG_OFFSET_BLDCNT, half1 | half2);
}

static void ScriptCmd_blendoff(void)
{
    sBattleAnimScriptPtr++;
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
}

static void ScriptCmd_call(void)
{
    sBattleAnimScriptPtr++;
    sBattleAnimScriptRetAddr = sBattleAnimScriptPtr + 4;
    sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
}

static void ScriptCmd_return(void)
{
    sBattleAnimScriptPtr = sBattleAnimScriptRetAddr;
}

static void ScriptCmd_setarg(void)
{
    const u8 *addr = sBattleAnimScriptPtr;
    u16 value;
    u8 argId;

    sBattleAnimScriptPtr++;
    argId = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    value = T1_READ_16(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr = addr + 4;
    gBattleAnimArgs[argId] = value;
}

static void ScriptCmd_choosetwoturnanim(void)
{
    sBattleAnimScriptPtr++;
    if (gAnimMoveTurn & 1)
        sBattleAnimScriptPtr += 4;
    sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
}

static void ScriptCmd_jumpifmoveturn(void)
{
    u8 toCheck;
    sBattleAnimScriptPtr++;
    toCheck = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;

    if (toCheck == gAnimMoveTurn)
        sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
    else
        sBattleAnimScriptPtr += 4;
}

static void ScriptCmd_goto(void)
{
    sBattleAnimScriptPtr++;
    sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
}

// Uses of this function that rely on a TRUE return are expecting inBattle to not be ticked as defined in contest behavior. As a result, if misused, this function cannot reliably discern between field and contest status and could result in undefined behavior.
bool8 IsContest(void)
{
    if (!gMain.inBattle)
        return TRUE;
    else
        return FALSE;
}

#define tBackgroundId   data[0]
#define tState          data[10]

static void ScriptCmd_fadetobg(void)
{
    u8 backgroundId;
    u8 taskId;

    sBattleAnimScriptPtr++;
    backgroundId = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    taskId = CreateTask(Task_FadeToBg, 5);
    gTasks[taskId].tBackgroundId = backgroundId;
    sAnimBackgroundFadeState = 1;
}

static void ScriptCmd_fadetobgfromset(void)
{
    u8 bg1, bg2, bg3;
    u8 taskId;

    sBattleAnimScriptPtr++;
    bg1 = sBattleAnimScriptPtr[0];
    bg2 = sBattleAnimScriptPtr[1];
    bg3 = sBattleAnimScriptPtr[2];
    sBattleAnimScriptPtr += 3;
    taskId = CreateTask(Task_FadeToBg, 5);

    if (IsContest())
        gTasks[taskId].tBackgroundId = bg3;
    else if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        gTasks[taskId].tBackgroundId = bg2;
    else
        gTasks[taskId].tBackgroundId = bg1;

    sAnimBackgroundFadeState = 1;
}

static void Task_FadeToBg(u8 taskId)
{
    if (gTasks[taskId].tState == 0)
    {
        BeginHardwarePaletteFade(0xE8, 0, 0, 16, 0);
        gTasks[taskId].tState++;
        return;
    }
    if (gPaletteFade.active)
        return;
    if (gTasks[taskId].tState == 1)
    {
        gTasks[taskId].tState++;
        sAnimBackgroundFadeState = 2;
    }
    else if (gTasks[taskId].tState == 2)
    {
        s16 bgId = gTasks[taskId].tBackgroundId;

        if (bgId == -1)
            LoadDefaultBg();
        else
            LoadMoveBg(bgId);

        BeginHardwarePaletteFade(0xE8, 0, 16, 0, 1);
        gTasks[taskId].tState++;
        return;
    }
    if (gPaletteFade.active)
        return;
    if (gTasks[taskId].tState == 3)
    {
        DestroyTask(taskId);
        sAnimBackgroundFadeState = 0;
    }
}

static void LoadMoveBg(u16 bgId)
{
    if (IsContest())
    {
        const u32 *tilemap = gBattleAnimBackgroundTable[bgId].tilemap;
        void *dmaSrc;
        void *dmaDest;

        LZDecompressWram(tilemap, gDecompressionBuffer);
        sub_80A4720(sub_80A6D94(), (void*)(gDecompressionBuffer), 0x100, 0);
        dmaSrc = gDecompressionBuffer;
        dmaDest = (void *)(BG_SCREEN_ADDR(26));
        DmaCopy32(3, dmaSrc, dmaDest, 0x800);
        LZDecompressVram(gBattleAnimBackgroundTable[bgId].image, (void *)(BG_SCREEN_ADDR(4)));
        LoadCompressedPalette(gBattleAnimBackgroundTable[bgId].palette, sub_80A6D94() * 16, 32);
    }
    else
    {
        LZDecompressVram(gBattleAnimBackgroundTable[bgId].tilemap, (void *)(BG_SCREEN_ADDR(26)));
        LZDecompressVram(gBattleAnimBackgroundTable[bgId].image, (void *)(BG_CHAR_ADDR(2)));
        LoadCompressedPalette(gBattleAnimBackgroundTable[bgId].palette, 32, 32);
    }
}

static void LoadDefaultBg(void)
{
    if (IsContest())
        LoadContestBgAfterMoveAnim();
    else
        DrawMainBattleBackground();
}

static void ScriptCmd_restorebg(void)
{
    u8 taskId;

    sBattleAnimScriptPtr++;
    taskId = CreateTask(Task_FadeToBg, 5);
    gTasks[taskId].tBackgroundId = -1;
    sAnimBackgroundFadeState = 1;
}

#undef tBackgroundId
#undef tState

static void ScriptCmd_waitbgfadeout(void)
{
    if (sAnimBackgroundFadeState == 2)
    {
        sBattleAnimScriptPtr++;
        gAnimFramesToWait = 0;
    }
    else
    {
        gAnimFramesToWait = 1;
    }
}

static void ScriptCmd_waitbgfadein(void)
{
    if (sAnimBackgroundFadeState == 0)
    {
        sBattleAnimScriptPtr++;
        gAnimFramesToWait = 0;
    }
    else
    {
        gAnimFramesToWait = 1;
    }
}

static void ScriptCmd_changebg(void)
{
    sBattleAnimScriptPtr++;
    LoadMoveBg(sBattleAnimScriptPtr[0]);
    sBattleAnimScriptPtr++;
}

s8 BattleAnimAdjustPanning(s8 pan)
{
    if (!IsContest() && gBattleSpritesDataPtr->healthBoxesData[gBattleAnimAttacker].statusAnimActive)
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            pan = SOUND_PAN_TARGET;
        else
            pan = SOUND_PAN_ATTACKER;
    }
    else if (IsContest())
    {
        if (gBattleAnimAttacker != gBattleAnimTarget || gBattleAnimAttacker != 2 || pan != SOUND_PAN_TARGET)
            pan *= -1;
    }
    else if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        {
            if (pan == SOUND_PAN_TARGET)
                pan = SOUND_PAN_ATTACKER;
            else if (pan != SOUND_PAN_ATTACKER)
                pan *= -1;
        }
    }
    else if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT)
    {
        if (pan == SOUND_PAN_ATTACKER)
            pan = SOUND_PAN_TARGET;
    }
    else
    {
        pan *= -1;
    }

    if (pan > SOUND_PAN_TARGET)
        pan = SOUND_PAN_TARGET;
    else if (pan < SOUND_PAN_ATTACKER)
        pan = SOUND_PAN_ATTACKER;

    return pan;
}

s8 BattleAnimAdjustPanning2(s8 pan)
{
    if (!IsContest() && gBattleSpritesDataPtr->healthBoxesData[gBattleAnimAttacker].statusAnimActive)
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            pan = SOUND_PAN_TARGET;
        else
            pan = SOUND_PAN_ATTACKER;
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER || IsContest())
            pan = -pan;
    }
    return pan;
}

s16 KeepPanInRange(s16 panArg)
{
    s16 pan = panArg;

    if (pan > SOUND_PAN_TARGET)
        pan = SOUND_PAN_TARGET;
    else if (pan < SOUND_PAN_ATTACKER)
        pan = SOUND_PAN_ATTACKER;

    return pan;
}

s16 CalculatePanIncrement(s16 sourcePan, s16 targetPan, s16 incrementPan)
{
    s16 ret;

    if (sourcePan < targetPan)
        ret = ((incrementPan < 0) ? -incrementPan : incrementPan);
    else if (sourcePan > targetPan)
        ret = -((incrementPan < 0) ? -incrementPan : incrementPan);
    else
        ret = 0;

    return ret;
}

static void ScriptCmd_playsewithpan(void)
{
    u16 songId;
    s8 pan;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    pan = sBattleAnimScriptPtr[2];
    PlaySE12WithPanning(songId, BattleAnimAdjustPanning(pan));
    sBattleAnimScriptPtr += 3;
}

static void ScriptCmd_setpan(void)
{
    s8 pan;

    sBattleAnimScriptPtr++;
    pan = sBattleAnimScriptPtr[0];
    SE12PanpotControl(BattleAnimAdjustPanning(pan));
    sBattleAnimScriptPtr++;
}

#define tInitialPan     data[0]
#define tTargetPan      data[1]
#define tIncrementPan   data[2]
#define tFramesToWait   data[3]
#define tCurrentPan     data[4]
#define tFrameCounter   data[8]

static void ScriptCmd_panse_1B(void)
{
    u16 songNum;
    s8 currentPanArg, incrementPan, incrementPanArg, currentPan, targetPan;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songNum = T1_READ_16(sBattleAnimScriptPtr);
    currentPanArg = sBattleAnimScriptPtr[2];
    incrementPan = sBattleAnimScriptPtr[3];
    incrementPanArg = sBattleAnimScriptPtr[4];
    framesToWait = sBattleAnimScriptPtr[5];

    currentPan = BattleAnimAdjustPanning(currentPanArg);
    targetPan = BattleAnimAdjustPanning(incrementPan);
    incrementPan = CalculatePanIncrement(currentPan, targetPan, incrementPanArg);
    taskId = CreateTask(Task_PanFromInitialToTarget, 1);
    gTasks[taskId].tInitialPan = currentPan;
    gTasks[taskId].tTargetPan = targetPan;
    gTasks[taskId].tIncrementPan = incrementPan;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tCurrentPan = currentPan;

    PlaySE12WithPanning(songNum, currentPan);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 6;
}

void Task_PanFromInitialToTarget(u8 taskId)
{
    bool32 destroyTask = FALSE;
    if (gTasks[taskId].tFrameCounter++ >= gTasks[taskId].tFramesToWait)
    {
        s16 pan;
        s16 initialPanning, targetPanning, currentPan, incrementPan;

        gTasks[taskId].tFrameCounter = 0;
        initialPanning = gTasks[taskId].tInitialPan;
        targetPanning = gTasks[taskId].tTargetPan;
        currentPan = gTasks[taskId].tCurrentPan;
        incrementPan = gTasks[taskId].tIncrementPan;
        pan = currentPan + incrementPan;
        gTasks[taskId].tCurrentPan = pan;

        if (incrementPan == 0) // If we're not incrementing, just cancel the task immediately.
        {
            destroyTask = TRUE;
        }
        else if (initialPanning < targetPanning) // Panning increasing.
        {
            if (pan >= targetPanning) // Target reached.
                destroyTask = TRUE;
        }
        else // Panning decreasing.
        {
            if (pan <= targetPanning) // Target reached.
                destroyTask = TRUE;
        }

        if (destroyTask)
        {
            pan = targetPanning;
            DestroyTask(taskId);
            gAnimSoundTaskCount--;
        }

        SE12PanpotControl(pan);
    }
}

static void ScriptCmd_panse_26(void)
{
    u16 songId;
    s8 currentPan, targetPan, incrementPan;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    currentPan = sBattleAnimScriptPtr[2];
    targetPan = sBattleAnimScriptPtr[3];
    incrementPan = sBattleAnimScriptPtr[4];
    framesToWait = sBattleAnimScriptPtr[5];

    taskId = CreateTask(Task_PanFromInitialToTarget, 1);
    gTasks[taskId].tInitialPan = currentPan;
    gTasks[taskId].tTargetPan = targetPan;
    gTasks[taskId].tIncrementPan = incrementPan;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tCurrentPan = currentPan;

    PlaySE12WithPanning(songId, currentPan);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 6;
}

static void ScriptCmd_panse_27(void)
{
    u16 songId;
    s8 targetPanArg, incrementPanArg, currentPanArg, currentPan, targetPan, incrementPan;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    currentPanArg = sBattleAnimScriptPtr[2];
    targetPanArg = sBattleAnimScriptPtr[3];
    incrementPanArg = sBattleAnimScriptPtr[4];
    framesToWait = sBattleAnimScriptPtr[5];

    currentPan = BattleAnimAdjustPanning2(currentPanArg);
    targetPan = BattleAnimAdjustPanning2(targetPanArg);
    incrementPan = BattleAnimAdjustPanning2(incrementPanArg);

    taskId = CreateTask(Task_PanFromInitialToTarget, 1);
    gTasks[taskId].tInitialPan = currentPan;
    gTasks[taskId].tTargetPan = targetPan;
    gTasks[taskId].tIncrementPan = incrementPan;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tCurrentPan = currentPan;

    PlaySE12WithPanning(songId, currentPan);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 6;
}

#undef tInitialPan
#undef tTargetPan
#undef tIncrementPan
#undef tFramesToWait
#undef tCurrentPan
#undef tFrameCounter

#define tSongId         data[0]
#define tPanning        data[1]
#define tFramesToWait   data[2]
#define tNumberOfPlays  data[3]
#define tFrameCounter   data[8]

static void ScriptCmd_loopsewithpan(void)
{
    u16 songId;
    s8 panningArg, panning;
    u8 framesToWait, numberOfPlays;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    panningArg = sBattleAnimScriptPtr[2];
    framesToWait = sBattleAnimScriptPtr[3];
    numberOfPlays = sBattleAnimScriptPtr[4];
    panning = BattleAnimAdjustPanning(panningArg);

    taskId = CreateTask(Task_LoopAndPlaySE, 1);
    gTasks[taskId].tSongId = songId;
    gTasks[taskId].tPanning = panning;
    gTasks[taskId].tFramesToWait = framesToWait;
    gTasks[taskId].tNumberOfPlays = numberOfPlays;
    gTasks[taskId].tFrameCounter = framesToWait;
    gTasks[taskId].func(taskId);

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 5;
}

static void Task_LoopAndPlaySE(u8 taskId)
{
    if (gTasks[taskId].tFrameCounter++ >= gTasks[taskId].tFramesToWait)
    {
        u16 songId;
        s8 panning;
        u8 numberOfPlays;

        gTasks[taskId].tFrameCounter = 0;
        songId = gTasks[taskId].tSongId;
        panning = gTasks[taskId].tPanning;
        numberOfPlays = --gTasks[taskId].tNumberOfPlays;
        PlaySE12WithPanning(songId, panning);
        if (numberOfPlays == 0)
        {
            DestroyTask(taskId);
            gAnimSoundTaskCount--;
        }
    }
}

#undef tSongId
#undef tPanning
#undef tFramesToWait
#undef tNumberOfPlays
#undef tFrameCounter

#define tSongId         data[0]
#define tPanning        data[1]
#define tFramesToWait   data[2]

static void ScriptCmd_waitplaysewithpan(void)
{
    u16 songId;
    s8 panningArg, panning;
    u8 framesToWait;
    u8 taskId;

    sBattleAnimScriptPtr++;
    songId = T1_READ_16(sBattleAnimScriptPtr);
    panningArg = sBattleAnimScriptPtr[2];
    framesToWait = sBattleAnimScriptPtr[3];
    panning = BattleAnimAdjustPanning(panningArg);

    taskId = CreateTask(Task_WaitAndPlaySE, 1);
    gTasks[taskId].tSongId = songId;
    gTasks[taskId].tPanning = panning;
    gTasks[taskId].tFramesToWait = framesToWait;

    gAnimSoundTaskCount++;
    sBattleAnimScriptPtr += 4;
}

static void Task_WaitAndPlaySE(u8 taskId)
{
    if (gTasks[taskId].tFramesToWait-- <= 0)
    {
        PlaySE12WithPanning(gTasks[taskId].tSongId, gTasks[taskId].tPanning);
        DestroyTask(taskId);
        gAnimSoundTaskCount--;
    }
}

#undef tSongId
#undef tPanning
#undef tFramesToWait

static void ScriptCmd_createsoundtask(void)
{
    TaskFunc func;
    u8 numArgs, taskId;
    s32 i;

    sBattleAnimScriptPtr++;
    func = (TaskFunc)T2_READ_32(sBattleAnimScriptPtr);
    sBattleAnimScriptPtr += 4;
    numArgs = sBattleAnimScriptPtr[0];
    sBattleAnimScriptPtr++;
    for (i = 0; i < numArgs; i++)
    {
        gBattleAnimArgs[i] = T1_READ_16(sBattleAnimScriptPtr);
        sBattleAnimScriptPtr += 2;
    }
    taskId = CreateTask(func, 1);
    func(taskId);
    gAnimSoundTaskCount++;
}

static void ScriptCmd_waitsound(void)
{
    if (gAnimSoundTaskCount != 0)
    {
        sSoundAnimFramesToWait = 0;
        gAnimFramesToWait = 1;
    }
    else if (IsSEPlaying())
    {
        if (++sSoundAnimFramesToWait > 90)
        {
            m4aMPlayStop(&gMPlayInfo_SE1);
            m4aMPlayStop(&gMPlayInfo_SE2);
            sSoundAnimFramesToWait = 0;
        }
        else
        {
            gAnimFramesToWait = 1;
        }
    }
    else
    {
        sSoundAnimFramesToWait = 0;
        sBattleAnimScriptPtr++;
        gAnimFramesToWait = 0;
    }
}

static void ScriptCmd_jumpargeq(void)
{
    u8 argId;
    s16 valueToCheck;

    sBattleAnimScriptPtr++;
    argId = sBattleAnimScriptPtr[0];
    valueToCheck = T1_READ_16(sBattleAnimScriptPtr + 1);

    if (valueToCheck == gBattleAnimArgs[argId])
        sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr + 3);
    else
        sBattleAnimScriptPtr += 7;
}

static void ScriptCmd_jumpifcontest(void)
{
    sBattleAnimScriptPtr++;
    if (IsContest())
        sBattleAnimScriptPtr = T2_READ_PTR(sBattleAnimScriptPtr);
    else
        sBattleAnimScriptPtr += 4;
}

static void ScriptCmd_monbgprio_28(void)
{
    u8 wantedBattler;
    u8 battlerId;
    u8 battlerPosition;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;

    if (wantedBattler != ANIM_ATTACKER)
        battlerId = gBattleAnimTarget;
    else
        battlerId = gBattleAnimAttacker;

    battlerPosition = GetBattlerPosition(battlerId);
    if (!IsContest() && (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_OPPONENT_RIGHT))
    {
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
    }
}

static void ScriptCmd_monbgprio_29(void)
{
    sBattleAnimScriptPtr++;
    if (!IsContest())
    {
        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
        SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
    }
}

static void ScriptCmd_monbgprio_2A(void)
{
    u8 wantedBattler;
    u8 battlerPosition;
    u8 battlerId;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;
    if (GetBattlerSide(gBattleAnimAttacker) != GetBattlerSide(gBattleAnimTarget))
    {
        if (wantedBattler != ANIM_ATTACKER)
            battlerId = gBattleAnimTarget;
        else
            battlerId = gBattleAnimAttacker;

        battlerPosition = GetBattlerPosition(battlerId);
        if (!IsContest() && (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_OPPONENT_RIGHT))
        {
            SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);
            SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 2);
        }
    }
}

static void ScriptCmd_invisible(void)
{
    u8 spriteId;

    spriteId = GetAnimBattlerSpriteId(sBattleAnimScriptPtr[1]);
    if (spriteId != 0xFF)
        gSprites[spriteId].invisible = TRUE;

    sBattleAnimScriptPtr += 2;
}

static void ScriptCmd_visible(void)
{
    u8 spriteId;

    spriteId = GetAnimBattlerSpriteId(sBattleAnimScriptPtr[1]);
    if (spriteId != 0xFF)
        gSprites[spriteId].invisible = FALSE;

    sBattleAnimScriptPtr += 2;
}

static void ScriptCmd_doublebattle_2D(void)
{
    u8 wantedBattler;
    u8 r4;
    u8 spriteId;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;
    if (!IsContest() && IsDoubleBattle()
     && GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget))
    {
        if (wantedBattler == ANIM_ATTACKER)
        {
            r4 = GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker);
            spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        }
        else
        {
            r4 = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);
            spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        }
        if (spriteId != 0xFF)
        {
            gSprites[spriteId].invisible = FALSE;
            if (r4 == 2)
                gSprites[spriteId].oam.priority = 3;

            if (r4 == 1)
                sub_80A477C(FALSE);
            else
                sub_80A477C(TRUE);
        }
    }
}

static void ScriptCmd_doublebattle_2E(void)
{
    u8 wantedBattler;
    u8 r4;
    u8 spriteId;

    wantedBattler = sBattleAnimScriptPtr[1];
    sBattleAnimScriptPtr += 2;
    if (!IsContest() && IsDoubleBattle()
     && GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget))
    {
        if (wantedBattler == ANIM_ATTACKER)
        {
            r4 = GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker);
            spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        }
        else
        {
            r4 = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);
            spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        }

        if (spriteId != 0xFF && r4 == 2)
            gSprites[spriteId].oam.priority = 2;
    }
}

static void ScriptCmd_stopsound(void)
{
    m4aMPlayStop(&gMPlayInfo_SE1);
    m4aMPlayStop(&gMPlayInfo_SE2);
    sBattleAnimScriptPtr++;
}
