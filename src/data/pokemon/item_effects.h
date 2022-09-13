const u8 gItemEffect_Potion[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = 20, // Amount of HP to recover
};

const u8 gItemEffect_Antidote[6] = {
    [3] = ITEM3_POISON,
};

const u8 gItemEffect_BurnHeal[6] = {
    [3] = ITEM3_BURN,
};

const u8 gItemEffect_IceHeal[6] = {
    [3] = ITEM3_FREEZE,
};

const u8 gItemEffect_Awakening[6] = {
    [3] = ITEM3_SLEEP,
};

const u8 gItemEffect_ParalyzeHeal[6] = {
    [3] = ITEM3_PARALYSIS,
};

const u8 gItemEffect_FullRestore[7] = {
    [3] = ITEM3_STATUS_ALL,
    [4] = ITEM4_HEAL_HP,
    [6] = ITEM6_HEAL_HP_FULL,
};

const u8 gItemEffect_MaxPotion[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = ITEM6_HEAL_HP_FULL,
};

const u8 gItemEffect_HyperPotion[7] = {
    [4] = ITEM4_HEAL_HP,
#if I_HEALTH_RECOVERY >= GEN_7
    [6] = 120, // Amount of HP to recover
#else
    [6] = 200, // Amount of HP to recover
#endif
};

const u8 gItemEffect_SuperPotion[7] = {
    [4] = ITEM4_HEAL_HP,
#if I_HEALTH_RECOVERY >= GEN_7
    [6] = 60, // Amount of HP to recover
#else
    [6] = 50, // Amount of HP to recover
#endif
};

const u8 gItemEffect_FullHeal[6] = {
    [3] = ITEM3_STATUS_ALL,
};

const u8 gItemEffect_Revive[7] = {
    [4] = ITEM4_REVIVE | ITEM4_HEAL_HP,
    [6] = ITEM6_HEAL_HP_HALF,
};

const u8 gItemEffect_MaxRevive[7] = {
    [4] = ITEM4_REVIVE | ITEM4_HEAL_HP,
    [6] = ITEM6_HEAL_HP_FULL,
};

const u8 gItemEffect_FreshWater[7] = {
    [4] = ITEM4_HEAL_HP,
#if I_HEALTH_RECOVERY >= GEN_7
    [6] = 30, // Amount of HP to recover
#else
    [6] = 50, // Amount of HP to recover
#endif
};

const u8 gItemEffect_SodaPop[7] = {
    [4] = ITEM4_HEAL_HP,
#if I_HEALTH_RECOVERY >= GEN_7
    [6] = 50, // Amount of HP to recover
#else
    [6] = 60, // Amount of HP to recover
#endif
};

const u8 gItemEffect_Lemonade[7] = {
    [4] = ITEM4_HEAL_HP,
#if I_HEALTH_RECOVERY >= GEN_7
    [6] = 70, // Amount of HP to recover
#else
    [6] = 80, // Amount of HP to recover
#endif
};

const u8 gItemEffect_MoomooMilk[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = 100, // Amount of HP to recover
};

const u8 gItemEffect_EnergyPowder[10] = {
    [4] = ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
#if I_HEALTH_RECOVERY >= GEN_7
    [6] = 60, // Amount of HP to recover
#else
    [6] = 50, // Amount of HP to recover
#endif
    [7] = -5, // Friendship change, low
    [8] = -5, // Friendship change, mid
    [9] = -10, // Friendship change, high
};

const u8 gItemEffect_EnergyRoot[10] = {
    [4] = ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
#if I_HEALTH_RECOVERY >= GEN_7
    [6] = 120, // Amount of HP to recover
#else
    [6] = 200, // Amount of HP to recover
#endif
    [7] = -10, // Friendship change, low
    [8] = -10, // Friendship change, mid
    [9] = -15, // Friendship change, high
};

const u8 gItemEffect_HealPowder[9] = {
    [3] = ITEM3_STATUS_ALL,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = -5,  // Friendship change, low
    [7] = -5,  // Friendship change, mid
    [8] = -10, // Friendship change, high
};

