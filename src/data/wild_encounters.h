// const rom data

/*This file consists of several parts.
 *First, the actual tables that define the available Pokemon and their level ranges.
 *Second, the headers for each area that links the tables to the actual maps.
 *Third, Battle Pyramid-specific tables and headers.
 *Fourth, Battle Pike-specific tables and headers.
 *And then finally, Feebas-related data.
 *You can search for // to jump between the sections.
 */
 
 //Start of regular Pokemon tables.

const struct WildPokemon gRoute101_LandMons[] =
{
    {2, 2, SPECIES_WURMPLE},
    {2, 2, SPECIES_POOCHYENA},
    {2, 2, SPECIES_WURMPLE},
    {3, 3, SPECIES_WURMPLE},
    {3, 3, SPECIES_POOCHYENA},
    {3, 3, SPECIES_POOCHYENA},
    {3, 3, SPECIES_WURMPLE},
    {3, 3, SPECIES_POOCHYENA},
    {2, 2, SPECIES_ZIGZAGOON},
    {2, 2, SPECIES_ZIGZAGOON},
    {3, 3, SPECIES_ZIGZAGOON},
    {3, 3, SPECIES_ZIGZAGOON},
};

const struct WildPokemonInfo gRoute101_LandMonsInfo = {20, gRoute101_LandMons};

const struct WildPokemon gRoute102_LandMons[] =
{
    {3, 3, SPECIES_POOCHYENA},
    {3, 3, SPECIES_WURMPLE},
    {4, 4, SPECIES_POOCHYENA},
    {4, 4, SPECIES_WURMPLE},
    {3, 3, SPECIES_LOTAD},
    {4, 4, SPECIES_LOTAD},
    {3, 3, SPECIES_ZIGZAGOON},
    {3, 3, SPECIES_ZIGZAGOON},
    {4, 4, SPECIES_ZIGZAGOON},
    {4, 4, SPECIES_RALTS},
    {4, 4, SPECIES_ZIGZAGOON},
    {3, 3, SPECIES_SEEDOT},
};

const struct WildPokemonInfo gRoute102_LandMonsInfo = {20, gRoute102_LandMons};

const struct WildPokemon gRoute102_WaterMons[] =
{
    {20, 30, SPECIES_MARILL},
    {10, 20, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
    {20, 30, SPECIES_GOLDEEN},
};

const struct WildPokemonInfo gRoute102_WaterMonsInfo = {4, gRoute102_WaterMons};

const struct WildPokemon gRoute102_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_CORPHISH},
    {25, 30, SPECIES_CORPHISH},
    {30, 35, SPECIES_CORPHISH},
    {20, 25, SPECIES_CORPHISH},
    {35, 40, SPECIES_CORPHISH},
    {40, 45, SPECIES_CORPHISH},
};

const struct WildPokemonInfo gRoute102_FishingMonsInfo = {30, gRoute102_FishingMons};

const struct WildPokemon gRoute103_LandMons[] =
{
    {2, 2, SPECIES_POOCHYENA},
    {3, 3, SPECIES_POOCHYENA},
    {3, 3, SPECIES_POOCHYENA},
    {4, 4, SPECIES_POOCHYENA},
    {2, 2, SPECIES_WINGULL},
    {3, 3, SPECIES_ZIGZAGOON},
    {3, 3, SPECIES_ZIGZAGOON},
    {4, 4, SPECIES_ZIGZAGOON},
    {3, 3, SPECIES_WINGULL},
    {3, 3, SPECIES_WINGULL},
    {2, 2, SPECIES_WINGULL},
    {4, 4, SPECIES_WINGULL},
};

const struct WildPokemonInfo gRoute103_LandMonsInfo = {20, gRoute103_LandMons};

const struct WildPokemon gRoute103_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute103_WaterMonsInfo = {4, gRoute103_WaterMons};

const struct WildPokemon gRoute103_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute103_FishingMonsInfo = {30, gRoute103_FishingMons};

const struct WildPokemon gRoute104_LandMons[] =
{
    {4, 4, SPECIES_POOCHYENA},
    {4, 4, SPECIES_WURMPLE},
    {5, 5, SPECIES_POOCHYENA},
    {5, 5, SPECIES_MARILL},
    {4, 4, SPECIES_MARILL},
    {5, 5, SPECIES_POOCHYENA},
    {4, 4, SPECIES_TAILLOW},
    {5, 5, SPECIES_TAILLOW},
    {4, 4, SPECIES_WINGULL},
    {4, 4, SPECIES_WINGULL},
    {3, 3, SPECIES_WINGULL},
    {5, 5, SPECIES_WINGULL},
};

const struct WildPokemonInfo gRoute104_LandMonsInfo = {20, gRoute104_LandMons};

const struct WildPokemon gRoute104_WaterMons[] =
{
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute104_WaterMonsInfo = {4, gRoute104_WaterMons};

const struct WildPokemon gRoute104_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_MAGIKARP},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_MAGIKARP},
    {25, 30, SPECIES_MAGIKARP},
    {30, 35, SPECIES_MAGIKARP},
    {20, 25, SPECIES_MAGIKARP},
    {35, 40, SPECIES_MAGIKARP},
    {40, 45, SPECIES_MAGIKARP},
};

const struct WildPokemonInfo gRoute104_FishingMonsInfo = {30, gRoute104_FishingMons};

const struct WildPokemon gRoute105_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute105_WaterMonsInfo = {4, gRoute105_WaterMons};

const struct WildPokemon gRoute105_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute105_FishingMonsInfo = {30, gRoute105_FishingMons};

const struct WildPokemon gRoute110_LandMons[] =
{
    {12, 12, SPECIES_POOCHYENA},
    {12, 12, SPECIES_ELECTRIKE},
    {12, 12, SPECIES_GULPIN},
    {13, 13, SPECIES_ELECTRIKE},
    {13, 13, SPECIES_MINUN},
    {13, 13, SPECIES_ODDISH},
    {13, 13, SPECIES_MINUN},
    {13, 13, SPECIES_GULPIN},
    {12, 12, SPECIES_WINGULL},
    {12, 12, SPECIES_WINGULL},
    {12, 12, SPECIES_PLUSLE},
    {13, 13, SPECIES_PLUSLE},
};

const struct WildPokemonInfo gRoute110_LandMonsInfo = {20, gRoute110_LandMons};

const struct WildPokemon gRoute110_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute110_WaterMonsInfo = {4, gRoute110_WaterMons};

const struct WildPokemon gRoute110_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute110_FishingMonsInfo = {30, gRoute110_FishingMons};

const struct WildPokemon gRoute111_LandMons[] =
{
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {21, 21, SPECIES_SANDSHREW},
    {21, 21, SPECIES_TRAPINCH},
    {19, 19, SPECIES_BALTOY},
    {21, 21, SPECIES_BALTOY},
    {19, 19, SPECIES_SANDSHREW},
    {19, 19, SPECIES_TRAPINCH},
    {20, 20, SPECIES_BALTOY},
    {20, 20, SPECIES_CACNEA},
    {22, 22, SPECIES_CACNEA},
    {22, 22, SPECIES_CACNEA},
};

const struct WildPokemonInfo gRoute111_LandMonsInfo = {10, gRoute111_LandMons};

const struct WildPokemon gRoute111_WaterMons[] =
{
    {20, 30, SPECIES_MARILL},
    {10, 20, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
    {20, 30, SPECIES_GOLDEEN},
};

const struct WildPokemonInfo gRoute111_WaterMonsInfo = {4, gRoute111_WaterMons};

const struct WildPokemon gRoute111_RockSmashMons[] =
{
    {10, 15, SPECIES_GEODUDE},
    {5, 10, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
};

const struct WildPokemonInfo gRoute111_RockSmashMonsInfo = {20, gRoute111_RockSmashMons};

const struct WildPokemon gRoute111_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {20, 25, SPECIES_BARBOACH},
    {35, 40, SPECIES_BARBOACH},
    {40, 45, SPECIES_BARBOACH},
};

const struct WildPokemonInfo gRoute111_FishingMonsInfo = {30, gRoute111_FishingMons};

const struct WildPokemon gRoute112_LandMons[] =
{
    {15, 15, SPECIES_NUMEL},
    {15, 15, SPECIES_NUMEL},
    {15, 15, SPECIES_MARILL},
    {14, 14, SPECIES_NUMEL},
    {14, 14, SPECIES_NUMEL},
    {14, 14, SPECIES_MARILL},
    {16, 16, SPECIES_NUMEL},
    {16, 16, SPECIES_MARILL},
    {16, 16, SPECIES_NUMEL},
    {16, 16, SPECIES_NUMEL},
    {16, 16, SPECIES_NUMEL},
    {16, 16, SPECIES_NUMEL},
};

const struct WildPokemonInfo gRoute112_LandMonsInfo = {20, gRoute112_LandMons};

const struct WildPokemon gRoute113_LandMons[] =
{
    {15, 15, SPECIES_SPINDA},
    {15, 15, SPECIES_SPINDA},
    {15, 15, SPECIES_SLUGMA},
    {14, 14, SPECIES_SPINDA},
    {14, 14, SPECIES_SPINDA},
    {14, 14, SPECIES_SLUGMA},
    {16, 16, SPECIES_SPINDA},
    {16, 16, SPECIES_SLUGMA},
    {16, 16, SPECIES_SPINDA},
    {16, 16, SPECIES_SKARMORY},
    {16, 16, SPECIES_SPINDA},
    {16, 16, SPECIES_SKARMORY},
};

const struct WildPokemonInfo gRoute113_LandMonsInfo = {20, gRoute113_LandMons};

const struct WildPokemon gRoute114_LandMons[] =
{
    {16, 16, SPECIES_SWABLU},
    {16, 16, SPECIES_LOTAD},
    {17, 17, SPECIES_SWABLU},
    {15, 15, SPECIES_SWABLU},
    {15, 15, SPECIES_LOTAD},
    {16, 16, SPECIES_LOMBRE},
    {16, 16, SPECIES_LOMBRE},
    {18, 18, SPECIES_LOMBRE},
    {17, 17, SPECIES_SEVIPER},
    {15, 15, SPECIES_SEVIPER},
    {17, 17, SPECIES_SEVIPER},
    {15, 15, SPECIES_NUZLEAF},
};

const struct WildPokemonInfo gRoute114_LandMonsInfo = {20, gRoute114_LandMons};

const struct WildPokemon gRoute114_WaterMons[] =
{
    {20, 30, SPECIES_MARILL},
    {10, 20, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
    {20, 30, SPECIES_GOLDEEN},
};

const struct WildPokemonInfo gRoute114_WaterMonsInfo = {4, gRoute114_WaterMons};

const struct WildPokemon gRoute114_RockSmashMons[] =
{
    {10, 15, SPECIES_GEODUDE},
    {5, 10, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
};

const struct WildPokemonInfo gRoute114_RockSmashMonsInfo = {20, gRoute114_RockSmashMons};

const struct WildPokemon gRoute114_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {20, 25, SPECIES_BARBOACH},
    {35, 40, SPECIES_BARBOACH},
    {40, 45, SPECIES_BARBOACH},
};

const struct WildPokemonInfo gRoute114_FishingMonsInfo = {30, gRoute114_FishingMons};

const struct WildPokemon gRoute116_LandMons[] =
{
    {6, 6, SPECIES_POOCHYENA},
    {6, 6, SPECIES_WHISMUR},
    {6, 6, SPECIES_NINCADA},
    {7, 7, SPECIES_ABRA},
    {7, 7, SPECIES_NINCADA},
    {6, 6, SPECIES_TAILLOW},
    {7, 7, SPECIES_TAILLOW},
    {8, 8, SPECIES_TAILLOW},
    {7, 7, SPECIES_POOCHYENA},
    {8, 8, SPECIES_POOCHYENA},
    {7, 7, SPECIES_SKITTY},
    {8, 8, SPECIES_SKITTY},
};

const struct WildPokemonInfo gRoute116_LandMonsInfo = {20, gRoute116_LandMons};

const struct WildPokemon gRoute117_LandMons[] =
{
    {13, 13, SPECIES_POOCHYENA},
    {13, 13, SPECIES_ODDISH},
    {14, 14, SPECIES_POOCHYENA},
    {14, 14, SPECIES_ODDISH},
    {13, 13, SPECIES_MARILL},
    {13, 13, SPECIES_ODDISH},
    {13, 13, SPECIES_ILLUMISE},
    {13, 13, SPECIES_ILLUMISE},
    {14, 14, SPECIES_ILLUMISE},
    {14, 14, SPECIES_ILLUMISE},
    {13, 13, SPECIES_VOLBEAT},
    {13, 13, SPECIES_SEEDOT},
};

const struct WildPokemonInfo gRoute117_LandMonsInfo = {20, gRoute117_LandMons};

const struct WildPokemon gRoute117_WaterMons[] =
{
    {20, 30, SPECIES_MARILL},
    {10, 20, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
    {20, 30, SPECIES_GOLDEEN},
};

const struct WildPokemonInfo gRoute117_WaterMonsInfo = {4, gRoute117_WaterMons};

const struct WildPokemon gRoute117_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_CORPHISH},
    {25, 30, SPECIES_CORPHISH},
    {30, 35, SPECIES_CORPHISH},
    {20, 25, SPECIES_CORPHISH},
    {35, 40, SPECIES_CORPHISH},
    {40, 45, SPECIES_CORPHISH},
};

const struct WildPokemonInfo gRoute117_FishingMonsInfo = {30, gRoute117_FishingMons};

const struct WildPokemon gRoute118_LandMons[] =
{
    {24, 24, SPECIES_ZIGZAGOON},
    {24, 24, SPECIES_ELECTRIKE},
    {26, 26, SPECIES_ZIGZAGOON},
    {26, 26, SPECIES_ELECTRIKE},
    {26, 26, SPECIES_LINOONE},
    {26, 26, SPECIES_MANECTRIC},
    {25, 25, SPECIES_WINGULL},
    {25, 25, SPECIES_WINGULL},
    {26, 26, SPECIES_WINGULL},
    {26, 26, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {25, 25, SPECIES_KECLEON},
};

const struct WildPokemonInfo gRoute118_LandMonsInfo = {20, gRoute118_LandMons};

const struct WildPokemon gRoute118_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute118_WaterMonsInfo = {4, gRoute118_WaterMons};

const struct WildPokemon gRoute118_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_CARVANHA},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_CARVANHA},
    {20, 25, SPECIES_CARVANHA},
    {35, 40, SPECIES_CARVANHA},
    {40, 45, SPECIES_CARVANHA},
};

