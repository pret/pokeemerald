const struct BattleMove gBattleMoves[MOVES_COUNT] =
{
    [MOVE_NONE] =
    {
        .effect = EFFECT_HIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POUND] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_KARATE_CHOP] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_SLAP] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COMET_PUNCH] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEGA_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PAY_DAY] =
    {
        .effect = EFFECT_PAY_DAY,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FIRE_PUNCH] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ICE_PUNCH] =
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 75,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THUNDER_PUNCH] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 75,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SCRATCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VICE_GRIP] =
    {
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GUILLOTINE] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAZOR_WIND] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SWORDS_DANCE] =
    {
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_CUT] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GUST] =
    {
        .effect = EFFECT_GUST,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WING_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WHIRLWIND] =
    {
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLY] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BIND] =
    {
        .effect = EFFECT_TRAP,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SLAM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VINE_WHIP] =
    {
        .effect = EFFECT_HIT,
        .power = 45,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STOMP] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_KICK] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEGA_KICK] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_JUMP_KICK] =
    {
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ROLLING_KICK] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SAND_ATTACK] =
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEADBUTT] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HORN_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FURY_ATTACK] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HORN_DRILL] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TACKLE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BODY_SLAM] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WRAP] =
    {
        .effect = EFFECT_TRAP,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TAKE_DOWN] =
    {
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THRASH] =
    {
        .effect = EFFECT_RAMPAGE,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TAIL_WHIP] =
    {
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POISON_STING] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 15,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TWINEEDLE] =
    {
        .effect = EFFECT_TWINEEDLE,
        .power = 25,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PIN_MISSILE] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEER] =
    {
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BITE] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GROWL] =
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROAR] =
    {
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_SING] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUPERSONIC] =
    {
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 55,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_SONIC_BOOM] =
    {
        .effect = EFFECT_SONICBOOM,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DISABLE] =
    {
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACID] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_EMBER] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 40,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FLAMETHROWER] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MIST] =
    {
        .effect = EFFECT_MIST,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WATER_GUN] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYDRO_PUMP] =
    {
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SURF] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERWATER,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ICE_BEAM] =
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 90,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BLIZZARD] =
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 110,
        .type = TYPE_ICE,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYBEAM] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 65,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BUBBLE_BEAM] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_AURORA_BEAM] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYPER_BEAM] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PECK] =
    {
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRILL_PECK] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SUBMISSION] =
    {
        .effect = EFFECT_RECOIL,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LOW_KICK] =
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COUNTER] =
    {
        .effect = EFFECT_COUNTER,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SEISMIC_TOSS] =
    {
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STRENGTH] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ABSORB] =
    {
        .effect = EFFECT_ABSORB,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MEGA_DRAIN] =
    {
        .effect = EFFECT_ABSORB,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LEECH_SEED] =
    {
        .effect = EFFECT_LEECH_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GROWTH] =
    {
        .effect = EFFECT_GROWTH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RAZOR_LEAF] =
    {
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SOLAR_BEAM] =
    {
        .effect = EFFECT_SOLARBEAM,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_POWDER] =
    {
        .effect = EFFECT_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 75,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_STUN_SPORE] =
    {
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_SLEEP_POWDER] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 75,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_PETAL_DANCE] =
    {
        .effect = EFFECT_RAMPAGE,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DANCE,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STRING_SHOT] =
    {
        .effect = EFFECT_SPEED_DOWN,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRAGON_RAGE] =
    {
        .effect = EFFECT_DRAGON_RAGE,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FIRE_SPIN] =
    {
        .effect = EFFECT_TRAP,
        .power = 35,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_THUNDER_SHOCK] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 40,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_THUNDERBOLT] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_THUNDER_WAVE] =
    {
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_THUNDER] =
    {
        .effect = EFFECT_THUNDER,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_THROW] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EARTHQUAKE] =
    {
        .effect = EFFECT_EARTHQUAKE,
        .power = 100,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FISSURE] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DIG] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TOXIC] =
    {
        .effect = EFFECT_TOXIC,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONFUSION] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 50,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHIC] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYPNOSIS] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 60,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MEDITATE] =
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AGILITY] =
    {
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_QUICK_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAGE] =
    {
        .effect = EFFECT_RAGE,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TELEPORT] =
    {
        .effect = EFFECT_TELEPORT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_NIGHT_SHADE] =
    {
        .effect = EFFECT_LEVEL_DAMAGE,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MIMIC] =
    {
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SCREECH] =
    {
        .effect = EFFECT_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_DOUBLE_TEAM] =
    {
        .effect = EFFECT_EVASION_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RECOVER] =
    {
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HARDEN] =
    {
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MINIMIZE] =
    {
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SMOKESCREEN] =
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONFUSE_RAY] =
    {
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WITHDRAW] =
    {
        .effect = EFFECT_DEFENSE_UP,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DEFENSE_CURL] =
    {
        .effect = EFFECT_DEFENSE_CURL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BARRIER] =
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LIGHT_SCREEN] =
    {
        .effect = EFFECT_LIGHT_SCREEN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HAZE] =
    {
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_REFLECT] =
    {
        .effect = EFFECT_REFLECT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FOCUS_ENERGY] =
    {
        .effect = EFFECT_FOCUS_ENERGY,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BIDE] =
    {
        .effect = EFFECT_BIDE,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_METRONOME] =
    {
        .effect = EFFECT_METRONOME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MIRROR_MOVE] =
    {
        .effect = EFFECT_MIRROR_MOVE,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SELF_DESTRUCT] =
    {
        .effect = EFFECT_EXPLOSION,
        .power = 200,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EGG_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LICK] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SMOG] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 20,
        .type = TYPE_POISON,
        .accuracy = 70,
        .pp = 30,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SLUDGE] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BONE_CLUB] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FIRE_BLAST] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 110,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATERFALL] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLAMP] =
    {
        .effect = EFFECT_TRAP,
        .power = 35,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWIFT] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKULL_BASH] =
    {
        .effect = EFFECT_SKULL_BASH,
        .power = 130,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPIKE_CANNON] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CONSTRICT] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 10,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 35,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AMNESIA] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_KINESIS] =
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 80,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SOFT_BOILED] =
    {
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HI_JUMP_KICK] =
    {
        .effect = EFFECT_RECOIL_IF_MISS,
        .power = 130,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GLARE] =
    {
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DREAM_EATER] =
    {
        .effect = EFFECT_DREAM_EATER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_GAS] =
    {
        .effect = EFFECT_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BARRAGE] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEECH_LIFE] =
    {
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LOVELY_KISS] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SKY_ATTACK] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_FLINCH,
    },

    [MOVE_TRANSFORM] =
    {
        .effect = EFFECT_TRANSFORM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_BUBBLE] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DIZZY_PUNCH] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPORE] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLASH] =
    {
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_PSYWAVE] =
    {
        .effect = EFFECT_PSYWAVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPLASH] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACID_ARMOR] =
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CRABHAMMER] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EXPLOSION] =
    {
        .effect = EFFECT_EXPLOSION,
        .power = 250,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FURY_SWIPES] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 18,
        .type = TYPE_NORMAL,
        .accuracy = 80,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BONEMERANG] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_REST] =
    {
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROCK_SLIDE] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 75,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HYPER_FANG] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHARPEN] =
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONVERSION] =
    {
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRI_ATTACK] =
    {
        .effect = EFFECT_TRI_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SUPER_FANG] =
    {
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SLASH] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SUBSTITUTE] =
    {
        .effect = EFFECT_SUBSTITUTE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_STRUGGLE] =
    {
        .effect = EFFECT_RECOIL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SKETCH] =
    {
        .effect = EFFECT_SKETCH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRIPLE_KICK] =
    {
        .effect = EFFECT_TRIPLE_KICK,
        .power = 10,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THIEF] =
    {
        .effect = EFFECT_THIEF,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPIDER_WEB] =
    {
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MIND_READER] =
    {
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_NIGHTMARE] =
    {
        .effect = EFFECT_NIGHTMARE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLAME_WHEEL] =
    {
        .effect = EFFECT_THAW_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SNORE] =
    {
        .effect = EFFECT_SNORE,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CURSE] =
    {
        .effect = EFFECT_CURSE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLAIL] =
    {
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CONVERSION_2] =
    {
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_AEROBLAST] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_COTTON_SPORE] =
    {
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_REVERSAL] =
    {
        .effect = EFFECT_FLAIL,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPITE] =
    {
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWDER_SNOW] =
    {
        .effect = EFFECT_FREEZE_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PROTECT] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_MACH_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SCARY_FACE] =
    {
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FAINT_ATTACK] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWEET_KISS] =
    {
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BELLY_DRUM] =
    {
        .effect = EFFECT_BELLY_DRUM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SLUDGE_BOMB] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MUD_SLAP] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 20,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_OCTAZOOKA] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPIKES] =
    {
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ZAP_CANNON] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FORESIGHT] =
    {
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DESTINY_BOND] =
    {
        .effect = EFFECT_DESTINY_BOND,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PERISH_SONG] =
    {
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_ICY_WIND] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DETECT] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_BONE_RUSH] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LOCK_ON] =
    {
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_OUTRAGE] =
    {
        .effect = EFFECT_RAMPAGE,
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SANDSTORM] =
    {
        .effect = EFFECT_SANDSTORM,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_GIGA_DRAIN] =
    {
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ENDURE] =
    {
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_CHARM] =
    {
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROLLOUT] =
    {
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FALSE_SWIPE] =
    {
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWAGGER] =
    {
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MILK_DRINK] =
    {
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SPARK] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FURY_CUTTER] =
    {
        .effect = EFFECT_FURY_CUTTER,
        .power = 40,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STEEL_WING] =
    {
        .effect = EFFECT_DEFENSE_UP_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEAN_LOOK] =
    {
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ATTRACT] =
    {
        .effect = EFFECT_ATTRACT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SLEEP_TALK] =
    {
        .effect = EFFECT_SLEEP_TALK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAL_BELL] =
    {
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_RETURN] =
    {
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PRESENT] =
    {
        .effect = EFFECT_PRESENT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FRUSTRATION] =
    {
        .effect = EFFECT_FRUSTRATION,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SAFEGUARD] =
    {
        .effect = EFFECT_SAFEGUARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_PAIN_SPLIT] =
    {
        .effect = EFFECT_PAIN_SPLIT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SACRED_FIRE] =
    {
        .effect = EFFECT_THAW_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MAGNITUDE] =
    {
        .effect = EFFECT_MAGNITUDE,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DYNAMIC_PUNCH] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MEGAHORN] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_BUG,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRAGON_BREATH] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BATON_PASS] =
    {
        .effect = EFFECT_BATON_PASS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ENCORE] =
    {
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_PURSUIT] =
    {
        .effect = EFFECT_PURSUIT,
        .power = 40,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAPID_SPIN] =
    {
        .effect = EFFECT_RAPID_SPIN,
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SWEET_SCENT] =
    {
        .effect = EFFECT_EVASION_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_IRON_TAIL] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 75,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_METAL_CLAW] =
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 35,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VITAL_THROW] =
    {
        .effect = EFFECT_VITAL_THROW,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MORNING_SUN] =
    {
        .effect = EFFECT_MORNING_SUN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SYNTHESIS] =
    {
        .effect = EFFECT_SYNTHESIS,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MOONLIGHT] =
    {
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HIDDEN_POWER] =
    {
        .effect = EFFECT_HIDDEN_POWER,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CROSS_CHOP] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TWISTER] =
    {
        .effect = EFFECT_TWISTER,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_RAIN_DANCE] =
    {
        .effect = EFFECT_RAIN_DANCE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUNNY_DAY] =
    {
        .effect = EFFECT_SUNNY_DAY,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_CRUNCH] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MIRROR_COAT] =
    {
        .effect = EFFECT_MIRROR_COAT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCH_UP] =
    {
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_EXTREME_SPEED] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ANCIENT_POWER] =
    {
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHADOW_BALL] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FUTURE_SIGHT] =
    {
        .effect = EFFECT_FUTURE_SIGHT,
        .power = 120,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_SMASH] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WHIRLPOOL] =
    {
        .effect = EFFECT_TRAP,
        .power = 35,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_UNDERWATER,
        .split = SPLIT_SPECIAL
    },

    [MOVE_BEAT_UP] =
    {
        .effect = EFFECT_BEAT_UP,
        .power = 10,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FAKE_OUT] =
    {
        .effect = EFFECT_FAKE_OUT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_UPROAR] =
    {
        .effect = EFFECT_UPROAR,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STOCKPILE] =
    {
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SPIT_UP] =
    {
        .effect = EFFECT_SPIT_UP,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SWALLOW] =
    {
        .effect = EFFECT_SWALLOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAT_WAVE] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 95,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HAIL] =
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TORMENT] =
    {
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLATTER] =
    {
        .effect = EFFECT_FLATTER,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WILL_O_WISP] =
    {
        .effect = EFFECT_WILL_O_WISP,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MEMENTO] =
    {
        .effect = EFFECT_MEMENTO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FACADE] =
    {
        .effect = EFFECT_FACADE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FOCUS_PUNCH] =
    {
        .effect = EFFECT_FOCUS_PUNCH,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SMELLING_SALT] =
    {
        .effect = EFFECT_SMELLINGSALT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
    },

    [MOVE_FOLLOW_ME] =
    {
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_NATURE_POWER] =
    {
        .effect = EFFECT_NATURE_POWER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_CHARGE] =
    {
        .effect = EFFECT_CHARGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TAUNT] =
    {
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HELPING_HAND] =
    {
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 5,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRICK] =
    {
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROLE_PLAY] =
    {
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_WISH] =
    {
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ASSIST] =
    {
        .effect = EFFECT_ASSIST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_INGRAIN] =
    {
        .effect = EFFECT_INGRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUPERPOWER] =
    {
        .effect = EFFECT_SUPERPOWER,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGIC_COAT] =
    {
        .effect = EFFECT_MAGIC_COAT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_RECYCLE] =
    {
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_REVENGE] =
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -4,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BRICK_BREAK] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_YAWN] =
    {
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_KNOCK_OFF] =
    {
        .effect = EFFECT_KNOCK_OFF,
        .power = 65,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ENDEAVOR] =
    {
        .effect = EFFECT_ENDEAVOR,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ERUPTION] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKILL_SWAP] =
    {
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_IMPRISON] =
    {
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_REFRESH] =
    {
        .effect = EFFECT_REFRESH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRUDGE] =
    {
        .effect = EFFECT_GRUDGE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SNATCH] =
    {
        .effect = EFFECT_SNATCH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 4,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SECRET_POWER] =
    {
        .effect = EFFECT_SECRET_POWER,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DIVE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ARM_THRUST] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CAMOUFLAGE] =
    {
        .effect = EFFECT_CAMOUFLAGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TAIL_GLOW] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_UP_3,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LUSTER_PURGE] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MIST_BALL] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FEATHER_DANCE] =
    {
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_TEETER_DANCE] =
    {
        .effect = EFFECT_TEETER_DANCE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_BLAZE_KICK] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 85,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MUD_SPORT] =
    {
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ICE_BALL] =
    {
        .effect = EFFECT_ROLLOUT,
        .power = 30,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_NEEDLE_ARM] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SLACK_OFF] =
    {
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HYPER_VOICE] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_FANG] =
    {
        .effect = EFFECT_POISON_FANG,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CRUSH_CLAW] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BLAST_BURN] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYDRO_CANNON] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL
    },

    [MOVE_METEOR_MASH] =
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 90,
        .type = TYPE_STEEL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ASTONISH] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WEATHER_BALL] =
    {
        .effect = EFFECT_WEATHER_BALL,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_AROMATHERAPY] =
    {
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FAKE_TEARS] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AIR_CUTTER] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_OVERHEAT] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ODOR_SLEUTH] =
    {
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROCK_TOMB] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SILVER_WIND] =
    {
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_METAL_SOUND] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRASS_WHISTLE] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 55,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_TICKLE] =
    {
        .effect = EFFECT_TICKLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_COSMIC_POWER] =
    {
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WATER_SPOUT] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SIGNAL_BEAM] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 75,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHADOW_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EXTRASENSORY] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKY_UPPERCUT] =
    {
        .effect = EFFECT_SKY_UPPERCUT,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SAND_TOMB] =
    {
        .effect = EFFECT_TRAP,
        .power = 35,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHEER_COLD] =
    {
        .effect = EFFECT_OHKO,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 30,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MUDDY_WATER] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BULLET_SEED] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AERIAL_ACE] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ICICLE_SPEAR] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_IRON_DEFENSE] =
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BLOCK] =
    {
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HOWL] =
    {
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRAGON_CLAW] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FRENZY_PLANT] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BULK_UP] =
    {
        .effect = EFFECT_BULK_UP,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BOUNCE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 85,
        .type = TYPE_FLYING,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
    },

    [MOVE_MUD_SHOT] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POISON_TAIL] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COVET] =
    {
        .effect = EFFECT_THIEF,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VOLT_TACKLE] =
    {
        .effect = EFFECT_RECOIL_33_STATUS,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
    },

    [MOVE_MAGICAL_LEAF] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_SPORT] =
    {
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_CALM_MIND] =
    {
        .effect = EFFECT_CALM_MIND,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LEAF_BLADE] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRAGON_DANCE] =
    {
        .effect = EFFECT_DRAGON_DANCE,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROCK_BLAST] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHOCK_WAVE] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_PULSE] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DOOM_DESIRE] =
    {
        .effect = EFFECT_FUTURE_SIGHT,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHO_BOOST] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 140,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROOST] =
    {
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRAVITY] =
    {
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MIRACLE_EYE] =
    {
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        .effect = EFFECT_WAKE_UP_SLAP,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_SLEEP,
    },

    [MOVE_HAMMER_ARM] =
    {
        .effect = EFFECT_HAMMER_ARM,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GYRO_BALL] =
    {
        .effect = EFFECT_GYRO_BALL,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HEALING_WISH] =
    {
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_BRINE] =
    {
        .effect = EFFECT_BRINE,
        .power = 65,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_NATURAL_GIFT] =
    {
        .effect = EFFECT_NATURAL_GIFT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FEINT] =
    {
        .effect = EFFECT_FEINT,
        .power = 30,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PLUCK] =
    {
        .effect = EFFECT_PLACEHOLDER, // Needs a custom move effect (Bug Bite and Pluck should have the same move effect)
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TAILWIND] =
    {
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACUPRESSURE] =
    {
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER | MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_METAL_BURST] =
    {
        .effect = EFFECT_METAL_BURST,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_U_TURN] =
    {
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLOSE_COMBAT] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PAYBACK] =
    {
        .effect = EFFECT_PAYBACK,
        .power = 50,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ASSURANCE] =
    {
        .effect = EFFECT_ASSURANCE,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EMBARGO] =
    {
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLING] =
    {
        .effect = EFFECT_FLING,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRUMP_CARD] =
    {
        .effect = EFFECT_TRUMP_CARD,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HEAL_BLOCK] =
    {
        .effect = EFFECT_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WRING_OUT] =
    {
        .effect = EFFECT_WRING_OUT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_TRICK] =
    {
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GASTRO_ACID] =
    {
        .effect = EFFECT_GASTRO_ACID,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LUCKY_CHANT] =
    {
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ME_FIRST] =
    {
        .effect = EFFECT_ME_FIRST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_COPYCAT] =
    {
        .effect = EFFECT_COPYCAT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWER_SWAP] =
    {
        .effect = EFFECT_POWER_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GUARD_SWAP] =
    {
        .effect = EFFECT_GUARD_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_PUNISHMENT] =
    {
        .effect = EFFECT_PUNISHMENT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LAST_RESORT] =
    {
        .effect = EFFECT_LAST_RESORT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WORRY_SEED] =
    {
        .effect = EFFECT_WORRY_SEED,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SUCKER_PUNCH] =
    {
        .effect = EFFECT_SUCKER_PUNCH,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_TOXIC_SPIKES] =
    {
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEART_SWAP] =
    {
        .effect = EFFECT_HEART_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AQUA_RING] =
    {
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MAGNET_RISE] =
    {
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLARE_BLITZ] =
    {
        .effect = EFFECT_RECOIL_33_STATUS,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_BURN,
    },

    [MOVE_FORCE_PALM] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AURA_SPHERE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_POLISH] =
    {
        .effect = EFFECT_SPEED_UP_2,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POISON_JAB] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 80,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DARK_PULSE] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_NIGHT_SLASH] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AQUA_TAIL] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SEED_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AIR_SLASH] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_X_SCISSOR] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BUG_BUZZ] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_PULSE] =
    {
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_RUSH] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POWER_GEM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAIN_PUNCH] =
    {
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_VACUUM_WAVE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FOCUS_BLAST] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ENERGY_BALL] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BRAVE_BIRD] =
    {
        .effect = EFFECT_DOUBLE_EDGE,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_EARTH_POWER] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SWITCHEROO] =
    {
        .effect = EFFECT_TRICK,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GIGA_IMPACT] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_NASTY_PLOT] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BULLET_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AVALANCHE] =
    {
        .effect = EFFECT_REVENGE,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = -4,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ICE_SHARD] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHADOW_CLAW] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THUNDER_FANG] =
    {
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
    },

    [MOVE_ICE_FANG] =
    {
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_FREEZE,
    },

    [MOVE_FIRE_FANG] =
    {
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_BURN,
    },

    [MOVE_SHADOW_SNEAK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MUD_BOMB] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHO_CUT] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ZEN_HEADBUTT] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MIRROR_SHOT] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FLASH_CANNON] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROCK_CLIMB] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DEFOG] =
    {
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TRICK_ROOM] =
    {
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = -7,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRACO_METEOR] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 130,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DISCHARGE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LAVA_PLUME] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LEAF_STORM] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 130,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_WHIP] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ROCK_WRECKER] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CROSS_POISON] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 70,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GUNK_SHOT] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_IRON_HEAD] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGNET_BOMB] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STONE_EDGE] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CAPTIVATE] =
    {
        .effect = EFFECT_CAPTIVATE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_STEALTH_ROCK] =
    {
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRASS_KNOT] =
    {
        .effect = EFFECT_LOW_KICK,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CHATTER] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 65,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_JUDGMENT] =
    {
        .effect = EFFECT_JUDGMENT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BUG_BITE] =
    {
        .effect = EFFECT_PLACEHOLDER, // Needs a custom move effect (Bug Bite and Pluck should have the same move effect)
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CHARGE_BEAM] =
    {
        .effect = EFFECT_SP_ATTACK_UP_HIT,
        .power = 50,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 70,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WOOD_HAMMER] =
    {
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AQUA_JET] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ATTACK_ORDER] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DEFEND_ORDER] =
    {
        .effect = EFFECT_COSMIC_POWER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAL_ORDER] =
    {
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAD_SMASH] =
    {
        .effect = EFFECT_RECOIL_50,
        .power = 150,
        .type = TYPE_ROCK,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DOUBLE_HIT] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ROAR_OF_TIME] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPACIAL_REND] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_LUNAR_DANCE] =
    {
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_CRUSH_GRIP] =
    {
        .effect = EFFECT_WRING_OUT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MAGMA_STORM] =
    {
        .effect = EFFECT_TRAP,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 75,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DARK_VOID] =
    {
        .effect = EFFECT_SLEEP,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 50,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SEED_FLARE] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_2,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_OMINOUS_WIND] =
    {
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHADOW_FORCE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HONE_CLAWS] =
    {
        .effect = EFFECT_ATTACK_ACCURACY_UP,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WIDE_GUARD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_GUARD_SPLIT] =
    {
        .effect = EFFECT_GUARD_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWER_SPLIT] =
    {
        .effect = EFFECT_POWER_SPLIT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_WONDER_ROOM] =
    {
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PSYSHOCK] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_VENOSHOCK] =
    {
        .effect = EFFECT_VENOSHOCK,
        .power = 65,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_AUTOTOMIZE] =
    {
        .effect = EFFECT_AUTONOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RAGE_POWDER] =
    {
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 2,
        .flags = FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_TELEKINESIS] =
    {
        .effect = EFFECT_TELEKINESIS,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_MAGIC_ROOM] =
    {
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SMACK_DOWN] =
    {
        .effect = EFFECT_SMACK_DOWN,
        .power = 50,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STORM_THROW] =
    {
        .effect = EFFECT_ALWAYS_CRIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FLAME_BURST] =
    {
        .effect = EFFECT_FLAME_BURST,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SLUDGE_WAVE] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 95,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_QUIVER_DANCE] =
    {
        .effect = EFFECT_QUIVER_DANCE,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAVY_SLAM] =
    {
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SYNCHRONOISE] =
    {
        .effect = EFFECT_SYNCHRONOISE,
        .power = 120,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ELECTRO_BALL] =
    {
        .effect = EFFECT_ELECTRO_BALL,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SOAK] =
    {
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FLAME_CHARGE] =
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 50,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COIL] =
    {
        .effect = EFFECT_COIL,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LOW_SWEEP] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 65,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ACID_SPRAY] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2,
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FOUL_PLAY] =
    {
        .effect = EFFECT_FOUL_PLAY,
        .power = 95,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SIMPLE_BEAM] =
    {
        .effect = EFFECT_SIMPLE_BEAM,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ENTRAINMENT] =
    {
        .effect = EFFECT_ENTRAINMENT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_AFTER_YOU] =
    {
        .effect = EFFECT_AFTER_YOU,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ROUND] =
    {
        .effect = EFFECT_ROUND,
        .power = 60,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ECHOED_VOICE] =
    {
        .effect = EFFECT_ECHOED_VOICE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CHIP_AWAY] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLEAR_SMOG] =
    {
        .effect = EFFECT_CLEAR_SMOG,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STORED_POWER] =
    {
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_QUICK_GUARD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_ALLY_SWITCH] =
    {
        .effect = EFFECT_PLACEHOLDER, // Needs a custom move effect
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 1,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_SCALD] =
    {
        .effect = EFFECT_SCALD,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SHELL_SMASH] =
    {
        .effect = EFFECT_SHELL_SMASH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEAL_PULSE] =
    {
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_STATUS,
    },

    [MOVE_HEX] =
    {
        .effect = EFFECT_HEX,
        .power = 65,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SKY_DROP] =
    {
        .effect = EFFECT_PLACEHOLDER, // Needs a custom move effect
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHIFT_GEAR] =
    {
        .effect = EFFECT_SHIFT_GEAR,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CIRCLE_THROW] =
    {
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_INCINERATE] =
    {
        .effect = EFFECT_INCINERATE,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_QUASH] =
    {
        .effect = EFFECT_QUASH,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ACROBATICS] =
    {
        .effect = EFFECT_ACROBATICS,
        .power = 55,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_REFLECT_TYPE] =
    {
        .effect = EFFECT_REFLECT_TYPE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_RETALIATE] =
    {
        .effect = EFFECT_RETALITATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BESTOW] =
    {
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_INFERNO] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_PLEDGE] =
    {
        .effect = EFFECT_PLEDGE,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FIRE_PLEDGE] =
    {
        .effect = EFFECT_PLEDGE,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_GRASS_PLEDGE] =
    {
        .effect = EFFECT_PLEDGE,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_VOLT_SWITCH] =
    {
        .effect = EFFECT_HIT_ESCAPE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STRUGGLE_BUG] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BULLDOZE] =
    {
        .effect = EFFECT_BULLDOZE,
        .power = 60,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FROST_BREATH] =
    {
        .effect = EFFECT_ALWAYS_CRIT,
        .power = 60,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_TAIL] =
    {
        .effect = EFFECT_HIT_SWITCH_TARGET,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_WORK_UP] =
    {
        .effect = EFFECT_ATTACK_SPATK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ELECTROWEB] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 55,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WILD_CHARGE] =
    {
        .effect = EFFECT_RECOIL,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRILL_RUN] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DUAL_CHOP] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HEART_STAMP] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HORN_LEECH] =
    {
        .effect = EFFECT_ABSORB,
        .power = 75,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SACRED_SWORD] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_RAZOR_SHELL] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 75,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HEAT_CRASH] =
    {
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEAF_TORNADO] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 65,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_STEAMROLLER] =
    {
        .effect = EFFECT_FLINCH_MINIMIZE_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_COTTON_GUARD] =
    {
        .effect = EFFECT_DEFENSE_UP_3,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_NIGHT_DAZE] =
    {
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYSTRIKE] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TAIL_SLAP] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HURRICANE] =
    {
        .effect = EFFECT_HURRICANE,
        .power = 110,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HEAD_CHARGE] =
    {
        .effect = EFFECT_RECOIL,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_GEAR_GRIND] =
    {
        .effect = EFFECT_DOUBLE_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SEARING_SHOT] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TECHNO_BLAST] =
    {
        .effect = EFFECT_TECHNO_BLAST,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_RELIC_SONG] =
    {
        .effect = EFFECT_SLEEP,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SECRET_SWORD] =
    {
        .effect = EFFECT_PSYSHOCK,
        .power = 85,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_GLACIATE] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BOLT_STRIKE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 130,
        .type = TYPE_ELECTRIC,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BLUE_FLARE] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FIERY_DANCE] =
    {
        .effect = EFFECT_SP_ATTACK_UP_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DANCE,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FREEZE_SHOCK] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
    },

    [MOVE_ICE_BURN] =
    {
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = MOVE_EFFECT_BURN,
    },

    [MOVE_SNARL] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 55,
        .type = TYPE_DARK,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ICICLE_CRASH] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 85,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_V_CREATE] =
    {
        .effect = EFFECT_V_CREATE,
        .power = 180,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FUSION_FLARE] =
    {
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FUSION_BOLT] =
    {
        .effect = EFFECT_FUSION_COMBO,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FLYING_PRESS] =
    {
        .effect = EFFECT_TWO_TYPED_MOVE,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
        .argument = TYPE_FLYING,
    },

    [MOVE_MAT_BLOCK] =
    {
        .effect = EFFECT_MAT_BLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_BELCH] =
    {
        .effect = EFFECT_BELCH,
        .power = 120,
        .type = TYPE_POISON,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ROTOTILLER] =
    {
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY | MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_STICKY_WEB] =
    {
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FELL_STINGER] =
    {
        .effect = EFFECT_FELL_STINGER,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PHANTOM_FORCE] =
    {
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_FEINT,
    },

    [MOVE_TRICK_OR_TREAT] =
    {
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_GHOST,
    },

    [MOVE_NOBLE_ROAR] =
    {
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_ION_DELUGE] =
    {
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 1,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
        .effect = EFFECT_ABSORB,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FOREST_S_CURSE] =
    {
        .effect = EFFECT_THIRD_TYPE,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TYPE_GRASS,
    },

    [MOVE_PETAL_BLIZZARD] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FREEZE_DRY] =
    {
        .effect = EFFECT_FREEZE_DRY,
        .power = 70,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DISARMING_VOICE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PARTING_SHOT] =
    {
        .effect = EFFECT_PARTING_SHOT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_TOPSY_TURVY] =
    {
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_DRAINING_KISS] =
    {
        .effect = EFFECT_ABSORB,
        .power = 50,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL, // restores 75% HP instead of 50% HP
        .argument = 75,
    },

    [MOVE_CRAFTY_SHIELD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 3,
        .flags = 0,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
    },

    [MOVE_FLOWER_SHIELD] =
    {
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER | MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_GRASSY_TERRAIN] =
    {
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MISTY_TERRAIN] =
    {
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ELECTRIFY] =
    {
        .effect = EFFECT_ELECTRIFY,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_PLAY_ROUGH] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FAIRY_WIND] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MOONBLAST] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 95,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_BOOMBURST] =
    {
        .effect = EFFECT_HIT,
        .power = 140,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FAIRY_LOCK] =
    {
        .effect = EFFECT_PLACEHOLDER, // Needs a custom move effect
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_KING_S_SHIELD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_PLAY_NICE] =
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_CONFIDE] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
    },

    [MOVE_DIAMOND_STORM] =
    {
        .effect = EFFECT_DEFENSE_UP2_HIT,
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STEAM_ERUPTION] =
    {
        .effect = EFFECT_SCALD,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HYPERSPACE_HOLE] =
    {
        .effect = EFFECT_FEINT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_WATER_SHURIKEN] =
    {
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MYSTICAL_FIRE] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 75,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPIKY_SHIELD] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_AROMATIC_MIST] =
    {
        .effect = EFFECT_AROMATIC_MIST,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_EERIE_IMPULSE] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_2,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_VENOM_DRENCH] =
    {
        .effect = EFFECT_VENOM_DRENCH,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_POWDER] =
    {
        .effect = EFFECT_POWDER,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
    },

    [MOVE_GEOMANCY] =
    {
        .effect = EFFECT_PLACEHOLDER, // Needs a custom move effect
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_MAGNETIC_FLUX] =
    {
        .effect = EFFECT_MAGNETIC_FLUX,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HAPPY_HOUR] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_DAZZLING_GLEAM] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CELEBRATE] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_HOLD_HANDS] =
    {
        .effect = EFFECT_DO_NOTHING,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_BABY_DOLL_EYES] =
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_NUZZLE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 20,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HOLD_BACK] =
    {
        .effect = EFFECT_FALSE_SWIPE,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_INFESTATION] =
    {
        .effect = EFFECT_TRAP,
        .power = 20,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_UP_PUNCH] =
    {
        .effect = EFFECT_ATTACK_UP_HIT,
        .power = 40,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_OBLIVION_WING] =
    {
        .effect = EFFECT_ABSORB,
        .power = 80,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = 75, // restores 75% HP instead of 50% HP
    },

    [MOVE_THOUSAND_ARROWS] =
    {
        .effect = EFFECT_SMACK_DOWN,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_THOUSAND_WAVES] =
    {
        .effect = EFFECT_HIT_PREVENT_ESCAPE,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LAND_S_WRATH] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LIGHT_OF_RUIN] =
    {
        .effect = EFFECT_RECOIL_50,
        .power = 140,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ORIGIN_PULSE] =
    {
        .effect = EFFECT_HIT,
        .power = 110,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PRECIPICE_BLADES] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GROUND,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DRAGON_ASCENT] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_HYPERSPACE_FURY] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_MYSTERY,
        .accuracy = 0,
        .pp = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHORE_UP] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_FIRST_IMPRESSION] =
    {
        .effect = EFFECT_FAKE_OUT,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BANEFUL_BUNKER] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
    },

    [MOVE_SPIRIT_SHACKLE] =
    {
        .effect = EFFECT_HIT_PREVENT_ESCAPE,
        .power = 80,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_DARKEST_LARIAT] =
    {
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPARKLING_ARIA] =
    {
        .effect = EFFECT_SPARKLING_ARIA,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .argument = STATUS1_BURN,
    },

    [MOVE_ICE_HAMMER] =
    {
        .effect = EFFECT_HAMMER_ARM,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FLORAL_HEALING] =
    {
        .effect = EFFECT_HEAL_PULSE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_HIGH_HORSEPOWER] =
    {
        .effect = EFFECT_HIT,
        .power = 95,
        .type = TYPE_GROUND,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STRENGTH_SAP] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SOLAR_BLADE] =
    {
        .effect = EFFECT_SOLARBEAM,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LEAFAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SPOTLIGHT] =
    {
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_TOXIC_THREAD] =
    {
        .effect = EFFECT_TOXIC_THREAD,
        .power = 20,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_LASER_FOCUS] =
    {
        .effect = EFFECT_LASER_FOCUS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_GEAR_UP] =
    {
        .effect = EFFECT_GEAR_UP,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_THROAT_CHOP] =
    {
        .effect = EFFECT_THROAT_CHOP,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POLLEN_PUFF] =
    {
        .effect = EFFECT_HIT_ENEMY_HEAL_ALLY,
        .power = 90,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_ANCHOR_SHOT] =
    {
        .effect = EFFECT_HIT_PREVENT_ESCAPE,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
    },

    [MOVE_LUNGE] =
    {
        .effect = EFFECT_ATTACK_DOWN,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_FIRE_LASH] =
    {
        .effect = EFFECT_DEFENSE_DOWN,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_POWER_TRIP] =
    {
        .effect = EFFECT_STORED_POWER,
        .power = 20,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BURN_UP] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPEED_SWAP] =
    {
        .effect = EFFECT_SPEED_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SMART_STRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PURIFY] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGICCOAT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_REVELATION_DANCE] =
    {
        .effect = EFFECT_REVELATION_DANCE,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_DANCE,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_CORE_ENFORCER] =
    {
        .effect = EFFECT_CORE_ENFORCER,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TROP_KICK] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_INSTRUCT] =
    {
        .effect = EFFECT_INSTRUCT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_BEAK_BLAST] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_CLANGING_SCALES] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_DRAGON_HAMMER] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_BRUTAL_SWING] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_AURORA_VEIL] =
    {
        .effect = EFFECT_AURORA_VEIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_SHELL_TRAP] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_FLEUR_CANNON] =
    {
        .effect = EFFECT_OVERHEAT,
        .power = 130,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_PSYCHIC_FANGS] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 75,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_STOMPING_TANTRUM] =
    {
        .effect = EFFECT_STOMPING_TANTRUM,
        .power = 75,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHADOW_BONE] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 85,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_ACCELEROCK] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_LIQUIDATION] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_PRISMATIC_LASER] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 160,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_SPECTRAL_THIEF] =
    {
        .effect = EFFECT_SPECTRAL_THIEF,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SUNSTEEL_STRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_MOONGEIST_BEAM] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_TEARFUL_LOOK] =
    {
        .effect = EFFECT_NOBLE_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAGICCOAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
    },

    [MOVE_ZING_ZAP] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_NATURES_MADNESS] =
    {
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_MULTI_ATTACK] =
    {
        .effect = EFFECT_PLACEHOLDER,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGSROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
    },
};
