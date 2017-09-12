#include "global.h"
#include "berry.h"

#define BERRY_NAME_LENGTH 6

#define FIRST_BERRY ITEM_CHERI_BERRY
#define LAST_BERRY ITEM_ENIGMA_BERRY

#ifdef ENGLISH
#define NAME_CHERI_BERRY   _("CHERI")
#define NAME_CHESTO_BERRY  _("CHESTO")
#define NAME_PECHA_BERRY   _("PECHA")
#define NAME_RAWST_BERRY   _("RAWST")
#define NAME_ASPEAR_BERRY  _("ASPEAR")
#define NAME_LEPPA_BERRY   _("LEPPA")
#define NAME_ORAN_BERRY    _("ORAN")
#define NAME_PERSIM_BERRY  _("PERSIM")
#define NAME_LUM_BERRY     _("LUM")
#define NAME_SITRUS_BERRY  _("SITRUS")
#define NAME_FIGY_BERRY    _("FIGY")
#define NAME_WIKI_BERRY    _("WIKI")
#define NAME_MAGO_BERRY    _("MAGO")
#define NAME_AGUAV_BERRY   _("AGUAV")
#define NAME_IAPAPA_BERRY  _("IAPAPA")
#define NAME_RAZZ_BERRY    _("RAZZ")
#define NAME_BLUK_BERRY    _("BLUK")
#define NAME_NANAB_BERRY   _("NANAB")
#define NAME_WEPEAR_BERRY  _("WEPEAR")
#define NAME_PINAP_BERRY   _("PINAP")
#define NAME_POMEG_BERRY   _("POMEG")
#define NAME_KELPSY_BERRY  _("KELPSY")
#define NAME_QUALOT_BERRY  _("QUALOT")
#define NAME_HONDEW_BERRY  _("HONDEW")
#define NAME_GREPA_BERRY   _("GREPA")
#define NAME_TAMATO_BERRY  _("TAMATO")
#define NAME_CORNN_BERRY   _("CORNN")
#define NAME_MAGOST_BERRY  _("MAGOST")
#define NAME_RABUTA_BERRY  _("RABUTA")
#define NAME_NOMEL_BERRY   _("NOMEL")
#define NAME_SPELON_BERRY  _("SPELON")
#define NAME_PAMTRE_BERRY  _("PAMTRE")
#define NAME_WATMEL_BERRY  _("WATMEL")
#define NAME_DURIN_BERRY   _("DURIN")
#define NAME_BELUE_BERRY   _("BELUE")
#define NAME_LIECHI_BERRY  _("LIECHI")
#define NAME_GANLON_BERRY  _("GANLON")
#define NAME_SALAC_BERRY   _("SALAC")
#define NAME_PETAYA_BERRY  _("PETAYA")
#define NAME_APICOT_BERRY  _("APICOT")
#define NAME_LANSAT_BERRY  _("LANSAT")
#define NAME_STARF_BERRY   _("STARF")
#define NAME_ENIGMA_BERRY _("ENIGMA")

#endif // ENGLISH

