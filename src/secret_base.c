#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "decoration.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "international_string_util.h"
#include "link.h"
#include "list_menu.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "menu_helpers.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "secret_base.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "tv.h"
#include "window.h"
#include "constants/bg_event_constants.h"
#include "constants/decorations.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/map_types.h"
#include "constants/metatile_behaviors.h"
#include "constants/moves.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"

struct SecretBaseRegistryMenu
{
    struct ListMenuItem items[11];
    u8 names[11][32];
};

struct SecretBaseRecordMixer
{
    struct SecretBase *secretBases;
    u32 version;
    u32 language;
};

struct SecretBaseEntranceMetatiles
{
    u16 closedMetatileId;
    u16 openMetatileId;
};

static EWRAM_DATA u8 sCurSecretBaseId = 0;
static EWRAM_DATA bool8 sInFriendSecretBase = FALSE;
static EWRAM_DATA struct SecretBaseRegistryMenu *sRegistryMenu = NULL;

static void Task_ShowSecretBaseRegistryMenu(u8 taskId);
static void BuildRegistryMenuItems(u8 taskId);
static void RegistryMenu_OnCursorMove(s32 unused, bool8 flag, struct ListMenu *menu);
static void FinalizeRegistryMenu(u8 taskId);
static void AddRegistryMenuScrollArrows(u8 taskId);
static void HandleRegistryMenuInput(u8 taskId);
static void ShowRegistryMenuActions(u8 taskId);
static void HandleRegistryMenuActionsInput(u8 taskId);
static void ShowRegistryMenuDeleteConfirmation(u8 taskId);
static void ShowRegistryMenuDeleteYesNo(u8 taskId);
static void DeleteRegistry_Yes(u8 taskId);
static void DeleteRegistry_No(u8 taskId);
static void ReturnToMainRegistryMenu(u8 taskId);
static void GoToSecretBasePCRegisterMenu(u8 taskId);
static u8 GetSecretBaseOwnerType(u8 secretBaseId);

static const struct SecretBaseEntranceMetatiles sSecretBaseEntranceMetatiles[] =
{
    {.closedMetatileId = 0x0026, .openMetatileId = 0x0036},
    {.closedMetatileId = 0x0027, .openMetatileId = 0x0037},
    {.closedMetatileId = 0x01a0, .openMetatileId = 0x01a1},
    {.closedMetatileId = 0x01a8, .openMetatileId = 0x01a9},
    {.closedMetatileId = 0x01b0, .openMetatileId = 0x01b1},
    {.closedMetatileId = 0x0208, .openMetatileId = 0x0210},
    {.closedMetatileId = 0x0271, .openMetatileId = 0x0278},
};

// mapNum, warpId, x, y
// x, y positions are for when the player warps in for the first time (in front of the computer)
static const u8 sSecretBaseEntrancePositions[] =
{
    MAP_NUM(SECRET_BASE_RED_CAVE1),    0,  1,  3,
    MAP_NUM(SECRET_BASE_RED_CAVE2),    0,  5,  9,
    MAP_NUM(SECRET_BASE_RED_CAVE3),    0,  1,  3,
    MAP_NUM(SECRET_BASE_RED_CAVE4),    0,  7, 13,
    MAP_NUM(SECRET_BASE_BROWN_CAVE1),  0,  2,  3,
    MAP_NUM(SECRET_BASE_BROWN_CAVE2),  0,  9,  2,
    MAP_NUM(SECRET_BASE_BROWN_CAVE3),  0, 13,  4,
    MAP_NUM(SECRET_BASE_BROWN_CAVE4),  0,  1,  2,
    MAP_NUM(SECRET_BASE_BLUE_CAVE1),   0,  1,  3,
    MAP_NUM(SECRET_BASE_BLUE_CAVE2),   0,  1,  2,
    MAP_NUM(SECRET_BASE_BLUE_CAVE3),   0,  3, 15,
    MAP_NUM(SECRET_BASE_BLUE_CAVE4),   0,  3, 14,
    MAP_NUM(SECRET_BASE_YELLOW_CAVE1), 0,  9,  3,
    MAP_NUM(SECRET_BASE_YELLOW_CAVE2), 0,  8,  7,
    MAP_NUM(SECRET_BASE_YELLOW_CAVE3), 0,  3,  6,
    MAP_NUM(SECRET_BASE_YELLOW_CAVE4), 0,  5,  9,
    MAP_NUM(SECRET_BASE_TREE1),        0,  2,  3,
    MAP_NUM(SECRET_BASE_TREE2),        0,  5,  6,
    MAP_NUM(SECRET_BASE_TREE3),        0, 15,  3,
    MAP_NUM(SECRET_BASE_TREE4),        0,  4, 10,
    MAP_NUM(SECRET_BASE_SHRUB1),       0,  3,  3,
    MAP_NUM(SECRET_BASE_SHRUB2),       0,  1,  2,
    MAP_NUM(SECRET_BASE_SHRUB3),       0,  7,  8,
    MAP_NUM(SECRET_BASE_SHRUB4),       0,  9,  6,
};

static const struct MenuAction sRegistryMenuActions[] =
{
    {
        .text = gText_DelRegist,
        .func = { .void_u8 = ShowRegistryMenuDeleteConfirmation },
    },
    {
        .text = gText_Cancel,
        .func = { .void_u8 = ReturnToMainRegistryMenu },
    },
};

static const struct YesNoFuncTable sDeleteRegistryYesNoFuncs =
{
    .yesFunc = DeleteRegistry_Yes,
    .noFunc = DeleteRegistry_No,
};

static const u8 sSecretBaseOwnerGfxIds[10] =
{
    // Male
    EVENT_OBJ_GFX_YOUNGSTER,
    EVENT_OBJ_GFX_BUG_CATCHER,
    EVENT_OBJ_GFX_RICH_BOY,
    EVENT_OBJ_GFX_CAMPER,
    EVENT_OBJ_GFX_MAN_3,
    // Female
    EVENT_OBJ_GFX_LASS,
    EVENT_OBJ_GFX_GIRL_3,
    EVENT_OBJ_GFX_WOMAN_2,
    EVENT_OBJ_GFX_PICNICKER,
    EVENT_OBJ_GFX_WOMAN_5,
};

static const struct WindowTemplate sRegistryWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 18,
        .tilemapTop = 1,
        .width = 11,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 0x01,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xc7,
    }
};

static const struct ListMenuTemplate sRegistryListMenuTemplate =
{
    .items = NULL,
    .moveCursorFunc = RegistryMenu_OnCursorMove,
    .itemPrintFunc = NULL,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 9,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0,
};

static void ClearSecretBase(struct SecretBase *secretBase)
{
    u16 i;
    CpuFastFill16(0, secretBase, sizeof(struct SecretBase));
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        secretBase->trainerName[i] = EOS;
}

void ClearSecretBases(void)
{
    u16 i;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
        ClearSecretBase(&gSaveBlock1Ptr->secretBases[i]);
}

static void SetCurSecretBaseId(void)
{
    sCurSecretBaseId = gSpecialVar_0x8004;
}

void TrySetCurSecretBaseIndex(void)
{
    u16 i;

    gSpecialVar_Result = FALSE;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (sCurSecretBaseId == gSaveBlock1Ptr->secretBases[i].secretBaseId)
        {
            gSpecialVar_Result = TRUE;
            VarSet(VAR_CURRENT_SECRET_BASE, i);
            break;
        }
    }
}

