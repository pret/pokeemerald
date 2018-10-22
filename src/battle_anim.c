#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "constants/battle_anim.h"
#include "sprite.h"
#include "contest.h"
#include "m4a.h"
#include "pokemon.h"
#include "battle_interface.h"
#include "task.h"
#include "decompress.h"
#include "sound.h"
#include "graphics.h"
#include "dma3.h"
#include "bg.h"
#include "gpu_regs.h"
#include "palette.h"
#include "main.h"

#define ANIM_SPRITE_INDEX_COUNT 8

extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern struct MusicPlayerInfo gMPlayInfo_BGM;
extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;

extern const u16 gMovesWithQuietBGM[];
extern const u8 *const gBattleAnims_Moves[];
extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];
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
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 0,
    .priority = 2,
};


const struct OamData gUnknown_0852490C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524914 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_0852491C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524924 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_0852492C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524934 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_0852493C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524944 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_0852494C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524954 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_0852495C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524964 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_0852496C =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524974 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_0852497C =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524984 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_0852498C =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524994 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_0852499C =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_085249A4 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_085249AC =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_085249B4 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_085249BC =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_085249C4 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_085249CC =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_085249D4 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_085249DC =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_SQUARE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_085249E4 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_085249EC =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_085249F4 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_085249FC =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524A04 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524A0C =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524A14 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524A1C =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524A24 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524A2C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524A34 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524A3C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524A44 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524A4C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524A54 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524A5C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524A64 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524A6C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524A74 =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524A7C =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524A84 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524A8C =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524A94 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524A9C =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524AA4 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524AAC =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524AB4 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524ABC =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524AC4 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524ACC =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524AD4 =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524ADC =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524AE4 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524AEC =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524AF4 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524AFC =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_SQUARE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524B04 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524B0C =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524B14 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524B1C =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_H_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct OamData gUnknown_08524B24 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 0,
    .priority = 2,
};

const struct OamData gUnknown_08524B2C =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 1,
    .priority = 2,
};

const struct OamData gUnknown_08524B34 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2,
    .priority = 2,
};

const struct OamData gUnknown_08524B3C =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = ST_OAM_V_RECTANGLE,
    .size = 3,
    .priority = 2,
};

