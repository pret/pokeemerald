#include "global.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "title_screen.h"
#include "libgcnmultiboot.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "link.h"
#include "multiboot_pokemon_colosseum.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "random.h"
#include "decompress.h"
#include "constants/songs.h"
#include "intro_credits_graphics.h"
#include "trig.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "constants/species.h"
#include "blend_palette.h"
#include "title_screen.h"

extern EWRAM_DATA u16 gUnknown_0203BCC8;
extern EWRAM_DATA u16 gUnknown_0203BCCA;
extern EWRAM_DATA u16 gUnknown_0203BCCC;

extern u16 gUnknown_0203BD24;
extern u16 gUnknown_0203BD26;
extern u16 gUnknown_0203BD28;

extern u32 gIntroFrameCounter;
extern struct GcmbStruct gMultibootProgramStruct;

extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];

extern const struct SpriteTemplate gUnknown_08596C10[];

extern u8 gIntroCopyright_Gfx[];
extern u8 gIntroCopyright_Tilemap[];
extern u16 gIntroCopyright_Pal[];

extern const u16 gIntro1BGPals[16][16]/* =
{
    INCBIN_U16("graphics/intro/intro1_bgpal1.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal2.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal3.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal4.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal5.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal6.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal7.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal8.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal9.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal10.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal11.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal12.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal13.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal14.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal15.gbapal"),
    INCBIN_U16("graphics/intro/intro1_bgpal16.gbapal"),
}*/;
extern const u8 gIntro1BG0_Tilemap[]/* = INCBIN_U8("graphics/intro/intro1_bg0_map.bin.lz")*/;
extern const u8 gIntro1BG1_Tilemap[]/* = INCBIN_U8("graphics/intro/intro1_bg1_map.bin.lz")*/;
extern const u8 gIntro1BG2_Tilemap[]/* = INCBIN_U8("graphics/intro/intro1_bg2_map.bin.lz")*/;
extern const u8 gIntro1BG3_Tilemap[]/* = INCBIN_U8("graphics/intro/intro1_bg3_map.bin.lz")*/;
extern const u8 gIntro1BGLeavesGfx[]/* = INCBIN_U8("graphics/intro/introgfx.4bpp.lz")*/;
extern const u16 gIntro3PokeballPal[]/* = INCBIN_U16("graphics/intro/intro3_pokeball.gbapal")*/;
extern const u8 gIntro3Pokeball_Tilemap[]/* = INCBIN_U8("graphics/intro/intro3_pokeball_map.bin.lz")*/;
extern const u8 gIntro3Pokeball_Gfx[]/* = INCBIN_U8("graphics/intro/intro3_pokeball.8bpp.lz")*/;

extern const struct CompressedSpriteSheet gUnknown_085E4A74[];
extern const struct SpritePalette gUnknown_085E4A84[];
extern const struct SpriteTemplate gUnknown_085E4AB8[];
extern const struct CompressedSpriteSheet gUnknown_085E4AE8[3];
extern const u8 gUnknown_085E4AD0[][2];
extern const struct SpritePalette gUnknown_085E4B08[];
extern const struct SpriteTemplate gUnknown_085E4B40[];
extern const struct SpriteTemplate gUnknown_085E4BA4[];
extern const struct SpriteTemplate gUnknown_085E4BDC[];
extern const struct CompressedSpriteSheet gUnknown_085E4BF4[];
extern const struct SpritePalette gUnknown_085E4C04[];
extern const struct SpriteTemplate gUnknown_085E4C4C[];
extern const s16 gUnknown_085E4C64[][3];
extern const struct CompressedSpriteSheet gUnknown_085E4C88[];
extern const struct SpritePalette gUnknown_085E4C98[];
extern const s16 gUnknown_085E4CA8[][3];
extern const struct SpriteTemplate gUnknown_085E4D14[];
extern const struct SpriteTemplate gUnknown_085E4D64/* =
{
    .tileTag = 2000,
    .paletteTag = 2000,
    .oam = &gOamData_840ADE8,
    .anims = gSpriteAnimTable_840AE10,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_813D208,
}*/;
extern const union AnimCmd *const gUnknown_085E4DC4[]/* =
{
    Unknown_40AE38,
    Unknown_40AE4C,
    Unknown_40AE60,
    Unknown_40AE70,
}*/;
extern const s16 gUnknown_085E4E94[][2];
extern const u16 gUnknown_085E4F48[];
extern const struct SpriteTemplate gUnknown_085E4F5C[];
extern const struct SpriteTemplate gUnknown_085E4F8C[];
extern const u8 gUnknown_085E4FA4[];
extern const struct SpriteTemplate gUnknown_085E4FC4[];
extern const struct CompressedSpriteSheet gUnknown_085E4FDC[]/* =
{
    {gIntroTiles, 0x1400, 2000},
    {NULL},
}*/;
extern const struct CompressedSpriteSheet gUnknown_085E4FEC[]/* =
{
    {gIntro1EonTiles, 0x400, 2002},
    {NULL},
}*/;
extern const struct SpritePalette gUnknown_085E4FFC[]/* =
{
    {Palette_406340, 2000},
    {Palette_406360, 2001},
    {gIntro1EonPalette, 2002},
    {NULL},
}*/;
extern const struct SpriteTemplate gUnknown_085E5030[];
extern const struct CompressedSpriteSheet gUnknown_085E5048[];
extern const struct SpritePalette gUnknown_085E5058[];

extern void MainCB2_EndIntro(void);
extern void Task_IntroLoadPart1Graphics(u8);
extern u8 CreateWaterDrop(s16, s16, u16, u16, u16, u8);
extern void Task_IntroFadeIn(u8);
extern void intro_reset_and_hide_bgs(void);
extern void Task_IntroWaterDrops(u8);
extern void Task_IntroWaterDrops_1(u8);
extern void Task_IntroWaterDrops_2(u8);
extern void Task_IntroWaterDrops_3(u8);
extern void Task_IntroScrollDownAndShowFlygon(u8);
extern void Task_IntroWaitToSetupPart2(u8);
extern void Task_IntroLoadPart2Graphics(u8);
extern void Task_IntroStartBikeRide(u8);
extern void Task_IntroHandleBikeAndFlygonMovement(u8);
extern void Task_IntroWaitToSetupPart3(u8);
extern void Task_IntroLoadPart3Graphics(u8);
extern void Task_IntroSpinAndZoomPokeball(u8);
extern void Task_IntroWaitToSetupPart3LegendsFight(u8);
extern void Task_IntroLoadPart1Graphics3(u8);
extern void Task_IntroLoadPart1Graphics4(u8);
extern void Task_IntroLoadPart1Graphics5(u8);
extern void Task_IntroLoadPart1Graphics6(u8);
extern void Task_IntroLoadPart1Graphics7(u8);
extern void Task_IntroLoadPart1Graphics8(u8);
extern void Task_IntroLoadPart1Graphics9(u8);
extern void Task_IntroFadeIn0(u8);
extern void Task_IntroFadeIn1(u8);
extern void Task_IntroFadeIn2(u8);
extern void Task_IntroFadeIn3(u8);
extern void Task_IntroFadeIn4(u8);
extern void Task_IntroFadeIn5(u8);
extern void Task_IntroFadeIn6(u8);
extern void Task_IntroFadeIn7(u8);
extern void Task_IntroFadeIn8(u8);
extern void Task_IntroFadeIn9(u8);
extern void sub_816E190(u8);
extern void sub_816E1F8(struct Sprite *);
extern void sub_816E6D4(u8);
extern void sub_816E74C(void);
extern void sub_816EEA8(u8);
extern void sub_816F46C(struct Sprite *);
extern void sub_816F5B4(struct Sprite *);
extern void sub_816F660(struct Sprite *);
extern void SpriteCB_WaterDropFall(struct Sprite *);
extern void sub_816F318(struct Sprite *);
extern void sub_816F9D4(struct Sprite *);
extern void sub_816FAB0(struct Sprite *);
extern u8 sub_816FDB8(s16, s16, s16);

void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

void MainCB2_Intro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gMain.newKeys && !gPaletteFade.active)
        SetMainCallback2(MainCB2_EndIntro);
    else if (gIntroFrameCounter != -1)
        gIntroFrameCounter++;
}

void MainCB2_EndIntro(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitTitleScreen);
}