void CheckPlayerHasSecretBase(void)
{
    // The player's secret base is always the first in the array.
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static u8 GetSecretBaseTypeInFrontOfPlayer_(void)
{
    s16 x, y;
    s16 behavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y) & 0xFFF;
    if (behavior == MB_SECRET_BASE_SPOT_RED_CAVE || behavior == MB_SECRET_BASE_SPOT_RED_CAVE_OPEN)
        return SECRET_BASE_RED_CAVE;

    if (behavior == MB_SECRET_BASE_SPOT_BROWN_CAVE || behavior == MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN)
        return SECRET_BASE_BROWN_CAVE;

    if (behavior == MB_SECRET_BASE_SPOT_BLUE_CAVE || behavior == MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN)
        return SECRET_BASE_BLUE_CAVE;

    if (behavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE || behavior == MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN)
        return SECRET_BASE_YELLOW_CAVE;

    if (behavior == MB_SECRET_BASE_SPOT_TREE_LEFT  || behavior == MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN
     || behavior == MB_SECRET_BASE_SPOT_TREE_RIGHT || behavior == MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN)
        return SECRET_BASE_TREE;

    if (behavior == MB_SECRET_BASE_SPOT_SHRUB || behavior == MB_SECRET_BASE_SPOT_SHRUB_OPEN)
        return SECRET_BASE_SHRUB;

    return 0;
}

void GetSecretBaseTypeInFrontOfPlayer(void)
{
    gSpecialVar_0x8007 = GetSecretBaseTypeInFrontOfPlayer_();
}

static void FindMetatileIdMapCoords(s16 *x, s16 *y, u16 metatileId)
{
    s16 i, j;
    const struct MapLayout *mapLayout = gMapHeader.mapLayout;

    for (j = 0; j < mapLayout->height; j++)
    {
        for (i = 0; i < mapLayout->width; i++)
        {
            if ((mapLayout->map[j * mapLayout->width + i] & METATILE_ID_MASK) == metatileId)
            {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

// Opens or closes the secret base entrance metatile in front of the player.
void ToggleSecretBaseEntranceMetatile(void)
{
    u16 i;
    s16 x, y;
    s16 metatileId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    metatileId = MapGridGetMetatileIdAt(x, y);
    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].closedMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].openMetatileId | METATILE_COLLISION_MASK);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }

    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
    {
        if (sSecretBaseEntranceMetatiles[i].openMetatileId == metatileId)
        {
            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].closedMetatileId | METATILE_COLLISION_MASK);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
}

static u8 GetNameLength(const u8 *secretBaseOwnerName)
{
    u8 i;
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
    {
        if (secretBaseOwnerName[i] == EOS)
            return i;
    }

    return PLAYER_NAME_LENGTH;
}

void SetPlayerSecretBase(void)
{
    u16 i;

    gSaveBlock1Ptr->secretBases[0].secretBaseId = sCurSecretBaseId;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        gSaveBlock1Ptr->secretBases[0].trainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    VarSet(VAR_CURRENT_SECRET_BASE, 0);
    StringCopyN(gSaveBlock1Ptr->secretBases[0].trainerName, gSaveBlock2Ptr->playerName, GetNameLength(gSaveBlock2Ptr->playerName));
    gSaveBlock1Ptr->secretBases[0].gender = gSaveBlock2Ptr->playerGender;
    gSaveBlock1Ptr->secretBases[0].language = GAME_LANGUAGE;
    VarSet(VAR_SECRET_BASE_MAP, gMapHeader.regionMapSectionId);
}

