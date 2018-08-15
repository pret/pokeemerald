#include "global.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_frontier_1.h"
#include "event_data.h"
#include "overworld.h"
#include "util.h"
#include "malloc.h"
#include "constants/species.h"

struct Unknown_0203BC8C_Struct
{
    u16 field_0;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 field_E;
};

extern struct Unknown_0203BC8C_Struct *gUnknown_0203BC8C;

extern void sub_81B8558(void);
extern u32 sub_81A39C4(void);
extern u16 sub_8162548(u8, u8);
extern u16 sub_8163524(u16);
extern u8 sub_8165C40(void);

extern u8 gUnknown_0203CEF8[];

extern void (* const gUnknown_0860D090[])(void);
extern const u32 gUnknown_0860D0EC[][2];
extern const u32 gUnknown_0860D0FC[][2];

// This file's functions.
u8 sub_8190168(u16);
void sub_818F720(u16 species, s32 level, s32 ivs, u8 evBits, u8 nature, s32 *stats);

// code
void sub_818E9AC(void)
{
    gUnknown_0860D090[gSpecialVar_0x8004]();
}

void sub_818E9CC(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.chosenLvl;
    u32 id = VarGet(VAR_0x40CE);

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860D0EC[id][lvlMode]))
        gSaveBlock2Ptr->frontier.field_D0C[id][lvlMode] = 0;

    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

void sub_818EA84(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.chosenLvl;
    u32 id = VarGet(VAR_0x40CE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D0C[id][lvlMode];
        break;
    case 1:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_0860D0EC[id][lvlMode]) != 0);
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_0;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_1;
        break;
    case 4:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_2;
        break;
    case 5:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_3;
        break;
    case 6:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_5;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_4;
        }
        else
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_1;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_0;
        }
        break;
    case 7:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_7;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_6;
        }
        else
        {
            if (lvlMode)
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_3;
            else
                gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D08_2;
        }
        break;
    case 8:
        sub_81B8558();
        gUnknown_0203CEF8[0] = gSaveBlock2Ptr->frontier.field_CB0;
        gUnknown_0203CEF8[1] = gSaveBlock2Ptr->frontier.field_CB0 >> 8;
        break;
    case 9:
        gSpecialVar_Result = (gSaveBlock2Ptr->frontier.field_D0A * 2) - 3 + gSaveBlock2Ptr->frontier.field_D0B;
        break;
    }
}

void sub_818ED28(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.chosenLvl;
    u32 id = VarGet(VAR_0x40CE);

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSaveBlock2Ptr->frontier.field_D0C[id][lvlMode] = gSpecialVar_0x8006;
        break;
    case 1:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_0860D0EC[id][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_0860D0FC[id][lvlMode];
        break;
    case 2:
        gSaveBlock2Ptr->frontier.field_D08_0 = gSpecialVar_0x8006;
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_D08_1 = gSpecialVar_0x8006;
        break;
    case 4:
        gSaveBlock2Ptr->frontier.field_D08_2 = gSpecialVar_0x8006;
        break;
    case 5:
        gSaveBlock2Ptr->frontier.field_D08_3 = gSpecialVar_0x8006;
        break;
    case 6:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_5 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_4 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_1 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_0 = gSpecialVar_0x8006;
        }
        break;
    case 7:
        if (VarGet(VAR_0x40CE) == 1)
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_7 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_6 = gSpecialVar_0x8006;
        }
        else
        {
            if (lvlMode)
                gSaveBlock2Ptr->frontier.field_D08_3 = gSpecialVar_0x8006;
            else
                gSaveBlock2Ptr->frontier.field_D08_2 = gSpecialVar_0x8006;
        }
        break;
    case 8:
        gSaveBlock2Ptr->frontier.field_CB0 = T1_READ_16(gUnknown_0203CEF8);
        break;
    }
}

