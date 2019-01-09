#include "global.h"
#include "scanline_effect.h"
#include "palette.h"
#include "task.h"
#include "main.h"
#include "window.h"
#include "alloc.h"
#include "link.h"
#include "bg.h"
#include "sound.h"
#include "constants/songs.h"
#include "overworld.h"
#include "menu.h"
#include "text.h"

extern const u8 gText_WaitingTrainerFinishReading[];
extern const u32 gUnknown_08DD2AE0[];
extern const u32 gUnknown_08DD21B0[];
extern const u32 gUnknown_08DD2D30[];
extern const u32 gUnknown_08DD2010[];
extern const u32 gUnknown_08DD2B78[];
extern const u32 gUnknown_08DD228C[];
extern const u32 gUnknown_08DD2E5C[];
extern const u32 gUnknown_0856F5CC[];
extern const u32 gUnknown_0856F814[];
extern const u32 gEmeraldTrainerCard_Gfx[];
extern const u32 gFireRedTrainerCard_Gfx[];
extern const u32 gUnknown_0856F018[];
extern const u32 gUnknown_08DD1F78[];

/*static*/ void sub_80C2690(void);
/*static*/ void sub_80C26D4(void);
/*static*/ void sub_80C48C8(void);
/*static*/ void sub_80C2710(void);
/*static*/ void sub_80C2728(u8 task);
/*static*/ bool8 sub_80C3438(void);
/*static*/ void sub_80C438C(u8);
/*static*/ void sub_80C4FF0(void);
/*static*/ void sub_80C4550(u8*); 
/*static*/ void sub_80C45C0(u8*);
/*static*/ void sub_80C4630(void);
/*static*/ void sub_80C3880(void);
/*static*/ void sub_80C4918(void);
/*static*/ bool8 sub_80C4940(void);
/*static*/ bool8 sub_80C2AD8(void);
/*static*/ void sub_80C2C80(void);

extern struct UnknownStruct{
    u8 var_0;
    u8 var_1;
    u8 var_2;
    u8 filler3[2];
    u8 var_5;
    u8 filler6[3];
    u8 var_9;
    u8 fillerA[0x51F];
    u8 var_529;
    u8 var_52A;
    u8 var_52B;
    u16 var_52C;
    void (*callback2)(void);
    u8 filler531[0x64];
    u8 var_598[0x4B0];
    u8 var_A48[0x4B0];
    u8 var_EF8[0x4B0];
    u8 var_13A8[0x400];
    u8 var_17A8[0x200];
    u8 var_19A8[0x200];
}* gUnknown_02039CE8;

void sub_80C2690(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    sub_80C48C8();
    if(gUnknown_02039CE8->var_9)
        DmaCopy16(3, &gScanlineEffectRegBuffers[0], &gScanlineEffectRegBuffers[1], 0x140);
}

void sub_80C26D4(void)
{
    u16 backup;
    u16 bgVOffset;
    
    backup = REG_IME;
    REG_IME = 0;
    bgVOffset = gScanlineEffectRegBuffers[1][REG_VCOUNT & 0xFF];
    REG_BG0VOFS = bgVOffset;
    REG_IME = backup;
}

void sub_80C2710(void)
{
    RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	UpdatePaletteFade();
}

void sub_80C2728(u8 taskId)
{
    SetMainCallback2(gUnknown_02039CE8->callback2);
    FreeAllWindowBuffers();
    Free(gUnknown_02039CE8);
    gUnknown_02039CE8 = NULL;
    DestroyTask(taskId);
} 

