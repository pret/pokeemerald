
// Includes
#include "global.h"
#include "alloc.h"
#include "dewford_trend.h"
#include "dynamic_placeholder_text_util.h"
#include "easy_chat.h"
#include "event_data.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "window.h"
#include "constants/flags.h"
#include "constants/songs.h"

#define EZCHAT_TASK_STATE        0
#define EZCHAT_TASK_KIND         1
#define EZCHAT_TASK_WORDS        2
#define EZCHAT_TASK_MAINCALLBACK 4
#define EZCHAT_TASK_UNK06        6
#define EZCHAT_TASK_SIZE         7

struct EasyChatScreenTemplate
{
    u8 unk_00;
    u8 numColumns;
    u8 numRows;
    u8 unk_03_0:7;
    u8 unk_03_7:1;
    const u8 *titleText;
    const u8 *instructionsText1;
    const u8 *instructionsText2;
    const u8 *confirmText1;
    const u8 *confirmText2;
};

struct EasyChatScreen
{
    /*0x00*/ u8 kind;
    /*0x01*/ u8 templateId;
    /*0x02*/ u8 numColumns;
    /*0x03*/ u8 numRows;
    /*0x04*/ u8 state;
    /*0x05*/ s8 mainCursorColumn;
    /*0x06*/ s8 mainCursorRow;
    /*0x07*/ u8 unk_07;
    /*0x08*/ u8 unk_08;
    /*0x09*/ u8 unk_09;
    /*0x0A*/ s8 unk_0a;
    /*0x0B*/ s8 unk_0b;
    /*0x0C*/ u8 unk_0c;
    /*0x0D*/ u8 unk_0d;
    /*0x0E*/ u8 unk_0e;
    /*0x0F*/ u8 unk_0f;
    /*0x10*/ s8 unk_10;
    /*0x11*/ s8 unk_11;
    /*0x12*/ u8 sizeParam;
    /*0x13*/ u8 unk_13;
    /*0x14*/ u8 unk_14[0x20];
    /*0x34*/ const u8 *titleText;
    /*0x38*/ u16 *words;
    /*0x3C*/ u16 ecWordBuffer[9];
};

EWRAM_DATA struct EasyChatScreen *gEasyChatScreen = NULL;
EWRAM_DATA void *gUnknown_0203A11C = 0;
EWRAM_DATA void *gUnknown_0203A120 = 0;

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
static u16 sub_811ACDC(void);
static u16 sub_811AE44(void);
static u16 sub_811AF00(void);
static u16 sub_811AF8C(void);
static u16 sub_811AFEC(void);
static u16 sub_811B040(void);
static u16 sub_811B08C(void);
static u16 sub_811B0BC(void);
static u16 sub_811B0E8(void);
static u16 sub_811B0F8(void);
static u16 sub_811B150(void);
u16 sub_811B1B4(void);
u8 sub_811BA68(void);
static u8 sub_811BCC8(u8);
static void sub_811BDF0(u8 *);
void sub_811BF78(void);
static bool8 sub_811BF8C(void);
bool8 sub_811BFA4(void);
void sub_811C13C(void);
/*static*/ void sub_811C158(u16);
/*static*/ bool8 sub_811C170(void);
bool8 sub_811F28C(void);
void sub_811F2B8(void);
u8 sub_811F3AC(void);
int sub_811BA3C(void);
int sub_811B184(void);
int sub_811B264(void);
static int sub_811B32C(void);
static int sub_811B2B0(void);
static int sub_811B33C(void);
static int sub_811B368(void);
static u16 sub_811B528(int);
static u16 sub_811B794(u32);
static int sub_811B394(void);
static u8 sub_811B2A4(void);
static void sub_811B3E4(void);
static void sub_811BE9C(void);
static int sub_811B4EC(void);
static void sub_811B418(void);
static void sub_811B454(void);
static int sub_811BD64(void);
static int sub_811BDB0(void);
static int sub_811BD2C(void);
int sub_811BCF4(void);
static u16 sub_811B8E8(void);
int sub_811F3B8(u8);
void sub_811F548(int, u16);
static int sub_811B908(void);
u16 sub_811F5B0(void);
static void sub_811B488(u16);
u16 sub_811B940(void);
u16 sub_811F578(u16);
int sub_811BF88(int);
static u16 sub_811B8C8(void);
static int sub_811B568(u32);
static int sub_811B634(u32);
static int sub_811B6C4(u32);
static void sub_811B978(void);
static void sub_811B744(void);
static u8 sub_811B9C8(void);
static void sub_811B768(void);
static u8 sub_811B960(u8);
static void sub_811B9A0(void);
static u8 sub_811BA1C(void);
static int sub_811BF20(void);
static u16 sub_811BF40(void);
u8 sub_811CE94(void);
u8 *CopyEasyChatWordPadded(u8 *, u16, u16);

extern const struct {
    u16 word;
    MainCallback callback;
} gUnknown_08597530[4];

