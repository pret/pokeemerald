#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "species.h"
#include "abilities.h"

#define AIScriptRead32(ptr) ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24)
#define AIScriptRead16(ptr) ((ptr)[0] | (ptr)[1] << 8)
#define AIScriptRead8(ptr) ((ptr)[0])
#define AIScriptReadPtr(ptr) (u8*) AIScriptRead32(ptr)

#define AI_THINKING_STRUCT ((struct AI_ThinkingStruct *)(gBattleStruct->ai))
#define UNK_2016A00_STRUCT ((struct UnknownStruct2 *)(gBattleStruct->unk18))
#define UNK_2016C00_STRUCT ((struct UnknownStruct4 *)(gBattleStruct->unk1C))
#define UNK_BATTLE_STRUCT ((struct BattleStruct *)(gBattleStruct))

#define AI_ACTION_UNK1          0x0001
#define AI_ACTION_UNK2          0x0002
#define AI_ACTION_UNK3          0x0004
#define AI_ACTION_UNK4          0x0008
#define AI_ACTION_UNK5          0x0010
#define AI_ACTION_UNK6          0x0020
#define AI_ACTION_UNK7          0x0040
#define AI_ACTION_UNK8          0x0080

enum
{
    TARGET,
    USER
};

// AI states
enum
{
    AIState_SettingUp,
    AIState_Processing,
    AIState_FinishedProcessing,
    AIState_DoNotProcess
};

//Copied from pokeruby -- hopefully the same
struct Trainer
{
    /*0x00*/ u8 partyFlags;
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u8 encounterMusic:7;
    /*0x02*/ u8 gender:1;
    /*0x03*/ u8 trainerPic;
    /*0x04*/ u8 trainerName[12];
    /*0x10*/ u16 items[4];
    /*0x18*/ bool8 doubleBattle;
    /*0x1C*/ u32 aiFlags;
    /*0x20*/ u8 partySize;
    /*0x24*/ void *party;
};

//size should be 0x1C
struct AI_ThinkingStruct
{
    u8 aiState;
    u8 movesetIndex;
    u16 moveConsidered;
    s8 score[4];
    u32 funcResult;
    u32 aiFlags;
    u8 aiAction;
    u8 aiLogicId;
    u8 filler12[6];
    u8 unk18[4];
};

//size should be 0x54
struct UnknownStruct2
{
    u16 unk0[2][8];
    u8 unk20[2];
    u8 filler20[0x1E];
    u8 unk40[4];
    u8 unk44[4];
    u16 unk48[4];
    u8 unk50;
};

struct UnknownStruct4
{
    u8 *ptr[8];
    u8 unk20;
};

struct SimpleUnknownStruct
{
    u32 unkArray[4]; // unknown size
};

/*
struct UnknownStruct5
{
    u8 filler0[0x3];
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 fillerA[0x9];
    u8 taunt:4;
    u8 unkC:4;
    u8 fillerD[0x2];
    u8 unk16;
    u8 filler17[0x4];
};

extern struct UnknownStruct5 gDisableStructs[];
*/

/*
gAIScriptPtr is a pointer to the next battle AI cmd command to read.
when a command finishes processing, gAIScriptPtr is incremented by
the number of bytes that the current command had reserved for arguments
in order to read the next command correctly. refer to battle_ai_scripts.s for the
AI scripts.
*/
extern u8 *gAIScriptPtr;

extern u32 gBattleTypeFlags;
extern u8 gActiveBank;
extern struct BattlePokemon gBattleMons[];
extern u16 gCurrentMove;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u16 gLastUsedMove[];
extern u8 *gUnknown_0202449C;
extern u16 gUnknown_02038BCA;
extern u16 gUnknown_02038BCC;
extern u8 gPlayerMonIndex;
extern struct Trainer gTrainers[];
extern const u32 gBitTable[];
extern u8 *gUnknown_082DBEF8[];
extern u32 gStatuses3[];
extern u16 gSideAffecting[];
extern struct BattleMove gBattleMoves[];
extern u8 gUnknown_03005D10[];
extern u8 gUnknown_0202406E[][2];
extern struct BaseStats gBaseStats[];
extern u16 gUnknown_02024400;
extern u8 gUnknown_02024474[];
extern u8 gBattleMoveFlags;
extern int gBattleMoveDamage;
extern u8 gCritMultiplier;
extern u16 gBattleWeather;

extern u8 battle_get_per_side_status(u8);
extern u8 b_first_side(u8, u8, u8);
extern u8 battle_get_side_with_given_state(u8);
extern void move_effectiveness_something(u16, u8, u8);
extern u8 ItemId_GetHoldEffect();
extern void b_mc_stack_push(u8 *);
extern bool8 b_mc_stack_pop_cursor(void);
extern void sub_8046E7C(u8, u8);

typedef void (*BattleAICmdFunc)(void);

extern const BattleAICmdFunc sBattleAICmdTable[];

extern u8 CheckMoveLimitations();
extern u16 Random();
extern u8 GetBankSide();
extern u32 sub_8186438();
extern u32 sub_81A6FB4();

void BattleAI_SetupAIData(u8 a);
u8 BattleAI_GetAIActionToUse(void);
u8 sub_8130CF4(void);
void sub_8131074(void);
void BattleAI_DoAIProcessing(void);

void BattleAI_HandleItemUseBeforeAISetup(u8 a)
{
    s32 i;
    u8 *data = (u8 *)gBattleStruct->unk18;

    for (i = 0; (u32)i < 0x54; i++)
        data[i] = 0;
    if ((gBattleTypeFlags & 0x0A7F098A) == 8)
    {
        for (i = 0; i < 4; i++)
        {
            if (gTrainers[gUnknown_02038BCA].items[i] != 0)
            {
                gBattleStruct->unk18->unk48[gBattleStruct->unk18->unk50] = gTrainers[gUnknown_02038BCA].items[i];
                gBattleStruct->unk18->unk50++;
            }
        }
    }

    BattleAI_SetupAIData(a);
}

void BattleAI_SetupAIData(u8 a)
{
    s32 i;
    u8 *data = (u8 *)AI_THINKING_STRUCT;
    u8 r6;

    // clear AI data.
    for (i = 0; (u32)i < sizeof(struct AI_ThinkingStruct); i++)
        data[i] = 0;

    // conditional score reset, unlike Ruby.
    for (i = 0; i < 4; i++)
    {
        if (a & 1)
            AI_THINKING_STRUCT->score[i] = 100;
        else
            AI_THINKING_STRUCT->score[i] = 0;
        a >>= 1;
    }

    r6 = CheckMoveLimitations(gActiveBank, 0, 0xFF);

    for (i = 0; i < 4; i++)
    {
        if (gBitTable[i] & r6)
            AI_THINKING_STRUCT->score[i] = 0;

        AI_THINKING_STRUCT->unk18[i] = 100 - (Random() % 16);
    }
    gBattleStruct->unk1C->unk20 = 0;
    gPlayerMonIndex = gActiveBank;
    if (gBattleTypeFlags & 1)
    {
        gBankTarget = (Random() & 2) + ((u32)GetBankSide(gActiveBank) ^ 1);
        if (gAbsentBankFlags & gBitTable[gBankTarget])
            gBankTarget ^= 2;
    }
    else
    {
        //_08130A60
        gBankTarget = gPlayerMonIndex ^ 1;
    }
    //_08130A68
    if (gBattleTypeFlags & 0x1000000)
        AI_THINKING_STRUCT->aiFlags = sub_8186438();
    else if (gBattleTypeFlags & 0x80)
        AI_THINKING_STRUCT->aiFlags = 0x40000000;
    else if (gBattleTypeFlags & 0x400)
        AI_THINKING_STRUCT->aiFlags = 0x20000000;
    else if (gBattleTypeFlags & 0x10)
        AI_THINKING_STRUCT->aiFlags = 0x80000000;
    else if (gBattleTypeFlags & 0x80000)
        AI_THINKING_STRUCT->aiFlags = sub_81A6FB4();
    else if (gBattleTypeFlags & 0x0C3F0900)
        AI_THINKING_STRUCT->aiFlags = 7;
    else if (gBattleTypeFlags & 0x8000)
        AI_THINKING_STRUCT->aiFlags = gTrainers[gUnknown_02038BCA].aiFlags | gTrainers[gUnknown_02038BCC].aiFlags;
    else
       AI_THINKING_STRUCT->aiFlags = gTrainers[gUnknown_02038BCA].aiFlags;
    if (gBattleTypeFlags & 1)
        AI_THINKING_STRUCT->aiFlags |= 0x80;
}

