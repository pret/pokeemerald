// gen 4+ data from urpg's contest movedex
const struct ContestMove gContestMoves[MOVES_COUNT] =
{
    [MOVE_NONE] = {0},

    [MOVE_POUND] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_POUND,
        .comboMoves = {0}
    },

    [MOVE_KARATE_CHOP] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_DOUBLE_SLAP] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_POUND},
    },

    [MOVE_COMET_PUNCH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MEGA_PUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
    },

    [MOVE_PAY_DAY] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FIRE_PUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_FIRE_PUNCH,
        .comboMoves = {COMBO_STARTER_ICE_PUNCH, COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_THUNDER_PUNCH},
    },

    [MOVE_ICE_PUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_ICE_PUNCH,
        .comboMoves = {COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_THUNDER_PUNCH},
    },

    [MOVE_THUNDER_PUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_THUNDER_PUNCH,
        .comboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_ICE_PUNCH},
    },

    [MOVE_SCRATCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SCRATCH,
        .comboMoves = {COMBO_STARTER_LEER},
    },

    [MOVE_VISE_GRIP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_VICE_GRIP,
        .comboMoves = {0}
    },

    [MOVE_GUILLOTINE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_VICE_GRIP},
    },

    [MOVE_RAZOR_WIND] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SWORDS_DANCE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SWORDS_DANCE,
        .comboMoves = {0}
    },

    [MOVE_CUT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_GUST] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WING_ATTACK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WHIRLWIND] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLY] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BIND] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_VICE_GRIP},
    },

    [MOVE_SLAM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_POUND},
    },

    [MOVE_VINE_WHIP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_STOMP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LEER},
    },

    [MOVE_DOUBLE_KICK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MEGA_KICK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
    },

    [MOVE_JUMP_KICK] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MIND_READER},
    },

    [MOVE_ROLLING_KICK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SAND_ATTACK] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_SAND_ATTACK,
        .comboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM},
    },

    [MOVE_HEADBUTT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_HORN_ATTACK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_HORN_ATTACK,
        .comboMoves = {COMBO_STARTER_LEER},
    },

    [MOVE_FURY_ATTACK] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HORN_ATTACK, COMBO_STARTER_PECK},
    },

    [MOVE_HORN_DRILL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HORN_ATTACK},
    },

    [MOVE_TACKLE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN, COMBO_STARTER_LEER},
    },

    [MOVE_BODY_SLAM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WRAP] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TAKE_DOWN] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
    },

    [MOVE_THRASH] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAGE},
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
    },

    [MOVE_TAIL_WHIP] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_POISON_STING] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TWINEEDLE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PIN_MISSILE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LEER] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_LEER,
        .comboMoves = {COMBO_STARTER_RAGE, COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_BITE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_GROWL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_ROAR] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SING] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_SING,
        .comboMoves = {0}
    },

    [MOVE_SUPERSONIC] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SONIC_BOOM] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DISABLE] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ACID] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_EMBER] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_FLAMETHROWER] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MIST] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WATER_GUN] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_WATER_SPORT},
    },

    [MOVE_HYDRO_PUMP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SURF] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SURF,
        .comboMoves = {COMBO_STARTER_DIVE, COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_ICE_BEAM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_BLIZZARD] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_POWDER_SNOW},
    },

    [MOVE_PSYBEAM] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_BUBBLE_BEAM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_AURORA_BEAM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_HYPER_BEAM] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PECK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_PECK,
        .comboMoves = {0}
    },

    [MOVE_DRILL_PECK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_PECK},
    },

    [MOVE_SUBMISSION] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MIND_READER},
    },

    [MOVE_LOW_KICK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COUNTER] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TAUNT},
    },

    [MOVE_SEISMIC_TOSS] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT},
    },

    [MOVE_STRENGTH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ABSORB] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_MEGA_DRAIN] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_LEECH_SEED] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_LEECH_SEED,
        .comboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_WORRY_SEED},
    },

    [MOVE_GROWTH] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_GROWTH,
        .comboMoves = {0}
    },

    [MOVE_RAZOR_LEAF] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_SOLAR_BEAM] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH, COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_POISON_POWDER] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWEET_SCENT},
    },

    [MOVE_STUN_SPORE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWEET_SCENT},
    },

    [MOVE_SLEEP_POWDER] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWEET_SCENT},
    },

    [MOVE_PETAL_DANCE] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_STRING_SHOT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_STRING_SHOT,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_RAGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_RAGE,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
    },

    [MOVE_FIRE_SPIN] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_THUNDER_SHOCK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_THUNDERBOLT] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_THUNDER_WAVE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_THUNDER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_ROCK_THROW] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_ROCK_THROW,
        .comboMoves = {0}
    },

    [MOVE_EARTHQUAKE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_EARTHQUAKE,
        .comboMoves = {0}
    },

    [MOVE_FISSURE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_EARTHQUAKE},
    },

    [MOVE_DIG] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TOXIC] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_TOXIC,
        .comboMoves = {0}
    },

    [MOVE_CONFUSION] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_CONFUSION,
        .comboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
    },

    [MOVE_PSYCHIC] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_PSYCHIC,
        .comboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS},
    },

    [MOVE_HYPNOSIS] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_HYPNOSIS,
        .comboMoves = {0}
    },

    [MOVE_MEDITATE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_AGILITY] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DOUBLE_TEAM},
    },

    [MOVE_QUICK_ATTACK] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DOUBLE_TEAM},
    },

    [MOVE_RAGE] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_RAGE,
        .comboMoves = {0}
    },

    [MOVE_TELEPORT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_DOUBLE_TEAM, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
    },

    [MOVE_NIGHT_SHADE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MIMIC] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SCREECH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DOUBLE_TEAM] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DOUBLE_TEAM,
        .comboMoves = {0}
    },

    [MOVE_RECOVER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HARDEN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_HARDEN,
        .comboMoves = {0}
    },

    [MOVE_MINIMIZE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SMOKESCREEN] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SMOG},
    },

    [MOVE_CONFUSE_RAY] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WITHDRAW] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_DEFENSE_CURL] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_DEFENSE_CURL,
        .comboMoves = {0}
    },

    [MOVE_BARRIER] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LIGHT_SCREEN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_HAZE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_REFLECT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_FOCUS_ENERGY] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_FOCUS_ENERGY,
        .comboMoves = {0}
    },

    [MOVE_BIDE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_METRONOME] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MIRROR_MOVE] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SELF_DESTRUCT] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_EGG_BOMB] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SOFT_BOILED},
    },

    [MOVE_LICK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SMOG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SMOG,
        .comboMoves = {0}
    },

    [MOVE_SLUDGE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SLUDGE,
        .comboMoves = {COMBO_STARTER_SLUDGE_BOMB},
    },

    [MOVE_BONE_CLUB] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_BONE_CLUB,
        .comboMoves = {COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
    },

    [MOVE_FIRE_BLAST] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_WATERFALL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_CLAMP] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SWIFT] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SKULL_BASH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPIKE_CANNON] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CONSTRICT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AMNESIA] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_KINESIS] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_KINESIS,
        .comboMoves = {COMBO_STARTER_CONFUSION, COMBO_STARTER_PSYCHIC},
    },

    [MOVE_SOFT_BOILED] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SOFT_BOILED,
        .comboMoves = {0}
    },

    [MOVE_HIGH_JUMP_KICK] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MIND_READER},
    },

    [MOVE_GLARE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LEER},
    },

    [MOVE_DREAM_EATER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_HYPNOSIS},
    },

    [MOVE_POISON_GAS] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BARRAGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LEECH_LIFE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LOVELY_KISS] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SKY_ATTACK] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRANSFORM] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BUBBLE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_DIZZY_PUNCH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPORE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLASH] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYWAVE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_SPLASH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ACID_ARMOR] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CRABHAMMER] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_EXPLOSION] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FURY_SWIPES] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCRATCH},
    },

    [MOVE_BONEMERANG] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_BONEMERANG,
        .comboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONE_RUSH, COMBO_STARTER_SHADOW_BONE},
    },

    [MOVE_REST] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_REST,
        .comboMoves = {COMBO_STARTER_BELLY_DRUM, COMBO_STARTER_CHARM, COMBO_STARTER_YAWN},
    },

    [MOVE_ROCK_SLIDE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ROCK_THROW},
    },

    [MOVE_HYPER_FANG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHARPEN] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CONVERSION] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRI_ATTACK] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LOCK_ON},
    },

    [MOVE_SUPER_FANG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_SLASH] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCRATCH, COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_SUBSTITUTE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STRUGGLE] = {0},

    [MOVE_SKETCH] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRIPLE_KICK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_THIEF] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPIDER_WEB] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_STRING_SHOT},
    },

    [MOVE_MIND_READER] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_MIND_READER,
        .comboMoves = {0}
    },

    [MOVE_NIGHTMARE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLAME_WHEEL] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_SNORE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_REST},
    },

    [MOVE_CURSE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_CURSE,
        .comboMoves = {0}
    },

    [MOVE_FLAIL] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_CONVERSION_2] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AEROBLAST] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COTTON_SPORE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_REVERSAL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_SPITE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CURSE},
    },

    [MOVE_POWDER_SNOW] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_POWDER_SNOW,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_PROTECT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HARDEN},
    },

    [MOVE_MACH_PUNCH] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SCARY_FACE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SCARY_FACE,
        .comboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_RAGE},
    },

    [MOVE_FEINT_ATTACK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_LEER, COMBO_STARTER_POUND},
    },

    [MOVE_SWEET_KISS] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_BELLY_DRUM] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_BELLY_DRUM,
        .comboMoves = {0}
    },

    [MOVE_SLUDGE_BOMB] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SLUDGE_BOMB,
        .comboMoves = {COMBO_STARTER_SLUDGE},
    },

    [MOVE_MUD_SLAP] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_MUD_SLAP,
        .comboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_SAND_ATTACK, COMBO_STARTER_SANDSTORM},
    },

    [MOVE_OCTAZOOKA] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SPIKES] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ZAP_CANNON] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_LOCK_ON},
    },

    [MOVE_FORESIGHT] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DESTINY_BOND] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CURSE, COMBO_STARTER_ENDURE, COMBO_STARTER_MEAN_LOOK},
    },

    [MOVE_PERISH_SONG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_SING},
    },

    [MOVE_ICY_WIND] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_DETECT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TAUNT},
    },

    [MOVE_BONE_RUSH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_BONE_RUSH,
        .comboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_SHADOW_BONE},
    },

    [MOVE_LOCK_ON] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_LOCK_ON,
        .comboMoves = {0}
    },

    [MOVE_OUTRAGE] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SANDSTORM] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SANDSTORM,
        .comboMoves = {0}
    },

    [MOVE_GIGA_DRAIN] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_ENDURE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_ENDURE,
        .comboMoves = {0}
    },

    [MOVE_CHARM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_CHARM,
        .comboMoves = {0}
    },

    [MOVE_ROLLOUT] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN},
    },

    [MOVE_FALSE_SWIPE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_SWAGGER] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MILK_DRINK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPARK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_FURY_CUTTER] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_STEEL_WING] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MEAN_LOOK] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_MEAN_LOOK,
        .comboMoves = {COMBO_STARTER_CURSE},
    },

    [MOVE_ATTRACT] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SLEEP_TALK] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_REST},
    },

    [MOVE_HEAL_BELL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_HEAL_BELL,
        .comboMoves = {COMBO_STARTER_LUCKY_CHANT},
    },

    [MOVE_RETURN] =
    {
        .effect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PRESENT] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FRUSTRATION] =
    {
        .effect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SAFEGUARD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PAIN_SPLIT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_SACRED_FIRE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MAGNITUDE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
    },

    [MOVE_MEGAHORN] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_BREATH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_BREATH,
        .comboMoves = {COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
    },

    [MOVE_BATON_PASS] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ENCORE] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PURSUIT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_RAPID_SPIN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SWEET_SCENT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_SWEET_SCENT,
        .comboMoves = {0}
    },

    [MOVE_IRON_TAIL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_METAL_CLAW] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_METAL_SOUND},
    },

    [MOVE_VITAL_THROW] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT},
    },

    [MOVE_MORNING_SUN] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_SYNTHESIS] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MOONLIGHT] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_HIDDEN_POWER] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CROSS_CHOP] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_TWISTER] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_RAIN_DANCE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_RAIN_DANCE,
        .comboMoves = {0}
    },

    [MOVE_SUNNY_DAY] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SUNNY_DAY,
        .comboMoves = {0}
    },

    [MOVE_CRUNCH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_MIRROR_COAT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TAUNT},
    },

    [MOVE_PSYCH_UP] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_EXTREME_SPEED] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ANCIENT_POWER] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHADOW_BALL] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FUTURE_SIGHT] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND, COMBO_STARTER_CONFUSION, COMBO_STARTER_KINESIS, COMBO_STARTER_PSYCHIC},
    },

    [MOVE_ROCK_SMASH] =
    {
        .effect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WHIRLPOOL] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_BEAT_UP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FAKE_OUT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_FAKE_OUT,
        .comboMoves = {0}
    },

    [MOVE_UPROAR] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STOCKPILE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_STOCKPILE,
        .comboMoves = {0}
    },

    [MOVE_SPIT_UP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_STOCKPILE},
    },

    [MOVE_SWALLOW] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_STOCKPILE},
    },

    [MOVE_HEAT_WAVE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_HAIL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_HAIL,
        .comboMoves = {0}
    },

    [MOVE_TORMENT] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLATTER] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_WILL_O_WISP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MEMENTO] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FACADE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FOCUS_PUNCH] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_SMELLING_SALTS] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FOLLOW_ME] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_NATURE_POWER] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CHARGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_CHARGE,
        .comboMoves = {0}
    },

    [MOVE_TAUNT] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_TAUNT,
        .comboMoves = {0}
    },

    [MOVE_HELPING_HAND] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRICK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ROLE_PLAY] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WISH] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ASSIST] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_INGRAIN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SUPERPOWER] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LOCK_ON, COMBO_STARTER_MIND_READER},
    },

    [MOVE_MAGIC_COAT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_RECYCLE] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_REVENGE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_REVENGE,
        .comboMoves = {COMBO_STARTER_PAYBACK},
    },

    [MOVE_BRICK_BREAK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_YAWN] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_YAWN,
        .comboMoves = {0}
    },

    [MOVE_KNOCK_OFF] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT},
    },

    [MOVE_ENDEAVOR] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_ERUPTION] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_EARTHQUAKE, COMBO_STARTER_ENDURE, COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_SKILL_SWAP] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_IMPRISON] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_REFRESH] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SING, COMBO_STARTER_WATER_SPORT},
    },

    [MOVE_GRUDGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CURSE},
    },

    [MOVE_SNATCH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SECRET_POWER] =
    {
        .effect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DIVE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_DIVE,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SURF},
    },

    [MOVE_ARM_THRUST] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_CAMOUFLAGE] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TAIL_GLOW] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LUSTER_PURGE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_MIST_BALL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_FEATHER_DANCE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TEETER_DANCE] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BLAZE_KICK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MUD_SPORT] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_MUD_SPORT,
        .comboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM, COMBO_STARTER_WATER_SPORT},
    },

    [MOVE_ICE_BALL] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_NEEDLE_ARM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SLACK_OFF] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HYPER_VOICE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POISON_FANG] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CRUSH_CLAW] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_BLAST_BURN] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_HYDRO_CANNON] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_METEOR_MASH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ASTONISH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WEATHER_BALL] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SANDSTORM, COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_AROMATHERAPY] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FAKE_TEARS] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AIR_CUTTER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_OVERHEAT] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_ODOR_SLEUTH] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ROCK_TOMB] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ROCK_THROW},
    },

    [MOVE_SILVER_WIND] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_METAL_SOUND] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_METAL_SOUND,
        .comboMoves = {0}
    },

    [MOVE_GRASS_WHISTLE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TICKLE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COSMIC_POWER] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WATER_SPOUT] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SIGNAL_BEAM] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHADOW_PUNCH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_EXTRASENSORY] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SKY_UPPERCUT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_SAND_TOMB] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SANDSTORM},
    },

    [MOVE_SHEER_COLD] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL, COMBO_STARTER_MIND_READER},
    },

    [MOVE_MUDDY_WATER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_BULLET_SEED] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_AERIAL_ACE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ICICLE_SPEAR] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_IRON_DEFENSE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BLOCK] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HOWL] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_CLAW] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
    },

    [MOVE_FRENZY_PLANT] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_BULK_UP] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BOUNCE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MUD_SHOT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SANDSTORM},
    },

    [MOVE_POISON_TAIL] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COVET] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_VOLT_TACKLE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAGICAL_LEAF] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_WATER_SPORT] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_WATER_SPORT,
        .comboMoves = {COMBO_STARTER_MUD_SPORT, COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_CALM_MIND] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_CALM_MIND,
        .comboMoves = {0}
    },

    [MOVE_LEAF_BLADE] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_DANCE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_DANCE,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
    },

    [MOVE_ROCK_BLAST] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHOCK_WAVE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_WATER_PULSE] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_DOOM_DESIRE] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYCHO_BOOST] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_ROOST] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_BRAVE_BIRD},
    },

    [MOVE_GRAVITY] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MIRACLE_EYE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HAMMER_ARM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_GYRO_BALL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEALING_WISH] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BRINE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_NATURAL_GIFT] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FEINT] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PLUCK] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TAILWIND] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ACUPRESSURE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_METAL_BURST] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_METAL_SOUND},
    },

    [MOVE_U_TURN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CLOSE_COMBAT] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
    },

    [MOVE_PAYBACK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_PAYBACK,
        .comboMoves = {COMBO_STARTER_REVENGE},
    },

    [MOVE_ASSURANCE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_PAYBACK, COMBO_STARTER_REVENGE},
    },

    [MOVE_EMBARGO] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLING] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRUMP_CARD] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEAL_BLOCK] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WRING_OUT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POWER_TRICK] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GASTRO_ACID] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LUCKY_CHANT] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_LUCKY_CHANT,
        .comboMoves = {COMBO_STARTER_HEAL_BELL},
    },

    [MOVE_ME_FIRST] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COPYCAT] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POWER_SWAP] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GUARD_SWAP] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PUNISHMENT] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LAST_RESORT] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WORRY_SEED] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_WORRY_SEED,
        .comboMoves = {COMBO_STARTER_LEECH_SEED},
    },

    [MOVE_SUCKER_PUNCH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TOXIC_SPIKES] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEART_SWAP] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AQUA_RING] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAGNET_RISE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLARE_BLITZ] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_FORCE_PALM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AURA_SPHERE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ROCK_POLISH] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POISON_JAB] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DARK_PULSE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_NIGHT_SLASH] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AQUA_TAIL] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SEED_BOMB] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AIR_SLASH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_X_SCISSOR] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_BUG_BUZZ] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_PULSE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_RUSH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_RUSH,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_TAIL},
    },

    [MOVE_POWER_GEM] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAIN_PUNCH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_VACUUM_WAVE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FOCUS_BLAST] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_ENERGY_BALL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_BRAVE_BIRD] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_BRAVE_BIRD,
        .comboMoves = {0}
    },

    [MOVE_EARTH_POWER] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SWITCHEROO] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GIGA_IMPACT] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_NASTY_PLOT] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BULLET_PUNCH] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AVALANCHE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ICE_SHARD] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHADOW_CLAW] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_THUNDER_FANG] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_THUNDER_FANG,
        .comboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_FANG, COMBO_STARTER_ICE_FANG},
    },

    [MOVE_ICE_FANG] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_ICE_FANG,
        .comboMoves = {COMBO_STARTER_FIRE_FANG, COMBO_STARTER_THUNDER_FANG},
    },

    [MOVE_FIRE_FANG] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_FIRE_FANG,
        .comboMoves = {COMBO_STARTER_ICE_FANG, COMBO_STARTER_THUNDER_FANG},
    },

    [MOVE_SHADOW_SNEAK] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MUD_BOMB] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYCHO_CUT] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ZEN_HEADBUTT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MIRROR_SHOT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLASH_CANNON] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ROCK_CLIMB] =
    {
        .effect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DEFOG] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRICK_ROOM] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRACO_METEOR] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DISCHARGE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_LAVA_PLUME] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_LEAF_STORM] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POWER_WHIP] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_ROCK_WRECKER] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CROSS_POISON] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GUNK_SHOT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_IRON_HEAD] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAGNET_BOMB] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STONE_EDGE] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CAPTIVATE] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_STEALTH_ROCK] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GRASS_KNOT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CHATTER] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_JUDGMENT] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BUG_BITE] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CHARGE_BEAM] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_WOOD_HAMMER] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AQUA_JET] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_ATTACK_ORDER] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_ATTACK_ORDER,
        .comboMoves = {COMBO_STARTER_DEFEND_ORDER, COMBO_STARTER_HEAL_ORDER},
    },

    [MOVE_DEFEND_ORDER] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_DEFEND_ORDER,
        .comboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_HEAL_ORDER},
    },

    [MOVE_HEAL_ORDER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_HEAL_ORDER,
        .comboMoves = {COMBO_STARTER_ATTACK_ORDER, COMBO_STARTER_DEFEND_ORDER},
    },

    [MOVE_HEAD_SMASH] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DOUBLE_HIT] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ROAR_OF_TIME] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPACIAL_REND] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LUNAR_DANCE] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CRUSH_GRIP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAGMA_STORM] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_DARK_VOID] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SEED_FLARE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_OMINOUS_WIND] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHADOW_FORCE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HONE_CLAWS] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WIDE_GUARD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GUARD_SPLIT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POWER_SPLIT] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WONDER_ROOM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYSHOCK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_VENOSHOCK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TOXIC},
    },

    [MOVE_AUTOTOMIZE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_RAGE_POWDER] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TELEKINESIS] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAGIC_ROOM] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SMACK_DOWN] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STORM_THROW] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLAME_BURST] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SLUDGE_WAVE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_QUIVER_DANCE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEAVY_SLAM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SYNCHRONOISE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ELECTRO_BALL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SOAK] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLAME_CHARGE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COIL] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LOW_SWEEP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ACID_SPRAY] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FOUL_PLAY] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SIMPLE_BEAM] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ENTRAINMENT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AFTER_YOU] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ROUND] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ECHOED_VOICE] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CHIP_AWAY] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CLEAR_SMOG] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STORED_POWER] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_QUICK_GUARD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ALLY_SWITCH] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SCALD] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SCALD,
        .comboMoves = {0}
    },

    [MOVE_SHELL_SMASH] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEAL_PULSE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEX] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TOXIC},
    },

    [MOVE_SKY_DROP] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHIFT_GEAR] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CIRCLE_THROW] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_INCINERATE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_QUASH] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ACROBATICS] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_REFLECT_TYPE] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_RETALIATE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BESTOW] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_INFERNO] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WATER_PLEDGE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FIRE_PLEDGE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GRASS_PLEDGE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_VOLT_SWITCH] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STRUGGLE_BUG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BULLDOZE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FROST_BREATH] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_TAIL] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_TAIL,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH},
    },

    [MOVE_WORK_UP] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ELECTROWEB] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_WILD_CHARGE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRILL_RUN] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DUAL_CHOP] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEART_STAMP] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HORN_LEECH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SACRED_SWORD] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_RAZOR_SHELL] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEAT_CRASH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LEAF_TORNADO] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STEAMROLLER] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COTTON_GUARD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_NIGHT_DAZE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYSTRIKE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TAIL_SLAP] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HURRICANE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HEAD_CHARGE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GEAR_GRIND] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SEARING_SHOT] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TECHNO_BLAST] =
    {
        .effect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_RELIC_SONG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SECRET_SWORD] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GLACIATE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BOLT_STRIKE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BLUE_FLARE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FIERY_DANCE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FREEZE_SHOCK] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ICE_BURN] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SNARL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ICICLE_CRASH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_V_CREATE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FUSION_FLARE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FUSION_BOLT] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLYING_PRESS] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAT_BLOCK] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BELCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ROTOTILLER] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STICKY_WEB] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FELL_STINGER] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PHANTOM_FORCE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRICK_OR_TREAT] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_NOBLE_ROAR] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ION_DELUGE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FORESTS_CURSE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PETAL_BLIZZARD] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FREEZE_DRY] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DISARMING_VOICE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PARTING_SHOT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TOPSY_TURVY] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAINING_KISS] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CRAFTY_SHIELD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLOWER_SHIELD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GRASSY_TERRAIN] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_GRASSY_TERRAIN,
        .comboMoves = {0}
    },

    [MOVE_MISTY_TERRAIN] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_MISTY_TERRAIN,
        .comboMoves = {0}
    },

    [MOVE_ELECTRIFY] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PLAY_ROUGH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FAIRY_WIND] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MOONBLAST] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BOOMBURST] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FAIRY_LOCK] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_KINGS_SHIELD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PLAY_NICE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CONFIDE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DIAMOND_STORM] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STEAM_ERUPTION] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCALD},
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_HYPERSPACE_HOLE,
        .comboMoves = {COMBO_STARTER_HYPERSPACE_FURY},
    },

    [MOVE_WATER_SHURIKEN] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MYSTICAL_FIRE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPIKY_SHIELD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AROMATIC_MIST] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_EERIE_IMPULSE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_VENOM_DRENCH] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TOXIC},
    },

    [MOVE_POWDER] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GEOMANCY] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAGNETIC_FLUX] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HAPPY_HOUR] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_ELECTRIC_TERRAIN,
        .comboMoves = {0}
    },

    [MOVE_DAZZLING_GLEAM] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CELEBRATE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HOLD_HANDS] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BABY_DOLL_EYES] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_NUZZLE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HOLD_BACK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_INFESTATION] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POWER_UP_PUNCH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_OBLIVION_WING] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_THOUSAND_ARROWS] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_THOUSAND_ARROWS,
        .comboMoves = {COMBO_STARTER_THOUSAND_WAVES},
    },

    [MOVE_THOUSAND_WAVES] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_THOUSAND_WAVES,
        .comboMoves = {COMBO_STARTER_THOUSAND_ARROWS},
    },

    [MOVE_LANDS_WRATH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LIGHT_OF_RUIN] = {0}, // undefined in urpg

    [MOVE_ORIGIN_PULSE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PRECIPICE_BLADES] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_ASCENT] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HYPERSPACE_FURY] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_HYPERSPACE_FURY,
        .comboMoves = {COMBO_STARTER_HYPERSPACE_HOLE},
    },

    [MOVE_SHORE_UP] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SANDSTORM}
    },

    [MOVE_FIRST_IMPRESSION] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BANEFUL_BUNKER] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DARKEST_LARIAT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPARKLING_ARIA] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCALD},
    },

    [MOVE_ICE_HAMMER] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_FLORAL_HEALING] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STRENGTH_SAP] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SOLAR_BLADE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_LEAFAGE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_SPOTLIGHT] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TOXIC_THREAD] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TOXIC},
    },

    [MOVE_LASER_FOCUS] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GEAR_UP] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_THROAT_CHOP] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POLLEN_PUFF] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ANCHOR_SHOT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_PSYCHIC_TERRAIN,
        .comboMoves = {0}
    },

    [MOVE_LUNGE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FIRE_LASH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_POWER_TRIP] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BURN_UP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_SPEED_SWAP] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SMART_STRIKE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PURIFY] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_REVELATION_DANCE] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CORE_ENFORCER] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TROP_KICK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_INSTRUCT] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BEAK_BLAST] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CLANGING_SCALES] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_HAMMER] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_RUSH, COMBO_STARTER_DRAGON_TAIL},
    },

    [MOVE_BRUTAL_SWING] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_AURORA_VEIL] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_SHELL_TRAP] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLEUR_CANNON] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PSYCHIC_FANGS] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STOMPING_TANTRUM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SHADOW_BONE] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SHADOW_BONE,
        .comboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH},
    },

    [MOVE_ACCELEROCK] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LIQUIDATION] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_PRISMATIC_LASER] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SPECTRAL_THIEF] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MOONGEIST_BEAM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TEARFUL_LOOK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ZING_ZAP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_NATURES_MADNESS] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MULTI_ATTACK] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MIND_BLOWN] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PLASMA_FISTS] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PHOTON_GEYSER] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DYNAMAX_CANNON] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SNIPE_SHOT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_JAW_LOCK] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STUFF_CHEEKS] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_NO_RETREAT] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TAR_SHOT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MAGIC_POWDER] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_DARTS] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TEATIME] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_OCTOLOCK] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BOLT_BEAK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FISHIOUS_REND] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COURT_CHANGE] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BODY_PRESS] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DECORATE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRUM_BEATING] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SNAP_TRAP] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_PYRO_BALL] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BEHEMOTH_BASH] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_AURA_WHEEL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BREAKING_SWIPE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BRANCH_POKE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_OVERDRIVE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_APPLE_ACID] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_GRAV_APPLE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SPIRIT_BREAK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STRANGE_STEAM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LIFE_DEW] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_OBSTRUCT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FALSE_SURRENDER] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_METEOR_ASSAULT] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_ETERNABEAM] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_STEEL_BEAM] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_EXPANDING_FORCE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_PSYCHIC_TERRAIN}
    },

    [MOVE_STEEL_ROLLER] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SCALE_SHOT] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_METEOR_BEAM] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_MISTY_EXPLOSION] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MISTY_TERRAIN}
    },

    [MOVE_GRASSY_GLIDE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GRASSY_TERRAIN}
    },

    [MOVE_RISING_VOLTAGE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN}
    },

    [MOVE_TERRAIN_PULSE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ELECTRIC_TERRAIN, COMBO_STARTER_MISTY_TERRAIN, COMBO_STARTER_GRASSY_TERRAIN, COMBO_STARTER_PSYCHIC_TERRAIN},
    },

    [MOVE_SKITTER_SMACK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_BURNING_JEALOUSY] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_LASH_OUT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_POLTERGEIST] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CORROSIVE_GAS] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_COACHING] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FLIP_TURN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_TRIPLE_AXEL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DUAL_WINGBEAT] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SCORCHING_SANDS] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_JUNGLE_HEALING] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WICKED_BLOW] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_SURGING_STRIKES] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_THUNDER_CAGE] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DRAGON_ENERGY] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FREEZING_GLARE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_FIERY_WRATH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_THUNDEROUS_KICK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_GLACIAL_LANCE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_EERIE_SPELL] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0}
    },

    [MOVE_DIRE_CLAW] = {0}, // TODO

    [MOVE_PSYSHIELD_BASH] = {0}, // TODO

    [MOVE_POWER_SHIFT] = {0}, // TODO

    [MOVE_STONE_AXE] = {0}, // TODO

    [MOVE_SPRINGTIDE_STORM] = {0}, // TODO

    [MOVE_MYSTICAL_POWER] = {0}, // TODO

    [MOVE_RAGING_FURY] = {0}, // TODO

    [MOVE_WAVE_CRASH] = {0}, // TODO

    [MOVE_CHLOROBLAST] = {0}, // TODO

    [MOVE_MOUNTAIN_GALE] = {0}, // TODO

    [MOVE_VICTORY_DANCE] = {0}, // TODO

    [MOVE_HEADLONG_RUSH] = {0}, // TODO

    [MOVE_BARB_BARRAGE] = {0}, // TODO

    [MOVE_ESPER_WING] = {0}, // TODO

    [MOVE_BITTER_MALICE] = {0}, // TODO

    [MOVE_SHELTER] = {0}, // TODO

    [MOVE_TRIPLE_ARROWS] = {0}, // TODO

    [MOVE_INFERNAL_PARADE] = {0}, // TODO

    [MOVE_CEASELESS_EDGE] = {0}, // TODO

    [MOVE_BLEAKWIND_STORM] = {0}, // TODO

    [MOVE_WILDBOLT_STORM] = {0}, // TODO

    [MOVE_SANDSEAR_STORM] = {0}, // TODO

    [MOVE_LUNAR_BLESSING] = {0}, // TODO

    [MOVE_TAKE_HEART] = {0}, // TODO

    [MOVE_TERA_BLAST] = {0}, // TODO

    [MOVE_SILK_TRAP] = {0}, // TODO

    [MOVE_AXE_KICK] = {0}, // TODO

    [MOVE_LAST_RESPECTS] = {0}, // TODO

    [MOVE_LUMINA_CRASH] = {0}, // TODO

    [MOVE_ORDER_UP] = {0}, // TODO

    [MOVE_JET_PUNCH] = {0}, // TODO

    [MOVE_SPICY_EXTRACT] = {0}, // TODO

    [MOVE_SPIN_OUT] = {0}, // TODO

    [MOVE_POPULATION_BOMB] = {0}, // TODO

    [MOVE_ICE_SPINNER] = {0}, // TODO

    [MOVE_GLAIVE_RUSH] = {0}, // TODO

    [MOVE_REVIVAL_BLESSING] = {0}, // TODO

    [MOVE_SALT_CURE] = {0}, // TODO

    [MOVE_TRIPLE_DIVE] = {0}, // TODO

    [MOVE_MORTAL_SPIN] = {0}, // TODO

    [MOVE_DOODLE] = {0}, // TODO

    [MOVE_FILLET_AWAY] = {0}, // TODO

    [MOVE_KOWTOW_CLEAVE] = {0}, // TODO

    [MOVE_FLOWER_TRICK] = {0}, // TODO

    [MOVE_TORCH_SONG] = {0}, // TODO

    [MOVE_AQUA_STEP] = {0}, // TODO

    [MOVE_RAGING_BULL] = {0}, // TODO

    [MOVE_MAKE_IT_RAIN] = {0}, // TODO

    [MOVE_RUINATION] = {0}, // TODO

    [MOVE_COLLISION_COURSE] = {0}, // TODO

    [MOVE_ELECTRO_DRIFT] = {0}, // TODO

    [MOVE_SHED_TAIL] = {0}, // TODO

    [MOVE_CHILLY_RECEPTION] = {0}, // TODO

    [MOVE_TIDY_UP] = {0}, // TODO

    [MOVE_SNOWSCAPE] = {0}, // TODO

    [MOVE_POUNCE] = {0}, // TODO

    [MOVE_TRAILBLAZE] = {0}, // TODO

    [MOVE_CHILLING_WATER] = {0}, // TODO

    [MOVE_HYPER_DRILL] = {0}, // TODO

    [MOVE_TWIN_BEAM] = {0}, // TODO

    [MOVE_RAGE_FIST] = {0}, // TODO

    [MOVE_ARMOR_CANNON] = {0}, // TODO

    [MOVE_BITTER_BLADE] = {0}, // TODO

    [MOVE_DOUBLE_SHOCK] = {0}, // TODO

    [MOVE_GIGATON_HAMMER] = {0}, // TODO

    [MOVE_COMEUPPANCE] = {0}, // TODO

    [MOVE_AQUA_CUTTER] = {0}, // TODO

    [MOVE_BLAZING_TORQUE] = {0}, // TODO

    [MOVE_WICKED_TORQUE] = {0}, // TODO

    [MOVE_NOXIOUS_TORQUE] = {0}, // TODO

    [MOVE_COMBAT_TORQUE] = {0}, // TODO

    [MOVE_MAGICAL_TORQUE] = {0}, // TODO

    [MOVE_PSYBLADE] = {0}, // TODO

    [MOVE_HYDRO_STEAM] = {0}, // TODO

    [MOVE_BLOOD_MOON] = {0}, // TODO

    [MOVE_MATCHA_GOTCHA] = {0}, // TODO

    [MOVE_SYRUP_BOMB] = {0}, // TODO

    [MOVE_IVY_CUDGEL] = {0}, // TODO
};

