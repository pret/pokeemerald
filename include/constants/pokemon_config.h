#ifndef GUARD_CONSTANTS_POKEMON_CONFIG_H
#define GUARD_CONSTANTS_POKEMON_CONFIG_H

#include "constants/expansion_branches.h"

#ifndef GEN_3
#define GEN_3 0
#define GEN_4 1
#define GEN_5 2
#define GEN_6 3
#define GEN_7 4
#define GEN_8 5
#endif

#define P_UPDATED_TYPES         GEN_8 // In Gen6+, several Pokémon were changed to be partially or fully Fairy type.
#define P_UPDATED_STATS         GEN_8 // Since Gen 6, Pokémon stats are updated with each passing generation.
#define P_UPDATED_ABILITIES     GEN_8 // Since Gen 6, certain Pokémon have their abilities changed. Requires BATTLE_ENGINE for Gen4+ abilities.
#define P_UPDATED_EGG_GROUPS    GEN_8 // Since Gen 8, certain Pokémon have gained new egg groups.

#ifndef ITEM_EXPANSION
//Item Definitions for gEvolutionTable

//EVO_MEGA_EVOLUTION
#define ITEM_VENUSAURITE         ITEM_NONE
#define ITEM_CHARIZARDITE_X      ITEM_NONE
#define ITEM_CHARIZARDITE_Y      ITEM_NONE
#define ITEM_BLASTOISINITE       ITEM_NONE
#define ITEM_BEEDRILLITE         ITEM_NONE
#define ITEM_PIDGEOTITE          ITEM_NONE
#define ITEM_ALAKAZITE           ITEM_NONE
#define ITEM_SLOWBRONITE         ITEM_NONE
#define ITEM_GENGARITE           ITEM_NONE
#define ITEM_KANGASKHANITE       ITEM_NONE
#define ITEM_PINSIRITE           ITEM_NONE
#define ITEM_GYARADOSITE         ITEM_NONE
#define ITEM_AERODACTYLITE       ITEM_NONE
#define ITEM_MEWTWONITE_X        ITEM_NONE
#define ITEM_MEWTWONITE_Y        ITEM_NONE
#define ITEM_AMPHAROSITE         ITEM_NONE
#define ITEM_STEELIXITE          ITEM_NONE
#define ITEM_SCIZORITE           ITEM_NONE
#define ITEM_HERACRONITE         ITEM_NONE
#define ITEM_HOUNDOOMINITE       ITEM_NONE
#define ITEM_TYRANITARITE        ITEM_NONE
#define ITEM_SCEPTILITE          ITEM_NONE
#define ITEM_BLAZIKENITE         ITEM_NONE
#define ITEM_SWAMPERTITE         ITEM_NONE
#define ITEM_SABLENITE           ITEM_NONE
#define ITEM_SHARPEDONITE        ITEM_NONE
#define ITEM_MANECTITE           ITEM_NONE
#define ITEM_CAMERUPTITE         ITEM_NONE
#define ITEM_GLALITITE           ITEM_NONE
#define ITEM_MAWILITE            ITEM_NONE
#define ITEM_MEDICHAMITE         ITEM_NONE
#define ITEM_ALTARIANITE         ITEM_NONE
#define ITEM_ABSOLITE            ITEM_NONE
#define ITEM_BANETTITE           ITEM_NONE
#define ITEM_AGGRONITE           ITEM_NONE
#define ITEM_GARDEVOIRITE        ITEM_NONE
#define ITEM_SALAMENCITE         ITEM_NONE
#define ITEM_METAGROSSITE        ITEM_NONE
#define ITEM_LATIASITE           ITEM_NONE
#define ITEM_LATIOSITE           ITEM_NONE
#define ITEM_LOPUNNITE           ITEM_NONE
#define ITEM_GARCHOMPITE         ITEM_NONE
#define ITEM_LUCARIONITE         ITEM_NONE
#define ITEM_ABOMASITE           ITEM_NONE
#define ITEM_GALLADITE           ITEM_NONE
#define ITEM_AUDINITE            ITEM_NONE
#define ITEM_DIANCITE            ITEM_NONE

//EVO_TRADE_ITEM
#define ITEM_PROTECTOR           ITEM_NONE
#define ITEM_ELECTIRIZER         ITEM_NONE
#define ITEM_MAGMARIZER          ITEM_NONE
#define ITEM_DUBIOUS_DISC        ITEM_NONE
#define ITEM_PRISM_SCALE         ITEM_NONE
#define ITEM_REAPER_CLOTH        ITEM_NONE
#define ITEM_SACHET              ITEM_NONE
#define ITEM_WHIPPED_DREAM       ITEM_NONE

//EVO_ITEM
#define ITEM_ICE_STONE           ITEM_NONE
#define ITEM_SHINY_STONE         ITEM_NONE
#define ITEM_DUSK_STONE          ITEM_NONE
#define ITEM_DAWN_STONE          ITEM_NONE
#define ITEM_TART_APPLE          ITEM_NONE
#define ITEM_SWEET_APPLE         ITEM_NONE
#define ITEM_CRACKED_POT         ITEM_NONE
#define ITEM_GALARICA_CUFF       ITEM_NONE
#define ITEM_GALARICA_WREATH     ITEM_NONE
#define ITEM_CHIPPED_POT         ITEM_NONE

//EVO_ITEM_HOLD
#define ITEM_RAZOR_FANG          ITEM_NONE
#define ITEM_RAZOR_CLAW          ITEM_NONE
#define ITEM_OVAL_STONE          ITEM_NONE
#endif

#endif // GUARD_CONSTANTS_POKEMON_CONFIG_H
