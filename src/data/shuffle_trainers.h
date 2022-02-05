#define TRAINER_TYPE_COMMON 0
#define TRAINER_TYPE_ELITE 1
#define TRAINER_TYPE_CHAMPION 2
#define TRAINER_TYPE_VIOLET_GYM_MEMBER 3
#define TRAINER_TYPE_VIOLET_GYM_LEADER 4
#define TRAINER_TYPE_CERULEAN_GYM_MEMBER 5
#define TRAINER_TYPE_CERULEAN_GYM_LEADER 6
#define TOTAL_TRAINER_TYPES 7

#define POSSIBLE_COMMON_TRAINERS 18
#define POSSIBLE_ELITE_TRAINERS 1
#define POSSIBLE_CHAMPION_TRAINERS 0

#define POSSIBLE_VIOLET_GYM_MEMBERS 4
#define POSSIBLE_VIOLET_GYM_LEADERS 1
#define POSSIBLE_CERULEAN_GYM_MEMBERS 3
#define POSSIBLE_CERULEAN_GYM_LEADERS 1

static const u8 unknown_string[] = _("unknown");

static const int allTrainersCount[TOTAL_TRAINER_TYPES] = {
    POSSIBLE_COMMON_TRAINERS,
    POSSIBLE_ELITE_TRAINERS,
    POSSIBLE_CHAMPION_TRAINERS,
    POSSIBLE_VIOLET_GYM_MEMBERS,
    POSSIBLE_VIOLET_GYM_LEADERS,
    POSSIBLE_CERULEAN_GYM_MEMBERS,
    POSSIBLE_CERULEAN_GYM_LEADERS,
};

static const struct TrainerMonNoItemDefaultMoves etHoldemJoeParty[] = {
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
static const u8 etHoldemJoeIntroText[] = _("test intro 1");
static const u8 etHoldemJoeDefeatText[] = _("test defeat 1");
static const u8 etHoldemJoePostbattleText[] = _("postbattle 1");
static const u8 etHoldemJoeName[] = _("HoldemJoe");
static const struct TrainerTemplate etHoldemJoe = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = etHoldemJoeName,
    .partySize = 4,
    .poolSize = 4,
    .party = {.NoItemDefaultMoves = etHoldemJoeParty},
    .introText = etHoldemJoeIntroText,
    .defeatText = etHoldemJoeDefeatText,
    .postbattleText = etHoldemJoePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_LITTLE_BOY,
};
        
static const struct TrainerMonNoItemDefaultMoves ctNormalParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_PIDGEY },
    { .iv = 0, .lvl = 1, .species = SPECIES_RATTATA },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPEAROW },
    { .iv = 0, .lvl = 1, .species = SPECIES_JIGGLYPUFF },
    { .iv = 0, .lvl = 1, .species = SPECIES_MEOWTH },
    { .iv = 0, .lvl = 1, .species = SPECIES_FARFETCHD },
    { .iv = 0, .lvl = 1, .species = SPECIES_DODUO },
    { .iv = 0, .lvl = 1, .species = SPECIES_LICKITUNG },
    { .iv = 0, .lvl = 1, .species = SPECIES_CHANSEY },
    { .iv = 0, .lvl = 1, .species = SPECIES_KANGASKHAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_TAUROS },
    { .iv = 0, .lvl = 1, .species = SPECIES_DITTO },
    { .iv = 0, .lvl = 1, .species = SPECIES_EEVEE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PORYGON },
    { .iv = 0, .lvl = 1, .species = SPECIES_SNORLAX },
    { .iv = 0, .lvl = 1, .species = SPECIES_SENTRET },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOOTHOOT },
    { .iv = 0, .lvl = 1, .species = SPECIES_AIPOM },
    { .iv = 0, .lvl = 1, .species = SPECIES_GIRAFARIG },
    { .iv = 0, .lvl = 1, .species = SPECIES_DUNSPARCE },
};
static const u8 ctNormalIntroText[] = _("I am challenging you\nto a Pokémon battle.");
static const u8 ctNormalDefeatText[] = _("You won the\nPokémon battle.");
static const u8 ctNormalPostbattleText[] = _("We had a Pokémon battle\nand you won it.");
static const u8 ctNormalName[] = _("Normán");
static const struct TrainerTemplate ctNormal = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GENTLEMAN,
    .trainerName = ctNormalName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctNormalParty},
    .introText = ctNormalIntroText,
    .defeatText = ctNormalDefeatText,
    .postbattleText = ctNormalPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_GENTLEMAN,
};
        
static const struct TrainerMonNoItemDefaultMoves ctFightingParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_MANKEY },
    { .iv = 0, .lvl = 1, .species = SPECIES_MACHOP },
    { .iv = 0, .lvl = 1, .species = SPECIES_FARFETCHD_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_HITMONLEE },
    { .iv = 0, .lvl = 1, .species = SPECIES_HITMONCHAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZAPDOS_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_HERACROSS },
    { .iv = 0, .lvl = 1, .species = SPECIES_HITMONTOP },
    { .iv = 0, .lvl = 1, .species = SPECIES_COMBUSKEN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAKUHITA },
    { .iv = 0, .lvl = 1, .species = SPECIES_MEDITITE },
    { .iv = 0, .lvl = 1, .species = SPECIES_RIOLU },
    { .iv = 0, .lvl = 1, .species = SPECIES_CROAGUNK },
    { .iv = 0, .lvl = 1, .species = SPECIES_TIMBURR },
    { .iv = 0, .lvl = 1, .species = SPECIES_THROH },
    { .iv = 0, .lvl = 1, .species = SPECIES_SAWK },
    { .iv = 0, .lvl = 1, .species = SPECIES_SCRAGGY },
    { .iv = 0, .lvl = 1, .species = SPECIES_MIENFOO },
    { .iv = 0, .lvl = 1, .species = SPECIES_COBALION },
    { .iv = 0, .lvl = 1, .species = SPECIES_TERRAKION },
};
static const u8 ctFightingIntroText[] = _("intro text");
static const u8 ctFightingDefeatText[] = _("defeat text");
static const u8 ctFightingPostbattleText[] = _("postbattle text");
static const u8 ctFightingName[] = _("Santo");
static const struct TrainerTemplate ctFighting = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BLACK_BELT,
    .trainerName = ctFightingName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctFightingParty},
    .introText = ctFightingIntroText,
    .defeatText = ctFightingDefeatText,
    .postbattleText = ctFightingPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BLACK_BELT,
};
        
