#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_tower.h"
#include "battle_setup.h"
#include "event_data.h"
#include "fieldmap.h"
#include "field_message_box.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "script.h"
#include "string_util.h"
#include "text.h"
#include "window.h"
#include "util.h"
#include "constants/event_object_movement_constants.h"
#include "constants/maps.h"

#define HILL_TRAINER_NAME_LENGTH 11
#define HILL_MAX_TIME 215999 // 60 * 60 * 60 - 1

struct TrHillStruct1
{
    u8 name[2][HILL_TRAINER_NAME_LENGTH];
    u8 facilityClass[2];
};

struct TrainerHillTrainer
{
    u8 name[HILL_TRAINER_NAME_LENGTH];
    u8 facilityClass;
    u32 field_18;
    u16 speechBefore[6];
    u16 speechWin[6];
    u16 speechLose[6];
    u16 speechAfter[6];
    struct BattleTowerPokemon mons[PARTY_SIZE];
};

struct TrHillStruct5
{
    u8 unk0;
    u8 unk1;
    struct TrainerHillTrainer trainers[2];
    u8 data[0x100];
    u16 unk3A0[2];
    u8 data2[0x20 - 4];
    u8 coords[2]; // x first 4 bits, y last 4 bites
    u8 direction; // array of 4 bites for each trainer
    u8 range; // array of 4 bites for each trainer
};

struct TrHillStruct4
{
    u8 unkField_0;
    u8 unkField_1;
    u8 unkField_2;
    u8 unkField_3;
    u8 unkField_4;
    u8 unkField_5;
    u8 unkField_6;
    struct TrHillStruct5 unk0[4];
};

struct TrHillStruct2
{
    u8 layoutId;
    struct TrHillStruct4 unk4;
};

extern struct TrHillStruct2 *gUnknown_0203CF54;
extern struct TrHillStruct1 *gUnknown_0203CF58;

// This file's functions.
void sub_81D56B0(void);
void sub_81D5710(void);
bool32 sub_81D5F48(void);
void nullsub_2(void);
void sub_81D5DF4(u32 *dst, u32 val);
bool32 sub_81D3B34(void);
u16 sub_81D6640(void);
u32 sub_81D5DF0(u32 *src);
u8 GetCurrentTrainerHillMapId(void);
u8 sub_81D6490(void);
void sub_81D642C(struct Pokemon *mon, u8 level);
bool32 sub_81D6534(void);

// const data
extern void (* const gUnknown_0862A618[])(void);
extern const struct TrHillStruct4 *const gUnknown_0862A5F8[];
extern const u16 gUnknown_0862A5D4[];
extern const u8 gText_TimeBoard[];
extern const u8 gText_TimeCleared[];
extern const u8 gText_XMinYDotZSec[];
extern const u8 gUnknown_0862A5F4[];

extern const u8 *const gUnknown_0862A660[];
extern const struct EventObjectTemplate gUnknown_0862A670;
extern const u32 gUnknown_0862A688[4];
extern const u8 gUnknown_0862A698[][3];
extern const u16 *const *const gUnknown_0862A5CC[];
struct
{
    u8 trainerClass;
    u8 musicId;
} extern const gUnknown_0862A3B4[0x36];

extern const u8 EventScript_2C83F0[];

void sp194_trainer_tower(void)
{
    sub_81D56B0();
    gUnknown_0862A618[gSpecialVar_0x8004]();
    sub_81D5710();
}

void sub_81D54BC(void)
{
    s32 i;

    gSaveBlock2Ptr->frontier.field_EF9_1 = 0;
    gSaveBlock2Ptr->frontier.field_EF9_0 = 0;
    gSaveBlock1Ptr->trainerHill.field_3D68 = 0;
    for (i = 0; i < 4; i++)
        sub_81D5DF4(&gSaveBlock1Ptr->field_3718[i], HILL_MAX_TIME);
}

u8 sub_81D5520(void)
{
    return gMapHeader.mapLayoutId - 159;
}

