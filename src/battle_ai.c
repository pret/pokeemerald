#include "global.h"

#define AIScriptRead32(ptr) ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24)
#define AIScriptRead16(ptr) ((ptr)[0] | (ptr)[1] << 8)
#define AIScriptRead8(ptr) ((ptr)[0])
#define AIScriptReadPtr(ptr) (u8*) AIScriptRead32(ptr)

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

#define POKEMON_NAME_LENGTH 10

struct BattlePokemon
{
 /* 0x00 */ u16 species;
 /* 0x02 */ u16 attack;
 /* 0x04 */ u16 defense;
 /* 0x06 */ u16 speed;
 /* 0x08 */ u16 spAttack;
 /* 0x0A */ u16 spDefense;
 /* 0x0C */ u16 moves[4];
 /* 0x14 */ u32 hpIV:5;
 /* 0x14 */ u32 attackIV:5;
 /* 0x15 */ u32 defenseIV:5;
 /* 0x15 */ u32 speedIV:5;
 /* 0x16 */ u32 spAttackIV:5;
 /* 0x17 */ u32 spDefenseIV:5;
 /* 0x17 */ u32 isEgg:1;
 /* 0x17 */ u32 altAbility:1;
 /* 0x18 */ s8 statStages[8];
 /* 0x20 */ u8 ability;
 /* 0x21 */ u8 type1;
 /* 0x22 */ u8 type2;
 /* 0x23 */ u8 unknown;
 /* 0x24 */ u8 pp[4];
 /* 0x28 */ u16 hp;
 /* 0x2A */ u8 level;
 /* 0x2B */ u8 friendship;
 /* 0x2C */ u16 maxHP;
 /* 0x2E */ u16 item;
 /* 0x30 */ u8 nickname[POKEMON_NAME_LENGTH + 1];
 /* 0x3B */ u8 ppBonuses;
 /* 0x3C */ u8 otName[8];
 /* 0x44 */ u32 experience;
 /* 0x48 */ u32 personality;
 /* 0x4C */ u32 status1;
 /* 0x50 */ u32 status2;
 /* 0x54 */ u32 otId;
};

//size should be 0x1C
struct UnknownStruct3
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    s8 unk4[4];
    u8 filler8[4];
    u32 unkC;
    u8 unk10;
    u8 unk11;
    u8 filler12[6];
    u8 unk18[4];
};

//size should be 0x54
struct UnknownStruct2
{
    u16 unk0[2][8];
    u8 filler20[0x20];
    u8 unk40[4];
    u8 unk44[4];
    u16 unk48[4];
    u8 unk50;
};

struct UnknownStruct4
{
    u8 filler0[0x20];
    u8 unk20;
};

struct UnknownStruct1
{
    u8 unk0;
    u8 filler1[0x13];
    struct UnknownStruct3 *unk14;
    struct UnknownStruct2 *unk18;
    struct UnknownStruct4 *unk1C;
};

extern u32 gBattleTypeFlags;
extern u8 gUnknown_02024064;
extern struct BattlePokemon gBattleMons[];
extern u16 gUnknown_020241EA;
extern u8 gUnknown_0202420C;
extern u8 gUnknown_02024210;
extern u16 gUnknown_02024248[];
extern u8 *gUnknown_0202449C;
extern struct UnknownStruct1 *gUnknown_020244A8;
extern u16 gUnknown_02038BCA;
extern u16 gUnknown_02038BCC;
extern const u8 *gAIScriptPtr;
extern u8 gUnknown_0203AB3C;
extern struct Trainer gTrainers[];
extern const u32 gBitTable[];
extern const u8 *const gUnknown_082DBEF8[];

typedef void (*BattleAICmdFunc)(void);

extern const BattleAICmdFunc gUnknown_085B083C[];

extern u8 sub_803FECC();
extern u16 Random();
extern u32 battle_side_get_owner();
extern u32 sub_8186438();
extern u32 sub_81A6FB4();

