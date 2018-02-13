#ifndef GUARD_GLOBAL_FIELDMAP_H
#define GUARD_GLOBAL_FIELDMAP_H

#define NUM_FIELD_OBJECTS 16

enum
{
    CONNECTION_SOUTH = 1,
    CONNECTION_NORTH,
    CONNECTION_WEST,
    CONNECTION_EAST,
    CONNECTION_DIVE,
    CONNECTION_EMERGE
};

// map types
enum
{
    MAP_TYPE_0,
    MAP_TYPE_TOWN,
    MAP_TYPE_CITY,
    MAP_TYPE_ROUTE,
    MAP_TYPE_UNDERGROUND,
    MAP_TYPE_UNDERWATER,
    MAP_TYPE_6,
    MAP_TYPE_7,
    MAP_TYPE_INDOOR,
    MAP_TYPE_SECRET_BASE
};

// map battle scenes
enum
{
    MAP_BATTLE_SCENE_NORMAL,       // 0
    MAP_BATTLE_SCENE_GYM,          // 1
    MAP_BATTLE_SCENE_MAGMA,        // 2
    MAP_BATTLE_SCENE_AQUA,         // 3
    MAP_BATTLE_SCENE_SIDNEY,       // 4
    MAP_BATTLE_SCENE_PHOEBE,       // 5
    MAP_BATTLE_SCENE_GLACIA,       // 6
    MAP_BATTLE_SCENE_DRAKE,        // 7
    MAP_BATTLE_SCENE_FRONTIER,     // 8
};

typedef void (*TilesetCB)(void);

struct Tileset
{
    /*0x00*/ bool8 isCompressed;
    /*0x01*/ bool8 isSecondary;
    /*0x04*/ void *tiles;
    /*0x08*/ void *palettes;
    /*0x0c*/ void *metatiles;
    /*0x10*/ void *metatileAttributes;
    /*0x14*/ TilesetCB callback;
};

struct MapData
{
    /*0x00*/ s32 width;
    /*0x04*/ s32 height;
    /*0x08*/ u16 *border;
    /*0x0c*/ u16 *map;
    /*0x10*/ struct Tileset *primaryTileset;
    /*0x14*/ struct Tileset *secondaryTileset;
};

struct BackupMapData
{
    s32 width;
    s32 height;
    u16 *map;
};

struct MapObjectTemplate
{
    /*0x00*/ u8 localId;
    /*0x01*/ u8 graphicsId;
    /*0x02*/ u8 unk2;
    /*0x04*/ s16 x;
    /*0x06*/ s16 y;
    /*0x08*/ u8 elevation;
    /*0x09*/ u8 movementType;
    /*0x0A*/ u8 unkA_0:4;
             u8 unkA_4:4;
    ///*0x0B*/ u8 fillerB[1];
    /*0x0C*/ u16 unkC;
    /*0x0E*/ u16 unkE;
    /*0x10*/ const u8 *script;
    /*0x14*/ u16 flagId;
    /*0x16*/ u8 filler_16[2];
};  /*size = 0x18*/

struct WarpEvent
{
    s16 x, y;
    s8 warpId;
    u8 mapGroup;
    u8 mapNum;
    u8 unk7;
};

struct CoordEvent
{
    s16 x, y;
    u8 unk4;
    u8 filler_5;
    u16 trigger;
    u16 index;
    u8 filler_A[0x2];
    u8 *script;
};

struct BgEvent
{
    u16 x, y;
    u8 unk4;
    u8 kind;
    // 0x2 padding for the union beginning.
    union { // carried over from diego's FR/LG work, seems to be the same struct
        // in gen 3, "kind" (0x3 in BgEvent struct) determines the method to read the union.
        u8 *script;

        // hidden item type probably
        struct {
            u8 filler6[0x2];
            u16 hiddenItemId; // flag offset to determine flag lookup
        } hiddenItem;

        // secret base type
        u32 secretBaseId;

    } bgUnion;
};

struct MapEvents
{
    u8 mapObjectCount;
    u8 warpCount;
    u8 coordEventCount;
    u8 bgEventCount;

    struct MapObjectTemplate *mapObjects;
    struct WarpEvent *warps;
    struct CoordEvent *coordEvents;
    struct BgEvent *bgEvents;
};

