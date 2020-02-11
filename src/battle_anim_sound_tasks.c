#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "contest.h"
#include "m4a.h"
#include "sound.h"
#include "task.h"
#include "constants/battle_anim.h"
#include "constants/species.h"

extern struct MusicPlayerInfo gMPlayInfo_SE1;

// this file's functions
static void sub_8158B98(u8 taskId);
static void sub_8158C04(u8 taskId);
static void sub_8158D08(u8 taskId);
static void sub_8158FF4(u8 taskId);
static void sub_815913C(u8 taskId);
static void sub_8159308(u8 taskId);
static void AnimTask_SeVolumeChange(u8 taskId);

// task start
void sub_8158B30(u8 taskId)
{
    s8 pan1, pan2, panIncrement;

    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[1] = gBattleAnimArgs[1];

    pan1 = BattleAnimAdjustPanning(SOUND_PAN_ATTACKER);
    pan2 = BattleAnimAdjustPanning(SOUND_PAN_TARGET);
    panIncrement = CalculatePanIncrement(pan1, pan2, 2);

    gTasks[taskId].data[2] = pan1;
    gTasks[taskId].data[3] = pan2;
    gTasks[taskId].data[4] = panIncrement;
    gTasks[taskId].data[10] = 10;

    gTasks[taskId].func = sub_8158B98;
}

static void sub_8158B98(u8 taskId)
{
    s16 pan = gTasks[taskId].data[2];
    s8 panIncrement = gTasks[taskId].data[4];
    if (++gTasks[taskId].data[11] == 111)
    {
        gTasks[taskId].data[10] = 5;
        gTasks[taskId].data[11] = 0;
        gTasks[taskId].func = sub_8158C04;
    }
    else
    {
        if (++gTasks[taskId].data[10] == 11)
        {
            gTasks[taskId].data[10] = 0;
            PlaySE12WithPanning(gTasks[taskId].data[0], pan);
        }
        pan += panIncrement;
        gTasks[taskId].data[2] = KeepPanInRange(pan, panIncrement);
    }
}

static void sub_8158C04(u8 taskId)
{
    if (++gTasks[taskId].data[10] == 6)
    {
        s8 pan;

        gTasks[taskId].data[10] = 0;
        pan = BattleAnimAdjustPanning(SOUND_PAN_TARGET);
        PlaySE12WithPanning(gTasks[taskId].data[1], pan);
        if (++gTasks[taskId].data[11] == 2)
            DestroyAnimSoundTask(taskId);
    }
}
// task end

// task start
void sub_8158C58(u8 taskId)
{
    u16 songId = gBattleAnimArgs[0];
    s8 targetPan = gBattleAnimArgs[2];
    s8 panIncrement = gBattleAnimArgs[3];
    u8 r10 = gBattleAnimArgs[4];
    u8 r7 = gBattleAnimArgs[5];
    u8 r9 = gBattleAnimArgs[6];
    s8 sourcePan = BattleAnimAdjustPanning(gBattleAnimArgs[1]);

    targetPan = BattleAnimAdjustPanning(targetPan);
    panIncrement = CalculatePanIncrement(sourcePan, targetPan, panIncrement);

    gTasks[taskId].data[0] = songId;
    gTasks[taskId].data[1] = sourcePan;
    gTasks[taskId].data[2] = targetPan;
    gTasks[taskId].data[3] = panIncrement;
    gTasks[taskId].data[4] = r10;
    gTasks[taskId].data[5] = r7;
    gTasks[taskId].data[6] = r9;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].data[11] = sourcePan;
    gTasks[taskId].data[12] = r9;

    gTasks[taskId].func = sub_8158D08;
    sub_8158D08(taskId);
}

static void sub_8158D08(u8 taskId)
{
    if (gTasks[taskId].data[12]++ == gTasks[taskId].data[6])
    {
        gTasks[taskId].data[12] = 0;
        PlaySE12WithPanning(gTasks[taskId].data[0], gTasks[taskId].data[11]);
        if (--gTasks[taskId].data[4] == 0)
        {
            DestroyAnimSoundTask(taskId);
            return;
        }
    }

    if (gTasks[taskId].data[10]++ == gTasks[taskId].data[5])
    {
        u16 dPan, oldPan;
        gTasks[taskId].data[10] = 0;
        dPan = gTasks[taskId].data[3];
        oldPan = gTasks[taskId].data[11] ;
        gTasks[taskId].data[11] = dPan + oldPan;
        gTasks[taskId].data[11] = KeepPanInRange(gTasks[taskId].data[11], oldPan);
    }
}
// task end

