#include "global.h"
#include "event_data.h"
#include "constants/region_map_sections.h"

struct Landmark
{
    const u8 *name;
    u16 flag;
};

struct LandmarkList
{
    u8 mapSection;
    u8 id;
    const struct Landmark *const *landmarks;
};

static const u8 LandmarkName_FlowerShop[] = _("FLOWER SHOP");
static const u8 LandmarkName_PetalburgWoods[] = _("PETALBURG WOODS");
static const u8 LandmarkName_MrBrineysCottage[] = _("MR. BRINEY'S COTTAGE");
static const u8 LandmarkName_AbandonedShip[] = _("ABANDONED SHIP");
static const u8 LandmarkName_SeashoreHouse[] = _("SEASHORE HOUSE");
static const u8 LandmarkName_SlateportBeach[] = _("SLATEPORT BEACH");
static const u8 LandmarkName_CyclingRoad[] = _("CYCLING ROAD");
static const u8 LandmarkName_NewMauville[] = _("NEW MAUVILLE");
static const u8 LandmarkName_TrickHouse[] = _("TRICK HOUSE");
static const u8 LandmarkName_OldLadysRestShop[] = _("OLD LADY'S REST STOP");
static const u8 LandmarkName_Desert[] = _("DESERT");
static const u8 LandmarkName_WinstrateFamily[] = _("THE WINSTRATE FAMILY");
static const u8 LandmarkName_CableCar[] = _("CABLE CAR");
static const u8 LandmarkName_GlassWorkshop[] = _("GLASS WORKSHOP");
static const u8 LandmarkName_WeatherInstitute[] = _("WEATHER INSTITUTE");
static const u8 LandmarkName_MeteorFalls[] = _("METEOR FALLS");
static const u8 LandmarkName_TunnelersRestHouse[] = _("TUNNELER'S RESTHOUSE");
static const u8 LandmarkName_RusturfTunnel[] = _("RUSTURF TUNNEL");
static const u8 LandmarkName_PokemonDayCare[] = _("POKéMON DAY CARE");
static const u8 LandmarkName_SafariZoneEntrance[] = _("SAFARI ZONE ENTRANCE");
static const u8 LandmarkName_MtPyre[] = _("MT. PYRE");
static const u8 LandmarkName_ShoalCave[] = _("SHOAL CAVE");
static const u8 LandmarkName_SeafloorCavern[] = _("SEAFLOOR CAVERN");
static const u8 LandmarkName_GraniteCave[] = _("GRANITE CAVE");
static const u8 LandmarkName_OceanCurrent[] = _("OCEAN CURRENT");
static const u8 LandmarkName_LanettesHouse[] = _("LANETTE'S HOUSE");
static const u8 LandmarkName_FieryPath[] = _("FIERY PATH");
static const u8 LandmarkName_JaggedPass[] = _("JAGGED PASS");
static const u8 LandmarkName_SkyPillar[] = _("SKY PILLAR");
static const u8 LandmarkName_BerryMastersHouse[] = _("BERRY MASTER'S HOUSE");
static const u8 LandmarkName_IslandCave[] = _("ISLAND CAVE");
static const u8 LandmarkName_DesertRuins[] = _("DESERT RUINS");
static const u8 LandmarkName_ScorchedSlab[] = _("SCORCHED SLAB");
static const u8 LandmarkName_AncientTomb[] = _("ANCIENT TOMB");
static const u8 LandmarkName_SealedChamber[] = _("SEALED CHAMBER");
static const u8 LandmarkName_FossilManiacsHouse[] = _("FOSSIL MANIAC'S HOUSE");
static const u8 LandmarkName_HuntersHouse[] = _("HUNTER'S HOUSE");
static const u8 LandmarkName_MagmaHideout[] = _("MAGMA HIDEOUT");
static const u8 LandmarkName_MirageTower[] = _("MIRAGE TOWER");
static const u8 LandmarkName_AlteringCave[] = _("ALTERING CAVE");
static const u8 LandmarkName_DesertUnderpass[] = _("DESERT UNDERPASS");
static const u8 LandmarkName_TrainerHill[] = _("TRAINER HILL");

