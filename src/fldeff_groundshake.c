#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "alloc.h"
#include "random.h"
#include "roulette_util.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/flags.h"
#include "constants/songs.h"

// structures
struct Struct203CF18 {
    u8 taskId;
    struct InnerStruct203CF18 unk4;
}; //size = 0xC8

// extern data
extern const struct SpriteSheet gUnknown_08617D94[];
extern const s16 gUnknown_08617D64[][3];

// static functions
static void sub_81BE808(u8 taskId);
static void sub_81BE900(u8 taskId);
static void sub_81BE968(void);
static void sub_81BE9C0(u8 taskId);
static void sub_81BEA00(u8 taskId);
static void sub_81BEA20(void);
static void sub_81BEAD8(struct Sprite* sprite);

// rodata
const struct InnerStruct203CF18_3 gUnknown_08617E18 = {
    .unk0 = 0x433b,
    .unk2 = 0x61,
    .unk4 = 0x0F,
    .unk5 = 0x05,
    .unk6 = 0xFF,
    .unk7_0 = 0xB,
    .unk7_4 = 0x1,
    .unk7_6 = 0,
    .unk7_7 = 1,
};

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
    .tileTag = 0x0FA0,
    .paletteTag = 0xFFFF,
    .oam = &gUnknown_08617E2C,
    .anims = gSpriteAnimTable_8617E28,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81BEAD8
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
    .tileTag = 0x0FA0,
    .paletteTag = 0xFFFF,
    .oam = &gSpriteAnim_8617E58,
    .anims = gSpriteAnim_8617E54,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_81BEAD8
};

// ewram
EWRAM_DATA struct Struct203CF18 *gUnknown_0203CF18 = NULL;

// text
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
    sub_8151B68(&(gUnknown_0203CF18->unk4), &gUnknown_08617E18);
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
    u8 eventObjectIdBuffer;
    struct EventObject *fieldEventObject;
    struct EventObject *playerAvatarEventObject;

    TryGetEventObjectIdByLocalIdAndMap(0x2D, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &eventObjectIdBuffer);
    fieldEventObject = &(gEventObjects[eventObjectIdBuffer]);
    gSprites[fieldEventObject->spriteId].pos2.y += 4;
    playerAvatarEventObject = &(gEventObjects[gPlayerAvatar.eventObjectId]);

    if((gSprites[fieldEventObject->spriteId].pos1.y + gSprites[fieldEventObject->spriteId].pos2.y) >=
       (gSprites[playerAvatarEventObject->spriteId].pos1.y + gSprites[playerAvatarEventObject->spriteId].pos2.y))
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
    u8 i;
    u8 spriteId;

    for(i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&gUnknown_08617E60, gUnknown_08617D64[i][0] + 120, gUnknown_08617D64[i][1], 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = i;
    }
    for(i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&gUnknown_08617E34, gUnknown_08617D64[i][0] + 115, gUnknown_08617D64[i][1] - 3, 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = 0;
        gSprites[spriteId].data[0] = i;
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
