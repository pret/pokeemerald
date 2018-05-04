#include "global.h"
#include "gpu_regs.h"
#include "bg.h"
#include "malloc.h"
#include "constants/items.h"
#include "constants/map_objects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "battle.h"
#include "battle_anim.h"
#include "blend_palette.h"
#include "contest.h"
#include "data2.h"
#include "decompress.h"
#include "graphics.h"
#include "link.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "scanline_effect.h"
#include "util.h"
#include "contest_link_80F57C4.h"
#include "dma3.h"
#include "battle_message.h"
#include "event_scripts.h"
#include "strings.h"
#include "contest_effect.h"

#define DESTROY_POINTER(ptr) \
    free(ptr); \
    ptr = NULL;

void sub_80D782C(void);
void sub_80D7C7C(u8 taskId);
void sub_80D7CB4(u8 taskId);
void sub_80D7DAC(u8 taskId);
void sub_80D7DC8(u8 taskId);
void sub_80D7DE8(u8 taskId);
bool8 sub_80D7E44(u8 *);
void sub_80D80C8(u8 taskId);
void sub_80D8108(u8 taskId);
void vblank_cb_battle(void);
void sub_80D823C(void);
void sub_80D833C(u8 taskId);
void sub_80D8424(u8 taskId);
void sub_80D8610(u8 taskId);
void sub_80D8490(u8 taskId);
void sub_80D880C(s8);
void sub_80D883C(s8);
void sub_80D8894(u8 taskId);
void sub_80D892C(u8 taskId);
void sub_80D895C(u8 taskId);
void sub_80D8A04(u8 taskId);
void sub_80D8A50(u8 taskId);
void sub_80D8A88(u8 taskId);
void sub_80D8B38(u8 taskId);
bool8 sub_80DA8A4(void);
u8 sub_80DB0C4(void);
u8 sub_80DB120(void);
void sub_80DB2BC(void);
void sub_80DB89C(void);
u16 sub_80DB8B8(u8);
void sub_80DB918(void);
bool8 sub_80DBCA8(u8);
void sub_80DBF68(void);
void sub_80DBF90(void);
void sub_80DC2BC(void);
void sub_80DC490(bool8);
void sub_80DC4F0(void);
void sub_80DC594(void);
void sub_80DC5E8(void);
void sub_80DC7EC(void);
void sub_80DCD48(void);
void sub_80DCE58(u8);
void sub_80DD04C(void);
void sub_80DD590(void);
void sub_80DDB0C(void);
void sub_80DDBE8(void);
bool8 sub_80DE1E8(u8);
void sub_80DE224(void);
void sub_80DE350(void);
void sub_80DE69C(u8);
void sub_80DEA20(void);
void sub_80DEBD0(u32, u8 *, u8, u8, u8);
void sub_80DEC30(u8 *, u8);
void sub_80DECB8(u8, u16, u8, u8, u8, u8, u8, u8);
bool32 sub_80DED4C(void);
void sub_80DED60(u32);
void sub_80FC9F8(u8);
bool8 AreMovesContestCombo(u16, u16);
void prints_contest_move_description(u16);


EWRAM_DATA struct ContestPokemon gContestMons[4] = {0};
EWRAM_DATA s16 gUnknown_02039F00[4] = {0};
EWRAM_DATA s16 gUnknown_02039F08[4] = {0};
EWRAM_DATA s16 gUnknown_02039F10[4] = {0};
EWRAM_DATA s16 gUnknown_02039F18[4] = {0};
EWRAM_DATA u8 gContestFinalStandings[4] = {0};
EWRAM_DATA u8 gUnknown_02039F24 = 0;
EWRAM_DATA u8 gContestPlayerMonIndex = 0;
EWRAM_DATA u8 gUnknown_02039F26[4] = {0};
EWRAM_DATA u8 gIsLinkContest = 0;
// Bit 0: Is a link contest
// Bit 1: Link contest uses wireless adapter
EWRAM_DATA u8 gUnknown_02039F2B = 0;
EWRAM_DATA u16 gSpecialVar_ContestCategory = 0;
EWRAM_DATA u16 gSpecialVar_ContestRank = 0;
EWRAM_DATA u8 gUnknown_02039F30 = 0;
EWRAM_DATA u8 gUnknown_02039F31 = 0;
EWRAM_DATA struct ContestResources * gContestResources = NULL;
EWRAM_DATA u8 sContestBgCopyFlags = 0;
EWRAM_DATA struct ContestWinner gUnknown_02039F3C = {0};

