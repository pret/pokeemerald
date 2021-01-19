#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_message.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "evolution_scene.h"
#include "evolution_graphics.h"
#include "gpu_regs.h"
#include "link.h"
#include "link_rfu.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "trade.h"
#include "util.h"
#include "constants/battle_string_ids.h"
#include "constants/songs.h"
#include "constants/rgb.h"

struct EvoInfo
{
    u8 preEvoSpriteID;
    u8 postEvoSpriteID;
    u8 evoTaskID;
    u8 field_3;
    u16 savedPalette[48];
};

// EWRAM vars
static EWRAM_DATA struct EvoInfo *sEvoStructPtr = NULL;
static EWRAM_DATA u16 *sEvoMovingBgPtr = NULL;

// IWRAM common
void (*gCB2_AfterEvolution)(void);

#define sEvoCursorPos           gBattleCommunication[1] // when learning a new move
#define sEvoGraphicsTaskID      gBattleCommunication[2]

// this file's functions
static void Task_EvolutionScene(u8 taskID);
static void Task_TradeEvolutionScene(u8 taskID);
static void CB2_EvolutionSceneUpdate(void);
static void CB2_TradeEvolutionSceneUpdate(void);
static void EvoDummyFunc(void);
static void VBlankCB_EvolutionScene(void);
static void VBlankCB_TradeEvolutionScene(void);
static void sub_8140134(void);
static void EvoScene_DoMonAnimation(u8 monSpriteId, u16 speciesId);
static bool32 EvoScene_IsMonAnimFinished(u8 monSpriteId);
static void InitMovingBackgroundTask(bool8 isLink);
static void sub_813FEE8(u8 taskId);
static void sub_8140174(void);

// const data
static const u16 sUnknown_085B4114[] = INCBIN_U16("graphics/evolution_scene/unknown_5B4114.gbapal");
static const u32 sUnknown_085B4134[] = INCBIN_U32("graphics/evolution_scene/bg.4bpp.lz");
static const u32 sUnknown_085B482C[] = INCBIN_U32("graphics/evolution_scene/bg.bin.lz");
static const u32 sUnknown_085B4D10[] = INCBIN_U32("graphics/evolution_scene/bg2.bin.lz");
static const u16 sUnknown_085B51E4[] = INCBIN_U16("graphics/evolution_scene/gray_transition_intro.gbapal");
static const u16 sUnknown_085B53E4[] = INCBIN_U16("graphics/evolution_scene/gray_transition_lighten.gbapal");
static const u16 sUnknown_085B5544[] = INCBIN_U16("graphics/evolution_scene/gray_transition_darken.gbapal");
static const u16 sUnknown_085B56E4[] = INCBIN_U16("graphics/evolution_scene/gray_transition_outro.gbapal");
static const u16 sUnknown_085B5884[] = INCBIN_U16("graphics/evolution_scene/transition.gbapal");

static const u8 Text_ShedinjaJapaneseName[] = _("ヌケニン");

static const u8 sUnknown_085B58C9[][4] =
{
    { 0x00, 0x0C, 0x01, 0x06 },
    { 0x0D, 0x24, 0x05, 0x02 },
    { 0x0D, 0x18, 0x01, 0x02 },
    { 0x25, 0x31, 0x01, 0x06 },
};

static const u8 sUnknown_085B58D9[][16] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x0B, 0x00, 0x00 },
    { 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x00, 0x00 },
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00 },
    { 0x00, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x00, 0x00 },
    { 0x00, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x00, 0x00 },
    { 0x00, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x00, 0x00 },
    { 0x00, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x00, 0x00 },
    { 0x00, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x00, 0x00 },
    { 0x00, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x00, 0x00 },
    { 0x00, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x00, 0x00 },
    { 0x00, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x00, 0x00 },
    { 0x00, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x00, 0x00 },
    { 0x00, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x00, 0x00 },
    { 0x00, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x00, 0x00 },
    { 0x00, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00 },
    { 0x00, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x00, 0x00 },
    { 0x00, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x00, 0x00 },
    { 0x00, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00 },
    { 0x00, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00 },
    { 0x00, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00 },
    { 0x00, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x00 },
    { 0x00, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x00, 0x00 },
    { 0x00, 0x05, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x00 },
    { 0x00, 0x04, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x00, 0x00 },
    { 0x00, 0x03, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x00, 0x00 },
    { 0x00, 0x02, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x00, 0x00 },
    { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00 },
    { 0x00, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00 },
    { 0x00, 0x0B, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x0A, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};

static void CB2_BeginEvolutionScene(void)
{
    UpdatePaletteFade();
    RunTasks();
}

#define tState              data[0]
#define tPreEvoSpecies      data[1]
#define tPostEvoSpecies     data[2]
#define tCanStop            data[3]
#define tBits               data[3]
#define tLearnsFirstMove    data[4]
#define tLearnMoveState     data[6]
#define tData7              data[7]
#define tData8              data[8]
#define tEvoWasStopped      data[9]
#define tPartyID            data[10]

#define TASK_BIT_CAN_STOP       0x1
#define TASK_BIT_LEARN_MOVE     0x80

static void Task_BeginEvolutionScene(u8 taskID)
{
    struct Pokemon* mon = NULL;
    switch (gTasks[taskID].tState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskID].tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            u16 speciesToEvolve;
            bool8 canStopEvo;
            u8 partyID;

            mon = &gPlayerParty[gTasks[taskID].tPartyID];
            speciesToEvolve = gTasks[taskID].tPostEvoSpecies;
            canStopEvo = gTasks[taskID].tCanStop;
            partyID = gTasks[taskID].tPartyID;

            DestroyTask(taskID);
            EvolutionScene(mon, speciesToEvolve, canStopEvo, partyID);
        }
        break;
    }
}

void BeginEvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, bool8 canStopEvo, u8 partyID)
{
    u8 taskID = CreateTask(Task_BeginEvolutionScene, 0);
    gTasks[taskID].tState = 0;
    gTasks[taskID].tPostEvoSpecies = speciesToEvolve;
    gTasks[taskID].tCanStop = canStopEvo;
    gTasks[taskID].tPartyID = partyID;
    SetMainCallback2(CB2_BeginEvolutionScene);
}

void EvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, bool8 canStopEvo, u8 partyID)
{
    u8 name[20];
    u16 currSpecies;
    u32 trainerId, personality;
    const struct CompressedSpritePalette* pokePal;
    u8 ID;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    CpuFill32(0, (void*)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    ResetPaletteFade();

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 256;
    gBattle_BG3_Y = 0;

    gBattleTerrain = BATTLE_TERRAIN_PLAIN;

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ScanlineEffect_Stop();
    ResetTasks();
    FreeAllSpritePalettes();

    gReservedSpritePaletteCount = 4;

    sEvoStructPtr = AllocZeroed(sizeof(struct EvoInfo));
    AllocateMonSpritesGfx();

    GetMonData(mon, MON_DATA_NICKNAME, name);
    StringCopy10(gStringVar1, name);
    StringCopy(gStringVar2, gSpeciesNames[speciesToEvolve]);

    // preEvo sprite
    currSpecies = GetMonData(mon, MON_DATA_SPECIES);
    trainerId = GetMonData(mon, MON_DATA_OT_ID);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);
    DecompressPicFromTable_2(&gMonFrontPicTable[currSpecies],
                             gMonSpritesGfxPtr->sprites.ptr[1],
                             currSpecies);
    pokePal = GetMonSpritePalStructFromOtIdPersonality(currSpecies, trainerId, personality);
    LoadCompressedPalette(pokePal->data, 0x110, 0x20);

    SetMultiuseSpriteTemplateToPokemon(currSpecies, 1);
    gMultiuseSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sEvoStructPtr->preEvoSpriteID = ID = CreateSprite(&gMultiuseSpriteTemplate, 120, 64, 30);

    gSprites[ID].callback = SpriteCallbackDummy_2;
    gSprites[ID].oam.paletteNum = 1;
    gSprites[ID].invisible = TRUE;

    // postEvo sprite
    DecompressPicFromTable_2(&gMonFrontPicTable[speciesToEvolve],
                             gMonSpritesGfxPtr->sprites.ptr[3],
                             speciesToEvolve);
    pokePal = GetMonSpritePalStructFromOtIdPersonality(speciesToEvolve, trainerId, personality);
    LoadCompressedPalette(pokePal->data, 0x120, 0x20);

    SetMultiuseSpriteTemplateToPokemon(speciesToEvolve, 3);
    gMultiuseSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sEvoStructPtr->postEvoSpriteID = ID = CreateSprite(&gMultiuseSpriteTemplate, 120, 64, 30);
    gSprites[ID].callback = SpriteCallbackDummy_2;
    gSprites[ID].oam.paletteNum = 2;
    gSprites[ID].invisible = TRUE;

    LoadEvoSparkleSpriteAndPal();

    sEvoStructPtr->evoTaskID = ID = CreateTask(Task_EvolutionScene, 0);
    gTasks[ID].tState = 0;
    gTasks[ID].tPreEvoSpecies = currSpecies;
    gTasks[ID].tPostEvoSpecies = speciesToEvolve;
    gTasks[ID].tCanStop = canStopEvo;
    gTasks[ID].tLearnsFirstMove = TRUE;
    gTasks[ID].tEvoWasStopped = FALSE;
    gTasks[ID].tPartyID = partyID;

    memcpy(&sEvoStructPtr->savedPalette, &gPlttBufferUnfaded[0x20], 0x60);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);

    SetHBlankCallback(EvoDummyFunc);
    SetVBlankCallback(VBlankCB_EvolutionScene);
    m4aMPlayAllStop();
    SetMainCallback2(CB2_EvolutionSceneUpdate);
}