void LoadCopyrightGraphics(u16 tilesetAddress, u16 tilemapAddress, u16 paletteAddress)
{
    LZ77UnCompVram(gIntroCopyright_Gfx, (void *)(VRAM + tilesetAddress));
    LZ77UnCompVram(gIntroCopyright_Tilemap, (void *)(VRAM + tilemapAddress));
    LoadPalette(gIntroCopyright_Pal, paletteAddress, 0x20);
}

void SerialCB_CopyrightScreen(void)
{
    GameCubeMultiBoot_HandleSerialInterrupt(&gMultibootProgramStruct);
}

u8 SetUpCopyrightScreen(void)
{
    u16 ime;

    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *(u16 *)PLTT = 0x7FFF;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        CpuFill32(0, (void *)OAM, OAM_SIZE);
        CpuFill16(0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        LoadCopyrightGraphics(0, 0x3800, 0);
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0xFFFF);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Intro);
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON;
        SetSerialCallback(SerialCB_CopyrightScreen);
        GameCubeMultiBoot_Init(&gMultibootProgramStruct);
    default:
        UpdatePaletteFade();
        gMain.state++;
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        break;
    case 140:
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        if (gMultibootProgramStruct.gcmb_field_2 != 1)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
            gMain.state++;
        }
        break;
    case 141:
        if (UpdatePaletteFade())
            break;
        CreateTask(Task_IntroLoadPart1Graphics, 0);
        SetMainCallback2(MainCB2_Intro);
        if (gMultibootProgramStruct.gcmb_field_2 != 0)
        {
            if (gMultibootProgramStruct.gcmb_field_2 == 2)
            {
                // check the multiboot ROM header game code to see if we already did this
                if (*(u32 *)(EWRAM_START + 0xAC) == 0x65366347) // "Gc6e" in ASCII
                {
                    CpuCopy16(&gMultiBootProgram_PokemonColosseum_Start, (void *)EWRAM_START, sizeof(gMultiBootProgram_PokemonColosseum_Start));
                    *(u32 *)(EWRAM_START + 0xAC) = 0x65366347;
                }
                GameCubeMultiBoot_ExecuteProgram(&gMultibootProgramStruct);
            }
        }
        else
        {
            GameCubeMultiBoot_Quit();
            SetSerialCallback(SerialCB);
        }
        return 0;
    }

    return 1;
}

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (!SetUpCopyrightScreen())
    {
        SetSaveBlocksPointers(sub_815355C());
        sub_808447C();
        Save_ResetSaveCounters();
        Save_LoadGameData(SAVE_NORMAL);
        if (gSaveFileStatus == 0 || gSaveFileStatus == 2)
            Sav2_ClearSetDefault();
        SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
        InitHeap(gHeap, HEAP_SIZE);
    }
}

void CB2_InitCopyrightScreenAfterTitleScreen(void)
{
    SetUpCopyrightScreen();
}

void Task_IntroLoadPart1Graphics(u8 taskId)
{
    SetVBlankCallback(NULL);
    gUnknown_0203BCC8 = Random() & 1;
    intro_reset_and_hide_bgs();
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0x50);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0x18);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0x28);
    LZ77UnCompVram(gIntro1BGLeavesGfx, (void *)VRAM);
    LZ77UnCompVram(gIntro1BG0_Tilemap, (void *)(VRAM + 0x8000));
    DmaClear16(3, VRAM + 0x8800, 0x800);
    LZ77UnCompVram(gIntro1BG1_Tilemap, (void *)(VRAM + 0x9000));
    DmaClear16(3, VRAM + 0x9800, 0x800);
    LZ77UnCompVram(gIntro1BG2_Tilemap, (void *)(VRAM + 0xA000));
    DmaClear16(3, VRAM + 0xA800, 0x800);
    LZ77UnCompVram(gIntro1BG3_Tilemap, (void *)(VRAM + 0xB000));
    DmaClear16(3, VRAM + 0xB800, 0x800);
    LoadPalette(gIntro1BGPals, 0, sizeof(gIntro1BGPals));
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(22) | BGCNT_16COLOR | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(20) | BGCNT_16COLOR | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(18) | BGCNT_16COLOR | BGCNT_TXT256x512);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(16) | BGCNT_16COLOR | BGCNT_TXT256x512);
    LoadCompressedObjectPic(gUnknown_085E4FDC);
    LoadCompressedObjectPic(gUnknown_085E4FEC);
    LoadSpritePalettes(gUnknown_085E4FFC);
    LoadCompressedObjectPic(gUnknown_085E4A74);
    LoadSpritePalettes(gUnknown_085E4A84);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1F0, 0x20);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1E1, 0x1E);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1D2, 0x1C);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1C3, 0x1A);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1B4, 0x18);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x1A5, 0x16);
    CpuCopy16(gPlttBufferUnfaded + 0x100, gPlttBufferUnfaded + 0x196, 0x14);
    sub_816FDB8(0x78, 0x50, 0);
    gTasks[taskId].data[0] = CreateWaterDrop(236, -14, 0x200, 1, 0x78, FALSE);
    gTasks[taskId].func = Task_IntroFadeIn;
}

void Task_IntroFadeIn(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
    SetVBlankCallback(VBlankCB_Intro);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_IntroWaterDrops;
    gIntroFrameCounter = 0;
    m4aSongNumStart(MUS_DEMO1);
    ResetSerial();
}

void Task_IntroWaterDrops(u8 taskId)
{
    //start moving rock
    if (gIntroFrameCounter == 76)
        gSprites[gTasks[taskId].data[0]].data[0] = 1;

    if (gIntroFrameCounter == 128)
        CreateTask(Task_IntroWaterDrops_1, 0);

    //drop rock
    if (gIntroFrameCounter == 251)
        gSprites[gTasks[taskId].data[0]].data[0] = 2;

    if (gIntroFrameCounter == 256)
        CreateTask(Task_IntroWaterDrops_2, 0);
    
    if (gIntroFrameCounter == 368)
        CreateWaterDrop(48, 0, 0x400, 5, 0x70, TRUE);
    
    if (gIntroFrameCounter == 384)
        CreateWaterDrop(200, 60, 0x400, 9, 0x80, TRUE);

    if (gIntroFrameCounter == 560)
        CreateTask(Task_IntroWaterDrops_3, 0);

    if (gIntroFrameCounter > 560)
    {
        gTasks[taskId].data[1] = 0x50;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0x18;
        gTasks[taskId].data[4] = 0;
        gTasks[taskId].data[5] = 0x28;
        gTasks[taskId].data[6] = 0;
        gTasks[taskId].func = Task_IntroScrollDownAndShowFlygon;
    }
}

void Task_IntroWaterDrops_3(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (++data[2] & 1)
        data[3]++;
    
    switch (data[0])
    {
        case 0:
            CreateSprite(gUnknown_085E4AB8, gUnknown_085E4AD0[data[4]][0], gUnknown_085E4AD0[data[4]][1] + data[3], 0);
            data[0]++;
            data[1] = 0xC;
            data[4]++;
            break;
        case 1:
            if (!--data[1])
                data[0] = 0;
            break;
    }
    
    if (data[3] > 0x3C)
        DestroyTask(taskId);
}

void sub_816D338(struct Sprite *sprite)
{
    if (++sprite->data[0] == 0xC)
        DestroySprite(sprite);
}

void Task_IntroScrollDownAndShowFlygon(u8 taskId)
{
    if (gIntroFrameCounter < 904)
    {
        s32 r2;

        //slide backgrounds downward
        r2 = (gTasks[taskId].data[1] << 16) + (u16)gTasks[taskId].data[2];
        r2 -= 0x6000;
        gTasks[taskId].data[1] = r2 >> 16;
        gTasks[taskId].data[2] = r2;
        SetGpuReg(REG_OFFSET_BG2VOFS, gTasks[taskId].data[1]);
        r2 = (gTasks[taskId].data[3] << 16) + (u16)gTasks[taskId].data[4];
        r2 -= 0x8000;
        gTasks[taskId].data[3] = r2 >> 16;
        gTasks[taskId].data[4] = r2;
        SetGpuReg(REG_OFFSET_BG1VOFS, gTasks[taskId].data[3]);
        r2 = (gTasks[taskId].data[5] << 16) + (u16)gTasks[taskId].data[6];
        r2 -= 0xC000;
        gTasks[taskId].data[5] = r2 >> 16;
        gTasks[taskId].data[6] = r2;
        SetGpuReg(REG_OFFSET_BG0VOFS, gTasks[taskId].data[5]);

        //show Flygon sprite
        if (gIntroFrameCounter == 832)
        {
            u8 spriteId = CreateSprite(gUnknown_085E4FC4, 120, 160, 10);
            gSprites[spriteId].invisible = TRUE;
        }
    }
    else
    {
        //fade to white
        if (gIntroFrameCounter > 1007)
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0xFFFF);
            gTasks[taskId].func = Task_IntroWaitToSetupPart2;
        }
    }
}

