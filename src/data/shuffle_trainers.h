#define TRAINER_TYPE_COMMON 0
#define TRAINER_TYPE_ELITE 1
#define TRAINER_TYPE_CHAMPION 2
#define TRAINER_TYPE_VIOLET_GYM_MEMBER 3
#define TRAINER_TYPE_VIOLET_GYM_LEADER 4
#define TRAINER_TYPE_CERULEAN_GYM_MEMBER 5
#define TRAINER_TYPE_CERULEAN_GYM_LEADER 6
#define TRAINER_TYPE_CELADON_GYM_MEMBER 7
#define TRAINER_TYPE_CELADON_GYM_LEADER 8
#define TOTAL_TRAINER_TYPES 9

#define POSSIBLE_COMMON_TRAINERS 18
#define POSSIBLE_ELITE_TRAINERS 1
#define POSSIBLE_CHAMPION_TRAINERS 0

#define POSSIBLE_VIOLET_GYM_MEMBERS 4
#define POSSIBLE_VIOLET_GYM_LEADERS 1
#define POSSIBLE_CERULEAN_GYM_MEMBERS 3
#define POSSIBLE_CERULEAN_GYM_LEADERS 1
#define POSSIBLE_CELADON_GYM_MEMBERS 4
#define POSSIBLE_CELADON_GYM_LEADERS 2

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

static const struct PokemonTemplate etHoldemJoeParty[] = {
    { .species = SPECIES_SCRAGGY },
    { .species = SPECIES_GASTLY },
    { .species = SPECIES_JOLTEON },
    { .species = SPECIES_DUSKULL },
};
static const u8 etHoldemJoeIntroText[] = _("elite intro");
static const u8 etHoldemJoeDefeatText[] = _("elite defeat");
static const u8 etHoldemJoePostbattleText[] = _("elite postbattle");
static const u8 etHoldemJoeName[] = _("HoldemJoe");
static const struct TrainerTemplate etHoldemJoe = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = etHoldemJoeName,
    .partySize = 4,
    .poolSize = 4,
    .party = &etHoldemJoeParty,
    .introText = etHoldemJoeIntroText,
    .defeatText = etHoldemJoeDefeatText,
    .postbattleText = etHoldemJoePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_LITTLE_BOY,
};
        
static const struct PokemonTemplate ctNormalParty[] = {
    { .species = SPECIES_MUNCHLAX }, // friendship
    { .species = SPECIES_HAPPINY }, // oval stone / friendship
    { .species = SPECIES_PORYGON }, // trade / trade
    { .species = SPECIES_ZIGZAGOON },
    { .species = SPECIES_ZIGZAGOON_GALARIAN },
    { .species = SPECIES_LICKITUNG }, // rollout level 33
    { .species = SPECIES_RUFFLET },
    { .species = SPECIES_LITLEO },
    { .species = SPECIES_TEDDIURSA },
    { .species = SPECIES_LILLIPUP },
    { .species = SPECIES_STUFFUL },
    { .species = SPECIES_KANGASKHAN },
    { .species = SPECIES_TAUROS },
    { .species = SPECIES_MILTANK },
    { .species = SPECIES_WHISMUR },
    { .species = SPECIES_BOUFFALANT },
    { .species = SPECIES_ORANGURU },
    { .species = SPECIES_WOOLOO },
    { .species = SPECIES_PIDOVE },
    { .species = SPECIES_STARLY },
    { .species = SPECIES_PIKIPEK },
    { .species = SPECIES_DRAMPA },
    { .species = SPECIES_AIPOM }, // double hit level 32
    { .species = SPECIES_HELIOPTILE }, // sun stone
    { .species = SPECIES_BUNEARY }, // friendship
    { .species = SPECIES_KOMALA },
    { .species = SPECIES_PIDGEY },
    { .species = SPECIES_DEERLING },
    { .species = SPECIES_INDEEDEE },
    { .species = SPECIES_INDEEDEE_FEMALE },
    { .species = SPECIES_FURFROU },
    { .species = SPECIES_DODUO },
    { .species = SPECIES_MINCCINO }, // shiny stone
    { .species = SPECIES_STANTLER },
    { .species = SPECIES_SKWOVET },
    { .species = SPECIES_ZANGOOSE },
    { .species = SPECIES_GIRAFARIG },
    { .species = SPECIES_TAILLOW },
    { .species = SPECIES_HOOTHOOT },
    { .species = SPECIES_GLAMEOW },
    { .species = SPECIES_AUDINO },
    { .species = SPECIES_SPEAROW },
    { .species = SPECIES_MEOWTH },
    { .species = SPECIES_SLAKOTH },
    { .species = SPECIES_KECLEON },
    { .species = SPECIES_JIGGLYPUFF }, // friendship / moon stone
    { .species = SPECIES_EEVEE, .evoStrat = EVO_STRAT_DO_NOT },
    { .species = SPECIES_BUNNELBY },
    { .species = SPECIES_CASTFORM },
    { .species = SPECIES_PATRAT },
    { .species = SPECIES_YUNGOOS },
    { .species = SPECIES_SENTRET },
    { .species = SPECIES_DUNSPARCE },
    { .species = SPECIES_RATTATA },
    { .species = SPECIES_RATTATA_ALOLAN },
    { .species = SPECIES_CHATOT },
    { .species = SPECIES_BIDOOF },
    { .species = SPECIES_SKITTY }, // moon stone
    { .species = SPECIES_FARFETCHD },
    { .species = SPECIES_SPINDA },
    { .species = SPECIES_SWABLU, .maxLevel = 34 },
    { .species = SPECIES_DITTO },
    { .species = SPECIES_SMEARGLE },
    { .species = SPECIES_AZURILL, .maxLevel = 9, .evoStrat = EVO_STRAT_DO_NOT },
};
static const u8 ctNormalIntroText[] = _("I am challenging you\nto a Pokémon battle.");
static const u8 ctNormalDefeatText[] = _("You won the\nPokémon battle.");
static const u8 ctNormalPostbattleText[] = _("We had a Pokémon battle\nand you won it.");
static const u8 ctNormalName[] = _("Normán");
static const struct TrainerTemplate ctNormal = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GENTLEMAN,
    .trainerName = ctNormalName,
    .partySize = 2,
    .poolSize = 64,
    .party = &ctNormalParty,
    .introText = ctNormalIntroText,
    .defeatText = ctNormalDefeatText,
    .postbattleText = ctNormalPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_GENTLEMAN,
};
        
static const struct PokemonTemplate ctFightingParty[] = {
    { .species = SPECIES_HAKAMO_O, .minLevel = 35 },
    { .species = SPECIES_MONFERNO, .minLevel = 14 },
    { .species = SPECIES_COMBUSKEN, .minLevel = 16 },
    { .species = SPECIES_CHESNAUGHT, .minLevel = 36 },
    { .species = SPECIES_PIGNITE, .minLevel = 17 },
    { .species = SPECIES_RIOLU },
    { .species = SPECIES_GALLADE, .minLevel = 20 }, // kirlia -> gallade via dawn stone, not sure what level to make this
    { .species = SPECIES_MIENFOO },
    { .species = SPECIES_POLIWRATH, .minLevel = 25 }, // poliwhirl -> poliwrath via water stone, not sure what level to make this
    { .species = SPECIES_FARFETCHD_GALARIAN }, // 3 crits in 1 battle
    { .species = SPECIES_TIMBURR }, // lvl / trade
    { .species = SPECIES_MACHOP }, // lvl / trade
    { .species = SPECIES_STUFFUL },
    { .species = SPECIES_HAWLUCHA },
    { .species = SPECIES_HERACROSS },
    { .species = SPECIES_PANCHAM }, // lvl but with dark in party
    { .species = SPECIES_PASSIMIAN },
    { .species = SPECIES_CROAGUNK },
    { .species = SPECIES_SCRAGGY },
    { .species = SPECIES_CLOBBOPUS }, // taunt level 35
    { .species = SPECIES_CRABRAWLER }, // location
    { .species = SPECIES_MAKUHITA },
    { .species = SPECIES_FALINKS },
    { .species = SPECIES_SAWK },
    { .species = SPECIES_THROH },
    { .species = SPECIES_BRELOOM, .minLevel = 23 },
    { .species = SPECIES_TYROGUE },
    { .species = SPECIES_MANKEY },
    { .species = SPECIES_MEDITITE },
};
static const u8 ctFightingIntroText[] = _("intro text");
static const u8 ctFightingDefeatText[] = _("defeat text");
static const u8 ctFightingPostbattleText[] = _("postbattle text");
static const u8 ctFightingName[] = _("Santo");
static const struct TrainerTemplate ctFighting = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BLACK_BELT,
    .trainerName = ctFightingName,
    .partySize = 2,
    .poolSize = 29,
    .party = &ctFightingParty,
    .introText = ctFightingIntroText,
    .defeatText = ctFightingDefeatText,
    .postbattleText = ctFightingPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BLACK_BELT,
};

