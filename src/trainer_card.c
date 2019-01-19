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
#include "constants/flags.h"
#include "event_data.h"
#include "constants/game_stat.h"
#include "money.h"
#include "string_util.h"
#include "trainer_card.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "pokedex.h"
#include "graphics.h"
#include "pokemon_icon.h"

//external functions
extern u8 sub_80F8940(void);
extern bool16 sub_80C08E4(void);
extern u8 sub_80D30A0(u16);
extern void TintPalette_CustomTone(u16 *palette, u16 count, u16 rTone, u16 gTone, u16 bTone);
extern void TintPalette_SepiaTone(u16 *palette, u16 count);

//gfx
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

//strings
extern const u8 gText_WaitingTrainerFinishReading[];
extern const u8 gText_TrainerCardName[];
extern const u8 gText_TrainerCardIDNo[];
extern const u8 gText_TrainerCardMoney[];
extern const u8 gText_PokedollarVar1[];
extern const u8 gText_EmptyString6[];
extern const u8 gText_TrainerCardPokedex[];
extern const u8 gText_TrainerCardTime[];
extern const u8 gText_Colon2[];
extern const u8 gText_Var1sTrainerCard[];
extern const u8 gText_HallOfFameDebut[];
extern const u8 gText_WinsLosses[];
extern const u8 gText_PokemonTrades[];
extern const u8 gText_BerryCrush[];
extern const u8 gText_UnionTradesAndBattles[];
extern const u8 gText_Var1DarkGreyShadowLightGrey[];
extern const u8 gText_PokeblocksWithFriends[];
extern const u8 gText_WonContestsWFriends[];
extern const u8 gText_WSlashStraightSlash[];
extern const u8 gText_Var1DarkLightGreyBP[];
extern const u8 gText_BattleTower[];
extern const u8 gText_BattlePtsWon[];

//const rom data to be moved from data/trainer_card.s to this file
extern const struct BgTemplate gUnknown_0856FAB4[4];
extern const struct WindowTemplate gUnknown_0856FAC4[];
extern const u8 gUnknown_0856FB0C[];
extern const u8* gUnknown_0856FB40[];
extern const u8 gUnknown_0856FB48[];
extern const u8 gUnknown_0856FB4A[];
extern const u8 gUnknown_0856FB4C[];
extern const u8 gUnknown_0856FB55[];
extern const u8 gUnknown_0856FB57[];
extern const u8 gUnknown_0856FB0F[];
extern const u8* gUnknown_0856FB5C[];
extern const u8 gUnknown_0856FB68[6];
extern const u8 gUnknown_0856FB6E[6];
extern const u8 gUnknown_0856FB74[4];
extern const u8 gUnknown_0856F54C[];
extern const u8 gUnknown_0856F56C[];
extern const u8 gUnknown_0856F58C[];
extern const u8 gUnknown_0856F5AC[];
extern const u8 gUnknown_0856F4EC[];
extern const u8 gUnknown_0856F4AC[];
extern const u8 gUnknown_0856F50C[];
extern const u8 gUnknown_0856F4CC[];
extern const u8 gUnknown_0856F52C[];
extern const u8* gEmeraldTrainerCardStarPals[];
extern const u8* gFireRedTrainerCardStarPals[];
extern const u8 gUnknown_0856FB78[];
extern bool8 (*const gUnknown_0856FB28[])(struct Task *);

//this file's functions
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
/*static*/ u32 sav12_xor_get_clamped_above(u8 stat, u32 max);
/*static*/ bool8 sub_80C2DFC(void);
/*static*/ u32 sub_80C2E40(void);
/*static*/ u8 TrainerCard_GetStarCount(struct TrainerCard*); 
/*static*/ u16 sub_80C376C(void);
/*static*/ void sub_80C2EC4(struct TrainerCard*, u8);
/*static*/ void sub_80C3020(struct TrainerCard*);
/*static*/ u8 sub_80C4FCC(u8);
/*static*/ void sub_80C3190(void);
/*static*/ void sub_80C3278(void);
/*static*/ void sub_80C334C(void);
/*static*/ void sub_80C3388(void);
/*static*/ void sub_80C3404(void);
/*static*/ void sub_80C3414(void);
/*static*/ void sub_80C4EE4(void);
/*static*/ void sub_80C3574(void);
/*static*/ void sub_80C3608(void);
/*static*/ void sub_80C3684(void);
/*static*/ void sub_80C378C(void);
/*static*/ void sub_80C3A18(void);
/*static*/ bool8 sub_80C34B0(void);
/*static*/ void sub_80C3B50(void);
/*static*/ void sub_80C3CCC(void);
/*static*/ void sub_80C3D60(void);
/*static*/ void sub_80C3DF0(void);
/*static*/ void sub_80C3E58(void);
/*static*/ void sub_80C3F64(void);
/*static*/ void sub_80C3ED4(void);
/*static*/ void sub_80C3FE0(void);
/*static*/ void sub_80C4140(void);
/*static*/ void sub_80C40CC(void);
/*static*/ void sub_80C42A4(void);
/*static*/ void sub_80C3548(void);
/*static*/ void sub_80C3AF0(void);
/*static*/ void sub_80C3BC4(void);
/*static*/ void sub_80C3CF4(void);
/*static*/ void sub_80C3DC0(void);
/*static*/ void sub_80C3E20(void);
/*static*/ void sub_80C3E98(void);
/*static*/ void sub_80C3F14(void);
/*static*/ void sub_80C3FA4(void);
/*static*/ void sub_80C4020(void);
/*static*/ void sub_80C3C34(u8 top, const u8* str1, u8* str2, const u8* color);
/*static*/ void sub_80C4330(void);
/*static*/ u8 sub_80C43A8(void);
/*static*/ void sub_80C474C(void);
/*static*/ void sub_80C4960(u8);
/*static*/ bool8 sub_80C4998(struct Task* task);
/*static*/ bool8 sub_80C49D8(struct Task* task);
/*static*/ void sub_80C32EC(u16);

extern struct UnknownStruct{
    u8 var_0;
    u8 var_1;
    u8 var_2;
    u8 var_3;
    u8 var_4;
    u8 var_5;
    u8 var_6;
    u8 var_7;
    u8 var_8;
    u8 var_9;
    u8 var_A;
    u8 var_B;
    u8 var_C;
    u8 var_D;
    u8 var_E;
    u8 var_F;
    u8 var_10;
    u8 badgeCount[8];
    u8 var_19[0xD];
    u8 var_26[0xD];
    u8 var_33[0xD];
    u8 var_40[0xD];
    u8 var_4D[0x46];
    u8 var_93[0x46];
    u8 var_D9[0x8C];
    u8 var_165[0x46];
    u8 var_1AB[0x8C];
    u8 var_237[0x8C];
    u8 var_2C3[0x8C];
    u8 var_34F[0x46];
    u8 var_395[0x46];
    u8 var_3DB[0x46];
    u8 var_421[0x47];
    u16 var_468[0x60];
    s8 var_528;
    u8 var_529;
    u8 var_52A;
    u8 var_52B;
    u16 var_52C;
    void (*callback2)(void);
    struct TrainerCard var_534;
    u8 var_598[0x4B0];
    u8 var_A48[0x4B0];
    u8 var_EF8[0x4B0];
    u8 var_13A8[0x400];
    u8 var_17A8[0x200];
    u8 var_19A8[0x2300];
    u8 var_3CA8[0x2000];
    u8 var_5CA8[0x2000];
    u16 var_7CA8;
    u8 var_7CAA;
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
        if(gWirelessCommType == 1 && gReceivedRemoteLinkPlayers == TRUE)
        {
            sub_800E0E8();
            CreateWirelessStatusIndicatorSprite(230, 150);
        }
        BlendPalettes(0xFFFFFFFF, 16, gUnknown_02039CE8->var_52C);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, gUnknown_02039CE8->var_52C);
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
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, gUnknown_02039CE8->var_52C);
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
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, gUnknown_02039CE8->var_52C);
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
               BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, gUnknown_02039CE8->var_52C);
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
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, gUnknown_02039CE8->var_52C);
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
        return TRUE;
    }
    gUnknown_02039CE8->var_2++;
    return FALSE;
}

