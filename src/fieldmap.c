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

struct ConnectionFlags
{
    u8 south:1;
    u8 north:1;
    u8 west:1;
    u8 east:1;
};

EWRAM_DATA static u16 gBackupMapData[MAX_MAP_DATA_SIZE] = {0};
EWRAM_DATA struct MapHeader gMapHeader = {0};
EWRAM_DATA struct Camera gCamera = {0};
EWRAM_DATA static struct ConnectionFlags gMapConnectionFlags = {0};
EWRAM_DATA static u32 sFiller = 0; // without this, the next file won't align properly

struct BackupMapLayout gBackupMapLayout;

static const struct ConnectionFlags sDummyConnectionFlags = {0};

static void InitMapLayoutData(struct MapHeader *mapHeader);
static void InitBackupMapLayoutData(u16 *map, u16 width, u16 height);
static void FillSouthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillNorthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillWestConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void FillEastConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset);
static void InitBackupMapLayoutConnections(struct MapHeader *mapHeader);
static void LoadSavedMapView(void);
static bool8 SkipCopyingMetatileFromSavedMap(u16* mapMetatilePtr, u16 mapWidth, u8 yMode);

struct MapHeader const *const GetMapHeaderFromConnection(struct MapConnection *connection)
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
    CpuFastFill(0x03ff03ff, gBackupMapData, sizeof(gBackupMapData));
    GenerateBattlePyramidFloorLayout(gBackupMapData, setPlayerPosition);
}

void InitTrainerHillMap(void)
{
    CpuFastFill(0x03ff03ff, gBackupMapData, sizeof(gBackupMapData));
    GenerateTrainerHillFloorLayout(gBackupMapData);
}

static void InitMapLayoutData(struct MapHeader *mapHeader)
{
    struct MapLayout const *mapLayout;
    int width;
    int height;
    mapLayout = mapHeader->mapLayout;
    CpuFastFill16(0x03ff, gBackupMapData, sizeof(gBackupMapData));
    gBackupMapLayout.map = gBackupMapData;
    width = mapLayout->width + 15;
    gBackupMapLayout.width = width;
    height = mapLayout->height + 14;
    gBackupMapLayout.height = height;
    if (width * height <= MAX_MAP_DATA_SIZE)
    {
        InitBackupMapLayoutData(mapLayout->map, mapLayout->width, mapLayout->height);
        InitBackupMapLayoutConnections(mapHeader);
    }
}

static void InitBackupMapLayoutData(u16 *map, u16 width, u16 height)
{
    u16 *dest;
    int y;
    dest = gBackupMapLayout.map;
    dest += gBackupMapLayout.width * 7 + 7;
    for (y = 0; y < height; y++)
    {
        CpuCopy16(map, dest, width * 2);
        dest += width + 15;
        map += width;
    }
}

static void InitBackupMapLayoutConnections(struct MapHeader *mapHeader)
{
    int count;
    struct MapConnection *connection;
    int i;

    if (mapHeader->connections)
    {
        count = mapHeader->connections->count;
        connection = mapHeader->connections->connections;
        gMapConnectionFlags = sDummyConnectionFlags;
        for (i = 0; i < count; i++, connection++)
        {
            struct MapHeader const *cMap = GetMapHeaderFromConnection(connection);
            u32 offset = connection->offset;
            switch (connection->direction)
            {
            case CONNECTION_SOUTH:
                FillSouthConnection(mapHeader, cMap, offset);
                gMapConnectionFlags.south = 1;
                break;
            case CONNECTION_NORTH:
                FillNorthConnection(mapHeader, cMap, offset);
                gMapConnectionFlags.north = 1;
                break;
            case CONNECTION_WEST:
                FillWestConnection(mapHeader, cMap, offset);
                gMapConnectionFlags.west = 1;
                break;
            case CONNECTION_EAST:
                FillEastConnection(mapHeader, cMap, offset);
                gMapConnectionFlags.east = 1;
                break;
            }
        }
    }
}