static const struct PokemonTemplate ctFlyingParty[] = {
    { .species = SPECIES_DRAGONITE, .minLevel = 55 },
    { .species = SPECIES_SALAMENCE, .minLevel = 50 },
    { .species = SPECIES_ARCHEN },
    { .species = SPECIES_TOGETIC }, // friendship / shiny stone
    { .species = SPECIES_GYARADOS, .minLevel = 20 },
    { .species = SPECIES_ZUBAT }, // lvl / friendship
    { .species = SPECIES_NOIBAT },
    { .species = SPECIES_CHARIZARD, .minLevel = 36 },
    { .species = SPECIES_ROTOM_FAN },
    { .species = SPECIES_AERODACTYL },
    { .species = SPECIES_YANMA }, // ancient power level 33
    { .species = SPECIES_GLIGAR }, // hold item
    { .species = SPECIES_RUFFLET },
    { .species = SPECIES_VULLABY },
    { .species = SPECIES_MURKROW }, // dusk stone
    { .species = SPECIES_SCYTHER, .evoStrat = EVO_STRAT_DO_NOT },
    { .species = SPECIES_HAWLUCHA },
    { .species = SPECIES_MINIOR },
    { .species = SPECIES_FLETCHLING },
    { .species = SPECIES_DRIFLOON },
    { .species = SPECIES_ROOKIDEE },
    { .species = SPECIES_SWABLU },
    { .species = SPECIES_SIGILYPH },
    { .species = SPECIES_PIDOVE },
    { .species = SPECIES_MANTYKE }, // remoraid in party
    { .species = SPECIES_STARLY },
    { .species = SPECIES_PIKIPEK },
    { .species = SPECIES_PIDGEY },
    { .species = SPECIES_ORICORIO },
    { .species = SPECIES_ORICORIO_POM_POM },
    { .species = SPECIES_ORICORIO_PAU },
    { .species = SPECIES_ORICORIO_SENSU },
    { .species = SPECIES_CRAMORANT },
    { .species = SPECIES_COMBEE },
    { .species = SPECIES_DUCKLETT },
    { .species = SPECIES_NATU },
    { .species = SPECIES_DODUO },
    { .species = SPECIES_SKARMORY },
    { .species = SPECIES_TROPIUS },
    { .species = SPECIES_HOPPIP },
    { .species = SPECIES_NINJASK, .minLevel = 20 },
    { .species = SPECIES_TAILLOW },
    { .species = SPECIES_MASQUERAIN, .minLevel = 22 },
    { .species = SPECIES_HOOTHOOT },
    { .species = SPECIES_SPEAROW },
    { .species = SPECIES_WINGULL },
    { .species = SPECIES_EMOLGA },
    { .species = SPECIES_WOOBAT }, // friendship
    { .species = SPECIES_MOTHIM, .minLevel = 20 },
    { .species = SPECIES_ROWLET, .maxLevel = 33 },
    { .species = SPECIES_VIVILLON, .minLevel = 12 },
    { .species = SPECIES_CHATOT },
    { .species = SPECIES_BEAUTIFLY, .minLevel = 10 },
    { .species = SPECIES_DUSTOX, .minLevel = 10 },
    { .species = SPECIES_BUTTERFREE, .minLevel = 10 },
    { .species = SPECIES_LEDYBA },
    { .species = SPECIES_FARFETCHD },
    { .species = SPECIES_DELIBIRD },
};
static const u8 ctFlyingIntroText[] = _("This is your captain speaking...\nI'm gonna kick your tail!");
static const u8 ctFlyingDefeatText[] = _("I'm stalling out!\nMayday! Mayday!");
static const u8 ctFlyingPostbattleText[] = _("You need a major\naltitude adjustment!");
static const u8 ctFlyingName[] = _("Joan Jet");
static const struct TrainerTemplate ctFlying = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = ctFlyingName,
    .partySize = 2,
    .poolSize = 58,
    .party = &ctFlyingParty,
    .introText = ctFlyingIntroText,
    .defeatText = ctFlyingDefeatText,
    .postbattleText = ctFlyingPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct PokemonTemplate ctPoisonParty[] = {
    { .species = SPECIES_ZUBAT }, // lvl / friendship
    { .species = SPECIES_BULBASAUR },
    { .species = SPECIES_TENTACOOL },
    { .species = SPECIES_BUDEW }, // friendship / shiny stone
    { .species = SPECIES_NIDORAN_F }, // lvl / moon stone
    { .species = SPECIES_NIDORAN_M }, // lvl / moon stone
    { .species = SPECIES_TOXEL }, // lvl with nature requirement
    { .species = SPECIES_GRIMER },
    { .species = SPECIES_GRIMER_ALOLAN },
    { .species = SPECIES_GASTLY }, // lvl / trade
    { .species = SPECIES_SKORUPI },
    { .species = SPECIES_MAREANIE },
    { .species = SPECIES_SKRELP },
    { .species = SPECIES_ODDISH, .evoStrat = EVO_STRAT_NO_BELLOSSOM }, // lvl / leaf stone
    { .species = SPECIES_BELLSPROUT }, // lvl / leaf stone
    { .species = SPECIES_SLOWBRO_GALARIAN }, // item
    { .species = SPECIES_SLOWKING_GALARIAN }, // item
    { .species = SPECIES_KOFFING },
    { .species = SPECIES_CROAGUNK },
    { .species = SPECIES_VENIPEDE },
    { .species = SPECIES_SALANDIT },
    { .species = SPECIES_STUNKY },
    { .species = SPECIES_TRUBBISH },
    { .species = SPECIES_GULPIN },
    { .species = SPECIES_FOONGUS },
    { .species = SPECIES_SEVIPER },
    { .species = SPECIES_VENONAT },
    { .species = SPECIES_EKANS },
    { .species = SPECIES_QWILFISH },
    // { .species = SPECIES_QWILFISH_HISUIAN },
    { .species = SPECIES_SPINARAK },
    { .species = SPECIES_WEEDLE },
    { .species = SPECIES_DUSTOX, .minLevel = 10 },
};
static const u8 ctPoisonIntroText[] = _("intro text");
static const u8 ctPoisonDefeatText[] = _("defeat text");
static const u8 ctPoisonPostbattleText[] = _("postbattle text");
static const u8 ctPoisonName[] = _("Mr. Yuk");
static const struct TrainerTemplate ctPoison = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_AQUA_GRUNT_F,
    .trainerName = ctPoisonName,
    .partySize = 2,
    .poolSize = 32,
    .party = &ctPoisonParty,
    .introText = ctPoisonIntroText,
    .defeatText = ctPoisonDefeatText,
    .postbattleText = ctPoisonPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_AQUA_MEMBER_F,
};

static const struct PokemonTemplate ctGroundParty[] = {
    { .species = SPECIES_GIBLE },
    { .species = SPECIES_MARSHTOMP, .minLevel = 16 },
    { .species = SPECIES_RHYHORN }, // lvl / trade
    { .species = SPECIES_SWINUB }, // lvl / ancient power at 1
    { .species = SPECIES_TORTERRA, .minLevel = 32 },
    { .species = SPECIES_HIPPOPOTAS },
    { .species = SPECIES_TRAPINCH },
    { .species = SPECIES_SANDILE },
    { .species = SPECIES_ONIX }, // trade
    { .species = SPECIES_GLIGAR }, // item
    { .species = SPECIES_SILICOBRA },
    { .species = SPECIES_PALPITOAD, .minLevel = 25 },
    { .species = SPECIES_DRILBUR },
    { .species = SPECIES_NIDOQUEEN, .minLevel = 16 }, // lvl / item
    { .species = SPECIES_NIDOKING, .minLevel = 16 }, // lvl / item
    { .species = SPECIES_PHANPY },
    { .species = SPECIES_BALTOY },
    { .species = SPECIES_MUDBRAY },
    { .species = SPECIES_GEODUDE }, // lvl / trade
    { .species = SPECIES_GOLETT },
    { .species = SPECIES_YAMASK_GALARIAN }, // area
    { .species = SPECIES_SANDYGAST },
    { .species = SPECIES_GASTRODON, .minLevel = 30 },
    { .species = SPECIES_STUNFISK },
    { .species = SPECIES_STUNFISK_GALARIAN },
    { .species = SPECIES_BARBOACH },
    { .species = SPECIES_NUMEL },
    { .species = SPECIES_SANDSHREW },
    { .species = SPECIES_WOOPER },
    { .species = SPECIES_DIGLETT },
    { .species = SPECIES_DIGLETT_ALOLAN },
    { .species = SPECIES_CUBONE, .evoStrat = EVO_STRAT_NO_MAROWAK_ALOLAN },
    { .species = SPECIES_WORMADAM_SANDY_CLOAK, .minLevel = 20 },
    { .species = SPECIES_DIGGERSBY, .minLevel = 20 },
    { .species = SPECIES_LARVITAR, .maxLevel = 54 },
    { .species = SPECIES_NINCADA, .maxLevel = 19 },
};
static const u8 ctGroundIntroText[] = _("Runnin' my fingers through this\nhere soil... makes me feel alive.");
static const u8 ctGroundDefeatText[] = _("Not much left to harvest\nnow the rains stopped comin'.");
static const u8 ctGroundPostbattleText[] = _("You live and die\nby what the land gives ya.");
static const u8 ctGroundName[] = _("Farmer Jed");
static const struct TrainerTemplate ctGround = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_RUIN_MANIAC,
    .trainerName = ctGroundName,
    .partySize = 2,
    .poolSize = 36,
    .party = &ctGroundParty,
    .introText = ctGroundIntroText,
    .defeatText = ctGroundDefeatText,
    .postbattleText = ctGroundPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_SCIENTIST_1,
};
        
