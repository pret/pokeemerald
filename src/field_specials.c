#include "global.h"
#include "alloc.h"
#include "battle.h"
#include "battle_tower.h"
#include "cable_club.h"
#include "data.h"
#include "decoration.h"
#include "diploma.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "field_weather.h"
#include "international_string_util.h"
#include "item_icon.h"
#include "link.h"
#include "list_menu.h"
#include "main.h"
#include "mevent.h"
#include "match_call.h"
#include "menu.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "rayquaza_scene.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "starter_choose.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "wallclock.h"
#include "window.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/items.h"
#include "constants/map_types.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/vars.h"
#include "constants/battle_frontier.h"
#include "constants/weather.h"
#include "palette.h"

EWRAM_DATA bool8 gBikeCyclingChallenge = FALSE;
EWRAM_DATA u8 gBikeCollisions = 0;
static EWRAM_DATA u32 gBikeCyclingTimer = 0;
static EWRAM_DATA u8 gUnknown_0203AB5C = 0;
static EWRAM_DATA u8 gUnknown_0203AB5D = 0;
static EWRAM_DATA u8 gUnknown_0203AB5E = 0;
static EWRAM_DATA u16 gUnknown_0203AB60 = 0;
static EWRAM_DATA u16 gUnknown_0203AB62 = 0;
static EWRAM_DATA struct ListMenuItem *gUnknown_0203AB64 = NULL;
static EWRAM_DATA u16 gUnknown_0203AB68 = 0;
static EWRAM_DATA u16 gUnknown_0203AB6A = 0;
static EWRAM_DATA u8 gUnknown_0203AB6C = 0;
static EWRAM_DATA u8 gUnknown_0203AB6D = 0;
static EWRAM_DATA u8 gUnknown_0203AB6E = 0;
static EWRAM_DATA u8 gUnknown_0203AB6F = 0;
static EWRAM_DATA u32 gUnknown_0203AB70 = 0;

struct ListMenuTemplate gUnknown_030061D0;

extern const u16 gEventObjectPalette8[];
extern const u16 gEventObjectPalette17[];
extern const u16 gEventObjectPalette33[];
extern const u16 gEventObjectPalette34[];


void UpdateMovedLilycoveFanClubMembers(void);
void sub_813BF60(void);
u16 GetNumMovedLilycoveFanClubMembers(void);

static void RecordCyclingRoadResults(u32, u8);
static void LoadLinkPartnerEventObjectSpritePalette(u8 graphicsId, u8 localEventId, u8 paletteNum);
static void Task_PetalburgGym(u8);
static void PetalburgGymFunc(u8, u16);
static void Task_PCTurnOnEffect(u8);
static void PCTurnOnEffect_0(struct Task *);
static void PCTurnOnEffect_1(s16, s8, s8);
static void PCTurnOffEffect(void);
static void Task_LotteryCornerComputerEffect(u8);
static void LotteryCornerComputerEffect(struct Task *);
static void sub_81395BC(u8 taskId);
static void sub_8139620(u8 taskId);
static void sub_8139AF4(u8 taskId);
static void sub_8139C2C(u16 a1, u8 a2);
static void sub_8139C80(u8 taskId);
static void sub_813A2DC(u8 taskId);
static void sub_813AA60(u16 a0, u16 a1);
static void sub_813ACE8(u8 a0, u16 a1);
static void sub_813A42C(void);
static void sub_813A4EC(u8 taskId);
static void sub_813A694(u8 taskId);
static void sub_813A46C(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void sub_813AC44(u16 a0, u16 a1);
static void sub_813AD34(u8 a0, u16 a1);
static void sub_813A570(u8 taskId);
static void sub_813A738(u8 taskId);
static void sub_813A600(u8 taskId);
static void sub_813A664(u8 taskId);
static void sub_813ABD4(u16 a0);
static void Task_DeoxysRockInteraction(u8 taskId);
static void ChangeDeoxysRockLevel(u8 a0);
static void WaitForDeoxysRockMovement(u8 taskId);
static void sub_813B57C(u8 taskId);
static void sub_813B824(u8 taskId);
static void _fwalk(u8 taskId);
static u8 sub_813BF44(void);
static void sub_813BD84(void);
static u16 sub_813BB74(void);
static void sub_813BE30(struct LinkBattleRecords *linkRecords, u8 a, u8 b);

void Special_ShowDiploma(void)
{
    SetMainCallback2(CB2_ShowDiploma);
    ScriptContext2_Enable();
}

void Special_ViewWallClock(void)
{
    gMain.savedCallback = CB2_ReturnToField;
    SetMainCallback2(CB2_ViewWallClock);
    ScriptContext2_Enable();
}

void ResetCyclingRoadChallengeData(void)
{
    gBikeCyclingChallenge = FALSE;
    gBikeCollisions = 0;
    gBikeCyclingTimer = 0;
}

void Special_BeginCyclingRoadChallenge(void)
{
    gBikeCyclingChallenge = TRUE;
    gBikeCollisions = 0;
    gBikeCyclingTimer = gMain.vblankCounter1;
}

u16 GetPlayerAvatarBike(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        return 1;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        return 2;
    return 0;
}

static void DetermineCyclingRoadResults(u32 numFrames, u8 numBikeCollisions)
{
    u8 result;

    if (numBikeCollisions < 100)
    {
        ConvertIntToDecimalStringN(gStringVar1, numBikeCollisions, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(gStringVar1, gText_SpaceTimes);
    }
    else
    {
        StringCopy(gStringVar1, gText_99TimesPlus);
    }

    if (numFrames < 3600)
    {
        ConvertIntToDecimalStringN(gStringVar2, numFrames / 60, STR_CONV_MODE_RIGHT_ALIGN, 2);
        gStringVar2[2] = CHAR_PERIOD;
        ConvertIntToDecimalStringN(&gStringVar2[3], ((numFrames % 60) * 100) / 60, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringAppend(gStringVar2, gText_SpaceSeconds);
    }
    else
    {
        StringCopy(gStringVar2, gText_1MinutePlus);
    }

    result = 0;
    if (numBikeCollisions == 0)
    {
        result = 5;
    }
    else if (numBikeCollisions < 4)
    {
        result = 4;
    }
    else if (numBikeCollisions < 10)
    {
        result = 3;
    }
    else if (numBikeCollisions < 20)
    {
        result = 2;
    }
    else if (numBikeCollisions < 100)
    {
        result = 1;
    }

    if (numFrames / 60 <= 10)
    {
        result += 5;
    }
    else if (numFrames / 60 <= 15)
    {
        result += 4;
    }
    else if (numFrames / 60 <= 20)
    {
        result += 3;
    }
    else if (numFrames / 60 <= 40)
    {
        result += 2;
    }
    else if (numFrames / 60 < 60)
    {
        result += 1;
    }


    gSpecialVar_Result = result;
}

void FinishCyclingRoadChallenge(void) {
    const u32 numFrames = gMain.vblankCounter1 - gBikeCyclingTimer;

    DetermineCyclingRoadResults(numFrames, gBikeCollisions);
    RecordCyclingRoadResults(numFrames, gBikeCollisions);
}

static void RecordCyclingRoadResults(u32 numFrames, u8 numBikeCollisions) {
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord > numFrames || framesRecord == 0)
    {
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_L, numFrames);
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_H, numFrames >> 16);
        VarSet(VAR_CYCLING_ROAD_RECORD_COLLISIONS, numBikeCollisions);
    }
}

u16 GetRecordedCyclingRoadResults(void) {
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord == 0)
    {
        return FALSE;
    }

    DetermineCyclingRoadResults(framesRecord, VarGet(VAR_CYCLING_ROAD_RECORD_COLLISIONS));
    return TRUE;
}

void UpdateCyclingRoadState(void) {
    if (gLastUsedWarp.mapNum == MAP_NUM(ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE) && gLastUsedWarp.mapGroup == MAP_GROUP(ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE))
    {
        return;
    }

    if (VarGet(VAR_CYCLING_CHALLENGE_STATE) == 2 || VarGet(VAR_CYCLING_CHALLENGE_STATE) == 3)
    {
        VarSet(VAR_CYCLING_CHALLENGE_STATE, 0);
        Overworld_SetSavedMusic(MUS_DUMMY);
    }
}

void SetSSTidalFlag(void)
{
    FlagSet(FLAG_SYS_CRUISE_MODE);
    *GetVarPointer(VAR_CRUISE_STEP_COUNT) = 0;
}

void ResetSSTidalFlag(void)
{
    FlagClear(FLAG_SYS_CRUISE_MODE);
}

bool32 CountSSTidalStep(u16 delta)
{
    if (!FlagGet(FLAG_SYS_CRUISE_MODE) || (*GetVarPointer(VAR_CRUISE_STEP_COUNT) += delta) <= 0xcc)
    {
        return FALSE;
    }
    return TRUE;
}

u8 GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y)
{
    u16 *varCruiseStepCount = GetVarPointer(VAR_CRUISE_STEP_COUNT);
    switch (*GetVarPointer(VAR_PORTHOLE_STATE))
    {
        case 1:
        case 8:
            return 1;
        case 3:
        case 9:
            return 4;
        case 4:
        case 5:
            return 2;
        case 6:
        case 10:
            return 3;
        case 2:
            if (*varCruiseStepCount < 60)
            {
                *mapNum = MAP_NUM(ROUTE134);
                *x = *varCruiseStepCount + 19;
            }
            else if (*varCruiseStepCount < 140)
            {
                *mapNum = MAP_NUM(ROUTE133);
                *x = *varCruiseStepCount - 60;
            }
            else
            {
                *mapNum = MAP_NUM(ROUTE132);
                *x = *varCruiseStepCount - 140;
            }
            break;
        case 7:
            if (*varCruiseStepCount < 66)
            {
                *mapNum = MAP_NUM(ROUTE132);
                *x = 65 - *varCruiseStepCount;
            }
            else if (*varCruiseStepCount < 146) {
                *mapNum = MAP_NUM(ROUTE133);
                *x = 145 - *varCruiseStepCount;
            }
            else
            {
                *mapNum = MAP_NUM(ROUTE134);
                *x = 224 - *varCruiseStepCount;
            }
            break;
    }
    *mapGroup = MAP_GROUP(ROUTE132);
    *y = 20;
    return 0;
}

