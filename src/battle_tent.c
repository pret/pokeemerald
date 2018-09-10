#include "global.h"
#include "battle_tent.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "random.h"
#include "item.h"
#include "battle_factory.h"
#include "battle_frontier_2.h"
#include "constants/items.h"
#include "constants/region_map_sections.h"

extern const struct BattleFrontierTrainer gSlateportBattleTentTrainers[];
extern const struct FacilityMon gSlateportBattleTentMons[];
extern const u16 gBattleFrontierHeldItems[];

extern u16 gUnknown_03006298[];

// This file's functions.
static void sub_81B99D4(void);
static void sub_81B9A28(void);
static void sub_81B9A44(void);
static void sub_81B9A60(void);
static void sub_81B9A90(void);
static void sub_81B9ABC(void);
static void sub_81B9B00(void);
static void sub_81B9B28(void);
static void sub_81B9BA0(void);
static void sub_81B9BF4(void);
static void sub_81B9C10(void);
static void sub_81B9C2C(void);
static void sub_81B9C70(void);
static void sub_81B9C98(void);
static void sub_81B9CF0(void);
static void sub_81B9D28(void);
static void sub_81B9D7C(void);
static void sub_81B9D98(void);
static void sub_81B9DB4(void);
static void sub_81B9DF8(void);
static void sub_81B9E20(void);
static void sub_81B9E78(void);
static void sub_81B9E88(void);
static void sub_81BA040(void);
static void sub_81B9EC0(void);

// IWRAM bss
static IWRAM_DATA u16 sRandMonSetId;

// const rom data
void static (*const gUnknown_086160B4[])(void) =
{
    sub_81B99D4,
    sub_81B9A28,
    sub_81B9A44,
    sub_81B9A60,
    sub_81B9A90,
    sub_81B9ABC,
    sub_81B9B00,
    sub_81B9B28
};

static const u16 sVerdanturfTentRewards[] = {ITEM_NEST_BALL};

void static (*const gUnknown_086160D8[])(void) =
{
    sub_81B9BA0,
    sub_81B9BF4,
    sub_81B9C10,
    sub_81B9C2C,
    sub_81B9C70,
    sub_81B9C98,
    sub_81B9CF0
};

static const u16 sFallarborTentRewards[] = {ITEM_HYPER_POTION};

void static (*const gUnknown_086160F8[])(void) =
{
    sub_81B9D28,
    sub_81B9D7C,
    sub_81B9D98,
    sub_81B9DB4,
    sub_81B9DF8,
    sub_81B9E20,
    sub_81B9E78,
    sub_81B9E88,
    sub_81BA040,
    sub_81B9EC0
};

static const u16 sSlateportTentRewards[] = {ITEM_FULL_HEAL};

// code
void sub_81B99B4(void)
{
    gUnknown_086160B4[gSpecialVar_0x8004]();
}

