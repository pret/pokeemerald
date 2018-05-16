#include "global.h"
#include "menu_indicators.h"
#include "task.h"
#include "trig.h"
#include "decompress.h"
#include "palette.h"

struct UnkIndicatorsStruct
{
    u8 field_0;
    u16 *field_4;
    u16 field_8;
    u16 field_A;
    u16 field_C;
    u16 field_E;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14_0:4;
    u8 field_14_1:4;
    u8 field_15_0:4;
    u8 field_15_1:4;
    u8 field_16_0:3;
    u8 field_16_1:3;
    u8 field_16_2:2;
    u8 field_17_0:6;
    u8 field_17_1:2;
};

struct UnkIndicatorsStruct2
{
    u8 field_0;
    u16 *field_4;
    u16 field_8;
    u16 field_A;
    u8 field_C;
    u8 field_D;
    u16 tileTag;
    u16 palTag;
    u16 field_12;
    u16 field_14;
    u16 field_16;
    u16 field_18;
    u16 field_1A;
    u16 field_1C;
    s16 field_1E;
};

struct UnkSmallIndicatorsStruct
{
    u8 field_0_0:4;
    u8 field_0_1:4;
    u8 field_1;
    u16 field_2;
};

extern const struct SpriteTemplate gUnknown_08614244;
extern const struct UnkSmallIndicatorsStruct gUnknown_086141FC[];
extern const u8 gUnknown_086142C8[];
extern const u16 gUnknown_086142A8[];

extern struct ArrowStruct gUnknown_0203CE8C;

// this file's functions
void Task_ScrollIndicatorArrowPair(u8 taskId);
u8 ListMenuAddRedOutlineCursorObject(struct CursorStruct *cursor);
u8 ListMenuAddRedArrowCursorObject(struct CursorStruct *cursor);
void ListMenuUpdateRedOutlineCursorObject(u8 taskId, u16 x, u16 y);
void ListMenuUpdateRedArrowCursorObject(u8 taskId, u16 x, u16 y);
void ListMenuRemoveRedOutlineCursorObject(u8 taskId);
void ListMenuRemoveRedArrowCursorObject(u8 taskId);

// code
s32 sub_81AF08C(u8 taskId, u8 field)
{
    struct UnkIndicatorsStruct *data = (void*) gTasks[taskId].data;

    switch (field)
    {
    case 0:
    case 1:
        return (s32)(data->field_4);
    case 2:
        return data->field_C;
    case 3:
        return data->field_E;
    case 4:
        return data->field_10;
    case 5:
        return data->field_11;
    case 6:
        return data->field_12;
    case 7:
        return data->field_13;
    case 8:
        return data->field_14_0;
    case 9:
        return data->field_14_1;
    case 10:
        return data->field_15_0;
    case 11:
        return data->field_15_1;
    case 12:
        return data->field_16_0;
    case 13:
        return data->field_16_1;
    case 14:
        return data->field_16_2;
    case 15:
        return data->field_17_0;
    case 16:
        return data->field_17_1;
    default:
        return -1;
    }
}

void sub_81AF15C(u8 taskId, u8 field, s32 value)
{
    struct UnkIndicatorsStruct *data = (void*) &gTasks[taskId].data;

    switch (field)
    {
    case 0:
    case 1:
        data->field_4 = (void*)(value);
		break;
    case 2:
        data->field_C = value;
		break;
    case 3:
        data->field_E = value;
		break;
    case 4:
        data->field_10 = value;
		break;
    case 5:
        data->field_11 = value;
		break;
    case 6:
        data->field_12 = value;
		break;
    case 7:
        data->field_13 = value;
		break;
    case 8:
        data->field_14_0 = value;
		break;
    case 9:
        data->field_14_1 = value;
		break;
    case 10:
        data->field_15_0 = value;
		break;
    case 11:
        data->field_15_1 = value;
		break;
    case 12:
        data->field_16_0 = value;
		break;
    case 13:
        data->field_16_1 = value;
		break;
    case 14:
        data->field_16_2 = value;
		break;
    case 15:
        data->field_17_0 = value;
		break;
    case 16:
        data->field_17_1 = value;
		break;
    }
}

void sub_81AF264(struct Sprite *sprite)
{
    s32 multiplier;

    switch (sprite->data[0])
    {
    case 0:
        StartSpriteAnim(sprite, sprite->data[1]);
        sprite->data[0]++;
        break;
    case 1:
        switch (sprite->data[2])
        {
        case 0:
            multiplier = sprite->data[3];
            sprite->pos2.x = (gSineTable[(u8)(sprite->data[5])] * multiplier) / 256;
            break;
        case 1:
            multiplier = sprite->data[3];
            sprite->pos2.y = (gSineTable[(u8)(sprite->data[5])] * multiplier) / 256;
            break;
        }
        sprite->data[5] += sprite->data[4];
        break;
    }
}

u8 AddScrollIndicatorArrowObject(u8 arg0, u8 x, u8 y, u16 tileTag, u16 palTag)
{
    u8 spriteId;
    struct SpriteTemplate spriteTemplate;

    spriteTemplate = gUnknown_08614244;
    spriteTemplate.tileTag = tileTag;
    spriteTemplate.paletteTag = palTag;

    spriteId = CreateSprite(&spriteTemplate, x, y, 0);
    gSprites[spriteId].invisible = 1;
    gSprites[spriteId].data[0] = 0;
    gSprites[spriteId].data[1] = gUnknown_086141FC[arg0].field_0_0;
    gSprites[spriteId].data[2] = gUnknown_086141FC[arg0].field_0_1;
    gSprites[spriteId].data[3] = gUnknown_086141FC[arg0].field_1;
    gSprites[spriteId].data[4] = gUnknown_086141FC[arg0].field_2;
    gSprites[spriteId].data[5] = 0;

    return spriteId;
}