static const struct PokemonTemplate ctRockParty[] = {
    { .species = SPECIES_LARVITAR },
    { .species = SPECIES_ARCHEN },
    { .species = SPECIES_RHYHORN }, // lvl / trade
    { .species = SPECIES_ARON },
    { .species = SPECIES_NOSEPASS }, // area
    { .species = SPECIES_AMAURA },
    { .species = SPECIES_TYRUNT },
    { .species = SPECIES_ROGGENROLA }, // lvl / trade
    { .species = SPECIES_AERODACTYL },
    { .species = SPECIES_ROLYCOLY },
    { .species = SPECIES_SHUCKLE },
    { .species = SPECIES_MINIOR },
    { .species = SPECIES_CARBINK },
    { .species = SPECIES_BINACLE },
    { .species = SPECIES_TIRTOUGA },
    { .species = SPECIES_SHIELDON },
    { .species = SPECIES_CRANIDOS },
    { .species = SPECIES_ANORITH },
    { .species = SPECIES_LILEEP },
    { .species = SPECIES_KABUTO },
    { .species = SPECIES_OMANYTE },
    { .species = SPECIES_GEODUDE }, // lvl / trade
    { .species = SPECIES_GEODUDE_ALOLAN }, // lvl / trade
    { .species = SPECIES_ROCKRUFF },
    { .species = SPECIES_DREDNAW, .minLevel = 22 },
    { .species = SPECIES_DWEBBLE },
    { .species = SPECIES_RELICANTH },
    { .species = SPECIES_STONJOURNER },
    { .species = SPECIES_SOLROCK },
    { .species = SPECIES_LUNATONE },
    { .species = SPECIES_MAGCARGO, .minLevel = 38 },
    { .species = SPECIES_CORSOLA },
    { .species = SPECIES_BONSLY }, // mimic level 15
};
static const u8 ctRockIntroText[] = _("intro text");
static const u8 ctRockDefeatText[] = _("defeat text");
static const u8 ctRockPostbattleText[] = _("postbattle text");
static const u8 ctRockName[] = _("Kimberly");
static const struct TrainerTemplate ctRock = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HIKER,
    .trainerName = ctRockName,
    .partySize = 2,
    .poolSize = 33,
    .party = &ctRockParty,
    .introText = ctRockIntroText,
    .defeatText = ctRockDefeatText,
    .postbattleText = ctRockPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_HIKER,
};
        
static const struct PokemonTemplate ctBugParty[] = {
    { .species = SPECIES_LARVESTA },
    { .species = SPECIES_WIMPOD },
    { .species = SPECIES_SIZZLIPEDE },
    { .species = SPECIES_YANMA }, // ancient power level 33
    { .species = SPECIES_SHUCKLE },
    { .species = SPECIES_BLIPBUG },
    { .species = SPECIES_SCYTHER }, // trade
    { .species = SPECIES_PINSIR },
    { .species = SPECIES_HERACROSS },
    { .species = SPECIES_SEWADDLE },
    { .species = SPECIES_GRUBBIN }, // lvl / item OR area
    { .species = SPECIES_ANORITH },
    { .species = SPECIES_KARRABLAST }, // trade
    { .species = SPECIES_SHELMET }, // trade
    { .species = SPECIES_VENIPEDE },
    { .species = SPECIES_DWEBBLE },
    { .species = SPECIES_DURANT },
    { .species = SPECIES_SNOM }, // friendship
    { .species = SPECIES_COMBEE },
    { .species = SPECIES_JOLTIK },
    { .species = SPECIES_PINECO },
    { .species = SPECIES_CUTIEFLY },
    { .species = SPECIES_NINCADA },
    { .species = SPECIES_SHEDINJA },
    { .species = SPECIES_SURSKIT },
    { .species = SPECIES_DEWPIDER },
    { .species = SPECIES_VENONAT },
    { .species = SPECIES_VOLBEAT },
    { .species = SPECIES_ILLUMISE },
    { .species = SPECIES_BURMY },
    { .species = SPECIES_SCATTERBUG },
    { .species = SPECIES_PARAS },
    { .species = SPECIES_SPINARAK },
    { .species = SPECIES_CATERPIE },
    { .species = SPECIES_WEEDLE },
    { .species = SPECIES_WURMPLE },
    { .species = SPECIES_LEDYBA },
    { .species = SPECIES_KRICKETOT },
    { .species = SPECIES_SKORUPI, .maxLevel = 39 },
};
static const u8 ctBugIntroText[] = _("intro text");
static const u8 ctBugDefeatText[] = _("defeat text");
static const u8 ctBugPostbattleText[] = _("postbattle text");
static const u8 ctBugName[] = _("Bea");
static const struct TrainerTemplate ctBug = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BUG_CATCHER,
    .trainerName = ctBugName,
    .partySize = 2,
    .poolSize = 39,
    .party = &ctBugParty,
    .introText = ctBugIntroText,
    .defeatText = ctBugDefeatText,
    .postbattleText = ctBugPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BUG_CATCHER,
};
        
static const struct PokemonTemplate ctGhostParty[] = {
    { .species = SPECIES_DREEPY },
    { .species = SPECIES_DECIDUEYE, .minLevel = 34 },
    { .species = SPECIES_DUSKULL }, // lvl / trade
    { .species = SPECIES_LITWICK }, // lvl / item
    { .species = SPECIES_DHELMISE },
    { .species = SPECIES_CORSOLA_GALARIAN },
    { .species = SPECIES_SINISTEA }, // item
    { .species = SPECIES_GASTLY }, // lvl / trade
    { .species = SPECIES_HONEDGE }, // lvl / item
    { .species = SPECIES_DRIFLOON },
    { .species = SPECIES_MISDREAVUS }, // item
    { .species = SPECIES_PUMPKABOO }, // trade
    { .species = SPECIES_SPIRITOMB },
    { .species = SPECIES_YAMASK },
    { .species = SPECIES_YAMASK_GALARIAN }, // area
    { .species = SPECIES_GOLETT },
    { .species = SPECIES_SABLEYE },
    { .species = SPECIES_FROSLASS }, // item
    { .species = SPECIES_FRILLISH },
    { .species = SPECIES_SANDYGAST },
    { .species = SPECIES_ORICORIO_SENSU },
    { .species = SPECIES_MIMIKYU },
    { .species = SPECIES_PHANTUMP }, // trade
    { .species = SPECIES_SHUPPET },
    { .species = SPECIES_ROTOM },
    { .species = SPECIES_MAROWAK_ALOLAN, .minLevel = 28 },
    { .species = SPECIES_SHEDINJA },
};
static const u8 ctGhostIntroText[] = _("intro text");
static const u8 ctGhostDefeatText[] = _("defeat text");
static const u8 ctGhostPostbattleText[] = _("postbattle text");
static const u8 ctGhostName[] = _("Clyde");
static const struct TrainerTemplate ctGhost = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_HEX_MANIAC,
    .trainerName = ctGhostName,
    .partySize = 2,
    .poolSize = 27,
    .party = &ctGhostParty,
    .introText = ctGhostIntroText,
    .defeatText = ctGhostDefeatText,
    .postbattleText = ctGhostPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_HEX_MANIAC,
};
        
static const struct PokemonTemplate ctSteelParty[] = {
    { .species = SPECIES_BELDUM },
    { .species = SPECIES_MAGNEMITE }, // lvl / area
    { .species = SPECIES_DURALUDON },
    { .species = SPECIES_ARON },
    { .species = SPECIES_EMPOLEON, .minLevel = 36 },
    { .species = SPECIES_LUCARIO }, // friendship
    { .species = SPECIES_PROBOPASS }, // area
    { .species = SPECIES_KLINK },
    { .species = SPECIES_STEELIX }, // trade
    { .species = SPECIES_EXCADRILL, .minLevel = 31 },
    { .species = SPECIES_SCIZOR }, // trade
    { .species = SPECIES_BRONZOR },
    { .species = SPECIES_HONEDGE }, // lvl / item
    { .species = SPECIES_CUFANT },
    { .species = SPECIES_SHIELDON },
    { .species = SPECIES_ESCAVALIER }, // trade
    { .species = SPECIES_CORVIKNIGHT, .minLevel = 38 },
    { .species = SPECIES_PAWNIARD },
    { .species = SPECIES_FERROSEED },
    { .species = SPECIES_DURANT },
    { .species = SPECIES_STUNFISK_GALARIAN },
    { .species = SPECIES_KLEFKI },
    { .species = SPECIES_FORRETRESS, .minLevel = 31 },
    { .species = SPECIES_SKARMORY },
    { .species = SPECIES_SANDSHREW_ALOLAN }, // item
    { .species = SPECIES_MEOWTH_GALARIAN },
    { .species = SPECIES_TOGEDEMARU },
    { .species = SPECIES_DIGLETT_ALOLAN },
    { .species = SPECIES_WORMADAM_TRASH_CLOAK, .minLevel = 20 },
    { .species = SPECIES_MAWILE },
};
static const u8 ctSteelIntroText[] = _("Let's battle NOW! YOW!");
static const u8 ctSteelDefeatText[] = _("You beat me HOW?! YOW!");
static const u8 ctSteelPostbattleText[] = _("My jokes are too HIGHBROW! YOW!");
static const u8 ctSteelName[] = _("David Defeis");
static const struct TrainerTemplate ctSteel = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_GUITARIST,
    .trainerName = ctSteelName,
    .partySize = 2,
    .poolSize = 30,
    .party = &ctSteelParty,
    .introText = ctSteelIntroText,
    .defeatText = ctSteelDefeatText,
    .postbattleText = ctSteelPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAN_5,
};