const struct WildPokemonInfo gRoute118_FishingMonsInfo = {30, gRoute118_FishingMons};

const struct WildPokemon gRoute124_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute124_WaterMonsInfo = {4, gRoute124_WaterMons};

const struct WildPokemon gRoute124_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute124_FishingMonsInfo = {30, gRoute124_FishingMons};

const struct WildPokemon gPetalburgWoods_LandMons[] =
{
    {5, 5, SPECIES_POOCHYENA},
    {5, 5, SPECIES_WURMPLE},
    {5, 5, SPECIES_SHROOMISH},
    {6, 6, SPECIES_POOCHYENA},
    {5, 5, SPECIES_SILCOON},
    {5, 5, SPECIES_CASCOON},
    {6, 6, SPECIES_WURMPLE},
    {6, 6, SPECIES_SHROOMISH},
    {5, 5, SPECIES_TAILLOW},
    {5, 5, SPECIES_SLAKOTH},
    {6, 6, SPECIES_TAILLOW},
    {6, 6, SPECIES_SLAKOTH},
};

const struct WildPokemonInfo gPetalburgWoods_LandMonsInfo = {20, gPetalburgWoods_LandMons};

const struct WildPokemon gRusturfTunnel_LandMons[] =
{
    {6, 6, SPECIES_WHISMUR},
    {7, 7, SPECIES_WHISMUR},
    {6, 6, SPECIES_WHISMUR},
    {6, 6, SPECIES_WHISMUR},
    {7, 7, SPECIES_WHISMUR},
    {7, 7, SPECIES_WHISMUR},
    {5, 5, SPECIES_WHISMUR},
    {8, 8, SPECIES_WHISMUR},
    {5, 5, SPECIES_WHISMUR},
    {8, 8, SPECIES_WHISMUR},
    {5, 5, SPECIES_WHISMUR},
    {8, 8, SPECIES_WHISMUR},
};

const struct WildPokemonInfo gRusturfTunnel_LandMonsInfo = {10, gRusturfTunnel_LandMons};

const struct WildPokemon gGraniteCave_1F_LandMons[] =
{
    {7, 7, SPECIES_ZUBAT},
    {8, 8, SPECIES_MAKUHITA},
    {7, 7, SPECIES_MAKUHITA},
    {8, 8, SPECIES_ZUBAT},
    {9, 9, SPECIES_MAKUHITA},
    {8, 8, SPECIES_ABRA},
    {10, 10, SPECIES_MAKUHITA},
    {6, 6, SPECIES_MAKUHITA},
    {7, 7, SPECIES_GEODUDE},
    {8, 8, SPECIES_GEODUDE},
    {6, 6, SPECIES_GEODUDE},
    {9, 9, SPECIES_GEODUDE},
};

const struct WildPokemonInfo gGraniteCave_1F_LandMonsInfo = {10, gGraniteCave_1F_LandMons};

const struct WildPokemon gGraniteCave_B1F_LandMons[] =
{
    {9, 9, SPECIES_ZUBAT},
    {10, 10, SPECIES_ARON},
    {9, 9, SPECIES_ARON},
    {11, 11, SPECIES_ARON},
    {10, 10, SPECIES_ZUBAT},
    {9, 9, SPECIES_ABRA},
    {10, 10, SPECIES_MAKUHITA},
    {11, 11, SPECIES_MAKUHITA},
    {10, 10, SPECIES_SABLEYE},
    {10, 10, SPECIES_SABLEYE},
    {9, 9, SPECIES_SABLEYE},
    {11, 11, SPECIES_SABLEYE},
};

const struct WildPokemonInfo gGraniteCave_B1F_LandMonsInfo = {10, gGraniteCave_B1F_LandMons};

const struct WildPokemon gMtPyre_1F_LandMons[] =
{
    {27, 27, SPECIES_SHUPPET},
    {28, 28, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {23, 23, SPECIES_SHUPPET},
    {22, 22, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
};

const struct WildPokemonInfo gMtPyre_1F_LandMonsInfo = {10, gMtPyre_1F_LandMons};

const struct WildPokemon gVictoryRoad_1F_LandMons[] =
{
    {40, 40, SPECIES_GOLBAT},
    {40, 40, SPECIES_HARIYAMA},
    {40, 40, SPECIES_LAIRON},
    {40, 40, SPECIES_LOUDRED},
    {36, 36, SPECIES_ZUBAT},
    {36, 36, SPECIES_MAKUHITA},
    {38, 38, SPECIES_GOLBAT},
    {38, 38, SPECIES_HARIYAMA},
    {36, 36, SPECIES_ARON},
    {36, 36, SPECIES_WHISMUR},
    {36, 36, SPECIES_ARON},
    {36, 36, SPECIES_WHISMUR},
};

const struct WildPokemonInfo gVictoryRoad_1F_LandMonsInfo = {10, gVictoryRoad_1F_LandMons};

const struct WildPokemon gSafariZone_South_LandMons[] =
{
    {25, 25, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {25, 25, SPECIES_GIRAFARIG},
    {27, 27, SPECIES_GIRAFARIG},
    {25, 25, SPECIES_NATU},
    {25, 25, SPECIES_DODUO},
    {25, 25, SPECIES_GLOOM},
    {27, 27, SPECIES_WOBBUFFET},
    {25, 25, SPECIES_PIKACHU},
    {27, 27, SPECIES_WOBBUFFET},
    {27, 27, SPECIES_PIKACHU},
    {29, 29, SPECIES_WOBBUFFET},
};

const struct WildPokemonInfo gSafariZone_South_LandMonsInfo = {25, gSafariZone_South_LandMons};

const struct WildPokemon gUnderwater2_WaterMons[] =
{
    {20, 30, SPECIES_CLAMPERL},
    {20, 30, SPECIES_CHINCHOU},
    {30, 35, SPECIES_CLAMPERL},
    {30, 35, SPECIES_RELICANTH},
    {30, 35, SPECIES_RELICANTH},
};

const struct WildPokemonInfo gUnderwater2_WaterMonsInfo = {4, gUnderwater2_WaterMons};

const struct WildPokemon gAbandonedShip_Rooms_B1F_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_TENTACOOL},
    {30, 35, SPECIES_TENTACRUEL},
};

const struct WildPokemonInfo gAbandonedShip_Rooms_B1F_WaterMonsInfo = {4, gAbandonedShip_Rooms_B1F_WaterMons};

const struct WildPokemon gAbandonedShip_Rooms_B1F_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_TENTACOOL},
    {25, 30, SPECIES_TENTACOOL},
    {30, 35, SPECIES_TENTACOOL},
    {30, 35, SPECIES_TENTACRUEL},
    {25, 30, SPECIES_TENTACRUEL},
    {20, 25, SPECIES_TENTACRUEL},
};

const struct WildPokemonInfo gAbandonedShip_Rooms_B1F_FishingMonsInfo = {20, gAbandonedShip_Rooms_B1F_FishingMons};

const struct WildPokemon gGraniteCave_B2F_LandMons[] =
{
    {10, 10, SPECIES_ZUBAT},
    {11, 11, SPECIES_ARON},
    {10, 10, SPECIES_ARON},
    {11, 11, SPECIES_ZUBAT},
    {12, 12, SPECIES_ARON},
    {10, 10, SPECIES_ABRA},
    {10, 10, SPECIES_SABLEYE},
    {11, 11, SPECIES_SABLEYE},
    {12, 12, SPECIES_SABLEYE},
    {10, 10, SPECIES_SABLEYE},
    {12, 12, SPECIES_SABLEYE},
    {10, 10, SPECIES_SABLEYE},
};

const struct WildPokemonInfo gGraniteCave_B2F_LandMonsInfo = {10, gGraniteCave_B2F_LandMons};

