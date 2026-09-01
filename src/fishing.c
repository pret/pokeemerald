#include "global.h"
#include "main.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "random.h"
#include "script.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "wild_encounter.h"
#include "config/fishing.h"

static void Task_Fishing(u8);
static bool32 Fishing_Init(struct Task *);
static bool32 Fishing_GetRodOut(struct Task *);
static bool32 Fishing_WaitBeforeDots(struct Task *);
static bool32 Fishing_InitDots(struct Task *);
static bool32 Fishing_ShowDots(struct Task *);
static bool32 Fishing_CheckForBite(struct Task *);
static bool32 Fishing_GotBite(struct Task *);
static bool32 Fishing_ChangeMinigame(struct Task *);
static bool32 Fishing_WaitForA(struct Task *);
static bool32 Fishing_APressNoMinigame(struct Task *);
static bool32 Fishing_CheckMoreDots(struct Task *);
static bool32 Fishing_MonOnHook(struct Task *);
static bool32 Fishing_StartEncounter(struct Task *);
static bool32 Fishing_NotEvenNibble(struct Task *);
static bool32 Fishing_GotAway(struct Task *);
static bool32 Fishing_NoMon(struct Task *);
static bool32 Fishing_PutRodAway(struct Task *);
static bool32 Fishing_EndNoMon(struct Task *);
static void AlignFishingAnimationFrames(void);
static bool32 DoesFishingMinigameAllowCancel(void);
static bool32 Fishing_DoesFirstMonInPartyHaveSuctionCupsOrStickyHold(void);
static bool32 Fishing_RollForBite(u32, bool32);
static u32 CalculateFishingBiteOdds(u32, bool32);
static u32 CalculateFishingFollowerBoost(void);
static u32 CalculateFishingProximityBoost(void);
static u32 CalculateFishingTimeOfDayBoost(void);

#define FISHING_PROXIMITY_BOOST 20     //Active if config I_FISHING_PROXIMITY is TRUE
#define FISHING_TIME_OF_DAY_BOOST 20   //Active if config I_FISHING_TIME_OF_DAY_BOOST is TRUE
#define FISHING_GEN3_STICKY_CHANCE 85  //Active if config I_FISHING_STICKY_BOOST is set to GEN_3 or lower

#if I_FISHING_BITE_ODDS >= GEN_4
    #define FISHING_OLD_ROD_ODDS 25
    #define FISHING_GOOD_ROD_ODDS 50
    #define FISHING_SUPER_ROD_ODDS 75
#elif I_FISHING_BITE_ODDS >= GEN_3
    #define FISHING_OLD_ROD_ODDS 50
    #define FISHING_GOOD_ROD_ODDS 50
    #define FISHING_SUPER_ROD_ODDS 50
#else
    #define FISHING_OLD_ROD_ODDS 100
    #define FISHING_GOOD_ROD_ODDS 33
    #define FISHING_SUPER_ROD_ODDS 50
#endif

static const u8 sText_OhABite[] = _("Oh! A bite!");
static const u8 sText_PokemonOnHook[] = _("A POKéMON's on the hook!{PAUSE_UNTIL_PRESS}");
static const u8 sText_NotEvenANibble[] = _("Not even a nibble…{PAUSE_UNTIL_PRESS}");
static const u8 sText_ItGotAway[] = _("It got away…{PAUSE_UNTIL_PRESS}");

struct FriendshipHookChanceBoost
{
    u8 threshold;
    u8 bonus;
};

//Needs to be defined in descending order and end with the 0 friendship boost
//Active if config I_FISHING_FOLLOWER_BOOST is TRUE
static const struct FriendshipHookChanceBoost sFriendshipHookChanceBoostArray[] =
{
    {.threshold = 250, .bonus = 50},
    {.threshold = 200, .bonus = 40},
    {.threshold = 150, .bonus = 30},
    {.threshold = 100, .bonus = 20},
    {.threshold =   0, .bonus =  0},
};