u32 gContestRngValue;

extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern s16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;

extern const u8 gContestMiscGfx[];
extern const u8 gContestAudienceGfx[];
extern const u8 gUnknown_08C16FA8[];
extern const u8 gUnknown_08C16E90[];
extern const u8 gUnknown_08C17170[];
extern const u16 gUnknown_08587C30[];
extern const struct BgTemplate gUnknown_08587F34[4];
extern const struct WindowTemplate gUnknown_08587F44[];

void TaskDummy1(u8 taskId)
{
}

void ResetLinkContestBoolean(void)
{
    gIsLinkContest = 0;
}

void sub_80D7678(void)
{
    u16 savedIme;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, 0x3F3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x3F3F);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
}

void LoadContestBgAfterMoveAnim(void)
{
    s32 i;

    LZDecompressVram(gContestMiscGfx, (void *)VRAM);
    LZDecompressVram(gContestAudienceGfx, (void *)(VRAM + 0x2000));
    CopyToBgTilemapBuffer(3, gUnknown_08C16FA8, 0, 0);
    CopyBgTilemapBufferToVram(3);
    LoadCompressedPalette(gUnknown_08C16E90, 0, 0x200);
    sub_80D782C();
    for (i = 0; i < 4; i++)
    {
        u32 var = 5 + i;

        LoadPalette(shared18000.unk18004[var], 16 * (5 + gUnknown_02039F26[i]), 16 * sizeof(u16));
    }
}

void sub_80D779C(void)
{
    s32 i;

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08587F34, ARRAY_COUNT(gUnknown_08587F34));
    SetBgAttribute(3, BG_CTRL_ATTR_PRIORITY, 1);
    for (i = 0; i < 4; i++)
    {
        SetBgTilemapBuffer(i, gContestResources->field_24[i]);
    }
}

void sub_80D77E4(void)
{
    InitWindows(gUnknown_08587F44);
    DeactivateAllTextPrinters();
    if (gIsLinkContest & 1)
    {
        gTextFlags.flag_0 = FALSE;
    }
    else
    {
        gTextFlags.flag_0 = TRUE;
    }
}

void sub_80D782C(void)
{
    s32 i;

    LoadPalette(gUnknown_08587C30, 0xf0, 0x20);
    FillPalette(0, 0, 2);
    for (i = 10; i < 14; i++)
        LoadPalette(gPlttBufferUnfaded + 241, 240 + i, 2);
    FillPalette(0x7E3F, 0xF3, 2);
}

void sub_80D787C(void)
{
    s32 i;

    *gContestResources->field_0 = (struct Contest){};
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_0->unk19206[i] = 0xFF;
    }
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_4[i] = (struct ContestantStatus){};
    }
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_4[i].unkB_0 = 0;
        gContestResources->field_4[i].effectStringId = CONTEST_STRING_NONE;
        gContestResources->field_4[i].effectStringId2 = CONTEST_STRING_NONE;
    }
    *gContestResources->field_8 = (struct UnknownContestStruct7){};
    *gContestResources->field_C = (struct ContestAIInfo){};
    *gContestResources->field_10 = (struct UnknownContestStruct5){};
    memset(gContestResources->field_14, 0, 4 * sizeof(struct UnknownContestStruct4));
    if (!(gIsLinkContest & 1))
        sub_80DCE58(0);
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_4[i].nextTurnOrder = 0xFF;
        gContestResources->field_0->unk19218[i] = gUnknown_02039F26[i];
    }
    sub_80DD590();
    *gContestResources->field_1c = (struct ContestResourcesField1C){};
}

void sub_80D7988(void)
{
    gContestResources = AllocZeroed(sizeof(struct ContestResources));
    gContestResources->field_0 = AllocZeroed(sizeof(struct Contest));
    gContestResources->field_4 = AllocZeroed(sizeof(struct ContestantStatus) * 4);
    gContestResources->field_8 = AllocZeroed(sizeof(struct UnknownContestStruct7));
    gContestResources->field_C = AllocZeroed(sizeof(struct ContestAIInfo));
    gContestResources->field_10 = AllocZeroed(sizeof(struct UnknownContestStruct5) * 4);
    gContestResources->field_14 = AllocZeroed(sizeof(struct UnknownContestStruct4) * 4);
    gContestResources->field_18 = AllocZeroed(sizeof(struct ContestStruct_field_18));
    gContestResources->field_1c = AllocZeroed(sizeof(struct ContestResourcesField1C));
    gContestResources->field_20 = AllocZeroed(sizeof(struct ContestResourcesField20));
    gContestResources->field_24[0] = AllocZeroed(0x1000);
    gContestResources->field_24[1] = AllocZeroed(0x1000);
    gContestResources->field_24[2] = AllocZeroed(0x1000);
    gContestResources->field_24[3] = AllocZeroed(0x1000);
    gContestResources->field_34 = AllocZeroed(0x800);
    gContestResources->field_38 = AllocZeroed(0x800);
    gContestResources->field_3c = AllocZeroed(0x2000);
    gUnknown_0202305C = gContestResources->field_3c;
    gUnknown_02023060 = gContestResources->field_24[1];
}

