#include "global.h"
#include "string_util.h"
#include "party_menu.h"
#include "species.h"
#include "task.h"
#include "field_message_box.h"
#include "strings.h"
#include "rom_818CFC8.h"
#include "battle_frontier_2.h"
#include "pokenav.h"
#include "event_data.h"
#include "script.h"
#include "fldeff_80F9BCC.h"

static bool32 sub_80F9568(struct Pokemon *pokemon)
{
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES2);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
    {
        return FALSE;
    }
    return TRUE;
}

static bool32 sub_80F958C(void)
{
    int i;
    struct Pokemon *pokemon;

    for (pokemon = gPlayerParty, i = 0; i < PARTY_SIZE; i++, pokemon++)
    {
        if (sub_80F9568(pokemon) && GetMonData(pokemon, MON_DATA_HP) != 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

static void sub_80F95C0(u8 partyIdx)
{
    struct Pokemon *pokemon;
    unsigned status;

    pokemon = &gPlayerParty[partyIdx];
    status = 0;
    AdjustFriendship(pokemon, 0x07);
    SetMonData(pokemon, MON_DATA_STATUS, &status);
    GetMonData(pokemon, MON_DATA_NICKNAME, gStringVar1);
    StringGetEnd10(gStringVar1);
}

static bool32 sub_80F960C(u8 partyIdx)
{
    struct Pokemon *pokemon;

    pokemon = &gPlayerParty[partyIdx];
    if (sub_80F9568(pokemon) && GetMonData(pokemon, MON_DATA_HP) == 0 && pokemon_ailments_get_primary(GetMonData(pokemon, MON_DATA_STATUS)) == 1)
    {
        return TRUE;
    }
    return FALSE;
}

static void sub_80F9654(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[0])
    {
        case 0:
            for (; data[1] < PARTY_SIZE; data[1]++)
            {
                if (sub_80F960C(data[1]))
                {
                    sub_80F95C0(data[1]);
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
            if (sub_80F958C())
            {
                if (InBattlePyramid() | InBattlePike() || sub_81D5C18())
                {
                    gSpecialVar_Result = 2;
                }
                else
                {
                    gSpecialVar_Result = 1;
                }
            }
            else
            {
                gSpecialVar_Result = 0;
            }
            EnableBothScriptContexts();
            DestroyTask(taskId);
            break;
    }
}

void sub_80F972C(void)
{
    CreateTask(sub_80F9654, 80);
    ScriptContext1_Stop();
}

unsigned overworld_poison(void)
{
    int i;
    unsigned cnt1;
    unsigned cnt2;
    unsigned hp;
    struct Pokemon *pokemon;

    pokemon = gPlayerParty;
    cnt2 = 0;
    cnt1 = 0;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(pokemon, MON_DATA_SANITY_BIT2) && pokemon_ailments_get_primary(GetMonData(pokemon, MON_DATA_STATUS)) == 1)
        {
            hp = GetMonData(pokemon, MON_DATA_HP);
            if (hp == 0 || --hp == 0)
            {
                cnt1++;
            }
            SetMonData(pokemon, MON_DATA_HP, &hp);
            cnt2++;
        }
        pokemon++;
    }
    if (cnt1 != 0 || cnt2 != 0)
    {
        overworld_poison_effect();
    }
    if (cnt1 != 0)
    {
        return 2;
    }
    if (cnt2 != 0)
    {
        return 1;
    }
    return 0;
}