static const struct TrainerMonNoItemDefaultMoves ctFlyingParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_PIDGEY },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPEAROW },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZUBAT },
    { .iv = 0, .lvl = 1, .species = SPECIES_FARFETCHD },
    { .iv = 0, .lvl = 1, .species = SPECIES_DODUO },
    { .iv = 0, .lvl = 1, .species = SPECIES_SCYTHER },
    { .iv = 0, .lvl = 1, .species = SPECIES_AERODACTYL },
    { .iv = 0, .lvl = 1, .species = SPECIES_ARTICUNO },
    { .iv = 0, .lvl = 1, .species = SPECIES_ARTICUNO_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZAPDOS },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZAPDOS_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MOLTRES },
    { .iv = 0, .lvl = 1, .species = SPECIES_MOLTRES_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOOTHOOT },
    { .iv = 0, .lvl = 1, .species = SPECIES_LEDYBA },
    { .iv = 0, .lvl = 1, .species = SPECIES_NATU },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOPPIP },
    { .iv = 0, .lvl = 1, .species = SPECIES_YANMA },
    { .iv = 0, .lvl = 1, .species = SPECIES_MURKROW },
    { .iv = 0, .lvl = 1, .species = SPECIES_GLIGAR },
};
static const u8 ctFlyingIntroText[] = _("This is your captain speaking...\nI'm gonna kick your tail!");
static const u8 ctFlyingDefeatText[] = _("I'm stalling out!\nMayday! Mayday!");
static const u8 ctFlyingPostbattleText[] = _("You need a major\naltitude adjustment!");
static const u8 ctFlyingName[] = _("Joan Jet");
static const struct TrainerTemplate ctFlying = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = ctFlyingName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctFlyingParty},
    .introText = ctFlyingIntroText,
    .defeatText = ctFlyingDefeatText,
    .postbattleText = ctFlyingPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};
        
static const struct TrainerMonNoItemDefaultMoves ctPoisonParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_BULBASAUR },
    { .iv = 0, .lvl = 1, .species = SPECIES_WEEDLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_EKANS },
    { .iv = 0, .lvl = 1, .species = SPECIES_NIDORAN_M },
    { .iv = 0, .lvl = 1, .species = SPECIES_NIDORAN_F },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZUBAT },
    { .iv = 0, .lvl = 1, .species = SPECIES_ODDISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_VENONAT },
    { .iv = 0, .lvl = 1, .species = SPECIES_BELLSPROUT },
    { .iv = 0, .lvl = 1, .species = SPECIES_TENTACOOL },
    { .iv = 0, .lvl = 1, .species = SPECIES_GRIMER },
    { .iv = 0, .lvl = 1, .species = SPECIES_GRIMER_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_GASTLY },
    { .iv = 0, .lvl = 1, .species = SPECIES_KOFFING },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPINARAK },
    { .iv = 0, .lvl = 1, .species = SPECIES_QWILFISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_BUDEW },
    { .iv = 0, .lvl = 1, .species = SPECIES_GULPIN },
    { .iv = 0, .lvl = 1, .species = SPECIES_SEVIPER },
    { .iv = 0, .lvl = 1, .species = SPECIES_STUNKY },
};
static const u8 ctPoisonIntroText[] = _("intro text");
static const u8 ctPoisonDefeatText[] = _("defeat text");
static const u8 ctPoisonPostbattleText[] = _("postbattle text");
static const u8 ctPoisonName[] = _("Mr. Yuk");
static const struct TrainerTemplate ctPoison = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
    .trainerName = ctPoisonName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctPoisonParty},
    .introText = ctPoisonIntroText,
    .defeatText = ctPoisonDefeatText,
    .postbattleText = ctPoisonPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_AQUA_MEMBER_F,
};
        
static const struct TrainerMonNoItemDefaultMoves ctGroundParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_SANDSHREW },
    { .iv = 0, .lvl = 1, .species = SPECIES_DIGLETT },
    { .iv = 0, .lvl = 1, .species = SPECIES_DIGLETT_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_GEODUDE },
    { .iv = 0, .lvl = 1, .species = SPECIES_ONIX },
    { .iv = 0, .lvl = 1, .species = SPECIES_CUBONE },
    { .iv = 0, .lvl = 1, .species = SPECIES_RHYHORN },
    { .iv = 0, .lvl = 1, .species = SPECIES_WOOPER },
    { .iv = 0, .lvl = 1, .species = SPECIES_GLIGAR },
    { .iv = 0, .lvl = 1, .species = SPECIES_SWINUB },
    { .iv = 0, .lvl = 1, .species = SPECIES_PHANPY },
    { .iv = 0, .lvl = 1, .species = SPECIES_LARVITAR },
    { .iv = 0, .lvl = 1, .species = SPECIES_NINCADA },
    { .iv = 0, .lvl = 1, .species = SPECIES_NUMEL },
    { .iv = 0, .lvl = 1, .species = SPECIES_TRAPINCH },
    { .iv = 0, .lvl = 1, .species = SPECIES_BARBOACH },
    { .iv = 0, .lvl = 1, .species = SPECIES_BALTOY },
    { .iv = 0, .lvl = 1, .species = SPECIES_GROUDON },
    { .iv = 0, .lvl = 1, .species = SPECIES_GIBLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_HIPPOPOTAS },
};
static const u8 ctGroundIntroText[] = _("Runnin' my fingers through this\nhere soil... makes me feel alive.");
static const u8 ctGroundDefeatText[] = _("Not much left to harvest\nnow that rains stopped comin'.");
static const u8 ctGroundPostbattleText[] = _("You live and die\nby what the land gives ya.");
static const u8 ctGroundName[] = _("Farmer Jed");
static const struct TrainerTemplate ctGround = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_RUIN_MANIAC,
    .trainerName = ctGroundName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctGroundParty},
    .introText = ctGroundIntroText,
    .defeatText = ctGroundDefeatText,
    .postbattleText = ctGroundPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_SCIENTIST_1,
};
        
static const struct TrainerMonNoItemDefaultMoves ctRockParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_GEODUDE },
    { .iv = 0, .lvl = 1, .species = SPECIES_GEODUDE_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_ONIX },
    { .iv = 0, .lvl = 1, .species = SPECIES_RHYHORN },
    { .iv = 0, .lvl = 1, .species = SPECIES_OMANYTE },
    { .iv = 0, .lvl = 1, .species = SPECIES_KABUTO },
    { .iv = 0, .lvl = 1, .species = SPECIES_AERODACTYL },
    { .iv = 0, .lvl = 1, .species = SPECIES_SUDOWOODO },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHUCKLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_CORSOLA },
    { .iv = 0, .lvl = 1, .species = SPECIES_LARVITAR },
    { .iv = 0, .lvl = 1, .species = SPECIES_NOSEPASS },
    { .iv = 0, .lvl = 1, .species = SPECIES_ARON },
    { .iv = 0, .lvl = 1, .species = SPECIES_LUNATONE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SOLROCK },
    { .iv = 0, .lvl = 1, .species = SPECIES_LILEEP },
    { .iv = 0, .lvl = 1, .species = SPECIES_ANORITH },
    { .iv = 0, .lvl = 1, .species = SPECIES_RELICANTH },
    { .iv = 0, .lvl = 1, .species = SPECIES_REGIROCK },
    { .iv = 0, .lvl = 1, .species = SPECIES_CRANIDOS },
};
static const u8 ctRockIntroText[] = _("intro text");
static const u8 ctRockDefeatText[] = _("defeat text");
static const u8 ctRockPostbattleText[] = _("postbattle text");
static const u8 ctRockName[] = _("Kimberly");
static const struct TrainerTemplate ctRock = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = ctRockName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctRockParty},
    .introText = ctRockIntroText,
    .defeatText = ctRockDefeatText,
    .postbattleText = ctRockPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_HIKER,
};
        