static void sub_8087F54(int x, int y, struct MapHeader const *connectedMapHeader, int x2, int y2, int width, int height)
{
    int i;
    u16 *src;
    u16 *dest;
    int mapWidth;

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

static void FillSouthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int x, y;
    int x2;
    int width;
    int cWidth;

    if (connectedMapHeader)
    {
        cWidth = connectedMapHeader->mapLayout->width;
        x = offset + 7;
        y = mapHeader->mapLayout->height + 7;
        if (x < 0)
        {
            x2 = -x;
            x += cWidth;
            if (x < gBackupMapLayout.width)
            {
                width = x;
            }
            else
            {
                width = gBackupMapLayout.width;
            }
            x = 0;
        }
        else
        {
            x2 = 0;
            if (x + cWidth < gBackupMapLayout.width)
            {
                width = cWidth;
            }
            else
            {
                width = gBackupMapLayout.width - x;
            }
        }

        sub_8087F54(
            x, y,
            connectedMapHeader,
            x2, /*y2*/ 0,
            width, /*height*/ 7);
    }
}

static void FillNorthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int x;
    int x2, y2;
    int width;
    int cWidth, cHeight;

    if (connectedMapHeader)
    {
        cWidth = connectedMapHeader->mapLayout->width;
        cHeight = connectedMapHeader->mapLayout->height;
        x = offset + 7;
        y2 = cHeight - 7;
        if (x < 0)
        {
            x2 = -x;
            x += cWidth;
            if (x < gBackupMapLayout.width)
            {
                width = x;
            }
            else
            {
                width = gBackupMapLayout.width;
            }
            x = 0;
        }
        else
        {
            x2 = 0;
            if (x + cWidth < gBackupMapLayout.width)
            {
                width = cWidth;
            }
            else
            {
                width = gBackupMapLayout.width - x;
            }
        }

        sub_8087F54(
            x, /*y*/ 0,
            connectedMapHeader,
            x2, y2,
            width, /*height*/ 7);

    }
}

static void FillWestConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int y;
    int x2, y2;
    int height;
    int cWidth, cHeight;
    if (connectedMapHeader)
    {
        cWidth = connectedMapHeader->mapLayout->width;
        cHeight = connectedMapHeader->mapLayout->height;
        y = offset + 7;
        x2 = cWidth - 7;
        if (y < 0)
        {
            y2 = -y;
            if (y + cHeight < gBackupMapLayout.height)
            {
                height = y + cHeight;
            }
            else
            {
                height = gBackupMapLayout.height;
            }
            y = 0;
        }
        else
        {
            y2 = 0;
            if (y + cHeight < gBackupMapLayout.height)
            {
                height = cHeight;
            }
            else
            {
                height = gBackupMapLayout.height - y;
            }
        }

        sub_8087F54(
            /*x*/ 0, y,
            connectedMapHeader,
            x2, y2,
            /*width*/ 7, height);
    }
}

static void FillEastConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
{
    int x, y;
    int y2;
    int height;
    int cHeight;
    if (connectedMapHeader)
    {
        cHeight = connectedMapHeader->mapLayout->height;
        x = mapHeader->mapLayout->width + 7;
        y = offset + 7;
        if (y < 0)
        {
            y2 = -y;
            if (y + cHeight < gBackupMapLayout.height)
            {
                height = y + cHeight;
            }
            else
            {
                height = gBackupMapLayout.height;
            }
            y = 0;
        }
        else
        {
            y2 = 0;
            if (y + cHeight < gBackupMapLayout.height)
            {
                height = cHeight;
            }
            else
            {
                height = gBackupMapLayout.height - y;
            }
        }

        sub_8087F54(
            x, y,
            connectedMapHeader,
            /*x2*/ 0, y2,
            /*width*/ 8, height);
    }
}

union Block
{
    struct
    {
        u16 block:10;
        u16 collision:2;
        u16 elevation:4;
    } block;
    u16 value;
};

u8 MapGridGetZCoordAt(int x, int y)
{
    u16 block;
    int i;
    u16 *border;

    if (x >= 0 && x < gBackupMapLayout.width
     && y >= 0 && y < gBackupMapLayout.height)
    {
        block = gBackupMapLayout.map[x + gBackupMapLayout.width * y];
    }
    else
    {
        border = gMapHeader.mapLayout->border;
        i = (x + 1) & 1;
        i += ((y + 1) & 1) * 2;
        block = gMapHeader.mapLayout->border[i];
        block |= METATILE_COLLISION_MASK;
    }

    if (block == METATILE_ID_UNDEFINED)
    {
        return 0;
    }

    return block >> METATILE_ELEVATION_SHIFT;
}

