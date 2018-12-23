#include "global.h"
#include "bg.h"
#include "fieldmap.h"
#include "fldeff_misc.h"
#include "fldeff_cut.h"
#include "fldeff_groundshake.h"
#include "frontier_util.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokenav.h"
#include "script.h"
#include "secret_base.h"
#include "tv.h"
#include "constants/rgb.h"

extern void sub_81AA078(u16*, u8);

struct ConnectionFlags
{
    u8 south:1;
    u8 north:1;
    u8 west:1;
    u8 east:1;
};

EWRAM_DATA static u16 gUnknown_02032318[0x2800] = {0};
EWRAM_DATA struct MapHeader gMapHeader = {0};
EWRAM_DATA struct Camera gCamera = {0};
EWRAM_DATA static struct ConnectionFlags gUnknown_02037340 = {0};
EWRAM_DATA static u32 sFiller_02037344 = 0; // without this, the next file won't align properly

struct BackupMapLayout gUnknown_03005DC0;

static const struct ConnectionFlags sDummyConnectionFlags = {0};

struct MapHeader const *const mapconnection_get_mapheader(struct MapConnection *connection)
{
    return Overworld_GetMapHeaderByGroupAndId(connection->mapGroup, connection->mapNum);
}

void not_trainer_hill_battle_pyramid(void)
{
    mapheader_copy_mapdata_with_padding(&gMapHeader);
    sub_80E8EE0(gMapHeader.events);
    mapheader_run_script_with_tag_x1();
}

void sub_8087D74(void)
{
    mapheader_copy_mapdata_with_padding(&gMapHeader);
    sub_80E9238(0);
    sub_80E8EE0(gMapHeader.events);
    mapdata_from_sav2();
    mapheader_run_script_with_tag_x1();
    UpdateTVScreensOnMap(gUnknown_03005DC0.width, gUnknown_03005DC0.height);
}

void battle_pyramid_map_load_related(u8 a0)
{
    CpuFastFill(0x03ff03ff, gUnknown_02032318, sizeof(gUnknown_02032318));
    sub_81AA078(gUnknown_02032318, a0);
}

void trainer_hill_map_load_related(void)
{
    CpuFastFill(0x03ff03ff, gUnknown_02032318, sizeof(gUnknown_02032318));
    sub_81D5FB4(gUnknown_02032318);
}

void mapheader_copy_mapdata_with_padding(struct MapHeader *mapHeader)
{
    struct MapLayout const *mapLayout;
    int width;
    int height;
    mapLayout = mapHeader->mapLayout;
    CpuFastFill16(0x03ff, gUnknown_02032318, sizeof(gUnknown_02032318));
    gUnknown_03005DC0.map = gUnknown_02032318;
    width = mapLayout->width + 15;
    gUnknown_03005DC0.width = width;
    height = mapLayout->height + 14;
    gUnknown_03005DC0.height = height;
    if (width * height <= 0x2800)
    {
        map_copy_with_padding(mapLayout->map, mapLayout->width, mapLayout->height);
        mapheader_copy_mapdata_of_adjacent_maps(mapHeader);
    }
}

void map_copy_with_padding(u16 *map, u16 width, u16 height)
{
    u16 *dest;
    int y;
    dest = gUnknown_03005DC0.map;
    dest += gUnknown_03005DC0.width * 7 + 7;
    for (y = 0; y < height; y++)
    {
        CpuCopy16(map, dest, width * 2);
        dest += width + 0xf;
        map += width;
    }
}

void mapheader_copy_mapdata_of_adjacent_maps(struct MapHeader *mapHeader)
{
    int count;
    struct MapConnection *connection;
    int i;

    if (mapHeader->connections)
    {
        count = mapHeader->connections->count;
        connection = mapHeader->connections->connections;

        gUnknown_02037340 = sDummyConnectionFlags;
        for (i = 0; i < count; i++, connection++)
        {
            struct MapHeader const *cMap = mapconnection_get_mapheader(connection);
            u32 offset = connection->offset;

            switch (connection->direction)
            {
            case CONNECTION_SOUTH:
                fillSouthConnection(mapHeader, cMap, offset);
                gUnknown_02037340.south = 1;
                break;
            case CONNECTION_NORTH:
                fillNorthConnection(mapHeader, cMap, offset);
                gUnknown_02037340.north = 1;
                break;
            case CONNECTION_WEST:
                fillWestConnection(mapHeader, cMap, offset);
                gUnknown_02037340.west = 1;
                break;
            case CONNECTION_EAST:
                fillEastConnection(mapHeader, cMap, offset);
                gUnknown_02037340.east = 1;
                break;
            }
        }
    }
}

