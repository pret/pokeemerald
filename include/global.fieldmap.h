#ifndef GUARD_GLOBAL_FIELDMAP_H
#define GUARD_GLOBAL_FIELDMAP_H

// Masks/shifts for blocks in the map grid
// Map grid blocks consist of a 10 bit metatile id, a 2 bit collision value, and a 4 bit elevation value
// This is the data stored in each data/layouts/*/map.bin file
#define MAPGRID_METATILE_ID_MASK 0x03FF // Bits 0-9
#define MAPGRID_COLLISION_MASK   0x0C00 // Bits 10-11
#define MAPGRID_ELEVATION_MASK   0xF000 // Bits 12-15
#define MAPGRID_COLLISION_SHIFT  10
#define MAPGRID_ELEVATION_SHIFT  12

// An undefined map grid block has all metatile id bits set and nothing else
#define MAPGRID_UNDEFINED   MAPGRID_METATILE_ID_MASK

// Masks/shifts for metatile attributes
// Metatile attributes consist of an 8 bit behavior value, 4 unused bits, and a 4 bit layer type value
// This is the data stored in each data/tilesets/*/*/metatile_attributes.bin file
#define METATILE_ATTR_BEHAVIOR_MASK 0x00FF // Bits 0-7
#define METATILE_ATTR_LAYER_MASK    0xF000 // Bits 12-15
#define METATILE_ATTR_LAYER_SHIFT   12

enum {
    METATILE_LAYER_TYPE_NORMAL,  // Metatile uses middle and top bg layers
    METATILE_LAYER_TYPE_COVERED, // Metatile uses bottom and middle bg layers
    METATILE_LAYER_TYPE_SPLIT,   // Metatile uses bottom and top bg layers
};

#define METATILE_ID(tileset, name) (METATILE_##tileset##_##name)

// Rows of metatiles do not actually have a strict width.
// This constant is used for calculations for finding the next row of metatiles
// for constructing large tiles, such as the Battle Pike's curtain tile.
#define METATILE_ROW_WIDTH 8

typedef void (*TilesetCB)(void);

struct Tileset
{
    /*0x00*/ bool8 isCompressed;
    /*0x01*/ bool8 isSecondary;
    /*0x04*/ const u32 *tiles;
    /*0x08*/ const u16 (*palettes)[16];
    /*0x0C*/ const u16 *metatiles;
    /*0x10*/ const u16 *metatileAttributes;
    /*0x14*/ TilesetCB callback;
};

struct MapLayout
{
    /*0x00*/ s32 width;
    /*0x04*/ s32 height;
    /*0x08*/ const u16 *border;
    /*0x0C*/ const u16 *map;
    /*0x10*/ const struct Tileset *primaryTileset;
    /*0x14*/ const struct Tileset *secondaryTileset;
};

struct BackupMapLayout
{
    s32 width;
    s32 height;
    u16 *map;
};

struct __attribute__((packed, aligned(4))) ObjectEventTemplate
{
    /*0x00*/ u8 localId;
    /*0x01*/ u16 graphicsId;
    /*0x03*/ u8 kind; // Always OBJ_KIND_NORMAL in Emerald.
    /*0x04*/ s16 x;
    /*0x06*/ s16 y;
    /*0x08*/ u8 elevation;
    /*0x09*/ u8 movementType;
    /*0x0A*/ u16 movementRangeX:4;
             u16 movementRangeY:4;
             u16 unused:8;
    /*0x0C*/ u16 trainerType;
    /*0x0E*/ u16 trainerRange_berryTreeId;
    /*0x10*/ const u8 *script;
    /*0x14*/ u16 flagId;
    /*0x16*/ u16 filler;
}; // size = 0x18

struct WarpEvent
{
    s16 x, y;
    u8 elevation;
    u8 warpId;
    u8 mapNum;
    u8 mapGroup;
};

struct CoordEvent
{
    s16 x, y;
    u8 elevation;
    u16 trigger;
    u16 index;
    const u8 *script;
};

struct BgEvent
{
    u16 x, y;
    u8 elevation;
    u8 kind; // The "kind" field determines how to access bgUnion union below.
    union {
        const u8 *script;
        struct {
            u16 item;
            u16 hiddenItemId;
        } hiddenItem;
        u32 secretBaseId;
    } bgUnion;
};