NAKED
void sub_80C2C80(void)         //not really a nonmatching, skipped it because of DMA macros
{
    asm("\n\
        .syntax unified\n\
        push {lr}\n\
    sub sp, 0x8\n\
    ldr r1, =gMain\n\
    movs r2, 0x87\n\
    lsls r2, 3\n\
    adds r0, r1, r2\n\
    ldrb r0, [r0]\n\
    adds r3, r1, 0\n\
    cmp r0, 0xA\n\
    bls _080C2C96\n\
    b _080C2DD8\n\
_080C2C96:\n\
    lsls r0, 2\n\
    ldr r1, =_080C2CA8\n\
    adds r0, r1\n\
    ldr r0, [r0]\n\
    mov pc, r0\n\
    .pool\n\
    .align 2, 0\n\
_080C2CA8:\n\
    .4byte _080C2CD4\n\
    .4byte _080C2CEC\n\
    .4byte _080C2D14\n\
    .4byte _080C2D50\n\
    .4byte _080C2D6A\n\
    .4byte _080C2D74\n\
    .4byte _080C2D88\n\
    .4byte _080C2D8E\n\
    .4byte _080C2DA0\n\
    .4byte _080C2DA6\n\
    .4byte _080C2DB8\n\
_080C2CD4:\n\
    bl sub_80C334C\n\
    bl sub_80C3414\n\
    ldr r1, =gMain\n\
    movs r0, 0x87\n\
    lsls r0, 3\n\
    adds r1, r0\n\
    b _080C2DCC\n\
    .pool\n\
_080C2CEC:\n\
    movs r1, 0xE0\n\
    lsls r1, 19\n\
    movs r0, 0\n\
    str r0, [sp]\n\
    ldr r0, =0x040000d4\n\
    mov r2, sp\n\
    str r2, [r0]\n\
    str r1, [r0, 0x4]\n\
    ldr r1, =0x85000100\n\
    str r1, [r0, 0x8]\n\
    ldr r0, [r0, 0x8]\n\
    movs r0, 0x87\n\
    lsls r0, 3\n\
    adds r1, r3, r0\n\
    b _080C2DCC\n\
    .pool\n\
_080C2D14:\n\
    ldr r0, =gUnknown_02039CE8\n\
    ldr r0, [r0]\n\
    ldr r1, =0x0000052c\n\
    adds r0, r1\n\
    ldrh r0, [r0]\n\
    cmp r0, 0\n\
    bne _080C2D36\n\
    movs r2, 0xA0\n\
    lsls r2, 19\n\
    add r1, sp, 0x4\n\
    strh r0, [r1]\n\
    ldr r0, =0x040000d4\n\
    str r1, [r0]\n\
    str r2, [r0, 0x4]\n\
    ldr r1, =0x81000200\n\
    str r1, [r0, 0x8]\n\
    ldr r0, [r0, 0x8]\n\
_080C2D36:\n\
    movs r2, 0x87\n\
    lsls r2, 3\n\
    adds r1, r3, r2\n\
    b _080C2DCC\n\
    .pool\n\
_080C2D50:\n\
    bl ResetSpriteData\n\
    bl FreeAllSpritePalettes\n\
    bl ResetPaletteFade\n\
    ldr r1, =gMain\n\
    movs r0, 0x87\n\
    lsls r0, 3\n\
    adds r1, r0\n\
    ldrb r0, [r1]\n\
    adds r0, 0x1\n\
    strb r0, [r1]\n\
_080C2D6A:\n\
    bl sub_80C3388\n\
    b _080C2DC4\n\
    .pool\n\
_080C2D74:\n\
    bl sub_80C41D8\n\
    ldr r1, =gMain\n\
    movs r0, 0x87\n\
    lsls r0, 3\n\
    adds r1, r0\n\
    b _080C2DCC\n\
    .pool\n\
_080C2D88:\n\
    bl sub_80C2AD8\n\
    b _080C2DBC\n\
_080C2D8E:\n\
    bl sub_80C4330\n\
    ldr r1, =gMain\n\
    movs r0, 0x87\n\
    lsls r0, 3\n\
    adds r1, r0\n\
    b _080C2DCC\n\
    .pool\n\
_080C2DA0:\n\
    bl sub_80C3278\n\
    b _080C2DC4\n\
_080C2DA6:\n\
    bl sub_80C3548\n\
    ldr r1, =gMain\n\
    movs r0, 0x87\n\
    lsls r0, 3\n\
    adds r1, r0\n\
    b _080C2DCC\n\
    .pool\n\
_080C2DB8:\n\
    bl sub_80C43A8\n\
_080C2DBC:\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0x1\n\
    bne _080C2DDC\n\
_080C2DC4:\n\
    ldr r1, =gMain\n\
    movs r2, 0x87\n\
    lsls r2, 3\n\
    adds r1, r2\n\
_080C2DCC:\n\
    ldrb r0, [r1]\n\
    adds r0, 0x1\n\
    strb r0, [r1]\n\
    b _080C2DDC\n\
    .pool\n\
_080C2DD8:\n\
    bl sub_80C3404\n\
_080C2DDC:\n\
    add sp, 0x8\n\
    pop {r0}\n\
    bx r0\n\
        .syntax divided");
}

u32 sav12_xor_get_clamped_above(u8 stat, u32 max)
{
    u32 retStat = GetGameStat(stat);
    return (retStat > max) ? max : retStat;
}

bool8 sub_80C2DFC(void)
{
    u8 i;
    for(i = 0; i <= 6; i++)
    {
        if(!FlagGet(FLAG_SYS_TOWER_SILVER + 2 * i) || !FlagGet(FLAG_SYS_TOWER_GOLD + 2 * i))
            return FALSE;
    }
    return TRUE; 
}

u32 sub_80C2E40(void)
{
    u32 stat = GetGameStat(GAME_STAT_ENTERED_HOF);
    u8 r4 = (stat | -stat) >> 31;
    
    if(sub_80C08E4())
        r4++;
    if(sub_80F8940() > 4)
        r4++;
    if(sub_80C2DFC())
        r4++;
    return r4;
}

