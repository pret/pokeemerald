const struct BattleMove gBattleMoves[MOVES_COUNT_Z] =
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VISE_GRIP] =
    {
        .effect = EFFECT_HIT,
        .power = 55,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAZOR_WIND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWORDS_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_ATTACK_UP_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_2X_IN_AIR,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WHIRLWIND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 0,
            .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_FLY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 90,
            .zMovePower = 175,
        #else
            .power = 70,
            .zMovePower = 140,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BIND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 85,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_TRAP,
        .power = 15,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VINE_WHIP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 45,
            .pp = 25,
        #elif B_UPDATED_MOVE_DATA == GEN_4 || B_UPDATED_MOVE_DATA == GEN_5
            .power = 35,
            .pp = 15,
        #else
            .power = 35,
            .pp = 10,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STOMP] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 65,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_KICK] =
    {
        .effect = EFFECT_HIT,
        .power = 30,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JUMP_KICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 100,
            .pp = 10,
            .zMovePower = 180,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 85,
            .pp = 25,
            .zMovePower = 160,
        #else
            .power = 70,
            .pp = 25,
            .zMovePower = 140,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROLLING_KICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_FIGHTING,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TACKLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 40,
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5 || B_UPDATED_MOVE_DATA == GEN_6
            .power = 50,
            .accuracy = 100,
        #else
            .power = 35,
            .accuracy = 95,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_NORMAL,
        .pp = 35,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BODY_SLAM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .power = 85,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WRAP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 90,
        #else
            .accuracy = 85,
        #endif
        .effect = EFFECT_TRAP,
        .power = 15,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAKE_DOWN] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 85,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THRASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
            .zMovePower = 190,
        #else
            .power = 90,
            .pp = 20,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_EDGE] =
    {
        .effect = EFFECT_RECOIL_33,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TWINEEDLE] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 25,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PIN_MISSILE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 25,
            .accuracy = 95,
        #else
            .power = 14,
            .accuracy = 85,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .type = TYPE_BUG,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ROAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 0,
            .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        #endif
        .effect = EFFECT_ROAR,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -6,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DISABLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 80,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 55,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_DISABLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ACID] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        #else
            .effect = EFFECT_DEFENSE_DOWN_HIT,
        #endif
        .power = 40,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLAMETHROWER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYDRO_PUMP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SURF] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
            .target = MOVE_TARGET_FOES_AND_ALLY,
        #elif B_UPDATED_MOVE_DATA == GEN_4 || B_UPDATED_MOVE_DATA == GEN_5
            .power = 95,
            .target = MOVE_TARGET_FOES_AND_ALLY,
        #else
            .power = 95,
            .target = MOVE_TARGET_BOTH,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_UNDERWATER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_BEAM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_FREEZE_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLIZZARD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_FREEZE_HIT,
        .type = TYPE_ICE,
        .accuracy = 70,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SUBMISSION] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 25,
        #endif
        .effect = EFFECT_RECOIL_25,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 80,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COUNTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .flags = FLAG_MAKES_CONTACT,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_COUNTER,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ABSORB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 25,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_ABSORB,
        .power = 20,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MEGA_DRAIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 15,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_ABSORB,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_GROWTH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 40,
        #endif
        #if B_GROWTH_STAT_RAISE >= GEN_5
            .effect = EFFECT_GROWTH,
        #else
            .effect = EFFECT_SPECIAL_ATTACK_UP,
        #endif
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SOLAR_BEAM] =
    {
        .effect = EFFECT_SOLAR_BEAM,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_PETAL_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
            .zMovePower = 190,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 90,
            .pp = 20,
            .zMovePower = 175,
        #else
            .power = 70,
            .pp = 20,
            .zMovePower = 140,
        #endif
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCE,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRING_SHOT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .effect = EFFECT_SPEED_DOWN_2,
        #else
            .effect = EFFECT_SPEED_DOWN,
        #endif
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_SPIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 35,
            .accuracy = 85,
        #else
            .power = 15,
            .accuracy = 70,
        #endif
        .effect = EFFECT_TRAP,
        .type = TYPE_FIRE,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,

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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDERBOLT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_WAVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 90,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_THUNDER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_THUNDER,
        .type = TYPE_ELECTRIC,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_IN_AIR,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 60,
            .zMovePower = 120,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TOXIC] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 90,
        #else
            .accuracy = 85,
        #endif
        .effect = EFFECT_TOXIC,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .priority = -6,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIMIC] =
    {
        .effect = EFFECT_MIMIC,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_RECOVER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #elif B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MINIMIZE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 10,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_MINIMIZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_BARRIER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_HAZE] =
    {
        .effect = EFFECT_HAZE,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_BIDE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .priority = 1,
        #else
            .accuracy = 100,
            .priority = 0,
        #endif
        .effect = EFFECT_BIDE,
        .power = 1,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_2,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 30,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SMOG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 30,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_POISON_HIT,
        .type = TYPE_POISON,
        .accuracy = 70,
        .pp = 20,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_BLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATERFALL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .effect = EFFECT_FLINCH_HIT,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .effect = EFFECT_FLINCH_HIT,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .effect = EFFECT_HIT,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLAMP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 85,
            .pp = 15,
        #else
            .accuracy = 75,
            .pp = 10,
        #endif
        .effect = EFFECT_TRAP,
        .power = 35,
        .type = TYPE_WATER,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKULL_BASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
            .pp = 10,
            .zMovePower = 195,
        #else
            .power = 100,
            .pp = 15,
            .zMovePower = 180,
        #endif
        .effect = EFFECT_SKULL_BASH,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_KINESIS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 80,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_SOFT_BOILED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HIGH_JUMP_KICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 130,
            .pp = 10,
            .zMovePower = 195,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 100,
            .pp = 20,
            .zMovePower = 180,
        #else
            .power = 85,
            .pp = 20,
            .zMovePower = 60,
        #endif
        .effect = EFFECT_RECOIL_IF_MISS,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLARE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 90,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_PARALYZE,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POISON_GAS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 90,
            .target = MOVE_TARGET_BOTH,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 80,
            .target = MOVE_TARGET_BOTH,
        #else
            .accuracy = 55,
            .target = MOVE_TARGET_SELECTED,
        #endif
        .effect = EFFECT_POISON,
        .power = 0,
        .type = TYPE_POISON,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEECH_LIFE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 80,
            .pp = 10,
            .zMovePower = 160,
        #else
            .power = 20,
            .pp = 15,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_BUG,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SKY_ATTACK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_TWO_TURNS_ATTACK,
        .power = 140,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_FLINCH,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_BUBBLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_SPEED_DOWN_HIT,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_FLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 100,
        #else
            .accuracy = 70,
        #endif
        .effect = EFFECT_ACCURACY_DOWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_PSYWAVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_PSYWAVE,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_3,
    },

    [MOVE_ACID_ARMOR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
        #else
            .pp = 40,
        #endif
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_CRABHAMMER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 100,
            .accuracy = 90,
            .zMovePower = 180,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 90,
            .accuracy = 90,
            .zMovePower = 175,
        #else
            .power = 90,
            .accuracy = 85,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_WATER,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BONEMERANG] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_GROUND,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_REST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_REST,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_STRONG_JAW_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_CONVERSION] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_CONVERSION,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_STRUGGLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .effect = EFFECT_RECOIL_HP_25,
        #else
            .accuracy = 100,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .effect = EFFECT_RECOIL_25,
        #endif
        .power = 50,
        .type = TYPE_NORMAL,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THIEF] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .pp = 25,
            .zMovePower = 120,
        #else
            .power = 40,
            .pp = 10,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_THIEF,
        .type = TYPE_DARK,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIDER_WEB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MIND_READER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_NIGHTMARE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 100,
        #else
            .accuracy = 0,
        #endif
        .effect = EFFECT_NIGHTMARE,
        .power = 0,
        .type = TYPE_GHOST,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_FLAME_WHEEL] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 60,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 50,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 40,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        #else
            .power = 40,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        #endif
        .effect = EFFECT_SNORE,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CURSE] =
    {
        #if B_UPDATED_MOVE_TYPES >= GEN_5
            .type = TYPE_GHOST,
        #else
            .type = TYPE_MYSTERY,
        #endif
        .effect = EFFECT_CURSE,
        .power = 0,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_CURSE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CONVERSION_2] =
    {
        .effect = EFFECT_CONVERSION_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COTTON_SPORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
            .target = MOVE_TARGET_BOTH,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .accuracy = 100,
            .target = MOVE_TARGET_SELECTED,
        #else
            .accuracy = 85,
            .target = MOVE_TARGET_SELECTED,
        #endif
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_GRASS,
        .pp = 40,
        .secondaryEffectChance = 0,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPITE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_SPITE,
        .power = 0,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PROTECT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SCARY_FACE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 100,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_SPEED_DOWN_2,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_FEINT_ATTACK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWEET_KISS] =
    {
        #if B_UPDATED_MOVE_TYPES >= GEN_6
            .type = TYPE_FAIRY,
        #else
            .type = TYPE_NORMAL,
        #endif
        .effect = EFFECT_CONFUSE,
        .power = 0,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIKES] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_SPIKES,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ZAP_CANNON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 120,
            .zMovePower = 190,
        #else
            .power = 100,
            .zMovePower = 180,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 50,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORESIGHT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_FOLLOW_ME,
    },

    [MOVE_PERISH_SONG] =
    {
        .effect = EFFECT_PERISH_SONG,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DETECT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_BONE_RUSH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 90,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_GROUND,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LOCK_ON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .accuracy = 0,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_LOCK_ON,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_OUTRAGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 120,
            .pp = 10,
            .zMovePower = 190,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 120,
            .pp = 15,
            .zMovePower = 190,
        #else
            .power = 90,
            .pp = 15,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SANDSTORM] =
    {
        .effect = EFFECT_SANDSTORM,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_GIGA_DRAIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 75,
            .pp = 10,
            .zMovePower = 140,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 60,
            .pp = 10,
            .zMovePower = 120,
        #else
            .power = 60,
            .pp = 5,
            .zMovePower = 120,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ENDURE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 4,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_ENDURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_CHARM] =
    {
        #if B_UPDATED_MOVE_TYPES >= GEN_6
            .type = TYPE_FAIRY,
        #else
            .type = TYPE_NORMAL,
        #endif
        .effect = EFFECT_ATTACK_DOWN_2,
        .power = 0,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWAGGER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 85,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_SWAGGER,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_MILK_DRINK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_SOFTBOILED,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FURY_CUTTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 40,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 20,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_FURY_CUTTER,
        .type = TYPE_BUG,
        .accuracy = 95,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MEAN_LOOK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_HEAL_BELL] =
    {
        #if B_UPDATED_MOVE_DATA != GEN_5
            .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_HEAL_BELL,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_SACRED_FIRE] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 100,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_UNDERGROUND,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ENCORE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_ENCORE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAPID_SPIN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 50,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_RAPID_SPIN,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SWEET_SCENT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .effect = EFFECT_EVASION_DOWN_2,
        #else
            .effect = EFFECT_EVASION_DOWN,
        #endif
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
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
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VITAL_THROW] =
    {
        .effect = EFFECT_VITAL_THROW,
        .power = 70,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_MOONLIGHT] =
    {
        #if B_UPDATED_MOVE_TYPES >= GEN_6
            .type = TYPE_FAIRY,
        #else
            .type = TYPE_NORMAL,
        #endif
        .effect = EFFECT_MOONLIGHT,
        .power = 0,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HIDDEN_POWER] =
    {
        #if B_HIDDEN_POWER_DMG >= GEN_6
            .power = 60,
        #else
            .power = 1,
        #endif
        .effect = EFFECT_HIDDEN_POWER,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TWISTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_2X_IN_AIR,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_2X_IN_AIR,
        #endif
        .effect = EFFECT_TWISTER,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAIN_DANCE] =
    {
        .effect = EFFECT_RAIN_DANCE,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SUNNY_DAY] =
    {
        .effect = EFFECT_SUNNY_DAY,
        .power = 0,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_CRUNCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_DEFENSE_DOWN_HIT,
        #else
            .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        #endif
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIRROR_COAT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .flags = 0,
        #else
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MIRROR_COAT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = -5,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCH_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = 0,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_PSYCH_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_EXTREME_SPEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 2,
        #else
            .priority = 1,
        #endif
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ANCIENT_POWER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 60,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FUTURE_SIGHT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
            .accuracy = 100,
            .pp = 10,
            .zMovePower = 190,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 100,
            .accuracy = 100,
            .pp = 10,
            .zMovePower = 180,
        #else
            .power = 80,
            .accuracy = 90,
            .pp = 15,
            .zMovePower = 160,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_PSYCHIC,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROCK_SMASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 40,
        #else
            .power = 20,
        #endif
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WHIRLPOOL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 35,
            .accuracy = 85,
        #else
            .power = 15,
            .accuracy = 70,
        #endif
        .effect = EFFECT_TRAP,
        .type = TYPE_WATER,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_UNDERWATER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BEAT_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 1,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_BEAT_UP,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FAKE_OUT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .priority = 3,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .priority = 1,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .priority = 1,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_FAKE_OUT,
        .power = 40,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_UPROAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 90,
            .zMovePower = 175,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_UPROAR,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STOCKPILE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .pp = 20,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_STOCKPILE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
    },

    [MOVE_SPIT_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 1,
        #else
            .power = 100,
        #endif
        .effect = EFFECT_SPIT_UP,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEAT_WAVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 95,
            .zMovePower = 175,
        #else
            .power = 100,
            .zMovePower = 180,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HAIL] =
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_TORMENT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_TORMENT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_WILL_O_WISP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 85,
        #else
            .accuracy = 75,
        #endif
        .effect = EFFECT_WILL_O_WISP,
        .power = 0,
        .type = TYPE_FIRE,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESTORE_REPLACEMENT_HP,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SMELLING_SALTS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 70,
            .zMovePower = 140,
        #else
            .power = 60,
            .zMovePower = 120,
        #endif
        .effect = EFFECT_SMELLINGSALT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FOLLOW_ME] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 2,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_NATURE_POWER] =
    {
        .effect = EFFECT_NATURE_POWER,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_TAUNT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED,
        #endif
        .effect = EFFECT_TAUNT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_HELPING_HAND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .target = MOVE_TARGET_ALLY,
        #else
            .target = MOVE_TARGET_USER,
        #endif
        .effect = EFFECT_HELPING_HAND,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .priority = 5,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_ROLE_PLAY] =
    {
        .effect = EFFECT_ROLE_PLAY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_WISH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_WISH,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_RECYCLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_RECYCLE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_YAWN] =
    {
        .effect = EFFECT_YAWN,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_KNOCK_OFF] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
            .zMovePower = 120,
        #else
            .power = 20,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_KNOCK_OFF,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKILL_SWAP] =
    {
        .effect = EFFECT_SKILL_SWAP,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_IMPRISON] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_SNATCH_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED,
        #endif
        .effect = EFFECT_IMPRISON,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_FOLLOW_ME,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIVE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 60,
            .zMovePower = 120,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
    },

    [MOVE_TAIL_GLOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .effect = EFFECT_SPECIAL_ATTACK_UP_3,
        #else
            .effect = EFFECT_SPECIAL_ATTACK_UP_2,
        #endif
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_TEETER_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DANCE,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_DANCE,
        #endif
        .effect = EFFECT_TEETER_DANCE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MUD_SPORT] =
    {
        .effect = EFFECT_MUD_SPORT,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NEEDLE_ARM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SLACK_OFF] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_RESTORE_HP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POISON_FANG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .secondaryEffectChance = 50,
        #else
            .secondaryEffectChance = 30,
        #endif
        .effect = EFFECT_POISON_FANG,
        .power = 50,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METEOR_MASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
            .accuracy = 90,
            .zMovePower = 175,
        #else
            .power = 100,
            .accuracy = 85,
            .zMovePower = 180,
        #endif
        .effect = EFFECT_ATTACK_UP_HIT,
        .type = TYPE_STEEL,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ASTONISH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 30,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_AIR_CUTTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .zMovePower = 120,
        #else
            .power = 55,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OVERHEAT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 195,
        #elif B_UPDATED_MOVE_DATA == GEN_4 || B_UPDATED_MOVE_DATA == GEN_5
            .power = 140,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 200,
        #else
            .power = 140,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 200,
        #endif
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ODOR_SLEUTH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .accuracy = 0,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_FORESIGHT,
        .power = 0,
        .type = TYPE_NORMAL,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_ROCK_TOMB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .accuracy = 95,
            .pp = 15,
            .zMovePower = 120,
        #else
            .power = 50,
            .accuracy = 80,
            .pp = 10,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_SPEED_DOWN_HIT,
        .type = TYPE_ROCK,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EXTRASENSORY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #elif B_UPDATED_MOVE_DATA == GEN_4 || B_UPDATED_MOVE_DATA == GEN_5
            .pp = 30,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .pp = 30,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_DMG_IN_AIR,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SAND_TOMB] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 35,
            .accuracy = 85,
        #else
            .power = 15,
            .accuracy = 70,
        #endif
        .effect = EFFECT_TRAP,
        .type = TYPE_GROUND,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MUDDY_WATER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_ACCURACY_DOWN_HIT,
        .type = TYPE_WATER,
        .accuracy = 85,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BULLET_SEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 25,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICICLE_SPEAR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 25,
        #else
            .power = 10,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_BLOCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MEAN_LOOK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_HOWL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_ATTACK_UP,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COVET] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .pp = 25,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
            .zMovePower = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 60,
            .pp = 40,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
            .zMovePower = 120,
        #elif B_UPDATED_MOVE_DATA == GEN_4
            .power = 40,
            .pp = 40,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
            .zMovePower = 100,
        #else
            .power = 40,
            .pp = 40,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_THIEF,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VOLT_TACKLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_RECOIL_33_STATUS,
            .argument = STATUS1_PARALYSIS,
        #else
            .effect = EFFECT_RECOIL_33,
        #endif
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_SPORT] =
    {
        .effect = EFFECT_WATER_SPORT,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_LEAF_BLADE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .power = 90,
            .zMovePower = 175,
        #else
            .power = 70,
            .zMovePower = 140,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_ROCK_BLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 90,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        #elif B_UPDATED_MOVE_DATA == GEN_5 || B_UPDATED_MOVE_DATA == GEN_6
            .accuracy = 90,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #else
            .accuracy = 80,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .power = 25,
        .type = TYPE_ROCK,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOOM_DESIRE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 140,
            .accuracy = 100,
            .zMovePower = 200,
        #else
            .power = 120,
            .accuracy = 85,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_FUTURE_SIGHT,
        .type = TYPE_STEEL,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROOST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_ROOST,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_GRAVITY] =
    {
        .effect = EFFECT_GRAVITY,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_MIRACLE_EYE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_MIRACLE_EYE,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_WAKE_UP_SLAP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 70,
            .zMovePower = 140,
        #else
            .power = 60,
            .zMovePower = 120,
        #endif
        .effect = EFFECT_WAKE_UP_SLAP,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_SLEEP,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HAMMER_ARM] =
    {
        .effect = EFFECT_HAMMER_ARM,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEALING_WISH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FEINT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 30,
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #elif B_UPDATED_MOVE_DATA >= GEN_5
            .power = 30,
            .flags = 0,
        #else
            .power = 50,
            .flags = 0,
        #endif
        .effect = EFFECT_FEINT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PLUCK] =
    {
        .effect = EFFECT_BUG_BITE,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAILWIND] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 15,
        #else
            .pp = 30,
        #endif
        .effect = EFFECT_TAILWIND,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_ACUPRESSURE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = 0,
        #else
            .flags = FLAG_SNATCH_AFFECTED,
        #endif
        .effect = EFFECT_ACUPRESSURE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER | MOVE_TARGET_ALLY,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_METAL_BURST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_METAL_BURST,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ASSURANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .zMovePower = 120,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_ASSURANCE,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EMBARGO] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_EMBARGO,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHO_SHIFT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 100,
        #else
            .accuracy = 90,
        #endif
        .effect = EFFECT_PSYCHO_SHIFT,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_2,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_HEAL_BLOCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_HEAL_BLOCK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_2,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
    },

    [MOVE_POWER_TRICK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_LUCKY_CHANT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_LUCKY_CHANT,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 30,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LAST_RESORT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 140,
            .zMovePower = 200,
        #else
            .power = 130,
            .zMovePower = 195,
        #endif
        .effect = EFFECT_LAST_RESORT,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SUCKER_PUNCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 70,
            .zMovePower = 140,
        #else
            .power = 80,
            .zMovePower = 160,
        #endif
        .effect = EFFECT_SUCKER_PUNCH,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TOXIC_SPIKES] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_TOXIC_SPIKES,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_BOOST_CRITS,
    },

    [MOVE_AQUA_RING] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_AQUA_RING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MAGNET_RISE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_SNATCH_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_MAGNET_RISE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_EVSN_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_RECKLESS_BOOST | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_BURN,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURA_SPHERE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 90,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DARK_PULSE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_MEGA_LAUNCHER_BOOST,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_MEGA_LAUNCHER_BOOST,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AIR_SLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 75,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_PULSE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 85,
            .zMovePower = 160,
        #else
            .power = 90,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_RUSH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 75,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_GEM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 70,
            .zMovePower = 140,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAIN_PUNCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .power = 75,
            .pp = 10,
            .zMovePower = 140,
        #else
            .power = 60,
            .pp = 5,
            .zMovePower = 120,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ENERGY_BALL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 90,
            .zMovePower = 175,
        #else
            .power = 80,
            .zMovePower = 160,
        #endif
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BRAVE_BIRD] =
    {
        .effect = EFFECT_RECOIL_33,
        .power = 120,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_FANG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        #endif
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ELECTRIC,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_PARALYSIS,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_FANG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        #endif
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_ICE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_FREEZE,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_FANG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_STRONG_JAW_BOOST,
        #endif
        .effect = EFFECT_FLINCH_STATUS,
        .power = 65,
        .type = TYPE_FIRE,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = STATUS1_BURN,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DEFOG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_DEFOG,
        .power = 0,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_TRICK_ROOM] =
    {
        .effect = EFFECT_TRICK_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = -7,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ACC_UP_1,
    },

    [MOVE_DRACO_METEOR] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
            .zMovePower = 195,
        #else
            .power = 140,
            .zMovePower = 200,
        #endif
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LEAF_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 130,
            .zMovePower = 195,
        #else
            .power = 140,
            .zMovePower = 200,
        #endif
        .effect = EFFECT_OVERHEAT,
        .type = TYPE_GRASS,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GUNK_SHOT] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .accuracy = 80,
        #else
            .accuracy = 70,
        #endif
        .effect = EFFECT_POISON_HIT,
        .power = 120,
        .type = TYPE_POISON,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_IRON_HEAD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 80,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_STEALTH_ROCK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_MAGIC_COAT_AFFECTED,
        #else
            .flags = 0,
        #endif
        .effect = EFFECT_STEALTH_ROCK,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHATTER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
            .secondaryEffectChance = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 60,
            .secondaryEffectChance = 10,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        #else
            .power = 60,
            .secondaryEffectChance = 31,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_CONFUSE_HIT,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JUDGMENT] =
    {
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = HOLD_EFFECT_PLATE,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BUG_BITE] =
    {
        .effect = EFFECT_BUG_BITE,
        .power = 60,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WOOD_HAMMER] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_HIT] =
    {
        .effect = EFFECT_HIT,
        .power = 35,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LUNAR_DANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_5
            .flags = FLAG_DANCE | FLAG_SNATCH_AFFECTED,
        #else
            .flags = FLAG_DANCE,
        #endif
        .effect = EFFECT_HEALING_WISH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGMA_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 100,
            .accuracy = 75,
            .zMovePower = 180,
        #elif B_UPDATED_MOVE_DATA == GEN_5
            .power = 120,
            .accuracy = 75,
            .zMovePower = 190,
        #else
            .power = 120,
            .accuracy = 70,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_TRAP,
        .type = TYPE_FIRE,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DARK_VOID] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 50,
        #else
            .accuracy = 80,
        #endif
        .effect = EFFECT_DARK_VOID,
        .power = 0,
        .type = TYPE_DARK,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_SEED_FLARE] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2,
        .power = 120,
        .type = TYPE_GRASS,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 40,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHADOW_FORCE] =
    {
        #if B_UPDATED_MOVE_DATA == GEN_6
            .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = MOVE_EFFECT_FEINT,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .flags = FLAG_PROTECTION_MOVE | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_WONDER_ROOM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 0,
        #else
            .priority = -7,
        #endif
        .effect = EFFECT_WONDER_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AUTOTOMIZE] =
    {
        .effect = EFFECT_AUTOTOMIZE,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_RAGE_POWDER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 2,
        #else
            .priority = 3,
        #endif
        .effect = EFFECT_FOLLOW_ME,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = FLAG_POWDER,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_MAGIC_ROOM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .priority = 0,
        #else
            .priority = -7,
        #endif
        .effect = EFFECT_MAGIC_ROOM,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_IN_AIR,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STORM_THROW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .zMovePower = 120,
        #else
            .power = 40,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_ALWAYS_CRIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEAVY_SLAM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SYNCHRONOISE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
            .pp = 10,
            .zMovePower = 190,
        #else
            .power = 70,
            .pp = 15,
            .zMovePower = 140,
        #endif
        .effect = EFFECT_SYNCHRONOISE,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_LOW_SWEEP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_SPEED_DOWN_HIT,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECTION_MOVE | FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ALLY_SWITCH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .priority = 2,
        #else
            .priority = 1,
        #endif
        .effect = EFFECT_ALLY_SWITCH,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
    },

    [MOVE_SCALD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .effect = EFFECT_SCALD,
        #else
            .effect = EFFECT_BURN_HIT,
        #endif
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
    },

    [MOVE_HEX] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 65,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_HEX,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKY_DROP] =
    {
        .effect = EFFECT_SKY_DROP,
        .power = 60,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INCINERATE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .zMovePower = 120,
        #else
            .power = 30,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_INCINERATE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_RETALIATE] =
    {
        .effect = EFFECT_RETALIATE,
        .power = 70,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FINAL_GAMBIT] =
    {
        .effect = EFFECT_FINAL_GAMBIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BESTOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MIRROR_MOVE_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        #endif
        .effect = EFFECT_BESTOW,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_2,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GRASS_PLEDGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 80,
            .zMovePower = 160,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_PLEDGE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRUGGLE_BUG] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 50,
        #else
            .power = 30,
        #endif
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FROST_BREATH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 60,
            .zMovePower = 120,
        #else
            .power = 40,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_ALWAYS_CRIT,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WILD_CHARGE] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 90,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DUAL_CHOP] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SACRED_SWORD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .pp = 15,
        #else
            .pp = 20,
        #endif
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEAT_CRASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_HEAT_CRASH,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEAMROLLER] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 65,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_MINIMIZE,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HURRICANE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 110,
            .zMovePower = 185,
        #else
            .power = 120,
            .zMovePower = 190,
        #endif
        .effect = EFFECT_HURRICANE,
        .type = TYPE_FLYING,
        .accuracy = 70,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_DMG_IN_AIR,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEAD_CHARGE] =
    {
        .effect = EFFECT_RECOIL_25,
        .power = 120,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GEAR_GRIND] =
    {
        .effect = EFFECT_HIT,
        .power = 50,
        .type = TYPE_STEEL,
        .accuracy = 85,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TECHNO_BLAST] =
    {
         #if B_UPDATED_MOVE_DATA >= GEN_6
            .power = 120,
            .zMovePower = 190,
        #else
            .power = 85,
            .zMovePower = 160,
        #endif
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = HOLD_EFFECT_DRIVE,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RELIC_SONG] =
    {
        .effect = EFFECT_RELIC_SONG,
        .power = 75,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = STATUS1_SLEEP,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCE | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_PARALYSIS,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .argument = MOVE_EFFECT_BURN,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 220,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLYING_PRESS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 100,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_TWO_TYPED_MOVE,
        .type = TYPE_FIGHTING,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        .split = SPLIT_PHYSICAL,
        .argument = TYPE_FLYING,
        .zMovePower = 170,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .argument = TRUE, // Protects the whole side.
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ROTOTILLER] =
    {
        .effect = EFFECT_ROTOTILLER,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
    },

    [MOVE_STICKY_WEB] =
    {
        .effect = EFFECT_STICKY_WEB,
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_OPPONENTS_FIELD,
        .priority = 0,
        .flags = FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_FELL_STINGER] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 50,
        #else
            .power = 30,
        #endif
        .effect = EFFECT_FELL_STINGER,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PHANTOM_FORCE] =
    {
        #if B_UPDATED_MOVE_DATA == GEN_6
            .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_MINIMIZE,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_SEMI_INVULNERABLE,
        .power = 90,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .argument = MOVE_EFFECT_FEINT,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_ION_DELUGE] =
    {
        .effect = EFFECT_ION_DELUGE,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 25,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 1,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_PARABOLIC_CHARGE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 65,
            .zMovePower = 120,
        #else
            .power = 50,
            .zMovePower = 100,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FORESTS_CURSE] =
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESTORE_REPLACEMENT_HP,
    },

    [MOVE_TOPSY_TURVY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .accuracy = 0,
        #else
            .accuracy = 100,
        #endif
        .effect = EFFECT_TOPSY_TURVY,
        .power = 0,
        .type = TYPE_DARK,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = 75, // restores 75% HP instead of 50% HP
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,

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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_FLOWER_SHIELD] =
    {
        .effect = EFFECT_FLOWER_SHIELD,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_GRASSY_TERRAIN] =
    {
        .effect = EFFECT_GRASSY_TERRAIN,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_MISTY_TERRAIN] =
    {
        .effect = EFFECT_MISTY_TERRAIN,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FAIRY_LOCK] =
    {
        .effect = EFFECT_FAIRY_LOCK,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_KINGS_SHIELD] =
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_DIAMOND_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_4
            .effect = EFFECT_DEFENSE_UP2_HIT,
        #else
            .effect = EFFECT_DEFENSE_UP_HIT,
        #endif
        .power = 100,
        .type = TYPE_ROCK,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 50,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WATER_SHURIKEN] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .split = SPLIT_SPECIAL,
        #else
            .split = SPLIT_PHYSICAL,
        #endif
        .effect = EFFECT_MULTI_HIT,
        .power = 15,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,

    },

    [MOVE_MYSTICAL_FIRE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_7
            .power = 75,
            .zMovePower = 140,
        #else
            .power = 65,
            .zMovePower = 120,
        #endif
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_2,
    },

    [MOVE_GEOMANCY] =
    {
        .effect = EFFECT_GEOMANCY,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
    },

    [MOVE_ELECTRIC_TERRAIN] =
    {
        .effect = EFFECT_ELECTRIC_TERRAIN,
        .power = 0,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .argument = 75, // restores 75% HP instead of 50% HP
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THOUSAND_ARROWS] =
    {
        .effect = EFFECT_SMACK_DOWN,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DMG_IN_AIR | FLAG_DMG_UNGROUNDED_IGNORE_TYPE_IF_FLYING,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LANDS_WRATH] =
    {
        .effect = EFFECT_HIT,
        .power = 90,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_RECKLESS_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPERSPACE_FURY] =
    {
        .effect = EFFECT_HYPERSPACE_FURY,
        .power = 100,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIT_IN_SUBSTITUTE,
        .split = SPLIT_PHYSICAL,
    },

    [MOVE_SHORE_UP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .pp = 5,
        #else
            .pp = 10,
        #endif
        .effect = EFFECT_SHORE_UP,
        .power = 0,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_STAT_STAGES_IGNORED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPARKLING_ARIA] =
    {
        .effect = EFFECT_SPARKLING_ARIA,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .argument = STATUS1_BURN,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ICE_HAMMER] =
    {
        .effect = EFFECT_HAMMER_ARM,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRENGTH_SAP] =
    {
        .effect = EFFECT_STRENGTH_SAP,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
    },

    [MOVE_SOLAR_BLADE] =
    {
        .effect = EFFECT_SOLAR_BEAM,
        .power = 125,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPDEF_UP_1,
    },

    [MOVE_TOXIC_THREAD] =
    {
        .effect = EFFECT_TOXIC_THREAD,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ATK_UP_1,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED |  FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHIC_TERRAIN] =
    {
        .effect = EFFECT_PSYCHIC_TERRAIN,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_LUNGE] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 80,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIRE_LASH] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BURN_UP] =
    {
        .effect = EFFECT_BURN_UP,
        .power = 130,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PURIFY] =
    {
        .effect = EFFECT_PURIFY,
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_ALL_STATS_UP_1,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCE,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPATK_UP_1,
    },

    [MOVE_BEAK_BLAST] =
    {
        .effect = EFFECT_BEAK_BLAST,
        .power = 100,
        .type = TYPE_FLYING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLANGING_SCALES] =
    {
        .effect = EFFECT_ATTACKER_DEFENSE_DOWN_HIT,
        .power = 110,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
    },

    [MOVE_SHELL_TRAP] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_SHELL_TRAP,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = -3,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYCHIC_FANGS] =
    {
        .effect = EFFECT_BRICK_BREAK,
        .power = 85,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_DEF_UP_1,
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
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
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
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MULTI_ATTACK] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 120,
            .zMovePower = 190,
        #else
            .power = 90,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_CHANGE_TYPE_ON_ITEM,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .argument = HOLD_EFFECT_MEMORY,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MIND_BLOWN] =
    {
        .effect = EFFECT_MIND_BLOWN,
        .power = 150,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PLASMA_FISTS] =
    {
        .effect = EFFECT_PLASMA_FISTS,
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PHOTON_GEYSER] =
    {
        .effect = EFFECT_PHOTON_GEYSER,
        .power = 100,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TARGET_ABILITY_IGNORED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ZIPPY_ZAP] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .effect = EFFECT_EVASION_UP_HIT,
            .pp = 10,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
            .zMovePower = 160,
        #else
            .effect = EFFECT_ALWAYS_CRIT,
            .power = 50,
            .pp = 15,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 100,
        #endif
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 2,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPLISHY_SPLASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .power = 90,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLOATY_FALL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 90,
        .type = TYPE_FLYING,
        .accuracy = 95,
        .pp = 15,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PIKA_PAPOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #else
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BOUNCY_BUBBLE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .argument = 100, // restores 100% HP instead of 50% HP
            .zMovePower = 120,
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_ABSORB,
        .type = TYPE_WATER,
        .accuracy = 100,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BUZZY_BUZZ] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 120,
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SIZZLY_SLIDE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 60,
            .pp = 20,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
            .zMovePower = 120,
        #else
            .power = 90,
            .pp = 15,
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_THAW_USER,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLITZY_GLOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .accuracy = 95,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 160,
        #else
            .power = 90,
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_GLITZY_GLOW,
        .type = TYPE_PSYCHIC,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BADDY_BAD] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 80,
            .accuracy = 95,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 160,
        #else
            .power = 90,
            .accuracy = 100,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_BADDY_BAD,
        .type = TYPE_DARK,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SAPPY_SEED] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 100,
            .accuracy = 90,
            .pp = 10,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 180,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_SAPPY_SEED,
        .type = TYPE_GRASS,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FREEZY_FROST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 100,
            .accuracy = 90,
            .pp = 10,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 180,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_FREEZY_FROST,
        .type = TYPE_ICE,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPARKLY_SWIRL] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .power = 120,
            .accuracy = 85,
            .pp = 5,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 190,
        #else
            .power = 90,
            .accuracy = 100,
            .pp = 15,
            .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
            .zMovePower = 175,
        #endif
        .effect = EFFECT_SPARKLY_SWIRL,
        .type = TYPE_FAIRY,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VEEVEE_VOLLEY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        #endif
        .effect = EFFECT_RETURN,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_IRON_BASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_8
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST | FLAG_TWO_STRIKES,
        #else
            .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_DMG_MINIMIZE | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST | FLAG_TWO_STRIKES,
        #endif
        .effect = EFFECT_FLINCH_HIT,
        .power = 60,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DYNAMAX_CANNON] =
    {
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNIPE_SHOT] =
    {
        .effect = EFFECT_SNIPE_SHOT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JAW_LOCK] =
    {
        .effect = EFFECT_JAW_LOCK,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STUFF_CHEEKS] =
    {
        .effect = EFFECT_STUFF_CHEEKS,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_NO_RETREAT] =
    {
        .effect = EFFECT_NO_RETREAT,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAR_SHOT] =
    {
        .effect = EFFECT_TAR_SHOT,
        .power = 0,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MAGIC_POWDER] =
    {
        .effect = EFFECT_SOAK,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_POWDER,
        .split = SPLIT_STATUS,
        .argument = TYPE_PSYCHIC,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_DARTS] =
    {
        .effect = EFFECT_MULTI_HIT, //TODO
        .power = 50,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TEATIME] =
    {
        .effect = EFFECT_PLACEHOLDER,   //TODO
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OCTOLOCK] =
    {
        .effect = EFFECT_OCTOLOCK,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BOLT_BEAK] =
    {
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FISHIOUS_REND] =
    {
        .effect = EFFECT_BOLT_BEAK,
        .power = 85,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_STRONG_JAW_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COURT_CHANGE] =
    {
        .effect = EFFECT_COURT_CHANGE,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CLANGOROUS_SOUL] =
    {
        .effect = EFFECT_CLANGOROUS_SOUL,
        .power = 0,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_SOUND,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BODY_PRESS] =
    {
        .effect = EFFECT_BODY_PRESS,
        .power = 80,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DECORATE] =
    {
        .effect = EFFECT_DECORATE,
        .power = 0,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRUM_BEATING] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SNAP_TRAP] =
    {
        .effect = EFFECT_TRAP,
        .power = 35,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PYRO_BALL] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_BALLISTIC | FLAG_SHEER_FORCE_BOOST | FLAG_THAW_USER,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BEHEMOTH_BLADE] =
    {
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BEHEMOTH_BASH] =
    {
        .effect = EFFECT_DYNAMAX_DOUBLE_DMG,
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AURA_WHEEL] =
    {
        .effect = EFFECT_AURA_WHEEL,
        .power = 110,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BREAKING_SWIPE] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 60,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BRANCH_POKE] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OVERDRIVE] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_APPLE_ACID] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GRAV_APPLE] =
    {
        .effect = EFFECT_GRAV_APPLE,
        .power = 80,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPIRIT_BREAK] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 75,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STRANGE_STEAM] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 90,
        .type = TYPE_FAIRY,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LIFE_DEW] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_OBSTRUCT] =
    {
        .effect = EFFECT_PROTECT,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FALSE_SURRENDER] =
    {
        .effect = EFFECT_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METEOR_ASSAULT] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 150,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ETERNABEAM] =
    {
        .effect = EFFECT_RECHARGE,
        .power = 160,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEEL_BEAM] =
    {
        .effect = EFFECT_STEEL_BEAM,
        .power = 140,
        .type = TYPE_STEEL,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EXPANDING_FORCE] =
    {
        .effect = EFFECT_EXPANDING_FORCE,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STEEL_ROLLER] =
    {
        .effect = EFFECT_REMOVE_TERRAIN,
        .power = 130,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SCALE_SHOT] =
    {
        .effect = EFFECT_SCALE_SHOT,
        .power = 25,
        .type = TYPE_DRAGON,
        .accuracy = 90,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_METEOR_BEAM] =
    {
        .effect = EFFECT_METEOR_BEAM,
        .power = 120,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHELL_SIDE_ARM] =
    {
        .effect = EFFECT_SHELL_SIDE_ARM,
        .power = 90,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MISTY_EXPLOSION] =
    {
        .effect = EFFECT_EXPLOSION,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GRASSY_GLIDE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 60,
        #else
            .power = 70,
        #endif
        .effect = EFFECT_GRASSY_GLIDE,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RISING_VOLTAGE] =
    {
        .effect = EFFECT_RISING_VOLTAGE,
        .power = 70,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TERRAIN_PULSE] =
    {
        .effect = EFFECT_TERRAIN_PULSE,
        .power = 50,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_MEGA_LAUNCHER_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SKITTER_SMACK] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_DOWN_HIT,
        .power = 70,
        .type = TYPE_BUG,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BURNING_JEALOUSY] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 70,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LASH_OUT] =
    {
        .effect = EFFECT_LASH_OUT,
        .power = 75,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POLTERGEIST] =
    {
        .effect = EFFECT_POLTERGEIST,
        .power = 110,
        .type = TYPE_GHOST,
        .accuracy = 90,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 185,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CORROSIVE_GAS] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_CORROSIVE_GAS, TODO
        .power = 0,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 40,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COACHING] =
    {
        .effect = EFFECT_COACHING,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALLY,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLIP_TURN] =
    {
        .effect = EFFECT_HIT_ESCAPE,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRIPLE_AXEL] =
    {
        .effect = EFFECT_TRIPLE_KICK,
        .power = 20,
        .type = TYPE_ICE,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DUAL_WINGBEAT] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_FLYING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SCORCHING_SANDS] =
    {
        .effect = EFFECT_SCALD,
        .power = 70,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_THAW_USER,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_JUNGLE_HEALING] =
    {
        .effect = EFFECT_JUNGLE_HEALING,
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WICKED_BLOW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 75,
        #else
            .power = 80,
        #endif
        .effect = EFFECT_ALWAYS_CRIT,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SURGING_STRIKES] =
    {
        .effect = EFFECT_ALWAYS_CRIT,
        .power = 25,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDER_CAGE] =
    {
        .effect = EFFECT_TRAP,
        .power = 80,
        .type = TYPE_ELECTRIC,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DRAGON_ENERGY] =
    {
        .effect = EFFECT_ERUPTION,
        .power = 150,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FREEZING_GLARE] =
    {
        .power = 90,
        .effect = EFFECT_FREEZE_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FIERY_WRATH] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 90,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_THUNDEROUS_KICK] =
    {
        .effect = EFFECT_DEFENSE_DOWN_HIT,
        .power = 90,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_GLACIAL_LANCE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 120,
        #else
            .power = 130,
        #endif
        .effect = EFFECT_HIT,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 195,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ASTRAL_BARRAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 120,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_EERIE_SPELL] =
    {
        .effect = EFFECT_EERIE_SPELL,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST | FLAG_SOUND,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DIRE_CLAW] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 80,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_PLACEHOLDER, // EFFECT_DIRE_CLAW,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_PSYSHIELD_BASH] =
    {
        .effect = EFFECT_DEFENSE_UP_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_POWER_SHIFT] =
    {
        .effect = EFFECT_POWER_TRICK,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_STONE_AXE] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_STONE_AXE,
        .power = 65,
        .type = TYPE_ROCK,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SPRINGTIDE_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 100,
        #else
            .power = 95,
        #endif
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .type = TYPE_FAIRY,
        .accuracy = 80,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MYSTICAL_POWER] =
    {
        .effect = EFFECT_SPECIAL_ATTACK_UP_HIT,
        .power = 70,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAGING_FURY] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 120,
        #else
            .power = 90,
        #endif
        .effect = EFFECT_RAMPAGE,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_RANDOM,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WAVE_CRASH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 120,
        #else
            .power = 75,
        #endif
        .effect = EFFECT_RECOIL_33,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHLOROBLAST] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 150,
        #else
            .power = 120,
        #endif
        .effect = EFFECT_RECOIL_50,
        .type = TYPE_GRASS,
        .accuracy = 95,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MOUNTAIN_GALE] =
    {
        .effect = EFFECT_FLINCH_HIT,
        .power = 100,
        .type = TYPE_ICE,
        .accuracy = 85,
        .pp = 5,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_VICTORY_DANCE] =
    {
        .effect = EFFECT_VICTORY_DANCE,
        .power = 0,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED | FLAG_DANCE,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HEADLONG_RUSH] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 120,
        #else
            .power = 100,
        #endif
        .effect = EFFECT_CLOSE_COMBAT,
        .type = TYPE_GROUND,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BARB_BARRAGE] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_BARB_BARRAGE,
        .power = 60,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ESPER_WING] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 80,
        #else
            .power = 75,
        #endif
        .effect = EFFECT_SPEED_UP_HIT,
        .type = TYPE_PSYCHIC,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BITTER_MALICE] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 75,
        #else
            .power = 60,
        #endif
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SHELTER] =
    {
        .effect = EFFECT_DEFENSE_UP_2,
        .power = 0,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRIPLE_ARROWS] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 90,
        #else
            .power = 50,
        #endif
        .effect = EFFECT_PLACEHOLDER, // EFFECT_TRIPLE_ARROWS,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_INFERNAL_PARADE] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_INFERNAL_PARADE,
        .power = 60,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CEASELESS_EDGE] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_CEASELESS_EDGE,
        .power = 65,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLEAKWIND_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 100,
            .pp = 10,
        #else
            .power = 95,
            .pp = 5,
        #endif
        .effect = EFFECT_SPEED_DOWN_HIT,
        .type = TYPE_FLYING,
        .accuracy = 80,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_WILDBOLT_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 100,
            .pp = 10,
        #else
            .power = 95,
            .pp = 5,
        #endif
        .effect = EFFECT_PARALYZE_HIT,
        .type = TYPE_ELECTRIC,
        .accuracy = 80,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SANDSEAR_STORM] =
    {
        #if B_UPDATED_MOVE_DATA >= GEN_9
            .power = 100,
            .pp = 10,
        #else
            .power = 95,
            .pp = 5,
        #endif
        .effect = EFFECT_BURN_HIT,
        .type = TYPE_GROUND,
        .accuracy = 80,
        .secondaryEffectChance = 20,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_LUNAR_BLESSING] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_LUNAR_BLESSING,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TAKE_HEART] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_TAKE_HEART,
        .power = 0,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TERA_BLAST] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_TERA_BLAST,
        .power = 80,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_SILK_TRAP] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_PROTECT with extra checks
        .power = 0,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 4,
        .flags = FLAG_PROTECTION_MOVE,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_AXE_KICK] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_RECOIL_IF_MISS + 30% chance to confuse
        .power = 120,
        .type = TYPE_FIGHTING,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_LAST_RESPECTS] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_LAST_RESPECTS
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_LUMINA_CRASH] =
    {
        .effect = EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2,
        .power = 80,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_ORDER_UP] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_ORDER_UP
        .power = 80,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_JET_PUNCH] =
    {
        .effect = EFFECT_HIT,
        .power = 60,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 1,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 120,
        .zMoveEffect = Z_EFFECT_NONE,
        // The datamine master sheet mentions uncopiable by Metronome but that sounds odd? not yet implemented
    },

    [MOVE_SPICY_EXTRACT] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_SPICY_EXTRACT
        .power = 0,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MAGIC_COAT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // The datamine master sheet mentions uncopiable by Metronome but that sounds odd? not yet implemented
    },

    [MOVE_SPIN_OUT] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_SPIN_OUT
        .power = 100,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_POPULATION_BOMB] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_MULTI_HIT maybe?
        .power = 20,
        .type = TYPE_NORMAL,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED, // | FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 40,
        .zMoveEffect = Z_EFFECT_NONE,
        //Supposedly uncallable by Metronome? (if so, needs implementation)
    },

    [MOVE_ICE_SPINNER] =
    {
        .effect = EFFECT_DAMAGE_SET_TERRAIN,
        .power = 80,
        .type = TYPE_ICE,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
        .argument = 1,  //remove terrain
    },

    [MOVE_GLAIVE_RUSH] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_GLAIVE_RUSH
        .power = 120,
        .type = TYPE_DRAGON,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_REVIVAL_BLESSING] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_REVIVAL_BLESSING
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_SALT_CURE] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_SALT_CURE
        .power = 40,
        .type = TYPE_ROCK,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 80,
        .zMoveEffect = Z_EFFECT_NONE,
        // Supposedly uncallable by Metronome, but dubious
    },

    [MOVE_TRIPLE_DIVE] =
    {
        .effect = EFFECT_TRIPLE_KICK,
        .power = 30,
        .type = TYPE_WATER,
        .accuracy = 95,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_MORTAL_SPIN] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_MORTAL_SPIN
        .power = 30,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 15,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 60,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_DOODLE] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_DOODLE
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_FOES_AND_ALLY, // Supposedly unconfirmed?
        .priority = 0,
        .flags = 0, // TO VERIFY
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // Supposedly uncallable by Metronome (unimplemented)
    },

    [MOVE_FILLET_AWAY] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_FILLET_AWAY
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = FLAG_SNATCH_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RECOVER_HP,
        // Supposedly uncallable by Metronome (unimplemented)
    },

    [MOVE_KOWTOW_CLEAVE] =
    {
        .effect = EFFECT_HIT,
        .power = 85,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,  // | FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_FLOWER_TRICK] =
    {
        .effect = EFFECT_ALWAYS_CRIT,
        .power = 70,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TORCH_SONG] =
    {
        .effect = EFFECT_SP_ATTACK_UP_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_SOUND | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_SPECIAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AQUA_STEP] =
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 80,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_DANCE | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAGING_BULL] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_RAGING_BULL
        .power = 90,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED, // TO VERIFY
        .split = SPLIT_PHYSICAL,
        .zMovePower = 175,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_MAKE_IT_RAIN] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_MAKE_IT_RAIN
        .power = 120,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_RUINATION] =
    {
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 90,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_COLLISION_COURSE] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_COLLISION_COURSE
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_ELECTRO_DRIFT] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_COLLISION_COURSE
        .power = 100,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_SHED_TAIL] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_SHED_TAIL
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_RESET_STATS,
        // Uncallable by Metronome (to be implemented)
    },

    [MOVE_CHILLY_RECEPTION] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_CHILLY_RECEPTION
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
        // Supposedly uncallable by Metronome? (to be implemented)
    },

    [MOVE_TIDY_UP] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_TIDY_UP
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_NONE,
        // Supposedly uncallable by Metronome? (to be implemented)
    },

    [MOVE_SNOWSCAPE] =
    {
        .effect = EFFECT_HAIL,
        .power = 0,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_ALL_BATTLERS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED,
        .split = SPLIT_STATUS,
        .zMovePower = 0,
        .zMoveEffect = Z_EFFECT_SPD_UP_1,
        // Currently an exact copy of Hail until we figure out what to do with it
    },

    [MOVE_POUNCE] =
    {
        .effect = EFFECT_SPEED_DOWN_HIT,
        .power = 50,
        .type = TYPE_BUG,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TRAILBLAZE] =
    {
        .effect = EFFECT_SPEED_UP_HIT,
        .power = 50,
        .type = TYPE_GRASS,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_CHILLING_WATER] =
    {
        .effect = EFFECT_ATTACK_DOWN_HIT,
        .power = 50,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_HYPER_DRILL] =
    {
        .effect = EFFECT_HIT,
        .power = 100,
        .type = TYPE_NORMAL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 180,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_TWIN_BEAM] =
    {
        .effect = EFFECT_HIT,
        .power = 40,
        .type = TYPE_PSYCHIC,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_TWO_STRIKES,
        .split = SPLIT_SPECIAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_RAGE_FIST] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_RAGE_FIST
        .power = 50,
        .type = TYPE_GHOST,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_IRON_FIST_BOOST | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 100,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_ARMOR_CANNON] =
    {
        .effect = EFFECT_CLOSE_COMBAT,
        .power = 120,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_SPECIAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BITTER_BLADE] =
    {
        .effect = EFFECT_ABSORB,
        .power = 90,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_MAKES_CONTACT | FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED, // | FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_DOUBLE_SHOCK] =
    {
        .effect = EFFECT_DOUBLE_SHOCK,
        .power = 120,
        .type = TYPE_ELECTRIC,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 190,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_GIGATON_HAMMER] =
    {
        .effect = EFFECT_PLACEHOLDER, // EFFECT_GIGATON_HAMMER
        .power = 160,
        .type = TYPE_STEEL,
        .accuracy = 100,
        .pp = 5,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 200,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_COMEUPPANCE] =
    {
        .effect = EFFECT_METAL_BURST,
        .power = 0,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_DEPENDS,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_AQUA_CUTTER] =
    {
        .effect = EFFECT_HIT,
        .power = 70,
        .type = TYPE_WATER,
        .accuracy = 100,
        .pp = 20,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_MIRROR_MOVE_AFFECTED | FLAG_KINGS_ROCK_AFFECTED | FLAG_HIGH_CRIT, // | FLAG_SLICING_MOVE,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 140,
        .zMoveEffect = Z_EFFECT_NONE,
    },

    [MOVE_BLAZING_TORQUE] =
    {
        .effect = EFFECT_BURN_HIT,
        .power = 80,
        .type = TYPE_FIRE,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_WICKED_TORQUE] =
    {
        .effect = EFFECT_SLEEP_HIT,
        .power = 80,
        .type = TYPE_DARK,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 10,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_NOXIOUS_TORQUE] =
    {
        .effect = EFFECT_POISON_HIT,
        .power = 100,
        .type = TYPE_POISON,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_COMBAT_TORQUE] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 100,
        .type = TYPE_FIGHTING,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    [MOVE_MAGICAL_TORQUE] =
    {
        .effect = EFFECT_CONFUSE_HIT,
        .power = 100,
        .type = TYPE_FAIRY,
        .accuracy = 100,
        .pp = 10,
        .secondaryEffectChance = 30,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_PROTECT_AFFECTED | FLAG_SHEER_FORCE_BOOST,
        .split = SPLIT_PHYSICAL,
        .zMovePower = 160,
        .zMoveEffect = Z_EFFECT_NONE
    },

    // Z-Moves
    [MOVE_BREAKNECK_BLITZ] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,    //determined from move type
        .zMoveEffect = 0
    },
    [MOVE_ALL_OUT_PUMMELING] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIGHTING,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SUPERSONIC_SKYSTRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FLYING,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_ACID_DOWNPOUR] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_POISON,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_TECTONIC_RAGE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GROUND,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CONTINENTAL_CRUSH] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SAVAGE_SPIN_OUT] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_BUG,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_NEVER_ENDING_NIGHTMARE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CORKSCREW_CRASH] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_INFERNO_OVERDRIVE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FIRE,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_HYDRO_VORTEX] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_BLOOM_DOOM] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_GRASS,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_GIGAVOLT_HAVOC] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SHATTERED_PSYCHE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_SUBZERO_SLAMMER] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_ICE,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_DEVASTATING_DRAKE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_BLACK_HOLE_ECLIPSE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_TWINKLE_TACKLE] =
    {
        .effect = EFFECT_HIT,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CATASTROPIKA] =
    {
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_10000000_VOLT_THUNDERBOLT] =
    {
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = FLAG_HIGH_CRIT,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_STOKED_SPARKSURFER] =
    {
        .effect = EFFECT_PARALYZE_HIT,
        .power = 175,
        .type = TYPE_ELECTRIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_EXTREME_EVOBOOST] =
    {
        .effect = EFFECT_EXTREME_EVOBOOST,
        .power = 0,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_USER,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_STATUS,
        .zMoveEffect = 0
    },
    [MOVE_PULVERIZING_PANCAKE] =
    {
        .effect = EFFECT_HIT,
        .power = 210,
        .type = TYPE_NORMAL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_GENESIS_SUPERNOVA] =
    {
        .effect = EFFECT_DAMAGE_SET_TERRAIN,
        .power = 185,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .argument = 0,  //psychic terrain
        .zMoveEffect = 0
    },
    [MOVE_SINISTER_ARROW_RAID] =
    {
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_MALICIOUS_MOONSAULT] =
    {
        .effect = EFFECT_HIT,
        .power = 180,
        .type = TYPE_DARK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_OCEANIC_OPERETTA] =
    {
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_WATER,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_SPLINTERED_STORMSHARDS] =
    {
        .effect = EFFECT_DAMAGE_SET_TERRAIN,
        .power = 190,
        .type = TYPE_ROCK,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .argument = 1,  //remove terrain
        .zMoveEffect = 0
    },
    [MOVE_LETS_SNUGGLE_FOREVER] =
    {
        .effect = EFFECT_HIT,
        .power = 190,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_CLANGOROUS_SOULBLAZE] =
    {
        .effect = EFFECT_ALL_STATS_UP_HIT,
        .power = 185,
        .type = TYPE_DRAGON,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 100,
        .target = MOVE_TARGET_BOTH,
        .priority = 0,
        .flags = FLAG_SOUND,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_GUARDIAN_OF_ALOLA] =
    {
        .effect = EFFECT_SUPER_FANG,
        .power = 1,
        .type = TYPE_FAIRY,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_SEARING_SUNRAZE_SMASH] =
    {
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_STEEL,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
    [MOVE_MENACING_MOONRAZE_MAELSTROM] =
    {
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_LIGHT_THAT_BURNS_THE_SKY] =
    {
        .effect = EFFECT_HIT,
        .power = 200,
        .type = TYPE_PSYCHIC,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_SPECIAL,
        .zMoveEffect = 0
    },
    [MOVE_SOUL_STEALING_7_STAR_STRIKE] =
    {
        .effect = EFFECT_HIT,
        .power = 195,
        .type = TYPE_GHOST,
        .accuracy = 0,
        .pp = 1,
        .secondaryEffectChance = 0,
        .target = MOVE_TARGET_SELECTED,
        .priority = 0,
        .flags = 0,
        .zMovePower = 0,
        .split = SPLIT_PHYSICAL,
        .zMoveEffect = 0
    },
};