const struct WildPokemon gGraniteCave_B2F_RockSmashMons[] =
{
    {10, 15, SPECIES_GEODUDE},
    {10, 20, SPECIES_NOSEPASS},
    {5, 10, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
};

const struct WildPokemonInfo gGraniteCave_B2F_RockSmashMonsInfo = {20, gGraniteCave_B2F_RockSmashMons};

const struct WildPokemon gFieryPath_LandMons[] =
{
    {15, 15, SPECIES_NUMEL},
    {15, 15, SPECIES_KOFFING},
    {16, 16, SPECIES_NUMEL},
    {15, 15, SPECIES_MACHOP},
    {15, 15, SPECIES_TORKOAL},
    {15, 15, SPECIES_SLUGMA},
    {16, 16, SPECIES_KOFFING},
    {16, 16, SPECIES_MACHOP},
    {14, 14, SPECIES_TORKOAL},
    {16, 16, SPECIES_TORKOAL},
    {14, 14, SPECIES_GRIMER},
    {14, 14, SPECIES_GRIMER},
};

const struct WildPokemonInfo gFieryPath_LandMonsInfo = {10, gFieryPath_LandMons};

const struct WildPokemon gMeteorFalls_B1F_2R_LandMons[] =
{
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {30, 30, SPECIES_BAGON},
    {35, 35, SPECIES_SOLROCK},
    {35, 35, SPECIES_BAGON},
    {37, 37, SPECIES_SOLROCK},
    {25, 25, SPECIES_BAGON},
    {39, 39, SPECIES_SOLROCK},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_LandMonsInfo = {10, gMeteorFalls_B1F_2R_LandMons};

const struct WildPokemon gMeteorFalls_B1F_2R_WaterMons[] =
{
    {30, 35, SPECIES_GOLBAT},
    {30, 35, SPECIES_GOLBAT},
    {25, 35, SPECIES_SOLROCK},
    {15, 25, SPECIES_SOLROCK},
    {5, 15, SPECIES_SOLROCK},
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_WaterMonsInfo = {4, gMeteorFalls_B1F_2R_WaterMons};

const struct WildPokemon gMeteorFalls_B1F_2R_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {30, 35, SPECIES_WHISCASH},
    {35, 40, SPECIES_WHISCASH},
    {40, 45, SPECIES_WHISCASH},
};

const struct WildPokemonInfo gMeteorFalls_B1F_2R_FishingMonsInfo = {30, gMeteorFalls_B1F_2R_FishingMons};

const struct WildPokemon gJaggedPass_LandMons[] =
{
    {21, 21, SPECIES_NUMEL},
    {21, 21, SPECIES_NUMEL},
    {21, 21, SPECIES_MACHOP},
    {20, 20, SPECIES_NUMEL},
    {20, 20, SPECIES_SPOINK},
    {20, 20, SPECIES_MACHOP},
    {21, 21, SPECIES_SPOINK},
    {22, 22, SPECIES_MACHOP},
    {22, 22, SPECIES_NUMEL},
    {22, 22, SPECIES_SPOINK},
    {22, 22, SPECIES_NUMEL},
    {22, 22, SPECIES_SPOINK},
};

const struct WildPokemonInfo gJaggedPass_LandMonsInfo = {20, gJaggedPass_LandMons};

const struct WildPokemon gRoute106_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute106_WaterMonsInfo = {4, gRoute106_WaterMons};

const struct WildPokemon gRoute106_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute106_FishingMonsInfo = {30, gRoute106_FishingMons};

const struct WildPokemon gRoute107_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute107_WaterMonsInfo = {4, gRoute107_WaterMons};

const struct WildPokemon gRoute107_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute107_FishingMonsInfo = {30, gRoute107_FishingMons};

const struct WildPokemon gRoute108_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute108_WaterMonsInfo = {4, gRoute108_WaterMons};

const struct WildPokemon gRoute108_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute108_FishingMonsInfo = {30, gRoute108_FishingMons};

const struct WildPokemon gRoute109_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute109_WaterMonsInfo = {4, gRoute109_WaterMons};

const struct WildPokemon gRoute109_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute109_FishingMonsInfo = {30, gRoute109_FishingMons};

const struct WildPokemon gRoute115_LandMons[] =
{
    {23, 23, SPECIES_SWABLU},
    {23, 23, SPECIES_TAILLOW},
    {25, 25, SPECIES_SWABLU},
    {24, 24, SPECIES_TAILLOW},
    {25, 25, SPECIES_TAILLOW},
    {25, 25, SPECIES_SWELLOW},
    {24, 24, SPECIES_JIGGLYPUFF},
    {25, 25, SPECIES_JIGGLYPUFF},
    {24, 24, SPECIES_WINGULL},
    {24, 24, SPECIES_WINGULL},
    {26, 26, SPECIES_WINGULL},
    {25, 25, SPECIES_WINGULL},
};

const struct WildPokemonInfo gRoute115_LandMonsInfo = {20, gRoute115_LandMons};

const struct WildPokemon gRoute115_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute115_WaterMonsInfo = {4, gRoute115_WaterMons};

const struct WildPokemon gRoute115_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute115_FishingMonsInfo = {30, gRoute115_FishingMons};

const struct WildPokemon gNewMauville_Inside_LandMons[] =
{
    {24, 24, SPECIES_VOLTORB},
    {24, 24, SPECIES_MAGNEMITE},
    {25, 25, SPECIES_VOLTORB},
    {25, 25, SPECIES_MAGNEMITE},
    {23, 23, SPECIES_VOLTORB},
    {23, 23, SPECIES_MAGNEMITE},
    {26, 26, SPECIES_VOLTORB},
    {26, 26, SPECIES_MAGNEMITE},
    {22, 22, SPECIES_VOLTORB},
    {22, 22, SPECIES_MAGNEMITE},
    {26, 26, SPECIES_ELECTRODE},
    {26, 26, SPECIES_MAGNETON},
};

const struct WildPokemonInfo gNewMauville_Inside_LandMonsInfo = {10, gNewMauville_Inside_LandMons};

const struct WildPokemon gRoute119_LandMons[] =
{
    {25, 25, SPECIES_ZIGZAGOON},
    {25, 25, SPECIES_LINOONE},
    {27, 27, SPECIES_ZIGZAGOON},
    {25, 25, SPECIES_ODDISH},
    {27, 27, SPECIES_LINOONE},
    {26, 26, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {24, 24, SPECIES_ODDISH},
    {25, 25, SPECIES_TROPIUS},
    {26, 26, SPECIES_TROPIUS},
    {27, 27, SPECIES_TROPIUS},
    {25, 25, SPECIES_KECLEON},
};

const struct WildPokemonInfo gRoute119_LandMonsInfo = {15, gRoute119_LandMons};

const struct WildPokemon gRoute119_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute119_WaterMonsInfo = {4, gRoute119_WaterMons};

const struct WildPokemon gRoute119_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_CARVANHA},
    {25, 30, SPECIES_CARVANHA},
    {30, 35, SPECIES_CARVANHA},
    {20, 25, SPECIES_CARVANHA},
    {35, 40, SPECIES_CARVANHA},
    {40, 45, SPECIES_CARVANHA},
};

const struct WildPokemonInfo gRoute119_FishingMonsInfo = {30, gRoute119_FishingMons};

const struct WildPokemon gRoute120_LandMons[] =
{
    {25, 25, SPECIES_POOCHYENA},
    {25, 25, SPECIES_MIGHTYENA},
    {27, 27, SPECIES_MIGHTYENA},
    {25, 25, SPECIES_ODDISH},
    {25, 25, SPECIES_MARILL},
    {26, 26, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {27, 27, SPECIES_MARILL},
    {25, 25, SPECIES_ABSOL},
    {27, 27, SPECIES_ABSOL},
    {25, 25, SPECIES_KECLEON},
    {25, 25, SPECIES_SEEDOT},
};

const struct WildPokemonInfo gRoute120_LandMonsInfo = {20, gRoute120_LandMons};

const struct WildPokemon gRoute120_WaterMons[] =
{
    {20, 30, SPECIES_MARILL},
    {10, 20, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
    {20, 30, SPECIES_GOLDEEN},
};

const struct WildPokemonInfo gRoute120_WaterMonsInfo = {4, gRoute120_WaterMons};

const struct WildPokemon gRoute120_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {20, 25, SPECIES_BARBOACH},
    {35, 40, SPECIES_BARBOACH},
    {40, 45, SPECIES_BARBOACH},
};

const struct WildPokemonInfo gRoute120_FishingMonsInfo = {30, gRoute120_FishingMons};

const struct WildPokemon gRoute121_LandMons[] =
{
    {26, 26, SPECIES_POOCHYENA},
    {26, 26, SPECIES_SHUPPET},
    {26, 26, SPECIES_MIGHTYENA},
    {28, 28, SPECIES_SHUPPET},
    {28, 28, SPECIES_MIGHTYENA},
    {26, 26, SPECIES_ODDISH},
    {28, 28, SPECIES_ODDISH},
    {28, 28, SPECIES_GLOOM},
    {26, 26, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {28, 28, SPECIES_WINGULL},
    {25, 25, SPECIES_KECLEON},
};

const struct WildPokemonInfo gRoute121_LandMonsInfo = {20, gRoute121_LandMons};

const struct WildPokemon gRoute121_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute121_WaterMonsInfo = {4, gRoute121_WaterMons};

const struct WildPokemon gRoute121_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute121_FishingMonsInfo = {30, gRoute121_FishingMons};

const struct WildPokemon gRoute122_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute122_WaterMonsInfo = {4, gRoute122_WaterMons};

const struct WildPokemon gRoute122_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute122_FishingMonsInfo = {30, gRoute122_FishingMons};

const struct WildPokemon gRoute123_LandMons[] =
{
    {26, 26, SPECIES_POOCHYENA},
    {26, 26, SPECIES_SHUPPET},
    {26, 26, SPECIES_MIGHTYENA},
    {28, 28, SPECIES_SHUPPET},
    {28, 28, SPECIES_MIGHTYENA},
    {26, 26, SPECIES_ODDISH},
    {28, 28, SPECIES_ODDISH},
    {28, 28, SPECIES_GLOOM},
    {26, 26, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {28, 28, SPECIES_WINGULL},
    {25, 25, SPECIES_KECLEON},
};

const struct WildPokemonInfo gRoute123_LandMonsInfo = {20, gRoute123_LandMons};

const struct WildPokemon gRoute123_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute123_WaterMonsInfo = {4, gRoute123_WaterMons};

const struct WildPokemon gRoute123_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute123_FishingMonsInfo = {30, gRoute123_FishingMons};

const struct WildPokemon gMtPyre_2F_LandMons[] =
{
    {27, 27, SPECIES_SHUPPET},
    {28, 28, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {23, 23, SPECIES_SHUPPET},
    {22, 22, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
};

const struct WildPokemonInfo gMtPyre_2F_LandMonsInfo = {10, gMtPyre_2F_LandMons};

const struct WildPokemon gMtPyre_3F_LandMons[] =
{
    {27, 27, SPECIES_SHUPPET},
    {28, 28, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {23, 23, SPECIES_SHUPPET},
    {22, 22, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
};

const struct WildPokemonInfo gMtPyre_3F_LandMonsInfo = {10, gMtPyre_3F_LandMons};

const struct WildPokemon gMtPyre_4F_LandMons[] =
{
    {27, 27, SPECIES_SHUPPET},
    {28, 28, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {23, 23, SPECIES_SHUPPET},
    {22, 22, SPECIES_SHUPPET},
    {27, 27, SPECIES_DUSKULL},
    {27, 27, SPECIES_DUSKULL},
    {25, 25, SPECIES_DUSKULL},
    {29, 29, SPECIES_DUSKULL},
};

const struct WildPokemonInfo gMtPyre_4F_LandMonsInfo = {10, gMtPyre_4F_LandMons};

const struct WildPokemon gMtPyre_5F_LandMons[] =
{
    {27, 27, SPECIES_SHUPPET},
    {28, 28, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {23, 23, SPECIES_SHUPPET},
    {22, 22, SPECIES_SHUPPET},
    {27, 27, SPECIES_DUSKULL},
    {27, 27, SPECIES_DUSKULL},
    {25, 25, SPECIES_DUSKULL},
    {29, 29, SPECIES_DUSKULL},
};

const struct WildPokemonInfo gMtPyre_5F_LandMonsInfo = {10, gMtPyre_5F_LandMons};

const struct WildPokemon gMtPyre_6F_LandMons[] =
{
    {27, 27, SPECIES_SHUPPET},
    {28, 28, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {23, 23, SPECIES_SHUPPET},
    {22, 22, SPECIES_SHUPPET},
    {27, 27, SPECIES_DUSKULL},
    {27, 27, SPECIES_DUSKULL},
    {25, 25, SPECIES_DUSKULL},
    {29, 29, SPECIES_DUSKULL},
};

const struct WildPokemonInfo gMtPyre_6F_LandMonsInfo = {10, gMtPyre_6F_LandMons};

const struct WildPokemon gMtPyre_Exterior_LandMons[] =
{
    {27, 27, SPECIES_SHUPPET},
    {27, 27, SPECIES_SHUPPET},
    {28, 28, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {29, 29, SPECIES_VULPIX},
    {27, 27, SPECIES_VULPIX},
    {29, 29, SPECIES_VULPIX},
    {25, 25, SPECIES_VULPIX},
    {27, 27, SPECIES_WINGULL},
    {27, 27, SPECIES_WINGULL},
    {26, 26, SPECIES_WINGULL},
    {28, 28, SPECIES_WINGULL},
};

const struct WildPokemonInfo gMtPyre_Exterior_LandMonsInfo = {10, gMtPyre_Exterior_LandMons};

const struct WildPokemon gMtPyre_Summit_LandMons[] =
{
    {28, 28, SPECIES_SHUPPET},
    {29, 29, SPECIES_SHUPPET},
    {27, 27, SPECIES_SHUPPET},
    {26, 26, SPECIES_SHUPPET},
    {30, 30, SPECIES_SHUPPET},
    {25, 25, SPECIES_SHUPPET},
    {24, 24, SPECIES_SHUPPET},
    {28, 28, SPECIES_DUSKULL},
    {26, 26, SPECIES_DUSKULL},
    {30, 30, SPECIES_DUSKULL},
    {28, 28, SPECIES_CHIMECHO},
    {28, 28, SPECIES_CHIMECHO},
};

const struct WildPokemonInfo gMtPyre_Summit_LandMonsInfo = {10, gMtPyre_Summit_LandMons};

const struct WildPokemon gGraniteCave_StevensRoom_LandMons[] =
{
    {7, 7, SPECIES_ZUBAT},
    {8, 8, SPECIES_MAKUHITA},
    {7, 7, SPECIES_MAKUHITA},
    {8, 8, SPECIES_ZUBAT},
    {9, 9, SPECIES_MAKUHITA},
    {8, 8, SPECIES_ABRA},
    {10, 10, SPECIES_MAKUHITA},
    {6, 6, SPECIES_MAKUHITA},
    {7, 7, SPECIES_ARON},
    {8, 8, SPECIES_ARON},
    {7, 7, SPECIES_ARON},
    {8, 8, SPECIES_ARON},
};

const struct WildPokemonInfo gGraniteCave_StevensRoom_LandMonsInfo = {10, gGraniteCave_StevensRoom_LandMons};

const struct WildPokemon gRoute125_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute125_WaterMonsInfo = {4, gRoute125_WaterMons};

const struct WildPokemon gRoute125_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute125_FishingMonsInfo = {30, gRoute125_FishingMons};

const struct WildPokemon gRoute126_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute126_WaterMonsInfo = {4, gRoute126_WaterMons};

const struct WildPokemon gRoute126_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute126_FishingMonsInfo = {30, gRoute126_FishingMons};

const struct WildPokemon gRoute127_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute127_WaterMonsInfo = {4, gRoute127_WaterMons};

const struct WildPokemon gRoute127_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute127_FishingMonsInfo = {30, gRoute127_FishingMons};

const struct WildPokemon gRoute128_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute128_WaterMonsInfo = {4, gRoute128_WaterMons};

const struct WildPokemon gRoute128_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_LUVDISC},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_LUVDISC},
    {30, 35, SPECIES_WAILMER},
    {30, 35, SPECIES_CORSOLA},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute128_FishingMonsInfo = {30, gRoute128_FishingMons};

const struct WildPokemon gRoute129_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_WAILORD},
};

const struct WildPokemonInfo gRoute129_WaterMonsInfo = {4, gRoute129_WaterMons};

const struct WildPokemon gRoute129_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute129_FishingMonsInfo = {30, gRoute129_FishingMons};

const struct WildPokemon gRoute130_LandMons[] =
{
    {30, 30, SPECIES_WYNAUT},
    {35, 35, SPECIES_WYNAUT},
    {25, 25, SPECIES_WYNAUT},
    {40, 40, SPECIES_WYNAUT},
    {20, 20, SPECIES_WYNAUT},
    {45, 45, SPECIES_WYNAUT},
    {15, 15, SPECIES_WYNAUT},
    {50, 50, SPECIES_WYNAUT},
    {10, 10, SPECIES_WYNAUT},
    {5, 5, SPECIES_WYNAUT},
    {10, 10, SPECIES_WYNAUT},
    {5, 5, SPECIES_WYNAUT},
};

const struct WildPokemonInfo gRoute130_LandMonsInfo = {20, gRoute130_LandMons};

const struct WildPokemon gRoute130_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute130_WaterMonsInfo = {4, gRoute130_WaterMons};

const struct WildPokemon gRoute130_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute130_FishingMonsInfo = {30, gRoute130_FishingMons};

const struct WildPokemon gRoute131_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute131_WaterMonsInfo = {4, gRoute131_WaterMons};

const struct WildPokemon gRoute131_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute131_FishingMonsInfo = {30, gRoute131_FishingMons};

const struct WildPokemon gRoute132_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute132_WaterMonsInfo = {4, gRoute132_WaterMons};

const struct WildPokemon gRoute132_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_HORSEA},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute132_FishingMonsInfo = {30, gRoute132_FishingMons};

const struct WildPokemon gRoute133_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute133_WaterMonsInfo = {4, gRoute133_WaterMons};

const struct WildPokemon gRoute133_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_HORSEA},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute133_FishingMonsInfo = {30, gRoute133_FishingMons};

const struct WildPokemon gRoute134_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gRoute134_WaterMonsInfo = {4, gRoute134_WaterMons};

const struct WildPokemon gRoute134_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_HORSEA},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gRoute134_FishingMonsInfo = {30, gRoute134_FishingMons};

const struct WildPokemon gAbandonedShip_HiddenFloorCorridors_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_TENTACOOL},
    {30, 35, SPECIES_TENTACRUEL},
};

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo = {4, gAbandonedShip_HiddenFloorCorridors_WaterMons};

const struct WildPokemon gAbandonedShip_HiddenFloorCorridors_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_TENTACOOL},
    {25, 30, SPECIES_TENTACOOL},
    {30, 35, SPECIES_TENTACOOL},
    {30, 35, SPECIES_TENTACRUEL},
    {25, 30, SPECIES_TENTACRUEL},
    {20, 25, SPECIES_TENTACRUEL},
};

const struct WildPokemonInfo gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo = {20, gAbandonedShip_HiddenFloorCorridors_FishingMons};

const struct WildPokemon gSeafloorCavern_Room1_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room1_LandMonsInfo = {4, gSeafloorCavern_Room1_LandMons};

const struct WildPokemon gSeafloorCavern_Room2_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room2_LandMonsInfo = {4, gSeafloorCavern_Room2_LandMons};

const struct WildPokemon gSeafloorCavern_Room3_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room3_LandMonsInfo = {4, gSeafloorCavern_Room3_LandMons};

const struct WildPokemon gSeafloorCavern_Room4_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room4_LandMonsInfo = {4, gSeafloorCavern_Room4_LandMons};

const struct WildPokemon gSeafloorCavern_Room5_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room5_LandMonsInfo = {4, gSeafloorCavern_Room5_LandMons};

const struct WildPokemon gSeafloorCavern_Room6_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room6_LandMonsInfo = {4, gSeafloorCavern_Room6_LandMons};

const struct WildPokemon gSeafloorCavern_Room6_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_ZUBAT},
    {30, 35, SPECIES_ZUBAT},
    {30, 35, SPECIES_GOLBAT},
    {30, 35, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room6_WaterMonsInfo = {4, gSeafloorCavern_Room6_WaterMons};

const struct WildPokemon gSeafloorCavern_Room6_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gSeafloorCavern_Room6_FishingMonsInfo = {10, gSeafloorCavern_Room6_FishingMons};

const struct WildPokemon gSeafloorCavern_Room7_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room7_LandMonsInfo = {4, gSeafloorCavern_Room7_LandMons};

const struct WildPokemon gSeafloorCavern_Room7_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_ZUBAT},
    {30, 35, SPECIES_ZUBAT},
    {30, 35, SPECIES_GOLBAT},
    {30, 35, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room7_WaterMonsInfo = {4, gSeafloorCavern_Room7_WaterMons};

const struct WildPokemon gSeafloorCavern_Room7_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gSeafloorCavern_Room7_FishingMonsInfo = {10, gSeafloorCavern_Room7_FishingMons};

const struct WildPokemon gSeafloorCavern_Room8_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Room8_LandMonsInfo = {4, gSeafloorCavern_Room8_LandMons};

const struct WildPokemon gSeafloorCavern_Entrance_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_ZUBAT},
    {30, 35, SPECIES_ZUBAT},
    {30, 35, SPECIES_GOLBAT},
    {30, 35, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gSeafloorCavern_Entrance_WaterMonsInfo = {4, gSeafloorCavern_Entrance_WaterMons};

const struct WildPokemon gSeafloorCavern_Entrance_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gSeafloorCavern_Entrance_FishingMonsInfo = {10, gSeafloorCavern_Entrance_FishingMons};

const struct WildPokemon gCaveOfOrigin_Entrance_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {33, 33, SPECIES_ZUBAT},
    {28, 28, SPECIES_ZUBAT},
    {29, 29, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {35, 35, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gCaveOfOrigin_Entrance_LandMonsInfo = {4, gCaveOfOrigin_Entrance_LandMons};

const struct WildPokemon gCaveOfOrigin_1F_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gCaveOfOrigin_1F_LandMonsInfo = {4, gCaveOfOrigin_1F_LandMons};

const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap1_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo = {4, gCaveOfOrigin_UnusedRubySapphireMap1_LandMons};

const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap2_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo = {4, gCaveOfOrigin_UnusedRubySapphireMap2_LandMons};

const struct WildPokemon gCaveOfOrigin_UnusedRubySapphireMap3_LandMons[] =
{
    {30, 30, SPECIES_ZUBAT},
    {31, 31, SPECIES_ZUBAT},
    {32, 32, SPECIES_ZUBAT},
    {30, 30, SPECIES_SABLEYE},
    {32, 32, SPECIES_SABLEYE},
    {34, 34, SPECIES_SABLEYE},
    {33, 33, SPECIES_ZUBAT},
    {34, 34, SPECIES_ZUBAT},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {36, 36, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo = {4, gCaveOfOrigin_UnusedRubySapphireMap3_LandMons};

const struct WildPokemon gNewMauville_Entrance_LandMons[] =
{
    {24, 24, SPECIES_VOLTORB},
    {24, 24, SPECIES_MAGNEMITE},
    {25, 25, SPECIES_VOLTORB},
    {25, 25, SPECIES_MAGNEMITE},
    {23, 23, SPECIES_VOLTORB},
    {23, 23, SPECIES_MAGNEMITE},
    {26, 26, SPECIES_VOLTORB},
    {26, 26, SPECIES_MAGNEMITE},
    {22, 22, SPECIES_VOLTORB},
    {22, 22, SPECIES_MAGNEMITE},
    {22, 22, SPECIES_VOLTORB},
    {22, 22, SPECIES_MAGNEMITE},
};

const struct WildPokemonInfo gNewMauville_Entrance_LandMonsInfo = {10, gNewMauville_Entrance_LandMons};

const struct WildPokemon gSafariZone_Southwest_LandMons[] =
{
    {25, 25, SPECIES_ODDISH},
    {27, 27, SPECIES_ODDISH},
    {25, 25, SPECIES_GIRAFARIG},
    {27, 27, SPECIES_GIRAFARIG},
    {25, 25, SPECIES_NATU},
    {27, 27, SPECIES_DODUO},
    {25, 25, SPECIES_GLOOM},
    {27, 27, SPECIES_WOBBUFFET},
    {25, 25, SPECIES_PIKACHU},
    {27, 27, SPECIES_WOBBUFFET},
    {27, 27, SPECIES_PIKACHU},
    {29, 29, SPECIES_WOBBUFFET},
};

const struct WildPokemonInfo gSafariZone_Southwest_LandMonsInfo = {25, gSafariZone_Southwest_LandMons};

const struct WildPokemon gSafariZone_Southwest_WaterMons[] =
{
    {20, 30, SPECIES_PSYDUCK},
    {20, 30, SPECIES_PSYDUCK},
    {30, 35, SPECIES_PSYDUCK},
    {30, 35, SPECIES_PSYDUCK},
    {30, 35, SPECIES_PSYDUCK},
};

const struct WildPokemonInfo gSafariZone_Southwest_WaterMonsInfo = {9, gSafariZone_Southwest_WaterMons};

const struct WildPokemon gSafariZone_Southwest_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 25, SPECIES_GOLDEEN},
    {10, 30, SPECIES_GOLDEEN},
    {25, 30, SPECIES_GOLDEEN},
    {30, 35, SPECIES_GOLDEEN},
    {30, 35, SPECIES_SEAKING},
    {35, 40, SPECIES_SEAKING},
    {25, 30, SPECIES_SEAKING},
};

const struct WildPokemonInfo gSafariZone_Southwest_FishingMonsInfo = {35, gSafariZone_Southwest_FishingMons};

const struct WildPokemon gSafariZone_North_LandMons[] =
{
    {27, 27, SPECIES_PHANPY},
    {27, 27, SPECIES_ODDISH},
    {29, 29, SPECIES_PHANPY},
    {29, 29, SPECIES_ODDISH},
    {27, 27, SPECIES_NATU},
    {29, 29, SPECIES_GLOOM},
    {31, 31, SPECIES_GLOOM},
    {29, 29, SPECIES_NATU},
    {29, 29, SPECIES_XATU},
    {27, 27, SPECIES_HERACROSS},
    {31, 31, SPECIES_XATU},
    {29, 29, SPECIES_HERACROSS},
};

const struct WildPokemonInfo gSafariZone_North_LandMonsInfo = {25, gSafariZone_North_LandMons};

const struct WildPokemon gSafariZone_North_RockSmashMons[] =
{
    {10, 15, SPECIES_GEODUDE},
    {5, 10, SPECIES_GEODUDE},
    {15, 20, SPECIES_GEODUDE},
    {20, 25, SPECIES_GEODUDE},
    {25, 30, SPECIES_GEODUDE},
};

const struct WildPokemonInfo gSafariZone_North_RockSmashMonsInfo = {25, gSafariZone_North_RockSmashMons};

const struct WildPokemon gSafariZone_Northwest_LandMons[] =
{
    {27, 27, SPECIES_RHYHORN},
    {27, 27, SPECIES_ODDISH},
    {29, 29, SPECIES_RHYHORN},
    {29, 29, SPECIES_ODDISH},
    {27, 27, SPECIES_DODUO},
    {29, 29, SPECIES_GLOOM},
    {31, 31, SPECIES_GLOOM},
    {29, 29, SPECIES_DODUO},
    {29, 29, SPECIES_DODRIO},
    {27, 27, SPECIES_PINSIR},
    {31, 31, SPECIES_DODRIO},
    {29, 29, SPECIES_PINSIR},
};

const struct WildPokemonInfo gSafariZone_Northwest_LandMonsInfo = {25, gSafariZone_Northwest_LandMons};

const struct WildPokemon gSafariZone_Northwest_WaterMons[] =
{
    {20, 30, SPECIES_PSYDUCK},
    {20, 30, SPECIES_PSYDUCK},
    {30, 35, SPECIES_PSYDUCK},
    {30, 35, SPECIES_GOLDUCK},
    {25, 40, SPECIES_GOLDUCK},
};

const struct WildPokemonInfo gSafariZone_Northwest_WaterMonsInfo = {9, gSafariZone_Northwest_WaterMons};

const struct WildPokemon gSafariZone_Northwest_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 25, SPECIES_GOLDEEN},
    {10, 30, SPECIES_GOLDEEN},
    {25, 30, SPECIES_GOLDEEN},
    {30, 35, SPECIES_GOLDEEN},
    {30, 35, SPECIES_SEAKING},
    {35, 40, SPECIES_SEAKING},
    {25, 30, SPECIES_SEAKING},
};

const struct WildPokemonInfo gSafariZone_Northwest_FishingMonsInfo = {35, gSafariZone_Northwest_FishingMons};

const struct WildPokemon gVictoryRoad_B1F_LandMons[] =
{
    {40, 40, SPECIES_GOLBAT},
    {40, 40, SPECIES_HARIYAMA},
    {40, 40, SPECIES_LAIRON},
    {40, 40, SPECIES_LAIRON},
    {38, 38, SPECIES_GOLBAT},
    {38, 38, SPECIES_HARIYAMA},
    {42, 42, SPECIES_GOLBAT},
    {42, 42, SPECIES_HARIYAMA},
    {42, 42, SPECIES_LAIRON},
    {38, 38, SPECIES_MAWILE},
    {42, 42, SPECIES_LAIRON},
    {38, 38, SPECIES_MAWILE},
};

const struct WildPokemonInfo gVictoryRoad_B1F_LandMonsInfo = {10, gVictoryRoad_B1F_LandMons};

const struct WildPokemon gVictoryRoad_B1F_RockSmashMons[] =
{
    {30, 40, SPECIES_GRAVELER},
    {30, 40, SPECIES_GEODUDE},
    {35, 40, SPECIES_GRAVELER},
    {35, 40, SPECIES_GRAVELER},
    {35, 40, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gVictoryRoad_B1F_RockSmashMonsInfo = {20, gVictoryRoad_B1F_RockSmashMons};

const struct WildPokemon gVictoryRoad_B2F_LandMons[] =
{
    {40, 40, SPECIES_GOLBAT},
    {40, 40, SPECIES_SABLEYE},
    {40, 40, SPECIES_LAIRON},
    {40, 40, SPECIES_LAIRON},
    {42, 42, SPECIES_GOLBAT},
    {42, 42, SPECIES_SABLEYE},
    {44, 44, SPECIES_GOLBAT},
    {44, 44, SPECIES_SABLEYE},
    {42, 42, SPECIES_LAIRON},
    {42, 42, SPECIES_MAWILE},
    {44, 44, SPECIES_LAIRON},
    {44, 44, SPECIES_MAWILE},
};

const struct WildPokemonInfo gVictoryRoad_B2F_LandMonsInfo = {10, gVictoryRoad_B2F_LandMons};

const struct WildPokemon gVictoryRoad_B2F_WaterMons[] =
{
    {30, 35, SPECIES_GOLBAT},
    {25, 30, SPECIES_GOLBAT},
    {35, 40, SPECIES_GOLBAT},
    {35, 40, SPECIES_GOLBAT},
    {35, 40, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gVictoryRoad_B2F_WaterMonsInfo = {4, gVictoryRoad_B2F_WaterMons};

const struct WildPokemon gVictoryRoad_B2F_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {30, 35, SPECIES_WHISCASH},
    {35, 40, SPECIES_WHISCASH},
    {40, 45, SPECIES_WHISCASH},
};

const struct WildPokemonInfo gVictoryRoad_B2F_FishingMonsInfo = {30, gVictoryRoad_B2F_FishingMons};

const struct WildPokemon gMeteorFalls_1F_1R_LandMons[] =
{
    {16, 16, SPECIES_ZUBAT},
    {17, 17, SPECIES_ZUBAT},
    {18, 18, SPECIES_ZUBAT},
    {15, 15, SPECIES_ZUBAT},
    {14, 14, SPECIES_ZUBAT},
    {16, 16, SPECIES_SOLROCK},
    {18, 18, SPECIES_SOLROCK},
    {14, 14, SPECIES_SOLROCK},
    {19, 19, SPECIES_ZUBAT},
    {20, 20, SPECIES_ZUBAT},
    {19, 19, SPECIES_ZUBAT},
    {20, 20, SPECIES_ZUBAT},
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_LandMonsInfo = {10, gMeteorFalls_1F_1R_LandMons};

const struct WildPokemon gMeteorFalls_1F_1R_WaterMons[] =
{
    {5, 35, SPECIES_ZUBAT},
    {30, 35, SPECIES_ZUBAT},
    {25, 35, SPECIES_SOLROCK},
    {15, 25, SPECIES_SOLROCK},
    {5, 15, SPECIES_SOLROCK},
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_WaterMonsInfo = {4, gMeteorFalls_1F_1R_WaterMons};

const struct WildPokemon gMeteorFalls_1F_1R_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {20, 25, SPECIES_BARBOACH},
    {35, 40, SPECIES_BARBOACH},
    {40, 45, SPECIES_BARBOACH},
};

const struct WildPokemonInfo gMeteorFalls_1F_1R_FishingMonsInfo = {30, gMeteorFalls_1F_1R_FishingMons};

const struct WildPokemon gMeteorFalls_1F_2R_LandMons[] =
{
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_SOLROCK},
    {33, 33, SPECIES_SOLROCK},
    {37, 37, SPECIES_SOLROCK},
    {35, 35, SPECIES_GOLBAT},
    {39, 39, SPECIES_SOLROCK},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_LandMonsInfo = {10, gMeteorFalls_1F_2R_LandMons};

const struct WildPokemon gMeteorFalls_1F_2R_WaterMons[] =
{
    {30, 35, SPECIES_GOLBAT},
    {30, 35, SPECIES_GOLBAT},
    {25, 35, SPECIES_SOLROCK},
    {15, 25, SPECIES_SOLROCK},
    {5, 15, SPECIES_SOLROCK},
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_WaterMonsInfo = {4, gMeteorFalls_1F_2R_WaterMons};

const struct WildPokemon gMeteorFalls_1F_2R_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {30, 35, SPECIES_WHISCASH},
    {35, 40, SPECIES_WHISCASH},
    {40, 45, SPECIES_WHISCASH},
};

const struct WildPokemonInfo gMeteorFalls_1F_2R_FishingMonsInfo = {30, gMeteorFalls_1F_2R_FishingMons};

const struct WildPokemon gMeteorFalls_B1F_1R_LandMons[] =
{
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_SOLROCK},
    {33, 33, SPECIES_SOLROCK},
    {37, 37, SPECIES_SOLROCK},
    {35, 35, SPECIES_GOLBAT},
    {39, 39, SPECIES_SOLROCK},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_LandMonsInfo = {10, gMeteorFalls_B1F_1R_LandMons};

const struct WildPokemon gMeteorFalls_B1F_1R_WaterMons[] =
{
    {30, 35, SPECIES_GOLBAT},
    {30, 35, SPECIES_GOLBAT},
    {25, 35, SPECIES_SOLROCK},
    {15, 25, SPECIES_SOLROCK},
    {5, 15, SPECIES_SOLROCK},
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_WaterMonsInfo = {4, gMeteorFalls_B1F_1R_WaterMons};

const struct WildPokemon gMeteorFalls_B1F_1R_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_BARBOACH},
    {25, 30, SPECIES_BARBOACH},
    {30, 35, SPECIES_BARBOACH},
    {30, 35, SPECIES_WHISCASH},
    {35, 40, SPECIES_WHISCASH},
    {40, 45, SPECIES_WHISCASH},
};

const struct WildPokemonInfo gMeteorFalls_B1F_1R_FishingMonsInfo = {30, gMeteorFalls_B1F_1R_FishingMons};

const struct WildPokemon gShoalCave_LowTideStairsRoom_LandMons[] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};

const struct WildPokemonInfo gShoalCave_LowTideStairsRoom_LandMonsInfo = {10, gShoalCave_LowTideStairsRoom_LandMons};

const struct WildPokemon gShoalCave_LowTideLowerRoom_LandMons[] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};

const struct WildPokemonInfo gShoalCave_LowTideLowerRoom_LandMonsInfo = {10, gShoalCave_LowTideLowerRoom_LandMons};

const struct WildPokemon gShoalCave_LowTideInnerRoom_LandMons[] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_LandMonsInfo = {10, gShoalCave_LowTideInnerRoom_LandMons};

const struct WildPokemon gShoalCave_LowTideInnerRoom_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_ZUBAT},
    {25, 30, SPECIES_SPHEAL},
    {25, 30, SPECIES_SPHEAL},
    {25, 35, SPECIES_SPHEAL},
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_WaterMonsInfo = {4, gShoalCave_LowTideInnerRoom_WaterMons};

const struct WildPokemon gShoalCave_LowTideInnerRoom_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gShoalCave_LowTideInnerRoom_FishingMonsInfo = {10, gShoalCave_LowTideInnerRoom_FishingMons};

const struct WildPokemon gShoalCave_LowTideEntranceRoom_LandMons[] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {32, 32, SPECIES_ZUBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
    {32, 32, SPECIES_GOLBAT},
    {32, 32, SPECIES_SPHEAL},
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_LandMonsInfo = {10, gShoalCave_LowTideEntranceRoom_LandMons};

const struct WildPokemon gShoalCave_LowTideEntranceRoom_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {5, 35, SPECIES_ZUBAT},
    {25, 30, SPECIES_SPHEAL},
    {25, 30, SPECIES_SPHEAL},
    {25, 35, SPECIES_SPHEAL},
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_WaterMonsInfo = {4, gShoalCave_LowTideEntranceRoom_WaterMons};

const struct WildPokemon gShoalCave_LowTideEntranceRoom_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gShoalCave_LowTideEntranceRoom_FishingMonsInfo = {10, gShoalCave_LowTideEntranceRoom_FishingMons};

const struct WildPokemon gLilycoveCity_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gLilycoveCity_WaterMonsInfo = {4, gLilycoveCity_WaterMons};

const struct WildPokemon gLilycoveCity_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_STARYU},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gLilycoveCity_FishingMonsInfo = {10, gLilycoveCity_FishingMons};

const struct WildPokemon gDewfordTown_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gDewfordTown_WaterMonsInfo = {4, gDewfordTown_WaterMons};

const struct WildPokemon gDewfordTown_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gDewfordTown_FishingMonsInfo = {10, gDewfordTown_FishingMons};

const struct WildPokemon gSlateportCity_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gSlateportCity_WaterMonsInfo = {4, gSlateportCity_WaterMons};

const struct WildPokemon gSlateportCity_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_WAILMER},
    {20, 25, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gSlateportCity_FishingMonsInfo = {10, gSlateportCity_FishingMons};

const struct WildPokemon gMossdeepCity_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gMossdeepCity_WaterMonsInfo = {4, gMossdeepCity_WaterMons};

const struct WildPokemon gMossdeepCity_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gMossdeepCity_FishingMonsInfo = {10, gMossdeepCity_FishingMons};

const struct WildPokemon gPacifidlogTown_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gPacifidlogTown_WaterMonsInfo = {4, gPacifidlogTown_WaterMons};

const struct WildPokemon gPacifidlogTown_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_SHARPEDO},
    {30, 35, SPECIES_WAILMER},
    {25, 30, SPECIES_WAILMER},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gPacifidlogTown_FishingMonsInfo = {10, gPacifidlogTown_FishingMons};