extern const struct EasyChatScreenTemplate gEasyChatScreenTemplates[21];
extern const u8 gUnknown_08597748[][7];
extern const u16 gUnknown_08597764[];
extern const u16 gUnknown_0859776C[][2];

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
    if (!IsUpdateLinkStateCBActive())
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
        words = GetSaveBlock1Field3564();
        break;
    default:
        return;
    }
    CleanupOverworldWindowsAndTilemaps();
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
            CleanupOverworldWindowsAndTilemaps();
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
    u8 templateId;
    int i;

    gEasyChatScreen = malloc(sizeof(*gEasyChatScreen));
    if (gEasyChatScreen == NULL)
    {
        return FALSE;
    }
    gEasyChatScreen->kind = kind;
    gEasyChatScreen->words = words;
    gEasyChatScreen->mainCursorColumn = 0;
    gEasyChatScreen->mainCursorRow = 0;
    gEasyChatScreen->unk_09 = 0;
    gEasyChatScreen->sizeParam = sizeParam;
    gEasyChatScreen->unk_13 = 0;
    templateId = sub_811BCC8(kind);
    if (kind == 0x10)
    {
        sub_811BDF0(gEasyChatScreen->unk_14);
        gEasyChatScreen->titleText = gEasyChatScreen->unk_14;
        gEasyChatScreen->state = 7;
    }
    else
    {
        gEasyChatScreen->state = 0;
        gEasyChatScreen->titleText = gEasyChatScreenTemplates[templateId].titleText;
    }
    gEasyChatScreen->numColumns = gEasyChatScreenTemplates[templateId].numColumns;
    gEasyChatScreen->numRows = gEasyChatScreenTemplates[templateId].numRows;
    gEasyChatScreen->unk_07 = gEasyChatScreen->numColumns * gEasyChatScreen->numRows;
    gEasyChatScreen->templateId = templateId;
    if (gEasyChatScreen->unk_07 > 9)
    {
        gEasyChatScreen->unk_07 = 9;
    }
    if (words != NULL)
    {
        CpuCopy16(words, gEasyChatScreen->ecWordBuffer, gEasyChatScreen->unk_07 * sizeof(u16));
    }
    else
    {
        for (i = 0; i < gEasyChatScreen->unk_07; i ++)
        {
            gEasyChatScreen->ecWordBuffer[i] = -1;
        }
        gEasyChatScreen->words = gEasyChatScreen->ecWordBuffer;
    }
    gEasyChatScreen->unk_0d = (sub_811F3AC() - 1) / 2 + 1;
    return TRUE;
}

static void EasyChat_FreeResources(void)
{
    if (gEasyChatScreen != NULL)
        FREE_AND_SET_NULL(gEasyChatScreen);
}

static u16 sub_811AAAC(void)
{
    switch (gEasyChatScreen->state)
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
        gEasyChatScreen->state = 2;
        gEasyChatScreen->unk_0a = 0;
        gEasyChatScreen->unk_0b = 0;
        gEasyChatScreen->unk_0c = 0;
        return 9;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        return sub_811B150();
    }
    else if (gMain.newKeys & START_BUTTON)
    {
        return sub_811B1B4();
    }
    else if (gMain.newKeys & DPAD_UP)
    {
        gEasyChatScreen->mainCursorRow--;
    }
    else if (gMain.newKeys & DPAD_LEFT)
    {
        gEasyChatScreen->mainCursorColumn--;
    }
    else if (gMain.newKeys & DPAD_DOWN)
    {
        gEasyChatScreen->mainCursorRow++;
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        gEasyChatScreen->mainCursorColumn++;
    }
    else
    {
        return 0;
    }
    
    if (gEasyChatScreen->mainCursorRow < 0)
        gEasyChatScreen->mainCursorRow = gEasyChatScreenTemplates[gEasyChatScreen->templateId].numRows;

    if (gEasyChatScreen->mainCursorRow > gEasyChatScreenTemplates[gEasyChatScreen->templateId].numRows)
        gEasyChatScreen->mainCursorRow = 0;

    if (gEasyChatScreen->mainCursorRow == gEasyChatScreenTemplates[gEasyChatScreen->templateId].numRows)
    {
        if (gEasyChatScreen->mainCursorColumn > 2)
            gEasyChatScreen->mainCursorColumn = 2;

        gEasyChatScreen->state = 1;
        return 3;
    }

    if (gEasyChatScreen->mainCursorColumn < 0)
        gEasyChatScreen->mainCursorColumn = gEasyChatScreenTemplates[gEasyChatScreen->templateId].numColumns - 1;

    if (gEasyChatScreen->mainCursorColumn >= gEasyChatScreenTemplates[gEasyChatScreen->templateId].numColumns)
        gEasyChatScreen->mainCursorColumn = 0;

    if (sub_811AB44() && gEasyChatScreen->mainCursorColumn == 1 && gEasyChatScreen->mainCursorRow == 4)
        gEasyChatScreen->mainCursorColumn = 0;

    return 2;
}
#else
NAKED
static u16 sub_811AB68(void)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    ldr r0, =gMain\n\
    ldrh r1, [r0, 0x2E]\n\
    movs r0, 0x1\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0811ABB8\n\
    bl sub_811BF78\n\
    ldr r1, =gEasyChatScreen\n\
    ldr r3, [r1]\n\
    movs r2, 0\n\
    movs r0, 0x2\n\
    strb r0, [r3, 0x4]\n\
    ldr r0, [r1]\n\
    strb r2, [r0, 0xA]\n\
    ldr r0, [r1]\n\
    strb r2, [r0, 0xB]\n\
    ldr r0, [r1]\n\
    strb r2, [r0, 0xC]\n\
    movs r0, 0x9\n\
    b RETURN\n\
    .pool\n\
_0811AB9C:\n\
    movs r0, 0x20\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0811AC68_dpad_left\n\
    movs r0, 0x80\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0811AC58_dpad_down\n\
    movs r0, 0x10\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0811AC48_dpad_right\n\
    movs r0, 0\n\
    b RETURN\n\
_0811ABB8:\n\
    movs r0, 0x2\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0811AC78_b_button\n\
    movs r0, 0x8\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0811AC7E_start_button\n\
    movs r0, 0x40\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0811AB9C\n\
    ldr r2, =gEasyChatScreen\n\
    ldr r1, [r2]\n\
    ldrb r0, [r1, 0x6]\n\
    subs r0, 0x1\n\
_0811ABD8:\n\
    strb r0, [r1, 0x6]\n\
_0811ABDA:\n\
    adds r7, r2, 0\n\
    adds r4, r7, 0\n\
    ldr r2, [r4]\n\
    movs r0, 0x6\n\
    ldrsb r0, [r2, r0]\n\
    ldr r6, =gEasyChatScreenTemplates\n\
    cmp r0, 0\n\
    bge _0811ABF8\n\
    ldrb r0, [r2, 0x1]\n\
    lsls r1, r0, 1\n\
    adds r1, r0\n\
    lsls r1, 3\n\
    adds r1, r6\n\
    ldrb r0, [r1, 0x2]\n\
    strb r0, [r2, 0x6]\n\
_0811ABF8:\n\
    ldr r3, [r4]\n\
    movs r2, 0x6\n\
    ldrsb r2, [r3, r2]\n\
    adds r5, r6, 0\n\
    ldrb r1, [r3, 0x1]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 3\n\
    adds r0, r5\n\
    ldrb r0, [r0, 0x2]\n\
    cmp r2, r0\n\
    ble _0811AC14\n\
    movs r0, 0\n\
    strb r0, [r3, 0x6]\n\