u8 MapGridIsImpassableAt(int x, int y)
{
    u16 block;
    int i;
    u16 *border;

    if (x >= 0 && x < gBackupMapLayout.width
     && y >= 0 && y < gBackupMapLayout.height)
    {
        block = gBackupMapLayout.map[x + gBackupMapLayout.width * y];
    }
    else
    {
        border = gMapHeader.mapLayout->border;
        i = (x + 1) & 1;
        i += ((y + 1) & 1) * 2;
        block = gMapHeader.mapLayout->border[i];
        block |= METATILE_COLLISION_MASK;
    }
    if (block == METATILE_ID_UNDEFINED)
    {
        return 1;
    }
    return (block & METATILE_COLLISION_MASK) >> METATILE_COLLISION_SHIFT;
}

u32 MapGridGetMetatileIdAt(int x, int y)
{
    u16 block;
    int i;
    int j;
    struct MapLayout const *mapLayout;
    u16 *border;
    u16 block2;

    if (x >= 0 && x < gBackupMapLayout.width
     && y >= 0 && y < gBackupMapLayout.height)
    {
        block = gBackupMapLayout.map[x + gBackupMapLayout.width * y];
    }
    else
    {
        mapLayout = gMapHeader.mapLayout;
        i = (x + 1) & 1;
        i += ((y + 1) & 1) * 2;
        block = mapLayout->border[i] | METATILE_COLLISION_MASK;
    }
    if (block == METATILE_ID_UNDEFINED)
    {
        border = gMapHeader.mapLayout->border;
        j = (x + 1) & 1;
        j += ((y + 1) & 1) * 2;
        block2 = gMapHeader.mapLayout->border[j];
        // This OR is completely pointless.
        block2 |= METATILE_COLLISION_MASK;
        return block2 & METATILE_ID_MASK;
    }
    return block & METATILE_ID_MASK;
}

u32 MapGridGetMetatileBehaviorAt(int x, int y)
{
    u16 metatile;
    metatile = MapGridGetMetatileIdAt(x, y);
    return GetBehaviorByMetatileId(metatile) & 0xff;
}

u8 MapGridGetMetatileLayerTypeAt(int x, int y)
{
    u16 metatile;
    metatile = MapGridGetMetatileIdAt(x, y);
    return (GetBehaviorByMetatileId(metatile) & METATILE_ELEVATION_MASK) >> METATILE_ELEVATION_SHIFT;
}

void MapGridSetMetatileIdAt(int x, int y, u16 metatile)
{
    int i;
    if (x >= 0 && x < gBackupMapLayout.width
     && y >= 0 && y < gBackupMapLayout.height)
    {
        i = x + y * gBackupMapLayout.width;
        gBackupMapLayout.map[i] = (gBackupMapLayout.map[i] & METATILE_ELEVATION_MASK) | (metatile & ~METATILE_ELEVATION_MASK);
    }
}

void MapGridSetMetatileEntryAt(int x, int y, u16 metatile)
{
    int i;
    if (x >= 0 && x < gBackupMapLayout.width
     && y >= 0 && y < gBackupMapLayout.height)
    {
        i = x + gBackupMapLayout.width * y;
        gBackupMapLayout.map[i] = metatile;
    }
}

u16 GetBehaviorByMetatileId(u16 metatile)
{
    u16 *attributes;
    if (metatile < NUM_METATILES_IN_PRIMARY)
    {
        attributes = gMapHeader.mapLayout->primaryTileset->metatileAttributes;
        return attributes[metatile];
    }
    else if (metatile < NUM_METATILES_TOTAL)
    {
        attributes = gMapHeader.mapLayout->secondaryTileset->metatileAttributes;
        return attributes[metatile - NUM_METATILES_IN_PRIMARY];
    }
    else
    {
        return 0xFF;
    }
}

void save_serialize_map(void)
{
    int i, j;
    int x, y;
    u16 *mapView;
    int width;
    mapView = gSaveBlock1Ptr->mapView;
    width = gBackupMapLayout.width;
    x = gSaveBlock1Ptr->pos.x;
    y = gSaveBlock1Ptr->pos.y;
    for (i = y; i < y + 14; i++)
    {
        for (j = x; j < x + 15; j++)
        {
            *mapView++ = gBackupMapData[width * i + j];
        }
    }
}