static const struct PokemonTemplate ctFireParty[] = {
    { .species = SPECIES_GROWLITHE }, // item
    { .species = SPECIES_LARVESTA },
    { .species = SPECIES_MAGBY }, // lvl / trade
    { .species = SPECIES_DARUMAKA },
    { .species = SPECIES_CHARMANDER },
    { .species = SPECIES_CYNDAQUIL },
    { .species = SPECIES_CHIMCHAR },
    { .species = SPECIES_FENNEKIN },
    { .species = SPECIES_TORCHIC },
    { .species = SPECIES_LITTEN },
    { .species = SPECIES_SCORBUNNY },
    { .species = SPECIES_TEPIG },
    { .species = SPECIES_FLAREON }, // item
    { .species = SPECIES_SIZZLIPEDE },
    { .species = SPECIES_ROTOM_HEAT },
    { .species = SPECIES_LITWICK },
    { .species = SPECIES_CARKOL, .minLevel = 18 },
    { .species = SPECIES_LITLEO },
    { .species = SPECIES_VULPIX }, // item
    { .species = SPECIES_PONYTA },
    { .species = SPECIES_HOUNDOUR },
    { .species = SPECIES_FLETCHINDER, .minLevel = 17 },
    { .species = SPECIES_PANSEAR }, // item
    { .species = SPECIES_TURTONATOR },
    { .species = SPECIES_HEATMOR },
    { .species = SPECIES_SALANDIT },
    { .species = SPECIES_ORICORIO },
    { .species = SPECIES_TORKOAL },
    { .species = SPECIES_NUMEL },
    { .species = SPECIES_SLUGMA },
    { .species = SPECIES_MAROWAK_ALOLAN, .minLevel = 28 },
};
static const u8 ctFireIntroText[] = _("Man it's a hot one.");
static const u8 ctFireDefeatText[] = _("Like seven inches from the midday\nsun.");
static const u8 ctFirePostbattleText[] = _("Give me your heart,\nmake it real.");
static const u8 ctFireName[] = _("Rob Thomas ft. Santana");
static const struct TrainerTemplate ctFire = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_MAGMA_GRUNT_M,
    .trainerName = ctFireName,
    .partySize = 2,
    .poolSize = 31,
    .party = &ctFireParty,
    .introText = ctFireIntroText,
    .defeatText = ctFireDefeatText,
    .postbattleText = ctFirePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAGMA_MEMBER_M,
};

static const struct PokemonTemplate ctWaterParty[] = {
    { .species = SPECIES_MAGIKARP },
    { .species = SPECIES_HORSEA }, // lvl / trade
    { .species = SPECIES_FEEBAS }, // trade OR max beauty (?)
    { .species = SPECIES_LAPRAS },
    { .species = SPECIES_MUDKIP },
    { .species = SPECIES_SQUIRTLE },
    { .species = SPECIES_TOTODILE },
    { .species = SPECIES_SPHEAL },
    { .species = SPECIES_PIPLUP },
    { .species = SPECIES_FROAKIE },
    { .species = SPECIES_POPPLIO },
    { .species = SPECIES_WIMPOD },
    { .species = SPECIES_SOBBLE },
    { .species = SPECIES_OSHAWOTT },
    { .species = SPECIES_SHELLDER }, // item
    { .species = SPECIES_VAPOREON }, // item
    { .species = SPECIES_STARYU }, // item
    { .species = SPECIES_ROTOM_WASH },
    { .species = SPECIES_TENTACOOL },
    { .species = SPECIES_POLIWAG }, // lvl / item
    { .species = SPECIES_TYMPOLE },
    { .species = SPECIES_DRACOVISH },
    { .species = SPECIES_ARCTOVISH },
    { .species = SPECIES_PSYDUCK },
    { .species = SPECIES_WAILMER },
    { .species = SPECIES_BINACLE },
    { .species = SPECIES_CLAUNCHER },
    { .species = SPECIES_PANPOUR }, // item
    { .species = SPECIES_OMANYTE },
    { .species = SPECIES_KABUTO },
    { .species = SPECIES_BUIZEL },
    { .species = SPECIES_TIRTOUGA },
    { .species = SPECIES_MAREANIE },
    { .species = SPECIES_SLOWPOKE }, // lvl / trade
    { .species = SPECIES_ARROKUDA },
    { .species = SPECIES_MANTYKE }, // remoraid in party
    { .species = SPECIES_CLAMPERL }, // trade
    { .species = SPECIES_RELICANTH },
    { .species = SPECIES_CHEWTLE },
    { .species = SPECIES_REMORAID },
    { .species = SPECIES_LOTAD }, // lvl / item
    { .species = SPECIES_PHIONE }, // Is this legendary?
    { .species = SPECIES_FRILLISH },
    { .species = SPECIES_SEEL },
    { .species = SPECIES_KRABBY },
    { .species = SPECIES_SHELLOS },
    { .species = SPECIES_BRUXISH },
    { .species = SPECIES_CRAMORANT },
    { .species = SPECIES_DUCKLETT },
    { .species = SPECIES_ALOMOMOLA },
    { .species = SPECIES_BARBOACH },
    { .species = SPECIES_CORPHISH },
    { .species = SPECIES_CHINCHOU },
    { .species = SPECIES_CARVANHA },
    { .species = SPECIES_FINNEON },
    { .species = SPECIES_BASCULIN },
    { .species = SPECIES_BASCULIN_BLUE_STRIPED }, // Maybe exclude this
    { .species = SPECIES_DEWPIDER },
    { .species = SPECIES_GOLDEEN },
    { .species = SPECIES_QWILFISH },
    { .species = SPECIES_WINGULL },
    { .species = SPECIES_WOOPER },
    { .species = SPECIES_MARILL }, // friendship / lvl
    { .species = SPECIES_CORSOLA },
    { .species = SPECIES_BIBAREL, .minLevel = 15 },
    { .species = SPECIES_PYUKUMUKU },
    { .species = SPECIES_LUVDISC },
    { .species = SPECIES_SKRELP, .maxLevel = 47 },
    { .species = SPECIES_SURSKIT, .maxLevel = 22 },
    { .species = SPECIES_WISHIWASHI },
};
static const u8 ctWaterIntroText[] = _("intro text");
static const u8 ctWaterDefeatText[] = _("defeat text");
static const u8 ctWaterPostbattleText[] = _("postbattle text");
static const u8 ctWaterName[] = _("Flo");
static const struct TrainerTemplate ctWater = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_TUBER_F,
    .trainerName = ctWaterName,
    .partySize = 2,
    .poolSize = 70,
    .party = &ctWaterParty,
    .introText = ctWaterIntroText,
    .defeatText = ctWaterDefeatText,
    .postbattleText = ctWaterPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_TUBER_F,
};

static const struct PokemonTemplate ctGrassParty[] = {
    { .species = SPECIES_TANGELA }, // ancient power level 38
    { .species = SPECIES_SKIDDO },
    { .species = SPECIES_EXEGGCUTE }, // item
    { .species = SPECIES_TREECKO },
    { .species = SPECIES_CHESPIN },
    { .species = SPECIES_ROWLET },
    { .species = SPECIES_GROOKEY },
    { .species = SPECIES_SNIVY },
    { .species = SPECIES_BULBASAUR },
    { .species = SPECIES_CHIKORITA },
    { .species = SPECIES_TURTWIG },
    { .species = SPECIES_LEAFEON }, // item
    { .species = SPECIES_ROTOM_MOW },
    { .species = SPECIES_DHELMISE },
    { .species = SPECIES_BUDEW }, // friendship / item
    { .species = SPECIES_BOUNSWEET }, // lvl / stomp lvl 29
    { .species = SPECIES_SEWADDLE }, // lvl / friendship
    { .species = SPECIES_PANSAGE }, // item
    { .species = SPECIES_LILEEP },
    { .species = SPECIES_SNOVER },
    { .species = SPECIES_PUMPKABOO }, // trade
    { .species = SPECIES_ODDISH }, // lvl / item
    { .species = SPECIES_BELLSPROUT }, // lvl / item
    { .species = SPECIES_FERROSEED },
    { .species = SPECIES_APPLIN }, // item
    { .species = SPECIES_LOTAD }, // lvl / item
    { .species = SPECIES_SEEDOT }, // lvl / item
    { .species = SPECIES_COTTONEE }, // item
    { .species = SPECIES_PETILIL }, // item
    { .species = SPECIES_FOMANTIS },
    { .species = SPECIES_CACNEA },
    { .species = SPECIES_DEERLING },
    { .species = SPECIES_PHANTUMP }, // trade
    { .species = SPECIES_FOONGUS },
    { .species = SPECIES_MARACTUS },
    { .species = SPECIES_HOPPIP },
    { .species = SPECIES_SHROOMISH },
    { .species = SPECIES_TROPIUS },
    { .species = SPECIES_GOSSIFLEUR },
    { .species = SPECIES_CARNIVINE },
    { .species = SPECIES_CHERUBI },
    { .species = SPECIES_SUNKERN }, // item
    { .species = SPECIES_WORMADAM, .minLevel = 20 },
    { .species = SPECIES_PARAS },
    { .species = SPECIES_MORELULL },
};
static const u8 ctGrassIntroText[] = _("I've been planting the seeds\nof your defeat!");
static const u8 ctGrassDefeatText[] = _("Alright, I've had my clorophyll of this.");
static const u8 ctGrassPostbattleText[] = _("I wish you'd just\nsod off.");
static const u8 ctGrassName[] = _("Scott");
static const struct TrainerTemplate ctGrass = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMON_BREEDER_F,
    .trainerName = ctGrassName,
    .partySize = 2,
    .poolSize = 45,
    .party = &ctGrassParty,
    .introText = ctGrassIntroText,
    .defeatText = ctGrassDefeatText,
    .postbattleText = ctGrassPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_WOMAN_2,
};
        