struct MapEvents
{
    u8 objectEventCount;
    u8 warpCount;
    u8 coordEventCount;
    u8 bgEventCount;
    const struct ObjectEventTemplate *objectEvents;
    const struct WarpEvent *warps;
    const struct CoordEvent *coordEvents;
    const struct BgEvent *bgEvents;
};

struct MapConnection
{
    u8 direction;
    s32 offset;
    u8 mapGroup;
    u8 mapNum;
};

struct MapConnections
{
    s32 count;
    const struct MapConnection *connections;
};

struct MapHeader
{
    /* 0x00 */ const struct MapLayout *mapLayout;
    /* 0x04 */ const struct MapEvents *events;
    /* 0x08 */ const u8 *mapScripts;
    /* 0x0C */ const struct MapConnections *connections;
    /* 0x10 */ u16 music;
    /* 0x12 */ u16 mapLayoutId;
    /* 0x14 */ u8 regionMapSectionId;
    /* 0x15 */ u8 cave;
    /* 0x16 */ u8 weather;
    /* 0x17 */ u8 mapType;
    /* 0x18 */ u8 filler_18[2];
               // fields correspond to the arguments in the map_header_flags macro
    /* 0x1A */ bool8 allowCycling:1;
               bool8 allowEscaping:1; // Escape Rope and Dig
               bool8 allowRunning:1;
               bool8 showMapName:5; // the last 4 bits are unused
                                    // but the 5 bit sized bitfield is required to match
    /* 0x1B */ u8 battleType;
};


struct ObjectEvent
{
    /*0x00*/ u32 active:1;
             u32 singleMovementActive:1;
             u32 triggerGroundEffectsOnMove:1;
             u32 triggerGroundEffectsOnStop:1;
             u32 disableCoveringGroundEffects:1;
             u32 landingJump:1;
             u32 heldMovementActive:1;
             u32 heldMovementFinished:1;
    /*0x01*/ u32 frozen:1;
             u32 facingDirectionLocked:1;
             u32 disableAnim:1;
             u32 enableAnim:1;
             u32 inanimate:1;
             u32 invisible:1;
             u32 offScreen:1;
             u32 trackedByCamera:1;
    /*0x02*/ u32 isPlayer:1;
             u32 hasReflection:1;
             u32 inShortGrass:1;
             u32 inShallowFlowingWater:1;
             u32 inSandPile:1;
             u32 inHotSprings:1;
             u32 hasShadow:1;
             u32 spriteAnimPausedBackup:1;
    /*0x03*/ u32 spriteAffineAnimPausedBackup:1;
             u32 disableJumpLandingGroundEffect:1;
             u32 fixedPriority:1;
             u32 hideReflection:1;
             u32 shiny:1; // OW mon shininess
             u32 padding:3;
    /*0x04*/ u16 graphicsId; // 11 bits for species; high 5 bits for form
    /*0x06*/ u8 movementType;
    /*0x07*/ u8 trainerType;
    /*0x08*/ u8 localId;
    /*0x09*/ u8 mapNum;
    /*0x0A*/ u8 mapGroup;
    /*0x0B*/ u8 currentElevation:4;
             u8 previousElevation:4;
    /*0x0C*/ struct Coords16 initialCoords;
    /*0x10*/ struct Coords16 currentCoords;
    /*0x14*/ struct Coords16 previousCoords;
    /*0x18*/ u16 facingDirection:4; // current direction?
             u16 movementDirection:4;
             u16 rangeX:4;
             u16 rangeY:4;
    /*0x1A*/ u8 fieldEffectSpriteId;
    /*0x1B*/ u8 warpArrowSpriteId;
    /*0x1C*/ u8 movementActionId;
    /*0x1D*/ u8 trainerRange_berryTreeId;
    /*0x1E*/ u8 currentMetatileBehavior;
    /*0x1F*/ u8 previousMetatileBehavior;
    /*0x20*/ u8 previousMovementDirection;
    /*0x21*/ u8 directionSequenceIndex;
    /*0x22*/ u8 playerCopyableMovement; // COPY_MOVE_*
    /*0x23*/ u8 spriteId;
    /*size = 0x24*/
};

