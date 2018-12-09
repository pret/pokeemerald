#include "global.h"
#include "main.h"
#include "pokeblock.h"
#include "alloc.h"
#include "palette.h"
#include "pokenav.h"
#include "scanline_effect.h"
#include "text.h"
#include "bg.h"
#include "window.h"
#include "text_window.h"

struct UsePokeblockSubStruct
{
    void (*field_0)(void);
    void (*callback)(void);
    struct Pokeblock *pokeblock;
    struct Pokemon *pokemon;
    u8 stringBuffer[0x40];
    u8 field_50;
    u8 field_51;
    u8 field_52;
    u8 field_53;
    u8 field_54;
    u8 field_55;
    u8 field_56;
    u8 field_57[5];
    u8 field_5c[5];
    u8 field_61[5];
    s16 field_66[5];
};

struct UsePokeblockStruct
{
    u8 field_0[0x7C58];
    u8 field_7C58[0x378];
    struct UsePokeblockSubStruct info;
};

extern u16 gKeyRepeatStartDelay;

// this file's functions
void sub_816636C(void (*func)(void));
void sub_8166380(void);
void sub_816631C(void);
void sub_81662C0(void);
void sub_8166564(void);
void sub_8166304(void);
void sub_81668F8(void);
void sub_8167420(void);
void sub_8167760(void);
u8 sub_81672E4(u8 arg0);
bool8 sub_8168328(void);
bool8 sub_8167930(void);
void sub_8167608(u8 arg0);
void sub_8167BA0(u16 arg0, u8 copyToVramMode);

extern const struct BgTemplate gUnknown_085DFCCC[4];
extern const struct WindowTemplate gUnknown_085DFCDC[];

// ram variables
EWRAM_DATA struct UsePokeblockSubStruct *gUnknown_0203BC90 = NULL;
EWRAM_DATA void (*gUnknown_0203BC94)(void) = NULL;
EWRAM_DATA struct Pokeblock *gUnknown_0203BC98 = NULL;
EWRAM_DATA u8 gPokeblockMonId = 0;
EWRAM_DATA s16 gPokeblockGain = 0;
EWRAM_DATA void *gUnknown_0203BCA0 = NULL;
EWRAM_DATA void *gUnknown_0203BCA4 = NULL;
EWRAM_DATA void *gUnknown_0203BCA8 = NULL;
EWRAM_DATA struct UsePokeblockStruct *gUnknown_0203BCAC = NULL;

// const rom data
// todo: make it static once the file is decompiled

// code
void ChooseMonToGivePokeblock(struct Pokeblock *pokeblock, void (*callback)(void))
{
    gUnknown_0203BCAC = AllocZeroed(0x806C);
    gUnknown_0203BC90 = &gUnknown_0203BCAC->info;
    gUnknown_0203BC90->pokeblock = pokeblock;
    gUnknown_0203BC90->callback = callback;
    sub_816636C(sub_8166380);
    SetMainCallback2(sub_816631C);
}

void CB2_ReturnAndChooseMonToGivePokeblock(void)
{
    gUnknown_0203BCAC = AllocZeroed(0x806C);
    gUnknown_0203BC90 = &gUnknown_0203BCAC->info;
    gUnknown_0203BC90->pokeblock = gUnknown_0203BC98;
    gUnknown_0203BC90->callback = gUnknown_0203BC94;
    gPokeblockMonId = sub_81672E4(gPokeblockMonId);
    gUnknown_0203BC90->field_56 = gPokeblockMonId < 4 ? 0 : 1;
    sub_816636C(sub_8166380);
    SetMainCallback2(sub_81662C0);
}

void sub_81662C0(void)
{
    gUnknown_0203BC90->field_0();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gUnknown_0203BC90->field_0 == sub_8166564)
    {
        gUnknown_0203BC90->field_50 = 0;
        SetMainCallback2(sub_8166304);
    }
}

void sub_8166304(void)
{
    sub_81668F8();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void sub_816631C(void)
{
    gUnknown_0203BC90->field_0();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
}

void sub_8166340(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_81D2108(gUnknown_0203BCAC->field_7C58);
    ScanlineEffect_InitHBlankDmaTransfer();
}

void sub_816636C(void (*func)(void))
{
    gUnknown_0203BC90->field_0 = func;
    gUnknown_0203BC90->field_50 = 0;
}

void sub_8166380(void)
{
    switch (gUnknown_0203BC90->field_50)
    {
        case 0:
            gUnknown_0203BCAC->field_0[0x7B10] = 0xFF;
            sub_81D1ED4(gUnknown_0203BCAC->field_7C58);
            gUnknown_0203BC90->field_50++;
            break;
        case 1:
            ResetSpriteData();
            FreeAllSpritePalettes();
            gUnknown_0203BC90->field_50++;
            break;
        case 2:
            SetVBlankCallback(NULL);
            CpuFill32(0, (void*)(VRAM), VRAM_SIZE);
            gUnknown_0203BC90->field_50++;
            break;
        case 3:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, gUnknown_085DFCCC, ARRAY_COUNT(gUnknown_085DFCCC));
            InitWindows(gUnknown_085DFCDC);
            DeactivateAllTextPrinters();
            LoadUserWindowBorderGfx(0, 0x97, 0xE0);
            gUnknown_0203BC90->field_50++;
            break;
        case 4:
            gUnknown_0203BC90->field_50++;
            break;
        case 5:
            if (!sub_8168328())
            {
                gUnknown_0203BC90->field_50++;
            }
            break;
        case 6:
            gKeyRepeatStartDelay = 20;
            sub_8167420();
            gUnknown_0203BC90->field_50++;
            break;
        case 7:
            if (!sub_8167930())
            {
                gUnknown_0203BC90->field_50++;
            }
            break;
        case 8:
            sub_8167608(0);
            sub_8167760();
            gUnknown_0203BC90->field_50++;
            break;
        case 9:
            if (!sub_81D312C(&gUnknown_0203BCAC->field_0[0x7B0E]))
            {
                gUnknown_0203BC90->field_50++;
            }
            break;
        case 10:
            gUnknown_0203BC90->field_50++;
            break;
        case 11:
            sub_81D2754(gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_0[0x7C6C]);
            sub_81D20AC(gUnknown_0203BCAC->field_7C58);
            gUnknown_0203BC90->field_50++;
            break;
        case 12:
            if (!sub_81D20BC(gUnknown_0203BCAC->field_7C58))
            {
                sub_81D1F84(gUnknown_0203BCAC->field_7C58, &gUnknown_0203BCAC->field_7C58[0x14], &gUnknown_0203BCAC->field_7C58[0x14]);
                gUnknown_0203BC90->field_50++;
            }
            break;
        case 13:
            sub_81D2230(gUnknown_0203BCAC->field_7C58);
            gUnknown_0203BC90->field_50++;
            break;
        case 14:
            PutWindowTilemap(0);
            PutWindowTilemap(1);
            sub_8167BA0(0, 1);
            gUnknown_0203BC90->field_50++;
            break;
        case 15:
            sub_816636C(sub_8166564);
            break;
    }
}