void sub_8087F54(int x, int y, struct MapHeader const *mapHeader, int x2, int y2, int width, int height)
{
    int i;
    u16 *src;
    u16 *dest;
    int mapWidth;

    mapWidth = mapHeader->mapLayout->width;
    src = &mapHeader->mapLayout->map[mapWidth * y2 + x2];
    dest = &gUnknown_03005DC0.map[gUnknown_03005DC0.width * y + x];

    for (i = 0; i < height; i++)
    {
        CpuCopy16(src, dest, width * 2);
        dest += gUnknown_03005DC0.width;
        src += mapWidth;
    }
}

void fillSouthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
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
            if (x < gUnknown_03005DC0.width)
            {
                width = x;
            }
            else
            {
                width = gUnknown_03005DC0.width;
            }
            x = 0;
        }
        else
        {
            x2 = 0;
            if (x + cWidth < gUnknown_03005DC0.width)
            {
                width = cWidth;
            }
            else
            {
                width = gUnknown_03005DC0.width - x;
            }
        }

        sub_8087F54(
            x, y,
            connectedMapHeader,
            x2, /*y2*/ 0,
            width, /*height*/ 7);
    }
}

void fillNorthConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
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
            if (x < gUnknown_03005DC0.width)
            {
                width = x;
            }
            else
            {
                width = gUnknown_03005DC0.width;
            }
            x = 0;
        }
        else
        {
            x2 = 0;
            if (x + cWidth < gUnknown_03005DC0.width)
            {
                width = cWidth;
            }
            else
            {
                width = gUnknown_03005DC0.width - x;
            }
        }

        sub_8087F54(
            x, /*y*/ 0,
            connectedMapHeader,
            x2, y2,
            width, /*height*/ 7);

    }
}

void fillWestConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
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
            if (y + cHeight < gUnknown_03005DC0.height)
            {
                height = y + cHeight;
            }
            else
            {
                height = gUnknown_03005DC0.height;
            }
            y = 0;
        }
        else
        {
            y2 = 0;
            if (y + cHeight < gUnknown_03005DC0.height)
            {
                height = cHeight;
            }
            else
            {
                height = gUnknown_03005DC0.height - y;
            }
        }

        sub_8087F54(
            /*x*/ 0, y,
            connectedMapHeader,
            x2, y2,
            /*width*/ 7, height);
    }
}