// task start
void sub_8158D8C(u8 taskId)
{
    u16 species = 0;
    s8 pan = BattleAnimAdjustPanning(SOUND_PAN_ATTACKER);
    if (IsContest())
    {
        if (gBattleAnimArgs[0] == ANIM_ATTACKER)
            species = gContestResources->field_18->species;
        else
            DestroyAnimVisualTask(taskId); // UB: function should return upon destroying task.
    }
    else
    {
        u8 battlerId;

        // Get wanted battler.
        if (gBattleAnimArgs[0] == ANIM_ATTACKER)
            battlerId = gBattleAnimAttacker;
        else if (gBattleAnimArgs[0] == ANIM_TARGET)
            battlerId = gBattleAnimTarget;
        else if (gBattleAnimArgs[0] == ANIM_ATK_PARTNER)
            battlerId = BATTLE_PARTNER(gBattleAnimAttacker);
        else
            battlerId = BATTLE_PARTNER(gBattleAnimTarget);

        // Check if battler is visible.
        if ((gBattleAnimArgs[0] == ANIM_TARGET || gBattleAnimArgs[0] == ANIM_DEF_PARTNER) && !IsBattlerSpriteVisible(battlerId))
        {
            DestroyAnimVisualTask(taskId);
            return;
        }

        if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
            species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
        else
            species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
    }

    if (species != SPECIES_NONE)
        PlayCry3(species, pan, 3);

    DestroyAnimVisualTask(taskId);
}
// task end

// task start
void sub_8158E9C(u8 taskId)
{
    u16 species = 0;
    s8 pan = BattleAnimAdjustPanning(SOUND_PAN_ATTACKER);
    if (IsContest())
    {
        if (gBattleAnimArgs[0] == ANIM_ATTACKER)
            species = gContestResources->field_18->species;
        else
            DestroyAnimVisualTask(taskId); // UB: function should return upon destroying task.
    }
    else
    {
        u8 battlerId;

        // Get wanted battler.
        if (gBattleAnimArgs[0] == ANIM_ATTACKER)
            battlerId = gBattleAnimAttacker;
        else if (gBattleAnimArgs[0] == ANIM_TARGET)
            battlerId = gBattleAnimTarget;
        else if (gBattleAnimArgs[0] == ANIM_ATK_PARTNER)
            battlerId = BATTLE_PARTNER(gBattleAnimAttacker);
        else
            battlerId = BATTLE_PARTNER(gBattleAnimTarget);

        // Check if battler is visible.
        if ((gBattleAnimArgs[0] == ANIM_TARGET || gBattleAnimArgs[0] == ANIM_DEF_PARTNER) && !IsBattlerSpriteVisible(battlerId))
        {
            DestroyAnimVisualTask(taskId);
            return;
        }

        if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
            species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
        else
            species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES);
    }

    gTasks[taskId].data[0] = gBattleAnimArgs[1];
    gTasks[taskId].data[1] = species;
    gTasks[taskId].data[2] = pan;

    if (species != SPECIES_NONE)
    {
        if (gBattleAnimArgs[1] == 0xFF)
            PlayCry3(species, pan, 9);
        else
            PlayCry3(species, pan, 7);

        gTasks[taskId].func = sub_8158FF4;
    }
    else
    {
        DestroyAnimVisualTask(taskId);
    }
}

static void sub_8158FF4(u8 taskId)
{
    u16 species = gTasks[taskId].data[1];
    s8 pan = gTasks[taskId].data[2];

    if (gTasks[taskId].data[9] < 2)
    {
        gTasks[taskId].data[9]++;
    }
    else
    {
        if (gTasks[taskId].data[0] == 0xFF)
        {
            if (!IsCryPlaying())
            {
                PlayCry3(species, pan, 10);
                DestroyAnimVisualTask(taskId);
            }
        }
        else
        {
            if (!IsCryPlaying())
            {
                PlayCry3(species, pan, 8);
                DestroyAnimVisualTask(taskId);
            }
        }
    }
}
// task end

void sub_8159078(u8 taskId)
{
    if (gTasks[taskId].data[9] < 2)
    {
        gTasks[taskId].data[9]++;
    }
    else
    {
        if (!IsCryPlaying())
            DestroyAnimVisualTask(taskId);
    }
}

// task start
void sub_81590B8(u8 taskId)
{
    u16 species;
    s8 pan;

    gTasks[taskId].data[10] = gBattleAnimArgs[0];
    pan = BattleAnimAdjustPanning(SOUND_PAN_ATTACKER);

    if (IsContest())
        species = gContestResources->field_18->species;
    else
        species = gAnimBattlerSpecies[gBattleAnimAttacker];

    gTasks[taskId].data[1] = species;
    gTasks[taskId].data[2] = pan;

    if (species != SPECIES_NONE)
        gTasks[taskId].func = sub_815913C;
    else
        DestroyAnimVisualTask(taskId);
}

static void sub_815913C(u8 taskId)
{
    u16 species = gTasks[taskId].data[1];
    s8 pan = gTasks[taskId].data[2];

    switch (gTasks[taskId].data[9])
    {
    case 2:
        PlayCry6(species, pan, 4);
        gTasks[taskId].data[9]++;
        break;
    case 1:
    case 3:
    case 4:
        gTasks[taskId].data[9]++;
        break;
    case 5:
        if (IsCryPlaying())
            break;
    case 0:
        StopCryAndClearCrySongs();
        gTasks[taskId].data[9]++;
        break;
    default:
        if (gTasks[taskId].data[10] == 0)
            PlayCry6(species, pan, 6);
        else
            PlayCry3(species, pan, 6);

        DestroyAnimVisualTask(taskId);
        break;
    }
}
// task end

