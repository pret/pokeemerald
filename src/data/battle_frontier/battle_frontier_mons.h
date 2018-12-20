const struct FacilityMon gBattleFrontierMons[] =
{
    [0] = {
        .species = SPECIES_SUNKERN,
        .moves = {MOVE_MEGA_DRAIN, MOVE_HELPING_HAND, MOVE_SUNNY_DAY, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [1] = {
        .species = SPECIES_AZURILL,
        .moves = {MOVE_WATER_PULSE, MOVE_ATTRACT, MOVE_SING, MOVE_CHARM},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RASH
    },
    [2] = {
        .species = SPECIES_CATERPIE,
        .moves = {MOVE_TACKLE, MOVE_STRING_SHOT, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [3] = {
        .species = SPECIES_WEEDLE,
        .moves = {MOVE_POISON_STING, MOVE_STRING_SHOT, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [4] = {
        .species = SPECIES_WURMPLE,
        .moves = {MOVE_TACKLE, MOVE_STRING_SHOT, MOVE_POISON_STING, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [5] = {
        .species = SPECIES_RALTS,
        .moves = {MOVE_CONFUSION, MOVE_IMPRISON, MOVE_DOUBLE_TEAM, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [6] = {
        .species = SPECIES_MAGIKARP,
        .moves = {MOVE_FLAIL, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [7] = {
        .species = SPECIES_FEEBAS,
        .moves = {MOVE_FLAIL, MOVE_MIRROR_COAT, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [8] = {
        .species = SPECIES_METAPOD,
        .moves = {MOVE_HARDEN, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BASHFUL
    },
    [9] = {
        .species = SPECIES_KAKUNA,
        .moves = {MOVE_HARDEN, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BASHFUL
    },
    [10] = {
        .species = SPECIES_PICHU,
        .moves = {MOVE_SWEET_KISS, MOVE_THUNDER_WAVE, MOVE_ATTRACT, MOVE_SHOCK_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RASH
    },
    [11] = {
        .species = SPECIES_SILCOON,
        .moves = {MOVE_HARDEN, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BASHFUL
    },
    [12] = {
        .species = SPECIES_CASCOON,
        .moves = {MOVE_HARDEN, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BASHFUL
    },
    [13] = {
        .species = SPECIES_IGGLYBUFF,
        .moves = {MOVE_SWEET_KISS, MOVE_SING, MOVE_ATTRACT, MOVE_SEISMIC_TOSS},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [14] = {
        .species = SPECIES_WOOPER,
        .moves = {MOVE_YAWN, MOVE_DIG, MOVE_WATER_PULSE, MOVE_RAIN_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [15] = {
        .species = SPECIES_TYROGUE,
        .moves = {MOVE_MACH_PUNCH, MOVE_PROTECT, MOVE_DOUBLE_TEAM, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [16] = {
        .species = SPECIES_SENTRET,
        .moves = {MOVE_QUICK_ATTACK, MOVE_FOLLOW_ME, MOVE_HELPING_HAND, MOVE_ASSIST},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [17] = {
        .species = SPECIES_CLEFFA,
        .moves = {MOVE_SWEET_KISS, MOVE_SING, MOVE_ATTRACT, MOVE_METRONOME},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SERIOUS
    },
    [18] = {
        .species = SPECIES_SEEDOT,
        .moves = {MOVE_BULLET_SEED, MOVE_BIDE, MOVE_DEFENSE_CURL, MOVE_ROLLOUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [19] = {
        .species = SPECIES_LOTAD,
        .moves = {MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_SUNNY_DAY, MOVE_MEGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [20] = {
        .species = SPECIES_POOCHYENA,
        .moves = {MOVE_CRUNCH, MOVE_SWAGGER, MOVE_ROAR, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [21] = {
        .species = SPECIES_SHEDINJA,
        .moves = {MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY, MOVE_SILVER_WIND, MOVE_GRUDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_NAIVE
    },
    [22] = {
        .species = SPECIES_MAKUHITA,
        .moves = {MOVE_FAKE_OUT, MOVE_SEISMIC_TOSS, MOVE_DETECT, MOVE_WHIRLWIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [23] = {
        .species = SPECIES_WHISMUR,
        .moves = {MOVE_UPROAR, MOVE_SWAGGER, MOVE_BODY_SLAM, MOVE_SMELLING_SALT},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [24] = {
        .species = SPECIES_ZIGZAGOON,
        .moves = {MOVE_HEADBUTT, MOVE_PIN_MISSILE, MOVE_SWIFT, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID
    },
    [25] = {
        .species = SPECIES_ZUBAT,
        .moves = {MOVE_POISON_FANG, MOVE_WHIRLWIND, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [26] = {
        .species = SPECIES_TOGEPI,
        .moves = {MOVE_RETURN, MOVE_YAWN, MOVE_WISH, MOVE_SWEET_KISS},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [27] = {
        .species = SPECIES_SPINARAK,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_NIGHT_SHADE, MOVE_SPIDER_WEB, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [28] = {
        .species = SPECIES_MARILL,
        .moves = {MOVE_WATER_PULSE, MOVE_RAIN_DANCE, MOVE_LIGHT_SCREEN, MOVE_RETURN},
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE
    },
    [29] = {
        .species = SPECIES_HOPPIP,
        .moves = {MOVE_MEGA_DRAIN, MOVE_LEECH_SEED, MOVE_SLEEP_POWDER, MOVE_STUN_SPORE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_LAX
    },
    [30] = {
        .species = SPECIES_SLUGMA,
        .moves = {MOVE_EMBER, MOVE_ROCK_SLIDE, MOVE_YAWN, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [31] = {
        .species = SPECIES_SWINUB,
        .moves = {MOVE_ICY_WIND, MOVE_DIG, MOVE_ROCK_TOMB, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_GENTLE
    },
    [32] = {
        .species = SPECIES_SMEARGLE,
        .moves = {MOVE_EXTREME_SPEED, MOVE_FAKE_OUT, MOVE_QUICK_ATTACK, MOVE_MACH_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [33] = {
        .species = SPECIES_PIDGEY,
        .moves = {MOVE_GUST, MOVE_SAND_ATTACK, MOVE_WHIRLWIND, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHARP_BEAK,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [34] = {
        .species = SPECIES_RATTATA,
        .moves = {MOVE_HYPER_FANG, MOVE_PURSUIT, MOVE_QUICK_ATTACK, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [35] = {
        .species = SPECIES_WYNAUT,
        .moves = {MOVE_ENCORE, MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_CHARM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_JOLLY
    },
    [36] = {
        .species = SPECIES_SKITTY,
        .moves = {MOVE_SING, MOVE_ATTRACT, MOVE_CHARM, MOVE_DOUBLE_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [37] = {
        .species = SPECIES_SPEAROW,
        .moves = {MOVE_FURY_ATTACK, MOVE_PURSUIT, MOVE_MIRROR_MOVE, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [38] = {
        .species = SPECIES_HOOTHOOT,
        .moves = {MOVE_CONFUSION, MOVE_HYPNOSIS, MOVE_SUPERSONIC, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [39] = {
        .species = SPECIES_DIGLETT,
        .moves = {MOVE_MAGNITUDE, MOVE_SLASH, MOVE_ROCK_TOMB, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAIVE
    },
    [40] = {
        .species = SPECIES_LEDYBA,
        .moves = {MOVE_PSYBEAM, MOVE_AGILITY, MOVE_BATON_PASS, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BASHFUL
    },
    [41] = {
        .species = SPECIES_NINCADA,
        .moves = {MOVE_MUD_SLAP, MOVE_DIG, MOVE_TOXIC, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [42] = {
        .species = SPECIES_SURSKIT,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_RAIN_DANCE, MOVE_SWEET_SCENT, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [43] = {
        .species = SPECIES_JIGGLYPUFF,
        .moves = {MOVE_SING, MOVE_WISH, MOVE_MIMIC, MOVE_DOUBLE_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [44] = {
        .species = SPECIES_TAILLOW,
        .moves = {MOVE_FLY, MOVE_QUICK_ATTACK, MOVE_ENDEAVOR, MOVE_FOCUS_ENERGY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE
    },
    [45] = {
        .species = SPECIES_WINGULL,
        .moves = {MOVE_WATER_PULSE, MOVE_FLY, MOVE_QUICK_ATTACK, MOVE_STEEL_WING},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [46] = {
        .species = SPECIES_NIDORAN_M,
        .moves = {MOVE_DOUBLE_KICK, MOVE_POISON_STING, MOVE_DISABLE, MOVE_HELPING_HAND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [47] = {
        .species = SPECIES_NIDORAN_F,
        .moves = {MOVE_CRUNCH, MOVE_DOUBLE_KICK, MOVE_FLATTER, MOVE_HELPING_HAND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [48] = {
        .species = SPECIES_KIRLIA,
        .moves = {MOVE_CONFUSION, MOVE_WILL_O_WISP, MOVE_FUTURE_SIGHT, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [49] = {
        .species = SPECIES_MAREEP,
        .moves = {MOVE_SHOCK_WAVE, MOVE_FLASH, MOVE_REFLECT, MOVE_COTTON_SPORE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [50] = {
        .species = SPECIES_MEDITITE,
        .moves = {MOVE_HI_JUMP_KICK, MOVE_MEDITATE, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_MENTAL_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [51] = {
        .species = SPECIES_SLAKOTH,
        .moves = {MOVE_YAWN, MOVE_SCRATCH, MOVE_ENCORE, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [52] = {
        .species = SPECIES_PARAS,
        .moves = {MOVE_SPORE, MOVE_LEECH_LIFE, MOVE_SLASH, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [53] = {
        .species = SPECIES_EKANS,
        .moves = {MOVE_ACID, MOVE_DIG, MOVE_SCREECH, MOVE_TORMENT},
        .itemTableId = BATTLE_FRONTIER_ITEM_POISON_BARB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [54] = {
        .species = SPECIES_DITTO,
        .moves = {MOVE_TRANSFORM, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_METAL_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [55] = {
        .species = SPECIES_BARBOACH,
        .moves = {MOVE_MAGNITUDE, MOVE_WATER_PULSE, MOVE_SPARK, MOVE_FUTURE_SIGHT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BASHFUL
    },
    [56] = {
        .species = SPECIES_MEOWTH,
        .moves = {MOVE_SLASH, MOVE_BITE, MOVE_SCREECH, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [57] = {
        .species = SPECIES_PINECO,
        .moves = {MOVE_SELF_DESTRUCT, MOVE_TAKE_DOWN, MOVE_REFLECT, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [58] = {
        .species = SPECIES_TRAPINCH,
        .moves = {MOVE_TOXIC, MOVE_DIG, MOVE_SANDSTORM, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SERIOUS
    },
    [59] = {
        .species = SPECIES_SPHEAL,
        .moves = {MOVE_ICE_BALL, MOVE_WATER_PULSE, MOVE_HAIL, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [60] = {
        .species = SPECIES_HORSEA,
        .moves = {MOVE_WATER_GUN, MOVE_AGILITY, MOVE_ICY_WIND, MOVE_TWISTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [61] = {
        .species = SPECIES_SHROOMISH,
        .moves = {MOVE_SPORE, MOVE_BULLET_SEED, MOVE_LEECH_SEED, MOVE_HEADBUTT},
        .itemTableId = BATTLE_FRONTIER_ITEM_MIRACLE_SEED,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [62] = {
        .species = SPECIES_SHUPPET,
        .moves = {MOVE_WILL_O_WISP, MOVE_NIGHT_SHADE, MOVE_GRUDGE, MOVE_KNOCK_OFF},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RASH
    },
    [63] = {
        .species = SPECIES_DUSKULL,
        .moves = {MOVE_SKILL_SWAP, MOVE_NIGHT_SHADE, MOVE_DISABLE, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [64] = {
        .species = SPECIES_ELECTRIKE,
        .moves = {MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_ROAR, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [65] = {
        .species = SPECIES_VULPIX,
        .moves = {MOVE_WILL_O_WISP, MOVE_CONFUSE_RAY, MOVE_FIRE_SPIN, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [66] = {
        .species = SPECIES_PIKACHU,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_THUNDER_WAVE, MOVE_DOUBLE_TEAM, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIGHT_BALL,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [67] = {
        .species = SPECIES_SANDSHREW,
        .moves = {MOVE_DIG, MOVE_ROCK_TOMB, MOVE_SANDSTORM, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [68] = {
        .species = SPECIES_POLIWAG,
        .moves = {MOVE_HYPNOSIS, MOVE_ICY_WIND, MOVE_WATER_GUN, MOVE_RAIN_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [69] = {
        .species = SPECIES_BELLSPROUT,
        .moves = {MOVE_RAZOR_LEAF, MOVE_ACID, MOVE_STUN_SPORE, MOVE_WRAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_LAX
    },
    [70] = {
        .species = SPECIES_GEODUDE,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_BLAST, MOVE_STRENGTH, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE
    },
    [71] = {
        .species = SPECIES_DRATINI,
        .moves = {MOVE_OUTRAGE, MOVE_THUNDER_WAVE, MOVE_SUPERSONIC, MOVE_WATER_PULSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [72] = {
        .species = SPECIES_SNUBBULL,
        .moves = {MOVE_BITE, MOVE_CHARM, MOVE_SWAGGER, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [73] = {
        .species = SPECIES_REMORAID,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_AURORA_BEAM, MOVE_PSYBEAM, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [74] = {
        .species = SPECIES_LARVITAR,
        .moves = {MOVE_THRASH, MOVE_ROCK_SLIDE, MOVE_DIG, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [75] = {
        .species = SPECIES_BALTOY,
        .moves = {MOVE_PSYBEAM, MOVE_ANCIENT_POWER, MOVE_LIGHT_SCREEN, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY
    },
    [76] = {
        .species = SPECIES_SNORUNT,
        .moves = {MOVE_ICY_WIND, MOVE_HEADBUTT, MOVE_LEER, MOVE_BITE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE
    },
    [77] = {
        .species = SPECIES_BAGON,
        .moves = {MOVE_DRAGON_BREATH, MOVE_HEADBUTT, MOVE_BRICK_BREAK, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [78] = {
        .species = SPECIES_BELDUM,
        .moves = {MOVE_TAKE_DOWN, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [79] = {
        .species = SPECIES_GULPIN,
        .moves = {MOVE_TOXIC, MOVE_YAWN, MOVE_PAIN_SPLIT, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SERIOUS
    },
    [80] = {
        .species = SPECIES_VENONAT,
        .moves = {MOVE_PSYBEAM, MOVE_SUPERSONIC, MOVE_STUN_SPORE, MOVE_SKILL_SWAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [81] = {
        .species = SPECIES_MANKEY,
        .moves = {MOVE_KARATE_CHOP, MOVE_LOW_KICK, MOVE_SCREECH, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [82] = {
        .species = SPECIES_MACHOP,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_REVENGE, MOVE_ROCK_TOMB, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [83] = {
        .species = SPECIES_SHELLDER,
        .moves = {MOVE_ICICLE_SPEAR, MOVE_SUPERSONIC, MOVE_CLAMP, MOVE_WITHDRAW},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [84] = {
        .species = SPECIES_SMOOCHUM,
        .moves = {MOVE_SWEET_KISS, MOVE_SING, MOVE_MUD_SLAP, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [85] = {
        .species = SPECIES_NUMEL,
        .moves = {MOVE_EMBER, MOVE_MAGNITUDE, MOVE_ROCK_TOMB, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [86] = {
        .species = SPECIES_CARVANHA,
        .moves = {MOVE_BITE, MOVE_SCREECH, MOVE_SCARY_FACE, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [87] = {
        .species = SPECIES_CORPHISH,
        .moves = {MOVE_CRABHAMMER, MOVE_WATER_PULSE, MOVE_MUD_SLAP, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE
    },
    [88] = {
        .species = SPECIES_CHARMANDER,
        .moves = {MOVE_FIRE_SPIN, MOVE_METAL_CLAW, MOVE_SMOKESCREEN, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [89] = {
        .species = SPECIES_CYNDAQUIL,
        .moves = {MOVE_EMBER, MOVE_SWIFT, MOVE_QUICK_ATTACK, MOVE_SMOKESCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [90] = {
        .species = SPECIES_ABRA,
        .moves = {MOVE_MIMIC, MOVE_METRONOME, MOVE_FLASH, MOVE_SEISMIC_TOSS},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [91] = {
        .species = SPECIES_DODUO,
        .moves = {MOVE_FURY_ATTACK, MOVE_UPROAR, MOVE_MUD_SLAP, MOVE_FAINT_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [92] = {
        .species = SPECIES_GASTLY,
        .moves = {MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_NIGHT_SHADE, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [93] = {
        .species = SPECIES_SWABLU,
        .moves = {MOVE_TAKE_DOWN, MOVE_DREAM_EATER, MOVE_SING, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_MENTAL_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [94] = {
        .species = SPECIES_TREECKO,
        .moves = {MOVE_BULLET_SEED, MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_LONELY
    },
    [95] = {
        .species = SPECIES_TORCHIC,
        .moves = {MOVE_FIRE_SPIN, MOVE_QUICK_ATTACK, MOVE_SAND_ATTACK, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [96] = {
        .species = SPECIES_MUDKIP,
        .moves = {MOVE_WHIRLPOOL, MOVE_ENDEAVOR, MOVE_MUD_SPORT, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [97] = {
        .species = SPECIES_SQUIRTLE,
        .moves = {MOVE_WATER_PULSE, MOVE_BITE, MOVE_WITHDRAW, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [98] = {
        .species = SPECIES_TOTODILE,
        .moves = {MOVE_SLASH, MOVE_WATER_PULSE, MOVE_SCREECH, MOVE_ICY_WIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [99] = {
        .species = SPECIES_SLOWPOKE,
        .moves = {MOVE_CONFUSION, MOVE_DISABLE, MOVE_WATER_PULSE, MOVE_YAWN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE
    },
    [100] = {
        .species = SPECIES_BULBASAUR,
        .moves = {MOVE_RAZOR_LEAF, MOVE_SWEET_SCENT, MOVE_SLEEP_POWDER, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [101] = {
        .species = SPECIES_CHIKORITA,
        .moves = {MOVE_SECRET_POWER, MOVE_BULLET_SEED, MOVE_MUD_SLAP, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [102] = {
        .species = SPECIES_ODDISH,
        .moves = {MOVE_ACID, MOVE_STUN_SPORE, MOVE_SWEET_SCENT, MOVE_MOONLIGHT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [103] = {
        .species = SPECIES_PSYDUCK,
        .moves = {MOVE_CONFUSION, MOVE_FURY_SWIPES, MOVE_AERIAL_ACE, MOVE_DISABLE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HASTY
    },
    [104] = {
        .species = SPECIES_CUBONE,
        .moves = {MOVE_BONE_CLUB, MOVE_HEADBUTT, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [105] = {
        .species = SPECIES_GOLDEEN,
        .moves = {MOVE_WATERFALL, MOVE_FURY_ATTACK, MOVE_AGILITY, MOVE_PSYBEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [106] = {
        .species = SPECIES_NATU,
        .moves = {MOVE_NIGHT_SHADE, MOVE_FUTURE_SIGHT, MOVE_CONFUSE_RAY, MOVE_FLASH},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [107] = {
        .species = SPECIES_CLEFAIRY,
        .moves = {MOVE_FOLLOW_ME, MOVE_RETURN, MOVE_ENCORE, MOVE_SING},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [108] = {
        .species = SPECIES_MAGNEMITE,
        .moves = {MOVE_SHOCK_WAVE, MOVE_SUPERSONIC, MOVE_METAL_SOUND, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_GENTLE
    },
    [109] = {
        .species = SPECIES_SEEL,
        .moves = {MOVE_AURORA_BEAM, MOVE_DIVE, MOVE_BODY_SLAM, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_ASPEAR_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [110] = {
        .species = SPECIES_GRIMER,
        .moves = {MOVE_SLUDGE, MOVE_ROCK_TOMB, MOVE_ACID_ARMOR, MOVE_MINIMIZE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [111] = {
        .species = SPECIES_KRABBY,
        .moves = {MOVE_CRABHAMMER, MOVE_MUD_SHOT, MOVE_FLAIL, MOVE_KNOCK_OFF},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [112] = {
        .species = SPECIES_EXEGGCUTE,
        .moves = {MOVE_CONFUSION, MOVE_ANCIENT_POWER, MOVE_LEECH_SEED, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [113] = {
        .species = SPECIES_EEVEE,
        .moves = {MOVE_CHARM, MOVE_ATTRACT, MOVE_FLAIL, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [114] = {
        .species = SPECIES_DROWZEE,
        .moves = {MOVE_CONFUSION, MOVE_HEADBUTT, MOVE_DISABLE, MOVE_BARRIER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [115] = {
        .species = SPECIES_VOLTORB,
        .moves = {MOVE_SPARK, MOVE_SCREECH, MOVE_ROLLOUT, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [116] = {
        .species = SPECIES_CHINCHOU,
        .moves = {MOVE_SPARK, MOVE_DIVE, MOVE_CONFUSE_RAY, MOVE_TAKE_DOWN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [117] = {
        .species = SPECIES_TEDDIURSA,
        .moves = {MOVE_SECRET_POWER, MOVE_FAKE_TEARS, MOVE_FAINT_ATTACK, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [118] = {
        .species = SPECIES_DELIBIRD,
        .moves = {MOVE_PRESENT, MOVE_ICE_BALL, MOVE_AERIAL_ACE, MOVE_HAIL},
        .itemTableId = BATTLE_FRONTIER_ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [119] = {
        .species = SPECIES_HOUNDOUR,
        .moves = {MOVE_CRUNCH, MOVE_EMBER, MOVE_ROAR, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHARCOAL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [120] = {
        .species = SPECIES_PHANPY,
        .moves = {MOVE_ROLLOUT, MOVE_DEFENSE_CURL, MOVE_ROCK_TOMB, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [121] = {
        .species = SPECIES_SPOINK,
        .moves = {MOVE_PSYWAVE, MOVE_BOUNCE, MOVE_MAGIC_COAT, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [122] = {
        .species = SPECIES_ARON,
        .moves = {MOVE_METAL_CLAW, MOVE_AERIAL_ACE, MOVE_METAL_SOUND, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [123] = {
        .species = SPECIES_LUVDISC,
        .moves = {MOVE_SWEET_KISS, MOVE_ATTRACT, MOVE_DIVE, MOVE_RAIN_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [124] = {
        .species = SPECIES_TENTACOOL,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_ACID, MOVE_BARRIER, MOVE_WRAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [125] = {
        .species = SPECIES_CACNEA,
        .moves = {MOVE_NEEDLE_ARM, MOVE_FAINT_ATTACK, MOVE_COTTON_SPORE, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [126] = {
        .species = SPECIES_UNOWN,
        .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [127] = {
        .species = SPECIES_KOFFING,
        .moves = {MOVE_SLUDGE, MOVE_SMOKESCREEN, MOVE_TORMENT, MOVE_HAZE},
        .itemTableId = BATTLE_FRONTIER_ITEM_POISON_BARB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [128] = {
        .species = SPECIES_STARYU,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_MINIMIZE, MOVE_SWIFT, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [129] = {
        .species = SPECIES_SKIPLOOM,
        .moves = {MOVE_MEGA_DRAIN, MOVE_CONFUSION, MOVE_COTTON_SPORE, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [130] = {
        .species = SPECIES_NUZLEAF,
        .moves = {MOVE_EXTRASENSORY, MOVE_FAKE_OUT, MOVE_RAZOR_WIND, MOVE_FAINT_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [131] = {
        .species = SPECIES_LOMBRE,
        .moves = {MOVE_WATER_PULSE, MOVE_FAKE_OUT, MOVE_BRICK_BREAK, MOVE_ABSORB},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [132] = {
        .species = SPECIES_VIBRAVA,
        .moves = {MOVE_DRAGON_BREATH, MOVE_DIG, MOVE_SCREECH, MOVE_ROCK_TOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [133] = {
        .species = SPECIES_RHYHORN,
        .moves = {MOVE_ROCK_BLAST, MOVE_DIG, MOVE_SCARY_FACE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [134] = {
        .species = SPECIES_CLAMPERL,
        .moves = {MOVE_DIVE, MOVE_TOXIC, MOVE_IRON_DEFENSE, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_DEEP_SEA_SCALE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [135] = {
        .species = SPECIES_PIDGEOTTO,
        .moves = {MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK, MOVE_FEATHER_DANCE, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [136] = {
        .species = SPECIES_GROWLITHE,
        .moves = {MOVE_FLAME_WHEEL, MOVE_BITE, MOVE_ROAR, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [137] = {
        .species = SPECIES_FARFETCHD,
        .moves = {MOVE_SLASH, MOVE_KNOCK_OFF, MOVE_SWORDS_DANCE, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_STICK,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [138] = {
        .species = SPECIES_OMANYTE,
        .moves = {MOVE_MUD_SHOT, MOVE_WATER_GUN, MOVE_ANCIENT_POWER, MOVE_TICKLE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [139] = {
        .species = SPECIES_KABUTO,
        .moves = {MOVE_MEGA_DRAIN, MOVE_ANCIENT_POWER, MOVE_SAND_ATTACK, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [140] = {
        .species = SPECIES_LILEEP,
        .moves = {MOVE_ANCIENT_POWER, MOVE_ACID, MOVE_INGRAIN, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [141] = {
        .species = SPECIES_ANORITH,
        .moves = {MOVE_METAL_CLAW, MOVE_FURY_CUTTER, MOVE_ANCIENT_POWER, MOVE_WATER_GUN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [142] = {
        .species = SPECIES_AIPOM,
        .moves = {MOVE_FURY_SWIPES, MOVE_SAND_ATTACK, MOVE_BATON_PASS, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [143] = {
        .species = SPECIES_ELEKID,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_QUICK_ATTACK, MOVE_SWIFT, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAIVE
    },
    [144] = {
        .species = SPECIES_LOUDRED,
        .moves = {MOVE_STOMP, MOVE_HOWL, MOVE_ASTONISH, MOVE_SUPERSONIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [145] = {
        .species = SPECIES_SPINDA,
        .moves = {MOVE_DIZZY_PUNCH, MOVE_TEETER_DANCE, MOVE_PSYBEAM, MOVE_FAINT_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [146] = {
        .species = SPECIES_NIDORINA,
        .moves = {MOVE_DOUBLE_KICK, MOVE_BITE, MOVE_AERIAL_ACE, MOVE_FLATTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [147] = {
        .species = SPECIES_NIDORINO,
        .moves = {MOVE_DOUBLE_KICK, MOVE_WATER_PULSE, MOVE_MUD_SLAP, MOVE_FLATTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [148] = {
        .species = SPECIES_FLAAFFY,
        .moves = {MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_COTTON_SPORE, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_MAGNET,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MILD
    },
    [149] = {
        .species = SPECIES_MAGBY,
        .moves = {MOVE_FIRE_PUNCH, MOVE_SMOKESCREEN, MOVE_CONFUSE_RAY, MOVE_SMOG},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [150] = {
        .species = SPECIES_NOSEPASS,
        .moves = {MOVE_ROCK_SLIDE, MOVE_SHOCK_WAVE, MOVE_THUNDER_WAVE, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_HARD_STONE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [151] = {
        .species = SPECIES_CORSOLA,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_MIRROR_COAT, MOVE_ATTRACT, MOVE_ANCIENT_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [152] = {
        .species = SPECIES_MAWILE,
        .moves = {MOVE_CRUNCH, MOVE_FAKE_TEARS, MOVE_IRON_DEFENSE, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [153] = {
        .species = SPECIES_BUTTERFREE,
        .moves = {MOVE_SILVER_WIND, MOVE_PSYBEAM, MOVE_TOXIC, MOVE_WHIRLWIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [154] = {
        .species = SPECIES_BEEDRILL,
        .moves = {MOVE_TWINEEDLE, MOVE_PURSUIT, MOVE_ENDEAVOR, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY
    },
    [155] = {
        .species = SPECIES_POLIWHIRL,
        .moves = {MOVE_WATER_PULSE, MOVE_DOUBLE_SLAP, MOVE_ICY_WIND, MOVE_RAIN_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [156] = {
        .species = SPECIES_ONIX,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BIND, MOVE_DRAGON_BREATH, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [157] = {
        .species = SPECIES_BEAUTIFLY,
        .moves = {MOVE_SILVER_WIND, MOVE_MEGA_DRAIN, MOVE_ATTRACT, MOVE_WHIRLWIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_MENTAL_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [158] = {
        .species = SPECIES_DUSTOX,
        .moves = {MOVE_SILVER_WIND, MOVE_TOXIC, MOVE_PSYBEAM, MOVE_WHIRLWIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILVER_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [159] = {
        .species = SPECIES_LEDIAN,
        .moves = {MOVE_COMET_PUNCH, MOVE_BATON_PASS, MOVE_SWORDS_DANCE, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BASHFUL
    },
    [160] = {
        .species = SPECIES_ARIADOS,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_SPIDER_WEB, MOVE_NIGHT_SHADE, MOVE_TOXIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SERIOUS
    },
    [161] = {
        .species = SPECIES_YANMA,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_AERIAL_ACE, MOVE_DOUBLE_TEAM, MOVE_DETECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED
    },
    [162] = {
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_SECRET_POWER, MOVE_FAINT_ATTACK, MOVE_DOUBLE_TEAM, MOVE_HEAL_BELL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [163] = {
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_FAINT_ATTACK, MOVE_CONFUSE_RAY, MOVE_KNOCK_OFF, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_GLASSES,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [164] = {
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_SLAM, MOVE_BRICK_BREAK, MOVE_LICK, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [165] = {
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_RAZOR_LEAF, MOVE_ACID, MOVE_WRAP, MOVE_SWEET_SCENT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [166] = {
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_MAGNITUDE, MOVE_ROCK_THROW, MOVE_DEFENSE_CURL, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [167] = {
        .species = SPECIES_GLOOM,
        .moves = {MOVE_PETAL_DANCE, MOVE_ACID, MOVE_STUN_SPORE, MOVE_MOONLIGHT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [168] = {
        .species = SPECIES_PORYGON,
        .moves = {MOVE_PSYBEAM, MOVE_ICY_WIND, MOVE_RECYCLE, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [169] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_CONFUSION, MOVE_ROLE_PLAY, MOVE_FUTURE_SIGHT, MOVE_DISABLE},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [170] = {
        .species = SPECIES_WAILMER,
        .moves = {MOVE_WHIRLPOOL, MOVE_ROAR, MOVE_DEFENSE_CURL, MOVE_ROLLOUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE
    },
    [171] = {
        .species = SPECIES_ROSELIA,
        .moves = {MOVE_MAGICAL_LEAF, MOVE_TOXIC, MOVE_GRASS_WHISTLE, MOVE_COTTON_SPORE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [172] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_SILVER_WIND, MOVE_CONFUSE_RAY, MOVE_QUICK_ATTACK, MOVE_HELPING_HAND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [173] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_SILVER_WIND, MOVE_WISH, MOVE_QUICK_ATTACK, MOVE_HELPING_HAND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [174] = {
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_PETAL_DANCE, MOVE_GROWTH, MOVE_SWEET_SCENT, MOVE_FURY_CUTTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE
    },
    [175] = {
        .species = SPECIES_CHARMELEON,
        .moves = {MOVE_SLASH, MOVE_FIRE_SPIN, MOVE_SWORDS_DANCE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [176] = {
        .species = SPECIES_WARTORTLE,
        .moves = {MOVE_WATER_PULSE, MOVE_BITE, MOVE_MUD_SLAP, MOVE_YAWN},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [177] = {
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SLASH, MOVE_PSYBEAM, MOVE_STUN_SPORE, MOVE_FLASH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RASH
    },
    [178] = {
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_LOW_KICK, MOVE_ROCK_TOMB, MOVE_FORESIGHT, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [179] = {
        .species = SPECIES_HAUNTER,
        .moves = {MOVE_SHADOW_PUNCH, MOVE_CONFUSE_RAY, MOVE_SPITE, MOVE_GRUDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RASH
    },
    [180] = {
        .species = SPECIES_BAYLEEF,
        .moves = {MOVE_RAZOR_LEAF, MOVE_TOXIC, MOVE_SAFEGUARD, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [181] = {
        .species = SPECIES_QUILAVA,
        .moves = {MOVE_FLAME_WHEEL, MOVE_FURY_SWIPES, MOVE_SWIFT, MOVE_SMOKESCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [182] = {
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_SLASH, MOVE_WATER_PULSE, MOVE_BITE, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [183] = {
        .species = SPECIES_TOGETIC,
        .moves = {MOVE_AERIAL_ACE, MOVE_MAGICAL_LEAF, MOVE_WISH, MOVE_FOLLOW_ME},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [184] = {
        .species = SPECIES_MURKROW,
        .moves = {MOVE_FAINT_ATTACK, MOVE_FLY, MOVE_TORMENT, MOVE_TAUNT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [185] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_CHARM, MOVE_SAFEGUARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [186] = {
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_SPARK, MOVE_FAKE_TEARS, MOVE_QUICK_ATTACK, MOVE_HELPING_HAND},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [187] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_SPARK, MOVE_CHARM, MOVE_ENCORE, MOVE_HELPING_HAND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [188] = {
        .species = SPECIES_GROVYLE,
        .moves = {MOVE_FURY_CUTTER, MOVE_ENDEAVOR, MOVE_BRICK_BREAK, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [189] = {
        .species = SPECIES_COMBUSKEN,
        .moves = {MOVE_EMBER, MOVE_DOUBLE_KICK, MOVE_QUICK_ATTACK, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [190] = {
        .species = SPECIES_MARSHTOMP,
        .moves = {MOVE_MUD_SHOT, MOVE_WATER_GUN, MOVE_ROCK_TOMB, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [191] = {
        .species = SPECIES_PONYTA,
        .moves = {MOVE_FIRE_SPIN, MOVE_BOUNCE, MOVE_QUICK_ATTACK, MOVE_TAIL_WHIP},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [192] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_FACADE, MOVE_DIG, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE
    },
    [193] = {
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_ROCK_SLIDE, MOVE_FAINT_ATTACK, MOVE_SANDSTORM, MOVE_BLOCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_HARD_STONE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [194] = {
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_ROCK_SLIDE, MOVE_EMBER, MOVE_ACID_ARMOR, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE
    },
    [195] = {
        .species = SPECIES_PUPITAR,
        .moves = {MOVE_DIG, MOVE_BITE, MOVE_SCARY_FACE, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [196] = {
        .species = SPECIES_SEALEO,
        .moves = {MOVE_ICE_BALL, MOVE_HAIL, MOVE_SNORE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [197] = {
        .species = SPECIES_RATICATE,
        .moves = {MOVE_ENDEAVOR, MOVE_PURSUIT, MOVE_SCARY_FACE, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAIVE
    },
    [198] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_SILVER_WIND, MOVE_AERIAL_ACE, MOVE_ICY_WIND, MOVE_STUN_SPORE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_RELAXED
    },
    [199] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_SLAM, MOVE_PROTECT, MOVE_HELPING_HAND, MOVE_FOLLOW_ME},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_SERIOUS
    },
    [200] = {
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_HEADBUTT, MOVE_GLARE, MOVE_DEFENSE_CURL, MOVE_ROLLOUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [201] = {
        .species = SPECIES_DRAGONAIR,
        .moves = {MOVE_DRAGON_BREATH, MOVE_LEER, MOVE_WRAP, MOVE_SAFEGUARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [202] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_BITE, MOVE_POISON_FANG, MOVE_TAUNT, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_MENTAL_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_TIMID
    },
    [203] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_SECRET_POWER, MOVE_SAND_ATTACK, MOVE_COVET, MOVE_TICKLE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [204] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_EMBER, MOVE_WATER_PULSE, MOVE_SHOCK_WAVE, MOVE_ICY_WIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY
    },
    [205] = {
        .species = SPECIES_SHELGON,
        .moves = {MOVE_HEADBUTT, MOVE_DRAGON_BREATH, MOVE_PROTECT, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [206] = {
        .species = SPECIES_METANG,
        .moves = {MOVE_METAL_CLAW, MOVE_CONFUSION, MOVE_PURSUIT, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [207] = {
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_SING, MOVE_DISABLE, MOVE_WISH, MOVE_SECRET_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED
    },
    [208] = {
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_PETAL_DANCE, MOVE_INGRAIN, MOVE_LEECH_SEED, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [209] = {
        .species = SPECIES_CHIMECHO,
        .moves = {MOVE_PSYWAVE, MOVE_TAKE_DOWN, MOVE_HEAL_BELL, MOVE_SAFEGUARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [210] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_METAL_CLAW, MOVE_DIG, MOVE_AERIAL_ACE, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY
    },
    [211] = {
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_PIN_MISSILE, MOVE_SPIKES, MOVE_MINIMIZE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_IMPISH
    },
    [212] = {
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_FAINT_ATTACK, MOVE_FAKE_OUT, MOVE_ICY_WIND, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [213] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_WATER_PULSE, MOVE_AERIAL_ACE, MOVE_STOCKPILE, MOVE_SWALLOW},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [214] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FLY, MOVE_ENDEAVOR, MOVE_FACADE, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [215] = {
        .species = SPECIES_LAIRON,
        .moves = {MOVE_METAL_CLAW, MOVE_ROCK_TOMB, MOVE_IRON_DEFENSE, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_METAL_COAT,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [216] = {
        .species = SPECIES_TANGELA,
        .moves = {MOVE_MEGA_DRAIN, MOVE_SLAM, MOVE_TOXIC, MOVE_BIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [217] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_POISON_FANG, MOVE_DIG, MOVE_BITE, MOVE_GLARE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [218] = {
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FAKE_OUT, MOVE_SLASH, MOVE_TORMENT, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [219] = {
        .species = SPECIES_SEADRA,
        .moves = {MOVE_AURORA_BEAM, MOVE_SMOKESCREEN, MOVE_WATER_GUN, MOVE_RAIN_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [220] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_SECRET_POWER, MOVE_PSYBEAM, MOVE_MAGIC_COAT, MOVE_SEISMIC_TOSS},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAIVE
    },
    [221] = {
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_SLASH, MOVE_COUNTER, MOVE_ENCORE, MOVE_UPROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_LONELY
    },
    [222] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_CONFUSION, MOVE_COSMIC_POWER, MOVE_LIGHT_SCREEN, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [223] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_CONFUSION, MOVE_FIRE_SPIN, MOVE_LIGHT_SCREEN, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [224] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_CONFUSION, MOVE_AERIAL_ACE, MOVE_FAINT_ATTACK, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [225] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_CRUSH_CLAW, MOVE_ROCK_SLIDE, MOVE_SWIFT, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [226] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_SILVER_WIND, MOVE_PSYBEAM, MOVE_SLEEP_POWDER, MOVE_SKILL_SWAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [227] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_METRONOME, MOVE_REFRESH, MOVE_DEFENSE_CURL, MOVE_MINIMIZE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED
    },
    [228] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_WATER_PULSE, MOVE_PSYBEAM, MOVE_SWIFT, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [229] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_AERIAL_ACE, MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [230] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_DIG, MOVE_ANCIENT_POWER, MOVE_HAIL, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [231] = {
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_AIR_CUTTER, MOVE_CONFUSE_RAY, MOVE_TOXIC, MOVE_STEEL_WING},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [232] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_KARATE_CHOP, MOVE_COUNTER, MOVE_SWAGGER, MOVE_SCREECH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [233] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_ROLLING_KICK, MOVE_BRICK_BREAK, MOVE_FOCUS_ENERGY, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [234] = {
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_MACH_PUNCH, MOVE_SKY_UPPERCUT, MOVE_DETECT, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [235] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_PSYBEAM, MOVE_STOMP, MOVE_WISH, MOVE_SKILL_SWAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [236] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_TRIPLE_KICK, MOVE_DIG, MOVE_MACH_PUNCH, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [237] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_NIGHT_SHADE, MOVE_WILL_O_WISP, MOVE_SPITE, MOVE_KNOCK_OFF},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [238] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_BATON_PASS, MOVE_SWORDS_DANCE, MOVE_ENDURE, MOVE_DIG},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MILD
    },
    [239] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_POISON_TAIL, MOVE_BITE, MOVE_GLARE, MOVE_SCREECH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [240] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_SLASH, MOVE_DOUBLE_KICK, MOVE_ROAR, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [241] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_MAGNITUDE, MOVE_PROTECT, MOVE_SANDSTORM, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [242] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_SLASH, MOVE_BITE, MOVE_WATER_PULSE, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [243] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_MAGICAL_LEAF, MOVE_WHIRLWIND, MOVE_AERIAL_ACE, MOVE_STEEL_WING},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [244] = {
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_SHOCK_WAVE, MOVE_SONIC_BOOM, MOVE_THUNDER_WAVE, MOVE_SUPERSONIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_LONELY
    },
    [245] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_AERIAL_ACE, MOVE_RAIN_DANCE, MOVE_ICY_WIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [246] = {
        .species = SPECIES_STANTLER,
        .moves = {MOVE_EXTRASENSORY, MOVE_CONFUSE_RAY, MOVE_STOMP, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_GENTLE
    },
    [247] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_BITE, MOVE_RAZOR_WIND, MOVE_FUTURE_SIGHT, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [248] = {
        .species = SPECIES_SWALOT,
        .moves = {MOVE_STOCKPILE, MOVE_SWALLOW, MOVE_SPIT_UP, MOVE_SLUDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIRKY
    },
    [249] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_VICE_GRIP, MOVE_KNOCK_OFF, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [250] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_AERIAL_ACE, MOVE_FEATHER_DANCE, MOVE_MUD_SLAP, MOVE_FAINT_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHARP_BEAK,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [251] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYBEAM, MOVE_CONFUSE_RAY, MOVE_FUTURE_SIGHT, MOVE_MAGIC_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [252] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_EMBER, MOVE_FIRE_SPIN, MOVE_SMOKESCREEN, MOVE_AMNESIA},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [253] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_CRABHAMMER, MOVE_METAL_CLAW, MOVE_MUD_SHOT, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [254] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_NEEDLE_ARM, MOVE_FAINT_ATTACK, MOVE_ACID, MOVE_MEGA_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_HASTY
    },
    [255] = {
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_PETAL_DANCE, MOVE_SAFEGUARD, MOVE_SUNNY_DAY, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [256] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_AURORA_BEAM, MOVE_PSYBEAM, MOVE_ROCK_BLAST},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [257] = {
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_WHIRLPOOL, MOVE_SCARY_FACE, MOVE_MUD_SLAP, MOVE_BITE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [258] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_WHIRLPOOL, MOVE_AMNESIA, MOVE_ICY_WIND, MOVE_CONFUSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE
    },
    [259] = {
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_ANCIENT_POWER, MOVE_WATER_PULSE, MOVE_HARDEN, MOVE_AMNESIA},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [260] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_BUBBLE_BEAM, MOVE_SPIKE_CANNON, MOVE_TICKLE, MOVE_ANCIENT_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [261] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_SLASH, MOVE_DIG, MOVE_FURY_CUTTER, MOVE_KNOCK_OFF},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [262] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_SUBMISSION, MOVE_DIG, MOVE_ROCK_TOMB, MOVE_BUBBLE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [263] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_FURY_CUTTER, MOVE_AERIAL_ACE, MOVE_LIGHT_SCREEN, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [264] = {
        .species = SPECIES_PINSIR,
        .moves = {MOVE_SUBMISSION, MOVE_FOCUS_ENERGY, MOVE_SWORDS_DANCE, MOVE_REVENGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BLACK_BELT,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_NAUGHTY
    },
    [265] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_DIVE, MOVE_DIG, MOVE_HYPNOSIS, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED
    },
    [266] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_AURORA_BEAM, MOVE_SPIKE_CANNON, MOVE_SUPERSONIC, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [267] = {
        .species = SPECIES_DELCATTY,
        .moves = {MOVE_FAKE_TEARS, MOVE_SING, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [268] = {
        .species = SPECIES_SABLEYE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FAINT_ATTACK, MOVE_CONFUSE_RAY, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [269] = {
        .species = SPECIES_LICKITUNG,
        .moves = {MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_SHADOW_BALL, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [270] = {
        .species = SPECIES_WEEPINBELL,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_RAZOR_LEAF, MOVE_SLEEP_POWDER, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIRKY
    },
    [271] = {
        .species = SPECIES_GRAVELER,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [272] = {
        .species = SPECIES_GLOOM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_SLUDGE_BOMB, MOVE_MOONLIGHT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PECHA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [273] = {
        .species = SPECIES_PORYGON,
        .moves = {MOVE_TRI_ATTACK, MOVE_PSYCHIC, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [274] = {
        .species = SPECIES_KADABRA,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDER_WAVE, MOVE_REFLECT, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [275] = {
        .species = SPECIES_WAILMER,
        .moves = {MOVE_WATER_SPOUT, MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE
    },
    [276] = {
        .species = SPECIES_ROSELIA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_GRASS_WHISTLE, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [277] = {
        .species = SPECIES_VOLBEAT,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_TAIL_GLOW},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [278] = {
        .species = SPECIES_ILLUMISE,
        .moves = {MOVE_SILVER_WIND, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [279] = {
        .species = SPECIES_IVYSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_SLEEP_POWDER, MOVE_LEECH_SEED},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [280] = {
        .species = SPECIES_CHARMELEON,
        .moves = {MOVE_FLAMETHROWER, MOVE_SLASH, MOVE_ANCIENT_POWER, MOVE_DRAGON_RAGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [281] = {
        .species = SPECIES_WARTORTLE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAPID_SPIN, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [282] = {
        .species = SPECIES_PARASECT,
        .moves = {MOVE_SPORE, MOVE_GIGA_DRAIN, MOVE_DIG, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [283] = {
        .species = SPECIES_MACHOKE,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_FORESIGHT, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [284] = {
        .species = SPECIES_HAUNTER,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_NIGHTMARE, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [285] = {
        .species = SPECIES_BAYLEEF,
        .moves = {MOVE_GIGA_DRAIN, MOVE_BODY_SLAM, MOVE_GRASS_WHISTLE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [286] = {
        .species = SPECIES_QUILAVA,
        .moves = {MOVE_FLAMETHROWER, MOVE_CRUSH_CLAW, MOVE_BODY_SLAM, MOVE_SMOKESCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [287] = {
        .species = SPECIES_CROCONAW,
        .moves = {MOVE_MEGA_KICK, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE, MOVE_DIG},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [288] = {
        .species = SPECIES_TOGETIC,
        .moves = {MOVE_RETURN, MOVE_SWEET_KISS, MOVE_AERIAL_ACE, MOVE_YAWN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [289] = {
        .species = SPECIES_MURKROW,
        .moves = {MOVE_PERISH_SONG, MOVE_MEAN_LOOK, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [290] = {
        .species = SPECIES_WOBBUFFET,
        .moves = {MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_ENCORE, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL
    },
    [291] = {
        .species = SPECIES_PLUSLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_SEISMIC_TOSS, MOVE_WISH},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [292] = {
        .species = SPECIES_MINUN,
        .moves = {MOVE_THUNDERBOLT, MOVE_ATTRACT, MOVE_CHARM, MOVE_WISH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [293] = {
        .species = SPECIES_GROVYLE,
        .moves = {MOVE_GIGA_DRAIN, MOVE_CRUSH_CLAW, MOVE_SCREECH, MOVE_ROCK_TOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [294] = {
        .species = SPECIES_COMBUSKEN,
        .moves = {MOVE_FLAMETHROWER, MOVE_SKY_UPPERCUT, MOVE_SLASH, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [295] = {
        .species = SPECIES_MARSHTOMP,
        .moves = {MOVE_MUDDY_WATER, MOVE_EARTHQUAKE, MOVE_MUD_SLAP, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [296] = {
        .species = SPECIES_PONYTA,
        .moves = {MOVE_FLAMETHROWER, MOVE_BODY_SLAM, MOVE_DOUBLE_KICK, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [297] = {
        .species = SPECIES_AZUMARILL,
        .moves = {MOVE_MEGA_KICK, MOVE_BRICK_BREAK, MOVE_IRON_TAIL, MOVE_DIG},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [298] = {
        .species = SPECIES_SUDOWOODO,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_LOW_KICK, MOVE_SELF_DESTRUCT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [299] = {
        .species = SPECIES_MAGCARGO,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [300] = {
        .species = SPECIES_PUPITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [301] = {
        .species = SPECIES_SEALEO,
        .moves = {MOVE_ICE_BEAM, MOVE_SURF, MOVE_BODY_SLAM, MOVE_HAIL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [302] = {
        .species = SPECIES_RATICATE,
        .moves = {MOVE_SUPER_FANG, MOVE_HYPER_FANG, MOVE_SHADOW_BALL, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [303] = {
        .species = SPECIES_MASQUERAIN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_GIGA_DRAIN, MOVE_STUN_SPORE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [304] = {
        .species = SPECIES_FURRET,
        .moves = {MOVE_TRICK, MOVE_FRUSTRATION, MOVE_SHADOW_BALL, MOVE_FOLLOW_ME},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [305] = {
        .species = SPECIES_DUNSPARCE,
        .moves = {MOVE_ICE_BEAM, MOVE_ROCK_TOMB, MOVE_BITE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [306] = {
        .species = SPECIES_DRAGONAIR,
        .moves = {MOVE_RETURN, MOVE_REST, MOVE_THUNDER_WAVE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [307] = {
        .species = SPECIES_MIGHTYENA,
        .moves = {MOVE_CRUNCH, MOVE_SHADOW_BALL, MOVE_FRUSTRATION, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIRKY
    },
    [308] = {
        .species = SPECIES_LINOONE,
        .moves = {MOVE_TRICK, MOVE_FRUSTRATION, MOVE_THUNDER_WAVE, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY
    },
    [309] = {
        .species = SPECIES_CASTFORM,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_WATER_PULSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [310] = {
        .species = SPECIES_SHELGON,
        .moves = {MOVE_FRUSTRATION, MOVE_DRAGON_DANCE, MOVE_CRUNCH, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [311] = {
        .species = SPECIES_METANG,
        .moves = {MOVE_METEOR_MASH, MOVE_PSYCHIC, MOVE_BODY_SLAM, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [312] = {
        .species = SPECIES_WIGGLYTUFF,
        .moves = {MOVE_FAKE_TEARS, MOVE_SING, MOVE_DREAM_EATER, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE
    },
    [313] = {
        .species = SPECIES_SUNFLORA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_GRASS_WHISTLE, MOVE_GROWTH, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [314] = {
        .species = SPECIES_CHIMECHO,
        .moves = {MOVE_PSYCHIC, MOVE_HYPNOSIS, MOVE_DREAM_EATER, MOVE_HEAL_BELL},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [315] = {
        .species = SPECIES_GLIGAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_GUILLOTINE, MOVE_SCREECH},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [316] = {
        .species = SPECIES_QWILFISH,
        .moves = {MOVE_REVENGE, MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [317] = {
        .species = SPECIES_SNEASEL,
        .moves = {MOVE_CRUSH_CLAW, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE, MOVE_SCREECH},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY
    },
    [318] = {
        .species = SPECIES_PELIPPER,
        .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_AERIAL_ACE, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [319] = {
        .species = SPECIES_SWELLOW,
        .moves = {MOVE_FACADE, MOVE_AERIAL_ACE, MOVE_PURSUIT, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [320] = {
        .species = SPECIES_LAIRON,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_ROAR, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [321] = {
        .species = SPECIES_TANGELA,
        .moves = {MOVE_GIGA_DRAIN, MOVE_STUN_SPORE, MOVE_REST, MOVE_AMNESIA},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [322] = {
        .species = SPECIES_ARBOK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_GLARE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [323] = {
        .species = SPECIES_PERSIAN,
        .moves = {MOVE_FRUSTRATION, MOVE_SHADOW_BALL, MOVE_ROAR, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SILK_SCARF,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [324] = {
        .species = SPECIES_SEADRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FRUSTRATION, MOVE_DRAGON_BREATH, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [325] = {
        .species = SPECIES_KECLEON,
        .moves = {MOVE_TRICK, MOVE_BRICK_BREAK, MOVE_SHADOW_BALL, MOVE_SKILL_SWAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [326] = {
        .species = SPECIES_VIGOROTH,
        .moves = {MOVE_CRUSH_CLAW, MOVE_REVERSAL, MOVE_ENDURE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [327] = {
        .species = SPECIES_LUNATONE,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_COSMIC_POWER, MOVE_CALM_MIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [328] = {
        .species = SPECIES_SOLROCK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_COSMIC_POWER, MOVE_OVERHEAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [329] = {
        .species = SPECIES_NOCTOWL,
        .moves = {MOVE_PSYCHIC, MOVE_FAINT_ATTACK, MOVE_AERIAL_ACE, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [330] = {
        .species = SPECIES_SANDSLASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CRUSH_CLAW, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [331] = {
        .species = SPECIES_VENOMOTH,
        .moves = {MOVE_SIGNAL_BEAM, MOVE_PSYCHIC, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [332] = {
        .species = SPECIES_CHANSEY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_SHADOW_BALL, MOVE_DOUBLE_TEAM, MOVE_SOFT_BOILED},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_RELAXED
    },
    [333] = {
        .species = SPECIES_SEAKING,
        .moves = {MOVE_HORN_DRILL, MOVE_MEGAHORN, MOVE_SLEEP_TALK, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [334] = {
        .species = SPECIES_JUMPLUFF,
        .moves = {MOVE_LEECH_SEED, MOVE_SLEEP_POWDER, MOVE_GIGA_DRAIN, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD
    },
    [335] = {
        .species = SPECIES_PILOSWINE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BODY_SLAM, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT
    },
    [336] = {
        .species = SPECIES_GOLBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY, MOVE_AIR_CUTTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [337] = {
        .species = SPECIES_PRIMEAPE,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_TOMB, MOVE_OVERHEAT, MOVE_BULK_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [338] = {
        .species = SPECIES_HITMONLEE,
        .moves = {MOVE_MEGA_KICK, MOVE_BRICK_BREAK, MOVE_FORESIGHT, MOVE_ROCK_TOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [339] = {
        .species = SPECIES_HITMONCHAN,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_MACH_PUNCH, MOVE_DETECT, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [340] = {
        .species = SPECIES_GIRAFARIG,
        .moves = {MOVE_PSYCHIC, MOVE_CRUNCH, MOVE_BATON_PASS, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [341] = {
        .species = SPECIES_HITMONTOP,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SEISMIC_TOSS, MOVE_ROCK_SLIDE, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [342] = {
        .species = SPECIES_BANETTE,
        .moves = {MOVE_SHADOW_BALL, MOVE_FRUSTRATION, MOVE_SCREECH, MOVE_WILL_O_WISP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT
    },
    [343] = {
        .species = SPECIES_NINJASK,
        .moves = {MOVE_SLASH, MOVE_SHADOW_BALL, MOVE_SWORDS_DANCE, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [344] = {
        .species = SPECIES_SEVIPER,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [345] = {
        .species = SPECIES_ZANGOOSE,
        .moves = {MOVE_CRUSH_CLAW, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [346] = {
        .species = SPECIES_CAMERUPT,
        .moves = {MOVE_EARTHQUAKE, MOVE_ERUPTION, MOVE_BODY_SLAM, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [347] = {
        .species = SPECIES_SHARPEDO,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_SURF},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [348] = {
        .species = SPECIES_TROPIUS,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [349] = {
        .species = SPECIES_MAGNETON,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_THUNDER_WAVE, MOVE_METAL_SOUND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [350] = {
        .species = SPECIES_MANTINE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [351] = {
        .species = SPECIES_STANTLER,
        .moves = {MOVE_FRUSTRATION, MOVE_SHADOW_BALL, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [352] = {
        .species = SPECIES_ABSOL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_AERIAL_ACE, MOVE_IRON_TAIL},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [353] = {
        .species = SPECIES_SWALOT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_BODY_SLAM, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [354] = {
        .species = SPECIES_CRAWDAUNT,
        .moves = {MOVE_GUILLOTINE, MOVE_FRUSTRATION, MOVE_ANCIENT_POWER, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [355] = {
        .species = SPECIES_PIDGEOT,
        .moves = {MOVE_RETURN, MOVE_AERIAL_ACE, MOVE_STEEL_WING, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [356] = {
        .species = SPECIES_GRUMPIG,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [357] = {
        .species = SPECIES_TORKOAL,
        .moves = {MOVE_OVERHEAT, MOVE_BODY_SLAM, MOVE_SMOKESCREEN, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [358] = {
        .species = SPECIES_KINGLER,
        .moves = {MOVE_GUILLOTINE, MOVE_ROCK_TOMB, MOVE_FLAIL, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [359] = {
        .species = SPECIES_CACTURNE,
        .moves = {MOVE_MEGA_KICK, MOVE_TEETER_DANCE, MOVE_FAINT_ATTACK, MOVE_SANDSTORM},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_HARDY
    },
    [360] = {
        .species = SPECIES_BELLOSSOM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_ATTRACT, MOVE_SUNNY_DAY, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [361] = {
        .species = SPECIES_OCTILLERY,
        .moves = {MOVE_OCTAZOOKA, MOVE_FIRE_BLAST, MOVE_THUNDER_WAVE, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [362] = {
        .species = SPECIES_HUNTAIL,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_CRUNCH, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [363] = {
        .species = SPECIES_GOREBYSS,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_PSYCHIC, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [364] = {
        .species = SPECIES_RELICANTH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AMNESIA, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [365] = {
        .species = SPECIES_OMASTAR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_RAIN_DANCE, MOVE_ICE_BEAM, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [366] = {
        .species = SPECIES_KABUTOPS,
        .moves = {MOVE_SLASH, MOVE_ROCK_SLIDE, MOVE_FLAIL, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [367] = {
        .species = SPECIES_POLIWRATH,
        .moves = {MOVE_BRICK_BREAK, MOVE_HYPNOSIS, MOVE_REST, MOVE_BELLY_DRUM},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [368] = {
        .species = SPECIES_SCYTHER,
        .moves = {MOVE_SILVER_WIND, MOVE_AERIAL_ACE, MOVE_SWORDS_DANCE, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [369] = {
        .species = SPECIES_PINSIR,
        .moves = {MOVE_GUILLOTINE, MOVE_SWORDS_DANCE, MOVE_FLAIL, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY
    },
    [370] = {
        .species = SPECIES_POLITOED,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_MUD_SLAP, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LAX_INCENSE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [371] = {
        .species = SPECIES_CLOYSTER,
        .moves = {MOVE_DIVE, MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [372] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_TRI_ATTACK, MOVE_SLASH, MOVE_SAND_TOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_SOFT_SAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [373] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_PSYCHIC, MOVE_HI_JUMP_KICK, MOVE_CALM_MIND, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [374] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_PAIN_SPLIT, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [375] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_TRI_ATTACK, MOVE_FACADE, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHARP_BEAK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [376] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_MEGA_KICK, MOVE_SMELLING_SALT, MOVE_THUNDER_WAVE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [377] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_ICE_BEAM, MOVE_FAKE_OUT, MOVE_LOVELY_KISS, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [378] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_WILL_O_WISP, MOVE_SEISMIC_TOSS, MOVE_PAIN_SPLIT, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [379] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_DRILL_PECK, MOVE_TRI_ATTACK, MOVE_SLEEP_TALK, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [380] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_MAGICAL_LEAF, MOVE_FAKE_OUT, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [381] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_ATTRACT, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [382] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_SKY_UPPERCUT, MOVE_MACH_PUNCH, MOVE_HEADBUTT, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY
    },
    [383] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_LIGHT_SCREEN, MOVE_SPIKES},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [384] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AMNESIA, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [385] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_DRILL_PECK, MOVE_NIGHT_SHADE, MOVE_WISH, MOVE_FUTURE_SIGHT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHARP_BEAK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [386] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_STEEL_WING, MOVE_AIR_CUTTER, MOVE_COUNTER, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [387] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_BONEMERANG, MOVE_ROCK_SLIDE, MOVE_ICY_WIND, MOVE_HEADBUTT},
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [388] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_COUNTER, MOVE_MUD_SLAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [389] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_METRONOME, MOVE_DOUBLE_TEAM, MOVE_REFLECT, MOVE_FOLLOW_ME},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BRAVE
    },
    [390] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_COUNTER, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [391] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_QUICK_ATTACK, MOVE_LIGHT_SCREEN, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [392] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_ICE_BEAM, MOVE_ICY_WIND, MOVE_HEADBUTT, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_NEVER_MELT_ICE,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [393] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLASH, MOVE_QUICK_ATTACK, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_MAGNET,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [394] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_PETAL_DANCE, MOVE_MOONLIGHT, MOVE_AROMATHERAPY},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [395] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_SWEET_SCENT, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [396] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_THUNDERBOLT, MOVE_SWIFT, MOVE_LIGHT_SCREEN, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [397] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_HYPER_VOICE, MOVE_SHADOW_BALL, MOVE_SLEEP_TALK, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [398] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_FAINT_ATTACK, MOVE_QUICK_ATTACK, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_MIRACLE_SEED,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [399] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_ICE_BEAM, MOVE_CRUNCH, MOVE_HAIL, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [400] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [401] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_HYPNOSIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [402] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_COUNTER, MOVE_ROCK_TOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [403] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_TOMB, MOVE_SCARY_FACE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [404] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [405] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_WILL_O_WISP, MOVE_SHADOW_BALL, MOVE_SMOKESCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [406] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_DIZZY_PUNCH, MOVE_BRICK_BREAK, MOVE_COUNTER, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [407] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_BRICK_BREAK, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [408] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_EARTHQUAKE, MOVE_THRASH, MOVE_SWAGGER, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [409] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_HEADBUTT, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [410] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_PSYCHIC, MOVE_BRICK_BREAK, MOVE_AMNESIA, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [411] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_FACADE, MOVE_SHADOW_BALL, MOVE_COUNTER, MOVE_MILK_DRINK},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [412] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE, MOVE_REFRESH, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [413] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_DOUBLE_KICK, MOVE_BODY_SLAM, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [414] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_HORN_DRILL, MOVE_DOUBLE_KICK, MOVE_BODY_SLAM, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [415] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_SMOKESCREEN, MOVE_BRICK_BREAK, MOVE_BARRIER},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [416] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_GIGA_DRAIN, MOVE_ROCK_SLIDE, MOVE_BARRIER, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [417] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_SLASH, MOVE_AERIAL_ACE, MOVE_ANCIENT_POWER, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [418] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_DIG, MOVE_BRICK_BREAK, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [419] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FLAMETHROWER, MOVE_DOUBLE_KICK, MOVE_QUICK_ATTACK, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHARCOAL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIET
    },
    [420] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BODY_SLAM, MOVE_SCREECH, MOVE_MINIMIZE},
        .itemTableId = BATTLE_FRONTIER_ITEM_POISON_BARB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [421] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_CONFUSE_RAY, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID
    },
    [422] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_THUNDER_WAVE, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_MAGNET,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [423] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_METAL_CLAW, MOVE_AERIAL_ACE, MOVE_COUNTER, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [424] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_BRICK_BREAK, MOVE_ROCK_TOMB, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [425] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_MEGA_KICK, MOVE_CRUNCH, MOVE_AERIAL_ACE, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [426] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FLAMETHROWER, MOVE_SHADOW_BALL, MOVE_COUNTER, MOVE_WILL_O_WISP},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [427] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_SWAGGER, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [428] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [429] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SURF, MOVE_ICY_WIND, MOVE_BODY_SLAM, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [430] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP},
        .itemTableId = BATTLE_FRONTIER_ITEM_RAWST_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [431] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_ROCK_SLIDE, MOVE_COUNTER, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [432] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_ROLLOUT, MOVE_DEFENSE_CURL, MOVE_SLEEP_TALK, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BRAVE
    },
    [433] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_BREATH, MOVE_ROCK_TOMB, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [434] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_ICY_WIND, MOVE_BARRIER, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_PERSIM_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_IMPISH
    },
    [435] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_ANCIENT_POWER, MOVE_DRAGON_BREATH, MOVE_AERIAL_ACE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [436] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_TRI_ATTACK, MOVE_AERIAL_ACE, MOVE_SHADOW_BALL, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [437] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_MAGICAL_LEAF, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID
    },
    [438] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [439] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [440] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_STEEL_WING, MOVE_FAINT_ATTACK, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [441] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_SLEEP_POWDER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [442] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ROAR, MOVE_BITE, MOVE_QUICK_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_MYSTIC_WATER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [443] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_ATTRACT, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [444] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_FLAMETHROWER, MOVE_ROAR, MOVE_BITE, MOVE_SAND_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [445] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_LIGHT_SCREEN, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [446] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_CHARM, MOVE_CALM_MIND, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [447] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_CONFUSE_RAY, MOVE_FAINT_ATTACK, MOVE_DOUBLE_TEAM, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [448] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_RAIN_DANCE, MOVE_BITE, MOVE_SEISMIC_TOSS},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [449] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SURF, MOVE_RAIN_DANCE, MOVE_AERIAL_ACE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [450] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_IRON_TAIL, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [451] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_FLAMETHROWER, MOVE_SUNNY_DAY, MOVE_DOUBLE_KICK, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [452] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_BLIZZARD, MOVE_HAIL, MOVE_YAWN, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [453] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_LEECH_SEED, MOVE_AERIAL_ACE, MOVE_DETECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [454] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_ROAR, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [455] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_SMOKESCREEN, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [456] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SURF, MOVE_ATTRACT, MOVE_CONFUSE_RAY, MOVE_SING},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD
    },
    [457] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BITE, MOVE_ASTONISH, MOVE_SCREECH},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [458] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_REST, MOVE_CURSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [459] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_RETURN, MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [460] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_FACADE, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [461] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_HYDRO_PUMP, MOVE_DRAGON_BREATH, MOVE_ICY_WIND, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [462] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_SING, MOVE_SOFT_BOILED},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD
    },
    [463] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICY_WIND, MOVE_RECOVER, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [464] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FLAMETHROWER, MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [465] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE, MOVE_HEADBUTT, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [466] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_AERIAL_ACE, MOVE_FACADE, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [467] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_YAWN, MOVE_BULK_UP, MOVE_SWAGGER, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [468] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_AERIAL_ACE, MOVE_TRI_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [469] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_PSYCHIC, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [470] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_ICY_WIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [471] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_CURSE, MOVE_ATTRACT, MOVE_YAWN, MOVE_ANCIENT_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_SASSY
    },
    [472] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_PSYCHIC, MOVE_ATTRACT, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD
    },
    [473] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_TRI_ATTACK, MOVE_ATTRACT, MOVE_PURSUIT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [474] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_QUIET
    },
    [475] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_PERISH_SONG, MOVE_MEAN_LOOK, MOVE_LOVELY_KISS, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [476] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_TOXIC, MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [477] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_DRILL_PECK, MOVE_DOUBLE_EDGE, MOVE_FAINT_ATTACK, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [478] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_BATON_PASS, MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_PSYCHIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [479] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_FLAIL, MOVE_ENDURE, MOVE_THUNDERBOLT, MOVE_SURF},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [480] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_LEECH_SEED, MOVE_FOCUS_PUNCH, MOVE_SPORE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [481] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_COUNTER, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [482] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_SPIKES, MOVE_ROAR, MOVE_DRILL_PECK, MOVE_TOXIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [483] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_SPARK, MOVE_FUTURE_SIGHT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [484] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_FLY, MOVE_TOXIC, MOVE_CONFUSE_RAY, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [485] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_METEOR_MASH, MOVE_COSMIC_POWER, MOVE_DOUBLE_TEAM, MOVE_FOLLOW_ME},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [486] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [487] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_REVERSAL, MOVE_ENDURE, MOVE_AGILITY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [488] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_BLIZZARD, MOVE_DOUBLE_EDGE, MOVE_ENCORE, MOVE_DISABLE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [489] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_CRUNCH, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [490] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_INGRAIN, MOVE_DOUBLE_TEAM, MOVE_TOXIC, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [491] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_SLEEP_POWDER, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_SERIOUS
    },
    [492] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_DOUBLE_TEAM, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [493] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [494] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_LEECH_SEED, MOVE_DIG, MOVE_DOUBLE_TEAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_IMPISH
    },
    [495] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_EXPLOSION, MOVE_ENDURE, MOVE_BODY_SLAM, MOVE_ICY_WIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [496] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [497] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_HYPNOSIS, MOVE_NIGHTMARE, MOVE_DREAM_EATER, MOVE_PSYCHIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_TWISTED_SPOON,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [498] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_DOUBLE_TEAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [499] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_EARTHQUAKE, MOVE_HORN_DRILL, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [500] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [501] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_MEMENTO, MOVE_SLUDGE_BOMB, MOVE_FACADE, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [502] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_CRUSH_CLAW, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [503] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_ATTRACT, MOVE_FOCUS_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [504] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_DOUBLE_TEAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [505] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_YAWN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_MODEST
    },
    [506] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_YAWN, MOVE_THUNDER_WAVE, MOVE_SURF, MOVE_PSYCHIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [507] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [508] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_PERISH_SONG, MOVE_DRAGON_BREATH, MOVE_PURSUIT, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [509] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [510] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [511] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FIRE_BLAST, MOVE_SMOKESCREEN, MOVE_THUNDER_PUNCH, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [512] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SITRUS_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [513] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_IRON_TAIL, MOVE_ANCIENT_POWER, MOVE_BRICK_BREAK, MOVE_KNOCK_OFF},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [514] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_CROSS_CHOP, MOVE_SURF, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [515] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_FIRE_BLAST, MOVE_BOUNCE, MOVE_DOUBLE_TEAM, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [516] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_CURSE, MOVE_REST, MOVE_SLUDGE_BOMB, MOVE_DYNAMIC_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [517] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [518] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_FOCUS_PUNCH, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [519] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_SILVER_WIND, MOVE_STEEL_WING, MOVE_SWORDS_DANCE, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [520] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ATTRACT, MOVE_BULK_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY
    },
    [521] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [522] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_FIRE_BLAST, MOVE_CRUNCH, MOVE_ROAR, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [523] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_FLAIL, MOVE_ENDURE, MOVE_EARTHQUAKE, MOVE_ROCK_TOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY
    },
    [524] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_DOUBLE_TEAM, MOVE_COSMIC_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [525] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_REST, MOVE_CURSE, MOVE_AMNESIA},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [526] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_HEAT_WAVE, MOVE_BODY_SLAM, MOVE_GRUDGE, MOVE_SUNNY_DAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [527] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_BULK_UP, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [528] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_SANDSTORM, MOVE_DIG, MOVE_FLASH, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL
    },
    [529] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_BREATH, MOVE_SANDSTORM, MOVE_BLOCK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [530] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_TOXIC, MOVE_GIGA_DRAIN, MOVE_CONFUSE_RAY, MOVE_SURF},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [531] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_HYPER_BEAM, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ANCIENT_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [532] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [533] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_DOUBLE_TEAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [534] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_RETURN, MOVE_CURSE, MOVE_SLEEP_POWDER, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [535] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [536] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_SOLAR_BEAM, MOVE_FIRE_BLAST, MOVE_CRUNCH, MOVE_SUNNY_DAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [537] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_DOUBLE_TEAM, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [538] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_BODY_SLAM, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [539] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_DIG, MOVE_DOUBLE_KICK, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [540] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_CURSE, MOVE_ATTRACT, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_RELAXED
    },
    [541] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_LEECH_SEED, MOVE_SUBSTITUTE, MOVE_DOUBLE_TEAM, MOVE_GRASS_WHISTLE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [542] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [543] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_CURSE, MOVE_SCREECH, MOVE_DOUBLE_TEAM, MOVE_DOUBLE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [544] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_HYDRO_PUMP, MOVE_MEGA_KICK, MOVE_BRICK_BREAK, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE
    },
    [545] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_SURF, MOVE_DRAGON_CLAW, MOVE_BRICK_BREAK, MOVE_SCARY_FACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_SASSY
    },
    [546] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [547] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_BLAZE_KICK, MOVE_MEGA_KICK, MOVE_THUNDER_PUNCH, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [548] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_CURSE, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_QUIRKY
    },
    [549] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_THUNDER_PUNCH, MOVE_ATTRACT, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [550] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_DRAGON_DANCE, MOVE_SMOKESCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [551] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_FLAMETHROWER, MOVE_THUNDER_PUNCH, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [552] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_BODY_SLAM, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID
    },
    [553] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_TOXIC, MOVE_GIGA_DRAIN, MOVE_CONFUSE_RAY, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [554] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [555] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDERBOLT, MOVE_FIRE_BLAST, MOVE_BLIZZARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [556] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CURSE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [557] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_DRAGON_BREATH, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [558] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_SING, MOVE_ATTRACT, MOVE_SUBSTITUTE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD
    },
    [559] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_SAFEGUARD, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [560] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_CRUNCH, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [561] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_SWAGGER, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [562] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EARTHQUAKE, MOVE_METEOR_MASH, MOVE_PSYCH_UP, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [563] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_YAWN, MOVE_AMNESIA},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT
    },
    [564] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_SLUDGE_BOMB, MOVE_FISSURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [565] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_HARDY
    },
    [566] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_PERISH_SONG, MOVE_MEAN_LOOK, MOVE_THUNDER_WAVE, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [567] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_RETURN, MOVE_STEEL_WING, MOVE_FAINT_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [568] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_SLUDGE_BOMB, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [569] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_DREAM_EATER, MOVE_LOVELY_KISS, MOVE_ATTRACT, MOVE_SUBSTITUTE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [570] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_PSYCH_UP, MOVE_SWAGGER, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [571] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_DRILL_PECK, MOVE_STEEL_WING, MOVE_FAINT_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [572] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_TRICK, MOVE_TORMENT, MOVE_PSYCHIC, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [573] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_CONFUSE_RAY, MOVE_RAIN_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [574] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_IRON_TAIL, MOVE_FOCUS_PUNCH, MOVE_ATTRACT, MOVE_SPORE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [575] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_GIGA_DRAIN, MOVE_ZAP_CANNON},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [576] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_SLEEP_TALK, MOVE_REST, MOVE_SURF, MOVE_FISSURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_HARDY
    },
    [577] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_DRILL_PECK, MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_STEEL_WING},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY
    },
    [578] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_TOXIC, MOVE_CURSE, MOVE_REST, MOVE_FLY},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [579] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [580] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_EARTHQUAKE, MOVE_SLUDGE_BOMB, MOVE_DOUBLE_EDGE, MOVE_CURSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [581] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_FLAMETHROWER, MOVE_MAGICAL_LEAF},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [582] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [583] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_IRON_TAIL, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHERI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [584] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_HORN_DRILL, MOVE_SHEER_COLD, MOVE_SLEEP_TALK, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [585] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_IRON_TAIL, MOVE_THUNDER_WAVE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [586] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_ATTRACT, MOVE_STUN_SPORE, MOVE_SLUDGE_BOMB, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [587] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_STUN_SPORE, MOVE_INGRAIN, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [588] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_EXPLOSION, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LIECHI_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY
    },
    [589] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_OVERHEAT, MOVE_ICE_BEAM, MOVE_THUNDER_PUNCH, MOVE_EXTRASENSORY},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [590] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_EXPLOSION, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [591] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_BLIZZARD, MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [592] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_LEECH_SEED, MOVE_RAIN_DANCE, MOVE_DOUBLE_TEAM, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [593] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCH_UP, MOVE_SWAGGER, MOVE_MEGA_KICK, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [594] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [595] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_MEGAHORN, MOVE_CRUSH_CLAW, MOVE_EARTHQUAKE, MOVE_HORN_DRILL},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [596] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_TRICK, MOVE_DISABLE, MOVE_PSYCHIC, MOVE_SKILL_SWAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [597] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_EXPLOSION, MOVE_SLUDGE_BOMB, MOVE_FLAMETHROWER, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [598] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_THUNDERBOLT, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY
    },
    [599] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_THUNDERBOLT, MOVE_CROSS_CHOP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [600] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_ICE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [601] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_QUIET
    },
    [602] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [603] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [604] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_SING, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [605] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_CRUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [606] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_HORN_DRILL, MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_SURF},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEPPA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [607] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_MEGA_KICK, MOVE_CROSS_CHOP, MOVE_IRON_TAIL, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_IMPISH
    },
    [608] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_SUBSTITUTE, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [609] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_SWORDS_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [610] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_HYDRO_PUMP, MOVE_CROSS_CHOP, MOVE_BLIZZARD, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [611] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_OVERHEAT, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY, MOVE_HYPNOSIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [612] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_QUIET
    },
    [613] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN, MOVE_SKILL_SWAP},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [614] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_MEGA_KICK, MOVE_IRON_TAIL, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [615] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_REVERSAL, MOVE_ENDURE, MOVE_AGILITY, MOVE_SLASH},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_CAREFUL
    },
    [616] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [617] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FIRE_PUNCH, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH, MOVE_CRUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [618] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_OVERHEAT, MOVE_SHADOW_BALL, MOVE_SLUDGE_BOMB, MOVE_DOUBLE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [619] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_FISSURE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SECRET_POWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [620] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_SOLAR_BEAM, MOVE_SUNNY_DAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [621] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_HYDRO_PUMP, MOVE_FISSURE, MOVE_DOUBLE_TEAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [622] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_FIRE_BLAST, MOVE_IRON_TAIL, MOVE_CONFUSE_RAY, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [623] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_FIRE_BLAST, MOVE_THUNDER_PUNCH, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [624] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_SUBSTITUTE, MOVE_ATTRACT, MOVE_TOXIC, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL
    },
    [625] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_BODY_SLAM, MOVE_ROCK_SLIDE, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [626] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_SURF, MOVE_GIGA_DRAIN, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [627] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_FIRE_BLAST, MOVE_DRAGON_CLAW},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [628] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_PSYCHIC, MOVE_TRI_ATTACK, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [629] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH, MOVE_MAGICAL_LEAF},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [630] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_LEECH_SEED, MOVE_GIGA_DRAIN, MOVE_TOXIC, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [631] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [632] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_FLAMETHROWER, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [633] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_SLEEP_POWDER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [634] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_ACID_ARMOR, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [635] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_AGILITY, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [636] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_SHADOW_BALL, MOVE_FLAIL, MOVE_ENDURE, MOVE_OVERHEAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY
    },
    [637] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_EARTHQUAKE, MOVE_FLAIL, MOVE_ENDURE, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_JOLLY
    },
    [638] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_BITE, MOVE_WISH, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [639] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_ATTRACT, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [640] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [641] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [642] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_SURF, MOVE_THUNDER, MOVE_FIRE_BLAST, MOVE_BLIZZARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [643] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_ENDURE, MOVE_REVERSAL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [644] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_SHEER_COLD, MOVE_FISSURE, MOVE_SURF, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [645] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_EARTHQUAKE, MOVE_CRUSH_CLAW, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [646] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_BITE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [647] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_EARTHQUAKE, MOVE_OVERHEAT, MOVE_ENDURE, MOVE_REVERSAL},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [648] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [649] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_AIR_CUTTER, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_SCREECH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [650] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BRAVE
    },
    [651] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_SURF, MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [652] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT
    },
    [653] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_FLAIL, MOVE_HYDRO_PUMP, MOVE_DRAGON_DANCE, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [654] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_CALM_MIND, MOVE_SOFT_BOILED},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD
    },
    [655] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SURF, MOVE_BLIZZARD, MOVE_ATTRACT, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [656] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [657] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [658] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EARTHQUAKE, MOVE_METEOR_MASH, MOVE_DOUBLE_TEAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [659] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_ADAMANT
    },
    [660] = {
        .species = SPECIES_DUGTRIO,
        .moves = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_ROCK_SLIDE, MOVE_FISSURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [661] = {
        .species = SPECIES_MEDICHAM,
        .moves = {MOVE_MEGA_KICK, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [662] = {
        .species = SPECIES_MISDREAVUS,
        .moves = {MOVE_DESTINY_BOND, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID
    },
    [663] = {
        .species = SPECIES_FEAROW,
        .moves = {MOVE_DRILL_PECK, MOVE_DOUBLE_EDGE, MOVE_STEEL_WING, MOVE_SKY_ATTACK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [664] = {
        .species = SPECIES_GRANBULL,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BRAVE
    },
    [665] = {
        .species = SPECIES_JYNX,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_LOVELY_KISS, MOVE_FAKE_TEARS},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [666] = {
        .species = SPECIES_DUSCLOPS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_CURSE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [667] = {
        .species = SPECIES_DODRIO,
        .moves = {MOVE_FLAIL, MOVE_ENDURE, MOVE_DRILL_PECK, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [668] = {
        .species = SPECIES_MR_MIME,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [669] = {
        .species = SPECIES_LANTURN,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [670] = {
        .species = SPECIES_BRELOOM,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SLUDGE_BOMB, MOVE_SPORE, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [671] = {
        .species = SPECIES_FORRETRESS,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [672] = {
        .species = SPECIES_WHISCASH,
        .moves = {MOVE_FISSURE, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [673] = {
        .species = SPECIES_XATU,
        .moves = {MOVE_PSYCHIC, MOVE_DRILL_PECK, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_PETAYA_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [674] = {
        .species = SPECIES_SKARMORY,
        .moves = {MOVE_DRILL_PECK, MOVE_STEEL_WING, MOVE_COUNTER, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [675] = {
        .species = SPECIES_MAROWAK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_SWORDS_DANCE, MOVE_MEGA_KICK},
        .itemTableId = BATTLE_FRONTIER_ITEM_THICK_CLUB,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [676] = {
        .species = SPECIES_QUAGSIRE,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_AMNESIA},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_SASSY
    },
    [677] = {
        .species = SPECIES_CLEFABLE,
        .moves = {MOVE_MEGA_KICK, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_SOFT_BOILED},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [678] = {
        .species = SPECIES_HARIYAMA,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [679] = {
        .species = SPECIES_RAICHU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_PROTECT, MOVE_MEGA_KICK},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [680] = {
        .species = SPECIES_DEWGONG,
        .moves = {MOVE_SHEER_COLD, MOVE_ICE_BEAM, MOVE_SURF, MOVE_SIGNAL_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [681] = {
        .species = SPECIES_MANECTRIC,
        .moves = {MOVE_THUNDERBOLT, MOVE_CRUNCH, MOVE_THUNDER_WAVE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [682] = {
        .species = SPECIES_VILEPLUME,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [683] = {
        .species = SPECIES_VICTREEBEL,
        .moves = {MOVE_GIGA_DRAIN, MOVE_DOUBLE_EDGE, MOVE_SLUDGE_BOMB, MOVE_SYNTHESIS},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [684] = {
        .species = SPECIES_ELECTRODE,
        .moves = {MOVE_EXPLOSION, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_NAUGHTY
    },
    [685] = {
        .species = SPECIES_EXPLOUD,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_OVERHEAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [686] = {
        .species = SPECIES_SHIFTRY,
        .moves = {MOVE_EXPLOSION, MOVE_GIGA_DRAIN, MOVE_MEGA_KICK, MOVE_FAKE_OUT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [687] = {
        .species = SPECIES_GLALIE,
        .moves = {MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [688] = {
        .species = SPECIES_LUDICOLO,
        .moves = {MOVE_LEECH_SEED, MOVE_RAIN_DANCE, MOVE_DOUBLE_TEAM, MOVE_TOXIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [689] = {
        .species = SPECIES_HYPNO,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [690] = {
        .species = SPECIES_GOLEM,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DOUBLE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [691] = {
        .species = SPECIES_RHYDON,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_HORN_DRILL},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [692] = {
        .species = SPECIES_ALAKAZAM,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [693] = {
        .species = SPECIES_WEEZING,
        .moves = {MOVE_EXPLOSION, MOVE_SLUDGE_BOMB, MOVE_FRUSTRATION, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [694] = {
        .species = SPECIES_KANGASKHAN,
        .moves = {MOVE_MEGA_KICK, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [695] = {
        .species = SPECIES_ELECTABUZZ,
        .moves = {MOVE_THUNDERBOLT, MOVE_PSYCHIC, MOVE_MEGA_KICK, MOVE_CROSS_CHOP},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [696] = {
        .species = SPECIES_TAUROS,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ROCK_TOMB, MOVE_THUNDERBOLT, MOVE_SURF},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [697] = {
        .species = SPECIES_SLOWBRO,
        .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_SASSY
    },
    [698] = {
        .species = SPECIES_SLOWKING,
        .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_ICE_BEAM, MOVE_FLAMETHROWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [699] = {
        .species = SPECIES_MILTANK,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_CURSE, MOVE_DOUBLE_TEAM, MOVE_MILK_DRINK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [700] = {
        .species = SPECIES_ALTARIA,
        .moves = {MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_ICE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [701] = {
        .species = SPECIES_NIDOQUEEN,
        .moves = {MOVE_SUPERPOWER, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [702] = {
        .species = SPECIES_NIDOKING,
        .moves = {MOVE_MEGAHORN, MOVE_SLUDGE_BOMB, MOVE_EARTHQUAKE, MOVE_THUNDER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [703] = {
        .species = SPECIES_MAGMAR,
        .moves = {MOVE_FLAMETHROWER, MOVE_PSYCHIC, MOVE_CROSS_CHOP, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [704] = {
        .species = SPECIES_CRADILY,
        .moves = {MOVE_TOXIC, MOVE_INGRAIN, MOVE_MIRROR_COAT, MOVE_GIGA_DRAIN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [705] = {
        .species = SPECIES_ARMALDO,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [706] = {
        .species = SPECIES_GOLDUCK,
        .moves = {MOVE_SURF, MOVE_CROSS_CHOP, MOVE_ICE_BEAM, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [707] = {
        .species = SPECIES_RAPIDASH,
        .moves = {MOVE_OVERHEAT, MOVE_DOUBLE_EDGE, MOVE_IRON_TAIL, MOVE_DOUBLE_KICK},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [708] = {
        .species = SPECIES_MUK,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_BRICK_BREAK, MOVE_GIGA_DRAIN, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_BRAVE
    },
    [709] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [710] = {
        .species = SPECIES_AMPHAROS,
        .moves = {MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_THUNDER_WAVE, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [711] = {
        .species = SPECIES_SCIZOR,
        .moves = {MOVE_SILVER_WIND, MOVE_SWORDS_DANCE, MOVE_AGILITY, MOVE_BATON_PASS},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [712] = {
        .species = SPECIES_HERACROSS,
        .moves = {MOVE_MEGAHORN, MOVE_EARTHQUAKE, MOVE_REVERSAL, MOVE_ENDURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [713] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [714] = {
        .species = SPECIES_HOUNDOOM,
        .moves = {MOVE_OVERHEAT, MOVE_SOLAR_BEAM, MOVE_CRUNCH, MOVE_SUNNY_DAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [715] = {
        .species = SPECIES_DONPHAN,
        .moves = {MOVE_FISSURE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_IRON_TAIL},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [716] = {
        .species = SPECIES_CLAYDOL,
        .moves = {MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [717] = {
        .species = SPECIES_WAILORD,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_FISSURE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [718] = {
        .species = SPECIES_NINETALES,
        .moves = {MOVE_OVERHEAT, MOVE_DOUBLE_EDGE, MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_QUIRKY
    },
    [719] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_FLAMETHROWER, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [720] = {
        .species = SPECIES_SHUCKLE,
        .moves = {MOVE_TOXIC, MOVE_DOUBLE_TEAM, MOVE_WRAP, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_CAREFUL
    },
    [721] = {
        .species = SPECIES_STEELIX,
        .moves = {MOVE_EARTHQUAKE, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [722] = {
        .species = SPECIES_TENTACRUEL,
        .moves = {MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIRKY
    },
    [723] = {
        .species = SPECIES_AERODACTYL,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST, MOVE_BITE},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [724] = {
        .species = SPECIES_PORYGON2,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [725] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [726] = {
        .species = SPECIES_EXEGGUTOR,
        .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [727] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [728] = {
        .species = SPECIES_FLYGON,
        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_DOUBLE_EDGE, MOVE_CRUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [729] = {
        .species = SPECIES_VENUSAUR,
        .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [730] = {
        .species = SPECIES_VAPOREON,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_ACID_ARMOR, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [731] = {
        .species = SPECIES_JOLTEON,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_BITE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_TIMID
    },
    [732] = {
        .species = SPECIES_FLAREON,
        .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [733] = {
        .species = SPECIES_MEGANIUM,
        .moves = {MOVE_GIGA_DRAIN, MOVE_EARTHQUAKE, MOVE_ANCIENT_POWER, MOVE_BODY_SLAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [734] = {
        .species = SPECIES_ESPEON,
        .moves = {MOVE_PSYCHIC, MOVE_BITE, MOVE_ATTRACT, MOVE_CALM_MIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [735] = {
        .species = SPECIES_UMBREON,
        .moves = {MOVE_CONFUSE_RAY, MOVE_TOXIC, MOVE_FAINT_ATTACK, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [736] = {
        .species = SPECIES_BLASTOISE,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [737] = {
        .species = SPECIES_FERALIGATR,
        .moves = {MOVE_HYDRO_PUMP, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [738] = {
        .species = SPECIES_AGGRON,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [739] = {
        .species = SPECIES_BLAZIKEN,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [740] = {
        .species = SPECIES_WALREIN,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_EARTHQUAKE, MOVE_SHEER_COLD},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [741] = {
        .species = SPECIES_SCEPTILE,
        .moves = {MOVE_LEAF_BLADE, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_THUNDER_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [742] = {
        .species = SPECIES_CHARIZARD,
        .moves = {MOVE_OVERHEAT, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [743] = {
        .species = SPECIES_TYPHLOSION,
        .moves = {MOVE_OVERHEAT, MOVE_THUNDER_PUNCH, MOVE_EARTHQUAKE, MOVE_CRUSH_CLAW},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [744] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_PSYCHIC},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [745] = {
        .species = SPECIES_CROBAT,
        .moves = {MOVE_SLUDGE_BOMB, MOVE_AERIAL_ACE, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [746] = {
        .species = SPECIES_SWAMPERT,
        .moves = {MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [747] = {
        .species = SPECIES_GYARADOS,
        .moves = {MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_DRAGON_DANCE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [748] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_CURSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [749] = {
        .species = SPECIES_KINGDRA,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_ICE_BEAM, MOVE_DRAGON_DANCE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [750] = {
        .species = SPECIES_BLISSEY,
        .moves = {MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_COUNTER, MOVE_SOFT_BOILED},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_BOLD
    },
    [751] = {
        .species = SPECIES_MILOTIC,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RECOVER, MOVE_MIRROR_COAT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [752] = {
        .species = SPECIES_ARCANINE,
        .moves = {MOVE_OVERHEAT, MOVE_EXTREME_SPEED, MOVE_CRUNCH, MOVE_DOUBLE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [753] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [754] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_PSYCHIC, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [755] = {
        .species = SPECIES_SLAKING,
        .moves = {MOVE_THUNDERBOLT, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_YAWN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,
        .nature = NATURE_MODEST
    },
    [756] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_ICE_BEAM, MOVE_WATER_PULSE, MOVE_ICY_WIND, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [757] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_THUNDER_WAVE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [758] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FLAMETHROWER, MOVE_AERIAL_ACE, MOVE_MUD_SLAP, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [759] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_CALM_MIND, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [760] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FLAMETHROWER, MOVE_DOUBLE_TEAM, MOVE_CALM_MIND, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [761] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_DOUBLE_TEAM, MOVE_CALM_MIND, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [762] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_SUPERPOWER, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [763] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_AMNESIA, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [764] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_METAL_CLAW, MOVE_CURSE, MOVE_AMNESIA, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [765] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_DRAGON_CLAW},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [766] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_DRAGON_CLAW},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [767] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_SUBSTITUTE, MOVE_TOXIC, MOVE_BLIZZARD, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [768] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_DRILL_PECK, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [769] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_AERIAL_ACE, MOVE_DOUBLE_TEAM, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [770] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_DOUBLE_TEAM, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [771] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [772] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_TOXIC, MOVE_DIVE, MOVE_DOUBLE_TEAM, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [773] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_COUNTER, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [774] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_BLIZZARD, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [775] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [776] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [777] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [778] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_ICE_BEAM, MOVE_FACADE, MOVE_AERIAL_ACE, MOVE_PROTECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [779] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_THUNDER_WAVE, MOVE_SUBSTITUTE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [780] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_FIRE_BLAST, MOVE_SUNNY_DAY, MOVE_DOUBLE_TEAM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [781] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_QUICK_ATTACK, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [782] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FLAMETHROWER, MOVE_DOUBLE_EDGE, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [783] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_RAIN_DANCE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [784] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE, MOVE_CURSE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [785] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_QUIET
    },
    [786] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_ANCIENT_POWER, MOVE_AMNESIA, MOVE_COUNTER, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [787] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [788] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [789] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_DOUBLE_EDGE, MOVE_REST, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [790] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_THUNDER_WAVE, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [791] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_DOUBLE_EDGE, MOVE_STEEL_WING, MOVE_SAFEGUARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_QUIET
    },
    [792] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_BITE, MOVE_THUNDER_WAVE, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [793] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FLAMETHROWER, MOVE_BITE, MOVE_DOUBLE_TEAM, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [794] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_BITE, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [795] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_CAREFUL
    },
    [796] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_HAIL, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [797] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_ANCIENT_POWER, MOVE_EARTHQUAKE, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_IMPISH
    },
    [798] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_SHADOW_BALL, MOVE_CHARM, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [799] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, MOVE_DRAGON_CLAW},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [800] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [801] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [802] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [803] = {
        .species = SPECIES_GENGAR,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_PUNCH, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [804] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_MEGA_KICK, MOVE_AERIAL_ACE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHOICE_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [805] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_HYPER_BEAM, MOVE_YAWN, MOVE_SWORDS_DANCE, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [806] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_BULK_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [807] = {
        .species = SPECIES_URSARING,
        .moves = {MOVE_FACADE, MOVE_EARTHQUAKE, MOVE_CRUNCH, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [808] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [809] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_CROSS_CHOP, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_ROCK_TOMB},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [810] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_ATTRACT, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [811] = {
        .species = SPECIES_MACHAMP,
        .moves = {MOVE_REVENGE, MOVE_ROCK_SLIDE, MOVE_FACADE, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [812] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ENDURE, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [813] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_WILL_O_WISP, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,
        .nature = NATURE_TIMID
    },
    [814] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_CALM_MIND, MOVE_WILL_O_WISP, MOVE_DESTINY_BOND},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BOLD
    },
    [815] = {
        .species = SPECIES_GARDEVOIR,
        .moves = {MOVE_PSYCHIC, MOVE_MAGICAL_LEAF, MOVE_ATTRACT, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [816] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_RECOVER, MOVE_LIGHT_SCREEN},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [817] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_THUNDER_WAVE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [818] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_COSMIC_POWER, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [819] = {
        .species = SPECIES_STARMIE,
        .moves = {MOVE_SURF, MOVE_THUNDERBOLT, MOVE_COSMIC_POWER, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [820] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_IRON_TAIL, MOVE_DOUBLE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [821] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_HYDRO_PUMP, MOVE_THUNDER, MOVE_RAIN_DANCE, MOVE_BLIZZARD},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [822] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_REST, MOVE_SLEEP_TALK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEPPA_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [823] = {
        .species = SPECIES_LAPRAS,
        .moves = {MOVE_SHEER_COLD, MOVE_HORN_DRILL, MOVE_SING, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_CALM
    },
    [824] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [825] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [826] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_HYPER_BEAM, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_CURSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [827] = {
        .species = SPECIES_SNORLAX,
        .moves = {MOVE_RETURN, MOVE_SHADOW_BALL, MOVE_BELLY_DRUM, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [828] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FACADE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [829] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_HEADBUTT, MOVE_AERIAL_ACE, MOVE_CRUNCH, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_HARDY
    },
    [830] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [831] = {
        .species = SPECIES_SALAMENCE,
        .moves = {MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [832] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_JOLLY
    },
    [833] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_PSYCHIC, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [834] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_ICE_PUNCH, MOVE_THUNDER_PUNCH},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [835] = {
        .species = SPECIES_METAGROSS,
        .moves = {MOVE_METEOR_MASH, MOVE_EARTHQUAKE, MOVE_BRICK_BREAK, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [836] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_HYPER_BEAM, MOVE_FOCUS_PUNCH, MOVE_ROCK_SLIDE, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [837] = {
        .species = SPECIES_REGIROCK,
        .moves = {MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_ROCK_SLIDE, MOVE_EXPLOSION},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [838] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_CURSE, MOVE_COUNTER},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_BRAVE
    },
    [839] = {
        .species = SPECIES_REGICE,
        .moves = {MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_SLEEP_TALK, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [840] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_FOCUS_PUNCH, MOVE_SUBSTITUTE, MOVE_TOXIC, MOVE_DOUBLE_TEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [841] = {
        .species = SPECIES_REGISTEEL,
        .moves = {MOVE_SUPERPOWER, MOVE_AERIAL_ACE, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [842] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDER_WAVE, MOVE_CALM_MIND, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [843] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_MIST_BALL, MOVE_DRAGON_CLAW, MOVE_ATTRACT, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [844] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_SWAGGER, MOVE_PSYCH_UP},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [845] = {
        .species = SPECIES_LATIAS,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [846] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDER_WAVE, MOVE_CALM_MIND, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [847] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_LUSTER_PURGE, MOVE_SHADOW_BALL, MOVE_DRAGON_CLAW, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [848] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_DRAGON_DANCE, MOVE_RECOVER},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [849] = {
        .species = SPECIES_LATIOS,
        .moves = {MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE},
        .itemTableId = BATTLE_FRONTIER_ITEM_KINGS_ROCK,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [850] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [851] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_EARTHQUAKE, MOVE_DOUBLE_EDGE, MOVE_AERIAL_ACE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [852] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HYPER_BEAM, MOVE_ATTRACT, MOVE_DOUBLE_TEAM, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LEFTOVERS,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,
        .nature = NATURE_ADAMANT
    },
    [853] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_HYPER_BEAM, MOVE_THUNDER_WAVE, MOVE_DRAGON_DANCE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [854] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_OUTRAGE, MOVE_DOUBLE_EDGE, MOVE_THUNDER_WAVE, MOVE_ROAR},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [855] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_SURF, MOVE_FLAMETHROWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [856] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_THUNDERBOLT, MOVE_SURF, MOVE_ICE_BEAM},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [857] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_DRAGON_CLAW, MOVE_FLAMETHROWER, MOVE_ICE_BEAM, MOVE_BRICK_BREAK},
        .itemTableId = BATTLE_FRONTIER_ITEM_SHELL_BELL,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [858] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_THUNDER, MOVE_SURF, MOVE_RAIN_DANCE, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [859] = {
        .species = SPECIES_DRAGONITE,
        .moves = {MOVE_FIRE_BLAST, MOVE_BLIZZARD, MOVE_SUNNY_DAY, MOVE_EARTHQUAKE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_DOCILE
    },
    [860] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_THUNDERBOLT, MOVE_SURF},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [861] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_THUNDERBOLT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [862] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_COUNTER, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [863] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_ICE_BEAM, MOVE_THUNDERBOLT, MOVE_FLAMETHROWER},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [864] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DRAGON_DANCE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [865] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_CURSE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [866] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_BRICK_BREAK, MOVE_CURSE},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [867] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_ROCK_SLIDE, MOVE_THUNDER_WAVE, MOVE_DRAGON_DANCE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [868] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_ATTRACT},
        .itemTableId = BATTLE_FRONTIER_ITEM_QUICK_CLAW,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_HARDY
    },
    [869] = {
        .species = SPECIES_TYRANITAR,
        .moves = {MOVE_DOUBLE_EDGE, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_DRAGON_DANCE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_ADAMANT
    },
    [870] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_BLIZZARD, MOVE_DOUBLE_EDGE, MOVE_AGILITY, MOVE_SWAGGER},
        .itemTableId = BATTLE_FRONTIER_ITEM_FOCUS_BAND,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [871] = {
        .species = SPECIES_ARTICUNO,
        .moves = {MOVE_ICE_BEAM, MOVE_AERIAL_ACE, MOVE_REFLECT, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [872] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_DOUBLE_EDGE, MOVE_THUNDER_WAVE},
        .itemTableId = BATTLE_FRONTIER_ITEM_SCOPE_LENS,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [873] = {
        .species = SPECIES_ZAPDOS,
        .moves = {MOVE_THUNDER, MOVE_DRILL_PECK, MOVE_RAIN_DANCE, MOVE_DOUBLE_EDGE},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [874] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_SWAGGER, MOVE_FACADE},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_DOCILE
    },
    [875] = {
        .species = SPECIES_MOLTRES,
        .moves = {MOVE_OVERHEAT, MOVE_DOUBLE_EDGE, MOVE_AERIAL_ACE, MOVE_STEEL_WING},
        .itemTableId = BATTLE_FRONTIER_ITEM_WHITE_HERB,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,
        .nature = NATURE_DOCILE
    },
    [876] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_DOUBLE_EDGE, MOVE_ROAR, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_BRIGHT_POWDER,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,
        .nature = NATURE_MODEST
    },
    [877] = {
        .species = SPECIES_RAIKOU,
        .moves = {MOVE_THUNDERBOLT, MOVE_CALM_MIND, MOVE_SUBSTITUTE, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [878] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FIRE_BLAST, MOVE_DOUBLE_EDGE, MOVE_ENDURE, MOVE_REFLECT},
        .itemTableId = BATTLE_FRONTIER_ITEM_SALAC_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_DOCILE
    },
    [879] = {
        .species = SPECIES_ENTEI,
        .moves = {MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_ROAR, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,
        .nature = NATURE_MODEST
    },
    [880] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_ICY_WIND},
        .itemTableId = BATTLE_FRONTIER_ITEM_LUM_BERRY,
        .evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    },
    [881] = {
        .species = SPECIES_SUICUNE,
        .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_CALM_MIND, MOVE_REST},
        .itemTableId = BATTLE_FRONTIER_ITEM_CHESTO_BERRY,
        .evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,
        .nature = NATURE_MODEST
    }
};
