static const u8 unknown_string[] = _("unknown");

static const struct TrainerMonNoItemDefaultMoves tt1Party[] = {
    {
        .iv = 0,
        .lvl = 1,
        .species = SPECIES_SCRAGGY,
    }, {
        .iv = 0,
        .lvl = 1,
        .species = SPECIES_GASTLY,
    }, {
        .iv = 0,
        .lvl = 1,
        .species = SPECIES_JOLTEON,
    }, {
        .iv = 0,
        .lvl = 1,
        .species = SPECIES_DUSKULL,
    }
};
static const u8 tt1IntroText[] = _("test intro 1");
static const u8 tt1DefeatText[] = _("test defeat 1");
static const u8 tt1PostbattleText[] = _("postbattle 1");
static const u8 tt1Name[] = _("HoldemJoe");
static const struct TrainerTemplate tt1 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = tt1Name,
    .partySize = 4,
    .party = {.NoItemDefaultMoves = tt1Party},
    .type1 = 0,
    .type2 = 0,
    .rarity = 0,
    .introText = tt1IntroText,
    .defeatText = tt1DefeatText,
    .postbattleText = tt1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_LITTLE_BOY,
};


static const u8 ttNormalIntroText[] = _("I am challenging you\nto a Pokémon battle.");
static const u8 ttNormalDefeatText[] = _("You won the\nPokémon battle.");
static const u8 ttNormalPostbattleText[] = _("We had a Pokémon battle\nand you won it.");
static const u8 ttNormalName[] = _("Normán");
static const struct TrainerTemplate ttNormal = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GENTLEMAN,
    .trainerName = ttNormalName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_NORMAL,
    .type2 = 0,
    .rarity = 1,
    .introText = ttNormalIntroText,
    .defeatText = ttNormalDefeatText,
    .postbattleText = ttNormalPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_GENTLEMAN,
};


static const u8 ttFightingIntroText[] = _("intro text");
static const u8 ttFightingDefeatText[] = _("defeat text");
static const u8 ttFightingPostbattleText[] = _("postbattle text");
static const u8 ttFightingName[] = _("Santo");
static const struct TrainerTemplate ttFighting = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BLACK_BELT,
    .trainerName = ttFightingName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FIGHTING,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFightingIntroText,
    .defeatText = ttFightingDefeatText,
    .postbattleText = ttFightingPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BLACK_BELT,
};


static const u8 ttFlyingIntroText[] = _("This is your captain speaking...\nI'm gonna kick your tail!");
static const u8 ttFlyingDefeatText[] = _("I'm stalling out!\nMayday! Mayday!");
static const u8 ttFlyingPostbattleText[] = _("You need a major\naltitude adjustment!");
static const u8 ttFlyingName[] = _("Joan Jet");
static const struct TrainerTemplate ttFlying = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = ttFlyingName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FLYING,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFlyingIntroText,
    .defeatText = ttFlyingDefeatText,
    .postbattleText = ttFlyingPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};


static const u8 ttPoisonIntroText[] = _("intro text");
static const u8 ttPoisonDefeatText[] = _("defeat text");
static const u8 ttPoisonPostbattleText[] = _("postbattle text");
static const u8 ttPoisonName[] = _("Mr. Yuk");
static const struct TrainerTemplate ttPoison = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
    .trainerName = ttPoisonName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_POISON,
    .type2 = 0,
    .rarity = 1,
    .introText = ttPoisonIntroText,
    .defeatText = ttPoisonDefeatText,
    .postbattleText = ttPoisonPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_AQUA_MEMBER_F,
};


static const u8 ttGroundIntroText[] = _("Runnin' my fingers through this\nhere soil... makes me feel alive.");
static const u8 ttGroundDefeatText[] = _("Not much left to harvest\nnow that rains stopped comin'.");
static const u8 ttGroundPostbattleText[] = _("You live and die\nby what the land gives ya.");
static const u8 ttGroundName[] = _("Farmer Jed");
static const struct TrainerTemplate ttGround = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_RUIN_MANIAC,
    .trainerName = ttGroundName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_GROUND,
    .type2 = 0,
    .rarity = 1,
    .introText = ttGroundIntroText,
    .defeatText = ttGroundDefeatText,
    .postbattleText = ttGroundPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_SCIENTIST_1,
};


