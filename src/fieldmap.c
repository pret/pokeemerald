#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "menu.h"
#include "mirage_tower.h"
#include "overworld.h"
#include "palette.h"
#include "pokenav.h"
#include "script.h"
#include "secret_base.h"
#include "trainer_hill.h"
#include "tv.h"
#include "constants/rgb.h"
#include "constants/layouts.h"
#include "constants/metatile_behaviors.h"
#include "constants/metatile_behaviors_frlg.h"
#include "wild_encounter.h"

struct ConnectionFlags
{
    u8 south:1;
    u8 north:1;
    u8 west:1;
    u8 east:1;
};

EWRAM_DATA u16 ALIGNED(4) sBackupMapData[MAX_MAP_DATA_SIZE] = {0};
EWRAM_DATA struct MapHeader gMapHeader = {0};
EWRAM_DATA struct Camera gCamera = {0};
EWRAM_DATA static struct ConnectionFlags sMapConnectionFlags = {0};

COMMON_DATA struct BackupMapLayout gBackupMapLayout = {0};

static const struct ConnectionFlags sDummyConnectionFlags = {0};

static void InitMapLayoutData(const struct MapHeader *mapHeader);
static void InitBackupMapLayoutData(const u16 *map, u16 width, u16 height);
static void FillSouthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillNorthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillWestConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillEastConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void InitBackupMapLayoutConnections(const struct MapHeader *mapHeader);
static void LoadSavedMapView(void);
static bool8 SkipCopyingMetatileFromSavedMap(u16 *mapBlock, u16 mapWidth, u8 yMode);
static const struct MapConnection *GetIncomingConnection(enum Connection direction, s32 x, s32 y);
static bool8 IsPosInIncomingConnectingMap(enum Connection direction, s32 x, s32 y, const struct MapConnection *connection);
static bool8 IsCoordInIncomingConnectingMap(s32 coord, s32 srcMax, s32 destMax, s32 offset);

static inline u16 GetBorderBlockAt(int x, int y)
{
    const struct MapLayout *mapLayout = gMapHeader.mapLayout;

    if (mapLayout->isFrlg)
    {
        s32 xprime;
        s32 yprime;

        xprime = x - MAP_OFFSET;
        xprime += 8 * mapLayout->borderWidth;
        xprime %= mapLayout->borderWidth;

        yprime = y - MAP_OFFSET;
        yprime += 8 * mapLayout->borderHeight;
        yprime %= mapLayout->borderHeight;

        return mapLayout->border[xprime + yprime * mapLayout->borderWidth] | MAPGRID_COLLISION_MASK;
    }

    int i = (x + 1) & 1;
    i += ((y + 1) & 1) * 2;
    return gMapHeader.mapLayout->border[i] | MAPGRID_IMPASSABLE;
}

#define AreCoordsWithinMapGridBounds(x, y) (x >= 0 && x < gBackupMapLayout.width && y >= 0 && y < gBackupMapLayout.height)

#define GetMapGridBlockAt(x, y) (AreCoordsWithinMapGridBounds(x, y) ? gBackupMapLayout.map[x + gBackupMapLayout.width * y] : GetBorderBlockAt(x, y))

// Masks/shifts for metatile attributes
// This is the format of the data stored in each data/tilesets/*/*/metatile_attributes.bin file
static const u32 sMetatileAttrMasks[METATILE_ATTRIBUTE_COUNT] = {
    [METATILE_ATTRIBUTE_BEHAVIOR]       = METATILE_ATTR_BEHAVIOR_MASK_FRLG, // Bits 0-8
    [METATILE_ATTRIBUTE_TERRAIN]        = 0x00003e00, // Bits 9-13
    [METATILE_ATTRIBUTE_2]              = 0x0003c000, // Bits 14-17
    [METATILE_ATTRIBUTE_3]              = 0x00fc0000, // Bits 18-23
    [METATILE_ATTRIBUTE_ENCOUNTER_TYPE] = 0x07000000, // Bits 24-26
    [METATILE_ATTRIBUTE_5]              = 0x18000000, // Bits 27-28
    [METATILE_ATTRIBUTE_LAYER_TYPE]     = METATILE_ATTR_LAYER_MASK_FRLG, // Bits 29-30
    [METATILE_ATTRIBUTE_7]              = 0x80000000  // Bit  31
};

static const u8 sMetatileAttrShifts[METATILE_ATTRIBUTE_COUNT] = {
    [METATILE_ATTRIBUTE_BEHAVIOR]       = METATILE_ATTR_BEHAVIOR_SHIFT_FRLG,
    [METATILE_ATTRIBUTE_TERRAIN]        = 9,
    [METATILE_ATTRIBUTE_2]              = 14,
    [METATILE_ATTRIBUTE_3]              = 18,
    [METATILE_ATTRIBUTE_ENCOUNTER_TYPE] = 24,
    [METATILE_ATTRIBUTE_5]              = 27,
    [METATILE_ATTRIBUTE_LAYER_TYPE]     = METATILE_ATTR_LAYER_SHIFT_FRLG,
    [METATILE_ATTRIBUTE_7]              = 31
};

