#include "fieldmap.h"

// Whether a palette has a night version, located at ((x + 9) % 16).pal
#define SWAP_PAL(x) ((x) < NUM_PALS_IN_PRIMARY ? 1 << (x) : 1 << ((x) - NUM_PALS_IN_PRIMARY))

const struct Tileset gTileset_SecretBase =
{
    .isCompressed = FALSE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SecretBase,
    .palettes = gTilesetPalettes_SecretBase,
    .metatiles = gMetatiles_SecretBasePrimary,
    .metatileAttributes = gMetatileAttributes_SecretBasePrimary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseRedCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseRedCave,
    .palettes = gTilesetPalettes_SecretBaseRedCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset *const gTilesetPointer_SecretBase = &gTileset_SecretBase;
const struct Tileset *const gTilesetPointer_SecretBaseRedCave = &gTileset_SecretBaseRedCave;

#if !IS_FRLG

const struct Tileset gTileset_General =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General,
    .palettes = gTilesetPalettes_General,
    .metatiles = gMetatiles_General,
    .metatileAttributes = gMetatileAttributes_General,
    .callback = InitTilesetAnim_General,
};

const struct Tileset gTileset_Petalburg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Petalburg,
    .palettes = gTilesetPalettes_Petalburg,
    .metatiles = gMetatiles_Petalburg,
    .metatileAttributes = gMetatileAttributes_Petalburg,
    .callback = InitTilesetAnim_Petalburg,
};

const struct Tileset gTileset_Rustboro =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Rustboro,
    .palettes = gTilesetPalettes_Rustboro,
    .metatiles = gMetatiles_Rustboro,
    .metatileAttributes = gMetatileAttributes_Rustboro,
    .callback = InitTilesetAnim_Rustboro,
};

const struct Tileset gTileset_Dewford =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Dewford,
    .palettes = gTilesetPalettes_Dewford,
    .metatiles = gMetatiles_Dewford,
    .metatileAttributes = gMetatileAttributes_Dewford,
    .callback = InitTilesetAnim_Dewford,
};

const struct Tileset gTileset_Slateport =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Slateport,
    .palettes = gTilesetPalettes_Slateport,
    .metatiles = gMetatiles_Slateport,
    .metatileAttributes = gMetatileAttributes_Slateport,
    .callback = InitTilesetAnim_Slateport,
};

const struct Tileset gTileset_Mauville =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mauville,
    .palettes = gTilesetPalettes_Mauville,
    .metatiles = gMetatiles_Mauville,
    .metatileAttributes = gMetatileAttributes_Mauville,
    .callback = InitTilesetAnim_Mauville,
};

const struct Tileset gTileset_Lavaridge =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lavaridge,
    .palettes = gTilesetPalettes_Lavaridge,
    .metatiles = gMetatiles_Lavaridge,
    .metatileAttributes = gMetatileAttributes_Lavaridge,
    .callback = InitTilesetAnim_Lavaridge,
};

const struct Tileset gTileset_Fallarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fallarbor,
    .palettes = gTilesetPalettes_Fallarbor,
    .metatiles = gMetatiles_Fallarbor,
    .metatileAttributes = gMetatileAttributes_Fallarbor,
    .callback = InitTilesetAnim_Fallarbor,
};

const struct Tileset gTileset_Fortree =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fortree,
    .palettes = gTilesetPalettes_Fortree,
    .metatiles = gMetatiles_Fortree,
    .metatileAttributes = gMetatileAttributes_Fortree,
    .callback = InitTilesetAnim_Fortree,
};

const struct Tileset gTileset_Lilycove =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lilycove,
    .palettes = gTilesetPalettes_Lilycove,
    .metatiles = gMetatiles_Lilycove,
    .metatileAttributes = gMetatileAttributes_Lilycove,
    .callback = InitTilesetAnim_Lilycove,
};

const struct Tileset gTileset_Mossdeep =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mossdeep,
    .palettes = gTilesetPalettes_Mossdeep,
    .metatiles = gMetatiles_Mossdeep,
    .metatileAttributes = gMetatileAttributes_Mossdeep,
    .callback = InitTilesetAnim_Mossdeep,
};

const struct Tileset gTileset_EverGrande =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EverGrande,
    .palettes = gTilesetPalettes_EverGrande,
    .metatiles = gMetatiles_EverGrande,
    .metatileAttributes = gMetatileAttributes_EverGrande,
    .callback = InitTilesetAnim_EverGrande,
};