static const u8 ttRockIntroText[] = _("intro text");
static const u8 ttRockDefeatText[] = _("defeat text");
static const u8 ttRockPostbattleText[] = _("postbattle text");
static const u8 ttRockName[] = _("Kimberly");
static const struct TrainerTemplate ttRock = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = ttRockName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_ROCK,
    .type2 = 0,
    .rarity = 1,
    .introText = ttRockIntroText,
    .defeatText = ttRockDefeatText,
    .postbattleText = ttRockPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_HIKER,
};

static const u8 ttBugIntroText[] = _("intro text");
static const u8 ttBugDefeatText[] = _("defeat text");
static const u8 ttBugPostbattleText[] = _("postbattle text");
static const u8 ttBugName[] = _("Bea");
static const struct TrainerTemplate ttBug = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BUG_CATCHER,
    .trainerName = ttBugName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_BUG,
    .type2 = 0,
    .rarity = 1,
    .introText = ttBugIntroText,
    .defeatText = ttBugDefeatText,
    .postbattleText = ttBugPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BUG_CATCHER,
};


static const u8 ttGhostIntroText[] = _("intro text");
static const u8 ttGhostDefeatText[] = _("defeat text");
static const u8 ttGhostPostbattleText[] = _("postbattle text");
static const u8 ttGhostName[] = _("Clyde");
static const struct TrainerTemplate ttGhost = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HEX_MANIAC,
    .trainerName = ttGhostName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_GHOST,
    .type2 = 0,
    .rarity = 1,
    .introText = ttGhostIntroText,
    .defeatText = ttGhostDefeatText,
    .postbattleText = ttGhostPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_HEX_MANIAC,
};


static const u8 ttSteelIntroText[] = _("Let's battle NOW! YOW!");
static const u8 ttSteelDefeatText[] = _("You beat me HOW?! YOW!");
static const u8 ttSteelPostbattleText[] = _("My jokes are too HIGHBROW! YOW!");
static const u8 ttSteelName[] = _("David Defeis");
static const struct TrainerTemplate ttSteel = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GUITARIST,
    .trainerName = ttSteelName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_STEEL,
    .type2 = 0,
    .rarity = 1,
    .introText = ttSteelIntroText,
    .defeatText = ttSteelDefeatText,
    .postbattleText = ttSteelPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAN_5,
};


static const u8 ttFireIntroText[] = _("Man it's a hot one.");
static const u8 ttFireDefeatText[] = _("Like seven inches from the midday\nsun.");
static const u8 ttFirePostbattleText[] = _("Give me your heart,\nmake it real.");
static const u8 ttFireName[] = _("Rob Thomas ft. Santana");
static const struct TrainerTemplate ttFire = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
    .trainerName = ttFireName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FIRE,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFireIntroText,
    .defeatText = ttFireDefeatText,
    .postbattleText = ttFirePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAGMA_MEMBER_M,
};


static const u8 ttWaterIntroText[] = _("intro text");
static const u8 ttWaterDefeatText[] = _("defeat text");
static const u8 ttWaterPostbattleText[] = _("postbattle text");
static const u8 ttWaterName[] = _("Flo");
static const struct TrainerTemplate ttWater = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_TUBER_F,
    .trainerName = ttWaterName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_WATER,
    .type2 = 0,
    .rarity = 1,
    .introText = ttWaterIntroText,
    .defeatText = ttWaterDefeatText,
    .postbattleText = ttWaterPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_TUBER_F,
};