const u8 gItemEffect_RevivalHerb[10] = {
    [4] = ITEM4_REVIVE | ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_HEAL_HP_FULL,
    [7] = -15, // Friendship change, low
    [8] = -15, // Friendship change, mid
    [9] = -20, // Friendship change, high
};

const u8 gItemEffect_Ether[7] = {
    [4] = ITEM4_HEAL_PP_ONE | ITEM4_HEAL_PP,
    [6] = 10,
};

const u8 gItemEffect_MaxEther[7] = {
    [4] = ITEM4_HEAL_PP_ONE | ITEM4_HEAL_PP,
    [6] = ITEM6_HEAL_PP_FULL,
};

const u8 gItemEffect_Elixir[7] = {
    [4] = ITEM4_HEAL_PP,
    [6] = 10, // Amount of PP to recover
};

const u8 gItemEffect_MaxElixir[7] = {
    [4] = ITEM4_HEAL_PP,
    [6] = ITEM6_HEAL_PP_FULL,
};

const u8 gItemEffect_BlueFlute[6] = {
    [3] = ITEM3_SLEEP,
};

const u8 gItemEffect_YellowFlute[6] = {
    [3] = ITEM3_CONFUSION,
};

const u8 gItemEffect_RedFlute[6] = {
    [0] = ITEM0_INFATUATION,
};

const u8 gItemEffect_BerryJuice[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = 20, // Amount of HP to recover
};

const u8 gItemEffect_SacredAsh[7] = {
    [0] = ITEM0_SACRED_ASH,
    [4] = ITEM4_REVIVE | ITEM4_HEAL_HP,
    [6] = ITEM6_HEAL_HP_FULL,
};

#define VITAMIN_FRIENDSHIP_CHANGE(i)             \
    [(i) + 0] = 5, /* Friendship change, low */  \
    [(i) + 1] = 3, /* Friendship change, mid */  \
    [(i) + 2] = 2  /* Friendship change, high */

const u8 gItemEffect_HPUp[11] = {
    [4] = ITEM4_EV_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_EV,
    VITAMIN_FRIENDSHIP_CHANGE(7),
    [10] = ITEM10_IS_VITAMIN,
};

const u8 gItemEffect_Protein[11] = {
    [4] = ITEM4_EV_ATK,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_EV,
    VITAMIN_FRIENDSHIP_CHANGE(7),
    [10] = ITEM10_IS_VITAMIN,
};

const u8 gItemEffect_Iron[11] = {
    [5] = ITEM5_EV_DEF | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_EV,
    VITAMIN_FRIENDSHIP_CHANGE(7),
    [10] = ITEM10_IS_VITAMIN,
};

const u8 gItemEffect_Carbos[11] = {
    [5] = ITEM5_EV_SPEED | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_EV,
    VITAMIN_FRIENDSHIP_CHANGE(7),
    [10] = ITEM10_IS_VITAMIN,
};

const u8 gItemEffect_Calcium[11] = {
    [5] = ITEM5_EV_SPATK | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_EV,
    VITAMIN_FRIENDSHIP_CHANGE(7),
    [10] = ITEM10_IS_VITAMIN,
};

const u8 gItemEffect_Zinc[11] = {
    [5] = ITEM5_EV_SPDEF | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_EV,
    VITAMIN_FRIENDSHIP_CHANGE(7),
    [10] = ITEM10_IS_VITAMIN,
};

#define FEATHER_FRIENDSHIP_CHANGE(i)             \
    [(i) + 0] = 3, /* Friendship change, low */  \
    [(i) + 1] = 2, /* Friendship change, mid */  \
    [(i) + 2] = 1  /* Friendship change, high */

const u8 gItemEffect_HpFeather[11] = {
    [4] = ITEM4_EV_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_ONE_EV,
    FEATHER_FRIENDSHIP_CHANGE(7),
    [10] = 0,
};

const u8 gItemEffect_AtkFeather[11] = {
    [4] = ITEM4_EV_ATK,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_ONE_EV,
    FEATHER_FRIENDSHIP_CHANGE(7),
    [10] = 0,
};