const struct WildPokemon gEverGrandeCity_WaterMons[] =
{
    {5, 35, SPECIES_TENTACOOL},
    {10, 30, SPECIES_WINGULL},
    {15, 25, SPECIES_WINGULL},
    {25, 30, SPECIES_PELIPPER},
    {25, 30, SPECIES_PELIPPER},
};

const struct WildPokemonInfo gEverGrandeCity_WaterMonsInfo = {4, gEverGrandeCity_WaterMons};

const struct WildPokemon gEverGrandeCity_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_LUVDISC},
    {10, 30, SPECIES_WAILMER},
    {30, 35, SPECIES_LUVDISC},
    {30, 35, SPECIES_WAILMER},
    {30, 35, SPECIES_CORSOLA},
    {35, 40, SPECIES_WAILMER},
    {40, 45, SPECIES_WAILMER},
};

const struct WildPokemonInfo gEverGrandeCity_FishingMonsInfo = {10, gEverGrandeCity_FishingMons};

const struct WildPokemon gPetalburgCity_WaterMons[] =
{
    {20, 30, SPECIES_MARILL},
    {10, 20, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
    {5, 10, SPECIES_MARILL},
};

const struct WildPokemonInfo gPetalburgCity_WaterMonsInfo = {1, gPetalburgCity_WaterMons};

const struct WildPokemon gPetalburgCity_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_GOLDEEN},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_GOLDEEN},
    {10, 30, SPECIES_CORPHISH},
    {25, 30, SPECIES_CORPHISH},
    {30, 35, SPECIES_CORPHISH},
    {20, 25, SPECIES_CORPHISH},
    {35, 40, SPECIES_CORPHISH},
    {40, 45, SPECIES_CORPHISH},
};