void sub_8159210(u8 taskId)
{
    u16 songId = gBattleAnimArgs[0];
    s8 pan = BattleAnimAdjustPanning(gBattleAnimArgs[1]);

    PlaySE1WithPanning(songId, pan);
    DestroyAnimVisualTask(taskId);
}

void sub_8159244(u8 taskId)
{
    u16 songId = gBattleAnimArgs[0];
    s8 pan = BattleAnimAdjustPanning(gBattleAnimArgs[1]);

    PlaySE2WithPanning(songId, pan);
    DestroyAnimVisualTask(taskId);
}

void sub_8159278(u8 taskId)
{
    s8 targetPan = gBattleAnimArgs[1];
    s8 panIncrement = gBattleAnimArgs[2];
    u16 r9 = gBattleAnimArgs[3];
    s8 sourcePan = BattleAnimAdjustPanning(gBattleAnimArgs[0]);

    targetPan = BattleAnimAdjustPanning(targetPan);
    panIncrement = CalculatePanIncrement(sourcePan, targetPan, panIncrement);

    gTasks[taskId].data[1] = sourcePan;
    gTasks[taskId].data[2] = targetPan;
    gTasks[taskId].data[3] = panIncrement;
    gTasks[taskId].data[5] = r9;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].data[11] = sourcePan;

    gTasks[taskId].func = sub_8159308;
    sub_8159308(taskId);
}

void sub_8159308(u8 taskId)
{
    u16 panIncrement = gTasks[taskId].data[3];

    if (gTasks[taskId].data[10]++ == gTasks[taskId].data[5])
    {
        u16 oldPan;
        gTasks[taskId].data[10] = 0;
        oldPan = gTasks[taskId].data[11];
        gTasks[taskId].data[11] = panIncrement + oldPan;
        gTasks[taskId].data[11] = KeepPanInRange(gTasks[taskId].data[11], oldPan);
    }

    gUnknown_02038440 = gTasks[taskId].data[11];
    if (gTasks[taskId].data[11] == gTasks[taskId].data[2])
        DestroyAnimVisualTask(taskId);
}

#define tSongNum        data[0]
#define tPan            data[1]
#define tCurrentVolume  data[2]
#define tIncrementVal   data[3]
#define tTargetVolume   data[4]
#define tDelay          data[5]
#define tFrameCounter   data[6]
#define tInitialVolume  data[7]

void AnimTask_PlaySeChangingVolume(u8 taskId)
{
    gTasks[taskId].tSongNum = gBattleAnimArgs[0];
    gTasks[taskId].tPan = BattleAnimAdjustPanning(gBattleAnimArgs[1]);
    gTasks[taskId].tCurrentVolume = gTasks[taskId].tInitialVolume = gBattleAnimArgs[2];
    gTasks[taskId].tIncrementVal = gBattleAnimArgs[3];
    gTasks[taskId].tTargetVolume = gBattleAnimArgs[4];
    gTasks[taskId].tDelay = gBattleAnimArgs[5];

    PlaySE1WithPanning(gTasks[taskId].tSongNum, gTasks[taskId].tPan);
    m4aMPlayVolumeControl(&gMPlayInfo_SE1, 0xFFFF, gTasks[taskId].tCurrentVolume);
    if (gTasks[taskId].tIncrementVal == 0) // Either increase or decrease volume.
        DestroyAnimSoundTask(taskId);
    else
        gTasks[taskId].func = AnimTask_SeVolumeChange;
}

static void AnimTask_SeVolumeChange(u8 taskId)
{
    bool32 destroyTask = FALSE;

    if (gTasks[taskId].tFrameCounter++ >= gTasks[taskId].tDelay)
    {
        gTasks[taskId].tFrameCounter = 0;
        gTasks[taskId].tCurrentVolume += gTasks[taskId].tIncrementVal;

        if (gTasks[taskId].tCurrentVolume < 0)
            gTasks[taskId].tCurrentVolume = 0;
        if (gTasks[taskId].tCurrentVolume > 256)
            gTasks[taskId].tCurrentVolume = 256;

        if (gTasks[taskId].tInitialVolume < gTasks[taskId].tTargetVolume) // Volume increasing.
        {
            if (gTasks[taskId].tCurrentVolume >= gTasks[taskId].tTargetVolume) // Target reached.
                destroyTask = TRUE;
        }
        else // Volume decreasing.
        {
            if (gTasks[taskId].tCurrentVolume <= gTasks[taskId].tTargetVolume) // Target reached.
                destroyTask = TRUE;
        }

        if (destroyTask)
            DestroyAnimSoundTask(taskId);

        m4aMPlayVolumeControl(&gMPlayInfo_SE1, 0xFFFF, gTasks[taskId].tCurrentVolume);
    }
}