static const struct PokemonTemplate ctElectricParty[] = {
    { .species = SPECIES_ELEKID }, // lvl / trade
    { .species = SPECIES_MAGNEMITE }, // lvl / area
    { .species = SPECIES_JOLTEON }, // item
    { .species = SPECIES_SHINX },
    { .species = SPECIES_ROTOM },
    { .species = SPECIES_ROTOM_FAN },
    { .species = SPECIES_ROTOM_FROST },
    { .species = SPECIES_ROTOM_HEAT },
    { .species = SPECIES_ROTOM_MOW },
    { .species = SPECIES_ROTOM_WASH },
    { .species = SPECIES_TYNAMO }, // lvl / item
    { .species = SPECIES_MAREEP },
    { .species = SPECIES_DRACOZOLT },
    { .species = SPECIES_ARCTOZOLT },
    { .species = SPECIES_TOXEL },
    { .species = SPECIES_CHARJABUG, .minLevel = 20 }, // lvl / item OR area
    { .species = SPECIES_BLITZLE },
    { .species = SPECIES_GEODUDE_ALOLAN }, // lvl / trade
    { .species = SPECIES_VOLTORB },
    { .species = SPECIES_YAMPER },
    { .species = SPECIES_PICHU }, // friendship / item
    { .species = SPECIES_HELIOPTILE }, // item
    { .species = SPECIES_ORICORIO_POM_POM },
    { .species = SPECIES_ELECTRIKE },
    { .species = SPECIES_JOLTIK },
    { .species = SPECIES_STUNFISK },
    { .species = SPECIES_CHINCHOU },
    { .species = SPECIES_MORPEKO },
    { .species = SPECIES_TOGEDEMARU },
    { .species = SPECIES_PINCURCHIN },
    { .species = SPECIES_DEDENNE },
    { .species = SPECIES_EMOLGA },
    { .species = SPECIES_PLUSLE },
    { .species = SPECIES_MINUN },
    { .species = SPECIES_PACHIRISU },
};
static const u8 ctElectricIntroText[] = _("I'm amped up for this fight!");
static const u8 ctElectricDefeatText[] = _("Oh zap!\nWhat a shocking defeat!");
static const u8 ctElectricPostbattleText[] = _("I don't currently have\nanything to say to you.");
static const u8 ctElectricName[] = _("Julia");
static const struct TrainerTemplate ctElectric = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_NINJA_BOY,
    .trainerName = ctElectricName,
    .partySize = 2,
    .poolSize = 35,
    .party = &ctElectricParty,
    .introText = ctElectricIntroText,
    .defeatText = ctElectricDefeatText,
    .postbattleText = ctElectricPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_NINJA_BOY,
};
        
static const struct PokemonTemplate ctPsychicParty[] = {
    { .species = SPECIES_BELDUM },
    { .species = SPECIES_FENNEKIN },
    { .species = SPECIES_EXEGGCUTE, .evoStrat = EVO_STRAT_NO_EXEGGUTOR_ALOLAN },
    { .species = SPECIES_ESPEON }, // item
    { .species = SPECIES_STARMIE }, // item
    { .species = SPECIES_MIME_JR }, // after mimic at 15 / lvl
    { .species = SPECIES_RALTS }, // lvl / lvl OR item
    { .species = SPECIES_HATENNA },
    { .species = SPECIES_DOTTLER, .minLevel = 10 },
    { .species = SPECIES_ABRA }, // lvl / trade
    { .species = SPECIES_PONYTA_GALARIAN },
    { .species = SPECIES_BALTOY },
    { .species = SPECIES_BRONZOR },
    { .species = SPECIES_SLOWPOKE }, // lvl OR trade
    { .species = SPECIES_SLOWBRO_GALARIAN }, // item
    { .species = SPECIES_SIGILYPH },
    { .species = SPECIES_GOTHITA },
    { .species = SPECIES_SOLOSIS },
    { .species = SPECIES_ORANGURU },
    { .species = SPECIES_MUNNA }, // item
    { .species = SPECIES_RAICHU_ALOLAN }, // friendship / item
    { .species = SPECIES_ELGYEM },
    { .species = SPECIES_DROWZEE },
    { .species = SPECIES_INKAY },
    { .species = SPECIES_ORICORIO_PAU },
    { .species = SPECIES_BRUXISH },
    { .species = SPECIES_INDEEDEE },
    { .species = SPECIES_INDEEDEE_FEMALE },
    { .species = SPECIES_NATU },
    { .species = SPECIES_SPOINK },
    { .species = SPECIES_ESPURR },
    { .species = SPECIES_LUNATONE },
    { .species = SPECIES_SOLROCK },
    { .species = SPECIES_SMOOCHUM },
    { .species = SPECIES_GIRAFARIG },
    { .species = SPECIES_CHINGLING }, // friendship
    { .species = SPECIES_WOOBAT }, // friendship
    { .species = SPECIES_MEDITITE },
    { .species = SPECIES_WYNAUT },
    { .species = SPECIES_UNOWN },
};
static const u8 ctPsychicIntroText[] = _("intro text");
static const u8 ctPsychicDefeatText[] = _("defeat text");
static const u8 ctPsychicPostbattleText[] = _("postbattle text");
static const u8 ctPsychicName[] = _("Sayeh");
static const struct TrainerTemplate ctPsychic = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_PSYCHIC_F,
    .trainerName = ctPsychicName,
    .partySize = 2,
    .poolSize = 40,
    .party = &ctPsychicParty,
    .introText = ctPsychicIntroText,
    .defeatText = ctPsychicDefeatText,
    .postbattleText = ctPsychicPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_LASS,
};
        
static const struct PokemonTemplate ctIceParty[] = {
    { .species = SPECIES_DARUMAKA_GALARIAN }, // item
    { .species = SPECIES_LAPRAS },
    { .species = SPECIES_VANILLITE },
    { .species = SPECIES_SPHEAL },
    { .species = SPECIES_SWINUB }, // lvl / ancient power at 1
    { .species = SPECIES_CLOYSTER }, // item
    { .species = SPECIES_GLACEON }, // item
    { .species = SPECIES_AMAURA },
    { .species = SPECIES_ROTOM_FROST },
    { .species = SPECIES_MR_MIME_GALARIAN }, // after mimic at 15 / lvl
    { .species = SPECIES_CRYOGONAL },
    { .species = SPECIES_BERGMITE },
    { .species = SPECIES_SNEASEL }, // item
    { .species = SPECIES_VULPIX }, // item
    { .species = SPECIES_CUBCHOO },
    { .species = SPECIES_ARCTOZOLT },
    { .species = SPECIES_ARCTOVISH },
    { .species = SPECIES_SNOVER },
    { .species = SPECIES_SNORUNT }, // lvl OR item
    { .species = SPECIES_CRABOMINABLE }, // area
    { .species = SPECIES_DEWGONG, .minLevel = 34 },
    { .species = SPECIES_SNOM }, // friendship
    { .species = SPECIES_EISCUE },
    { .species = SPECIES_SMOOCHUM },
    { .species = SPECIES_SANDSHREW_ALOLAN }, // item
    { .species = SPECIES_DELIBIRD },
};
static const u8 ctIceIntroText[] = _("intro text");
static const u8 ctIceDefeatText[] = _("defeat text");
static const u8 ctIcePostbattleText[] = _("postbattle text");
static const u8 ctIceName[] = _("Kelvin");
static const struct TrainerTemplate ctIce = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEFAN_F,
    .trainerName = ctIceName,
    .partySize = 2,
    .poolSize = 26,
    .party =  &ctIceParty,
    .introText = ctIceIntroText,
    .defeatText = ctIceDefeatText,
    .postbattleText = ctIcePostbattleText,
    .graphicsId = OBJ_EVENT_GFX_POKEFAN_F,
};
        
static const struct PokemonTemplate ctDragonParty[] = {
    { .species = SPECIES_DRATINI },
    { .species = SPECIES_BAGON },
    { .species = SPECIES_GIBLE },
    { .species = SPECIES_DEINO },
    { .species = SPECIES_GOOMY },
    { .species = SPECIES_JANGMO_O },
    { .species = SPECIES_DREEPY },
    { .species = SPECIES_KINGDRA }, // lvl / item
    { .species = SPECIES_AXEW },
    { .species = SPECIES_NOIBAT },
    { .species = SPECIES_DURALUDON },
    { .species = SPECIES_EXEGGUTOR_ALOLAN }, // item
    { .species = SPECIES_TYRUNT },
    { .species = SPECIES_VIBRAVA, .minLevel = 35 },
    { .species = SPECIES_DRACOZOLT },
    { .species = SPECIES_DRACOVISH },
    { .species = SPECIES_DRAGALGE, .minLevel = 48 },
    { .species = SPECIES_ALTARIA, .minLevel = 35 },
    { .species = SPECIES_DRUDDIGON },
    { .species = SPECIES_TURTONATOR },
    { .species = SPECIES_DRAMPA },
    { .species = SPECIES_APPLIN }, // item
};
static const u8 ctDragonIntroText[] = _("Well met good sir! Let us away\nto the field of battle!");
static const u8 ctDragonDefeatText[] = _("I have been bested\nby a worthy adversary!");
static const u8 ctDragonPostbattleText[] = _("I shall recover my mana\nand return to battle you anew!");
static const u8 ctDragonName[] = _("Archmage Stanley");
static const struct TrainerTemplate ctDragon = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_DRAGON_TAMER,
    .trainerName = ctDragonName,
    .partySize = 2,
    .poolSize = 22,
    .party = &ctDragonParty,
    .introText = ctDragonIntroText,
    .defeatText = ctDragonDefeatText,
    .postbattleText = ctDragonPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MAN_3,
};
        