static const u8 ttGrassIntroText[] = _("I've been planting the seeds\nof your defeat!");
static const u8 ttGrassDefeatText[] = _("Alright, I've had my clorophyll of this.");
static const u8 ttGrassPostbattleText[] = _("I wish you'd just\nsod off.");
static const u8 ttGrassName[] = _("Scott");
static const struct TrainerTemplate ttGrass = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
    .trainerName = ttGrassName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_GRASS,
    .type2 = 0,
    .rarity = 1,
    .introText = ttGrassIntroText,
    .defeatText = ttGrassDefeatText,
    .postbattleText = ttGrassPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_WOMAN_2,
};


static const u8 ttElectricIntroText[] = _("I'm amped up for this fight!");
static const u8 ttElectricDefeatText[] = _("Oh zap!\nWhat a shocking defeat!");
static const u8 ttElectricPostbattleText[] = _("I don't currently have\nanything to say to you.");
static const u8 ttElectricName[] = _("Julia");
static const struct TrainerTemplate ttElectric = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_NINJA_BOY,
    .trainerName = ttElectricName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_ELECTRIC,
    .type2 = 0,
    .rarity = 1,
    .introText = ttElectricIntroText,
    .defeatText = ttElectricDefeatText,
    .postbattleText = ttElectricPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_NINJA_BOY,
};


static const u8 ttPsychicIntroText[] = _("intro text");
static const u8 ttPsychicDefeatText[] = _("defeat text");
static const u8 ttPsychicPostbattleText[] = _("postbattle text");
static const u8 ttPsychicName[] = _("Sayeh");
static const struct TrainerTemplate ttPsychic = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_PSYCHIC_F,
    .trainerName = ttPsychicName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_PSYCHIC,
    .type2 = 0,
    .rarity = 1,
    .introText = ttPsychicIntroText,
    .defeatText = ttPsychicDefeatText,
    .postbattleText = ttPsychicPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_LASS,
};


static const u8 ttIceIntroText[] = _("intro text");
static const u8 ttIceDefeatText[] = _("defeat text");
static const u8 ttIcePostbattleText[] = _("postbattle text");
static const u8 ttIceName[] = _("Kelvin");
static const struct TrainerTemplate ttIce = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEFAN_F,
    .trainerName = ttIceName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_ICE,
    .type2 = 0,
    .rarity = 1,
    .introText = ttIceIntroText,
    .defeatText = ttIceDefeatText,
    .postbattleText = ttIcePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_POKEFAN_F,
};


static const u8 ttDragonIntroText[] = _("Well met good sir! Let us away\nto the field of battle!");
static const u8 ttDragonDefeatText[] = _("I have been bested\nby a worthy adversary!");
static const u8 ttDragonPostbattleText[] = _("I shall recover my mana\nand return to battle you anew!");
static const u8 ttDragonName[] = _("Archmage Stanley");
static const struct TrainerTemplate ttDragon = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_DRAGON_TAMER,
    .trainerName = ttDragonName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_DRAGON,
    .type2 = 0,
    .rarity = 1,
    .introText = ttDragonIntroText,
    .defeatText = ttDragonDefeatText,
    .postbattleText = ttDragonPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAN_3,
};


static const u8 ttDarkIntroText[] = _("I am the son and heir\nof nothing in particular.");
static const u8 ttDarkDefeatText[] = _("To die by your side\nis such a heavenly way to die.");
static const u8 ttDarkPostbattleText[] = _("Every day is like Sunday\nEvery day is silent and gray.");
static const u8 ttDarkName[] = _("Raven Batshade");
static const struct TrainerTemplate ttDark = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMANIAC,
    .trainerName = ttDarkName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_DARK,
    .type2 = 0,
    .rarity = 1,
    .introText = ttDarkIntroText,
    .defeatText = ttDarkDefeatText,
    .postbattleText = ttDarkPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MANIAC,
};