const struct ContestEffect gContestEffects[] =
{
    [CONTEST_EFFECT_HIGHLY_APPEALING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 40,
        .jam = 0,
    },
    [CONTEST_EFFECT_USER_MORE_EASILY_STARTLED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 60,
        .jam = 0,
    },
    [CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 80,
        .jam = 0,
    },
    [CONTEST_EFFECT_REPETITION_NOT_BORING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_ONCE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_USER_LESS_EASILY_STARTLED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_STARTLE_FRONT_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
    },
    [CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 20,
        .jam = 30,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 20,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 10,
        .jam = 40,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 10,
        .jam = 30,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON_2] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS_2] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 40,
        .jam = 40,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_BETTER_IF_FIRST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_LAST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_WHEN_LATER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_SAME_TYPE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_DIFF_TYPE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_EARLIER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_LATER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_DONT_EXCITE_AUDIENCE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
};

void (*const gContestEffectFuncs[])(void) =
{
    ContestEffect_HighlyAppealing,
    ContestEffect_UserMoreEasilyStartled,
    ContestEffect_GreatAppealButNoMoreMoves,
    ContestEffect_RepetitionNotBoring,
    ContestEffect_AvoidStartleOnce,
    ContestEffect_AvoidStartle,
    ContestEffect_AvoidStartleSlightly,
    ContestEffect_UserLessEasilyStartled,
    ContestEffect_StartleFrontMon,
    ContestEffect_StartlePrevMons,
    ContestEffect_StartleFrontMon,
    ContestEffect_StartlePrevMons,
    ContestEffect_StartleFrontMon,
    ContestEffect_StartlePrevMons,
    ContestEffect_StartlePrevMon2,
    ContestEffect_StartlePrevMons2,
    ContestEffect_ShiftJudgeAttention,
    ContestEffect_StartleMonWithJudgesAttention,
    ContestEffect_JamsOthersButMissOneTurn,
    ContestEffect_StartleMonsSameTypeAppeal,
    ContestEffect_StartleMonsCoolAppeal,
    ContestEffect_StartleMonsBeautyAppeal,
    ContestEffect_StartleMonsCuteAppeal,
    ContestEffect_StartleMonsSmartAppeal,
    ContestEffect_StartleMonsToughAppeal,
    ContestEffect_MakeFollowingMonNervous,
    ContestEffect_MakeFollowingMonsNervous,
    ContestEffect_WorsenConditionOfPrevMons,
    ContestEffect_BadlyStartlesMonsInGoodCondition,
    ContestEffect_BetterIfFirst,
    ContestEffect_BetterIfLast,
    ContestEffect_AppealAsGoodAsPrevOnes,
    ContestEffect_AppealAsGoodAsPrevOne,
    ContestEffect_BetterWhenLater,
    ContestEffect_QualityDependsOnTiming,
    ContestEffect_BetterIfSameType,
    ContestEffect_BetterIfDiffType,
    ContestEffect_AffectedByPrevAppeal,
    ContestEffect_ImproveConditionPreventNervousness,
    ContestEffect_BetterWithGoodCondition,
    ContestEffect_NextAppealEarlier,
    ContestEffect_NextAppealLater,
    ContestEffect_MakeScramblingTurnOrderEasier,
    ContestEffect_ScrambleNextTurnOrder,
    ContestEffect_ExciteAudienceInAnyContest,
    ContestEffect_BadlyStartleMonsWithGoodAppeals,
    ContestEffect_BetterWhenAudienceExcited,
    ContestEffect_DontExciteAudience,
};