u8 sub_8130BA4(void)
{
    u16 r4 = gCurrentMove;
    u8 ret;

    if (!(gBattleTypeFlags & 1))
        ret = BattleAI_GetAIActionToUse();
    else
        ret = sub_8130CF4();

    gCurrentMove = r4;
    return ret;
}

u8 BattleAI_GetAIActionToUse(void)
{
    u8 currentMoveArray[4];
    u8 consideredMoveArray[4];
    u8 numOfBestMoves;
    s32 i;

    sub_8131074();

    while (AI_THINKING_STRUCT->aiFlags != 0)
    {
        if (AI_THINKING_STRUCT->aiFlags & 1)
        {
            AI_THINKING_STRUCT->aiState = AIState_SettingUp;
            BattleAI_DoAIProcessing();
        }
        AI_THINKING_STRUCT->aiFlags >>= 1;
        AI_THINKING_STRUCT->aiLogicId++;
        AI_THINKING_STRUCT->movesetIndex = 0;
    }

    // special flags for safari watch/flee.
    if (AI_THINKING_STRUCT->aiAction & 2)
        return 4;
    if (AI_THINKING_STRUCT->aiAction & 4)
        return 5;

    numOfBestMoves = 1;
    currentMoveArray[0] = AI_THINKING_STRUCT->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < 4; i++)
    {
        if (gBattleMons[gPlayerMonIndex].moves[i] != 0) // emerald adds an extra move ID check for some reason.
        {
            // in ruby, the order of these if statements are reversed.
            if (currentMoveArray[0] == AI_THINKING_STRUCT->score[i])
            {
                currentMoveArray[numOfBestMoves] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[numOfBestMoves++] = i;
            }
            if (currentMoveArray[0] < AI_THINKING_STRUCT->score[i])
            {
                numOfBestMoves = 1;
                currentMoveArray[0] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[0] = i;
            }
        }
    }
    return consideredMoveArray[Random() % numOfBestMoves];
}