static void CB2_EvolutionSceneLoadGraphics(void)
{
    u8 ID;
    const struct CompressedSpritePalette* pokePal;
    u16 postEvoSpecies;
    u32 trainerId, personality;
    struct Pokemon* Mon = &gPlayerParty[gTasks[sEvoStructPtr->evoTaskID].tPartyID];

    postEvoSpecies = gTasks[sEvoStructPtr->evoTaskID].tPostEvoSpecies;
    trainerId = GetMonData(Mon, MON_DATA_OT_ID);
    personality = GetMonData(Mon, MON_DATA_PERSONALITY);

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    CpuFill32(0, (void*)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    ResetPaletteFade();

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 256;
    gBattle_BG3_Y = 0;

    gBattleTerrain = BATTLE_TERRAIN_PLAIN;

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;

    DecompressPicFromTable_2(&gMonFrontPicTable[postEvoSpecies],
                             gMonSpritesGfxPtr->sprites.ptr[3],
                             postEvoSpecies);
    pokePal = GetMonSpritePalStructFromOtIdPersonality(postEvoSpecies, trainerId, personality);

    LoadCompressedPalette(pokePal->data, 0x120, 0x20);

    SetMultiuseSpriteTemplateToPokemon(postEvoSpecies, 3);
    gMultiuseSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sEvoStructPtr->postEvoSpriteID = ID = CreateSprite(&gMultiuseSpriteTemplate, 120, 64, 30);

    gSprites[ID].callback = SpriteCallbackDummy_2;
    gSprites[ID].oam.paletteNum = 2;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);

    SetHBlankCallback(EvoDummyFunc);
    SetVBlankCallback(VBlankCB_EvolutionScene);
    SetMainCallback2(CB2_EvolutionSceneUpdate);

    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void CB2_TradeEvolutionSceneLoadGraphics(void)
{
    struct Pokemon* Mon = &gPlayerParty[gTasks[sEvoStructPtr->evoTaskID].tPartyID];
    u16 postEvoSpecies = gTasks[sEvoStructPtr->evoTaskID].tPostEvoSpecies;

    switch (gMain.state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetHBlankCallback(NULL);
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 4;
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 256;
        gBattle_BG3_Y = 0;
        gMain.state++;
        break;
    case 1:
        ResetPaletteFade();
        SetHBlankCallback(EvoDummyFunc);
        SetVBlankCallback(VBlankCB_TradeEvolutionScene);
        gMain.state++;
        break;
    case 2:
        InitTradeBg();
        gMain.state++;
        break;
    case 3:
        FillBgTilemapBufferRect(1, 0, 0, 0, 0x20, 0x20, 0x11);
        CopyBgTilemapBufferToVram(1);
        gMain.state++;
        break;
    case 4:
        {
            const struct CompressedSpritePalette* pokePal;
            u32 trainerId = GetMonData(Mon, MON_DATA_OT_ID);
            u32 personality = GetMonData(Mon, MON_DATA_PERSONALITY);
            DecompressPicFromTable_2(&gMonFrontPicTable[postEvoSpecies],
                                     gMonSpritesGfxPtr->sprites.ptr[3],
                                     postEvoSpecies);
            pokePal = GetMonSpritePalStructFromOtIdPersonality(postEvoSpecies, trainerId, personality);
            LoadCompressedPalette(pokePal->data, 0x120, 0x20);
            gMain.state++;
        }
        break;
    case 5:
        {
            u8 ID;

            SetMultiuseSpriteTemplateToPokemon(postEvoSpecies, 1);
            gMultiuseSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
            sEvoStructPtr->postEvoSpriteID = ID = CreateSprite(&gMultiuseSpriteTemplate, 120, 64, 30);

            gSprites[ID].callback = SpriteCallbackDummy_2;
            gSprites[ID].oam.paletteNum = 2;
            gMain.state++;
            LinkTradeDrawWindow();
        }
        break;
    case 6:
        if (gWirelessCommType)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        BlendPalettes(-1,0x10, 0);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        InitTradeSequenceBgGpuRegs();
        ShowBg(0);
        ShowBg(1);
        SetMainCallback2(CB2_TradeEvolutionSceneUpdate);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_OBJ_1D_MAP);
        break;
    }
}

void TradeEvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, u8 preEvoSpriteID, u8 partyID)
{
    u8 name[20];
    u16 currSpecies;
    u32 trainerId, personality;
    const struct CompressedSpritePalette* pokePal;
    u8 ID;

    GetMonData(mon, MON_DATA_NICKNAME, name);
    StringCopy10(gStringVar1, name);
    StringCopy(gStringVar2, gSpeciesNames[speciesToEvolve]);

    gAffineAnimsDisabled = TRUE;

    // preEvo sprite
    currSpecies = GetMonData(mon, MON_DATA_SPECIES);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);
    trainerId = GetMonData(mon, MON_DATA_OT_ID);

    sEvoStructPtr = AllocZeroed(sizeof(struct EvoInfo));
    sEvoStructPtr->preEvoSpriteID = preEvoSpriteID;

    DecompressPicFromTable_2(&gMonFrontPicTable[speciesToEvolve],
                            gMonSpritesGfxPtr->sprites.ptr[1],
                            speciesToEvolve);

    pokePal = GetMonSpritePalStructFromOtIdPersonality(speciesToEvolve, trainerId, personality);
    LoadCompressedPalette(pokePal->data, 0x120, 0x20);

    SetMultiuseSpriteTemplateToPokemon(speciesToEvolve, 1);
    gMultiuseSpriteTemplate.affineAnims = gDummySpriteAffineAnimTable;
    sEvoStructPtr->postEvoSpriteID = ID = CreateSprite(&gMultiuseSpriteTemplate, 120, 64, 30);

    gSprites[ID].callback = SpriteCallbackDummy_2;
    gSprites[ID].oam.paletteNum = 2;
    gSprites[ID].invisible = TRUE;

    LoadEvoSparkleSpriteAndPal();

    sEvoStructPtr->evoTaskID = ID = CreateTask(Task_TradeEvolutionScene, 0);
    gTasks[ID].tState = 0;
    gTasks[ID].tPreEvoSpecies = currSpecies;
    gTasks[ID].tPostEvoSpecies = speciesToEvolve;
    gTasks[ID].tLearnsFirstMove = TRUE;
    gTasks[ID].tEvoWasStopped = FALSE;
    gTasks[ID].tPartyID = partyID;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 256;
    gBattle_BG3_Y = 0;

    gTextFlags.useAlternateDownArrow = 1;

    SetVBlankCallback(VBlankCB_TradeEvolutionScene);
    SetMainCallback2(CB2_TradeEvolutionSceneUpdate);
}