bool32 ShouldDoWallyCall(void)
{
    if (FlagGet(FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_WALLY_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoWinonaCall(void)
{
    if (FlagGet(FLAG_REGISTER_WINONA_POKENAV))
    {
        switch (gMapHeader.mapType)
        {
            case MAP_TYPE_TOWN:
            case MAP_TYPE_CITY:
            case MAP_TYPE_ROUTE:
            case MAP_TYPE_OCEAN_ROUTE:
                if (++(*GetVarPointer(VAR_WINONA_CALL_STEP_COUNTER)) < 10)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoScottCall(void)
{
    if (FlagGet(FLAG_SCOTT_CALL_NATIONAL_DEX))
    {
        switch (gMapHeader.mapType)
        {
            case 1:
            case 2:
            case 3:
            case 6:
                if (++(*GetVarPointer(VAR_SCOTT_CALL_STEP_COUNTER)) < 10)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRoxanneCall(void)
{
    if (FlagGet(FLAG_ENABLE_ROXANNE_FIRST_CALL))
    {
        switch (gMapHeader.mapType)
        {
            case 1:
            case 2:
            case 3:
            case 6:
                if (++(*GetVarPointer(VAR_ROXANNE_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRivalRayquazaCall(void)
{
    if (FlagGet(FLAG_DEFEATED_MAGMA_SPACE_CENTER))
    {
        switch (gMapHeader.mapType)
        {
            case 1:
            case 2:
            case 3:
            case 6:
                if (++(*GetVarPointer(VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER)) < 250)
                {
                    return FALSE;
                }
                break;
            default:
                return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

u8 GetLinkPartnerNames(void)
{
    u8 i;
    u8 j = 0;
    u8 myLinkPlayerNumber = GetMultiplayerId();
    u8 nLinkPlayers = GetLinkPlayerCount();
    for (i = 0; i < nLinkPlayers; i++)
    {
        if (myLinkPlayerNumber != i)
        {
            StringCopy(gTVStringVarPtrs[j], gLinkPlayers[i].name);
            j++;
        }
    }
    return nLinkPlayers;
}

void SpawnLinkPartnerEventObject(void)
{
    u8 j = 0;
    s16 x = 0;
    s16 y = 0;
    u8 gUnknown_085B2B5C[] = {7, 9, 8, 10};
    s8 gUnknown_085B2B60[][2] = {
        { 0,  1},
        { 1,  0},
        { 0, -1},
        {-1,  0}
    };
    u8 myLinkPlayerNumber;
    u8 playerFacingDirection;
    u8 linkSpriteId;
    u8 i;

    myLinkPlayerNumber = GetMultiplayerId();
    playerFacingDirection = GetPlayerFacingDirection();
    switch (playerFacingDirection)
    {
        case DIR_WEST:
            j = 2;
            x = gSaveBlock1Ptr->pos.x - 1;
            y = gSaveBlock1Ptr->pos.y;
            break;
        case DIR_NORTH:
            j = 1;
            x = gSaveBlock1Ptr->pos.x;
            y = gSaveBlock1Ptr->pos.y - 1;
            break;
        case DIR_EAST:
            x = gSaveBlock1Ptr->pos.x + 1;
            y = gSaveBlock1Ptr->pos.y;
            break;
        case DIR_SOUTH:
            j = 3;
            x = gSaveBlock1Ptr->pos.x;
            y = gSaveBlock1Ptr->pos.y + 1;
    }
    for (i = 0; i < gSpecialVar_0x8004; i++)
    {
        if (myLinkPlayerNumber != i)
        {
            switch ((u8)gLinkPlayers[i].version)
            {
                case VERSION_RUBY:
                case VERSION_SAPPHIRE:
                    if (gLinkPlayers[i].gender == 0)
                        linkSpriteId = EVENT_OBJ_GFX_LINK_RS_BRENDAN;
                    else
                        linkSpriteId = EVENT_OBJ_GFX_LINK_RS_MAY;
                    break;
                case VERSION_EMERALD:
                    if (gLinkPlayers[i].gender == 0)
                        linkSpriteId = EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL;
                    else
                        linkSpriteId = EVENT_OBJ_GFX_RIVAL_MAY_NORMAL;
                    break;
                default:
                    if (gLinkPlayers[i].gender == 0)
                        linkSpriteId = EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL;
                    else
                        linkSpriteId = EVENT_OBJ_GFX_RIVAL_MAY_NORMAL;
                    break;
            }
            SpawnSpecialEventObjectParameterized(linkSpriteId, gUnknown_085B2B5C[j], 0xf0 - i, gUnknown_085B2B60[j][0] + x + 7, gUnknown_085B2B60[j][1] + y + 7, 0);
            LoadLinkPartnerEventObjectSpritePalette(linkSpriteId, 0xf0 - i, i);
            j++;
            if (j == 4)
            {
                j = 0;
            }
        }
    }
}

static void LoadLinkPartnerEventObjectSpritePalette(u8 graphicsId, u8 localEventId, u8 paletteNum)
{
    u8 adjustedPaletteNum;
    // Note: This temp var is necessary; paletteNum += 6 doesn't match.
    adjustedPaletteNum = paletteNum + 6;
    if (graphicsId == EVENT_OBJ_GFX_LINK_RS_BRENDAN ||
        graphicsId == EVENT_OBJ_GFX_LINK_RS_MAY ||
        graphicsId == EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL ||
        graphicsId == EVENT_OBJ_GFX_RIVAL_MAY_NORMAL)
    {
        u8 obj = GetEventObjectIdByLocalIdAndMap(localEventId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        if (obj != EVENT_OBJECTS_COUNT)
        {
            u8 spriteId = gEventObjects[obj].spriteId;
            struct Sprite *sprite = &gSprites[spriteId];
            sprite->oam.paletteNum = adjustedPaletteNum;

            switch (graphicsId)
            {
                case EVENT_OBJ_GFX_LINK_RS_BRENDAN:
                    LoadPalette(gEventObjectPalette33, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
                case EVENT_OBJ_GFX_LINK_RS_MAY:
                    LoadPalette(gEventObjectPalette34, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
                case EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL:
                    LoadPalette(gEventObjectPalette8, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
                case EVENT_OBJ_GFX_RIVAL_MAY_NORMAL:
                    LoadPalette(gEventObjectPalette17, 0x100 + (adjustedPaletteNum << 4), 0x20);
                    break;
            }
        }
    }
}

static const struct UCoords8 gUnknown_085B2B68[] = {
    { 7, 22},
    {11, 19},
    {10, 16},
    {15, 16}
};

void MauvilleGymSpecial1(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gUnknown_085B2B68); i++)
    {
        if (i == gSpecialVar_0x8004)
        {
            MapGridSetMetatileIdAt(gUnknown_085B2B68[i].x, gUnknown_085B2B68[i].y, 0x206);
        }
        else
        {
            MapGridSetMetatileIdAt(gUnknown_085B2B68[i].x, gUnknown_085B2B68[i].y, 0x205);
        }
    }
}

void MauvilleGymSpecial2(void)
{
    int x, y;
    for (y = 12; y < 24; y++)
    {
        for (x = 7; x < 16; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
                case 0x220:
                    MapGridSetMetatileIdAt(x, y, 0x230);
                    break;
                case 0x221:
                    MapGridSetMetatileIdAt(x, y, 0x231);
                    break;
                case 0x228:
                    MapGridSetMetatileIdAt(x, y, 0x238);
                    break;
                case 0x229:
                    MapGridSetMetatileIdAt(x, y, 0x239);
                    break;
                case 0x230:
                    MapGridSetMetatileIdAt(x, y, 0x220);
                    break;
                case 0x231:
                    MapGridSetMetatileIdAt(x, y, 0x221);
                    break;
                case 0x238:
                    MapGridSetMetatileIdAt(x, y, 0xe28);
                    break;
                case 0x239:
                    MapGridSetMetatileIdAt(x, y, 0xe29);
                    break;
                case 0x222:
                    MapGridSetMetatileIdAt(x, y, 0x232);
                    break;
                case 0x223:
                    MapGridSetMetatileIdAt(x, y, 0x233);
                    break;
                case 0x22a:
                    MapGridSetMetatileIdAt(x, y, 0x23a);
                    break;
                case 0x22b:
                    MapGridSetMetatileIdAt(x, y, 0x23b);
                    break;
                case 0x232:
                    MapGridSetMetatileIdAt(x, y, 0x222);
                    break;
                case 0x233:
                    MapGridSetMetatileIdAt(x, y, 0x223);
                    break;
                case 0x23a:
                    MapGridSetMetatileIdAt(x, y, 0xe2a);
                    break;
                case 0x23b:
                    MapGridSetMetatileIdAt(x, y, 0xe2b);
                    break;
                case 0x240:
                    MapGridSetMetatileIdAt(x, y, 0xe42);
                    break;
                case 0x248:
                    MapGridSetMetatileIdAt(x, y, 0x21a);
                    break;
                case 0x241:
                    MapGridSetMetatileIdAt(x, y, 0xe43);
                    break;
                case 0x249:
                    MapGridSetMetatileIdAt(x, y, 0x21a);
                    break;
                case 0x242:
                    MapGridSetMetatileIdAt(x, y, 0xe40);
                    break;
                case 0x21a:
                    if (MapGridGetMetatileIdAt(x, y - 1) == 0x240)
                    {
                        MapGridSetMetatileIdAt(x, y, 0xe48);
                    }
                    else
                    {
                        MapGridSetMetatileIdAt(x, y, 0xe49);
                    }
                    break;
                case 0x243:
                    MapGridSetMetatileIdAt(x, y, 0xe41);
                    break;
                case 0x251:
                    MapGridSetMetatileIdAt(x, y, 0xe50);
                    break;
                case 0x250:
                    MapGridSetMetatileIdAt(x, y, 0x251);
                    break;
            }
        }
    }
}

void MauvilleGymSpecial3(void)
{
    int i, x, y;
    const struct UCoords8 *switchCoords = gUnknown_085B2B68;
    for (i = ARRAY_COUNT(gUnknown_085B2B68) - 1; i >= 0; i--)
    {
        MapGridSetMetatileIdAt(switchCoords->x, switchCoords->y, 0x206);
        switchCoords++;
    }
    for (y = 12; y < 24; y++)
    {
        for (x = 7; x < 16; x++)
        {
            switch (MapGridGetMetatileIdAt(x, y))
            {
                case 0x220:
                    MapGridSetMetatileIdAt(x, y, 0x230);
                    break;
                case 0x221:
                    MapGridSetMetatileIdAt(x, y, 0x231);
                    break;
                case 0x228:
                    MapGridSetMetatileIdAt(x, y, 0x238);
                    break;
                case 0x229:
                    MapGridSetMetatileIdAt(x, y, 0x239);
                    break;
                case 0x222:
                    MapGridSetMetatileIdAt(x, y, 0x232);
                    break;
                case 0x223:
                    MapGridSetMetatileIdAt(x, y, 0x233);
                    break;
                case 0x22a:
                    MapGridSetMetatileIdAt(x, y, 0x23a);
                    break;
                case 0x22b:
                    MapGridSetMetatileIdAt(x, y, 0x23b);
                    break;
                case 0x240:
                    MapGridSetMetatileIdAt(x, y, 0xe42);
                    break;
                case 0x241:
                    MapGridSetMetatileIdAt(x, y, 0xe43);
                    break;
                case 0x248:
                case 0x249:
                    MapGridSetMetatileIdAt(x, y, 0x21a);
                    break;
                case 0x250:
                    MapGridSetMetatileIdAt(x, y, 0x251);
                    break;
            }
        }
    }
}

static const u8 gUnknown_085B2B78[] = {0, 1, 1, 1, 1};
static const u16 gUnknown_085B2B7E[] = {0x218, 0x219, 0x21a, 0x21b, 0x21c};

void PetalburgGymSpecial1(void)
{
    gUnknown_0203AB5C = 0;
    gUnknown_0203AB5D = 0;
    PlaySE(SE_KI_GASYAN);
    CreateTask(Task_PetalburgGym, 8);
}

static void Task_PetalburgGym(u8 taskId)
{
    if (gUnknown_085B2B78[gUnknown_0203AB5D] == gUnknown_0203AB5C)
    {
        PetalburgGymFunc(gSpecialVar_0x8004, gUnknown_085B2B7E[gUnknown_0203AB5D]);
        gUnknown_0203AB5C = 0;
        if ((++gUnknown_0203AB5D) == 5)
        {
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
    }
    else
    {
        gUnknown_0203AB5C++;
    }
}

static void PetalburgGymFunc(u8 a0, u16 a1)
{
    u16 x[4];
    u16 y[4];
    u8 i;
    u8 nDoors = 0;
    switch (a0)
    {
        case 1:
            nDoors = 2;
            x[0] = 1;
            x[1] = 7;
            y[0] = 0x68;
            y[1] = 0x68;
            break;
        case 2:
            nDoors = 2;
            x[0] = 1;
            x[1] = 7;
            y[0] = 0x4e;
            y[1] = 0x4e;
            break;
        case 3:
            nDoors = 2;
            x[0] = 1;
            x[1] = 7;
            y[0] = 0x5b;
            y[1] = 0x5b;
            break;
        case 4:
            nDoors = 1;
            x[0] = 7;
            y[0] = 0x27;
            break;
        case 5:
            nDoors = 2;
            x[0] = 1;
            x[1] = 7;
            y[0] = 0x34;
            y[1] = 0x34;
            break;
        case 6:
            nDoors = 1;
            x[0] = 1;
            y[0] = 0x41;
            break;
        case 7:
            nDoors = 1;
            x[0] = 7;
            y[0] = 0xd;
            break;
        case 8:
            nDoors = 1;
            x[0] = 1;
            y[0] = 0x1a;
            break;
    }
    for (i = 0; i < nDoors; i++)
    {
        MapGridSetMetatileIdAt(x[i] + 7, y[i] + 7, a1 | METATILE_COLLISION_MASK);
        MapGridSetMetatileIdAt(x[i] + 7, y[i] + 8, (a1 + 8) | METATILE_COLLISION_MASK);
    }
    DrawWholeMapView();
}

void PetalburgGymSpecial2(void)
{
    PetalburgGymFunc(gSpecialVar_0x8004, gUnknown_085B2B7E[4]);
}

void ShowFieldMessageStringVar4(void)
{
    ShowFieldMessage(gStringVar4);
}

void StorePlayerCoordsInVars(void)
{
    gSpecialVar_0x8004 = gSaveBlock1Ptr->pos.x;
    gSpecialVar_0x8005 = gSaveBlock1Ptr->pos.y;
}

u8 GetPlayerTrainerIdOnesDigit(void)
{
    return (u16)((gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0]) % 10;
}

void GetPlayerBigGuyGirlString(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        StringCopy(gStringVar1, gText_BigGuy);
    }
    else
    {
        StringCopy(gStringVar1, gText_BigGirl);
    }
}

void GetRivalSonDaughterString(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        StringCopy(gStringVar1, gText_Daughter);
    }
    else
    {
        StringCopy(gStringVar1, gText_Son);
    }
}

u8 GetBattleOutcome(void)
{
    return gBattleOutcome;
}

void CableCarWarp(void)
{
    if (gSpecialVar_0x8004 != 0)
    {
        SetWarpDestination(MAP_GROUP(ROUTE112_CABLE_CAR_STATION), MAP_NUM(ROUTE112_CABLE_CAR_STATION), -1, 6, 4);
    }
    else
    {
        SetWarpDestination(MAP_GROUP(MT_CHIMNEY_CABLE_CAR_STATION), MAP_NUM(MT_CHIMNEY_CABLE_CAR_STATION), -1, 6, 4);
    }
}

void SetFlagInVar(void)
{
    FlagSet(gSpecialVar_0x8004);
}

u16 GetWeekCount(void)
{
    u16 weekCount = gLocalTime.days / 7;
    if (weekCount > 9999)
    {
        weekCount = 9999;
    }
    return weekCount;
}

u8 GetLeadMonFriendshipScore(void)
{
    struct Pokemon *pokemon = &gPlayerParty[GetLeadMonIndex()];
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) == 255)
    {
        return 6;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 200)
    {
        return 5;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 150)
    {
        return 4;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 100)
    {
        return 3;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 50)
    {
        return 2;
    }
    if (GetMonData(pokemon, MON_DATA_FRIENDSHIP) >= 1)
    {
        return 1;
    }
    return 0;
}

static void CB2_FieldShowRegionMap(void)
{
    FieldInitRegionMap(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void FieldShowRegionMap(void)
{
    SetMainCallback2(CB2_FieldShowRegionMap);
}

void DoPCTurnOnEffect(void)
{
    if (FuncIsActiveTask(Task_PCTurnOnEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_PCTurnOnEffect, 8);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = taskId;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[4] = 0;
    }
}

static void Task_PCTurnOnEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->data[0] == 0)
    {
        PCTurnOnEffect_0(task);
    }
}

static void PCTurnOnEffect_0(struct Task *task)
{
    u8 playerDirection;
    s8 dx = 0;
    s8 dy = 0;
    if (task->data[3] == 6)
    {
        task->data[3] = 0;
        playerDirection = GetPlayerFacingDirection();
        switch (playerDirection)
        {
            case DIR_NORTH:
                dx = 0;
                dy = -1;
                break;
            case DIR_WEST:
                dx = -1;
                dy = -1;
                break;
            case DIR_EAST:
                dx = 1;
                dy = -1;
                break;
        }
        PCTurnOnEffect_1(task->data[4], dx, dy);
        DrawWholeMapView();
        task->data[4] ^= 1;
        if ((++task->data[2]) == 5)
        {
            DestroyTask(task->data[1]);
        }
    }
    task->data[3]++;
}

static void PCTurnOnEffect_1(s16 flag, s8 dx, s8 dy)
{
    u16 tileId = 0;
    if (flag != 0)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            tileId = 0x4;
        }
        else if (gSpecialVar_0x8004 == 1)
        {
            tileId = 0x25a;
        }
        else if (gSpecialVar_0x8004 == 2)
        {
            tileId = 0x259;
        }
    }
    else
    {
        if (gSpecialVar_0x8004 == 0)
        {
            tileId = 0x5;
        }
        else if (gSpecialVar_0x8004 == 1)
        {
            tileId = 0x27f;
        }
        else if (gSpecialVar_0x8004 == 2)
        {
            tileId = 0x27e;
        }
    }
    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + 7, gSaveBlock1Ptr->pos.y + dy + 7, tileId | METATILE_COLLISION_MASK);
}

void DoPCTurnOffEffect(void)
{
    PCTurnOffEffect();
}

static void PCTurnOffEffect(void)
{
    s8 dx = 0;
    s8 dy = 0;
    u16 tileId = 0;
    u8 playerDirection = GetPlayerFacingDirection();
    switch (playerDirection)
    {
        case DIR_NORTH:
            dx = 0;
            dy = -1;
            break;
        case DIR_WEST:
            dx = -1;
            dy = -1;
            break;
        case DIR_EAST:
            dx = 1;
            dy = -1;
            break;
    }
    if (gSpecialVar_0x8004 == 0)
    {
        tileId = 0x4;
    }
    else if (gSpecialVar_0x8004 == 1)
    {
        tileId = 0x25a;
    }
    else if (gSpecialVar_0x8004 == 2)
    {
        tileId = 0x259;
    }
    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + 7, gSaveBlock1Ptr->pos.y + dy + 7, tileId | METATILE_COLLISION_MASK);
    DrawWholeMapView();
}

void DoLotteryCornerComputerEffect(void)
{
    if (FuncIsActiveTask(Task_LotteryCornerComputerEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_LotteryCornerComputerEffect, 8);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = taskId;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].data[3] = 0;
        gTasks[taskId].data[4] = 0;
    }
}

static void Task_LotteryCornerComputerEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->data[0] == 0)
    {
        LotteryCornerComputerEffect(task);
    }
}

static void LotteryCornerComputerEffect(struct Task *task)
{
    if (task->data[3] == 6)
    {
        task->data[3] = 0;
        if (task->data[4] != 0)
        {
            MapGridSetMetatileIdAt(18, 8, 0xe9d);
            MapGridSetMetatileIdAt(18, 9, 0xea5);
        }
        else
        {
            MapGridSetMetatileIdAt(18, 8, 0xe58);
            MapGridSetMetatileIdAt(18, 9, 0xe60);
        }
        DrawWholeMapView();
        task->data[4] ^= 1;
        if ((++task->data[2]) == 5)
        {
            DestroyTask(task->data[1]);
        }
    }
    task->data[3]++;
}

void EndLotteryCornerComputerEffect(void)
{
    MapGridSetMetatileIdAt(18, 8, 0xe9d);
    MapGridSetMetatileIdAt(18, 9, 0xea5);
    DrawWholeMapView();
}

void SetTrickHouseEndRoomFlag(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_TRICK_HOUSE_END_ROOM;
    *specVar = flag;
    FlagSet(flag);
}

void ResetTrickHouseEndRoomFlag(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_TRICK_HOUSE_END_ROOM;
    *specVar = flag;
    FlagClear(flag);
}

bool8 CheckLeadMonCool(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_COOL) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonBeauty(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_BEAUTY) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonCute(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_CUTE) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonSmart(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_SMART) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 CheckLeadMonTough(void)
{
    if (GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_TOUGH) < 200)
    {
        return FALSE;
    }
    return TRUE;
}

void IsGrassTypeInParty(void)
{
    u8 i;
    u16 species;
    struct Pokemon *pokemon;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(pokemon, MON_DATA_IS_EGG))
        {
            species = GetMonData(pokemon, MON_DATA_SPECIES);
            if (gBaseStats[species].type1 == TYPE_GRASS || gBaseStats[species].type2 == TYPE_GRASS)
            {
                gSpecialVar_Result = TRUE;
                return;
            }
        }
    }
    gSpecialVar_Result = FALSE;
}

void SpawnCameraObject(void)
{
    u8 obj = SpawnSpecialEventObjectParameterized(EVENT_OBJ_GFX_BOY_1, 8, EVENT_OBJ_ID_CAMERA, gSaveBlock1Ptr->pos.x + 7, gSaveBlock1Ptr->pos.y + 7, 3);
    gEventObjects[obj].invisible = TRUE;
    CameraObjectSetFollowedObjectId(gEventObjects[obj].spriteId);
}

void RemoveCameraObject(void)
{
    CameraObjectSetFollowedObjectId(GetPlayerAvatarObjectId());
    RemoveEventObjectByLocalIdAndMap(EVENT_OBJ_ID_CAMERA, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

u8 GetPokeblockNameByMonNature(void)
{
    return CopyMonFavoritePokeblockName(GetNature(&gPlayerParty[GetLeadMonIndex()]), gStringVar1);
}

void GetSecretBaseNearbyMapName(void)
{
    GetMapName(gStringVar1, VarGet(VAR_SECRET_BASE_MAP), 0);
}

u16 GetBestBattleTowerStreak(void)
{
    return GetGameStat(GAME_STAT_BATTLE_TOWER_BEST_STREAK);
}

void BufferEReaderTrainerName(void)
{
    GetEreaderTrainerName(gStringVar1);
}

u16 GetSlotMachineId(void)
{
    static const u8 gUnknown_085B2B88[] = {12, 2, 4, 5, 1, 8, 7, 11, 3, 10, 9, 6};
    static const u8 gUnknown_085B2B94[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    static const u8 gUnknown_085B2BA0[] = {3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5};

    u32 v0 = gSaveBlock1Ptr->easyChatPairs[0].unk0_0 + gSaveBlock1Ptr->easyChatPairs[0].unk2 + gUnknown_085B2B88[gSpecialVar_0x8004];
    if (GetPriceReduction(2))
    {
        return gUnknown_085B2BA0[v0 % 12];
    }
    return gUnknown_085B2B94[v0 % 12];
}

bool8 FoundAbandonedShipRoom1Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 FoundAbandonedShipRoom2Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 FoundAbandonedShipRoom4Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 FoundAbandonedShipRoom6Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 LeadMonHasEffortRibbon(void)
{
    return GetMonData(&gPlayerParty[GetLeadMonIndex()], MON_DATA_EFFORT_RIBBON, NULL);
}

void GiveLeadMonEffortRibbon(void)
{
    bool8 ribbonSet;
    struct Pokemon *leadMon;
    IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
    FlagSet(FLAG_SYS_RIBBON_GET);
    ribbonSet = TRUE;
    leadMon = &gPlayerParty[GetLeadMonIndex()];
    SetMonData(leadMon, MON_DATA_EFFORT_RIBBON, &ribbonSet);
    if (GetRibbonCount(leadMon) > 4)
    {
        sub_80EE4DC(leadMon, 0x47);
    }
}

bool8 Special_AreLeadMonEVsMaxedOut(void)
{
    if (GetMonEVCount(&gPlayerParty[GetLeadMonIndex()]) >= 510)
    {
        return TRUE;
    }
    return FALSE;
}

u8 TryUpdateRusturfTunnelState(void)
{
    if (!FlagGet(FLAG_RUSTURF_TUNNEL_OPENED) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(RUSTURF_TUNNEL) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(RUSTURF_TUNNEL))
    {
        if (FlagGet(FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1))
        {
            VarSet(VAR_RUSTURF_TUNNEL_STATE, 4);
            return TRUE;
        }
        else if (FlagGet(FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2))
        {
            VarSet(VAR_RUSTURF_TUNNEL_STATE, 5);
            return TRUE;
        }
    }
    return FALSE;
}

void SetShoalItemFlag(u16 v0)
{
    FlagSet(FLAG_SYS_SHOAL_ITEM);
}

void PutZigzagoonInPlayerParty(void)
{
    u16 monData;
    CreateMon(&gPlayerParty[0], SPECIES_ZIGZAGOON, 7, 0x20, FALSE, 0, FALSE, 0);
    monData = TRUE;
    SetMonData(&gPlayerParty[0], MON_DATA_ABILITY_NUM, &monData);
    monData = MOVE_TACKLE;
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE1, &monData);
    monData = MOVE_NONE;
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE2, &monData);
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE3, &monData);
    SetMonData(&gPlayerParty[0], MON_DATA_MOVE4, &monData);
}

bool8 IsStarterInParty(void)
{
    u8 i;
    u16 starter = GetStarterPokemon(VarGet(VAR_STARTER_MON));
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) == starter)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 ScriptCheckFreePokemonStorageSpace(void)
{
    return CheckFreePokemonStorageSpace();
}

bool8 IsPokerusInParty(void)
{
    if (!CheckPartyPokerus(gPlayerParty, 0x3f))
    {
        return FALSE;
    }
    return TRUE;
}

void sub_8139560(void)
{
    u8 taskId = CreateTask(sub_81395BC, 9);
    gTasks[taskId].data[0] = gSpecialVar_0x8005;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = gSpecialVar_0x8006;
    gTasks[taskId].data[3] = gSpecialVar_0x8007;
    gTasks[taskId].data[4] = gSpecialVar_0x8004;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_W070);
}

static void sub_81395BC(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[1]++;
    if (data[1] % data[3] == 0)
    {
        data[1] = 0;
        data[2]--;
        data[0] = -data[0];
        data[4] = -data[4];
        SetCameraPanning(data[0], data[4]);
        if (data[2] == 0)
        {
            sub_8139620(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

static void sub_8139620(u8 taskId)
{
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

bool8 FoundBlackGlasses(void)
{
    return FlagGet(FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES);
}

void SetRoute119Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
    {
        SetSav1Weather(20);
    }
}

void SetRoute123Weather(void)
{
    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()) != TRUE)
    {
        SetSav1Weather(21);
    }
}

u8 GetLeadMonIndex(void)
{
    u8 i;
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_EGG && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != 0)
        {
            return i;
        }
    }
    return 0;
}

u16 ScriptGetPartyMonSpecies(void)
{
    return GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES2, NULL);
}

void nullsub_54(void)
{

}

u16 GetDaysUntilPacifidlogTMAvailable(void)
{
    u16 tmReceivedDay = VarGet(VAR_PACIFIDLOG_TM_RECEIVED_DAY);
    if (gLocalTime.days - tmReceivedDay >= 7)
    {
        return 0;
    }
    else if (gLocalTime.days < 0)
    {
        return 8;
    }
    return 7 - (gLocalTime.days - tmReceivedDay);
}

u16 SetPacifidlogTMReceivedDay(void)
{
    VarSet(VAR_PACIFIDLOG_TM_RECEIVED_DAY, gLocalTime.days);
    return gLocalTime.days;
}

bool8 MonOTNameMatchesPlayer(void)
{
    if (GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LANGUAGE) != GAME_LANGUAGE)
    {
        return TRUE;    // huh?
    }

    GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_OT_NAME, gStringVar1);
    if (!StringCompare(gSaveBlock2Ptr->playerName, gStringVar1))
    {
        return FALSE;
    }
    return TRUE;
}

void BufferLottoTicketNumber(void)
{
    if (gSpecialVar_Result >= 10000)
    {
        TV_PrintIntToStringVar(0, gSpecialVar_Result);
    }
    else if (gSpecialVar_Result >= 1000)
    {
        gStringVar1[0] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 1, gSpecialVar_Result, 0, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 100)
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 2, gSpecialVar_Result, 0, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 10)
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        gStringVar1[2] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 3, gSpecialVar_Result, 0, CountDigits(gSpecialVar_Result));
    }
    else
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        gStringVar1[2] = CHAR_0;
        gStringVar1[3] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 4, gSpecialVar_Result, 0, CountDigits(gSpecialVar_Result));
    }
}