void SetOccupiedSecretBaseEntranceMetatiles(struct MapEvents const *events)
{
    u16 bgId;
    u16 i, j;

    for (bgId = 0; bgId < events->bgEventCount; bgId++)
    {
        if (events->bgEvents[bgId].kind == BG_EVENT_SECRET_BASE)
        {
            for (j = 0; j < SECRET_BASES_COUNT; j++)
            {
                if (gSaveBlock1Ptr->secretBases[j].secretBaseId == events->bgEvents[bgId].bgUnion.secretBaseId)
                {
                    s16 x = events->bgEvents[bgId].x + 7;
                    s16 y = events->bgEvents[bgId].y + 7;
                    s16 tile_id = MapGridGetMetatileIdAt(x, y);
                    for (i = 0; i < ARRAY_COUNT(sSecretBaseEntranceMetatiles); i++)
                    {
                        if (sSecretBaseEntranceMetatiles[i].closedMetatileId == tile_id)
                        {
                            MapGridSetMetatileIdAt(x, y, sSecretBaseEntranceMetatiles[i].openMetatileId | METATILE_COLLISION_MASK);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}

static void SetSecretBaseWarpDestination(void)
{
    s8 offset = (sCurSecretBaseId / 10) * 4;
    SetWarpDestinationToMapWarp(MAP_GROUP(SECRET_BASE_RED_CAVE1), sSecretBaseEntrancePositions[offset], sSecretBaseEntrancePositions[offset + 1]);
}

static void Task_EnterSecretBase(u8 taskId)
{
    u16 secretBaseId;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (!gPaletteFade.active)
            gTasks[taskId].data[0] = 1;
        break;
    case 1:
        secretBaseId = VarGet(VAR_CURRENT_SECRET_BASE);
        if (gSaveBlock1Ptr->secretBases[secretBaseId].numTimesEntered < 255)
            gSaveBlock1Ptr->secretBases[secretBaseId].numTimesEntered++;

        SetSecretBaseWarpDestination();
        WarpIntoMap();
        gFieldCallback = FieldCallback_ReturnToEventScript2;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
        break;
    }
}

void EnterSecretBase(void)
{
    CreateTask(Task_EnterSecretBase, 0);
    FadeScreen(1, 0);
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

bool8 SecretBaseMapPopupEnabled(void)
{
    if (gMapHeader.mapType == MAP_TYPE_SECRET_BASE && VarGet(VAR_INIT_SECRET_BASE) == 0)
        return FALSE;

    return TRUE;
}

static void EnterNewlyCreatedSecretBase_WaitFadeIn(u8 taskId)
{
    EventObjectTurn(&gEventObjects[gPlayerAvatar.eventObjectId], DIR_NORTH);
    if (IsWeatherNotFadingIn() == TRUE)
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

static void EnterNewlyCreatedSecretBase_StartFadeIn(void)
{
    s16 x, y;

    ScriptContext2_Enable();
    HideMapNamePopUpWindow();
    FindMetatileIdMapCoords(&x, &y, 0x220);
    x += 7;
    y += 7;
    MapGridSetMetatileIdAt(x, y, 0x220 | METATILE_COLLISION_MASK);
    CurrentMapDrawMetatileAt(x, y);
    pal_fill_black();
    CreateTask(EnterNewlyCreatedSecretBase_WaitFadeIn, 0);
}

static void Task_EnterNewlyCreatedSecretBase(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        s8 offset = sCurSecretBaseId / 10 * 4;
        SetWarpDestination(
            gSaveBlock1Ptr->location.mapGroup,
            gSaveBlock1Ptr->location.mapNum,
            -1,
            sSecretBaseEntrancePositions[offset + 2],
            sSecretBaseEntrancePositions[offset + 3]);
        WarpIntoMap();
        gFieldCallback = EnterNewlyCreatedSecretBase_StartFadeIn;
        SetMainCallback2(CB2_LoadMap);
        DestroyTask(taskId);
    }
}

void EnterNewlyCreatedSecretBase(void)
{
    CreateTask(Task_EnterNewlyCreatedSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
}

bool8 CurMapIsSecretBase(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SECRET_BASE_RED_CAVE1)
     && (u8)gSaveBlock1Ptr->location.mapNum <= MAP_NUM(SECRET_BASE_SHRUB4))
        return TRUE;
    else
        return FALSE;
}

void InitSecretBaseAppearance(bool8 hidePC)
{
    u16 secretBaseId;
    u16 x, y;
    u8 *decorations;
    u8 *decorPos;

    if (CurMapIsSecretBase())
    {
        secretBaseId = VarGet(VAR_CURRENT_SECRET_BASE);
        decorations = gSaveBlock1Ptr->secretBases[secretBaseId].decorations;
        decorPos = gSaveBlock1Ptr->secretBases[secretBaseId].decorationPositions;
        for (x = 0; x < 16; x++)
        {
            if (decorations[x] > 0 && decorations[x] <= NUM_DECORATIONS && gDecorations[decorations[x]].permission != DECORPERM_SPRITE)
                ShowDecorationOnMap((decorPos[x] >> 4) + 7, (decorPos[x] & 0xF) + 7, decorations[x]);
        }

        if (secretBaseId != 0)
        {
            // Another player's secret base. Change PC type to the "Register" PC.
            FindMetatileIdMapCoords(&x, &y, 0x220);
            MapGridSetMetatileIdAt(x + 7, y + 7, 0x221 | METATILE_COLLISION_MASK);
        }
        else if (hidePC == TRUE && VarGet(VAR_SECRET_BASE_INITIALIZED) == 1)
        {
            // Change PC to regular ground tile.
            FindMetatileIdMapCoords(&x, &y, 0x220);
            MapGridSetMetatileIdAt(x + 7, y + 7, 0x20a | METATILE_COLLISION_MASK);
        }
    }
}

void InitSecretBaseDecorationSprites(void)
{
    u8 i;
    u8 *decorations;
    u8 *decorationPositions;
    u8 eventObjectId;
    u8 metatileBehavior;
    u8 category;
    u8 permission;
    u8 numDecorations;

    eventObjectId = 0;
    if (!CurMapIsSecretBase())
    {
        decorations = gSaveBlock1Ptr->playerRoomDecor;
        decorationPositions = gSaveBlock1Ptr->playerRoomDecorPos;
        numDecorations = 12;
    }
    else
    {
        u16 secretBaseId = VarGet(VAR_CURRENT_SECRET_BASE);
        decorations = gSaveBlock1Ptr->secretBases[secretBaseId].decorations;
        decorationPositions = gSaveBlock1Ptr->secretBases[secretBaseId].decorationPositions;
        numDecorations = 16;
    }

    for (i = 0; i < numDecorations; i++)
    {
        if (decorations[i] == DECOR_NONE)
            continue;
        
        permission = gDecorations[decorations[i]].permission;
        category = gDecorations[decorations[i]].category;
        if (permission == DECORPERM_SPRITE)
        {
            for (eventObjectId = 0; eventObjectId < gMapHeader.events->eventObjectCount; eventObjectId++)
            {
                if (gMapHeader.events->eventObjects[eventObjectId].flagId == FLAG_DECORATION_1 + gSpecialVar_0x8004)
                    break;
            }

            if (eventObjectId == gMapHeader.events->eventObjectCount)
                continue;

            gSpecialVar_0x8006 = decorationPositions[i] >> 4;
            gSpecialVar_0x8007 = decorationPositions[i] & 0xF;
            metatileBehavior = MapGridGetMetatileBehaviorAt(gSpecialVar_0x8006 + 7, gSpecialVar_0x8007 + 7);
            if (MetatileBehavior_HoldsSmallDecoration(metatileBehavior) == TRUE
             || MetatileBehavior_HoldsLargeDecoration(metatileBehavior) == TRUE)
            {
                gSpecialVar_Result = VAR_OBJ_GFX_ID_0 + (gMapHeader.events->eventObjects[eventObjectId].graphicsId - EVENT_OBJ_GFX_VAR_0);
                VarSet(gSpecialVar_Result, gDecorations[decorations[i]].tiles[0]);
                gSpecialVar_Result = gMapHeader.events->eventObjects[eventObjectId].localId;
                FlagClear(FLAG_DECORATION_1 + gSpecialVar_0x8004);
                TrySpawnEventObject(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
                TryMoveEventObjectToMapCoords(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
                TryOverrideEventObjectTemplateCoords(gSpecialVar_Result, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
                if (CurMapIsSecretBase() == TRUE && VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                {
                    if (category == DECORCAT_DOLL)
                    {
                        OverrideSecretBaseDecorationSpriteScript(
                            gSpecialVar_Result,
                            gSaveBlock1Ptr->location.mapNum,
                            gSaveBlock1Ptr->location.mapGroup,
                            DECORCAT_DOLL);
                    }
                    else if (category == DECORCAT_CUSHION)
                    {
                        OverrideSecretBaseDecorationSpriteScript(
                            gSpecialVar_Result,
                            gSaveBlock1Ptr->location.mapNum,
                            gSaveBlock1Ptr->location.mapGroup,
                            DECORCAT_CUSHION);
                    }
                }

                gSpecialVar_0x8004++;
            }
        }
    }
}

void HideSecretBaseDecorationSprites(void)
{
    u8 eventObjectId;
    u16 flag;

    for (eventObjectId = 0; eventObjectId < gMapHeader.events->eventObjectCount; eventObjectId++)
    {
        flag = gMapHeader.events->eventObjects[eventObjectId].flagId;
        if (flag >= FLAG_DECORATION_1 && flag <= FLAG_DECORATION_14)
        {
            RemoveEventObjectByLocalIdAndMap(
                gMapHeader.events->eventObjects[eventObjectId].localId,
                gSaveBlock1Ptr->location.mapNum,
                gSaveBlock1Ptr->location.mapGroup);
            FlagSet(flag);
        }
    }
}

void SetSecretBaseOwnerGfxId(void)
{
    VarSet(VAR_OBJ_GFX_ID_F, sSecretBaseOwnerGfxIds[GetSecretBaseOwnerType(VarGet(VAR_CURRENT_SECRET_BASE))]);
}

void SetCurSecretBaseIdFromPosition(const struct MapPosition *position, const struct MapEvents *events)
{
    s16 i;
    for (i = 0; i < events->bgEventCount; i++)
    {
        if (events->bgEvents[i].kind == BG_EVENT_SECRET_BASE && position->x == events->bgEvents[i].x + 7 && position->y == events->bgEvents[i].y + 7)
        {
            sCurSecretBaseId = events->bgEvents[i].bgUnion.secretBaseId;
            break;
        }
    }
}

void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events)
{
    SetCurSecretBaseIdFromPosition(position, events);
    TrySetCurSecretBaseIndex();
    ScriptContext1_SetupScript(SecretBase_EventScript_Enter);
}

bool8 TrySetCurSecretBase(void)
{
    SetCurSecretBaseId();
    TrySetCurSecretBaseIndex();
    if (gSpecialVar_Result == TRUE)
        return FALSE;

    return TRUE;
}

static void Task_WarpOutOfSecretBase(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        ScriptContext2_Enable();
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        SetWarpDestinationToDynamicWarp(0x7e);
        WarpIntoMap();
        gFieldCallback = mapldr_default;
        SetMainCallback2(CB2_LoadMap);
        ScriptContext2_Disable();
        DestroyTask(taskId);
        break;
    }
}

static void WarpOutOfSecretBase(void)
{
    CreateTask(Task_WarpOutOfSecretBase, 0);
    FadeScreen(FADE_TO_BLACK, 0);
}

void IsCurSecretBaseOwnedByAnotherPlayer(void)
{
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId != sCurSecretBaseId)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

static u8 *GetSecretBaseName(u8 *dest, u8 secretBaseId)
{
    *StringCopyN(dest, gSaveBlock1Ptr->secretBases[secretBaseId].trainerName, GetNameLength(gSaveBlock1Ptr->secretBases[secretBaseId].trainerName)) = EOS;
    ConvertInternationalString(dest, gSaveBlock1Ptr->secretBases[secretBaseId].language);
    return StringAppend(dest, gText_ApostropheSBase);
}

u8 *GetSecretBaseMapName(u8 *dest)
{
    return GetSecretBaseName(dest, VarGet(VAR_CURRENT_SECRET_BASE));
}

void CopyCurSecretBaseOwnerName_StrVar1(void)
{
    u8 secretBaseId;
    const u8 *name;

    secretBaseId = VarGet(VAR_CURRENT_SECRET_BASE);
    name = gSaveBlock1Ptr->secretBases[secretBaseId].trainerName;
    *StringCopyN(gStringVar1, name, GetNameLength(name)) = EOS;
    ConvertInternationalString(gStringVar1, gSaveBlock1Ptr->secretBases[secretBaseId].language);
}

static bool8 IsSecretBaseRegistered(u8 secretBaseId)
{
    if (gSaveBlock1Ptr->secretBases[secretBaseId].registryStatus)
        return TRUE;

    return FALSE;
}

static u8 GetAverageEVs(struct Pokemon *pokemon)
{
    u16 evTotal;
    evTotal  = GetMonData(pokemon, MON_DATA_HP_EV);
    evTotal += GetMonData(pokemon, MON_DATA_ATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_DEF_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPEED_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPDEF_EV);
    return evTotal / 6;
}

void SetPlayerSecretBaseParty(void)
{
    u16 i;
    u16 moveIdx;
    u16 partyId;
    struct SecretBaseParty *party;

    partyId = 0;
    party = &gSaveBlock1Ptr->secretBases[0].party;
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            for (moveIdx = 0; moveIdx < MAX_MON_MOVES; moveIdx++)
                party->moves[i * MAX_MON_MOVES + moveIdx] = MOVE_NONE;

            party->species[i] = SPECIES_NONE;
            party->heldItems[i] = ITEM_NONE;
            party->levels[i] = 0;
            party->personality[i] = 0;
            party->EVs[i] = 0;

            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            {
                for (moveIdx = 0; moveIdx < MAX_MON_MOVES; moveIdx++)
                    party->moves[partyId * MAX_MON_MOVES + moveIdx] = GetMonData(&gPlayerParty[i], MON_DATA_MOVE1 + moveIdx);

                party->species[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
                party->heldItems[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
                party->levels[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
                party->personality[partyId] = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
                party->EVs[partyId] = GetAverageEVs(&gPlayerParty[i]);
                partyId++;
            }
        }
    }
}

void ClearAndLeaveSecretBase(void)
{
    u16 temp = gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlock1Ptr->secretBases[0]);
    gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived = temp;
    WarpOutOfSecretBase();
}

void MoveOutOfSecretBase(void)
{
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    ClearAndLeaveSecretBase();
}

static void ClosePlayerSecretBaseEntrance(void)
{
    u16 i;
    u16 j;
    s16 metatileId;
    const struct MapEvents *events = gMapHeader.events;

    for (i = 0; i < events->bgEventCount; i++)
    {
        if (events->bgEvents[i].kind == BG_EVENT_SECRET_BASE
         && gSaveBlock1Ptr->secretBases[0].secretBaseId == events->bgEvents[i].bgUnion.secretBaseId)
        {
            metatileId = MapGridGetMetatileIdAt(events->bgEvents[i].x + 7, events->bgEvents[i].y + 7);
            for (j = 0; j < 7; j++)
            {
                if (sSecretBaseEntranceMetatiles[j].openMetatileId == metatileId)
                {
                    MapGridSetMetatileIdAt(events->bgEvents[i].x + 7, events->bgEvents[i].y + 7, sSecretBaseEntranceMetatiles[j].closedMetatileId | METATILE_COLLISION_MASK);
                    break;
                }
            }

            DrawWholeMapView();
            break;
        }
    }
}

// When the player moves to a new secret base by interacting with a new secret base
// entrance in the overworld.
void MoveOutOfSecretBaseFromOutside(void)
{
    u16 temp;

    ClosePlayerSecretBaseEntrance();
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    temp = gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived;
    ClearSecretBase(&gSaveBlock1Ptr->secretBases[0]);
    gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived = temp;
}

static u8 GetNumRegisteredSecretBases(void)
{
    s16 i;
    u8 count = 0;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (IsSecretBaseRegistered(i) == TRUE)
            count++;
    }

    return count;
}

void GetCurSecretBaseRegistrationValidity(void)
{
    if (IsSecretBaseRegistered(VarGet(VAR_CURRENT_SECRET_BASE)) == TRUE)
        gSpecialVar_Result = 1;
    else if (GetNumRegisteredSecretBases() >= 10)
        gSpecialVar_Result = 2;
    else
        gSpecialVar_Result = 0;
}

void ToggleCurSecretBaseRegistry(void)
{
    gSaveBlock1Ptr->secretBases[VarGet(VAR_CURRENT_SECRET_BASE)].registryStatus ^= 1;
    FlagSet(FLAG_SECRET_BASE_REGISTRY_ENABLED);
}

void ShowSecretBaseDecorationMenu(void)
{
    CreateTask(DoSecretBaseDecorationMenu, 0);
}

void ShowSecretBaseRegistryMenu(void)
{
    CreateTask(Task_ShowSecretBaseRegistryMenu, 0);
}

static void Task_ShowSecretBaseRegistryMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ScriptContext2_Enable();
    data[0] = GetNumRegisteredSecretBases();
    if (data[0] != 0)
    {
        data[1] = 0;
        data[2] = 0;
        ClearDialogWindowAndFrame(0, 0);
        sRegistryMenu = calloc(1, sizeof(*sRegistryMenu));
        data[6] = AddWindow(&sRegistryWindowTemplates[0]);
        BuildRegistryMenuItems(taskId);
        FinalizeRegistryMenu(taskId);
        gTasks[taskId].func = HandleRegistryMenuInput;
    }
    else
    {
        DisplayItemMessageOnField(taskId, gText_NoRegistry, GoToSecretBasePCRegisterMenu);
    }
}

static void BuildRegistryMenuItems(u8 taskId)
{
    s16 *data;
    u8 i;
    u8 count;

    data = gTasks[taskId].data;
    count = 0;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (IsSecretBaseRegistered(i))
        {
            GetSecretBaseName(sRegistryMenu->names[count], i);
            sRegistryMenu->items[count].name = sRegistryMenu->names[count];
            sRegistryMenu->items[count].id = i;
            count++;
        }
    }

    sRegistryMenu->items[count].name = gText_Cancel;
    sRegistryMenu->items[count].id = -2;
    data[0] = count + 1;
    if (data[0] < 8)
        data[3] = data[0];
    else
        data[3] = 8;

    gMultiuseListMenuTemplate = sRegistryListMenuTemplate;
    gMultiuseListMenuTemplate.windowId = data[6];
    gMultiuseListMenuTemplate.totalItems = data[0];
    gMultiuseListMenuTemplate.items = sRegistryMenu->items;
    gMultiuseListMenuTemplate.maxShowed = data[3];
}

static void RegistryMenu_OnCursorMove(s32 unused, bool8 flag, struct ListMenu *menu)
{
    if (flag != TRUE)
        PlaySE(SE_SELECT);
}

static void FinalizeRegistryMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    SetStandardWindowBorderStyle(data[6], 0);
    data[5] = ListMenuInit(&gMultiuseListMenuTemplate, data[2], data[1]);
    AddRegistryMenuScrollArrows(taskId);
    schedule_bg_copy_tilemap_to_vram(0);
}

static void AddRegistryMenuScrollArrows(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[8] = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 0xbc, 0x0c, 0x94, data[0] - data[3], 0x13f8, 0x13f8, &data[2]);
}

static void HandleRegistryMenuInput(u8 taskId)
{
    s16 *data;
    s32 input;

    data = gTasks[taskId].data;
    input = ListMenu_ProcessInput(data[5]);
    ListMenuGetScrollAndRow(data[5], &data[2], &data[1]);
    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        PlaySE(SE_SELECT);
        DestroyListMenuTask(data[5], NULL, NULL);
        RemoveScrollIndicatorArrowPair(data[8]);
        ClearStdWindowAndFrame(data[6], 0);
        ClearWindowTilemap(data[6]);
        RemoveWindow(data[6]);
        schedule_bg_copy_tilemap_to_vram(0);
        free(sRegistryMenu);
        GoToSecretBasePCRegisterMenu(taskId);
        break;
    default:
        PlaySE(SE_SELECT);
        data[4] = input;
        ShowRegistryMenuActions(taskId);
        break;
    }
}

static void ShowRegistryMenuActions(u8 taskId)
{
    struct WindowTemplate template;
    s16 *data = gTasks[taskId].data;
    RemoveScrollIndicatorArrowPair(data[8]);
    template = sRegistryWindowTemplates[1];
    template.width = GetMaxWidthInMenuTable(sRegistryMenuActions, 2);
    data[7] = AddWindow(&template);
    SetStandardWindowBorderStyle(data[7], 0);
    PrintMenuTable(data[7], 2, sRegistryMenuActions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(data[7], 2, 0);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = HandleRegistryMenuActionsInput;
}

static void HandleRegistryMenuActionsInput(u8 taskId)
{
    s8 input = Menu_ProcessInputNoWrap();
    switch (input)
    {
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        ReturnToMainRegistryMenu(taskId);
        break;
    case MENU_NOTHING_CHOSEN:
        break;
    default:
        PlaySE(SE_SELECT);
        sRegistryMenuActions[input].func.void_u8(taskId);
        break;
    }
}

static void ShowRegistryMenuDeleteConfirmation(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ClearStdWindowAndFrame(data[6], FALSE);
    ClearStdWindowAndFrame(data[7], FALSE);
    ClearWindowTilemap(data[6]);
    ClearWindowTilemap(data[7]);
    RemoveWindow(data[7]);
    schedule_bg_copy_tilemap_to_vram(0);
    GetSecretBaseName(gStringVar1, data[4]);
    StringExpandPlaceholders(gStringVar4, gText_OkayToDeleteFromRegistry);
    DisplayItemMessageOnField(taskId, gStringVar4, ShowRegistryMenuDeleteYesNo);
}

static void ShowRegistryMenuDeleteYesNo(u8 taskId)
{
    DisplayYesNoMenuDefaultYes();
    DoYesNoFuncWithChoice(taskId, &sDeleteRegistryYesNoFuncs);
}

void DeleteRegistry_Yes_Callback(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ClearDialogWindowAndFrame(0, 0);
    DestroyListMenuTask(data[5], &data[2], &data[1]);
    gSaveBlock1Ptr->secretBases[data[4]].registryStatus = 0;
    BuildRegistryMenuItems(taskId);
    sub_812225C(&data[2], &data[1], data[3], data[0]);
    FinalizeRegistryMenu(taskId);
    gTasks[taskId].func = HandleRegistryMenuInput;
}

static void DeleteRegistry_Yes(u8 taskId)
{
    DisplayItemMessageOnField(taskId, gText_RegisteredDataDeleted, DeleteRegistry_Yes_Callback);
}

static void DeleteRegistry_No(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    ClearDialogWindowAndFrame(0, 0);
    DestroyListMenuTask(data[5], &data[2], &data[1]);
    FinalizeRegistryMenu(taskId);
    gTasks[taskId].func = HandleRegistryMenuInput;
}

static void ReturnToMainRegistryMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    AddRegistryMenuScrollArrows(taskId);
    ClearStdWindowAndFrame(data[7], 0);
    ClearWindowTilemap(data[7]);
    RemoveWindow(data[7]);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = HandleRegistryMenuInput;
}

static void GoToSecretBasePCRegisterMenu(u8 taskId)
{
    if (VarGet(VAR_CURRENT_SECRET_BASE) == 0)
        ScriptContext1_SetupScript(SecretBase_EventScript_PCCancel);
    else
        ScriptContext1_SetupScript(SecretBase_EventScript_ShowRegisterMenu);

    DestroyTask(taskId);
}

static u8 GetSecretBaseOwnerType(u8 secretBaseId)
{
    return (gSaveBlock1Ptr->secretBases[secretBaseId].trainerId[0] % 5)
         + (gSaveBlock1Ptr->secretBases[secretBaseId].gender * 5);
}

const u8 *GetSecretBaseTrainerLoseText(void)
{
    u8 ownerType = GetSecretBaseOwnerType(VarGet(VAR_CURRENT_SECRET_BASE));
    if (ownerType == 0)
        return SecretBase_Text_Trainer0Defeated;
    else if (ownerType == 1)
        return SecretBase_Text_Trainer1Defeated;
    else if (ownerType == 2)
        return SecretBase_Text_Trainer2Defeated;
    else if (ownerType == 3)
        return SecretBase_Text_Trainer3Defeated;
    else if (ownerType == 4)
        return SecretBase_Text_Trainer4Defeated;
    else if (ownerType == 5)
        return SecretBase_Text_Trainer5Defeated;
    else if (ownerType == 6)
        return SecretBase_Text_Trainer6Defeated;
    else if (ownerType == 7)
        return SecretBase_Text_Trainer7Defeated;
    else if (ownerType == 8)
        return SecretBase_Text_Trainer8Defeated;
    else
        return SecretBase_Text_Trainer9Defeated;
}

void PrepSecretBaseBattleFlags(void)
{
    sub_813BADC(1);
    gTrainerBattleOpponent_A = TRAINER_SECRET_BASE;
    gBattleTypeFlags = BATTLE_TYPE_TRAINER | BATTLE_TYPE_SECRET_BASE;
}

void SetBattledOwnerFromResult(void)
{
    gSaveBlock1Ptr->secretBases[VarGet(VAR_CURRENT_SECRET_BASE)].battledOwnerToday = gSpecialVar_Result;
}

void GetSecretBaseOwnerAndState(void)
{
    u16 secretBaseId;
    u8 i;

    secretBaseId = VarGet(VAR_CURRENT_SECRET_BASE);
    if (!FlagGet(FLAG_DAILY_SECRET_BASE))
    {
        for (i = 0; i < SECRET_BASES_COUNT; i++)
            gSaveBlock1Ptr->secretBases[i].battledOwnerToday = FALSE;

        FlagSet(FLAG_DAILY_SECRET_BASE);
    }
    gSpecialVar_0x8004 = GetSecretBaseOwnerType(secretBaseId);
    gSpecialVar_Result = gSaveBlock1Ptr->secretBases[secretBaseId].battledOwnerToday;
}

void SecretBasePerStepCallback(u8 taskId)
{
    s16 x;
    s16 y;
    u8 behavior;
    u16 tileId;
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[1])
    {
    case 0:
        if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
            sInFriendSecretBase = TRUE;
        else
            sInFriendSecretBase = FALSE;

        PlayerGetDestCoords(&data[2], &data[3]);
        data[1] = 1;
        break;
    case 1:
        PlayerGetDestCoords(&x, &y);
        if (x != data[2] || y != data[3])
        {
            data[2] = x;
            data[3] = y;
            VarSet(VAR_SECRET_BASE_STEP_COUNTER, VarGet(VAR_SECRET_BASE_STEP_COUNTER) + 1);
            behavior = MapGridGetMetatileBehaviorAt(x, y);
            tileId = MapGridGetMetatileIdAt(x, y);
            if (tileId == 0x234 || tileId == 0x23C)
            {
                if (sInFriendSecretBase == TRUE)
                {
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x20);
                }
            }
            else if (tileId == 0x2b8 || tileId == 0x2b9 || tileId == 0x2ba || tileId == 0x2c0 || tileId == 0x2c1 || tileId == 0x2c2 || tileId == 0x2c8 || tileId == 0x2c9 || tileId == 0x2ca)
            {
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x01);
            }
            else if (tileId == 0x239 || tileId == 0x241 || tileId == 0x251 || tileId == 0x259)
            {
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x04);
            }
            else if ((behavior == 0x34 && tileId == 0x26d) || (behavior == 0x35 && MapGridGetMetatileIdAt(x, y) == 0x26a))
            {
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x200);
            }
            else if (behavior == 0xc1 && tileId == 0x23d)
            {
                if (sInFriendSecretBase == TRUE)
                {
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) ^ 0x1000);
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x2000);
                }
            }
            else if (behavior == 0x47 && tileId == 0x23e)
            {
                if (sInFriendSecretBase == TRUE)
                {
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x1000);
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) ^ 0x2000);
                }
            }
            else if (MetatileBehavior_IsSecretBaseGlitterMat(behavior) == TRUE)
            {
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x80);
            }
            else if (MetatileBehavior_IsSecretBaseBalloon(behavior) == TRUE)
            {
                PopSecretBaseBalloon(MapGridGetMetatileIdAt(x, y), x, y);
                if (sInFriendSecretBase == TRUE)
                {
                    switch ((int)MapGridGetMetatileIdAt(x, y))
                    {
                    case 0x338:
                    case 0x33c:
                    case 0x340:
                        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x02);
                        break;
                    case 0x228:
                        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x100);
                        break;
                    }
                }
            }
            else if (MetatileBehavior_IsSecretBaseBreakableDoor(behavior) == TRUE)
            {
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x400);

                ShatterSecretBaseBreakableDoor(x, y);
            }
            else if (MetatileBehavior_IsSecretBaseSoundMat(behavior) == TRUE){
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x8000);
            }
            else if (MetatileBehavior_IsSecretBaseJumpMat(behavior) == TRUE)
            {
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x4000);
            }
            else if (MetatileBehavior_IsSecretBaseSpinMat(behavior) == TRUE)
            {
                if (sInFriendSecretBase == TRUE)
                    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x02);
            }
        }
        break;
    case 2:
        if (!FieldEffectActiveListContains(data[4]))
            data[1] = 1;
        break;
    }
}

