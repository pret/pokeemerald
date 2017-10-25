
// Includes
#include "global.h"
#include "task.h"
#include "palette.h"
#include "list_menu.h"
#include "map_constants.h"
#include "overworld.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "field_screen.h"
#include "field_weather.h"
#include "field_map_obj.h"
#include "metatile_behavior.h"
#include "map_name_popup.h"
#include "text.h"
#include "string_util.h"
#include "script.h"
#include "event_data.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "secret_base.h"

// Static type declarations

struct SecretBaseListMenuBuffer {
    struct ListMenuItem items[11];
    u8 names[11][32];
};

// Static RAM declarations
EWRAM_DATA u8 sCurSecretBaseId = 0;
EWRAM_DATA u8 gUnknown_0203A01D = 0;
EWRAM_DATA struct SecretBaseListMenuBuffer *gUnknown_0203A020 = NULL;

// Static ROM declarations

// .rodata

extern const struct {
    u16 tile1;
    u16 tile2;
} gUnknown_0858CFCC[7];

extern const u8 gUnknown_0858CFE8[];

// .text

void sub_80E8AF0(struct SecretBaseRecord *sbr)
{
    u16 i;

    CpuFastFill16(0, sbr, sizeof(struct SecretBaseRecord));
    for (i = 0; i < 7; i ++)
    {
        sbr->trainerName[i] = EOS;
    }
}

void ResetSecretBases(void)
{
    u16 i;

    for (i = 0; i < 20; i ++)
    {
        sub_80E8AF0(&gSaveBlock1Ptr->secretBases[i]);
    }
}

void sub_80E8B58(void)
{
    sCurSecretBaseId = gSpecialVar_0x8004;
}

void sub_80E8B6C(void)
{
    u16 i;

    gScriptResult = FALSE;
    for (i = 0; i < 20; i ++)
    {
        if (sCurSecretBaseId != gSaveBlock1Ptr->secretBases[i].secretBaseId)
        {
            continue;
        }
        gScriptResult = TRUE;
        VarSet(VAR_0x4054, i);
        break;
    }
}

void sub_80E8BC8(void)
{
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId != 0)
    {
        gScriptResult = TRUE;
    }
    else
    {
        gScriptResult = FALSE;
    }
}

u8 sub_80E8BF8(void)
{
    s16 x;
    s16 y;
    s16 behavior;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y) & 0xFFF;
    if (behavior == 0x90 || behavior == 0x91)
    {
        return 1;
    }
    if (behavior == 0x92 || behavior == 0x93)
    {
        return 2;
    }
    if (behavior == 0x9a || behavior == 0x9b)
    {
        return 3;
    }
    if (behavior == 0x94 || behavior == 0x95)
    {
        return 4;
    }
    if (behavior == 0x96 || behavior == 0x97 || behavior == 0x9c || behavior == 0x9d)
    {
        return 5;
    }
    if (behavior == 0x98 || behavior == 0x99)
    {
        return 6;
    }
    return 0;
}

void sub_80E8C98(void)
{
    gSpecialVar_0x8007 = sub_80E8BF8();
}

void sub_80E8CB0(s16 *xPtr, s16 *yPtr, u16 tile)
{
    struct MapData *mapData;
    s16 x;
    s16 y;

    mapData = gMapHeader.mapData;
    for (y = 0; y < mapData->height; y ++)
    {
        for (x = 0; x < mapData->width; x ++)
        {
            if ((mapData->map[y * mapData->width + x] & 0x3ff) == tile)
            {
                *xPtr = x;
                *yPtr = y;
                return;
            }
        }
    }
}

