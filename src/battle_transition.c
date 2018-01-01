#include "global.h"
#include "battle_transition.h"
#include "unk_transition.h"
#include "main.h"
#include "overworld.h"
#include "task.h"
#include "palette.h"
#include "trig.h"
#include "field_effect.h"
#include "random.h"
#include "sprite.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "field_camera.h"
#include "unknown_task.h"
#include "malloc.h"

struct TransitionData
{
    vs8 VBlank_DMA;
    u16 WININ;
    u16 WINOUT;
    u16 field_6;
    u16 WIN0V;
    u16 field_A;
    u16 field_C;
    u16 BLDCNT;
    u16 BLDALPHA;
    u16 BLDY;
    s16 field_14;
    s16 field_16;
    s16 field_18;
    s16 field_1A;
    s16 field_1C;
    s16 field_1E; // unused
    s16 field_20;
    s16 field_22; // unused
    s16 data[11];
};

typedef bool8 (*TransitionState)(struct Task *task);
typedef bool8 (*TransitionSpriteCallback)(struct Sprite *sprite);

extern void c2_exit_to_overworld_2_switch(void);
extern void sub_80AC3D0(void);

// this file's functions
void LaunchBattleTransitionTask(u8 transitionId);
void Task_BattleTransitionMain(u8 taskId);
void Phase1Task_TransitionAll(u8 taskId);
void Phase2Task_Transition_Blur(u8 taskId);
void Phase2Task_Transition_Swirl(u8 taskId);
void Phase2Task_Transition_Shuffle(u8 taskId);
void Phase2Task_Transition_BigPokeball(u8 taskId);
void Phase2Task_Transition_PokeballsTrail(u8 taskId);
void Phase2Task_Transition_Clockwise_BlackFade(u8 taskId);
void Phase2Task_Transition_Ripple(u8 taskId);
void Phase2Task_Transition_Wave(u8 taskId);
void Phase2Task_Transition_Slice(u8 taskId);
void Phase2Task_Transition_WhiteFade(u8 taskId);
void Phase2Task_Transition_GridSquares(u8 taskId);
void Phase2Task_Transition_Shards(u8 taskId);
void Phase2Task_Transition_Sydney(u8 taskId);
void Phase2Task_Transition_Phoebe(u8 taskId);
void Phase2Task_Transition_Glacia(u8 taskId);
void Phase2Task_Transition_Drake(u8 taskId);
void Phase2Task_Transition_Wallace(u8 taskId);
void Phase2Task_Transition_Aqua(u8 taskId);
void Phase2Task_Transition_Magma(u8 taskId);
void Phase2Task_Transition_Regice(u8 taskId);
void Phase2Task_Transition_Registeel(u8 taskId);
void Phase2Task_Transition_Regirock(u8 taskId);
void Phase2Task_Transition_Kyogre(u8 taskId);
void Phase2Task_Transition_Groudon(u8 taskId);
void Phase2Task_Transition_Rayquaza(u8 taskId);
void Phase2Task_Transition_25(u8 taskId);
void Phase2Task_Transition_26(u8 taskId);
void Phase2Task_Transition_27(u8 taskId);
void Phase2Task_Transition_28(u8 taskId);
void Phase2Task_Transition_29(u8 taskId);
void Phase2Task_Transition_30(u8 taskId);
void Phase2Task_Transition_31(u8 taskId);
void Phase2Task_Transition_32(u8 taskId);
void Phase2Task_Transition_33(u8 taskId);
bool8 Transition_Phase1(struct Task *task);
bool8 Transition_WaitForPhase1(struct Task *task);
bool8 Transition_Phase2(struct Task *task);
bool8 Transition_WaitForPhase2(struct Task *task);

// iwram bss vars
IWRAM_DATA u16 gUnknown_03001208;
IWRAM_DATA static u8 sTestingTransitionId;
IWRAM_DATA static u8 sTestingTransitionState;

// ewram vars
EWRAM_DATA struct TransitionData *sTransitionStructPtr = NULL;