void BattleAI_SetupAIData(u8 a);
u8 sub_8130BDC(void);
u8 sub_8130CF4(void);
void sub_8131074(void);
void BattleAI_DoAIProcessing(void);

void BattleAI_HandleItemUseBeforeAISetup(u8 a)
{
    s32 i;
    u8 *data = (u8 *)gUnknown_020244A8->unk18;
    
    for (i = 0; (u32)i < 0x54; i++)
        data[i] = 0;
    if ((gBattleTypeFlags & 0x0A7F098A) == 8)
    {
        for (i = 0; i < 4; i++)
        {
            if (gTrainers[gUnknown_02038BCA].items[i] != 0)
            {
                gUnknown_020244A8->unk18->unk48[gUnknown_020244A8->unk18->unk50] = gTrainers[gUnknown_02038BCA].items[i];
                gUnknown_020244A8->unk18->unk50++;
            }
        }
    }
    
    BattleAI_SetupAIData(a);
}

void BattleAI_SetupAIData(u8 a)
{
    s32 i;
    u8 *data = (u8 *)gUnknown_020244A8->unk14;
    u8 r6;
    
    for (i = 0; (u32)i < 0x1C; i++)
        data[i] = 0;
    for (i = 0; i < 4; i++)
    {
        if (a & 1)
            gUnknown_020244A8->unk14->unk4[i] = 100;
        else
            gUnknown_020244A8->unk14->unk4[i] = 0;
        a >>= 1;
    }
    r6 = sub_803FECC(gUnknown_02024064, 0, 0xFF);
    for (i = 0; i < 4; i++)
    {
        if (gBitTable[i] & r6)
            gUnknown_020244A8->unk14->unk4[i] = 0;
        gUnknown_020244A8->unk14->unk18[i] = 100 - (Random() % 16);
    }
    gUnknown_020244A8->unk1C->unk20 = 0;
    gUnknown_0203AB3C = gUnknown_02024064;
    if (gBattleTypeFlags & 1)
    {
        gUnknown_0202420C = (Random() & 2) + (battle_side_get_owner(gUnknown_02024064) ^ 1);
        if (gUnknown_02024210 & gBitTable[gUnknown_0202420C])
            gUnknown_0202420C ^= 2;
    }
    else
    {
        //_08130A60
        gUnknown_0202420C = gUnknown_0203AB3C ^ 1;
    }
    //_08130A68
    if (gBattleTypeFlags & 0x1000000)
        gUnknown_020244A8->unk14->unkC = sub_8186438();
    else if (gBattleTypeFlags & 0x80)
        gUnknown_020244A8->unk14->unkC = 0x40000000;
    else if (gBattleTypeFlags & 0x400)
        gUnknown_020244A8->unk14->unkC = 0x20000000;
    else if (gBattleTypeFlags & 0x10)
        gUnknown_020244A8->unk14->unkC = 0x80000000;
    else if (gBattleTypeFlags & 0x80000)
        gUnknown_020244A8->unk14->unkC = sub_81A6FB4();
    else if (gBattleTypeFlags & 0x0C3F0900)
        gUnknown_020244A8->unk14->unkC = 7;
    else if (gBattleTypeFlags & 0x8000)
        gUnknown_020244A8->unk14->unkC = gTrainers[gUnknown_02038BCA].aiFlags | gTrainers[gUnknown_02038BCC].aiFlags;
    else
        gUnknown_020244A8->unk14->unkC = gTrainers[gUnknown_02038BCA].aiFlags;
    if (gBattleTypeFlags & 1)
        gUnknown_020244A8->unk14->unkC |= 0x80;
}

u8 sub_8130BA4(void)
{
    u16 r4 = gUnknown_020241EA;
    u8 ret;
    
    if (!(gBattleTypeFlags & 1))
        ret = sub_8130BDC();
    else
        ret = sub_8130CF4();
    gUnknown_020241EA = r4;
    return ret;
}