#define FISHING_CHAIN_SHINY_STREAK_MAX 20

enum
{
    FISHING_INIT,
    FISHING_GET_ROD_OUT,
    FISHING_WAIT_BEFORE_DOTS,
    FISHING_INIT_DOTS,
    FISHING_SHOW_DOTS,
    FISHING_CHECK_FOR_BITE,
    FISHING_GOT_BITE,
    FISHING_CHANGE_MINIGAME,
    FISHING_WAIT_FOR_A,
    FISHING_A_PRESS_NO_MINIGAME,
    FISHING_CHECK_MORE_DOTS,
    FISHING_MON_ON_HOOK,
    FISHING_START_ENCOUNTER,
    FISHING_NOT_EVEN_NIBBLE,
    FISHING_GOT_AWAY,
    FISHING_NO_MON,
    FISHING_PUT_ROD_AWAY,
    FISHING_END_NO_MON,
};

static bool32 (*const sFishingStateFuncs[])(struct Task *) =
{
    [FISHING_INIT]                  = Fishing_Init,
    [FISHING_GET_ROD_OUT]           = Fishing_GetRodOut,
    [FISHING_WAIT_BEFORE_DOTS]      = Fishing_WaitBeforeDots,
    [FISHING_INIT_DOTS]             = Fishing_InitDots,
    [FISHING_SHOW_DOTS]             = Fishing_ShowDots,
    [FISHING_CHECK_FOR_BITE]        = Fishing_CheckForBite,
    [FISHING_GOT_BITE]              = Fishing_GotBite,
    [FISHING_CHANGE_MINIGAME]       = Fishing_ChangeMinigame,
    [FISHING_WAIT_FOR_A]            = Fishing_WaitForA,
    [FISHING_A_PRESS_NO_MINIGAME]   = Fishing_APressNoMinigame,
    [FISHING_CHECK_MORE_DOTS]       = Fishing_CheckMoreDots,
    [FISHING_MON_ON_HOOK]           = Fishing_MonOnHook,
    [FISHING_START_ENCOUNTER]       = Fishing_StartEncounter,
    [FISHING_NOT_EVEN_NIBBLE]       = Fishing_NotEvenNibble,
    [FISHING_GOT_AWAY]              = Fishing_GotAway,
    [FISHING_NO_MON]                = Fishing_NoMon,
    [FISHING_PUT_ROD_AWAY]          = Fishing_PutRodAway,
    [FISHING_END_NO_MON]            = Fishing_EndNoMon,
};

#define tStep              data[0]
#define tFrameCounter      data[1]
#define tNumDots           data[2]
#define tDotsRequired      data[3]
#define tRoundsPlayed      data[12]
#define tMinRoundsRequired data[13]
#define tPlayerGfxId       data[14]
#define tFishingRod        data[15]

void StartFishing(u8 rod)
{
    u8 taskId = CreateTask(Task_Fishing, 0xFF);

    gTasks[taskId].tFishingRod = rod;
    Task_Fishing(taskId);
}

static void Task_Fishing(u8 taskId)
{
    while (sFishingStateFuncs[gTasks[taskId].tStep](&gTasks[taskId]))
        ;
}

static bool32 Fishing_Init(struct Task *task)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    task->tStep = FISHING_GET_ROD_OUT;
    return FALSE;
}

static bool32 Fishing_GetRodOut(struct Task *task)
{
    struct ObjectEvent *playerObjEvent;
    const s16 minRounds1[] = {
        [OLD_ROD]   = 1,
        [GOOD_ROD]  = 1,
        [SUPER_ROD] = 1
    };
    const s16 minRounds2[] = {
        [OLD_ROD]   = 1,
        [GOOD_ROD]  = 3,
        [SUPER_ROD] = 6
    };

    task->tRoundsPlayed = 0;
    task->tMinRoundsRequired = minRounds1[task->tFishingRod] + (Random() % minRounds2[task->tFishingRod]);
    task->tPlayerGfxId = gObjectEvents[gPlayerAvatar.objectEventId].graphicsId;
    playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    ObjectEventClearHeldMovementIfActive(playerObjEvent);
    playerObjEvent->enableAnim = TRUE;
    SetPlayerAvatarFishing(playerObjEvent->facingDirection);
    task->tStep = FISHING_WAIT_BEFORE_DOTS;
    return FALSE;
}

