#include "global.h"
#include "fldeff_softboiled.h"
#include "menu.h"
#include "party_menu.h"
#include "pokemon.h"
//#include "pokemon_menu.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"

void sub_816166C(u8 taskId);
void sub_81617B8(u8 taskId);
void sub_81616C0(u8 taskId);
void sub_81B1F18(u8 taskId, u8 pokemonIdx, s8 a, s16 hp, TaskFunc func);

bool8 SetUpFieldMove_SoftBoiled(void)
{
    u16 maxHp;
    u16 hp;
    u16 minHp;

    maxHp = GetMonData(&gPlayerParty[GetCursorSelectionMonId()], MON_DATA_MAX_HP);
    hp = GetMonData(&gPlayerParty[GetCursorSelectionMonId()], MON_DATA_HP);

    minHp = (maxHp / 5);
    if (hp > minHp)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_8161560(u8 taskId)
{
    gUnknown_0203CEC8.unkB = 0xA;
    gUnknown_0203CEC8.unkA =  gUnknown_0203CEC8.unk9;
    sub_81B0FCC(GetCursorSelectionMonId(), 0x1);
    display_pokemon_menu_message(0x5);
    gTasks[taskId].func = sub_81B1370;
}

void sub_81615A8(u8 taskId)
{
    u16 hp;

    u8 unk9 = gUnknown_0203CEC8.unk9;
    u8 pokemonIndex = gUnknown_0203CEC8.unkA;
    if(pokemonIndex > 6)
    {
        gUnknown_0203CEC8.unkB = 0;
        display_pokemon_menu_message(0x0);
        gTasks[taskId].func = sub_81B1370;
        return;
    }

    hp = GetMonData(&gPlayerParty[pokemonIndex], MON_DATA_HP);
    if(hp == 0 || unk9 == pokemonIndex || GetMonData(&gPlayerParty[pokemonIndex], MON_DATA_MAX_HP) == hp)
    {
        sub_81617B8(taskId);
        return;
    }

    PlaySE(SE_KAIFUKU);
    sub_81B1F18(taskId, unk9, -1, GetMonData(&gPlayerParty[unk9], MON_DATA_MAX_HP)/5, sub_816166C);
}

#ifdef NONMATCHING
void sub_816166C(u8 taskId)
{
    PlaySE(SE_KAIFUKU);
    sub_81B1F18(taskId, gUnknown_0203CEC8.unkA, 1, GetMonData(&gPlayerParty[gUnknown_0203CEC8.unk9], MON_DATA_MAX_HP)/5, sub_81616C0);
}
#else
__attribute__((naked))
void sub_816166C(u8 taskId)
{
    asm(".syntax unified\n\
    push {r4,r5,lr}\n\
    sub sp, 0x4\n\
    adds r4, r0, 0\n\
    lsls r4, 24\n\
    lsrs r4, 24\n\
    movs r0, 0x1\n\
    bl PlaySE\n\
    ldr r5, =gUnknown_0203CEC8\n\
    movs r1, 0x9\n\
    ldrsb r1, [r5, r1]\n\
    movs r0, 0x64\n\
    muls r0, r1\n\
    ldr r1, =gPlayerParty\n\
    adds r0, r1\n\
    movs r1, 0x3A\n\
    bl GetMonData\n\
    movs r1, 0x5\n\
    bl __udivsi3\n\
    adds r3, r0, 0\n\
    lsls r3, 16\n\
    asrs r3, 16\n\
    ldrb r1, [r5, 0xA]\n\
    ldr r0, =sub_81616C0\n\
    str r0, [sp]\n\
    adds r0, r4, 0\n\
    movs r2, 0x1\n\
    bl sub_81B1F18\n\
    add sp, 0x4\n\
    pop {r4,r5}\n\
    pop {r0}\n\
    bx r0\n\
    .pool\n\
    .syntax divided\n");

}
#endif