static void CB2_EvolutionSceneUpdate(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void CB2_TradeEvolutionSceneUpdate(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void CreateShedinja(u16 preEvoSpecies, struct Pokemon* mon)
{
    u32 data = 0;
    if (gEvolutionTable[preEvoSpecies][0].method == EVO_LEVEL_NINJASK && gPlayerPartyCount < 6)
    {
        s32 i;
        struct Pokemon* shedinja = &gPlayerParty[gPlayerPartyCount];
        const struct Evolution *evos;
        const struct Evolution *evos2;

        CopyMon(&gPlayerParty[gPlayerPartyCount], mon, sizeof(struct Pokemon));
        SetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_SPECIES, (&gEvolutionTable[preEvoSpecies][1].targetSpecies));
        SetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_NICKNAME, (gSpeciesNames[gEvolutionTable[preEvoSpecies][1].targetSpecies]));
        SetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_HELD_ITEM, (&data));
        SetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_MARKINGS, (&data));
        SetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_ENCRYPT_SEPARATOR, (&data));

        for (i = MON_DATA_COOL_RIBBON; i < MON_DATA_COOL_RIBBON + 5; i++)
            SetMonData(&gPlayerParty[gPlayerPartyCount], i, (&data));
        for (i = MON_DATA_CHAMPION_RIBBON; i <= MON_DATA_FATEFUL_ENCOUNTER; i++)
            SetMonData(&gPlayerParty[gPlayerPartyCount], i, (&data));

        SetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_STATUS, (&data));
        data = 0xFF;
        SetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_MAIL, (&data));

        CalculateMonStats(&gPlayerParty[gPlayerPartyCount]);
        CalculatePlayerPartyCount();

        // can't match it otherwise, ehh
        evos2 = gEvolutionTable[0];
        evos = evos2 + EVOS_PER_MON * preEvoSpecies;

        GetSetPokedexFlag(SpeciesToNationalPokedexNum(evos[1].targetSpecies), FLAG_SET_SEEN);
        GetSetPokedexFlag(SpeciesToNationalPokedexNum(evos[1].targetSpecies), FLAG_SET_CAUGHT);

        if (GetMonData(shedinja, MON_DATA_SPECIES) == SPECIES_SHEDINJA
            && GetMonData(shedinja, MON_DATA_LANGUAGE) == LANGUAGE_JAPANESE
            && GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NINJASK)
                SetMonData(shedinja, MON_DATA_NICKNAME, Text_ShedinjaJapaneseName);
    }
}

