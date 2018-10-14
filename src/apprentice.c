#include "global.h"
#include "apprentice.h"
#include "constants/apprentice.h"
#include "string_util.h"
#include "script.h"
#include "text.h"
#include "random.h"
#include "main.h"
#include "malloc.h"
#include "strings.h"
#include "menu.h"
#include "script_menu.h"
#include "party_menu.h"
#include "item_menu.h"
#include "data2.h"
#include "task.h"
#include "item.h"
#include "sound.h"
#include "battle_tower.h"
#include "event_data.h"
#include "international_string_util.h"
#include "field_player_avatar.h"
#include "new_game.h"
#include "event_object_movement.h"
#include "constants/items.h"
#include "constants/songs.h"

#define PLAYER_APPRENTICE gSaveBlock2Ptr->playerApprentice

struct Unk030062ECStruct
{
    u8 unk0;
    u16 unk2[3][5];
    u8 unk20[3][5];
};

struct Unk030062F0Struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
};

extern struct Unk030062ECStruct *gUnknown_030062EC;
extern struct Unk030062F0Struct *gUnknown_030062F0;
extern void (*gUnknown_030062F4)(void);

extern void sub_8165AE8(struct Apprentice *);

extern const u8 *const gUnknown_08611330[];
extern const u8 *const gUnknown_08610FF0[][2];
extern const u8 *const gUnknown_086112B0[][2];
extern const u8 *const gUnknown_08611230[][2];
extern const u8 *const gUnknown_086111B0[][2];
extern const u8 *const gUnknown_08610EF0[][4];
extern const u8 *const gUnknown_08611070[][5];
extern const u8 gUnknown_08611548[8];
extern const u8 gUnknown_086114D3[];
extern const bool8 gUnknown_08611370[];
extern void (* const gUnknown_086114E0[])(void);

extern const u8 gUnknown_085DCEDC[];
extern const u8 gUnknown_085DCF0E[];
extern const u8 gUnknown_085DCEFA[];
extern const u8 gUnknown_085DCF2C[];

// text
extern const u8 gText_Give[];
extern const u8 gText_NoNeed[];
extern const u8 gText_Yes[];
extern const u8 gText_No[];

// This file's functions.
void sub_81A087C(void);
static u16 sub_819FF98(u8 arg0);
static bool8 sub_81A0194(u8 arg0, u16 moveId);
static void CreateChooseAnswerTask(bool8 noBButton, u8 itemsCount, u8 windowId);
static u8 CreateAndShowWindow(u8 left, u8 top, u8 width, u8 height);
static void RemoveAndHideWindow(u8 windowId);
static void ExecuteFuncAfterButtonPress(void (*func)(void));

void CopyFriendsApprenticeChallengeText(u8 saveblockApprenticeId)
{
    u8 i, var;
    const u8 *str;

    var = gSaveBlock2Ptr->apprentices[saveblockApprenticeId].number;
    for (i = 0; var != 0 && i < 4; var /= 10, i++)
        ;

    StringCopy7(gStringVar1, gSaveBlock2Ptr->apprentices[saveblockApprenticeId].playerName);
    ConvertInternationalString(gStringVar1, gSaveBlock2Ptr->apprentices[saveblockApprenticeId].language);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->apprentices[saveblockApprenticeId].number, STR_CONV_MODE_RIGHT_ALIGN, i);
    str = gUnknown_08611330[gSaveBlock2Ptr->apprentices[saveblockApprenticeId].id];
    StringExpandPlaceholders(gStringVar4, str);
}

void sub_819FA50(void)
{
    EnableBothScriptContexts();
}

void sub_819FA5C(struct Apprentice *apprentice)
{
    u8 i;

    for (i = 0; i < 6; i++)
        apprentice->easyChatWords[i] |= 0xFFFF;

    apprentice->playerName[0] = EOS;
    apprentice->id = 16;
}

void sub_819FAA0(void)
{
    u8 i, j;

    PLAYER_APPRENTICE.field_B2_1 = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
            gSaveBlock2Ptr->apprentices[i].easyChatWords[j] |= 0xFFFF;
        gSaveBlock2Ptr->apprentices[i].id = 16;
        gSaveBlock2Ptr->apprentices[i].playerName[0] = EOS;
        gSaveBlock2Ptr->apprentices[i].lvlMode = 0;
        gSaveBlock2Ptr->apprentices[i].number = 0;
        gSaveBlock2Ptr->apprentices[i].field_1 = 0;
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->apprentices[i].playerId[j] = 0;
        gSaveBlock2Ptr->apprentices[i].language = gGameLanguage;
        gSaveBlock2Ptr->apprentices[i].unk40 = 0;
    }

    sub_81A087C();
}

static bool8 IsPlayersApprenticeActive(void)
{
    return (PLAYER_APPRENTICE.activeLvlMode != 0);
}

void sub_819FBC8(void)
{
    if (gSaveBlock2Ptr->apprentices[0].number == 0)
    {
        do
        {
            PLAYER_APPRENTICE.id = gUnknown_08611548[Random() % ARRAY_COUNT(gUnknown_08611548)];
        } while (PLAYER_APPRENTICE.id == gSaveBlock2Ptr->apprentices[0].id);
    }
    else
    {
        do
        {
            PLAYER_APPRENTICE.id = Random() % 16;
        } while (PLAYER_APPRENTICE.id == gSaveBlock2Ptr->apprentices[0].id);
    }
}