u16 sub_813986C(void)
{
    switch (gSpecialVar_Result)
    {
        case 0:
            return mevent_081445C0(3);
        case 1:
            return mevent_081445C0(4);
        case 2:
            return mevent_081445C0(0);
        case 3:
            return mevent_081445C0(1);
        case 4:
            return mevent_081445C0(2);
        default:
            return 0;
    }
}

bool8 sub_81398C0(void)
{
    if (gSpecialVar_0x8004 >= ITEM_TM01 && gSpecialVar_0x8004 <= ITEM_HM08)
    {
        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(gSpecialVar_0x8004)]);
        return TRUE;
    }

    return FALSE;
}

bool8 sub_813990C(void)
{
    u8 partyCount = CalculatePlayerPartyCount();
    u8 i;

    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_BAD_EGG) == 1)
            return TRUE;
    }

    return FALSE;
}

bool8 InMultiBattleRoom(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_BATTLE_ROOM) &&
        VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_MULTIS)
        return TRUE;
    return FALSE;
}

void sub_8139980(void)
{
    SetCameraPanningCallback(NULL);
    SetCameraPanning(8, 0);
}

const struct WindowTemplate gUnknown_085B2BAC = {
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 1,
    .width = 8,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 8,
};

const u8 *const gElevatorFloorsTable[] = {
    gText_B4F,
    gText_B3F,
    gText_B2F,
    gText_B1F,
    gText_1F,
    gText_2F,
    gText_3F,
    gText_4F,
    gText_5F,
    gText_6F,
    gText_7F,
    gText_8F,
    gText_9F,
    gText_10F,
    gText_11F,
    gText_Rooftop
};

const u16 gUnknown_085B2BF4[][3] =
{
    {0x0329, 0x032a, 0x032b},
    {0x0331, 0x0332, 0x0333},
    {0x0339, 0x033a, 0x033b},
};
const u16 gUnknown_085B2C06[][3] =
{
    {0x0329, 0x032b, 0x032a},
    {0x0331, 0x0333, 0x0332},
    {0x0339, 0x033b, 0x033a},
};

