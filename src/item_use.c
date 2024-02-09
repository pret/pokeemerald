#include "global.h"
#include "item_use.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "berry.h"
#include "berry_powder.h"
#include "bike.h"
#include "coins.h"
#include "data.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fldeff.h"
#include "item.h"
#include "item_menu.h"
#include "item_use.h"
#include "mail.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "vs_seeker.h"
#include "constants/event_bg.h"
#include "constants/event_objects.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/map_types.h"

static void SetUpItemUseCallback(u8);
static void FieldCB_UseItemOnField(void);
static void Task_CallItemUseOnFieldCallback(u8);
static void Task_UseItemfinder(u8);
static void Task_CloseItemfinderMessage(u8);
static void Task_HiddenItemNearby(u8);
static void Task_StandingOnHiddenItem(u8);
static bool8 ItemfinderCheckForHiddenItems(const struct MapEvents *, u8);
static u8 GetDirectionToHiddenItem(s16, s16);
static void PlayerFaceHiddenItem(u8);
static void CheckForHiddenItemsInMapConnection(u8);
static void Task_OpenRegisteredPokeblockCase(u8);
static void Task_AccessPokemonBoxLink(u8);
static void ItemUseOnFieldCB_Bike(u8);
static void ItemUseOnFieldCB_Rod(u8);
static void ItemUseOnFieldCB_Itemfinder(u8);
static void ItemUseOnFieldCB_Berry(u8);
static void ItemUseOnFieldCB_WailmerPailBerry(u8);
static void ItemUseOnFieldCB_WailmerPailSudowoodo(u8);
static bool8 TryToWaterSudowoodo(void);
static void BootUpSoundTMHM(u8);
static void Task_ShowTMHMContainedMessage(u8);
static void UseTMHMYesNo(u8);
static void UseTMHM(u8);
static void Task_StartUseRepel(u8);
static void Task_StartUseLure(u8 taskId);
static void Task_UseRepel(u8);
static void Task_UseLure(u8 taskId);
static void Task_CloseCantUseKeyItemMessage(u8);
static void SetDistanceOfClosestHiddenItem(u8, s16, s16);
static void CB2_OpenPokeblockFromBag(void);
static void ItemUseOnFieldCB_Honey(u8 taskId);
static bool32 IsValidLocationForVsSeeker(void);

// EWRAM variables
EWRAM_DATA static void(*sItemUseOnFieldCB)(u8 taskId) = NULL;

// Below is set TRUE by UseRegisteredKeyItemOnField
#define tUsingRegisteredKeyItem  data[3]

// UB here if an item with type ITEM_USE_MAIL or ITEM_USE_BAG_MENU uses SetUpItemUseCallback
// Never occurs in vanilla, but can occur with improperly created items
static const MainCallback sItemUseCallbacks[] =
{
    [ITEM_USE_PARTY_MENU - 1]       = CB2_ShowPartyMenuForItemUse,
    [ITEM_USE_FIELD - 1]            = CB2_ReturnToField,
    [ITEM_USE_PBLOCK_CASE - 1]      = NULL,
    [ITEM_USE_PARTY_MENU_MOVES - 1] = CB2_ShowPartyMenuForItemUse,
};

static const u8 sClockwiseDirections[] = {DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST};

static const struct YesNoFuncTable sUseTMHMYesNoFuncTable =
{
    .yesFunc = UseTMHM,
    .noFunc = CloseItemMessage,
};

#define tEnigmaBerryType data[4]
static void SetUpItemUseCallback(u8 taskId)
{
    u8 type;
    if (gSpecialVar_ItemId == ITEM_ENIGMA_BERRY_E_READER)
        type = gTasks[taskId].tEnigmaBerryType - 1;
    else
        type = ItemId_GetType(gSpecialVar_ItemId) - 1;
    if (!InBattlePyramid())
    {
        gBagMenu->newScreenCallback = sItemUseCallbacks[type];
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gPyramidBagMenu->newScreenCallback = sItemUseCallbacks[type];
        CloseBattlePyramidBag(taskId);
    }
}

static void SetUpItemUseOnFieldCallback(u8 taskId)
{
    if (gTasks[taskId].tUsingRegisteredKeyItem != TRUE)
    {
        gFieldCallback = FieldCB_UseItemOnField;
        SetUpItemUseCallback(taskId);
    }
    else
        sItemUseOnFieldCB(taskId);
}

static void FieldCB_UseItemOnField(void)
{
    FadeInFromBlack();
    CreateTask(Task_CallItemUseOnFieldCallback, 8);
}

static void Task_CallItemUseOnFieldCallback(u8 taskId)
{
    if (IsWeatherNotFadingIn() == 1)
        sItemUseOnFieldCB(taskId);
}

static void DisplayCannotUseItemMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField, const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    if (!isUsingRegisteredKeyItemOnField)
    {
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, gText_DadsAdvice, Task_CloseBattlePyramidBagMessage);
    }
    else
        DisplayItemMessageOnField(taskId, gStringVar4, Task_CloseCantUseKeyItemMessage);
}

void DisplayDadsAdviceCannotUseItemMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField)
{
    DisplayCannotUseItemMessage(taskId, isUsingRegisteredKeyItemOnField, gText_DadsAdvice);
}

static void DisplayCannotDismountBikeMessage(u8 taskId, bool8 isUsingRegisteredKeyItemOnField)
{
    DisplayCannotUseItemMessage(taskId, isUsingRegisteredKeyItemOnField, gText_CantDismountBike);
}