const struct Tileset gTileset_Pacifidlog =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Pacifidlog,
    .palettes = gTilesetPalettes_Pacifidlog,
    .metatiles = gMetatiles_Pacifidlog,
    .metatileAttributes = gMetatileAttributes_Pacifidlog,
    .callback = InitTilesetAnim_Pacifidlog,
};

const struct Tileset gTileset_Sootopolis =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Sootopolis,
    .palettes = gTilesetPalettes_Sootopolis,
    .metatiles = gMetatiles_Sootopolis,
    .metatileAttributes = gMetatileAttributes_Sootopolis,
    .callback = InitTilesetAnim_Sootopolis,
};

const struct Tileset gTileset_BattleFrontierOutsideWest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideWest,
    .palettes = gTilesetPalettes_BattleFrontierOutsideWest,
    .metatiles = gMetatiles_BattleFrontierOutsideWest,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideWest,
    .callback = InitTilesetAnim_BattleFrontierOutsideWest,
};

const struct Tileset gTileset_BattleFrontierOutsideEast =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideEast,
    .palettes = gTilesetPalettes_BattleFrontierOutsideEast,
    .metatiles = gMetatiles_BattleFrontierOutsideEast,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideEast,
    .callback = InitTilesetAnim_BattleFrontierOutsideEast,
};

const struct Tileset gTileset_Building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_InsideBuilding,
    .palettes = gTilesetPalettes_InsideBuilding,
    .metatiles = gMetatiles_InsideBuilding,
    .metatileAttributes = gMetatileAttributes_InsideBuilding,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_Shop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Shop,
    .palettes = gTilesetPalettes_Shop,
    .metatiles = gMetatiles_Shop,
    .metatileAttributes = gMetatileAttributes_Shop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenter =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter,
    .palettes = gTilesetPalettes_PokemonCenter,
    .metatiles = gMetatiles_PokemonCenter,
    .metatileAttributes = gMetatileAttributes_PokemonCenter,
    .callback = NULL,
};

const struct Tileset gTileset_Cave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave,
    .palettes = gTilesetPalettes_Cave,
    .metatiles = gMetatiles_Cave,
    .metatileAttributes = gMetatileAttributes_Cave,
    .callback = InitTilesetAnim_Cave,
};

const struct Tileset gTileset_PokemonSchool =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonSchool,
    .palettes = gTilesetPalettes_PokemonSchool,
    .metatiles = gMetatiles_PokemonSchool,
    .metatileAttributes = gMetatileAttributes_PokemonSchool,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonFanClub =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonFanClub,
    .palettes = gTilesetPalettes_PokemonFanClub,
    .metatiles = gMetatiles_PokemonFanClub,
    .metatileAttributes = gMetatileAttributes_PokemonFanClub,
    .callback = NULL,
};

const struct Tileset gTileset_Unused1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused1,
    .palettes = gTilesetPalettes_Unused1,
    .metatiles = gMetatiles_Unused1,
    .metatileAttributes = gMetatileAttributes_Unused1,
    .callback = NULL,
};

const struct Tileset gTileset_MeteorFalls =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MeteorFalls,
    .palettes = gTilesetPalettes_MeteorFalls,
    .metatiles = gMetatiles_MeteorFalls,
    .metatileAttributes = gMetatileAttributes_MeteorFalls,
    .callback = NULL,
};

const struct Tileset gTileset_OceanicMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OceanicMuseum,
    .palettes = gTilesetPalettes_OceanicMuseum,
    .metatiles = gMetatiles_OceanicMuseum,
    .metatileAttributes = gMetatileAttributes_OceanicMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_CableClub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClub,
    .palettes = gTilesetPalettes_CableClub,
    .metatiles = gMetatiles_CableClub,
    .metatileAttributes = gMetatileAttributes_CableClub,
    .callback = NULL,
};

const struct Tileset gTileset_SeashoreHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeashoreHouse,
    .palettes = gTilesetPalettes_SeashoreHouse,
    .metatiles = gMetatiles_SeashoreHouse,
    .metatileAttributes = gMetatileAttributes_SeashoreHouse,
    .callback = NULL,
};

const struct Tileset gTileset_PrettyPetalFlowerShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PrettyPetalFlowerShop,
    .palettes = gTilesetPalettes_PrettyPetalFlowerShop,
    .metatiles = gMetatiles_PrettyPetalFlowerShop,
    .metatileAttributes = gMetatileAttributes_PrettyPetalFlowerShop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonDayCare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonDayCare,
    .palettes = gTilesetPalettes_PokemonDayCare,
    .metatiles = gMetatiles_PokemonDayCare,
    .metatileAttributes = gMetatileAttributes_PokemonDayCare,
    .callback = NULL,
};