static const struct Landmark Landmark_FlowerShop = {LandmarkName_FlowerShop, FLAG_LANDMARK_FLOWER_SHOP};
static const struct Landmark Landmark_PetalburgWoods = {LandmarkName_PetalburgWoods, -1};
static const struct Landmark Landmark_MrBrineysCottage = {LandmarkName_MrBrineysCottage, FLAG_LANDMARK_MR_BRINEY_HOUSE};
static const struct Landmark Landmark_AbandonedShip = {LandmarkName_AbandonedShip, FLAG_LANDMARK_ABANDONED_SHIP};
static const struct Landmark Landmark_SeashoreHouse = {LandmarkName_SeashoreHouse, FLAG_LANDMARK_SEASHORE_HOUSE};
static const struct Landmark Landmark_SlateportBeach = {LandmarkName_SlateportBeach, -1};
static const struct Landmark Landmark_CyclingRoad = {LandmarkName_CyclingRoad, -1};
static const struct Landmark Landmark_NewMauville = {LandmarkName_NewMauville, FLAG_LANDMARK_NEW_MAUVILLE};
static const struct Landmark Landmark_TrickHouse = {LandmarkName_TrickHouse, FLAG_LANDMARK_TRICK_HOUSE};
static const struct Landmark Landmark_OldLadysRestShop = {LandmarkName_OldLadysRestShop, FLAG_LANDMARK_OLD_LADY_REST_SHOP};
static const struct Landmark Landmark_Desert = {LandmarkName_Desert, -1};
static const struct Landmark Landmark_WinstrateFamily = {LandmarkName_WinstrateFamily, FLAG_LANDMARK_WINSTRATE_FAMILY};
static const struct Landmark Landmark_CableCar = {LandmarkName_CableCar, -1};
static const struct Landmark Landmark_GlassWorkshop = {LandmarkName_GlassWorkshop, FLAG_LANDMARK_GLASS_WORKSHOP};
static const struct Landmark Landmark_WeatherInstitute = {LandmarkName_WeatherInstitute, -1};
static const struct Landmark Landmark_MeteorFalls = {LandmarkName_MeteorFalls, -1};
static const struct Landmark Landmark_TunnelersRestHouse = {LandmarkName_TunnelersRestHouse, FLAG_LANDMARK_TUNNELERS_REST_HOUSE};
static const struct Landmark Landmark_RusturfTunnel = {LandmarkName_RusturfTunnel, -1};
static const struct Landmark Landmark_PokemonDayCare = {LandmarkName_PokemonDayCare, FLAG_LANDMARK_POKEMON_DAYCARE};
static const struct Landmark Landmark_SafariZoneEntrance = {LandmarkName_SafariZoneEntrance, -1};
static const struct Landmark Landmark_MtPyre = {LandmarkName_MtPyre, -1};
static const struct Landmark Landmark_ShoalCave = {LandmarkName_ShoalCave, -1};
static const struct Landmark Landmark_SeafloorCavern = {LandmarkName_SeafloorCavern, FLAG_LANDMARK_SEAFLOOR_CAVERN};
static const struct Landmark Landmark_GraniteCave = {LandmarkName_GraniteCave, -1};
static const struct Landmark Landmark_OceanCurrent = {LandmarkName_OceanCurrent, -1};
static const struct Landmark Landmark_LanettesHouse = {LandmarkName_LanettesHouse, FLAG_LANDMARK_LANETTES_HOUSE};
static const struct Landmark Landmark_FieryPath = {LandmarkName_FieryPath, FLAG_LANDMARK_FIERY_PATH};
static const struct Landmark Landmark_JaggedPass = {LandmarkName_JaggedPass, -1};
static const struct Landmark Landmark_BerryMastersHouse = {LandmarkName_BerryMastersHouse, FLAG_LANDMARK_BERRY_MASTERS_HOUSE};
static const struct Landmark Landmark_IslandCave = {LandmarkName_IslandCave, FLAG_LANDMARK_ISLAND_CAVE};
static const struct Landmark Landmark_DesertRuins = {LandmarkName_DesertRuins, FLAG_LANDMARK_DESERT_RUINS};
static const struct Landmark Landmark_ScorchedSlab = {LandmarkName_ScorchedSlab, FLAG_LANDMARK_SCORCHED_SLAB};
static const struct Landmark Landmark_AncientTomb = {LandmarkName_AncientTomb, FLAG_LANDMARK_ANCIENT_TOMB};
static const struct Landmark Landmark_SealedChamber = {LandmarkName_SealedChamber, FLAG_LANDMARK_SEALED_CHAMBER};
static const struct Landmark Landmark_FossilManiacsHouse = {LandmarkName_FossilManiacsHouse, FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE};
static const struct Landmark Landmark_HuntersHouse = {LandmarkName_HuntersHouse, FLAG_LANDMARK_HUNTERS_HOUSE};
static const struct Landmark Landmark_SkyPillar = {LandmarkName_SkyPillar, FLAG_LANDMARK_SKY_PILLAR};
static const struct Landmark Landmark_MirageTower = {LandmarkName_MirageTower, FLAG_LANDMARK_MIRAGE_TOWER};
static const struct Landmark Landmark_AlteringCave = {LandmarkName_AlteringCave, FLAG_LANDMARK_ALTERING_CAVE};
static const struct Landmark Landmark_DesertUnderpass = {LandmarkName_DesertUnderpass, FLAG_LANDMARK_DESERT_UNDERPASS};
static const struct Landmark Landmark_TrainerHill = {LandmarkName_TrainerHill, FLAG_LANDMARK_TRAINER_HILL};

