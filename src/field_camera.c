#include "global.h"
#include "berry.h"
#include "bike.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "event_object_movement.h"
#include "gpu_regs.h"
#include "menu.h"
#include "overworld.h"
#include "rotating_gate.h"
#include "sprite.h"
#include "text.h"

EWRAM_DATA bool8 gUnusedBikeCameraAheadPanback = FALSE;

// Static type declarations
struct FieldCameraUnknownStruct
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    bool8 unk4;
};

// static functions
static void RedrawMapSliceNorth(struct FieldCameraUnknownStruct *a, const struct MapData *mapData);
static void RedrawMapSliceSouth(struct FieldCameraUnknownStruct *a, const struct MapData *mapData);
static void RedrawMapSliceEast(struct FieldCameraUnknownStruct *a, const struct MapData *mapData);
static void RedrawMapSliceWest(struct FieldCameraUnknownStruct *a, const struct MapData *mapData);
static s32 MapPosToBgTilemapOffset(struct FieldCameraUnknownStruct *a, s32 x, s32 y);
static void DrawWholeMapViewInternal(int x, int y, const struct MapData *mapData);
static void DrawMetatileAt(const struct MapData *mapData, u16, int, int);
static void DrawMetatile(s32 a, u16 *b, u16 c);
static void CameraPanningCB_PanAhead(void);

// IWRAM bss vars
static IWRAM_DATA struct FieldCameraUnknownStruct gUnknown_03000E20;
static IWRAM_DATA s16 gUnknown_03000E28;
static IWRAM_DATA s16 gUnknown_03000E2A;
static IWRAM_DATA u8 gUnknown_03000E2C;
static IWRAM_DATA void (*gUnknown_03000E30)(void);

struct CameraObject gUnknown_03005DD0;
u16 gUnknown_03005DE8;
u16 gUnknown_03005DEC;

// text
static void move_tilemap_camera_to_upper_left_corner_(struct FieldCameraUnknownStruct *a)
{
    a->unk2 = 0;
    a->unk3 = 0;
    a->unk0 = 0;
    a->unk1 = 0;
    a->unk4 = TRUE;
}

static void tilemap_move_something(struct FieldCameraUnknownStruct *a, u32 b, u32 c)
{
    a->unk2 += b;
    a->unk2 %= 32;
    a->unk3 += c;
    a->unk3 %= 32;
}

static void coords8_add(struct FieldCameraUnknownStruct *a, u32 b, u32 c)
{
    a->unk0 += b;
    a->unk1 += c;
}

void move_tilemap_camera_to_upper_left_corner(void)
{
    move_tilemap_camera_to_upper_left_corner_(&gUnknown_03000E20);
}

void FieldUpdateBgTilemapScroll(void)
{
    u32 r4, r5;
    r5 = gUnknown_03000E20.unk0 + gUnknown_03000E28;
    r4 = gUnknown_03000E2A + gUnknown_03000E20.unk1 + 8;

    SetGpuReg(REG_OFFSET_BG1HOFS, r5);
    SetGpuReg(REG_OFFSET_BG1VOFS, r4);
    SetGpuReg(REG_OFFSET_BG2HOFS, r5);
    SetGpuReg(REG_OFFSET_BG2VOFS, r4);
    SetGpuReg(REG_OFFSET_BG3HOFS, r5);
    SetGpuReg(REG_OFFSET_BG3VOFS, r4);
}

void sub_8089C08(s16 *a, s16 *b)
{
    *a = gUnknown_03000E20.unk0 + gUnknown_03000E28;
    *b = gUnknown_03000E20.unk1 + gUnknown_03000E2A + 8;
}

void DrawWholeMapView(void)
{
    DrawWholeMapViewInternal(gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y, gMapHeader.mapData);
    gUnknown_03000E20.unk4 = TRUE;
}

static void DrawWholeMapViewInternal(int x, int y, const struct MapData *mapData)
{
    u8 i;
    u8 j;
    u32 r6;
    u8 temp;

    for (i = 0; i < 32; i += 2)
    {
        temp = gUnknown_03000E20.unk3 + i;
        if (temp >= 32)
            temp -= 32;
        r6 = temp * 32;
        for (j = 0; j < 32; j += 2)
        {
            temp = gUnknown_03000E20.unk2 + j;
            if (temp >= 32)
                temp -= 32;
            DrawMetatileAt(mapData, r6 + temp, x + j / 2, y + i / 2);
        }
    }
}

