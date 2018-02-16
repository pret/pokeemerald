#include "global.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "event_data.h"
#include "fldeff_groundshake.h"
#include "malloc.h"
#include "menu.h"
#include "party_menu.h"
#include "pokemon.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"

bool8 sub_81BE66C(void)
{
    if (!(gSaveBlock1Ptr->location.mapGroup == 0x0 && gSaveBlock1Ptr->location.mapNum == 0x1A))
        return 0;
    return FlagGet(FLAG_0x14E);
}

void sub_81BE698(u8 taskId)
{
    sub_8151E50(&(gUnknown_0203CF18->unk4));
}

void sub_81BE6AC(void)
{
    gUnknown_0203CF18 = NULL;
}

void sub_81BE6B8(void)
{
    if(gUnknown_0203CF18 != NULL)
    {
        gUnknown_0203CF18 = NULL;
        return;
    }
    if(!(gSaveBlock1Ptr->location.mapGroup == 0x0 && gSaveBlock1Ptr->location.mapNum == 0x1A) || !FlagGet(FLAG_0x14E))
        return;

    gUnknown_0203CF18 = (struct Struct203CF18 *)AllocZeroed(sizeof(struct Struct203CF18));
    sub_8151B3C(&(gUnknown_0203CF18->unk4));
    sub_8151B68(&(gUnknown_0203CF18->unk4), gUnknown_08617E18);
    sub_8151CA8(&(gUnknown_0203CF18->unk4), 1, 1);
    gUnknown_0203CF18->taskId = CreateTask(sub_81BE698, 0xFF);
}

void sub_81BE72C(void)
{
    if(!(gSaveBlock1Ptr->location.mapGroup == 0x0 && gSaveBlock1Ptr->location.mapNum == 0x1A) || !FlagGet(FLAG_0x14E) || gUnknown_0203CF18 == NULL)
        return;
    if(FuncIsActiveTask(sub_81BE698))
        DestroyTask(gUnknown_0203CF18->taskId);
    sub_8151D28(&(gUnknown_0203CF18->unk4), 1, 1);
    sub_8151C50(&(gUnknown_0203CF18->unk4), 1, 1);
    Free(gUnknown_0203CF18);
    gUnknown_0203CF18 = NULL;
}

void sub_81BE79C(void)
{
    u16 rand;
    bool8 chance;

    if(VarGet(VAR_0x40CB) != 0)
    {
        FlagClear(FLAG_0x14E);
        return;
    }
    rand = Random();
    chance = rand & 1;
    if(FlagGet(FLAG_0x09D) == TRUE)
        chance = TRUE;
    if(chance)
    {
        FlagSet(FLAG_0x14E);
        sub_81BE6B8();
        return;
    }
    FlagClear(FLAG_0x14E);
}

