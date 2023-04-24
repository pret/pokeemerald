#include "global.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_effect.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "fieldmap.h"
#include "party_menu.h"
#include "fldeff.h"

EWRAM_DATA static bool8 sIsRegisteelPuzzle = 0;

static const u8 sRegicePathCoords[][2] =
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

static void Task_SealedChamberShakingEffect(u8);
static void DoBrailleRegirockEffect(void);
static void DoBrailleRegisteelEffect(void);

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
    MapGridSetMetatileIdAt( 9 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(10 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt( 9 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomLeft | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(10 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomRight | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_BRAILLE_DIG);
    UnlockPlayerFieldControls();
}

bool8 CheckRelicanthWailord(void)
{
    // Emerald change: why did they flip it?
    // First comes Wailord
    if (GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_WAILORD)
    {
        CalculatePlayerPartyCount();
        // Last comes Relicanth
        if (GetMonData(&gPlayerParty[gPlayerPartyCount - 1], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_RELICANTH)
            return TRUE;
    }
    return FALSE;
}

// THEORY: this was caused by block commenting out all of the older R/S braille functions but leaving the call to it itself, which creates the nullsub.
void ShouldDoBrailleRegirockEffectOld(void)
{
}

#define tDelayCounter  data[1]
#define tShakeCounter  data[2]
#define tVerticalPan   data[4]
#define tDelay         data[5]
#define tNumShakes     data[6]

void DoSealedChamberShakingEffect_Long(void)
{
    u8 taskId = CreateTask(Task_SealedChamberShakingEffect, 9);

    gTasks[taskId].tDelayCounter = 0;
    gTasks[taskId].tShakeCounter = 0;
    gTasks[taskId].tVerticalPan = 2;
    gTasks[taskId].tDelay = 5;
    gTasks[taskId].tNumShakes = 50;
    SetCameraPanningCallback(0);
}

void DoSealedChamberShakingEffect_Short(void)
{
    u8 taskId = CreateTask(Task_SealedChamberShakingEffect, 9);

    gTasks[taskId].tDelayCounter = 0;
    gTasks[taskId].tShakeCounter = 0;
    gTasks[taskId].tVerticalPan = 3;
    gTasks[taskId].tDelay = 5;
    gTasks[taskId].tNumShakes = 2;
    SetCameraPanningCallback(0);
}

static void Task_SealedChamberShakingEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->tDelayCounter++;
    if (task->tDelayCounter % task->tDelay == 0)
    {
        task->tDelayCounter = 0;
        task->tShakeCounter++;
        task->tVerticalPan = -task->tVerticalPan;
        SetCameraPanning(0, task->tVerticalPan);
        if (task->tShakeCounter == task->tNumShakes)
        {
            DestroyTask(taskId);
            ScriptContext_Enable();
            InstallCameraPanAheadCallback();
        }
    }
}

#undef tDelayCounter
#undef tShakeCounter
#undef tVerticalPan
#undef tDelay
#undef tNumShakes

bool8 ShouldDoBrailleRegirockEffect(void)
{
    if (!FlagGet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED)
        && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(DESERT_RUINS)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(DESERT_RUINS))
    {
        if (gSaveBlock1Ptr->pos.x == 6 && gSaveBlock1Ptr->pos.y == 23)
        {
            sIsRegisteelPuzzle = FALSE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 5 && gSaveBlock1Ptr->pos.y == 23)
        {
            sIsRegisteelPuzzle = FALSE;
            return TRUE;
        }
        else if (gSaveBlock1Ptr->pos.x == 7 && gSaveBlock1Ptr->pos.y == 23)
        {
            sIsRegisteelPuzzle = FALSE;
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

static void DoBrailleRegirockEffect(void)
{
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomLeft | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomRight | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGIROCK_PUZZLE_COMPLETED);
    UnlockPlayerFieldControls();
}

bool8 ShouldDoBrailleRegisteelEffect(void)
{
    if (!FlagGet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED) && (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ANCIENT_TOMB) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ANCIENT_TOMB)))
    {
        if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 25)
        {
            sIsRegisteelPuzzle = TRUE;
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

static void DoBrailleRegisteelEffect(void)
{
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopLeft);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 19 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_TopRight);
    MapGridSetMetatileIdAt(7 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomLeft | MAPGRID_COLLISION_MASK);
    MapGridSetMetatileIdAt(8 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomMid);
    MapGridSetMetatileIdAt(9 + MAP_OFFSET, 20 + MAP_OFFSET, METATILE_Cave_SealedChamberEntrance_BottomRight | MAPGRID_COLLISION_MASK);
    DrawWholeMapView();
    PlaySE(SE_BANG);
    FlagSet(FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED);
    UnlockPlayerFieldControls();
}

// theory: another commented out DoBrailleWait and Task_BrailleWait.
static void DoBrailleWait(void)
{
}

// this used to be FldEff_UseFlyAncientTomb . why did GF merge the 2 functions?
bool8 FldEff_UsePuzzleEffect(void)
{
    u8 taskId = CreateFieldMoveTask();

    if (sIsRegisteelPuzzle == TRUE)
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

        for (i = 0; i < ARRAY_COUNT(sRegicePathCoords); i++)
        {
            u8 xPos = sRegicePathCoords[i][0];
            u8 yPos = sRegicePathCoords[i][1];
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
