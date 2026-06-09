const struct BattleFrontierTrainer gBattleFrontierTrainers[FRONTIER_TRAINERS_COUNT] =
{
    [FRONTIER_TRAINER_BRADY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("BRADI"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_LOSS, EC_WORD_NOT_VERY, EC_WORD_REALLY},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_NOISY, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HEY_THERE, EC_WORD_WHAT_S_UP_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Brady
    },
    [FRONTIER_TRAINER_CONNER] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("ARIEL"),
        .speechBefore = {EC_WORD_WIN, EC_WORD_IS, EC_WORD_AROUND, EC_WORD_SPIRALING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_LOSS, EC_WORD_QUES},
        .speechLose = {EC_WORD_LOSS, EC_WORD_IS, EC_WORD_HOPELESS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Conner
    },
    [FRONTIER_TRAINER_BRADLEY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("BRADIL"),
        .speechBefore = {EC_WORD_HEH, EC_WORD_SNORT, EC_WORD_EH_QUES, EC_WORD_GWAH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DASH, EC_WORD_DASH, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_DASH, EC_WORD_DASH, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS},
        .speechLose = {EC_WORD_HERE_IT_IS, EC_WORD_LISTENING, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bradley
    },
    [FRONTIER_TRAINER_CYBIL] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("CELINA"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_WORD_HAS, EC_WORD_FIGHTS, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IS, EC_WORD_SAD, EC_WORD_LIKELY_TO, EC_WORD_AWFULLY, EC_WORD_GUARD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHAT_S_UP_QUES, EC_WORD_HUMPH, EC_WORD_LISTENING, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Cybil
    },
    [FRONTIER_TRAINER_RODETTE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("ROSANA"),
        .speechBefore = {EC_WORD_AVANT_GARDE, EC_WORD_MOVE, EC_WORD_FOE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCUSE_ME, EC_WORD_SMELL_YA, EC_WORD_HASSLE, EC_WORD_GIGGLE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OH_DEAR, EC_WORD_UGLY, EC_WORD_SIGH, EC_WORD_NO, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rodette
    },
    [FRONTIER_TRAINER_PEGGY] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("PILI"),
        .speechBefore = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_PUSHOVER, EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_UNBELIEVABLE, EC_WORD_UNBELIEVABLE, EC_WORD_SEE_YA, EC_WORD_SEE_YA, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_SAD, EC_WORD_HOWEVER, EC_WORD_REALLY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Peggy
    },
    [FRONTIER_TRAINER_KEITH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("IMANOL"),
        .speechBefore = {EC_WORD_I, EC_WORD_DOES, EC_WORD_HOBBY, EC_WORD_AND, EC_WORD_FIGHTS, EC_WORD_OH_QUES},
        .speechWin = {EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_WORD_A_LOT, EC_WORD_PLUS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_HOBBY, EC_WORD_AND, EC_WORD_FIGHTS, EC_WORD_PLUS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Keith
    },
    [FRONTIER_TRAINER_GRAYSON] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("GRUSO"),
        .speechBefore = {EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_POKEMON, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_WEAKENED},
        .speechWin = {EC_WORD_WHERE, EC_WORD_HAVE, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_OH_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WENT, EC_WORD_WEAKENED, EC_WORD_RECOMMEND, EC_WORD_REALLY, EC_WORD_OH_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Grayson
    },
    [FRONTIER_TRAINER_GLENN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("LADIS"),
        .speechBefore = {EC_WORD_SINCE, EC_WORD_SINCE, EC_WORD_AND, EC_WORD_SINCE, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WILL_BE_HERE, EC_WORD_LIE, EC_WORD_CONGRATS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_LOSS, EC_WORD_PLUS, EC_WORD_WHERE, EC_WORD_SINCE},
        .monSet = gBattleFrontierTrainerMons_Glenn
    },
    [FRONTIER_TRAINER_LILIANA] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("LILIANA"),
        .speechBefore = {EC_WORD_I, EC_WORD_WHERE, EC_WORD_SURRENDER, EC_WORD_FOREVER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_WORD_CHORES, EC_WORD_IS, EC_WORD_WIN, EC_WORD_THE, EC_WORD_BATTLE},
        .speechLose = {EC_WORD_NOW, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_SURRENDER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Liliana
    },
    [FRONTIER_TRAINER_ELISE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ELISE"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_THAT_S, EC_WORD_STRATEGY, EC_WORD_LIE, EC_WORD_JUST, EC_WORD_FATHER},
        .speechWin = {EC_WORD_FATHER, EC_WORD_DASH_DASH_DASH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_FATHER, EC_WORD_SORRY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Elise
    },
    [FRONTIER_TRAINER_ZOEY] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ZOIRA"),
        .speechBefore = {EC_WORD_GUARD, EC_WORD_THING, EC_WORD_WHEN, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANKS, EC_WORD_LIE, EC_WORD_THESE_WERE, EC_WORD_THANKS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_FIGHTS, EC_WORD_THING, EC_WORD_DARN, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Zoey
    },
    [FRONTIER_TRAINER_MANUEL] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("MANEL"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LEFT, EC_WORD_ARE, EC_WORD_RECOMMEND, EC_WORD_FIGHTS, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_WILL_BE_HERE, EC_WORD_DARN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SHAKE, EC_WORD_WHERE, EC_WORD_WILL_BE_HERE, EC_WORD_DARN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Manuel
    },
    [FRONTIER_TRAINER_RUSS] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("RUCHIO"),
        .speechBefore = {EC_WORD_TO_THEM, EC_WORD_THERE, EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_THAT_S, EC_WORD_HOLIDAY, EC_WORD_POKEMON},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_THAT_S, EC_WORD_HOLIDAY, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Russ
    },
    [FRONTIER_TRAINER_DUSTIN] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("DIDI"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_ONLY, EC_WORD_POKEMON, EC_WORD_MISS, EC_WORD_COOL},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_THAT_S, EC_MOVE2(FAKE_OUT), EC_WORD_LIE, EC_WORD_WIN},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_CAN_T_WIN, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Dustin
    },
    [FRONTIER_TRAINER_TINA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("TERE"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_LAY, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_GIVES, EC_MOVE2(SWEET_KISS)},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_MOVE2(SWEET_KISS), EC_WORD_LIE, EC_POKEMON_NATIONAL(JYNX), EC_WORD_QUES},
        .speechLose = {EC_WORD_WON_T, EC_WORD_GIVES, EC_WORD_NATURALLY, EC_MOVE2(MEGA_KICK), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Tina
    },
    [FRONTIER_TRAINER_GILLIAN1] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("GALENIA"),
        .speechBefore = {EC_WORD_DON_T, EC_WORD_LIE, EC_WORD_FASHION, EC_WORD_A_TINY_BIT, EC_WORD_BATTLE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_ONLY, EC_WORD_POKEMON, EC_WORD_ALWAYS, EC_WORD_IT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LOSS, EC_WORD_WHERE, EC_WORD_DON_T, EC_WORD_LIE, EC_WORD_FASHION, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gillian
    },
    [FRONTIER_TRAINER_ZOE] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("ZOE"),
        .speechBefore = {EC_WORD_A, EC_WORD_BOOK, EC_WORD_AND, EC_WORD_THAT_S, EC_WORD_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NOW, EC_WORD_A, EC_WORD_COMICS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_HOBBY, EC_WORD_PLUS, EC_WORD_ONLY, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Zoe
    },
    [FRONTIER_TRAINER_CHEN] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("CHEN"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_DARN, EC_WORD_RECOMMEND, EC_WORD_CASE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHOM, EC_WORD_LOLLING, EC_MOVE(FOCUS_ENERGY), EC_WORD_AND, EC_WORD_TOUGH, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WHOM, EC_MOVE(FOCUS_ENERGY), EC_WORD_AND, EC_WORD_TOUGH, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Chen
    },
    [FRONTIER_TRAINER_AL] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("ACHI"),
        .speechBefore = {EC_WORD_HOWEVER, EC_WORD_AWFULLY, EC_MOVE(FACADE), EC_WORD_LET_S, EC_WORD_LEFT, EC_WORD_APPROVED},
        .speechWin = {EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_WORD_A_TINY_BIT, EC_WORD_LEFT, EC_WORD_APPROVED, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IS, EC_WORD_THESE_WERE, EC_WORD_LET_S, EC_WORD_LEFT, EC_WORD_APPROVED, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Al
    },
    [FRONTIER_TRAINER_MITCH] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("MELCHOR"),
        .speechBefore = {EC_WORD_THAT_S, EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_IS, EC_WORD_JUST, EC_WORD_DUDE},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_FIGHTS, EC_WORD_INSIDE, EC_WORD_PLUS, EC_WORD_QUES},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_DUDE},
        .monSet = gBattleFrontierTrainerMons_Mitch
    },
    [FRONTIER_TRAINER_ANNE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("AMPARO"),
        .speechBefore = {EC_WORD_RESUSCITATE, EC_WORD_MISS, EC_WORD_HUSTLE, EC_WORD_AND, EC_MOVE(GRUDGE), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_GUARD, EC_WORD_EVERY, EC_WORD_GOES, EC_WORD_EXCL},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_HUSTLE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anne
    },
    [FRONTIER_TRAINER_ALIZE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("FLOR"),
        .speechBefore = {EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_WORD_CUTENESS, EC_WORD_AND, EC_WORD_VERY, EC_WORD_APPROVED},
        .speechWin = {EC_WORD_UP, EC_WORD_ISN_T_IT_QUES, EC_WORD_CUTENESS, EC_WORD_AND, EC_WORD_APPROVED, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ISN_T_IT_QUES, EC_WORD_CUTENESS, EC_WORD_BUT, EC_WORD_WHERE, EC_WORD_APPROVED, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alize
    },
    [FRONTIER_TRAINER_LAUREN] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("LUCERO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_NATURALLY, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_INCREDIBLE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_IS, EC_WORD_AROUND, EC_WORD_SPIRALING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_EVERY, EC_WORD_HARD, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Lauren
    },
    [FRONTIER_TRAINER_KIPP] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("MANOLO"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_MOVE2(SURF), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_MOVE2(SURF), EC_WORD_EXCL},
        .speechLose = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_MOVE2(WHIRLWIND), EC_WORD_SPIRALING, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kipp
    },
    [FRONTIER_TRAINER_JASON] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("JAIRO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_TEACH, EC_WORD_JUST, EC_WORD_STRATEGY, EC_WORD_QUES},
        .speechWin = {EC_WORD_JUST, EC_WORD_STRATEGY, EC_WORD_DON_T, EC_WORD_LIE, EC_WORD_FASHION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_ABSOLUTELY, EC_WORD_TEACHES, EC_WORD_AWFULLY, EC_WORD_STRATEGY, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jason
    },
    [FRONTIER_TRAINER_JOHN] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("JULI"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_LOLLING, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_ALT_COLOR, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_AND, EC_WORD_MISS, EC_WORD_CASE, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IS, EC_WORD_SPIRALING, EC_WORD_AWFULLY, EC_WORD_THIS_IS_IT_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_John
    },
    [FRONTIER_TRAINER_ANN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ADA"),
        .speechBefore = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_CAN_WIN, EC_WORD_IS, EC_WORD_CASE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_SEE, EC_WORD_NITWIT, EC_WORD_WILL_BE_HERE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_SAD, EC_WORD_NITWIT, EC_WORD_WILL_BE_HERE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Ann
    },
    [FRONTIER_TRAINER_EILEEN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ELADIA"),
        .speechBefore = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_PRETEND, EC_WORD_NITWIT, EC_WORD_DOES, EC_WORD_SMACK},
        .speechWin = {EC_WORD_LEFT, EC_WORD_TIMES, EC_WORD_NITWIT, EC_WORD_DOES, EC_WORD_SMACK, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_LIE, EC_WORD_DOWN, EC_WORD_WHY, EC_WORD_SMACK},
        .monSet = gBattleFrontierTrainerMons_Eileen
    },
    [FRONTIER_TRAINER_CARLIE] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("CARLE"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_VACATION, EC_WORD_WAS, EC_WORD_ONLY, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TOO_LATE, EC_WORD_VACATION, EC_WORD_WAS, EC_WORD_RECOMMEND, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_VACATION, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Carlie
    },
    [FRONTIER_TRAINER_GORDON] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("GIL"),
        .speechBefore = {EC_WORD_THAT_S, EC_WORD_VICTORY, EC_WORD_WERE, EC_WORD_MORE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_MORE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_VICTORY, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_MORE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gordon
    },
    [FRONTIER_TRAINER_AYDEN] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("DADEN"),
        .speechBefore = {EC_WORD_EXCL_EXCL, EC_WORD_A, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_ANTICIPATION, EC_WORD_EXCL},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_A, EC_WORD_WATER, EC_WORD_AND, EC_MOVE2(REST), EC_WORD_EXCL},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_SINCE, EC_WORD_GIVES, EC_WORD_FOR_NOW, EC_WORD_BATH, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ayden
    },
    [FRONTIER_TRAINER_MARCO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("MARUO"),
        .speechBefore = {EC_WORD_THE, EC_WORD_WINTER, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_MOVE2(SURF)},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_MOVE2(SURF), EC_WORD_UP, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_MOVE2(SURF)},
        .monSet = gBattleFrontierTrainerMons_Marco
    },
    [FRONTIER_TRAINER_CIERRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("CERIA"),
        .speechBefore = {EC_WORD_HIGH, EC_WORD_USING, EC_WORD_SWIFT_SWIM, EC_WORD_AND, EC_WORD_SYNCHRONIZE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FOR_NOW, EC_WORD_POKEMON, EC_WORD_WEREN_T, EC_WORD_USING, EC_WORD_SYNCHRONIZE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_USING, EC_WORD_SPIRALING, EC_WORD_SYNCHRONIZE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Cierra
    },
    [FRONTIER_TRAINER_MARCY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("MARCELA"),
        .speechBefore = {EC_WORD_NEAR, EC_WORD_WHERE, EC_WORD_AS, EC_WORD_WIN, EC_WORD_FOREVER, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NEAR, EC_WORD_WIN, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_WEAKENED, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NEAR, EC_WORD_IS, EC_WORD_WEAKENED, EC_WORD_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Marcy
    },
    [FRONTIER_TRAINER_KATHY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("CORA"),
        .speechBefore = {EC_WORD_TODAY, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_DECIDE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_WIN, EC_WORD_IS, EC_WORD_EVERY, EC_WORD_BEING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IS, EC_WORD_WEAKENED, EC_WORD_CAN_T_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kathy
    },
    [FRONTIER_TRAINER_PEYTON] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("SOREL"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_AND, EC_WORD_I, EC_WORD_MAYBE, EC_WORD_FIGHTS},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_ONCE, EC_WORD_THING, EC_WORD_MISS, EC_WORD_THEY},
        .speechLose = {EC_WORD_WENT, EC_WORD_VERY, EC_WORD_CAN_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Peyton
    },
    [FRONTIER_TRAINER_JULIAN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("JACINTO"),
        .speechBefore = {EC_WORD_LAY, EC_WORD_IT, EC_WORD_A_LOT, EC_WORD_ONLY, EC_WORD_POKEMON, EC_WORD_OH_QUES},
        .speechWin = {EC_WORD_DIGITAL, EC_WORD_JUST, EC_WORD_POWER, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_LAY, EC_WORD_IT, EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Julian
    },
    [FRONTIER_TRAINER_QUINN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("OCTAVIO"),
        .speechBefore = {EC_WORD_YOURS, EC_WORD_IS, EC_WORD_PLUS, EC_WORD_LEGEND, EC_WORD_NITWIT, EC_WORD_I},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_NATURALLY, EC_WORD_LEGEND, EC_WORD_LIE, EC_WORD_THESE_WERE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLAYS, EC_WORD_LOSE, EC_WORD_JUST, EC_MOVE(MEMENTO), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Quinn
    },
    [FRONTIER_TRAINER_HAYLEE] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("QUINA"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_TIMES, EC_WORD_MEAN, EC_WORD_NEGATIVE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_TIMES, EC_WORD_MEAN, EC_WORD_FOREVER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_TIMES, EC_WORD_DISAPPOINTS, EC_WORD_NEAR, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Haylee
    },
    [FRONTIER_TRAINER_AMANDA] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("DALIA"),
        .speechBefore = {EC_WORD_TRULY, EC_WORD_JUST, EC_WORD_FAMILY, EC_WORD_TRAINS, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_WORD_FAMILY, EC_WORD_WINS, EC_WORD_ALWAYS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SINCE, EC_WORD_A_LOT, EC_WORD_LISTEN, EC_WORD_JUST, EC_WORD_FAMILY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Amanda
    },
    [FRONTIER_TRAINER_STACY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("NARCISA"),
        .speechBefore = {EC_WORD_IS, EC_WORD_MATCH_UP, EC_WORD_USING, EC_WORD_CUTE_CHARM, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_WHOM, EC_WORD_CUTE_CHARM, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_DOWN, EC_WORD_BRAG, EC_WORD_THIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stacy
    },
    [FRONTIER_TRAINER_RAFAEL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("FAEL"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_HERO, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TOO_LATE, EC_WORD_HERO, EC_WORD_WAS, EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_MOVE2(REST), EC_WORD_RECOMMEND, EC_WORD_TOO_LATE, EC_WORD_HERO, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rafael
    },
    [FRONTIER_TRAINER_OLIVER] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("ISMAEL"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR_NOW, EC_WORD_GENIUS, EC_WORD_UP, EC_WORD_UP, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FOR_NOW, EC_WORD_GENIUS, EC_WORD_WINS, EC_WORD_ALWAYS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LET_S, EC_WORD_LEFT, EC_WORD_BEING, EC_WORD_UP, EC_WORD_UP, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Oliver
    },
    [FRONTIER_TRAINER_PAYTON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("SEREO"),
        .speechBefore = {EC_WORD_I, EC_WORD_DOES, EC_WORD_FORGETS, EC_WORD_MISS, EC_MOVE(ENDEAVOR), EC_WORD_PERFECTION},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_WON, EC_WORD_HOWEVER, EC_WORD_BE, EC_WORD_PERFECTION, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_PLUS, EC_WORD_PERFECTION, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Payton
    },
    [FRONTIER_TRAINER_PAMELA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("PAMELA"),
        .speechBefore = {EC_WORD_COLD, EC_WORD_NITWIT, EC_WORD_WAKES_UP, EC_WORD_AWFULLY, EC_WORD_STRONG, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_WAKES_UP, EC_WORD_AWFULLY, EC_WORD_FUNNY, EC_WORD_STRONG, EC_WORD_QUES},
        .speechLose = {EC_WORD_JUST, EC_WORD_STRONG, EC_WORD_WHERE, EC_WORD_WAKES_UP, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Pamela
    },
    [FRONTIER_TRAINER_ELIZA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("ELVIA"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_MEAN, EC_WORD_JUST, EC_WORD_FAMILY},
        .speechWin = {EC_WORD_WILL_BE_HERE, EC_WORD_HAPPINESS, EC_WORD_MISS, EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_TIMES, EC_WORD_AIM, EC_WORD_HOWEVER, EC_WORD_TOO_LATE, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Eliza
    },
    [FRONTIER_TRAINER_MARISA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("MARUCHI"),
        .speechBefore = {EC_WORD_THE, EC_WORD_BATTLE, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_PRETTY},
        .speechWin = {EC_WORD_I, EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_HEALTHY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SOON, EC_WORD_JUST, EC_WORD_GUARD, EC_WORD_WERE, EC_WORD_PLUS, EC_WORD_HEALTHY},
        .monSet = gBattleFrontierTrainerMons_Marisa
    },
    [FRONTIER_TRAINER_LEWIS] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("LAUREN"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_FAINTED, EC_WORD_HOWEVER, EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_BUG},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_WINS, EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_BUG, EC_WORD_EXCL},
        .speechLose = {EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR_NOW, EC_WORD_BUG, EC_WORD_BAD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lewis
    },
    [FRONTIER_TRAINER_YOSHI] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("YOSHI"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_BUG, EC_WORD_ABSOLUTELY, EC_WORD_PRAISE, EC_WORD_CARES},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_ONLY, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_IT, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHERE, EC_WORD_SERIOUS, EC_WORD_MEAN, EC_WORD_FOR_NOW, EC_WORD_BUG, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Yoshi
    },
    [FRONTIER_TRAINER_DESTIN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("DIEGO"),
        .speechBefore = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_MOVE(OVERHEAT), EC_WORD_NITWIT, EC_WORD_WHOM, EC_WORD_EXCL},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_INSIDE, EC_WORD_WHOM, EC_WORD_PLUS, EC_MOVE(OVERHEAT), EC_WORD_EXCL},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_MOVE(OVERHEAT), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Destin
    },
    [FRONTIER_TRAINER_KEON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("KEON"),
        .speechBefore = {EC_WORD_SORRY, EC_WORD_I_VE_ARRIVED, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_APOLOGIZE, EC_WORD_PARDON, EC_WORD_SORRY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CRY, EC_WORD_OH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Keon
    },
    [FRONTIER_TRAINER_STUART] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("KIAN"),
        .speechBefore = {EC_WORD_EH_QUES, EC_WORD_FOE, EC_WORD_GWAH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_FOR_NOW, EC_WORD_LOLLING, EC_WORD_COOL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_EXCITING, EC_WORD_COOL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stuart
    },
    [FRONTIER_TRAINER_NESTOR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("KIUN"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_ABSOLUTELY, EC_WORD_TEACHES, EC_WORD_FOR_NOW, EC_MOVE(SKY_ATTACK), EC_WORD_QUES},
        .speechWin = {EC_WORD_WEAK, EC_WORD_PLUS, EC_WORD_SKILL, EC_WORD_RECOMMEND, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HAVE, EC_WORD_A_LITTLE, EC_WORD_MYSTERY, EC_WORD_THE, EC_WORD_BATTLE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Nestor
    },
    [FRONTIER_TRAINER_DERRICK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("DERIL"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_THAT_S, EC_MOVE2(MEDITATE), EC_WORD_QUES},
        .speechWin = {EC_WORD_THAT_S, EC_MOVE2(MEDITATE), EC_WORD_IS, EC_WORD_AROUND, EC_WORD_SPIRALING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_MOVE2(MEDITATE), EC_WORD_AND, EC_MOVE2(CALM_MIND), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Derrick
    },
    [FRONTIER_TRAINER_BRYSON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("BRISON"),
        .speechBefore = {EC_WORD_POISON_POINT, EC_WORD_AND, EC_MOVE2(COTTON_SPORE), EC_WORD_WAS, EC_WORD_AROUND, EC_WORD_SPIRALING},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_WORD_POISON_POINT, EC_WORD_QUES},
        .speechLose = {EC_WORD_JUST, EC_MOVE2(COTTON_SPORE), EC_WORD_WENT, EC_WORD_VERY, EC_WORD_FUNNY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bryson
    },
    [FRONTIER_TRAINER_CLAYTON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("CALISO"),
        .speechBefore = {EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_PLAYS, EC_WORD_LOSE, EC_WORD_JUST, EC_WORD_POKENAV, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLAYS, EC_WORD_LOSE, EC_WORD_A_TINY_BIT, EC_WORD_SPEED_BOOST, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Clayton
    },
    [FRONTIER_TRAINER_TRENTON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("TORREN"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_A_LITTLE, EC_WORD_LIE, EC_WORD_WATER, EC_WORD_QUES},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_PLUS, EC_WORD_WATER, EC_WORD_INSIDE, EC_WORD_QUES},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WHOM, EC_MOVE(ENDURE), EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Trenton
    },
    [FRONTIER_TRAINER_JENSON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("JEROLO"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WHERE, EC_WORD_WAS, EC_WORD_AWFULLY, EC_MOVE2(BARRAGE)},
        .speechWin = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_VERY, EC_WORD_TWIRLING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_WORD_HERE, EC_WORD_THAT_S, EC_MOVE2(BARRAGE), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jenson
    },
    [FRONTIER_TRAINER_WESLEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("MARINO"),
        .speechBefore = {EC_WORD_CRIES, EC_WORD_IS, EC_WORD_JUST, EC_WORD_WHY, EC_WORD_LIE, EC_WORD_WORLD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_DOES, EC_WORD_NITWIT, EC_WORD_ISN_T_IT_QUES, EC_WORD_CUTENESS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_CRIES, EC_WORD_CRIES, EC_WORD_CRIES, EC_WORD_CRIES, EC_WORD_CRIES, EC_WORD_CRIES},
        .monSet = gBattleFrontierTrainerMons_Wesley
    },
    [FRONTIER_TRAINER_ANTON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("AMADOR"),
        .speechBefore = {EC_WORD_LAY, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_GIVES, EC_WORD_FOR_NOW, EC_MOVE(THRASH)},
        .speechWin = {EC_WORD_TCH, EC_WORD_WOWEE, EC_WORD_WAAAH, EC_WORD_SORRY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THIS, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_IS, EC_WORD_FOR_NOW, EC_MOVE(THRASH)},
        .monSet = gBattleFrontierTrainerMons_Anton
    },
    [FRONTIER_TRAINER_LAWSON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("LENI"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_LOWS, EC_WORD_LIE, EC_WORD_SPIRIT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_LAY, EC_WORD_BETTER, EC_WORD_VERY, EC_WORD_LOWS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_TIMES, EC_WORD_EVERY, EC_WORD_LOWS},
        .monSet = gBattleFrontierTrainerMons_Lawson
    },
    [FRONTIER_TRAINER_SAMMY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("SAMI"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_PLAY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_PLAYS, EC_WORD_PLAY, EC_WORD_A_LOT, EC_WORD_QUES},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_PLAY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Sammy
    },
    [FRONTIER_TRAINER_ARNIE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("AMADEO"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_RIVAL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_OPPONENT, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_WHOM, EC_WORD_RIVAL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Arnie
    },
    [FRONTIER_TRAINER_ADRIAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("ADRI"),
        .speechBefore = {EC_WORD_UH_HUH, EC_WORD_UH_HUH, EC_WORD_UH_HUH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WAY, EC_WORD_WAY, EC_WORD_WAY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GOOD_BYE, EC_WORD_GOOD_BYE, EC_WORD_GOOD_BYE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Adrian
    },
    [FRONTIER_TRAINER_TRISTAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("TRISTO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_CAPABLE, EC_WORD_A_LITTLE, EC_WORD_LIE, EC_MOVE2(CONFUSION), EC_WORD_QUES},
        .speechWin = {EC_WORD_THAT_S, EC_MOVE2(CONFUSION), EC_WORD_WEREN_T, EC_WORD_ALLOW, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_NOW, EC_MOVE2(CONFUSION), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Tristan
    },
    [FRONTIER_TRAINER_JULIANA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("JULITA"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_CARE, EC_WORD_LIE, EC_WORD_PROBABLY, EC_WORD_DEPT_STORE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BUT, EC_WORD_SINCE, EC_WORD_FOR_NOW, EC_WORD_PLUSH_DOLL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SINCE, EC_WORD_FOR_NOW, EC_WORD_PLUSH_DOLL, EC_WORD_PLUS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Juliana
    },
    [FRONTIER_TRAINER_RYLEE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("RILITA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_LIE, EC_WORD_THESE_WERE, EC_WORD_GUTS, EC_WORD_QUES},
        .speechWin = {EC_WORD_WHERE, EC_WORD_HAVE, EC_WORD_GUTS, EC_WORD_GOOD_BYE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_PLUS, EC_WORD_GUTS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rylee
    },
    [FRONTIER_TRAINER_CHELSEA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("CHELSI"),
        .speechBefore = {EC_WORD_EXCL_EXCL, EC_WORD_I, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_ISN_T_IT_QUES, EC_WORD_BEING, EC_WORD_THE, EC_WORD_BATTLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_LET_S, EC_WORD_EXCITING, EC_WORD_THE, EC_WORD_BATTLE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Chelsea
    },
    [FRONTIER_TRAINER_DANELA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("DANLA"),
        .speechBefore = {EC_WORD_EXCL_EXCL, EC_WORD_A, EC_WORD_AN, EC_WORD_FOR_NOW, EC_WORD_OPPONENT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_AWAY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_PLUS, EC_WORD_AWAY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Danela
    },
    [FRONTIER_TRAINER_LIZBETH] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("LINARA"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_WHERE, EC_WORD_LAY, EC_WORD_GIVE, EC_WORD_THAT_S, EC_WORD_IF_I_LOSE},
        .speechWin = {EC_WORD_MUFUFU, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_MOVE(DOUBLE_SLAP), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lizbeth
    },
    [FRONTIER_TRAINER_AMELIA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("LAREA"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_MOVE2(ATTRACT), EC_WORD_AND, EC_MOVE(CHARM), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_USING, EC_WORD_THAT_S, EC_WORD_FASHION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_FASHION, EC_WORD_WHERE, EC_WORD_WALKS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Amelia
    },
    [FRONTIER_TRAINER_JILLIAN] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("GALARA"),
        .speechBefore = {EC_WORD_EXCL_EXCL, EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_USING, EC_WORD_WATER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_WATER, EC_WORD_PRAISE, EC_WORD_FOR_NOW, EC_MOVE(SWEET_SCENT), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AWFULLY, EC_WORD_OFFENSIVE, EC_WORD_WHERE, EC_WORD_PRAISE, EC_WORD_FOR_NOW, EC_MOVE(SWEET_SCENT)},
        .monSet = gBattleFrontierTrainerMons_Jillian
    },
    [FRONTIER_TRAINER_ABBIE] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("ABRIL"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_TEACH, EC_WORD_JUST, EC_MOVE(AROMATHERAPY), EC_WORD_QUES},
        .speechWin = {EC_WORD_JUST, EC_MOVE(AROMATHERAPY), EC_WORD_IS, EC_WORD_HOPELESS, EC_WORD_RECOMMEND, EC_WORD_REALLY},
        .speechLose = {EC_WORD_JUST, EC_MOVE(AROMATHERAPY), EC_WORD_WHERE, EC_WORD_WALKS, EC_WORD_VERY, EC_WORD_THING},
        .monSet = gBattleFrontierTrainerMons_Abbie
    },
    [FRONTIER_TRAINER_BRIANA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("BRIANA"),
        .speechBefore = {EC_WORD_JUST, EC_WORD_TO_WHOM, EC_WORD_PRAISE, EC_WORD_EXCITING, EC_WORD_WORK, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SINCE, EC_WORD_LIKELY_TO, EC_WORD_LISTEN, EC_WORD_JUST, EC_WORD_TO_WHOM, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_LIKELY_TO, EC_WORD_LISTEN, EC_WORD_JUST, EC_WORD_TO_WHOM, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Briana
    },
    [FRONTIER_TRAINER_ANTONIO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("RECO"),
        .speechBefore = {EC_WORD_THAT_S, EC_WORD_MUSIC, EC_WORD_IS, EC_WORD_AROUND, EC_WORD_PLUS, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BUT, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_DANCE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_EAT, EC_WORD_HOWEVER, EC_WORD_THAT_S, EC_WORD_MUSIC, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Antonio
    },
    [FRONTIER_TRAINER_JADEN] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("JADEN"),
        .speechBefore = {EC_WORD_HELLO, EC_WORD_APPRECIATE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_A_LITTLE, EC_WORD_LIE, EC_MOVE2(FRUSTRATION), EC_WORD_QUES},
        .speechLose = {EC_WORD_ARRGH, EC_WORD_HERE_IT_IS, EC_WORD_GOOD_BYE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jaden
    },
    [FRONTIER_TRAINER_DAKOTA] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("DANEO"),
        .speechBefore = {EC_WORD_RECOMMEND, EC_WORD_DANCE, EC_WORD_A, EC_WORD_STRONG, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_CAN, EC_WORD_DANCE, EC_WORD_MISS, EC_WORD_STRONG, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_AN, EC_WORD_PLUS, EC_WORD_STRONG, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dakota
    },
    [FRONTIER_TRAINER_BRAYDEN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("BRAIDEN"),
        .speechBefore = {EC_WORD_COLOR_CHANGE, EC_WORD_WALKS, EC_WORD_EXCITING, EC_WORD_THING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHOM, EC_WORD_COLLECTION, EC_WORD_LIE, EC_WORD_BOARD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_PLUS, EC_WORD_BOARD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Brayden
    },
    [FRONTIER_TRAINER_CORSON] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("CORSON"),
        .speechBefore = {EC_WORD_I, EC_WORD_FIGHT, EC_WORD_MISS, EC_WORD_CUTE_CHARM, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WENT, EC_WORD_WEAKENED, EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_WORD_BEING, EC_EMPTY_WORD},
        .speechLose = {EC_MOVE2(CURSE), EC_WORD_SURRENDER, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Corson
    },
    [FRONTIER_TRAINER_TREVIN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("TREVIN"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_BELONGS_TO, EC_WORD_YOURS, EC_WORD_MEAN, EC_WORD_I, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_UP, EC_WORD_ISN_T_IT_QUES, EC_WORD_GOOD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ONLY, EC_WORD_BELONGS_TO, EC_WORD_THIRSTY, EC_WORD_NITWIT, EC_WORD_I, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Trevin
    },
    [FRONTIER_TRAINER_PATRICK] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("TRICIO"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_NATURALLY, EC_WORD_PERSON, EC_WORD_MISS, EC_MOVE(SPARK), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WHERE, EC_WORD_STORY, EC_WORD_FOREVER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_WHOM, EC_MOVE(SPARK), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Patrick
    },
    [FRONTIER_TRAINER_KADEN] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("CADEN"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_HERS, EC_MOVE2(FUTURE_SIGHT), EC_WORD_MATCH_UP, EC_WORD_QUES},
        .speechWin = {EC_WORD_JUST, EC_MOVE2(FUTURE_SIGHT), EC_WORD_WENT, EC_WORD_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_DOWN, EC_WORD_MAKE, EC_WORD_HERE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kaden
    },
    [FRONTIER_TRAINER_MAXWELL] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("DOLFO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LET_S, EC_WORD_JUST, EC_WORD_LOLLING, EC_WORD_RIVAL, EC_WORD_QUES},
        .speechWin = {EC_WORD_JUST, EC_WORD_RIVAL, EC_WORD_IS, EC_WORD_JUST, EC_WORD_WHOSE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_LET_S, EC_WORD_JUST, EC_WORD_RIVAL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Maxwell
    },
    [FRONTIER_TRAINER_DARYL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("CIPRI"),
        .speechBefore = {EC_WORD_FIGHTS, EC_WORD_THING, EC_WORD_IS, EC_WORD_NATURALLY, EC_MOVE(CHARGE), EC_WORD_MATCH_UP},
        .speechWin = {EC_WORD_LET_S, EC_WORD_NATURALLY, EC_MOVE(CHARGE), EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LET_S, EC_WORD_LEFT, EC_WORD_NATURALLY, EC_WORD_DESTROYED, EC_WORD_LEGEND, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Daryl
    },
    [FRONTIER_TRAINER_KENNETH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("SANCHO"),
        .speechBefore = {EC_WORD_FEELING, EC_WORD_FIGHTS, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_MOVE2(SLACK_OFF), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_MOVE2(TAUNT), EC_WORD_WALKS, EC_WORD_MISS, EC_MOVE2(SLACK_OFF), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_MOVE2(SLACK_OFF), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kenneth
    },
    [FRONTIER_TRAINER_RICH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("NORBER"),
        .speechBefore = {EC_WORD_AWFULLY, EC_MOVE(FACADE), EC_WORD_WHERE, EC_WORD_WALKS, EC_WORD_MEAN, EC_MOVE2(TRICK)},
        .speechWin = {EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_GIVES, EC_WORD_NATURALLY, EC_MOVE(FACADE), EC_WORD_REFRESHING},
        .speechLose = {EC_WORD_COME_ON, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rich
    },
    [FRONTIER_TRAINER_CADEN] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("GUROL"),
        .speechBefore = {EC_WORD_NEAR, EC_WORD_COLD, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_CAN_T, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TIMES, EC_WORD_NITWIT, EC_WORD_FIGHT, EC_WORD_MISS, EC_WORD_FIRE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_DOWNCAST, EC_WORD_DOWN, EC_MOVE(OVERHEAT), EC_WORD_WHOM, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Caden
    },
    [FRONTIER_TRAINER_MARLON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("MAURO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_THAT_S, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_RADIO, EC_WORD_QUES},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_THAT_S, EC_WORD_RADIO, EC_WORD_IS, EC_WORD_POKEDEX, EC_WORD_QUES},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_MEAN, EC_WORD_POKENAV, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Marlon
    },
    [FRONTIER_TRAINER_NASH] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("NAREO"),
        .speechBefore = {EC_WORD_HIP_AND, EC_WORD_GUARD, EC_WORD_MISS, EC_MOVE(SPARK), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_ARE, EC_WORD_LEFT, EC_WORD_THE, EC_MOVE2(EMBER), EC_WORD_QUES},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_WATER, EC_WORD_ME, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Nash
    },
    [FRONTIER_TRAINER_ROBBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("RODRI"),
        .speechBefore = {EC_WORD_HEH, EC_WORD_HELLO, EC_WORD_HERE_I_COME, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_NATURALLY, EC_WORD_LOLLING, EC_WORD_SERENE_GRACE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HUMPH, EC_WORD_EXCUSE, EC_WORD_FUFUFU, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Robby
    },
    [FRONTIER_TRAINER_REECE] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("RERE"),
        .speechBefore = {EC_WORD_JUST, EC_MOVE2(QUICK_ATTACK), EC_WORD_IS, EC_WORD_SPIRALING, EC_WORD_NITWIT, EC_MOVE2(TELEPORT)},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_ISN_T_IT_QUES, EC_WORD_LEFT, EC_WORD_VERY, EC_WORD_SKILL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_MOVE2(TELEPORT), EC_WORD_WHERE, EC_WORD_IS, EC_WORD_EVERY, EC_WORD_ANTICIPATION},
        .monSet = gBattleFrontierTrainerMons_Reece
    },
    [FRONTIER_TRAINER_KATHRYN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("CATRIN"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_NITWIT, EC_WORD_IF, EC_WORD_DOES, EC_WORD_FORGETS, EC_WORD_QUES},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_DOES, EC_WORD_FORGETS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_FORGETS, EC_WORD_EXCITING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kathryn
    },
    [FRONTIER_TRAINER_ELLEN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("ELO"),
        .speechBefore = {EC_MOVE2(CRUSH_CLAW), EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_QUITE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_VICTORY, EC_WORD_EVERY, EC_WORD_CUTENESS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WHOM, EC_MOVE2(CRUSH_CLAW), EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ellen
    },
    [FRONTIER_TRAINER_RAMON] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("MONCHU"),
        .speechBefore = {EC_WORD_IS, EC_WORD_MATCH_UP, EC_WORD_BE, EC_WORD_VERY, EC_WORD_PERFECTION, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_WILL_BE_HERE, EC_WORD_SATISFIED, EC_WORD_HOWEVER, EC_WORD_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_A_LOT, EC_WORD_PLUS, EC_WORD_PERFECTION},
        .monSet = gBattleFrontierTrainerMons_Ramon
    },
    [FRONTIER_TRAINER_ARTHUR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ARMANDO"),
        .speechBefore = {EC_WORD_SINCE, EC_WORD_AN, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_BADLY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_BADLY, EC_WORD_NITWIT, EC_WORD_WENT, EC_WORD_EXCL},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_TALENT, EC_WORD_PLUS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Arthur
    },
    [FRONTIER_TRAINER_ALONDRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("LONDRA"),
        .speechBefore = {EC_WORD_TO_THEM, EC_WORD_ONLY, EC_WORD_DAYS, EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_EMPTY_WORD},
        .speechWin = {EC_MOVE2(DIVE), EC_WORD_IS, EC_WORD_SLIMY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_MOVE2(DIVE), EC_WORD_IS, EC_WORD_A_LITTLE, EC_WORD_HOPELESS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alondra
    },
    [FRONTIER_TRAINER_ADRIANA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ADRIANA"),
        .speechBefore = {EC_WORD_SWIFT_SWIM, EC_WORD_IS, EC_WORD_HUNGRY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WENT, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_VERY, EC_WORD_PLAY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_IMPORTANT, EC_WORD_AND, EC_WORD_SAD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Adriana
    },
    [FRONTIER_TRAINER_MALIK] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("VADEO"),
        .speechBefore = {EC_WORD_PLUS, EC_WORD_GUARD, EC_WORD_WHERE, EC_WORD_WHEN, EC_WORD_SIGH, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WON, EC_WORD_AND, EC_WORD_WILL_BE_HERE, EC_WORD_DOWNCAST, EC_WORD_SIGH, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLAYS, EC_WORD_LOSE, EC_WORD_WILL_BE_HERE, EC_WORD_DOWNCAST, EC_WORD_SIGH, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Malik
    },
    [FRONTIER_TRAINER_JILL] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("GILDA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_MISS, EC_MOVE2(QUICK_ATTACK), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IF, EC_WORD_CAN_T, EC_WORD_USING, EC_MOVE2(QUICK_ATTACK), EC_WORD_THOSE_ARE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CAN_T, EC_WORD_USING, EC_MOVE2(QUICK_ATTACK), EC_WORD_MISS, EC_WORD_TYPE, EC_WORD_GRASS},
        .monSet = gBattleFrontierTrainerMons_Jill
    },
    [FRONTIER_TRAINER_ERIK] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("ENRIC"),
        .speechBefore = {EC_WORD_I, EC_WORD_DOES, EC_WORD_FIGHTS, EC_WORD_MISS, EC_WORD_LOLLING, EC_WORD_SPEED_BOOST},
        .speechWin = {EC_WORD_THANKS, EC_WORD_HOWEVER, EC_WORD_A_TINY_BIT, EC_WORD_LOLLING, EC_WORD_SPEED_BOOST, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_SPEED_BOOST, EC_WORD_YOUR, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Erik
    },
    [FRONTIER_TRAINER_YAZMIN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("LLAIRA"),
        .speechBefore = {EC_WORD_HIGH, EC_WORD_RUN, EC_WORD_FEELING, EC_WORD_BIKE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_UP, EC_WORD_HIGH, EC_WORD_A_LOT, EC_WORD_PLUS, EC_WORD_RUN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GOOD_BYE, EC_WORD_OR, EC_WORD_SKILL, EC_WORD_LISTEN, EC_WORD_RUN, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Yazmin
    },
    [FRONTIER_TRAINER_JAMAL] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("JAMAL"),
        .speechBefore = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_BE, EC_WORD_FATHER, EC_WORD_SOON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FOR_NOW, EC_WORD_BABE, EC_WORD_IS, EC_WORD_AROUND, EC_WORD_PLUS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WERE, EC_WORD_FOR_NOW, EC_WORD_BABE, EC_WORD_MISS, EC_WORD_CUTE_CHARM, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jamal
    },
    [FRONTIER_TRAINER_LESLIE] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("LESLI"),
        .speechBefore = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_BE, EC_WORD_MOTHER, EC_WORD_SOON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FOR_NOW, EC_WORD_BABE, EC_WORD_IS, EC_WORD_FOR_NOW, EC_WORD_LOLLING, EC_WORD_CHALLENGE},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_EXCITING, EC_WORD_SEE, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_MOVE(OUTRAGE)},
        .monSet = gBattleFrontierTrainerMons_Leslie
    },
    [FRONTIER_TRAINER_DAVE] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("DARO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DOWN, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_USING, EC_WORD_QUES},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_A_LOT, EC_WORD_ONLY, EC_WORD_SPORTS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_HOWEVER, EC_WORD_TOO_LATE, EC_WORD_RPG, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dave
    },
    [FRONTIER_TRAINER_CARLO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("CARLOS"),
        .speechBefore = {EC_WORD_EH_QUES, EC_WORD_EH_QUES, EC_WORD_EH_QUES, EC_WORD_EH_QUES, EC_WORD_EH_QUES, EC_WORD_EH_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_HIGH, EC_WORD_ALWAYS, EC_WORD_THAT_S, EC_MOVE(EXTREME_SPEED), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WHOM, EC_MOVE(EXTREME_SPEED), EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Carlo
    },
    [FRONTIER_TRAINER_EMILIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("EMILIA"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_BELONGS_TO, EC_WORD_LIE, EC_WORD_DOWN, EC_WORD_WORRY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HAH, EC_WORD_UNBELIEVABLE, EC_WORD_SEE_YA, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SNORT, EC_WORD_COUPLE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emilia
    },
    [FRONTIER_TRAINER_DALIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("DALINA"),
        .speechBefore = {EC_WORD_RECOMMEND, EC_WORD_A_TINY_BIT, EC_WORD_BIKE, EC_WORD_A, EC_WORD_MONEY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_WORD_BIKE, EC_WORD_QUES},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_AROUND, EC_WORD_SPIRALING, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dalia
    },
    [FRONTIER_TRAINER_HITOMI] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("HITOM"),
        .speechBefore = {EC_WORD_OH_YEAH, EC_WORD_ARRGH, EC_WORD_OH_YEAH, EC_WORD_ARRGH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_DOWN, EC_WORD_NITWIT, EC_WORD_ISN_T_IT_QUES, EC_WORD_BEING, EC_WORD_QUES},
        .speechLose = {EC_WORD_AWW, EC_WORD_AWW, EC_WORD_AWW, EC_WORD_CRY, EC_WORD_OI_OI_OI, EC_WORD_SORRY},
        .monSet = gBattleFrontierTrainerMons_Hitomi
    },
    [FRONTIER_TRAINER_RICARDO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("LOREN"),
        .speechBefore = {EC_WORD_MAYBE, EC_WORD_FIGHTS, EC_WORD_CHOICE, EC_WORD_GWAH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YO, EC_WORD_LISTENING, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MODERN, EC_WORD_WHOAH, EC_WORD_GIVE_ME, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ricardo
    },
    [FRONTIER_TRAINER_SHIZUKA] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("SHIZUKA"),
        .speechBefore = {EC_WORD_SINCE, EC_WORD_LIKELY_TO, EC_WORD_IF, EC_WORD_LET_S, EC_WORD_INCREDIBLE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_VERY, EC_WORD_SECRET, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HAVE, EC_WORD_FOR_NOW, EC_WORD_LEVEL, EC_WORD_INCREDIBLE, EC_WORD_UP, EC_WORD_UP},
        .monSet = gBattleFrontierTrainerMons_Shizuka
    },
    [FRONTIER_TRAINER_JOANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("JOANA"),
        .speechBefore = {EC_WORD_BETTER, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_OVER, EC_WORD_COME_ON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THE, EC_WORD_BATTLE, EC_WORD_PLAYS, EC_MOVE2(ROAR), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_NITWIT, EC_WORD_IF, EC_WORD_ABSOLUTELY, EC_MOVE(OUTRAGE), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Joana
    },
    [FRONTIER_TRAINER_KELLY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ELI"),
        .speechBefore = {EC_WORD_PRETEND, EC_WORD_BE, EC_WORD_MUCH, EC_WORD_WHERE, EC_WORD_DON_T, EC_WORD_THING},
        .speechWin = {EC_WORD_I, EC_WORD_SEARCH, EC_WORD_LISTEN, EC_WORD_NATURALLY, EC_WORD_PERSON, EC_WORD_DESTROYED},
        .speechLose = {EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_NATURALLY, EC_WORD_PERSON, EC_WORD_DESTROYED, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kelly
    },
    [FRONTIER_TRAINER_RAYNA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("RANIA"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_POWER, EC_WORD_WAKES_UP, EC_WORD_FEELING, EC_WORD_FIGHTS, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_WHOM, EC_WORD_POWER, EC_WORD_ENOUGH, EC_WORD_WHERE, EC_WORD_QUES},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_HAS, EC_WORD_WAKES_UP, EC_WORD_FEELING, EC_WORD_LOSS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rayna
    },
    [FRONTIER_TRAINER_EVAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("BLASCO"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_BATTLE, EC_WORD_PRAISE, EC_WORD_MODE, EC_WORD_SPIRIT, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_WORD_SPIRIT, EC_WORD_FEELING, EC_WORD_FIGHTS, EC_WORD_IS, EC_WORD_FIERY},
        .speechLose = {EC_WORD_LOSS, EC_WORD_WITHOUT, EC_WORD_QUITE, EC_MOVE(HARDEN), EC_WORD_FEELING, EC_WORD_SPIRIT},
        .monSet = gBattleFrontierTrainerMons_Evan
    },
    [FRONTIER_TRAINER_JORDAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("MENDRO"),
        .speechBefore = {EC_WORD_ACCEPT, EC_WORD_I_VE_ARRIVED, EC_WORD_MOVE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_CAN_T, EC_WORD_NEAR, EC_WORD_GRAAAH, EC_WORD_GWAHAHAHA, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_WHERE, EC_WORD_LAY, EC_WORD_CAN, EC_WORD_WIN, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jordan
    },
    [FRONTIER_TRAINER_JOEL] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JIMENO"),
        .speechBefore = {EC_WORD_HEH, EC_WORD_HEH, EC_WORD_HEH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LALALA, EC_WORD_HIYAH, EC_WORD_LALALA, EC_WORD_LALALA, EC_WORD_HIYAH, EC_WORD_LALALA},
        .speechLose = {EC_WORD_OI_OI_OI, EC_WORD_CRY, EC_WORD_OI_OI_OI, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joel
    },
    [FRONTIER_TRAINER_KRISTEN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("DRILDA"),
        .speechBefore = {EC_WORD_CONCEDE, EC_WORD_NITWIT, EC_WORD_LET_S, EC_WORD_LOWS, EC_WORD_RECOMMEND, EC_WORD_FIGHTS},
        .speechWin = {EC_WORD_LET_S, EC_WORD_EXCITING, EC_WORD_LOWS, EC_WORD_RECOMMEND, EC_WORD_THIS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_DID, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_EVERY, EC_WORD_LOWS},
        .monSet = gBattleFrontierTrainerMons_Kristen
    },
    [FRONTIER_TRAINER_SELPHY] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("SELIA"),
        .speechBefore = {EC_WORD_HUH_QUES, EC_WORD_WHAT_S_UP_QUES, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HUH_QUES, EC_WORD_OH_QUES, EC_WORD_OH_QUES, EC_WORD_HEHEHE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_FUFUFU, EC_WORD_HEY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Selphy
    },
    [FRONTIER_TRAINER_CHLOE] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("CADILIA"),
        .speechBefore = {EC_WORD_EH_QUES, EC_WORD_EEK, EC_WORD_WOW, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_SINCE, EC_WORD_FIGHTS, EC_MOVE(ENCORE), EC_WORD_PLUS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_MOTHER, EC_WORD_MORE, EC_WORD_DOWN, EC_WORD_APPROVED, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Chloe
    },
    [FRONTIER_TRAINER_NORTON] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("NICANOR"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_ALT_COLOR, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_DID, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_HAVE, EC_WORD_ME},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_LET_S, EC_WORD_NATURALLY, EC_WORD_PERSON, EC_WORD_SCATTER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Norton
    },
    [FRONTIER_TRAINER_LUKAS] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("MENTO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_IT, EC_WORD_TOO_LATE, EC_WORD_THANKS, EC_WORD_QUES},
        .speechWin = {EC_WORD_USING, EC_WORD_ROCK_HEAD, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_SMARTNESS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_USING, EC_WORD_ROCK_HEAD, EC_WORD_IS, EC_WORD_VERY, EC_WORD_SMARTNESS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lukas
    },
    [FRONTIER_TRAINER_ZACH] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("ZAC"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_A_LITTLE, EC_MOVE2(MIMIC), EC_WORD_MISS, EC_WORD_TOO_LATE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_ISN_T_IT_QUES, EC_WORD_CUTENESS, EC_WORD_MEAN, EC_POKEMON_NATIONAL(TOGEPI), EC_WORD_EXCL},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_WILL_BE_HERE, EC_WORD_MEET, EC_WORD_MEAN, EC_POKEMON_NATIONAL(MANKEY), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zach
    },
    [FRONTIER_TRAINER_KAITLYN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("DRINA"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_PUSHOVER, EC_WORD_THINGS, EC_WORD_MISS, EC_WORD_VITAL_SPIRIT},
        .speechWin = {EC_WORD_JUST, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_LESS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HERE_GOES, EC_WORD_KTHX_BYE, EC_WORD_AGREE, EC_WORD_AGREE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kaitlyn
    },
    [FRONTIER_TRAINER_BREANNA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("LIREA"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_PURE_POWER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_GROUP, EC_WORD_EXCL},
        .speechLose = {EC_WORD_HAVE, EC_WORD_GUTS, EC_WORD_AND, EC_WORD_LET_S, EC_WORD_BECOMES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Breanna
    },
    [FRONTIER_TRAINER_KENDRA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("CANDI"),
        .speechBefore = {EC_WORD_IF, EC_WORD_LET_S, EC_WORD_GUTSY, EC_WORD_EEK, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LET_S, EC_WORD_GUTSY, EC_WORD_BUT, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_QUITE},
        .speechLose = {EC_WORD_LET_S, EC_WORD_GUTSY, EC_WORD_AND, EC_WORD_HAVE, EC_WORD_COOL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kendra
    },
    [FRONTIER_TRAINER_MOLLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("MILA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_CUTE_CHARM, EC_WORD_LAY, EC_WORD_WITHOUT, EC_MOVE2(ATTRACT), EC_WORD_QUES},
        .speechWin = {EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_MEAN, EC_WORD_TOO_LATE, EC_WORD_TOYS},
        .speechLose = {EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_AWFULLY, EC_WORD_CUTE_CHARM, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Molly
    },
    [FRONTIER_TRAINER_JAZMIN] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("JAZMINA"),
        .speechBefore = {EC_WORD_JUST, EC_WORD_FORECAST, EC_WORD_RECOMMEND, EC_WORD_REALLY, EC_WORD_IS, EC_WORD_HARD},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_WHERE, EC_WORD_WENT, EC_WORD_HAPPILY, EC_WORD_FORECAST, EC_WORD_QUES},
        .speechLose = {EC_WORD_JUST, EC_WORD_FORECAST, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_SAID, EC_WORD_THIS},
        .monSet = gBattleFrontierTrainerMons_Jazmin
    },
    [FRONTIER_TRAINER_KELSEY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("ELIA"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_PLAYS, EC_WORD_SLEPT, EC_WORD_THE, EC_WORD_THESE, EC_WORD_DAYS},
        .speechWin = {EC_WORD_NOW, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_ANIME, EC_WORD_VERY, EC_WORD_THING},
        .speechLose = {EC_WORD_WHERE, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_POWER, EC_WORD_ANIME, EC_WORD_PLUS},
        .monSet = gBattleFrontierTrainerMons_Kelsey
    },
    [FRONTIER_TRAINER_JALEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("DUREL"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_DOESN_T, EC_MOVE(THRASH), EC_WORD_LISTEN, EC_WORD_TOO_LATE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_HOHOHO, EC_WORD_BABY, EC_WORD_HUH_QUES, EC_WORD_OH_QUES, EC_WORD_GWAHAHAHA, EC_WORD_HEHEHE},
        .speechLose = {EC_WORD_THIS, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_IS, EC_WORD_FOR_NOW, EC_MOVE(THRASH)},
        .monSet = gBattleFrontierTrainerMons_Jalen
    },
    [FRONTIER_TRAINER_GRIFFEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("TRIFEN"),
        .speechBefore = {EC_WORD_FEELING, EC_MOVE2(SWALLOW), EC_MOVE2(SLUDGE), EC_WORD_ABSOLUTELY, EC_WORD_GO_EASY, EC_EMPTY_WORD},
        .speechWin = {EC_MOVE(GROWTH), EC_WORD_NATURALLY, EC_MOVE2(ACID_ARMOR), EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_MOVE(GROWTH), EC_WORD_SUCTION_CUPS, EC_WORD_SMOOTH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Griffen
    },
    [FRONTIER_TRAINER_XANDER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("CUAR"),
        .speechBefore = {EC_WORD_RECOMMEND, EC_WORD_FIGHTS, EC_WORD_I, EC_WORD_CHANGE, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ALWAYS, EC_WORD_IS, EC_WORD_ANTICIPATION, EC_WORD_A_TINY_BIT, EC_WORD_CHANGE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_CHANGE, EC_WORD_PLUS, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Xander
    },
    [FRONTIER_TRAINER_MARVIN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("PRESTO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_FIGHTS, EC_WORD_THE, EC_WORD_CHALLENGE, EC_WORD_QUES},
        .speechWin = {EC_WORD_INSIDE, EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_LIE, EC_WORD_AROUND, EC_WORD_SPIRALING},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_THING, EC_WORD_THANKS, EC_WORD_THANKS, EC_WORD_THANKS},
        .monSet = gBattleFrontierTrainerMons_Marvin
    },
    [FRONTIER_TRAINER_BRENNAN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("BRENAN"),
        .speechBefore = {EC_WORD_SINCE, EC_WORD_LIKELY_TO, EC_WORD_THAT_S, EC_WORD_TELEVISION, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ONLY, EC_WORD_COMICS, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_A_LOT},
        .speechLose = {EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_LIKELY_TO, EC_WORD_PLUS, EC_WORD_TELEVISION, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Brennan
    },
    [FRONTIER_TRAINER_BALEY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("BALENO"),
        .speechBefore = {EC_WORD_FOR_NOW, EC_MOVE(SCREECH), EC_WORD_IS, EC_WORD_MEAN, EC_WORD_FOR_NOW, EC_MOVE2(HOWL)},
        .speechWin = {EC_WORD_JUST, EC_WORD_STRATEGY, EC_MOVE(SCREECH), EC_WORD_IS, EC_WORD_THAT_S, EC_WORD_SPIRALING},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_DIDN_T, EC_WORD_SOUNDPROOF, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Baley
    },
    [FRONTIER_TRAINER_ZACKARY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("NACOR"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_LISTENS, EC_WORD_QUES},
        .speechWin = {EC_WORD_IF, EC_WORD_DIDN_T, EC_WORD_LISTENS, EC_WORD_PLUS, EC_WORD_COULD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CAN_T, EC_WORD_LISTENS, EC_WORD_BUT, EC_WORD_I, EC_WORD_WHERE, EC_WORD_CAN},
        .monSet = gBattleFrontierTrainerMons_Zackary
    },
    [FRONTIER_TRAINER_GABRIEL] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("BRIEL"),
        .speechBefore = {EC_MOVE2(BELLY_DRUM), EC_WORD_IS, EC_MOVE2(POUND), EC_WORD_AND, EC_WORD_THICK_FAT, EC_WORD_WHERE},
        .speechWin = {EC_WORD_JUST, EC_MOVE2(BELLY_DRUM), EC_WORD_IS, EC_WORD_VERY, EC_MOVE2(POUND), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_JUST, EC_MOVE2(BELLY_DRUM), EC_WORD_WHERE, EC_WORD_WENT, EC_MOVE2(POUND), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gabriel
    },
    [FRONTIER_TRAINER_EMILY] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("EMILI"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_A_LITTLE, EC_WORD_LIE, EC_MOVE(HYPNOSIS), EC_WORD_QUES},
        .speechWin = {EC_WORD_JUST, EC_WORD_STRATEGY, EC_MOVE(HYPNOSIS), EC_WORD_WALKS, EC_WORD_VERY, EC_WORD_THING},
        .speechLose = {EC_WORD_JUST, EC_WORD_STRATEGY, EC_MOVE(HYPNOSIS), EC_WORD_WHERE, EC_WORD_WALKS, EC_WORD_THING},
        .monSet = gBattleFrontierTrainerMons_Emily
    },
    [FRONTIER_TRAINER_JORDYN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("JOLEA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_LEFT, EC_WORD_NATURALLY, EC_WORD_SECRET_BASE, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_NATURALLY, EC_WORD_SECRET_BASE, EC_WORD_UP, EC_WORD_UP},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_SECRET_BASE, EC_WORD_IS, EC_MOVE2(PROTECT), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jordyn
    },
    [FRONTIER_TRAINER_SOFIA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("PETUNIA"),
        .speechBefore = {EC_POKEMON(LOUDRED), EC_WORD_DID, EC_WORD_AN, EC_WORD_FOR_NOW, EC_MOVE(SWEET_SCENT), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_DID, EC_WORD_NITWIT, EC_WORD_IS, EC_WORD_CUTENESS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_MOVE(SWEET_SCENT), EC_WORD_IS, EC_WORD_NATURALLY, EC_WORD_LOLLING, EC_MOVE2(PROTECT)},
        .monSet = gBattleFrontierTrainerMons_Sofia
    },
    [FRONTIER_TRAINER_BRADEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("BRADEN"),
        .speechBefore = {EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_EEK, EC_WORD_SMELL_YA, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCUSE_ME, EC_WORD_AVANT_GARDE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SHAKE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Braden
    },
    [FRONTIER_TRAINER_KAYDEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("CAIDEN"),
        .speechBefore = {EC_WORD_FEELING, EC_WORD_FIGHTS, EC_WORD_WHERE, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_OVERDO},
        .speechWin = {EC_WORD_OVERDO, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_JUST, EC_WORD_STRATEGY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OVERDO, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_JUST, EC_WORD_APPROVED, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kayden
    },
    [FRONTIER_TRAINER_COOPER] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("CUREO"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_WHO, EC_WORD_PRAISE, EC_WORD_NITWIT, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_TRUMP_CARD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LOL, EC_WORD_SORRY, EC_WORD_LOL, EC_WORD_LOL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Cooper
    },
    [FRONTIER_TRAINER_JULIA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("GENO"),
        .speechBefore = {EC_WORD_RECOMMEND, EC_WORD_WIN, EC_WORD_A, EC_WORD_PLUS, EC_WORD_NITWIT, EC_WORD_SPIRIT},
        .speechWin = {EC_WORD_THAT_S, EC_MOVE(NATURE_POWER), EC_WORD_IS, EC_WORD_VERY, EC_WORD_MATCH_UP, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GOOD_BYE, EC_WORD_HERE_IT_IS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Julia
    },
    [FRONTIER_TRAINER_AMARA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("AMARA"),
        .speechBefore = {EC_WORD_I_VE_ARRIVED, EC_WORD_YAY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_YUP, EC_WORD_BABY, EC_WORD_ELLIPSIS_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_URGH, EC_WORD_ARRGH, EC_WORD_AWW, EC_WORD_DESTINY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Amara
    },
    [FRONTIER_TRAINER_LYNN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("LIN"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_INVINCIBLE, EC_WORD_WHERE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_ISN_T_IT_QUES, EC_WORD_INVINCIBLE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_MOVE(SAFEGUARD), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lynn
    },
    [FRONTIER_TRAINER_JOVAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("JOVAN"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_SPIRIT, EC_WORD_LIE, EC_WORD_BATTLE, EC_WORD_QUES},
        .speechWin = {EC_WORD_WHOM, EC_WORD_A_LOT, EC_WORD_SPIRIT, EC_WORD_LIE, EC_WORD_BATTLE, EC_WORD_OH_QUES},
        .speechLose = {EC_WORD_JUST, EC_WORD_SPIRIT, EC_WORD_WHERE, EC_MOVE2(ASSIST), EC_WORD_QUITE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jovan
    },
    [FRONTIER_TRAINER_DOMINIC] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("DOMINIC"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_A_LOT, EC_WORD_PROBABLY, EC_WORD_SHOPPING, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_SPIRALING, EC_WORD_NITWIT, EC_WORD_PROBABLY, EC_WORD_SHOPPING},
        .speechLose = {EC_WORD_PROBABLY, EC_WORD_SHOPPING, EC_WORD_WHERE, EC_WORD_AROUND, EC_WORD_WAS, EC_WORD_CASE},
        .monSet = gBattleFrontierTrainerMons_Dominic
    },
    [FRONTIER_TRAINER_NIKOLAS] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("NICO"),
        .speechBefore = {EC_WORD_THE, EC_WORD_BATTLE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_USING, EC_MOVE2(MIMIC)},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_SINCE, EC_WORD_FORGETS, EC_WORD_FOR_NOW, EC_POKEMON_NATIONAL(TAUROS), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IF, EC_WORD_FAINTED, EC_WORD_SINCE, EC_WORD_FORGETS, EC_WORD_FOR_NOW, EC_POKEMON_NATIONAL(MILTANK)},
        .monSet = gBattleFrontierTrainerMons_Nikolas
    },
    [FRONTIER_TRAINER_VALERIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("LERITA"),
        .speechBefore = {EC_WORD_THINKS, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_CAN_T, EC_MOVE2(GLARE)},
        .speechWin = {EC_WORD_DOES, EC_WORD_NITWIT, EC_WORD_DIDN_T, EC_MOVE2(GLARE), EC_WORD_HEHE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_WORD_HAS, EC_WORD_AWFULLY, EC_MOVE(SCARY_FACE), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Valeria
    },
    [FRONTIER_TRAINER_DELANEY] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("DELINA"),
        .speechBefore = {EC_WORD_AROUND, EC_WORD_BORING, EC_WORD_IS, EC_WORD_BAD, EC_WORD_EEK, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_KNOW, EC_WORD_LISTEN, EC_WORD_JUST, EC_WORD_TO_WHOM, EC_WORD_FROM, EC_WORD_ALWAYS},
        .speechLose = {EC_WORD_SOON, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_WORKING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Delaney
    },
    [FRONTIER_TRAINER_MEGHAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("MEGAN"),
        .speechBefore = {EC_WORD_IS, EC_WORD_BORING, EC_WORD_WHERE, EC_WORD_FIGHTS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_WORD_TO_WHOM, EC_WORD_PRAISE, EC_WORD_COMICS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SOON, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Meghan
    },
    [FRONTIER_TRAINER_ROBERTO] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("ROBER"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_DRAGON, EC_WORD_IS, EC_WORD_INVINCIBLE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TIMES, EC_WORD_NITWIT, EC_WORD_ISN_T_IT_QUES, EC_WORD_SPIRALING, EC_WORD_SORRY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_FIGHTS, EC_WORD_INSIDE, EC_WORD_PLUS, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Roberto
    },
    [FRONTIER_TRAINER_DAMIAN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DAMI"),
        .speechBefore = {EC_WORD_JUST, EC_WORD_PURE_POWER, EC_WORD_IS, EC_WORD_VERY, EC_WORD_APPROVED, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_MOVE2(MACH_PUNCH), EC_MOVE2(ASSIST), EC_WORD_LISTEN, EC_MOVE(BRICK_BREAK), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OH, EC_WORD_EXCUSE, EC_WORD_YO, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Damian
    },
    [FRONTIER_TRAINER_BRODY] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("BRODI"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_A_LOT, EC_WORD_LIE, EC_WORD_FASHION, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THE, EC_WORD_JUST, EC_WORD_FAMILY, EC_WORD_THERE, EC_WORD_ONLY, EC_WORD_POKEMON},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_THAT_S, EC_WORD_FASHION, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Brody
    },
    [FRONTIER_TRAINER_GRAHAM] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DREGO"),
        .speechBefore = {EC_WORD_OH_YEAH, EC_WORD_OH_YEAH, EC_WORD_OH_YEAH, EC_WORD_UH_HUH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_GWAHAHAHA, EC_WORD_GWAHAHAHA, EC_WORD_GWAHAHAHA, EC_WORD_UH_HUH, EC_WORD_UH_HUH, EC_WORD_UH_HUH},
        .speechLose = {EC_WORD_CRIES, EC_WORD_SORRY, EC_WORD_COME_OVER, EC_WORD_CRIES, EC_WORD_CRIES, EC_WORD_CRIES},
        .monSet = gBattleFrontierTrainerMons_Graham
    },
    [FRONTIER_TRAINER_TYLOR] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("TONIO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_LIKELY_TO, EC_WORD_JUST, EC_MOVE2(HEAT_WAVE), EC_WORD_QUES},
        .speechWin = {EC_WORD_FIGHT, EC_WORD_MISS, EC_WORD_THAT_S, EC_WORD_STRONG, EC_WORD_HIT, EC_WORD_FIRE},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_FIGHTS, EC_WORD_MISS, EC_WORD_PLUS, EC_WORD_FIRE},
        .monSet = gBattleFrontierTrainerMons_Tylor
    },
    [FRONTIER_TRAINER_JAREN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("JARE"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_SPIRIT, EC_WORD_LIE, EC_WORD_GUARD, EC_WORD_QUES},
        .speechWin = {EC_WORD_SINCE, EC_WORD_POKEMON, EC_WORD_MISS, EC_WORD_CUTE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_DID, EC_WORD_NITWIT, EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_CUTE},
        .monSet = gBattleFrontierTrainerMons_Jaren
    },
    [FRONTIER_TRAINER_CORDELL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("JUACO"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_BATTLE, EC_WORD_IS, EC_WORD_SPIRIT, EC_WORD_AND, EC_WORD_PURE_POWER},
        .speechWin = {EC_WORD_BE, EC_WORD_LOW, EC_WORD_IS, EC_WORD_SHALLOW, EC_WORD_MATCH_UP, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_A_TINY_BIT, EC_WORD_SPIRIT, EC_WORD_IS, EC_MOVE(ENDEAVOR), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Cordell
    },
    [FRONTIER_TRAINER_JAZLYN] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("JALIZA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_NATURALLY, EC_WORD_HAPPILY, EC_WORD_POKEDEX, EC_WORD_QUES},
        .speechWin = {EC_WORD_HMM, EC_WORD_AWFULLY, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_BEING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AN, EC_WORD_NATURALLY, EC_WORD_HAPPILY, EC_WORD_POKEDEX, EC_MOVE2(ASSIST), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jazlyn
    },
    [FRONTIER_TRAINER_ZACHERY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("ZARO"),
        .speechBefore = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_HAS, EC_WORD_LIE, EC_WORD_FIGHTS},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_VERY, EC_WORD_ANTICIPATION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_THING, EC_WORD_WILL_BE_HERE, EC_WORD_THING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Zachery
    },
    [FRONTIER_TRAINER_JOHAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("LUISMI"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_WINTER, EC_WORD_IS, EC_WORD_FIGHTING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_ALWAYS, EC_WORD_ALLOWANCE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_PLUS, EC_WORD_ALLOWANCE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Johan
    },
    [FRONTIER_TRAINER_SHEA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("SHEA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_WONDER, EC_WORD_LISTEN, EC_WORD_USING, EC_WORD_BEAUTY, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_USE, EC_WORD_THAT_S, EC_WORD_BEAUTY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WENT, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_BEAUTIFUL, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Shea
    },
    [FRONTIER_TRAINER_KAILA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("CAILA"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_LEFT, EC_WORD_SURPRISE, EC_WORD_SIGH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AROUND, EC_WORD_NITWIT, EC_WORD_A, EC_WORD_IS, EC_WORD_FOR_NOW, EC_MOVE2(MILK_DRINK)},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_WHOM, EC_WORD_NITWIT, EC_MOVE2(SWALLOW), EC_WORD_THIS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kaila
    },
    [FRONTIER_TRAINER_ISIAH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("ISERO"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_PRETEND, EC_WORD_FEELING, EC_WORD_HOBBY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BUT, EC_WORD_HOBBY, EC_WORD_IS, EC_WORD_MATCH_UP, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_HOBBY, EC_WORD_PLUS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Isiah
    },
    [FRONTIER_TRAINER_GARRETT] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("MONTI"),
        .speechBefore = {EC_WORD_HIGH, EC_WORD_ONLY, EC_WORD_COMICS, EC_WORD_LISTEN, EC_WORD_ONLY, EC_WORD_BOARD},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_THAT_S, EC_WORD_MUSIC, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BUT, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_WORD_HI, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Garrett
    },
    [FRONTIER_TRAINER_HAYLIE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ARINA"),
        .speechBefore = {EC_WORD_CONCEDE, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_SLEEP, EC_WORD_THING, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_VICTORY, EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_MOVE2(CALM_MIND), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_INSOMNIA, EC_WORD_IS, EC_WORD_SHALLOW, EC_WORD_BAD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Haylie
    },
    [FRONTIER_TRAINER_MEGAN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("MABEL"),
        .speechBefore = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_JUST, EC_MOVE(AROMATHERAPY), EC_WORD_IS, EC_WORD_DESTROYED},
        .speechWin = {EC_WORD_FOR_NOW, EC_WORD_CLEAR_BODY, EC_WORD_WEREN_T, EC_WORD_WIN, EC_WORD_THING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_PLUS, EC_WORD_MONEY, EC_WORD_RECOMMEND, EC_MOVE(AROMATHERAPY), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Megan
    },
    [FRONTIER_TRAINER_ISSAC] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("CHECHU"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_AROUND, EC_WORD_NITWIT, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_QUES},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_A_TINY_BIT, EC_MOVE2(WATER_SPORT), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_MOVE2(MUD_SPORT), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Issac
    },
    [FRONTIER_TRAINER_QUINTON] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("LUISMA"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_THING, EC_WORD_I, EC_WORD_DOES, EC_WORD_FIGHTS, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_VERY, EC_WORD_APPROVED},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_SAD, EC_WORD_HOWEVER, EC_WORD_BE, EC_WORD_FUNNY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Quinton
    },
    [FRONTIER_TRAINER_SALMA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("SALMA"),
        .speechBefore = {EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_FIGHTS, EC_WORD_MISS, EC_WORD_HUSTLE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WIN, EC_WORD_WITHOUT, EC_WORD_A_LOT, EC_WORD_HUSTLE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_HUSTLE, EC_WORD_WHERE, EC_WORD_UM, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Salma
    },
    [FRONTIER_TRAINER_ANSLEY] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("SELA"),
        .speechBefore = {EC_WORD_IS, EC_WORD_BORING, EC_WORD_WHERE, EC_WORD_AN, EC_WORD_RIVAL, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_BATTLE, EC_WORD_WENT, EC_WORD_VERY, EC_WORD_BORING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THAT_S, EC_MOVE2(FRUSTRATION), EC_WORD_WHERE, EC_MOVE2(ASSIST), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ansley
    },
    [FRONTIER_TRAINER_HOLDEN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("HOLI"),
        .speechBefore = {EC_WORD_FIGHTS, EC_WORD_MISS, EC_WORD_COOL, EC_WORD_WEREN_T, EC_WORD_CAUSE, EC_MOVE(UPROAR)},
        .speechWin = {EC_WORD_LET_S, EC_WORD_FUNNY, EC_WORD_RECOMMEND, EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_BUG},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_BATTLE, EC_WORD_WENT, EC_WORD_BADLY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Holden
    },
    [FRONTIER_TRAINER_LUCA] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("MONE"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_NATURALLY, EC_WORD_HAPPILY, EC_WORD_GUARD},
        .speechWin = {EC_WORD_JUST, EC_WORD_VICTORY, EC_WORD_WENT, EC_WORD_BEING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_YOU, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_LET_S, EC_WORD_BEING, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Luca
    },
    [FRONTIER_TRAINER_JAMISON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("KATON"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_NITWIT, EC_WORD_IF, EC_WORD_WHOM, EC_MOVE2(SECRET_POWER), EC_WORD_QUES},
        .speechWin = {EC_WORD_JUST, EC_MOVE2(SECRET_POWER), EC_WORD_IS, EC_WORD_INCREDIBLE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_MOVE(SMOKESCREEN), EC_WORD_GOOD_BYE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jamison
    },
    [FRONTIER_TRAINER_GUNNAR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("KETON"),
        .speechBefore = {EC_MOVE(CUT), EC_WORD_IS, EC_WORD_APPROVED, EC_WORD_RECOMMEND, EC_WORD_A_TINY_BIT, EC_WORD_RIVAL},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_WITHOUT, EC_MOVE(GRUDGE), EC_WORD_LOSS, EC_WORD_QUES},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_AN, EC_WORD_NATURALLY, EC_MOVE(SCARY_FACE), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gunnar
    },
    [FRONTIER_TRAINER_CRAIG] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("YEROE"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_CAN, EC_WORD_LOSS, EC_WORD_LOCOMOTIVE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ONLY, EC_WORD_LOCOMOTIVE, EC_WORD_WAS, EC_WORD_RECOMMEND, EC_WORD_TRAVEL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_TRAVEL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Craig
    },
    [FRONTIER_TRAINER_PIERCE] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("LERO"),
        .speechBefore = {EC_WORD_NATURALLY, EC_MOVE2(HEAT_WAVE), EC_WORD_WEREN_T, EC_WORD_BE, EC_WORD_SLIMY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_CLOUD_NINE, EC_WORD_IS, EC_WORD_SHALLOW, EC_WORD_MATCH_UP, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HIGH, EC_WORD_A_TINY_BIT, EC_MOVE(HAIL), EC_WORD_LISTEN, EC_WORD_THAT_S, EC_MOVE2(HEAT_WAVE)},
        .monSet = gBattleFrontierTrainerMons_Pierce
    },
    [FRONTIER_TRAINER_REGINA] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("REGINA"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_WORD_CHILD_S_PLAY, EC_WORD_THE, EC_WORD_WATER},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_MOVE(WATER_SPOUT), EC_WORD_MISS, EC_WORD_WATER, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_PLUS, EC_WORD_WATER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Regina
    },
    [FRONTIER_TRAINER_ALISON] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ALISON"),
        .speechBefore = {EC_WORD_THAT_S, EC_WORD_LIFE, EC_WORD_IS, EC_WORD_BREAK, EC_WORD_AND, EC_WORD_NATURAL},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_BREAK, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_A_LITTLE, EC_WORD_HAPPY, EC_WORD_SURRENDER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alison
    },
    [FRONTIER_TRAINER_HANK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("HILARIO"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_BUG, EC_WORD_SHADY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_BUG, EC_WORD_DON_T, EC_WORD_LIE, EC_WORD_FASHION},
        .speechLose = {EC_WORD_INSIDE, EC_WORD_HIGH, EC_WORD_FEELING, EC_WORD_TYPE, EC_WORD_BUG, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hank
    },
    [FRONTIER_TRAINER_EARL] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("ENARO"),
        .speechBefore = {EC_WORD_HERE, EC_WORD_DON_T, EC_WORD_A_TINY_BIT, EC_WORD_TRAINER, EC_WORD_PLUS, EC_WORD_BUG},
        .speechWin = {EC_WORD_PLAYS, EC_WORD_SCARY, EC_WORD_MISS, EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_BUG},
        .speechLose = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_WHERE, EC_WORD_WAS, EC_WORD_TWIRLING},
        .monSet = gBattleFrontierTrainerMons_Earl
    },
    [FRONTIER_TRAINER_RAMIRO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("RAMIRO"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_BEFORE, EC_WORD_THINGS, EC_WORD_RECOMMEND, EC_WORD_FISHING, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_RECOMMEND, EC_WORD_FISHING, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_CLOSE},
        .speechLose = {EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_IF, EC_WORD_SINCE, EC_WORD_FISHING, EC_WORD_PLUS},
        .monSet = gBattleFrontierTrainerMons_Ramiro
    },
    [FRONTIER_TRAINER_HUNTER] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("TARIO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_ABSOLUTELY, EC_WORD_TEACHES, EC_WORD_FOR_NOW, EC_MOVE(CROSS_CHOP), EC_WORD_QUES},
        .speechWin = {EC_WORD_LET_S, EC_WORD_VERY, EC_WORD_FUNNY, EC_WORD_RECOMMEND, EC_WORD_FOR_NOW, EC_MOVE(CROSS_CHOP)},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_USING, EC_MOVE(CROSS_CHOP), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Hunter
    },
    [FRONTIER_TRAINER_AIDEN] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("AIDEN"),
        .speechBefore = {EC_WORD_JUST, EC_WORD_WORK, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_ME, EC_WORD_ROCK_SOLID},
        .speechWin = {EC_WORD_YOU, EC_WORD_UP, EC_WORD_NITWIT, EC_WORD_LET_S, EC_WORD_NATURALLY, EC_WORD_ROCK_SOLID},
        .speechLose = {EC_WORD_LOSS, EC_WORD_IS, EC_WORD_NATURALLY, EC_WORD_DESTROYED, EC_WORD_ROCK_SOLID, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Aiden
    },
    [FRONTIER_TRAINER_XAVIER] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("XAVIER"),
        .speechBefore = {EC_WORD_HEH, EC_WORD_HEH, EC_WORD_OOPS, EC_WORD_OOPS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_UNBELIEVABLE, EC_WORD_SEE_YA, EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHOAH, EC_WORD_SIGH, EC_WORD_OH_DEAR, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Xavier
    },
    [FRONTIER_TRAINER_CLINTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("CELES"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_LIKELY_TO, EC_WORD_JUST, EC_MOVE(HYPNOSIS), EC_WORD_QUES},
        .speechWin = {EC_WORD_AS_MUCH_AS, EC_MOVE2(FURY_SWIPES), EC_WORD_AND, EC_WORD_AWFULLY, EC_WORD_STRONG, EC_WORD_IT},
        .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCITING, EC_WORD_FUNNY, EC_WORD_FUFUFU, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Clinton
    },
    [FRONTIER_TRAINER_JESSE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("JERO"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_BATTLE, EC_WORD_IS, EC_WORD_RECOMMEND, EC_WORD_JUST, EC_WORD_MOTHER},
        .speechWin = {EC_WORD_JUST, EC_WORD_MOTHER, EC_WORD_DON_T, EC_WORD_LONESOME, EC_WORD_NEAR, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OH_DEAR, EC_WORD_AWW, EC_WORD_CRY, EC_WORD_FUFUFU, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jesse
    },
    [FRONTIER_TRAINER_EDUARDO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("DUARDO"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_CASE, EC_WORD_TYPE, EC_WORD_LIE, EC_WORD_MUSIC},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_MUSIC, EC_WORD_AROUND, EC_WORD_IS, EC_WORD_CASE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_ONCE, EC_WORD_THING, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Eduardo
    },
    [FRONTIER_TRAINER_HAL] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("HIGINIO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_IF, EC_WORD_WILL_BE_HERE, EC_WORD_LIE, EC_WORD_FASHION, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_WILL_BE_HERE, EC_WORD_LIE, EC_WORD_FASHION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WIN, EC_WORD_DON_T, EC_WORD_LIE, EC_WORD_FASHION, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hal
    },
    [FRONTIER_TRAINER_GAGE] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("GAGOR"),
        .speechBefore = {EC_WORD_ONLY, EC_WORD_POKEMON, EC_WORD_LIE, EC_WORD_TYPE, EC_WORD_FLYING, EC_WORD_IT},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_POKEMON, EC_WORD_FLYING, EC_WORD_FEELING, EC_WORD_POWER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_MOVE(FLY)},
        .monSet = gBattleFrontierTrainerMons_Gage
    },
    [FRONTIER_TRAINER_ARNOLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("AVELINO"),
        .speechBefore = {EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_MOVE2(SLEEP_TALK), EC_WORD_SHOCKED, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ALWAYS, EC_WORD_WHOM, EC_WORD_FOR_NOW, EC_WORD_INSOMNIA, EC_WORD_HOPELESS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOW, EC_WORD_UP, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_AN, EC_WORD_INSOMNIA},
        .monSet = gBattleFrontierTrainerMons_Arnold
    },
    [FRONTIER_TRAINER_JARRETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("JARANO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_DANCE, EC_WORD_A_LITTLE, EC_WORD_NEAR, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOURS, EC_WORD_OPPOSITE, EC_WORD_MEAN, EC_WORD_I, EC_WORD_DOES, EC_WORD_DANCE},
        .speechLose = {EC_WORD_SOMEONE, EC_WORD_OPPOSITE, EC_WORD_A_LOT, EC_WORD_SPIRALING, EC_WORD_NITWIT, EC_WORD_I},
        .monSet = gBattleFrontierTrainerMons_Jarrett
    },
    [FRONTIER_TRAINER_GARETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("GRETO"),
        .speechBefore = {EC_WORD_JUST, EC_WORD_WHOSE, EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_WORD_FOR_NOW, EC_MOVE2(SWEET_KISS)},
        .speechWin = {EC_WORD_JUST, EC_WORD_WHOSE, EC_WORD_IS, EC_WORD_JUST, EC_WORD_LOLLING, EC_WORD_WHO_WAS},
        .speechLose = {EC_WORD_IS, EC_WORD_SHALLOW, EC_WORD_MATCH_UP, EC_WORD_AN, EC_WORD_ALWAYS, EC_WORD_GROUP},
        .monSet = gBattleFrontierTrainerMons_Garett
    },
    [FRONTIER_TRAINER_EMANUEL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("EMANUEL"),
        .speechBefore = {EC_WORD_BE, EC_WORD_SMARTNESS, EC_WORD_WHERE, EC_WORD_AROUND, EC_WORD_IS, EC_WORD_CASE},
        .speechWin = {EC_WORD_WHERE, EC_WORD_ISN_T_IT_QUES, EC_WORD_SMARTNESS, EC_WORD_BUT, EC_WORD_DOES, EC_WORD_WIN},
        .speechLose = {EC_WORD_WENT, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_MOVE2(FAKE_OUT), EC_WORD_OH_QUES, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emanuel
    },
    [FRONTIER_TRAINER_GUSTAVO] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("GUSTAVO"),
        .speechBefore = {EC_WORD_EXCL_EXCL, EC_MOVE(CHARGE), EC_MOVE(CHARGE), EC_WORD_AND, EC_MOVE(CHARGE), EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_S, EC_MOVE(CHARGE), EC_WORD_IS, EC_WORD_LEFT, EC_WORD_VERY, EC_WORD_AWFUL},
        .speechLose = {EC_WORD_NOW, EC_WORD_TIMES, EC_WORD_NATURALLY, EC_WORD_LOLLING, EC_MOVE(CHARGE), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gustavo
    },
    [FRONTIER_TRAINER_KAMERON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("RUDEO"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_NITWIT, EC_WORD_CAN, EC_WORD_WIN, EC_WORD_MISS, EC_MOVE2(TRICK)},
        .speechWin = {EC_WORD_MISS, EC_MOVE2(TRICK), EC_WORD_DOES, EC_WORD_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_DOWN, EC_MOVE2(TRICK), EC_WORD_HAVE, EC_WORD_YOU, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Kameron
    },
    [FRONTIER_TRAINER_ALFREDO] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("ALFRED"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_DIET, EC_WORD_MEAN, EC_WORD_A_TINY_BIT, EC_WORD_SPIRALING, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_RECOMMEND, EC_WORD_DIET, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_AWAY},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_INFORMATION, EC_WORD_PLUS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Alfredo
    },
    [FRONTIER_TRAINER_RUBEN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("RUBE"),
        .speechBefore = {EC_WORD_LISTEN, EC_WORD_DAILY, EC_WORD_WHOM, EC_WORD_FOR_NOW, EC_WORD_SPIRIT, EC_WORD_ANTICIPATION},
        .speechWin = {EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_AN, EC_WORD_SPIRALING, EC_WORD_SPIRIT, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_NATURALLY, EC_MOVE(RECOVER), EC_WORD_LIE, EC_WORD_SPIRIT, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ruben
    },
    [FRONTIER_TRAINER_LAMAR] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("LENER"),
        .speechBefore = {EC_WORD_RECOMMEND, EC_WORD_FIGHTS, EC_WORD_BELONGS_TO, EC_WORD_MUST_BE, EC_WORD_RULE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_RECOMMEND, EC_WORD_FIGHTS, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_LUKEWARM},
        .speechLose = {EC_WORD_RECOMMEND, EC_WORD_REALLY, EC_WORD_WENT, EC_WORD_MEAN, EC_WORD_FOR_NOW, EC_WORD_CHILD_S_PLAY},
        .monSet = gBattleFrontierTrainerMons_Lamar
    },
    [FRONTIER_TRAINER_JAXON] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("JULIO"),
        .speechBefore = {EC_WORD_A, EC_WORD_CHOICE, EC_WORD_FOR_NOW, EC_WORD_SHELL_ARMOR, EC_WORD_LIE, EC_WORD_THESE_WERE},
        .speechWin = {EC_WORD_JUST, EC_WORD_FATHER, EC_WORD_PRAISE, EC_WORD_FOR_NOW, EC_WORD_SHELL_ARMOR, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_NITWIT, EC_WORD_SINCE, EC_WORD_FOR_NOW, EC_WORD_SHELL_ARMOR, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jaxon
    },
    [FRONTIER_TRAINER_LOGAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("LOLO"),
        .speechBefore = {EC_WORD_IF, EC_WORD_FAINTED, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_HOBBY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_HOBBY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_WORD_UP},
        .monSet = gBattleFrontierTrainerMons_Logan
    },
    [FRONTIER_TRAINER_EMILEE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("EMILINA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_WORD_BATTLE, EC_WORD_QUES},
        .speechWin = {EC_MOVE(ICY_WIND), EC_WORD_AND, EC_MOVE2(SURF), EC_WORD_WAS, EC_WORD_LEFT, EC_WORD_TWIRLING},
        .speechLose = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_MOVE(ROCK_SLIDE), EC_WORD_DON_T, EC_WORD_A_LOT, EC_WORD_SPIRALING},
        .monSet = gBattleFrontierTrainerMons_Emilee
    },
    [FRONTIER_TRAINER_JOSIE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("SEFINA"),
        .speechBefore = {EC_WORD_I, EC_WORD_CONTEST, EC_WORD_THE, EC_WORD_THAT_S, EC_WORD_LET_ME_WIN, EC_WORD_BEAUTY},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_BEAUTY, EC_WORD_DON_T, EC_WORD_LIE, EC_WORD_FASHION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_WIN, EC_WORD_THE, EC_WORD_BEAUTY},
        .monSet = gBattleFrontierTrainerMons_Josie
    },
    [FRONTIER_TRAINER_ARMANDO] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("MANDI"),
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_LIE, EC_WORD_TYPE, EC_WORD_GRASS, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LAY, EC_WORD_CHANGE, EC_WORD_POKEMON, EC_WORD_HOWEVER, EC_WORD_TYPE, EC_WORD_GRASS},
        .speechLose = {EC_WORD_WHERE, EC_WORD_CAN, EC_WORD_WIN, EC_WORD_MISS, EC_WORD_TYPE, EC_WORD_GRASS},
        .monSet = gBattleFrontierTrainerMons_Armando
    },
    [FRONTIER_TRAINER_SKYLER] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("NERIO"),
        .speechBefore = {EC_MOVE2(INGRAIN), EC_WORD_IS, EC_WORD_MISS, EC_WORD_AROUND, EC_WORD_NITWIT, EC_WORD_ATTACK},
        .speechWin = {EC_WORD_ATTACK, EC_WORD_MEAN, EC_WORD_SPIRALING, EC_WORD_DOES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_SERIOUSLY, EC_WORD_WINS, EC_WORD_IF, EC_WORD_ARE, EC_WORD_TRUANT},
        .monSet = gBattleFrontierTrainerMons_Skyler
    },
    [FRONTIER_TRAINER_RUTH] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("RENATA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WENT, EC_WORD_EXCITING, EC_WORD_WEAKENED, EC_WORD_AND, EC_WORD_BORING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HEH, EC_WORD_NO, EC_WORD_COME_OVER, EC_WORD_COUNT_ON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ruth
    },
    [FRONTIER_TRAINER_MELODY] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("MELODI"),
        .speechBefore = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_A_TINY_BIT, EC_WORD_SUNDAY, EC_WORD_WENT, EC_MOVE2(SUNNY_DAY)},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_SUNDAY, EC_WORD_IS, EC_WORD_RECOMMEND, EC_WORD_ANIME, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_COLD, EC_WORD_NITWIT, EC_WORD_TODAY, EC_WORD_WHERE, EC_WORD_IS, EC_MOVE2(SUNNY_DAY)},
        .monSet = gBattleFrontierTrainerMons_Melody
    },
    [FRONTIER_TRAINER_PEDRO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("PETRO"),
        .speechBefore = {EC_WORD_SWIFT_SWIM, EC_WORD_IS, EC_WORD_ELSE, EC_WORD_AND, EC_WORD_VERY, EC_WORD_BADLY},
        .speechWin = {EC_WORD_MISS, EC_WORD_SWIFT_SWIM, EC_WORD_CAN, EC_WORD_PUSHOVER, EC_WORD_FEELING, EC_WORD_RIVAL},
        .speechLose = {EC_WORD_TIMES, EC_WORD_FOR_NOW, EC_WORD_APPROVED, EC_MOVE2(WHIRLWIND), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Pedro
    },
    [FRONTIER_TRAINER_ERICK] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("ERIC"),
        .speechBefore = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_MOVE2(TACKLE), EC_WORD_WHERE, EC_WORD_DECIDE},
        .speechWin = {EC_WORD_CAN_T_WIN, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_WEAKENED, EC_WORD_OH_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_MOVE(COUNTER), EC_WORD_IS, EC_WORD_RIPPED, EC_WORD_LIE, EC_WORD_THESE_WERE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Erick
    },
    [FRONTIER_TRAINER_ELAINE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("ELIANA"),
        .speechBefore = {EC_WORD_ONLY, EC_WORD_HERO, EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_A_LOT, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WAY, EC_WORD_WAHAHAHA, EC_WORD_THANK_YOU, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_ISN_T_IT_QUES, EC_WORD_EXCITING, EC_WORD_BEING, EC_WORD_WHERE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Elaine
    },
    [FRONTIER_TRAINER_JOYCE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("JOSEFA"),
        .speechBefore = {EC_WORD_I_VE_ARRIVED, EC_WORD_APPRECIATE, EC_WORD_EH_QUES, EC_WORD_GWAH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HIYAH, EC_WORD_HIYAH, EC_WORD_EXCUSE_ME, EC_WORD_HIYAH, EC_WORD_HIYAH, EC_WORD_SEE_YA},
        .speechLose = {EC_WORD_OH_DEAR, EC_WORD_HEHE, EC_WORD_HUMPH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joyce
    },
    [FRONTIER_TRAINER_TODD] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("TICHU"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_FOR_NOW, EC_WORD_LIGHTNINGROD, EC_WORD_RECOMMEND, EC_WORD_JUST, EC_WORD_POWER},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_WHERE, EC_WORD_CAN_T, EC_MOVE(ABSORB), EC_WORD_PLUS, EC_WORD_QUES},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_USING, EC_MOVE2(REFLECT), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Todd
    },
    [FRONTIER_TRAINER_GAVIN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("GASTONI"),
        .speechBefore = {EC_WORD_IS, EC_WORD_THAT_S, EC_WORD_TIME, EC_WORD_LIE, EC_WORD_THAT_S, EC_MOVE(BIDE)},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_MOVE(BIDE), EC_WORD_QUES},
        .speechLose = {EC_WORD_NOW, EC_WORD_WHOM, EC_WORD_PLUS, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_MOVE(BIDE)},
        .monSet = gBattleFrontierTrainerMons_Gavin
    },
    [FRONTIER_TRAINER_MALORY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("MALORI"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_TEACH, EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_HEHEHE, EC_WORD_WHOM, EC_WORD_POKEMON, EC_WORD_LIE, EC_WORD_THESE_WERE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_ABSOLUTELY, EC_WORD_TEACHES, EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Malory
    },
    [FRONTIER_TRAINER_ESTHER] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("ESTER"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_ONLY, EC_WORD_RPG, EC_WORD_LIE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_SINCE, EC_WORD_PLUS, EC_WORD_RPG, EC_WORD_LIE, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOW, EC_WORD_HIGH, EC_WORD_FOR_NOW, EC_WORD_HEROINE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Esther
    },
    [FRONTIER_TRAINER_OSCAR] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("OSCARIO"),
        .speechBefore = {EC_WORD_SINCE, EC_WORD_LIKELY_TO, EC_WORD_CASE, EC_WORD_AWFULLY, EC_WORD_POWER, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DOES, EC_WORD_NITWIT, EC_WORD_HAVE, EC_WORD_PLUS, EC_WORD_POWER, EC_WORD_INSIDE},
        .speechLose = {EC_WORD_HAVE, EC_WORD_EXCITING, EC_WORD_POWER, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Oscar
    },
    [FRONTIER_TRAINER_WILSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("ILSON"),
        .speechBefore = {EC_WORD_HOWEVER, EC_WORD_A_TINY_BIT, EC_WORD_WORK, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_EARLY_BIRD},
        .speechWin = {EC_WORD_FEELING, EC_WORD_WORKING, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_ALONE},
        .speechLose = {EC_WORD_THE, EC_WORD_A_TINY_BIT, EC_WORD_WORK, EC_WORD_A, EC_WORD_PLUS, EC_MOVE(ENDURE)},
        .monSet = gBattleFrontierTrainerMons_Wilson
    },
    [FRONTIER_TRAINER_CLARE] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("CLARITA"),
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_ISN_T_IT_QUES, EC_WORD_VERY, EC_WORD_HAPPILY, EC_WORD_ALT_COLOR, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HEY_THERE, EC_WORD_ISN_T_IT_QUES, EC_WORD_BEING, EC_WORD_ALT_COLOR, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MMM, EC_WORD_ISN_T_IT_QUES, EC_WORD_NORMAL, EC_WORD_ALT_COLOR, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Clare
    },
    [FRONTIER_TRAINER_TESS] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("TESA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_FOR_NOW, EC_WORD_CUTENESS, EC_POKEMON(GULPIN), EC_WORD_QUES},
        .speechWin = {EC_POKEMON(GULPIN), EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_VERY, EC_WORD_CUTENESS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WENT, EC_WORD_EXCITING, EC_WORD_BREAK, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Tess
    },
    [FRONTIER_TRAINER_LEON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("LEONI"),
        .speechBefore = {EC_WORD_ALT_COLOR, EC_WORD_WHERE, EC_WORD_BELONGS_TO, EC_WORD_YOURS, EC_WORD_MEAN, EC_WORD_I},
        .speechWin = {EC_MOVE2(JUMP_KICK), EC_WORD_SHADY, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_MOVE2(JUMP_KICK), EC_WORD_SPIRALING, EC_WORD_INSIDE},
        .monSet = gBattleFrontierTrainerMons_Leon
    },
    [FRONTIER_TRAINER_ALONZO] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("ALONSO"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_PLAYS, EC_WORD_LOSE, EC_WORD_FOREVER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_GIVES, EC_WORD_SPIRALING, EC_MOVE(FACADE), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THIS, EC_WORD_ABSOLUTELY, EC_WORD_DID, EC_WORD_LEFT, EC_WORD_INCREDIBLE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alonzo
    },
    [FRONTIER_TRAINER_VINCE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("OSVALDO"),
        .speechBefore = {EC_WORD_WIN, EC_WORD_BRAG, EC_WORD_A_LOT, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_A_TINY_BIT, EC_WORD_SPIRALING, EC_WORD_LEVEL, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_JOKING, EC_WORD_ABSOLUTELY, EC_MOVE(OUTRAGE), EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Vince
    },
    [FRONTIER_TRAINER_BRYON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("BRION"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_HAVE, EC_MOVE(ENDURE), EC_WORD_RECOMMEND, EC_WORD_JUST, EC_MOVE2(BARRAGE)},
        .speechWin = {EC_WORD_JUST, EC_MOVE2(BARRAGE), EC_WORD_WITHOUT, EC_WORD_PRESSURE, EC_WORD_OH_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_WORD_A_TINY_BIT, EC_WORD_LIE, EC_WORD_THAT_S, EC_WORD_PRESSURE},
        .monSet = gBattleFrontierTrainerMons_Bryon
    },
    [FRONTIER_TRAINER_AVA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("ABI"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_THE, EC_WORD_FOR_NOW, EC_WORD_FINISH, EC_WORD_VERY, EC_WORD_ANTICIPATION},
        .speechWin = {EC_WORD_WHOM, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_RENTAL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_RENTAL, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Ava
    },
    [FRONTIER_TRAINER_MIRIAM] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("MIRNA"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_FOR_NOW, EC_WORD_RIVAL, EC_WORD_MISS, EC_MOVE(SCARY_FACE)},
        .speechWin = {EC_WORD_GWAHAHAHA, EC_WORD_DESTINY, EC_WORD_GWAHAHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARRGH, EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_WORD_HAS, EC_WORD_AWFULLY, EC_MOVE(SCARY_FACE)},
        .monSet = gBattleFrontierTrainerMons_Miriam
    },
    [FRONTIER_TRAINER_CARRIE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("INIRA"),
        .speechBefore = {EC_WORD_CASE, EC_WORD_WALKS, EC_WORD_MISS, EC_WORD_GUTS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_GUTS, EC_WORD_LIE, EC_WORD_THESE_WERE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_MOVE(SELF_DESTRUCT), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Carrie
    },
    [FRONTIER_TRAINER_GILLIAN2] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("GALENIA"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_BEFORE, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_LIE, EC_WORD_THESE_WERE},
        .speechWin = {EC_WORD_A, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_A_LOT, EC_WORD_SPIRALING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WENT, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_EXCITING, EC_WORD_SCATTER, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gillian2
    },
    [FRONTIER_TRAINER_TYLER] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("TILEN"),
        .speechBefore = {EC_WORD_SNORT, EC_WORD_EH_QUES, EC_WORD_OH_YEAH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SNORT, EC_WORD_COME_OVER, EC_WORD_GWAHAHAHA, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SNORT, EC_WORD_LISTENING, EC_WORD_YO, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Tyler
    },
    [FRONTIER_TRAINER_CHAZ] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("TEO"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_POWER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NOW, EC_WORD_WAS, EC_WORD_PLUS, EC_WORD_POWER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_WHOM, EC_WORD_POWER, EC_WORD_YOUR, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Chaz
    },
    [FRONTIER_TRAINER_NELSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("MODESTO"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_WORRY, EC_WORD_HOWEVER, EC_WORD_WIN},
        .speechWin = {EC_WORD_THAT_S, EC_MOVE2(PROTECT), EC_WORD_IS, EC_WORD_MATCH_UP, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CONGRATS, EC_WORD_FIGHTS, EC_WORD_MISS, EC_WORD_HUSTLE, EC_WORD_DON_T, EC_WORD_BEING},
        .monSet = gBattleFrontierTrainerMons_Nelson
    },
    [FRONTIER_TRAINER_SHANIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("SENTIA"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_AND, EC_WORD_I, EC_WORD_MOOD, EC_WORD_THERE},
        .speechWin = {EC_WORD_FOR_NOW, EC_WORD_POKEMON, EC_WORD_SATISFIED, EC_WORD_IS, EC_WORD_AROUND, EC_WORD_SPIRALING},
        .speechLose = {EC_WORD_DOES, EC_WORD_CUTENESS, EC_WORD_MISS, EC_WORD_ONLY, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Shania
    },
    [FRONTIER_TRAINER_STELLA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("ESTELA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_LIKELY_TO, EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_DOWN, EC_WORD_BORING, EC_WORD_LIKELY_TO, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_A_LITTLE, EC_WORD_RIPPED, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stella
    },
    [FRONTIER_TRAINER_DORINE] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("DORINA"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_LOWS, EC_WORD_AND, EC_WORD_VERY, EC_WORD_VERY, EC_WORD_APPROVED},
        .speechWin = {EC_WORD_WHERE, EC_WORD_BELONGS_TO, EC_WORD_YOURS, EC_WORD_PLUS, EC_WORD_APPROVED, EC_WORD_HAH},
        .speechLose = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_ONLY, EC_WORD_BELONGS_TO, EC_WORD_THIRSTY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dorine
    },
    [FRONTIER_TRAINER_MADDOX] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("MADONI"),
        .speechBefore = {EC_WORD_I, EC_WORD_HIGH, EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_DRAGON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ONLY, EC_WORD_HIT, EC_WORD_TYPE, EC_WORD_DRAGON, EC_WORD_WAS, EC_WORD_TWIRLING},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_DRAGON, EC_WORD_DID, EC_WORD_PATTERN, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Maddox
    },
    [FRONTIER_TRAINER_DAVIN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DAVINO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_CAN_T, EC_WORD_USING, EC_WORD_A_TINY_BIT, EC_MOVE2(ROAR), EC_WORD_QUES},
        .speechWin = {EC_WORD_HASSLE, EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_YEAH, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARRGH, EC_WORD_ARRGH, EC_WORD_ARRGH, EC_MOVE2(ROAR), EC_WORD_WHERE, EC_WORD_WALKS},
        .monSet = gBattleFrontierTrainerMons_Davin
    },
    [FRONTIER_TRAINER_TREVON] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("TREVINO"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_HIT, EC_WORD_TYPE, EC_WORD_DRAGON},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_DRAGON, EC_WORD_IS, EC_WORD_FIERY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_DRAGON, EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_MOVE2(CONFUSION)},
        .monSet = gBattleFrontierTrainerMons_Trevon
    },
    [FRONTIER_TRAINER_MATEO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("MAT"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_PROBABLY, EC_MOVE(TICKLE), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_ONLY, EC_WORD_LEADERS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_ANIME, EC_WORD_HOWEVER, EC_WORD_THAT_S, EC_WORD_TOMORROW, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Mateo
    },
    [FRONTIER_TRAINER_BRET] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("BASTIN"),
        .speechBefore = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_ROCK, EC_WORD_IS, EC_WORD_A_TINY_BIT, EC_WORD_SPIRALING},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_TOUGH, EC_WORD_IS, EC_WORD_THAT_S, EC_WORD_WHY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LOSS, EC_WORD_IS, EC_WORD_VERY, EC_WORD_TOUGHNESS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bret
    },
    [FRONTIER_TRAINER_RAUL] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("RALE"),
        .speechBefore = {EC_WORD_FOR_NOW, EC_WORD_RIVAL, EC_WORD_FUNNY, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_DONE},
        .speechWin = {EC_WORD_LET_S, EC_WORD_FOR_NOW, EC_WORD_RIVAL, EC_WORD_A_LITTLE, EC_WORD_PATTERN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_NATURALLY, EC_WORD_PERSON, EC_WORD_PATTERN, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Raul
    },
    [FRONTIER_TRAINER_KAY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("BUSA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_WHOM, EC_WORD_NITWIT, EC_WORD_FIGHTS, EC_WORD_NOW, EC_WORD_QUES},
        .speechWin = {EC_WORD_WON, EC_WORD_BUT, EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_IMPORTANT, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HOWEVER, EC_WORD_END, EC_WORD_SIGH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kay
    },
    [FRONTIER_TRAINER_ELENA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ELENA"),
        .speechBefore = {EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_WORD_NATURALLY, EC_WORD_DESTROYED, EC_WORD_WEIRD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_STRONG, EC_WORD_WEIRD, EC_WORD_AND, EC_WORD_POWER, EC_WORD_ISN_T_IT_QUES, EC_WORD_I},
        .speechLose = {EC_WORD_WHOM, EC_WORD_WEIRD, EC_WORD_BUT, EC_WORD_ME, EC_WORD_STRONG, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Elena
    },
    [FRONTIER_TRAINER_ALANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ALINA"),
        .speechBefore = {EC_WORD_I, EC_WORD_ATTACK, EC_WORD_LIE, EC_WORD_WHY, EC_WORD_INVINCIBLE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HAVE, EC_WORD_A_LOT, EC_WORD_NITWIT, EC_WORD_HOBBY, EC_WORD_UP, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LEFT, EC_WORD_ISN_T_IT_QUES, EC_WORD_A_LITTLE, EC_WORD_GETS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alana
    },
    [FRONTIER_TRAINER_ALEXAS] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("ALEXIO"),
        .speechBefore = {EC_WORD_I, EC_WORD_ATTACK, EC_WORD_LIE, EC_WORD_WHY, EC_WORD_DIRECT, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_GIVE_UP, EC_WORD_FOREVER, EC_WORD_ANOTHER, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_PLUS, EC_WORD_LEVEL, EC_WORD_COULDN_T, EC_WORD_PLUS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alexas
    },
    [FRONTIER_TRAINER_WESTON] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("VESTON"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_CAN_T, EC_WORD_MISS, EC_WORD_A_TINY_BIT, EC_WORD_CHALLENGE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_CHALLENGE, EC_WORD_HAH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LET_S, EC_WORD_CASE, EC_WORD_FOR_NOW, EC_WORD_CHALLENGE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Weston
    },
    [FRONTIER_TRAINER_JASPER] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JAREN"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_SURRENDER, EC_WORD_SKILL, EC_WORD_GRAAAH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_MOVE(SPITE), EC_WORD_WHERE, EC_WORD_IS, EC_WORD_ANTICIPATION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOW, EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_SURRENDER, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jasper
    },
    [FRONTIER_TRAINER_NADIA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("NADIA"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_WAS, EC_WORD_LEFT, EC_WORD_SHAKY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HAH, EC_WORD_AIYEEH, EC_WORD_FORGIVE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_IMPORTANT, EC_WORD_LATER, EC_WORD_LIE, EC_WORD_THAT_S, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Nadia
    },
    [FRONTIER_TRAINER_MIRANDA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("MIRELA"),
        .speechBefore = {EC_WORD_YUP, EC_WORD_YUP, EC_WORD_YUP, EC_WORD_EH_QUES, EC_WORD_GWAH, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OH_QUES, EC_WORD_HUH_QUES, EC_WORD_UH_HUH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_EXCUSE, EC_WORD_ISN_T_IT_QUES, EC_WORD_PATTERN, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Miranda
    },
    [FRONTIER_TRAINER_EMMA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("EMMA"),
        .speechBefore = {EC_WORD_DOES, EC_WORD_THINGS, EC_WORD_LIE, EC_WORD_REALLY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_LET_S, EC_WORD_BECOMES, EC_WORD_LIE, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PROBABLY, EC_WORD_THINGS, EC_WORD_WAS, EC_WORD_LIE, EC_WORD_THESE_WERE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emma
    },
    [FRONTIER_TRAINER_ROLANDO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("ROLAN"),
        .speechBefore = {EC_WORD_IF, EC_WORD_ATTACK, EC_WORD_ISN_T_IT_QUES, EC_WORD_QUITE, EC_WORD_BUSY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_COULD, EC_WORD_IF, EC_WORD_ISN_T_IT_QUES, EC_WORD_BUSY, EC_WORD_ENOUGH, EC_WORD_WHERE},
        .speechLose = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_ALWAYS, EC_WORD_ISN_T_IT_QUES, EC_WORD_BUSY},
        .monSet = gBattleFrontierTrainerMons_Rolando
    },
    [FRONTIER_TRAINER_STANLY] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("SILVANO"),
        .speechBefore = {EC_WORD_GET, EC_WORD_A_TINY_BIT, EC_WORD_INCREDIBLE, EC_WORD_FINISH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AWFULLY, EC_WORD_OFFENSIVE, EC_WORD_IS, EC_WORD_A_LITTLE, EC_WORD_PATTERN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_WORD_FINISH, EC_WORD_WENT, EC_WORD_HOPELESS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stanly
    },
    [FRONTIER_TRAINER_DARIO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("FERMINO"),
        .speechBefore = {EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_WORD_JUST, EC_MOVE2(FORESIGHT), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_MOVE2(FORESIGHT), EC_WORD_WALKS, EC_WORD_THE, EC_WORD_CASE, EC_WORD_FINISH},
        .speechLose = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_NATURALLY, EC_WORD_DESTROYED, EC_MOVE(REVERSAL), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dario
    },
    [FRONTIER_TRAINER_KARLEE] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("CARLINA"),
        .speechBefore = {EC_WORD_THE, EC_WORD_BATTLE, EC_WORD_MAKE, EC_WORD_AROUND, EC_WORD_NITWIT, EC_WORD_SINCE},
        .speechWin = {EC_WORD_WILL_BE_HERE, EC_WORD_LEFT, EC_WORD_THE, EC_WORD_WHY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WENT, EC_WORD_FOR_NOW, EC_WORD_FINAL, EC_WORD_RARE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Karlee
    },
    [FRONTIER_TRAINER_JAYLIN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("JAIDI"),
        .speechBefore = {EC_WORD_THE, EC_WORD_BATTLE, EC_WORD_WHOM, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_ANIME},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_PLAYS, EC_WORD_DOWNCAST, EC_WORD_THE, EC_WORD_A_TINY_BIT, EC_WORD_BATTLE},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_MOVE(YAWN), EC_WORD_PLUS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jaylin
    },
    [FRONTIER_TRAINER_INGRID] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("INGRID"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_QUITE, EC_WORD_HAPPILY, EC_WORD_ALT_COLOR, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_WENT, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_CAN_WIN},
        .speechLose = {EC_WORD_CONFUSED, EC_WORD_PLAYS, EC_WORD_LOSE, EC_WORD_EXCUSE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ingrid
    },
    [FRONTIER_TRAINER_DELILAH] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("DELILA"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_IS, EC_WORD_ANTICIPATION, EC_WORD_LOSS, EC_WORD_MISS, EC_MOVE(GRUDGE)},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_WITHOUT, EC_MOVE(GRUDGE), EC_WORD_LOSS, EC_WORD_QUES},
        .speechLose = {EC_WORD_NOW, EC_WORD_WHOM, EC_MOVE(GRUDGE), EC_WORD_I, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Delilah
    },
    [FRONTIER_TRAINER_CARLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("CARI"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_USING, EC_MOVE2(POISON_POWDER), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_JUST, EC_WORD_STRATEGY, EC_WORD_WALKS, EC_WORD_LIE, EC_WORD_HAS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_AS_MUCH_AS, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Carly
    },
    [FRONTIER_TRAINER_LEXIE] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("LEXI"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_POKEMON, EC_WORD_MISS, EC_MOVE(SCARY_FACE), EC_WORD_QUES},
        .speechWin = {EC_MOVE(SCARY_FACE), EC_WORD_WITHOUT, EC_WORD_HAS, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HAVE, EC_WORD_PLUS, EC_MOVE(SCARY_FACE), EC_WORD_NITWIT, EC_WORD_TOO_LATE, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Lexie
    },
    [FRONTIER_TRAINER_MILLER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("MILTON"),
        .speechBefore = {EC_WORD_HELLO, EC_WORD_HELLO, EC_WORD_EH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OH_DEAR, EC_WORD_SEE_YA, EC_WORD_YEAH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CRIES, EC_WORD_KTHX_BYE, EC_WORD_YEAH_YEAH, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Miller
    },
    [FRONTIER_TRAINER_MARV] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("MARCELO"),
        .speechBefore = {EC_WORD_SINCE, EC_WORD_LIKELY_TO, EC_WORD_AWFULLY, EC_MOVE(SWAGGER), EC_WORD_MOVE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHERE, EC_WORD_DIDN_T, EC_WORD_PLUS, EC_MOVE(SWAGGER), EC_WORD_OH_QUES, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOPE, EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_PLUS, EC_MOVE(SWAGGER), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Marv
    },
    [FRONTIER_TRAINER_LAYTON] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("LANTEO"),
        .speechBefore = {EC_WORD_AROUND, EC_WORD_DOES, EC_WORD_DOES, EC_WORD_NITWIT, EC_WORD_WHOM, EC_WORD_COOL},
        .speechWin = {EC_WORD_BEAUTY, EC_WORD_TOUGH, EC_WORD_COOL, EC_WORD_CUTE, EC_WORD_CASE, EC_WORD_WALKS},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_PLUS, EC_WORD_COOL, EC_WORD_NITWIT, EC_WORD_I},
        .monSet = gBattleFrontierTrainerMons_Layton
    },
    [FRONTIER_TRAINER_BROOKS] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("CELIO"),
        .speechBefore = {EC_WORD_WERE, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_GOOD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HAVE, EC_WORD_FOR_NOW, EC_WORD_LEVEL, EC_WORD_VERY, EC_WORD_ANTICIPATION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LEFT, EC_WORD_HAVE, EC_WORD_EXCITING, EC_WORD_LEVEL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Brooks
    },
    [FRONTIER_TRAINER_GREGORY] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("GRAU"),
        .speechBefore = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_INSIDE, EC_WORD_ISN_T_IT_QUES, EC_WORD_VERY, EC_WORD_LOWS},
        .speechWin = {EC_WORD_BE, EC_WORD_LOWS, EC_MOVE2(ASSIST), EC_WORD_LISTEN, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OUTSIDE, EC_WORD_WHERE, EC_WORD_ISN_T_IT_QUES, EC_WORD_EVERY, EC_WORD_LOWS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gregory
    },
    [FRONTIER_TRAINER_REESE] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("CLEN"),
        .speechBefore = {EC_WORD_I, EC_WORD_WHOM, EC_WORD_TOO_LATE, EC_WORD_HABIT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_DIET, EC_WORD_AND, EC_WORD_ONLY, EC_WORD_SPORTS},
        .speechLose = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_ONLY, EC_WORD_BOOK, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Reese
    },
    [FRONTIER_TRAINER_MASON] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("MARIANO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_SATISFIED, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_DISAPPOINTED, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Mason
    },
    [FRONTIER_TRAINER_TOBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("TANIO"),
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_NITWIT, EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_FIGHT, EC_WORD_BEING},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_AWESOME, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THE, EC_WORD_SMART, EC_WORD_LAY, EC_WORD_CAN, EC_WORD_WIN, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Toby
    },
    [FRONTIER_TRAINER_DOROTHY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("DORITA"),
        .speechBefore = {EC_WORD_FIGHTS, EC_WORD_MISS, EC_WORD_POKEMON, EC_WORD_IS, EC_WORD_BREAK, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_WIN, EC_WORD_WENT, EC_WORD_BREAK, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THANK_YOU, EC_WORD_LOSS, EC_WORD_WENT, EC_WORD_BREAK, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dorothy
    },
    [FRONTIER_TRAINER_PIPER] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("PEPITA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_A_LITTLE, EC_WORD_LIE, EC_WORD_SPEED_BOOST, EC_WORD_QUES},
        .speechWin = {EC_WORD_RECOMMEND, EC_WORD_WIN, EC_WORD_LAY, EC_WORD_WHICH, EC_WORD_AN, EC_WORD_GUTS},
        .speechLose = {EC_WORD_I, EC_WORD_WHERE, EC_WORD_A, EC_WORD_PLUS, EC_WORD_SPEED_BOOST, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Piper
    },
    [FRONTIER_TRAINER_FINN] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("AMARO"),
        .speechBefore = {EC_WORD_WHERE, EC_WORD_CAN, EC_WORD_PLUS, EC_WORD_WILL_BE_HERE, EC_WORD_DOWNCAST, EC_WORD_CHOICE},
        .speechWin = {EC_WORD_WHERE, EC_WORD_SINCE, EC_WORD_FIGHTS, EC_WORD_A_LOT, EC_WORD_PLUS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HOWEVER, EC_WORD_END, EC_WORD_CAN, EC_WORD_AN, EC_WORD_FOR_NOW, EC_MOVE2(REST)},
        .monSet = gBattleFrontierTrainerMons_Finn
    },
    [FRONTIER_TRAINER_SAMIR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("SAMEL"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_MOVE2(DIVE), EC_WORD_AND, EC_MOVE2(SURF), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HAVE, EC_WORD_NITWIT, EC_WORD_USING, EC_MOVE2(DIVE), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A_TINY_BIT, EC_MOVE2(DIVE), EC_WORD_WHERE, EC_WORD_WALKS, EC_WORD_HIT, EC_WORD_CASE},
        .monSet = gBattleFrontierTrainerMons_Samir
    },
    [FRONTIER_TRAINER_FIONA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("GRACITA"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_WORD_A_LITTLE, EC_WORD_LIE, EC_WORD_LIMBER, EC_WORD_QUES},
        .speechWin = {EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_FIGHTS, EC_WORD_PLUS, EC_WORD_DARN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AN, EC_WORD_LIMBER, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Fiona
    },
    [FRONTIER_TRAINER_GLORIA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("GERTRU"),
        .speechBefore = {EC_WORD_I, EC_WORD_ATTACK, EC_WORD_MISS, EC_WORD_SUCTION_CUPS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HEHEHE, EC_WORD_GOOD_BYE, EC_WORD_COME_OVER, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_DOES, EC_WORD_IF, EC_WORD_SUCTION_CUPS, EC_WORD_WALKS, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gloria
    },
    [FRONTIER_TRAINER_NICO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("NICO"),
        .speechBefore = {EC_WORD_I_VE_ARRIVED, EC_WORD_MEAN, EC_WORD_NATURALLY, EC_MOVE(SONIC_BOOM), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_NATURALLY, EC_MOVE(SONIC_BOOM), EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR_NOW, EC_WORD_GENIUS},
        .speechLose = {EC_WORD_A, EC_WORD_PLUS, EC_MOVE2(SUPERSONIC), EC_WORD_WILD, EC_WORD_SPEED_BOOST, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Nico
    },
    [FRONTIER_TRAINER_JEREMY] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("ADOLFO"),
        .speechBefore = {EC_WORD_SINCE, EC_WORD_BE, EC_WORD_FOR_NOW, EC_WORD_MASTER, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_CHOICE, EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR_NOW, EC_WORD_MASTER},
        .speechLose = {EC_WORD_WHERE, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_BE, EC_WORD_MASTER, EC_WORD_FOREVER},
        .monSet = gBattleFrontierTrainerMons_Jeremy
    },
    [FRONTIER_TRAINER_CAITLIN] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("NOE"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_IF, EC_WORD_ABSOLUTELY, EC_WORD_BETTER, EC_WORD_CUTENESS, EC_WORD_QUES},
        .speechWin = {EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_PLUS, EC_WORD_NITWIT, EC_WORD_CUTENESS},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_WHOM, EC_WORD_CUTE_CHARM, EC_WORD_RECOMMEND, EC_WORD_REALLY, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Caitlin
    },
    [FRONTIER_TRAINER_REENA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("ROMINA"),
        .speechBefore = {EC_WORD_ALWAYS, EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_SEE, EC_WORD_UP, EC_WORD_UP},
        .speechWin = {EC_WORD_UH_HUH, EC_WORD_UH_HUH, EC_WORD_UH_HUH, EC_WORD_WAY, EC_WORD_WAY, EC_WORD_WAY},
        .speechLose = {EC_WORD_HEH, EC_WORD_GIVE_ME, EC_WORD_ELLIPSIS_EXCL, EC_WORD_EXCUSE_ME, EC_WORD_RICKETY, EC_WORD_WAY},
        .monSet = gBattleFrontierTrainerMons_Reena
    },
    [FRONTIER_TRAINER_AVERY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("AVERO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_POKEMON, EC_WORD_LIE, EC_WORD_TYPE, EC_WORD_BUG, EC_WORD_HAH},
        .speechWin = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_WAS, EC_WORD_TWIRLING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_WAS, EC_WORD_SHAKY, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Avery
    },
    [FRONTIER_TRAINER_LIAM] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("LIAM"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_IT, EC_WORD_FIRE, EC_WORD_AND, EC_WORD_FLYING, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_BUG, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_OH_QUES},
        .speechLose = {EC_WORD_BELONGS_TO, EC_WORD_THINGS, EC_WORD_NITWIT, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_IT},
        .monSet = gBattleFrontierTrainerMons_Liam
    },
    [FRONTIER_TRAINER_THEO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("FELIPO"),
        .speechBefore = {EC_WORD_FISHING, EC_WORD_IS, EC_WORD_AROUND, EC_WORD_PLUS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_WATER, EC_WORD_IS, EC_WORD_JUST, EC_WORD_TYPE},
        .speechLose = {EC_WORD_SOON, EC_WORD_OR, EC_WORD_LISTEN, EC_WORD_GIVES, EC_WORD_FOR_NOW, EC_WORD_CHANGE},
        .monSet = gBattleFrontierTrainerMons_Theo
    },
    [FRONTIER_TRAINER_BAILEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("BENITO"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR_NOW, EC_WORD_ADULT, EC_WORD_NITWIT, EC_WORD_GUARD, EC_WORD_A_LOT},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR_NOW, EC_WORD_ADULT, EC_WORD_NITWIT, EC_WORD_WINS, EC_WORD_ALWAYS},
        .speechLose = {EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR_NOW, EC_WORD_ADULT, EC_WORD_MISS, EC_MOVE2(FRUSTRATION), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bailey
    },
    [FRONTIER_TRAINER_HUGO] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("HUGUE"),
        .speechBefore = {EC_WORD_I, EC_WORD_ABSOLUTELY, EC_MOVE(ENDEAVOR), EC_WORD_ALWAYS, EC_WORD_A_LOT, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IF, EC_WORD_ABSOLUTELY, EC_MOVE(ENDEAVOR), EC_WORD_ALWAYS, EC_WORD_CAN, EC_WORD_WIN},
        .speechLose = {EC_WORD_WHERE, EC_WORD_WENT, EC_WORD_EXCITING, EC_MOVE(ENDEAVOR), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hugo
    },
    [FRONTIER_TRAINER_BRYCE] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("SUSO"),
        .speechBefore = {EC_WORD_I, EC_WORD_WILL_BE_HERE, EC_WORD_A_LOT, EC_WORD_LIE, EC_WORD_VACATION, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NOW, EC_WORD_SINCE, EC_WORD_PLUS, EC_WORD_VACATION, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_SINCE, EC_MOVE2(REST), EC_WORD_AND, EC_MOVE2(SLACK_OFF)},
        .monSet = gBattleFrontierTrainerMons_Bryce
    },
    [FRONTIER_TRAINER_GIDEON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("GIL"),
        .speechBefore = {EC_WORD_WHAT_S_UP_QUES, EC_WORD_OH_QUES, EC_WORD_QUES_EXCL, EC_WORD_GIVE, EC_WORD_HAS, EC_WORD_QUES},
        .speechWin = {EC_WORD_WHOM, EC_WORD_COOL, EC_WORD_BUT, EC_WORD_WHERE, EC_WORD_GIVE, EC_WORD_HAS},
        .speechLose = {EC_WORD_MYSELF, EC_WORD_ABSOLUTELY, EC_WORD_GIVE, EC_WORD_HAS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gideon
    },
    [FRONTIER_TRAINER_TRISTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("TRISO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_COLLECTION, EC_WORD_LIE, EC_WORD_POKEMON, EC_WORD_HAPPENING, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AIYEEH, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_LOT, EC_WORD_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MMM, EC_WORD_ALWAYS, EC_WORD_FAINTED, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Triston
    },
    [FRONTIER_TRAINER_CHARLES] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("CHARLI"),
        .speechBefore = {EC_WORD_TOO, EC_WORD_JUST, EC_WORD_INVINCIBLE, EC_WORD_STRATEGY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_MOVE(SUBMISSION), EC_WORD_IS, EC_WORD_AWFULLY, EC_WORD_LESS, EC_WORD_OFFENSIVE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_EXCL_EXCL, EC_WORD_PLAYS, EC_WORD_LOSE, EC_WORD_NEW, EC_WORD_MEET_YOU, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Charles
    },
    [FRONTIER_TRAINER_RAYMOND] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("RAIMON"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_LIKE, EC_WORD_JUST, EC_WORD_SONG, EC_WORD_QUES},
        .speechWin = {EC_WORD_WILL_BE_HERE, EC_WORD_SHALLOW, EC_WORD_LIKES, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LEFT, EC_WORD_WHERE, EC_WORD_WILL_BE_HERE, EC_WORD_LIKES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Raymond
    },
    [FRONTIER_TRAINER_DIRK] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("GASPAR"),
        .speechBefore = {EC_WORD_ONLY, EC_WORD_LIE, EC_WORD_TYPE, EC_WORD_FLYING, EC_WORD_WAS, EC_WORD_TWIRLING},
        .speechWin = {EC_WORD_EXCL_EXCL, EC_WORD_POKEMON, EC_WORD_FLYING, EC_WORD_FEELING, EC_WORD_POWER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_LIKE, EC_WORD_A_TINY_BIT, EC_WORD_TYPE, EC_WORD_FLYING},
        .monSet = gBattleFrontierTrainerMons_Dirk
    },
    [FRONTIER_TRAINER_HAROLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("HORACIO"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_HAVE, EC_MOVE2(ATTRACT), EC_WORD_HOWEVER, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_IT, EC_WORD_TOO_LATE, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_WHERE, EC_WORD_LAY, EC_WORD_IT, EC_WORD_THESE, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Harold
    },
    [FRONTIER_TRAINER_OMAR] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("OMAR"),
        .speechBefore = {EC_WORD_IF, EC_WORD_CAN, EC_WORD_WIN, EC_WORD_LAY, EC_WORD_GIVE, EC_WORD_A_LITTLE},
        .speechWin = {EC_WORD_LAY, EC_WORD_GIVE, EC_WORD_SWEETS, EC_WORD_AND, EC_MOVE2(TOXIC), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_LAY, EC_WORD_SINCE, EC_WORD_GIVES, EC_WORD_THINGS},
        .monSet = gBattleFrontierTrainerMons_Omar
    },
    [FRONTIER_TRAINER_PETER] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("IGNACIO"),
        .speechBefore = {EC_WORD_NAME, EC_WORD_RIGHT, EC_WORD_IS, EC_WORD_MATCH_UP, EC_WORD_AND, EC_WORD_ANTICIPATION},
        .speechWin = {EC_WORD_NAME, EC_WORD_IS, EC_WORD_BREAK, EC_WORD_AND, EC_WORD_BEING, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WIN, EC_WORD_WHERE, EC_WORD_BRAG, EC_WORD_EXCITING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Peter
    },
    [FRONTIER_TRAINER_DEV] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("EVELIO"),
        .speechBefore = {EC_WORD_I_VE_ARRIVED, EC_WORD_YES, EC_WORD_EH_QUES, EC_WORD_OH_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NOW, EC_WORD_A, EC_WORD_NATURALLY, EC_WORD_HAPPILY, EC_WORD_NAP, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OK_QUES, EC_WORD_NITWIT, EC_WORD_A, EC_WORD_NATURALLY, EC_WORD_HAPPILY, EC_WORD_NAP},
        .monSet = gBattleFrontierTrainerMons_Dev
    },
    [FRONTIER_TRAINER_COREY] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("CEFE"),
        .speechBefore = {EC_WORD_QUES_EXCL, EC_WORD_LAY, EC_WORD_TEACH, EC_WORD_JUST, EC_WORD_WHY, EC_WORD_QUES},
        .speechWin = {EC_MOVE(BRICK_BREAK), EC_WORD_IS, EC_WORD_AROUND, EC_WORD_PLUS, EC_MOVE2(POUND), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_JUST, EC_MOVE2(FRUSTRATION), EC_WORD_WEREN_T, EC_WORD_CAUSE, EC_WORD_FOR_NOW, EC_MOVE2(ERUPTION)},
        .monSet = gBattleFrontierTrainerMons_Corey
    },
    [FRONTIER_TRAINER_ANDRE] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("ANDI"),
        .speechBefore = {EC_WORD_FLAME_BODY, EC_WORD_WEREN_T, EC_WORD_BE, EC_WORD_SHALLOW, EC_MOVE2(POUND), EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A_TINY_BIT, EC_WORD_FIRE, EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_WORD_A_LOT, EC_WORD_POWER},
        .speechLose = {EC_WORD_QUES_EXCL, EC_WORD_DIDN_T, EC_WORD_CAUSE, EC_WORD_NATURALLY, EC_MOVE2(EXPLOSION), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Andre
    },
    [FRONTIER_TRAINER_FERRIS] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("FLOREN"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_A_TINY_BIT, EC_WORD_NO_1, EC_WORD_ALT_COLOR, EC_WORD_POKEMON, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LEFT, EC_WORD_ISN_T_IT_QUES, EC_WORD_A_TINY_BIT, EC_WORD_NO_1, EC_WORD_UP, EC_WORD_UP},
        .speechLose = {EC_WORD_CHOICE, EC_WORD_WHERE, EC_WORD_ISN_T_IT_QUES, EC_WORD_A_TINY_BIT, EC_WORD_NO_1, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ferris
    },
    [FRONTIER_TRAINER_ALIVIA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("LIRIA"),
        .speechBefore = {EC_WORD_ABSOLUTELY, EC_WORD_TIMES, EC_WORD_VERY, EC_WORD_SEE, EC_WORD_HAH, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WIN, EC_WORD_ABSOLUTELY, EC_WORD_WITHOUT, EC_WORD_SATISFIED, EC_WORD_HAH, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LOSS, EC_WORD_WHERE, EC_WORD_ABSOLUTELY, EC_WORD_SEE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alivia
    },
    [FRONTIER_TRAINER_PAIGE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("LULI"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_THOSE_ARE, EC_WORD_LIE, EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_BADLY},
        .speechWin = {EC_WORD_ANTICIPATION, EC_WORD_THANK_YOU, EC_WORD_HOWEVER, EC_WORD_A_TINY_BIT, EC_WORD_BATTLE, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ANTICIPATION, EC_WORD_VERY, EC_WORD_BADLY, EC_WORD_WHERE, EC_WORD_WENT, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Paige
    },
    [FRONTIER_TRAINER_ANYA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("ANIA"),
        .speechBefore = {EC_WORD_THAT_S, EC_WORD_FASHION, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_BEAUTY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_FASHION, EC_WORD_WHERE, EC_WORD_IS, EC_WORD_ALWAYS, EC_MOVE2(ROLE_PLAY)},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_BEAUTY, EC_WORD_WHERE, EC_WORD_ALWAYS, EC_MOVE2(ASSIST), EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anya
    },
    [FRONTIER_TRAINER_DAWN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("ARRATE"),
        .speechBefore = {EC_WORD_I, EC_WORD_ISN_T_IT_QUES, EC_WORD_MUCH, EC_WORD_MISS, EC_WORD_ONLY, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_ALWAYS, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_ENJOY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WHERE, EC_WORD_BELONGS_TO, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_SHOULD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dawn
    },
    [FRONTIER_TRAINER_ABBY] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("MARGA"),
        .speechBefore = {EC_WORD_FOR_NOW, EC_WORD_BATTLE, EC_WORD_PRAISE, EC_WORD_NITWIT, EC_WORD_BE, EC_WORD_BREAK},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_VICTORY, EC_WORD_PRAISE, EC_WORD_FOR_NOW, EC_MOVE(SWEET_SCENT), EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BELONGS_TO, EC_WORD_FOR_NOW, EC_WORD_STENCH, EC_WORD_PLUS, EC_WORD_NITWIT, EC_WORD_HOPELESS},
        .monSet = gBattleFrontierTrainerMons_Abby
    },
    [FRONTIER_TRAINER_GRETEL] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("BEGO"),
        .speechBefore = {EC_WORD_FEELING, EC_WORD_FORGETS, EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_ABSOLUTELY, EC_MOVE(OUTRAGE)},
        .speechWin = {EC_WORD_JUST, EC_MOVE(OUTRAGE), EC_WORD_IS, EC_WORD_AWAY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LAY, EC_WORD_SINCE, EC_WORD_GIVES, EC_WORD_THAT_S, EC_WORD_CONGRATS, EC_WORD_SIGH},
        .monSet = gBattleFrontierTrainerMons_Gretel
    }
};