static bool32 SavedMapViewIsEmpty(void)
{
    u16 i;
    u32 marker = 0;

#ifndef UBFIX
    // BUG: This loop extends past the bounds of the mapView array. Its size is only 0x100.
    for (i = 0; i < 0x200; i++)
        marker |= gSaveBlock1Ptr->mapView[i];
#else
    // UBFIX: Only iterate over 0x100
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
    int i, j;
    int x, y;
    u16 *mapView;
    int width;
    mapView = gSaveBlock1Ptr->mapView;
    if (!SavedMapViewIsEmpty())
    {
        width = gBackupMapLayout.width;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        for (i = y; i < y + 14; i++)
        {
            if (i == y && i != 0)
                yMode = 0;
            else if (i == y + 13 && i != gMapHeader.mapLayout->height - 1)
                yMode = 1;
            else
                yMode = 0xFF;

            for (j = x; j < x + 15; j++)
            {
                if (!SkipCopyingMetatileFromSavedMap(&gBackupMapData[j + width * i], width, yMode))
                    gBackupMapData[j + width * i] = *mapView;
                mapView++;
            }
        }
        for (j = x; j < x + 15; j++)
        {
            if (y != 0)
                FixLongGrassMetatilesWindowTop(j, y - 1);
            if (i < gMapHeader.mapLayout->height - 1)
                FixLongGrassMetatilesWindowBottom(j, y + 13);
        }
        ClearSavedMapView();
    }
}

void sub_80885C4(u8 a1)
{
    int width;
    u16 *mapView;
    int x0, y0;
    int x2, y2;
    u16 *src, *dest;
    int srci, desti;
    int r9, r8;
    int x, y;
    int i, j;
    mapView = gSaveBlock1Ptr->mapView;
    width = gBackupMapLayout.width;
    r9 = 0;
    r8 = 0;
    x0 = gSaveBlock1Ptr->pos.x;
    y0 = gSaveBlock1Ptr->pos.y;
    x2 = 15;
    y2 = 14;
    switch (a1)
    {
    case CONNECTION_NORTH:
        y0 += 1;
        y2 = 13;
        break;
    case CONNECTION_SOUTH:
        r8 = 1;
        y2 = 13;
        break;
    case CONNECTION_WEST:
        x0 += 1;
        x2 = 14;
        break;
    case CONNECTION_EAST:
        r9 = 1;
        x2 = 14;
        break;
    }
    for (y = 0; y < y2; y++)
    {
        i = 0;
        j = 0;
        for (x = 0; x < x2; x++)
        {
            desti = width * (y + y0);
            srci = (y + r8) * 15 + r9;
            src = &mapView[srci + i];
            dest = &gBackupMapData[x0 + desti + j];
            *dest = *src;
            i++;
            j++;
        }
    }
    ClearSavedMapView();
}

int GetMapBorderIdAt(int x, int y)
{
    struct MapLayout const *mapLayout;
    u16 block, block2;
    int i, j;
    if (x >= 0 && x < gBackupMapLayout.width
     && y >= 0 && y < gBackupMapLayout.height)
    {
        i = gBackupMapLayout.width;
        i *= y;
        block = gBackupMapLayout.map[x + i];
        if (block == METATILE_ID_UNDEFINED)
        {
            goto fail;
        }
    }
    else
    {
        mapLayout = gMapHeader.mapLayout;
        j = (x + 1) & 1;
        j += ((y + 1) & 1) * 2;
        block2 = METATILE_COLLISION_MASK | mapLayout->border[j];
        if (block2 == METATILE_ID_UNDEFINED)
        {
            goto fail;
        }
    }
    goto success;
fail:
    return -1;
success:

    if (x >= (gBackupMapLayout.width - 8))
    {
        if (!gMapConnectionFlags.east)
        {
            return -1;
        }
        return CONNECTION_EAST;
    }
    else if (x < 7)
    {
        if (!gMapConnectionFlags.west)
        {
            return -1;
        }
        return CONNECTION_WEST;
    }
    else if (y >= (gBackupMapLayout.height - 7))
    {
        if (!gMapConnectionFlags.south)
        {
            return -1;
        }
        return CONNECTION_SOUTH;
    }
    else if (y < 7)
    {
        if (!gMapConnectionFlags.north)
        {
            return -1;
        }
        return CONNECTION_NORTH;
    }
    else
    {
        return 0;
    }
}

int GetPostCameraMoveMapBorderId(int x, int y)
{
    return GetMapBorderIdAt(gSaveBlock1Ptr->pos.x + 7 + x, gSaveBlock1Ptr->pos.y + 7 + y);
}