const struct CompressedSpriteSheet gBattleAnimPicTable[] =
{
    {gBattleAnimSpriteSheet_000, 0x0200, 0x2710},
    {gBattleAnimSpriteSheet_001, 0x0300, 0x2711},
    {gBattleAnimSpriteSheet_002, 0x0200, 0x2712},
    {gBattleAnimSpriteSheet_003, 0x0100, 0x2713},
    {gBattleAnimSpriteSheet_004, 0x0200, 0x2714},
    {gBattleAnimSpriteSheet_005, 0x0400, 0x2715},
    {gBattleAnimSpriteSheet_006, 0x0180, 0x2716},
    {gBattleAnimSpriteSheet_007, 0x0800, 0x2717},
    {gBattleAnimSpriteSheet_008, 0x0020, 0x2718},
    {gBattleAnimSpriteSheet_009, 0x0400, 0x2719},
    {gBattleAnimSpriteSheet_010, 0x1200, 0x271a},
    {gBattleAnimSpriteSheet_011, 0x0180, 0x271b},
    {gBattleAnimSpriteSheet_012, 0x0080, 0x271c},
    {gBattleAnimSpriteSheet_013, 0x0080, 0x271d},
    {gBattleAnimSpriteSheet_014, 0x0280, 0x271e},
    {gBattleAnimSpriteSheet_015, 0x0080, 0x271f},
    {gBattleAnimSpriteSheet_016, 0x0100, 0x2720},
    {gBattleAnimSpriteSheet_017, 0x0020, 0x2721},
    {gBattleAnimSpriteSheet_018, 0x0080, 0x2722},
    {gBattleAnimSpriteSheet_019, 0x0400, 0x2723},
    {gBattleAnimSpriteSheet_020, 0x0200, 0x2724},
    {gBattleAnimSpriteSheet_021, 0x0a00, 0x2725},
    {gBattleAnimSpriteSheet_021, 0x0a00, 0x2726},
    {gBattleAnimSpriteSheet_023, 0x0380, 0x2727},
    {gBattleAnimSpriteSheet_024, 0x0300, 0x2728},
    {gBattleAnimSpriteSheet_025, 0x0a00, 0x2729},
    {gBattleAnimSpriteSheet_026, 0x0a00, 0x272a},
    {gBattleAnimSpriteSheet_027, 0x0a00, 0x272b},
    {gBattleAnimSpriteSheet_028, 0x0a00, 0x272c},
    {gBattleAnimSpriteSheet_029, 0x0a00, 0x272d},
    {gBattleAnimSpriteSheet_030, 0x0a00, 0x272e},
    {gBattleAnimSpriteSheet_031, 0x0e00, 0x272f},
    {gBattleAnimSpriteSheet_032, 0x0380, 0x2730},
    {gBattleAnimSpriteSheet_033, 0x1000, 0x2731},
    {gBattleAnimSpriteSheet_034, 0x0800, 0x2732},
    {gBattleAnimSpriteSheet_035, 0x0a00, 0x2733},
    {gBattleAnimSpriteSheet_036, 0x0800, 0x2734},
    {gBattleAnimSpriteSheet_037, 0x0a00, 0x2735},
    {gBattleAnimSpriteSheet_038, 0x0a00, 0x2736},
    {gBattleAnimSpriteSheet_039, 0x0a00, 0x2737},
    {gBattleAnimSpriteSheet_040, 0x0a00, 0x2738},
    {gBattleAnimSpriteSheet_041, 0x0a00, 0x2739},
    {gBattleAnimSpriteSheet_042, 0x0a00, 0x273a},
    {gBattleAnimSpriteSheet_043, 0x0a00, 0x273b},
    {gBattleAnimSpriteSheet_044, 0x0a00, 0x273c},
    {gBattleAnimSpriteSheet_045, 0x0a00, 0x273d},
    {gBattleAnimSpriteSheet_046, 0x1000, 0x273e},
    {gBattleAnimSpriteSheet_046, 0x1000, 0x273f},
    {gBattleAnimSpriteSheet_048, 0x1000, 0x2740},
    {gBattleAnimSpriteSheet_048, 0x1000, 0x2741},
    {gBattleAnimSpriteSheet_050, 0x0200, 0x2742},
    {gBattleAnimSpriteSheet_051, 0x0200, 0x2743},
    {gBattleAnimSpriteSheet_052, 0x0200, 0x2744},
    {gBattleAnimSpriteSheet_053, 0x0800, 0x2745},
    {gBattleAnimSpriteSheet_054, 0x0080, 0x2746},
    {gBattleAnimSpriteSheet_055, 0x0200, 0x2747},
    {gBattleAnimSpriteSheet_056, 0x1000, 0x2748},
    {gBattleAnimSpriteSheet_057, 0x0180, 0x2749},
    {gBattleAnimSpriteSheet_058, 0x0c00, 0x274a},
    {gBattleAnimSpriteSheet_059, 0x0100, 0x274b},
    {gBattleAnimSpriteSheet_060, 0x0040, 0x274c},
    {gBattleAnimSpriteSheet_061, 0x0180, 0x274d},
    {gBattleAnimSpriteSheet_062, 0x0800, 0x274e},
    {gBattleAnimSpriteSheet_063, 0x0480, 0x274f},
    {gBattleAnimSpriteSheet_064, 0x0200, 0x2750},
    {gBattleAnimSpriteSheet_065, 0x0200, 0x2751},
    {gBattleAnimSpriteSheet_066, 0x0100, 0x2752},
    {gBattleAnimSpriteSheet_065, 0x0200, 0x2753},
    {gBattleAnimSpriteSheet_065, 0x0200, 0x2754},
    {gBattleAnimSpriteSheet_065, 0x0200, 0x2755},
    {gBattleAnimSpriteSheet_070, 0x0200, 0x2756},
    {gBattleAnimSpriteSheet_071, 0x0a00, 0x2757},
    {gBattleAnimSpriteSheet_072, 0x0300, 0x2758},
    {gBattleAnimSpriteSheet_073, 0x0180, 0x2759},
    {gBattleAnimSpriteSheet_074, 0x00a0, 0x275a},
    {gBattleAnimSpriteSheet_075, 0x0700, 0x275b},
    {gBattleAnimSpriteSheet_076, 0x0400, 0x275c},
    {gBattleAnimSpriteSheet_077, 0x0200, 0x275d},
    {gBattleAnimSpriteSheet_078, 0x0300, 0x275e},
    {gBattleAnimSpriteSheet_079, 0x0c00, 0x275f},
    {gBattleAnimSpriteSheet_080, 0x0a00, 0x2760},
    {gBattleAnimSpriteSheet_081, 0x0080, 0x2761},
    {gBattleAnimSpriteSheet_082, 0x0040, 0x2762},
    {gBattleAnimSpriteSheet_083, 0x0e00, 0x2763},
    {gBattleAnimSpriteSheet_084, 0x0e00, 0x2764},
    {gBattleAnimSpriteSheet_085, 0x0280, 0x2765},
    {gBattleAnimSpriteSheet_086, 0x0200, 0x2766},
    {gBattleAnimSpriteSheet_087, 0x0080, 0x2767},
    {gBattleAnimSpriteSheet_088, 0x00c0, 0x2768},
    {gBattleAnimSpriteSheet_089, 0x0a00, 0x2769},
    {gBattleAnimSpriteSheet_090, 0x0200, 0x276a},
    {gBattleAnimSpriteSheet_091, 0x0180, 0x276b},
    {gBattleAnimSpriteSheet_092, 0x0080, 0x276c},
    {gBattleAnimSpriteSheet_093, 0x1000, 0x276d},
    {gBattleAnimSpriteSheet_094, 0x0a00, 0x276e},
    {gBattleAnimSpriteSheet_095, 0x0180, 0x276f},
    {gBattleAnimSpriteSheet_096, 0x0380, 0x2770},
    {gBattleAnimSpriteSheet_097, 0x0c00, 0x2771},
    {gBattleAnimSpriteSheet_098, 0x0200, 0x2772},
    {gBattleAnimSpriteSheet_099, 0x0200, 0x2773},
    {gBattleAnimSpriteSheet_100, 0x0200, 0x2774},
    {gBattleAnimSpriteSheet_101, 0x0200, 0x2775},
    {gBattleAnimSpriteSheet_102, 0x0400, 0x2776},
    {gBattleAnimSpriteSheet_103, 0x0080, 0x2777},
    {gBattleAnimSpriteSheet_104, 0x0400, 0x2778},
    {gBattleAnimSpriteSheet_105, 0x0c00, 0x2779},
    {gBattleAnimSpriteSheet_106, 0x0200, 0x277a},
    {gBattleAnimSpriteSheet_107, 0x1000, 0x277b},
    {gBattleAnimSpriteSheet_108, 0x0a00, 0x277c},
    {gBattleAnimSpriteSheet_109, 0x0020, 0x277d},
    {gBattleAnimSpriteSheet_110, 0x0e00, 0x277e},
    {gBattleAnimSpriteSheet_111, 0x0080, 0x277f},
    {gBattleAnimSpriteSheet_112, 0x0a00, 0x2780},
    {gBattleAnimSpriteSheet_113, 0x0400, 0x2781},
    {gBattleAnimSpriteSheet_114, 0x0200, 0x2782},
    {gBattleAnimSpriteSheet_115, 0x0700, 0x2783},
    {gBattleAnimSpriteSheet_116, 0x0800, 0x2784},
    {gBattleAnimSpriteSheet_117, 0x0a00, 0x2785},
    {gBattleAnimSpriteSheet_118, 0x0600, 0x2786},
    {gBattleAnimSpriteSheet_119, 0x0800, 0x2787},
    {gBattleAnimSpriteSheet_120, 0x0200, 0x2788},
    {gBattleAnimSpriteSheet_121, 0x0040, 0x2789},
    {gBattleAnimSpriteSheet_122, 0x0180, 0x278a},
    {gBattleAnimSpriteSheet_123, 0x0600, 0x278b},
    {gBattleAnimSpriteSheet_124, 0x0600, 0x278c},
    {gBattleAnimSpriteSheet_125, 0x0200, 0x278d},
    {gBattleAnimSpriteSheet_126, 0x0080, 0x278e},
    {gBattleAnimSpriteSheet_127, 0x0200, 0x278f},
    {gBattleAnimSpriteSheet_128, 0x0800, 0x2790},
    {gBattleAnimSpriteSheet_129, 0x0080, 0x2791},
    {gBattleAnimSpriteSheet_130, 0x0a00, 0x2792},
    {gBattleAnimSpriteSheet_131, 0x0280, 0x2793},
    {gBattleAnimSpriteSheet_132, 0x0280, 0x2794},
    {gBattleAnimSpriteSheet_133, 0x0100, 0x2795},
    {gBattleAnimSpriteSheet_134, 0x0200, 0x2796},
    {gBattleAnimSpriteSheet_135, 0x0200, 0x2797},
    {gBattleAnimSpriteSheet_136, 0x0020, 0x2798},
    {gBattleAnimSpriteSheet_137, 0x0a00, 0x2799},
    {gBattleAnimSpriteSheet_138, 0x0800, 0x279a},
    {gBattleAnimSpriteSheet_139, 0x0800, 0x279b},
    {gBattleAnimSpriteSheet_140, 0x00c0, 0x279c},
    {gBattleAnimSpriteSheet_141, 0x01c0, 0x279d},
    {gBattleAnimSpriteSheet_142, 0x0100, 0x279e},
    {gBattleAnimSpriteSheet_143, 0x0800, 0x279f},
    {gBattleAnimSpriteSheet_144, 0x0200, 0x27a0},
    {gBattleAnimSpriteSheet_145, 0x0800, 0x27a1},
    {gBattleAnimSpriteSheet_146, 0x0180, 0x27a2},
    {gBattleAnimSpriteSheet_147, 0x0180, 0x27a3},
    {gBattleAnimSpriteSheet_148, 0x0200, 0x27a4},
    {gBattleAnimSpriteSheet_149, 0x0200, 0x27a5},
    {gBattleAnimSpriteSheet_150, 0x0180, 0x27a6},
    {gBattleAnimSpriteSheet_151, 0x0400, 0x27a7},
    {gBattleAnimSpriteSheet_152, 0x0080, 0x27a8},
    {gBattleAnimSpriteSheet_153, 0x0100, 0x27a9},
    {gBattleAnimSpriteSheet_154, 0x0100, 0x27aa},
    {gBattleAnimSpriteSheet_155, 0x0140, 0x27ab},
    {gBattleAnimSpriteSheet_156, 0x0800, 0x27ac},
    {gBattleAnimSpriteSheet_157, 0x0200, 0x27ad},
    {gBattleAnimSpriteSheet_158, 0x0100, 0x27ae},
    {gBattleAnimSpriteSheet_159, 0x00a0, 0x27af},
    {gBattleAnimSpriteSheet_160, 0x0100, 0x27b0},
    {gBattleAnimSpriteSheet_161, 0x0080, 0x27b1},
    {gBattleAnimSpriteSheet_162, 0x0300, 0x27b2},
    {gBattleAnimSpriteSheet_163, 0x0100, 0x27b3},
    {gBattleAnimSpriteSheet_163, 0x0100, 0x27b4},
    {gBattleAnimSpriteSheet_163, 0x0100, 0x27b5},
    {gBattleAnimSpriteSheet_166, 0x0800, 0x27b6},
    {gBattleAnimSpriteSheet_166, 0x0800, 0x27b7},
    {gBattleAnimSpriteSheet_166, 0x0800, 0x27b8},
    {gBattleAnimSpriteSheet_166, 0x0800, 0x27b9},
    {gBattleAnimSpriteSheet_166, 0x0800, 0x27ba},
    {gBattleAnimSpriteSheet_171, 0x0080, 0x27bb},
    {gBattleAnimSpriteSheet_144, 0x0200, 0x27bc},
    {gBattleAnimSpriteSheet_173, 0x0200, 0x27bd},
    {gBattleAnimSpriteSheet_174, 0x0200, 0x27be},
    {gBattleAnimSpriteSheet_175, 0x0080, 0x27bf},
    {gBattleAnimSpriteSheet_176, 0x0200, 0x27c0},
    {gBattleAnimSpriteSheet_177, 0x0500, 0x27c1},
    {gBattleAnimSpriteSheet_178, 0x0800, 0x27c2},
    {gBattleAnimSpriteSheet_179, 0x0400, 0x27c3},
    {gBattleAnimSpriteSheet_180, 0x0020, 0x27c4},
    {gBattleAnimSpriteSheet_181, 0x0800, 0x27c5},
    {gBattleAnimSpriteSheet_182, 0x0100, 0x27c6},
    {gBattleAnimSpriteSheet_183, 0x0800, 0x27c7},
    {gBattleAnimSpriteSheet_184, 0x0400, 0x27c8},
    {gBattleAnimSpriteSheet_185, 0x0a00, 0x27c9},
    {gBattleAnimSpriteSheet_186, 0x1000, 0x27ca},
    {gBattleAnimSpriteSheet_187, 0x0800, 0x27cb},
    {gBattleAnimSpriteSheet_188, 0x0400, 0x27cc},
    {gBattleAnimSpriteSheet_189, 0x0200, 0x27cd},
    {gBattleAnimSpriteSheet_190, 0x0800, 0x27ce},
    {gBattleAnimSpriteSheet_191, 0x0800, 0x27cf},
    {gBattleAnimSpriteSheet_192, 0x0800, 0x27d0},
    {gBattleAnimSpriteSheet_193, 0x0200, 0x27d1},
    {gBattleAnimSpriteSheet_194, 0x0800, 0x27d2},
    {gBattleAnimSpriteSheet_195, 0x0200, 0x27d3},
    {gBattleAnimSpriteSheet_196, 0x0800, 0x27d4},
    {gBattleAnimSpriteSheet_197, 0x0200, 0x27d5},
    {gBattleAnimSpriteSheet_198, 0x0800, 0x27d6},
    {gBattleAnimSpriteSheet_199, 0x0400, 0x27d7},
    {gBattleAnimSpriteSheet_200, 0x0200, 0x27d8},
    {gBattleAnimSpriteSheet_201, 0x0a80, 0x27d9},
    {gBattleAnimSpriteSheet_202, 0x0600, 0x27da},
    {gBattleAnimSpriteSheet_203, 0x0800, 0x27db},
    {gBattleAnimSpriteSheet_204, 0x0200, 0x27dc},
    {gBattleAnimSpriteSheet_205, 0x0600, 0x27dd},
    {gBattleAnimSpriteSheet_206, 0x0800, 0x27de},
    {gBattleAnimSpriteSheet_207, 0x0180, 0x27df},
    {gBattleAnimSpriteSheet_208, 0x0800, 0x27e0},
    {gBattleAnimSpriteSheet_209, 0x0800, 0x27e1},
    {gBattleAnimSpriteSheet_210, 0x0080, 0x27e2},
    {gBattleAnimSpriteSheet_211, 0x0080, 0x27e3},
    {gBattleAnimSpriteSheet_212, 0x0800, 0x27e4},
    {gBattleAnimSpriteSheet_213, 0x0800, 0x27e5},
    {gBattleAnimSpriteSheet_214, 0x0600, 0x27e6},
    {gBattleAnimSpriteSheet_215, 0x0600, 0x27e7},
    {gBattleAnimSpriteSheet_210, 0x0080, 0x27e8},
    {gBattleAnimSpriteSheet_217, 0x0080, 0x27e9},
    {gBattleAnimSpriteSheet_218, 0x0180, 0x27ea},
    {gBattleAnimSpriteSheet_210, 0x0080, 0x27eb},
    {gBattleAnimSpriteSheet_220, 0x0200, 0x27ec},
    {gBattleAnimSpriteSheet_221, 0x0400, 0x27ed},
    {gBattleAnimSpriteSheet_222, 0x0a00, 0x27ee},
    {gBattleAnimSpriteSheet_223, 0x0800, 0x27ef},
    {gBattleAnimSpriteSheet_224, 0x0200, 0x27f0},
    {gBattleAnimSpriteSheet_225, 0x0400, 0x27f1},
    {gBattleAnimSpriteSheet_226, 0x0080, 0x27f2},
    {gBattleAnimSpriteSheet_227, 0x0800, 0x27f3},
    {gBattleAnimSpriteSheet_228, 0x0200, 0x27f4},
    {gBattleAnimSpriteSheet_229, 0x0300, 0x27f5},
    {gBattleAnimSpriteSheet_230, 0x0800, 0x27f6},
    {gBattleAnimSpriteSheet_231, 0x0380, 0x27f7},
    {gBattleAnimSpriteSheet_232, 0x0800, 0x27f8},
    {gBattleAnimSpriteSheet_233, 0x00c0, 0x27f9},
    {gBattleAnimSpriteSheet_234, 0x0800, 0x27fa},
    {gBattleAnimSpriteSheet_235, 0x0060, 0x27fb},
    {gBattleAnimSpriteSheet_235, 0x0060, 0x27fc},
    {gBattleAnimSpriteSheet_235, 0x0060, 0x27fd},
    {gBattleAnimSpriteSheet_238, 0x0080, 0x27fe},
    {gBattleAnimSpriteSheet_239, 0x0180, 0x27ff},
    {gBattleAnimSpriteSheet_240, 0x0180, 0x2800},
    {gBattleAnimSpriteSheet_241, 0x0200, 0x2801},
    {gBattleAnimSpriteSheet_242, 0x0200, 0x2802},
    {gBattleAnimSpriteSheet_243, 0x0020, 0x2803},
    {gBattleAnimSpriteSheet_244, 0x0400, 0x2804},
    {gBattleAnimSpriteSheet_245, 0x0600, 0x2805},
    {gBattleAnimSpriteSheet_246, 0x1000, 0x2806},
    {gBattleAnimSpriteSheet_247, 0x0400, 0x2807},
    {gBattleAnimSpriteSheet_248, 0x0020, 0x2808},
    {gBattleAnimSpriteSheet_249, 0x0080, 0x2809},
    {gBattleAnimSpriteSheet_250, 0x0800, 0x280a},
    {gBattleAnimSpriteSheet_251, 0x0080, 0x280b},
    {gBattleAnimSpriteSheet_252, 0x0200, 0x280c},
    {gBattleAnimSpriteSheet_253, 0x0400, 0x280d},
    {gBattleAnimSpriteSheet_254, 0x0200, 0x280e},
    {gBattleAnimSpriteSheet_255, 0x0200, 0x280f},
    {gBattleAnimSpriteSheet_256, 0x0800, 0x2810},
    {gBattleAnimSpriteSheet_257, 0x0280, 0x2811},
    {gBattleAnimSpriteSheet_258, 0x0200, 0x2812},
    {gBattleAnimSpriteSheet_149, 0x0200, 0x2813},
    {gBattleAnimSpriteSheet_260, 0x0400, 0x2814},
    {gBattleAnimSpriteSheet_261, 0x0200, 0x2815},
    {gBattleAnimSpriteSheet_262, 0x0200, 0x2816},
    {gBattleAnimSpriteSheet_263, 0x0080, 0x2817},
    {gBattleAnimSpriteSheet_264, 0x0020, 0x2818},
    {gBattleAnimSpriteSheet_264, 0x0020, 0x2819},
    {gBattleAnimSpriteSheet_266, 0x0080, 0x281a},
    {gBattleAnimSpriteSheet_212, 0x0800, 0x281b},
    {gBattleAnimSpriteSheet_264, 0x0020, 0x281c},
    {gBattleAnimSpriteSheet_269, 0x0080, 0x281d},
    {gBattleAnimSpriteSheet_270, 0x0400, 0x281e},
    {gBattleAnimSpriteSheet_271, 0x0080, 0x281f},
    {gBattleAnimSpriteSheet_272, 0x0800, 0x2820},
    {gBattleAnimSpriteSheet_273, 0x0020, 0x2821},
    {gBattleAnimSpriteSheet_274, 0x0800, 0x2822},
    {gBattleAnimSpriteSheet_275, 0x0800, 0x2823},
    {gBattleAnimSpriteSheet_276, 0x0800, 0x2824},
    {gBattleAnimSpriteSheet_277, 0x1000, 0x2825},
    {gBattleAnimSpriteSheet_278, 0x0800, 0x2826},
    {gBattleAnimSpriteSheet_279, 0x00a0, 0x2827},
    {gBattleAnimSpriteSheet_280, 0x0800, 0x2828},
    {gBattleAnimSpriteSheet_281, 0x0200, 0x2829},
    {gBattleAnimSpriteSheet_282, 0x0600, 0x282a},
    {gBattleAnimSpriteSheet_283, 0x0200, 0x282b},
    {gBattleAnimSpriteSheet_284, 0x0800, 0x282c},
    {gBattleAnimSpriteSheet_285, 0x0200, 0x282d},
    {gBattleAnimSpriteSheet_183, 0x0800, 0x282e},
    {gBattleAnimSpriteSheet_056, 0x1000, 0x282f},
    {gBattleAnimSpriteSheet_163, 0x0100, 0x2830},
};