void Task_IntroWaitToSetupPart2(u8 taskId)
{
    if (gIntroFrameCounter > 1026)
        gTasks[taskId].func = Task_IntroLoadPart2Graphics;
}

void Task_IntroLoadPart2Graphics(u8 taskId)
{
    intro_reset_and_hide_bgs();
    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    gUnknown_0203BD24 = 0;
    gUnknown_0203BD26 = 0;
    gUnknown_0203BCCC = 0;
    load_intro_part2_graphics(1);
    gTasks[taskId].func = Task_IntroStartBikeRide;
}

void Task_IntroStartBikeRide(u8 taskId)
{
    u8 spriteId;

    if (gUnknown_0203BCC8 == 0)
        LoadCompressedObjectPic(gIntro2BrendanSpriteSheet);
    else
        LoadCompressedObjectPic(gIntro2MaySpriteSheet);
    
    LoadCompressedObjectPic(gIntro2BicycleSpriteSheet);
    LoadCompressedObjectPic(gIntro2FlygonSpriteSheet);
    
    for (spriteId = 0; spriteId < 3; spriteId++)
    {
        LoadCompressedObjectPic(&gUnknown_085E4AE8[spriteId]);
    }
    
    LoadSpritePalettes(gUnknown_085F530C);
    LoadSpritePalettes(gUnknown_085E4B08);
    CreateSprite(gUnknown_085E4BDC, 0x110, 0x80, 0);
    CreateSprite(gUnknown_085E4BA4, 0x120, 0x6E, 1);
    
    if (gUnknown_0203BCC8 == 0)
        spriteId = intro_create_brendan_sprite(0x110, 100);
    else
        spriteId = intro_create_may_sprite(0x110, 100);
    
    gSprites[spriteId].callback = sub_816F9D4;
    gSprites[spriteId].anims = gUnknown_085E4DC4;
    gTasks[taskId].data[1] = spriteId;
    CreateSprite(gUnknown_085E4B40, 0x110, 0x50, 0x4);
    spriteId = intro_create_flygon_sprite(-0x40, 0x3C);
    gSprites[spriteId].callback = sub_816FAB0;
    gTasks[taskId].data[2] = spriteId;
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0xFFFF);
    SetVBlankCallback(VBlankCB_Intro);
    gTasks[taskId].data[0] = sub_817B3DC(1, 0x4000, 0x400, 0x10);
    sub_817B150(1);
    gTasks[taskId].func = Task_IntroHandleBikeAndFlygonMovement;
}

void Task_IntroHandleBikeAndFlygonMovement(u8 taskId)
{
    s16 a;
    u16 sine;
    
    if (gIntroFrameCounter == 1856)
    {
        gUnknown_0203BD28 = 2;
        DestroyTask(gTasks[taskId].data[0]);
    }
    if (gIntroFrameCounter > 1946)
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 8, 0, 16, 0xFFFF);
        gTasks[taskId].func = Task_IntroWaitToSetupPart3;
    }
    if (gIntroFrameCounter == 1109)
        gSprites[gTasks[taskId].data[1]].data[0] = 1;
    if (gIntroFrameCounter == 1214)
        gSprites[gTasks[taskId].data[1]].data[0] = 0;
    if (gIntroFrameCounter == 1394)
        gSprites[gTasks[taskId].data[2]].data[0] = 1;
    if (gIntroFrameCounter == 1398)
        gSprites[gTasks[taskId].data[1]].data[0] = 2;
    if (gIntroFrameCounter == 1576)
        gSprites[gTasks[taskId].data[1]].data[0] = 3;
    if (gIntroFrameCounter == 1727)
        gSprites[gTasks[taskId].data[1]].data[0] = 4;

    sine = Sin(gTasks[taskId].data[3] >> 2 & 0x7F, 48);
    gUnknown_0203BCCC = sine;
    if (gTasks[taskId].data[3] < 512)
        gTasks[taskId].data[3]++;
    sub_817B540(0);
}

void Task_IntroWaitToSetupPart3(u8 taskId)
{
    if (gIntroFrameCounter > 2068)
        gTasks[taskId].func = Task_IntroLoadPart3Graphics;
}

void sub_816D81C(struct Sprite *sprite)
{
    sprite->data[3] += 4;
    switch (sprite->data[0])
    {
        case 0:
            if (++sprite->data[1] < 180)
                break;
            ++sprite->data[0];
        case 1:
            sprite->pos1.x -= 4;
            if (sprite->pos1.x == 0x3C)
            {
                sprite->data[0] = 8;
                sprite->data[1] = 20;
                sprite->data[2] = 2;
            }
            break;
        case 2:
            sprite->pos1.x += 8;
            sprite->pos1.y -= 2;
            if (sprite->pos1.x == 0x7C)
            {
                sprite->data[0] = 8;
                sprite->data[1] = 20;
                sprite->data[2] = 3;
            }
            break;
        case 3:
            sprite->pos1.y += 4;
            if (sprite->pos1.y == 0x50)
            {
                sprite->data[0] = 8;
                sprite->data[1] = 10;
                sprite->data[2] = 4;
            }
            break;
        case 4:
            sprite->pos1.x -= 8;
            sprite->pos1.y -= 2;
            if (sprite->pos1.x == 0x3C)
            {
                sprite->data[0] = 8;
                sprite->data[1] = 10;
                sprite->data[2] = 5;
            }
            break;
        case 5:
            sprite->pos1.x += 0x3C;
            sprite->data[4] = 0xC0;
            sprite->data[5] = 0x80;
            sprite->data[6] = 0x3;
            sprite->data[0]++;
        case 6:
            sprite->pos2.x = Sin((u8)sprite->data[4], 0x3C);
            sprite->pos2.y = Sin((u8)sprite->data[5], 0x14);
            sprite->data[4] += 2;
            sprite->data[5] += 4;
            if ((sprite->data[4] & 0xFF) == 0x40)
            {
                sprite->hFlip = FALSE;
                if (!--sprite->data[6])
                {
                    sprite->pos1.x += sprite->pos2.x;
                    sprite->pos2.x = 0;
                    sprite->data[0]++;
                }
            }
            break;
        case 7:
            sprite->pos1.x -= 2;
            sprite->pos2.y = Sin((u8)sprite->data[5], 0x14);
            sprite->data[5] += 4;
            if (sprite->pos1.x < -16)
                DestroySprite(sprite);
            break;
        case 8:
            sprite->pos2.y = Cos((u8)sprite->data[3], 2);
            if (!--sprite->data[1])
                sprite->data[0] = sprite->data[2];
            break;
    }
}

void sub_816D9C0(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
        case 0:
            if (gIntroFrameCounter == 1224)
            {
                StartSpriteAnim(sprite, 1);
                sprite->data[0]++;
            }
            break;
        case 1:
            if (gIntroFrameCounter == 1576)
            {
                StartSpriteAnim(sprite, 0);
                sprite->data[0]++;
            }
            else
            {
                sprite->data[1] += 0x40;
                if (sprite->data[1] & 0xFF00)
                {
                    sprite->pos1.x--;
                    sprite->data[1] &= 0xFF;
                }
            }
            break;
        case 2:
            if (gIntroFrameCounter != 1735)
            {
                sprite->data[1] += 0x20;
                if (sprite->data[1] & 0xFF00)
                {
                    sprite->pos1.x++;
                    sprite->data[1] &= 0xFF;
                }
            }
            else
            {
                StartSpriteAnim(sprite, 1);
                sprite->data[0]++;
                sprite->data[2] = 0x50;
            }
            break;
        case 3:
            if (--sprite->data[2])
            {
                sprite->data[1] += 0x40;
                if (sprite->data[1] & 0xFF00)
                {
                    sprite->pos1.x--;
                    sprite->data[1] &= 0xFF;
                }
            }
            else
            {
                StartSpriteAnim(sprite, 2);
                sprite->data[0]++;
            }
            break;
        case 4:
            if (sprite->animEnded)
                sprite->pos1.x += 4;
            
            if (sprite->pos1.x > 336)
            {
                StartSpriteAnim(sprite, 1);
                sprite->data[0]++;
            }
            break;
        case 5:
            if (gIntroFrameCounter > 1855)
                sprite->pos1.x -= 2;
            break;
    }
}

