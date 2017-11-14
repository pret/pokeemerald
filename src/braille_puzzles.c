#include "global.h"
#include "event_data.h"
#include "songs.h"
#include "sound.h"
#include "script.h"
#include "species.h"
#include "task.h"
#include "field_effect.h"
#include "flags.h"

extern void MapGridSetMetatileIdAt(s32 x, s32 y, u16 metatileId); // fieldmap
extern void DrawWholeMapView(); // field_camera
extern void SetCameraPanningCallback(void ( *callback)()); // field_camera
extern void InstallCameraPanAheadCallback(void);
extern void SetCameraPanning(s16 x, s16 y);
extern u8 GetCursorSelectionMonId(void);
extern void FieldEffectActiveListRemove(u8 id); // field_effect
extern u8 oei_task_add(void);

// why do this, GF?
enum
{
    STRENGTH_PUZZLE,
    FLY_PUZZLE
};

extern u8 gBraillePuzzleCallbackFlag;
extern u8 gUnknown_085EFE74[][2];

void SealedChamberShakingEffect(u8);
void sub_8179860(void);
void sub_8179944(void);

bool8 ShouldDoBrailleDigEffect(void)
{
    if (!FlagGet(SYS_BRAILLE_DIG)
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
    FlagSet(SYS_BRAILLE_DIG);
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
        if (!FlagGet(SYS_BRAILLE_STRENGTH) && (gSaveBlock1.location.mapGroup == MAP_GROUP_DESERT_RUINS && gSaveBlock1.location.mapNum == MAP_ID_DESERT_RUINS))
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
    FlagSet(SYS_BRAILLE_STRENGTH);
    ScriptContext2_Disable();
}

bool8 ShouldDoBrailleFlyEffect(void)
{
    if (!FlagGet(SYS_BRAILLE_FLY) && (gSaveBlock1.location.mapGroup == MAP_GROUP_ANCIENT_TOMB && gSaveBlock1.location.mapNum == MAP_ID_ANCIENT_TOMB))
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
    FlagSet(SYS_BRAILLE_FLY);
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
    if (!FlagGet(SYS_BRAILLE_STRENGTH) && (gSaveBlock1Ptr->location.mapGroup == 0x18 && gSaveBlock1Ptr->location.mapNum == 0x06))
    {
        if (gSaveBlock1Ptr->pos.x == 6 && gSaveBlock1Ptr->pos.y == 23)
            { gBraillePuzzleCallbackFlag = STRENGTH_PUZZLE; return TRUE; }
        else if (gSaveBlock1Ptr->pos.x == 5 && gSaveBlock1Ptr->pos.y == 23)
            { gBraillePuzzleCallbackFlag = STRENGTH_PUZZLE; return TRUE; }
        else if (gSaveBlock1Ptr->pos.x == 7 && gSaveBlock1Ptr->pos.y == 23)
            { gBraillePuzzleCallbackFlag = STRENGTH_PUZZLE; return TRUE; }
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
    FlagSet(SYS_BRAILLE_STRENGTH);
    ScriptContext2_Disable();
}

bool8 ShouldDoBrailleFlyEffect(void)
{
    if (!FlagGet(SYS_BRAILLE_FLY) && (gSaveBlock1Ptr->location.mapGroup == 0x18 && gSaveBlock1Ptr->location.mapNum == 0x44))
    {
        if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 25)
            { gBraillePuzzleCallbackFlag = FLY_PUZZLE; return TRUE; }
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
    FlagSet(SYS_BRAILLE_FLY);
    ScriptContext2_Disable();
}

// theory: another commented out DoBrailleWait and Task_BrailleWait.
void DoBrailleWait(void)
{
    /*
    if (!FlagGet(SYS_BRAILLE_WAIT))
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

    if (gBraillePuzzleCallbackFlag == FLY_PUZZLE)
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

// can't get this one to match due to the weird macro-like varsets with strange bitshifting.
// to note: 0x10000 is loaded in, and its obviously supposed to be 1, but i cant get 0x80 << 9 to be loaded in without using it directly.
// maybe there's some way of writing it that works?
#ifdef NONMATCHING
// ShouldDoBrailleRegicePuzzle
bool8 ShouldDoBrailleRegicePuzzle(void)
{
    u8 i;

    if (gSaveBlock1Ptr->location.mapGroup == 0x18 && gSaveBlock1Ptr->location.mapNum == 0x43)
    {
        // _08179A1A
        if (FlagGet(SYS_BRAILLE_WAIT) != FALSE)
            return FALSE;
        if (FlagGet(2) == FALSE)
            return FALSE;
        if (FlagGet(3) == TRUE)
            return FALSE;

        for (i = 0; i < 36; i++)
        {
            if (gSaveBlock1Ptr->pos.x == gUnknown_085EFE74[i][0] && gSaveBlock1Ptr->pos.y == gUnknown_085EFE74[i][1])
            {
                if (i < 16)
                    VarSet(0x403B, (0x10000 << i | VarGet(0x403B) << 16) >> 16); // correct
                else if (i < 32)
                    VarSet(0x403C, (0x10000 << (i - 16) | VarGet(0x403C) << 16) >> 16); // hmm?
                else
                    VarSet(0x403D, (0x10000 << (i - 32) | VarGet(0x403D) << 16) >> 16); // hmm?

                if (VarGet(0x403B) != 0xFFFF || VarGet(0x403C) != 0xFF || VarGet(0x403D) != 0xF)
                    return FALSE;

                if (gSaveBlock1Ptr->pos.x == 8 && gSaveBlock1Ptr->pos.y == 21)
                    return TRUE;
                else
                    return FALSE;
            }
        }
    }
    // TODO: Find what flags 2 and 3 are.
    FlagSet(3);
    FlagClear(2);
    return FALSE;
}
#else
__attribute__((naked))
bool8 ShouldDoBrailleRegicePuzzle(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r9\n\
    mov r6, r8\n\
    push {r6,r7}\n\
    ldr r4, =gSaveBlock1Ptr\n\
    ldr r0, [r4]\n\
    ldrh r1, [r0, 0x4]\n\
    ldr r0, =0x00004318\n\
    cmp r1, r0\n\
    beq _08179A1A\n\
    b _08179B5A\n\
_08179A1A:\n\
    ldr r0, =0x000008b1\n\
    bl FlagGet\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    beq _08179A28\n\
    b _08179B5A\n\
_08179A28:\n\
    movs r0, 0x2\n\
    bl FlagGet\n\
    lsls r0, 24\n\
    cmp r0, 0\n\
    bne _08179A36\n\
    b _08179B5A\n\
_08179A36:\n\
    movs r0, 0x3\n\
    bl FlagGet\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    cmp r0, 0x1\n\
    bne _08179A58\n\
    b _08179B5A\n\
    .pool\n\
_08179A54:\n\
    movs r0, 0x1\n\
    b _08179B5C\n\
_08179A58:\n\
    movs r5, 0\n\
    mov r8, r4\n\
    ldr r4, =gUnknown_085EFE74\n\
    adds r0, r4, 0x1\n\
    mov r12, r0\n\
    ldr r6, =0x0000403b\n\
    ldr r1, =0x0000403c\n\
    mov r9, r1\n\
_08179A68:\n\
    lsls r0, r5, 1\n\
    adds r1, r0, r4\n\
    add r0, r12\n\
    ldrb r3, [r0]\n\
    mov r7, r8\n\
    ldr r2, [r7]\n\
    movs r7, 0\n\
    ldrsh r0, [r2, r7]\n\
    ldrb r1, [r1]\n\
    cmp r0, r1\n\
    bne _08179B44\n\
    movs r1, 0x2\n\
    ldrsh r0, [r2, r1]\n\
    cmp r0, r3\n\
    bne _08179B44\n\
    cmp r5, 0xF\n\
    bhi _08179AB0\n\
    adds r0, r6, 0\n\
    bl VarGet\n\
    lsls r0, 16\n\
    movs r1, 0x80\n\
    lsls r1, 9\n\
    lsls r1, r5\n\
    orrs r1, r0\n\
    lsrs r1, 16\n\
    adds r0, r6, 0\n\
    bl VarSet\n\
    b _08179AF0\n\
    .pool\n\
_08179AB0:\n\
    cmp r5, 0x1F\n\
    bhi _08179AD2\n\
    mov r0, r9\n\
    bl VarGet\n\
    lsls r0, 16\n\
    adds r2, r5, 0\n\
    subs r2, 0x10\n\
    movs r1, 0x80\n\
    lsls r1, 9\n\
    lsls r1, r2\n\
    orrs r1, r0\n\
    lsrs r1, 16\n\
    mov r0, r9\n\
    bl VarSet\n\
    b _08179AF0\n\
_08179AD2:\n\
    ldr r4, =0x0000403d\n\
    adds r0, r4, 0\n\
    bl VarGet\n\
    lsls r0, 16\n\
    adds r2, r5, 0\n\
    subs r2, 0x20\n\
    movs r1, 0x80\n\
    lsls r1, 9\n\
    lsls r1, r2\n\
    orrs r1, r0\n\
    lsrs r1, 16\n\
    adds r0, r4, 0\n\
    bl VarSet\n\
_08179AF0:\n\
    ldr r0, =0x0000403b\n\
    bl VarGet\n\
    lsls r0, 16\n\
    lsrs r4, r0, 16\n\
    ldr r0, =0x0000ffff\n\
    cmp r4, r0\n\
    bne _08179B5A\n\
    ldr r0, =0x0000403c\n\
    bl VarGet\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, r4\n\
    bne _08179B5A\n\
    ldr r0, =0x0000403d\n\
    bl VarGet\n\
    lsls r0, 16\n\
    lsrs r0, 16\n\
    cmp r0, 0xF\n\
    bne _08179B5A\n\
    ldr r0, =gSaveBlock1Ptr\n\
    ldr r0, [r0]\n\
    ldr r1, [r0]\n\
    ldr r0, =0x00150008\n\
    cmp r1, r0\n\
    beq _08179A54\n\
    b _08179B5A\n\
    .pool\n\
_08179B44:\n\
    adds r0, r5, 0x1\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    cmp r5, 0x23\n\
    bls _08179A68\n\
    movs r0, 0x3\n\
    bl FlagSet\n\
    movs r0, 0x2\n\
    bl FlagClear\n\
_08179B5A:\n\
    movs r0, 0\n\
_08179B5C:\n\
    pop {r3,r4}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .syntax divided");
}
#endif