static void Task_CloseCantUseKeyItemMessage(u8 taskId)
{
    ClearDialogWindowAndFrame(0, TRUE);
    DestroyTask(taskId);
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

u8 CheckIfItemIsTMHMOrEvolutionStone(u16 itemId)
{
    if (ItemId_GetFieldFunc(itemId) == ItemUseOutOfBattle_TMHM)
        return 1;
    else if (ItemId_GetFieldFunc(itemId) == ItemUseOutOfBattle_EvolutionStone)
        return 2;
    else
        return 0;
}

// Mail in the bag menu can't have a message but it can be checked (view the mail background, no message)
static void CB2_CheckMail(void)
{
    struct Mail mail;
    mail.itemId = gSpecialVar_ItemId;
    ReadMail(&mail, CB2_ReturnToBagMenuPocket, FALSE);
}

void ItemUseOutOfBattle_Mail(u8 taskId)
{
    gBagMenu->newScreenCallback = CB2_CheckMail;
    Task_FadeAndCloseBagMenu(taskId);
}

STATIC_ASSERT(I_EXP_SHARE_ITEM < GEN_6 || I_EXP_SHARE_FLAG > TEMP_FLAGS_END, YouNeedToSetAFlagToUseGen6ExpShare);

void ItemUseOutOfBattle_ExpShare(u8 taskId)
{
#if I_EXP_SHARE_ITEM >= GEN_6
    if (IsGen6ExpShareEnabled())
    {
        PlaySE(SE_PC_OFF);
        if (!gTasks[taskId].data[2]) // to account for pressing select in the overworld
            DisplayItemMessageOnField(taskId, gText_ExpShareOff, Task_CloseCantUseKeyItemMessage);
        else
            DisplayItemMessage(taskId, FONT_NORMAL, gText_ExpShareOff, CloseItemMessage);
    }
    else
    {
        PlaySE(SE_EXP_MAX);
        if (!gTasks[taskId].data[2]) // to account for pressing select in the overworld
            DisplayItemMessageOnField(taskId, gText_ExpShareOn, Task_CloseCantUseKeyItemMessage);
        else
            DisplayItemMessage(taskId, FONT_NORMAL, gText_ExpShareOn, CloseItemMessage);
    }
    FlagToggle(I_EXP_SHARE_FLAG);
#else
    DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
#endif
}

void ItemUseOutOfBattle_Bike(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 coordsY;
    s16 coordsX;
    u8 behavior;
    PlayerGetDestCoords(&coordsX, &coordsY);
    behavior = MapGridGetMetatileBehaviorAt(coordsX, coordsY);
    if (FlagGet(FLAG_SYS_CYCLING_ROAD) == TRUE || MetatileBehavior_IsVerticalRail(behavior) == TRUE || MetatileBehavior_IsHorizontalRail(behavior) == TRUE || MetatileBehavior_IsIsolatedVerticalRail(behavior) == TRUE || MetatileBehavior_IsIsolatedHorizontalRail(behavior) == TRUE)
        DisplayCannotDismountBikeMessage(taskId, tUsingRegisteredKeyItem);
    else
    {
        if (Overworld_IsBikingAllowed() == TRUE && IsBikingDisallowedByPlayer() == 0)
        {
            sItemUseOnFieldCB = ItemUseOnFieldCB_Bike;
            SetUpItemUseOnFieldCallback(taskId);
        }
        else
            DisplayDadsAdviceCannotUseItemMessage(taskId, tUsingRegisteredKeyItem);
    }
}

static void ItemUseOnFieldCB_Bike(u8 taskId)
{
    if (ItemId_GetSecondaryId(gSpecialVar_ItemId) == MACH_BIKE)
        GetOnOffBike(PLAYER_AVATAR_FLAG_MACH_BIKE);
    else // ACRO_BIKE
        GetOnOffBike(PLAYER_AVATAR_FLAG_ACRO_BIKE);
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
    DestroyTask(taskId);
}

static bool32 CanFish(void)
{
    s16 x, y;
    u16 tileBehavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (MetatileBehavior_IsWaterfall(tileBehavior))
        return FALSE;

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        return FALSE;

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        if (IsPlayerFacingSurfableFishableWater())
            return TRUE;
    }
    else
    {
        if (MetatileBehavior_IsSurfableWaterOrUnderwater(tileBehavior) && MapGridGetCollisionAt(x, y) == 0)
            return TRUE;
        if (MetatileBehavior_IsBridgeOverWaterNoEdge(tileBehavior) == TRUE)
            return TRUE;
    }

    return FALSE;
}