static void Task_EvolutionScene(u8 taskID)
{
    u32 var;
    struct Pokemon* mon = &gPlayerParty[gTasks[taskID].tPartyID];

    // check if B Button was held, so the evolution gets stopped
    if (gMain.heldKeys == B_BUTTON
        && gTasks[taskID].tState == 8
        && gTasks[sEvoGraphicsTaskID].isActive
        && gTasks[taskID].tBits & TASK_BIT_CAN_STOP)
    {
        gTasks[taskID].tState = 17;
        gTasks[sEvoGraphicsTaskID].EvoGraphicsTaskEvoStop = TRUE;
        sub_8140134();
        return;
    }

    switch (gTasks[taskID].tState)
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, RGB_BLACK);
        gSprites[sEvoStructPtr->preEvoSpriteID].invisible = FALSE;
        gTasks[taskID].tState++;
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        break;
    case 1: // print 'whoa, poke is evolving!!!' msg
        if (!gPaletteFade.active)
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnIsEvolving);
            BattlePutTextOnWindow(gStringVar4, 0);
            gTasks[taskID].tState++;
        }
        break;
    case 2: // wait for string, animate mon(and play its cry)
        if (!IsTextPrinterActive(0))
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->preEvoSpriteID, gTasks[taskID].tPreEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 3:
        if (EvoScene_IsMonAnimFinished(sEvoStructPtr->preEvoSpriteID)) // wait for animation, play tu du SE
        {
            PlaySE(MUS_EVOLUTION_INTRO);
            gTasks[taskID].tState++;
        }
        break;
    case 4: // play evolution music and fade screen black
        if (!IsSEPlaying())
        {
            PlayNewMapMusic(MUS_EVOLUTION);
            gTasks[taskID].tState++;
            BeginNormalPaletteFade(0x1C, 4, 0, 0x10, RGB_BLACK);
        }
        break;
    case 5: // launch moving bg task, preapre evo sparkles
        if (!gPaletteFade.active)
        {
            InitMovingBackgroundTask(FALSE);
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet1(17);
            gTasks[taskID].tState++;
        }
        break;
    case 6: // another set of evo sparkles
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            gTasks[taskID].tState++;
            sEvoStructPtr->field_3 = 1;
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet2();
        }
        break;
    case 7: // launch task that flashes pre evo with post evo sprites
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = sub_817C3A0(sEvoStructPtr->preEvoSpriteID, sEvoStructPtr->postEvoSpriteID);
            gTasks[taskID].tState++;
        }
        break;
    case 8: // wait for the above task to finish
        if (--sEvoStructPtr->field_3 == 0)
        {
            sEvoStructPtr->field_3 = 3;
            if (!gTasks[sEvoGraphicsTaskID].isActive)
                gTasks[taskID].tState++;
        }
        break;
    case 9: // post evo sparkles
        sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet1();
        gTasks[taskID].tState++;
        break;
    case 10:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet2AndFlash(gTasks[taskID].tPostEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 11: // play tu du sound after evolution
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            PlaySE(SE_EXP);
            gTasks[taskID].tState++;
        }
        break;
    case 12: // stop music, return screen to pre-fade state
        if (IsSEPlaying())
        {
            m4aMPlayAllStop();
            memcpy(&gPlttBufferUnfaded[0x20], sEvoStructPtr->savedPalette, 0x60);
            sub_8140174();
            BeginNormalPaletteFade(0x1C, 0, 0x10, 0, RGB_BLACK);
            gTasks[taskID].tState++;
        }
        break;
    case 13: // animate mon
        if (!gPaletteFade.active)
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->postEvoSpriteID, gTasks[taskID].tPostEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 14: // congratulations string and rename prompt
        if (IsCryFinished())
        {
            StringExpandPlaceholders(gStringVar4, gText_CongratsPkmnEvolved);
            BattlePutTextOnWindow(gStringVar4, 0);
            PlayBGM(MUS_EVOLVED);
            gTasks[taskID].tState++;
            SetMonData(mon, MON_DATA_SPECIES, (void*)(&gTasks[taskID].tPostEvoSpecies));
            CalculateMonStats(mon);
            EvolutionRenameMon(mon, gTasks[taskID].tPreEvoSpecies, gTasks[taskID].tPostEvoSpecies);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_SEEN);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_CAUGHT);
            IncrementGameStat(GAME_STAT_EVOLVED_POKEMON);
        }
        break;
    case 15: // check if it wants to learn a new move
        if (!IsTextPrinterActive(0))
        {
            var = MonTryLearningNewMove(mon, gTasks[taskID].tLearnsFirstMove);
            if (var != 0 && !gTasks[taskID].tEvoWasStopped)
            {
                u8 text[20];

                if (!(gTasks[taskID].tBits & TASK_BIT_LEARN_MOVE))
                {
                    StopMapMusic();
                    Overworld_PlaySpecialMapMusic();
                }

                gTasks[taskID].tBits |= TASK_BIT_LEARN_MOVE;
                gTasks[taskID].tLearnsFirstMove = FALSE;
                gTasks[taskID].tLearnMoveState = 0;
                GetMonData(mon, MON_DATA_NICKNAME, text);
                StringCopy10(gBattleTextBuff1, text);

                if (var == MON_HAS_MAX_MOVES)
                    gTasks[taskID].tState = 22;
                else if (var == MON_ALREADY_KNOWS_MOVE)
                    break;
                else
                    gTasks[taskID].tState = 20; // move has been learned
            }
            else // no move to learn
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                gTasks[taskID].tState++;
            }
        }
        break;
    case 16: // task has finished, return
        if (!gPaletteFade.active)
        {
            if (!(gTasks[taskID].tBits & TASK_BIT_LEARN_MOVE))
            {
                StopMapMusic();
                Overworld_PlaySpecialMapMusic();
            }
            if (!gTasks[taskID].tEvoWasStopped)
                CreateShedinja(gTasks[taskID].tPreEvoSpecies, mon);

            DestroyTask(taskID);
            FreeMonSpritesGfx();
            Free(sEvoStructPtr);
            sEvoStructPtr = NULL;
            FreeAllWindowBuffers();
            SetMainCallback2(gCB2_AfterEvolution);
        }
        break;
    case 17: // evolution has been canceled, stop music and re-fade palette
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            m4aMPlayAllStop();
            BeginNormalPaletteFade(0x6001C, 0, 0x10, 0, RGB_WHITE);
            gTasks[taskID].tState++;
        }
        break;
    case 18: // animate pokemon trying to evolve again, evolution has been stopped
        if (!gPaletteFade.active)
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->preEvoSpriteID, gTasks[taskID].tPreEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 19: // after the animation, print the string 'WHOA IT DID NOT EVOLVE!!!'
        if (EvoScene_IsMonAnimFinished(sEvoStructPtr->preEvoSpriteID))
        {
            if (gTasks[taskID].tEvoWasStopped)
                StringExpandPlaceholders(gStringVar4, gText_EllipsisQuestionMark);
            else // Fire Red leftover probably
                StringExpandPlaceholders(gStringVar4, gText_PkmnStoppedEvolving);

            BattlePutTextOnWindow(gStringVar4, 0);
            gTasks[taskID].tEvoWasStopped = TRUE;
            gTasks[taskID].tState = 15;
        }
        break;
    case 20: // pokemon learned a new move, print string and play a fanfare
        if (!IsTextPrinterActive(0) && !IsSEPlaying())
        {
            BufferMoveToLearnIntoBattleTextBuff2();
            PlayFanfare(MUS_LEVEL_UP);
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tLearnsFirstMove = 0x40; // re-used as a counter
            gTasks[taskID].tState++;
        }
        break;
    case 21: // wait a bit and check if can learn another move
        if (!IsTextPrinterActive(0) && !IsSEPlaying() && --gTasks[taskID].tLearnsFirstMove == 0)
            gTasks[taskID].tState = 15;
        break;
    case 22: // try to learn a new move
        switch (gTasks[taskID].tLearnMoveState)
        {
        case 0:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BufferMoveToLearnIntoBattleTextBuff2();
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 1:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 2:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tData7 = 5;
                gTasks[taskID].tData8 = 10;
                gTasks[taskID].tLearnMoveState++;
            }
        case 3:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
                BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
                gTasks[taskID].tLearnMoveState++;
                sEvoCursorPos = 0;
                BattleCreateYesNoCursorAt(0);
            }
            break;
        case 4:
            if (JOY_NEW(DPAD_UP) && sEvoCursorPos != 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(sEvoCursorPos);
                sEvoCursorPos = 0;
                BattleCreateYesNoCursorAt(0);
            }
            if (JOY_NEW(DPAD_DOWN) && sEvoCursorPos == 0)
            {
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(sEvoCursorPos);
                sEvoCursorPos = 1;
                BattleCreateYesNoCursorAt(1);
            }
            if (JOY_NEW(A_BUTTON))
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
                PlaySE(SE_SELECT);

                if (sEvoCursorPos != 0)
                {
                    gTasks[taskID].tLearnMoveState = gTasks[taskID].tData8;
                }
                else
                {
                    gTasks[taskID].tLearnMoveState = gTasks[taskID].tData7;
                    if (gTasks[taskID].tLearnMoveState == 5)
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                }
            }
            if (JOY_NEW(B_BUTTON))
            {
                HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
                PlaySE(SE_SELECT);
                gTasks[taskID].tLearnMoveState = gTasks[taskID].tData8;
            }
            break;
        case 5:
            if (!gPaletteFade.active)
            {
                FreeAllWindowBuffers();
                ShowSelectMovePokemonSummaryScreen(gPlayerParty, gTasks[taskID].tPartyID,
                            gPlayerPartyCount - 1, CB2_EvolutionSceneLoadGraphics,
                            gMoveToLearn);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 6:
            if (!gPaletteFade.active && gMain.callback2 == CB2_EvolutionSceneUpdate)
            {
                var = GetMoveSlotToReplace();
                if (var == MAX_MON_MOVES)
                {
                    gTasks[taskID].tLearnMoveState = 10;
                }
                else
                {
                    u16 move = GetMonData(mon, var + MON_DATA_MOVE1);
                    if (IsHMMove2(move))
                    {
                        BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_ID_ADDER]);
                        BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                        gTasks[taskID].tLearnMoveState = 12;
                    }
                    else
                    {
                        PREPARE_MOVE_BUFFER(gBattleTextBuff2, move)

                        RemoveMonPPBonus(mon, var);
                        SetMonMoveSlot(mon, gMoveToLearn, var);
                        gTasks[taskID].tLearnMoveState++;
                    }
                }
            }
            break;
        case 7:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_123POOF - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tLearnMoveState++;
            break;
        case 8:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 9:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_ANDELLIPSIS - BATTLESTRINGS_ID_ADDER]);
                BattlePutTextOnWindow(gDisplayedStringBattle, 0);
                gTasks[taskID].tState = 20;
            }
            break;
        case 10:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tData7 = 11;
            gTasks[taskID].tData8 = 0;
            gTasks[taskID].tLearnMoveState = 3;
            break;
        case 11:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_ID_ADDER]);
            BattlePutTextOnWindow(gDisplayedStringBattle, 0);
            gTasks[taskID].tState = 15;
            break;
        case 12:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
                gTasks[taskID].tLearnMoveState = 5;
            break;
        }
        break;
    }
}