_0811AC14:\n\
    ldr r3, [r4]\n\
    movs r2, 0x6\n\
    ldrsb r2, [r3, r2]\n\
    ldrb r1, [r3, 0x1]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 3\n\
    adds r1, r0, r5\n\
    ldrb r0, [r1, 0x2]\n\
    cmp r2, r0\n\
    bne _0811AC88\n\
    movs r0, 0x5\n\
    ldrsb r0, [r3, r0]\n\
    cmp r0, 0x2\n\
    ble _0811AC36\n\
    movs r0, 0x2\n\
    strb r0, [r3, 0x5]\n\
_0811AC36:\n\
    ldr r1, [r4]\n\
    movs r0, 0x1\n\
    strb r0, [r1, 0x4]\n\
    movs r0, 0x3\n\
    b RETURN\n\
    .pool\n\
_0811AC48_dpad_right:\n\
    ldr r2, =gEasyChatScreen\n\
    ldr r1, [r2]\n\
    ldrb r0, [r1, 0x5]\n\
    adds r0, 0x1\n\
    strb r0, [r1, 0x5]\n\
    b _0811ABDA\n\
    .pool\n\
_0811AC58_dpad_down:\n\
    ldr r2, =gEasyChatScreen\n\
    ldr r1, [r2]\n\
    ldrb r0, [r1, 0x6]\n\
    adds r0, 0x1\n\
    b _0811ABD8\n\
    .pool\n\
_0811AC68_dpad_left:\n\
    ldr r2, =gEasyChatScreen\n\
    ldr r1, [r2]\n\
    ldrb r0, [r1, 0x5]\n\
    subs r0, 0x1\n\
    strb r0, [r1, 0x5]\n\
    b _0811ABDA\n\
    .pool\n\
_0811AC78_b_button:\n\
    bl sub_811B150\n\
    b _0811AC82\n\
_0811AC7E_start_button:\n\
    bl sub_811B1B4\n\
_0811AC82:\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    b RETURN\n\
_0811AC88:\n\
    movs r0, 0x5\n\
    ldrsb r0, [r3, r0]\n\
    cmp r0, 0\n\
    bge _0811AC96\n\
    ldrb r0, [r1, 0x1]\n\
    subs r0, 0x1\n\
    strb r0, [r3, 0x5]\n\
_0811AC96:\n\
    ldr r3, [r4]\n\
    movs r2, 0x5\n\
    ldrsb r2, [r3, r2]\n\
    ldrb r1, [r3, 0x1]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 3\n\
    adds r0, r6\n\
    ldrb r0, [r0, 0x1]\n\
    cmp r2, r0\n\
    blt _0811ACB0\n\
    movs r0, 0\n\
    strb r0, [r3, 0x5]\n\
_0811ACB0:\n\
    bl sub_811AB44\n\
    cmp r0, 0\n\
    beq _0811ACCA\n\
    ldr r2, [r7]\n\
    ldr r0, [r2, 0x4]\n\
    ldr r1, =0x00ffff00\n\
    ands r0, r1\n\
    ldr r1, =0x00040100\n\
    cmp r0, r1\n\
    bne _0811ACCA\n\
    movs r0, 0\n\
    strb r0, [r2, 0x5]\n\
_0811ACCA:\n\
    movs r0, 0x2\n\
RETURN:\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .pool");
}
#endif // NONMATCHING