void sub_80D7A5C(void)
{
    DESTROY_POINTER(gContestResources->field_0);
    DESTROY_POINTER(gContestResources->field_4);
    DESTROY_POINTER(gContestResources->field_8);
    DESTROY_POINTER(gContestResources->field_C);
    DESTROY_POINTER(gContestResources->field_10);
    DESTROY_POINTER(gContestResources->field_14);
    DESTROY_POINTER(gContestResources->field_18);
    DESTROY_POINTER(gContestResources->field_1c);
    DESTROY_POINTER(gContestResources->field_20);
    DESTROY_POINTER(gContestResources->field_24[0]);
    DESTROY_POINTER(gContestResources->field_24[1]);
    DESTROY_POINTER(gContestResources->field_24[2]);
    DESTROY_POINTER(gContestResources->field_24[3]);
    DESTROY_POINTER(gContestResources->field_34);
    DESTROY_POINTER(gContestResources->field_38);
    DESTROY_POINTER(gContestResources->field_3c);
    DESTROY_POINTER(gContestResources);
    gUnknown_0202305C = NULL;
    gUnknown_02023060 = NULL;
}

void sub_80D7B24(void)
{
    switch (gMain.state)
    {
        case 0:
            sContestBgCopyFlags = 0;
            sub_80D7988();
            AllocateMonSpritesGfx();
            DESTROY_POINTER(gMonSpritesGfxPtr->firstDecompressed);
            gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(0x4000);
            SetVBlankCallback(NULL);
            sub_80D779C();
            sub_80D77E4();
            sub_80D7678();
            ScanlineEffect_Clear();
            ResetPaletteFade();
            gPaletteFade.bufferTransferDisabled = TRUE;
            ResetSpriteData();
            ResetTasks();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 4;
            //shared18000.unk18000 = 0;
            gHeap[0x1a000] = 0;
            ClearBattleMonForms();
            sub_80D787C();
            gMain.state++;
            break;
        case 1:
            gMain.state++;
            break;
        case 2:
            if (sub_80D7E44(&gContestResources->field_0->unk1925D))
            {
                gContestResources->field_0->unk1925D = 0;
                gMain.state++;
            }
            break;
        case 3:
            sub_80DE224();
            gBattle_BG1_X = 0;
            gBattle_BG1_Y = 0;
            BeginFastPaletteFade(2);
            gPaletteFade.bufferTransferDisabled = FALSE;
            SetVBlankCallback(vblank_cb_battle);
            gContestResources->field_0->mainTaskId = CreateTask(sub_80D7C7C, 10);
            SetMainCallback2(sub_80D823C);
            if (gIsLinkContest & 2)
            {
                sub_800E0E8();
                CreateWirelessStatusIndicatorSprite(8, 8);
            }
            break;
    }
}

void sub_80D7C7C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80D7CB4;
    }
}

void sub_80D7CB4(u8 taskId)
{
    if (gIsLinkContest & 1)
    {
        if (gIsLinkContest & 2)
        {
            switch (gTasks[taskId].data[0])
            {
                case 0:
                    sub_80DBF68();
                    gTasks[taskId].data[0]++;
                    // fallthrough
                case 1:
                    if (sub_800A520())
                    {
                        sub_800ADF8();
                        gTasks[taskId].data[0]++;
                    }
                    return;
                case 2:
                    if (sub_800A520() != TRUE)
                        return;
                    gTasks[taskId].data[0]++;
                    break;
            }
        }

        if (!gPaletteFade.active)
        {
            gPaletteFade.bufferTransferDisabled = FALSE;
            if (!(gIsLinkContest & 2))
                sub_80DBF68();
            CreateTask(sub_80D7DAC, 0);
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = TaskDummy1;
        }
    }
    else
    {
        gTasks[taskId].func = sub_80D80C8;
    }
}