u8 TrainerCard_GetStarCount(struct TrainerCard *trainerCard)
{
    u8 value = 0;

    if (trainerCard->firstHallOfFameA || trainerCard->firstHallOfFameB || trainerCard->firstHallOfFameC)
        value++;
    if (trainerCard->var_3)
        value++;
    if (trainerCard->battleTowerLosses > 49)
        value++;
    if (trainerCard->var_4)
        value++;
    
    return value;
}

void sub_80C2EC4(struct TrainerCard *trainerCard, u8 arg1)
{
    u32 playTime;
    bool32 enteredHallOfFame;
    u8 i;

    trainerCard->gender = gSaveBlock2Ptr->playerGender;
    trainerCard->playTimeHours = gSaveBlock2Ptr->playTimeHours;
    trainerCard->playTimeMinutes = gSaveBlock2Ptr->playTimeMinutes;

    playTime = GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME);
    enteredHallOfFame = GetGameStat(GAME_STAT_ENTERED_HOF);
    if (!enteredHallOfFame)
        playTime = 0;
    
    trainerCard->firstHallOfFameA = playTime >> 16;
    trainerCard->firstHallOfFameB = (playTime >> 8) & 0xFF;
    trainerCard->firstHallOfFameC = playTime & 0xFF;
    if((playTime >> 16) > 999)
    {
        trainerCard->firstHallOfFameA = 999;
        trainerCard->firstHallOfFameB = 59;
        trainerCard->firstHallOfFameC = 59;
    }
    
    trainerCard->hasPokedex = FlagGet(FLAG_SYS_POKEDEX_GET);
    trainerCard->var_3 = sub_80C08E4();
    trainerCard->pokedexCaught = sub_80C376C();

    trainerCard->trainerId = (gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0];

    trainerCard->linkBattleWins = sav12_xor_get_clamped_above(GAME_STAT_LINK_BATTLE_WINS, 9999);
    trainerCard->linkBattleLosses = sav12_xor_get_clamped_above(GAME_STAT_LINK_BATTLE_LOSSES, 9999);
    
    trainerCard->pokemonTrades = sav12_xor_get_clamped_above(GAME_STAT_POKEMON_TRADES, 0xFFFF);
    
    trainerCard->money = GetMoney(&gSaveBlock1Ptr->money);

    for (i = 0; i < 4; i++)
        trainerCard->var_28[i] = gSaveBlock1Ptr->unk2BB0[i];
    
    StringCopy(trainerCard->playerName, gSaveBlock2Ptr->playerName);
    
    switch(arg1)
    {
    case 2:
        trainerCard->battleTowerWins = 0;
        trainerCard->battleTowerLosses = 0;
    case 0:
        trainerCard->contestsWithFriends = sav12_xor_get_clamped_above(GAME_STAT_WON_LINK_CONTEST, 999);
        trainerCard->pokeblocksWithFriends = sav12_xor_get_clamped_above(GAME_STAT_POKEBLOCKS_WITH_FRIENDS, 0xFFFF);
        if(sub_80F8940() > 4)
            trainerCard->var_4 = TRUE;
        trainerCard->stars = TrainerCard_GetStarCount(trainerCard);
        break;
    case 1:
        trainerCard->battleTowerWins = 0;
        trainerCard->battleTowerLosses = 0;
        trainerCard->contestsWithFriends = 0;
        trainerCard->pokeblocksWithFriends = 0;
        trainerCard->var_4 = 0;
        trainerCard->stars = 0;
    }
}

