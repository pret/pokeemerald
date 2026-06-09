const struct BattleFrontierTrainer gBattleFrontierTrainers[FRONTIER_TRAINERS_COUNT] =
{
    [FRONTIER_TRAINER_BRADY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("UGO"),
        .speechBefore = {EC_WORD_I, EC_WORD_ISN_T, EC_WORD_ON, EC_WORD_NOT, EC_WORD_LOSE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_STRONG, EC_WORD_ELLIPSIS, EC_WORD_HUH_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BUT, EC_EMPTY_WORD, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_IMPOSSIBLE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Brady
    },
    [FRONTIER_TRAINER_CONNER] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("GERARD"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_FEAR, EC_WORD_OF, EC_WORD_LOSE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_LIKE, EC_WORD_NOT, EC_WORD_LOSE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Conner
    },
    [FRONTIER_TRAINER_BRADLEY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("PIERROT"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_HIM, EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_TODAY, EC_WORD_QUES},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_EXCL, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_TO_US, EC_WORD_AREN_T, EC_WORD_GIVES, EC_WORD_DATE, EC_WORD_TOMORROW, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Bradley
    },
    [FRONTIER_TRAINER_CYBIL] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("CECILE"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_ISN_T, EC_WORD_WHO_WAS, EC_WORD_DIDN_T, EC_WORD_NOT, EC_WORD_FEAR},
        .speechWin = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_MAGAZINE, EC_WORD_OF, EC_WORD_FASHION, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_LADY, EC_EMPTY_WORD, EC_WORD_THIN, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Cybil
    },
    [FRONTIER_TRAINER_RODETTE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("ODILE"),
        .speechBefore = {EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_EXCITING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_UNBELIEVABLE, EC_WORD_I_AM, EC_WORD_INVINCIBLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_INVINCIBLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rodette
    },
    [FRONTIER_TRAINER_PEGGY] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("PEGGY"),
        .speechBefore = {EC_WORD_LIKELY_TO, EC_WORD_BE, EC_WORD_SHREDDED, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_YES, EC_WORD_IT_S, EC_WORD_ME, EC_WORD_MISS, EC_WORD_HEROINE},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SAD, EC_WORD_NOW, EC_WORD_ELLIPSIS, EC_WORD_HELLO, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Peggy
    },
    [FRONTIER_TRAINER_KEITH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("MATHIEU"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_PLUS, EC_WORD_NOTHING, EC_WORD_EVEN_SO, EC_WORD_LEARN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_RECOMMEND, EC_EMPTY_WORD, EC_WORD_UGLY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_BADLY, EC_WORD_SKILLED, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Keith
    },
    [FRONTIER_TRAINER_GRAYSON] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("PAOLO"),
        .speechBefore = {EC_WORD_A, EC_WORD_FIGHTING, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_A, EC_WORD_CHILD_S_PLAY},
        .speechWin = {EC_WORD_GO, EC_WORD_EXCL, EC_WORD_EVEN_SO, EC_WORD_A_LOT, EC_WORD_LATER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_COUPLE, EC_EMPTY_WORD, EC_WORD_YOU_RE, EC_WORD_SERIOUSLY, EC_WORD_GETS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Grayson
    },
    [FRONTIER_TRAINER_GLENN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("GLENN"),
        .speechBefore = {EC_WORD_COOL, EC_WORD_OR, EC_WORD_NOT, EC_EMPTY_WORD, EC_WORD_COOL, EC_WORD_QUES},
        .speechWin = {EC_WORD_HIYAH, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_RECOMMEND, EC_WORD_COOL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WROOOAAR_EXCL, EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_SO, EC_WORD_COOL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Glenn
    },
    [FRONTIER_TRAINER_LILIANA] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("LILIANA"),
        .speechBefore = {EC_WORD_SURRENDER, EC_WORD_QUES, EC_WORD_NO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WEAK, EC_WORD_QUES, EC_WORD_ME, EC_WORD_QUES, EC_WORD_NO, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_TERRIBLE, EC_WORD_WILL, EC_EMPTY_WORD, EC_WORD_GIVE_UP, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Liliana
    },
    [FRONTIER_TRAINER_ELISE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ELISE"),
        .speechBefore = {EC_WORD_DAUGHTER, EC_WORD_STRATEGY, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_OVERWHELMING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_FATHER, EC_WORD_EXCL, EC_WORD_I_VE, EC_WORD_WINS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_FORGIVE, EC_WORD_FATHER, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Elise
    },
    [FRONTIER_TRAINER_ZOEY] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ZARA"),
        .speechBefore = {EC_WORD_EXCUSE_ME, EC_WORD_YOURS, EC_WORD_GUTSY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL_EXCL, EC_WORD_THANK_YOU, EC_EMPTY_WORD, EC_WORD_A_LOT, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_RATHER, EC_WORD_SERIOUS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Zoey
    },
    [FRONTIER_TRAINER_MANUEL] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("ULRICH"),
        .speechBefore = {EC_WORD_ME, EC_WORD_ELLIPSIS, EC_WORD_LOSE, EC_WORD_QUES, EC_WORD_PREPOSTEROUS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_NATURAL, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_WORD_WINS},
        .speechLose = {EC_WORD_SIGH, EC_WORD_SIGH, EC_WORD_LOST, EC_WORD_ELLIPSIS, EC_WORD_MOTHER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Manuel
    },
    [FRONTIER_TRAINER_RUSS] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("URBAIN"),
        .speechBefore = {EC_WORD_THEY, EC_WORD_IN, EC_WORD_THAN, EC_WORD_FOREVER, EC_WORD_WHO_IS, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_IT_S, EC_WORD_FEELING, EC_WORD_PARTY, EC_WORD_MOOD, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WELL_THEN, EC_WORD_ELLIPSIS, EC_WORD_WITHOUT, EC_EMPTY_WORD, EC_MOVE(GRUDGE), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Russ
    },
    [FRONTIER_TRAINER_DUSTIN] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("DUSTIN"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_THEY, EC_WORD_ARE, EC_WORD_COOL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_WIN, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_COOL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_ADORE, EC_WORD_LOSE, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_COOL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Dustin
    },
    [FRONTIER_TRAINER_TINA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("TINA"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_YOU_VE, EC_WORD_A, EC_EMPTY_WORD, EC_MOVE2(SWEET_KISS), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_A, EC_MOVE2(SWEET_KISS), EC_WORD_OF, EC_EMPTY_WORD, EC_POKEMON_NATIONAL(JYNX), EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT, EC_WORD_A, EC_MOVE2(MEGA_KICK), EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Tina
    },
    [FRONTIER_TRAINER_GILLIAN1] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("REINE"),
        .speechBefore = {EC_WORD_FEELING, EC_WORD_GOURMET, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_TRENDY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_TRENDY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_WHEN, EC_WORD_YOURS, EC_WORD_NEXT, EC_WORD_FIGHTING, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Gillian
    },
    [FRONTIER_TRAINER_ZOE] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("ZOE"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_LISTEN, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_TOUGH, EC_WORD_QUES},
        .speechWin = {EC_WORD_I_VE, EC_WORD_TRUST, EC_WORD_AFTER, EC_WORD_FEELING, EC_WORD_LIFE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_FEAR, EC_WORD_FOR, EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zoe
    },
    [FRONTIER_TRAINER_CHEN] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("CHEN"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_READY, EC_WORD_FOR, EC_WORD_THE, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_READY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_DAUGHTER, EC_EMPTY_WORD, EC_MOVE(FOCUS_ENERGY), EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Chen
    },
    [FRONTIER_TRAINER_AL] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("AL"),
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_VERY, EC_WORD_TOUGH, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_PLUS, EC_EMPTY_WORD, EC_WORD_TOUGH, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WON, EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_FABULOUS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Al
    },
    [FRONTIER_TRAINER_MITCH] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("MITCH"),
        .speechBefore = {EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_IS, EC_WORD_WITH, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IF, EC_WORD_ENOUGH, EC_WORD_FOR, EC_EMPTY_WORD, EC_WORD_TODAY, EC_WORD_QUES},
        .speechLose = {EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_I_VE, EC_WORD_TOTALLY, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Mitch
    },
    [FRONTIER_TRAINER_ANNE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("ESTELLE"),
        .speechBefore = {EC_WORD_NOT, EC_WORD_THE, EC_WORD_TIME, EC_WORD_COME, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN},
        .speechWin = {EC_WORD_DAUGHTER, EC_WORD_JOY, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_OVERWHELMING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_SAD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anne
    },
    [FRONTIER_TRAINER_ALIZE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("SOLENE"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_A, EC_WORD_CUTE_CHARM, EC_WORD_AND, EC_WORD_I_AM, EC_WORD_OVERWHELMING},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_CHILD_S_PLAY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_WEAK, EC_WORD_BUT, EC_WORD_I_VE, EC_WORD_A, EC_WORD_CUTE_CHARM},
        .monSet = gBattleFrontierTrainerMons_Alize
    },
    [FRONTIER_TRAINER_LAUREN] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("LAUREN"),
        .speechBefore = {EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_THE, EC_EMPTY_WORD, EC_WORD_SPRING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_MISS, EC_WORD_SUMMER, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_LAY, EC_WORD_BETTER},
        .speechLose = {EC_WORD_OLD, EC_WORD_EXCL, EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Lauren
    },
    [FRONTIER_TRAINER_KIPP] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("ROMAIN"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_EMPTY_WORD, EC_WORD_WILL, EC_WORD_AFTER, EC_WORD_MISS, EC_WORD_WATER},
        .speechWin = {EC_WORD_YUP, EC_WORD_EXCL_EXCL, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_A, EC_EMPTY_WORD, EC_MOVE(WHIRLPOOL), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kipp
    },
    [FRONTIER_TRAINER_JASON] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("YOURI"),
        .speechBefore = {EC_WORD_EXCUSE_ME, EC_WORD_HER, EC_WORD_STRATEGY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT_S, EC_WORD_IF, EC_WORD_HER, EC_EMPTY_WORD, EC_WORD_STRATEGY, EC_WORD_QUES},
        .speechLose = {EC_WORD_SHE_IS, EC_WORD_SUPER, EC_WORD_HIP_AND, EC_WORD_HER, EC_WORD_STRATEGY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jason
    },
    [FRONTIER_TRAINER_JOHN] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("JOHN"),
        .speechBefore = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_WILL_BE_HERE, EC_EMPTY_WORD, EC_MOVE2(RECYCLE), EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_VERY, EC_WORD_YET, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_HUSTLE, EC_WORD_TODAY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_John
    },
    [FRONTIER_TRAINER_ANN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("LOTTE"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_EXCITING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YUP, EC_WORD_EXCL_EXCL, EC_WORD_APPRECIATE, EC_WORD_OF, EC_WORD_WIN, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_IN, EC_WORD_CRIES, EC_WORD_ELLIPSIS, EC_WORD_SIGH, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ann
    },
    [FRONTIER_TRAINER_EILEEN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("MIREIA"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_EXCL, EC_WORD_OKAY, EC_WORD_QUES},
        .speechWin = {EC_WORD_WHAT, EC_WORD_AGE, EC_WORD_WHOM, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_MOVE(YAWN), EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Eileen
    },
    [FRONTIER_TRAINER_CARLIE] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ROSE"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_IN, EC_WORD_HOLIDAY, EC_WORD_WITH, EC_WORD_WHO_IS, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_IF, EC_WORD_BELONGS_TO, EC_WORD_BE, EC_EMPTY_WORD, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FEVER, EC_WORD_THAT, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Carlie
    },
    [FRONTIER_TRAINER_GORDON] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("GILLES"),
        .speechBefore = {EC_WORD_FEELING, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_EVEN_SO, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_EXCL, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NOTHING, EC_WORD_ISN_T, EC_WORD_WALKS, EC_EMPTY_WORD, EC_WORD_TODAY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Gordon
    },
    [FRONTIER_TRAINER_AYDEN] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("TOBY"),
        .speechBefore = {EC_WORD_GO, EC_WORD_EXCL, EC_WORD_COME, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_WANT, EC_WORD_OF, EC_WORD_MISS, EC_WORD_WATER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_VE, EC_WORD_REALLY, EC_WORD_COLD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ayden
    },
    [FRONTIER_TRAINER_MARCO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("TARIK"),
        .speechBefore = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_WILL_BE_HERE, EC_MOVE2(SURF), EC_WORD_IN, EC_WORD_WINTER},
        .speechWin = {EC_WORD_MEGA, EC_WORD_THE, EC_MOVE2(SURF), EC_WORD_IT_S, EC_WORD_COOL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_MAKE, EC_WORD_WILL_BE_HERE, EC_MOVE2(SURF), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Marco
    },
    [FRONTIER_TRAINER_CIERRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("CLARYS"),
        .speechBefore = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_OF, EC_WORD_FEELING, EC_MOVE2(DIVE), EC_WORD_EXCL},
        .speechWin = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ALSO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MY, EC_WORD_INNER_FOCUS, EC_WORD_IS, EC_WORD_OF, EC_WORD_WIN, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Cierra
    },
    [FRONTIER_TRAINER_MARCY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("MARCY"),
        .speechBefore = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_HASSLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_ARENA_TRAP, EC_WORD_EXCL_EXCL, EC_WORD_AHAHA, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THIS, EC_WORD_FIGHTING, EC_WORD_WAS, EC_EMPTY_WORD, EC_WORD_UGLY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Marcy
    },
    [FRONTIER_TRAINER_KATHY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("KATHY"),
        .speechBefore = {EC_WORD_I, EC_WORD_WINS, EC_WORD_ALL, EC_WORD_THE, EC_WORD_TIME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_AWESOME, EC_WORD_OF, EC_WORD_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_EH_QUES, EC_EMPTY_WORD, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kathy
    },
    [FRONTIER_TRAINER_PEYTON] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("VALERIO"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_FABULOUS, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_TRY, EC_WORD_OF, EC_WORD_WIN, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_LAY, EC_WORD_PLUS, EC_WORD_FABULOUS},
        .monSet = gBattleFrontierTrainerMons_Peyton
    },
    [FRONTIER_TRAINER_JULIAN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("JULIAN"),
        .speechBefore = {EC_WORD_LIKE, EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ME, EC_WORD_ALSO, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_FEELING, EC_EMPTY_WORD, EC_WORD_QUESTION, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_WHERE, EC_WORD_JOY, EC_WORD_WONDER, EC_WORD_HAVE, EC_WORD_MOOD, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Julian
    },
    [FRONTIER_TRAINER_QUINN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("ISIDORE"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_FABULOUS, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_INCREDIBLE, EC_EMPTY_WORD, EC_WORD_DREAM, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_AWFUL, EC_EMPTY_WORD, EC_MOVE(NIGHTMARE), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Quinn
    },
    [FRONTIER_TRAINER_HAYLEE] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("JULIA"),
        .speechBefore = {EC_WORD_I, EC_WORD_WHO_WAS, EC_WORD_SENSE, EC_EMPTY_WORD, EC_WORD_WEIRD, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_THE, EC_WORD_HAPPINESS, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_ANYWHERE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NEED, EC_WORD_OF, EC_MOVE2(REST), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Haylee
    },
    [FRONTIER_TRAINER_AMANDA] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("AMANDA"),
        .speechBefore = {EC_WORD_DAUGHTER, EC_WORD_FAMILY, EC_WORD_EVER, EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_AN, EC_WORD_JOY, EC_WORD_OF, EC_WORD_WIN, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_WILL, EC_WORD_EVEN_SO, EC_WORD_FEELING, EC_EMPTY_WORD, EC_WORD_HOME, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Amanda
    },
    [FRONTIER_TRAINER_STACY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("AIMEE"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_THAN, EC_WORD_WILL_BE_HERE, EC_WORD_APPEAL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_DOES, EC_WORD_AGREE, EC_WORD_WITH, EC_EMPTY_WORD, EC_WORD_ME, EC_WORD_QUES},
        .speechLose = {EC_WORD_AGREE, EC_WORD_OR, EC_WORD_NOT, EC_WORD_IS_IT_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stacy
    },
    [FRONTIER_TRAINER_RAFAEL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("RAFAEL"),
        .speechBefore = {EC_WORD_COME, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_VERSUS, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_GO, EC_WORD_EXCL, EC_WORD_WITHOUT, EC_EMPTY_WORD, EC_MOVE(GRUDGE), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HE_S, EC_WORD_RARE, EC_WORD_OF, EC_WORD_WIN, EC_WORD_VERSUS, EC_WORD_ME},
        .monSet = gBattleFrontierTrainerMons_Rafael
    },
    [FRONTIER_TRAINER_OLIVER] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("TANGUY"),
        .speechBefore = {EC_WORD_ME, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_HERE_IT_IS, EC_WORD_A, EC_WORD_WORK, EC_WORD_OF, EC_WORD_GENIUS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_BEST, EC_WORD_THAT, EC_EMPTY_WORD, EC_WORD_ME, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Oliver
    },
    [FRONTIER_TRAINER_PAYTON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("TERENCE"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_A, EC_WORD_EGG, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCUSE, EC_EMPTY_WORD, EC_WORD_PLAYS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_AN, EC_WORD_LOSS, EC_WORD_AWFUL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Payton
    },
    [FRONTIER_TRAINER_PAMELA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("PAMELA"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_FABULOUS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT_S, EC_WORD_UGLY, EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_UGLY, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Pamela
    },
    [FRONTIER_TRAINER_ELIZA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("ELIZA"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_WHO_IS, EC_WORD_CHILDREN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_HAPPY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FORGIVE, EC_WORD_ELLIPSIS, EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Eliza
    },
    [FRONTIER_TRAINER_MARISA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("MARISA"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_WHO_WAS, EC_WORD_WHEN_I_WIN, EC_EMPTY_WORD, EC_WORD_SERIOUSLY, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_SOMEONE, EC_WORD_IN, EC_WORD_DIDN_T, EC_WORD_FEELING, EC_WORD_PROMISE, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_A, EC_WORD_OTHER, EC_WORD_FIGHTING, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Marisa
    },
    [FRONTIER_TRAINER_LEWIS] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("SAMIR"),
        .speechBefore = {EC_WORD_I, EC_WORD_SEEK, EC_WORD_A, EC_WORD_BUG, EC_WORD_SCARY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_LOOKS, EC_WORD_EXCL, EC_WORD_A, EC_WORD_BUG, EC_WORD_SCARY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_A, EC_WORD_BUG, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_SCARY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Lewis
    },
    [FRONTIER_TRAINER_YOSHI] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("YOSHI"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_ARE, EC_WORD_LOVEY_DOVEY, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_IT_S, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MUCH, EC_WORD_WITH, EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_BUG},
        .monSet = gBattleFrontierTrainerMons_Yoshi
    },
    [FRONTIER_TRAINER_DESTIN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("BILAL"),
        .speechBefore = {EC_WORD_THE, EC_WORD_SHINE, EC_WORD_SMACK, EC_EMPTY_WORD, EC_WORD_TOO_STRONG, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_IN, EC_MOVE(OVERHEAT), EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_EXCL, EC_WORD_GIVE_ME, EC_WORD_A_LITTLE, EC_WORD_WONDER, EC_WORD_WATER},
        .monSet = gBattleFrontierTrainerMons_Destin
    },
    [FRONTIER_TRAINER_KEON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("BRUCE"),
        .speechBefore = {EC_WORD_FORGIVE, EC_WORD_ELLIPSIS, EC_WORD_HERE_I_COME, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FORGIVE, EC_EMPTY_WORD, EC_WORD_FOR, EC_WORD_DAUGHTER, EC_MOVE(FOCUS_ENERGY), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Keon
    },
    [FRONTIER_TRAINER_STUART] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("STUART"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_FIGHTING, EC_WORD_BELONGS_TO, EC_WORD_BE, EC_WORD_HOT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_MASTER, EC_WORD_WILL_BE_HERE, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_SO, EC_EMPTY_WORD, EC_WORD_COOL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Stuart
    },
    [FRONTIER_TRAINER_NESTOR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("NESTOR"),
        .speechBefore = {EC_WORD_SIBLINGS, EC_WORD_TIRED, EC_WORD_NOT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_INVINCIBLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_IMPORTANT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Nestor
    },
    [FRONTIER_TRAINER_DERRICK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("ARNAUD"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_ALSO, EC_WORD_WILL_BE_HERE, EC_MOVE2(MEDITATE), EC_WORD_QUES},
        .speechWin = {EC_WORD_THE, EC_MOVE2(MEDITATE), EC_WORD_IT_S, EC_WORD_RECOMMEND, EC_WORD_COOL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FEELING, EC_MOVE2(CALM_MIND), EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_MISS, EC_WORD_BE},
        .monSet = gBattleFrontierTrainerMons_Derrick
    },
    [FRONTIER_TRAINER_BRYSON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("LUCIO"),
        .speechBefore = {EC_WORD_OUR, EC_WORD_MOVE, EC_WORD_IT_S, EC_EMPTY_WORD, EC_MOVE2(POISON_POWDER), EC_WORD_EXCL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_FEELING, EC_MOVE2(POISON_POWDER), EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THE, EC_MOVE2(COTTON_SPORE), EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_USELESS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Bryson
    },
    [FRONTIER_TRAINER_CLAYTON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("AUBIN"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ELLIPSIS, EC_WORD_LOST, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_MY, EC_EMPTY_WORD, EC_WORD_POKENAV, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_I_AM, EC_WORD_LOST, EC_WORD_WITHOUT, EC_WORD_MY, EC_WORD_POKENAV, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Clayton
    },
    [FRONTIER_TRAINER_TRENTON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("LOIC"),
        .speechBefore = {EC_WORD_IT, EC_WORD_OF, EC_WORD_MISS, EC_WORD_WATER, EC_WORD_NO, EC_WORD_QUES},
        .speechWin = {EC_WORD_MMM, EC_WORD_ELLIPSIS, EC_WORD_YOU, EC_WORD_IN, EC_WORD_ON, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_WILL_BE_HERE, EC_WORD_SHOPPING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Trenton
    },
    [FRONTIER_TRAINER_JENSON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("FLO"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_FIERY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_BAD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THIS_IS_IT_EXCL, EC_WORD_LOSS, EC_WORD_WHO_WAS, EC_EMPTY_WORD, EC_WORD_DOWNCAST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jenson
    },
    [FRONTIER_TRAINER_WESLEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("BRODY"),
        .speechBefore = {EC_POKEMON_NATIONAL(MEW), EC_POKEMON_NATIONAL(MEW), EC_WORD_IT_S, EC_WORD_MY, EC_WORD_CRY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_MEAN, EC_WORD_BUT, EC_WORD_ANY, EC_WORD_EXCL},
        .speechLose = {EC_POKEMON_NATIONAL(MEW), EC_WORD_EXCL, EC_POKEMON_NATIONAL(MEW), EC_WORD_EXCL_EXCL, EC_POKEMON_NATIONAL(MEW), EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Wesley
    },
    [FRONTIER_TRAINER_ANTON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("ANTON"),
        .speechBefore = {EC_WORD_APOLOGIZE, EC_WORD_EVEN_SO, EC_WORD_FEELING, EC_EMPTY_WORD, EC_MOVE2(FIRE_BLAST), EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_I_AM, EC_WORD_THE, EC_EMPTY_WORD, EC_WORD_BEST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_GIVE_ME, EC_WORD_A, EC_WORD_SMALL, EC_MOVE2(HELPING_HAND), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anton
    },
    [FRONTIER_TRAINER_LAWSON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("ELIOT"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_BOY, EC_WORD_COOL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NOT, EC_WORD_COOL, EC_WORD_WILL_BE_HERE, EC_EMPTY_WORD, EC_WORD_ALL, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ELLIPSIS, EC_WORD_ANGRY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lawson
    },
    [FRONTIER_TRAINER_SAMMY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("SAMI"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_FEELING, EC_WORD_PARTY, EC_WORD_IT_S, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_INCREDIBLE, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_UNBELIEVABLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FUNNY, EC_WORD_OF, EC_WORD_PARTY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Sammy
    },
    [FRONTIER_TRAINER_ARNIE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("ARNIE"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_RIVAL, EC_WORD_AND, EC_WORD_I_AM, EC_WORD_THE, EC_WORD_NO_1},
        .speechWin = {EC_WORD_HEHE, EC_WORD_I_AM, EC_WORD_INVINCIBLE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARRGH, EC_WORD_EXCL, EC_WORD_WILL, EC_WORD_ACCEPT, EC_WORD_FEELING, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Arnie
    },
    [FRONTIER_TRAINER_ADRIAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("ADRIAN"),
        .speechBefore = {EC_WORD_YAHOO, EC_WORD_EXCL, EC_WORD_YAHOO, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_THANK_YOU, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GOOD_BYE, EC_WORD_EXCL, EC_WORD_GOOD_BYE, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Adrian
    },
    [FRONTIER_TRAINER_TRISTAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("GILDAS"),
        .speechBefore = {EC_WORD_HELLO, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_GREAT, EC_WORD_EXCL, EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_WILL_BE_HERE, EC_WORD_FIGHTING},
        .monSet = gBattleFrontierTrainerMons_Tristan
    },
    [FRONTIER_TRAINER_JULIANA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("JULIANA"),
        .speechBefore = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_RECOMMEND, EC_WORD_OF, EC_WORD_SHOPPING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WANT, EC_WORD_A, EC_WORD_PLUSH_DOLL, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WANT, EC_WORD_RATHER, EC_WORD_A, EC_WORD_PLUSH_DOLL, EC_WORD_POKEMON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Juliana
    },
    [FRONTIER_TRAINER_RYLEE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("DOLORES"),
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_LISTEN, EC_WORD_WHO, EC_WORD_EVEN_SO, EC_WORD_WILL_BE_HERE, EC_WORD_GUTS},
        .speechWin = {EC_WORD_NOT, EC_WORD_OF, EC_WORD_GUTS, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_SAD},
        .speechLose = {EC_WORD_IF, EC_WORD_IT_S, EC_WORD_WILL_BE_HERE, EC_WORD_GUTS, EC_WORD_YOU_RE, EC_WORD_AWESOME},
        .monSet = gBattleFrontierTrainerMons_Rylee
    },
    [FRONTIER_TRAINER_CHELSEA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("CHERYLL"),
        .speechBefore = {EC_WORD_SERIOUSLY, EC_WORD_ELLIPSIS, EC_WORD_WILL, EC_EMPTY_WORD, EC_WORD_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_NORMAL, EC_WORD_THAT, EC_WORD_I, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_WILL_BE_HERE, EC_WORD_TALENT, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_EXCUSE},
        .monSet = gBattleFrontierTrainerMons_Chelsea
    },
    [FRONTIER_TRAINER_DANELA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("ALBANE"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_FOR, EC_WORD_TODAY, EC_WORD_QUES},
        .speechWin = {EC_WORD_OH_DEAR, EC_WORD_YOU_RE, EC_WORD_REALLY, EC_EMPTY_WORD, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_THE, EC_WORD_HAPPINESS, EC_WORD_ELLIPSIS, EC_WORD_BYE_BYE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Danela
    },
    [FRONTIER_TRAINER_LIZBETH] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("LISBETH"),
        .speechBefore = {EC_WORD_IF_I_LOSE, EC_WORD_YOU_VE, EC_WORD_A, EC_EMPTY_WORD, EC_MOVE2(PRESENT), EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_JOKING, EC_WORD_AHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOURS, EC_EMPTY_WORD, EC_MOVE2(PRESENT), EC_WORD_QUES_EXCL, EC_WORD_MOOD, EC_MOVE(DOUBLE_SLAP)},
        .monSet = gBattleFrontierTrainerMons_Lizbeth
    },
    [FRONTIER_TRAINER_AMELIA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("AMELIA"),
        .speechBefore = {EC_WORD_THE, EC_WORD_APPEAL, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_FASHION, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WITH, EC_WORD_HIM, EC_WORD_IT_S, EC_WORD_ALWAYS, EC_WORD_A, EC_WORD_DISASTER},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_AWFUL, EC_WORD_BYE_BYE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Amelia
    },
    [FRONTIER_TRAINER_JILLIAN] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("CLAUDIA"),
        .speechBefore = {EC_WORD_WHAT, EC_WORD_IS, EC_WORD_THIS, EC_EMPTY_WORD, EC_MOVE(SWEET_SCENT), EC_WORD_QUES},
        .speechWin = {EC_WORD_IT_S, EC_WORD_THE, EC_MOVE(SWEET_SCENT), EC_WORD_OF, EC_WORD_MISS, EC_WORD_SUMMER},
        .speechLose = {EC_WORD_YOURS, EC_WORD_AWAY, EC_WORD_IS, EC_WORD_ELLIPSIS, EC_WORD_FANTASTIC, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jillian
    },
    [FRONTIER_TRAINER_ABBIE] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("ABBIE"),
        .speechBefore = {EC_WORD_ADORE, EC_EMPTY_WORD, EC_WORD_MISS, EC_MOVE(AROMATHERAPY), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MY, EC_MOVE(AROMATHERAPY), EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_AWFUL, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_EH_QUES, EC_WORD_THIS_IS_IT_EXCL, EC_EMPTY_WORD, EC_WORD_AWAY, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Abbie
    },
    [FRONTIER_TRAINER_BRIANA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("CLARA"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_RECOMMEND, EC_WORD_HARD, EC_WORD_OF, EC_WORD_WORKING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_LIKE, EC_EMPTY_WORD, EC_WORD_WIN, EC_WORD_OF, EC_WORD_MISS, EC_WORD_SILVER},
        .speechLose = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_A, EC_EMPTY_WORD, EC_WORD_DISASTER, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Briana
    },
    [FRONTIER_TRAINER_ANTONIO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("TINO"),
        .speechBefore = {EC_WORD_FEELING, EC_WORD_MUSIC, EC_WORD_IT_S, EC_WORD_DAUGHTER, EC_WORD_LIFE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_BUT, EC_WORD_LIKE, EC_WORD_NOT, EC_WORD_FEELING, EC_WORD_DANCE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_A, EC_EMPTY_WORD, EC_MOVE(FLAIL), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Antonio
    },
    [FRONTIER_TRAINER_JADEN] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("HERCULE"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_BE, EC_WORD_WITH, EC_EMPTY_WORD, EC_WORD_HIM, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_UNDERSTOOD, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_JUST, EC_WORD_EXCL, EC_WORD_GO, EC_WORD_HELLO},
        .monSet = gBattleFrontierTrainerMons_Jaden
    },
    [FRONTIER_TRAINER_DAKOTA] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("HOMERE"),
        .speechBefore = {EC_WORD_IN, EC_WORD_NIGHTTIME, EC_WORD_FEELING, EC_EMPTY_WORD, EC_WORD_MUSIC, EC_WORD_EXCL},
        .speechWin = {EC_WORD_FEELING, EC_WORD_DANCE, EC_WORD_IT_S, EC_WORD_RECOMMEND, EC_WORD_POWER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OKAY, EC_WORD_ELLIPSIS, EC_WORD_YOU, EC_EMPTY_WORD, EC_WORD_UNDERSTAND, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Dakota
    },
    [FRONTIER_TRAINER_BRAYDEN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("HORACE"),
        .speechBefore = {EC_WORD_THE, EC_WORD_COLOR_CHANGE, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_USELESS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_COLLECT, EC_WORD_CASE, EC_EMPTY_WORD, EC_WORD_TOYS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_ADORE, EC_WORD_THE, EC_WORD_COLOR_CHANGE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Brayden
    },
    [FRONTIER_TRAINER_CORSON] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("OCTAVE"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_RECOMMEND, EC_WORD_EASY, EC_WORD_I_AM, EC_WORD_RECOMMEND, EC_WORD_COOL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_EH_QUES, EC_EMPTY_WORD, EC_MOVE2(CURSE), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Corson
    },
    [FRONTIER_TRAINER_TREVIN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("TREVIN"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YES_SIR_EXCL, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_SERIOUSLY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Trevin
    },
    [FRONTIER_TRAINER_PATRICK] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("EDGAR"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_BOY, EC_EMPTY_WORD, EC_WORD_PERFECT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_PERFECT, EC_WORD_DOES, EC_EMPTY_WORD, EC_WORD_ANGRY, EC_WORD_QUES},
        .speechLose = {EC_WORD_EH_QUES, EC_WORD_I_AM, EC_WORD_PERFECT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Patrick
    },
    [FRONTIER_TRAINER_KADEN] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("VLAD"),
        .speechBefore = {EC_WORD_BE, EC_WORD_OR, EC_WORD_ISN_T, EC_WORD_NOT, EC_WORD_BE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_HER, EC_MOVE(STRENGTH), EC_WORD_IS, EC_WORD_REALLY, EC_WORD_AN, EC_WORD_SURPRISE},
        .speechLose = {EC_WORD_WHERE, EC_WORD_LESS, EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_NO_MATCH, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kaden
    },
    [FRONTIER_TRAINER_MAXWELL] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("MAXWELL"),
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_WHO, EC_WORD_IS, EC_WORD_YOURS, EC_WORD_OPPONENT, EC_WORD_QUES},
        .speechWin = {EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_HIM, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NOW, EC_WORD_ELLIPSIS, EC_WORD_YOU_RE, EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Maxwell
    },
    [FRONTIER_TRAINER_DARYL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("DARYL"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_LEGEND, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_OVERWHELMING, EC_WORD_ELLIPSIS, EC_WORD_NO, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_NOW, EC_WORD_AN, EC_EMPTY_WORD, EC_WORD_LEGEND, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Daryl
    },
    [FRONTIER_TRAINER_KENNETH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("SAMSON"),
        .speechBefore = {EC_WORD_LIKE, EC_WORD_NOT, EC_WORD_FEELING, EC_EMPTY_WORD, EC_MOVE2(SLACK_OFF), EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_MISS, EC_WORD_INTIMIDATE, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_AWESOME, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_FORGIVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kenneth
    },
    [FRONTIER_TRAINER_RICH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("BLAISE"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_FEAR, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_NOTHING, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_LIKELY_TO, EC_EMPTY_WORD, EC_WORD_EXCUSE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ANY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rich
    },
    [FRONTIER_TRAINER_CADEN] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("GUILLEM"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_ISN_T, EC_WORD_COULD, EC_WORD_NOT, EC_WORD_WHO_WAS, EC_WORD_WHEN_I_WIN},
        .speechWin = {EC_WORD_FIRE, EC_WORD_EXCL, EC_WORD_FIRE, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_IT_S, EC_WORD_FEELING, EC_MOVE2(HEAT_WAVE), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Caden
    },
    [FRONTIER_TRAINER_MARLON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("ERIK"),
        .speechBefore = {EC_WORD_A, EC_WORD_POKEDEX, EC_WORD_IT_S, EC_WORD_AN, EC_WORD_RADIO, EC_WORD_QUES},
        .speechWin = {EC_WORD_AN, EC_WORD_RADIO, EC_WORD_AHAHA, EC_WORD_IT_S, EC_WORD_RECOMMEND, EC_WORD_COOL},
        .speechLose = {EC_WORD_AND, EC_WORD_THE, EC_WORD_POKENAV, EC_WORD_IT_S, EC_WORD_EH_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Marlon
    },
    [FRONTIER_TRAINER_NASH] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("WERNER"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_IN, EC_WORD_FIRE, EC_EMPTY_WORD, EC_WORD_BABE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_A, EC_WORD_BLAZE, EC_WORD_AWFUL, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOT, EC_EMPTY_WORD, EC_WORD_WONDER, EC_WORD_WATER, EC_WORD_PLEASE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Nash
    },
    [FRONTIER_TRAINER_ROBBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("ROBIN"),
        .speechBefore = {EC_WORD_MEGA, EC_EMPTY_WORD, EC_WORD_MEET_YOU, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_LEADER, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_SERENE_GRACE},
        .speechLose = {EC_WORD_I_VE, EC_WORD_IGNORANT, EC_WORD_WHO_IS, EC_EMPTY_WORD, EC_WORD_TOYS, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Robby
    },
    [FRONTIER_TRAINER_REECE] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("GATIEN"),
        .speechBefore = {EC_MOVE2(QUICK_ATTACK), EC_WORD_IS, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_THAT, EC_MOVE2(TELEPORT)},
        .speechWin = {EC_WORD_I_AM, EC_WORD_VERY, EC_WORD_FAST, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_MOVE2(TELEPORT), EC_WORD_ELLIPSIS, EC_WORD_THAT_WAS, EC_EMPTY_WORD, EC_WORD_JOKING, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Reece
    },
    [FRONTIER_TRAINER_KATHRYN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("KATHRYN"),
        .speechBefore = {EC_WORD_THE, EC_WORD_SPORTS, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_YET, EC_WORD_EXCL},
        .speechWin = {EC_WORD_TRAINS, EC_WORD_PLUS, EC_WORD_YOUR, EC_WORD_POKEMON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_ELLIPSIS, EC_WORD_WHY, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Kathryn
    },
    [FRONTIER_TRAINER_ELLEN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("ELLA"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_THE, EC_WORD_BALL, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_AN, EC_WORD_VICTORY, EC_EMPTY_WORD, EC_WORD_EASY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_OF, EC_WORD_FEELING, EC_MOVE2(BULK_UP), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Ellen
    },
    [FRONTIER_TRAINER_RAMON] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("RAYMOND"),
        .speechBefore = {EC_WORD_LIKE, EC_WORD_FEELING, EC_WORD_PERFECTION, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_TRY, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THE, EC_WORD_SPORTS, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_YET, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Ramon
    },
    [FRONTIER_TRAINER_ARTHUR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("LILIAN"),
        .speechBefore = {EC_WORD_APOLOGIZE, EC_WORD_EXCL, EC_WORD_HERE_I_COME, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_REALLY, EC_WORD_FABULOUS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_THIS, EC_WORD_THAT, EC_WORD_WANT, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Arthur
    },
    [FRONTIER_TRAINER_ALONDRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("EUNICE"),
        .speechBefore = {EC_WORD_FEELING, EC_MOVE2(DIVE), EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_FABULOUS, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_LEGEND, EC_WORD_OF, EC_WORD_FEELING, EC_MOVE2(DIVE)},
        .speechLose = {EC_WORD_FEELING, EC_MOVE2(DIVE), EC_WORD_IF, EC_WORD_GIVES, EC_WORD_COLD, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Alondra
    },
    [FRONTIER_TRAINER_ADRIANA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ADRIANA"),
        .speechBefore = {EC_WORD_LOOKS, EC_WORD_MY, EC_WORD_UNBELIEVABLE, EC_EMPTY_WORD, EC_WORD_SWIFT_SWIM, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SO, EC_WORD_EASY, EC_WORD_EVEN_SO, EC_WORD_MAKE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_IT_S, EC_WORD_EXCUSE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Adriana
    },
    [FRONTIER_TRAINER_MALIK] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("ROMUALD"),
        .speechBefore = {EC_WORD_OH, EC_WORD_NO, EC_WORD_LAY, EC_WORD_A, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_AND, EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Malik
    },
    [FRONTIER_TRAINER_JILL] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("LUCIE"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_TRAINER, EC_WORD_THE, EC_WORD_PLUS, EC_WORD_FAST},
        .speechWin = {EC_WORD_THE, EC_WORD_TRAINER, EC_MOVE2(QUICK_ATTACK), EC_WORD_EVEN_SO, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THE, EC_WORD_TRAINER, EC_MOVE2(QUICK_ATTACK), EC_WORD_EVEN_SO, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jill
    },
    [FRONTIER_TRAINER_ERIK] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("NOE"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_HERO, EC_EMPTY_WORD, EC_WORD_SPEED_BOOST, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_THE, EC_WORD_HERO, EC_WORD_SPEED_BOOST, EC_WORD_SIBLINGS, EC_WORD_SAID, EC_WORD_THANK_YOU},
        .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL_EXCL, EC_WORD_NO, EC_WORD_AND, EC_WORD_NO, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Erik
    },
    [FRONTIER_TRAINER_YAZMIN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("FELICIE"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_A_LOT, EC_WORD_PLUS, EC_WORD_COOL, EC_WORD_OF, EC_WORD_WORRY},
        .speechWin = {EC_WORD_ADORE, EC_EMPTY_WORD, EC_WORD_WORRY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GO, EC_WORD_BYE_BYE, EC_WORD_WILL, EC_EMPTY_WORD, EC_WORD_WORRY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Yazmin
    },
    [FRONTIER_TRAINER_JAMAL] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("JAMEL"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_BE, EC_WORD_FATHER, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT_S, EC_WORD_COOL, EC_WORD_WONDER, EC_WORD_HAVE, EC_WORD_A, EC_WORD_BABE},
        .speechLose = {EC_WORD_MY, EC_WORD_BABE, EC_WORD_BELONGS_TO, EC_WORD_BE, EC_WORD_LOVEY_DOVEY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jamal
    },
    [FRONTIER_TRAINER_LESLIE] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("LESLIE"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_BE, EC_WORD_MOTHER, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A, EC_WORD_BABE, EC_WORD_IT_S, EC_WORD_A, EC_WORD_CHALLENGE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HAVE, EC_WORD_A, EC_WORD_BABE, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_COOL},
        .monSet = gBattleFrontierTrainerMons_Leslie
    },
    [FRONTIER_TRAINER_DAVE] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("DAVE"),
        .speechBefore = {EC_WORD_THAT, EC_WORD_MAKE, EC_WORD_TODAY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_WILL_BE_HERE, EC_WORD_SPORTS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_COMPLETE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dave
    },
    [FRONTIER_TRAINER_CARLO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("RONAN"),
        .speechBefore = {EC_WORD_HAH, EC_EMPTY_WORD, EC_WORD_YAY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_ALL, EC_WORD_EVEN_SO, EC_WORD_AN, EC_MOVE(EXTREME_SPEED)},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_EVEN_SO, EC_WORD_AN, EC_MOVE(EXTREME_SPEED), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Carlo
    },
    [FRONTIER_TRAINER_EMILIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("EMILIA"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_TRUST, EC_WORD_IN, EC_EMPTY_WORD, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_THAT_WAS, EC_WORD_FANTASTIC, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AHAHA, EC_WORD_THAT_WAS, EC_WORD_ENTERTAINING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emilia
    },
    [FRONTIER_TRAINER_DALIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("LYDIA"),
        .speechBefore = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_VERY, EC_WORD_EXPENSIVE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_MY, EC_WORD_BIKE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_MY, EC_WORD_BEST, EC_WORD_ALLY},
        .monSet = gBattleFrontierTrainerMons_Dalia
    },
    [FRONTIER_TRAINER_HITOMI] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("MEHDI"),
        .speechBefore = {EC_WORD_YAY, EC_WORD_EXCL_EXCL, EC_WORD_A, EC_WORD_FIGHTING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EH_QUES, EC_EMPTY_WORD, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_QUES},
        .speechLose = {EC_WORD_AIYEEH, EC_EMPTY_WORD, EC_WORD_FORGIVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hitomi
    },
    [FRONTIER_TRAINER_RICARDO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("RICARDO"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_ON, EC_WORD_PLAYED, EC_WORD_WITH, EC_WORD_ME, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU_VE, EC_WORD_LOST, EC_WORD_AND, EC_WORD_YOU_RE, EC_WORD_PREPOSTEROUS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_GOOD_BYE, EC_EMPTY_WORD, EC_WORD_EVEN_SO, EC_EMPTY_WORD, EC_WORD_SOON, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ricardo
    },
    [FRONTIER_TRAINER_SHIZUKA] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("RUBEN"),
        .speechBefore = {EC_WORD_EXCUSE_ME, EC_WORD_YOURS, EC_WORD_GUTSY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_TRY, EC_WORD_WONDER, EC_WORD_HAVE, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_A_LOT, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_GUTSY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Shizuka
    },
    [FRONTIER_TRAINER_JOANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("JOHANA"),
        .speechBefore = {EC_WORD_LIKELY_TO, EC_EMPTY_WORD, EC_WORD_LOSE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_OWN, EC_WORD_MY, EC_MOVE2(ROAR), EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_AWFULLY, EC_WORD_ANGRY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joana
    },
    [FRONTIER_TRAINER_KELLY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("KELLY"),
        .speechBefore = {EC_WORD_MISS, EC_WORD_SCHOOL, EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_BORING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_FEELING, EC_WORD_EXCL, EC_WORD_A, EC_EMPTY_WORD, EC_WORD_GHOST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LIKE, EC_WORD_NOT_VERY, EC_WORD_WORKING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kelly
    },
    [FRONTIER_TRAINER_RAYNA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("LORRIE"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_NO_1, EC_WORD_OF, EC_WORD_FEELING, EC_MOVE(FOCUS_ENERGY)},
        .speechWin = {EC_WORD_YOU, EC_WORD_UNDERSTAND, EC_WORD_DAUGHTER, EC_EMPTY_WORD, EC_MOVE(FOCUS_ENERGY), EC_WORD_QUES},
        .speechLose = {EC_WORD_AWFUL, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_AWFUL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Rayna
    },
    [FRONTIER_TRAINER_EVAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("AKIM"),
        .speechBefore = {EC_WORD_I, EC_WORD_SENSE, EC_WORD_MISS, EC_WORD_AWAY, EC_WORD_WILL_BE_HERE, EC_WORD_FIGHTING},
        .speechWin = {EC_WORD_ADORE, EC_WORD_THE, EC_MOVE(SWEET_SCENT), EC_WORD_OF, EC_WORD_FEELING, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_MISS, EC_WORD_AWAY, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_LOSS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Evan
    },
    [FRONTIER_TRAINER_JORDAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("LOTHAR"),
        .speechBefore = {EC_WORD_EXCUSE, EC_WORD_EXCL, EC_WORD_COME_OVER, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_EH_QUES, EC_WORD_BUT, EC_WORD_YOU_VE, EC_WORD_ELLIPSIS, EC_WORD_WINS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jordan
    },
    [FRONTIER_TRAINER_JOEL] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JOEL"),
        .speechBefore = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AHAHA, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joel
    },
    [FRONTIER_TRAINER_KRISTEN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("KRISTY"),
        .speechBefore = {EC_WORD_AHAHA, EC_WORD_ELLIPSIS, EC_WORD_A, EC_EMPTY_WORD, EC_WORD_KID, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_JUST, EC_WORD_A, EC_EMPTY_WORD, EC_WORD_KID, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_OH_DEAR, EC_EMPTY_WORD, EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_KID, EC_WORD_TOUGH},
        .monSet = gBattleFrontierTrainerMons_Kristen
    },
    [FRONTIER_TRAINER_SELPHY] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("MARTINE"),
        .speechBefore = {EC_WORD_HUH_QUES, EC_WORD_EH_QUES, EC_WORD_THAT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YES, EC_WORD_EXCL, EC_WORD_WHY, EC_EMPTY_WORD, EC_WORD_NOT, EC_WORD_QUES},
        .speechLose = {EC_WORD_OH, EC_WORD_ELLIPSIS, EC_WORD_NO, EC_WORD_EXCL, EC_WORD_HOW, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Selphy
    },
    [FRONTIER_TRAINER_CHLOE] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("CHLOE"),
        .speechBefore = {EC_WORD_COME, EC_WORD_EXCL, EC_WORD_TO_US, EC_WORD_BELONGS_TO, EC_WORD_AREN_T, EC_WORD_WHEN_I_WIN},
        .speechWin = {EC_WORD_LAY, EC_WORD_EXCL, EC_WORD_A, EC_WORD_OTHER, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHAT, EC_WORD_IS, EC_WORD_YOURS, EC_EMPTY_WORD, EC_WORD_SECRET, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Chloe
    },
    [FRONTIER_TRAINER_NORTON] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("PACOME"),
        .speechBefore = {EC_WORD_I, EC_WORD_SIBLINGS, EC_WORD_KNOWS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FORGIVE, EC_WORD_BUT, EC_WORD_YOU_RE, EC_WORD_AN, EC_WORD_PUSHOVER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_AWESOME, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Norton
    },
    [FRONTIER_TRAINER_LUKAS] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("MAURIN"),
        .speechBefore = {EC_WORD_GO_AHEAD, EC_EMPTY_WORD, EC_WORD_COME_OVER, EC_EMPTY_WORD, EC_WORD_SMELL_YA, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_HER, EC_WORD_ROCK_HEAD, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_ROCK_SOLID, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HER, EC_WORD_ROCK_HEAD, EC_WORD_IS, EC_WORD_VERY, EC_WORD_ROCK_SOLID, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Lukas
    },
    [FRONTIER_TRAINER_ZACH] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("ZACH"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_EXCELLENT, EC_MOVE2(MIMIC), EC_WORD_OF, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_I_AM, EC_WORD_ALSO, EC_WORD_TRY, EC_WORD_THAT, EC_POKEMON_NATIONAL(TOGEPI), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ALSO, EC_WORD_ANGRY, EC_WORD_THAT, EC_POKEMON_NATIONAL(MANKEY), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zach
    },
    [FRONTIER_TRAINER_KAITLYN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("NENA"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_VERY, EC_WORD_HEALTHY, EC_EMPTY_WORD, EC_WORD_TODAY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_DAUGHTER, EC_WORD_VICTORY, EC_WORD_BELONGS_TO, EC_WORD_MAKE, EC_WORD_CASE, EC_WORD_NEWS},
        .speechLose = {EC_WORD_NO, EC_WORD_NO, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_JUST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kaitlyn
    },
    [FRONTIER_TRAINER_BREANNA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("SUZON"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_ANGRY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HEHEHE, EC_WORD_EXCL, EC_WORD_IN, EC_WORD_HERE_IT_IS, EC_WORD_LAY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_EXCUSE, EC_WORD_YOU_VE, EC_WORD_WILL_BE_HERE, EC_WORD_GUTS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Breanna
    },
    [FRONTIER_TRAINER_KENDRA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("KENZA"),
        .speechBefore = {EC_WORD_ISN_T, EC_WORD_WHO_WAS, EC_WORD_CAUSE, EC_EMPTY_WORD, EC_WORD_NOT, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_NOW, EC_EMPTY_WORD, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_TOO_LATE, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_A_LOT, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_GUTS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kendra
    },
    [FRONTIER_TRAINER_MOLLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("MOLLY"),
        .speechBefore = {EC_WORD_TODAY, EC_EMPTY_WORD, EC_WORD_IT_S, EC_WORD_MY, EC_WORD_COMMEMORATE, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_WHO_IS, EC_WORD_TOYS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_HOW, EC_EMPTY_WORD, EC_WORD_WHOM, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Molly
    },
    [FRONTIER_TRAINER_JAZMIN] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("ORNELLA"),
        .speechBefore = {EC_WORD_I, EC_WORD_SIBLINGS, EC_WORD_THROW, EC_WORD_A, EC_WORD_CHALLENGE, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_TAKE_THAT, EC_WORD_AND, EC_WORD_IF, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_REFUSE, EC_WORD_FEELING, EC_EMPTY_WORD, EC_WORD_LOSS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jazmin
    },
    [FRONTIER_TRAINER_KELSEY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("ZORA"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_A_LOT, EC_EMPTY_WORD, EC_WORD_SLEPT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WILL, EC_WORD_SLEEP, EC_WORD_NOW, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_COOL},
        .speechLose = {EC_WORD_NEED, EC_WORD_OF, EC_MOVE2(REST), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kelsey
    },
    [FRONTIER_TRAINER_JALEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("KHALID"),
        .speechBefore = {EC_WORD_SMELL, EC_EMPTY_WORD, EC_WORD_LOSER, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_DOES, EC_WORD_ANGRY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHY, EC_WORD_IT_S, EC_WORD_SO, EC_EMPTY_WORD, EC_WORD_HARD, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jalen
    },
    [FRONTIER_TRAINER_GRIFFEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("EUDES"),
        .speechBefore = {EC_WORD_SOMEONE, EC_MOVE2(SWALLOW), EC_WORD_MOOD, EC_EMPTY_WORD, EC_MOVE2(SLUDGE), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT_S, EC_WORD_FOR, EC_WORD_HAVE, EC_WORD_AN, EC_MOVE2(ACID_ARMOR), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WILL, EC_WORD_BE, EC_WORD_INVINCIBLE, EC_WORD_EHEHE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Griffen
    },
    [FRONTIER_TRAINER_XANDER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("MERLIN"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_PRAISE, EC_WORD_WHO_IS, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT_S, EC_WORD_UNBELIEVABLE, EC_WORD_THEY, EC_WORD_THAN, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHOM, EC_WORD_ALSO, EC_WORD_PRAISE, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Xander
    },
    [FRONTIER_TRAINER_MARVIN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("MARVIN"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_READY, EC_WORD_FOR, EC_WORD_THE, EC_WORD_CHALLENGE, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_A_LOT, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_WHO_WAS, EC_WORD_SENSE, EC_WORD_REALLY, EC_WORD_EXCUSE, EC_WORD_THANK_YOU},
        .monSet = gBattleFrontierTrainerMons_Marvin
    },
    [FRONTIER_TRAINER_BRENNAN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("GWENDAL"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_SEE, EC_WORD_CASE, EC_EMPTY_WORD, EC_WORD_NEWS, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_FEELING, EC_WORD_DAMP, EC_WORD_AND, EC_WORD_THE, EC_WORD_DRIZZLE},
        .speechLose = {EC_WORD_FEELING, EC_WORD_FORECAST, EC_WORD_IT_S, EC_WORD_VERY, EC_WORD_LOLLING, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Brennan
    },
    [FRONTIER_TRAINER_BALEY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("SOREN"),
        .speechBefore = {EC_WORD_THE, EC_MOVE(SCREECH), EC_WORD_IT_S, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_MUSIC},
        .speechWin = {EC_WORD_ADORE, EC_WORD_THE, EC_MOVE(SCREECH), EC_WORD_IT_S, EC_WORD_WAY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHOM, EC_WORD_A, EC_WORD_SYSTEM, EC_EMPTY_WORD, EC_WORD_SOUNDPROOF, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Baley
    },
    [FRONTIER_TRAINER_ZACKARY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("ABEL"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_LISTEN, EC_WORD_OF, EC_WORD_COOL, EC_WORD_YO, EC_WORD_QUES},
        .speechWin = {EC_WORD_LET_S, EC_WORD_COOL, EC_WORD_AFTER, EC_WORD_FEELING, EC_WORD_LIFE, EC_WORD_YO},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_ALWAYS, EC_WORD_THE, EC_WORD_TIME, EC_WORD_YO, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zackary
    },
    [FRONTIER_TRAINER_GABRIEL] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("EMERICK"),
        .speechBefore = {EC_WORD_MISS, EC_WORD_THICK_FAT, EC_WORD_UP, EC_WORD_MY, EC_MOVE2(BELLY_DRUM), EC_WORD_EXCL},
        .speechWin = {EC_WORD_OR, EC_WORD_IS, EC_WORD_MY, EC_EMPTY_WORD, EC_MOVE2(BELLY_DRUM), EC_WORD_QUES},
        .speechLose = {EC_WORD_MY, EC_MOVE2(BELLY_DRUM), EC_WORD_WAS, EC_WORD_RECOMMEND, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Gabriel
    },
    [FRONTIER_TRAINER_EMILY] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("EMILY"),
        .speechBefore = {EC_WORD_A_LITTLE, EC_EMPTY_WORD, EC_WORD_WONDER, EC_MOVE(HYPNOSIS), EC_WORD_ELLIPSIS, EC_WORD_QUES},
        .speechWin = {EC_WORD_DAUGHTER, EC_WORD_STRATEGY, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_MISS, EC_MOVE(HYPNOSIS)},
        .speechLose = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_FEELING, EC_WORD_FISHING, EC_WORD_TODAY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Emily
    },
    [FRONTIER_TRAINER_JORDYN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("JORDYN"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_ISN_T, EC_WORD_KNOWS, EC_WORD_NOT, EC_WORD_MY, EC_WORD_SECRET},
        .speechWin = {EC_WORD_GIRL, EC_WORD_OR, EC_WORD_BOY, EC_WORD_IT_S, EC_WORD_MY, EC_WORD_SECRET},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_I_WAS, EC_WORD_AN, EC_EMPTY_WORD, EC_WORD_LADY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jordyn
    },
    [FRONTIER_TRAINER_SOFIA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("VERONA"),
        .speechBefore = {EC_POKEMON(LOUDRED), EC_WORD_EVEN_SO, EC_WORD_A, EC_EMPTY_WORD, EC_MOVE(SWEET_SCENT), EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_THIS, EC_WORD_THAT, EC_WORD_I, EC_WORD_THINKS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_WORKS, EC_WORD_AFTER, EC_WORD_AN, EC_WORD_DEPT_STORE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Sofia
    },
    [FRONTIER_TRAINER_BRADEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("KARL"),
        .speechBefore = {EC_WORD_I_CHOOSE_YOU, EC_WORD_EXCL, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_ALL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_WHO_WAS, EC_WORD_SENSE, EC_WORD_REALLY, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OKAY, EC_WORD_EXCL, EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Braden
    },
    [FRONTIER_TRAINER_KAYDEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("ELOI"),
        .speechBefore = {EC_WORD_THIS_IS_IT_EXCL, EC_WORD_GOURMET, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_OVERDO, EC_WORD_EXCL},
        .speechWin = {EC_WORD_FEELING, EC_WORD_GOURMET, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_EHEHE, EC_EMPTY_WORD, EC_WORD_BUT, EC_WORD_IT_S, EC_WORD_TASTY, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kayden
    },
    [FRONTIER_TRAINER_COOPER] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("LEE"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_AN, EC_EMPTY_WORD, EC_WORD_PUSHOVER, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_RECOMMEND, EC_WORD_EXCITING, EC_WORD_FOR, EC_WORD_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_ELLIPSIS, EC_WORD_FORGIVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Cooper
    },
    [FRONTIER_TRAINER_JULIA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("JULIA"),
        .speechBefore = {EC_WORD_WE_RE, EC_WORD_WE, EC_WORD_WHEN_I_WIN, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ELLIPSIS, EC_WORD_ACCEPT, EC_WORD_FEELING, EC_EMPTY_WORD, EC_WORD_SERENE_GRACE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_FOR_NOW, EC_WORD_ELLIPSIS, EC_WORD_GOOD_BYE, EC_EMPTY_WORD, EC_WORD_SNORT, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Julia
    },
    [FRONTIER_TRAINER_AMARA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("TAMARA"),
        .speechBefore = {EC_WORD_WROOOAAR_EXCL, EC_EMPTY_WORD, EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_FEELING, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_RATHER, EC_WORD_EXCITING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_REALLY, EC_WORD_GREAT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Amara
    },
    [FRONTIER_TRAINER_LYNN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("LYNN"),
        .speechBefore = {EC_WORD_YOU_VE, EC_WORD_HIDDEN, EC_WORD_YOURS, EC_EMPTY_WORD, EC_WORD_SECRET, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_KNOWS, EC_WORD_YOURS, EC_EMPTY_WORD, EC_WORD_SECRET, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NOW, EC_WORD_IT_S, EC_WORD_PLUS, EC_WORD_A, EC_WORD_SECRET, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Lynn
    },
    [FRONTIER_TRAINER_JOVAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("EUGENE"),
        .speechBefore = {EC_WORD_YOURS, EC_WORD_SENSE, EC_WORD_WILL_BE_HERE, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_TERRIBLE},
        .speechWin = {EC_WORD_MY, EC_WORD_SENSE, EC_WORD_WILL_BE_HERE, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_AWFUL},
        .speechLose = {EC_WORD_TODAY, EC_WORD_I_AM, EC_WORD_NOT, EC_EMPTY_WORD, EC_WORD_HEALTHY, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jovan
    },
    [FRONTIER_TRAINER_DOMINIC] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("DOMINIC"),
        .speechBefore = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_CAMERA, EC_WORD_EXCL},
        .speechWin = {EC_WORD_FEELING, EC_WORD_CAMERA, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_EXPENSIVE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FEELING, EC_WORD_CAMERA, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_VERY, EC_WORD_LOLLING},
        .monSet = gBattleFrontierTrainerMons_Dominic
    },
    [FRONTIER_TRAINER_NIKOLAS] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("PANIS"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(MIMIC), EC_WORD_CASE, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IF_I_WIN, EC_EMPTY_WORD, EC_WORD_I_AM, EC_EMPTY_WORD, EC_POKEMON_NATIONAL(TAUROS), EC_WORD_EXCL},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_EMPTY_WORD, EC_WORD_I_AM, EC_EMPTY_WORD, EC_POKEMON_NATIONAL(MILTANK), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Nikolas
    },
    [FRONTIER_TRAINER_VALERIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("YOLANDE"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_FEAR, EC_WORD_OF, EC_WORD_HIM, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_MEAN, EC_WORD_REALLY, EC_EMPTY_WORD, EC_WORD_MEAN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_AN, EC_WORD_FUNNY, EC_WORD_OF, EC_MOVE(SCARY_FACE)},
        .monSet = gBattleFrontierTrainerMons_Valeria
    },
    [FRONTIER_TRAINER_DELANEY] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("URSULA"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_FEELING, EC_WORD_END, EC_WORD_OF, EC_WORD_MISS, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_HE, EC_WORD_IS, EC_WORD_TIME, EC_WORD_OF, EC_WORD_PLAYED, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_A, EC_WORD_WORK, EC_WORD_EVEN_SO, EC_WORD_MAKE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Delaney
    },
    [FRONTIER_TRAINER_MEGHAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("MEGANE"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_FEELING, EC_WORD_END, EC_WORD_OF, EC_WORD_MISS, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_MY, EC_WORD_WORK, EC_WORD_AND, EC_WORD_FEELING, EC_WORD_COMICS},
        .speechLose = {EC_WORD_I_VE, EC_WORD_A, EC_WORD_WORK, EC_WORD_EVEN_SO, EC_WORD_MAKE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Meghan
    },
    [FRONTIER_TRAINER_ROBERTO] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("ROBERTO"),
        .speechBefore = {EC_WORD_THE, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_IS, EC_WORD_INVINCIBLE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_BEST, EC_WORD_THAT, EC_WORD_HIM, EC_WORD_EXCL},
        .speechLose = {EC_WORD_SOMEONE, EC_WORD_WERE, EC_WORD_BEST, EC_EMPTY_WORD, EC_WORD_OLDEN, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Roberto
    },
    [FRONTIER_TRAINER_DAMIAN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("FIRMIN"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_MOVE(STRENGTH), EC_WORD_OF, EC_WORD_FEELING, EC_WORD_NATURE},
        .speechWin = {EC_WORD_DAUGHTER, EC_MOVE(STRENGTH), EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_UNBELIEVABLE, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_ARRGH, EC_WORD_EXCL, EC_WORD_NO, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Damian
    },
    [FRONTIER_TRAINER_BRODY] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("FRANZ"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_EVEN_SO, EC_WORD_FEELING, EC_WORD_FASHION, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_WELCOME, EC_WORD_AFTER, EC_WORD_THIS_IS_IT_EXCL, EC_EMPTY_WORD, EC_WORD_STAY_AT_HOME, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_ARRGH, EC_EMPTY_WORD, EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_ARENA_TRAP, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Brody
    },
    [FRONTIER_TRAINER_GRAHAM] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("FULBERT"),
        .speechBefore = {EC_WORD_YEAH, EC_WORD_EXCL, EC_WORD_YEAH_YEAH, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_EXCL, EC_WORD_WAHAHAHA, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_FORGIVE, EC_WORD_ELLIPSIS, EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Graham
    },
    [FRONTIER_TRAINER_TYLOR] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("TITOUAN"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_SENSE, EC_WORD_FEELING, EC_EMPTY_WORD, EC_MOVE2(HEAT_WAVE), EC_WORD_QUES},
        .speechWin = {EC_WORD_YES, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_IN, EC_WORD_FIRE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_ISN_T, EC_WORD_WHO_WAS, EC_WORD_CAUSE, EC_EMPTY_WORD, EC_WORD_NOT, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Tylor
    },
    [FRONTIER_TRAINER_JAREN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("NADIA"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_FORGET, EC_WORD_WHO_IS, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WANT, EC_WORD_PLUS, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NEED, EC_WORD_OF, EC_MOVE2(REST), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jaren
    },
    [FRONTIER_TRAINER_CORDELL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("JIMMY"),
        .speechBefore = {EC_WORD_MISS, EC_WORD_SPIRIT, EC_WORD_IS, EC_WORD_VERY, EC_WORD_YET, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WROOOAAR_EXCL, EC_WORD_YOU_VE, EC_WORD_LOST, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_OPPONENT, EC_EMPTY_WORD, EC_WORD_EXCELLENT, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Cordell
    },
    [FRONTIER_TRAINER_JAZLYN] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("SAVANNA"),
        .speechBefore = {EC_WORD_YOURS, EC_WORD_POKEDEX, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_AWESOME, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_OH_YEAH, EC_WORD_WOW, EC_WORD_YOURS, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_SUPER},
        .speechLose = {EC_WORD_A, EC_WORD_POKEDEX, EC_WORD_KIDDING, EC_EMPTY_WORD, EC_WORD_IT_S, EC_WORD_AWESOME},
        .monSet = gBattleFrontierTrainerMons_Jazlyn
    },
    [FRONTIER_TRAINER_ZACHERY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("HABIB"),
        .speechBefore = {EC_WORD_IT, EC_WORD_WHO_WAS, EC_WORD_WHEN_I_WIN, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_EXCITING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SOMEONE, EC_WORD_OVER, EC_WORD_ALL, EC_WORD_THE, EC_WORD_TIME, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zachery
    },
    [FRONTIER_TRAINER_JOHAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("NOE"),
        .speechBefore = {EC_WORD_MISS, EC_WORD_WINTER, EC_WORD_IS, EC_WORD_SOON, EC_WORD_FEELING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_DISLIKES, EC_WORD_WONDER, EC_WORD_BE, EC_WORD_IN, EC_WORD_WINTER},
        .speechLose = {EC_WORD_MISS, EC_WORD_SUMMER, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_LAY, EC_WORD_BETTER},
        .monSet = gBattleFrontierTrainerMons_Johan
    },
    [FRONTIER_TRAINER_SHEA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("CHUK"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_CAN_WIN, EC_WORD_OF, EC_WORD_AREN_T, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_UGLY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LIKE, EC_WORD_EXCUSE, EC_WORD_WHO_WAS, EC_EMPTY_WORD, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Shea
    },
    [FRONTIER_TRAINER_KAILA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("LUANA"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_THIRSTY, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_AWFUL, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_UPBEAT, EC_WORD_BUT, EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_ALWAYS, EC_WORD_THIRSTY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kaila
    },
    [FRONTIER_TRAINER_ISIAH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("JOSSE"),
        .speechBefore = {EC_WORD_I, EC_WORD_PRETEND, EC_WORD_STUDY, EC_WORD_EVEN_SO, EC_WORD_MISS, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_MISS, EC_WORD_SCHOOL, EC_WORD_WINNER, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WANT, EC_WORD_STUDY, EC_WORD_CASE, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Isiah
    },
    [FRONTIER_TRAINER_GARRETT] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("LOGAN"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_THIS, EC_WORD_ANIME, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ADORE, EC_WORD_ALSO, EC_WORD_FEELING, EC_EMPTY_WORD, EC_WORD_MUSIC, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WANT, EC_WORD_STUDY, EC_WORD_FEELING, EC_EMPTY_WORD, EC_WORD_CAMERA, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Garrett
    },
    [FRONTIER_TRAINER_HAYLIE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ESTELLA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_FEAR, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_NIGHT, EC_WORD_QUES},
        .speechWin = {EC_WORD_ME, EC_WORD_QUES, EC_WORD_FEAR, EC_WORD_QUES, EC_WORD_ABSOLUTELY, EC_WORD_NOT},
        .speechLose = {EC_WORD_MISS, EC_WORD_INSOMNIA, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_AWFUL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Haylie
    },
    [FRONTIER_TRAINER_MEGAN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("MEGAN"),
        .speechBefore = {EC_WORD_NEED, EC_WORD_OF, EC_WORD_WIN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WANT, EC_WORD_A, EC_WORD_CLEAR_BODY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MISS, EC_MOVE(AROMATHERAPY), EC_WORD_IT_S, EC_WORD_RECOMMEND, EC_WORD_COOL, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Megan
    },
    [FRONTIER_TRAINER_ISSAC] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("RICKY"),
        .speechBefore = {EC_WORD_MY, EC_EMPTY_WORD, EC_WORD_HOBBY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ADORE, EC_WORD_THE, EC_WORD_SPORTS, EC_WORD_AFTER, EC_WORD_MISS, EC_WORD_WATER},
        .speechLose = {EC_WORD_THE, EC_MOVE2(MUD_SPORT), EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_UGLY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Issac
    },
    [FRONTIER_TRAINER_QUINTON] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("CANDIDE"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_SAD, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_TOO_WEAK},
        .speechWin = {EC_WORD_BUT, EC_WORD_I, EC_WORD_COULD, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_SHOCKED, EC_WORD_EXCL, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_CAN_WIN, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Quinton
    },
    [FRONTIER_TRAINER_SALMA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("SALMA"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_MAGAZINE, EC_WORD_OF, EC_WORD_FASHION, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_AWESOME, EC_WORD_WONDER, EC_WORD_BE, EC_WORD_TRENDY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_DOES, EC_WORD_AGREE, EC_WORD_WITH, EC_EMPTY_WORD, EC_WORD_ME, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Salma
    },
    [FRONTIER_TRAINER_ANSLEY] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("MARYLOU"),
        .speechBefore = {EC_WORD_DANCE, EC_WORD_FOR, EC_WORD_ME, EC_WORD_ELLIPSIS, EC_WORD_PLEASE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_VERY, EC_WORD_BORING, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THE, EC_WORD_HIT, EC_WORD_ISN_T, EC_WORD_ENOUGH, EC_WORD_NOT, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ansley
    },
    [FRONTIER_TRAINER_HOLDEN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("MILOUD"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_GO_EASY, EC_WORD_AND, EC_EMPTY_WORD, EC_WORD_CARE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOO_WEAK, EC_WORD_FOR, EC_EMPTY_WORD, EC_WORD_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_YOURS, EC_WORD_SENSE, EC_WORD_WILL_BE_HERE, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_AMUSING},
        .monSet = gBattleFrontierTrainerMons_Holden
    },
    [FRONTIER_TRAINER_LUCA] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("ELTON"),
        .speechBefore = {EC_WORD_THE, EC_WORD_FIGHTING, EC_WORD_BELONGS_TO, EC_WORD_BE, EC_WORD_COOL, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_AND, EC_WORD_IT_S, EC_WORD_NORMAL, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HELLO, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_A, EC_WORD_KID},
        .monSet = gBattleFrontierTrainerMons_Luca
    },
    [FRONTIER_TRAINER_JAMISON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("TETSUO"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_LACKING, EC_WORD_OF, EC_WORD_DAUGHTER, EC_MOVE2(SECRET_POWER), EC_WORD_EXCL},
        .speechWin = {EC_WORD_HEY, EC_EMPTY_WORD, EC_WORD_HEHEHE, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THE, EC_MOVE(SMOKESCREEN), EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_PERFECT, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jamison
    },
    [FRONTIER_TRAINER_GUNNAR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("PIOTR"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_FEAR, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_ME, EC_WORD_QUES},
        .speechWin = {EC_WORD_I_VE, EC_WORD_AN, EC_MOVE(HARDEN), EC_WORD_IN, EC_WORD_STEEL, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_THE, EC_WORD_BEGINNING, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_END},
        .monSet = gBattleFrontierTrainerMons_Gunnar
    },
    [FRONTIER_TRAINER_CRAIG] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("ELIJAH"),
        .speechBefore = {EC_WORD_OR, EC_WORD_IS, EC_WORD_MY, EC_EMPTY_WORD, EC_WORD_TRAIN, EC_WORD_QUES},
        .speechWin = {EC_WORD_ADORE, EC_WORD_PLAYED, EC_WORD_THAT_S, EC_WORD_SMALL, EC_WORD_TRAIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HE_S, EC_WORD_EXCUSE, EC_WORD_FEELING, EC_WORD_ELLIPSIS, EC_WORD_BYE_BYE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Craig
    },
    [FRONTIER_TRAINER_PIERCE] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("GERARD"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_RECEIVED, EC_WORD_WILL_BE_HERE, EC_WORD_MAIL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_VE, EC_WORD_A, EC_WORD_DATE, EC_WORD_MONDAY, EC_WORD_MORNING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MONDAY, EC_WORD_MORNING, EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_EH_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Pierce
    },
    [FRONTIER_TRAINER_REGINA] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("REGINA"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_REALLY, EC_WORD_PLAYED, EC_WORD_AFTER, EC_WORD_MISS, EC_WORD_WATER},
        .speechWin = {EC_WORD_SHE, EC_WORD_IS, EC_WORD_GREAT, EC_EMPTY_WORD, EC_WORD_TODAY, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_MISS, EC_WORD_WATER, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_CAN_WIN, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Regina
    },
    [FRONTIER_TRAINER_ALISON] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ALISON"),
        .speechBefore = {EC_WORD_FEELING, EC_WORD_KINDERGARTEN, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_COOL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_FEELING, EC_WORD_KINDERGARTEN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_EMPTY_WORD, EC_WORD_LESS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alison
    },
    [FRONTIER_TRAINER_HANK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("SERGE"),
        .speechBefore = {EC_WORD_I, EC_WORD_LOOKS, EC_WORD_RECOMMEND, EC_WORD_FEELING, EC_WORD_TELEVISION, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_RPG, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IT, EC_WORD_PLAYED, EC_WORD_WITH, EC_EMPTY_WORD, EC_WORD_ME, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Hank
    },
    [FRONTIER_TRAINER_EARL] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("DAN"),
        .speechBefore = {EC_WORD_THE, EC_WORD_TRAINER, EC_WORD_INVINCIBLE, EC_WORD_IT_S, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_EHEHE, EC_WORD_I_AM, EC_WORD_INVINCIBLE, EC_WORD_AHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ALSO, EC_WORD_VERY, EC_WORD_FAST, EC_WORD_EHEHE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Earl
    },
    [FRONTIER_TRAINER_RAMIRO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("JO"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_EVEN_SO, EC_WORD_MISS, EC_WORD_SCHOOL, EC_WORD_OF, EC_WORD_FISHING},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_CLASS},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LAY, EC_WORD_A_LOT, EC_WORD_EVEN_SO, EC_WORD_LEARN, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Ramiro
    },
    [FRONTIER_TRAINER_HUNTER] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("CEDRIC"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_KNOWS, EC_WORD_THE, EC_EMPTY_WORD, EC_MOVE(CROSS_CHOP), EC_WORD_QUES},
        .speechWin = {EC_WORD_YOURS, EC_MOVE(CROSS_CHOP), EC_WORD_IS, EC_WORD_RECOMMEND, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_AN, EC_WORD_MISTAKE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hunter
    },
    [FRONTIER_TRAINER_AIDEN] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("FLORENT"),
        .speechBefore = {EC_WORD_I, EC_WORD_WORKS, EC_WORD_AND, EC_WORD_I_AM, EC_WORD_HEALTHY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HEY, EC_WORD_YES, EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_HEALTHY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_PLUS, EC_WORD_HEALTHY, EC_WORD_THAT, EC_WORD_ME, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Aiden
    },
    [FRONTIER_TRAINER_XAVIER] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("EWEN"),
        .speechBefore = {EC_WORD_HEY_THERE, EC_EMPTY_WORD, EC_WORD_LOOKS, EC_WORD_EXCL, EC_WORD_LOOKS, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_HELLO, EC_WORD_AND, EC_WORD_THANK_YOU, EC_WORD_THAT_WAS, EC_WORD_COOL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WOWEE, EC_WORD_EXCL, EC_WORD_NO, EC_WORD_AND, EC_WORD_NO, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Xavier
    },
    [FRONTIER_TRAINER_CLINTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("NEIL"),
        .speechBefore = {EC_WORD_IT, EC_WORD_SEE, EC_WORD_MY, EC_EMPTY_WORD, EC_MOVE(HYPNOSIS), EC_WORD_QUES},
        .speechWin = {EC_WORD_THE, EC_MOVE2(FURY_SWIPES), EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_COOL, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_ELLIPSIS, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Clinton
    },
    [FRONTIER_TRAINER_JESSE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("SAMMY"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_FOR, EC_WORD_DAUGHTER, EC_WORD_MOTHER},
        .speechWin = {EC_WORD_ADORE, EC_WORD_DAUGHTER, EC_WORD_MOTHER, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WANT, EC_WORD_DAUGHTER, EC_WORD_MOTHER, EC_WORD_EXCL, EC_WORD_GWAH, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jesse
    },
    [FRONTIER_TRAINER_EDUARDO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("EDUARDO"),
        .speechBefore = {EC_WORD_TO_US, EC_WORD_BELONGS_TO, EC_WORD_PLAYED, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_NIGHT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_PLAYED, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_MUSIC, EC_WORD_NON_STOP, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_PLAYED, EC_WORD_ANOTHER, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_THE, EC_WORD_HAPPINESS},
        .monSet = gBattleFrontierTrainerMons_Eduardo
    },
    [FRONTIER_TRAINER_HAL] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("ADEL"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_TRENDY, EC_WORD_NO, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WHO_WAS, EC_WORD_SENSE, EC_WORD_HEALTHY, EC_WORD_TODAY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_TRENDY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hal
    },
    [FRONTIER_TRAINER_GAGE] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("JAMES"),
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_EXCUSE, EC_WORD_EARLY_BIRD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_COUPLE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THANKS, EC_EMPTY_WORD, EC_WORD_AND, EC_WORD_EVEN_SO, EC_WORD_LATER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Gage
    },
    [FRONTIER_TRAINER_ARNOLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("ARNOLD"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_DREAM, EC_WORD_OR, EC_WORD_EH_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HER, EC_MOVE(SCARY_FACE), EC_WORD_WAS, EC_WORD_AFTER, EC_WORD_MY, EC_WORD_DREAM},
        .speechLose = {EC_WORD_MY, EC_WORD_DREAM, EC_WORD_WAS, EC_WORD_REALLY, EC_WORD_WEIRD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Arnold
    },
    [FRONTIER_TRAINER_JARRETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("KEN"),
        .speechBefore = {EC_WORD_TO_US, EC_EMPTY_WORD, EC_WORD_DANCE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LIKE, EC_WORD_FEELING, EC_WORD_DANCE, EC_WORD_AND, EC_WORD_HIM, EC_WORD_QUES},
        .speechLose = {EC_WORD_FEELING, EC_WORD_DANCE, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_EXCUSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jarrett
    },
    [FRONTIER_TRAINER_GARETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("GREGORY"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_THE, EC_MOVE2(SWEET_KISS), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_VE, EC_WORD_FULL, EC_WORD_OF, EC_WORD_TREASURE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHO_IS, EC_WORD_TREASURE, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_ANYWHERE, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Garett
    },
    [FRONTIER_TRAINER_EMANUEL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("BRAD"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_YET, EC_WORD_WONDER, EC_WORD_BE, EC_WORD_SMART, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_SMART, EC_WORD_BUT, EC_WORD_I_VE, EC_WORD_WINS},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_WILL_BE_HERE, EC_MOVE2(FAKE_OUT), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emanuel
    },
    [FRONTIER_TRAINER_GUSTAVO] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("GUSTAVO"),
        .speechBefore = {EC_WORD_ATTACK, EC_WORD_EXCL, EC_WORD_ATTACK, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SURRENDER, EC_WORD_QUES, EC_WORD_AHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SURRENDER, EC_WORD_QUES, EC_WORD_NO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gustavo
    },
    [FRONTIER_TRAINER_KAMERON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("EDMOND"),
        .speechBefore = {EC_WORD_TAKE_THAT, EC_EMPTY_WORD, EC_WORD_IT_S, EC_WORD_MY, EC_MOVE2(TRICK), EC_WORD_EXCL},
        .speechWin = {EC_WORD_MY, EC_MOVE2(TRICK), EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_OVERWHELMING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_WINS, EC_WORD_VERSUS, EC_WORD_MY, EC_MOVE2(TRICK), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kameron
    },
    [FRONTIER_TRAINER_ALFREDO] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("TREVOR"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_REALLY, EC_WORD_MAKE, EC_WORD_FEELING, EC_WORD_GOURMET, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_FEELING, EC_WORD_VICTORY, EC_WORD_OF, EC_WORD_FEELING, EC_WORD_GOURMET},
        .speechLose = {EC_WORD_THAT_WAS, EC_EMPTY_WORD, EC_WORD_REALLY, EC_WORD_A, EC_WORD_DISASTER, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Alfredo
    },
    [FRONTIER_TRAINER_RUBEN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("STEVEN"),
        .speechBefore = {EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_NOT, EC_WORD_THE, EC_WORD_TIME, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_GOOD, EC_EMPTY_WORD, EC_WORD_GO, EC_WORD_ELLIPSIS, EC_WORD_HELLO, EC_WORD_EXCL},
        .speechLose = {EC_WORD_GOOD_BYE, EC_EMPTY_WORD, EC_WORD_EVEN_SO, EC_WORD_VERY, EC_WORD_SOON, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ruben
    },
    [FRONTIER_TRAINER_LAMAR] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("LAMAR"),
        .speechBefore = {EC_WORD_A, EC_EMPTY_WORD, EC_MOVE2(PRESENT), EC_WORD_FOR, EC_WORD_ME, EC_WORD_QUES},
        .speechWin = {EC_WORD_HMM, EC_WORD_IT_S, EC_WORD_TASTY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_MOOD, EC_WORD_COMPLETE, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Lamar
    },
    [FRONTIER_TRAINER_JAXON] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("ROMAIN"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_AN, EC_WORD_SHELL_ARMOR, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHO_IS, EC_WORD_PARENT, EC_WORD_ARE, EC_WORD_NOT, EC_WORD_AGREE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_EXCL, EC_WORD_WANT, EC_WORD_AN, EC_WORD_SHELL_ARMOR, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jaxon
    },
    [FRONTIER_TRAINER_LOGAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("LUDO"),
        .speechBefore = {EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS, EC_WORD_WILL, EC_WORD_EVEN_SO, EC_WORD_MISS, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_LIKE, EC_EMPTY_WORD, EC_WORD_NOT, EC_EMPTY_WORD, EC_WORD_MISS, EC_WORD_SCHOOL},
        .speechLose = {EC_WORD_NO, EC_EMPTY_WORD, EC_WORD_THANK_YOU, EC_WORD_WILL, EC_WORD_SLEEP, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Logan
    },
    [FRONTIER_TRAINER_EMILEE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("NANETTE"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_SWEETS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_CASE, EC_WORD_SWEETS, EC_WORD_IT_S, EC_WORD_RATHER, EC_WORD_GOOD, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OR, EC_WORD_ARE, EC_WORD_YOUR, EC_EMPTY_WORD, EC_WORD_SWEETS, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Emilee
    },
    [FRONTIER_TRAINER_JOSIE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("JOSIE"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_CASE, EC_WORD_CONTEST, EC_WORD_OF, EC_WORD_POKEMON, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_FEELING, EC_WORD_FASHION, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_VERY, EC_WORD_YET},
        .speechLose = {EC_WORD_I_AM, EC_WORD_DONE, EC_WORD_WONDER, EC_WORD_HAVE, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Josie
    },
    [FRONTIER_TRAINER_ARMANDO] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("HENRI"),
        .speechBefore = {EC_WORD_ADORE, EC_EMPTY_WORD, EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_GRASS, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_IT, EC_WORD_TRADE, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_GRASS, EC_WORD_QUES},
        .speechLose = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_GRASS, EC_WORD_ARE, EC_WORD_RECOMMEND, EC_WORD_COOL},
        .monSet = gBattleFrontierTrainerMons_Armando
    },
    [FRONTIER_TRAINER_SKYLER] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("REGIS"),
        .speechBefore = {EC_WORD_CASE, EC_MOVE2(INGRAIN), EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_YET, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_WAIT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_WINS, EC_WORD_AND, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Skyler
    },
    [FRONTIER_TRAINER_RUTH] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("AURORE"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_WHO_WAS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A_LOT, EC_WORD_RECOMMEND, EC_EMPTY_WORD, EC_WORD_EASY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LOSE, EC_EMPTY_WORD, EC_WORD_IT_S, EC_WORD_ALSO, EC_WORD_WIN, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ruth
    },
    [FRONTIER_TRAINER_MELODY] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("MELODY"),
        .speechBefore = {EC_WORD_THE, EC_WORD_SUNDAY, EC_WORD_IT_S, EC_WORD_AWESOME, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SUNDAY, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_FOREVER, EC_WORD_SATURDAY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_SUNDAY, EC_EMPTY_WORD, EC_WORD_HE, EC_WORD_BELONGS_TO, EC_WORD_MAKE, EC_WORD_COLD},
        .monSet = gBattleFrontierTrainerMons_Melody
    },
    [FRONTIER_TRAINER_PEDRO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("PEDRO"),
        .speechBefore = {EC_WORD_AN, EC_WORD_SWIFT_SWIM, EC_WORD_IT_S, EC_WORD_ALWAYS, EC_WORD_COOL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HERE_IT_IS, EC_WORD_HOW, EC_WORD_I_VE, EC_WORD_SINK, EC_WORD_MY, EC_WORD_OPPONENT},
        .speechLose = {EC_WORD_UH_OH, EC_WORD_A, EC_MOVE(WHIRLPOOL), EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Pedro
    },
    [FRONTIER_TRAINER_ERICK] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("ERICK"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_CAPABLE, EC_WORD_OF, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_EMPTY_WORD, EC_WORD_REALLY, EC_WORD_SUPER, EC_WORD_UGLY, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_YOU, EC_EMPTY_WORD, EC_WORD_SIBLINGS, EC_WORD_BESIDE, EC_WORD_EXCUSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Erick
    },
    [FRONTIER_TRAINER_ELAINE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("HELENE"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_HEROINE, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANKS, EC_EMPTY_WORD, EC_WORD_NEED, EC_WORD_OF, EC_WORD_IF, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_NOT, EC_WORD_AN, EC_WORD_HEROINE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Elaine
    },
    [FRONTIER_TRAINER_JOYCE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("JOYCE"),
        .speechBefore = {EC_WORD_LALALA, EC_WORD_ELLIPSIS, EC_WORD_WHO_WAS, EC_EMPTY_WORD, EC_WORD_HERE_IT_IS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_LALALA, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_LOST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LALALA, EC_WORD_ELLIPSIS, EC_WORD_HUH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joyce
    },
    [FRONTIER_TRAINER_TODD] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("GERAUD"),
        .speechBefore = {EC_WORD_LIKELY_TO, EC_WORD_BE, EC_WORD_MY, EC_EMPTY_WORD, EC_WORD_LIGHTNINGROD, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_ALL, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_RECOMMEND, EC_WORD_OF, EC_EMPTY_WORD, EC_MOVE2(REFLECT), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Todd
    },
    [FRONTIER_TRAINER_GAVIN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("CASIMIR"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_A_LOT, EC_WORD_OF, EC_EMPTY_WORD, EC_MOVE(BIDE), EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_FEELING, EC_WORD_END, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MY, EC_WORD_MISTAKE, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_AWFUL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Gavin
    },
    [FRONTIER_TRAINER_MALORY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("MALORIE"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_SEE, EC_WORD_MOOD, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_WORD_THANKS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_ISN_T, EC_WORD_ARE, EC_WORD_NOT, EC_WORD_INCREDIBLE},
        .monSet = gBattleFrontierTrainerMons_Malory
    },
    [FRONTIER_TRAINER_ESTHER] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("ESTHER"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_A, EC_WORD_PRETTY, EC_EMPTY_WORD, EC_MOVE2(PRESENT), EC_WORD_EXCL},
        .speechWin = {EC_WORD_WANT, EC_WORD_MOOD, EC_WORD_GAME, EC_WORD_OF, EC_WORD_POKEMON, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_PLEASE, EC_EMPTY_WORD, EC_WORD_WANT, EC_WORD_MOOD, EC_WORD_CARDS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Esther
    },
    [FRONTIER_TRAINER_OSCAR] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("OSCAR"),
        .speechBefore = {EC_WORD_DIDN_T, EC_WORD_SEE, EC_WORD_HER, EC_EMPTY_WORD, EC_MOVE(FOCUS_ENERGY), EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_ALL, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_UPBEAT, EC_WORD_ELLIPSIS, EC_WORD_YOU_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Oscar
    },
    [FRONTIER_TRAINER_WILSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("WILSON"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_WORKING, EC_WORD_THE, EC_EMPTY_WORD, EC_WORD_MORNING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_BORING, EC_WORD_OF, EC_WORD_ALWAYS, EC_WORD_WORKING, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THE, EC_WORD_PLUS, EC_WORD_YET, EC_WORD_IT_S, EC_WORD_FEELING, EC_WORD_LET_ME_WIN},
        .monSet = gBattleFrontierTrainerMons_Wilson
    },
    [FRONTIER_TRAINER_CLARE] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("ELOISE"),
        .speechBefore = {EC_WORD_YAY, EC_WORD_EXCL, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_TOUGH, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_AHAHA, EC_EMPTY_WORD, EC_WORD_AN, EC_WORD_WIMPY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_COOL, EC_WORD_EXCL, EC_WORD_A, EC_WORD_SUPER, EC_WORD_TRAINER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Clare
    },
    [FRONTIER_TRAINER_TESS] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("TESS"),
        .speechBefore = {EC_WORD_IT, EC_EMPTY_WORD, EC_WORD_MOOD, EC_WORD_SWEETS, EC_POKEMON(GULPIN), EC_WORD_QUES},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_SECRET, EC_WORD_OF, EC_WORD_GOURMET, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_CASE, EC_EMPTY_WORD, EC_WORD_SWEETS, EC_WORD_IT_S, EC_WORD_GOOD, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Tess
    },
    [FRONTIER_TRAINER_LEON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("JUAN"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST, EC_EMPTY_WORD, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_VERY, EC_WORD_MEET, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_COOL},
        .speechLose = {EC_WORD_WILL, EC_WORD_EVEN_SO, EC_WORD_FEELING, EC_WORD_HOME, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Leon
    },
    [FRONTIER_TRAINER_ALONZO] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("ALESSIO"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_LAY, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IF, EC_WORD_BECOMES, EC_WORD_BORING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NO, EC_WORD_EXCL, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_IMPOSSIBLE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Alonzo
    },
    [FRONTIER_TRAINER_VINCE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("VINCE"),
        .speechBefore = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_THE, EC_WORD_BEST, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST, EC_WORD_AFTER, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_RANK},
        .speechLose = {EC_WORD_NOW, EC_EMPTY_WORD, EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_ANGRY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Vince
    },
    [FRONTIER_TRAINER_BRYON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("NOLAN"),
        .speechBefore = {EC_WORD_APPRECIATE, EC_WORD_OF, EC_WORD_SIBLINGS, EC_EMPTY_WORD, EC_WORD_MEETS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AIYEEH, EC_EMPTY_WORD, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_GIDDY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bryon
    },
    [FRONTIER_TRAINER_AVA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("AVA"),
        .speechBefore = {EC_WORD_I, EC_WORD_COLLECT, EC_WORD_CASE, EC_WORD_TREASURE, EC_WORD_WILL_BE_HERE, EC_WORD_WORLD},
        .speechWin = {EC_WORD_WHO_IS, EC_WORD_TREASURE, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_INCREDIBLE, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_WHY, EC_WORD_DOES, EC_WORD_SO, EC_EMPTY_WORD, EC_WORD_AWFUL, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Ava
    },
    [FRONTIER_TRAINER_MIRIAM] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("MIRIAM"),
        .speechBefore = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_SCARY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_WHOM, EC_WORD_FEAR, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SHOCKED, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_ELLIPSIS, EC_WORD_DRINK, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Miriam
    },
    [FRONTIER_TRAINER_CARRIE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("GLADYS"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_WILL_BE_HERE, EC_WORD_GUTSY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DID, EC_WORD_A_TINY_BIT, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_GUTS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_ELLIPSIS, EC_MOVE(SELF_DESTRUCT), EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Carrie
    },
    [FRONTIER_TRAINER_GILLIAN2] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("REINE"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_A, EC_WORD_FIGHTING, EC_WORD_GREAT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_JUST, EC_WORD_ENTERTAINING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_RECOMMEND, EC_WORD_HARD, EC_WORD_FOR, EC_WORD_ME, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Gillian2
    },
    [FRONTIER_TRAINER_TYLER] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("ETHAN"),
        .speechBefore = {EC_WORD_YO, EC_WORD_EXCL, EC_WORD_PARDON, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YO, EC_WORD_EXCL, EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_YO, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YO, EC_WORD_EXCL, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_YO, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Tyler
    },
    [FRONTIER_TRAINER_CHAZ] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("SACHA"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_VERY, EC_WORD_FIERY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THEY_RE, EC_WORD_LAY, EC_WORD_PLUS, EC_WORD_FIERY, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_IMPORTANT, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Chaz
    },
    [FRONTIER_TRAINER_NELSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("NELSON"),
        .speechBefore = {EC_WORD_WELL_THEN, EC_WORD_ELLIPSIS, EC_WORD_HERE_GOES, EC_WORD_THE, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A_LOT, EC_WORD_RECOMMEND, EC_WORD_HARD, EC_WORD_FOR, EC_WORD_HIM},
        .speechLose = {EC_WORD_FEELING, EC_WORD_MATCH_UP, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_BEAUTIFUL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Nelson
    },
    [FRONTIER_TRAINER_SHANIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("SHANON"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHAT, EC_WORD_HAPPINESS, EC_WORD_WONDER, EC_WORD_HAVE, EC_WORD_A, EC_WORD_POKEMON},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MEAN, EC_WORD_WITH, EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Shania
    },
    [FRONTIER_TRAINER_STELLA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("STELLA"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_SEE, EC_WORD_YOUR, EC_EMPTY_WORD, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THEY_RE, EC_WORD_AWFULLY, EC_WORD_BORING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_OPPONENT, EC_EMPTY_WORD, EC_WORD_EXCELLENT, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Stella
    },
    [FRONTIER_TRAINER_DORINE] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("DORIS"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_RIVAL, EC_WORD_AND, EC_WORD_WILL, EC_WORD_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_LIKE, EC_WORD_EXCUSE, EC_WORD_WIN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HEY_QUES, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_WORD_LOST, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dorine
    },
    [FRONTIER_TRAINER_MADDOX] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DANIEL"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_ARE, EC_WORD_NO_1, EC_WORD_EXCL},
        .speechWin = {EC_WORD_RULE, EC_EMPTY_WORD, EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_IMPOSSIBLE, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Maddox
    },
    [FRONTIER_TRAINER_DAVIN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("BENOIT"),
        .speechBefore = {EC_WORD_SNORT, EC_WORD_SNORT, EC_WORD_HIM, EC_WORD_EXCL, EC_WORD_SNORT, EC_WORD_SNORT},
        .speechWin = {EC_WORD_WROOOAAR_EXCL, EC_EMPTY_WORD, EC_WORD_VICTORY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WROOOAAR_EXCL, EC_EMPTY_WORD, EC_WORD_WHY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Davin
    },
    [FRONTIER_TRAINER_TREVON] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("AXEL"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_ARE, EC_WORD_MY, EC_WORD_LIVING},
        .speechWin = {EC_WORD_HAH, EC_WORD_COUPLE, EC_WORD_THAT_WAS, EC_EMPTY_WORD, EC_WORD_INCREDIBLE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HAH, EC_WORD_COUPLE, EC_WORD_THAT_WAS, EC_EMPTY_WORD, EC_WORD_AWFUL, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Trevon
    },
    [FRONTIER_TRAINER_MATEO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("MATEO"),
        .speechBefore = {EC_WORD_FOR, EC_WORD_HIM, EC_WORD_IT_S, EC_WORD_SOON, EC_WORD_FEELING, EC_WORD_END},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_VERY, EC_WORD_FAST, EC_WORD_AHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Mateo
    },
    [FRONTIER_TRAINER_BRET] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("CLINT"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_NO_1, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_LACKING, EC_WORD_OF, EC_WORD_DAUGHTER, EC_WORD_TOUGHNESS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_ALSO, EC_WORD_AN, EC_WORD_COLLECTION, EC_WORD_OF, EC_WORD_PLUSH_DOLL},
        .monSet = gBattleFrontierTrainerMons_Bret
    },
    [FRONTIER_TRAINER_RAUL] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("JASON"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_A, EC_WORD_TRAINER, EC_EMPTY_WORD, EC_WORD_WEAK, EC_WORD_QUES},
        .speechWin = {EC_WORD_UH_OH, EC_WORD_LAY, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_WEAK, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FINALLY, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Raul
    },
    [FRONTIER_TRAINER_KAY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("KATY"),
        .speechBefore = {EC_WORD_LAY, EC_WORD_EXCL, EC_WORD_A, EC_WORD_OTHER, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_HARD, EC_WORD_BUT, EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THIS_IS_IT_EXCL, EC_WORD_TIMES, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_FEELING, EC_WORD_END},
        .monSet = gBattleFrontierTrainerMons_Kay
    },
    [FRONTIER_TRAINER_ELENA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("HELENA"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_LADY, EC_EMPTY_WORD, EC_WORD_ANGRY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AN, EC_WORD_LADY, EC_WORD_ANGRY, EC_WORD_IT_S, EC_WORD_CAN_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_WORD_WONDER, EC_WORD_BE, EC_WORD_ANGRY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Elena
    },
    [FRONTIER_TRAINER_ALANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ELISA"),
        .speechBefore = {EC_WORD_COME, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_VERSUS, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_VE, EC_WORD_LAY, EC_WORD_A_LOT, EC_EMPTY_WORD, EC_WORD_EVEN_SO, EC_WORD_LEARN},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LAY, EC_WORD_A_LOT, EC_EMPTY_WORD, EC_WORD_EVEN_SO, EC_WORD_LEARN},
        .monSet = gBattleFrontierTrainerMons_Alana
    },
    [FRONTIER_TRAINER_ALEXAS] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JEROME"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_TRY, EC_WORD_OF, EC_WORD_SIBLINGS, EC_WORD_MEETS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_GWAHAHAHA, EC_WORD_EXCL, EC_WORD_YOU, EC_WORD_COULD, EC_WORD_GIVE_UP, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_GOOD, EC_EMPTY_WORD, EC_WORD_TRAINER, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Alexas
    },
    [FRONTIER_TRAINER_WESTON] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("RACHID"),
        .speechBefore = {EC_WORD_TODAY, EC_WORD_I_CHOOSE_YOU, EC_WORD_MY, EC_EMPTY_WORD, EC_WORD_OPPONENT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_UGLY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_EXCUSE, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_DROOLING, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Weston
    },
    [FRONTIER_TRAINER_JASPER] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("DIMITRI"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_SMALL, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_SKILLED, EC_WORD_EXCL},
        .speechWin = {EC_WORD_EHEHE, EC_WORD_YOU_RE, EC_WORD_LAY, EC_WORD_RECOMMEND, EC_WORD_RIVAL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_COUPLE, EC_EMPTY_WORD, EC_WORD_YOU_RE, EC_EMPTY_WORD, EC_WORD_UNBELIEVABLE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jasper
    },
    [FRONTIER_TRAINER_NADIA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("NADIA"),
        .speechBefore = {EC_WORD_WOULD, EC_WORD_VERY, EC_WORD_HEALTHY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_I_VE, EC_WORD_WINS, EC_WORD_EXCL, EC_WORD_AWESOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_A, EC_WORD_DISASTER},
        .monSet = gBattleFrontierTrainerMons_Nadia
    },
    [FRONTIER_TRAINER_MIRANDA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("MIRANDA"),
        .speechBefore = {EC_WORD_EXCUSE, EC_WORD_EXCL, EC_WORD_EXCUSE, EC_WORD_EXCL, EC_WORD_FOREVER, EC_WORD_HIM},
        .speechWin = {EC_WORD_EH_QUES, EC_EMPTY_WORD, EC_WORD_OKAY, EC_WORD_ELLIPSIS, EC_WORD_WITHOUT, EC_MOVE(GRUDGE)},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_A_LOT, EC_WORD_TOO_WEAK, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Miranda
    },
    [FRONTIER_TRAINER_EMMA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("EMMA"),
        .speechBefore = {EC_WORD_I, EC_WORD_SIBLINGS, EC_WORD_KNOWS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_ALSO, EC_WORD_MISHEARD, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_AS, EC_WORD_HIM, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emma
    },
    [FRONTIER_TRAINER_ROLANDO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("ENZO"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_HERO, EC_WORD_MOOD, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IF, EC_WORD_ENOUGH, EC_WORD_FOR, EC_EMPTY_WORD, EC_WORD_TODAY, EC_WORD_QUES},
        .speechLose = {EC_WORD_WHEN_I_WIN, EC_WORD_A, EC_WORD_HERO, EC_EMPTY_WORD, EC_WORD_WHERE, EC_WORD_SMITE},
        .monSet = gBattleFrontierTrainerMons_Rolando
    },
    [FRONTIER_TRAINER_STANLY] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("HUGO"),
        .speechBefore = {EC_WORD_IF, EC_WORD_BELONGS_TO, EC_WORD_BE, EC_WORD_A, EC_WORD_FIGHTING, EC_WORD_EASY},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_REALLY, EC_WORD_VERY, EC_EMPTY_WORD, EC_WORD_EASY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_THE, EC_WORD_HAPPINESS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stanly
    },
    [FRONTIER_TRAINER_DARIO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("DARIO"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_UP, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_WIN, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_I_AM, EC_WORD_THE, EC_EMPTY_WORD, EC_WORD_BEST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_HUH_QUES, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_I_AM, EC_WORD_EAT, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Dario
    },
    [FRONTIER_TRAINER_KARLEE] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("BARBARA"),
        .speechBefore = {EC_WORD_SOMETHING, EC_WORD_THING, EC_WORD_OF, EC_WORD_REALLY, EC_WORD_EXCUSE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_HEHEHE, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_FANTASTIC, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THIS_IS_IT_EXCL, EC_WORD_THING, EC_WORD_IS, EC_WORD_FOR, EC_WORD_HIM, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Karlee
    },
    [FRONTIER_TRAINER_JAYLIN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("SOLANGE"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_WERE, EC_WORD_ABSENT, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_FIGHTING, EC_WORD_VERY, EC_WORD_BORING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_SLEPT, EC_WORD_AS, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jaylin
    },
    [FRONTIER_TRAINER_INGRID] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("LOU-ANN"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_HEALTHY, EC_EMPTY_WORD, EC_WORD_TODAY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_BUT, EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_FIGHTING, EC_WORD_LOLLING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_MEAN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ingrid
    },
    [FRONTIER_TRAINER_DELILAH] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("NELL"),
        .speechBefore = {EC_WORD_DAUGHTER, EC_WORD_VICTORY, EC_WORD_BELONGS_TO, EC_WORD_BE, EC_WORD_GREAT, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_YOU_VE, EC_WORD_LOST, EC_WORD_YOURS, EC_EMPTY_WORD, EC_WORD_COOLNESS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHERE, EC_EMPTY_WORD, EC_WORD_LOSS, EC_WORD_I_AM, EC_WORD_ANGRY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Delilah
    },
    [FRONTIER_TRAINER_CARLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("LORA"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_SCATTER, EC_WORD_OF, EC_WORD_FEELING, EC_MOVE2(POISON_POWDER), EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_CHILD_S_PLAY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_AN, EC_MOVE2(FURY_ATTACK), EC_WORD_AND, EC_WORD_I_AM, EC_WORD_DONE},
        .monSet = gBattleFrontierTrainerMons_Carly
    },
    [FRONTIER_TRAINER_LEXIE] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("LOUISE"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_FIERY, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_LOL, EC_WORD_WE_VE, EC_WORD_WINS, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU_RE, EC_EMPTY_WORD, EC_WORD_ELLIPSIS, EC_WORD_ELLIPSIS, EC_WORD_UNBELIEVABLE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Lexie
    },
    [FRONTIER_TRAINER_MILLER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("VIVIEN"),
        .speechBefore = {EC_WORD_HELLO, EC_WORD_QUES, EC_WORD_HELLO, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MOTHER, EC_WORD_EXCL, EC_WORD_I_VE, EC_EMPTY_WORD, EC_WORD_WINS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MY, EC_WORD_PHONE, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_IGNORANT, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Miller
    },
    [FRONTIER_TRAINER_MARV] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("NESTOR"),
        .speechBefore = {EC_WORD_SOMEONE, EC_WORD_EVER, EC_WORD_NOT, EC_WORD_FEELING, EC_MOVE(SWAGGER), EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_FEELING, EC_MOVE(SWAGGER), EC_WORD_IS, EC_WORD_REALLY, EC_WORD_A, EC_MOVE(FLAIL)},
        .speechLose = {EC_WORD_GO_AHEAD, EC_WORD_EXCL, EC_WORD_GO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Marv
    },
    [FRONTIER_TRAINER_LAYTON] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("SOFIAN"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ANOTHER, EC_WORD_COOL, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SORRY, EC_WORD_SO, EC_WORD_I_AM, EC_WORD_ALSO, EC_WORD_COOL, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_REALLY, EC_EMPTY_WORD, EC_WORD_YOU_RE, EC_WORD_SUPER, EC_WORD_COOL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Layton
    },
    [FRONTIER_TRAINER_BROOKS] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("SAMY"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_FIGHTING, EC_WORD_OF, EC_WORD_HIGH, EC_WORD_LEVEL},
        .speechWin = {EC_WORD_THE, EC_WORD_HIGH, EC_WORD_LEVEL, EC_WORD_IT_S, EC_WORD_EXCITING, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_WONDER, EC_WORD_GOT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Brooks
    },
    [FRONTIER_TRAINER_GREGORY] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("JB"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_SUPER, EC_WORD_GETS, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT, EC_WORD_LAY, EC_WORD_A, EC_EMPTY_WORD, EC_MOVE(HEADBUTT), EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_TOUGH, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_EXCUSE},
        .monSet = gBattleFrontierTrainerMons_Gregory
    },
    [FRONTIER_TRAINER_REESE] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("XAVIER"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_A_LOT, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_THINGS, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_THE, EC_WORD_SPORTS, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_GOOD, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT, EC_WORD_EH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Reese
    },
    [FRONTIER_TRAINER_MASON] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("BRUNO"),
        .speechBefore = {EC_WORD_ISN_T, EC_WORD_LET_S, EC_WORD_NOT, EC_WORD_SO, EC_WORD_AWFUL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THANKS, EC_EMPTY_WORD, EC_WORD_WILL, EC_WORD_EXCUSE, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_VERY, EC_WORD_DISAPPOINTED, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Mason
    },
    [FRONTIER_TRAINER_TOBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("MANU"),
        .speechBefore = {EC_WORD_I, EC_WORD_WINS, EC_WORD_ALL, EC_WORD_THE, EC_WORD_TIME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HEY, EC_WORD_YES, EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MY, EC_WORD_SMARTNESS, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_UNBELIEVABLE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Toby
    },
    [FRONTIER_TRAINER_DOROTHY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("DOROTHY"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_ARE, EC_EMPTY_WORD, EC_WORD_ANYWHERE, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_THIS_IS_IT_EXCL, EC_WORD_VICTORY, EC_WORD_WAS, EC_EMPTY_WORD, EC_WORD_UNAVOIDABLE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THIS_IS_IT_EXCL, EC_WORD_LOSS, EC_WORD_WAS, EC_EMPTY_WORD, EC_WORD_UNAVOIDABLE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Dorothy
    },
    [FRONTIER_TRAINER_PIPER] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("MARYLIN"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_A, EC_WORD_SPEED_BOOST, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YOU_VE, EC_WORD_FEELING, EC_WORD_ROUGH_SKIN, EC_EMPTY_WORD, EC_WORD_IT_S, EC_WORD_EXCUSE},
        .speechLose = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_HIM, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Piper
    },
    [FRONTIER_TRAINER_FINN] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ETIENNE"),
        .speechBefore = {EC_WORD_LAY, EC_WORD_EXCL, EC_WORD_A, EC_WORD_OTHER, EC_WORD_FIGHTING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT_S, EC_WORD_REALLY, EC_WORD_WITHOUT, EC_EMPTY_WORD, EC_WORD_END, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NEED, EC_WORD_OF, EC_MOVE2(REST), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Finn
    },
    [FRONTIER_TRAINER_SAMIR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("MATHYS"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_FEELING, EC_MOVE2(DIVE), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT, EC_WORD_MAKE, EC_WORD_OF, EC_WORD_FEELING, EC_MOVE2(DIVE), EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_EMPTY_WORD, EC_WORD_SINK, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Samir
    },
    [FRONTIER_TRAINER_FIONA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("FIONA"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_KIDDING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FEELING, EC_WORD_FASHION, EC_WORD_IT_S, EC_WORD_VERY, EC_WORD_YET, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_PLUS, EC_WORD_TRENDY, EC_WORD_THAT, EC_WORD_ME, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Fiona
    },
    [FRONTIER_TRAINER_GLORIA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("GLORIA"),
        .speechBefore = {EC_WORD_ADORE, EC_WORD_ATTACK, EC_WORD_WITH, EC_WORD_AN, EC_WORD_SUCTION_CUPS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_FEELING, EC_WORD_END, EC_WORD_FOR, EC_WORD_HIM, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AN, EC_EMPTY_WORD, EC_WORD_SUCTION_CUPS, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_EH_QUES},
        .monSet = gBattleFrontierTrainerMons_Gloria
    },
    [FRONTIER_TRAINER_NICO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("ARSENE"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_A, EC_MOVE(SONIC_BOOM), EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SORRY, EC_WORD_EXCL, EC_WORD_REALLY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_VE, EC_WORD_A, EC_MOVE(SONIC_BOOM), EC_WORD_WITH, EC_WORD_A, EC_WORD_SPEED_BOOST},
        .monSet = gBattleFrontierTrainerMons_Nico
    },
    [FRONTIER_TRAINER_JEREMY] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("MAURICE"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_BE, EC_WORD_A, EC_WORD_MASTER, EC_WORD_POKEMON, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_MY, EC_WORD_DREAM, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MY, EC_WORD_DREAM, EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_EXCELLENT, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jeremy
    },
    [FRONTIER_TRAINER_CAITLIN] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("EMMA"),
        .speechBefore = {EC_WORD_COME, EC_WORD_MAKE, EC_MOVE2(SPLASH), EC_WORD_WITH, EC_WORD_ME, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_TODAY, EC_WORD_THE, EC_WORD_TIME, EC_WORD_IS, EC_WORD_BEAUTIFUL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_TOMORROW, EC_EMPTY_WORD, EC_WORD_HE, EC_WORD_WON_T, EC_WORD_BAD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Caitlin
    },
    [FRONTIER_TRAINER_REENA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("JUDITH"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_HAPPY, EC_WORD_TODAY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YAY, EC_WORD_EXCL, EC_WORD_YUP, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WOULD, EC_WORD_REALLY, EC_WORD_HAPPY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Reena
    },
    [FRONTIER_TRAINER_AVERY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("EVAN"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_A_LOT, EC_WORD_OF, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_EXCL},
        .speechWin = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_IT_S, EC_WORD_TOO_STRONG, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_RECOMMEND, EC_WORD_UPSIDE_DOWN, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_WORD_LOST},
        .monSet = gBattleFrontierTrainerMons_Avery
    },
    [FRONTIER_TRAINER_LIAM] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("ELVIN"),
        .speechBefore = {EC_WORD_SOMEONE, EC_WORD_EVER, EC_WORD_NOT, EC_WORD_THE, EC_WORD_FIRE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_IT_S, EC_WORD_COOL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_SOMEONE, EC_WORD_EVER, EC_WORD_NOT, EC_WORD_THE, EC_WORD_FLYING, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Liam
    },
    [FRONTIER_TRAINER_THEO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("THEO"),
        .speechBefore = {EC_WORD_AFTER, EC_WORD_FEELING, EC_WORD_LIFE, EC_WORD_ADORE, EC_WORD_FEELING, EC_WORD_FISHING},
        .speechWin = {EC_WORD_CASE, EC_WORD_POKEMON, EC_WORD_WATER, EC_WORD_ARE, EC_WORD_REALLY, EC_WORD_COOL},
        .speechLose = {EC_WORD_COUNT_ON, EC_WORD_EXCL, EC_WORD_AN, EC_WORD_OTHER, EC_WORD_TIMES, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Theo
    },
    [FRONTIER_TRAINER_BAILEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("BERNY"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_ADULT, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BE, EC_WORD_ADULT, EC_WORD_IT_S, EC_WORD_A, EC_WORD_HAPPINESS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHERE, EC_EMPTY_WORD, EC_MOVE2(FRUSTRATION), EC_WORD_EXCL, EC_WORD_HAHAHA, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Bailey
    },
    [FRONTIER_TRAINER_HUGO] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("UGO"),
        .speechBefore = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_OF, EC_WORD_MY, EC_WORD_BETTER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_TRY, EC_WORD_OF, EC_EMPTY_WORD, EC_WORD_WIN, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_MOVE(BIDE), EC_WORD_ELLIPSIS, EC_MOVE(BIDE), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hugo
    },
    [FRONTIER_TRAINER_BRYCE] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("BRYCE"),
        .speechBefore = {EC_WORD_SOMEONE, EC_WORD_WERE, EC_WORD_IN, EC_EMPTY_WORD, EC_WORD_HOLIDAY, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_LOST, EC_WORD_MY, EC_WORD_SKILL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FOR_NOW, EC_WORD_ELLIPSIS, EC_WORD_NEED, EC_WORD_OF, EC_MOVE2(REST), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Bryce
    },
    [FRONTIER_TRAINER_GIDEON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("GEDEON"),
        .speechBefore = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_FEAR, EC_WORD_OR, EC_WORD_EH_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_VERY, EC_EMPTY_WORD, EC_WORD_COOL, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_TRENDY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gideon
    },
    [FRONTIER_TRAINER_TRISTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("IAN"),
        .speechBefore = {EC_WORD_I, EC_WORD_LOOKS, EC_WORD_YOUR, EC_WORD_ELLIPSIS, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HUH_QUES, EC_WORD_ELLIPSIS, EC_WORD_I_VE, EC_WORD_REALLY, EC_WORD_WINS, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_HEY, EC_WORD_HEHEHE, EC_WORD_I_VE, EC_WORD_LAY, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Triston
    },
    [FRONTIER_TRAINER_CHARLES] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("RAINIER"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_HOPELESS, EC_WORD_WILL, EC_WORD_WIN, EC_WORD_EHEHE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I_AM, EC_WORD_YOURS, EC_MOVE(NIGHTMARE), EC_WORD_AHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GRAAAH, EC_WORD_GRAAAH, EC_WORD_GRAAAH, EC_WORD_ISN_T_IT_QUES, EC_WORD_ISN_T_IT_QUES, EC_WORD_ISN_T_IT_QUES},
        .monSet = gBattleFrontierTrainerMons_Charles
    },
    [FRONTIER_TRAINER_RAYMOND] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("MOUNIR"),
        .speechBefore = {EC_WORD_IT, EC_WORD_LISTENS, EC_WORD_AN, EC_EMPTY_WORD, EC_WORD_SONG, EC_WORD_QUES},
        .speechWin = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_HAPPY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_EMPTY_WORD, EC_WORD_HEARS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Raymond
    },
    [FRONTIER_TRAINER_DIRK] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("CLEMENT"),
        .speechBefore = {EC_WORD_HERE_GOES, EC_WORD_THE, EC_WORD_FIGHTING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_RULE, EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CAN_T, EC_WORD_A_LOT, EC_WORD_OF, EC_WORD_POKEMON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dirk
    },
    [FRONTIER_TRAINER_HAROLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("HAROLD"),
        .speechBefore = {EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_THAN, EC_WORD_A_LOT, EC_WORD_OF, EC_WORD_APPEAL},
        .speechWin = {EC_WORD_ADORE, EC_WORD_WHO_IS, EC_WORD_POKEMON, EC_WORD_AND, EC_WORD_HIM, EC_WORD_QUES},
        .speechLose = {EC_WORD_HAVE, EC_WORD_MOOD, EC_WORD_POKEMON, EC_WORD_ELLIPSIS, EC_WORD_WHERE, EC_WORD_JOY},
        .monSet = gBattleFrontierTrainerMons_Harold
    },
    [FRONTIER_TRAINER_OMAR] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("MALCOLM"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_EMPTY_WORD, EC_WORD_YOU_VE, EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_EXCL},
        .speechWin = {EC_WORD_EHEHE, EC_WORD_HERE_IT_IS, EC_WORD_MOOD, EC_WORD_SWEETS, EC_MOVE2(TOXIC), EC_WORD_EXCL},
        .speechLose = {EC_WORD_A, EC_WORD_SMALL, EC_MOVE2(PRESENT), EC_WORD_QUES_EXCL, EC_WORD_LATER, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Omar
    },
    [FRONTIER_TRAINER_PETER] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("PETER"),
        .speechBefore = {EC_WORD_I, EC_WORD_WHO_WAS, EC_WORD_BRAG, EC_WORD_OF, EC_WORD_RECOMMEND, EC_WORD_QUES},
        .speechWin = {EC_WORD_OWN, EC_WORD_A_LITTLE, EC_WORD_QUITE, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_DISAPPOINTED, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Peter
    },
    [FRONTIER_TRAINER_DEV] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("DEV"),
        .speechBefore = {EC_WORD_GO, EC_WORD_EXCL, EC_WORD_COME, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_NEED, EC_EMPTY_WORD, EC_WORD_WONDER, EC_WORD_AN, EC_WORD_NAP, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NEED, EC_EMPTY_WORD, EC_WORD_WONDER, EC_WORD_AN, EC_WORD_NAP, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Dev
    },
    [FRONTIER_TRAINER_COREY] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("DIDIER"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_KNOWS, EC_WORD_THE, EC_EMPTY_WORD, EC_MOVE(BRICK_BREAK), EC_WORD_QUES},
        .speechWin = {EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_A, EC_MOVE(BRICK_BREAK), EC_WORD_AHAHA, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_DAUGHTER, EC_MOVE2(FRUSTRATION), EC_WORD_IS, EC_EMPTY_WORD, EC_WORD_BIG, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Corey
    },
    [FRONTIER_TRAINER_ANDRE] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("ANDREAS"),
        .speechBefore = {EC_WORD_NOW, EC_WORD_IT_S, EC_WORD_A, EC_WORD_FLAME_BODY, EC_WORD_PERFECT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_BOY, EC_WORD_VERY, EC_WORD_FIERY, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_IT, EC_WORD_REALLY, EC_WORD_AN, EC_MOVE2(EXPLOSION), EC_WORD_THERE, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Andre
    },
    [FRONTIER_TRAINER_FERRIS] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("FERRIS"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_NO_1, EC_WORD_I_VE, EC_WORD_FEELING, EC_WORD_CLASS},
        .speechWin = {EC_WORD_THE, EC_WORD_NO_1, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_PLUS, EC_WORD_THE, EC_EMPTY_WORD, EC_WORD_NO_1, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Ferris
    },
    [FRONTIER_TRAINER_ALIVIA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("ALIVIA"),
        .speechBefore = {EC_WORD_WOULD, EC_WORD_GO_EASY, EC_WORD_TODAY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BUT, EC_EMPTY_WORD, EC_WORD_ALL, EC_WORD_IS, EC_WORD_SO, EC_WORD_EASY},
        .speechLose = {EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_MY, EC_EMPTY_WORD, EC_WORD_DAY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Alivia
    },
    [FRONTIER_TRAINER_PAIGE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("MARINE"),
        .speechBefore = {EC_WORD_BORED, EC_WORD_ELLIPSIS, EC_WORD_A, EC_WORD_SMALL, EC_WORD_FIGHTING, EC_WORD_QUES},
        .speechWin = {EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_IF, EC_WORD_ELLIPSIS, EC_WORD_THANK_YOU, EC_WORD_A_LOT},
        .speechLose = {EC_WORD_IT_S, EC_WORD_IF, EC_WORD_IT_S, EC_EMPTY_WORD, EC_WORD_EXCUSE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Paige
    },
    [FRONTIER_TRAINER_ANYA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("ANYA"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_EXCUSE, EC_WORD_WONDER, EC_WORD_BE, EC_WORD_DISLIKE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_BUT, EC_WORD_IT_S, EC_WORD_ALSO, EC_WORD_EXCUSE, EC_WORD_OF, EC_WORD_WIN},
        .speechLose = {EC_WORD_FINALLY, EC_WORD_ELLIPSIS, EC_WORD_YOU_VE, EC_WORD_A, EC_WORD_CUTE_CHARM, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anya
    },
    [FRONTIER_TRAINER_DAWN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("MAELLE"),
        .speechBefore = {EC_WORD_IT, EC_WORD_SIBLINGS, EC_WORD_WHEN_I_WIN, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_A, EC_EMPTY_WORD, EC_WORD_BABE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ANGRY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dawn
    },
    [FRONTIER_TRAINER_ABBY] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("ABBY"),
        .speechBefore = {EC_WORD_YOU, EC_EMPTY_WORD, EC_WORD_SENSE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FEELING, EC_WORD_VICTORY, EC_WORD_EVEN_SO, EC_WORD_A, EC_MOVE(SWEET_SCENT), EC_WORD_EXCL},
        .speechLose = {EC_WORD_HAHAHA, EC_WORD_EXCL, EC_WORD_WHERE, EC_EMPTY_WORD, EC_WORD_AWAY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Abby
    },
    [FRONTIER_TRAINER_GRETEL] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("SAFIA"),
        .speechBefore = {EC_WORD_NATURALLY, EC_WORD_THAT, EC_WORD_WILL, EC_WORD_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SIMPLE, EC_WORD_AND, EC_WORD_LIE, EC_WORD_NORMAL, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_IT_S, EC_WORD_HARD, EC_WORD_EVEN_SO, EC_EMPTY_WORD, EC_WORD_BELIEVE, EC_WORD_EXCL_EXCL},
        .monSet = gBattleFrontierTrainerMons_Gretel
    }
};