static void SetPlayersApprenticeLvlMode(u8 mode)
{
    PLAYER_APPRENTICE.activeLvlMode = mode;
}

void sub_819FC60(void)
{
    u8 array[APPRENTICE_SPECIES_COUNT];
    u8 i;

    for (i = 0; i < ARRAY_COUNT(array); i++)
        array[i] = i;

    for (i = 0; i < 50; i++)
    {
        u8 temp;
        u8 var1 = Random() % ARRAY_COUNT(array);
        u8 var2 = Random() % ARRAY_COUNT(array);
        SWAP(array[var1], array[var2], temp);
    }

    for (i = 0; i < 3; i++)
        PLAYER_APPRENTICE.monIds[i] = ((array[i * 2] & 0xF) << 4) | ((array[i * 2 + 1]) & 0xF);
}

u8 sub_819FCF8(u8 val, u8 *arg1, u8 *arg2)
{
    u8 i, count;
    u8 ret = 0;

    if (val == 2)
    {
        do
        {
            ret = Random() % 3;
            for (count = 0, i = 0; i < 5; i++)
            {
                if (gUnknown_030062EC->unk2[ret][i] != 0)
                    count++;
            }
        } while (count > 3);
    }
    else if (val == 1)
    {
        ret = arg1[*arg2];
        (*arg2)++;
    }

    return ret;
}

void sub_819FD64(void)
{
    u8 sp_0[10];
    u8 sp_C[3];
    u8 sp_10;
    u8 i, j;
    u8 rand1, rand2;
    u8 id;

    for (i = 0; i < 3; i++)
        sp_C[i] = i;
    for (i = 0; i < 10; i++)
    {
        u8 temp;
        rand1 = Random() % ARRAY_COUNT(sp_C);
        rand2 = Random() % ARRAY_COUNT(sp_C);
        SWAP(sp_C[rand1], sp_C[rand2], temp);
    }

    for (i = 0; i < 10; i++)
        sp_0[i] = gUnknown_086114D3[i];
    for (i = 0; i < 50; i++)
    {
        u8 temp;
        rand1 = Random() % ARRAY_COUNT(sp_0);
        rand2 = Random() % ARRAY_COUNT(sp_0);
        SWAP(sp_0[rand1], sp_0[rand2], temp);
    }

    gUnknown_030062EC = AllocZeroed(sizeof(*gUnknown_030062EC));
    gUnknown_030062EC->unk0 = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
            gUnknown_030062EC->unk20[j][i] = 4;
    }

    sp_10 = 0;
    for (i = 0; i < 9; i++)
    {
        PLAYER_APPRENTICE.field_B8[i].unk0_0 = sp_0[i];
        if (sp_0[i] != 3)
        {
            PLAYER_APPRENTICE.field_B8[i].unk0_1 = sub_819FCF8(sp_0[i], sp_C, &sp_10);
            id = PLAYER_APPRENTICE.field_B8[i].unk0_1;
            if (sp_0[i] == 2)
            {
                do
                {
                    rand1 = Random() % 4;
                    for (j = 0; j < gUnknown_030062EC->unk0 + 1; j++)
                    {
                        if (gUnknown_030062EC->unk20[id][j] == rand1)
                            break;
                    }
                } while (j != gUnknown_030062EC->unk0 + 1);

                gUnknown_030062EC->unk20[id][gUnknown_030062EC->unk0] = rand1;
                PLAYER_APPRENTICE.field_B8[i].unk0_2 = rand1;
                PLAYER_APPRENTICE.field_B8[i].unk2 = sub_819FF98(PLAYER_APPRENTICE.field_B8[i].unk0_1);
            }
        }
    }

    FREE_AND_SET_NULL(gUnknown_030062EC);
}

// No idea why a do-while loop is needed, but it will not match without it.

#define APPRENTICE_SPECIES_ID(speciesArrId, monId) speciesArrId = (PLAYER_APPRENTICE.monIds[monId] >> \
                                                                  (((PLAYER_APPRENTICE.field_B2_0 >> monId) & 1) << 2)) & 0xF; \
                                                   do {} while (0)

// Why the need to have two macros do the exact thing differently?
#define APPRENTICE_SPECIES_ID_2(speciesArrId, monId) {  u8 a0 = ((PLAYER_APPRENTICE.field_B2_0 >> monId) & 1);\
                                                        speciesArrId = PLAYER_APPRENTICE.monIds[monId];     \
                                                        speciesArrId = ((speciesArrId) >> (a0 << 2)) & 0xF; \
                                                     }