static const struct TrainerMonNoItemDefaultMoves ctBugParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_CATERPIE },
    { .iv = 0, .lvl = 1, .species = SPECIES_WEEDLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PARAS },
    { .iv = 0, .lvl = 1, .species = SPECIES_VENONAT },
    { .iv = 0, .lvl = 1, .species = SPECIES_SCYTHER },
    { .iv = 0, .lvl = 1, .species = SPECIES_PINSIR },
    { .iv = 0, .lvl = 1, .species = SPECIES_LEDYBA },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPINARAK },
    { .iv = 0, .lvl = 1, .species = SPECIES_PINECO },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHUCKLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_HERACROSS },
    { .iv = 0, .lvl = 1, .species = SPECIES_WURMPLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SURSKIT },
    { .iv = 0, .lvl = 1, .species = SPECIES_NINCADA },
    { .iv = 0, .lvl = 1, .species = SPECIES_VOLBEAT },
    { .iv = 0, .lvl = 1, .species = SPECIES_ANORITH },
    { .iv = 0, .lvl = 1, .species = SPECIES_KRICKETOT },
    { .iv = 0, .lvl = 1, .species = SPECIES_BURMY },
    { .iv = 0, .lvl = 1, .species = SPECIES_COMBEE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SKORUPI },
};
static const u8 ctBugIntroText[] = _("intro text");
static const u8 ctBugDefeatText[] = _("defeat text");
static const u8 ctBugPostbattleText[] = _("postbattle text");
static const u8 ctBugName[] = _("Bea");
static const struct TrainerTemplate ctBug = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BUG_CATCHER,
    .trainerName = ctBugName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctBugParty},
    .introText = ctBugIntroText,
    .defeatText = ctBugDefeatText,
    .postbattleText = ctBugPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BUG_CATCHER,
};
        
static const struct TrainerMonNoItemDefaultMoves ctGhostParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_GASTLY },
    { .iv = 0, .lvl = 1, .species = SPECIES_MISDREAVUS },
    { .iv = 0, .lvl = 1, .species = SPECIES_CORSOLA_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_SABLEYE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHUPPET },
    { .iv = 0, .lvl = 1, .species = SPECIES_DUSKULL },
    { .iv = 0, .lvl = 1, .species = SPECIES_DRIFLOON },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPIRITOMB },
    { .iv = 0, .lvl = 1, .species = SPECIES_ROTOM },
    { .iv = 0, .lvl = 1, .species = SPECIES_GIRATINA },
    { .iv = 0, .lvl = 1, .species = SPECIES_YAMASK },
    { .iv = 0, .lvl = 1, .species = SPECIES_YAMASK_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_FRILLISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_LITWICK },
    { .iv = 0, .lvl = 1, .species = SPECIES_GOLETT },
    { .iv = 0, .lvl = 1, .species = SPECIES_HONEDGE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PHANTUMP },
    { .iv = 0, .lvl = 1, .species = SPECIES_PUMPKABOO },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOOPA },
    { .iv = 0, .lvl = 1, .species = SPECIES_SANDYGAST },
};
static const u8 ctGhostIntroText[] = _("intro text");
static const u8 ctGhostDefeatText[] = _("defeat text");
static const u8 ctGhostPostbattleText[] = _("postbattle text");
static const u8 ctGhostName[] = _("Clyde");
static const struct TrainerTemplate ctGhost = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HEX_MANIAC,
    .trainerName = ctGhostName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctGhostParty},
    .introText = ctGhostIntroText,
    .defeatText = ctGhostDefeatText,
    .postbattleText = ctGhostPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_HEX_MANIAC,
};
        
static const struct TrainerMonNoItemDefaultMoves ctSteelParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_SANDSHREW_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_DIGLETT_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MEOWTH_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAGNEMITE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SKARMORY },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAWILE },
    { .iv = 0, .lvl = 1, .species = SPECIES_ARON },
    { .iv = 0, .lvl = 1, .species = SPECIES_BELDUM },
    { .iv = 0, .lvl = 1, .species = SPECIES_REGISTEEL },
    { .iv = 0, .lvl = 1, .species = SPECIES_JIRACHI },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHIELDON },
    { .iv = 0, .lvl = 1, .species = SPECIES_BRONZOR },
    { .iv = 0, .lvl = 1, .species = SPECIES_DIALGA },
    { .iv = 0, .lvl = 1, .species = SPECIES_HEATRAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_FERROSEED },
    { .iv = 0, .lvl = 1, .species = SPECIES_KLINK },
    { .iv = 0, .lvl = 1, .species = SPECIES_STUNFISK_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_PAWNIARD },
    { .iv = 0, .lvl = 1, .species = SPECIES_DURANT },
    { .iv = 0, .lvl = 1, .species = SPECIES_COBALION },
};
static const u8 ctSteelIntroText[] = _("Let's battle NOW! YOW!");
static const u8 ctSteelDefeatText[] = _("You beat me HOW?! YOW!");
static const u8 ctSteelPostbattleText[] = _("My jokes are too HIGHBROW! YOW!");
static const u8 ctSteelName[] = _("David Defeis");
static const struct TrainerTemplate ctSteel = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GUITARIST,
    .trainerName = ctSteelName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctSteelParty},
    .introText = ctSteelIntroText,
    .defeatText = ctSteelDefeatText,
    .postbattleText = ctSteelPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAN_5,
};