static const struct PokemonTemplate ctDarkParty[] = {
    { .species = SPECIES_TYRANITAR, .minLevel = 55 },
    { .species = SPECIES_DEINO },
    { .species = SPECIES_GRENINJA, .minLevel = 36 },
    { .species = SPECIES_INCINEROAR, .minLevel = 34 },
    { .species = SPECIES_UMBREON }, // item
    { .species = SPECIES_ZIGZAGOON_GALARIAN },
    { .species = SPECIES_SANDILE },
    { .species = SPECIES_SNEASEL },
    { .species = SPECIES_ZORUA },
    { .species = SPECIES_VULLABY },
    { .species = SPECIES_IMPIDIMP },
    { .species = SPECIES_MURKROW }, // item
    { .species = SPECIES_GRIMER_ALOLAN },
    { .species = SPECIES_HOUNDOUR },
    { .species = SPECIES_DRAPION, .minLevel = 40 },
    { .species = SPECIES_PANGORO, .minLevel = 32 },
    { .species = SPECIES_PAWNIARD },
    { .species = SPECIES_SCRAGGY },
    { .species = SPECIES_SPIRITOMB },
    { .species = SPECIES_INKAY },
    { .species = SPECIES_NUZLEAF, .minLevel = 14 }, // lvl / item
    { .species = SPECIES_STUNKY },
    { .species = SPECIES_CACTURNE, .minLevel = 32 },
    { .species = SPECIES_CRAWDAUNT, .minLevel = 30 },
    { .species = SPECIES_ABSOL },
    { .species = SPECIES_CARVANHA },
    { .species = SPECIES_NICKIT },
    { .species = SPECIES_PURRLOIN },
    { .species = SPECIES_MEOWTH_ALOLAN }, // friendship
    { .species = SPECIES_MORPEKO },
    { .species = SPECIES_POOCHYENA },
    { .species = SPECIES_RATTATA_ALOLAN },
    { .species = SPECIES_SABLEYE },
};
static const u8 ctDarkIntroText[] = _("I am the son and heir\nof nothing in particular.");
static const u8 ctDarkDefeatText[] = _("To die by your side\nis such a heavenly way to die.");
static const u8 ctDarkPostbattleText[] = _("Every day is like Sunday\nEvery day is silent and gray.");
static const u8 ctDarkName[] = _("Raven Batshade");
static const struct TrainerTemplate ctDark = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_POKEMANIAC,
    .trainerName = ctDarkName,
    .partySize = 2,
    .poolSize = 33,
    .party = &ctDarkParty,
    .introText = ctDarkIntroText,
    .defeatText = ctDarkDefeatText,
    .postbattleText = ctDarkPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_MANIAC,
};

static const struct PokemonTemplate ctFairyParty[] = {
    { .species = SPECIES_FLABEBE }, // lvl / item
    { .species = SPECIES_TOGEPI }, // friendship / item
    { .species = SPECIES_PRIMARINA, .minLevel = 34 },
    { .species = SPECIES_SYLVEON },
    { .species = SPECIES_RALTS, .evoStrat = EVO_STRAT_NO_GALLADE },
    { .species = SPECIES_HATTERENE, .minLevel = 42 },
    { .species = SPECIES_IMPIDIMP },
    { .species = SPECIES_NINETALES_ALOLAN }, // item
    { .species = SPECIES_RAPIDASH_GALARIAN, .minLevel = 40 },
    { .species = SPECIES_CARBINK },
    { .species = SPECIES_MILCERY }, // fucking what
    { .species = SPECIES_WEEZING_GALARIAN, .minLevel = 35 },
    { .species = SPECIES_COMFEY },
    { .species = SPECIES_CLEFFA }, // friendship / item
    { .species = SPECIES_COTTONEE }, // item
    { .species = SPECIES_SWIRLIX }, // trade
    { .species = SPECIES_MIMIKYU },
    { .species = SPECIES_KLEFKI },
    { .species = SPECIES_CUTIEFLY },
    { .species = SPECIES_SPRITZEE }, // trade
    { .species = SPECIES_MIME_JR, .evoStrat = EVO_STRAT_NO_MR_MIME_GALARIAN },
    { .species = SPECIES_SNUBBULL },
    { .species = SPECIES_IGGLYBUFF }, // friendship / item
    { .species = SPECIES_DEDENNE },
    { .species = SPECIES_AZURILL }, // friendship / lvl
    { .species = SPECIES_MORELULL },
    { .species = SPECIES_MAWILE },
};
static const u8 ctFairyIntroText[] = _("intro text");
static const u8 ctFairyDefeatText[] = _("defeat text");
static const u8 ctFairyPostbattleText[] = _("postbattle text");
static const u8 ctFairyName[] = _("Yosei");
static const struct TrainerTemplate ctFairy = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
    .trainerName = ctFairyName,
    .partySize = 2,
    .poolSize = 27,
    .party = &ctFairyParty,
    .introText = ctFairyIntroText,
    .defeatText = ctFairyDefeatText,
    .postbattleText = ctFairyPostbattleText,
    .graphicsId = OBJ_EVENT_GFX_ANABEL,
};

static const struct PokemonTemplate gmViolet1Party[] = {
    { .species = SPECIES_PIDOVE },
    { .species = SPECIES_PIDGEY },
    { .species = SPECIES_DODUO },
    { .species = SPECIES_TAILLOW },
    { .species = SPECIES_PIDOVE },
    { .species = SPECIES_PIDGEY },
    { .species = SPECIES_DODUO },
    { .species = SPECIES_TAILLOW },
};
static const u8 gmViolet1IntroText[] = _("intro text");
static const u8 gmViolet1DefeatText[] = _("defeat text");
static const u8 gmViolet1PostbattleText[] = _("postbattle text");
static const u8 gmViolet1Name[] = _("Violet Gym Member 1");
static const struct TrainerTemplate gmViolet1 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet1Name,
    .partySize = 3,
    .poolSize = 8,
    .party = &gmViolet1Party,
    .introText = gmViolet1IntroText,
    .defeatText = gmViolet1DefeatText,
    .postbattleText = gmViolet1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct PokemonTemplate gmViolet2Party[] = {
    { .species = SPECIES_TOGETIC },
    { .species = SPECIES_GYARADOS },
    { .species = SPECIES_ZUBAT },
    { .species = SPECIES_YANMA },
    { .species = SPECIES_VULLABY },
    { .species = SPECIES_HAWLUCHA },
};
static const u8 gmViolet2IntroText[] = _("intro text");
static const u8 gmViolet2DefeatText[] = _("defeat text");
static const u8 gmViolet2PostbattleText[] = _("postbattle text");
static const u8 gmViolet2Name[] = _("Violet Gym Member 2");
static const struct TrainerTemplate gmViolet2 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet2Name,
    .partySize = 2,
    .poolSize = 6,
    .party = &gmViolet2Party,
    .introText = gmViolet2IntroText,
    .defeatText = gmViolet2DefeatText,
    .postbattleText = gmViolet2PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct PokemonTemplate gmViolet3Party[] = {
    { .species = SPECIES_FLETCHLING },
    { .species = SPECIES_DRIFLOON },
    { .species = SPECIES_SWABLU },
    { .species = SPECIES_PIKIPEK },
    { .species = SPECIES_NATU },
    { .species = SPECIES_SKARMORY },
    { .species = SPECIES_TROPIUS },
    { .species = SPECIES_HOPPIP },
};
static const u8 gmViolet3IntroText[] = _("intro text");
static const u8 gmViolet3DefeatText[] = _("defeat text");
static const u8 gmViolet3PostbattleText[] = _("postbattle text");
static const u8 gmViolet3Name[] = _("Violet Gym Member 3");
static const struct TrainerTemplate gmViolet3 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet3Name,
    .partySize = 3,
    .poolSize = 8,
    .party = &gmViolet3Party,
    .introText = gmViolet3IntroText,
    .defeatText = gmViolet3DefeatText,
    .postbattleText = gmViolet3PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct PokemonTemplate gmViolet4Party[] = {
    { .species = SPECIES_ORICORIO },
    { .species = SPECIES_ORICORIO_PAU },
    { .species = SPECIES_ORICORIO_POM_POM },
    { .species = SPECIES_ORICORIO_SENSU },
};
static const u8 gmViolet4IntroText[] = _("intro text");
static const u8 gmViolet4DefeatText[] = _("defeat text");
static const u8 gmViolet4PostbattleText[] = _("postbattle text");
static const u8 gmViolet4Name[] = _("Violet Gym Member 4");
static const struct TrainerTemplate gmViolet4 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = gmViolet4Name,
    .partySize = 2,
    .poolSize = 4,
    .party = &gmViolet4Party,
    .introText = gmViolet4IntroText,
    .defeatText = gmViolet4DefeatText,
    .postbattleText = gmViolet4PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct PokemonTemplate glViolet1Party[] = {
    { .species = SPECIES_STARLY, .heldItem = ITEM_LUM_BERRY },
    { .species = SPECIES_HOOTHOOT, .heldItem = ITEM_SITRUS_BERRY },
    { .species = SPECIES_TAILLOW, .heldItem = ITEM_ENIGMA_BERRY },
    { .species = SPECIES_MURKROW, .heldItem = ITEM_JABOCA_BERRY },
    { .species = SPECIES_WINGULL, .heldItem = ITEM_WACAN_BERRY },
    { .species = SPECIES_PIDGEY, .heldItem = ITEM_LANSAT_BERRY },
};
static const u8 glViolet1IntroText[] = _("intro text");
static const u8 glViolet1DefeatText[] = _("defeat text");
static const u8 glViolet1PostbattleText[] = _("postbattle text");
static const u8 glViolet1Name[] = _("Falkner 1");
static const struct TrainerTemplate glViolet1 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = glViolet1Name,
    .partySize = 6,
    .poolSize = 6,
    .party = &glViolet1Party,
    .introText = glViolet1IntroText,
    .defeatText = glViolet1DefeatText,
    .postbattleText = glViolet1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct PokemonTemplate gmCerulean1Party[] = {
    { .species = SPECIES_SQUIRTLE },
    { .species = SPECIES_TOTODILE },
    { .species = SPECIES_MUDKIP },
    { .species = SPECIES_PIPLUP },
    { .species = SPECIES_OSHAWOTT },
    { .species = SPECIES_FROAKIE },
    { .species = SPECIES_POPPLIO },
    { .species = SPECIES_SOBBLE },
    { .species = SPECIES_VAPOREON },
};
static const u8 gmCerulean1IntroText[] = _("intro text");
static const u8 gmCerulean1DefeatText[] = _("defeat text");
static const u8 gmCerulean1PostbattleText[] = _("postbattle text");
static const u8 gmCerulean1Name[] = _("Cerulean Gym Member 1");
static const struct TrainerTemplate gmCerulean1 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SWIMMER_F,
    .trainerName = gmCerulean1Name,
    .partySize = 3,
    .poolSize = 9,
    .party = &gmCerulean1Party,
    .introText = gmCerulean1IntroText,
    .defeatText = gmCerulean1DefeatText,
    .postbattleText = gmCerulean1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_SWIMMER_F,
};