void fillEastConnection(struct MapHeader const *mapHeader, struct MapHeader const *connectedMapHeader, s32 offset)
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
            if (y + cHeight < gUnknown_03005DC0.height)
            {
                height = y + cHeight;
            }
            else
            {
                height = gUnknown_03005DC0.height;
            }
            y = 0;
        }
        else
        {
            y2 = 0;
            if (y + cHeight < gUnknown_03005DC0.height)
            {
                height = cHeight;
            }
            else
            {
                height = gUnknown_03005DC0.height - y;
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

    if (x >= 0 && x < gUnknown_03005DC0.width
     && y >= 0 && y < gUnknown_03005DC0.height)
    {
        block = gUnknown_03005DC0.map[x + gUnknown_03005DC0.width * y];
    }
    else
    {
        border = gMapHeader.mapLayout->border;
        i = (x + 1) & 1;
        i += ((y + 1) & 1) * 2;
        block = gMapHeader.mapLayout->border[i];
        block |= 0xc00;
    }

    if (block == 0x3ff)
    {
        return 0;
    }

    return block >> 12;
}

u8 MapGridIsImpassableAt(int x, int y)
{
    u16 block;
    int i;
    u16 *border;

    if (x >= 0 && x < gUnknown_03005DC0.width
     && y >= 0 && y < gUnknown_03005DC0.height)
    {
        block = gUnknown_03005DC0.map[x + gUnknown_03005DC0.width * y];
    }
    else
    {
        border = gMapHeader.mapLayout->border;
        i = (x + 1) & 1;
        i += ((y + 1) & 1) * 2;
        block = gMapHeader.mapLayout->border[i];
        block |= 0xc00;
    }
    if (block == 0x3ff)
    {
        return 1;
    }
    return (block & 0xc00) >> 10;
}

u32 MapGridGetMetatileIdAt(int x, int y)
{
    u16 block;
    int i;
    int j;
    struct MapLayout const *mapLayout;
    u16 *border;
    u16 block2;

    if (x >= 0 && x < gUnknown_03005DC0.width
     && y >= 0 && y < gUnknown_03005DC0.height)
    {
        block = gUnknown_03005DC0.map[x + gUnknown_03005DC0.width * y];
    }
    else
    {
        mapLayout = gMapHeader.mapLayout;
        i = (x + 1) & 1;
        i += ((y + 1) & 1) * 2;
        block = mapLayout->border[i] | 0xc00;
    }
    if (block == 0x3ff)
    {
        border = gMapHeader.mapLayout->border;
        j = (x + 1) & 1;
        j += ((y + 1) & 1) * 2;
        block2 = gMapHeader.mapLayout->border[j];
        block2 |= 0xc00;
        return block2 & block;
    }
    return block & 0x3ff;
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
    return (GetBehaviorByMetatileId(metatile) & 0xf000) >> 12;
}

void MapGridSetMetatileIdAt(int x, int y, u16 metatile)
{
    int i;
    if (x >= 0 && x < gUnknown_03005DC0.width
     && y >= 0 && y < gUnknown_03005DC0.height)
    {
        i = x + y * gUnknown_03005DC0.width;
        gUnknown_03005DC0.map[i] = (gUnknown_03005DC0.map[i] & 0xf000) | (metatile & 0xfff);
    }
}

void MapGridSetMetatileEntryAt(int x, int y, u16 metatile)
{
    int i;
    if (x >= 0 && x < gUnknown_03005DC0.width
     && y >= 0 && y < gUnknown_03005DC0.height)
    {
        i = x + gUnknown_03005DC0.width * y;
        gUnknown_03005DC0.map[i] = metatile;
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
    width = gUnknown_03005DC0.width;
    x = gSaveBlock1Ptr->pos.x;
    y = gSaveBlock1Ptr->pos.y;
    for (i = y; i < y + 14; i++)
    {
        for (j = x; j < x + 15; j++)
        {
            *mapView++ = gUnknown_02032318[width * i + j];
        }
    }
}

int sub_8088438(void)
{
    u16 i;
    u32 r2;
    r2 = 0;
    for (i = 0; i < 0x200; i++)
    {
        r2 |= gSaveBlock1Ptr->mapView[i];
    }
    if (r2 == 0)
    {
        return 1;
    }
    return 0;
}

void sav2_mapdata_clear(void)
{
    CpuFill16(0, gSaveBlock1Ptr->mapView, sizeof(gSaveBlock1Ptr->mapView));
}

void mapdata_from_sav2(void)
{
    u8 a0;
    int i, j;
    int x, y;
    u16 *mapView;
    int width;
    mapView = gSaveBlock1Ptr->mapView;
    if (!sub_8088438())
    {
        width = gUnknown_03005DC0.width;
        x = gSaveBlock1Ptr->pos.x;
        y = gSaveBlock1Ptr->pos.y;
        for (i = y; i < y + 14; i++)
        {
            if (i == y && i != 0)
                a0 = 0;
            else if (i == y + 13 && i != gMapHeader.mapLayout->height - 1)
                a0 = 1;
            else
                a0 = -1;

            for (j = x; j < x + 15; j++)
            {
                if (!sub_8088BF0(&gUnknown_02032318[j + width * i], width, a0))
                    gUnknown_02032318[j + width * i] = *mapView;
                mapView++;
            }
        }
        for (j = x; j < x + 15; j++)
        {
            if (y != 0)
                sub_80D423C(j, y - 1);
            if (i < gMapHeader.mapLayout->height - 1)
                sub_80D42B8(j, y + 13);
        }
        sav2_mapdata_clear();
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
    width = gUnknown_03005DC0.width;
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
            dest = &gUnknown_02032318[x0 + desti + j];
            *dest = *src;
            i++;
            j++;
        }
    }
    sav2_mapdata_clear();
}

int GetMapBorderIdAt(int x, int y)
{
    struct MapLayout const *mapLayout;
    u16 block, block2;
    int i, j;
    if (x >= 0 && x < gUnknown_03005DC0.width
     && y >= 0 && y < gUnknown_03005DC0.height)
    {
        i = gUnknown_03005DC0.width;
        i *= y;
        block = gUnknown_03005DC0.map[x + i];
        if (block == 0x3ff)
        {
            goto fail;
        }
    }
    else
    {
        mapLayout = gMapHeader.mapLayout;
        j = (x + 1) & 1;
        j += ((y + 1) & 1) * 2;
        block2 = 0xc00 | mapLayout->border[j];
        if (block2 == 0x3ff)
        {
            goto fail;
        }
    }
    goto success;
fail:
    return -1;
success:

    if (x >= (gUnknown_03005DC0.width - 8))
    {
        if (!gUnknown_02037340.east)
        {
            return -1;
        }
        return CONNECTION_EAST;
    }
    else if (x < 7)
    {
        if (!gUnknown_02037340.west)
        {
            return -1;
        }
        return CONNECTION_WEST;
    }
    else if (y >= (gUnknown_03005DC0.height - 7))
    {
        if (!gUnknown_02037340.south)
        {
            return -1;
        }
        return CONNECTION_SOUTH;
    }
    else if (y < 7)
    {
        if (!gUnknown_02037340.north)
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
    mapHeader = mapconnection_get_mapheader(connection);
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
        sub_81BE72C();
        old_x = gSaveBlock1Ptr->pos.x;
        old_y = gSaveBlock1Ptr->pos.y;
        connection = sub_8088950(direction, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
        sub_80887F8(connection, direction, x, y);
        mliX_load_map(connection->mapGroup, connection->mapNum);
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
    struct MapConnection *connection;
    int i;
    count = gMapHeader.connections->count;
    connection = gMapHeader.connections->connections;
    for (i = 0; i < count; i++, connection++)
    {
        if (connection->direction == direction && sub_80889A8(direction, x, y, connection) == TRUE)
            return connection;
    }
    return NULL;
}

bool8 sub_80889A8(u8 direction, int x, int y, struct MapConnection *connection)
{
    struct MapHeader const *mapHeader;
    mapHeader = mapconnection_get_mapheader(connection);
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
    mapHeader = mapconnection_get_mapheader(connection);
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

struct MapConnection *sub_8088A8C(s16 x, s16 y)
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

void sub_8088B3C(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x - 7;
    gSaveBlock1Ptr->pos.y = y - 7;
}

void sav1_camera_get_focus_coords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x + 7;
    *y = gSaveBlock1Ptr->pos.y + 7;
}

void SetCameraCoords(u16 x, u16 y)
{
    gSaveBlock1Ptr->pos.x = x;
    gSaveBlock1Ptr->pos.y = y;
}

void GetCameraCoords(u16 *x, u16 *y)
{
    *x = gSaveBlock1Ptr->pos.x;
    *y = gSaveBlock1Ptr->pos.y;
}

void sub_8088B94(int x, int y, int a2)
{
    if (x >= 0 && x < gUnknown_03005DC0.width && y >= 0 && y < gUnknown_03005DC0.height)
    {
        if (a2 != 0)
            gUnknown_03005DC0.map[x + gUnknown_03005DC0.width * y] |= 0xC00;
        else
            gUnknown_03005DC0.map[x + gUnknown_03005DC0.width * y] &= 0xF3FF;
    }
}

bool8 sub_8088BF0(u16* a0, u16 a1, u8 a2)
{
    if (a2 == 0xFF)
        return FALSE;

    if (a2 == 0)
        a0 -= a1;
    else
        a0 += a1;

    if (sub_80FADE4(*a0 & 0x3FF, a2) == 1)
        return TRUE;
    return FALSE;
}

void copy_tileset_patterns_to_vram(struct Tileset const *tileset, u16 numTiles, u16 offset)
{
    if (tileset)
    {
        if (!tileset->isCompressed)
            LoadBgTiles(2, tileset->tiles, numTiles * 32, offset);
        else
            decompress_and_copy_tile_data_to_vram(2, tileset->tiles, numTiles * 32, offset, 0);
    }
}

void copy_tileset_patterns_to_vram2(struct Tileset const *tileset, u16 numTiles, u16 offset)
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

void apply_map_tileset_palette(struct Tileset const *tileset, u16 destOffset, u16 size)
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
            LoadCompressedPalette((u16*)tileset->palettes, destOffset, size);
            nullsub_3(destOffset, size >> 1);
        }
    }
}