#ifdef NONMATCHING
u8 sub_8130CF4(void)
{
    s32 i;
    s32 j;
    //s32 r4_2;
    #define r4_2 r4
    s32 r5;
    s16 r5_2;
    s32 r4;
    s16 sp0[4];
    s8 sp8[4];
    s8 spC[4];
    u8 sp10[4]; // definitely unsigned
    u8 sp14[4];
    //u8 *sp1C = spC;
    //u8 *sp18 = sp8;
    //u8 *sp20 = spC;

    for (i = 0; i < 4; i++) //_08130D14
    {
        if (i == gPlayerMonIndex || gBattleMons[i].hp == 0)
        {
            //_08130D2E
            spC[i] = -1;
            sp0[i] = -1;
        }
        //_08130D48
        else
        {
            if (gBattleTypeFlags & 0x20000)
                BattleAI_SetupAIData(gUnknown_0202449C[0x92] >> 4);
            else
                BattleAI_SetupAIData(0xF);
            //_08130D76
            gBankTarget = i;
            if ((i & 1) != (gPlayerMonIndex & 1))
                sub_8131074();
            //_08130D90
            AI_THINKING_STRUCT->unk11 = 0;
            AI_THINKING_STRUCT->unk1 = 0;
            r4 = AI_THINKING_STRUCT->aiFlags;
            while (r4 != 0)
            {
                if (r4 & 1)
                {
                    AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    BattleAI_DoAIProcessing();
                }
                r4 >>= 1;
                AI_THINKING_STRUCT->unk11++;
                AI_THINKING_STRUCT->unk1 = 0;
            }
            //_08130DD8
            if (AI_THINKING_STRUCT->unk10 & 2)
                spC[i] = 4;
            else if (AI_THINKING_STRUCT->unk10 & 4)
                spC[i] = 5;
            else
            {
                //_08130E10
                sp10[0] = AI_THINKING_STRUCT->score[0];
                sp14[0] = 0;
                r5 = 1;
                for (j = 1; j < 4; j++)
                {
                    if (gBattleMons[gPlayerMonIndex].moves[j] != 0)
                    {
                        if (sp10[0] == AI_THINKING_STRUCT->score[j])
                        {
                            sp10[r5] = AI_THINKING_STRUCT->score[j];
                            sp14[r5] = j;
                            r5++;
                        }
                        if (sp10[0] < AI_THINKING_STRUCT->score[j])
                        {
                            sp10[0] = AI_THINKING_STRUCT->score[j];
                            sp14[0] = j;
                            r5 = 1;
                        }
                    }
                    //_08130E72
                }
                spC[i] = sp14[Random() % r5];
                //asm("":::"r3");
                sp0[i] = sp10[0];
                if (i == (gPlayerMonIndex ^ 2) && sp0[i] < 100)
                    sp0[i] = -1;
            }
        }
        //_08130EAE
    }

    //#define i r5

    //_08130EC4
    r5_2 = sp0[0];
    sp8[0] = 0;
    r4_2 = 1;
    for (i = 1; i < 4; i++)
    {
        //_08130EDA
        if (r5_2 == sp0[i])
        {
            sp8[r4_2] = i;
            r4_2++;
        }
        //_08130EEE
        if (r5_2 < sp0[i])
        {
            r5_2 = sp0[i];
            sp8[0] = i;
            r4_2 = 1;
        }
    }
    gBankTarget = sp8[Random() % r4_2];
    return spC[gBankTarget];
}
#else
__attribute__((naked))
u8 sub_8130CF4(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x24\n\
    movs r0, 0\n\
    mov r8, r0\n\
    mov r1, sp\n\
    adds r1, 0xC\n\
    str r1, [sp, 0x1C]\n\
    mov r2, sp\n\
    adds r2, 0x8\n\
    str r2, [sp, 0x18]\n\
    str r1, [sp, 0x20]\n\
    mov r10, sp\n\
_08130D14:\n\
    ldr r0, =gPlayerMonIndex\n\
    ldrb r0, [r0]\n\
    cmp r8, r0\n\
    beq _08130D2E\n\
    movs r0, 0x58\n\
    mov r7, r8\n\
    muls r7, r0\n\
    adds r0, r7, 0\n\
    ldr r1, =gBattleMons\n\
    adds r0, r1\n\
    ldrh r0, [r0, 0x28]\n\
    cmp r0, 0\n\
    bne _08130D48\n\
_08130D2E:\n\
    movs r0, 0xFF\n\
    ldr r2, [sp, 0x20]\n\
    strb r0, [r2]\n\
    ldr r0, =0x0000ffff\n\
    mov r7, r10\n\
    strh r0, [r7]\n\
    b _08130EAE\n\
    .pool\n\
_08130D48:\n\
    ldr r0, =gBattleTypeFlags\n\
    ldr r0, [r0]\n\
    movs r1, 0x80\n\
    lsls r1, 10\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08130D70\n\
    ldr r0, =gUnknown_0202449C\n\
    ldr r0, [r0]\n\
    adds r0, 0x92\n\
    ldrb r0, [r0]\n\
    lsrs r0, 4\n\
    bl BattleAI_SetupAIData\n\
    b _08130D76\n\
    .pool\n\
_08130D70:\n\
    movs r0, 0xF\n\
    bl BattleAI_SetupAIData\n\
_08130D76:\n\
    ldr r0, =gBankTarget\n\
    mov r1, r8\n\
    strb r1, [r0]\n\
    movs r1, 0x1\n\
    mov r2, r8\n\
    ands r2, r1\n\
    ldr r0, =gPlayerMonIndex\n\
    ldrb r0, [r0]\n\
    ands r1, r0\n\
    cmp r2, r1\n\
    beq _08130D90\n\
    bl sub_8131074\n\
_08130D90:\n\
    ldr r2, =gBattleStruct\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    movs r1, 0\n\
    strb r1, [r0, 0x11]\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    strb r1, [r0, 0x1]\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldr r4, [r0, 0xC]\n\
    mov r9, r2\n\
    cmp r4, 0\n\
    beq _08130DD8\n\
    mov r5, r9\n\
    movs r6, 0\n\
_08130DB0:\n\
    movs r0, 0x1\n\
    ands r0, r4\n\
    cmp r0, 0\n\
    beq _08130DC2\n\
    ldr r0, [r5]\n\
    ldr r0, [r0, 0x14]\n\
    strb r6, [r0]\n\
    bl BattleAI_DoAIProcessing\n\
_08130DC2:\n\
    asrs r4, 1\n\
    ldr r0, [r5]\n\
    ldr r1, [r0, 0x14]\n\
    ldrb r0, [r1, 0x11]\n\
    adds r0, 0x1\n\
    strb r0, [r1, 0x11]\n\
    ldr r0, [r5]\n\
    ldr r0, [r0, 0x14]\n\
    strb r6, [r0, 0x1]\n\
    cmp r4, 0\n\
    bne _08130DB0\n\
_08130DD8:\n\
    mov r2, r9\n\
    ldr r0, [r2]\n\
    ldr r3, [r0, 0x14]\n\
    ldrb r1, [r3, 0x10]\n\
    movs r0, 0x2\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    beq _08130DFC\n\
    movs r0, 0x4\n\
    ldr r7, [sp, 0x20]\n\
    strb r0, [r7]\n\
    b _08130EAE\n\
    .pool\n\
_08130DFC:\n\
    movs r0, 0x4\n\
    ands r0, r1\n\
    lsls r0, 24\n\
    lsrs r2, r0, 24\n\
    cmp r2, 0\n\
    beq _08130E10\n\
    movs r0, 0x5\n\
    ldr r1, [sp, 0x20]\n\
    strb r0, [r1]\n\
    b _08130EAE\n\
_08130E10:\n\
    add r1, sp, 0x10\n\
    ldrb r0, [r3, 0x4]\n\
    strb r0, [r1]\n\
    add r0, sp, 0x14\n\
    strb r2, [r0]\n\
    movs r5, 0x1\n\
    movs r3, 0x1\n\
    adds r6, r1, 0\n\
    ldr r0, =gPlayerMonIndex\n\
    ldrb r1, [r0]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    ldr r2, =gBattleMons+0xC\n\
    adds r0, r2\n\
    adds r4, r0, 0x2\n\
    add r7, sp, 0x14\n\
_08130E30:\n\
    ldrh r0, [r4]\n\
    cmp r0, 0\n\
    beq _08130E72\n\
    ldrb r1, [r6]\n\
    mov r2, r9\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    adds r0, 0x4\n\
    adds r2, r0, r3\n\
    movs r0, 0\n\
    ldrsb r0, [r2, r0]\n\
    cmp r1, r0\n\
    bne _08130E56\n\
    adds r0, r6, r5\n\
    ldrb r1, [r2]\n\
    strb r1, [r0]\n\
    adds r0, r7, r5\n\
    strb r3, [r0]\n\
    adds r5, 0x1\n\
_08130E56:\n\
    ldrb r1, [r6]\n\
    mov r2, r9\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    adds r0, 0x4\n\
    adds r2, r0, r3\n\
    movs r0, 0\n\
    ldrsb r0, [r2, r0]\n\
    cmp r1, r0\n\
    bge _08130E72\n\
    ldrb r0, [r2]\n\
    strb r0, [r6]\n\
    strb r3, [r7]\n\
    movs r5, 0x1\n\
_08130E72:\n\
    adds r4, 0x2\n\
    adds r3, 0x1\n\
    cmp r3, 0x3\n\
    ble _08130E30\n\
    bl Random\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    adds r1, r5, 0\n\
    bl __modsi3\n\
    add r0, sp\n\
    adds r0, 0x14\n\
    ldrb r0, [r0]\n\
    ldr r7, [sp, 0x20]\n\
    strb r0, [r7]\n\
    ldrb r2, [r6]\n\
    mov r0, r10\n\
    strh r2, [r0]\n\
    ldr r0, =gPlayerMonIndex\n\
    ldrb r1, [r0]\n\
    movs r0, 0x2\n\
    eors r0, r1\n\
    cmp r8, r0\n\
    bne _08130EAE\n\
    cmp r2, 0x63\n\
    bgt _08130EAE\n\
    ldr r0, =0x0000ffff\n\
    mov r1, r10\n\
    strh r0, [r1]\n\
_08130EAE:\n\
    ldr r2, [sp, 0x20]\n\
    adds r2, 0x1\n\
    str r2, [sp, 0x20]\n\
    movs r7, 0x2\n\
    add r10, r7\n\
    movs r0, 0x1\n\
    add r8, r0\n\
    mov r1, r8\n\
    cmp r1, 0x3\n\
    bgt _08130EC4\n\
    b _08130D14\n\
_08130EC4:\n\
    mov r0, sp\n\
    ldrh r5, [r0]\n\
    movs r0, 0\n\
    ldr r2, [sp, 0x18]\n\
    strb r0, [r2]\n\
    movs r4, 0x1\n\
    mov r8, r4\n\
    ldr r6, =gBankTarget\n\
    ldr r3, [sp, 0x18]\n\
    mov r1, sp\n\
    adds r1, 0x2\n\
_08130EDA:\n\
    lsls r0, r5, 16\n\
    asrs r2, r0, 16\n\
    movs r7, 0\n\
    ldrsh r0, [r1, r7]\n\
    cmp r2, r0\n\
    bne _08130EEE\n\
    adds r0, r3, r4\n\
    mov r7, r8\n\
    strb r7, [r0]\n\
    adds r4, 0x1\n\
_08130EEE:\n\
    movs r7, 0\n\
    ldrsh r0, [r1, r7]\n\
    cmp r2, r0\n\
    bge _08130EFE\n\
    ldrh r5, [r1]\n\
    mov r0, r8\n\
    strb r0, [r3]\n\
    movs r4, 0x1\n\
_08130EFE:\n\
    adds r1, 0x2\n\
    movs r2, 0x1\n\
    add r8, r2\n\
    mov r7, r8\n\
    cmp r7, 0x3\n\
    ble _08130EDA\n\
    bl Random\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    adds r1, r4, 0\n\
    bl __modsi3\n\
    ldr r1, [sp, 0x18]\n\
    adds r0, r1, r0\n\
    ldrb r0, [r0]\n\
    strb r0, [r6]\n\
    ldrb r0, [r6]\n\
    ldr r2, [sp, 0x1C]\n\
    adds r0, r2, r0\n\
    ldrb r0, [r0]\n\
    add sp, 0x24\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .pool\n\
    .syntax divided\n");
}
#endif