void sub_80D7DAC(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_80FC998, sub_80D7DC8);
}

void sub_80D7DC8(u8 taskId)
{
    gTasks[taskId].data[0] = 1;
    gTasks[taskId].func = sub_80D7DE8;
}

void sub_80D7DE8(u8 taskId)
{
    gTasks[taskId].data[0]--;
    if (gTasks[taskId].data[0] <= 0)
    {
        GetMultiplayerId();  // unused return value
        DestroyTask(taskId);
        gTasks[gContestResources->field_0->mainTaskId].func = sub_80D80C8;
        gRngValue = gContestRngValue;
    }
}

u8 sub_80D7E44(u8 *a)
{
    u16 sp0[16];
    u16 sp20[16];

    switch (*a)
    {
        case 0:
            gPaletteFade.bufferTransferDisabled = TRUE;
            RequestDma3Fill(0, (void *)VRAM, 0x8000, 1);
            RequestDma3Fill(0, (void *)VRAM + 0x8000, 0x8000, 1);
            RequestDma3Fill(0, (void *)VRAM + 0x10000, 0x8000, 1);
            break;
        case 1:
            LZDecompressVram(gContestMiscGfx, (void *)VRAM);
            break;
        case 2:
            LZDecompressVram(gContestAudienceGfx, (void *)(VRAM + 0x2000));
            DmaCopyLarge32(3, (void *)(VRAM + 0x2000), shared15800, 0x2000, 0x1000);
            break;
        case 3:
            CopyToBgTilemapBuffer(3, gUnknown_08C16FA8, 0, 0);
            CopyBgTilemapBufferToVram(3);
            break;
        case 4:
            CopyToBgTilemapBuffer(2, gUnknown_08C17170, 0, 0);
            CopyBgTilemapBufferToVram(2);
            DmaCopy32Defvars(3, gContestResources->field_24[2], shared18000.unk18A04, 0x800);
            break;
        case 5:
            LoadCompressedPalette(gUnknown_08C16E90, 0, 0x200);
            CpuCopy32(gPlttBufferUnfaded + 128, sp0, 16 * sizeof(u16));
            CpuCopy32(gPlttBufferUnfaded + (5 + gContestPlayerMonIndex) * 16, sp20, 16 * sizeof(u16));
            CpuCopy32(sp20, gPlttBufferUnfaded + 128, 16 * sizeof(u16));
            CpuCopy32(sp0, gPlttBufferUnfaded + (5 + gContestPlayerMonIndex) * 16, 16 * sizeof(u16));
            DmaCopy32Defvars(3, gPlttBufferUnfaded, shared18000.unk18004, 0x200);
            sub_80D782C();
            break;
        case 6:
            sub_80DD04C();
            sub_80DBF90();
            sub_80DB2BC();
            gContestResources->field_0->unk19216 = sub_80DB120();
            sub_80DC2BC();
            sub_80DC4F0();
            sub_80DC594();
            sub_80DC5E8();
            sub_80DC7EC();
            gBattlerPositions[0] = 0;
            gBattlerPositions[1] = 1;
            gBattlerPositions[2] = 3;
            gBattlerPositions[3] = 2;
            gBattleTypeFlags = 0;
            gBattlerAttacker = 2;
            gBattlerTarget = 3;
            gBattlerSpriteIds[gBattlerAttacker] = sub_80DB0C4();
            sub_80DEA20();
            CopyBgTilemapBufferToVram(3);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(1);
            ShowBg(3);
            ShowBg(2);
            ShowBg(0);
            ShowBg(1);
            break;
        default:
            *a = 0;
            return 1;
    }

    (*a)++;
    return 0;
}

void sub_80D80C8(u8 taskId)
{
    gPaletteFade.bufferTransferDisabled = FALSE;
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = sub_80D8108;
    }
}


