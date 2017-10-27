
// Includes
#include "global.h"
#include "malloc.h"
#include "task.h"
#include "palette.h"
#include "list_menu.h"
#include "window.h"
#include "menu.h"
#include "new_menu_helpers.h"
#include "menu_indicators.h"
#include "map_constants.h"
#include "songs.h"
#include "sound.h"
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
#include "event_scripts.h"
#include "strings.h"
#include "international_string_util.h"
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

void sub_80E9C9C(u8 taskId);
void game_continue(u8 taskId);
void sub_80E9E00(u8 taskId);
void sub_80E9E44(u8 taskId);
void sub_80E9E90(u8 taskId);
void sub_80E9F20(u8 taskId);
void sub_80E9FB0(u8 taskId);
void task_pc_turn_off(u8 taskId);
u8 sub_80EA18C(u8 sbId);
u8 sub_80EA20C(u8 sbId);

// .rodata

extern const struct {
    u16 tile1;
    u16 tile2;
} gUnknown_0858CFCC[7];

extern const u8 gUnknown_0858CFE8[];
extern const u8 gUnknown_0858D060[];
extern const struct WindowTemplate gUnknown_0858D06C[];
extern const struct ListMenuTemplate gUnknown_0858D07C;
extern const struct MenuAction gUnknown_0858D048[];

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

void sub_80E95D4(void)
{
    VarSet(VAR_0x401F, gUnknown_0858D060[sub_80EA20C(VarGet(VAR_0x4054))]);
}

void sub_80E9608(struct Coords16 *coords, struct MapEvents *events)
{
    s16 bgevtidx;

    for (bgevtidx = 0; bgevtidx < events->bgEventCount; bgevtidx ++)
    {
        if (events->bgEvents[bgevtidx].kind == 8 && coords->x == events->bgEvents[bgevtidx].x + 7 && coords->y == events->bgEvents[bgevtidx].y + 7)
        {
            sCurSecretBaseId = events->bgEvents[bgevtidx].bgUnion.secretBaseId;
            break;
        }
    }
}

void sub_80E9668(struct Coords16 *coords, struct MapEvents *events)
{
    sub_80E9608(coords, events);
    sub_80E8B6C();
    ScriptContext1_SetupScript(gUnknown_08275BB7);
}

bool8 sub_80E9680(void)
{
    sub_80E8B58();
    sub_80E8B6C();
    if (gScriptResult == TRUE)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_80E96A4(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        case 0:
            ScriptContext2_Enable();
            gTasks[taskId].data[0] = 1;
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                gTasks[taskId].data[0] = 2;
            }
            break;
        case 2:
            copy_saved_warp2_bank_and_enter_x_to_warp1(0x7e);
            warp_in();
            gFieldCallback = mapldr_default;
            SetMainCallback2(c2_load_new_map);
            ScriptContext2_Disable();
            DestroyTask(taskId);
            break;
    }
}

void sub_80E9728(void)
{
    CreateTask(sub_80E96A4, 0);
    fade_screen(1, 0);
}

void sub_80E9744(void)
{
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId != sCurSecretBaseId)
    {
        gScriptResult = TRUE;
    }
    else
    {
        gScriptResult = FALSE;
    }
}

u8 *sub_80E9780(u8 *dest, u8 sbId)
{
    *StringCopyN(dest, gSaveBlock1Ptr->secretBases[sbId].trainerName, sub_80E8DF4(gSaveBlock1Ptr->secretBases[sbId].trainerName)) = EOS;
    ConvertInternationalString(dest, gSaveBlock1Ptr->secretBases[sbId].language);
    return StringAppend(dest, gText_ApostropheSBase);
}

u8 *GetSecretBaseMapName(u8 *dest)
{
    return sub_80E9780(dest, VarGet(VAR_0x4054));
}

void sub_80E980C(void)
{
    u8 sbId;
    const u8 *src;

    sbId = VarGet(VAR_0x4054);
    src = gSaveBlock1Ptr->secretBases[sbId].trainerName;
    *StringCopyN(gStringVar1, src, sub_80E8DF4(src)) = EOS;
    ConvertInternationalString(gStringVar1, gSaveBlock1Ptr->secretBases[sbId].language);
}

bool8 sub_80E9878(u8 sbId)
{
    if (gSaveBlock1Ptr->secretBases[sbId].sbr_field_1_6 != 0)
    {
        return TRUE;
    }
    return FALSE;
}