#ifdef NONMATCHING
static u16 sub_811ACDC(void)
{
    int numFooterColumns;

    if (gMain.newKeys & A_BUTTON)
    {
        switch (gEasyChatScreen->mainCursorColumn)
        {
        case 0:
            return sub_811B184();
        case 1:
            return sub_811B150();
        case 2:
            return sub_811B1B4();
        case 3:
            return sub_811B264();
        }
    }

    if (gMain.newKeys & B_BUTTON)
        return sub_811B150();
    else if (gMain.newKeys & START_BUTTON)
        return sub_811B1B4();
    else if (gMain.newKeys & DPAD_UP)
        gEasyChatScreen->mainCursorRow--;
    else if (gMain.newKeys & DPAD_LEFT)
        gEasyChatScreen->mainCursorColumn--;
    else if (gMain.newKeys & DPAD_DOWN)
        gEasyChatScreen->mainCursorRow = 0;
    else if (gMain.newKeys & DPAD_RIGHT)
        gEasyChatScreen->mainCursorColumn++;
    else
        return 0;

    if (gEasyChatScreen->mainCursorRow == gEasyChatScreenTemplates[gEasyChatScreen->templateId].numRows)
    {
        numFooterColumns = sub_811BA3C() ? 4 : 3;
        if (gEasyChatScreen->mainCursorColumn < 0)
            gEasyChatScreen->mainCursorColumn = numFooterColumns - 1;

        if (gEasyChatScreen->mainCursorColumn >= numFooterColumns)
            gEasyChatScreen->mainCursorColumn = 0;

        return 3;
    }

    if (gEasyChatScreen->mainCursorColumn >= gEasyChatScreenTemplates[gEasyChatScreen->templateId].numColumns)
        gEasyChatScreen->mainCursorColumn = gEasyChatScreenTemplates[gEasyChatScreen->templateId].numColumns - 1;
    
    if (sub_811AB44() && gEasyChatScreen->mainCursorColumn == 1 && gEasyChatScreen->mainCursorRow == 4)
        gEasyChatScreen->mainCursorColumn = 0;

    gEasyChatScreen->state = 0;
    return 2;
}
#else
NAKED
static u16 sub_811ACDC(void)
{
    asm_unified("\n\
    push {r4-r6,lr}\n\
    ldr r2, =gMain\n\
    ldrh r1, [r2, 0x2E]\n\
    movs r0, 0x1\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _0811AD4A\n\
    ldr r0, =gEasyChatScreen\n\
    ldr r0, [r0]\n\
    ldrb r0, [r0, 0x5]\n\
    lsls r0, 24\n\
    asrs r0, 24\n\
    cmp r0, 0x1\n\
    beq _0811AD3E\n\
    b _0811AD24\n\
    .pool\n\
_0811AD04:\n\
    movs r0, 0x20\n\
    ands r0, r2\n\
    lsls r0, 16\n\
    lsrs r3, r0, 16\n\
    cmp r3, 0\n\
    bne _0811ADE0\n\
    movs r0, 0x80\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    bne _0811ADD0\n\
    movs r0, 0x10\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    bne _0811ADC0\n\
    movs r0, 0\n\
    b _0811AE32\n\
_0811AD24:\n\
    cmp r0, 0x1\n\
    bgt _0811AD2E\n\
    cmp r0, 0\n\
    beq _0811AD38\n\
    b _0811AD4A\n\
_0811AD2E:\n\
    cmp r0, 0x2\n\
    beq _0811ADF6\n\
    cmp r0, 0x3\n\
    beq _0811AD44\n\
    b _0811AD4A\n\
_0811AD38:\n\
    bl sub_811B184\n\
    b _0811ADFA\n\
_0811AD3E:\n\
    bl sub_811B150\n\
    b _0811ADFA\n\
_0811AD44:\n\
    bl sub_811B264\n\
    b _0811ADFA\n\
_0811AD4A:\n\
    ldrh r2, [r2, 0x2E]\n\
    movs r0, 0x2\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    bne _0811ADF0\n\
    movs r0, 0x8\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    bne _0811ADF6\n\
    movs r0, 0x40\n\
    ands r0, r2\n\
    cmp r0, 0\n\
    beq _0811AD04\n\
    ldr r2, =gEasyChatScreen\n\
    ldr r1, [r2]\n\
    ldrb r0, [r1, 0x6]\n\
    subs r0, 0x1\n\
    strb r0, [r1, 0x6]\n\
_0811AD6E:\n\
    adds r6, r2, 0\n\
_0811AD70:\n\
    adds r5, r6, 0\n\
    ldr r4, [r5]\n\
    movs r3, 0x6\n\
    ldrsb r3, [r4, r3]\n\
    ldr r2, =gEasyChatScreenTemplates\n\
    ldrb r1, [r4, 0x1]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 3\n\
    adds r1, r0, r2\n\
    ldrb r0, [r1, 0x2]\n\
    cmp r3, r0\n\
    bne _0811AE00\n\
    bl sub_811BA3C\n\
    movs r2, 0x3\n\
    cmp r0, 0\n\
    beq _0811AD96\n\
    movs r2, 0x4\n\
_0811AD96:\n\
    ldr r1, [r5]\n\
    movs r0, 0x5\n\
    ldrsb r0, [r1, r0]\n\
    cmp r0, 0\n\
    bge _0811ADA4\n\
    subs r0, r2, 0x1\n\
    strb r0, [r1, 0x5]\n\
_0811ADA4:\n\
    ldr r1, [r5]\n\
    movs r0, 0x5\n\
    ldrsb r0, [r1, r0]\n\
    cmp r0, r2\n\
    blt _0811ADB2\n\
    movs r0, 0\n\
    strb r0, [r1, 0x5]\n\
_0811ADB2:\n\
    movs r0, 0x3\n\
    b _0811AE32\n\
    .pool\n\
_0811ADC0:\n\
    ldr r2, =gEasyChatScreen\n\
    ldr r1, [r2]\n\
    ldrb r0, [r1, 0x5]\n\
    adds r0, 0x1\n\
    strb r0, [r1, 0x5]\n\
    b _0811AD6E\n\
    .pool\n\
_0811ADD0:\n\
    ldr r1, =gEasyChatScreen\n\
    ldr r0, [r1]\n\
    strb r3, [r0, 0x6]\n\
    adds r6, r1, 0\n\
    b _0811AD70\n\
    .pool\n\
_0811ADE0:\n\
    ldr r2, =gEasyChatScreen\n\
    ldr r1, [r2]\n\
    ldrb r0, [r1, 0x5]\n\
    subs r0, 0x1\n\
    strb r0, [r1, 0x5]\n\
    b _0811AD6E\n\
    .pool\n\
_0811ADF0:\n\
    bl sub_811B150\n\
    b _0811ADFA\n\
_0811ADF6:\n\
    bl sub_811B1B4\n\
_0811ADFA:\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    b _0811AE32\n\
_0811AE00:\n\
    movs r0, 0x5\n\
    ldrsb r0, [r4, r0]\n\
    ldrb r1, [r1, 0x1]\n\
    cmp r0, r1\n\
    blt _0811AE0E\n\
    subs r0, r1, 0x1\n\
    strb r0, [r4, 0x5]\n\
_0811AE0E:\n\
    bl sub_811AB44\n\
    cmp r0, 0\n\
    beq _0811AE28\n\
    ldr r2, [r6]\n\
    ldr r0, [r2, 0x4]\n\
    ldr r1, =0x00ffff00\n\
    ands r0, r1\n\
    ldr r1, =0x00040100\n\
    cmp r0, r1\n\
    bne _0811AE28\n\
    movs r0, 0\n\
    strb r0, [r2, 0x5]\n\
_0811AE28:\n\
    ldr r0, =gEasyChatScreen\n\
    ldr r1, [r0]\n\
    movs r0, 0\n\
    strb r0, [r1, 0x4]\n\
    movs r0, 0x2\n\
_0811AE32:\n\
    pop {r4-r6}\n\
    pop {r1}\n\
    bx r1\n\
    .pool");
}
#endif // NONMATCHING

static u16 sub_811AE44(void)
{
    if (gMain.newKeys & B_BUTTON)
        return sub_811B32C();

    if (gMain.newKeys & A_BUTTON)
    {
        if (gEasyChatScreen->unk_0a != -1)
            return sub_811B2B0();

        switch (gEasyChatScreen->unk_0b)
        {
        case 0:
            return sub_811B33C();
        case 1:
            return sub_811B368();
        case 2:
            return sub_811B32C();
        }
    }

    if (gMain.newKeys & SELECT_BUTTON)
        return sub_811B33C();

    if (gMain.newAndRepeatedKeys & DPAD_UP)
        return sub_811B528(2);

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        return sub_811B528(3);

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        return sub_811B528(1);

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        return sub_811B528(0);

    return 0;
}