void SetDepartmentStoreFloorVar(void)
{
    u8 deptStoreFloor;
    switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
    {
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_1F):
            deptStoreFloor = 4;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_2F):
            deptStoreFloor = 5;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_3F):
            deptStoreFloor = 6;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_4F):
            deptStoreFloor = 7;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_5F):
            deptStoreFloor = 8;
            break;
        case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP):
            deptStoreFloor = 15;
            break;
        default:
            deptStoreFloor = 4;
            break;
    }
    VarSet(VAR_DEPT_STORE_FLOOR, deptStoreFloor);
}

u16 sub_81399F4(void)
{
    gUnknown_0203AB60 = 0;
    gUnknown_0203AB62 = 0;

    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(LILYCOVE_CITY_DEPARTMENT_STORE_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_5F):
                gUnknown_0203AB60 = 0;
                gUnknown_0203AB62 = 0;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_4F):
                gUnknown_0203AB60 = 0;
                gUnknown_0203AB62 = 1;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_3F):
                gUnknown_0203AB60 = 0;
                gUnknown_0203AB62 = 2;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_2F):
                gUnknown_0203AB60 = 0;
                gUnknown_0203AB62 = 3;
                break;
            case MAP_NUM(LILYCOVE_CITY_DEPARTMENT_STORE_1F):
                gUnknown_0203AB60 = 0;
                gUnknown_0203AB62 = 4;
                break;
        }
    }

    return gUnknown_0203AB62;
}

void ShakeScreenInElevator(void)
{
    static const u8 gUnknown_085B2C18[] = { 0x08, 0x10, 0x18, 0x20, 0x26, 0x2e, 0x34, 0x38, 0x39 };

    s16 *data = gTasks[CreateTask(sub_8139AF4, 9)].data;
    u16 floorDelta;

    data[1] = 0;
    data[2] = 0;
    data[4] = 1;

    if (gSpecialVar_0x8005 > gSpecialVar_0x8006)
    {
        floorDelta = gSpecialVar_0x8005 - gSpecialVar_0x8006;
        data[6] = 1;
    }
    else
    {
        floorDelta = gSpecialVar_0x8006 - gSpecialVar_0x8005;
        data[6] = 0;
    }

    if (floorDelta > 8)
        floorDelta = 8;

    data[5] = gUnknown_085B2C18[floorDelta];

    SetCameraPanningCallback(NULL);
    sub_8139C2C(floorDelta, data[6]);
    PlaySE(SE_ELEBETA);
}

static void sub_8139AF4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1]++;
    if (data[1] % 3 == 0)
    {
        data[1] = 0;
        data[2]++;
        data[4] = -data[4];
        SetCameraPanning(0, data[4]);
        if (data[2] == data[5])
        {
            PlaySE(SE_PINPON);
            DestroyTask(taskId);
            EnableBothScriptContexts();
            InstallCameraPanAheadCallback();
        }
    }
}

void sub_8139B60(void)
{
    int xPos;

    gUnknown_0203AB5E = AddWindow(&gUnknown_085B2BAC);
    SetStandardWindowBorderStyle(gUnknown_0203AB5E, 0);

    xPos = GetStringCenterAlignXOffset(1, gText_ElevatorNowOn, 64);
    AddTextPrinterParameterized(gUnknown_0203AB5E, 1, gText_ElevatorNowOn, xPos, 1, TEXT_SPEED_FF, NULL);

    xPos = GetStringCenterAlignXOffset(1, gElevatorFloorsTable[gSpecialVar_0x8005], 64);
    AddTextPrinterParameterized(gUnknown_0203AB5E, 1, gElevatorFloorsTable[gSpecialVar_0x8005], xPos, 17, TEXT_SPEED_FF, NULL);

    PutWindowTilemap(gUnknown_0203AB5E);
    CopyWindowToVram(gUnknown_0203AB5E, 3);
}

void sub_8139C10(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_0203AB5E, TRUE);
    RemoveWindow(gUnknown_0203AB5E);
}

static void sub_8139C2C(u16 a1, u8 a2)
{
    static const u8 gUnknown_085B2C21[] = { 0x03, 0x06, 0x09, 0x0c, 0x0f, 0x12, 0x15, 0x18, 0x1b };

    if (FuncIsActiveTask(sub_8139C80) != TRUE)
    {
        u8 taskId = CreateTask(sub_8139C80, 8);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = a2;
        gTasks[taskId].data[3] = gUnknown_085B2C21[a1];
    }
}

static void sub_8139C80(u8 taskId)
{
    u8 x, y;
    s16 *data = gTasks[taskId].data;

    if (data[1] == 6)
    {
        data[0]++;
        if (data[2] == 0)
        {
            for (y = 0; y < 3; y++)
            {
                for (x = 0; x < 3; x++)
                {
                    MapGridSetMetatileIdAt(x + 8, y + 7, gUnknown_085B2BF4[y][data[0] % 3] | METATILE_COLLISION_MASK);
                }
            }
        }
        else
        {
            for (y = 0; y < 3; y++)
            {
                for (x = 0; x < 3; x++)
                {
                    MapGridSetMetatileIdAt(x + 8, y + 7, gUnknown_085B2C06[y][data[0] % 3] | METATILE_COLLISION_MASK);
                }
            }
        }
        DrawWholeMapView();
        data[1] = 0;
        if (data[0] == data[3])
        {
            DestroyTask(taskId);
        }
    }
    data[1]++;
}

void sub_8139D98(void)
{
    u8 i;
    u32 ivStorage[NUM_STATS];

    ivStorage[STAT_HP] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HP_IV);
    ivStorage[STAT_ATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ATK_IV);
    ivStorage[STAT_DEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_DEF_IV);
    ivStorage[STAT_SPEED] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPEED_IV);
    ivStorage[STAT_SPATK] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPATK_IV);
    ivStorage[STAT_SPDEF] = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPDEF_IV);

    gSpecialVar_0x8005 = 0;

    for (i = 0; i < NUM_STATS; i++)
    {
        gSpecialVar_0x8005 += ivStorage[i];
    }

    gSpecialVar_0x8006 = 0;
    gSpecialVar_0x8007 = ivStorage[STAT_HP];

    for (i = 1; i < NUM_STATS; i++)
    {
        if (ivStorage[gSpecialVar_0x8006] < ivStorage[i])
        {
            gSpecialVar_0x8006 = i;
            gSpecialVar_0x8007 = ivStorage[i];
        }
        else if (ivStorage[gSpecialVar_0x8006] == ivStorage[i])
        {
            u16 randomNumber = Random();
            if (randomNumber & 1)
            {
                gSpecialVar_0x8006 = i;
                gSpecialVar_0x8007 = ivStorage[i];
            }
        }
    }
}

bool8 warp0_in_pokecenter(void)
{
    static const u16 gUnknown_085B2C2A[] = { 0x0202, 0x0301, 0x0405, 0x0504, 0x0604, 0x0700, 0x0804, 0x090b, 0x0a05, 0x0b05, 0x0c02, 0x0d06, 0x0e03, 0x0f02, 0x100c, 0x100a, 0x1a35, 0x193c, 0xFFFF };

    int i;
    u16 map = (gLastUsedWarp.mapGroup << 8) + gLastUsedWarp.mapNum;

    for (i = 0; gUnknown_085B2C2A[i] != 0xFFFF; i++)
    {
        if (gUnknown_085B2C2A[i] == map)
            return TRUE;
    }

    return FALSE;
}

bool32 sub_8139ED0(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(TRAINER_HILL_ENTRANCE) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(TRAINER_HILL_ENTRANCE))
    {
        return FALSE;
    }
    return TRUE;
}

void UpdateFrontierManiac(u16 a0)
{
    u16 *var = GetVarPointer(VAR_FRONTIER_MANIAC_FACILITY);
    *var += a0;
    *var %= 10;
}

void sub_8139F20(void)
{
    static const u8 *const gUnknown_085B2C50[][3] = {
        { BattleFrontier_Lounge2_Text_260971, BattleFrontier_Lounge2_Text_260A1E, BattleFrontier_Lounge2_Text_260AE7 },
        { BattleFrontier_Lounge2_Text_2619AC, BattleFrontier_Lounge2_Text_261A91, BattleFrontier_Lounge2_Text_261B0C },
        { BattleFrontier_Lounge2_Text_261B95, BattleFrontier_Lounge2_Text_261B95, BattleFrontier_Lounge2_Text_261B95 },
        { BattleFrontier_Lounge2_Text_261C1A, BattleFrontier_Lounge2_Text_261C1A, BattleFrontier_Lounge2_Text_261C1A },
        { BattleFrontier_Lounge2_Text_260BC4, BattleFrontier_Lounge2_Text_260C6D, BattleFrontier_Lounge2_Text_260D3A },
        { BattleFrontier_Lounge2_Text_260E1E, BattleFrontier_Lounge2_Text_260EC7, BattleFrontier_Lounge2_Text_260F74 },
        { BattleFrontier_Lounge2_Text_2614E6, BattleFrontier_Lounge2_Text_261591, BattleFrontier_Lounge2_Text_26166F },
        { BattleFrontier_Lounge2_Text_261282, BattleFrontier_Lounge2_Text_261329, BattleFrontier_Lounge2_Text_261403 },
        { BattleFrontier_Lounge2_Text_261026, BattleFrontier_Lounge2_Text_2610CC, BattleFrontier_Lounge2_Text_261194 },
        { BattleFrontier_Lounge2_Text_26174D, BattleFrontier_Lounge2_Text_2617F9, BattleFrontier_Lounge2_Text_2618C4 },
    };

    static const u8 gUnknown_085B2CC8[][2] = {
        { 0x15, 0x38 },
        { 0x15, 0x23 },
        { 0xff, 0xff },
        { 0xff, 0xff },
        { 0x02, 0x04 },
        { 0x07, 0x15 },
        { 0x07, 0x15 },
        { 0x0e, 0x1c },
        { 0x0d, 0x70 },
        { 0x07, 0x38 }
    };

    u8 i;
    u16 unk = 0;
    u16 var = VarGet(VAR_FRONTIER_MANIAC_FACILITY);
    switch (var)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            if (gSaveBlock2Ptr->frontier.towerWinStreaks[var][0] >= gSaveBlock2Ptr->frontier.towerWinStreaks[var][1])
            {
                unk = gSaveBlock2Ptr->frontier.towerWinStreaks[var][0];
            }
            else
            {
                unk = gSaveBlock2Ptr->frontier.towerWinStreaks[var][1];
            }
            break;
        case 4:
            if (gSaveBlock2Ptr->frontier.domeWinStreaks[0][0] >= gSaveBlock2Ptr->frontier.domeWinStreaks[0][1])
            {
                unk = gSaveBlock2Ptr->frontier.domeWinStreaks[0][0];
            }
            else
            {
                unk = gSaveBlock2Ptr->frontier.domeWinStreaks[0][1];
            }
            break;
        case 5:
            if (gSaveBlock2Ptr->frontier.factoryWinStreaks[0][0] >= gSaveBlock2Ptr->frontier.factoryWinStreaks[0][1])
            {
                unk = gSaveBlock2Ptr->frontier.factoryWinStreaks[0][0];
            }
            else
            {
                unk = gSaveBlock2Ptr->frontier.factoryWinStreaks[0][1];
            }
            break;
        case 6:
            if (gSaveBlock2Ptr->frontier.palaceWinStreaks[0][0] >= gSaveBlock2Ptr->frontier.palaceWinStreaks[0][1])
            {
                unk = gSaveBlock2Ptr->frontier.palaceWinStreaks[0][0];
            }
            else
            {
                unk = gSaveBlock2Ptr->frontier.palaceWinStreaks[0][1];
            }
            break;
        case 7:
            if (gSaveBlock2Ptr->frontier.arenaWinStreaks[0] >= gSaveBlock2Ptr->frontier.arenaWinStreaks[1])
            {
                unk = gSaveBlock2Ptr->frontier.arenaWinStreaks[0];
            }
            else
            {
                unk = gSaveBlock2Ptr->frontier.arenaWinStreaks[1];
            }
            break;
        case 8:
            if (gSaveBlock2Ptr->frontier.pikeWinStreaks[0] >= gSaveBlock2Ptr->frontier.pikeWinStreaks[1])
            {
                unk = gSaveBlock2Ptr->frontier.pikeWinStreaks[0];
            }
            else
            {
                unk = gSaveBlock2Ptr->frontier.pikeWinStreaks[1];
            }
            break;
        case 9:
            if (gSaveBlock2Ptr->frontier.pyramidWinStreaks[0] >= gSaveBlock2Ptr->frontier.pyramidWinStreaks[1])
            {
                unk = gSaveBlock2Ptr->frontier.pyramidWinStreaks[0];
            }
            else
            {
                unk = gSaveBlock2Ptr->frontier.pyramidWinStreaks[1];
            }
            break;
    }

    for (i = 0; i < 2 && gUnknown_085B2CC8[var][i] < unk; i++);

    ShowFieldMessage(gUnknown_085B2C50[var][i]);
}

void sub_813A080(void)
{
    static const u16 gUnknown_085B2CDC[] = {
        0x0007, 0x000e, 0x0015, 0x001c, 0x0023, 0x0031, 0x003f, 0x004d, 0x005b, 0x0000
    };

    u8 i;
    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (battleMode == FRONTIER_MODE_MULTIS && !FlagGet(FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER))
    {
        gSpecialVar_0x8005 = 5;
        gSpecialVar_0x8006 = 4;
        return;
    }

    for (i = 0; i < 9; i++)
    {
        if (gUnknown_085B2CDC[i] > gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode])
        {
            gSpecialVar_0x8005 = 4;
            gSpecialVar_0x8006 = i + 5;
            return;
        }
    }

    gSpecialVar_0x8005 = 4;
    gSpecialVar_0x8006 = 12;
}