#ifdef NONMATCHING
// Not even close, this function is insane.
void sub_818F02C(void)
{
    s32 i, j, k, l;
    u32 array[16];
    u32 var_28;
    u32 var_24;
    s32 var_38;
    s32 monTypesBits, monTypesCount;
    u32 var_54 = 0;
    u32 var_50 = 0;
    u32 var_4C = 0;
    u32 *var_40 = AllocZeroed(0x20);
    u16 *var_44 = AllocZeroed(0x18);
    u32 var_48;

    gSaveBlock2Ptr->frontier.field_D0A = gSaveBlock2Ptr->frontier.chosenLvl + 1;
    gSaveBlock2Ptr->frontier.field_D0B = VarGet(VAR_0x40CE) + 1;
    gSaveBlock2Ptr->frontier.field_D24[0].unk0 = 0x3FF;
    gSaveBlock2Ptr->frontier.field_D24[0].unk1 = 0;
    gSaveBlock2Ptr->frontier.field_D24[0].unk2 = 0;
    gSaveBlock2Ptr->frontier.field_D24[0].unk3 = 0;

    for (i = 0; i < 3; i++)
    {
        gSaveBlock2Ptr->frontier.field_D64[i] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1], MON_DATA_SPECIES, NULL);
        for (j = 0; j < 4; j++)
            gSaveBlock2Ptr->frontier.field_EFC[i].moves[j] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1], MON_DATA_MOVE1 + j, NULL);
        for (j = 0; j < 6; j++)
            gSaveBlock2Ptr->frontier.field_EFC[i].evs[j] = GetMonData(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1], MON_DATA_HP_EV + j, NULL);

        gSaveBlock2Ptr->frontier.field_EFC[i].nature = GetNature(&gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1]);
    }

    var_28 = 4;
    var_24 = 6;
    for (l = j; l < 16; l++)
    {
        u16 val;
        if (l > 5)
        {
            while (1)
            {
                val = sub_8162548(sub_81A39C4(), 0);
                for (k = 1; k < l; k++)
                {
                    if (gSaveBlock2Ptr->frontier.field_D24[k].unk0 == val)
                        break;
                }
                if (k != l)
                {
                    gSaveBlock2Ptr->frontier.field_D24[var_28].unk0 = val;
                    break;
                }
            }
        }
        else
        {
            while (1)
            {
                val = sub_8162548(sub_81A39C4() + 1, 0);
                for (k = 1; k < l; k++)
                {
                    if (gSaveBlock2Ptr->frontier.field_D24[k].unk0 == val)
                        break;
                }
                if (k != l)
                {
                    gSaveBlock2Ptr->frontier.field_D24[var_28].unk0 = val;
                    break;
                }
            }
        }

        for (var_38 = 0; var_38 < 3; var_38++)
        {
            u16 val2;
            do
            {
                val2 = sub_8163524(val);
                for (i = 0; i < l; i++)
                {
                    if (gSaveBlock2Ptr->frontier.field_D64[i] == val2)
                        break;
                    if (var_54 == gUnknown_0203BC8C[val2].field_0)
                        break;
                    if (var_50 == gUnknown_0203BC8C[val2].field_0)
                        break;
                    if (gUnknown_0203BC8C[gSaveBlock2Ptr->frontier.field_D64[i]].field_A == gUnknown_0203BC8C[val2].field_A)
                        break;
                }
            } while (i != var_38);

            gSaveBlock2Ptr->frontier.field_D64[var_24] = val2;
            array[var_38] = gUnknown_0203BC8C[val2].field_0;
        }

        gSaveBlock2Ptr->frontier.field_D24[var_28].unk1 = 0;
        gSaveBlock2Ptr->frontier.field_D24[var_28].unk2 = 0;
        gSaveBlock2Ptr->frontier.field_D24[var_28].unk3 = 0;
    }

    for (i = 0; i < 3; i++)
    {
        struct Pokemon *mon = &gPlayerParty[gSaveBlock2Ptr->frontier.field_CAA[i] - 1];
        var_44[0] += GetMonData(mon, MON_DATA_ATK, NULL);
        var_44[0] += GetMonData(mon, MON_DATA_DEF, NULL);
        var_44[0] += GetMonData(mon, MON_DATA_SPATK, NULL);
        var_44[0] += GetMonData(mon, MON_DATA_SPDEF, NULL);
        var_44[0] += GetMonData(mon, MON_DATA_SPEED, NULL);
        var_44[0] += GetMonData(mon, MON_DATA_MAX_HP, NULL);
        monTypesBits |= gBitTable[gBaseStats[GetMonData(mon, MON_DATA_SPECIES, NULL)].type1];
        monTypesBits |= gBitTable[gBaseStats[GetMonData(mon, MON_DATA_SPECIES, NULL)].type2];
    }

    for (monTypesCount = 0, i = 0; i < 31; i++)
    {
        if (monTypesBits & 1)
            monTypesCount++;
        monTypesBits >>= 1;
    }

    var_48 = sub_8165C40();
    var_44[0] += (monTypesCount * var_48) / 20;

    for (i = 0; i < 16; i++)
    {
        u8 r8;

        var_44[i + 1] = 0;
        r8 = sub_8190168(gSaveBlock2Ptr->frontier.field_D24[i].unk0);
        for (j = 0; j < 3; j++)
        {
            sub_818F720(gSaveBlock2Ptr->frontier.field_D64[i]);
        }
    }

    Free(var_44);
    Free(var_40);
}
#else
NAKED
void sub_818F02C(void)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x3C\n\
	movs r0, 0\n\
	str r0, [sp, 0x8]\n\
	str r0, [sp, 0xC]\n\
	str r0, [sp, 0x10]\n\
	movs r0, 0x20\n\
	bl AllocZeroed\n\
	str r0, [sp, 0x18]\n\
	movs r0, 0x18\n\
	bl AllocZeroed\n\
	str r0, [sp, 0x1C]\n\
	ldr r4, =gSaveBlock2Ptr\n\
	ldr r1, [r4]\n\
	ldr r2, =0x00000ca9\n\
	adds r0, r1, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, 30\n\
	lsrs r0, 30\n\
	adds r0, 0x1\n\
	ldr r3, =0x00000d0a\n\
	adds r1, r3\n\
	strb r0, [r1]\n\
	ldr r0, =0x000040ce\n\
	bl VarGet\n\
	ldr r1, [r4]\n\
	adds r0, 0x1\n\
	ldr r5, =0x00000d0b\n\
	adds r1, r5\n\
	strb r0, [r1]\n\
	ldr r2, [r4]\n\
	ldr r7, =0x00000d24\n\
	adds r3, r2, r7\n\
	ldrh r0, [r3]\n\
	ldr r5, =0x000003ff\n\
	adds r1, r5, 0\n\
	orrs r0, r1\n\
	strh r0, [r3]\n\
	ldr r3, =0x00000d25\n\
	adds r2, r3\n\
	ldrb r1, [r2]\n\
	movs r0, 0x5\n\
	negs r0, r0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r1, [r4]\n\
	adds r1, r3\n\
	ldrb r2, [r1]\n\
	movs r0, 0x19\n\
	negs r0, r0\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	ldr r1, [r4]\n\
	adds r1, r3\n\
	ldrb r2, [r1]\n\
	movs r0, 0x1F\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	movs r7, 0\n\
	mov r10, r7\n\
	mov r8, r4\n\
	ldr r0, =gBattleScripting + 0x14\n\
	mov r9, r0\n\
	movs r4, 0\n\
