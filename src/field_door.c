#include "global.h"
#include "event_data.h"
#include "field_door.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "task.h"
#include "constants/flags.h"
#include "constants/maps.h"
#include "constants/songs.h"

static bool8 ShouldUseMultiCorridorDoor(void);

const u8 DoorAnimTiles_04[][0x100] =
{
    INCBIN_U8("graphics/door_anims/04/0.4bpp"),
    INCBIN_U8("graphics/door_anims/04/1.4bpp"),
    INCBIN_U8("graphics/door_anims/04/2.4bpp"),
};

// TODO: Make these blank palette includes?
asm(".space 32");

const u8 DoorAnimTiles_05[][0x100] =
{
    INCBIN_U8("graphics/door_anims/05/0.4bpp"),
    INCBIN_U8("graphics/door_anims/05/1.4bpp"),
    INCBIN_U8("graphics/door_anims/05/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_08[][0x100] =
{
    INCBIN_U8("graphics/door_anims/08/0.4bpp"),
    INCBIN_U8("graphics/door_anims/08/1.4bpp"),
    INCBIN_U8("graphics/door_anims/08/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_15[][0x100] =
{
    INCBIN_U8("graphics/door_anims/15/0.4bpp"),
    INCBIN_U8("graphics/door_anims/15/1.4bpp"),
    INCBIN_U8("graphics/door_anims/15/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_16[][0x100] =
{
    INCBIN_U8("graphics/door_anims/16/0.4bpp"),
    INCBIN_U8("graphics/door_anims/16/1.4bpp"),
    INCBIN_U8("graphics/door_anims/16/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_00[][0x100] =
{
    INCBIN_U8("graphics/door_anims/00/0.4bpp"),
    INCBIN_U8("graphics/door_anims/00/1.4bpp"),
    INCBIN_U8("graphics/door_anims/00/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_01[][0x100] =
{
    INCBIN_U8("graphics/door_anims/01/0.4bpp"),
    INCBIN_U8("graphics/door_anims/01/1.4bpp"),
    INCBIN_U8("graphics/door_anims/01/2.4bpp"),
};

const u8 DoorAnimTiles_02[][0x100] =
{
    INCBIN_U8("graphics/door_anims/02/0.4bpp"),
    INCBIN_U8("graphics/door_anims/02/1.4bpp"),
    INCBIN_U8("graphics/door_anims/02/2.4bpp"),
};

const u8 DoorAnimTiles_03[][0x100] =
{
    INCBIN_U8("graphics/door_anims/03/0.4bpp"),
    INCBIN_U8("graphics/door_anims/03/1.4bpp"),
    INCBIN_U8("graphics/door_anims/03/2.4bpp"),
};

const u8 DoorAnimTiles_06[][0x100] =
{
    INCBIN_U8("graphics/door_anims/06/0.4bpp"),
    INCBIN_U8("graphics/door_anims/06/1.4bpp"),
    INCBIN_U8("graphics/door_anims/06/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_07[][0x100] =
{
    INCBIN_U8("graphics/door_anims/07/0.4bpp"),
    INCBIN_U8("graphics/door_anims/07/1.4bpp"),
    INCBIN_U8("graphics/door_anims/07/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_09[][0x100] =
{
    INCBIN_U8("graphics/door_anims/09/0.4bpp"),
    INCBIN_U8("graphics/door_anims/09/1.4bpp"),
    INCBIN_U8("graphics/door_anims/09/2.4bpp"),
};

asm(".space 0x5900");

const u8 DoorAnimTiles_UnusedTops[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_848EDEC/0_top.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/1_top.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/2_top.4bpp"),
};

asm(".space 0x140");

const u8 DoorAnimTiles_UnusedBottoms[][0x40] =
{
    INCBIN_U8("graphics/door_anims/unused_848EDEC/0_bottom.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/1_bottom.4bpp"),
    INCBIN_U8("graphics/door_anims/unused_848EDEC/2_bottom.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_10[][0x100] =
{
    INCBIN_U8("graphics/door_anims/10/0.4bpp"),
    INCBIN_U8("graphics/door_anims/10/1.4bpp"),
    INCBIN_U8("graphics/door_anims/10/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_11[][0x100] =
{
    INCBIN_U8("graphics/door_anims/11/0.4bpp"),
    INCBIN_U8("graphics/door_anims/11/1.4bpp"),
    INCBIN_U8("graphics/door_anims/11/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_12[][0x100] =
{
    INCBIN_U8("graphics/door_anims/12/0.4bpp"),
    INCBIN_U8("graphics/door_anims/12/1.4bpp"),
    INCBIN_U8("graphics/door_anims/12/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_13[][0x100] =
{
    INCBIN_U8("graphics/door_anims/13/0.4bpp"),
    INCBIN_U8("graphics/door_anims/13/1.4bpp"),
    INCBIN_U8("graphics/door_anims/13/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_14[][0x100] =
{
    INCBIN_U8("graphics/door_anims/14/0.4bpp"),
    INCBIN_U8("graphics/door_anims/14/1.4bpp"),
    INCBIN_U8("graphics/door_anims/14/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_17[][0x100] =
{
    INCBIN_U8("graphics/door_anims/17/0.4bpp"),
    INCBIN_U8("graphics/door_anims/17/1.4bpp"),
    INCBIN_U8("graphics/door_anims/17/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_18[][0x100] =
{
    INCBIN_U8("graphics/door_anims/18/0.4bpp"),
    INCBIN_U8("graphics/door_anims/18/1.4bpp"),
    INCBIN_U8("graphics/door_anims/18/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_19[][0x100] =
{
    INCBIN_U8("graphics/door_anims/19/0.4bpp"),
    INCBIN_U8("graphics/door_anims/19/1.4bpp"),
    INCBIN_U8("graphics/door_anims/19/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_20[][0x100] =
{
    INCBIN_U8("graphics/door_anims/20/0.4bpp"),
    INCBIN_U8("graphics/door_anims/20/1.4bpp"),
    INCBIN_U8("graphics/door_anims/20/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_21[][0x100] =
{
    INCBIN_U8("graphics/door_anims/21/0.4bpp"),
    INCBIN_U8("graphics/door_anims/21/1.4bpp"),
    INCBIN_U8("graphics/door_anims/21/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_22[][0x100] =
{
    INCBIN_U8("graphics/door_anims/22/0.4bpp"),
    INCBIN_U8("graphics/door_anims/22/1.4bpp"),
    INCBIN_U8("graphics/door_anims/22/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_23[][0x100] =
{
    INCBIN_U8("graphics/door_anims/23/0.4bpp"),
    INCBIN_U8("graphics/door_anims/23/1.4bpp"),
    INCBIN_U8("graphics/door_anims/23/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_24[][0x100] =
{
    INCBIN_U8("graphics/door_anims/24/0.4bpp"),
    INCBIN_U8("graphics/door_anims/24/1.4bpp"),
    INCBIN_U8("graphics/door_anims/24/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_25[][0x100] =
{
    INCBIN_U8("graphics/door_anims/25/0.4bpp"),
    INCBIN_U8("graphics/door_anims/25/1.4bpp"),
    INCBIN_U8("graphics/door_anims/25/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_26[][0x100] =
{
    INCBIN_U8("graphics/door_anims/26/0.4bpp"),
    INCBIN_U8("graphics/door_anims/26/1.4bpp"),
    INCBIN_U8("graphics/door_anims/26/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_27[][0x100] =
{
    INCBIN_U8("graphics/door_anims/27/0.4bpp"),
    INCBIN_U8("graphics/door_anims/27/1.4bpp"),
    INCBIN_U8("graphics/door_anims/27/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_28[][0x100] =
{
    INCBIN_U8("graphics/door_anims/28/0.4bpp"),
    INCBIN_U8("graphics/door_anims/28/1.4bpp"),
    INCBIN_U8("graphics/door_anims/28/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_29[][0x100] =
{
    INCBIN_U8("graphics/door_anims/29/0.4bpp"),
    INCBIN_U8("graphics/door_anims/29/1.4bpp"),
    INCBIN_U8("graphics/door_anims/29/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_30[][0x100] =
{
    INCBIN_U8("graphics/door_anims/30/0.4bpp"),
    INCBIN_U8("graphics/door_anims/30/1.4bpp"),
    INCBIN_U8("graphics/door_anims/30/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_31[][0x100] =
{
    INCBIN_U8("graphics/door_anims/31/0.4bpp"),
    INCBIN_U8("graphics/door_anims/31/1.4bpp"),
    INCBIN_U8("graphics/door_anims/31/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_32[][0x100] =
{
    INCBIN_U8("graphics/door_anims/32/0.4bpp"),
    INCBIN_U8("graphics/door_anims/32/1.4bpp"),
    INCBIN_U8("graphics/door_anims/32/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_33[][0x100] =
{
    INCBIN_U8("graphics/door_anims/33/0.4bpp"),
    INCBIN_U8("graphics/door_anims/33/1.4bpp"),
    INCBIN_U8("graphics/door_anims/33/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_34[][0x100] =
{
    INCBIN_U8("graphics/door_anims/34/0.4bpp"),
    INCBIN_U8("graphics/door_anims/34/1.4bpp"),
    INCBIN_U8("graphics/door_anims/34/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_35[][0x100] =
{
    INCBIN_U8("graphics/door_anims/35/0.4bpp"),
    INCBIN_U8("graphics/door_anims/35/1.4bpp"),
    INCBIN_U8("graphics/door_anims/35/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_36[][0x100] =
{
    INCBIN_U8("graphics/door_anims/36/0.4bpp"),
    INCBIN_U8("graphics/door_anims/36/1.4bpp"),
    INCBIN_U8("graphics/door_anims/36/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_37[][0x100] =
{
    INCBIN_U8("graphics/door_anims/37/0.4bpp"),
    INCBIN_U8("graphics/door_anims/37/1.4bpp"),
    INCBIN_U8("graphics/door_anims/37/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_38[][0x100] =
{
    INCBIN_U8("graphics/door_anims/38/0.4bpp"),
    INCBIN_U8("graphics/door_anims/38/1.4bpp"),
    INCBIN_U8("graphics/door_anims/38/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_39[][0x100] =
{
    INCBIN_U8("graphics/door_anims/39/0.4bpp"),
    INCBIN_U8("graphics/door_anims/39/1.4bpp"),
    INCBIN_U8("graphics/door_anims/39/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_40[][0x100] =
{
    INCBIN_U8("graphics/door_anims/40/0.4bpp"),
    INCBIN_U8("graphics/door_anims/40/1.4bpp"),
    INCBIN_U8("graphics/door_anims/40/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_41[][0x100] =
{
    INCBIN_U8("graphics/door_anims/41/0.4bpp"),
    INCBIN_U8("graphics/door_anims/41/1.4bpp"),
    INCBIN_U8("graphics/door_anims/41/2.4bpp"),
};

const u8 DoorAnimTiles_42[][0x100] =
{
    INCBIN_U8("graphics/door_anims/42/0.4bpp"),
    INCBIN_U8("graphics/door_anims/42/1.4bpp"),
    INCBIN_U8("graphics/door_anims/42/2.4bpp"),
    INCBIN_U8("graphics/door_anims/42/3.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_43[][0x100] =
{
    INCBIN_U8("graphics/door_anims/43/0.4bpp"),
    INCBIN_U8("graphics/door_anims/43/1.4bpp"),
    INCBIN_U8("graphics/door_anims/43/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_44[][0x100] =
{
    INCBIN_U8("graphics/door_anims/44/0_left.4bpp"),
    INCBIN_U8("graphics/door_anims/44/0_right.4bpp"),
    INCBIN_U8("graphics/door_anims/44/1_left.4bpp"),
    INCBIN_U8("graphics/door_anims/44/1_right.4bpp"),
    INCBIN_U8("graphics/door_anims/44/2_left.4bpp"),
    INCBIN_U8("graphics/door_anims/44/2_right.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_45[][0x100] =
{
    INCBIN_U8("graphics/door_anims/45/0.4bpp"),
    INCBIN_U8("graphics/door_anims/45/1.4bpp"),
    INCBIN_U8("graphics/door_anims/45/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_46[][0x100] =
{
    INCBIN_U8("graphics/door_anims/46/0.4bpp"),
    INCBIN_U8("graphics/door_anims/46/1.4bpp"),
    INCBIN_U8("graphics/door_anims/46/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_47[][0x100] =
{
    INCBIN_U8("graphics/door_anims/47/0.4bpp"),
    INCBIN_U8("graphics/door_anims/47/1.4bpp"),
    INCBIN_U8("graphics/door_anims/47/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_48[][0x100] =
{
    INCBIN_U8("graphics/door_anims/48/0.4bpp"),
    INCBIN_U8("graphics/door_anims/48/1.4bpp"),
    INCBIN_U8("graphics/door_anims/48/2.4bpp"),
    INCBIN_U8("graphics/door_anims/48/3.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_49[][0x100] =
{
    INCBIN_U8("graphics/door_anims/49/0.4bpp"),
    INCBIN_U8("graphics/door_anims/49/1.4bpp"),
    INCBIN_U8("graphics/door_anims/49/2.4bpp"),
};

asm(".space 32");

const u8 DoorAnimTiles_50[][0x100] =
{
    INCBIN_U8("graphics/door_anims/50/0.4bpp"),
    INCBIN_U8("graphics/door_anims/50/1.4bpp"),
    INCBIN_U8("graphics/door_anims/50/2.4bpp"),
};

asm(".space 32");

static const struct DoorAnimFrame gDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x100},
    {4, 0x200},
    {0, 0},
};

static const struct DoorAnimFrame gDoorCloseAnimFrames[] =
{
    {4, 0x200},
    {4, 0x100},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame gBigDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x200},
    {4, 0x400},
    {0, 0},
};

static const struct DoorAnimFrame gBigDoorCloseAnimFrames[] =
{
    {4, 0x400},
    {4, 0x200},
    {4, 0},
    {4, -1},
    {0, 0},
};

const u8 DoorAnimPalettes_8496FDC[] = {1, 1, 1, 1, 1, 1, 1, 1}; // door 00
const u8 DoorAnimPalettes_8496FE4[] = {1, 1, 1, 1, 1, 1, 1, 1}; // door 01
const u8 DoorAnimPalettes_8496FEC[] = {5, 5, 5, 5, 5, 5, 5, 5}; // door 02
const u8 DoorAnimPalettes_8496FF4[] = {0, 0, 1, 1, 1, 1, 1, 1}; // door 03
const u8 DoorAnimPalettes_8496FFC[] = {10, 10, 6, 6, 6, 6, 6, 6}; // door 04
const u8 DoorAnimPalettes_8497004[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 05
const u8 DoorAnimPalettes_849700C[] = {11, 11, 11, 11, 11, 11, 11, 11}; // door 06
const u8 DoorAnimPalettes_8497014[] = {10, 10, 10, 10, 10, 10, 10, 10}; // door 07
const u8 DoorAnimPalettes_849701C[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 08
const u8 DoorAnimPalettes_8497024[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 09
const u8 DoorAnimPalettes_849702C[] = {10, 10, 9, 9, 9, 9, 9, 9}; // door 10
const u8 DoorAnimPalettes_8497034[] = {9, 9, 1, 1, 1, 1, 1, 1}; // door 11
const u8 DoorAnimPalettes_849703C[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 12
const u8 DoorAnimPalettes_8497044[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 13
const u8 DoorAnimPalettes_849704C[] = {6, 6, 6, 6, 6, 6, 6, 6}; // door 14
const u8 DoorAnimPalettes_8497054[] = {6, 6, 6, 6, 6, 6, 6, 6}; // door 15
const u8 DoorAnimPalettes_849705C[] = {0, 0, 5, 5, 5, 5, 5, 5}; // door 16
const u8 DoorAnimPalettes_8497064[] = {6, 6, 1, 1, 1, 1, 1, 1}; // door 17
const u8 DoorAnimPalettes_849706C[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 18
const u8 DoorAnimPalettes_8497074[] = {6, 6, 5, 5, 5, 5, 5, 5}; // door 19
const u8 DoorAnimPalettes_849707C[] = {5, 5, 5, 5, 5, 5, 5, 5}; // door 20
const u8 DoorAnimPalettes_8497084[] = {1, 1, 1, 1, 1, 1, 1, 1}; // door 21
const u8 DoorAnimPalettes_849708C[] = {6, 6, 6, 6, 6, 6, 6, 6}; // door 22
const u8 DoorAnimPalettes_8497094[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 23
const u8 DoorAnimPalettes_849709C[] = {5, 5, 5, 5, 5, 5, 5, 5}; // door 24
const u8 DoorAnimPalettes_84970A4[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 25
const u8 DoorAnimPalettes_84970AC[] = {8, 8, 8, 8, 8, 8, 8, 8}; // door 26
const u8 DoorAnimPalettes_84970B4[] = {6, 6, 6, 6, 6, 6, 6, 6}; // door 27
const u8 DoorAnimPalettes_84970BC[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 28
const u8 DoorAnimPalettes_84970C4[] = {11, 11, 7, 7, 7, 7, 7, 7}; // door 29
const u8 DoorAnimPalettes_84970CC[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 30
const u8 DoorAnimPalettes_84970D4[] = {6, 6, 7, 7, 7, 7, 7, 7}; // door 31
const u8 DoorAnimPalettes_84970DC[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 32
const u8 DoorAnimPalettes_84970E4[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 33
const u8 DoorAnimPalettes_84970EC[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 34
const u8 DoorAnimPalettes_84970F4[] = {1, 1, 1, 1, 1, 1, 1, 1}; // door 35
const u8 DoorAnimPalettes_84970FC[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 36
const u8 DoorAnimPalettes_8497104[] = {0, 0, 0, 0, 0, 0, 0, 0}; // door 37
const u8 DoorAnimPalettes_849710C[] = {5, 5, 5, 5, 5, 5, 5, 5}; // door 38
const u8 DoorAnimPalettes_8497114[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 39
const u8 DoorAnimPalettes_849711C[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 40
const u8 DoorAnimPalettes_8497124[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 41
const u8 DoorAnimPalettes_849712C[] = {1, 1, 1, 1, 1, 1, 1, 1}; // doors 42, 43, and 44
const u8 DoorAnimPalettes_8497134[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 45
const u8 DoorAnimPalettes_849713C[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 46
const u8 DoorAnimPalettes_8497144[] = {1, 1, 1, 1, 1, 1, 1, 1}; // unused 
const u8 DoorAnimPalettes_849714C[] = {1, 1, 1, 1, 1, 1, 1, 1}; // doors 47 and 48
const u8 DoorAnimPalettes_8497154[] = {9, 9, 7, 7, 7, 7, 7, 7}; // door 49
const u8 DoorAnimPalettes_849715C[] = {9, 9, 9, 9, 9, 9, 9, 9}; // door 50
const u8 DoorAnimPalettes_8497164[] = {7, 7, 7, 7, 7, 7, 7, 7}; // door 51
const u8 DoorAnimPalettes_849716C[] = {9, 9, 7, 7, 7, 7, 7, 7}; // door 52

static const struct DoorGraphics gDoorAnimGraphicsTable[] =
{
    {0x021, 0, 1, DoorAnimTiles_00, DoorAnimPalettes_8496FDC}, // door 00
    {0x061, 1, 1, DoorAnimTiles_01, DoorAnimPalettes_8496FE4}, // door 01
    {0x1CD, 1, 1, DoorAnimTiles_02, DoorAnimPalettes_8496FEC}, // door 02
    {0x041, 1, 1, DoorAnimTiles_03, DoorAnimPalettes_8496FF4}, // door 03
    {0x248, 0, 1, DoorAnimTiles_04, DoorAnimPalettes_8496FFC}, // door 04
    {0x249, 0, 1, DoorAnimTiles_05, DoorAnimPalettes_8497004}, // door 05
    {0x22F, 0, 1, DoorAnimTiles_06, DoorAnimPalettes_849700C}, // door 06
    {0x21F, 0, 1, DoorAnimTiles_07, DoorAnimPalettes_8497014}, // door 07
    {0x2A5, 0, 1, DoorAnimTiles_08, DoorAnimPalettes_849701C}, // door 08
    {0x287, 0, 1, DoorAnimTiles_09, DoorAnimPalettes_849702C}, // door 09
    {0x2AC, 0, 1, DoorAnimTiles_10, DoorAnimPalettes_849706C}, // door 10
    {0x3A1, 0, 1, DoorAnimTiles_11, DoorAnimPalettes_8497074}, // door 11
    {0x2DC, 0, 1, DoorAnimTiles_12, DoorAnimPalettes_8497064}, // door 12
    {0x225, 0, 1, DoorAnimTiles_13, DoorAnimPalettes_849705C}, // door 13
    {0x1DB, 1, 1, DoorAnimTiles_14, DoorAnimPalettes_8497084}, // door 14
    {0x246, 0, 1, DoorAnimTiles_15, DoorAnimPalettes_8497024}, // door 15
    {0x28E, 0, 1, DoorAnimTiles_16, DoorAnimPalettes_849707C}, // door 16
    {0x2A1, 0, 1, DoorAnimTiles_17, DoorAnimPalettes_8497034}, // door 17
    {0x21C, 0, 1, DoorAnimTiles_18, DoorAnimPalettes_849704C}, // door 18
    {0x21E, 0, 1, DoorAnimTiles_19, DoorAnimPalettes_8497054}, // door 19
    {0x21D, 1, 1, DoorAnimTiles_20, DoorAnimPalettes_849703C}, // door 20
    {0x21A, 0, 1, DoorAnimTiles_21, DoorAnimPalettes_8497044}, // door 21
    {0x224, 0, 1, DoorAnimTiles_22, DoorAnimPalettes_849708C}, // door 22
    {0x289, 0, 1, DoorAnimTiles_23, DoorAnimPalettes_8497094}, // door 23
    {0x30C, 1, 1, DoorAnimTiles_24, DoorAnimPalettes_849709C}, // door 24
    {0x32D, 1, 1, DoorAnimTiles_25, DoorAnimPalettes_84970A4}, // door 25
    {0x2ED, 1, 1, DoorAnimTiles_26, DoorAnimPalettes_84970AC}, // door 26
    {0x264, 1, 1, DoorAnimTiles_27, DoorAnimPalettes_84970B4}, // door 27
    {0x22B, 0, 1, DoorAnimTiles_28, DoorAnimPalettes_84970BC}, // door 28
    {0x2F7, 0, 1, DoorAnimTiles_29, DoorAnimPalettes_84970C4}, // door 29
    {0x297, 0, 1, DoorAnimTiles_30, DoorAnimPalettes_84970CC}, // door 30
    {0x285, 1, 1, DoorAnimTiles_31, DoorAnimPalettes_84970D4}, // door 31
    {0x25D, 1, 1, DoorAnimTiles_32, DoorAnimPalettes_84970DC}, // door 32
    {0x20E, 1, 1, DoorAnimTiles_33, DoorAnimPalettes_84970E4}, // door 33
    {0x3B0, 1, 1, DoorAnimTiles_34, DoorAnimPalettes_84970EC}, // door 34
    {0x28A, 1, 1, DoorAnimTiles_35, DoorAnimPalettes_84970F4}, // door 35
    {0x263, 1, 1, DoorAnimTiles_36, DoorAnimPalettes_84970FC}, // door 36
    {0x329, 1, 1, DoorAnimTiles_37, DoorAnimPalettes_8497104}, // door 37
    {0x291, 0, 1, DoorAnimTiles_38, DoorAnimPalettes_849710C}, // door 38
    {0x21B, 2, 1, DoorAnimTiles_39, DoorAnimPalettes_8497114}, // door 39
    {0x209, 1, 1, DoorAnimTiles_40, DoorAnimPalettes_849711C}, // door 40
    {0x219, 0, 1, DoorAnimTiles_41, DoorAnimPalettes_8497124}, // door 41
    {0x393, 1, 1, DoorAnimTiles_42, DoorAnimPalettes_849712C}, // door 42
    {0x3D4, 1, 1, DoorAnimTiles_42, DoorAnimPalettes_849712C}, // door 43
    {0x36C, 1, 1, DoorAnimTiles_42, DoorAnimPalettes_849712C}, // door 44
    {0x25E, 1, 1, DoorAnimTiles_43, DoorAnimPalettes_8497134}, // door 45
    {0x2AD, 1, 2, DoorAnimTiles_44, DoorAnimPalettes_849713C}, // door 46
    {0x3FC, 0, 1, DoorAnimTiles_45, DoorAnimPalettes_849714C}, // door 47
    {0x396, 1, 1, DoorAnimTiles_46, DoorAnimPalettes_849714C}, // door 48
    {0x20A, 1, 1, DoorAnimTiles_47, DoorAnimPalettes_8497154}, // door 49
    {0x26B, 1, 1, DoorAnimTiles_48, DoorAnimPalettes_849715C}, // door 50
    {0x32C, 1, 1, DoorAnimTiles_49, DoorAnimPalettes_8497164}, // door 51
    {0x383, 1, 1, DoorAnimTiles_50, DoorAnimPalettes_849716C}, // door 52
    {0, 0, 0, NULL, NULL},
};

static void CopyDoorTilesToVram(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame)
{
    if (gfx->size == 2)
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7E00), 0x80);
    else
        CpuFastSet(gfx->tiles + frame->offset, (void *)(VRAM + 0x7F00), 0x40);
}

static void door_build_blockdef(u16 *a, u16 b, const u8 *c)
{
    int i;
    u16 unk;

    for (i = 0; i < 4; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk | (b + i);
    }
    for (; i < 8; i++)
    {
        unk = *(c++) << 12;
        a[i] = unk;
    }
}

static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, u32 x, u32 y, const u8 *pal)
{
    u16 arr[24];
    
    if (gfx->size == 2)
    {
        door_build_blockdef(&arr[8], 0x3F0, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F4, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[8]);
        door_build_blockdef(&arr[8], 0x3F8, pal);
        DrawDoorMetatileAt(x + 1, y - 1, &arr[8]);
        door_build_blockdef(&arr[8], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x + 1, y, &arr[8]);
    }
    else
    {
        door_build_blockdef(&arr[0], 0x3F8, pal);
        DrawDoorMetatileAt(x, y - 1, &arr[0]);
        door_build_blockdef(&arr[0], 0x3FC, pal + 4);
        DrawDoorMetatileAt(x, y, &arr[0]);
    }
}

static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    CurrentMapDrawMetatileAt(x, y - 1);
    CurrentMapDrawMetatileAt(x, y);

    if (gfx->size == 2)
    {
        CurrentMapDrawMetatileAt(x + 1, y - 1);
        CurrentMapDrawMetatileAt(x + 1, y);
    }
}

static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, u32 x, u32 y)
{
    if (frame->offset == 0xFFFF)
    {
        DrawClosedDoorTiles(gfx, x, y);
        if (ShouldUseMultiCorridorDoor())
            DrawClosedDoorTiles(gfx, gSpecialVar_0x8004 + 7, gSpecialVar_0x8005 + 7);
    }
    else
    {
        CopyDoorTilesToVram(gfx, frame);
        DrawCurrentDoorAnimFrame(gfx, x, y, gfx->palette);
        if (ShouldUseMultiCorridorDoor())
            DrawCurrentDoorAnimFrame(gfx, gSpecialVar_0x8004 + 7, gSpecialVar_0x8005 + 7, gfx->palette);
    }
}

enum
{
    TD_FRAMELIST = 0,
    TD_GFX = 2,
    TD_FRAME = 4,
    TD_COUNTER,
    TD_X,
    TD_Y
};

static bool32 sub_808A5F0(struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *taskData)
{
    if (taskData[TD_COUNTER] == 0)
        DrawDoor(gfx, &frames[taskData[TD_FRAME]], taskData[TD_X], taskData[TD_Y]);
    if (taskData[TD_COUNTER] == frames[taskData[TD_FRAME]].time)
    {
        taskData[TD_COUNTER] = 0;
        taskData[TD_FRAME]++;
        if (frames[taskData[TD_FRAME]].time == 0)
            return FALSE;
        else
            return TRUE;
    }
    taskData[TD_COUNTER]++;
    return TRUE;
}

static void Task_AnimateDoor(u8 taskId)
{
    u16 *taskData = gTasks[taskId].data;
    struct DoorAnimFrame *frames = (struct DoorAnimFrame *)(taskData[TD_FRAMELIST] << 16 | taskData[TD_FRAMELIST + 1]);
    struct DoorGraphics *gfx = (struct DoorGraphics *)(taskData[TD_GFX] << 16 | taskData[TD_GFX + 1]);

    if (sub_808A5F0(gfx, frames, taskData) == FALSE)
        DestroyTask(taskId);
}

static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused)
{
    while (frame->time != 0)
        frame++;
    return frame - 1;
}

static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum)
{
    while (gfx->tiles != NULL)
    {
        if (gfx->metatileNum == metatileNum)
            return gfx;
        gfx++;
    }
    return NULL;
}

static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y)
{
    if (FuncIsActiveTask(Task_AnimateDoor) == TRUE)
        return -1;
    else
    {
        u8 taskId = CreateTask(Task_AnimateDoor, 0x50);
        s16 *taskData = gTasks[taskId].data;

        taskData[TD_X] = x;
        taskData[TD_Y] = y;

        taskData[TD_FRAMELIST + 1] = (u32)frames;
        taskData[TD_FRAMELIST] = (u32)frames >> 16;

        taskData[TD_GFX + 1] = (u32)gfx;
        taskData[TD_GFX] = (u32)gfx >> 16;

        return taskId;
    }
}

static void DrawClosedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    DrawClosedDoorTiles(gfx, x, y);
}

static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx != NULL)
        DrawDoor(gfx, GetLastDoorFrame(gDoorOpenAnimFrames, gDoorOpenAnimFrames), x, y);
}

static s8 StartDoorOpenAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
    {
        return -1;
    }
    else
    {
        if (gfx->size == 2)
            return StartDoorAnimationTask(gfx, gBigDoorOpenAnimFrames, x, y);
        else
            return StartDoorAnimationTask(gfx, gDoorOpenAnimFrames, x, y);
    }
}

static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return StartDoorAnimationTask(gfx, gDoorCloseAnimFrames, x, y);
}

static s8 cur_mapdata_get_door_x2_at(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return gfx->sound;
}

void unref_sub_808A83C(u32 x, u32 y)
{
    StartDoorOpenAnimation(gDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorOpened(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawOpenedDoor(gDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorClosed(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawClosedDoor(gDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorClose(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorCloseAnimation(gDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorOpen(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorOpenAnimation(gDoorAnimGraphicsTable, x, y);
}

bool8 FieldIsDoorAnimationRunning(void)
{
    return FuncIsActiveTask(Task_AnimateDoor);
}

u32 GetDoorSoundEffect(u32 x, u32 y)
{
    int sound = cur_mapdata_get_door_x2_at(gDoorAnimGraphicsTable, x, y);
    
    if (sound == 0)
        return SE_DOOR;
    else if (sound == 1)
        return SE_JIDO_DOA;
    else if (sound == 2)
        return SE_TU_SAA;
    else
        return SE_DOOR;
}

// Opens the Battle Tower multi partner's door in sync with the player's door
static bool8 ShouldUseMultiCorridorDoor(void)
{
    if (FlagGet(FLAG_ENABLE_MULTI_CORRIDOR_DOOR))
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR) 
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR))
        {
            return TRUE;
        }
    }
    return FALSE;
}