void sub_813A128(void)
{
    u8 taskId = CreateTask(sub_813A2DC, 8);
    struct Task *task = &gTasks[taskId];
    task->data[11] = gSpecialVar_0x8004;

    switch (gSpecialVar_0x8004)
    {
        case 0:
            task->data[0] = 1;
            task->data[1] = 1;
            task->data[2] = 1;
            task->data[3] = 1;
            task->data[4] = 1;
            task->data[5] = 1;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 1:
            task->data[0] = 5;
            task->data[1] = 8;
            task->data[2] = 1;
            task->data[3] = 1;
            task->data[4] = 9;
            task->data[5] = 10;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 2:
            task->data[0] = 6;
            task->data[1] = 12;
            task->data[2] = 1;
            task->data[3] = 1;
            task->data[4] = 7;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 3:
            task->data[0] = 6;
            task->data[1] = 11;
            task->data[2] = 14;
            task->data[3] = 1;
            task->data[4] = 15;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 4:
            task->data[0] = 6;
            task->data[1] = 6;
            task->data[2] = 14;
            task->data[3] = 1;
            task->data[4] = 15;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 5:
            task->data[0] = 6;
            task->data[1] = 7;
            task->data[2] = 14;
            task->data[3] = 1;
            task->data[4] = 15;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 6:
            task->data[0] = 6;
            task->data[1] = 10;
            task->data[2] = 14;
            task->data[3] = 1;
            task->data[4] = 15;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 7:
            task->data[0] = 6;
            task->data[1] = 12;
            task->data[2] = 15;
            task->data[3] = 1;
            task->data[4] = 14;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 8:
            task->data[0] = 6;
            task->data[1] = 10;
            task->data[2] = 17;
            task->data[3] = 1;
            task->data[4] = 11;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 9:
        case 10:
            task->data[0] = 6;
            task->data[1] = 11;
            task->data[2] = 15;
            task->data[3] = 1;
            task->data[4] = 14;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 11:
            task->data[0] = 6;
            task->data[1] = 7;
            task->data[2] = 19;
            task->data[3] = 1;
            task->data[4] = 10;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        case 12:
            task->data[0] = 6;
            task->data[1] = 7;
            task->data[2] = 17;
            task->data[3] = 1;
            task->data[4] = 12;
            task->data[5] = 12;
            task->data[6] = 0;
            task->data[15] = taskId;
            break;
        default:
            gSpecialVar_Result = 0x7F;
            DestroyTask(taskId);
            break;
    }
}

static const u8 *const gUnknown_085B2CF0[][16] = {
    {
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_BlueFlute,
        gText_YellowFlute,
        gText_RedFlute,
        gText_WhiteFlute,
        gText_BlackFlute,
        gText_PrettyChair,
        gText_PrettyDesk,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_0Pts,
        gText_10Pts,
        gText_20Pts,
        gText_30Pts,
        gText_40Pts,
        gText_50Pts,
        gText_60Pts,
        gText_70Pts,
        gText_80Pts,
        gText_90Pts,
        gText_100Pts,
        gText_QuestionMark,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_KissPoster16BP,
        gText_KissCushion32BP,
        gText_SmoochumDoll32BP,
        gText_TogepiDoll48BP,
        gText_MeowthDoll48BP,
        gText_ClefairyDoll48BP,
        gText_DittoDoll48BP,
        gText_CyndaquilDoll80BP,
        gText_ChikoritaDoll80BP,
        gText_TotodileDoll80BP,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_LaprasDoll128BP,
        gText_SnorlaxDoll128BP,
        gText_VenusaurDoll256BP,
        gText_CharizardDoll256BP,
        gText_BlastoiseDoll256BP,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_Protein1BP,
        gText_Calcium1BP,
        gText_Iron1BP,
        gText_Zinc1BP,
        gText_Carbos1BP,
        gText_HpUp1BP,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_Leftovers48BP,
        gText_WhiteHerb48BP,
        gText_QuickClaw48BP,
        gText_MentalHerb48BP,
        gText_BrightPowder64BP,
        gText_ChoiceBand64BP,
        gText_KingsRock64BP,
        gText_FocusBand64BP,
        gText_ScopeLens64BP,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_EnergyPowder50,
        gText_EnergyRoot80,
        gText_HealPowder50,
        gText_RevivalHerb300,
        gText_Protein1000,
        gText_Iron1000,
        gText_Carbos1000,
        gText_Calcium1000,
        gText_Zinc1000,
        gText_HPUp1000,
        gText_PPUp3000,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_BattleTower2,
        gText_BattleDome,
        gText_BattlePalace,
        gText_BattleArena,
        gText_BattleFactory,
        gText_BattlePike,
        gText_BattlePyramid,
        gText_RankingHall,
        gText_ExchangeService,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_Softboiled16BP,
        gText_SeismicToss24BP,
        gText_DreamEater24BP,
        gText_MegaPunch24BP,
        gText_MegaKick48BP,
        gText_BodySlam48BP,
        gText_RockSlide48BP,
        gText_Counter48BP,
        gText_ThunderWave48BP,
        gText_SwordsDance48BP,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_DefenseCurl16BP,
        gText_Snore24BP,
        gText_MudSlap24BP,
        gText_Swift24BP,
        gText_IcyWind24BP,
        gText_Endure48BP,
        gText_PsychUp48BP,
        gText_IcePunch48BP,
        gText_ThunderPunch48BP,
        gText_FirePunch48BP,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_SlateportCity,
        gText_BattleFrontier,
        gText_SouthernIsland,
        gText_NavelRock,
        gText_BirthIsland,
        gText_FarawayIsland,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    },
    {
        gText_BattleTrainers,
        gText_BattleBasics,
        gText_PokemonNature,
        gText_PokemonMoves,
        gText_Underpowered,
        gText_WhenInDanger,
        gText_Exit,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    }
};

static void sub_813A2DC(u8 taskId)
{
    u32 unk1;
    u8 i, windowId;
    struct WindowTemplate template;
    struct Task *task = &gTasks[taskId];

    ScriptContext2_Enable();
    gUnknown_0203AB68 = 0;
    gUnknown_0203AB6C = 0x40;
    sub_813AA60(task->data[11], 0);
    sub_813ACE8(task->data[11], 0);
    gUnknown_0203AB64 = AllocZeroed(task->data[1] * 8);
    gUnknown_0203AB6A = 0;
    sub_813A42C();

    for (unk1 = 0, i = 0; i < task->data[1]; i++)
    {
        const u8 *text = gUnknown_085B2CF0[gSpecialVar_0x8004][i];
        gUnknown_0203AB64[i].name = text;
        gUnknown_0203AB64[i].id = i;
        unk1 = display_text_and_get_width(text, unk1);
    }

    task->data[4] = convert_pixel_width_to_tile_width(unk1);

    if (task->data[2] + task->data[4] > 0x1D)
    {
        int unk2 = 0x1D - task->data[4];
        if (unk2 < 0)
        {
            task->data[2] = 0;
        }
        else
        {
            task->data[2] = unk2;
        }
    }

    template = CreateWindowTemplate(0, task->data[2], task->data[3], task->data[4], task->data[5], 0xF, 0x64);
    windowId = AddWindow(&template);
    task->data[13] = windowId;
    SetStandardWindowBorderStyle(windowId, 0);

    gUnknown_030061D0.totalItems = task->data[1];
    gUnknown_030061D0.maxShowed = task->data[0];
    gUnknown_030061D0.windowId = task->data[13];

    sub_813A694(taskId);
    task->data[14] = ListMenuInit(&gUnknown_030061D0, task->data[7], task->data[8]);
    schedule_bg_copy_tilemap_to_vram(0);
    gTasks[taskId].func = sub_813A4EC;
}

static void sub_813A42C(void)
{
    gUnknown_030061D0.items = gUnknown_0203AB64;
    gUnknown_030061D0.moveCursorFunc = sub_813A46C;
    gUnknown_030061D0.itemPrintFunc = NULL;
    gUnknown_030061D0.totalItems = 1;
    gUnknown_030061D0.maxShowed = 1;
    gUnknown_030061D0.windowId = 0;
    gUnknown_030061D0.header_X = 0;
    gUnknown_030061D0.item_X = 8;
    gUnknown_030061D0.cursor_X = 0;
    gUnknown_030061D0.upText_Y = 1;
    gUnknown_030061D0.cursorPal = 2;
    gUnknown_030061D0.fillValue = 1;
    gUnknown_030061D0.cursorShadowPal = 3;
    gUnknown_030061D0.lettersSpacing = 0;
    gUnknown_030061D0.itemVerticalPadding = 0;
    gUnknown_030061D0.scrollMultiple = 0;
    gUnknown_030061D0.fontId = 1;
    gUnknown_030061D0.cursorKind = 0;
}

static void sub_813A46C(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    u8 taskId;
    PlaySE(SE_SELECT);
    taskId = FindTaskIdByFunc(sub_813A4EC);
    if (taskId != 0xFF)
    {
        u16 misc;
        struct Task *task = &gTasks[taskId];
        ListMenuGetScrollAndRow(task->data[14], &misc, NULL);
        gUnknown_0203AB68 = misc;
        ListMenuGetCurrentItemArrayId(task->data[14], &misc);
        sub_813AC44(task->data[11], gUnknown_0203AB6A);
        sub_813AA60(task->data[11], misc);
        sub_813AD34(task->data[11], misc);
        gUnknown_0203AB6A = misc;
    }
}

static void sub_813A4EC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    s32 input = ListMenu_ProcessInput(task->data[14]);

    switch (input)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        gSpecialVar_Result = 0x7F;
        PlaySE(SE_SELECT);
        sub_813A570(taskId);
        break;
    default:
        gSpecialVar_Result = input;
        PlaySE(SE_SELECT);
        if (!task->data[6])
        {
            sub_813A570(taskId);
        }
        else if (input == task->data[1] - 1)
        {
            sub_813A570(taskId);
        }
        else
        {
            sub_813A738(taskId);
            task->func = sub_813A600;
            EnableBothScriptContexts();
        }
        break;
    }
}