static u16 sub_819FF98(u8 arg0)
{
    u8 i, j;
    u8 id;
    u8 knownMovesCount;
    u16 species;
    const u16 *learnset;
    bool32 var_24 = FALSE;
    u16 moveId = 0;
    bool32 valid;
    u8 level;

    if (arg0 < 3)
    {
        APPRENTICE_SPECIES_ID(id, arg0);
    }
    else
    {
        id = 0;
    }

    species = gApprentices[PLAYER_APPRENTICE.id].species[id];
    learnset = gLevelUpLearnsets[species];
    j = 0;
    if (PLAYER_APPRENTICE.activeLvlMode == 1)
        level = 50;
    else
        level = 60;

    for (j = 0; learnset[j] != 0xFFFF; j++)
    {
        if ((learnset[j] & 0xFE00) > (level << 9))
            break;
    }

    knownMovesCount = j;
    i = 0;
    while (i < 5)
    {
        if (Random() % 2 == 0 || var_24 == TRUE)
        {
            do
            {
                do
                {
                    id = Random() % (NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES);
                    valid = CanSpeciesLearnTMHM(species, id);
                }
                while (!valid);

                moveId = ItemIdToBattleMoveId(ITEM_TM01 + id);
                valid = TRUE;

                if (knownMovesCount < 5)
                    j = 0;
                else
                    j = knownMovesCount - 4;

                for (; j < knownMovesCount; j++)
                {
                    if ((learnset[j] & 0x1FF) == moveId)
                    {
                        valid = FALSE;
                        break;
                    }
                }
            } while (valid != TRUE);
        }
        else
        {
            if (knownMovesCount < 5)
            {
                var_24 = TRUE;
                continue;
            }
            else
            {
                do
                {
                    u8 learnsetId = Random() % (knownMovesCount - 4);
                    moveId = learnset[learnsetId] & 0x1FF;
                    valid = TRUE;
                    for (j = knownMovesCount - 4; j < knownMovesCount; j++)
                    {
                        if ((learnset[j] & 0x1FF) == moveId)
                        {
                            valid = FALSE;
                            break;
                        }
                    }
                } while (valid != TRUE);
            }
        }

        if (sub_81A0194(arg0, moveId))
        {
            if (gUnknown_08611370[moveId])
                break;
            i++;
        }
    }

    gUnknown_030062EC->unk0++;
    return moveId;
}

static bool8 sub_81A0194(u8 arg0, u16 moveId)
{
    u8 i;

    for (i = 0; i < 5; i++)
    {
        if (gUnknown_030062EC->unk2[arg0][i] == moveId)
            return FALSE;
    }

    gUnknown_030062EC->unk2[arg0][gUnknown_030062EC->unk0] = moveId;
    return TRUE;
}

void GetLatestLearnedMoves(u16 species, u16 *moves)
{
    u8 i, j;
    u8 level, knownMovesCount;
    const u16 *learnset;

    if (PLAYER_APPRENTICE.activeLvlMode == 1)
        level = 50;
    else
        level = 60;

    learnset = gLevelUpLearnsets[species];
    for (i = 0; learnset[i] != 0xFFFF; i++)
    {
        if ((learnset[i] & 0xFE00) > (level << 9))
            break;
    }

    knownMovesCount = i;
    if (knownMovesCount > 4)
        knownMovesCount = 4;

    for (j = 0; j < knownMovesCount; j++)
        moves[j] = learnset[(i - 1) - j] & 0x1FF;
}

u16 sub_81A0284(u8 arg0, u8 speciesTableId, u8 arg2)
{
    u16 moves[4];
    u8 i, count;

    if (PLAYER_APPRENTICE.field_B1_1 < 3)
        return 0;

    count = 0;
    for (i = 0; i < 9; i++)
    {
        if (PLAYER_APPRENTICE.field_B8[i].unk0_0 == 0)
            break;
        count++;
    }

    GetLatestLearnedMoves(gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId], moves);
    for (i = 0; i < count && i < PLAYER_APPRENTICE.field_B1_1 - 3; i++)
    {
        if (PLAYER_APPRENTICE.field_B8[i].unk0_0 == 2
            && PLAYER_APPRENTICE.field_B8[i].unk0_1 == arg0
            && PLAYER_APPRENTICE.field_B8[i].unk0_3 != 0)
        {
            moves[PLAYER_APPRENTICE.field_B8[i].unk0_2] = PLAYER_APPRENTICE.field_B8[i].unk2;
        }
    }

    return moves[arg2];
}

void sub_81A0390(u8 arg0)
{
    struct ApprenticeMon *apprenticeMons[3];
    u8 i, j;
    u32 speciesTableId;

    for (i = 0; i < 3; i++)
    {
        gSaveBlock2Ptr->apprentices[0].monData[i].species = 0;
        gSaveBlock2Ptr->apprentices[0].monData[i].item = 0;
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->apprentices[0].monData[i].moves[j] = 0;
    }

    j = PLAYER_APPRENTICE.field_B1_2;
    for (i = 0; i < 3; i++)
    {
        apprenticeMons[j] = &gSaveBlock2Ptr->apprentices[0].monData[i];
        j = (j + 1) % 3;
    }

    for (i = 0; i < 3; i++)
    {
        APPRENTICE_SPECIES_ID(speciesTableId, i);
        apprenticeMons[i]->species = gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId];
        GetLatestLearnedMoves(apprenticeMons[i]->species, apprenticeMons[i]->moves);
    }

    for (i = 0; i < arg0; i++)
    {
        u8 var1 = PLAYER_APPRENTICE.field_B8[i].unk0_0;
        u8 monId = PLAYER_APPRENTICE.field_B8[i].unk0_1;
        if (var1 == 1)
        {
            if (PLAYER_APPRENTICE.field_B8[i].unk0_3 != 0)
                apprenticeMons[monId]->item = PLAYER_APPRENTICE.field_B8[i].unk2;
        }
        else if (var1 == 2)
        {
            if (PLAYER_APPRENTICE.field_B8[i].unk0_3 != 0)
            {
                u32 moveSlot = PLAYER_APPRENTICE.field_B8[i].unk0_2;
                apprenticeMons[monId]->moves[moveSlot] = PLAYER_APPRENTICE.field_B8[i].unk2;
            }
        }
    }
}