static bool32 Fishing_WaitBeforeDots(struct Task *task)
{
    AlignFishingAnimationFrames();

    // Wait one second
    task->tFrameCounter++;
    if (task->tFrameCounter >= 60)
        task->tStep = FISHING_INIT_DOTS;
    return FALSE;
}

static bool32 Fishing_InitDots(struct Task *task)
{
    u32 randVal;

    LoadMessageBoxAndFrameGfx(0, TRUE);
    task->tStep = FISHING_SHOW_DOTS;
    task->tFrameCounter = 0;
    task->tNumDots = 0;
    randVal = Random();
    randVal %= 10;
    task->tDotsRequired = randVal + 1;
    if (task->tRoundsPlayed == 0)
        task->tDotsRequired = randVal + 4;
    if (task->tDotsRequired >= 10)
        task->tDotsRequired = 10;
    return TRUE;
}

static bool32 Fishing_ShowDots(struct Task *task)
{
    const u8 dot[] = _("·");

    AlignFishingAnimationFrames();
    task->tFrameCounter++;
    if (JOY_NEW(A_BUTTON))
    {
        if (!DoesFishingMinigameAllowCancel())
            return FALSE;

        task->tStep = FISHING_NOT_EVEN_NIBBLE;
        if (task->tRoundsPlayed != 0)
            task->tStep = FISHING_GOT_AWAY;
        return TRUE;
    }
    else
    {
        if (task->tFrameCounter >= 20)
        {
            task->tFrameCounter = 0;
            if (task->tNumDots >= task->tDotsRequired)
            {
                task->tStep = FISHING_CHECK_FOR_BITE;
                if (task->tRoundsPlayed != 0)
                    task->tStep = FISHING_GOT_BITE;
                task->tRoundsPlayed++;
            }
            else
            {
                AddTextPrinterParameterized(0, FONT_NORMAL, dot, task->tNumDots * 8, 1, 0, NULL);
                task->tNumDots++;
            }
        }
        return FALSE;
    }
}

static bool32 Fishing_CheckForBite(struct Task *task)
{
    bool32 bite, firstMonHasSuctionOrSticky;

    AlignFishingAnimationFrames();
    task->tStep = FISHING_GOT_BITE;
    bite = FALSE;

    if (!DoesCurrentMapHaveFishingMons())
    {
        task->tStep = FISHING_NOT_EVEN_NIBBLE;
        return TRUE;
    }

    firstMonHasSuctionOrSticky = Fishing_DoesFirstMonInPartyHaveSuctionCupsOrStickyHold();

    if (firstMonHasSuctionOrSticky && I_FISHING_STICKY_BOOST < GEN_4)
        bite = RandomPercentage(RNG_FISHING_GEN3_STICKY, FISHING_GEN3_STICKY_CHANCE);

    if (!bite)
        bite = Fishing_RollForBite(task->tFishingRod, firstMonHasSuctionOrSticky);

    if (!bite)
        task->tStep = FISHING_NOT_EVEN_NIBBLE;

    if (bite)
        StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingBiteDirectionAnimNum(GetPlayerFacingDirection()));

    return TRUE;
}

static bool32 Fishing_GotBite(struct Task *task)
{
    AlignFishingAnimationFrames();
    AddTextPrinterParameterized(0, FONT_NORMAL, sText_OhABite, 0, 17, 0, NULL);
    task->tStep = FISHING_CHANGE_MINIGAME;
    task->tFrameCounter = 0;
    return FALSE;
}

