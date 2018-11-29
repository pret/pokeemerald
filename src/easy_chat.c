
// Includes
#include "global.h"
#include "alloc.h"
#include "constants/songs.h"
#include "sound.h"
#include "overworld.h"
#include "task.h"
#include "main.h"
#include "link.h"
#include "field_weather.h"
#include "window.h"
#include "palette.h"
#include "event_data.h"
#include "easy_chat.h"
#include "string_util.h"

// Static type declarations

#define EZCHAT_TASK_STATE        0
#define EZCHAT_TASK_KIND         1
#define EZCHAT_TASK_WORDS        2
#define EZCHAT_TASK_MAINCALLBACK 4
#define EZCHAT_TASK_UNK06        6
#define EZCHAT_TASK_SIZE         7

// Static RAM declarations

EWRAM_DATA struct
{
    u8 kind;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    s8 unk_05;
    s8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
    u8 unk_0c;
    u8 unk_0d;
    u8 unk_0e[0x4];
    u8 sizeParam;
    u8 unk_13;
    u8 unk_14[0x20];
    const u8 *src;
    const u16 *words;
    u16 ecWordBuffer[9];
} *gUnknown_0203A118 = NULL;

// Static ROM declarations

static void sub_811A2C0(u8);
static void sub_811A278(void);
static bool8 sub_811A428(u8);
static void sub_811A2FC(u8);
static void sub_811A4D0(MainCallback);
static bool32 sub_811A88C(u16);
static void sub_811A8A4(u16);
void sub_811A8F0(void);
static bool8 EasyChat_AllocateResources(u8, u16 *, u8);
static void EasyChat_FreeResources(void);
static u16 sub_811AAAC(void);
static u16 sub_811AB68(void);
u16 sub_811ACDC(void);
u16 sub_811AE44(void);
u16 sub_811AF00(void);
u16 sub_811AF8C(void);
u16 sub_811AFEC(void);
u16 sub_811B040(void);
u16 sub_811B08C(void);
u16 sub_811B0BC(void);
u16 sub_811B0E8(void);
u16 sub_811B0F8(void);
u16 sub_811B150(void);
u16 sub_811B1B4(void);
u8 sub_811BA68(void);
u8 sub_811BCC8(u8);
void sub_811BDF0(u8 *);
void sub_811BF78(void);
bool8 sub_811BF8C(void);
bool8 sub_811BFA4(void);
void sub_811C13C(void);
/*static*/ void sub_811C158(u16);
/*static*/ bool8 sub_811C170(void);
bool8 sub_811F28C(void);
void sub_811F2B8(void);
u8 sub_811F3AC(void);

// .rodata

extern const struct {
    u16 word;
    MainCallback callback;
} gUnknown_08597530[4];
extern const struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 *data;
    u8 filler_08[16];
} gUnknown_08597550[];

// .text

void sub_811A20C(u8 kind, u16 *words, MainCallback callback, u8 sizeParam)
{
    u8 taskId;

    ResetTasks();
    taskId = CreateTask(sub_811A2C0, 0);
    gTasks[taskId].data[EZCHAT_TASK_KIND] = kind;
    gTasks[taskId].data[EZCHAT_TASK_SIZE] = sizeParam;
    SetWordTaskArg(taskId, EZCHAT_TASK_WORDS, (u32)words);
    SetWordTaskArg(taskId, EZCHAT_TASK_MAINCALLBACK, (u32)callback);
    SetMainCallback2(sub_811A278);
}