static const u32 sMetatileAttrMasksEmerald[METATILE_ATTRIBUTE_COUNT] = {

    [METATILE_ATTRIBUTE_BEHAVIOR]       = METATILE_ATTR_BEHAVIOR_MASK,
    [METATILE_ATTRIBUTE_TERRAIN]        = 0xFFFFFFFF,
    [METATILE_ATTRIBUTE_2]              = 0xFFFFFFFF,
    [METATILE_ATTRIBUTE_3]              = 0xFFFFFFFF,
    [METATILE_ATTRIBUTE_ENCOUNTER_TYPE] = 0xFFFFFFFF,
    [METATILE_ATTRIBUTE_5]              = 0xFFFFFFFF,
    [METATILE_ATTRIBUTE_LAYER_TYPE]     = METATILE_ATTR_LAYER_MASK,
    [METATILE_ATTRIBUTE_7]              = 0xFFFFFFFF
};

static const u8 sMetatileAttrShiftsEmerald[METATILE_ATTRIBUTE_COUNT] = {

    [METATILE_ATTRIBUTE_BEHAVIOR]       = METATILE_ATTR_BEHAVIOR_SHIFT,
    [METATILE_ATTRIBUTE_TERRAIN]        = 0,
    [METATILE_ATTRIBUTE_2]              = 0,
    [METATILE_ATTRIBUTE_3]              = 0,
    [METATILE_ATTRIBUTE_ENCOUNTER_TYPE] = 0,
    [METATILE_ATTRIBUTE_5]              = 0,
    [METATILE_ATTRIBUTE_LAYER_TYPE]     = METATILE_ATTR_LAYER_SHIFT,
    [METATILE_ATTRIBUTE_7]              = 0
};

const struct MapHeader *const GetMapHeaderFromConnection(const struct MapConnection *connection)
{
    return Overworld_GetMapHeaderByGroupAndId(connection->mapGroup, connection->mapNum);
}

void InitMap(void)
{
    InitMapLayoutData(&gMapHeader);
    SetOccupiedSecretBaseEntranceMetatiles(gMapHeader.events);
    RunOnLoadMapScript();
}

void InitMapFromSavedGame(void)
{
    InitMapLayoutData(&gMapHeader);
    InitSecretBaseAppearance(FALSE);
    SetOccupiedSecretBaseEntranceMetatiles(gMapHeader.events);
    LoadSavedMapView();
    RunOnLoadMapScript();
    UpdateTVScreensOnMap(gBackupMapLayout.width, gBackupMapLayout.height);
}

void InitBattlePyramidMap(bool8 setPlayerPosition)
{
    CpuFastFill16(MAPGRID_UNDEFINED, sBackupMapData, sizeof(sBackupMapData));
    GenerateBattlePyramidFloorLayout(sBackupMapData, setPlayerPosition);
}

void InitTrainerHillMap(void)
{
    CpuFastFill16(MAPGRID_UNDEFINED, sBackupMapData, sizeof(sBackupMapData));
    GenerateTrainerHillFloorLayout(sBackupMapData);
}

static void InitMapLayoutData(const struct MapHeader *mapHeader)
{
    const struct MapLayout *mapLayout = mapHeader->mapLayout;
    CpuFastFill16(MAPGRID_UNDEFINED, sBackupMapData, sizeof(sBackupMapData));

    gBackupMapLayout.map = sBackupMapData;
    gBackupMapLayout.width = mapLayout->width + MAP_OFFSET_W;
    gBackupMapLayout.height = mapLayout->height + MAP_OFFSET_H;

    if (gBackupMapLayout.width * gBackupMapLayout.height > MAX_MAP_DATA_SIZE)
        return;

    InitBackupMapLayoutData(mapLayout->map, mapLayout->width, mapLayout->height);
    InitBackupMapLayoutConnections(mapHeader);
}

static void InitBackupMapLayoutData(const u16 *map, u16 width, u16 height)
{
    u16 *dest;
    s32 y;
    dest = gBackupMapLayout.map;
    dest += gBackupMapLayout.width * MAP_OFFSET + MAP_OFFSET;
    for (y = 0; y < height; y++)
    {
        CpuCopy16(map, dest, width * 2);
        dest += width + MAP_OFFSET_W;
        map += width;
    }
}