static const struct PokemonTemplate gmCerulean2Party[] = {
    { .species = SPECIES_CORSOLA },
    { .species = SPECIES_SPHEAL },
    { .species = SPECIES_PYUKUMUKU },
    { .species = SPECIES_MARILL },
    { .species = SPECIES_HORSEA },
    { .species = SPECIES_WINGULL },
    { .species = SPECIES_DEWPIDER },
    { .species = SPECIES_CORPHISH },
    { .species = SPECIES_DUCKLETT },
    { .species = SPECIES_SEEL },
    { .species = SPECIES_KRABBY },
    { .species = SPECIES_SHELLOS },
    { .species = SPECIES_CRAMORANT },
    { .species = SPECIES_OCTILLERY },
    { .species = SPECIES_LOTAD },
    { .species = SPECIES_FRILLISH },
    { .species = SPECIES_OMANYTE },
    { .species = SPECIES_KABUTO },
};
static const u8 gmCerulean2IntroText[] = _("intro text");
static const u8 gmCerulean2DefeatText[] = _("defeat text");
static const u8 gmCerulean2PostbattleText[] = _("postbattle text");
static const u8 gmCerulean2Name[] = _("Cerulean Gym Member 2");
static const struct TrainerTemplate gmCerulean2 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_SWIMMER_M,
    .trainerName = gmCerulean2Name,
    .partySize = 2,
    .poolSize = 18,
    .party = &gmCerulean2Party,
    .introText = gmCerulean2IntroText,
    .defeatText = gmCerulean2DefeatText,
    .postbattleText = gmCerulean2PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_SWIMMER_M,
};

static const struct PokemonTemplate gmCerulean3Party[] = {
    { .species = SPECIES_QWILFISH },
    { .species = SPECIES_GOLDEEN },
    { .species = SPECIES_CHINCHOU },
    { .species = SPECIES_CARVANHA },
    { .species = SPECIES_FINNEON },
    { .species = SPECIES_BASCULIN },
    { .species = SPECIES_BASCULIN_BLUE_STRIPED },
    { .species = SPECIES_BARBOACH },
    { .species = SPECIES_ALOMOMOLA },
    { .species = SPECIES_BRUXISH },
    { .species = SPECIES_RELICANTH },
};
static const u8 gmCerulean3IntroText[] = _("intro text");
static const u8 gmCerulean3DefeatText[] = _("defeat text");
static const u8 gmCerulean3PostbattleText[] = _("postbattle text");
static const u8 gmCerulean3Name[] = _("Cerulean Gym Member 3");
static const struct TrainerTemplate gmCerulean3 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_TUBER_M,
    .trainerName = gmCerulean3Name,
    .partySize = 2,
    .poolSize = 11,
    .party = &gmCerulean3Party,
    .introText = gmCerulean3IntroText,
    .defeatText = gmCerulean3DefeatText,
    .postbattleText = gmCerulean3PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_TUBER_M_SWIMMING,
};

static const struct PokemonTemplate glCerulean1Party[] = {
    { .species = SPECIES_PSYDUCK, .moves = { MOVE_DISABLE, MOVE_CONFUSION, MOVE_FURY_SWIPES, MOVE_BODY_SLAM } },
    { .species = SPECIES_PSYDUCK, .moves = { MOVE_SCALD, MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_LIGHT_SCREEN } },
    { .species = SPECIES_SEEL, .moves = { MOVE_AQUA_JET, MOVE_ICE_SHARD, MOVE_WATERFALL, MOVE_IRON_TAIL } },
    { .species = SPECIES_SEEL, .moves = { MOVE_BLIZZARD, MOVE_REST, MOVE_TAKE_DOWN, MOVE_SURF } },
    { .species = SPECIES_VAPOREON, .moves = { MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_QUICK_ATTACK, MOVE_SHADOW_BALL } },
    { .species = SPECIES_STARYU, .moves = { MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_RECOVER, MOVE_ICE_BEAM } },
    { .species = SPECIES_STARYU, .moves = { MOVE_SCALD, MOVE_SWIFT, MOVE_PSYWAVE, MOVE_NONE } },
    { .species = SPECIES_GYARADOS, .moves = { MOVE_WATERFALL, MOVE_CRUNCH, MOVE_OUTRAGE, MOVE_IRON_TAIL } },
    { .species = SPECIES_LAPRAS, .moves = { MOVE_SURF, MOVE_PERISH_SONG, MOVE_BLIZZARD, MOVE_RAIN_DANCE } },
    { .species = SPECIES_LAPRAS, .moves = { MOVE_ICE_BEAM, MOVE_SING, MOVE_WATER_PULSE, MOVE_BODY_SLAM } },
    { .species = SPECIES_WOOPER, .moves = { MOVE_WATER_PULSE, MOVE_AMNESIA, MOVE_RAIN_DANCE, MOVE_EARTHQUAKE } },
    { .species = SPECIES_SQUIRTLE, .moves = { MOVE_HYDRO_PUMP, MOVE_DIG, MOVE_BITE, MOVE_SEISMIC_TOSS } },
    { .species = SPECIES_HORSEA, .moves = { MOVE_SMOKESCREEN, MOVE_SURF, MOVE_TOXIC, MOVE_ICE_BEAM } },
    { .species = SPECIES_HORSEA, .moves = { MOVE_RAIN_DANCE, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM } },
    { .species = SPECIES_POLIWAG, .moves = { MOVE_RAIN_DANCE, MOVE_EARTHQUAKE, MOVE_HYDRO_PUMP, MOVE_BODY_SLAM } },
};
static const u8 glCerulean1IntroText[] = _("intro text");
static const u8 glCerulean1DefeatText[] = _("defeat text");
static const u8 glCerulean1PostbattleText[] = _("postbattle text");
static const u8 glCerulean1Name[] = _("Misty 1");
static const struct TrainerTemplate glCerulean1 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BIRD_KEEPER,
    .trainerName = glCerulean1Name,
    .partySize = 6,
    .poolSize = 15,
    .party = &glCerulean1Party,
    .introText = glCerulean1IntroText,
    .defeatText = glCerulean1DefeatText,
    .postbattleText = glCerulean1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_FISHERMAN,
};

static const struct PokemonTemplate gmCeladon1Party[] = {
    { .species = SPECIES_BELLSPROUT },
    { .species = SPECIES_ODDISH },
    { .species = SPECIES_BULBASAUR },
    { .species = SPECIES_EXEGGCUTE },
    { .species = SPECIES_HOPPIP },
    { .species = SPECIES_PARAS },
    { .species = SPECIES_CARNIVINE },
    { .species = SPECIES_TANGELA },
};
static const u8 gmCeladon1IntroText[] = _("intro text");
static const u8 gmCeladon1DefeatText[] = _("defeat text");
static const u8 gmCeladon1PostbattleText[] = _("postbattle text");
static const u8 gmCeladon1Name[] = _("Celadon Gym Member 1");
static const struct TrainerTemplate gmCeladon1 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BEAUTY,
    .trainerName = gmCeladon1Name,
    .partySize = 3,
    .poolSize = 8,
    .party = &gmCeladon1Party,
    .introText = gmCeladon1IntroText,
    .defeatText = gmCeladon1DefeatText,
    .postbattleText = gmCeladon1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BEAUTY,
};

static const struct PokemonTemplate gmCeladon2Party[] = {
    { .species = SPECIES_BULBASAUR },
    { .species = SPECIES_CHIKORITA },
    { .species = SPECIES_TREECKO },
    { .species = SPECIES_TURTWIG },
    { .species = SPECIES_SNIVY },
    { .species = SPECIES_CHESPIN },
    { .species = SPECIES_ROWLET },
    { .species = SPECIES_GROOKEY },
    { .species = SPECIES_LEAFEON },
};
static const u8 gmCeladon2IntroText[] = _("intro text");
static const u8 gmCeladon2DefeatText[] = _("defeat text");
static const u8 gmCeladon2PostbattleText[] = _("postbattle text");
static const u8 gmCeladon2Name[] = _("Celadon Gym Member 2");
static const struct TrainerTemplate gmCeladon2 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BEAUTY,
    .trainerName = gmCeladon2Name,
    .partySize = 3,
    .poolSize = 9,
    .party = &gmCeladon2Party,
    .introText = gmCeladon2IntroText,
    .defeatText = gmCeladon2DefeatText,
    .postbattleText = gmCeladon2PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_GIRL_1,
};

static const struct PokemonTemplate gmCeladon3Party[] = {
    { .species = SPECIES_CHIKORITA },
    { .species = SPECIES_SUNKERN },
    { .species = SPECIES_LOTAD },
    { .species = SPECIES_SEEDOT },
    { .species = SPECIES_SHROOMISH },
    { .species = SPECIES_CACNEA },
    { .species = SPECIES_LILEEP },
    { .species = SPECIES_TROPIUS },
    { .species = SPECIES_WORMADAM },
};
static const u8 gmCeladon3IntroText[] = _("intro text");
static const u8 gmCeladon3DefeatText[] = _("defeat text");
static const u8 gmCeladon3PostbattleText[] = _("postbattle text");
static const u8 gmCeladon3Name[] = _("Celadon Gym Member 3");
static const struct TrainerTemplate gmCeladon3 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BEAUTY,
    .trainerName = gmCeladon3Name,
    .partySize = 3,
    .poolSize = 9,
    .party = &gmCeladon3Party,
    .introText = gmCeladon3IntroText,
    .defeatText = gmCeladon3DefeatText,
    .postbattleText = gmCeladon3PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_GIRL_2,
};