void sub_816DAE8(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
        case 0:
            if (gIntroFrameCounter == 1088)
                sprite->data[0]++;
            break;
        case 1:
            sprite->pos1.x -= 2;
            if (gIntroFrameCounter != 1168)
                break;
            sprite->pos1.y -= 12;
            sprite->data[1] = 0x80;
            sprite->data[2] = 0;
            sprite->data[0]++;
        case 2:
            if (sprite->pos1.x + sprite->pos2.x <= -0x20)
            {
                DestroySprite(sprite);
            }
            else
            {
                if ((sprite->data[1] & 0xFF) < 0x40)
                {
                    sprite->pos2.x = Sin((u8)sprite->data[1], 0x10);
                }
                else
                {
                    if ((sprite->data[1] & 0xFF) == 0x40)
                        sprite->pos1.x -= 0x30;
                    sprite->pos2.x = Sin((u8)sprite->data[1], 0x40);
                }
                sprite->data[1]++;
                sprite->pos2.y = Cos((u8)sprite->data[2], 0xC);
                sprite->data[2]++;
            }
            break;
    }
}

void Task_IntroLoadPart3Graphics(u8 taskId)
{
    intro_reset_and_hide_bgs();
    LZ77UnCompVram(gIntro3Pokeball_Gfx, (void *)VRAM);
    LZ77UnCompVram(gIntro3Pokeball_Tilemap, (void *)(VRAM + 0x4000));
    LoadPalette(gIntro3PokeballPal, 0, 0x200);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[3] = 0;
    sub_816F2A8(0x78, 0x50, 0, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0xFFFF);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(8) | BGCNT_256COLOR | BGCNT_AFF256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_IntroSpinAndZoomPokeball;
    gIntroFrameCounter = 0;
    m4aSongNumStart(MUS_T_BATTLE);
}

void Task_IntroSpinAndZoomPokeball(u8 taskId)
{
    gTasks[taskId].data[0] += 0x400;
    
    if (gTasks[taskId].data[1] <= 0x6BF)
    {
        gTasks[taskId].data[1] += gTasks[taskId].data[2];
        gTasks[taskId].data[2] += 2;
    }
    else
    {
        gTasks[taskId].func = Task_IntroWaitToSetupPart3LegendsFight;
    }
    
    sub_816F2A8(0x78, 0x50, 0x10000 / gTasks[taskId].data[1], gTasks[taskId].data[0]);
    
    if (gIntroFrameCounter == 28)
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0xFFFF);
}

void Task_IntroWaitToSetupPart3LegendsFight(u8 taskId)
{
    if (gIntroFrameCounter > 43)
        gTasks[taskId].func = Task_IntroLoadPart1Graphics3;
}

void Task_IntroLoadPart1Graphics3(u8 taskId)
{
    u16 i;
    
    if (!gPaletteFade.active)
    {
        intro_reset_and_hide_bgs();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        LZDecompressVram(gIntro3GroudonGfx, (void *)VRAM);
        LZDecompressVram(gIntro3GroudonTilemap, (void *)(VRAM + 0xC000));
        LZDecompressVram(gIntro3LegendBgGfx, (void *)(VRAM + 0x4000));
        LZDecompressVram(gIntro3GroudonBgTilemap, (void *)(VRAM + 0xE000));
        LoadCompressedObjectPicUsingHeap(&gBattleAnimPicTable[0x3A]);
        LoadCompressedObjectPaletteUsingHeap(&gBattleAnimPaletteTable[0x3A]);
        CpuCopy16(gIntro3BgPal, gPlttBufferUnfaded, sizeof(gIntro3BgPal));
        gTasks[taskId].func = Task_IntroLoadPart1Graphics4;
    }
}

void Task_IntroLoadPart1Graphics4(u8 taskId)
{
    SetGpuReg(REG_OFFSET_WIN0H, 0xF0);
    SetGpuReg(REG_OFFSET_WIN0V, 0xA0);
    SetGpuReg(REG_OFFSET_WININ, 0x3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_256COLOR
                               | BGCNT_WRAP
                               | BGCNT_AFF512x512);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0x10, 0, 0xFFFF);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0xFFA0;
    gTasks[taskId].data[2] = 0xFF51;
    gTasks[taskId].data[3] = 0x100;
    sub_816F2A8(0xFFA0, 0xFF51, 0x100, 0);
    gTasks[taskId].func = Task_IntroLoadPart1Graphics5;
}

void Task_IntroLoadPart1Graphics5(u8 taskId)
{
    u16 foo = gTasks[taskId].data[0];

    if (gTasks[taskId].data[0] != 32)
    {
        gTasks[taskId].data[0] += 4;
        SetGpuReg(REG_OFFSET_WIN0V, (gTasks[taskId].data[0] * 256) - (foo -= 0x9C));
    }
    else
    {
        SetGpuReg(REG_OFFSET_WIN0V, 0x2080);
        gTasks[taskId].func = Task_IntroLoadPart1Graphics6;
    }
}

void Task_IntroLoadPart1Graphics6(u8 taskId)
{
    gTasks[taskId].func = Task_IntroLoadPart1Graphics7;
}

void Task_IntroLoadPart1Graphics7(u8 taskId)
{
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].func = Task_IntroLoadPart1Graphics8;
    ScanlineEffect_InitWave(0, 0xA0, 0x4, 4, 1, 4, 0);
}

void Task_IntroLoadPart1Graphics8(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    data[5]++;
    if ((u16)(data[0] - 1) < 7 && data[5] % 2 == 0)
        data[4] ^= 3;
    sub_816F2A8(data[1], data[2] + data[4], data[3], 0);
    switch (data[0])
    {
        case 0:
            data[1] += 0x10;
            if (data[1] == 0xA0)
            {
                data[0]++;
                data[6] = 2;
                data[7] = 0x1E2;
                sub_816E190(taskId);
            }
            break;
        case 1:
            if (--data[6] == 0)
            {
                data[6] = 2;
                CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[31], sizeof(u16));
                data[7] += 2;
                if (data[7] == 0x1EC)
                    data[0]++;
            }
            break;
        case 2:
            if (--data[6] == 0)
            {
                data[6] = 2;
                data[0]++;
            }
            break;
        case 3:
            if (--data[6] == 0)
            {
                data[6] = 2;
                CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[31], sizeof(u16));
                data[7] -= 2;
                if (data[7] == 0x1E0)
                {
                    data[6] = 8;
                    data[0]++;
                }
            }
            break;
        case 4:
            if (--data[6] == 0)
            {
                data[1] = -0x60;
                data[2] = 0xA9;
                data[6] = 3;
                data[0]++;
            }
            break;
        case 5:
            if (--data[6] == 0)
            {
                data[1] = 0x50;
                data[2] = 0x29;
                data[6] = 0x10;
                PlayCryInternal(SPECIES_GROUDON, 0, 100, 10, 0);
                data[0]++;
            }
            break;
        case 6:
            if (--data[6] == 0)
            {
                data[1] = 0x50;
                data[2] = 0x28;
                data[0]++;
            }
            break;
        case 7:
            data[1] += 4;
            data[2] += 4;
            data[6] += 0x666;
            data[3] = Sin((data[6] & 0xFF00) >> 8, 0x40) + 0x100;
            if (data[1] == 0x78)
            {
                BeginNormalPaletteFade(0xFFFFFFFE, 3, 0, 16, 0x7FFF);
                data[3] = 0x100;
                data[4] = 0;
                data[0]++;
            }
            break;
        case 8:
            if (data[3])
                data[3] -= 8;
            else
                data[0]++;
            break;
        case 9:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].func = Task_IntroLoadPart1Graphics9;
                gScanlineEffect.state = 3;
            }
            break;
    }
}

void sub_816E190(u8 a0)
{
    int i;
    u8 spriteId;
    
    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(gUnknown_08596C10, gUnknown_085E4C64[i][0], 0xA0, i);
        gSprites[spriteId].callback = sub_816E1F8;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].data[1] = i;
        gSprites[spriteId].data[4] = a0;
        StartSpriteAnim(&gSprites[spriteId], gUnknown_085E4C64[i][1]);
    }
}

