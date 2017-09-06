// Includes

#include "global.h"
#include "sprite.h"
#include "rom4.h"
#include "field_player_avatar.h"
#include "field_map_obj.h"

// Static struct declarations

// Static RAM declarations

// Static ROM declarations

/*static*/ void sub_808D450(void);
/*static*/ u8 GetFieldObjectIdByLocalId(u8);
/*static*/ u8 GetFieldObjectIdByLocalIdAndMapInternal(u8, u8, u8);

// ROM data

// Code

/*static*/ void npc_clear_ids_and_state(struct MapObject *mapObject)
{
    memset(mapObject, 0, sizeof(struct MapObject));
    mapObject->localId = 0xFF;
    mapObject->mapNum = -1;
    mapObject->mapGroup = -1;
    mapObject->mapobj_unk_1C = -1;
}

static void npcs_clear_ids_and_state(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_02037350); i ++)
    {
        npc_clear_ids_and_state(&gUnknown_02037350[i]);
    }
}

void sub_808D438(void)
{
    strange_npc_table_clear();
    npcs_clear_ids_and_state();
    ClearPlayerAvatarInfo();
    sub_808D450();
}

/*static*/ void sub_808D450(void)
{
    u8 spriteIdx;

    spriteIdx = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteIdx].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteIdx]);
    StartSpriteAffineAnim(&gSprites[spriteIdx], 0);
    gSprites[spriteIdx].invisible = TRUE;

    spriteIdx = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[21], 0, 0, 31);
    gSprites[spriteIdx].oam.affineMode = 1;
    InitSpriteAffineAnim(&gSprites[spriteIdx]);
    StartSpriteAffineAnim(&gSprites[spriteIdx], 1);
    gSprites[spriteIdx].invisible = TRUE;
}

u8 sub_808D4F4(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(gUnknown_02037350); i ++)
    {
        if (!gUnknown_02037350[i].active)
        {
            break;
        }
    }
    return i;
}

u8 GetFieldObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId)
{
    if (localId < 0xff)
    {
        return GetFieldObjectIdByLocalIdAndMapInternal(localId, mapId, mapGroupId);
    }
    return GetFieldObjectIdByLocalId(localId);
}

bool8 TryGetFieldObjectIdByLocalIdAndMap(u8 localId, u8 mapId, u8 mapGroupId, u8 *fieldObjectId)
{
    *fieldObjectId = GetFieldObjectIdByLocalIdAndMap(localId, mapId, mapGroupId);
    if (*fieldObjectId == ARRAY_COUNT(gUnknown_02037350))
    {
        return TRUE;
    }
    return FALSE;
}

u8 GetFieldObjectIdByXY(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gUnknown_02037350); i ++)
    {
        if (gUnknown_02037350[i].active && gUnknown_02037350[i].coords2.x == x && gUnknown_02037350[i].coords2.y == y)
        {
            break;
        }
    }
    return i;
}