static void sub_813A570(u8 taskId)
{
    u16 array;
    struct Task *task = &gTasks[taskId];
    ListMenuGetCurrentItemArrayId(task->data[14], &array);
    sub_813AC44(task->data[11], array);
    sub_813A738(taskId);
    DestroyListMenuTask(task->data[14], NULL, NULL);
    Free(gUnknown_0203AB64);
    ClearStdWindowAndFrameToTransparent(task->data[13], 1);
    FillWindowPixelBuffer(task->data[13], PIXEL_FILL(0));
    CopyWindowToVram(task->data[13], 2);
    RemoveWindow(task->data[13]);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void sub_813A600(u8 taskId)
{
    switch (gTasks[taskId].data[6])
    {
        case 1:
        default:
            break;
        case 2:
            gTasks[taskId].data[6] = 1;
            gTasks[taskId].func = sub_813A664;
            break;
    }
}

void sub_813A630(void)
{
    u8 taskId = FindTaskIdByFunc(sub_813A600);
    if (taskId == 0xFF)
    {
        EnableBothScriptContexts();
    }
    else
    {
        gTasks[taskId].data[6]++;
    }
}

static void sub_813A664(u8 taskId)
{
    ScriptContext2_Enable();
    sub_813A694(taskId);
    gTasks[taskId].func = sub_813A4EC;
}

static void sub_813A694(u8 taskId)
{
    static const struct ScrollArrowsTemplate gUnknown_085B3030 = {
        .firstArrowType = SCROLL_ARROW_UP,
        .firstX = 0,
        .firstY = 0,
        .secondArrowType = SCROLL_ARROW_DOWN,
        .secondX = 0,
        .secondY = 0,
        .fullyUpThreshold = 0,
        .fullyDownThreshold = 0,
        .tileTag = 2000,
        .palTag = 100,
        .palNum = 0
    };

    struct Task *task = &gTasks[taskId];
    struct ScrollArrowsTemplate template = gUnknown_085B3030;
    if (task->data[0] != task->data[1])
    {
        template.firstX = (task->data[4] / 2) * 8 + 12 + (task->data[2] - 1) * 8;
        template.firstY = 8;
        template.secondX = (task->data[4] / 2) * 8 + 12 + (task->data[2] - 1) * 8;
        template.secondY = task->data[5] * 8 + 10;
        template.fullyUpThreshold = 0;
        template.fullyDownThreshold = task->data[1] - task->data[0];
        task->data[12] = AddScrollIndicatorArrowPair(&template, &gUnknown_0203AB68);
    }
}

static void sub_813A738(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (task->data[0] != task->data[1])
    {
        RemoveScrollIndicatorArrowPair(task->data[12]);
    }
}

void nullsub_55(void)
{

}

void sub_813A76C(void)
{
    u8 i;
    for (i = 0; i < 2; i++)
    {
        if (gLinkPlayers[i].gender == MALE)
        {
            VarSet(VAR_OBJ_GFX_ID_F - i, EVENT_OBJ_GFX_BRENDAN_NORMAL);
        }
        else
        {
            VarSet(VAR_OBJ_GFX_ID_F - i, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL);
        }
    }
}

void sub_813A7B8(void)
{
    static const u8 *const gUnknown_085B3040[] = {
        BattleFrontier_Lounge5_Text_26468D,
        BattleFrontier_Lounge5_Text_2646E5,
        BattleFrontier_Lounge5_Text_264741,
        BattleFrontier_Lounge5_Text_2647A4,
        BattleFrontier_Lounge5_Text_2647FC,
        BattleFrontier_Lounge5_Text_264858,
        BattleFrontier_Lounge5_Text_2648BE,
        BattleFrontier_Lounge5_Text_264916,
        BattleFrontier_Lounge5_Text_264972,
        BattleFrontier_Lounge5_Text_2649D5,
        BattleFrontier_Lounge5_Text_264A3F,
        BattleFrontier_Lounge5_Text_264A9B,
        BattleFrontier_Lounge5_Text_264AF3,
        BattleFrontier_Lounge5_Text_264B5D,
        BattleFrontier_Lounge5_Text_2648BE,
        BattleFrontier_Lounge5_Text_264BC3,
        BattleFrontier_Lounge5_Text_264C36,
        BattleFrontier_Lounge5_Text_2648BE,
        BattleFrontier_Lounge5_Text_264C95,
        BattleFrontier_Lounge5_Text_264D01,
        BattleFrontier_Lounge5_Text_264D6B,
        BattleFrontier_Lounge5_Text_264DD7,
        BattleFrontier_Lounge5_Text_264E33,
        BattleFrontier_Lounge5_Text_264E8F,
        BattleFrontier_Lounge5_Text_2648BE,
    };

    u8 nature;

    if (gSpecialVar_0x8004 >= PARTY_SIZE)
    {
        gSpecialVar_0x8004 = 0;
    }

    nature = GetNature(&gPlayerParty[gSpecialVar_0x8004]);
    ShowFieldMessage(gUnknown_085B3040[nature]);
}

void UpdateFrontierGambler(u16 a0)
{
    u16 *var = GetVarPointer(VAR_FRONTIER_GAMBLER_FACILITY);
    *var += a0;
    *var %= 12;
}

void sub_813A820(void)
{
    static const u8 *const gUnknown_085B30A4[] = {
        BattleFrontier_Lounge3_Text_262261,
        BattleFrontier_Lounge3_Text_26230D,
        BattleFrontier_Lounge3_Text_2623B9,
        BattleFrontier_Lounge3_Text_262464,
        BattleFrontier_Lounge3_Text_26250E,
        BattleFrontier_Lounge3_Text_2625B8,
        BattleFrontier_Lounge3_Text_26266A,
        BattleFrontier_Lounge3_Text_26271C,
        BattleFrontier_Lounge3_Text_2627C9,
        BattleFrontier_Lounge3_Text_262876,
        BattleFrontier_Lounge3_Text_26291A,
        BattleFrontier_Lounge3_Text_2629BC,
    };

    u16 var = VarGet(VAR_FRONTIER_GAMBLER_FACILITY);
    ShowFieldMessage(gUnknown_085B30A4[var]);
    VarSet(VAR_FRONTIER_GAMBLER_SET_FACILITY_F, var);
}

void sub_813A854(void)
{
    static const u8 *const gUnknown_085B30D4[] = {
        BattleFrontier_Lounge3_Text_262C04,
        BattleFrontier_Lounge3_Text_262C90,
        BattleFrontier_Lounge3_Text_262D1C,
        BattleFrontier_Lounge3_Text_262DA7,
        BattleFrontier_Lounge3_Text_262E34,
        BattleFrontier_Lounge3_Text_262EC1,
        BattleFrontier_Lounge3_Text_262F56,
        BattleFrontier_Lounge3_Text_262FEB,
        BattleFrontier_Lounge3_Text_263078,
        BattleFrontier_Lounge3_Text_263105,
        BattleFrontier_Lounge3_Text_26318C,
        BattleFrontier_Lounge3_Text_263211,
    };

    ShowFieldMessage(gUnknown_085B30D4[VarGet(VAR_FRONTIER_GAMBLER_SET_FACILITY_F)]);
}

void sub_813A878(u8 a0)
{
    static const u16 gUnknown_085B3104[] = {0x0000, 0x0001, 0x0002, 0x0100, 0x0101, 0x0400, 0x0401, 0x0200, 0x0201, 0x0300, 0x0500, 0x0600};

    u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u16 var2 = VarGet(VAR_FRONTIER_GAMBLER_SET_FACILITY_F);
    u16 frontierFacilityId = VarGet(VAR_FRONTIER_FACILITY);

    if (VarGet(VAR_FRONTIER_GAMBLER_PLACED_BET_F) == 1)
    {
        if (gUnknown_085B3104[var2] == (frontierFacilityId << 8) + battleMode)
        {
            if (a0 != 0)
            {
                VarSet(VAR_FRONTIER_GAMBLER_PLACED_BET_F, 2);
            }
            else
            {
                VarSet(VAR_FRONTIER_GAMBLER_PLACED_BET_F, 3);
            }
        }
    }
}

void sub_813A8FC(void)
{
    u8 string[32];
    u32 x;
    StringCopy(ConvertIntToDecimalStringN(string, gSaveBlock2Ptr->frontier.battlePoints, STR_CONV_MODE_RIGHT_ALIGN, 4), gText_BP);
    x = GetStringRightAlignXOffset(1, string, 48);
    AddTextPrinterParameterized(gUnknown_0203AB6D, 1, string, x, 1, 0, NULL);
}

void sub_813A958(void)
{
    static const struct WindowTemplate gUnknown_085B311C = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 6,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 8,
    };

    gUnknown_0203AB6D = AddWindow(&gUnknown_085B311C);
    SetStandardWindowBorderStyle(gUnknown_0203AB6D, 0);
    sub_813A8FC();
    CopyWindowToVram(gUnknown_0203AB6D, 2);
}

void sub_813A988(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_0203AB6D, TRUE);
    RemoveWindow(gUnknown_0203AB6D);
}

void sub_813A9A4(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints < gSpecialVar_0x8004)
    {
        gSaveBlock2Ptr->frontier.battlePoints = 0;
    }
    else
    {
        gSaveBlock2Ptr->frontier.battlePoints -= gSpecialVar_0x8004;
    }
}

void sub_813A9D0(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004 > 9999)
    {
        gSaveBlock2Ptr->frontier.battlePoints = 9999;
    }
    else
    {
        gSaveBlock2Ptr->frontier.battlePoints = gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004;
    }
}

u16 sub_813AA04(void)
{
    return gSaveBlock2Ptr->frontier.battlePoints;
}

void sub_813AA18(void)
{
    static const struct WindowTemplate gUnknown_085B3124 = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 9,
        .width = 4,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 20,
    };

    gUnknown_0203AB6E = AddWindow(&gUnknown_085B3124);
    SetStandardWindowBorderStyle(gUnknown_0203AB6E, 0);
    CopyWindowToVram(gUnknown_0203AB6E, 2);
}

void sub_813AA44(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_0203AB6E, TRUE);
    RemoveWindow(gUnknown_0203AB6E);
}

static void sub_813AA60(u16 a0, u16 a1)
{
    static const u16 gUnknown_085B312C[] = { 0x004b, 0x0067, 0x0057, 0x004f, 0x0054, 0x0055, 0x0056, 0x0050, 0x0051, 0x0052, 0xFFFF };
    static const u16 gUnknown_085B3142[] = { 0x0071, 0x006f, 0x0072, 0x0073, 0x0074, 0xFFFF };
    static const u16 gUnknown_085B314E[] = { 0x0040, 0x0043, 0x0041, 0x0046, 0x0042, 0x003f, 0xFFFF };
    static const u16 gUnknown_085B315C[] = { 0x00c8, 0x00b4, 0x00b7, 0x00b9, 0x00b3, 0x00ba, 0x00bb, 0x00c4, 0x00c6, 0xFFFF };

    static const u8 *const gUnknown_085B3170[] = {
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2601AA,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2601D0,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_260201,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26022F,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26025B,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_260287,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2602B5,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2602E0,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26030F,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26033E,
        gText_Exit,
    };

    static const u8 *const gUnknown_085B319C[] = {
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26036C,
        gText_Exit
    };

    static const u8 *const gUnknown_085B31B4[] = {
        BattleFrontier_BattlePointExchangeServiceCorner_Text_260397,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2603BE,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2603E6,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26040E,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_260436,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26045C,
        gText_Exit
    };

    static const u8 *const gUnknown_085B31D0[] = {
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26047A,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2604AC,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2604D8,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_26050F,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_260542,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_260575,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2605A8,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_2605E2,
        BattleFrontier_BattlePointExchangeServiceCorner_Text_260613,
        gText_Exit
    };

    if (a0 > 2 && a0 < 7)
    {
        FillWindowPixelRect(0, PIXEL_FILL(1), 0, 0, 216, 32);
        switch (a0)
        {
            case 3:
                AddTextPrinterParameterized2(0, 1, gUnknown_085B3170[a1], 0, NULL, 2, 1, 3);
                if (gUnknown_085B312C[a1] == 0xFFFF)
                {
                    sub_813ABD4(gUnknown_085B312C[a1]);
                }
                else
                {
                    FreeSpriteTilesByTag(5500);
                    FreeSpritePaletteByTag(5500);
                    gUnknown_0203AB6C = AddDecorationIconObject(gUnknown_085B312C[a1], 33, 88, 0, 5500, 5500);
                }
                break;
            case 4:
                AddTextPrinterParameterized2(0, 1, gUnknown_085B319C[a1], 0, NULL, 2, 1, 3);
                if (gUnknown_085B3142[a1] == 0xFFFF)
                {
                    sub_813ABD4(gUnknown_085B3142[a1]);
                }
                else
                {
                    FreeSpriteTilesByTag(5500);
                    FreeSpritePaletteByTag(5500);
                    gUnknown_0203AB6C = AddDecorationIconObject(gUnknown_085B3142[a1], 33, 88, 0, 5500, 5500);
                }
                break;
            case 5:
                AddTextPrinterParameterized2(0, 1, gUnknown_085B31B4[a1], 0, NULL, 2, 1, 3);
                sub_813ABD4(gUnknown_085B314E[a1]);
                break;
            case 6:
                AddTextPrinterParameterized2(0, 1, gUnknown_085B31D0[a1], 0, NULL, 2, 1, 3);
                sub_813ABD4(gUnknown_085B315C[a1]);
                break;
        }
    }
}

static void sub_813ABD4(u16 a0)
{
    FreeSpriteTilesByTag(5500);
    FreeSpritePaletteByTag(5500);
    gUnknown_0203AB6C = AddItemIconSprite(5500, 5500, a0);

    if (gUnknown_0203AB6C != MAX_SPRITES)
    {
        gSprites[gUnknown_0203AB6C].oam.priority = 0;
        gSprites[gUnknown_0203AB6C].pos1.x = 36;
        gSprites[gUnknown_0203AB6C].pos1.y = 92;
    }
}

static void sub_813AC44(u16 a0, u16 unused)
{
    if (gUnknown_0203AB6C != MAX_SPRITES)
    {
        switch (a0)
        {
            case 3 ... 6:
                DestroySpriteAndFreeResources(&gSprites[gUnknown_0203AB6C]);
                break;
        }
        gUnknown_0203AB6C = MAX_SPRITES;
    }
}

static const u16 gUnknown_085B31F8[] = { 0x0087, 0x0045, 0x008a, 0x0005, 0x0019, 0x0022, 0x009d, 0x0044, 0x0056, 0x000e };
static const u16 gUnknown_085B320C[] = { 0x006f, 0x00ad, 0x00bd, 0x0081, 0x00c4, 0x00cb, 0x00f4, 0x0008, 0x0009, 0x0007 };

void sub_813AC7C(void)
{
    if (gSpecialVar_0x8005 != 0)
    {
        StringCopy(gStringVar1, gMoveNames[gUnknown_085B320C[gSpecialVar_0x8004]]);
    }
    else
    {
        StringCopy(gStringVar1, gMoveNames[gUnknown_085B31F8[gSpecialVar_0x8004]]);
    }
}

static void sub_813ACE8(u8 a0, u16 a1)
{
    static const struct WindowTemplate gUnknown_085B3220 = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 7,
        .width = 12,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 28,
    };

    if (a0 == 9 || a0 == 10)
    {
        if (gSpecialVar_0x8006 == 0)
        {
            gUnknown_0203AB5E = AddWindow(&gUnknown_085B3220);
            SetStandardWindowBorderStyle(gUnknown_0203AB5E, 0);
        }
        sub_813AD34(a0, a1);
    }
}

static void sub_813AD34(u8 a0, u16 a1)
{
    static const u8 *const gUnknown_085B3228[] = {
        BattleFrontier_Lounge7_Text_265E30,
        BattleFrontier_Lounge7_Text_265E5B,
        BattleFrontier_Lounge7_Text_265E8A,
        BattleFrontier_Lounge7_Text_265EC0,
        BattleFrontier_Lounge7_Text_265EED,
        BattleFrontier_Lounge7_Text_265F1C,
        BattleFrontier_Lounge7_Text_265F47,
        BattleFrontier_Lounge7_Text_265F77,
        BattleFrontier_Lounge7_Text_265FAA,
        BattleFrontier_Lounge7_Text_265FDD,
        gText_Exit,
    };

    static const u8 *const gUnknown_085B3254[] = {
        BattleFrontier_Lounge7_Text_26600A,
        BattleFrontier_Lounge7_Text_26603E,
        BattleFrontier_Lounge7_Text_266070,
        BattleFrontier_Lounge7_Text_2660A6,
        BattleFrontier_Lounge7_Text_2660D0,
        BattleFrontier_Lounge7_Text_2660FF,
        BattleFrontier_Lounge7_Text_26612D,
        BattleFrontier_Lounge7_Text_26615F,
        BattleFrontier_Lounge7_Text_266185,
        BattleFrontier_Lounge7_Text_2661B5,
        gText_Exit,
    };

    if (a0 == 9 || a0 == 10)
    {
        FillWindowPixelRect(gUnknown_0203AB5E, PIXEL_FILL(1), 0, 0, 96, 48);
        if (a0 == 10)
        {
            AddTextPrinterParameterized(gUnknown_0203AB5E, 1, gUnknown_085B3254[a1], 0, 1, 0, NULL);
        }
        else
        {
            AddTextPrinterParameterized(gUnknown_0203AB5E, 1, gUnknown_085B3228[a1], 0, 1, 0, NULL);
        }
    }
}

void sub_813ADB8(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_0203AB5E, TRUE);
    RemoveWindow(gUnknown_0203AB5E);
}