static const struct TrainerMonNoItemDefaultMoves ctFireParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_CHARMANDER },
    { .iv = 0, .lvl = 1, .species = SPECIES_VULPIX },
    { .iv = 0, .lvl = 1, .species = SPECIES_GROWLITHE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PONYTA },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAGBY },
    { .iv = 0, .lvl = 1, .species = SPECIES_MOLTRES },
    { .iv = 0, .lvl = 1, .species = SPECIES_CYNDAQUIL },
    { .iv = 0, .lvl = 1, .species = SPECIES_SLUGMA },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOUNDOUR },
    { .iv = 0, .lvl = 1, .species = SPECIES_ENTEI },
    { .iv = 0, .lvl = 1, .species = SPECIES_HO_OH },
    { .iv = 0, .lvl = 1, .species = SPECIES_TORCHIC },
    { .iv = 0, .lvl = 1, .species = SPECIES_NUMEL },
    { .iv = 0, .lvl = 1, .species = SPECIES_TORKOAL },
    { .iv = 0, .lvl = 1, .species = SPECIES_GROUDON_PRIMAL },
    { .iv = 0, .lvl = 1, .species = SPECIES_CHIMCHAR },
    { .iv = 0, .lvl = 1, .species = SPECIES_HEATRAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_VICTINI },
    { .iv = 0, .lvl = 1, .species = SPECIES_TEPIG },
    { .iv = 0, .lvl = 1, .species = SPECIES_PANSEAR },
};
static const u8 ctFireIntroText[] = _("Man it's a hot one.");
static const u8 ctFireDefeatText[] = _("Like seven inches from the midday\nsun.");
static const u8 ctFirePostbattleText[] = _("Give me your heart,\nmake it real.");
static const u8 ctFireName[] = _("Rob Thomas ft. Santana");
static const struct TrainerTemplate ctFire = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
    .trainerName = ctFireName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctFireParty},
    .introText = ctFireIntroText,
    .defeatText = ctFireDefeatText,
    .postbattleText = ctFirePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAGMA_MEMBER_M,
};
        
static const struct TrainerMonNoItemDefaultMoves ctWaterParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_SQUIRTLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PSYDUCK },
    { .iv = 0, .lvl = 1, .species = SPECIES_POLIWAG },
    { .iv = 0, .lvl = 1, .species = SPECIES_TENTACOOL },
    { .iv = 0, .lvl = 1, .species = SPECIES_SLOWPOKE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SEEL },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHELLDER },
    { .iv = 0, .lvl = 1, .species = SPECIES_KRABBY },
    { .iv = 0, .lvl = 1, .species = SPECIES_HORSEA },
    { .iv = 0, .lvl = 1, .species = SPECIES_GOLDEEN },
    { .iv = 0, .lvl = 1, .species = SPECIES_STARYU },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAGIKARP },
    { .iv = 0, .lvl = 1, .species = SPECIES_LAPRAS },
    { .iv = 0, .lvl = 1, .species = SPECIES_OMANYTE },
    { .iv = 0, .lvl = 1, .species = SPECIES_KABUTO },
    { .iv = 0, .lvl = 1, .species = SPECIES_TOTODILE },
    { .iv = 0, .lvl = 1, .species = SPECIES_CHINCHOU },
    { .iv = 0, .lvl = 1, .species = SPECIES_WOOPER },
    { .iv = 0, .lvl = 1, .species = SPECIES_QWILFISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_REMORAID },
};
static const u8 ctWaterIntroText[] = _("intro text");
static const u8 ctWaterDefeatText[] = _("defeat text");
static const u8 ctWaterPostbattleText[] = _("postbattle text");
static const u8 ctWaterName[] = _("Flo");
static const struct TrainerTemplate ctWater = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_TUBER_F,
    .trainerName = ctWaterName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctWaterParty},
    .introText = ctWaterIntroText,
    .defeatText = ctWaterDefeatText,
    .postbattleText = ctWaterPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_TUBER_F,
};
        
static const struct TrainerMonNoItemDefaultMoves ctGrassParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_BULBASAUR },
    { .iv = 0, .lvl = 1, .species = SPECIES_ODDISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_PARAS },
    { .iv = 0, .lvl = 1, .species = SPECIES_BELLSPROUT },
    { .iv = 0, .lvl = 1, .species = SPECIES_EXEGGCUTE },
    { .iv = 0, .lvl = 1, .species = SPECIES_TANGELA },
    { .iv = 0, .lvl = 1, .species = SPECIES_CHIKORITA },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOPPIP },
    { .iv = 0, .lvl = 1, .species = SPECIES_SUNKERN },
    { .iv = 0, .lvl = 1, .species = SPECIES_CELEBI },
    { .iv = 0, .lvl = 1, .species = SPECIES_TREECKO },
    { .iv = 0, .lvl = 1, .species = SPECIES_LOTAD },
    { .iv = 0, .lvl = 1, .species = SPECIES_SEEDOT },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHROOMISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_BUDEW },
    { .iv = 0, .lvl = 1, .species = SPECIES_CACNEA },
    { .iv = 0, .lvl = 1, .species = SPECIES_LILEEP },
    { .iv = 0, .lvl = 1, .species = SPECIES_TROPIUS },
    { .iv = 0, .lvl = 1, .species = SPECIES_TURTWIG },
    { .iv = 0, .lvl = 1, .species = SPECIES_CHERUBI },
};
static const u8 ctGrassIntroText[] = _("I've been planting the seeds\nof your defeat!");
static const u8 ctGrassDefeatText[] = _("Alright, I've had my clorophyll of this.");
static const u8 ctGrassPostbattleText[] = _("I wish you'd just\nsod off.");
static const u8 ctGrassName[] = _("Scott");
static const struct TrainerTemplate ctGrass = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
    .trainerName = ctGrassName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctGrassParty},
    .introText = ctGrassIntroText,
    .defeatText = ctGrassDefeatText,
    .postbattleText = ctGrassPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_WOMAN_2,
};
        
static const struct TrainerMonNoItemDefaultMoves ctElectricParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_PICHU },
    { .iv = 0, .lvl = 1, .species = SPECIES_GEODUDE_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAGNEMITE },
    { .iv = 0, .lvl = 1, .species = SPECIES_VOLTORB },
    { .iv = 0, .lvl = 1, .species = SPECIES_ELEKID },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZAPDOS },
    { .iv = 0, .lvl = 1, .species = SPECIES_CHINCHOU },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAREEP },
    { .iv = 0, .lvl = 1, .species = SPECIES_RAIKOU },
    { .iv = 0, .lvl = 1, .species = SPECIES_ELECTRIKE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PLUSLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_MINUN },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHINX },
    { .iv = 0, .lvl = 1, .species = SPECIES_PACHIRISU },
    { .iv = 0, .lvl = 1, .species = SPECIES_ROTOM },
    { .iv = 0, .lvl = 1, .species = SPECIES_BLITZLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_EMOLGA },
    { .iv = 0, .lvl = 1, .species = SPECIES_JOLTIK },
    { .iv = 0, .lvl = 1, .species = SPECIES_TYNAMO },
    { .iv = 0, .lvl = 1, .species = SPECIES_STUNFISK },
};
static const u8 ctElectricIntroText[] = _("I'm amped up for this fight!");
static const u8 ctElectricDefeatText[] = _("Oh zap!\nWhat a shocking defeat!");
static const u8 ctElectricPostbattleText[] = _("I don't currently have\nanything to say to you.");
static const u8 ctElectricName[] = _("Julia");
static const struct TrainerTemplate ctElectric = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_NINJA_BOY,
    .trainerName = ctElectricName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctElectricParty},
    .introText = ctElectricIntroText,
    .defeatText = ctElectricDefeatText,
    .postbattleText = ctElectricPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_NINJA_BOY,
};
        
