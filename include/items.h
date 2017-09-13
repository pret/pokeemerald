#ifndef GUARD_ITEMS_H
#define GUARD_ITEMS_H

enum
{
    ITEM_NONE,           // 0x000
    ITEM_MASTER_BALL,    // 0x001
    ITEM_ULTRA_BALL,     // 0x002
    ITEM_GREAT_BALL,     // 0x003
    ITEM_POKE_BALL,      // 0x004
    ITEM_SAFARI_BALL,    // 0x005
    ITEM_NET_BALL,       // 0x006
    ITEM_DIVE_BALL,      // 0x007
    ITEM_NEST_BALL,      // 0x008
    ITEM_REPEAT_BALL,    // 0x009
    ITEM_TIMER_BALL,     // 0x00a
    ITEM_LUXURY_BALL,    // 0x00b
    ITEM_PREMIER_BALL,   // 0x00c
    ITEM_POTION,         // 0x00d
    ITEM_ANTIDOTE,       // 0x00e
    ITEM_BURN_HEAL,      // 0x00f
    ITEM_ICE_HEAL,       // 0x010
    ITEM_AWAKENING,      // 0x011
    ITEM_PARALYZE_HEAL,  // 0x012
    ITEM_FULL_RESTORE,   // 0x013
    ITEM_MAX_POTION,     // 0x014
    ITEM_HYPER_POTION,   // 0x015
    ITEM_SUPER_POTION,   // 0x016
    ITEM_FULL_HEAL,      // 0x017
    ITEM_REVIVE,         // 0x018
    ITEM_MAX_REVIVE,     // 0x019
    ITEM_FRESH_WATER,    // 0x01a
    ITEM_SODA_POP,       // 0x01b
    ITEM_LEMONADE,       // 0x01c
    ITEM_MOOMOO_MILK,    // 0x01d
    ITEM_ENERGY_POWDER,  // 0x01e
    ITEM_ENERGY_ROOT,    // 0x01f
    ITEM_HEAL_POWDER,    // 0x020
    ITEM_REVIVAL_HERB,   // 0x021
    ITEM_ETHER,          // 0x022
    ITEM_MAX_ETHER,      // 0x023
    ITEM_ELIXIR,         // 0x024
    ITEM_MAX_ELIXIR,     // 0x025
    ITEM_LAVA_COOKIE,    // 0x026
    ITEM_BLUE_FLUTE,     // 0x027
    ITEM_YELLOW_FLUTE,   // 0x028
    ITEM_RED_FLUTE,      // 0x029
    ITEM_BLACK_FLUTE,    // 0x02a
    ITEM_WHITE_FLUTE,    // 0x02b
    ITEM_BERRY_JUICE,    // 0x02c
    ITEM_SACRED_ASH,     // 0x02d
    ITEM_SHOAL_SALT,     // 0x02e
    ITEM_SHOAL_SHELL,    // 0x02f
    ITEM_RED_SHARD,      // 0x030
    ITEM_BLUE_SHARD,     // 0x031
    ITEM_YELLOW_SHARD,   // 0x032
    ITEM_GREEN_SHARD,    // 0x033
    ITEM_034,
    ITEM_035,
    ITEM_036,
    ITEM_037,
    ITEM_038,
    ITEM_039,
    ITEM_03A,
    ITEM_03B,
    ITEM_03C,
    ITEM_03D,
    ITEM_03E,
    ITEM_HP_UP,          // 0x03f
    ITEM_PROTEIN,        // 0x040
    ITEM_IRON,           // 0x041
    ITEM_CARBOS,         // 0x042
    ITEM_CALCIUM,        // 0x043
    ITEM_RARE_CANDY,     // 0x044
    ITEM_PP_UP,          // 0x045
    ITEM_ZINC,           // 0x046
    ITEM_PP_MAX,         // 0x047
    ITEM_048,
    ITEM_GUARD_SPEC,     // 0x049
    ITEM_DIRE_HIT,       // 0x04a
    ITEM_X_ATTACK,       // 0x04b
    ITEM_X_DEFEND,       // 0x04c
    ITEM_X_SPEED,        // 0x04d
    ITEM_X_ACCURACY,     // 0x04e
    ITEM_X_SPECIAL,      // 0x04f
    ITEM_POKE_DOLL,      // 0x050
    ITEM_FLUFFY_TAIL,    // 0x051
    ITEM_052,
    ITEM_SUPER_REPEL,    // 0x053
    ITEM_MAX_REPEL,      // 0x054
    ITEM_ESCAPE_ROPE,    // 0x055
    ITEM_REPEL,          // 0x056
    ITEM_057,
    ITEM_058,
    ITEM_059,
    ITEM_05A,
    ITEM_05B,
    ITEM_05C,
    ITEM_SUN_STONE,      // 0x05d
    ITEM_MOON_STONE,     // 0x05e
    ITEM_FIRE_STONE,     // 0x05f
    ITEM_THUNDER_STONE,  // 0x060
    ITEM_WATER_STONE,    // 0x061
    ITEM_LEAF_STONE,     // 0x062
    ITEM_063,
    ITEM_064,
    ITEM_065,
    ITEM_066,
    ITEM_TINY_MUSHROOM,  // 0x067
    ITEM_BIG_MUSHROOM,   // 0x068
    ITEM_069,
    ITEM_PEARL,          // 0x06a
    ITEM_BIG_PEARL,      // 0x06b
    ITEM_STARDUST,       // 0x06c
    ITEM_STAR_PIECE,     // 0x06d
    ITEM_NUGGET,         // 0x06e
    ITEM_HEART_SCALE,    // 0x06f
    ITEM_070,
    ITEM_071,
    ITEM_072,
    ITEM_073,
    ITEM_074,
    ITEM_075,
    ITEM_076,
    ITEM_077,
    ITEM_078,
    ITEM_ORANGE_MAIL,    // 0x079
    ITEM_HARBOR_MAIL,    // 0x07a
    ITEM_GLITTER_MAIL,   // 0x07b
    ITEM_MECH_MAIL,      // 0x07c
    ITEM_WOOD_MAIL,      // 0x07d
    ITEM_WAVE_MAIL,      // 0x07e
    ITEM_BEAD_MAIL,      // 0x07f
    ITEM_SHADOW_MAIL,    // 0x080
    ITEM_TROPIC_MAIL,    // 0x081
    ITEM_DREAM_MAIL,     // 0x082
    ITEM_FAB_MAIL,       // 0x083
    ITEM_RETRO_MAIL,     // 0x084
    ITEM_CHERI_BERRY,    // 0x085
    ITEM_CHESTO_BERRY,   // 0x086
    ITEM_PECHA_BERRY,    // 0x087
    ITEM_RAWST_BERRY,    // 0x088
    ITEM_ASPEAR_BERRY,   // 0x089
    ITEM_LEPPA_BERRY,    // 0x08a
    ITEM_ORAN_BERRY,     // 0x08b
    ITEM_PERSIM_BERRY,   // 0x08c
    ITEM_LUM_BERRY,      // 0x08d
    ITEM_SITRUS_BERRY,   // 0x08e
    ITEM_FIGY_BERRY,     // 0x08f
    ITEM_WIKI_BERRY,     // 0x090
    ITEM_MAGO_BERRY,     // 0x091
    ITEM_AGUAV_BERRY,    // 0x092
    ITEM_IAPAPA_BERRY,   // 0x093
    ITEM_RAZZ_BERRY,     // 0x094
    ITEM_BLUK_BERRY,     // 0x095
    ITEM_NANAB_BERRY,    // 0x096
    ITEM_WEPEAR_BERRY,   // 0x097
    ITEM_PINAP_BERRY,    // 0x098
    ITEM_POMEG_BERRY,    // 0x099
    ITEM_KELPSY_BERRY,   // 0x09a
    ITEM_QUALOT_BERRY,   // 0x09b
    ITEM_HONDEW_BERRY,   // 0x09c
    ITEM_GREPA_BERRY,    // 0x09d
    ITEM_TAMATO_BERRY,   // 0x09e
    ITEM_CORNN_BERRY,    // 0x09f
    ITEM_MAGOST_BERRY,   // 0x0a0
    ITEM_RABUTA_BERRY,   // 0x0a1
    ITEM_NOMEL_BERRY,    // 0x0a2
    ITEM_SPELON_BERRY,   // 0x0a3
    ITEM_PAMTRE_BERRY,   // 0x0a4
    ITEM_WATMEL_BERRY,   // 0x0a5
    ITEM_DURIN_BERRY,    // 0x0a6
    ITEM_BELUE_BERRY,    // 0x0a7
    ITEM_LIECHI_BERRY,   // 0x0a8
    ITEM_GANLON_BERRY,   // 0x0a9
    ITEM_SALAC_BERRY,    // 0x0aa
    ITEM_PETAYA_BERRY,   // 0x0ab
    ITEM_APICOT_BERRY,   // 0x0ac
    ITEM_LANSAT_BERRY,   // 0x0ad
    ITEM_STARF_BERRY,    // 0x0ae
    ITEM_ENIGMA_BERRY,   // 0x0af
    ITEM_0B0,
    ITEM_0B1,
    ITEM_0B2,
    ITEM_BRIGHT_POWDER,  // 0x0b3
    ITEM_WHITE_HERB,     // 0x0b4
    ITEM_MACHO_BRACE,    // 0x0b5
    ITEM_EXP_SHARE,      // 0x0b6
    ITEM_QUICK_CLAW,     // 0x0b7
    ITEM_SOOTHE_BELL,    // 0x0b8
    ITEM_MENTAL_HERB,    // 0x0b9
    ITEM_CHOICE_BAND,    // 0x0ba
    ITEM_KINGS_ROCK,     // 0x0bb
    ITEM_SILVER_POWDER,  // 0x0bc
    ITEM_AMULET_COIN,    // 0x0bd
    ITEM_CLEANSE_TAG,    // 0x0be
    ITEM_SOUL_DEW,       // 0x0bf
    ITEM_DEEP_SEA_TOOTH, // 0x0c0
    ITEM_DEEP_SEA_SCALE, // 0x0c1
    ITEM_SMOKE_BALL,     // 0x0c2
    ITEM_EVERSTONE,      // 0x0c3
    ITEM_FOCUS_BAND,     // 0x0c4
    ITEM_LUCKY_EGG,      // 0x0c5
    ITEM_SCOPE_LENS,     // 0x0c6
    ITEM_METAL_COAT,     // 0x0c7
    ITEM_LEFTOVERS,      // 0x0c8
    ITEM_DRAGON_SCALE,   // 0x0c9
    ITEM_LIGHT_BALL,     // 0x0ca
    ITEM_SOFT_SAND,      // 0x0cb
    ITEM_HARD_STONE,     // 0x0cc
    ITEM_MIRACLE_SEED,   // 0x0cd
    ITEM_BLACK_GLASSES,  // 0x0ce
    ITEM_BLACK_BELT,     // 0x0cf
    ITEM_MAGNET,         // 0x0d0
    ITEM_MYSTIC_WATER,   // 0x0d1
    ITEM_SHARP_BEAK,     // 0x0d2
    ITEM_POISON_BARB,    // 0x0d3
    ITEM_NEVER_MELT_ICE, // 0x0d4
    ITEM_SPELL_TAG,      // 0x0d5
    ITEM_TWISTED_SPOON,  // 0x0d6
    ITEM_CHARCOAL,       // 0x0d7
    ITEM_DRAGON_FANG,    // 0x0d8
    ITEM_SILK_SCARF,     // 0x0d9
    ITEM_UP_GRADE,       // 0x0da
    ITEM_SHELL_BELL,     // 0x0db
    ITEM_SEA_INCENSE,    // 0x0dc
    ITEM_LAX_INCENSE,    // 0x0dd
    ITEM_LUCKY_PUNCH,    // 0x0de
    ITEM_METAL_POWDER,   // 0x0df
    ITEM_THICK_CLUB,     // 0x0e0
    ITEM_STICK,          // 0x0e1
    ITEM_0E2,
    ITEM_0E3,
    ITEM_0E4,
    ITEM_0E5,
    ITEM_0E6,
    ITEM_0E7,
    ITEM_0E8,
    ITEM_0E9,
    ITEM_0EA,
    ITEM_0EB,
    ITEM_0EC,
    ITEM_0ED,
    ITEM_0EE,
    ITEM_0EF,
    ITEM_0F0,
    ITEM_0F1,
    ITEM_0F2,
    ITEM_0F3,
    ITEM_0F4,
    ITEM_0F5,
    ITEM_0F6,
    ITEM_0F7,
    ITEM_0F8,
    ITEM_0F9,
    ITEM_0FA,
    ITEM_0FB,
    ITEM_0FC,
    ITEM_0FD,
    ITEM_RED_SCARF,      // 0x0fe
    ITEM_BLUE_SCARF,     // 0x0ff
    ITEM_PINK_SCARF,     // 0x100
    ITEM_GREEN_SCARF,    // 0x101
    ITEM_YELLOW_SCARF,   // 0x102
    ITEM_MACH_BIKE,      // 0x103
    ITEM_COIN_CASE,      // 0x104
    ITEM_ITEMFINDER,     // 0x105
    ITEM_OLD_ROD,        // 0x106
    ITEM_GOOD_ROD,       // 0x107
    ITEM_SUPER_ROD,      // 0x108
    ITEM_SS_TICKET,      // 0x109
    ITEM_CONTEST_PASS,   // 0x10a
    ITEM_10B,
    ITEM_WAILMER_PAIL,   // 0x10c
    ITEM_DEVON_GOODS,    // 0x10d
    ITEM_SOOT_SACK,      // 0x10e
    ITEM_BASEMENT_KEY,   // 0x10f
    ITEM_ACRO_BIKE,      // 0x110
    ITEM_POKEBLOCK_CASE, // 0x111
    ITEM_LETTER,         // 0x112
    ITEM_EON_TICKET,     // 0x113
    ITEM_RED_ORB,        // 0x114
    ITEM_BLUE_ORB,       // 0x115
    ITEM_SCANNER,        // 0x116
    ITEM_GO_GOGGLES,     // 0x117
    ITEM_METEORITE,      // 0x118
    ITEM_ROOM_1_KEY,     // 0x119
    ITEM_ROOM_2_KEY,     // 0x11a
    ITEM_ROOM_4_KEY,     // 0x11b
    ITEM_ROOM_6_KEY,     // 0x11c
    ITEM_STORAGE_KEY,    // 0x11d
    ITEM_ROOT_FOSSIL,    // 0x11e
    ITEM_CLAW_FOSSIL,    // 0x11f
    ITEM_DEVON_SCOPE,    // 0x120
    ITEM_TM01,           // 0x121
    ITEM_TM02,           // 0x122
    ITEM_TM03,           // 0x123
    ITEM_TM04,           // 0x124
    ITEM_TM05,           // 0x125
    ITEM_TM06,           // 0x126
    ITEM_TM07,           // 0x127
    ITEM_TM08,           // 0x128
    ITEM_TM09,           // 0x129
    ITEM_TM10,           // 0x12a
    ITEM_TM11,           // 0x12b
    ITEM_TM12,           // 0x12c
    ITEM_TM13,           // 0x12d
    ITEM_TM14,           // 0x12e
    ITEM_TM15,           // 0x12f
    ITEM_TM16,           // 0x130
    ITEM_TM17,           // 0x131
    ITEM_TM18,           // 0x132
    ITEM_TM19,           // 0x133
    ITEM_TM20,           // 0x134
    ITEM_TM21,           // 0x135
    ITEM_TM22,           // 0x136
    ITEM_TM23,           // 0x137
    ITEM_TM24,           // 0x138
    ITEM_TM25,           // 0x139
    ITEM_TM26,           // 0x13a
    ITEM_TM27,           // 0x13b
    ITEM_TM28,           // 0x13c
    ITEM_TM29,           // 0x13d
    ITEM_TM30,           // 0x13e
    ITEM_TM31,           // 0x13f
    ITEM_TM32,           // 0x140
    ITEM_TM33,           // 0x141
    ITEM_TM34,           // 0x142
    ITEM_TM35,           // 0x143
    ITEM_TM36,           // 0x144
    ITEM_TM37,           // 0x145
    ITEM_TM38,           // 0x146
    ITEM_TM39,           // 0x147
    ITEM_TM40,           // 0x148
    ITEM_TM41,           // 0x149
    ITEM_TM42,           // 0x14a
    ITEM_TM43,           // 0x14b
    ITEM_TM44,           // 0x14c
    ITEM_TM45,           // 0x14d
    ITEM_TM46,           // 0x14e
    ITEM_TM47,           // 0x14f
    ITEM_TM48,           // 0x150
    ITEM_TM49,           // 0x151
    ITEM_TM50,           // 0x152
    ITEM_HM01,           // 0x153
    ITEM_HM02,           // 0x154
    ITEM_HM03,           // 0x155
    ITEM_HM04,           // 0x156
    ITEM_HM05,           // 0x157
    ITEM_HM06,           // 0x158
    ITEM_HM07,           // 0x159
    ITEM_HM08,           // 0x15a
    ITEM_15B,
    ITEM_15C,

