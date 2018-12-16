#include "global.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "overworld.h"
#include "random.h"
#include "script.h"
#include "constants/weather.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "gpu_regs.h"

// This file's functions.
void sub_80AC6B4(struct Sprite *);

// EWRAM
EWRAM_DATA static u8 gUnknown_02038BC4 = 0;
EWRAM_DATA static u16 gUnknown_02038BC6 = 0;

// CONST
const u16 gUnknown_0854C290[] = INCBIN_U16("graphics/weather/1.gbapal");
const u16 gUnknown_0854C2B0[] = INCBIN_U16("graphics/weather/2.gbapal");
const u8 gWeatherFog2Tiles[] = INCBIN_U8("graphics/weather/fog2.4bpp");
const u8 gWeatherFog1Tiles[] = INCBIN_U8("graphics/weather/fog1.4bpp");
const u8 gWeatherCloudTiles[] = INCBIN_U8("graphics/weather/cloud.4bpp");
const u8 gWeatherSnow1Tiles[] = INCBIN_U8("graphics/weather/snow0.4bpp");
const u8 gWeatherSnow2Tiles[] = INCBIN_U8("graphics/weather/snow1.4bpp");
const u8 gWeatherBubbleTiles[] = INCBIN_U8("graphics/weather/bubble.4bpp");
const u8 gWeatherAshTiles[] = INCBIN_U8("graphics/weather/ash.4bpp");
const u8 gWeatherRainTiles[] = INCBIN_U8("graphics/weather/rain.4bpp");
const u8 gWeatherSandstormTiles[] = INCBIN_U8("graphics/weather/sandstorm.4bpp");

static const struct Coords16 gUnknown_0854FB50[] =
{
    { 0, 66},
    { 5, 73},
    {10, 78},
};

static const struct SpriteSheet sCloudSpriteSheet = {gWeatherCloudTiles, sizeof(gWeatherCloudTiles), 0x1200};

static const struct OamData gOamData_839A9DC =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd gSpriteAnim_839A9E4[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const gSpriteAnimTable_839A9EC[] =
{
    gSpriteAnim_839A9E4,
};

static const struct SpriteTemplate sCloudSpriteTemplate =
{
    .tileTag = 4608,
    .paletteTag = 4609,
    .oam = &gOamData_839A9DC,
    .anims = gSpriteAnimTable_839A9EC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80AC6B4,
};

//------------------------------------------------------------------------------
// Clouds
//------------------------------------------------------------------------------

void Clouds_InitVars(void)
{
    gWeatherPtr->gammaTargetIndex = 0;
    gWeatherPtr->gammaStepDelay = 20;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->initStep = 0;
    if (gWeatherPtr->cloudSpritesCreated == FALSE)
        Weather_SetBlendCoeffs(0, 16);
}

void Clouds_InitAll(void)
{
    Clouds_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Clouds_Main();
}

void CreateCloudSprites(void);

void Clouds_Main(void)
{
    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateCloudSprites();
        gWeatherPtr->initStep++;
        break;
    case 1:
        Weather_SetTargetBlendCoeffs(12, 8, 1);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (Weather_UpdateBlend())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    }
}

void sub_807E0A0(void);

bool8 Clouds_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 1);
        gWeatherPtr->finishStep++;
        return TRUE;
    case 1:
        if (Weather_UpdateBlend())
        {
            sub_807E0A0();
            gWeatherPtr->finishStep++;
        }
        return TRUE;
    }
    return FALSE;
}

//------------------------------------------------------------------------------
// Weather 2
//------------------------------------------------------------------------------

void Weather2_InitVars(void)
{
    gWeatherPtr->gammaTargetIndex = 0;
    gWeatherPtr->gammaStepDelay = 20;
}

void Weather2_InitAll(void)
{
    Weather2_InitVars();
}

void Weather2_Main(void)
{
}

bool8 Weather2_Finish(void)
{
    return 0;
}

void CreateCloudSprites(void)
{
    u16 i;

    if (gWeatherPtr->cloudSpritesCreated == TRUE)
        return;
    LoadSpriteSheet(&sCloudSpriteSheet);
    LoadCustomWeatherSpritePalette(gUnknown_0854C290);
    for (i = 0; i < 3; i++)
    {
        u8 spriteId = CreateSprite(&sCloudSpriteTemplate, 0, 0, 0xFF);

        if (spriteId != MAX_SPRITES)
        {
            struct Sprite *sprite;

            gWeatherPtr->sprites.s1.cloudSprites[i] = &gSprites[spriteId];
            sprite = gWeatherPtr->sprites.s1.cloudSprites[i];
            sub_8093038(gUnknown_0854FB50[i].x + 7, gUnknown_0854FB50[i].y + 7, &sprite->pos1.x, &sprite->pos1.y);
            sprite->coordOffsetEnabled = TRUE;
        }
        else
        {
            gWeatherPtr->sprites.s1.cloudSprites[i] = NULL;
        }
    }
    gWeatherPtr->cloudSpritesCreated = TRUE;
}

void sub_807E0A0(void)
{
    u16 i;

    if (gWeatherPtr->cloudSpritesCreated == FALSE)
        return;
    for (i = 0; i < 3; i++)
    {
        if (gWeatherPtr->sprites.s1.cloudSprites[i] != NULL)
            DestroySprite(gWeatherPtr->sprites.s1.cloudSprites[i]);
    }
    FreeSpriteTilesByTag(0x1200);
    gWeatherPtr->cloudSpritesCreated = FALSE;
}

void sub_80AC6B4(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 1) & 1;
    if (sprite->data[0] != 0)
        sprite->pos1.x--;
}

//------------------------------------------------------------------------------
// Drought
//------------------------------------------------------------------------------

void Drought_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->gammaTargetIndex = 0;
    gWeatherPtr->gammaStepDelay = 0;
}

void Drought_InitAll(void)
{
    Drought_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Drought_Main();
}

void Drought_Main(void)
{
    switch (gWeatherPtr->initStep)
    {
    case 0:
        if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_CHANGING_WEATHER)
            gWeatherPtr->initStep++;
        break;
    case 1:
        ResetDroughtWeatherPaletteLoading();
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (LoadDroughtWeatherPalettes() == FALSE)
            gWeatherPtr->initStep++;
        break;
    case 3:
        sub_80ABFF0();
        gWeatherPtr->initStep++;
        break;
    case 4:
        sub_80AC01C();
        if (gWeatherPtr->unknown_73C == 6)
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    default:
        sub_80AC01C();
        break;
    }
}

bool8 Drought_Finish(void)
{
    return 0;
}

void task50_0807B6D4(u8);

void sub_80AC81C(void)
{
    CreateTask(task50_0807B6D4, 0x50);
}

#define tState      data[0]
#define tBlendY     data[1]
#define tBlendDelay data[2]
#define tWinRange   data[3]

void task50_0807B6D4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tBlendY = 0;
        task->tBlendDelay = 0;
        task->tWinRange = REG_WININ;
        SetGpuReg(REG_OFFSET_WININ, WIN_RANGE(63, 63));
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        task->tState++;
        // fall through
    case 1:
        task->tBlendY += 3;
        if (task->tBlendY > 16)
            task->tBlendY = 16;
        SetGpuReg(REG_OFFSET_BLDY, task->tBlendY);
        if (task->tBlendY >= 16)
            task->tState++;
        break;
    case 2:
        task->tBlendDelay++;
        if (task->tBlendDelay > 9)
        {
            task->tBlendDelay = 0;
            task->tBlendY--;
            if (task->tBlendY <= 0)
            {
                task->tBlendY = 0;
                task->tState++;
            }
            SetGpuReg(REG_OFFSET_BLDY, task->tBlendY);
        }
        break;
    case 3:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_WININ, task->tWinRange);
        task->tState++;
        break;
    case 4:
        EnableBothScriptContexts();
        DestroyTask(taskId);
        break;
    }
}

#undef tState
#undef tBlendY
#undef tBlendDelay
#undef tWinRange

//------------------------------------------------------------------------------
// Light Rain
//------------------------------------------------------------------------------