static void Task_TradeEvolutionScene(u8 taskID)
{
    u32 var = 0;
    struct Pokemon* mon = &gPlayerParty[gTasks[taskID].tPartyID];

    switch (gTasks[taskID].tState)
    {
    case 0:
        StringExpandPlaceholders(gStringVar4, gText_PkmnIsEvolving);
        DrawTextOnTradeWindow(0, gStringVar4, 1);
        gTasks[taskID].tState++;
        break;
    case 1:
        if (!IsTextPrinterActive(0))
        {
            PlayCry1(gTasks[taskID].tPreEvoSpecies, 0);
            gTasks[taskID].tState++;
        }
        break;
    case 2:
        if (IsCryFinished())
        {
            m4aSongNumStop(MUS_EVOLUTION);
            PlaySE(MUS_EVOLUTION_INTRO);
            gTasks[taskID].tState++;
        }
        break;
    case 3:
        if (!IsSEPlaying())
        {
            PlayBGM(MUS_EVOLUTION);
            gTasks[taskID].tState++;
            BeginNormalPaletteFade(0x1C, 4, 0, 0x10, RGB_BLACK);
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            InitMovingBackgroundTask(TRUE);
            var = gSprites[sEvoStructPtr->preEvoSpriteID].oam.paletteNum + 16;
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet1(var);
            gTasks[taskID].tState++;
            SetGpuReg(REG_OFFSET_BG3CNT, 0x603);
        }
        break;
    case 5:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            gTasks[taskID].tState++;
            sEvoStructPtr->field_3 = 1;
            sEvoGraphicsTaskID = LaunchTask_PreEvoSparklesSet2();
        }
        break;
    case 6:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = sub_817C3A0(sEvoStructPtr->preEvoSpriteID, sEvoStructPtr->postEvoSpriteID);
            gTasks[taskID].tState++;
        }
        break;
    case 7:
        if (--sEvoStructPtr->field_3 == 0)
        {
            sEvoStructPtr->field_3 = 3;
            if (!gTasks[sEvoGraphicsTaskID].isActive)
                gTasks[taskID].tState++;
        }
        break;
    case 8:
        sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet1();
        gTasks[taskID].tState++;
        break;
    case 9:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            sEvoGraphicsTaskID = LaunchTask_PostEvoSparklesSet2AndFlash_Trade(gTasks[taskID].tPostEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 10:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            PlaySE(SE_EXP);
            gTasks[taskID].tState++;
        }
        break;
    case 11:
        if (IsSEPlaying())
        {
            Free(sEvoMovingBgPtr);
            EvoScene_DoMonAnimation(sEvoStructPtr->postEvoSpriteID, gTasks[taskID].tPostEvoSpecies);
            memcpy(&gPlttBufferUnfaded[0x20], sEvoStructPtr->savedPalette, 0x60);
            gTasks[taskID].tState++;
        }
        break;
    case 12:
        if (IsCryFinished())
        {
            StringExpandPlaceholders(gStringVar4, gText_CongratsPkmnEvolved);
            DrawTextOnTradeWindow(0, gStringVar4, 1);
            PlayFanfare(MUS_EVOLVED);
            gTasks[taskID].tState++;
            SetMonData(mon, MON_DATA_SPECIES, (&gTasks[taskID].tPostEvoSpecies));
            CalculateMonStats(mon);
            EvolutionRenameMon(mon, gTasks[taskID].tPreEvoSpecies, gTasks[taskID].tPostEvoSpecies);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_SEEN);
            GetSetPokedexFlag(SpeciesToNationalPokedexNum(gTasks[taskID].tPostEvoSpecies), FLAG_SET_CAUGHT);
            IncrementGameStat(GAME_STAT_EVOLVED_POKEMON);
        }
        break;
    case 13:
        if (!IsTextPrinterActive(0) && IsFanfareTaskInactive() == TRUE)
        {
            var = MonTryLearningNewMove(mon, gTasks[taskID].tLearnsFirstMove);
            if (var != 0 && !gTasks[taskID].tEvoWasStopped)
            {
                u8 text[20];

                gTasks[taskID].tBits |= TASK_BIT_LEARN_MOVE;
                gTasks[taskID].tLearnsFirstMove = FALSE;
                gTasks[taskID].tLearnMoveState = 0;
                GetMonData(mon, MON_DATA_NICKNAME, text);
                StringCopy10(gBattleTextBuff1, text);

                if (var == MON_HAS_MAX_MOVES)
                    gTasks[taskID].tState = 20;
                else if (var == MON_ALREADY_KNOWS_MOVE)
                    break;
                else
                    gTasks[taskID].tState = 18;
            }
            else
            {
                PlayBGM(MUS_EVOLUTION);
                DrawTextOnTradeWindow(0, gText_CommunicationStandby5, 1);
                gTasks[taskID].tState++;
            }
        }
        break;
    case 14:
        if (!IsTextPrinterActive(0))
        {
            DestroyTask(taskID);
            Free(sEvoStructPtr);
            sEvoStructPtr = NULL;
            gTextFlags.useAlternateDownArrow = 0;
            SetMainCallback2(gCB2_AfterEvolution);
        }
        break;
    case 15:
        if (!gTasks[sEvoGraphicsTaskID].isActive)
        {
            m4aMPlayAllStop();
            BeginNormalPaletteFade((1 << (gSprites[sEvoStructPtr->preEvoSpriteID].oam.paletteNum + 16)) | (0x4001C), 0, 0x10, 0, RGB_WHITE);
            gTasks[taskID].tState++;
        }
        break;
    case 16:
        if (!gPaletteFade.active)
        {
            EvoScene_DoMonAnimation(sEvoStructPtr->preEvoSpriteID, gTasks[taskID].tPreEvoSpecies);
            gTasks[taskID].tState++;
        }
        break;
    case 17:
        if (EvoScene_IsMonAnimFinished(sEvoStructPtr->preEvoSpriteID))
        {
            StringExpandPlaceholders(gStringVar4, gText_EllipsisQuestionMark);
            DrawTextOnTradeWindow(0, gStringVar4, 1);
            gTasks[taskID].tEvoWasStopped = 1;
            gTasks[taskID].tState = 13;
        }
        break;
    case 18:
        if (!IsTextPrinterActive(0) && !IsSEPlaying())
        {
            BufferMoveToLearnIntoBattleTextBuff2();
            PlayFanfare(MUS_LEVEL_UP);
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_ID_ADDER]);
            DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
            gTasks[taskID].tLearnsFirstMove = 0x40; // re-used as a counter
            gTasks[taskID].tState++;
        }
        break;
    case 19:
        if (!IsTextPrinterActive(0) && IsFanfareTaskInactive() == TRUE && --gTasks[taskID].tLearnsFirstMove == 0)
            gTasks[taskID].tState = 13;
        break;
    case 20:
        switch (gTasks[taskID].tLearnMoveState)
        {
        case 0:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BufferMoveToLearnIntoBattleTextBuff2();
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 1:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 2:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tData7 = 5;
                gTasks[taskID].tData8 = 9;
                gTasks[taskID].tLearnMoveState++;
            }
        case 3:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                LoadUserWindowBorderGfx(0, 0xA8, 0xE0);
                CreateYesNoMenu(&gTradeEvolutionSceneYesNoWindowTemplate, 0xA8, 0xE, 0);
                sEvoCursorPos = 0;
                gTasks[taskID].tLearnMoveState++;
                sEvoCursorPos = 0;
            }
            break;
        case 4:
            switch (Menu_ProcessInputNoWrapClearOnChoose())
            {
            case 0:
                sEvoCursorPos = 0;
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_EMPTYSTRING3 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState = gTasks[taskID].tData7;
                if (gTasks[taskID].tLearnMoveState == 5)
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                break;
            case 1:
            case -1:
                sEvoCursorPos = 1;
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_EMPTYSTRING3 - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState = gTasks[taskID].tData8;
                break;
            }
            break;
        case 5:
            if (!gPaletteFade.active)
            {
                if (gWirelessCommType)
                    DestroyWirelessStatusIndicatorSprite();

                Free(GetBgTilemapBuffer(3));
                Free(GetBgTilemapBuffer(1));
                Free(GetBgTilemapBuffer(0));
                FreeAllWindowBuffers();

                ShowSelectMovePokemonSummaryScreen(gPlayerParty, gTasks[taskID].tPartyID,
                            gPlayerPartyCount - 1, CB2_TradeEvolutionSceneLoadGraphics,
                            gMoveToLearn);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 6:
            if (!gPaletteFade.active && gMain.callback2 == CB2_TradeEvolutionSceneUpdate)
            {
                var = GetMoveSlotToReplace();
                if (var == MAX_MON_MOVES)
                {
                    gTasks[taskID].tLearnMoveState = 9;
                }
                else
                {
                    u16 move = GetMonData(mon, var + MON_DATA_MOVE1);
                    if (IsHMMove2(move))
                    {
                        BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_ID_ADDER]);
                        DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                        gTasks[taskID].tLearnMoveState = 11;
                    }
                    else
                    {
                        PREPARE_MOVE_BUFFER(gBattleTextBuff2, move)

                        RemoveMonPPBonus(mon, var);
                        SetMonMoveSlot(mon, gMoveToLearn, var);
                        BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_123POOF - BATTLESTRINGS_ID_ADDER]);
                        DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                        gTasks[taskID].tLearnMoveState++;
                    }
                }
            }
            break;
        case 7:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tLearnMoveState++;
            }
            break;
        case 8:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
            {
                BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_ANDELLIPSIS - BATTLESTRINGS_ID_ADDER]);
                DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
                gTasks[taskID].tState = 18;
            }
            break;
        case 9:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_ID_ADDER]);
            DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
            gTasks[taskID].tData7 = 10;
            gTasks[taskID].tData8 = 0;
            gTasks[taskID].tLearnMoveState = 3;
            break;
        case 10:
            BattleStringExpandPlaceholdersToDisplayedString(gBattleStringsTable[STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_ID_ADDER]);
            DrawTextOnTradeWindow(0, gDisplayedStringBattle, 1);
            gTasks[taskID].tState = 13;
            break;
        case 11:
            if (!IsTextPrinterActive(0) && !IsSEPlaying())
                gTasks[taskID].tLearnMoveState = 5;
            break;
        }
        break;
    }
}