static u16 sub_811AF00(void)
{
    if (gMain.newKeys & B_BUTTON)
    {
        gEasyChatScreen->state = 2;
        return 14;
    }

    if (gMain.newKeys & A_BUTTON)
        return sub_811B394();

    if (gMain.newKeys & START_BUTTON)
        return sub_811B794(4);

    if (gMain.newKeys & SELECT_BUTTON)
        return sub_811B794(5);

    if (gMain.newAndRepeatedKeys & DPAD_UP)
        return sub_811B794(2);

    if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        return sub_811B794(3);

    if (gMain.newAndRepeatedKeys & DPAD_LEFT)
        return sub_811B794(1);

    if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
        return sub_811B794(0);

    return 0;
}

static u16 sub_811AF8C(void)
{
    u8 var0;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_B_PRESSED: // B Button
    case 1: // No
        gEasyChatScreen->state = sub_811B2A4();
        return 7;
    case 0: // Yes
        gSpecialVar_Result = 0;
        var0 = gEasyChatScreen->kind - 17;
        if (var0 < 2)
            sub_811B3E4();

        return 24;
    default:
        return 0;
    }
}

static u16 sub_811AFEC(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_B_PRESSED: // B Button
    case 1: // No
        gEasyChatScreen->state = sub_811B2A4();
        return 7;
    case 0: // Yes
        sub_811BE9C();
        gSpecialVar_Result = sub_811B4EC();
        sub_811B3E4();
        return 24;
    default:
        return 0;
    }
}

static u16 sub_811B040(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_B_PRESSED: // B Button
    case 1: // No
        gEasyChatScreen->state = 1;
        return 7;
    case 0: // Yes
        sub_811B418();
        gEasyChatScreen->state = 1;
        return 8;
    default:
        return 0;
    }
}

static u16 sub_811B08C(void)
{
    if (gMain.newKeys & A_BUTTON)
        return 26;

    if (gMain.newKeys & B_BUTTON)
        return sub_811B150();

    return 0;
}

static u16 sub_811B0BC(void)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        gEasyChatScreen->state = sub_811B2A4();
        return 7;
    }

    return 0;
}

static u16 sub_811B0E8(void)
{
    gEasyChatScreen->state = 10;
    return 6;
}

static u16 sub_811B0F8(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_B_PRESSED: // B Button
    case 1: // No
        sub_811B454();
        gEasyChatScreen->unk_08 = 0;
        gEasyChatScreen->state = 8;
        return 31;
    case 0: // Yes
        gSpecialVar_Result = sub_811B4EC();
        sub_811B3E4();
        return 24;
    default:
        return 0;
    }
}

static u16 sub_811B150(void)
{
    if (gEasyChatScreen->kind == 19 || gEasyChatScreen->kind == 11)
    {
        gEasyChatScreen->unk_08 = gEasyChatScreen->state;
        gEasyChatScreen->state = 8;
        return 34;
    }
    else
    {
        gEasyChatScreen->unk_08 = gEasyChatScreen->state;
        gEasyChatScreen->state = 4;
        return 5;
    }
}

int sub_811B184(void)
{
    gEasyChatScreen->unk_08 = gEasyChatScreen->state;
    if (gEasyChatScreen->kind != 6)
    {
        gEasyChatScreen->state = 5;
        return 4;
    }
    else
    {
        gEasyChatScreen->unk_08 = gEasyChatScreen->state;
        gEasyChatScreen->state = 8;
        return 32;
    }
}

u16 sub_811B1B4(void)
{
    gEasyChatScreen->unk_08 = gEasyChatScreen->state;
    if (gEasyChatScreen->kind == 17)
    {
        if (sub_811BD64())
        {
            gEasyChatScreen->state = 8;
            return 29;
        }

        if (sub_811BDB0())
        {
            gEasyChatScreen->state = 8;
            return 30;
        }

        gEasyChatScreen->state = 6;
        return 6;
    }
    else if (gEasyChatScreen->kind == 18)
    {
        if (sub_811BDB0())
        {
            gEasyChatScreen->state = 8;
            return 30;
        }

        if (sub_811BD64())
        {
            gEasyChatScreen->state = 8;
            return 29;
        }

        gEasyChatScreen->state = 6;
        return 6;
    }
    else if (gEasyChatScreen->kind == 9 || gEasyChatScreen->kind == 13)
    {
        if (!sub_811BD2C())
        {
            gEasyChatScreen->state = 8;
            return 33;
        }

        gEasyChatScreen->state = 6;
        return 6;
    }
    else if (gEasyChatScreen->kind == 19 || gEasyChatScreen->kind == 11)
    {
        if (sub_811BCF4())
        {
            gEasyChatScreen->state = 8;
            return 34;
        }

        gEasyChatScreen->state = 6;
        return 6;
    }
    else if (gEasyChatScreen->kind == 20)
    {
        gEasyChatScreen->state = 6;
        return 6;
    }
    else
    {
        if (sub_811BCF4() == 1 || !sub_811B4EC())
        {
            gEasyChatScreen->state = 4;
            return 5;
        }

        gEasyChatScreen->state = 6;
        return 6;
    }
}

int sub_811B264(void)
{
    gEasyChatScreen->unk_08 = gEasyChatScreen->state;
    switch (gEasyChatScreen->kind)
    {
    case 15:
        return 25;
    case 17:
        sub_811B3E4();
        return 28;
    case 18:
        sub_811B3E4();
        return 27;
    default:
        return 0;
    }
}

static u8 sub_811B2A4(void)
{
    return gEasyChatScreen->unk_08;
}

static int sub_811B2B0(void)
{
    u16 var1;

    if (gEasyChatScreen->unk_09 == 0)
    {
        u8 var0 = sub_811F3B8(sub_811B8E8());
        sub_811F548(0, var0);
    }
    else
    {
        sub_811F548(1, sub_811B908());
    }

    var1 = sub_811F5B0();
    if (var1 == 0)
        return 0;
    
    gEasyChatScreen->unk_0f = (var1 - 1) / 2;
    gEasyChatScreen->unk_0e = 0;
    gEasyChatScreen->unk_10 = 0;
    gEasyChatScreen->unk_11 = 0;
    gEasyChatScreen->state = 3;
    return 11;
}