void sub_813ADD4(void)
{
    u16 scrollOffset, selectedRow;
    u8 i;
    u8 taskId = FindTaskIdByFunc(sub_813A600);
    if (taskId != 0xFF)
    {
        struct Task *task = &gTasks[taskId];
        ListMenuGetScrollAndRow(task->data[14], &scrollOffset, &selectedRow);
        SetStandardWindowBorderStyle(task->data[13], 0);

        for (i = 0; i < 6; i++)
        {
            AddTextPrinterParameterized5(task->data[13], 1, gUnknown_085B2CF0[gSpecialVar_0x8004][scrollOffset + i], 10, i * 16, TEXT_SPEED_FF, NULL, 0, 0);
        }

        AddTextPrinterParameterized(task->data[13], 1, gText_SelectorArrow, 0, selectedRow * 16, TEXT_SPEED_FF, NULL);
        PutWindowTilemap(task->data[13]);
        CopyWindowToVram(task->data[13], 3);
    }
}

void sub_813AEB4(void)
{
    u8 i;
    u16 temp1 = 0;
    u16 temp2 = 0;
    gSpecialVar_0x8005 = 0;

    temp1 = VarGet(VAR_TEMP_E);
    temp2 = VarGet(VAR_TEMP_D);

    if (temp1 != 0)
    {
        i = 0;
        do
        {
            if (gTutorMoves[i] == gUnknown_085B320C[temp2])
            {
                gSpecialVar_0x8005 = i;
                break;
            }
            i++;
        } while (i < 30);
    }
    else
    {
        i = 0;
        do
        {
            if (gTutorMoves[i] == gUnknown_085B31F8[temp2])
            {
                gSpecialVar_0x8005 = i;
                break;
            }
            i++;
        } while (i < 30);
    }
}

void sub_813AF48(void)
{
    u8 taskId = FindTaskIdByFunc(sub_813A600);
    if (taskId != 0xFF)
    {
        struct Task *task = &gTasks[taskId];
        DestroyListMenuTask(task->data[14], NULL, NULL);
        Free(gUnknown_0203AB64);
        ClearStdWindowAndFrameToTransparent(task->data[13], TRUE);
        FillWindowPixelBuffer(task->data[13], PIXEL_FILL(0));
        ClearWindowTilemap(task->data[13]);
        CopyWindowToVram(task->data[13], 2);
        RemoveWindow(task->data[13]);
        DestroyTask(taskId);
    }
}

void DoDeoxysRockInteraction(void)
{
    CreateTask(Task_DeoxysRockInteraction, 8);
}

static const u16 sDeoxysRockPalettes[][16] = {
    INCBIN_U16("graphics/misc/deoxys1.gbapal"),
    INCBIN_U16("graphics/misc/deoxys2.gbapal"),
    INCBIN_U16("graphics/misc/deoxys3.gbapal"),
    INCBIN_U16("graphics/misc/deoxys4.gbapal"),
    INCBIN_U16("graphics/misc/deoxys5.gbapal"),
    INCBIN_U16("graphics/misc/deoxys6.gbapal"),
    INCBIN_U16("graphics/misc/deoxys7.gbapal"),
    INCBIN_U16("graphics/misc/deoxys8.gbapal"),
    INCBIN_U16("graphics/misc/deoxys9.gbapal"),
    INCBIN_U16("graphics/misc/deoxys10.gbapal"),
    INCBIN_U16("graphics/misc/deoxys11.gbapal"),
};

static const u8 sDeoxysRockCoords[][2] = {
    { 15, 12 },
    { 11, 14 },
    { 15,  8 },
    { 19, 14 },
    { 12, 11 },
    { 18, 11 },
    { 15, 14 },
    { 11, 14 },
    { 19, 14 },
    { 15, 15 },
    { 15, 10 },
};

static void Task_DeoxysRockInteraction(u8 taskId)
{
    static const u8 sStoneMaxStepCounts[] = { 4, 8, 8, 8, 4, 4, 4, 6, 3, 3 };

    if (FlagGet(FLAG_DEOXYS_ROCK_COMPLETE) == TRUE)
    {
        gSpecialVar_Result = 3;
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
    else
    {
        u16 rockLevel = VarGet(VAR_DEOXYS_ROCK_LEVEL);
        u16 stepCount = VarGet(VAR_DEOXYS_ROCK_STEP_COUNT);

        VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, 0);
        if (rockLevel != 0 && sStoneMaxStepCounts[rockLevel - 1] < stepCount)
        {
            // Player failed to take the shortest path to the stone, so it resets.
            ChangeDeoxysRockLevel(0);
            VarSet(VAR_DEOXYS_ROCK_LEVEL, 0);
            gSpecialVar_Result = 0;
            DestroyTask(taskId);
        }
        else if (rockLevel == 10)
        {
            FlagSet(FLAG_DEOXYS_ROCK_COMPLETE);
            gSpecialVar_Result = 2;
            EnableBothScriptContexts();
            DestroyTask(taskId);
        }
        else
        {
            rockLevel++;
            ChangeDeoxysRockLevel(rockLevel);
            VarSet(VAR_DEOXYS_ROCK_LEVEL, rockLevel);
            gSpecialVar_Result = 1;
            DestroyTask(taskId);
        }
    }
}

static void ChangeDeoxysRockLevel(u8 rockLevel)
{
    u8 eventObjectId;
    LoadPalette(&sDeoxysRockPalettes[rockLevel], 0x1A0, 8);
    TryGetEventObjectIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &eventObjectId);

    if (rockLevel == 0)
        PlaySE(SE_W109);
    else
        PlaySE(SE_RG_DEOMOV);

    CreateTask(WaitForDeoxysRockMovement, 8);
    gFieldEffectArguments[0] = 1;
    gFieldEffectArguments[1] = 58;
    gFieldEffectArguments[2] = 26;
    gFieldEffectArguments[3] = sDeoxysRockCoords[rockLevel][0];
    gFieldEffectArguments[4] = sDeoxysRockCoords[rockLevel][1];

    if (rockLevel == 0)
        gFieldEffectArguments[5] = 60;
    else
        gFieldEffectArguments[5] = 5;

    FieldEffectStart(FLDEFF_MOVE_DEOXYS_ROCK);
    Overworld_SetEventObjTemplateCoords(1, sDeoxysRockCoords[rockLevel][0], sDeoxysRockCoords[rockLevel][1]);
}

static void WaitForDeoxysRockMovement(u8 taskId)
{
    if (FieldEffectActiveListContains(FLDEFF_MOVE_DEOXYS_ROCK) == FALSE)
    {
        EnableBothScriptContexts();
        DestroyTask(taskId);
    }
}

void IncrementBirthIslandRockStepCount(void)
{
    u16 var = VarGet(VAR_DEOXYS_ROCK_STEP_COUNT);
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(BIRTH_ISLAND_EXTERIOR) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BIRTH_ISLAND_EXTERIOR))
    {
        var++;
        if (var > 99)
        {
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, 0);
        }
        else
        {
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, var);
        }
    }
}

void sub_813B1D0(void)
{
    LoadPalette(&sDeoxysRockPalettes[(u8)VarGet(VAR_DEOXYS_ROCK_LEVEL)], 0x1A0, 8);
    BlendPalettes(0x04000000, 16, 0);
}

void set_unknown_box_id(u8 id)
{
    gUnknown_0203AB6F = id;
}

u16 get_unknown_box_id(void)
{
    return gUnknown_0203AB6F;
}

bool8 sub_813B21C(void)
{
    if (FlagGet(FLAG_SYS_STORAGE_UNKNOWN_FLAG) == FALSE)
    {
        if (StorageGetCurrentBox() != VarGet(VAR_STORAGE_UNKNOWN))
        {
            FlagSet(FLAG_SYS_STORAGE_UNKNOWN_FLAG);
            return TRUE;
        }
    }
    return FALSE;
}

bool8 sub_813B260(void)
{
    int box;
    int i;
    set_unknown_box_id(VarGet(VAR_STORAGE_UNKNOWN));
    box = StorageGetCurrentBox();
    do
    {
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            if (GetBoxMonData(GetBoxedMonPtr(box, i), MON_DATA_SPECIES, 0) == 0)
            {
                if (get_unknown_box_id() != box)
                {
                    FlagClear(FLAG_SYS_STORAGE_UNKNOWN_FLAG);
                }
                VarSet(VAR_STORAGE_UNKNOWN, box);
                return sub_813B21C();
            }
        }

        if (++box == TOTAL_BOXES_COUNT)
        {
            box = 0;
        }
    } while (box != StorageGetCurrentBox());
    return FALSE;
}

void CreateUnusualWeatherEvent(void)
{
    u16 randomValue = Random();
    VarSet(VAR_UNUSUAL_WEATHER_STEP_COUNTER, 0);

    if (FlagGet(FLAG_DEFEATED_KYOGRE) == TRUE)
    {
        VarSet(VAR_UNUSUAL_WEATHER_LOCATION, (randomValue % UNUSUAL_WEATHER_COUNT_PER_LEGENDARY) + UNUSUAL_WEATHER_GROUDON_LOCATIONS_START);
    }
    else if (FlagGet(FLAG_DEFEATED_GROUDON) == TRUE)
    {
        VarSet(VAR_UNUSUAL_WEATHER_LOCATION, (randomValue % UNUSUAL_WEATHER_COUNT_PER_LEGENDARY) + UNUSUAL_WEATHER_KYOGRE_LOCATIONS_START);
    }
    else if ((randomValue & 1) == 0)
    {
        randomValue = Random();
        VarSet(VAR_UNUSUAL_WEATHER_LOCATION, (randomValue % UNUSUAL_WEATHER_COUNT_PER_LEGENDARY) + UNUSUAL_WEATHER_GROUDON_LOCATIONS_START);
    }
    else
    {
        randomValue = Random();
        VarSet(VAR_UNUSUAL_WEATHER_LOCATION, (randomValue % UNUSUAL_WEATHER_COUNT_PER_LEGENDARY) + UNUSUAL_WEATHER_KYOGRE_LOCATIONS_START);
    }
}

// Saves the map name for the current unusual weather location in gStringVar1, then
// returns TRUE if the weather is for Kyogre, and FALSE if it's for Groudon.
bool32 GetUnusualWeatherMapNameAndType(void)
{
    static const u8 sUnusualWeatherMapNumbers[] = {
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE129),
        MAP_NUM(ROUTE129)
    };

    u16 unusualWeather = VarGet(VAR_UNUSUAL_WEATHER_LOCATION);

    GetMapName(gStringVar1, sUnusualWeatherMapNumbers[unusualWeather - 1], 0);

    if (unusualWeather < UNUSUAL_WEATHER_KYOGRE_LOCATIONS_START)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

bool8 UnusualWeatherHasExpired(void)
{
    // Duplicate array.
    static const u8 sUnusualWeatherMapNumbers_2[] = {
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE114),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE115),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE116),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE118),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE105),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE125),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE127),
        MAP_NUM(ROUTE129),
        MAP_NUM(ROUTE129)
    };

    u16 steps = VarGet(VAR_UNUSUAL_WEATHER_STEP_COUNTER);
    u16 unusualWeather = VarGet(VAR_UNUSUAL_WEATHER_LOCATION);

    if (unusualWeather == UNUSUAL_WEATHER_NONE)
    {
        return FALSE;
    }

    if (++steps > 999)
    {
        VarSet(VAR_UNUSUAL_WEATHER_STEP_COUNTER, 0);
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(UNDERWATER_MARINE_CAVE))
        {
            switch (gSaveBlock1Ptr->location.mapNum)
            {
                case MAP_NUM(UNDERWATER_MARINE_CAVE):
                case MAP_NUM(MARINE_CAVE_ENTRANCE):
                case MAP_NUM(MARINE_CAVE_END):
                case MAP_NUM(TERRA_CAVE_ENTRANCE):
                case MAP_NUM(TERRA_CAVE_END):
                    VarSet(VAR_SHOULD_END_UNUSUAL_WEATHER, 1);
                    return FALSE;
                default:
                    break;
            }
        }

        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(UNDERWATER3))
        {
            switch (gSaveBlock1Ptr->location.mapNum)
            {
                case MAP_NUM(UNDERWATER3):
                case MAP_NUM(UNDERWATER5):
                case MAP_NUM(UNDERWATER6):
                case MAP_NUM(UNDERWATER7):
                    VarSet(VAR_SHOULD_END_UNUSUAL_WEATHER, 1);
                    return FALSE;
                default:
                    break;
            }
        }

        if (gSaveBlock1Ptr->location.mapNum == sUnusualWeatherMapNumbers_2[unusualWeather - 1] &&
            gSaveBlock1Ptr->location.mapGroup == 0)
        {
            return TRUE;
        }
        else
        {
            VarSet(VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_NONE);
            return FALSE;
        }
    }
    else
    {
        VarSet(VAR_UNUSUAL_WEATHER_STEP_COUNTER, steps);
        return FALSE;
    }
}

void Unused_SetWeatherSunny(void)
{
    SetCurrentAndNextWeather(WEATHER_SUNNY);
}

bool32 sub_813B490(void)
{
    static const u8 gUnknown_085B3420[][3] = {
        { 0x02, 0x04, 0x01 },
        { 0x04, 0x04, 0x01 },
        { 0x05, 0x00, 0x01 },
        { 0x06, 0x03, 0x01 },
        { 0x08, 0x06, 0x01 },
        { 0x09, 0x0d, 0x01 },
        { 0x0a, 0x07, 0x01 },
        { 0x0b, 0x07, 0x01 },
        { 0x0c, 0x04, 0x01 },
        { 0x0e, 0x05, 0x01 },
        { 0x0f, 0x04, 0x01 },
        { 0x1a, 0x37, 0x01 }
    };

    u8 i;
    for (i = 0; i < 12; i++)
    {
        if (gSaveBlock1Ptr->location.mapGroup == gUnknown_085B3420[i][0])
        {
            if (gSaveBlock1Ptr->location.mapNum == gUnknown_085B3420[i][1])
            {
                return gUnknown_085B3420[i][2];
            }
        }
    }
    return TRUE;
}

