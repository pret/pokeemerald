#include "global.h"
#include "evolution_scene.h"
#include "evolution_graphics.h"
#include "sprite.h"
#include "malloc.h"
#include "task.h"
#include "palette.h"
#include "main.h"
#include "text.h"
#include "text_window.h"
#include "pokemon.h"
#include "string_util.h"
#include "battle.h"
#include "unknown_task.h"
#include "decompress.h"
#include "m4a.h"
#include "menu.h"
#include "pokedex.h"
#include "species.h"
#include "sound.h"
#include "songs.h"
#include "overworld.h"
#include "battle_message.h"
#include "gpu_regs.h"
#include "bg.h"

struct EvoInfo
{
    u8 preEvoSpriteID;
    u8 postEvoSpriteID;
    u8 evoTaskID;
    u16 savedPalette[48];
};

extern struct EvoInfo *gEvoStructPtr;

extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;
extern u8 gBattleTerrain;
extern struct SpriteTemplate gUnknown_0202499C;

extern const struct CompressedSpriteSheet gMonFrontPicTable[];

extern void SpriteCallbackDummy_2(struct Sprite *sprite);
extern void sub_80356D0(void);
extern void sub_806A068(u16, u8);

// this file's functions
void Task_EvolutionScene(u8 taskID);
void Task_TradeEvolutionScene(u8 taskID);
void CB2_EvolutionSceneUpdate(void);
void CB2_TradeEvolutionSceneUpdate(void);
void EvoDummyFunc(void);
void EvoDummyFunc2(void);
void VBlankCB_EvolutionScene(void);
void VBlankCB_TradeEvolutionScene(void);
void sub_81150D8(void);

void CB2_BeginEvolutionScene(void)
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

void Task_BeginEvolutionScene(u8 taskID)
{
    struct Pokemon* mon = NULL;
    switch (gTasks[taskID].tState)
    {
    case 0:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
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
    u32 TiD, PiD;
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

    sub_80356D0();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    remove_some_task();
    ResetTasks();
    FreeAllSpritePalettes();

    gReservedSpritePaletteCount = 4;

    gEvoStructPtr = AllocZeroed(sizeof(struct EvoInfo));
    AllocateMonSpritesGfx();

    GetMonData(mon, MON_DATA_NICKNAME, name);
    StringCopy10(gStringVar1, name);
    StringCopy(gStringVar2, gSpeciesNames[speciesToEvolve]);

    // preEvo sprite
    currSpecies = GetMonData(mon, MON_DATA_SPECIES);
    TiD = GetMonData(mon, MON_DATA_OT_ID);
    PiD = GetMonData(mon, MON_DATA_PERSONALITY);
    DecompressPicFromTable_2(&gMonFrontPicTable[currSpecies],
                             gMonSpritesGfxPtr->sprites[1],
                             currSpecies);
    pokePal = GetMonSpritePalStructFromOtIdPersonality(currSpecies, TiD, PiD);
    LoadCompressedPalette(pokePal->data, 0x110, 0x20);

    sub_806A068(currSpecies, 1);
    gUnknown_0202499C.affineAnims = gDummySpriteAffineAnimTable;
    gEvoStructPtr->preEvoSpriteID = ID = CreateSprite(&gUnknown_0202499C, 120, 64, 30);

    gSprites[ID].callback = SpriteCallbackDummy_2;
    gSprites[ID].oam.paletteNum = 1;
    gSprites[ID].invisible = 1;

    // postEvo sprite
    DecompressPicFromTable_2(&gMonFrontPicTable[speciesToEvolve],
                             gMonSpritesGfxPtr->sprites[3],
                             speciesToEvolve);
    pokePal = GetMonSpritePalStructFromOtIdPersonality(speciesToEvolve, TiD, PiD);
    LoadCompressedPalette(pokePal->data, 0x120, 0x20);

    sub_806A068(speciesToEvolve, 3);
    gUnknown_0202499C.affineAnims = gDummySpriteAffineAnimTable;
    gEvoStructPtr->postEvoSpriteID = ID = CreateSprite(&gUnknown_0202499C, 120, 64, 30);
    gSprites[ID].callback = SpriteCallbackDummy_2;
    gSprites[ID].oam.paletteNum = 2;
    gSprites[ID].invisible = 1;

    LoadEvoSparkleSpriteAndPal();

    gEvoStructPtr->evoTaskID = ID = CreateTask(Task_EvolutionScene, 0);
    gTasks[ID].tState = 0;
    gTasks[ID].tPreEvoSpecies = currSpecies;
    gTasks[ID].tPostEvoSpecies = speciesToEvolve;
    gTasks[ID].tCanStop = canStopEvo;
    gTasks[ID].tLearnsFirstMove = TRUE;
    gTasks[ID].tEvoWasStopped = FALSE;
    gTasks[ID].tPartyID = partyID;

    memcpy(&gEvoStructPtr->savedPalette, &gPlttBufferUnfaded[0x20], 0x60);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);

    SetHBlankCallback(EvoDummyFunc);
    SetVBlankCallback(VBlankCB_EvolutionScene);
    m4aMPlayAllStop();
    SetMainCallback2(CB2_EvolutionSceneUpdate);
}

void CB2_EvolutionSceneLoadGraphics(void)
{
    u8 ID;
    const struct CompressedSpritePalette* pokePal;
    u16 postEvoSpecies;
    u32 TiD, PiD;
    struct Pokemon* Mon = &gPlayerParty[gTasks[gEvoStructPtr->evoTaskID].tPartyID];

    postEvoSpecies = gTasks[gEvoStructPtr->evoTaskID].tPostEvoSpecies;
    TiD = GetMonData(Mon, MON_DATA_OT_ID);
    PiD = GetMonData(Mon, MON_DATA_PERSONALITY);

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

    sub_80356D0();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 4;

    DecompressPicFromTable_2(&gMonFrontPicTable[postEvoSpecies],
                             gMonSpritesGfxPtr->sprites[3],
                             postEvoSpecies);
    pokePal = GetMonSpritePalStructFromOtIdPersonality(postEvoSpecies, TiD, PiD);

    LoadCompressedPalette(pokePal->data, 0x120, 0x20);

    sub_806A068(postEvoSpecies, 3);
    gUnknown_0202499C.affineAnims = gDummySpriteAffineAnimTable;
    gEvoStructPtr->postEvoSpriteID = ID = CreateSprite(&gUnknown_0202499C, 120, 64, 30);

    gSprites[ID].callback = SpriteCallbackDummy_2;
    gSprites[ID].oam.paletteNum = 2;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);

    SetHBlankCallback(EvoDummyFunc);
    SetVBlankCallback(VBlankCB_EvolutionScene);
    SetMainCallback2(CB2_EvolutionSceneUpdate);

    BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}