u8 sub_80E98AC(struct Pokemon *pokemon)
{
    u16 evTotal;

    evTotal  = GetMonData(pokemon, MON_DATA_HP_EV);
    evTotal += GetMonData(pokemon, MON_DATA_ATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_DEF_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPD_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPATK_EV);
    evTotal += GetMonData(pokemon, MON_DATA_SPDEF_EV);
    return evTotal / 6;
}

#ifdef NONMATCHING
// This function is a meme
void sub_80E9914(void)
{
    u32 zero;
    u32 *personality;
    u16 partyidx;
    u16 moveidx;
    u16 sbpartyidx;
    u16 *species;
    u16 *items;
    u16 *moves;
    u8 *levels;
    u8 *evs;

    sbpartyidx = 0;
    personality = gSaveBlock1Ptr->secretBases[0].partyPersonality;
    if (gSaveBlock1Ptr->secretBases[0].secretBaseId != 0)
    {
        partyidx = 0;
        moves = gSaveBlock1Ptr->secretBases[0].partyMoves;
        species = gSaveBlock1Ptr->secretBases[0].partySpecies;
        items = gSaveBlock1Ptr->secretBases[0].partyHeldItems;
        levels = gSaveBlock1Ptr->secretBases[0].partyLevels;
        evs = gSaveBlock1Ptr->secretBases[0].partyEVs;
        zero = 0;
        for (partyidx = 0; partyidx < PARTY_SIZE; partyidx ++)
        {
            for (moveidx = 0; moveidx < 4; moveidx ++)
            {
                moves[partyidx * 4 + moveidx] = zero;
            }
            species[partyidx] = zero;
            items[partyidx] = zero;
            levels[partyidx] = zero;
            personality[partyidx] = zero;
            evs[partyidx] = zero;
            if (GetMonData(&gPlayerParty[partyidx], MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(&gPlayerParty[partyidx], MON_DATA_IS_EGG))
            {
                for (moveidx = 0; moveidx < 4; moveidx ++)
                {
                    moves[sbpartyidx * 4 + moveidx] = GetMonData(&gPlayerParty[partyidx], MON_DATA_MOVE1 + moveidx);
                }
                species[sbpartyidx] = GetMonData(&gPlayerParty[partyidx], MON_DATA_SPECIES);
                items[sbpartyidx] = GetMonData(&gPlayerParty[partyidx], MON_DATA_HELD_ITEM);
                levels[sbpartyidx] = GetMonData(&gPlayerParty[partyidx], MON_DATA_LEVEL);
                personality[sbpartyidx] = GetMonData(&gPlayerParty[partyidx], MON_DATA_PERSONALITY);
                evs[sbpartyidx] = sub_80E98AC(&gPlayerParty[partyidx]);
                sbpartyidx ++;
            }
        }
    }
}
#else
__attribute__((naked)) void sub_80E9914(void)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                    "\tmov r7, r10\n"
                    "\tmov r6, r9\n"
                    "\tmov r5, r8\n"
                    "\tpush {r5-r7}\n"
                    "\tsub sp, 0x24\n"
                    "\tmovs r0, 0\n"
                    "\tmov r10, r0\n"
                    "\tldr r0, =gSaveBlock1Ptr\n"
                    "\tldr r1, [r0]\n"
                    "\tldr r2, =0x00001ad0\n"
                    "\tadds r2, r1, r2\n"
                    "\tstr r2, [sp]\n"
                    "\tldr r3, =0x00001a9c\n"
                    "\tadds r0, r1, r3\n"
                    "\tldrb r0, [r0]\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080E993A\n"
                    "\tb _080E9A60\n"
                    "_080E993A:\n"
                    "\tmovs r6, 0\n"
                    "\tldr r7, =0x00001ae8\n"
                    "\tadds r7, r1, r7\n"
                    "\tstr r7, [sp, 0x14]\n"
                    "\tldr r0, =0x00001b18\n"
                    "\tadds r0, r1, r0\n"
                    "\tstr r0, [sp, 0xC]\n"
                    "\tldr r2, =0x00001b24\n"
                    "\tadds r2, r1, r2\n"
                    "\tstr r2, [sp, 0x10]\n"
                    "\tadds r3, 0x94\n"
                    "\tadds r3, r1, r3\n"
                    "\tstr r3, [sp, 0x18]\n"
                    "\tldr r7, =0x00001b36\n"
                    "\tadds r7, r1, r7\n"
                    "\tstr r7, [sp, 0x1C]\n"
                    "\tmov r9, r6\n"
                    "_080E995C:\n"
                    "\tmovs r4, 0\n"
                    "\tlsls r5, r6, 2\n"
                    "\tlsls r3, r6, 1\n"
                    "\tldr r0, =gPlayerParty\n"
                    "\tmov r8, r0\n"
                    "\tadds r1, r6, 0x1\n"
                    "\tstr r1, [sp, 0x4]\n"
                    "\tadds r2, r5, 0\n"
                    "\tldr r1, [sp, 0x14]\n"
                    "_080E996E:\n"
                    "\tadds r0, r2, r4\n"
                    "\tlsls r0, 1\n"
                    "\tadds r0, r1, r0\n"
                    "\tmov r7, r9\n"
                    "\tstrh r7, [r0]\n"
                    "\tadds r0, r4, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r4, r0, 16\n"
                    "\tcmp r4, 0x3\n"
                    "\tbls _080E996E\n"
                    "\tldr r1, [sp, 0xC]\n"
                    "\tadds r0, r1, r3\n"
                    "\tmov r2, r9\n"
                    "\tstrh r2, [r0]\n"
                    "\tldr r7, [sp, 0x10]\n"
                    "\tadds r0, r7, r3\n"
                    "\tstrh r2, [r0]\n"
                    "\tldr r1, [sp, 0x18]\n"
                    "\tadds r0, r1, r6\n"
                    "\tmov r2, r9\n"
                    "\tstrb r2, [r0]\n"
                    "\tldr r3, [sp]\n"
                    "\tadds r0, r3, r5\n"
                    "\tmov r7, r9\n"
                    "\tstr r7, [r0]\n"
                    "\tldr r1, [sp, 0x1C]\n"
                    "\tadds r0, r1, r6\n"
                    "\tstrb r7, [r0]\n"
                    "\tmovs r2, 0x64\n"
                    "\tadds r5, r6, 0\n"
                    "\tmuls r5, r2\n"
                    "\tmov r3, r8\n"
                    "\tadds r4, r5, r3\n"
                    "\tadds r0, r4, 0\n"
                    "\tmovs r1, 0xB\n"
                    "\tbl GetMonData\n"
                    "\tcmp r0, 0\n"
                    "\tbeq _080E9A54\n"
                    "\tadds r0, r4, 0\n"
                    "\tmovs r1, 0x2D\n"
                    "\tbl GetMonData\n"
                    "\tcmp r0, 0\n"
                    "\tbne _080E9A54\n"
                    "\tmovs r4, 0\n"
                    "\tmov r7, r10\n"
                    "\tlsls r7, 2\n"
                    "\tmov r8, r7\n"
                    "\tmov r0, r10\n"
                    "\tlsls r7, r0, 1\n"
                    "\tadds r0, 0x1\n"
                    "\tstr r0, [sp, 0x8]\n"
                    "\tldr r2, =gPlayerParty\n"
                    "_080E99DA:\n"
                    "\tadds r1, r4, 0\n"
                    "\tadds r1, 0xD\n"
                    "\tadds r0, r5, r2\n"
                    "\tstr r2, [sp, 0x20]\n"
                    "\tbl GetMonData\n"
                    "\tmov r3, r8\n"
                    "\tadds r1, r3, r4\n"
                    "\tlsls r1, 1\n"
                    "\tldr r3, [sp, 0x14]\n"
                    "\tadds r1, r3, r1\n"
                    "\tstrh r0, [r1]\n"
                    "\tadds r0, r4, 0x1\n"
                    "\tlsls r0, 16\n"
                    "\tlsrs r4, r0, 16\n"
                    "\tldr r2, [sp, 0x20]\n"
                    "\tcmp r4, 0x3\n"
                    "\tbls _080E99DA\n"
                    "\tmovs r0, 0x64\n"
                    "\tadds r4, r6, 0\n"
                    "\tmuls r4, r0\n"
                    "\tldr r0, =gPlayerParty\n"
                    "\tadds r4, r0\n"
                    "\tadds r0, r4, 0\n"
                    "\tmovs r1, 0xB\n"
                    "\tbl GetMonData\n"
                    "\tldr r2, [sp, 0xC]\n"
                    "\tadds r1, r2, r7\n"
                    "\tstrh r0, [r1]\n"
                    "\tadds r0, r4, 0\n"
                    "\tmovs r1, 0xC\n"
                    "\tbl GetMonData\n"
                    "\tldr r3, [sp, 0x10]\n"
                    "\tadds r1, r3, r7\n"
                    "\tstrh r0, [r1]\n"
                    "\tadds r0, r4, 0\n"
                    "\tmovs r1, 0x38\n"
                    "\tbl GetMonData\n"
                    "\tldr r1, [sp, 0x18]\n"
                    "\tadd r1, r10\n"
                    "\tstrb r0, [r1]\n"
                    "\tadds r0, r4, 0\n"
                    "\tmovs r1, 0\n"
                    "\tbl GetMonData\n"
                    "\tldr r1, [sp]\n"
                    "\tadd r1, r8\n"
                    "\tstr r0, [r1]\n"
                    "\tadds r0, r4, 0\n"
                    "\tbl sub_80E98AC\n"
                    "\tldr r1, [sp, 0x1C]\n"
                    "\tadd r1, r10\n"
                    "\tstrb r0, [r1]\n"
                    "\tldr r7, [sp, 0x8]\n"
                    "\tlsls r0, r7, 16\n"
                    "\tlsrs r0, 16\n"
                    "\tmov r10, r0\n"
                    "_080E9A54:\n"
                    "\tldr r1, [sp, 0x4]\n"
                    "\tlsls r0, r1, 16\n"
                    "\tlsrs r6, r0, 16\n"
                    "\tcmp r6, 0x5\n"
                    "\tbhi _080E9A60\n"
                    "\tb _080E995C\n"
                    "_080E9A60:\n"
                    "\tadd sp, 0x24\n"
                    "\tpop {r3-r5}\n"
                    "\tmov r8, r3\n"
                    "\tmov r9, r4\n"
                    "\tmov r10, r5\n"
                    "\tpop {r4-r7}\n"
                    "\tpop {r0}\n"
                    "\tbx r0\n"
                    "\t.pool");
}
#endif