static void RedrawMapSlicesForCameraUpdate(struct FieldCameraUnknownStruct *a, int x, int y)
{
    const struct MapData *mapData = gMapHeader.mapData;

    if (x > 0)
        RedrawMapSliceWest(a, mapData);
    if (x < 0)
        RedrawMapSliceEast(a, mapData);
    if (y > 0)
        RedrawMapSliceNorth(a, mapData);
    if (y < 0)
        RedrawMapSliceSouth(a, mapData);
    a->unk4 = TRUE;
}

static void RedrawMapSliceNorth(struct FieldCameraUnknownStruct *a, const struct MapData *mapData)
{
    u8 i;
    u8 temp;
    u32 r7;

    temp = a->unk3 + 28;
    if (temp >= 32)
        temp -= 32;
    r7 = temp * 32;
    for (i = 0; i < 32; i += 2)
    {
        temp = a->unk2 + i;
        if (temp >= 32)
            temp -= 32;
        DrawMetatileAt(mapData, r7 + temp, gSaveBlock1Ptr->pos.x + i / 2, gSaveBlock1Ptr->pos.y + 14);
    }
}

static void RedrawMapSliceSouth(struct FieldCameraUnknownStruct *a, const struct MapData *mapData)
{
    u8 i;
    u8 temp;
    u32 r7 = a->unk3 * 32;

    for (i = 0; i < 32; i += 2)
    {
        temp = a->unk2 + i;
        if (temp >= 32)
            temp -= 32;
        DrawMetatileAt(mapData, r7 + temp, gSaveBlock1Ptr->pos.x + i / 2, gSaveBlock1Ptr->pos.y);
    }
}

static void RedrawMapSliceEast(struct FieldCameraUnknownStruct *a, const struct MapData *mapData)
{
    u8 i;
    u8 temp;
    u32 r6 = a->unk2;

    for (i = 0; i < 32; i += 2)
    {
        temp = a->unk3 + i;
        if (temp >= 32)
            temp -= 32;
        DrawMetatileAt(mapData, temp * 32 + r6, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y + i / 2);
    }
}

static void RedrawMapSliceWest(struct FieldCameraUnknownStruct *a, const struct MapData *mapData)
{
    u8 i;
    u8 temp;
    u8 r5 = a->unk2 + 28;

    if (r5 >= 32)
        r5 -= 32;
    for (i = 0; i < 32; i += 2)
    {
        temp = a->unk3 + i;
        if (temp >= 32)
            temp -= 32;
        DrawMetatileAt(mapData, temp * 32 + r5, gSaveBlock1Ptr->pos.x + 14, gSaveBlock1Ptr->pos.y + i / 2);
    }
}

void CurrentMapDrawMetatileAt(int a, int b)
{
    int offset = MapPosToBgTilemapOffset(&gUnknown_03000E20, a, b);

    if (offset >= 0)
    {
        DrawMetatileAt(gMapHeader.mapData, offset, a, b);
        gUnknown_03000E20.unk4 = TRUE;
    }
}

void DrawDoorMetatileAt(int x, int y, u16 *arr)
{
    int offset = MapPosToBgTilemapOffset(&gUnknown_03000E20, x, y);

    if (offset >= 0)
    {
        DrawMetatile(1, arr, offset);
        gUnknown_03000E20.unk4 = TRUE;
    }
}

static void DrawMetatileAt(const struct MapData *mapData, u16 b, int c, int d)
{
    u16 metatileId = MapGridGetMetatileIdAt(c, d);
    u16 *metatiles;

    if (metatileId > 1024)
        metatileId = 0;
    if (metatileId < 512)
        metatiles = mapData->primaryTileset->metatiles;
    else
    {
        metatiles = mapData->secondaryTileset->metatiles;
        metatileId -= 512;
    }
    DrawMetatile(MapGridGetMetatileLayerTypeAt(c, d), metatiles + metatileId * 8, b);
}

