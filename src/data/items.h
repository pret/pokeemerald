const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = gDummyItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Pokeballs

    [ITEM_MASTER_BALL] =
    {
        .name = _("MASTER BALL"),
        .itemId = ITEM_MASTER_BALL,
        .price = 0,
        .description = gMasterBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 0,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 0,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = _("ULTRA BALL"),
        .itemId = ITEM_ULTRA_BALL,
        .price = 1200,
        .description = gUltraBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 1,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 1,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = _("GREAT BALL"),
        .itemId = ITEM_GREAT_BALL,
        .price = 600,
        .description = gGreatBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 2,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 2,
    },

    [ITEM_POKE_BALL] =
    {
        .name = _("POKé BALL"),
        .itemId = ITEM_POKE_BALL,
        .price = 200,
        .description = gPokeBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 3,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 3,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = _("SAFARI BALL"),
        .itemId = ITEM_SAFARI_BALL,
        .price = 0,
        .description = gSafariBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 4,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 4,
    },

    [ITEM_NET_BALL] =
    {
        .name = _("NET BALL"),
        .itemId = ITEM_NET_BALL,
        .price = 1000,
        .description = gNetBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 5,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 5,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = _("DIVE BALL"),
        .itemId = ITEM_DIVE_BALL,
        .price = 1000,
        .description = gDiveBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 6,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 6,
    },

    [ITEM_NEST_BALL] =
    {
        .name = _("NEST BALL"),
        .itemId = ITEM_NEST_BALL,
        .price = 1000,
        .description = gNestBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 7,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 7,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = _("REPEAT BALL"),
        .itemId = ITEM_REPEAT_BALL,
        .price = 1000,
        .description = gRepeatBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 8,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 8,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = _("TIMER BALL"),
        .itemId = ITEM_TIMER_BALL,
        .price = 1000,
        .description = gTimerBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 9,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 9,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = _("LUXURY BALL"),
        .itemId = ITEM_LUXURY_BALL,
        .price = 1000,
        .description = gLuxuryBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 10,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 10,
    },

    [ITEM_PREMIER_BALL] =
    {
        .name = _("PREMIER BALL"),
        .itemId = ITEM_PREMIER_BALL,
        .price = 200,
        .description = gPremierBallItemDescription,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 11,
    },

	[ITEM_LEVEL_BALL] =
	{
        .name = _("Level Ball"),
        .itemId = ITEM_LEVEL_BALL,
        .price = 2000,
        .description = gItemDescription_LevelBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 12,
    },

    [ITEM_LURE_BALL] =
    {
        .name = _("Lure Ball"),
        .itemId = ITEM_LURE_BALL,
        .price = 2000,
        .description = gItemDescription_LureBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 13,
    },

    [ITEM_MOON_BALL] =
    {
        .name = _("Moon Ball"),
        .itemId = ITEM_MOON_BALL,
        .price = 2000,
        .description = gItemDescription_MoonBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 14,
    },

    [ITEM_FRIEND_BALL] =
    {
        .name = _("Friend Ball"),
        .itemId = ITEM_FRIEND_BALL,
        .price = 2000,
        .description = gItemDescription_FriendBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 15,
    },

    [ITEM_LOVE_BALL] =
    {
        .name = _("Love Ball"),
        .itemId = ITEM_LOVE_BALL,
        .price = 2000,
        .description = gItemDescription_LoveBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 16,
    },

    [ITEM_HEAVY_BALL] =
    {
        .name = _("Heavy Ball"),
        .itemId = ITEM_HEAVY_BALL,
        .price = 2000,
        .description = gItemDescription_HeavyBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 17,
    },

    [ITEM_FAST_BALL] =
    {
        .name = _("Fast Ball"),
        .itemId = ITEM_FAST_BALL,
        .price = 2000,
        .description = gItemDescription_FastBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 18,
    },

    [ITEM_HEAL_BALL] =
    {
        .name = _("Heal Ball"),
        .itemId = ITEM_HEAL_BALL,
        .price = 300,
        .description = gItemDescription_HealBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 19,
    },

    [ITEM_QUICK_BALL] =
    {
        .name = _("Quick Ball"),
        .itemId = ITEM_QUICK_BALL,
        .price = 3000,
        .description = gItemDescription_QuickBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 20,
    },

    [ITEM_DUSK_BALL] =
    {
        .name = _("Dusk Ball"),
        .itemId = ITEM_DUSK_BALL,
        .price = 3000,
        .description = gItemDescription_DuskBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 21,
    },

    [ITEM_CHERISH_BALL] =
    {
        .name = _("Cherish Ball"),
        .itemId = ITEM_CHERISH_BALL,
        .price = 10,
        .description = gItemDescription_CherishBall,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .fieldUseFunc = NULL,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 22,
	},

// Medicine

    [ITEM_POTION] =
    {
        .name = _("POTION"),
        .itemId = ITEM_POTION,
        .price = 300,
        .holdEffectParam = 20,
        .description = gPotionItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = _("ANTIDOTE"),
        .itemId = ITEM_ANTIDOTE,
        .price = 100,
        .description = gAntidoteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = _("BURN HEAL"),
        .itemId = ITEM_BURN_HEAL,
        .price = 250,
        .description = gBurnHealItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = _("ICE HEAL"),
        .itemId = ITEM_ICE_HEAL,
        .price = 250,
        .description = gIceHealItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_AWAKENING] =
    {
        .name = _("AWAKENING"),
        .itemId = ITEM_AWAKENING,
        .price = 250,
        .description = gAwakeningItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = _("PARLYZ HEAL"),
        .itemId = ITEM_PARALYZE_HEAL,
        .price = 200,
        .description = gParalyzeHealItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = _("FULL RESTORE"),
        .itemId = ITEM_FULL_RESTORE,
        .price = 3000,
        .holdEffectParam = 255,
        .description = gFullRestoreItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_MAX_POTION] =
    {
        .name = _("MAX POTION"),
        .itemId = ITEM_MAX_POTION,
        .price = 2500,
        .holdEffectParam = 255,
        .description = gMaxPotionItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = _("HYPER POTION"),
        .itemId = ITEM_HYPER_POTION,
        .price = 1200,
        .holdEffectParam = 200,
        .description = gHyperPotionItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = _("SUPER POTION"),
        .itemId = ITEM_SUPER_POTION,
        .price = 700,
        .holdEffectParam = 50,
        .description = gSuperPotionItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = _("FULL HEAL"),
        .itemId = ITEM_FULL_HEAL,
        .price = 600,
        .description = gFullHealItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_REVIVE] =
    {
        .name = _("REVIVE"),
        .itemId = ITEM_REVIVE,
        .price = 1500,
        .description = gReviveItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = _("MAX REVIVE"),
        .itemId = ITEM_MAX_REVIVE,
        .price = 4000,
        .description = gMaxReviveItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = _("FRESH WATER"),
        .itemId = ITEM_FRESH_WATER,
        .price = 200,
        .holdEffectParam = 50,
        .description = gFreshWaterItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SODA_POP] =
    {
        .name = _("SODA POP"),
        .itemId = ITEM_SODA_POP,
        .price = 300,
        .holdEffectParam = 60,
        .description = gSodaPopItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_LEMONADE] =
    {
        .name = _("LEMONADE"),
        .itemId = ITEM_LEMONADE,
        .price = 350,
        .holdEffectParam = 80,
        .description = gLemonadeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = _("MOOMOO MILK"),
        .itemId = ITEM_MOOMOO_MILK,
        .price = 500,
        .holdEffectParam = 100,
        .description = gMoomooMilkItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = _("ENERGYPOWDER"),
        .itemId = ITEM_ENERGY_POWDER,
        .price = 500,
        .description = gEnergyPowderItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = _("ENERGY ROOT"),
        .itemId = ITEM_ENERGY_ROOT,
        .price = 800,
        .description = gEnergyRootItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = _("HEAL POWDER"),
        .itemId = ITEM_HEAL_POWDER,
        .price = 450,
        .description = gHealPowderItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = _("REVIVAL HERB"),
        .itemId = ITEM_REVIVAL_HERB,
        .price = 2800,
        .description = gRevivalHerbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ETHER] =
    {
        .name = _("ETHER"),
        .itemId = ITEM_ETHER,
        .price = 1200,
        .holdEffectParam = 10,
        .description = gEtherItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = _("MAX ETHER"),
        .itemId = ITEM_MAX_ETHER,
        .price = 2000,
        .holdEffectParam = 255,
        .description = gMaxEtherItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_ELIXIR] =
    {
        .name = _("ELIXIR"),
        .itemId = ITEM_ELIXIR,
        .price = 3000,
        .holdEffectParam = 10,
        .description = gElixirItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = _("MAX ELIXIR"),
        .itemId = ITEM_MAX_ELIXIR,
        .price = 4500,
        .holdEffectParam = 255,
        .description = gMaxElixirItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = _("LAVA COOKIE"),
        .itemId = ITEM_LAVA_COOKIE,
        .price = 200,
        .description = gLavaCookieItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_BLUE_FLUTE] =
    {
        .name = _("BLUE FLUTE"),
        .itemId = ITEM_BLUE_FLUTE,
        .price = 100,
        .description = gBlueFluteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = _("YELLOW FLUTE"),
        .itemId = ITEM_YELLOW_FLUTE,
        .price = 200,
        .description = gYellowFluteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = _("RED FLUTE"),
        .itemId = ITEM_RED_FLUTE,
        .price = 300,
        .description = gRedFluteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_BLACK_FLUTE] =
    {
        .name = _("BLACK FLUTE"),
        .itemId = ITEM_BLACK_FLUTE,
        .price = 400,
        .holdEffectParam = 50,
        .description = gBlackFluteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .secondaryId = 0,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = _("WHITE FLUTE"),
        .itemId = ITEM_WHITE_FLUTE,
        .price = 500,
        .holdEffectParam = 150,
        .description = gWhiteFluteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .secondaryId = 0,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = _("BERRY JUICE"),
        .itemId = ITEM_BERRY_JUICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = gBerryJuiceItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = _("SACRED ASH"),
        .itemId = ITEM_SACRED_ASH,
        .price = 200,
        .description = gSacredAshItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
        .secondaryId = 0,
    },