void ItemUseOutOfBattle_Rod(u8 taskId)
{
    if (CanFish() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_Rod;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
}

static void ItemUseOnFieldCB_Rod(u8 taskId)
{
    StartFishing(ItemId_GetSecondaryId(gSpecialVar_ItemId));
    DestroyTask(taskId);
}

void ItemUseOutOfBattle_Itemfinder(u8 var)
{
    IncrementGameStat(GAME_STAT_USED_ITEMFINDER);
    sItemUseOnFieldCB = ItemUseOnFieldCB_Itemfinder;
    SetUpItemUseOnFieldCallback(var);
}

static void ItemUseOnFieldCB_Itemfinder(u8 taskId)
{
    if (ItemfinderCheckForHiddenItems(gMapHeader.events, taskId) == TRUE)
        gTasks[taskId].func = Task_UseItemfinder;
    else
        DisplayItemMessageOnField(taskId, gText_ItemFinderNothing, Task_CloseItemfinderMessage);
}

// Define itemfinder task data
#define tItemDistanceX    data[0]
#define tItemDistanceY    data[1]
#define tItemFound        data[2]
#define tCounter          data[3] // Used to count delay between beeps and rotations during player spin
#define tItemfinderBeeps  data[4]
#define tFacingDir        data[5]

static void Task_UseItemfinder(u8 taskId)
{
    u8 playerDir;
    u8 playerDirToItem;
    u8 i;
    s16 *data = gTasks[taskId].data;
    if (tCounter == 0)
    {
        if (tItemfinderBeeps == 4)
        {
            playerDirToItem = GetDirectionToHiddenItem(tItemDistanceX, tItemDistanceY);
            if (playerDirToItem != DIR_NONE)
            {
                PlayerFaceHiddenItem(sClockwiseDirections[playerDirToItem - 1]);
                gTasks[taskId].func = Task_HiddenItemNearby;
            }
            else
            {
                // Player is standing on hidden item
                playerDir = GetPlayerFacingDirection();
                for (i = 0; i < ARRAY_COUNT(sClockwiseDirections); i++)
                {
                    if (playerDir == sClockwiseDirections[i])
                        tFacingDir = (i + 1) & 3;
                }
                gTasks[taskId].func = Task_StandingOnHiddenItem;
                tCounter = 0;
                tItemFound = 0;
            }
            return;
        }
        PlaySE(SE_ITEMFINDER);
        tItemfinderBeeps++;
    }
    tCounter = (tCounter + 1) & 0x1F;
}

static void Task_CloseItemfinderMessage(u8 taskId)
{
    ClearDialogWindowAndFrame(0, TRUE);
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
    DestroyTask(taskId);
}

static bool8 ItemfinderCheckForHiddenItems(const struct MapEvents *events, u8 taskId)
{
    int itemX, itemY;
    s16 playerX, playerY, i, distanceX, distanceY;
    PlayerGetDestCoords(&playerX, &playerY);
    gTasks[taskId].tItemFound = FALSE;

    for (i = 0; i < events->bgEventCount; i++)
    {
        // Check if there are any hidden items on the current map that haven't been picked up
        if (events->bgEvents[i].kind == BG_EVENT_HIDDEN_ITEM && !FlagGet(events->bgEvents[i].bgUnion.hiddenItem.hiddenItemId + FLAG_HIDDEN_ITEMS_START))
        {
            itemX = (u16)events->bgEvents[i].x + MAP_OFFSET;
            distanceX = itemX - playerX;
            itemY = (u16)events->bgEvents[i].y + MAP_OFFSET;
            distanceY = itemY - playerY;

            // Player can see 7 metatiles on either side horizontally
            // and 5 metatiles on either side vertically
            if (distanceX >= -7 && distanceX <= 7 && distanceY >= -5 && distanceY <= 5)
                SetDistanceOfClosestHiddenItem(taskId, distanceX, distanceY);
        }
    }

    CheckForHiddenItemsInMapConnection(taskId);
    if (gTasks[taskId].tItemFound == TRUE)
        return TRUE;
    else
        return FALSE;
}

static bool8 IsHiddenItemPresentAtCoords(const struct MapEvents *events, s16 x, s16 y)
{
    u8 bgEventCount = events->bgEventCount;
    const struct BgEvent *bgEvent = events->bgEvents;
    int i;

    for (i = 0; i < bgEventCount; i++)
    {
        if (bgEvent[i].kind == BG_EVENT_HIDDEN_ITEM && x == (u16)bgEvent[i].x && y == (u16)bgEvent[i].y) // hidden item and coordinates matches x and y passed?
        {
            if (!FlagGet(bgEvent[i].bgUnion.hiddenItem.hiddenItemId + FLAG_HIDDEN_ITEMS_START))
                return TRUE;
            else
                return FALSE;
        }
    }
    return FALSE;
}

static bool8 IsHiddenItemPresentInConnection(const struct MapConnection *connection, int x, int y)
{

    u16 localX, localY;
    u32 localOffset;
    s32 localLength;

    struct MapHeader const *const mapHeader = GetMapHeaderFromConnection(connection);

    switch (connection->direction)
    {
    // same weird temp variable behavior seen in IsHiddenItemPresentAtCoords
    case CONNECTION_NORTH:
        localOffset = connection->offset + MAP_OFFSET;
        localX = x - localOffset;
        localLength = mapHeader->mapLayout->height - MAP_OFFSET;
        localY = localLength + y; // additions are reversed for some reason
        break;
    case CONNECTION_SOUTH:
        localOffset = connection->offset + MAP_OFFSET;
        localX = x - localOffset;
        localLength = gMapHeader.mapLayout->height + MAP_OFFSET;
        localY = y - localLength;
        break;
    case CONNECTION_WEST:
        localLength = mapHeader->mapLayout->width - MAP_OFFSET;
        localX = localLength + x; // additions are reversed for some reason
        localOffset = connection->offset + MAP_OFFSET;
        localY = y - localOffset;
        break;
    case CONNECTION_EAST:
        localLength = gMapHeader.mapLayout->width + MAP_OFFSET;
        localX = x - localLength;
        localOffset = connection->offset + MAP_OFFSET;
        localY = y - localOffset;
        break;
    default:
        return FALSE;
    }
    return IsHiddenItemPresentAtCoords(mapHeader->events, localX, localY);
}

static void CheckForHiddenItemsInMapConnection(u8 taskId)
{
    s16 playerX, playerY;
    s16 x, y;
    s16 width = gMapHeader.mapLayout->width + MAP_OFFSET;
    s16 height = gMapHeader.mapLayout->height + MAP_OFFSET;

    s16 var1 = MAP_OFFSET;
    s16 var2 = MAP_OFFSET;

    PlayerGetDestCoords(&playerX, &playerY);

    // Player can see 7 metatiles on either side horizontally
    // and 5 metatiles on either side vertically
    for (x = playerX - 7; x <= playerX + 7; x++)
    {
        for (y = playerY - 5; y <= playerY + 5; y++)
        {
            if (var1 > x
             || x >= width
             || var2 > y
             || y >= height)
            {
                const struct MapConnection *conn = GetMapConnectionAtPos(x, y);
                if (conn && IsHiddenItemPresentInConnection(conn, x, y) == TRUE)
                    SetDistanceOfClosestHiddenItem(taskId, x - playerX, y - playerY);
            }
        }
    }
}

static void SetDistanceOfClosestHiddenItem(u8 taskId, s16 itemDistanceX, s16 itemDistanceY)
{
    s16 *data = gTasks[taskId].data;
    s16 oldItemAbsX, oldItemAbsY, newItemAbsX, newItemAbsY;

    if (tItemFound == FALSE)
    {
        // No other items found yet, set this one
        tItemDistanceX = itemDistanceX;
        tItemDistanceY = itemDistanceY;
        tItemFound = TRUE;
    }
    else
    {
        // Other items have been found, check if this one is closer

        // Get absolute x distance of the already-found item
        if (tItemDistanceX < 0)
            oldItemAbsX = tItemDistanceX * -1; // WEST
        else
            oldItemAbsX = tItemDistanceX;      // EAST

        // Get absolute y distance of the already-found item
        if (tItemDistanceY < 0)
            oldItemAbsY = tItemDistanceY * -1; // NORTH
        else
            oldItemAbsY = tItemDistanceY;      // SOUTH

        // Get absolute x distance of the newly-found item
        if (itemDistanceX < 0)
            newItemAbsX = itemDistanceX * -1;
        else
            newItemAbsX = itemDistanceX;

        // Get absolute y distance of the newly-found item
        if (itemDistanceY < 0)
            newItemAbsY = itemDistanceY * -1;
        else
            newItemAbsY = itemDistanceY;


        if (oldItemAbsX + oldItemAbsY > newItemAbsX + newItemAbsY)
        {
            // New item is closer
            tItemDistanceX = itemDistanceX;
            tItemDistanceY = itemDistanceY;
        }
        else
        {
            if (oldItemAbsX + oldItemAbsY == newItemAbsX + newItemAbsY
            && (oldItemAbsY > newItemAbsY || (oldItemAbsY == newItemAbsY && tItemDistanceY < itemDistanceY)))
            {
                // If items are equal distance, use whichever is closer on the Y axis or further south
                tItemDistanceX = itemDistanceX;
                tItemDistanceY = itemDistanceY;
            }
        }
    }
}

static u8 GetDirectionToHiddenItem(s16 itemDistanceX, s16 itemDistanceY)
{
    s16 absX, absY;

    if (itemDistanceX == 0 && itemDistanceY == 0)
        return DIR_NONE; // player is standing on the item.

    // Get absolute X distance.
    if (itemDistanceX < 0)
        absX = itemDistanceX * -1;
    else
        absX = itemDistanceX;

    // Get absolute Y distance.
    if (itemDistanceY < 0)
        absY = itemDistanceY * -1;
    else
        absY = itemDistanceY;

    if (absX > absY)
    {
        if (itemDistanceX < 0)
            return DIR_EAST;
        else
            return DIR_NORTH;
    }
    else
    {
        if (absX < absY)
        {
            if (itemDistanceY < 0)
                return DIR_SOUTH;
            else
                return DIR_WEST;
        }
        if (absX == absY)
        {
            if (itemDistanceY < 0)
                return DIR_SOUTH;
            else
                return DIR_WEST;
        }
        return DIR_NONE; // Unreachable
    }
}

static void PlayerFaceHiddenItem(u8 direction)
{
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]);
    ObjectEventClearHeldMovement(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]);
    UnfreezeObjectEvent(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]);
    PlayerTurnInPlace(direction);
}