const struct WildPokemonInfo gPetalburgCity_FishingMonsInfo = {10, gPetalburgCity_FishingMons};

const struct WildPokemon gUnderwater1_WaterMons[] =
{
    {20, 30, SPECIES_CLAMPERL},
    {20, 30, SPECIES_CHINCHOU},
    {30, 35, SPECIES_CLAMPERL},
    {30, 35, SPECIES_RELICANTH},
    {30, 35, SPECIES_RELICANTH},
};

const struct WildPokemonInfo gUnderwater1_WaterMonsInfo = {4, gUnderwater1_WaterMons};

const struct WildPokemon gShoalCave_LowTideIceRoom_LandMons[] =
{
    {26, 26, SPECIES_ZUBAT},
    {26, 26, SPECIES_SPHEAL},
    {28, 28, SPECIES_ZUBAT},
    {28, 28, SPECIES_SPHEAL},
    {30, 30, SPECIES_ZUBAT},
    {30, 30, SPECIES_SPHEAL},
    {26, 26, SPECIES_SNORUNT},
    {32, 32, SPECIES_SPHEAL},
    {30, 30, SPECIES_GOLBAT},
    {28, 28, SPECIES_SNORUNT},
    {32, 32, SPECIES_GOLBAT},
    {30, 30, SPECIES_SNORUNT},
};

const struct WildPokemonInfo gShoalCave_LowTideIceRoom_LandMonsInfo = {10, gShoalCave_LowTideIceRoom_LandMons};

const struct WildPokemon gSkyPillar_1F_LandMons[] =
{
    {33, 33, SPECIES_SABLEYE},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {34, 34, SPECIES_SABLEYE},
    {36, 36, SPECIES_CLAYDOL},
    {37, 37, SPECIES_BANETTE},
    {38, 38, SPECIES_BANETTE},
    {36, 36, SPECIES_CLAYDOL},
    {37, 37, SPECIES_CLAYDOL},
    {38, 38, SPECIES_CLAYDOL},
    {37, 37, SPECIES_CLAYDOL},
    {38, 38, SPECIES_CLAYDOL},
};

const struct WildPokemonInfo gSkyPillar_1F_LandMonsInfo = {10, gSkyPillar_1F_LandMons};

const struct WildPokemon gSootopolisCity_WaterMons[] =
{
    {5, 35, SPECIES_MAGIKARP},
    {10, 30, SPECIES_MAGIKARP},
    {15, 25, SPECIES_MAGIKARP},
    {25, 30, SPECIES_MAGIKARP},
    {25, 30, SPECIES_MAGIKARP},
};

const struct WildPokemonInfo gSootopolisCity_WaterMonsInfo = {1, gSootopolisCity_WaterMons};

const struct WildPokemon gSootopolisCity_FishingMons[] =
{
    {5, 10, SPECIES_MAGIKARP},
    {5, 10, SPECIES_TENTACOOL},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_MAGIKARP},
    {10, 30, SPECIES_MAGIKARP},
    {30, 35, SPECIES_MAGIKARP},
    {30, 35, SPECIES_MAGIKARP},
    {35, 40, SPECIES_GYARADOS},
    {35, 45, SPECIES_GYARADOS},
    {5, 45, SPECIES_GYARADOS},
};

const struct WildPokemonInfo gSootopolisCity_FishingMonsInfo = {10, gSootopolisCity_FishingMons};