// Collectibles

    [ITEM_SHOAL_SALT] =
    {
        .name = _("SHOAL SALT"),
        .itemId = ITEM_SHOAL_SALT,
        .price = 20,
        .description = gShoalSaltItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = _("SHOAL SHELL"),
        .itemId = ITEM_SHOAL_SHELL,
        .price = 20,
        .description = gShoalShellItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RED_SHARD] =
    {
        .name = _("RED SHARD"),
        .itemId = ITEM_RED_SHARD,
        .price = 200,
        .description = gRedShardItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = _("BLUE SHARD"),
        .itemId = ITEM_BLUE_SHARD,
        .price = 200,
        .description = gBlueShardItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = _("YELLOW SHARD"),
        .itemId = ITEM_YELLOW_SHARD,
        .price = 200,
        .description = gYellowShardItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = _("GREEN SHARD"),
        .itemId = ITEM_GREEN_SHARD,
        .price = 200,
        .description = gGreenShardItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = _("HP UP"),
        .itemId = ITEM_HP_UP,
        .price = 9800,
        .description = gHPUpItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PROTEIN] =
    {
        .name = _("PROTEIN"),
        .itemId = ITEM_PROTEIN,
        .price = 9800,
        .description = gProteinItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_IRON] =
    {
        .name = _("IRON"),
        .itemId = ITEM_IRON,
        .price = 9800,
        .description = gIronItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_CARBOS] =
    {
        .name = _("CARBOS"),
        .itemId = ITEM_CARBOS,
        .price = 9800,
        .description = gCarbosItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_CALCIUM] =
    {
        .name = _("CALCIUM"),
        .itemId = ITEM_CALCIUM,
        .price = 9800,
        .description = gCalciumItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_RARE_CANDY] =
    {
        .name = _("RARE CANDY"),
        .itemId = ITEM_RARE_CANDY,
        .price = 4800,
        .description = gRareCandyItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .secondaryId = 0,
    },

    [ITEM_PP_UP] =
    {
        .name = _("PP UP"),
        .itemId = ITEM_PP_UP,
        .price = 9800,
        .description = gPPUpItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .secondaryId = 0,
    },

    [ITEM_ZINC] =
    {
        .name = _("ZINC"),
        .itemId = ITEM_ZINC,
        .price = 9800,
        .description = gZincItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PP_MAX] =
    {
        .name = _("PP MAX"),
        .itemId = ITEM_PP_MAX,
        .price = 9800,
        .description = gPPMaxItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .secondaryId = 0,
    },

// Battle items

    [ITEM_GUARD_SPEC] =
    {
        .name = _("GUARD SPEC."),
        .itemId = ITEM_GUARD_SPEC,
        .price = 700,
        .description = gGuardSpecItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = _("DIRE HIT"),
        .itemId = ITEM_DIRE_HIT,
        .price = 650,
        .description = gDireHitItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_ATTACK] =
    {
        .name = _("X ATTACK"),
        .itemId = ITEM_X_ATTACK,
        .price = 500,
        .description = gXAttackItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_DEFENSE] =
    {
        .name = _("X DEFEND"),
        .itemId = ITEM_X_DEFENSE,
        .price = 550,
        .description = gXDefendItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_SPEED] =
    {
        .name = _("X SPEED"),
        .itemId = ITEM_X_SPEED,
        .price = 350,
        .description = gXSpeedItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = _("X ACCURACY"),
        .itemId = ITEM_X_ACCURACY,
        .price = 950,
        .description = gXAccuracyItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_X_SP_ATK] =
    {
        .name = _("X SPECIAL"),
        .itemId = ITEM_X_SP_ATK,
        .price = 350,
        .description = gXSpecialItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
        .secondaryId = 0,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = _("POKé DOLL"),
        .itemId = ITEM_POKE_DOLL,
        .price = 1000,
        .description = gPokeDollItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_Escape,
        .secondaryId = 0,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = _("FLUFFY TAIL"),
        .itemId = ITEM_FLUFFY_TAIL,
        .price = 1000,
        .description = gFluffyTailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 2,
        .battleUseFunc = ItemUseInBattle_Escape,
        .secondaryId = 0,
    },

// Field items

    [ITEM_SUPER_REPEL] =
    {
        .name = _("SUPER REPEL"),
        .itemId = ITEM_SUPER_REPEL,
        .price = 500,
        .holdEffectParam = 200,
        .description = gSuperRepelItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .secondaryId = 0,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = _("MAX REPEL"),
        .itemId = ITEM_MAX_REPEL,
        .price = 700,
        .holdEffectParam = 250,
        .description = gMaxRepelItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .secondaryId = 0,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = _("ESCAPE ROPE"),
        .itemId = ITEM_ESCAPE_ROPE,
        .price = 550,
        .description = gEscapeRopeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
        .secondaryId = 0,
    },

    [ITEM_REPEL] =
    {
        .name = _("REPEL"),
        .itemId = ITEM_REPEL,
        .price = 350,
        .holdEffectParam = 100,
        .description = gRepelItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .secondaryId = 0,
    },

// Evolution stones

    [ITEM_SUN_STONE] =
    {
        .name = _("SUN STONE"),
        .itemId = ITEM_SUN_STONE,
        .price = 2100,
        .description = gSunStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_MOON_STONE] =
    {
        .name = _("MOON STONE"),
        .itemId = ITEM_MOON_STONE,
        .price = 0,
        .description = gMoonStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_FIRE_STONE] =
    {
        .name = _("FIRE STONE"),
        .itemId = ITEM_FIRE_STONE,
        .price = 2100,
        .description = gFireStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = _("THUNDERSTONE"),
        .itemId = ITEM_THUNDER_STONE,
        .price = 2100,
        .description = gThunderStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_WATER_STONE] =
    {
        .name = _("WATER STONE"),
        .itemId = ITEM_WATER_STONE,
        .price = 2100,
        .description = gWaterStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = _("LEAF STONE"),
        .itemId = ITEM_LEAF_STONE,
        .price = 2100,
        .description = gLeafStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .secondaryId = 0,
    },

