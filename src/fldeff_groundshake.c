#include "global.h"
#include "global.fieldmap.h"
#include "constants/flags.h"
#include "constants/songs.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_map_obj.h"
#include "malloc.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"

// structures
struct InnerStruct203CF18
{
    u8 filler[0xC4];
};

struct Struct203CF18 {
    u8 taskId;
    struct InnerStruct203CF18 unk4;
}; //size = 0xC8

// extern data
extern const struct SpriteSheet gUnknown_08617D94[];
extern const s16 gUnknown_08617D64[][3];

// extern functions
extern void sub_8151B68(struct InnerStruct203CF18 *, const u8*);
extern void sub_8151B3C(struct InnerStruct203CF18 *);
extern void sub_8151CA8(struct InnerStruct203CF18 *, u8, u8);
extern void sub_8151C50(struct InnerStruct203CF18 *, u8, u8);
extern void sub_8151D28(struct InnerStruct203CF18 *, u8, u8);
extern void sub_8151E50(struct InnerStruct203CF18 *);

// static functions
static void sub_81BE808(u8 taskId);
static void sub_81BE900(u8 taskId);
static void sub_81BE968(void);
static void sub_81BE9C0(u8 taskId);
static void sub_81BEA00(u8 taskId);
static void sub_81BEA20(void);
static void sub_81BEAD8(struct Sprite* sprite);

//.rodata
static const u8 gUnknown_08617E18[] = {0x3b, 0x43, 0x61, 0x00, 0x0f, 0x05, 0xff, 0x9b};

static const union AnimCmd gSpriteAnim_8617E20[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gSpriteAnimTable_8617E28[] =
{
    gSpriteAnim_8617E20,
};

static const struct OamData gUnknown_08617E2C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate gUnknown_08617E34 = {
    0x0FA0, 0xFFFF, &gUnknown_08617E2C, gSpriteAnimTable_8617E28, NULL, gDummySpriteAffineAnimTable, sub_81BEAD8
};

static const union AnimCmd gSpriteAnim_8617E4C[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gSpriteAnim_8617E54[] =
{
    gSpriteAnim_8617E4C,
};

static const struct OamData gSpriteAnim_8617E58 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate gUnknown_08617E60 = {
    0x0FA0, 0xFFFF, &gSpriteAnim_8617E58, gSpriteAnim_8617E54, NULL, gDummySpriteAffineAnimTable, sub_81BEAD8
};

// ewram
EWRAM_DATA struct Struct203CF18 *gUnknown_0203CF18 = NULL;

//text
bool8 sub_81BE66C(void)
{
    if (!(gSaveBlock1Ptr->location.mapGroup == 0x0 && gSaveBlock1Ptr->location.mapNum == 0x1A))
        return 0;
    return FlagGet(FLAG_0x14E);
}

void sub_81BE698(u8 taskId)
{
    sub_8151E50(&(gUnknown_0203CF18->unk4));
}

void sub_81BE6AC(void)
{
    gUnknown_0203CF18 = NULL;
}

void sub_81BE6B8(void)
{
    if(gUnknown_0203CF18 != NULL)
    {
        gUnknown_0203CF18 = NULL;
        return;
    }
    if(!(gSaveBlock1Ptr->location.mapGroup == 0x0 && gSaveBlock1Ptr->location.mapNum == 0x1A) || !FlagGet(FLAG_0x14E))
        return;

    gUnknown_0203CF18 = (struct Struct203CF18 *)AllocZeroed(sizeof(struct Struct203CF18));
    sub_8151B3C(&(gUnknown_0203CF18->unk4));
    sub_8151B68(&(gUnknown_0203CF18->unk4), gUnknown_08617E18);
    sub_8151CA8(&(gUnknown_0203CF18->unk4), 1, 1);
    gUnknown_0203CF18->taskId = CreateTask(sub_81BE698, 0xFF);
}

void sub_81BE72C(void)
{
    if(!(gSaveBlock1Ptr->location.mapGroup == 0x0 && gSaveBlock1Ptr->location.mapNum == 0x1A) || !FlagGet(FLAG_0x14E) || gUnknown_0203CF18 == NULL)
        return;
    if(FuncIsActiveTask(sub_81BE698))
        DestroyTask(gUnknown_0203CF18->taskId);
    sub_8151D28(&(gUnknown_0203CF18->unk4), 1, 1);
    sub_8151C50(&(gUnknown_0203CF18->unk4), 1, 1);
    Free(gUnknown_0203CF18);
    gUnknown_0203CF18 = NULL;
}

void sub_81BE79C(void)
{
    u16 rand;
    bool8 chance;

    if(VarGet(VAR_0x40CB) != 0)
    {
        FlagClear(FLAG_0x14E);
        return;
    }
    rand = Random();
    chance = rand & 1;
    if(FlagGet(FLAG_0x09D) == TRUE)
        chance = TRUE;
    if(chance)
    {
        FlagSet(FLAG_0x14E);
        sub_81BE6B8();
        return;
    }
    FlagClear(FLAG_0x14E);
}

void sub_81BE7F4(void)
{
    CreateTask(sub_81BE808, 0x8);
}

static void sub_81BE808(u8 taskId)
{
    u8 mapObjectIdBuffer;
    struct MapObject *fieldMapObject;
    struct MapObject *playerAvatarMapObject;

    TryGetFieldObjectIdByLocalIdAndMap(0x2D, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &mapObjectIdBuffer);
    fieldMapObject = &(gMapObjects[mapObjectIdBuffer]);
    gSprites[fieldMapObject->spriteId].pos2.y += 4;
    playerAvatarMapObject = &(gMapObjects[gPlayerAvatar.mapObjectId]);

    if((gSprites[fieldMapObject->spriteId].pos1.y + gSprites[fieldMapObject->spriteId].pos2.y) >=
       (gSprites[playerAvatarMapObject->spriteId].pos1.y + gSprites[playerAvatarMapObject->spriteId].pos2.y))
    {
        DestroyTask(taskId);
        EnableBothScriptContexts();
    }
}

static void sp136_strengh_sound(u8 a, u8 b, u8 c, u8 d)
{
    u8 taskId;

    taskId = CreateTask(sub_81BE900, 0x9);
    gTasks[taskId].data[0] = b;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].data[2] = c;
    gTasks[taskId].data[3] = d;
    gTasks[taskId].data[4] = a;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_W070);
}