_0818F0BA:\n\
	mov r1, r8\n\
	ldr r0, [r1]\n\
	ldr r2, =0x00000caa\n\
	adds r0, r2\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	movs r3, 0x64\n\
	muls r0, r3\n\
	add r0, r9\n\
	movs r1, 0xB\n\
	movs r2, 0\n\
	bl GetMonData\n\
	mov r5, r8\n\
	ldr r1, [r5]\n\
	ldr r7, =0x00000d64\n\
	adds r1, r7\n\
	adds r1, r4\n\
	strh r0, [r1]\n\
	movs r5, 0\n\
	mov r0, r10\n\
	lsls r7, r0, 4\n\
	adds r6, r7, 0\n\
_0818F0E8:\n\
	mov r1, r8\n\
	ldr r0, [r1]\n\
	ldr r2, =0x00000caa\n\
	adds r0, r2\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	movs r3, 0x64\n\
	muls r0, r3\n\
	add r0, r9\n\
	adds r1, r5, 0\n\
	adds r1, 0xD\n\
	movs r2, 0\n\
	bl GetMonData\n\
	mov r2, r8\n\
	ldr r1, [r2]\n\
	ldr r3, =0x00000efc\n\
	adds r1, r3\n\
	adds r1, r6\n\
	strh r0, [r1]\n\
	adds r6, 0x2\n\
	adds r5, 0x1\n\
	cmp r5, 0x3\n\
	ble _0818F0E8\n\
	movs r5, 0\n\
	ldr r6, =gSaveBlock2Ptr\n\
_0818F11C:\n\
	ldr r0, [r6]\n\
	ldr r1, =0x00000caa\n\
	adds r0, r1\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	movs r2, 0x64\n\
	muls r0, r2\n\
	add r0, r9\n\
	adds r1, r5, 0\n\
	adds r1, 0x1A\n\
	movs r2, 0\n\
	bl GetMonData\n\
	ldr r1, [r6]\n\
	adds r2, r5, r7\n\
	ldr r3, =0x00000f04\n\
	adds r1, r3\n\
	adds r1, r2\n\
	strb r0, [r1]\n\
	adds r5, 0x1\n\
	cmp r5, 0x5\n\
	ble _0818F11C\n\
	mov r5, r8\n\
	ldr r0, [r5]\n\
	ldr r1, =0x00000caa\n\
	adds r0, r1\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	movs r2, 0x64\n\
	muls r0, r2\n\
	add r0, r9\n\
	bl GetNature\n\
	ldr r1, [r5]\n\
	adds r1, r7\n\
	ldr r3, =0x00000f0a\n\
	adds r1, r3\n\
	strb r0, [r1]\n\
	adds r4, 0x2\n\
	movs r5, 0x1\n\
	add r10, r5\n\
	mov r7, r10\n\
	cmp r7, 0x2\n\
	ble _0818F0BA\n\
	mov r10, r5\n\
	movs r0, 0x4\n\
	str r0, [sp, 0x34]\n\
	movs r1, 0x6\n\
	str r1, [sp, 0x38]\n\
_0818F17E:\n\
	mov r2, r10\n\
	cmp r2, 0x5\n\
	ble _0818F22C\n\
