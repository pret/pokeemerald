#include "global.h"
#include "battle.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "field_message_box.h"
#include "field_poison.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "party_menu.h"
#include "pokenav.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trainer_hill.h"
#include "constants/field_poison.h"
#include "constants/party_menu.h"

static bool32 IsMonValidSpecies(struct Pokemon *pokemon)
{
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES2);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
    {
        return FALSE;
    }
    return TRUE;
}

static bool32 AllMonsFainted(void)
{
    int i;
    struct Pokemon *pokemon = gPlayerParty;

    for (i = 0; i < PARTY_SIZE; i++, pokemon++)
    {
        if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) != 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

static void FaintFromFieldPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = gPlayerParty + partyIdx;
    u32 status = STATUS1_NONE;

    AdjustFriendship(pokemon, FRIENDSHIP_EVENT_FAINT_FIELD_PSN);
    SetMonData(pokemon, MON_DATA_STATUS, &status);
    GetMonData(pokemon, MON_DATA_NICKNAME, gStringVar1);
    StringGetEnd10(gStringVar1);
}

static bool32 MonFaintedFromPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = gPlayerParty + partyIdx;
    if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) == 0 && GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
    {
        return TRUE;
    }
    return FALSE;
}

static void Task_TryFieldPoisonWhiteOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
        case 0:
            for (; data[1] < PARTY_SIZE; data[1]++)
            {
                if (MonFaintedFromPoison(data[1]))
                {
                    FaintFromFieldPoison(data[1]);
                    ShowFieldMessage(gText_PkmnFainted3);
                    data[0]++;
                    return;
                }
            }
            data[0] = 2;
            break;
        case 1:
            if (IsFieldMessageBoxHidden())
            {
                data[0]--;
            }
            break;
        case 2:
            if (AllMonsFainted())
            {
                if (InBattlePyramid() | InBattlePike() || InTrainerHillChallenge())
                {
                    gSpecialVar_Result = FLDPSN_FRONTIER_WHITEOUT;
                }
                else
                {
                    gSpecialVar_Result = FLDPSN_WHITEOUT;
                }
            }
            else
            {
                gSpecialVar_Result = FLDPSN_NO_WHITEOUT;
            }
            EnableBothScriptContexts();
            DestroyTask(taskId);
            break;
    }
}

void TryFieldPoisonWhiteOut(void)
{
    CreateTask(Task_TryFieldPoisonWhiteOut, 80);
    ScriptContext1_Stop();
}

s32 DoPoisonFieldEffect(void)
{
    int i;
    u32 hp;
    struct Pokemon *pokemon = gPlayerParty;
    u32 numPoisoned = 0;
    u32 numFainted = 0;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
        {
            hp = GetMonData(pokemon, MON_DATA_HP);
            if (hp == 0 || --hp == 0)
            {
                numFainted++;
            }
            SetMonData(pokemon, MON_DATA_HP, &hp);
            numPoisoned++;
        }
        pokemon++;
    }
    if (numFainted != 0 || numPoisoned != 0)
    {
        FldEffPoison_Start();
    }
    if (numFainted != 0)
    {
        return FLDPSN_FNT;
    }
    if (numPoisoned != 0)
    {
        return FLDPSN_PSN;
    }
    return FLDPSN_NONE;
}