const struct Tileset gTileset_Facility =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Facility,
    .palettes = gTilesetPalettes_Facility,
    .metatiles = gMetatiles_Facility,
    .metatileAttributes = gMetatileAttributes_Facility,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop,
    .palettes = gTilesetPalettes_BikeShop,
    .metatiles = gMetatiles_BikeShop,
    .metatileAttributes = gMetatileAttributes_BikeShop,
    .callback = InitTilesetAnim_BikeShop,
};

const struct Tileset gTileset_RusturfTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RusturfTunnel,
    .palettes = gTilesetPalettes_RusturfTunnel,
    .metatiles = gMetatiles_RusturfTunnel,
    .metatileAttributes = gMetatileAttributes_RusturfTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBrownCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBrownCave,
    .palettes = gTilesetPalettes_SecretBaseBrownCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseTree =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseTree,
    .palettes = gTilesetPalettes_SecretBaseTree,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseShrub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseShrub,
    .palettes = gTilesetPalettes_SecretBaseShrub,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBlueCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBlueCave,
    .palettes = gTilesetPalettes_SecretBaseBlueCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseYellowCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseYellowCave,
    .palettes = gTilesetPalettes_SecretBaseYellowCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_InsideOfTruck =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideOfTruck,
    .palettes = gTilesetPalettes_InsideOfTruck,
    .metatiles = gMetatiles_InsideOfTruck,
    .metatileAttributes = gMetatileAttributes_InsideOfTruck,
    .callback = NULL,
};

const struct Tileset gTileset_Unused2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused2,
    .palettes = gTilesetPalettes_Unused2,
    .metatiles = gMetatiles_Unused2,
    .metatileAttributes = gMetatileAttributes_Unused2,
    .callback = NULL,
};

const struct Tileset gTileset_Contest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Contest,
    .palettes = gTilesetPalettes_Contest,
    .metatiles = gMetatiles_Contest,
    .metatileAttributes = gMetatileAttributes_Contest,
    .callback = NULL,
};

const struct Tileset gTileset_LilycoveMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LilycoveMuseum,
    .palettes = gTilesetPalettes_LilycoveMuseum,
    .metatiles = gMetatiles_LilycoveMuseum,
    .metatileAttributes = gMetatileAttributes_LilycoveMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_BrendansMaysHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BrendansMaysHouse,
    .palettes = gTilesetPalettes_BrendansMaysHouse,
    .metatiles = gMetatiles_BrendansMaysHouse,
    .metatileAttributes = gMetatileAttributes_BrendansMaysHouse,
    .callback = NULL,
};

const struct Tileset gTileset_Lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lab,
    .palettes = gTilesetPalettes_Lab,
    .metatiles = gMetatiles_Lab,
    .metatileAttributes = gMetatileAttributes_Lab,
    .callback = NULL,
};

const struct Tileset gTileset_Underwater =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Underwater,
    .palettes = gTilesetPalettes_Underwater,
    .metatiles = gMetatiles_Underwater,
    .metatileAttributes = gMetatileAttributes_Underwater,
    .callback = InitTilesetAnim_Underwater,
};

const struct Tileset gTileset_PetalburgGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PetalburgGym,
    .palettes = gTilesetPalettes_PetalburgGym,
    .metatiles = gMetatiles_PetalburgGym,
    .metatileAttributes = gMetatileAttributes_PetalburgGym,
    .callback = NULL,
};

const struct Tileset gTileset_SootopolisGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootopolisGym,
    .palettes = gTilesetPalettes_SootopolisGym,
    .metatiles = gMetatiles_SootopolisGym,
    .metatileAttributes = gMetatileAttributes_SootopolisGym,
    .callback = InitTilesetAnim_SootopolisGym,
};

const struct Tileset gTileset_GenericBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding,
    .palettes = gTilesetPalettes_GenericBuilding,
    .metatiles = gMetatiles_GenericBuilding,
    .metatileAttributes = gMetatileAttributes_GenericBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGameCorner,
    .palettes = gTilesetPalettes_MauvilleGameCorner,
    .metatiles = gMetatiles_MauvilleGameCorner,
    .metatileAttributes = gMetatileAttributes_MauvilleGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_RustboroGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RustboroGym,
    .palettes = gTilesetPalettes_RustboroGym,
    .metatiles = gMetatiles_RustboroGym,
    .metatileAttributes = gMetatileAttributes_RustboroGym,
    .callback = NULL,
};