static const struct Landmark *const Landmarks_Route103_2[]  =
{
    &Landmark_AlteringCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route104_0[]  =
{
    &Landmark_FlowerShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route104_1[]  =
{
    &Landmark_PetalburgWoods,
    &Landmark_MrBrineysCottage,
    NULL,
};

static const struct Landmark *const Landmarks_Route105_0[]  =
{
    &Landmark_IslandCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route106_1[]  =
{
    &Landmark_GraniteCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route108_0[]  =
{
    &Landmark_AbandonedShip,
    NULL,
};

static const struct Landmark *const Landmarks_Route109_0[]  =
{
    &Landmark_SeashoreHouse,
    &Landmark_SlateportBeach,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_0[]  =
{
    &Landmark_CyclingRoad,
    &Landmark_NewMauville,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_1[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_2[]  =
{
    &Landmark_CyclingRoad,
    &Landmark_TrickHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_0[]  =
{
    &Landmark_OldLadysRestShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_1[]  =
{
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_2[]  =
{
    &Landmark_MirageTower,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_3[]  =
{
    &Landmark_DesertRuins,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_4[]  =
{
    &Landmark_TrainerHill,
    &Landmark_WinstrateFamily,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_0[]  =
{
    &Landmark_FieryPath,
    &Landmark_JaggedPass,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_1[]  =
{
    &Landmark_CableCar,
    &Landmark_FieryPath,
    NULL,
};

static const struct Landmark *const Landmarks_Route113_1[]  =
{
    &Landmark_GlassWorkshop,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_1[]  =
{
    &Landmark_DesertUnderpass,
    &Landmark_FossilManiacsHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_2[]  =
{
    &Landmark_LanettesHouse,
    NULL,
};

static const struct Landmark *const Landmarks_MeteorFalls[]  =
{
    &Landmark_MeteorFalls,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_1[]  =
{
    &Landmark_TunnelersRestHouse,
    &Landmark_RusturfTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_2[]  =
{
    &Landmark_RusturfTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route117_2[]  =
{
    &Landmark_PokemonDayCare,
    NULL,
};

static const struct Landmark *const Landmarks_Route119_1[]  =
{
    &Landmark_WeatherInstitute,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_0[]  =
{
    &Landmark_ScorchedSlab,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_2[]  =
{
    &Landmark_AncientTomb,
    NULL,
};

static const struct Landmark *const Landmarks_Route121_2[]  =
{
    &Landmark_SafariZoneEntrance,
    NULL,
};

static const struct Landmark *const Landmarks_Route122_0[]  =
{
    &Landmark_MtPyre,
    NULL,
};

static const struct Landmark *const Landmarks_Route123_0[]  =
{
    &Landmark_BerryMastersHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route124_7[]  =
{
    &Landmark_HuntersHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route125_2[]  =
{
    &Landmark_ShoalCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route128_1[]  =
{
    &Landmark_SeafloorCavern,
    NULL,
};

static const struct Landmark *const Landmarks_Route131_1[]  =
{
    &Landmark_SkyPillar,
    NULL,
};

static const struct Landmark *const Landmarks_OceanCurrent[]  =
{
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_Route134_2[]  =
{
    &Landmark_SealedChamber,
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_MtChimney_2[]  =
{
    &Landmark_CableCar,
    &Landmark_JaggedPass,
    NULL,
};

static const struct LandmarkList sLandmarkLists[] =
{
    {MAPSEC_ROUTE_103, 2, Landmarks_Route103_2},
    {MAPSEC_ROUTE_104, 0, Landmarks_Route104_0},
    {MAPSEC_ROUTE_104, 1, Landmarks_Route104_1},
    {MAPSEC_ROUTE_105, 0, Landmarks_Route105_0},
    {MAPSEC_ROUTE_106, 1, Landmarks_Route106_1},
    {MAPSEC_ROUTE_108, 0, Landmarks_Route108_0},
    {MAPSEC_ROUTE_109, 0, Landmarks_Route109_0},
    {MAPSEC_ROUTE_110, 0, Landmarks_Route110_0},
    {MAPSEC_ROUTE_110, 1, Landmarks_Route110_1},
    {MAPSEC_ROUTE_110, 2, Landmarks_Route110_2},
    {MAPSEC_ROUTE_111, 0, Landmarks_Route111_0},
    {MAPSEC_ROUTE_111, 1, Landmarks_Route111_1},
    {MAPSEC_ROUTE_111, 2, Landmarks_Route111_2},
    {MAPSEC_ROUTE_111, 3, Landmarks_Route111_3},
    {MAPSEC_ROUTE_111, 4, Landmarks_Route111_4},
    {MAPSEC_ROUTE_112, 0, Landmarks_Route112_0},
    {MAPSEC_ROUTE_112, 1, Landmarks_Route112_1},
    {MAPSEC_ROUTE_113, 1, Landmarks_Route113_1},
    {MAPSEC_ROUTE_114, 1, Landmarks_Route114_1},
    {MAPSEC_ROUTE_114, 2, Landmarks_Route114_2},
    {MAPSEC_ROUTE_114, 3, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_115, 0, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_115, 1, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_116, 1, Landmarks_Route116_1},
    {MAPSEC_ROUTE_116, 2, Landmarks_Route116_2},
    {MAPSEC_ROUTE_117, 2, Landmarks_Route117_2},
    {MAPSEC_ROUTE_119, 1, Landmarks_Route119_1},
    {MAPSEC_ROUTE_120, 0, Landmarks_Route120_0},
    {MAPSEC_ROUTE_120, 2, Landmarks_Route120_2},
    {MAPSEC_ROUTE_121, 2, Landmarks_Route121_2},
    {MAPSEC_ROUTE_122, 0, Landmarks_Route122_0},
    {MAPSEC_ROUTE_123, 0, Landmarks_Route123_0},
    {MAPSEC_ROUTE_122, 1, Landmarks_Route122_0},
    {MAPSEC_ROUTE_124, 7, Landmarks_Route124_7},
    {MAPSEC_ROUTE_125, 2, Landmarks_Route125_2},
    {MAPSEC_ROUTE_128, 1, Landmarks_Route128_1},
    {MAPSEC_ROUTE_131, 1, Landmarks_Route131_1},
    {MAPSEC_ROUTE_132, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_132, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 2, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 2, Landmarks_Route134_2},
    {MAPSEC_MT_CHIMNEY, 2, Landmarks_MtChimney_2},
    {MAPSEC_NONE, 0, NULL},
};

static const struct Landmark *const *GetLandmarks(u8 mapSection, u8 id);

const u8 *GetLandmarkName(u8 mapSection, u8 id, u8 count)
{
    const struct Landmark *const *landmarks = GetLandmarks(mapSection, id);

    if (!landmarks)
        return NULL;

    while (1)
    {
        const struct Landmark *landmark = *landmarks;

        if (landmark->flag == 0xFFFF || FlagGet(landmark->flag) == TRUE)
        {
            if (count == 0)
                break;
            else
                count--;
        }

        landmarks++;
        if (!*landmarks)
            return NULL;
    }

    return (*landmarks)->name;
}

static const struct Landmark *const *GetLandmarks(u8 mapSection, u8 id)
{
    u16 i = 0;

    for (; sLandmarkLists[i].mapSection != MAPSEC_NONE; i++)
    {
        if (sLandmarkLists[i].mapSection > mapSection)
            return NULL;
        if (sLandmarkLists[i].mapSection == mapSection)
            break;
    }

    if (sLandmarkLists[i].mapSection == MAPSEC_NONE)
        return NULL;

    for (; sLandmarkLists[i].mapSection == mapSection; i++)
    {
        if (sLandmarkLists[i].id == id)
            return sLandmarkLists[i].landmarks;
    }

    return NULL;
}