const struct WildPokemon gSkyPillar_3F_LandMons[] =
{
    {33, 33, SPECIES_SABLEYE},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {34, 34, SPECIES_SABLEYE},
    {36, 36, SPECIES_CLAYDOL},
    {37, 37, SPECIES_BANETTE},
    {38, 38, SPECIES_BANETTE},
    {36, 36, SPECIES_CLAYDOL},
    {37, 37, SPECIES_CLAYDOL},
    {38, 38, SPECIES_CLAYDOL},
    {37, 37, SPECIES_CLAYDOL},
    {38, 38, SPECIES_CLAYDOL},
};

const struct WildPokemonInfo gSkyPillar_3F_LandMonsInfo = {10, gSkyPillar_3F_LandMons};

const struct WildPokemon gSkyPillar_5F_LandMons[] =
{
    {33, 33, SPECIES_SABLEYE},
    {34, 34, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {34, 34, SPECIES_SABLEYE},
    {36, 36, SPECIES_CLAYDOL},
    {37, 37, SPECIES_BANETTE},
    {38, 38, SPECIES_BANETTE},
    {36, 36, SPECIES_CLAYDOL},
    {37, 37, SPECIES_CLAYDOL},
    {38, 38, SPECIES_ALTARIA},
    {39, 39, SPECIES_ALTARIA},
    {39, 39, SPECIES_ALTARIA},
};

const struct WildPokemonInfo gSkyPillar_5F_LandMonsInfo = {10, gSkyPillar_5F_LandMons};

const struct WildPokemon gSafariZone_Southeast_LandMons[] =
{
    {33, 33, SPECIES_SUNKERN},
    {34, 34, SPECIES_MAREEP},
    {35, 35, SPECIES_SUNKERN},
    {36, 36, SPECIES_MAREEP},
    {34, 34, SPECIES_AIPOM},
    {33, 33, SPECIES_SPINARAK},
    {35, 35, SPECIES_HOOTHOOT},
    {34, 34, SPECIES_SNUBBULL},
    {36, 36, SPECIES_STANTLER},
    {37, 37, SPECIES_GLIGAR},
    {39, 39, SPECIES_STANTLER},
    {40, 40, SPECIES_GLIGAR},
};

const struct WildPokemonInfo gSafariZone_Southeast_LandMonsInfo = {25, gSafariZone_Southeast_LandMons};

const struct WildPokemon gSafariZone_Southeast_WaterMons[] =
{
    {25, 30, SPECIES_WOOPER},
    {25, 30, SPECIES_MARILL},
    {25, 30, SPECIES_MARILL},
    {30, 35, SPECIES_MARILL},
    {35, 40, SPECIES_QUAGSIRE},
};

const struct WildPokemonInfo gSafariZone_Southeast_WaterMonsInfo = {9, gSafariZone_Southeast_WaterMons};

const struct WildPokemon gSafariZone_Southeast_FishingMons[] =
{
    {25, 30, SPECIES_MAGIKARP},
    {25, 30, SPECIES_GOLDEEN},
    {25, 30, SPECIES_MAGIKARP},
    {25, 30, SPECIES_GOLDEEN},
    {30, 35, SPECIES_REMORAID},
    {25, 30, SPECIES_GOLDEEN},
    {25, 30, SPECIES_REMORAID},
    {30, 35, SPECIES_REMORAID},
    {30, 35, SPECIES_REMORAID},
    {35, 40, SPECIES_OCTILLERY},
};

const struct WildPokemonInfo gSafariZone_Southeast_FishingMonsInfo = {35, gSafariZone_Southeast_FishingMons};

const struct WildPokemon gSafariZone_Northeast_LandMons[] =
{
    {33, 33, SPECIES_AIPOM},
    {34, 34, SPECIES_TEDDIURSA},
    {35, 35, SPECIES_AIPOM},
    {36, 36, SPECIES_TEDDIURSA},
    {34, 34, SPECIES_SUNKERN},
    {33, 33, SPECIES_LEDYBA},
    {35, 35, SPECIES_HOOTHOOT},
    {34, 34, SPECIES_PINECO},
    {36, 36, SPECIES_HOUNDOUR},
    {37, 37, SPECIES_MILTANK},
    {39, 39, SPECIES_HOUNDOUR},
    {40, 40, SPECIES_MILTANK},
};

const struct WildPokemonInfo gSafariZone_Northeast_LandMonsInfo = {25, gSafariZone_Northeast_LandMons};

const struct WildPokemon gSafariZone_Northeast_RockSmashMons[] =
{
    {25, 30, SPECIES_SHUCKLE},
    {20, 25, SPECIES_SHUCKLE},
    {30, 35, SPECIES_SHUCKLE},
    {30, 35, SPECIES_SHUCKLE},
    {35, 40, SPECIES_SHUCKLE},
};

const struct WildPokemonInfo gSafariZone_Northeast_RockSmashMonsInfo = {25, gSafariZone_Northeast_RockSmashMons};

const struct WildPokemon gMagmaHideout_1F_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_1F_LandMonsInfo = {10, gMagmaHideout_1F_LandMons};

const struct WildPokemon gMagmaHideout_2F_1R_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_2F_1R_LandMonsInfo = {10, gMagmaHideout_2F_1R_LandMons};

const struct WildPokemon gMagmaHideout_2F_2R_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_2F_2R_LandMonsInfo = {10, gMagmaHideout_2F_2R_LandMons};

const struct WildPokemon gMagmaHideout_3F_1R_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_3F_1R_LandMonsInfo = {10, gMagmaHideout_3F_1R_LandMons};

const struct WildPokemon gMagmaHideout_3F_2R_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_3F_2R_LandMonsInfo = {10, gMagmaHideout_3F_2R_LandMons};

const struct WildPokemon gMagmaHideout_4F_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_4F_LandMonsInfo = {10, gMagmaHideout_4F_LandMons};

const struct WildPokemon gMagmaHideout_3F_3R_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_3F_3R_LandMonsInfo = {10, gMagmaHideout_3F_3R_LandMons};

const struct WildPokemon gMagmaHideout_2F_3R_LandMons[] =
{
    {27, 27, SPECIES_GEODUDE},
    {28, 28, SPECIES_TORKOAL},
    {28, 28, SPECIES_GEODUDE},
    {30, 30, SPECIES_TORKOAL},
    {29, 29, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GEODUDE},
    {30, 30, SPECIES_GRAVELER},
    {30, 30, SPECIES_GRAVELER},
    {31, 31, SPECIES_GRAVELER},
    {32, 32, SPECIES_GRAVELER},
    {33, 33, SPECIES_GRAVELER},
};

const struct WildPokemonInfo gMagmaHideout_2F_3R_LandMonsInfo = {10, gMagmaHideout_2F_3R_LandMons};

const struct WildPokemon gMirageTower_1F_LandMons[] =
{
    {21, 21, SPECIES_SANDSHREW},
    {21, 21, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {22, 22, SPECIES_SANDSHREW},
    {22, 22, SPECIES_TRAPINCH},
    {23, 23, SPECIES_SANDSHREW},
    {23, 23, SPECIES_TRAPINCH},
    {24, 24, SPECIES_SANDSHREW},
    {24, 24, SPECIES_TRAPINCH},
};

const struct WildPokemonInfo gMirageTower_1F_LandMonsInfo = {10, gMirageTower_1F_LandMons};

const struct WildPokemon gMirageTower_2F_LandMons[] =
{
    {21, 21, SPECIES_SANDSHREW},
    {21, 21, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {22, 22, SPECIES_SANDSHREW},
    {22, 22, SPECIES_TRAPINCH},
    {23, 23, SPECIES_SANDSHREW},
    {23, 23, SPECIES_TRAPINCH},
    {24, 24, SPECIES_SANDSHREW},
    {24, 24, SPECIES_TRAPINCH},
};

const struct WildPokemonInfo gMirageTower_2F_LandMonsInfo = {10, gMirageTower_2F_LandMons};

const struct WildPokemon gMirageTower_3F_LandMons[] =
{
    {21, 21, SPECIES_SANDSHREW},
    {21, 21, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {22, 22, SPECIES_SANDSHREW},
    {22, 22, SPECIES_TRAPINCH},
    {23, 23, SPECIES_SANDSHREW},
    {23, 23, SPECIES_TRAPINCH},
    {24, 24, SPECIES_SANDSHREW},
    {24, 24, SPECIES_TRAPINCH},
};

const struct WildPokemonInfo gMirageTower_3F_LandMonsInfo = {10, gMirageTower_3F_LandMons};

const struct WildPokemon gMirageTower_4F_LandMons[] =
{
    {21, 21, SPECIES_SANDSHREW},
    {21, 21, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {20, 20, SPECIES_SANDSHREW},
    {20, 20, SPECIES_TRAPINCH},
    {22, 22, SPECIES_SANDSHREW},
    {22, 22, SPECIES_TRAPINCH},
    {23, 23, SPECIES_SANDSHREW},
    {23, 23, SPECIES_TRAPINCH},
    {24, 24, SPECIES_SANDSHREW},
    {24, 24, SPECIES_TRAPINCH},
};

const struct WildPokemonInfo gMirageTower_4F_LandMonsInfo = {10, gMirageTower_4F_LandMons};

const struct WildPokemon gDesertUnderpass_LandMons[] =
{
    {38, 38, SPECIES_DITTO},
    {35, 35, SPECIES_WHISMUR},
    {40, 40, SPECIES_DITTO},
    {40, 40, SPECIES_LOUDRED},
    {41, 41, SPECIES_DITTO},
    {36, 36, SPECIES_WHISMUR},
    {38, 38, SPECIES_LOUDRED},
    {42, 42, SPECIES_DITTO},
    {38, 38, SPECIES_WHISMUR},
    {43, 43, SPECIES_DITTO},
    {44, 44, SPECIES_LOUDRED},
    {45, 45, SPECIES_DITTO},
};

const struct WildPokemonInfo gDesertUnderpass_LandMonsInfo = {10, gDesertUnderpass_LandMons};

const struct WildPokemon gArtisanCave_B1F_LandMons[] =
{
    {40, 40, SPECIES_SMEARGLE},
    {41, 41, SPECIES_SMEARGLE},
    {42, 42, SPECIES_SMEARGLE},
    {43, 43, SPECIES_SMEARGLE},
    {44, 44, SPECIES_SMEARGLE},
    {45, 45, SPECIES_SMEARGLE},
    {46, 46, SPECIES_SMEARGLE},
    {47, 47, SPECIES_SMEARGLE},
    {48, 48, SPECIES_SMEARGLE},
    {49, 49, SPECIES_SMEARGLE},
    {50, 50, SPECIES_SMEARGLE},
    {50, 50, SPECIES_SMEARGLE},
};

const struct WildPokemonInfo gArtisanCave_B1F_LandMonsInfo = {10, gArtisanCave_B1F_LandMons};

const struct WildPokemon gArtisanCave_1F_LandMons[] =
{
    {40, 40, SPECIES_SMEARGLE},
    {41, 41, SPECIES_SMEARGLE},
    {42, 42, SPECIES_SMEARGLE},
    {43, 43, SPECIES_SMEARGLE},
    {44, 44, SPECIES_SMEARGLE},
    {45, 45, SPECIES_SMEARGLE},
    {46, 46, SPECIES_SMEARGLE},
    {47, 47, SPECIES_SMEARGLE},
    {48, 48, SPECIES_SMEARGLE},
    {49, 49, SPECIES_SMEARGLE},
    {50, 50, SPECIES_SMEARGLE},
    {50, 50, SPECIES_SMEARGLE},
};

const struct WildPokemonInfo gArtisanCave_1F_LandMonsInfo = {10, gArtisanCave_1F_LandMons};

const struct WildPokemon gAlteringCave1_LandMons[] =
{
    {10, 10, SPECIES_ZUBAT},
    {12, 12, SPECIES_ZUBAT},
    {8, 8, SPECIES_ZUBAT},
    {14, 14, SPECIES_ZUBAT},
    {10, 10, SPECIES_ZUBAT},
    {12, 12, SPECIES_ZUBAT},
    {16, 16, SPECIES_ZUBAT},
    {6, 6, SPECIES_ZUBAT},
    {8, 8, SPECIES_ZUBAT},
    {14, 14, SPECIES_ZUBAT},
    {8, 8, SPECIES_ZUBAT},
    {14, 14, SPECIES_ZUBAT},
};

const struct WildPokemonInfo gAlteringCave1_LandMonsInfo = {7, gAlteringCave1_LandMons};

const struct WildPokemon gAlteringCave2_LandMons[] =
{
    {7, 7, SPECIES_MAREEP},
    {9, 9, SPECIES_MAREEP},
    {5, 5, SPECIES_MAREEP},
    {11, 11, SPECIES_MAREEP},
    {7, 7, SPECIES_MAREEP},
    {9, 9, SPECIES_MAREEP},
    {13, 13, SPECIES_MAREEP},
    {3, 3, SPECIES_MAREEP},
    {5, 5, SPECIES_MAREEP},
    {11, 11, SPECIES_MAREEP},
    {5, 5, SPECIES_MAREEP},
    {11, 11, SPECIES_MAREEP},
};

const struct WildPokemonInfo gAlteringCave2_LandMonsInfo = {7, gAlteringCave2_LandMons};

const struct WildPokemon gAlteringCave3_LandMons[] =
{
    {23, 23, SPECIES_PINECO},
    {25, 25, SPECIES_PINECO},
    {22, 22, SPECIES_PINECO},
    {27, 27, SPECIES_PINECO},
    {23, 23, SPECIES_PINECO},
    {25, 25, SPECIES_PINECO},
    {29, 29, SPECIES_PINECO},
    {19, 19, SPECIES_PINECO},
    {21, 21, SPECIES_PINECO},
    {27, 27, SPECIES_PINECO},
    {21, 21, SPECIES_PINECO},
    {27, 27, SPECIES_PINECO},
};

const struct WildPokemonInfo gAlteringCave3_LandMonsInfo = {7, gAlteringCave3_LandMons};

const struct WildPokemon gAlteringCave4_LandMons[] =
{
    {16, 16, SPECIES_HOUNDOUR},
    {18, 18, SPECIES_HOUNDOUR},
    {14, 14, SPECIES_HOUNDOUR},
    {20, 20, SPECIES_HOUNDOUR},
    {16, 16, SPECIES_HOUNDOUR},
    {18, 18, SPECIES_HOUNDOUR},
    {22, 22, SPECIES_HOUNDOUR},
    {12, 12, SPECIES_HOUNDOUR},
    {14, 14, SPECIES_HOUNDOUR},
    {20, 20, SPECIES_HOUNDOUR},
    {14, 14, SPECIES_HOUNDOUR},
    {20, 20, SPECIES_HOUNDOUR},
};

const struct WildPokemonInfo gAlteringCave4_LandMonsInfo = {7, gAlteringCave4_LandMons};

const struct WildPokemon gAlteringCave5_LandMons[] =
{
    {10, 10, SPECIES_TEDDIURSA},
    {12, 12, SPECIES_TEDDIURSA},
    {8, 8, SPECIES_TEDDIURSA},
    {14, 14, SPECIES_TEDDIURSA},
    {10, 10, SPECIES_TEDDIURSA},
    {12, 12, SPECIES_TEDDIURSA},
    {16, 16, SPECIES_TEDDIURSA},
    {6, 6, SPECIES_TEDDIURSA},
    {8, 8, SPECIES_TEDDIURSA},
    {14, 14, SPECIES_TEDDIURSA},
    {8, 8, SPECIES_TEDDIURSA},
    {14, 14, SPECIES_TEDDIURSA},
};

const struct WildPokemonInfo gAlteringCave5_LandMonsInfo = {7, gAlteringCave5_LandMons};

const struct WildPokemon gAlteringCave6_LandMons[] =
{
    {22, 22, SPECIES_AIPOM},
    {24, 24, SPECIES_AIPOM},
    {20, 20, SPECIES_AIPOM},
    {26, 26, SPECIES_AIPOM},
    {22, 22, SPECIES_AIPOM},
    {24, 24, SPECIES_AIPOM},
    {28, 28, SPECIES_AIPOM},
    {18, 18, SPECIES_AIPOM},
    {20, 20, SPECIES_AIPOM},
    {26, 26, SPECIES_AIPOM},
    {20, 20, SPECIES_AIPOM},
    {26, 26, SPECIES_AIPOM},
};

const struct WildPokemonInfo gAlteringCave6_LandMonsInfo = {7, gAlteringCave6_LandMons};

const struct WildPokemon gAlteringCave7_LandMons[] =
{
    {22, 22, SPECIES_SHUCKLE},
    {24, 24, SPECIES_SHUCKLE},
    {20, 20, SPECIES_SHUCKLE},
    {26, 26, SPECIES_SHUCKLE},
    {22, 22, SPECIES_SHUCKLE},
    {24, 24, SPECIES_SHUCKLE},
    {28, 28, SPECIES_SHUCKLE},
    {18, 18, SPECIES_SHUCKLE},
    {20, 20, SPECIES_SHUCKLE},
    {26, 26, SPECIES_SHUCKLE},
    {20, 20, SPECIES_SHUCKLE},
    {26, 26, SPECIES_SHUCKLE},
};

const struct WildPokemonInfo gAlteringCave7_LandMonsInfo = {7, gAlteringCave7_LandMons};

const struct WildPokemon gAlteringCave8_LandMons[] =
{
    {22, 22, SPECIES_STANTLER},
    {24, 24, SPECIES_STANTLER},
    {20, 20, SPECIES_STANTLER},
    {26, 26, SPECIES_STANTLER},
    {22, 22, SPECIES_STANTLER},
    {24, 24, SPECIES_STANTLER},
    {28, 28, SPECIES_STANTLER},
    {18, 18, SPECIES_STANTLER},
    {20, 20, SPECIES_STANTLER},
    {26, 26, SPECIES_STANTLER},
    {20, 20, SPECIES_STANTLER},
    {26, 26, SPECIES_STANTLER},
};

const struct WildPokemonInfo gAlteringCave8_LandMonsInfo = {7, gAlteringCave8_LandMons};

const struct WildPokemon gAlteringCave9_LandMons[] =
{
    {22, 22, SPECIES_SMEARGLE},
    {24, 24, SPECIES_SMEARGLE},
    {20, 20, SPECIES_SMEARGLE},
    {26, 26, SPECIES_SMEARGLE},
    {22, 22, SPECIES_SMEARGLE},
    {24, 24, SPECIES_SMEARGLE},
    {28, 28, SPECIES_SMEARGLE},
    {18, 18, SPECIES_SMEARGLE},
    {20, 20, SPECIES_SMEARGLE},
    {26, 26, SPECIES_SMEARGLE},
    {20, 20, SPECIES_SMEARGLE},
    {26, 26, SPECIES_SMEARGLE},
};

const struct WildPokemonInfo gAlteringCave9_LandMonsInfo = {7, gAlteringCave9_LandMons};

const struct WildPokemon gMeteorFalls_StevensCave_LandMons[] =
{
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_GOLBAT},
    {33, 33, SPECIES_GOLBAT},
    {35, 35, SPECIES_SOLROCK},
    {33, 33, SPECIES_SOLROCK},
    {37, 37, SPECIES_SOLROCK},
    {35, 35, SPECIES_GOLBAT},
    {39, 39, SPECIES_SOLROCK},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
    {38, 38, SPECIES_GOLBAT},
    {40, 40, SPECIES_GOLBAT},
};

const struct WildPokemonInfo gMeteorFalls_StevensCave_LandMonsInfo = {10, gMeteorFalls_StevensCave_LandMons};

//The actual headers that link the encounter tables to particular maps start here.

const struct WildPokemonHeader gWildMonHeaders[] =
{
    {
        .mapGroup = MAP_GROUP(ROUTE101),
        .mapNum = MAP_NUM(ROUTE101),
        .landMonsInfo = &gRoute101_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE102),
        .mapNum = MAP_NUM(ROUTE102),
        .landMonsInfo = &gRoute102_LandMonsInfo,
        .waterMonsInfo = &gRoute102_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute102_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE103),
        .mapNum = MAP_NUM(ROUTE103),
        .landMonsInfo = &gRoute103_LandMonsInfo,
        .waterMonsInfo = &gRoute103_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute103_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE104),
        .mapNum = MAP_NUM(ROUTE104),
        .landMonsInfo = &gRoute104_LandMonsInfo,
        .waterMonsInfo = &gRoute104_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute104_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE105),
        .mapNum = MAP_NUM(ROUTE105),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute105_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute105_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE110),
        .mapNum = MAP_NUM(ROUTE110),
        .landMonsInfo = &gRoute110_LandMonsInfo,
        .waterMonsInfo = &gRoute110_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute110_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE111),
        .mapNum = MAP_NUM(ROUTE111),
        .landMonsInfo = &gRoute111_LandMonsInfo,
        .waterMonsInfo = &gRoute111_WaterMonsInfo,
        .rockSmashMonsInfo = &gRoute111_RockSmashMonsInfo,
        .fishingMonsInfo = &gRoute111_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE112),
        .mapNum = MAP_NUM(ROUTE112),
        .landMonsInfo = &gRoute112_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE113),
        .mapNum = MAP_NUM(ROUTE113),
        .landMonsInfo = &gRoute113_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE114),
        .mapNum = MAP_NUM(ROUTE114),
        .landMonsInfo = &gRoute114_LandMonsInfo,
        .waterMonsInfo = &gRoute114_WaterMonsInfo,
        .rockSmashMonsInfo = &gRoute114_RockSmashMonsInfo,
        .fishingMonsInfo = &gRoute114_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE116),
        .mapNum = MAP_NUM(ROUTE116),
        .landMonsInfo = &gRoute116_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE117),
        .mapNum = MAP_NUM(ROUTE117),
        .landMonsInfo = &gRoute117_LandMonsInfo,
        .waterMonsInfo = &gRoute117_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute117_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE118),
        .mapNum = MAP_NUM(ROUTE118),
        .landMonsInfo = &gRoute118_LandMonsInfo,
        .waterMonsInfo = &gRoute118_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute118_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE124),
        .mapNum = MAP_NUM(ROUTE124),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute124_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute124_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_WOODS),
        .mapNum = MAP_NUM(PETALBURG_WOODS),
        .landMonsInfo = &gPetalburgWoods_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(RUSTURF_TUNNEL),
        .mapNum = MAP_NUM(RUSTURF_TUNNEL),
        .landMonsInfo = &gRusturfTunnel_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_1F),
        .landMonsInfo = &gGraniteCave_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B1F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B1F),
        .landMonsInfo = &gGraniteCave_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_1F),
        .mapNum = MAP_NUM(MT_PYRE_1F),
        .landMonsInfo = &gMtPyre_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_1F),
        .landMonsInfo = &gVictoryRoad_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTH),
        .landMonsInfo = &gSafariZone_South_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER2),
        .mapNum = MAP_NUM(UNDERWATER2),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gUnderwater2_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_ROOMS_B1F),
        .mapNum = MAP_NUM(ABANDONED_SHIP_ROOMS_B1F),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gAbandonedShip_Rooms_B1F_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gAbandonedShip_Rooms_B1F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_B2F),
        .mapNum = MAP_NUM(GRANITE_CAVE_B2F),
        .landMonsInfo = &gGraniteCave_B2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gGraniteCave_B2F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(FIERY_PATH),
        .mapNum = MAP_NUM(FIERY_PATH),
        .landMonsInfo = &gFieryPath_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_2R),
        .landMonsInfo = &gMeteorFalls_B1F_2R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_B1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_B1F_2R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(JAGGED_PASS),
        .mapNum = MAP_NUM(JAGGED_PASS),
        .landMonsInfo = &gJaggedPass_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE106),
        .mapNum = MAP_NUM(ROUTE106),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute106_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute106_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE107),
        .mapNum = MAP_NUM(ROUTE107),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute107_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute107_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE108),
        .mapNum = MAP_NUM(ROUTE108),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute108_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute108_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE109),
        .mapNum = MAP_NUM(ROUTE109),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute109_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute109_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE115),
        .mapNum = MAP_NUM(ROUTE115),
        .landMonsInfo = &gRoute115_LandMonsInfo,
        .waterMonsInfo = &gRoute115_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute115_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_INSIDE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_INSIDE),
        .landMonsInfo = &gNewMauville_Inside_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE119),
        .mapNum = MAP_NUM(ROUTE119),
        .landMonsInfo = &gRoute119_LandMonsInfo,
        .waterMonsInfo = &gRoute119_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute119_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE120),
        .mapNum = MAP_NUM(ROUTE120),
        .landMonsInfo = &gRoute120_LandMonsInfo,
        .waterMonsInfo = &gRoute120_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute120_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE121),
        .mapNum = MAP_NUM(ROUTE121),
        .landMonsInfo = &gRoute121_LandMonsInfo,
        .waterMonsInfo = &gRoute121_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute121_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE122),
        .mapNum = MAP_NUM(ROUTE122),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute122_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute122_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE123),
        .mapNum = MAP_NUM(ROUTE123),
        .landMonsInfo = &gRoute123_LandMonsInfo,
        .waterMonsInfo = &gRoute123_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute123_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_2F),
        .mapNum = MAP_NUM(MT_PYRE_2F),
        .landMonsInfo = &gMtPyre_2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_3F),
        .mapNum = MAP_NUM(MT_PYRE_3F),
        .landMonsInfo = &gMtPyre_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_4F),
        .mapNum = MAP_NUM(MT_PYRE_4F),
        .landMonsInfo = &gMtPyre_4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_5F),
        .mapNum = MAP_NUM(MT_PYRE_5F),
        .landMonsInfo = &gMtPyre_5F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_6F),
        .mapNum = MAP_NUM(MT_PYRE_6F),
        .landMonsInfo = &gMtPyre_6F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_EXTERIOR),
        .mapNum = MAP_NUM(MT_PYRE_EXTERIOR),
        .landMonsInfo = &gMtPyre_Exterior_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MT_PYRE_SUMMIT),
        .mapNum = MAP_NUM(MT_PYRE_SUMMIT),
        .landMonsInfo = &gMtPyre_Summit_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(GRANITE_CAVE_STEVENS_ROOM),
        .mapNum = MAP_NUM(GRANITE_CAVE_STEVENS_ROOM),
        .landMonsInfo = &gGraniteCave_StevensRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE125),
        .mapNum = MAP_NUM(ROUTE125),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute125_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute125_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE126),
        .mapNum = MAP_NUM(ROUTE126),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute126_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute126_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE127),
        .mapNum = MAP_NUM(ROUTE127),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute127_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute127_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE128),
        .mapNum = MAP_NUM(ROUTE128),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute128_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute128_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE129),
        .mapNum = MAP_NUM(ROUTE129),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute129_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute129_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE130),
        .mapNum = MAP_NUM(ROUTE130),
        .landMonsInfo = &gRoute130_LandMonsInfo,
        .waterMonsInfo = &gRoute130_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute130_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE131),
        .mapNum = MAP_NUM(ROUTE131),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute131_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute131_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE132),
        .mapNum = MAP_NUM(ROUTE132),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute132_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute132_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE133),
        .mapNum = MAP_NUM(ROUTE133),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute133_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute133_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ROUTE134),
        .mapNum = MAP_NUM(ROUTE134),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gRoute134_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gRoute134_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .mapNum = MAP_NUM(ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gAbandonedShip_HiddenFloorCorridors_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gAbandonedShip_HiddenFloorCorridors_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM1),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM1),
        .landMonsInfo = &gSeafloorCavern_Room1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM2),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM2),
        .landMonsInfo = &gSeafloorCavern_Room2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM3),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM3),
        .landMonsInfo = &gSeafloorCavern_Room3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM4),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM4),
        .landMonsInfo = &gSeafloorCavern_Room4_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM5),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM5),
        .landMonsInfo = &gSeafloorCavern_Room5_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM6),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM6),
        .landMonsInfo = &gSeafloorCavern_Room6_LandMonsInfo,
        .waterMonsInfo = &gSeafloorCavern_Room6_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Room6_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM7),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM7),
        .landMonsInfo = &gSeafloorCavern_Room7_LandMonsInfo,
        .waterMonsInfo = &gSeafloorCavern_Room7_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Room7_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ROOM8),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ROOM8),
        .landMonsInfo = &gSeafloorCavern_Room8_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SEAFLOOR_CAVERN_ENTRANCE),
        .mapNum = MAP_NUM(SEAFLOOR_CAVERN_ENTRANCE),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gSeafloorCavern_Entrance_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSeafloorCavern_Entrance_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_ENTRANCE),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_ENTRANCE),
        .landMonsInfo = &gCaveOfOrigin_Entrance_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_1F),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_1F),
        .landMonsInfo = &gCaveOfOrigin_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .mapNum = MAP_NUM(CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3),
        .landMonsInfo = &gCaveOfOrigin_UnusedRubySapphireMap3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(NEW_MAUVILLE_ENTRANCE),
        .mapNum = MAP_NUM(NEW_MAUVILLE_ENTRANCE),
        .landMonsInfo = &gNewMauville_Entrance_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHWEST),
        .landMonsInfo = &gSafariZone_Southwest_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_Southwest_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_Southwest_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTH),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTH),
        .landMonsInfo = &gSafariZone_North_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gSafariZone_North_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHWEST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHWEST),
        .landMonsInfo = &gSafariZone_Northwest_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_Northwest_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_Northwest_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B1F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B1F),
        .landMonsInfo = &gVictoryRoad_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gVictoryRoad_B1F_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(VICTORY_ROAD_B2F),
        .mapNum = MAP_NUM(VICTORY_ROAD_B2F),
        .landMonsInfo = &gVictoryRoad_B2F_LandMonsInfo,
        .waterMonsInfo = &gVictoryRoad_B2F_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gVictoryRoad_B2F_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_1R),
        .landMonsInfo = &gMeteorFalls_1F_1R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_1F_1R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_1F_2R),
        .mapNum = MAP_NUM(METEOR_FALLS_1F_2R),
        .landMonsInfo = &gMeteorFalls_1F_2R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_1F_2R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_1F_2R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_B1F_1R),
        .mapNum = MAP_NUM(METEOR_FALLS_B1F_1R),
        .landMonsInfo = &gMeteorFalls_B1F_1R_LandMonsInfo,
        .waterMonsInfo = &gMeteorFalls_B1F_1R_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMeteorFalls_B1F_1R_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM),
        .landMonsInfo = &gShoalCave_LowTideStairsRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_LOWER_ROOM),
        .landMonsInfo = &gShoalCave_LowTideLowerRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_INNER_ROOM),
        .landMonsInfo = &gShoalCave_LowTideInnerRoom_LandMonsInfo,
        .waterMonsInfo = &gShoalCave_LowTideInnerRoom_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gShoalCave_LowTideInnerRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM),
        .landMonsInfo = &gShoalCave_LowTideEntranceRoom_LandMonsInfo,
        .waterMonsInfo = &gShoalCave_LowTideEntranceRoom_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gShoalCave_LowTideEntranceRoom_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(LILYCOVE_CITY),
        .mapNum = MAP_NUM(LILYCOVE_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gLilycoveCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gLilycoveCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(DEWFORD_TOWN),
        .mapNum = MAP_NUM(DEWFORD_TOWN),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gDewfordTown_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gDewfordTown_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SLATEPORT_CITY),
        .mapNum = MAP_NUM(SLATEPORT_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gSlateportCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSlateportCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(MOSSDEEP_CITY),
        .mapNum = MAP_NUM(MOSSDEEP_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gMossdeepCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gMossdeepCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PACIFIDLOG_TOWN),
        .mapNum = MAP_NUM(PACIFIDLOG_TOWN),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gPacifidlogTown_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gPacifidlogTown_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(EVER_GRANDE_CITY),
        .mapNum = MAP_NUM(EVER_GRANDE_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gEverGrandeCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gEverGrandeCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(PETALBURG_CITY),
        .mapNum = MAP_NUM(PETALBURG_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gPetalburgCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gPetalburgCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(UNDERWATER1),
        .mapNum = MAP_NUM(UNDERWATER1),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gUnderwater1_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .mapNum = MAP_NUM(SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        .landMonsInfo = &gShoalCave_LowTideIceRoom_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_1F),
        .mapNum = MAP_NUM(SKY_PILLAR_1F),
        .landMonsInfo = &gSkyPillar_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SOOTOPOLIS_CITY),
        .mapNum = MAP_NUM(SOOTOPOLIS_CITY),
        .landMonsInfo = NULL,
        .waterMonsInfo = &gSootopolisCity_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSootopolisCity_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_3F),
        .mapNum = MAP_NUM(SKY_PILLAR_3F),
        .landMonsInfo = &gSkyPillar_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SKY_PILLAR_5F),
        .mapNum = MAP_NUM(SKY_PILLAR_5F),
        .landMonsInfo = &gSkyPillar_5F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_SOUTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_SOUTHEAST),
        .landMonsInfo = &gSafariZone_Southeast_LandMonsInfo,
        .waterMonsInfo = &gSafariZone_Southeast_WaterMonsInfo,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = &gSafariZone_Southeast_FishingMonsInfo,
    },
    {
        .mapGroup = MAP_GROUP(SAFARI_ZONE_NORTHEAST),
        .mapNum = MAP_NUM(SAFARI_ZONE_NORTHEAST),
        .landMonsInfo = &gSafariZone_Northeast_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = &gSafariZone_Northeast_RockSmashMonsInfo,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_1F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_1F),
        .landMonsInfo = &gMagmaHideout_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_1R),
        .landMonsInfo = &gMagmaHideout_2F_1R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_2R),
        .landMonsInfo = &gMagmaHideout_2F_2R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_1R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_1R),
        .landMonsInfo = &gMagmaHideout_3F_1R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_2R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_2R),
        .landMonsInfo = &gMagmaHideout_3F_2R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_4F),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_4F),
        .landMonsInfo = &gMagmaHideout_4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_3F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_3F_3R),
        .landMonsInfo = &gMagmaHideout_3F_3R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MAGMA_HIDEOUT_2F_3R),
        .mapNum = MAP_NUM(MAGMA_HIDEOUT_2F_3R),
        .landMonsInfo = &gMagmaHideout_2F_3R_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_1F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_1F),
        .landMonsInfo = &gMirageTower_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_2F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_2F),
        .landMonsInfo = &gMirageTower_2F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_3F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_3F),
        .landMonsInfo = &gMirageTower_3F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(MIRAGE_TOWER_4F),
        .mapNum = MAP_NUM(MIRAGE_TOWER_4F),
        .landMonsInfo = &gMirageTower_4F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(DESERT_UNDERPASS),
        .mapNum = MAP_NUM(DESERT_UNDERPASS),
        .landMonsInfo = &gDesertUnderpass_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_B1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_B1F),
        .landMonsInfo = &gArtisanCave_B1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ARTISAN_CAVE_1F),
        .mapNum = MAP_NUM(ARTISAN_CAVE_1F),
        .landMonsInfo = &gArtisanCave_1F_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave1_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave2_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave3_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave4_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave5_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave6_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave7_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave8_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(ALTERING_CAVE),
        .mapNum = MAP_NUM(ALTERING_CAVE),
        .landMonsInfo = &gAlteringCave9_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(METEOR_FALLS_STEVENS_CAVE),
        .mapNum = MAP_NUM(METEOR_FALLS_STEVENS_CAVE),
        .landMonsInfo = &gMeteorFalls_StevensCave_LandMonsInfo,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = MAP_GROUP(UNDEFINED),
        .mapNum = MAP_NUM(UNDEFINED),
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};