void sub_80E9A90(void)
{
    u16 sbr_e;

    sbr_e = gSaveBlock1Ptr->secretBases[0].sbr_field_e;
    sub_80E8AF0(&gSaveBlock1Ptr->secretBases[0]);
    gSaveBlock1Ptr->secretBases[0].sbr_field_e = sbr_e;
    sub_80E9728();
}

void sub_80E9AC0(void)
{
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    sub_80E9A90();
}

void sub_80E9AD0(void)
{
    u16 i;
    u16 j;
    s16 tile;
    struct MapEvents *events;

    events = gMapHeader.events;
    for (i = 0; i < events->bgEventCount; i ++)
    {
        if (events->bgEvents[i].kind == 8 && gSaveBlock1Ptr->secretBases[0].secretBaseId == events->bgEvents[i].bgUnion.secretBaseId)
        {
            tile = MapGridGetMetatileIdAt(events->bgEvents[i].x + 7, events->bgEvents[i].y + 7);
            for (j = 0; j < 7; j ++)
            {
                if (gUnknown_0858CFCC[j].tile2 == tile)
                {
                    MapGridSetMetatileIdAt(events->bgEvents[i].x + 7, events->bgEvents[i].y + 7, gUnknown_0858CFCC[j].tile1 | 0xc00);
                    break;
                }
            }
            DrawWholeMapView();
            break;
        }
    }
}