static void sub_811A278(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_811A290(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void sub_811A2A4(u8 taskId, TaskFunc taskFunc)
{
    gTasks[taskId].func = taskFunc;
    gTasks[taskId].data[EZCHAT_TASK_STATE] = 0;
}

static void sub_811A2C0(u8 taskId)
{
    if (!is_c1_link_related_active())
    {
        while (sub_811A428(taskId));
    }
    else
    {
        if (sub_811A428(taskId) == TRUE)
        {
            return;
        }
    }
    sub_811A2A4(taskId, sub_811A2FC);
}

static void sub_811A2FC(u8 taskId)
{
    u16 v0;
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[EZCHAT_TASK_STATE])
    {
    case 0:
        SetVBlankCallback(sub_811A290);
        BlendPalettes(0xFFFFFFFF, 16, 0);
        BeginNormalPaletteFade(-1, -1, 16, 0, 0);
        data[EZCHAT_TASK_STATE] = 5;
        break;
    case 1:
        v0 = sub_811AAAC();
        if (sub_811A88C(v0))
        {
            BeginNormalPaletteFade(-1, -2, 0, 16, 0);
            data[EZCHAT_TASK_STATE] = 3;
            data[EZCHAT_TASK_UNK06] = v0;
        }
        else if (v0 == 0x18)
        {
            BeginNormalPaletteFade(-1, -1, 0, 16, 0);
            data[EZCHAT_TASK_STATE] = 4;
        }
        else if (v0 != 0)
        {
            PlaySE(SE_SELECT);
            sub_811C158(v0);
            data[EZCHAT_TASK_STATE] ++;
        }
        break;
    case 2:
        if (!sub_811C170())
        {
            data[EZCHAT_TASK_STATE] = 1;
        }
        break;
    case 3:
        if (!gPaletteFade.active)
        {
            sub_811A8A4(data[EZCHAT_TASK_UNK06]);
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            sub_811A4D0((MainCallback)GetWordTaskArg(taskId, EZCHAT_TASK_MAINCALLBACK));
        }
        break;
    case 5:
        if (!gPaletteFade.active)
        {
            data[EZCHAT_TASK_STATE] = 1;
        }
        break;
    }
}

static bool8 sub_811A428(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[EZCHAT_TASK_STATE])
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        break;
    case 1:
        if (!sub_811F28C())
        {
            sub_811A4D0((MainCallback)GetWordTaskArg(taskId, EZCHAT_TASK_MAINCALLBACK));
        }
        break;
    case 2:
        if (!EasyChat_AllocateResources(data[EZCHAT_TASK_KIND], (u16 *)GetWordTaskArg(taskId, EZCHAT_TASK_WORDS), data[EZCHAT_TASK_SIZE]))
        {
            sub_811A4D0((MainCallback)GetWordTaskArg(taskId, EZCHAT_TASK_MAINCALLBACK));
        }
        break;
    case 3:
        if (!sub_811BF8C())
        {
            sub_811A4D0((MainCallback)GetWordTaskArg(taskId, EZCHAT_TASK_MAINCALLBACK));
        }
        break;
    case 4:
        if (sub_811BFA4())
        {
            return TRUE;
        }
        break;
    default:
        return FALSE;
    }
    data[EZCHAT_TASK_STATE] ++;
    return TRUE;
}

static void sub_811A4D0(MainCallback callback)
{
    sub_811C13C();
    EasyChat_FreeResources();
    sub_811F2B8();
    FreeAllWindowBuffers();
    SetMainCallback2(callback);
}