_0818F184:\n\
	bl sub_81A39C4\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	movs r1, 0\n\
	bl sub_8162548\n\
	lsls r0, 16\n\
	lsrs r4, r0, 16\n\
	movs r5, 0x1\n\
	cmp r5, r10\n\
	bge _0818F1CA\n\
	ldr r3, =gSaveBlock2Ptr\n\
	ldr r0, [r3]\n\
	ldr r7, =0x00000d28\n\
	adds r0, r7\n\
	ldrh r0, [r0]\n\
	lsls r0, 22\n\
	lsrs r0, 22\n\
	adds r2, r3, 0\n\
	cmp r0, r4\n\
	beq _0818F1CA\n\
	ldr r3, =0x00000d24\n\
_0818F1B2:\n\
	adds r5, 0x1\n\
	cmp r5, r10\n\
	bge _0818F1CA\n\
	ldr r0, [r2]\n\
	lsls r1, r5, 2\n\
	adds r0, r1\n\
	adds r0, r3\n\
	ldrh r0, [r0]\n\
	lsls r0, 22\n\
	lsrs r0, 22\n\
	cmp r0, r4\n\
	bne _0818F1B2\n\
_0818F1CA:\n\
	cmp r5, r10\n\
	bne _0818F184\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r3, [r0]\n\
	ldr r1, [sp, 0x34]\n\
	adds r3, r1\n\
	ldr r2, =0x00000d24\n\
	adds r3, r2\n\
	ldr r5, =0x000003ff\n\
	adds r0, r5, 0\n\
	adds r2, r4, 0\n\
	ands r2, r0\n\
	ldrh r0, [r3]\n\
	ldr r7, =0xfffffc00\n\
	adds r1, r7, 0\n\
	b _0818F292\n\
	.pool\n\
_0818F22C:\n\
	bl sub_81A39C4\n\
	adds r0, 0x1\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	movs r1, 0\n\
	bl sub_8162548\n\
	lsls r0, 16\n\
	lsrs r4, r0, 16\n\
	movs r5, 0x1\n\
	cmp r5, r10\n\
	bge _0818F274\n\
	ldr r1, =gSaveBlock2Ptr\n\
	ldr r0, [r1]\n\
	ldr r2, =0x00000d28\n\
	adds r0, r2\n\
	ldrh r0, [r0]\n\
	lsls r0, 22\n\
	lsrs r0, 22\n\
	adds r2, r1, 0\n\
	cmp r0, r4\n\
	beq _0818F274\n\
	ldr r3, =0x00000d24\n\
_0818F25C:\n\
	adds r5, 0x1\n\
	cmp r5, r10\n\
	bge _0818F274\n\
	ldr r0, [r2]\n\
	lsls r1, r5, 2\n\
	adds r0, r1\n\
	adds r0, r3\n\
	ldrh r0, [r0]\n\
	lsls r0, 22\n\
	lsrs r0, 22\n\
	cmp r0, r4\n\
	bne _0818F25C\n\
_0818F274:\n\
	cmp r5, r10\n\
	bne _0818F22C\n\
	ldr r5, =gSaveBlock2Ptr\n\
	ldr r3, [r5]\n\
	ldr r7, [sp, 0x34]\n\
	adds r3, r7\n\
	ldr r0, =0x00000d24\n\
	adds r3, r0\n\
	ldr r1, =0x000003ff\n\
	adds r0, r1, 0\n\
	adds r2, r4, 0\n\
	ands r2, r0\n\
	ldrh r0, [r3]\n\
	ldr r5, =0xfffffc00\n\
	adds r1, r5, 0\n\
_0818F292:\n\
	ands r0, r1\n\
	orrs r0, r2\n\
	strh r0, [r3]\n\
	movs r5, 0\n\
	lsls r4, 16\n\
	str r4, [sp, 0x2C]\n\
	ldr r7, [sp, 0x38]\n\
	str r7, [sp, 0x20]\n\
_0818F2A2:\n\
	lsls r0, r5, 1\n\
	mov r9, r0\n\
	adds r1, r5, 0x1\n\
	str r1, [sp, 0x24]\n\
	lsls r2, r5, 2\n\
	str r2, [sp, 0x28]\n\
_0818F2AE:\n\
	ldr r3, [sp, 0x2C]\n\
	lsrs r0, r3, 16\n\
	bl sub_8163524\n\
	lsls r0, 16\n\
	lsrs r6, r0, 16\n\
	movs r7, 0\n\
	cmp r7, r5\n\
	bge _0818F300\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r0, [r0]\n\
	ldr r1, [sp, 0x8]\n\
	mov r8, r1\n\
	ldr r2, [sp, 0xC]\n\
	mov r12, r2\n\
	ldr r3, =0x00000d64\n\
	adds r0, r3\n\
	ldr r1, [sp, 0x20]\n\
	adds r4, r1, r0\n\