static void Task_HiddenItemNearby(u8 taskId)
{
    if (ObjectEventCheckHeldMovementStatus(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]) == TRUE)
        DisplayItemMessageOnField(taskId, gText_ItemFinderNearby, Task_CloseItemfinderMessage);
}

static void Task_StandingOnHiddenItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (ObjectEventCheckHeldMovementStatus(&gObjectEvents[GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0)]) == TRUE
    || tItemFound == FALSE)
    {
        // Spin player around on item
        PlayerFaceHiddenItem(sClockwiseDirections[tFacingDir]);
        tItemFound = TRUE;
        tFacingDir = (tFacingDir + 1) & 3;
        tCounter++;

        if (tCounter == 4)
            DisplayItemMessageOnField(taskId, gText_ItemFinderOnTop, Task_CloseItemfinderMessage);
    }
}

// Undefine itemfinder task data
#undef tItemDistanceX
#undef tItemDistanceY
#undef tItemFound
#undef tCounter
#undef tItemfinderBeeps
#undef tFacingDir

void ItemUseOutOfBattle_PokeblockCase(u8 taskId)
{
    if (MenuHelpers_IsLinkActive() == TRUE)
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
    else if (gTasks[taskId].tUsingRegisteredKeyItem != TRUE)
    {
        gBagMenu->newScreenCallback = CB2_OpenPokeblockFromBag;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gFieldCallback = FieldCB_ReturnToFieldNoScript;
        FadeScreen(FADE_TO_BLACK, 0);
        gTasks[taskId].func = Task_OpenRegisteredPokeblockCase;
    }
}

static void CB2_OpenPokeblockFromBag(void)
{
    OpenPokeblockCase(PBLOCK_CASE_FIELD, CB2_ReturnToBagMenuPocket);
}

static void Task_OpenRegisteredPokeblockCase(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        OpenPokeblockCase(PBLOCK_CASE_FIELD, CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

void ItemUseOutOfBattle_PokemonBoxLink(u8 taskId)
{
    sItemUseOnFieldCB = Task_AccessPokemonBoxLink;
    SetUpItemUseOnFieldCallback(taskId);
}

static void Task_AccessPokemonBoxLink(u8 taskId)
{
    ScriptContext_SetupScript(EventScript_AccessPokemonBoxLink);
    DestroyTask(taskId);
}

void ItemUseOutOfBattle_CoinCase(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar1, GetCoins(), STR_CONV_MODE_LEFT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_CoinCase);

    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
    }
    else
    {
        DisplayItemMessageOnField(taskId, gStringVar4, Task_CloseCantUseKeyItemMessage);
    }
}

void ItemUseOutOfBattle_PowderJar(u8 taskId)
{
    ConvertIntToDecimalStringN(gStringVar1, GetBerryPowder(), STR_CONV_MODE_LEFT_ALIGN, 5);
    StringExpandPlaceholders(gStringVar4, gText_PowderQty);

    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
    }
    else
    {
        DisplayItemMessageOnField(taskId, gStringVar4, Task_CloseCantUseKeyItemMessage);
    }
}

void ItemUseOutOfBattle_Berry(u8 taskId)
{
    if (IsPlayerFacingEmptyBerryTreePatch() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_Berry;
        gFieldCallback = FieldCB_UseItemOnField;
        gBagMenu->newScreenCallback = CB2_ReturnToField;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        ItemId_GetFieldFunc(gSpecialVar_ItemId)(taskId);
    }
}

static void ItemUseOnFieldCB_Berry(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    LockPlayerFieldControls();
    ScriptContext_SetupScript(BerryTree_EventScript_ItemUsePlantBerry);
    DestroyTask(taskId);
}