static bool32 Fishing_ChangeMinigame(struct Task *task)
{
    switch (I_FISHING_MINIGAME)
    {
    case GEN_1:
    case GEN_2:
        task->tStep = FISHING_A_PRESS_NO_MINIGAME;
        break;
    case GEN_3:
    default:
        task->tStep = FISHING_WAIT_FOR_A;
        break;
    }
    return TRUE;
}

// We have a bite. Now, wait for the player to press A, or the timer to expire.
static bool32 Fishing_WaitForA(struct Task *task)
{
    const s16 reelTimeouts[3] = {
        [OLD_ROD]   = 36,
        [GOOD_ROD]  = 33,
        [SUPER_ROD] = 30
    };

    AlignFishingAnimationFrames();
    task->tFrameCounter++;
    if (task->tFrameCounter >= reelTimeouts[task->tFishingRod])
        task->tStep = FISHING_GOT_AWAY;
    else if (JOY_NEW(A_BUTTON))
        task->tStep = FISHING_CHECK_MORE_DOTS;
    return FALSE;
}

static bool32 Fishing_APressNoMinigame(struct Task *task)
{
    AlignFishingAnimationFrames();
    if (JOY_NEW(A_BUTTON))
        task->tStep = FISHING_MON_ON_HOOK;
    return FALSE;
}

// Determine if we're going to play the dot game again
static bool32 Fishing_CheckMoreDots(struct Task *task)
{
    const s16 moreDotsChance[][2] =
    {
        [OLD_ROD]   = {0, 0},
        [GOOD_ROD]  = {40, 10},
        [SUPER_ROD] = {70, 30}
    };

    AlignFishingAnimationFrames();
    task->tStep = FISHING_MON_ON_HOOK;
    if (task->tRoundsPlayed < task->tMinRoundsRequired)
    {
        task->tStep = FISHING_INIT_DOTS;
    }
    else if (task->tRoundsPlayed < 2)
    {
        // probability of having to play another round
        s16 probability = Random() % 100;

        if (moreDotsChance[task->tFishingRod][task->tRoundsPlayed] > probability)
            task->tStep = FISHING_INIT_DOTS;
    }
    return FALSE;
}

static bool32 Fishing_MonOnHook(struct Task *task)
{
    AlignFishingAnimationFrames();
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, FONT_NORMAL, sText_PokemonOnHook, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    task->tStep = FISHING_START_ENCOUNTER;
    task->tFrameCounter = 0;
    return FALSE;
}

static bool32 Fishing_StartEncounter(struct Task *task)
{
    if (task->tFrameCounter == 0)
        AlignFishingAnimationFrames();

    RunTextPrinters();

    if (task->tFrameCounter == 0)
    {
        if (!IsTextPrinterActiveOnWindow(0))
        {
            struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

            ObjectEventSetGraphicsId(playerObjEvent, task->tPlayerGfxId);
            ObjectEventTurn(playerObjEvent, playerObjEvent->movementDirection);
            if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
                SetSurfBlob_PlayerOffset(gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId, FALSE, 0);
            gSprites[gPlayerAvatar.spriteId].x2 = 0;
            gSprites[gPlayerAvatar.spriteId].y2 = 0;
            ClearDialogWindowAndFrame(0, TRUE);
            task->tFrameCounter++;
            return FALSE;
        }
    }

    if (task->tFrameCounter != 0)
    {
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        FishingWildEncounter(task->tFishingRod);
        RecordFishingAttemptForTV(TRUE);
        DestroyTask(FindTaskIdByFunc(Task_Fishing));
    }
    return FALSE;
}

static bool32 Fishing_NotEvenNibble(struct Task *task)
{
    gChainFishingDexNavStreak = 0;
    AlignFishingAnimationFrames();
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingNoCatchDirectionAnimNum(GetPlayerFacingDirection()));
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, FONT_NORMAL, sText_NotEvenANibble, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    task->tStep = FISHING_NO_MON;
    return TRUE;
}

