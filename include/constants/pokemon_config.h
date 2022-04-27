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
#define P_SHEDINJA_BALL         GEN_8 // Since Gen 4, Shedinja requires a Poké Ball for its evolution. In Gen 3, Shedinja inherits Nincada's Ball.
#define P_LEGENDARY_PERFECT_IVS GEN_8 // Since Gen 6, Legendaries, Mythicals and Ultra Beasts found in the wild or given through gifts have at least 3 perfect IVs.
#define P_KADABRA_EVERSTONE     GEN_8 // Since Gen 4, Kadabra can evolve even when holding an Everstone.

#define P_ENABLE_DEBUG          TRUE  // Enables a debug menu for pokemon sprites and icons, accessed by pressing SELECT in the summary screen.

#ifndef ITEM_EXPANSION
//Item Definitions for gEvolutionTable

    //EVO_MEGA_EVOLUTION
    #define ITEM_VENUSAURITE         10001
    #define ITEM_CHARIZARDITE_X      10002
    #define ITEM_CHARIZARDITE_Y      10003
    #define ITEM_BLASTOISINITE       10004
    #define ITEM_BEEDRILLITE         10005
    #define ITEM_PIDGEOTITE          10006
    #define ITEM_ALAKAZITE           10007
    #define ITEM_SLOWBRONITE         10008
    #define ITEM_GENGARITE           10009
    #define ITEM_KANGASKHANITE       10010
    #define ITEM_PINSIRITE           10011
    #define ITEM_GYARADOSITE         10012
    #define ITEM_AERODACTYLITE       10013
    #define ITEM_MEWTWONITE_X        10014
    #define ITEM_MEWTWONITE_Y        10015
    #define ITEM_AMPHAROSITE         10016
    #define ITEM_STEELIXITE          10017
    #define ITEM_SCIZORITE           10018
    #define ITEM_HERACRONITE         10019
    #define ITEM_HOUNDOOMINITE       10020
    #define ITEM_TYRANITARITE        10021
    #define ITEM_SCEPTILITE          10022
    #define ITEM_BLAZIKENITE         10023
    #define ITEM_SWAMPERTITE         10024
    #define ITEM_SABLENITE           10025
    #define ITEM_SHARPEDONITE        10026
    #define ITEM_MANECTITE           10027
    #define ITEM_CAMERUPTITE         10028
    #define ITEM_GLALITITE           10029
    #define ITEM_MAWILITE            10030
    #define ITEM_MEDICHAMITE         10031
    #define ITEM_ALTARIANITE         10032
    #define ITEM_ABSOLITE            10033
    #define ITEM_BANETTITE           10034
    #define ITEM_AGGRONITE           10035
    #define ITEM_GARDEVOIRITE        10036
    #define ITEM_SALAMENCITE         10037
    #define ITEM_METAGROSSITE        10038
    #define ITEM_LATIASITE           10039
    #define ITEM_LATIOSITE           10040
    #define ITEM_LOPUNNITE           10041
    #define ITEM_GARCHOMPITE         10042
    #define ITEM_LUCARIONITE         10043
    #define ITEM_ABOMASITE           10044
    #define ITEM_GALLADITE           10045
    #define ITEM_AUDINITE            10046
    #define ITEM_DIANCITE            10047

    //EVO_TRADE_ITEM
    #define ITEM_PROTECTOR           10048
    #define ITEM_ELECTIRIZER         10049
    #define ITEM_MAGMARIZER          10050
    #define ITEM_DUBIOUS_DISC        10051
    #define ITEM_PRISM_SCALE         10052
    #define ITEM_REAPER_CLOTH        10053
    #define ITEM_SACHET              10054
    #define ITEM_WHIPPED_DREAM       10055

    //EVO_ITEM
    #define ITEM_ICE_STONE           10056
    #define ITEM_SHINY_STONE         10057
    #define ITEM_DUSK_STONE          10058
    #define ITEM_DAWN_STONE          10059
    #define ITEM_TART_APPLE          10060
    #define ITEM_SWEET_APPLE         10061
    #define ITEM_CRACKED_POT         10062
    #define ITEM_GALARICA_CUFF       10063
    #define ITEM_GALARICA_WREATH     10064
    #define ITEM_CHIPPED_POT         10065

    //EVO_ITEM_HOLD
    #define ITEM_RAZOR_FANG          10066
    #define ITEM_RAZOR_CLAW          10067
    #define ITEM_OVAL_STONE          10068

    //FORM_ITEM_HOLD
    #define ITEM_GRISEOUS_ORB        10069
    #define ITEM_DRACO_PLATE         10070
    #define ITEM_DREAD_PLATE         10071
    #define ITEM_EARTH_PLATE         10072
    #define ITEM_FIST_PLATE          10073
    #define ITEM_FLAME_PLATE         10074
    #define ITEM_ICICLE_PLATE        10075
    #define ITEM_INSECT_PLATE        10076
    #define ITEM_IRON_PLATE          10077
    #define ITEM_MEADOW_PLATE        10078
    #define ITEM_MIND_PLATE          10079
    #define ITEM_PIXIE_PLATE         10080
    #define ITEM_SKY_PLATE           10081
    #define ITEM_SPLASH_PLATE        10082
    #define ITEM_SPOOKY_PLATE        10083
    #define ITEM_STONE_PLATE         10084
    #define ITEM_TOXIC_PLATE         10085
    #define ITEM_ZAP_PLATE           10086
    #define ITEM_FIGHTINIUM_Z        10087
    #define ITEM_FLYINIUM_Z          10088
    #define ITEM_POISONIUM_Z         10089
    #define ITEM_GROUNDIUM_Z         10090
    #define ITEM_ROCKIUM_Z           10091
    #define ITEM_BUGINIUM_Z          10092
    #define ITEM_GHOSTIUM_Z          10093
    #define ITEM_STEELIUM_Z          10094
    #define ITEM_FIRIUM_Z            10095
    #define ITEM_WATERIUM_Z          10096
    #define ITEM_GRASSIUM_Z          10097
    #define ITEM_ELECTRIUM_Z         10098
    #define ITEM_PSYCHIUM_Z          10099
    #define ITEM_ICIUM_Z             10100
    #define ITEM_DRAGONIUM_Z         10101
    #define ITEM_DARKINIUM_Z         10102
    #define ITEM_FAIRIUM_Z           10103
    #define ITEM_DOUSE_DRIVE         10104
    #define ITEM_SHOCK_DRIVE         10105
    #define ITEM_BURN_DRIVE          10106
    #define ITEM_CHILL_DRIVE         10107
    #define ITEM_BUG_MEMORY          10108
    #define ITEM_DARK_MEMORY         10109
    #define ITEM_DRAGON_MEMORY       10110
    #define ITEM_ELECTRIC_MEMORY     10111
    #define ITEM_FAIRY_MEMORY        10112
    #define ITEM_FIGHTING_MEMORY     10113
    #define ITEM_FIRE_MEMORY         10114
    #define ITEM_FLYING_MEMORY       10115
    #define ITEM_GHOST_MEMORY        10116
    #define ITEM_GRASS_MEMORY        10117
    #define ITEM_GROUND_MEMORY       10118
    #define ITEM_ICE_MEMORY          10119
    #define ITEM_POISON_MEMORY       10120
    #define ITEM_PSYCHIC_MEMORY      10121
    #define ITEM_ROCK_MEMORY         10122
    #define ITEM_STEEL_MEMORY        10123
    #define ITEM_WATER_MEMORY        10124

    //FORM_ITEM_USE
    #define ITEM_GRACIDEA            10125
    // #define ITEM_REVEAL_GLASS        10126
    // #define ITEM_PRISON_BOTTLE       10127
    #define ITEM_RED_NECTAR          10128
    #define ITEM_YELLOW_NECTAR       10129
    #define ITEM_PINK_NECTAR         10130
    #define ITEM_PURPLE_NECTAR       10131
#endif // ITEM_EXPANSION

#ifndef BATTLE_ENGINE
    #define ABILITY_MULTITYPE        ABILITY_NONE
    #define ABILITY_RKS_SYSTEM       ABILITY_NONE
#endif // BATTLE_ENGINE

#endif // GUARD_CONSTANTS_POKEMON_CONFIG_H