const struct Tileset gTileset_DewfordGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DewfordGym,
    .palettes = gTilesetPalettes_DewfordGym,
    .metatiles = gMetatiles_DewfordGym,
    .metatileAttributes = gMetatileAttributes_DewfordGym,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGym,
    .palettes = gTilesetPalettes_MauvilleGym,
    .metatiles = gMetatiles_MauvilleGym,
    .metatileAttributes = gMetatileAttributes_MauvilleGym,
    .callback = InitTilesetAnim_MauvilleGym,
};

const struct Tileset gTileset_LavaridgeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavaridgeGym,
    .palettes = gTilesetPalettes_LavaridgeGym,
    .metatiles = gMetatiles_LavaridgeGym,
    .metatileAttributes = gMetatileAttributes_LavaridgeGym,
    .callback = NULL,
};

const struct Tileset gTileset_TrickHousePuzzle =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrickHousePuzzle,
    .palettes = gTilesetPalettes_TrickHousePuzzle,
    .metatiles = gMetatiles_TrickHousePuzzle,
    .metatileAttributes = gMetatileAttributes_TrickHousePuzzle,
    .callback = NULL,
};

const struct Tileset gTileset_FortreeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FortreeGym,
    .palettes = gTilesetPalettes_FortreeGym,
    .metatiles = gMetatiles_FortreeGym,
    .metatileAttributes = gMetatileAttributes_FortreeGym,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGym,
    .palettes = gTilesetPalettes_MossdeepGym,
    .metatiles = gMetatiles_MossdeepGym,
    .metatileAttributes = gMetatileAttributes_MossdeepGym,
    .callback = NULL,
};

const struct Tileset gTileset_InsideShip =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideShip,
    .palettes = gTilesetPalettes_InsideShip,
    .metatiles = gMetatiles_InsideShip,
    .metatileAttributes = gMetatileAttributes_InsideShip,
    .callback = NULL,
};

const struct Tileset gTileset_EliteFour =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EliteFour,
    .palettes = gTilesetPalettes_EliteFour,
    .metatiles = gMetatiles_EliteFour,
    .metatileAttributes = gMetatileAttributes_EliteFour,
    .callback = InitTilesetAnim_EliteFour,
};

const struct Tileset gTileset_BattleFrontier =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontier,
    .palettes = gTilesetPalettes_BattleFrontier,
    .metatiles = gMetatiles_BattleFrontier,
    .metatileAttributes = gMetatileAttributes_BattleFrontier,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePalace =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePalace,
    .palettes = gTilesetPalettes_BattlePalace,
    .metatiles = gMetatiles_BattlePalace,
    .metatileAttributes = gMetatileAttributes_BattlePalace,
    .callback = NULL,
};

const struct Tileset gTileset_BattleDome =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleDome,
    .palettes = gTilesetPalettes_BattleDome,
    .metatiles = gMetatiles_BattleDome,
    .metatileAttributes = gMetatileAttributes_BattleDome,
    .callback = InitTilesetAnim_BattleDome,
};

const struct Tileset gTileset_BattleFactory =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFactory,
    .palettes = gTilesetPalettes_BattleFactory,
    .metatiles = gMetatiles_BattleFactory,
    .metatileAttributes = gMetatileAttributes_BattleFactory,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePike =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePike,
    .palettes = gTilesetPalettes_BattlePike,
    .metatiles = gMetatiles_BattlePike,
    .metatileAttributes = gMetatileAttributes_BattlePike,
    .callback = NULL,
};

const struct Tileset gTileset_BattleArena =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleArena,
    .palettes = gTilesetPalettes_BattleArena,
    .metatiles = gMetatiles_BattleArena,
    .metatileAttributes = gMetatileAttributes_BattleArena,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePyramid =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePyramid,
    .palettes = gTilesetPalettes_BattlePyramid,
    .metatiles = gMetatiles_BattlePyramid,
    .metatileAttributes = gMetatileAttributes_BattlePyramid,
    .callback = InitTilesetAnim_BattlePyramid,
};