static void InitBackupMapLayoutConnections(const struct MapHeader *mapHeader)
{
    s32 count, i, offset;
    const struct MapConnection *connection;
    const struct MapHeader *cMap;

    if (!mapHeader->connections)
        return;

    count = mapHeader->connections->count;
    connection = mapHeader->connections->connections;
    sMapConnectionFlags = sDummyConnectionFlags;
    for (i = 0; i < count; i++, connection++)
    {
        cMap = GetMapHeaderFromConnection(connection);
        offset = connection->offset;
        switch (connection->direction)
        {
        case CONNECTION_SOUTH:
            FillSouthConnection(mapHeader, cMap, offset);
            sMapConnectionFlags.south = TRUE;
            break;
        case CONNECTION_NORTH:
            FillNorthConnection(mapHeader, cMap, offset);
            sMapConnectionFlags.north = TRUE;
            break;
        case CONNECTION_WEST:
            FillWestConnection(mapHeader, cMap, offset);
            sMapConnectionFlags.west = TRUE;
            break;
        case CONNECTION_EAST:
            FillEastConnection(mapHeader, cMap, offset);
            sMapConnectionFlags.east = TRUE;
            break;
        }
    }
}

static void FillConnection(s32 x, s32 y, const struct MapHeader *connectedMapHeader, s32 x2, s32 y2, s32 width, s32 height)
{
    s32 i;
    const u16 *src;
    u16 *dest;
    s32 mapWidth;

    mapWidth = connectedMapHeader->mapLayout->width;
    src = &connectedMapHeader->mapLayout->map[mapWidth * y2 + x2];
    dest = &gBackupMapLayout.map[gBackupMapLayout.width * y + x];

    for (i = 0; i < height; i++)
    {
        CpuCopy16(src, dest, width * 2);
        dest += gBackupMapLayout.width;
        src += mapWidth;
    }
}

static void FillSouthConnection(const struct MapHeader *mapHeader, const struct MapHeader *connectedMapHeader, s32 offset)
{
    s32 x, y;
    s32 x2;
    s32 width;
    s32 cWidth;

    if (!connectedMapHeader)
        return;

    cWidth = connectedMapHeader->mapLayout->width;
    x = offset + MAP_OFFSET;
    y = mapHeader->mapLayout->height + MAP_OFFSET;
    if (x < 0)
    {
        x2 = -x;
        x += cWidth;
        if (x < gBackupMapLayout.width)
            width = x;
        else
            width = gBackupMapLayout.width;
        x = 0;
    }
    else
    {
        x2 = 0;
        if (x + cWidth < gBackupMapLayout.width)
            width = cWidth;
        else
            width = gBackupMapLayout.width - x;
    }

    FillConnection(x, y, connectedMapHeader, x2, /*y2*/ 0, width, /*height*/ MAP_OFFSET);
}

static void FillNorthConnection(const struct MapHeader *mapHeader, const struct MapHeader *connectedMapHeader, s32 offset)
{
    s32 x;
    s32 x2, y2;
    s32 width;
    s32 cWidth, cHeight;

    if (!connectedMapHeader)
        return;

    cWidth = connectedMapHeader->mapLayout->width;
    cHeight = connectedMapHeader->mapLayout->height;
    x = offset + MAP_OFFSET;
    y2 = cHeight - MAP_OFFSET;
    if (x < 0)
    {
        x2 = -x;
        x += cWidth;
        if (x < gBackupMapLayout.width)
            width = x;
        else
            width = gBackupMapLayout.width;
        x = 0;
    }
    else
    {
        x2 = 0;
        if (x + cWidth < gBackupMapLayout.width)
            width = cWidth;
        else
            width = gBackupMapLayout.width - x;
    }

    FillConnection(x, /*y*/ 0, connectedMapHeader, x2, y2, width, /*height*/ MAP_OFFSET);
}

static void FillWestConnection(const struct MapHeader *mapHeader, const struct MapHeader *connectedMapHeader, s32 offset)
{
    s32 y;
    s32 x2, y2;
    s32 height;
    s32 cWidth, cHeight;

    if (!connectedMapHeader)
        return;

    cWidth = connectedMapHeader->mapLayout->width;
    cHeight = connectedMapHeader->mapLayout->height;
    y = offset + MAP_OFFSET;
    x2 = cWidth - MAP_OFFSET;
    if (y < 0)
    {
        y2 = -y;
        if (y + cHeight < gBackupMapLayout.height)
            height = y + cHeight;
        else
            height = gBackupMapLayout.height;
        y = 0;
    }
    else
    {
        y2 = 0;
        if (y + cHeight < gBackupMapLayout.height)
            height = cHeight;
        else
            height = gBackupMapLayout.height - y;
    }

    FillConnection(/*x*/ 0, y, connectedMapHeader, x2, y2, /*width*/ MAP_OFFSET, height);
}