void easy_chat_input_maybe(void)
{
    int i;
    u16 *words;
    struct MauvilleManBard *bard;
    u8 sizeParam = 3;
    switch (gSpecialVar_0x8004)
    {
    case 0:
        words = gSaveBlock1Ptr->unk2BB0;
        break;
    case 1:
        words = gSaveBlock1Ptr->unk2BBC;
        break;
    case 2:
        words = gSaveBlock1Ptr->unk2BC8;
        break;
    case 3:
        words = gSaveBlock1Ptr->unk2BD4;
        break;
    case 4:
        words = gSaveBlock1Ptr->mail[gSpecialVar_0x8005].words;
        break;
    case 6:
        bard = &gSaveBlock1Ptr->oldMan.bard;
        for (i = 0; i < 6; i ++)
        {
            bard->temporaryLyrics[i] = bard->songLyrics[i];
        }
        words = bard->temporaryLyrics;
        break;
    case 5:
        words = gSaveBlock1Ptr->tvShows[gSpecialVar_0x8005].bravoTrainer.words;
        sizeParam = gSpecialVar_0x8006;
        break;
    case 7:
        words = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8005].fanclubOpinions.words[gSpecialVar_0x8006];
        sizeParam = 1;
        break;
    case 8:
        words = gSaveBlock1Ptr->tvShows[gSpecialVar_0x8005].unkShow04.words;
        sizeParam = 0;
        break;
    case 9:
        words = (u16 *)gStringVar3;
        words[0] = gSaveBlock1Ptr->easyChatPairs[0].words[0];
        words[1] = gSaveBlock1Ptr->easyChatPairs[0].words[1];
        break;
    case 10:
        words = gSaveBlock1Ptr->gabbyAndTyData.quote;
        *words = -1;
        sizeParam = 1;
        break;
    case 11:
        words = &gSaveBlock1Ptr->tvShows[gSpecialVar_0x8005].bravoTrainer.words[gSpecialVar_0x8006];
        sizeParam = 0;
        break;
    case 12:
        words = gSaveBlock1Ptr->tvShows[gSpecialVar_0x8005].fanclubOpinions.words18;
        sizeParam = 1;
        break;
    case 13:
        words = (u16 *)gStringVar3;
        InitializeEasyChatWordArray(words, 2);
        break;
    case 14:
        words = gSaveBlock1Ptr->tvShows[gSpecialVar_0x8005].fanClubSpecial.words;
        words[0] = -1;
        sizeParam = 2;
        break;
    case 15:
        words = &gSaveBlock1Ptr->lilycoveLady.quiz.unk_016;
        break;
    case 16:
        return;
    case 17:
        words = gSaveBlock1Ptr->lilycoveLady.quiz.unk_002;
        break;
    case 18:
        words = &gSaveBlock1Ptr->lilycoveLady.quiz.unk_014;
        break;
    case 19:
        words = gSaveBlock2Ptr->apprentices[0].easyChatWords;
        break;
    case 20:
        words = sub_801B058();
        break;
    default:
        return;
    }
    overworld_free_bg_tilemaps();
    sub_811A20C(gSpecialVar_0x8004, words, CB2_ReturnToFieldContinueScript, sizeParam);
}

static void sub_811A7E4(void)
{
    LilycoveLady *lilycoveLady;

    UpdatePaletteFade();
    switch (gMain.state)
    {
    case 0:
        FadeScreen(1, 0);
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            lilycoveLady = &gSaveBlock1Ptr->lilycoveLady;
            lilycoveLady->quiz.unk_016 = -1;
            overworld_free_bg_tilemaps();
            sub_811A8F0();
        }
        return;
    }
    gMain.state ++;
}

void sub_811A858(void)
{
    SetMainCallback2(sub_811A7E4);
}

static int sub_811A868(u16 word)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_08597530); i ++)
    {
        if (word == gUnknown_08597530[i].word)
            return i;
    }
    return -1;
}

static bool32 sub_811A88C(u16 word)
{
    return sub_811A868(word) == -1 ? FALSE : TRUE;
}

static void sub_811A8A4(u16 word)
{
    int i;

    i = sub_811A868(word);
    ResetTasks();
    sub_811A4D0(gUnknown_08597530[i].callback);
}

void sub_811A8CC(void)
{
    sub_811A20C(0xF, &gSaveBlock1Ptr->lilycoveLady.quiz.unk_016, CB2_ReturnToFieldContinueScript, 3);
}

void sub_811A8F0(void)
{
    sub_811A20C(0x10, gSaveBlock1Ptr->lilycoveLady.quiz.unk_002, CB2_ReturnToFieldContinueScript, 3);
}

void sub_811A914(void)
{
    sub_811A20C(0x12, &gSaveBlock1Ptr->lilycoveLady.quiz.unk_014, CB2_ReturnToFieldContinueScript, 3);
}

void sub_811A938(void)
{
    sub_811A20C(0x11, gSaveBlock1Ptr->lilycoveLady.quiz.unk_002, CB2_ReturnToFieldContinueScript, 3);
}