static const struct PokemonTemplate gmCeladon4Party[] = {
    { .species = SPECIES_TURTWIG },
    { .species = SPECIES_BUDEW },
    { .species = SPECIES_CHERUBI },
    { .species = SPECIES_SNOVER },
    { .species = SPECIES_SEWADDLE },
    { .species = SPECIES_COTTONEE },
    { .species = SPECIES_PETILIL },
    { .species = SPECIES_MARACTUS },
    { .species = SPECIES_DEERLING },
    { .species = SPECIES_FERROSEED },
    { .species = SPECIES_AMOONGUSS },
};
static const u8 gmCeladon4IntroText[] = _("intro text");
static const u8 gmCeladon4DefeatText[] = _("defeat text");
static const u8 gmCeladon4PostbattleText[] = _("postbattle text");
static const u8 gmCeladon4Name[] = _("Celadon Gym Member 3");
static const struct TrainerTemplate gmCeladon4 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BEAUTY,
    .trainerName = gmCeladon4Name,
    .partySize = 3,
    .poolSize = 11,
    .party = &gmCeladon4Party,
    .introText = gmCeladon4IntroText,
    .defeatText = gmCeladon4DefeatText,
    .postbattleText = gmCeladon4PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_GIRL_3,
};

static const struct PokemonTemplate glCeladon1Party[] = {
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_RAZOR_LEAF, MOVE_WRAP, MOVE_POISON_POWDER, MOVE_SLEEP_POWDER} },
    { .species = SPECIES_TANGELA, .moves = {MOVE_CONSTRICT, MOVE_BIND, MOVE_NONE, MOVE_NONE} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_PETAL_DANCE, MOVE_POISON_POWDER, MOVE_MEGA_DRAIN, MOVE_SLEEP_POWDER}, .evoStrat = EVO_STRAT_NO_BELLOSSOM },
    { .species = SPECIES_TANGELA, .moves = {MOVE_BIND, MOVE_MEGA_DRAIN, MOVE_VINE_WHIP, MOVE_CONSTRICT} },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_ACID, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER, MOVE_RAZOR_LEAF} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_ACID, MOVE_PETAL_DANCE, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER} },
    { .species = SPECIES_TANGELA, .moves = {MOVE_VINE_WHIP, MOVE_BIND, MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER} },
    { .species = SPECIES_HOPPIP, .moves = {MOVE_MEGA_DRAIN, MOVE_LEECH_SEED, MOVE_COTTON_SPORE, MOVE_GIGA_DRAIN} },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_ACID, MOVE_RAZOR_LEAF} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_PETAL_DANCE, MOVE_SOLAR_BEAM}, .evoStrat = EVO_STRAT_NO_VILEPLUME },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_STUN_SPORE, MOVE_ACID, MOVE_POISON_POWDER, MOVE_GIGA_DRAIN} },
    { .species = SPECIES_TANGELA, .moves = {MOVE_POISON_POWDER, MOVE_CONSTRICT, MOVE_INGRAIN, MOVE_GIGA_DRAIN} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_SLEEP_POWDER, MOVE_ACID, MOVE_STUN_SPORE, MOVE_GIGA_DRAIN}, .evoStrat = EVO_STRAT_NO_VILEPLUME },
    { .species = SPECIES_HOPPIP, .moves = {MOVE_LEECH_SEED, MOVE_U_TURN, MOVE_GIGA_DRAIN, MOVE_SUNNY_DAY} },
    { .species = SPECIES_TANGELA, .moves = {MOVE_ANCIENT_POWER, MOVE_WRING_OUT, MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER} },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_SUNNY_DAY, MOVE_SYNTHESIS, MOVE_LEAF_STORM, MOVE_GRASS_KNOT} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_GIGA_DRAIN, MOVE_SYNTHESIS}, .evoStrat = EVO_STRAT_NO_VILEPLUME },
    { .species = SPECIES_TANGELA, .moves = {MOVE_MEGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_BIND, MOVE_NONE} },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_MEGA_DRAIN, MOVE_POISON_JAB, MOVE_NONE, MOVE_NONE} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_MEGA_DRAIN, MOVE_MOONBLAST, MOVE_NONE, MOVE_NONE} },
    { .species = SPECIES_TANGELA, .moves = {MOVE_MEGA_DRAIN, MOVE_SLUDGE_BOMB, MOVE_REFLECT, MOVE_POWER_WHIP} },
};
static const u8 glCeladon1IntroText[] = _("intro text");
static const u8 glCeladon1DefeatText[] = _("defeat text");
static const u8 glCeladon1PostbattleText[] = _("postbattle text");
static const u8 glCeladon1Name[] = _("Erika 1");
static const struct TrainerTemplate glCeladon1 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BEAUTY,
    .trainerName = glCeladon1Name,
    .partySize = 6,
    .poolSize = 21,
    .party = &glCeladon1Party,
    .introText = glCeladon1IntroText,
    .defeatText = glCeladon1DefeatText,
    .postbattleText = glCeladon1PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BEAUTY,
};

static const struct PokemonTemplate glCeladon2Party[] = {
    { .species = SPECIES_PARAS, .moves = {MOVE_SOLAR_BEAM, MOVE_BRICK_BREAK, MOVE_LEECH_LIFE, MOVE_SPORE} },
    { .species = SPECIES_EXEGGCUTE, .moves = {MOVE_SOLAR_BEAM, MOVE_SLUDGE_BOMB, MOVE_HYPER_BEAM, MOVE_PSYCHIC} },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_POWER_WHIP, MOVE_POISON_JAB, MOVE_REFLECT, MOVE_SWORDS_DANCE} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_MOONBLAST, MOVE_PETAL_DANCE, MOVE_SLUDGE_BOMB, MOVE_STUN_SPORE}, .evoStrat = EVO_STRAT_NO_BELLOSSOM },
    { .species = SPECIES_ODDISH, .moves = {MOVE_ACID, MOVE_SLEEP_POWDER, MOVE_PETAL_DANCE, MOVE_MEGA_DRAIN} },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_SLEEP_POWDER, MOVE_ACID, MOVE_RAZOR_LEAF, MOVE_CUT} },
    { .species = SPECIES_TANGELA, .moves = {MOVE_BIND, MOVE_STUN_SPORE, MOVE_DOUBLE_EDGE, MOVE_MEGA_DRAIN} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_ACID, MOVE_ABSORB, MOVE_SOLAR_BEAM, MOVE_BODY_SLAM}, .evoStrat = EVO_STRAT_NO_BELLOSSOM },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_WRAP, MOVE_STUN_SPORE, MOVE_MEGA_DRAIN, MOVE_RAZOR_LEAF} },
    { .species = SPECIES_EXEGGCUTE, .moves = {MOVE_HYPNOSIS, MOVE_LEECH_SEED, MOVE_TOXIC, MOVE_PSYCHIC} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_STUN_SPORE, MOVE_PETAL_DANCE, MOVE_BODY_SLAM, MOVE_MEGA_DRAIN}, .evoStrat = EVO_STRAT_NO_BELLOSSOM },
    { .species = SPECIES_TANGELA, .moves = {MOVE_BIND, MOVE_TOXIC, MOVE_DOUBLE_EDGE, MOVE_MEGA_DRAIN} },
    { .species = SPECIES_BELLSPROUT, .moves = {MOVE_BIND, MOVE_MEGA_DRAIN, MOVE_RAZOR_LEAF, MOVE_TOXIC} },
    { .species = SPECIES_EXEGGCUTE, .moves = {MOVE_HYPNOSIS, MOVE_EXPLOSION, MOVE_PSYCHIC, MOVE_MEGA_DRAIN} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_SLEEP_POWDER, MOVE_RETURN, MOVE_MOONLIGHT, MOVE_GIGA_DRAIN}, .evoStrat = EVO_STRAT_NO_VILEPLUME },
    { .species = SPECIES_TANGELA, .moves = {MOVE_SLEEP_POWDER, MOVE_SLAM, MOVE_SOLAR_BEAM, MOVE_GIGA_DRAIN} },
    { .species = SPECIES_BULBASAUR, .moves = {MOVE_SLEEP_POWDER, MOVE_CUT, MOVE_LEECH_SEED, MOVE_RAZOR_LEAF} },
    { .species = SPECIES_HOPPIP, .moves = {MOVE_SLEEP_POWDER, MOVE_RETURN, MOVE_SOLAR_BEAM, MOVE_LEECH_SEED} },
    { .species = SPECIES_ODDISH, .moves = {MOVE_RETURN, MOVE_RAZOR_LEAF, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER}, .evoStrat = EVO_STRAT_NO_VILEPLUME },
    { .species = SPECIES_EXEGGCUTE, .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER} },
};
static const u8 glCeladon2IntroText[] = _("intro text");
static const u8 glCeladon2DefeatText[] = _("defeat text");
static const u8 glCeladon2PostbattleText[] = _("postbattle text");
static const u8 glCeladon2Name[] = _("Erika 2");
static const struct TrainerTemplate glCeladon2 = {
    .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
    .trainerPic = TRAINER_PIC_BEAUTY,
    .trainerName = glCeladon2Name,
    .partySize = 6,
    .poolSize = 20,
    .party = &glCeladon2Party,
    .introText = glCeladon2IntroText,
    .defeatText = glCeladon2DefeatText,
    .postbattleText = glCeladon2PostbattleText,
    .graphicsId = OBJ_EVENT_GFX_BEAUTY,
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
static const struct TrainerTemplate* const celadonGymMembers[POSSIBLE_CELADON_GYM_MEMBERS] = {
    &gmCeladon1,
    &gmCeladon2,
    &gmCeladon3,
    &gmCeladon4,
};
static const struct TrainerTemplate* const celadonGymLeaders[POSSIBLE_CELADON_GYM_LEADERS] = {
    &glCeladon1,
    &glCeladon2,
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
    &ceruleanGymLeaders,
    &celadonGymMembers,
    &celadonGymLeaders,
};