static void SetSecretBaseDataAndLanguage(u8 secretBaseId, struct SecretBase *secretBase, u32 version, u32 language)
{
    int stringLength;
    u8 *name;

    gSaveBlock1Ptr->secretBases[secretBaseId] = *secretBase;
    gSaveBlock1Ptr->secretBases[secretBaseId].registryStatus = 2;
    if (version == VERSION_SAPPHIRE || version == VERSION_RUBY)
        gSaveBlock1Ptr->secretBases[secretBaseId].language = LANGUAGE_ENGLISH;

    if (version == VERSION_EMERALD && language == LANGUAGE_JAPANESE)
    {
        name = gSaveBlock1Ptr->secretBases[secretBaseId].trainerName;
        for (stringLength = 0; stringLength < 7; stringLength++)
        {
            if (name[stringLength] == EOS)
                break;
        }

        if (stringLength > 5)
            gSaveBlock1Ptr->secretBases[secretBaseId].language = LANGUAGE_ENGLISH;
    }
}

static bool8 SecretBasesHaveSameTrainerId(struct SecretBase *secretBase1, struct SecretBase *secretBase2)
{
    u8 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
    {
        if (secretBase1->trainerId[i] != secretBase2->trainerId[i])
            return FALSE;
    }

    return TRUE;
}