const struct Tileset gTileset_MirageTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MirageTower,
    .palettes = gTilesetPalettes_MirageTower,
    .metatiles = gMetatiles_MirageTower,
    .metatileAttributes = gMetatileAttributes_MirageTower,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGameCorner,
    .palettes = gTilesetPalettes_MossdeepGameCorner,
    .metatiles = gMetatiles_MossdeepGameCorner,
    .metatileAttributes = gMetatileAttributes_MossdeepGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_IslandHarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IslandHarbor,
    .palettes = gTilesetPalettes_IslandHarbor,
    .metatiles = gMetatiles_IslandHarbor,
    .metatileAttributes = gMetatileAttributes_IslandHarbor,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerHill =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerHill,
    .palettes = gTilesetPalettes_TrainerHill,
    .metatiles = gMetatiles_TrainerHill,
    .metatileAttributes = gMetatileAttributes_TrainerHill,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRock =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRock,
    .palettes = gTilesetPalettes_NavelRock,
    .metatiles = gMetatiles_NavelRock,
    .metatileAttributes = gMetatileAttributes_NavelRock,
    .callback = NULL,
};

const struct Tileset gTileset_BattleFrontierRankingHall =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierRankingHall,
    .palettes = gTilesetPalettes_BattleFrontierRankingHall,
    .metatiles = gMetatiles_BattleFrontierRankingHall,
    .metatileAttributes = gMetatileAttributes_BattleFrontierRankingHall,
    .callback = NULL,
};

const struct Tileset gTileset_BattleTent =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleTent,
    .palettes = gTilesetPalettes_BattleTent,
    .metatiles = gMetatiles_BattleTent,
    .metatileAttributes = gMetatileAttributes_BattleTent,
    .callback = NULL,
};

const struct Tileset gTileset_MysteryEventsHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MysteryEventsHouse,
    .palettes = gTilesetPalettes_MysteryEventsHouse,
    .metatiles = gMetatiles_MysteryEventsHouse,
    .metatileAttributes = gMetatileAttributes_MysteryEventsHouse,
    .callback = NULL,
};

const struct Tileset gTileset_UnionRoom =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnionRoom,
    .palettes = gTilesetPalettes_UnionRoom,
    .metatiles = gMetatiles_UnionRoom,
    .metatileAttributes = gMetatileAttributes_UnionRoom,
    .callback = NULL,
};

#else

// FRLG tilesets
const struct Tileset gTileset_BuildingFrlg =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Building_Frlg,
    .palettes = gTilesetPalettes_Building_Frlg,
    .metatiles = gMetatiles_Building_Frlg,
    .metatileAttributes = gMetatileAttributes_Building_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_General_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General_Frlg,
    .palettes = gTilesetPalettes_General_Frlg,
    .metatiles = gMetatiles_General_Frlg,
    .metatileAttributes = gMetatileAttributes_General_Frlg,
    .callback = InitTilesetAnim_General_Frlg,
};

const struct Tileset gTileset_PalletTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PalletTown,
    .palettes = gTilesetPalettes_PalletTown,
    .metatiles = gMetatiles_PalletTown,
    .metatileAttributes = gMetatileAttributes_PalletTown,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCity,
    .palettes = gTilesetPalettes_ViridianCity,
    .metatiles = gMetatiles_ViridianCity,
    .metatileAttributes = gMetatileAttributes_ViridianCity,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCity,
    .palettes = gTilesetPalettes_PewterCity,
    .metatiles = gMetatiles_PewterCity,
    .metatileAttributes = gMetatileAttributes_PewterCity,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCity,
    .palettes = gTilesetPalettes_CeruleanCity,
    .metatiles = gMetatiles_CeruleanCity,
    .metatileAttributes = gMetatileAttributes_CeruleanCity,
    .callback = NULL,
};

const struct Tileset gTileset_LavenderTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavenderTown,
    .palettes = gTilesetPalettes_LavenderTown,
    .metatiles = gMetatiles_LavenderTown,
    .metatileAttributes = gMetatileAttributes_LavenderTown,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionCity,
    .palettes = gTilesetPalettes_VermilionCity,
    .metatiles = gMetatiles_VermilionCity,
    .metatileAttributes = gMetatileAttributes_VermilionCity,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonCity,
    .palettes = gTilesetPalettes_CeladonCity,
    .metatiles = gMetatiles_CeladonCity,
    .metatileAttributes = gMetatileAttributes_CeladonCity,
    .callback = InitTilesetAnim_CeladonCity,
};

const struct Tileset gTileset_FuchsiaCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaCity,
    .palettes = gTilesetPalettes_FuchsiaCity,
    .metatiles = gMetatiles_FuchsiaCity,
    .metatileAttributes = gMetatileAttributes_FuchsiaCity,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarIsland =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarIsland,
    .palettes = gTilesetPalettes_CinnabarIsland,
    .metatiles = gMetatiles_CinnabarIsland,
    .metatileAttributes = gMetatileAttributes_CinnabarIsland,
    .callback = NULL,
};