void BattleAI_DoAIProcessing(void)
{
    while (AI_THINKING_STRUCT->aiState != AIState_FinishedProcessing)
    {
        switch (AI_THINKING_STRUCT->aiState)
        {
            case AIState_DoNotProcess: //Needed to match.
                break;
            case AIState_SettingUp:
                gAIScriptPtr = gUnknown_082DBEF8[AI_THINKING_STRUCT->aiLogicId]; // set AI ptr to logic ID.
                if (gBattleMons[gPlayerMonIndex].pp[AI_THINKING_STRUCT->movesetIndex] == 0)
                {
                    AI_THINKING_STRUCT->moveConsidered = 0;
                }
                else
                {
                    AI_THINKING_STRUCT->moveConsidered = gBattleMons[gPlayerMonIndex].moves[AI_THINKING_STRUCT->movesetIndex];
                }
                AI_THINKING_STRUCT->aiState++;
                break;
            case AIState_Processing:
                if (AI_THINKING_STRUCT->moveConsidered != 0)
                    sBattleAICmdTable[*gAIScriptPtr](); // run AI command.
                else
                {
                    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;
                    AI_THINKING_STRUCT->aiAction |= 1;
                }
                if (AI_THINKING_STRUCT->aiAction & 1)
                {
                   AI_THINKING_STRUCT->movesetIndex++;

                    if (AI_THINKING_STRUCT->movesetIndex < 4 && !(AI_THINKING_STRUCT->aiAction & 8))
                        AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    else
                        AI_THINKING_STRUCT->aiState++;

                    AI_THINKING_STRUCT->aiAction &= 0xFE;
                }
                break;
        }
    }
}

void sub_8131074(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleStruct->unk18->unk0[gBankTarget][i] == gLastUsedMove[gBankTarget])
            break;
        if (gBattleStruct->unk18->unk0[gBankTarget][i] != gLastUsedMove[gBankTarget]  //HACK: This redundant condition is a hack to make the asm match.
         && gBattleStruct->unk18->unk0[gBankTarget][i] == 0)
        {
            gBattleStruct->unk18->unk0[gBankTarget][i] = gLastUsedMove[gBankTarget];
            break;
        }
    }
}

void sub_81310F0(u8 a)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gBattleStruct->unk18->unk0[a][i] = 0;
}

void b_history__record_ability_usage_of_player(u8 a, u8 b)
{
    gBattleStruct->unk18->unk40[a] = b;
}

void sub_8131130(u8 a)
{
    gBattleStruct->unk18->unk40[a] = 0;
}

void b_history__record_item_x12_of_player(u8 a, u8 b)
{
    gBattleStruct->unk18->unk44[a] = b;
}

void sub_8131160(u8 a)
{
    gBattleStruct->unk18->unk44[a] = 0;
}