_0818F2D4:\n\
	ldrh r3, [r4]\n\
	cmp r3, r6\n\
	beq _0818F300\n\
	ldr r2, =gUnknown_0203BC8C\n\
	ldr r1, [r2]\n\
	lsls r0, r6, 4\n\
	adds r2, r0, r1\n\
	ldrh r0, [r2]\n\
	cmp r8, r0\n\
	beq _0818F300\n\
	cmp r12, r0\n\
	beq _0818F300\n\
	lsls r0, r3, 4\n\
	adds r0, r1\n\
	ldrb r0, [r0, 0xA]\n\
	ldrb r2, [r2, 0xA]\n\
	cmp r0, r2\n\
	beq _0818F300\n\
	adds r4, 0x2\n\
	adds r7, 0x1\n\
	cmp r7, r5\n\
	blt _0818F2D4\n\
_0818F300:\n\
	cmp r7, r5\n\
	bne _0818F2AE\n\
	ldr r3, =gSaveBlock2Ptr\n\
	ldr r0, [r3]\n\
	ldr r1, [sp, 0x38]\n\
	add r1, r9\n\
	ldr r5, =0x00000d64\n\
	adds r0, r5\n\
	adds r0, r1\n\
	strh r6, [r0]\n\
	ldr r2, [sp, 0x28]\n\
	add r2, sp\n\
	adds r2, 0x8\n\
	ldr r0, =gUnknown_0203BC8C\n\
	ldr r1, [r0]\n\
	lsls r0, r6, 4\n\
	adds r0, r1\n\
	ldrh r0, [r0]\n\
	str r0, [r2]\n\
	ldr r5, [sp, 0x24]\n\
	cmp r5, 0x2\n\
	ble _0818F2A2\n\
	ldr r2, [r3]\n\
	ldr r7, [sp, 0x34]\n\
	adds r2, r7\n\
	ldr r0, =0x00000d25\n\
	adds r2, r0\n\
	ldrb r0, [r2]\n\
	movs r3, 0x5\n\
	negs r3, r3\n\
	adds r1, r3, 0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r5, =gSaveBlock2Ptr\n\
	ldr r2, [r5]\n\
	adds r2, r7\n\
	ldr r7, =0x00000d25\n\
	adds r2, r7\n\
	ldrb r0, [r2]\n\
	subs r3, 0x14\n\
	adds r1, r3, 0\n\
	ands r0, r1\n\
	strb r0, [r2]\n\
	ldr r1, [r5]\n\
	ldr r5, [sp, 0x34]\n\
	adds r1, r5\n\
	adds r1, r7\n\
	ldrb r2, [r1]\n\
	movs r0, 0x1F\n\
	ands r0, r2\n\
	strb r0, [r1]\n\
	adds r5, 0x4\n\
	str r5, [sp, 0x34]\n\
	ldr r7, [sp, 0x38]\n\
	adds r7, 0x6\n\
	str r7, [sp, 0x38]\n\
	movs r0, 0x1\n\
	add r10, r0\n\
	mov r1, r10\n\
	cmp r1, 0xF\n\
	bgt _0818F37C\n\
	b _0818F17E\n\
_0818F37C:\n\
	movs r7, 0\n\
	ldr r2, [sp, 0x18]\n\
	strh r7, [r2]\n\
	movs r3, 0\n\
	mov r10, r3\n\
	ldr r6, =gBitTable\n\
	ldr r5, =gBaseStats\n\