static void FillEastConnection(const struct MapHeader *mapHeader, const struct MapHeader *connectedMapHeader, s32 offset)
{
    s32 x, y;
    s32 y2;
    s32 height;
    s32 cHeight;
    if (!connectedMapHeader)
        return;

    cHeight = connectedMapHeader->mapLayout->height;
    x = mapHeader->mapLayout->width + MAP_OFFSET;
    y = offset + MAP_OFFSET;
    if (y < 0)
    {
        y2 = -y;
        if (y + cHeight < gBackupMapLayout.height)
            height = y + cHeight;
        else
            height = gBackupMapLayout.height;
        y = 0;
    }
    else
    {
        y2 = 0;
        if (y + cHeight < gBackupMapLayout.height)
            height = cHeight;
        else
            height = gBackupMapLayout.height - y;
    }

    FillConnection(x, y, connectedMapHeader, /*x2*/ 0, y2, /*width*/ MAP_OFFSET + 1, height);
}

u8 MapGridGetElevationAt(s32 x, s32 y)
{
    u16 block = GetMapGridBlockAt(x, y);

    if (block == MAPGRID_UNDEFINED)
        return 0;

    return UNPACK_ELEVATION(block);
}

u8 MapGridGetCollisionAt(s32 x, s32 y)
{
    u16 block = GetMapGridBlockAt(x, y);

    if (block == MAPGRID_UNDEFINED)
        return 1;

    return UNPACK_COLLISION(block);
}

u32 GetNumTilesInPrimary(struct MapLayout const *mapLayout)
{
    return mapLayout->isFrlg ? NUM_TILES_IN_PRIMARY_FRLG : NUM_TILES_IN_PRIMARY;
}

u32 GetNumMetatilesInPrimary(struct MapLayout const *mapLayout)
{
    return mapLayout->isFrlg ? NUM_METATILES_IN_PRIMARY_FRLG : NUM_METATILES_IN_PRIMARY;
}

u32 GetNumPalsInPrimary(struct MapLayout const *mapLayout)
{
    return mapLayout->isFrlg ? NUM_PALS_IN_PRIMARY_FRLG : NUM_PALS_IN_PRIMARY;
}

u32 MapGridGetMetatileIdAt(s32 x, s32 y)
{
    s32 block = GetMapGridBlockAt(x, y);

    if (block == MAPGRID_UNDEFINED)
        return GetBorderBlockAt(x, y) & MAPGRID_METATILE_ID_MASK;

    return UNPACK_METATILE(block);
}

u32 MapGridGetMetatileAttributeAt(s16 x, s16 y, u8 attributeType)
{
    u16 metatileId = MapGridGetMetatileIdAt(x, y);
    return GetAttributeByMetatileIdAndMapLayout(metatileId, attributeType, gMapHeader.mapLayout->isFrlg);
}

u32 MapGridGetMetatileBehaviorAt(s32 x, s32 y)
{
    return MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_BEHAVIOR);
}

u8 MapGridGetMetatileLayerTypeAt(s32 x, s32 y)
{
    return MapGridGetMetatileAttributeAt(x, y, METATILE_ATTRIBUTE_LAYER_TYPE);
}

void MapGridSetMetatileIdAt(s32 x, s32 y, u16 metatile)
{
    if (AreCoordsWithinMapGridBounds(x, y))
    {
        // Elevation is ignored in the argument, but copy metatile ID and collision
        gBackupMapLayout.map[x + y * gBackupMapLayout.width] &= MAPGRID_ELEVATION_MASK;
        gBackupMapLayout.map[x + y * gBackupMapLayout.width] |= metatile & ~MAPGRID_ELEVATION_MASK;
    }
}

void MapGridSetMetatileEntryAt(s32 x, s32 y, u16 metatile)
{
    if (AreCoordsWithinMapGridBounds(x, y))
    {
        gBackupMapLayout.map[x + gBackupMapLayout.width * y] = metatile;
    }
}

u32 ExtractMetatileAttribute(u32 attributes, u8 attributeType, bool32 isFrlg)
{
    if (attributeType >= METATILE_ATTRIBUTE_COUNT) // Check for METATILE_ATTRIBUTES_ALL
        return attributes;

    if (isFrlg)
        return (attributes & sMetatileAttrMasks[attributeType]) >> sMetatileAttrShifts[attributeType];

    return (attributes & sMetatileAttrMasksEmerald[attributeType]) >> sMetatileAttrShiftsEmerald[attributeType];
}

static u32 GetAttributeByMetatileIdAndMapLayoutFrlg(u16 metatile, u8 attributeType)
{
    u32 attribute;
    if (metatile < GetNumMetatilesInPrimary(gMapHeader.mapLayout))
    {
        const u32 *attributes = (const u32*)gMapHeader.mapLayout->primaryTileset->metatileAttributes;
        attribute = attributes[metatile];
    }
    else if (metatile < NUM_METATILES_TOTAL)
    {
        const u32 *attributes = (const u32*) gMapHeader.mapLayout->secondaryTileset->metatileAttributes;
        metatile -= GetNumMetatilesInPrimary(gMapHeader.mapLayout);
        attribute = attributes[metatile];
    }
    else
    {
        return MB_INVALID;
    }

    return ExtractMetatileAttribute(attribute, attributeType, TRUE);
}