//Battle Pyramid-specific tables and headers start here.

const struct WildPokemon gBattlePyramidPlaceholders_1[] =
{
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_BULBASAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
};

const struct WildPokemonInfo gBattlePyramidPlaceholders_1Info = {4, gBattlePyramidPlaceholders_1};

const struct WildPokemon gBattlePyramidPlaceholders_2[] =
{
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_IVYSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMANDER},
};

const struct WildPokemonInfo gBattlePyramidPlaceholders_2Info = {4, gBattlePyramidPlaceholders_2};

const struct WildPokemon gBattlePyramidPlaceholders_3[] =
{
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_VENUSAUR},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
};

const struct WildPokemonInfo gBattlePyramidPlaceholders_3Info = {4, gBattlePyramidPlaceholders_3};

const struct WildPokemon gBattlePyramidPlaceholders_4[] =
{
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMANDER},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_SQUIRTLE},
};

const struct WildPokemonInfo gBattlePyramidPlaceholders_4Info = {4, gBattlePyramidPlaceholders_4};

const struct WildPokemon gBattlePyramidPlaceholders_5[] =
{
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_WARTORTLE},
};

const struct WildPokemonInfo gBattlePyramidPlaceholders_5Info = {4, gBattlePyramidPlaceholders_5};

const struct WildPokemon gBattlePyramidPlaceholders_6[] =
{
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
};