u8 GetTrainerHillOpponentClass(u16 trainerId)
{
    u8 id = trainerId - 1;

    return gFacilityClassToTrainerClass[gUnknown_0203CF58->facilityClass[id]];
}

void GetTrainerHillTrainerName(u8 *dst, u16 trainerId)
{
    s32 i;
    u8 id = trainerId - 1;

    for (i = 0; i < HILL_TRAINER_NAME_LENGTH; i++)
        dst[i] = gUnknown_0203CF58->name[id][i];
}

u8 GetTrainerHillTrainerFrontSpriteId(u16 trainerId)
{
    u8 id, facilityClass;

    sub_81D56B0();
    id = trainerId - 1;
    facilityClass = gUnknown_0203CF54->unk4.unk0[gUnknown_0203CF54->layoutId].trainers[id].facilityClass;
    sub_81D5710();

    return gFacilityClassToPicIndex[facilityClass];
}

void sub_81D55D0(void)
{
    s32 i, j;

    sub_81D56B0();
    gUnknown_0203CF58 = AllocZeroed(sizeof(*gUnknown_0203CF58));

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < HILL_TRAINER_NAME_LENGTH; j++)
        {
            gUnknown_0203CF58->name[i][j] = gUnknown_0203CF54->unk4.unk0[gUnknown_0203CF54->layoutId].trainers[i].name[j];
        }
        gUnknown_0203CF58->facilityClass[i] = gUnknown_0203CF54->unk4.unk0[gUnknown_0203CF54->layoutId].trainers[i].facilityClass;
    }
    sub_80008DC(&gSaveBlock1Ptr->trainerHill.field_3D64);
    sub_81D5710();
}

void sub_81D5694(void)
{
    if (gUnknown_0203CF58 != NULL)
        FREE_AND_SET_NULL(gUnknown_0203CF58);
}

void sub_81D56B0(void)
{
    if (gUnknown_0203CF54 == NULL)
    {
        gUnknown_0203CF54 = AllocZeroed(sizeof(*gUnknown_0203CF54));
        gUnknown_0203CF54->layoutId = gMapHeader.mapLayoutId - 159;
        CpuCopy32(gUnknown_0862A5F8[gSaveBlock1Ptr->trainerHill.field_3D6E_1], &gUnknown_0203CF54->unk4, sizeof(gUnknown_0203CF54->unk4));
        nullsub_2();
    }
}

void sub_81D5710(void)
{
    if (gUnknown_0203CF54 != NULL)
        FREE_AND_SET_NULL(gUnknown_0203CF54);
}

void CopyTrainerHillTrainerText(u8 which, u16 trainerId)
{
    u8 id, layoutId;

    sub_81D56B0();
    layoutId = sub_81D5520();
    id = trainerId - 1;

    switch (which)
    {
    case 2:
        FrontierSpeechToString(gUnknown_0203CF54->unk4.unk0[layoutId].trainers[id].speechBefore);
        break;
    case 3:
        FrontierSpeechToString(gUnknown_0203CF54->unk4.unk0[layoutId].trainers[id].speechWin);
        break;
    case 4:
        FrontierSpeechToString(gUnknown_0203CF54->unk4.unk0[layoutId].trainers[id].speechLose);
        break;
    case 5:
        FrontierSpeechToString(gUnknown_0203CF54->unk4.unk0[layoutId].trainers[id].speechAfter);
        break;
    }

    sub_81D5710();
}

void sub_81D581C(void)
{
    nullsub_2();
    if (!sub_81D3B34())
        gSaveBlock1Ptr->trainerHill.field_3D6E_0f = 1;
    else
        gSaveBlock1Ptr->trainerHill.field_3D6E_0f = 0;

    gSaveBlock1Ptr->trainerHill.field_3D6C = 0;
    sub_80008DC(&gSaveBlock1Ptr->trainerHill.field_3D64);
    gSaveBlock1Ptr->trainerHill.field_3D64 = 0;
    gSaveBlock1Ptr->trainerHill.field_3D6E_0c = 0;
    gSaveBlock1Ptr->trainerHill.field_3D6E_0b = 0;
    gSaveBlock1Ptr->trainerHill.field_3D6E_0e = 0;
    gSaveBlock2Ptr->frontier.field_EE0 = 0;
    gBattleOutcome = 0;
    gSaveBlock1Ptr->trainerHill.field_3D6E_0a = 0;
}