_0818F38A:\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r0, [r0]\n\
	mov r2, r10\n\
	lsls r1, r2, 1\n\
	ldr r3, =0x00000caa\n\
	adds r0, r3\n\
	adds r0, r1\n\
	ldrh r0, [r0]\n\
	subs r4, r0, 0x1\n\
	movs r0, 0x64\n\
	muls r4, r0\n\
	ldr r0, =gPlayerParty\n\
	adds r4, r0\n\
	adds r0, r4, 0\n\
	movs r1, 0x3B\n\
	movs r2, 0\n\
	bl GetMonData\n\
	ldr r2, [sp, 0x18]\n\
	ldrh r1, [r2]\n\
	adds r1, r0\n\
	strh r1, [r2]\n\
	adds r0, r4, 0\n\
	movs r1, 0x3C\n\
	movs r2, 0\n\
	bl GetMonData\n\
	ldr r3, [sp, 0x18]\n\
	ldrh r1, [r3]\n\
	adds r1, r0\n\
	strh r1, [r3]\n\
	adds r0, r4, 0\n\
	movs r1, 0x3E\n\
	movs r2, 0\n\
	bl GetMonData\n\
	ldr r2, [sp, 0x18]\n\
	ldrh r1, [r2]\n\
	adds r1, r0\n\
	strh r1, [r2]\n\
	adds r0, r4, 0\n\
	movs r1, 0x3F\n\
	movs r2, 0\n\
	bl GetMonData\n\
	ldr r3, [sp, 0x18]\n\
	ldrh r1, [r3]\n\
	adds r1, r0\n\
	strh r1, [r3]\n\
	adds r0, r4, 0\n\
	movs r1, 0x3D\n\
	movs r2, 0\n\
	bl GetMonData\n\
	ldr r2, [sp, 0x18]\n\
	ldrh r1, [r2]\n\
	adds r1, r0\n\
	strh r1, [r2]\n\
	adds r0, r4, 0\n\
	movs r1, 0x3A\n\
	movs r2, 0\n\
	bl GetMonData\n\
	ldr r3, [sp, 0x18]\n\
	ldrh r1, [r3]\n\
	adds r1, r0\n\
	strh r1, [r3]\n\
	adds r0, r4, 0\n\
	movs r1, 0xB\n\
	movs r2, 0\n\
	bl GetMonData\n\
	lsls r1, r0, 3\n\
	subs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r5\n\
	ldrb r0, [r1, 0x6]\n\
	lsls r0, 2\n\
	adds r0, r6\n\
	ldr r0, [r0]\n\
	orrs r7, r0\n\
	adds r0, r4, 0\n\
	movs r1, 0xB\n\
	movs r2, 0\n\
	bl GetMonData\n\
	lsls r1, r0, 3\n\
	subs r1, r0\n\
	lsls r1, 2\n\
	adds r1, r5\n\
	ldrb r0, [r1, 0x7]\n\
	lsls r0, 2\n\
	adds r0, r6\n\
	ldr r0, [r0]\n\
	orrs r7, r0\n\
	movs r0, 0x1\n\
	add r10, r0\n\
	mov r1, r10\n\
	cmp r1, 0x2\n\
	ble _0818F38A\n\
	movs r4, 0\n\
	movs r1, 0x1\n\
	movs r5, 0x1F\n\
_0818F458:\n\
	adds r0, r7, 0\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _0818F462\n\
	adds r4, 0x1\n\
_0818F462:\n\
	asrs r7, 1\n\
	subs r5, 0x1\n\
	cmp r5, 0\n\
	bge _0818F458\n\
	bl sub_8165C40\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	str r0, [sp, 0x14]\n\
	adds r2, r0, 0\n\
	adds r0, r4, 0\n\
	muls r0, r2\n\
	movs r1, 0x14\n\
	bl __divsi3\n\
	ldr r3, [sp, 0x18]\n\
	ldrh r1, [r3]\n\
	adds r1, r0\n\
	strh r1, [r3]\n\
	movs r5, 0x1\n\
	mov r10, r5\n\
	adds r6, r3, 0\n\
	adds r6, 0x2\n\
	movs r7, 0x2\n\
	str r7, [sp, 0x30]\n\
_0818F494:\n\
	movs r7, 0\n\
	strh r7, [r6]\n\
	ldr r1, =gSaveBlock2Ptr\n\
	ldr r0, [r1]\n\
	mov r2, r10\n\
	lsls r1, r2, 2\n\
	adds r0, r1\n\
	ldr r3, =0x00000d24\n\
	adds r0, r3\n\
	ldrh r0, [r0]\n\
	lsls r0, 22\n\
	lsrs r0, 22\n\
	bl sub_8190168\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	mov r8, r0\n\
	movs r5, 0\n\
	ldr r0, [sp, 0x30]\n\
	mov r9, r0\n\
_0818F4BC:\n\
	ldr r1, =gSaveBlock2Ptr\n\
	ldr r0, [r1]\n\
	mov r4, r9\n\
	add r4, r10\n\
	adds r4, r5\n\
	lsls r4, 1\n\
	ldr r2, =0x00000d64\n\
	adds r0, r2\n\
	adds r0, r4\n\
	ldrh r1, [r0]\n\
	ldr r3, =gUnknown_0203BC8C\n\
	ldr r0, [r3]\n\
	lsls r1, 4\n\
	adds r1, r0\n\
	ldrh r0, [r1]\n\
	ldrb r3, [r1, 0xB]\n\
	ldrb r1, [r1, 0xC]\n\
	str r1, [sp]\n\
	ldr r1, [sp, 0x1C]\n\
	str r1, [sp, 0x4]\n\
	ldr r1, [sp, 0x14]\n\
	mov r2, r8\n\
	bl sub_818F720\n\
	ldr r2, [sp, 0x1C]\n\
	ldr r1, [r2, 0x4]\n\
	ldrh r0, [r6]\n\
	adds r0, r1\n\
	ldr r1, [r2, 0x8]\n\
	adds r0, r1\n\
	ldr r1, [r2, 0x10]\n\
	adds r0, r1\n\
	ldr r1, [r2, 0x14]\n\
	adds r0, r1\n\
	ldr r1, [r2, 0xC]\n\
	adds r0, r1\n\
	ldr r1, [r2]\n\
	adds r0, r1\n\
	strh r0, [r6]\n\
	ldr r3, =gSaveBlock2Ptr\n\
	ldr r0, [r3]\n\
	ldr r1, =0x00000d64\n\
	adds r0, r1\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	ldr r2, =gUnknown_0203BC8C\n\
	ldr r1, [r2]\n\
	lsls r0, 4\n\
	adds r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r1, r0, 3\n\
	subs r1, r0\n\
	lsls r1, 2\n\
	ldr r3, =gBaseStats\n\
	adds r1, r3\n\
	ldrb r0, [r1, 0x6]\n\
	lsls r0, 2\n\
	ldr r2, =gBitTable\n\
	adds r0, r2\n\
	ldr r0, [r0]\n\
	orrs r7, r0\n\
	ldrb r0, [r1, 0x7]\n\
	lsls r0, 2\n\
	adds r0, r2\n\
	ldr r0, [r0]\n\
	orrs r7, r0\n\
	adds r5, 0x1\n\
	cmp r5, 0x2\n\
	ble _0818F4BC\n\
	movs r4, 0\n\
	movs r1, 0x1\n\
	movs r5, 0x1F\n\