static const struct TrainerMonNoItemDefaultMoves ctPsychicParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_ABRA },
    { .iv = 0, .lvl = 1, .species = SPECIES_PONYTA_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_SLOWPOKE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SLOWPOKE_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_DROWZEE },
    { .iv = 0, .lvl = 1, .species = SPECIES_EXEGGCUTE },
    { .iv = 0, .lvl = 1, .species = SPECIES_MIME_JR },
    { .iv = 0, .lvl = 1, .species = SPECIES_MR_MIME_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_SMOOCHUM },
    { .iv = 0, .lvl = 1, .species = SPECIES_ARTICUNO_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MEWTWO },
    { .iv = 0, .lvl = 1, .species = SPECIES_MEW },
    { .iv = 0, .lvl = 1, .species = SPECIES_NATU },
    { .iv = 0, .lvl = 1, .species = SPECIES_UNOWN },
    { .iv = 0, .lvl = 1, .species = SPECIES_WYNAUT },
    { .iv = 0, .lvl = 1, .species = SPECIES_GIRAFARIG },
    { .iv = 0, .lvl = 1, .species = SPECIES_LUGIA },
    { .iv = 0, .lvl = 1, .species = SPECIES_CELEBI },
    { .iv = 0, .lvl = 1, .species = SPECIES_RALTS },
    { .iv = 0, .lvl = 1, .species = SPECIES_MEDITITE },
};
static const u8 ctPsychicIntroText[] = _("intro text");
static const u8 ctPsychicDefeatText[] = _("defeat text");
static const u8 ctPsychicPostbattleText[] = _("postbattle text");
static const u8 ctPsychicName[] = _("Sayeh");
static const struct TrainerTemplate ctPsychic = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_PSYCHIC_F,
    .trainerName = ctPsychicName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctPsychicParty},
    .introText = ctPsychicIntroText,
    .defeatText = ctPsychicDefeatText,
    .postbattleText = ctPsychicPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_LASS,
};
        
static const struct TrainerMonNoItemDefaultMoves ctIceParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_SANDSHREW_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_VULPIX_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MR_MIME_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_SMOOCHUM },
    { .iv = 0, .lvl = 1, .species = SPECIES_LAPRAS },
    { .iv = 0, .lvl = 1, .species = SPECIES_ARTICUNO },
    { .iv = 0, .lvl = 1, .species = SPECIES_SNEASEL },
    { .iv = 0, .lvl = 1, .species = SPECIES_SWINUB },
    { .iv = 0, .lvl = 1, .species = SPECIES_DELIBIRD },
    { .iv = 0, .lvl = 1, .species = SPECIES_SNORUNT },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPHEAL },
    { .iv = 0, .lvl = 1, .species = SPECIES_REGICE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SNOVER },
    { .iv = 0, .lvl = 1, .species = SPECIES_DARUMAKA_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_VANILLITE },
    { .iv = 0, .lvl = 1, .species = SPECIES_CUBCHOO },
    { .iv = 0, .lvl = 1, .species = SPECIES_CRYOGONAL },
    { .iv = 0, .lvl = 1, .species = SPECIES_KYUREM },
    { .iv = 0, .lvl = 1, .species = SPECIES_AMAURA },
    { .iv = 0, .lvl = 1, .species = SPECIES_BERGMITE },
};
static const u8 ctIceIntroText[] = _("intro text");
static const u8 ctIceDefeatText[] = _("defeat text");
static const u8 ctIcePostbattleText[] = _("postbattle text");
static const u8 ctIceName[] = _("Kelvin");
static const struct TrainerTemplate ctIce = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEFAN_F,
    .trainerName = ctIceName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctIceParty},
    .introText = ctIceIntroText,
    .defeatText = ctIceDefeatText,
    .postbattleText = ctIcePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_POKEFAN_F,
};
        
static const struct TrainerMonNoItemDefaultMoves ctDragonParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_DRATINI },
    { .iv = 0, .lvl = 1, .species = SPECIES_BAGON },
    { .iv = 0, .lvl = 1, .species = SPECIES_LATIAS },
    { .iv = 0, .lvl = 1, .species = SPECIES_LATIOS },
    { .iv = 0, .lvl = 1, .species = SPECIES_RAYQUAZA },
    { .iv = 0, .lvl = 1, .species = SPECIES_GIBLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_DIALGA },
    { .iv = 0, .lvl = 1, .species = SPECIES_PALKIA },
    { .iv = 0, .lvl = 1, .species = SPECIES_GIRATINA },
    { .iv = 0, .lvl = 1, .species = SPECIES_AXEW },
    { .iv = 0, .lvl = 1, .species = SPECIES_DRUDDIGON },
    { .iv = 0, .lvl = 1, .species = SPECIES_DEINO },
    { .iv = 0, .lvl = 1, .species = SPECIES_RESHIRAM },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZEKROM },
    { .iv = 0, .lvl = 1, .species = SPECIES_KYUREM },
    { .iv = 0, .lvl = 1, .species = SPECIES_TYRUNT },
    { .iv = 0, .lvl = 1, .species = SPECIES_GOOMY },
    { .iv = 0, .lvl = 1, .species = SPECIES_NOIBAT },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZYGARDE },
    { .iv = 0, .lvl = 1, .species = SPECIES_TURTONATOR },
};
static const u8 ctDragonIntroText[] = _("Well met good sir! Let us away\nto the field of battle!");
static const u8 ctDragonDefeatText[] = _("I have been bested\nby a worthy adversary!");
static const u8 ctDragonPostbattleText[] = _("I shall recover my mana\nand return to battle you anew!");
static const u8 ctDragonName[] = _("Archmage Stanley");
static const struct TrainerTemplate ctDragon = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_DRAGON_TAMER,
    .trainerName = ctDragonName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctDragonParty},
    .introText = ctDragonIntroText,
    .defeatText = ctDragonDefeatText,
    .postbattleText = ctDragonPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAN_3,
};
        