#ifdef NONMATCHING      //r0 and r1 swapped
void sub_80C3020(struct TrainerCard *trainerCard)
{
    memset(trainerCard, 0, sizeof(struct TrainerCard));
    trainerCard->var_38 = 3;
    sub_80C2EC4(trainerCard, 2);
    trainerCard->var_60 = sub_80C2DFC();
    trainerCard->var_62 = gSaveBlock2Ptr->frontier.field_EBA;
    if(trainerCard->var_60)
        trainerCard->stars++;
    if(trainerCard->gender == FEMALE)
        trainerCard->var_4F = gUnknown_08329D54[(trainerCard->trainerId & 7) + 8];
    else
        trainerCard->var_4F = gUnknown_08329D54[trainerCard->trainerId & 7];
}
#else
NAKED
void sub_80C3020(struct TrainerCard *trainerCard)
{
    asm("\n\
    .syntax unified\n\
    push {r4,lr}\n\
    adds r4, r0, 0\n\
    movs r1, 0\n\
    movs r2, 0x64\n\
    bl memset\n\
    adds r1, r4, 0\n\
    adds r1, 0x38\n\
    movs r0, 0x3\n\
    strb r0, [r1]\n\
    adds r0, r4, 0\n\
    movs r1, 0x2\n\
    bl sub_80C2EC4\n\
    bl sub_80C2DFC\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    adds r1, r4, 0\n\
    adds r1, 0x60\n\
    strh r0, [r1]\n\
    ldr r0, =gSaveBlock2Ptr\n\
    ldr r0, [r0]\n\
    ldr r2, =0x00000eba\n\
    adds r0, r2\n\
    ldrh r0, [r0]\n\
    adds r2, r4, 0\n\
    adds r2, 0x62\n\
    strh r0, [r2]\n\
    ldrh r0, [r1]\n\
    cmp r0, 0\n\
    beq _080C3066\n\
    ldrb r0, [r4, 0x1]\n\
    adds r0, 0x1\n\
    strb r0, [r4, 0x1]\n\
_080C3066:\n\
    ldrb r0, [r4]\n\
    cmp r0, 0x1\n\
    bne _080C3084\n\
    ldr r2, =gUnknown_08329D54\n\
    ldrh r0, [r4, 0xE]\n\
    movs r1, 0x7\n\
    ands r0, r1\n\
    adds r0, 0x8\n\
    b _080C308C\n\
    .pool\n\
_080C3084:\n\
    ldr r2, =gUnknown_08329D54\n\
    ldrh r0, [r4, 0xE]\n\
    movs r1, 0x7\n\
    ands r0, r1\n\
_080C308C:\n\
    lsls r0, 1\n\
    adds r0, r2\n\
    ldrh r1, [r0]\n\
    adds r0, r4, 0\n\
    adds r0, 0x4F\n\
    strb r1, [r0]\n\
    pop {r4}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}
#endif // NONMATCHING

#ifdef NONMATCHING      //r0 and r1 swapped                                          
void TrainerCard_GenerateCardForPlayer(struct TrainerCard *trainerCard)
{
    u8 temp;
    memset(trainerCard, 0, 0x60);
    trainerCard->var_38 = 3;
    sub_80C2EC4(trainerCard, 2);
    temp = sub_80C2DFC();
    trainerCard->var_3A = temp;
    *((u16*)&trainerCard->var_3C) = gSaveBlock2Ptr->frontier.field_EBA;
    if(temp)
        trainerCard->stars++;
    if(trainerCard->gender == FEMALE)
        trainerCard->var_4F = gUnknown_08329D54[(trainerCard->trainerId & 7) + 8];
    else
        trainerCard->var_4F = gUnknown_08329D54[trainerCard->trainerId & 7];
}
#else
NAKED
void TrainerCard_GenerateCardForPlayer(struct TrainerCard *trainerCard)
{
    asm("\n\
    .syntax unified\n\
    push {r4,lr}\n\
    adds r4, r0, 0\n\
    movs r1, 0\n\
    movs r2, 0x60\n\
    bl memset\n\
    adds r1, r4, 0\n\
    adds r1, 0x38\n\
    movs r0, 0x3\n\
    strb r0, [r1]\n\
    adds r0, r4, 0\n\
    movs r1, 0x2\n\
    bl sub_80C2EC4\n\
    bl sub_80C2DFC\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    strh r0, [r4, 0x3A]\n\
    ldr r1, =gSaveBlock2Ptr\n\
    ldr r1, [r1]\n\
    ldr r2, =0x00000eba\n\
    adds r1, r2\n\
    ldrh r1, [r1]\n\
    strh r1, [r4, 0x3C]\n\
    cmp r0, 0\n\
    beq _080C30E0\n\
    ldrb r0, [r4, 0x1]\n\
    adds r0, 0x1\n\
    strb r0, [r4, 0x1]\n\
_080C30E0:\n\
    ldrb r0, [r4]\n\
    cmp r0, 0x1\n\
    bne _080C3100\n\
    ldr r2, =gUnknown_08329D54\n\
    ldrh r0, [r4, 0xE]\n\
    movs r1, 0x7\n\
    ands r0, r1\n\
    adds r0, 0x8\n\
    b _080C3108\n\
    .pool\n\
_080C3100:\n\
    ldr r2, =gUnknown_08329D54\n\
    ldrh r0, [r4, 0xE]\n\
    movs r1, 0x7\n\
    ands r0, r1\n\
_080C3108:\n\
    lsls r0, 1\n\
    adds r0, r2\n\
    ldrh r1, [r0]\n\
    adds r0, r4, 0\n\
    adds r0, 0x4F\n\
    strb r1, [r0]\n\
    pop {r4}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}
#endif // NONMATCHING

void sub_80C3120(struct TrainerCard *trainerCard, u16 *src, u8 gameVersion)
{
    memset(trainerCard, 0, sizeof(struct TrainerCard));
    trainerCard->var_38 = gameVersion;
    switch(sub_80C4FCC(gameVersion))
    {
    case 0:
        memcpy(trainerCard, src, 0x60); 
        break;
    case 1:
        memcpy(trainerCard, src, 0x38);
        break;
    case 2:
        memcpy(trainerCard, src, 0x60);
        trainerCard->var_3C = 0;
        trainerCard->var_60 = src[29];
        trainerCard->var_62 = src[30];
    }
}

void sub_80C3190(void)
{
    u8 i;
    u32 badgeFlag;
    
    gUnknown_02039CE8->var_A = 0;
    gUnknown_02039CE8->var_B = 0;
    gUnknown_02039CE8->var_C = 0;
    gUnknown_02039CE8->var_D = 0;
    gUnknown_02039CE8->var_E = 0;
    gUnknown_02039CE8->var_F = 0;
    gUnknown_02039CE8->var_10 = 0;
    memset(gUnknown_02039CE8->badgeCount, 0, 8);
    if(gUnknown_02039CE8->var_534.hasPokedex)
        gUnknown_02039CE8->var_A++;
    
    if(gUnknown_02039CE8->var_534.firstHallOfFameA 
     ||gUnknown_02039CE8->var_534.firstHallOfFameB 
     ||gUnknown_02039CE8->var_534.firstHallOfFameC)
        gUnknown_02039CE8->var_B++;
    
    if(gUnknown_02039CE8->var_534.linkBattleWins || gUnknown_02039CE8->var_534.linkBattleLosses)
        gUnknown_02039CE8->var_C++;
    if(gUnknown_02039CE8->var_534.pokemonTrades)
        gUnknown_02039CE8->var_10++;
    if(gUnknown_02039CE8->var_534.battleTowerWins || gUnknown_02039CE8->var_534.battleTowerLosses)
        gUnknown_02039CE8->var_D++;
    
    i = 0;
    badgeFlag = FLAG_BADGE01_GET;
    while (1)
    {
        if(FlagGet(badgeFlag))
            gUnknown_02039CE8->badgeCount[i]++;
        badgeFlag++;
        i++;
        if (badgeFlag > FLAG_BADGE08_GET)
            break;
    }
}

void sub_80C3278(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0V, 160);
    SetGpuReg(REG_OFFSET_WIN0H, 240);
    if(gReceivedRemoteLinkPlayers)
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    else
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_HBLANK);
}

void sub_80C32EC(u16 arg0)
{
    u8 quotient = (arg0 + 40) / 10;
    
    if((s8)quotient <= 4)
        quotient = 0;
    gUnknown_02039CE8->var_528 = quotient;
    SetGpuReg(REG_OFFSET_BLDY, gUnknown_02039CE8->var_528);
    SetGpuReg(REG_OFFSET_WIN0V, (gUnknown_02039CE8->var_7CA8 * 256) | (160 - gUnknown_02039CE8->var_7CA8));
}

void sub_80C334C(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
}

void sub_80C3388(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0856FAB4, ARRAY_COUNT(gUnknown_0856FAB4));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(gUnknown_0856FAC4);
    DeactivateAllTextPrinters();
    sub_81973A4();
}

void sub_80C3404(void)
{
    SetMainCallback2(sub_80C2710);
}

void sub_80C3414(void)
{
    ResetTasks();
    ScanlineEffect_Stop();
    CreateTask(sub_80C2760, 0);
    sub_80C4EE4();
    sub_80C3190();
}

bool8 sub_80C3438(void)
{
    switch(gUnknown_02039CE8->var_1)
    {
    case 0:
        sub_80C3574();
        break;
    case 1:
        sub_80C3608();
        break;
    case 2:
        sub_80C3684();
        break;
    case 3:
        sub_80C378C();
        break;
    case 4:
        sub_80C3880();
        break;
    case 5:
        sub_80C3A18();
        break;
    default:
        gUnknown_02039CE8->var_1 = 0;
        return TRUE;
    }
    gUnknown_02039CE8->var_1++;
    return FALSE;
}

bool8 sub_80C34B0(void)
{
    switch(gUnknown_02039CE8->var_1)
    {
    case 0:
        sub_80C3B50();
        break;
    case 1:
        sub_80C3CCC();
        break;
    case 2:
        sub_80C3D60();
        break;
    case 3:
        sub_80C3DF0();
        break;
    case 4:
        sub_80C3E58();
        sub_80C3F64();
        break;
    case 5:
        sub_80C3ED4();
        sub_80C3FE0();
        break;
    case 6:
        sub_80C4140();
        sub_80C40CC();
        break;
    case 7:
        sub_80C42A4();
        break;
    default:
        gUnknown_02039CE8->var_1 = 0;
        return TRUE;
    }
    gUnknown_02039CE8->var_1++;
    return FALSE;
}

void sub_80C3548(void)
{
    sub_80C3AF0();
    sub_80C3BC4();
    sub_80C3CF4();
    sub_80C3DC0();
    sub_80C3E20();
    sub_80C3E98();
    sub_80C3F14();
    sub_80C3FA4();
    sub_80C4020();
}

void sub_80C3574(void)
{
    u8 buffer[32];
    u8* txtPtr;
    txtPtr = StringCopy(buffer, gText_TrainerCardName);
    StringCopy(txtPtr, gUnknown_02039CE8->var_534.playerName);
    ConvertInternationalString(txtPtr, gUnknown_02039CE8->var_7CAA);
    if(!gUnknown_02039CE8->var_52A)
        AddTextPrinterParameterized3(1, 1, 20, 28, gUnknown_0856FB0C, -1, buffer);
    else
        AddTextPrinterParameterized3(1, 1, 16, 33, gUnknown_0856FB0C, -1, buffer);
}

void sub_80C3608(void)
{
    u8 buffer[32];
    u8* txtPtr;
    s32 xPos;
    u32 top;
    txtPtr = StringCopy(buffer, gText_TrainerCardIDNo);
    ConvertIntToDecimalStringN(txtPtr, gUnknown_02039CE8->var_534.trainerId, STR_CONV_MODE_LEADING_ZEROS, 5);
    if(!gUnknown_02039CE8->var_52A)
    {
        xPos = GetStringCenterAlignXOffset(1, buffer, 80) + 132; 
        top = 9;
    }
    else
    {
        xPos = GetStringCenterAlignXOffset(1, buffer, 96) + 120;
        top = 9;
    }
    
    AddTextPrinterParameterized3(1, 1, xPos, top, gUnknown_0856FB0C, -1, buffer);
}

void sub_80C3684(void)
{
    s32 xOffset;
    u8 top;
    if(!gUnknown_02039CE8->var_52B)
        AddTextPrinterParameterized3(1, 1, 20, 56, gUnknown_0856FB0C, -1, gText_TrainerCardMoney);
    else
        AddTextPrinterParameterized3(1, 1, 16, 57, gUnknown_0856FB0C, -1, gText_TrainerCardMoney);
    ConvertIntToDecimalStringN(gStringVar1, gUnknown_02039CE8->var_534.money, 0, 6);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    if(!gUnknown_02039CE8->var_52B)
    {
        xOffset = GetStringRightAlignXOffset(1, gStringVar4, 144);
        top = 56;
    }
    else
    {
        xOffset = GetStringRightAlignXOffset(1, gStringVar4, 128);
        top = 57;
    }   
    AddTextPrinterParameterized3(1, 1, xOffset, top, gUnknown_0856FB0C, -1, gStringVar4);
}

u16 sub_80C376C(void)
{
    if(IsNationalPokedexEnabled())
        return GetNationalPokedexCount(FLAG_GET_CAUGHT);
    
    return GetHoennPokedexCount(FLAG_GET_CAUGHT);
}

void sub_80C378C(void)
{
    s32 xOffset;
    u8 top;
    if(FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        if(!gUnknown_02039CE8->var_52B)
            AddTextPrinterParameterized3(1, 1, 20, 72, gUnknown_0856FB0C, -1, gText_TrainerCardPokedex);
        else
            AddTextPrinterParameterized3(1, 1, 16, 73, gUnknown_0856FB0C, -1,gText_TrainerCardPokedex);
        StringCopy(ConvertIntToDecimalStringN(gStringVar4, gUnknown_02039CE8->var_534.pokedexCaught, 0, 3), gText_EmptyString6);
        if(!gUnknown_02039CE8->var_52B)
        {
            xOffset = GetStringRightAlignXOffset(1, gStringVar4, 144);
            top = 72;
        }
        else
        {
            xOffset = GetStringRightAlignXOffset(1, gStringVar4, 128);
            top = 73;
        }   
        AddTextPrinterParameterized3(1, 1, xOffset, top, gUnknown_0856FB0C, -1, gStringVar4);
    }
}

void sub_80C3880(void)
{
    u16 hours;
    u16 minutes;
    s32 width;
    u32 r7, r4, r10;
    if(!gUnknown_02039CE8->var_52B)
        AddTextPrinterParameterized3(1, 1, 20, 88, gUnknown_0856FB0C, -1, gText_TrainerCardTime);
    else
        AddTextPrinterParameterized3(1, 1, 16, 89, gUnknown_0856FB0C, -1, gText_TrainerCardTime);
    if(gUnknown_02039CE8->var_5)
    {
        hours = gUnknown_02039CE8->var_534.playTimeHours;
        minutes = gUnknown_02039CE8->var_534.playTimeMinutes; 
    }
    else
    {
        hours = gSaveBlock2Ptr->playTimeHours;
        minutes = gSaveBlock2Ptr->playTimeMinutes;
    }
    if(hours > 999)
        hours = 999;
    if(minutes > 59)
        minutes = 59;
    width = GetStringWidth(1, gText_Colon2, 0);
    
    if(!gUnknown_02039CE8->var_52B)
    {
        r7 = 144;
        r4 = 88;
    } 
    else
    {
        r7 = 128;
        r4 = 89;
    }
    r10 = width + 30;
    r7 -= r10;
    
    FillWindowPixelRect(1, 0, r7, r4, r10, 15);
    ConvertIntToDecimalStringN(gStringVar4, hours, 1, 3);
    AddTextPrinterParameterized3(1, 1, r7, r4, gUnknown_0856FB0C, -1, gStringVar4);
    r7 += 18;
    AddTextPrinterParameterized3(1, 1, r7, r4, gUnknown_0856FB40[gUnknown_02039CE8->var_7], -1, gText_Colon2);
    r7 += width;
    ConvertIntToDecimalStringN(gStringVar4, minutes, 2, 2);
    AddTextPrinterParameterized3(1, 1, r7, r4, gUnknown_0856FB0C, -1, gStringVar4);
}

void sub_80C3A18(void)
{
    if(gUnknown_02039CE8->var_5)
    {
        AddTextPrinterParameterized3(1, 1, 8, gUnknown_0856FB48[gUnknown_02039CE8->var_52B], gUnknown_0856FB0C, -1, gUnknown_02039CE8->var_19);
        AddTextPrinterParameterized3(1, 1, GetStringWidth(1, gUnknown_02039CE8->var_19, 0) + 14, gUnknown_0856FB48[gUnknown_02039CE8->var_52B], gUnknown_0856FB0C, -1, gUnknown_02039CE8->var_26);
        AddTextPrinterParameterized3(1, 1, 8, gUnknown_0856FB4A[gUnknown_02039CE8->var_52B], gUnknown_0856FB0C, -1, gUnknown_02039CE8->var_33);
        AddTextPrinterParameterized3(1, 1, GetStringWidth(1, gUnknown_02039CE8->var_33, 0) + 14, gUnknown_0856FB4A[gUnknown_02039CE8->var_52B], gUnknown_0856FB0C, -1, gUnknown_02039CE8->var_40);
    }
}

void sub_80C3AF0(void)
{
    StringCopy(gUnknown_02039CE8->var_4D, gUnknown_02039CE8->var_534.playerName);
    ConvertInternationalString(gUnknown_02039CE8->var_4D, gUnknown_02039CE8->var_7CAA);
    if(gUnknown_02039CE8->var_52A)
    {
        StringCopy(gStringVar1, gUnknown_02039CE8->var_4D);
        StringExpandPlaceholders(gUnknown_02039CE8->var_4D, gText_Var1sTrainerCard);
    }
}

void sub_80C3B50(void)
{
    if(!gUnknown_02039CE8->var_52B)
        AddTextPrinterParameterized3(1, 1, 136, 9, gUnknown_0856FB0C, -1, gUnknown_02039CE8->var_4D);
    else
        AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, gUnknown_02039CE8->var_4D, 216), 9, gUnknown_0856FB0C, -1, gUnknown_02039CE8->var_4D);
}

