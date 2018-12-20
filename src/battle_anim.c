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
    {gBattleAnimSpriteSheet_000, 0x0200, ANIM_TAG_BONE},
    {gBattleAnimSpriteSheet_001, 0x0300, ANIM_TAG_SPARK},
    {gBattleAnimSpriteSheet_002, 0x0200, ANIM_TAG_PENCIL},
    {gBattleAnimSpriteSheet_003, 0x0100, ANIM_TAG_AIR_WAVE},
    {gBattleAnimSpriteSheet_004, 0x0200, ANIM_TAG_UNUSED_ORB},
    {gBattleAnimSpriteSheet_005, 0x0400, ANIM_TAG_SWORD},
    {gBattleAnimSpriteSheet_006, 0x0180, ANIM_TAG_SEED},
    {gBattleAnimSpriteSheet_007, 0x0800, ANIM_TAG_UNUSED_EXPLOSION},
    {gBattleAnimSpriteSheet_008, 0x0020, ANIM_TAG_UNUSED_PINK_ORB},
    {gBattleAnimSpriteSheet_009, 0x0400, ANIM_TAG_GUST},
    {gBattleAnimSpriteSheet_010, 0x1200, ANIM_TAG_ICE_CUBE},
    {gBattleAnimSpriteSheet_011, 0x0180, ANIM_TAG_SPARK_2},
    {gBattleAnimSpriteSheet_012, 0x0080, ANIM_TAG_UNUSED_ORANGE},
    {gBattleAnimSpriteSheet_013, 0x0080, ANIM_TAG_YELLOW_BALL},
    {gBattleAnimSpriteSheet_014, 0x0280, ANIM_TAG_LOCK_ON},
    {gBattleAnimSpriteSheet_015, 0x0080, ANIM_TAG_TIED_BAG},
    {gBattleAnimSpriteSheet_016, 0x0100, ANIM_TAG_BLACK_SMOKE},
    {gBattleAnimSpriteSheet_017, 0x0020, ANIM_TAG_BLACK_BALL},
    {gBattleAnimSpriteSheet_018, 0x0080, ANIM_TAG_CONVERSION},
    {gBattleAnimSpriteSheet_019, 0x0400, ANIM_TAG_UNUSED_GLASS},
    {gBattleAnimSpriteSheet_020, 0x0200, ANIM_TAG_HORN_HIT},
    {gBattleAnimSpriteSheet_021, 0x0A00, ANIM_TAG_UNUSED_HIT},
    {gBattleAnimSpriteSheet_021, 0x0A00, ANIM_TAG_UNUSED_HIT_2},
    {gBattleAnimSpriteSheet_023, 0x0380, ANIM_TAG_UNUSED_BLUE_SHARDS},
    {gBattleAnimSpriteSheet_024, 0x0300, ANIM_TAG_UNUSED_CLOSING_EYE},
    {gBattleAnimSpriteSheet_025, 0x0A00, ANIM_TAG_UNUSED_WAVING_HAND},
    {gBattleAnimSpriteSheet_026, 0x0A00, ANIM_TAG_UNUSED_HIT_DUPLICATE},
    {gBattleAnimSpriteSheet_027, 0x0A00, ANIM_TAG_LEER},
    {gBattleAnimSpriteSheet_028, 0x0A00, ANIM_TAG_UNUSED_BLUE_BURST},
    {gBattleAnimSpriteSheet_029, 0x0A00, ANIM_TAG_SMALL_EMBER},
    {gBattleAnimSpriteSheet_030, 0x0A00, ANIM_TAG_GRAY_SMOKE},
    {gBattleAnimSpriteSheet_031, 0x0E00, ANIM_TAG_BLUE_STAR},
    {gBattleAnimSpriteSheet_032, 0x0380, ANIM_TAG_UNUSED_BUBBLE_BURST},
    {gBattleAnimSpriteSheet_033, 0x1000, ANIM_TAG_FIRE},
    {gBattleAnimSpriteSheet_034, 0x0800, ANIM_TAG_UNUSED_SPINNING_FIRE},
    {gBattleAnimSpriteSheet_035, 0x0A00, ANIM_TAG_FIRE_PLUME},
    {gBattleAnimSpriteSheet_036, 0x0800, ANIM_TAG_UNUSED_LIGHTNING},
    {gBattleAnimSpriteSheet_037, 0x0A00, ANIM_TAG_LIGHTNING},
    {gBattleAnimSpriteSheet_038, 0x0A00, ANIM_TAG_UNUSED_CLAW_SLASH},
    {gBattleAnimSpriteSheet_039, 0x0A00, ANIM_TAG_CLAW_SLASH},
    {gBattleAnimSpriteSheet_040, 0x0A00, ANIM_TAG_UNUSED_SCRATCH},
    {gBattleAnimSpriteSheet_041, 0x0A00, ANIM_TAG_UNUSED_SCRATCH_2},
    {gBattleAnimSpriteSheet_042, 0x0A00, ANIM_TAG_UNUSED_BUBBLE_BURST_2},
    {gBattleAnimSpriteSheet_043, 0x0A00, ANIM_TAG_ICE_CHUNK},
    {gBattleAnimSpriteSheet_044, 0x0A00, ANIM_TAG_UNUSED_GLASS_2},
    {gBattleAnimSpriteSheet_045, 0x0A00, ANIM_TAG_UNUSED_PINK_HEART},
    {gBattleAnimSpriteSheet_046, 0x1000, ANIM_TAG_UNUSED_SAP_DRIP},
    {gBattleAnimSpriteSheet_046, 0x1000, ANIM_TAG_UNUSED_SAP_DRIP_2},
    {gBattleAnimSpriteSheet_048, 0x1000, ANIM_TAG_SPARKLE_1},
    {gBattleAnimSpriteSheet_048, 0x1000, ANIM_TAG_SPARKLE_2},
    {gBattleAnimSpriteSheet_050, 0x0200, ANIM_TAG_HUMANOID_FOOT},
    {gBattleAnimSpriteSheet_051, 0x0200, ANIM_TAG_UNUSED_MONSTER_FOOT},
    {gBattleAnimSpriteSheet_052, 0x0200, ANIM_TAG_UNUSED_HUMANOID_HAND},
    {gBattleAnimSpriteSheet_053, 0x0800, ANIM_TAG_NOISE_LINE},
    {gBattleAnimSpriteSheet_054, 0x0080, ANIM_TAG_UNUSED_YELLOW_UNK},
    {gBattleAnimSpriteSheet_055, 0x0200, ANIM_TAG_UNUSED_RED_FIST},
    {gBattleAnimSpriteSheet_056, 0x1000, ANIM_TAG_SLAM_HIT},
    {gBattleAnimSpriteSheet_057, 0x0180, ANIM_TAG_UNUSED_RING},
    {gBattleAnimSpriteSheet_058, 0x0C00, ANIM_TAG_ROCKS},
    {gBattleAnimSpriteSheet_059, 0x0100, ANIM_TAG_UNUSED_Z},
    {gBattleAnimSpriteSheet_060, 0x0040, ANIM_TAG_UNUSED_YELLOW_UNK_2},
    {gBattleAnimSpriteSheet_061, 0x0180, ANIM_TAG_UNUSED_AIR_SLASH},
    {gBattleAnimSpriteSheet_062, 0x0800, ANIM_TAG_UNUSED_SPINNING_GREEN_ORBS},
    {gBattleAnimSpriteSheet_063, 0x0480, ANIM_TAG_LEAF},
    {gBattleAnimSpriteSheet_064, 0x0200, ANIM_TAG_FINGER},
    {gBattleAnimSpriteSheet_065, 0x0200, ANIM_TAG_POISON_POWDER},
    {gBattleAnimSpriteSheet_066, 0x0100, ANIM_TAG_UNUSED_BROWN_TRIANGLE},
    {gBattleAnimSpriteSheet_065, 0x0200, ANIM_TAG_SLEEP_POWDER},
    {gBattleAnimSpriteSheet_065, 0x0200, ANIM_TAG_STUN_SPORE},
    {gBattleAnimSpriteSheet_065, 0x0200, ANIM_TAG_UNUSED_POWDER},
    {gBattleAnimSpriteSheet_070, 0x0200, ANIM_TAG_SPARKLE_3},
    {gBattleAnimSpriteSheet_071, 0x0A00, ANIM_TAG_SPARKLE_4},
    {gBattleAnimSpriteSheet_072, 0x0300, ANIM_TAG_MUSIC_NOTES},
    {gBattleAnimSpriteSheet_073, 0x0180, ANIM_TAG_DUCK},
    {gBattleAnimSpriteSheet_074, 0x00A0, ANIM_TAG_MUD_SAND},
    {gBattleAnimSpriteSheet_075, 0x0700, ANIM_TAG_ALERT},
    {gBattleAnimSpriteSheet_076, 0x0400, ANIM_TAG_UNUSED_BLUE_FLAMES},
    {gBattleAnimSpriteSheet_077, 0x0200, ANIM_TAG_UNUSED_BLUE_FLAMES_2},
    {gBattleAnimSpriteSheet_078, 0x0300, ANIM_TAG_UNUSED_SHOCK},
    {gBattleAnimSpriteSheet_079, 0x0C00, ANIM_TAG_SHOCK},
    {gBattleAnimSpriteSheet_080, 0x0A00, ANIM_TAG_UNUSED_BELL},
    {gBattleAnimSpriteSheet_081, 0x0080, ANIM_TAG_UNUSED_PINK_GLOVE},
    {gBattleAnimSpriteSheet_082, 0x0040, ANIM_TAG_UNUSED_BLUE_LINES},
    {gBattleAnimSpriteSheet_083, 0x0E00, ANIM_TAG_UNUSED_IMPACT},
    {gBattleAnimSpriteSheet_084, 0x0E00, ANIM_TAG_UNUSED_IMPACT_2},
    {gBattleAnimSpriteSheet_085, 0x0280, ANIM_TAG_UNUSED_RETICLE},
    {gBattleAnimSpriteSheet_086, 0x0200, ANIM_TAG_BREATH},
    {gBattleAnimSpriteSheet_087, 0x0080, ANIM_TAG_ANGER},
    {gBattleAnimSpriteSheet_088, 0x00C0, ANIM_TAG_UNUSED_SNOWBALL},
    {gBattleAnimSpriteSheet_089, 0x0A00, ANIM_TAG_UNUSED_VINE},
    {gBattleAnimSpriteSheet_090, 0x0200, ANIM_TAG_UNUSED_SWORD},
    {gBattleAnimSpriteSheet_091, 0x0180, ANIM_TAG_UNUSED_CLAPPING},
    {gBattleAnimSpriteSheet_092, 0x0080, ANIM_TAG_UNUSED_RED_TUBE},
    {gBattleAnimSpriteSheet_093, 0x1000, ANIM_TAG_AMNESIA},
    {gBattleAnimSpriteSheet_094, 0x0A00, ANIM_TAG_UNUSED_STRING},
    {gBattleAnimSpriteSheet_095, 0x0180, ANIM_TAG_UNUSED_PENCIL},
    {gBattleAnimSpriteSheet_096, 0x0380, ANIM_TAG_UNUSED_PETAL},
    {gBattleAnimSpriteSheet_097, 0x0C00, ANIM_TAG_BENT_SPOON},
    {gBattleAnimSpriteSheet_098, 0x0200, ANIM_TAG_UNUSED_WEB},
    {gBattleAnimSpriteSheet_099, 0x0200, ANIM_TAG_MILK_BOTTLE},
    {gBattleAnimSpriteSheet_100, 0x0200, ANIM_TAG_COIN},
    {gBattleAnimSpriteSheet_101, 0x0200, ANIM_TAG_UNUSED_CRACKED_EGG},
    {gBattleAnimSpriteSheet_102, 0x0400, ANIM_TAG_UNUSED_HATCHED_EGG},
    {gBattleAnimSpriteSheet_103, 0x0080, ANIM_TAG_UNUSED_FRESH_EGG},
    {gBattleAnimSpriteSheet_104, 0x0400, ANIM_TAG_UNUSED_FANGS},
    {gBattleAnimSpriteSheet_105, 0x0c00, ANIM_TAG_UNUSED_EXPLOSION_2},
    {gBattleAnimSpriteSheet_106, 0x0200, ANIM_TAG_UNUSED_EXPLOSION_3},
    {gBattleAnimSpriteSheet_107, 0x1000, ANIM_TAG_UNUSED_WATER_DROPLET},
    {gBattleAnimSpriteSheet_108, 0x0a00, ANIM_TAG_UNUSED_WATER_DROPLET_2},
    {gBattleAnimSpriteSheet_109, 0x0020, ANIM_TAG_UNUSED_SEED},
    {gBattleAnimSpriteSheet_110, 0x0e00, ANIM_TAG_UNUSED_SPROUT},
    {gBattleAnimSpriteSheet_111, 0x0080, ANIM_TAG_UNUSED_RED_WAND},
    {gBattleAnimSpriteSheet_112, 0x0a00, ANIM_TAG_UNUSED_PURPLE_GREEN_UNK},
    {gBattleAnimSpriteSheet_113, 0x0400, ANIM_TAG_UNUSED_WATER_COLUMN},
    {gBattleAnimSpriteSheet_114, 0x0200, ANIM_TAG_UNUSED_MUD_UNK},
    {gBattleAnimSpriteSheet_115, 0x0700, ANIM_TAG_RAIN_DROPS},
    {gBattleAnimSpriteSheet_116, 0x0800, ANIM_TAG_UNUSED_FURY_SWIPES},
    {gBattleAnimSpriteSheet_117, 0x0a00, ANIM_TAG_UNUSED_VINE_2},
    {gBattleAnimSpriteSheet_118, 0x0600, ANIM_TAG_UNUSED_TEETH},
    {gBattleAnimSpriteSheet_119, 0x0800, ANIM_TAG_UNUSED_BONE},
    {gBattleAnimSpriteSheet_120, 0x0200, ANIM_TAG_UNUSED_WHITE_BAG},
    {gBattleAnimSpriteSheet_121, 0x0040, ANIM_TAG_UNUSED_UNKNOWN},
    {gBattleAnimSpriteSheet_122, 0x0180, ANIM_TAG_UNUSED_PURPLE_CORAL},
    {gBattleAnimSpriteSheet_123, 0x0600, ANIM_TAG_UNUSED_PURPLE_DROPLET},
    {gBattleAnimSpriteSheet_124, 0x0600, ANIM_TAG_UNUSED_SHOCK_2},
    {gBattleAnimSpriteSheet_125, 0x0200, ANIM_TAG_UNUSED_CLOSING_EYE_2},
    {gBattleAnimSpriteSheet_126, 0x0080, ANIM_TAG_UNUSED_METAL_BALL},
    {gBattleAnimSpriteSheet_127, 0x0200, ANIM_TAG_UNUSED_MONSTER_DOLL},
    {gBattleAnimSpriteSheet_128, 0x0800, ANIM_TAG_UNUSED_WHIRLWIND},
    {gBattleAnimSpriteSheet_129, 0x0080, ANIM_TAG_UNUSED_WHIRLWIND_2},
    {gBattleAnimSpriteSheet_130, 0x0a00, ANIM_TAG_UNUSED_EXPLOSION_4},
    {gBattleAnimSpriteSheet_131, 0x0280, ANIM_TAG_UNUSED_EXPLOSION_5},
    {gBattleAnimSpriteSheet_132, 0x0280, ANIM_TAG_UNUSED_TONGUE},
    {gBattleAnimSpriteSheet_133, 0x0100, ANIM_TAG_UNUSED_SMOKE},
    {gBattleAnimSpriteSheet_134, 0x0200, ANIM_TAG_UNUSED_SMOKE_2},
    {gBattleAnimSpriteSheet_135, 0x0200, ANIM_TAG_IMPACT},
    {gBattleAnimSpriteSheet_136, 0x0020, ANIM_TAG_CIRCLE_IMPACT},
    {gBattleAnimSpriteSheet_137, 0x0a00, ANIM_TAG_SCRATCH},
    {gBattleAnimSpriteSheet_138, 0x0800, ANIM_TAG_CUT},
    {gBattleAnimSpriteSheet_139, 0x0800, ANIM_TAG_SHARP_TEETH},
    {gBattleAnimSpriteSheet_140, 0x00c0, ANIM_TAG_RAINBOW_RINGS},
    {gBattleAnimSpriteSheet_141, 0x01c0, ANIM_TAG_ICE_CRYSTALS},
    {gBattleAnimSpriteSheet_142, 0x0100, ANIM_TAG_ICE_SPIKES},
    {gBattleAnimSpriteSheet_143, 0x0800, ANIM_TAG_HANDS_AND_FEET},
    {gBattleAnimSpriteSheet_144, 0x0200, ANIM_TAG_MIST_CLOUD},
    {gBattleAnimSpriteSheet_145, 0x0800, ANIM_TAG_CLAMP},
    {gBattleAnimSpriteSheet_146, 0x0180, ANIM_TAG_BUBBLE},
    {gBattleAnimSpriteSheet_147, 0x0180, ANIM_TAG_ORBS},
    {gBattleAnimSpriteSheet_148, 0x0200, ANIM_TAG_WATER_IMPACT},
    {gBattleAnimSpriteSheet_149, 0x0200, ANIM_TAG_WATER_ORB},
    {gBattleAnimSpriteSheet_150, 0x0180, ANIM_TAG_POISON_BUBBLE},
    {gBattleAnimSpriteSheet_151, 0x0400, ANIM_TAG_TOXIC_BUBBLE},
    {gBattleAnimSpriteSheet_152, 0x0080, ANIM_TAG_SPIKES},
    {gBattleAnimSpriteSheet_153, 0x0100, ANIM_TAG_HORN_HIT_2},
    {gBattleAnimSpriteSheet_154, 0x0100, ANIM_TAG_AIR_WAVE_2},
    {gBattleAnimSpriteSheet_155, 0x0140, ANIM_TAG_SMALL_BUBBLES},
    {gBattleAnimSpriteSheet_156, 0x0800, ANIM_TAG_ROUND_SHADOW},
    {gBattleAnimSpriteSheet_157, 0x0200, ANIM_TAG_SUNLIGHT},
    {gBattleAnimSpriteSheet_158, 0x0100, ANIM_TAG_SPORE},
    {gBattleAnimSpriteSheet_159, 0x00a0, ANIM_TAG_FLOWER},
    {gBattleAnimSpriteSheet_160, 0x0100, ANIM_TAG_RAZOR_LEAF},
    {gBattleAnimSpriteSheet_161, 0x0080, ANIM_TAG_NEEDLE},
    {gBattleAnimSpriteSheet_162, 0x0300, ANIM_TAG_WHIRLWIND_LINES},
    {gBattleAnimSpriteSheet_163, 0x0100, ANIM_TAG_GOLD_RING},
    {gBattleAnimSpriteSheet_163, 0x0100, ANIM_TAG_PURPLE_RING},
    {gBattleAnimSpriteSheet_163, 0x0100, ANIM_TAG_BLUE_RING},
    {gBattleAnimSpriteSheet_166, 0x0800, ANIM_TAG_GREEN_LIGHT_WALL},
    {gBattleAnimSpriteSheet_166, 0x0800, ANIM_TAG_BLUE_LIGHT_WALL},
    {gBattleAnimSpriteSheet_166, 0x0800, ANIM_TAG_RED_LIGHT_WALL},
    {gBattleAnimSpriteSheet_166, 0x0800, ANIM_TAG_GRAY_LIGHT_WALL},
    {gBattleAnimSpriteSheet_166, 0x0800, ANIM_TAG_ORANGE_LIGHT_WALL},
    {gBattleAnimSpriteSheet_171, 0x0080, ANIM_TAG_BLACK_BALL_2},
    {gBattleAnimSpriteSheet_144, 0x0200, ANIM_TAG_PURPLE_GAS_CLOUD},
    {gBattleAnimSpriteSheet_173, 0x0200, ANIM_TAG_SPARK_H},
    {gBattleAnimSpriteSheet_174, 0x0200, ANIM_TAG_YELLOW_STAR},
    {gBattleAnimSpriteSheet_175, 0x0080, ANIM_TAG_LARGE_FRESH_EGG},
    {gBattleAnimSpriteSheet_176, 0x0200, ANIM_TAG_SHADOW_BALL},
    {gBattleAnimSpriteSheet_177, 0x0500, ANIM_TAG_LICK},
    {gBattleAnimSpriteSheet_178, 0x0800, ANIM_TAG_UNUSED_VOID_LINES},
    {gBattleAnimSpriteSheet_179, 0x0400, ANIM_TAG_STRING},
    {gBattleAnimSpriteSheet_180, 0x0020, ANIM_TAG_WEB_THREAD},
    {gBattleAnimSpriteSheet_181, 0x0800, ANIM_TAG_SPIDER_WEB},
    {gBattleAnimSpriteSheet_182, 0x0100, ANIM_TAG_UNUSED_LIGHTBULB},
    {gBattleAnimSpriteSheet_183, 0x0800, ANIM_TAG_SLASH},
    {gBattleAnimSpriteSheet_184, 0x0400, ANIM_TAG_FOCUS_ENERGY},
    {gBattleAnimSpriteSheet_185, 0x0a00, ANIM_TAG_SPHERE_TO_CUBE},
    {gBattleAnimSpriteSheet_186, 0x1000, ANIM_TAG_TENDRILS},
    {gBattleAnimSpriteSheet_187, 0x0800, ANIM_TAG_EYE},
    {gBattleAnimSpriteSheet_188, 0x0400, ANIM_TAG_WHITE_SHADOW},
    {gBattleAnimSpriteSheet_189, 0x0200, ANIM_TAG_TEAL_ALERT},
    {gBattleAnimSpriteSheet_190, 0x0800, ANIM_TAG_OPENING_EYE},
    {gBattleAnimSpriteSheet_191, 0x0800, ANIM_TAG_ROUND_WHITE_HALO},
    {gBattleAnimSpriteSheet_192, 0x0800, ANIM_TAG_FANG_ATTACK},
    {gBattleAnimSpriteSheet_193, 0x0200, ANIM_TAG_PURPLE_HAND_OUTLINE},
    {gBattleAnimSpriteSheet_194, 0x0800, ANIM_TAG_MOON},
    {gBattleAnimSpriteSheet_195, 0x0200, ANIM_TAG_GREEN_SPARKLE},
    {gBattleAnimSpriteSheet_196, 0x0800, ANIM_TAG_SPIRAL},
    {gBattleAnimSpriteSheet_197, 0x0200, ANIM_TAG_SNORE_Z},
    {gBattleAnimSpriteSheet_198, 0x0800, ANIM_TAG_EXPLOSION},
    {gBattleAnimSpriteSheet_199, 0x0400, ANIM_TAG_NAIL},
    {gBattleAnimSpriteSheet_200, 0x0200, ANIM_TAG_GHOSTLY_SPIRIT},
    {gBattleAnimSpriteSheet_201, 0x0a80, ANIM_TAG_WARM_ROCK},
    {gBattleAnimSpriteSheet_202, 0x0600, ANIM_TAG_BREAKING_EGG},
    {gBattleAnimSpriteSheet_203, 0x0800, ANIM_TAG_THIN_RING},
    {gBattleAnimSpriteSheet_204, 0x0200, ANIM_TAG_UNUSED_PUNCH_IMPACT},
    {gBattleAnimSpriteSheet_205, 0x0600, ANIM_TAG_BELL},
    {gBattleAnimSpriteSheet_206, 0x0800, ANIM_TAG_MUSIC_NOTES_2},
    {gBattleAnimSpriteSheet_207, 0x0180, ANIM_TAG_SPEED_DUST},
    {gBattleAnimSpriteSheet_208, 0x0800, ANIM_TAG_TORN_METAL},
    {gBattleAnimSpriteSheet_209, 0x0800, ANIM_TAG_THOUGHT_BUBBLE},
    {gBattleAnimSpriteSheet_210, 0x0080, ANIM_TAG_MAGENTA_HEART},
    {gBattleAnimSpriteSheet_211, 0x0080, ANIM_TAG_ELECTRIC_ORBS},
    {gBattleAnimSpriteSheet_212, 0x0800, ANIM_TAG_CIRCLE_OF_LIGHT},
    {gBattleAnimSpriteSheet_213, 0x0800, ANIM_TAG_ELECTRICITY},
    {gBattleAnimSpriteSheet_214, 0x0600, ANIM_TAG_FINGER_2},
    {gBattleAnimSpriteSheet_215, 0x0600, ANIM_TAG_MOVEMENT_WAVES},
    {gBattleAnimSpriteSheet_210, 0x0080, ANIM_TAG_RED_HEART},
    {gBattleAnimSpriteSheet_217, 0x0080, ANIM_TAG_RED_ORB},
    {gBattleAnimSpriteSheet_218, 0x0180, ANIM_TAG_EYE_SPARKLE},
    {gBattleAnimSpriteSheet_210, 0x0080, ANIM_TAG_PINK_HEART},
    {gBattleAnimSpriteSheet_220, 0x0200, ANIM_TAG_ANGEL},
    {gBattleAnimSpriteSheet_221, 0x0400, ANIM_TAG_DEVIL},
    {gBattleAnimSpriteSheet_222, 0x0a00, ANIM_TAG_SWIPE},
    {gBattleAnimSpriteSheet_223, 0x0800, ANIM_TAG_ROOTS},
    {gBattleAnimSpriteSheet_224, 0x0200, ANIM_TAG_ITEM_BAG},
    {gBattleAnimSpriteSheet_225, 0x0400, ANIM_TAG_JAGGED_MUSIC_NOTE},
    {gBattleAnimSpriteSheet_226, 0x0080, ANIM_TAG_POKEBALL},
    {gBattleAnimSpriteSheet_227, 0x0800, ANIM_TAG_SPOTLIGHT},
    {gBattleAnimSpriteSheet_228, 0x0200, ANIM_TAG_LETTER_Z},
    {gBattleAnimSpriteSheet_229, 0x0300, ANIM_TAG_RAPID_SPIN},
    {gBattleAnimSpriteSheet_230, 0x0800, ANIM_TAG_TRI_FORCE_TRIANGLE},
    {gBattleAnimSpriteSheet_231, 0x0380, ANIM_TAG_WISP_ORB},
    {gBattleAnimSpriteSheet_232, 0x0800, ANIM_TAG_WISP_FIRE},
    {gBattleAnimSpriteSheet_233, 0x00c0, ANIM_TAG_GOLD_STARS},
    {gBattleAnimSpriteSheet_234, 0x0800, ANIM_TAG_ECLIPSING_ORB},
    {gBattleAnimSpriteSheet_235, 0x0060, ANIM_TAG_GRAY_ORB},
    {gBattleAnimSpriteSheet_235, 0x0060, ANIM_TAG_BLUE_ORB},
    {gBattleAnimSpriteSheet_235, 0x0060, ANIM_TAG_RED_ORB_2},
    {gBattleAnimSpriteSheet_238, 0x0080, ANIM_TAG_PINK_PETAL},
    {gBattleAnimSpriteSheet_239, 0x0180, ANIM_TAG_PAIN_SPLIT},
    {gBattleAnimSpriteSheet_240, 0x0180, ANIM_TAG_CONFETTI},
    {gBattleAnimSpriteSheet_241, 0x0200, ANIM_TAG_GREEN_STAR},
    {gBattleAnimSpriteSheet_242, 0x0200, ANIM_TAG_PINK_CLOUD},
    {gBattleAnimSpriteSheet_243, 0x0020, ANIM_TAG_SWEAT_DROP},
    {gBattleAnimSpriteSheet_244, 0x0400, ANIM_TAG_GUARD_RING},
    {gBattleAnimSpriteSheet_245, 0x0600, ANIM_TAG_PURPLE_SCRATCH},
    {gBattleAnimSpriteSheet_246, 0x1000, ANIM_TAG_PURPLE_SWIPE},
    {gBattleAnimSpriteSheet_247, 0x0400, ANIM_TAG_TAG_HAND},
    {gBattleAnimSpriteSheet_248, 0x0020, ANIM_TAG_SMALL_RED_EYE},
    {gBattleAnimSpriteSheet_249, 0x0080, ANIM_TAG_HOLLOW_ORB},
    {gBattleAnimSpriteSheet_250, 0x0800, ANIM_TAG_X_SIGN},
    {gBattleAnimSpriteSheet_251, 0x0080, ANIM_TAG_BLUEGREEN_ORB},
    {gBattleAnimSpriteSheet_252, 0x0200, ANIM_TAG_PAW_PRINT},
    {gBattleAnimSpriteSheet_253, 0x0400, ANIM_TAG_PURPLE_FLAME},
    {gBattleAnimSpriteSheet_254, 0x0200, ANIM_TAG_RED_BALL},
    {gBattleAnimSpriteSheet_255, 0x0200, ANIM_TAG_SMELLINGSALT_EFFECT},
    {gBattleAnimSpriteSheet_256, 0x0800, ANIM_TAG_METEOR},
    {gBattleAnimSpriteSheet_257, 0x0280, ANIM_TAG_FLAT_ROCK},
    {gBattleAnimSpriteSheet_258, 0x0200, ANIM_TAG_MAGNIFYING_GLASS},
    {gBattleAnimSpriteSheet_149, 0x0200, ANIM_TAG_BROWN_ORB},
    {gBattleAnimSpriteSheet_260, 0x0400, ANIM_TAG_METAL_SOUND_WAVES},
    {gBattleAnimSpriteSheet_261, 0x0200, ANIM_TAG_FLYING_DIRT},
    {gBattleAnimSpriteSheet_262, 0x0200, ANIM_TAG_ICICLE_SPEAR},
    {gBattleAnimSpriteSheet_263, 0x0080, ANIM_TAG_HAIL},
    {gBattleAnimSpriteSheet_264, 0x0020, ANIM_TAG_GLOWY_RED_ORB},
    {gBattleAnimSpriteSheet_264, 0x0020, ANIM_TAG_GLOWY_GREEN_ORB},
    {gBattleAnimSpriteSheet_266, 0x0080, ANIM_TAG_GREEN_SPIKE},
    {gBattleAnimSpriteSheet_212, 0x0800, ANIM_TAG_WHITE_CIRCLE_OF_LIGHT},
    {gBattleAnimSpriteSheet_264, 0x0020, ANIM_TAG_GLOWY_BLUE_ORB},
    {gBattleAnimSpriteSheet_269, 0x0080, ANIM_TAG_UNUSED_RED_BRICK},
    {gBattleAnimSpriteSheet_270, 0x0400, ANIM_TAG_WHITE_FEATHER},
    {gBattleAnimSpriteSheet_271, 0x0080, ANIM_TAG_SPARKLE_6},
    {gBattleAnimSpriteSheet_272, 0x0800, ANIM_TAG_SPLASH},
    {gBattleAnimSpriteSheet_273, 0x0020, ANIM_TAG_SWEAT_BEAD},
    {gBattleAnimSpriteSheet_274, 0x0800, ANIM_TAG_UNUSED_GEM_1},
    {gBattleAnimSpriteSheet_275, 0x0800, ANIM_TAG_UNUSED_GEM_2},
    {gBattleAnimSpriteSheet_276, 0x0800, ANIM_TAG_UNUSED_GEM_3},
    {gBattleAnimSpriteSheet_277, 0x1000, ANIM_TAG_SLAM_HIT_2},
    {gBattleAnimSpriteSheet_278, 0x0800, ANIM_TAG_RECYCLE},
    {gBattleAnimSpriteSheet_279, 0x00a0, ANIM_TAG_UNUSED_RED_PARTICLES},
    {gBattleAnimSpriteSheet_280, 0x0800, ANIM_TAG_PROTECT},
    {gBattleAnimSpriteSheet_281, 0x0200, ANIM_TAG_DIRT_MOUND},
    {gBattleAnimSpriteSheet_282, 0x0600, ANIM_TAG_SHOCK_3},
    {gBattleAnimSpriteSheet_283, 0x0200, ANIM_TAG_WEATHER_BALL},
    {gBattleAnimSpriteSheet_284, 0x0800, ANIM_TAG_BIRD},
    {gBattleAnimSpriteSheet_285, 0x0200, ANIM_TAG_CROSS_IMPACT},
    {gBattleAnimSpriteSheet_183, 0x0800, ANIM_TAG_SLASH_2},
    {gBattleAnimSpriteSheet_056, 0x1000, ANIM_TAG_WHIP_HIT},
    {gBattleAnimSpriteSheet_163, 0x0100, ANIM_TAG_BLUE_RING_2},
};