static const struct TrainerMonNoItemDefaultMoves ctDarkParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_RATTATA_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MEOWTH_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_GRIMER_ALOLAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_MURKROW },
    { .iv = 0, .lvl = 1, .species = SPECIES_SNEASEL },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOUNDOUR },
    { .iv = 0, .lvl = 1, .species = SPECIES_POOCHYENA },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZIGZAGOON_GALARIAN },
    { .iv = 0, .lvl = 1, .species = SPECIES_NUZLEAF },
    { .iv = 0, .lvl = 1, .species = SPECIES_SABLEYE },
    { .iv = 0, .lvl = 1, .species = SPECIES_CARVANHA },
    { .iv = 0, .lvl = 1, .species = SPECIES_ABSOL },
    { .iv = 0, .lvl = 1, .species = SPECIES_STUNKY },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPIRITOMB },
    { .iv = 0, .lvl = 1, .species = SPECIES_DARKRAI },
    { .iv = 0, .lvl = 1, .species = SPECIES_PURRLOIN },
    { .iv = 0, .lvl = 1, .species = SPECIES_SANDILE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SCRAGGY },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZORUA },
    { .iv = 0, .lvl = 1, .species = SPECIES_PAWNIARD },
};
static const u8 ctDarkIntroText[] = _("I am the son and heir\nof nothing in particular.");
static const u8 ctDarkDefeatText[] = _("To die by your side\nis such a heavenly way to die.");
static const u8 ctDarkPostbattleText[] = _("Every day is like Sunday\nEvery day is silent and gray.");
static const u8 ctDarkName[] = _("Raven Batshade");
static const struct TrainerTemplate ctDark = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMANIAC,
    .trainerName = ctDarkName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctDarkParty},
    .introText = ctDarkIntroText,
    .defeatText = ctDarkDefeatText,
    .postbattleText = ctDarkPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MANIAC,
};

static const struct TrainerMonNoItemDefaultMoves ctFairyParty[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_CLEFFA },
    { .iv = 0, .lvl = 1, .species = SPECIES_IGGLYBUFF },
    { .iv = 0, .lvl = 1, .species = SPECIES_MIME_JR },
    { .iv = 0, .lvl = 1, .species = SPECIES_TOGEPI },
    { .iv = 0, .lvl = 1, .species = SPECIES_AZURILL },
    { .iv = 0, .lvl = 1, .species = SPECIES_SNUBBULL },
    { .iv = 0, .lvl = 1, .species = SPECIES_RALTS },
    { .iv = 0, .lvl = 1, .species = SPECIES_MAWILE },
    { .iv = 0, .lvl = 1, .species = SPECIES_COTTONEE },
    { .iv = 0, .lvl = 1, .species = SPECIES_FLABEBE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPRITZEE },
    { .iv = 0, .lvl = 1, .species = SPECIES_SWIRLIX },
    { .iv = 0, .lvl = 1, .species = SPECIES_DEDENNE },
    { .iv = 0, .lvl = 1, .species = SPECIES_CARBINK },
    { .iv = 0, .lvl = 1, .species = SPECIES_KLEFKI },
    { .iv = 0, .lvl = 1, .species = SPECIES_XERNEAS },
    { .iv = 0, .lvl = 1, .species = SPECIES_DIANCIE },
    { .iv = 0, .lvl = 1, .species = SPECIES_CUTIEFLY },
    { .iv = 0, .lvl = 1, .species = SPECIES_MORELULL },
    { .iv = 0, .lvl = 1, .species = SPECIES_MIMIKYU },
};
static const u8 ctFairyIntroText[] = _("intro text");
static const u8 ctFairyDefeatText[] = _("defeat text");
static const u8 ctFairyPostbattleText[] = _("postbattle text");
static const u8 ctFairyName[] = _("Yosei");
static const struct TrainerTemplate ctFairy = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
    .trainerName = ctFairyName,
    .partySize = 2,
    .poolSize = 20,
    .party = {.NoItemDefaultMoves = ctFairyParty},
    .introText = ctFairyIntroText,
    .defeatText = ctFairyDefeatText,
    .postbattleText = ctFairyPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_ANABEL,
};

