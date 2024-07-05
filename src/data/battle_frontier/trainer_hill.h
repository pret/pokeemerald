// NOTE: Each of these macros turn data into one byte. Therefore ranges for all arguments is 0-15
// See struct TrainerHillFloorMap for more info about each
#define COORDS_XY(x,y)      ((y<<4)|(x))
#define TRAINER_DIRS(a, b)  (((a-1)<<4)|(b-1))
#define TRAINER_RANGE(a, b) ((a<<4)|(b))

// WARNING: While not referenced directly, the floor data in this file is referenced by virtue
//          of coming after its corresponding challenge (see SetUpDataStruct in trainer_hill.c).
//          Do not insert data between a pair of 'sChallenge_Mode' and 'sFloors_Mode'.

// Unused
static const struct TrainerHillChallenge sChallenge_JPDefault = {
    .numTrainers = NUM_TRAINER_HILL_TRAINERS_JP,
    .unused1 = 1,
    .numFloors = NUM_TRAINER_HILL_FLOORS_JP,
    .checksum = 0x0
};

// Unused
static const struct TrainerHillFloor sFloors_JPDefault[] = {
    [0] = {
        .trainerNum1 = 0,
        .trainerNum2 = 0,
        .trainers = {
            [0] = {
                .name = __("シゲノブ$$$$   "),
                .facilityClass = FACILITY_CLASS_YOUNGSTER,
                .unused = TRUE,
                .speechBefore = { EC_WORD_TRAINER, EC_WORD_MRS, EC_WORD_EXCL, EC_WORD_THEY_WERE, EC_WORD_OPPONENT, EC_WORD_CAN },
                .speechWin = { EC_WORD_TRAINER, EC_WORD_MRS, EC_WORD_WEAK, EC_WORD_OF, EC_WORD_WERE, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS },
                .speechLose = { EC_WORD_TRAINER, EC_WORD_MRS, EC_WORD_STRONG, EC_WORD_HEY_QUES, EC_WORD_EXCL, EC_WORD_EXCL },
                .speechAfter = { EC_WORD_FABULOUS, EC_WORD_CAN_T, EC_WORD_TRAINER, EC_WORD_MRS, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_EXCITING },
                .mons = {
                    [0] = {
                        .species = SPECIES_ZIGZAGOON,
                        .heldItem = ITEM_SITRUS_BERRY,
                        .moves = { MOVE_HEADBUTT, MOVE_PIN_MISSILE, MOVE_GROWL, MOVE_TAIL_WHIP },
                        .hpEV = 110,
                        .attackEV = 100,
                        .defenseEV = 100,
                        .speedEV = 100,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x80,
                        .nickname = __("ジグザグマ$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [1] = {
                        .species = SPECIES_SHROOMISH,
                        .heldItem = ITEM_PECHA_BERRY,
                        .moves = { MOVE_MEGA_DRAIN, MOVE_LEECH_SEED, MOVE_POISON_POWDER, MOVE_GROWTH },
                        .hpEV = 120,
                        .defenseEV = 120,
                        .spAttackEV = 150,
                        .spDefenseEV = 120,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x0,
                        .nickname = __("キノココ$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [2] = {
                        .species = SPECIES_SANDSHREW,
                        .heldItem = ITEM_QUICK_CLAW,
                        .moves = { MOVE_SCRATCH, MOVE_POISON_STING, MOVE_SAND_ATTACK, MOVE_SWIFT },
                        .hpEV = 110,
                        .attackEV = 100,
                        .defenseEV = 100,
                        .spDefenseEV = 200,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x80,
                        .nickname = __("サンド$$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [3] = DUMMY_HILL_MON,
                    [4] = DUMMY_HILL_MON,
                    [5] = DUMMY_HILL_MON
                }
            },
            [1] = {
                .name = __("アカリ$$$$$   "),
                .facilityClass = FACILITY_CLASS_PARASOL_LADY,
                .unused = TRUE,
                .speechBefore = { EC_WORD_SHE, EC_WORD_EVERY, EC_WORD_TYPE, EC_WORD_ADORE, EC_WORD_FOR, EC_WORD_EXCL },
                .speechWin = { EC_WORD_SURPRISE, EC_WORD_THESE, EC_WORD_WONDER, EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_WORD_EXCL },
                .speechLose = { EC_WORD_OH_QUES, EC_MOVE(EARTHQUAKE), EC_WORD_EXISTS, EC_WORD_OF, EC_WORD_WITHOUT, EC_WORD_EXCL },
                .speechAfter = { EC_WORD_YOU_RE, EC_WORD_PROBABLY, EC_WORD_END, EC_WORD_UNTIL, EC_WORD_GOING, EC_WORD_ANYWHERE },
                .mons = {
                    [0] = DUMMY_HILL_MON,
                    [1] = DUMMY_HILL_MON,
                    [2] = DUMMY_HILL_MON,
                    [3] = {
                        .species = SPECIES_WINGULL,
                        .heldItem = ITEM_CHERI_BERRY,
                        .moves = { MOVE_WATER_GUN, MOVE_WING_ATTACK, MOVE_GROWL, MOVE_SUPERSONIC },
                        .hpEV = 110,
                        .attackEV = 100,
                        .defenseEV = 100,
                        .spAttackEV = 100,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x0,
                        .nickname = __("キャモメ$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [4] = {
                        .species = SPECIES_NUMEL,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = { MOVE_EMBER, MOVE_DIG, MOVE_TACKLE, MOVE_FOCUS_ENERGY },
                        .hpEV = 110,
                        .attackEV = 100,
                        .defenseEV = 100,
                        .spAttackEV = 100,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x96,
                        .nickname = __("ドンメル$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [5] = {
                        .species = SPECIES_SURSKIT,
                        .heldItem = ITEM_PERSIM_BERRY,
                        .moves = { MOVE_BUBBLE_BEAM, MOVE_MUD_SHOT, MOVE_QUICK_ATTACK, MOVE_AGILITY },
                        .hpEV = 100,
                        .attackEV = 100,
                        .defenseEV = 100,
                        .spAttackEV = 100,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x0,
                        .nickname = __("アメタマ$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                }
            },
        },
        .map = {
            .metatileData = INCBIN_U8("graphics/trainer_hill/maps_jp/floor_0/metatiles.bin"),
            .collisionData = INCBIN_U16("graphics/trainer_hill/maps_jp/floor_0/collision.bin"),
            .trainerCoords = { COORDS_XY(8,2), COORDS_XY(8,7) },
            .trainerDirections = TRAINER_DIRS(DIR_SOUTH, DIR_NORTH),
            .trainerRanges = TRAINER_RANGE(2, 3)
        }
    },
    [1] = {
        .trainerNum1 = 0,
        .trainerNum2 = 0,
        .trainers = {
            [0] = {
                .name = __("シゲゾウ$$$$   "),
                .facilityClass = FACILITY_CLASS_NINJA_BOY,
                .unused = TRUE,
                .speechBefore = { EC_WORD_WIN, EC_WORD_UNTIL, EC_WORD_DAUGHTER, EC_MOVE(CONSTRICT), EC_WORD_OF, EC_WORD_WERE },
                .speechWin = { EC_MOVE(CONSTRICT), EC_WORD_UNTIL, EC_WORD_LESS, EC_WORD_NONE, EC_WORD_HEY_QUES, EC_WORD_EXCL },
                .speechLose = { EC_WORD_YET, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_URGH, EC_WORD_ALMOST, EC_WORD_POWER, EC_WORD_NONE },
                .speechAfter = { EC_WORD_HUH_QUES, EC_WORD_TOMORROW, EC_WORD_SMELL, EC_WORD_ABSOLUTELY, EC_WORD_THOSE, EC_WORD_EXCL_EXCL },
                .mons = {
                    [0] = {
                        .species = SPECIES_ELECTRIKE,
                        .heldItem = ITEM_CHERI_BERRY,
                        .moves = { MOVE_SPARK, MOVE_THUNDER_WAVE, MOVE_QUICK_ATTACK, MOVE_ROAR },
                        .hpEV = 120,
                        .attackEV = 120,
                        .speedEV = 120,
                        .spAttackEV = 150,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 1,
                        .personality = 0x0,
                        .nickname = __("ラクライ$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [1] = {
                        .species = SPECIES_CORPHISH,
                        .heldItem = ITEM_QUICK_CLAW,
                        .moves = { MOVE_KNOCK_OFF, MOVE_CRABHAMMER, MOVE_TAUNT, MOVE_PROTECT },
                        .hpEV = 100,
                        .attackEV = 110,
                        .defenseEV = 100,
                        .spAttackEV = 100,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 1,
                        .personality = 0x96,
                        .nickname = __("ヘイガニ$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [2] = {
                        .species = SPECIES_BALTOY,
                        .heldItem = ITEM_PERSIM_BERRY,
                        .moves = { MOVE_PSYBEAM, MOVE_ROCK_TOMB, MOVE_MUD_SLAP, MOVE_HARDEN },
                        .hpEV = 100,
                        .attackEV = 100,
                        .defenseEV = 100,
                        .spAttackEV = 110,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x96,
                        .nickname = __("ヤジロン$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [3] = DUMMY_HILL_MON,
                    [4] = DUMMY_HILL_MON,
                    [5] = DUMMY_HILL_MON,
                }
            },
            [1] = {
                .name = __("ナミコ$$$$$   "),
                .facilityClass = FACILITY_CLASS_BEAUTY,
                .unused = TRUE,
                .speechBefore = { EC_WORD_SISTER, EC_WORD_ALTHOUGH, EC_WORD_KIND, EC_WORD_MATCH, EC_WORD_PLEASE, EC_WORD_WITHOUT },
                .speechWin = { EC_WORD_KIND, EC_WORD_ELLIPSIS, EC_WORD_INSTEAD, EC_WORD_DEEP, EC_WORD_WEAK, EC_WORD_QUES },
                .speechLose = { EC_WORD_AWFUL, EC_WORD_GWAH, EC_WORD_HOPELESS, EC_WORD_CAN_T_WIN, EC_WORD_IS, EC_WORD_NONE },
                .speechAfter = { EC_WORD_AWW, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_WORD_ALMOST, EC_WORD_GOOD, EC_WORD_ANYWHERE },
                .mons = {
                    [0] = DUMMY_HILL_MON,
                    [1] = DUMMY_HILL_MON,
                    [2] = DUMMY_HILL_MON,
                    [3] = {
                        .species = SPECIES_SPHEAL,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = { MOVE_ICE_BALL, MOVE_BODY_SLAM, MOVE_WATER_GUN, MOVE_ENCORE },
                        .hpEV = 100,
                        .attackEV = 100,
                        .defenseEV = 100,
                        .spAttackEV = 110,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x80,
                        .nickname = __("タマザラシ$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [4] = {
                        .species = SPECIES_SPOINK,
                        .heldItem = ITEM_PERSIM_BERRY,
                        .moves = { MOVE_PSYWAVE, MOVE_FUTURE_SIGHT, MOVE_CONFUSE_RAY, MOVE_MAGIC_COAT },
                        .hpEV = 100,
                        .defenseEV = 100,
                        .speedEV = 100,
                        .spAttackEV = 110,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 1,
                        .personality = 0xf,
                        .nickname = __("バネブー$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                    [5] = {
                        .species = SPECIES_POOCHYENA,
                        .heldItem = ITEM_PECHA_BERRY,
                        .moves = { MOVE_BITE, MOVE_POISON_FANG, MOVE_SWAGGER, MOVE_SCARY_FACE },
                        .hpEV = 70,
                        .attackEV = 80,
                        .defenseEV = 80,
                        .speedEV = 80,
                        .spAttackEV = 80,
                        .spDefenseEV = 80,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x96,
                        .nickname = __("ポチエナ$$$$$$$"),
                        .friendship = MAX_FRIENDSHIP
                    },
                }
            },
        },
        .map = {
            .metatileData = INCBIN_U8("graphics/trainer_hill/maps_jp/floor_1/metatiles.bin"),
            .collisionData = INCBIN_U16("graphics/trainer_hill/maps_jp/floor_1/collision.bin"),
            .trainerCoords = { COORDS_XY(7,6), COORDS_XY(7,10) },
            .trainerDirections = TRAINER_DIRS(DIR_SOUTH, DIR_NORTH),
            .trainerRanges = TRAINER_RANGE(3, 3)
        }
    },
};

static const struct TrainerHillChallenge sChallenge_Normal =
{
    .numTrainers = NUM_TRAINER_HILL_TRAINERS,
    .unused1 = 2,
    .numFloors = NUM_TRAINER_HILL_FLOORS,
    .checksum = 0x00051E05
};

static const struct TrainerHillFloor sFloors_Normal[] =
{
    [0] =
    {
        .trainerNum1 = 17,
        .trainerNum2 = 18,
        .trainers =
        {
            [0] =
            {
            #if FRENCH
                .name = _("ALAINA"),
                .facilityClass = FACILITY_CLASS_HEX_MANIAC,
                .speechBefore = {EC_WORD_YOU, EC_WORD_ISN_T, EC_WORD_ON, EC_WORD_NOT, EC_WORD_WHO_WAS, EC_WORD_BELIEVE, },
                .speechWin = {EC_WORD_TAKE_THAT, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                .speechLose = {EC_WORD_IT_S, EC_WORD_IMPOSSIBLE, EC_WORD_IT_S, EC_WORD_A, EC_MOVE(NIGHTMARE), EC_WORD_EXCL, },
                .speechAfter = {EC_WORD_ARRGH, EC_WORD_EXCL, EC_WORD_DISAPPEAR, EC_WORD_AFTER, EC_WORD_CASE, EC_WORD_DARK, },
            #elif ITALIAN
                .name = _("MARISTELLA"),
                .facilityClass = FACILITY_CLASS_HEX_MANIAC,
                .speechBefore = {EC_WORD_CHOOSE, EC_WORD_LOWS, EC_WORD_IF_I_WIN, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechWin = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_LISTENS, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_NATURAL},
                .speechLose = {EC_WORD_IS, EC_WORD_A, EC_MOVE(NIGHTMARE), EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechAfter = {EC_WORD_WHOM, EC_WORD_TRAINS, EC_WORD_IF_I_LOSE, EC_WORD_ALTHOUGH, EC_WORD_DARK, EC_WORD_ELLIPSIS},
            #else //ENGLISH
                .name = _("ALAINA"),
                .facilityClass = FACILITY_CLASS_HEX_MANIAC,
                .speechBefore = {EC_WORD_YOU, EC_WORD_CAN, EC_WORD_CHOOSE, EC_WORD_NOT, EC_WORD_TO, EC_WORD_BELIEVE},
                .speechWin = {EC_WORD_A, EC_WORD_SUPER, EC_WORD_NATURAL, EC_WORD_POWER, EC_WORD_HAS, EC_WORD_COME},
                .speechLose = {EC_WORD_THIS, EC_WORD_MUST_BE, EC_WORD_A, EC_MOVE(NIGHTMARE), EC_WORD_EXCL, EC_EMPTY_WORD},
                .speechAfter = {EC_WORD_I, EC_WORD_WILL, EC_WORD_DISAPPEAR, EC_WORD_IN, EC_WORD_THE, EC_WORD_DARK},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_MISDREAVUS,
                        .heldItem = ITEM_BRIGHT_POWDER,
                        .moves = {MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_CONFUSE_RAY},
                        .attackEV = 155,
                        .speedEV = 255,
                        .spAttackEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 24,
                        .attackIV = 24,
                        .defenseIV = 24,
                        .speedIV = 24,
                        .spAttackIV = 24,
                        .spDefenseIV = 24,
                        .abilityNum = 0,
                        .personality = 0x0,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MISDREAVUS"),
                    #elif FRENCH
                        .nickname = _("FEUFOREVE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [1] =
                    {
                        .species = SPECIES_SOLROCK,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_PSYCHIC, MOVE_FLAMETHROWER, MOVE_ROCK_SLIDE, MOVE_CALM_MIND},
                        .hpEV = 200,
                        .defenseEV = 100,
                        .spAttackEV = 110,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 24,
                        .attackIV = 24,
                        .defenseIV = 24,
                        .speedIV = 24,
                        .spAttackIV = 24,
                        .spDefenseIV = 24,
                        .abilityNum = 0,
                        .personality = 0xF,
                    #if ENGLISH || ITALIAN
                        .nickname = _("SOLROCK"),
                    #elif FRENCH
                        .nickname = _("SOLAROC"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [2] =
                    {
                        .species = SPECIES_CLAYDOL,
                        .heldItem = ITEM_SHELL_BELL,
                        .moves = {MOVE_EARTHQUAKE, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_ICE_BEAM},
                        .hpEV = 255,
                        .defenseEV = 135,
                        .spDefenseEV = 120,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 24,
                        .attackIV = 24,
                        .defenseIV = 24,
                        .speedIV = 24,
                        .spAttackIV = 24,
                        .spDefenseIV = 24,
                        .abilityNum = 0,
                        .personality = 0xC,
                    #if ENGLISH || ITALIAN
                        .nickname = _("CLAYDOL"),
                    #elif FRENCH
                        .nickname = _("KAORINE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [3] =
                    {
                        .species = SPECIES_WEEZING,
                        .heldItem = ITEM_SALAC_BERRY,
                        .moves = {MOVE_SLUDGE_BOMB, MOVE_SHADOW_BALL, MOVE_FRUSTRATION, MOVE_DESTINY_BOND},
                        .hpEV = 110,
                        .attackEV = 200,
                        .spDefenseEV = 200,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 24,
                        .attackIV = 24,
                        .defenseIV = 24,
                        .speedIV = 24,
                        .spAttackIV = 24,
                        .spDefenseIV = 24,
                        .abilityNum = 0,
                        .personality = 0x80,
                    #if ENGLISH || ITALIAN
                        .nickname = _("WEEZING"),
                    #elif FRENCH
                        .nickname = _("SMOGOGO"),
                    #endif
                        .friendship = 0,
                    },
                    [4] =
                    {
                        .species = SPECIES_LUNATONE,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_PSYCHIC, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_CALM_MIND},
                        .hpEV = 200,
                        .defenseEV = 100,
                        .spAttackEV = 110,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 24,
                        .attackIV = 24,
                        .defenseIV = 24,
                        .speedIV = 24,
                        .spAttackIV = 24,
                        .spDefenseIV = 24,
                        .abilityNum = 0,
                        .personality = 0xF,
                    #if ENGLISH || ITALIAN
                        .nickname = _("LUNATONE"),
                    #elif FRENCH
                        .nickname = _("SELEROC"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [5] =
                    {
                        .species = SPECIES_FLYGON,
                        .heldItem = ITEM_CHOICE_BAND,
                        .moves = {MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_CRUNCH, MOVE_FLAMETHROWER},
                        .attackEV = 155,
                        .speedEV = 255,
                        .spAttackEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 24,
                        .attackIV = 24,
                        .defenseIV = 24,
                        .speedIV = 24,
                        .spAttackIV = 24,
                        .spDefenseIV = 24,
                        .abilityNum = 0,
                        .personality = 0x83,
                    #if ENGLISH || ITALIAN
                        .nickname = _("FLYGON"),
                    #elif FRENCH
                        .nickname = _("LIBEGON"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
            [1] =
            {
            #if FRENCH
                .name = _("BARTH"),
                .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
                .speechBefore = {EC_WORD_THE, EC_EMPTY_WORD, EC_WORD_TRAIN, EC_WORD_QUES, EC_WORD_THANKS, EC_EMPTY_WORD, },
                .speechWin = {EC_WORD_I_AM, EC_WORD_FAST, EC_WORD_UP, EC_WORD_MY, EC_WORD_BIKE, EC_WORD_EXCL, },
                .speechLose = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_DESTROYED, EC_WORD_EXCL, },
                .speechAfter = {EC_WORD_A, EC_WORD_BIKE, EC_WORD_VERSUS, EC_WORD_A, EC_WORD_TRAIN, EC_WORD_QUES, },
            #elif ITALIAN
                .name = _("ALFONSO"),
                .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
                .speechBefore = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_MUST_BE, EC_WORD_GOTCHA, EC_WORD_IT, EC_WORD_TRAIN},
                .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_SUPER, EC_WORD_EXCL},
                .speechLose = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_BIKE, EC_WORD_QUES_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechAfter = {EC_WORD_WEREN_T, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_NOT_VERY, EC_WORD_TRAIN},
            #else //ENGLISH
                .name = _("ALFONSO"),
                .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
                .speechBefore = {EC_WORD_I, EC_WORD_NEVER, EC_WORD_TAKE, EC_WORD_A, EC_WORD_TRAIN, EC_EMPTY_WORD},
                .speechWin = {EC_WORD_I_AM, EC_WORD_FEELING, EC_MOVE2(SUPERSONIC), EC_WORD_ON, EC_WORD_MY, EC_WORD_BIKE},
                .speechLose = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_EXCL, EC_WORD_YOU_VE, EC_WORD_DESTROYED, EC_WORD_IT},
                .speechAfter = {EC_WORD_A, EC_WORD_BIKE, EC_WORD_OVER, EC_WORD_ANY, EC_WORD_TRAIN, EC_WORD_EXCL},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_SEALEO,
                        .heldItem = ITEM_NEVER_MELT_ICE,
                        .moves = {MOVE_BLIZZARD, MOVE_ICE_BALL, MOVE_ENCORE, MOVE_HAIL},
                        .hpEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0xF,
                    #if ENGLISH || ITALIAN
                        .nickname = _("SEALEO"),
                    #elif FRENCH
                        .nickname = _("PHOGLEUR"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [1] =
                    {
                        .species = SPECIES_AMPHAROS,
                        .heldItem = ITEM_MAGNET,
                        .moves = {MOVE_THUNDER, MOVE_THUNDER_WAVE, MOVE_COTTON_SPORE, MOVE_LIGHT_SCREEN},
                        .speedEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0xF,
                    #if ENGLISH || ITALIAN
                        .nickname = _("AMPHAROS"),
                    #elif FRENCH
                        .nickname = _("PHARAMP"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [2] =
                    {
                        .species = SPECIES_MACHOKE,
                        .heldItem = ITEM_BLACK_BELT,
                        .moves = {MOVE_DYNAMIC_PUNCH, MOVE_MUD_SLAP, MOVE_COUNTER, MOVE_SCARY_FACE},
                        .hpEV = 255,
                        .attackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x4E,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MACHOKE"),
                    #elif FRENCH
                        .nickname = _("MACHOPEUR"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [3] =
                    {
                        .species = SPECIES_FLAREON,
                        .heldItem = ITEM_CHARCOAL,
                        .moves = {MOVE_FIRE_BLAST, MOVE_BITE, MOVE_QUICK_ATTACK, MOVE_SAND_ATTACK},
                        .speedEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x28,
                    #if ENGLISH || ITALIAN
                        .nickname = _("FLAREON"),
                    #elif FRENCH
                        .nickname = _("PYROLI"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [4] =
                    {
                        .species = SPECIES_MAGNETON,
                        .heldItem = ITEM_MAGNET,
                        .moves = {MOVE_ZAP_CANNON, MOVE_THUNDER_WAVE, MOVE_SCREECH, MOVE_METAL_SOUND},
                        .speedEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x0,
                        .nickname = _("MAGNETON"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [5] =
                    {
                        .species = SPECIES_PINSIR,
                        .heldItem = ITEM_QUICK_CLAW,
                        .moves = {MOVE_GUILLOTINE, MOVE_BRICK_BREAK, MOVE_SWAGGER, MOVE_FAINT_ATTACK},
                        .hpEV = 200,
                        .defenseEV = 155,
                        .spDefenseEV = 155,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x85,
                    #if ENGLISH || ITALIAN
                        .nickname = _("PINSIR"),
                    #elif FRENCH
                        .nickname = _("SCARABRUTE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
        },
        .map = {
            .metatileData = INCBIN_U8("graphics/trainer_hill/maps_normal/floor_0/metatiles.bin"),
            .collisionData = INCBIN_U16("graphics/trainer_hill/maps_normal/floor_0/collision.bin"),
            .trainerCoords = {COORDS_XY(11,1), COORDS_XY(13,2)},
            .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_NORTH),
            .trainerRanges = TRAINER_RANGE(2, 1),
        }
    },
    [1] =
    {
        .trainerNum1 = 19,
        .trainerNum2 = 20,
        .trainers =
        {
            [0] =
            {
            #if FRENCH
                .name = _("THEODORE"),
                .facilityClass = FACILITY_CLASS_BLACK_BELT,
                .speechBefore = {EC_WORD_I_AM, EC_WORD_POWER, EC_WORD_AND, EC_WORD_ANGRY, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                .speechWin = {EC_WORD_WAAAH, EC_WORD_AHAHA, EC_WORD_WAAAH, EC_WORD_AHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                .speechLose = {EC_WORD_I_WAS, EC_WORD_A_LOT, EC_WORD_RECOMMEND, EC_WORD_FAST, EC_WORD_ARRGH, EC_WORD_EXCL, },
                .speechAfter = {EC_WORD_YES_SIR_EXCL, EC_WORD_QUES, EC_WORD_IT_S, EC_WORD_ALWAYS, EC_WORD_AN, EC_WORD_JOY, },
            #elif ITALIAN
                .name = _("TEODORO"),
                .facilityClass = FACILITY_CLASS_BLACK_BELT,
                .speechBefore = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_MOVE(STRENGTH), EC_WORD_IS, EC_WORD_OVERWHELMING, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS},
                .speechWin = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_TEACHES, EC_WORD_REFRESHING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechAfter = {EC_WORD_WILL, EC_WORD_SMACK, EC_WORD_TAKE_THAT, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_MOVE(STRENGTH)},
            #else //ENGLISH
                .name = _("THEODORE"),
                .facilityClass = FACILITY_CLASS_BLACK_BELT,
                .speechBefore = {EC_WORD_MY, EC_WORD_POWER, EC_WORD_WILL, EC_MOVE2(STOMP), EC_WORD_YOU, EC_WORD_EXCL},
                .speechWin = {EC_WORD_WAAAH, EC_WORD_HAHAHA, EC_WORD_EXCL, EC_WORD_WAAAH, EC_WORD_HAHAHA, EC_WORD_EXCL_EXCL},
                .speechLose = {EC_WORD_I, EC_WORD_WENT, EC_WORD_AT, EC_WORD_IT, EC_WORD_TOO, EC_WORD_HARD},
                .speechAfter = {EC_WORD_YES_SIR_EXCL, EC_WORD_YOU, EC_WORD_LOOK, EC_WORD_NICE, EC_WORD_AND, EC_WORD_GUTSY},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_MEDITITE,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_FOCUS_PUNCH, MOVE_PROTECT, MOVE_NONE, MOVE_NONE},
                        .hpEV = 252,
                        .attackEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 20,
                        .defenseIV = 20,
                        .speedIV = 20,
                        .spAttackIV = 20,
                        .spDefenseIV = 20,
                        .abilityNum = 0,
                        .personality = 0x80,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MEDITITE"),
                    #elif FRENCH
                        .nickname = _("MEDITIKKA"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [1] =
                    {
                        .species = SPECIES_HERACROSS,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_FOCUS_PUNCH, MOVE_PROTECT, MOVE_NONE, MOVE_NONE},
                        .hpEV = 252,
                        .attackEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 20,
                        .defenseIV = 20,
                        .speedIV = 20,
                        .spAttackIV = 20,
                        .spDefenseIV = 20,
                        .abilityNum = 1,
                        .personality = 0x80,
                    #if ENGLISH || ITALIAN
                        .nickname = _("HERACROSS"),
                    #elif FRENCH
                        .nickname = _("SCARHINO"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [2] =
                    {
                        .species = SPECIES_HITMONTOP,
                        .heldItem = ITEM_SHELL_BELL,
                        .moves = {MOVE_FOCUS_PUNCH, MOVE_PROTECT, MOVE_NONE, MOVE_NONE},
                        .hpEV = 252,
                        .attackEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 20,
                        .defenseIV = 20,
                        .speedIV = 20,
                        .spAttackIV = 20,
                        .spDefenseIV = 20,
                        .abilityNum = 0,
                        .personality = 0x3,
                    #if ENGLISH || ITALIAN
                        .nickname = _("HITMONTOP"),
                    #elif FRENCH
                        .nickname = _("KAPOERA"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [3] =
                    {
                        .species = SPECIES_MACHOP,
                        .heldItem = ITEM_SALAC_BERRY,
                        .moves = {MOVE_FOCUS_PUNCH, MOVE_REVENGE, MOVE_NONE, MOVE_NONE},
                        .hpEV = 252,
                        .attackEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 20,
                        .defenseIV = 20,
                        .speedIV = 20,
                        .spAttackIV = 20,
                        .spDefenseIV = 20,
                        .abilityNum = 0,
                        .personality = 0x4E,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MACHOP"),
                    #elif FRENCH
                        .nickname = _("MACHOC"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [4] =
                    {
                        .species = SPECIES_PINSIR,
                        .heldItem = ITEM_SALAC_BERRY,
                        .moves = {MOVE_FOCUS_PUNCH, MOVE_REVENGE, MOVE_NONE, MOVE_NONE},
                        .hpEV = 252,
                        .attackEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 20,
                        .defenseIV = 20,
                        .speedIV = 20,
                        .spAttackIV = 20,
                        .spDefenseIV = 20,
                        .abilityNum = 0,
                        .personality = 0x80,
                    #if ENGLISH || ITALIAN
                        .nickname = _("PINSIR"),
                    #elif FRENCH
                        .nickname = _("SCARABRUTE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [5] =
                    {
                        .species = SPECIES_HITMONCHAN,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_FOCUS_PUNCH, MOVE_REVENGE, MOVE_NONE, MOVE_NONE},
                        .hpEV = 252,
                        .attackEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 20,
                        .defenseIV = 20,
                        .speedIV = 20,
                        .spAttackIV = 20,
                        .spDefenseIV = 20,
                        .abilityNum = 0,
                        .personality = 0x3,
                    #if ENGLISH || ITALIAN
                        .nickname = _("HITMONCHAN"),
                    #elif FRENCH
                        .nickname = _("TYGNON"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
            [1] =
            {
            #if FRENCH
                .name = _("LAETICIA"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
                .speechBefore = {EC_WORD_WHO, EC_WORD_BELONGS_TO, EC_WORD_WIN, EC_EMPTY_WORD, EC_WORD_TODAY, EC_WORD_QUES, },
                .speechWin = {EC_WORD_TODAY, EC_WORD_IT_S, EC_WORD_ME, EC_WORD_WHO, EC_WORD_WINS, EC_WORD_EXCL, },
                .speechLose = {EC_WORD_TODAY, EC_WORD_ELLIPSIS, EC_WORD_YOU_VE, EC_WORD_REALLY, EC_WORD_WINS, EC_WORD_EXCL, },
                .speechAfter = {EC_WORD_WANT, EC_WORD_MOOD, EC_WORD_FRIEND, EC_WORD_ELLIPSIS, EC_WORD_SIGH, EC_WORD_EXCL_EXCL, },
            #elif ITALIAN
                .name = _("ISOTTA"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
                .speechBefore = {EC_WORD_HOW, EC_WORD_IS, EC_WORD_BEAUTIFUL, EC_WORD_HEARING, EC_WORD_ME, EC_WORD_EXCL},
                .speechWin = {EC_WORD_HOW, EC_WORD_IS, EC_WORD_BEAUTIFUL, EC_WORD_IF_I_WIN, EC_WORD_ME, EC_WORD_EXCL},
                .speechLose = {EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_BEAUTIFUL, EC_WORD_IF_I_LOSE, EC_WORD_ME, EC_WORD_EXCL},
                .speechAfter = {EC_WORD_NATURALLY, EC_WORD_WHOM, EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_A, EC_WORD_BOY},
            #else //ENGLISH
                .name = _("JAYDEN"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
                .speechBefore = {EC_WORD_SOME, EC_WORD_THINGS, EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_DO, EC_WORD_ALONE},
                .speechWin = {EC_WORD_YOU, EC_WORD_WIN, EC_WORD_AS, EC_WORD_A, EC_WORD_GROUP, EC_EMPTY_WORD},
                .speechLose = {EC_WORD_WE, EC_WORD_COULDN_T, EC_WORD_WIN, EC_WORD_TOGETHER, EC_WORD_QUES, EC_EMPTY_WORD},
                .speechAfter = {EC_WORD_MAYBE, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_WORD_BOY, EC_WORD_FRIEND},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_VULPIX,
                        .heldItem = ITEM_LUM_BERRY,
                        .moves = {MOVE_WILL_O_WISP, MOVE_CONFUSE_RAY, MOVE_TAIL_WHIP, MOVE_OVERHEAT},
                        .hpEV = 252,
                        .defenseEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0xF,
                    #if ENGLISH || ITALIAN
                        .nickname = _("VULPIX"),
                    #elif FRENCH
                        .nickname = _("GOUPIX"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [1] =
                    {
                        .species = SPECIES_MINUN,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_THUNDER_WAVE, MOVE_CHARM, MOVE_ENCORE, MOVE_SPARK},
                        .hpEV = 252,
                        .defenseEV = 252,
                        .spAttackEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x8C,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MINUN"),
                    #elif FRENCH
                        .nickname = _("NEGAPI"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [2] =
                    {
                        .species = SPECIES_ROSELIA,
                        .heldItem = ITEM_LUM_BERRY,
                        .moves = {MOVE_TOXIC, MOVE_LEECH_SEED, MOVE_SWEET_SCENT, MOVE_GIGA_DRAIN},
                        .hpEV = 252,
                        .defenseEV = 252,
                        .spAttackEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 1,
                        .personality = 0xF,
                        .nickname = _("ROSELIA"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [3] =
                    {
                        .species = SPECIES_MR_MIME,
                        .heldItem = ITEM_SITRUS_BERRY,
                        .moves = {MOVE_SAFEGUARD, MOVE_REFLECT, MOVE_LIGHT_SCREEN, MOVE_PSYCHIC},
                        .hpEV = 252,
                        .defenseEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x82,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MR. MIME"),
                    #elif FRENCH
                        .nickname = _("M. MIME"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [4] =
                    {
                        .species = SPECIES_PLUSLE,
                        .heldItem = ITEM_SITRUS_BERRY,
                        .moves = {MOVE_RAIN_DANCE, MOVE_LIGHT_SCREEN, MOVE_HELPING_HAND, MOVE_THUNDER},
                        .hpEV = 252,
                        .defenseEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x5,
                    #if ENGLISH || ITALIAN
                        .nickname = _("PLUSLE"),
                    #elif FRENCH
                        .nickname = _("POSIPI"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [5] =
                    {
                        .species = SPECIES_TOGEPI,
                        .heldItem = ITEM_SITRUS_BERRY,
                        .moves = {MOVE_LIGHT_SCREEN, MOVE_REFLECT, MOVE_FOLLOW_ME, MOVE_METRONOME},
                        .hpEV = 252,
                        .defenseEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 1,
                        .personality = 0x37,
                        .nickname = _("TOGEPI"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
        },
        .map = {
            .metatileData = INCBIN_U8("graphics/trainer_hill/maps_normal/floor_1/metatiles.bin"),
            .collisionData = INCBIN_U16("graphics/trainer_hill/maps_normal/floor_1/collision.bin"),
            .trainerCoords = {COORDS_XY(4,11), COORDS_XY(9,14)},
            .trainerDirections = TRAINER_DIRS(DIR_SOUTH, DIR_EAST),
            .trainerRanges = TRAINER_RANGE(3, 5),
        }
    },
    [2] =
    {
        .trainerNum1 = 21,
        .trainerNum2 = 22,
        .trainers =
        {
            [0] =
            {
            #if FRENCH
                .name = _("ANGEL"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
                .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_EXCL, EC_WORD_COME_OVER, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL, },
                .speechWin = {EC_WORD_GO, EC_WORD_EXCL_EXCL, EC_WORD_EVEN_SO, EC_EMPTY_WORD, EC_WORD_FEELING, EC_WORD_HOME, },
                .speechLose = {EC_WORD_FEVER, EC_WORD_THAT, EC_WORD_I_VE, EC_WORD_LOST, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                .speechAfter = {EC_WORD_YOU, EC_WORD_IN, EC_WORD_DIDN_T, EC_WORD_ALWAYS, EC_WORD_RECOMMEND, EC_WORD_EXCL, },
            #elif ITALIAN
                .name = _("SALVATORE"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
                .speechBefore = {EC_WORD_GO_AHEAD, EC_WORD_ELLIPSIS, EC_WORD_WAKES_UP, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechWin = {EC_WORD_ABOVE, EC_WORD_IF, EC_WORD_REFUSE, EC_WORD_MEAN, EC_WORD_HOME, EC_WORD_ELLIPSIS},
                .speechLose = {EC_WORD_AS_IF, EC_WORD_WILL, EC_WORD_SAYS, EC_WORD_THOSE_ARE, EC_WORD_MEAN, EC_WORD_IF_I_WIN},
                .speechAfter = {EC_WORD_AS_IF, EC_WORD_OVER, EC_WORD_WILL, EC_WORD_MUST_BE, EC_WORD_WHERE, EC_WORD_QUES},
            #else //ENGLISH
                .name = _("SALVADORE"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
                .speechBefore = {EC_WORD_LET_S, EC_MOVE2(WRAP), EC_WORD_THINGS, EC_WORD_UP, EC_WORD_HERE, EC_WORD_HEY_QUES},
                .speechWin = {EC_WORD_WOULD, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_GO_HOME, EC_WORD_QUES},
                .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_SORRY, EC_WORD_FRIEND},
                .speechAfter = {EC_WORD_HAVEN_T, EC_WORD_YOU, EC_WORD_DONE, EC_WORD_ENOUGH, EC_WORD_QUES, EC_EMPTY_WORD},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_VAPOREON,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_HAZE, MOVE_HELPING_HAND, MOVE_TICKLE, MOVE_WATER_PULSE},
                        .hpEV = 250,
                        .defenseEV = 130,
                        .spDefenseEV = 130,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x37,
                    #if ENGLISH || ITALIAN
                        .nickname = _("VAPOREON"),
                    #elif FRENCH
                        .nickname = _("AQUALI"),
                    #endif
                        .friendship = 0,
                    },
                    [1] =
                    {
                        .species = SPECIES_DODRIO,
                        .heldItem = ITEM_KINGS_ROCK,
                        .moves = {MOVE_HAZE, MOVE_TRI_ATTACK, MOVE_TAUNT, MOVE_TORMENT},
                        .hpEV = 252,
                        .speedEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 1,
                        .personality = 0x8A,
                        .nickname = _("DODRIO"),
                        .friendship = 0,
                    },
                    [2] =
                    {
                        .species = SPECIES_OMASTAR,
                        .heldItem = ITEM_QUICK_CLAW,
                        .moves = {MOVE_HAZE, MOVE_HYDRO_PUMP, MOVE_TICKLE, MOVE_ATTRACT},
                        .hpEV = 250,
                        .defenseEV = 130,
                        .spDefenseEV = 130,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x14,
                    #if ENGLISH || ITALIAN
                        .nickname = _("OMASTAR"),
                    #elif FRENCH
                        .nickname = _("AMONISTAR"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [3] =
                    {
                        .species = SPECIES_LICKITUNG,
                        .heldItem = ITEM_CHESTO_BERRY,
                        .moves = {MOVE_BELLY_DRUM, MOVE_REST, MOVE_MUD_SLAP, MOVE_SWAGGER},
                        .hpEV = 250,
                        .defenseEV = 130,
                        .spDefenseEV = 130,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x8,
                    #if ENGLISH || ITALIAN
                        .nickname = _("LICKITUNG"),
                    #elif FRENCH
                        .nickname = _("EXCELANGUE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [4] =
                    {
                        .species = SPECIES_SLOWBRO,
                        .heldItem = ITEM_LEFTOVERS,
                        .moves = {MOVE_BELLY_DRUM, MOVE_MUD_SLAP, MOVE_SWAGGER, MOVE_AMNESIA},
                        .hpEV = 250,
                        .defenseEV = 130,
                        .spDefenseEV = 130,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 1,
                        .personality = 0x94,
                    #if ENGLISH || ITALIAN
                        .nickname = _("SLOWBRO"),
                    #elif FRENCH
                        .nickname = _("FLAGADOSS"),
                    #endif
                        .friendship = 0,
                    },
                    [5] =
                    {
                        .species = SPECIES_LINOONE,
                        .heldItem = ITEM_LUM_BERRY,
                        .moves = {MOVE_BELLY_DRUM, MOVE_REST, MOVE_MUD_SLAP, MOVE_SWAGGER},
                        .hpEV = 250,
                        .defenseEV = 130,
                        .spDefenseEV = 130,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 20,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x8,
                    #if ENGLISH || ITALIAN
                        .nickname = _("LINOONE"),
                    #elif FRENCH
                        .nickname = _("LINEON"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
            [1] =
            {
            #if FRENCH
                .name = _("VERONICA"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
                .speechBefore = {EC_WORD_FEELING, EC_WORD_BEAUTY, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_YET, EC_WORD_EXCL_EXCL, },
                .speechWin = {EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_AND, EC_WORD_IT_S, EC_WORD_ALL, EC_WORD_EXCL_EXCL, },
                .speechLose = {EC_WORD_I_VE, EC_WORD_ALWAYS, EC_WORD_A_LOT, EC_WORD_OF, EC_WORD_APPEAL, EC_WORD_EXCL, },
                .speechAfter = {EC_WORD_YES, EC_WORD_EXCL, EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_ANGRY, EC_WORD_EXCL, },
            #elif ITALIAN
                .name = _("VERONICA"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
                .speechBefore = {EC_WORD_ARE, EC_WORD_WEREN_T, EC_WORD_PLUS, EC_WORD_SILKY, EC_WORD_AND, EC_WORD_STRONG},
                .speechWin = {EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_WEREN_T, EC_WORD_PLUS, EC_WORD_SILKY, EC_WORD_EXCL},
                .speechLose = {EC_WORD_TODAY, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_VERY, EC_WORD_ALONE, EC_WORD_ELLIPSIS},
                .speechAfter = {EC_WORD_NOW, EC_WORD_ARE, EC_WORD_INSIDE, EC_WORD_LISTEN, EC_WORD_DON_T, EC_WORD_EXCL},
            #else //ENGLISH
                .name = _("VERONICA"),
                .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
                .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_STRONG, EC_WORD_BEAUTY, EC_WORD_AROUND, EC_WORD_HERE},
                .speechWin = {EC_WORD_I_AM, EC_WORD_STRONG, EC_WORD_THAT_S, EC_WORD_WHY, EC_WORD_EXCL, EC_EMPTY_WORD},
                .speechLose = {EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_TODAY, EC_WORD_THAT_S, EC_WORD_WHY, EC_WORD_EXCL},
                .speechAfter = {EC_WORD_WHY, EC_WORD_YES, EC_WORD_I_AM, EC_WORD_ANGRY, EC_WORD_THANK_YOU, EC_WORD_EXCL},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_SKITTY,
                        .heldItem = ITEM_FOCUS_BAND,
                        .moves = {MOVE_PSYCH_UP, MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_IRON_TAIL},
                        .attackEV = 252,
                        .speedEV = 252,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = MAX_PER_STAT_IVS,
                        .attackIV = MAX_PER_STAT_IVS,
                        .defenseIV = MAX_PER_STAT_IVS,
                        .speedIV = MAX_PER_STAT_IVS,
                        .spAttackIV = MAX_PER_STAT_IVS,
                        .spDefenseIV = MAX_PER_STAT_IVS,
                        .abilityNum = 0,
                        .personality = 0xCB,
                        .nickname = _("SKITTY"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [1] =
                    {
                        .species = SPECIES_MEDICHAM,
                        .heldItem = ITEM_QUICK_CLAW,
                        .moves = {MOVE_PSYCH_UP, MOVE_HI_JUMP_KICK, MOVE_MEGA_KICK, MOVE_ROCK_SLIDE},
                        .hpEV = 252,
                        .attackEV = 6,
                        .speedEV = 252,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0xD,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MEDICHAM"),
                    #elif FRENCH
                        .nickname = _("CHARMINA"),
                    #endif
                        .friendship = 0,
                    },
                    [2] =
                    {
                        .species = SPECIES_STANTLER,
                        .heldItem = ITEM_SHELL_BELL,
                        .moves = {MOVE_PSYCH_UP, MOVE_RETURN, MOVE_EARTHQUAKE, MOVE_SHADOW_BALL},
                        .hpEV = 252,
                        .attackEV = 252,
                        .speedEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x3,
                    #if ENGLISH || ITALIAN
                        .nickname = _("STANTLER"),
                    #elif FRENCH
                        .nickname = _("CERFROUSSE"),
                    #endif
                        .friendship = 0,
                    },
                    [3] =
                    {
                        .species = SPECIES_NIDOQUEEN,
                        .heldItem = ITEM_SALAC_BERRY,
                        .moves = {MOVE_SUPERPOWER, MOVE_BITE, MOVE_CHARM, MOVE_FLATTER},
                        .hpEV = 252,
                        .attackEV = 252,
                        .spDefenseEV = 6,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 20,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x3,
                        .nickname = _("NIDOQUEEN"),
                        .friendship = 0,
                    },
                    [4] =
                    {
                        .species = SPECIES_NINETALES,
                        .heldItem = ITEM_SALAC_BERRY,
                        .moves = {MOVE_OVERHEAT, MOVE_QUICK_ATTACK, MOVE_SPITE, MOVE_TAIL_WHIP},
                        .hpEV = 6,
                        .speedEV = 252,
                        .spAttackEV = 252,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0xD7,
                    #if ENGLISH || ITALIAN
                        .nickname = _("NINETALES"),
                    #elif FRENCH
                        .nickname = _("FEUNARD"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [5] =
                    {
                        .species = SPECIES_CHARIZARD,
                        .heldItem = ITEM_SALAC_BERRY,
                        .moves = {MOVE_OVERHEAT, MOVE_BEAT_UP, MOVE_SCARY_FACE, MOVE_GROWL},
                        .hpEV = 6,
                        .speedEV = 252,
                        .spAttackEV = 252,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x28,
                    #if ENGLISH || ITALIAN
                        .nickname = _("CHARIZARD"),
                    #elif FRENCH
                        .nickname = _("DRACAUFEU"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
        },
        .map = {
            .metatileData = INCBIN_U8("graphics/trainer_hill/maps_normal/floor_2/metatiles.bin"),
            .collisionData = INCBIN_U16("graphics/trainer_hill/maps_normal/floor_2/collision.bin"),
            .trainerCoords = {COORDS_XY(5,2), COORDS_XY(9,2)},
            .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
            .trainerRanges = TRAINER_RANGE(3, 3),
        }
    },
    [3] =
    {
        .trainerNum1 = 23,
        .trainerNum2 = 24,
        .trainers =
        {
            [0] =
            {
            #if FRENCH
                .name = _("ARTHUS"),
                .facilityClass = FACILITY_CLASS_PSYCHIC_M,
                .speechBefore = {EC_WORD_DOES, EC_EMPTY_WORD, EC_WORD_HURRIED, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                .speechWin = {EC_WORD_PLUS, EC_WORD_THE, EC_WORD_TIME, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                .speechLose = {EC_WORD_THE, EC_WORD_TIME, EC_WORD_IT_S, EC_WORD_OF, EC_WORD_MISS, EC_WORD_SILVER, },
                .speechAfter = {EC_WORD_NOT, EC_WORD_THE, EC_WORD_TIME, EC_WORD_OF, EC_WORD_CHAT, EC_WORD_EXCL_EXCL, },
            #elif ITALIAN
                .name = _("CAMILLO"),
                .facilityClass = FACILITY_CLASS_PSYCHIC_M,
                .speechBefore = {EC_WORD_WILL, EC_WORD_A_TINY_BIT, EC_WORD_BEGINNING, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechWin = {EC_WORD_ONLY, EC_WORD_IT, EC_WORD_BEGINNING, EC_WORD_LISTEN, EC_WORD_IF_I_LOSE, EC_WORD_EXCL},
                .speechLose = {EC_WORD_ONLY, EC_WORD_IT, EC_WORD_BEGINNING, EC_WORD_LISTEN, EC_WORD_IF_I_WIN, EC_WORD_EXCL},
                .speechAfter = {EC_WORD_WILL, EC_WORD_BEGINNING, EC_WORD_NITWIT, EC_WORD_TO, EC_WORD_WORD, EC_WORD_QUES},
            #else //ENGLISH
                .name = _("KEENAN"),
                .facilityClass = FACILITY_CLASS_PSYCHIC_M,
                .speechBefore = {EC_WORD_YOU, EC_WORD_LOOK, EC_WORD_SO, EC_WORD_HURRIED, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechWin = {EC_WORD_TOO, EC_WORD_BAD, EC_EMPTY_WORD, EC_WORD_TIME, EC_WORD_IS, EC_WORD_UP},
                .speechLose = {EC_WORD_DOES, EC_WORD_THE, EC_WORD_TIME, EC_WORD_WORRY, EC_WORD_YOU, EC_WORD_QUES},
                .speechAfter = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_HAVE, EC_WORD_TIME, EC_WORD_TO, EC_WORD_CHAT},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_ALAKAZAM,
                        .heldItem = ITEM_PETAYA_BERRY,
                        .moves = {MOVE_SKILL_SWAP, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH, MOVE_REFLECT},
                        .speedEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x41,
                        .nickname = _("ALAKAZAM"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [1] =
                    {
                        .species = SPECIES_BLISSEY,
                        .heldItem = ITEM_LEFTOVERS,
                        .moves = {MOVE_SKILL_SWAP, MOVE_EGG_BOMB, MOVE_THUNDERBOLT, MOVE_SING},
                        .defenseEV = 255,
                        .spAttackEV = 155,
                        .spDefenseEV = 100,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 1,
                        .personality = 0xF,
                    #if ENGLISH || ITALIAN
                        .nickname = _("BLISSEY"),
                    #elif FRENCH
                        .nickname = _("LEUPHORIE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [2] =
                    {
                        .species = SPECIES_GRUMPIG,
                        .heldItem = ITEM_TWISTED_SPOON,
                        .moves = {MOVE_SKILL_SWAP, MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_REST},
                        .hpEV = 110,
                        .defenseEV = 200,
                        .spAttackEV = 200,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x8C,
                    #if ENGLISH || ITALIAN
                        .nickname = _("GRUMPIG"),
                    #elif FRENCH
                        .nickname = _("GRORET"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [3] =
                    {
                        .species = SPECIES_GARDEVOIR,
                        .heldItem = ITEM_SALAC_BERRY,
                        .moves = {MOVE_SKILL_SWAP, MOVE_DREAM_EATER, MOVE_HYPNOSIS, MOVE_PROTECT},
                        .speedEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 1,
                        .personality = 0xF,
                        .nickname = _("GARDEVOIR"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [4] =
                    {
                        .species = SPECIES_VENOMOTH,
                        .heldItem = ITEM_BRIGHT_POWDER,
                        .moves = {MOVE_SKILL_SWAP, MOVE_SIGNAL_BEAM, MOVE_SLEEP_POWDER, MOVE_TOXIC},
                        .attackEV = 255,
                        .speedEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0x80,
                    #if ENGLISH || ITALIAN
                        .nickname = _("VENOMOTH"),
                    #elif FRENCH
                        .nickname = _("AEROMITE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [5] =
                    {
                        .species = SPECIES_ESPEON,
                        .heldItem = ITEM_LUM_BERRY,
                        .moves = {MOVE_SKILL_SWAP, MOVE_PSYBEAM, MOVE_SWIFT, MOVE_ATTRACT},
                        .speedEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 5,
                        .attackIV = 5,
                        .defenseIV = 5,
                        .speedIV = 5,
                        .spAttackIV = 5,
                        .spDefenseIV = 5,
                        .abilityNum = 0,
                        .personality = 0xF,
                    #if ENGLISH || ITALIAN
                        .nickname = _("ESPEON"),
                    #elif FRENCH
                        .nickname = _("MENTALI"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
            [1] =
            {
            #if FRENCH
                .name = _("KRISTINA"),
                .facilityClass = FACILITY_CLASS_AROMA_LADY,
                .speechBefore = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, EC_WORD_WHERE, EC_EMPTY_WORD, EC_WORD_STENCH, EC_WORD_EXCL, },
                .speechWin = {EC_WORD_ADORE, EC_WORD_FEELING, EC_WORD_LET_ME_WIN, EC_WORD_OF, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_AWAY, },
                .speechLose = {EC_WORD_SOMEONE, EC_MOVE2(COVET), EC_WORD_FEELING, EC_MOVE(FOCUS_ENERGY), EC_EMPTY_WORD, EC_EMPTY_WORD, },
                .speechAfter = {EC_WORD_WILL, EC_WORD_VERY, EC_WORD_EXCUSE, EC_WORD_ELLIPSIS, EC_WORD_THANKS, EC_EMPTY_WORD, },
            #elif ITALIAN
                .name = _("CRISTIANA"),
                .facilityClass = FACILITY_CLASS_AROMA_LADY,
                .speechBefore = {EC_WORD_MISS, EC_WORD_STENCH, EC_WORD_UNDERSTOOD, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                .speechWin = {EC_WORD_IT, EC_WORD_STENCH, EC_WORD_THAT_S, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_ELLIPSIS},
                .speechLose = {EC_WORD_LOWS, EC_WORD_IT, EC_WORD_STENCH, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_THOSE_WERE},
                .speechAfter = {EC_WORD_IT, EC_WORD_STENCH, EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_NOT_VERY, EC_MOVE(SWEET_SCENT)},
            #else //ENGLISH
                .name = _("KRISTINA"),
                .facilityClass = FACILITY_CLASS_AROMA_LADY,
                .speechBefore = {EC_WORD_IT_S, EC_WORD_HOT, EC_WORD_ELLIPSIS, EC_WORD_WHAT, EC_WORD_A, EC_WORD_STENCH},
                .speechWin = {EC_WORD_I, EC_WORD_REALLY, EC_WORD_LIKE, EC_WORD_AN, EC_WORD_OFFENSIVE, EC_WORD_STENCH},
                .speechLose = {EC_WORD_I, EC_MOVE2(COVET), EC_WORD_ANY, EC_WORD_STRONG, EC_WORD_STENCH, EC_EMPTY_WORD},
                .speechAfter = {EC_WORD_MY, EC_WORD_SENSE, EC_WORD_OF, EC_WORD_SMELL, EC_WORD_ISN_T, EC_WORD_NORMAL},
            #endif
                .mons =
                {
                    [0] =
                    {
                        .species = SPECIES_WEEZING,
                        .heldItem = ITEM_POISON_BARB,
                        .moves = {MOVE_TOXIC, MOVE_SLUDGE_BOMB, MOVE_SMOKESCREEN, MOVE_HAZE},
                        .hpEV = 255,
                        .attackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x3,
                    #if ENGLISH || ITALIAN
                        .nickname = _("WEEZING"),
                    #elif FRENCH
                        .nickname = _("SMOGOGO"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [1] =
                    {
                        .species = SPECIES_GLOOM,
                        .heldItem = ITEM_MIRACLE_SEED,
                        .moves = {MOVE_PETAL_DANCE, MOVE_SYNTHESIS, MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM},
                        .speedEV = 255,
                        .spAttackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x8C,
                    #if ENGLISH || ITALIAN
                        .nickname = _("GLOOM"),
                    #elif FRENCH
                        .nickname = _("ORTIDE"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [2] =
                    {
                        .species = SPECIES_MUK,
                        .heldItem = ITEM_BRIGHT_POWDER,
                        .moves = {MOVE_SCREECH, MOVE_DISABLE, MOVE_SLUDGE_BOMB, MOVE_ACID_ARMOR},
                        .hpEV = 255,
                        .attackEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x3,
                    #if ENGLISH || ITALIAN
                        .nickname = _("MUK"),
                    #elif FRENCH
                        .nickname = _("GROTADMORV"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [3] =
                    {
                        .species = SPECIES_TROPIUS,
                        .heldItem = ITEM_WHITE_HERB,
                        .moves = {MOVE_SUNNY_DAY, MOVE_SOLAR_BEAM, MOVE_SWEET_SCENT, MOVE_AERIAL_ACE},
                        .attackEV = 120,
                        .speedEV = 255,
                        .spAttackEV = 135,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x83,
                        .nickname = _("TROPIUS"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [4] =
                    {
                        .species = SPECIES_BELLOSSOM,
                        .heldItem = ITEM_MENTAL_HERB,
                        .moves = {MOVE_SWEET_SCENT, MOVE_PETAL_DANCE, MOVE_STUN_SPORE, MOVE_SLUDGE_BOMB},
                        .hpEV = 255,
                        .speedEV = 255,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x6,
                    #if ENGLISH || ITALIAN
                        .nickname = _("BELLOSSOM"),
                    #elif FRENCH
                        .nickname = _("JOLIFLOR"),
                    #endif
                        .friendship = MAX_FRIENDSHIP,
                    },
                    [5] =
                    {
                        .species = SPECIES_MEGANIUM,
                        .heldItem = ITEM_MIRACLE_SEED,
                        .moves = {MOVE_RAZOR_LEAF, MOVE_BODY_SLAM, MOVE_LEECH_SEED, MOVE_SYNTHESIS},
                        .attackEV = 200,
                        .speedEV = 110,
                        .spAttackEV = 200,
                        .otId = TRAINER_HILL_OTID,
                        .hpIV = 15,
                        .attackIV = 15,
                        .defenseIV = 15,
                        .speedIV = 15,
                        .spAttackIV = 15,
                        .spDefenseIV = 15,
                        .abilityNum = 0,
                        .personality = 0x1F,
                        .nickname = _("MEGANIUM"),
                        .friendship = MAX_FRIENDSHIP,
                    },
                },
            },
        },
        .map = {
            .metatileData = INCBIN_U8("graphics/trainer_hill/maps_normal/floor_3/metatiles.bin"),
            .collisionData = INCBIN_U16("graphics/trainer_hill/maps_normal/floor_3/collision.bin"),
            .trainerCoords = {COORDS_XY(7,4), COORDS_XY(7,10)},
            .trainerDirections = TRAINER_DIRS(DIR_SOUTH, DIR_NORTH),
            .trainerRanges = TRAINER_RANGE(3, 3),
        }
    },
};

static const struct TrainerHillChallenge sChallenge_Variety =
{
    .numTrainers = NUM_TRAINER_HILL_TRAINERS,
    .unused1 = 1,
    .numFloors = NUM_TRAINER_HILL_FLOORS,
    .checksum = 0x00054C15
};

static const struct TrainerHillFloor sFloors_Variety[] = {
    [0] =
        {
            .trainerNum1 = 41,
            .trainerNum2 = 42,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("ANSELME"),
                            .facilityClass = FACILITY_CLASS_GENTLEMAN,
                            .speechBefore = {EC_WORD_IT, EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechWin = {EC_WORD_DAUGHTER, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_YOURS, EC_MOVE2(PRESENT), EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_THAT_WAS, EC_WORD_MY, EC_MOVE2(PRESENT), EC_WORD_FOR, EC_WORD_HIM, EC_EMPTY_WORD, },
                            .speechAfter = {EC_WORD_WELL_THEN, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_EXCUSE, EC_WORD_ELLIPSIS, },
                        #elif ITALIAN
                            .name = _("VINICIO"),
                            .facilityClass = FACILITY_CLASS_GENTLEMAN,
                            .speechBefore = {EC_WORD_WONDER, EC_WORD_IS, EC_WORD_GOOD, EC_WORD_WINS, EC_WORD_A, EC_MOVE2(PRESENT)},
                            .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_IT, EC_MOVE2(PRESENT)},
                            .speechLose = {EC_WORD_IS, EC_WORD_PERFECT, EC_WORD_ON, EC_WORD_IT, EC_WORD_WITH, EC_MOVE2(PRESENT)},
                            .speechAfter = {EC_WORD_WHICH, EC_WORD_GIVE, EC_WORD_ALL, EC_WORD_TOO, EC_WORD_CONGRATS, EC_WORD_EXCL},
                        #else //ENGLISH
                            .name = _("TERRANCE"),
                            .facilityClass = FACILITY_CLASS_GENTLEMAN,
                            .speechBefore = {EC_WORD_GOOD, EC_WORD_CHILDREN, EC_WORD_WILL, EC_WORD_GET, EC_WORD_A, EC_MOVE2(PRESENT)},
                            .speechWin = {EC_WORD_THANK_YOU, EC_WORD_MY, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_YOUR, EC_MOVE2(PRESENT)},
                            .speechLose = {EC_WORD_THAT_WAS, EC_WORD_MY, EC_MOVE2(PRESENT), EC_WORD_TO, EC_WORD_YOU, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_WELL_THEN, EC_WORD_CONGRATS, EC_WORD_MY, EC_WORD_FRIEND, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_DELIBIRD,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_PRESENT, MOVE_SPLASH, MOVE_HAIL, MOVE_PROTECT},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x8A,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("DELIBIRD"),
                                        #elif FRENCH
                                            .nickname = _("CADOIZO"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_CLEFAIRY,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_PRESENT, MOVE_COSMIC_POWER, MOVE_LIGHT_SCREEN, MOVE_MOONLIGHT},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CLEFAIRY"),
                                        #elif FRENCH
                                            .nickname = _("MELOFEE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_PIKACHU,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_PRESENT, MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_AGILITY},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xD,
                                            .nickname = _("PIKACHU"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_MARILL,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_PRESENT, MOVE_DEFENSE_CURL, MOVE_TAIL_WHIP, MOVE_ENDURE},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x8A,
                                            .nickname = _("MARILL"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_JIGGLYPUFF,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_PRESENT, MOVE_SING, MOVE_DISABLE, MOVE_REST},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("JIGGLYPUFF"),
                                        #elif FRENCH
                                            .nickname = _("RONDOUDOU"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_TOGETIC,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_PRESENT, MOVE_CHARM, MOVE_SWEET_KISS, MOVE_WISH},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x26,
                                            .nickname = _("TOGETIC"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("ELIZABETH"),
                            .facilityClass = FACILITY_CLASS_LADY,
                            .speechBefore = {EC_WORD_YOU, EC_WORD_SENSE, EC_WORD_DAUGHTER, EC_EMPTY_WORD, EC_MOVE(FOCUS_ENERGY), EC_WORD_QUES, },
                            .speechWin = {EC_WORD_IT_S, EC_WORD_PERFECT, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_YOU_VE, EC_WORD_FEELING, EC_WORD_ROUGH_SKIN, EC_EMPTY_WORD, EC_WORD_IT_S, EC_WORD_EXCUSE, },
                            .speechAfter = {EC_WORD_NOW, EC_WORD_I_AM, EC_WORD_SAD, EC_WORD_AND, EC_WORD_IN, EC_WORD_CRIES, },
                        #elif ITALIAN
                            .name = _("ALBA"),
                            .facilityClass = FACILITY_CLASS_LADY,
                            .speechBefore = {EC_WORD_LEARN, EC_WORD_MAKING, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_POWER, EC_WORD_QUES},
                            .speechWin = {EC_WORD_MISS, EC_WORD_SHINE, EC_WORD_HEH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_AS_IF, EC_WORD_ALWAYS, EC_WORD_STORES, EC_WORD_HERE, EC_WORD_THOSE_ARE, EC_WORD_ELLIPSIS},
                            .speechAfter = {EC_WORD_NOW, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_SAD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #else //ENGLISH
                            .name = _("ELIZABETH"),
                            .facilityClass = FACILITY_CLASS_LADY,
                            .speechBefore = {EC_WORD_CAN, EC_WORD_YOU, EC_WORD_SENSE, EC_WORD_ME, EC_MOVE(FOCUS_ENERGY), EC_WORD_QUES},
                            .speechWin = {EC_WORD_THAT_S, EC_WORD_ABOUT, EC_WORD_RIGHT, EC_WORD_I, EC_WORD_WOULD, EC_WORD_THINK},
                            .speechLose = {EC_WORD_THINGS, EC_WORD_DON_T, EC_WORD_ALWAYS, EC_WORD_WORK, EC_WORD_OUT, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_LONESOME, EC_WORD_AND, EC_WORD_SAD, EC_WORD_NOW},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_WIGGLYTUFF,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_ROLLOUT, MOVE_DEFENSE_CURL, MOVE_SING, MOVE_DREAM_EATER},
                                            .hpEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xC1,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("WIGGLYTUFF"),
                                        #elif FRENCH
                                            .nickname = _("GRODOUDOU"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_SABLEYE,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_ASTONISH, MOVE_FAINT_ATTACK, MOVE_DETECT, MOVE_CONFUSE_RAY},
                                            .hpEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x87,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SABLEYE"),
                                        #elif FRENCH
                                            .nickname = _("TENEFIX"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_GRUMPIG,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_PSYBEAM, MOVE_MAGIC_COAT, MOVE_BOUNCE, MOVE_FUTURE_SIGHT},
                                            .hpEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("GRUMPIG"),
                                        #elif FRENCH
                                            .nickname = _("GRORET"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_CORSOLA,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_BUBBLE_BEAM, MOVE_ROCK_BLAST, MOVE_REFLECT, MOVE_LIGHT_SCREEN},
                                            .hpEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x12,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CORSOLA"),
                                        #elif FRENCH
                                            .nickname = _("CORAYON"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_CLAMPERL,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_WHIRLPOOL, MOVE_IRON_DEFENSE, MOVE_ENDURE, MOVE_CONFUSE_RAY},
                                            .hpEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CLAMPERL"),
                                        #elif FRENCH
                                            .nickname = _("COQUIPERL"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_STARMIE,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_DIVE, MOVE_ICY_WIND, MOVE_SWIFT, MOVE_SKILL_SWAP},
                                            .hpEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("STARMIE"),
                                        #elif FRENCH
                                            .nickname = _("STAROSS"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_variety/floor_0/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_variety/floor_0/collision.bin"),
                .trainerCoords = {COORDS_XY(5,8), COORDS_XY(9,8)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(3, 3),
            }
        },
    [1] =
        {
            .trainerNum1 = 43,
            .trainerNum2 = 44,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("ANNABEL"),
                            .facilityClass = FACILITY_CLASS_PARASOL_LADY,
                            .speechBefore = {EC_WORD_YOU, EC_WORD_SIBLINGS, EC_WORD_SENSE, EC_EMPTY_WORD, EC_WORD_WEIRD, EC_WORD_QUES, },
                            .speechWin = {EC_WORD_NO, EC_WORD_QUES, EC_WORD_REALLY, EC_WORD_QUES, EC_WORD_OKAY, EC_WORD_ELLIPSIS, },
                            .speechLose = {EC_WORD_NOW, EC_WORD_YOU, EC_WORD_SIBLINGS, EC_WORD_SENSE, EC_WORD_EXCUSE, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_YOURS, EC_WORD_POKEMON, EC_WORD_IS, EC_WORD_READY, EC_WORD_EVEN_SO, EC_WORD_FIGHT, },
                        #elif ITALIAN
                            .name = _("ANNARITA"),
                            .facilityClass = FACILITY_CLASS_PARASOL_LADY,
                            .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_ALONE, EC_WORD_NITWIT, EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_QUES},
                            .speechWin = {EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_ALONE, EC_WORD_TODAY, EC_WORD_HEH, EC_WORD_QUES},
                            .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_PERFECT, EC_WORD_ALONE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_ALONE},
                        #else //ENGLISH
                            .name = _("ANNABELL"),
                            .facilityClass = FACILITY_CLASS_PARASOL_LADY,
                            .speechBefore = {EC_WORD_HI, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_FEELING, EC_WORD_UPBEAT, EC_WORD_QUES},
                            .speechWin = {EC_WORD_AREN_T, EC_WORD_YOU, EC_WORD_FEELING, EC_WORD_WELL, EC_WORD_QUES, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_I, EC_WORD_CAN, EC_WORD_SEE, EC_WORD_YOU_RE, EC_WORD_FEELING, EC_WORD_GREAT},
                            .speechAfter = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_LOOK, EC_WORD_READY, EC_WORD_TO, EC_WORD_HUSTLE},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_JIGGLYPUFF,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_SING, MOVE_HYPER_VOICE, MOVE_ATTRACT, MOVE_NONE},
                                            .hpEV = 85,
                                            .attackEV = 85,
                                            .defenseEV = 85,
                                            .speedEV = 85,
                                            .spAttackEV = 85,
                                            .spDefenseEV = 85,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("JIGGLYPUFF"),
                                        #elif FRENCH
                                            .nickname = _("RONDOUDOU"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_JYNX,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_PERISH_SONG, MOVE_FAKE_TEARS, MOVE_ATTRACT, MOVE_NONE},
                                            .hpEV = 85,
                                            .attackEV = 85,
                                            .defenseEV = 85,
                                            .speedEV = 85,
                                            .spAttackEV = 85,
                                            .spDefenseEV = 85,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("JYNX"),
                                        #elif FRENCH
                                            .nickname = _("LIPPOUTOU"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_EXPLOUD,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_HOWL, MOVE_HYPER_VOICE, MOVE_ATTRACT, MOVE_NONE},
                                            .hpEV = 85,
                                            .attackEV = 85,
                                            .defenseEV = 85,
                                            .speedEV = 85,
                                            .spAttackEV = 85,
                                            .spDefenseEV = 85,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x96,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("EXPLOUD"),
                                        #elif FRENCH
                                            .nickname = _("BROUHABAM"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_ABSOL,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_SWORDS_DANCE, MOVE_SLASH, MOVE_ATTRACT, MOVE_NONE},
                                            .hpEV = 85,
                                            .attackEV = 85,
                                            .defenseEV = 85,
                                            .speedEV = 85,
                                            .spAttackEV = 85,
                                            .spDefenseEV = 85,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x96,
                                            .nickname = _("ABSOL"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_PIDGEOTTO,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_FEATHER_DANCE, MOVE_AERIAL_ACE, MOVE_ATTRACT, MOVE_NONE},
                                            .hpEV = 85,
                                            .attackEV = 85,
                                            .defenseEV = 85,
                                            .speedEV = 85,
                                            .spAttackEV = 85,
                                            .spDefenseEV = 85,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x96,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("PIDGEOTTO"),
                                        #elif FRENCH
                                            .nickname = _("ROUCOUPS"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_ALTARIA,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_DRAGON_DANCE, MOVE_AERIAL_ACE, MOVE_ATTRACT, MOVE_NONE},
                                            .hpEV = 85,
                                            .attackEV = 85,
                                            .defenseEV = 85,
                                            .speedEV = 85,
                                            .spAttackEV = 85,
                                            .spDefenseEV = 85,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                            .nickname = _("ALTARIA"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("ARNAUD"),
                            .facilityClass = FACILITY_CLASS_COLLECTOR,
                            .speechBefore = {EC_WORD_I, EC_WORD_SEEK, EC_WORD_AN, EC_EMPTY_WORD, EC_WORD_IDOL, EC_WORD_ELLIPSIS, },
                            .speechWin = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_LACKING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechLose = {EC_WORD_WHAT, EC_WORD_IS, EC_WORD_YOURS, EC_EMPTY_WORD, EC_WORD_SECRET, EC_WORD_QUES, },
                            .speechAfter = {EC_WORD_LIKELY_TO, EC_WORD_NOW, EC_WORD_BE, EC_WORD_DAUGHTER, EC_WORD_IDOL, EC_WORD_EXCL, },
                        #elif ITALIAN
                            .name = _("ROSALINO"),
                            .facilityClass = FACILITY_CLASS_COLLECTOR,
                            .speechBefore = {EC_WORD_WHOM, EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_A, EC_WORD_IDOL, EC_WORD_ELLIPSIS},
                            .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_NITWIT, EC_WORD_IT, EC_WORD_WITH, EC_WORD_IDOL},
                            .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_LAY, EC_WORD_DO, EC_WORD_AS_IF, EC_WORD_SORRY, EC_WORD_ELLIPSIS},
                            .speechAfter = {EC_WORD_WILL_BE_HERE, EC_WORD_LET_S, EC_WORD_IT, EC_WORD_WITH, EC_WORD_IDOL, EC_WORD_QUES},
                        #else //ENGLISH
                            .name = _("COLEMAN"),
                            .facilityClass = FACILITY_CLASS_COLLECTOR,
                            .speechBefore = {EC_WORD_I, EC_WORD_SEEK, EC_WORD_SOMEONE, EC_WORD_AS, EC_WORD_MY, EC_WORD_IDOL},
                            .speechWin = {EC_WORD_DID, EC_WORD_MY, EC_WORD_IDOL, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_QUES},
                            .speechLose = {EC_WORD_YOU_RE, EC_WORD_LIKE, EC_WORD_A, EC_MOVE(HEAL_BELL), EC_WORD_TO_ME, EC_WORD_EXCL},
                            .speechAfter = {EC_WORD_I_VE, EC_WORD_DECIDED, EC_WORD_I_CHOOSE_YOU, EC_WORD_AS, EC_WORD_MY, EC_WORD_IDOL},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_CHIMECHO,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_UPROAR, MOVE_ATTRACT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CHIMECHO"),
                                        #elif FRENCH
                                            .nickname = _("EOKO"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_WHISMUR,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_UPROAR, MOVE_ATTRACT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("WHISMUR"),
                                        #elif FRENCH
                                            .nickname = _("CHUCHMUR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_YANMA,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_UPROAR, MOVE_ATTRACT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x8A,
                                            .nickname = _("YANMA"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_ILLUMISE,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_ENCORE, MOVE_ATTRACT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .defenseEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("ILLUMISE"),
                                        #elif FRENCH
                                            .nickname = _("LUMIVOLE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_SPHEAL,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_ENCORE, MOVE_ATTRACT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SPHEAL"),
                                        #elif FRENCH
                                            .nickname = _("OBALIE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_VIGOROTH,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_ENCORE, MOVE_ATTRACT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .defenseEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x87,
                                            .nickname = _("VIGOROTH"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_variety/floor_1/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_variety/floor_1/collision.bin"),
                .trainerCoords = {COORDS_XY(3,8), COORDS_XY(11,8)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(7, 7),
            }
        },
    [2] =
        {
            .trainerNum1 = 45,
            .trainerNum2 = 46,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("ADEMAR"),
                            .facilityClass = FACILITY_CLASS_RICH_BOY,
                            .speechBefore = {EC_WORD_THE, EC_WORD_TIME, EC_WORD_BELONGS_TO, EC_WORD_BE, EC_WORD_AWESOME, EC_WORD_EXCL_EXCL, },
                            .speechWin = {EC_WORD_EHEHE, EC_EMPTY_WORD, EC_WORD_WHAT_S_UP_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechLose = {EC_WORD_HUH_QUES, EC_WORD_WHY, EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_WINS, EC_WORD_QUES, },
                            .speechAfter = {EC_WORD_YOU, EC_WORD_KNOWS, EC_WORD_MY, EC_WORD_SKILL, EC_WORD_NO, EC_WORD_QUES, },
                        #elif ITALIAN
                            .name = _("ENRIQUE"),
                            .facilityClass = FACILITY_CLASS_RICH_BOY,
                            .speechBefore = {EC_WORD_HEARING, EC_WORD_IS, EC_WORD_LOWS, EC_WORD_AS, EC_WORD_NICE, EC_WORD_EXCL},
                            .speechWin = {EC_WORD_UNBELIEVABLE, EC_WORD_WILL, EC_WORD_LOST, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_WILL, EC_WORD_SAYS, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
                            .speechAfter = {EC_WORD_AGREE, EC_WORD_IS_IT_QUES, EC_WORD_COOLNESS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #else //ENGLISH
                            .name = _("ENRIQUE"),
                            .facilityClass = FACILITY_CLASS_RICH_BOY,
                            .speechBefore = {EC_WORD_GET, EC_WORD_READY, EC_WORD_FOR, EC_WORD_AN, EC_WORD_AWESOME, EC_WORD_TIME},
                            .speechWin = {EC_WORD_HEY, EC_WORD_HEY, EC_WORD_EXCL, EC_WORD_WHAT_S_UP_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_AWW, EC_WORD_COULDN_T, EC_WORD_YOU, EC_WORD_LET_ME_WIN, EC_WORD_QUES, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_DID, EC_WORD_YOU, EC_WORD_SEE, EC_WORD_MY, EC_WORD_SKILL, EC_WORD_QUES},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_WOOPER,
                                            .heldItem = ITEM_FIGY_BERRY,
                                            .moves = {MOVE_RAIN_DANCE, MOVE_YAWN, MOVE_SURF, MOVE_HAZE},
                                            .hpEV = 252,
                                            .speedEV = 6,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x8C,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("WOOPER"),
                                        #elif FRENCH
                                            .nickname = _("AXOLOTO"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_POLIWAG,
                                            .heldItem = ITEM_WIKI_BERRY,
                                            .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_MIST, MOVE_HYPNOSIS},
                                            .hpEV = 252,
                                            .speedEV = 6,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("POLIWAG"),
                                        #elif FRENCH
                                            .nickname = _("PTITARD"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_PSYDUCK,
                                            .heldItem = ITEM_AGUAV_BERRY,
                                            .moves = {MOVE_HYPNOSIS, MOVE_SURF, MOVE_DISABLE, MOVE_SEISMIC_TOSS},
                                            .hpEV = 250,
                                            .defenseEV = 130,
                                            .spDefenseEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("PSYDUCK"),
                                        #elif FRENCH
                                            .nickname = _("PSYKOKWAK"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_RHYDON,
                                            .heldItem = ITEM_SOFT_SAND,
                                            .moves = {MOVE_EARTHQUAKE, MOVE_MAGNITUDE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .speedEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x96,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("RHYDON"),
                                        #elif FRENCH
                                            .nickname = _("RHINOFEROS"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_RHYHORN,
                                            .heldItem = ITEM_SOFT_SAND,
                                            .moves = {MOVE_EARTHQUAKE, MOVE_MAGNITUDE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("RHYHORN"),
                                        #elif FRENCH
                                            .nickname = _("RHINOCORNE"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_CUBONE,
                                            .heldItem = ITEM_SOFT_SAND,
                                            .moves = {MOVE_EARTHQUAKE, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CUBONE"),
                                        #elif FRENCH
                                            .nickname = _("OSSELAIT"),
                                        #endif
                                            .friendship = 0,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("LUCETTE"),
                            .facilityClass = FACILITY_CLASS_LADY,
                            .speechBefore = {EC_WORD_LIKELY_TO, EC_WORD_BE, EC_WORD_SHREDDED, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechWin = {EC_WORD_TAKE_THAT, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechLose = {EC_WORD_GO_AHEAD, EC_WORD_EXCL, EC_WORD_IGNORANT, EC_WORD_MY, EC_WORD_DREAM, EC_WORD_ELLIPSIS, },
                            .speechAfter = {EC_WORD_SOMETIME, EC_EMPTY_WORD, EC_WORD_WANT, EC_WORD_BE, EC_WORD_WILD, EC_WORD_EXCL, },
                        #elif ITALIAN
                            .name = _("VIOLETTA"),
                            .facilityClass = FACILITY_CLASS_LADY,
                            .speechBefore = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_WEREN_T, EC_WORD_MUSIC, EC_WORD_ANIME, EC_WORD_ELLIPSIS},
                            .speechWin = {EC_WORD_IT, EC_WORD_ANIME, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_WIN, EC_WORD_EXCL},
                            .speechLose = {EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_END, EC_WORD_NOT_VERY, EC_WORD_WITH, EC_WORD_DREAM},
                            .speechAfter = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_IT, EC_WORD_ANIME, EC_WORD_EXCL},
                        #else //ENGLISH
                            .name = _("COLLEEN"),
                            .facilityClass = FACILITY_CLASS_LADY,
                            .speechBefore = {EC_WORD_I, EC_WORD_WOULD, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_ROCK, EC_WORD_OUT},
                            .speechWin = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_THIS, EC_WORD_ROCK, EC_WORD_THING, EC_WORD_EXCL},
                            .speechLose = {EC_WORD_GO_AHEAD, EC_WORD_AND, EC_WORD_CRUSH, EC_WORD_MY, EC_WORD_DREAM, EC_WORD_ELLIPSIS},
                            .speechAfter = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_GO, EC_WORD_WILD, EC_WORD_SOMETIME},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_MAGNEMITE,
                                            .heldItem = ITEM_MAGNET,
                                            .moves = {MOVE_THUNDER, MOVE_ZAP_CANNON, MOVE_SPARK, MOVE_THUNDER_SHOCK},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x8C,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MAGNEMITE"),
                                        #elif FRENCH
                                            .nickname = _("MAGNETI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_ELECTABUZZ,
                                            .heldItem = ITEM_MAGNET,
                                            .moves = {MOVE_THUNDER, MOVE_THUNDERBOLT, MOVE_THUNDER_PUNCH, MOVE_SHOCK_WAVE},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x41,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("ELECTABUZZ"),
                                        #elif FRENCH
                                            .nickname = _("ELEKTEK"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_FLAAFFY,
                                            .heldItem = ITEM_MAGNET,
                                            .moves = {MOVE_THUNDER, MOVE_THUNDERBOLT, MOVE_SHOCK_WAVE, MOVE_THUNDER_SHOCK},
                                            .hpEV = 250,
                                            .spAttackEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("FLAAFFY"),
                                        #elif FRENCH
                                            .nickname = _("LAINERGIE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_BALTOY,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_EXPLOSION, MOVE_SELF_DESTRUCT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("BALTOY"),
                                        #elif FRENCH
                                            .nickname = _("BALBUTO"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_PINECO,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_EXPLOSION, MOVE_SELF_DESTRUCT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .speedEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("PINECO"),
                                        #elif FRENCH
                                            .nickname = _("POMDEPIK"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_VOLTORB,
                                            .heldItem = ITEM_SILK_SCARF,
                                            .moves = {MOVE_EXPLOSION, MOVE_SELF_DESTRUCT, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("VOLTORB"),
                                        #elif FRENCH
                                            .nickname = _("VOLTORBE"),
                                        #endif
                                            .friendship = 0,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_variety/floor_2/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_variety/floor_2/collision.bin"),
                .trainerCoords = {COORDS_XY(9,1), COORDS_XY(14,1)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(4, 4),
            }
        },
    [3] =
        {
            .trainerNum1 = 47,
            .trainerNum2 = 48,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("KIMBERLY"),
                            .facilityClass = FACILITY_CLASS_POKEFAN_F,
                            .speechBefore = {EC_WORD_LIKE, EC_WORD_WORKING, EC_WORD_NEARLY, EC_WORD_MY, EC_WORD_OWN_TEMPO, EC_WORD_EXCL, },
                            .speechWin = {EC_WORD_FINALLY, EC_WORD_ELLIPSIS, EC_WORD_YOU_VE, EC_WORD_ELLIPSIS, EC_WORD_LOST, EC_WORD_EXCL_EXCL, },
                            .speechLose = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_MEAN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechAfter = {EC_WORD_MY, EC_WORD_OWN_TEMPO, EC_WORD_IS, EC_WORD_EXCUSE, EC_WORD_FOR, EC_WORD_ME, },
                        #elif ITALIAN
                            .name = _("KIMBERLY"),
                            .facilityClass = FACILITY_CLASS_POKEFAN_F,
                            .speechBefore = {EC_WORD_IT, EC_WORD_WORK, EC_WORD_SHOW, EC_WORD_CONCEDE, EC_WORD_ENTERTAINING, EC_WORD_ELLIPSIS},
                            .speechWin = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_JUST, EC_WORD_THOSE_WERE, EC_WORD_NO, EC_WORD_QUES},
                            .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_LOWS, EC_WORD_WANDERING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_WORK, EC_WORD_SOMETIME, EC_WORD_IS, EC_WORD_ENTERTAINING},
                        #else //ENGLISH
                            .name = _("KIMBERLY"),
                            .facilityClass = FACILITY_CLASS_POKEFAN_F,
                            .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_WORKING, EC_WORD_AT, EC_WORD_MY, EC_WORD_OWN_TEMPO},
                            .speechWin = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_BAD, EC_WORD_YOU, EC_WORD_THINK, EC_WORD_QUES},
                            .speechLose = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_MEAN, EC_WORD_KID, EC_WORD_IT, EC_WORD_SEEMS},
                            .speechAfter = {EC_WORD_MY, EC_WORD_OWN_TEMPO, EC_WORD_IS, EC_WORD_RIGHT, EC_WORD_FOR, EC_WORD_ME},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_UNOWN,
                                            .heldItem = ITEM_MIRACLE_SEED,
                                            .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 30,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = 30,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = 30,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x202,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("UNOWN"),
                                        #elif FRENCH
                                            .nickname = _("ZARBI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_UNOWN,
                                            .heldItem = ITEM_MYSTIC_WATER,
                                            .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 30,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = 30,
                                            .spAttackIV = 30,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x10001,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("UNOWN"),
                                        #elif FRENCH
                                            .nickname = _("ZARBI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_UNOWN,
                                            .heldItem = ITEM_BLACK_BELT,
                                            .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 30,
                                            .attackIV = 30,
                                            .defenseIV = 30,
                                            .speedIV = 30,
                                            .spAttackIV = 30,
                                            .spDefenseIV = 30,
                                            .abilityNum = 0,
                                            .personality = 0x102,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("UNOWN"),
                                        #elif FRENCH
                                            .nickname = _("ZARBI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_SPINDA,
                                            .heldItem = ITEM_LUM_BERRY,
                                            .moves = {MOVE_TEETER_DANCE, MOVE_DIZZY_PUNCH, MOVE_CALM_MIND, MOVE_BATON_PASS},
                                            .hpEV = 110,
                                            .defenseEV = 200,
                                            .spDefenseEV = 200,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x88FE980F,
                                            .nickname = _("SPINDA"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_PLUSLE,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_HELPING_HAND, MOVE_THUNDERBOLT, MOVE_AGILITY, MOVE_BATON_PASS},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("PLUSLE"),
                                        #elif FRENCH
                                            .nickname = _("POSIPI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_VOLBEAT,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_HELPING_HAND, MOVE_SIGNAL_BEAM, MOVE_SOLAR_BEAM, MOVE_MOONLIGHT},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("VOLBEAT"),
                                        #elif FRENCH
                                            .nickname = _("MUCIOLE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("FRANCISCO"),
                            .facilityClass = FACILITY_CLASS_POKEFAN_M,
                            .speechBefore = {EC_WORD_STUDY, EC_WORD_ELLIPSIS, EC_WORD_ANOTHER, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechWin = {EC_WORD_HEY, EC_WORD_YES, EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_EXCL_EXCL, },
                            .speechLose = {EC_WORD_IT_S, EC_WORD_IMPOSSIBLE, EC_WORD_OF, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_YES, EC_WORD_ELLIPSIS, EC_WORD_THANK_YOU, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                        #elif ITALIAN
                            .name = _("FRANCISCO"),
                            .facilityClass = FACILITY_CLASS_POKEFAN_M,
                            .speechBefore = {EC_WORD_DAILY, EC_WORD_STUDY, EC_WORD_VERY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_NITWIT, EC_WORD_ON, EC_WORD_WIN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_THE, EC_WORD_AS_IF, EC_WORD_WHICH, EC_WORD_PLEASE, EC_WORD_TAKE_THAT, EC_WORD_EXCL},
                            .speechAfter = {EC_WORD_YES, EC_WORD_ELLIPSIS, EC_WORD_THANKS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #else //ENGLISH
                            .name = _("FRANCISCO"),
                            .facilityClass = FACILITY_CLASS_POKEFAN_M,
                            .speechBefore = {EC_WORD_I, EC_WORD_STUDY, EC_WORD_EVERY, EC_WORD_DAY, EC_WORD_TOO, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_SO, EC_WORD_THAT_S, EC_WORD_HOW, EC_WORD_YOU, EC_WORD_LOSE, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_NO, EC_WORD_WONDER, EC_WORD_I, EC_WORD_COULDN_T, EC_WORD_BEAT, EC_WORD_YOU},
                            .speechAfter = {EC_WORD_YES, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_THANK_YOU, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SPINDA,
                                            .heldItem = ITEM_LUM_BERRY,
                                            .moves = {MOVE_TEETER_DANCE, MOVE_DIZZY_PUNCH, MOVE_CALM_MIND, MOVE_BATON_PASS},
                                            .hpEV = 110,
                                            .defenseEV = 200,
                                            .spDefenseEV = 200,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xE2880098,
                                            .nickname = _("SPINDA"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_MINUN,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_HELPING_HAND, MOVE_THUNDERBOLT, MOVE_AGILITY, MOVE_BATON_PASS},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x8C,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MINUN"),
                                        #elif FRENCH
                                            .nickname = _("NEGAPI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_ILLUMISE,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_HELPING_HAND, MOVE_WISH, MOVE_THUNDERBOLT, MOVE_MOONLIGHT},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("ILLUMISE"),
                                        #elif FRENCH
                                            .nickname = _("LUMIVOLE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_UNOWN,
                                            .heldItem = ITEM_CHARCOAL,
                                            .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 30,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = 30,
                                            .speedIV = 30,
                                            .spAttackIV = 30,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x302,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("UNOWN"),
                                        #elif FRENCH
                                            .nickname = _("ZARBI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_UNOWN,
                                            .heldItem = ITEM_SOFT_SAND,
                                            .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 255,
                                            .attackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = 30,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = 30,
                                            .spDefenseIV = 30,
                                            .abilityNum = 0,
                                            .personality = 0x203,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("UNOWN"),
                                        #elif FRENCH
                                            .nickname = _("ZARBI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_UNOWN,
                                            .heldItem = ITEM_TWISTED_SPOON,
                                            .moves = {MOVE_HIDDEN_POWER, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = 30,
                                            .speedIV = 30,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x301,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("UNOWN"),
                                        #elif FRENCH
                                            .nickname = _("ZARBI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_variety/floor_3/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_variety/floor_3/collision.bin"),
                .trainerCoords = {COORDS_XY(10,2), COORDS_XY(14,2)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(3, 3),
            }
        },
};

static const struct TrainerHillChallenge sChallenge_Unique =
{
    .numTrainers = NUM_TRAINER_HILL_TRAINERS,
    .unused1 = 3,
    .numFloors = NUM_TRAINER_HILL_FLOORS,
    .checksum = 0x000652F3
};

static const struct TrainerHillFloor sFloors_Unique[] = {
    [0] =
        {
            .trainerNum1 = 49,
            .trainerNum2 = 50,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("MEREDITH"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
                            .speechBefore = {EC_WORD_HMM, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechWin = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_HMM, EC_EMPTY_WORD, EC_WORD_YAY, EC_WORD_ELLIPSIS, },
                            .speechLose = {EC_WORD_HMM, EC_WORD_ELLIPSIS, EC_WORD_SIGH, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechAfter = {EC_WORD_HMM, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_VERY, EC_WORD_SAD, EC_WORD_ELLIPSIS, },
                        #elif ITALIAN
                            .name = _("WILMA"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
                            .speechBefore = {EC_WORD_HMM, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_YES, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_NO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_SAD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #else //ENGLISH
                            .name = _("MEREDITH"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
                            .speechBefore = {EC_WORD_UM, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_I, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_OH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_UM, EC_WORD_ELLIPSIS, EC_WORD_YAY},
                            .speechLose = {EC_WORD_UM, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_WAAAH, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_UM, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_SAD, EC_WORD_ELLIPSIS},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SUNFLORA,
                                            .heldItem = ITEM_PERSIM_BERRY,
                                            .moves = {MOVE_PETAL_DANCE, MOVE_GRASS_WHISTLE, MOVE_LIGHT_SCREEN, MOVE_SUNNY_DAY},
                                            .hpEV = 255,
                                            .defenseEV = 155,
                                            .spDefenseEV = 100,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SUNFLORA"),
                                        #elif FRENCH
                                            .nickname = _("HELIATRONC"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_TANGELA,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_GIGA_DRAIN, MOVE_SLEEP_POWDER, MOVE_AMNESIA, MOVE_SUNNY_DAY},
                                            .hpEV = 255,
                                            .spDefenseEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x91,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("TANGELA"),
                                        #elif FRENCH
                                            .nickname = _("SAQUEDENEU"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_VENUSAUR,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_SOLAR_BEAM, MOVE_EARTHQUAKE, MOVE_SYNTHESIS, MOVE_SUNNY_DAY},
                                            .hpEV = 100,
                                            .attackEV = 110,
                                            .defenseEV = 100,
                                            .spAttackEV = 100,
                                            .spDefenseEV = 100,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x1F,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("VENUSAUR"),
                                        #elif FRENCH
                                            .nickname = _("FLORIZARRE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_LANTURN,
                                            .heldItem = ITEM_PERSIM_BERRY,
                                            .moves = {MOVE_SPARK, MOVE_WATER_PULSE, MOVE_CONFUSE_RAY, MOVE_RAIN_DANCE},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("LANTURN"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_MANECTRIC,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_THUNDERBOLT, MOVE_HEADBUTT, MOVE_BITE, MOVE_RAIN_DANCE},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MANECTRIC"),
                                        #elif FRENCH
                                            .nickname = _("ELECSPRINT"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_RAIKOU,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_THUNDER, MOVE_CRUNCH, MOVE_ROAR, MOVE_RAIN_DANCE},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("RAIKOU"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("YVAN"),
                            .facilityClass = FACILITY_CLASS_KINDLER,
                            .speechBefore = {EC_WORD_FOR_NOW, EC_WORD_EXCL, EC_WORD_WILL, EC_WORD_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechWin = {EC_WORD_THAT_WAS, EC_WORD_AMUSING, EC_WORD_OF, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_SHOCKED, EC_WORD_YOU_RE, EC_WORD_AN, EC_WORD_PERSON, EC_WORD_AWFUL, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_HOW, EC_WORD_COULD, EC_WORD_YOU, EC_WORD_BE, EC_WORD_ALSO, EC_WORD_COLD, },
                        #elif ITALIAN
                            .name = _("BERNARDO"),
                            .facilityClass = FACILITY_CLASS_KINDLER,
                            .speechBefore = {EC_WORD_AS_IF, EC_WORD_PLEASE, EC_WORD_IF_I_LOSE, EC_WORD_OFF, EC_WORD_FIGHTING, EC_WORD_ELLIPSIS},
                            .speechWin = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_MISS, EC_WORD_PERSON, EC_WORD_WANDERING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_OVERDO, EC_WORD_MEETS, EC_WORD_IT, EC_WORD_DISAPPOINTED, EC_WORD_LISTEN, EC_WORD_STEEL},
                        #else //ENGLISH
                            .name = _("BERNARD"),
                            .facilityClass = FACILITY_CLASS_KINDLER,
                            .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_LOSE, EC_WORD_THIS, EC_WORD_HOT, EC_WORD_BATTLE},
                            .speechWin = {EC_WORD_DID, EC_WORD_I, EC_WORD_COOL, EC_WORD_YOU, EC_WORD_DOWN, EC_WORD_QUES},
                            .speechLose = {EC_WORD_AIYEEH, EC_WORD_EXCL, EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_TERRIBLE, EC_WORD_PERSON},
                            .speechAfter = {EC_WORD_YOUR, EC_WORD_HEART, EC_WORD_MUST_BE, EC_WORD_ICE, EC_WORD_COLD, EC_WORD_ELLIPSIS},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_RELICANTH,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_ANCIENT_POWER, MOVE_WATER_PULSE, MOVE_MUD_SPORT, MOVE_RAIN_DANCE},
                                            .hpEV = 155,
                                            .defenseEV = 100,
                                            .spDefenseEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x2F,
                                            .nickname = _("RELICANTH"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_GOLDUCK,
                                            .heldItem = ITEM_LAX_INCENSE,
                                            .moves = {MOVE_SURF, MOVE_PSYBEAM, MOVE_BRICK_BREAK, MOVE_RAIN_DANCE},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("GOLDUCK"),
                                        #elif FRENCH
                                            .nickname = _("AKWAKWAK"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_BLASTOISE,
                                            .heldItem = ITEM_SHELL_BELL,
                                            .moves = {MOVE_HYDRO_PUMP, MOVE_BITE, MOVE_MIRROR_COAT, MOVE_RAIN_DANCE},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x28,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("BLASTOISE"),
                                        #elif FRENCH
                                            .nickname = _("TORTANK"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_MAGCARGO,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_HEAT_WAVE, MOVE_ROCK_SLIDE, MOVE_PROTECT, MOVE_SUNNY_DAY},
                                            .hpEV = 255,
                                            .spDefenseEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x93,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MAGCARGO"),
                                        #elif FRENCH
                                            .nickname = _("VOLCAROPOD"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_RAPIDASH,
                                            .heldItem = ITEM_KINGS_ROCK,
                                            .moves = {MOVE_FIRE_BLAST, MOVE_BOUNCE, MOVE_QUICK_ATTACK, MOVE_SUNNY_DAY},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("RAPIDASH"),
                                        #elif FRENCH
                                            .nickname = _("GALOPA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_MOLTRES,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_SKY_ATTACK, MOVE_AERIAL_ACE, MOVE_ROAR, MOVE_SUNNY_DAY},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MOLTRES"),
                                        #elif FRENCH
                                            .nickname = _("SULFURA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_unique/floor_0/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_unique/floor_0/collision.bin"),
                .trainerCoords = {COORDS_XY(4,3), COORDS_XY(7,3)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(2, 2),
            }
        },
    [1] =
        {
            .trainerNum1 = 51,
            .trainerNum2 = 52,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("ABRAHAM"),
                            .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
                            .speechBefore = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechWin = {EC_WORD_HE, EC_WORD_IS, EC_WORD_SUPER, EC_WORD_THIS, EC_WORD_POKEMON, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_HER, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_REALLY, EC_WORD_USELESS, EC_WORD_ELLIPSIS, },
                            .speechAfter = {EC_WORD_I, EC_WORD_ON, EC_WORD_A, EC_WORD_DESIGN, EC_WORD_OF, EC_WORD_HIM, },
                        #elif ITALIAN
                            .name = _("ABRAMO"),
                            .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
                            .speechBefore = {EC_WORD_HOW, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_ON, EC_WORD_POKEMON, EC_WORD_EXCL},
                            .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_LOWS, EC_WORD_A, EC_WORD_THIN, EC_WORD_POKEMON, EC_WORD_EXCL},
                            .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_MOVE2(CONFUSION), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_IS_IT_QUES, EC_WORD_TO, EC_WORD_MOVE, EC_WORD_VERY, EC_WORD_ENTERTAINING, EC_WORD_ELLIPSIS},
                        #else //ENGLISH
                            .name = _("ABRAHAM"),
                            .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
                            .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_THIS, EC_WORD_POKEMON, EC_WORD_THE, EC_WORD_BEST},
                            .speechWin = {EC_WORD_WHAT, EC_WORD_A, EC_WORD_GREAT, EC_WORD_POKEMON, EC_WORD_IT, EC_WORD_IS},
                            .speechLose = {EC_WORD_I, EC_WORD_CONFUSED, EC_WORD_A, EC_WORD_MOVE, EC_WORD_WITH, EC_WORD_ANOTHER},
                            .speechAfter = {EC_WORD_I, EC_WORD_WANT, EC_WORD_A, EC_MOVE(SKETCH), EC_WORD_OF, EC_WORD_YOU},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SMEARGLE,
                                            .heldItem = ITEM_SCOPE_LENS,
                                            .moves = {MOVE_EARTHQUAKE, MOVE_SHADOW_BALL, MOVE_AERIAL_ACE, MOVE_IMPRISON},
                                            .hpEV = 252,
                                            .attackEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x8A,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SMEARGLE"),
                                        #elif FRENCH
                                            .nickname = _("QUEULORIOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_SMEARGLE,
                                            .heldItem = ITEM_CHESTO_BERRY,
                                            .moves = {MOVE_REST, MOVE_THUNDER_WAVE, MOVE_FLAMETHROWER, MOVE_IMPRISON},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x87,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SMEARGLE"),
                                        #elif FRENCH
                                            .nickname = _("QUEULORIOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_SMEARGLE,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_TEETER_DANCE, MOVE_LOCK_ON, MOVE_SHEER_COLD, MOVE_EXPLOSION},
                                            .hpEV = 252,
                                            .attackEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SMEARGLE"),
                                        #elif FRENCH
                                            .nickname = _("QUEULORIOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_SMEARGLE,
                                            .heldItem = ITEM_SCOPE_LENS,
                                            .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_THUNDERBOLT, MOVE_IMPRISON},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SMEARGLE"),
                                        #elif FRENCH
                                            .nickname = _("QUEULORIOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_SMEARGLE,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_TOXIC, MOVE_PROTECT, MOVE_WILL_O_WISP, MOVE_IMPRISON},
                                            .hpEV = 252,
                                            .defenseEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SMEARGLE"),
                                        #elif FRENCH
                                            .nickname = _("QUEULORIOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_SMEARGLE,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_TEETER_DANCE, MOVE_LOCK_ON, MOVE_SHEER_COLD, MOVE_DESTINY_BOND},
                                            .hpEV = 252,
                                            .defenseEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x8A,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SMEARGLE"),
                                        #elif FRENCH
                                            .nickname = _("QUEULORIOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("LEOPOLD"),
                            .facilityClass = FACILITY_CLASS_TUBER_M,
                            .speechBefore = {EC_WORD_DAUGHTER, EC_WORD_MOVE, EC_WORD_IS, EC_WORD_RARE, EC_WORD_AND, EC_WORD_COOL, },
                            .speechWin = {EC_WORD_I_AM, EC_WORD_LACKING, EC_WORD_OF, EC_WORD_DAUGHTER, EC_WORD_MATCH_UP, EC_WORD_EXCL_EXCL, },
                            .speechLose = {EC_WORD_I, EC_WORD_SEEK, EC_WORD_A, EC_WORD_GOOD, EC_WORD_TEACHER, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_I_AM, EC_WORD_SMART, EC_WORD_BUT, EC_WORD_WEAK, EC_WORD_ALSO, EC_WORD_ELLIPSIS, },
                        #elif ITALIAN
                            .name = _("LUCHINO"),
                            .facilityClass = FACILITY_CLASS_TUBER_M,
                            .speechBefore = {EC_WORD_ENTERTAINING, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_MOVE, EC_WORD_HEH, EC_WORD_QUES},
                            .speechWin = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_ENTERTAINING, EC_WORD_ELLIPSIS},
                            .speechLose = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_MOVE, EC_WORD_IS, EC_WORD_WEAK, EC_WORD_WEAK},
                            .speechAfter = {EC_WORD_ARE, EC_WORD_SMART, EC_WORD_BUT, EC_WORD_AS_IF, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
                        #else //ENGLISH
                            .name = _("LUC"),
                            .facilityClass = FACILITY_CLASS_TUBER_M,
                            .speechBefore = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_A, EC_WORD_COOL, EC_WORD_RARE, EC_WORD_MOVE},
                            .speechWin = {EC_WORD_MY, EC_WORD_RARE, EC_WORD_MOVE, EC_WORD_IS, EC_WORD_COOL, EC_WORD_ISN_T_IT_QUES},
                            .speechLose = {EC_WORD_DIDN_T, EC_WORD_YOU, EC_WORD_SEE, EC_WORD_MY, EC_WORD_MOVE, EC_WORD_QUES},
                            .speechAfter = {EC_WORD_I_AM, EC_WORD_SMART, EC_WORD_BUT, EC_WORD_ALSO, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_STARYU,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_CAMOUFLAGE, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 1,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("STARYU"),
                                        #elif FRENCH
                                            .nickname = _("STARI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_MEOWTH,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_PAY_DAY, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MEOWTH"),
                                        #elif FRENCH
                                            .nickname = _("MIAOUSS"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_BLAZIKEN,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_BLAZE_KICK, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x28,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("BLAZIKEN"),
                                        #elif FRENCH
                                            .nickname = _("BRASEGALI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_CUBONE,
                                            .heldItem = ITEM_THICK_CLUB,
                                            .moves = {MOVE_BONEMERANG, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .defenseEV = 6,
                                            .spDefenseEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 1,
                                            .personality = 0x16,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CUBONE"),
                                        #elif FRENCH
                                            .nickname = _("OSSELAIT"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_BEEDRILL,
                                            .heldItem = ITEM_SHELL_BELL,
                                            .moves = {MOVE_TWINEEDLE, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 0,
                                            .personality = 0x8A,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("BEEDRILL"),
                                        #elif FRENCH
                                            .nickname = _("DARDARGNAN"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_RATICATE,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_SUPER_FANG, MOVE_NONE, MOVE_NONE, MOVE_NONE},
                                            .hpEV = 252,
                                            .defenseEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 5,
                                            .attackIV = 5,
                                            .defenseIV = 5,
                                            .speedIV = 5,
                                            .spAttackIV = 5,
                                            .spDefenseIV = 5,
                                            .abilityNum = 1,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("RATICATE"),
                                        #elif FRENCH
                                            .nickname = _("RATTATAC"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_unique/floor_1/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_unique/floor_1/collision.bin"),
                .trainerCoords = {COORDS_XY(9,6), COORDS_XY(13,6)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(3, 3),
            }
        },
    [2] =
        {
            .trainerNum1 = 53,
            .trainerNum2 = 54,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("AUGUSTIN"),
                            .facilityClass = FACILITY_CLASS_YOUNGSTER,
                            .speechBefore = {EC_WORD_I_VE, EC_WORD_TRUST, EC_WORD_IN, EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_EXCL, },
                            .speechWin = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_VERY, EC_WORD_FIERY, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_I, EC_WORD_COULD, EC_WORD_NOT, EC_WORD_ALWAYS, EC_WORD_WIN, EC_WORD_ELLIPSIS, },
                            .speechAfter = {EC_WORD_LIKE, EC_WORD_FEELING, EC_WORD_CLASS, EC_WORD_MOOD, EC_WORD_POKEMON, EC_WORD_EXCL, },
                        #elif ITALIAN
                            .name = _("ILARIO"),
                            .facilityClass = FACILITY_CLASS_YOUNGSTER,
                            .speechBefore = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_HERE, EC_WORD_NITWIT, EC_WORD_DON_T},
                            .speechWin = {EC_WORD_SORRY, EC_WORD_NITWIT, EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
                            .speechLose = {EC_WORD_AS_IF, EC_WORD_ALWAYS, EC_WORD_LEGEND, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_IS_IT_QUES, EC_WORD_GOTCHA, EC_WORD_A, EC_WORD_EGG, EC_WORD_LISTEN, EC_WORD_POKEMON},
                        #else //ENGLISH
                            .name = _("BREYDEN"),
                            .facilityClass = FACILITY_CLASS_YOUNGSTER,
                            .speechBefore = {EC_WORD_I, EC_WORD_CARE, EC_WORD_FOR, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_A_LOT},
                            .speechWin = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_CAN, EC_WORD_DO, EC_WORD_IT, EC_WORD_ALL},
                            .speechLose = {EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_LIKE, EC_WORD_WE, EC_WORD_ALWAYS, EC_WORD_WIN},
                            .speechAfter = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_THE, EC_WORD_BEGINNING, EC_WORD_POKEMON, EC_WORD_BEST},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_CHARMELEON,
                                            .heldItem = ITEM_CHARCOAL,
                                            .moves = {MOVE_FIRE_SPIN, MOVE_DRAGON_RAGE, MOVE_FLAMETHROWER, MOVE_SLASH},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 25,
                                            .attackIV = 25,
                                            .defenseIV = 25,
                                            .speedIV = 25,
                                            .spAttackIV = 25,
                                            .spDefenseIV = 25,
                                            .abilityNum = 0,
                                            .personality = 0x32,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CHARMELEON"),
                                        #elif FRENCH
                                            .nickname = _("REPTINCEL"),
                                        #endif
                                            .friendship = 100,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_WARTORTLE,
                                            .heldItem = ITEM_MYSTIC_WATER,
                                            .moves = {MOVE_HYDRO_PUMP, MOVE_SKULL_BASH, MOVE_RAIN_DANCE, MOVE_PROTECT},
                                            .hpEV = 250,
                                            .defenseEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 25,
                                            .attackIV = 25,
                                            .defenseIV = 25,
                                            .speedIV = 25,
                                            .spAttackIV = 25,
                                            .spDefenseIV = 25,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("WARTORTLE"),
                                        #elif FRENCH
                                            .nickname = _("CARABAFFE"),
                                        #endif
                                            .friendship = 100,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_IVYSAUR,
                                            .heldItem = ITEM_MIRACLE_SEED,
                                            .moves = {MOVE_SOLAR_BEAM, MOVE_SYNTHESIS, MOVE_GROWTH, MOVE_SWEET_SCENT},
                                            .hpEV = 252,
                                            .speedEV = 6,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 25,
                                            .attackIV = 25,
                                            .defenseIV = 25,
                                            .speedIV = 25,
                                            .spAttackIV = 25,
                                            .spDefenseIV = 25,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("IVYSAUR"),
                                        #elif FRENCH
                                            .nickname = _("HERBIZARRE"),
                                        #endif
                                            .friendship = 100,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_BAYLEEF,
                                            .heldItem = ITEM_MIRACLE_SEED,
                                            .moves = {MOVE_SOLAR_BEAM, MOVE_SAFEGUARD, MOVE_LIGHT_SCREEN, MOVE_BODY_SLAM},
                                            .hpEV = 250,
                                            .attackEV = 130,
                                            .spAttackEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 25,
                                            .attackIV = 25,
                                            .defenseIV = 25,
                                            .speedIV = 25,
                                            .spAttackIV = 25,
                                            .spDefenseIV = 25,
                                            .abilityNum = 0,
                                            .personality = 0x32,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("BAYLEEF"),
                                        #elif FRENCH
                                            .nickname = _("MACRONIUM"),
                                        #endif
                                            .friendship = 100,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_CROCONAW,
                                            .heldItem = ITEM_MYSTIC_WATER,
                                            .moves = {MOVE_SCARY_FACE, MOVE_SLASH, MOVE_HYDRO_PUMP, MOVE_SCREECH},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .speedEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 25,
                                            .attackIV = 25,
                                            .defenseIV = 25,
                                            .speedIV = 25,
                                            .spAttackIV = 25,
                                            .spDefenseIV = 25,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CROCONAW"),
                                        #elif FRENCH
                                            .nickname = _("CROCRODIL"),
                                        #endif
                                            .friendship = 100,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_QUILAVA,
                                            .heldItem = ITEM_CHARCOAL,
                                            .moves = {MOVE_QUICK_ATTACK, MOVE_FLAMETHROWER, MOVE_FLAME_WHEEL, MOVE_SWIFT},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x28,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("QUILAVA"),
                                        #elif FRENCH
                                            .nickname = _("FEURISSON"),
                                        #endif
                                            .friendship = 100,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("ANIYA"),
                            .facilityClass = FACILITY_CLASS_TUBER_F,
                            .speechBefore = {EC_WORD_I_VE, EC_WORD_RECEIVED, EC_WORD_A, EC_WORD_EGG, EC_WORD_OF, EC_WORD_POKEMON, },
                            .speechWin = {EC_WORD_GO, EC_WORD_EXCL, EC_WORD_WITHOUT, EC_EMPTY_WORD, EC_MOVE(GRUDGE), EC_WORD_ELLIPSIS, },
                            .speechLose = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_BUT, EC_WORD_ELLIPSIS, EC_WORD_WHY, EC_WORD_QUES, },
                            .speechAfter = {EC_WORD_DOES, EC_EMPTY_WORD, EC_WORD_BUSY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                        #elif ITALIAN
                            .name = _("MOIRA"),
                            .facilityClass = FACILITY_CLASS_TUBER_F,
                            .speechBefore = {EC_WORD_WILL, EC_WORD_A, EC_WORD_EGG, EC_WORD_LISTEN, EC_WORD_POKEMON, EC_WORD_QUES},
                            .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_AWFULLY, EC_WORD_WON, EC_WORD_OLDEN, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_HIT, EC_WORD_QUES_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_WILL, EC_WORD_VERY, EC_WORD_WORK, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #else //ENGLISH
                            .name = _("ANIYA"),
                            .facilityClass = FACILITY_CLASS_TUBER_F,
                            .speechBefore = {EC_WORD_SOMEONE, EC_WORD_GOT, EC_WORD_ME, EC_WORD_A_LITTLE, EC_WORD_POKEMON, EC_WORD_EGG},
                            .speechWin = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_NEW, EC_WORD_AT, EC_WORD_THIS, EC_WORD_EXCL},
                            .speechLose = {EC_WORD_OH, EC_WORD_BUT, EC_WORD_ELLIPSIS, EC_WORD_WHY, EC_WORD_WHY, EC_WORD_QUES_EXCL},
                            .speechAfter = {EC_WORD_YOU_RE, EC_WORD_BUSY, EC_WORD_QUES, EC_WORD_DON_T, EC_WORD_GIVE_UP, EC_WORD_EXCL},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SMOOCHUM,
                                            .heldItem = ITEM_PETAYA_BERRY,
                                            .moves = {MOVE_ICE_BEAM, MOVE_PSYCHIC, MOVE_SWEET_KISS, MOVE_FAKE_TEARS},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x32,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SMOOCHUM"),
                                        #elif FRENCH
                                            .nickname = _("LIPPOUTI"),
                                        #endif
                                            .friendship = 50,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_AZURILL,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_SURF, MOVE_SING, MOVE_RAIN_DANCE, MOVE_BLIZZARD},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xC8,
                                            .nickname = _("AZURILL"),
                                            .friendship = 50,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_ELEKID,
                                            .heldItem = ITEM_KINGS_ROCK,
                                            .moves = {MOVE_FIRE_PUNCH, MOVE_THUNDER, MOVE_ICE_PUNCH, MOVE_THUNDER_WAVE},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                            .nickname = _("ELEKID"),
                                            .friendship = 50,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_CLEFFA,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_MEGA_KICK, MOVE_SWEET_KISS, MOVE_SING, MOVE_METRONOME},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CLEFFA"),
                                        #elif FRENCH
                                            .nickname = _("MELO"),
                                        #endif
                                            .friendship = 50,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_WYNAUT,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_ENCORE, MOVE_COUNTER, MOVE_MIRROR_COAT, MOVE_DESTINY_BOND},
                                            .hpEV = 250,
                                            .defenseEV = 130,
                                            .spDefenseEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x84,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("WYNAUT"),
                                        #elif FRENCH
                                            .nickname = _("OKEOKE"),
                                        #endif
                                            .friendship = 50,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_MAGBY,
                                            .heldItem = ITEM_SCOPE_LENS,
                                            .moves = {MOVE_FIRE_BLAST, MOVE_CONFUSE_RAY, MOVE_THUNDER_PUNCH, MOVE_BARRIER},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("MAGBY"),
                                            .friendship = 50,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_unique/floor_2/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_unique/floor_2/collision.bin"),
                .trainerCoords = {COORDS_XY(6,9), COORDS_XY(8,9)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(1, 1),
            }
        },
    [3] =
        {
            .trainerNum1 = 56,
            .trainerNum2 = 55,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("ADAM"),
                            .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
                            .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_IN, EC_WORD_HOLIDAY, EC_WORD_EXCL, },
                            .speechWin = {EC_WORD_CASE, EC_WORD_TRAVEL, EC_WORD_WINNER, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechLose = {EC_WORD_SIGH, EC_WORD_ELLIPSIS, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_RARE, EC_EMPTY_WORD, },
                            .speechAfter = {EC_WORD_WILL, EC_WORD_IN, EC_WORD_HOLIDAY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                        #elif ITALIAN
                            .name = _("IPPOLITO"),
                            .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
                            .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_GOTCHA, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_INSTEAD, EC_WORD_VACATION},
                            .speechWin = {EC_WORD_MISS, EC_WORD_BEAUTIFUL, EC_WORD_TRAVEL, EC_WORD_AND, EC_WORD_HEARING, EC_WORD_ELLIPSIS},
                            .speechLose = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_DREAM, EC_WORD_ABOUT, EC_WORD_VACATION, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #else //ENGLISH
                            .name = _("DANE"),
                            .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
                            .speechBefore = {EC_WORD_I, EC_WORD_GOT, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ON, EC_WORD_VACATION},
                            .speechWin = {EC_WORD_IT_S, EC_WORD_GREAT, EC_WORD_TO, EC_WORD_TRAVEL, EC_WORD_AND, EC_WORD_BATTLE},
                            .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL, EC_WORD_MY, EC_WORD_RARE, EC_WORD_POKEMON, EC_WORD_EXCL},
                            .speechAfter = {EC_WORD_OFF, EC_WORD_ON, EC_WORD_ANOTHER, EC_WORD_VACATION, EC_WORD_I, EC_WORD_GO},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SUDOWOODO,
                                            .heldItem = ITEM_SITRUS_BERRY,
                                            .moves = {MOVE_ROCK_SLIDE, MOVE_BLOCK, MOVE_TOXIC, MOVE_EXPLOSION},
                                            .hpEV = 100,
                                            .attackEV = 255,
                                            .spDefenseEV = 155,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SUDOWOODO"),
                                        #elif FRENCH
                                            .nickname = _("SIMULARBRE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_SLOWKING,
                                            .heldItem = ITEM_SCOPE_LENS,
                                            .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_BLIZZARD, MOVE_DISABLE},
                                            .hpEV = 255,
                                            .defenseEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x8C,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SLOWKING"),
                                        #elif FRENCH
                                            .nickname = _("ROIGADA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_ENTEI,
                                            .heldItem = ITEM_PETAYA_BERRY,
                                            .moves = {MOVE_FLAMETHROWER, MOVE_CALM_MIND, MOVE_FIRE_SPIN, MOVE_ROAR},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("ENTEI"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_HITMONCHAN,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_MEGA_PUNCH, MOVE_DETECT, MOVE_COUNTER, MOVE_SKY_UPPERCUT},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("HITMONCHAN"),
                                        #elif FRENCH
                                            .nickname = _("TYGNON"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_MANTINE,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_SURF, MOVE_CONFUSE_RAY, MOVE_ATTRACT, MOVE_AERIAL_ACE},
                                            .hpEV = 255,
                                            .defenseEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0x6,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MANTINE"),
                                        #elif FRENCH
                                            .nickname = _("DEMANTA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_ZAPDOS,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_THUNDERBOLT, MOVE_DRILL_PECK, MOVE_THUNDER_WAVE, MOVE_AGILITY},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x18,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("ZAPDOS"),
                                        #elif FRENCH
                                            .nickname = _("ELECTHOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("STEPHANIE"),
                            .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
                            .speechBefore = {EC_WORD_I, EC_WORD_THINKS, EC_WORD_WIN, EC_WORD_WITH, EC_WORD_GOING, EC_WORD_EXCL, },
                            .speechWin = {EC_WORD_WHOM, EC_WORD_A, EC_WORD_GOOD, EC_EMPTY_WORD, EC_WORD_TEACHER, EC_WORD_QUES, },
                            .speechLose = {EC_WORD_HOW, EC_EMPTY_WORD, EC_WORD_WHOM, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechAfter = {EC_WORD_YOU_VE, EC_WORD_WINS, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_EXCUSE, EC_WORD_EXCL, },
                        #elif ITALIAN
                            .name = _("STEPHANIE"),
                            .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
                            .speechBefore = {EC_WORD_CHOOSE, EC_WORD_PRETEND, EC_WORD_HOW, EC_WORD_LEARN, EC_WORD_IF_I_WIN, EC_WORD_QUES},
                            .speechWin = {EC_WORD_NOW, EC_WORD_WORKS, EC_WORD_HOW, EC_WORD_WIN, EC_WORD_ISN_T_IT_QUES, EC_WORD_ELLIPSIS},
                            .speechLose = {EC_WORD_NOW, EC_WORD_WORKS, EC_WORD_HOW, EC_WORD_SPIRIT, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_WILL, EC_WORD_WON, EC_WORD_WILL_BE_HERE, EC_WORD_HAPPY, EC_WORD_NOW, EC_WORD_QUES},
                        #else //ENGLISH
                            .name = _("STEPHANIE"),
                            .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
                            .speechBefore = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_HOW, EC_WORD_YOU, EC_WORD_WIN, EC_WORD_EXCL},
                            .speechWin = {EC_WORD_DO, EC_WORD_YOU, EC_WORD_UNDERSTAND, EC_WORD_HOW, EC_WORD_NOW, EC_WORD_QUES},
                            .speechLose = {EC_WORD_YES, EC_WORD_THAT_S, EC_WORD_HOW, EC_WORD_YOU, EC_WORD_DO, EC_WORD_IT},
                            .speechAfter = {EC_WORD_YOU, EC_WORD_BEAT, EC_WORD_ME, EC_WORD_GOOD, EC_WORD_FOR, EC_WORD_YOU},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_HITMONLEE,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_MEGA_KICK, MOVE_MIND_READER, MOVE_FOCUS_ENERGY, MOVE_HI_JUMP_KICK},
                                            .hpEV = 255,
                                            .attackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("HITMONLEE"),
                                        #elif FRENCH
                                            .nickname = _("KICKLEE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_PORYGON2,
                                            .heldItem = ITEM_SCOPE_LENS,
                                            .moves = {MOVE_LOCK_ON, MOVE_BLIZZARD, MOVE_CONVERSION_2, MOVE_PSYCHIC},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("PORYGON2"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_SUICUNE,
                                            .heldItem = ITEM_PETAYA_BERRY,
                                            .moves = {MOVE_SURF, MOVE_CALM_MIND, MOVE_MIRROR_COAT, MOVE_MIST},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("SUICUNE"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_HOUNDOOM,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_FLAMETHROWER, MOVE_CRUNCH, MOVE_ROAR, MOVE_WILL_O_WISP},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 1,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("HOUNDOOM"),
                                        #elif FRENCH
                                            .nickname = _("DEMOLOSSE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_STANTLER,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_CONFUSE_RAY, MOVE_SWAGGER, MOVE_PSYCH_UP, MOVE_TAKE_DOWN},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("STANTLER"),
                                        #elif FRENCH
                                            .nickname = _("CERFROUSSE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_ARTICUNO,
                                            .heldItem = ITEM_NEVER_MELT_ICE,
                                            .moves = {MOVE_BLIZZARD, MOVE_SHEER_COLD, MOVE_MIST, MOVE_AERIAL_ACE},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = 15,
                                            .attackIV = 15,
                                            .defenseIV = 15,
                                            .speedIV = 15,
                                            .spAttackIV = 15,
                                            .spDefenseIV = 15,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("ARTICUNO"),
                                        #elif FRENCH
                                            .nickname = _("ARTIKODIN"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_unique/floor_3/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_unique/floor_3/collision.bin"),
                .trainerCoords = {COORDS_XY(8,2), COORDS_XY(11,5)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_NORTH),
                .trainerRanges = TRAINER_RANGE(3, 3),
            }
        },
};

static const struct TrainerHillChallenge sChallenge_Expert =
{
    .numTrainers = NUM_TRAINER_HILL_TRAINERS,
    .unused1 = 1,
    .numFloors = NUM_TRAINER_HILL_FLOORS,
    .checksum = 0x00061F3F
};

static const struct TrainerHillFloor sFloors_Expert[] = {
    [0] =
        {
            .trainerNum1 = 57,
            .trainerNum2 = 58,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("ALBAN"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
                            .speechBefore = {EC_WORD_I_AM, EC_WORD_LIE, EC_WORD_CAPABLE, EC_WORD_OF, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, },
                            .speechWin = {EC_WORD_THAT_WAS, EC_WORD_REALLY, EC_WORD_EXCELLENT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechLose = {EC_WORD_OUR, EC_WORD_STRATEGY, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_PREPOSTEROUS, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_DONE, EC_EMPTY_WORD, EC_WORD_SNORT, EC_WORD_EXCL, },
                        #elif ITALIAN
                            .name = _("ORAZIO"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
                            .speechBefore = {EC_WORD_STORY, EC_WORD_IF_I_WIN, EC_WORD_ALWAYS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_OR, EC_WORD_PERFECT, EC_WORD_OKAY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_WEREN_T, EC_WORD_AT, EC_WORD_STRATEGY, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_OKAY},
                            .speechAfter = {EC_WORD_WHOM, EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_PLUS, EC_WORD_WORK, EC_WORD_ELLIPSIS},
                        #else //ENGLISH
                            .name = _("ALFRED"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
                            .speechBefore = {EC_WORD_WE, EC_WORD_CAN, EC_WORD_TAKE, EC_WORD_ON, EC_WORD_ANY, EC_WORD_TYPE},
                            .speechWin = {EC_WORD_WE, EC_WORD_DID, EC_WORD_BETTER, EC_WORD_THAN, EC_WORD_OKAY, EC_WORD_EXCL},
                            .speechLose = {EC_WORD_OUR, EC_WORD_STRATEGY, EC_WORD_ISN_T, EC_WORD_ANY, EC_WORD_GOOD, EC_WORD_ELLIPSIS},
                            .speechAfter = {EC_WORD_WE, EC_WORD_NEED, EC_WORD_TO, EC_WORD_TRAIN, EC_WORD_A_LOT, EC_WORD_MORE},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SNORLAX,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_EARTHQUAKE},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .defenseEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x35,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SNORLAX"),
                                        #elif FRENCH
                                            .nickname = _("RONFLEX"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_MILTANK,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_DOUBLE_EDGE, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_MILK_DRINK},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MILTANK"),
                                        #elif FRENCH
                                            .nickname = _("ECREMEUH"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_URSARING,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_DOUBLE_EDGE, MOVE_CRUNCH, MOVE_BRICK_BREAK, MOVE_AERIAL_ACE},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x7F,
                                            .nickname = _("URSARING"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_SLAKING,
                                            .heldItem = ITEM_CHESTO_BERRY,
                                            .moves = {MOVE_HYPER_BEAM, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_REST},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .spDefenseEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SLAKING"),
                                        #elif FRENCH
                                            .nickname = _("MONAFLEMIT"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_KANGASKHAN,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_MEGA_KICK, MOVE_SHADOW_BALL, MOVE_ATTRACT, MOVE_FAKE_OUT},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("KANGASKHAN"),
                                        #elif FRENCH
                                            .nickname = _("KANGOUREX"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_ZANGOOSE,
                                            .heldItem = ITEM_SCOPE_LENS,
                                            .moves = {MOVE_CRUSH_CLAW, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_ROAR},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("ZANGOOSE"),
                                        #elif FRENCH
                                            .nickname = _("MANGRIFF"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("SARRAH"),
                            .facilityClass = FACILITY_CLASS_PSYCHIC_F,
                            .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_FOR, EC_WORD_ACCEPT, EC_WORD_A, EC_WORD_CHALLENGE, },
                            .speechWin = {EC_WORD_DAUGHTER, EC_WORD_STRATEGY, EC_WORD_WALKS, EC_WORD_EVEN_SO, EC_WORD_FEELING, EC_WORD_PERFECTION, },
                            .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_IF, EC_WORD_ISN_T, EC_WORD_WALKS, EC_WORD_NOT, },
                            .speechAfter = {EC_WORD_AN, EC_WORD_SCHOOL, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_TRAINER, EC_WORD_QUES, },
                        #elif ITALIAN
                            .name = _("EDDA"),
                            .facilityClass = FACILITY_CLASS_PSYCHIC_F,
                            .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_LET_S, EC_WORD_WEREN_T, EC_WORD_ANOTHER, EC_WORD_CHALLENGE, EC_WORD_QUES},
                            .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_STRATEGY, EC_WORD_IS, EC_WORD_FROM, EC_WORD_FEAR},
                            .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_AS_IF, EC_WORD_LEARN, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
                            .speechAfter = {EC_WORD_TRAINS, EC_WORD_TO, EC_WORD_SCHOOL, EC_WORD_FROM, EC_WORD_TRAINER, EC_WORD_ELLIPSIS},
                        #else //ENGLISH
                            .name = _("EDIE"),
                            .facilityClass = FACILITY_CLASS_PSYCHIC_F,
                            .speechBefore = {EC_WORD_WE, EC_WORD_WILL_BE_HERE, EC_WORD_FOR, EC_WORD_ANY, EC_WORD_TRAINER, EC_WORD_CHALLENGE},
                            .speechWin = {EC_WORD_MY, EC_WORD_STRATEGY, EC_WORD_WORKS, EC_WORD_TO, EC_WORD_PERFECTION, EC_WORD_EXCL},
                            .speechLose = {EC_WORD_NO, EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_THAT, EC_WORD_WON_T, EC_WORD_DO},
                            .speechAfter = {EC_WORD_THERE, EC_WORD_SHOULD, EC_WORD_BE, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_SCHOOL},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SLOWKING,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_ICE_BEAM, MOVE_SKILL_SWAP},
                                            .hpEV = 200,
                                            .defenseEV = 110,
                                            .spAttackEV = 200,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 1,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SLOWKING"),
                                        #elif FRENCH
                                            .nickname = _("ROIGADA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_ESPEON,
                                            .heldItem = ITEM_LUM_BERRY,
                                            .moves = {MOVE_PSYCHIC, MOVE_BITE, MOVE_CALM_MIND, MOVE_REFLECT},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x28,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("ESPEON"),
                                        #elif FRENCH
                                            .nickname = _("MENTALI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_STARMIE,
                                            .heldItem = ITEM_SHELL_BELL,
                                            .moves = {MOVE_PSYCHIC, MOVE_SURF, MOVE_THUNDERBOLT, MOVE_ICE_BEAM},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 1,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("STARMIE"),
                                        #elif FRENCH
                                            .nickname = _("STAROSS"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_GENGAR,
                                            .heldItem = ITEM_LUM_BERRY,
                                            .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FIRE_PUNCH, MOVE_ICE_PUNCH},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("GENGAR"),
                                        #elif FRENCH
                                            .nickname = _("ECTOPLASMA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_GARDEVOIR,
                                            .heldItem = ITEM_SALAC_BERRY,
                                            .moves = {MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_MAGICAL_LEAF, MOVE_DESTINY_BOND},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("GARDEVOIR"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_ALAKAZAM,
                                            .heldItem = ITEM_LUM_BERRY,
                                            .moves = {MOVE_PSYCHIC, MOVE_RECOVER, MOVE_THUNDER_WAVE, MOVE_ATTRACT},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                            .nickname = _("ALAKAZAM"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_expert/floor_0/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_expert/floor_0/collision.bin"),
                .trainerCoords = {COORDS_XY(4,7), COORDS_XY(10,7)},
                .trainerDirections = TRAINER_DIRS(DIR_WEST, DIR_EAST),
                .trainerRanges = TRAINER_RANGE(5, 5),
            }
        },
    [1] =
        {
            .trainerNum1 = 59,
            .trainerNum2 = 60,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("ALISTAIR"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
                            .speechBefore = {EC_WORD_CAN, EC_WORD_WIN, EC_WORD_WITHOUT, EC_EMPTY_WORD, EC_MOVE2(HELPING_HAND), EC_WORD_EXCL, },
                            .speechWin = {EC_WORD_IT_S, EC_WORD_NORMAL, EC_WORD_THAT, EC_WORD_I, EC_WORD_WINS, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_FEAR, EC_WORD_OF, EC_WORD_LOSE, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_WHOM, EC_EMPTY_WORD, EC_WORD_A, EC_WORD_GOOD, EC_WORD_TEACHER, EC_WORD_QUES, },
                        #elif ITALIAN
                            .name = _("SAMUELE"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
                            .speechBefore = {EC_WORD_PLEASE, EC_WORD_IF_I_WIN, EC_WORD_ALWAYS, EC_WORD_LAY, EC_WORD_DO, EC_WORD_ELLIPSIS},
                            .speechWin = {EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_WEREN_T, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_NATURAL},
                            .speechLose = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_IF_I_LOSE, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_HOW, EC_WORD_IS, EC_WORD_IT, EC_WORD_EVER, EC_WORD_TEACHER, EC_WORD_QUES},
                        #else //ENGLISH
                            .name = _("RODERICK"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
                            .speechBefore = {EC_WORD_I, EC_WORD_CAN, EC_WORD_WIN, EC_WORD_WITHOUT, EC_WORD_A, EC_MOVE2(HELPING_HAND)},
                            .speechWin = {EC_WORD_IT_S, EC_WORD_ONLY, EC_WORD_NATURAL, EC_WORD_THAT, EC_WORD_I, EC_WORD_WIN},
                            .speechLose = {EC_WORD_LOSING, EC_WORD_HAS, EC_WORD_ME, EC_WORD_FEELING, EC_WORD_SMALL, EC_WORD_ELLIPSIS},
                            .speechAfter = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_A, EC_WORD_GOOD, EC_WORD_TEACHER, EC_WORD_QUES},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SWELLOW,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_AERIAL_ACE, MOVE_AGILITY, MOVE_FACADE, MOVE_ATTRACT},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SWELLOW"),
                                        #elif FRENCH
                                            .nickname = _("HELEDELLE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_MACHAMP,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_LOW_KICK, MOVE_ROCK_SLIDE, MOVE_FACADE, MOVE_ATTRACT},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MACHAMP"),
                                        #elif FRENCH
                                            .nickname = _("MACKOGNEUR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_URSARING,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_PROTECT, MOVE_ROCK_SLIDE, MOVE_FACADE, MOVE_ATTRACT},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                            .nickname = _("URSARING"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_KINGLER,
                                            .heldItem = ITEM_PERSIM_BERRY,
                                            .moves = {MOVE_RETURN, MOVE_PROTECT, MOVE_CRABHAMMER, MOVE_ATTRACT},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("KINGLER"),
                                        #elif FRENCH
                                            .nickname = _("KRABBOSS"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_TYRANITAR,
                                            .heldItem = ITEM_PERSIM_BERRY,
                                            .moves = {MOVE_ROCK_SLIDE, MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_ATTRACT},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .defenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("TYRANITAR"),
                                        #elif FRENCH
                                            .nickname = _("TYRANOCIF"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_DRAGONITE,
                                            .heldItem = ITEM_PERSIM_BERRY,
                                            .moves = {MOVE_BODY_SLAM, MOVE_THUNDER_WAVE, MOVE_EARTHQUAKE, MOVE_ATTRACT},
                                            .hpEV = 252,
                                            .attackEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x80,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("DRAGONITE"),
                                        #elif FRENCH
                                            .nickname = _("DRACOLOSSE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("ISABELLE"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
                            .speechBefore = {EC_WORD_SOMEONE, EC_WORD_ON, EC_WORD_NOT, EC_WORD_OF, EC_MOVE2(HELPING_HAND), EC_WORD_EXCL, },
                            .speechWin = {EC_WORD_FORGIVE, EC_EMPTY_WORD, EC_WORD_BUT, EC_WORD_YOU_VE, EC_WORD_LOST, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_THAT_WAS, EC_EMPTY_WORD, EC_WORD_AN, EC_WORD_BATTLE, EC_WORD_UNBELIEVABLE, EC_WORD_ELLIPSIS, },
                            .speechAfter = {EC_WORD_CAN, EC_WORD_BE, EC_WORD_YOURS, EC_WORD_TEACHER, EC_WORD_OF, EC_WORD_POKEMON, },
                        #elif ITALIAN
                            .name = _("ISABELLE"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
                            .speechBefore = {EC_WORD_WIN, EC_WORD_LAY, EC_WORD_AS, EC_MOVE(YAWN), EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_SIMPLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_INCREDIBLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_PLEASE, EC_WORD_CONCEDE, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_TEACHER, EC_WORD_POKEMON},
                        #else //ENGLISH
                            .name = _("ALICIA"),
                            .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
                            .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_NEED, EC_WORD_A, EC_MOVE2(HELPING_HAND), EC_WORD_EXCL},
                            .speechWin = {EC_WORD_SORRY, EC_WORD_EXCL, EC_WORD_TOO, EC_WORD_BAD, EC_WORD_FOR, EC_WORD_YOU},
                            .speechLose = {EC_WORD_WHAT, EC_WORD_AN, EC_WORD_UNBELIEVABLE, EC_MOVE2(STRUGGLE), EC_WORD_THAT_WAS, EC_WORD_EXCL},
                            .speechAfter = {EC_WORD_I, EC_WORD_CAN, EC_WORD_BE, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_TEACHER},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_JOLTEON,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_ATTRACT, MOVE_SWAGGER},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("JOLTEON"),
                                        #elif FRENCH
                                            .nickname = _("VOLTALI"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_ALAKAZAM,
                                            .heldItem = ITEM_KINGS_ROCK,
                                            .moves = {MOVE_PSYCHIC, MOVE_ICE_PUNCH, MOVE_ATTRACT, MOVE_SWAGGER},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xA,
                                            .nickname = _("ALAKAZAM"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_STARMIE,
                                            .heldItem = ITEM_SCOPE_LENS,
                                            .moves = {MOVE_SURF, MOVE_PSYCHIC, MOVE_CONFUSE_RAY, MOVE_SWAGGER},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 1,
                                            .personality = 0xA,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("STARMIE"),
                                        #elif FRENCH
                                            .nickname = _("STAROSS"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_DUSCLOPS,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_PURSUIT, MOVE_PROTECT, MOVE_ATTRACT, MOVE_WILL_O_WISP},
                                            .hpEV = 252,
                                            .defenseEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x82,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("DUSCLOPS"),
                                        #elif FRENCH
                                            .nickname = _("TERACLOPE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_NINETALES,
                                            .heldItem = ITEM_WHITE_HERB,
                                            .moves = {MOVE_OVERHEAT, MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP, MOVE_ATTRACT},
                                            .hpEV = 6,
                                            .speedEV = 252,
                                            .spAttackEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xD2,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("NINETALES"),
                                        #elif FRENCH
                                            .nickname = _("FEUNARD"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_BANETTE,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_SHADOW_BALL, MOVE_FAINT_ATTACK, MOVE_ATTRACT, MOVE_WILL_O_WISP},
                                            .hpEV = 252,
                                            .defenseEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x85,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("BANETTE"),
                                        #elif FRENCH
                                            .nickname = _("BRANETTE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_expert/floor_1/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_expert/floor_1/collision.bin"),
                .trainerCoords = {COORDS_XY(7,10), COORDS_XY(7,14)},
                .trainerDirections = TRAINER_DIRS(DIR_SOUTH, DIR_NORTH),
                .trainerRanges = TRAINER_RANGE(3, 3),
            }
        },
    [2] =
        {
            .trainerNum1 = 61,
            .trainerNum2 = 62,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("GREGOIRE"),
                            .facilityClass = FACILITY_CLASS_EXPERT_M,
                            .speechBefore = {EC_WORD_OH_DEAR, EC_WORD_THIS, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_FOR, EC_WORD_HIM, },
                            .speechWin = {EC_WORD_SHAKE, EC_EMPTY_WORD, EC_WORD_WHERE, EC_WORD_VICTORY, EC_WORD_EASY, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_OH_DEAR, EC_WORD_ELLIPSIS, EC_WORD_UPBEAT, EC_WORD_ELLIPSIS, EC_WORD_FORGIVE, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_HER, EC_EMPTY_WORD, EC_WORD_GRANDMOTHER, EC_WORD_IS, EC_WORD_COOL, EC_WORD_QUES, },
                        #elif ITALIAN
                            .name = _("TERRENCE"),
                            .facilityClass = FACILITY_CLASS_EXPERT_M,
                            .speechBefore = {EC_WORD_OFF, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_EXCL},
                            .speechWin = {EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_BORED, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_SINCE, EC_WORD_GRANDMOTHER, EC_WORD_IS, EC_WORD_VERY, EC_WORD_STRONG, EC_WORD_QUES},
                        #else //ENGLISH
                            .name = _("TERRENCE"),
                            .facilityClass = FACILITY_CLASS_EXPERT_M,
                            .speechBefore = {EC_WORD_OH_DEAR, EC_WORD_THIS, EC_WORD_MATCH, EC_WORD_IS, EC_WORD_FOR, EC_WORD_YOU},
                            .speechWin = {EC_WORD_OH_DEAR, EC_WORD_DID, EC_WORD_YOU, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_QUES},
                            .speechLose = {EC_WORD_OH_DEAR, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SORRY, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_IS, EC_WORD_YOUR, EC_WORD_GRANDMOTHER, EC_WORD_STRONG, EC_WORD_QUES, EC_EMPTY_WORD},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_WOBBUFFET,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_MIRROR_COAT, MOVE_COUNTER, MOVE_SAFEGUARD, MOVE_ENCORE},
                                            .hpEV = 250,
                                            .defenseEV = 130,
                                            .spDefenseEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x94,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("WOBBUFFET"),
                                        #elif FRENCH
                                            .nickname = _("QULBUTOKE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_EXPLOUD,
                                            .heldItem = ITEM_CHESTO_BERRY,
                                            .moves = {MOVE_HYPER_VOICE, MOVE_COUNTER, MOVE_REST, MOVE_ROCK_SLIDE},
                                            .hpEV = 250,
                                            .defenseEV = 130,
                                            .spDefenseEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x85,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("EXPLOUD"),
                                        #elif FRENCH
                                            .nickname = _("BROUHABAM"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_CROBAT,
                                            .heldItem = ITEM_KINGS_ROCK,
                                            .moves = {MOVE_MEAN_LOOK, MOVE_CONFUSE_RAY, MOVE_AERIAL_ACE, MOVE_TOXIC},
                                            .hpEV = 250,
                                            .defenseEV = 130,
                                            .spDefenseEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("CROBAT"),
                                        #elif FRENCH
                                            .nickname = _("NOSTENFER"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_DUGTRIO,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_DOUBLE_TEAM, MOVE_PROTECT, MOVE_RETURN, MOVE_SLUDGE_BOMB},
                                            .hpEV = 6,
                                            .attackEV = 252,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 1,
                                            .personality = 0xD,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("DUGTRIO"),
                                        #elif FRENCH
                                            .nickname = _("TRIOPIKEUR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_ELECTRODE,
                                            .heldItem = ITEM_PETAYA_BERRY,
                                            .moves = {MOVE_TORMENT, MOVE_MIRROR_COAT, MOVE_THUNDERBOLT, MOVE_LIGHT_SCREEN},
                                            .hpEV = 252,
                                            .defenseEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x5,
                                            .nickname = _("ELECTRODE"),
                                            .friendship = 0,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_GENGAR,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_CONFUSE_RAY, MOVE_MEAN_LOOK, MOVE_GIGA_DRAIN, MOVE_WILL_O_WISP},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spDefenseEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x14,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("GENGAR"),
                                        #elif FRENCH
                                            .nickname = _("ECTOPLASMA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("CARLOTTA"),
                            .facilityClass = FACILITY_CLASS_EXPERT_F,
                            .speechBefore = {EC_WORD_YOU, EC_WORD_COME, EC_WORD_EVEN_SO, EC_WORD_FEELING, EC_WORD_PARTY, EC_WORD_QUES, },
                            .speechWin = {EC_WORD_OH_DEAR, EC_WORD_FEELING, EC_WORD_PARTY, EC_WORD_IS, EC_WORD_PLUS, EC_WORD_LATE, },
                            .speechLose = {EC_WORD_YOU_RE, EC_EMPTY_WORD, EC_WORD_DISAPPOINTED, EC_WORD_QUES, EC_WORD_FORGIVE, EC_WORD_ELLIPSIS, },
                            .speechAfter = {EC_WORD_YOURS, EC_EMPTY_WORD, EC_WORD_GRANDFATHER, EC_WORD_IS, EC_WORD_COOL, EC_WORD_QUES, },
                        #elif ITALIAN
                            .name = _("EDVIGE"),
                            .facilityClass = FACILITY_CLASS_EXPERT_F,
                            .speechBefore = {EC_WORD_WIN, EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_LATER, EC_WORD_PLAYS, EC_WORD_TO, EC_WORD_SILKY, EC_WORD_PARTY, EC_WORD_QUES},
                            .speechLose = {EC_WORD_SORRY, EC_WORD_JUST, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_DISAPPOINT, EC_WORD_EXCL},
                            .speechAfter = {EC_WORD_EVER, EC_WORD_GRANDFATHER, EC_WORD_IS, EC_WORD_VERY, EC_WORD_STRONG, EC_WORD_QUES},
                        #else //ENGLISH
                            .name = _("CARLOTTA"),
                            .facilityClass = FACILITY_CLASS_EXPERT_F,
                            .speechBefore = {EC_WORD_OH_DEAR, EC_WORD_I, EC_WORD_WILL, EC_WORD_WIN, EC_WORD_FOR, EC_WORD_YOU},
                            .speechWin = {EC_WORD_OH_DEAR, EC_WORD_WE, EC_WORD_HAVE, EC_WORD_A, EC_WORD_PARTY, EC_WORD_LATER},
                            .speechLose = {EC_WORD_OH_DEAR, EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_TO, EC_WORD_DISAPPOINT, EC_WORD_YOU},
                            .speechAfter = {EC_WORD_IS, EC_WORD_YOUR, EC_WORD_GRANDFATHER, EC_WORD_COOL, EC_WORD_QUES, EC_EMPTY_WORD},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_LAPRAS,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_SURF, MOVE_ICE_BEAM, MOVE_PERISH_SONG, MOVE_SING},
                                            .hpEV = 250,
                                            .defenseEV = 130,
                                            .spDefenseEV = 130,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x82,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("LAPRAS"),
                                        #elif FRENCH
                                            .nickname = _("LOKHLASS"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_ABSOL,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_PERISH_SONG, MOVE_DOUBLE_EDGE, MOVE_PROTECT, MOVE_TORMENT},
                                            .hpEV = 252,
                                            .defenseEV = 6,
                                            .speedEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x8A,
                                            .nickname = _("ABSOL"),
                                            .friendship = 0,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_ALTARIA,
                                            .heldItem = ITEM_KINGS_ROCK,
                                            .moves = {MOVE_PERISH_SONG, MOVE_PROTECT, MOVE_DRAGON_CLAW, MOVE_FIRE_BLAST},
                                            .hpEV = 252,
                                            .spAttackEV = 6,
                                            .spDefenseEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x0,
                                            .nickname = _("ALTARIA"),
                                            .friendship = 0,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_DEWGONG,
                                            .heldItem = ITEM_CHESTO_BERRY,
                                            .moves = {MOVE_ICE_BEAM, MOVE_SIGNAL_BEAM, MOVE_REST, MOVE_PERISH_SONG},
                                            .hpEV = 252,
                                            .speedEV = 252,
                                            .spAttackEV = 6,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x14,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("DEWGONG"),
                                        #elif FRENCH
                                            .nickname = _("LAMANTINE"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_POLITOED,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_HYDRO_PUMP, MOVE_BLIZZARD, MOVE_MIND_READER, MOVE_PERISH_SONG},
                                            .hpEV = 252,
                                            .spAttackEV = 6,
                                            .spDefenseEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 1,
                                            .personality = 0x14,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("POLITOED"),
                                        #elif FRENCH
                                            .nickname = _("TARPAUD"),
                                        #endif
                                            .friendship = 0,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_MAROWAK,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_PERISH_SONG, MOVE_EARTHQUAKE, MOVE_COUNTER, MOVE_PROTECT},
                                            .hpEV = 252,
                                            .speedEV = 6,
                                            .spDefenseEV = 252,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 1,
                                            .personality = 0x17,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MAROWAK"),
                                        #elif FRENCH
                                            .nickname = _("OSSATUEUR"),
                                        #endif
                                            .friendship = 0,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_expert/floor_2/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_expert/floor_2/collision.bin"),
                .trainerCoords = {COORDS_XY(7,6), COORDS_XY(7,10)},
                .trainerDirections = TRAINER_DIRS(DIR_SOUTH, DIR_NORTH),
                .trainerRanges = TRAINER_RANGE(3, 3),
            }
        },
    [3] =
        {
            .trainerNum1 = 63,
            .trainerNum2 = 64,
            .trainers =
                {
                    [0] =
                        {
                        #if FRENCH
                            .name = _("JACKIE"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
                            .speechBefore = {EC_WORD_WAAAH, EC_EMPTY_WORD, EC_WORD_IT_S, EC_WORD_RATHER, EC_WORD_EXCITING, EC_WORD_EXCL, },
                            .speechWin = {EC_WORD_WAAAH, EC_EMPTY_WORD, EC_WORD_WHAT, EC_EMPTY_WORD, EC_WORD_HAPPINESS, EC_WORD_EXCL, },
                            .speechLose = {EC_WORD_WAAAH, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SAD, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechAfter = {EC_WORD_WAAAH, EC_EMPTY_WORD, EC_WORD_NOT, EC_WORD_LAY, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                        #elif ITALIAN
                            .name = _("NORA"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
                            .speechBefore = {EC_WORD_ENTERTAINING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_HAPPINESS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechLose = {EC_WORD_ON, EC_WORD_IS, EC_WORD_SAD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechAfter = {EC_WORD_WROOOAAR_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
                        #else //ENGLISH
                            .name = _("NORA"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
                            .speechBefore = {EC_WORD_WAAAH, EC_WORD_THIS, EC_WORD_IS, EC_WORD_SO, EC_WORD_EXCITING, EC_WORD_EXCL},
                            .speechWin = {EC_WORD_WAAAH, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_HAPPY, EC_WORD_I, EC_WORD_WON},
                            .speechLose = {EC_WORD_WAAAH, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SAD, EC_WORD_I, EC_WORD_LOST},
                            .speechAfter = {EC_WORD_WAAAH, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_GO, EC_WORD_AWAY, EC_WORD_EXCL},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_FORRETRESS,
                                            .heldItem = ITEM_QUICK_CLAW,
                                            .moves = {MOVE_EXPLOSION, MOVE_EARTHQUAKE, MOVE_ATTRACT, MOVE_SPIKES},
                                            .hpEV = 110,
                                            .attackEV = 200,
                                            .spDefenseEV = 200,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("FORRETRESS"),
                                        #elif FRENCH
                                            .nickname = _("FORETRESS"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_ELECTRODE,
                                            .heldItem = ITEM_SALAC_BERRY,
                                            .moves = {MOVE_EXPLOSION, MOVE_THUNDERBOLT, MOVE_SWIFT, MOVE_LIGHT_SCREEN},
                                            .attackEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 1,
                                            .personality = 0xC,
                                            .nickname = _("ELECTRODE"),
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_EXEGGUTOR,
                                            .heldItem = ITEM_SHELL_BELL,
                                            .moves = {MOVE_EXPLOSION, MOVE_HYPNOSIS, MOVE_PSYCHIC, MOVE_SOLAR_BEAM},
                                            .attackEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x7F,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("EXEGGUTOR"),
                                        #elif FRENCH
                                            .nickname = _("NOADKOKO"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_DUSCLOPS,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_IMPRISON, MOVE_PROTECT, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
                                            .hpEV = 110,
                                            .defenseEV = 200,
                                            .spDefenseEV = 200,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x93,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("DUSCLOPS"),
                                        #elif FRENCH
                                            .nickname = _("TERACLOPE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_NINETALES,
                                            .heldItem = ITEM_WHITE_HERB,
                                            .moves = {MOVE_IMPRISON, MOVE_PROTECT, MOVE_OVERHEAT, MOVE_CONFUSE_RAY},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0xF,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("NINETALES"),
                                        #elif FRENCH
                                            .nickname = _("FEUNARD"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_BANETTE,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_IMPRISON, MOVE_PROTECT, MOVE_THUNDERBOLT, MOVE_THUNDER},
                                            .hpEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x96,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("BANETTE"),
                                        #elif FRENCH
                                            .nickname = _("BRANETTE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                    [1] =
                        {
                        #if FRENCH
                            .name = _("IGNACE"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
                            .speechBefore = {EC_WORD_WAHAHAHA, EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST, EC_EMPTY_WORD, EC_EMPTY_WORD, },
                            .speechWin = {EC_WORD_WHOAH, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_AWESOME, EC_WORD_AND, EC_WORD_COOL, },
                            .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_COOL, EC_WORD_WILL_BE_HERE, EC_WORD_ALL, EC_WORD_EXCL, },
                            .speechAfter = {EC_WORD_EHEHE, EC_WORD_THIS, EC_WORD_FIGHTING, EC_WORD_WAS, EC_WORD_AWFUL, EC_WORD_EXCL, },
                        #elif ITALIAN
                            .name = _("MICHELINO"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
                            .speechBefore = {EC_WORD_SAID, EC_WORD_AS_IF, EC_WORD_STOP, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
                            .speechWin = {EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_COOL, EC_WORD_ELLIPSIS},
                            .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_JUST, EC_WORD_STRONG},
                            .speechAfter = {EC_WORD_MISS, EC_WORD_THIN, EC_WORD_FIGHTING, EC_WORD_LISTEN, EC_WORD_POKEMON, EC_WORD_EXCL},
                        #else //ENGLISH
                            .name = _("GAV"),
                            .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
                            .speechBefore = {EC_WORD_WAHAHAHA, EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_STOP, EC_WORD_ME, EC_WORD_EXCL},
                            .speechWin = {EC_WORD_WOWEE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_AWESOME, EC_WORD_COOL},
                            .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_COOL, EC_WORD_AT, EC_WORD_ALL, EC_WORD_EXCL},
                            .speechAfter = {EC_WORD_HEHEHE, EC_WORD_THAT_WAS, EC_WORD_AN, EC_WORD_AWESOME, EC_WORD_BATTLE, EC_WORD_EXCL},
                        #endif
                            .mons =
                                {
                                    [0] =
                                        {
                                            .species = SPECIES_SALAMENCE,
                                            .heldItem = ITEM_SHELL_BELL,
                                            .moves = {MOVE_ROCK_SLIDE, MOVE_FLAMETHROWER, MOVE_DRAGON_CLAW, MOVE_AERIAL_ACE},
                                            .attackEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x95,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("SALAMENCE"),
                                        #elif FRENCH
                                            .nickname = _("DRATTAK"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [1] =
                                        {
                                            .species = SPECIES_GENGAR,
                                            .heldItem = ITEM_LUM_BERRY,
                                            .moves = {MOVE_PSYCHIC, MOVE_GIGA_DRAIN, MOVE_WILL_O_WISP, MOVE_DESTINY_BOND},
                                            .speedEV = 255,
                                            .spAttackEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x8C,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("GENGAR"),
                                        #elif FRENCH
                                            .nickname = _("ECTOPLASMA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [2] =
                                        {
                                            .species = SPECIES_GYARADOS,
                                            .heldItem = ITEM_BRIGHT_POWDER,
                                            .moves = {MOVE_DRAGON_DANCE, MOVE_HYPER_BEAM, MOVE_BITE, MOVE_EARTHQUAKE},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("GYARADOS"),
                                        #elif FRENCH
                                            .nickname = _("LEVIATOR"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [3] =
                                        {
                                            .species = SPECIES_GENGAR,
                                            .heldItem = ITEM_SALAC_BERRY,
                                            .moves = {MOVE_EXPLOSION, MOVE_MEAN_LOOK, MOVE_SHADOW_BALL, MOVE_CONFUSE_RAY},
                                            .attackEV = 255,
                                            .speedEV = 255,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x3,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("GENGAR"),
                                        #elif FRENCH
                                            .nickname = _("ECTOPLASMA"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [4] =
                                        {
                                            .species = SPECIES_DUSCLOPS,
                                            .heldItem = ITEM_LEFTOVERS,
                                            .moves = {MOVE_MEAN_LOOK, MOVE_CONFUSE_RAY, MOVE_WILL_O_WISP, MOVE_SHADOW_BALL},
                                            .hpEV = 110,
                                            .defenseEV = 200,
                                            .spDefenseEV = 200,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x14,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("DUSCLOPS"),
                                        #elif FRENCH
                                            .nickname = _("TERACLOPE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                    [5] =
                                        {
                                            .species = SPECIES_MISDREAVUS,
                                            .heldItem = ITEM_FOCUS_BAND,
                                            .moves = {MOVE_MEAN_LOOK, MOVE_CONFUSE_RAY, MOVE_PERISH_SONG, MOVE_SHADOW_BALL},
                                            .hpEV = 180,
                                            .defenseEV = 180,
                                            .spDefenseEV = 150,
                                            .otId = TRAINER_HILL_OTID,
                                            .hpIV = MAX_PER_STAT_IVS,
                                            .attackIV = MAX_PER_STAT_IVS,
                                            .defenseIV = MAX_PER_STAT_IVS,
                                            .speedIV = MAX_PER_STAT_IVS,
                                            .spAttackIV = MAX_PER_STAT_IVS,
                                            .spDefenseIV = MAX_PER_STAT_IVS,
                                            .abilityNum = 0,
                                            .personality = 0x85,
                                        #if ENGLISH || ITALIAN
                                            .nickname = _("MISDREAVUS"),
                                        #elif FRENCH
                                            .nickname = _("FEUFOREVE"),
                                        #endif
                                            .friendship = MAX_FRIENDSHIP,
                                        },
                                },
                        },
                },
            .map = {
                .metatileData = INCBIN_U8("graphics/trainer_hill/maps_expert/floor_3/metatiles.bin"),
                .collisionData = INCBIN_U16("graphics/trainer_hill/maps_expert/floor_3/collision.bin"),
                .trainerCoords = {COORDS_XY(7,6), COORDS_XY(7,10)},
                .trainerDirections = TRAINER_DIRS(DIR_SOUTH, DIR_NORTH),
                .trainerRanges = TRAINER_RANGE(3, 3),
            }
        },
};

#undef COORDS_XY
#undef TRAINER_DIRS
#undef TRAINER_RANGE