void copy_map_tileset1_to_vram(struct MapLayout const *mapLayout)
{
    copy_tileset_patterns_to_vram(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY, 0);
}

void copy_map_tileset2_to_vram(struct MapLayout const *mapLayout)
{
    copy_tileset_patterns_to_vram(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
}

void copy_map_tileset2_to_vram_2(struct MapLayout const *mapLayout)
{
    copy_tileset_patterns_to_vram2(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
}

void apply_map_tileset1_palette(struct MapLayout const *mapLayout)
{
    apply_map_tileset_palette(mapLayout->primaryTileset, 0, NUM_PALS_IN_PRIMARY * 16 * 2);
}

void apply_map_tileset2_palette(struct MapLayout const *mapLayout)
{
    apply_map_tileset_palette(mapLayout->secondaryTileset, NUM_PALS_IN_PRIMARY * 16, (NUM_PALS_TOTAL - NUM_PALS_IN_PRIMARY) * 16 * 2);
}

void copy_map_tileset1_tileset2_to_vram(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
        copy_tileset_patterns_to_vram2(mapLayout->primaryTileset, NUM_TILES_IN_PRIMARY, 0);
        copy_tileset_patterns_to_vram2(mapLayout->secondaryTileset, NUM_TILES_TOTAL - NUM_TILES_IN_PRIMARY, NUM_TILES_IN_PRIMARY);
    }
}

void apply_map_tileset1_tileset2_palette(struct MapLayout const *mapLayout)
{
    if (mapLayout)
    {
        apply_map_tileset1_palette(mapLayout);
        apply_map_tileset2_palette(mapLayout);
    }
}