static int sub_811B32C(void)
{
    gEasyChatScreen->state = 0;
    return 10;
}

static int sub_811B33C(void)
{
    gEasyChatScreen->unk_0a = 0;
    gEasyChatScreen->unk_0b = 0;
    gEasyChatScreen->unk_0c = 0;
    if (!gEasyChatScreen->unk_09)
        gEasyChatScreen->unk_09 = 1;
    else
        gEasyChatScreen->unk_09 = 0;

    return 23;
}

static int sub_811B368(void)
{
    if (gEasyChatScreen->kind == 6)
    {
        PlaySE(SE_HAZURE);
        return 0;
    }
    else
    {
        sub_811B488(0xFFFF);
        return 1;
    }
}

static int sub_811B394(void)
{
    u16 easyChatWord = sub_811F578(sub_811B940());
    if (sub_811BF88(easyChatWord))
    {
        PlaySE(SE_HAZURE);
        return 0;
    }
    else
    {
        sub_811B488(easyChatWord);
        if (gEasyChatScreen->kind != 6)
        {
            gEasyChatScreen->state = 0;
            return 12;
        }
        else
        {
            gEasyChatScreen->state = 9;
            return 13;
        }
    }
}

static void sub_811B3E4(void)
{
    int i;
    for (i = 0; i < gEasyChatScreen->unk_07; i++)
        gEasyChatScreen->words[i] = gEasyChatScreen->ecWordBuffer[i];
}

static void sub_811B418(void)
{
    int i;
    for (i = 0; i < gEasyChatScreen->unk_07; i++)
        gEasyChatScreen->ecWordBuffer[i] = 0xFFFF;
}

static void sub_811B454(void)
{
    int i;
    for (i = 0; i < gEasyChatScreen->unk_07; i++)
        gEasyChatScreen->ecWordBuffer[i] = gEasyChatScreen->words[i];
}

static void sub_811B488(u16 easyChatWord)
{
    u16 index = sub_811B8C8();
    gEasyChatScreen->ecWordBuffer[index] = easyChatWord;
}

static u8 sub_811B4AC(void)
{
    u16 i;
    for (i = 0; i < gEasyChatScreen->unk_07; i++)
    {
        if (gEasyChatScreen->ecWordBuffer[i] != gEasyChatScreen->words[i])
            return 1;
    }

    return 0;
}

static int sub_811B4EC(void)
{
    u8 var0 = gEasyChatScreen->kind - 17;
    if (var0 < 2)
    {
        if (sub_811BD64())
            return 0;

        if (sub_811BDB0())
            return 0;

        return 1;
    }
    else
    {
        return sub_811B4AC();
    }
}

static u16 sub_811B528(int arg0)
{
    if (gEasyChatScreen->unk_0a != -1)
    {
        if (gEasyChatScreen->unk_09 == 0)
            return sub_811B568(arg0);
        else
            return sub_811B634(arg0);
    }
    else
    {
        return sub_811B6C4(arg0);
    }
}

static int sub_811B568(u32 arg0)
{
    switch (arg0)
    {
    case 2:
        if (gEasyChatScreen->unk_0b != -gEasyChatScreen->unk_0c)
        {
            if (gEasyChatScreen->unk_0b)
            {
                gEasyChatScreen->unk_0b--;
                return 15;
            }
            else
            {
                gEasyChatScreen->unk_0c--;
                return 17;
            }
        }
        break;
    case 3:
        if (gEasyChatScreen->unk_0b + gEasyChatScreen->unk_0c < gEasyChatScreen->unk_0d - 1)
        {
            int var0;
            if (gEasyChatScreen->unk_0b < 3)
            {
                gEasyChatScreen->unk_0b++;
                var0 = 15;
            }
            else
            {
                gEasyChatScreen->unk_0c++;
                var0 = 16;
            }

            sub_811B978();
            return var0;
        }
        break;
    case 1:
        if (gEasyChatScreen->unk_0a)
            gEasyChatScreen->unk_0a--;
        else
            sub_811B744();

        return 15;
    case 0:
        if (gEasyChatScreen->unk_0a < 1)
        {
            gEasyChatScreen->unk_0a++;
            if (sub_811B9C8())
                sub_811B744();
        }
        else
        {
            sub_811B744();
        }
        return 15;
    }

    return 0;
}

static int sub_811B634(u32 arg0)
{
    switch (arg0)
    {
    case 2:
        if (gEasyChatScreen->unk_0b > 0)
            gEasyChatScreen->unk_0b--;
        else
            gEasyChatScreen->unk_0b = 3;

        sub_811B978();
        return 15;
    case 3:
        if (gEasyChatScreen->unk_0b < 3)
            gEasyChatScreen->unk_0b++;
        else
            gEasyChatScreen->unk_0b = 0;

        sub_811B978();
        return 15;
    case 0:
        gEasyChatScreen->unk_0a++;
        if (sub_811B9C8())
            sub_811B744();

        return 15;
    case 1:
        gEasyChatScreen->unk_0a--;
        if (gEasyChatScreen->unk_0a < 0)
            sub_811B744();

        return 15;
    }

    return 0;
}

static int sub_811B6C4(u32 arg0)
{
    switch (arg0)
    {
    case 2:
        if (gEasyChatScreen->unk_0b)
            gEasyChatScreen->unk_0b--;
        else
            gEasyChatScreen->unk_0b = 2;

        return 15;
    case 3:
        if (gEasyChatScreen->unk_0b < 2)
            gEasyChatScreen->unk_0b++;
        else
            gEasyChatScreen->unk_0b = 0;

        return 15;
    case 1:
        gEasyChatScreen->unk_0b++;
        sub_811B768();
        return 15;
    case 0:
        gEasyChatScreen->unk_0a = 0;
        gEasyChatScreen->unk_0b++;
        return 15;
    }

    return 0;
}

static void sub_811B744(void)
{
    gEasyChatScreen->unk_0a = 0xFF;
    if (gEasyChatScreen->unk_0b)
        gEasyChatScreen->unk_0b--;
}