static const struct TrainerMonNoItemDefaultMoves gmViolet1Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_PIDOVE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PIDGEY },
    { .iv = 0, .lvl = 1, .species = SPECIES_DODUO },
    { .iv = 0, .lvl = 1, .species = SPECIES_TAILLOW },
    { .iv = 0, .lvl = 1, .species = SPECIES_PIDOVE },
    { .iv = 0, .lvl = 1, .species = SPECIES_PIDGEY },
    { .iv = 0, .lvl = 1, .species = SPECIES_DODUO },
    { .iv = 0, .lvl = 1, .species = SPECIES_TAILLOW },
};
static const u8 gmViolet1IntroText[] = _("intro text");
static const u8 gmViolet1DefeatText[] = _("defeat text");
static const u8 gmViolet1PostbattleText[] = _("postbattle text");
static const u8 gmViolet1Name[] = _("Violet Gym Member 1");
static const struct TrainerTemplate gmViolet1 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet1Name,
    .partySize = 3,
    .poolSize = 8,
    .party = {.NoItemDefaultMoves = gmViolet1Party},
    .introText = gmViolet1IntroText,
    .defeatText = gmViolet1DefeatText,
    .postbattleText = gmViolet1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct TrainerMonNoItemDefaultMoves gmViolet2Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_TOGETIC },
    { .iv = 0, .lvl = 1, .species = SPECIES_GYARADOS },
    { .iv = 0, .lvl = 1, .species = SPECIES_ZUBAT },
    { .iv = 0, .lvl = 1, .species = SPECIES_YANMA },
    { .iv = 0, .lvl = 1, .species = SPECIES_VULLABY },
    { .iv = 0, .lvl = 1, .species = SPECIES_HAWLUCHA },
};
static const u8 gmViolet2IntroText[] = _("intro text");
static const u8 gmViolet2DefeatText[] = _("defeat text");
static const u8 gmViolet2PostbattleText[] = _("postbattle text");
static const u8 gmViolet2Name[] = _("Violet Gym Member 2");
static const struct TrainerTemplate gmViolet2 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet2Name,
    .partySize = 2,
    .poolSize = 6,
    .party = {.NoItemDefaultMoves = gmViolet2Party},
    .introText = gmViolet2IntroText,
    .defeatText = gmViolet2DefeatText,
    .postbattleText = gmViolet2PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct TrainerMonNoItemDefaultMoves gmViolet3Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_FLETCHLING },
    { .iv = 0, .lvl = 1, .species = SPECIES_DRIFLOON },
    { .iv = 0, .lvl = 1, .species = SPECIES_SWABLU },
    { .iv = 0, .lvl = 1, .species = SPECIES_PIKIPEK },
    { .iv = 0, .lvl = 1, .species = SPECIES_NATU },
    { .iv = 0, .lvl = 1, .species = SPECIES_SKARMORY },
    { .iv = 0, .lvl = 1, .species = SPECIES_TROPIUS },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOPPIP },
};
static const u8 gmViolet3IntroText[] = _("intro text");
static const u8 gmViolet3DefeatText[] = _("defeat text");
static const u8 gmViolet3PostbattleText[] = _("postbattle text");
static const u8 gmViolet3Name[] = _("Violet Gym Member 3");
static const struct TrainerTemplate gmViolet3 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet3Name,
    .partySize = 3,
    .poolSize = 8,
    .party = {.NoItemDefaultMoves = gmViolet3Party},
    .introText = gmViolet3IntroText,
    .defeatText = gmViolet3DefeatText,
    .postbattleText = gmViolet3PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct TrainerMonNoItemDefaultMoves gmViolet4Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_ORICORIO },
    { .iv = 0, .lvl = 1, .species = SPECIES_ORICORIO_PAU },
    { .iv = 0, .lvl = 1, .species = SPECIES_ORICORIO_POM_POM },
    { .iv = 0, .lvl = 1, .species = SPECIES_ORICORIO_SENSU },
};
static const u8 gmViolet4IntroText[] = _("intro text");
static const u8 gmViolet4DefeatText[] = _("defeat text");
static const u8 gmViolet4PostbattleText[] = _("postbattle text");
static const u8 gmViolet4Name[] = _("Violet Gym Member 4");
static const struct TrainerTemplate gmViolet4 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet4Name,
    .partySize = 2,
    .poolSize = 4,
    .party = {.NoItemDefaultMoves = gmViolet4Party},
    .introText = gmViolet4IntroText,
    .defeatText = gmViolet4DefeatText,
    .postbattleText = gmViolet4PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct TrainerMonItemDefaultMoves glViolet1Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_STARLY, .heldItem = ITEM_LUM_BERRY },
    { .iv = 0, .lvl = 1, .species = SPECIES_HOOTHOOT, .heldItem = ITEM_SITRUS_BERRY },
    { .iv = 0, .lvl = 1, .species = SPECIES_TAILLOW, .heldItem = ITEM_ENIGMA_BERRY },
    { .iv = 0, .lvl = 1, .species = SPECIES_MURKROW, .heldItem = ITEM_JABOCA_BERRY },
    { .iv = 0, .lvl = 1, .species = SPECIES_WINGULL, .heldItem = ITEM_WACAN_BERRY },
    { .iv = 0, .lvl = 1, .species = SPECIES_PIDGEY, .heldItem = ITEM_LANSAT_BERRY },
};
static const u8 glViolet1IntroText[] = _("intro text");
static const u8 glViolet1DefeatText[] = _("defeat text");
static const u8 glViolet1PostbattleText[] = _("postbattle text");
static const u8 glViolet1Name[] = _("Falkner 1");
static const struct TrainerTemplate glViolet1 = {
    .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = glViolet1Name,
    .partySize = 6,
    .poolSize = 6,
    .party = {.ItemDefaultMoves = glViolet1Party},
    .introText = glViolet1IntroText,
    .defeatText = glViolet1DefeatText,
    .postbattleText = glViolet1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct TrainerMonNoItemDefaultMoves gmCerulean1Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_SQUIRTLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_TOTODILE },
    { .iv = 0, .lvl = 1, .species = SPECIES_MUDKIP },
    { .iv = 0, .lvl = 1, .species = SPECIES_PIPLUP },
    { .iv = 0, .lvl = 1, .species = SPECIES_OSHAWOTT },
    { .iv = 0, .lvl = 1, .species = SPECIES_FROAKIE },
    { .iv = 0, .lvl = 1, .species = SPECIES_POPPLIO },
    { .iv = 0, .lvl = 1, .species = SPECIES_SOBBLE },
    { .iv = 0, .lvl = 1, .species = SPECIES_VAPOREON },
};
static const u8 gmCerulean1IntroText[] = _("intro text");
static const u8 gmCerulean1DefeatText[] = _("defeat text");
static const u8 gmCerulean1PostbattleText[] = _("postbattle text");
static const u8 gmCerulean1Name[] = _("Cerulean Gym Member 1");
static const struct TrainerTemplate gmCerulean1 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SWIMMER_F,
    .trainerName = gmCerulean1Name,
    .partySize = 3,
    .poolSize = 9,
    .party = {.NoItemDefaultMoves = gmCerulean1Party},
    .introText = gmCerulean1IntroText,
    .defeatText = gmCerulean1DefeatText,
    .postbattleText = gmCerulean1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_SWIMMER_F,
};

static const struct TrainerMonNoItemDefaultMoves gmCerulean2Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_CORSOLA },
    { .iv = 0, .lvl = 1, .species = SPECIES_SPHEAL },
    { .iv = 0, .lvl = 1, .species = SPECIES_PYUKUMUKU },
    { .iv = 0, .lvl = 1, .species = SPECIES_MARILL },
    { .iv = 0, .lvl = 1, .species = SPECIES_HORSEA },
    { .iv = 0, .lvl = 1, .species = SPECIES_WINGULL },
    { .iv = 0, .lvl = 1, .species = SPECIES_DEWPIDER },
    { .iv = 0, .lvl = 1, .species = SPECIES_CORPHISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_DUCKLETT },
    { .iv = 0, .lvl = 1, .species = SPECIES_SEEL },
    { .iv = 0, .lvl = 1, .species = SPECIES_KRABBY },
    { .iv = 0, .lvl = 1, .species = SPECIES_SHELLOS },
    { .iv = 0, .lvl = 1, .species = SPECIES_CRAMORANT },
    { .iv = 0, .lvl = 1, .species = SPECIES_OCTILLERY },
    { .iv = 0, .lvl = 1, .species = SPECIES_LOTAD },
    { .iv = 0, .lvl = 1, .species = SPECIES_FRILLISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_OMANYTE },
    { .iv = 0, .lvl = 1, .species = SPECIES_KABUTO },
};
static const u8 gmCerulean2IntroText[] = _("intro text");
static const u8 gmCerulean2DefeatText[] = _("defeat text");
static const u8 gmCerulean2PostbattleText[] = _("postbattle text");
static const u8 gmCerulean2Name[] = _("Cerulean Gym Member 2");
static const struct TrainerTemplate gmCerulean2 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SWIMMER_M,
    .trainerName = gmCerulean2Name,
    .partySize = 2,
    .poolSize = 4,
    .party = {.NoItemDefaultMoves = gmCerulean2Party},
    .introText = gmCerulean2IntroText,
    .defeatText = gmCerulean2DefeatText,
    .postbattleText = gmCerulean2PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_SWIMMER_M,
};