u8 sub_8130BDC(void)
{
    u8 r6;
    s32 i;
    u8 arr1[4];
    u8 arr2[4];
    
    sub_8131074();
    while (gUnknown_020244A8->unk14->unkC != 0)
    {
        if (gUnknown_020244A8->unk14->unkC & 1)
        {
            gUnknown_020244A8->unk14->unk0 = 0;
            BattleAI_DoAIProcessing();
        }
        gUnknown_020244A8->unk14->unkC >>= 1;
        gUnknown_020244A8->unk14->unk11++;
        gUnknown_020244A8->unk14->unk1 = 0;
    }
    //_08130C2C
    if (gUnknown_020244A8->unk14->unk10 & 2)
        return 4;
    if (gUnknown_020244A8->unk14->unk10 & 4)
        return 5;
    r6 = 1;
    arr1[0] = gUnknown_020244A8->unk14->unk4[0];
    arr2[0] = 0;
    for (i = 1; i < 4; i++)
    {
        if (gBattleMons[gUnknown_0203AB3C].moves[i] != 0)
        {
            if (arr1[0] == gUnknown_020244A8->unk14->unk4[i])
            {
                arr1[r6] = gUnknown_020244A8->unk14->unk4[i];
                arr2[r6++] = i;
            }
            //_08130CAA
            if (arr1[0] < gUnknown_020244A8->unk14->unk4[i])
            {
                r6 = 1;
                arr1[0] = gUnknown_020244A8->unk14->unk4[i];
                arr2[0] = i;
            }
        }
        //_08130CC6
    }
    return arr2[Random() % r6];
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
        if (i == gUnknown_0203AB3C || gBattleMons[i].hp == 0)
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
            gUnknown_0202420C = i;
            if ((i & 1) != (gUnknown_0203AB3C & 1))
                sub_8131074();
            //_08130D90
            gUnknown_020244A8->unk14->unk11 = 0;
            gUnknown_020244A8->unk14->unk1 = 0;
            r4 = gUnknown_020244A8->unk14->unkC;
            while (r4 != 0)
            {
                if (r4 & 1)
                {
                    gUnknown_020244A8->unk14->unk0 = 0;
                    BattleAI_DoAIProcessing();
                }
                r4 >>= 1;
                gUnknown_020244A8->unk14->unk11++;
                gUnknown_020244A8->unk14->unk1 = 0;
            }
            //_08130DD8
            if (gUnknown_020244A8->unk14->unk10 & 2)
                spC[i] = 4;
            else if (gUnknown_020244A8->unk14->unk10 & 4)
                spC[i] = 5;
            else
            {
                //_08130E10
                sp10[0] = gUnknown_020244A8->unk14->unk4[0];
                sp14[0] = 0;
                r5 = 1;
                for (j = 1; j < 4; j++)
                {
                    if (gBattleMons[gUnknown_0203AB3C].moves[j] != 0)
                    {
                        if (sp10[0] == gUnknown_020244A8->unk14->unk4[j])
                        {
                            sp10[r5] = gUnknown_020244A8->unk14->unk4[j];
                            sp14[r5] = j;
                            r5++;
                        }
                        if (sp10[0] < gUnknown_020244A8->unk14->unk4[j])
                        {
                            sp10[0] = gUnknown_020244A8->unk14->unk4[j];
                            sp14[0] = j;
                            r5 = 1;
                        }
                    }
                    //_08130E72
                }
                spC[i] = sp14[Random() % r5];
                //asm("":::"r3");
                sp0[i] = sp10[0];
                if (i == (gUnknown_0203AB3C ^ 2) && sp0[i] < 100)
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
    gUnknown_0202420C = sp8[Random() % r4_2];
    return spC[gUnknown_0202420C];
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
    ldr r0, =gUnknown_0203AB3C\n\
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
    ldr r0, =gUnknown_0202420C\n\
    mov r1, r8\n\
    strb r1, [r0]\n\
    movs r1, 0x1\n\
    mov r2, r8\n\
    ands r2, r1\n\
    ldr r0, =gUnknown_0203AB3C\n\
    ldrb r0, [r0]\n\
    ands r1, r0\n\
    cmp r2, r1\n\
    beq _08130D90\n\
    bl sub_8131074\n\
_08130D90:\n\
    ldr r2, =gUnknown_020244A8\n\
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
    ldr r0, =gUnknown_0203AB3C\n\
    ldrb r1, [r0]\n\
    movs r0, 0x58\n\
    muls r0, r1\n\
    ldr r2, =gUnknown_02024090\n\
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
    ldr r0, =gUnknown_0203AB3C\n\
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
    ldr r6, =gUnknown_0202420C\n\
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
    while (gUnknown_020244A8->unk14->unk0 != 2)
    {
        switch (gUnknown_020244A8->unk14->unk0)
        {
            case 3: //Needed to match.
                break;
            case 0:
                gAIScriptPtr = gUnknown_082DBEF8[gUnknown_020244A8->unk14->unk11];
                if (gBattleMons[gUnknown_0203AB3C].pp[gUnknown_020244A8->unk14->unk1] == 0)
                {
                    gUnknown_020244A8->unk14->unk2 = 0;
                }
                else
                {
                    gUnknown_020244A8->unk14->unk2 = gBattleMons[gUnknown_0203AB3C].moves[gUnknown_020244A8->unk14->unk1];
                }
                gUnknown_020244A8->unk14->unk0++;
                break;
            case 1:
                if (gUnknown_020244A8->unk14->unk2 != 0)
                    gUnknown_085B083C[*gAIScriptPtr]();
                else
                {
                    gUnknown_020244A8->unk14->unk4[gUnknown_020244A8->unk14->unk1] = 0;
                    gUnknown_020244A8->unk14->unk10 |= 1;
                }
                if (gUnknown_020244A8->unk14->unk10 & 1)
                {
                    gUnknown_020244A8->unk14->unk1++;
                    if (gUnknown_020244A8->unk14->unk1 < 4 && !(gUnknown_020244A8->unk14->unk10 & 8))
                        gUnknown_020244A8->unk14->unk0 = 0;
                    else
                        gUnknown_020244A8->unk14->unk0++;
                    gUnknown_020244A8->unk14->unk10 &= 0xFE;
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
        if (gUnknown_020244A8->unk18->unk0[gUnknown_0202420C][i] == gUnknown_02024248[gUnknown_0202420C])
            break;
        if (gUnknown_020244A8->unk18->unk0[gUnknown_0202420C][i] != gUnknown_02024248[gUnknown_0202420C]  //HACK: This redundant condition is a hack to make the asm match.
         && gUnknown_020244A8->unk18->unk0[gUnknown_0202420C][i] == 0)
        {
            gUnknown_020244A8->unk18->unk0[gUnknown_0202420C][i] = gUnknown_02024248[gUnknown_0202420C];
            break;
        }
    }
}

void sub_81310F0(u8 a)
{
    s32 i;
    
    for (i = 0; i < 4; i++)
        gUnknown_020244A8->unk18->unk0[a][i] = 0;
}

void b_history__record_ability_usage_of_player(u8 a, u8 b)
{
    gUnknown_020244A8->unk18->unk40[a] = b;
}

void sub_8131130(u8 a)
{
    gUnknown_020244A8->unk18->unk40[a] = 0;
}

void b_history__record_item_x12_of_player(u8 a, u8 b)
{
    gUnknown_020244A8->unk18->unk44[a] = b;
}

void sub_8131160(u8 a)
{
    gUnknown_020244A8->unk18->unk44[a] = 0;
}

void BattleAICmd_if_random(void)
{
    u16 random = Random();
    
    if ((random & 0xFF) < gAIScriptPtr[1])
        gAIScriptPtr = AIScriptReadPtr(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}
