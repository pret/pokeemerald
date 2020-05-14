#include "global.h"
#include "decompress.h"
#include "link.h"
#include "link_rfu.h"
#include "sound.h"
#include "task.h"
#include "trig.h"
#include "constants/songs.h"

extern const struct OamData gOamData_AffineOff_ObjNormal_32x32;

static void sub_802E6D0(u8 taskId);
static void sub_802E83C(u8 taskId);
static void sub_802E8C8(u8 taskId);
static void sub_802EA50(u8 taskId);
static void sub_802EAB0(u8 taskId);
static void sub_802EB98(u8 taskId);
static void Task_MinigameCountdown(u8 taskId);
static bool32 RunMinigameCountdownDigitsAnim(u8 spriteId);
static bool32 IsStartGraphicAnimRunning(u8 spriteId);
static void Load321StartGfx(u16 tileTag, u16 palTag);
static u8 CreateNumberSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority);
static void CreateStartSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority, s16 *spriteId1, s16 *spriteId2);
static void InitStartGraphic(u8 spriteId1, u8 spriteId2, u8 spriteId3);
static void SpriteCB_Start(struct Sprite *sprite);

static const u16 sSpritePal_321Start_2[] = INCBIN_U16("graphics/link_games/321start_2.gbapal");
static const u32 sSpriteSheet_321Start_2[] = INCBIN_U32("graphics/link_games/321start_2.4bpp.lz");

static const struct CompressedSpriteSheet gUnknown_082FE6C8[] =
{
    {sSpriteSheet_321Start_2, 0xC00, 0x2000},
    {},
};

static const struct SpritePalette gUnknown_082FE6D8[] =
{
    {sSpritePal_321Start_2, 0x2000},
    {},
};