static bool8 EasyChat_AllocateResources(u8 kind, u16 *words, u8 sizeParam)
{
    u8 r6;
    int i;

    gUnknown_0203A118 = malloc(sizeof(*gUnknown_0203A118));
    if (gUnknown_0203A118 == NULL)
    {
        return FALSE;
    }
    gUnknown_0203A118->kind = kind;
    gUnknown_0203A118->words = words;
    gUnknown_0203A118->unk_05 = 0;
    gUnknown_0203A118->unk_06 = 0;
    gUnknown_0203A118->unk_09 = 0;
    gUnknown_0203A118->sizeParam = sizeParam;
    gUnknown_0203A118->unk_13 = 0;
    r6 = sub_811BCC8(kind);
    if (kind == 0x10)
    {
        sub_811BDF0(gUnknown_0203A118->unk_14);
        gUnknown_0203A118->src = gUnknown_0203A118->unk_14;
        gUnknown_0203A118->unk_04 = 7;
    }
    else
    {
        gUnknown_0203A118->unk_04 = 0;
        gUnknown_0203A118->src = gUnknown_08597550[r6].data;
    }
    gUnknown_0203A118->unk_02 = gUnknown_08597550[r6].unk_01;
    gUnknown_0203A118->unk_03 = gUnknown_08597550[r6].unk_02;
    gUnknown_0203A118->unk_07 = gUnknown_0203A118->unk_02 * gUnknown_0203A118->unk_03;
    gUnknown_0203A118->unk_01 = r6;
    if (gUnknown_0203A118->unk_07 > 9)
    {
        gUnknown_0203A118->unk_07 = 9;
    }
    if (words != NULL)
    {
        CpuCopy16(words, gUnknown_0203A118->ecWordBuffer, gUnknown_0203A118->unk_07 * sizeof(u16));
    }
    else
    {
        for (i = 0; i < gUnknown_0203A118->unk_07; i ++)
        {
            gUnknown_0203A118->ecWordBuffer[i] = -1;
        }
        gUnknown_0203A118->words = gUnknown_0203A118->ecWordBuffer;
    }
    gUnknown_0203A118->unk_0d = (sub_811F3AC() - 1) / 2 + 1;
    return TRUE;
}

static void EasyChat_FreeResources(void)
{
    if (gUnknown_0203A118 != NULL)
        FREE_AND_SET_NULL(gUnknown_0203A118);
}

static u16 sub_811AAAC(void)
{
    switch (gUnknown_0203A118->unk_04)
    {
    case 0:
        return sub_811AB68();
    case 1:
        return sub_811ACDC();
    case 2:
        return sub_811AE44();
    case 3:
        return sub_811AF00();
    case 4:
        return sub_811AF8C();
    case 5:
        return sub_811B040();
    case 6:
        return sub_811AFEC();
    case 7:
        return sub_811B08C();
    case 8:
        return sub_811B0BC();
    case 9:
        return sub_811B0E8();
    case 10:
        return sub_811B0F8();
    }
    return 0;
}

bool32 sub_811AB44(void)
{
    switch (sub_811BA68())
    {
    case 2:
    case 7:
    case 8:
        return TRUE;
    }
    return FALSE;
}