void LightRain_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->unknown_6D6 = 0;
    gWeatherPtr->unknown_6DB = 8;
    gWeatherPtr->unknown_6DC = 0;
    gWeatherPtr->unknown_6D9 = 10;
    gWeatherPtr->gammaTargetIndex = 3;
    gWeatherPtr->gammaStepDelay = 20;
    SetRainStrengthFromSoundEffect(SE_T_KOAME);
}

void LightRain_InitAll(void)
{
    LightRain_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        LightRain_Main();
}

void LoadRainSpriteSheet(void);
u8 CreateRainSprite(void);
u8 sub_807E8E8(void);

void LightRain_Main(void)
{
    switch (gWeatherPtr->initStep)
    {
    case 0:
        LoadRainSpriteSheet();
        gWeatherPtr->initStep++;
        break;
    case 1:
        if (CreateRainSprite() == 0)
            gWeatherPtr->initStep++;
        break;
    case 2:
        if (sub_807E8E8() == FALSE)
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    }
}

void DestroyRainSprites(void);

bool8 LightRain_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        if (gWeatherPtr->nextWeather == WEATHER_RAIN_LIGHT
         || gWeatherPtr->nextWeather == WEATHER_RAIN_MED
         || gWeatherPtr->nextWeather == WEATHER_RAIN_HEAVY)
        {
            gWeatherPtr->finishStep = 0xFF;
            return FALSE;
        }
        else
        {
            gWeatherPtr->unknown_6D9 = 0;
            gWeatherPtr->finishStep++;
        }
        // fall through
    case 1:
        if (sub_807E8E8() == FALSE)
        {
            DestroyRainSprites();
            gWeatherPtr->finishStep++;
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

// defined below
extern const s16 gUnknown_0839AABC[][2];
extern const u16 gUnknown_0839AAC4[][2];

void sub_807E4EC(struct Sprite *sprite)
{
    u32 randVal;
    u16 r6;
    s32 r4;
    s32 r0;

    if (sprite->data[1] == 0)
        sprite->data[1] = 361;
    randVal = sprite->data[1] * 1103515245 + 12345;
    sprite->data[1] = ((randVal & 0x7FFF0000) >> 16) % 600;

    r6 = gUnknown_0839AAC4[gWeatherPtr->unknown_6DC][0];

    r4 = sprite->data[1] % 30;
    sprite->data[2] = r4 * 8;  // useless assignment

    r0 = sprite->data[1] / 30;
    sprite->data[3] = r0 * 8;  // useless assignment

    sprite->data[2] = r4;
    sprite->data[2] <<= 7;

    sprite->data[3] = r0;
    sprite->data[3] <<= 7;

    sprite->data[2] -= gUnknown_0839AABC[gWeatherPtr->unknown_6DC][0] * r6;
    sprite->data[3] -= gUnknown_0839AABC[gWeatherPtr->unknown_6DC][1] * r6;

    StartSpriteAnim(sprite, 0);
    sprite->data[4] = 0;
    sprite->coordOffsetEnabled = FALSE;
    sprite->data[0] = r6;
}

void sub_807E5C0(struct Sprite *sprite)
{
    if (sprite->data[4] == 0)
    {
        sprite->data[2] += gUnknown_0839AABC[gWeatherPtr->unknown_6DC][0];
        sprite->data[3] += gUnknown_0839AABC[gWeatherPtr->unknown_6DC][1];
        sprite->pos1.x = sprite->data[2] >> 4;
        sprite->pos1.y = sprite->data[3] >> 4;

        if (sprite->data[5] != 0
         && (sprite->pos1.x >= -8 && sprite->pos1.x <= 248)
         && sprite->pos1.y >= -16 && sprite->pos1.y <= 176)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;

        sprite->data[0]--;
        if (sprite->data[0] == 0)
        {
            StartSpriteAnim(sprite, gWeatherPtr->unknown_6DC + 1);
            sprite->data[4] = 1;
            sprite->pos1.x -= gSpriteCoordOffsetX;
            sprite->pos1.y -= gSpriteCoordOffsetY;
            sprite->coordOffsetEnabled = TRUE;
        }
    }
    else if (sprite->animEnded)
    {
        sprite->invisible = TRUE;
        sub_807E4EC(sprite);
    }
}

void sub_807E6C4(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sub_807E4EC(sprite);
        sprite->callback = sub_807E5C0;
    }
    else
    {
        sprite->data[0]--;
    }
}

void sub_807E6F0(struct Sprite *sprite, u16 b)
{
    u16 r8 = gUnknown_0839AAC4[gWeatherPtr->unknown_6DC][0];
    u16 r6 = b / (gUnknown_0839AAC4[gWeatherPtr->unknown_6DC][1] + r8);
    u16 r4 = b % (gUnknown_0839AAC4[gWeatherPtr->unknown_6DC][1] + r8);

    while (--r6 != 0xFFFF)
        sub_807E4EC(sprite);
    if (r4 < r8)
    {
        while (--r4 != 0xFFFF)
            sub_807E5C0(sprite);
        sprite->data[6] = 0;
    }
    else
    {
        sprite->data[0] = r4 - r8;
        sprite->invisible = TRUE;
        sprite->data[6] = 1;
    }
}

extern const struct SpriteSheet sRainSpriteSheet;  // defined below

void LoadRainSpriteSheet(void)
{
    LoadSpriteSheet(&sRainSpriteSheet);
}

static const struct Coords16 sRainSpriteCoords[] =
{
    {  0,   0},
    {  0, 160},
    {  0,  64},
    {144, 224},
    {144, 128},
    { 32,  32},
    { 32, 192},
    { 32,  96},
    { 72, 128},
    { 72,  32},
    { 72, 192},
    {216,  96},
    {216,   0},
    {104, 160},
    {104,  64},
    {104, 224},
    {144,   0},
    {144, 160},
    {144,  64},
    { 32, 224},
    { 32, 128},
    { 72,  32},
    { 72, 192},
    { 48,  96},
};

static const struct OamData gOamData_839AA68 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 2,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 2,
    .affineParam = 0,
};