const struct CompressedSpritePalette gBattleAnimPaletteTable[] =
{
    {gBattleAnimSpritePalette_000, 0x2710},
    {gBattleAnimSpritePalette_001, 0x2711},
    {gBattleAnimSpritePalette_002, 0x2712},
    {gBattleAnimSpritePalette_003, 0x2713},
    {gBattleAnimSpritePalette_004, 0x2714},
    {gBattleAnimSpritePalette_005, 0x2715},
    {gBattleAnimSpritePalette_006, 0x2716},
    {gBattleAnimSpritePalette_007, 0x2717},
    {gBattleAnimSpritePalette_008, 0x2718},
    {gBattleAnimSpritePalette_009, 0x2719},
    {gBattleAnimSpritePalette_010, 0x271a},
    {gBattleAnimSpritePalette_011, 0x271b},
    {gBattleAnimSpritePalette_012, 0x271c},
    {gBattleAnimSpritePalette_013, 0x271d},
    {gBattleAnimSpritePalette_014, 0x271e},
    {gBattleAnimSpritePalette_015, 0x271f},
    {gBattleAnimSpritePalette_016, 0x2720},
    {gBattleAnimSpritePalette_016, 0x2721},
    {gBattleAnimSpritePalette_018, 0x2722},
    {gBattleAnimSpritePalette_019, 0x2723},
    {gBattleAnimSpritePalette_020, 0x2724},
    {gBattleAnimSpritePalette_021, 0x2725},
    {gBattleAnimSpritePalette_022, 0x2726},
    {gBattleAnimSpritePalette_023, 0x2727},
    {gBattleAnimSpritePalette_024, 0x2728},
    {gBattleAnimSpritePalette_025, 0x2729},
    {gBattleAnimSpritePalette_026, 0x272a},
    {gBattleAnimSpritePalette_027, 0x272b},
    {gBattleAnimSpritePalette_028, 0x272c},
    {gBattleAnimSpritePalette_029, 0x272d},
    {gBattleAnimSpritePalette_030, 0x272e},
    {gBattleAnimSpritePalette_031, 0x272f},
    {gBattleAnimSpritePalette_032, 0x2730},
    {gBattleAnimSpritePalette_033, 0x2731},
    {gBattleAnimSpritePalette_033, 0x2732},
    {gBattleAnimSpritePalette_033, 0x2733},
    {gBattleAnimSpritePalette_036, 0x2734},
    {gBattleAnimSpritePalette_036, 0x2735},
    {gBattleAnimSpritePalette_038, 0x2736},
    {gBattleAnimSpritePalette_039, 0x2737},
    {gBattleAnimSpritePalette_038, 0x2738},
    {gBattleAnimSpritePalette_038, 0x2739},
    {gBattleAnimSpritePalette_042, 0x273a},
    {gBattleAnimSpritePalette_043, 0x273b},
    {gBattleAnimSpritePalette_044, 0x273c},
    {gBattleAnimSpritePalette_045, 0x273d},
    {gBattleAnimSpritePalette_046, 0x273e},
    {gBattleAnimSpritePalette_047, 0x273e},
    {gBattleAnimSpritePalette_048, 0x2740},
    {gBattleAnimSpritePalette_049, 0x2741},
    {gBattleAnimSpritePalette_050, 0x2742},
    {gBattleAnimSpritePalette_050, 0x2743},
    {gBattleAnimSpritePalette_050, 0x2744},
    {gBattleAnimSpritePalette_026, 0x2745},
    {gBattleAnimSpritePalette_054, 0x2746},
    {gBattleAnimSpritePalette_050, 0x2747},
    {gBattleAnimSpritePalette_056, 0x2748},
    {gBattleAnimSpritePalette_057, 0x2749},
    {gBattleAnimSpritePalette_058, 0x274a},
    {gBattleAnimSpritePalette_059, 0x274b},
    {gBattleAnimSpritePalette_060, 0x274c},
    {gBattleAnimSpritePalette_061, 0x274d},
    {gBattleAnimSpritePalette_062, 0x274e},
    {gBattleAnimSpritePalette_063, 0x274f},
    {gBattleAnimSpritePalette_064, 0x2750},
    {gBattleAnimSpritePalette_065, 0x2751},
    {gBattleAnimSpritePalette_066, 0x2752},
    {gBattleAnimSpritePalette_067, 0x2753},
    {gBattleAnimSpritePalette_068, 0x2754},
    {gBattleAnimSpritePalette_065, 0x2755},
    {gBattleAnimSpritePalette_070, 0x2756},
    {gBattleAnimSpritePalette_070, 0x2757},
    {gBattleAnimSpritePalette_072, 0x2758},
    {gBattleAnimSpritePalette_073, 0x2759},
    {gBattleAnimSpritePalette_074, 0x275a},
    {gBattleAnimSpritePalette_075, 0x275b},
    {gBattleAnimSpritePalette_076, 0x275c},
    {gBattleAnimSpritePalette_076, 0x275d},
    {gBattleAnimSpritePalette_078, 0x275e},
    {gBattleAnimSpritePalette_078, 0x275f},
    {gBattleAnimSpritePalette_080, 0x2760},
    {gBattleAnimSpritePalette_081, 0x2761},
    {gBattleAnimSpritePalette_082, 0x2762},
    {gBattleAnimSpritePalette_083, 0x2763},
    {gBattleAnimSpritePalette_084, 0x2764},
    {gBattleAnimSpritePalette_085, 0x2765},
    {gBattleAnimSpritePalette_086, 0x2766},
    {gBattleAnimSpritePalette_087, 0x2767},
    {gBattleAnimSpritePalette_088, 0x2768},
    {gBattleAnimSpritePalette_089, 0x2769},
    {gBattleAnimSpritePalette_090, 0x276a},
    {gBattleAnimSpritePalette_091, 0x276b},
    {gBattleAnimSpritePalette_092, 0x276c},
    {gBattleAnimSpritePalette_093, 0x276d},
    {gBattleAnimSpritePalette_094, 0x276e},
    {gBattleAnimSpritePalette_095, 0x276f},
    {gBattleAnimSpritePalette_096, 0x2770},
    {gBattleAnimSpritePalette_097, 0x2771},
    {gBattleAnimSpritePalette_094, 0x2772},
    {gBattleAnimSpritePalette_099, 0x2773},
    {gBattleAnimSpritePalette_100, 0x2774},
    {gBattleAnimSpritePalette_101, 0x2775},
    {gBattleAnimSpritePalette_101, 0x2776},
    {gBattleAnimSpritePalette_103, 0x2777},
    {gBattleAnimSpritePalette_104, 0x2778},
    {gBattleAnimSpritePalette_105, 0x2779},
    {gBattleAnimSpritePalette_105, 0x277a},
    {gBattleAnimSpritePalette_107, 0x277b},
    {gBattleAnimSpritePalette_107, 0x277c},
    {gBattleAnimSpritePalette_109, 0x277d},
    {gBattleAnimSpritePalette_109, 0x277e},
    {gBattleAnimSpritePalette_111, 0x277f},
    {gBattleAnimSpritePalette_112, 0x2780},
    {gBattleAnimSpritePalette_113, 0x2781},
    {gBattleAnimSpritePalette_114, 0x2782},
    {gBattleAnimSpritePalette_115, 0x2783},
    {gBattleAnimSpritePalette_116, 0x2784},
    {gBattleAnimSpritePalette_117, 0x2785},
    {gBattleAnimSpritePalette_118, 0x2786},
    {gBattleAnimSpritePalette_119, 0x2787},
    {gBattleAnimSpritePalette_120, 0x2788},
    {gBattleAnimSpritePalette_121, 0x2789},
    {gBattleAnimSpritePalette_122, 0x278a},
    {gBattleAnimSpritePalette_122, 0x278b},
    {gBattleAnimSpritePalette_124, 0x278c},
    {gBattleAnimSpritePalette_125, 0x278d},
    {gBattleAnimSpritePalette_126, 0x278e},
    {gBattleAnimSpritePalette_127, 0x278f},
    {gBattleAnimSpritePalette_128, 0x2790},
    {gBattleAnimSpritePalette_128, 0x2791},
    {gBattleAnimSpritePalette_130, 0x2792},
    {gBattleAnimSpritePalette_130, 0x2793},
    {gBattleAnimSpritePalette_132, 0x2794},
    {gBattleAnimSpritePalette_133, 0x2795},
    {gBattleAnimSpritePalette_133, 0x2796},
    {gBattleAnimSpritePalette_135, 0x2797},
    {gBattleAnimSpritePalette_136, 0x2798},
    {gBattleAnimSpritePalette_135, 0x2799},
    {gBattleAnimSpritePalette_135, 0x279a},
    {gBattleAnimSpritePalette_139, 0x279b},
    {gBattleAnimSpritePalette_140, 0x279c},
    {gBattleAnimSpritePalette_141, 0x279d},
    {gBattleAnimSpritePalette_141, 0x279e},
    {gBattleAnimSpritePalette_143, 0x279f},
    {gBattleAnimSpritePalette_144, 0x27a0},
    {gBattleAnimSpritePalette_139, 0x27a1},
    {gBattleAnimSpritePalette_115, 0x27a2},
    {gBattleAnimSpritePalette_147, 0x27a3},
    {gBattleAnimSpritePalette_148, 0x27a4},
    {gBattleAnimSpritePalette_148, 0x27a5},
    {gBattleAnimSpritePalette_150, 0x27a6},
    {gBattleAnimSpritePalette_150, 0x27a7},
    {gBattleAnimSpritePalette_152, 0x27a8},
    {gBattleAnimSpritePalette_153, 0x27a9},
    {gBattleAnimSpritePalette_154, 0x27aa},
    {gBattleAnimSpritePalette_155, 0x27ab},
    {gBattleAnimSpritePalette_156, 0x27ac},
    {gBattleAnimSpritePalette_157, 0x27ad},
    {gBattleAnimSpritePalette_158, 0x27ae},
    {gBattleAnimSpritePalette_159, 0x27af},
    {gBattleAnimSpritePalette_160, 0x27b0},
    {gBattleAnimSpritePalette_161, 0x27b1},
    {gBattleAnimSpritePalette_162, 0x27b2},
    {gBattleAnimSpritePalette_163, 0x27b3},
    {gBattleAnimSpritePalette_164, 0x27b4},
    {gBattleAnimSpritePalette_165, 0x27b5},
    {gBattleAnimSpritePalette_166, 0x27b6},
    {gBattleAnimSpritePalette_167, 0x27b7},
    {gBattleAnimSpritePalette_168, 0x27b8},
    {gBattleAnimSpritePalette_169, 0x27b9},
    {gBattleAnimSpritePalette_170, 0x27ba},
    {gBattleAnimSpritePalette_171, 0x27bb},
    {gBattleAnimSpritePalette_172, 0x27bc},
    {gBattleAnimSpritePalette_001, 0x27bd},
    {gBattleAnimSpritePalette_174, 0x27be},
    {gBattleAnimSpritePalette_175, 0x27bf},
    {gBattleAnimSpritePalette_176, 0x27c0},
    {gBattleAnimSpritePalette_177, 0x27c1},
    {gBattleAnimSpritePalette_178, 0x27c2},
    {gBattleAnimSpritePalette_179, 0x27c3},
    {gBattleAnimSpritePalette_179, 0x27c4},
    {gBattleAnimSpritePalette_179, 0x27c5},
    {gBattleAnimSpritePalette_182, 0x27c6},
    {gBattleAnimSpritePalette_183, 0x27c7},
    {gBattleAnimSpritePalette_184, 0x27c8},
    {gBattleAnimSpritePalette_185, 0x27c9},
    {gBattleAnimSpritePalette_186, 0x27ca},
    {gBattleAnimSpritePalette_187, 0x27cb},
    {gBattleAnimSpritePalette_188, 0x27cc},
    {gBattleAnimSpritePalette_189, 0x27cd},
    {gBattleAnimSpritePalette_190, 0x27ce},
    {gBattleAnimSpritePalette_191, 0x27cf},
    {gBattleAnimSpritePalette_192, 0x27d0},
    {gBattleAnimSpritePalette_193, 0x27d1},
    {gBattleAnimSpritePalette_194, 0x27d2},
    {gBattleAnimSpritePalette_195, 0x27d3},
    {gBattleAnimSpritePalette_196, 0x27d4},
    {gBattleAnimSpritePalette_197, 0x27d5},
    {gBattleAnimSpritePalette_198, 0x27d6},
    {gBattleAnimSpritePalette_199, 0x27d7},
    {gBattleAnimSpritePalette_200, 0x27d8},
    {gBattleAnimSpritePalette_201, 0x27d9},
    {gBattleAnimSpritePalette_202, 0x27da},
    {gBattleAnimSpritePalette_203, 0x27db},
    {gBattleAnimSpritePalette_204, 0x27dc},
    {gBattleAnimSpritePalette_205, 0x27dd},
    {gBattleAnimSpritePalette_206, 0x27de},
    {gBattleAnimSpritePalette_207, 0x27df},
    {gBattleAnimSpritePalette_167, 0x27e0},
    {gBattleAnimSpritePalette_209, 0x27e1},
    {gBattleAnimSpritePalette_210, 0x27e2},
    {gBattleAnimSpritePalette_211, 0x27e3},
    {gBattleAnimSpritePalette_211, 0x27e4},
    {gBattleAnimSpritePalette_211, 0x27e5},
    {gBattleAnimSpritePalette_064, 0x27e6},
    {gBattleAnimSpritePalette_215, 0x27e7},
    {gBattleAnimSpritePalette_216, 0x27e8},
    {gBattleAnimSpritePalette_217, 0x27e9},
    {gBattleAnimSpritePalette_218, 0x27ea},
    {gBattleAnimSpritePalette_219, 0x27eb},
    {gBattleAnimSpritePalette_220, 0x27ec},
    {gBattleAnimSpritePalette_221, 0x27ed},
    {gBattleAnimSpritePalette_222, 0x27ee},
    {gBattleAnimSpritePalette_223, 0x27ef},
    {gBattleAnimSpritePalette_224, 0x27f0},
    {gBattleAnimSpritePalette_225, 0x27f1},
    {gBattleAnimSpritePalette_226, 0x27f2},
    {gBattleAnimSpritePalette_226, 0x27f3},
    {gBattleAnimSpritePalette_228, 0x27f4},
    {gBattleAnimSpritePalette_229, 0x27f5},
    {gBattleAnimSpritePalette_230, 0x27f6},
    {gBattleAnimSpritePalette_231, 0x27f7},
    {gBattleAnimSpritePalette_231, 0x27f8},
    {gBattleAnimSpritePalette_233, 0x27f9},
    {gBattleAnimSpritePalette_234, 0x27fa},
    {gBattleAnimSpritePalette_235, 0x27fb},
    {gBattleAnimSpritePalette_236, 0x27fc},
    {gBattleAnimSpritePalette_237, 0x27fd},
    {gBattleAnimSpritePalette_238, 0x27fe},
    {gBattleAnimSpritePalette_239, 0x27ff},
    {gBattleAnimSpritePalette_240, 0x2800},
    {gBattleAnimSpritePalette_241, 0x2801},
    {gBattleAnimSpritePalette_242, 0x2802},
    {gBattleAnimSpritePalette_243, 0x2803},
    {gBattleAnimSpritePalette_244, 0x2804},
    {gBattleAnimSpritePalette_245, 0x2805},
    {gBattleAnimSpritePalette_245, 0x2806},
    {gBattleAnimSpritePalette_064, 0x2807},
    {gBattleAnimSpritePalette_248, 0x2808},
    {gBattleAnimSpritePalette_249, 0x2809},
    {gBattleAnimSpritePalette_249, 0x280a},
    {gBattleAnimSpritePalette_251, 0x280b},
    {gBattleAnimSpritePalette_252, 0x280c},
    {gBattleAnimSpritePalette_253, 0x280d},
    {gBattleAnimSpritePalette_254, 0x280e},
    {gBattleAnimSpritePalette_255, 0x280f},
    {gBattleAnimSpritePalette_256, 0x2810},
    {gBattleAnimSpritePalette_257, 0x2811},
    {gBattleAnimSpritePalette_258, 0x2812},
    {gBattleAnimSpritePalette_259, 0x2813},
    {gBattleAnimSpritePalette_260, 0x2814},
    {gBattleAnimSpritePalette_261, 0x2815},
    {gBattleAnimSpritePalette_262, 0x2816},
    {gBattleAnimSpritePalette_263, 0x2817},
    {gBattleAnimSpritePalette_264, 0x2818},
    {gBattleAnimSpritePalette_265, 0x2819},
    {gBattleAnimSpritePalette_266, 0x281a},
    {gBattleAnimSpritePalette_267, 0x281b},
    {gBattleAnimSpritePalette_268, 0x281c},
    {gBattleAnimSpritePalette_269, 0x281d},
    {gBattleAnimSpritePalette_270, 0x281e},
    {gBattleAnimSpritePalette_271, 0x281f},
    {gBattleAnimSpritePalette_272, 0x2820},
    {gBattleAnimSpritePalette_272, 0x2821},
    {gBattleAnimSpritePalette_274, 0x2822},
    {gBattleAnimSpritePalette_274, 0x2823},
    {gBattleAnimSpritePalette_274, 0x2824},
    {gBattleAnimSpritePalette_277, 0x2825},
    {gBattleAnimSpritePalette_278, 0x2826},
    {gBattleAnimSpritePalette_279, 0x2827},
    {gBattleAnimSpritePalette_280, 0x2828},
    {gBattleAnimSpritePalette_281, 0x2829},
    {gBattleAnimSpritePalette_282, 0x282a},
    {gBattleAnimSpritePalette_283, 0x282b},
    {gBattleAnimSpritePalette_284, 0x282c},
    {gBattleAnimSpritePalette_285, 0x282d},
    {gBattleAnimSpritePalette_286, 0x282e},
    {gBattleAnimSpritePalette_287, 0x282f},
    {gBattleAnimSpritePalette_288, 0x2830},
};