static const u8 ttFairyIntroText[] = _("intro text");
static const u8 ttFairyDefeatText[] = _("defeat text");
static const u8 ttFairyPostbattleText[] = _("postbattle text");
static const u8 ttFairyName[] = _("Yosei");
static const struct TrainerTemplate ttFairy = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
    .trainerName = ttFairyName,
    .partySize = 0,
    .party = {},
    .type1 = TYPE_FAIRY,
    .type2 = 0,
    .rarity = 1,
    .introText = ttFairyIntroText,
    .defeatText = ttFairyDefeatText,
    .postbattleText = ttFairyPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_ANABEL,
};

static const struct TrainerTemplate* const qTrainers[POSSIBLE_TRAINERS] = {
    &ttNormal,
    &ttFighting,
    &ttFlying,
    &ttPoison,
    &ttGround,
    &ttRock,
    &ttBug,
    &ttGhost,
    &ttSteel,
    &ttFire,
    &ttWater,
    &ttGrass,
    &ttElectric,
    &ttPsychic,
    &ttIce,
    &ttDragon,
    &ttDark,
    &ttFairy
};

static const int TrainerMonTypes[19][20] = {
    [TYPE_NORMAL] = {
        SPECIES_PIDGEY,
        SPECIES_RATTATA,
        SPECIES_SPEAROW,
        SPECIES_JIGGLYPUFF,
        SPECIES_MEOWTH,
        SPECIES_FARFETCHD,
        SPECIES_DODUO,
        SPECIES_LICKITUNG,
        SPECIES_CHANSEY,
        SPECIES_KANGASKHAN,
        SPECIES_TAUROS,
        SPECIES_DITTO,
        SPECIES_EEVEE,
        SPECIES_PORYGON,
        SPECIES_SNORLAX,
        SPECIES_SENTRET,
        SPECIES_HOOTHOOT,
        SPECIES_AIPOM,
        SPECIES_GIRAFARIG,
        SPECIES_DUNSPARCE
    },
    [TYPE_FIGHTING] = {
        SPECIES_MANKEY,
        SPECIES_MACHOP,
        SPECIES_FARFETCHD_GALARIAN,
        SPECIES_HITMONLEE,
        SPECIES_HITMONCHAN,
        SPECIES_ZAPDOS_GALARIAN,
        SPECIES_HERACROSS,
        SPECIES_HITMONTOP,
        SPECIES_COMBUSKEN,
        SPECIES_MAKUHITA,
        SPECIES_MEDITITE,
        SPECIES_RIOLU,
        SPECIES_CROAGUNK,
        SPECIES_TIMBURR,
        SPECIES_THROH,
        SPECIES_SAWK,
        SPECIES_SCRAGGY,
        SPECIES_MIENFOO,
        SPECIES_COBALION,
        SPECIES_TERRAKION
    },
    [TYPE_FLYING] = {
        SPECIES_PIDGEY,
        SPECIES_SPEAROW,
        SPECIES_ZUBAT,
        SPECIES_FARFETCHD,
        SPECIES_DODUO,
        SPECIES_SCYTHER,
        SPECIES_AERODACTYL,
        SPECIES_ARTICUNO,
        SPECIES_ARTICUNO_GALARIAN,
        SPECIES_ZAPDOS,
        SPECIES_ZAPDOS_GALARIAN,
        SPECIES_MOLTRES,
        SPECIES_MOLTRES_GALARIAN,
        SPECIES_HOOTHOOT,
        SPECIES_LEDYBA,
        SPECIES_NATU,
        SPECIES_HOPPIP,
        SPECIES_YANMA,
        SPECIES_MURKROW,
        SPECIES_GLIGAR
    },
    [TYPE_POISON] = {
        SPECIES_BULBASAUR,
        SPECIES_WEEDLE,
        SPECIES_EKANS,
        SPECIES_NIDORAN_M,
        SPECIES_NIDORAN_F,
        SPECIES_ZUBAT,
        SPECIES_ODDISH,
        SPECIES_VENONAT,
        SPECIES_BELLSPROUT,
        SPECIES_TENTACOOL,
        SPECIES_GRIMER,
        SPECIES_GRIMER_ALOLAN,
        SPECIES_GASTLY,
        SPECIES_KOFFING,
        SPECIES_SPINARAK,
        SPECIES_QWILFISH,
        SPECIES_BUDEW,
        SPECIES_GULPIN,
        SPECIES_SEVIPER,
        SPECIES_STUNKY
    },
    [TYPE_GROUND] = {
        SPECIES_SANDSHREW,
        SPECIES_DIGLETT,
        SPECIES_DIGLETT_ALOLAN,
        SPECIES_GEODUDE,
        SPECIES_ONIX,
        SPECIES_CUBONE,
        SPECIES_RHYHORN,
        SPECIES_WOOPER,
        SPECIES_GLIGAR,
        SPECIES_SWINUB,
        SPECIES_PHANPY,
        SPECIES_LARVITAR,
        SPECIES_NINCADA,
        SPECIES_NUMEL,
        SPECIES_TRAPINCH,
        SPECIES_BARBOACH,
        SPECIES_BALTOY,
        SPECIES_GROUDON,
        SPECIES_GIBLE,
        SPECIES_HIPPOPOTAS
    },
    [TYPE_ROCK] = {
        SPECIES_GEODUDE,
        SPECIES_GEODUDE_ALOLAN,
        SPECIES_ONIX,
        SPECIES_RHYHORN,
        SPECIES_OMANYTE,
        SPECIES_KABUTO,
        SPECIES_AERODACTYL,
        SPECIES_SUDOWOODO,
        SPECIES_SHUCKLE,
        SPECIES_CORSOLA,
        SPECIES_LARVITAR,
        SPECIES_NOSEPASS,
        SPECIES_ARON,
        SPECIES_LUNATONE,
        SPECIES_SOLROCK,
        SPECIES_LILEEP,
        SPECIES_ANORITH,
        SPECIES_RELICANTH,
        SPECIES_REGIROCK,
        SPECIES_CRANIDOS
    },
    [TYPE_BUG] = {
        SPECIES_CATERPIE,
        SPECIES_WEEDLE,
        SPECIES_PARAS,
        SPECIES_VENONAT,
        SPECIES_SCYTHER,
        SPECIES_PINSIR,
        SPECIES_LEDYBA,
        SPECIES_SPINARAK,
        SPECIES_PINECO,
        SPECIES_SHUCKLE,
        SPECIES_HERACROSS,
        SPECIES_WURMPLE,
        SPECIES_SURSKIT,
        SPECIES_NINCADA,
        SPECIES_VOLBEAT,
        SPECIES_ANORITH,
        SPECIES_KRICKETOT,
        SPECIES_BURMY,
        SPECIES_COMBEE,
        SPECIES_SKORUPI
    },
    [TYPE_GHOST] = {
        SPECIES_GASTLY,
        SPECIES_MISDREAVUS,
        SPECIES_CORSOLA_GALARIAN,
        SPECIES_SABLEYE,
        SPECIES_SHUPPET,
        SPECIES_DUSKULL,
        SPECIES_DRIFLOON,
        SPECIES_SPIRITOMB,
        SPECIES_ROTOM,
        SPECIES_GIRATINA,
        SPECIES_YAMASK,
        SPECIES_YAMASK_GALARIAN,
        SPECIES_FRILLISH,
        SPECIES_LITWICK,
        SPECIES_GOLETT,
        SPECIES_HONEDGE,
        SPECIES_PHANTUMP,
        SPECIES_PUMPKABOO,
        SPECIES_HOOPA,
        SPECIES_SANDYGAST
    },
    [TYPE_STEEL] = {
        SPECIES_SANDSHREW_ALOLAN,
        SPECIES_DIGLETT_ALOLAN,
        SPECIES_MEOWTH_GALARIAN,
        SPECIES_MAGNEMITE,
        SPECIES_SKARMORY,
        SPECIES_MAWILE,
        SPECIES_ARON,
        SPECIES_BELDUM,
        SPECIES_REGISTEEL,
        SPECIES_JIRACHI,
        SPECIES_SHIELDON,
        SPECIES_BRONZOR,
        SPECIES_DIALGA,
        SPECIES_HEATRAN,
        SPECIES_FERROSEED,
        SPECIES_KLINK,
        SPECIES_STUNFISK_GALARIAN,
        SPECIES_PAWNIARD,
        SPECIES_DURANT,
        SPECIES_COBALION
    },
    [TYPE_FIRE] = {
        SPECIES_CHARMANDER,
        SPECIES_VULPIX,
        SPECIES_GROWLITHE,
        SPECIES_PONYTA,
        SPECIES_MAGBY,
        SPECIES_MOLTRES,
        SPECIES_CYNDAQUIL,
        SPECIES_SLUGMA,
        SPECIES_HOUNDOUR,
        SPECIES_ENTEI,
        SPECIES_HO_OH,
        SPECIES_TORCHIC,
        SPECIES_NUMEL,
        SPECIES_TORKOAL,
        SPECIES_GROUDON_PRIMAL,
        SPECIES_CHIMCHAR,
        SPECIES_HEATRAN,
        SPECIES_VICTINI,
        SPECIES_TEPIG,
        SPECIES_PANSEAR
    },
    [TYPE_WATER] = {
        SPECIES_SQUIRTLE,
        SPECIES_PSYDUCK,
        SPECIES_POLIWAG,
        SPECIES_TENTACOOL,
        SPECIES_SLOWPOKE,
        SPECIES_SEEL,
        SPECIES_SHELLDER,
        SPECIES_KRABBY,
        SPECIES_HORSEA,
        SPECIES_GOLDEEN,
        SPECIES_STARYU,
        SPECIES_MAGIKARP,
        SPECIES_LAPRAS,
        SPECIES_OMANYTE,
        SPECIES_KABUTO,
        SPECIES_TOTODILE,
        SPECIES_CHINCHOU,
        SPECIES_WOOPER,
        SPECIES_QWILFISH,
        SPECIES_REMORAID
    },
    [TYPE_GRASS] = {
        SPECIES_BULBASAUR,
        SPECIES_ODDISH,
        SPECIES_PARAS,
        SPECIES_BELLSPROUT,
        SPECIES_EXEGGCUTE,
        SPECIES_TANGELA,
        SPECIES_CHIKORITA,
        SPECIES_HOPPIP,
        SPECIES_SUNKERN,
        SPECIES_CELEBI,
        SPECIES_TREECKO,
        SPECIES_LOTAD,
        SPECIES_SEEDOT,
        SPECIES_SHROOMISH,
        SPECIES_BUDEW,
        SPECIES_CACNEA,
        SPECIES_LILEEP,
        SPECIES_TROPIUS,
        SPECIES_TURTWIG,
        SPECIES_CHERUBI
    },
    [TYPE_ELECTRIC] = {
        SPECIES_PICHU,
        SPECIES_GEODUDE_ALOLAN,
        SPECIES_MAGNEMITE,
        SPECIES_VOLTORB,
        SPECIES_ELEKID,
        SPECIES_ZAPDOS,
        SPECIES_CHINCHOU,
        SPECIES_MAREEP,
        SPECIES_RAIKOU,
        SPECIES_ELECTRIKE,
        SPECIES_PLUSLE,
        SPECIES_MINUN,
        SPECIES_SHINX,
        SPECIES_PACHIRISU,
        SPECIES_ROTOM,
        SPECIES_BLITZLE,
        SPECIES_EMOLGA,
        SPECIES_JOLTIK,
        SPECIES_TYNAMO,
        SPECIES_STUNFISK
    },
    [TYPE_PSYCHIC] = {
        SPECIES_ABRA,
        SPECIES_PONYTA_GALARIAN,
        SPECIES_SLOWPOKE,
        SPECIES_SLOWPOKE_GALARIAN,
        SPECIES_DROWZEE,
        SPECIES_EXEGGCUTE,
        SPECIES_MIME_JR,
        SPECIES_MR_MIME_GALARIAN,
        SPECIES_SMOOCHUM,
        SPECIES_ARTICUNO_GALARIAN,
        SPECIES_MEWTWO,
        SPECIES_MEW,
        SPECIES_NATU,
        SPECIES_UNOWN,
        SPECIES_WYNAUT,
        SPECIES_GIRAFARIG,
        SPECIES_LUGIA,
        SPECIES_CELEBI,
        SPECIES_RALTS,
        SPECIES_MEDITITE
    },
    [TYPE_ICE] = {
        SPECIES_SANDSHREW_ALOLAN,
        SPECIES_VULPIX_ALOLAN,
        SPECIES_MR_MIME_GALARIAN,
        SPECIES_SMOOCHUM,
        SPECIES_LAPRAS,
        SPECIES_ARTICUNO,
        SPECIES_SNEASEL,
        SPECIES_SWINUB,
        SPECIES_DELIBIRD,
        SPECIES_SNORUNT,
        SPECIES_SPHEAL,
        SPECIES_REGICE,
        SPECIES_SNOVER,
        SPECIES_DARUMAKA_GALARIAN,
        SPECIES_VANILLITE,
        SPECIES_CUBCHOO,
        SPECIES_CRYOGONAL,
        SPECIES_KYUREM,
        SPECIES_AMAURA,
        SPECIES_BERGMITE
    },
    [TYPE_DRAGON] = {
        SPECIES_DRATINI,
        SPECIES_BAGON,
        SPECIES_LATIAS,
        SPECIES_LATIOS,
        SPECIES_RAYQUAZA,
        SPECIES_GIBLE,
        SPECIES_DIALGA,
        SPECIES_PALKIA,
        SPECIES_GIRATINA,
        SPECIES_AXEW,
        SPECIES_DRUDDIGON,
        SPECIES_DEINO,
        SPECIES_RESHIRAM,
        SPECIES_ZEKROM,
        SPECIES_KYUREM,
        SPECIES_TYRUNT,
        SPECIES_GOOMY,
        SPECIES_NOIBAT,
        SPECIES_ZYGARDE,
        SPECIES_TURTONATOR
    },
    [TYPE_DARK] = {
        SPECIES_RATTATA_ALOLAN,
        SPECIES_MEOWTH_ALOLAN,
        SPECIES_GRIMER_ALOLAN,
        SPECIES_MURKROW,
        SPECIES_SNEASEL,
        SPECIES_HOUNDOUR,
        SPECIES_POOCHYENA,
        SPECIES_ZIGZAGOON_GALARIAN,
        SPECIES_NUZLEAF,
        SPECIES_SABLEYE,
        SPECIES_CARVANHA,
        SPECIES_ABSOL,
        SPECIES_STUNKY,
        SPECIES_SPIRITOMB,
        SPECIES_DARKRAI,
        SPECIES_PURRLOIN,
        SPECIES_SANDILE,
        SPECIES_SCRAGGY,
        SPECIES_ZORUA,
        SPECIES_PAWNIARD
    },
    [TYPE_FAIRY] = {
        SPECIES_CLEFFA,
        SPECIES_IGGLYBUFF,
        SPECIES_MIME_JR,
        SPECIES_TOGEPI,
        SPECIES_AZURILL,
        SPECIES_SNUBBULL,
        SPECIES_RALTS,
        SPECIES_MAWILE,
        SPECIES_COTTONEE,
        SPECIES_FLABEBE,
        SPECIES_SPRITZEE,
        SPECIES_SWIRLIX,
        SPECIES_DEDENNE,
        SPECIES_CARBINK,
        SPECIES_KLEFKI,
        SPECIES_XERNEAS,
        SPECIES_DIANCIE,
        SPECIES_CUTIEFLY,
        SPECIES_MORELULL,
        SPECIES_MIMIKYU
    },
};