static const union AnimCmd sSpriteAnim_82FE6E8[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FE6F0[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FE6F8[] =
{
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FE700[] =
{
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FE708[] =
{
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82FE710[] =
{
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_82FE718[] =
{
    sSpriteAnim_82FE6E8,
    sSpriteAnim_82FE6F0,
    sSpriteAnim_82FE6F8,
    sSpriteAnim_82FE700,
    sSpriteAnim_82FE708,
    sSpriteAnim_82FE710
};

static const struct SpriteTemplate gUnknown_082FE730[] =
{
    {
        .tileTag = 0x2000,
        .paletteTag = 0x2000,
        .oam = &gOamData_AffineOff_ObjNormal_32x32,
        .anims = sSpriteAnimTable_82FE718,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

static const TaskFunc gUnknown_082FE748[][4] =
{
    {
        sub_802E83C,
        sub_802E8C8,
        sub_802EA50,
        sub_802EAB0
    },
};

static const u16 sSpritePal_321Start[] = INCBIN_U16("graphics/link_games/321start.gbapal");
static const u32 sSpriteSheet_321Start[] = INCBIN_U32("graphics/link_games/321start.4bpp.lz");

// Unused
static u32 sub_802E63C(u8 funcSetId, u8 taskPriority)
{
    u8 taskId = CreateTask(sub_802E6D0, taskPriority);
    struct Task *task = &gTasks[taskId];

    task->data[0] = 1;
    task->data[1] = funcSetId;
    gUnknown_082FE748[funcSetId][0](taskId);
    return taskId;
}

static bool32 sub_802E688(void)
{
    u8 taskId = FindTaskIdByFunc(sub_802E6D0);
    if (taskId == 0xFF)
        return FALSE;

    gTasks[taskId].data[0] = 2;
    return TRUE;
}

static bool32 sub_802E6BC(void)
{
    return FuncIsActiveTask(sub_802E6D0);
}

static void sub_802E6D0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 2:
        gUnknown_082FE748[data[1]][2](taskId);
        data[0] = 3;
        break;
    case 3:
        gUnknown_082FE748[data[1]][3](taskId);
        break;
    case 4:
        gUnknown_082FE748[data[1]][1](taskId);
        DestroyTask(taskId);
        break;
    }
}

static void sub_802E75C(u8 taskId, s16 *data)
{
    u8 i;
    struct Sprite *sprite;

    LoadCompressedSpriteSheet(&gUnknown_082FE6C8[data[3]]);
    LoadSpritePalette(&gUnknown_082FE6D8[data[4]]);
    for (i = 0; i < data[8]; i++)
        data[13 + i] = CreateSprite(&gUnknown_082FE730[data[2]], data[9], data[10], data[7]);
    for (i = 0; i < data[8]; i++)
    {
        sprite = &gSprites[data[13 + i]];
        sprite->oam.priority = data[6];
        sprite->invisible = TRUE;
        sprite->data[1] = data[5];
        sprite->data[3] = taskId;
        sprite->data[4] = i;
        sprite->data[5] = data[13];
    }
}

static void sub_802E83C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[2] = 0;
    data[3] = 0;
    data[4] = 0;
    data[5] = 60;
    data[6] = 0;
    data[7] = 0;
    data[8] = 3;
    data[9] = 120;
    data[10] = 88;
    sub_802E75C(taskId, data);

    StartSpriteAnim(&gSprites[data[14]], 4);
    gSprites[data[14]].pos2.x = -32;

    StartSpriteAnim(&gSprites[data[15]], 5);
    gSprites[data[15]].pos2.x = 32;
}

static void sub_802E8C8(u8 taskId)
{
    u8 i = 0;
    s16 *data = gTasks[taskId].data;

    for (i = 0; i < data[8]; i++)
        DestroySprite(&gSprites[data[13 + i]]);
    FreeSpriteTilesByTag(gUnknown_082FE6C8[data[3]].tag);
    FreeSpritePaletteByTag(gUnknown_082FE6D8[data[4]].tag);
}

static void sub_802E938(struct Sprite *sprite)
{
    s16 *data = gTasks[sprite->data[3]].data;

    if (data[11] % data[5] != 0)
        return;
    if (data[11] == data[10])
        return;

    data[10] = data[11];
    switch (sprite->data[2])
    {
    case 0:
        sprite->invisible = FALSE;
    case 1:
    case 2:
        PlaySE(SE_KON);
        StartSpriteAnim(sprite, sprite->data[2]);
        break;
    case 3:
        PlaySE(SE_PIN);
        StartSpriteAnim(sprite, sprite->data[2]);
        gSprites[data[14]].invisible = FALSE;
        gSprites[data[15]].invisible = FALSE;
        break;
    case 4:
        sprite->invisible = TRUE;
        gSprites[data[14]].invisible = TRUE;
        gSprites[data[15]].invisible = TRUE;
        data[0] = 4;
        return;
    }
    sprite->data[2]++;
}

static void sub_802EA50(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    PlaySE(SE_KON);
    gSprites[data[13]].callback = sub_802E938;
    gSprites[data[13]].invisible = FALSE;
    gTasks[taskId].data[0] = 3;
}

static void sub_802EAB0(u8 taskId)
{
    u16 packet[6];
    s16 *data = gTasks[taskId].data;

    if (gReceivedRemoteLinkPlayers != 0)
    {
        if (gRecvCmds[0][1] == 0x7FFF)
            data[11] = gRecvCmds[0][2];
        if (GetMultiplayerId() == 0)
        {
            data[12]++;
            memset(packet, 0, sizeof(packet));
            packet[0] = 0x7FFF;
            packet[1] = data[12];
            sub_800FE50(packet);
        }
    }
    else
    {
        data[11]++;
    }
}

#define tState       data[0]
#define tTilesTag    data[2]
#define tPalTag      data[3]
#define tX           data[4]
#define tY           data[5]
#define tSubpriority data[6]
#define tSpriteId1   data[7]
#define tSpriteId2   data[8]
#define tSpriteId3   data[9]

void StartMinigameCountdown(s16 tilesTag, s16 palTag, s16 x, s16 y, u8 subpriority)
{
    u8 taskId = CreateTask(Task_MinigameCountdown, 80);
    gTasks[taskId].tTilesTag = tilesTag;
    gTasks[taskId].tPalTag = palTag;
    gTasks[taskId].tX = x;
    gTasks[taskId].tY = y;
    gTasks[taskId].tSubpriority = subpriority;
}

bool32 IsMinigameCountdownRunning(void)
{
    return FuncIsActiveTask(Task_MinigameCountdown);
}

static void Task_MinigameCountdown(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        Load321StartGfx(tTilesTag, tPalTag);
        tSpriteId1 = CreateNumberSprite(tTilesTag, tPalTag, tX, tY, tSubpriority);
        CreateStartSprite(tTilesTag, tPalTag, tX, tY, tSubpriority, &tSpriteId2, &tSpriteId3);
        tState++;
        break;
    case 1:
        if (!RunMinigameCountdownDigitsAnim(tSpriteId1))
        {
            InitStartGraphic(tSpriteId1, tSpriteId2, tSpriteId3);
            FreeSpriteOamMatrix(&gSprites[tSpriteId1]);
            DestroySprite(&gSprites[tSpriteId1]);
            tState++;
        }
        break;
    case 2:
        if (!IsStartGraphicAnimRunning(tSpriteId2))
        {
            DestroySprite(&gSprites[tSpriteId2]);
            DestroySprite(&gSprites[tSpriteId3]);
            FreeSpriteTilesByTag(tTilesTag);
            FreeSpritePaletteByTag(tPalTag);
            DestroyTask(taskId);
        }
        break;
    }
}

static bool32 RunMinigameCountdownDigitsAnim(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];

    switch (sprite->data[0])
    {
    case 0:
        sub_8007E18(sprite, 0x800, 0x1A);
        sprite->data[0]++;
        // fallthrough
    case 1:
        if (sprite->data[2] == 0)
            PlaySE(SE_KON2);
        if (++sprite->data[2] >= 20)
        {
            sprite->data[2] = 0;
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[0]++;
        }
        break;
    case 2:
        if (sprite->affineAnimEnded)
            sprite->data[0]++;
        break;
    case 3:
        if (++sprite->data[2] >= 4)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
            StartSpriteAffineAnim(sprite, 2);
        }
        break;
    case 4:
        sprite->pos1.y -= 4;
        if (++sprite->data[2] >= 8)
        {
            if (sprite->data[4] <= 1)
            {
                StartSpriteAnim(sprite, sprite->data[4] + 1);
                sprite->data[2] = 0;
                sprite->data[0]++;
            }
            else
            {
                sprite->data[0] = 7;
                return FALSE;
            }
        }
        break;
    case 5:
        sprite->pos1.y += 4;
        if (++sprite->data[2] >= 8)
        {
            sprite->data[2] = 0;
            StartSpriteAffineAnim(sprite, 3);
            sprite->data[0]++;
        }
        break;
    case 6:
        if (sprite->affineAnimEnded)
        {
            sprite->data[4]++;
            sprite->data[0] = 1;
        }
        break;
    case 7:
        return FALSE;
    }

    return TRUE;
}

// First argument is unused.
static void InitStartGraphic(u8 spriteId1, u8 spriteId2, u8 spriteId3)
{
    gSprites[spriteId2].pos2.y = -40;
    gSprites[spriteId3].pos2.y = -40;
    gSprites[spriteId2].invisible = FALSE;
    gSprites[spriteId3].invisible = FALSE;
    gSprites[spriteId2].callback = SpriteCB_Start;
    gSprites[spriteId3].callback = SpriteCB_Start;
}

static bool32 IsStartGraphicAnimRunning(u8 spriteId)
{
    return gSprites[spriteId].callback == SpriteCB_Start;
}

static void SpriteCB_Start(struct Sprite *sprite)
{
    int y;
    s16 *data = sprite->data;

    switch (data[0])
    {
    case 0:
        data[4] = 64;
        data[5] = sprite->pos2.y << 4;
        data[0]++;
    case 1:
        data[5] += data[4];
        data[4]++;
        sprite->pos2.y = data[5] >> 4;
        if (sprite->pos2.y >= 0)
        {
            PlaySE(SE_KON2);
            sprite->pos2.y = 0;
            data[0]++;
        }
        break;
    case 2:
        data[1] += 12;
        if (data[1] >= 128)
        {
            PlaySE(SE_KON2);
            data[1] = 0;
            data[0]++;
        }
        y = gSineTable[data[1]];
        sprite->pos2.y = -(y >> 4);
        break;
    case 3:
        data[1] += 16;
        if (data[1] >= 128)
        {
            PlaySE(SE_KON2);
            data[1] = 0;
            data[0]++;
        }
        sprite->pos2.y = -(gSineTable[data[1]] >> 5);
        break;
    case 4:
        if (++data[1] > 40)
            sprite->callback = SpriteCallbackDummy;
        break;
    }
}

static void Load321StartGfx(u16 tileTag, u16 palTag)
{
    struct CompressedSpriteSheet spriteSheet = {sSpriteSheet_321Start, 0xE00, 0};
    struct SpritePalette spritePalette = {sSpritePal_321Start, 0};

    spriteSheet.tag = tileTag;
    spritePalette.tag = palTag;

    LoadCompressedSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
}

static const struct OamData sOamData_Numbers =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct OamData sOamData_Start =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sAnim_Numbers_Three[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Numbers_Two[] =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Numbers_One[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnimTable_Numbers[] =
{
    sAnim_Numbers_Three,
    sAnim_Numbers_Two,
    sAnim_Numbers_One
};

static const union AnimCmd sAnim_StartLeft[] =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StartRight[] =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnimTable_Start[] =
{
    sAnim_StartLeft,
    sAnim_StartRight
};

static const union AffineAnimCmd sAffineAnim_Numbers_0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Numbers_1[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(16, -16, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Numbers_2[] =
{
    AFFINEANIMCMD_FRAME(-18, 18, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Numbers_3[] =
{
    AFFINEANIMCMD_FRAME(  6,  -6, 0, 8),
    AFFINEANIMCMD_FRAME( -4,   4, 0, 8),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnimTable_Numbers[] =
{
    sAffineAnim_Numbers_0,
    sAffineAnim_Numbers_1,
    sAffineAnim_Numbers_2,
    sAffineAnim_Numbers_3
};

static u8 CreateNumberSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority)
{
    struct SpriteTemplate spriteTemplate =
    {
        .oam = &sOamData_Numbers,
        .anims = sAnimTable_Numbers,
        .affineAnims = sAffineAnimTable_Numbers,
        .callback = SpriteCallbackDummy,
    };

    spriteTemplate.tileTag = tileTag;
    spriteTemplate.paletteTag = palTag;
    return CreateSprite(&spriteTemplate, x, y, subpriority);
}

static void CreateStartSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority, s16 *spriteId1, s16 *spriteId2)
{
    struct SpriteTemplate spriteTemplate =
    {
        .oam = &sOamData_Start,
        .anims = sAnimTable_Start,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    };

    spriteTemplate.tileTag = tileTag;
    spriteTemplate.paletteTag = palTag;
    *spriteId1 = CreateSprite(&spriteTemplate, x - 32, y, subpriority);
    *spriteId2 = CreateSprite(&spriteTemplate, x + 32, y, subpriority);

    gSprites[*spriteId1].invisible = TRUE;
    gSprites[*spriteId2].invisible = TRUE;
    StartSpriteAnim(&gSprites[*spriteId2], 1);
}