void sub_816E1F8(struct Sprite *sprite)
{
    sprite->data[3]++;
    if (sprite->data[3] % 2 == 0)
        sprite->pos2.y ^= 3;
    
    switch(sprite->data[0])
    {
        case 0:
            sprite->data[2] += gUnknown_085E4C64[sprite->data[1]][2];
            sprite->pos1.y -= (sprite->data[2] & 0xFF00) >> 8;
            sprite->data[2] &= 0xFF;
            if (gTasks[sprite->data[4]].data[0] > 7)
                sprite->data[0]++;
            break;
        case 1:
            if (sprite->pos1.x < 0x78)
                sprite->pos1.x -= 2;
            else
                sprite->pos1.x += 2;
            
            if (sprite->pos1.y < 0x50)
                sprite->pos1.y -= 2;
            else
                sprite->pos1.y += 2;
            break;
    }
}

void Task_IntroLoadPart1Graphics9(u8 taskId)
{
    ResetSpriteData();
    LZDecompressVram(gIntro3KyogreGfx, (void *)VRAM);
    LZDecompressVram(gIntro3KyogreTilemap, (void *)(VRAM + 0xC000));
    LZDecompressVram(gIntro3KyogreBgTilemap, (void *)(VRAM + 0xE000));
    LoadCompressedObjectPic(gUnknown_085E4C88);
    LoadSpritePalette(gUnknown_085E4C98);
    BeginNormalPaletteFade(0xFFFFFFFE, 0, 0x10, 0, 0xFFFF);
    gTasks[taskId].func = Task_IntroFadeIn0;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0x150;
    gTasks[taskId].data[2] = 0x50;
    gTasks[taskId].data[6] = 0x10;
    gTasks[taskId].data[3] = 0x100;
    sub_816F2A8(0x150, 0x50, 0x100, 0);
    ScanlineEffect_InitWave(0, 0xA0, 4, 4, 1, 6, 0);
}

void Task_IntroFadeIn0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    sub_816F2A8(data[1], data[2], data[3], 0);
    
    switch (data[0])
    {
        case 0:
            if (--data[6] != 0)
                break;
            data[0]++;
        case 1:
            data[6] += 4;
            gTasks[taskId].data[1] = 0x158 - Sin(data[6], 0x100);
            gTasks[taskId].data[2] = 0x54 - Cos(data[6], 0x40);
            if (data[6] == 0x40)
            {
                data[6] = 0x19;
                data[7] = 1;
                data[0]++;
                sub_816E6D4(0);
            }
            break;
        case 2:
            if (--data[6] == 0)
            {
                gTasks[taskId].data[1] += 0x100;
                gTasks[taskId].data[2] -= 0x102;
                data[6] = 8;
                data[0]++;
                sub_816E6D4(0);
                sub_816E74C();
            }
            break;
        case 3:
            if (--data[6] == 0)
            {
                gTasks[taskId].data[1] -= 0x100;
                gTasks[taskId].data[2] += 0x102;
                data[6] = 8;
                data[0]++;
            }
            break;
        case 4:
            if (--data[6] == 0)
            {
                gTasks[taskId].data[2] -= 0xFC;
                data[6] = 8;
                data[0]++;
            }
            break;
        case 5:
            if (--data[6] == 0)
            {
                gTasks[taskId].data[2] += 0xFC;
                if (data[7] != 0)
                {
                    data[6] = 12;
                    data[7]--;
                    data[0] = 2;
                }
                else
                {
                    data[6] = 1;
                    data[0]++;
                    PlayCryInternal(SPECIES_KYOGRE, 0, 120, 10, 0);
                }
            }
            break;
        case 6:
            if (--data[6] == 0)
            {
                data[6] = 4;
                data[7] = 0x1EA;
                data[0]++;
            }
            break;
        case 7:
            if (--data[6] == 0)
            {
                data[6] = 4;
                CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[47], sizeof(u16));
                data[7] -= 2;
                if (data[7] == 0x1E0)
                    data[0]++;
            }
            break;
        case 8:
            if (--data[6] == 0)
            {
                data[6] = 4;
                data[7] = 0x1E2;
                data[0]++;
            }
            break;
        case 9:
            if (--data[6] == 0)
            {
                data[6] = 4;
                CpuCopy16(&gIntro3BgPal[data[7]], &gPlttBufferFaded[47], sizeof(u16));
                data[7] += 2;
                if (data[7] == 0x1EE)
                {
                    data[6] = 0x10;
                    data[0]++;
                }
            }
            break;
        case 10:
            if (--data[6] == 0)
            {
                data[6] = 0;
                data[0]++;
                sub_816E6D4(taskId);
            }
            break;
        case 11:
            data[6] += 4;
            data[3] -= 8;
            gTasks[taskId].data[1] = Sin(data[6], 0x3C) + 0x58;
            if (data[6] == 0x40)
            {
                BeginNormalPaletteFade(0xFFFFFFFE, 3, 0, 16, 0x7FFF);
                data[0]++;
            }
            break;
        case 12:
            data[6] += 4;
            data[3] -= 8;
            gTasks[taskId].data[1] = Sin(data[6], 0x14) + 0x80;
            if (data[6] == 0x80)
                data[0]++;
            break;
        case 13:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].func = Task_IntroFadeIn1;
                gScanlineEffect.state = 3;
            }
            break;
    }
}

void sub_816E6D4(u8 a0)
{
    int i;
    u8 spriteId;
    
    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(gUnknown_085E4D14, gUnknown_085E4CA8[i][0], gUnknown_085E4CA8[i][1], i);
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].data[5] = a0;
        gSprites[spriteId].data[6] = gUnknown_085E4CA8[i][2];
        gSprites[spriteId].data[7] = 0x40;
    }
}

void sub_816E74C(void)
{
    int i;
    u8 spriteId;
    
    for (i = 0; i < 6; i++)
    {
        spriteId = CreateSprite(gUnknown_085E4D14, gUnknown_085E4CA8[i + 6][0], gUnknown_085E4CA8[i + 6][1], i);
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].data[6] = gUnknown_085E4CA8[i][2];
        gSprites[spriteId].data[7] = 0x40;
    }
}

void sub_816E7B4(struct Sprite *sprite)
{
    switch(sprite->data[0])
    {
        case 0:
            if (sprite->data[6] == 0)
            {
                sprite->data[1] = (sprite->data[1] + 11) & 0xFF;
                sprite->pos2.x = Sin(sprite->data[1], 4);
                sprite->data[2] += 0x30;
                sprite->pos2.y = -(sprite->data[2] >> 8);
                if (sprite->animEnded)
                    DestroySprite(sprite);
            }
            else if (--sprite->data[6] == 0)
            {
                StartSpriteAnim(sprite, 0);
                sprite->invisible = FALSE;
            }
            if (gTasks[sprite->data[5]].data[0] > 11)
                sprite->data[0]++;
            break;
        case 1:
            if (sprite->pos1.x < 120)
                sprite->pos1.x -= 3;
            else
                sprite->pos1.x += 3;
            
            if (sprite->pos1.y < 80)
                sprite->pos1.y -= 3;
            else
                sprite->pos1.y += 3;
            if ((u16)(sprite->pos1.y - 20) > 140)
                DestroySprite(sprite);
            break;
    }
}

void Task_IntroFadeIn1(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0
                               | BLDCNT_TGT1_BG1
                               | BLDCNT_TGT1_BG2
                               | BLDCNT_EFFECT_LIGHTEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(31, 31));
    SetGpuReg(REG_OFFSET_BLDY, 31);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(26)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_BG0HOFS, 80);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, -80);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    LZDecompressVram(gIntro3CloudsGfx, (void *)VRAM);
    LZDecompressVram(gIntro3CloudsGfx, (void *)(VRAM + 0x4000));
    LZDecompressVram(gIntro3Clouds3Tilemap, (void *)(VRAM + 0xE000));
    gTasks[taskId].func = Task_IntroFadeIn2;
}

void Task_IntroFadeIn2(u8 taskId)
{
    LZDecompressVram(gIntro3Clouds1Tilemap, (void *)(VRAM + 0xC000));
    LZDecompressVram(gIntro3Clouds2Tilemap, (void *)(VRAM + 0xD000));
    gTasks[taskId].func = Task_IntroFadeIn3;
}

void Task_IntroFadeIn3(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].func = Task_IntroFadeIn4;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[6] = 16;
}