u32 GetAttributeByMetatileIdAndMapLayout(u16 metatile, u8 attributeType, bool32 isFrlg)
{
    u32 attribute;

    if (isFrlg)
        return GetAttributeByMetatileIdAndMapLayoutFrlg(metatile, attributeType);

    if (metatile < GetNumMetatilesInPrimary(gMapHeader.mapLayout))
    {
        const u16 *attributes = (const u16*)gMapHeader.mapLayout->primaryTileset->metatileAttributes;
        attribute = attributes[metatile];
    }
    else if (metatile < NUM_METATILES_TOTAL)
    {
        const u16 *attributes = (const u16*)gMapHeader.mapLayout->secondaryTileset->metatileAttributes;
        metatile -= GetNumMetatilesInPrimary(gMapHeader.mapLayout);
        attribute = attributes[metatile];
    }
    else
    {
        return MB_INVALID;
    }

    return ExtractMetatileAttribute(attribute, attributeType, FALSE);
}

void SaveMapView(void)
{
    s32 i, j;
    s32 x, y;
    u16 *mapView;
    s32 width;
    mapView = gSaveBlock1Ptr->mapView;
    width = gBackupMapLayout.width;
    x = gSaveBlock1Ptr->pos.x;
    y = gSaveBlock1Ptr->pos.y;
    for (i = y; i < y + MAP_OFFSET_H; i++)
    {
        for (j = x; j < x + MAP_OFFSET_W; j++)
            *mapView++ = sBackupMapData[width * i + j];
    }
}

static bool32 SavedMapViewIsEmpty(void)
{
    u16 i;
    u32 marker = 0;

#ifndef UBFIX
    for (i = 0; i < sizeof(gSaveBlock1Ptr->mapView); i++)
        marker |= gSaveBlock1Ptr->mapView[i];
#else
    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->mapView); i++)
        marker |= gSaveBlock1Ptr->mapView[i];
#endif


    if (marker == 0)
        return TRUE;
    else
        return FALSE;
}

static void ClearSavedMapView(void)
{
    CpuFill16(0, gSaveBlock1Ptr->mapView, sizeof(gSaveBlock1Ptr->mapView));
}

static void LoadSavedMapView(void)
{
    u8 yMode;
    s32 i, j;
    s32 x, y;
    u16 *mapView;
    s32 width;
    mapView = gSaveBlock1Ptr->mapView;
    if (SavedMapViewIsEmpty())
        return;

    width = gBackupMapLayout.width;
    x = gSaveBlock1Ptr->pos.x;
    y = gSaveBlock1Ptr->pos.y;
    for (i = y; i < y + MAP_OFFSET_H; i++)
    {
        if (i == y && i != 0)
            yMode = 0;
        else if (i == y + MAP_OFFSET_H - 1 && i != gMapHeader.mapLayout->height - 1)
            yMode = 1;
        else
            yMode = 0xFF;

        for (j = x; j < x + MAP_OFFSET_W; j++)
        {
            if (!SkipCopyingMetatileFromSavedMap(&sBackupMapData[j + width * i], width, yMode))
                sBackupMapData[j + width * i] = *mapView;
            mapView++;
        }
    }
    for (j = x; j < x + MAP_OFFSET_W; j++)
    {
        if (y != 0)
            FixLongGrassMetatilesWindowTop(j, y - 1);
        if (i < gMapHeader.mapLayout->height - 1)
            FixLongGrassMetatilesWindowBottom(j, y + MAP_OFFSET_H - 1);
    }
    ClearSavedMapView();
}

static void MoveMapViewToBackup(enum Connection direction)
{
    s32 width;
    s32 x0, y0;
    s32 x2, y2;
    s32 x, y;
    s32 i, j;

    u16 *mapView = gSaveBlock1Ptr->mapView;
    
    width = gBackupMapLayout.width;
    i = 0;
    j = 0;
    x0 = gSaveBlock1Ptr->pos.x;
    y0 = gSaveBlock1Ptr->pos.y;
    x2 = MAP_OFFSET_W;
    y2 = MAP_OFFSET_H;

    switch (direction)
    {
    case CONNECTION_NORTH:
        y0++;
        y2 = MAP_OFFSET_H - 1;
        break;
    case CONNECTION_SOUTH:
        j = 1;
        y2 = MAP_OFFSET_H - 1;
        break;
    case CONNECTION_WEST:
        x0++;
        x2 = MAP_OFFSET_W - 1;
        break;
    case CONNECTION_EAST:
        i = 1;
        x2 = MAP_OFFSET_W - 1;
        break;
    default:
        break;
    }

    for (y = 0; y < y2; y++)
    {
        for (x = 0; x < x2; x++)
        {
            sBackupMapData[x + x0 + width * (y + y0)] = mapView[i + x + MAP_OFFSET_W * (j + y)];
        }
    }

    ClearSavedMapView();
}