const struct BattleAnimBackground gBattleAnimBackgroundTable[] =
{
    &gBattleAnimBackgroundImage_00, &gBattleAnimBackgroundPalette_00, &gBattleAnimBackgroundTilemap_00,
    &gBattleAnimBackgroundImage_00, &gBattleAnimBackgroundPalette_00, &gBattleAnimBackgroundTilemap_00,
    &gBattleAnimBackgroundImage_02, &gBattleAnimBackgroundPalette_02, &gBattleAnimBackgroundTilemap_02,
    &gBattleAnimBackgroundImage_03, &gBattleAnimBackgroundPalette_03, &gBattleAnimBackgroundTilemap_03,
    &gBattleAnimBackgroundImage_04, &gBattleAnimBackgroundPalette_04, &gBattleAnimBackgroundTilemap_04,
    &gBattleAnimBackgroundImage_04, &gBattleAnimBackgroundPalette_04, &gBattleAnimBackgroundTilemap_05,
    &gBattleAnimBackgroundImage_04, &gBattleAnimBackgroundPalette_04, &gBattleAnimBackgroundTilemap_06,
    &gBattleAnimBackgroundImage_07, &gBattleAnimBackgroundPalette_07, &gBattleAnimBackgroundTilemap_07,
    &gBattleAnimBackgroundImage_07, &gBattleAnimBackgroundPalette_07, &gBattleAnimBackgroundTilemap_08,
    &gBattleAnimBackgroundImage_09, &gBattleAnimBackgroundPalette_09, &gBattleAnimBackgroundTilemap_09,
    &gBattleAnimBackgroundImage_09, &gBattleAnimBackgroundPalette_09, &gBattleAnimBackgroundTilemap_10,
    &gBattleAnimBackgroundImage_11, &gBattleAnimBackgroundPalette_11, &gBattleAnimBackgroundTilemap_11,
    &gBattleAnimBackgroundImage_12, &gBattleAnimBackgroundPalette_12, &gBattleAnimBackgroundTilemap_12,
    &gBattleAnimBackgroundImage_12, &gBattleAnimBackgroundPalette_12, &gBattleAnimBackgroundTilemap_13,
    &gBattleAnimBackgroundImage_12, &gBattleAnimBackgroundPalette_12, &gBattleAnimBackgroundTilemap_14,
    &gBattleAnimBackgroundImage_15, &gBattleAnimBackgroundPalette_15, &gBattleAnimBackgroundTilemap_15,
    &gBattleAnimBackgroundImage_16, &gBattleAnimBackgroundPalette_16, &gBattleAnimBackgroundTilemap_16,
    &gBattleAnimBackgroundImage_17, &gBattleAnimBackgroundPalette_17, &gBattleAnimBackgroundTilemap_17,
    &gBattleAnimBackgroundImage_07, &gBattleAnimBackgroundPalette_18, &gBattleAnimBackgroundTilemap_07,
    &gBattleAnimBackgroundImage_07, &gBattleAnimBackgroundPalette_18, &gBattleAnimBackgroundTilemap_08,
    &gBattleAnimBackgroundImage_20, &gBattleAnimBackgroundPalette_20, &gBattleAnimBackgroundTilemap_20,
    &gBattleAnimBackgroundImage_21, &gBattleAnimBackgroundPalette_21, &gBattleAnimBackgroundTilemap_21,
    &gBattleAnimBackgroundImage_09, &gBattleAnimBackgroundPalette_22, &gBattleAnimBackgroundTilemap_09,
    &gBattleAnimBackgroundImage_09, &gBattleAnimBackgroundPalette_22, &gBattleAnimBackgroundTilemap_10,
    &gBattleAnimBackgroundImage_04, &gBattleAnimBackgroundPalette_24, &gBattleAnimBackgroundTilemap_04,
    &gBattleAnimBackgroundImage_04, &gBattleAnimBackgroundPalette_24, &gBattleAnimBackgroundTilemap_05,
    &gBattleAnimBackgroundImage_04, &gBattleAnimBackgroundPalette_24, &gBattleAnimBackgroundTilemap_06,
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
        sAnimSpriteIndexArray[i] |= 0xFFFF;

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
            gAnimBattlerSpecies[i] = gContestResources->field_18->unk0;
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
        sAnimSpriteIndexArray[i] |= 0xFFFF;

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
            sAnimSpriteIndexArray[i] |= 0xFFFF;
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
    LoadCompressedObjectPicUsingHeap(&gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(index)]);
    LoadCompressedObjectPaletteUsingHeap(&gBattleAnimPaletteTable[GET_TRUE_SPRITE_INDEX(index)]);
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

        subpriority = sub_80A82E4(gBattleAnimTarget) + (s8)(argVar);
    }
    else
    {
        if (argVar >= 0x40)
            argVar -= 0x40;
        else
            argVar *= -1;

        subpriority = sub_80A82E4(gBattleAnimAttacker) + (s8)(argVar);
    }

    if (subpriority < 3)
        subpriority = 3;

    CreateSpriteAndAnimate(template, GetBattlerSpriteCoord(gBattleAnimTarget, 2), GetBattlerSpriteCoord(gBattleAnimTarget, 3), subpriority);
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
            sAnimSpriteIndexArray[i] |= 0xFFFF; // set terminator.
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

        sub_80A438C(battlerId, toBG_2, FALSE);
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

        sub_80A438C(battlerId, toBG_2, FALSE);
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