void Task_IntroFadeIn4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    SetGpuReg(REG_OFFSET_BG0HOFS, (data[6] >> 8));
    SetGpuReg(REG_OFFSET_BG1HOFS, -(data[6] >> 8));
    
    switch (data[0])
    {
        case 0:
            if (--data[6] == 0)
            {
                BeginNormalPaletteFade(0xFFFFFFFE, 0, 16, 0, 0xFFFF);
                data[6] = 0x5000;
                data[0]++;
            }
            break;
        case 1:
            if (data[6] == 0x2800)
                BeginNormalPaletteFade(0x0000FFFE, 3, 0, 16, 0x2949);
            
            if (data[6] != 0)
                data[6] -= 0x80;
            else if (!gPaletteFade.active)
                gTasks[taskId].func = Task_IntroFadeIn5;
            break;
    }
}

void Task_IntroFadeIn5(u8 taskId)
{
    LZDecompressVram(gIntro3RayquazaTilemap, (void *)(VRAM + 0xE000));
    LZDecompressVram(gIntro3Clouds4Tilemap, (void *)(VRAM + 0xC000));
    LZDecompressVram(gIntro3RayquazaGfx, (void *)(VRAM + 0x4000));
    LZDecompressVram(gIntro3Clouds2Gfx, (void *)VRAM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].func = Task_IntroFadeIn6;
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[6] = 1;
    gTasks[taskId].data[7] = 0;
    LoadCompressedObjectPicUsingHeap(gUnknown_085E4BF4);
    LoadSpritePalettes(gUnknown_085E4C04);
}

void Task_IntroFadeIn6(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 spriteId;
    
    switch (data[0])
    {
        case 0:
            if (--data[6] == 0)
            {
                CreateSprite(gUnknown_085E4C4C, 200, 48, 0);
                spriteId = CreateSprite(gUnknown_085E4C4C, 200, 80, 1);
                StartSpriteAnim(&gSprites[spriteId], 1);
                spriteId = CreateSprite(gUnknown_085E4C4C, 200, 112, 2);
                StartSpriteAnim(&gSprites[spriteId], 2);
                data[0]++;
                data[6] = 72;
            }
            break;
        case 1:
            if (--data[6] == 0)
            {
                CreateSprite(gUnknown_085E4C4C, 40, 48, 0);
                spriteId = CreateSprite(gUnknown_085E4C4C, 40, 80, 1);
                StartSpriteAnim(&gSprites[spriteId], 1);
                spriteId = CreateSprite(gUnknown_085E4C4C, 40, 112, 2);
                StartSpriteAnim(&gSprites[spriteId], 2);
                data[0]++;
                data[6] = 48;
            }
            break;
        case 2:
            if (--data[6] == 0)
                gTasks[taskId].func = Task_IntroFadeIn7;
            break;
    }
}

void sub_816EC6C(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->invisible = TRUE;
    
    switch(sprite->data[0])
    {
        case 0:
            sprite->data[1] = 0x1C2;
            sprite->data[0]++;
        case 1:
            CpuCopy16(&gIntro3BgPal[sprite->data[1]], &gPlttBufferFaded[93], 2);
            sprite->data[1] += 2;
            if (sprite->data[1] != 0x1CE)
                break;
            sprite->data[1] = 0x1CC;
            sprite->data[2] = 4;
            sprite->data[0]++;
        case 2:
            if (--sprite->data[2] == 0)
            {
                sprite->data[2] = 4;
                CpuCopy16(&gIntro3BgPal[sprite->data[1]], &gPlttBufferFaded[93], 2);
                sprite->data[1] -= 2;
                if (sprite->data[1] == 0x1C0)
                    DestroySprite(sprite);
            }
            break;
    }
}

void Task_IntroFadeIn7(u8 taskId)
{
    u8 newTaskId;
    
    LoadCompressedObjectPic(gUnknown_085E5048);
    LoadSpritePalettes(gUnknown_085E5058);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].func = Task_IntroFadeIn8;
    BeginNormalPaletteFade(0x0000FFDE, 0, 16, 0, 0x2949);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0xA8;
    gTasks[taskId].data[2] = -0x10;
    gTasks[taskId].data[3] = -0x88;
    gTasks[taskId].data[4] = -0x10;
    newTaskId = CreateTask(sub_816EEA8, 0);
    gTasks[newTaskId].data[4] = taskId;
}

void Task_IntroFadeIn8(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (data[7] % 2 == 0)
        data[6] ^= 2;
    
    data[7]++;
    
    switch(data[0])
    {
        case 0:
            if ((data[7] & 1) != 0)
            {
                data[1] -= 2;
                data[2]++;
                data[3] += 2;
                data[4]++;
            }
            if (data[1] == 0x68)
            {
                data[0]++;
                data[5] = 1;
            }
            break;
        case 1:
            data[0]++;
            data[5] = 4;
            break;
        case 2:
            data[1] += 4;
            data[2] -= 2;
            data[3] -= 4;
            data[4] -= 2;
            if (!gPaletteFade.active)
            {
                data[5] = 0x8C;
                data[0]++;
            }
            break;
        case 3:
            if (--data[5] == 0)
                gTasks[taskId].func = Task_IntroFadeIn9;
            break;
    }
}

void Task_IntroFadeIn9(u8 taskId)
{
    DestroyTask(taskId);
    SetMainCallback2(MainCB2_EndIntro);
}

void sub_816EEA8(u8 taskId)
{
    u8 spriteId;
    s16 *data = gTasks[taskId].data;
    
    data[2]++;
    
    switch(data[0])
    {
        case 0:
            if ((data[2] & 1) != 0)
            {
                CpuCopy16(&gIntro3BgPal[0x1A2 + data[1] * 2], &gPlttBufferFaded[94], 2);
                data[1]++;
            }
            if (data[1] == 6)
            {
                data[0]++;
                data[1] = 0;
                data[3] = 10;
            }
            break;
        case 1:
            if (data[3] == 0)
            {
                if ((data[2] & 1) != 0)
                {
                    CpuCopy16(&gIntro3BgPal[0x1A2 + data[1] * 2], &gPlttBufferFaded[88], 2);
                    data[1]++;
                }
                if (data[1] == 6)
                {
                    data[0]++;
                    data[3] = 10;
                }
            }
            else
            {
                data[3]--;
            }
            break;
        case 2:
            if (data[3] == 0)
            {
                if ((data[2] & 1) != 0)
                {
                    CpuCopy16(&gIntro3BgPal[0x182 + data[1] * 2], &gPlttBufferFaded[92], 2);
                    data[1]++;
                }
                if (data[1] == 6)
                {
                    spriteId = CreateSprite(gUnknown_085E5030, 120, 88, 15);
                    PlaySE(SE_OP_BASYU);
                    gSprites[spriteId].invisible = TRUE;
                    gSprites[spriteId].data[3] = data[4];
                    data[0]++;
                    data[3] = 16;
                }
            }
            else
            {
                data[3]--;
            }
            break;
        case 3:
            if ((data[2] & 1) != 0)
            {
                if (--data[3] != 0)
                {
                    BlendPalette(0x50, 16, data[3], 0x2949);
                    CpuCopy16(&gIntro3BgPal[0x1AC], &gPlttBufferFaded[94], 2);
                    CpuCopy16(&gIntro3BgPal[0x1AC], &gPlttBufferFaded[88], 2);
                    CpuCopy16(&gIntro3BgPal[0x18C], &gPlttBufferFaded[92], 2);
                }
                else
                {
                    data[0]++;
                    data[3] = 53;
                }
            }
            break;
        case 4:
            if (--data[3] == 0)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0x7FFF);
                data[0]++;
            }
            break;
        case 5:
            if (!gPaletteFade.active)
                DestroyTask(taskId);
            break;
    }
}

void intro_reset_and_hide_bgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

void Task_IntroWaterDrops_1(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND
                                   | BLDCNT_TGT2_BG0
                                   | BLDCNT_TGT2_BG1
                                   | BLDCNT_TGT2_BG2
                                   | BLDCNT_TGT2_BG3
                                   | BLDCNT_TGT2_OBJ
                                   | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, gUnknown_0853FF70[31]);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gTasks[taskId].data[1] = 0x40;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (gTasks[taskId].data[1] != 0)
        {
            u8 tmp;
            
            gTasks[taskId].data[1]--;
            tmp = gTasks[taskId].data[1] / 2;
            SetGpuReg(REG_OFFSET_BLDALPHA, gUnknown_0853FF70[tmp]);
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDALPHA, gUnknown_0853FF70[0]);
            gTasks[taskId].data[1] = 0x10;
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        DestroyTask(taskId);
        break;
    }
}