static bool8 SecretBasesHaveSameTrainerName(struct SecretBase *sbr1, struct SecretBase *sbr2)
{
    u8 i;
    for (i = 0; i < PLAYER_NAME_LENGTH && (sbr1->trainerName[i] != EOS || sbr2->trainerName[i] != EOS); i++)
    {
        if (sbr1->trainerName[i] != sbr2->trainerName[i])
            return FALSE;
    }

    return TRUE;
}

static bool8 SecretBasesBelongToSamePlayer(struct SecretBase *secretBase1, struct SecretBase *secretBase2)
{
    if (secretBase1->gender == secretBase2->gender
     && SecretBasesHaveSameTrainerId(secretBase1, secretBase2)
     && SecretBasesHaveSameTrainerName(secretBase1, secretBase2))
    {
        return TRUE;
    }

    return FALSE;
}

static s16 GetSecretBaseIndexFromId(u8 secretBaseId)
{
    s16 i;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (gSaveBlock1Ptr->secretBases[i].secretBaseId == secretBaseId)
            return i;
    }

    return -1;
}

static u8 FindAvailableSecretBaseIndex(void)
{
    s16 i;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (gSaveBlock1Ptr->secretBases[i].secretBaseId == 0)
            return i;
    }

    return 0;
}

static u8 sub_80EAA18(void)
{
    s16 i;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (gSaveBlock1Ptr->secretBases[i].registryStatus == 0 && gSaveBlock1Ptr->secretBases[i].sbr_field_1_0 == 0)
            return i;
    }

    return 0;
}

