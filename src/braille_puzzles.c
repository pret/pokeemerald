#include "global.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/species.h"

extern void MapGridSetMetatileIdAt(s32 x, s32 y, u16 metatileId); // fieldmap
extern u8 GetCursorSelectionMonId(void);
extern u8 oei_task_add(void);

// why do this, GF?
enum
{
    STRENGTH_PUZZLE,
    FLY_PUZZLE
};

EWRAM_DATA static u8 sBraillePuzzleCallbackFlag = 0;

static const u8 gUnknown_085EFE74[][2] =
{
    {0x04, 0x15},
    {0x05, 0x15},
    {0x06, 0x15},
    {0x07, 0x15},
    {0x08, 0x15},
    {0x09, 0x15},
    {0x0a, 0x15},
    {0x0b, 0x15},
    {0x0c, 0x15},
    {0x0c, 0x16},
    {0x0c, 0x17},
    {0x0d, 0x17},
    {0x0d, 0x18},
    {0x0d, 0x19},
    {0x0d, 0x1a},
    {0x0d, 0x1b},
    {0x0c, 0x1b},
    {0x0c, 0x1c},
    {0x04, 0x1d},
    {0x05, 0x1d},
    {0x06, 0x1d},
    {0x07, 0x1d},
    {0x08, 0x1d},
    {0x09, 0x1d},
    {0x0a, 0x1d},
    {0x0b, 0x1d},
    {0x0c, 0x1d},
    {0x04, 0x1c},
    {0x04, 0x1b},
    {0x03, 0x1b},
    {0x03, 0x1a},
    {0x03, 0x19},
    {0x03, 0x18},
    {0x03, 0x17},
    {0x04, 0x17},
    {0x04, 0x16},
};

void SealedChamberShakingEffect(u8);
void sub_8179860(void);
void sub_8179944(void);

bool8 ShouldDoBrailleDigEffect(void)
{
    if (!FlagGet(FLAG_SYS_BRAILLE_DIG)
     && (gSaveBlock1Ptr->location.mapGroup == 0x18
     && gSaveBlock1Ptr->location.mapNum == 0x47))
    {
        if (gSaveBlock1Ptr->pos.x == 10 && gSaveBlock1Ptr->pos.y == 3)
            return TRUE;
        if (gSaveBlock1Ptr->pos.x == 9 && gSaveBlock1Ptr->pos.y == 3)
            return TRUE;
        if (gSaveBlock1Ptr->pos.x == 11 && gSaveBlock1Ptr->pos.y == 3)
            return TRUE;
    }

    return FALSE;
}

void DoBrailleDigEffect(void)
{
    MapGridSetMetatileIdAt(16, 8, 554);
    MapGridSetMetatileIdAt(17, 8, 555);
    MapGridSetMetatileIdAt(18, 8, 556);
    MapGridSetMetatileIdAt(16, 9, 3634);
    MapGridSetMetatileIdAt(17, 9, 563);
    MapGridSetMetatileIdAt(18, 9, 3636);
    DrawWholeMapView();
    PlaySE(SE_BAN);
    FlagSet(FLAG_SYS_BRAILLE_DIG);
    ScriptContext2_Disable();
}

bool8 CheckRelicanthWailord(void)
{
    // Emerald change: why did they flip it?
    // First comes Wailord
    if (GetMonData(&gPlayerParty[0], MON_DATA_SPECIES2, 0) == SPECIES_WAILORD)
    {
        CalculatePlayerPartyCount();
        // Last comes Relicanth
        if (GetMonData(&gPlayerParty[gPlayerPartyCount - 1], MON_DATA_SPECIES2, 0) == SPECIES_RELICANTH)
            return TRUE;
    }
    return FALSE;
}