void Task_IntroWaterDrops_2(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
    default:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND
                                   | BLDCNT_TGT2_BG0
                                   | BLDCNT_TGT2_BG1
                                   | BLDCNT_TGT2_BG2
                                   | BLDCNT_TGT2_BG3
                                   | BLDCNT_TGT2_OBJ
                                   | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, gUnknown_0853FF70[0]);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (gTasks[taskId].data[1] < 62)
        {
            u8 tmp;
            
            gTasks[taskId].data[1]++;
            tmp = gTasks[taskId].data[1] / 2;
            SetGpuReg(REG_OFFSET_BLDALPHA, gUnknown_0853FF70[tmp]);
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDALPHA, gUnknown_0853FF70[31]);
            gTasks[taskId].data[1] = 0x10;
            gTasks[taskId].data[0]++;
        }
        break;
    case 2:
        if (gTasks[taskId].data[1] != 0)
        {
            gTasks[taskId].data[1]--;
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            DestroyTask(taskId);
        }
        break;
    }
}

void sub_816F2A8(u16 scrX, u16 scrY, u16 zoom, u16 alpha)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    src.texX = 0x8000;
    src.texY = 0x8000;
    src.scrX = scrX;
    src.scrY = scrY;
    src.sx = zoom;
    src.sy = zoom;
    src.alpha = alpha;
    BgAffineSet(&src, &dest, 1);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, dest.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, dest.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, dest.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, dest.dy >> 16);
}

void sub_816F318(struct Sprite *sprite)
{
    u8 r0;

    if (sprite->data[2] >= 192)
    {
        if (sprite->data[3] != 0)
        {
            sprite->data[3]--;
        }
        else
        {
            sprite->invisible = FALSE;
            SetOamMatrix(sprite->data[1], sprite->data[2], 0, 0, sprite->data[2]);
            sprite->data[2] = (sprite->data[2] * 95) / 100;
            r0 = (sprite->data[2] - 192) / 128 + 9;
            if (r0 > 15)
                r0 = 15;
            sprite->oam.paletteNum = r0;
        }
    }
    else
    {
        DestroySprite(sprite);
    }
}

void sub_816F3A4(struct Sprite *sprite)
{
    if (gSprites[sprite->data[7]].data[7] != 0)
    {
        sprite->invisible = TRUE;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        StartSpriteAnim(sprite, 3);
        sprite->data[2] = 1024;
        sprite->data[3] = 8 * (sprite->data[1] & 3);
        sprite->callback = sub_816F318;
        sprite->oam.shape = 1;
        sprite->oam.size = 3;
        CalcCenterToCornerVec(sprite, 1, 3, 2);
    }
    else
    {
        sprite->pos2.x = gSprites[sprite->data[7]].pos2.x;
        sprite->pos2.y = gSprites[sprite->data[7]].pos2.y;
        sprite->pos1.x = gSprites[sprite->data[7]].pos1.x;
        sprite->pos1.y = gSprites[sprite->data[7]].pos1.y;
    }
}

void sub_816F454(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
        sprite->callback = sub_816F46C;
}

void sub_816F46C(struct Sprite *sprite)
{
    if (sprite->pos1.x <= 116)
    {
        sprite->pos1.y += sprite->pos2.y;
        sprite->pos2.y = 0;
        sprite->pos1.x += 4;
        sprite->pos2.x = -4;
        sprite->data[4] = 128;
        sprite->callback = sub_816F5B4;
    }
    else
    {
        u16 data2;
        u16 data3;
        u16 data4;
        s16 sin1;
        s16 sin2;
        s16 sin3;
        s16 sin4;
        s16 var1;
        s16 var2;
        s16 var3;
        s16 var4;
        s16 temp;

        data4 = sprite->data[4];
        sin1 = gSineTable[(u8)data4];
        sin2 = gSineTable[(u8)(data4 + 64)];
        sprite->data[4] += 2;
        sprite->pos2.y = sin1 / 32;
        sprite->pos1.x--;
        if (sprite->pos1.x & 1)
            sprite->pos1.y++;
        temp = -sin2 / 16;
        data2 = sprite->data[2];
        data3 = sprite->data[3];
        sin3 = gSineTable[(u8)(temp - 16)];
        sin4 = gSineTable[(u8)(temp + 48)];
        var1 = sin4 * data2 / 256;
        var2 = -sin3 * data3 / 256;
        var3 = sin3 * data2 / 256;
        var4 = sin4 * data3 / 256;
        SetOamMatrix(sprite->data[1], data2, 0, 0, data3);
        SetOamMatrix(sprite->data[1] + 1, var1, var3, var2, var4);
        SetOamMatrix(sprite->data[1] + 2, var1, var3, var2 * 2, var4 * 2);
    }
}

void sub_816F5B4(struct Sprite *sprite)
{
    SetOamMatrix(sprite->data[1], sprite->data[6] + 64, 0, 0, sprite->data[6] + 64);
    SetOamMatrix(sprite->data[1] + 1, sprite->data[6] + 64, 0, 0, sprite->data[6] + 64);
    SetOamMatrix(sprite->data[1] + 2, sprite->data[6] + 64, 0, 0, sprite->data[6] + 64);
    if (sprite->data[4] != 64)
    {
        u16 data4;

        sprite->data[4] -= 8;
        data4 = sprite->data[4];
        sprite->pos2.x = gSineTable[(u8)(data4 + 64)] / 64;
        sprite->pos2.y = gSineTable[(u8)data4] / 64;
    }
    else
    {
        sprite->data[4] = 0;
        sprite->callback = sub_816F660;
    }
}

void sub_816F660(struct Sprite *sprite)
{
    if (sprite->data[0] != 2)
    {
        s16 r2;

        sprite->data[4] += 8;
        r2 = gSineTable[(u8)sprite->data[4]] / 16 + 64;
        sprite->pos2.x = gSineTable[(u8)(r2 + 64)] / 64;
        sprite->pos2.y = gSineTable[(u8)r2] / 64;
    }
    else
    {
        sprite->callback = SpriteCB_WaterDropFall;
    }
}

void SpriteCB_WaterDropFall(struct Sprite *sprite)
{
    if (sprite->pos1.y < sprite->data[5])
    {
        sprite->pos1.y += 4;
    }
    else
    {
        sprite->data[7] = 1;
        sprite->invisible = TRUE;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        StartSpriteAnim(sprite, 3);
        sprite->data[2] = 1024;
        sprite->data[3] = 8 * (sprite->data[1] & 3);
        sprite->callback = sub_816F318;
        sprite->oam.shape = 1;
        sprite->oam.size = 3;
        CalcCenterToCornerVec(sprite, 1, 3, 2);
    }
}

//Duplicate function
void SpriteCB_WaterDropFall_2(struct Sprite *sprite)
{
    if (sprite->pos1.y < sprite->data[5])
    {
        sprite->pos1.y += 4;
    }
    else
    {
        sprite->data[7] = 1;
        sprite->invisible = TRUE;
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos1.y += sprite->pos2.y;
        StartSpriteAnim(sprite, 3);
        sprite->data[2] = 1024;
        sprite->data[3] = 8 * (sprite->data[1] & 3);
        sprite->callback = sub_816F318;
        sprite->oam.shape = 1;
        sprite->oam.size = 3;
        CalcCenterToCornerVec(sprite, 1, 3, 2);
    }
}

u8 CreateWaterDrop(s16 x, s16 y, u16 c, u16 d, u16 e, u8 fallImmediately)
{
    u8 spriteId;
    u8 oldSpriteId;

    spriteId = CreateSprite(&gUnknown_085E4D64, x, y, 1);
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].data[7] = 0;
    gSprites[spriteId].data[1] = d;
    gSprites[spriteId].data[2] = c;
    gSprites[spriteId].data[3] = c;
    gSprites[spriteId].data[5] = e;
    gSprites[spriteId].data[6] = c;
    gSprites[spriteId].oam.affineMode = 3;
    gSprites[spriteId].oam.matrixNum = d;
    CalcCenterToCornerVec(&gSprites[spriteId], 0, 2, 2);
    StartSpriteAnim(&gSprites[spriteId], 2);
    if (!fallImmediately)
        gSprites[spriteId].callback = sub_816F454;
    else
        gSprites[spriteId].callback = SpriteCB_WaterDropFall_2;
    oldSpriteId = spriteId;

    spriteId = CreateSprite(&gUnknown_085E4D64, x, y, 1);
    gSprites[spriteId].data[7] = oldSpriteId;
    gSprites[spriteId].data[1] = d + 1;
    gSprites[spriteId].oam.affineMode = 3;
    gSprites[spriteId].oam.matrixNum = d + 1;
    CalcCenterToCornerVec(&gSprites[spriteId], 0, 2, 2);
    gSprites[spriteId].callback = sub_816F3A4;

    spriteId = CreateSprite(&gUnknown_085E4D64, x, y, 1);
    gSprites[spriteId].data[7] = oldSpriteId;
    gSprites[spriteId].data[1] = d + 2;
    StartSpriteAnim(&gSprites[spriteId], 1);
    gSprites[spriteId].oam.affineMode = 3;
    gSprites[spriteId].oam.matrixNum = d + 2;
    CalcCenterToCornerVec(&gSprites[spriteId], 0, 2, 2);
    gSprites[spriteId].callback = sub_816F3A4;

    SetOamMatrix(d, c + 32, 0, 0, c + 32);
    SetOamMatrix(d + 1, c + 32, 0, 0, c + 32);
    SetOamMatrix(d + 2, c + 32, 0, 0, 2 * (c + 32));

    return oldSpriteId;
}