static const union AnimCmd gSpriteAnim_839AA70[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gSpriteAnim_839AA78[] =
{
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(40, 2),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_839AA88[] =
{
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const gSpriteAnimTable_839AA98[] =
{
    gSpriteAnim_839AA70,
    gSpriteAnim_839AA78,
    gSpriteAnim_839AA88,
};

static const struct SpriteTemplate sRainSpriteTemplate =
{
    .tileTag = 4614,
    .paletteTag = 4608,
    .oam = &gOamData_839AA68,
    .anims = gSpriteAnimTable_839AA98,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807E5C0,
};

const s16 gUnknown_0839AABC[][2] =
{
	{-104, 208},
	{-160, 320},
};

const u16 gUnknown_0839AAC4[][2] =
{
    {18, 7},
    {12, 10},
};

static const struct SpriteSheet sRainSpriteSheet = {gWeatherRainTiles, sizeof(gWeatherRainTiles), 0x1206};

static const struct OamData gOamData_839AAD4 =
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage gSpriteImageTable_839AADC[] =
{
    {gWeatherSnow1Tiles, sizeof(gWeatherSnow1Tiles)},
    {gWeatherSnow2Tiles, sizeof(gWeatherSnow2Tiles)},
};

static const union AnimCmd gSpriteAnim_839AAEC[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_839AAF4[] =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const gSpriteAnimTable_839AAFC[] =
{
    gSpriteAnim_839AAEC,
    gSpriteAnim_839AAF4,
};

void sub_807ED48(struct Sprite *);
static const struct SpriteTemplate sSnowflakeSpriteTemplate =
{
    .tileTag = 0xFFFF,
    .paletteTag = 4608,
    .oam = &gOamData_839AAD4,
    .anims = gSpriteAnimTable_839AAFC,
    .images = gSpriteImageTable_839AADC,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807ED48,
};

// unused data
static const u16 unusedData_839AB1C[] = {0, 6, 6, 12, 18, 42, 300, 300};

static const struct OamData gOamData_839AB2C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd gSpriteAnim_839AB34[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_839AB3C[] =
{
    ANIMCMD_FRAME(32, 16),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_839AB44[] =
{
    ANIMCMD_FRAME(64, 16),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_839AB4C[] =
{
    ANIMCMD_FRAME(96, 16),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_839AB54[] =
{
    ANIMCMD_FRAME(128, 16),
    ANIMCMD_END,
};

static const union AnimCmd gSpriteAnim_839AB5C[] =
{
    ANIMCMD_FRAME(160, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const gSpriteAnimTable_839AB64[] =
{
    gSpriteAnim_839AB34,
    gSpriteAnim_839AB3C,
    gSpriteAnim_839AB44,
    gSpriteAnim_839AB4C,
    gSpriteAnim_839AB54,
    gSpriteAnim_839AB5C,
};

static const union AffineAnimCmd gSpriteAffineAnim_839AB7C[] =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_839AB8C[] =
{
    gSpriteAffineAnim_839AB7C,
};

static void Fog1SpriteCallback(struct Sprite *);
static const struct SpriteTemplate sFog1SpriteTemplate =
{
    .tileTag = 4609,
    .paletteTag = 4608,
    .oam = &gOamData_839AB2C,
    .anims = gSpriteAnimTable_839AB64,
    .images = NULL,
    .affineAnims = gSpriteAffineAnimTable_839AB8C,
    .callback = Fog1SpriteCallback,
};

bool8 CreateRainSprite(void)
{
    u8 spriteNum;
    u8 spriteId;

    if (gWeatherPtr->rainSpriteCount == 24)
        return FALSE;

    spriteNum = gWeatherPtr->rainSpriteCount;
    spriteId = CreateSpriteAtEnd(&sRainSpriteTemplate,
      sRainSpriteCoords[spriteNum].x, sRainSpriteCoords[spriteNum].y, 78);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[5] = 0;
        gSprites[spriteId].data[1] = spriteNum * 145;
        while (gSprites[spriteId].data[1] >= 600)
            gSprites[spriteId].data[1] -= 600;
        sub_807E4EC(&gSprites[spriteId]);
        sub_807E6F0(&gSprites[spriteId], spriteNum * 9);
        gSprites[spriteId].invisible = TRUE;
        gWeatherPtr->sprites.s1.rainSprites[spriteNum] = &gSprites[spriteId];
    }
    else
    {
        gWeatherPtr->sprites.s1.rainSprites[spriteNum] = NULL;
    }

    if (++gWeatherPtr->rainSpriteCount == 24)
    {
        u16 i;

        for (i = 0; i < 24; i++)
        {
            if (gWeatherPtr->sprites.s1.rainSprites[i] != NULL)
            {
                if (gWeatherPtr->sprites.s1.rainSprites[i]->data[6] == 0)
                    gWeatherPtr->sprites.s1.rainSprites[i]->callback = sub_807E5C0;
                else
                    gWeatherPtr->sprites.s1.rainSprites[i]->callback = sub_807E6C4;
            }
        }
        return FALSE;
    }
    return TRUE;
}

bool8 sub_807E8E8(void)
{
    if (gWeatherPtr->unknown_6D8 == gWeatherPtr->unknown_6D9)
        return FALSE;

    if (++gWeatherPtr->unknown_6D6 > gWeatherPtr->unknown_6DB)
    {
        gWeatherPtr->unknown_6D6 = 0;
        if (gWeatherPtr->unknown_6D8 < gWeatherPtr->unknown_6D9)
        {
            gWeatherPtr->sprites.s1.rainSprites[gWeatherPtr->unknown_6D8++]->data[5] = 1;
        }
        else
        {
            gWeatherPtr->unknown_6D8--;
            gWeatherPtr->sprites.s1.rainSprites[gWeatherPtr->unknown_6D8]->data[5] = 0;
            gWeatherPtr->sprites.s1.rainSprites[gWeatherPtr->unknown_6D8]->invisible = TRUE;
        }
    }
    return TRUE;
}

void DestroyRainSprites(void)
{
    u16 i;

    for (i = 0; i < gWeatherPtr->rainSpriteCount; i++)
    {
        if (gWeatherPtr->sprites.s1.rainSprites[i] != NULL)
            DestroySprite(gWeatherPtr->sprites.s1.rainSprites[i]);
    }
    gWeatherPtr->rainSpriteCount = 0;
    FreeSpriteTilesByTag(0x1206);
}

//------------------------------------------------------------------------------
// Snow
//------------------------------------------------------------------------------

void Snow_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->gammaTargetIndex = 3;
    gWeatherPtr->gammaStepDelay = 20;
    gWeatherPtr->unknown_6E5 = 16;
    gWeatherPtr->unknown_6E0 = 0;
}

void Snow_Main(void);
void sub_807ED48(struct Sprite *);

void Snow_InitAll(void)
{
    Snow_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
    {
        u16 i;

        Snow_Main();
        for (i = 0; i < gWeatherPtr->snowflakeSpriteCount; i++)
        {
            sub_807ED48(gWeatherPtr->sprites.s1.snowflakeSprites[i]);
        }
    }
}

u8 snowflakes_progress(void);

void Snow_Main(void)
{
    if (gWeatherPtr->initStep == 0 && snowflakes_progress() == FALSE)
    {
        gWeatherPtr->weatherGfxLoaded = TRUE;
        gWeatherPtr->initStep++;
    }
}

bool8 Snow_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        gWeatherPtr->unknown_6E5 = 0;
        gWeatherPtr->unknown_6E0 = 0;
        gWeatherPtr->finishStep++;
        // fall through
    case 1:
        if (snowflakes_progress() == FALSE)
        {
            gWeatherPtr->finishStep++;
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

bool8 CreateSnowflakeSprite(void);
bool8 RemoveSnowflakeSprite(void);

bool8 snowflakes_progress(void)
{
    if (gWeatherPtr->snowflakeSpriteCount == gWeatherPtr->unknown_6E5)
        return FALSE;

    gWeatherPtr->unknown_6E0++;
    if (gWeatherPtr->unknown_6E0 > 36)
    {
        gWeatherPtr->unknown_6E0 = 0;
        if (gWeatherPtr->snowflakeSpriteCount < gWeatherPtr->unknown_6E5)
            CreateSnowflakeSprite();
        else
            RemoveSnowflakeSprite();
    }
    return (gWeatherPtr->snowflakeSpriteCount != gWeatherPtr->unknown_6E5);
}

void sub_807EC40(struct Sprite *);

bool8 CreateSnowflakeSprite(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSnowflakeSpriteTemplate, 0, 0, 78);

    if (spriteId == MAX_SPRITES)
        return FALSE;
    gSprites[spriteId].data[4] = gWeatherPtr->snowflakeSpriteCount;
    sub_807EC40(&gSprites[spriteId]);
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    gWeatherPtr->sprites.s1.snowflakeSprites[gWeatherPtr->snowflakeSpriteCount++] = &gSprites[spriteId];
    return TRUE;
}

bool8 RemoveSnowflakeSprite(void)
{
    if (gWeatherPtr->snowflakeSpriteCount != 0)
    {
        DestroySprite(gWeatherPtr->sprites.s1.snowflakeSprites[--gWeatherPtr->snowflakeSpriteCount]);
        return TRUE;
    }
    return FALSE;
}

void sub_807EC40(struct Sprite *sprite)
{
    u16 r4 = ((sprite->data[4] * 5) & 7) * 30 + (Random() % 30);
    u16 r6;

    sprite->pos1.y = -3 - (gSpriteCoordOffsetY + sprite->centerToCornerVecY);
    sprite->pos1.x = r4 - (gSpriteCoordOffsetX + sprite->centerToCornerVecX);
    sprite->data[0] = sprite->pos1.y * 128;
    sprite->pos2.x = 0;
    r6 = Random();
    sprite->data[1] = (r6 & 3) * 5 + 64;
    sprite->data[7] = (r6 & 3) * 5 + 64;
    StartSpriteAnim(sprite, (r6 & 1) ? 0 : 1);
    sprite->data[3] = 0;
    sprite->data[2] = ((r6 & 3) == 0) ? 2 : 1;
    sprite->data[6] = (r6 & 0x1F) + 210;
    sprite->data[5] = 0;
}

void sub_807ECEC(struct Sprite *sprite)
{
    if (gWeatherPtr->unknown_6E2 > 18)
    {
        sprite->invisible = FALSE;
        sprite->callback = sub_807ED48;
        sprite->pos1.y = 0xFA - (gSpriteCoordOffsetY + sprite->centerToCornerVecY);
        sprite->data[0] = sprite->pos1.y * 128;
        gWeatherPtr->unknown_6E2 = 0;
    }
}

void sub_807ED48(struct Sprite *sprite)
{
    s16 r3;
    s16 r2;

    sprite->data[0] += sprite->data[1];
    sprite->pos1.y = sprite->data[0] >> 7;
    sprite->data[3] = (sprite->data[3] + sprite->data[2]) & 0xFF;
    sprite->pos2.x = gSineTable[sprite->data[3]] / 64;

    r3 = (sprite->pos1.x + sprite->centerToCornerVecX + gSpriteCoordOffsetX) & 0x1FF;
    if (r3 & 0x100)
        r3 |= -0x100;  // hmm... what is this?
    if (r3 < -3)
        sprite->pos1.x = 242 - (gSpriteCoordOffsetX + sprite->centerToCornerVecX);
    else if (r3 > 242)
        sprite->pos1.x = -3 - (gSpriteCoordOffsetX + sprite->centerToCornerVecX);

    r2 = (sprite->pos1.y + sprite->centerToCornerVecY + gSpriteCoordOffsetY) & 0xFF;
    if (r2 > 163 && r2 < 171)
    {
        sprite->pos1.y = 250 - (gSpriteCoordOffsetY + sprite->centerToCornerVecY);
        sprite->data[0] = sprite->pos1.y * 128;
        sprite->data[5] = 0;
        sprite->data[6] = 220;
    }
    else if (r2 > 242 && r2 < 250)
    {
        sprite->pos1.y = 163;
        sprite->data[0] = sprite->pos1.y * 128;
        sprite->data[5] = 0;
        sprite->data[6] = 220;
        sprite->invisible = TRUE;
        sprite->callback = sub_807ECEC;
    }

    sprite->data[5]++;
    if (sprite->data[5] == sprite->data[6])
    {
        sub_807EC40(sprite);
        sprite->pos1.y = 250;
        sprite->invisible = TRUE;
        sprite->callback = sub_807ECEC;
    }
}

//------------------------------------------------------------------------------
// Medium Rain
//------------------------------------------------------------------------------

void MedRain_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->unknown_6D6 = 0;
    gWeatherPtr->unknown_6DB = 4;
    gWeatherPtr->unknown_6DC = 0;
    gWeatherPtr->unknown_6D9 = 16;
    gWeatherPtr->gammaTargetIndex = 3;
    gWeatherPtr->gammaStepDelay = 20;
    gWeatherPtr->weatherGfxLoaded = FALSE;  // duplicate assignment
    gWeatherPtr->unknown_6ED = 0;
    SetRainStrengthFromSoundEffect(SE_T_AME);
}

void Rain_Main(void);

void MedRain_InitAll(void)
{
    MedRain_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Rain_Main();
}

//------------------------------------------------------------------------------
// Heavy Rain
//------------------------------------------------------------------------------

void HeavyRain_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->unknown_6D6 = 0;
    gWeatherPtr->unknown_6DB = 4;
    gWeatherPtr->unknown_6DC = 1;
    gWeatherPtr->unknown_6D9 = 24;
    gWeatherPtr->gammaTargetIndex = 3;
    gWeatherPtr->gammaStepDelay = 20;
    gWeatherPtr->weatherGfxLoaded = FALSE;  // duplicate assignment
    SetRainStrengthFromSoundEffect(SE_T_OOAME);
}

void HeavyRain_InitAll(void)
{
    HeavyRain_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Rain_Main();
}

void UpdateThunderSound(void);
void SetThunderCounter(u16);

void Rain_Main(void)
{
    UpdateThunderSound();
    switch (gWeatherPtr->initStep)
    {
    case 0:
        LoadRainSpriteSheet();
        gWeatherPtr->initStep++;
        break;
    case 1:
        if (CreateRainSprite())
            break;
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (sub_807E8E8())
            break;
        gWeatherPtr->weatherGfxLoaded = TRUE;
        gWeatherPtr->initStep++;
        break;
    case 3:
        if (gWeatherPtr->palProcessingState == WEATHER_PAL_STATE_CHANGING_WEATHER)
            break;
        gWeatherPtr->initStep = 6;
        break;
    case 4:
        gWeatherPtr->unknown_6EA = 1;
        gWeatherPtr->unknown_6E6 = (Random() % 360) + 360;
        gWeatherPtr->initStep++;
        // fall through
    case 5:
        if (--gWeatherPtr->unknown_6E6 != 0)
            break;
        gWeatherPtr->initStep++;
        break;
    case 6:
        gWeatherPtr->unknown_6EA = 1;
        gWeatherPtr->unknown_6EB = Random() % 2;
        gWeatherPtr->initStep++;
        break;
    case 7:
        gWeatherPtr->unknown_6EC = (Random() & 1) + 1;
        gWeatherPtr->initStep++;
        // fall through
    case 8:
        sub_80ABC48(19);
        if (gWeatherPtr->unknown_6EB == 0 && gWeatherPtr->unknown_6EC == 1)
            SetThunderCounter(20);
        gWeatherPtr->unknown_6E6 = (Random() % 3) + 6;
        gWeatherPtr->initStep++;
        break;
    case 9:
        if (--gWeatherPtr->unknown_6E6 != 0)
            break;
        sub_80ABC48(3);
        gWeatherPtr->unknown_6EA = 1;
        if (--gWeatherPtr->unknown_6EC != 0)
        {
            gWeatherPtr->unknown_6E6 = (Random() % 16) + 60;
            gWeatherPtr->initStep = 10;
        }
        else if (gWeatherPtr->unknown_6EB == 0)
        {
            gWeatherPtr->initStep = 4;
        }
        else
        {
            gWeatherPtr->initStep = 11;
        }
        break;
    case 10:
        if (--gWeatherPtr->unknown_6E6 != 0)
            break;
        gWeatherPtr->initStep = 8;
        break;
    case 11:
        gWeatherPtr->unknown_6E6 = (Random() % 16) + 60;
        gWeatherPtr->initStep++;
        break;
    case 12:
        if (--gWeatherPtr->unknown_6E6 != 0)
            break;
        SetThunderCounter(100);
        sub_80ABC48(19);
        // Why use "% 16" everywhere else and "& 0xF" here. So dumb.
        gWeatherPtr->unknown_6E6 = (Random() & 0xF) + 30;
        gWeatherPtr->initStep++;
        break;
    case 13:
        if (--gWeatherPtr->unknown_6E6 != 0)
            break;
        sub_80ABC7C(19, 3, 5);
        gWeatherPtr->initStep++;
        break;
    case 14:
        if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_IDLE)
            break;
        gWeatherPtr->unknown_6EA = 1;
        gWeatherPtr->initStep = 4;
        break;
    }
}

bool8 Rain_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        gWeatherPtr->unknown_6EA = 0;
        gWeatherPtr->finishStep++;
        // fall through
    case 1:
        Rain_Main();
        if (gWeatherPtr->unknown_6EA != 0)
        {
            if (gWeatherPtr->nextWeather == WEATHER_RAIN_LIGHT
             || gWeatherPtr->nextWeather == WEATHER_RAIN_MED
             || gWeatherPtr->nextWeather == WEATHER_RAIN_HEAVY)
                return FALSE;
            gWeatherPtr->unknown_6D9 = 0;
            gWeatherPtr->finishStep++;
        }
        break;
    case 2:
        if (sub_807E8E8())
            break;
        DestroyRainSprites();
        gWeatherPtr->unknown_6ED = 0;
        gWeatherPtr->finishStep++;
        return FALSE;
    default:
        return FALSE;
    }
    return TRUE;
}

void SetThunderCounter(u16 max)
{
    if (gWeatherPtr->unknown_6ED == 0)
    {
        gWeatherPtr->thunderCounter = Random() % max;
        gWeatherPtr->unknown_6ED = 1;
    }
}

void UpdateThunderSound(void)
{
    if (gWeatherPtr->unknown_6ED == 1)
    {
        if (gWeatherPtr->thunderCounter == 0)
        {
            if (IsSEPlaying())
                return;
            if (Random() & 1)
                PlaySE(SE_T_KAMI);
            else
                PlaySE(SE_T_KAMI2);
            gWeatherPtr->unknown_6ED = 0;
        }
        else
        {
            gWeatherPtr->thunderCounter--;
        }
    }
}

//------------------------------------------------------------------------------
// Fog 1
//------------------------------------------------------------------------------

void Fog1_Main(void);
static void CreateFog1Sprites(void);
static void DestroyFog1Sprites(void);

void Fog1_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->gammaTargetIndex = 0;
    gWeatherPtr->gammaStepDelay = 20;
    if (gWeatherPtr->fog1SpritesCreated == 0)
    {
        gWeatherPtr->unknown_6F0 = 0;
        gWeatherPtr->unknown_6F2 = 0;
        gWeatherPtr->fog1ScrollPosX = 0;
        Weather_SetBlendCoeffs(0, 16);
    }
}

void Fog1_InitAll(void)
{
    Fog1_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Fog1_Main();
}

void Fog1_Main(void)
{
    gWeatherPtr->fog1ScrollPosX = (gSpriteCoordOffsetX - gWeatherPtr->unknown_6F2) & 0xFF;
    if (++gWeatherPtr->unknown_6F0 > 3)
    {
        gWeatherPtr->unknown_6F0 = 0;
        gWeatherPtr->unknown_6F2++;
    }
    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateFog1Sprites();
        if (gWeatherPtr->currWeather == WEATHER_FOG_1)
            Weather_SetTargetBlendCoeffs(12, 8, 3);
        else
            Weather_SetTargetBlendCoeffs(4, 16, 0);
        gWeatherPtr->initStep++;
        break;
    case 1:
        if (Weather_UpdateBlend())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    }
}

bool8 Fog1_Finish(void)
{
    gWeatherPtr->fog1ScrollPosX = (gSpriteCoordOffsetX - gWeatherPtr->unknown_6F2) & 0xFF;
    if (++gWeatherPtr->unknown_6F0 > 3)
    {
        gWeatherPtr->unknown_6F0 = 0;
        gWeatherPtr->unknown_6F2++;
    }
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 3);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->finishStep++;
        break;
    case 2:
        DestroyFog1Sprites();
        gWeatherPtr->finishStep++;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

#define sprColumn data[0]

static void Fog1SpriteCallback(struct Sprite *sprite)
{
    sprite->pos2.y = (u8)gSpriteCoordOffsetY;
    sprite->pos1.x = gWeatherPtr->fog1ScrollPosX + 32 + sprite->sprColumn * 64;
    if (sprite->pos1.x > 0x10F)
    {
        sprite->pos1.x = 480 + gWeatherPtr->fog1ScrollPosX - (4 - sprite->sprColumn) * 64;
        sprite->pos1.x &= 0x1FF;
    }
}

static void CreateFog1Sprites(void)
{
    u16 i;

    if (!gWeatherPtr->fog1SpritesCreated)
    {
        struct SpriteSheet fog1SpriteSheet = {gWeatherFog1Tiles, sizeof(gWeatherFog1Tiles), 0x1201};

        LoadSpriteSheet(&fog1SpriteSheet);
        for (i = 0; i < 20; i++)
        {
            u8 spriteId = CreateSpriteAtEnd(&sFog1SpriteTemplate, 0, 0, 0xFF);

            if (spriteId != MAX_SPRITES)
            {
                struct Sprite *sprite = &gSprites[spriteId];

                sprite->sprColumn = i % 5;
                sprite->pos1.x = (i % 5) * 64 + 32;
                sprite->pos1.y = (i / 5) * 64 + 32;
                gWeatherPtr->sprites.s2.fog1Sprites[i] = sprite;
            }
            else
            {
                gWeatherPtr->sprites.s2.fog1Sprites[i] = NULL;
            }
        }
        gWeatherPtr->fog1SpritesCreated = TRUE;
    }
}

#undef sprColumn

static void DestroyFog1Sprites(void)
{
    u16 i;

    if (gWeatherPtr->fog1SpritesCreated)
    {
        for (i = 0; i < 20; i++)
        {
            if (gWeatherPtr->sprites.s2.fog1Sprites[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.fog1Sprites[i]);
        }
        FreeSpriteTilesByTag(0x1201);
        gWeatherPtr->fog1SpritesCreated = 0;
    }
}

//------------------------------------------------------------------------------
// Volcanic ash
//------------------------------------------------------------------------------

void Ash_Main(void);
void LoadAshSpriteSheet(void);
void CreateAshSprites(void);
void DestroyAshSprites(void);

void Ash_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->gammaTargetIndex = 0;
    gWeatherPtr->gammaStepDelay = 20;
    gWeatherPtr->unknown_6FE = 20;
    if (!gWeatherPtr->ashSpritesCreated)
    {
        Weather_SetBlendCoeffs(0, 16);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(64, 63));  // Those aren't even valid coefficients!
    }
}

