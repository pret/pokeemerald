#include "global.h"
#include "event_data.h"
#include "give_gift_ribbon_to_party.h"
#include "pokemon.h"

// - 4 for unused gift ribbon bits in MON_DATA_UNUSED_RIBBONS
static const u8 sGiftRibbonsMonDataIds[GIFT_RIBBONS_COUNT - 4] =
{
    MON_DATA_MARINE_RIBBON, MON_DATA_LAND_RIBBON, MON_DATA_SKY_RIBBON,
    MON_DATA_COUNTRY_RIBBON, MON_DATA_NATIONAL_RIBBON, MON_DATA_EARTH_RIBBON,
    MON_DATA_WORLD_RIBBON
};

void GiveGiftRibbonToParty(u8 index, u8 ribbonId)
{
    s32 i;
    bool32 gotRibbon = FALSE;
    u8 data = 1;
    u8 array[ARRAY_COUNT(sGiftRibbonsMonDataIds)];
    memcpy(array, sGiftRibbonsMonDataIds, sizeof(sGiftRibbonsMonDataIds));

    if (index < GIFT_RIBBONS_COUNT && ribbonId <= MAX_GIFT_RIBBON)
    {
        gSaveBlock1Ptr->giftRibbons[index] = ribbonId;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];

            if (GetMonData(mon, MON_DATA_SPECIES) != 0 && GetMonData(mon, MON_DATA_SANITY_IS_EGG) == 0)
            {
                SetMonData(mon, array[index], &data);
                gotRibbon = TRUE;
            }
        }
        if (gotRibbon)
            FlagSet(FLAG_SYS_RIBBON_GET);
    }
}