const struct WildPokemonInfo gBattlePyramidPlaceholders_6Info = {4, gBattlePyramidPlaceholders_6};

const struct WildPokemon gBattlePyramidPlaceholders_7[] =
{
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_WARTORTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_SQUIRTLE},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARIZARD},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
    {5, 5, SPECIES_CHARMELEON},
};

const struct WildPokemonInfo gBattlePyramidPlaceholders_7Info = {8, gBattlePyramidPlaceholders_7};

const struct WildPokemonHeader gBattlePyramidWildMonHeaders[] =
{
    {
        .mapGroup = 0,
        .mapNum = 1,
        .landMonsInfo = &gBattlePyramidPlaceholders_1Info,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 2,
        .landMonsInfo = &gBattlePyramidPlaceholders_2Info,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 3,
        .landMonsInfo = &gBattlePyramidPlaceholders_3Info,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 4,
        .landMonsInfo = &gBattlePyramidPlaceholders_4Info,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 5,
        .landMonsInfo = &gBattlePyramidPlaceholders_5Info,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 6,
        .landMonsInfo = &gBattlePyramidPlaceholders_6Info,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 7,
        .landMonsInfo = &gBattlePyramidPlaceholders_7Info,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 255,
        .mapNum = 255,
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};

//Battle Pike-specific tables and headers start here.

const struct WildPokemon gBattlePikeMons_1[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_DUSCLOPS},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

const struct WildPokemonInfo gBattlePikeMonsInfo_1 = {10, gBattlePikeMons_1};

const struct WildPokemon gBattlePikeMons_2[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_ELECTRODE},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

const struct WildPokemonInfo gBattlePikeMonsInfo_2 = {10, gBattlePikeMons_2};

const struct WildPokemon gBattlePikeMons_3[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_BRELOOM},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

const struct WildPokemonInfo gBattlePikeMonsInfo_3 = {10, gBattlePikeMons_3};

const struct WildPokemon gBattlePikeMons_4[] =
{
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_WOBBUFFET},
    {5, 5, SPECIES_SEVIPER},
    {5, 5, SPECIES_MILOTIC},
};

const struct WildPokemonInfo gBattlePikeMonsInfo_4 = {10, gBattlePikeMons_4};

const struct WildPokemonHeader gBattlePikeWildMonHeaders[] =
{
    {
        .mapGroup = 0,
        .mapNum = 1,
        .landMonsInfo = &gBattlePikeMonsInfo_1,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 2,
        .landMonsInfo = &gBattlePikeMonsInfo_2,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 3,
        .landMonsInfo = &gBattlePikeMonsInfo_3,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 0,
        .mapNum = 4,
        .landMonsInfo = &gBattlePikeMonsInfo_4,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
    {
        .mapGroup = 255,
        .mapNum = 255,
        .landMonsInfo = NULL,
        .waterMonsInfo = NULL,
        .rockSmashMonsInfo = NULL,
        .fishingMonsInfo = NULL,
    },
};

//Special Feebas-related data.

const struct WildPokemon gWildFeebasRoute119Data = {20, 25, SPECIES_FEEBAS};

const u16 gRoute119WaterTileData[] =
{
    0, 0x2D, 0,
    0x2E, 0x5B, 0x83,
    0x5C, 0x8B, 0x12A,
};