void ItemUseOutOfBattle_WailmerPail(u8 taskId)
{
    if (TryToWaterSudowoodo() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_WailmerPailSudowoodo;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else if (TryToWaterBerryTree() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_WailmerPailBerry;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

static void ItemUseOnFieldCB_WailmerPailBerry(u8 taskId)
{
    LockPlayerFieldControls();
    ScriptContext_SetupScript(BerryTree_EventScript_ItemUseWailmerPail);
    DestroyTask(taskId);
}

static bool8 TryToWaterSudowoodo(void)
{
    s16 x, y;
    u8 elevation;
    u8 objId;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    elevation = PlayerGetElevation();
    objId = GetObjectEventIdByPosition(x, y, elevation);
    if (objId == OBJECT_EVENTS_COUNT || gObjectEvents[objId].graphicsId != OBJ_EVENT_GFX_SUDOWOODO)
        return FALSE;
    else
        return TRUE;
}

static void ItemUseOnFieldCB_WailmerPailSudowoodo(u8 taskId)
{
    LockPlayerFieldControls();
    ScriptContext_SetupScript(BattleFrontier_OutsideEast_EventScript_WaterSudowoodo);
    DestroyTask(taskId);
}

void ItemUseOutOfBattle_Medicine(u8 taskId)
{
    gItemUseCB = ItemUseCB_Medicine;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_AbilityCapsule(u8 taskId)
{
    gItemUseCB = ItemUseCB_AbilityCapsule;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_AbilityPatch(u8 taskId)
{
    gItemUseCB = ItemUseCB_AbilityPatch;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_Mint(u8 taskId)
{
    gItemUseCB = ItemUseCB_Mint;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_ResetEVs(u8 taskId)
{
    gItemUseCB = ItemUseCB_ResetEVs;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_ReduceEV(u8 taskId)
{
    gItemUseCB = ItemUseCB_ReduceEV;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_SacredAsh(u8 taskId)
{
    gItemUseCB = ItemUseCB_SacredAsh;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_PPRecovery(u8 taskId)
{
    gItemUseCB = ItemUseCB_PPRecovery;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_PPUp(u8 taskId)
{
    gItemUseCB = ItemUseCB_PPUp;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_RareCandy(u8 taskId)
{
    gItemUseCB = ItemUseCB_RareCandy;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_DynamaxCandy(u8 taskId)
{
    gItemUseCB = ItemUseCB_DynamaxCandy;
    SetUpItemUseCallback(taskId);
}

void ItemUseOutOfBattle_TMHM(u8 taskId)
{
    if (gSpecialVar_ItemId >= ITEM_HM01)
        DisplayItemMessage(taskId, FONT_NORMAL, gText_BootedUpHM, BootUpSoundTMHM); // HM
    else
        DisplayItemMessage(taskId, FONT_NORMAL, gText_BootedUpTM, BootUpSoundTMHM); // TM
}

static void BootUpSoundTMHM(u8 taskId)
{
    PlaySE(SE_PC_LOGIN);
    gTasks[taskId].func = Task_ShowTMHMContainedMessage;
}

static void Task_ShowTMHMContainedMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        StringCopy(gStringVar1, GetMoveName(ItemIdToBattleMoveId(gSpecialVar_ItemId)));
        StringExpandPlaceholders(gStringVar4, gText_TMHMContainedVar1);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, UseTMHMYesNo);
    }
}

static void UseTMHMYesNo(u8 taskId)
{
    BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sUseTMHMYesNoFuncTable);
}

static void UseTMHM(u8 taskId)
{
    gItemUseCB = ItemUseCB_TMHM;
    SetUpItemUseCallback(taskId);
}

static void RemoveUsedItem(void)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gText_PlayerUsedVar2);
    if (!InBattlePyramid())
    {
        UpdatePocketItemList(ItemId_GetPocket(gSpecialVar_ItemId));
        UpdatePocketListPosition(ItemId_GetPocket(gSpecialVar_ItemId));
    }
    else
    {
        UpdatePyramidBagList();
        UpdatePyramidBagCursorPos();
    }
}

void ItemUseOutOfBattle_Repel(u8 taskId)
{
    if (REPEL_STEP_COUNT == 0)
        gTasks[taskId].func = Task_StartUseRepel;
    else if (!InBattlePyramid())
        DisplayItemMessage(taskId, FONT_NORMAL, gText_RepelEffectsLingered, CloseItemMessage);
    else
        DisplayItemMessageInBattlePyramid(taskId, gText_RepelEffectsLingered, Task_CloseBattlePyramidBagMessage);
}

static void Task_StartUseRepel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (++data[8] > 7)
    {
        data[8] = 0;
        PlaySE(SE_REPEL);
        gTasks[taskId].func = Task_UseRepel;
    }
}

static void Task_UseRepel(u8 taskId)
{
    if (!IsSEPlaying())
    {
        VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(gSpecialVar_ItemId));
    #if VAR_LAST_REPEL_LURE_USED != 0
        VarSet(VAR_LAST_REPEL_LURE_USED, gSpecialVar_ItemId);
    #endif
        RemoveUsedItem();
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
}
void HandleUseExpiredRepel(struct ScriptContext *ctx)
{
#if VAR_LAST_REPEL_LURE_USED != 0
    VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(VarGet(VAR_LAST_REPEL_LURE_USED)));
#endif
}

void ItemUseOutOfBattle_Lure(u8 taskId)
{
    if (LURE_STEP_COUNT == 0)
        gTasks[taskId].func = Task_StartUseLure;
    else if (!InBattlePyramid())
        DisplayItemMessage(taskId, FONT_NORMAL, gText_LureEffectsLingered, CloseItemMessage);
    else
        DisplayItemMessageInBattlePyramid(taskId, gText_LureEffectsLingered, Task_CloseBattlePyramidBagMessage);
}

static void Task_StartUseLure(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (++data[8] > 7)
    {
        data[8] = 0;
        PlaySE(SE_REPEL);
        gTasks[taskId].func = Task_UseLure;
    }
}

static void Task_UseLure(u8 taskId)
{
    if (!IsSEPlaying())
    {
        VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(gSpecialVar_ItemId) | REPEL_LURE_MASK);
    #if VAR_LAST_REPEL_LURE_USED != 0
        VarSet(VAR_LAST_REPEL_LURE_USED, gSpecialVar_ItemId);
    #endif
        RemoveUsedItem();
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
}

void HandleUseExpiredLure(struct ScriptContext *ctx)
{
#if VAR_LAST_REPEL_LURE_USED != 0
    VarSet(VAR_REPEL_STEP_COUNT, ItemId_GetHoldEffectParam(VarGet(VAR_LAST_REPEL_LURE_USED)) | REPEL_LURE_MASK);
#endif
}

static void Task_UsedBlackWhiteFlute(u8 taskId)
{
    if(++gTasks[taskId].data[8] > 7)
    {
        PlaySE(SE_GLASS_FLUTE);
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
}

void ItemUseOutOfBattle_BlackWhiteFlute(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    if (gSpecialVar_ItemId == ITEM_WHITE_FLUTE)
    {
        FlagSet(FLAG_SYS_ENC_UP_ITEM);
        FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
        StringExpandPlaceholders(gStringVar4, gText_UsedVar2WildLured);
    }
    else
    {
        FlagSet(FLAG_SYS_ENC_DOWN_ITEM);
        FlagClear(FLAG_SYS_ENC_UP_ITEM);
        StringExpandPlaceholders(gStringVar4, gText_UsedVar2WildRepelled);
    }
    gTasks[taskId].data[8] = 0;
    gTasks[taskId].func = Task_UsedBlackWhiteFlute;
}

void Task_UseDigEscapeRopeOnField(u8 taskId)
{
    ResetInitialPlayerAvatarState();
    StartEscapeRopeFieldEffect();
    DestroyTask(taskId);
}

static void ItemUseOnFieldCB_EscapeRope(u8 taskId)
{
    Overworld_ResetStateAfterDigEscRope();
    if (I_KEY_ESCAPE_ROPE < GEN_8)
    {
        RemoveUsedItem();
    }
    else
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_PlayerUsedVar2);
    }
    gTasks[taskId].data[0] = 0;
    DisplayItemMessageOnField(taskId, gStringVar4, Task_UseDigEscapeRopeOnField);
}

bool8 CanUseDigOrEscapeRopeOnCurMap(void)
{
    if (gMapHeader.allowEscaping)
        return TRUE;
    else
        return FALSE;
}

void ItemUseOutOfBattle_EscapeRope(u8 taskId)
{
    if (CanUseDigOrEscapeRopeOnCurMap() == TRUE)
    {
        sItemUseOnFieldCB = ItemUseOnFieldCB_EscapeRope;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

void ItemUseOutOfBattle_EvolutionStone(u8 taskId)
{
    gItemUseCB = ItemUseCB_EvolutionStone;
    SetUpItemUseCallback(taskId);
}

static u32 GetBallThrowableState(void)
{
    if (IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
     && IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)))
        return BALL_THROW_UNABLE_TWO_MONS;
    else if (IsPlayerPartyAndPokemonStorageFull() == TRUE)
        return BALL_THROW_UNABLE_NO_ROOM;
    else if (B_SEMI_INVULNERABLE_CATCH >= GEN_4 && (gStatuses3[GetCatchingBattler()] & STATUS3_SEMI_INVULNERABLE))
        return BALL_THROW_UNABLE_SEMI_INVULNERABLE;
    else if (FlagGet(B_FLAG_NO_CATCHING))
        return BALL_THROW_UNABLE_DISABLED_FLAG;

    return BALL_THROW_ABLE;
}

bool32 CanThrowBall(void)
{
    return (GetBallThrowableState() == BALL_THROW_ABLE);
}

static const u8 sText_CantThrowPokeBall_TwoMons[] = _("Cannot throw a ball!\nThere are two Pokémon out there!\p");
static const u8 sText_CantThrowPokeBall_SemiInvulnerable[] = _("Cannot throw a ball!\nThere's no Pokémon in sight!\p");
static const u8 sText_CantThrowPokeBall_Disabled[] = _("POKé BALLS cannot be used\nright now!\p");
void ItemUseInBattle_PokeBall(u8 taskId)
{
    switch (GetBallThrowableState())
    {
    case BALL_THROW_ABLE:
    default:
        RemoveBagItem(gSpecialVar_ItemId, 1);
        if (!InBattlePyramid())
            Task_FadeAndCloseBagMenu(taskId);
        else
            CloseBattlePyramidBag(taskId);
        break;
    case BALL_THROW_UNABLE_TWO_MONS:
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, sText_CantThrowPokeBall_TwoMons, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, sText_CantThrowPokeBall_TwoMons, Task_CloseBattlePyramidBagMessage);
        break;
    case BALL_THROW_UNABLE_NO_ROOM:
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, gText_BoxFull, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, gText_BoxFull, Task_CloseBattlePyramidBagMessage);
        break;
    case BALL_THROW_UNABLE_SEMI_INVULNERABLE:
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, sText_CantThrowPokeBall_SemiInvulnerable, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, sText_CantThrowPokeBall_SemiInvulnerable, Task_CloseBattlePyramidBagMessage);
        break;
    case BALL_THROW_UNABLE_DISABLED_FLAG:
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, sText_CantThrowPokeBall_Disabled, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, sText_CantThrowPokeBall_Disabled, Task_CloseBattlePyramidBagMessage);
        break;
    }
}