#undef tState
#undef tPreEvoSpecies
#undef tPostEvoSpecies
#undef tCanStop
#undef tBits
#undef tLearnsFirstMove
#undef tLearnMoveState
#undef tData7
#undef tData8
#undef tEvoWasStopped
#undef tPartyID

static void EvoDummyFunc(void)
{
}

static void VBlankCB_EvolutionScene(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);

    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void VBlankCB_TradeEvolutionScene(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);

    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void sub_813FDEC(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[6] != 0)
        return;
    if (data[5]++ < 20)
        return;

    if (data[0]++ > sUnknown_085B58C9[data[2]][3])
    {
        if (sUnknown_085B58C9[data[2]][1] == data[1])
        {
            data[3]++;
            if (data[3] == sUnknown_085B58C9[data[2]][2])
            {
                data[3] = 0;
                data[2]++;
            }
            data[1] = sUnknown_085B58C9[data[2]][0];
        }
        else
        {
            LoadPalette(&sEvoMovingBgPtr[data[1] * 16], 0xA0, 0x20);
            data[0] = 0;
            data[1]++;
        }
    }

    if (data[2] == 4)
        DestroyTask(taskId);
}

static void sub_813FEA4(bool8 isLink)
{
    u8 taskId = CreateTask(sub_813FEE8, 7);

    if (!isLink)
        gTasks[taskId].data[2] = 0;
    else
        gTasks[taskId].data[2] = 1;
}