const u8 gBerryDescriptionPart1_Cheri[] = _("Blooms with delicate pretty flowers.");
const u8 gBerryDescriptionPart2_Cheri[] = _("The bright red BERRY is very spicy.");
const u8 gBerryDescriptionPart1_Chesto[] = _("The BERRYís thick skin and fruit are");
const u8 gBerryDescriptionPart2_Chesto[] = _("very tough. It is dry-tasting all over.");
const u8 gBerryDescriptionPart1_Pecha[] = _("Very sweet and delicious.");
const u8 gBerryDescriptionPart2_Pecha[] = _("Also very tender - handle with care.");
const u8 gBerryDescriptionPart1_Rawst[] = _("If the leaves grow long and curly,");
const u8 gBerryDescriptionPart2_Rawst[] = _("the BERRY seems to grow very bitter.");
const u8 gBerryDescriptionPart1_Aspear[] = _("The hard BERRY is dense with a rich");
const u8 gBerryDescriptionPart2_Aspear[] = _("juice. It is quite sour.");
const u8 gBerryDescriptionPart1_Leppa[] = _("Grows slower than CHERI and others.");
const u8 gBerryDescriptionPart2_Leppa[] = _("The smaller the BERRY, the tastier.");
const u8 gBerryDescriptionPart1_Oran[] = _("A peculiar BERRY with a mix of flavors.");
const u8 gBerryDescriptionPart2_Oran[] = _("BERRIES grow in half a day.");
const u8 gBerryDescriptionPart1_Persim[] = _("Loves sunlight. The BERRYís color");
const u8 gBerryDescriptionPart2_Persim[] = _("grows vivid when exposed to the sun.");
const u8 gBerryDescriptionPart1_Lum[] = _("Slow to grow. If raised with loving");
const u8 gBerryDescriptionPart2_Lum[] = _("care, it may grow two BERRIES.");
const u8 gBerryDescriptionPart1_Sitrus[] = _("Closely related to ORAN. The large");
const u8 gBerryDescriptionPart2_Sitrus[] = _("BERRY has a well-rounded flavor.");
const u8 gBerryDescriptionPart1_Figy[] = _("The BERRY, which looks chewed up,");
const u8 gBerryDescriptionPart2_Figy[] = _("brims with spicy substances.");
const u8 gBerryDescriptionPart1_Wiki[] = _("The BERRY is said to have grown lumpy");
const u8 gBerryDescriptionPart2_Wiki[] = _("to help POKÈMON grip it.");
const u8 gBerryDescriptionPart1_Mago[] = _("The BERRY turns curvy as it grows.");
const u8 gBerryDescriptionPart2_Mago[] = _("The curvier, the sweeter and tastier.");
const u8 gBerryDescriptionPart1_Aguav[] = _("The flower is dainty. It is rare in its");
const u8 gBerryDescriptionPart2_Aguav[] = _("ability to grow without light.");
const u8 gBerryDescriptionPart1_Iapapa[] = _("The BERRY is very big and sour.");
const u8 gBerryDescriptionPart2_Iapapa[] = _("It takes at least a day to grow.");
const u8 gBerryDescriptionPart1_Razz[] = _("The red BERRY tastes slightly spicy.");
const u8 gBerryDescriptionPart2_Razz[] = _("It grows quickly in just four hours.");
const u8 gBerryDescriptionPart1_Bluk[] = _("The BERRY is blue on the outside, but");
const u8 gBerryDescriptionPart2_Bluk[] = _("it blackens the mouth when eaten.");
const u8 gBerryDescriptionPart1_Nanab[] = _("This BERRY was the seventh");
const u8 gBerryDescriptionPart2_Nanab[] = _("discovered in the world. It is sweet.");
const u8 gBerryDescriptionPart1_Wepear[] = _("The flower is small and white. It has a");
const u8 gBerryDescriptionPart2_Wepear[] = _("delicate balance of bitter and sour.");
const u8 gBerryDescriptionPart1_Pinap[] = _("Weak against wind and cold.");
const u8 gBerryDescriptionPart2_Pinap[] = _("The fruit is spicy and the skin, sour.");
const u8 gBerryDescriptionPart1_Pomeg[] = _("However much it is watered,");
const u8 gBerryDescriptionPart2_Pomeg[] = _("it only grows up to six BERRIES.");
const u8 gBerryDescriptionPart1_Kelpsy[] = _("A rare variety shaped like a root.");
const u8 gBerryDescriptionPart2_Kelpsy[] = _("Grows a very large flower.");
const u8 gBerryDescriptionPart1_Qualot[] = _("Loves water. Grows strong even in");
const u8 gBerryDescriptionPart2_Qualot[] = _("locations with constant rainfall.");
const u8 gBerryDescriptionPart1_Hondew[] = _("A BERRY that is very valuable and");
const u8 gBerryDescriptionPart2_Hondew[] = _("rarely seen. It is very delicious.");
const u8 gBerryDescriptionPart1_Grepa[] = _("Despite its tenderness and round");
const u8 gBerryDescriptionPart2_Grepa[] = _("shape, the BERRY is unimaginably sour.");
const u8 gBerryDescriptionPart1_Tamato[] = _("The BERRY is lip-bendingly spicy.");
const u8 gBerryDescriptionPart2_Tamato[] = _("It takes time to grow.");
const u8 gBerryDescriptionPart1_Cornn[] = _("A BERRY from an ancient era. May not");
const u8 gBerryDescriptionPart2_Cornn[] = _("grow unless planted in quantity.");
const u8 gBerryDescriptionPart1_Magost[] = _("A BERRY that is widely said to have");
const u8 gBerryDescriptionPart2_Magost[] = _("a finely balanced flavor.");
const u8 gBerryDescriptionPart1_Rabuta[] = _("A rare variety that is overgrown with");
const u8 gBerryDescriptionPart2_Rabuta[] = _("hair. It is quite bitter.");
const u8 gBerryDescriptionPart1_Nomel[] = _("Quite sour. Just one bite makes it");
const u8 gBerryDescriptionPart2_Nomel[] = _("impossible to taste for three days.");
const u8 gBerryDescriptionPart1_Spelon[] = _("The vividly red BERRY is very spicy.");
const u8 gBerryDescriptionPart2_Spelon[] = _("Its warts secrete a spicy substance.");
const u8 gBerryDescriptionPart1_Pamtre[] = _("Drifts on the sea from somewhere.");
const u8 gBerryDescriptionPart2_Pamtre[] = _("It is thought to grow elsewhere.");
const u8 gBerryDescriptionPart1_Watmel[] = _("A huge BERRY, with some over 20");
const u8 gBerryDescriptionPart2_Watmel[] = _("inches discovered. Exceedingly sweet.");
const u8 gBerryDescriptionPart1_Durin[] = _("Bitter to even look at. It is so");
const u8 gBerryDescriptionPart2_Durin[] = _("bitter, no one has ever eaten it as is.");
const u8 gBerryDescriptionPart1_Belue[] = _("It is glossy and looks delicious, but");
const u8 gBerryDescriptionPart2_Belue[] = _("it is awfully sour. Takes time to grow.");
const u8 gBerryDescriptionPart1_Liechi[] = _("A mysterious BERRY. It is rumored to");
const u8 gBerryDescriptionPart2_Liechi[] = _("contain the power of the sea.");
const u8 gBerryDescriptionPart1_Ganlon[] = _("A mysterious BERRY. It is rumored to");
const u8 gBerryDescriptionPart2_Ganlon[] = _("contain the power of the land.");
const u8 gBerryDescriptionPart1_Salac[] = _("A mysterious BERRY. It is rumored to");
const u8 gBerryDescriptionPart2_Salac[] = _("contain the power of the sky.");
const u8 gBerryDescriptionPart1_Petaya[] = _("A mysterious BERRY. It is rumored to");
const u8 gBerryDescriptionPart2_Petaya[] = _("contain the power of all living things.");
const u8 gBerryDescriptionPart1_Apicot[] = _("A very mystifying BERRY. No telling");
const u8 gBerryDescriptionPart2_Apicot[] = _("what may happen or how it can be used.");
const u8 gBerryDescriptionPart1_Lansat[] = _("Said to be a legendary BERRY.");
const u8 gBerryDescriptionPart2_Lansat[] = _("Holding it supposedly brings joy.");
const u8 gBerryDescriptionPart1_Starf[] = _("So strong, it was abandoned at the");
const u8 gBerryDescriptionPart2_Starf[] = _("worldís edge. Considered a mirage.");
const u8 gBerryDescriptionPart1_Enigma[] = _("A completely enigmatic BERRY.");
const u8 gBerryDescriptionPart2_Enigma[] = _("Appears to have the power of stars.");