static void ItemUseInBattle_ShowPartyMenu(u8 taskId)
{
    if (!InBattlePyramid())
    {
        gBagMenu->newScreenCallback = ChooseMonForInBattleItem;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        gPyramidBagMenu->newScreenCallback = ChooseMonForInBattleItem;
        CloseBattlePyramidBag(taskId);
    }
}

void ItemUseInBattle_PartyMenu(u8 taskId)
{
    gItemUseCB = ItemUseCB_BattleScript;
    ItemUseInBattle_ShowPartyMenu(taskId);
}

void ItemUseInBattle_PartyMenuChooseMove(u8 taskId)
{
    gItemUseCB = ItemUseCB_BattleChooseMove;
    ItemUseInBattle_ShowPartyMenu(taskId);
}

// Returns whether an item can be used in battle and sets the fail text.
bool32 CannotUseItemsInBattle(u16 itemId, struct Pokemon *mon)
{
    u16 battleUsage = ItemId_GetBattleUsage(itemId);
    bool8 cannotUse = FALSE;
    const u8* failStr = NULL;
    u32 i;
    u16 hp = GetMonData(mon, MON_DATA_HP);

    // Embargo Check
    if ((gPartyMenu.slotId == 0 && gStatuses3[B_POSITION_PLAYER_LEFT] & STATUS3_EMBARGO)
        || (gPartyMenu.slotId == 1 && gStatuses3[B_POSITION_PLAYER_RIGHT] & STATUS3_EMBARGO))
    {
        return TRUE;
    }

    // battleUsage checks
    switch (battleUsage)
    {
    case EFFECT_ITEM_INCREASE_STAT:
        if (gBattleMons[gBattlerInMenuId].statStages[ItemId_GetEffect(itemId)[1]] == MAX_STAT_STAGE)
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_SET_FOCUS_ENERGY:
        if (gBattleMons[gBattlerInMenuId].status2 & STATUS2_FOCUS_ENERGY_ANY)
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_SET_MIST:
        if (gSideStatuses[GetBattlerSide(gBattlerInMenuId)] & SIDE_STATUS_MIST)
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_ESCAPE:
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_THROW_BALL:
        switch (GetBallThrowableState())
        {
        case BALL_THROW_UNABLE_TWO_MONS:
            failStr = sText_CantThrowPokeBall_TwoMons;
            cannotUse = TRUE;
            break;
        case BALL_THROW_UNABLE_NO_ROOM:
            failStr = gText_BoxFull;
            cannotUse = TRUE;
            break;
        case BALL_THROW_UNABLE_SEMI_INVULNERABLE:
            failStr = sText_CantThrowPokeBall_SemiInvulnerable;
            cannotUse = TRUE;
            break;
        case BALL_THROW_UNABLE_DISABLED_FLAG:
            failStr = sText_CantThrowPokeBall_Disabled;
            cannotUse = TRUE;
            break;
        }
        break;
    case EFFECT_ITEM_INCREASE_ALL_STATS:
        for (i = STAT_ATK; i < NUM_STATS; i++)
        {
            if (CompareStat(gBattlerInMenuId, i, MAX_STAT_STAGE, CMP_EQUAL))
            {
                cannotUse = TRUE;
                break;
            }
        }
        break;
    case EFFECT_ITEM_RESTORE_HP:
        if (hp == 0 || hp == GetMonData(mon, MON_DATA_MAX_HP))
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_CURE_STATUS:
        if (!((GetMonData(mon, MON_DATA_STATUS) & GetItemStatus1Mask(itemId))
            || (gPartyMenu.slotId == 0 && gBattleMons[gBattlerInMenuId].status2 & GetItemStatus2Mask(itemId))))
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_HEAL_AND_CURE_STATUS:
        if ((hp == 0 || hp == GetMonData(mon, MON_DATA_MAX_HP))
            && !((GetMonData(mon, MON_DATA_STATUS) & GetItemStatus1Mask(itemId))
            || (gPartyMenu.slotId == 0 && gBattleMons[gBattlerInMenuId].status2 & GetItemStatus2Mask(itemId))))
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_REVIVE:
        if (hp != 0)
            cannotUse = TRUE;
        break;
    case EFFECT_ITEM_RESTORE_PP:
        if (ItemId_GetEffect(itemId)[6] == ITEM4_HEAL_PP)
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (GetMonData(mon, MON_DATA_PP1 + i) < CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + i), GetMonData(mon, MON_DATA_PP_BONUSES), i));
                    break;
            }
            if (i == MAX_MON_MOVES)
                cannotUse = TRUE;
        }
        else if (GetMonData(mon, MON_DATA_PP1 + gPartyMenu.data1) == CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + gPartyMenu.data1), GetMonData(mon, MON_DATA_PP_BONUSES), gPartyMenu.data1))
        {
            cannotUse = TRUE;
        }
        break;
    }

    if (failStr != NULL)
        StringExpandPlaceholders(gStringVar4, failStr);
    else
        StringExpandPlaceholders(gStringVar4, gText_WontHaveEffect);

    return cannotUse;
}