static void sub_813FEE8(u8 taskId)
{
    u16 *outer_X, *outer_Y;

    u16 *inner_X = &gBattle_BG1_X;
    u16 *inner_Y = &gBattle_BG1_Y;

    if (!gTasks[taskId].data[2])
    {
        outer_X = &gBattle_BG2_X;
        outer_Y = &gBattle_BG2_Y;
    }
    else
    {
        outer_X = &gBattle_BG3_X;
        outer_Y = &gBattle_BG3_Y;
    }

    gTasks[taskId].data[0] = (gTasks[taskId].data[0] + 5) & 0xFF;
    gTasks[taskId].data[1] = (gTasks[taskId].data[0] + 0x80) & 0xFF;

    *inner_X = Cos(gTasks[taskId].data[0], 4) + 8;
    *inner_Y = Sin(gTasks[taskId].data[0], 4) + 16;

    *outer_X = Cos(gTasks[taskId].data[1], 4) + 8;
    *outer_Y = Sin(gTasks[taskId].data[1], 4) + 16;

    if (!FuncIsActiveTask(sub_813FDEC))
    {
        DestroyTask(taskId);

        *inner_X = 0;
        *inner_Y = 0;

        *outer_X = 256;
        *outer_Y = 0;
    }
}

static void InitMovingBgValues(u16 *movingBgs)
{
    s32 i, j;

    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 16; j++)
        {
            movingBgs[i * 16 + j] = sUnknown_085B5884[sUnknown_085B58D9[i][j]];
        }
    }
}

static void InitMovingBackgroundTask(bool8 isLink)
{
    u8 innerBgId, outerBgId;

    sEvoMovingBgPtr = AllocZeroed(0x640);
    InitMovingBgValues(sEvoMovingBgPtr);

    if (!isLink)
        innerBgId = 1, outerBgId = 2;
    else
        innerBgId = 1, outerBgId = 3;

    LoadPalette(sUnknown_085B51E4, 0xA0, 0x20);

    DecompressAndLoadBgGfxUsingHeap(1, sUnknown_085B4134, FALSE, 0, 0);
    CopyToBgTilemapBuffer(1, sUnknown_085B482C, 0, 0);
    CopyToBgTilemapBuffer(outerBgId, sUnknown_085B4D10, 0, 0);
    CopyBgTilemapBufferToVram(1);
    CopyBgTilemapBufferToVram(outerBgId);

    if (!isLink)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG2_ON | DISPCNT_BG1_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);

        SetBgAttribute(innerBgId, BG_ATTR_PRIORITY, 2);
        SetBgAttribute(outerBgId, BG_ATTR_PRIORITY, 2);

        ShowBg(1);
        ShowBg(2);
    }
    else
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG3_ON | DISPCNT_BG1_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
    }

    CreateTask(sub_813FDEC, 5);
    sub_813FEA4(isLink);
}

static void sub_8140100(void) // unused
{
    u8 taskId = FindTaskIdByFunc(sub_813FDEC);

    if (taskId != 0xFF)
        gTasks[taskId].data[6] = 1;

    FillPalette(0, 0xA0, 0x20);
}

static void sub_8140134(void)
{
    u8 taskId;

    if ((taskId = FindTaskIdByFunc(sub_813FDEC)) != 0xFF)
        DestroyTask(taskId);
    if ((taskId = FindTaskIdByFunc(sub_813FEE8)) != 0xFF)
        DestroyTask(taskId);

    FillPalette(0, 0xA0, 0x20);
    sub_8140174();
}

static void sub_8140174(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    SetBgAttribute(1, BG_ATTR_PRIORITY, sub_80391E0(1, 5));
    SetBgAttribute(2, BG_ATTR_PRIORITY, sub_80391E0(2, 5));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG3_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
    Free(sEvoMovingBgPtr);
}

static void EvoScene_DoMonAnimation(u8 monSpriteId, u16 speciesId)
{
    DoMonFrontSpriteAnimation(&gSprites[monSpriteId], speciesId, FALSE, 0);
}

static bool32 EvoScene_IsMonAnimFinished(u8 monSpriteId)
{
    if (gSprites[monSpriteId].callback == SpriteCallbackDummy)
        return TRUE;

    return FALSE;
}