const struct Berry gBerries[] =
{
    {
        .name = NAME_CHERI_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 20,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Cheri,
        .description2 = gBerryDescriptionPart2_Cheri,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_CHESTO_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 80,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Chesto,
        .description2 = gBerryDescriptionPart2_Chesto,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_PECHA_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 40,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Pecha,
        .description2 = gBerryDescriptionPart2_Pecha,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_RAWST_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 32,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Rawst,
        .description2 = gBerryDescriptionPart2_Rawst,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_ASPEAR_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 50,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Aspear,
        .description2 = gBerryDescriptionPart2_Aspear,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },
    {
        .name = NAME_LEPPA_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 28,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Leppa,
        .description2 = gBerryDescriptionPart2_Leppa,
        .stageDuration = 4,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_ORAN_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 35,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Oran,
        .description2 = gBerryDescriptionPart2_Oran,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_PERSIM_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 47,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Persim,
        .description2 = gBerryDescriptionPart2_Persim,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_LUM_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 34,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Lum,
        .description2 = gBerryDescriptionPart2_Lum,
        .stageDuration = 12,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_SITRUS_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Sitrus,
        .description2 = gBerryDescriptionPart2_Sitrus,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_FIGY_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 100,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Figy,
        .description2 = gBerryDescriptionPart2_Figy,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_WIKI_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 115,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Wiki,
        .description2 = gBerryDescriptionPart2_Wiki,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_MAGO_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 126,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Mago,
        .description2 = gBerryDescriptionPart2_Mago,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_AGUAV_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 64,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Aguav,
        .description2 = gBerryDescriptionPart2_Aguav,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },
    {
        .name = NAME_IAPAPA_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 223,
        .maxYield = 3,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Iapapa,
        .description2 = gBerryDescriptionPart2_Iapapa,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },
    {
        .name = NAME_RAZZ_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 120,
        .maxYield = 6,
        .minYield = 3,
        .description1 = gBerryDescriptionPart1_Razz,
        .description2 = gBerryDescriptionPart2_Razz,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },
    {
        .name = NAME_BLUK_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 108,
        .maxYield = 6,
        .minYield = 3,
        .description1 = gBerryDescriptionPart1_Bluk,
        .description2 = gBerryDescriptionPart2_Bluk,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },
    {
        .name = NAME_NANAB_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 77,
        .maxYield = 6,
        .minYield = 3,
        .description1 = gBerryDescriptionPart1_Nanab,
        .description2 = gBerryDescriptionPart2_Nanab,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },
    {
        .name = NAME_WEPEAR_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 74,
        .maxYield = 6,
        .minYield = 3,
        .description1 = gBerryDescriptionPart1_Wepear,
        .description2 = gBerryDescriptionPart2_Wepear,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_PINAP_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 80,
        .maxYield = 6,
        .minYield = 3,
        .description1 = gBerryDescriptionPart1_Pinap,
        .description2 = gBerryDescriptionPart2_Pinap,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_POMEG_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 6,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Pomeg,
        .description2 = gBerryDescriptionPart2_Pomeg,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },
    {
        .name = NAME_KELPSY_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 150,
        .maxYield = 6,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Kelpsy,
        .description2 = gBerryDescriptionPart2_Kelpsy,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_QUALOT_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 110,
        .maxYield = 6,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Qualot,
        .description2 = gBerryDescriptionPart2_Qualot,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_HONDEW_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 162,
        .maxYield = 6,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Hondew,
        .description2 = gBerryDescriptionPart2_Hondew,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },
    {
        .name = NAME_GREPA_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 149,
        .maxYield = 6,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Grepa,
        .description2 = gBerryDescriptionPart2_Grepa,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },
    {
        .name = NAME_TAMATO_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 200,
        .maxYield = 4,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Tamato,
        .description2 = gBerryDescriptionPart2_Tamato,
        .stageDuration = 6,
        .spicy = 20,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },
    {
        .name = NAME_CORNN_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 4,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Cornn,
        .description2 = gBerryDescriptionPart2_Cornn,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 20,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },
    {
        .name = NAME_MAGOST_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 140,
        .maxYield = 4,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Magost,
        .description2 = gBerryDescriptionPart2_Magost,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 20,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },
    {
        .name = NAME_RABUTA_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 226,
        .maxYield = 4,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Rabuta,
        .description2 = gBerryDescriptionPart2_Rabuta,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 20,
        .sour = 10,
        .smoothness = 30,
    },
    {
        .name = NAME_NOMEL_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 285,
        .maxYield = 4,
        .minYield = 2,
        .description1 = gBerryDescriptionPart1_Nomel,
        .description2 = gBerryDescriptionPart2_Nomel,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 20,
        .smoothness = 30,
    },
    {
        .name = NAME_SPELON_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 133,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Spelon,
        .description2 = gBerryDescriptionPart2_Spelon,
        .stageDuration = 18,
        .spicy = 40,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },
    {
        .name = NAME_PAMTRE_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 244,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Pamtre,
        .description2 = gBerryDescriptionPart2_Pamtre,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 40,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },
    {
        .name = NAME_WATMEL_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 250,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Watmel,
        .description2 = gBerryDescriptionPart2_Watmel,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 10,
        .sour = 0,
        .smoothness = 70,
    },
    {
        .name = NAME_DURIN_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 280,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Durin,
        .description2 = gBerryDescriptionPart2_Durin,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 10,
        .smoothness = 70,
    },
    {
        .name = NAME_BELUE_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 300,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Belue,
        .description2 = gBerryDescriptionPart2_Belue,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },
    {
        .name = NAME_LIECHI_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 111,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Liechi,
        .description2 = gBerryDescriptionPart2_Liechi,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 10,
        .smoothness = 80,
    },
    {
        .name = NAME_GANLON_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 33,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Ganlon,
        .description2 = gBerryDescriptionPart2_Ganlon,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },
    {
        .name = NAME_SALAC_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Salac,
        .description2 = gBerryDescriptionPart2_Salac,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },
    {
        .name = NAME_PETAYA_BERRY,
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 237,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Petaya,
        .description2 = gBerryDescriptionPart2_Petaya,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },
    {
        .name = NAME_APICOT_BERRY,
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Apicot,
        .description2 = gBerryDescriptionPart2_Apicot,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },
    {
        .name = NAME_LANSAT_BERRY,
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 97,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Lansat,
        .description2 = gBerryDescriptionPart2_Lansat,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },
    {
        .name = NAME_STARF_BERRY,
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 153,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Starf,
        .description2 = gBerryDescriptionPart2_Starf,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },
    {
        .name = NAME_ENIGMA_BERRY,
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 2,
        .minYield = 1,
        .description1 = gBerryDescriptionPart1_Enigma,
        .description2 = gBerryDescriptionPart2_Enigma,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 40,
        .sweet = 40,
        .bitter = 40,
        .sour = 40,
        .smoothness = 40,
    },
};