void ItemUseInBattle_BagMenu(u8 taskId)
{
    if (CannotUseItemsInBattle(gSpecialVar_ItemId, NULL))
    {
        if (!InBattlePyramid())
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
        else
            DisplayItemMessageInBattlePyramid(taskId, gStringVar4, Task_CloseBattlePyramidBagMessage);
    }
    else
    {
        PlaySE(SE_SELECT);
        if (!(B_TRY_CATCH_TRAINER_BALL >= GEN_4 && (ItemId_GetBattleUsage(gSpecialVar_ItemId) == EFFECT_ITEM_THROW_BALL) && (gBattleTypeFlags & BATTLE_TYPE_TRAINER)))
            RemoveUsedItem();
        ScheduleBgCopyTilemapToVram(2);
        if (!InBattlePyramid())
            gTasks[taskId].func = Task_FadeAndCloseBagMenu;
        else
            gTasks[taskId].func = CloseBattlePyramidBag;
    }
}

void ItemUseOutOfBattle_EnigmaBerry(u8 taskId)
{
    switch (GetItemEffectType(gSpecialVar_ItemId))
    {
    case ITEM_EFFECT_HEAL_HP:
    case ITEM_EFFECT_CURE_POISON:
    case ITEM_EFFECT_CURE_SLEEP:
    case ITEM_EFFECT_CURE_BURN:
    case ITEM_EFFECT_CURE_FREEZE_FROSTBITE:
    case ITEM_EFFECT_CURE_PARALYSIS:
    case ITEM_EFFECT_CURE_ALL_STATUS:
    case ITEM_EFFECT_ATK_EV:
    case ITEM_EFFECT_HP_EV:
    case ITEM_EFFECT_SPATK_EV:
    case ITEM_EFFECT_SPDEF_EV:
    case ITEM_EFFECT_SPEED_EV:
    case ITEM_EFFECT_DEF_EV:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_Medicine(taskId);
        break;
    case ITEM_EFFECT_SACRED_ASH:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_SacredAsh(taskId);
        break;
    case ITEM_EFFECT_RAISE_LEVEL:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_RareCandy(taskId);
        break;
    case ITEM_EFFECT_PP_UP:
    case ITEM_EFFECT_PP_MAX:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_PPUp(taskId);
        break;
    case ITEM_EFFECT_HEAL_PP:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_PARTY_MENU;
        ItemUseOutOfBattle_PPRecovery(taskId);
        break;
    default:
        gTasks[taskId].tEnigmaBerryType = ITEM_USE_BAG_MENU;
        ItemUseOutOfBattle_CannotUse(taskId);
        break;
    }
}

