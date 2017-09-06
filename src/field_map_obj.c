// Includes

#include "global.h"
#include "field_map_obj.h"

// Static struct declarations

// Static RAM declarations

// Static ROM declarations

// ROM data

// Code

void npc_clear_ids_and_state(struct MapObject *mapObject)
{
    memset(mapObject, 0, sizeof(struct MapObject));
    mapObject->localId = 0xFF;
    mapObject->mapNum = -1;
    mapObject->mapGroup = -1;
    mapObject->mapobj_unk_1C = -1;
}

void npcs_clear_ids_and_state(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gUnknown_02037350); i ++)
    {
        npc_clear_ids_and_state(&gUnknown_02037350[i]);
    }
}