void sub_81D58D8(void)
{
    sub_80008E8();
    gSpecialVar_Result = 0;
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0c)
        gSpecialVar_Result++;
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0a && gSaveBlock1Ptr->trainerHill.field_3D6E_0b)
        gSpecialVar_Result++;

    gSaveBlock1Ptr->trainerHill.field_3D6E_0c = 1;
}

void sub_81D5924(void)
{
    u16 itemId = sub_81D6640();

    if (gUnknown_0203CF54->unk4.unkField_2 != 4 || gSaveBlock1Ptr->trainerHill.field_3D6E_0a)
    {
        gSpecialVar_Result = 2;
    }
    else if (AddBagItem(itemId, 1) == TRUE)
    {
        CopyItemName(itemId, gStringVar2);
        gSaveBlock1Ptr->trainerHill.field_3D6E_0a = 1;
        gSaveBlock2Ptr->frontier.field_EF9_0 = 0;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }
}

void sub_81D59D0(void)
{
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0b)
    {
        gSpecialVar_Result = 2;
    }
    else if (sub_81D5DF0(&gSaveBlock1Ptr->trainerHill.field_3D68) > gSaveBlock1Ptr->trainerHill.field_3D64)
    {
        sub_81D5DF4(&gSaveBlock1Ptr->trainerHill.field_3D68, gSaveBlock1Ptr->trainerHill.field_3D64);
        gSaveBlock1Ptr->field_3718[gSaveBlock1Ptr->trainerHill.field_3D6E_1] = gSaveBlock1Ptr->trainerHill.field_3D68;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    gSaveBlock1Ptr->trainerHill.field_3D6E_0b = 1;
}

void sub_81D5A70(void)
{
    if (!gSaveBlock1Ptr->trainerHill.field_3D6E_0c)
    {
        if (gSaveBlock1Ptr->trainerHill.field_3D64 >= HILL_MAX_TIME)
            gSaveBlock1Ptr->trainerHill.field_3D64 = HILL_MAX_TIME;
        else
            sub_80008DC(&gSaveBlock1Ptr->trainerHill.field_3D64);
    }
}

void sub_81D5AB4(void)
{
    gSaveBlock1Ptr->trainerHill.field_3D6E_0d = 1;
}

void sub_81D5AD0(void)
{
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0d)
    {
        gSaveBlock1Ptr->trainerHill.field_3D6E_0d = 0;
        gSpecialVar_Result = 0;
    }
    else if (gSaveBlock1Ptr->trainerHill.field_3D6E_0e)
    {
        gSaveBlock1Ptr->trainerHill.field_3D6E_0e = 0;
        gSpecialVar_Result = 1;
    }
    else
    {
        gSpecialVar_Result = 2;
    }
}

void sub_81D5B2C(void)
{
    s32 total, minutes, secondsWhole, secondsFraction;

    total = gSaveBlock1Ptr->trainerHill.field_3D64;
    if (total >= HILL_MAX_TIME)
        total = HILL_MAX_TIME;

    minutes = total / (60 * 60);
    total %= (60 * 60);
    secondsWhole = total / 60;
    total %= 60;
    secondsFraction = (total * 168) / 100;

    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
}