const struct Tileset gTileset_IndigoPlateau =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IndigoPlateau,
    .palettes = gTilesetPalettes_IndigoPlateau,
    .metatiles = gMetatiles_IndigoPlateau,
    .metatileAttributes = gMetatileAttributes_IndigoPlateau,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity,
    .palettes = gTilesetPalettes_SaffronCity,
    .metatiles = gMetatiles_SaffronCity,
    .metatileAttributes = gMetatileAttributes_SaffronCity,
    .callback = NULL,
};

const struct Tileset gTileset_Mart =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mart,
    .palettes = gTilesetPalettes_Mart,
    .metatiles = gMetatiles_Mart,
    .metatileAttributes = gMetatileAttributes_Mart,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenterFrlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter_Frlg,
    .palettes = gTilesetPalettes_PokemonCenter_Frlg,
    .metatiles = gMetatiles_PokemonCenter_Frlg,
    .metatileAttributes = gMetatileAttributes_PokemonCenter_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Frlg,
    .palettes = gTilesetPalettes_Cave_Frlg,
    .metatiles = gMetatiles_Cave_Frlg,
    .metatileAttributes = gMetatileAttributes_Cave_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_Museum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Museum,
    .palettes = gTilesetPalettes_Museum,
    .metatiles = gMetatiles_Museum,
    .metatileAttributes = gMetatileAttributes_Museum,
    .callback = NULL,
};

const struct Tileset gTileset_CableClub_Frlg =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClub_Frlg,
    .palettes = gTilesetPalettes_CableClub_Frlg,
    .metatiles = gMetatiles_CableClub_Frlg,
    .metatileAttributes = gMetatileAttributes_CableClub_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop_Frlg,
    .palettes = gTilesetPalettes_BikeShop_Frlg,
    .metatiles = gMetatiles_BikeShop_Frlg,
    .metatileAttributes = gMetatileAttributes_BikeShop_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_GenericBuilding1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding1,
    .palettes = gTilesetPalettes_GenericBuilding1,
    .metatiles = gMetatiles_GenericBuilding1,
    .metatileAttributes = gMetatileAttributes_GenericBuilding1,
    .callback = NULL,
};

const struct Tileset gTileset_Lab_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lab_Frlg,
    .palettes = gTilesetPalettes_Lab_Frlg,
    .metatiles = gMetatiles_Lab_Frlg,
    .metatileAttributes = gMetatileAttributes_Lab_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaGym,
    .palettes = gTilesetPalettes_FuchsiaGym,
    .metatiles = gMetatiles_FuchsiaGym,
    .metatileAttributes = gMetatileAttributes_FuchsiaGym,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianGym,
    .palettes = gTilesetPalettes_ViridianGym,
    .metatiles = gMetatiles_ViridianGym,
    .metatileAttributes = gMetatileAttributes_ViridianGym,
    .callback = NULL,
};

const struct Tileset gTileset_HoennBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HoennBuilding,
    .palettes = gTilesetPalettes_HoennBuilding,
    .metatiles = gMetatiles_HoennBuilding,
    .metatileAttributes = gMetatileAttributes_HoennBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_GameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GameCorner,
    .palettes = gTilesetPalettes_GameCorner,
    .metatiles = gMetatiles_GameCorner,
    .metatileAttributes = gMetatileAttributes_GameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_PewterGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterGym,
    .palettes = gTilesetPalettes_PewterGym,
    .metatiles = gMetatiles_PewterGym,
    .metatileAttributes = gMetatileAttributes_PewterGym,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanGym,
    .palettes = gTilesetPalettes_CeruleanGym,
    .metatiles = gMetatiles_CeruleanGym,
    .metatileAttributes = gMetatileAttributes_CeruleanGym,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionGym,
    .palettes = gTilesetPalettes_VermilionGym,
    .metatiles = gMetatiles_VermilionGym,
    .metatileAttributes = gMetatileAttributes_VermilionGym,
    .callback = InitTilesetAnim_VermilionGym,
};

const struct Tileset gTileset_CeladonGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonGym,
    .palettes = gTilesetPalettes_CeladonGym,
    .metatiles = gMetatiles_CeladonGym,
    .metatileAttributes = gMetatileAttributes_CeladonGym,
    .callback = InitTilesetAnim_CeladonGym,
};

const struct Tileset gTileset_SaffronGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronGym,
    .palettes = gTilesetPalettes_SaffronGym,
    .metatiles = gMetatiles_SaffronGym,
    .metatileAttributes = gMetatileAttributes_SaffronGym,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarGym,
    .palettes = gTilesetPalettes_CinnabarGym,
    .metatiles = gMetatiles_CinnabarGym,
    .metatileAttributes = gMetatileAttributes_CinnabarGym,
    .callback = NULL,
};