void BattleAICmd_if_random_less_than(void)
{
    u16 random = Random();

    if (random % 256 < gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_random_greater_than(void)
{
    u16 random = Random();

    if (random % 256 > gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_random_equal(void)
{
    u16 random = Random();

    if (random % 256 == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_random_not_equal(void)
{
    u16 random = Random();

    if (random % 256 != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_score(void)
{
    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] += gAIScriptPtr[1]; // add the result to the array of the move consider's score.

    if (AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] < 0) // if the score is negative, flatten it to 0.
        AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;

    gAIScriptPtr += 2; // AI return.
}

void BattleAICmd_if_hp_less_than(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) < gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

void BattleAICmd_if_hp_more_than(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) > gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

void BattleAICmd_if_hp_equal(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) == gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

void BattleAICmd_if_hp_not_equal(void)
{
    u16 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if ((u32)(100 * gBattleMons[index].hp / gBattleMons[index].maxHP) != gAIScriptPtr[2])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

void BattleAICmd_if_status(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status1 & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_not_status(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status1 & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_status2(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status2 & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_not_status2(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gBattleMons[index].status2 & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_status3(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[index] & arg) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_not_status3(void)
{
    u16 index;
    u32 arg;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg = AIScriptRead32(gAIScriptPtr + 2);

    if ((gStatuses3[index] & arg) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_status4(void)
{
    u16 index;
    u32 arg1, arg2;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg1 = battle_get_per_side_status(index) & 1;
    arg2 = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideAffecting[arg1] & arg2) != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_not_status4(void)
{
    u16 index;
    u32 arg1, arg2;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    arg1 = battle_get_per_side_status(index) & 1;
    arg2 = AIScriptRead32(gAIScriptPtr + 2);

    if ((gSideAffecting[arg1] & arg2) == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

void BattleAICmd_if_less_than(void)
{
    if (AI_THINKING_STRUCT->funcResult < gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_more_than(void)
{
    if (AI_THINKING_STRUCT->funcResult > gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_not_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_less_than_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult < *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

void BattleAICmd_if_more_than_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult > *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

void BattleAICmd_if_equal_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult == *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

void BattleAICmd_if_not_equal_32(void)
{
    u8 *temp = AIScriptReadPtr(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult != *temp)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

void BattleAICmd_if_move(void)
{
    u16 move = AIScriptRead16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered == move)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

void BattleAICmd_if_not_move(void)
{
    u16 move = AIScriptRead16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered != move)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

void BattleAICmd_if_in_bytes(void)
{
    u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

void BattleAICmd_if_not_in_bytes(void)
{
    u8 *ptr = AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
}

void BattleAICmd_if_in_words(void)
{
    u16 *ptr = (u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

void BattleAICmd_if_not_in_words(void)
{
    u16 *ptr = (u16 *)AIScriptReadPtr(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 5);
}

void BattleAICmd_if_user_can_damage(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[gPlayerMonIndex].moves[i] != 0
            && gBattleMoves[gBattleMons[gPlayerMonIndex].moves[i]].power != 0)
            break;
    }
    if (i == 4)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

void BattleAICmd_if_user_cant_damage(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[gPlayerMonIndex].moves[i] != 0
         && gBattleMoves[gBattleMons[gPlayerMonIndex].moves[i]].power != 0)
            break;
    }
    if (i != 4)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

void BattleAICmd_get_turn_count(void)
{
    AI_THINKING_STRUCT->funcResult = gUnknown_03005D10[19];
    gAIScriptPtr += 1;
}

void BattleAICmd_get_type(void)
{
    u8 typeVar = gAIScriptPtr[1];

    switch (typeVar)
    {
    case 1: // player primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gPlayerMonIndex].type1;
        break;
    case 0: // enemy primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankTarget].type1;
        break;
    case 3: // player secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gPlayerMonIndex].type2;
        break;
    case 2: // enemy secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBankTarget].type2;
        break;
    case 4: // type of move being pointed to
        AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].type;
        break;
    }
    gAIScriptPtr += 2;
}

// util for double battles? whats this doing in the middle of the battle AI macros?
u8 sub_8131E70(u8 index)
{
    switch (index)
    {
        case 1:
            return gPlayerMonIndex;
        case 0:
        default:
            return gBankTarget;
        case 3:
            return gPlayerMonIndex ^ 2;
        case 2:
            return gBankTarget ^ 2;
    }
}

void BattleAICmd_unk_5F(void)
{
    u8 index = sub_8131E70(gAIScriptPtr[1]);

    if(gBattleMons[index].type1 == gAIScriptPtr[2] || gBattleMons[index].type2 == gAIScriptPtr[2])
    {
        AI_THINKING_STRUCT->funcResult = 1;
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = 0;
    }

    gAIScriptPtr += 3;
}

void BattleAICmd_get_move_power(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power;
    gAIScriptPtr += 1;
}

__attribute__((naked)) // not even going to try. if it doesnt match in ruby, it wont match in emerald (yet).
void BattleAICmd_is_most_powerful_move(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x14\n\
    movs r3, 0\n\
    ldr r0, =gUnknown_085B09C8\n\
    ldrh r1, [r0]\n\
    ldr r5, =0x0000ffff\n\
    ldr r6, =gBattleMoves\n\
    ldr r2, =gBattleStruct\n\
    cmp r1, r5\n\
    beq _08131F86\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldrh r1, [r0, 0x2]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r4, [r0]\n\
    ldr r1, =gUnknown_085B09C8\n\
_08131F76:\n\
    ldrh r0, [r1]\n\
    cmp r4, r0\n\
    beq _08131F86\n\
    adds r1, 0x2\n\
    adds r3, 0x1\n\
    ldrh r0, [r1]\n\
    cmp r0, r5\n\
    bne _08131F76\n\
_08131F86:\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldrh r1, [r0, 0x2]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r6\n\
    ldrb r0, [r0, 0x1]\n\
    cmp r0, 0x1\n\
    bhi _08131F9C\n\
    b _08132126\n\
_08131F9C:\n\
    lsls r0, r3, 1\n\
    ldr r1, =gUnknown_085B09C8\n\
    adds r0, r1\n\
    ldrh r3, [r0]\n\
    ldr r0, =0x0000ffff\n\
    cmp r3, r0\n\
    beq _08131FAC\n\
    b _08132126\n\
_08131FAC:\n\
    ldr r0, =gUnknown_02024400\n\
    movs r1, 0\n\
    strh r1, [r0]\n\
    ldr r0, =gUnknown_0202449C\n\
    ldr r0, [r0]\n\
    strb r1, [r0, 0x13]\n\
    ldr r0, =gUnknown_02024474\n\
    movs r2, 0x1\n\
    strb r2, [r0, 0xE]\n\
    ldr r0, =gBattleMoveFlags\n\
    strb r1, [r0]\n\
    ldr r0, =gCritMultiplier\n\
    strb r2, [r0]\n\
    movs r6, 0\n\
    mov r9, r3\n\
    ldr r2, =gUnknown_085B09C8\n\
    ldrh r2, [r2]\n\
    str r2, [sp, 0x10]\n\
_08131FD0:\n\
    movs r3, 0\n\
    ldr r5, =gBattleMons\n\
    lsls r4, r6, 1\n\
    ldr r7, =gPlayerMonIndex\n\
    lsls r0, r6, 2\n\
    mov r8, r0\n\
    adds r1, r6, 0x1\n\
    mov r10, r1\n\
    ldr r2, [sp, 0x10]\n\
    cmp r2, r9\n\
    beq _08132014\n\
    ldr r2, =gBattleMoves\n\
    ldrb r1, [r7]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    adds r0, r4, r0\n\
    adds r1, r5, 0\n\
    adds r1, 0xC\n\
    adds r0, r1\n\
    ldrh r1, [r0]\n\
    lsls r0, r1, 1\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r2\n\
    ldrb r2, [r0]\n\
    ldr r1, =gUnknown_085B09C8\n\
_08132004:\n\
    ldrh r0, [r1]\n\
    cmp r2, r0\n\
    beq _08132014\n\
    adds r1, 0x2\n\
    adds r3, 0x1\n\
    ldrh r0, [r1]\n\
    cmp r0, r9\n\
    bne _08132004\n\
_08132014:\n\
    ldrb r1, [r7]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    adds r0, r4, r0\n\
    adds r1, r5, 0\n\
    adds r1, 0xC\n\
    adds r1, r0, r1\n\
    ldrh r0, [r1]\n\
    cmp r0, 0\n\
    beq _081320C0\n\
    lsls r0, r3, 1\n\
    ldr r2, =gUnknown_085B09C8\n\
    adds r0, r2\n\
    ldrh r0, [r0]\n\
    cmp r0, r9\n\
    bne _081320C0\n\
    ldr r0, =gBattleMoves\n\
    ldrh r2, [r1]\n\
    lsls r1, r2, 1\n\
    adds r1, r2\n\
    lsls r1, 2\n\
    adds r1, r0\n\
    ldrb r0, [r1, 0x1]\n\
    cmp r0, 0x1\n\
    bls _081320C0\n\
    ldr r5, =gCurrentMove\n\
    strh r2, [r5]\n\
    ldrb r0, [r7]\n\
    ldr r4, =gBankTarget\n\
    ldrb r1, [r4]\n\
    bl sub_8046E7C\n\
    ldrh r0, [r5]\n\
    ldrb r1, [r7]\n\
    ldrb r2, [r4]\n\
    bl move_effectiveness_something\n\
    mov r4, sp\n\
    add r4, r8\n\
    ldr r2, =gBattleMoveDamage\n\
    ldr r0, =gBattleStruct\n\
    ldr r0, [r0]\n\
    ldr r0, [r0, 0x14]\n\
    adds r0, 0x18\n\
    adds r0, r6\n\
    ldrb r1, [r0]\n\
    ldr r0, [r2]\n\
    muls r0, r1\n\
    movs r1, 0x64\n\
    bl __divsi3\n\
    str r0, [r4]\n\
    cmp r0, 0\n\
    bne _081320C8\n\
    movs r0, 0x1\n\
    str r0, [r4]\n\
    b _081320C8\n\
    .pool\n\
_081320C0:\n\
    mov r1, sp\n\
    add r1, r8\n\
    movs r0, 0\n\
    str r0, [r1]\n\
_081320C8:\n\
    mov r6, r10\n\
    cmp r6, 0x3\n\
    bgt _081320D0\n\
    b _08131FD0\n\
_081320D0:\n\
    movs r6, 0\n\
    ldr r2, =gBattleStruct\n\
    ldr r0, [r2]\n\
    ldr r0, [r0, 0x14]\n\
    ldrb r0, [r0, 0x1]\n\
    lsls r0, 2\n\
    add r0, sp\n\
    ldr r1, [sp]\n\
    ldr r0, [r0]\n\
    ldr r5, =gAIScriptPtr\n\
    cmp r1, r0\n\
    bgt _08132106\n\
    adds r4, r2, 0\n\
    mov r3, sp\n\
_081320EC:\n\
    adds r3, 0x4\n\
    adds r6, 0x1\n\
    cmp r6, 0x3\n\
    bgt _08132106\n\
    ldr r0, [r4]\n\
    ldr r0, [r0, 0x14]\n\
    ldrb r0, [r0, 0x1]\n\
    lsls r0, 2\n\
    add r0, sp\n\
    ldr r1, [r3]\n\
    ldr r0, [r0]\n\
    cmp r1, r0\n\
    ble _081320EC\n\
_08132106:\n\
    cmp r6, 0x4\n\
    bne _0813211C\n\
    ldr r0, [r2]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x2\n\
    str r0, [r1, 0x8]\n\
    b _08132130\n\
    .pool\n\
_0813211C:\n\
    ldr r0, [r2]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x1\n\
    str r0, [r1, 0x8]\n\
    b _08132130\n\
_08132126:\n\
    ldr r0, [r2]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0\n\
    str r0, [r1, 0x8]\n\
    ldr r5, =gAIScriptPtr\n\
_08132130:\n\
    ldr r0, [r5]\n\
    adds r0, 0x1\n\
    str r0, [r5]\n\
    add sp, 0x14\n\
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

void BattleAICmd_get_move(void)
{
    if (gAIScriptPtr[1] == USER)
        AI_THINKING_STRUCT->funcResult = gLastUsedMove[gPlayerMonIndex];
    else
        AI_THINKING_STRUCT->funcResult = gLastUsedMove[gBankTarget];

    gAIScriptPtr += 2;
}

void BattleAICmd_if_arg_equal(void)
{
    if (gAIScriptPtr[1] == AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_arg_not_equal(void)
{
    if (gAIScriptPtr[1] != AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_would_go_first(void)
{
    if (b_first_side(gPlayerMonIndex, gBankTarget, 1) == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_would_not_go_first(void)
{
    if (b_first_side(gPlayerMonIndex, gBankTarget, 1) != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_nullsub_2A(void)
{
}

void BattleAICmd_nullsub_2B(void)
{
}

void BattleAICmd_count_alive_pokemon(void)
{
    u8 index;
    u8 var, var2;
    struct Pokemon *party;
    int i;

    AI_THINKING_STRUCT->funcResult = 0;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if (GetBankSide(index) == 0)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 status;
        var = gUnknown_0202406E[index][0];
        status = battle_get_per_side_status(index) ^ 2;
        var2 = gUnknown_0202406E[battle_get_side_with_given_state(status)][0];
    }
    else
    {
        var = gUnknown_0202406E[index][0];
        var2 = gUnknown_0202406E[index][0];
    }

    for (i = 0; i < 6; i++)
    {
        if (i != var && i != var2
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            AI_THINKING_STRUCT->funcResult++;
        }
    }

    gAIScriptPtr += 2;
}

void BattleAICmd_get_considered_move(void)
{
    AI_THINKING_STRUCT->funcResult = AI_THINKING_STRUCT->moveConsidered;
    gAIScriptPtr += 1;
}

void BattleAICmd_get_considered_move_effect(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect;
    gAIScriptPtr += 1;
}

void BattleAICmd_get_ability(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if(gActiveBank != index)
    {
        if(UNK_2016A00_STRUCT->unk40[index] != 0)
        {
            AI_THINKING_STRUCT->funcResult = UNK_2016A00_STRUCT->unk40[index];
            gAIScriptPtr += 2;
            return;
        }

        // abilities that prevent fleeing.
        if (gBattleMons[index].ability == ABILITY_SHADOW_TAG
        || gBattleMons[index].ability == ABILITY_MAGNET_PULL
        || gBattleMons[index].ability == ABILITY_ARENA_TRAP)
        {
            AI_THINKING_STRUCT->funcResult = gBattleMons[index].ability;
            gAIScriptPtr += 2;
            return;
        }

        if (gBaseStats[gBattleMons[index].species].ability1 != ABILITY_NONE)
        {
            if (gBaseStats[gBattleMons[index].species].ability2 != ABILITY_NONE)
            {
                // AI has no knowledge of opponent, so it guesses which ability.
                if(Random() & 1)
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability1;
                }
                else
                {
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability2;
                }
            }
            else
            {
                AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability1; // it's definitely ability 1.
            }
        }
        else
        {
            AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[index].species].ability2; // AI cant actually reach this part since every mon has at least 1 ability.
        }
    }
    else
    {
        // The AI knows its own ability.
        AI_THINKING_STRUCT->funcResult = gBattleMons[index].ability;
    }
    gAIScriptPtr += 2;
}

#ifdef NONMATCHING
void tai60_unk(void)
{
    u8 index = sub_8131E70(gAIScriptPtr[1]);
    u8 arg2 = gAIScriptPtr[2];
    u8 var;

    if(gAIScriptPtr[1] == 0 || gAIScriptPtr[1] == 2)
    {
        // _0813253A
        if(UNK_2016A00_STRUCT->unk40[index] != 0)
        {
            var = UNK_2016A00_STRUCT->unk40[index];
            AI_THINKING_STRUCT->funcResult = var;
        }
        else
        {
            // _0813255C
            if (gBattleMons[index].ability == ABILITY_SHADOW_TAG
            || gBattleMons[index].ability == ABILITY_MAGNET_PULL
            || gBattleMons[index].ability == ABILITY_ARENA_TRAP)
            {
                var = gBattleMons[index].ability;
            }
            else
            {
                // _08132588
                if (gBaseStats[gBattleMons[index].species].ability1 != ABILITY_NONE)
                {
                    if (gBaseStats[gBattleMons[index].species].ability2 != ABILITY_NONE)
                    {
                        if(gBaseStats[gBattleMons[index].species].ability1 != arg2 && gBaseStats[gBattleMons[index].species].ability2 != arg2)
                        {
                            var = 2;
                        }
                        else
                        {
                            var = gBaseStats[gBattleMons[index].species].ability1;
                        }
                    }
                    else
                    {
                        // _081325B4
                        var = gBaseStats[gBattleMons[index].species].ability1;
                    }
                }
                else
                {
                    // _081325B8
                    var = gBaseStats[gBattleMons[index].species].ability2;
                }
            }
        }
    }
    else
    {
        // _081325BC
        var = gBattleMons[index].ability;
    }

    // _081325CA
    if(var == ABILITY_NONE)
    {
        AI_THINKING_STRUCT->funcResult = 2;
    }
    else if(var == arg2)
    {
        AI_THINKING_STRUCT->funcResult = 1;
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = 0;
    }
    gAIScriptPtr += 3;
}
#else
__attribute__((naked))
void tai60_unk(void)
{
    asm(".syntax unified\n\
    push {r4-r6,lr}\n\
    ldr r4, =gAIScriptPtr\n\
    ldr r0, [r4]\n\
    ldrb r0, [r0, 0x1]\n\
    bl sub_8131E70\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    ldr r0, [r4]\n\
    ldrb r3, [r0, 0x2]\n\
    ldrb r0, [r0, 0x1]\n\
    cmp r0, 0\n\
    beq _0813253A\n\
    cmp r0, 0x2\n\
    bne _081325BC\n\
_0813253A:\n\
    ldr r0, =gBattleStruct\n\
    ldr r4, [r0]\n\
    ldr r1, [r4, 0x18]\n\
    adds r1, 0x40\n\
    adds r2, r1, r5\n\
    ldrb r1, [r2]\n\
    adds r6, r0, 0\n\
    cmp r1, 0\n\
    beq _0813255C\n\
    adds r3, r1, 0\n\
    ldr r0, [r4, 0x14]\n\
    str r3, [r0, 0x8]\n\
    b _081325CA\n\
    .pool\n\
_0813255C:\n\
    ldr r1, =gBattleMons\n\
    movs r0, 0x58\n\
    muls r0, r5\n\
    adds r4, r0, r1\n\
    adds r0, r4, 0\n\
    adds r0, 0x20\n\
    ldrb r0, [r0]\n\
    cmp r0, 0x17\n\
    beq _08132576\n\
    cmp r0, 0x2A\n\
    beq _08132576\n\
    cmp r0, 0x47\n\
    bne _08132588\n\
_08132576:\n\
    movs r0, 0x58\n\
    muls r0, r5\n\
    adds r0, r1\n\
    adds r0, 0x20\n\
    ldrb r3, [r0]\n\
    b _081325CA\n\
    .pool\n\
_08132588:\n\
    ldr r2, =gBaseStats\n\
    ldrh r1, [r4]\n\
    lsls r0, r1, 3\n\
    subs r0, r1\n\
    lsls r0, 2\n\
    adds r1, r0, r2\n\
    ldrb r4, [r1, 0x16]\n\
    cmp r4, 0\n\
    beq _081325B8\n\
    ldrb r2, [r1, 0x17]\n\
    cmp r2, 0\n\
    beq _081325B4\n\
    adds r0, r3, 0\n\
    cmp r4, r0\n\
    beq _081325CE\n\
    cmp r2, r0\n\
    beq _081325CE\n\
    adds r3, r4, 0\n\
    b _081325CA\n\
    .pool\n\
_081325B4:\n\
    ldrb r3, [r1, 0x16]\n\
    b _081325CA\n\
_081325B8:\n\
    ldrb r3, [r1, 0x17]\n\
    b _081325CA\n\
_081325BC:\n\
    ldr r1, =gBattleMons\n\
    movs r0, 0x58\n\
    muls r0, r5\n\
    adds r0, r1\n\
    adds r0, 0x20\n\
    ldrb r3, [r0]\n\
    ldr r6, =gBattleStruct\n\
_081325CA:\n\
    cmp r3, 0\n\
    bne _081325E8\n\
_081325CE:\n\
    ldr r0, [r6]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x2\n\
    str r0, [r1, 0x8]\n\
    ldr r2, =gAIScriptPtr\n\
    b _08132608\n\
    .pool\n\
_081325E8:\n\
    ldr r0, =gAIScriptPtr\n\
    ldr r1, [r0]\n\
    adds r2, r0, 0\n\
    ldrb r1, [r1, 0x2]\n\
    cmp r3, r1\n\
    bne _08132600\n\
    ldr r0, [r6]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0x1\n\
    b _08132606\n\
    .pool\n\
_08132600:\n\
    ldr r0, [r6]\n\
    ldr r1, [r0, 0x14]\n\
    movs r0, 0\n\
_08132606:\n\
    str r0, [r1, 0x8]\n\
_08132608:\n\
    ldr r0, [r2]\n\
    adds r0, 0x3\n\
    str r0, [r2]\n\
    pop {r4-r6}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided");
}
#endif

void BattleAICmd_get_highest_possible_damage(void)
{
    s32 i;

    gUnknown_02024400 = 0;
    gUnknown_0202449C[0x13] = 0;
    gUnknown_02024474[0xE] = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    AI_THINKING_STRUCT->funcResult = 0;

    for (i = 0; i < 4; i++)
    {
        gBattleMoveDamage = 40;
        gCurrentMove = gBattleMons[gPlayerMonIndex].moves[i];

        if (gCurrentMove)
        {
            move_effectiveness_something(gCurrentMove, gPlayerMonIndex, gBankTarget);

            // reduce by 1/3.
            if (gBattleMoveDamage == 120)
                gBattleMoveDamage = 80;
            if (gBattleMoveDamage == 240)
                gBattleMoveDamage = 160;
            if (gBattleMoveDamage == 30)
                gBattleMoveDamage = 20;
            if (gBattleMoveDamage == 15)
                gBattleMoveDamage = 10;

            if (gBattleMoveFlags & 8) // if it's a status move, it wont do anything.
                gBattleMoveDamage = 0;

            if (AI_THINKING_STRUCT->funcResult < gBattleMoveDamage)
                AI_THINKING_STRUCT->funcResult = gBattleMoveDamage;
        }
    }
    gAIScriptPtr += 1;
}

void BattleAICmd_if_damage_bonus(void)
{
    u8 damageVar;

    gUnknown_02024400 = 0;
    gUnknown_0202449C[0x13] = 0;
    gUnknown_02024474[0xE] = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;

    gBattleMoveDamage = 40;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;

    move_effectiveness_something(gCurrentMove, gPlayerMonIndex, gBankTarget);

    if (gBattleMoveDamage == 120)
        gBattleMoveDamage = 80;
    if (gBattleMoveDamage == 240)
        gBattleMoveDamage = 160;
    if (gBattleMoveDamage == 30)
        gBattleMoveDamage = 20;
    if (gBattleMoveDamage == 15)
        gBattleMoveDamage = 10;

    if (gBattleMoveFlags & 8)
        gBattleMoveDamage = 0;

    // store gBattleMoveDamage in a u8 variable because gAIScriptPtr[1] is a u8.
    damageVar = gBattleMoveDamage;

    if (damageVar == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_nullsub_32(void)
{
}

void BattleAICmd_nullsub_33(void)
{
}

void BattleAICmd_if_status_in_party(void)
{
    struct Pokemon *party;
    int i;
    u32 statusToCompareTo;
    u8 index;

    switch(gAIScriptPtr[1])
    {
        case 1:
            index = gPlayerMonIndex;
            break;
        default:
            index = gBankTarget;
            break;
    }

    party = (GetBankSide(index) == 0) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < 6; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
            return;
        }
    }

    gAIScriptPtr += 10;
}

void BattleAICmd_if_status_not_in_party(void)
{
    struct Pokemon *party;
    int i;
    u32 statusToCompareTo;
    u8 index;

    switch(gAIScriptPtr[1])
    {
        case 1:
            index = gPlayerMonIndex;
            break;
        default:
            index = gBankTarget;
            break;
    }

    party = (GetBankSide(index) == 0) ? gPlayerParty : gEnemyParty;

    statusToCompareTo = AIScriptRead32(gAIScriptPtr + 2);

    for (i = 0; i < 6; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gAIScriptPtr += 10; // still bugged in Emerald
        }
    }

    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 6);
}

void BattleAICmd_get_weather(void)
{
    if (gBattleWeather & 7)
        AI_THINKING_STRUCT->funcResult = 1;
    if (gBattleWeather & 0x18)
        AI_THINKING_STRUCT->funcResult = 2;
    if (gBattleWeather & 0x60)
        AI_THINKING_STRUCT->funcResult = 0;
    if (gBattleWeather & 0x80)
        AI_THINKING_STRUCT->funcResult = 3;

    gAIScriptPtr += 1;
}

void BattleAICmd_if_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect == gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_not_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect != gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void BattleAICmd_if_stat_level_less_than(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gPlayerMonIndex;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] < gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

void BattleAICmd_if_stat_level_more_than(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gPlayerMonIndex;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] > gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

void BattleAICmd_if_stat_level_equal(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gPlayerMonIndex;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] == gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

void BattleAICmd_if_stat_level_not_equal(void)
{
    u32 party;

    if (gAIScriptPtr[1] == USER)
        party = gPlayerMonIndex;
    else
        party = gBankTarget;

    if (gBattleMons[party].statStages[gAIScriptPtr[2]] != gAIScriptPtr[3])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

void BattleAICmd_if_can_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gUnknown_02024400 = 0;
    gUnknown_0202449C[0x13] = 0;
    gUnknown_02024474[0xE] = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    sub_8046E7C(gPlayerMonIndex, gBankTarget);
    move_effectiveness_something(gCurrentMove, gPlayerMonIndex, gBankTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->unk18[AI_THINKING_STRUCT->movesetIndex] / 100;

    // moves always do at least 1 damage.
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    if (gBattleMons[gBankTarget].hp <= gBattleMoveDamage)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

void BattleAICmd_if_cant_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gUnknown_02024400 = 0;
    gUnknown_0202449C[0x13] = 0;
    gUnknown_02024474[0xE] = 1;
    gBattleMoveFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    sub_8046E7C(gPlayerMonIndex, gBankTarget);
    move_effectiveness_something(gCurrentMove, gPlayerMonIndex, gBankTarget);

    gBattleMoveDamage = gBattleMoveDamage * AI_THINKING_STRUCT->unk18[AI_THINKING_STRUCT->movesetIndex] / 100;

    // this macro is missing the damage 0 = 1 assumption.

    if (gBattleMons[gBankTarget].hp > gBattleMoveDamage)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

void BattleAICmd_if_has_move(void)
{
    int i;
    u16 *temp_ptr = (u16 *)(gAIScriptPtr + 2);

    switch(gAIScriptPtr[1])
    {
        case 1:
            // _08132E42
            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[gPlayerMonIndex].moves[i] == *temp_ptr)
                    break;
            }
            if (i == 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
        case 3: // new to Emerald
            if(gBattleMons[gPlayerMonIndex ^ 2].hp == 0)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                for (i = 0; i < 4; i++)
                {
                    if (gBattleMons[gPlayerMonIndex ^ 2].moves[i] == *temp_ptr)
                        break;
                }
            }
            if (i == 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
        case 0:
        case 2:
            for (i = 0; i < 4; i++)
            {
                if (UNK_2016A00_STRUCT->unk0[gBankTarget][i] == *temp_ptr)
                    break;
            }
            if (i == 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
    }
}

void BattleAICmd_if_dont_have_move(void)
{
    int i;
    u16 *temp_ptr = (u16 *)(gAIScriptPtr + 2);

    switch(gAIScriptPtr[1])
    {
        case 1:
        case 3: // if_dont_have_move does not have the seperate 3 case check in Emerald unlike if_has_move.
            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[gPlayerMonIndex].moves[i] == *temp_ptr)
                    break;
            }
            if (i != 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
        case 0:
        case 2:
            for (i = 0; i < 4; i++)
            {
                if (UNK_2016A00_STRUCT->unk0[gBankTarget][i] == *temp_ptr)
                    break;
            }
            if (i != 4)
            {
                gAIScriptPtr += 8;
                return;
            }
            else
            {
                gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
                return;
            }
    }
}

void BattleAICmd_if_move_effect(void)
{
    int i;

    switch (gAIScriptPtr[1])
    {
    case 1:
    case 3: // _08133044
        for(i = 0; i < 4; i++)
        {
            if(gBattleMons[gPlayerMonIndex].moves[i] != 0 && gBattleMoves[gBattleMons[gPlayerMonIndex].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i == 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    case 0:
    case 2: // _08133090
        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[gPlayerMonIndex].moves[i] != 0 && gBattleMoves[UNK_2016A00_STRUCT->unk0[gBankTarget][i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i == 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    }
}

void BattleAICmd_if_not_move_effect(void)
{
    int i;

    switch (gAIScriptPtr[1])
    {
    case 1:
    case 3: // _0813313C
        for(i = 0; i < 4; i++)
        {
            if(gBattleMons[gPlayerMonIndex].moves[i] != 0 && gBattleMoves[gBattleMons[gPlayerMonIndex].moves[i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    case 0:
    case 2: // _08133188
        for (i = 0; i < 4; i++)
        {
            if (UNK_2016A00_STRUCT->unk0[gBankTarget][i] && gBattleMoves[UNK_2016A00_STRUCT->unk0[gBankTarget][i]].effect == gAIScriptPtr[2])
                break;
        }
        if (i != 4)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        break;
    }
}

void BattleAICmd_if_last_move_did_damage(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if (gAIScriptPtr[2] == 0)
    {
        if (gDisableStructs[index].disabledMove == 0)
        {
            gAIScriptPtr += 7;
            return;
        }
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        return;
    }
    else if (gAIScriptPtr[2] != 1) // ignore the macro if its not 0 or 1.
    {
        gAIScriptPtr += 7;
        return;
    }
    else if (gDisableStructs[index].encoredMove != 0)
    {
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 3);
        return;
    }
    gAIScriptPtr += 7;
}

void BattleAICmd_if_encored(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0: // _08109348
        if (gDisableStructs[gActiveBank].disabledMove == AI_THINKING_STRUCT->moveConsidered)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1: // _08109370
        if (gDisableStructs[gActiveBank].encoredMove == AI_THINKING_STRUCT->moveConsidered)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    default:
        gAIScriptPtr += 6;
        return;
    }
}

void BattleAICmd_flee(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_UNK1 | AI_ACTION_UNK2 | AI_ACTION_UNK4); // what matters is UNK2 being enabled.
}

void BattleAICmd_if_random_100(void)
{
    u8 safariFleeRate = gUnknown_0202449C[0x7B] * 5; // safari flee rate, from 0-20

    if ((u8)(Random() % 100) < safariFleeRate)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

void BattleAICmd_watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_UNK1 | AI_ACTION_UNK3 | AI_ACTION_UNK4); // what matters is UNK3 being enabled.
}

void BattleAICmd_get_hold_effect(void)
{
    u8 index;
    u16 status;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    if (gActiveBank != index)
    {
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(UNK_2016A00_STRUCT->unk44[index]);
    }
    else
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(gBattleMons[index].item);

    gAIScriptPtr += 2;
}

void tai62_unk(void)
{
    u8 index = sub_8131E70(gAIScriptPtr[1]);
    u16 item;
    u8 var1, var2;

    if((index & 1) == (gPlayerMonIndex & 1))
        item = gBattleMons[index].item;
    else
        item = UNK_2016A00_STRUCT->unk44[index];

    // strange way of loading a 16-bit argument from the AI command.
    var2 = gAIScriptPtr[2];
    var1 = gAIScriptPtr[3];

    if((var1 | var2) == item)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

void BattleAICmd_get_gender(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = pokemon_species_get_gender_info(gBattleMons[index].species, gBattleMons[index].personality);

    gAIScriptPtr += 2;
}

void BattleAICmd_is_first_turn(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[index].isFirstTurn;

    gAIScriptPtr += 2;
}

void BattleAICmd_get_stockpile_count(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[index].stockpileCounter;

    gAIScriptPtr += 2;
}

void BattleAICmd_is_double_battle(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleTypeFlags & BATTLE_TYPE_DOUBLE;

    gAIScriptPtr += 1;
}

void BattleAICmd_get_item(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    // this hack and a half matches. whatever. i dont care. someone else fix this mess later. PS: still cant fix this.
    AI_THINKING_STRUCT->funcResult = gUnknown_0202449C[0xB8 + (index * 2)];

    gAIScriptPtr += 2;
}

void BattleAICmd_get_move_type_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].type;

    gAIScriptPtr += 1;
}

void BattleAICmd_get_move_power_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].power;

    gAIScriptPtr += 1;
}

void BattleAICmd_get_move_effect_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].effect;

    gAIScriptPtr += 1;
}

void BattleAICmd_get_protect_count(void)
{
    u8 index;

    if (gAIScriptPtr[1] == USER)
        index = gPlayerMonIndex;
    else
        index = gBankTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[index].protectUses;

    gAIScriptPtr += 2;
}

void BattleAICmd_nullsub_52(void)
{
}

void BattleAICmd_nullsub_53(void)
{
}

void BattleAICmd_nullsub_54(void)
{
}

void BattleAICmd_nullsub_55(void)
{
}

void BattleAICmd_nullsub_56(void)
{
}

void BattleAICmd_nullsub_57(void)
{
}

void BattleAICmd_call(void)
{
    b_mc_stack_push(gAIScriptPtr + 5);
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

void BattleAICmd_jump(void)
{
    gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
}

void BattleAICmd_end(void)
{
    if (b_mc_stack_pop_cursor() == 0)
        AI_THINKING_STRUCT->aiAction |= AI_ACTION_UNK1;
}

void BattleAICmd_if_level_cond(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0: // greater than
        if (gBattleMons[gPlayerMonIndex].level > gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 1: // less than
        if (gBattleMons[gPlayerMonIndex].level < gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    case 2: // equal
        if (gBattleMons[gPlayerMonIndex].level == gBattleMons[gBankTarget].level)
        {
            gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
            return;
        }
        gAIScriptPtr += 6;
        return;
    }
}

void BattleAICmd_if_taunted(void)
{
    if (gDisableStructs[gBankTarget].tauntTimer1 != 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

void BattleAICmd_if_not_taunted(void)
{
    if (gDisableStructs[gBankTarget].tauntTimer1 == 0)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

void tai5E_unk(void)
{
    if((gPlayerMonIndex & 1) == (gBankTarget & 1))
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

void tai61_unk(void)
{
    u8 index = sub_8131E70(gAIScriptPtr[1]);

    if(UNK_BATTLE_STRUCT->unk4->unkArray[index] & 1)
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

void b_mc_stack_push(u8 *var)
{
    UNK_2016C00_STRUCT->ptr[UNK_2016C00_STRUCT->unk20++] = var;
}

void b_mc_stack_push_cursor(void)
{
    UNK_2016C00_STRUCT->ptr[UNK_2016C00_STRUCT->unk20++] = gAIScriptPtr;
}

bool8 b_mc_stack_pop_cursor(void)
{
    if (UNK_2016C00_STRUCT->unk20 != 0)
    {
        --UNK_2016C00_STRUCT->unk20;
        gAIScriptPtr = UNK_2016C00_STRUCT->ptr[UNK_2016C00_STRUCT->unk20];
        return TRUE;
    }
    else
        return FALSE;
}