static void CreateMenuWithAnswers(u8 arg0)
{
    u8 i;
    u8 windowId;
    const u8 *strings[3];
    u8 count = 2;
    u8 width;
    u8 left;
    u8 top;
    s32 pixelWidth;

    switch (arg0)
    {
    case APPRENTICE_ASK_WHICH_LEVEL:
        left = 0x12;
        top = 8;
        strings[0] = gText_Lv50;
        strings[1] = gText_OpenLevel;
        break;
    case APPRENTICE_ASK_3SPECIES:
        count = 3;
        left = 0x12;
        top = 6;
        for (i = 0; i < 3; i++)
        {
            u16 species;
            u32 speciesTableId;

            APPRENTICE_SPECIES_ID(speciesTableId, i);
            species =  gApprentices[PLAYER_APPRENTICE.id].species[speciesTableId];
            strings[i] = gSpeciesNames[species];
        }
        break;
    case APPRENTICE_ASK_2SPECIES:
        left = 0x12;
        top = 8;
        if (PLAYER_APPRENTICE.field_B1_1 > 2)
            return;
        strings[1] = gSpeciesNames[gUnknown_030062F0->unk2];
        strings[0] = gSpeciesNames[gUnknown_030062F0->unk0];
        break;
    case APPRENTICE_ASK_MOVES:
        left = 0x11;
        top = 8;
        strings[0] = gMoveNames[gUnknown_030062F0->unk4];
        strings[1] = gMoveNames[gUnknown_030062F0->unk6];
        break;
    case APPRENTICE_ASK_GIVE:
        left = 0x12;
        top = 8;
        strings[0] = gText_Give;
        strings[1] = gText_NoNeed;
        break;
    case APPRENTICE_ASK_YES_NO:
        left = 0x14;
        top = 8;
        strings[0] = gText_Yes;
        strings[1] = gText_No;
        break;
    default:
        left = 0;
        top = 0;
        break;
    }

    pixelWidth = 0;
    for (i = 0; i < count; i++)
    {
        s32 width = GetStringWidth(1, strings[i], 0);
        if (width > pixelWidth)
            pixelWidth = width;
    }

    width = convert_pixel_width_to_tile_width(pixelWidth);
    left = sub_80E2D5C(left, width);
    windowId = CreateAndShowWindow(left, top, width, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);

    for (i = 0; i < count; i++)
        AddTextPrinterParameterized(windowId, 1, strings[i], 8, (i * 16) + 1, TEXT_SPEED_FF, NULL);

    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, 0);
    CreateChooseAnswerTask(TRUE, count, windowId);
}

#define tNoBButton data[4]
#define tWrapAround data[5]
#define tWindowId data[6]

void Task_ChooseAnswer(u8 taskId)
{
    s8 input;
    s16 *data = gTasks[taskId].data;

    if (!tWrapAround)
        input = Menu_ProcessInputNoWrapAround();
    else
        input = ProcessMenuInput();

    switch (input)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tNoBButton)
            return;

        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0x7F;
        break;
    default:
        gSpecialVar_Result = input;
        break;
    }

    RemoveAndHideWindow(tWindowId);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static u8 CreateAndShowWindow(u8 left, u8 top, u8 width, u8 height)
{
    u8 windowId;
    struct WindowTemplate winTemplate = CreateWindowTemplate(0, left + 1, top + 1, width, height, 15, 100);

    windowId = AddWindow(&winTemplate);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
    return windowId;
}

static void RemoveAndHideWindow(u8 windowId)
{
    sub_8198070(windowId, TRUE);
    RemoveWindow(windowId);
}

static void CreateChooseAnswerTask(bool8 noBButton, u8 itemsCount, u8 windowId)
{
    u8 taskId = CreateTask(Task_ChooseAnswer, 80);
    gTasks[taskId].tNoBButton = noBButton;

    if (itemsCount > 3)
        gTasks[taskId].tWrapAround = TRUE;
    else
        gTasks[taskId].tWrapAround = FALSE;

    gTasks[taskId].tWindowId = windowId;
}

#undef tNoBButton
#undef tWrapAround
#undef tWindowId

void sub_81A085C(void)
{
    gUnknown_086114E0[gSpecialVar_0x8004]();
}

void sub_81A087C(void)
{
    u8 i;

    sub_819FBC8();
    PLAYER_APPRENTICE.activeLvlMode = 0;
    PLAYER_APPRENTICE.field_B1_1 = 0;
    PLAYER_APPRENTICE.field_B1_2 = 0;
    PLAYER_APPRENTICE.field_B2_0 = 0;

    for (i = 0; i < 3; i++)
        PLAYER_APPRENTICE.monIds[i] = 0;

    for (i = 0; i < 9; i++)
    {
        PLAYER_APPRENTICE.field_B8[i].unk0_0 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk0_1 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk0_2 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk0_3 = 0;
        PLAYER_APPRENTICE.field_B8[i].unk2 = 0;
    }
}