static const struct TrainerMonNoItemDefaultMoves gmCerulean3Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_QWILFISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_GOLDEEN },
    { .iv = 0, .lvl = 1, .species = SPECIES_CHINCHOU },
    { .iv = 0, .lvl = 1, .species = SPECIES_CARVANHA },
    { .iv = 0, .lvl = 1, .species = SPECIES_FINNEON },
    { .iv = 0, .lvl = 1, .species = SPECIES_BASCULIN },
    { .iv = 0, .lvl = 1, .species = SPECIES_BASCULIN_BLUE_STRIPED },
    { .iv = 0, .lvl = 1, .species = SPECIES_BARBOACH },
    { .iv = 0, .lvl = 1, .species = SPECIES_ALOMOMOLA },
    { .iv = 0, .lvl = 1, .species = SPECIES_BRUXISH },
    { .iv = 0, .lvl = 1, .species = SPECIES_RELICANTH },
};
static const u8 gmCerulean3IntroText[] = _("intro text");
static const u8 gmCerulean3DefeatText[] = _("defeat text");
static const u8 gmCerulean3PostbattleText[] = _("postbattle text");
static const u8 gmCerulean3Name[] = _("Cerulean Gym Member 3");
static const struct TrainerTemplate gmCerulean3 = {
    .partyFlags = 0,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_TUBER_M,
    .trainerName = gmCerulean3Name,
    .partySize = 2,
    .poolSize = 4,
    .party = {.NoItemDefaultMoves = gmCerulean3Party},
    .introText = gmCerulean3IntroText,
    .defeatText = gmCerulean3DefeatText,
    .postbattleText = gmCerulean3PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_TUBER_M_SWIMMING,
};

static const struct TrainerMonNoItemCustomMoves glCerulean1Party[] = {
    { .iv = 0, .lvl = 1, .species = SPECIES_PSYDUCK, .moves = { MOVE_DISABLE, MOVE_CONFUSION, MOVE_FURY_SWIPES, MOVE_BODY_SLAM } },
    { .iv = 0, .lvl = 1, .species = SPECIES_PSYDUCK, .moves = { MOVE_SCALD, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_LIGHT_SCREEN } },
    { .iv = 0, .lvl = 1, .species = SPECIES_SEEL, .moves = { MOVE_AQUA_JET, MOVE_ICE_SHARD, MOVE_WATERFALL, MOVE_IRON_TAIL } },
    { .iv = 0, .lvl = 1, .species = SPECIES_SEEL, .moves = { MOVE_BLIZZARD, MOVE_REST, MOVE_TAKE_DOWN, MOVE_SURF } },
    { .iv = 0, .lvl = 1, .species = SPECIES_VAPOREON, .moves = { MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_QUICK_ATTACK, MOVE_SHADOW_BALL } },
    { .iv = 0, .lvl = 1, .species = SPECIES_STARYU, .moves = { MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_RECOVER, MOVE_ICE_BEAM } },
    { .iv = 0, .lvl = 1, .species = SPECIES_STARYU, .moves = { MOVE_SCALD, MOVE_SWIFT, MOVE_PSYWAVE, MOVE_NONE } },
    { .iv = 0, .lvl = 1, .species = SPECIES_GYARADOS, .moves = { MOVE_WATERFALL, MOVE_CRUNCH, MOVE_OUTRAGE, MOVE_IRON_TAIL } },
    { .iv = 0, .lvl = 1, .species = SPECIES_LAPRAS, .moves = { MOVE_SURF, MOVE_PERISH_SONG, MOVE_BLIZZARD, MOVE_RAIN_DANCE } },
    { .iv = 0, .lvl = 1, .species = SPECIES_LAPRAS, .moves = { MOVE_ICE_BEAM, MOVE_SING, MOVE_WATER_PULSE, MOVE_BODY_SLAM } },
    { .iv = 0, .lvl = 1, .species = SPECIES_WOOPER, .moves = { MOVE_WATER_PULSE, MOVE_AMNESIA, MOVE_RAIN_DANCE, MOVE_EARTHQUAKE } },
    { .iv = 0, .lvl = 1, .species = SPECIES_SQUIRTLE, .moves = { MOVE_HYDRO_PUMP, MOVE_DIG, MOVE_BITE, MOVE_SEISMIC_TOSS } },
    { .iv = 0, .lvl = 1, .species = SPECIES_HORSEA, .moves = { MOVE_SMOKESCREEN, MOVE_SURF, MOVE_TOXIC, MOVE_ICE_BEAM } },
    { .iv = 0, .lvl = 1, .species = SPECIES_HORSEA, .moves = { MOVE_RAIN_DANCE, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM } },
    { .iv = 0, .lvl = 1, .species = SPECIES_POLIWAG, .moves = { MOVE_RAIN_DANCE, MOVE_EARTHQUAKE, MOVE_HYDRO_PUMP, MOVE_BODY_SLAM } },
};
static const u8 glCerulean1IntroText[] = _("intro text");
static const u8 glCerulean1DefeatText[] = _("defeat text");
static const u8 glCerulean1PostbattleText[] = _("postbattle text");
static const u8 glCerulean1Name[] = _("Misty 1");
static const struct TrainerTemplate glCerulean1 = {
    .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = glCerulean1Name,
    .partySize = 6,
    .poolSize = 15,
    .party = {.NoItemCustomMoves = glCerulean1Party},
    .introText = glCerulean1IntroText,
    .defeatText = glCerulean1DefeatText,
    .postbattleText = glCerulean1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct TrainerTemplate* const commonTrainers[POSSIBLE_COMMON_TRAINERS] = {
    &ctNormal,
    &ctFighting,
    &ctFlying,
    &ctPoison,
    &ctGround,
    &ctRock,
    &ctBug,
    &ctGhost,
    &ctSteel,
    &ctFire,
    &ctWater,
    &ctGrass,
    &ctElectric,
    &ctPsychic,
    &ctIce,
    &ctDragon,
    &ctDark,
    &ctFairy
};
static const struct TrainerTemplate* const violetGymMembers[POSSIBLE_VIOLET_GYM_MEMBERS] = {
    &gmViolet1,
    &gmViolet2,
    &gmViolet3,
    &gmViolet4,
};
static const struct TrainerTemplate* const violetGymLeaders[POSSIBLE_VIOLET_GYM_LEADERS] = {
    &glViolet1
};
static const struct TrainerTemplate* const ceruleanGymMembers[POSSIBLE_CERULEAN_GYM_MEMBERS] = {
    &gmCerulean1,
    &gmCerulean2,
    &gmCerulean3,
};
static const struct TrainerTemplate* const ceruleanGymLeaders[POSSIBLE_CERULEAN_GYM_LEADERS] = {
    &glCerulean1
};
static const struct TrainerTemplate* const eliteTrainers[POSSIBLE_ELITE_TRAINERS] = {
    &etHoldemJoe,
};
static const struct TrainerTemplate** const allTrainers[TOTAL_TRAINER_TYPES] = {
    &commonTrainers,
    &eliteTrainers,
    NULL, // champions
    &violetGymMembers,
    &violetGymLeaders,
    &ceruleanGymMembers,
    &ceruleanGymLeaders
};