void Ash_InitAll(void)
{
    Ash_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Ash_Main();
}

void Ash_Main(void)
{
    gWeatherPtr->unknown_6FC = gSpriteCoordOffsetX & 0x1FF;
    while (gWeatherPtr->unknown_6FC > 0xEF)
        gWeatherPtr->unknown_6FC -= 0xF0;
    switch (gWeatherPtr->initStep)
    {
    case 0:
        LoadAshSpriteSheet();
        gWeatherPtr->initStep++;
        break;
    case 1:
        if (!gWeatherPtr->ashSpritesCreated)
            CreateAshSprites();
        Weather_SetTargetBlendCoeffs(16, 0, 1);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->weatherGfxLoaded = TRUE;
        gWeatherPtr->initStep++;
        break;
    default:
        Weather_UpdateBlend();
        break;
    }
}

bool8 Ash_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 1);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (!Weather_UpdateBlend())
            break;
        DestroyAshSprites();
        gWeatherPtr->finishStep++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        gWeatherPtr->finishStep++;
        return FALSE;
    default:
        return FALSE;
    }
    return TRUE;
}

static const struct SpriteSheet sAshSpriteSheet = {gWeatherAshTiles, sizeof(gWeatherAshTiles), 0x1202};

void LoadAshSpriteSheet(void)
{
    LoadSpriteSheet(&sAshSpriteSheet);
}