// THEORY: this was caused by block commenting out all of the older R/S braille functions but leaving the call to it itself, which creates the nullsub.
// the code is shown below to show what this might look like.
void ShouldDoBrailleStrengthEffectOld(void)
{
    /*
        if (!FlagGet(FLAG_SYS_BRAILLE_STRENGTH) && (gSaveBlock1.location.mapGroup == MAP_GROUP_DESERT_RUINS && gSaveBlock1.location.mapNum == MAP_ID_DESERT_RUINS))
    {
        if (gSaveBlock1.pos.x == 10 && gSaveBlock1.pos.y == 23)
            return TRUE;
        else if (gSaveBlock1.pos.x == 9 && gSaveBlock1.pos.y == 23)
            return TRUE;
        else if (gSaveBlock1.pos.x == 11 && gSaveBlock1.pos.y == 23)
            return TRUE;
    }

    return FALSE;
}

void DoBrailleStrengthEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_STRENGTH);
    MapGridSetMetatileIdAt(14, 26, 554);
    MapGridSetMetatileIdAt(15, 26, 555);
    MapGridSetMetatileIdAt(16, 26, 556);
    MapGridSetMetatileIdAt(14, 27, 3634);
    MapGridSetMetatileIdAt(15, 27, 563);
    MapGridSetMetatileIdAt(16, 27, 3636);
    DrawWholeMapView();
    PlaySE(SE_BAN);
    FlagSet(FLAG_SYS_BRAILLE_STRENGTH);
    ScriptContext2_Disable();
}

bool8 ShouldDoBrailleFlyEffect(void)
{
    if (!FlagGet(FLAG_SYS_BRAILLE_FLY) && (gSaveBlock1.location.mapGroup == MAP_GROUP_ANCIENT_TOMB && gSaveBlock1.location.mapNum == MAP_ID_ANCIENT_TOMB))
    {
        if (gSaveBlock1.pos.x == 8 && gSaveBlock1.pos.y == 25)
            return TRUE;
    }

    return FALSE;
}

void DoBrailleFlyEffect(void)
{
    gFieldEffectArguments[0] = gLastFieldPokeMenuOpened;
    FieldEffectStart(FLDEFF_USE_FLY_ANCIENT_TOMB);
}

bool8 FldEff_UseFlyAncientTomb(void)
{
    u8 taskId = oei_task_add();

    gTasks[taskId].data[8] = (u32)UseFlyAncientTomb_Callback >> 16;
    gTasks[taskId].data[9] = (u32)UseFlyAncientTomb_Callback;
    return FALSE;
}

void UseFlyAncientTomb_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_FLY_ANCIENT_TOMB);
    UseFlyAncientTomb_Finish();
}

void UseFlyAncientTomb_Finish(void)
{
    MapGridSetMetatileIdAt(14, 26, 554);
    MapGridSetMetatileIdAt(15, 26, 555);
    MapGridSetMetatileIdAt(16, 26, 556);
    MapGridSetMetatileIdAt(14, 27, 3634);
    MapGridSetMetatileIdAt(15, 27, 563);
    MapGridSetMetatileIdAt(16, 27, 3636);
    DrawWholeMapView();
    PlaySE(SE_BAN);
    FlagSet(FLAG_SYS_BRAILLE_FLY);
    ScriptContext2_Disable();
}
    */
}

void DoSealedChamberShakingEffect1(void)
{
    u8 taskId = CreateTask(SealedChamberShakingEffect, 9);

    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[4] = 2;
    gTasks[taskId].data[5] = 5;
    gTasks[taskId].data[6] = 50;
    SetCameraPanningCallback(0);
}

void DoSealedChamberShakingEffect2(void)
{
    u8 taskId = CreateTask(SealedChamberShakingEffect, 9);

    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].data[4] = 3;
    gTasks[taskId].data[5] = 5;
    gTasks[taskId].data[6] = 2;
    SetCameraPanningCallback(0);
}

void SealedChamberShakingEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[1]++;

    if (!(task->data[1] % task->data[5]))
    {
        task->data[1] = 0;
        task->data[2]++;
        task->data[4] = -task->data[4];
        SetCameraPanning(0, task->data[4]);
        if (task->data[2] == task->data[6])
        {
            DestroyTask(taskId);
            EnableBothScriptContexts();
            InstallCameraPanAheadCallback();
        }
    }
}

// moved later in the function because it was rewritten.
bool8 ShouldDoBrailleStrengthEffect(void)
{
    if (!FlagGet(FLAG_SYS_BRAILLE_STRENGTH)
        && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(DESERT_RUINS)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(DESERT_RUINS))
    {
        if (gSaveBlock1Ptr->pos.x == 6 && gSaveBlock1Ptr->pos.y == 23)
        {
            sBraillePuzzleCallbackFlag = STRENGTH_PUZZLE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 5 && gSaveBlock1Ptr->pos.y == 23)
        {
            sBraillePuzzleCallbackFlag = STRENGTH_PUZZLE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 7 && gSaveBlock1Ptr->pos.y == 23)
        {
            sBraillePuzzleCallbackFlag = STRENGTH_PUZZLE;
            return TRUE;
        }
    }

    return FALSE;
}

void sub_8179834(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_FLY_ANCIENT_TOMB);
}

void UseStrengthDesertRuins_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_FLY_ANCIENT_TOMB);
    sub_8179860();
}

void sub_8179860(void)
{
    MapGridSetMetatileIdAt(14, 26, 554);
    MapGridSetMetatileIdAt(15, 26, 555);
    MapGridSetMetatileIdAt(16, 26, 556);
    MapGridSetMetatileIdAt(14, 27, 3634);
    MapGridSetMetatileIdAt(15, 27, 563);
    MapGridSetMetatileIdAt(16, 27, 3636);
    DrawWholeMapView();
    PlaySE(SE_BAN);
    FlagSet(FLAG_SYS_BRAILLE_STRENGTH);
    ScriptContext2_Disable();
}

bool8 ShouldDoBrailleFlyEffect(void)
{
    if (!FlagGet(FLAG_SYS_BRAILLE_FLY) && (gSaveBlock1Ptr->location.mapGroup == 0x18 && gSaveBlock1Ptr->location.mapNum == 0x44))
    {
        if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 25)
            { sBraillePuzzleCallbackFlag = FLY_PUZZLE; return TRUE; }
    }
    return FALSE;
}

void sub_8179918(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_FLY_ANCIENT_TOMB);
}