static void DrawMetatile(s32 a, u16 *b, u16 c)
{
    switch (a)
    {
    case 2:
        gBGTilemapBuffers3[c] = b[0];
        gBGTilemapBuffers3[c + 1] = b[1];
        gBGTilemapBuffers3[c + 0x20] = b[2];
        gBGTilemapBuffers3[c + 0x21] = b[3];

        gBGTilemapBuffers1[c] = 0;
        gBGTilemapBuffers1[c + 1] = 0;
        gBGTilemapBuffers1[c + 0x20] = 0;
        gBGTilemapBuffers1[c + 0x21] = 0;

        gBGTilemapBuffers2[c] = b[4];
        gBGTilemapBuffers2[c + 1] = b[5];
        gBGTilemapBuffers2[c + 0x20] = b[6];
        gBGTilemapBuffers2[c + 0x21] = b[7];
        break;
    case 1:
        gBGTilemapBuffers3[c] = b[0];
        gBGTilemapBuffers3[c + 1] = b[1];
        gBGTilemapBuffers3[c + 0x20] = b[2];
        gBGTilemapBuffers3[c + 0x21] = b[3];

        gBGTilemapBuffers1[c] = b[4];
        gBGTilemapBuffers1[c + 1] = b[5];
        gBGTilemapBuffers1[c + 0x20] = b[6];
        gBGTilemapBuffers1[c + 0x21] = b[7];

        gBGTilemapBuffers2[c] = 0;
        gBGTilemapBuffers2[c + 1] = 0;
        gBGTilemapBuffers2[c + 0x20] = 0;
        gBGTilemapBuffers2[c + 0x21] = 0;
        break;
    case 0:
        gBGTilemapBuffers3[c] = 0x3014;
        gBGTilemapBuffers3[c + 1] = 0x3014;
        gBGTilemapBuffers3[c + 0x20] = 0x3014;
        gBGTilemapBuffers3[c + 0x21] = 0x3014;

        gBGTilemapBuffers1[c] = b[0];
        gBGTilemapBuffers1[c + 1] = b[1];
        gBGTilemapBuffers1[c + 0x20] = b[2];
        gBGTilemapBuffers1[c + 0x21] = b[3];

        gBGTilemapBuffers2[c] = b[4];
        gBGTilemapBuffers2[c + 1] = b[5];
        gBGTilemapBuffers2[c + 0x20] = b[6];
        gBGTilemapBuffers2[c + 0x21] = b[7];
        break;
    }
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
}

static s32 MapPosToBgTilemapOffset(struct FieldCameraUnknownStruct *a, s32 x, s32 y)
{
    x -= gSaveBlock1Ptr->pos.x;
    x *= 2;
    if (x >= 32 || x < 0)
        return -1;
    x = x + a->unk2;
    if (x >= 32)
        x -= 32;

    y = (y - gSaveBlock1Ptr->pos.y) * 2;
    if (y >= 32 || y < 0)
        return -1;
    y = y + a->unk3;
    if (y >= 32)
        y -= 32;

    return y * 32 + x;
}

static void CameraUpdateCallback(struct CameraObject *a)
{
    if (a->spriteId != 0)
    {
        a->unk8 = gSprites[a->spriteId].data[2];
        a->unkC = gSprites[a->spriteId].data[3];
    }
}

void ResetCameraUpdateInfo(void)
{
    gUnknown_03005DD0.unk8 = 0;
    gUnknown_03005DD0.unkC = 0;
    gUnknown_03005DD0.x = 0;
    gUnknown_03005DD0.y = 0;
    gUnknown_03005DD0.spriteId = 0;
    gUnknown_03005DD0.callback = NULL;
}

u32 InitCameraUpdateCallback(u8 a)
{
    if (gUnknown_03005DD0.spriteId != 0)
        DestroySprite(&gSprites[gUnknown_03005DD0.spriteId]);
    gUnknown_03005DD0.spriteId = AddCameraObject(a);
    gUnknown_03005DD0.callback = CameraUpdateCallback;
    return 0;
}

