#include "global.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/field_effects.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "fieldmap.h"
#include "party_menu.h"
#include "fldeff.h"

// why do this, GF?
enum
{
    REGIROCK_PUZZLE,
    REGISTEEL_PUZZLE
};

EWRAM_DATA static u8 sBraillePuzzleCallbackFlag = 0;

static const u8 gRegicePathCoords[][2] =
{
    {4,  21},
    {5,  21},
    {6,  21},
    {7,  21},
    {8,  21},
    {9,  21},
    {10, 21},
    {11, 21},
    {12, 21},
    {12, 22},
    {12, 23},
    {13, 23},
    {13, 24},
    {13, 25},
    {13, 26},
    {13, 27},
    {12, 27},
    {12, 28},
    {4,  29},
    {5,  29},
    {6,  29},
    {7,  29},
    {8,  29},
    {9,  29},
    {10, 29},
    {11, 29},
    {12, 29},
    {4,  28},
    {4,  27},
    {3,  27},
    {3,  26},
    {3,  25},
    {3,  24},
    {3,  23},
    {4,  23},
    {4,  22},
};

void SealedChamberShakingEffect(u8);
void DoBrailleRegirockEffect(void);
void DoBrailleRegisteelEffect(void);

bool8 ShouldDoBrailleDigEffect(void)
{
    if (!FlagGet(FLAG_SYS_BRAILLE_DIG)
     && (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SEALED_CHAMBER_OUTER_ROOM)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(SEALED_CHAMBER_OUTER_ROOM)))
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
    MapGridSetMetatileIdAt(16, 8, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(17, 8, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(18, 8, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(16, 9, METATILE_Cave_SealedChamberEntrance_BottomLeft | METATILE_COLLISION_MASK);
    MapGridSetMetatileIdAt(17, 9, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(18, 9, METATILE_Cave_SealedChamberEntrance_BottomRight | METATILE_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
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
void ShouldDoBrailleRegirockEffectOld(void)
{
    /*
        if (!FlagGet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED) && (gSaveBlock1.location.mapGroup == MAP_GROUP_DESERT_RUINS && gSaveBlock1.location.mapNum == MAP_ID_DESERT_RUINS))
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

void DoBrailleRegirockEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_STRENGTH);
    MapGridSetMetatileIdAt(14, 26, 554);
    MapGridSetMetatileIdAt(15, 26, 555);
    MapGridSetMetatileIdAt(16, 26, 556);
    MapGridSetMetatileIdAt(14, 27, 3634);
    MapGridSetMetatileIdAt(15, 27, 563);
    MapGridSetMetatileIdAt(16, 27, 3636);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED);
    ScriptContext2_Disable();
}

bool8 ShouldDoBrailleRegisteelEffect(void)
{
    if (!FlagGet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED) && (gSaveBlock1.location.mapGroup == MAP_GROUP_ANCIENT_TOMB && gSaveBlock1.location.mapNum == MAP_ID_ANCIENT_TOMB))
    {
        if (gSaveBlock1.pos.x == 8 && gSaveBlock1.pos.y == 25)
            return TRUE;
    }

    return FALSE;
}

void DoBrailleRegisteelEffect(void)
{
    gFieldEffectArguments[0] = gLastFieldPokeMenuOpened;
    FieldEffectStart(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
}

bool8 FldEff_UseFlyAncientTomb(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)UseRegisteelHm_Callback >> 16;
    gTasks[taskId].data[9] = (u32)UseRegisteelHm_Callback;
    return FALSE;
}

void UseRegisteelHm_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
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
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED);
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
bool8 ShouldDoBrailleRegirockEffect(void)
{
    if (!FlagGet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED)
        && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(DESERT_RUINS)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(DESERT_RUINS))
    {
        if (gSaveBlock1Ptr->pos.x == 6 && gSaveBlock1Ptr->pos.y == 23)
        {
            sBraillePuzzleCallbackFlag = REGIROCK_PUZZLE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 5 && gSaveBlock1Ptr->pos.y == 23)
        {
            sBraillePuzzleCallbackFlag = REGIROCK_PUZZLE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 7 && gSaveBlock1Ptr->pos.y == 23)
        {
            sBraillePuzzleCallbackFlag = REGIROCK_PUZZLE;
            return TRUE;
        }
    }

    return FALSE;
}

void SetUpPuzzleEffectRegirock(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
}

void UseRegirockHm_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
    DoBrailleRegirockEffect();
}

void DoBrailleRegirockEffect(void)
{
    MapGridSetMetatileIdAt(14, 26, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(15, 26, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(16, 26, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(14, 27, METATILE_Cave_SealedChamberEntrance_BottomLeft | METATILE_COLLISION_MASK);
    MapGridSetMetatileIdAt(15, 27, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(16, 27, METATILE_Cave_SealedChamberEntrance_BottomRight | METATILE_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED);
    ScriptContext2_Disable();
}

bool8 ShouldDoBrailleRegisteelEffect(void)
{
    if (!FlagGet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED) && (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ANCIENT_TOMB) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ANCIENT_TOMB)))
    {
        if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 25)
        {
            sBraillePuzzleCallbackFlag = REGISTEEL_PUZZLE;
            return TRUE;
        }
    }
    return FALSE;
}

void SetUpPuzzleEffectRegisteel(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
}

void UseRegisteelHm_Callback(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_TOMB_PUZZLE_EFFECT);
    DoBrailleRegisteelEffect();
}

void DoBrailleRegisteelEffect(void)
{
    MapGridSetMetatileIdAt(14, 26, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(15, 26, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(16, 26, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(14, 27, METATILE_Cave_SealedChamberEntrance_BottomLeft | METATILE_COLLISION_MASK);
    MapGridSetMetatileIdAt(15, 27, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(16, 27, METATILE_Cave_SealedChamberEntrance_BottomRight | METATILE_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED);
    ScriptContext2_Disable();
}

// theory: another commented out DoBrailleWait and Task_BrailleWait.
void DoBrailleWait(void)
{
    /*
    if (!FlagGet(FLAG_SYS_BRAILLE_REGICE_COMPLETED))
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
    u8 taskId = CreateFieldMoveTask();

    if (sBraillePuzzleCallbackFlag == REGISTEEL_PUZZLE)
    {
        gTasks[taskId].data[8] = (u32)UseRegisteelHm_Callback >> 16;
        gTasks[taskId].data[9] = (u32)UseRegisteelHm_Callback;
    }
    else
    {
        gTasks[taskId].data[8] = (u32)UseRegirockHm_Callback >> 16;
        gTasks[taskId].data[9] = (u32)UseRegirockHm_Callback;
    }
    return FALSE;
}

bool8 ShouldDoBrailleRegicePuzzle(void)
{
    u8 i;

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ISLAND_CAVE)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ISLAND_CAVE))
    {
        if (FlagGet(FLAG_SYS_BRAILLE_REGICE_COMPLETED))
            return FALSE;
        if (FlagGet(FLAG_TEMP_2) == FALSE)
            return FALSE;
        if (FlagGet(FLAG_TEMP_3) == TRUE)
            return FALSE;

        for (i = 0; i < 36; i++)
        {
            u8 xPos = gRegicePathCoords[i][0];
            u8 yPos = gRegicePathCoords[i][1];
            if (gSaveBlock1Ptr->pos.x == xPos && gSaveBlock1Ptr->pos.y == yPos)
            {
                u16 varValue;

                if (i < 16)
                {
                    u16 val = VarGet(VAR_REGICE_STEPS_1);
                    val |= 1 << i;
                    VarSet(VAR_REGICE_STEPS_1, val);
                }
                else if (i < 32)
                {
                    u16 val = VarGet(VAR_REGICE_STEPS_2);
                    val |= 1 << (i - 16);
                    VarSet(VAR_REGICE_STEPS_2, val);
                }
                else
                {
                    u16 val = VarGet(VAR_REGICE_STEPS_3);
                    val |= 1 << (i - 32);
                    VarSet(VAR_REGICE_STEPS_3, val);
                }

                varValue = VarGet(VAR_REGICE_STEPS_1);
                if (varValue != 0xFFFF || VarGet(VAR_REGICE_STEPS_2) != 0xFFFF || VarGet(VAR_REGICE_STEPS_3) != 0xF)
                    return FALSE;

                // This final check is redundant.
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
