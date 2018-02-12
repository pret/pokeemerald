#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "constants/species.h"

extern u16 gSpecialVar_0x8004;
extern u16 gSpecialVar_0x8005;
extern u16 gSpecialVar_0x8006;

extern const u8 gBirchDexRatingText_LessThan10[];
extern const u8 gBirchDexRatingText_LessThan20[];
extern const u8 gBirchDexRatingText_LessThan30[];
extern const u8 gBirchDexRatingText_LessThan40[];
extern const u8 gBirchDexRatingText_LessThan50[];
extern const u8 gBirchDexRatingText_LessThan60[];
extern const u8 gBirchDexRatingText_LessThan70[];
extern const u8 gBirchDexRatingText_LessThan80[];
extern const u8 gBirchDexRatingText_LessThan90[];
extern const u8 gBirchDexRatingText_LessThan100[];
extern const u8 gBirchDexRatingText_LessThan110[];
extern const u8 gBirchDexRatingText_LessThan120[];
extern const u8 gBirchDexRatingText_LessThan130[];
extern const u8 gBirchDexRatingText_LessThan140[];
extern const u8 gBirchDexRatingText_LessThan150[];
extern const u8 gBirchDexRatingText_LessThan160[];
extern const u8 gBirchDexRatingText_LessThan170[];
extern const u8 gBirchDexRatingText_LessThan180[];
extern const u8 gBirchDexRatingText_LessThan190[];
extern const u8 gBirchDexRatingText_LessThan200[];
extern const u8 gBirchDexRatingText_DexCompleted[];

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetHoennPokedexCount(0);
        gSpecialVar_0x8006 = GetHoennPokedexCount(1);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(0);
        gSpecialVar_0x8006 = GetNationalPokedexCount(1);
    }

    return IsNationalPokedexEnabled();
}

// This shows your Hoenn Pokedex rating and not your National Dex.
const u8 *GetPokedexRatingText(u16 count)
{
    if (count < 10)
        return gBirchDexRatingText_LessThan10;
    if (count < 20)
        return gBirchDexRatingText_LessThan20;
    if (count < 30)
        return gBirchDexRatingText_LessThan30;
    if (count < 40)
        return gBirchDexRatingText_LessThan40;
    if (count < 50)
        return gBirchDexRatingText_LessThan50;
    if (count < 60)
        return gBirchDexRatingText_LessThan60;
    if (count < 70)
        return gBirchDexRatingText_LessThan70;
    if (count < 80)
        return gBirchDexRatingText_LessThan80;
    if (count < 90)
        return gBirchDexRatingText_LessThan90;
    if (count < 100)
        return gBirchDexRatingText_LessThan100;
    if (count < 110)
        return gBirchDexRatingText_LessThan110;
    if (count < 120)
        return gBirchDexRatingText_LessThan120;
    if (count < 130)
        return gBirchDexRatingText_LessThan130;
    if (count < 140)
        return gBirchDexRatingText_LessThan140;
    if (count < 150)
        return gBirchDexRatingText_LessThan150;
    if (count < 160)
        return gBirchDexRatingText_LessThan160;
    if (count < 170)
        return gBirchDexRatingText_LessThan170;
    if (count < 180)
        return gBirchDexRatingText_LessThan180;
    if (count < 190)
        return gBirchDexRatingText_LessThan190;
    if (count < 200)
        return gBirchDexRatingText_LessThan200;
    if (count == 200)
    {
        if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_JIRACHI), 1)
         || GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DEOXYS), 1)) // Jirachi or Deoxys is not counted towards the dex completion. If either of these flags are enabled, it means the actual count is less than 200.
            return gBirchDexRatingText_LessThan200;
        return gBirchDexRatingText_DexCompleted;
    }
    if (count == 201)
    {
        if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_JIRACHI), 1)
         && GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_DEOXYS), 1)) // If both of these flags are enabled, it means the actual count is less than 200.
            return gBirchDexRatingText_LessThan200;
        return gBirchDexRatingText_DexCompleted;
    }
    if (count == 202)
        return gBirchDexRatingText_DexCompleted; // Hoenn dex is considered complete, even though the hoenn dex count is 210.
    return gBirchDexRatingText_LessThan10;
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}