void sub_81D5BBC(void)
{
    sub_81D56B0();
    if (gUnknown_0203CF54->unk4.unkField_2 != 4)
    {
        ConvertIntToDecimalStringN(gStringVar1, gUnknown_0203CF54->unk4.unkField_2, STR_CONV_MODE_LEFT_ALIGN, 1);
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    sub_81D5710();
}

void sub_81D5C00(void)
{
    sub_81D56B0();
    gSpecialVar_Result = 0;
    sub_81D5710();
}

bool8 sub_81D5C18(void)
{
    if (VarGet(VAR_0x40D6) == 0)
        return FALSE;
    else if (gSaveBlock1Ptr->trainerHill.field_3D6E_0c)
        return FALSE;
    else if (GetCurrentTrainerHillMapId() != 0)
        return TRUE;
    else
        return FALSE;
}

void sub_81D5C5C(void)
{
    if (!sub_81D5C18())
        gSpecialVar_Result = 0;
    else
        gSpecialVar_Result = 1;
}

void nullsub_129(void)
{

}

void nullsub_2(void)
{

}

void PrintOnTrainerHillRecordsWindow(void)
{
    s32 i, x, y;
    u32 total, minutes, secondsWhole, secondsFraction;

    sub_81D56B0();
    FillWindowPixelBuffer(0, 0);
    x = GetStringCenterAlignXOffset(1, gText_TimeBoard, 0xD0);
    AddTextPrinterParameterized3(0, 1, x, 2, gUnknown_0862A5F4, TEXT_SPEED_FF, gText_TimeBoard);

    y = 18;
    for (i = 0; i < 4; i++)
    {
        AddTextPrinterParameterized3(0, 1, 0, y, gUnknown_0862A5F4, TEXT_SPEED_FF, gUnknown_0862A660[i]);
        y += 15;
        total = sub_81D5DF0(&gSaveBlock1Ptr->field_3718[i]);
        minutes = total / (60 * 60);
        total %= (60 * 60);
        ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsWhole = total / 60;
        total %= 60;
        ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsFraction = (total * 168) / 100;
        ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(StringCopy(gStringVar4, gText_TimeCleared), gText_XMinYDotZSec);
        x = GetStringRightAlignXOffset(1, gStringVar4, 0xD0);
        AddTextPrinterParameterized3(0, 1, x, y, gUnknown_0862A5F4, TEXT_SPEED_FF, gStringVar4);
        y += 17;
    }

    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
    sub_81D5710();
}

// In fire red the counter had to be xored by the encryption key in Sav2.
u32 sub_81D5DF0(u32 *src)
{
    return *src;
}

void sub_81D5DF4(u32 *dst, u32 val)
{
    *dst = val;
}

void sub_81D5DF8(void)
{
    u8 i, layoutId;
    struct EventObjectTemplate *eventTemplates = gSaveBlock1Ptr->eventObjectTemplates;

    if (!sub_81D5F48())
        return;

    sub_81D56B0();
    for (i = 0; i < 2; i++)
        gSaveBlock2Ptr->frontier.field_CB4[i] = 0xFFFF;
    CpuFill32(0, gSaveBlock1Ptr->eventObjectTemplates, sizeof(gSaveBlock1Ptr->eventObjectTemplates));

    layoutId = sub_81D5520();
    for (i = 0; i < 2; i++)
    {
        u8 bits;

        eventTemplates[i] = gUnknown_0862A670;
        eventTemplates[i].localId = i + 1;
        eventTemplates[i].graphicsId = FacilityClassToGraphicsId(gUnknown_0203CF54->unk4.unk0[layoutId].trainers[i].facilityClass);
        eventTemplates[i].x = gUnknown_0203CF54->unk4.unk0[layoutId].coords[i] & 0xF;
        eventTemplates[i].y = ((gUnknown_0203CF54->unk4.unk0[layoutId].coords[i] >> 4) & 0xF) + 5;
        bits = i << 2;
        eventTemplates[i].movementType = ((gUnknown_0203CF54->unk4.unk0[layoutId].direction >> bits) & 0xF) + MOVEMENT_TYPE_FACE_UP;
        eventTemplates[i].trainerRange_berryTreeId = (gUnknown_0203CF54->unk4.unk0[layoutId].range >> bits) & 0xF;
        eventTemplates[i].script = EventScript_2C83F0;
        gSaveBlock2Ptr->frontier.field_CB4[i] = i + 1;
    }

    sub_81D5710();
}

bool32 sub_81D5F48(void)
{
    sub_81D56B0();
    sub_81D5710();
    return TRUE;
}

// Functionally equivalent.
#ifdef NONMATCHING
u32 sub_81D5F58(u8 layoutId, u32 bit, u32 arg2, u32 arg3)
{
    u32 var0, var1, var2, var3;

    var0 = (gUnknown_0203CF54->unk4.unk0[layoutId].unk3A0[arg2] >> (15 - bit)) & 1;
    var1 = gUnknown_0203CF54->unk4.unk0[layoutId].data[arg2 * arg3 + bit];
    var3 = 0x200;
    var2 = 0x3000;

    return ((var0 << 10) | var2) | (var1 | var3);
}
#else
NAKED
u32 sub_81D5F58(u8 layoutId, u32 bit, u32 arg2, u32 arg3)
{
    asm_unified("\n\
    push {r4,r5,lr}\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	ldr r4, =gUnknown_0203CF54\n\
	ldr r4, [r4]\n\
	mov r12, r4\n\
	lsls r4, r2, 1\n\
	lsls r5, r0, 4\n\
	subs r5, r0\n\
	lsls r5, 3\n\
	subs r5, r0\n\
	lsls r5, 3\n\
	adds r4, r5\n\
	movs r0, 0xE8\n\
	lsls r0, 2\n\
	add r0, r12\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	movs r4, 0xF\n\
	subs r4, r1\n\
	asrs r0, r4\n\
	movs r4, 0x1\n\
	ands r0, r4\n\
	muls r2, r3\n\
	adds r2, r1\n\
	adds r2, r5\n\
	movs r1, 0xA8\n\
	lsls r1, 2\n\
	add r1, r12\n\
	adds r1, r2\n\
	ldrb r1, [r1]\n\
	movs r2, 0x80\n\
	lsls r2, 2\n\
	adds r3, r2, 0\n\
	movs r2, 0xC0\n\
	lsls r2, 6\n\
	lsls r0, 10\n\
	orrs r0, r2\n\
	orrs r1, r3\n\
	orrs r0, r1\n\
	pop {r4,r5}\n\
	pop {r1}\n\
	bx r1\n\
	.pool");
}
#endif // NONMATCHING

void sub_81D5FB4(u16 *mapArg)
{
    s32 i, j;
    u16 *src, *dst;
    u8 layoutId = GetCurrentTrainerHillMapId();

    if (layoutId == 6)
    {
        InitMapFromSavedGame();
        return;
    }

    sub_81D56B0();
    if (layoutId == 5)
    {
        InitMapFromSavedGame();
        sub_81D5710();
        return;
    }

    layoutId = sub_81D5520();
    src = gMapHeader.mapLayout->map;
    gBackupMapLayout.map = mapArg;
    gBackupMapLayout.width = 31;
    gBackupMapLayout.height = 35;
    dst = mapArg + 224;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 16; j++)
            dst[j] = src[j];
        dst += 31;
        src += 16;
    }

    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
            dst[j] = sub_81D5F58(layoutId, j, i, 0x10);
        dst += 31;
    }

    mapheader_run_script_with_tag_x1();
    sub_81D5710();
}