// const rom data
const u32 sBigPokeball_Tileset[] = INCBIN_U32("graphics/battle_transitions/big_pokeball.4bpp");
const u32 sPokeballTrail_Tileset[] = INCBIN_U32("graphics/battle_transitions/pokeball_trail.4bpp");
const u32 sSpriteImage_85B98F0[] = INCBIN_U32("graphics/battle_transitions/pokeball.4bpp");
const u32 sUnknown_085B9AF0[] = INCBIN_U32("graphics/battle_transitions/elite_four_bg.4bpp");
const u32 sSpriteImage_85B9CD0[] = INCBIN_U32("graphics/battle_transitions/unused_brendan.4bpp");
const u32 sSpriteImage_85BA4D0[] = INCBIN_U32("graphics/battle_transitions/unused_lass.4bpp");
const u32 sShrinkingBoxTileset[] = INCBIN_U32("graphics/battle_transitions/shrinking_box.4bpp");
const u32 sEvilTeam_Palette[] = INCBIN_U32("graphics/battle_transitions/evil_team.gbapal");
const u32 sTeamAqua_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_aqua.4bpp.lz");
const u32 sTeamAqua_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_aqua.bin.lz");
const u32 sTeamMagma_Tileset[] = INCBIN_U32("graphics/battle_transitions/team_magma.4bpp.lz");
const u32 sTeamMagma_Tilemap[] = INCBIN_U32("graphics/battle_transitions/team_magma.bin.lz");
const u32 gUnknown_085BBC14[] = INCBIN_U32("graphics/battle_transitions/85BBC14.4bpp");
const u32 gUnknown_085BC2B4[] = INCBIN_U32("graphics/battle_transitions/85BC2B4.gbapal");
const u32 gUnknown_085BC2D4[] = INCBIN_U32("graphics/battle_transitions/85BC2D4.gbapal");
const u32 gUnknown_085BC2F4[] = INCBIN_U32("graphics/battle_transitions/85BC2F4.gbapal");
const u32 gUnknown_085BC314[] = INCBIN_U32("graphics/battle_transitions/85BC314.bin");
const u32 gUnknown_085BCB14[] = INCBIN_U32("graphics/battle_transitions/85BCB14.bin");
const u32 gUnknown_085BD314[] = INCBIN_U32("graphics/battle_transitions/85BD314.bin");
const u32 gUnknown_085BDB14[] = INCBIN_U32("graphics/battle_transitions/85BDB14.gbapal");
const u32 gUnknown_085BDB34[] = INCBIN_U32("graphics/battle_transitions/kyogre.4bpp.lz");
const u32 gUnknown_085BE1E8[] = INCBIN_U32("graphics/battle_transitions/kyogre.bin.lz");
const u32 gUnknown_085BE51C[] = INCBIN_U32("graphics/battle_transitions/groudon.4bpp.lz");
const u32 gUnknown_085BEA88[] = INCBIN_U32("graphics/battle_transitions/groudon.bin.lz");
const u32 gUnknown_085BEDA0[] = INCBIN_U32("graphics/battle_transitions/kyogre_pt1.gbapal");
const u32 gUnknown_085BEEE0[] = INCBIN_U32("graphics/battle_transitions/kyogre_pt2.gbapal");
const u32 gUnknown_085BF0A0[] = INCBIN_U32("graphics/battle_transitions/groudon_pt1.gbapal");
const u32 gUnknown_085BF2A0[] = INCBIN_U32("graphics/battle_transitions/groudon_pt2.gbapal");
const u32 gUnknown_085BF4A0[] = INCBIN_U32("graphics/battle_transitions/rayquaza.gbapal");
const u32 gUnknown_085BF6A0[] = INCBIN_U32("graphics/battle_transitions/rayquaza.4bpp");
const u32 gUnknown_085C6BE0[] = INCBIN_U32("graphics/battle_transitions/rayquaza.bin");
const u32 gUnknown_085C7BE0[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.gbapal");
const u32 gUnknown_085C7C00[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.4bpp.lz");
const u32 gUnknown_085C828C[] = INCBIN_U32("graphics/battle_transitions/frontier_brain.bin.lz");
const u32 gUnknown_085C8578[] = INCBIN_U32("graphics/battle_transitions/frontier_squares_blanktiles.gbapal");
const u32 gUnknown_085C8598[] = INCBIN_U32("graphics/battle_transitions/frontier_square_1.4bpp.lz");
const u32 gUnknown_085C86F4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_2.4bpp.lz");
const u32 gUnknown_085C87F4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_3.4bpp.lz");
const u32 gUnknown_085C88A4[] = INCBIN_U32("graphics/battle_transitions/frontier_square_4.4bpp.lz");
const u32 gUnknown_085C8928[] = INCBIN_U32("graphics/battle_transitions/frontier_squares.bin");

const TaskFunc sPhase1_Tasks[B_TRANSITION_COUNT] =
{
    [0 ... B_TRANSITION_COUNT - 1] = &Phase1Task_TransitionAll
};

const TaskFunc sPhase2_Tasks[B_TRANSITION_COUNT] =
{
    Phase2Task_Transition_Blur,                        // 0
    Phase2Task_Transition_Swirl,                       // 1
    Phase2Task_Transition_Shuffle,                     // 2
    Phase2Task_Transition_BigPokeball,                 // 3
    Phase2Task_Transition_PokeballsTrail,              // 4
    Phase2Task_Transition_Clockwise_BlackFade,         // 5
    Phase2Task_Transition_Ripple,                      // 6
    Phase2Task_Transition_Wave,                        // 7
    Phase2Task_Transition_Slice,                       // 8
    Phase2Task_Transition_WhiteFade,                   // 9
    Phase2Task_Transition_GridSquares,                 // 10
    Phase2Task_Transition_Shards,                      // 11
    Phase2Task_Transition_Sydney,                      // 12
    Phase2Task_Transition_Phoebe,                      // 13
    Phase2Task_Transition_Glacia,                      // 14
    Phase2Task_Transition_Drake,                       // 15
    Phase2Task_Transition_Wallace,                     // 16
    Phase2Task_Transition_Aqua,                        // 17
    Phase2Task_Transition_Magma,                       // 18
    Phase2Task_Transition_Regice,                      // 19
    Phase2Task_Transition_Registeel,                   // 20
    Phase2Task_Transition_Regirock,                    // 21
    Phase2Task_Transition_Kyogre,                      // 22
    Phase2Task_Transition_Groudon,                     // 23
    Phase2Task_Transition_Rayquaza,                    // 24
    Phase2Task_Transition_25,                          // 25
    Phase2Task_Transition_26,                          // 26
    Phase2Task_Transition_27,                          // 27
    Phase2Task_Transition_28,                          // 28
    Phase2Task_Transition_29,                          // 29
    Phase2Task_Transition_30,                          // 30
    Phase2Task_Transition_31,                          // 31
    Phase2Task_Transition_32,                          // 32
    Phase2Task_Transition_33,                          // 33
    Phase2Task_Transition_34,                          // 34
    Phase2Task_Transition_35,                          // 35
    Phase2Task_Transition_36,                          // 36
    Phase2Task_Transition_37,                          // 37
    Phase2Task_Transition_38,                          // 38
    Phase2Task_Transition_39,                          // 39
    Phase2Task_Transition_40,                          // 40
    Phase2Task_Transition_41,                          // 41
};

const TransitionState sMainTransitionPhases[] =
{
    &Transition_Phase1,
    &Transition_WaitForPhase1,
    &Transition_Phase2,
    &Transition_WaitForPhase2
};

// code
static void CB2_TestBattleTransition(void)
{
    switch (sTestingTransitionState)
    {
    case 0:
        LaunchBattleTransitionTask(sTestingTransitionId);
        sTestingTransitionState++;
        break;
    case 1:
        if (IsBattleTransitionDone())
        {
            sTestingTransitionState = 0;
            SetMainCallback2(c2_exit_to_overworld_2_switch);
        }
        break;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void TestBattleTransition(u8 transitionId)
{
    sTestingTransitionId = transitionId;
    SetMainCallback2(CB2_TestBattleTransition);
}

void BattleTransition_StartOnField(u8 transitionId)
{
    gMain.callback2 = CB2_OverworldBasic;
    LaunchBattleTransitionTask(transitionId);
}

void BattleTransition_Start(u8 transitionId)
{
    LaunchBattleTransitionTask(transitionId);
}

#define tState          data[0]
#define tTransitionID   data[1]
#define tTransitionDone data[15]

bool8 IsBattleTransitionDone(void)
{
    u8 taskId = FindTaskIdByFunc(Task_BattleTransitionMain);
    if (gTasks[taskId].tTransitionDone)
    {
        DestroyTask(taskId);
        FREE_AND_SET_NULL(sTransitionStructPtr);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void LaunchBattleTransitionTask(u8 transitionId)
{
    u8 taskId = CreateTask(Task_BattleTransitionMain, 2);
    gTasks[taskId].tTransitionID = transitionId;
    sTransitionStructPtr = AllocZeroed(sizeof(*sTransitionStructPtr));
}

void Task_BattleTransitionMain(u8 taskId)
{
    while (sMainTransitionPhases[gTasks[taskId].tState](&gTasks[taskId]));
}

bool8 Transition_Phase1(struct Task *task)
{
    sub_80AC3D0();
    CpuCopy32(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    if (sPhase1_Tasks[task->tTransitionID] != NULL)
    {
        CreateTask(sPhase1_Tasks[task->tTransitionID], 4);
        task->tState++;
        return FALSE;
    }
    else
    {
        task->tState = 2;
        return TRUE;
    }
}