const struct CompressedSpritePalette gBattleAnimPaletteTable[] =
{
    {gBattleAnimSpritePalette_000, ANIM_TAG_BONE},
    {gBattleAnimSpritePalette_001, ANIM_TAG_SPARK},
    {gBattleAnimSpritePalette_002, ANIM_TAG_PENCIL},
    {gBattleAnimSpritePalette_003, ANIM_TAG_AIR_WAVE},
    {gBattleAnimSpritePalette_004, ANIM_TAG_UNUSED_ORB},
    {gBattleAnimSpritePalette_005, ANIM_TAG_SWORD},
    {gBattleAnimSpritePalette_006, ANIM_TAG_SEED},
    {gBattleAnimSpritePalette_007, ANIM_TAG_UNUSED_EXPLOSION},
    {gBattleAnimSpritePalette_008, ANIM_TAG_UNUSED_PINK_ORB},
    {gBattleAnimSpritePalette_009, ANIM_TAG_GUST},
    {gBattleAnimSpritePalette_010, ANIM_TAG_ICE_CUBE},
    {gBattleAnimSpritePalette_011, ANIM_TAG_SPARK_2},
    {gBattleAnimSpritePalette_012, ANIM_TAG_UNUSED_ORANGE},
    {gBattleAnimSpritePalette_013, ANIM_TAG_YELLOW_BALL},
    {gBattleAnimSpritePalette_014, ANIM_TAG_LOCK_ON},
    {gBattleAnimSpritePalette_015, ANIM_TAG_TIED_BAG},
    {gBattleAnimSpritePalette_016, ANIM_TAG_BLACK_SMOKE},
    {gBattleAnimSpritePalette_016, ANIM_TAG_BLACK_BALL},
    {gBattleAnimSpritePalette_018, ANIM_TAG_CONVERSION},
    {gBattleAnimSpritePalette_019, ANIM_TAG_UNUSED_GLASS},
    {gBattleAnimSpritePalette_020, ANIM_TAG_HORN_HIT},
    {gBattleAnimSpritePalette_021, ANIM_TAG_UNUSED_HIT},
    {gBattleAnimSpritePalette_022, ANIM_TAG_UNUSED_HIT_2},
    {gBattleAnimSpritePalette_023, ANIM_TAG_UNUSED_BLUE_SHARDS},
    {gBattleAnimSpritePalette_024, ANIM_TAG_UNUSED_CLOSING_EYE},
    {gBattleAnimSpritePalette_025, ANIM_TAG_UNUSED_WAVING_HAND},
    {gBattleAnimSpritePalette_026, ANIM_TAG_UNUSED_HIT_DUPLICATE},
    {gBattleAnimSpritePalette_027, ANIM_TAG_LEER},
    {gBattleAnimSpritePalette_028, ANIM_TAG_UNUSED_BLUE_BURST},
    {gBattleAnimSpritePalette_029, ANIM_TAG_SMALL_EMBER},
    {gBattleAnimSpritePalette_030, ANIM_TAG_GRAY_SMOKE},
    {gBattleAnimSpritePalette_031, ANIM_TAG_BLUE_STAR},
    {gBattleAnimSpritePalette_032, ANIM_TAG_UNUSED_BUBBLE_BURST},
    {gBattleAnimSpritePalette_033, ANIM_TAG_FIRE},
    {gBattleAnimSpritePalette_033, ANIM_TAG_UNUSED_SPINNING_FIRE},
    {gBattleAnimSpritePalette_033, ANIM_TAG_FIRE_PLUME},
    {gBattleAnimSpritePalette_036, ANIM_TAG_UNUSED_LIGHTNING},
    {gBattleAnimSpritePalette_036, ANIM_TAG_LIGHTNING},
    {gBattleAnimSpritePalette_038, ANIM_TAG_UNUSED_CLAW_SLASH},
    {gBattleAnimSpritePalette_039, ANIM_TAG_CLAW_SLASH},
    {gBattleAnimSpritePalette_038, ANIM_TAG_UNUSED_SCRATCH},
    {gBattleAnimSpritePalette_038, ANIM_TAG_UNUSED_SCRATCH_2},
    {gBattleAnimSpritePalette_042, ANIM_TAG_UNUSED_BUBBLE_BURST_2},
    {gBattleAnimSpritePalette_043, ANIM_TAG_ICE_CHUNK},
    {gBattleAnimSpritePalette_044, ANIM_TAG_UNUSED_GLASS_2},
    {gBattleAnimSpritePalette_045, ANIM_TAG_UNUSED_PINK_HEART},
    {gBattleAnimSpritePalette_046, ANIM_TAG_UNUSED_SAP_DRIP},
    {gBattleAnimSpritePalette_047, ANIM_TAG_UNUSED_SAP_DRIP},
    {gBattleAnimSpritePalette_048, ANIM_TAG_SPARKLE_1},
    {gBattleAnimSpritePalette_049, ANIM_TAG_SPARKLE_2},
    {gBattleAnimSpritePalette_050, ANIM_TAG_HUMANOID_FOOT},
    {gBattleAnimSpritePalette_050, ANIM_TAG_UNUSED_MONSTER_FOOT},
    {gBattleAnimSpritePalette_050, ANIM_TAG_UNUSED_HUMANOID_HAND},
    {gBattleAnimSpritePalette_026, ANIM_TAG_NOISE_LINE},
    {gBattleAnimSpritePalette_054, ANIM_TAG_UNUSED_YELLOW_UNK},
    {gBattleAnimSpritePalette_050, ANIM_TAG_UNUSED_RED_FIST},
    {gBattleAnimSpritePalette_056, ANIM_TAG_SLAM_HIT},
    {gBattleAnimSpritePalette_057, ANIM_TAG_UNUSED_RING},
    {gBattleAnimSpritePalette_058, ANIM_TAG_ROCKS},
    {gBattleAnimSpritePalette_059, ANIM_TAG_UNUSED_Z},
    {gBattleAnimSpritePalette_060, ANIM_TAG_UNUSED_YELLOW_UNK_2},
    {gBattleAnimSpritePalette_061, ANIM_TAG_UNUSED_AIR_SLASH},
    {gBattleAnimSpritePalette_062, ANIM_TAG_UNUSED_SPINNING_GREEN_ORBS},
    {gBattleAnimSpritePalette_063, ANIM_TAG_LEAF},
    {gBattleAnimSpritePalette_064, ANIM_TAG_FINGER},
    {gBattleAnimSpritePalette_065, ANIM_TAG_POISON_POWDER},
    {gBattleAnimSpritePalette_066, ANIM_TAG_UNUSED_BROWN_TRIANGLE},
    {gBattleAnimSpritePalette_067, ANIM_TAG_SLEEP_POWDER},
    {gBattleAnimSpritePalette_068, ANIM_TAG_STUN_SPORE},
    {gBattleAnimSpritePalette_065, ANIM_TAG_UNUSED_POWDER},
    {gBattleAnimSpritePalette_070, ANIM_TAG_SPARKLE_3},
    {gBattleAnimSpritePalette_070, ANIM_TAG_SPARKLE_4},
    {gBattleAnimSpritePalette_072, ANIM_TAG_MUSIC_NOTES},
    {gBattleAnimSpritePalette_073, ANIM_TAG_DUCK},
    {gBattleAnimSpritePalette_074, ANIM_TAG_MUD_SAND},
    {gBattleAnimSpritePalette_075, ANIM_TAG_ALERT},
    {gBattleAnimSpritePalette_076, ANIM_TAG_UNUSED_BLUE_FLAMES},
    {gBattleAnimSpritePalette_076, ANIM_TAG_UNUSED_BLUE_FLAMES_2},
    {gBattleAnimSpritePalette_078, ANIM_TAG_UNUSED_SHOCK},
    {gBattleAnimSpritePalette_078, ANIM_TAG_SHOCK},
    {gBattleAnimSpritePalette_080, ANIM_TAG_UNUSED_BELL},
    {gBattleAnimSpritePalette_081, ANIM_TAG_UNUSED_PINK_GLOVE},
    {gBattleAnimSpritePalette_082, ANIM_TAG_UNUSED_BLUE_LINES},
    {gBattleAnimSpritePalette_083, ANIM_TAG_UNUSED_IMPACT},
    {gBattleAnimSpritePalette_084, ANIM_TAG_UNUSED_IMPACT_2},
    {gBattleAnimSpritePalette_085, ANIM_TAG_UNUSED_RETICLE},
    {gBattleAnimSpritePalette_086, ANIM_TAG_BREATH},
    {gBattleAnimSpritePalette_087, ANIM_TAG_ANGER},
    {gBattleAnimSpritePalette_088, ANIM_TAG_UNUSED_SNOWBALL},
    {gBattleAnimSpritePalette_089, ANIM_TAG_UNUSED_VINE},
    {gBattleAnimSpritePalette_090, ANIM_TAG_UNUSED_SWORD},
    {gBattleAnimSpritePalette_091, ANIM_TAG_UNUSED_CLAPPING},
    {gBattleAnimSpritePalette_092, ANIM_TAG_UNUSED_RED_TUBE},
    {gBattleAnimSpritePalette_093, ANIM_TAG_AMNESIA},
    {gBattleAnimSpritePalette_094, ANIM_TAG_UNUSED_STRING},
    {gBattleAnimSpritePalette_095, ANIM_TAG_UNUSED_PENCIL},
    {gBattleAnimSpritePalette_096, ANIM_TAG_UNUSED_PETAL},
    {gBattleAnimSpritePalette_097, ANIM_TAG_BENT_SPOON},
    {gBattleAnimSpritePalette_094, ANIM_TAG_UNUSED_WEB},
    {gBattleAnimSpritePalette_099, ANIM_TAG_MILK_BOTTLE},
    {gBattleAnimSpritePalette_100, ANIM_TAG_COIN},
    {gBattleAnimSpritePalette_101, ANIM_TAG_UNUSED_CRACKED_EGG},
    {gBattleAnimSpritePalette_101, ANIM_TAG_UNUSED_HATCHED_EGG},
    {gBattleAnimSpritePalette_103, ANIM_TAG_UNUSED_FRESH_EGG},
    {gBattleAnimSpritePalette_104, ANIM_TAG_UNUSED_FANGS},
    {gBattleAnimSpritePalette_105, ANIM_TAG_UNUSED_EXPLOSION_2},
    {gBattleAnimSpritePalette_105, ANIM_TAG_UNUSED_EXPLOSION_3},
    {gBattleAnimSpritePalette_107, ANIM_TAG_UNUSED_WATER_DROPLET},
    {gBattleAnimSpritePalette_107, ANIM_TAG_UNUSED_WATER_DROPLET_2},
    {gBattleAnimSpritePalette_109, ANIM_TAG_UNUSED_SEED},
    {gBattleAnimSpritePalette_109, ANIM_TAG_UNUSED_SPROUT},
    {gBattleAnimSpritePalette_111, ANIM_TAG_UNUSED_RED_WAND},
    {gBattleAnimSpritePalette_112, ANIM_TAG_UNUSED_PURPLE_GREEN_UNK},
    {gBattleAnimSpritePalette_113, ANIM_TAG_UNUSED_WATER_COLUMN},
    {gBattleAnimSpritePalette_114, ANIM_TAG_UNUSED_MUD_UNK},
    {gBattleAnimSpritePalette_115, ANIM_TAG_RAIN_DROPS},
    {gBattleAnimSpritePalette_116, ANIM_TAG_UNUSED_FURY_SWIPES},
    {gBattleAnimSpritePalette_117, ANIM_TAG_UNUSED_VINE_2},
    {gBattleAnimSpritePalette_118, ANIM_TAG_UNUSED_TEETH},
    {gBattleAnimSpritePalette_119, ANIM_TAG_UNUSED_BONE},
    {gBattleAnimSpritePalette_120, ANIM_TAG_UNUSED_WHITE_BAG},
    {gBattleAnimSpritePalette_121, ANIM_TAG_UNUSED_UNKNOWN},
    {gBattleAnimSpritePalette_122, ANIM_TAG_UNUSED_PURPLE_CORAL},
    {gBattleAnimSpritePalette_122, ANIM_TAG_UNUSED_PURPLE_DROPLET},
    {gBattleAnimSpritePalette_124, ANIM_TAG_UNUSED_SHOCK_2},
    {gBattleAnimSpritePalette_125, ANIM_TAG_UNUSED_CLOSING_EYE_2},
    {gBattleAnimSpritePalette_126, ANIM_TAG_UNUSED_METAL_BALL},
    {gBattleAnimSpritePalette_127, ANIM_TAG_UNUSED_MONSTER_DOLL},
    {gBattleAnimSpritePalette_128, ANIM_TAG_UNUSED_WHIRLWIND},
    {gBattleAnimSpritePalette_128, ANIM_TAG_UNUSED_WHIRLWIND_2},
    {gBattleAnimSpritePalette_130, ANIM_TAG_UNUSED_EXPLOSION_4},
    {gBattleAnimSpritePalette_130, ANIM_TAG_UNUSED_EXPLOSION_5},
    {gBattleAnimSpritePalette_132, ANIM_TAG_UNUSED_TONGUE},
    {gBattleAnimSpritePalette_133, ANIM_TAG_UNUSED_SMOKE},
    {gBattleAnimSpritePalette_133, ANIM_TAG_UNUSED_SMOKE_2},
    {gBattleAnimSpritePalette_135, ANIM_TAG_IMPACT},
    {gBattleAnimSpritePalette_136, ANIM_TAG_CIRCLE_IMPACT},
    {gBattleAnimSpritePalette_135, ANIM_TAG_SCRATCH},
    {gBattleAnimSpritePalette_135, ANIM_TAG_CUT},
    {gBattleAnimSpritePalette_139, ANIM_TAG_SHARP_TEETH},
    {gBattleAnimSpritePalette_140, ANIM_TAG_RAINBOW_RINGS},
    {gBattleAnimSpritePalette_141, ANIM_TAG_ICE_CRYSTALS},
    {gBattleAnimSpritePalette_141, ANIM_TAG_ICE_SPIKES},
    {gBattleAnimSpritePalette_143, ANIM_TAG_HANDS_AND_FEET},
    {gBattleAnimSpritePalette_144, ANIM_TAG_MIST_CLOUD},
    {gBattleAnimSpritePalette_139, ANIM_TAG_CLAMP},
    {gBattleAnimSpritePalette_115, ANIM_TAG_BUBBLE},
    {gBattleAnimSpritePalette_147, ANIM_TAG_ORBS},
    {gBattleAnimSpritePalette_148, ANIM_TAG_WATER_IMPACT},
    {gBattleAnimSpritePalette_148, ANIM_TAG_WATER_ORB},
    {gBattleAnimSpritePalette_150, ANIM_TAG_POISON_BUBBLE},
    {gBattleAnimSpritePalette_150, ANIM_TAG_TOXIC_BUBBLE},
    {gBattleAnimSpritePalette_152, ANIM_TAG_SPIKES},
    {gBattleAnimSpritePalette_153, ANIM_TAG_HORN_HIT_2},
    {gBattleAnimSpritePalette_154, ANIM_TAG_AIR_WAVE_2},
    {gBattleAnimSpritePalette_155, ANIM_TAG_SMALL_BUBBLES},
    {gBattleAnimSpritePalette_156, ANIM_TAG_ROUND_SHADOW},
    {gBattleAnimSpritePalette_157, ANIM_TAG_SUNLIGHT},
    {gBattleAnimSpritePalette_158, ANIM_TAG_SPORE},
    {gBattleAnimSpritePalette_159, ANIM_TAG_FLOWER},
    {gBattleAnimSpritePalette_160, ANIM_TAG_RAZOR_LEAF},
    {gBattleAnimSpritePalette_161, ANIM_TAG_NEEDLE},
    {gBattleAnimSpritePalette_162, ANIM_TAG_WHIRLWIND_LINES},
    {gBattleAnimSpritePalette_163, ANIM_TAG_GOLD_RING},
    {gBattleAnimSpritePalette_164, ANIM_TAG_PURPLE_RING},
    {gBattleAnimSpritePalette_165, ANIM_TAG_BLUE_RING},
    {gBattleAnimSpritePalette_166, ANIM_TAG_GREEN_LIGHT_WALL},
    {gBattleAnimSpritePalette_167, ANIM_TAG_BLUE_LIGHT_WALL},
    {gBattleAnimSpritePalette_168, ANIM_TAG_RED_LIGHT_WALL},
    {gBattleAnimSpritePalette_169, ANIM_TAG_GRAY_LIGHT_WALL},
    {gBattleAnimSpritePalette_170, ANIM_TAG_ORANGE_LIGHT_WALL},
    {gBattleAnimSpritePalette_171, ANIM_TAG_BLACK_BALL_2},
    {gBattleAnimSpritePalette_172, ANIM_TAG_PURPLE_GAS_CLOUD},
    {gBattleAnimSpritePalette_001, ANIM_TAG_SPARK_H},
    {gBattleAnimSpritePalette_174, ANIM_TAG_YELLOW_STAR},
    {gBattleAnimSpritePalette_175, ANIM_TAG_LARGE_FRESH_EGG},
    {gBattleAnimSpritePalette_176, ANIM_TAG_SHADOW_BALL},
    {gBattleAnimSpritePalette_177, ANIM_TAG_LICK},
    {gBattleAnimSpritePalette_178, ANIM_TAG_UNUSED_VOID_LINES},
    {gBattleAnimSpritePalette_179, ANIM_TAG_STRING},
    {gBattleAnimSpritePalette_179, ANIM_TAG_WEB_THREAD},
    {gBattleAnimSpritePalette_179, ANIM_TAG_SPIDER_WEB},
    {gBattleAnimSpritePalette_182, ANIM_TAG_UNUSED_LIGHTBULB},
    {gBattleAnimSpritePalette_183, ANIM_TAG_SLASH},
    {gBattleAnimSpritePalette_184, ANIM_TAG_FOCUS_ENERGY},
    {gBattleAnimSpritePalette_185, ANIM_TAG_SPHERE_TO_CUBE},
    {gBattleAnimSpritePalette_186, ANIM_TAG_TENDRILS},
    {gBattleAnimSpritePalette_187, ANIM_TAG_EYE},
    {gBattleAnimSpritePalette_188, ANIM_TAG_WHITE_SHADOW},
    {gBattleAnimSpritePalette_189, ANIM_TAG_TEAL_ALERT},
    {gBattleAnimSpritePalette_190, ANIM_TAG_OPENING_EYE},
    {gBattleAnimSpritePalette_191, ANIM_TAG_ROUND_WHITE_HALO},
    {gBattleAnimSpritePalette_192, ANIM_TAG_FANG_ATTACK},
    {gBattleAnimSpritePalette_193, ANIM_TAG_PURPLE_HAND_OUTLINE},
    {gBattleAnimSpritePalette_194, ANIM_TAG_MOON},
    {gBattleAnimSpritePalette_195, ANIM_TAG_GREEN_SPARKLE},
    {gBattleAnimSpritePalette_196, ANIM_TAG_SPIRAL},
    {gBattleAnimSpritePalette_197, ANIM_TAG_SNORE_Z},
    {gBattleAnimSpritePalette_198, ANIM_TAG_EXPLOSION},
    {gBattleAnimSpritePalette_199, ANIM_TAG_NAIL},
    {gBattleAnimSpritePalette_200, ANIM_TAG_GHOSTLY_SPIRIT},
    {gBattleAnimSpritePalette_201, ANIM_TAG_WARM_ROCK},
    {gBattleAnimSpritePalette_202, ANIM_TAG_BREAKING_EGG},
    {gBattleAnimSpritePalette_203, ANIM_TAG_THIN_RING},
    {gBattleAnimSpritePalette_204, ANIM_TAG_UNUSED_PUNCH_IMPACT},
    {gBattleAnimSpritePalette_205, ANIM_TAG_BELL},
    {gBattleAnimSpritePalette_206, ANIM_TAG_MUSIC_NOTES_2},
    {gBattleAnimSpritePalette_207, ANIM_TAG_SPEED_DUST},
    {gBattleAnimSpritePalette_167, ANIM_TAG_TORN_METAL},
    {gBattleAnimSpritePalette_209, ANIM_TAG_THOUGHT_BUBBLE},
    {gBattleAnimSpritePalette_210, ANIM_TAG_MAGENTA_HEART},
    {gBattleAnimSpritePalette_211, ANIM_TAG_ELECTRIC_ORBS},
    {gBattleAnimSpritePalette_211, ANIM_TAG_CIRCLE_OF_LIGHT},
    {gBattleAnimSpritePalette_211, ANIM_TAG_ELECTRICITY},
    {gBattleAnimSpritePalette_064, ANIM_TAG_FINGER_2},
    {gBattleAnimSpritePalette_215, ANIM_TAG_MOVEMENT_WAVES},
    {gBattleAnimSpritePalette_216, ANIM_TAG_RED_HEART},
    {gBattleAnimSpritePalette_217, ANIM_TAG_RED_ORB},
    {gBattleAnimSpritePalette_218, ANIM_TAG_EYE_SPARKLE},
    {gBattleAnimSpritePalette_219, ANIM_TAG_PINK_HEART},
    {gBattleAnimSpritePalette_220, ANIM_TAG_ANGEL},
    {gBattleAnimSpritePalette_221, ANIM_TAG_DEVIL},
    {gBattleAnimSpritePalette_222, ANIM_TAG_SWIPE},
    {gBattleAnimSpritePalette_223, ANIM_TAG_ROOTS},
    {gBattleAnimSpritePalette_224, ANIM_TAG_ITEM_BAG},
    {gBattleAnimSpritePalette_225, ANIM_TAG_JAGGED_MUSIC_NOTE},
    {gBattleAnimSpritePalette_226, ANIM_TAG_POKEBALL},
    {gBattleAnimSpritePalette_226, ANIM_TAG_SPOTLIGHT},
    {gBattleAnimSpritePalette_228, ANIM_TAG_LETTER_Z},
    {gBattleAnimSpritePalette_229, ANIM_TAG_RAPID_SPIN},
    {gBattleAnimSpritePalette_230, ANIM_TAG_TRI_FORCE_TRIANGLE},
    {gBattleAnimSpritePalette_231, ANIM_TAG_WISP_ORB},
    {gBattleAnimSpritePalette_231, ANIM_TAG_WISP_FIRE},
    {gBattleAnimSpritePalette_233, ANIM_TAG_GOLD_STARS},
    {gBattleAnimSpritePalette_234, ANIM_TAG_ECLIPSING_ORB},
    {gBattleAnimSpritePalette_235, ANIM_TAG_GRAY_ORB},
    {gBattleAnimSpritePalette_236, ANIM_TAG_BLUE_ORB},
    {gBattleAnimSpritePalette_237, ANIM_TAG_RED_ORB_2},
    {gBattleAnimSpritePalette_238, ANIM_TAG_PINK_PETAL},
    {gBattleAnimSpritePalette_239, ANIM_TAG_PAIN_SPLIT},
    {gBattleAnimSpritePalette_240, ANIM_TAG_CONFETTI},
    {gBattleAnimSpritePalette_241, ANIM_TAG_GREEN_STAR},
    {gBattleAnimSpritePalette_242, ANIM_TAG_PINK_CLOUD},
    {gBattleAnimSpritePalette_243, ANIM_TAG_SWEAT_DROP},
    {gBattleAnimSpritePalette_244, ANIM_TAG_GUARD_RING},
    {gBattleAnimSpritePalette_245, ANIM_TAG_PURPLE_SCRATCH},
    {gBattleAnimSpritePalette_245, ANIM_TAG_PURPLE_SWIPE},
    {gBattleAnimSpritePalette_064, ANIM_TAG_TAG_HAND},
    {gBattleAnimSpritePalette_248, ANIM_TAG_SMALL_RED_EYE},
    {gBattleAnimSpritePalette_249, ANIM_TAG_HOLLOW_ORB},
    {gBattleAnimSpritePalette_249, ANIM_TAG_X_SIGN},
    {gBattleAnimSpritePalette_251, ANIM_TAG_BLUEGREEN_ORB},
    {gBattleAnimSpritePalette_252, ANIM_TAG_PAW_PRINT},
    {gBattleAnimSpritePalette_253, ANIM_TAG_PURPLE_FLAME},
    {gBattleAnimSpritePalette_254, ANIM_TAG_RED_BALL},
    {gBattleAnimSpritePalette_255, ANIM_TAG_SMELLINGSALT_EFFECT},
    {gBattleAnimSpritePalette_256, ANIM_TAG_METEOR},
    {gBattleAnimSpritePalette_257, ANIM_TAG_FLAT_ROCK},
    {gBattleAnimSpritePalette_258, ANIM_TAG_MAGNIFYING_GLASS},
    {gBattleAnimSpritePalette_259, ANIM_TAG_BROWN_ORB},
    {gBattleAnimSpritePalette_260, ANIM_TAG_METAL_SOUND_WAVES},
    {gBattleAnimSpritePalette_261, ANIM_TAG_FLYING_DIRT},
    {gBattleAnimSpritePalette_262, ANIM_TAG_ICICLE_SPEAR},
    {gBattleAnimSpritePalette_263, ANIM_TAG_HAIL},
    {gBattleAnimSpritePalette_264, ANIM_TAG_GLOWY_RED_ORB},
    {gBattleAnimSpritePalette_265, ANIM_TAG_GLOWY_GREEN_ORB},
    {gBattleAnimSpritePalette_266, ANIM_TAG_GREEN_SPIKE},
    {gBattleAnimSpritePalette_267, ANIM_TAG_WHITE_CIRCLE_OF_LIGHT},
    {gBattleAnimSpritePalette_268, ANIM_TAG_GLOWY_BLUE_ORB},
    {gBattleAnimSpritePalette_269, ANIM_TAG_UNUSED_RED_BRICK},
    {gBattleAnimSpritePalette_270, ANIM_TAG_WHITE_FEATHER},
    {gBattleAnimSpritePalette_271, ANIM_TAG_SPARKLE_6},
    {gBattleAnimSpritePalette_272, ANIM_TAG_SPLASH},
    {gBattleAnimSpritePalette_272, ANIM_TAG_SWEAT_BEAD},
    {gBattleAnimSpritePalette_274, ANIM_TAG_UNUSED_GEM_1},
    {gBattleAnimSpritePalette_274, ANIM_TAG_UNUSED_GEM_2},
    {gBattleAnimSpritePalette_274, ANIM_TAG_UNUSED_GEM_3},
    {gBattleAnimSpritePalette_277, ANIM_TAG_SLAM_HIT_2},
    {gBattleAnimSpritePalette_278, ANIM_TAG_RECYCLE},
    {gBattleAnimSpritePalette_279, ANIM_TAG_UNUSED_RED_PARTICLES},
    {gBattleAnimSpritePalette_280, ANIM_TAG_PROTECT},
    {gBattleAnimSpritePalette_281, ANIM_TAG_DIRT_MOUND},
    {gBattleAnimSpritePalette_282, ANIM_TAG_SHOCK_3},
    {gBattleAnimSpritePalette_283, ANIM_TAG_WEATHER_BALL},
    {gBattleAnimSpritePalette_284, ANIM_TAG_BIRD},
    {gBattleAnimSpritePalette_285, ANIM_TAG_CROSS_IMPACT},
    {gBattleAnimSpritePalette_286, ANIM_TAG_SLASH_2},
    {gBattleAnimSpritePalette_287, ANIM_TAG_WHIP_HIT},
    {gBattleAnimSpritePalette_288, ANIM_TAG_BLUE_RING_2},
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
        if (IsContest() && IsSpeciesNotUnown(gContestResources->field_18->species))
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

    if (IsSpeciesNotUnown(gContestResources->field_18->species))
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
        const u32 *tilemap = gBattleAnimBackgroundTable[bgId].tilemap;
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
