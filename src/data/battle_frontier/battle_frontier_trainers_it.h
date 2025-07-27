const struct BattleFrontierTrainer gBattleFrontierTrainers[FRONTIER_TRAINERS_COUNT] =
{
    [FRONTIER_TRAINER_BRADY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("BRADY"),
        .speechBefore = {EC_WORD_THAT_WAS, EC_WORD_MEAN, EC_WORD_IF_I_LOSE, EC_WORD_HIT, EC_WORD_ABSENT, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AGREE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WERE, EC_WORD_QUES_EXCL, EC_WORD_NEARLY, EC_WORD_AS_IF, EC_WORD_FAST, EC_WORD_PLUS},
        .monSet = gBattleFrontierTrainerMons_Brady
    },
    [FRONTIER_TRAINER_CONNER] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("ATTILIO"),
        .speechBefore = {EC_WORD_IF_I_LOSE, EC_WORD_AS_IF, EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MODE, EC_WORD_END, EC_WORD_IF_I_LOSE, EC_WORD_SORRY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Conner
    },
    [FRONTIER_TRAINER_BRADLEY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("BRADLEY"),
        .speechBefore = {EC_WORD_NOW, EC_WORD_SAID, EC_WORD_VERSUS, EC_WORD_LISTEN, EC_WORD_DO, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_ISN_T_IT_QUES, EC_WORD_ELLIPSIS, EC_WORD_WELCOME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_TOMORROW, EC_WORD_SAID, EC_WORD_ABOVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bradley
    },
    [FRONTIER_TRAINER_CYBIL] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("ANGELA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_GIVES, EC_WORD_FEAR, EC_WORD_HOW, EC_WORD_BETTER, EC_WORD_GRANDMOTHER},
        .speechWin = {EC_WORD_BETTER, EC_WORD_GRANDMOTHER, EC_WORD_IS, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_ALSO, EC_WORD_BETTER, EC_WORD_GRANDMOTHER, EC_WORD_IS, EC_WORD_VERY, EC_WORD_STRONG},
        .monSet = gBattleFrontierTrainerMons_Cybil
    },
    [FRONTIER_TRAINER_RODETTE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("LUNA"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_TO, EC_WORD_FEAR, EC_WORD_MISS, EC_MOVE(YAWN), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS, EC_WORD_WASN_T, EC_MOVE(YAWN), EC_WORD_PROBABLY, EC_WORD_VICTORY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WASN_T, EC_MOVE(YAWN), EC_WORD_WHOM, EC_WORD_HAVE, EC_WORD_SAYS, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Rodette
    },
    [FRONTIER_TRAINER_PEGGY] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("PEGGY"),
        .speechBefore = {EC_WORD_THAT_WAS, EC_WORD_MEAN, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HERE, EC_WORD_VERY, EC_WORD_SIMPLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THANKS, EC_WORD_MEAN, EC_WORD_DO, EC_WORD_ARE, EC_WORD_SAD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Peggy
    },
    [FRONTIER_TRAINER_KEITH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("HARRY"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_LIFE, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_ONLY, EC_WORD_APPEARS},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_LIFE, EC_WORD_IS, EC_WORD_ALSO, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_LIFE, EC_WORD_IS, EC_WORD_ALSO, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Keith
    },
    [FRONTIER_TRAINER_GRAYSON] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("MANLIO"),
        .speechBefore = {EC_WORD_ON, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_A, EC_WORD_TRENDY, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AGREE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IF_I_WIN, EC_WORD_IS, EC_WORD_A, EC_WORD_TRENDY, EC_WORD_NITWIT, EC_WORD_DO},
        .monSet = gBattleFrontierTrainerMons_Grayson
    },
    [FRONTIER_TRAINER_GLENN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("LORIS"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_PERFECT, EC_WORD_IF_I_WIN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FEVER, EC_WORD_MISS, EC_WORD_VICTORY, EC_WORD_ELLIPSIS, EC_WORD_TIRED, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_A, EC_MOVE2(THIEF), EC_WORD_BEAUTIFUL, EC_WORD_AND, EC_WORD_GOOD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Glenn
    },
    [FRONTIER_TRAINER_LILIANA] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("MAGDA"),
        .speechBefore = {EC_WORD_KNOWS, EC_WORD_GO_AHEAD, EC_WORD_AND, EC_WORD_TRAINS, EC_WORD_WEREN_T, EC_WORD_VICTORY},
        .speechWin = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_FOR, EC_WORD_NOW, EC_WORD_PROBABLY, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_FOR, EC_WORD_NOW, EC_WORD_PROBABLY, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Liliana
    },
    [FRONTIER_TRAINER_ELISE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("MICAELA"),
        .speechBefore = {EC_WORD_WITH, EC_WORD_FATHER, EC_WORD_IS, EC_WORD_TRAINER, EC_WORD_FROM, EC_WORD_ALWAYS},
        .speechWin = {EC_WORD_WITH, EC_WORD_FATHER, EC_WORD_IS, EC_WORD_IT, EC_WORD_WITH, EC_WORD_STORE},
        .speechLose = {EC_WORD_FATHER, EC_WORD_EXCL, EC_WORD_GIVE_UP, EC_WORD_EXCL, EC_WORD_IS_IT_QUES, EC_WORD_LOST},
        .monSet = gBattleFrontierTrainerMons_Elise
    },
    [FRONTIER_TRAINER_ZOEY] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("MELANIA"),
        .speechBefore = {EC_WORD_FIGHTING, EC_WORD_THOSE_ARE, EC_WORD_AGREE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANKS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WAKE_UP, EC_WORD_PERFECT, EC_WORD_THOSE_ARE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Zoey
    },
    [FRONTIER_TRAINER_MANUEL] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("MELINDO"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_LISTEN, EC_WORD_A, EC_WORD_THIS, EC_WORD_LEVEL},
        .speechWin = {EC_WORD_AGREE, EC_WORD_PERFECT, EC_WORD_A, EC_WORD_THIS, EC_WORD_LEVEL, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_MOTHER, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Manuel
    },
    [FRONTIER_TRAINER_RUSS] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("ABACO"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_TO, EC_WORD_GO_EASY, EC_WORD_LOWS, EC_WORD_BORED, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_FOR, EC_WORD_THINK, EC_WORD_PROBABLY, EC_WORD_GO_EASY},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_IT, EC_WORD_WITH, EC_WORD_NAME, EC_WORD_AS_IF, EC_WORD_PREPOSTEROUS},
        .monSet = gBattleFrontierTrainerMons_Russ
    },
    [FRONTIER_TRAINER_DUSTIN] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("DUSTIN"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_NITWIT, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_HUNGRY},
        .speechWin = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_HUNGRY},
        .speechLose = {EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_HUNGRY},
        .monSet = gBattleFrontierTrainerMons_Dustin
    },
    [FRONTIER_TRAINER_TINA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("TIZIANA"),
        .speechBefore = {EC_WORD_IF, EC_WORD_SPIRIT, EC_WORD_WHICH, EC_WORD_GIVE, EC_WORD_A, EC_MOVE2(PRESENT)},
        .speechWin = {EC_WORD_WILL, EC_WORD_LOST, EC_WORD_AND, EC_WORD_WHEN, EC_MOVE2(PRESENT), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_IT, EC_MOVE2(PRESENT), EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_WE_RE},
        .monSet = gBattleFrontierTrainerMons_Tina
    },
    [FRONTIER_TRAINER_GILLIAN1] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("GIANNA"),
        .speechBefore = {EC_WORD_CHANNEL, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_PLUS, EC_WORD_LISTEN, EC_WORD_FASHION},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_LISTEN, EC_WORD_FASHION, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_IS, EC_WORD_TO, EC_WORD_FASHION, EC_WORD_SAD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Gillian
    },
    [FRONTIER_TRAINER_ZOE] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("ZOE"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_FEAR, EC_WORD_NITWIT, EC_WORD_OFF, EC_WORD_FIGHTING},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_LIFE, EC_WORD_IS, EC_WORD_SIMPLE, EC_WORD_NITWIT, EC_WORD_DON_T},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_VERY, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Zoe
    },
    [FRONTIER_TRAINER_CHEN] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("ISIDORO"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_UNDERSTOOD, EC_WORD_NITWIT, EC_WORD_TO, EC_WORD_THIN, EC_WORD_FIGHTING},
        .speechWin = {EC_WORD_AND, EC_WORD_NOW, EC_WORD_AN, EC_WORD_EVERY, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_TOUGHNESS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Chen
    },
    [FRONTIER_TRAINER_AL] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("ALE"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_THOSE_ARE, EC_WORD_ABSOLUTELY, EC_WORD_WILL_BE_HERE, EC_WORD_STRONG},
        .speechWin = {EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_LISTEN, EC_WORD_DO},
        .speechLose = {EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_PLUS, EC_WORD_WEAK, EC_WORD_LISTEN, EC_WORD_DO},
        .monSet = gBattleFrontierTrainerMons_Al
    },
    [FRONTIER_TRAINER_MITCH] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("NUCCIO"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_LADY, EC_WORD_LAY, EC_WORD_WEREN_T, EC_WORD_NATURE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_NATURE, EC_WORD_WHOM, EC_WORD_HAVE, EC_WORD_SAYS, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_NATURE, EC_WORD_WHOM, EC_WORD_HAVE, EC_WORD_SAYS, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Mitch
    },
    [FRONTIER_TRAINER_ANNE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("ANNE"),
        .speechBefore = {EC_WORD_OH, EC_WORD_MISS, EC_WORD_HAPPINESS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_HAPPINESS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_AS_IF, EC_WORD_PLAYED, EC_WORD_WEREN_T, EC_WORD_HAPPINESS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Anne
    },
    [FRONTIER_TRAINER_ALIZE] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("ALIZE"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_SHREDDED, EC_WORD_FEELING, EC_WORD_ENTERTAINING, EC_WORD_QUES},
        .speechWin = {EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_SHREDDED, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_ENTERTAINING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Alize
    },
    [FRONTIER_TRAINER_LAUREN] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("SVEVA"),
        .speechBefore = {EC_WORD_CHOOSE, EC_WORD_PRETEND, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_AGE, EC_WORD_QUES},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_CURRENT, EC_WORD_FOR, EC_WORD_AGE, EC_WORD_NITWIT, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_LOWS, EC_WORD_PLUS, EC_WORD_FOR, EC_WORD_AGE},
        .monSet = gBattleFrontierTrainerMons_Lauren
    },
    [FRONTIER_TRAINER_KIPP] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("PLACIDO"),
        .speechBefore = {EC_WORD_IF, EC_WORD_WIN, EC_WORD_KNOWS, EC_WORD_MEAN, EC_WORD_MAKE, EC_MOVE2(SURF)},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_AND, EC_WORD_NOW, EC_WORD_GIVE, EC_MOVE2(SURF)},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_AND, EC_WORD_WHEN, EC_MOVE2(SURF), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kipp
    },
    [FRONTIER_TRAINER_JASON] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("CHRIS"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_WORKS, EC_WORD_TO, EC_WORD_HAS, EC_WORD_STRATEGY, EC_WORD_QUES},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_WORKS, EC_WORD_TO, EC_WORD_HAS, EC_WORD_STRATEGY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LOWS, EC_WORD_HAS, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_STRATEGY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jason
    },
    [FRONTIER_TRAINER_JOHN] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("JOHN"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_TRAINER, EC_WORD_FROM, EC_WORD_VERY, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_BUT, EC_WORD_ARE, EC_WORD_AWFULLY, EC_WORD_WHERE, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_MORE, EC_WORD_WHERE, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_John
    },
    [FRONTIER_TRAINER_ANN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ANNY"),
        .speechBefore = {EC_WORD_ON, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_A, EC_WORD_DREAM, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS, EC_WORD_HERE, EC_WORD_EXCITING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IS, EC_WORD_HERE, EC_WORD_VERY, EC_WORD_VERY, EC_WORD_SAD, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Ann
    },
    [FRONTIER_TRAINER_EILEEN] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("TATIANA"),
        .speechBefore = {EC_WORD_POKEMON, EC_WORD_IS, EC_WORD_A, EC_WORD_TRENDY, EC_WORD_ADULT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_A, EC_WORD_ADULT, EC_WORD_WORKING, EC_WORD_HOW, EC_WORD_IF_I_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_A, EC_WORD_ADULT, EC_WORD_SHOW, EC_WORD_PRETEND, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Eileen
    },
    [FRONTIER_TRAINER_CARLIE] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("COLOMBA"),
        .speechBefore = {EC_WORD_TODAY, EC_WORD_IS, EC_WORD_SUMMER, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LIE, EC_WORD_WIN, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_SUMMER, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LIE, EC_WORD_LOSE, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_SUMMER, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Carlie
    },
    [FRONTIER_TRAINER_GORDON] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("SERGIO"),
        .speechBefore = {EC_WORD_KNOWS, EC_WORD_CRY, EC_WORD_TO, EC_WORD_THIN, EC_WORD_VICTORY, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_HERE_GOES, EC_WORD_WEREN_T, EC_WORD_THIN, EC_WORD_VICTORY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WELL_THEN, EC_WORD_ELLIPSIS, EC_WORD_OFF, EC_WORD_THIN, EC_WORD_VICTORY, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Gordon
    },
    [FRONTIER_TRAINER_AYDEN] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("SILVANO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_TO, EC_WORD_SILKY, EC_WORD_FIGHTING},
        .speechWin = {EC_WORD_PERFECT, EC_WORD_TO, EC_WORD_SILKY, EC_WORD_FIGHTING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_THIS, EC_WORD_MISS, EC_WORD_SILKY, EC_WORD_FIGHTING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ayden
    },
    [FRONTIER_TRAINER_MARCO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("MORENO"),
        .speechBefore = {EC_WORD_GIVE, EC_MOVE2(SURF), EC_WORD_ALSO, EC_WORD_TOO_LATE, EC_WORD_WINTER, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_MAKE, EC_MOVE2(SURF), EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MAKE, EC_MOVE2(SURF), EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_LOSE, EC_WORD_QUES_EXCL},
        .monSet = gBattleFrontierTrainerMons_Marco
    },
    [FRONTIER_TRAINER_CIERRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("ROMILDE"),
        .speechBefore = {EC_WORD_TOO_LATE, EC_WORD_WATER, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_IT, EC_WORD_SYNCHRONIZE},
        .speechWin = {EC_WORD_NITWIT, EC_WORD_IF_I_WIN, EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_SYNCHRONIZE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NOW, EC_WORD_WHOM, EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_PLUS, EC_WORD_SYNCHRONIZE},
        .monSet = gBattleFrontierTrainerMons_Cierra
    },
    [FRONTIER_TRAINER_MARCY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("FLORA"),
        .speechBefore = {EC_WORD_OVERDO, EC_WORD_IF_I_WIN, EC_WORD_IF, EC_WORD_CHOOSE, EC_WORD_ALLOW, EC_WORD_FAR},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_WIN, EC_WORD_AND, EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_UNDERSTOOD},
        .speechLose = {EC_WORD_ALSO, EC_WORD_IF_I_LOSE, EC_WORD_HAVE, EC_WORD_IT, EC_WORD_NOT, EC_MOVE(CHARM)},
        .monSet = gBattleFrontierTrainerMons_Marcy
    },
    [FRONTIER_TRAINER_KATHY] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("KATHY"),
        .speechBefore = {EC_WORD_TODAY, EC_WORD_IS_IT_QUES, EC_WORD_ALWAYS, EC_WORD_WON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_MORE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OFF, EC_WORD_TIME, EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kathy
    },
    [FRONTIER_TRAINER_PEYTON] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("ADDO"),
        .speechBefore = {EC_WORD_MUST_BE, EC_WORD_TO, EC_WORD_DISAPPOINT, EC_WORD_LAY, EC_WORD_ALL, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_ARE, EC_WORD_HAPPY, EC_WORD_LISTEN, EC_WORD_IF_I_WIN, EC_WORD_LAY, EC_WORD_CAN},
        .speechLose = {EC_WORD_ALSO, EC_WORD_IF, EC_WORD_LOSE, EC_WORD_MAYBE, EC_WORD_DISASTER, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Peyton
    },
    [FRONTIER_TRAINER_JULIAN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("JULIAN"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_ENJOY, EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_BUT, EC_WORD_AS_IF, EC_WORD_MAYBE, EC_WORD_OVERDO, EC_WORD_ADORE, EC_WORD_JUST},
        .speechLose = {EC_WORD_RUN, EC_WORD_MISS, EC_WORD_MAYBE, EC_WORD_ENJOY, EC_WORD_HOW, EC_WORD_DON_T},
        .monSet = gBattleFrontierTrainerMons_Julian
    },
    [FRONTIER_TRAINER_QUINN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("TOMMASO"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_A, EC_WORD_DREAM, EC_WORD_ALTHOUGH, EC_WORD_DISAPPOINTED, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS, EC_WORD_A, EC_WORD_DREAM, EC_WORD_LISTEN, EC_WORD_HAPPINESS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FOR, EC_WORD_IMPORTANT, EC_WORD_IS, EC_WORD_IT, EC_WORD_WITH, EC_WORD_DREAM},
        .monSet = gBattleFrontierTrainerMons_Quinn
    },
    [FRONTIER_TRAINER_HAYLEE] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("GINEVRA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_IF, EC_WORD_ARE, EC_WORD_HAPPY, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_LET_S, EC_WORD_QUES, EC_WORD_LET_S, EC_WORD_WILL_BE_HERE, EC_WORD_HAPPY, EC_WORD_QUES},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_HAPPINESS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Haylee
    },
    [FRONTIER_TRAINER_AMANDA] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("NOEMI"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_FAMILY, EC_WORD_ENJOYS, EC_WORD_HEARING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_TO, EC_WORD_VICTORY, EC_WORD_IMPORTANT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_TRAINS, EC_WORD_ALLOW, EC_WORD_MEAN, EC_WORD_HOME, EC_WORD_NOW, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Amanda
    },
    [FRONTIER_TRAINER_STACY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("GISELLA"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_A, EC_WORD_TO_US},
        .speechWin = {EC_WORD_MISS, EC_WORD_TO_US, EC_WORD_LISTEN, EC_WORD_POKEMON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_MAYBE, EC_WORD_PRAISE, EC_WORD_ADORE, EC_WORD_LISTEN, EC_WORD_MINUS},
        .monSet = gBattleFrontierTrainerMons_Stacy
    },
    [FRONTIER_TRAINER_RAFAEL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("RAFAEL"),
        .speechBefore = {EC_WORD_YAHOO, EC_EMPTY_WORD, EC_WORD_YES, EC_WORD_PERFECT, EC_WORD_DO, EC_WORD_EXCL},
        .speechWin = {EC_WORD_BUT, EC_WORD_WORKS, EC_WORD_MISS, EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_QUES},
        .speechLose = {EC_WORD_BUT, EC_WORD_WORKS, EC_WORD_MISS, EC_WORD_WILL_BE_HERE, EC_WORD_STRONG, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Rafael
    },
    [FRONTIER_TRAINER_OLIVER] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("OLIVER"),
        .speechBefore = {EC_WORD_FOR, EC_WORD_SMARTNESS, EC_WORD_IS, EC_WORD_IMPORTANT, EC_WORD_WORKS, EC_WORD_QUES},
        .speechWin = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_SMARTNESS, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_IT, EC_WORD_EVER, EC_WORD_SMARTNESS, EC_WORD_IS, EC_WORD_EXCELLENT, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Oliver
    },
    [FRONTIER_TRAINER_PAYTON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("ROMANO"),
        .speechBefore = {EC_WORD_ALLOW, EC_WORD_ALWAYS, EC_WORD_GO_AHEAD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ALLOW, EC_WORD_GO_AHEAD, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_VICTORY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_YES, EC_WORD_ELLIPSIS, EC_WORD_BUT, EC_WORD_ALLOW, EC_WORD_EVEN_SO, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Payton
    },
    [FRONTIER_TRAINER_PAMELA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("PAMELA"),
        .speechBefore = {EC_WORD_A, EC_WORD_TRAINER, EC_WORD_SHOW, EC_WORD_CONCEDE, EC_WORD_MEET, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_MEET, EC_WORD_AND, EC_WORD_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BUT, EC_WORD_ON, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_MEET, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Pamela
    },
    [FRONTIER_TRAINER_ELIZA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("ROSALBA"),
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_IS, EC_WORD_HOW, EC_WORD_A, EC_WORD_SON},
        .speechWin = {EC_WORD_THANKS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SORRY, EC_WORD_LISTEN, EC_WORD_MEETS, EC_WORD_LOST, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Eliza
    },
    [FRONTIER_TRAINER_MARISA] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("ROSY"),
        .speechBefore = {EC_WORD_PROMISE, EC_WORD_ELLIPSIS, EC_WORD_AS, EC_WORD_CRUSH, EC_WORD_SUPER, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_LEARN, EC_WORD_MAKE, EC_WORD_VERY, EC_WORD_LISTEN, EC_WORD_PLUS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_MAKE, EC_WORD_VERY, EC_WORD_LISTEN, EC_WORD_PLUS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Marisa
    },
    [FRONTIER_TRAINER_LEWIS] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("ENNIO"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_FEAR, EC_WORD_LISTEN, EC_WORD_WHEN, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WHICH, EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_WORD_LOWS, EC_WORD_FEAR, EC_WORD_QUES},
        .speechLose = {EC_WORD_WHOM, EC_WORD_GIVES, EC_WORD_LOWS, EC_WORD_FEAR, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Lewis
    },
    [FRONTIER_TRAINER_YOSHI] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("YOSHI"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_SECRET},
        .speechWin = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_WHOM, EC_WORD_WALKING, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_BUT, EC_WORD_IS_IT_QUES, EC_WORD_POKEMON, EC_WORD_TOO_STRONG},
        .monSet = gBattleFrontierTrainerMons_Yoshi
    },
    [FRONTIER_TRAINER_DESTIN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("DESTIN"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_MOVE(SAFEGUARD), EC_WORD_PROBABLY, EC_WORD_NATURE},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_ALSO, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_NATURE},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_BUT, EC_WORD_IS_IT_QUES, EC_WORD_POKEMON, EC_WORD_TOO_STRONG},
        .monSet = gBattleFrontierTrainerMons_Destin
    },
    [FRONTIER_TRAINER_KEON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("KEON"),
        .speechBefore = {EC_WORD_SORRY, EC_WORD_BUT, EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_EXPENSIVE, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ARE, EC_WORD_A, EC_WORD_SMALL, EC_WORD_PROBABLY, EC_WORD_NATURE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_MISS, EC_WORD_LOSS, EC_WORD_EXPENSIVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Keon
    },
    [FRONTIER_TRAINER_STUART] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("STUART"),
        .speechBefore = {EC_WORD_LOW, EC_WORD_ELLIPSIS, EC_WORD_IS, EC_WORD_TO, EC_WORD_PROMISE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ARE, EC_WORD_INCREDIBLE, EC_WORD_HEH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WHICH, EC_WORD_IS_IT_QUES, EC_WORD_FAINTED, EC_WORD_HURRIED, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Stuart
    },
    [FRONTIER_TRAINER_NESTOR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("NESTOR"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_MAKING, EC_WORD_TO, EC_WORD_SILKY, EC_WORD_MOVE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_MISS, EC_WORD_MOVE, EC_WORD_IS, EC_WORD_MUST_BE, EC_WORD_OFF, EC_WORD_QUES},
        .speechLose = {EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_MOVE, EC_WORD_PROBABLY, EC_WORD_SINCE, EC_WORD_VICTORY},
        .monSet = gBattleFrontierTrainerMons_Nestor
    },
    [FRONTIER_TRAINER_DERRICK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("DERRICK"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_WORKS, EC_WORD_MAKE, EC_WORD_WEREN_T, EC_MOVE2(MEDITATE), EC_WORD_QUES},
        .speechWin = {EC_WORD_WEREN_T, EC_MOVE2(MEDITATE), EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WEREN_T, EC_MOVE2(MEDITATE), EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_WIN},
        .monSet = gBattleFrontierTrainerMons_Derrick
    },
    [FRONTIER_TRAINER_BRYSON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("RUFO"),
        .speechBefore = {EC_MOVE2(POISON_POWDER), EC_WORD_ELLIPSIS, EC_MOVE2(COTTON_SPORE), EC_WORD_ELLIPSIS, EC_WORD_ARE, EC_WORD_BREAK},
        .speechWin = {EC_WORD_ALSO, EC_WORD_MEAN, EC_WORD_DO, EC_WORD_LIKES, EC_MOVE2(POISON_POWDER), EC_WORD_QUES},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_INVINCIBLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bryson
    },
    [FRONTIER_TRAINER_CLAYTON] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("CLAYTON"),
        .speechBefore = {EC_WORD_BUT, EC_WORD_ELLIPSIS, EC_WORD_EVEN_SO, EC_WORD_ELLIPSIS, EC_WORD_IS, EC_WORD_QUES_EXCL},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_IT, EC_WORD_WITH, EC_WORD_POKENAV, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_POKENAV, EC_WORD_AND, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Clayton
    },
    [FRONTIER_TRAINER_TRENTON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("RUPERTO"),
        .speechBefore = {EC_WORD_CHOOSE, EC_WORD_A_LITTLE, EC_WORD_LISTEN, EC_WORD_WATER, EC_WORD_HAS, EC_WORD_QUES},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_OVER, EC_WORD_CHOOSE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_FOR, EC_WORD_WATER, EC_WORD_PLAYED, EC_WORD_VERY, EC_WORD_THOSE_ARE, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Trenton
    },
    [FRONTIER_TRAINER_JENSON] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("JENSON"),
        .speechBefore = {EC_WORD_HERE_IT_IS, EC_WORD_TO, EC_WORD_THIN, EC_WORD_HOO_HAH, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_UNDERSTAND, EC_WORD_OFF, EC_WORD_HOO_HAH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AN, EC_WORD_HOO_HAH, EC_WORD_SAD, EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jenson
    },
    [FRONTIER_TRAINER_WESLEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("WESLEY"),
        .speechBefore = {EC_WORD_OR, EC_WORD_HOW, EC_MOVE(SWIFT), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HOW, EC_MOVE(SWIFT), EC_WORD_CRY, EC_WORD_WEREN_T, EC_WORD_VICTORY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HOW, EC_MOVE(SWIFT), EC_WORD_CRY, EC_WORD_WEREN_T, EC_WORD_LOSS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Wesley
    },
    [FRONTIER_TRAINER_ANTON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("ANTON"),
        .speechBefore = {EC_WORD_HIGHS, EC_WORD_ELLIPSIS, EC_WORD_IF, EC_WORD_WIN, EC_WORD_GIVE, EC_WORD_PARTY},
        .speechWin = {EC_WORD_NOW, EC_WORD_ELLIPSIS, EC_WORD_PARTY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_PLAYS, EC_WORD_PARTY, EC_WORD_AN, EC_WORD_EVERY, EC_WORD_TIME, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Anton
    },
    [FRONTIER_TRAINER_LAWSON] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("LAWSON"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_MORE, EC_WORD_STRONG, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_MODE, EC_WORD_BETTER, EC_WORD_AGE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_PLUS, EC_WORD_FOR, EC_WORD_AGE},
        .monSet = gBattleFrontierTrainerMons_Lawson
    },
    [FRONTIER_TRAINER_SAMMY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("SAMMY"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_GO_EASY, EC_WORD_IS, EC_WORD_SUPER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_GO_EASY, EC_WORD_IS, EC_WORD_PERFECT, EC_WORD_INCREDIBLE},
        .speechLose = {EC_WORD_SORRY, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_GO_EASY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Sammy
    },
    [FRONTIER_TRAINER_ARNIE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("TINO"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_TO, EC_WORD_ROCK, EC_WORD_ELLIPSIS, EC_WORD_IT, EC_WORD_NO_1},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_PLEASE, EC_WORD_PERFECT, EC_WORD_IF_I_LOSE, EC_WORD_MUST_BE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_ARE, EC_WORD_MINUS, EC_WORD_ROCK_SOLID, EC_WORD_LISTEN, EC_WORD_TO, EC_WORD_ROCK},
        .monSet = gBattleFrontierTrainerMons_Arnie
    },
    [FRONTIER_TRAINER_ADRIAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("ADRIAN"),
        .speechBefore = {EC_MOVE(ENCORE), EC_WORD_LAY, EC_WORD_DON_T, EC_WORD_ELLIPSIS, EC_WORD_POKEMON, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_POKEMON, EC_WORD_POKEMON, EC_WORD_POKEMON, EC_WORD_ELLIPSIS, EC_WORD_VICTORY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_POKEMON, EC_WORD_POKEMON, EC_WORD_POKEMON, EC_WORD_ELLIPSIS, EC_WORD_LOSS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Adrian
    },
    [FRONTIER_TRAINER_TRISTAN] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("RANIERI"),
        .speechBefore = {EC_WORD_HAPPINESS, EC_WORD_IS, EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_LISTEN, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_HAPPINESS, EC_WORD_IS, EC_WORD_IF_I_WIN, EC_WORD_LAY, EC_WORD_ALL, EC_WORD_POKEMON},
        .speechLose = {EC_WORD_HAPPINESS, EC_WORD_CHANGE, EC_WORD_CONCEDE, EC_WORD_ALSO, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Tristan
    },
    [FRONTIER_TRAINER_JULIANA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("JULIANA"),
        .speechBefore = {EC_WORD_GIVE, EC_WORD_JUST, EC_WORD_SHOPPING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TRAINS, EC_WORD_A, EC_WORD_PLUSH_DOLL, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_TRAINS, EC_WORD_A, EC_WORD_PLUSH_DOLL, EC_WORD_ANY, EC_WORD_DAY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Juliana
    },
    [FRONTIER_TRAINER_RYLEE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("ROSETTA"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_MAKING, EC_WORD_IF, EC_WORD_LOWS, EC_WORD_BIG, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WELL_THEN, EC_WORD_NATURALLY, EC_WORD_BIG, EC_WORD_MEAN, EC_WORD_DIET, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BIG, EC_WORD_THIN, EC_WORD_THIN, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rylee
    },
    [FRONTIER_TRAINER_CHELSEA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("CHELSEA"),
        .speechBefore = {EC_WORD_FORGETS, EC_WORD_IS, EC_WORD_LISTENS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AND, EC_WORD_TRAINS, EC_WORD_IF_I_WIN, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BUT, EC_WORD_ISN_T_IT_QUES, EC_WORD_AS_IF, EC_WORD_TRAINS, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Chelsea
    },
    [FRONTIER_TRAINER_DANELA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("VANDA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_SURRENDER, EC_WORD_MUST_BE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ARE, EC_WORD_TO, EC_MOVE(STRENGTH), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SURRENDER, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Danela
    },
    [FRONTIER_TRAINER_LIZBETH] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("LISELLA"),
        .speechBefore = {EC_WORD_CHOOSE, EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT, EC_MOVE2(PRESENT), EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_LOSS},
        .speechLose = {EC_WORD_WHOM, EC_WORD_WILL, EC_WORD_SAYS, EC_WORD_LET_S, EC_WORD_A, EC_MOVE2(PRESENT)},
        .monSet = gBattleFrontierTrainerMons_Lizbeth
    },
    [FRONTIER_TRAINER_AMELIA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("AMELIA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_WEREN_T, EC_WORD_FASHION, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LET_S, EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_PERFECT, EC_WORD_MODE, EC_WORD_FASHION},
        .speechLose = {EC_WORD_KNOWS, EC_WORD_MEAN, EC_WORD_HOME, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Amelia
    },
    [FRONTIER_TRAINER_JILLIAN] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("JADE"),
        .speechBefore = {EC_WORD_BUT, EC_WORD_THING, EC_WORD_IS, EC_WORD_ON, EC_MOVE(SWEET_SCENT), EC_WORD_QUES},
        .speechWin = {EC_WORD_IS, EC_WORD_IT, EC_MOVE(SWEET_SCENT), EC_WORD_PROBABLY, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IS, EC_WORD_IT, EC_WORD_STENCH, EC_WORD_PROBABLY, EC_WORD_LOSS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Jillian
    },
    [FRONTIER_TRAINER_ABBIE] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("LICIA"),
        .speechBefore = {EC_WORD_WIN, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_MOVE(STRENGTH), EC_WORD_MOOD, EC_MOVE(AROMATHERAPY)},
        .speechWin = {EC_WORD_FOR, EC_MOVE(AROMATHERAPY), EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_WIN, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_FOR, EC_MOVE(AROMATHERAPY), EC_WORD_AS_IF, EC_WORD_PLAYED, EC_WORD_NITWIT, EC_WORD_DO},
        .monSet = gBattleFrontierTrainerMons_Abbie
    },
    [FRONTIER_TRAINER_BRIANA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("BRIGIDA"),
        .speechBefore = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_BOY, EC_WORD_AWFUL, EC_WORD_HUH_QUES, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_BOY, EC_WORD_IS, EC_WORD_PLUS, EC_WORD_STRONG},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_NOT_VERY, EC_WORD_WITH, EC_WORD_BOY},
        .monSet = gBattleFrontierTrainerMons_Briana
    },
    [FRONTIER_TRAINER_ANTONIO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("ANTONIO"),
        .speechBefore = {EC_WORD_RUN, EC_WORD_DANCE, EC_WORD_THOSE_ARE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_RUN, EC_WORD_DANCE, EC_WORD_BUT, EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_LIKES},
        .speechLose = {EC_WORD_NOW, EC_WORD_LEARN, EC_WORD_DANCE, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_JOY},
        .monSet = gBattleFrontierTrainerMons_Antonio
    },
    [FRONTIER_TRAINER_JADEN] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("FLERIDE"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_A, EC_WORD_BOY, EC_WORD_ROMANTIC, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_PLEASE, EC_WORD_MAKING, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_MOVE2(FRUSTRATION), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BYE_BYE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jaden
    },
    [FRONTIER_TRAINER_DAKOTA] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("DAKOTA"),
        .speechBefore = {EC_WORD_WHICH, EC_WORD_LIKES, EC_WORD_DANCE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_DANCE, EC_WORD_IS, EC_WORD_EXPENSIVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_IF_I_WIN, EC_WORD_BUT, EC_WORD_RUN, EC_WORD_DANCE},
        .monSet = gBattleFrontierTrainerMons_Dakota
    },
    [FRONTIER_TRAINER_BRAYDEN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("ADELFO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_WANT, EC_WORD_ALL, EC_WORD_TOYS},
        .speechWin = {EC_WORD_GAME, EC_WORD_ELLIPSIS, EC_WORD_HEARING, EC_WORD_ELLIPSIS, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_GAME, EC_WORD_ELLIPSIS, EC_WORD_HEARING, EC_WORD_ELLIPSIS, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Brayden
    },
    [FRONTIER_TRAINER_CORSON] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("PRISCO"),
        .speechBefore = {EC_WORD_IS, EC_WORD_SIMPLE, EC_WORD_IF_I_WIN, EC_WORD_VERSUS, EC_WORD_LISTEN, EC_WORD_DO},
        .speechWin = {EC_WORD_SIMPLE, EC_WORD_SIMPLE, EC_WORD_SIMPLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARE, EC_WORD_ALSO, EC_WORD_VERSUS, EC_WORD_WEREN_T, EC_WORD_LOSS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Corson
    },
    [FRONTIER_TRAINER_TREVIN] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("TREVIN"),
        .speechBefore = {EC_WORD_WONDER, EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_LISTEN, EC_WORD_DON_T, EC_WORD_QUES},
        .speechWin = {EC_WORD_LET_S, EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_ABOVE, EC_WORD_LISTEN, EC_WORD_DON_T},
        .speechLose = {EC_WORD_LET_S, EC_WORD_QUES, EC_WORD_NATURALLY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Trevin
    },
    [FRONTIER_TRAINER_PATRICK] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("PATRICK"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_WEREN_T, EC_WORD_PERFECTION, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_PERFECTION, EC_WORD_WINS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_PERFECTION, EC_WORD_AS_IF, EC_WORD_HAVE, EC_WORD_WON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Patrick
    },
    [FRONTIER_TRAINER_KADEN] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("VASCO"),
        .speechBefore = {EC_WORD_GIMME, EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_MOVE(STRENGTH), EC_WORD_QUES},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_MOVE(STRENGTH), EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_SURPRISE},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_SINCE, EC_MOVE(STRENGTH), EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_SURPRISE},
        .monSet = gBattleFrontierTrainerMons_Kaden
    },
    [FRONTIER_TRAINER_MAXWELL] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("MAXWELL"),
        .speechBefore = {EC_WORD_WONDER, EC_WORD_IS, EC_WORD_IT, EC_WORD_EVER, EC_WORD_FOE, EC_WORD_QUES},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_DUDE, EC_WORD_FIGHTING, EC_WORD_LAY, EC_WORD_DON_T},
        .speechLose = {EC_WORD_ARE, EC_WORD_ISN_T_IT_QUES, EC_WORD_IT, EC_WORD_EVER, EC_WORD_FOE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Maxwell
    },
    [FRONTIER_TRAINER_DARYL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("LUIGI"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_SAID, EC_WORD_ONLY, EC_WORD_TOO_LATE, EC_WORD_ATTACK, EC_WORD_EXCL},
        .speechWin = {EC_WORD_A, EC_WORD_ATTACK, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_LOWS, EC_WORD_THIN, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Daryl
    },
    [FRONTIER_TRAINER_KENNETH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("KENNETH"),
        .speechBefore = {EC_WORD_THAT_WAS, EC_WORD_MEAN, EC_WORD_TO, EC_WORD_SILKY, EC_WORD_SURPRISE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WHICH, EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_WORD_FEAR, EC_WORD_HEH, EC_WORD_QUES},
        .speechLose = {EC_WORD_SORRY, EC_WORD_LOWS, EC_WORD_VERY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kenneth
    },
    [FRONTIER_TRAINER_RICH] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("DANILO"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_GIVES, EC_WORD_PERFECT, EC_WORD_FEAR, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_LOWS, EC_WORD_HERE, EC_WORD_OKAY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LOWS, EC_WORD_TO, EC_MOVE(CRABHAMMER), EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Rich
    },
    [FRONTIER_TRAINER_CADEN] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("VELIO"),
        .speechBefore = {EC_WORD_LOWS, EC_WORD_WHOM, EC_WORD_CHOOSE, EC_WORD_MAKE, EC_WORD_IF_I_LOSE, EC_WORD_QUES},
        .speechWin = {EC_WORD_TRUMP_CARD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ANY, EC_WORD_FIRE, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Caden
    },
    [FRONTIER_TRAINER_MARLON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("MARLON"),
        .speechBefore = {EC_WORD_IT, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_TO, EC_WORD_RADIO, EC_WORD_QUES},
        .speechWin = {EC_WORD_HOW, EC_WORD_QUES, EC_WORD_TO, EC_WORD_RADIO, EC_WORD_BEAT, EC_WORD_QUES},
        .speechLose = {EC_WORD_HAH, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_TO, EC_WORD_RADIO, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Marlon
    },
    [FRONTIER_TRAINER_NASH] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("NASH"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_A, EC_WORD_FIRE, EC_WORD_LISTEN, EC_WORD_CARES, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IS, EC_WORD_IT, EC_WORD_FIRE, EC_WORD_PROBABLY, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_FOR, EC_WORD_CARES, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_WHERE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Nash
    },
    [FRONTIER_TRAINER_ROBBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("ROBBY"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_HAPPY, EC_WORD_LISTEN, EC_WORD_HEARING, EC_WORD_LAY, EC_WORD_DO},
        .speechWin = {EC_WORD_ARE, EC_WORD_HAPPY, EC_WORD_LISTEN, EC_WORD_IF_I_WIN, EC_WORD_LAY, EC_WORD_DO},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_MUST_BE, EC_WORD_HAPPY, EC_WORD_LISTEN, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Robby
    },
    [FRONTIER_TRAINER_REECE] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("VALTER"),
        .speechBefore = {EC_WORD_REJECT, EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_YET, EC_WORD_LISTEN, EC_WORD_DO},
        .speechWin = {EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_YET, EC_WORD_HOW, EC_WORD_LEARN, EC_WORD_MAKING},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_JUST, EC_WORD_YET, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Reece
    },
    [FRONTIER_TRAINER_KATHRYN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("ALFREDA"),
        .speechBefore = {EC_WORD_NATURALLY, EC_WORD_PRAISE, EC_WORD_HEARING, EC_WORD_LISTEN, EC_WORD_PLUS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_BUT, EC_WORD_HIT, EC_WORD_IS_IT_QUES, EC_WORD_FAINTED, EC_WORD_IF_I_WIN, EC_WORD_QUES},
        .speechLose = {EC_WORD_HIT, EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_FAINTED, EC_WORD_IF_I_WIN, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Kathryn
    },
    [FRONTIER_TRAINER_ELLEN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("ELLEN"),
        .speechBefore = {EC_WORD_WHICH, EC_MOVE2(SLAM), EC_WORD_HOW, EC_WORD_A, EC_WORD_EGG, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WILL_BE_HERE, EC_WORD_A, EC_WORD_EGG, EC_WORD_FROM, EC_WORD_GOURMET, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_ARE, EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR, EC_WORD_EGG, EC_WORD_FROM, EC_WORD_GOURMET},
        .monSet = gBattleFrontierTrainerMons_Ellen
    },
    [FRONTIER_TRAINER_RAMON] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("RAMON"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_WEREN_T, EC_WORD_PERFECTION, EC_WORD_EXCL, EC_WORD_LOWS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HAPPY, EC_WORD_LISTEN, EC_WORD_MEETS, EC_WORD_WON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_BUT, EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_HAPPY},
        .monSet = gBattleFrontierTrainerMons_Ramon
    },
    [FRONTIER_TRAINER_ARTHUR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("ARTURO"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_UNDERSTOOD, EC_WORD_STORY, EC_WORD_HEARING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCITING, EC_WORD_ELLIPSIS, EC_WORD_THANKS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_TO, EC_WORD_LOSS, EC_WORD_NO, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Arthur
    },
    [FRONTIER_TRAINER_ALONDRA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ALONDRA"),
        .speechBefore = {EC_WORD_DAILY, EC_WORD_IS, EC_WORD_A, EC_WORD_THIN, EC_WORD_DAY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ARE, EC_WORD_A, EC_MOVE2(DIVE), EC_WORD_EXCELLENT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARE, EC_WORD_A, EC_MOVE2(DIVE), EC_WORD_AS_IF, EC_WORD_A, EC_WORD_TRAINER},
        .monSet = gBattleFrontierTrainerMons_Alondra
    },
    [FRONTIER_TRAINER_ADRIANA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("ADRIANA"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_REFRESHING, EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AGREE, EC_WORD_ARE, EC_WORD_REFRESHING, EC_WORD_BABY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOW, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_KNOCKOUT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Adriana
    },
    [FRONTIER_TRAINER_MALIK] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("MALIK"),
        .speechBefore = {EC_WORD_WAAAH, EC_WORD_MORE, EC_WORD_AN, EC_WORD_EVERY, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_AND, EC_WORD_KNOWS, EC_WORD_MEAN, EC_WORD_HOME},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_AND, EC_WORD_KNOWS, EC_WORD_MEAN, EC_WORD_HOME},
        .monSet = gBattleFrontierTrainerMons_Malik
    },
    [FRONTIER_TRAINER_JILL] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("ALESSIA"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_YET, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_YET, EC_WORD_MEAN, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_YET, EC_WORD_MEAN, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jill
    },
    [FRONTIER_TRAINER_ERIK] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("ERIK"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_YET, EC_WORD_HOW, EC_WORD_A, EC_MOVE(THUNDERBOLT), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_YET, EC_WORD_HOW, EC_WORD_A, EC_MOVE(THUNDERBOLT)},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_YET, EC_WORD_HOW, EC_WORD_A, EC_MOVE(THUNDERBOLT)},
        .monSet = gBattleFrontierTrainerMons_Erik
    },
    [FRONTIER_TRAINER_YAZMIN] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("GALATEA"),
        .speechBefore = {EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_FESTIVAL, EC_WORD_MISS, EC_WORD_HEARING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_IF_I_WIN, EC_WORD_MISS, EC_WORD_FESTIVAL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_IF_I_WIN, EC_WORD_MISS, EC_WORD_IF_I_LOSE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Yazmin
    },
    [FRONTIER_TRAINER_JAMAL] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("CECILIO"),
        .speechBefore = {EC_WORD_SOON, EC_WORD_ARE, EC_WORD_FATHER, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AGREE, EC_WORD_A, EC_WORD_KID, EC_WORD_HERE, EC_WORD_WITH, EC_WORD_EXCL},
        .speechLose = {EC_WORD_HOW, EC_WORD_FATHER, EC_WORD_TRAINS, EC_WORD_CONCEDE, EC_WORD_GOOD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jamal
    },
    [FRONTIER_TRAINER_LESLIE] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("LESLIE"),
        .speechBefore = {EC_WORD_SOON, EC_WORD_ARE, EC_WORD_MOTHER, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AGREE, EC_WORD_A, EC_WORD_KID, EC_WORD_HERE, EC_WORD_WITH, EC_WORD_EXCL},
        .speechLose = {EC_WORD_HOW, EC_WORD_MOTHER, EC_WORD_TRAINS, EC_WORD_CONCEDE, EC_WORD_HAS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Leslie
    },
    [FRONTIER_TRAINER_DAVE] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("DORIANO"),
        .speechBefore = {EC_WORD_WORKS, EC_WORD_MISS, EC_WORD_THING, EC_WORD_PLEASE, EC_WORD_MAKE, EC_WORD_QUES},
        .speechWin = {EC_WORD_PLEASE, EC_WORD_IF_I_WIN, EC_WORD_VERSUS, EC_WORD_LISTEN, EC_WORD_DO, EC_WORD_EXCL},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_IF_I_LOSE, EC_WORD_VERSUS, EC_WORD_LISTEN, EC_WORD_DO, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Dave
    },
    [FRONTIER_TRAINER_CARLO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("ALEARDO"),
        .speechBefore = {EC_WORD_GIVE, EC_WORD_HERE, EC_WORD_YET, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TO, EC_WORD_VICTORY, EC_WORD_YET, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_TO, EC_WORD_LOSS, EC_WORD_YET, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Carlo
    },
    [FRONTIER_TRAINER_EMILIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("EMILIA"),
        .speechBefore = {EC_WORD_WHEN, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_FEAR, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EXCITING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ENTERTAINING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emilia
    },
    [FRONTIER_TRAINER_DALIA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("ASIA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_BIKE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_VERY, EC_WORD_ALLOW, EC_WORD_TOO_LATE, EC_WORD_BIKE},
        .speechLose = {EC_WORD_TOO_LATE, EC_WORD_BIKE, EC_WORD_KNOWS, EC_WORD_THOSE_ARE, EC_WORD_BUT, EC_WORD_LOSE},
        .monSet = gBattleFrontierTrainerMons_Dalia
    },
    [FRONTIER_TRAINER_HITOMI] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("HITOMI"),
        .speechBefore = {EC_WORD_HERE_GOES, EC_WORD_MEAN, EC_WORD_DO, EC_WORD_TOO_LATE, EC_MOVE2(IMPRISON), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_LOSS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_VICTORY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hitomi
    },
    [FRONTIER_TRAINER_RICARDO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("RICARDO"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_BEGINNING, EC_WORD_LISTEN, EC_WORD_GAME, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS, EC_WORD_BEGINNING, EC_WORD_LISTEN, EC_WORD_HEARING, EC_WORD_AND, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_MAKE, EC_WORD_THOSE_WERE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ricardo
    },
    [FRONTIER_TRAINER_SHIZUKA] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("SHIZUKA"),
        .speechBefore = {EC_WORD_LAY, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_WEREN_T, EC_WORD_PERFECTION},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_WHICH, EC_WORD_PLEASE, EC_WORD_LOWS, EC_WORD_FORGET, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LET_S, EC_WORD_WILL_BE_HERE, EC_WORD_PERFECT, EC_WORD_WEREN_T, EC_WORD_PERFECTION, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Shizuka
    },
    [FRONTIER_TRAINER_JOANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("JOANA"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_WORKS, EC_WORD_IF_I_LOSE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HOW, EC_WORD_WILL, EC_WORD_GOTCHA, EC_WORD_WEREN_T, EC_WORD_LOSS, EC_WORD_QUES},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_GOTCHA, EC_WORD_THOSE_WERE, EC_WORD_WEREN_T, EC_WORD_LOSS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Joana
    },
    [FRONTIER_TRAINER_KELLY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("GIOIA"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_AS, EC_WORD_GHOST, EC_WORD_SOMETHING, EC_WORD_BETTER, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_IS, EC_WORD_WASN_T, EC_WORD_GHOST, EC_WORD_PROBABLY, EC_WORD_BETTER, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_IS, EC_WORD_WASN_T, EC_WORD_GHOST, EC_WORD_PROBABLY, EC_WORD_BETTER, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Kelly
    },
    [FRONTIER_TRAINER_RAYNA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("RAYNA"),
        .speechBefore = {EC_WORD_HOW, EC_MOVE(STRENGTH), EC_WORD_ARE, EC_WORD_WEREN_T, EC_WORD_NO_1, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NOW, EC_WORD_WORKS, EC_WORD_ABSOLUTELY, EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THOSE_WERE, EC_WORD_ELLIPSIS, EC_WORD_VERY, EC_WORD_THOSE_WERE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Rayna
    },
    [FRONTIER_TRAINER_EVAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("EVAN"),
        .speechBefore = {EC_WORD_DISASTER, EC_WORD_ON, EC_MOVE(SWEET_SCENT), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IS, EC_WORD_IT, EC_MOVE(SWEET_SCENT), EC_WORD_PROBABLY, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_ON, EC_WORD_IS, EC_WORD_IT, EC_WORD_STENCH, EC_WORD_PROBABLY, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Evan
    },
    [FRONTIER_TRAINER_JORDAN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("JORDAN"),
        .speechBefore = {EC_WORD_WAKES_UP, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_HOW, EC_WORD_IS, EC_WORD_NATURAL, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_KIDDING, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jordan
    },
    [FRONTIER_TRAINER_JOEL] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("GASTONE"),
        .speechBefore = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_DASH_DASH_DASH, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Joel
    },
    [FRONTIER_TRAINER_KRISTEN] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("KRISTEN"),
        .speechBefore = {EC_WORD_FOR, EC_WORD_IMPORTANT, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_FOR, EC_WORD_START},
        .speechWin = {EC_WORD_TOTALLY, EC_WORD_START, EC_WORD_WHOM, EC_WORD_WILL, EC_WORD_SAYS, EC_WORD_FEAR},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_LOWS, EC_WORD_STRONG, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kristen
    },
    [FRONTIER_TRAINER_SELPHY] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("SAMARA"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_A, EC_WORD_STRONG, EC_MOVE2(WISH), EC_WORD_LISTEN, EC_WORD_IF_I_WIN},
        .speechWin = {EC_WORD_IT, EC_MOVE2(WISH), EC_WORD_WHOM, EC_WORD_HAVE, EC_WORD_SAYS, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_A, EC_WORD_STRONG, EC_MOVE2(WISH), EC_WORD_CHANGE, EC_WORD_MAKE, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Selphy
    },
    [FRONTIER_TRAINER_CHLOE] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("CHLOE"),
        .speechBefore = {EC_WORD_NOW, EC_WORD_WAKES_UP, EC_WORD_OKAY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LATER, EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_MORE, EC_WORD_AN, EC_WORD_EVERY},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_STRONG, EC_WORD_LOWS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Chloe
    },
    [FRONTIER_TRAINER_NORTON] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("GUSTAVO"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_WHOSE, EC_WORD_ELLIPSIS, EC_WORD_ONLY, EC_WORD_DO},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_WHEN, EC_WORD_LISTEN, EC_WORD_BEAT, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_PERFECT, EC_WORD_BEAT, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Norton
    },
    [FRONTIER_TRAINER_LUKAS] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("LUKAS"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_MAKE, EC_WORD_A, EC_WORD_BEAUTIFUL, EC_WORD_GIGGLE},
        .speechWin = {EC_WORD_BUT, EC_WORD_ON, EC_WORD_IS, EC_WORD_A, EC_WORD_BEAUTIFUL, EC_WORD_GIGGLE},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_MAKE, EC_WORD_A, EC_WORD_BEAUTIFUL, EC_WORD_GIGGLE},
        .monSet = gBattleFrontierTrainerMons_Lukas
    },
    [FRONTIER_TRAINER_ZACH] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("GENESIO"),
        .speechBefore = {EC_WORD_LAY, EC_WORD_WEREN_T, EC_MOVE2(MIMIC), EC_WORD_ARE, EC_WORD_A, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_ARE, EC_WORD_HAPPY, EC_WORD_HOW, EC_WORD_ALL, EC_WORD_SWEETS, EC_POKEMON_NATIONAL(TOGEPI)},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_WEREN_T, EC_WORD_ANGER, EC_WORD_LISTEN, EC_POKEMON_NATIONAL(MANKEY), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Zach
    },
    [FRONTIER_TRAINER_KAITLYN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("CARINA"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_A, EC_WORD_STRONG, EC_WORD_LISTENS, EC_MOVE(PSYCHIC), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_TO, EC_WORD_VICTORY, EC_WORD_KTHX_BYE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kaitlyn
    },
    [FRONTIER_TRAINER_BREANNA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("BREANNA"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_WALKING, EC_WORD_THOSE_WERE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_MISS, EC_MOVE2(POUND), EC_WORD_HEH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_STRONG, EC_WORD_AND, EC_WORD_GUTSY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Breanna
    },
    [FRONTIER_TRAINER_KENDRA] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("AURORA"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_TOO_LATE, EC_WORD_BEGINNING, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_ESCAPE},
        .speechWin = {EC_WORD_WILL_BE_HERE, EC_WORD_MORE, EC_WORD_UNDERSTOOD, EC_WORD_QUES, EC_WORD_WILL, EC_WORD_LOST},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_MORE, EC_WORD_UNDERSTOOD, EC_WORD_QUES, EC_WORD_WILL, EC_WORD_WON},
        .monSet = gBattleFrontierTrainerMons_Kendra
    },
    [FRONTIER_TRAINER_MOLLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("LAURA"),
        .speechBefore = {EC_WORD_FOR, EC_MOVE2(ATTRACT), EC_WORD_HOWEVER, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ONLY, EC_WORD_TOYS},
        .speechLose = {EC_WORD_HOW, EC_WORD_WILL, EC_WORD_FAINTED, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Molly
    },
    [FRONTIER_TRAINER_JAZMIN] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("GETULIA"),
        .speechBefore = {EC_WORD_FORECAST, EC_WORD_AS_IF, EC_WORD_OKAY, EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_LOWS, EC_WORD_TO, EC_WORD_THIN, EC_MOVE2(FORESIGHT), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_MOVE2(FORESIGHT), EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_LATE},
        .monSet = gBattleFrontierTrainerMons_Jazmin
    },
    [FRONTIER_TRAINER_KELSEY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("KELSEY"),
        .speechBefore = {EC_WORD_FROM, EC_WORD_BEGINNING, EC_WORD_AS_IF, EC_WORD_PLEASE, EC_WORD_NAP, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_NOW, EC_WORD_PLEASE, EC_WORD_NAP, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOW, EC_WORD_PLEASE, EC_WORD_NAP, EC_WORD_MORE, EC_WORD_AM, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kelsey
    },
    [FRONTIER_TRAINER_JALEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("GALDINO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_COLLECTION, EC_WORD_TREASURE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_PLEASE, EC_WORD_MAKING, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_ANGER, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HIT, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_PLUS, EC_WORD_SIMPLE, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jalen
    },
    [FRONTIER_TRAINER_GRIFFEN] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("ORESTE"),
        .speechBefore = {EC_WORD_NITWIT, EC_WORD_BETTER, EC_WORD_AUNT, EC_WORD_ARE, EC_WORD_TO, EC_MOVE(ROCK_SLIDE)},
        .speechWin = {EC_WORD_ALSO, EC_WORD_LET_S, EC_WORD_WILL_BE_HERE, EC_WORD_TO, EC_MOVE(ROCK_SLIDE), EC_WORD_EXCL},
        .speechLose = {EC_WORD_LET_S, EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_TO, EC_MOVE(ROCK_SLIDE), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Griffen
    },
    [FRONTIER_TRAINER_XANDER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("OTELLO"),
        .speechBefore = {EC_WORD_DISASTER, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_SERIOUSLY, EC_WORD_TRADE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_MISS, EC_WORD_GO_EASY, EC_WORD_STRONG, EC_WORD_LAY, EC_WORD_WASN_T, EC_WORD_TRADE},
        .speechLose = {EC_WORD_AS, EC_WORD_TRADE, EC_WORD_AS_IF, EC_WORD_LATE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Xander
    },
    [FRONTIER_TRAINER_MARVIN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("MARVIN"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_TO, EC_WORD_CHALLENGE, EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_QUES},
        .speechWin = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_TO, EC_WORD_CHALLENGE},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_TO, EC_WORD_CHALLENGE, EC_WORD_EXCELLENT, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Marvin
    },
    [FRONTIER_TRAINER_BRENNAN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("BRENNAN"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_WILL, EC_WORD_NEWS, EC_WORD_TOO_LATE, EC_MOVE2(IMPRISON), EC_WORD_QUES},
        .speechWin = {EC_WORD_TRAINS, EC_WORD_NEWS, EC_WORD_AS_IF, EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_TRAINS, EC_WORD_NEWS, EC_WORD_AS_IF, EC_WORD_TO, EC_WORD_LOSS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Brennan
    },
    [FRONTIER_TRAINER_BALEY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("GAVINO"),
        .speechBefore = {EC_WORD_AS, EC_MOVE(SCREECH), EC_WORD_IS, EC_WORD_MUSIC, EC_WORD_NITWIT, EC_WORD_DON_T},
        .speechWin = {EC_WORD_WASN_T, EC_MOVE(SCREECH), EC_WORD_IS, EC_WORD_HOW, EC_WORD_TO, EC_WORD_STRATEGY},
        .speechLose = {EC_WORD_ON, EC_WORD_IS, EC_WORD_WASN_T, EC_MOVE(SCREECH), EC_WORD_PROBABLY, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Baley
    },
    [FRONTIER_TRAINER_ZACKARY] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("GEREMIA"),
        .speechBefore = {EC_WORD_IT, EC_WORD_BEGINNING, EC_WORD_IS, EC_WORD_GOLD, EC_WORD_NITWIT, EC_WORD_DON_T},
        .speechWin = {EC_WORD_WHOM, EC_WORD_WILL, EC_WORD_SAYS, EC_WORD_IF_I_LOSE, EC_WORD_BEGINNING, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WHICH, EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_WORD_IF_I_LOSE, EC_WORD_BEGINNING, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Zackary
    },
    [FRONTIER_TRAINER_GABRIEL] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("GABRIEL"),
        .speechBefore = {EC_WORD_IT, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_WINS, EC_WORD_ALWAYS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_VICTORY, EC_WORD_NOT_VERY, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_HOW, EC_WORD_ALWAYS},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_JUST, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Gabriel
    },
    [FRONTIER_TRAINER_EMILY] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("EMILY"),
        .speechBefore = {EC_WORD_FOR, EC_MOVE(HYPNOSIS), EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_STRATEGY},
        .speechWin = {EC_WORD_FOR, EC_MOVE(HYPNOSIS), EC_WORD_PREPOSTEROUS, EC_WORD_PROBABLY, EC_WORD_STRATEGY, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_FOR, EC_MOVE(HYPNOSIS), EC_WORD_AS_IF, EC_WORD_PREPOSTEROUS, EC_WORD_PROBABLY, EC_WORD_STRATEGY},
        .monSet = gBattleFrontierTrainerMons_Emily
    },
    [FRONTIER_TRAINER_JORDYN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("FIORY"),
        .speechBefore = {EC_WORD_CHOOSE, EC_WORD_KNOW, EC_WORD_IT, EC_WORD_WITH, EC_WORD_MYSTERY, EC_WORD_QUES},
        .speechWin = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_MYSTERY, EC_WORD_IS, EC_WORD_VERY, EC_WORD_MYSTERY},
        .speechLose = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_MYSTERY, EC_WORD_IS, EC_WORD_A_TINY_BIT, EC_WORD_MYSTERY},
        .monSet = gBattleFrontierTrainerMons_Jordyn
    },
    [FRONTIER_TRAINER_SOFIA] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("NIVES"),
        .speechBefore = {EC_WORD_BUT, EC_WORD_THING, EC_WORD_IS, EC_WORD_ON, EC_MOVE(SWEET_SCENT), EC_WORD_QUES},
        .speechWin = {EC_WORD_ON, EC_MOVE(SWEET_SCENT), EC_WORD_AS_IF, EC_WORD_SORRY, EC_WORD_NITWIT, EC_WORD_WHEN},
        .speechLose = {EC_WORD_ON, EC_MOVE(SWEET_SCENT), EC_WORD_AS_IF, EC_WORD_PREPOSTEROUS, EC_WORD_PROBABLY, EC_WORD_LIFE},
        .monSet = gBattleFrontierTrainerMons_Sofia
    },
    [FRONTIER_TRAINER_BRADEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("BRADEN"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_HEARING, EC_WORD_PERFECT, EC_WORD_VERSUS, EC_WORD_LISTEN, EC_WORD_DO},
        .speechWin = {EC_WORD_HOW, EC_WORD_TRAINER, EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_TO, EC_MOVE(STRENGTH)},
        .speechLose = {EC_WORD_HOW, EC_WORD_TRAINER, EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_TO, EC_MOVE(ROCK_SLIDE)},
        .monSet = gBattleFrontierTrainerMons_Braden
    },
    [FRONTIER_TRAINER_KAYDEN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("GERMANO"),
        .speechBefore = {EC_WORD_DISASTER, EC_WORD_GOURMET, EC_WORD_BUT, EC_WORD_ALSO, EC_WORD_HEARING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_HEARING, EC_WORD_IS, EC_WORD_IT, EC_WORD_WITH, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_GOURMET, EC_WORD_IS, EC_WORD_IT, EC_WORD_WITH, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kayden
    },
    [FRONTIER_TRAINER_COOPER] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("COOPER"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_PUSHOVER, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_NOT_VERY, EC_WORD_SKILLED, EC_WORD_HOW, EC_WORD_TRAINER, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_APOLOGIZE, EC_WORD_OFF, EC_WORD_TIME, EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Cooper
    },
    [FRONTIER_TRAINER_JULIA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("JULIA"),
        .speechBefore = {EC_WORD_WEREN_T, EC_MOVE(STRENGTH), EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_HERE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WEREN_T, EC_MOVE(STRENGTH), EC_WORD_IS, EC_WORD_THAT_S, EC_WORD_HERE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_PLUS, EC_WORD_WEREN_T, EC_MOVE(STRENGTH), EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Julia
    },
    [FRONTIER_TRAINER_AMARA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("ONDINA"),
        .speechBefore = {EC_WORD_TODAY, EC_WORD_NON_STOP, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_ALONE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_TIRED, EC_WORD_A, EC_WORD_SMALL, EC_WORD_SUPER, EC_WORD_MEGA, EC_WORD_HIP_AND},
        .speechLose = {EC_WORD_TODAY, EC_WORD_TOP, EC_WORD_WILL_BE_HERE, EC_WORD_PERFECT, EC_WORD_ALONE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Amara
    },
    [FRONTIER_TRAINER_LYNN] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("LYNN"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_A, EC_WORD_MYSTERY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NOW, EC_WORD_RUN, EC_WORD_IT, EC_WORD_EVER, EC_WORD_MYSTERY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_IT, EC_WORD_EVER, EC_WORD_MYSTERY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Lynn
    },
    [FRONTIER_TRAINER_JOVAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("JOVAN"),
        .speechBefore = {EC_WORD_BUT, EC_WORD_WILL_BE_HERE, EC_WORD_SHREDDED, EC_WORD_LISTEN, EC_WORD_HEARING, EC_WORD_QUES},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_SHREDDED, EC_WORD_LISTEN, EC_WORD_HEARING, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_TODAY, EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_TEACHES, EC_WORD_THOSE_ARE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jovan
    },
    [FRONTIER_TRAINER_DOMINIC] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("DOMINIC"),
        .speechBefore = {EC_WORD_PLAYS, EC_WORD_TO, EC_WORD_CAMERA, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TO, EC_WORD_CAMERA, EC_WORD_PROBABLY, EC_WORD_BETTER, EC_WORD_VICTORY, EC_WORD_QUES},
        .speechLose = {EC_WORD_TO, EC_WORD_CAMERA, EC_WORD_PROBABLY, EC_WORD_BETTER, EC_WORD_LOSS, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Dominic
    },
    [FRONTIER_TRAINER_NIKOLAS] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("NIKOLAS"),
        .speechBefore = {EC_WORD_GIVE, EC_MOVE2(FAINT_ATTACK), EC_WORD_LISTEN, EC_WORD_CONCEDE, EC_WORD_A, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_GIVE, EC_MOVE2(FAINT_ATTACK), EC_WORD_LISTEN, EC_WORD_CONCEDE, EC_POKEMON_NATIONAL(TAUROS), EC_WORD_QUES},
        .speechLose = {EC_WORD_GIVE, EC_MOVE2(FAINT_ATTACK), EC_WORD_LISTEN, EC_WORD_CONCEDE, EC_POKEMON_NATIONAL(MILTANK), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Nikolas
    },
    [FRONTIER_TRAINER_VALERIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("VALERIA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_TRAINS, EC_WORD_NEGATIVE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OFF, EC_WORD_VICTORY, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_LOWS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WHOM, EC_WORD_WILL, EC_WORD_PERFECT, EC_WORD_SAYS, EC_WORD_FEAR, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Valeria
    },
    [FRONTIER_TRAINER_DELANEY] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("GILDA"),
        .speechBefore = {EC_WORD_LATER, EC_WORD_WEREN_T, EC_WORD_SCHOOL, EC_WORD_THERE, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_BOY, EC_WORD_STORES, EC_WORD_MEAN, EC_WORD_SCHOOL},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_ANOTHER, EC_WORD_WEEK, EC_WORD_PRAISE, EC_WORD_APPEARS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Delaney
    },
    [FRONTIER_TRAINER_MEGHAN] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("JOLE"),
        .speechBefore = {EC_WORD_LIE, EC_WORD_KNOWS, EC_WORD_CRY, EC_WORD_HOME, EC_WORD_SAID, EC_WORD_ALWAYS},
        .speechWin = {EC_WORD_LIE, EC_WORD_KNOWS, EC_WORD_CRY, EC_WORD_HOME, EC_WORD_WIN, EC_WORD_ALWAYS},
        .speechLose = {EC_WORD_LIE, EC_WORD_KNOWS, EC_WORD_CRY, EC_WORD_HOME, EC_WORD_LOSE, EC_WORD_ALWAYS},
        .monSet = gBattleFrontierTrainerMons_Meghan
    },
    [FRONTIER_TRAINER_ROBERTO] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("ROBERTO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_NEVER, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_NITWIT, EC_WORD_ALWAYS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_DREAM, EC_WORD_WEREN_T, EC_MOVE2(REVENGE), EC_WORD_HOWEVER, EC_WORD_POKEMON, EC_WORD_DRAGON},
        .monSet = gBattleFrontierTrainerMons_Roberto
    },
    [FRONTIER_TRAINER_DAMIAN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DAMIANO"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_WEREN_T, EC_WORD_POWER, EC_WORD_LISTEN, EC_WORD_TO, EC_WORD_MACHINE},
        .speechWin = {EC_WORD_LOWS, EC_WORD_TO, EC_WORD_STRONG, EC_MOVE2(EXPLOSION), EC_WORD_LISTEN, EC_WORD_POWER},
        .speechLose = {EC_WORD_TODAY, EC_WORD_AS_IF, EC_WORD_TRAINS, EC_WORD_PERFECT, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Damian
    },
    [FRONTIER_TRAINER_BRODY] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("REGOLO"),
        .speechBefore = {EC_WORD_NATURALLY, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_MODE, EC_WORD_FASHION, EC_WORD_QUES},
        .speechWin = {EC_WORD_AND, EC_WORD_LET_S, EC_WORD_WILL_BE_HERE, EC_WORD_MODE, EC_WORD_FASHION, EC_WORD_QUES},
        .speechLose = {EC_WORD_END, EC_WORD_PROBABLY, EC_WORD_FASHION, EC_WORD_HOWEVER, EC_WORD_POKEMON, EC_WORD_DRAGON},
        .monSet = gBattleFrontierTrainerMons_Brody
    },
    [FRONTIER_TRAINER_GRAHAM] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("GOLIA"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_EXCELLENT, EC_WORD_FEELING, EC_WORD_BORED, EC_WORD_QUES},
        .speechWin = {EC_WORD_EXCELLENT, EC_WORD_ELLIPSIS, EC_WORD_BORED, EC_WORD_ELLIPSIS, EC_WORD_EXCITING, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Graham
    },
    [FRONTIER_TRAINER_TYLOR] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("TYLOR"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_TO, EC_MOVE(OVERHEAT), EC_WORD_LISTEN, EC_WORD_CARES, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_CARES, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_CARES, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_CARES, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS},
        .speechLose = {EC_WORD_FOR, EC_WORD_CARES, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_HERE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Tylor
    },
    [FRONTIER_TRAINER_JAREN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("JAREN"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_WHERE, EC_WORD_STRONG, EC_WORD_NITWIT, EC_WORD_IF_I_WIN, EC_WORD_QUES},
        .speechWin = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_SWEETS},
        .speechLose = {EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_SWEETS},
        .monSet = gBattleFrontierTrainerMons_Jaren
    },
    [FRONTIER_TRAINER_CORDELL] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("CORDELL"),
        .speechBefore = {EC_WORD_SAID, EC_WORD_LAY, EC_WORD_WEREN_T, EC_MOVE(STRENGTH), EC_WORD_TO_WHOM, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_LAY, EC_WORD_WEREN_T, EC_MOVE(STRENGTH), EC_WORD_TO_WHOM},
        .speechLose = {EC_WORD_SAID, EC_WORD_AND, EC_WORD_LOSE, EC_WORD_MEAN, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_WITH},
        .monSet = gBattleFrontierTrainerMons_Cordell
    },
    [FRONTIER_TRAINER_JAZLYN] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("BIBIANA"),
        .speechBefore = {EC_WORD_IT, EC_WORD_EVER, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_OKAY, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT, EC_WORD_EVER, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_SUPER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_POKEDEX, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_THOSE_WERE},
        .monSet = gBattleFrontierTrainerMons_Jazlyn
    },
    [FRONTIER_TRAINER_ZACHERY] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("BRANDO"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_LIFE, EC_WORD_IS, EC_WORD_SILKY, EC_WORD_IF, EC_WORD_WAKE_UP},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_LIFE, EC_WORD_IS, EC_WORD_SILKY, EC_WORD_IF, EC_WORD_SPIRIT},
        .speechLose = {EC_WORD_SILKY, EC_WORD_WEREN_T, EC_WORD_LIFE, EC_WORD_ALSO, EC_WORD_IF, EC_WORD_GENIUS},
        .monSet = gBattleFrontierTrainerMons_Zachery
    },
    [FRONTIER_TRAINER_JOHAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("FELICE"),
        .speechBefore = {EC_WORD_SOON, EC_WORD_THERE, EC_WORD_STORES, EC_WORD_CRY, EC_WORD_FOR, EC_WORD_WINTER},
        .speechWin = {EC_WORD_IF, EC_WORD_SPIRIT, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_SPRING, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LIE, EC_WORD_GENIUS, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_WINTER, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Johan
    },
    [FRONTIER_TRAINER_SHEA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("SHEA"),
        .speechBefore = {EC_WORD_SOMETHING, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_IMPORTANT, EC_WORD_WEREN_T, EC_WORD_BEAUTY},
        .speechWin = {EC_WORD_TODAY, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_TOO_LATE, EC_WORD_BEAUTY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_TODAY, EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_TOO_LATE, EC_WORD_BEAUTY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Shea
    },
    [FRONTIER_TRAINER_KAILA] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("KAILA"),
        .speechBefore = {EC_WORD_LISTENING, EC_WORD_ELLIPSIS, EC_WORD_GO, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_GUTSY, EC_WORD_BUT, EC_WORD_WILL, EC_WORD_LOST, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GUTSY, EC_WORD_AND, EC_WORD_WILL, EC_WORD_WON, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Kaila
    },
    [FRONTIER_TRAINER_ISIAH] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("BRIZIO"),
        .speechBefore = {EC_WORD_GIVE, EC_MOVE2(FAINT_ATTACK), EC_WORD_LISTEN, EC_WORD_APPEARS, EC_WORD_VERY, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_STUDY, EC_WORD_A_TINY_BIT, EC_WORD_BUT, EC_WORD_WIN, EC_WORD_VERY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_STUDY, EC_WORD_A_TINY_BIT, EC_WORD_AND, EC_WORD_WIN, EC_WORD_A_TINY_BIT, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Isiah
    },
    [FRONTIER_TRAINER_GARRETT] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("GARRETT"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_NEVER, EC_WORD_COMICS, EC_WORD_AND, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_ALSO, EC_WORD_WEREN_T, EC_WORD_MUSIC, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_THOSE_WERE},
        .speechLose = {EC_WORD_BUT, EC_WORD_PRAISE, EC_WORD_APPEARS, EC_WORD_LISTEN, EC_WORD_PLUS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Garrett
    },
    [FRONTIER_TRAINER_HAYLIE] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ELDA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_PLEASE, EC_WORD_PERFECT, EC_WORD_NAP, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_NAP, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ANGRY, EC_WORD_IF, EC_WORD_LOSE, EC_WORD_IS_IT_QUES, EC_WORD_FOR, EC_WORD_INSOMNIA},
        .monSet = gBattleFrontierTrainerMons_Haylie
    },
    [FRONTIER_TRAINER_MEGAN] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("ENZA"),
        .speechBefore = {EC_WORD_FOR, EC_MOVE(AROMATHERAPY), EC_WORD_IS, EC_WORD_LOWS, EC_WORD_LATE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WHOAH, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_LAY, EC_WORD_FOR, EC_MOVE(AROMATHERAPY)},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_WORD_WHERE, EC_MOVE(AROMATHERAPY), EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Megan
    },
    [FRONTIER_TRAINER_ISSAC] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("IARNO"),
        .speechBefore = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_HOBBY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHOM, EC_WORD_NEVER, EC_WORD_HAVEN_T, EC_WORD_SPORTS, EC_WORD_TRULY, EC_WORD_WATER},
        .speechLose = {EC_WORD_WHOM, EC_WORD_NEVER, EC_WORD_HAVEN_T, EC_WORD_SPORTS, EC_WORD_ALTHOUGH, EC_MOVE2(SLUDGE)},
        .monSet = gBattleFrontierTrainerMons_Issac
    },
    [FRONTIER_TRAINER_QUINTON] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("QUINTON"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_SAD, EC_WORD_HIT, EC_WORD_ARE, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WELL_THEN, EC_WORD_NATURALLY, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_VERY, EC_WORD_WEAK},
        .speechLose = {EC_WORD_HOW, EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_WORD_MEAN, EC_WORD_IF_I_LOSE, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Quinton
    },
    [FRONTIER_TRAINER_SALMA] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("SIBILLA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_LOWS, EC_WORD_HIT, EC_WORD_SAID, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_LOWS, EC_WORD_HIT, EC_WORD_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_LOWS, EC_WORD_HIT, EC_WORD_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Salma
    },
    [FRONTIER_TRAINER_ANSLEY] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("ELOISA"),
        .speechBefore = {EC_WORD_MISS, EC_WORD_WANTS, EC_WORD_TODAY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TO, EC_WORD_WANTS, EC_WORD_MORE, EC_WORD_PLUS, EC_WORD_THIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BUT, EC_WORD_THING, EC_WORD_ARE, EC_WORD_ONCE, EC_MOVE2(FURY_SWIPES), EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Ansley
    },
    [FRONTIER_TRAINER_HOLDEN] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("HOLDEN"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_MAKE, EC_WORD_TO, EC_WORD_COMMEMORATE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_COMMEMORATE, EC_WORD_PROBABLY, EC_WORD_BETTER, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_COMMEMORATE, EC_WORD_PROBABLY, EC_WORD_SINCE, EC_WORD_VICTORY, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Holden
    },
    [FRONTIER_TRAINER_LUCA] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("LUCA"),
        .speechBefore = {EC_WORD_PLAYS, EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_FROM, EC_WORD_ENCYCLOPEDIA, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_TO, EC_WORD_VICTORY, EC_WORD_FROM, EC_WORD_ENCYCLOPEDIA},
        .speechLose = {EC_WORD_ARE, EC_WORD_ONLY, EC_WORD_A, EC_WORD_KID, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Luca
    },
    [FRONTIER_TRAINER_JAMISON] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("JAMISON"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_WAKE_UP, EC_WORD_TOO_LATE, EC_WORD_THIS_IS_IT_EXCL, EC_WORD_OVERWHELMING, EC_WORD_QUES},
        .speechWin = {EC_WORD_WILL_BE_HERE, EC_WORD_AM, EC_WORD_LISTEN, EC_WORD_A, EC_MOVE2(SLEEP_POWDER), EC_WORD_EXCL},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_LOWS, EC_WORD_AS, EC_WORD_MODERN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jamison
    },
    [FRONTIER_TRAINER_GUNNAR] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("ELVEZIO"),
        .speechBefore = {EC_WORD_DAILY, EC_MOVE2(SLAM), EC_WORD_A, EC_WORD_FOE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AM, EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GIVES, EC_WORD_LOWS, EC_WORD_FEAR, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gunnar
    },
    [FRONTIER_TRAINER_CRAIG] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("CRAIG"),
        .speechBefore = {EC_WORD_TODAY, EC_WORD_IS_IT_QUES, EC_WORD_GOTCHA, EC_WORD_IT, EC_WORD_TRAIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_GOTCHA, EC_WORD_IT, EC_WORD_TRAIN, EC_WORD_PROBABLY, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_GOTCHA, EC_WORD_IT, EC_WORD_TRAIN, EC_WORD_PROBABLY, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Craig
    },
    [FRONTIER_TRAINER_PIERCE] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("PIPPO"),
        .speechBefore = {EC_WORD_MISS, EC_WORD_BEGINNING, EC_WORD_PLAYED, EC_WORD_QUES, EC_WORD_BEAUTIFUL, EC_WORD_QUES},
        .speechWin = {EC_WORD_MISS, EC_WORD_BEAUTIFUL, EC_WORD_IT, EC_WORD_BEGINNING, EC_WORD_LIE, EC_WORD_SPIRIT},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_BEAUTIFUL, EC_WORD_IT, EC_WORD_BEGINNING, EC_WORD_LIE, EC_WORD_GENIUS},
        .monSet = gBattleFrontierTrainerMons_Pierce
    },
    [FRONTIER_TRAINER_REGINA] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("REGINA"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_VERY, EC_WORD_GAME, EC_WORD_TRULY, EC_WORD_WATER},
        .speechWin = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_VERY, EC_WORD_IF_I_WIN, EC_WORD_TRULY, EC_WORD_WATER},
        .speechLose = {EC_WORD_WAAAH, EC_WORD_AS_IF, EC_WORD_TRAINS, EC_WORD_IF_I_LOSE, EC_WORD_TRULY, EC_WORD_WATER},
        .monSet = gBattleFrontierTrainerMons_Regina
    },
    [FRONTIER_TRAINER_ALISON] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("ALISON"),
        .speechBefore = {EC_WORD_WHOAH, EC_WORD_UNDERSTOOD, EC_WORD_AS_IF, EC_WORD_OR, EC_WORD_TOTALLY, EC_WORD_KINDERGARTEN},
        .speechWin = {EC_WORD_IT, EC_WORD_EVER, EC_WORD_TEACHER, EC_WORD_IS, EC_WORD_MEET, EC_WORD_QUES},
        .speechLose = {EC_WORD_MAGAZINE, EC_WORD_MEAN, EC_WORD_SCHOOL, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Alison
    },
    [FRONTIER_TRAINER_HANK] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("GIANNI"),
        .speechBefore = {EC_WORD_TO, EC_WORD_PARTY, EC_WORD_LISTEN, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_QUES},
        .speechWin = {EC_WORD_A, EC_MOVE2(WHIRLWIND), EC_WORD_LISTEN, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_EXCL},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WHICH, EC_WORD_NEVER, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_BUG},
        .monSet = gBattleFrontierTrainerMons_Hank
    },
    [FRONTIER_TRAINER_EARL] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("TOSCO"),
        .speechBefore = {EC_WORD_CHOOSE, EC_WORD_MAKING, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_INCREDIBLE, EC_WORD_QUES},
        .speechWin = {EC_WORD_ARE, EC_WORD_ISN_T_IT_QUES, EC_WORD_FOR, EC_WORD_TRAINER, EC_WORD_INCREDIBLE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_INCREDIBLE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Earl
    },
    [FRONTIER_TRAINER_RAMIRO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("RAMIRO"),
        .speechBefore = {EC_WORD_NITWIT, EC_WORD_FISHING, EC_WORD_ARE, EC_WORD_WENT, EC_WORD_MEAN, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_NITWIT, EC_WORD_IF_I_WIN, EC_WORD_ARE, EC_WORD_WENT, EC_WORD_MEAN, EC_WORD_SCHOOL},
        .speechLose = {EC_WORD_ALSO, EC_WORD_MEAN, EC_WORD_SCHOOL, EC_WORD_LOSE, EC_WORD_ALWAYS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ramiro
    },
    [FRONTIER_TRAINER_HUNTER] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("HUNTER"),
        .speechBefore = {EC_WORD_THESE, EC_WORD_LISTEN, EC_WORD_HEARING, EC_WORD_LAY, EC_WORD_DON_T, EC_WORD_QUES},
        .speechWin = {EC_WORD_BUT, EC_WORD_WILL_BE_HERE, EC_WORD_WEAK, EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BUT, EC_WORD_WILL_BE_HERE, EC_WORD_STRONG, EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Hunter
    },
    [FRONTIER_TRAINER_AIDEN] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("PIO"),
        .speechBefore = {EC_WORD_IT, EC_WORD_WORK, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_HOW, EC_WORD_LEARN, EC_WORD_MAKING, EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LET_S, EC_WORD_WILL_BE_HERE, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_LISTEN, EC_WORD_DON_T},
        .monSet = gBattleFrontierTrainerMons_Aiden
    },
    [FRONTIER_TRAINER_XAVIER] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("XAVIER"),
        .speechBefore = {EC_WORD_YAHOO, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WELCOME, EC_WORD_AND, EC_WORD_THANKS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Xavier
    },
    [FRONTIER_TRAINER_CLINTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("NADIR"),
        .speechBefore = {EC_WORD_FOR, EC_MOVE(HYPNOSIS), EC_WORD_WHICH, EC_WORD_PLAYED, EC_WORD_FEAR, EC_WORD_QUES},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_ANGER, EC_WORD_AS_IF, EC_WORD_PLAYED, EC_WORD_THOSE_ARE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_WEAK, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Clinton
    },
    [FRONTIER_TRAINER_JESSE] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("TURI"),
        .speechBefore = {EC_WORD_OFF, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_NITWIT, EC_WORD_BETTER, EC_WORD_MOTHER},
        .speechWin = {EC_WORD_OFF, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_NITWIT, EC_WORD_BETTER, EC_WORD_MOTHER},
        .speechLose = {EC_WORD_MOTHER, EC_WORD_ELLIPSIS, EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jesse
    },
    [FRONTIER_TRAINER_EDUARDO] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("QUIRINO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_WEREN_T, EC_WORD_MUSIC, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_MUSIC, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_STRONG, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_MUSIC, EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Eduardo
    },
    [FRONTIER_TRAINER_HAL] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("LIVIANO"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_MODE, EC_WORD_FASHION, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_FASHION, EC_WORD_ARE, EC_WORD_ISN_T_IT_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_MODE, EC_WORD_FASHION, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Hal
    },
    [FRONTIER_TRAINER_GAGE] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("ZENO"),
        .speechBefore = {EC_WORD_IT, EC_WORD_TYPE, EC_WORD_FLYING, EC_WORD_IS, EC_WORD_EXCELLENT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_VICTORY, EC_WORD_NOT_VERY, EC_WORD_TYPE, EC_WORD_FLYING},
        .speechLose = {EC_WORD_IF, EC_WORD_LOSE, EC_MOVE(FLY), EC_WORD_MEAN, EC_WORD_HOME, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Gage
    },
    [FRONTIER_TRAINER_ARNOLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("EROS"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_WORD_A, EC_WORD_DREAM, EC_WORD_INCREDIBLE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_IS, EC_WORD_A, EC_WORD_DREAM, EC_WORD_VERY, EC_WORD_BEAUTIFUL},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_IS, EC_WORD_A, EC_WORD_DREAM, EC_WORD_INCREDIBLE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Arnold
    },
    [FRONTIER_TRAINER_JARRETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("JARRETT"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_STORES, EC_WORD_LISTEN, EC_WORD_DANCE, EC_WORD_LAY, EC_WORD_DO},
        .speechWin = {EC_WORD_TRAINS, EC_WORD_DANCE, EC_WORD_AS_IF, EC_WORD_HEARING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_TRAINS, EC_WORD_DANCE, EC_WORD_AS_IF, EC_WORD_IF_I_LOSE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jarrett
    },
    [FRONTIER_TRAINER_GARETT] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("GIGLIO"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_DUDE, EC_WORD_IS, EC_WORD_SILKY, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IS, EC_WORD_SILKY, EC_WORD_KTHX_BYE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IS, EC_WORD_IT, EC_WORD_WITH, EC_WORD_BABE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Garett
    },
    [FRONTIER_TRAINER_EMANUEL] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("EMANUEL"),
        .speechBefore = {EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_SMARTNESS, EC_WORD_NITWIT, EC_WORD_HEARING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_OK_QUES, EC_WORD_COME, EC_WORD_SMARTNESS, EC_WORD_NITWIT, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HOW, EC_WORD_WILL, EC_WORD_SAYS, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Emanuel
    },
    [FRONTIER_TRAINER_GUSTAVO] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("ZEFIRO"),
        .speechBefore = {EC_MOVE(STRENGTH), EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_WILL, EC_MOVE(ENDURE), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WELCOME, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gustavo
    },
    [FRONTIER_TRAINER_KAMERON] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("CESARIO"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_MAKE, EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_HEART, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_TO, EC_WORD_HEART, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_TO, EC_WORD_HEART, EC_WORD_LOSS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Kameron
    },
    [FRONTIER_TRAINER_ALFREDO] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("NUNZIO"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_MAGAZINE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_IF_I_WIN, EC_WORD_PLUS, EC_WORD_MISS, EC_WORD_MAGAZINE},
        .speechLose = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_MAGAZINE, EC_WORD_PLUS, EC_WORD_MISS, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Alfredo
    },
    [FRONTIER_TRAINER_RUBEN] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("RUBEN"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_PERFECT, EC_WORD_HEARING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FEVER, EC_WORD_MISS, EC_WORD_VICTORY, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WELCOME, EC_WORD_WELCOME, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Ruben
    },
    [FRONTIER_TRAINER_LAMAR] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("LEOLUCA"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_QUES},
        .speechWin = {EC_WORD_THANKS, EC_WORD_NITWIT, EC_WORD_IT, EC_WORD_EVER, EC_MOVE2(PRESENT), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_JUST, EC_WORD_IS, EC_WORD_ONLY, EC_WORD_A, EC_WORD_TRENDY, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Lamar
    },
    [FRONTIER_TRAINER_JAXON] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("LEO"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_A, EC_WORD_SHELL_ARMOR, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_PERFECT, EC_WORD_EVEN_SO, EC_WORD_IS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WILL, EC_WORD_A, EC_WORD_SHELL_ARMOR, EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Jaxon
    },
    [FRONTIER_TRAINER_LOGAN] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("LOGAN"),
        .speechBefore = {EC_WORD_IF, EC_WORD_LOSE, EC_WORD_KNOWS, EC_WORD_MEAN, EC_WORD_APPEARS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_AND, EC_WORD_AS_IF, EC_WORD_STUDY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_AND, EC_WORD_KNOWS, EC_WORD_MEAN, EC_WORD_NAP},
        .monSet = gBattleFrontierTrainerMons_Logan
    },
    [FRONTIER_TRAINER_EMILEE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("ZAIRA"),
        .speechBefore = {EC_WORD_HOW, EC_WORD_CHOOSE, EC_WORD_HEARING, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_NOW, EC_WORD_MISS, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_GIVE, EC_MOVE2(SURF)},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_BUT, EC_WORD_ARE, EC_WORD_TO, EC_WORD_ROCK},
        .monSet = gBattleFrontierTrainerMons_Emilee
    },
    [FRONTIER_TRAINER_JOSIE] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("GAETANA"),
        .speechBefore = {EC_WORD_TO, EC_WORD_CONTEST, EC_WORD_LISTEN, EC_WORD_FASHION, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_FASHION, EC_WORD_LISTEN, EC_WORD_TODAY, EC_WORD_IS, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WORKS, EC_WORD_THING, EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_FASHION},
        .monSet = gBattleFrontierTrainerMons_Josie
    },
    [FRONTIER_TRAINER_ARMANDO] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("VALENTE"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_PLUS, EC_WORD_POKEMON, EC_WORD_LISTEN, EC_WORD_TYPE, EC_WORD_GRASS},
        .speechWin = {EC_WORD_IT, EC_WORD_TYPE, EC_WORD_GRASS, EC_WORD_IS, EC_WORD_VERY, EC_WORD_IMPORTANT},
        .speechLose = {EC_WORD_IT, EC_WORD_TYPE, EC_WORD_GRASS, EC_WORD_IS, EC_WORD_PERFECT, EC_WORD_INCREDIBLE},
        .monSet = gBattleFrontierTrainerMons_Armando
    },
    [FRONTIER_TRAINER_SKYLER] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("SAVIO"),
        .speechBefore = {EC_WORD_COULD, EC_WORD_AWFULLY, EC_WORD_TEACHES, EC_WORD_ME, EC_WORD_OLDEN, EC_WORD_QUES},
        .speechWin = {EC_WORD_WOWEE, EC_WORD_NATURALLY, EC_WORD_YES, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WOWEE, EC_WORD_NATURALLY, EC_WORD_NO, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Skyler
    },
    [FRONTIER_TRAINER_RUTH] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("RUTH"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_TO, EC_WORD_SENSE, EC_WORD_ENTERTAINING, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_THANKS, EC_WORD_EXCL, EC_WORD_HERE, EC_WORD_LOWS, EC_WORD_SIMPLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THANKS, EC_WORD_ALSO, EC_WORD_IF, EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Ruth
    },
    [FRONTIER_TRAINER_MELODY] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("MELODY"),
        .speechBefore = {EC_WORD_DRIZZLE, EC_WORD_NITWIT, EC_WORD_SUNDAY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_MOVE(BIDE), EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NATURALLY, EC_WORD_PLAYED, EC_WORD_BEAUTIFUL, EC_WORD_MONDAY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Melody
    },
    [FRONTIER_TRAINER_PEDRO] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("PEDRO"),
        .speechBefore = {EC_WORD_FOR, EC_WORD_WATER, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_PERFECT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ARE, EC_WORD_TO, EC_MOVE2(VINE_WHIP), EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL, EC_WORD_WEREN_T, EC_WORD_POWER, EC_WORD_LISTEN, EC_WORD_A, EC_MOVE(WHIRLPOOL)},
        .monSet = gBattleFrontierTrainerMons_Pedro
    },
    [FRONTIER_TRAINER_ERICK] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("ERICK"),
        .speechBefore = {EC_WORD_NOW, EC_WORD_WHICH, EC_WORD_GIVE, EC_WORD_IF_I_LOSE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_EVEN_SO, EC_WORD_REFUSE, EC_WORD_NOW, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOW, EC_WORD_IS_IT_QUES, EC_WORD_ONLY, EC_WORD_WEREN_T, EC_WORD_ESCAPE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Erick
    },
    [FRONTIER_TRAINER_ELAINE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("LENA"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_ADVENTURE, EC_WORD_HAVE, EC_WORD_START, EC_WORD_EXCL},
        .speechWin = {EC_WORD_TO, EC_WORD_VICTORY, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_ADVENTURE},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_ADVENTURE, EC_WORD_QUES_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Elaine
    },
    [FRONTIER_TRAINER_JOYCE] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("GIULIA"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_WAKES_UP, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_WEREN_T, EC_WORD_LOSS, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Joyce
    },
    [FRONTIER_TRAINER_TODD] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("SIRO"),
        .speechBefore = {EC_WORD_SOMETIME, EC_WORD_KNOWS, EC_WORD_SHAKE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TODAY, EC_WORD_KNOWS, EC_WORD_SHAKE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_TODAY, EC_WORD_AS_IF, EC_WORD_KNOWS, EC_WORD_SHAKE},
        .monSet = gBattleFrontierTrainerMons_Todd
    },
    [FRONTIER_TRAINER_GAVIN] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("ARNOLD"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_HERE, EC_WORD_IT, EC_WORD_BEGINNING, EC_WORD_MISS, EC_WORD_TRAINS},
        .speechWin = {EC_WORD_BUT, EC_WORD_OR, EC_WORD_AWFULLY, EC_WORD_MODE, EC_WORD_END, EC_WORD_QUES},
        .speechLose = {EC_WORD_TODAY, EC_WORD_IS_IT_QUES, EC_WORD_TEACHES, EC_WORD_LOWS, EC_WORD_THOSE_WERE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Gavin
    },
    [FRONTIER_TRAINER_MALORY] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("MARICA"),
        .speechBefore = {EC_WORD_WIN, EC_WORD_ELLIPSIS, EC_WORD_IS, EC_WORD_TO, EC_WORD_PROMISE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_LISTEN, EC_WORD_WORD, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_LISTEN, EC_WORD_WORD, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Malory
    },
    [FRONTIER_TRAINER_ESTHER] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("ESTHER"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_CHOOSE, EC_WORD_MAKE, EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_QUES},
        .speechWin = {EC_WORD_IT, EC_MOVE2(PRESENT), EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_IT, EC_MOVE2(PRESENT), EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_LOSS},
        .monSet = gBattleFrontierTrainerMons_Esther
    },
    [FRONTIER_TRAINER_OSCAR] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("OSCAR"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_MAKING, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_POWER, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WOWEE, EC_WORD_HERE, EC_WORD_UNDERSTOOD, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BORED, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Oscar
    },
    [FRONTIER_TRAINER_WILSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("WILSON"),
        .speechBefore = {EC_WORD_WORK, EC_WORD_VERY, EC_WORD_AND, EC_WORD_TRENDY, EC_WORD_A_TINY_BIT, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_TRENDY, EC_WORD_A_TINY_BIT, EC_WORD_BUT, EC_WORD_WIN, EC_WORD_ALWAYS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_OK_QUES, EC_WORD_COME, EC_MOVE(ENDURE), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Wilson
    },
    [FRONTIER_TRAINER_CLARE] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("CAMELIA"),
        .speechBefore = {EC_WORD_A, EC_WORD_TRAINER, EC_WORD_STRONG, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_A, EC_WORD_TRAINER, EC_WORD_WEAK, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_TRAINER, EC_WORD_EXCELLENT, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Clare
    },
    [FRONTIER_TRAINER_TESS] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_F,
        .trainerName = _("TERRY"),
        .speechBefore = {EC_WORD_MEAN, EC_WORD_DON_T, EC_WORD_NEVER, EC_WORD_VERY, EC_WORD_ALL, EC_WORD_SWEETS},
        .speechWin = {EC_WORD_ALL, EC_WORD_SWEETS, EC_WORD_ARE, EC_WORD_HOW, EC_WORD_ALL, EC_WORD_POKEMON},
        .speechLose = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_SWEETS, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Tess
    },
    [FRONTIER_TRAINER_LEON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("LEON"),
        .speechBefore = {EC_WORD_FOR, EC_WORD_TRAINER, EC_WORD_PLUS, EC_WORD_STRONG, EC_WORD_ARE, EC_WORD_ISN_T_IT_QUES},
        .speechWin = {EC_WORD_LISTEN, EC_WORD_VICTORY, EC_WORD_TOO_LATE, EC_WORD_VICTORY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_CAN_T_WIN, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Leon
    },
    [FRONTIER_TRAINER_ALONZO] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("ALBANO"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_MUST_BE, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_NATURALLY, EC_WORD_AS_IF, EC_WORD_PLEASE, EC_WORD_PERFECT, EC_WORD_IF_I_LOSE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_ALSO, EC_WORD_ISN_T_IT_QUES, EC_WORD_PLEASE, EC_WORD_IF_I_LOSE, EC_WORD_SOMETIME, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Alonzo
    },
    [FRONTIER_TRAINER_VINCE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("VINCE"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_PERFECT, EC_WORD_INVINCIBLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHOM, EC_WORD_GIVE, EC_WORD_THAT_S, EC_WORD_FEAR, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_SOMETIME, EC_WORD_AS_IF, EC_WORD_NON_STOP, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Vince
    },
    [FRONTIER_TRAINER_BRYON] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("BRYON"),
        .speechBefore = {EC_WORD_NOW, EC_WORD_WHICH, EC_WORD_GIVE, EC_WORD_MAKING, EC_WORD_ISN_T_IT_QUES, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_HEH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_HIT, EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Bryon
    },
    [FRONTIER_TRAINER_AVA] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("AVA"),
        .speechBefore = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_WORLD, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_IS, EC_WORD_IT, EC_WORD_WORLD, EC_WORD_PROBABLY, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_BUT, EC_WORD_HIT, EC_WORD_WILL_BE_HERE, EC_WORD_JUST, EC_WORD_STRONG, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Ava
    },
    [FRONTIER_TRAINER_MIRIAM] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("MIRIAM"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_GIVES, EC_WORD_FEAR, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_WHOM, EC_WORD_GIVES, EC_WORD_FEAR, EC_WORD_BUT, EC_WORD_IS_IT_QUES, EC_WORD_WON},
        .speechLose = {EC_WORD_WHOM, EC_WORD_GIVES, EC_WORD_FEAR, EC_WORD_AND, EC_WORD_IS_IT_QUES, EC_WORD_LOST},
        .monSet = gBattleFrontierTrainerMons_Miriam
    },
    [FRONTIER_TRAINER_CARRIE] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("GILIOLA"),
        .speechBefore = {EC_WORD_GUTSY, EC_WORD_HOW, EC_WORD_DON_T, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_GUTSY, EC_WORD_HOW, EC_WORD_DON_T, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_GUTSY, EC_WORD_AND, EC_WORD_WILL, EC_WORD_WON, EC_WORD_LET_S, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Carrie
    },
    [FRONTIER_TRAINER_GILLIAN2] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("GIANNA"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_TO, EC_WORD_THIN, EC_WORD_SENSE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_TRAINS, EC_WORD_TO, EC_WORD_SENSE, EC_WORD_PLUS, EC_WORD_THIN, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_TRAINS, EC_WORD_TO, EC_WORD_SENSE, EC_WORD_JUST, EC_WORD_THIN},
        .monSet = gBattleFrontierTrainerMons_Gillian2
    },
    [FRONTIER_TRAINER_TYLER] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("TYLER"),
        .speechBefore = {EC_WORD_HE_S, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_VICTORY, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_NATURALLY, EC_WORD_LOST, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Tyler
    },
    [FRONTIER_TRAINER_CHAZ] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("CHAZ"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_TO, EC_MOVE(CRABHAMMER)},
        .speechWin = {EC_WORD_MISS, EC_MOVE(CRABHAMMER), EC_WORD_HEH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MISS, EC_MOVE(CRABHAMMER), EC_WORD_MISS, EC_WORD_IS_IT_QUES, EC_WORD_GOTCHA, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Chaz
    },
    [FRONTIER_TRAINER_NELSON] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("NELSON"),
        .speechBefore = {EC_WORD_HOW, EC_WORD_FIGHTING, EC_WORD_IT, EC_WORD_WITH, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_FIGHTING, EC_WORD_THOSE_ARE, EC_WORD_IT, EC_WORD_WITH, EC_WORD_POKEMON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_IS, EC_WORD_SLIDE, EC_WORD_THOSE_ARE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Nelson
    },
    [FRONTIER_TRAINER_SHANIA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("SHANIA"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_WHOM, EC_WORD_BAD, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WHOM, EC_WORD_BAD, EC_WORD_AND, EC_WORD_TOO_WEAK, EC_WORD_NITWIT, EC_WORD_DON_T},
        .speechLose = {EC_WORD_WHOM, EC_WORD_BAD, EC_WORD_BUT, EC_WORD_AS_IF, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Shania
    },
    [FRONTIER_TRAINER_STELLA] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("STELLA"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_PERFECT, EC_WORD_MAKING, EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_BUT, EC_WORD_UGLY, EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_MISS, EC_WORD_TOO_STRONG, EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Stella
    },
    [FRONTIER_TRAINER_DORINE] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("DORINA"),
        .speechBefore = {EC_WORD_ISN_T_IT_QUES, EC_WORD_ARE, EC_WORD_TO, EC_WORD_DUDE, EC_WORD_STRONG, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HOW, EC_WORD_LEARN, EC_WORD_MAKING, EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_AS_IF, EC_WORD_STORES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Dorine
    },
    [FRONTIER_TRAINER_MADDOX] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("MADDOX"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_ARE, EC_WORD_ALL, EC_WORD_NO_1},
        .speechWin = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_TOO_WEAK, EC_WORD_ALWAYS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_AS_IF, EC_WORD_ALWAYS, EC_WORD_TOO_WEAK},
        .monSet = gBattleFrontierTrainerMons_Maddox
    },
    [FRONTIER_TRAINER_DAVIN] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("DAVIN"),
        .speechBefore = {EC_WORD_VICTORY, EC_WORD_FEELING, EC_WORD_LOSS, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_VICTORY, EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS, EC_WORD_INCREDIBLE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LOSS, EC_WORD_ELLIPSIS, EC_WORD_INCREDIBLE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Davin
    },
    [FRONTIER_TRAINER_TREVON] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("TREVON"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_TRAINER, EC_WORD_ONLY, EC_WORD_LISTEN, EC_WORD_POKEMON, EC_WORD_DRAGON},
        .speechWin = {EC_WORD_ONLY, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_ARE, EC_WORD_CLOSE},
        .speechLose = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_DRAGON, EC_WORD_ARE, EC_WORD_EASY, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Trevon
    },
    [FRONTIER_TRAINER_MATEO] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("MIRKO"),
        .speechBefore = {EC_WORD_PLAYS, EC_WORD_SOON, EC_WORD_NO, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_COULD, EC_WORD_SAYS, EC_WORD_SOON, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_LOSE, EC_WORD_SOON, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Mateo
    },
    [FRONTIER_TRAINER_BRET] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("FILI"),
        .speechBefore = {EC_WORD_WHOM, EC_WORD_NEVER, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_SCATTER, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_TOUGHNESS, EC_WORD_IS, EC_WORD_PERFECT, EC_WORD_IMPORTANT, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_COLLECTION, EC_WORD_ALL, EC_WORD_PLUSH_DOLL, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Bret
    },
    [FRONTIER_TRAINER_RAUL] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("RAUL"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_NEVER, EC_WORD_ALL, EC_WORD_EASY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_A, EC_WORD_THIS, EC_WORD_TRAINER, EC_WORD_WEAK},
        .speechLose = {EC_WORD_LET_S, EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Raul
    },
    [FRONTIER_TRAINER_KAY] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("KAY"),
        .speechBefore = {EC_WORD_WAAAH, EC_WORD_MORE, EC_WORD_AN, EC_WORD_EVERY, EC_WORD_FIGHTING, EC_WORD_QUES},
        .speechWin = {EC_WORD_NOW, EC_WORD_WHOM, EC_WORD_OK_QUES, EC_WORD_COME, EC_MOVE2(REST), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NOW, EC_WORD_PLEASE, EC_WORD_ALLOW, EC_WORD_MEAN, EC_WORD_HOME, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Kay
    },
    [FRONTIER_TRAINER_ELENA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ELENA"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_TO, EC_WORD_DUDE, EC_WORD_MISS, EC_WORD_HAVE, EC_WORD_TOUGHNESS},
        .speechWin = {EC_WORD_WHICH, EC_WORD_LIKES, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_TOUGHNESS, EC_WORD_QUES},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_TOUGHNESS, EC_WORD_AS_IF, EC_WORD_WHICH, EC_WORD_LIKES, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Elena
    },
    [FRONTIER_TRAINER_ALANA] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("ALANA"),
        .speechBefore = {EC_WORD_HERE_GOES, EC_WORD_IT, EC_WORD_WITH, EC_WORD_INVINCIBLE, EC_WORD_ATTACK, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OVERDO, EC_WORD_MORE, EC_WORD_APPEARS, EC_WORD_VERY, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HERE, EC_WORD_UNDERSTOOD, EC_WORD_IT, EC_WORD_WITH, EC_WORD_ATTACK, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Alana
    },
    [FRONTIER_TRAINER_ALEXAS] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("ALFIO"),
        .speechBefore = {EC_WORD_A, EC_WORD_TRAINER, EC_WORD_MODE, EC_WORD_SINCE, EC_WORD_AGE, EC_WORD_QUES_EXCL},
        .speechWin = {EC_WORD_GO, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WELL_THEN, EC_WORD_WILL_BE_HERE, EC_WORD_LOWS, EC_WORD_STRONG, EC_WORD_KTHX_BYE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Alexas
    },
    [FRONTIER_TRAINER_WESTON] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("WESTON"),
        .speechBefore = {EC_WORD_WHICH, EC_WORD_ATTACK, EC_WORD_LAY, EC_MOVE(STRENGTH), EC_WORD_OKAY, EC_WORD_QUES},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_LAY, EC_WORD_DO, EC_WORD_IS, EC_WORD_SIMPLE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_SURRENDER, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Weston
    },
    [FRONTIER_TRAINER_JASPER] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("VITALE"),
        .speechBefore = {EC_WORD_WEREN_T, EC_WORD_COOLNESS, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_WATER, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AND, EC_WORD_ISN_T_IT_QUES, EC_WORD_IS_IT_QUES, EC_WORD_PERFECT, EC_WORD_COOLNESS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_SHOCKED, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Jasper
    },
    [FRONTIER_TRAINER_NADIA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("NADIA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_LEARN, EC_WORD_PERFECT, EC_WORD_TAKE_THAT, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_ISN_T_IT_QUES, EC_WORD_WHICH, EC_WORD_PLEASE, EC_WORD_TAKE_THAT, EC_WORD_LIE, EC_WORD_TRAINS},
        .speechLose = {EC_WORD_LET_S, EC_WORD_WHOM, EC_WORD_LEARN, EC_WORD_TAKE_THAT, EC_WORD_LIE, EC_WORD_CHOOSE},
        .monSet = gBattleFrontierTrainerMons_Nadia
    },
    [FRONTIER_TRAINER_MIRANDA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("MIRANDA"),
        .speechBefore = {EC_WORD_HE_S, EC_EMPTY_WORD, EC_WORD_WAKES_UP, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_OFF, EC_WORD_IS, EC_WORD_AWFULLY, EC_WORD_WEREN_T, EC_WORD_END, EC_WORD_QUES},
        .speechLose = {EC_WORD_HOW, EC_WORD_PLEASE, EC_WORD_MAKING, EC_WORD_ARE, EC_WORD_VERY, EC_WORD_WEAK},
        .monSet = gBattleFrontierTrainerMons_Miranda
    },
    [FRONTIER_TRAINER_EMMA] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("EMILIE"),
        .speechBefore = {EC_WORD_RUN, EC_WORD_VERY, EC_WORD_UP, EC_WORD_LISTEN, EC_WORD_DO, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_NOW, EC_WORD_RUN, EC_WORD_MISS, EC_WORD_WILL_BE_HERE, EC_WORD_WEAK, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_NOW, EC_WORD_RUN, EC_WORD_MISS, EC_WORD_WILL_BE_HERE, EC_WORD_STRONG, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Emma
    },
    [FRONTIER_TRAINER_ROLANDO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("ROLANDO"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_A, EC_WORD_DRAGON, EC_WORD_HOWEVER, EC_WORD_POKEMON, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_OVER, EC_WORD_WILL, EC_WORD_WHERE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_LET_S, EC_WORD_AS_IF, EC_WORD_WORKS, EC_WORD_WONDER, EC_WORD_ARE, EC_WORD_ISN_T_IT_QUES},
        .monSet = gBattleFrontierTrainerMons_Rolando
    },
    [FRONTIER_TRAINER_STANLY] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("FEDELE"),
        .speechBefore = {EC_WORD_A, EC_WORD_TALENT, EC_WORD_SIMPLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HERE, EC_WORD_HOW, EC_WORD_INSTEAD, EC_WORD_FORECAST, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NOW, EC_WORD_WILL_BE_HERE, EC_WORD_HAPPY, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Stanly
    },
    [FRONTIER_TRAINER_DARIO] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("DARIO"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_PROBABLY, EC_WORD_BETTER, EC_MOVE2(FORESIGHT), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_MOVE2(FORESIGHT), EC_WORD_IS, EC_WORD_MODE, EC_WORD_PERFECTION},
        .speechLose = {EC_WORD_WHOM, EC_WORD_WILL, EC_WORD_GOTCHA, EC_WORD_TOO_LATE, EC_MOVE(REVERSAL), EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Dario
    },
    [FRONTIER_TRAINER_KARLEE] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("CARLINA"),
        .speechBefore = {EC_WORD_PLEASE, EC_WORD_AWFULLY, EC_WORD_MAKING, EC_WORD_A, EC_WORD_EXCITING, EC_WORD_FINAL},
        .speechWin = {EC_WORD_EXCITING, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_A, EC_WORD_EXCITING, EC_WORD_FINAL, EC_WORD_BUT, EC_WORD_NITWIT, EC_WORD_DO},
        .monSet = gBattleFrontierTrainerMons_Karlee
    },
    [FRONTIER_TRAINER_JAYLIN] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("AVE"),
        .speechBefore = {EC_WORD_EVEN_SO, EC_WORD_IS, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_STRONG, EC_WORD_QUES},
        .speechWin = {EC_WORD_BUT, EC_WORD_MISS, EC_WORD_WANTS, EC_WORD_OFF, EC_WORD_FIGHTING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_WANTS, EC_WORD_WHOM, EC_WORD_HAVE, EC_WORD_SAYS, EC_WORD_IF_I_LOSE},
        .monSet = gBattleFrontierTrainerMons_Jaylin
    },
    [FRONTIER_TRAINER_INGRID] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("INGRID"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_NITWIT, EC_WORD_WHEN, EC_WORD_WANDERING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_TO, EC_WORD_SILKY, EC_WORD_FIGHTING, EC_WORD_ELLIPSIS, EC_WORD_HEH, EC_WORD_QUES},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_HOW, EC_WORD_WILL_BE_HERE, EC_WORD_WANDERING, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Ingrid
    },
    [FRONTIER_TRAINER_DELILAH] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("DACIA"),
        .speechBefore = {EC_WORD_IF, EC_WORD_WIN, EC_WORD_AS_IF, EC_WORD_WHICH, EC_WORD_HURRIED, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WHICH, EC_WORD_PLAYED, EC_WORD_ANGER, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_WHOM, EC_WORD_PLAYED, EC_WORD_ANGER, EC_WORD_WEREN_T, EC_WORD_SINCE, EC_WORD_VICTORY},
        .monSet = gBattleFrontierTrainerMons_Delilah
    },
    [FRONTIER_TRAINER_CARLY] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("CARLY"),
        .speechBefore = {EC_WORD_WAKES_UP, EC_WORD_LAY, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_STRATEGY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_STRATEGY, EC_WORD_IS, EC_WORD_EXCELLENT, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_NEVER, EC_WORD_ALL, EC_WORD_DID, EC_WORD_POKEMON},
        .monSet = gBattleFrontierTrainerMons_Carly
    },
    [FRONTIER_TRAINER_LEXIE] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("LEDA"),
        .speechBefore = {EC_WORD_CHOOSE, EC_WORD_MAKING, EC_WORD_HOWEVER, EC_WORD_POKEMON, EC_WORD_KTHX_BYE, EC_WORD_QUES},
        .speechWin = {EC_WORD_PERFECT, EC_WORD_KTHX_BYE, EC_WORD_HEH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_PLUS, EC_WORD_KTHX_BYE, EC_WORD_LET_S, EC_WORD_LISTEN, EC_WORD_DON_T},
        .monSet = gBattleFrontierTrainerMons_Lexie
    },
    [FRONTIER_TRAINER_MILLER] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("FURIO"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_ANY, EC_WORD_PHONE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MOTHER, EC_WORD_QUES, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_ISN_T_IT_QUES, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MOTHER, EC_WORD_QUES, EC_WORD_TODAY, EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Miller
    },
    [FRONTIER_TRAINER_MARV] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("BEPPE"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_TO, EC_WORD_SURPRISE, EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_TO, EC_WORD_SILKY, EC_WORD_SURPRISE, EC_WORD_HEH, EC_WORD_QUES},
        .speechLose = {EC_WORD_TO, EC_WORD_SILKY, EC_WORD_SURPRISE, EC_WORD_ELLIPSIS, EC_WORD_HEH, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Marv
    },
    [FRONTIER_TRAINER_LAYTON] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("LAYTON"),
        .speechBefore = {EC_WORD_RUN, EC_WORD_LISTEN, EC_WORD_CONCEDE, EC_WORD_MODE, EC_WORD_PERFECTION, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NOW, EC_WORD_WASN_T, EC_WORD_WORKS, EC_WORD_ALSO, EC_WORD_LET_S, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_ALSO, EC_WORD_LET_S, EC_WORD_WILL_BE_HERE, EC_WORD_MODE, EC_WORD_PERFECTION, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Layton
    },
    [FRONTIER_TRAINER_BROOKS] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("EGISTO"),
        .speechBefore = {EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_LISTEN, EC_WORD_LEVEL, EC_WORD_EXCELLENT, EC_WORD_EXCL},
        .speechWin = {EC_WORD_LEVEL, EC_WORD_EXCELLENT, EC_WORD_AND, EC_WORD_PERFECT, EC_WORD_ENTERTAINING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_ABOVE, EC_WORD_LET_S, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Brooks
    },
    [FRONTIER_TRAINER_GREGORY] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("GREGORY"),
        .speechBefore = {EC_WORD_MODE, EC_WORD_BETTER, EC_WORD_AGE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_MODE, EC_WORD_BETTER, EC_WORD_AGE, EC_WORD_PLEASE, EC_WORD_MORE, EC_WORD_IF_I_WIN},
        .speechLose = {EC_WORD_MODE, EC_WORD_BETTER, EC_WORD_AGE, EC_WORD_AS_IF, EC_WORD_PLEASE, EC_WORD_IF_I_WIN},
        .monSet = gBattleFrontierTrainerMons_Gregory
    },
    [FRONTIER_TRAINER_REESE] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("AUGUSTO"),
        .speechBefore = {EC_WORD_CHOOSE, EC_WORD_PRETEND, EC_WORD_TO, EC_WORD_THING, EC_WORD_IMPORTANT, EC_WORD_QUES},
        .speechWin = {EC_WORD_MAKE, EC_WORD_SPORTS, EC_WORD_PLAYED, EC_WORD_THOSE_ARE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BOOK, EC_WORD_IS, EC_WORD_ABOVE, EC_WORD_PROBABLY, EC_WORD_TELEVISION, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Reese
    },
    [FRONTIER_TRAINER_MASON] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("GIGI"),
        .speechBefore = {EC_WORD_HE_S, EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_MAKE, EC_WORD_FEAR, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THANKS, EC_WORD_ELLIPSIS, EC_WORD_NOW, EC_WORD_ARE, EC_WORD_HAPPY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_TO, EC_WORD_THIN, EC_WORD_DISAPPOINT, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Mason
    },
    [FRONTIER_TRAINER_TOBY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("TOBY"),
        .speechBefore = {EC_WORD_LISTENING, EC_WORD_ELLIPSIS, EC_WORD_ISN_T_IT_QUES, EC_WORD_WIN, EC_WORD_ALWAYS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_ARE, EC_WORD_A, EC_WORD_DRAGON, EC_WORD_FEELING, EC_WORD_NO, EC_WORD_QUES},
        .speechLose = {EC_WORD_HOW, EC_WORD_SMARTNESS, EC_WORD_ARE, EC_WORD_ABOVE, EC_WORD_ISN_T_IT_QUES, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Toby
    },
    [FRONTIER_TRAINER_DOROTHY] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("DOROTHY"),
        .speechBefore = {EC_WORD_ALSO, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_AS, EC_WORD_SPORTS},
        .speechWin = {EC_WORD_OFF, EC_WORD_VICTORY, EC_WORD_IS, EC_WORD_HOW, EC_WORD_TO, EC_MOVE2(REFRESH)},
        .speechLose = {EC_WORD_OFF, EC_WORD_LOSS, EC_WORD_IS, EC_WORD_HOW, EC_WORD_TO, EC_MOVE2(REFRESH)},
        .monSet = gBattleFrontierTrainerMons_Dorothy
    },
    [FRONTIER_TRAINER_PIPER] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("PERLA"),
        .speechBefore = {EC_WORD_IT, EC_WORD_WORLD, EC_WORD_COME, EC_WORD_PRETEND, EC_WORD_IF, EC_WORD_GUTSY},
        .speechWin = {EC_WORD_IF, EC_WORD_GUTSY, EC_WORD_WASN_T, EC_WORD_OVERDO, EC_WORD_MAKE, EC_WORD_MAKING},
        .speechLose = {EC_WORD_GUTSY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Piper
    },
    [FRONTIER_TRAINER_FINN] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("FINN"),
        .speechBefore = {EC_WORD_A, EC_WORD_THIS, EC_WORD_TRAINER, EC_WORD_QUES_EXCL, EC_WORD_NO, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_BUT, EC_WORD_LIE, EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_END, EC_WORD_QUES},
        .speechLose = {EC_WORD_NOW, EC_WORD_WHOM, EC_MOVE2(REST), EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Finn
    },
    [FRONTIER_TRAINER_SAMIR] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("SAMIR"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_A, EC_MOVE2(DIVE), EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_AND, EC_WORD_LET_S, EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_MOVE2(DIVE), EC_WORD_QUES},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_LOST, EC_WORD_AND, EC_WORD_ARE, EC_WORD_LOST, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Samir
    },
    [FRONTIER_TRAINER_FIONA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("FIONA"),
        .speechBefore = {EC_WORD_WILL_BE_HERE, EC_WORD_LOWS, EC_WORD_ALONE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BUT, EC_WORD_AS_IF, EC_WORD_WILL_BE_HERE, EC_WORD_VERY, EC_WORD_ALONE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WILL_BE_HERE, EC_WORD_PLUS, EC_WORD_ALONE, EC_WORD_LISTEN, EC_WORD_DON_T, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Fiona
    },
    [FRONTIER_TRAINER_GLORIA] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("GLORIA"),
        .speechBefore = {EC_WORD_WONDER, EC_WORD_FIGHTING, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_FORGIVE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_DARN, EC_WORD_IT, EC_WORD_FORGIVE, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_OOPS, EC_WORD_ELLIPSIS, EC_WORD_RECEIVED, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Gloria
    },
    [FRONTIER_TRAINER_NICO] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("NICO"),
        .speechBefore = {EC_WORD_HERE_I_COME, EC_WORD_EXCL, EC_WORD_SURPRISE, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SORRY, EC_WORD_NITWIT, EC_WORD_WEREN_T, EC_WORD_SURPRISE, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_BUT, EC_WORD_WILL_BE_HERE, EC_WORD_LET_S, EC_WORD_WEREN_T, EC_WORD_SURPRISE, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Nico
    },
    [FRONTIER_TRAINER_JEREMY] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("JEREMY"),
        .speechBefore = {EC_WORD_TRAINS, EC_WORD_CONCEDE, EC_WORD_A, EC_WORD_THIN, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_DREAM, EC_WORD_IS, EC_WORD_NEAR, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_IT, EC_WORD_WITH, EC_WORD_DREAM, EC_WORD_IS, EC_WORD_FAR, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Jeremy
    },
    [FRONTIER_TRAINER_CAITLIN] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("CAITLIN"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_SILKY, EC_WORD_HEH, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_BUT, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_ONLY, EC_WORD_SILKY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_BEAUTY, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_HERE, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Caitlin
    },
    [FRONTIER_TRAINER_REENA] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("DORA"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_ALWAYS, EC_WORD_HAPPY, EC_WORD_HAPPY, EC_WORD_HAPPY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NON_STOP, EC_WORD_PROBABLY, EC_WORD_HAPPINESS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_ARE, EC_WORD_LOWS, EC_WORD_HAPPY, EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Reena
    },
    [FRONTIER_TRAINER_AVERY] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("PIERINO"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_PLUS, EC_WORD_LISTEN, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_BUG},
        .speechWin = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_ARE, EC_WORD_DOWNCAST},
        .speechLose = {EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_ARE, EC_WORD_GOT},
        .monSet = gBattleFrontierTrainerMons_Avery
    },
    [FRONTIER_TRAINER_LIAM] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("LIAM"),
        .speechBefore = {EC_WORD_FIRE, EC_WORD_AND, EC_WORD_FLYING, EC_WORD_AS_IF, EC_WORD_OK_QUES, EC_WORD_NEVER},
        .speechWin = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_BUG, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_THOSE_WERE},
        .speechLose = {EC_WORD_WORKS, EC_WORD_THOSE_ARE, EC_WORD_THING, EC_WORD_AS_IF, EC_WORD_OK_QUES, EC_WORD_LIKES},
        .monSet = gBattleFrontierTrainerMons_Liam
    },
    [FRONTIER_TRAINER_THEO] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("THEO"),
        .speechBefore = {EC_WORD_FISHING, EC_WORD_IS, EC_WORD_WEREN_T, EC_WORD_BETTER, EC_WORD_LIFE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_DISASTER, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_LISTEN, EC_WORD_TYPE, EC_WORD_WATER},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_ANOTHER, EC_WORD_TIME, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Theo
    },
    [FRONTIER_TRAINER_BAILEY] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("BETTO"),
        .speechBefore = {EC_WORD_ON, EC_WORD_IS, EC_WORD_A, EC_WORD_WORLD, EC_WORD_ADULT, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_GIVE, EC_WORD_MAKING, EC_WORD_WEREN_T, EC_WORD_JOY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_GIVE, EC_WORD_MAKING, EC_WORD_WEREN_T, EC_MOVE2(FRUSTRATION), EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Bailey
    },
    [FRONTIER_TRAINER_HUGO] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("REMO"),
        .speechBefore = {EC_WORD_RUN, EC_WORD_MISS, EC_WORD_PLEASE, EC_WORD_IF_I_WIN, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_FORGETS, EC_WORD_IS, EC_WORD_LISTENS, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_ANOTHER, EC_WORD_TIME, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Hugo
    },
    [FRONTIER_TRAINER_BRYCE] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("BRYCE"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_SAYS, EC_WORD_THIRSTY, EC_WORD_VACATION, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LATER, EC_WORD_ABOUT, EC_WORD_VACATION, EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_STRONG},
        .speechLose = {EC_WORD_WHOM, EC_WORD_OK_QUES, EC_WORD_COME, EC_MOVE2(REST), EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Bryce
    },
    [FRONTIER_TRAINER_GIDEON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("GIDEON"),
        .speechBefore = {EC_WORD_WHICH, EC_WORD_GIVE, EC_WORD_FEAR, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_BUT, EC_WORD_AS_IF, EC_WORD_GIVE, EC_WORD_FEAR},
        .speechLose = {EC_WORD_IS_IT_QUES, EC_WORD_FEAR, EC_WORD_LISTEN, EC_WORD_AS_IF, EC_WORD_CONCEDE, EC_WORD_STRONG},
        .monSet = gBattleFrontierTrainerMons_Gideon
    },
    [FRONTIER_TRAINER_TRISTON] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("MILO"),
        .speechBefore = {EC_WORD_LOWS, EC_WORD_CHOOSE, EC_WORD_HEARING, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_LOWS, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_HOW, EC_WORD_LEARN, EC_WORD_MAKING, EC_WORD_LOSE, EC_WORD_ALWAYS, EC_WORD_ELLIPSIS},
        .monSet = gBattleFrontierTrainerMons_Triston
    },
    [FRONTIER_TRAINER_CHARLES] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("CHARLES"),
        .speechBefore = {EC_WORD_LAY, EC_WORD_DON_T, EC_WORD_AS_IF, EC_WORD_LEARN, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_AS_IF, EC_WORD_LEARN, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS, EC_WORD_LOWS, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LEARN, EC_WORD_LOWS, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Charles
    },
    [FRONTIER_TRAINER_RAYMOND] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("RAYMOND"),
        .speechBefore = {EC_WORD_WHICH, EC_MOVE(SING), EC_WORD_TO, EC_WORD_SILKY, EC_WORD_SONGS, EC_WORD_QUES},
        .speechWin = {EC_WORD_MISS, EC_WORD_SILKY, EC_WORD_VICTORY, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_MISHEARD, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Raymond
    },
    [FRONTIER_TRAINER_DIRK] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("NEREO"),
        .speechBefore = {EC_WORD_SMOOTH, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_LISTEN, EC_WORD_TYPE, EC_WORD_FLYING},
        .speechWin = {EC_WORD_BATTLE, EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_LISTEN, EC_WORD_TYPE, EC_WORD_FLYING},
        .speechLose = {EC_WORD_FLYING, EC_WORD_IS, EC_WORD_IT, EC_WORD_TYPE, EC_WORD_PLUS, EC_WORD_STRONG},
        .monSet = gBattleFrontierTrainerMons_Dirk
    },
    [FRONTIER_TRAINER_HAROLD] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("HAROLD"),
        .speechBefore = {EC_WORD_WHICH, EC_WORD_NEVER, EC_WORD_ALL, EC_WORD_TOO, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_LOWS, EC_WORD_WHICH, EC_WORD_NEVER, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WHICH, EC_WORD_NEVER, EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Harold
    },
    [FRONTIER_TRAINER_OMAR] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("CELSO"),
        .speechBefore = {EC_WORD_PLEASE, EC_WORD_IF_I_WIN, EC_WORD_NITWIT, EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_QUES},
        .speechWin = {EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_NITWIT, EC_WORD_DO, EC_WORD_MUST_BE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BUT, EC_WORD_GIMME, EC_MOVE2(PRESENT), EC_WORD_QUES, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Omar
    },
    [FRONTIER_TRAINER_PETER] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("PETER"),
        .speechBefore = {EC_WORD_WHICH, EC_MOVE(SING), EC_WORD_LISTEN, EC_WORD_HOW, EC_WORD_ARE, EC_WORD_HAPPY},
        .speechWin = {EC_WORD_YEAH, EC_WORD_EXCL, EC_WORD_ARE, EC_WORD_HAPPY, EC_WORD_HAPPY, EC_WORD_HAPPY},
        .speechLose = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_CHOOSE, EC_WORD_MAKE, EC_WORD_DIET, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Peter
    },
    [FRONTIER_TRAINER_DEV] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("TULLIO"),
        .speechBefore = {EC_WORD_WAKES_UP, EC_WORD_SOON, EC_WORD_UP, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_SAID, EC_WORD_AND, EC_WORD_AS_IF, EC_MOVE2(REST), EC_WORD_MUST_BE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_LATER, EC_WORD_OFF, EC_WORD_FIGHTING, EC_WORD_WHOM, EC_MOVE2(REST), EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Dev
    },
    [FRONTIER_TRAINER_COREY] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("LEONE"),
        .speechBefore = {EC_WORD_WHICH, EC_WORD_GIVE, EC_WORD_MAKING, EC_WORD_ABSOLUTELY, EC_WORD_ARE, EC_WORD_STRONG},
        .speechWin = {EC_WORD_ARE, EC_WORD_STRONG, EC_WORD_HOW, EC_WORD_LEARN, EC_WORD_MAKING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_BETTER, EC_MOVE2(FRUSTRATION), EC_WORD_IS, EC_WORD_PERFECT, EC_WORD_STRONG},
        .monSet = gBattleFrontierTrainerMons_Corey
    },
    [FRONTIER_TRAINER_ANDRE] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("CARMINE"),
        .speechBefore = {EC_WORD_IS_IT_QUES, EC_WORD_IT, EC_WORD_FIRE, EC_WORD_OUTSIDE, EC_WORD_LISTEN, EC_WORD_DON_T},
        .speechWin = {EC_WORD_LAY, EC_WORD_IT, EC_WORD_FIRE, EC_WORD_IS_IT_QUES, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LAY, EC_WORD_IT, EC_WORD_FIRE, EC_WORD_AS_IF, EC_WORD_IS_IT_QUES, EC_WORD_WON},
        .monSet = gBattleFrontierTrainerMons_Andre
    },
    [FRONTIER_TRAINER_FERRIS] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("DANY"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_ISN_T_IT_QUES, EC_WORD_IT, EC_WORD_NO_1, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechWin = {EC_WORD_HOW, EC_WORD_LEARN, EC_WORD_MAKING, EC_WORD_ARE, EC_WORD_IT, EC_WORD_NO_1},
        .speechLose = {EC_WORD_WELL_THEN, EC_WORD_AS_IF, EC_WORD_ARE, EC_WORD_PLUS, EC_WORD_IT, EC_WORD_NO_1},
        .monSet = gBattleFrontierTrainerMons_Ferris
    },
    [FRONTIER_TRAINER_ALIVIA] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("ALIVIA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_RUN, EC_WORD_IF, EC_WORD_IS, EC_WORD_SIMPLE, EC_WORD_IF_I_WIN},
        .speechWin = {EC_WORD_LOWS, EC_WORD_HERE, EC_WORD_SIMPLE, EC_WORD_ELLIPSIS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_AS_IF, EC_WORD_IS, EC_WORD_VERY, EC_WORD_SIMPLE},
        .monSet = gBattleFrontierTrainerMons_Alivia
    },
    [FRONTIER_TRAINER_PAIGE] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("PIERA"),
        .speechBefore = {EC_WORD_TO, EC_WORD_FIGHTING, EC_WORD_ENTERTAINING, EC_WORD_ELLIPSIS, EC_WORD_OKAY, EC_WORD_QUES},
        .speechWin = {EC_WORD_THANKS, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .speechLose = {EC_WORD_REFUSE, EC_WORD_LOWS, EC_WORD_STRONG, EC_WORD_EXCL, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Paige
    },
    [FRONTIER_TRAINER_ANYA] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("ANYA"),
        .speechBefore = {EC_WORD_AS_IF, EC_WORD_WHOM, EC_WORD_LIKES, EC_WORD_WEREN_T, EC_WORD_FASHION, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_EARLIER, EC_WORD_WEREN_T, EC_WORD_PERSON, EC_WORD_LATER, EC_WORD_WEREN_T, EC_WORD_FASHION},
        .speechLose = {EC_WORD_WEREN_T, EC_WORD_CUTENESS, EC_WORD_IS, EC_WORD_LISTEN, EC_WORD_FASHION, EC_WORD_QUES},
        .monSet = gBattleFrontierTrainerMons_Anya
    },
    [FRONTIER_TRAINER_DAWN] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("RINA"),
        .speechBefore = {EC_WORD_GIVE, EC_WORD_LISTEN, EC_WORD_HERE, EC_WORD_NITWIT, EC_WORD_IF_I_WIN, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_BUT, EC_WORD_NOW, EC_WORD_AS_IF, EC_WORD_CONCEDE, EC_WORD_SAD, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_WILL, EC_WORD_WON, EC_WORD_LET_S, EC_WORD_EXCL, EC_WORD_NOW, EC_WORD_REFUSE},
        .monSet = gBattleFrontierTrainerMons_Dawn
    },
    [FRONTIER_TRAINER_ABBY] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("CINZIA"),
        .speechBefore = {EC_WORD_HEARING, EC_WORD_IS, EC_WORD_HOW, EC_WORD_TO, EC_MOVE2(REFRESH), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_OFF, EC_WORD_VICTORY, EC_WORD_HAVE, EC_WORD_A, EC_MOVE(SWEET_SCENT), EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_MISS, EC_WORD_STENCH, EC_WORD_OFF, EC_WORD_LOSS, EC_EMPTY_WORD, EC_EMPTY_WORD},
        .monSet = gBattleFrontierTrainerMons_Abby
    },
    [FRONTIER_TRAINER_GRETEL] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("ARIELLA"),
        .speechBefore = {EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_HEARING, EC_WORD_IS, EC_WORD_NATURAL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_IF_I_WIN, EC_WORD_IS, EC_WORD_NATURAL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NITWIT, EC_WORD_DON_T, EC_WORD_IF_I_LOSE, EC_WORD_IS, EC_WORD_NATURAL, EC_WORD_EXCL},
        .monSet = gBattleFrontierTrainerMons_Gretel
    }
};