bool32 InTrainerHill(void)
{
    bool32 ret;

    if (gMapHeader.mapLayoutId == 0x19F
            || gMapHeader.mapLayoutId == 0x1A0
            || gMapHeader.mapLayoutId == 0x1A1
            || gMapHeader.mapLayoutId == 0x1A2)
        ret = TRUE;
    else
        ret = FALSE;

    return ret;
}

u8 GetCurrentTrainerHillMapId(void)
{
    u8 ret;

    if (gMapHeader.mapLayoutId == 0x19F)
        ret = 1;
    else if (gMapHeader.mapLayoutId == 0x1A0)
        ret = 2;
    else if (gMapHeader.mapLayoutId == 0x1A1)
        ret = 3;
    else if (gMapHeader.mapLayoutId == 0x1A2)
        ret = 4;
    else if (gMapHeader.mapLayoutId == 0x1A3)
        ret = 5;
    else if (gMapHeader.mapLayoutId == 0x19E)
        ret = 6;
    else
        ret = 0;

    return ret;
}

bool32 sub_81D6100(void)
{
    bool32 ret;

    if (gMapHeader.mapLayoutId == 0x1A3)
        ret = TRUE;
    else
        ret = FALSE;

    return ret;
}

const struct WarpEvent* sub_81D6120(void)
{
    const struct MapHeader *header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_HILL_4F), MAP_NUM(TRAINER_HILL_4F));

    return &header->events->warps[1];
}