void sub_80E8D4C(void)
{
    s16 x;
    s16 y;
    s16 tile;
    u16 i;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    tile = MapGridGetMetatileIdAt(x, y);
    for (i = 0; i < 7; i ++)
    {
        if (gUnknown_0858CFCC[i].tile1 == tile)
        {
            MapGridSetMetatileIdAt(x, y, gUnknown_0858CFCC[i].tile2 | 0xC00);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
    for (i = 0; i < 7; i ++)
    {
        if (gUnknown_0858CFCC[i].tile2 == tile)
        {
            MapGridSetMetatileIdAt(x, y, gUnknown_0858CFCC[i].tile1 | 0xC00);
            CurrentMapDrawMetatileAt(x, y);
            return;
        }
    }
}

u8 sub_80E8DF4(const u8 *src)
{
    u8 i;

    for (i = 0; i < 7; i ++)
    {
        if (src[i] == EOS)
        {
            return i;
        }
    }
    return 7;
}

void sub_80E8E18(void)
{
    u16 i;

    gSaveBlock1Ptr->secretBases[0].secretBaseId = sCurSecretBaseId;
    for (i = 0; i < 4; i ++)
    {
        gSaveBlock1Ptr->secretBases[0].trainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];
    }
    VarSet(VAR_0x4054, 0);
    StringCopyN(gSaveBlock1Ptr->secretBases[0].trainerName, gSaveBlock2Ptr->playerName, sub_80E8DF4(gSaveBlock2Ptr->playerName));
    gSaveBlock1Ptr->secretBases[0].gender = gSaveBlock2Ptr->playerGender;
    gSaveBlock1Ptr->secretBases[0].language = GAME_LANGUAGE;
    VarSet(VAR_SECRET_BASE_MAP, gMapHeader.regionMapSectionId);
}

void sub_80E8EE0(struct MapEvents *events)
{
    u16 bgevidx;
    u16 idx;
    u16 jdx;
    s16 tile_id;
    s16 x;
    s16 y;

    for (bgevidx = 0; bgevidx < events->bgEventCount; bgevidx ++)
    {
        if (events->bgEvents[bgevidx].kind == 8)
        {
            for (jdx = 0; jdx < 20; jdx ++)
            {
                if (gSaveBlock1Ptr->secretBases[jdx].secretBaseId == events->bgEvents[bgevidx].bgUnion.secretBaseId)
                {
                    x = events->bgEvents[bgevidx].x + 7;
                    y = events->bgEvents[bgevidx].y + 7;
                    tile_id = MapGridGetMetatileIdAt(x, y);
                    for (idx = 0; idx < 7; idx ++)
                    {
                        if (gUnknown_0858CFCC[idx].tile1 == tile_id)
                        {
                            MapGridSetMetatileIdAt(x, y, gUnknown_0858CFCC[idx].tile2 | 0xc00);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}

void sub_80E8F9C(void)
{
    s8 idx;

    idx = sCurSecretBaseId / 10 * 4;
    warp1_set_2(MAP_GROUP_SECRET_BASE_RED_CAVE1, gUnknown_0858CFE8[idx], gUnknown_0858CFE8[idx + 1]);
}

void sub_80E8FD0(u8 taskId)
{
    u16 sbrId;

    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].data[0] = 1;
            }
            break;
        case 1:
            sbrId = VarGet(VAR_0x4054);
            if (gSaveBlock1Ptr->secretBases[sbrId].sbr_field_10 < 255)
            {
                gSaveBlock1Ptr->secretBases[sbrId].sbr_field_10 ++;
            }
            sub_80E8F9C();
            warp_in();
            gFieldCallback = sub_80AF168;
            SetMainCallback2(c2_load_new_map);
            DestroyTask(taskId);
            break;
    }
}

void sub_80E9068(void)
{
    CreateTask(sub_80E8FD0, 0);
    fade_screen(1, 0);
    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
}

bool8 sub_80E909C(void)
{
    if (gMapHeader.mapType == MAP_TYPE_SECRET_BASE && VarGet(VAR_0x4097) == 0)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_80E90C8(u8 taskId)
{
    FieldObjectTurn(&gMapObjects[gPlayerAvatar.mapObjectId], DIR_NORTH);
    if (sub_80ABDFC() == TRUE)
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

void sub_80E9108(void)
{
    s16 x;
    s16 y;

    ScriptContext2_Enable();
    HideMapNamePopUpWindow();
    sub_80E8CB0(&x, &y, 0x220);
    x += 7;
    y += 7;
    MapGridSetMetatileIdAt(x, y, 0x220 | 0xC00);
    CurrentMapDrawMetatileAt(x, y);
    pal_fill_black();
    CreateTask(sub_80E90C8, 0);
}

void sub_80E916C(u8 taskId)
{
    s8 idx;

    if (!gPaletteFade.active)
    {
        idx = sCurSecretBaseId / 10 * 4;
        Overworld_SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, gUnknown_0858CFE8[idx + 2], gUnknown_0858CFE8[idx + 3]);
        warp_in();
        gFieldCallback = sub_80E9108;
        SetMainCallback2(c2_load_new_map);
        DestroyTask(taskId);
    }
}

void sub_80E91F8(void)
{
    CreateTask(sub_80E916C, 0);
    fade_screen(1, 0);
}

bool8 CurrentMapIsSecretBase(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP_SECRET_BASE_RED_CAVE1 && (u8)gSaveBlock1Ptr->location.mapNum <= MAP_ID_SECRET_BASE_SHRUB4)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_80E9238(u8 flagIn)
{
    u16 curBaseId;
    u16 x;
    u16 y;
    u8 *decorations;
    u8 *decorPos;

    if (CurrentMapIsSecretBase())
    {
        curBaseId = VarGet(VAR_0x4054);
        decorations = gSaveBlock1Ptr->secretBases[curBaseId].decorations;
        decorPos = gSaveBlock1Ptr->secretBases[curBaseId].decorationPos;
        for (x = 0; x < 16; x ++)
        {
            if (decorations[x] > 0 && decorations[x] <= 0x78 && gDecorations[decorations[x]].permission != DECORPERM_SOLID_MAT) {
                sub_8127D38((decorPos[x] >> 4) + 7, (decorPos[x] & 0xF) + 7, decorations[x]);
            }
        }
        if (curBaseId != 0)
        {
            sub_80E8CB0(&x, &y, 0x220);
            MapGridSetMetatileIdAt(x + 7, y + 7, 0x221 | 0xc00);
        }
        else if (flagIn == 1 && VarGet(VAR_0x4089) == 1)
        {
            sub_80E8CB0(&x, &y, 0x220);
            MapGridSetMetatileIdAt(x + 7, y + 7, 0x20a | 0xc00);
        }
    }
}

void sub_80E933C(void)
{
    u8 *roomdecor;
    u8 *roomdecorpos;
    u8 decidx;
    u8 objid;
    u8 metatile;
    u8 category;
    u8 permission;
    u8 ndecor;
    u16 curBase;

    objid = 0;
    if (!CurrentMapIsSecretBase())
    {
        roomdecor = gSaveBlock1Ptr->playerRoomDecor;
        roomdecorpos = gSaveBlock1Ptr->playerRoomDecorPos;
        ndecor = 12;
    }
    else
    {
        curBase = VarGet(VAR_0x4054);
        roomdecor = gSaveBlock1Ptr->secretBases[curBase].decorations;
        roomdecorpos = gSaveBlock1Ptr->secretBases[curBase].decorationPos;
        ndecor = 16;
    }
    for (decidx = 0; decidx < ndecor; decidx ++)
    {
        if (roomdecor[decidx] != DECOR_NONE)
        {
            permission = gDecorations[roomdecor[decidx]].permission;
            category = gDecorations[roomdecor[decidx]].category;
            if (permission == DECORPERM_SOLID_MAT)
            {
                for (objid = 0; objid < gMapHeader.events->mapObjectCount; objid ++)
                {
                    if (gMapHeader.events->mapObjects[objid].flagId == gSpecialVar_0x8004 + 0xAE)
                    {
                        break;
                    }
                }
                if (objid == gMapHeader.events->mapObjectCount)
                {
                    continue;
                }
                gSpecialVar_0x8006 = roomdecorpos[decidx] >> 4;
                gSpecialVar_0x8007 = roomdecorpos[decidx] & 0xF;
                metatile = MapGridGetMetatileBehaviorAt(gSpecialVar_0x8006 + 7, gSpecialVar_0x8007 + 7);
                if (MetatileBehavior_IsMB_B5(metatile) == TRUE || MetatileBehavior_IsMB_C3(metatile) == TRUE)
                {
                    gScriptResult = gMapHeader.events->mapObjects[objid].graphicsId + VAR_0x3F20;
                    VarSet(gScriptResult, gDecorations[roomdecor[decidx]].tiles[0]);
                    gScriptResult = gMapHeader.events->mapObjects[objid].localId;
                    FlagClear(gSpecialVar_0x8004 + 0xAE);
                    show_sprite(gScriptResult, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
                    sub_808EBA8(gScriptResult, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
                    sub_808F254(gScriptResult, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
                    if (CurrentMapIsSecretBase() == TRUE && VarGet(VAR_0x4054) != 0)
                    {
                        if (category == DECORCAT_DOLL)
                        {
                            sub_808F28C(gScriptResult, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, DECORCAT_DOLL);
                        }
                        else if (category == DECORCAT_CUSHION)
                        {
                            sub_808F28C(gScriptResult, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, DECORCAT_CUSHION);
                        }
                    }
                    gSpecialVar_0x8004 ++;
                }
            }
        }
    }
}

void sub_80E9578(void)
{
    u8 objIdx;
    u16 flagId;

    for (objIdx = 0; objIdx < gMapHeader.events->mapObjectCount; objIdx ++)
    {
        flagId = gMapHeader.events->mapObjects[objIdx].flagId;
        if (flagId >= 0xAE && flagId <= 0xBB)
        {
            RemoveFieldObjectByLocalIdAndMap(gMapHeader.events->mapObjects[objIdx].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            FlagSet(flagId);
        }
    }
}
