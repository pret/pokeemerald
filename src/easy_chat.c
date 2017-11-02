
// Includes
#include "global.h"
#include "songs.h"
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

// Static type declarations

#define EZCHAT_TASK_STATE        0
#define EZCHAT_TASK_KIND        1
#define EZCHAT_TASK_WORDS        2
#define EZCHAT_TASK_MAINCALLBACK 4
#define EZCHAT_TASK_UNK06        6
#define EZCHAT_TASK_SIZE        7

// Static RAM declarations
static void sub_811A2C0(u8);
static void sub_811A278(void);
static bool8 sub_811A428(u8);
static void sub_811A2FC(u8);
/*static*/ void sub_811A4D0(MainCallback);
static bool32 sub_811A88C(u16);
static void sub_811A8A4(u16);
static void sub_811A8F0(void);
bool8 sub_811A95C(u8, u32, u8);
void sub_811AA90(void);
/*static*/ u16 sub_811AAAC(void);
bool8 sub_811BF8C(void);
bool8 sub_811BFA4(void);
void sub_811C13C(void);
/*static*/ void sub_811C158(u16);
/*static*/ bool8 sub_811C170(void);
bool8 sub_811F28C(void);
void sub_811F2B8(void);

// Static ROM declarations

// .rodata

extern const struct {
    u16 word;
    MainCallback callback;
} gUnknown_08597530[4];

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
            BlendPalettes(-1, 16, 0);
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
            if (!sub_811A95C(data[EZCHAT_TASK_KIND], GetWordTaskArg(taskId, EZCHAT_TASK_WORDS), data[EZCHAT_TASK_SIZE]))
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

void sub_811A4D0(MainCallback callback)
{
    sub_811C13C();
    sub_811AA90();
    sub_811F2B8();
    FreeAllWindowBuffers();
    SetMainCallback2(callback);
}

void easy_chat_input_maybe(void)
{
    int i;
    u16 *words;
    OldMan *oldMan;
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
            oldMan = &gSaveBlock1Ptr->oldMan;
            for (i = 0; i < 6; i ++)
            {
                oldMan->oldMan1.mauvilleOldMan_ecArray2[i] = oldMan->oldMan1.mauvilleOldMan_ecArray[i];
            }
            words = oldMan->oldMan1.mauvilleOldMan_ecArray2;
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
            words = gSaveBlock1Ptr->lilycoveLady.quiz.unk_016;
            break;
        case 16:
            return;
        case 17:
            words = gSaveBlock1Ptr->lilycoveLady.quiz.unk_002;
            break;
        case 18:
            words = gSaveBlock1Ptr->lilycoveLady.quiz.unk_014;
            break;
        case 19:
            words = gSaveBlock2Ptr->unk_104;
            break;
        case 20:
            words = sub_801B058();
            break;
        default:
            return;
    }
    overworld_free_bg_tilemaps();
    sub_811A20C(gSpecialVar_0x8004, words, sub_80861B0, sizeParam);
}

static void sub_811A7E4(void)
{
    LilycoveLady *lilycoveLady;

    UpdatePaletteFade();
    switch (gMain.state)
    {
        case 0:
            fade_screen(1, 0);
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                lilycoveLady = &gSaveBlock1Ptr->lilycoveLady;
                lilycoveLady->quiz.unk_016[0] = -1;
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
        {
            return i;
        }
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

static void sub_811A8CC(void)
{
    sub_811A20C(0xF, gSaveBlock1Ptr->lilycoveLady.quiz.unk_016, sub_80861B0, 3);
}

static void sub_811A8F0(void)
{
    sub_811A20C(0x10, gSaveBlock1Ptr->lilycoveLady.quiz.unk_002, sub_80861B0, 3);
}

static void sub_811A914(void)
{
    sub_811A20C(0x12, gSaveBlock1Ptr->lilycoveLady.quiz.unk_014, sub_80861B0, 3);
}

static void sub_811A938(void)
{
    sub_811A20C(0x11, gSaveBlock1Ptr->lilycoveLady.quiz.unk_002, sub_80861B0, 3);
}