_0818F54C:\n\
	adds r0, r7, 0\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _0818F556\n\
	adds r4, 0x1\n\
_0818F556:\n\
	asrs r7, 1\n\
	subs r5, 0x1\n\
	cmp r5, 0\n\
	bge _0818F54C\n\
	ldr r3, [sp, 0x14]\n\
	adds r0, r4, 0\n\
	muls r0, r3\n\
	movs r1, 0x14\n\
	bl __divsi3\n\
	ldrh r1, [r6]\n\
	adds r1, r0\n\
	strh r1, [r6]\n\
	adds r6, 0x2\n\
	ldr r5, [sp, 0x30]\n\
	adds r5, 0x2\n\
	str r5, [sp, 0x30]\n\
	movs r7, 0x1\n\
	add r10, r7\n\
	mov r0, r10\n\
	cmp r0, 0xF\n\
	ble _0818F494\n\
	movs r1, 0\n\
	mov r10, r1\n\
	ldr r2, =0x000003ff\n\
	mov r8, r2\n\
_0818F58A:\n\
	mov r5, r10\n\
	adds r5, 0x1\n\
	adds r7, r5, 0\n\
	cmp r5, 0xF\n\
	bgt _0818F626\n\
	mov r3, r10\n\
	lsls r0, r3, 1\n\
	ldr r1, [sp, 0x18]\n\
	adds r6, r0, r1\n\
	lsls r0, r5, 1\n\
	adds r4, r0, r1\n\
_0818F5A0:\n\
	ldrh r1, [r6]\n\
	ldrh r0, [r4]\n\
	cmp r1, r0\n\
	bcc _0818F5C2\n\
	cmp r1, r0\n\
	bne _0818F61E\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r1, [r0]\n\
	lsls r0, r5, 2\n\
	adds r0, r1, r0\n\
	ldr r2, =0x00000d24\n\
	adds r0, r2\n\
	ldrh r0, [r0]\n\
	lsls r2, r0, 22\n\
	lsrs r0, r2, 22\n\
	cmp r0, r8\n\
	bne _0818F602\n\
_0818F5C2:\n\
	mov r0, r10\n\
	adds r1, r5, 0\n\
	ldr r2, [sp, 0x18]\n\
	bl sub_818F904\n\
	b _0818F600\n\
	.pool\n\
_0818F600:\n\
	b _0818F61E\n\
_0818F602:\n\
	mov r3, r10\n\
	lsls r0, r3, 2\n\
	adds r0, r1, r0\n\
	ldr r1, =0x00000d24\n\
	adds r0, r1\n\
	ldrh r0, [r0]\n\
	lsls r0, 22\n\
	cmp r0, r2\n\
	bls _0818F61E\n\
	mov r0, r10\n\
	adds r1, r5, 0\n\
	ldr r2, [sp, 0x18]\n\
	bl sub_818F904\n\
_0818F61E:\n\
	adds r4, 0x2\n\
	adds r5, 0x1\n\
	cmp r5, 0xF\n\
	ble _0818F5A0\n\
_0818F626:\n\
	mov r10, r7\n\
	mov r2, r10\n\
	cmp r2, 0xE\n\
	ble _0818F58A\n\
	bl sub_81A3610\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _0818F6EE\n\
	movs r3, 0\n\
	mov r10, r3\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r1, [r0]\n\
	ldr r4, =0x00000d24\n\
	adds r1, r4\n\
	ldrh r1, [r1]\n\
	lsls r1, 22\n\
	lsrs r1, 22\n\
	ldr r3, =0x000003ff\n\
	adds r2, r0, 0\n\
	ldr r6, =gUnknown_0860D3F1\n\
	cmp r1, r3\n\
	beq _0818F674\n\
	adds r5, r2, 0\n\
