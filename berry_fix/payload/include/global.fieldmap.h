#ifndef GUARD_GLOBAL_FIELDMAP_H
#define GUARD_GLOBAL_FIELDMAP_H

enum
{
    CONNECTION_SOUTH = 1,
    CONNECTION_NORTH,
    CONNECTION_WEST,
    CONNECTION_EAST,
    CONNECTION_DIVE,
    CONNECTION_EMERGE
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

struct MapLayout
{
    /*0x00*/ s32 width;
    /*0x04*/ s32 height;
    /*0x08*/ u16 *border;
    /*0x0c*/ u16 *map;
    /*0x10*/ struct Tileset *primaryTileset;
    /*0x14*/ struct Tileset *secondaryTileset;
};

struct BackupMapLayout
{
    s32 width;
    s32 height;
    u16 *map;
};

struct EventObjectTemplate
{
    /*0x00*/ u8 localId;
    /*0x01*/ u8 graphicsId;
    /*0x02*/ u8 unk2;
    /*0x04*/ s16 x;
    /*0x06*/ s16 y;
    /*0x08*/ u8 elevation;
    /*0x09*/ u8 movementType;
    /*0x0A*/ u8 movementRangeX:4;
             u8 movementRangeY:4;
    /*0x0C*/ u16 trainerType;
    /*0x0E*/ u16 trainerRange_berryTreeId;
    /*0x10*/ u8 *script;
    /*0x14*/ u16 flagId;
};

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
    u8 filler_A[0x2];
    u8 *script;
};

struct BgEvent
{
    u16 x, y;
    u8 elevation;
    u8 kind; // The "kind" field determines how to access bgUnion union below.
    union {
        u8 *script;
        struct {
            u16 item;
            u16 hiddenItemId;
        } hiddenItem;
        u32 secretBaseId;
    } bgUnion;
};

struct MapEvents
{
    u8 eventObjectCount;
    u8 warpCount;
    u8 coordEventCount;
    u8 bgEventCount;

    struct EventObjectTemplate *eventObjects;
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
    /* 0x00 */ struct MapLayout *mapLayout;
    /* 0x04 */ struct MapEvents *events;
    /* 0x08 */ u8 *mapScripts;
    /* 0x0C */ struct MapConnections *connections;
    /* 0x10 */ u16 music;
    /* 0x12 */ u16 mapLayoutId;
    /* 0x14 */ u8 regionMapSectionId;
    /* 0x15 */ u8 cave;
    /* 0x16 */ u8 weather;
    /* 0x17 */ u8 mapType;
    /* 0x18 */ u8 filler_18;
    /* 0x19 */ u8 escapeRope;
    /* 0x1A */ u8 flags;
    /* 0x1B */ u8 battleType;
};

struct EventObject
{
    /*0x00*/ u32 active:1;
             u32 singleMovementActive:1;
             u32 triggerGroundEffectsOnMove:1;
             u32 triggerGroundEffectsOnStop:1;
             u32 disableCoveringGroundEffects:1; // disables ground effects that cover parts of the object's sprite
             u32 landingJump:1;
             u32 heldMovementActive:1;
             u32 heldMovementFinished:1;
    /*0x01*/ u32 frozen:1;
             u32 facingDirectionLocked:1;
             u32 disableAnim:1; // used to disable forced movement sliding animations (like on ice)
             u32 enableAnim:1;
             u32 inanimate:1;
             u32 invisible:1;
             u32 offScreen:1;
             u32 trackedByCamera:1; // only set for the player object
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
    /*0x04*/ u8 spriteId;
    /*0x05*/ u8 graphicsId;
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
    /*0x18*/ u8 facingDirection:4;
    /*0x18*/ u8 movementDirection:4;
    /*0x19*/ union __attribute__((packed)) {
        u8 as_byte;
        struct __attribute__((packed)) {
            u16 x:4;
            u16 y:4;
        } as_nybbles;
    }  range;
    /*0x1A*/ u8 fieldEffectSpriteId;
    /*0x1B*/ u8 warpArrowSpriteId;
    /*0x1C*/ u8 movementActionId;
    /*0x1D*/ u8 trainerRange_berryTreeId;
    /*0x1E*/ u8 currentMetatileBehavior;
    /*0x1F*/ u8 previousMetatileBehavior;
    /*0x20*/ u8 previousMovementDirection;
    /*0x21*/ u8 directionSequenceIndex;
    /*0x22*/ u8 playerCopyableMovement; // used as an index to gCopyPlayerMovementFuncs for the "copy player" movement types
    /*size = 0x24*/
};

struct EventObjectGraphicsInfo
{
    /*0x00*/ u16 tileTag;
    /*0x02*/ u16 paletteTag;
    /*0x04*/ u16 bridgeReflectionPaletteTag;
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

#define PLAYER_AVATAR_FLAG_ON_FOOT    (1 << 0)
#define PLAYER_AVATAR_FLAG_MACH_BIKE  (1 << 1)
#define PLAYER_AVATAR_FLAG_ACRO_BIKE  (1 << 2)
#define PLAYER_AVATAR_FLAG_SURFING    (1 << 3)
#define PLAYER_AVATAR_FLAG_UNDERWATER (1 << 4)
#define PLAYER_AVATAR_FLAG_5          (1 << 5)
#define PLAYER_AVATAR_FLAG_6          (1 << 6)
#define PLAYER_AVATAR_FLAG_DASH       (1 << 7)

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
    DIR_SOUTHWEST,
    DIR_SOUTHEAST,
    DIR_NORTHWEST,
    DIR_NORTHEAST,
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

struct PlayerAvatar /* 0x202E858 */
{
    /*0x00*/ u8 flags;
    /*0x01*/ u8 unk1; // used to be named bike, but its definitely not that. seems to be some transition flags
    /*0x02*/ u8 runningState; // this is a static running state. 00 is not moving, 01 is turn direction, 02 is moving.
    /*0x03*/ u8 tileTransitionState; // this is a transition running state: 00 is not moving, 01 is transition between tiles, 02 means you are on the frame in which you have centered on a tile but are about to keep moving, even if changing directions. 2 is also used for a ledge hop, since you are transitioning.
    /*0x04*/ u8 spriteId;
    /*0x05*/ u8 eventObjectId;
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

extern struct EventObject gMapObjects[];
extern u8 gSelectedEventObject;
extern struct MapHeader gMapHeader;
extern struct PlayerAvatar gPlayerAvatar;

#endif // GUARD_GLOBAL_FIELDMAP_H