static void sub_811B768(void)
{
    if (gEasyChatScreen->unk_09 == 0)
    {
        gEasyChatScreen->unk_0a = 1;
        sub_811B978();
    }
    else
    {
        gEasyChatScreen->unk_0a = sub_811B960(gEasyChatScreen->unk_0b);
    }
}

static u16 sub_811B794(u32 arg0)
{
    u16 result;
    switch (arg0)
    {
    case 2:
        if (gEasyChatScreen->unk_11 + gEasyChatScreen->unk_0e > 0)
        {
            if (gEasyChatScreen->unk_11 > 0)
            {
                gEasyChatScreen->unk_11--;
                result = 18;
            }
            else
            {
                gEasyChatScreen->unk_0e--;
                result = 19;
            }

            sub_811B9A0();
            return result;
        }
        break;
    case 3:
        if (gEasyChatScreen->unk_11 + gEasyChatScreen->unk_0e < gEasyChatScreen->unk_0f)
        {
            if (gEasyChatScreen->unk_11 < 3)
            {
                gEasyChatScreen->unk_11++;
                result = 18;
            }
            else
            {
                gEasyChatScreen->unk_0e++;
                result = 20;
            }

            sub_811B9A0();
            return result;
        }
        break;
    case 1:
        if (gEasyChatScreen->unk_10 > 0)
            gEasyChatScreen->unk_10--;
        else
            gEasyChatScreen->unk_10 = 1;

        sub_811B9A0();
        return 18;
    case 0:
        if (gEasyChatScreen->unk_10 < 1)
        {
            gEasyChatScreen->unk_10++;
            if (sub_811BA1C())
                gEasyChatScreen->unk_10 = 0;
        }
        else
        {
            gEasyChatScreen->unk_10 = 0;
        }
        return 18;
    case 4:
        if (gEasyChatScreen->unk_0e)
        {
            if (gEasyChatScreen->unk_0e > 3)
                gEasyChatScreen->unk_0e -= 4;
            else
                gEasyChatScreen->unk_0e = 0;

            return 21;
        }
        break;
    case 5:
        if (gEasyChatScreen->unk_0e <= gEasyChatScreen->unk_0f - 4)
        {
            gEasyChatScreen->unk_0e += 4;
            if (gEasyChatScreen->unk_0e > gEasyChatScreen->unk_0f - 3)
                gEasyChatScreen->unk_0e = gEasyChatScreen->unk_0f + 0xFD;
            
            sub_811B9A0();
            return 22;
        }
        break;
    }

    return 0;
}

static u16 sub_811B8C8(void)
{
    return (gEasyChatScreen->mainCursorRow * gEasyChatScreen->numColumns) + gEasyChatScreen->mainCursorColumn;
}

static u16 sub_811B8E8(void)
{
    return 2 * (gEasyChatScreen->unk_0b + gEasyChatScreen->unk_0c) + gEasyChatScreen->unk_0a;
}

static int sub_811B908(void)
{
    int var0 = (u8)gEasyChatScreen->unk_0a < 7 ? gEasyChatScreen->unk_0a : 0;
    int var1 = (u8)gEasyChatScreen->unk_0b < 4 ? gEasyChatScreen->unk_0b : 0;
    return gUnknown_08597748[var1][var0];
}

u16 sub_811B940(void)
{
    return 2 * (gEasyChatScreen->unk_11 + gEasyChatScreen->unk_0e)  + gEasyChatScreen->unk_10;
}

static u8 sub_811B960(u8 arg0)
{
    switch (arg0)
    {
    case 0:
    default:
        return 6;
    case 1:
        return 5;
    }
}

static void sub_811B978(void)
{
    while (sub_811B9C8())
    {
        if (gEasyChatScreen->unk_0a)
            gEasyChatScreen->unk_0a--;
        else
            break;
    }
}

static void sub_811B9A0(void)
{
    while (sub_811BA1C())
    {
        if (gEasyChatScreen->unk_10)
            gEasyChatScreen->unk_10--;
        else
            break;
    }
}

static u8 sub_811B9C8(void)
{
    if (gEasyChatScreen->unk_09 == 0)
        return sub_811B8E8() >= sub_811F3AC() ? 1 : 0;
    else
        return gEasyChatScreen->unk_0a > sub_811B960(gEasyChatScreen->unk_0b) ? 1 : 0;
}

static u8 sub_811BA1C(void)
{
    return sub_811B940() >= sub_811F5B0() ? 1 : 0;
}

int sub_811BA3C(void)
{
    return gEasyChatScreenTemplates[gEasyChatScreen->templateId].unk_03_7;
}

u8 sub_811BA5C(void)
{
    return gEasyChatScreen->kind;
}

u8 sub_811BA68(void)
{
    return gEasyChatScreenTemplates[gEasyChatScreen->templateId].unk_03_0;
}

const u8 *sub_811BA88(void)
{
    return gEasyChatScreen->titleText;
}

u16 *sub_811BA94(void)
{
    return gEasyChatScreen->ecWordBuffer;
}

u8 sub_811BAA0(void)
{
    return gEasyChatScreen->numRows;
}

u8 sub_811BAAC(void)
{
    return gEasyChatScreen->numColumns;
}

u8 sub_811BAB8(void)
{
    return gEasyChatScreen->mainCursorColumn;
}

u8 sub_811BAC4(void)
{
    return gEasyChatScreen->mainCursorRow;
}

void sub_811BAD0(const u8 **str1, const u8 **str2)
{
    *str1 = gEasyChatScreenTemplates[gEasyChatScreen->templateId].instructionsText1;
    *str2 = gEasyChatScreenTemplates[gEasyChatScreen->templateId].instructionsText2;
}

void sub_811BB08(const u8 **str1, const u8 **str2)
{
    *str1 = gEasyChatScreenTemplates[gEasyChatScreen->templateId].confirmText1;
    *str2 = gEasyChatScreenTemplates[gEasyChatScreen->templateId].confirmText2;
}

void sub_811BB40(const u8 **str1, const u8 **str2)
{
    switch (gEasyChatScreen->kind)
    {
    case 4:
        *str1 = gText_StopGivingPkmnMail;
        *str2 = NULL;
        break;
    case 15:
    case 16:
        *str1 = gText_LikeToQuitQuiz;
        *str2 = gText_ChallengeQuestionMark;
        break;
    default:
        *str1 = gText_QuitEditing;
        *str2 = NULL;
        break;
    }

}

