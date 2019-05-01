const struct BattleFrontierTrainer gBattleFrontierTrainers[] =
{
    [0] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("Brady"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NEVER, EC_WORD_GOING, EC_WORD_TO, EC_WORD_LOSE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_STRONG, EC_WORD_AREN_T, EC_WORD_I, EC_WORD_QUES, 0xFFFF},
        .speechLose = {EC_WORD_WHAT, EC_WORD_QUES, 0xFFFF, EC_WORD_BUT, EC_WORD_HOW, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Brady
    },
    [1] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("Conner"),
        .speechBefore = {EC_WORD_LOSING, EC_WORD_DOESN_T, EC_WORD_BUG, EC_WORD_ME, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_A, EC_WORD_WIN, EC_WORD_IS, EC_WORD_JUST, EC_WORD_AWESOME, 0xFFFF},
        .speechLose = {EC_WORD_DARN, EC_WORD_ELLIPSIS, EC_WORD_LOSING, EC_WORD_DOES, EC_WORD_BUG, EC_WORD_ME},
        .monSets = gBattleFrontierTrainerMons_Conner
    },
    [2] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("Bradley"),
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_EXCL, EC_WORD_YOU_RE, EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_TODAY},
        .speechWin = {EC_WORD_HAHAHA, EC_WORD_EXCL, 0xFFFF, EC_WORD_SEE_YA, EC_WORD_LATER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_TOMORROW, EC_WORD_IS, EC_WORD_WHEN, EC_WORD_WE, EC_WORD_REALLY, EC_WORD_BATTLE},
        .monSets = gBattleFrontierTrainerMons_Bradley
    },
    [3] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("Cybil"),
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_NOT_VERY, EC_WORD_SCARY, EC_WORD_AT, EC_WORD_ALL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SAD, EC_WORD_TO, EC_WORD_SEE, EC_WORD_YOU, EC_MOVE2(STRUGGLE)},
        .speechLose = {EC_WORD_THIS, EC_WORD_CAN_T, EC_WORD_BE, EC_WORD_HAPPENING, EC_WORD_TO_ME, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Cybil
    },
    [4] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("Rodette"),
        .speechBefore = {EC_WORD_OH, EC_WORD_THIS, EC_WORD_IS, EC_WORD_SO, EC_WORD_EXCITING, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_INCREDIBLE, EC_WORD_HOW, EC_WORD_STRONG, EC_WORD_I_AM, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OH_DEAR, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_NO, EC_WORD_GOOD},
        .monSets = gBattleFrontierTrainerMons_Rodette
    },
    [5] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("Peggy"),
        .speechBefore = {EC_WORD_GET, EC_WORD_READY, EC_WORD_TO, EC_WORD_BE, EC_WORD_DESTROYED, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HAHAHA, EC_WORD_EXCL_EXCL, 0xFFFF, EC_WORD_I_AM, EC_WORD_LOLLING, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_SAD, EC_WORD_THANKS, EC_WORD_TO, EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Peggy
    },
    [6] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("Keith"),
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_JUST, EC_WORD_STUDY, EC_WORD_YOU, EC_WORD_KNOW},
        .speechWin = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_STUDY, EC_WORD_ENOUGH, EC_WORD_ELLIPSIS, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_NEED, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_MORE, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Keith
    },
    [7] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("Grayson"),
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_BATTLE, EC_WORD_ISN_T, EC_WORD_CHILD_S_PLAY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_DONE, EC_WORD_AREN_T, EC_WORD_YOU, EC_WORD_QUES, 0xFFFF},
        .speechLose = {EC_WORD_WE, EC_WORD_WERE, EC_WORD_LIKE, EC_WORD_TOYS, EC_WORD_TO, EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Grayson
    },
    [8] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("Glenn"),
        .speechBefore = {EC_WORD_I, EC_WORD_WOULD, EC_WORD_BE, EC_WORD_COOL, EC_WORD_IF_I_WIN, 0xFFFF},
        .speechWin = {EC_WORD_COOL, EC_WORD_EXCL, 0xFFFF, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_GOING, EC_WORD_TO, EC_WORD_BE, EC_WORD_COOL},
        .monSets = gBattleFrontierTrainerMons_Glenn
    },
    [9] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("Liliana"),
        .speechBefore = {EC_WORD_I, EC_WORD_WON_T, EC_WORD_GIVE_UP, EC_WORD_UNTIL, EC_WORD_I, EC_WORD_WIN},
        .speechWin = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NO, EC_WORD_SURRENDER, EC_WORD_IN, EC_WORD_ME},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_IT, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_GIVE_UP, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Liliana
    },
    [10] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("Elise"),
        .speechBefore = {EC_WORD_MY, EC_WORD_STRATEGY, EC_WORD_IS, EC_WORD_FROM, EC_WORD_MY, EC_WORD_FATHER},
        .speechWin = {EC_WORD_I, EC_WORD_WIN, EC_WORD_EXCL, EC_WORD_FATHER, EC_WORD_I_VE, EC_WORD_WON},
        .speechLose = {EC_WORD_FORGIVE, EC_WORD_ME, EC_WORD_FATHER, EC_WORD_FOR, EC_WORD_I_VE, EC_WORD_LOST},
        .monSets = gBattleFrontierTrainerMons_Elise
    },
    [11] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("Zoey"),
        .speechBefore = {EC_WORD_PLEASE, EC_WORD_BATTLE, EC_WORD_LIKE, EC_WORD_YOU, EC_WORD_MEAN, EC_WORD_IT},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL_EXCL, 0xFFFF, EC_WORD_THANK_YOU, EC_WORD_SO, EC_WORD_MUCH},
        .speechLose = {EC_WORD_WERE, EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_BEING, EC_WORD_SERIOUS, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Zoey
    },
    [12] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("Manuel"),
        .speechBefore = {EC_WORD_ME, EC_WORD_LOSE, EC_WORD_QUES, EC_WORD_THAT_S, EC_WORD_PREPOSTEROUS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_NATURALLY, EC_WORD_I, EC_WORD_WIN, 0xFFFF, 0xFFFF, 0xFFFF},
        .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL, 0xFFFF, EC_WORD_I, EC_WORD_LOST, EC_WORD_MOTHER},
        .monSets = gBattleFrontierTrainerMons_Manuel
    },
    [13] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("Russ"),
        .speechBefore = {EC_WORD_THEY, EC_WORD_ALL, EC_WORD_WANT, EC_WORD_MY, EC_WORD_FABULOUS, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_I, EC_WORD_WILL, EC_WORD_HAVE, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_PARTY},
        .speechLose = {EC_WORD_HOW, EC_WORD_COULD, EC_WORD_YOU, EC_WORD_DO, EC_WORD_THAT, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Russ
    },
    [14] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("Dustin"),
        .speechBefore = {EC_WORD_I, EC_WORD_REALLY, EC_WORD_LIKE, EC_WORD_COOL, EC_WORD_POKEMON, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_MYSELF, EC_WORD_WHEN_I_WIN, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_MYSELF, EC_WORD_IF_I_LOSE, EC_WORD_TOO, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Dustin
    },
    [15] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("Tina"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_YOU, EC_WORD_CAN, EC_WORD_HAVE, EC_WORD_A, EC_MOVE2(SWEET_KISS)},
        .speechWin = {EC_WORD_HERE_IT_IS, EC_WORD_YOUR, EC_MOVE2(SWEET_KISS), EC_WORD_FROM, EC_WORD_MY, EC_POKEMON2(JYNX)},
        .speechLose = {EC_WORD_YOU, EC_WORD_WANT, EC_WORD_A, EC_MOVE(SWIFT), EC_MOVE2(MEGA_KICK), EC_WORD_INSTEAD},
        .monSets = gBattleFrontierTrainerMons_Tina
    },
    [16] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("Gillian"),
        .speechBefore = {EC_WORD_THE, EC_WORD_GOURMET, EC_WORD_THING, EC_WORD_IS, EC_WORD_SO, EC_WORD_YESTERDAY},
        .speechWin = {EC_WORD_POKEMON, EC_WORD_NEVER, EC_WORD_GO, EC_WORD_OUT, EC_WORD_OF, EC_WORD_FASHION},
        .speechLose = {EC_WORD_LOSING, EC_WORD_DOESN_T, EC_WORD_DISAPPOINT, EC_WORD_ME, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Gillian
    },
    [17] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("Zoe"),
        .speechBefore = {EC_WORD_I, EC_WORD_HAVEN_T, EC_WORD_A, EC_WORD_WORRY, EC_WORD_AT, EC_WORD_ALL},
        .speechWin = {EC_WORD_LIFE, EC_WORD_IS, EC_WORD_ALWAYS, EC_WORD_GOOD, EC_WORD_TO_ME, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_WORRY, EC_WORD_ABOUT, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_SKILL},
        .monSets = gBattleFrontierTrainerMons_Zoe
    },
    [18] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("Chen"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_TOTALLY, EC_WORD_READY, EC_WORD_TO, EC_WORD_ROCK, EC_WORD_TODAY},
        .speechWin = {EC_WORD_I_AM, EC_WORD_READY, EC_WORD_TO, EC_WORD_GO, EC_WORD_ON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_MY, EC_MOVE(FOCUS_ENERGY), EC_WORD_AND, EC_WORD_TOUGHNESS},
        .monSets = gBattleFrontierTrainerMons_Chen
    },
    [19] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("Al"),
        .speechBefore = {EC_WORD_YOUR, EC_WORD_LOOK, EC_WORD_SAYS, EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_TOUGH},
        .speechWin = {EC_WORD_IT_S, EC_WORD_ME, EC_WORD_WHO_IS, EC_WORD_REALLY, EC_WORD_TOUGH, 0xFFFF},
        .speechLose = {EC_WORD_I_AM, EC_WORD_RIGHT, EC_WORD_EXCL, EC_WORD_YOU_RE, EC_WORD_REALLY, EC_WORD_TOUGH},
        .monSets = gBattleFrontierTrainerMons_Al
    },
    [20] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("Mitch"),
        .speechBefore = {EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_IS, EC_WORD_MY, EC_WORD_ALLY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WAS, EC_WORD_THAT, EC_WORD_ENOUGH, EC_WORD_FOR, EC_WORD_YOU, EC_WORD_QUES},
        .speechLose = {EC_WORD_MOTHER, EC_WORD_NATURE, EC_WORD_DIDN_T, EC_WORD_LET_ME_WIN, EC_WORD_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Mitch
    },
    [21] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("Anne"),
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_LET_S, EC_WORD_BATTLE, EC_WORD_NOW},
        .speechWin = {EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_IS, EC_WORD_OVERWHELMING, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_DESTROYED, EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Anne
    },
    [22] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("Alize"),
        .speechBefore = {EC_WORD_CUTE, EC_WORD_AND, EC_WORD_AWFULLY, EC_WORD_STRONG, EC_WORD_THAT_S, EC_WORD_ME},
        .speechWin = {EC_WORD_YUP, EC_WORD_I_AM, EC_WORD_CUTE, EC_WORD_AND, EC_WORD_AWFULLY, EC_WORD_STRONG},
        .speechLose = {EC_WORD_I_AM, EC_WORD_WEAK, EC_WORD_ELLIPSIS, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_CUTE},
        .monSets = gBattleFrontierTrainerMons_Alize
    },
    [23] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("Lauren"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_OLD, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_ALSO, EC_WORD_GOOD},
        .speechWin = {EC_WORD_I, EC_WORD_SAID, EC_WORD_I_WAS, EC_WORD_OLD, EC_WORD_BUT, EC_WORD_GOOD},
        .speechLose = {EC_WORD_WHAT, EC_WORD_A, EC_WORD_WEIRD, EC_WORD_DREAM, EC_WORD_THAT_WAS, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Lauren
    },
    [24] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("Kipp"),
        .speechBefore = {EC_WORD_IF_I_WIN, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_GO, EC_MOVE2(SURF)},
        .speechWin = {EC_WORD_YEAH, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_OFF, EC_WORD_TO, EC_MOVE2(SURF)},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_EXCL, EC_WORD_A, EC_MOVE(WHIRLPOOL), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Kipp
    },
    [25] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("Jason"),
        .speechBefore = {EC_WORD_TEACH, EC_WORD_ME, EC_WORD_A, EC_WORD_GOOD, EC_WORD_STRATEGY, 0xFFFF},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_YOUR, EC_WORD_GOOD, EC_WORD_STRATEGY, EC_WORD_QUES_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_WOW, EC_WORD_THAT, EC_WORD_IS, EC_WORD_AN, EC_WORD_AWESOME, EC_WORD_STRATEGY},
        .monSets = gBattleFrontierTrainerMons_Jason
    },
    [26] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("John"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_PRETTY, EC_WORD_NEW, EC_WORD_TRAINER, 0xFFFF},
        .speechWin = {EC_WORD_I_AM, EC_WORD_NEW, EC_WORD_BUT, EC_WORD_I, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NEW, EC_WORD_SO, EC_WORD_WHAT, EC_WORD_IF_I_LOSE, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_John
    },
    [27] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("Ann"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_SO, EC_WORD_EXCITING, EC_WORD_IT, EC_WORD_REALLY, EC_WORD_IS},
        .speechWin = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_HAPPY, EC_WORD_I, EC_WORD_CAN, EC_WORD_CRY},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SAD, EC_WORD_I, EC_WORD_WILL, EC_WORD_CRY},
        .monSets = gBattleFrontierTrainerMons_Ann
    },
    [28] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("Eileen"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_PRETEND, EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_SO, EC_WORD_THIS, EC_WORD_IS, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_FEELING},
        .speechLose = {EC_WORD_AN, EC_WORD_ADULT, EC_WORD_CAN_T, EC_WORD_BEAT, EC_WORD_YOU, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Eileen
    },
    [29] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("Carlie"),
        .speechBefore = {EC_WORD_MY, EC_WORD_SUMMER, EC_WORD_VACATION, EC_WORD_IS, EC_WORD_FOR, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_MY, EC_WORD_SUMMER, EC_WORD_VACATION, EC_WORD_WILL, EC_WORD_BE, EC_WORD_AWESOME},
        .speechLose = {EC_WORD_I, EC_WORD_CAN_T_WIN, EC_WORD_LIKE, EC_WORD_THIS, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Carlie
    },
    [30] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("Gordon"),
        .speechBefore = {EC_WORD_VICTORY, EC_WORD_WILL, EC_WORD_COME, EC_WORD_TO_ME, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_OH_YEAH, EC_WORD_EXCL, 0xFFFF, EC_WORD_I, EC_WORD_REALLY, EC_WORD_WON},
        .speechLose = {EC_WORD_NOTHING, EC_WORD_IS, EC_WORD_WORKING, EC_WORD_OUT, EC_WORD_FOR, EC_WORD_ME},
        .monSets = gBattleFrontierTrainerMons_Gordon
    },
    [31] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("Ayden"),
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_WORD_HOT, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_I, EC_WORD_NEED, EC_WORD_WATER, EC_WORD_TO, EC_WORD_COOL, EC_WORD_DOWN},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_ME, EC_WORD_FEELING, EC_WORD_ICE, EC_WORD_COLD},
        .monSets = gBattleFrontierTrainerMons_Ayden
    },
    [32] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("Marco"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(SURF), EC_WORD_IN, EC_WORD_THE, EC_WORD_WINTER, EC_WORD_TOO},
        .speechWin = {EC_WORD_I, EC_WORD_WILL, EC_WORD_GO, EC_MOVE2(SURF), EC_WORD_RIGHT, EC_WORD_NOW},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_MOVE2(BEAT_UP), EC_WORD_MY, EC_MOVE2(SURF), EC_WORD_BOARD},
        .monSets = gBattleFrontierTrainerMons_Marco
    },
    [33] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("Cierra"),
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_SYNCHRONIZE, EC_WORD_MY, EC_WORD_SWIFT_SWIM},
        .speechWin = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_SYNCHRONIZE, EC_WORD_WITH, EC_WORD_ME, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_NEED, EC_WORD_TO, EC_WORD_SYNCHRONIZE, EC_WORD_BETTER, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Cierra
    },
    [34] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("Marcy"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_KNOCKOUT, EC_WORD_YOU, EC_WORD_CAN_T_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AFTER, EC_WORD_ALL, EC_WORD_I_AM, EC_WORD_A, EC_WORD_KNOCKOUT, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_NOT, EC_WORD_THE, EC_WORD_KNOCKOUT, EC_WORD_I, EC_WORD_MEAN},
        .monSets = gBattleFrontierTrainerMons_Marcy
    },
    [35] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("Kathy"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_WON, EC_WORD_EVERY, EC_WORD_MATCH, EC_WORD_TODAY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SO, EC_WORD_GREAT, EC_WORD_TO, EC_WORD_WIN, EC_WORD_EXCL},
        .speechLose = {EC_WORD_HUH_QUES, EC_WORD_I, EC_WORD_SHOULD, EC_WORD_NOT, EC_WORD_HAVE, EC_WORD_LOST},
        .monSets = gBattleFrontierTrainerMons_Kathy
    },
    [36] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("Peyton"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NEVER, EC_WORD_DISAPPOINTED, EC_WORD_WITH, EC_WORD_MY, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_IF, EC_WORD_WE, EC_WORD_WIN, EC_WORD_TOGETHER},
        .speechLose = {EC_WORD_I, EC_WORD_ADORE, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_MORE, EC_WORD_IF_I_LOSE},
        .monSets = gBattleFrontierTrainerMons_Peyton
    },
    [37] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("Julian"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_ADORE, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_RIGHT, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOTALLY, EC_WORD_OUT, EC_WORD_OF, EC_WORD_THE, EC_WORD_QUESTION},
        .speechLose = {EC_WORD_YOU, EC_WORD_DO, EC_WORD_ADORE, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Julian
    },
    [38] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("Quinn"),
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_BUT, EC_WORD_A, EC_WORD_DREAM},
        .speechWin = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_A, EC_WORD_BEAUTIFUL, EC_WORD_DREAM, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_AN, EC_WORD_AWFUL, EC_MOVE(NIGHTMARE), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Quinn
    },
    [39] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("Haylee"),
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_HOW, EC_WORD_I_AM, EC_WORD_FEELING},
        .speechWin = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_OVERWHELMING, EC_WORD_JOY, EC_WORD_OVER, EC_WORD_THIS},
        .speechLose = {EC_WORD_DESTROYED, EC_WORD_IS, EC_WORD_THE, EC_WORD_WAY, EC_WORD_I_AM, EC_WORD_FEELING},
        .monSets = gBattleFrontierTrainerMons_Haylee
    },
    [40] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("Amanda"),
        .speechBefore = {EC_WORD_I, EC_WORD_COME, EC_WORD_FROM, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_FAMILY},
        .speechWin = {EC_WORD_I, EC_WORD_WILL, EC_WORD_TREASURE, EC_WORD_THIS, EC_WORD_WIN, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_GO_HOME, EC_WORD_RIGHT, EC_WORD_NOW},
        .monSets = gBattleFrontierTrainerMons_Amanda
    },
    [41] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("Stacy"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_HAVE, EC_WORD_THEIR, EC_WORD_OWN, EC_WORD_CUTE_CHARM},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_WHAT, EC_WORD_I, EC_WORD_MEAN, EC_WORD_QUES},
        .speechLose = {EC_WORD_SHOULD, EC_WORD_I, EC_WORD_NOT, EC_WORD_ADORE, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Stacy
    },
    [42] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("Rafael"),
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_EXCL, EC_WORD_LET_S, EC_WORD_SEE, EC_WORD_SOME, EC_WORD_SPIRIT},
        .speechWin = {EC_WORD_THAT_S_IT_EXCL, EC_WORD_THAT_S, EC_WORD_THE, EC_WORD_SPIRIT, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_WELL, EC_WORD_SO, EC_WORD_MUCH, EC_WORD_FOR, EC_WORD_OUR, EC_WORD_SPIRIT},
        .monSets = gBattleFrontierTrainerMons_Rafael
    },
    [43] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("Oliver"),
        .speechBefore = {EC_WORD_A, EC_WORD_GENIUS, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_HOW, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_WORKS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MORE, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_THAN, EC_WORD_I_AM},
        .monSets = gBattleFrontierTrainerMons_Oliver
    },
    [44] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("Payton"),
        .speechBefore = {EC_WORD_I, EC_WORD_TRAIN, EC_WORD_FROM, EC_WORD_THE, EC_WORD_EGG, EC_WORD_UP},
        .speechWin = {EC_WORD_WELL, EC_WORD_DONE, EC_WORD_EXCL, 0xFFFF, 0xFFFF, 0xFFFF},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_A, EC_MOVE2(SOFT_BOILED), EC_WORD_LOSS, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Payton
    },
    [45] = {
        .facilityClass = FACILITY_CLASS_POKEMON_BREEDER_F,
        .trainerName = _("Pamela"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_POKEMON, EC_WORD_ADORE, EC_WORD_A, EC_WORD_KIND, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_IT_S, EC_WORD_TOO, EC_WORD_BAD, EC_WORD_YOU, EC_WORD_LOST, 0xFFFF},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_KIND, EC_WORD_AND, EC_WORD_YOU_RE, EC_WORD_ALSO, EC_WORD_STRONG},
        .monSets = gBattleFrontierTrainerMons_Pamela
    },
    [46] = {
        .facilityClass = FACILITY_CLASS_POKEMON_BREEDER_F,
        .trainerName = _("Eliza"),
        .speechBefore = {EC_WORD_I, EC_WORD_ADORE, EC_WORD_POKEMON, EC_WORD_LIKE, EC_WORD_MY, EC_WORD_CHILDREN},
        .speechWin = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_HAPPY, EC_WORD_FOR, EC_WORD_MY, EC_WORD_POKEMON},
        .speechLose = {EC_WORD_OH_DEAR, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_SORRY, EC_WORD_ABOUT, EC_WORD_THIS},
        .monSets = gBattleFrontierTrainerMons_Eliza
    },
    [47] = {
        .facilityClass = FACILITY_CLASS_POKEMON_BREEDER_F,
        .trainerName = _("Marisa"),
        .speechBefore = {EC_WORD_I, EC_WORD_PROMISE, EC_WORD_TO, EC_WORD_BATTLE, EC_WORD_SERIOUSLY, 0xFFFF},
        .speechWin = {EC_WORD_PROMISE, EC_WORD_ME, EC_WORD_YOU, EC_WORD_WILL, EC_WORD_DO, EC_WORD_BETTER},
        .speechLose = {EC_WORD_PROMISE, EC_WORD_ME, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_PLEASE, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Marisa
    },
    [48] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("Lewis"),
        .speechBefore = {EC_WORD_A_LITTLE, EC_WORD_BUG, EC_WORD_IS, EC_WORD_SCARY, EC_WORD_QUES, EC_WORD_HAHAHA},
        .speechWin = {EC_WORD_LOOK, EC_WORD_LOOK, EC_WORD_EXCL, EC_WORD_A, EC_WORD_SCARY, EC_WORD_BUG},
        .speechLose = {EC_WORD_OH, EC_WORD_A, EC_WORD_BUG, EC_WORD_ISN_T, EC_WORD_SCARY, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Lewis
    },
    [49] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("Yoshi"),
        .speechBefore = {EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_FEELING, EC_WORD_LOVEY_DOVEY},
        .speechWin = {EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_THE, EC_WORD_BEST, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_IGNORANT, EC_WORD_ABOUT, EC_WORD_BUG, EC_WORD_POKEMON, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Yoshi
    },
    [50] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("Destin"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_WAY, EC_WORD_TOO, EC_WORD_HOT, EC_WORD_HERE, 0xFFFF},
        .speechWin = {EC_WORD_I_AM, EC_WORD_ABOUT, EC_WORD_TO, EC_MOVE(OVERHEAT), 0xFFFF, 0xFFFF},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_I, EC_WORD_NEED, EC_WORD_SOME, EC_WORD_WATER, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Destin
    },
    [51] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("Keon"),
        .speechBefore = {EC_WORD_FORGIVE, EC_WORD_ME, EC_WORD_BUT, EC_WORD_HERE_I_COME, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_FORGIVE, EC_WORD_ME, EC_WORD_FOR, EC_WORD_MY, EC_WORD_OVERWHELMING, EC_WORD_POWER},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Keon
    },
    [52] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("Stuart"),
        .speechBefore = {EC_WORD_I, EC_WORD_PROMISE, EC_WORD_YOU, EC_WORD_A, EC_WORD_HOT, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_THE, EC_WORD_MASTER, EC_WORD_OF, EC_WORD_COOL, EC_WORD_THAT_S, EC_WORD_ME},
        .speechLose = {EC_WORD_I, EC_WORD_SEE, EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_SO, EC_WORD_COOL},
        .monSets = gBattleFrontierTrainerMons_Stuart
    },
    [53] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("Nestor"),
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_A, EC_WORD_REALLY, EC_WORD_SMOOTH, EC_WORD_MOVE},
        .speechWin = {EC_WORD_THERE, EC_WORD_WAS, EC_WORD_NOTHING, EC_WORD_SMOOTH, EC_WORD_ABOUT, EC_WORD_THAT},
        .speechLose = {EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_ARE, EC_WORD_SMOOTH, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Nestor
    },
    [54] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Derrick"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_SEE, EC_WORD_YOU, EC_MOVE2(MEDITATE), EC_WORD_LIKE, EC_WORD_ME},
        .speechWin = {EC_WORD_HOW, EC_WORD_I, EC_MOVE2(MEDITATE), EC_WORD_IS, EC_WORD_JUST, EC_WORD_BEAUTIFUL},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_MOVE2(MEDITATE), EC_WORD_FOR, EC_WORD_A, EC_MOVE2(CALM_MIND)},
        .monSets = gBattleFrontierTrainerMons_Derrick
    },
    [55] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Bryson"),
        .speechBefore = {EC_MOVE2(POISON_POWDER), EC_WORD_IS, EC_WORD_IN, EC_WORD_OUR, EC_MOVE2(COTTON_SPORE), EC_WORD_MOVE},
        .speechWin = {EC_WORD_HOW_DO, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_OUR, EC_MOVE2(POISON_POWDER), EC_WORD_QUES},
        .speechLose = {EC_WORD_MY, EC_MOVE2(COTTON_SPORE), EC_WORD_WAS, EC_WORD_USELESS, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Bryson
    },
    [56] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Clayton"),
        .speechBefore = {EC_WORD_HUH_QUES, 0xFFFF, 0xFFFF, EC_WORD_WHERE, EC_WORD_IS_IT_QUES, 0xFFFF},
        .speechWin = {EC_WORD_WHERE, EC_WORD_IS_IT_QUES, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_MY, EC_WORD_POKENAV},
        .speechLose = {EC_WORD_WHERE, EC_WORD_IS_IT_QUES, EC_WORD_I_VE, EC_WORD_LOST, EC_WORD_MY, EC_WORD_SENSE},
        .monSets = gBattleFrontierTrainerMons_Clayton
    },
    [57] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("Trenton"),
        .speechBefore = {EC_WORD_COME_OVER, EC_WORD_FOR, EC_WORD_SOME, EC_WORD_TASTY, EC_WORD_WATER, 0xFFFF},
        .speechWin = {EC_WORD_MMM, EC_WORD_DO, EC_WORD_YOU, EC_WORD_WANT, EC_WORD_SOME, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_GOT, EC_WORD_THIS, EC_WORD_TASTY, EC_WORD_WATER, EC_WORD_SHOPPING},
        .monSets = gBattleFrontierTrainerMons_Trenton
    },
    [58] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("Jenson"),
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_DOWNCAST},
        .speechWin = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_DON_T, EC_WORD_MAKE, EC_WORD_THE, EC_MOVE(CUT)},
        .speechLose = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_TRAINER, EC_WORD_WHO_IS, EC_WORD_FEELING, EC_WORD_DOWNCAST},
        .monSets = gBattleFrontierTrainerMons_Jenson
    },
    [59] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("Wesley"),
        .speechBefore = {EC_POKEMON2(MEW), EC_POKEMON2(MEW), EC_WORD_IS, EC_WORD_HOW, EC_WORD_I, EC_WORD_CRY},
        .speechWin = {EC_WORD_YES, EC_WORD_I, EC_WORD_KNOW, EC_WORD_I_AM, EC_WORD_CUTE, EC_WORD_EXCL},
        .speechLose = {EC_POKEMON2(MEW), EC_POKEMON2(MEW), EC_WORD_EXCL, EC_POKEMON2(MEW), EC_WORD_EXCL_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Wesley
    },
    [60] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Anton"),
        .speechBefore = {EC_WORD_GET, EC_WORD_READY, EC_WORD_FOR, EC_WORD_ME, EC_WORD_TO, EC_MOVE(THRASH)},
        .speechWin = {EC_WORD_WAHAHAHA, EC_WORD_EXCL, EC_WORD_SORRY, EC_WORD_ABOUT, EC_WORD_THAT, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_TOUGH, EC_WORD_LOSS, EC_WORD_TO, EC_MOVE2(SWALLOW)},
        .monSets = gBattleFrontierTrainerMons_Anton
    },
    [61] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Lawson"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_YOUNG, EC_WORD_AT, EC_WORD_HEART, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_NOT, EC_WORD_COOL, EC_WORD_EXCL, EC_WORD_NOT, EC_WORD_AT, EC_WORD_ALL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_OLD, EC_WORD_AND, EC_WORD_FEELING, EC_WORD_SHAKY, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Lawson
    },
    [62] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Sammy"),
        .speechBefore = {EC_WORD_MY, EC_WORD_PARTY, EC_WORD_IS, EC_WORD_READY, EC_WORD_TO, EC_WORD_ROCK},
        .speechWin = {EC_WORD_MY, EC_WORD_PARTY, EC_WORD_IS, EC_WORD_JUST, EC_WORD_INCREDIBLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_CRY, EC_WORD_FOR, EC_WORD_MY, EC_WORD_PARTY, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Sammy
    },
    [63] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Arnie"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NO_1, EC_WORD_I, EC_WORD_HAVE, EC_WORD_NO, EC_WORD_RIVAL},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_I, EC_WORD_CAN_T, EC_WORD_LOSE},
        .speechLose = {EC_WORD_NO, EC_WORD_EXCL, EC_WORD_I, EC_WORD_WON_T, EC_WORD_ACCEPT, EC_WORD_THIS},
        .monSets = gBattleFrontierTrainerMons_Arnie
    },
    [64] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Adrian"),
        .speechBefore = {EC_WORD_YAHOO, EC_WORD_EXCL, 0xFFFF, EC_WORD_YAHOO, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL, 0xFFFF, EC_WORD_THANK_YOU, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_GOOD_BYE, EC_WORD_EXCL, 0xFFFF, EC_WORD_GOOD_BYE, EC_WORD_EXCL_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Adrian
    },
    [65] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Tristan"),
        .speechBefore = {EC_WORD_CONFUSED, EC_WORD_QUES, 0xFFFF, EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS},
        .speechWin = {EC_WORD_SEE, EC_WORD_QUES, 0xFFFF, EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_IN, EC_WORD_BATTLE},
        .monSets = gBattleFrontierTrainerMons_Tristan
    },
    [66] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("Juliana"),
        .speechBefore = {EC_WORD_I, EC_WORD_THINK, EC_WORD_I_AM, EC_WORD_SHOPPING, EC_WORD_TOO, EC_WORD_MUCH},
        .speechWin = {EC_WORD_BUT, EC_WORD_I, EC_WORD_WANT, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_PLUSH_DOLL},
        .speechLose = {EC_WORD_I, EC_WORD_SO, EC_WORD_WANT, EC_WORD_ANOTHER, EC_WORD_POKEMON, EC_WORD_PLUSH_DOLL},
        .monSets = gBattleFrontierTrainerMons_Juliana
    },
    [67] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("Rylee"),
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_THAT, EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_GUTS},
        .speechWin = {EC_WORD_BYE_BYE, EC_WORD_EXCL, EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_NO, EC_WORD_GUTS},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_GUTSY, EC_WORD_ELLIPSIS, EC_WORD_YOU_RE, EC_WORD_QUITE, EC_WORD_SUPER},
        .monSets = gBattleFrontierTrainerMons_Rylee
    },
    [68] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("Chelsea"),
        .speechBefore = {EC_WORD_I, EC_WORD_SERIOUSLY, EC_WORD_MEAN, EC_WORD_TO, EC_WORD_WIN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_MY, EC_WORD_WILL, EC_WORD_TO, EC_WORD_WIN, 0xFFFF},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_FAR, EC_WORD_TOO_STRONG, EC_WORD_FOR, EC_WORD_ME, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Chelsea
    },
    [69] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("Danela"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_MUST_BE, EC_WORD_MY, EC_WORD_OPPONENT, EC_WORD_NOW, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OH_DEAR, EC_WORD_TOO_WEAK, EC_WORD_EXCL, EC_WORD_DON_T, EC_WORD_GIVE_UP, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_GOOD, EC_WORD_AND, EC_WORD_THIS, EC_WORD_IS, EC_WORD_GOOD_BYE},
        .monSets = gBattleFrontierTrainerMons_Danela
    },
    [70] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("Lizbeth"),
        .speechBefore = {EC_WORD_IF_I_LOSE, EC_WORD_YOU, EC_WORD_CAN, EC_WORD_HAVE, EC_WORD_A, EC_MOVE2(PRESENT)},
        .speechWin = {EC_WORD_HERE_IT_IS, EC_WORD_A_LITTLE, EC_WORD_PRAISE, EC_WORD_AS, EC_WORD_YOUR, EC_MOVE2(PRESENT)},
        .speechLose = {EC_WORD_YOUR, EC_MOVE2(PRESENT), EC_WORD_QUES_EXCL, EC_WORD_HERE_IT_IS, EC_WORD_A, EC_MOVE(DOUBLE_SLAP)},
        .monSets = gBattleFrontierTrainerMons_Lizbeth
    },
    [71] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("Amelia"),
        .speechBefore = {EC_WORD_I, EC_WORD_BELIEVE, EC_WORD_IN, EC_WORD_CUTE, EC_WORD_FASHION, EC_WORD_APPEAL},
        .speechWin = {EC_WORD_YOUR, EC_WORD_FASHION, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_A, EC_WORD_DISASTER},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_AWFUL, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_HOME},
        .monSets = gBattleFrontierTrainerMons_Amelia
    },
    [72] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("Jillian"),
        .speechBefore = {EC_WORD_WHAT, EC_WORD_IS, EC_WORD_THAT, EC_WORD_I, EC_WORD_SMELL, EC_WORD_QUES},
        .speechWin = {EC_WORD_IT_S, EC_WORD_THE, EC_MOVE(SWEET_SCENT), EC_WORD_OF, EC_WORD_TASTY, EC_WORD_WATER},
        .speechLose = {EC_WORD_IT_S, EC_WORD_YOUR, EC_WORD_OFFENSIVE, EC_WORD_STENCH, EC_WORD_THAT_S, EC_WORD_WHAT},
        .monSets = gBattleFrontierTrainerMons_Jillian
    },
    [73] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("Abbie"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_TRY, EC_WORD_MY, EC_WORD_SECRET, EC_MOVE(AROMATHERAPY), EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_MY, EC_MOVE(AROMATHERAPY), EC_WORD_IS, EC_WORD_TERRIBLE, EC_WORD_FOR, EC_WORD_YOU},
        .speechLose = {EC_WORD_DIDN_T, EC_WORD_YOU, EC_WORD_SMELL, EC_WORD_A, EC_WORD_THING, EC_WORD_QUES_EXCL},
        .monSets = gBattleFrontierTrainerMons_Abbie
    },
    [74] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("Briana"),
        .speechBefore = {EC_WORD_MY, EC_WORD_BOY, EC_WORD_FRIEND, EC_WORD_WORKS, EC_WORD_TOO, EC_WORD_MUCH},
        .speechWin = {EC_WORD_I, EC_WORD_ONLY, EC_WORD_MISS, EC_WORD_HIM, EC_WORD_MORE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SO, EC_WORD_LONESOME, EC_WORD_WITHOUT, EC_WORD_HIM, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Briana
    },
    [75] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("Antonio"),
        .speechBefore = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_HOW, EC_WORD_TO, EC_WORD_GO, EC_WORD_GO},
        .speechWin = {EC_WORD_BUT, EC_WORD_I, EC_WORD_DON_T, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_DANCE},
        .speechLose = {EC_WORD_GO, EC_WORD_GO, EC_WORD_ELLIPSIS, EC_WORD_JUST, EC_MOVE(FLAIL), EC_WORD_ABOUT},
        .monSets = gBattleFrontierTrainerMons_Antonio
    },
    [76] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("Jaden"),
        .speechBefore = {EC_WORD_HELLO, EC_WORD_I, EC_WORD_THINK, EC_WORD_I, EC_WORD_ADORE, EC_WORD_YOU},
        .speechWin = {EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_ME, EC_MOVE(THRASH), EC_WORD_IN, EC_MOVE2(FRUSTRATION)},
        .speechLose = {EC_WORD_THIS_IS_IT_EXCL, 0xFFFF, 0xFFFF, EC_WORD_GOOD_BYE, EC_WORD_FOREVER, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Jaden
    },
    [77] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("Dakota"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_DANCE, EC_WORD_WITH, EC_WORD_POWER},
        .speechWin = {EC_WORD_GOT, EC_WORD_IT, EC_WORD_QUES, EC_WORD_DANCE, EC_WORD_WITH, EC_WORD_POWER},
        .speechLose = {EC_WORD_OKAY, EC_WORD_YOU, EC_WORD_UNDERSTAND, EC_WORD_ALL_RIGHT, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Dakota
    },
    [78] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("Brayden"),
        .speechBefore = {EC_WORD_COLOR_CHANGE, EC_WORD_VERSION, EC_WORD_TOYS, EC_WORD_ARE, EC_WORD_USELESS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_ONLY, EC_WORD_COLLECT, EC_WORD_NORMAL, EC_WORD_VERSION, EC_WORD_TOYS},
        .speechLose = {EC_WORD_I, EC_MOVE2(ATTRACT), EC_WORD_COLOR_CHANGE, EC_WORD_VERSION, EC_WORD_TOYS, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Brayden
    },
    [79] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("Corson"),
        .speechBefore = {EC_WORD_I, EC_WORD_GET, EC_WORD_TO, EC_MOVE2(BEAT_UP), EC_WORD_ON, EC_WORD_YOU},
        .speechWin = {EC_WORD_TOO, EC_WORD_EASY, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_COOL},
        .speechLose = {EC_WORD_WHY, EC_WORD_QUES_EXCL, 0xFFFF, EC_WORD_I, EC_MOVE2(CURSE), EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Corson
    },
    [80] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("Trevin"),
        .speechBefore = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NONE, EC_WORD_BETTER, EC_WORD_THAN, EC_WORD_ME},
        .speechWin = {EC_WORD_YES_SIR_EXCL, 0xFFFF, 0xFFFF, EC_WORD_I_AM, EC_WORD_THE, EC_WORD_BEST},
        .speechLose = {EC_WORD_SERIOUS, EC_WORD_QUES_EXCL, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Trevin
    },
    [81] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("Patrick"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_PERFECT, EC_WORD_EXCL, EC_WORD_GIVE_UP, EC_WORD_NOW, 0xFFFF},
        .speechWin = {EC_WORD_DON_T, EC_WORD_BE, EC_WORD_DISAPPOINTED, EC_WORD_I_AM, EC_WORD_PERFECT, 0xFFFF},
        .speechLose = {EC_WORD_BUT, EC_WORD_HOW, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_PERFECT, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Patrick
    },
    [82] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("Kaden"),
        .speechBefore = {EC_WORD_WHAT, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_UP, EC_WORD_TO, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_WERE, EC_WORD_A, EC_WORD_SURPRISE, EC_WORD_TO_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_WHO, EC_WORD_I_AM, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Kaden
    },
    [83] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("Maxwell"),
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_WHO_IS, EC_WORD_YOUR, EC_WORD_RIVAL, EC_WORD_QUES, 0xFFFF},
        .speechWin = {EC_WORD_MY, EC_WORD_RIVAL, EC_WORD_IS, EC_WORD_MY, EC_WORD_GIRL, EC_WORD_FRIEND},
        .speechLose = {EC_WORD_I_AM, EC_WORD_MAKING, EC_WORD_YOU, EC_WORD_MY, EC_WORD_RIVAL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Maxwell
    },
    [84] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("Daryl"),
        .speechBefore = {EC_WORD_I, EC_WORD_ONLY, EC_WORD_KNOW, EC_WORD_HOW, EC_WORD_TO, EC_MOVE(CHARGE)},
        .speechWin = {EC_WORD_AM, EC_WORD_I, EC_WORD_OVERWHELMING, EC_WORD_OR, EC_WORD_WHAT, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_GOING, EC_WORD_TO, EC_WORD_A, EC_WORD_LEGEND, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Daryl
    },
    [85] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("Kenneth"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_BETTER, EC_WORD_NOT, EC_MOVE2(SLACK_OFF), EC_WORD_WITH, EC_WORD_ME},
        .speechWin = {EC_WORD_DID, EC_WORD_MY, EC_MOVE2(TAUNT), EC_WORD_INTIMIDATE, EC_WORD_YOU, EC_WORD_QUES},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Kenneth
    },
    [86] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("Rich"),
        .speechBefore = {EC_WORD_YOUR, EC_MOVE(FACADE), EC_WORD_DOESN_T, EC_MOVE2(TRICK), EC_WORD_ME, 0xFFFF},
        .speechWin = {EC_WORD_SERIOUSLY, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_OK_QUES, 0xFFFF},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_REALLY, EC_WORD_TOUGH, EC_WORD_ON, EC_WORD_ME, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Rich
    },
    [87] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("Caden"),
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_BE, EC_WORD_DEFEATED, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_FIRE, EC_WORD_EXCL, 0xFFFF, EC_WORD_FIRE, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_SO, EC_WORD_HOT},
        .monSets = gBattleFrontierTrainerMons_Caden
    },
    [88] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("Marlon"),
        .speechBefore = {EC_WORD_A, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_A_LITTLE, EC_WORD_RADIO, EC_WORD_QUES},
        .speechWin = {EC_WORD_A_LITTLE, EC_WORD_RADIO, EC_WORD_HUH_QUES, EC_WORD_THAT_S, EC_WORD_TOTALLY, EC_WORD_COOL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_QUES, EC_WORD_IS, EC_WORD_POKENAV, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Marlon
    },
    [89] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("Nash"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ON, EC_WORD_FIRE, EC_WORD_BABY, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_WORD_LEFT, EC_WORD_YOU, EC_WORD_JUST, EC_WORD_AN, EC_MOVE2(EMBER)},
        .speechLose = {EC_WORD_AIYEEH, EC_WORD_EXCL_EXCL, 0xFFFF, EC_WORD_NO, EC_WORD_WATER, EC_WORD_PLEASE},
        .monSets = gBattleFrontierTrainerMons_Nash
    },
    [90] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("Robby"),
        .speechBefore = {EC_WORD_HAHAHA, EC_WORD_EXCL, EC_WORD_HAPPY, EC_WORD_TO, EC_WORD_MEET_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_LEADER, EC_WORD_WITH, EC_WORD_REFRESHING, EC_WORD_SERENE_GRACE},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_MOVE(THRASH), EC_WORD_MY, EC_WORD_TOYS, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Robby
    },
    [91] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("Reece"),
        .speechBefore = {EC_WORD_MY, EC_MOVE2(QUICK_ATTACK), EC_WORD_CAN, EC_WORD_BEAT, EC_WORD_A, EC_MOVE2(TELEPORT)},
        .speechWin = {EC_WORD_LIKE, EC_WORD_I, EC_WORD_SAID, EC_WORD_I_AM, EC_WORD_DARN, EC_WORD_FAST},
        .speechLose = {EC_WORD_I_WAS, EC_WORD_KIDDING, EC_WORD_ABOUT, EC_WORD_THAT, EC_MOVE2(TELEPORT), EC_WORD_THING},
        .monSets = gBattleFrontierTrainerMons_Reece
    },
    [92] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("Kathryn"),
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_TRAIN, EC_WORD_GOOD, EC_WORD_ENOUGH, EC_WORD_QUES},
        .speechWin = {EC_WORD_DON_T, EC_MOVE2(TAUNT), EC_WORD_ME, EC_WORD_LIKE, EC_WORD_THAT, EC_WORD_OK_QUES},
        .speechLose = {EC_WORD_WHY, EC_WORD_COULDN_T, EC_WORD_I, EC_WORD_WIN, EC_WORD_THIS, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Kathryn
    },
    [93] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("Ellen"),
        .speechBefore = {EC_WORD_CRUSH, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_AN, EC_WORD_EGG, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_A, EC_WORD_TASTY, EC_WORD_VICTORY, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_TOO, EC_WORD_TOUGH, EC_WORD_TO, EC_WORD_CRUSH, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Ellen
    },
    [94] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("Ramon"),
        .speechBefore = {EC_WORD_OKAY, EC_WORD_EXCL, 0xFFFF, EC_WORD_THIS, EC_WORD_IS, EC_WORD_PERFECTION},
        .speechWin = {EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_THAT, EC_WORD_I, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_SECRET, EC_WORD_WHY, EC_WORD_I_AM, EC_WORD_HAPPY},
        .monSets = gBattleFrontierTrainerMons_Ramon
    },
    [95] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("Arthur"),
        .speechBefore = {EC_WORD_HERE_I_COME, EC_WORD_FEELING, EC_WORD_READY, EC_WORD_FOR, EC_WORD_IT, EC_WORD_ALL},
        .speechWin = {EC_WORD_THAT_S_IT_EXCL, 0xFFFF, 0xFFFF, EC_WORD_THAT_WAS, EC_WORD_FABULOUS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_NOT, EC_WORD_WHAT, EC_WORD_I, EC_WORD_NEED, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Arthur
    },
    [96] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("Alondra"),
        .speechBefore = {EC_WORD_EVERY, EC_WORD_DAY, EC_WORD_IS, EC_WORD_A, EC_WORD_GREAT, EC_WORD_DAY},
        .speechWin = {EC_WORD_MY, EC_MOVE2(DIVE), EC_WORD_WILL, EC_WORD_BE, EC_WORD_A, EC_WORD_LEGEND},
        .speechLose = {EC_WORD_MY, EC_MOVE2(DIVE), EC_WORD_LEFT, EC_WORD_ME, EC_WORD_COLD, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Alondra
    },
    [97] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("Adriana"),
        .speechBefore = {EC_WORD_COME, EC_WORD_SEE, EC_WORD_AN, EC_WORD_INCREDIBLE, EC_WORD_SWIFT_SWIM, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_MAKE, EC_WORD_IT, EC_WORD_LOOK, EC_WORD_SO, EC_WORD_EASY},
        .speechLose = {EC_WORD_I_AM, EC_WORD_FEELING, EC_MOVE2(BEAT_UP), EC_WORD_AND, EC_WORD_TIRED, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Adriana
    },
    [98] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("Malik"),
        .speechBefore = {EC_WORD_OH, EC_WORD_NOT, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_PLEASE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_I, EC_WORD_FINALLY, EC_WORD_WON, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_TIRED},
        .speechLose = {EC_WORD_I, EC_WORD_FINALLY, EC_WORD_LOST, EC_WORD_ELLIPSIS, EC_WORD_I_AM, EC_WORD_TIRED},
        .monSets = gBattleFrontierTrainerMons_Malik
    },
    [99] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("Jill"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_MOVE2(QUICK_ATTACK), EC_WORD_TRAINER, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_THE, EC_MOVE2(QUICK_ATTACK), EC_WORD_TRAINER, EC_WORD_WINS, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_THE, EC_MOVE2(QUICK_ATTACK), EC_WORD_TRAINER, EC_WORD_GIVES, EC_WORD_UP, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Jill
    },
    [100] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("Erik"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_SPEED_BOOST, EC_WORD_HERO, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_FROM, EC_WORD_THE, EC_WORD_SPEED_BOOST, EC_WORD_HERO, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WAAAH, EC_WORD_EXCL_EXCL, 0xFFFF, EC_WORD_NO, EC_WORD_NO, EC_WORD_EXCL_EXCL},
        .monSets = gBattleFrontierTrainerMons_Erik
    },
    [101] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("Yazmin"),
        .speechBefore = {EC_WORD_I, EC_WORD_WOULD, EC_WORD_RATHER, EC_WORD_RUN, EC_WORD_THAN, EC_WORD_BIKE},
        .speechWin = {EC_WORD_YES, EC_WORD_I, EC_WORD_WOULD, EC_WORD_MUCH, EC_WORD_RATHER, EC_WORD_RUN},
        .speechLose = {EC_WORD_BYE_BYE, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_RUN_AWAY},
        .monSets = gBattleFrontierTrainerMons_Yazmin
    },
    [102] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("Jamal"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_BE, EC_WORD_A, EC_WORD_FATHER},
        .speechWin = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_FOR, EC_WORD_MY, EC_WORD_BABY},
        .speechLose = {EC_WORD_MY, EC_WORD_BABY, EC_WORD_WILL, EC_WORD_BE, EC_WORD_TOTALLY, EC_WORD_AWESOME},
        .monSets = gBattleFrontierTrainerMons_Jamal
    },
    [103] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("Leslie"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_BE, EC_WORD_A, EC_WORD_MOTHER},
        .speechWin = {EC_WORD_A, EC_WORD_BABY, EC_WORD_WILL, EC_WORD_BE, EC_WORD_A_LITTLE, EC_WORD_CHALLENGE},
        .speechLose = {EC_WORD_I_AM, EC_WORD_TOO, EC_WORD_HAPPY, EC_WORD_TO, EC_WORD_BE, EC_WORD_ANGRY},
        .monSets = gBattleFrontierTrainerMons_Leslie
    },
    [104] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("Dave"),
        .speechBefore = {EC_WORD_WHAT, EC_WORD_SHOULD, EC_WORD_I, EC_WORD_DO, EC_WORD_TODAY, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_SHOULD, EC_WORD_ENJOY, EC_WORD_SOME, EC_WORD_SPORTS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_GO, EC_WORD_PLAY, EC_WORD_A, EC_WORD_GAME},
        .monSets = gBattleFrontierTrainerMons_Dave
    },
    [105] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("Carlo"),
        .speechBefore = {EC_WORD_HAH, EC_WORD_EXCL_EXCL, 0xFFFF, EC_WORD_YEAH, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_WORD_DO, EC_WORD_THINGS, EC_WORD_AT, EC_MOVE(EXTREME_SPEED), EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_LOST, EC_WORD_AT, EC_MOVE(EXTREME_SPEED), EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Carlo
    },
    [106] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("Emilia"),
        .speechBefore = {EC_WORD_ME, EC_WORD_WORRY, EC_WORD_QUES, EC_WORD_I, EC_WORD_HAVE, EC_WORD_NONE},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_THAT_WAS, EC_WORD_FANTASTIC, EC_WORD_EXCL},
        .speechLose = {EC_WORD_AHAHA, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_THAT_WAS, EC_WORD_ENTERTAINING, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Emilia
    },
    [107] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("Dalia"),
        .speechBefore = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_VERY, EC_WORD_EXPENSIVE, 0xFFFF},
        .speechWin = {EC_WORD_DON_T, EC_WORD_COME, EC_WORD_NEAR, EC_WORD_MY, EC_WORD_BIKE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MY, EC_WORD_BIKE, EC_WORD_IS, EC_WORD_MY, EC_WORD_BEST, EC_WORD_FRIEND},
        .monSets = gBattleFrontierTrainerMons_Dalia
    },
    [108] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("Hitomi"),
        .speechBefore = {EC_WORD_YEAH, EC_WORD_EXCL_EXCL, 0xFFFF, EC_WORD_HAH, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_WHAT, EC_WORD_QUES_EXCL, 0xFFFF, EC_WORD_I, EC_WORD_WON, EC_WORD_QUES_EXCL},
        .speechLose = {EC_WORD_AIYEEH, EC_WORD_EXCL_EXCL, 0xFFFF, EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_EXCL_EXCL},
        .monSets = gBattleFrontierTrainerMons_Hitomi
    },
    [109] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("Ricardo"),
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_EXCL, EC_WORD_PLAY, EC_WORD_TIME, EC_WORD_IS, EC_WORD_OVER},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_OUT, EC_WORD_OF, EC_WORD_HERE, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_DON_T, EC_WORD_HIT, EC_WORD_ME, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Ricardo
    },
    [110] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("Shizuka"),
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_THAT, EC_WORD_YOU_RE, EC_WORD_SERIOUS, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_WON_T, EC_WORD_FORGET, EC_WORD_ABOUT, EC_WORD_YOU, 0xFFFF},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_PERFECT, EC_WORD_IN, EC_WORD_EVERY, EC_WORD_WAY, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Shizuka
    },
    [111] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("Joana"),
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_GOING, EC_WORD_TO, EC_WORD_LOSE, EC_WORD_RIGHT, EC_WORD_AWAY},
        .speechWin = {EC_WORD_I_AM, EC_WORD_THE, EC_WORD_WINNER, EC_WORD_HEAR, EC_WORD_ME, EC_MOVE2(ROAR)},
        .speechLose = {EC_WORD_I, EC_WORD_REFUSE, EC_WORD_TO, EC_WORD_ACCEPT, EC_WORD_THAT, EC_MOVE(OUTRAGE)},
        .monSets = gBattleFrontierTrainerMons_Joana
    },
    [112] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("Kelly"),
        .speechBefore = {EC_WORD_MY, EC_WORD_NIGHT, EC_WORD_SCHOOL, EC_WORD_IS, EC_WORD_REALLY, EC_WORD_SCARY},
        .speechWin = {EC_WORD_A, EC_WORD_LADY, EC_WORD_GHOST, EC_WORD_APPEARS, EC_WORD_THERE, 0xFFFF},
        .speechLose = {EC_WORD_THE, EC_WORD_HOME, EC_WORD_WORK, EC_WORD_IS, EC_WORD_AWFULLY, EC_WORD_SCARY},
        .monSets = gBattleFrontierTrainerMons_Kelly
    },
    [113] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("Rayna"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NO_1, EC_WORD_WHEN, EC_WORD_IT_S, EC_WORD_ABOUT, EC_WORD_POWER},
        .speechWin = {EC_WORD_UNDERSTAND, EC_WORD_MY, EC_WORD_POWER, EC_WORD_NOW, EC_WORD_QUES, 0xFFFF},
        .speechLose = {EC_WORD_TERRIBLE, EC_WORD_ELLIPSIS, 0xFFFF, EC_WORD_I_AM, EC_WORD_TERRIBLE, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Rayna
    },
    [114] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("Evan"),
        .speechBefore = {EC_WORD_EVERY, EC_WORD_BATTLE, EC_WORD_HAS, EC_WORD_A, EC_WORD_SMELL, 0xFFFF},
        .speechWin = {EC_WORD_OH, EC_WORD_EXCL, EC_WORD_THE, EC_MOVE(SWEET_SCENT), EC_WORD_OF, EC_WORD_VICTORY},
        .speechLose = {EC_WORD_THE, EC_WORD_AWFUL, EC_WORD_STENCH, EC_WORD_OF, EC_WORD_A, EC_WORD_LOSS},
        .monSets = gBattleFrontierTrainerMons_Evan
    },
    [115] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("Jordan"),
        .speechBefore = {EC_WORD_GOOD, EC_WORD_EXCL, 0xFFFF, EC_WORD_COME_ON, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_BEAT, EC_WORD_ME, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_WHAT, EC_WORD_QUES_EXCL, 0xFFFF, EC_WORD_BUT, EC_WORD_HOW, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Jordan
    },
    [116] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("Joel"),
        .speechBefore = {EC_WORD_FUFUFU, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
        .speechLose = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Joel
    },
    [117] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("Kristen"),
        .speechBefore = {EC_WORD_HAHAHA, EC_WORD_ELLIPSIS, 0xFFFF, EC_WORD_A, EC_WORD_KID, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_JUST, EC_WORD_A_LITTLE, EC_WORD_KID, EC_WORD_AFTER, EC_WORD_ALL, EC_WORD_EXCL},
        .speechLose = {EC_WORD_A, EC_WORD_TOUGH, EC_WORD_KID, EC_WORD_HUH_QUES, EC_WORD_HUMPH, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Kristen
    },
    [118] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("Selphy"),
        .speechBefore = {EC_WORD_HUH_QUES, EC_WORD_WHAT, EC_WORD_IS_IT_QUES, 0xFFFF, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_OH, EC_WORD_YES, EC_WORD_EXCL, EC_WORD_WHY, EC_WORD_NOT, EC_WORD_QUES},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_EXCL, EC_WORD_WHY, EC_WORD_NOT, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Selphy
    },
    [119] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("Chloe"),
        .speechBefore = {EC_WORD_COME, EC_WORD_WE, EC_WORD_WILL, EC_WORD_DO, EC_WORD_BATTLE, EC_WORD_NOW},
        .speechWin = {EC_WORD_MORE, EC_WORD_EXCL, 0xFFFF, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_OH, EC_WORD_EXCL, 0xFFFF, EC_WORD_STRONG, EC_WORD_YOU, EC_WORD_ARE},
        .monSets = gBattleFrontierTrainerMons_Chloe
    },
    [120] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("Norton"),
        .speechBefore = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_ONLY, EC_WORD_YOU, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_EXCUSE_ME, EC_WORD_BUT, EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_PUSHOVER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_SOME, EC_WORD_KIND, EC_WORD_OF, EC_WORD_AWESOME, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Norton
    },
    [121] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("Lukas"),
        .speechBefore = {EC_WORD_MY, EC_WORD_JOKING, EC_WORD_IS, EC_WORD_PRETTY, EC_WORD_TERRIBLE, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_YOUR, EC_WORD_ROCK_HEAD, EC_WORD_EXISTS, EC_WORD_TO, EC_WORD_SHINE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOUR, EC_WORD_ROCK_HEAD, EC_WORD_COME, EC_WORD_TO, EC_WORD_SHINE, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Lukas
    },
    [122] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("Zach"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_EXCELLENT, EC_MOVE2(MIMIC), EC_WORD_OF, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_LIKE, EC_WORD_A_LITTLE, EC_POKEMON2(TOGEPI), EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ANGRY, EC_WORD_LIKE, EC_WORD_A, EC_POKEMON2(MANKEY), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Zach
    },
    [123] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("Kaitlyn"),
        .speechBefore = {EC_WORD_I, EC_WORD_CRUSH, EC_WORD_THINGS, EC_WORD_WITH, EC_WORD_PSYCHIC, EC_WORD_POWER},
        .speechWin = {EC_WORD_MY, EC_WORD_VICTORY, EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_THE, EC_WORD_NEWS},
        .speechLose = {EC_WORD_NO, EC_WORD_NO, EC_WORD_ELLIPSIS, EC_WORD_THIS, EC_WORD_WON_T, EC_WORD_DO},
        .monSets = gBattleFrontierTrainerMons_Kaitlyn
    },
    [124] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("Breanna"),
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_WILL, EC_WORD_CRUSH, EC_WORD_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HAVE, EC_WORD_SOME, EC_WORD_MORE, EC_WORD_OF, EC_WORD_THIS, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_GUTS, EC_WORD_AND, EC_WORD_SKILL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Breanna
    },
    [125] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("Kendra"),
        .speechBefore = {EC_WORD_IF, EC_WORD_YOU_RE, EC_WORD_SMART, EC_WORD_STOP, EC_WORD_RIGHT, EC_WORD_NOW},
        .speechWin = {EC_WORD_I, EC_WORD_SAID, EC_WORD_THAT, EC_WORD_YOU, EC_WORD_SHOULD, EC_WORD_STOP},
        .speechLose = {EC_WORD_WHY, EC_WORD_DIDN_T, EC_WORD_YOU, EC_WORD_STOP, EC_WORD_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Kendra
    },
    [126] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("Molly"),
        .speechBefore = {EC_WORD_WILL, EC_WORD_MY, EC_WORD_CUTE_CHARM, EC_MOVE2(ATTRACT), EC_WORD_YOU, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_MY, EC_WORD_TOYS, EC_WORD_NOW},
        .speechLose = {EC_WORD_OH, EC_WORD_HOW, EC_WORD_COULD, EC_WORD_YOU, EC_WORD_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Molly
    },
    [127] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("Jazmin"),
        .speechBefore = {EC_WORD_I, EC_WORD_FORECAST, EC_WORD_TERRIBLE, EC_WORD_THINGS, EC_WORD_FOR, EC_WORD_YOU},
        .speechWin = {EC_WORD_THERE, EC_WORD_WASN_T, EC_WORD_MY, EC_WORD_FORECAST, EC_WORD_RIGHT, EC_WORD_QUES},
        .speechLose = {EC_WORD_MY, EC_MOVE2(FORESIGHT), EC_WORD_DIDN_T, EC_WORD_SHOW, EC_WORD_ME, EC_WORD_THIS},
        .monSets = gBattleFrontierTrainerMons_Jazmin
    },
    [128] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("Kelsey"),
        .speechBefore = {EC_WORD_I, EC_WORD_HAVEN_T, EC_WORD_SLEPT, EC_WORD_IN, EC_WORD_DAYS, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_MY, EC_WORD_SLEEP, EC_WORD_WILL, EC_WORD_BE, EC_WORD_EXCELLENT, EC_WORD_NOW},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_DESTROYED, EC_WORD_MY, EC_WORD_SLEEP, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Kelsey
    },
    [129] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("Jalen"),
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_ALLOW, EC_WORD_POKEMON, EC_WORD_TO, EC_MOVE(THRASH)},
        .speechWin = {EC_WORD_HAHAHA, EC_WORD_EXCL, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_ANGRY, EC_WORD_QUES},
        .speechLose = {EC_WORD_WHY, EC_WORD_IS, EC_WORD_THIS, EC_WORD_SO, EC_WORD_HARD, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Jalen
    },
    [130] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("Griffen"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(SWALLOW), EC_MOVE2(SLUDGE), EC_WORD_TO, EC_MOVE2(TRANSFORM), EC_WORD_MYSELF},
        .speechWin = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_A, EC_MOVE(GROWTH), EC_WORD_OF, EC_MOVE2(ACID_ARMOR)},
        .speechLose = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_A, EC_MOVE(GROWTH), EC_WORD_OF, EC_WORD_SUCTION_CUPS},
        .monSets = gBattleFrontierTrainerMons_Griffen
    },
    [131] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("Xander"),
        .speechBefore = {EC_WORD_I, EC_WORD_GOT, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ON, EC_WORD_RENTAL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_INCREDIBLE, EC_WORD_MY, EC_WORD_RENTAL, EC_WORD_POKEMON, EC_WORD_WON},
        .speechLose = {EC_WORD_RENTAL, EC_WORD_POKEMON, EC_WORD_AREN_T, EC_WORD_UP, EC_WORD_TO, EC_MOVE2(SCRATCH)},
        .monSets = gBattleFrontierTrainerMons_Xander
    },
    [132] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("Marvin"),
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_UP, EC_WORD_TO, EC_WORD_THE, EC_WORD_CHALLENGE, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_THINK, EC_WORD_YOU_RE, EC_WORD_GOOD, EC_WORD_ENOUGH},
        .speechLose = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_PERFECT, EC_WORD_THANK_YOU, EC_WORD_SO, EC_WORD_MUCH},
        .monSets = gBattleFrontierTrainerMons_Marvin
    },
    [133] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("Brennan"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(WISH), EC_WORD_TO, EC_WORD_SEE, EC_WORD_THE, EC_WORD_NEWS},
        .speechWin = {EC_WORD_COMICS, EC_WORD_GET, EC_WORD_DAMP, EC_WORD_FROM, EC_WORD_DRIZZLE, EC_WORD_QUES},
        .speechLose = {EC_WORD_THE, EC_WORD_TIGHT, EC_WORD_MONEY, EC_WORD_LIVING, EC_WORD_CHANNEL, EC_WORD_QUES_EXCL},
        .monSets = gBattleFrontierTrainerMons_Brennan
    },
    [134] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Baley"),
        .speechBefore = {EC_MOVE(SCREECH), EC_WORD_IS, EC_WORD_LIKE, EC_WORD_MUSIC, EC_WORD_TO_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_MY, EC_MOVE(SCREECH), EC_WORD_STRATEGY, EC_WORD_IS, EC_WORD_THE, EC_WORD_BEST},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_SOUNDPROOF, EC_WORD_QUES, 0xFFFF, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Baley
    },
    [135] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Zackary"),
        .speechBefore = {EC_WORD_CAN, EC_WORD_YOU, EC_MOVE(DIG), EC_WORD_IT, EC_WORD_YO, EC_WORD_QUES},
        .speechWin = {EC_MOVE2(TAKE_DOWN), EC_WORD_TAKE, EC_WORD_A, EC_MOVE2(DIVE), EC_WORD_YO, EC_WORD_YO},
        .speechLose = {EC_WORD_BREAK, EC_WORD_DOWN, EC_MOVE2(DIVE), EC_WORD_TIME, EC_WORD_FOR, EC_WORD_ME},
        .monSets = gBattleFrontierTrainerMons_Zackary
    },
    [136] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Gabriel"),
        .speechBefore = {EC_MOVE2(POUND), EC_WORD_THE, EC_WORD_THICK_FAT, EC_WORD_ON, EC_WORD_MY, EC_MOVE2(BELLY_DRUM)},
        .speechWin = {EC_MOVE2(POUND), EC_WORD_MY, EC_MOVE2(BELLY_DRUM), EC_MOVE2(POUND), EC_WORD_MY, EC_MOVE2(BELLY_DRUM)},
        .speechLose = {EC_WORD_MY, EC_MOVE2(BELLY_DRUM), EC_WORD_WAS, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Gabriel
    },
    [137] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("Emily"),
        .speechBefore = {EC_WORD_HOW, EC_WORD_ABOUT, EC_WORD_A_TINY_BIT, EC_WORD_OF, EC_MOVE(HYPNOSIS), EC_WORD_QUES},
        .speechWin = {EC_WORD_MY, EC_MOVE(HYPNOSIS), EC_WORD_STRATEGY, EC_WORD_WORKS, EC_WORD_TO, EC_WORD_PERFECTION},
        .speechLose = {EC_WORD_MY, EC_MOVE(HYPNOSIS), EC_WORD_STRATEGY, EC_WORD_WENT, EC_WORD_BADLY, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Emily
    },
    [138] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("Jordyn"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_KNOW, EC_WORD_MY, EC_WORD_SECRET, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_AS, EC_WORD_I, EC_WORD_APPEAR, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_BUT, EC_WORD_HOW, EC_WORD_DID, EC_WORD_YOU, EC_WORD_KNOW, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Jordyn
    },
    [139] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("Sofia"),
        .speechBefore = {EC_POKEMON(LOUDRED), EC_WORD_PROBABLY, EC_WORD_HAS, EC_WORD_A, EC_MOVE(SWEET_SCENT), 0xFFFF},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_THE, EC_WORD_FEELING, EC_WORD_THAT, EC_WORD_I, EC_WORD_GET},
        .speechLose = {EC_WORD_I, EC_WORD_WORK, EC_WORD_AT, EC_WORD_THE, EC_WORD_DEPT_STORE, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Sofia
    },
    [140] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("Braden"),
        .speechBefore = {EC_WORD_I_CHOOSE_YOU, EC_WORD_EXCL, 0xFFFF, EC_WORD_THIS_IS_IT_EXCL, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_PRETTY, EC_WORD_AWESOME, EC_WORD_ABOUT, EC_WORD_MYSELF},
        .speechLose = {EC_WORD_ALL_RIGHT, EC_WORD_EXCL, 0xFFFF, EC_WORD_I, EC_WORD_SURRENDER, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Braden
    },
    [141] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("Kayden"),
        .speechBefore = {EC_WORD_THEY, EC_WORD_OVERDO, EC_WORD_THAT, EC_WORD_GOURMET, EC_WORD_THING, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_THAT, EC_WORD_GOURMET, EC_WORD_THING, EC_WORD_ISN_T, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_HEY, EC_WORD_THIS, EC_WORD_IS, EC_WORD_PRETTY, EC_WORD_TASTY, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Kayden
    },
    [142] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("Cooper"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_SHOULD, EC_WORD_ABSOLUTELY, EC_WORD_BE, EC_WORD_A, EC_WORD_PUSHOVER},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_TOO, EC_WORD_EXCITING, EC_WORD_FOR, EC_WORD_ME, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_EXCL, 0xFFFF, EC_WORD_SORRY, EC_WORD_I_AM, EC_WORD_SORRY},
        .monSets = gBattleFrontierTrainerMons_Cooper
    },
    [143] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("Julia"),
        .speechBefore = {EC_WORD_SPIRIT, EC_WORD_ALONE, EC_WORD_WON_T, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_WIN},
        .speechWin = {EC_WORD_YOU, EC_WORD_SHOULD, EC_WORD_ACCEPT, EC_WORD_THIS, EC_WORD_WITH, EC_WORD_SERENE_GRACE},
        .speechLose = {EC_WORD_FOR_NOW, EC_WORD_GOOD_BYE, EC_WORD_BUT, EC_WORD_IT_S, EC_WORD_NOT, EC_WORD_OVER},
        .monSets = gBattleFrontierTrainerMons_Julia
    },
    [144] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("Amara"),
        .speechBefore = {EC_WORD_WROOOAAR_EXCL, EC_WORD_EXCL_EXCL, EC_WORD_I_AM, EC_WORD_SO, EC_WORD_READY, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_LOSE, EC_WORD_MYSELF, EC_WORD_IF, EC_WORD_IT_S, EC_WORD_EXCITING},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_TO, EC_MOVE2(TACKLE), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Amara
    },
    [145] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("Lynn"),
        .speechBefore = {EC_WORD_YOUR, EC_WORD_SECRET, EC_WORD_CAN_T, EC_WORD_BE, EC_WORD_HIDDEN, EC_WORD_FOREVER},
        .speechWin = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_YOUR, EC_WORD_SECRET, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_CAN_T, EC_MOVE(SAFEGUARD), EC_WORD_YOUR, EC_WORD_OWN, EC_WORD_SECRET},
        .monSets = gBattleFrontierTrainerMons_Lynn
    },
    [146] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("Jovan"),
        .speechBefore = {EC_WORD_YOUR, EC_WORD_BATTLE, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_SADLY, EC_WORD_LACKING},
        .speechWin = {EC_WORD_MY, EC_WORD_BATTLE, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_COOL, EC_WORD_ISN_T_IT_QUES},
        .speechLose = {EC_WORD_I_WAS, EC_WORD_MINUS, EC_WORD_MY, EC_WORD_NORMAL, EC_WORD_POWER, EC_WORD_TODAY},
        .monSets = gBattleFrontierTrainerMons_Jovan
    },
    [147] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("Dominic"),
        .speechBefore = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_THIS, EC_WORD_EXCELLENT, EC_WORD_CAMERA, 0xFFFF},
        .speechWin = {EC_WORD_MY, EC_WORD_CAMERA, EC_WORD_WAS, EC_WORD_AWFULLY, EC_WORD_EXPENSIVE, 0xFFFF},
        .speechLose = {EC_WORD_MY, EC_WORD_CAMERA, EC_WORD_DOESN_T, EC_WORD_MISS, EC_WORD_A, EC_WORD_THING},
        .monSets = gBattleFrontierTrainerMons_Dominic
    },
    [148] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("Nikolas"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(MIMIC), EC_WORD_POKEMON, EC_WORD_AFTER, EC_WORD_EVERY, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_IF_I_WIN, EC_WORD_I, EC_WORD_PRETEND, EC_WORD_I_AM, EC_WORD_A, EC_POKEMON2(TAUROS)},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_I, EC_WORD_PRETEND, EC_WORD_I_AM, EC_WORD_A, EC_POKEMON2(MILTANK)},
        .monSets = gBattleFrontierTrainerMons_Nikolas
    },
    [149] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("Valeria"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(WISH), EC_WORD_YOU, EC_WORD_WOULD, EC_WORD_NOT, EC_MOVE2(GLARE)},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_MEAN, EC_WORD_EXCL, EC_WORD_I, EC_WORD_MEAN, EC_WORD_REALLY},
        .speechLose = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_A, EC_WORD_REALLY, EC_MOVE(SCARY_FACE), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Valeria
    },
    [150] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("Delaney"),
        .speechBefore = {EC_WORD_SCHOOL, EC_WORD_IS, EC_WORD_OVER, EC_WORD_TIME, EC_WORD_TO, EC_WORD_PLAY},
        .speechWin = {EC_WORD_MY, EC_WORD_BOY, EC_WORD_FRIEND, EC_WORD_IS, EC_WORD_FROM, EC_WORD_SCHOOL},
        .speechLose = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_WORK, EC_WORD_NEXT, EC_WORD_WEEK},
        .monSets = gBattleFrontierTrainerMons_Delaney
    },
    [151] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("Meghan"),
        .speechBefore = {EC_WORD_SCHOOL, EC_WORD_IS, EC_WORD_OUT, EC_WORD_TIME, EC_WORD_TO, EC_WORD_PLAY},
        .speechWin = {EC_WORD_MY, EC_WORD_BOY, EC_WORD_FRIEND, EC_WORD_LIKES, EC_WORD_COMICS, 0xFFFF},
        .speechLose = {EC_WORD_IT_S, EC_WORD_BACK, EC_WORD_TO, EC_WORD_SCHOOL, EC_WORD_SOON, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Meghan
    },
    [152] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("Roberto"),
        .speechBefore = {EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_INVINCIBLE, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_YOU, EC_WORD_WEREN_T, EC_WORD_BAD, EC_WORD_I_WAS, EC_WORD_JUST, EC_WORD_BETTER},
        .speechLose = {EC_WORD_AREN_T, EC_WORD_YOU, EC_WORD_SATISFIED, EC_WORD_YET, EC_WORD_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Roberto
    },
    [153] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("Damian"),
        .speechBefore = {EC_WORD_MY, EC_WORD_PURE_POWER, EC_WORD_IS, EC_WORD_MACHINE, EC_WORD_LIKE, EC_WORD_EXCL},
        .speechWin = {EC_WORD_MY, EC_MOVE2(MACH_PUNCH), EC_WORD_WILL, EC_WORD_MAKE, EC_WORD_A, EC_MOVE(BRICK_BREAK)},
        .speechLose = {EC_WORD_ARRGH, EC_WORD_EXCL, 0xFFFF, EC_WORD_NO, EC_WORD_EXCL_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Damian
    },
    [154] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("Brody"),
        .speechBefore = {EC_WORD_MY, EC_WORD_FASHION, EC_WORD_SENSE, EC_WORD_SEEMS, EC_POKEMON(ODDISH), EC_WORD_QUES},
        .speechWin = {EC_WORD_IT_S, EC_WORD_MY, EC_WORD_FAMILY, EC_WORD_STAY_AT_HOME, EC_WORD_LOOK, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_QUESTION, EC_WORD_YOUR, EC_WORD_FASHION, EC_WORD_SENSE, EC_WORD_SERIOUSLY},
        .monSets = gBattleFrontierTrainerMons_Brody
    },
    [155] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("Graham"),
        .speechBefore = {EC_WORD_YEAH, EC_WORD_EXCL, 0xFFFF, EC_WORD_YEAH_YEAH, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_EXCL, EC_WORD_WAHAHAHA, EC_WORD_WAHAHAHA, EC_WORD_EXCL_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_MY, EC_WORD_BAD},
        .monSets = gBattleFrontierTrainerMons_Graham
    },
    [156] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("Tylor"),
        .speechBefore = {EC_WORD_ARE, EC_WORD_YOU, EC_WORD_FEELING, EC_WORD_MY, EC_MOVE2(HEAT_WAVE), EC_WORD_QUES},
        .speechWin = {EC_WORD_YES, EC_WORD_I_AM, EC_WORD_ON, EC_WORD_FIRE, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_BUT, EC_WORD_I_WAS, EC_WORD_ON, EC_WORD_FIRE, EC_WORD_FOR, EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Tylor
    },
    [157] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("Jaren"),
        .speechBefore = {EC_WORD_FIGHTING, EC_WORD_SPIRIT, EC_WORD_QUES, EC_WORD_ME, EC_WORD_QUES, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_WORD_WANT, EC_WORD_MORE, EC_WORD_CUTE, EC_WORD_POKEMON, 0xFFFF},
        .speechLose = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_LOOK, EC_WORD_QUITE, EC_WORD_CUTE, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Jaren
    },
    [158] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("Cordell"),
        .speechBefore = {EC_WORD_A, EC_WORD_BATTLE, EC_WORD_IS, EC_WORD_DECIDED, EC_WORD_ON, EC_WORD_SPIRIT},
        .speechWin = {EC_WORD_CAN_T, EC_WORD_YOU, EC_WORD_ACCEPT, EC_WORD_THAT, EC_WORD_QUES, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_BE, EC_WORD_ON, EC_WORD_MY, EC_WORD_WAY},
        .monSets = gBattleFrontierTrainerMons_Cordell
    },
    [159] = {
        .facilityClass = FACILITY_CLASS_POKEMON_BREEDER_F,
        .trainerName = _("Jazlyn"),
        .speechBefore = {EC_WORD_IS, EC_WORD_YOUR, EC_WORD_POKEDEX, EC_WORD_REALLY, EC_WORD_AWESOME, EC_WORD_QUES},
        .speechWin = {EC_WORD_OH_YEAH, EC_WORD_WOW, EC_WORD_YOUR, EC_WORD_POKEDEX, EC_WORD_IS, EC_WORD_SUPER},
        .speechLose = {EC_WORD_AN, EC_WORD_AVANT_GARDE, EC_WORD_POKEDEX, EC_WORD_WOULD, EC_WORD_BE, EC_WORD_AWESOME},
        .monSets = gBattleFrontierTrainerMons_Jazlyn
    },
    [160] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("Zachery"),
        .speechBefore = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_MY, EC_WORD_OWN, EC_WORD_PLACE, EC_WORD_YEEHAW_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_AN, EC_WORD_EXCITING, EC_WORD_TIME, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_FLATTEN, EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Zachery
    },
    [161] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("Johan"),
        .speechBefore = {EC_WORD_WINTER, EC_WORD_WILL, EC_WORD_SOON, EC_WORD_BE, EC_WORD_HERE, 0xFFFF},
        .speechWin = {EC_WORD_MY, EC_WORD_ALLOWANCE, EC_WORD_COULD, EC_WORD_USE, EC_WORD_A, EC_MOVE2(HELPING_HAND)},
        .speechLose = {EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_USE, EC_WORD_MY, EC_WORD_ALLOWANCE, EC_WORD_UP},
        .monSets = gBattleFrontierTrainerMons_Johan
    },
    [162] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("Shea"),
        .speechBefore = {EC_WORD_DO, EC_WORD_YOU, EC_WORD_BATTLE, EC_WORD_WITH, EC_WORD_BEAUTY, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_BATTLE, EC_WORD_IN, EC_WORD_AN, EC_WORD_UGLY, EC_WORD_WAY},
        .speechLose = {EC_WORD_WHAT, EC_WORD_IS, EC_WORD_BEAUTY, EC_WORD_TO, EC_WORD_YOU, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Shea
    },
    [163] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("Kaila"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_THIRSTY, EC_WORD_RIGHT, EC_WORD_NOW, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_I, EC_WORD_COULD, EC_WORD_USE, EC_WORD_A, EC_WORD_COLD, EC_WORD_DRINK},
        .speechLose = {EC_WORD_THAT, EC_WORD_LOSS, EC_WORD_IS, EC_WORD_HARD, EC_WORD_TO, EC_MOVE2(SWALLOW)},
        .monSets = gBattleFrontierTrainerMons_Kaila
    },
    [164] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("Isiah"),
        .speechBefore = {EC_WORD_I, EC_WORD_PRETEND, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_A_LOT, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_MOVE2(TRICK), EC_WORD_MOTHER, EC_WORD_FOR, EC_WORD_MY, EC_WORD_ALLOWANCE},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_WANT, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_MORE},
        .monSets = gBattleFrontierTrainerMons_Isiah
    },
    [165] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .trainerName = _("Garrett"),
        .speechBefore = {EC_WORD_I, EC_WORD_ENJOY, EC_WORD_COMICS, EC_WORD_AND, EC_WORD_THIS, EC_WORD_GAME},
        .speechWin = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_THIS, EC_WORD_MUSIC, EC_WORD_IDOL, EC_WORD_TOO},
        .speechLose = {EC_WORD_BUT, EC_WORD_I, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_STUDY, EC_WORD_MORE},
        .monSets = gBattleFrontierTrainerMons_Garrett
    },
    [166] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("Haylie"),
        .speechBefore = {EC_WORD_I, EC_WORD_WORRY, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_TO, EC_WORD_SLEEP},
        .speechWin = {EC_WORD_A, EC_WORD_WIN, EC_WORD_GIVES, EC_WORD_ME, EC_WORD_A, EC_MOVE2(CALM_MIND)},
        .speechLose = {EC_WORD_MY, EC_WORD_INSOMNIA, EC_WORD_WILL, EC_WORD_GET, EC_WORD_BAD, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Haylie
    },
    [167] = {
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .trainerName = _("Megan"),
        .speechBefore = {EC_WORD_I, EC_WORD_BELIEVE, EC_WORD_IN, EC_WORD_AN, EC_MOVE(AROMATHERAPY), EC_WORD_BATH},
        .speechWin = {EC_WORD_I, EC_WORD_WANT, EC_WORD_A, EC_WORD_HEALTHY, EC_WORD_CLEAR_BODY, 0xFFFF},
        .speechLose = {EC_WORD_IF, EC_WORD_ONLY, EC_MOVE(AROMATHERAPY), EC_WORD_WERE, EC_WORD_LESS, EC_WORD_EXPENSIVE},
        .monSets = gBattleFrontierTrainerMons_Megan
    },
    [168] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("Issac"),
        .speechBefore = {EC_WORD_MY, EC_WORD_HOBBY, EC_WORD_QUES, 0xFFFF, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_ANY, EC_WORD_KIND, EC_WORD_OF, EC_MOVE2(WATER_SPORT)},
        .speechLose = {EC_WORD_I, EC_WORD_DISLIKE, EC_WORD_ANY, EC_WORD_KIND, EC_WORD_OF, EC_MOVE2(MUD_SPORT)},
        .monSets = gBattleFrontierTrainerMons_Issac
    },
    [169] = {
        .facilityClass = FACILITY_CLASS_RICH_BOY,
        .trainerName = _("Quinton"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_SAD, EC_WORD_CAUSE, EC_WORD_I_AM, EC_WORD_TOO_WEAK, 0xFFFF},
        .speechWin = {EC_WORD_YOU, EC_WORD_AREN_T, EC_WORD_TOO_STRONG, EC_WORD_FOR, EC_WORD_ME, 0xFFFF},
        .speechLose = {EC_WORD_HEY, EC_WORD_WHAT, EC_WORD_DID, EC_WORD_I, EC_WORD_DO, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Quinton
    },
    [170] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("Salma"),
        .speechBefore = {EC_WORD_YOU_VE, EC_WORD_GOT, EC_WORD_YOUR, EC_WORD_HUSTLE, EC_WORD_ON, EC_WORD_EXCL},
        .speechWin = {EC_WORD_I, EC_WORD_WIN, EC_WORD_YOU, EC_WORD_HUSTLE, EC_WORD_ON, EC_WORD_OUT},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_GET, EC_WORD_HOW, EC_WORD_I, EC_WORD_LOST},
        .monSets = gBattleFrontierTrainerMons_Salma
    },
    [171] = {
        .facilityClass = FACILITY_CLASS_LADY,
        .trainerName = _("Ansley"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_BORED, EC_WORD_ELLIPSIS, EC_WORD_DANCE, EC_WORD_FOR, EC_WORD_ME},
        .speechWin = {EC_WORD_YOU_VE, EC_WORD_BORED, EC_WORD_ME, EC_WORD_SOME, EC_WORD_MORE, 0xFFFF},
        .speechLose = {EC_WORD_TAKE, EC_WORD_YOUR, EC_MOVE2(FRUSTRATION), EC_WORD_SOME, EC_WORD_OTHER, EC_WORD_PLACE},
        .monSets = gBattleFrontierTrainerMons_Ansley
    },
    [172] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("Holden"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_COMMEMORATE, EC_WORD_MY, EC_WORD_COOLNESS, EC_WORD_IN, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOO_WEAK, EC_WORD_FOR, EC_WORD_ANY, EC_WORD_PRAISE, 0xFFFF},
        .speechLose = {EC_WORD_YOUR, EC_WORD_BATTLE, EC_WORD_SENSE, EC_WORD_IS, EC_WORD_AMUSING, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Holden
    },
    [173] = {
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .trainerName = _("Luca"),
        .speechBefore = {EC_WORD_WE, EC_WORD_WILL, EC_WORD_HAVE, EC_WORD_A, EC_WORD_COOL, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_I, EC_WORD_WON, EC_WORD_IN, EC_WORD_A, EC_WORD_COOL, EC_WORD_WAY},
        .speechLose = {EC_WORD_HELLO, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_JUST, EC_WORD_A, EC_WORD_KID},
        .monSets = gBattleFrontierTrainerMons_Luca
    },
    [174] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("Jamison"),
        .speechBefore = {EC_WORD_MY, EC_MOVE2(SECRET_POWER), EC_WORD_IS, EC_WORD_OVERWHELMING, EC_WORD_TO, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_DID, EC_WORD_YOU, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_QUES, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_USE, EC_MOVE(SMOKESCREEN), EC_WORD_TO, EC_WORD_ESCAPE},
        .monSets = gBattleFrontierTrainerMons_Jamison
    },
    [175] = {
        .facilityClass = FACILITY_CLASS_NINJA_BOY,
        .trainerName = _("Gunnar"),
        .speechBefore = {EC_WORD_I, EC_MOVE(CUT), EC_WORD_DOWN, EC_WORD_EVERY, EC_WORD_OPPONENT, 0xFFFF},
        .speechWin = {EC_WORD_DON_T, EC_MOVE(GRUDGE), EC_WORD_ME, EC_WORD_FOR, EC_WORD_YOUR, EC_WORD_LOSS},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_LOSE, EC_WORD_THAT, EC_MOVE(SCARY_FACE), EC_WORD_OF, EC_WORD_YOURS},
        .monSets = gBattleFrontierTrainerMons_Gunnar
    },
    [176] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("Craig"),
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_FOR, EC_WORD_MY, EC_WORD_TRAIN},
        .speechWin = {EC_WORD_MY, EC_WORD_TRAIN, EC_WORD_ISN_T, EC_WORD_HERE, EC_WORD_YET, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_HERE_IT_IS, EC_WORD_MY, EC_WORD_TRAIN, EC_WORD_SEE_YA, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Craig
    },
    [177] = {
        .facilityClass = FACILITY_CLASS_TUBER_M,
        .trainerName = _("Pierce"),
        .speechBefore = {EC_WORD_THERE, EC_WORD_WAS, EC_WORD_A, EC_MOVE2(HEAT_WAVE), EC_WORD_LAST, EC_WORD_WEEK},
        .speechWin = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_TAKE, EC_WORD_A, EC_MOVE2(HEAT_WAVE), 0xFFFF},
        .speechLose = {EC_WORD_DIDN_T, EC_WORD_IT, EC_MOVE(HAIL), EC_WORD_TOO, EC_WORD_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Pierce
    },
    [178] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("Regina"),
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_PLAY, EC_WORD_IN, EC_WORD_WATER},
        .speechWin = {EC_WORD_I, EC_WORD_REFUSE, EC_WORD_TO, EC_WORD_COME, EC_WORD_OUT, 0xFFFF},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_NOT, EC_WORD_MUCH, EC_WORD_GOOD, EC_WORD_IN, EC_WORD_WATER},
        .monSets = gBattleFrontierTrainerMons_Regina
    },
    [179] = {
        .facilityClass = FACILITY_CLASS_TUBER_F,
        .trainerName = _("Alison"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_KINDERGARTEN, EC_WORD_MAGAZINE, EC_WORD_IS, EC_WORD_TOO, EC_WORD_MUCH},
        .speechWin = {EC_WORD_HOW, EC_WORD_TO, EC_WORD_BUG, EC_WORD_YOUR, EC_WORD_TEACHER, EC_WORD_QUES},
        .speechLose = {EC_WORD_ENJOY, EC_WORD_A, EC_WORD_TASTY, EC_WORD_SCHOOL, EC_WORD_DIET, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Alison
    },
    [180] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Hank"),
        .speechBefore = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_A, EC_WORD_BUG, EC_WORD_EVENT, EC_WORD_SOON},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_BUG, EC_WORD_FASHION, EC_WORD_SHOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_DON_T, EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Hank
    },
    [181] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Earl"),
        .speechBefore = {EC_WORD_THE, EC_WORD_INVINCIBLE, EC_WORD_BUG, EC_WORD_TRAINER, EC_WORD_IS, EC_WORD_HERE},
        .speechWin = {EC_WORD_THE, EC_WORD_INVINCIBLE, EC_WORD_BUG, EC_WORD_TRAINER, EC_WORD_AM, EC_WORD_I},
        .speechLose = {EC_WORD_SEE, EC_WORD_HOW, EC_WORD_FAST, EC_WORD_I, EC_WORD_RUN_AWAY, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Earl
    },
    [182] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("Ramiro"),
        .speechBefore = {EC_WORD_I, EC_WORD_WENT, EC_WORD_TO, EC_WORD_A, EC_WORD_FISHING, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_SERIOUSLY, EC_WORD_I_AM, EC_WORD_IN, EC_WORD_THE, EC_WORD_FISHING, EC_WORD_HALL_OF_FAME},
        .speechLose = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_GO, EC_WORD_BACK, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Ramiro
    },
    [183] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("Hunter"),
        .speechBefore = {EC_WORD_SHOW, EC_WORD_ME, EC_WORD_A, EC_WORD_TOTALLY, EC_WORD_COOL, EC_MOVE(CROSS_CHOP)},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_TOO_WEAK, EC_WORD_TO, EC_WORD_DO, EC_WORD_A, EC_MOVE(CROSS_CHOP)},
        .speechLose = {EC_WORD_WAS, EC_WORD_IT, EC_WORD_A, EC_WORD_MISTAKE, EC_WORD_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Hunter
    },
    [184] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Aiden"),
        .speechBefore = {EC_WORD_MY, EC_WORD_WORK, EC_WORD_IS, EC_WORD_MAKING, EC_WORD_ME, EC_WORD_HEALTHY},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_I_AM, EC_WORD_HEALTHY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MORE, EC_WORD_HEALTHY, EC_WORD_THAN, EC_WORD_I_AM, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Aiden
    },
    [185] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Xavier"),
        .speechBefore = {EC_WORD_HEY_THERE, EC_WORD_EXCL, 0xFFFF, EC_WORD_LOOK, EC_WORD_LOOK, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_GOOD_BYE, EC_WORD_AND, EC_WORD_THANK_YOU, EC_WORD_THAT_WAS, EC_WORD_FUNNY, 0xFFFF},
        .speechLose = {EC_WORD_WOWEE, EC_WORD_EXCL, 0xFFFF, EC_WORD_NO, EC_WORD_NO, EC_WORD_EXCL_EXCL},
        .monSets = gBattleFrontierTrainerMons_Xavier
    },
    [186] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Clinton"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_TO, EC_WORD_SEE, EC_WORD_MY, EC_MOVE(HYPNOSIS), EC_WORD_QUES},
        .speechWin = {EC_WORD_YOUR, EC_MOVE2(FURY_SWIPES), EC_WORD_YOUR, EC_MOVE(STRENGTH), EC_WORD_YOUNG, EC_WORD_TRAINER},
        .speechLose = {EC_WORD_TCH, EC_WORD_ELLIPSIS, 0xFFFF, EC_WORD_I_AM, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Clinton
    },
    [187] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Jesse"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_BATTLE, EC_WORD_IS, EC_WORD_FOR, EC_WORD_MY, EC_WORD_MOTHER},
        .speechWin = {EC_WORD_MOTHER, EC_WORD_WILL, EC_WORD_BE, EC_WORD_HAPPY, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_I, EC_WORD_WANT, EC_WORD_MY, EC_WORD_MOTHER, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Jesse
    },
    [188] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("Eduardo"),
        .speechBefore = {EC_WORD_OUR, EC_WORD_MUSIC, EC_WORD_WILL, EC_WORD_PLAY, EC_WORD_ALL, EC_WORD_NIGHT},
        .speechWin = {EC_WORD_NIGHTTIME, EC_WORD_IS, EC_WORD_WHEN, EC_WORD_I, EC_WORD_PLAY, EC_WORD_BEST},
        .speechLose = {EC_WORD_LET_S, EC_WORD_PARTY, EC_WORD_UNTIL, EC_WORD_THE, EC_MOVE(MORNING_SUN), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Eduardo
    },
    [189] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("Hal"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_TRENDY, EC_WORD_AREN_T, EC_WORD_I, EC_WORD_QUES, 0xFFFF},
        .speechWin = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_HIP_AND, EC_WORD_HAPPENING, EC_WORD_OH_YEAH, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_TRENDY, EC_WORD_THANK_YOU, EC_WORD_VERY, EC_WORD_MUCH},
        .monSets = gBattleFrontierTrainerMons_Hal
    },
    [190] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("Gage"),
        .speechBefore = {EC_WORD_HERE_IT_IS, EC_WORD_A, EC_WORD_FLYING, EC_WORD_TYPE, EC_WORD_HIDDEN, EC_WORD_MOVE},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_FLYING, EC_WORD_TYPE, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IF_I_LOSE, EC_WORD_I, EC_WORD_JUST, EC_MOVE(FLY), EC_WORD_AWAY, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Gage
    },
    [191] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("Arnold"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_WEIRD, EC_WORD_FROM, EC_WORD_A, EC_WORD_DREAM},
        .speechWin = {EC_WORD_YOUR, EC_MOVE(SCARY_FACE), EC_WORD_WAS, EC_WORD_IN, EC_WORD_MY, EC_WORD_DREAM},
        .speechLose = {EC_WORD_MY, EC_WORD_INCREDIBLE, EC_WORD_DREAM, EC_WORD_WAS, EC_WORD_SO, EC_WORD_WEIRD},
        .monSets = gBattleFrontierTrainerMons_Arnold
    },
    [192] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("Jarrett"),
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_LET_S, EC_WORD_DANCE, EC_WORD_LIKE, EC_WORD_IT_S, EC_WORD_YESTERDAY},
        .speechWin = {EC_WORD_YOU, EC_WORD_LIKE, EC_WORD_HOW, EC_WORD_I, EC_WORD_DANCE, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_DON_T, EC_WORD_APPRECIATE, EC_WORD_HOW, EC_WORD_I, EC_WORD_DANCE},
        .monSets = gBattleFrontierTrainerMons_Jarrett
    },
    [193] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("Garett"),
        .speechBefore = {EC_WORD_MY, EC_WORD_GIRL, EC_WORD_GIVES, EC_WORD_ME, EC_WORD_A_LITTLE, EC_MOVE2(SWEET_KISS)},
        .speechWin = {EC_WORD_MY, EC_WORD_GIRL, EC_WORD_FRIEND, EC_WORD_IS, EC_WORD_MY, EC_WORD_TREASURE},
        .speechLose = {EC_WORD_A, EC_WORD_TREASURE, EC_WORD_ISN_T, EC_WORD_ALWAYS, EC_WORD_ABOUT, EC_WORD_MONEY},
        .monSets = gBattleFrontierTrainerMons_Garett
    },
    [194] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("Emanuel"),
        .speechBefore = {EC_WORD_SMARTNESS, EC_WORD_ALONE, EC_WORD_WON_T, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_WIN},
        .speechWin = {EC_WORD_I_AM, EC_WORD_NOT_VERY, EC_WORD_SMART, EC_WORD_BUT, EC_WORD_I, EC_WORD_WON},
        .speechLose = {EC_WORD_HOW, EC_WORD_DID, EC_WORD_YOU, EC_MOVE2(FAKE_OUT), EC_WORD_ME, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Emanuel
    },
    [195] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("Gustavo"),
        .speechBefore = {EC_MOVE(CHARGE), EC_WORD_EXCL, 0xFFFF, EC_MOVE(CHARGE), EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_SURRENDER, EC_WORD_QUES, 0xFFFF, EC_WORD_SO, EC_WORD_SOON, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_SURRENDER, EC_WORD_YET},
        .monSets = gBattleFrontierTrainerMons_Gustavo
    },
    [196] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("Kameron"),
        .speechBefore = {EC_WORD_TAKE_THAT, EC_WORD_EXCL, EC_WORD_IT_S, EC_WORD_MY, EC_WORD_FIERY, EC_MOVE2(TRICK)},
        .speechWin = {EC_WORD_DID, EC_WORD_MY, EC_WORD_FIERY, EC_MOVE2(TRICK), EC_MOVE(ASTONISH), EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_FALL, EC_WORD_FOR, EC_WORD_MY, EC_MOVE2(TRICK)},
        .monSets = gBattleFrontierTrainerMons_Kameron
    },
    [197] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("Alfredo"),
        .speechBefore = {EC_WORD_A, EC_WORD_FIERY, EC_WORD_GOURMET, EC_WORD_AM, EC_WORD_I, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_A, EC_WORD_TASTY, EC_WORD_GOURMET, EC_WORD_VICTORY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHAT, EC_WORD_A, EC_WORD_DISASTER, EC_WORD_THAT_WAS, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Alfredo
    },
    [198] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("Ruben"),
        .speechBefore = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_WAIT, EC_WORD_TO, EC_WORD_GET, EC_WORD_GOING},
        .speechWin = {EC_WORD_GET, EC_WORD_GOING, EC_WORD_EXCL, EC_WORD_THIS, EC_WORD_IS, EC_WORD_GOOD_BYE},
        .speechLose = {EC_WORD_I_VE, EC_WORD_GOT, EC_WORD_TO, EC_WORD_GET, EC_WORD_GOING, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Ruben
    },
    [199] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("Lamar"),
        .speechBefore = {EC_WORD_A, EC_MOVE2(PRESENT), EC_WORD_FOR, EC_WORD_ME, EC_WORD_QUES, 0xFFFF},
        .speechWin = {EC_WORD_MMM, EC_WORD_THIS, EC_WORD_IS, EC_WORD_QUITE, EC_WORD_TASTY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_OH, EC_WORD_IT_S, EC_WORD_A, EC_WORD_GAME, EC_WORD_IS_IT_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Lamar
    },
    [200] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("Jaxon"),
        .speechBefore = {EC_WORD_A, EC_WORD_SHELL_ARMOR, EC_WORD_IS, EC_WORD_WHAT, EC_WORD_I, EC_WORD_WANT},
        .speechWin = {EC_WORD_MY, EC_WORD_FATHER, EC_WORD_AND, EC_WORD_MOTHER, EC_WORD_WON_T, EC_WORD_ACCEPT},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_I, EC_WORD_NEED, EC_WORD_A, EC_WORD_SHELL_ARMOR, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Jaxon
    },
    [201] = {
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .trainerName = _("Logan"),
        .speechBefore = {EC_WORD_IF_I_LOSE, EC_WORD_I, EC_WORD_WILL, EC_WORD_STUDY, EC_WORD_FOR, EC_WORD_SCHOOL},
        .speechWin = {EC_WORD_ME, EC_WORD_STUDY, EC_WORD_QUES, EC_WORD_NOT_VERY, EC_WORD_LIKELY_TO, EC_WORD_SEE},
        .speechLose = {EC_WORD_NO, EC_WORD_THANKS, EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_SLEEP},
        .monSets = gBattleFrontierTrainerMons_Logan
    },
    [202] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("Emilee"),
        .speechBefore = {EC_WORD_IS, EC_WORD_THIS, EC_WORD_KIND, EC_WORD_OF, EC_WORD_BATTLE, EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_LET_S, EC_WORD_GO, EC_WORD_FOR, EC_WORD_AN, EC_MOVE(ICY_WIND), EC_MOVE2(SURF)},
        .speechLose = {EC_WORD_HOW, EC_WORD_ABOUT, EC_WORD_A, EC_MOVE(ROCK_SLIDE), EC_WORD_SHOW, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Emilee
    },
    [203] = {
        .facilityClass = FACILITY_CLASS_LASS,
        .trainerName = _("Josie"),
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_FASHION, EC_WORD_CONTEST, EC_WORD_IS, EC_WORD_PRETTY},
        .speechWin = {EC_WORD_I, EC_WORD_REALLY, EC_WORD_LIKE, EC_WORD_MODE, EC_WORD_FASHION, EC_WORD_THINGS},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_TOTALLY, EC_WORD_LACKING, EC_WORD_IN, EC_WORD_FASHION, EC_WORD_SENSE},
        .monSets = gBattleFrontierTrainerMons_Josie
    },
    [204] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("Armando"),
        .speechBefore = {EC_WORD_I, EC_WORD_NEED, EC_WORD_MORE, EC_WORD_GRASS, EC_WORD_TYPE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_TRADE, EC_WORD_ME, EC_WORD_A, EC_WORD_GRASS, EC_WORD_POKEMON, EC_WORD_PLEASE},
        .speechLose = {EC_WORD_THERE, EC_WORD_AREN_T, EC_WORD_ENOUGH, EC_WORD_GRASS, EC_WORD_TYPE, EC_WORD_POKEMON},
        .monSets = gBattleFrontierTrainerMons_Armando
    },
    [205] = {
        .facilityClass = FACILITY_CLASS_CAMPER,
        .trainerName = _("Skyler"),
        .speechBefore = {EC_MOVE2(INGRAIN), EC_WORD_IS, EC_WORD_MY, EC_WORD_CHOICE, EC_WORD_BATTLE, EC_WORD_MOVE},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_MOVE, EC_WORD_ME, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_MOVE(CUT), EC_WORD_ME, EC_WORD_DOWN, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Skyler
    },
    [206] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("Ruth"),
        .speechBefore = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_ENJOY, EC_WORD_THIS, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_MUCH, EC_WORD_TOO, EC_WORD_EASY, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_STOP, EC_WORD_I, EC_WORD_DON_T, EC_WORD_ENJOY, EC_WORD_THIS},
        .monSets = gBattleFrontierTrainerMons_Ruth
    },
    [207] = {
        .facilityClass = FACILITY_CLASS_PICNICKER,
        .trainerName = _("Melody"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(WISH), EC_WORD_SUNDAY, EC_WORD_IS, EC_WORD_A, EC_MOVE2(SUNNY_DAY)},
        .speechWin = {EC_WORD_SUNDAY, EC_WORD_SEEMS, EC_WORD_FOREVER, EC_WORD_TO, EC_WORD_COME, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THE, EC_WORD_FORECAST, EC_WORD_SAYS, EC_WORD_IT, EC_WORD_WILL, EC_MOVE(HAIL)},
        .monSets = gBattleFrontierTrainerMons_Melody
    },
    [208] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("Pedro"),
        .speechBefore = {EC_WORD_A, EC_WORD_SWIFT_SWIM, EC_WORD_WILL, EC_WORD_DO, EC_WORD_YOU, EC_WORD_GOOD},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_HOW, EC_WORD_I, EC_WORD_SINK, EC_WORD_AN, EC_WORD_OPPONENT},
        .speechLose = {EC_WORD_UH_OH, EC_WORD_EXCL, 0xFFFF, EC_WORD_A, EC_MOVE(WHIRLPOOL), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Pedro
    },
    [209] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_M,
        .trainerName = _("Erick"),
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_MOVE2(TACKLE), EC_WORD_YOU, EC_WORD_DOWN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_DON_T, EC_WORD_YOU, EC_WORD_RUN_AWAY, EC_WORD_YOU, EC_WORD_LOSER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_THINK, EC_WORD_YOU, EC_WORD_WOULD, EC_MOVE(COUNTER)},
        .monSets = gBattleFrontierTrainerMons_Erick
    },
    [210] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("Elaine"),
        .speechBefore = {EC_WORD_MY, EC_WORD_HEROINE, EC_WORD_ADVENTURE, EC_WORD_ISN_T, EC_WORD_GOING, EC_WORD_WELL},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I, EC_WORD_NEED},
        .speechLose = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_HEROINE},
        .monSets = gBattleFrontierTrainerMons_Elaine
    },
    [211] = {
        .facilityClass = FACILITY_CLASS_SWIMMER_F,
        .trainerName = _("Joyce"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_MAKE, EC_WORD_ME, EC_WORD_GO, EC_WORD_AHAHA, EC_WORD_EXCL},
        .speechWin = {EC_WORD_LALALA, EC_WORD_NO, EC_WORD_LOSING, EC_WORD_FOR, EC_WORD_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LALALA, EC_WORD_ELLIPSIS, 0xFFFF, EC_WORD_HUH_QUES, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Joyce
    },
    [212] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("Todd"),
        .speechBefore = {EC_WORD_YOU_RE, EC_WORD_A, EC_WORD_LIGHTNINGROD, EC_WORD_FOR, EC_WORD_MY, EC_WORD_POWER},
        .speechWin = {EC_WORD_THAT_S, EC_WORD_ALL, EC_WORD_YOU, EC_WORD_COULD, EC_MOVE(ABSORB), EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_MOVE2(REFLECT), EC_WORD_MY, EC_WORD_POWER, EC_WORD_BACK, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Todd
    },
    [213] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_M,
        .trainerName = _("Gavin"),
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_MOVE(BIDE), EC_WORD_MY, EC_WORD_TIME, 0xFFFF},
        .speechWin = {EC_WORD_IT_S, EC_WORD_OVER, EC_WORD_SO, EC_WORD_SOON, EC_WORD_QUES, 0xFFFF},
        .speechLose = {EC_WORD_MY, EC_WORD_MISTAKE, EC_WORD_WAS, EC_WORD_TOO, EC_WORD_EXPENSIVE, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Gavin
    },
    [214] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("Malory"),
        .speechBefore = {EC_WORD_PROMISE, EC_WORD_TO, EC_WORD_SHOW, EC_WORD_ME, EC_WORD_CUTE, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, 0xFFFF, EC_WORD_THANK_YOU, EC_WORD_SO, EC_WORD_MUCH},
        .speechLose = {EC_WORD_TCH, EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_AREN_T, EC_WORD_VERY, EC_WORD_NICE},
        .monSets = gBattleFrontierTrainerMons_Malory
    },
    [215] = {
        .facilityClass = FACILITY_CLASS_POKEFAN_F,
        .trainerName = _("Esther"),
        .speechBefore = {EC_WORD_I, EC_WORD_WANT, EC_WORD_A, EC_WORD_NICE, EC_MOVE2(PRESENT), EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_PLEASE, EC_WORD_GET, EC_WORD_ME, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_GAME},
        .speechLose = {EC_WORD_MESSAGE, EC_WORD_CARDS, EC_WORD_MAKE, EC_WORD_A, EC_WORD_WEAK, EC_MOVE2(PRESENT)},
        .monSets = gBattleFrontierTrainerMons_Esther
    },
    [216] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("Oscar"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_SEE, EC_WORD_YOUR, EC_WORD_POWER, EC_WORD_IN, EC_WORD_FULL},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_NOT, EC_WORD_YOUR, EC_WORD_FULL, EC_WORD_POWER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_NOT, EC_WORD_FUNNY, EC_WORD_ELLIPSIS, EC_WORD_YOU_RE, EC_WORD_TOO_STRONG, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Oscar
    },
    [217] = {
        .facilityClass = FACILITY_CLASS_PKMN_BREEDER_M,
        .trainerName = _("Wilson"),
        .speechBefore = {EC_WORD_WORK, EC_WORD_IS, EC_WORD_MAKING, EC_WORD_ME, EC_WORD_AN, EC_WORD_EARLY_BIRD},
        .speechWin = {EC_WORD_ALL, EC_WORD_WORK, EC_WORD_AND, EC_WORD_NO, EC_WORD_PLAY, EC_WORD_ELLIPSIS},
        .speechLose = {EC_MOVE(ENDURE), EC_WORD_IS, EC_WORD_ALL, EC_WORD_I, EC_WORD_CAN, EC_WORD_DO},
        .monSets = gBattleFrontierTrainerMons_Wilson
    },
    [218] = {
        .facilityClass = FACILITY_CLASS_POKEMON_BREEDER_F,
        .trainerName = _("Clare"),
        .speechBefore = {EC_WORD_YAY, EC_WORD_EXCL, EC_WORD_A, EC_WORD_TOUGH, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_AWW, EC_WORD_EXCL, EC_WORD_A, EC_WORD_WIMPY, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechLose = {EC_WORD_COOL, EC_WORD_EXCL, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_TRAINER, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Clare
    },
    [219] = {
        .facilityClass = FACILITY_CLASS_POKEMON_BREEDER_F,
        .trainerName = _("Tess"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_SOME, EC_POKEMON(GULPIN), EC_WORD_DESIGN, EC_WORD_SWEETS, EC_WORD_QUES},
        .speechWin = {EC_WORD_THEY_RE, EC_WORD_A, EC_WORD_SECRET, EC_WORD_POKEMON, EC_WORD_GOURMET, EC_WORD_ITEM},
        .speechLose = {EC_WORD_THEY_RE, EC_WORD_TASTY, EC_WORD_EXCL, EC_WORD_REFRESHING, EC_WORD_TOO, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Tess
    },
    [220] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("Leon"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_BETTER, EC_WORD_THAN, EC_WORD_ANY, EC_WORD_OTHER, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_I, EC_WORD_DID, EC_WORD_IT, EC_MOVE2(JUMP_KICK), EC_WORD_FOR, EC_WORD_JOY},
        .speechLose = {EC_WORD_BACK, EC_WORD_HOME, EC_WORD_I, EC_WORD_WILL, EC_WORD_GO, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Leon
    },
    [221] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("Alonzo"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_NOT, EC_WORD_LOST, EC_WORD_ONCE, EC_WORD_YET, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOUR, EC_WORD_SAD, EC_WORD_LOOK, EC_WORD_BECOMES, EC_WORD_YOU, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_BELIEVE, EC_WORD_THIS, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Alonzo
    },
    [222] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("Vince"),
        .speechBefore = {EC_WORD_THE, EC_WORD_TOP, EC_WORD_TRAINER, EC_WORD_THAT_S, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_THE, EC_WORD_TOP, EC_WORD_RANK, EC_WORD_BELONGS_TO, EC_WORD_ME, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_APPEAL, EC_WORD_THIS, EC_MOVE(OUTRAGE), EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Vince
    },
    [223] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_M,
        .trainerName = _("Bryon"),
        .speechBefore = {EC_WORD_MY, EC_MOVE2(BARRAGE), EC_WORD_WILL, EC_MOVE2(SLAM), EC_WORD_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU, EC_WORD_DIDN_T, EC_WORD_COUNT_ON, EC_WORD_ANY, EC_WORD_LESS, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_JUST, EC_WORD_DON_T, EC_WORD_GET, EC_WORD_IT, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Bryon
    },
    [224] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("Ava"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_TREASURE, EC_WORD_OF, EC_WORD_THIS, EC_WORD_WORLD},
        .speechWin = {EC_WORD_MY, EC_WORD_WORLD, EC_WORD_IS, EC_WORD_FULL, EC_WORD_OF, EC_WORD_WONDER},
        .speechLose = {EC_WORD_WHY, EC_WORD_ARE, EC_WORD_YOU, EC_WORD_SO, EC_WORD_TERRIBLE, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Ava
    },
    [225] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("Miriam"),
        .speechBefore = {EC_WORD_OH, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_WITH, EC_WORD_A, EC_MOVE(SCARY_FACE)},
        .speechWin = {EC_WORD_AHAHA, EC_WORD_YOU, EC_WORD_ONLY, EC_WORD_LOOK, EC_WORD_SCARY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_AIYEEH, EC_WORD_EXCL, EC_WORD_YOU, EC_WORD_REALLY, EC_WORD_ARE, EC_WORD_SCARY},
        .monSets = gBattleFrontierTrainerMons_Miriam
    },
    [226] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("Carrie"),
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_WORD_SHOW, EC_WORD_YOU, EC_WORD_GUTSY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_IT_S, EC_WORD_ALL, EC_WORD_ABOUT, EC_WORD_GUTS, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_OH, EC_WORD_NO, EC_WORD_ELLIPSIS, EC_MOVE(SELF_DESTRUCT), EC_WORD_MODE, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Carrie
    },
    [227] = {
        .facilityClass = FACILITY_CLASS_COOLTRAINER_F,
        .trainerName = _("Gillian"),
        .speechBefore = {EC_WORD_I, EC_WORD_SEEK, EC_WORD_A, EC_WORD_TRULY, EC_WORD_GREAT, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_I, EC_WORD_NEED, EC_WORD_A_LOT, EC_WORD_BETTER, EC_WORD_BATTLE, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THAT_WAS, EC_WORD_A_LITTLE, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_TO, EC_WORD_TAKE},
        .monSets = gBattleFrontierTrainerMons_Gillian2
    },
    [228] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("Tyler"),
        .speechBefore = {EC_WORD_YO, EC_WORD_EXCL, 0xFFFF, EC_WORD_LET_S, EC_WORD_GO, EC_WORD_EXCL_EXCL},
        .speechWin = {EC_WORD_YO, EC_WORD_EXCL, 0xFFFF, EC_WORD_I, EC_WORD_WON, EC_WORD_YO},
        .speechLose = {EC_WORD_YO, EC_WORD_EXCL, 0xFFFF, EC_WORD_I, EC_WORD_LOST, EC_WORD_YO},
        .monSets = gBattleFrontierTrainerMons_Tyler
    },
    [229] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("Chaz"),
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_HAVE, EC_WORD_TOO, EC_WORD_MUCH, EC_WORD_POWER},
        .speechWin = {EC_WORD_THEY, EC_WORD_HAVE, EC_WORD_MORE, EC_WORD_POWER, EC_WORD_NOW, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YEAH, EC_MOVE2(TAKE_DOWN), EC_WORD_THEIR, EC_WORD_POWER, EC_WORD_A_TINY_BIT, EC_WORD_PLEASE},
        .monSets = gBattleFrontierTrainerMons_Chaz
    },
    [230] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_M,
        .trainerName = _("Nelson"),
        .speechBefore = {EC_WORD_WELL_THEN, EC_WORD_WILL, EC_WORD_THIS, EC_WORD_POKEMON, EC_WORD_WORK, EC_WORD_QUES},
        .speechWin = {EC_WORD_I, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_IT, EC_WORD_WAS, EC_WORD_TOO_STRONG},
        .speechLose = {EC_WORD_IT, EC_WORD_DIDN_T, EC_WORD_MATCH_UP, EC_WORD_WELL, EC_WORD_I, EC_WORD_THINK},
        .monSets = gBattleFrontierTrainerMons_Nelson
    },
    [231] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("Shania"),
        .speechBefore = {EC_WORD_ALL, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_ABSOLUTELY, EC_WORD_ADORE, EC_WORD_ME},
        .speechWin = {EC_WORD_HAPPINESS, EC_WORD_IS, EC_WORD_A, EC_WORD_POKEMON, EC_WORD_WITH, EC_WORD_CUTE_CHARM},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_SO, EC_WORD_MEAN, EC_WORD_TO, EC_WORD_CUTE, EC_WORD_POKEMON},
        .monSets = gBattleFrontierTrainerMons_Shania
    },
    [232] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("Stella"),
        .speechBefore = {EC_WORD_I, EC_WORD_WANT, EC_WORD_TO, EC_WORD_SEE, EC_WORD_YOUR, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_WELL, EC_WORD_AREN_T, EC_WORD_THEY, EC_WORD_BORING, EC_WORD_QUES, EC_WORD_AHAHA},
        .speechLose = {EC_WORD_YOUR, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_SOMETHING, EC_WORD_ELSE, EC_WORD_ALL_RIGHT},
        .monSets = gBattleFrontierTrainerMons_Stella
    },
    [233] = {
        .facilityClass = FACILITY_CLASS_PKMN_RANGER_F,
        .trainerName = _("Dorine"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_YOUNG, EC_WORD_AND, EC_WORD_STRONG, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_SEE, EC_WORD_QUES, EC_WORD_AREN_T, EC_WORD_I, EC_WORD_GOOD, EC_WORD_QUES},
        .speechLose = {EC_WORD_THIS, EC_WORD_ISN_T, EC_WORD_WORKING, EC_WORD_OUT, EC_WORD_AT, EC_WORD_ALL},
        .monSets = gBattleFrontierTrainerMons_Dorine
    },
    [234] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("Maddox"),
        .speechBefore = {EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_MY, EC_WORD_NO_1, EC_WORD_CHOICE},
        .speechWin = {EC_WORD_IT_S, EC_WORD_NO, EC_WORD_SECRET, EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_WIN},
        .speechLose = {EC_WORD_DRAGON, EC_WORD_POKEMON, EC_WORD_SHOULD, EC_WORD_NOT, EC_WORD_LOSE, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Maddox
    },
    [235] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("Davin"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_HEAR, EC_WORD_YOU, EC_MOVE2(ROAR), EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_WROOOAAR_EXCL, 0xFFFF, 0xFFFF, EC_WORD_VICTORY, EC_WORD_EXCL_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_WROOOAAR_EXCL, 0xFFFF, 0xFFFF, EC_WORD_WHY, EC_WORD_QUES_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Davin
    },
    [236] = {
        .facilityClass = FACILITY_CLASS_DRAGON_TAMER,
        .trainerName = _("Trevon"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_LIVING, EC_WORD_ONLY, EC_WORD_WITH, EC_WORD_DRAGON, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_THE, EC_WORD_WAY, EC_WORD_I_AM, EC_WORD_LIVING, EC_WORD_IS, EC_WORD_PERFECT},
        .speechLose = {EC_WORD_YOU_VE, EC_WORD_DESTROYED, EC_WORD_THE, EC_WORD_WAY, EC_WORD_I_AM, EC_WORD_LIVING},
        .monSets = gBattleFrontierTrainerMons_Trevon
    },
    [237] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("Mateo"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_SHOULD, EC_WORD_BE, EC_WORD_OVER, EC_WORD_SOON, EC_WORD_ENOUGH},
        .speechWin = {EC_WORD_WELL, EC_WORD_THAT, EC_WORD_DIDN_T, EC_WORD_TAKE, EC_WORD_VERY, EC_WORD_MUCH},
        .speechLose = {EC_WORD_I, EC_WORD_CAN_T, EC_WORD_LOSE, EC_WORD_SO, EC_WORD_SOON, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Mateo
    },
    [238] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("Bret"),
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_ROCK_SOLID, EC_WORD_POKEMON, EC_WORD_THE, EC_WORD_BEST},
        .speechWin = {EC_WORD_TOUGHNESS, EC_WORD_IS, EC_WORD_THE, EC_WORD_WAY, EC_WORD_TO, EC_WORD_GO},
        .speechLose = {EC_WORD_I, EC_WORD_ALSO, EC_WORD_HAVE, EC_WORD_A, EC_WORD_PLUSH_DOLL, EC_WORD_COLLECTION},
        .monSets = gBattleFrontierTrainerMons_Bret
    },
    [239] = {
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .trainerName = _("Raul"),
        .speechBefore = {EC_WORD_I, EC_WORD_REJECT, EC_WORD_EVERY, EC_WORD_WEAK, EC_WORD_TRAINER, 0xFFFF},
        .speechWin = {EC_WORD_HUMPH, EC_WORD_EXCL, EC_WORD_ANOTHER, EC_WORD_WEAK, EC_WORD_TRAINER, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NOTHING, EC_WORD_WEAK, EC_WORD_ABOUT, EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Raul
    },
    [240] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("Kay"),
        .speechBefore = {EC_WORD_AND, EC_WORD_YET, EC_WORD_ANOTHER, EC_WORD_BATTLE, EC_WORD_QUES, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_WORD_WON, EC_WORD_BUT, EC_WORD_I_AM, EC_WORD_TIRED, EC_WORD_ELLIPSIS},
        .speechLose = {EC_WORD_GOOD, EC_WORD_IT_S, EC_WORD_OVER, EC_WORD_AT, EC_WORD_LAST, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Kay
    },
    [241] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("Elena"),
        .speechBefore = {EC_WORD_A, EC_WORD_BATTLE, EC_WORD_GIRL, EC_WORD_THAT_S, EC_WORD_ME, EC_WORD_EXCL},
        .speechWin = {EC_WORD_ISN_T, EC_WORD_A, EC_WORD_BATTLE, EC_WORD_GIRL, EC_WORD_AWESOME, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_DISLIKE, EC_WORD_A, EC_WORD_BATTLE, EC_WORD_GIRL, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Elena
    },
    [242] = {
        .facilityClass = FACILITY_CLASS_BATTLE_GIRL,
        .trainerName = _("Alana"),
        .speechBefore = {EC_WORD_EAT, EC_WORD_MY, EC_WORD_INVINCIBLE, EC_WORD_ATTACK, EC_WORD_YOU, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_MUCH, EC_WORD_TO, EC_WORD_LEARN, 0xFFFF},
        .speechLose = {EC_WORD_SO, EC_WORD_MUCH, EC_WORD_FOR, EC_WORD_MY, EC_WORD_INVINCIBLE, EC_WORD_ATTACK},
        .monSets = gBattleFrontierTrainerMons_Alana
    },
    [243] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("Alexas"),
        .speechBefore = {EC_WORD_GOOD, EC_WORD_TO, EC_WORD_MEET_YOU, EC_WORD_YOUNG, EC_WORD_TRAINER, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WAHAHAHA, EC_WORD_EXCL, 0xFFFF, EC_WORD_GIVE, EC_WORD_IT, EC_WORD_UP},
        .speechLose = {EC_WORD_YOU, EC_WORD_ARE, EC_WORD_A, EC_WORD_STRONG, EC_WORD_TRAINER, EC_WORD_KID},
        .monSets = gBattleFrontierTrainerMons_Alexas
    },
    [244] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("Weston"),
        .speechBefore = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_PLAY, EC_WORD_DOWN, EC_WORD_ALL_RIGHT, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU_RE, EC_WORD_FAR, EC_WORD_TOO, EC_WORD_EASY, EC_WORD_TO, EC_WORD_ATTACK},
        .speechLose = {EC_WORD_WELL, EC_WORD_WELL, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_SURRENDER, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Weston
    },
    [245] = {
        .facilityClass = FACILITY_CLASS_EXPERT_M,
        .trainerName = _("Jasper"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_OLD, EC_WORD_I_AM, EC_WORD_SKILLED, EC_WORD_EXCL},
        .speechWin = {EC_WORD_SKILLED, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_I_AM, EC_WORD_SHOCKED, EC_WORD_EXCL, EC_WORD_DOWN, EC_WORD_I, EC_WORD_GO},
        .monSets = gBattleFrontierTrainerMons_Jasper
    },
    [246] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("Nadia"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_CAN_T, EC_WORD_BEAT, EC_WORD_ME, EC_WORD_DOWN, EC_WORD_EXCL},
        .speechWin = {EC_WORD_HAH, EC_WORD_EXCL, 0xFFFF, EC_WORD_I, EC_WORD_BEAT, EC_WORD_YOU},
        .speechLose = {EC_WORD_I_AM, EC_MOVE2(BEAT_UP), EC_WORD_AND, EC_WORD_DOWNCAST, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Nadia
    },
    [247] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("Miranda"),
        .speechBefore = {EC_WORD_WELL, EC_WORD_WELL, 0xFFFF, EC_WORD_LET_S, EC_WORD_START, 0xFFFF},
        .speechWin = {EC_WORD_WHAT, EC_WORD_QUES, EC_WORD_DONE, EC_WORD_SO, EC_WORD_SOON, EC_WORD_QUES},
        .speechLose = {EC_WORD_WELL, EC_WORD_I, EC_WORD_SEE, EC_WORD_THAT, EC_WORD_I_AM, EC_WORD_TOO_WEAK},
        .monSets = gBattleFrontierTrainerMons_Miranda
    },
    [248] = {
        .facilityClass = FACILITY_CLASS_EXPERT_F,
        .trainerName = _("Emma"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_BEEN, EC_WORD_HEARING, EC_WORD_ABOUT, EC_WORD_YOU, 0xFFFF},
        .speechWin = {EC_WORD_I, EC_WORD_THINK, EC_WORD_I_VE, EC_WORD_MISHEARD, EC_WORD_THINGS, 0xFFFF},
        .speechLose = {EC_WORD_WHAT, EC_WORD_I_VE, EC_WORD_BEEN, EC_WORD_HEARING, EC_WORD_IS, EC_WORD_RIGHT},
        .monSets = gBattleFrontierTrainerMons_Emma
    },
    [249] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("Rolando"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_SUPER, EC_WORD_POKEMON, EC_WORD_HERO, EC_WORD_EXCL},
        .speechWin = {EC_WORD_WAS, EC_WORD_THAT, EC_WORD_ENOUGH, EC_WORD_FOR, EC_WORD_YOU, EC_WORD_QUES},
        .speechLose = {EC_WORD_YOU, EC_WORD_SHOULD, EC_WORD_NOT, EC_WORD_BEAT, EC_WORD_A, EC_WORD_HERO},
        .monSets = gBattleFrontierTrainerMons_Rolando
    },
    [250] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("Stanly"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_SHOULD, EC_WORD_BE, EC_WORD_AN, EC_WORD_EASY, EC_WORD_MATCH},
        .speechWin = {EC_WORD_IT, EC_WORD_REALLY, EC_WORD_WAS, EC_WORD_EASY, 0xFFFF, 0xFFFF},
        .speechLose = {EC_WORD_ARE, EC_WORD_YOU, EC_WORD_HAPPY, EC_WORD_NOW, EC_WORD_QUES, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Stanly
    },
    [251] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_M,
        .trainerName = _("Dario"),
        .speechBefore = {EC_WORD_MY, EC_MOVE2(FORESIGHT), EC_WORD_SAYS, EC_WORD_I, EC_WORD_WILL, EC_WORD_WIN},
        .speechWin = {EC_WORD_MY, EC_MOVE2(FORESIGHT), EC_WORD_HAS, EC_WORD_BEEN, EC_WORD_PERFECT, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_DIDN_T, EC_WORD_SEE, EC_WORD_THIS, EC_MOVE(REVERSAL), EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Dario
    },
    [252] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("Karlee"),
        .speechBefore = {EC_WORD_SOMETHING, EC_WORD_GOOD, EC_WORD_WILL, EC_WORD_COME, EC_WORD_OF, EC_WORD_THIS},
        .speechWin = {EC_WORD_YOU, EC_WORD_SEE, EC_WORD_QUES, EC_WORD_FANTASTIC, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_THAT, EC_WORD_SOMETHING, EC_WORD_GOOD, EC_WORD_WENT, EC_WORD_TO, EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Karlee
    },
    [253] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("Jaylin"),
        .speechBefore = {EC_WORD_EVERY, EC_WORD_TRAINER, EC_WORD_HAS, EC_WORD_BEEN, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS},
        .speechWin = {EC_WORD_IT_S, EC_WORD_MAKING, EC_WORD_ME, EC_MOVE(YAWN), EC_WORD_THAT, EC_WORD_BATTLE},
        .speechLose = {EC_WORD_I, EC_WORD_SLEPT, EC_WORD_AND, EC_WORD_SO, EC_WORD_I, EC_WORD_LOST},
        .monSets = gBattleFrontierTrainerMons_Jaylin
    },
    [254] = {
        .facilityClass = FACILITY_CLASS_PSYCHIC_F,
        .trainerName = _("Ingrid"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_A, EC_WORD_VERY, EC_WORD_MEAN, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_WASN_T, EC_WORD_THAT, EC_WORD_A, EC_WORD_GOOD, EC_WORD_MATCH, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_LOST, EC_WORD_CAUSE, EC_WORD_YOU_RE, EC_WORD_MEAN, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Ingrid
    },
    [255] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("Delilah"),
        .speechBefore = {EC_WORD_DON_T, EC_MOVE(GRUDGE), EC_WORD_ME, EC_WORD_IF_I_WIN, EC_WORD_OK_QUES, 0xFFFF},
        .speechWin = {EC_WORD_I_AM, EC_WORD_SORRY, EC_WORD_TO, EC_WORD_SEE, EC_WORD_YOU, EC_WORD_ANGRY},
        .speechLose = {EC_WORD_I, EC_WORD_HAVE, EC_WORD_A, EC_MOVE(GRUDGE), EC_WORD_WITH, EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Delilah
    },
    [256] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("Carly"),
        .speechBefore = {EC_WORD_I, EC_WORD_WILL, EC_WORD_SCATTER, EC_WORD_SOME, EC_MOVE2(POISON_POWDER), EC_WORD_ABOUT},
        .speechWin = {EC_WORD_IT_S, EC_WORD_SCARY, EC_WORD_HOW, EC_WORD_MY, EC_WORD_STRATEGY, EC_WORD_WORKS},
        .speechLose = {EC_WORD_I, EC_WORD_DISLIKE, EC_WORD_YOU, EC_WORD_AND, EC_WORD_YOUR, EC_WORD_POKEMON},
        .monSets = gBattleFrontierTrainerMons_Carly
    },
    [257] = {
        .facilityClass = FACILITY_CLASS_HEX_MANIAC,
        .trainerName = _("Lexie"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_TO, EC_WORD_SEE, EC_WORD_SCARY, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechWin = {EC_WORD_WASN_T, EC_WORD_THAT, EC_WORD_SCARY, EC_WORD_EH_QUES, 0xFFFF, 0xFFFF},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_MORE, EC_WORD_SCARY, EC_WORD_THAN, EC_WORD_MY, EC_WORD_POKEMON},
        .monSets = gBattleFrontierTrainerMons_Lexie
    },
    [258] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("Miller"),
        .speechBefore = {EC_WORD_HELLO, EC_WORD_QUES, 0xFFFF, EC_WORD_HELLO, EC_WORD_QUES_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_HELLO, EC_WORD_MOTHER, EC_WORD_EXCL, EC_WORD_I, EC_WORD_WON, EC_WORD_EXCL},
        .speechLose = {EC_WORD_MY, EC_WORD_PHONE, EC_WORD_ISN_T, EC_WORD_WORKING, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Miller
    },
    [259] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("Marv"),
        .speechBefore = {EC_WORD_YOU, EC_WORD_CAN, EC_WORD_LOSE, EC_WORD_YOUR, EC_MOVE(SWAGGER), EC_WORD_NOW},
        .speechWin = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_NO, EC_MOVE(SWAGGER), EC_WORD_LEFT, EC_WORD_EH_QUES},
        .speechLose = {EC_WORD_GO, EC_WORD_ON, EC_MOVE(SWAGGER), EC_WORD_ALL, EC_WORD_YOU, EC_WORD_WANT},
        .monSets = gBattleFrontierTrainerMons_Marv
    },
    [260] = {
        .facilityClass = FACILITY_CLASS_POKEMANIAC,
        .trainerName = _("Layton"),
        .speechBefore = {EC_WORD_I, EC_WORD_KNOW, EC_WORD_I_AM, EC_WORD_TOTALLY, EC_WORD_COOL, EC_WORD_EXCL},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN, EC_WORD_LOOK, EC_WORD_UP, EC_WORD_TO, EC_WORD_ME},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_COOL, EC_WORD_EXCL, EC_WORD_NO, EC_WORD_REALLY, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Layton
    },
    [261] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("Brooks"),
        .speechBefore = {EC_WORD_THIS, EC_WORD_IS, EC_WORD_A, EC_WORD_HIGH, EC_WORD_LEVEL, EC_WORD_BATTLE},
        .speechWin = {EC_WORD_THAT_WAS, EC_WORD_HIGH, EC_WORD_LEVEL, EC_WORD_AND, EC_WORD_EXCITING, EC_WORD_TOO},
        .speechLose = {EC_WORD_YOU_RE, EC_WORD_TOO, EC_WORD_HIGH, EC_WORD_IN, EC_WORD_LEVEL, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Brooks
    },
    [262] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("Gregory"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_THAT, EC_WORD_OLD, EC_WORD_YET, 0xFFFF},
        .speechWin = {EC_WORD_WHO, EC_WORD_SAYS, EC_WORD_I_AM, EC_WORD_TOO, EC_WORD_OLD, EC_WORD_QUES},
        .speechLose = {EC_WORD_PLEASE, EC_WORD_I_AM, EC_WORD_REALLY, EC_WORD_NOT, EC_WORD_THAT, EC_WORD_OLD},
        .monSets = gBattleFrontierTrainerMons_Gregory
    },
    [263] = {
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .trainerName = _("Reese"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_A, EC_WORD_COUPLE, EC_WORD_THINGS, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_DON_T, EC_WORD_DIET, EC_WORD_PLAY, EC_WORD_SPORTS, EC_WORD_INSTEAD, 0xFFFF},
        .speechLose = {EC_WORD_INSTEAD, EC_WORD_OF, EC_WORD_TELEVISION, EC_WORD_GET, EC_WORD_A, EC_WORD_BOOK},
        .monSets = gBattleFrontierTrainerMons_Reese
    },
    [264] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("Mason"),
        .speechBefore = {EC_WORD_PLEASE, EC_WORD_DON_T, EC_WORD_MAKE, EC_WORD_THIS, EC_WORD_SCARY, 0xFFFF},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_ELLIPSIS, 0xFFFF, EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_NOW},
        .speechLose = {EC_WORD_I_AM, EC_WORD_DISAPPOINTED, EC_WORD_ELLIPSIS, 0xFFFF, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Mason
    },
    [265] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .trainerName = _("Toby"),
        .speechBefore = {EC_WORD_LISTEN, EC_WORD_UP, 0xFFFF, EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_WIN},
        .speechWin = {EC_WORD_I_AM, EC_WORD_A, EC_WORD_GENIUS, EC_WORD_OR, EC_WORD_WHAT, EC_WORD_QUES},
        .speechLose = {EC_WORD_I, EC_WORD_CAN, EC_WORD_BEAT, EC_WORD_YOU, EC_WORD_AT, EC_WORD_SMARTNESS},
        .monSets = gBattleFrontierTrainerMons_Toby
    },
    [266] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("Dorothy"),
        .speechBefore = {EC_WORD_THE, EC_WORD_SPORTS, EC_WORD_WORLD, EC_WORD_SHOULD, EC_WORD_ACCEPT, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_THAT, EC_WORD_WIN, EC_WORD_WAS, EC_WORD_REFRESHING},
        .speechLose = {EC_WORD_THANK_YOU, EC_WORD_EXCL, EC_WORD_THAT, EC_WORD_LOSS, EC_WORD_WAS, EC_WORD_REFRESHING},
        .monSets = gBattleFrontierTrainerMons_Dorothy
    },
    [267] = {
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .trainerName = _("Piper"),
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_YOU, EC_WORD_NEED, EC_WORD_A, EC_WORD_SPEED_BOOST, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_NEED, EC_WORD_TO, EC_WORD_SHOW, EC_WORD_MORE, EC_WORD_GUTS},
        .speechLose = {EC_WORD_OH, EC_WORD_YOU, EC_WORD_EXCL, 0xFFFF, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Piper
    },
    [268] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("Finn"),
        .speechBefore = {EC_WORD_NOT, EC_WORD_ANOTHER, EC_WORD_TRAINER, EC_WORD_BATTLE, EC_WORD_ELLIPSIS, 0xFFFF},
        .speechWin = {EC_WORD_WON_T, EC_WORD_THIS, EC_WORD_EVER, EC_WORD_END, EC_WORD_QUES, 0xFFFF},
        .speechLose = {EC_WORD_I, EC_WORD_FINALLY, EC_WORD_GET, EC_WORD_TO, EC_MOVE2(REST), EC_WORD_A_LITTLE},
        .monSets = gBattleFrontierTrainerMons_Finn
    },
    [269] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_M,
        .trainerName = _("Samir"),
        .speechBefore = {EC_WORD_I, EC_MOVE2(DIVE), EC_WORD_BELOW, EC_WORD_THE, EC_MOVE2(SURF), EC_WORD_EXCL},
        .speechWin = {EC_WORD_YAHOO, EC_WORD_TAKE, EC_WORD_A, EC_MOVE2(DIVE), EC_WORD_YOU, EC_WORD_EXCL},
        .speechLose = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_TO, EC_WORD_SINK, EC_WORD_ELLIPSIS, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Samir
    },
    [270] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("Fiona"),
        .speechBefore = {EC_WORD_DID, EC_WORD_YOU, EC_WORD_LIMBER, EC_WORD_UP, EC_WORD_BEFORE, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_NEED, EC_WORD_TO, EC_WORD_BE, EC_WORD_MORE, EC_WORD_READY},
        .speechLose = {EC_WORD_BEING, EC_WORD_LIMBER, EC_WORD_DIDN_T, EC_WORD_WORK, EC_WORD_FOR, EC_WORD_ME},
        .monSets = gBattleFrontierTrainerMons_Fiona
    },
    [271] = {
        .facilityClass = FACILITY_CLASS_SWIMMING_TRIATHLETE_F,
        .trainerName = _("Gloria"),
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_TO, EC_WORD_ATTACK, EC_WORD_WITH, EC_WORD_SUCTION_CUPS},
        .speechWin = {EC_WORD_GIGGLE, EC_WORD_ELLIPSIS, EC_WORD_IT_S, EC_WORD_OVER, EC_WORD_FOR, EC_WORD_YOU},
        .speechLose = {EC_WORD_I, EC_WORD_DON_T, EC_WORD_GET, EC_WORD_HOW, EC_WORD_SUCTION_CUPS, EC_WORD_WORK},
        .monSets = gBattleFrontierTrainerMons_Gloria
    },
    [272] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("Nico"),
        .speechBefore = {EC_WORD_LIKE, EC_WORD_A, EC_MOVE(SONIC_BOOM), EC_WORD_I_VE_ARRIVED, 0xFFFF, 0xFFFF},
        .speechWin = {EC_WORD_SORRY, EC_WORD_TO, EC_WORD_MAKE, EC_WORD_YOU, EC_WORD_SO, EC_WORD_DOWNCAST},
        .speechLose = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_WITH, EC_WORD_A, EC_MOVE2(SUPERSONIC), EC_WORD_SPEED_BOOST},
        .monSets = gBattleFrontierTrainerMons_Nico
    },
    [273] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_M,
        .trainerName = _("Jeremy"),
        .speechBefore = {EC_WORD_A, EC_WORD_POKEMON, EC_WORD_MASTER, EC_WORD_THAT_S, EC_WORD_MY, EC_WORD_DREAM},
        .speechWin = {EC_WORD_MY, EC_WORD_DREAM, EC_WORD_ISN_T, EC_WORD_FAR, EC_WORD_OFF, EC_WORD_EXCL},
        .speechLose = {EC_WORD_WHAT, EC_WORD_I, EC_WORD_DREAM, EC_WORD_ISN_T, EC_WORD_HAPPENING, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Jeremy
    },
    [274] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("Caitlin"),
        .speechBefore = {EC_WORD_DON_T, EC_WORD_YOU, EC_WORD_THINK, EC_WORD_I_AM, EC_WORD_CUTE, EC_WORD_QUES},
        .speechWin = {EC_WORD_THERE, EC_WORD_IS, EC_WORD_MORE, EC_WORD_TO_ME, EC_WORD_THAN, EC_WORD_CUTENESS},
        .speechLose = {EC_WORD_MY, EC_WORD_CUTE_CHARM, EC_WORD_DOESN_T, EC_MOVE2(ATTRACT), EC_WORD_YOU, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Caitlin
    },
    [275] = {
        .facilityClass = FACILITY_CLASS_CYCLING_TRIATHLETE_F,
        .trainerName = _("Reena"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_ALWAYS, EC_WORD_HAPPY, EC_WORD_HAPPY, EC_WORD_HAPPY, EC_WORD_EXCL},
        .speechWin = {EC_WORD_OH, EC_WORD_YAY, EC_WORD_EXCL, EC_WORD_YAHOO, EC_WORD_FOR, EC_WORD_ME},
        .speechLose = {EC_WORD_YAHOO, EC_WORD_EXCL, EC_WORD_I_AM, EC_WORD_HAPPY, EC_WORD_FOR, EC_WORD_YOU},
        .monSets = gBattleFrontierTrainerMons_Reena
    },
    [276] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Avery"),
        .speechBefore = {EC_WORD_I_VE, EC_WORD_GOT, EC_WORD_A_LOT, EC_WORD_OF, EC_WORD_BUG, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_MY, EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ALL, EC_WORD_UNBELIEVABLE},
        .speechLose = {EC_WORD_MY, EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ALL, EC_WORD_UPSIDE_DOWN},
        .monSets = gBattleFrontierTrainerMons_Avery
    },
    [277] = {
        .facilityClass = FACILITY_CLASS_BUG_MANIAC,
        .trainerName = _("Liam"),
        .speechBefore = {EC_WORD_WE, EC_WORD_REALLY, EC_WORD_DISLIKE, EC_WORD_FIRE, EC_WORD_AND, EC_WORD_FLYING},
        .speechWin = {EC_WORD_BUG, EC_WORD_POKEMON, EC_WORD_AREN_T, EC_WORD_BAD, EC_WORD_HEY_QUES, 0xFFFF},
        .speechLose = {EC_WORD_YOU, EC_WORD_KNOW, EC_WORD_WHAT, EC_WORD_WE, EC_WORD_DISLIKE, EC_WORD_HEY_QUES},
        .monSets = gBattleFrontierTrainerMons_Liam
    },
    [278] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("Theo"),
        .speechBefore = {EC_WORD_FISHING, EC_WORD_IS, EC_WORD_MY, EC_WORD_CHOICE, EC_WORD_IN, EC_WORD_LIFE},
        .speechWin = {EC_WORD_WATER, EC_WORD_POKEMON, EC_MOVE2(ATTRACT), EC_WORD_ME, EC_WORD_WITHOUT, EC_WORD_END},
        .speechLose = {EC_WORD_DON_T, EC_WORD_COUNT_ON, EC_WORD_THAT, EC_WORD_HAPPENING, EC_WORD_ANOTHER, EC_WORD_TIME},
        .monSets = gBattleFrontierTrainerMons_Theo
    },
    [279] = {
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .trainerName = _("Bailey"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_I, EC_WORD_BATTLE, EC_WORD_EASY},
        .speechWin = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_I, EC_MOVE2(SWALLOW), EC_WORD_JOY},
        .speechLose = {EC_WORD_I_AM, EC_WORD_AN, EC_WORD_ADULT, EC_WORD_I, EC_MOVE2(SWALLOW), EC_MOVE2(FRUSTRATION)},
        .monSets = gBattleFrontierTrainerMons_Bailey
    },
    [280] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Hugo"),
        .speechBefore = {EC_WORD_I, EC_WORD_TRY, EC_WORD_THE, EC_WORD_BEST, EC_WORD_I, EC_WORD_CAN},
        .speechWin = {EC_WORD_I, EC_WORD_CAN_WIN, EC_WORD_IF, EC_WORD_I, EC_WORD_TRY, EC_WORD_ENOUGH},
        .speechLose = {EC_WORD_I, EC_WORD_DID, EC_WORD_TRY, EC_WORD_DIDN_T, EC_WORD_I, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Hugo
    },
    [281] = {
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .trainerName = _("Bryce"),
        .speechBefore = {EC_WORD_I_WAS, EC_WORD_ON, EC_WORD_VACATION, EC_WORD_UNTIL, EC_WORD_ONLY, EC_WORD_YESTERDAY},
        .speechWin = {EC_WORD_I, EC_WORD_HAVEN_T, EC_WORD_LOST, EC_WORD_MY, EC_WORD_SKILL, EC_WORD_YET},
        .speechLose = {EC_WORD_THAT_S, EC_WORD_IT, EC_WORD_ELLIPSIS, EC_WORD_I, EC_WORD_NEED, EC_WORD_SLEEP},
        .monSets = gBattleFrontierTrainerMons_Bryce
    },
    [282] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Gideon"),
        .speechBefore = {EC_WORD_WHAT_S_UP_QUES, EC_WORD_YOU, EC_WORD_THINK, EC_WORD_I_AM, EC_WORD_SCARY, EC_WORD_QUES},
        .speechWin = {EC_WORD_I_AM, EC_WORD_COOL, EC_WORD_BUT, EC_WORD_NOT, EC_WORD_SCARY, EC_WORD_EXCL},
        .speechLose = {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_MY, EC_WORD_FABULOUS, EC_WORD_FASHION, EC_WORD_SENSE},
        .monSets = gBattleFrontierTrainerMons_Gideon
    },
    [283] = {
        .facilityClass = FACILITY_CLASS_COLLECTOR,
        .trainerName = _("Triston"),
        .speechBefore = {EC_WORD_I, EC_WORD_WOULD, EC_WORD_RATHER, EC_WORD_LOOK, EC_WORD_AT, EC_WORD_POKEMON},
        .speechWin = {EC_WORD_HUH_QUES, EC_WORD_YOU, EC_WORD_MEAN, EC_WORD_I, EC_WORD_WON, EC_WORD_QUES_EXCL},
        .speechLose = {EC_WORD_SEE, EC_WORD_QUES, 0xFFFF, EC_WORD_I, EC_WORD_ALWAYS, EC_WORD_LOSE},
        .monSets = gBattleFrontierTrainerMons_Triston
    },
    [284] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("Charles"),
        .speechBefore = {EC_WORD_IT_S, EC_WORD_HOPELESS, EC_WORD_TO, EC_MOVE2(STRUGGLE), EC_WORD_WITH, EC_WORD_ME},
        .speechWin = {EC_MOVE(SUBMISSION), EC_WORD_WAS, EC_WORD_YOUR, EC_WORD_ONLY, EC_WORD_CHOICE, 0xFFFF},
        .speechLose = {EC_WORD_I_AM, EC_WORD_GOING, EC_WORD_DOWN, EC_WORD_DOWN, EC_WORD_DOWN, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Charles
    },
    [285] = {
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .trainerName = _("Raymond"),
        .speechBefore = {EC_WORD_WANT, EC_WORD_TO, EC_WORD_HEAR, EC_WORD_MY, EC_WORD_SONG, EC_WORD_QUES},
        .speechWin = {EC_WORD_SATISFIED, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_SATISFIED, EC_WORD_IS, EC_WORD_WHAT, EC_WORD_I, EC_WORD_CAN_T, EC_WORD_BE},
        .monSets = gBattleFrontierTrainerMons_Raymond
    },
    [286] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("Dirk"),
        .speechBefore = {EC_WORD_FLYING, EC_WORD_POKEMON, EC_WORD_ARE, EC_WORD_ABOVE, EC_WORD_THE, EC_MOVE2(REST)},
        .speechWin = {EC_WORD_YOU, EC_WORD_CAN_T_WIN, EC_WORD_EXCL, EC_WORD_FLYING, EC_WORD_POKEMON, EC_WORD_RULE},
        .speechLose = {EC_WORD_AREN_T, EC_WORD_THERE, EC_WORD_MORE, EC_WORD_FLYING, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Dirk
    },
    [287] = {
        .facilityClass = FACILITY_CLASS_BIRD_KEEPER,
        .trainerName = _("Harold"),
        .speechBefore = {EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_APPEAL, EC_WORD_TO, EC_WORD_YOU, EC_WORD_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_DO, EC_WORD_LIKE, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_QUES},
        .speechLose = {EC_WORD_SO, EC_WORD_YOU, EC_WORD_DISLIKE, EC_WORD_MY, EC_WORD_POKEMON, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Harold
    },
    [288] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("Omar"),
        .speechBefore = {EC_WORD_LET_ME_WIN, EC_WORD_IN, EC_MOVE(RETURN), EC_WORD_FOR, EC_WORD_A, EC_MOVE2(PRESENT)},
        .speechWin = {EC_WORD_HERE, EC_WORD_YOU, EC_WORD_ARE, EC_WORD_SOME, EC_MOVE2(TOXIC), EC_WORD_SWEETS},
        .speechLose = {EC_WORD_YOUR, EC_MOVE2(PRESENT), EC_WORD_QUES, EC_WORD_WHAT, EC_WORD_FOR, EC_WORD_QUES_EXCL},
        .monSets = gBattleFrontierTrainerMons_Omar
    },
    [289] = {
        .facilityClass = FACILITY_CLASS_SAILOR,
        .trainerName = _("Peter"),
        .speechBefore = {EC_WORD_I, EC_WORD_BRAG, EC_WORD_ABOUT, EC_WORD_MY, EC_WORD_HAPPINESS, EC_WORD_OK_QUES},
        .speechWin = {EC_WORD_YOU, EC_WORD_HAVE, EC_WORD_TO, EC_WORD_LISTEN, EC_WORD_TO_ME, EC_WORD_BRAG},
        .speechLose = {EC_WORD_I_AM, EC_WORD_DISAPPOINTED, EC_WORD_YOU, EC_WORD_WON_T, EC_WORD_LISTEN, EC_WORD_TO_ME},
        .monSets = gBattleFrontierTrainerMons_Peter
    },
    [290] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("Dev"),
        .speechBefore = {EC_WORD_COME_ON, EC_WORD_LET_S, EC_WORD_GET, EC_WORD_A, EC_WORD_MOVE, EC_WORD_ON},
        .speechWin = {EC_WORD_I, EC_WORD_GET, EC_WORD_TO, EC_WORD_NAP, EC_WORD_AFTER, EC_WORD_THAT},
        .speechLose = {EC_WORD_I, EC_WORD_NEED, EC_WORD_TO, EC_WORD_NAP, EC_WORD_AFTER, EC_WORD_THAT},
        .monSets = gBattleFrontierTrainerMons_Dev
    },
    [291] = {
        .facilityClass = FACILITY_CLASS_HIKER,
        .trainerName = _("Corey"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_TEACH, EC_WORD_YOU, EC_WORD_HOW, EC_WORD_TOUGH, EC_WORD_I_AM},
        .speechWin = {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_ME, EC_WORD_MAKE, EC_WORD_A, EC_MOVE(BRICK_BREAK)},
        .speechLose = {EC_WORD_MY, EC_MOVE2(FRUSTRATION), EC_WORD_IS, EC_WORD_CLOSE, EC_WORD_TO, EC_MOVE2(ERUPTION)},
        .monSets = gBattleFrontierTrainerMons_Corey
    },
    [292] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("Andre"),
        .speechBefore = {EC_WORD_NOW, EC_WORD_THIS, EC_WORD_IS, EC_WORD_A, EC_WORD_PERFECT, EC_WORD_FLAME_BODY},
        .speechWin = {EC_WORD_LOOK, EC_WORD_AT, EC_WORD_MY, EC_WORD_FIERY, EC_WORD_DANCE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_YOU, EC_WORD_WANT, EC_WORD_AN, EC_MOVE2(EXPLOSION), EC_WORD_HERE, EC_WORD_QUES},
        .monSets = gBattleFrontierTrainerMons_Andre
    },
    [293] = {
        .facilityClass = FACILITY_CLASS_KINDLER,
        .trainerName = _("Ferris"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_NO_1, EC_WORD_IN, EC_WORD_THE, EC_WORD_OLD, EC_WORD_CLASS},
        .speechWin = {EC_WORD_NO_1, EC_WORD_THAT_S, EC_WORD_WHAT, EC_WORD_I_AM, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_I_AM, EC_WORD_NOT, EC_WORD_NO_1, EC_WORD_ANY, EC_WORD_MORE, EC_WORD_ELLIPSIS},
        .monSets = gBattleFrontierTrainerMons_Ferris
    },
    [294] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("Alivia"),
        .speechBefore = {EC_WORD_I_AM, EC_WORD_FEELING, EC_WORD_GIDDY, EC_WORD_SO, EC_WORD_SHOULD, EC_WORD_YOU},
        .speechWin = {EC_WORD_IT, EC_WORD_WAS, EC_WORD_ALL, EC_WORD_TOGETHER, EC_WORD_TOO, EC_WORD_EASY},
        .speechLose = {EC_WORD_I, EC_WORD_WILL, EC_WORD_GIDDY, EC_WORD_UP, EC_WORD_AND, EC_WORD_AWAY},
        .monSets = gBattleFrontierTrainerMons_Alivia
    },
    [295] = {
        .facilityClass = FACILITY_CLASS_PARASOL_LADY,
        .trainerName = _("Paige"),
        .speechBefore = {EC_WORD_LET_S, EC_WORD_ENJOY, EC_WORD_OUR, EC_WORD_BATTLE, EC_WORD_TOGETHER, 0xFFFF},
        .speechWin = {EC_WORD_THAT_S_IT_EXCL, 0xFFFF, 0xFFFF, EC_WORD_THANK_YOU, EC_WORD_VERY, EC_WORD_MUCH},
        .speechLose = {EC_WORD_THAT_S_IT_EXCL, 0xFFFF, 0xFFFF, EC_WORD_DO, EC_WORD_GO, EC_WORD_ON},
        .monSets = gBattleFrontierTrainerMons_Paige
    },
    [296] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("Anya"),
        .speechBefore = {EC_WORD_I, EC_WORD_DISLIKE, EC_WORD_OH, EC_WORD_SO, EC_WORD_PRETTY, EC_WORD_FASHION},
        .speechWin = {EC_WORD_FASHION, EC_WORD_SHOULD, EC_WORD_MATCH, EC_WORD_THE, EC_WORD_PERSON, 0xFFFF},
        .speechLose = {EC_WORD_PRETTY, EC_WORD_COULD, EC_WORD_BE, EC_WORD_GOOD, 0xFFFF, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Anya
    },
    [297] = {
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .trainerName = _("Dawn"),
        .speechBefore = {EC_WORD_I, EC_WORD_GO, EC_WORD_ALL, EC_WORD_OUT, EC_WORD_EXCL, 0xFFFF},
        .speechWin = {EC_WORD_DON_T, EC_WORD_BE, EC_WORD_A, EC_WORD_BABY, EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_YOU, EC_WORD_WON, EC_WORD_EXCL, EC_WORD_MOVE, EC_WORD_ON, EC_WORD_EXCL},
        .monSets = gBattleFrontierTrainerMons_Dawn
    },
    [298] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("Abby"),
        .speechBefore = {EC_WORD_I, EC_WORD_LIKE, EC_WORD_A, EC_WORD_TRAINER, EC_WORD_THAT_S, EC_WORD_REFRESHING},
        .speechWin = {EC_WORD_VICTORY, EC_WORD_HAS, EC_WORD_A, EC_MOVE(SWEET_SCENT), EC_WORD_EXCL, 0xFFFF},
        .speechLose = {EC_WORD_WHAT, EC_WORD_AN, EC_WORD_AWFUL, EC_WORD_STENCH, EC_WORD_EXCL, 0xFFFF},
        .monSets = gBattleFrontierTrainerMons_Abby
    },
    [299] = {
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .trainerName = _("Gretel"),
        .speechBefore = {EC_WORD_I, EC_WORD_CAUSE, EC_MOVE(OUTRAGE), EC_WORD_AS, EC_WORD_A, EC_WORD_TRAINER},
        .speechWin = {EC_WORD_IT_S, EC_WORD_ONLY, EC_WORD_NATURAL, EC_WORD_SEE_YA, EC_WORD_BYE_BYE, EC_WORD_EXCL},
        .speechLose = {EC_WORD_IT_S, EC_WORD_HARD, EC_WORD_TO, EC_WORD_BELIEVE, EC_WORD_BUT, EC_WORD_CONGRATS},
        .monSets = gBattleFrontierTrainerMons_Gretel
    }
};