void sub_81A093C(void)
{
    if (!IsPlayersApprenticeActive())
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

void sub_81A0964(void)
{
    SetPlayersApprenticeLvlMode(gSpecialVar_0x8005);
}

void sub_81A0978(void)
{
    sub_819FBC8();
}

void sub_81A0984(void)
{
    sub_819FD64();
}

void sub_81A0990(void)
{
    PLAYER_APPRENTICE.field_B1_1++;
}

void sub_81A09B4(void)
{
    gSpecialVar_Result = PLAYER_APPRENTICE.field_B1_1;
}

void sub_81A09D0(void)
{
    s32 var = PLAYER_APPRENTICE.field_B1_1 - 3;
    if (var < 0)
    {
        gSpecialVar_Result = FALSE;
    }
    else
    {
        if (var > 8)
            gSpecialVar_Result = TRUE;

        if (!PLAYER_APPRENTICE.field_B8[var].unk0_0)
            gSpecialVar_Result = TRUE;
        else
            gSpecialVar_Result = FALSE;
    }
}

void sub_81A0A20(void)
{
    CreateMenuWithAnswers(gSpecialVar_0x8005);
}

static void Task_WaitForPrintingMessage(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        DestroyTask(taskId);
        if (gSpecialVar_0x8005)
            ExecuteFuncAfterButtonPress(EnableBothScriptContexts);
        else
            EnableBothScriptContexts();
    }
}

static void PrintMessage(void)
{
    const u8 *string;

    if (gSpecialVar_0x8006 == 6)
    {
        string = gUnknown_08610FF0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 7)
    {
        string = gUnknown_08610FF0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 8)
    {
        string = gUnknown_086111B0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 9)
    {
        string = gUnknown_086111B0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 4)
    {
        string = gUnknown_08611230[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 5)
    {
        string = gUnknown_08611230[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 10)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 11)
    {
        string = gUnknown_086112B0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 12)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][3];
    }
    else if (gSpecialVar_0x8006 == 13)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 16)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][4];
    }
    else if (gSpecialVar_0x8006 == 14)
    {
        string = gUnknown_08611070[PLAYER_APPRENTICE.id][2];
    }
    else if (gSpecialVar_0x8006 == 15)
    {
        string = gUnknown_086112B0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 0)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][0];
    }
    else if (gSpecialVar_0x8006 == 1)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][1];
    }
    else if (gSpecialVar_0x8006 == 2)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][2];
    }
    else if (gSpecialVar_0x8006 == 3)
    {
        string = gUnknown_08610EF0[PLAYER_APPRENTICE.id][3];
    }
    else
    {
        EnableBothScriptContexts();
        return;
    }

    StringExpandPlaceholders(gStringVar4, string);
    AddTextPrinterForMessage(TRUE);
    CreateTask(Task_WaitForPrintingMessage, 1);
}

void sub_81A0C9C(void)
{
    ScriptContext2_Enable();
    FreezeEventObjects();
    sub_808B864();
    sub_808BCF4();
    NewMenuHelpers_DrawDialogueFrame(0, 1);
    PrintMessage();
}

void sub_81A0CC0(void)
{
    if (PLAYER_APPRENTICE.field_B1_1 < 3)
    {
        gSpecialVar_Result = 2;
    }
    else if (PLAYER_APPRENTICE.field_B1_1 > 11)
    {
        gSpecialVar_Result = 5;
    }
    else
    {
        s32 id = PLAYER_APPRENTICE.field_B1_1 - 3;
        switch (PLAYER_APPRENTICE.field_B8[id].unk0_0)
        {
        case 1:
            gSpecialVar_Result = 4;
            break;
        case 2:
            gSpecialVar_Result = 3;
            break;
        case 3:
            gSpecialVar_Result = 1;
            break;
        default:
            gSpecialVar_Result = 5;
            break;
        }
    }
}

void sub_81A0D40(void)
{
    if (gSpecialVar_0x8005)
    {
        u8 bitNo = gSpecialVar_0x8006;
        PLAYER_APPRENTICE.field_B2_0 |= 1 << bitNo;
    }
}

void sub_81A0D80(void)
{
    if (PLAYER_APPRENTICE.field_B1_1 >= 3)
    {
        u8 id = PLAYER_APPRENTICE.field_B1_1 - 3;
        if (gSpecialVar_0x8005)
            PLAYER_APPRENTICE.field_B8[id].unk0_3 = 1;
        else
            PLAYER_APPRENTICE.field_B8[id].unk0_3 = 0;
    }
}

void sub_81A0DD4(void)
{
    u8 i;
    u8 count = 0;
    u8 id1, id2;

    for (i = 0; i < 9 && PLAYER_APPRENTICE.field_B8[i].unk0_0; count++, i++)
        ;

    gUnknown_030062F0 = AllocZeroed(sizeof(*gUnknown_030062F0));
    if (gSpecialVar_0x8005 == 2)
    {
        if (PLAYER_APPRENTICE.field_B1_1 < 3)
        {
            id1 = PLAYER_APPRENTICE.monIds[PLAYER_APPRENTICE.field_B1_1] >> 4;
            gUnknown_030062F0->unk2 = gApprentices[PLAYER_APPRENTICE.id].species[id1];

            id2 = PLAYER_APPRENTICE.monIds[PLAYER_APPRENTICE.field_B1_1] & 0xF;
            gUnknown_030062F0->unk0 = gApprentices[PLAYER_APPRENTICE.id].species[id2];
        }
    }
    else if (gSpecialVar_0x8005 == 3)
    {
        if (PLAYER_APPRENTICE.field_B1_1 >= 3
            && PLAYER_APPRENTICE.field_B1_1 < count + 3
            && PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_0 == 2)
        {
            count = PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_1;
            APPRENTICE_SPECIES_ID_2(id1, count);
            gUnknown_030062F0->unk0 = gApprentices[PLAYER_APPRENTICE.id].species[id1];
            gUnknown_030062F0->unk4 = sub_81A0284(count, id1, PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_2);
            gUnknown_030062F0->unk6 = PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2;
        }
    }
    else if (gSpecialVar_0x8005 == 4)
    {
        if (PLAYER_APPRENTICE.field_B1_1 >= 3
            && PLAYER_APPRENTICE.field_B1_1 < count + 3
            && PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_0 == 1)
        {
            count = PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_1;
            APPRENTICE_SPECIES_ID_2(id2, count);
            gUnknown_030062F0->unk0 = gApprentices[PLAYER_APPRENTICE.id].species[id2];
        }
    }
}