void sub_811BB88(const u8 **str1, const u8 **str2)
{
    *str1 = gText_AllTextBeingEditedWill;
    *str2 = gText_BeDeletedThatOkay;
}

void sub_811BB9C(u8 *arg0, u8 *arg1)
{
    *arg0 = gEasyChatScreen->unk_0a;
    *arg1 = gEasyChatScreen->unk_0b;
}

u8 sub_811BBB0(void)
{
    return gEasyChatScreen->unk_09;
}

u8 sub_811BBBC(void)
{
    return gEasyChatScreen->unk_0c;
}

void sub_811BBC8(u8 *arg0, u8 *arg1)
{
    *arg0 = gEasyChatScreen->unk_10;
    *arg1 = gEasyChatScreen->unk_11;
}

u8 sub_811BBDC(void)
{
    return gEasyChatScreen->unk_0e;
}

u8 sub_811BBE8(void)
{
    return gEasyChatScreen->unk_0f;
}

static u8 unref_sub_811BBF4(void)
{
    return 0;
}

int sub_811BBF8(void)
{
    switch (gEasyChatScreen->state)
    {
    case 2:
        if (gEasyChatScreen->unk_09 == 0 && gEasyChatScreen->unk_0c)
            return 1;
        break;
    case 3:
        if (gEasyChatScreen->unk_0e)
            return 1;
        break;
    }

    return 0;
}

int sub_811BC2C(void)
{
    switch (gEasyChatScreen->state)
    {
    case 2:
        if (gEasyChatScreen->unk_09 == 0 && gEasyChatScreen->unk_0c + 4 <= gEasyChatScreen->unk_0d - 1)
            return 1;
        break;
    case 3:
        if (gEasyChatScreen->unk_0e + 4 <= gEasyChatScreen->unk_0f)
            return 1;
        break;
    }

    return 0;
}

int sub_811BC70(void)
{
    return sub_811BA3C();
}

u8 sub_811BC7C(const u16 *arg0, u8 arg1)
{
    u8 i;

    for (i = 0; i < arg1; i++)
    {
        if (arg0[i] != gEasyChatScreen->ecWordBuffer[i])
            return 1;
    }

    return 0;
}

u8 sub_811BCBC(void)
{
    return gEasyChatScreen->sizeParam;
}

static u8 sub_811BCC8(u8 entryType)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(gEasyChatScreenTemplates); i++)
    {
        if (gEasyChatScreenTemplates[i].unk_00 == entryType)
            return i;
    }

    return 0;
}

int sub_811BCF4(void)
{
    int i;

    for (i = 0; i < gEasyChatScreen->unk_07; i++)
    {
        if (gEasyChatScreen->ecWordBuffer[i] != 0xFFFF)
            return 0;
    }

    return 1;
}

static int sub_811BD2C(void)
{
    int i;

    for (i = 0; i < gEasyChatScreen->unk_07; i++)
    {
        if (gEasyChatScreen->ecWordBuffer[i] == 0xFFFF)
            return 0;
    }

    return 1;
}

static int sub_811BD64(void)
{
    int i;
    struct SaveBlock1 *saveBlock1;

    if (gEasyChatScreen->kind == 17)
        return sub_811BCF4();
    
    saveBlock1 = gSaveBlock1Ptr;
    for (i = 0; i < 9; i++)
    {
        if (saveBlock1->lilycoveLady.quiz.unk_002[i] != 0xFFFF)
            return 0;
    }

    return 1;
}

static int sub_811BDB0(void)
{
    struct LilycoveLadyQuiz *quiz;
    if (gEasyChatScreen->kind == 18)
        return sub_811BCF4();

    quiz = &gSaveBlock1Ptr->lilycoveLady.quiz;
    return quiz->unk_014 == 0xFFFF ? 1 : 0;
}

static void sub_811BDF0(u8 *arg0)
{
    u8 name[32];
    struct SaveBlock1 *saveBlock1 = gSaveBlock1Ptr;
    DynamicPlaceholderTextUtil_Reset();
    if (StringLength(saveBlock1->lilycoveLady.quiz.playerName) != 0)
    {
        TVShowConvertInternationalString(name, saveBlock1->lilycoveLady.quiz.playerName, saveBlock1->lilycoveLady.quiz.language);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, name);
    }
    else
    {
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gText_Lady);
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(arg0, gText_F700sQuiz);
}

static void sub_811BE54(void)
{
    int i;
    u16 *ecWord;
    u8 *str;

    ecWord = gEasyChatScreen->ecWordBuffer;
    str = gStringVar2;
    i = 0;
    while (i < gEasyChatScreen->unk_07)
    {
        str = CopyEasyChatWordPadded(str, *ecWord, 0);
        *str = 0;
        str++;
        ecWord++;
        i++;
    }

    str--;
    str[0] = 0xFF;
}

static void sub_811BE9C(void)
{
    switch (gEasyChatScreen->kind)
    {
    case 0:
        FlagSet(FLAG_SYS_CHAT_USED);
        break;
    case 20:
        if (sub_811BF20())
            gSpecialVar_0x8004 = 2;
        else
            gSpecialVar_0x8004 = 0;
        break;
    case 9:
        sub_811BE54();
        gSpecialVar_0x8004 = sub_81226D8(gEasyChatScreen->ecWordBuffer);
        break;
    case 13:
        gSpecialVar_0x8004 = sub_811BF40();
        break;
    }
}

static int sub_811BF20(void)
{
    return sub_811BC7C(gUnknown_08597764, 4) == 0;
}

static u16 sub_811BF40(void)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (!sub_811BC7C(gUnknown_0859776C[i], 2))
            return i + 1;
    }

    return 0;
}

void sub_811BF78(void)
{
    gEasyChatScreen->unk_13 = 0;
}

int sub_811BF88(int easyChatWord)
{
    return 0;
}

static bool8 sub_811BF8C(void)
{
    if (!sub_811CE94())
        return 0; 
    else
        return 1;
}