static u8 sub_80EAA64(struct SecretBase *secretBase, u32 version, u32 language)
{
    s16 index;

    if (!secretBase->secretBaseId)
        return 0;

    index = GetSecretBaseIndexFromId(secretBase->secretBaseId);
    if (index != 0)
    {
        if (index != -1)
        {
            if (gSaveBlock1Ptr->secretBases[index].sbr_field_1_0 == 1)
                return 0;

            if (gSaveBlock1Ptr->secretBases[index].registryStatus != 2 || secretBase->sbr_field_1_0 == 1)
            {
                SetSecretBaseDataAndLanguage(index, secretBase, version, language);
                return index;
            }
        }
        else
        {
            index = FindAvailableSecretBaseIndex();
            if (index != 0)
            {
                SetSecretBaseDataAndLanguage(index, secretBase, version, language);
                return index;
            }

            index = sub_80EAA18();
            if (index != 0)
            {
                SetSecretBaseDataAndLanguage(index, secretBase, version, language);
                return index;
            }
        }
    }
    return 0;
}

// Moves the registered secret bases to the beginning of the array, so that
// they won't be forgotten during record mixing.
static void SortSecretBasesByRegistryStatus(void)
{
    u8 i;
    u8 j;
    struct SecretBase *secretBases;

    secretBases = gSaveBlock1Ptr->secretBases;
    for (i = 1; i < 19; i++)
    {
        for (j = i + 1; j < SECRET_BASES_COUNT; j++)
        {
            if ((secretBases[i].registryStatus == 0 && secretBases[j].registryStatus == 1) || (secretBases[i].registryStatus == 2 && secretBases[j].registryStatus != 2))
            {
                struct SecretBase temp = secretBases[i];
                secretBases[i] = secretBases[j];
                secretBases[j] = temp;
            }
        }
    }
}

void sub_80EABA4(struct SecretBaseRecordMixer *mixer, u8 registryStatus)
{
    u16 i;
    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (mixer->secretBases[i].registryStatus == registryStatus)
            sub_80EAA64(&mixer->secretBases[i], mixer->version, mixer->language);
    }
}