void sub_80D8108(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (gTasks[taskId].data[1]++ <= 60)
                break;
            gTasks[taskId].data[1] = 0;
            PlaySE12WithPanning(SE_C_MAKU_U, 0);
            gTasks[taskId].data[0]++;
            break;
        case 1:
            if ((gBattle_BG1_Y += 7) <= 160)
                break;
            gTasks[taskId].data[0]++;
            break;
        case 2:
            sub_80DE350();
            gTasks[taskId].data[0]++;
            break;
        case 3:
        {
            u16 bg0Cnt = GetGpuReg(REG_OFFSET_BG0CNT);
            u16 bg2Cnt = GetGpuReg(REG_OFFSET_BG2CNT);
            ((struct BgCnt *)&bg0Cnt)->priority = 0;
            ((struct BgCnt *)&bg2Cnt)->priority = 0;
            SetGpuReg(REG_OFFSET_BG0CNT, bg0Cnt);
            SetGpuReg(REG_OFFSET_BG2CNT, bg2Cnt);
            sub_80DDB0C();
            gTasks[taskId].data[0]++;
            break;
        }
        case 4:
        default:
            if (gContestResources->field_0->unk1920A_6)
                break;
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].func = sub_80D833C;
            break;
    }
}

void sub_80D823C(void)
{
    s32 i;

    AnimateSprites();
    RunTasks();
    BuildOamBuffer();
    UpdatePaletteFade();

    for (i = 0; i < 4; i++)
    {
        if ((sContestBgCopyFlags >> i) & 1)
            CopyBgTilemapBufferToVram(i);
    }
    sContestBgCopyFlags = 0;
}

void vblank_cb_battle(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
    SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

void sub_80D833C(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        gBattle_BG0_Y = 0;
        gBattle_BG2_Y = 0;
        sub_80DCD48();
        DmaCopy32Defvars(3, gPlttBufferUnfaded, shared18000.unk18204, 0x400);
        ConvertIntToDecimalStringN(gStringVar1, gContestResources->field_0->turnNumber + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
        if (!sub_80DBCA8(gContestPlayerMonIndex))
            StringCopy(gDisplayedStringBattle, gText_0827D507);
        else
            StringCopy(gDisplayedStringBattle, gText_0827D531);
        sub_80DB89C();
        StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
        sub_80DEC30(gStringVar4, 1);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!sub_80DED4C())
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = sub_80D8424;
        }
    }
}

void sub_80D8424(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys == B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (!sub_80DBCA8(gContestPlayerMonIndex))
        {
            sub_80DC490(TRUE);
            gTasks[taskId].func = sub_80D8490;
        }
        else
        {
            gTasks[taskId].func = sub_80D8894;
        }
    }
}

void sub_80D8490(u8 taskId)
{
    u8 i;
    u8 sp8[32];

    gBattle_BG0_Y = 0xA0;
    gBattle_BG2_Y = 0xA0;

    for (i = 0; i < 4; i++)
    {
        u16 move = gContestMons[gContestPlayerMonIndex].moves[i];
        u8 *r5 = sp8;

        if (gContestResources->field_4[gContestPlayerMonIndex].prevMove != MOVE_NONE
            && sub_80DE1E8(gContestPlayerMonIndex)
            && AreMovesContestCombo(gContestResources->field_4[gContestPlayerMonIndex].prevMove, move) != 0
            && gContestResources->field_4[gContestPlayerMonIndex].hasJudgesAttention)
        {
            r5 = StringCopy(sp8, gText_ColorLightShadowDarkGrey);
        }
        else if (move != 0
                 && gContestResources->field_4[gContestPlayerMonIndex].prevMove == move
                 && gContestMoves[move].effect != CONTEST_EFFECT_REPETITION_NOT_BORING)
        {
            // Gray the text because it is a repeated move
            r5 = StringCopy(sp8, gText_ColorBlue);
        }
        r5 = StringCopy(r5, gMoveNames[move]);

        FillWindowPixelBuffer(i + 5, 0);
        sub_80DEBD0(i + 5, sp8, 5, 1, 7);
    }

    sub_80D880C(gContestResources->field_0->playerMoveChoice);
    prints_contest_move_description(gContestMons[gContestPlayerMonIndex].moves[gContestResources->field_0->playerMoveChoice]);
    gTasks[taskId].func = sub_80D8610;
}