const struct Tileset gTileset_SSAnne =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SSAnne,
    .palettes = gTilesetPalettes_SSAnne,
    .metatiles = gMetatiles_SSAnne,
    .metatileAttributes = gMetatileAttributes_SSAnne,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianForest,
    .palettes = gTilesetPalettes_ViridianForest,
    .metatiles = gMetatiles_ViridianForest,
    .metatileAttributes = gMetatileAttributes_ViridianForest,
    .callback = NULL,
};

const struct Tileset gTileset_UnusedGatehouse1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnusedGatehouse1,
    .palettes = gTilesetPalettes_UnusedGatehouse1,
    .metatiles = gMetatiles_UnusedGatehouse1,
    .metatileAttributes = gMetatileAttributes_UnusedGatehouse1,
    .callback = NULL,
};

const struct Tileset gTileset_RockTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RockTunnel,
    .palettes = gTilesetPalettes_RockTunnel,
    .metatiles = gMetatiles_RockTunnel,
    .metatileAttributes = gMetatileAttributes_RockTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_DiglettsCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DiglettsCave,
    .palettes = gTilesetPalettes_DiglettsCave,
    .metatiles = gMetatiles_DiglettsCave,
    .metatileAttributes = gMetatileAttributes_DiglettsCave,
    .callback = NULL,
};

const struct Tileset gTileset_SeafoamIslands =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeafoamIslands,
    .palettes = gTilesetPalettes_SeafoamIslands,
    .metatiles = gMetatiles_SeafoamIslands,
    .metatileAttributes = gMetatileAttributes_SeafoamIslands,
    .callback = NULL,
};

const struct Tileset gTileset_UnusedGatehouse2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnusedGatehouse2,
    .palettes = gTilesetPalettes_UnusedGatehouse2,
    .metatiles = gMetatiles_UnusedGatehouse2,
    .metatileAttributes = gMetatileAttributes_UnusedGatehouse2,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCave,
    .palettes = gTilesetPalettes_CeruleanCave,
    .metatiles = gMetatiles_CeruleanCave,
    .metatileAttributes = gMetatileAttributes_CeruleanCave,
    .callback = NULL,
};

const struct Tileset gTileset_DepartmentStore =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DepartmentStore,
    .palettes = gTilesetPalettes_DepartmentStore,
    .metatiles = gMetatiles_DepartmentStore,
    .metatileAttributes = gMetatileAttributes_DepartmentStore,
    .callback = NULL,
};

const struct Tileset gTileset_GenericBuilding2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding2,
    .palettes = gTilesetPalettes_GenericBuilding2,
    .metatiles = gMetatiles_GenericBuilding2,
    .metatileAttributes = gMetatileAttributes_GenericBuilding2,
    .callback = NULL,
};

const struct Tileset gTileset_PowerPlant =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PowerPlant,
    .palettes = gTilesetPalettes_PowerPlant,
    .metatiles = gMetatiles_PowerPlant,
    .metatileAttributes = gMetatileAttributes_PowerPlant,
    .callback = NULL,
};

const struct Tileset gTileset_SeaCottage =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeaCottage,
    .palettes = gTilesetPalettes_SeaCottage,
    .metatiles = gMetatiles_SeaCottage,
    .metatileAttributes = gMetatileAttributes_SeaCottage,
    .callback = NULL,
};

const struct Tileset gTileset_SilphCo =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Condominiums,
    .palettes = gTilesetPalettes_Condominiums,
    .metatiles = gMetatiles_SilphCo,
    .metatileAttributes = gMetatileAttributes_SilphCo,
    .callback = InitTilesetAnim_SilphCo,
};

const struct Tileset gTileset_UndergroundPath =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UndergroundPath,
    .palettes = gTilesetPalettes_UndergroundPath,
    .metatiles = gMetatiles_UndergroundPath,
    .metatileAttributes = gMetatileAttributes_UndergroundPath,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonTower,
    .palettes = gTilesetPalettes_PokemonTower,
    .metatiles = gMetatiles_PokemonTower,
    .metatileAttributes = gMetatileAttributes_PokemonTower,
    .callback = NULL,
};

