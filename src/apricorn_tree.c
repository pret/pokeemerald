#include "global.h"
#include "apricorn_tree.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "item.h"
#include "random.h"
#include "string_util.h"
#include "data/apricorns.h"

void DailyResetApricornTrees(void)
{
#if (APRICORN_TREE_COUNT > 0)
    memset(&gSaveBlock3Ptr->apricornTrees[0], 0, NUM_APRICORN_TREE_BYTES);
#endif
}

void ObjectEventInteractionGetApricornTreeData(void)
{
    u32 id = GetObjectEventApricornTreeId(gSelectedObjectEvent);
    gSpecialVar_0x8004 = GetApricornTypeByApricornTreeId(id);
    gSpecialVar_0x8005 = GetApricornCountByApricornTreeId(id);

    CopyItemNameHandlePlural(gSpecialVar_0x8004, gStringVar1, gSpecialVar_0x8005);
}

void ObjectEventInteractionPickApricornTree(void)
{
    u32 id = GetObjectEventApricornTreeId(gSelectedObjectEvent);
    enum ApricornType apricorn = GetApricornTypeByApricornTreeId(id);
    gSpecialVar_0x8006 = CheckBagHasSpace((enum Item)apricorn, GetApricornCountByApricornTreeId(id));

    if (gSpecialVar_0x8006)
    {
        AddBagItem((enum Item)apricorn, GetApricornCountByApricornTreeId(id));
        SetApricornTreePicked(id);
    }
    gSpecialVar_Result = GetItemPocket((enum Item)apricorn);
}

enum ApricornType GetApricornTypeByApricornTreeId(u32 id)
{
    if (APRICORN_TREE_COUNT > 0)
        return gApricornTrees[id].apricornType;
    else
        return 0;
}

u8 GetApricornCountByApricornTreeId(u32 id)
{
    if (IsApricornTreePicked(id))
        return 0;

    if (APRICORN_TREE_COUNT > 0)
    {
        if (gApricornTrees[id].maximum > gApricornTrees[id].minimum)
            return gApricornTrees[id].minimum + Random() % (gApricornTrees[id].maximum - gApricornTrees[id].minimum);
        else
            return gApricornTrees[id].minimum;
    }
    else
        return 0;
}

bool8 IsApricornTreePicked(u32 id)
{
    if (id > APRICORN_TREE_COUNT)
        return TRUE;

#if (APRICORN_TREE_COUNT > 0)
    return gSaveBlock3Ptr->apricornTrees[id / 8] & (1 << (id % 8));
#else
    return TRUE;
#endif
}

void SetApricornTreePicked(u32 id)
{
    if (id > APRICORN_TREE_COUNT)
        return;

#if (APRICORN_TREE_COUNT > 0)
    u8 *flagByte = &gSaveBlock3Ptr->apricornTrees[id / 8];
    *flagByte = (*flagByte) | (1 << (id % 8));
#endif
}