void sub_80C3BC4(void)
{
    if(gUnknown_02039CE8->var_B)
    {
        ConvertIntToDecimalStringN(gStringVar1, gUnknown_02039CE8->var_534.firstHallOfFameA, 1, 3);
        ConvertIntToDecimalStringN(gStringVar2, gUnknown_02039CE8->var_534.firstHallOfFameB, 2, 2);
        ConvertIntToDecimalStringN(gStringVar3, gUnknown_02039CE8->var_534.firstHallOfFameC, 2, 2);
        StringExpandPlaceholders(gUnknown_02039CE8->var_93, gUnknown_0856FB4C);
    }
}

void sub_80C3C34(u8 top, const u8* str1, u8* str2, const u8* color)
{
    AddTextPrinterParameterized3(1, 1, gUnknown_0856FB55[gUnknown_02039CE8->var_52B], top * 16 + 33, gUnknown_0856FB0C, -1, str1);
    AddTextPrinterParameterized3(1, 1, GetStringRightAlignXOffset(1, str2, gUnknown_0856FB57[gUnknown_02039CE8->var_52B]), top * 16 + 33, color, -1, str2);
}

void sub_80C3CCC(void)
{
    if(gUnknown_02039CE8->var_B)
        sub_80C3C34(0, gText_HallOfFameDebut, gUnknown_02039CE8->var_93, gUnknown_0856FB0F); 
}