#ifdef NONMATCHING
static u16 sub_811AB68(void)
{
    if (gMain.newKeys & A_BUTTON)
    {
        sub_811BF78();
        gUnknown_0203A118->unk_04 = 2;
        gUnknown_0203A118->unk_0a = 0;
        gUnknown_0203A118->unk_0b = 0;
        gUnknown_0203A118->unk_0c = 0;
        return 9;
    }
    else if (gMain.newKeys & B_BUTTON)
    { // FIXME: See note below
        return sub_811B150();
    }
    else if (gMain.newKeys & START_BUTTON)
    { // FIXME: See note below
        return sub_811B1B4();
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        gUnknown_0203A118->unk_06--;
    }
    else if (gMain.newKeys & DPAD_LEFT)
    { // FIXME: See note below
        gUnknown_0203A118->unk_05--;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    { // FIXME: See note below
        gUnknown_0203A118->unk_06++;
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    { // FIXME: See note below
        gUnknown_0203A118->unk_05++;
    }
    else
    {
        return 0;
    }
    if (gUnknown_0203A118->unk_06 < 0)
    {
        gUnknown_0203A118->unk_06 = gUnknown_08597550[gUnknown_0203A118->unk_01].unk_02;
    }
    if (gUnknown_0203A118->unk_06 > gUnknown_08597550[gUnknown_0203A118->unk_01].unk_02)
    {
        gUnknown_0203A118->unk_06 = 0;
    }
    if (gUnknown_0203A118->unk_06 == gUnknown_08597550[gUnknown_0203A118->unk_01].unk_02)
    {
        if (gUnknown_0203A118->unk_05 > 2)
        {
            gUnknown_0203A118->unk_05 = 2;
        }
        gUnknown_0203A118->unk_04 = 1;
        return 3;
    }
    /*
     * FIXME: right, down, left, b, and start
     * should be inserted here, but aren't
     */
    if (gUnknown_0203A118->unk_05 < 0)
    {
        gUnknown_0203A118->unk_05 = gUnknown_08597550[gUnknown_0203A118->unk_01].unk_01 - 1;
    }
    if (gUnknown_0203A118->unk_05 >= gUnknown_08597550[gUnknown_0203A118->unk_01].unk_01)
    {
        gUnknown_0203A118->unk_05 = 0;
    }
    if (sub_811AB44() && gUnknown_0203A118->unk_05 == 1 && gUnknown_0203A118->unk_06 == 4)
    {
        gUnknown_0203A118->unk_05 = 0;
    }
    return 2;
}
#else
__attribute__((naked)) static u16 sub_811AB68(void)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tldr r0, =gMain\n"
                    "\tldrh r1, [r0, 0x2E]\n"
                    "\tmovs r0, 0x1\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0811ABB8\n"
                    "\tbl sub_811BF78\n"
                    "\tldr r1, =gUnknown_0203A118\n"
                    "\tldr r3, [r1]\n"
                    "\tmovs r2, 0\n"
                    "\tmovs r0, 0x2\n"
                    "\tstrb r0, [r3, 0x4]\n"
                    "\tldr r0, [r1]\n"
                    "\tstrb r2, [r0, 0xA]\n"
                    "\tldr r0, [r1]\n"
                    "\tstrb r2, [r0, 0xB]\n"
                    "\tldr r0, [r1]\n"
                    "\tstrb r2, [r0, 0xC]\n"
                    "\tmovs r0, 0x9\n"
                    "\tb _0811ACCC_return_r0\n"
                    "\t.pool\n"
                    "_0811AB9C:\n"
                    "\tmovs r0, 0x20\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0811AC68_dpad_left\n"
                    "\tmovs r0, 0x80\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0811AC58_dpad_down\n"
                    "\tmovs r0, 0x10\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0811AC48_dpad_right\n"
                    "\tmovs r0, 0\n"
                    "\tb _0811ACCC_return_r0\n"
                    "_0811ABB8:\n"
                    "\tmovs r0, 0x2\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0811AC78_b_button\n"
                    "\tmovs r0, 0x8\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbne _0811AC7E_start_button\n"
                    "\tmovs r0, 0x40\n"
                    "\tands r0, r1\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0811AB9C\n"
                    "\tldr r2, =gUnknown_0203A118\n"
                    "\tldr r1, [r2]\n"
                    "\tldrb r0, [r1, 0x6]\n"
                    "\tsubs r0, 0x1\n"
                    "_0811ABD8:\n"
                    "\tstrb r0, [r1, 0x6]\n"
                    "_0811ABDA:\n"
                    "\tadds r7, r2, 0\n"
                    "\tadds r4, r7, 0\n"
                    "\tldr r2, [r4]\n"
                    "\tmovs r0, 0x6\n"
                    "\tldrsb r0, [r2, r0]\n"
                    "\tldr r6, =gUnknown_08597550\n"
                    "\tcmp r0, 0\n"
                    "\tbge _0811ABF8\n"
                    "\tldrb r0, [r2, 0x1]\n"
                    "\tlsls r1, r0, 1\n"
                    "\tadds r1, r0\n"
                    "\tlsls r1, 3\n"
                    "\tadds r1, r6\n"
                    "\tldrb r0, [r1, 0x2]\n"
                    "\tstrb r0, [r2, 0x6]\n"
                    "_0811ABF8:\n"
                    "\tldr r3, [r4]\n"
                    "\tmovs r2, 0x6\n"
                    "\tldrsb r2, [r3, r2]\n"
                    "\tadds r5, r6, 0\n"
                    "\tldrb r1, [r3, 0x1]\n"
                    "\tlsls r0, r1, 1\n"
                    "\tadds r0, r1\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r5\n"
                    "\tldrb r0, [r0, 0x2]\n"
                    "\tcmp r2, r0\n"
                    "\tble _0811AC14\n"
                    "\tmovs r0, 0\n"
                    "\tstrb r0, [r3, 0x6]\n"
                    "_0811AC14:\n"
                    "\tldr r3, [r4]\n"
                    "\tmovs r2, 0x6\n"
                    "\tldrsb r2, [r3, r2]\n"
                    "\tldrb r1, [r3, 0x1]\n"
                    "\tlsls r0, r1, 1\n"
                    "\tadds r0, r1\n"
                    "\tlsls r0, 3\n"
                    "\tadds r1, r0, r5\n"
                    "\tldrb r0, [r1, 0x2]\n"
                    "\tcmp r2, r0\n"
                    "\tbne _0811AC88\n"
                    "\tmovs r0, 0x5\n"
                    "\tldrsb r0, [r3, r0]\n"
                    "\tcmp r0, 0x2\n"
                    "\tble _0811AC36\n"
                    "\tmovs r0, 0x2\n"
                    "\tstrb r0, [r3, 0x5]\n"
                    "_0811AC36:\n"
                    "\tldr r1, [r4]\n"
                    "\tmovs r0, 0x1\n"
                    "\tstrb r0, [r1, 0x4]\n"
                    "\tmovs r0, 0x3\n"
                    "\tb _0811ACCC_return_r0\n"
                    "\t.pool\n"
                    "_0811AC48_dpad_right:\n"
                    "\tldr r2, =gUnknown_0203A118\n"
                    "\tldr r1, [r2]\n"
                    "\tldrb r0, [r1, 0x5]\n"
                    "\tadds r0, 0x1\n"
                    "\tstrb r0, [r1, 0x5]\n"
                    "\tb _0811ABDA\n"
                    "\t.pool\n"
                    "_0811AC58_dpad_down:\n"
                    "\tldr r2, =gUnknown_0203A118\n"
                    "\tldr r1, [r2]\n"
                    "\tldrb r0, [r1, 0x6]\n"
                    "\tadds r0, 0x1\n"
                    "\tb _0811ABD8\n"
                    "\t.pool\n"
                    "_0811AC68_dpad_left:\n"
                    "\tldr r2, =gUnknown_0203A118\n"
                    "\tldr r1, [r2]\n"
                    "\tldrb r0, [r1, 0x5]\n"
                    "\tsubs r0, 0x1\n"
                    "\tstrb r0, [r1, 0x5]\n"
                    "\tb _0811ABDA\n"
                    "\t.pool\n"
                    "_0811AC78_b_button:\n"
                    "\tbl sub_811B150\n"
                    "\tb _0811AC82\n"
                    "_0811AC7E_start_button:\n"
                    "\tbl sub_811B1B4\n"
                    "_0811AC82:\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tb _0811ACCC_return_r0\n"
                    "_0811AC88:\n"
                    "\tmovs r0, 0x5\n"
                    "\tldrsb r0, [r3, r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbge _0811AC96\n"
                    "\tldrb r0, [r1, 0x1]\n"
                    "\tsubs r0, 0x1\n"
                    "\tstrb r0, [r3, 0x5]\n"
                    "_0811AC96:\n"
                    "\tldr r3, [r4]\n"
                    "\tmovs r2, 0x5\n"
                    "\tldrsb r2, [r3, r2]\n"
                    "\tldrb r1, [r3, 0x1]\n"
                    "\tlsls r0, r1, 1\n"
                    "\tadds r0, r1\n"
                    "\tlsls r0, 3\n"
                    "\tadds r0, r6\n"
                    "\tldrb r0, [r0, 0x1]\n"
                    "\tcmp r2, r0\n"
                    "\tblt _0811ACB0\n"
                    "\tmovs r0, 0\n"
                    "\tstrb r0, [r3, 0x5]\n"
                    "_0811ACB0:\n"
                    "\tbl sub_811AB44\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _0811ACCA\n"
                    "\tldr r2, [r7]\n"
                    "\tldr r0, [r2, 0x4]\n"
                    "\tldr r1, =0x00ffff00\n"
                    "\tands r0, r1\n"
                    "\tldr r1, =0x00040100\n"
                    "\tcmp r0, r1\n"
                    "\tbne _0811ACCA\n"
                    "\tmovs r0, 0\n"
                    "\tstrb r0, [r2, 0x5]\n"
                    "_0811ACCA:\n"
                    "\tmovs r0, 0x2\n"
                    "_0811ACCC_return_r0:\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r1}\n"
                    "\tbx r1\n"
                    "\t.pool");
}
#endif