void sub_81A0FE4(void)
{
    FREE_AND_SET_NULL(gUnknown_030062F0);
}

void sub_81A0FFC(void)
{
    u8 *stringDst;
    u8 text[16];
    u32 speciesArrayId;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        stringDst = gStringVar1;
        break;
    case 1:
        stringDst = gStringVar2;
        break;
    case 2:
        stringDst = gStringVar3;
        break;
    default:
        return;
    }

    switch (gSpecialVar_0x8006)
    {
    case APPRENTICE_BUFF_SPECIES1:
        StringCopy(stringDst, gSpeciesNames[gUnknown_030062F0->unk0]);
        break;
    case APPRENTICE_BUFF_SPECIES2:
        StringCopy(stringDst, gSpeciesNames[gUnknown_030062F0->unk2]);
        break;
    case APPRENTICE_BUFF_SPECIES3:
        StringCopy(stringDst, gSpeciesNames[gUnknown_030062F0->unk0]);
        break;
    case APPRENTICE_BUFF_MOVE1:
        StringCopy(stringDst, gMoveNames[gUnknown_030062F0->unk4]);
        break;
    case APPRENTICE_BUFF_MOVE2:
        StringCopy(stringDst, gMoveNames[gUnknown_030062F0->unk6]);
        break;
    case APPRENTICE_BUFF_ITEM:
        StringCopy(stringDst, ItemId_GetName(PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2));
        break;
    case APPRENTICE_BUFF_NAME:
        TVShowConvertInternationalString(text, GetApprenticeNameInLanguage(PLAYER_APPRENTICE.id, LANGUAGE_ENGLISH), LANGUAGE_ENGLISH);
        StringCopy(stringDst, text);
        break;
    case APPRENTICE_BUFF_LEVEL:
        if (PLAYER_APPRENTICE.activeLvlMode == 1)
            StringCopy(stringDst, gText_Lv50);
        else
            StringCopy(stringDst, gText_OpenLevel);
        break;
    case APPRENTICE_BUFF_EASY_CHAT:
        ConvertBattleFrontierTrainerSpeechToString(gSaveBlock2Ptr->apprentices[0].easyChatWords);
        StringCopy(stringDst, gStringVar4);
        break;
    case APPRENTICE_BUFF_SPECIES4:
        if (PLAYER_APPRENTICE.field_B1_2 < 3)
        {
            APPRENTICE_SPECIES_ID(speciesArrayId, PLAYER_APPRENTICE.field_B1_2);
        }
        else
        {
            speciesArrayId = 0;
        }
        StringCopy(stringDst, gSpeciesNames[gApprentices[PLAYER_APPRENTICE.id].species[speciesArrayId]]);
        break;
    }
}

void sub_81A11F8(void)
{
    PLAYER_APPRENTICE.field_B1_2 = gSpecialVar_0x8005;
}

void sub_81A1218(void)
{
    sub_81AAC28();
}