const struct OamData gOamData_839ABB8 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 15,
    .affineParam = 0,
};

const union AnimCmd gSpriteAnim_839ABC0[] =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(64, 60),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const gSpriteAnimTable_839ABCC[] =
{
    gSpriteAnim_839ABC0,
};

void sub_807FAA8(struct Sprite *);
static const struct SpriteTemplate sAshSpriteTemplate =
{
    .tileTag = 4610,
    .paletteTag = 4608,
    .oam = &gOamData_839ABB8,
    .anims = gSpriteAnimTable_839ABCC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_807FAA8,
};

void CreateAshSprites(void)
{
    u8 i;

    if (!gWeatherPtr->ashSpritesCreated)
    {
        for (i = 0; i < 20; i++)
        {
            u8 spriteId = CreateSpriteAtEnd(&sAshSpriteTemplate, 0, 0, 0x4E);

            if (spriteId != MAX_SPRITES)
            {
                struct Sprite *sprite = &gSprites[spriteId];

                sprite->data[1] = 0;
                sprite->data[2] = (u8)(i % 5);
                sprite->data[3] = (u8)(i / 5);
                sprite->data[0] = sprite->data[3] * 64 + 32;
                gWeatherPtr->sprites.s2.ashSprites[i] = sprite;
            }
            else
            {
                gWeatherPtr->sprites.s2.ashSprites[i] = NULL;
            }
        }
        gWeatherPtr->ashSpritesCreated = TRUE;
    }
}