const struct WarpEvent* sub_81D6134(u8 warpEventId)
{
    u8 id;
    const struct MapHeader *header;

    if (warpEventId == 1)
        return &gMapHeader.events->warps[1];

    id = sub_81D6490();
    if ((u8)(id - 1) >= 4)
        id = 4;

    header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_HILL_4F), gUnknown_0862A688[id - 1]);
    return &header->events->warps[0];
}

u16 sub_81D6180(u8 localId)
{
    return gSaveBlock2Ptr->frontier.field_CB4[localId - 1];
}

bool8 GetTrainerHillTrainerFlag(u8 eventObjectId)
{
    u32 layoutId = sub_81D5520() * 2;
    u8 bitId = gEventObjects[eventObjectId].localId - 1 + layoutId;

    return gSaveBlock2Ptr->frontier.field_EE0 & gBitTable[bitId];
}

void sub_81D61E8(void)
{
    u8 i;
    u8 layoutId = sub_81D5520() * 2;

    for (i = 0; i < 2; i++)
    {
        if (gSaveBlock2Ptr->frontier.field_CB4[i] == gTrainerBattleOpponent_A)
        {
            gSaveBlock2Ptr->frontier.field_EE0 |= gBitTable[layoutId + i];
            break;
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        for (i = 0; i < 2; i++)
        {
            if (gSaveBlock2Ptr->frontier.field_CB4[i] == gTrainerBattleOpponent_B)
            {
                gSaveBlock2Ptr->frontier.field_EE0 |= gBitTable[layoutId + i];
                break;
            }
        }
    }
}

const u8 *sub_81D62AC(void)
{
    return EventScript_2C83F0;
}

void sub_81D62B4(void)
{
    CopyTrainerHillTrainerText(5, gSpecialVar_LastTalked);
    sub_80982B8();
}

void sub_81D62CC(u16 trainerId, u8 firstMonId)
{
    u8 trId, level;
    s32 i, layoutId, arrId;

    if ((u16)(trainerId - 1) > 1)
        return;

    trId = trainerId - 1;
    sub_81D56B0();
    level = GetHighestLevelInPlayerParty();
    layoutId = sub_81D5520();
    for (i = firstMonId, arrId = 0; i < firstMonId + 3; i++, arrId++)
    {
        u8 id = gUnknown_0862A698[trId][arrId];
        struct Pokemon *mon = &gEnemyParty[i];

        CreateBattleTowerMon(mon, &gUnknown_0203CF54->unk4.unk0[layoutId].trainers[trId].mons[id]);
        sub_81D642C(mon, level);
    }

    sub_81D5710();
}

void sub_81D6384(void)
{
    ZeroEnemyPartyMons();
    sub_81D62CC(gTrainerBattleOpponent_A, 0);
}

void sub_81D639C(void)
{
    ZeroEnemyPartyMons();
    sub_81D62CC(gTrainerBattleOpponent_A, 0);
    sub_81D62CC(gTrainerBattleOpponent_B, 3);
}

// This function is unused, but my best guess is
// it was supposed to return AI scripts for trainer
// hill trainers.
u32 sub_81D63C4(void)
{
    return 7;
}

u8 sub_81D63C8(u16 trainerId)
{
    s32 i;
    u8 trId, facilityClass;

    sub_81D56B0();
    trId = trainerId - 1;
    facilityClass = gUnknown_0203CF54->unk4.unk0[gUnknown_0203CF54->layoutId].trainers[trId].facilityClass;
    sub_81D5710();

    for (i = 0; i < ARRAY_COUNT(gUnknown_0862A3B4); i++)
    {
        if (gUnknown_0862A3B4[i].trainerClass == gFacilityClassToTrainerClass[facilityClass])
            return gUnknown_0862A3B4[i].musicId;
    }

    return 0;
}

void sub_81D642C(struct Pokemon *mon, u8 level)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = gExperienceTables[gBaseStats[species].growthRate][level];

    SetMonData(mon, MON_DATA_EXP, &exp);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    CalculateMonStats(mon);
}

