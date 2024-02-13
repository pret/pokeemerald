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
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 120 : 200, // Amount of HP to recover
};

const u8 gItemEffect_SuperPotion[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 60 : 50, // Amount of HP to recover
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
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 30 : 50, // Amount of HP to recover
};

const u8 gItemEffect_SodaPop[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 50 : 60, // Amount of HP to recover
};

const u8 gItemEffect_Lemonade[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 70 : 80, // Amount of HP to recover
};

const u8 gItemEffect_MoomooMilk[7] = {
    [4] = ITEM4_HEAL_HP,
    [6] = 100, // Amount of HP to recover
};

const u8 gItemEffect_EnergyPowder[10] = {
    [4] = ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 60 : 50, // Amount of HP to recover
    [7] = -5, // Friendship change, low
    [8] = -5, // Friendship change, mid
    [9] = -10, // Friendship change, high
};

const u8 gItemEffect_EnergyRoot[10] = {
    [4] = ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 120 : 200, // Amount of HP to recover
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

const u8 gItemEffect_Remedy[10] = {
    [4] = ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = 20, // Amount of HP to recover
    [7] = -5, // Friendship change, low
    [8] = -5, // Friendship change, mid
    [9] = -10, // Friendship change, high
};

const u8 gItemEffect_FineRemedy[10] = {
    [4] = ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 60 : 50, // Amount of HP to recover
    [7] = -10, // Friendship change, low
    [8] = -10, // Friendship change, mid
    [9] = -15, // Friendship change, high
};

const u8 gItemEffect_SuperbRemedy[10] = {
    [4] = ITEM4_HEAL_HP,
    [5] = ITEM5_FRIENDSHIP_ALL,
    [6] = I_HEALTH_RECOVERY >= GEN_7 ? 120 : 200, // Amount of HP to recover
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

const u8 gItemEffect_YellowFlute[6] = {
    [3] = ITEM3_CONFUSION,
};

const u8 gItemEffect_RedFlute[6] = {
    [0] = ITEM0_INFATUATION,
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

const u8 gItemEffect_HpMochi[11] = {
    [4] = ITEM4_EV_HP,
    [6] = ITEM6_ADD_EV,
    [10] = 0,
};

const u8 gItemEffect_AtkMochi[11] = {
    [4] = ITEM4_EV_ATK,
    [6] = ITEM6_ADD_EV,
    [10] = 0,
};

const u8 gItemEffect_DefMochi[11] = {
    [5] = ITEM5_EV_DEF,
    [6] = ITEM6_ADD_EV,
    [10] = 0,
};

const u8 gItemEffect_SpeedMochi[11] = {
    [5] = ITEM5_EV_SPEED,
    [6] = ITEM6_ADD_EV,
    [10] = 0,
};

const u8 gItemEffect_SpatkMochi[11] = {
    [5] = ITEM5_EV_SPATK,
    [6] = ITEM6_ADD_EV,
    [10] = 0,
};

const u8 gItemEffect_SpdefMochi[11] = {
    [5] = ITEM5_EV_SPDEF,
    [6] = ITEM6_ADD_EV,
    [10] = 0,
};

const u8 gItemEffect_ResetMochi[11] = {
    [4] = ITEM4_EV_HP | ITEM4_EV_ATK,
    [5] = ITEM5_EV_DEF | ITEM5_EV_SPEED | ITEM5_EV_SPATK | ITEM5_EV_SPDEF,
    [6] = ITEM6_RESET_EV,
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