#ifdef NONMATCHING
void sub_81A1224(void)
{
    u8 count;
    u8 i, j;

    if (PLAYER_APPRENTICE.field_B1_1 < 3)
        return;

    count = 0;
    for (j = 0; j < 9 && PLAYER_APPRENTICE.field_B8[j].unk0_0; count++, j++)
        ;

    for (i = 0; i < count && i < PLAYER_APPRENTICE.field_B1_1 - 3; i++)
    {
        if (PLAYER_APPRENTICE.field_B8[i].unk0_0 == 1
            && PLAYER_APPRENTICE.field_B8[i].unk0_3
            && PLAYER_APPRENTICE.field_B8[i].unk2 == gSpecialVar_0x8005)
        {
            PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_3 = 0;
            PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2 = gSpecialVar_0x8005;
            gSpecialVar_Result = i;
            return;
        }
    }

    PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk0_3 = 1;
    PLAYER_APPRENTICE.field_B8[PLAYER_APPRENTICE.field_B1_1 - 3].unk2 = gSpecialVar_0x8005;
    gSpecialVar_Result = 1;
}
#else
NAKED
void sub_81A1224(void)
{
    asm_unified("\n\
                	push {r4-r7,lr}\n\
	mov r7, r9\n\
	mov r6, r8\n\
	push {r6,r7}\n\
	ldr r1, =gSaveBlock2Ptr\n\
	ldr r3, [r1]\n\
	adds r0, r3, 0\n\
	adds r0, 0xB1\n\
	ldrb r0, [r0]\n\
	lsls r0, 26\n\
	lsrs r0, 28\n\
	adds r7, r1, 0\n\
	cmp r0, 0x2\n\
	bhi _081A1242\n\
	b _081A1362\n\
_081A1242:\n\
	movs r5, 0\n\
	movs r2, 0\n\
	adds r0, r3, 0\n\
	adds r0, 0xB8\n\
	ldrb r0, [r0]\n\
	lsls r0, 30\n\
	ldr r1, =gSpecialVar_0x8005\n\
	mov r12, r1\n\
	ldr r1, =gSpecialVar_Result\n\
	mov r8, r1\n\
	cmp r0, 0\n\
	beq _081A127C\n\
	adds r3, r7, 0\n\
_081A125C:\n\
	adds r0, r5, 0x1\n\
	lsls r0, 24\n\
	lsrs r5, r0, 24\n\
	adds r0, r2, 0x1\n\
	lsls r0, 24\n\
	lsrs r2, r0, 24\n\
	cmp r2, 0x8\n\
	bhi _081A127C\n\
	ldr r0, [r3]\n\
	lsls r1, r2, 2\n\
	adds r0, r1\n\
	adds r0, 0xB8\n\
	ldrb r0, [r0]\n\
	lsls r0, 30\n\
	cmp r0, 0\n\
	bne _081A125C\n\
_081A127C:\n\
	movs r4, 0\n\
	cmp r4, r5\n\
	bcs _081A1322\n\
	ldr r0, [r7]\n\
	adds r0, 0xB1\n\
	ldrb r0, [r0]\n\
	lsls r0, 26\n\
	lsrs r0, 28\n\
	subs r0, 0x3\n\
	cmp r4, r0\n\
	bge _081A1322\n\
	adds r6, r7, 0\n\
	mov r9, r4\n\
_081A1296:\n\
	ldr r3, [r6]\n\
	lsls r0, r4, 2\n\
	adds r2, r3, r0\n\
	adds r0, r2, 0\n\
	adds r0, 0xB8\n\
	ldrb r1, [r0]\n\
	lsls r0, r1, 30\n\
	lsrs r0, 30\n\
	cmp r0, 0x1\n\
	bne _081A1308\n\
	lsrs r0, r1, 6\n\
	cmp r0, 0\n\
	beq _081A1308\n\
	adds r0, r2, 0\n\
	adds r0, 0xBA\n\
	ldrh r0, [r0]\n\
	mov r2, r12\n\
	ldrh r2, [r2]\n\
	cmp r0, r2\n\
	bne _081A1308\n\
	adds r0, r3, 0\n\
	adds r0, 0xB1\n\
	ldrb r0, [r0]\n\
	lsls r0, 26\n\
	lsrs r0, 28\n\
	subs r0, 0x3\n\
	lsls r0, 2\n\
	adds r0, r3, r0\n\
	adds r0, 0xB8\n\
	ldrb r2, [r0]\n\
	movs r1, 0x3F\n\
	ands r1, r2\n\
	strb r1, [r0]\n\
	ldr r1, [r6]\n\
	adds r0, r1, 0\n\
	adds r0, 0xB1\n\
	ldrb r0, [r0]\n\
	lsls r0, 26\n\
	lsrs r0, 28\n\
	subs r0, 0x3\n\
	lsls r0, 2\n\
	adds r1, r0\n\
	mov r2, r12\n\
	ldrh r0, [r2]\n\
	adds r1, 0xBA\n\
	strh r0, [r1]\n\
	mov r1, r9\n\
	mov r0, r8\n\
	strh r1, [r0]\n\
	b _081A1362\n\
	.pool\n\
_081A1308:\n\
	adds r0, r4, 0x1\n\
	lsls r0, 24\n\
	lsrs r4, r0, 24\n\
	cmp r4, r5\n\
	bcs _081A1322\n\
	ldr r0, [r6]\n\
	adds r0, 0xB1\n\
	ldrb r0, [r0]\n\
	lsls r0, 26\n\
	lsrs r0, 28\n\
	subs r0, 0x3\n\
	cmp r4, r0\n\
	blt _081A1296\n\
_081A1322:\n\
	ldr r2, [r7]\n\
	adds r0, r2, 0\n\
	adds r0, 0xB1\n\
	ldrb r0, [r0]\n\
	lsls r0, 26\n\
	lsrs r0, 28\n\
	subs r0, 0x3\n\
	lsls r0, 2\n\
	adds r2, r0\n\
	adds r2, 0xB8\n\
	ldrb r1, [r2]\n\
	movs r0, 0x3F\n\
	ands r0, r1\n\
	movs r1, 0x40\n\
	orrs r0, r1\n\
	strb r0, [r2]\n\
	ldr r1, [r7]\n\
	adds r0, r1, 0\n\
	adds r0, 0xB1\n\
	ldrb r0, [r0]\n\
	lsls r0, 26\n\
	lsrs r0, 28\n\
	subs r0, 0x3\n\
	lsls r0, 2\n\
	adds r1, r0\n\
	mov r2, r12\n\
	ldrh r0, [r2]\n\
	adds r1, 0xBA\n\
	strh r0, [r1]\n\
	movs r0, 0x1\n\
	mov r1, r8\n\
	strh r0, [r1]\n\
_081A1362:\n\
	pop {r3,r4}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
");
}
#endif // NONMATCHING

void sub_81A1370(void)
{
    s32 i;
    s32 r10;
    s32 r9;

    if (gSaveBlock2Ptr->apprentices[0].playerName[0] == EOS)
        return;

    for (i = 0; i < 3; i++)
    {
        if (gSaveBlock2Ptr->apprentices[i + 1].playerName[0] == EOS)
        {
            gSaveBlock2Ptr->apprentices[i + 1] = gSaveBlock2Ptr->apprentices[0];
            return;
        }
    }

    r10 = 0xFFFF;
    r9 = -1;
    for (i = 1; i < 4; i++)
    {
        if (ReadUnalignedWord(gSaveBlock2Ptr->apprentices[i].playerId) == ReadUnalignedWord(gSaveBlock2Ptr->playerTrainerId)
            && gSaveBlock2Ptr->apprentices[i].number < r10)
        {
            r10 = gSaveBlock2Ptr->apprentices[i].number;
            r9 = i;
        }
    }

    if (r9 > 0)
        gSaveBlock2Ptr->apprentices[r9] = gSaveBlock2Ptr->apprentices[0];
}

void sub_81A1438(void)
{
    u8 i;

    gSaveBlock2Ptr->apprentices[0].id = PLAYER_APPRENTICE.id;
    gSaveBlock2Ptr->apprentices[0].lvlMode = PLAYER_APPRENTICE.activeLvlMode;

    for (i = 0; i < 9 && PLAYER_APPRENTICE.field_B8[i].unk0_0; i++)
        ;

    gSaveBlock2Ptr->apprentices[0].field_1 = i;
    if (gSaveBlock2Ptr->apprentices[0].number < 255)
        gSaveBlock2Ptr->apprentices[0].number++;

    sub_81A0390(gSaveBlock2Ptr->apprentices[0].field_1);
    for (i = 0; i < 4; i++)
        gSaveBlock2Ptr->apprentices[0].playerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    StringCopy(gSaveBlock2Ptr->apprentices[0].playerName, gSaveBlock2Ptr->playerName);
    gSaveBlock2Ptr->apprentices[0].language = gGameLanguage;
    sub_8165AE8(&gSaveBlock2Ptr->apprentices[0]);
}

void sub_81A150C(void)
{
    u8 i;
    u8 mapObjectGfxId;
    u8 class = gApprentices[gSaveBlock2Ptr->apprentices[0].id].facilityClass;

    for (i = 0; i < 30 && gUnknown_085DCEDC[i] != class; i++)
        ;

    if (i != 30)
    {
        mapObjectGfxId = gUnknown_085DCF0E[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
    }
    else
    {
        for (i = 0; i < 20 && gUnknown_085DCEFA[i] != class; i++)
            ;

        if (i != 20)
        {
            mapObjectGfxId = gUnknown_085DCF2C[i];
            VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
        }
    }
}

void sub_81A15A4(void)
{
    u8 i;
    u8 mapObjectGfxId;
    u8 class = gApprentices[PLAYER_APPRENTICE.id].facilityClass;

    for (i = 0; i < 30 && gUnknown_085DCEDC[i] != class; i++)
        ;

    if (i != 30)
    {
        mapObjectGfxId = gUnknown_085DCF0E[i];
        VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
    }
    else
    {
        for (i = 0; i < 20 && gUnknown_085DCEFA[i] != class; i++)
            ;

        if (i != 20)
        {
            mapObjectGfxId = gUnknown_085DCF2C[i];
            VarSet(VAR_OBJ_GFX_ID_0, mapObjectGfxId);
        }
    }
}

void sub_81A1638(void)
{
    gSpecialVar_0x8004 = 1;
}

void sub_81A1644(void)
{
    gSpecialVar_0x8004 = 1;
}

const u8 *GetApprenticeNameInLanguage(u32 apprenticeId, s32 language)
{
    const struct ApprenticeTrainer *apprentice = &gApprentices[apprenticeId];

    switch (language)
    {
    case LANGUAGE_JAPANESE:
        return apprentice->name[0];
    case LANGUAGE_ENGLISH:
        return apprentice->name[1];
    case LANGUAGE_FRENCH:
        return apprentice->name[2];
    case LANGUAGE_ITALIAN:
        return apprentice->name[3];
    case LANGUAGE_GERMAN:
        return apprentice->name[4];
    case LANGUAGE_SPANISH:
    default:
        return apprentice->name[5];
    }
}

void sub_81A16B4(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
        SwitchTaskToFollowupFunc(taskId);
}

static void Task_ExecuteFuncAfterButtonPress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        gUnknown_030062F4 = (void*)(u32)(((u16)gTasks[taskId].data[0] | (gTasks[taskId].data[1] << 0x10)));
        gUnknown_030062F4();
        DestroyTask(taskId);
    }
}

static void ExecuteFuncAfterButtonPress(void (*func)(void))
{
    u8 taskId = CreateTask(Task_ExecuteFuncAfterButtonPress, 1);
    gTasks[taskId].data[0] = (u32)(func);
    gTasks[taskId].data[1] = (u32)(func) >> 16;
}

void sub_81A175C(TaskFunc taskFunc)
{
    u8 taskId = CreateTask(sub_81A16B4, 1);
    SetTaskFuncWithFollowupFunc(taskId, sub_81A16B4, taskFunc);
}