u8 AddScrollIndicatorArrowPair(const struct ArrowStruct *arrowInfo, u16 *arg1)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePal;
    struct UnkIndicatorsStruct2 *data;
    u8 taskId;

    spriteSheet.data = gUnknown_086142C8;
    spriteSheet.size = 0x100;
    spriteSheet.tag = arrowInfo->tileTag;
    LoadCompressedObjectPic(&spriteSheet);

    if (arrowInfo->palTag == 0xFFFF)
    {
        LoadPalette(gUnknown_086142A8, (16 * arrowInfo->palNum) + 0x100, 0x20);
    }
    else
    {
        spritePal.data = gUnknown_086142A8;
        spritePal.tag = arrowInfo->palTag;
        LoadSpritePalette(&spritePal);
    }

    taskId = CreateTask(Task_ScrollIndicatorArrowPair, 0);
    data = (void*) gTasks[taskId].data;

    data->field_0 = 0;
    data->field_4 = arg1;
    data->field_8 = arrowInfo->unk6;
    data->field_A = arrowInfo->unk8;
    data->tileTag = arrowInfo->tileTag;
    data->palTag = arrowInfo->palTag;
    data->field_C = AddScrollIndicatorArrowObject(arrowInfo->unk0, arrowInfo->unk1, arrowInfo->unk2, arrowInfo->tileTag, arrowInfo->palTag);
    data->field_D = AddScrollIndicatorArrowObject(arrowInfo->unk3, arrowInfo->unk4, arrowInfo->unk5, arrowInfo->tileTag, arrowInfo->palTag);

    if (arrowInfo->palTag == 0xFFFF)
    {
        gSprites[data->field_C].oam.paletteNum = arrowInfo->palNum;
        gSprites[data->field_D].oam.paletteNum = arrowInfo->palNum;
    }

    return taskId;
}

u8 AddScrollIndicatorArrowPairParametrized(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 tileTag, s32 palTag, void *arg7)
{
    if (arg0 == 2 || arg0 == 3)
    {
        gUnknown_0203CE8C.unk0 = 2;
        gUnknown_0203CE8C.unk1 = arg1;
        gUnknown_0203CE8C.unk2 = arg2;
        gUnknown_0203CE8C.unk3 = 3;
        gUnknown_0203CE8C.unk4 = arg1;
        gUnknown_0203CE8C.unk5 = arg3;
    }
    else
    {
        gUnknown_0203CE8C.unk0 = 0;
        gUnknown_0203CE8C.unk1 = arg2;
        gUnknown_0203CE8C.unk2 = arg1;
        gUnknown_0203CE8C.unk3 = 1;
        gUnknown_0203CE8C.unk4 = arg3;
        gUnknown_0203CE8C.unk5 = arg1;
    }

    gUnknown_0203CE8C.unk6 = 0;
    gUnknown_0203CE8C.unk8 = arg4;
    gUnknown_0203CE8C.tileTag = tileTag;
    gUnknown_0203CE8C.palTag = palTag;
    gUnknown_0203CE8C.palNum = 0;

    return AddScrollIndicatorArrowPair(&gUnknown_0203CE8C, arg7);
}

void Task_ScrollIndicatorArrowPair(u8 taskId)
{
    struct UnkIndicatorsStruct2 *data = (void*) gTasks[taskId].data;
    u16 var = (*data->field_4);

    if (var == data->field_8 && var != 0xFFFF)
        gSprites[data->field_C].invisible = 1;
    else
        gSprites[data->field_C].invisible = 0;

    if (var == data->field_A)
        gSprites[data->field_D].invisible = 1;
    else
        gSprites[data->field_D].invisible = 0;
}

void Task_ScrollIndicatorArrowPairOnMainMenu(u8 taskId)
{
    struct UnkIndicatorsStruct2 *data = (void*) gTasks[taskId].data;

    if (data->field_1E != 0)
    {
        gSprites[data->field_C].invisible = 0;
        gSprites[data->field_D].invisible = 1;
    }
    else
    {
        gSprites[data->field_C].invisible = 1;
        gSprites[data->field_D].invisible = 0;
    }
}

void RemoveScrollIndicatorArrowPair(u8 taskId)
{
    struct UnkIndicatorsStruct2 *data = (void*) gTasks[taskId].data;

    if (data->tileTag != 0xFFFF)
        FreeSpriteTilesByTag(data->tileTag);
    if (data->palTag != 0xFFFF)
        FreeSpritePaletteByTag(data->palTag);

    DestroySprite(&gSprites[data->field_C]);
    DestroySprite(&gSprites[data->field_D]);

    DestroyTask(taskId);
}

u8 ListMenuAddCursorObjectInternal(struct CursorStruct *cursor, u32 cursorKind)
{
    switch (cursorKind)
    {
    case 0:
    default:
        return ListMenuAddRedOutlineCursorObject(cursor);
    case 1:
        return ListMenuAddRedArrowCursorObject(cursor);
    }
}

void ListMenuUpdateCursorObject(u8 taskId, u16 x, u16 y, u32 cursorKind)
{
    switch (cursorKind)
    {
    case 0:
        ListMenuUpdateRedOutlineCursorObject(taskId, x, y);
        break;
    case 1:
        ListMenuUpdateRedArrowCursorObject(taskId, x, y);
        break;
    }
}

void ListMenuRemoveCursorObject(u8 taskId, u32 cursorKind)
{
    switch (cursorKind)
    {
    case 0:
        ListMenuRemoveRedOutlineCursorObject(taskId);
        break;
    case 1:
        ListMenuRemoveRedArrowCursorObject(taskId);
        break;
    }
}

void Task_RedOutlineCursor(u8 taskId)
{

}
