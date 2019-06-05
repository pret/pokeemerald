#include "global.h"
#include "menu.h"
#include "party_menu.h"
#include "pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/songs.h"

static void sub_816166C(u8 taskId);
static void sub_81616C0(u8 taskId);
static void sub_8161724(u8 taskId);
static void sub_81617B8(u8 taskId);

bool8 SetUpFieldMove_SoftBoiled(void)
{
    u16 maxHp;
    u16 hp;
    u16 minHp;

    maxHp = GetMonData(&gPlayerParty[GetCursorSelectionMonId()], MON_DATA_MAX_HP);
    hp = GetMonData(&gPlayerParty[GetCursorSelectionMonId()], MON_DATA_HP);

    minHp = (maxHp / 5);
    if (hp > minHp)
        return TRUE;
    return FALSE;
}

void sub_8161560(u8 taskId)
{
    gUnknown_0203CEC8.unkB = 0xA;
    gUnknown_0203CEC8.unkA =  gUnknown_0203CEC8.slotId;
    sub_81B0FCC(GetCursorSelectionMonId(), 0x1);
    display_pokemon_menu_message(0x5);
    gTasks[taskId].func = sub_81B1370;
}

void sub_81615A8(u8 taskId)
{
    u16 hp;

    u8 slotId = gUnknown_0203CEC8.slotId;
    u8 pokemonIndex = gUnknown_0203CEC8.unkA;
    if(pokemonIndex > 6)
    {
        gUnknown_0203CEC8.unkB = 0;
        display_pokemon_menu_message(0x0);
        gTasks[taskId].func = sub_81B1370;
        return;
    }

    hp = GetMonData(&gPlayerParty[pokemonIndex], MON_DATA_HP);
    if(hp == 0 || slotId == pokemonIndex || GetMonData(&gPlayerParty[pokemonIndex], MON_DATA_MAX_HP) == hp)
    {
        sub_81617B8(taskId);
        return;
    }

    PlaySE(SE_KAIFUKU);
    sub_81B1F18(taskId, slotId, -1, GetMonData(&gPlayerParty[slotId], MON_DATA_MAX_HP)/5, sub_816166C);
}

static void sub_816166C(u8 taskId)
{
    PlaySE(SE_KAIFUKU);
    sub_81B1F18(taskId, gUnknown_0203CEC8.unkA, 1, GetMonData(&gPlayerParty[gUnknown_0203CEC8.slotId], MON_DATA_MAX_HP)/5, sub_81616C0);
}

static void sub_81616C0(u8 taskId)
{
    GetMonNickname(&gPlayerParty[gUnknown_0203CEC8.unkA], gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
    sub_81B1B5C(gStringVar4, 0);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_8161724;
}

static void sub_8161724(u8 taskId)
{
    if(sub_81B1BD4() == 1)
        return;
    gUnknown_0203CEC8.unkB = 0x0;
    sub_81B0FCC(gUnknown_0203CEC8.slotId, 0);
    gUnknown_0203CEC8.slotId = gUnknown_0203CEC8.unkA;
    sub_81B0FCC(gUnknown_0203CEC8.unkA, 1);
    ClearStdWindowAndFrameToTransparent(0x6, FALSE);
    ClearWindowTilemap(0x6);
    display_pokemon_menu_message(0);
    gTasks[taskId].func = sub_81B1370;
}

static void sub_8161784(u8 taskId)
{
    if(sub_81B1BD4() == 1)
        return;
    display_pokemon_menu_message(0x5);
    gTasks[taskId].func = sub_81B1370;
}

static void sub_81617B8(u8 taskId)
{
    PlaySE(SE_SELECT);
    sub_81B1B5C(gText_CantBeUsedOnPkmn, 0);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_8161784;
}