void sub_80A438C(u8 battlerId, bool8 toBG_2, bool8 setSpriteInvisible)
{
    struct UnknownAnimStruct2 unknownStruct;
    u8 battlerSpriteId;

    if (!toBG_2)
    {
        u8 battlerPosition;

        if (IsContest() == TRUE)
        {
            RequestDma3Fill(0, (void*)(VRAM + 0x8000), 0x2000, 1);
            RequestDma3Fill(0xFF, (void*)(VRAM + 0xF000), 0x1000, 0);
        }
        else
        {
            RequestDma3Fill(0, (void*)(VRAM + 0x4000), 0x2000, 1);
            RequestDma3Fill(0xFF, (void*)(VRAM + 0xe000), 0x1000, 0);
        }

        sub_80A6B30(&unknownStruct);
        CpuFill16(0, unknownStruct.bgTiles, 0x1000);
        CpuFill16(0xFF, unknownStruct.unk4, 0x800);

        SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 2);
        SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 1);
        SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 0);

        battlerSpriteId = gBattlerSpriteIds[battlerId];

        gBattle_BG1_X =  -(gSprites[battlerSpriteId].pos1.x + gSprites[battlerSpriteId].pos2.x) + 0x20;
        if (IsContest() && IsSpeciesNotUnown(gContestResources->field_18->unk0))
            gBattle_BG1_X--;

        gBattle_BG1_Y =  -(gSprites[battlerSpriteId].pos1.y + gSprites[battlerSpriteId].pos2.y) + 0x20;
        if (setSpriteInvisible)
            gSprites[gBattlerSpriteIds[battlerId]].invisible = TRUE;

        SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
        SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

        LoadPalette(&gPlttBufferUnfaded[0x100 + battlerId * 16], unknownStruct.unk8 * 16, 0x20);
        CpuCopy32(&gPlttBufferUnfaded[0x100 + battlerId * 16], (void*)(BG_PLTT + unknownStruct.unk8 * 32), 0x20);

        if (IsContest())
            battlerPosition = 0;
        else
            battlerPosition = GetBattlerPosition(battlerId);

        sub_8118FBC(1, 0, 0, battlerPosition, unknownStruct.unk8, unknownStruct.bgTiles, unknownStruct.unk4, unknownStruct.tilesOffset);

        if (IsContest())
            sub_80A46A0();
    }
    else
    {
        RequestDma3Fill(0, (void*)(VRAM + 0x6000), 0x2000, 1);
        RequestDma3Fill(0, (void*)(VRAM + 0xF000), 0x1000, 1);
        sub_80A6B90(&unknownStruct, 2);
        CpuFill16(0, unknownStruct.bgTiles + 0x1000, 0x1000);
        CpuFill16(0, unknownStruct.unk4 + 0x400, 0x800);
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

        sub_8118FBC(2, 0, 0, GetBattlerPosition(battlerId), unknownStruct.unk8, unknownStruct.bgTiles + 0x1000, unknownStruct.unk4 + 0x400, unknownStruct.tilesOffset);
    }
}