struct ObjectEventGraphicsInfo
{
    /*0x00*/ u16 tileTag;
    /*0x02*/ u16 paletteTag;
    /*0x04*/ u16 reflectionPaletteTag;
    /*0x06*/ u16 size;
    /*0x08*/ s16 width;
    /*0x0A*/ s16 height;
    /*0x0C*/ u8 paletteSlot:4;
             u8 shadowSize:2;
             u8 inanimate:1;
             u8 compressed:1;
    /*0x0D*/ u8 tracks;
    /*0x10*/ const struct OamData *oam;
    /*0x14*/ const struct SubspriteTable *subspriteTables;
    /*0x18*/ const union AnimCmd *const *anims;
    /*0x1C*/ const struct SpriteFrameImage *images;
    /*0x20*/ const union AffineAnimCmd *const *affineAnims;
};

enum {
    PLAYER_AVATAR_STATE_NORMAL,
    PLAYER_AVATAR_STATE_MACH_BIKE,
    PLAYER_AVATAR_STATE_ACRO_BIKE,
    PLAYER_AVATAR_STATE_SURFING,
    PLAYER_AVATAR_STATE_UNDERWATER,
    PLAYER_AVATAR_STATE_FIELD_MOVE,
    PLAYER_AVATAR_STATE_FISHING,
    PLAYER_AVATAR_STATE_WATERING,
    PLAYER_AVATAR_STATE_VSSEEKER,
};

#define PLAYER_AVATAR_FLAG_ON_FOOT      (1 << 0)
#define PLAYER_AVATAR_FLAG_MACH_BIKE    (1 << 1)
#define PLAYER_AVATAR_FLAG_ACRO_BIKE    (1 << 2)
#define PLAYER_AVATAR_FLAG_SURFING      (1 << 3)
#define PLAYER_AVATAR_FLAG_UNDERWATER   (1 << 4)
#define PLAYER_AVATAR_FLAG_CONTROLLABLE (1 << 5)
#define PLAYER_AVATAR_FLAG_FORCED_MOVE  (1 << 6)
#define PLAYER_AVATAR_FLAG_DASH         (1 << 7)

#define PLAYER_AVATAR_FLAG_BIKE        (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE)
// Player avatar flags for which follower Pokémon are hidden
#define FOLLOWER_INVISIBLE_FLAGS       (PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER | \
                                        PLAYER_AVATAR_FLAG_BIKE | PLAYER_AVATAR_FLAG_FORCED_MOVE)

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
    COLLISION_NONE,
    COLLISION_OUTSIDE_RANGE,
    COLLISION_IMPASSABLE,
    COLLISION_ELEVATION_MISMATCH,
    COLLISION_OBJECT_EVENT,
    COLLISION_STOP_SURFING,
    COLLISION_LEDGE_JUMP,
    COLLISION_PUSHED_BOULDER,
    COLLISION_ROTATING_GATE,
    COLLISION_WHEELIE_HOP,
    COLLISION_ISOLATED_VERTICAL_RAIL,
    COLLISION_ISOLATED_HORIZONTAL_RAIL,
    COLLISION_VERTICAL_RAIL,
    COLLISION_HORIZONTAL_RAIL,
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
    /*0x01*/ u8 transitionFlags; // used to be named bike, but its definitely not that. seems to be some transition flags
    /*0x02*/ u8 runningState; // this is a static running state. 00 is not moving, 01 is turn direction, 02 is moving.
    /*0x03*/ u8 tileTransitionState; // this is a transition running state: 00 is not moving, 01 is transition between tiles, 02 means you are on the frame in which you have centered on a tile but are about to keep moving, even if changing directions. 2 is also used for a ledge hop, since you are transitioning.
    /*0x04*/ u8 spriteId;
    /*0x05*/ u8 objectEventId;
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

extern struct ObjectEvent gObjectEvents[OBJECT_EVENTS_COUNT];
extern u8 gSelectedObjectEvent;
extern struct MapHeader gMapHeader;
extern struct PlayerAvatar gPlayerAvatar;
extern struct Camera gCamera;

#endif // GUARD_GLOBAL_FIELDMAP_H
