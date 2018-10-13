#include "global.h"
#include "apprentice.h"
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
#include "data2.h"
#include "constants/items.h"

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

extern const u8 *const gUnknown_08611330[];
extern const u8 gUnknown_08611548[8];
extern const u8 gUnknown_086114D3[];
extern const bool8 gUnknown_08611370[];

// text
extern const u8 gText_Give[];
extern const u8 gText_NoNeed[];
extern const u8 gText_Yes[];
extern const u8 gText_No[];

// This file's functions.
void sub_81A087C(void);
u16 sub_819FF98(u8 arg0);
bool8 sub_81A0194(u8 arg0, u16 moveId);
void sub_81A0804(u8 arg0, u8 itemsCount, u8 windowId);
u8 sub_81A0784(u8 arg0, u8 arg1, u8 arg2, u8 arg3);

void sub_819F99C(u8 id)
{
    u8 i, var;
    const u8 *str;

    var = gSaveBlock2Ptr->field_DC[id].field_2;
    for (i = 0; var != 0 && i < 4; i++)
    {
        var /= 10;
    }

    StringCopy7(gStringVar1, gSaveBlock2Ptr->field_DC[id].playerName);
    ConvertInternationalString(gStringVar1, gSaveBlock2Ptr->field_DC[id].language);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->field_DC[id].field_2, STR_CONV_MODE_RIGHT_ALIGN, i);
    str = gUnknown_08611330[gSaveBlock2Ptr->field_DC[id].field_0_0];
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
        apprentice->unk28[i] |= 0xFFFF;

    apprentice->playerName[0] = EOS;
    apprentice->field_0_0 = 16;
}

void sub_819FAA0(void)
{
    u8 i, j;

    gSaveBlock2Ptr->field_B2_1 = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
            gSaveBlock2Ptr->field_DC[i].unk28[j] |= 0xFFFF;
        gSaveBlock2Ptr->field_DC[i].field_0_0 = 16;
        gSaveBlock2Ptr->field_DC[i].playerName[0] = EOS;
        gSaveBlock2Ptr->field_DC[i].field_0_1 = 0;
        gSaveBlock2Ptr->field_DC[i].field_2 = 0;
        gSaveBlock2Ptr->field_DC[i].field_1 = 0;
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->field_DC[i].playerId[j] = 0;
        gSaveBlock2Ptr->field_DC[i].language = gGameLanguage;
        gSaveBlock2Ptr->field_DC[i].unk40 = 0;
    }

    sub_81A087C();
}

u8 sub_819FBB0(void)
{
    return (gSaveBlock2Ptr->field_B1_0 != 0);
}

void sub_819FBC8(void)
{
    if (gSaveBlock2Ptr->field_DC[0].field_2 == 0)
    {
        do
        {
            gSaveBlock2Ptr->field_B0 = gUnknown_08611548[Random() % ARRAY_COUNT(gUnknown_08611548)];
        } while (gSaveBlock2Ptr->field_B0 == gSaveBlock2Ptr->field_DC[0].field_0_0);
    }
    else
    {
        do
        {
            gSaveBlock2Ptr->field_B0 = Random() % 16;
        } while (gSaveBlock2Ptr->field_B0 == gSaveBlock2Ptr->field_DC[0].field_0_0);
    }
}

void sub_819FC40(u8 value)
{
    gSaveBlock2Ptr->field_B1_0 = value;
}

void sub_819FC60(void)
{
    u8 array[10];
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
        gSaveBlock2Ptr->field_B4[i] = ((array[i * 2] & 0xF) << 4) | ((array[i * 2 + 1]) & 0xF);
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
        gSaveBlock2Ptr->field_B8[i].unk0_0 = sp_0[i];
        if (sp_0[i] != 3)
        {
            gSaveBlock2Ptr->field_B8[i].unk0_1 = sub_819FCF8(sp_0[i], sp_C, &sp_10);
            id = gSaveBlock2Ptr->field_B8[i].unk0_1;
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
                gSaveBlock2Ptr->field_B8[i].unk0_2 = rand1;
                gSaveBlock2Ptr->field_B8[i].unk2 = sub_819FF98(gSaveBlock2Ptr->field_B8[i].unk0_1);
            }
        }
    }

    FREE_AND_SET_NULL(gUnknown_030062EC);
}

// No idea why a do-while loop is needed, but it will not match without it.

#define APPRENTICE_SPECIES_ID(speciesArrId, monId) speciesArrId = (gSaveBlock2Ptr->field_B4[monId] >> \
                                                                  (((gSaveBlock2Ptr->field_B2_0 >> monId) & 1) << 2)) & 0xF; \
                                                                  do {} while (0)

u16 sub_819FF98(u8 arg0)
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

    species = gApprentices[gSaveBlock2Ptr->field_B0].species[id];
    learnset = gLevelUpLearnsets[species];
    j = 0;
    if (gSaveBlock2Ptr->field_B1_0 == 1)
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