void sub_80C2760(u8 taskId)
{
    switch(gUnknown_02039CE8->var_0)
    {
    case 0:    
        if(!IsDma3ManagerBusyWithBgCopy())
        {
            FillWindowPixelBuffer(1, 0);
            gUnknown_02039CE8->var_0++;
        }
        break;
    case 1:
        if(sub_80C3438())
            gUnknown_02039CE8->var_0++;
        break;
    case 2:
        sub_80C438C(1);
        gUnknown_02039CE8->var_0++;
        break;
    case 3:
        FillWindowPixelBuffer(2, 0);
        sub_80C4FF0();
        sub_80C438C(2);
        gUnknown_02039CE8->var_0++;
        break;
    case 4:
        sub_80C4550(gUnknown_02039CE8->var_EF8);
        gUnknown_02039CE8->var_0++;
        break;
    case 5:
        sub_80C45C0(gUnknown_02039CE8->var_598);
        gUnknown_02039CE8->var_0++;
        break;
    case 6:
        sub_80C4630();
        gUnknown_02039CE8->var_0++;
        break;
    case 7:
        if(gWirelessCommType == TRUE && gReceivedRemoteLinkPlayers == TRUE)
        {
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(230, 150);
        }
        BlendPalettes(-1, 16, gUnknown_02039CE8->var_52C);
        BeginNormalPaletteFade(- 1, 0, 16, 0, gUnknown_02039CE8->var_52C);
        SetVBlankCallback(sub_80C2690);
        gUnknown_02039CE8->var_0++;
        break;
    case 8:
        if(!UpdatePaletteFade() && !IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_RG_CARD3);
            gUnknown_02039CE8->var_0 = 10;
        }
        break;
    case 9:
        if(!IsSEPlaying())
            gUnknown_02039CE8->var_0++;
        break;
    case 10:
        if(!gReceivedRemoteLinkPlayers && gUnknown_02039CE8->var_529)
        {
            sub_80C3880();
            sub_80C438C(1);
            gUnknown_02039CE8->var_529 = 0;
        }    
        if(gMain.newKeys & A_BUTTON)
        {
            sub_80C4918();
            PlaySE(SE_RG_CARD1);
            gUnknown_02039CE8->var_0 = 12;
        }
        else if(gMain.newKeys & B_BUTTON)
        {
            if(gReceivedRemoteLinkPlayers && gUnknown_02039CE8->var_5 && InUnionRoom() == TRUE)
                gUnknown_02039CE8->var_0 = 15;
            else
            {
                BeginNormalPaletteFade(-1, 0, 0, 16, gUnknown_02039CE8->var_52C);
                gUnknown_02039CE8->var_0 = 14;
            }
        }    
        break;
    case 12:
        if(sub_80C4940() && sub_8087598() != TRUE)
        {
            PlaySE(SE_RG_CARD3);
            gUnknown_02039CE8->var_0 = 11;
        } 
        break; 
    case 11:
        if(gMain.newKeys & B_BUTTON) 
        {
            if(gReceivedRemoteLinkPlayers && gUnknown_02039CE8->var_5 && InUnionRoom() == TRUE)
                gUnknown_02039CE8->var_0 = 15;
            else if(gReceivedRemoteLinkPlayers)
            {
                BeginNormalPaletteFade(-1, 0, 0, 16, gUnknown_02039CE8->var_52C);
                gUnknown_02039CE8->var_0 = 14;
            }
            else
            {
                sub_80C4918();
                gUnknown_02039CE8->var_0 = 13;
                PlaySE(SE_RG_CARD1);  
            }
        }   
        else if(gMain.newKeys & A_BUTTON)
        {
           if(gReceivedRemoteLinkPlayers && gUnknown_02039CE8->var_5 && InUnionRoom() == TRUE)
               gUnknown_02039CE8->var_0 = 15;
           else
           {
               BeginNormalPaletteFade(-1, 0, 0, 16, gUnknown_02039CE8->var_52C);
               gUnknown_02039CE8->var_0 = 14;
           }
        }
        break; 
    case 15:
        sub_800AC34();
        NewMenuHelpers_DrawDialogueFrame(0, 1);
        AddTextPrinterParameterized(0, 1, gText_WaitingTrainerFinishReading, 0, 1, 255, 0);
        CopyWindowToVram(0, 3);
        gUnknown_02039CE8->var_0 = 16;
        break;
    case 16:
        if(!gReceivedRemoteLinkPlayers)
        {
            BeginNormalPaletteFade(-1, 0, 0, 16, gUnknown_02039CE8->var_52C);
            gUnknown_02039CE8->var_0 = 14;
        }
        break;
    case 14: 
        if(!UpdatePaletteFade())
            sub_80C2728(taskId);
        break;
    case 13:
        if(sub_80C4940() && sub_8087598() != TRUE)
        {
            gUnknown_02039CE8->var_0 = 10;
            PlaySE(SE_RG_CARD3);
        }
        break;
   }
}

bool8 sub_80C2AD8(void)
{
    switch(gUnknown_02039CE8->var_2)
    {
    case 0:
        if(gUnknown_02039CE8->var_52A)
            LZ77UnCompWram(gUnknown_08DD1F78, gUnknown_02039CE8->var_EF8);
        else
            LZ77UnCompWram(gUnknown_08DD2AE0, gUnknown_02039CE8->var_EF8);
        break;
    case 1:
        if(gUnknown_02039CE8->var_52A)
            LZ77UnCompWram(gUnknown_08DD21B0, gUnknown_02039CE8->var_A48);
        else
            LZ77UnCompWram(gUnknown_08DD2D30, gUnknown_02039CE8->var_A48);
        break;
    case 2:
        if(!gUnknown_02039CE8->var_5)
        {
            if(gUnknown_02039CE8->var_52A)
                LZ77UnCompWram(gUnknown_08DD2010, gUnknown_02039CE8->var_598);
            else
                LZ77UnCompWram(gUnknown_08DD2B78, gUnknown_02039CE8->var_598);
        }
        else
        {
            if(gUnknown_02039CE8->var_52A)
                LZ77UnCompWram(gUnknown_08DD228C, gUnknown_02039CE8->var_598);
            else
                LZ77UnCompWram(gUnknown_08DD2E5C, gUnknown_02039CE8->var_598);
        }
        break;
    case 3:
        if(gUnknown_02039CE8->var_52A)
            LZ77UnCompWram(gUnknown_0856F5CC, gUnknown_02039CE8->var_13A8);
        else
            LZ77UnCompWram(gUnknown_0856F814, gUnknown_02039CE8->var_13A8);
        break;
    case 4:
        if(gUnknown_02039CE8->var_52A)
            LZ77UnCompWram(gEmeraldTrainerCard_Gfx, gUnknown_02039CE8->var_19A8);
        else
            LZ77UnCompWram(gFireRedTrainerCard_Gfx, gUnknown_02039CE8->var_19A8);
        break;
    case 5:
        if(!gUnknown_02039CE8->var_52A)
            LZ77UnCompWram(gUnknown_0856F018, gUnknown_02039CE8->var_17A8);
        break;
    default:
        gUnknown_02039CE8->var_2 = 0;
        return 1;
    }
    gUnknown_02039CE8->var_2++;
    return 0;
}