enum Connection GetMapBorderIdAt(s32 x, s32 y)
{
    if (GetMapGridBlockAt(x, y) == MAPGRID_UNDEFINED)
        return CONNECTION_INVALID;

    if (x >= (gBackupMapLayout.width - (MAP_OFFSET + 1)))
    {
        if (!sMapConnectionFlags.east)
            return CONNECTION_INVALID;

        return CONNECTION_EAST;
    }
    else if (x < MAP_OFFSET)
    {
        if (!sMapConnectionFlags.west)
            return CONNECTION_INVALID;

        return CONNECTION_WEST;
    }
    else if (y >= (gBackupMapLayout.height - MAP_OFFSET))
    {
        if (!sMapConnectionFlags.south)
            return CONNECTION_INVALID;

        return CONNECTION_SOUTH;
    }
    else if (y < MAP_OFFSET)
    {
        if (!sMapConnectionFlags.north)
            return CONNECTION_INVALID;

        return CONNECTION_NORTH;
    }
    else
    {
        return CONNECTION_NONE;
    }
}

enum Connection GetPostCameraMoveMapBorderId(s32 x, s32 y)
{
    return GetMapBorderIdAt(gSaveBlock1Ptr->pos.x + MAP_OFFSET + x, gSaveBlock1Ptr->pos.y + MAP_OFFSET + y);
}

bool32 CanCameraMoveInDirection(enum Direction direction)
{
    s32 x, y;
    x = gSaveBlock1Ptr->pos.x + MAP_OFFSET + gDirectionToVectors[direction].x;
    y = gSaveBlock1Ptr->pos.y + MAP_OFFSET + gDirectionToVectors[direction].y;

    if (GetMapBorderIdAt(x, y) == CONNECTION_INVALID)
        return FALSE;

    return TRUE;
}

static void SetPositionFromConnection(const struct MapConnection *connection, enum Connection direction, s32 x, s32 y)
{
    struct MapHeader const *mapHeader = GetMapHeaderFromConnection(connection);

    switch (direction)
    {
    case CONNECTION_EAST:
        gSaveBlock1Ptr->pos.x = -x;
        gSaveBlock1Ptr->pos.y -= connection->offset;
        break;
    case CONNECTION_WEST:
        gSaveBlock1Ptr->pos.x = mapHeader->mapLayout->width;
        gSaveBlock1Ptr->pos.y -= connection->offset;
        break;
    case CONNECTION_SOUTH:
        gSaveBlock1Ptr->pos.x -= connection->offset;
        gSaveBlock1Ptr->pos.y = -y;
        break;
    case CONNECTION_NORTH:
        gSaveBlock1Ptr->pos.x -= connection->offset;
        gSaveBlock1Ptr->pos.y = mapHeader->mapLayout->height;
        break;
    default:
        errorf("invalid direction: %d", direction);
        break;
    }
}

bool8 CameraMove(s32 x, s32 y)
{
    enum Connection direction;
    const struct MapConnection *connection;
    s32 old_x, old_y;
    gCamera.active = FALSE;
    direction = GetPostCameraMoveMapBorderId(x, y);
    if (direction == CONNECTION_NONE || direction == CONNECTION_INVALID)
    {
        gSaveBlock1Ptr->pos.x += x;
        gSaveBlock1Ptr->pos.y += y;
    }
    else
    {
        SaveMapView();
        ClearMirageTowerPulseBlendEffect();
        old_x = gSaveBlock1Ptr->pos.x;
        old_y = gSaveBlock1Ptr->pos.y;
        connection = GetIncomingConnection(direction, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
        assertf(connection)
        {
            return gCamera.active;
        }

        SetPositionFromConnection(connection, direction, x, y);
        LoadMapFromCameraTransition(connection->mapGroup, connection->mapNum);
        gCamera.active = TRUE;
        gCamera.x = old_x - gSaveBlock1Ptr->pos.x;
        gCamera.y = old_y - gSaveBlock1Ptr->pos.y;
        gSaveBlock1Ptr->pos.x += x;
        gSaveBlock1Ptr->pos.y += y;
        MoveMapViewToBackup(direction);
    }

    return gCamera.active;
}

static const struct MapConnection *GetIncomingConnection(enum Connection direction, s32 x, s32 y)
{
    s32 count;
    s32 i;
    const struct MapConnection *connection;
    const struct MapConnections *connections = gMapHeader.connections;

#ifdef UBFIX // UB: Multiple possible null dereferences
    if (connections == NULL || connections->connections == NULL)
        return NULL;
#endif
    count = connections->count;
    connection = connections->connections;
    for (i = 0; i < count; i++, connection++)
    {
        if (connection->direction == direction && IsPosInIncomingConnectingMap(direction, x, y, connection) == TRUE)
            return connection;
    }
    return NULL;
}

static bool8 IsPosInIncomingConnectingMap(enum Connection direction, s32 x, s32 y, const struct MapConnection *connection)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
    switch (direction)
    {
    case CONNECTION_SOUTH:
    case CONNECTION_NORTH:
        return IsCoordInIncomingConnectingMap(x, gMapHeader.mapLayout->width, mapHeader->mapLayout->width, connection->offset);
    case CONNECTION_WEST:
    case CONNECTION_EAST:
        return IsCoordInIncomingConnectingMap(y, gMapHeader.mapLayout->height, mapHeader->mapLayout->height, connection->offset);
    default:
        return FALSE;
    }
}

