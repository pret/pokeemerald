#include "global.h"
#include "event_object_movement.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/songs.h"

// Tasks governing the ship's departure after you've gotten HM01 CUT

#define SPRITE_TAG_WAKE  4000
#define SPRITE_TAG_SMOKE 4001

#define PALTAG_SMOKE_WAKE 3000

static void Task_SSAnneInit(u8 taskId);
static void Task_SSAnneRun(u8 taskId);
static void Task_SSAnneFinish(u8 taskId);
static void CreateWakeBehindBoat(void);
static void WakeSpriteCallback(struct Sprite *sprite);
static void CreateSmokeSprite(void);
static void SmokeSpriteCallback(struct Sprite *sprite);

static const u16 sWakeTiles[] = INCGFX_U16("graphics/ss_anne/wake.png", ".4bpp");
static const u16 sSmokeTiles[] = INCGFX_U16("graphics/ss_anne/smoke.png", ".4bpp");

static const u16 sWakeSmokePalette[] = INCGFX_U16("graphics/ss_anne/wake.png", ".gbapal");

static const struct SpriteSheet sSpriteSheets[] = {
    {
        .data = (const void *)sWakeTiles, 
        .size = sizeof(sWakeTiles), 
        .tag = SPRITE_TAG_WAKE,
    },
    {
        .data = (const void *)sSmokeTiles, 
        .size = sizeof(sSmokeTiles), 
        .tag = SPRITE_TAG_SMOKE,
    },
    {
        .data = NULL
    }
};

static const struct SpritePalette sSpritePalettes[] = {
    {
        .data = (const void *)sWakeSmokePalette, 
        .tag = PALTAG_SMOKE_WAKE
    },
    {
        .data = NULL
    }
};

static const union AnimCmd sWakeAnim[] = {
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sWakeAnimTable[] = {
    sWakeAnim
};

static const struct OamData sWakeOamData = {
    .shape = ST_OAM_V_RECTANGLE,
    .size = 2
};

static const struct SpriteTemplate sWakeSpriteTemplate = {
    .tileTag = SPRITE_TAG_WAKE,
    .paletteTag = PALTAG_SMOKE_WAKE,
    .oam = &sWakeOamData,
    .anims = sWakeAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = WakeSpriteCallback,
};

static const union AnimCmd sSmokeAnim[] = {
    ANIMCMD_FRAME( 0, 10),
    ANIMCMD_FRAME( 4, 20),
    ANIMCMD_FRAME( 8, 20),
    ANIMCMD_FRAME(12, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSmokeAnimTable[] = {
    sSmokeAnim
};

static const struct OamData sSmokeOamData = {
    .shape = ST_OAM_SQUARE,
    .size = 1
};

static const struct SpriteTemplate sSmokeSpriteTemplate = {
    .tileTag = SPRITE_TAG_SMOKE,
    .paletteTag = PALTAG_SMOKE_WAKE,
    .oam = &sSmokeOamData,
    .anims = sSmokeAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SmokeSpriteCallback,
};

void DoSSAnneDepartureCutscene(void)
{
    u8 taskId;

    PlaySE(SE_RG_SS_ANNE_HORN);
    taskId = CreateTask(Task_SSAnneInit, 8);
    gTasks[taskId].data[0] = 50;
}

static void Task_SSAnneInit(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (--data[0] == 0)
    {
        LoadSpriteSheets(sSpriteSheets);
        LoadSpritePalette(sSpritePalettes);
        CreateWakeBehindBoat();
        gTasks[taskId].func = Task_SSAnneRun;
    }
}

static void Task_SSAnneRun(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    u8 objectEventId;
    struct ObjectEvent * boatObject;
    s16 x;

    data[1]++;
    data[2]++;
    if (data[1] == 70)
    {
        data[1] = 0;
        CreateSmokeSprite();
    }
    TryGetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    boatObject = &gObjectEvents[objectEventId];
    if (gSprites[boatObject->spriteId].x + gSprites[boatObject->spriteId].x2 < -120)
    {
        PlaySE(SE_RG_SS_ANNE_HORN);
        gTasks[taskId].func = Task_SSAnneFinish;
    }
    else
    {
        x = data[2] / 5;
        gSprites[boatObject->spriteId].x2 = -x;
    }
}

static void Task_SSAnneFinish(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (++data[3] == 40)
    {
        FreeSpriteTilesByTag(SPRITE_TAG_WAKE);
        FreeSpriteTilesByTag(SPRITE_TAG_SMOKE);
        FreeSpritePaletteByTag(PALTAG_SMOKE_WAKE);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

static void CreateWakeBehindBoat(void)
{
    u8 objectEventId;
    struct ObjectEvent * boatObject;
    u16 x;
    u8 spriteId;

    TryGetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    boatObject = &gObjectEvents[objectEventId];
    x = gSprites[boatObject->spriteId].x + gSprites[boatObject->spriteId].x2 + 80;
    spriteId = CreateSprite(&sWakeSpriteTemplate, x, 109, 0xFF);
    gSprites[spriteId].oam.priority = 2;
}

static void WakeSpriteCallback(struct Sprite *sprite)
{
    u8 objectEventId;
    struct ObjectEvent * boatObject;
    u16 x;

    TryGetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    boatObject = &gObjectEvents[objectEventId];
    x = gSprites[boatObject->spriteId].x + gSprites[boatObject->spriteId].x2 + 80;
    sprite->x = x;
    if (sprite->data[0] / 6 < 22)
        sprite->data[0]++;
    sprite->x2 = sprite->data[0] / 6;
    if (sprite->x + sprite->x2 < -18)
        DestroySprite(sprite);
}

static void CreateSmokeSprite(void)
{
    u8 objectEventId;
    struct ObjectEvent * boatObject;
    u16 x;

    TryGetObjectEventIdByLocalIdAndMap(1, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    boatObject = &gObjectEvents[objectEventId];
    x = gSprites[boatObject->spriteId].x + gSprites[boatObject->spriteId].x2 + 49;
    if ((s16)x >= -32)
        CreateSprite(&sSmokeSpriteTemplate, x, 78, 8);
}

static void SmokeSpriteCallback(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->x2 = sprite->data[0] / 4;
    if (sprite->animEnded)
        DestroySprite(sprite);
}