bool8 SecretBaseBelongsToPlayer(struct SecretBase *secretBase)
{
    u8 i;

    if (secretBase->secretBaseId == 0)
        return FALSE;

    if (secretBase->secretBaseId && secretBase->gender != gSaveBlock2Ptr->playerGender)
        return FALSE;

    // Check if the player's trainer Id matches the secret base's id.
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
    {
        if (secretBase->trainerId[i] != gSaveBlock2Ptr->playerTrainerId[i])
            return FALSE;
    }

    for (i = 0; i < PLAYER_NAME_LENGTH && (secretBase->trainerName[i] != EOS || gSaveBlock2Ptr->playerName[i] != EOS); i++)
    {
        if (secretBase->trainerName[i] != gSaveBlock2Ptr->playerName[i])
            return FALSE;
    }

    return TRUE;
}

void DeleteFirstOldBaseFromPlayerInRecordMixingFriendsRecords(struct SecretBase *basesA, struct SecretBase *basesB, struct SecretBase *basesC)
{
    u8 i;
    u8 sbFlags = 0x0;

    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (!(sbFlags & 0x1)) // 001
        {
            if (SecretBaseBelongsToPlayer(&basesA[i]) == TRUE)
            {
                ClearSecretBase(&basesA[i]);
                sbFlags |= 1;
            }
        }

        if (!(sbFlags & 0x2)) // 010
        {
            if (SecretBaseBelongsToPlayer(&basesB[i]) == TRUE)
            {
                ClearSecretBase(&basesB[i]);
                sbFlags |= 2;
            }
        }

        if (!(sbFlags & 0x4)) // 100
        {
            if (SecretBaseBelongsToPlayer(&basesC[i]) == TRUE)
            {
                ClearSecretBase(&basesC[i]);
                sbFlags |= 4;
            }
        }

        if (sbFlags == 0x7) // 111
        {
            break;
        }
    }
}

bool8 sub_80EAD14(struct SecretBase *secretBase, struct SecretBase *secretBases, u8 c)
{
    u8 i;

    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (secretBases[i].secretBaseId != 0)
        {
            if (SecretBasesBelongToSamePlayer(secretBase, &secretBases[i]) == TRUE)
            {
                if (c == 0)
                {
                    ClearSecretBase(&secretBases[i]);
                    return FALSE;
                }

                if (secretBase->numSecretBasesReceived > secretBases[i].numSecretBasesReceived)
                {
                    ClearSecretBase(&secretBases[i]);
                    return FALSE;
                }

                secretBases[i].sbr_field_1_0 = secretBase->sbr_field_1_0;
                ClearSecretBase(secretBase);
                return TRUE;
            }
        }
    }

    return FALSE;
}

void sub_80EAD94(struct SecretBase *basesA, struct SecretBase *basesB, struct SecretBase *basesC, struct SecretBase *basesD)
{
    u8 i;

    for (i = 1; i < SECRET_BASES_COUNT; i++)
    {
        if (basesA[i].secretBaseId)
        {
            if (basesA[i].registryStatus == 1)
            {
                basesA[i].sbr_field_1_0 = 1;
            }
            if (!sub_80EAD14(&basesA[i], basesB, i))
            {
                if (!sub_80EAD14(&basesA[i], basesC, i))
                {
                    sub_80EAD14(&basesA[i], basesD, i);
                }
            }
        }
    }
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (basesB[i].secretBaseId)
        {
            basesB[i].battledOwnerToday = 0;
            if (!sub_80EAD14(&basesB[i], basesC, i))
            {
                sub_80EAD14(&basesB[i], basesD, i);
            }
        }
    }
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (basesC[i].secretBaseId)
        {
            basesC[i].battledOwnerToday = 0;
            sub_80EAD14(&basesC[i], basesD, i);
        }
        if (basesD[i].secretBaseId)
        {
            basesD[i].battledOwnerToday = 0;
        }
    }
}

void sub_80EAE90(struct SecretBase *base, u32 version, u32 language)
{
    if (base->sbr_field_1_0 == 1)
    {
        sub_80EAA64(base, version, language);
        ClearSecretBase(base);
    }
}

void sub_80EAEB4(struct SecretBaseRecordMixer *mixers)
{
    u16 i;

    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        sub_80EAE90(&mixers[0].secretBases[i], mixers[0].version, mixers[0].language);
        sub_80EAE90(&mixers[1].secretBases[i], mixers[1].version, mixers[1].language);
        sub_80EAE90(&mixers[2].secretBases[i], mixers[2].version, mixers[2].language);
    }
}

void sub_80EAEF4(struct SecretBaseRecordMixer *mixers)
{
    DeleteFirstOldBaseFromPlayerInRecordMixingFriendsRecords(mixers[0].secretBases, mixers[1].secretBases, mixers[2].secretBases);
    sub_80EAD94(gSaveBlock1Ptr->secretBases, mixers[0].secretBases, mixers[1].secretBases, mixers[2].secretBases);
    sub_80EAEB4(mixers);
    sub_80EAA64(mixers[0].secretBases, mixers[0].version, mixers[0].language);
    sub_80EAA64(mixers[1].secretBases, mixers[1].version, mixers[1].language);
    sub_80EAA64(mixers[2].secretBases, mixers[2].version, mixers[2].language);
    sub_80EABA4(&mixers[0], 1);
    sub_80EABA4(&mixers[1], 1);
    sub_80EABA4(&mixers[2], 1);
    sub_80EABA4(&mixers[0], 0);
    sub_80EABA4(&mixers[1], 0);
    sub_80EABA4(&mixers[2], 0);
}

void ReceiveSecretBasesData(void *secretBases, size_t recordSize, u8 linkIdx)
{
    struct SecretBaseRecordMixer mixers[3];
    u16 i;

    if (FlagGet(FLAG_RECEIVED_SECRET_POWER))
    {
        switch (GetLinkPlayerCount())
        {
        case 2:
            memset(secretBases + 2 * recordSize, 0, recordSize);
            memset(secretBases + 3 * recordSize, 0, recordSize);
            break;
        case 3:
            memset(secretBases + 3 * recordSize, 0, recordSize);
            break;
        }

        switch (linkIdx)
        {
        case 0:
            mixers[0].secretBases = secretBases + 1 * recordSize;
            mixers[0].version = gLinkPlayers[1].version & 0xFF;
            mixers[0].language = gLinkPlayers[1].language;
            mixers[1].secretBases = secretBases + 2 * recordSize;
            mixers[1].version = gLinkPlayers[2].version & 0xFF;
            mixers[1].language = gLinkPlayers[2].language;
            mixers[2].secretBases = secretBases + 3 * recordSize;
            mixers[2].version = gLinkPlayers[3].version & 0xFF;
            mixers[2].language = gLinkPlayers[3].language;
            break;
        case 1:
            mixers[0].secretBases = secretBases + 2 * recordSize;
            mixers[0].version = gLinkPlayers[2].version & 0xFF;
            mixers[0].language = gLinkPlayers[2].language;
            mixers[1].secretBases = secretBases + 3 * recordSize;
            mixers[1].version = gLinkPlayers[3].version & 0xFF;
            mixers[1].language = gLinkPlayers[3].language;
            mixers[2].secretBases = secretBases + 0 * recordSize;
            mixers[2].version = gLinkPlayers[0].version & 0xFF;
            mixers[2].language = gLinkPlayers[0].language;
            break;
        case 2:
            mixers[0].secretBases = secretBases + 3 * recordSize;
            mixers[0].version = gLinkPlayers[3].version & 0xFF;
            mixers[0].language = gLinkPlayers[3].language;
            mixers[1].secretBases = secretBases + 0 * recordSize;
            mixers[1].version = gLinkPlayers[0].version & 0xFF;
            mixers[1].language = gLinkPlayers[0].language;
            mixers[2].secretBases = secretBases + 1 * recordSize;
            mixers[2].version = gLinkPlayers[1].version & 0xFF;
            mixers[2].language = gLinkPlayers[1].language;
            break;
        case 3:
            mixers[0].secretBases = secretBases + 0 * recordSize;
            mixers[0].version = gLinkPlayers[0].version & 0xFF;
            mixers[0].language = gLinkPlayers[0].language;
            mixers[1].secretBases = secretBases + 1 * recordSize;
            mixers[1].version = gLinkPlayers[1].version & 0xFF;
            mixers[1].language = gLinkPlayers[1].language;
            mixers[2].secretBases = secretBases + 2 * recordSize;
            mixers[2].version = gLinkPlayers[2].version & 0xFF;
            mixers[2].language = gLinkPlayers[2].language;
            break;
        }

        sub_80EAEF4(mixers);
        for (i = 1; i < SECRET_BASES_COUNT; i++)
        {
            if (gSaveBlock1Ptr->secretBases[i].sbr_field_1_0 == 1)
            {
                gSaveBlock1Ptr->secretBases[i].registryStatus = 1;
                gSaveBlock1Ptr->secretBases[i].sbr_field_1_0 = 0;
            }
        }

        SortSecretBasesByRegistryStatus();
        for (i = 1; i < SECRET_BASES_COUNT; i++)
        {
            if (gSaveBlock1Ptr->secretBases[i].registryStatus == 2)
            {
                gSaveBlock1Ptr->secretBases[i].registryStatus = 0;
            }
        }

        if (gSaveBlock1Ptr->secretBases[0].secretBaseId != 0
         && gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived != 0xFFFF)
        {
            gSaveBlock1Ptr->secretBases[0].numSecretBasesReceived++;
        }
    }
}