struct MapConnection
{
 /*0x00*/ u8 direction;
 /*0x01*/ u32 offset;
 /*0x05*/ u8 mapGroup;
 /*0x06*/ u8 mapNum;
};

struct MapConnections
{
    s32 count;
    struct MapConnection *connections;
};

struct MapHeader
{
    /* 0x00 */ const struct MapData *mapData;
    /* 0x04 */ const struct MapEvents *events;
    /* 0x08 */ u8 *mapScripts;
    /* 0x0C */ const struct MapConnections *connections;
    /* 0x10 */ u16 music;
    /* 0x12 */ u16 mapDataId;
    /* 0x14 */ u8 regionMapSectionId;
    /* 0x15 */ u8 cave;
    /* 0x16 */ u8 weather;
    /* 0x17 */ u8 mapType;
    /* 0x18 */ u8 filler_18;
    /* 0x19 */ u8 escapeRope;
    /* 0x1A */ u8 flags;
    /* 0x1B */ u8 battleType;
};

struct MapObject
{
    /*0x00*/ u32 active:1;
             u32 mapobj_bit_1:1;
             u32 mapobj_bit_2:1;
             u32 mapobj_bit_3:1;
             u32 mapobj_bit_4:1;
             u32 mapobj_bit_5:1;
             u32 mapobj_bit_6:1;
             u32 mapobj_bit_7:1;
    /*0x01*/ u32 mapobj_bit_8:1;
             u32 mapobj_bit_9:1;
             u32 mapobj_bit_10:1;
             u32 mapobj_bit_11:1;
             u32 mapobj_bit_12:1;
             u32 mapobj_bit_13:1;
             u32 mapobj_bit_14:1;
             u32 mapobj_bit_15:1;
    /*0x02*/ u32 mapobj_bit_16:1;
             u32 mapobj_bit_17:1;
             u32 mapobj_bit_18:1;
             u32 mapobj_bit_19:1;
             u32 mapobj_bit_20:1;
             u32 mapobj_bit_21:1;
             u32 mapobj_bit_22:1;
             u32 mapobj_bit_23:1;
    /*0x03*/ u32 mapobj_bit_24:1;
             u32 mapobj_bit_25:1;
             u32 mapobj_bit_26:1;
             u32 mapobj_bit_27:1;
             u32 mapobj_bit_28:1;
             u32 mapobj_bit_29:1;
             u32 mapobj_bit_30:1;
             u32 mapobj_bit_31:1;
    /*0x04*/ u8 spriteId;
    /*0x05*/ u8 graphicsId;
    /*0x06*/ u8 animPattern;
    /*0x07*/ u8 trainerType;
    /*0x08*/ u8 localId;
    /*0x09*/ u8 mapNum;
    /*0x0A*/ u8 mapGroup;
    /*0x0B*/ u8 mapobj_unk_0B_0:4;
             u8 elevation:4;
    /*0x0C*/ struct Coords16 coords1;
    /*0x10*/ struct Coords16 coords2;
    /*0x14*/ struct Coords16 coords3;
    /*0x18*/ u8 mapobj_unk_18:4;  // current direction?
    /*0x18*/ u8 placeholder18:4;
    /*0x19*/ union __attribute__((packed)) {
        u8 as_byte;
        struct __attribute__((packed)) {
            u8 x:4;
            u8 y:4;
        } __attribute__((aligned (1))) as_nybbles;
    } __attribute__((aligned (1))) range;
    /*0x1A*/ u8 mapobj_unk_1A;
    /*0x1B*/ u8 mapobj_unk_1B;
    /*0x1C*/ u8 mapobj_unk_1C;
    /*0x1D*/ u8 trainerRange_berryTreeId;
    /*0x1E*/ u8 mapobj_unk_1E;
    /*0x1F*/ u8 mapobj_unk_1F;
    /*0x20*/ u8 mapobj_unk_20;
    /*0x21*/ u8 mapobj_unk_21;
    /*0x22*/ u8 animId;
    /*size = 0x24*/
};