void CameraUpdate(void)
{
    int deltaX;
    int deltaY;
    int r0;
    int r1;
    int r7;
    int r8;

    if (gUnknown_03005DD0.callback != NULL)
        gUnknown_03005DD0.callback(&gUnknown_03005DD0);
    r7 = gUnknown_03005DD0.unk8;
    r8 = gUnknown_03005DD0.unkC;
    deltaX = 0;
    deltaY = 0;
    r1 = gUnknown_03005DD0.x;
    r0 = gUnknown_03005DD0.y;


    if (r1 == 0 && r7 != 0)
    {
        if (r7 > 0)
            deltaX = 1;
        else
            deltaX = -1;
    }
    if (r0 == 0 && r8 != 0)
    {
        if (r8 > 0)
            deltaY = 1;
        else
            deltaY = -1;
    }
    if (r1 != 0 && r1 == -r7)
    {
        if (r7 > 0)
            deltaX = 1;
        else
            deltaX = -1;
    }
    if (r0 != 0 && r0 == -r8)
    {
        if (r8 > 0)
            deltaX = 1;
        else
            deltaX = -1;
    }

    gUnknown_03005DD0.x += r7;
    gUnknown_03005DD0.x = gUnknown_03005DD0.x - 16 * (gUnknown_03005DD0.x / 16);
    gUnknown_03005DD0.y += r8;
    gUnknown_03005DD0.y = gUnknown_03005DD0.y - 16 * (gUnknown_03005DD0.y / 16);

    if (deltaX != 0 || deltaY != 0)
    {
        CameraMove(deltaX, deltaY);
        UpdateFieldObjectsForCameraUpdate(deltaX, deltaY);
        RotatingGatePuzzleCameraUpdate(deltaX, deltaY);
        ResetBerryTreeSparkleFlags();
        tilemap_move_something(&gUnknown_03000E20, deltaX * 2, deltaY * 2);
        RedrawMapSlicesForCameraUpdate(&gUnknown_03000E20, deltaX * 2, deltaY * 2);
    }

    coords8_add(&gUnknown_03000E20, r7, r8);
    gUnknown_03005DEC -= r7;
    gUnknown_03005DE8 -= r8;
}

void camera_move_and_redraw(int a, int b) //unused
{
    CameraMove(a, b);
    UpdateFieldObjectsForCameraUpdate(a, b);
    DrawWholeMapView();
    gUnknown_03005DEC -= a * 16;
    gUnknown_03005DE8 -= b * 16;
}

void SetCameraPanningCallback(void (*a)(void))
{
    gUnknown_03000E30 = a;
}

void SetCameraPanning(s16 a, s16 b)
{
    gUnknown_03000E28 = a;
    gUnknown_03000E2A = b + 32;
}

void InstallCameraPanAheadCallback(void)
{
    gUnknown_03000E30 = CameraPanningCB_PanAhead;
    gUnknown_03000E2C = 0;
    gUnknown_03000E28 = 0;
    gUnknown_03000E2A = 32;
}

void UpdateCameraPanning(void)
{
    if (gUnknown_03000E30 != NULL)
        gUnknown_03000E30();
    //Update sprite offset of overworld objects
    gSpriteCoordOffsetX = gUnknown_03005DEC - gUnknown_03000E28;
    gSpriteCoordOffsetY = gUnknown_03005DE8 - gUnknown_03000E2A - 8;
}

static void CameraPanningCB_PanAhead(void)
{
    u8 var;

    if (gUnusedBikeCameraAheadPanback == FALSE)
    {
        InstallCameraPanAheadCallback();
    }
    else
    {
        // this code is never reached.
        if (gPlayerAvatar.tileTransitionState == T_TILE_TRANSITION)
        {
            gUnknown_03000E2C ^= 1;
            if (gUnknown_03000E2C == 0)
                return;
        }
        else
        {
            gUnknown_03000E2C = 0;
        }

        var = player_get_direction_upper_nybble();
        if (var == 2)
        {
            if (gUnknown_03000E2A > -8)
                gUnknown_03000E2A -= 2;
        }
        else if (var == 1)
        {
            if (gUnknown_03000E2A < 72)
                gUnknown_03000E2A += 2;
        }
        else if (gUnknown_03000E2A < 32)
        {
            gUnknown_03000E2A += 2;
        }
        else if (gUnknown_03000E2A > 32)
        {
            gUnknown_03000E2A -= 2;
        }
    }
}