const struct Tileset gTileset_SafariZoneBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SafariZoneBuilding,
    .palettes = gTilesetPalettes_SafariZoneBuilding,
    .metatiles = gMetatiles_SafariZoneBuilding,
    .metatileAttributes = gMetatileAttributes_SafariZoneBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonMansion =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonMansion,
    .palettes = gTilesetPalettes_PokemonMansion,
    .metatiles = gMetatiles_PokemonMansion,
    .metatileAttributes = gMetatileAttributes_PokemonMansion,
    .callback = NULL,
};

const struct Tileset gTileset_RestaurantHotel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RestaurantHotel,
    .palettes = gTilesetPalettes_RestaurantHotel,
    .metatiles = gMetatiles_RestaurantHotel,
    .metatileAttributes = gMetatileAttributes_RestaurantHotel,
    .callback = NULL,
};

const struct Tileset gTileset_School =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_School,
    .palettes = gTilesetPalettes_School,
    .metatiles = gMetatiles_School,
    .metatileAttributes = gMetatileAttributes_School,
    .callback = NULL,
};

const struct Tileset gTileset_FanClubDaycare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FanClubDaycare,
    .palettes = gTilesetPalettes_FanClubDaycare,
    .metatiles = gMetatiles_FanClubDaycare,
    .metatileAttributes = gMetatileAttributes_FanClubDaycare,
    .callback = NULL,
};

const struct Tileset gTileset_Condominiums =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Condominiums,
    .palettes = gTilesetPalettes_Condominiums,
    .metatiles = gMetatiles_Condominiums,
    .metatileAttributes = gMetatileAttributes_Condominiums,
    .callback = NULL,
};

const struct Tileset gTileset_BurgledHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BurgledHouse,
    .palettes = gTilesetPalettes_BurgledHouse,
    .metatiles = gMetatiles_BurgledHouse,
    .metatileAttributes = gMetatileAttributes_BurgledHouse,
    .callback = NULL,
};

const struct Tileset gTileset_MtEmber =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MtEmber,
    .palettes = gTilesetPalettes_MtEmber,
    .metatiles = gMetatiles_MtEmber,
    .metatileAttributes = gMetatileAttributes_MtEmber,
    .callback = InitTilesetAnim_MtEmber,
};

const struct Tileset gTileset_BerryForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BerryForest,
    .palettes = gTilesetPalettes_BerryForest,
    .metatiles = gMetatiles_BerryForest,
    .metatileAttributes = gMetatileAttributes_BerryForest,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRock_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRock_Frlg,
    .palettes = gTilesetPalettes_NavelRock_Frlg,
    .metatiles = gMetatiles_NavelRock_Frlg,
    .metatileAttributes = gMetatileAttributes_NavelRock_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_TanobyRuins =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TanobyRuins,
    .palettes = gTilesetPalettes_TanobyRuins,
    .metatiles = gMetatiles_TanobyRuins,
    .metatileAttributes = gMetatileAttributes_TanobyRuins,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIslands123 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIslands123,
    .palettes = gTilesetPalettes_SeviiIslands123,
    .metatiles = gMetatiles_SeviiIslands123,
    .metatileAttributes = gMetatileAttributes_SeviiIslands123,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIslands45 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIslands45,
    .palettes = gTilesetPalettes_SeviiIslands45,
    .metatiles = gMetatiles_SeviiIslands45,
    .metatileAttributes = gMetatileAttributes_SeviiIslands45,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIslands67 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIslands67,
    .palettes = gTilesetPalettes_SeviiIslands67,
    .metatiles = gMetatiles_SeviiIslands67,
    .metatileAttributes = gMetatileAttributes_SeviiIslands67,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerTower,
    .palettes = gTilesetPalettes_TrainerTower,
    .metatiles = gMetatiles_TrainerTower,
    .metatileAttributes = gMetatileAttributes_TrainerTower,
    .callback = NULL,
};

const struct Tileset gTileset_IslandHarbor_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IslandHarbor_Frlg,
    .palettes = gTilesetPalettes_IslandHarbor_Frlg,
    .metatiles = gMetatiles_IslandHarbor_Frlg,
    .metatileAttributes = gMetatileAttributes_IslandHarbor_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonLeague =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonLeague,
    .palettes = gTilesetPalettes_PokemonLeague,
    .metatiles = gMetatiles_PokemonLeague,
    .metatileAttributes = gMetatileAttributes_PokemonLeague,
    .callback = NULL,
};

const struct Tileset gTileset_HallOfFame =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HallOfFame,
    .palettes = gTilesetPalettes_HallOfFame,
    .metatiles = gMetatiles_HallOfFame,
    .metatileAttributes = gMetatileAttributes_HallOfFame,
    .callback = NULL,
};

#endif // IS_FRLG