    // FireRed/LeafGreen
    ITEM_OAKS_PARCEL,    // 0x15d
    ITEM_POKE_FLUTE,     // 0x15e
    ITEM_SECRET_KEY,     // 0x15f
    ITEM_BIKE_VOUCHER,   // 0x160
    ITEM_GOLD_TEETH,     // 0x161
    ITEM_OLD_AMBER,      // 0x162
    ITEM_CARD_KEY,       // 0x163
    ITEM_LIFT_KEY,       // 0x164
    ITEM_HELIX_FOSSIL,   // 0x165
    ITEM_DOME_FOSSIL,    // 0x166
    ITEM_SILPH_SCOPE,    // 0x167
    ITEM_BICYCLE,        // 0x168
    ITEM_TOWN_MAP,       // 0x169
    ITEM_VS_SEEKER,      // 0x16a
    ITEM_FAME_CHECKER,   // 0x16b
    ITEM_TM_CASE,        // 0x16c
    ITEM_BERRY_POUCH,    // 0x16d
    ITEM_TEACHY_TV,      // 0x16e
    ITEM_TRI_PASS,       // 0x16f
    ITEM_RAINBOW_PASS,   // 0x170
    ITEM_TEA,            // 0x171
    ITEM_MYSTIC_TICKET,  // 0x172
    ITEM_AURORA_TICKET,  // 0x173
    ITEM_POWDER_JAR,     // 0x174
    ITEM_RUBY,           // 0x175
    ITEM_SAPPHIRE,       // 0x176

    // Emerald
    ITEM_MAGMA_EMBLEM,   // 0x177
    ITEM_OLD_SEA_MAP,    // 0x178
};

#endif // GUARD_ITEMS_H