_0818F656:\n\
	movs r7, 0x1\n\
	add r10, r7\n\
	mov r0, r10\n\
	cmp r0, 0xF\n\
	bgt _0818F674\n\
	ldr r0, [r5]\n\
	mov r7, r10\n\
	lsls r1, r7, 2\n\
	adds r0, r1\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	lsls r0, 22\n\
	lsrs r0, 22\n\
	cmp r0, r3\n\
	bne _0818F656\n\
_0818F674:\n\
	mov r1, r10\n\
	lsls r0, r1, 1\n\
	adds r0, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, 0\n\
	beq _0818F6AC\n\
	movs r5, 0\n\
	ldr r2, [r2]\n\
	ldr r3, =0x00000d24\n\
	adds r2, r3\n\
	ldrh r1, [r2]\n\
	ldr r0, =0xfffffc00\n\
	ands r0, r1\n\
	ldr r7, =0x000003fe\n\
	adds r1, r7, 0\n\
	b _0818F6BE\n\
	.pool\n\
_0818F6AC:\n\
	movs r5, 0x1\n\
	ldr r2, [r2]\n\
	ldr r0, =0x00000d28\n\
	adds r2, r0\n\
	ldrh r1, [r2]\n\
	ldr r0, =0xfffffc00\n\
	ands r0, r1\n\
	ldr r3, =0x000003fe\n\
	adds r1, r3, 0\n\
_0818F6BE:\n\
	orrs r0, r1\n\
	strh r0, [r2]\n\
	movs r7, 0\n\
	mov r10, r7\n\
	lsls r0, r5, 1\n\
	adds r0, r5\n\
	lsls r4, r0, 1\n\
_0818F6CC:\n\
	mov r1, r10\n\
	lsls r0, r1, 24\n\
	lsrs r0, 24\n\
	bl sub_81A4FF0\n\
	ldr r1, =gSaveBlock2Ptr\n\
	ldr r1, [r1]\n\
	ldr r2, =0x00000d64\n\
	adds r1, r2\n\
	adds r1, r4\n\
	strh r0, [r1]\n\
	adds r4, 0x2\n\
	movs r3, 0x1\n\
	add r10, r3\n\
	mov r5, r10\n\
	cmp r5, 0x2\n\
	ble _0818F6CC\n\
_0818F6EE:\n\
	ldr r0, [sp, 0x18]\n\
	bl Free\n\
	ldr r0, [sp, 0x1C]\n\
	bl Free\n\
	add sp, 0x3C\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
\n\
        ");
}
#endif // NONMATCHING

#define CALC_STAT(base, statIndex)                                                          \
{                                                                                           \
    u8 baseStat = gBaseStats[species].base;                                                 \
    stats[statIndex] = (((2 * baseStat + ivs + evs[statIndex] / 4) * level) / 100) + 5;     \
    stats[statIndex] = (u8) ModifyStatByNature(nature, stats[statIndex], statIndex);        \
}

void sub_818F720(u16 species, s32 level, s32 ivs, u8 evBits, u8 nature, s32 *stats)
{
    s32 i, count;
    u8 bits;
    u16 resultingEvs;
    s32 evs[6];

    count = 0, bits = evBits;
    for (i = 0; i < 6; bits >>= 1, i++)
    {
        if (bits & 1)
            count++;
    }

    resultingEvs = 510 / count;
    for (i = 0; i < 6; bits <<= 1, i++)
    {
        evs[i] = 0;
        if (evBits & bits)
            evs[i] = resultingEvs;
    }

    if (species == SPECIES_SHEDINJA)
    {
        stats[STAT_HP] = 1;
    }
    else
    {
        s32 n = 2 * gBaseStats[species].baseHP;
        stats[STAT_HP] = (((n + ivs + evs[STAT_HP] / 4) * level) / 100) + level + 10;
    }

    CALC_STAT(baseAttack, STAT_ATK);
    CALC_STAT(baseDefense, STAT_DEF);
    CALC_STAT(baseSpeed, STAT_SPEED);
    CALC_STAT(baseSpAttack, STAT_SPATK);
    CALC_STAT(baseSpDefense, STAT_SPDEF);
}

#define SWAP_16(x, y)   \
{                       \
    temp = x;           \
    x = y;              \
    y = temp;           \
}

void sub_818F904(s32 id1, s32 id2, u16 *dst)
{
    s32 i;
    u16 temp;

    SWAP_16(dst[id1], dst[id2]);
    SWAP_16(gSaveBlock2Ptr->frontier.field_D24[id1].unk0, gSaveBlock2Ptr->frontier.field_D24[id2].unk0);

    for (i = 0; i < 3; i++)
        SWAP_16(gSaveBlock2Ptr->frontier.field_D64[id1][i], gSaveBlock2Ptr->frontier.field_D64[id2][i]);
}