void sub_80D8610(u8 taskId)
{
    u8 numMoves = 0;
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gContestMons[gContestPlayerMonIndex].moves[i] != MOVE_NONE)
            numMoves++;
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = sub_80D8894;
    }
    else
    {
        switch (gMain.newAndRepeatedKeys)
        {
            case B_BUTTON:
                PlaySE(SE_SELECT);
                sub_80DC490(FALSE);
                ConvertIntToDecimalStringN(gStringVar1, gContestResources->field_0->turnNumber + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                if (!sub_80DBCA8(gContestPlayerMonIndex))
                    StringCopy(gDisplayedStringBattle, gText_0827D507);
                else
                    StringCopy(gDisplayedStringBattle, gText_0827D531);
                sub_80DB89C();
                StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
                sub_80DEC30(gStringVar4, 0);
                gBattle_BG0_Y = 0;
                gBattle_BG2_Y = 0;
                gTasks[taskId].func = sub_80D8424;
                break;
            case DPAD_LEFT:
            case DPAD_RIGHT:
                break;
            case DPAD_UP:
                sub_80D883C(gContestResources->field_0->playerMoveChoice);
                if (gContestResources->field_0->playerMoveChoice == 0)
                    gContestResources->field_0->playerMoveChoice = numMoves - 1;
                else
                    gContestResources->field_0->playerMoveChoice--;
                sub_80D880C(gContestResources->field_0->playerMoveChoice);
                prints_contest_move_description(gContestMons[gContestPlayerMonIndex].moves[gContestResources->field_0->playerMoveChoice]);
                if (numMoves > 1)
                    PlaySE(SE_SELECT);
                break;
            case DPAD_DOWN:
                sub_80D883C(gContestResources->field_0->playerMoveChoice);
                if (gContestResources->field_0->playerMoveChoice == numMoves - 1)
                    gContestResources->field_0->playerMoveChoice = 0;
                else
                    gContestResources->field_0->playerMoveChoice++;
                sub_80D880C(gContestResources->field_0->playerMoveChoice);
                prints_contest_move_description(gContestMons[gContestPlayerMonIndex].moves[gContestResources->field_0->playerMoveChoice]);
                if (numMoves > 1)
                    PlaySE(SE_SELECT);
                break;
        }
    }
}

void sub_80D880C(s8 a0)
{
    sub_80DECB8(2, 55, 0, 31 + a0 * 2, 2, 2, 17, 1);
}

void sub_80D883C(s8 a0)
{
    sub_80DECB8(2, 11, 0, 31 + a0 * 2, 2, 1, 17, 1);
    sub_80DECB8(2, 11, 0, 32 + a0 * 2, 2, 1, 17, 1);
}

void sub_80D8894(u8 taskId)
{
    if (gIsLinkContest & 1)
    {
        u16 var = sub_80DB8B8(gContestPlayerMonIndex);
        u8 taskId2;

        gContestResources->field_4[gContestPlayerMonIndex].currMove = var;
        taskId2 = CreateTask(sub_80FC9F8, 0);
        SetTaskFuncWithFollowupFunc(taskId2, sub_80FC9F8, sub_80D892C);
        gTasks[taskId].func = TaskDummy1;
        sub_80DBF68();
        sub_80DC490(FALSE);
    }
    else
    {
        sub_80DB918();
        gTasks[taskId].func = sub_80D895C;
    }
}

void sub_80D892C(u8 taskId)
{
    DestroyTask(taskId);
    gTasks[gContestResources->field_0->mainTaskId].func = sub_80D895C;
}

void sub_80D895C(u8 taskId)
{
    s32 i;

    sub_80DB89C();
    gBattle_BG0_Y = 0;
    gBattle_BG2_Y = 0;
    sub_80DC490(FALSE);

    for (i = 0; i < 4; i++)
    {
        FillWindowPixelBuffer(5 + i, 0);
        PutWindowTilemap(5 + i);
        CopyWindowToVram(5 + i, 2);
    }
    sub_80DED60(0);

    DmaCopy32Defvars(3, gPlttBufferFaded, shared18000.unk18604, 0x400);
    LoadPalette(shared18000.unk18204, 0, 0x400);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_80D8A04;
}

void sub_80D8A04(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 2)
    {
        gTasks[taskId].data[0] = 0;
        if (++gTasks[taskId].data[1] == 2)
        {
            sub_80DDBE8();
            sub_80DE69C(1);
            gTasks[taskId].func = sub_80D8A50;
        }
    }
}

void sub_80D8A50(u8 taskId)
{
    if (!gContestResources->field_0->unk1920A_6 && !gContestResources->field_0->unk1920B_1)
        gTasks[taskId].func = sub_80D8A88;
}

void sub_80D8A88(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 19)
    {
        gContestResources->field_0->unk19214 = 0;
        gContestResources->field_0->unk1921C = gRngValue;
        if ((gIsLinkContest & 1) && sub_80DA8A4())
        {
            s32 i;

            for (i = 0; i + gUnknown_02039F30 < 4; i++)
            {
                gContestResources->field_4[gUnknown_02039F30 + i].currMove = sub_80DB8B8(gUnknown_02039F30 + i);
            }
        }
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80D8B38;
    }
}
