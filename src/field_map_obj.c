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