void sub_80C3CF4(void)
{
    if(gUnknown_02039CE8->var_C)
    {
        StringCopy(gUnknown_02039CE8->var_D9, gUnknown_0856FB5C[gUnknown_02039CE8->var_52A]);
        ConvertIntToDecimalStringN(gUnknown_02039CE8->var_165, gUnknown_02039CE8->var_534.linkBattleWins, 0, 4);
        ConvertIntToDecimalStringN(gUnknown_02039CE8->var_1AB, gUnknown_02039CE8->var_534.linkBattleLosses, 0, 4);
    }
}

void sub_80C3D60(void)
{
    if(gUnknown_02039CE8->var_C)
    {
        StringCopy(gStringVar1, gUnknown_02039CE8->var_165);
        StringCopy(gStringVar2, gUnknown_02039CE8->var_1AB);
        StringExpandPlaceholders(gStringVar4, gText_WinsLosses);
        sub_80C3C34(1, gUnknown_02039CE8->var_D9, gStringVar4, gUnknown_0856FB0C);
    }
}

void sub_80C3DC0(void)
{
    if(gUnknown_02039CE8->var_10)
        ConvertIntToDecimalStringN(gUnknown_02039CE8->var_237, gUnknown_02039CE8->var_534.pokemonTrades, 1, 5);
}

void sub_80C3DF0(void)
{
    if(gUnknown_02039CE8->var_10)
        sub_80C3C34(2, gText_PokemonTrades, gUnknown_02039CE8->var_237, gUnknown_0856FB0F);
}

void sub_80C3E20(void)
{
    if(!gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.var_3C)
        ConvertIntToDecimalStringN(gUnknown_02039CE8->var_2C3, gUnknown_02039CE8->var_534.var_3C, 1, 5);
}

void sub_80C3E58(void)
{
    if(!gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.var_3C)
        sub_80C3C34(4, gText_BerryCrush, gUnknown_02039CE8->var_2C3, gUnknown_0856FB0F);
}

void sub_80C3E98(void)
{
    if(!gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.var_40)
        ConvertIntToDecimalStringN(gUnknown_02039CE8->var_34F, gUnknown_02039CE8->var_534.var_40, 1, 5);
}

void sub_80C3ED4(void)
{
    if(!gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.var_40)
        sub_80C3C34(3, gText_UnionTradesAndBattles, gUnknown_02039CE8->var_34F, gUnknown_0856FB0F);
}

void sub_80C3F14(void)
{
    if(gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.pokeblocksWithFriends)
    {
        ConvertIntToDecimalStringN(gStringVar1, gUnknown_02039CE8->var_534.pokeblocksWithFriends, 1, 5);
        StringExpandPlaceholders(gUnknown_02039CE8->var_395, gText_Var1DarkGreyShadowLightGrey);
    }
}

void sub_80C3F64(void)
{
    if(gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.pokeblocksWithFriends)
        sub_80C3C34(3, gText_PokeblocksWithFriends, gUnknown_02039CE8->var_395, gUnknown_0856FB0F);
}

void sub_80C3FA4(void)
{
    if(gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.contestsWithFriends)
        ConvertIntToDecimalStringN(gUnknown_02039CE8->var_3DB, gUnknown_02039CE8->var_534.contestsWithFriends, 1, 5);
}

void sub_80C3FE0(void)
{
    if(gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.contestsWithFriends)
        sub_80C3C34(4, gText_WonContestsWFriends, gUnknown_02039CE8->var_3DB, gUnknown_0856FB0F);
}

void sub_80C4020(void)
{
    switch(gUnknown_02039CE8->var_52A)
    {
    case 1:
        if(gUnknown_02039CE8->var_D)
        {
            ConvertIntToDecimalStringN(gStringVar1, gUnknown_02039CE8->var_534.battleTowerWins, 1, 4);
            ConvertIntToDecimalStringN(gStringVar2, gUnknown_02039CE8->var_534.battleTowerLosses, 1, 4);
            StringExpandPlaceholders(gUnknown_02039CE8->var_421, gText_WSlashStraightSlash);
        }
        break;
    
    case 2:
        if(gUnknown_02039CE8->var_534.var_62)
        {
            ConvertIntToDecimalStringN(gStringVar1, gUnknown_02039CE8->var_534.var_62, 1, 5);
            StringExpandPlaceholders(gUnknown_02039CE8->var_421, gText_Var1DarkLightGreyBP);
        }
    case 0:
    }
}

void sub_80C40CC(void)
{
    switch(gUnknown_02039CE8->var_52A)
    {
    case 1:
        if(gUnknown_02039CE8->var_D)
            sub_80C3C34(5, gText_BattleTower, gUnknown_02039CE8->var_421, gUnknown_0856FB0C);
        break;
    case 2:
        if(gUnknown_02039CE8->var_534.var_62)
            sub_80C3C34(5, gText_BattlePtsWon, gUnknown_02039CE8->var_421, gUnknown_0856FB0F);
    case 0:
    }  
}

void sub_80C4140(void)
{
    u8 i;
    u8 buffer[8];
    u8 buffer2[8];
    memcpy(buffer, gUnknown_0856FB68, sizeof(gUnknown_0856FB68));
    memcpy(buffer2, gUnknown_0856FB6E, sizeof(gUnknown_0856FB6E));
    
    if(!gUnknown_02039CE8->var_52A)
    {
        for(i = 0; i < 6; i++)
        {
            if(gUnknown_02039CE8->var_534.monSpecies[i])
            {
                u8 monSpecies = sub_80D30A0(gUnknown_02039CE8->var_534.monSpecies[i]);
                WriteSequenceToBgTilemapBuffer(3, 16 * i + 224, buffer2[i] + 3, 15, 4, 4, buffer[monSpecies], 1);
            }
        }
    }   
}