void sub_80E9B70(void)
{
    u16 sbr_e;

    sub_80E9AD0();
    IncrementGameStat(GAME_STAT_MOVED_SECRET_BASE);
    sbr_e = gSaveBlock1Ptr->secretBases[0].sbr_field_e;
    sub_80E8AF0(&gSaveBlock1Ptr->secretBases[0]);
    gSaveBlock1Ptr->secretBases[0].sbr_field_e = sbr_e;
}

u8 sub_80E9BA8(void)
{
    u8 tot;
    s16 i;

    tot = 0;
    for (i = 1; i < 20; i ++)
    {
        if (sub_80E9878(i) == TRUE)
        {
            tot ++;
        }
    }
    return tot;
}

void sub_80E9BDC(void)
{
    if (sub_80E9878(VarGet(VAR_0x4054)) == TRUE)
    {
        gScriptResult = 1;
    }
    else if (sub_80E9BA8() > 9)
    {
        gScriptResult = 2;
    }
    else
    {
        gScriptResult = 0;
    }
}

void sub_80E9C2C(void)
{
    gSaveBlock1Ptr->secretBases[VarGet(VAR_0x4054)].sbr_field_1_6 ^= 1;
    FlagSet(0x10C);
}

void sub_80E9C74(void)
{
    CreateTask(sub_8126AD8, 0);
}