int CanCameraMoveInDirection(int direction)
{
    int x, y;
    x = gSaveBlock1Ptr->pos.x + 7 + gDirectionToVectors[direction].x;
    y = gSaveBlock1Ptr->pos.y + 7 + gDirectionToVectors[direction].y;
    if (GetMapBorderIdAt(x, y) == -1)
    {
        return 0;
    }
    return 1;
}

void sub_80887F8(struct MapConnection *connection, int direction, int x, int y)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
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
    }
}

bool8 CameraMove(int x, int y)
{
    unsigned int direction;
    struct MapConnection *connection;
    int old_x, old_y;
    gCamera.active = FALSE;
    direction = GetPostCameraMoveMapBorderId(x, y);
    if (direction + 1 <= 1)
    {
        gSaveBlock1Ptr->pos.x += x;
        gSaveBlock1Ptr->pos.y += y;
    }
    else
    {
        save_serialize_map();
        ClearMirageTowerPulseBlendEffect();
        old_x = gSaveBlock1Ptr->pos.x;
        old_y = gSaveBlock1Ptr->pos.y;
        connection = sub_8088950(direction, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
        sub_80887F8(connection, direction, x, y);
        LoadMapFromCameraTransition(connection->mapGroup, connection->mapNum);
        gCamera.active = TRUE;
        gCamera.x = old_x - gSaveBlock1Ptr->pos.x;
        gCamera.y = old_y - gSaveBlock1Ptr->pos.y;
        gSaveBlock1Ptr->pos.x += x;
        gSaveBlock1Ptr->pos.y += y;
        sub_80885C4(direction);
    }
    return gCamera.active;
}

struct MapConnection *sub_8088950(u8 direction, int x, int y)
{
    int count;
    int i;
    struct MapConnection *connection;
    const struct MapConnections *connections = gMapHeader.connections;
    // UB: Multiple possible null dereferences
#ifdef UBFIX
    if (connections != NULL)
    {
        count = connections->count;
        connection = connections->connections;
        if (connection != NULL)
        {
            for (i = 0; i < count; i++, connection++)
            {
                if (connection->direction == direction && sub_80889A8(direction, x, y, connection) == TRUE)
                    return connection;
            }
        }
    }
#else
    count = connections->count;
    connection = connections->connections;
    for (i = 0; i < count; i++, connection++)
    {
        if (connection->direction == direction && sub_80889A8(direction, x, y, connection) == TRUE)
            return connection;
    }
#endif
    return NULL;
}

bool8 sub_80889A8(u8 direction, int x, int y, struct MapConnection *connection)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
    switch (direction)
    {
    case CONNECTION_SOUTH:
    case CONNECTION_NORTH:
        return sub_8088A0C(x, gMapHeader.mapLayout->width, mapHeader->mapLayout->width, connection->offset);
    case CONNECTION_WEST:
    case CONNECTION_EAST:
        return sub_8088A0C(y, gMapHeader.mapLayout->height, mapHeader->mapLayout->height, connection->offset);
    }
    return FALSE;
}

bool8 sub_8088A0C(int x, int src_width, int dest_width, int offset)
{
    int offset2;
    offset2 = offset;

    if (offset2 < 0)
        offset2 = 0;

    if (dest_width + offset < src_width)
        src_width = dest_width + offset;

    if (offset2 <= x && x <= src_width)
        return TRUE;

    return FALSE;
}

int sub_8088A38(int x, int width)
{
    if (x >= 0 && x < width)
        return TRUE;

    return FALSE;
}

int sub_8088A4C(struct MapConnection *connection, int x, int y)
{
    struct MapHeader const *mapHeader;
    mapHeader = GetMapHeaderFromConnection(connection);
    switch (connection->direction)
    {
    case CONNECTION_SOUTH:
    case CONNECTION_NORTH:
        return sub_8088A38(x - connection->offset, mapHeader->mapLayout->width);
    case CONNECTION_WEST:
    case CONNECTION_EAST:
        return sub_8088A38(y - connection->offset, mapHeader->mapLayout->height);
    }
    return FALSE;
}