static bool8 IsCoordInIncomingConnectingMap(s32 coord, s32 srcMax, s32 destMax, s32 offset)
{
    s32 min, max;

    if (offset < 0)
        min = 0;
    else
        min = offset;

    if (destMax + offset < srcMax)
        max = destMax + offset;
    else
        max = srcMax;

    if (min <= coord && coord <= max)
        return TRUE;

    return FALSE;
}

static s32 IsCoordInConnectingMap(s32 coord, s32 max)
{
    if (coord >= 0 && coord < max)
        return TRUE;

    return FALSE;
}

static s32 IsPosInConnectingMap(const struct MapConnection *connection, s32 x, s32 y)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
    switch (connection->direction)
    {
    case CONNECTION_SOUTH:
    case CONNECTION_NORTH:
        return IsCoordInConnectingMap(x - connection->offset, mapHeader->mapLayout->width);
    case CONNECTION_WEST:
    case CONNECTION_EAST:
        return IsCoordInConnectingMap(y - connection->offset, mapHeader->mapLayout->height);
    }
    return FALSE;
}

const struct MapConnection *GetMapConnectionAtPos(s16 x, s16 y)
{
    s32 count;
    const struct MapConnection *connection;
    s32 i;
    enum Connection direction;
    if (!gMapHeader.connections)
    {
        return NULL;
    }

    count = gMapHeader.connections->count;
    connection = gMapHeader.connections->connections;
    for (i = 0; i < count; i++, connection++)
    {
        direction = connection->direction;
        if (direction == CONNECTION_DIVE || direction == CONNECTION_EMERGE)
            continue;
        else if (direction == CONNECTION_NORTH && y > MAP_OFFSET - 1)
            continue;
        else if (direction == CONNECTION_SOUTH && y < gMapHeader.mapLayout->height + MAP_OFFSET)
            continue;
        else if (direction == CONNECTION_WEST && x > MAP_OFFSET - 1)
            continue;
        else if (direction == CONNECTION_EAST && x < gMapHeader.mapLayout->width + MAP_OFFSET)
            continue;

        if (IsPosInConnectingMap(connection, x - MAP_OFFSET, y - MAP_OFFSET) == TRUE)
            return connection;
    }
    return NULL;
}

void SetCameraFocusCoords(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x - MAP_OFFSET;
    gSaveBlock1Ptr->pos.y = y - MAP_OFFSET;
}

void GetCameraFocusCoords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x + MAP_OFFSET;
    *y = gSaveBlock1Ptr->pos.y + MAP_OFFSET;
}

static void UNUSED SetCameraCoords(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x;
    gSaveBlock1Ptr->pos.y = y;
}

void GetCameraCoords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x;
    *y = gSaveBlock1Ptr->pos.y;
}

void MapGridSetMetatileImpassabilityAt(s32 x, s32 y, bool32 impassable)
{
    if (AreCoordsWithinMapGridBounds(x, y))
    {
        if (impassable)
            gBackupMapLayout.map[x + gBackupMapLayout.width * y] |= MAPGRID_COLLISION_MASK;
        else
            gBackupMapLayout.map[x + gBackupMapLayout.width * y] &= ~MAPGRID_COLLISION_MASK;
    }
}

static bool8 SkipCopyingMetatileFromSavedMap(u16 *mapBlock, u16 mapWidth, u8 yMode)
{
    if (yMode == 0xFF)
        return FALSE;

    if (yMode == 0)
        mapBlock -= mapWidth;
    else
        mapBlock += mapWidth;

    if (IsLargeBreakableDecoration(UNPACK_METATILE(*mapBlock), yMode) == TRUE)
        return TRUE;
    return FALSE;
}

static void CopyTilesetToVram(struct Tileset const *tileset, u16 numTiles, u16 offset)
{
    if (tileset)
    {
        if (!tileset->isCompressed)
            LoadBgTiles(2, tileset->tiles, numTiles * 32, offset);
        else
            DecompressAndCopyTileDataToVram(2, tileset->tiles, numTiles * 32, offset, 0);
    }
}