void sub_80E9C88(void)
{
    CreateTask(sub_80E9C9C, 0);
}

void sub_80E9C9C(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    ScriptContext2_Enable();
    data[0] = sub_80E9BA8();
    if (data[0] != 0)
    {
        data[1] = 0;
        data[2] = 0;
        sub_8197434(0, 0);
        gUnknown_0203A020 = calloc(1, sizeof(struct SecretBaseListMenuBuffer));
        data[6] = AddWindow(&gUnknown_0858D06C[0]);
        game_continue(taskId);
        sub_80E9E00(taskId);
        gTasks[taskId].func = sub_80E9E90;
    }
    else
    {
        DisplayItemMessageOnField(taskId, gText_NoRegistry, task_pc_turn_off);
    }
}

void game_continue(u8 taskId)
{
    s16 *data;
    u8 i;
    u8 ct;

    data = gTasks[taskId].data;
    ct = 0;
    for (i = 1; i < 20; i ++)
    {
        if (sub_80E9878(i))
        {
            sub_80E9780(gUnknown_0203A020->names[ct], i);
            gUnknown_0203A020->items[ct].unk_00 = gUnknown_0203A020->names[ct];
            gUnknown_0203A020->items[ct].unk_04 = i;
            ct ++;
        }
    }
    gUnknown_0203A020->items[ct].unk_00 = gText_Cancel;
    gUnknown_0203A020->items[ct].unk_04 = -2;
    data[0] = ct + 1;
    if (data[0] < 8)
    {
        data[3] = data[0];
    }
    else
    {
        data[3] = 8;
    }
    gUnknown_03006310 = gUnknown_0858D07C;
    gUnknown_03006310.unk_10 = data[6];
    gUnknown_03006310.unk_0c = data[0];
    gUnknown_03006310.unk_00 = gUnknown_0203A020->items;
    gUnknown_03006310.unk_0e = data[3];
}

void sub_80E9DEC(u32 unused, bool8 flag)
{
    if (flag != TRUE)
    {
        PlaySE(SE_SELECT);
    }
}

void sub_80E9E00(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    SetStandardWindowBorderStyle(data[6], 0);
    data[5] = ListMenuInit(&gUnknown_03006310, data[2], data[1]);
    sub_80E9E44(taskId);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_80E9E44(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    data[8] = AddScrollIndicatorArrowPairParametrized(0x02, 0xbc, 0x0c, 0x94, data[0] - data[3], 0x13f8, 0x13f8, &data[2]);
}

void sub_80E9E90(u8 taskId)
{
    s16 *data;
    s32 input;

    data = gTasks[taskId].data;
    input = ListMenuHandleInput(data[5]);
    get_coro_args_x18_x1A(data[5], &data[2], &data[1]);
    switch (input)
    {
        case -1:
            break;
        case -2:
            PlaySE(SE_SELECT);
            sub_81AE6C8(data[5], NULL, NULL);
            RemoveScrollIndicatorArrowPair(data[8]);
            sub_819746C(data[6], 0);
            ClearWindowTilemap(data[6]);
            RemoveWindow(data[6]);
            schedule_bg_copy_tilemap_to_vram(0);
            free(gUnknown_0203A020);
            task_pc_turn_off(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            data[4] = input;
            sub_80E9F20(taskId);
            break;
    }
}

void sub_80E9F20(u8 taskId)
{
    struct WindowTemplate template;
    s16 *data;

    data = gTasks[taskId].data;
    RemoveScrollIndicatorArrowPair(data[8]);
    template = gUnknown_0858D06C[1];
    template.width = GetMaxWidthInMenuTable(gUnknown_0858D048, 2);
    data[7] = AddWindow(&template);
    SetStandardWindowBorderStyle(data[7], 0);
    PrintMenuTable(data[7], 2, gUnknown_0858D048);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(data[7], 2, 0);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = sub_80E9FB0;
}

void sub_80E9FB0(u8 taskId)
{
    s8 input;

    input = ProcessMenuInputNoWrapAround();
    switch (input)
    {
        case -1:
            PlaySE(SE_SELECT);
            sub_80EA18C(taskId);
            break;
        case -2:
            break;
        default:
            PlaySE(SE_SELECT);
            gUnknown_0858D048[input].func.void_u8(taskId);
            break;
    }
}