bool32 sub_813B4E0(void)
{
    int index = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (index >= 0)
    {
        if (FlagGet(FLAG_MATCH_CALL_REGISTERED + index) == TRUE)
            return TRUE;
    }
    return FALSE;
}

bool32 sub_813B514(void)
{
    if (!VarGet(VAR_ALWAYS_ZERO_0x403F))
    {
        return FALSE;
    }
    return TRUE;
}

void sub_813B534(void)
{
    gUnknown_0203AB70 = gBattleTypeFlags;
    gBattleTypeFlags = 0;
    if (!gReceivedRemoteLinkPlayers)
    {
        CreateTask(sub_80B3AF8, 5);
    }
}

void sub_813B568(void)
{
    CreateTask(sub_813B57C, 5);
}

static void sub_813B57C(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (!FuncIsActiveTask(sub_80B3AF8))
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 1:
            if (IsLinkTaskFinished() == TRUE)
            {
                if (GetMultiplayerId() == 0)
                {
                    gTasks[taskId].data[0]++;
                }
                else
                {
                    SendBlock(bitmask_all_link_players_but_self(), &gSpecialVar_0x8004, 2);
                    gTasks[taskId].data[0]++;
                }
            }
            break;
        case 2:
            if ((GetBlockReceivedStatus() & 2) != 0)
            {
                if (GetMultiplayerId() == 0)
                {
                    gSpecialVar_0x8005 = gBlockRecvBuffer[1][0];
                    ResetBlockReceivedFlag(1);
                    if (gSpecialVar_0x8004 == 1 && gSpecialVar_0x8005 == 1)
                    {
                        gSpecialVar_Result = 1;
                    }
                    else if (gSpecialVar_0x8004 == 0 && gSpecialVar_0x8005 == 1)
                    {
                        gSpecialVar_Result = 2;
                    }
                    else if (gSpecialVar_0x8004 == 1 && gSpecialVar_0x8005 == 0)
                    {
                        gSpecialVar_Result = 3;
                    }
                    else
                    {
                        gSpecialVar_Result = 0;
                    }
                }
                gTasks[taskId].data[0]++;
            }
            break;
        case 3:
            if (IsLinkTaskFinished() == TRUE)
            {
                if (GetMultiplayerId() != 0)
                {
                    gTasks[taskId].data[0]++;
                }
                else
                {
                    SendBlock(bitmask_all_link_players_but_self(), &gSpecialVar_Result, 2);
                    gTasks[taskId].data[0]++;
                }
            }
            break;
        case 4:
            if ((GetBlockReceivedStatus() & 1) != 0)
            {
                if (GetMultiplayerId() != 0)
                {
                    gSpecialVar_Result = gBlockRecvBuffer[0][0];
                    ResetBlockReceivedFlag(0);
                    gTasks[taskId].data[0]++;
                }
                else
                {
                    gTasks[taskId].data[0]++;
                }
            }
            break;
        case 5:
            if (GetMultiplayerId() == 0)
            {
                if (gSpecialVar_Result == 2)
                {
                    ShowFieldAutoScrollMessage(gText_YourPartnerHasRetired);
                }
            }
            else
            {
                if (gSpecialVar_Result == 3)
                {
                    ShowFieldAutoScrollMessage(gText_YourPartnerHasRetired);
                }
            }
            gTasks[taskId].data[0]++;
            break;
        case 6:
            if (!IsTextPrinterActive(0))
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 7:
            if (IsLinkTaskFinished() == 1)
            {
                sub_800ADF8();
                gTasks[taskId].data[0]++;
            }
            break;
        case 8:
            if (IsLinkTaskFinished() == 1)
            {
                gTasks[taskId].data[0]++;
            }
            break;
        case 9:
            if (gWirelessCommType == 0)
            {
                sub_800AC34();
            }
            gBattleTypeFlags = gUnknown_0203AB70;
            EnableBothScriptContexts();
            DestroyTask(taskId);
            break;
    }
}

void sub_813B7D8(void)
{
    if (gSpecialVar_0x8004 == 0)
    {
        DoRayquazaScene(0, TRUE, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
    else
    {
        DoRayquazaScene(1, FALSE, CB2_ReturnToFieldContinueScriptPlayMapMusic);
    }
}

void sub_813B80C(void)
{
    CreateTask(sub_813B824, 8);
    PlaySE(SE_W017);
}

static void sub_813B824(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[1]++;
    if (data[1] == gSpecialVar_0x8005)
    {
        data[0]++;
        data[1] = 0;
        PlaySE(SE_W017);
    }

    if (data[0] == gSpecialVar_0x8004 - 1)
    {
        DestroyTask(taskId);
    }
}

void sub_813B880(void)
{
    u8 taskId = CreateTask(_fwalk, 8);
    gTasks[taskId].data[0] = 4;
    gTasks[taskId].data[1] = 4;
    gTasks[taskId].data[2] = 4;
    gTasks[taskId].data[3] = 0;
}

static void _fwalk(u8 taskId)
{
    u8 x, y;
    s16 *data = gTasks[taskId].data;

    data[data[3]]--;
    if (data[data[3]] == 0)
    {
        for (y = 0; y < 4; y++)
        {
            for (x = 0; x < 3; x++)
            {
                MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + x + 6, gSaveBlock1Ptr->pos.y + y + 4, x + 0x201 + y * 8 + data[3] * 32);
            }
        }
        DrawWholeMapView();
        data[3]++;
        if (data[3] == 3)
        {
            DestroyTask(taskId);
            EnableBothScriptContexts();
        }
    }
}

void sub_813B968(void)
{
    gSpecialVar_Result = gSpecialVar_0x8004 / 7;
    gSpecialVar_Result -= (gSpecialVar_Result / 20) * 20;
}

void sub_813B9A0(void)
{
    if (gSaveBlock1Ptr->lastHealLocation.mapGroup == MAP_GROUP(DEWFORD_TOWN) && gSaveBlock1Ptr->lastHealLocation.mapNum == MAP_NUM(DEWFORD_TOWN))
    {
        SetLastHealLocationWarp(3);
    }
}

bool8 sub_813B9C0(void)
{
    static const u16 gUnknown_085B3444[] = {
        MAP_OLDALE_TOWN_POKEMON_CENTER_1F,
        MAP_DEWFORD_TOWN_POKEMON_CENTER_1F,
        MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F,
        MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F,
        MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F,
        MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F,
        MAP_PETALBURG_CITY_POKEMON_CENTER_1F,
        MAP_SLATEPORT_CITY_POKEMON_CENTER_1F,
        MAP_MAUVILLE_CITY_POKEMON_CENTER_1F,
        MAP_RUSTBORO_CITY_POKEMON_CENTER_1F,
        MAP_FORTREE_CITY_POKEMON_CENTER_1F,
        MAP_LILYCOVE_CITY_POKEMON_CENTER_1F,
        MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F,
        MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F,
        MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F,
        MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F,
        MAP_BATTLE_FRONTIER_POKEMON_CENTER_1F,
        MAP_SINGLE_BATTLE_COLOSSEUM,
        MAP_TRADE_CENTER,
        MAP_RECORD_CORNER,
        MAP_DOUBLE_BATTLE_COLOSSEUM,
        0xFFFF
    };

    int i;
    u16 map = (gSaveBlock1Ptr->location.mapGroup << 8) + gSaveBlock1Ptr->location.mapNum;

    for (i = 0; gUnknown_085B3444[i] != 0xFFFF; i++)
    {
        if (gUnknown_085B3444[i] == map)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void ResetFanClub(void)
{
    gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] = 0;
    gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_2 - VARS_START] = 0;
}

void sub_813BA30(void)
{
    if (sub_813BF44() != 0)
    {
        UpdateMovedLilycoveFanClubMembers();
        gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_2 - VARS_START] = gSaveBlock2Ptr->playTimeHours;
    }
}

void sub_813BA60(void)
{
    if (!((gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] >> 7) & 1))
    {
        sub_813BF60();
        sub_813BD84();
        gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_2 - VARS_START] = gSaveBlock2Ptr->playTimeHours;
        FlagClear(FLAG_HIDE_FANCLUB_OLD_LADY);
        FlagClear(FLAG_HIDE_FANCLUB_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LITTLE_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LADY);
        FlagClear(FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER);
        VarSet(VAR_LILYCOVE_FAN_CLUB_STATE, 1);
    }
}

u8 sub_813BADC(u8 a0)
{
    static const u8 gUnknown_085B3470[] = { 0x02, 0x01, 0x02, 0x01 };

    if (VarGet(VAR_LILYCOVE_FAN_CLUB_STATE) == 2)
    {
        if ((gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] & 0x7F) + gUnknown_085B3470[a0] > 19)
        {
            if (GetNumMovedLilycoveFanClubMembers() < 3)
            {
                sub_813BB74();
                gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] &= 0xFF80;
            }
            else
            {
                gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] = (gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] & 0xFF80) | 0x14;
            }
        }
        else
        {
            gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] += gUnknown_085B3470[a0];
        }
    }

    return gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] & 0x7F;
}

static u16 sub_813BB74(void)
{
    static const u8 gUnknown_085B3474[] = { 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

    u8 i;
    u8 retVal = 0;

    for (i = 0; i < 8; i++)
    {
        if (!((gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] >> gUnknown_085B3474[i]) & 1))
        {
            retVal = i;
            if ((Random() & 1) != 0)
            {
                gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] |= 1 << gUnknown_085B3474[retVal];
                return retVal;
            }
        }
    }
    gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] |= 1 << gUnknown_085B3474[retVal];
    return retVal;
}

static u16 sub_813BC00(void)
{
    static const u8 gUnknown_085B347C[] = { 0x08, 0x0d, 0x0e, 0x0b, 0x0a, 0x0c, 0x0f, 0x09 };

    u8 i;
    u8 retVal = 0;

    if (GetNumMovedLilycoveFanClubMembers() == 1)
    {
        return 0;
    }

    for (i = 0; i < 8; i++)
    {
        if (((gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] >> gUnknown_085B347C[i]) & 1) != 0)
        {
            retVal = i;
            if ((Random() & 1) != 0)
            {
                gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] ^= 1 << gUnknown_085B347C[retVal];
                return retVal;
            }
        }
    }

    if (((gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] >> gUnknown_085B347C[retVal]) & 1))
    {
        gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] ^= 1 << gUnknown_085B347C[retVal];
    }

    return retVal;
}

u16 GetNumMovedLilycoveFanClubMembers(void)
{
    u8 i;
    u8 retVal = 0;

    for (i = 0; i < 8; i++)
    {
        if (((gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] >> (i + 8)) & 1) != 0)
        {
            retVal++;
        }
    }

    return retVal;
}

void UpdateMovedLilycoveFanClubMembers(void)
{
    u8 i = 0;
    if (gSaveBlock2Ptr->playTimeHours < 999)
    {
        while (TRUE)
        {
            if (GetNumMovedLilycoveFanClubMembers() < 5)
            {
                gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_2 - VARS_START] = gSaveBlock2Ptr->playTimeHours;
                break;
            }
            else if (i == 8)
            {
                break;
            }
            else if (gSaveBlock2Ptr->playTimeHours - gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_2 - VARS_START] < 12)
            {
                return;
            }
            sub_813BC00();
            gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_2 - VARS_START] += 12;
            i++;
        }
    }
}

bool8 ShouldMoveLilycoveFanClubMember(void)
{
    return (gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] >> gSpecialVar_0x8004) & 1;
}

static void sub_813BD84(void)
{
    gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] |= 0x2000;
    gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] |= 0x100;
    gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] |= 0x400;
}

void BufferStreakTrainerText(void)
{
    u8 a = 0;
    u8 b = 0;
    switch (gSpecialVar_0x8004)
    {
        case 8:
            break;
        case 9:
            break;
        case 10:
            a = 0;
            b = 3;
            break;
        case 11:
            a = 0;
            b = 1;
            break;
        case 12:
            a = 1;
            b = 0;
            break;
        case 13:
            a = 0;
            b = 4;
            break;
        case 14:
            a = 1;
            b = 5;
            break;
        case 15:
            break;
    }
    sub_813BE30(&gSaveBlock1Ptr->linkBattleRecords, a, b);
}

static void sub_813BE30(struct LinkBattleRecords *linkRecords, u8 a, u8 b)
{
    struct LinkBattleRecord *record = &linkRecords->entries[a];
    if (record->name[0] == EOS)
    {
        switch (b)
        {
            case 0:
                StringCopy(gStringVar1, gText_Wallace);
                break;
            case 1:
                StringCopy(gStringVar1, gText_Steven);
                break;
            case 2:
                StringCopy(gStringVar1, gText_Brawly);
                break;
            case 3:
                StringCopy(gStringVar1, gText_Winona);
                break;
            case 4:
                StringCopy(gStringVar1, gText_Phoebe);
                break;
            case 5:
                StringCopy(gStringVar1, gText_Glacia);
                break;
            default:
                StringCopy(gStringVar1, gText_Wallace);
                break;
        }
    }
    else
    {
        StringCopyN(gStringVar1, record->name, 7);
        gStringVar1[7] = EOS;
        ConvertInternationalString(gStringVar1, linkRecords->languages[a]);
    }
}

void sub_813BF10(void)
{
    if (VarGet(VAR_LILYCOVE_FAN_CLUB_STATE) == 2)
    {
        sub_813BA30();
        if (gBattleOutcome == 1)
        {
            sub_813BB74();
        }
        else
        {
            sub_813BC00();
        }
    }
}

static bool8 sub_813BF44(void)
{
    return (gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] >> 7) & 1;
}

void sub_813BF60(void)
{
    gSaveBlock1Ptr->vars[VAR_FANCLUB_UNKNOWN_1 - VARS_START] |= 0x80;
}

u8 sub_813BF7C(void)
{
    return sub_813BADC(gSpecialVar_0x8004);
}