static void CopyTilesetToVramUsingHeap(struct Tileset const *tileset, u16 numTiles, u16 offset)
{
    if (tileset)
    {
        if (!tileset->isCompressed)
            LoadBgTiles(2, tileset->tiles, numTiles * 32, offset);
        else
            DecompressAndLoadBgGfxUsingHeap(2, tileset->tiles, numTiles * 32, offset, 0);
    }
}

// Below two are dummied functions from FRLG, used to tint the overworld palettes for the Quest Log
static void ApplyGlobalTintToPaletteEntries(u16 offset, u16 size)
{

}

static void UNUSED ApplyGlobalTintToPaletteSlot(u8 slot, u8 count)
{

}

static void LoadTilesetPalette(struct Tileset const *tileset, u16 destOffset, u16 size, bool8 skipFaded, u32 numPalsInPrimary)
{
    if (tileset)
    {
        if (tileset->isSecondary == FALSE)
        {
            if (skipFaded)
                CpuFastCopy(tileset->palettes, &gPlttBufferUnfaded[destOffset], size); // always word-aligned
            else
                LoadPaletteFast(tileset->palettes, destOffset, size);
            gPlttBufferFaded[destOffset] = gPlttBufferUnfaded[destOffset] = RGB_BLACK;
            ApplyGlobalTintToPaletteEntries(destOffset + 1, (size - 2) >> 1);
        }
        else if (tileset->isSecondary == TRUE)
        {
            // All 'gTilesetPalettes_' arrays should have ALIGNED(4) in them,
            // but we use SmartCopy here just in case they don't
            if (skipFaded)
                CpuCopy16(tileset->palettes[numPalsInPrimary], &gPlttBufferUnfaded[destOffset], size);
            else
                LoadPaletteFast(tileset->palettes[numPalsInPrimary], destOffset, size);
        }
        else
        {
            LoadPalette((const u16 *)tileset->palettes, destOffset, size);
            ApplyGlobalTintToPaletteEntries(destOffset, size >> 1);
        }
    }
}

void CopyPrimaryTilesetToVram(struct MapLayout const *mapLayout)
{
    CopyTilesetToVram(mapLayout->primaryTileset, GetNumTilesInPrimary(mapLayout), 0);
}

void CopySecondaryTilesetToVram(struct MapLayout const *mapLayout)
{
    CopyTilesetToVram(mapLayout->secondaryTileset, NUM_TILES_TOTAL - GetNumTilesInPrimary(mapLayout), GetNumTilesInPrimary(mapLayout));
}

void CopySecondaryTilesetToVramUsingHeap(struct MapLayout const *mapLayout)
{
    CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - GetNumTilesInPrimary(mapLayout), GetNumTilesInPrimary(mapLayout));
}

static void LoadPrimaryTilesetPalette(struct MapLayout const *mapLayout)
{
    LoadTilesetPalette(mapLayout->primaryTileset, 0, GetNumPalsInPrimary(mapLayout) * PLTT_SIZE_4BPP, FALSE, GetNumPalsInPrimary(mapLayout));
}

void LoadSecondaryTilesetPalette(struct MapLayout const *mapLayout, bool8 skipFaded)
{
    LoadTilesetPalette(mapLayout->secondaryTileset, GetNumPalsInPrimary(mapLayout) * 16, (NUM_PALS_TOTAL - GetNumPalsInPrimary(mapLayout)) * PLTT_SIZE_4BPP, skipFaded, GetNumPalsInPrimary(mapLayout));
}

void CopyMapTilesetsToVram(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
        CopyTilesetToVramUsingHeap(mapLayout->primaryTileset, GetNumTilesInPrimary(mapLayout), 0);
        CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - GetNumTilesInPrimary(mapLayout), GetNumTilesInPrimary(mapLayout));
    }
}

void LoadMapTilesetPalettes(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
        LoadPrimaryTilesetPalette(mapLayout);
        LoadSecondaryTilesetPalette(mapLayout, FALSE);
    }
}

bool32 AreCoordsInsideMap(u8 mapGroup, u8 mapNum, s16 x, s16 y)
{
    const struct MapLayout *layout = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->mapLayout;
    s32 width = layout->width;
    s32 height = layout->height;
    x -= MAP_OFFSET;
    y -= MAP_OFFSET;

    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
    {
        width *= PYRAMID_FLOOR_SQUARES_WIDE;
        height *= PYRAMID_FLOOR_SQUARES_HIGH;
    }

    return (x >= 0 && x < width && y >= 0 && y < height);
}

bool32 AreCoordsInsidePlayerMap(s16 x, s16 y)
{
    return AreCoordsInsideMap(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, x, y);
}