void sub_80C41D8(void)
{
    u8 i;
    CpuSet(gMonIconPalettes, gUnknown_02039CE8->var_468, 0x60);
    switch(gUnknown_02039CE8->var_534.var_4E)
    {
    case 1:
        TintPalette_CustomTone(gUnknown_02039CE8->var_468, 96, 0, 0, 0);
        break;
    case 2:
        TintPalette_CustomTone(gUnknown_02039CE8->var_468, 96, 500, 330, 310);
        break;
    case 3:
        TintPalette_SepiaTone(gUnknown_02039CE8->var_468, 96);
    case 0:
    }
    LoadPalette(gUnknown_02039CE8->var_468, 80, 192);
    
    for(i = 0; i < 6; i++)
    {
        if(gUnknown_02039CE8->var_534.monSpecies[i])
            LoadBgTiles(3, GetMonIconTiles(gUnknown_02039CE8->var_534.monSpecies[i], 0), 512, 16 * i + 32);
    }   
}

void sub_80C42A4(void)
{
    u8 i;
    u8 buffer[4];
    memcpy(buffer, gUnknown_0856FB74, sizeof(gUnknown_0856FB74));
    if(!gUnknown_02039CE8->var_52A && gUnknown_02039CE8->var_534.var_4C == 1)
    {
        for(i = 0; i < 3; i++)
        {
            u8 var_50 = gUnknown_02039CE8->var_534.var_50[i];
            if(gUnknown_02039CE8->var_534.var_50[i])
                WriteSequenceToBgTilemapBuffer(3, i * 4 + 320, i * 3 + 2, 2, 2, 2, buffer[var_50 - 1], 1);
        }
    }
}

void sub_80C4330(void)
{
    LoadPalette(gUnknown_0856F54C, 176, 32);
    LoadPalette(gUnknown_0856F56C, 192, 32);
    LoadPalette(gUnknown_0856F58C, 208, 32);
    LoadPalette(gUnknown_0856F5AC, 224, 32);
    LoadBgTiles(3, gUnknown_02039CE8->var_17A8, 1024, 128);
}