static void sub_80A46A0(void)
{
    s32 i, j;
    struct UnknownAnimStruct2 unknownStruct;
    u16 *ptr;

    if (IsSpeciesNotUnown(gContestResources->field_18->unk0))
    {
        sub_80A6B30(&unknownStruct);
        ptr = unknownStruct.unk4;
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
    struct UnknownAnimStruct2 unknownStruct;
    sub_80A6B30(&unknownStruct);

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
    struct UnknownAnimStruct2 unknownStruct;

    spriteId = gTasks[taskId].data[0];
    palIndex = gTasks[taskId].data[6];
    sub_80A6B30(&unknownStruct);
    x = gTasks[taskId].data[1] - (gSprites[spriteId].pos1.x + gSprites[spriteId].pos2.x);
    y = gTasks[taskId].data[2] - (gSprites[spriteId].pos1.y + gSprites[spriteId].pos2.y);

    if (gTasks[taskId].data[5] == 0)
    {
        u16 *src;
        u16 *dst;

        gBattle_BG1_X = x + gTasks[taskId].data[3];
        gBattle_BG1_Y = y + gTasks[taskId].data[4];
        src = gPlttBufferFaded + 0x100 + palIndex * 16;
        dst = gPlttBufferFaded + 0x100 + unknownStruct.unk8 * 16 - 256;
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

        sub_80A438C(battlerId, toBG_2, FALSE);
    }

    battlerId ^= BIT_FLANK;
    if (animBattlerId > 1 && IsBattlerSpriteVisible(battlerId))
    {
        u8 position = GetBattlerPosition(battlerId);
        if (position == B_POSITION_OPPONENT_LEFT || position == B_POSITION_PLAYER_RIGHT || IsContest())
            toBG_2 = FALSE;
        else
            toBG_2 = TRUE;

        sub_80A438C(battlerId, toBG_2, FALSE);
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
    SetGpuReg(REG_OFFSET_BLDCNT, 0x3F40);
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
        const void *tilemap = gBattleAnimBackgroundTable[bgId].tilemap;
        void *dmaSrc;
        void *dmaDest;

        LZDecompressWram(tilemap, gDecompressionBuffer);
        sub_80A4720(sub_80A6D94(), (void*)(gDecompressionBuffer), 0x100, 0);
        dmaSrc = gDecompressionBuffer;
        dmaDest = (void *)(VRAM + 0xD000);
        DmaCopy32(3, dmaSrc, dmaDest, 0x800);
        LZDecompressVram(gBattleAnimBackgroundTable[bgId].image, (void *)(VRAM + 0x2000));
        LoadCompressedPalette(gBattleAnimBackgroundTable[bgId].palette, sub_80A6D94() * 16, 32);
    }
    else
    {
        LZDecompressVram(gBattleAnimBackgroundTable[bgId].tilemap, (void *)(VRAM + 0xD000));
        LZDecompressVram(gBattleAnimBackgroundTable[bgId].image, (void *)(VRAM + 0x8000));
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
            r4 = sub_80A8364(gBattleAnimAttacker);
            spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        }
        else
        {
            r4 = sub_80A8364(gBattleAnimTarget);
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
            r4 = sub_80A8364(gBattleAnimAttacker);
            spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);
        }
        else
        {
            r4 = sub_80A8364(gBattleAnimTarget);
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