bool8 sub_81A0194(u8 arg0, u16 moveId)
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

    if (gSaveBlock2Ptr->field_B1_0 == 1)
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

    if (gSaveBlock2Ptr->field_B1_1 < 3)
        return 0;

    count = 0;
    for (i = 0; i < 9; i++)
    {
        if (gSaveBlock2Ptr->field_B8[i].unk0_0 == 0)
            break;
        count++;
    }

    GetLatestLearnedMoves(gApprentices[gSaveBlock2Ptr->field_B0].species[speciesTableId], moves);
    for (i = 0; i < count && i < gSaveBlock2Ptr->field_B1_1 - 3; i++)
    {
        if (gSaveBlock2Ptr->field_B8[i].unk0_0 == 2
            && gSaveBlock2Ptr->field_B8[i].unk0_1 == arg0
            && gSaveBlock2Ptr->field_B8[i].unk0_3 != 0)
        {
            moves[gSaveBlock2Ptr->field_B8[i].unk0_2] = gSaveBlock2Ptr->field_B8[i].unk2;
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
        gSaveBlock2Ptr->field_DC[0].monData[i].species = 0;
        gSaveBlock2Ptr->field_DC[0].monData[i].item = 0;
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->field_DC[0].monData[i].moves[j] = 0;
    }

    j = gSaveBlock2Ptr->field_B1_2;
    for (i = 0; i < 3; i++)
    {
        apprenticeMons[j] = &gSaveBlock2Ptr->field_DC[0].monData[i];
        j = (j + 1) % 3;
    }

    for (i = 0; i < 3; i++)
    {
        APPRENTICE_SPECIES_ID(speciesTableId, i);
        apprenticeMons[i]->species = gApprentices[gSaveBlock2Ptr->field_B0].species[speciesTableId];
        GetLatestLearnedMoves(apprenticeMons[i]->species, apprenticeMons[i]->moves);
    }

    for (i = 0; i < arg0; i++)
    {
        u8 var1 = gSaveBlock2Ptr->field_B8[i].unk0_0;
        u8 monId = gSaveBlock2Ptr->field_B8[i].unk0_1;
        if (var1 == 1)
        {
            if (gSaveBlock2Ptr->field_B8[i].unk0_3 != 0)
                apprenticeMons[monId]->item = gSaveBlock2Ptr->field_B8[i].unk2;
        }
        else if (var1 == 2)
        {
            if (gSaveBlock2Ptr->field_B8[i].unk0_3 != 0)
            {
                u32 moveSlot = gSaveBlock2Ptr->field_B8[i].unk0_2;
                apprenticeMons[monId]->moves[moveSlot] = gSaveBlock2Ptr->field_B8[i].unk2;
            }
        }
    }
}

void sub_81A04E4(u8 arg0)
{
    u8 i;
    u8 windowId;
    const u8 *strings[3];
    u8 count = 2;
    u8 tileWidth;
    u8 r10;
    u8 r6;
    s32 pixelWidth;

    switch (arg0)
    {
    case 0:
        r10 = 0x12;
        r6 = 8;
        strings[0] = gText_Lv50;
        strings[1] = gText_OpenLevel;
        break;
    case 1:
        count = 3;
        r10 = 0x12;
        r6 = 6;
        for (i = 0; i < 3; i++)
        {
            u16 species;
            u32 speciesTableId;

            APPRENTICE_SPECIES_ID(speciesTableId, i);
            species =  gApprentices[gSaveBlock2Ptr->field_B0].species[speciesTableId];
            strings[i] = gSpeciesNames[species];
        }
        break;
    case 2:
        r10 = 0x12;
        r6 = 8;
        if (gSaveBlock2Ptr->field_B1_1 > 2)
            return;
        strings[1] = gSpeciesNames[gUnknown_030062F0->unk2];
        strings[0] = gSpeciesNames[gUnknown_030062F0->unk0];
        break;
    case 3:
        r10 = 0x11;
        r6 = 8;
        strings[0] = gMoveNames[gUnknown_030062F0->unk4];
        strings[1] = gMoveNames[gUnknown_030062F0->unk6];
        break;
    case 4:
        r10 = 0x12;
        r6 = 8;
        strings[0] = gText_Give;
        strings[1] = gText_NoNeed;
        break;
    case 6:
        r10 = 0x14;
        r6 = 8;
        strings[0] = gText_Yes;
        strings[1] = gText_No;
        break;
    default:
        r10 = 0;
        r6 = 0;
        break;
    }

    pixelWidth = 0;
    for (i = 0; i < count; i++)
    {
        s32 width = GetStringWidth(1, strings[i], 0);
        if (width > pixelWidth)
            pixelWidth = width;
    }

    tileWidth = convert_pixel_width_to_tile_width(pixelWidth);
    r10 = sub_80E2D5C(r10, tileWidth);
    windowId = sub_81A0784(r10, r6, tileWidth, count * 2);
    SetStandardWindowBorderStyle(windowId, 0);

    for (i = 0; i < count; i++)
        AddTextPrinterParameterized(windowId, 1, strings[i], 8, (i * 16) + 1, TEXT_SPEED_FF, NULL);

    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(windowId, count, 0);
    sub_81A0804(1, count, windowId);
}