void ClearJapaneseSecretBases(struct SecretBase *bases)
{
    u32 i;
    for (i = 0; i < SECRET_BASES_COUNT; i++)
    {
        if (bases[i].language == LANGUAGE_JAPANESE)
            ClearSecretBase(&bases[i]);
    }
}

void InitSecretBaseVars(void)
{
    VarSet(VAR_SECRET_BASE_STEP_COUNTER, 0);
    VarSet(VAR_SECRET_BASE_LAST_ITEM_USED, 0);
    VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, 0);
    VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, 0);
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        VarSet(VAR_SECRET_BASE_IS_NOT_LOCAL, TRUE);
    else
        VarSet(VAR_SECRET_BASE_IS_NOT_LOCAL, FALSE);

    sInFriendSecretBase = FALSE;
}

void sub_80EB218(void)
{
    if (VarGet(VAR_SECRET_BASE_IS_NOT_LOCAL) && sInFriendSecretBase == TRUE && !CurMapIsSecretBase())
    {
        VarSet(VAR_SECRET_BASE_IS_NOT_LOCAL, FALSE);
        sInFriendSecretBase = FALSE;
        sub_80EEA70();
        VarSet(VAR_SECRET_BASE_STEP_COUNTER, 0);
        VarSet(VAR_SECRET_BASE_LAST_ITEM_USED, 0);
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, 0);
        VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, 0);
        VarSet(VAR_SECRET_BASE_IS_NOT_LOCAL, FALSE);
    }
}

void sub_80EB290(void)
{
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x800);
}

void sub_80EB2C8(void)
{
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x400);
}

void sub_80EB300(void)
{
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
    {
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) & ~0x3800);
        VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) & ~0x001);
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x2000);
    }
}

void sub_80EB368(void)
{
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
    {
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) & ~0x3800);
        VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) & ~0x001);
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x800);
    }
}

void sub_80EB3D0(void)
{
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
    {
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) & ~0x3800);
        VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) & ~0x001);
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x1000);
    }
}

void sub_80EB438(void)
{
    if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
    {
        VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) & ~0x3800);
        VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) & ~0x001);
        VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x001);
    }
}

void SetSecretBaseSecretsTvFlags_Poster(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case 0x31C:
        case 0x31D:
        case 0x31E:
        case 0x31F:
        case 0x324:
        case 0x325:
        case 0x326:
        case 0x327:
        case 0x32C:
        case 0x32D:
        case 0x330:
        case 0x331:
        case 0x332:
        case 0x333:
        case 0x334:
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x4000);
            break;
    }
}

void SetSecretBaseSecretsTvFlags_MiscFurnature(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case 0x28a:
        case 0x28b:
            // Bird Statue
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x40);
            break;
        case 0x2d8:
        case 0x2d9:
        case 0x2da:
        case 0x2db:
        case 0x2dc:
        case 0x2dd:
        case 0x2e8:
        case 0x2e9:
        case 0x2ea:
        case 0x2eb:
        case 0x2ec:
        case 0x2ed:
        case 0x2ee:
        case 0x2ef:
        case 0x2f8:
        case 0x2f9:
        case 0x2fa:
        case 0x2fb:
            // Plants
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_LOW_TV_FLAGS, VarGet(VAR_SECRET_BASE_LOW_TV_FLAGS) | 0x8);
            break;
        case 0x22c:
        case 0x233:
            // Fence
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x40);
            break;
        case 0x288:
        case 0x289:
            // Tire
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x100);
            break;
        case 0x22d:
        case 0x22e:
        case 0x22f:
            // Bricks
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x10);
            break;
        case 0x287:
        case 0x28f:
        case 0x298:
        case 0x299:
        case 0x29a:
        case 0x29b:
        case 0x29c:
        case 0x29d:
        case 0x29e:
        case 0x29f:
        case 0x2ab:
        case 0x2b0:
        case 0x2b1:
        case 0x2b2:
        case 0x2b4:
        case 0x2b5:
        case 0x2b6:
        case 0x2b7:
        case 0x2cb:
        case 0x2cc:
        case 0x2cd:
        case 0x2ce:
        case 0x2cf:
            // Tables
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x8);
            break;
    }
}

void SetSecretBaseSecretsTvFlags_LargeDecorationSpot(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case 0x291:
        case 0x294:
        case 0x297:
        case 0x2a1:
        case 0x2a5:
        case 0x2a9:
        case 0x2ad:
        case 0x2bb:
        case 0x2be:
        case 0x2c3:
        case 0x2c6:
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x8);
            break;
    }
}

void SetSecretBaseSecretsTvFlags_SmallDecorationSpot(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch (MapGridGetMetatileIdAt(x, y))
    {
        case 0x290:
        case 0x292:
        case 0x293:
        case 0x295:
        case 0x296:
        case 0x2a0:
        case 0x2a2:
        case 0x2a3:
        case 0x2a4:
        case 0x2a6:
        case 0x2a7:
        case 0x2a8:
        case 0x2aa:
        case 0x2ac:
        case 0x2ae:
        case 0x2af:
        case 0x2bc:
        case 0x2bd:
        case 0x2bf:
        case 0x2c4:
        case 0x2c5:
        case 0x2c7:
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x8);
            break;
        case 0x280:
        case 0x281:
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x100);
            break;
        case 0x225:
        case 0x226:
        case 0x227:
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x10);
            break;
    }
}

void SetSecretBaseSecretsTvFlags_SandOrnament(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    switch ((int)MapGridGetMetatileIdAt(x, y))
    {
        case 0x28d:
        case 0x28e:
            // Sand Ornament
            if (VarGet(VAR_CURRENT_SECRET_BASE) != 0)
                VarSet(VAR_SECRET_BASE_HIGH_TV_FLAGS, VarGet(VAR_SECRET_BASE_HIGH_TV_FLAGS) | 0x4);
            break;
    }
}