void DestroyAshSprites(void)
{
    u16 i;

    if (gWeatherPtr->ashSpritesCreated)
    {
        for (i = 0; i < 20; i++)
        {
            if (gWeatherPtr->sprites.s2.ashSprites[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.ashSprites[i]);
        }
        FreeSpriteTilesByTag(0x1202);
        gWeatherPtr->ashSpritesCreated = FALSE;
    }
}

void sub_807FAA8(struct Sprite *sprite)
{
    sprite->data[1]++;
    if (sprite->data[1] > 5)
    {
        sprite->data[1] = 0;
        sprite->data[0]++;
    }
    sprite->pos1.y = gSpriteCoordOffsetY + sprite->data[0];
    sprite->pos1.x = gWeatherPtr->unknown_6FC + 32 + sprite->data[2] * 64;
    if (sprite->pos1.x > 271)
    {
        sprite->pos1.x = gWeatherPtr->unknown_6FC + 0x1E0 - (4 - sprite->data[2]) * 64;
        sprite->pos1.x &= 0x1FF;
    }
}

//------------------------------------------------------------------------------
// Fog 2
//------------------------------------------------------------------------------

void Fog2_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = 0;
    gWeatherPtr->gammaTargetIndex = 0;
    gWeatherPtr->gammaStepDelay = 20;
    gWeatherPtr->unknown_6F0 = 0;
    gWeatherPtr->unknown_6F2 = 1;
    if (gWeatherPtr->fog2SpritesCreated == 0)
    {
        gWeatherPtr->unknown_71C = 0;
        gWeatherPtr->unknown_71E = 0;
        gWeatherPtr->unknown_720 = 0;
        gWeatherPtr->unknown_722 = 0;
        gWeatherPtr->unknown_718 = 0;
        gWeatherPtr->unknown_71A = 0;
        Weather_SetBlendCoeffs(0, 16);
    }
}

void Fog2_Main(void);

void Fog2_InitAll(void)
{
    Fog2_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Fog2_Main();
}

void sub_807FC9C(void);
void CreateFog2Sprites(void);

void Fog2_Main(void)
{
    sub_807FC9C();
    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateFog2Sprites();
        gWeatherPtr->initStep++;
        break;
    case 1:
        Weather_SetTargetBlendCoeffs(12, 8, 8);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->weatherGfxLoaded = TRUE;
        gWeatherPtr->initStep++;
        break;
    }
}

void DestroyFog2Sprites(void);

bool8 Fog2_Finish(void)
{
    sub_807FC9C();
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 1);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->finishStep++;
        break;
    case 2:
        DestroyFog2Sprites();
        gWeatherPtr->finishStep++;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

void sub_807FC9C(void)
{
    if (++gWeatherPtr->unknown_71C > 2)
    {
        gWeatherPtr->unknown_720++;
        gWeatherPtr->unknown_71C = 0;
    }

    if (++gWeatherPtr->unknown_71E > 4)
    {
        gWeatherPtr->unknown_722++;
        gWeatherPtr->unknown_71E = 0;
    }

    gWeatherPtr->unknown_718 = (gSpriteCoordOffsetX - gWeatherPtr->unknown_720) & 0xFF;
    gWeatherPtr->unknown_71A = gSpriteCoordOffsetY + gWeatherPtr->unknown_722;
}

extern const struct SpriteTemplate sFog2SpriteTemplate;  // defined below

void CreateFog2Sprites(void)
{
    u16 i;

    if (!gWeatherPtr->fog2SpritesCreated)
    {
        struct SpriteSheet fog2SpriteSheet = {gWeatherFog2Tiles, sizeof(gWeatherFog2Tiles), 0x1203};

        LoadSpriteSheet(&fog2SpriteSheet);
        for (i = 0; i < 20; i++)
        {
            u8 spriteId = CreateSpriteAtEnd(&sFog2SpriteTemplate, 0, (i / 5) * 64, 0xFF);

            if (spriteId != MAX_SPRITES)
            {
                struct Sprite *sprite = &gSprites[spriteId];

                sprite->data[0] = i % 5;
                sprite->data[1] = i / 5;
                gWeatherPtr->sprites.s2.fog2Sprites[i] = sprite;
            }
            else
            {
                gWeatherPtr->sprites.s2.fog2Sprites[i] = NULL;
            }
        }
        gWeatherPtr->fog2SpritesCreated = TRUE;
    }
}

const struct OamData gOamData_839ABF0 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

const union AnimCmd gSpriteAnim_839ABF8[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

const union AnimCmd *const gSpriteAnimTable_839AC00[] =
{
    gSpriteAnim_839ABF8,
};

void Fog2SpriteCallback(struct Sprite *);
const struct SpriteTemplate sFog2SpriteTemplate =
{
    .tileTag = 4611,
    .paletteTag = 4608,
    .oam = &gOamData_839ABF0,
    .anims = gSpriteAnimTable_839AC00,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = Fog2SpriteCallback,
};

void DestroyFog2Sprites(void)
{
    u16 i;

    if (gWeatherPtr->fog2SpritesCreated)
    {
        for (i = 0; i < 20; i++)
        {
            if (gWeatherPtr->sprites.s2.fog2Sprites[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.fog2Sprites[i]);
        }
        FreeSpriteTilesByTag(0x1203);
        gWeatherPtr->fog2SpritesCreated = FALSE;
    }
}

void Fog2SpriteCallback(struct Sprite *sprite)
{
    sprite->pos2.y = gWeatherPtr->unknown_71A;
    sprite->pos1.x = gWeatherPtr->unknown_718 + 32 + sprite->data[0] * 64;
    if (sprite->pos1.x > 271)
    {
        sprite->pos1.x = gWeatherPtr->unknown_718 + 0x1E0 - (4 - sprite->data[0]) * 64;
        sprite->pos1.x &= 0x1FF;
    }
}

//------------------------------------------------------------------------------
// Sandstorm
//------------------------------------------------------------------------------

void Sandstorm_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = 0;
    gWeatherPtr->gammaTargetIndex = 0;
    gWeatherPtr->gammaStepDelay = 20;
    if (gWeatherPtr->sandstormSprites1Created == 0)
    {
        gWeatherPtr->unknown_704 = gWeatherPtr->unknown_708 = 0;
        gWeatherPtr->unknown_712 = 8;
        gWeatherPtr->unknown_714 = 0;
        // Dead code. How does the compiler not optimize this out?
        if (gWeatherPtr->unknown_712 > 0x5F)
            gWeatherPtr->unknown_712 = 0x80 - gWeatherPtr->unknown_712;
        Weather_SetBlendCoeffs(0, 16);
    }
}

void Sandstorm_Main(void);

void Sandstorm_InitAll(void)
{
    Sandstorm_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Sandstorm_Main();
}

void sub_808002C(void);
void sub_8080064(void);
void CreateSandstormSprites_1(void);
void CreateSandstormSprites_2(void);

void Sandstorm_Main(void)
{
    sub_8080064();
    sub_808002C();
    if (gWeatherPtr->unknown_712 > 0x5F)
        gWeatherPtr->unknown_712 = 32;
    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateSandstormSprites_1();
        CreateSandstormSprites_2();
        gWeatherPtr->initStep++;
        break;
    case 1:
        Weather_SetTargetBlendCoeffs(16, 0, 0);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->weatherGfxLoaded = TRUE;
        gWeatherPtr->initStep++;
        break;
    }
}

void sub_80800E4(void);

bool8 Sandstorm_Finish(void)
{
    sub_8080064();
    sub_808002C();
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 0);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->finishStep++;
        break;
    case 2:
        sub_80800E4();
        gWeatherPtr->finishStep++;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

void sub_808002C(void)
{
    if (gWeatherPtr->unknown_714++ > 4)
    {
        gWeatherPtr->unknown_712++;
        gWeatherPtr->unknown_714 = 0;
    }
}