// Valuable items

    [ITEM_TINY_MUSHROOM] =
    {
        .name = _("TINYMUSHROOM"),
        .itemId = ITEM_TINY_MUSHROOM,
        .price = 500,
        .description = gTinyMushroomItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = _("BIG MUSHROOM"),
        .itemId = ITEM_BIG_MUSHROOM,
        .price = 5000,
        .description = gBigMushroomItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PEARL] =
    {
        .name = _("PEARL"),
        .itemId = ITEM_PEARL,
        .price = 1400,
        .description = gPearlItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = _("BIG PEARL"),
        .itemId = ITEM_BIG_PEARL,
        .price = 7500,
        .description = gBigPearlItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STARDUST] =
    {
        .name = _("STARDUST"),
        .itemId = ITEM_STARDUST,
        .price = 2000,
        .description = gStardustItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = _("STAR PIECE"),
        .itemId = ITEM_STAR_PIECE,
        .price = 9800,
        .description = gStarPieceItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NUGGET] =
    {
        .name = _("NUGGET"),
        .itemId = ITEM_NUGGET,
        .price = 10000,
        .description = gNuggetItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = _("HEART SCALE"),
        .itemId = ITEM_HEART_SCALE,
        .price = 100,
        .description = gHeartScaleItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Mail
    [ITEM_ORANGE_MAIL] =
    {
        .name = _("ORANGE MAIL"),
        .itemId = ITEM_ORANGE_MAIL,
        .price = 50,
        .description = gOrangeMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 0,
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = _("HARBOR MAIL"),
        .itemId = ITEM_HARBOR_MAIL,
        .price = 50,
        .description = gHarborMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 1,
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = _("GLITTER MAIL"),
        .itemId = ITEM_GLITTER_MAIL,
        .price = 50,
        .description = gGlitterMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 2,
    },

    [ITEM_MECH_MAIL] =
    {
        .name = _("MECH MAIL"),
        .itemId = ITEM_MECH_MAIL,
        .price = 50,
        .description = gMechMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 3,
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = _("WOOD MAIL"),
        .itemId = ITEM_WOOD_MAIL,
        .price = 50,
        .description = gWoodMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 4,
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = _("WAVE MAIL"),
        .itemId = ITEM_WAVE_MAIL,
        .price = 50,
        .description = gWaveMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 5,
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = _("BEAD MAIL"),
        .itemId = ITEM_BEAD_MAIL,
        .price = 50,
        .description = gBeadMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 6,
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = _("SHADOW MAIL"),
        .itemId = ITEM_SHADOW_MAIL,
        .price = 50,
        .description = gShadowMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 7,
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = _("TROPIC MAIL"),
        .itemId = ITEM_TROPIC_MAIL,
        .price = 50,
        .description = gTropicMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 8,
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = _("DREAM MAIL"),
        .itemId = ITEM_DREAM_MAIL,
        .price = 50,
        .description = gDreamMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 9,
    },

    [ITEM_FAB_MAIL] =
    {
        .name = _("FAB MAIL"),
        .itemId = ITEM_FAB_MAIL,
        .price = 50,
        .description = gFabMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 10,
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = _("RETRO MAIL"),
        .itemId = ITEM_RETRO_MAIL,
        .price = 0,
        .description = gRetroMailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 11,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = _("CHERI BERRY"),
        .itemId = ITEM_CHERI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = gCheriBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = _("CHESTO BERRY"),
        .itemId = ITEM_CHESTO_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = gChestoBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = _("PECHA BERRY"),
        .itemId = ITEM_PECHA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = gPechaBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = _("RAWST BERRY"),
        .itemId = ITEM_RAWST_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = gRawstBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = _("ASPEAR BERRY"),
        .itemId = ITEM_ASPEAR_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = gAspearBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = _("LEPPA BERRY"),
        .itemId = ITEM_LEPPA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = gLeppaBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
        .secondaryId = 0,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = _("ORAN BERRY"),
        .itemId = ITEM_ORAN_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = gOranBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = _("PERSIM BERRY"),
        .itemId = ITEM_PERSIM_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = gPersimBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = _("LUM BERRY"),
        .itemId = ITEM_LUM_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = gLumBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = _("SITRUS BERRY"),
        .itemId = ITEM_SITRUS_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = gSitrusBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_Medicine,
        .secondaryId = 0,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = _("FIGY BERRY"),
        .itemId = ITEM_FIGY_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = 8,
        .description = gFigyBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = _("WIKI BERRY"),
        .itemId = ITEM_WIKI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = 8,
        .description = gWikiBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = _("MAGO BERRY"),
        .itemId = ITEM_MAGO_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = 8,
        .description = gMagoBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = _("AGUAV BERRY"),
        .itemId = ITEM_AGUAV_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = 8,
        .description = gAguavBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = _("IAPAPA BERRY"),
        .itemId = ITEM_IAPAPA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = 8,
        .description = gIapapaBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = _("RAZZ BERRY"),
        .itemId = ITEM_RAZZ_BERRY,
        .price = 20,
        .description = gRazzBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = _("BLUK BERRY"),
        .itemId = ITEM_BLUK_BERRY,
        .price = 20,
        .description = gBlukBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = _("NANAB BERRY"),
        .itemId = ITEM_NANAB_BERRY,
        .price = 20,
        .description = gNanabBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = _("WEPEAR BERRY"),
        .itemId = ITEM_WEPEAR_BERRY,
        .price = 20,
        .description = gWepearBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = _("PINAP BERRY"),
        .itemId = ITEM_PINAP_BERRY,
        .price = 20,
        .description = gPinapBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = _("POMEG BERRY"),
        .itemId = ITEM_POMEG_BERRY,
        .price = 20,
        .description = gPomegBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = _("KELPSY BERRY"),
        .itemId = ITEM_KELPSY_BERRY,
        .price = 20,
        .description = gKelpsyBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = _("QUALOT BERRY"),
        .itemId = ITEM_QUALOT_BERRY,
        .price = 20,
        .description = gQualotBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = _("HONDEW BERRY"),
        .itemId = ITEM_HONDEW_BERRY,
        .price = 20,
        .description = gHondewBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = _("GREPA BERRY"),
        .itemId = ITEM_GREPA_BERRY,
        .price = 20,
        .description = gGrepaBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = _("TAMATO BERRY"),
        .itemId = ITEM_TAMATO_BERRY,
        .price = 20,
        .description = gTamatoBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .secondaryId = 0,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = _("CORNN BERRY"),
        .itemId = ITEM_CORNN_BERRY,
        .price = 20,
        .description = gCornnBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = _("MAGOST BERRY"),
        .itemId = ITEM_MAGOST_BERRY,
        .price = 20,
        .description = gMagostBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = _("RABUTA BERRY"),
        .itemId = ITEM_RABUTA_BERRY,
        .price = 20,
        .description = gRabutaBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = _("NOMEL BERRY"),
        .itemId = ITEM_NOMEL_BERRY,
        .price = 20,
        .description = gNomelBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = _("SPELON BERRY"),
        .itemId = ITEM_SPELON_BERRY,
        .price = 20,
        .description = gSpelonBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = _("PAMTRE BERRY"),
        .itemId = ITEM_PAMTRE_BERRY,
        .price = 20,
        .description = gPamtreBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = _("WATMEL BERRY"),
        .itemId = ITEM_WATMEL_BERRY,
        .price = 20,
        .description = gWatmelBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = _("DURIN BERRY"),
        .itemId = ITEM_DURIN_BERRY,
        .price = 20,
        .description = gDurinBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = _("BELUE BERRY"),
        .itemId = ITEM_BELUE_BERRY,
        .price = 20,
        .description = gBelueBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = _("LIECHI BERRY"),
        .itemId = ITEM_LIECHI_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = gLiechiBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = _("GANLON BERRY"),
        .itemId = ITEM_GANLON_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = gGanlonBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = _("SALAC BERRY"),
        .itemId = ITEM_SALAC_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = gSalacBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = _("PETAYA BERRY"),
        .itemId = ITEM_PETAYA_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = gPetayaBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = _("APICOT BERRY"),
        .itemId = ITEM_APICOT_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = gApicotBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = _("LANSAT BERRY"),
        .itemId = ITEM_LANSAT_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = gLansatBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = _("STARF BERRY"),
        .itemId = ITEM_STARF_BERRY,
        .price = 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = gStarfBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = _("ENIGMA BERRY"),
        .itemId = ITEM_ENIGMA_BERRY,
        .price = 20,
        .description = gEnigmaBerryItemDescription,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = 1,
        .battleUseFunc = ItemUseInBattle_EnigmaBerry,
        .secondaryId = 0,
    },

// Hold items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = _("BRIGHTPOWDER"),
        .itemId = ITEM_BRIGHT_POWDER,
        .price = 10,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = gBrightPowderItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = _("WHITE HERB"),
        .itemId = ITEM_WHITE_HERB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_STATS,
        .description = gWhiteHerbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MACHO_BRACE] =
    {
        .name = _("MACHO BRACE"),
        .itemId = ITEM_MACHO_BRACE,
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = gMachoBraceItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = _("EXP. SHARE"),
        .itemId = ITEM_EXP_SHARE,
        .price = 3000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        .description = gExpShareItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = _("QUICK CLAW"),
        .itemId = ITEM_QUICK_CLAW,
        .price = 100,
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = gQuickClawItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = _("SOOTHE BELL"),
        .itemId = ITEM_SOOTHE_BELL,
        .price = 100,
        .holdEffect = HOLD_EFFECT_HAPPINESS_UP,
        .description = gSootheBellItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = _("MENTAL HERB"),
        .itemId = ITEM_MENTAL_HERB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_CURE_ATTRACT,
        .description = gMentalHerbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHOICE_BAND] =
    {
        .name = _("CHOICE BAND"),
        .itemId = ITEM_CHOICE_BAND,
        .price = 100,
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = gChoiceBandItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = _("KING'S ROCK"),
        .itemId = ITEM_KINGS_ROCK,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = gKingsRockItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = _("SILVERPOWDER"),
        .itemId = ITEM_SILVER_POWDER,
        .price = 100,
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = 10,
        .description = gSilverPowderItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = _("AMULET COIN"),
        .itemId = ITEM_AMULET_COIN,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .holdEffectParam = 10,
        .description = gAmuletCoinItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = _("CLEANSE TAG"),
        .itemId = ITEM_CLEANSE_TAG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = gCleanseTagItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = _("SOUL DEW"),
        .itemId = ITEM_SOUL_DEW,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .description = gSoulDewItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = _("DEEPSEATOOTH"),
        .itemId = ITEM_DEEP_SEA_TOOTH,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = gDeepSeaToothItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = _("DEEPSEASCALE"),
        .itemId = ITEM_DEEP_SEA_SCALE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = gDeepSeaScaleItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = _("SMOKE BALL"),
        .itemId = ITEM_SMOKE_BALL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = gSmokeBallItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EVERSTONE] =
    {
        .name = _("EVERSTONE"),
        .itemId = ITEM_EVERSTONE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = gEverstoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = _("FOCUS BAND"),
        .itemId = ITEM_FOCUS_BAND,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = gFocusBandItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = _("LUCKY EGG"),
        .itemId = ITEM_LUCKY_EGG,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = gLuckyEggItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = _("SCOPE LENS"),
        .itemId = ITEM_SCOPE_LENS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = gScopeLensItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METAL_COAT] =
    {
        .name = _("METAL COAT"),
        .itemId = ITEM_METAL_COAT,
        .price = 100,
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = 10,
        .description = gMetalCoatItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = _("LEFTOVERS"),
        .itemId = ITEM_LEFTOVERS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = gLeftoversItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = _("DRAGON SCALE"),
        .itemId = ITEM_DRAGON_SCALE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
        .holdEffectParam = 10,
        .description = gDragonScaleItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIGHT_BALL] =
    {
        .name = _("LIGHT BALL"),
        .itemId = ITEM_LIGHT_BALL,
        .price = 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = gLightBallItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = _("SOFT SAND"),
        .itemId = ITEM_SOFT_SAND,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = 10,
        .description = gSoftSandItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HARD_STONE] =
    {
        .name = _("HARD STONE"),
        .itemId = ITEM_HARD_STONE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 10,
        .description = gHardStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = _("MIRACLE SEED"),
        .itemId = ITEM_MIRACLE_SEED,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 10,
        .description = gMiracleSeedItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = _("BLACKGLASSES"),
        .itemId = ITEM_BLACK_GLASSES,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = 10,
        .description = gBlackGlassesItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = _("BLACK BELT"),
        .itemId = ITEM_BLACK_BELT,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = 10,
        .description = gBlackBeltItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAGNET] =
    {
        .name = _("MAGNET"),
        .itemId = ITEM_MAGNET,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = 10,
        .description = gMagnetItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = _("MYSTIC WATER"),
        .itemId = ITEM_MYSTIC_WATER,
        .price = 100,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 10,
        .description = gMysticWaterItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = _("SHARP BEAK"),
        .itemId = ITEM_SHARP_BEAK,
        .price = 100,
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = 10,
        .description = gSharpBeakItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POISON_BARB] =
    {
        .name = _("POISON BARB"),
        .itemId = ITEM_POISON_BARB,
        .price = 100,
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = 10,
        .description = gPoisonBarbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = _("NEVERMELTICE"),
        .itemId = ITEM_NEVER_MELT_ICE,
        .price = 100,
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = 10,
        .description = gNeverMeltIceItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = _("SPELL TAG"),
        .itemId = ITEM_SPELL_TAG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = 10,
        .description = gSpellTagItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = _("TWISTEDSPOON"),
        .itemId = ITEM_TWISTED_SPOON,
        .price = 100,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 10,
        .description = gTwistedSpoonItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHARCOAL] =
    {
        .name = _("CHARCOAL"),
        .itemId = ITEM_CHARCOAL,
        .price = 9800,
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = 10,
        .description = gCharcoalItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = _("DRAGON FANG"),
        .itemId = ITEM_DRAGON_FANG,
        .price = 100,
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = 10,
        .description = gDragonFangItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SILK_SCARF] =
    {
        .name = _("SILK SCARF"),
        .itemId = ITEM_SILK_SCARF,
        .price = 100,
        .holdEffect = HOLD_EFFECT_NORMAL_POWER,
        .holdEffectParam = 10,
        .description = gSilkScarfItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_UP_GRADE] =
    {
        .name = _("UP-GRADE"),
        .itemId = ITEM_UP_GRADE,
        .price = 2100,
        .holdEffect = HOLD_EFFECT_UP_GRADE,
        .description = gUpGradeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = _("SHELL BELL"),
        .itemId = ITEM_SHELL_BELL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = gShellBellItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SEA_INCENSE] =
    {
        .name = _("SEA INCENSE"),
        .itemId = ITEM_SEA_INCENSE,
        .price = 9600,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 5,
        .description = gSeaIncenseItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = _("LAX INCENSE"),
        .itemId = ITEM_LAX_INCENSE,
        .price = 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 5,
        .description = gLaxIncenseItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = _("LUCKY PUNCH"),
        .itemId = ITEM_LUCKY_PUNCH,
        .price = 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = gLuckyPunchItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = _("METAL POWDER"),
        .itemId = ITEM_METAL_POWDER,
        .price = 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = gMetalPowderItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = _("THICK CLUB"),
        .itemId = ITEM_THICK_CLUB,
        .price = 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = gThickClubItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STICK] =
    {
        .name = _("STICK"),
        .itemId = ITEM_STICK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_STICK,
        .description = gStickItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RED_SCARF] =
    {
        .name = _("RED SCARF"),
        .itemId = ITEM_RED_SCARF,
        .price = 100,
        .description = gRedScarfItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = _("BLUE SCARF"),
        .itemId = ITEM_BLUE_SCARF,
        .price = 100,
        .description = gBlueScarfItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = _("PINK SCARF"),
        .itemId = ITEM_PINK_SCARF,
        .price = 100,
        .description = gPinkScarfItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = _("GREEN SCARF"),
        .itemId = ITEM_GREEN_SCARF,
        .price = 100,
        .description = gGreenScarfItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = _("YELLOW SCARF"),
        .itemId = ITEM_YELLOW_SCARF,
        .price = 100,
        .description = gYellowScarfItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Key items

    [ITEM_MACH_BIKE] =
    {
        .name = _("MACH BIKE"),
        .itemId = ITEM_MACH_BIKE,
        .price = 0,
        .description = gMachBikeItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = 0,
    },

    [ITEM_COIN_CASE] =
    {
        .name = _("COIN CASE"),
        .itemId = ITEM_COIN_CASE,
        .price = 0,
        .description = gCoinCaseItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
        .secondaryId = 0,
    },

    [ITEM_ITEMFINDER] =
    {
        .name = _("ITEMFINDER"),
        .itemId = ITEM_ITEMFINDER,
        .price = 0,
        .description = gItemfinderItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
        .secondaryId = 0,
    },

    [ITEM_OLD_ROD] =
    {
        .name = _("OLD ROD"),
        .itemId = ITEM_OLD_ROD,
        .price = 0,
        .description = gOldRodItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = 0,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = _("GOOD ROD"),
        .itemId = ITEM_GOOD_ROD,
        .price = 0,
        .description = gGoodRodItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = 1,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = _("SUPER ROD"),
        .itemId = ITEM_SUPER_ROD,
        .price = 0,
        .description = gSuperRodItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = 2,
    },

    [ITEM_SS_TICKET] =
    {
        .name = _("S.S. TICKET"),
        .itemId = ITEM_SS_TICKET,
        .price = 0,
        .description = gSSTicketItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = _("CONTEST PASS"),
        .itemId = ITEM_CONTEST_PASS,
        .price = 0,
        .description = gContestPassItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = _("WAILMER PAIL"),
        .itemId = ITEM_WAILMER_PAIL,
        .price = 0,
        .description = gWailmerPailItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
        .secondaryId = 0,
    },

    [ITEM_DEVON_GOODS] =
    {
        .name = _("DEVON GOODS"),
        .itemId = ITEM_DEVON_GOODS,
        .price = 0,
        .description = gDevonGoodsItemDescription,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = _("SOOT SACK"),
        .itemId = ITEM_SOOT_SACK,
        .price = 0,
        .description = gSootSackItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = _("BASEMENT KEY"),
        .itemId = ITEM_BASEMENT_KEY,
        .price = 0,
        .description = gBasementKeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = _("ACRO BIKE"),
        .itemId = ITEM_ACRO_BIKE,
        .price = 0,
        .description = gAcroBikeItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = 1,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = _("{POKEBLOCK} CASE"),
        .itemId = ITEM_POKEBLOCK_CASE,
        .price = 0,
        .description = gPokeblockCaseItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 3,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
        .secondaryId = 0,
    },

    [ITEM_LETTER] =
    {
        .name = _("LETTER"),
        .itemId = ITEM_LETTER,
        .price = 0,
        .description = gLetterItemDescription,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EON_TICKET] =
    {
        .name = _("EON TICKET"),
        .itemId = ITEM_EON_TICKET,
        .price = 0,
        .description = gEonTicketItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_RED_ORB] =
    {
        .name = _("RED ORB"),
        .itemId = ITEM_RED_ORB,
        .price = 0,
        .description = gRedOrbItemDescription,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = _("BLUE ORB"),
        .itemId = ITEM_BLUE_ORB,
        .price = 0,
        .description = gBlueOrbItemDescription,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCANNER] =
    {
        .name = _("SCANNER"),
        .itemId = ITEM_SCANNER,
        .price = 0,
        .description = gScannerItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = _("GO-GOGGLES"),
        .itemId = ITEM_GO_GOGGLES,
        .price = 0,
        .description = gGoGogglesItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METEORITE] =
    {
        .name = _("METEORITE"),
        .itemId = ITEM_METEORITE,
        .price = 0,
        .description = gMeteoriteItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_1_KEY] =
    {
        .name = _("RM. 1 KEY"),
        .itemId = ITEM_ROOM_1_KEY,
        .price = 0,
        .description = gRoom1KeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_2_KEY] =
    {
        .name = _("RM. 2 KEY"),
        .itemId = ITEM_ROOM_2_KEY,
        .price = 0,
        .description = gRoom2KeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_4_KEY] =
    {
        .name = _("RM. 4 KEY"),
        .itemId = ITEM_ROOM_4_KEY,
        .price = 0,
        .description = gRoom4KeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOM_6_KEY] =
    {
        .name = _("RM. 6 KEY"),
        .itemId = ITEM_ROOM_6_KEY,
        .price = 0,
        .description = gRoom6KeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = _("STORAGE KEY"),
        .itemId = ITEM_STORAGE_KEY,
        .price = 0,
        .description = gStorageKeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = _("ROOT FOSSIL"),
        .itemId = ITEM_ROOT_FOSSIL,
        .price = 0,
        .description = gRootFossilItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = _("CLAW FOSSIL"),
        .itemId = ITEM_CLAW_FOSSIL,
        .price = 0,
        .description = gClawFossilItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = _("DEVON SCOPE"),
        .itemId = ITEM_DEVON_SCOPE,
        .price = 0,
        .description = gDevonScopeItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// TMs/HMs

    [ITEM_TM01_FOCUS_PUNCH] =
    {
        .name = _("TM01"),
        .itemId = ITEM_TM01_FOCUS_PUNCH,
        .price = 3000,
        .description = gTM01ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM02_DRAGON_CLAW] =
    {
        .name = _("TM02"),
        .itemId = ITEM_TM02_DRAGON_CLAW,
        .price = 3000,
        .description = gTM02ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM03_WATER_PULSE] =
    {
        .name = _("TM03"),
        .itemId = ITEM_TM03_WATER_PULSE,
        .price = 3000,
        .description = gTM03ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM04_CALM_MIND] =
    {
        .name = _("TM04"),
        .itemId = ITEM_TM04_CALM_MIND,
        .price = 3000,
        .description = gTM04ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM05_ROAR] =
    {
        .name = _("TM05"),
        .itemId = ITEM_TM05_ROAR,
        .price = 1000,
        .description = gTM05ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM06_TOXIC] =
    {
        .name = _("TM06"),
        .itemId = ITEM_TM06_TOXIC,
        .price = 3000,
        .description = gTM06ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM07_HAIL] =
    {
        .name = _("TM07"),
        .itemId = ITEM_TM07_HAIL,
        .price = 3000,
        .description = gTM07ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM08_BULK_UP] =
    {
        .name = _("TM08"),
        .itemId = ITEM_TM08_BULK_UP,
        .price = 3000,
        .description = gTM08ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM09_BULLET_SEED] =
    {
        .name = _("TM09"),
        .itemId = ITEM_TM09_BULLET_SEED,
        .price = 3000,
        .description = gTM09ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM10_HIDDEN_POWER] =
    {
        .name = _("TM10"),
        .itemId = ITEM_TM10_HIDDEN_POWER,
        .price = 3000,
        .description = gTM10ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM11_SUNNY_DAY] =
    {
        .name = _("TM11"),
        .itemId = ITEM_TM11_SUNNY_DAY,
        .price = 2000,
        .description = gTM11ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM12_TAUNT] =
    {
        .name = _("TM12"),
        .itemId = ITEM_TM12_TAUNT,
        .price = 3000,
        .description = gTM12ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM13_ICE_BEAM] =
    {
        .name = _("TM13"),
        .itemId = ITEM_TM13_ICE_BEAM,
        .price = 3000,
        .description = gTM13ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM14_BLIZZARD] =
    {
        .name = _("TM14"),
        .itemId = ITEM_TM14_BLIZZARD,
        .price = 5500,
        .description = gTM14ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM15_HYPER_BEAM] =
    {
        .name = _("TM15"),
        .itemId = ITEM_TM15_HYPER_BEAM,
        .price = 7500,
        .description = gTM15ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM16_LIGHT_SCREEN] =
    {
        .name = _("TM16"),
        .itemId = ITEM_TM16_LIGHT_SCREEN,
        .price = 3000,
        .description = gTM16ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM17_PROTECT] =
    {
        .name = _("TM17"),
        .itemId = ITEM_TM17_PROTECT,
        .price = 3000,
        .description = gTM17ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM18_RAIN_DANCE] =
    {
        .name = _("TM18"),
        .itemId = ITEM_TM18_RAIN_DANCE,
        .price = 2000,
        .description = gTM18ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM19_GIGA_DRAIN] =
    {
        .name = _("TM19"),
        .itemId = ITEM_TM19_GIGA_DRAIN,
        .price = 3000,
        .description = gTM19ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM20_SAFEGUARD] =
    {
        .name = _("TM20"),
        .itemId = ITEM_TM20_SAFEGUARD,
        .price = 3000,
        .description = gTM20ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM21_FRUSTRATION] =
    {
        .name = _("TM21"),
        .itemId = ITEM_TM21_FRUSTRATION,
        .price = 1000,
        .description = gTM21ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM22_SOLARBEAM] =
    {
        .name = _("TM22"),
        .itemId = ITEM_TM22_SOLARBEAM,
        .price = 3000,
        .description = gTM22ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM23_IRON_TAIL] =
    {
        .name = _("TM23"),
        .itemId = ITEM_TM23_IRON_TAIL,
        .price = 3000,
        .description = gTM23ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM24_THUNDERBOLT] =
    {
        .name = _("TM24"),
        .itemId = ITEM_TM24_THUNDERBOLT,
        .price = 3000,
        .description = gTM24ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM25_THUNDER] =
    {
        .name = _("TM25"),
        .itemId = ITEM_TM25_THUNDER,
        .price = 5500,
        .description = gTM25ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM26_EARTHQUAKE] =
    {
        .name = _("TM26"),
        .itemId = ITEM_TM26_EARTHQUAKE,
        .price = 3000,
        .description = gTM26ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM27_RETURN] =
    {
        .name = _("TM27"),
        .itemId = ITEM_TM27_RETURN,
        .price = 1000,
        .description = gTM27ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM28_DIG] =
    {
        .name = _("TM28"),
        .itemId = ITEM_TM28_DIG,
        .price = 2000,
        .description = gTM28ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM29_PSYCHIC] =
    {
        .name = _("TM29"),
        .itemId = ITEM_TM29_PSYCHIC,
        .price = 2000,
        .description = gTM29ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM30_SHADOW_BALL] =
    {
        .name = _("TM30"),
        .itemId = ITEM_TM30_SHADOW_BALL,
        .price = 3000,
        .description = gTM30ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM31_BRICK_BREAK] =
    {
        .name = _("TM31"),
        .itemId = ITEM_TM31_BRICK_BREAK,
        .price = 3000,
        .description = gTM31ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM32_DOUBLE_TEAM] =
    {
        .name = _("TM32"),
        .itemId = ITEM_TM32_DOUBLE_TEAM,
        .price = 2000,
        .description = gTM32ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM33_REFLECT] =
    {
        .name = _("TM33"),
        .itemId = ITEM_TM33_REFLECT,
        .price = 3000,
        .description = gTM33ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM34_SHOCK_WAVE] =
    {
        .name = _("TM34"),
        .itemId = ITEM_TM34_SHOCK_WAVE,
        .price = 3000,
        .description = gTM34ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM35_FLAMETHROWER] =
    {
        .name = _("TM35"),
        .itemId = ITEM_TM35_FLAMETHROWER,
        .price = 3000,
        .description = gTM35ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM36_SLUDGE_BOMB] =
    {
        .name = _("TM36"),
        .itemId = ITEM_TM36_SLUDGE_BOMB,
        .price = 1000,
        .description = gTM36ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM37_SANDSTORM] =
    {
        .name = _("TM37"),
        .itemId = ITEM_TM37_SANDSTORM,
        .price = 2000,
        .description = gTM37ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM38_FIRE_BLAST] =
    {
        .name = _("TM38"),
        .itemId = ITEM_TM38_FIRE_BLAST,
        .price = 5500,
        .description = gTM38ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM39_ROCK_TOMB] =
    {
        .name = _("TM39"),
        .itemId = ITEM_TM39_ROCK_TOMB,
        .price = 3000,
        .description = gTM39ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM40_AERIAL_ACE] =
    {
        .name = _("TM40"),
        .itemId = ITEM_TM40_AERIAL_ACE,
        .price = 3000,
        .description = gTM40ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM41_TORMENT] =
    {
        .name = _("TM41"),
        .itemId = ITEM_TM41_TORMENT,
        .price = 3000,
        .description = gTM41ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM42_FACADE] =
    {
        .name = _("TM42"),
        .itemId = ITEM_TM42_FACADE,
        .price = 3000,
        .description = gTM42ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM43_SECRET_POWER] =
    {
        .name = _("TM43"),
        .itemId = ITEM_TM43_SECRET_POWER,
        .price = 3000,
        .description = gTM43ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM44_REST] =
    {
        .name = _("TM44"),
        .itemId = ITEM_TM44_REST,
        .price = 3000,
        .description = gTM44ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM45_ATTRACT] =
    {
        .name = _("TM45"),
        .itemId = ITEM_TM45_ATTRACT,
        .price = 3000,
        .description = gTM45ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM46_THIEF] =
    {
        .name = _("TM46"),
        .itemId = ITEM_TM46_THIEF,
        .price = 3000,
        .description = gTM46ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM47_STEEL_WING] =
    {
        .name = _("TM47"),
        .itemId = ITEM_TM47_STEEL_WING,
        .price = 3000,
        .description = gTM47ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM48_SKILL_SWAP] =
    {
        .name = _("TM48"),
        .itemId = ITEM_TM48_SKILL_SWAP,
        .price = 3000,
        .description = gTM48ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM49_SNATCH] =
    {
        .name = _("TM49"),
        .itemId = ITEM_TM49_SNATCH,
        .price = 3000,
        .description = gTM49ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_TM50_OVERHEAT] =
    {
        .name = _("TM50"),
        .itemId = ITEM_TM50_OVERHEAT,
        .price = 3000,
        .description = gTM50ItemDescription,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM01_CUT] =
    {
        .name = _("HM01"),
        .itemId = ITEM_HM01_CUT,
        .price = 0,
        .description = gHM01ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM02_FLY] =
    {
        .name = _("HM02"),
        .itemId = ITEM_HM02_FLY,
        .price = 0,
        .description = gHM02ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM03_SURF] =
    {
        .name = _("HM03"),
        .itemId = ITEM_HM03_SURF,
        .price = 0,
        .description = gHM03ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM04_STRENGTH] =
    {
        .name = _("HM04"),
        .itemId = ITEM_HM04_STRENGTH,
        .price = 0,
        .description = gHM04ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM05_FLASH] =
    {
        .name = _("HM05"),
        .itemId = ITEM_HM05_FLASH,
        .price = 0,
        .description = gHM05ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM06_ROCK_SMASH] =
    {
        .name = _("HM06"),
        .itemId = ITEM_HM06_ROCK_SMASH,
        .price = 0,
        .description = gHM06ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM07_WATERFALL] =
    {
        .name = _("HM07"),
        .itemId = ITEM_HM07_WATERFALL,
        .price = 0,
        .description = gHM07ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

    [ITEM_HM08_DIVE] =
    {
        .name = _("HM08"),
        .itemId = ITEM_HM08_DIVE,
        .price = 0,
        .description = gHM08ItemDescription,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = 0,
    },

// FireRed/LeafGreen key items

    [ITEM_OAKS_PARCEL] =
    {
        .name = _("OAK'S PARCEL"),
        .itemId = ITEM_OAKS_PARCEL,
        .price = 0,
        .description = gOaksParcelItemDescription,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = _("POKé FLUTE"),
        .itemId = ITEM_POKE_FLUTE,
        .price = 0,
        .description = gPokeFluteItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = _("SECRET KEY"),
        .itemId = ITEM_SECRET_KEY,
        .price = 0,
        .description = gSecretKeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = _("BIKE VOUCHER"),
        .itemId = ITEM_BIKE_VOUCHER,
        .price = 0,
        .description = gBikeVoucherItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = _("GOLD TEETH"),
        .itemId = ITEM_GOLD_TEETH,
        .price = 0,
        .description = gGoldTeethItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = _("OLD AMBER"),
        .itemId = ITEM_OLD_AMBER,
        .price = 0,
        .description = gOldAmberItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CARD_KEY] =
    {
        .name = _("CARD KEY"),
        .itemId = ITEM_CARD_KEY,
        .price = 0,
        .description = gCardKeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = _("LIFT KEY"),
        .itemId = ITEM_LIFT_KEY,
        .price = 0,
        .description = gLiftKeyItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HELIX_FOSSIL] =
    {
        .name = _("HELIX FOSSIL"),
        .itemId = ITEM_HELIX_FOSSIL,
        .price = 0,
        .description = gHelixFossilItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = _("DOME FOSSIL"),
        .itemId = ITEM_DOME_FOSSIL,
        .price = 0,
        .description = gDomeFossilItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = _("SILPH SCOPE"),
        .itemId = ITEM_SILPH_SCOPE,
        .price = 0,
        .description = gSilphScopeItemDescription,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BICYCLE] =
    {
        .name = _("BICYCLE"),
        .itemId = ITEM_BICYCLE,
        .price = 0,
        .description = gBicycleItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = _("TOWN MAP"),
        .itemId = ITEM_TOWN_MAP,
        .price = 0,
        .description = gTownMapItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = _("VS SEEKER"),
        .itemId = ITEM_VS_SEEKER,
        .price = 0,
        .description = gVSSeekerItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = _("FAME CHECKER"),
        .itemId = ITEM_FAME_CHECKER,
        .price = 0,
        .description = gFameCheckerItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TM_CASE] =
    {
        .name = _("TM CASE"),
        .itemId = ITEM_TM_CASE,
        .price = 0,
        .description = gTMCaseItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = _("BERRY POUCH"),
        .itemId = ITEM_BERRY_POUCH,
        .price = 0,
        .description = gBerryPouchItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = _("TEACHY TV"),
        .itemId = ITEM_TEACHY_TV,
        .price = 0,
        .description = gTeachyTVItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TRI_PASS] =
    {
        .name = _("TRI-PASS"),
        .itemId = ITEM_TRI_PASS,
        .price = 0,
        .description = gTriPassItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = _("RAINBOW PASS"),
        .itemId = ITEM_RAINBOW_PASS,
        .price = 0,
        .description = gRainbowPassItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TEA] =
    {
        .name = _("TEA"),
        .itemId = ITEM_TEA,
        .price = 0,
        .description = gTeaItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = _("MYSTICTICKET"),
        .itemId = ITEM_MYSTIC_TICKET,
        .price = 0,
        .description = gMysticTicketItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = _("AURORATICKET"),
        .itemId = ITEM_AURORA_TICKET,
        .price = 0,
        .description = gAuroraTicketItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = _("POWDER JAR"),
        .itemId = ITEM_POWDER_JAR,
        .price = 0,
        .description = gPowderJarItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
        .secondaryId = 0,
    },

    [ITEM_RUBY] =
    {
        .name = _("RUBY"),
        .itemId = ITEM_RUBY,
        .price = 0,
        .description = gRubyItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = _("SAPPHIRE"),
        .itemId = ITEM_SAPPHIRE,
        .price = 0,
        .description = gSapphireItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// Emerald-specific key items

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = _("MAGMA EMBLEM"),
        .itemId = ITEM_MAGMA_EMBLEM,
        .price = 0,
        .description = gMagmaEmblemItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = _("OLD SEA MAP"),
        .itemId = ITEM_OLD_SEA_MAP,
        .price = 0,
        .description = gOldSeaMapItemDescription,
        .importance = 1,
        .unk19 = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

// New items

    [ITEM_WIDE_LENS] =
    {
        .name = _("Wide Lens"),
        .itemId = ITEM_WIDE_LENS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = gWideLensItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MUSCLE_BAND] =
    {
        .name = _("Muscle Band"),
        .itemId = ITEM_MUSCLE_BAND,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = gMuscleBandItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WISE_GLASSES] =
    {
        .name = _("Wise Glasses"),
        .itemId = ITEM_WISE_GLASSES,
        .price = 200,
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = gWiseGlassesItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EXPERT_BELT] =
    {
        .name = _("Expert Belt"),
        .itemId = ITEM_EXPERT_BELT,
        .price = 200,
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = gExpertBeltItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIGHT_CLAY] =
    {
        .name = _("Light Clay"),
        .itemId = ITEM_LIGHT_CLAY,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = gLightClayItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LIFE_ORB] =
    {
        .name = _("Life Orb"),
        .itemId = ITEM_LIFE_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = gLifeOrbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POWER_HERB] =
    {
        .name = _("Power Herb"),
        .itemId = ITEM_POWER_HERB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = gPowerHerbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TOXIC_ORB] =
    {
        .name = _("Toxic Orb"),
        .itemId = ITEM_TOXIC_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = gToxicOrbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FLAME_ORB] =
    {
        .name = _("Flame Orb"),
        .itemId = ITEM_FLAME_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = gFlameOrbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_QUICK_POWDER] =
    {
        .name = _("Quick Powder"),
        .itemId = ITEM_QUICK_POWDER,
        .price = 200,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = gQuickPowderItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FOCUS_SASH] =
    {
        .name = _("Focus Sash"),
        .itemId = ITEM_FOCUS_SASH,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = gFocusSashItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ZOOM_LENS] =
    {
        .name = _("Zoom Lens"),
        .itemId = ITEM_ZOOM_LENS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = gZoomLensItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METRONOME] =
    {
        .name = _("Metronome"),
        .itemId = ITEM_METRONOME,
        .price = 200,
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = gMetronomeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_IRON_BALL] =
    {
        .name = _("Iron Ball"),
        .itemId = ITEM_IRON_BALL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = gIronBallItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LAGGING_TAIL] =
    {
        .name = _("Lagging Tail"),
        .itemId = ITEM_LAGGING_TAIL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = gLaggingTailItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DESTINY_KNOT] =
    {
        .name = _("Destiny Knot"),
        .itemId = ITEM_DESTINY_KNOT,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = gDestinyKnotItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLACK_SLUDGE] =
    {
        .name = _("Black Sludge"),
        .itemId = ITEM_BLACK_SLUDGE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = gBlackSludgeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ICY_ROCK] =
    {
        .name = _("Icy Rock"),
        .itemId = ITEM_ICY_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
        .description = gIcyRockItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SMOOTH_ROCK] =
    {
        .name = _("Smooth Rock"),
        .itemId = ITEM_SMOOTH_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = gSmoothRockItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HEAT_ROCK] =
    {
        .name = _("Heat Rock"),
        .itemId = ITEM_HEAT_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = gHeatRockItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DAMP_ROCK] =
    {
        .name = _("Damp Rock"),
        .itemId = ITEM_DAMP_ROCK,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = gDampRockItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRIP_CLAW] =
    {
        .name = _("Grip Claw"),
        .itemId = ITEM_GRIP_CLAW,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = gGripClawItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHOICE_SCARF] =
    {
        .name = _("Choice Scarf"),
        .itemId = ITEM_CHOICE_SCARF,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = gChoiceScarfItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STICKY_BARB] =
    {
        .name = _("Sticky Barb"),
        .itemId = ITEM_STICKY_BARB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = gStickyBarbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHED_SHELL] =
    {
        .name = _("Shed Shell"),
        .itemId = ITEM_SHED_SHELL,
        .price = 200,
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = gShedShellItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BIG_ROOT] =
    {
        .name = _("Big Root"),
        .itemId = ITEM_BIG_ROOT,
        .price = 200,
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = gBigRootItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHOICE_SPECS] =
    {
        .name = _("Choice Specs"),
        .itemId = ITEM_CHOICE_SPECS,
        .price = 200,
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = gChoiceSpecsItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ADAMANT_ORB] =
    {
        .name = _("Adamant Orb"),
        .itemId = ITEM_ADAMANT_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .description = gAdamantOrbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUSTROUS_ORB] =
    {
        .name = _("Lustrous Orb"),
        .itemId = ITEM_LUSTROUS_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .description = gLustrousOrbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRISEOUS_ORB] =
    {
        .name = _("Griseous Orb"),
        .itemId = ITEM_GRISEOUS_ORB,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .description = gGriseousOrbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FLAME_PLATE] =
    {
        .name = _("Flame Plate"),
        .itemId = ITEM_FLAME_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = 20,
        .description = gFlamePlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SPLASH_PLATE] =
    {
        .name = _("Splash Plate"),
        .itemId = ITEM_SPLASH_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 20,
        .description = gSplashPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ZAP_PLATE] =
    {
        .name = _("Zap Plate"),
        .itemId = ITEM_ZAP_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = 20,
        .description = gZapPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEADOW_PLATE] =
    {
        .name = _("Meadow Plate"),
        .itemId = ITEM_MEADOW_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 20,
        .description = gMeadowPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ICICLE_PLATE] =
    {
        .name = _("Icicle Plate"),
        .itemId = ITEM_ICICLE_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = 20,
        .description = gIciclePlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FIST_PLATE] =
    {
        .name = _("Fist Plate"),
        .itemId = ITEM_FIST_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = 20,
        .description = gFistPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TOXIC_PLATE] =
    {
        .name = _("Toxic Plate"),
        .itemId = ITEM_TOXIC_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = 20,
        .description = gToxicPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EARTH_PLATE] =
    {
        .name = _("Earth Plate"),
        .itemId = ITEM_EARTH_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = 20,
        .description = gEarthPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SKY_PLATE] =
    {
        .name = _("Sky Plate"),
        .itemId = ITEM_SKY_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = 20,
        .description = gSkyPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MIND_PLATE] =
    {
        .name = _("Mind Plate"),
        .itemId = ITEM_MIND_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 20,
        .description = gMindPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_INSECT_PLATE] =
    {
        .name = _("Insect Plate"),
        .itemId = ITEM_INSECT_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = 20,
        .description = gInsectPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STONE_PLATE] =
    {
        .name = _("Stone Plate"),
        .itemId = ITEM_STONE_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 20,
        .description = gStonePlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SPOOKY_PLATE] =
    {
        .name = _("Spooky Plate"),
        .itemId = ITEM_SPOOKY_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = 20,
        .description = gSpookyPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DRACO_PLATE] =
    {
        .name = _("Draco Plate"),
        .itemId = ITEM_DRACO_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = 20,
        .description = gDracoPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DREAD_PLATE] =
    {
        .name = _("Dread Plate"),
        .itemId = ITEM_DREAD_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = 20,
        .description = gDreadPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_IRON_PLATE] =
    {
        .name = _("Iron Plate"),
        .itemId = ITEM_IRON_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = 20,
        .description = gIronPlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_EVIOLITE] =
    {
        .name = _("Eviolite"),
        .itemId = ITEM_EVIOLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = gEvioliteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FLOAT_STONE] =
    {
        .name = _("Float Stone"),
        .itemId = ITEM_FLOAT_STONE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = gFloatStoneItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BINDING_BAND] =
    {
        .name = _("Binding Band"),
        .itemId = ITEM_BINDING_BAND,
        .price = 200,
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = gBindingBandItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DOUSE_DRIVE] =
    {
        .name = _("Douse Drive"),
        .itemId = ITEM_DOUSE_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = gDouseDriveItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHOCK_DRIVE] =
    {
        .name = _("Shock Drive"),
        .itemId = ITEM_SHOCK_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = gShockDriveItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BURN_DRIVE] =
    {
        .name = _("Burn Drive"),
        .itemId = ITEM_BURN_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = gBurnDriveItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHILL_DRIVE] =
    {
        .name = _("Chill Drive"),
        .itemId = ITEM_CHILL_DRIVE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = gChillDriveItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FIRE_GEM] =
    {
        .name = _("Fire Gem"),
        .itemId = ITEM_FIRE_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gFireGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_WATER_GEM] =
    {
        .name = _("Water Gem"),
        .itemId = ITEM_WATER_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gWaterGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ELECTRIC_GEM] =
    {
        .name = _("Electric Gem"),
        .itemId = ITEM_ELECTRIC_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gElectricGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRASS_GEM] =
    {
        .name = _("Grass Gem"),
        .itemId = ITEM_GRASS_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gGrassGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ICE_GEM] =
    {
        .name = _("Ice Gem"),
        .itemId = ITEM_ICE_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gIceGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FIGHTING_GEM] =
    {
        .name = _("Fighting Gem"),
        .itemId = ITEM_FIGHTING_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gFightingGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_POISON_GEM] =
    {
        .name = _("Poison Gem"),
        .itemId = ITEM_POISON_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gPoisonGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GROUND_GEM] =
    {
        .name = _("Ground Gem"),
        .itemId = ITEM_GROUND_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gGroundGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FLYING_GEM] =
    {
        .name = _("Flying Gem"),
        .itemId = ITEM_FLYING_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gFlyingGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PSYCHIC_GEM] =
    {
        .name = _("Psychic Gem"),
        .itemId = ITEM_PSYCHIC_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gPsychicGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BUG_GEM] =
    {
        .name = _("Bug Gem"),
        .itemId = ITEM_BUG_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gBugGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ROCK_GEM] =
    {
        .name = _("Rock Gem"),
        .itemId = ITEM_ROCK_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gRockGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GHOST_GEM] =
    {
        .name = _("Ghost Gem"),
        .itemId = ITEM_GHOST_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gGhostGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DRAGON_GEM] =
    {
        .name = _("Dragon Gem"),
        .itemId = ITEM_DRAGON_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gDragonGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DARK_GEM] =
    {
        .name = _("Dark Gem"),
        .itemId = ITEM_DARK_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gDarkGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STEEL_GEM] =
    {
        .name = _("Steel Gem"),
        .itemId = ITEM_STEEL_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gSteelGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_NORMAL_GEM] =
    {
        .name = _("Normal Gem"),
        .itemId = ITEM_NORMAL_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gNormalGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_FAIRY_GEM] =
    {
        .name = _("Fairy Gem"),
        .itemId = ITEM_FAIRY_GEM,
        .price = 200,
        .holdEffect = HOLD_EFFECT_GEMS,
        .description = gFairyGemItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ASSAULT_VEST] =
    {
        .name = _("Assault Vest"),
        .itemId = ITEM_ASSAULT_VEST,
        .price = 200,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = gAssaultVestItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PIXIE_PLATE] =
    {
        .name = _("Pixie Plate"),
        .itemId = ITEM_PIXIE_PLATE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_FAIRY_POWER,
        .holdEffectParam = 20,
        .description = gPixiePlateItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
        .name = _("SafetyGoggles"),
        .itemId = ITEM_SAFETY_GOGGLES,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SAFETY_GOOGLES,
        .description = gSafetyGogglesItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GENGARITE] =
    {
        .name = _("Gengarite"),
        .itemId = ITEM_GENGARITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gGengariteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GARDEVOIRITE] =
    {
        .name = _("Gardevoirite"),
        .itemId = ITEM_GARDEVOIRITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gGardevoiriteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AMPHAROSITE] =
    {
        .name = _("Ampharosite"),
        .itemId = ITEM_AMPHAROSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAmpharositeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_VENUSAURITE] =
    {
        .name = _("Venusaurite"),
        .itemId = ITEM_VENUSAURITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gVenusauriteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHARIZARDITE_X] =
    {
        .name = _("CharizarditeX"),
        .itemId = ITEM_CHARIZARDITE_X,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gCharizarditeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLASTOISINITE] =
    {
        .name = _("Blastoisinite"),
        .itemId = ITEM_BLASTOISINITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gBlastoisiniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEWTWONITE_X] =
    {
        .name = _("Mewtwonite X"),
        .itemId = ITEM_MEWTWONITE_X,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gMewtwoniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEWTWONITE_Y] =
    {
        .name = _("Mewtwonite Y"),
        .itemId = ITEM_MEWTWONITE_Y,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gMewtwoniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BLAZIKENITE] =
    {
        .name = _("Blazikenite"),
        .itemId = ITEM_BLAZIKENITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gBlazikeniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEDICHAMITE] =
    {
        .name = _("Medichamite"),
        .itemId = ITEM_MEDICHAMITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gMedichamiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HOUNDOOMINITE] =
    {
        .name = _("Houndoominite"),
        .itemId = ITEM_HOUNDOOMINITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gHoundoominiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AGGRONITE] =
    {
        .name = _("Aggronite"),
        .itemId = ITEM_AGGRONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAggroniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BANETTITE] =
    {
        .name = _("Banettite"),
        .itemId = ITEM_BANETTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gBanettiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TYRANITARITE] =
    {
        .name = _("Tyranitarite"),
        .itemId = ITEM_TYRANITARITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gTyranitariteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCIZORITE] =
    {
        .name = _("Scizorite"),
        .itemId = ITEM_SCIZORITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gScizoriteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PINSIRITE] =
    {
        .name = _("Pinsirite"),
        .itemId = ITEM_PINSIRITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gPinsiriteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AERODACTYLITE] =
    {
        .name = _("Aerodactylite"),
        .itemId = ITEM_AERODACTYLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAerodactyliteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LUCARIONITE] =
    {
        .name = _("Lucarionite"),
        .itemId = ITEM_LUCARIONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gLucarioniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ABOMASITE] =
    {
        .name = _("Abomasite"),
        .itemId = ITEM_ABOMASITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAbomasiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_KANGASKHANITE] =
    {
        .name = _("Kangaskhanite"),
        .itemId = ITEM_KANGASKHANITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gKangaskhaniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GYARADOSITE] =
    {
        .name = _("Gyaradosite"),
        .itemId = ITEM_GYARADOSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gGyaradositeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ABSOLITE] =
    {
        .name = _("Absolite"),
        .itemId = ITEM_ABSOLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAbsoliteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
        .name = _("CharizarditeY"),
        .itemId = ITEM_CHARIZARDITE_Y,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gCharizarditeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ALAKAZITE] =
    {
        .name = _("Alakazite"),
        .itemId = ITEM_ALAKAZITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAlakaziteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HERACRONITE] =
    {
        .name = _("Heracronite"),
        .itemId = ITEM_HERACRONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gHeracroniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MAWILITE] =
    {
        .name = _("Mawilite"),
        .itemId = ITEM_MAWILITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gMawiliteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MANECTITE] =
    {
        .name = _("Manectite"),
        .itemId = ITEM_MANECTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gManectiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GARCHOMPITE] =
    {
        .name = _("Garchompite"),
        .itemId = ITEM_GARCHOMPITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gGarchompiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LATIASITE] =
    {
        .name = _("Latiasite"),
        .itemId = ITEM_LATIASITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gLatiasiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LATIOSITE] =
    {
        .name = _("Latiosite"),
        .itemId = ITEM_LATIOSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gLatiositeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SWAMPERTITE] =
    {
        .name = _("Swampertite"),
        .itemId = ITEM_SWAMPERTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gSwampertiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SCEPTILITE] =
    {
        .name = _("Sceptilite"),
        .itemId = ITEM_SCEPTILITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gSceptiliteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SABLENITE] =
    {
        .name = _("Sablenite"),
        .itemId = ITEM_SABLENITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gSableniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ALTARIANITE] =
    {
        .name = _("Altarianite"),
        .itemId = ITEM_ALTARIANITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAltarianiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GALLADITE] =
    {
        .name = _("Galladite"),
        .itemId = ITEM_GALLADITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gGalladiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_AUDINITE] =
    {
        .name = _("Audinite"),
        .itemId = ITEM_AUDINITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gAudiniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_METAGROSSITE] =
    {
        .name = _("Metagrossite"),
        .itemId = ITEM_METAGROSSITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gMetagrossiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SHARPEDONITE] =
    {
        .name = _("Sharpedonite"),
        .itemId = ITEM_SHARPEDONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gSharpedoniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SLOWBRONITE] =
    {
        .name = _("Slowbronite"),
        .itemId = ITEM_SLOWBRONITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gSlowbroniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_STEELIXITE] =
    {
        .name = _("Steelixite"),
        .itemId = ITEM_STEELIXITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gSteelixiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PIDGEOTITE] =
    {
        .name = _("Pidgeotite"),
        .itemId = ITEM_PIDGEOTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gPidgeotiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GLALITITE] =
    {
        .name = _("Glalitite"),
        .itemId = ITEM_GLALITITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gGlalititeItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_DIANCITE] =
    {
        .name = _("Diancite"),
        .itemId = ITEM_DIANCITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gDianciteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_CAMERUPTITE] =
    {
        .name = _("Cameruptite"),
        .itemId = ITEM_CAMERUPTITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gCameruptiteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_LOPUNNITE] =
    {
        .name = _("Lopunnite"),
        .itemId = ITEM_LOPUNNITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gLopunniteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_SALAMENCITE] =
    {
        .name = _("Salamencite"),
        .itemId = ITEM_SALAMENCITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gSalamenciteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_BEEDRILLITE] =
    {
        .name = _("Beedrillite"),
        .itemId = ITEM_BEEDRILLITE,
        .price = 200,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = gBeedrilliteItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MEGA_BRACELET] =
    {
        .name = _("Mega Bracelet"),
        .itemId = ITEM_MEGA_BRACELET,
        .price = 200,
        .description = gMegaBraceletItemDescription,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
        .name = _("Protect Pads"), // Shortened name from Protective Pads
        .itemId = ITEM_PROTECTIVE_PADS,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = gProtectPadsItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
        .name = _("Terrain Exte."),
        .itemId = ITEM_TERRAIN_EXTENDER,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = gTerrainExtenderItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ELECTRIC_SEED] =
    {
        .name = _("Electric Seed"),
        .itemId = ITEM_ELECTRIC_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = gElectricSeedItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_GRASSY_SEED] =
    {
        .name = _("Grassy Seed"),
        .itemId = ITEM_GRASSY_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = gGrassySeedItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_MISTY_SEED] =
    {
        .name = _("Misty Seed"),
        .itemId = ITEM_MISTY_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = gMistySeedItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_PSYCHIC_SEED] =
    {
        .name = _("Psychic Seed"),
        .itemId = ITEM_PSYCHIC_SEED,
        .price = 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .description = gPsychicSeedItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_ADRENALINE_ORB] =
    {
        .name = _("AdrenalineOrb"),
        .itemId = ITEM_ADRENALINE_ORB,
        .price = 300,
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = gAdrenalineOrbItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    },

    [ITEM_HONEY] =
    {
        .name = _("Honey"),
        .itemId = ITEM_HONEY,
        .price = 100,
        .description = gHoneyItemDescription,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 0,
    }
};