struct MapConnection *GetConnectionAtCoords(s16 x, s16 y)
{
    int count;
    struct MapConnection *connection;
    int i;
    u8 direction;
    if (!gMapHeader.connections)
    {
        return NULL;
    }
    else
    {
        count = gMapHeader.connections->count;
        connection = gMapHeader.connections->connections;
        for (i = 0; i < count; i++, connection++)
        {
            direction = connection->direction;
            if ((direction == CONNECTION_DIVE || direction == CONNECTION_EMERGE)
             || (direction == CONNECTION_NORTH && y > 6)
             || (direction == CONNECTION_SOUTH && y < gMapHeader.mapLayout->height + 7)
             || (direction == CONNECTION_WEST && x > 6)
             || (direction == CONNECTION_EAST && x < gMapHeader.mapLayout->width + 7))
            {
                continue;
            }
            if (sub_8088A4C(connection, x - 7, y - 7) == TRUE)
            {
                return connection;
            }
        }
    }
    return NULL;
}

void SetCameraFocusCoords(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x - 7;
    gSaveBlock1Ptr->pos.y = y - 7;
}

void GetCameraFocusCoords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x + 7;
    *y = gSaveBlock1Ptr->pos.y + 7;
}

// Unused
static void SetCameraCoords(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x;
    gSaveBlock1Ptr->pos.y = y;
}

void GetCameraCoords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x;
    *y = gSaveBlock1Ptr->pos.y;
}

void MapGridSetMetatileImpassabilityAt(int x, int y, bool32 impassable)
{
    if (x >= 0 && x < gBackupMapLayout.width && y >= 0 && y < gBackupMapLayout.height)
    {
        if (impassable)
            gBackupMapLayout.map[x + gBackupMapLayout.width * y] |= METATILE_COLLISION_MASK;
        else
            gBackupMapLayout.map[x + gBackupMapLayout.width * y] &= ~METATILE_COLLISION_MASK;
    }
}

static bool8 SkipCopyingMetatileFromSavedMap(u16* mapMetatilePtr, u16 mapWidth, u8 yMode)
{
    if (yMode == 0xFF)
        return FALSE;

    if (yMode == 0)
        mapMetatilePtr -= mapWidth;
    else
        mapMetatilePtr += mapWidth;

    if (IsLargeBreakableDecoration(*mapMetatilePtr & METATILE_ID_MASK, yMode) == TRUE)
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

void nullsub_3(u16 a0, u16 a1)
{

}

void nullsub_90(void)
{

}

void LoadTilesetPalette(struct Tileset const *tileset, u16 destOffset, u16 size)
{
    u16 black = RGB_BLACK;

    if (tileset)
    {
        if (tileset->isSecondary == FALSE)
        {
            LoadPalette(&black, destOffset, 2);
            LoadPalette(((u16*)tileset->palettes) + 1, destOffset + 1, size - 2);
            nullsub_3(destOffset + 1, (size - 2) >> 1);
        }
        else if (tileset->isSecondary == TRUE)
        {
            LoadPalette(((u16*)tileset->palettes) + (NUM_PALS_IN_PRIMARY * 16), destOffset, size);
            nullsub_3(destOffset, size >> 1);
        }
        else
        {
            LoadCompressedPalette((u32*)tileset->palettes, destOffset, size);
            nullsub_3(destOffset, size >> 1);
        }
    }
}

void CopyPrimaryTilesetToVram(struct MapLayout const *mapLayout)
{
    CopyTilesetToVram(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY, 0);
}

void CopySecondaryTilesetToVram(struct MapLayout const *mapLayout)
{
    CopyTilesetToVram(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
}

void CopySecondaryTilesetToVramUsingHeap(struct MapLayout const *mapLayout)
{
    CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
}

static void LoadPrimaryTilesetPalette(struct MapLayout const *mapLayout)
{
    LoadTilesetPalette(mapLayout->primaryTileset, 0, NUM_PALS_IN_PRIMARY * 16 * 2);
}

void LoadSecondaryTilesetPalette(struct MapLayout const *mapLayout)
{
    LoadTilesetPalette(mapLayout->secondaryTileset, NUM_PALS_IN_PRIMARY * 16, (NUM_PALS_TOTAL - NUM_PALS_IN_PRIMARY) * 16 * 2);
}

void CopyMapTilesetsToVram(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
        CopyTilesetToVramUsingHeap(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY, 0);
        CopyTilesetToVramUsingHeap(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
    }
}

void LoadMapTilesetPalettes(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
        LoadPrimaryTilesetPalette(mapLayout);
        LoadSecondaryTilesetPalette(mapLayout);
    }
}