u8 sub_81D6490(void)
{
    u8 ret;

    sub_81D56B0();
    ret = gUnknown_0203CF54->unk4.unkField_2;
    sub_81D5710();

    return ret;
}

void sub_81D64AC(void)
{
    gSaveBlock2Ptr->frontier.field_EE0 = 0xFF;
}

void sub_81D64C0(void)
{
    if (sub_81D6534() == TRUE)
        LoadPalette(gUnknown_0862A5D4, 0x70, 0x20);
}

void sub_81D64DC(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_EF9_1;
}

void sub_81D64FC(void)
{
    gSaveBlock2Ptr->frontier.field_EF9_1 = 1;
}

void sub_81D6518(void)
{
    gSaveBlock2Ptr->frontier.field_EF9_1 = 0;
}

bool32 sub_81D6534(void)
{
    if (!sub_81D5C18() || GetCurrentTrainerHillMapId() == 6)
        return FALSE;

    sub_81D5C00();
    if (gSpecialVar_Result == 0)
        return FALSE;
    else
        return TRUE;
}

void sub_81D6568(void)
{
    if (gSaveBlock1Ptr->trainerHill.field_3D6E_0d)
        gSpecialVar_Result = 0;
    else
        gSpecialVar_Result = 1;
}

void sub_81D65A0(void)
{
    gSaveBlock1Ptr->trainerHill.field_3D6E_1 = gSpecialVar_0x8005;
    gSaveBlock1Ptr->trainerHill.field_3D68 = gSaveBlock1Ptr->field_3718[gSpecialVar_0x8005];
}

u8 sub_81D65E8(u8 arg0)
{
    u8 var, i, modBy;

    var = 0;
    for (i = 0; i < 4; i++)
    {
        var ^= gUnknown_0203CF54->unk4.unk0[i].unk0 & 0x1F;
        var ^= gUnknown_0203CF54->unk4.unk0[i].unk1 & 0x1F;
    }

    if (arg0)
        modBy = 10;
    else
        modBy = 5;

    var %= modBy;
    return var;
}

u16 sub_81D6640(void)
{
    u8 i;
    const u16 *ptr;
    s32 var = 0, var2, minutes, id;

    for (i = 0; i < 4; i++)
    {
        var += gUnknown_0203CF54->unk4.unk0[i].unk0;
        var += gUnknown_0203CF54->unk4.unk0[i].unk1;
    }

    var2 = var / 256;
    var2 %= 2;
    if (FlagGet(FLAG_SYS_GAME_CLEAR) && gUnknown_0203CF54->unk4.unkField_0 == 8)
        i = sub_81D65E8(1);
    else
        i = sub_81D65E8(0);

    if (gSaveBlock1Ptr->trainerHill.field_3D6E_1 == 3)
        i = (i + 1) % 10;

    ptr = gUnknown_0862A5CC[var2][i];
    minutes = (signed)(gSaveBlock1Ptr->trainerHill.field_3D64) / (60 * 60);
    if (minutes < 12)
        id = 0;
    else if (minutes < 13)
        id = 1;
    else if (minutes < 14)
        id = 2;
    else if (minutes < 16)
        id = 3;
    else if (minutes < 18)
        id = 4;
    else
        id = 5;

    return ptr[id];
}