static void sub_81B99D4(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void sub_81B9A28(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6A;
}

static void sub_81B9A44(void)
{
    gSaveBlock2Ptr->frontier.field_E6A = gSpecialVar_0x8006;
}

static void sub_81B9A60(void)
{
    gTrainerBattleOpponent_A = (u32)((Random() % 255) * 5) / 64;
    sub_8162614(gTrainerBattleOpponent_A, 0);
}

static void sub_81B9A90(void)
{
    if (gTrainerBattleOpponent_A < 300)
        ConvertBattleFrontierTrainerSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

static void sub_81B9ABC(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

static void sub_81B9B00(void)
{
    gSaveBlock2Ptr->frontier.field_E6A = sVerdanturfTentRewards[Random() % ARRAY_COUNT(sVerdanturfTentRewards)];
}

static void sub_81B9B28(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E6A, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E6A, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E6A = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void sub_81B9B80(void)
{
    gUnknown_086160D8[gSpecialVar_0x8004]();
}

static void sub_81B9BA0(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void sub_81B9BF4(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6C;
}

static void sub_81B9C10(void)
{
    gSaveBlock2Ptr->frontier.field_E6C = gSpecialVar_0x8006;
}

static void sub_81B9C2C(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

static void sub_81B9C70(void)
{
    gSaveBlock2Ptr->frontier.field_E6C = sFallarborTentRewards[Random() % ARRAY_COUNT(sFallarborTentRewards)];
}

static void sub_81B9C98(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E6C, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E6C, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E6C = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void sub_81B9CF0(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void sub_81B9D08(void)
{
    gUnknown_086160F8[gSpecialVar_0x8004]();
}

static void sub_81B9D28(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.field_CB2 = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = FALSE;
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

static void sub_81B9D7C(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_E6E;
}

static void sub_81B9D98(void)
{
    gSaveBlock2Ptr->frontier.field_E6E = gSpecialVar_0x8006;
}

static void sub_81B9DB4(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = TRUE;
    sub_81A4C30();
}

static void sub_81B9DF8(void)
{
    gSaveBlock2Ptr->frontier.field_E6E = sSlateportTentRewards[Random() % ARRAY_COUNT(sSlateportTentRewards)];
}

static void sub_81B9E20(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.field_E6E, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.field_E6E, gStringVar1);
        gSaveBlock2Ptr->frontier.field_E6E = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void sub_81B9E78(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void sub_81B9E88(void)
{
    DoBattleFactorySwapScreen();
}

bool8 sub_81B9E94(void)
{
    return (gMapHeader.regionMapSectionId == MAPSEC_SLATEPORT_CITY
            && ((gMapHeader.mapLayoutId == 385) | (gMapHeader.mapLayoutId == 386)));
}

// This function was written very...oddly.
#ifdef NONMATCHING
static void sub_81B9EC0(void)
{
    s32 i, j;
    u16 currMonId = 0, currSpecies = 0;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];
    s32 zero = 0;

    gFacilityTrainers = gSlateportBattleTentTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    gFacilityTrainerMons = gSlateportBattleTentMons;
    currSpecies = 0;
    for (i = 0; i != PARTY_SIZE;)
    {
        // Cannot have two pokemon of the same species.
        currMonId = Random() % 70;
        for (j = zero; j < i + zero; j++)
        {
            if (monIds[j] == currMonId)
                break;
            if (species[j] == gFacilityTrainerMons[currMonId].species)
            {
                if (currSpecies == 0)
                    currSpecies = gFacilityTrainerMons[currMonId].species;
                else
                    break;
            }
        }
        if (j != i + zero)
            continue;

        // Cannot have two same held items.
        for (j = zero; j < i + zero; j++)
        {
            if (heldItems[j] == 0)
                continue;
            if (heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[currMonId].itemTableId])
            {
                if (gFacilityTrainerMons[currMonId].species == currSpecies)
                    currSpecies = 0;
                else
                    break;
            }
        }
        if (j != i + zero)
            continue;

        gSaveBlock2Ptr->frontier.field_E70[i].monId = currMonId;
        species[i] = gFacilityTrainerMons[currMonId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[currMonId].itemTableId];
        monIds[i] = currMonId;
        i++;
    }
}
#else
NAKED
static void sub_81B9EC0(void)
{
    asm_unified("\n\
    	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x3C\n\
	ldr r1, =gFacilityTrainers\n\
	ldr r0, =gSlateportBattleTentTrainers\n\
	str r0, [r1]\n\
	add r0, sp, 0xC\n\
	mov r9, r0\n\
	mov r1, sp\n\
	adds r1, 0x18\n\
	str r1, [sp, 0x2C]\n\
	ldr r5, =gFacilityTrainerMons\n\
	ldr r4, =gSlateportBattleTentMons\n\
	movs r2, 0\n\
	adds r3, r1, 0\n\
	mov r1, r9\n\
	mov r0, sp\n\
	movs r6, 0x5\n\
	mov r8, r6\n\
_081B9EEC:\n\
	strh r2, [r0]\n\
	strh r2, [r1]\n\
	strh r2, [r3]\n\
	adds r3, 0x2\n\
	adds r1, 0x2\n\
	adds r0, 0x2\n\
	movs r7, 0x1\n\
	negs r7, r7\n\
	add r8, r7\n\
	mov r6, r8\n\
	cmp r6, 0\n\
	bge _081B9EEC\n\
	str r4, [r5]\n\
	movs r7, 0\n\
	mov r10, r7\n\
	movs r0, 0\n\
	mov r8, r0\n\
	ldr r1, [sp, 0x2C]\n\
	str r1, [sp, 0x30]\n\
	mov r2, sp\n\
	str r2, [sp, 0x34]\n\
	lsls r6, r0, 1\n\
	str r6, [sp, 0x24]\n\
	add r6, r9\n\
	str r6, [sp, 0x28]\n\
_081B9F1E:\n\
	bl Random\n\
	lsls r0, 16\n\
	lsrs r0, 16\n\
	movs r1, 0x46\n\
	bl __umodsi3\n\
	lsls r0, 16\n\
	lsrs r5, r0, 16\n\
	movs r2, 0\n\
	mov r7, r8\n\
	adds r6, r2, r7\n\
	cmp r2, r6\n\
	bge _081B9F7C\n\
	ldr r1, [sp, 0x28]\n\
	ldrh r0, [r1]\n\
	cmp r0, r5\n\
	beq _081B9F7C\n\
	ldr r0, =gFacilityTrainerMons\n\
	ldr r1, [r0]\n\
	lsls r0, r5, 4\n\
	adds r4, r0, r1\n\
	ldrh r7, [r4]\n\
	mov r12, r7\n\
	lsls r3, r2, 1\n\
	ldr r1, [sp, 0x24]\n\
	add r1, sp\n\
	str r6, [sp, 0x38]\n\
_081B9F56:\n\
	ldrh r0, [r1]\n\
	cmp r0, r12\n\
	bne _081B9F66\n\
	mov r0, r10\n\
	cmp r0, 0\n\
	bne _081B9F7C\n\
	ldrh r7, [r4]\n\
	mov r10, r7\n\
_081B9F66:\n\
	adds r3, 0x2\n\
	adds r1, 0x2\n\
	adds r2, 0x1\n\
	ldr r0, [sp, 0x38]\n\
	cmp r2, r0\n\
	bge _081B9F7C\n\
	mov r7, r9\n\
	adds r0, r7, r3\n\
	ldrh r0, [r0]\n\
	cmp r0, r5\n\
	bne _081B9F56\n\
_081B9F7C:\n\
	cmp r2, r6\n\
	bne _081BA01C\n\
	movs r2, 0\n\
	cmp r2, r6\n\
	bge _081B9FD4\n\
	ldr r0, =gBattleFrontierHeldItems\n\
	mov r12, r0\n\
	ldr r7, =gFacilityTrainerMons\n\
	ldr r1, [sp, 0x24]\n\
	ldr r0, [sp, 0x2C]\n\
	adds r4, r1, r0\n\
_081B9F92:\n\
	ldrh r3, [r4]\n\
	cmp r3, 0\n\
	beq _081B9FCC\n\
	ldr r1, [r7]\n\
	lsls r0, r5, 4\n\
	adds r1, r0, r1\n\
	ldrb r0, [r1, 0xA]\n\
	lsls r0, 1\n\
	add r0, r12\n\
	ldrh r0, [r0]\n\
	cmp r3, r0\n\
	bne _081B9FCC\n\
	ldrh r0, [r1]\n\
	cmp r0, r10\n\
	bne _081B9FD4\n\
	movs r1, 0\n\
	mov r10, r1\n\
	b _081B9FD4\n\
	.pool\n\
_081B9FCC:\n\
	adds r4, 0x2\n\
	adds r2, 0x1\n\
	cmp r2, r6\n\
	blt _081B9F92\n\
_081B9FD4:\n\
	cmp r2, r6\n\
	bne _081BA01C\n\
	ldr r0, =gSaveBlock2Ptr\n\
	ldr r1, [r0]\n\
	mov r2, r8\n\
	lsls r3, r2, 1\n\
	adds r0, r3, r2\n\
	lsls r0, 2\n\
	adds r1, r0\n\
	movs r6, 0xE7\n\
	lsls r6, 4\n\
	adds r1, r6\n\
	strh r5, [r1]\n\
	ldr r0, =gFacilityTrainerMons\n\
	ldr r0, [r0]\n\
	lsls r1, r5, 4\n\
	adds r1, r0\n\
	ldrh r0, [r1]\n\
	ldr r7, [sp, 0x34]\n\
	strh r0, [r7]\n\
	ldr r2, =gBattleFrontierHeldItems\n\
	ldrb r0, [r1, 0xA]\n\
	lsls r0, 1\n\
	adds r0, r2\n\
	ldrh r0, [r0]\n\
	ldr r1, [sp, 0x30]\n\
	strh r0, [r1]\n\
	add r3, r9\n\
	strh r5, [r3]\n\
	adds r1, 0x2\n\
	str r1, [sp, 0x30]\n\
	adds r2, r7, 0\n\
	adds r2, 0x2\n\
	str r2, [sp, 0x34]\n\
	movs r6, 0x1\n\
	add r8, r6\n\
_081BA01C:\n\
	mov r7, r8\n\
	cmp r7, 0x6\n\
	beq _081BA024\n\
	b _081B9F1E\n\
_081BA024:\n\
	add sp, 0x3C\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    ");
}
#endif // NONMATCHING

static void sub_81BA040(void)
{
    u16 trainerId;
    s32 i, j, k;
    register const u16 *monSetsPool asm("r9"); // Fix me. Compiler insists on moving that variable into stack.
    u16 species[3];
    u16 heldItems[3];
    s32 monPoolCount = 0;

    gFacilityTrainers = gSlateportBattleTentTrainers;
    gFacilityTrainerMons = gSlateportBattleTentMons;

    while (1)
    {
        do
        {
            trainerId = Random() % 30;
            for (i = 0; i < gSaveBlock2Ptr->frontier.field_CB2; i++)
            {
                if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                    break;
            }
        } while (i != gSaveBlock2Ptr->frontier.field_CB2);

        gTrainerBattleOpponent_A = trainerId;
        while (gFacilityTrainers[gTrainerBattleOpponent_A].btMonPool[monPoolCount] != 0xFFFF)
            monPoolCount++;
        if (monPoolCount > 8)
            break;
        monPoolCount = 0;
    }

    if (gSaveBlock2Ptr->frontier.field_CB2 < 2)
        gSaveBlock2Ptr->frontier.field_CB4[gSaveBlock2Ptr->frontier.field_CB2] = gTrainerBattleOpponent_A;

    monSetsPool = gFacilityTrainers[gTrainerBattleOpponent_A].btMonPool;
    i = 0;
    while (i != 3)
    {
        sRandMonSetId = monSetsPool[Random() % monPoolCount];
        for (j = 0; j < 6; j++)
        {
            if (gFacilityTrainerMons[sRandMonSetId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.field_E70[j].monId].species)
                break;
        }
        if (j != 6)
            continue;

        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[sRandMonSetId].species)
                break;
        }
        if (k != i)
            continue;

        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != 0 && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonSetId].itemTableId])
                break;
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[sRandMonSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonSetId].itemTableId];
        gUnknown_03006298[i] = sRandMonSetId;
        i++;
    }
}