const u8 gItemEffect_DefFeather[11] = {
    [5] = ITEM5_EV_DEF | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_ONE_EV,
    FEATHER_FRIENDSHIP_CHANGE(7),
    [10] = 0,
};

const u8 gItemEffect_SpeedFeather[11] = {
    [5] = ITEM5_EV_SPEED | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_ONE_EV,
    FEATHER_FRIENDSHIP_CHANGE(7),
    [10] = 0,
};

const u8 gItemEffect_SpatkFeather[11] = {
    [5] = ITEM5_EV_SPATK | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_ONE_EV,
    FEATHER_FRIENDSHIP_CHANGE(7),
    [10] = 0,
};

const u8 gItemEffect_SpdefFeather[11] = {
    [5] = ITEM5_EV_SPDEF | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_ADD_ONE_EV,
    FEATHER_FRIENDSHIP_CHANGE(7),
    [10] = 0,
};

const u8 gItemEffect_RareCandy[10] = {
    [3] = ITEM3_LEVEL_UP,
    [4] = ITEM4_REVIVE | ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_HEAL_HP_LVL_UP,
    VITAMIN_FRIENDSHIP_CHANGE(7),
};

const u8 gItemEffect_PPUp[9] = {
    [4] = ITEM4_PP_UP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    VITAMIN_FRIENDSHIP_CHANGE(6),
};

const u8 gItemEffect_PPMax[9] = {
    [5] = ITEM5_PP_MAX | ITEM5_FRIENDSHIP_ALL,
    VITAMIN_FRIENDSHIP_CHANGE(6),
};

#define STAT_BOOST_FRIENDSHIP_CHANGE      \
    [6] = 1, /* Friendship change, low */ \
    [7] = 1  /* Friendship change, mid */