struct MapObjectGraphicsInfo
{
    /*0x00*/ u16 tileTag;
    /*0x02*/ u16 paletteTag1;
    /*0x04*/ u16 paletteTag2;
    /*0x06*/ u16 size;
    /*0x08*/ s16 width;
    /*0x0A*/ s16 height;
    /*0x0C*/ u8 paletteSlot:4;
             u8 shadowSize:2;
             u8 inanimate:1;
             u8 disableReflectionPaletteLoad:1;
    /*0x0D*/ u8 tracks;
    /*0x10*/ const struct OamData *oam;
    /*0x14*/ const struct SubspriteTable *subspriteTables;
    /*0x18*/ const union AnimCmd *const *anims;
    /*0x1C*/ const struct SpriteFrameImage *images;
    /*0x20*/ const union AffineAnimCmd *const *affineAnims;
};

#define PLAYER_AVATAR_FLAG_ON_FOOT   (1 << 0)
#define PLAYER_AVATAR_FLAG_MACH_BIKE (1 << 1)
#define PLAYER_AVATAR_FLAG_ACRO_BIKE (1 << 2)
#define PLAYER_AVATAR_FLAG_SURFING   (1 << 3)
#define PLAYER_AVATAR_FLAG_4         (1 << 4)
#define PLAYER_AVATAR_FLAG_5         (1 << 5)
#define PLAYER_AVATAR_FLAG_6         (1 << 6)
#define PLAYER_AVATAR_FLAG_DASH      (1 << 7)

enum
{
    ACRO_BIKE_NORMAL,
    ACRO_BIKE_TURNING,
    ACRO_BIKE_WHEELIE_STANDING,
    ACRO_BIKE_BUNNY_HOP,
    ACRO_BIKE_WHEELIE_MOVING,
    ACRO_BIKE_STATE5,
    ACRO_BIKE_STATE6,
};

enum
{
    DIR_NONE,
    DIR_SOUTH,
    DIR_NORTH,
    DIR_WEST,
    DIR_EAST,
};

enum
{
    COLLISION_LEDGE_JUMP = 6
};

// player running states
enum
{
    NOT_MOVING,
    TURN_DIRECTION, // not the same as turning! turns your avatar without moving. also known as a turn frame in some circles
    MOVING,
};

// player tile transition states
enum
{
    T_NOT_MOVING,
    T_TILE_TRANSITION,
    T_TILE_CENTER, // player is on a frame in which they are centered on a tile during which the player either stops or keeps their momentum and keeps going, changing direction if necessary.
};

struct PlayerAvatar
{
    /*0x00*/ u8 flags;
    /*0x01*/ u8 unk1; // used to be named bike, but its definitely not that. seems to be some transition flags
    /*0x02*/ u8 runningState; // this is a static running state. 00 is not moving, 01 is turn direction, 02 is moving.
    /*0x03*/ u8 tileTransitionState; // this is a transition running state: 00 is not moving, 01 is transition between tiles, 02 means you are on the frame in which you have centered on a tile but are about to keep moving, even if changing directions. 2 is also used for a ledge hop, since you are transitioning.
    /*0x04*/ u8 spriteId;
    /*0x05*/ u8 mapObjectId;
    /*0x06*/ bool8 preventStep;
    /*0x07*/ u8 gender;
    /*0x08*/ u8 acroBikeState; // 00 is normal, 01 is turning, 02 is standing wheelie, 03 is hopping wheelie
    /*0x09*/ u8 newDirBackup; // during bike movement, the new direction as opposed to player's direction is backed up here.
    /*0x0A*/ u8 bikeFrameCounter; // on the mach bike, when this value is 1, the bike is moving but not accelerating yet for 1 tile. on the acro bike, this acts as a timer for acro bike.
    /*0x0B*/ u8 bikeSpeed;
	// acro bike only
    /*0x0C*/ u32 directionHistory; // up/down/left/right history is stored in each nybble, but using the field directions and not the io inputs.
    /*0x10*/ u32 abStartSelectHistory; // same as above but for A + B + start + select only
	// these two are timer history arrays which [0] is the active timer for acro bike. every element is backed up to the next element upon update.
    /*0x14*/ u8 dirTimerHistory[8];
    /*0x1C*/ u8 abStartSelectTimerHistory[8];
};

struct Camera
{
    bool8 active:1;
    s32 x;
    s32 y;
};

extern struct MapObject gMapObjects[NUM_FIELD_OBJECTS];
extern u8 gSelectedMapObject;
extern struct MapHeader gMapHeader;
extern struct PlayerAvatar gPlayerAvatar;
extern struct Camera gCamera;

#endif // GUARD_GLOBAL_FIELDMAP_H