void sub_8080064(void)
{
    gWeatherPtr->unknown_704 -= gSineTable[gWeatherPtr->unknown_712] * 4;
    gWeatherPtr->unknown_708 -= gSineTable[gWeatherPtr->unknown_712];
    gWeatherPtr->unknown_70E = (gSpriteCoordOffsetX + (gWeatherPtr->unknown_704 >> 8)) & 0xFF;
    gWeatherPtr->unknown_710 = gSpriteCoordOffsetY + (gWeatherPtr->unknown_708 >> 8);
}

void sub_80800E4(void)
{
    u16 i;

    if (gWeatherPtr->sandstormSprites1Created)
    {
        for (i = 0; i < 20; i++)
        {
            if (gWeatherPtr->sprites.s2.sandstormSprites1[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.sandstormSprites1[i]);
        }
        gWeatherPtr->sandstormSprites1Created = FALSE;
        FreeSpriteTilesByTag(0x1204);
    }

    if (gWeatherPtr->sandstormSprites2Created)
    {
        for (i = 0; i < 5; i++)
        {
            if (gWeatherPtr->sprites.s2.sandstormSprites2[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.sandstormSprites2[i]);
        }
        gWeatherPtr->sandstormSprites2Created = FALSE;
    }
}

const struct OamData gOamData_839AC1C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 1,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

const union AnimCmd gSpriteAnim_839AC24[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

const union AnimCmd gSpriteAnim_839AC2C[] =
{
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

const union AnimCmd *const gSpriteAnimTable_839AC34[] =
{
    gSpriteAnim_839AC24,
    gSpriteAnim_839AC2C,
};

void SandstormSpriteCallback1(struct Sprite *);
const struct SpriteTemplate sSandstormSpriteTemplate =
{
    .tileTag = 4612,
    .paletteTag = 4609,
    .oam = &gOamData_839AC1C,
    .anims = gSpriteAnimTable_839AC34,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SandstormSpriteCallback1,
};

static const struct SpriteSheet sSandstormSpriteSheet = {gWeatherSandstormTiles, sizeof(gWeatherSandstormTiles), 0x1204};

void CreateSandstormSprites_1(void)
{
    u16 i;

    if (!gWeatherPtr->sandstormSprites1Created)
    {
        LoadSpriteSheet(&sSandstormSpriteSheet);
        LoadCustomWeatherSpritePalette(gUnknown_0854C2B0);
        for (i = 0; i < 20; i++)
        {
            u8 spriteId = CreateSpriteAtEnd(&sSandstormSpriteTemplate, 0, (i / 5) * 64, 1);

            if (spriteId != MAX_SPRITES)
            {
                gWeatherPtr->sprites.s2.sandstormSprites1[i] = &gSprites[spriteId];
                gWeatherPtr->sprites.s2.sandstormSprites1[i]->data[0] = i % 5;
                gWeatherPtr->sprites.s2.sandstormSprites1[i]->data[1] = i / 5;
            }
            else
            {
                gWeatherPtr->sprites.s2.sandstormSprites1[i] = NULL;
            }
        }
        gWeatherPtr->sandstormSprites1Created = TRUE;
    }
}

const u16 gUnknown_0839AC5C[] = {0,	120, 80, 160, 40, 0};

void SandstormSpriteCallback2(struct Sprite *);

void CreateSandstormSprites_2(void)
{
    u16 i;

    if (!gWeatherPtr->sandstormSprites2Created)
    {
        for (i = 0; i < 5; i++)
        {
            u8 spriteId = CreateSpriteAtEnd(&sSandstormSpriteTemplate, i * 48 + 24, 208, 1);

            if (spriteId != MAX_SPRITES)
            {
                gWeatherPtr->sprites.s2.sandstormSprites2[i] = &gSprites[spriteId];
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->oam.size = 2;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[1] = i * 51;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[0] = 8;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[2] = 0;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[4] = 0x6730;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[3] = gUnknown_0839AC5C[i];
                StartSpriteAnim(gWeatherPtr->sprites.s2.sandstormSprites2[i], 1);
                CalcCenterToCornerVec(gWeatherPtr->sprites.s2.sandstormSprites2[i], 0, 2, 0);
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->callback = SandstormSpriteCallback2;
            }
            else
            {
                gWeatherPtr->sprites.s2.sandstormSprites2[i] = NULL;
            }
            gWeatherPtr->sandstormSprites2Created = TRUE;
        }
    }
}

void SandstormSpriteCallback1(struct Sprite *sprite)
{
    sprite->pos2.y = gWeatherPtr->unknown_710;
    sprite->pos1.x = gWeatherPtr->unknown_70E + 32 + sprite->data[0] * 64;
    if (sprite->pos1.x > 271)
    {
        sprite->pos1.x = gWeatherPtr->unknown_70E + 0x1E0 - (4 - sprite->data[0]) * 64;
        sprite->pos1.x &= 0x1FF;
    }
}

void SandstormSpriteCallback3(struct Sprite *);

void SandstormSpriteCallback2(struct Sprite *sprite)
{
    if (--sprite->data[3] == -1)
        sprite->callback = SandstormSpriteCallback3;
}

void SandstormSpriteCallback3(struct Sprite *sprite)
{
    u32 x;
    u32 y;

    if (--sprite->pos1.y < -48)
    {
        sprite->pos1.y = 208;
        sprite->data[0] = 4;
    }
    x = sprite->data[0] * gSineTable[sprite->data[1]];
    y = sprite->data[0] * gSineTable[sprite->data[1] + 64];
    sprite->pos2.x = x >> 8;
    sprite->pos2.y = y >> 8;
    sprite->data[1] = (sprite->data[1] + 10) & 0xFF;
    if (++sprite->data[2] > 8)
    {
        sprite->data[2] = 0;
        sprite->data[0]++;
    }
}

//------------------------------------------------------------------------------
// Shade
//------------------------------------------------------------------------------

void Shade_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->gammaTargetIndex = 3;
    gWeatherPtr->gammaStepDelay = 20;
}

void Shade_InitAll(void)
{
    Shade_InitVars();
}

void Shade_Main(void)
{
}

bool8 Shade_Finish(void)
{
    return FALSE;
}

//------------------------------------------------------------------------------
// Weather 14
//------------------------------------------------------------------------------

const u8 gUnknown_0839AC68[] = {40, 90, 60, 90, 2, 60, 40, 30};

const struct SpriteSheet gWeatherBubbleSpriteSheet = {gWeatherBubbleTiles, sizeof(gWeatherBubbleTiles), 0x1205};

void Bubbles_InitVars(void)
{
    Fog1_InitVars();
    if (gWeatherPtr->unknown_72E == 0)
    {
        LoadSpriteSheet(&gWeatherBubbleSpriteSheet);
        gWeatherPtr->unknown_728 = 0;
        gWeatherPtr->unknown_726 = gUnknown_0839AC68[0];
        gWeatherPtr->unknown_72A = 0;
        gWeatherPtr->unknown_72C = 0;
    }
}

void Bubbles_Main(void);

void Bubbles_InitAll(void)
{
    Bubbles_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Bubbles_Main();
}

void sub_8080588(u16);

void Bubbles_Main(void)
{
    Fog1_Main();
    if (++gWeatherPtr->unknown_726 > gUnknown_0839AC68[gWeatherPtr->unknown_728])
    {
        gWeatherPtr->unknown_726 = 0;
        if (++gWeatherPtr->unknown_728 > 7)
            gWeatherPtr->unknown_728 = 0;
        sub_8080588(gWeatherPtr->unknown_72A);
        if (++gWeatherPtr->unknown_72A > 12)
            gWeatherPtr->unknown_72A = 0;
    }
}

void sub_8080610(void);

bool8 Bubbles_Finish(void)
{
    if (!Fog1_Finish())
    {
        sub_8080610();
        return FALSE;
    }
    return TRUE;
}

const s16 gUnknown_0839AC78[][2] =
{
    {120, 160},
    {376, 160},
    { 40, 140},
    {296, 140},
    {180, 130},
    {436, 130},
    { 60, 160},
    {436, 160},
    {220, 180},
    {476, 180},
    { 10,  90},
    {266,  90},
    {256, 160},
};

const union AnimCmd gSpriteAnim_839ACAC[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_END,
};

const union AnimCmd *const gSpriteAnimTable_839ACB8[] =
{
    gSpriteAnim_839ACAC,
};

extern const struct OamData gUnknown_08524904;

void unc_0807DAB4(struct Sprite *);
const struct SpriteTemplate gSpriteTemplate_839ACBC =
{
    .tileTag = 4613,
    .paletteTag = 4608,
    .oam = &gUnknown_08524904,
    .anims = gSpriteAnimTable_839ACB8,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = unc_0807DAB4,
};

void sub_8080588(u16 a)
{
    s16 x = gUnknown_0839AC78[a][0];
    s16 y = gUnknown_0839AC78[a][1] - gSpriteCoordOffsetY;
    u8 spriteId = CreateSpriteAtEnd(
      &gSpriteTemplate_839ACBC,
      x,
      y,
      0);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].data[0] = 0;
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].data[2] = 0;
        gWeatherPtr->unknown_72C++;
    }
}