void UseFlyAncientTomb_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_FLY_ANCIENT_TOMB);
    sub_8179944();
}

void sub_8179944(void)
{
    MapGridSetMetatileIdAt(14, 26, 554);
    MapGridSetMetatileIdAt(15, 26, 555);
    MapGridSetMetatileIdAt(16, 26, 556);
    MapGridSetMetatileIdAt(14, 27, 3634);
    MapGridSetMetatileIdAt(15, 27, 563);
    MapGridSetMetatileIdAt(16, 27, 3636);
    DrawWholeMapView();
    PlaySE(SE_BAN);
    FlagSet(FLAG_SYS_BRAILLE_FLY);
    ScriptContext2_Disable();
}

// theory: another commented out DoBrailleWait and Task_BrailleWait.
void DoBrailleWait(void)
{
    /*
    if (!FlagGet(FLAG_SYS_BRAILLE_WAIT))
        CreateTask(Task_BrailleWait, 0x50);
}

void Task_BrailleWait(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        data[1] = 7200;
        data[0] = 1;
        break;
    case 1:
        if (BrailleWait_CheckButtonPress() != FALSE)
        {
            MenuZeroFillScreen();
            PlaySE(SE_SELECT);
            data[0] = 2;
        }
        else
        {
            data[1] = data[1] - 1;
            if (data[1] == 0)
            {
                MenuZeroFillScreen();
                data[0] = 3;
                data[1] = 30;
            }
        }
        break;
    case 2:
        if (BrailleWait_CheckButtonPress() == FALSE)
        {
            data[1] = data[1] - 1;
            if (data[1] == 0)
                data[0] = 4;
            break;
        }
        sub_8064E2C();
        DestroyTask(taskId);
        ScriptContext2_Disable();
        break;
    case 3:
        data[1] = data[1] - 1;
        if (data[1] == 0)
            data[0] = 4;
        break;
    case 4:
        sub_8064E2C();
        ScriptContext1_SetupScript(S_OpenRegiceChamber);
        DestroyTask(taskId);
        break;
    }
}

bool32 BrailleWait_CheckButtonPress(void)
{
    u16 keyMask = A_BUTTON | B_BUTTON | START_BUTTON | SELECT_BUTTON | DPAD_ANY;

    if (gSaveBlock2.optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        keyMask |= L_BUTTON | R_BUTTON;
    if (gSaveBlock2.optionsButtonMode == OPTIONS_BUTTON_MODE_L_EQUALS_A)
        keyMask |= L_BUTTON;

    if (gMain.newKeys & keyMask)
        return TRUE;
    else
        return FALSE;
    */
}

// this used to be FldEff_UseFlyAncientTomb . why did GF merge the 2 functions?
bool8 FldEff_UsePuzzleEffect(void)
{
    u8 taskId = oei_task_add();

    if (sBraillePuzzleCallbackFlag == FLY_PUZZLE)
    {
        gTasks[taskId].data[8] = (u32)UseFlyAncientTomb_Callback >> 16;
        gTasks[taskId].data[9] = (u32)UseFlyAncientTomb_Callback;
    }
    else
    {
        gTasks[taskId].data[8] = (u32)UseStrengthDesertRuins_Callback >> 16;
        gTasks[taskId].data[9] = (u32)UseStrengthDesertRuins_Callback;
    }
    return FALSE;
}

bool8 ShouldDoBrailleRegicePuzzle(void)
{
    u8 i;

    if (gSaveBlock1Ptr->location.mapGroup == 0x18
        && gSaveBlock1Ptr->location.mapNum == 0x43)
    {
        if (FlagGet(FLAG_SYS_BRAILLE_WAIT) != FALSE)
            return FALSE;
        if (FlagGet(FLAG_TEMP_2) == FALSE)
            return FALSE;
        if (FlagGet(FLAG_TEMP_3) == TRUE)
            return FALSE;

        for (i = 0; i < 36; i++)
        {
            u8 xPos = gUnknown_085EFE74[i][0];
            u8 yPos = gUnknown_085EFE74[i][1];
            if (gSaveBlock1Ptr->pos.x == xPos && gSaveBlock1Ptr->pos.y == yPos)
            {
                u16 varValue;

                if (i < 16)
                {
                    u16 val = VarGet(VAR_0x403B);
                    val |= 1 << i;
                    VarSet(VAR_0x403B, val);
                }
                else if (i < 32)
                {
                    u16 val = VarGet(VAR_0x403C);
                    val |= 1 << (i - 16);
                    VarSet(VAR_0x403C, val);
                }
                else
                {
                    u16 val = VarGet(VAR_0x403D);
                    val |= 1 << (i - 32);
                    VarSet(VAR_0x403D, val);
                }

                varValue = VarGet(VAR_0x403B);
                if (varValue != 0xFFFF || VarGet(VAR_0x403C) != varValue || VarGet(VAR_0x403D) != 0xF)
                    return FALSE;

                if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 21)
                    return TRUE;
                else
                    return FALSE;
            }
        }

        FlagSet(FLAG_TEMP_3);
        FlagClear(FLAG_TEMP_2);
    }

    return FALSE;
}