void sub_80C438C(u8 windowId)
{
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

u8 sub_80C43A8(void)
{
    switch(gUnknown_02039CE8->var_3)
    {
    case 0:
        LoadBgTiles(3, gUnknown_02039CE8->var_13A8, 1024, 0);
        break;
    case 1:
        LoadBgTiles(0, gUnknown_02039CE8->var_19A8, 6144, 0);
        break;
    case 2:
        if(gUnknown_02039CE8->var_52A)
        {
            LoadPalette(gEmeraldTrainerCardStarPals[gUnknown_02039CE8->var_534.stars], 0, 96);
            LoadPalette(gUnknown_0856F4EC, 48, 32);
            if(gUnknown_02039CE8->var_534.gender)
                LoadPalette(gUnknown_0856F4AC, 16, 32);
        }
        else
        {
            LoadPalette(gFireRedTrainerCardStarPals[gUnknown_02039CE8->var_534.stars], 0, 96);
            LoadPalette(gUnknown_0856F50C, 48, 32);
            if(gUnknown_02039CE8->var_534.gender)
                LoadPalette(gUnknown_0856F4CC, 16, 32);
        }
        LoadPalette(gUnknown_0856F52C, 64, 32);
        break;
    case 3:
        SetBgTilemapBuffer(0, gUnknown_02039CE8->var_3CA8);
        SetBgTilemapBuffer(2, gUnknown_02039CE8->var_5CA8);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
    default:
        return 1;
    }
    gUnknown_02039CE8->var_3++;
    return 0;
}

NAKED
void sub_80C4550(u8* ptr)           //nested loop
{
    asm("\n\
    .syntax unified\n\
    push {r4-r7,lr}\n\
    adds r7, r0, 0\n\
    ldr r0, =gUnknown_02039CE8\n\
    ldr r0, [r0]\n\
    ldr r1, =0x00005ca8\n\
    adds r6, r0, r1\n\
    movs r1, 0\n\
_080C455E:\n\
    movs r2, 0\n\
    lsls r5, r1, 16\n\
    asrs r1, r5, 16\n\
    lsls r3, r1, 5\n\
    lsls r0, r1, 4\n\
    subs r0, r1\n\
    lsls r4, r0, 1\n\
_080C456C:\n\
    lsls r0, r2, 16\n\
    asrs r1, r0, 16\n\
    adds r2, r0, 0\n\
    cmp r1, 0x1D\n\
    bgt _080C4590\n\
    adds r0, r3, r1\n\
    lsls r0, 1\n\
    adds r0, r6\n\
    adds r1, r4, r1\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r1, [r1]\n\
    b _080C4598\n\
    .pool\n\
_080C4590:\n\
    adds r0, r3, r1\n\
    lsls r0, 1\n\
    adds r0, r6\n\
    ldrh r1, [r7]\n\
_080C4598:\n\
    strh r1, [r0]\n\
    movs r1, 0x80\n\
    lsls r1, 9\n\
    adds r0, r2, r1\n\
    lsrs r2, r0, 16\n\
    asrs r0, 16\n\
    cmp r0, 0x1F\n\
    ble _080C456C\n\
    adds r0, r5, r1\n\
    lsrs r1, r0, 16\n\
    asrs r0, 16\n\
    cmp r0, 0x13\n\
    ble _080C455E\n\
    movs r0, 0x2\n\
    bl CopyBgTilemapBufferToVram\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .syntax divided");
}

NAKED
void sub_80C45C0(u8* ptr)             //nested loop
{
    asm("\n\
    .syntax unified\n\
    push {r4-r7,lr}\n\
    adds r7, r0, 0\n\
    ldr r0, =gUnknown_02039CE8\n\
    ldr r0, [r0]\n\
    ldr r1, =0x00003ca8\n\
    adds r6, r0, r1\n\
    movs r1, 0\n\
_080C45CE:\n\
    movs r2, 0\n\
    lsls r5, r1, 16\n\
    asrs r1, r5, 16\n\
    lsls r3, r1, 5\n\
    lsls r0, r1, 4\n\
    subs r0, r1\n\
    lsls r4, r0, 1\n\
_080C45DC:\n\
    lsls r0, r2, 16\n\
    asrs r1, r0, 16\n\
    adds r2, r0, 0\n\
    cmp r1, 0x1D\n\
    bgt _080C4600\n\
    adds r0, r3, r1\n\
    lsls r0, 1\n\
    adds r0, r6\n\
    adds r1, r4, r1\n\
    lsls r1, 1\n\
    adds r1, r7\n\
    ldrh r1, [r1]\n\
    b _080C4608\n\
    .pool\n\
_080C4600:\n\
    adds r0, r3, r1\n\
    lsls r0, 1\n\
    adds r0, r6\n\
    ldrh r1, [r7]\n\
_080C4608:\n\
    strh r1, [r0]\n\
    movs r1, 0x80\n\
    lsls r1, 9\n\
    adds r0, r2, r1\n\
    lsrs r2, r0, 16\n\
    asrs r0, 16\n\
    cmp r0, 0x1F\n\
    ble _080C45DC\n\
    adds r0, r5, r1\n\
    lsrs r1, r0, 16\n\
    asrs r0, 16\n\
    cmp r0, 0x13\n\
    ble _080C45CE\n\
    movs r0, 0\n\
    bl CopyBgTilemapBufferToVram\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .syntax divided");
}

NAKED
void sub_80C4630(void)
{
    asm("\n\
    .syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0xC\n\
    movs r0, 0xC0\n\
    mov r8, r0\n\
    movs r2, 0x3\n\
    mov r10, r2\n\
    ldr r2, =gUnknown_0856FB78\n\
    ldr r4, =gUnknown_02039CE8\n\
    ldr r1, [r4]\n\
    ldr r3, =0x0000052b\n\
    adds r0, r1, r3\n\
    ldrb r0, [r0]\n\
    adds r0, r2\n\
    ldrb r3, [r0]\n\
    ldr r0, =0x00000535\n\
    adds r1, r0\n\
    ldrb r0, [r1]\n\
    str r0, [sp]\n\
    movs r0, 0x1\n\
    str r0, [sp, 0x4]\n\
    movs r0, 0x4\n\
    str r0, [sp, 0x8]\n\
    movs r0, 0x3\n\
    movs r1, 0x8F\n\
    movs r2, 0xF\n\
    bl FillBgTilemapBufferRect\n\
    ldr r0, [r4]\n\
    ldrb r0, [r0, 0x5]\n\
    cmp r0, 0\n\
    bne _080C4724\n\
    movs r2, 0x4\n\
    mov r9, r2\n\
    movs r2, 0\n\
    movs r6, 0x1\n\
_080C467E:\n\
    ldr r0, =gUnknown_02039CE8\n\
    ldr r1, [r0]\n\
    lsls r0, r2, 16\n\
    asrs r7, r0, 16\n\
    adds r1, 0x11\n\
    adds r1, r7\n\
    ldrb r0, [r1]\n\
    cmp r0, 0\n\
    beq _080C4700\n\
    mov r3, r9\n\
    lsls r5, r3, 24\n\
    lsrs r5, 24\n\
    str r6, [sp]\n\
    str r6, [sp, 0x4]\n\
    mov r0, r10\n\
    str r0, [sp, 0x8]\n\
    movs r0, 0x3\n\
    mov r1, r8\n\
    adds r2, r5, 0\n\
    movs r3, 0xF\n\
    bl FillBgTilemapBufferRect\n\
    mov r1, r8\n\
    adds r1, 0x1\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    mov r4, r9\n\
    adds r4, 0x1\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    str r6, [sp]\n\
    str r6, [sp, 0x4]\n\
    mov r2, r10\n\
    str r2, [sp, 0x8]\n\
    movs r0, 0x3\n\
    adds r2, r4, 0\n\
    movs r3, 0xF\n\
    bl FillBgTilemapBufferRect\n\
    mov r1, r8\n\
    adds r1, 0x10\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    str r6, [sp]\n\
    str r6, [sp, 0x4]\n\
    mov r3, r10\n\
    str r3, [sp, 0x8]\n\
    movs r0, 0x3\n\
    adds r2, r5, 0\n\
    movs r3, 0x10\n\
    bl FillBgTilemapBufferRect\n\
    mov r1, r8\n\
    adds r1, 0x11\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    str r6, [sp]\n\
    str r6, [sp, 0x4]\n\
    mov r0, r10\n\
    str r0, [sp, 0x8]\n\
    movs r0, 0x3\n\
    adds r2, r4, 0\n\
    movs r3, 0x10\n\
    bl FillBgTilemapBufferRect\n\
_080C4700:\n\
    adds r0, r7, 0x1\n\
    lsls r0, 16\n\
    mov r1, r8\n\
    adds r1, 0x2\n\
    lsls r1, 16\n\
    lsrs r1, 16\n\
    mov r8, r1\n\
    mov r2, r9\n\
    lsls r1, r2, 16\n\
    movs r3, 0xC0\n\
    lsls r3, 10\n\
    adds r1, r3\n\
    lsrs r1, 16\n\
    mov r9, r1\n\
    lsrs r2, r0, 16\n\
    asrs r0, 16\n\
    cmp r0, 0x7\n\
    ble _080C467E\n\
_080C4724:\n\
    movs r0, 0x3\n\
    bl CopyBgTilemapBufferToVram\n\
    add sp, 0xC\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}

void sub_80C474C(void)
{
    if(!gUnknown_02039CE8->var_52A)
    {
        if(gUnknown_02039CE8->var_10)
        {
            FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 1);
            FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 1);
        }
        if(gUnknown_02039CE8->var_534.var_3C)
        {
            FillBgTilemapBufferRect(3, 141, 21, 13, 1, 1, 1);
            FillBgTilemapBufferRect(3, 157, 21, 14, 1, 1, 1);
        }
        if(gUnknown_02039CE8->var_534.var_40)
        {
            FillBgTilemapBufferRect(3, 141, 27, 11, 1, 1, 1);
            FillBgTilemapBufferRect(3, 157, 27, 12, 1, 1, 1);
        }
    }
    else
    {
        if(gUnknown_02039CE8->var_10)
        {
            FillBgTilemapBufferRect(3, 141, 27, 9, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 27, 10, 1, 1, 0);
        }
        if(gUnknown_02039CE8->var_534.contestsWithFriends)
        {
            FillBgTilemapBufferRect(3, 141, 27, 13, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 27, 14, 1, 1, 0);
        }
        if(gUnknown_02039CE8->var_D)
        {
            FillBgTilemapBufferRect(3, 141, 17, 15, 1, 1, 0);
            FillBgTilemapBufferRect(3, 157, 17, 16, 1, 1, 0);
            FillBgTilemapBufferRect(3, 140, 27, 15, 1, 1, 0);
            FillBgTilemapBufferRect(3, 156, 27, 16, 1, 1, 0);
        }
    }
    CopyBgTilemapBufferToVram(3);
}

void sub_80C48C8(void)
{
    if(++gUnknown_02039CE8->var_6 > 60)
    {
        gUnknown_02039CE8->var_6 = 0;
        gUnknown_02039CE8->var_7 ^= 1;
        gUnknown_02039CE8->var_529 = 1;
    }
}

u8 sub_80C4904(u8 cardId)
{
    struct TrainerCard* trainerCards = gTrainerCards;
    return trainerCards[cardId].stars;
}

void sub_80C4918(void)
{
    u8 taskId = CreateTask(sub_80C4960, 0);
    sub_80C4960(taskId);
    SetHBlankCallback(sub_80C26D4);
}

bool8 sub_80C4940(void)
{
    if(FindTaskIdByFunc(sub_80C4960) == 0xFF)
        return TRUE;
    return FALSE;
}

void sub_80C4960(u8 taskId)
{
    while(gUnknown_0856FB28[gTasks[taskId].data[0]](&gTasks[taskId]))
        ;
}

bool8 sub_80C4998(struct Task* task)
{
    u32 i;
    HideBg(1);
    HideBg(3);
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    for(i = 0; i < 160; i++)
        gScanlineEffectRegBuffers[1][i] = 0;
    task->data[0]++;
    return FALSE;
}