void sub_8080610(void)
{
    u16 i;

    if (gWeatherPtr->unknown_72C != 0)
    {
        for (i = 0; i < 64; i++)
        {
            if (gSprites[i].template == &gSpriteTemplate_839ACBC)
                DestroySprite(&gSprites[i]);
        }
        FreeSpriteTilesByTag(0x1205);
        gWeatherPtr->unknown_72C = 0;
    }
}

void unc_0807DAB4(struct Sprite *sprite)
{
    ++sprite->data[0];
    if (++sprite->data[0] > 8)  // double increment
    {
        sprite->data[0] = 0;
        if (sprite->data[1] == 0)
        {
            if (++sprite->pos2.x > 4)
                sprite->data[1] = 1;
        }
        else
        {
            if (--sprite->pos2.x <= 0)
                sprite->data[1] = 0;
        }
    }
    sprite->pos1.y -= 3;
    if (++sprite->data[2] > 0x77)
        DestroySprite(sprite);
}

//------------------------------------------------------------------------------

static void sub_80AEC94(u32 a0, u32 a1)
{
    gUnknown_02038BC4 = a0;
    gUnknown_02038BC6 = a1;
}

static void sub_80AECA8(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        if (data[15]-- <= 0)
        {
            ChangeWeather(data[1]);
            gUnknown_02038BC4 = data[1];
            data[15] = 600;
            data[0]++;
        }
        break;
    case 1:
        if (data[15]-- <= 0)
        {
            ChangeWeather(data[2]);
            gUnknown_02038BC4 = data[2];
            data[15] = 600;
            data[0] = 0;
        }
        break;
    }
}

static void sub_80AED28(void)
{
    u8 taskId = CreateTask(sub_80AECA8, 0);
    s16 *data = gTasks[taskId].data;

    data[15] = 600;
    if (gUnknown_02038BC4 == WEATHER_RAIN_HEAVY)
    {
        data[1] = WEATHER_DROUGHT;
        data[2] = WEATHER_RAIN_HEAVY;
    }
    else if (gUnknown_02038BC4 == WEATHER_DROUGHT)
    {
        data[1] = WEATHER_RAIN_HEAVY;
        data[2] = WEATHER_DROUGHT;
    }
    else
    {
        gUnknown_02038BC4 = WEATHER_RAIN_HEAVY;
        data[1] = WEATHER_DROUGHT;
        data[2] = WEATHER_RAIN_HEAVY;
    }
}

static u8 TranslateWeatherNum(u8);
static void UpdateRainCounter(u8, u8);

void SetSav1Weather(u32 weather)
{
    u8 oldWeather = gSaveBlock1Ptr->weather;
    gSaveBlock1Ptr->weather = TranslateWeatherNum(weather);
    UpdateRainCounter(gSaveBlock1Ptr->weather, oldWeather);
}

u8 GetSav1Weather(void)
{
    return gSaveBlock1Ptr->weather;
}

void SetSav1WeatherFromCurrMapHeader(void)
{
    u8 oldWeather = gSaveBlock1Ptr->weather;
    gSaveBlock1Ptr->weather = TranslateWeatherNum(gMapHeader.weather);
    UpdateRainCounter(gSaveBlock1Ptr->weather, oldWeather);
}

void SetWeather(u32 weather)
{
    SetSav1Weather(weather);
    ChangeWeather(GetSav1Weather());
}

void SetWeather_Unused(u32 weather)
{
    SetSav1Weather(weather);
    sub_80AB104(GetSav1Weather());
}

void DoCurrentWeather(void)
{
    u8 weather = GetSav1Weather();

    if (weather == WEATHER_15)
    {
        if (!FuncIsActiveTask(sub_80AECA8))
            sub_80AED28();
        weather = gUnknown_02038BC4;
    }
    else
    {
        if (FuncIsActiveTask(sub_80AECA8))
            DestroyTask(FindTaskIdByFunc(sub_80AECA8));
        gUnknown_02038BC4 = WEATHER_RAIN_HEAVY;
    }
    ChangeWeather(weather);
}

void sub_80AEE84(void)
{
    u8 weather = GetSav1Weather();

    if (weather == WEATHER_15)
    {
        if (!FuncIsActiveTask(sub_80AECA8))
            sub_80AED28();
        weather = gUnknown_02038BC4;
    }
    else
    {
        if (FuncIsActiveTask(sub_80AECA8))
            DestroyTask(FindTaskIdByFunc(sub_80AECA8));
        gUnknown_02038BC4 = WEATHER_RAIN_HEAVY;
    }
    sub_80AB104(weather);
}

static const u8 sWeatherCycleRoute119[] =
{
    WEATHER_SUNNY,
    WEATHER_RAIN_LIGHT,
    WEATHER_RAIN_MED,
    WEATHER_RAIN_LIGHT,
};
static const u8 sWeatherCycleRoute123[] =
{
    WEATHER_SUNNY,
    WEATHER_SUNNY,
    WEATHER_RAIN_LIGHT,
    WEATHER_SUNNY,
};

static u8 TranslateWeatherNum(u8 weather)
{
    switch (weather)
    {
    case WEATHER_NONE:       return WEATHER_NONE;
    case WEATHER_CLOUDS:     return WEATHER_CLOUDS;
    case WEATHER_SUNNY:      return WEATHER_SUNNY;
    case WEATHER_RAIN_LIGHT: return WEATHER_RAIN_LIGHT;
    case WEATHER_SNOW:       return WEATHER_SNOW;
    case WEATHER_RAIN_MED:   return WEATHER_RAIN_MED;
    case WEATHER_FOG_1:      return WEATHER_FOG_1;
    case WEATHER_ASH:        return WEATHER_ASH;
    case WEATHER_SANDSTORM:  return WEATHER_SANDSTORM;
    case WEATHER_FOG_2:      return WEATHER_FOG_2;
    case WEATHER_FOG_3:      return WEATHER_FOG_3;
    case WEATHER_SHADE:      return WEATHER_SHADE;
    case WEATHER_DROUGHT:    return WEATHER_DROUGHT;
    case WEATHER_RAIN_HEAVY: return WEATHER_RAIN_HEAVY;
    case WEATHER_BUBBLES:    return WEATHER_BUBBLES;
    case WEATHER_15:         return WEATHER_15;
    case WEATHER_ROUTE119_CYCLE: return sWeatherCycleRoute119[gSaveBlock1Ptr->weatherCycleStage];
    case WEATHER_ROUTE123_CYCLE: return sWeatherCycleRoute123[gSaveBlock1Ptr->weatherCycleStage];
    default:                 return WEATHER_NONE;
    }
}

void UpdateWeatherPerDay(u16 increment)
{
    u16 weatherStage = gSaveBlock1Ptr->weatherCycleStage + increment;
    weatherStage %= 4;
    gSaveBlock1Ptr->weatherCycleStage = weatherStage;
}

static void UpdateRainCounter(u8 newWeather, u8 oldWeather)
{
    if (newWeather != oldWeather
     && (newWeather == WEATHER_RAIN_LIGHT || newWeather == WEATHER_RAIN_MED))
        IncrementGameStat(GAME_STAT_GOT_RAINED_ON);
}