static bool32 Fishing_GotAway(struct Task *task)
{
    gChainFishingDexNavStreak = 0;
    AlignFishingAnimationFrames();
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingNoCatchDirectionAnimNum(GetPlayerFacingDirection()));
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, FONT_NORMAL, sText_ItGotAway, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    task->tStep = FISHING_NO_MON;
    return TRUE;
}

static bool32 Fishing_NoMon(struct Task *task)
{
    AlignFishingAnimationFrames();
    task->tStep = FISHING_PUT_ROD_AWAY;
    return FALSE;
}

static bool32 Fishing_PutRodAway(struct Task *task)
{
    AlignFishingAnimationFrames();
    if (gSprites[gPlayerAvatar.spriteId].animEnded)
    {
        struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

        ObjectEventSetGraphicsId(playerObjEvent, task->tPlayerGfxId);
        ObjectEventTurn(playerObjEvent, playerObjEvent->movementDirection);
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
            SetSurfBlob_PlayerOffset(gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId, FALSE, 0);
        gSprites[gPlayerAvatar.spriteId].x2 = 0;
        gSprites[gPlayerAvatar.spriteId].y2 = 0;
        task->tStep = FISHING_END_NO_MON;
    }
    return FALSE;
}

static bool32 Fishing_EndNoMon(struct Task *task)
{
    RunTextPrinters();
    if (!IsTextPrinterActiveOnWindow(0))
    {
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        ClearDialogWindowAndFrame(0, TRUE);
        RecordFishingAttemptForTV(FALSE);
        DestroyTask(FindTaskIdByFunc(Task_Fishing));
    }
    return FALSE;
}

static bool32 DoesFishingMinigameAllowCancel(void)
{
    switch (I_FISHING_MINIGAME)
    {
    case GEN_1:
    case GEN_2:
        return FALSE;
    case GEN_3:
    default:
            return TRUE;
    }
}

static bool32 Fishing_DoesFirstMonInPartyHaveSuctionCupsOrStickyHold(void)
{
    enum Ability ability;

    if (GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SANITY_IS_EGG))
        return FALSE;

    ability = GetMonAbility(&gParties[B_TRAINER_PLAYER][0]);

    return (ability == ABILITY_SUCTION_CUPS || ability == ABILITY_STICKY_HOLD);
}

static bool32 Fishing_RollForBite(u32 rod, bool32 isStickyHold)
{
    return ((RandomUniform(RNG_FISHING_BITE, 1, 100)) <= CalculateFishingBiteOdds(rod, isStickyHold));
}

static u32 CalculateFishingBiteOdds(u32 rod, bool32 isStickyHold)
{
    u32 odds;

    if (rod == OLD_ROD)
        odds = FISHING_OLD_ROD_ODDS;
    if (rod == GOOD_ROD)
        odds = FISHING_GOOD_ROD_ODDS;
    if (rod == SUPER_ROD)
        odds = FISHING_SUPER_ROD_ODDS;

    odds += CalculateFishingFollowerBoost();
    odds += CalculateFishingProximityBoost();
    odds += CalculateFishingTimeOfDayBoost();

    if (isStickyHold && I_FISHING_STICKY_BOOST >= GEN_4)
        odds *= 2;

    odds = min(100, odds);
    return odds;
}

static u32 CalculateFishingFollowerBoost()
{
    u32 friendship;
    struct Pokemon *mon = GetFirstLiveMon();

    if (!I_FISHING_FOLLOWER_BOOST || !mon)
        return 0;

    friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    for (u32 i = 0;; i++)
    {
        if (friendship >= sFriendshipHookChanceBoostArray[i].threshold)
            return sFriendshipHookChanceBoostArray[i].bonus;
    }
}