void ItemUseOutOfBattle_FormChange(u8 taskId)
{
    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        gItemUseCB = ItemUseCB_FormChange;
        gTasks[taskId].data[0] = FALSE;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        // TODO: handle key items with callbacks to menus allow to be used by registering them.
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

void ItemUseOutOfBattle_FormChange_ConsumedOnUse(u8 taskId)
{
    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        gItemUseCB = ItemUseCB_FormChange_ConsumedOnUse;
        gTasks[taskId].data[0] = TRUE;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        // TODO: handle key items with callbacks to menus allow to be used by registering them.
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

void ItemUseOutOfBattle_RotomCatalog(u8 taskId)
{
    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        gItemUseCB = ItemUseCB_RotomCatalog;
        gTasks[taskId].data[0] = TRUE;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        // TODO: handle key items with callbacks to menus allow to be used by registering them.
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

void ItemUseOutOfBattle_ZygardeCube(u8 taskId)
{
    if (!gTasks[taskId].tUsingRegisteredKeyItem)
    {
        gItemUseCB = ItemUseCB_ZygardeCube;
        gTasks[taskId].data[0] = TRUE;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
    {
        // TODO: handle key items with callbacks to menus allow to be used by registering them.
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
    }
}

void ItemUseOutOfBattle_Fusion(u8 taskId)
{
    gItemUseCB = ItemUseCB_Fusion;
    gTasks[taskId].data[0] = FALSE;
    SetUpItemUseCallback(taskId);
}

void Task_UseHoneyOnField(u8 taskId)
{
    //ResetInitialPlayerAvatarState();
    StartSweetScentFieldEffect();
    DestroyTask(taskId);
}

static void ItemUseOnFieldCB_Honey(u8 taskId)
{
    Overworld_ResetStateAfterDigEscRope();
    RemoveUsedItem();
    gTasks[taskId].data[0] = 0;
    DisplayItemMessageOnField(taskId, gStringVar4, Task_UseHoneyOnField);
}

void ItemUseOutOfBattle_Honey(u8 taskId)
{
    sItemUseOnFieldCB = ItemUseOnFieldCB_Honey;
    gFieldCallback = FieldCB_UseItemOnField;
    gBagMenu->newScreenCallback = CB2_ReturnToField;
    Task_FadeAndCloseBagMenu(taskId);
}

void ItemUseOutOfBattle_CannotUse(u8 taskId)
{
    DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].tUsingRegisteredKeyItem);
}

static bool32 IsValidLocationForVsSeeker(void)
{
    u16 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u16 mapNum = gSaveBlock1Ptr->location.mapNum;
    u16 mapType = gMapHeader.mapType;

    typedef struct {
        u16 mapGroup;
        u16 mapNum;
    } Location;

    u32 i;
    Location validIndoorLocations[] =
    {
        { MAP_GROUP(MT_PYRE_SUMMIT),           MAP_NUM(MT_PYRE_SUMMIT) },
        { MAP_GROUP(SAFARI_ZONE_NORTH),        MAP_NUM(SAFARI_ZONE_NORTH) },
        { MAP_GROUP(SAFARI_ZONE_NORTHEAST),    MAP_NUM(SAFARI_ZONE_NORTHEAST) },
        { MAP_GROUP(SAFARI_ZONE_NORTHWEST),    MAP_NUM(SAFARI_ZONE_NORTHWEST) },
        { MAP_GROUP(SAFARI_ZONE_SOUTH),        MAP_NUM(SAFARI_ZONE_SOUTH) },
        { MAP_GROUP(SAFARI_ZONE_SOUTHEAST),    MAP_NUM(SAFARI_ZONE_SOUTHEAST) },
        { MAP_GROUP(SAFARI_ZONE_SOUTHWEST),    MAP_NUM(SAFARI_ZONE_SOUTHWEST) },
        { MAP_GROUP(SKY_PILLAR_TOP),           MAP_NUM(SKY_PILLAR_TOP) },
        { MAP_GROUP(SOUTHERN_ISLAND_EXTERIOR), MAP_NUM(SOUTHERN_ISLAND_EXTERIOR) },
        { MAP_GROUP(SOUTHERN_ISLAND_INTERIOR), MAP_NUM(SOUTHERN_ISLAND_INTERIOR) },
        { MAP_GROUP(RUSTBORO_CITY_GYM),        MAP_NUM(RUSTBORO_CITY_GYM) },
        { MAP_GROUP(DEWFORD_TOWN_GYM),         MAP_NUM(DEWFORD_TOWN_GYM) },
        { MAP_GROUP(MAUVILLE_CITY_GYM),        MAP_NUM(MAUVILLE_CITY_GYM) },
        { MAP_GROUP(LAVARIDGE_TOWN_GYM_1F),    MAP_NUM(LAVARIDGE_TOWN_GYM_1F) },
        { MAP_GROUP(LAVARIDGE_TOWN_GYM_B1F),   MAP_NUM(LAVARIDGE_TOWN_GYM_B1F) },
        { MAP_GROUP(PETALBURG_CITY_GYM),       MAP_NUM(PETALBURG_CITY_GYM) },
        { MAP_GROUP(FORTREE_CITY_GYM),         MAP_NUM(FORTREE_CITY_GYM) },
        { MAP_GROUP(MOSSDEEP_CITY_GYM),        MAP_NUM(MOSSDEEP_CITY_GYM) },
        { MAP_GROUP(SOOTOPOLIS_CITY_GYM_1F),   MAP_NUM(SOOTOPOLIS_CITY_GYM_1F) },
        { MAP_GROUP(SOOTOPOLIS_CITY_GYM_B1F),  MAP_NUM(SOOTOPOLIS_CITY_GYM_B1F) },
    };

    if (IsMapTypeOutdoors(mapType))
        return TRUE;

    for (i = 0; i < ARRAY_COUNT(validIndoorLocations); i++)
    {
        if (mapNum == validIndoorLocations[i].mapNum && mapGroup == validIndoorLocations[i].mapGroup)
            return TRUE;
    }

    return FALSE;
}

void FieldUseFunc_VsSeeker(u8 taskId)
{
    if (IsValidLocationForVsSeeker())
    {
        sItemUseOnFieldCB = Task_InitVsSeekerAndCheckForTrainersOnScreen;
        SetUpItemUseOnFieldCallback(taskId);
    }
    else
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].data[3]);
}

void Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker(u8 taskId)
{
    Task_CloseCantUseKeyItemMessage(taskId);
}

#undef tUsingRegisteredKeyItem