const u8 gItemEffect_GuardSpec[8] = {
    [3] = ITEM3_GUARD_SPEC,
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

// The first item effect value for the stat boost items
// only uses the least significant bit of its full mask.
// The full constant is commented next to it

const u8 gItemEffect_DireHit[8] = {
    [0] = 1 << 5, // ITEM0_DIRE_HIT
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_XAttack[8] = {
    [1] = ITEM1_X_ATTACK,
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_XDefense[8] = {
    [1] = ITEM1_X_DEFENSE,
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_XSpeed[8] = {
    [1] = ITEM1_X_SPEED,
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_XAccuracy[8] = {
    [1] = ITEM1_X_ACCURACY,
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_XSpecialAttack[8] = {
    [1] = ITEM1_X_SPATK,
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_XSpecialDefense[8] = {
    [1] = ITEM1_X_SPDEF,
    [5] = ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID,
    STAT_BOOST_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_EvoItem[6] = {
    [4] = ITEM4_EVO_STONE,
};

const u8 gItemEffect_CheriBerry[6] = {
    [3] = ITEM3_PARALYSIS,
};

const u8 gItemEffect_ChestoBerry[6] = {
    [3] = ITEM3_SLEEP,
};

const u8 gItemEffect_PechaBerry[6] = {
    [3] = ITEM3_POISON,
};

const u8 gItemEffect_RawstBerry[6] = {
    [3] = ITEM3_BURN,
};

const u8 gItemEffect_AspearBerry[6] = {
    [3] = ITEM3_FREEZE,
};

const u8 gItemEffect_LeppaBerry[7] = {
    [4] = ITEM4_HEAL_PP_ONE | ITEM4_HEAL_PP,
    [6] = 10, // Amount of PP to recover
};

const u8 gItemEffect_OranBerry[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = 10, // Amount of HP to recover
};

const u8 gItemEffect_PersimBerry[6] = {
    [3] = ITEM3_CONFUSION,
};

const u8 gItemEffect_SitrusBerry[7] = {
    [4] = ITEM4_HEAL_HP,
#if I_SITRUS_BERRY_HEAL >= GEN_4
    [6] = ITEM6_HEAL_HP_QUARTER,
#else
    [6] = 30, // Amount of HP to recover
#endif
};

#define EV_BERRY_FRIENDSHIP_CHANGE          \
    [7] = 10, /* Friendship change, low */  \
    [8] = 5,  /* Friendship change, mid */  \
    [9] = 2   /* Friendship change, high */

const u8 gItemEffect_PomegBerry[10] = {
    [4] = ITEM4_EV_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_SUBTRACT_EV,
    EV_BERRY_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_KelpsyBerry[10] = {
    [4] = ITEM4_EV_ATK,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_SUBTRACT_EV,
    EV_BERRY_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_QualotBerry[10] = {
    [5] = ITEM5_EV_DEF | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_SUBTRACT_EV,
    EV_BERRY_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_HondewBerry[10] = {
    [5] = ITEM5_EV_SPATK | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_SUBTRACT_EV,
    EV_BERRY_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_GrepaBerry[10] = {
    [5] = ITEM5_EV_SPDEF | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_SUBTRACT_EV,
    EV_BERRY_FRIENDSHIP_CHANGE,
};

const u8 gItemEffect_TamatoBerry[10] = {
    [5] = ITEM5_EV_SPEED | ITEM5_FRIENDSHIP_ALL,
    [6] = ITEM6_SUBTRACT_EV,
    EV_BERRY_FRIENDSHIP_CHANGE,
};

const u8 *const gItemEffectTable[] =
{
    // Medicine
    [ITEM_POTION - ITEM_POTION]           = gItemEffect_Potion,
    [ITEM_SUPER_POTION - ITEM_POTION]     = gItemEffect_SuperPotion,
    [ITEM_HYPER_POTION - ITEM_POTION]     = gItemEffect_HyperPotion,
    [ITEM_MAX_POTION - ITEM_POTION]       = gItemEffect_MaxPotion,
    [ITEM_FULL_RESTORE - ITEM_POTION]     = gItemEffect_FullRestore,
    [ITEM_REVIVE - ITEM_POTION]           = gItemEffect_Revive,
    [ITEM_MAX_REVIVE - ITEM_POTION]       = gItemEffect_MaxRevive,
    [ITEM_FRESH_WATER - ITEM_POTION]      = gItemEffect_FreshWater,
    [ITEM_SODA_POP - ITEM_POTION]         = gItemEffect_SodaPop,
    [ITEM_LEMONADE - ITEM_POTION]         = gItemEffect_Lemonade,
    [ITEM_MOOMOO_MILK - ITEM_POTION]      = gItemEffect_MoomooMilk,
    [ITEM_ENERGY_POWDER - ITEM_POTION]    = gItemEffect_EnergyPowder,
    [ITEM_ENERGY_ROOT - ITEM_POTION]      = gItemEffect_EnergyRoot,
    [ITEM_HEAL_POWDER - ITEM_POTION]      = gItemEffect_HealPowder,
    [ITEM_REVIVAL_HERB - ITEM_POTION]     = gItemEffect_RevivalHerb,
    [ITEM_ANTIDOTE - ITEM_POTION]         = gItemEffect_Antidote,
    [ITEM_PARALYZE_HEAL - ITEM_POTION]    = gItemEffect_ParalyzeHeal,
    [ITEM_BURN_HEAL - ITEM_POTION]        = gItemEffect_BurnHeal,
    [ITEM_ICE_HEAL - ITEM_POTION]         = gItemEffect_IceHeal,
    [ITEM_AWAKENING - ITEM_POTION]        = gItemEffect_Awakening,
    [ITEM_FULL_HEAL - ITEM_POTION]        = gItemEffect_FullHeal,
    [ITEM_ETHER - ITEM_POTION]            = gItemEffect_Ether,
    [ITEM_MAX_ETHER - ITEM_POTION]        = gItemEffect_MaxEther,
    [ITEM_ELIXIR - ITEM_POTION]           = gItemEffect_Elixir,
    [ITEM_MAX_ELIXIR - ITEM_POTION]       = gItemEffect_MaxElixir,
    [ITEM_BERRY_JUICE - ITEM_POTION]      = gItemEffect_BerryJuice,
    [ITEM_SACRED_ASH - ITEM_POTION]       = gItemEffect_SacredAsh,
    [ITEM_SWEET_HEART - ITEM_POTION]      = gItemEffect_Potion,
    [ITEM_MAX_HONEY - ITEM_POTION]        = gItemEffect_MaxRevive,

    // Regional Specialties
    [ITEM_PEWTER_CRUNCHIES - ITEM_POTION] = gItemEffect_FullHeal,
    [ITEM_RAGE_CANDY_BAR - ITEM_POTION]   = gItemEffect_FullHeal,
    [ITEM_LAVA_COOKIE - ITEM_POTION]      = gItemEffect_FullHeal,
    [ITEM_OLD_GATEAU - ITEM_POTION]       = gItemEffect_FullHeal,
    [ITEM_CASTELIACONE - ITEM_POTION]     = gItemEffect_FullHeal,
    [ITEM_LUMIOSE_GALETTE - ITEM_POTION]  = gItemEffect_FullHeal,
    [ITEM_SHALOUR_SABLE - ITEM_POTION]    = gItemEffect_FullHeal,
    [ITEM_BIG_MALASADA - ITEM_POTION]     = gItemEffect_FullHeal,

    // Vitamins
    [ITEM_HP_UP - ITEM_POTION]            = gItemEffect_HPUp,
    [ITEM_PROTEIN - ITEM_POTION]          = gItemEffect_Protein,
    [ITEM_IRON - ITEM_POTION]             = gItemEffect_Iron,
    [ITEM_CALCIUM - ITEM_POTION]          = gItemEffect_Calcium,
    [ITEM_ZINC - ITEM_POTION]             = gItemEffect_Zinc,
    [ITEM_CARBOS - ITEM_POTION]           = gItemEffect_Carbos,
    [ITEM_PP_UP - ITEM_POTION]            = gItemEffect_PPUp,
    [ITEM_PP_MAX - ITEM_POTION]           = gItemEffect_PPMax,

    // EV Feathers
    [ITEM_HEALTH_FEATHER - ITEM_POTION]   = gItemEffect_HpFeather,
    [ITEM_MUSCLE_FEATHER - ITEM_POTION]   = gItemEffect_AtkFeather,
    [ITEM_RESIST_FEATHER - ITEM_POTION]   = gItemEffect_DefFeather,
    [ITEM_GENIUS_FEATHER - ITEM_POTION]   = gItemEffect_SpatkFeather,
    [ITEM_CLEVER_FEATHER - ITEM_POTION]   = gItemEffect_SpdefFeather,
    [ITEM_SWIFT_FEATHER - ITEM_POTION]    = gItemEffect_SpeedFeather,

    // Candy
    [ITEM_RARE_CANDY - ITEM_POTION]       = gItemEffect_RareCandy,
    [ITEM_EXP_CANDY_XS - ITEM_POTION]     = gItemEffect_RareCandy,
    [ITEM_EXP_CANDY_S - ITEM_POTION]      = gItemEffect_RareCandy,
    [ITEM_EXP_CANDY_M - ITEM_POTION]      = gItemEffect_RareCandy,
    [ITEM_EXP_CANDY_L - ITEM_POTION]      = gItemEffect_RareCandy,
    [ITEM_EXP_CANDY_XL - ITEM_POTION]     = gItemEffect_RareCandy,
    //[ITEM_DYNAMAX_CANDY - ITEM_POTION]    = gItemEffect_DynamaxCandy, // Todo

    // Medicinal Flutes
    [ITEM_BLUE_FLUTE - ITEM_POTION]       = gItemEffect_BlueFlute,
    [ITEM_YELLOW_FLUTE - ITEM_POTION]     = gItemEffect_YellowFlute,
    [ITEM_RED_FLUTE - ITEM_POTION]        = gItemEffect_RedFlute,

    // X Items
    [ITEM_X_ATTACK - ITEM_POTION]         = gItemEffect_XAttack,
    [ITEM_X_DEFENSE - ITEM_POTION]        = gItemEffect_XDefense,
    [ITEM_X_SPEED - ITEM_POTION]          = gItemEffect_XSpeed,
    [ITEM_X_ACCURACY - ITEM_POTION]       = gItemEffect_XAccuracy,
    [ITEM_X_SP_ATK - ITEM_POTION]         = gItemEffect_XSpecialAttack,
    [ITEM_X_SP_DEF - ITEM_POTION]         = gItemEffect_XSpecialDefense,

    [ITEM_DIRE_HIT - ITEM_POTION]         = gItemEffect_DireHit,
    [ITEM_GUARD_SPEC - ITEM_POTION]       = gItemEffect_GuardSpec,

    //[ITEM_MAX_MUSHROOMS - ITEM_POTION]    = gItemEffect_MaxMushrooms, // Todo

    // Evolution Items
    [ITEM_FIRE_STONE - ITEM_POTION]       = gItemEffect_EvoItem,
    [ITEM_WATER_STONE - ITEM_POTION]      = gItemEffect_EvoItem,
    [ITEM_THUNDER_STONE - ITEM_POTION]    = gItemEffect_EvoItem,
    [ITEM_LEAF_STONE - ITEM_POTION]       = gItemEffect_EvoItem,
    [ITEM_ICE_STONE - ITEM_POTION]        = gItemEffect_EvoItem,
    [ITEM_SUN_STONE - ITEM_POTION]        = gItemEffect_EvoItem,
    [ITEM_MOON_STONE - ITEM_POTION]       = gItemEffect_EvoItem,
    [ITEM_SHINY_STONE - ITEM_POTION]      = gItemEffect_EvoItem,
    [ITEM_DUSK_STONE - ITEM_POTION]       = gItemEffect_EvoItem,
    [ITEM_DAWN_STONE - ITEM_POTION]       = gItemEffect_EvoItem,
    [ITEM_SWEET_APPLE - ITEM_POTION]      = gItemEffect_EvoItem,
    [ITEM_TART_APPLE - ITEM_POTION]       = gItemEffect_EvoItem,
    [ITEM_CRACKED_POT - ITEM_POTION]      = gItemEffect_EvoItem,
    [ITEM_CHIPPED_POT - ITEM_POTION]      = gItemEffect_EvoItem,
    [ITEM_GALARICA_CUFF - ITEM_POTION]    = gItemEffect_EvoItem,
    [ITEM_GALARICA_WREATH - ITEM_POTION]  = gItemEffect_EvoItem,

    // Berries
    [ITEM_CHERI_BERRY - ITEM_POTION]      = gItemEffect_CheriBerry,
    [ITEM_CHESTO_BERRY - ITEM_POTION]     = gItemEffect_ChestoBerry,
    [ITEM_PECHA_BERRY - ITEM_POTION]      = gItemEffect_PechaBerry,
    [ITEM_RAWST_BERRY - ITEM_POTION]      = gItemEffect_RawstBerry,
    [ITEM_ASPEAR_BERRY - ITEM_POTION]     = gItemEffect_AspearBerry,
    [ITEM_LEPPA_BERRY - ITEM_POTION]      = gItemEffect_LeppaBerry,
    [ITEM_ORAN_BERRY - ITEM_POTION]       = gItemEffect_OranBerry,
    [ITEM_PERSIM_BERRY - ITEM_POTION]     = gItemEffect_PersimBerry,
    [ITEM_LUM_BERRY - ITEM_POTION]        = gItemEffect_FullHeal,
    [ITEM_SITRUS_BERRY - ITEM_POTION]     = gItemEffect_SitrusBerry,
    [ITEM_POMEG_BERRY - ITEM_POTION]      = gItemEffect_PomegBerry,
    [ITEM_KELPSY_BERRY - ITEM_POTION]     = gItemEffect_KelpsyBerry,
    [ITEM_QUALOT_BERRY - ITEM_POTION]     = gItemEffect_QualotBerry,
    [ITEM_HONDEW_BERRY - ITEM_POTION]     = gItemEffect_HondewBerry,
    [ITEM_GREPA_BERRY - ITEM_POTION]      = gItemEffect_GrepaBerry,
    [ITEM_TAMATO_BERRY - ITEM_POTION]     = gItemEffect_TamatoBerry,
    [LAST_BERRY_INDEX - ITEM_POTION]      = NULL,
};