static u32 CalculateFishingProximityBoost()
{
    s16 bobber_x, bobber_y, tile_x, tile_y;
    enum Direction direction, facingDirection;
    u32 numQualifyingTile = 0;
    struct ObjectEvent *objectEvent;

    if (!I_FISHING_PROXIMITY)
        return 0;

    objectEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    bobber_x = objectEvent->currentCoords.x;
    bobber_y = objectEvent->currentCoords.y;

    facingDirection = GetPlayerFacingDirection();
    MoveCoords(facingDirection, &bobber_x, &bobber_y);

    numQualifyingTile = 0;
    for (direction = DIR_SOUTH; direction < CARDINAL_DIRECTION_COUNT; direction++)
    {
        tile_x = bobber_x;
        tile_y = bobber_y;
        MoveCoords(direction, &tile_x, &tile_y);
        if (tile_x == objectEvent->currentCoords.x && tile_y == objectEvent->currentCoords.y)
            continue;
        if (!MetatileBehavior_IsSurfableFishableWater(MapGridGetMetatileBehaviorAt(tile_x, tile_y)))
            numQualifyingTile++;
        else if (MapGridGetCollisionAt(tile_x, tile_y))
            numQualifyingTile++;
        else if (GetMapBorderIdAt(tile_x, tile_y) == CONNECTION_INVALID)
            numQualifyingTile++;
    }

    return (numQualifyingTile * FISHING_PROXIMITY_BOOST);
}

static u32 CalculateFishingTimeOfDayBoost()
{
    if (!I_FISHING_TIME_OF_DAY_BOOST)
        return 0;

    enum TimeOfDay timeOfDay = GetTimeOfDay();
    if (timeOfDay == TIME_MORNING || timeOfDay == TIME_EVENING)
        return FISHING_TIME_OF_DAY_BOOST;
    return 0;
}

#undef tStep
#undef tFrameCounter
#undef tNumDots
#undef tDotsRequired
#undef tRoundsPlayed
#undef tMinRoundsRequired
#undef tPlayerGfxId
#undef tFishingRod

static void AlignFishingAnimationFrames(void)
{
    struct Sprite *playerSprite = &gSprites[gPlayerAvatar.spriteId];
    u8 animCmdIndex;
    u8 animType;

    AnimateSprite(playerSprite);
    playerSprite->x2 = 0;
    playerSprite->y2 = 0;
    animCmdIndex = playerSprite->animCmdIndex;
    if (playerSprite->anims[playerSprite->animNum][animCmdIndex].type == -1)
    {
        animCmdIndex--;
    }
    else
    {
        playerSprite->animDelayCounter++;
        if (playerSprite->anims[playerSprite->animNum][animCmdIndex].type == -1)
            animCmdIndex--;
    }
    animType = playerSprite->anims[playerSprite->animNum][animCmdIndex].type;
    if (animType == 1 || animType == 2 || animType == 3)
    {
        playerSprite->x2 = 8;
        if (GetPlayerFacingDirection() == 3)
            playerSprite->x2 = -8;
    }
    if (animType == 5)
        playerSprite->y2 = -8;
    if (animType == 10 || animType == 11)
        playerSprite->y2 = 8;
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
        SetSurfBlob_PlayerOffset(gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId, TRUE, playerSprite->y2);
}

void UpdateChainFishingStreak()
{
    if (!I_FISHING_CHAIN)
        return;

    if (gChainFishingDexNavStreak == MAX_u8)
        return;

    gChainFishingDexNavStreak++;
}

u32 CalculateChainFishingShinyRolls(void)
{
    if (!I_FISHING_CHAIN || !gIsFishingEncounter)
        return 0;
    u32 a = 2 * min(gChainFishingDexNavStreak, FISHING_CHAIN_SHINY_STREAK_MAX);
    return a;
}

bool32 ShouldUseFishingEnvironmentInBattle()
{
    return (I_FISHING_ENVIRONMENT >= GEN_4 && gIsFishingEncounter);
}