void sub_816F9D4(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        StartSpriteAnimIfDifferent(sprite, 0);
        sprite->pos1.x--;
        break;
    case 1:
        StartSpriteAnimIfDifferent(sprite, 0);
        if (gIntroFrameCounter & 7)
            return;
        sprite->pos1.x++;
        break;
    case 2:
        if (sprite->pos1.x <= 120 || gIntroFrameCounter & 7)
            sprite->pos1.x++;
        break;
    case 3:
        break;
    case 4:
        if (sprite->pos1.x > -32)
            sprite->pos1.x -= 2;
        break;
    }
    if (gIntroFrameCounter & 7)
        return;
    if (sprite->pos2.y != 0)
    {
        sprite->pos2.y = 0;
    }
    else
    {
        switch (Random() & 3)
        {
        case 0:
            sprite->pos2.y = -1;
            break;
        case 1:
            sprite->pos2.y = 1;
            break;
        case 2:
        case 3:
            sprite->pos2.y = 0;
            break;
        }
    }
}

void sub_816FAB0(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        break;
    case 1:
        if (sprite->pos2.x + sprite->pos1.x < 304)
            sprite->pos2.x += 8;
        else
            sprite->data[0] = 2;
        break;
    case 2:
        if (sprite->pos2.x + sprite->pos1.x > 120)
            sprite->pos2.x -= 1;
        else
            sprite->data[0] = 3;
        break;
    case 3:
        if (sprite->pos2.x > 0)
            sprite->pos2.x -= 2;
        break;
    }
    sprite->pos2.y = Sin((u8)sprite->data[1], 8) - gUnknown_0203BCCC;
    sprite->data[1] += 4;
}

void sub_816FB38(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
        case 0:
            if (sprite->data[1] != 0)
            {
                sprite->data[1]--;
            }
            else
            {
                sprite->invisible = FALSE;
                StartSpriteAffineAnim(sprite, 1);
                sprite->data[0]++;
            }
            break;
        case 1:
            if (gIntroFrameCounter == 0x90)
            {
                sprite->data[0]++;
                sprite->data[1] = 9;
                sprite->data[3] = 2;
            }
            break;
        case 2:
            if (sprite->data[3] == 0)
            {
                sprite->data[3] = 2;
                if (sprite->data[1] != 0)
                {
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1]], &gPlttBufferFaded[0x11F], 2);
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x10], &gPlttBufferFaded[0x114], 2);
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x20], &gPlttBufferFaded[0x11A], 2);
                    sprite->data[1]--;
                }
                else
                {
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1]], &gPlttBufferFaded[0x11F], 2);
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x10], &gPlttBufferFaded[0x114], 2);
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x20], &gPlttBufferFaded[0x11A], 2);
                    sprite->data[0]++;
                }
            }
            else
            {
                sprite->data[3]--;
            }
            break;
        case 3:
            if (sprite->data[3] != 0)
            {
                sprite->data[3]--;
            }
            else
            {
                sprite->data[3] = 2;
                if (sprite->data[1] < 10)
                {
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1]], &gPlttBufferFaded[0x11F], 2);
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x10], &gPlttBufferFaded[0x114], 2);
                    CpuCopy16(&gIntro1GameFreakTextFadePal[sprite->data[1] + 0x20], &gPlttBufferFaded[0x11A], 2);
                    sprite->data[1]++;
                }
                else
                {
                    sprite->data[0]++;
                }
            }
            break;
        case 4:
            if (gIntroFrameCounter == 0x110)
            {
                StartSpriteAffineAnim(sprite, 2);
                sprite->oam.objMode = 1;
                sprite->data[0]++;
            }
            break;
        case 5:
            sprite->data[3] += gUnknown_085E4F48[sprite->data[2]];
            sprite->pos2.x = (sprite->data[3] & 0xFF00) >> 8;
            if (sprite->data[2] < 4)
            {
                s16 temp = sprite->pos2.x;
                sprite->pos2.x = -temp;
            }
            if (sprite->affineAnimEnded)
                DestroySprite(sprite);
            break;
    }
}

void sub_816FD44(struct Sprite *sprite)
{
    switch(sprite->data[0])
    {
        case 0:
            if (gIntroFrameCounter == 0x80)
            {
                sprite->invisible = FALSE;
                sprite->data[0]++;
            }
            break;
        case 1:
            if (gIntroFrameCounter == 0x110)
            {
                StartSpriteAffineAnim(sprite, 3);
                sprite->data[0]++;
            }
            break;
        case 2:
            if (sprite->affineAnimEnded)
                DestroySprite(sprite);
            break;
    }
}

u8 sub_816FDB8(s16 a0, s16 a1, s16 a2)
{
    u16 i;
    u8 spriteId;
    
    for (i = 0; i < 9; i++)
    {
        spriteId = CreateSprite(gUnknown_085E4F5C, gUnknown_085E4E94[i][1] + a0, a1 - 4, 0);
        gSprites[spriteId].data[0] = 0;
        gSprites[spriteId].data[1] = gUnknown_085E4FA4[i];
        gSprites[spriteId].data[2] = i;
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].oam.matrixNum = i + 12;
        StartSpriteAnim(&gSprites[spriteId], gUnknown_085E4E94[i][0]);
        StartSpriteAffineAnim(&gSprites[spriteId], 0);
    }
    spriteId = CreateSprite(gUnknown_085E4F8C, 120, a1 - 6, 0);
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].oam.matrixNum = i + 12;
    StartSpriteAffineAnim(&gSprites[spriteId], 1);
    return spriteId;
}

/*void sub_816FEDC(struct Sprite *sprite)
{
    sprite->data[7]++;
    
    if (sprite->data[0] != 0)
    {
        s16 sin1;
        s16 sin2;
        s16 var1;
        s16 var2;
        s16 var3;

        sin1 = gSineTable[(u8)sprite->data[2]];
        sin2 = gSineTable[(u8)(sprite->data[2] + 64)];
        var1 = sin2 * sprite->data[1] / 256;
        var2 = -sin1 * sprite->data[1] / 256;
        var3 = sin1 * sprite->data[1] / 256;
        SetOamMatrix(1, var1, var3, var2, var1);
    }
    
    switch (sprite->data[0])
    {
    case 0:
    default:
        sprite->oam.affineMode = 3;
        sprite->oam.matrixNum = 1;
        CalcCenterToCornerVec(sprite, 1, 3, 3);
        sprite->invisible = FALSE;
        sprite->data[0] = 1;
        sprite->data[1] = 0x80;
        sprite->data[2] = 0;
        sprite->data[3] = 0;
        break;
    case 1:
        sprite->pos2.x = -Sin((u8)sprite->data[3], 140);
        sprite->pos2.y = -Sin((u8)sprite->data[3], 120);
        sprite->data[1] += 7;
        sprite->data[3] += 3;
        if (sprite->pos1.x + sprite->pos2.x <= -16)
        {
            sprite->oam.priority = 3;
            sprite->data[0]++;
            sprite->pos1.x = 20;
            sprite->pos1.y = 40;
            sprite->data[1] = 0x200;
            sprite->data[2] = 0;
            sprite->data[3] = 0x10;
        }
        break;
    case 2:
        sprite->pos2.x = Sin((u8)sprite->data[3], 34);
        sprite->pos2.y = -Cos((u8)sprite->data[3], 60);
        sprite->data[1] += 2;
        if (sprite->data[7] % 5 == 0)
            sprite->data[3]++;
        break;
    }
}*/