static void sub_81BE900(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    data[1]++;
    if((data[1] % data[3]) == 0)
    {
        data[1] = 0;
        data[2]--;
        data[0] = -data[0];
        data[4] = -data[4];
        SetCameraPanning(data[0], data[4]);
        if(!data[2])
        {
            sub_81BE968();
            DestroyTask(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

static void sub_81BE968(void)
{
    u8 taskId;

    taskId = FindTaskIdByFunc(sub_81BE9C0);
    if(taskId != 0xFF)
        gTasks[taskId].data[0]++;
}

void sub_81BE994(void)
{
    LoadSpriteSheets(gUnknown_08617D94);
    sub_81BEA20();
    CreateTask(sub_81BE9C0, 0x8);
    sp136_strengh_sound(2, 1, 16, 3);
}

static void sub_81BE9C0(u8 taskId)
{
    u16 *data;

    data = gTasks[taskId].data;
    data[1]++;
    if(data[1] == 1000 || data[0] == 17)
        gTasks[taskId].func = sub_81BEA00;
}

static void sub_81BEA00(u8 taskId)
{
    FreeSpriteTilesByTag(4000);
    DestroyTask(taskId);
    EnableBothScriptContexts();
}

static void sub_81BEA20(void)
{
    u8 count;
    u8 spriteId;

    for(count = 0; count <= 7; count++)
    {
        spriteId = CreateSprite(&gUnknown_08617E60, gUnknown_08617D64[count][0] + 120, gUnknown_08617D64[count][1], 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = count;
    }
    for(count = 0; count <= 7; count++)
    {
        spriteId = CreateSprite(&gUnknown_08617E34, gUnknown_08617D64[count][0] + 115, gUnknown_08617D64[count][1] - 3, 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = count;
    }
}

static void sub_81BEAD8(struct Sprite* sprite)
{
    sprite->data[1] += 2;
    sprite->pos2.y = (sprite->data[1] / 2);
    if(((sprite->pos1.y) + (sprite->pos2.y)) >  gUnknown_08617D64[sprite->data[0]][2])
    {
        DestroySprite(sprite);
        sub_81BE968();
    }
}
