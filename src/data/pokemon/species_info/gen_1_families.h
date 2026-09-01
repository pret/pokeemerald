#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen1[] =
{
#endif

#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR] =
    {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 49,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Bulbasaur"),
        .cryId = CRY_BULBASAUR,
        .natDexNum = NATIONAL_DEX_BULBASAUR,
        .categoryName = _("Seed"),
        .height = 7,
        .weight = 69,
        .description = COMPOUND_STRING(
            "Bulbasaur can be seen napping in bright\n"
            "sunlight. There is a seed on its back.\n"
            "By soaking up the sun's rays, the seed\n"
            "grows progressively larger."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bulbasaur,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Bulbasaur,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 32) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Bulbasaur,
        .shinyPalette = gMonShinyPalette_Bulbasaur,
        .iconSprite = gMonIcon_Bulbasaur,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 4,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -1, SHADOW_SIZE_S)
        FOOTPRINT(Bulbasaur)
        OVERWORLD(
            sPicTable_Bulbasaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bulbasaur,
            gShinyOverworldPalette_Bulbasaur
        )
        .levelUpLearnset = sBulbasaurLevelUpLearnset,
        .teachableLearnset = sBulbasaurTeachableLearnset,
        .eggMoveLearnset = sBulbasaurEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_IVYSAUR}),
    },

    [SPECIES_IVYSAUR] =
    {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 63,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 141,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Ivysaur"),
        .cryId = CRY_IVYSAUR,
        .natDexNum = NATIONAL_DEX_IVYSAUR,
        .categoryName = _("Seed"),
        .height = 10,
        .weight = 130,
        .description = COMPOUND_STRING(
            "To support its bulb, Ivysaur's legs\n"
            "grow sturdy. If it spends more time lying in\n"
            "the sunlight, the bud will soon bloom into\n"
            "a large flower."),
        .pokemonScale = 335,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ivysaur,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Ivysaur,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Ivysaur,
        .shinyPalette = gMonShinyPalette_Ivysaur,
        .iconSprite = gMonIcon_Ivysaur,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 4,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 3, SHADOW_SIZE_L)
        FOOTPRINT(Ivysaur)
        OVERWORLD(
            sPicTable_Ivysaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ivysaur,
            gShinyOverworldPalette_Ivysaur
        )
        .levelUpLearnset = sIvysaurLevelUpLearnset,
        .teachableLearnset = sIvysaurTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_VENUSAUR}),
    },

#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define VENUSAUR_EXP_YIELD 263
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define VENUSAUR_EXP_YIELD 236
#else
    #define VENUSAUR_EXP_YIELD 208
#endif

    [SPECIES_VENUSAUR] =
    {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 83,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
        .expYield = VENUSAUR_EXP_YIELD,
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Venusaur"),
        .cryId = CRY_VENUSAUR,
        .natDexNum = NATIONAL_DEX_VENUSAUR,
        .categoryName = _("Seed"),
        .height = 20,
        .weight = 1000,
        .description = COMPOUND_STRING(
            "Venusaur's flower is said to take on vivid\n"
            "colors if it gets plenty of nutrition and\n"
            "sunlight. The flower's aroma soothes the\n"
            "emotions of people."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Venusaur,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        .backPic = gMonBackPic_Venusaur,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 10,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Venusaur,
        .shinyPalette = gMonShinyPalette_Venusaur,
        .iconSprite = gMonIcon_Venusaur,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 4,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_VenusaurF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_VenusaurF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Venusaur)
        OVERWORLD(
            sPicTable_Venusaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Venusaur,
            gShinyOverworldPalette_Venusaur
        )
        OVERWORLD_FEMALE(
            sPicTable_VenusaurF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sVenusaurLevelUpLearnset,
        .teachableLearnset = sVenusaurTeachableLearnset,
        .formSpeciesIdTable = sVenusaurFormSpeciesIdTable,
        .formChangeTable = sVenusaurFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_VENUSAUR_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 123,
        .baseSpeed     = 80,
        .baseSpAttack  = 122,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 313 : 281,
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_THICK_FAT, ABILITY_THICK_FAT, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Venusaur"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_VENUSAUR_MEGA,
    #else
        .cryId = CRY_VENUSAUR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_VENUSAUR,
        .categoryName = _("Seed"),
        .height = 24,
        .weight = 1555,
        .description = COMPOUND_STRING(
            "In order to support its flower, which\n"
            "has grown larger due to Mega Evolution,\n"
            "its back and legs have become stronger."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_VenusaurMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_VenusaurMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_VenusaurMega,
        .shinyPalette = gMonShinyPalette_VenusaurMega,
        .iconSprite = gMonIcon_VenusaurMega,
        .iconPalIndex = 4,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Venusaur)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_VenusaurMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_VenusaurMega,
            gShinyOverworldPalette_VenusaurMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sVenusaurLevelUpLearnset,
        .teachableLearnset = sVenusaurTeachableLearnset,
        .formSpeciesIdTable = sVenusaurFormSpeciesIdTable,
        .formChangeTable = sVenusaurFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GIGANTAMAX_FORMS
    [SPECIES_VENUSAUR_GMAX] =
    {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 83,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
        .expYield = VENUSAUR_EXP_YIELD,
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Venusaur"),
        .cryId = CRY_VENUSAUR,
        .natDexNum = NATIONAL_DEX_VENUSAUR,
        .categoryName = _("Seed"),
        .height = 240,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Spits big amounts of pollen like a volcano.\n"
            "Breathing too much of it causes fainting.\n"
            "In battle, it swings around two thick vines\n"
            "that can easily topple 10-story buildings."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_VenusaurGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_VenusaurGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_VenusaurGmax,
        .shinyPalette = gMonShinyPalette_VenusaurGmax,
        .iconSprite = gMonIcon_VenusaurGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 4, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Venusaur)
        .isGigantamax = TRUE,
        .levelUpLearnset = sVenusaurLevelUpLearnset,
        .teachableLearnset = sVenusaurTeachableLearnset,
        .formSpeciesIdTable = sVenusaurFormSpeciesIdTable,
        .formChangeTable = sVenusaurFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_BULBASAUR

#if P_FAMILY_CHARMANDER
    [SPECIES_CHARMANDER] =
    {
        .baseHP        = 39,
        .baseAttack    = 52,
        .baseDefense   = 43,
        .baseSpeed     = 65,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 60 : 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 65,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charmander"),
        .cryId = CRY_CHARMANDER,
        .natDexNum = NATIONAL_DEX_CHARMANDER,
        .categoryName = _("Lizard"),
        .height = 6,
        .weight = 85,
        .description = COMPOUND_STRING(
            "The flame that burns at the tip of its\n"
            "tail is an indication of its emotions.\n"
            "The flame wavers when Charmander is\n"
            "happy, and blazes when it is enraged."),
        .pokemonScale = 444,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Charmander,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 46),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Charmander,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Charmander,
        .shinyPalette = gMonShinyPalette_Charmander,
        .iconSprite = gMonIcon_Charmander,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, 3, SHADOW_SIZE_S)
        FOOTPRINT(Charmander)
        OVERWORLD(
            sPicTable_Charmander,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Charmander,
            gShinyOverworldPalette_Charmander
        )
        .levelUpLearnset = sCharmanderLevelUpLearnset,
        .teachableLearnset = sCharmanderTeachableLearnset,
        .eggMoveLearnset = sCharmanderEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_CHARMELEON}),
    },

    [SPECIES_CHARMELEON] =
    {
        .baseHP        = 58,
        .baseAttack    = 64,
        .baseDefense   = 58,
        .baseSpeed     = 80,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 80 : 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charmeleon"),
        .cryId = CRY_CHARMELEON,
        .natDexNum = NATIONAL_DEX_CHARMELEON,
        .categoryName = _("Flame"),
        .height = 11,
        .weight = 190,
        .description = COMPOUND_STRING(
            "Without pity, its sharp claws destroy foes.\n"
            "If it encounters a strong enemy, it\n"
            "becomes agitated, and the flame on its\n"
            "tail flares with a bluish white color."),
        .pokemonScale = 302,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Charmeleon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Charmeleon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Charmeleon,
        .shinyPalette = gMonShinyPalette_Charmeleon,
        .iconSprite = gMonIcon_Charmeleon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 5, SHADOW_SIZE_M)
        FOOTPRINT(Charmeleon)
        OVERWORLD(
            sPicTable_Charmeleon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Charmeleon,
            gShinyOverworldPalette_Charmeleon
        )
        .levelUpLearnset = sCharmeleonLevelUpLearnset,
        .teachableLearnset = sCharmeleonTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_CHARIZARD}),
    },

#define CHARIZARD_SP_ATK (P_UPDATED_STATS >= GEN_2 ? 109 : 85)

#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define CHARIZARD_EXP_YIELD 267
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define CHARIZARD_EXP_YIELD 240
#else
    #define CHARIZARD_EXP_YIELD 209
#endif

    [SPECIES_CHARIZARD] =
    {
        .baseHP        = 78,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = CHARIZARD_SP_ATK,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 45,
        .expYield = CHARIZARD_EXP_YIELD,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charizard"),
        .cryId = CRY_CHARIZARD,
        .natDexNum = NATIONAL_DEX_CHARIZARD,
        .categoryName = _("Flame"),
        .height = 17,
        .weight = 905,
        .description = COMPOUND_STRING(
            "A Charizard flies about in search of\n"
            "strong opponents. It breathes intense\n"
            "flames that can melt any material. However,\n"
            "it will never torch a weaker foe."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Charizard,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Charizard,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 1,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Charizard,
        .shinyPalette = gMonShinyPalette_Charizard,
        .iconSprite = gMonIcon_Charizard,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_L)
        FOOTPRINT(Charizard)
        OVERWORLD(
            sPicTable_Charizard,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Charizard,
            gShinyOverworldPalette_Charizard
        )
        .levelUpLearnset = sCharizardLevelUpLearnset,
        .teachableLearnset = sCharizardTeachableLearnset,
        .formSpeciesIdTable = sCharizardFormSpeciesIdTable,
        .formChangeTable = sCharizardFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_CHARIZARD_MEGA_X] =
    {
        .baseHP        = 78,
        .baseAttack    = 130,
        .baseDefense   = 111,
        .baseSpeed     = 100,
        .baseSpAttack  = 130,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIRE, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 317 : 285,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_TOUGH_CLAWS, ABILITY_TOUGH_CLAWS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Charizard"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_CHARIZARD_MEGA_X,
    #else
        .cryId = CRY_CHARIZARD,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_CHARIZARD,
        .categoryName = _("Flame"),
        .height = 17,
        .weight = 1105,
        .description = COMPOUND_STRING(
            "The overwhelming power that fills its\n"
            "entire body causes it to turn black\n"
            "and creates intense blue flames."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_CharizardMegaX,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        .backPic = gMonBackPic_CharizardMegaX,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_CharizardMegaX,
        .shinyPalette = gMonShinyPalette_CharizardMegaX,
        .iconSprite = gMonIcon_CharizardMegaX,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_L)
        FOOTPRINT(Charizard)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_CharizardMegaX,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_CharizardMegaX,
            gShinyOverworldPalette_CharizardMegaX
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCharizardLevelUpLearnset,
        .teachableLearnset = sCharizardTeachableLearnset,
        .formSpeciesIdTable = sCharizardFormSpeciesIdTable,
        .formChangeTable = sCharizardFormChangeTable,
    },

    [SPECIES_CHARIZARD_MEGA_Y] =
    {
        .baseHP        = 78,
        .baseAttack    = 104,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = 159,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 317 : 285,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_DROUGHT, ABILITY_DROUGHT, ABILITY_DROUGHT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charizard"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_CHARIZARD_MEGA_Y,
    #else
        .cryId = CRY_CHARIZARD,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_CHARIZARD,
        .categoryName = _("Flame"),
        .height = 17,
        .weight = 1005,
        .description = COMPOUND_STRING(
            "Its bond with its Trainer is the source\n"
            "of its power. It boasts speed and\n"
            "maneuverability greater than that of a\n"
            "jet fighter."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_CharizardMegaY,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 41),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_SHAKE_GLOW_RED_FAST,
        .backPic = gMonBackPic_CharizardMegaY,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_CharizardMegaY,
        .shinyPalette = gMonShinyPalette_CharizardMegaY,
        .iconSprite = gMonIcon_CharizardMegaY,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 14, SHADOW_SIZE_L)
        FOOTPRINT(Charizard)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_CharizardMegaY,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_CharizardMegaY,
            gShinyOverworldPalette_CharizardMegaY
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCharizardLevelUpLearnset,
        .teachableLearnset = sCharizardTeachableLearnset,
        .formSpeciesIdTable = sCharizardFormSpeciesIdTable,
        .formChangeTable = sCharizardFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GIGANTAMAX_FORMS
    [SPECIES_CHARIZARD_GMAX] =
    {
        .baseHP        = 78,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = CHARIZARD_SP_ATK,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 45,
        .expYield = CHARIZARD_EXP_YIELD,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charizard"),
        .cryId = CRY_CHARIZARD,
        .natDexNum = NATIONAL_DEX_CHARIZARD,
        .categoryName = _("Flame"),
        .height = 280,
        .weight = 0,
        .description = COMPOUND_STRING(
            "The flame inside its body burns\n"
            "hotter than 3,600 degrees Fahrenheit.\n"
            "When Charizard roars, that\n"
            "temperature climbs even higher."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_CharizardGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CharizardGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CharizardGmax,
        .shinyPalette = gMonShinyPalette_CharizardGmax,
        .iconSprite = gMonIcon_CharizardGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 13, SHADOW_SIZE_L)
        FOOTPRINT(Charizard)
        .isGigantamax = TRUE,
        .levelUpLearnset = sCharizardLevelUpLearnset,
        .teachableLearnset = sCharizardTeachableLearnset,
        .formSpeciesIdTable = sCharizardFormSpeciesIdTable,
        .formChangeTable = sCharizardFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_CHARMANDER

#if P_FAMILY_SQUIRTLE
    [SPECIES_SQUIRTLE] =
    {
        .baseHP        = 44,
        .baseAttack    = 48,
        .baseDefense   = 65,
        .baseSpeed     = 43,
        .baseSpAttack  = 50,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 64 : 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 63 : 66,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Squirtle"),
        .cryId = CRY_SQUIRTLE,
        .natDexNum = NATIONAL_DEX_SQUIRTLE,
        .categoryName = _("Tiny Turtle"),
        .height = 5,
        .weight = 90,
        .description = COMPOUND_STRING(
            "Its shell is not just for protection.\n"
            "Its rounded shape and the grooves on its\n"
            "surface minimize resistance in water,\n"
            "enabling Squirtle to swim at high speeds."),
        .pokemonScale = 412,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Squirtle,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE : ANIM_V_JUMPS_BIG,
        .backPic = gMonBackPic_Squirtle,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Squirtle,
        .shinyPalette = gMonShinyPalette_Squirtle,
        .iconSprite = gMonIcon_Squirtle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 2, SHADOW_SIZE_S)
        FOOTPRINT(Squirtle)
        OVERWORLD(
            sPicTable_Squirtle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Squirtle,
            gShinyOverworldPalette_Squirtle
        )
        .levelUpLearnset = sSquirtleLevelUpLearnset,
        .teachableLearnset = sSquirtleTeachableLearnset,
        .eggMoveLearnset = sSquirtleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_WARTORTLE}),
    },

    [SPECIES_WARTORTLE] =
    {
        .baseHP        = 59,
        .baseAttack    = 63,
        .baseDefense   = 80,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 80 : 65,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 143,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Wartortle"),
        .cryId = CRY_WARTORTLE,
        .natDexNum = NATIONAL_DEX_WARTORTLE,
        .categoryName = _("Turtle"),
        .height = 10,
        .weight = 225,
        .description = COMPOUND_STRING(
            "Its large tail is covered with rich, thick\n"
            "fur that deepens in color with age.\n"
            "The scratches on its shell are evidence\n"
            "of this Pokémon's toughness in battle."),
        .pokemonScale = 332,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wartortle,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Wartortle,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Wartortle,
        .shinyPalette = gMonShinyPalette_Wartortle,
        .iconSprite = gMonIcon_Wartortle,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_M)
        FOOTPRINT(Wartortle)
        OVERWORLD(
            sPicTable_Wartortle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wartortle,
            gShinyOverworldPalette_Wartortle
        )
        .levelUpLearnset = sWartortleLevelUpLearnset,
        .teachableLearnset = sWartortleTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_BLASTOISE}),
    },

#define BLASTOISE_SP_DEF (P_UPDATED_STATS >= GEN_2 ? 105 : 85)

#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define BLASTOISE_EXP_YIELD 265
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define BLASTOISE_EXP_YIELD 239
#else
    #define BLASTOISE_EXP_YIELD 210
#endif

    [SPECIES_BLASTOISE] =
    {
        .baseHP        = 79,
        .baseAttack    = 83,
        .baseDefense   = 100,
        .baseSpeed     = 78,
        .baseSpAttack  = 85,
        .baseSpDefense = BLASTOISE_SP_DEF,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = BLASTOISE_EXP_YIELD,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Blastoise"),
        .cryId = CRY_BLASTOISE,
        .natDexNum = NATIONAL_DEX_BLASTOISE,
        .categoryName = _("Shellfish"),
        .height = 16,
        .weight = 855,
        .description = COMPOUND_STRING(
            "The waterspouts that protrude from its\n"
            "shell are highly accurate. Their bullets of\n"
            "water can precisely nail tin cans from\n"
            "a distance of over 160 feet."),
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 293,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Blastoise,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .frontAnimDelay = P_GBA_STYLE_SPECIES_GFX ? 50 : 20,
        .backPic = gMonBackPic_Blastoise,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Blastoise,
        .shinyPalette = gMonShinyPalette_Blastoise,
        .iconSprite = gMonIcon_Blastoise,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Blastoise)
        OVERWORLD(
            sPicTable_Blastoise,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Blastoise,
            gShinyOverworldPalette_Blastoise
        )
        .levelUpLearnset = sBlastoiseLevelUpLearnset,
        .teachableLearnset = sBlastoiseTeachableLearnset,
        .formSpeciesIdTable = sBlastoiseFormSpeciesIdTable,
        .formChangeTable = sBlastoiseFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_BLASTOISE_MEGA] =
    {
        .baseHP        = 79,
        .baseAttack    = 103,
        .baseDefense   = 120,
        .baseSpeed     = 78,
        .baseSpAttack  = 135,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 315 : 284,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_MEGA_LAUNCHER, ABILITY_MEGA_LAUNCHER, ABILITY_MEGA_LAUNCHER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Blastoise"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_BLASTOISE_MEGA,
    #else
        .cryId = CRY_BLASTOISE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_BLASTOISE,
        .categoryName = _("Shellfish"),
        .height = 16,
        .weight = 1011,
        .description = COMPOUND_STRING(
            "The cannon on its back is as powerful\n"
            "as a tank gun. Its tough legs and back\n"
            "enable it to withstand the recoil from\n"
            "firing the cannon."),
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 293,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_BlastoiseMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_JOLT_RIGHT_SLOW,
        .backPic = gMonBackPic_BlastoiseMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_BlastoiseMega,
        .shinyPalette = gMonShinyPalette_BlastoiseMega,
        .iconSprite = gMonIcon_BlastoiseMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 11, SHADOW_SIZE_L)
        FOOTPRINT(Blastoise)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_BlastoiseMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BlastoiseMega,
            gShinyOverworldPalette_BlastoiseMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sBlastoiseLevelUpLearnset,
        .teachableLearnset = sBlastoiseTeachableLearnset,
        .formSpeciesIdTable = sBlastoiseFormSpeciesIdTable,
        .formChangeTable = sBlastoiseFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GIGANTAMAX_FORMS
    [SPECIES_BLASTOISE_GMAX] =
    {
        .baseHP        = 79,
        .baseAttack    = 83,
        .baseDefense   = 100,
        .baseSpeed     = 78,
        .baseSpAttack  = 85,
        .baseSpDefense = BLASTOISE_SP_DEF,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = BLASTOISE_EXP_YIELD,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Blastoise"),
        .cryId = CRY_BLASTOISE,
        .natDexNum = NATIONAL_DEX_BLASTOISE,
        .categoryName = _("Shellfish"),
        .height = 250,
        .weight = 0,
        .description = COMPOUND_STRING(
            "It's not very good at precision\n"
            "shooting. When attacking, it just fires\n"
            "its 31 cannons over and over and\n"
            "over."),
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 293,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_BlastoiseGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_BlastoiseGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_BlastoiseGmax,
        .shinyPalette = gMonShinyPalette_BlastoiseGmax,
        .iconSprite = gMonIcon_BlastoiseGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Blastoise)
        .isGigantamax = TRUE,
        .levelUpLearnset = sBlastoiseLevelUpLearnset,
        .teachableLearnset = sBlastoiseTeachableLearnset,
        .formSpeciesIdTable = sBlastoiseFormSpeciesIdTable,
        .formChangeTable = sBlastoiseFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SQUIRTLE

#if P_FAMILY_CATERPIE
    [SPECIES_CATERPIE] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 35,
        .baseSpeed     = 45,
        .baseSpAttack  = 20,
        .baseSpDefense = 20,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 39 : 53,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Caterpie"),
        .cryId = CRY_CATERPIE,
        .natDexNum = NATIONAL_DEX_CATERPIE,
        .categoryName = _("Worm"),
        .height = 3,
        .weight = 29,
        .description = COMPOUND_STRING(
            "Its voracious appetite compels it to\n"
            "devour leaves bigger than itself without\n"
            "hesitation. It releases a terribly strong\n"
            "odor from its antennae."),
        .pokemonScale = 549,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Caterpie,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Caterpie,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Caterpie,
        .shinyPalette = gMonShinyPalette_Caterpie,
        .iconSprite = gMonIcon_Caterpie,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(4, 1, SHADOW_SIZE_S)
        FOOTPRINT(Caterpie)
        OVERWORLD(
            sPicTable_Caterpie,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Caterpie,
            gShinyOverworldPalette_Caterpie
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sCaterpieLevelUpLearnset,
        .teachableLearnset = sCaterpieTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 7, SPECIES_METAPOD}),
    },

    [SPECIES_METAPOD] =
    {
        .baseHP        = 50,
        .baseAttack    = 20,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 120,
        .expYield = 72,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Metapod"),
        .cryId = CRY_METAPOD,
        .natDexNum = NATIONAL_DEX_METAPOD,
        .categoryName = _("Cocoon"),
        .height = 7,
        .weight = 99,
        .description = COMPOUND_STRING(
            "Its shell is as hard as an iron slab.\n"
            "A Metapod does not move very much\n"
            "because it is preparing its soft innards\n"
            "for evolution inside the shell."),
        .pokemonScale = 350,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Metapod,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Metapod,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(40, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 8,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Metapod,
        .shinyPalette = gMonShinyPalette_Metapod,
        .iconSprite = gMonIcon_Metapod,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(3, 0, SHADOW_SIZE_S)
        FOOTPRINT(Metapod)
        OVERWORLD(
            sPicTable_Metapod,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Metapod,
            gShinyOverworldPalette_Metapod
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sMetapodLevelUpLearnset,
        .teachableLearnset = sMetapodTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_BUTTERFREE}),
    },

#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define BUTTERFREE_EXP_YIELD 198
#elif P_UPDATED_EXP_YIELDS >= GEN_6
    #define BUTTERFREE_EXP_YIELD 178
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define BUTTERFREE_EXP_YIELD 173
#else
    #define BUTTERFREE_EXP_YIELD 160
#endif

    [SPECIES_BUTTERFREE] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_6 ? 90 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 45,
        .expYield = BUTTERFREE_EXP_YIELD,
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SILVER_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_NONE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Butterfree"),
        .cryId = CRY_BUTTERFREE,
        .natDexNum = NATIONAL_DEX_BUTTERFREE,
        .categoryName = _("Butterfly"),
        .height = 11,
        .weight = 320,
        .description = COMPOUND_STRING(
            "It has a superior ability to search for\n"
            "delicious honey from flowers. It can seek,\n"
            "extract, and carry honey from flowers\n"
            "blooming over six miles away."),
        .pokemonScale = 312,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Butterfree,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SLIDE_WOBBLE : ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 12,
        .backPic = gMonBackPic_Butterfree,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Butterfree,
        .shinyPalette = gMonShinyPalette_Butterfree,
        .iconSprite = gMonIcon_Butterfree,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_ButterfreeF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_ButterfreeF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 13, SHADOW_SIZE_S)
        FOOTPRINT(Butterfree)
        OVERWORLD(
            sPicTable_Butterfree,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Butterfree,
            gShinyOverworldPalette_Butterfree
        )
        OVERWORLD_FEMALE(
            sPicTable_ButterfreeF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sButterfreeLevelUpLearnset,
        .teachableLearnset = sButterfreeTeachableLearnset,
        .formSpeciesIdTable = sButterfreeFormSpeciesIdTable,
        .formChangeTable = sButterfreeFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_BUTTERFREE_GMAX] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_6 ? 90 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 45,
        .expYield = BUTTERFREE_EXP_YIELD,
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SILVER_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_NONE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Butterfree"),
        .cryId = CRY_BUTTERFREE,
        .natDexNum = NATIONAL_DEX_BUTTERFREE,
        .categoryName = _("Butterfly"),
        .height = 170,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Once it has opponents trapped in a\n"
            "tornado that could blow away a 10-\n"
            "ton truck, it finishes them off with\n"
            "its poisonous scales."),
        .pokemonScale = 312,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ButterfreeGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_ButterfreeGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ButterfreeGmax,
        .shinyPalette = gMonShinyPalette_ButterfreeGmax,
        .iconSprite = gMonIcon_ButterfreeGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 18, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Butterfree)
        .isGigantamax = TRUE,
        .levelUpLearnset = sButterfreeLevelUpLearnset,
        .teachableLearnset = sButterfreeTeachableLearnset,
        .formSpeciesIdTable = sButterfreeFormSpeciesIdTable,
        .formChangeTable = sButterfreeFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_CATERPIE

#if P_FAMILY_WEEDLE
    [SPECIES_WEEDLE] =
    {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 50,
        .baseSpAttack  = 20,
        .baseSpDefense = 20,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 39 : 52,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Weedle"),
        .cryId = CRY_WEEDLE,
        .natDexNum = NATIONAL_DEX_WEEDLE,
        .categoryName = _("Hairy Bug"),
        .height = 3,
        .weight = 32,
        .description = COMPOUND_STRING(
            "A Weedle has an extremely acute sense\n"
            "of smell. It distinguishes its favorite\n"
            "kinds of leaves from those it dislikes by\n"
            "sniffing with its big red nose."),
        .pokemonScale = 455,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Weedle,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Weedle,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 7,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Weedle,
        .shinyPalette = gMonShinyPalette_Weedle,
        .iconSprite = gMonIcon_Weedle,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Weedle)
        OVERWORLD(
            sPicTable_Weedle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Weedle,
            gShinyOverworldPalette_Weedle
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sWeedleLevelUpLearnset,
        .teachableLearnset = sWeedleTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 7, SPECIES_KAKUNA}),
    },

    [SPECIES_KAKUNA] =
    {
        .baseHP        = 45,
        .baseAttack    = 25,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 72 : 71,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Kakuna"),
        .cryId = CRY_KAKUNA,
        .natDexNum = NATIONAL_DEX_KAKUNA,
        .categoryName = _("Cocoon"),
        .height = 6,
        .weight = 100,
        .description = COMPOUND_STRING(
            "It remains virtually immobile while it\n"
            "clings to a tree. However, on the inside,\n"
            "it busily prepares for evolution. This is\n"
            "evident from how hot its shell becomes."),
        .pokemonScale = 424,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kakuna,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(24, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_GLOW_ORANGE,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Kakuna,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(32, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Kakuna,
        .shinyPalette = gMonShinyPalette_Kakuna,
        .iconSprite = gMonIcon_Kakuna,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Kakuna)
        OVERWORLD(
            sPicTable_Kakuna,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Kakuna,
            gShinyOverworldPalette_Kakuna
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sKakunaLevelUpLearnset,
        .teachableLearnset = sKakunaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_BEEDRILL}),
    },

    [SPECIES_BEEDRILL] =
    {
        .baseHP        = 65,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 90 : 80,
        .baseDefense   = 40,
        .baseSpeed     = 75,
        .baseSpAttack  = 45,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 80 : 45,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 198,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 178,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 173,
    #else
        .expYield = 159,
    #endif
        .evYield_Attack = 2,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Beedrill"),
        .cryId = CRY_BEEDRILL,
        .natDexNum = NATIONAL_DEX_BEEDRILL,
        .categoryName = _("Poison Bee"),
        .height = 10,
        .weight = 295,
        .description = COMPOUND_STRING(
            "A Beedrill is extremely territorial.\n"
            "For safety reasons, no one should ever\n"
            "approach its nest. If angered, they will\n"
            "attack in a swarm."),
        .pokemonScale = 366,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Beedrill,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_VIBRATE : ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .backPic = gMonBackPic_Beedrill,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 5,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Beedrill,
        .shinyPalette = gMonShinyPalette_Beedrill,
        .iconSprite = gMonIcon_Beedrill,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 15, SHADOW_SIZE_M)
        FOOTPRINT(Beedrill)
        OVERWORLD(
            sPicTable_Beedrill,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Beedrill,
            gShinyOverworldPalette_Beedrill
        )
        .levelUpLearnset = sBeedrillLevelUpLearnset,
        .teachableLearnset = sBeedrillTeachableLearnset,
        .formSpeciesIdTable = sBeedrillFormSpeciesIdTable,
        .formChangeTable = sBeedrillFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_BEEDRILL_MEGA] =
    {
        .baseHP        = 65,
        .baseAttack    = 150,
        .baseDefense   = 40,
        .baseSpeed     = 145,
        .baseSpAttack  = 15,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 248 : 223,
        .evYield_Attack = 2,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_ADAPTABILITY, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Beedrill"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_BEEDRILL_MEGA,
    #else
        .cryId = CRY_BEEDRILL,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_BEEDRILL,
        .categoryName = _("Poison Bee"),
        .height = 14,
        .weight = 405,
        .description = COMPOUND_STRING(
            "Its legs have become poison stingers.\n"
            "It stabs its prey repeatedly with the\n"
            "stingers on its limbs, dealing the final\n"
            "blow with the stinger on its rear."),
        .pokemonScale = 366,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BeedrillMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_BeedrillMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_BeedrillMega,
        .shinyPalette = gMonShinyPalette_BeedrillMega,
        .iconSprite = gMonIcon_BeedrillMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 14, SHADOW_SIZE_S)
        FOOTPRINT(Beedrill)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_BeedrillMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BeedrillMega,
            gShinyOverworldPalette_BeedrillMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sBeedrillLevelUpLearnset,
        .teachableLearnset = sBeedrillTeachableLearnset,
        .formSpeciesIdTable = sBeedrillFormSpeciesIdTable,
        .formChangeTable = sBeedrillFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_WEEDLE

#if P_FAMILY_PIDGEY
    [SPECIES_PIDGEY] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 56,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 50 : 55,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_KEEN_EYE, ABILITY_TANGLED_FEET, ABILITY_BIG_PECKS },
    #else
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_BIG_PECKS },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pidgey"),
        .cryId = CRY_PIDGEY,
        .natDexNum = NATIONAL_DEX_PIDGEY,
        .categoryName = _("Tiny Bird"),
        .height = 3,
        .weight = 18,
        .description = COMPOUND_STRING(
            "It has an extremely sharp sense of\n"
            "direction. It can unerringly return home to\n"
            "its nest, however far it may be removed\n"
            "from its familiar surroundings."),
        .pokemonScale = 508,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pidgey,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SLIDE_SLOW : ANIM_V_STRETCH,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 16 : 0,
        .backPic = gMonBackPic_Pidgey,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 11,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Pidgey,
        .shinyPalette = gMonShinyPalette_Pidgey,
        .iconSprite = gMonIcon_Pidgey,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, -1, SHADOW_SIZE_S)
        FOOTPRINT(Pidgey)
        OVERWORLD(
            sPicTable_Pidgey,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pidgey,
            gShinyOverworldPalette_Pidgey
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sPidgeyLevelUpLearnset,
        .teachableLearnset = sPidgeyTeachableLearnset,
        .eggMoveLearnset = sPidgeyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_PIDGEOTTO}),
    },

    [SPECIES_PIDGEOTTO] =
    {
        .baseHP        = 63,
        .baseAttack    = 60,
        .baseDefense   = 55,
        .baseSpeed     = 71,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 122 : 113,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_KEEN_EYE, ABILITY_TANGLED_FEET, ABILITY_BIG_PECKS },
    #else
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_BIG_PECKS },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pidgeotto"),
        .cryId = CRY_PIDGEOTTO,
        .natDexNum = NATIONAL_DEX_PIDGEOTTO,
        .categoryName = _("Bird"),
        .height = 11,
        .weight = 300,
        .description = COMPOUND_STRING(
            "This Pokémon flies around, patrolling its\n"
            "large territory. If its living space is\n"
            "violated, it shows no mercy in thoroughly\n"
            "punishing the foe with its sharp claws."),
        .pokemonScale = 331,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pidgeotto,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .frontAnimDelay = 25,
        .backPic = gMonBackPic_Pidgeotto,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Pidgeotto,
        .shinyPalette = gMonShinyPalette_Pidgeotto,
        .iconSprite = gMonIcon_Pidgeotto,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 6, SHADOW_SIZE_M)
        FOOTPRINT(Pidgeotto)
        OVERWORLD(
            sPicTable_Pidgeotto,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pidgeotto,
            gShinyOverworldPalette_Pidgeotto
        )
        .levelUpLearnset = sPidgeottoLevelUpLearnset,
        .teachableLearnset = sPidgeottoTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_PIDGEOT}),
    },

    [SPECIES_PIDGEOT] =
    {
        .baseHP        = 83,
        .baseAttack    = 80,
        .baseDefense   = 75,
        .baseSpeed     = P_UPDATED_STATS >= GEN_6 ? 101 : 91,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 240,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 216,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 211,
    #else
        .expYield = 172,
    #endif
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_KEEN_EYE, ABILITY_TANGLED_FEET, ABILITY_BIG_PECKS },
    #else
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_BIG_PECKS },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pidgeot"),
        .cryId = CRY_PIDGEOT,
        .natDexNum = NATIONAL_DEX_PIDGEOT,
        .categoryName = _("Bird"),
        .height = 15,
        .weight = 395,
        .description = COMPOUND_STRING(
            "This Pokémon has gorgeous, glossy\n"
            "feathers. Many Trainers are so captivated\n"
            "by the beautiful feathers on its head that\n"
            "they choose Pidgeot as their Pokémon."),
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pidgeot,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_FRONT_FLIP : ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .backPic = gMonBackPic_Pidgeot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Pidgeot,
        .shinyPalette = gMonShinyPalette_Pidgeot,
        .iconSprite = gMonIcon_Pidgeot,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 14, SHADOW_SIZE_M)
        FOOTPRINT(Pidgeot)
        OVERWORLD(
            sPicTable_Pidgeot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pidgeot,
            gShinyOverworldPalette_Pidgeot
        )
        .levelUpLearnset = sPidgeotLevelUpLearnset,
        .teachableLearnset = sPidgeotTeachableLearnset,
        .formSpeciesIdTable = sPidgeotFormSpeciesIdTable,
        .formChangeTable = sPidgeotFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_PIDGEOT_MEGA] =
    {
        .baseHP        = 83,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 121,
        .baseSpAttack  = 135,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_NO_GUARD, ABILITY_NO_GUARD, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pidgeot"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_PIDGEOT_MEGA,
    #else
        .cryId = CRY_PIDGEOT,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_PIDGEOT,
        .categoryName = _("Bird"),
        .height = 22,
        .weight = 505,
        .description = COMPOUND_STRING(
            "With its muscular strength now greatly\n"
            "increased, it can fly continuously\n"
            "for two weeks without resting."),
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PidgeotMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_TRIANGLE_DOWN_SLOW,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_PidgeotMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_PidgeotMega,
        .shinyPalette = gMonShinyPalette_PidgeotMega,
        .iconSprite = gMonIcon_PidgeotMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 19, SHADOW_SIZE_M)
        FOOTPRINT(Pidgeot)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_PidgeotMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_PidgeotMega,
            gShinyOverworldPalette_PidgeotMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sPidgeotLevelUpLearnset,
        .teachableLearnset = sPidgeotTeachableLearnset,
        .formSpeciesIdTable = sPidgeotFormSpeciesIdTable,
        .formChangeTable = sPidgeotFormChangeTable,
    },
#endif
#endif //P_FAMILY_PIDGEY

#if P_FAMILY_RATTATA
    [SPECIES_RATTATA] =
    {
        .baseHP        = 30,
        .baseAttack    = 56,
        .baseDefense   = 35,
        .baseSpeed     = 72,
        .baseSpAttack  = 25,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 35 : 25,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 51 : 57,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_GUTS, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Rattata"),
        .cryId = CRY_RATTATA,
        .natDexNum = NATIONAL_DEX_RATTATA,
        .categoryName = _("Mouse"),
        .height = 3,
        .weight = 35,
        .description = COMPOUND_STRING(
            "A Rattata is cautious in the extreme.\n"
            "Even while it is asleep, it constantly\n"
            "moves its ears and listens for danger.\n"
            "It will make its nest anywhere."),
        .pokemonScale = 481,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rattata,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 32) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_RAPID_H_HOPS : ANIM_H_JUMPS,
        .backPic = gMonBackPic_Rattata,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 7,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Rattata,
        .shinyPalette = gMonShinyPalette_Rattata,
        .iconSprite = gMonIcon_Rattata,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_RattataF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 40),
        .backPicFemale = gMonBackPic_RattataF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, -3, SHADOW_SIZE_S)
        FOOTPRINT(Rattata)
        OVERWORLD(
            sPicTable_Rattata,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rattata,
            gShinyOverworldPalette_Rattata
        )
        OVERWORLD_FEMALE(
            sPicTable_RattataF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sRattataLevelUpLearnset,
        .teachableLearnset = sRattataTeachableLearnset,
        .eggMoveLearnset = sRattataEggMoveLearnset,
        .formSpeciesIdTable = sRattataFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_RATICATE}),
    },

    [SPECIES_RATICATE] =
    {
        .baseHP        = 55,
        .baseAttack    = 81,
        .baseDefense   = 60,
        .baseSpeed     = 97,
        .baseSpAttack  = 50,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 70 : 50,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 127,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 145 : 116,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_GUTS, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Raticate"),
        .cryId = CRY_RATICATE,
        .natDexNum = NATIONAL_DEX_RATICATE,
        .categoryName = _("Mouse"),
        .height = 7,
        .weight = 185,
        .description = COMPOUND_STRING(
            "A Raticate's sturdy fangs grow steadily.\n"
            "To keep them ground down, it gnaws on\n"
            "rocks and logs. It may even chew on the\n"
            "walls of houses."),
        .pokemonScale = 459,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Raticate,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_FIGURE_8 : ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .backPic = gMonBackPic_Raticate,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 10,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Raticate,
        .shinyPalette = gMonShinyPalette_Raticate,
        .iconSprite = gMonIcon_Raticate,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_RaticateF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_RaticateF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 8, SHADOW_SIZE_L)
        FOOTPRINT(Raticate)
        OVERWORLD(
            sPicTable_Raticate,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Raticate,
            gShinyOverworldPalette_Raticate
        )
        OVERWORLD_FEMALE(
            sPicTable_RaticateF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sRaticateLevelUpLearnset,
        .teachableLearnset = sRaticateTeachableLearnset,
        .formSpeciesIdTable = sRaticateFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_RATTATA_ALOLA] =
    {
        .baseHP        = 30,
        .baseAttack    = 56,
        .baseDefense   = 35,
        .baseSpeed     = 72,
        .baseSpAttack  = 25,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_DARK, TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 51,
        .evYield_Speed = 1,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_HUSTLE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Rattata"),
        .cryId = CRY_RATTATA,
        .natDexNum = NATIONAL_DEX_RATTATA,
        .categoryName = _("Mouse"),
        .height = 3,
        .weight = 38,
        .description = COMPOUND_STRING(
            "With its incisors, it gnaws through doors\n"
            "and infiltrates people's homes.\n"
            "Then, with a twitch of its whiskers,\n"
            "it steals whatever food it finds."),
        .pokemonScale = 481,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_RattataAlola,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 50),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .frontAnimDelay = 28,
        .backPic = gMonBackPic_RattataAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RattataAlola,
        .shinyPalette = gMonShinyPalette_RattataAlola,
        .iconSprite = gMonIcon_RattataAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-3, 2, SHADOW_SIZE_S)
        FOOTPRINT(Rattata)
        OVERWORLD(
            sPicTable_RattataAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_RattataAlola,
            gShinyOverworldPalette_RattataAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sRattataAlolaLevelUpLearnset,
        .teachableLearnset = sRattataAlolaTeachableLearnset,
        .eggMoveLearnset = sRattataAlolaEggMoveLearnset,
        .formSpeciesIdTable = sRattataFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_RATICATE_ALOLA, CONDITIONS({IF_TIME, TIME_NIGHT})},
                                {EVO_NONE, 0, SPECIES_RATICATE_ALOLA_TOTEM}),
    },

    [SPECIES_RATICATE_ALOLA] =
    {
        .baseHP        = 75,
        .baseAttack    = 71,
        .baseDefense   = 70,
        .baseSpeed     = 77,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_DARK, TYPE_NORMAL),
        .catchRate = 127,
        .expYield = 145,
        .evYield_Speed = 2,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_HUSTLE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Raticate"),
        .cryId = CRY_RATICATE,
        .natDexNum = NATIONAL_DEX_RATICATE,
        .categoryName = _("Mouse"),
        .height = 7,
        .weight = 255,
        .description = gRaticateAlolaPokedexText,
        .pokemonScale = 459,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_RaticateAlola,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_RaticateAlola,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .frontAnimDelay = 22,
        .backPic = gMonBackPic_RaticateAlola,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RaticateAlola,
        .shinyPalette = gMonShinyPalette_RaticateAlola,
        .iconSprite = gMonIcon_RaticateAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Raticate)
        OVERWORLD(
            sPicTable_RaticateAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_RaticateAlola,
            gShinyOverworldPalette_RaticateAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sRaticateAlolaLevelUpLearnset,
        .teachableLearnset = sRaticateAlolaTeachableLearnset,
        .formSpeciesIdTable = sRaticateFormSpeciesIdTable,
    },

    [SPECIES_RATICATE_ALOLA_TOTEM] =
    {
        .baseHP        = 75,
        .baseAttack    = 71,
        .baseDefense   = 70,
        .baseSpeed     = 77,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_DARK, TYPE_NORMAL),
        .catchRate = 127,
        .expYield = 145,
        .evYield_Speed = 2,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_THICK_FAT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Raticate"),
        .cryId = CRY_RATICATE,
        .natDexNum = NATIONAL_DEX_RATICATE,
        .categoryName = _("Mouse"),
        .height = 14,
        .weight = 1050,
        .description = gRaticateAlolaPokedexText,
        .pokemonScale = 459,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_RaticateAlola,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_RaticateAlola,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .frontAnimDelay = 22,
        .backPic = gMonBackPic_RaticateAlola,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RaticateAlola,
        .shinyPalette = gMonShinyPalette_RaticateAlola,
        .iconSprite = gMonIcon_RaticateAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Raticate)
        OVERWORLD(
            sPicTable_RaticateAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_RaticateAlola,
            gShinyOverworldPalette_RaticateAlola
        )
        .isTotem = TRUE,
        .isAlolanForm = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRaticateAlolaLevelUpLearnset,
        .teachableLearnset = sRaticateAlolaTeachableLearnset,
        .formSpeciesIdTable = sRaticateFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_RATTATA

#if P_FAMILY_SPEAROW
    [SPECIES_SPEAROW] =
    {
        .baseHP        = 40,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 70,
        .baseSpAttack  = 31,
        .baseSpDefense = 31,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 52 : 58,
        .evYield_Speed = 1,
        .itemRare = ITEM_SHARP_BEAK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Spearow"),
        .cryId = CRY_SPEAROW,
        .natDexNum = NATIONAL_DEX_SPEAROW,
        .categoryName = _("Tiny Bird"),
        .height = 3,
        .weight = 20,
        .description = COMPOUND_STRING(
            "Its loud cry can be heard over half a mile\n"
            "away. If its high, keening cry is heard\n"
            "echoing all around, it is a sign that they\n"
            "are warning each other of danger."),
        .pokemonScale = 571,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Spearow,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_RISING_WOBBLE : ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Spearow,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Spearow,
        .shinyPalette = gMonShinyPalette_Spearow,
        .iconSprite = gMonIcon_Spearow,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Spearow)
        OVERWORLD(
            sPicTable_Spearow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Spearow,
            gShinyOverworldPalette_Spearow
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sSpearowLevelUpLearnset,
        .teachableLearnset = sSpearowTeachableLearnset,
        .eggMoveLearnset = sSpearowEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_FEAROW}),
    },

    [SPECIES_FEAROW] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 61,
        .baseSpDefense = 61,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 155 : 162,
        .evYield_Speed = 2,
        .itemRare = ITEM_SHARP_BEAK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Fearow"),
        .cryId = CRY_FEAROW,
        .natDexNum = NATIONAL_DEX_FEAROW,
        .categoryName = _("Beak"),
        .height = 12,
        .weight = 380,
        .description = COMPOUND_STRING(
            "Its long neck and elongated beak are\n"
            "ideal for catching prey in soil or water.\n"
            "It deftly moves this extended and skinny\n"
            "beak to pluck prey."),
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fearow,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_FIGURE_8,
        .frontAnimDelay = 2,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Fearow,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Fearow,
        .shinyPalette = gMonShinyPalette_Fearow,
        .iconSprite = gMonIcon_Fearow,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 17, SHADOW_SIZE_M)
        FOOTPRINT(Fearow)
        OVERWORLD(
            sPicTable_Fearow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Fearow,
            gShinyOverworldPalette_Fearow
        )
        .levelUpLearnset = sFearowLevelUpLearnset,
        .teachableLearnset = sFearowTeachableLearnset,
    },
#endif //P_FAMILY_SPEAROW

#if P_FAMILY_EKANS
    [SPECIES_EKANS] =
    {
        .baseHP        = 35,
        .baseAttack    = 60,
        .baseDefense   = 44,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 54 : 40,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SHED_SKIN, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Ekans"),
        .cryId = CRY_EKANS,
        .natDexNum = NATIONAL_DEX_EKANS,
        .categoryName = _("Snake"),
        .height = 20,
        .weight = 69,
        .description = COMPOUND_STRING(
            "An Ekans curls itself up in a spiral while\n"
            "it rests. This position allows it to quickly\n"
            "respond to an enemy from any direction\n"
            "with a threat from its upraised head."),
        .pokemonScale = 298,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ekans,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_STRETCH : ANIM_V_STRETCH,
        .frontAnimDelay = 30,
        .backPic = gMonBackPic_Ekans,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Ekans,
        .shinyPalette = gMonShinyPalette_Ekans,
        .iconSprite = gMonIcon_Ekans,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(Ekans)
        OVERWORLD(
            sPicTable_Ekans,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Ekans,
            gShinyOverworldPalette_Ekans
        )
        .levelUpLearnset = sEkansLevelUpLearnset,
        .teachableLearnset = sEkansTeachableLearnset,
        .eggMoveLearnset = sEkansEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_ARBOK}),
    },

    [SPECIES_ARBOK] =
    {
        .baseHP        = 60,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 95 : 85,
        .baseDefense   = 69,
        .baseSpeed     = 80,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 79 : 65,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 90,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 157,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 153,
    #else
        .expYield = 147,
    #endif
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SHED_SKIN, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Arbok"),
        .cryId = CRY_ARBOK,
        .natDexNum = NATIONAL_DEX_ARBOK,
        .categoryName = _("Cobra"),
        .height = 35,
        .weight = 650,
        .description = COMPOUND_STRING(
            "This Pokémon has a terrifically strong\n"
            "constricting power. It can even flatten\n"
            "steel oil drums. Once it wraps its body\n"
            "around its foe, escaping is impossible."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 296,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Arbok,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Arbok,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 1,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Arbok,
        .shinyPalette = gMonShinyPalette_Arbok,
        .iconSprite = gMonIcon_Arbok,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Arbok)
        OVERWORLD(
            sPicTable_Arbok,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Arbok,
            gShinyOverworldPalette_Arbok
        )
        .levelUpLearnset = sArbokLevelUpLearnset,
        .teachableLearnset = sArbokTeachableLearnset,
    },
#endif //P_FAMILY_EKANS

#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
    [SPECIES_PICHU] =
    {
        .baseHP        = 20,
        .baseAttack    = 40,
        .baseDefense   = 15,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 41 : 42,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pichu"),
        .cryId = CRY_PICHU,
        .natDexNum = NATIONAL_DEX_PICHU,
        .categoryName = _("Tiny Mouse"),
        .height = 3,
        .weight = 20,
        .description = gPichuPokedexText,
        .pokemonScale = 508,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pichu,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_JUMPS_BIG,
        .backPic = gMonBackPic_Pichu,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Pichu,
        .shinyPalette = gMonShinyPalette_Pichu,
        .iconSprite = gMonIcon_Pichu,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Pichu)
        OVERWORLD(
            sPicTable_Pichu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pichu,
            gShinyOverworldPalette_Pichu
        )
        .levelUpLearnset = sPichuLevelUpLearnset,
        .teachableLearnset = sPichuTeachableLearnset,
        .eggMoveLearnset = sPichuEggMoveLearnset,
        .formSpeciesIdTable = sPichuFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_PIKACHU, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },

    [SPECIES_PICHU_SPIKY_EARED] =
    {
        .baseHP        = 20,
        .baseAttack    = 40,
        .baseDefense   = 15,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = 42,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Pichu"),
        .cryId = CRY_PICHU,
        .natDexNum = NATIONAL_DEX_PICHU,
        .categoryName = _("Tiny Mouse"),
        .height = 3,
        .weight = 20,
        .description = gPichuPokedexText,
        .pokemonScale = 508,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PichuSpikyEared,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_PichuSpikyEared,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PichuSpikyEared,
        .shinyPalette = gMonShinyPalette_PichuSpikyEared,
        .iconSprite = gMonIcon_PichuSpikyEared,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Pichu)
        OVERWORLD(
            sPicTable_PichuSpikyEared,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_PichuSpikyEared,
            gShinyOverworldPalette_PichuSpikyEared
        )
        .levelUpLearnset = sPichuLevelUpLearnset,
        .teachableLearnset = sPichuTeachableLearnset,
        .eggMoveLearnset = sPichuEggMoveLearnset,
        .formSpeciesIdTable = sPichuFormSpeciesIdTable,
    },
#endif //P_GEN_2_CROSS_EVOS

#define PIKACHU_DEFENSE (P_UPDATED_STATS >= GEN_6 ? 40 : 30)
#define PIKACHU_SP_DEF (P_UPDATED_STATS >= GEN_6 || P_UPDATED_STATS == GEN_1 ? 50 : 40)

#if P_UPDATED_EXP_YIELDS >= GEN_6
    #define PIKACHU_EXP_YIELD 112
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define PIKACHU_EXP_YIELD 105
#else
    #define PIKACHU_EXP_YIELD 82
#endif

    [SPECIES_PIKACHU] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = PIKACHU_DEFENSE,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 || P_UPDATED_STATS == GEN_1 ? 50 : 40,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pikachu,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 60),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_FLASH_YELLOW,
        .frontAnimDelay = P_GBA_STYLE_SPECIES_GFX ? 0 : 25,
        .backPic = gMonBackPic_Pikachu,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 4,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Pikachu,
        .shinyPalette = gMonShinyPalette_Pikachu,
        .iconSprite = gMonIcon_Pikachu,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_PikachuF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 48),
        .backPicFemale = gMonBackPic_PikachuF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        .iconSpriteFemale = gMonIcon_PikachuF,
        .iconPalIndexFemale = 2,
    #endif //P_CUSTOM_GENDER_DIFF_ICONS
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        OVERWORLD(
            sPicTable_Pikachu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pikachu,
            gShinyOverworldPalette_Pikachu
        )
        OVERWORLD_FEMALE(
            sPicTable_PikachuF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
        .formChangeTable = sPikachuFormChangeTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU, CONDITIONS({IF_NOT_REGION, REGION_ALOLA})}
                            #if P_ALOLAN_FORMS
                                ,{EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU_ALOLA, CONDITIONS({IF_REGION, REGION_ALOLA})}
                            #endif
                            ),
    },

#if P_COSPLAY_PIKACHU_FORMS
    [SPECIES_PIKACHU_COSPLAY]   =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuCosplay,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuCosplay,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuCosplay,
        .shinyPalette = gMonShinyPalette_PikachuCosplay,
        .iconSprite = gMonIcon_PikachuCosplay,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_ROCK_STAR] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuRockStar,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuRockStar,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuRockStar,
        .shinyPalette = gMonShinyPalette_PikachuRockStar,
        .iconSprite = gMonIcon_PikachuRockStar,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_BELLE] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuBelle,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuBelle,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuBelle,
        .shinyPalette = gMonShinyPalette_PikachuBelle,
        .iconSprite = gMonIcon_PikachuBelle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_POP_STAR] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuPopStar,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuPopStar,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuPopStar,
        .shinyPalette = gMonShinyPalette_PikachuPopStar,
        .iconSprite = gMonIcon_PikachuPopStar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_PHD] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuPhD,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuPhD,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuPhD,
        .shinyPalette = gMonShinyPalette_PikachuPhD,
        .iconSprite = gMonIcon_PikachuPhD,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_LIBRE] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuLibre,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuLibre,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuLibre,
        .shinyPalette = gMonShinyPalette_PikachuLibre,
        .iconSprite = gMonIcon_PikachuLibre,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

#endif //P_COSPLAY_PIKACHU_FORMS

#if P_CAP_PIKACHU_FORMS
    [SPECIES_PIKACHU_ORIGINAL] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed during adventures\n"
            "across many different regions."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuOriginal,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuOriginal,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuOriginal,
        .shinyPalette = gMonShinyPalette_PikachuOriginal,
        .iconSprite = gMonIcon_PikachuOriginal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_HOENN] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed during adventures\n"
            "across the Hoenn region together."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuHoenn,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuHoenn,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuHoenn,
        .shinyPalette = gMonShinyPalette_PikachuHoenn,
        .iconSprite = gMonIcon_PikachuHoenn,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_SINNOH] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed during adventures\n"
            "across the Sinnoh region together."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuSinnoh,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuSinnoh,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuSinnoh,
        .shinyPalette = gMonShinyPalette_PikachuSinnoh,
        .iconSprite = gMonIcon_PikachuSinnoh,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_UNOVA] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed during adventures\n"
            "across the Unova region together."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuUnova,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuUnova,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuUnova,
        .shinyPalette = gMonShinyPalette_PikachuUnova,
        .iconSprite = gMonIcon_PikachuUnova,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_KALOS] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed during adventures\n"
            "across the Kalos region together."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuKalos,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuKalos,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuKalos,
        .shinyPalette = gMonShinyPalette_PikachuKalos,
        .iconSprite = gMonIcon_PikachuKalos,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_ALOLA] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed during adventures\n"
            "across the Alola region together."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuAlola,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuAlola,
        .shinyPalette = gMonShinyPalette_PikachuAlola,
        .iconSprite = gMonIcon_PikachuAlola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_PARTNER] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed as the two overcame\n"
            "many hardships together."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuPartner,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuPartner,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuPartner,
        .shinyPalette = gMonShinyPalette_PikachuPartner,
        .iconSprite = gMonIcon_PikachuPartner,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

    [SPECIES_PIKACHU_WORLD] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = MON_MALE,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "This Pikachu wears its partner's cap, which\n"
            "is proof of the strong bond Pikachu and\n"
            "its partner formed during adventures\n"
            "across the world together."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuWorld,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuWorld,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuWorld,
        .shinyPalette = gMonShinyPalette_PikachuWorld,
        .iconSprite = gMonIcon_PikachuWorld,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

#endif //P_CAP_PIKACHU_FORMS

#if P_GIGANTAMAX_FORMS
    [SPECIES_PIKACHU_GMAX] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = PIKACHU_DEFENSE,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = PIKACHU_SP_DEF,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = PIKACHU_EXP_YIELD,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 210,
        .weight = 0,
        .description = COMPOUND_STRING(
            "When it smashes its opponents with\n"
            "its bolt-shaped tail, it delivers a\n"
            "surge of electricity equivalent to a\n"
            "lightning strike."),
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PikachuGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PikachuGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PikachuGmax,
        .shinyPalette = gMonShinyPalette_PikachuGmax,
        .iconSprite = gMonIcon_PikachuGmax,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Pikachu)
        .isGigantamax = TRUE,
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
        .formChangeTable = sPikachuFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS

    [SPECIES_PIKACHU_STARTER] =
    {
        .baseHP        = 45,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 120,
        .baseSpAttack  = 75,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 151 : 86,
        .evYield_Speed = 2,
        .itemRare = ITEM_LIGHT_BALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pikachu"),
        .cryId = CRY_PIKACHU,
        .natDexNum = NATIONAL_DEX_PIKACHU,
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pikachu,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 60),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_FLASH_YELLOW,
        .frontAnimDelay = 25,
        .backPic = gMonBackPic_Pikachu,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Pikachu,
        .shinyPalette = gMonShinyPalette_Pikachu,
        .iconSprite = gMonIcon_PikachuStarter,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_PikachuF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 48),
        .backPicFemale = gMonBackPic_PikachuF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        .iconSpriteFemale = gMonIcon_PikachuStarterF,
        .iconPalIndexFemale = 2,
    #endif
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Pikachu)
        OVERWORLD(
            sPicTable_Pikachu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pikachu,
            gShinyOverworldPalette_Pikachu
        )
        .cannotBeTraded = TRUE,
        .perfectIVCount = NUM_STATS,
        .levelUpLearnset = sPikachuLevelUpLearnset,
        .teachableLearnset = sPikachuTeachableLearnset,
        .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },

#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define RAICHU_EXP_YIELD 243
#elif P_UPDATED_EXP_YIELDS >= GEN_6
    #define RAICHU_EXP_YIELD 218
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define RAICHU_EXP_YIELD 214
#else
    #define RAICHU_EXP_YIELD 122
#endif

    [SPECIES_RAICHU] =
    {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 55,
        .baseSpeed     = P_UPDATED_STATS >= GEN_6 ? 110 : 100,
        .baseSpAttack  = 90,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 80 : 90,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = RAICHU_EXP_YIELD,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Raichu"),
        .cryId = CRY_RAICHU,
        .natDexNum = NATIONAL_DEX_RAICHU,
        .categoryName = _("Mouse"),
        .height = 8,
        .weight = 300,
        .description = COMPOUND_STRING(
            "If it stores too much electricity, its\n"
            "behavior turns aggressive. To avoid this,\n"
            "it occasionally discharges excess energy\n"
            "and calms itself down."),
        .pokemonScale = 426,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Raichu,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Raichu,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Raichu,
        .shinyPalette = gMonShinyPalette_Raichu,
        .iconSprite = gMonIcon_Raichu,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_RaichuF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 10, SHADOW_SIZE_M)
        FOOTPRINT(Raichu)
        OVERWORLD(
            sPicTable_Raichu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Raichu,
            gShinyOverworldPalette_Raichu
        )
        OVERWORLD_FEMALE(
            sPicTable_RaichuF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sRaichuLevelUpLearnset,
        .teachableLearnset = sRaichuTeachableLearnset,
        .formSpeciesIdTable = sRaichuFormSpeciesIdTable,
        .formChangeTable = sRaichuFormChangeTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_RAICHU_ALOLA] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 110,
        .baseSpAttack  = 95,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 243 : 218,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_SURGE_SURFER, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Raichu"),
        .cryId = CRY_RAICHU,
        .natDexNum = NATIONAL_DEX_RAICHU,
        .categoryName = _("Mouse"),
        .height = 7,
        .weight = 210,
        .description = COMPOUND_STRING(
            "It uses psychokinesis to control\n"
            "electricity. It focuses psychic energy\n"
            "into its tail and rides it like it's surfing.\n"
            "Another name for this Pokémon is 'hodad'."),
        .pokemonScale = 426,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_RaichuAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_RaichuAlola,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RaichuAlola,
        .shinyPalette = gMonShinyPalette_RaichuAlola,
        .iconSprite = gMonIcon_RaichuAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 15, SHADOW_SIZE_M)
        FOOTPRINT(Raichu)
        OVERWORLD(
            sPicTable_RaichuAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_RaichuAlola,
            gShinyOverworldPalette_RaichuAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sRaichuAlolaLevelUpLearnset,
        .teachableLearnset = sRaichuAlolaTeachableLearnset,
        .formSpeciesIdTable = sRaichuFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_RAICHU_MEGA_X] =
    {
        .baseHP        = 60,
        .baseAttack    = 135,
        .baseDefense   = 95,
        .baseSpeed     = 110,
        .baseSpAttack  = 90,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = RAICHU_EXP_YIELD,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_ELECTRIC_SURGE, ABILITY_ELECTRIC_SURGE, ABILITY_ELECTRIC_SURGE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Raichu"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_RAICHU_MEGA_X,
    #else
        .cryId = CRY_RAICHU,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_RAICHU,
        .categoryName = _("Mouse"),
        .height = 12,
        .weight = 380,
        .description = COMPOUND_STRING(
            "It resembles an X as it flies through\n"
            "the air with 50 million volts of\n"
            "electricity sparking from its ears and\n"
            "forked tail."),
        .frontPic = gMonFrontPic_RaichuMegaX,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_RaichuMegaX,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RaichuMegaX,
        .shinyPalette = gMonShinyPalette_RaichuMegaX,
        .iconSprite = gMonIcon_RaichuMegaX,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Raichu)
        SHADOW(-7, 9, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sRaichuLevelUpLearnset,
        .teachableLearnset = sRaichuTeachableLearnset,
        .formSpeciesIdTable = sRaichuFormSpeciesIdTable,
        .formChangeTable = sRaichuFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS


#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_RAICHU_MEGA_Y] =
    {
        .baseHP        = 60,
        .baseAttack    = 100,
        .baseDefense   = 55,
        .baseSpeed     = 130,
        .baseSpAttack  = 160,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = RAICHU_EXP_YIELD,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_NO_GUARD, ABILITY_NO_GUARD, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Raichu"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_RAICHU_MEGA_Y,
    #else
        .cryId = CRY_RAICHU,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_RAICHU,
        .categoryName = _("Mouse"),
        .height = 10,
        .weight = 260,
        .description = COMPOUND_STRING(
            "It fires bolts of electricity from the\n"
            "tip of its tail and from the spiky tufts\n"
            "of fur growing out of its temples. This\n"
            "electricity forms the letter Y."),
        .frontPic = gMonFrontPic_RaichuMegaY,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_RaichuMegaY,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RaichuMegaY,
        .shinyPalette = gMonShinyPalette_RaichuMegaY,
        .iconSprite = gMonIcon_RaichuMegaY,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Raichu)
        SHADOW(-3, 10, SHADOW_SIZE_S)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sRaichuLevelUpLearnset,
        .teachableLearnset = sRaichuTeachableLearnset,
        .formSpeciesIdTable = sRaichuFormSpeciesIdTable,
        .formChangeTable = sRaichuFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_PIKACHU

#if P_FAMILY_SANDSHREW
    [SPECIES_SANDSHREW] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 20 : 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 93,
        .evYield_Defense = 1,
        .itemRare = ITEM_GRIP_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_SAND_RUSH },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Sandshrew"),
        .cryId = CRY_SANDSHREW,
        .natDexNum = NATIONAL_DEX_SANDSHREW,
        .categoryName = _("Mouse"),
        .height = 6,
        .weight = 120,
        .description = COMPOUND_STRING(
            "When it curls up in a ball, it can make any\n"
            "attack bounce off harmlessly. Its hide has\n"
            "turned tough and solid as a result of\n"
            "living in the desert."),
        .pokemonScale = 365,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sandshrew,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        .backPic = gMonBackPic_Sandshrew,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Sandshrew,
        .shinyPalette = gMonShinyPalette_Sandshrew,
        .iconSprite = gMonIcon_Sandshrew,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 1, SHADOW_SIZE_M)
        FOOTPRINT(Sandshrew)
        OVERWORLD(
            sPicTable_Sandshrew,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sandshrew,
            gShinyOverworldPalette_Sandshrew
        )
        .levelUpLearnset = sSandshrewLevelUpLearnset,
        .teachableLearnset = sSandshrewTeachableLearnset,
        .eggMoveLearnset = sSandshrewEggMoveLearnset,
        .formSpeciesIdTable = sSandshrewFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_SANDSLASH}),
    },

    [SPECIES_SANDSLASH] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 45 : 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 158 : 163,
        .evYield_Defense = 2,
        .itemRare = ITEM_GRIP_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_SAND_RUSH },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Sandslash"),
        .cryId = CRY_SANDSLASH,
        .natDexNum = NATIONAL_DEX_SANDSLASH,
        .categoryName = _("Mouse"),
        .height = 10,
        .weight = 295,
        .description = COMPOUND_STRING(
            "It curls up in a ball to protect itself from\n"
            "enemy attacks. It also curls up to prevent\n"
            "heatstroke during the daytime when\n"
            "temperatures rise sharply."),
        .pokemonScale = 341,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sandslash,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_H_SHAKE,
        .backPic = gMonBackPic_Sandslash,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Sandslash,
        .shinyPalette = gMonShinyPalette_Sandslash,
        .iconSprite = gMonIcon_Sandslash,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 4, SHADOW_SIZE_L)
        FOOTPRINT(Sandslash)
        OVERWORLD(
            sPicTable_Sandslash,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sandslash,
            gShinyOverworldPalette_Sandslash
        )
        .levelUpLearnset = sSandslashLevelUpLearnset,
        .teachableLearnset = sSandslashTeachableLearnset,
        .formSpeciesIdTable = sSandslashFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_SANDSHREW_ALOLA] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 90,
        .baseSpeed     = 40,
        .baseSpAttack  = 10,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_ICE, TYPE_STEEL),
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense = 1,
        .itemRare = ITEM_GRIP_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SLUSH_RUSH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Sandshrew"),
        .cryId = CRY_SANDSHREW,
        .natDexNum = NATIONAL_DEX_SANDSHREW,
        .categoryName = _("Mouse"),
        .height = 7,
        .weight = 400,
        .description = COMPOUND_STRING(
            "Life on mountains covered with deep snow\n"
            "has granted this Pokémon a body of ice\n"
            "that's as hard as steel.\n"
            "Predators go after its soft belly."),
        .pokemonScale = 365,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SandshrewAlola,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        .backPic = gMonBackPic_SandshrewAlola,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SandshrewAlola,
        .shinyPalette = gMonShinyPalette_SandshrewAlola,
        .iconSprite = gMonIcon_SandshrewAlola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, -1, SHADOW_SIZE_M)
        FOOTPRINT(Sandshrew)
        OVERWORLD(
            sPicTable_SandshrewAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SandshrewAlola,
            gShinyOverworldPalette_SandshrewAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sSandshrewAlolaLevelUpLearnset,
        .teachableLearnset = sSandshrewAlolaTeachableLearnset,
        .eggMoveLearnset = sSandshrewAlolaEggMoveLearnset,
        .formSpeciesIdTable = sSandshrewFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_ICE_STONE, SPECIES_SANDSLASH_ALOLA}),
    },

    [SPECIES_SANDSLASH_ALOLA] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 65,
        .baseSpAttack  = 25,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ICE, TYPE_STEEL),
        .catchRate = 90,
        .expYield = 158,
        .evYield_Defense = 2,
        .itemRare = ITEM_GRIP_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SLUSH_RUSH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Sandslash"),
        .cryId = CRY_SANDSLASH,
        .natDexNum = NATIONAL_DEX_SANDSLASH,
        .categoryName = _("Mouse"),
        .height = 12,
        .weight = 550,
        .description = COMPOUND_STRING(
            "It uses large, hooked claws to cut a path\n"
            "through deep snow as it runs.\n"
            "On snowy mountains, this Sandslash\n"
            "is faster than any other Pokémon."),
        .pokemonScale = 341,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SandslashAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 15,
        .backPic = gMonBackPic_SandslashAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SandslashAlola,
        .shinyPalette = gMonShinyPalette_SandslashAlola,
        .iconSprite = gMonIcon_SandslashAlola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 9, SHADOW_SIZE_L)
        FOOTPRINT(Sandslash)
        OVERWORLD(
            sPicTable_SandslashAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SandslashAlola,
            gShinyOverworldPalette_SandslashAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sSandslashAlolaLevelUpLearnset,
        .teachableLearnset = sSandslashAlolaTeachableLearnset,
        .formSpeciesIdTable = sSandslashFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_SANDSHREW

#if P_FAMILY_NIDORAN
    [SPECIES_NIDORAN_F] =
    {
        .baseHP        = 55,
        .baseAttack    = 47,
        .baseDefense   = 52,
        .baseSpeed     = 41,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 235,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 55 : 59,
        .evYield_HP = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_POISON_POINT, ABILITY_RIVALRY, ABILITY_HUSTLE },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_NONE, ABILITY_HUSTLE },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Nidoran♀"),
        .cryId = CRY_NIDORAN_F,
        .natDexNum = NATIONAL_DEX_NIDORAN_F,
        .categoryName = _("Poison Pin"),
        .height = 4,
        .weight = 70,
        .description = COMPOUND_STRING(
            "Its highly toxic barbs are thought to have\n"
            "developed as protection for this small-\n"
            "bodied Pokémon. When enraged, it releases\n"
            "a horrible toxin from its horn."),
        .pokemonScale = 488,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_NidoranF,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 50),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = 28,
        .backPic = gMonBackPic_NidoranF,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_NidoranF,
        .shinyPalette = gMonShinyPalette_NidoranF,
        .iconSprite = gMonIcon_NidoranF,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 0, SHADOW_SIZE_S)
        FOOTPRINT(NidoranF)
        OVERWORLD(
            sPicTable_NidoranF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_NidoranF,
            gShinyOverworldPalette_NidoranF
        )
        .levelUpLearnset = sNidoranFLevelUpLearnset,
        .teachableLearnset = sNidoranFTeachableLearnset,
        .eggMoveLearnset = sNidoranFEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_NIDORINA}),
    },

    [SPECIES_NIDORINA] =
    {
        .baseHP        = 70,
        .baseAttack    = 62,
        .baseDefense   = 67,
        .baseSpeed     = 56,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 128 : 117,
        .evYield_HP = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_POISON_POINT, ABILITY_RIVALRY, ABILITY_HUSTLE },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_NONE, ABILITY_HUSTLE },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Nidorina"),
        .cryId = CRY_NIDORINA,
        .natDexNum = NATIONAL_DEX_NIDORINA,
        .categoryName = _("Poison Pin"),
        .height = 8,
        .weight = 200,
        .description = COMPOUND_STRING(
            "When it is with its friends or\n"
            "family, its barbs are tucked away to\n"
            "prevent injury. It appears to become\n"
            "nervous if separated from the others."),
        .pokemonScale = 381,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nidorina,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Nidorina,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 5,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Nidorina,
        .shinyPalette = gMonShinyPalette_Nidorina,
        .iconSprite = gMonIcon_Nidorina,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Nidorina)
        OVERWORLD(
            sPicTable_Nidorina,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nidorina,
            gShinyOverworldPalette_Nidorina
        )
        .levelUpLearnset = sNidorinaLevelUpLearnset,
        .teachableLearnset = sNidorinaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_NIDOQUEEN}),
    },

    [SPECIES_NIDOQUEEN] =
    {
        .baseHP        = 90,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 92 : 82,
        .baseDefense   = 87,
        .baseSpeed     = 76,
        .baseSpAttack  = 75,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 85 : 75,
        .types = MON_TYPES(TYPE_POISON, TYPE_GROUND),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 253,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 227,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 223,
    #else
        .expYield = 194,
    #endif
        .evYield_HP = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_POISON_POINT, ABILITY_RIVALRY, ABILITY_SHEER_FORCE },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_NONE, ABILITY_SHEER_FORCE },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Nidoqueen"),
        .cryId = CRY_NIDOQUEEN,
        .natDexNum = NATIONAL_DEX_NIDOQUEEN,
        .categoryName = _("Drill"),
        .height = 13,
        .weight = 600,
        .description = COMPOUND_STRING(
            "It is adept at sending foes flying with\n"
            "harsh tackles using its tough, scaly body.\n"
            "This Pokémon is at its strongest when\n"
            "it is defending its young."),
        .pokemonScale = 293,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nidoqueen,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Nidoqueen,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Nidoqueen,
        .shinyPalette = gMonShinyPalette_Nidoqueen,
        .iconSprite = gMonIcon_Nidoqueen,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Nidoqueen)
        OVERWORLD(
            sPicTable_Nidoqueen,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nidoqueen,
            gShinyOverworldPalette_Nidoqueen
        )
        .levelUpLearnset = sNidoqueenLevelUpLearnset,
        .teachableLearnset = sNidoqueenTeachableLearnset,
    },

    [SPECIES_NIDORAN_M] =
    {
        .baseHP        = 46,
        .baseAttack    = 57,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 235,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 55 : 60,
        .evYield_Attack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_POISON_POINT, ABILITY_RIVALRY, ABILITY_HUSTLE },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_NONE, ABILITY_HUSTLE },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Nidoran♂"),
        .cryId = CRY_NIDORAN_M,
        .natDexNum = NATIONAL_DEX_NIDORAN_M,
        .categoryName = _("Poison Pin"),
        .height = 5,
        .weight = 90,
        .description = COMPOUND_STRING(
            "The male Nidoran has developed muscles\n"
            "that freely move its ears in any direction.\n"
            "Even the slightest sound does not escape\n"
            "this Pokémon's notice."),
        .pokemonScale = 511,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_NidoranM,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_NidoranM,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_NidoranM,
        .shinyPalette = gMonShinyPalette_NidoranM,
        .iconSprite = gMonIcon_NidoranM,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 0, SHADOW_SIZE_S)
        FOOTPRINT(NidoranM)
        OVERWORLD(
            sPicTable_NidoranM,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_NidoranM,
            gShinyOverworldPalette_NidoranM
        )
        .levelUpLearnset = sNidoranMLevelUpLearnset,
        .teachableLearnset = sNidoranMTeachableLearnset,
        .eggMoveLearnset = sNidoranMEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_NIDORINO}),
    },

    [SPECIES_NIDORINO] =
    {
        .baseHP        = 61,
        .baseAttack    = 72,
        .baseDefense   = 57,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 128 : 118,
        .evYield_Attack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_POISON_POINT, ABILITY_RIVALRY, ABILITY_HUSTLE },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_NONE, ABILITY_HUSTLE },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Nidorino"),
        .cryId = CRY_NIDORINO,
        .natDexNum = NATIONAL_DEX_NIDORINO,
        .categoryName = _("Poison Pin"),
        .height = 9,
        .weight = 195,
        .description = COMPOUND_STRING(
            "Its horn is harder than a diamond.\n"
            "If it senses a hostile presence, all the\n"
            "barbs on its back bristle up at once, and it\n"
            "challenges the foe with all its might."),
        .pokemonScale = 408,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nidorino,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 23),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SHRINK_GROW : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Nidorino,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Nidorino,
        .shinyPalette = gMonShinyPalette_Nidorino,
        .iconSprite = gMonIcon_Nidorino,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 1, SHADOW_SIZE_L)
        FOOTPRINT(Nidorino)
        OVERWORLD(
            sPicTable_Nidorino,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nidorino,
            gShinyOverworldPalette_Nidorino
        )
        .levelUpLearnset = sNidorinoLevelUpLearnset,
        .teachableLearnset = sNidorinoTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_NIDOKING}),
    },

    [SPECIES_NIDOKING] =
    {
        .baseHP        = 81,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 102 : 92,
        .baseDefense   = 77,
        .baseSpeed     = 85,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 85 : 75,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_POISON, TYPE_GROUND),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 253,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 227,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 223,
    #else
        .expYield = 195,
    #endif
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_POISON_POINT, ABILITY_RIVALRY, ABILITY_SHEER_FORCE },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_NONE, ABILITY_SHEER_FORCE },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Nidoking"),
        .cryId = CRY_NIDOKING,
        .natDexNum = NATIONAL_DEX_NIDOKING,
        .categoryName = _("Drill"),
        .height = 14,
        .weight = 620,
        .description = COMPOUND_STRING(
            "A Nidoking's thick tail packs enormously\n"
            "destructive power capable of toppling\n"
            "a metal transmission tower. Once it goes\n"
            "on a rampage, there is no stopping it."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nidoking,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 25,
        .backPic = gMonBackPic_Nidoking,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Nidoking,
        .shinyPalette = gMonShinyPalette_Nidoking,
        .iconSprite = gMonIcon_Nidoking,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Nidoking)
        OVERWORLD(
            sPicTable_Nidoking,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nidoking,
            gShinyOverworldPalette_Nidoking
        )
        .levelUpLearnset = sNidokingLevelUpLearnset,
        .teachableLearnset = sNidokingTeachableLearnset,
    },
#endif //P_FAMILY_NIDORAN

#if P_FAMILY_CLEFAIRY
#if P_UPDATED_TYPES >= GEN_6
    #define CLEFAIRY_FAMILY_TYPES { TYPE_FAIRY, TYPE_FAIRY }
#else
    #define CLEFAIRY_FAMILY_TYPES { TYPE_NORMAL, TYPE_NORMAL }
#endif

#if P_GEN_2_CROSS_EVOS
    [SPECIES_CLEFFA] =
    {
        .baseHP        = 50,
        .baseAttack    = 25,
        .baseDefense   = 28,
        .baseSpeed     = 15,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = CLEFAIRY_FAMILY_TYPES,
        .catchRate = 150,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 44 : 37,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_MAGIC_GUARD, ABILITY_FRIEND_GUARD },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_FRIEND_GUARD },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Cleffa"),
        .cryId = CRY_CLEFFA,
        .natDexNum = NATIONAL_DEX_CLEFFA,
        .categoryName = _("Star Shape"),
        .height = 3,
        .weight = 30,
        .description = COMPOUND_STRING(
            "On nights with many shooting stars,\n"
            "Cleffa can be seen dancing in a ring.\n"
            "They dance until daybreak, when they\n"
            "quench their thirst with the morning dew."),
        .pokemonScale = 462,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cleffa,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 18,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Cleffa,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Cleffa,
        .shinyPalette = gMonShinyPalette_Cleffa,
        .iconSprite = gMonIcon_Cleffa,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, -4, SHADOW_SIZE_S)
        FOOTPRINT(Cleffa)
        OVERWORLD(
            sPicTable_Cleffa,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cleffa,
            gShinyOverworldPalette_Cleffa
        )
        .levelUpLearnset = sCleffaLevelUpLearnset,
        .teachableLearnset = sCleffaTeachableLearnset,
        .eggMoveLearnset = sCleffaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_CLEFAIRY, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },
#endif //P_GEN_2_CROSS_EVOS

    [SPECIES_CLEFAIRY] =
    {
        .baseHP        = 70,
        .baseAttack    = 45,
        .baseDefense   = 48,
        .baseSpeed     = 35,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 65 : 60,
        .types = CLEFAIRY_FAMILY_TYPES,
        .catchRate = 150,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 113 : 68,
        .evYield_HP = 2,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_MAGIC_GUARD, ABILITY_FRIEND_GUARD },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_FRIEND_GUARD },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Clefairy"),
        .cryId = CRY_CLEFAIRY,
        .natDexNum = NATIONAL_DEX_CLEFAIRY,
        .categoryName = _("Fairy"),
        .height = 6,
        .weight = 75,
        .description = COMPOUND_STRING(
            "On every night of a full moon, they come\n"
            "out to play. When dawn arrives, the tired\n"
            "Clefairy go to sleep nestled up against\n"
            "each other in deep and quiet mountains."),
        .pokemonScale = 441,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Clefairy,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Clefairy,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 14,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Clefairy,
        .shinyPalette = gMonShinyPalette_Clefairy,
        .iconSprite = gMonIcon_Clefairy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Clefairy)
        OVERWORLD(
            sPicTable_Clefairy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Clefairy,
            gShinyOverworldPalette_Clefairy
        )
        .levelUpLearnset = sClefairyLevelUpLearnset,
        .teachableLearnset = sClefairyTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_CLEFABLE}),
    },

    [SPECIES_CLEFABLE] =
    {
        .baseHP        = 95,
        .baseAttack    = 70,
        .baseDefense   = 73,
        .baseSpeed     = 60,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 90 : 85,
        .types = CLEFAIRY_FAMILY_TYPES,
        .catchRate = 25,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 242,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 217,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 213,
    #else
        .expYield = 129,
    #endif
        .evYield_HP = 3,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_MAGIC_GUARD, ABILITY_UNAWARE },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_UNAWARE },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Clefable"),
        .cryId = CRY_CLEFABLE,
        .natDexNum = NATIONAL_DEX_CLEFABLE,
        .categoryName = _("Fairy"),
        .height = 13,
        .weight = 400,
        .description = COMPOUND_STRING(
            "A Clefable uses its wings to skip lightly \n"
            "as if it were flying. Its bouncy step\n"
            "lets it even walk on water. On quiet,\n"
            "moonlit nights, it strolls on lakes."),
        .pokemonScale = 256,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Clefable,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 48),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW : ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Clefable,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Clefable,
        .shinyPalette = gMonShinyPalette_Clefable,
        .iconSprite = gMonIcon_Clefable,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_M)
        FOOTPRINT(Clefable)
        OVERWORLD(
            sPicTable_Clefable,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Clefable,
            gShinyOverworldPalette_Clefable
        )
        .levelUpLearnset = sClefableLevelUpLearnset,
        .teachableLearnset = sClefableTeachableLearnset,
        .formSpeciesIdTable = sClefableFormSpeciesIdTable,
        .formChangeTable = sClefableFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_CLEFABLE_MEGA] =
    {
        .baseHP        = 95,
        .baseAttack    = 80,
        .baseDefense   = 93,
        .baseSpeed     = 70,
        .baseSpAttack  = 135,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_FLYING),
        .catchRate = 25,
        .expYield = 242,
        .evYield_HP = 3,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Clefable"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_CLEFABLE_MEGA,
    #else
        .cryId = CRY_CLEFABLE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_CLEFABLE,
        .categoryName = _("Fairy"),
        .height = 17,
        .weight = 423,
        .description = COMPOUND_STRING(
            "It flies by using the power of\n"
            "moonlight to control gravity within\n"
            "a radius of over 32 feet around it."),
        .frontPic = gMonFrontPic_ClefableMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_ClefableMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ClefableMega,
        .shinyPalette = gMonShinyPalette_ClefableMega,
        .iconSprite = gMonIcon_ClefableMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Clefable)
        SHADOW(5, 20, SHADOW_SIZE_S)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sClefableLevelUpLearnset,
        .teachableLearnset = sClefableTeachableLearnset,
        .formSpeciesIdTable = sClefableFormSpeciesIdTable,
        .formChangeTable = sClefableFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_CLEFAIRY

#if P_FAMILY_VULPIX
    [SPECIES_VULPIX] =
    {
        .baseHP        = 38,
        .baseAttack    = 41,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 50 : 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 63,
        .evYield_Speed = 1,
        .itemRare = ITEM_CHARCOAL,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_DROUGHT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Vulpix"),
        .cryId = CRY_VULPIX,
        .natDexNum = NATIONAL_DEX_VULPIX,
        .categoryName = _("Fox"),
        .height = 6,
        .weight = 99,
        .description = COMPOUND_STRING(
            "It can freely control fire, making fiery\n"
            "orbs fly like will-o'-the-wisps. Just\n"
            "before evolution, its six tails grow hot \n"
            "as if on fire."),
        .pokemonScale = 542,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vulpix,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Vulpix,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Vulpix,
        .shinyPalette = gMonShinyPalette_Vulpix,
        .iconSprite = gMonIcon_Vulpix,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 5,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(Vulpix)
        OVERWORLD(
            sPicTable_Vulpix,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vulpix,
            gShinyOverworldPalette_Vulpix
        )
        .levelUpLearnset = sVulpixLevelUpLearnset,
        .teachableLearnset = sVulpixTeachableLearnset,
        .eggMoveLearnset = sVulpixEggMoveLearnset,
        .formSpeciesIdTable = sVulpixFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_FIRE_STONE, SPECIES_NINETALES}),
    },

    [SPECIES_NINETALES] =
    {
        .baseHP        = 73,
        .baseAttack    = 76,
        .baseDefense   = 75,
        .baseSpeed     = 100,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 81 : 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 177 : 178,
        .evYield_Speed = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_CHARCOAL,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_DROUGHT },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Ninetales"),
        .cryId = CRY_NINETALES,
        .natDexNum = NATIONAL_DEX_NINETALES,
        .categoryName = _("Fox"),
        .height = 11,
        .weight = 199,
        .description = COMPOUND_STRING(
            "It has long been said that each of the\n"
            "nine tails embody an enchanted power.\n"
            "A long-lived Ninetales will have fur that\n"
            "shines like gold."),
        .pokemonScale = 339,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ninetales,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE : ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Ninetales,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Ninetales,
        .shinyPalette = gMonShinyPalette_Ninetales,
        .iconSprite = gMonIcon_Ninetales,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Ninetales)
        OVERWORLD(
            sPicTable_Ninetales,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ninetales,
            gShinyOverworldPalette_Ninetales
        )
        .levelUpLearnset = sNinetalesLevelUpLearnset,
        .teachableLearnset = sNinetalesTeachableLearnset,
        .formSpeciesIdTable = sNinetalesFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_VULPIX_ALOLA] =
    {
        .baseHP        = 38,
        .baseAttack    = 41,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 190,
        .expYield = 60,
        .evYield_Speed = 1,
        .itemRare = ITEM_SNOWBALL,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SNOW_WARNING },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Vulpix"),
        .cryId = CRY_VULPIX,
        .natDexNum = NATIONAL_DEX_VULPIX,
        .categoryName = _("Fox"),
        .height = 6,
        .weight = 99,
        .description = COMPOUND_STRING(
            "They live together in a skulk, helping\n"
            "one another. In hot weather, this Pokémon\n"
            "makes ice shards with its six tails and\n"
            "sprays them around to cool itself off."),
        .pokemonScale = 542,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_VulpixAlola,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_VulpixAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_VulpixAlola,
        .shinyPalette = gMonShinyPalette_VulpixAlola,
        .iconSprite = gMonIcon_VulpixAlola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 3, SHADOW_SIZE_M)
        FOOTPRINT(Vulpix)
        OVERWORLD(
            sPicTable_VulpixAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_VulpixAlola,
            gShinyOverworldPalette_VulpixAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sVulpixAlolaLevelUpLearnset,
        .teachableLearnset = sVulpixAlolaTeachableLearnset,
        .eggMoveLearnset = sVulpixAlolaEggMoveLearnset,
        .formSpeciesIdTable = sVulpixFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_ICE_STONE, SPECIES_NINETALES_ALOLA}),
    },

    [SPECIES_NINETALES_ALOLA] =
    {
        .baseHP        = 73,
        .baseAttack    = 67,
        .baseDefense   = 75,
        .baseSpeed     = 109,
        .baseSpAttack  = 81,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_ICE, TYPE_FAIRY),
        .catchRate = 75,
        .expYield = 177,
        .evYield_Speed = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SNOWBALL,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SNOW_WARNING },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Ninetales"),
        .cryId = CRY_NINETALES,
        .natDexNum = NATIONAL_DEX_NINETALES,
        .categoryName = _("Fox"),
        .height = 11,
        .weight = 199,
        .description = COMPOUND_STRING(
            "While it will guide travelers who get lost\n"
            "on a snowy mountain down to the\n"
            "mountain's base, it won't forgive anyone\n"
            "who harms nature."),
        .pokemonScale = 339,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_NinetalesAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_NinetalesAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_NinetalesAlola,
        .shinyPalette = gMonShinyPalette_NinetalesAlola,
        .iconSprite = gMonIcon_NinetalesAlola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Ninetales)
        OVERWORLD(
            sPicTable_NinetalesAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_NinetalesAlola,
            gShinyOverworldPalette_NinetalesAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sNinetalesAlolaLevelUpLearnset,
        .teachableLearnset = sNinetalesAlolaTeachableLearnset,
        .formSpeciesIdTable = sNinetalesFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_VULPIX

#if P_FAMILY_JIGGLYPUFF
#if P_UPDATED_TYPES >= GEN_6
    #define JIGGLYPUFF_FAMILY_TYPES { TYPE_NORMAL, TYPE_FAIRY}
#else
    #define JIGGLYPUFF_FAMILY_TYPES { TYPE_NORMAL, TYPE_NORMAL}
#endif

#if P_GEN_2_CROSS_EVOS
    [SPECIES_IGGLYBUFF] =
    {
        .baseHP        = 90,
        .baseAttack    = 30,
        .baseDefense   = 15,
        .baseSpeed     = 15,
        .baseSpAttack  = 40,
        .baseSpDefense = 20,
        .types = JIGGLYPUFF_FAMILY_TYPES,
        .catchRate = 170,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 42 : 39,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_COMPETITIVE, ABILITY_FRIEND_GUARD },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_FRIEND_GUARD },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Igglybuff"),
        .cryId = CRY_IGGLYBUFF,
        .natDexNum = NATIONAL_DEX_IGGLYBUFF,
        .categoryName = _("Balloon"),
        .height = 3,
        .weight = 10,
        .description = COMPOUND_STRING(
            "Its soft and pliable body is very bouncy.\n"
            "When it sings continuously with all its\n"
            "might, its body steadily turns a deepening\n"
            "pink color."),
        .pokemonScale = 457,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Igglybuff,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST,
        .backPic = gMonBackPic_Igglybuff,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Igglybuff,
        .shinyPalette = gMonShinyPalette_Igglybuff,
        .iconSprite = gMonIcon_Igglybuff,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -3, SHADOW_SIZE_S)
        FOOTPRINT(Igglybuff)
        OVERWORLD(
            sPicTable_Igglybuff,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Igglybuff,
            gShinyOverworldPalette_Igglybuff
        )
        .levelUpLearnset = sIgglybuffLevelUpLearnset,
        .teachableLearnset = sIgglybuffTeachableLearnset,
        .eggMoveLearnset = sIgglybuffEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_JIGGLYPUFF, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },
#endif //P_GEN_2_CROSS_EVOS

    [SPECIES_JIGGLYPUFF] =
    {
        .baseHP        = 115,
        .baseAttack    = 45,
        .baseDefense   = 20,
        .baseSpeed     = 20,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 45 : 25,
        .baseSpDefense = 25,
        .types = JIGGLYPUFF_FAMILY_TYPES,
        .catchRate = 170,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 95 : 76,
        .evYield_HP = 2,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_COMPETITIVE, ABILITY_FRIEND_GUARD },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_FRIEND_GUARD },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Jigglypuff"),
        .cryId = CRY_JIGGLYPUFF,
        .natDexNum = NATIONAL_DEX_JIGGLYPUFF,
        .categoryName = _("Balloon"),
        .height = 5,
        .weight = 55,
        .description = COMPOUND_STRING(
            "Nothing can avoid falling asleep hearing a\n"
            "Jigglypuff's song. The sound waves of its\n"
            "singing voice match the brain waves of\n"
            "someone in a deep sleep."),
        .pokemonScale = 433,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Jigglypuff,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .backPic = gMonBackPic_Jigglypuff,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Jigglypuff,
        .shinyPalette = gMonShinyPalette_Jigglypuff,
        .iconSprite = gMonIcon_Jigglypuff,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -1, SHADOW_SIZE_S)
        FOOTPRINT(Jigglypuff)
        OVERWORLD(
            sPicTable_Jigglypuff,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Jigglypuff,
            gShinyOverworldPalette_Jigglypuff
        )
        .levelUpLearnset = sJigglypuffLevelUpLearnset,
        .teachableLearnset = sJigglypuffTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_WIGGLYTUFF}),
    },

#if P_UPDATED_STATS >= GEN_6
    #define WIGGLYTUFF_SP_ATK   85
#elif P_UPDATED_STATS >= GEN_2
    #define WIGGLYTUFF_SP_ATK   75
#else
    #define WIGGLYTUFF_SP_ATK   50
#endif

    [SPECIES_WIGGLYTUFF] =
    {
        .baseHP        = 140,
        .baseAttack    = 70,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = WIGGLYTUFF_SP_ATK,
        .baseSpDefense = 50,
        .types = JIGGLYPUFF_FAMILY_TYPES,
        .catchRate = 50,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 218,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 196,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 191,
    #else
        .expYield = 109,
    #endif
        .evYield_HP = 3,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_COMPETITIVE, ABILITY_FRISK },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_FRISK },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Wigglytuff"),
        .cryId = CRY_WIGGLYTUFF,
        .natDexNum = NATIONAL_DEX_WIGGLYTUFF,
        .categoryName = _("Balloon"),
        .height = 10,
        .weight = 120,
        .description = COMPOUND_STRING(
            "Its fur is the ultimate in luxuriousness.\n"
            "Sleeping alongside a Wigglytuff is simply\n"
            "divine. Its body expands seemingly without\n"
            "end when it inhales."),
        .pokemonScale = 328,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wigglytuff,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = gMonBackPic_Wigglytuff,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Wigglytuff,
        .shinyPalette = gMonShinyPalette_Wigglytuff,
        .iconSprite = gMonIcon_Wigglytuff,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Wigglytuff)
        OVERWORLD(
            sPicTable_Wigglytuff,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wigglytuff,
            gShinyOverworldPalette_Wigglytuff
        )
        .levelUpLearnset = sWigglytuffLevelUpLearnset,
        .teachableLearnset = sWigglytuffTeachableLearnset,
    },
#endif //P_FAMILY_JIGGLYPUFF

#if P_FAMILY_ZUBAT
    [SPECIES_ZUBAT] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 55,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 30 : 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_POISON, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 49 : 54,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Zubat"),
        .cryId = CRY_ZUBAT,
        .natDexNum = NATIONAL_DEX_ZUBAT,
        .categoryName = _("Bat"),
        .height = 8,
        .weight = 75,
        .description = COMPOUND_STRING(
            "While living in pitch-black caverns, their\n"
            "eyes gradually grew shut and deprived\n"
            "them of vision. They use ultrasonic waves\n"
            "to detect obstacles."),
        .pokemonScale = 362,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Zubat,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 16,
        .backPic = gMonBackPic_Zubat,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Zubat,
        .shinyPalette = gMonShinyPalette_Zubat,
        .iconSprite = gMonIcon_Zubat,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_ZubatF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 48),
        .backPicFemale = gMonBackPic_ZubatF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 11, SHADOW_SIZE_S)
        FOOTPRINT(Zubat)
        OVERWORLD(
            sPicTable_Zubat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zubat,
            gShinyOverworldPalette_Zubat
        )
        OVERWORLD_FEMALE(
            sPicTable_ZubatF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sZubatLevelUpLearnset,
        .teachableLearnset = sZubatTeachableLearnset,
        .eggMoveLearnset = sZubatEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_GOLBAT}),
    },

    [SPECIES_GOLBAT] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 65 : 75,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_POISON, TYPE_FLYING),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 171,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Golbat"),
        .cryId = CRY_GOLBAT,
        .natDexNum = NATIONAL_DEX_GOLBAT,
        .categoryName = _("Bat"),
        .height = 16,
        .weight = 550,
        .description = COMPOUND_STRING(
            "Its fangs easily puncture even thick\n"
            "animal hide. It loves to feast on the blood\n"
            "of people and Pokémon. It flits about in\n"
            "darkness and strikes from behind."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Golbat,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .backPic = gMonBackPic_Golbat,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Golbat,
        .shinyPalette = gMonShinyPalette_Golbat,
        .iconSprite = gMonIcon_Golbat,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GolbatF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_GolbatF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 40),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Golbat)
        OVERWORLD(
            sPicTable_Golbat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Golbat,
            gShinyOverworldPalette_Golbat
        )
        OVERWORLD_FEMALE(
            sPicTable_GolbatF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGolbatLevelUpLearnset,
        .teachableLearnset = sGolbatTeachableLearnset,
    #if P_GEN_2_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_CROBAT, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    #endif
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_CROBAT] =
    {
        .baseHP        = 85,
        .baseAttack    = 90,
        .baseDefense   = 80,
        .baseSpeed     = 130,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_POISON, TYPE_FLYING),
        .catchRate = 90,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 268,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 241,
    #else
        .expYield = 204,
    #endif
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Crobat"),
        .cryId = CRY_CROBAT,
        .natDexNum = NATIONAL_DEX_CROBAT,
        .categoryName = _("Bat"),
        .height = 18,
        .weight = 750,
        .description = COMPOUND_STRING(
            "Over the course of evolution, its hind legs\n"
            "turned into wings. By alternately resting\n"
            "its front and rear wings, it can fly all day\n"
            "without having to stop."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 281,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Crobat,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 9,
        .backPic = gMonBackPic_Crobat,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 1,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Crobat,
        .shinyPalette = gMonShinyPalette_Crobat,
        .iconSprite = gMonIcon_Crobat,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 14, SHADOW_SIZE_M)
        FOOTPRINT(Crobat)
        OVERWORLD(
            sPicTable_Crobat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Crobat,
            gShinyOverworldPalette_Crobat
        )
        .levelUpLearnset = sCrobatLevelUpLearnset,
        .teachableLearnset = sCrobatTeachableLearnset,
    },
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_ZUBAT

#if P_FAMILY_ODDISH
    [SPECIES_ODDISH] =
    {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 75,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 65 : 75,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 64 : 78,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Oddish"),
        .cryId = CRY_ODDISH,
        .natDexNum = NATIONAL_DEX_ODDISH,
        .categoryName = _("Weed"),
        .height = 5,
        .weight = 54,
        .description = COMPOUND_STRING(
            "This Pokémon grows by absorbing moonlight.\n"
            "During the daytime, it buries itself in the\n"
            "ground, leaving only its leaves exposed to\n"
            "avoid detection by its enemies."),
        .pokemonScale = 423,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Oddish,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Oddish,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 10,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Oddish,
        .shinyPalette = gMonShinyPalette_Oddish,
        .iconSprite = gMonIcon_Oddish,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 4,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -2, SHADOW_SIZE_S)
        FOOTPRINT(Oddish)
        OVERWORLD(
            sPicTable_Oddish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Oddish,
            gShinyOverworldPalette_Oddish
        )
        .levelUpLearnset = sOddishLevelUpLearnset,
        .teachableLearnset = sOddishTeachableLearnset,
        .eggMoveLearnset = sOddishEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 21, SPECIES_GLOOM}),
    },

    [SPECIES_GLOOM] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 85,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 75 : 85,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 138 : 132,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_STENCH },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Gloom"),
        .cryId = CRY_GLOOM,
        .natDexNum = NATIONAL_DEX_GLOOM,
        .categoryName = _("Weed"),
        .height = 8,
        .weight = 86,
        .description = COMPOUND_STRING(
            "A horribly noxious honey drools from its\n"
            "mouth. One whiff of the honey can result\n"
            "in memory loss. Some fans are said to\n"
            "enjoy this overwhelming stink, however."),
        .pokemonScale = 329,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gloom,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 21),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Gloom,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Gloom,
        .shinyPalette = gMonShinyPalette_Gloom,
        .iconSprite = gMonIcon_Gloom,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GloomF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 48),
        .backPicFemale = gMonBackPic_GloomF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 3, SHADOW_SIZE_M)
        FOOTPRINT(Gloom)
        OVERWORLD(
            sPicTable_Gloom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gloom,
            gShinyOverworldPalette_Gloom
        )
        OVERWORLD_FEMALE(
            sPicTable_GloomF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGloomLevelUpLearnset,
        .teachableLearnset = sGloomTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_VILEPLUME}
                            #if P_GEN_2_CROSS_EVOS
                                ,{EVO_ITEM, ITEM_SUN_STONE, SPECIES_BELLOSSOM}
                            #endif
                            ),
    },

    [SPECIES_VILEPLUME] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 85,
        .baseSpeed     = 50,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_6 ? 110 : 100,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 90 : 100,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 245,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 221,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 216,
    #else
        .expYield = 184,
    #endif
        .evYield_SpAttack = 3,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_EFFECT_SPORE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Vileplume"),
        .cryId = CRY_VILEPLUME,
        .natDexNum = NATIONAL_DEX_VILEPLUME,
        .categoryName = _("Flower"),
        .height = 12,
        .weight = 186,
        .description = COMPOUND_STRING(
            "In seasons when it produces more pollen,\n"
            "the air around a Vileplume turns yellow\n"
            "with the powder as it walks. The pollen is\n"
            "highly toxic and causes paralysis."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vileplume,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 38),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW : ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Vileplume,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Vileplume,
        .shinyPalette = gMonShinyPalette_Vileplume,
        .iconSprite = gMonIcon_Vileplume,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_VileplumeF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_VileplumeF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Vileplume)
        OVERWORLD(
            sPicTable_Vileplume,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vileplume,
            gShinyOverworldPalette_Vileplume
        )
        OVERWORLD_FEMALE(
            sPicTable_VileplumeF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sVileplumeLevelUpLearnset,
        .teachableLearnset = sVileplumeTeachableLearnset,
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_BELLOSSOM] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .baseSpeed     = 50,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 245,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 221,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 216,
    #else
        .expYield = 184,
    #endif
        .evYield_SpDefense = 3,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_HEALER },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bellossom"),
        .cryId = CRY_BELLOSSOM,
        .natDexNum = NATIONAL_DEX_BELLOSSOM,
        .categoryName = _("Flower"),
        .height = 4,
        .weight = 58,
        .description = COMPOUND_STRING(
            "Its flower petals deepen in color through\n"
            "exposure to sunlight. When cloudy weather\n"
            "persists, it does a dance that is thought\n"
            "to be a ritual for summoning the sun."),
        .pokemonScale = 472,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bellossom,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE : ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Bellossom,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Bellossom,
        .shinyPalette = gMonShinyPalette_Bellossom,
        .iconSprite = gMonIcon_Bellossom,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Bellossom)
        OVERWORLD(
            sPicTable_Bellossom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bellossom,
            gShinyOverworldPalette_Bellossom
        )
        .levelUpLearnset = sBellossomLevelUpLearnset,
        .teachableLearnset = sBellossomTeachableLearnset,
    },
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_ODDISH

#if P_FAMILY_PARAS
    [SPECIES_PARAS] =
    {
        .baseHP        = 35,
        .baseAttack    = 70,
        .baseDefense   = 55,
        .baseSpeed     = 25,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 45 : 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_BUG, TYPE_GRASS),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 57 : 70,
        .evYield_Attack = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_DRY_SKIN, ABILITY_DAMP },
    #else
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_DAMP },
    #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Paras"),
        .cryId = CRY_PARAS,
        .natDexNum = NATIONAL_DEX_PARAS,
        .categoryName = _("Mushroom"),
        .height = 3,
        .weight = 54,
        .description = COMPOUND_STRING(
            "A Paras has parasitic tochukaso\n"
            "mushrooms growing on its back. They grow\n"
            "by drawing nutrients from the host. They\n"
            "are valued as a medicine for long life."),
        .pokemonScale = 593,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Paras,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Paras,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 24) : MON_COORDS_SIZE(64, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 18,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Paras,
        .shinyPalette = gMonShinyPalette_Paras,
        .iconSprite = gMonIcon_Paras,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(7, -11, SHADOW_SIZE_M)
        FOOTPRINT(Paras)
        OVERWORLD(
            sPicTable_Paras,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Paras,
            gShinyOverworldPalette_Paras
        )
        .levelUpLearnset = sParasLevelUpLearnset,
        .teachableLearnset = sParasTeachableLearnset,
        .eggMoveLearnset = sParasEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_PARASECT}),
    },

    [SPECIES_PARASECT] =
    {
        .baseHP        = 60,
        .baseAttack    = 95,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 60 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_GRASS),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 128,
        .evYield_Attack = 2,
        .evYield_Defense = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_DRY_SKIN, ABILITY_DAMP },
    #else
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_DAMP },
    #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Parasect"),
        .cryId = CRY_PARASECT,
        .natDexNum = NATIONAL_DEX_PARASECT,
        .categoryName = _("Mushroom"),
        .height = 10,
        .weight = 295,
        .description = COMPOUND_STRING(
            "Parasect are known to infest the roots of\n"
            "large trees en masse and drain nutrients.\n"
            "When an infested tree dies, they move\n"
            "onto another tree all at once."),
        .pokemonScale = 307,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Parasect,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 45,
        .backPic = gMonBackPic_Parasect,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 13,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Parasect,
        .shinyPalette = gMonShinyPalette_Parasect,
        .iconSprite = gMonIcon_Parasect,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 2, SHADOW_SIZE_L)
        FOOTPRINT(Parasect)
        OVERWORLD(
            sPicTable_Parasect,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Parasect,
            gShinyOverworldPalette_Parasect
        )
        .levelUpLearnset = sParasectLevelUpLearnset,
        .teachableLearnset = sParasectTeachableLearnset,
    },
#endif //P_FAMILY_PARAS

#if P_FAMILY_VENONAT
    [SPECIES_VENONAT] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 45,
        .baseSpAttack  = 40,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 55 : 40,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 61 : 75,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_TINTED_LENS, ABILITY_RUN_AWAY },
    #else
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_NONE, ABILITY_RUN_AWAY },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Venonat"),
        .cryId = CRY_VENONAT,
        .natDexNum = NATIONAL_DEX_VENONAT,
        .categoryName = _("Insect"),
        .height = 10,
        .weight = 300,
        .description = COMPOUND_STRING(
            "Its coat of thin, stiff hair that covers\n"
            "its entire body is said to have evolved\n"
            "for protection. Its large eyes never fail\n"
            "to spot even miniscule prey."),
        .pokemonScale = 360,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -1,
        .frontPic = gMonFrontPic_Venonat,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 35),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Venonat,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Venonat,
        .shinyPalette = gMonShinyPalette_Venonat,
        .iconSprite = gMonIcon_Venonat,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 5, SHADOW_SIZE_M)
        FOOTPRINT(Venonat)
        OVERWORLD(
            sPicTable_Venonat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Venonat,
            gShinyOverworldPalette_Venonat
        )
        .levelUpLearnset = sVenonatLevelUpLearnset,
        .teachableLearnset = sVenonatTeachableLearnset,
        .eggMoveLearnset = sVenonatEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_VENOMOTH}),
    },

    [SPECIES_VENOMOTH] =
    {
        .baseHP        = 70,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 90,
        .baseSpAttack  = 90,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 75 : 90,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 158 : 138,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_TINTED_LENS, ABILITY_WONDER_SKIN },
    #else
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_WONDER_SKIN },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Venomoth"),
        .cryId = CRY_VENOMOTH,
        .natDexNum = NATIONAL_DEX_VENOMOTH,
        .categoryName = _("Poison Moth"),
        .height = 15,
        .weight = 125,
        .description = COMPOUND_STRING(
            "Venomoth are nocturnal--they are only\n"
            "active at night. Their favorite prey are\n"
            "insects that gather around streetlights,\n"
            "attracted by the light in the darkness."),
        .pokemonScale = 285,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Venomoth,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 16,
        .backPic = gMonBackPic_Venomoth,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Venomoth,
        .shinyPalette = gMonShinyPalette_Venomoth,
        .iconSprite = gMonIcon_Venomoth,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 18, SHADOW_SIZE_M)
        FOOTPRINT(Venomoth)
        OVERWORLD(
            sPicTable_Venomoth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Venomoth,
            gShinyOverworldPalette_Venomoth
        )
        .levelUpLearnset = sVenomothLevelUpLearnset,
        .teachableLearnset = sVenomothTeachableLearnset,
    },
#endif //P_FAMILY_VENONAT

#if P_FAMILY_DIGLETT
    [SPECIES_DIGLETT] =
    {
        .baseHP        = 10,
        .baseAttack    = 55,
        .baseDefense   = 25,
        .baseSpeed     = 95,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 35 : 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 53 : 81,
        .evYield_Speed = 1,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_ARENA_TRAP, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Diglett"),
        .cryId = CRY_DIGLETT,
        .natDexNum = NATIONAL_DEX_DIGLETT,
        .categoryName = _("Mole"),
        .height = 2,
        .weight = 8,
        .description = COMPOUND_STRING(
            "Diglett are raised in most farms.\n"
            "The reason is simple--wherever they\n"
            "burrow, the soil is left perfectly tilled\n"
            "for growing delicious crops."),
        .pokemonScale = 833,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Diglett,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .frontAnimDelay = 25,
        .backPic = gMonBackPic_Diglett,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(40, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 14,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Diglett,
        .shinyPalette = gMonShinyPalette_Diglett,
        .iconSprite = gMonIcon_Diglett,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Diglett)
        OVERWORLD(
            sPicTable_Diglett,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Diglett,
            gShinyOverworldPalette_Diglett
        )
        .isTelekinesisBanned = TRUE,
        .levelUpLearnset = sDiglettLevelUpLearnset,
        .teachableLearnset = sDiglettTeachableLearnset,
        .eggMoveLearnset = sDiglettEggMoveLearnset,
        .formSpeciesIdTable = sDiglettFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_DUGTRIO}),
    },

    [SPECIES_DUGTRIO] =
    {
        .baseHP        = 35,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 100 : 80,
        .baseDefense   = 50,
        .baseSpeed     = 120,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 50 : 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 50,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 149,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 142,
    #else
        .expYield = 153,
    #endif
        .evYield_Speed = 2,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_ARENA_TRAP, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Dugtrio"),
        .cryId = CRY_DUGTRIO,
        .natDexNum = NATIONAL_DEX_DUGTRIO,
        .categoryName = _("Mole"),
        .height = 7,
        .weight = 333,
        .description = COMPOUND_STRING(
            "Because the triplets originally split from\n"
            "one body, they think exactly alike.\n"
            "They work cooperatively to burrow\n"
            "endlessly through the ground."),
        .pokemonScale = 406,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dugtrio,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        .frontAnimDelay = 35,
        .backPic = gMonBackPic_Dugtrio,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 17,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Dugtrio,
        .shinyPalette = gMonShinyPalette_Dugtrio,
        .iconSprite = gMonIcon_Dugtrio,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Dugtrio)
        OVERWORLD(
            sPicTable_Dugtrio,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Dugtrio,
            gShinyOverworldPalette_Dugtrio
        )
        .isTelekinesisBanned = TRUE,
        .levelUpLearnset = sDugtrioLevelUpLearnset,
        .teachableLearnset = sDugtrioTeachableLearnset,
        .formSpeciesIdTable = sDugtrioFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_DIGLETT_ALOLA] =
    {
        .baseHP        = 10,
        .baseAttack    = 55,
        .baseDefense   = 30,
        .baseSpeed     = 90,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 255,
        .expYield = 53,
        .evYield_Speed = 1,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_TANGLING_HAIR, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Diglett"),
        .cryId = CRY_DIGLETT,
        .natDexNum = NATIONAL_DEX_DIGLETT,
        .categoryName = _("Mole"),
        .height = 2,
        .weight = 10,
        .description = COMPOUND_STRING(
            "The metal-rich geology of its habitat\n"
            "caused it to develop steel whiskers on its\n"
            "head that change shape depending on its\n"
            "mood and when communicating with others."),
        .pokemonScale = 833,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DiglettAlola,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 19,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .frontAnimDelay = 25,
        .backPic = gMonBackPic_DiglettAlola,
        .backPicSize = MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DiglettAlola,
        .shinyPalette = gMonShinyPalette_DiglettAlola,
        .iconSprite = gMonIcon_DiglettAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Diglett)
        OVERWORLD(
            sPicTable_DiglettAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DiglettAlola,
            gShinyOverworldPalette_DiglettAlola
        )
        .isAlolanForm = TRUE,
        .isTelekinesisBanned = TRUE,
        .levelUpLearnset = sDiglettAlolaLevelUpLearnset,
        .teachableLearnset = sDiglettAlolaTeachableLearnset,
        .eggMoveLearnset = sDiglettAlolaEggMoveLearnset,
        .formSpeciesIdTable = sDiglettFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_DUGTRIO_ALOLA}),
    },

    [SPECIES_DUGTRIO_ALOLA] =
    {
        .baseHP        = 35,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 50,
        .expYield = 149,
        .evYield_Speed = 2,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_TANGLING_HAIR, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Dugtrio"),
        .cryId = CRY_DUGTRIO,
        .natDexNum = NATIONAL_DEX_DUGTRIO,
        .categoryName = _("Mole"),
        .height = 7,
        .weight = 666,
        .description = COMPOUND_STRING(
            "Their beautiful, metallic whiskers create\n"
            "a sort of protective helmet on\n"
            "heir heads, and they also function\n"
            "as highly precise sensors."),
        .pokemonScale = 406,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DugtrioAlola,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        .frontAnimDelay = 35,
        .backPic = gMonBackPic_DugtrioAlola,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DugtrioAlola,
        .shinyPalette = gMonShinyPalette_DugtrioAlola,
        .iconSprite = gMonIcon_DugtrioAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Dugtrio)
        OVERWORLD(
            sPicTable_DugtrioAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_DugtrioAlola,
            gShinyOverworldPalette_DugtrioAlola
        )
        .isAlolanForm = TRUE,
        .isTelekinesisBanned = TRUE,
        .levelUpLearnset = sDugtrioAlolaLevelUpLearnset,
        .teachableLearnset = sDugtrioAlolaTeachableLearnset,
        .formSpeciesIdTable = sDugtrioFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_DIGLETT

#if P_FAMILY_MEOWTH
#if P_UPDATED_ABILITIES >= GEN_4
    #define MEOWTH_ABILITIES { ABILITY_PICKUP, ABILITY_TECHNICIAN, ABILITY_UNNERVE }
#else
    #define MEOWTH_ABILITIES { ABILITY_PICKUP, ABILITY_NONE, ABILITY_UNNERVE }
#endif

    [SPECIES_MEOWTH] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 69,
        .evYield_Speed = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = MEOWTH_ABILITIES,
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Meowth"),
        .cryId = CRY_MEOWTH,
        .natDexNum = NATIONAL_DEX_MEOWTH,
        .categoryName = _("Scratch Cat"),
        .height = 4,
        .weight = 42,
        .description = COMPOUND_STRING(
            "Meowth withdraw their sharp claws into\n"
            "their paws to silently sneak about.\n"
            "For some reason, this Pokémon loves\n"
            "shiny coins that glitter with light."),
        .pokemonScale = 480,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Meowth,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 17),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .frontAnimDelay = 40,
        .backPic = gMonBackPic_Meowth,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Meowth,
        .shinyPalette = gMonShinyPalette_Meowth,
        .iconSprite = gMonIcon_Meowth,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 3, SHADOW_SIZE_S)
        FOOTPRINT(Meowth)
        OVERWORLD(
            sPicTable_Meowth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Meowth,
            gShinyOverworldPalette_Meowth
        )
        .levelUpLearnset = sMeowthLevelUpLearnset,
        .teachableLearnset = sMeowthTeachableLearnset,
        .eggMoveLearnset = sMeowthEggMoveLearnset,
        .formSpeciesIdTable = sMeowthFormSpeciesIdTable,
        .formChangeTable = sMeowthFormChangeTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_PERSIAN}),
    },

    [SPECIES_PERSIAN] =
    {
        .baseHP        = 65,
        .baseAttack    = 70,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 154 : 148,
        .evYield_Speed = 2,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_LIMBER, ABILITY_TECHNICIAN, ABILITY_UNNERVE },
    #else
        .abilities = { ABILITY_LIMBER, ABILITY_NONE, ABILITY_UNNERVE },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Persian"),
        .cryId = CRY_PERSIAN,
        .natDexNum = NATIONAL_DEX_PERSIAN,
        .categoryName = _("Classy Cat"),
        .height = 10,
        .weight = 320,
        .description = COMPOUND_STRING(
            "A Persian's six bold whiskers sense air\n"
            "movements to determine what is in its\n"
            "vicinity. It becomes docile if grabbed\n"
            "by the whiskers."),
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Persian,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Persian,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Persian,
        .shinyPalette = gMonShinyPalette_Persian,
        .iconSprite = gMonIcon_Persian,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Persian)
        OVERWORLD(
            sPicTable_Persian,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Persian,
            gShinyOverworldPalette_Persian
        )
        .levelUpLearnset = sPersianLevelUpLearnset,
        .teachableLearnset = sPersianTeachableLearnset,
        .formSpeciesIdTable = sPersianFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_MEOWTH_ALOLA] =
    {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 255,
        .expYield = 58,
        .evYield_Speed = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PICKUP, ABILITY_TECHNICIAN, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Meowth"),
        .cryId = CRY_MEOWTH,
        .natDexNum = NATIONAL_DEX_MEOWTH,
        .categoryName = _("Scratch Cat"),
        .height = 4,
        .weight = 42,
        .description = COMPOUND_STRING(
            "It's accustomed to luxury because it used\n"
            "to live with Alolan royalty. Highly smart\n"
            "and proud, it's famously difficult to\n"
            "handle, but that also makes it popular."),
        .pokemonScale = 480,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MeowthAlola,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
		    ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .frontAnimDelay = 45,
        .backPic = gMonBackPic_MeowthAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MeowthAlola,
        .shinyPalette = gMonShinyPalette_MeowthAlola,
        .iconSprite = gMonIcon_MeowthAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 5, SHADOW_SIZE_M)
        FOOTPRINT(Meowth)
        OVERWORLD(
            sPicTable_MeowthAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MeowthAlola,
            gShinyOverworldPalette_MeowthAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sMeowthAlolaLevelUpLearnset,
        .teachableLearnset = sMeowthAlolaTeachableLearnset,
        .eggMoveLearnset = sMeowthAlolaEggMoveLearnset,
        .formSpeciesIdTable = sMeowthFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_PERSIAN_ALOLA, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },

    [SPECIES_PERSIAN_ALOLA] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 75,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 90,
        .expYield = 154,
        .evYield_Speed = 2,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FUR_COAT, ABILITY_TECHNICIAN, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Persian"),
        .cryId = CRY_PERSIAN,
        .natDexNum = NATIONAL_DEX_PERSIAN,
        .categoryName = _("Classy Cat"),
        .height = 11,
        .weight = 330,
        .description = COMPOUND_STRING(
            "It looks down on everyone other than\n"
            "itself. In contrast to its lovely face, it\n"
            "is so brutal that it tortures its weakened\n"
            "prey rather than finishing them off."),
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PersianAlola,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_PersianAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PersianAlola,
        .shinyPalette = gMonShinyPalette_PersianAlola,
        .iconSprite = gMonIcon_PersianAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_L)
        FOOTPRINT(Persian)
        OVERWORLD(
            sPicTable_PersianAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_PersianAlola,
            gShinyOverworldPalette_PersianAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sPersianAlolaLevelUpLearnset,
        .teachableLearnset = sPersianAlolaTeachableLearnset,
        .formSpeciesIdTable = sPersianFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS

#if P_GALARIAN_FORMS
    [SPECIES_MEOWTH_GALAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 255,
        .expYield = 58,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PICKUP, ABILITY_TOUGH_CLAWS, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Meowth"),
        .cryId = CRY_MEOWTH,
        .natDexNum = NATIONAL_DEX_MEOWTH,
        .categoryName = _("Scratch Cat"),
        .height = 4,
        .weight = 75,
        .description = COMPOUND_STRING(
            "Living with a savage, seafaring people has\n"
            "hardened its body so much that parts of it\n"
            "turned to iron. Darker coins are harder\n"
            "and garner more respect among Meowth."),
        .pokemonScale = 480,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MeowthGalar,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MeowthGalar,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MeowthGalar,
        .shinyPalette = gMonShinyPalette_MeowthGalar,
        .iconSprite = gMonIcon_MeowthGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 4, SHADOW_SIZE_M)
        FOOTPRINT(Meowth)
        OVERWORLD(
            sPicTable_MeowthGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MeowthGalar,
            gShinyOverworldPalette_MeowthGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sMeowthGalarLevelUpLearnset,
        .teachableLearnset = sMeowthGalarTeachableLearnset,
        .eggMoveLearnset = sMeowthGalarEggMoveLearnset,
        .formSpeciesIdTable = sMeowthFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_PERRSERKER}),
    },

    [SPECIES_PERRSERKER] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 90,
        .expYield = 154,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_TOUGH_CLAWS, ABILITY_STEELY_SPIRIT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Perrserker"),
        .cryId = CRY_PERRSERKER,
        .natDexNum = NATIONAL_DEX_PERRSERKER,
        .categoryName = _("Viking"),
        .height = 8,
        .weight = 280,
        .description = COMPOUND_STRING(
            "What appears to be an iron helmet is\n"
            "actually hardened hair. This Pokémon\n"
            "lives for the thrill of battle."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Perrserker,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Perrserker,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Perrserker,
        .shinyPalette = gMonShinyPalette_Perrserker,
        .iconSprite = gMonIcon_Perrserker,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Perrserker)
        OVERWORLD(
            sPicTable_Perrserker,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Perrserker,
            gShinyOverworldPalette_Perrserker
        )
        .levelUpLearnset = sPerrserkerLevelUpLearnset,
        .teachableLearnset = sPerrserkerTeachableLearnset,
    },
#endif //P_GALARIAN_FORMS

#if P_GIGANTAMAX_FORMS
    [SPECIES_MEOWTH_GMAX] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 69,
        .evYield_Speed = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = MEOWTH_ABILITIES,
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Meowth"),
        .cryId = CRY_MEOWTH,
        .natDexNum = NATIONAL_DEX_MEOWTH,
        .categoryName = _("Scratch Cat"),
        .height = 330,
        .weight = 0,
        .description = COMPOUND_STRING(
            "The pattern that has appeared on\n"
            "its giant coin is thought to be the\n"
            "key to unlocking the secrets of the\n"
            "Dynamax phenomenon."),
        .pokemonScale = 480,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MeowthGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MeowthGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MeowthGmax,
        .shinyPalette = gMonShinyPalette_MeowthGmax,
        .iconSprite = gMonIcon_MeowthGmax,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Meowth)
        .isGigantamax = TRUE,
        .levelUpLearnset = sMeowthLevelUpLearnset,
        .teachableLearnset = sMeowthTeachableLearnset,
        .eggMoveLearnset = sMeowthEggMoveLearnset,
        .formSpeciesIdTable = sMeowthFormSpeciesIdTable,
        .formChangeTable = sMeowthFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_MEOWTH

#if P_FAMILY_PSYDUCK
    [SPECIES_PSYDUCK] =
    {
        .baseHP        = 50,
        .baseAttack    = 52,
        .baseDefense   = 48,
        .baseSpeed     = 55,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 65 : 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 64 : 80,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_DAMP, ABILITY_CLOUD_NINE, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Psyduck"),
        .cryId = CRY_PSYDUCK,
        .natDexNum = NATIONAL_DEX_PSYDUCK,
        .categoryName = _("Duck"),
        .height = 8,
        .weight = 196,
        .description = COMPOUND_STRING(
            "When its headache intensifies, it starts\n"
            "using strange powers. However, it has no\n"
            "recollection of its powers, so it always\n"
            "looks befuddled and bewildered."),
        .pokemonScale = 369,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Psyduck,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Psyduck,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Psyduck,
        .shinyPalette = gMonShinyPalette_Psyduck,
        .iconSprite = gMonIcon_Psyduck,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Psyduck)
        OVERWORLD(
            sPicTable_Psyduck,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Psyduck,
            gShinyOverworldPalette_Psyduck
        )
        .levelUpLearnset = sPsyduckLevelUpLearnset,
        .teachableLearnset = sPsyduckTeachableLearnset,
        .eggMoveLearnset = sPsyduckEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_GOLDUCK}),
    },

    [SPECIES_GOLDUCK] =
    {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 78,
        .baseSpeed     = 85,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 95 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 174,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_DAMP, ABILITY_CLOUD_NINE, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Golduck"),
        .cryId = CRY_GOLDUCK,
        .natDexNum = NATIONAL_DEX_GOLDUCK,
        .categoryName = _("Duck"),
        .height = 17,
        .weight = 766,
        .description = COMPOUND_STRING(
            "A Golduck is an adept swimmer.\n"
            "It sometimes joins competitive swimmers\n"
            "in training. It uses psychic powers when\n"
            "its forehead shimmers with light."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 273,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Golduck,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        .backPic = gMonBackPic_Golduck,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 3,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Golduck,
        .shinyPalette = gMonShinyPalette_Golduck,
        .iconSprite = gMonIcon_Golduck,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 6, SHADOW_SIZE_M)
        FOOTPRINT(Golduck)
        OVERWORLD(
            sPicTable_Golduck,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Golduck,
            gShinyOverworldPalette_Golduck
        )
        .levelUpLearnset = sGolduckLevelUpLearnset,
        .teachableLearnset = sGolduckTeachableLearnset,
    },
#endif //P_FAMILY_PSYDUCK

#if P_FAMILY_MANKEY
    [SPECIES_MANKEY] =
    {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 35,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 45 : 35,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 61 : 74,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_ANGER_POINT, ABILITY_DEFIANT },
    #else
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_NONE, ABILITY_DEFIANT },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mankey"),
        .cryId = CRY_MANKEY,
        .natDexNum = NATIONAL_DEX_MANKEY,
        .categoryName = _("Pig Monkey"),
        .height = 5,
        .weight = 280,
        .description = COMPOUND_STRING(
            "When it starts shaking and its nasal\n"
            "breathing turns rough, it's a sure sign\n"
            "of anger. However, since this happens\n"
            "instantly, there is no time to flee."),
        .pokemonScale = 404,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mankey,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 28),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Mankey,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Mankey,
        .shinyPalette = gMonShinyPalette_Mankey,
        .iconSprite = gMonIcon_Mankey,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-1, 1, SHADOW_SIZE_M)
        FOOTPRINT(Mankey)
        OVERWORLD(
            sPicTable_Mankey,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mankey,
            gShinyOverworldPalette_Mankey
        )
        .levelUpLearnset = sMankeyLevelUpLearnset,
        .teachableLearnset = sMankeyTeachableLearnset,
        .eggMoveLearnset = sMankeyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_PRIMEAPE}),
    },

    [SPECIES_PRIMEAPE] =
    {
        .baseHP        = 65,
        .baseAttack    = 105,
        .baseDefense   = 60,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 70 : 60,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 149,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_ANGER_POINT, ABILITY_DEFIANT },
    #else
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_NONE, ABILITY_DEFIANT },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Primeape"),
        .cryId = CRY_PRIMEAPE,
        .natDexNum = NATIONAL_DEX_PRIMEAPE,
        .categoryName = _("Pig Monkey"),
        .height = 10,
        .weight = 320,
        .description = COMPOUND_STRING(
            "When it becomes furious, its blood\n"
            "circulation becomes more robust, and\n"
            "its muscles are made stronger. But it\n"
            "also becomes much less intelligent."),
        .pokemonScale = 326,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Primeape,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL : ANIM_BOUNCE_ROTATE_TO_SIDES,
        .backPic = gMonBackPic_Primeape,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Primeape,
        .shinyPalette = gMonShinyPalette_Primeape,
        .iconSprite = gMonIcon_Primeape,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_L)
        FOOTPRINT(Primeape)
        OVERWORLD(
            sPicTable_Primeape,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Primeape,
            gShinyOverworldPalette_Primeape
        )
        .levelUpLearnset = sPrimeapeLevelUpLearnset,
        .teachableLearnset = sPrimeapeTeachableLearnset,
    #if P_GEN_9_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_ANNIHILAPE, CONDITIONS({IF_USED_MOVE_X_TIMES, MOVE_RAGE_FIST, 20})}),
    #endif
    },

#if P_GEN_9_CROSS_EVOS
    [SPECIES_ANNIHILAPE] =
    {
        .baseHP        = 110,
        .baseAttack    = 115,
        .baseDefense   = 80,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 268,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_INNER_FOCUS, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Annihilape"),
        .cryId = CRY_ANNIHILAPE,
        .natDexNum = NATIONAL_DEX_ANNIHILAPE,
        .categoryName = _("Rage Monkey"),
        .height = 12,
        .weight = 560,
        .description = COMPOUND_STRING(
            "When its anger rose beyond a\n"
            "critical point, this Pokémon gained power\n"
            "that is unfettered by the limits of\n"
            "its physical body."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Annihilape,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Annihilape,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Annihilape,
        .shinyPalette = gMonShinyPalette_Annihilape,
        .iconSprite = gMonIcon_Annihilape,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Annihilape)
        OVERWORLD(
            sPicTable_Annihilape,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Annihilape,
            gShinyOverworldPalette_Annihilape
        )
        .levelUpLearnset = sAnnihilapeLevelUpLearnset,
        .teachableLearnset = sAnnihilapeTeachableLearnset,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_MANKEY

#if P_FAMILY_GROWLITHE
    [SPECIES_GROWLITHE] =
    {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 70 : 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 70 : 91,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FLASH_FIRE, ABILITY_JUSTIFIED },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Growlithe"),
        .cryId = CRY_GROWLITHE,
        .natDexNum = NATIONAL_DEX_GROWLITHE,
        .categoryName = _("Puppy"),
        .height = 7,
        .weight = 190,
        .description = COMPOUND_STRING(
            "Its superb sense of smell ensures that\n"
            "this Pokémon won't forget any scent,\n"
            "no matter what. It uses its sense of smell\n"
            "to detect the emotions of others."),
        .pokemonScale = 346,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Growlithe,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BACK_AND_LUNGE : ANIM_V_STRETCH,
        .frontAnimDelay = 30,
        .backPic = gMonBackPic_Growlithe,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Growlithe,
        .shinyPalette = gMonShinyPalette_Growlithe,
        .iconSprite = gMonIcon_Growlithe,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 4, SHADOW_SIZE_M)
        FOOTPRINT(Growlithe)
        OVERWORLD(
            sPicTable_Growlithe,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Growlithe,
            gShinyOverworldPalette_Growlithe
        )
        .levelUpLearnset = sGrowlitheLevelUpLearnset,
        .teachableLearnset = sGrowlitheTeachableLearnset,
        .eggMoveLearnset = sGrowlitheEggMoveLearnset,
        .formSpeciesIdTable = sGrowlitheFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_FIRE_STONE, SPECIES_ARCANINE}),
    },

    [SPECIES_ARCANINE] =
    {
        .baseHP        = 90,
        .baseAttack    = 110,
        .baseDefense   = 80,
        .baseSpeed     = 95,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 100 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 194 : 213,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FLASH_FIRE, ABILITY_JUSTIFIED },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Arcanine"),
        .cryId = CRY_ARCANINE,
        .natDexNum = NATIONAL_DEX_ARCANINE,
        .categoryName = _("Legendary"),
        .height = 19,
        .weight = 1550,
        .description = COMPOUND_STRING(
            "This fleet-footed Pokémon is said to run\n"
            "over 6,200 miles in a single day and night.\n"
            "The fire that blazes wildly within its body\n"
            "is its source of power."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 312,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Arcanine,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 38),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_VIBRATE : ANIM_V_SHAKE,
        .frontAnimDelay = P_GBA_STYLE_SPECIES_GFX ? 40 : 8,
        .backPic = gMonBackPic_Arcanine,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Arcanine,
        .shinyPalette = gMonShinyPalette_Arcanine,
        .iconSprite = gMonIcon_Arcanine,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Arcanine)
        OVERWORLD(
            sPicTable_Arcanine,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Arcanine,
            gShinyOverworldPalette_Arcanine
        )
        .levelUpLearnset = sArcanineLevelUpLearnset,
        .teachableLearnset = sArcanineTeachableLearnset,
        .formSpeciesIdTable = sArcanineFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_GROWLITHE_HISUI] =
    {
        .baseHP        = 60,
        .baseAttack    = 75,
        .baseDefense   = 45,
        .baseSpeed     = 55,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE, TYPE_ROCK),
        .catchRate = 190,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FLASH_FIRE, ABILITY_ROCK_HEAD },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Growlithe"),
        .cryId = CRY_GROWLITHE,
        .natDexNum = NATIONAL_DEX_GROWLITHE,
        .categoryName = _("Scout"),
        .height = 8,
        .weight = 227,
        .description = COMPOUND_STRING(
            "They patrol their territory in pairs.\n"
            "It's believed the igneous rock components\n"
            "in the fur of this species are the result\n"
            "of volcanic activity in its habitat."),
        .pokemonScale = 346,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GrowlitheHisui,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GrowlitheHisui,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GrowlitheHisui,
        .shinyPalette = gMonShinyPalette_GrowlitheHisui,
        .iconSprite = gMonIcon_GrowlitheHisui,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, -2, SHADOW_SIZE_M)
        FOOTPRINT(Growlithe)
        OVERWORLD(
            sPicTable_GrowlitheHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GrowlitheHisui,
            gShinyOverworldPalette_GrowlitheHisui
        )
        .isHisuianForm = TRUE,
        .levelUpLearnset = sGrowlitheHisuiLevelUpLearnset,
        .teachableLearnset = sGrowlitheHisuiTeachableLearnset,
        .eggMoveLearnset = sGrowlitheHisuiEggMoveLearnset,
        .formSpeciesIdTable = sGrowlitheFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_FIRE_STONE, SPECIES_ARCANINE_HISUI}),
    },

    [SPECIES_ARCANINE_HISUI] =
    {
        .baseHP        = 95,
        .baseAttack    = 115,
        .baseDefense   = 80,
        .baseSpeed     = 90,
        .baseSpAttack  = 95,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE, TYPE_ROCK),
        .catchRate = 75,
        .expYield = 194,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FLASH_FIRE, ABILITY_ROCK_HEAD },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Arcanine"),
        .cryId = CRY_ARCANINE,
        .natDexNum = NATIONAL_DEX_ARCANINE,
        .categoryName = _("Legendary"),
        .height = 20,
        .weight = 1680,
        .description = COMPOUND_STRING(
            "Snaps at its foes with fangs cloaked in\n"
            "blazing flame. Despite its bulk, it deftly\n"
            "feints every which way, leading opponents\n"
            "on a deceptively merry chase."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 312,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_ArcanineHisui,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ArcanineHisui,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ArcanineHisui,
        .shinyPalette = gMonShinyPalette_ArcanineHisui,
        .iconSprite = gMonIcon_ArcanineHisui,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Arcanine)
        OVERWORLD(
            sPicTable_ArcanineHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ArcanineHisui,
            gShinyOverworldPalette_ArcanineHisui
        )
        .isHisuianForm = TRUE,
        .levelUpLearnset = sArcanineHisuiLevelUpLearnset,
        .teachableLearnset = sArcanineHisuiTeachableLearnset,
        .formSpeciesIdTable = sArcanineFormSpeciesIdTable,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_GROWLITHE

#if P_FAMILY_POLIWAG
    [SPECIES_POLIWAG] =
    {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 77,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_DAMP, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Poliwag"),
        .cryId = CRY_POLIWAG,
        .natDexNum = NATIONAL_DEX_POLIWAG,
        .categoryName = _("Tadpole"),
        .height = 6,
        .weight = 124,
        .description = COMPOUND_STRING(
            "It is possible to see this Pokémon's spiral\n"
            "innards right through its thin skin.\n"
            "However, the skin is also very flexible.\n"
            "Even sharp fangs bounce right off it."),
        .pokemonScale = 369,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Poliwag,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 32) : MON_COORDS_SIZE(64, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 19 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Poliwag,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 32) : MON_COORDS_SIZE(48, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 18,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Poliwag,
        .shinyPalette = gMonShinyPalette_Poliwag,
        .iconSprite = gMonIcon_Poliwag,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-3, 0, SHADOW_SIZE_S)
        FOOTPRINT(Poliwag)
        OVERWORLD(
            sPicTable_Poliwag,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Poliwag,
            gShinyOverworldPalette_Poliwag
        )
        .levelUpLearnset = sPoliwagLevelUpLearnset,
        .teachableLearnset = sPoliwagTeachableLearnset,
        .eggMoveLearnset = sPoliwagEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_POLIWHIRL}),
    },

    [SPECIES_POLIWHIRL] =
    {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 135 : 131,
        .evYield_Speed = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_DAMP, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Poliwhirl"),
        .cryId = CRY_POLIWHIRL,
        .natDexNum = NATIONAL_DEX_POLIWHIRL,
        .categoryName = _("Tadpole"),
        .height = 10,
        .weight = 200,
        .description = COMPOUND_STRING(
            "Its body surface is always wet and slick\n"
            "with an oily fluid. Because of this greasy\n"
            "covering, it can easily slip and slide out\n"
            "of the clutches of any enemy in battle."),
        .pokemonScale = 288,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Poliwhirl,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .frontAnimDelay = 5,
        .backPic = gMonBackPic_Poliwhirl,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Poliwhirl,
        .shinyPalette = gMonShinyPalette_Poliwhirl,
        .iconSprite = gMonIcon_Poliwhirl,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 4, SHADOW_SIZE_M)
        FOOTPRINT(Poliwhirl)
        OVERWORLD(
            sPicTable_Poliwhirl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Poliwhirl,
            gShinyOverworldPalette_Poliwhirl
        )
        .levelUpLearnset = sPoliwhirlLevelUpLearnset,
        .teachableLearnset = sPoliwhirlTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_WATER_STONE, SPECIES_POLIWRATH}
                            #if P_GEN_2_CROSS_EVOS
                                ,{EVO_TRADE, 0, SPECIES_POLITOED, CONDITIONS({IF_HOLD_ITEM, ITEM_KINGS_ROCK})},
                                {EVO_ITEM, ITEM_KINGS_ROCK, SPECIES_POLITOED}
                            #endif
                            ),
    },

    [SPECIES_POLIWRATH] =
    {
        .baseHP        = 90,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .baseDefense   = 95,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 90 : 70,
        .types = MON_TYPES(TYPE_WATER, TYPE_FIGHTING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 255,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 230,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 225,
    #else
        .expYield = 185,
    #endif
        .evYield_Defense = 3,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_DAMP, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Poliwrath"),
        .cryId = CRY_POLIWRATH,
        .natDexNum = NATIONAL_DEX_POLIWRATH,
        .categoryName = _("Tadpole"),
        .height = 13,
        .weight = 540,
        .description = COMPOUND_STRING(
            "Its highly developed muscles never grow\n"
            "fatigued, however much it exercises.\n"
            "This Pokémon can swim back and forth\n"
            "across the Pacific Ocean without effort."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Poliwrath,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Poliwrath,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Poliwrath,
        .shinyPalette = gMonShinyPalette_Poliwrath,
        .iconSprite = gMonIcon_Poliwrath,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_L)
        FOOTPRINT(Poliwrath)
        OVERWORLD(
            sPicTable_Poliwrath,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Poliwrath,
            gShinyOverworldPalette_Poliwrath
        )
        .levelUpLearnset = sPoliwrathLevelUpLearnset,
        .teachableLearnset = sPoliwrathTeachableLearnset,
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_POLITOED] =
    {
        .baseHP        = 90,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 70,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 250,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 225,
    #else
        .expYield = 185,
    #endif
        .evYield_SpDefense = 3,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_DAMP, ABILITY_DRIZZLE },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Politoed"),
        .cryId = CRY_POLITOED,
        .natDexNum = NATIONAL_DEX_POLITOED,
        .categoryName = _("Frog"),
        .height = 11,
        .weight = 339,
        .description = COMPOUND_STRING(
            "The curled hair on its head proves its\n"
            "status as a king. It is said that the\n"
            "longer and curlier the hair, the more\n"
            "respect it earns from its peers."),
        .pokemonScale = 289,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Politoed,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .frontAnimDelay = 40,
        .backPic = gMonBackPic_Politoed,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 5,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Politoed,
        .shinyPalette = gMonShinyPalette_Politoed,
        .iconSprite = gMonIcon_Politoed,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_PolitoedF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 56),
        .backPicFemale = gMonBackPic_PolitoedF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Politoed)
        OVERWORLD(
            sPicTable_Politoed,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Politoed,
            gShinyOverworldPalette_Politoed
        )
        OVERWORLD_FEMALE(
            sPicTable_PolitoedF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sPolitoedLevelUpLearnset,
        .teachableLearnset = sPolitoedTeachableLearnset,
    },
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_POLIWAG

#if P_FAMILY_ABRA
    [SPECIES_ABRA] =
    {
        .baseHP        = 25,
        .baseAttack    = 20,
        .baseDefense   = 15,
        .baseSpeed     = 90,
        .baseSpAttack  = 105,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 55 : 105,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 200,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 62,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 75,
    #else
        .expYield = 73,
    #endif
        .evYield_SpAttack = 1,
        .itemRare = ITEM_TWISTED_SPOON,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_INNER_FOCUS, ABILITY_MAGIC_GUARD },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Abra"),
        .cryId = CRY_ABRA,
        .natDexNum = NATIONAL_DEX_ABRA,
        .categoryName = _("Psi"),
        .height = 9,
        .weight = 195,
        .description = COMPOUND_STRING(
            "A Pokémon that sleeps 18 hours a day.\n"
            "Observation revealed that it uses\n"
            "Teleport to change its location once\n"
            "every hour."),
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Abra,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 21),
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 21),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_JUMPS : ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Abra,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 12,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Abra,
        .shinyPalette = gMonShinyPalette_Abra,
        .iconSprite = gMonIcon_Abra,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 0, SHADOW_SIZE_L)
        FOOTPRINT(Abra)
        OVERWORLD(
            sPicTable_Abra,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Abra,
            gShinyOverworldPalette_Abra
        )
        .levelUpLearnset = sAbraLevelUpLearnset,
        .teachableLearnset = sAbraTeachableLearnset,
        .eggMoveLearnset = sAbraEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_KADABRA}),
    },

    [SPECIES_KADABRA] =
    {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 105,
        .baseSpAttack  = 120,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 70 : 120,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 100,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 140 : 145,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_TWISTED_SPOON,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_INNER_FOCUS, ABILITY_MAGIC_GUARD },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Kadabra"),
        .cryId = CRY_KADABRA,
        .natDexNum = NATIONAL_DEX_KADABRA,
        .categoryName = _("Psi"),
        .height = 13,
        .weight = 565,
        .description = COMPOUND_STRING(
            "It is rumored that a boy with psychic\n"
            "abilities suddenly transformed into\n"
            "Kadabra while he was assisting research\n"
            "into extrasensory powers."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kadabra,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Kadabra,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Kadabra,
        .shinyPalette = gMonShinyPalette_Kadabra,
        .iconSprite = gMonIcon_Kadabra,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_KadabraF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_KadabraF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 6, SHADOW_SIZE_L)
        FOOTPRINT(Kadabra)
        OVERWORLD(
            sPicTable_Kadabra,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following_Asym,
            gOverworldPalette_Kadabra,
            gShinyOverworldPalette_Kadabra
        )
        OVERWORLD_FEMALE(
            sPicTable_KadabraF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following_Asym
        )
        .levelUpLearnset = sKadabraLevelUpLearnset,
        .teachableLearnset = sKadabraTeachableLearnset,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_ALAKAZAM},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_ALAKAZAM}),
    },

#if P_UPDATED_STATS >= GEN_6
    #define ALAKAZAM_SP_DEF 95
#elif P_UPDATED_STATS >= GEN_2
    #define ALAKAZAM_SP_DEF 85
#else
    #define ALAKAZAM_SP_DEF 135
#endif

    [SPECIES_ALAKAZAM] =
    {
        .baseHP        = 55,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 120,
        .baseSpAttack  = 135,
        .baseSpDefense = ALAKAZAM_SP_DEF,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 50,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 250,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 225,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 221,
    #else
        .expYield = 186,
    #endif
        .evYield_SpAttack = 3,
        .itemRare = ITEM_TWISTED_SPOON,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_INNER_FOCUS, ABILITY_MAGIC_GUARD },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Alakazam"),
        .cryId = CRY_ALAKAZAM,
        .natDexNum = NATIONAL_DEX_ALAKAZAM,
        .categoryName = _("Psi"),
        .height = 15,
        .weight = 480,
        .description = COMPOUND_STRING(
            "While it has strong psychic abilities and\n"
            "high intelligence, an Alakazam's muscles\n"
            "are very weak. It uses psychic power to\n"
            "move its body."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Alakazam,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 54),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Alakazam,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Alakazam,
        .shinyPalette = gMonShinyPalette_Alakazam,
        .iconSprite = gMonIcon_Alakazam,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_AlakazamF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_AlakazamF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_L)
        FOOTPRINT(Alakazam)
        OVERWORLD(
            sPicTable_Alakazam,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Alakazam,
            gShinyOverworldPalette_Alakazam
        )
        OVERWORLD_FEMALE(
            sPicTable_AlakazamF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following
        )
        .levelUpLearnset = sAlakazamLevelUpLearnset,
        .teachableLearnset = sAlakazamTeachableLearnset,
        .formSpeciesIdTable = sAlakazamFormSpeciesIdTable,
        .formChangeTable = sAlakazamFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_ALAKAZAM_MEGA] =
    {
        .baseHP        = 55,
        .baseAttack    = 50,
        .baseDefense   = 65,
        .baseSpeed     = 150,
        .baseSpAttack  = 175,
        .baseSpDefense = P_UPDATED_STATS >= GEN_7 ? 105 : 95,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 50,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 270,
    #else
        .expYield = 266,
    #endif
        .evYield_SpAttack = 3,
        .itemRare = ITEM_TWISTED_SPOON,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_TRACE, ABILITY_TRACE, ABILITY_TRACE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Alakazam"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_ALAKAZAM_MEGA,
    #else
        .cryId = CRY_ALAKAZAM,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_ALAKAZAM,
        .categoryName = _("Psi"),
        .height = 12,
        .weight = 480,
        .description = COMPOUND_STRING(
            "Having traded away its muscles, Alakazam's\n"
            "true power has been unleashed. With its\n"
            "psychic powers, it can foresee all things."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AlakazamMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 40),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_AlakazamMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_AlakazamMega,
        .shinyPalette = gMonShinyPalette_AlakazamMega,
        .iconSprite = gMonIcon_AlakazamMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 18, SHADOW_SIZE_L)
        FOOTPRINT(Alakazam)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_AlakazamMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_AlakazamMega,
            gShinyOverworldPalette_AlakazamMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAlakazamLevelUpLearnset,
        .teachableLearnset = sAlakazamTeachableLearnset,
        .formSpeciesIdTable = sAlakazamFormSpeciesIdTable,
        .formChangeTable = sAlakazamFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_ABRA

#if P_FAMILY_MACHOP
    [SPECIES_MACHOP] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 180,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 61,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 75,
    #else
        .expYield = 88,
    #endif
        .evYield_Attack = 1,
        .itemRare = ITEM_FOCUS_BAND,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_GUTS, ABILITY_NO_GUARD, ABILITY_STEADFAST },
    #else
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_STEADFAST },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Machop"),
        .cryId = CRY_MACHOP,
        .natDexNum = NATIONAL_DEX_MACHOP,
        .categoryName = _("Superpower"),
        .height = 8,
        .weight = 195,
        .description = COMPOUND_STRING(
            "It continually undertakes strenuous\n"
            "training to master all forms of martial\n"
            "arts. Its strength lets it easily hoist\n"
            "a sumo wrestler onto its shoulders."),
        .pokemonScale = 342,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Machop,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Machop,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Machop,
        .shinyPalette = gMonShinyPalette_Machop,
        .iconSprite = gMonIcon_Machop,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_S)
        FOOTPRINT(Machop)
        OVERWORLD(
            sPicTable_Machop,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Machop,
            gShinyOverworldPalette_Machop
        )
        .levelUpLearnset = sMachopLevelUpLearnset,
        .teachableLearnset = sMachopTeachableLearnset,
        .eggMoveLearnset = sMachopEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_MACHOKE}),
    },

    [SPECIES_MACHOKE] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 60 : 50,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 146,
        .evYield_Attack = 2,
        .itemRare = ITEM_FOCUS_BAND,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_GUTS, ABILITY_NO_GUARD, ABILITY_STEADFAST },
    #else
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_STEADFAST },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Machoke"),
        .cryId = CRY_MACHOKE,
        .natDexNum = NATIONAL_DEX_MACHOKE,
        .categoryName = _("Superpower"),
        .height = 15,
        .weight = 705,
        .description = COMPOUND_STRING(
            "A belt is worn by a Machoke to keep its\n"
            "overwhelming power under control.\n"
            "Because it is so dangerous, no one has\n"
            "ever removed the belt."),
        .pokemonScale = 323,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Machoke,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Machoke,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Machoke,
        .shinyPalette = gMonShinyPalette_Machoke,
        .iconSprite = gMonIcon_Machoke,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Machoke)
        OVERWORLD(
            sPicTable_Machoke,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Machoke,
            gShinyOverworldPalette_Machoke
        )
        .levelUpLearnset = sMachokeLevelUpLearnset,
        .teachableLearnset = sMachokeTeachableLearnset,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_MACHAMP},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_MACHAMP}),
    },

#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define MACHAMP_EXP_YIELD 253
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define MACHAMP_EXP_YIELD 227
#else
    #define MACHAMP_EXP_YIELD 193
#endif

    [SPECIES_MACHAMP] =
    {
        .baseHP        = 90,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 85 : 65,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = MACHAMP_EXP_YIELD,
        .evYield_Attack = 3,
        .itemRare = ITEM_FOCUS_BAND,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_GUTS, ABILITY_NO_GUARD, ABILITY_STEADFAST },
    #else
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_STEADFAST },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Machamp"),
        .cryId = CRY_MACHAMP,
        .natDexNum = NATIONAL_DEX_MACHAMP,
        .categoryName = _("Superpower"),
        .height = 16,
        .weight = 1300,
        .description = COMPOUND_STRING(
            "It is impossible to defend against punches\n"
            "and chops doled out by its four arms.\n"
            "Its fighting spirit flares up when it faces\n"
            "a tough opponent."),
        .pokemonScale = 280,
        .pokemonOffset = 1,
        .trainerScale = 269,
        .trainerOffset = -1,
        .frontPic = gMonFrontPic_Machamp,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = gMonBackPic_Machamp,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 7,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Machamp,
        .shinyPalette = gMonShinyPalette_Machamp,
        .iconSprite = gMonIcon_Machamp,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 13, SHADOW_SIZE_L)
        FOOTPRINT(Machamp)
        OVERWORLD(
            sPicTable_Machamp,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Machamp,
            gShinyOverworldPalette_Machamp
        )
        .levelUpLearnset = sMachampLevelUpLearnset,
        .teachableLearnset = sMachampTeachableLearnset,
        .formSpeciesIdTable = sMachampFormSpeciesIdTable,
        .formChangeTable = sMachampFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_MACHAMP_GMAX] =
    {
        .baseHP        = 90,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 85 : 65,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = MACHAMP_EXP_YIELD,
        .evYield_Attack = 3,
        .itemRare = ITEM_FOCUS_BAND,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_GUTS, ABILITY_NO_GUARD, ABILITY_STEADFAST },
    #else
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_STEADFAST },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Machamp"),
        .cryId = CRY_MACHAMP,
        .natDexNum = NATIONAL_DEX_MACHAMP,
        .categoryName = _("Superpower"),
        .height = 250,
        .weight = 0,
        .description = COMPOUND_STRING(
            "One of these Pokémon once used\n"
            "its immeasurable strength to lift a\n"
            "large ship that was in trouble. It\n"
            "then carried the ship to port."),
        .pokemonScale = 280,
        .pokemonOffset = 1,
        .trainerScale = 269,
        .trainerOffset = -1,
        .frontPic = gMonFrontPic_MachampGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MachampGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MachampGmax,
        .shinyPalette = gMonShinyPalette_MachampGmax,
        .iconSprite = gMonIcon_MachampGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 13, SHADOW_SIZE_L)
        FOOTPRINT(Machamp)
        .isGigantamax = TRUE,
        .levelUpLearnset = sMachampLevelUpLearnset,
        .teachableLearnset = sMachampTeachableLearnset,
        .formSpeciesIdTable = sMachampFormSpeciesIdTable,
        .formChangeTable = sMachampFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_MACHOP

#if P_FAMILY_BELLSPROUT
    [SPECIES_BELLSPROUT] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 35,
        .baseSpeed     = 40,
        .baseSpAttack  = 70,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 30 : 70,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 84,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bellsprout"),
        .cryId = CRY_BELLSPROUT,
        .natDexNum = NATIONAL_DEX_BELLSPROUT,
        .categoryName = _("Flower"),
        .height = 7,
        .weight = 40,
        .description = COMPOUND_STRING(
            "A Bellsprout's thin and flexible body lets\n"
            "it bend and sway to avoid any attack,\n"
            "however strong it may be. From its mouth,\n"
            "it leaks a fluid that melts even iron."),
        .pokemonScale = 354,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bellsprout,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_H_JUMPS,
        .backPic = gMonBackPic_Bellsprout,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Bellsprout,
        .shinyPalette = gMonShinyPalette_Bellsprout,
        .iconSprite = gMonIcon_Bellsprout,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, 3, SHADOW_SIZE_S)
        FOOTPRINT(Bellsprout)
        OVERWORLD(
            sPicTable_Bellsprout,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bellsprout,
            gShinyOverworldPalette_Bellsprout
        )
        .levelUpLearnset = sBellsproutLevelUpLearnset,
        .teachableLearnset = sBellsproutTeachableLearnset,
        .eggMoveLearnset = sBellsproutEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 21, SPECIES_WEEPINBELL}),
    },

    [SPECIES_WEEPINBELL] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 85,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 45 : 85,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 137 : 151,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Weepinbell"),
        .cryId = CRY_WEEPINBELL,
        .natDexNum = NATIONAL_DEX_WEEPINBELL,
        .categoryName = _("Flycatcher"),
        .height = 10,
        .weight = 64,
        .description = COMPOUND_STRING(
            "At night, a Weepinbell hangs on to a tree\n"
            "branch with its hooked rear and sleeps.\n"
            "If it moves around in its sleep, it may\n"
            "wake up to find itself on the ground."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Weepinbell,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONVEX,
        .frontAnimDelay = 3,
        .backPic = gMonBackPic_Weepinbell,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Weepinbell,
        .shinyPalette = gMonShinyPalette_Weepinbell,
        .iconSprite = gMonIcon_Weepinbell,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 3, SHADOW_SIZE_M)
        FOOTPRINT(Weepinbell)
        OVERWORLD(
            sPicTable_Weepinbell,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Weepinbell,
            gShinyOverworldPalette_Weepinbell
        )
        .levelUpLearnset = sWeepinbellLevelUpLearnset,
        .teachableLearnset = sWeepinbellTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_VICTREEBEL}),
    },

#if P_UPDATED_STATS >= GEN_6
    #define VICTREEBEL_SP_DEF 70
#elif P_UPDATED_STATS >= GEN_2
    #define VICTREEBEL_SP_DEF 60
#else
    #define VICTREEBEL_SP_DEF 100
#endif

    [SPECIES_VICTREEBEL] =
    {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 100,
        .baseSpDefense = VICTREEBEL_SP_DEF,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 245,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 221,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 216,
    #else
        .expYield = 191,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Victreebel"),
        .cryId = CRY_VICTREEBEL,
        .natDexNum = NATIONAL_DEX_VICTREEBEL,
        .categoryName = _("Flycatcher"),
        .height = 17,
        .weight = 155,
        .description = COMPOUND_STRING(
            "The long vine extending from its head is\n"
            "waved about as if it were a living thing to\n"
            "attract prey. When an unsuspecting victim\n"
            "approaches, it is swallowed whole."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 312,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Victreebel,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Victreebel,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Victreebel,
        .shinyPalette = gMonShinyPalette_Victreebel,
        .iconSprite = gMonIcon_Victreebel,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 8, SHADOW_SIZE_M)
        FOOTPRINT(Victreebel)
        OVERWORLD(
            sPicTable_Victreebel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Victreebel,
            gShinyOverworldPalette_Victreebel
        )
        .levelUpLearnset = sVictreebelLevelUpLearnset,
        .teachableLearnset = sVictreebelTeachableLearnset,
        .formSpeciesIdTable = sVictreebelFormSpeciesIdTable,
        .formChangeTable = sVictreebelFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_VICTREEBEL_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 125,
        .baseDefense   = 85,
        .baseSpeed     = 70,
        .baseSpAttack  = 135,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 45,
        .expYield = 245,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_INNARDS_OUT, ABILITY_INNARDS_OUT, ABILITY_INNARDS_OUT },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Victreebel"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_VICTREEBEL_MEGA,
    #else
        .cryId = CRY_VICTREEBEL,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_VICTREEBEL,
        .categoryName = _("Flycatcher"),
        .height = 45,
        .weight = 1255,
        .description = COMPOUND_STRING(
            "The volume of this Pokémon's acid\n"
            "has increased due to Mega Evolution,\n"
            "filling its mouth. If not careful,\n"
            "the acid will overflow and spill out."),
        .frontPic = gMonFrontPic_VictreebelMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_VictreebelMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_VictreebelMega,
        .shinyPalette = gMonShinyPalette_VictreebelMega,
        .iconSprite = gMonIcon_VictreebelMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Victreebel)
        SHADOW(-2, 13, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sVictreebelLevelUpLearnset,
        .teachableLearnset = sVictreebelTeachableLearnset,
        .formSpeciesIdTable = sVictreebelFormSpeciesIdTable,
        .formChangeTable = sVictreebelFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_BELLSPROUT

#if P_FAMILY_TENTACOOL
    [SPECIES_TENTACOOL] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 50 : 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_WATER, TYPE_POISON),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 67 : 105,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_LIQUID_OOZE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Tentacool"),
        .cryId = CRY_TENTACOOL,
        .natDexNum = NATIONAL_DEX_TENTACOOL,
        .categoryName = _("Jellyfish"),
        .height = 9,
        .weight = 455,
        .description = COMPOUND_STRING(
            "Its body is almost entirely composed of\n"
            "water. It ensnares its foe with its two\n"
            "long tentacles, then stabs with the poison\n"
            "stingers at their tips."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tentacool,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Tentacool,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Tentacool,
        .shinyPalette = gMonShinyPalette_Tentacool,
        .iconSprite = gMonIcon_Tentacool,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 6, SHADOW_SIZE_M)
        FOOTPRINT(Tentacool)
        OVERWORLD(
            sPicTable_Tentacool,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Tentacool,
            gShinyOverworldPalette_Tentacool
        )
        .levelUpLearnset = sTentacoolLevelUpLearnset,
        .teachableLearnset = sTentacoolTeachableLearnset,
        .eggMoveLearnset = sTentacoolEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_TENTACRUEL}),
    },

    [SPECIES_TENTACRUEL] =
    {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 80 : 120,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_WATER, TYPE_POISON),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 180 : 205,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_LIQUID_OOZE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Tentacruel"),
        .cryId = CRY_TENTACRUEL,
        .natDexNum = NATIONAL_DEX_TENTACRUEL,
        .categoryName = _("Jellyfish"),
        .height = 16,
        .weight = 550,
        .description = COMPOUND_STRING(
            "It lives in complex rock formations on\n"
            "the ocean floor and traps prey using its\n"
            "80 tentacles. Its red orbs glow when it\n"
            "grows excited or agitated."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 312,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Tentacruel,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 19),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 19),
            ANIMCMD_FRAME(1, 19),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_V_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Tentacruel,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Tentacruel,
        .shinyPalette = gMonShinyPalette_Tentacruel,
        .iconSprite = gMonIcon_Tentacruel,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Tentacruel)
        OVERWORLD(
            sPicTable_Tentacruel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Tentacruel,
            gShinyOverworldPalette_Tentacruel
        )
        .levelUpLearnset = sTentacruelLevelUpLearnset,
        .teachableLearnset = sTentacruelTeachableLearnset,
    },
#endif //P_FAMILY_TENTACOOL

#if P_FAMILY_GEODUDE
    [SPECIES_GEODUDE] =
    {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 20,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GROUND),
        .catchRate = 255,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 60,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 73,
    #else
        .expYield = 86,
    #endif
        .evYield_Defense = 1,
        .itemRare = ITEM_EVERSTONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Geodude"),
        .cryId = CRY_GEODUDE,
        .natDexNum = NATIONAL_DEX_GEODUDE,
        .categoryName = _("Rock"),
        .height = 4,
        .weight = 200,
        .description = COMPOUND_STRING(
            "It climbs mountain paths using only the\n"
            "power of its arms. Because they look just\n"
            "like boulders lining paths, hikers may step\n"
            "on them without noticing."),
        .pokemonScale = 347,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Geodude,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(64, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 19,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 16 : 10,
        .backPic = gMonBackPic_Geodude,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Geodude,
        .shinyPalette = gMonShinyPalette_Geodude,
        .iconSprite = gMonIcon_Geodude,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Geodude)
        OVERWORLD(
            sPicTable_Geodude,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Geodude,
            gShinyOverworldPalette_Geodude
        )
        .levelUpLearnset = sGeodudeLevelUpLearnset,
        .teachableLearnset = sGeodudeTeachableLearnset,
        .eggMoveLearnset = sGeodudeEggMoveLearnset,
        .formSpeciesIdTable = sGeodudeFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_GRAVELER}),
    },

    [SPECIES_GRAVELER] =
    {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GROUND),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 137 : 134,
        .evYield_Defense = 2,
        .itemRare = ITEM_EVERSTONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Graveler"),
        .cryId = CRY_GRAVELER,
        .natDexNum = NATIONAL_DEX_GRAVELER,
        .categoryName = _("Rock"),
        .height = 10,
        .weight = 1050,
        .description = COMPOUND_STRING(
            "They descend from mountains by tumbling\n"
            "down steep slopes. They are so brutal,\n"
            "they smash aside obstructing trees and\n"
            "massive boulders with thunderous tackles."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Graveler,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL : ANIM_V_SHAKE,
        .backPic = gMonBackPic_Graveler,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Graveler,
        .shinyPalette = gMonShinyPalette_Graveler,
        .iconSprite = gMonIcon_Graveler,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Graveler)
        OVERWORLD(
            sPicTable_Graveler,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Graveler,
            gShinyOverworldPalette_Graveler
        )
        .levelUpLearnset = sGravelerLevelUpLearnset,
        .teachableLearnset = sGravelerTeachableLearnset,
        .formSpeciesIdTable = sGravelerFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOLEM},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOLEM}),
    },

    [SPECIES_GOLEM] =
    {
        .baseHP        = 80,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 120 : 110,
        .baseDefense   = 130,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 65 : 55,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GROUND),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 248,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 223,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 218,
    #else
        .expYield = 177,
    #endif
        .evYield_Defense = 3,
        .itemRare = ITEM_EVERSTONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Golem"),
        .cryId = CRY_GOLEM,
        .natDexNum = NATIONAL_DEX_GOLEM,
        .categoryName = _("Megaton"),
        .height = 14,
        .weight = 3000,
        .description = COMPOUND_STRING(
            "It is said to live in volcanic craters\n"
            "on mountain peaks. Once a year, it sheds\n"
            "its hide and grows larger. The shed hide\n"
            "crumbles and returns to the soil."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 296,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Golem,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 31),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        .backPic = gMonBackPic_Golem,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 32) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 11,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Golem,
        .shinyPalette = gMonShinyPalette_Golem,
        .iconSprite = gMonIcon_Golem,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 5, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Golem)
        OVERWORLD(
            sPicTable_Golem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Golem,
            gShinyOverworldPalette_Golem
        )
        .levelUpLearnset = sGolemLevelUpLearnset,
        .teachableLearnset = sGolemTeachableLearnset,
        .formSpeciesIdTable = sGolemFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_GEODUDE_ALOLA] =
    {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 20,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ROCK, TYPE_ELECTRIC),
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense = 1,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_GALVANIZE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Geodude"),
        .cryId = CRY_GEODUDE,
        .natDexNum = NATIONAL_DEX_GEODUDE,
        .categoryName = _("Rock"),
        .height = 4,
        .weight = 203,
        .description = COMPOUND_STRING(
            "Its body is a magnetic stone. Iron sand\n"
            "attach to parts of its body with stronger\n"
            "magnetism. If you carelessly step on one,\n"
            "it will headbutt and shock you in anger."),
        .pokemonScale = 347,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GeodudeAlola,
        .frontPicSize = MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_TWIST,
        .enemyMonElevation = 16,
        .backPic = gMonBackPic_GeodudeAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GeodudeAlola,
        .shinyPalette = gMonShinyPalette_GeodudeAlola,
        .iconSprite = gMonIcon_GeodudeAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 10, SHADOW_SIZE_M)
        FOOTPRINT(Geodude)
        OVERWORLD(
            sPicTable_GeodudeAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GeodudeAlola,
            gShinyOverworldPalette_GeodudeAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sGeodudeAlolaLevelUpLearnset,
        .teachableLearnset = sGeodudeAlolaTeachableLearnset,
        .eggMoveLearnset = sGeodudeAlolaEggMoveLearnset,
        .formSpeciesIdTable = sGeodudeFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_GRAVELER_ALOLA}),
    },

    [SPECIES_GRAVELER_ALOLA] =
    {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ROCK, TYPE_ELECTRIC),
        .catchRate = 120,
        .expYield = 137,
        .evYield_Defense = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_GALVANIZE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Graveler"),
        .cryId = CRY_GRAVELER,
        .natDexNum = NATIONAL_DEX_GRAVELER,
        .categoryName = _("Rock"),
        .height = 10,
        .weight = 1100,
        .description = COMPOUND_STRING(
            "When two Graveler smash each other over\n"
            "dravite, their favorite food, they cause\n"
            "flashes of light and booming noises.\n"
            "People call them “fireworks of the earth.”"),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GravelerAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_GravelerAlola,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GravelerAlola,
        .shinyPalette = gMonShinyPalette_GravelerAlola,
        .iconSprite = gMonIcon_GravelerAlola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 5, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Graveler)
        OVERWORLD(
            sPicTable_GravelerAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GravelerAlola,
            gShinyOverworldPalette_GravelerAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sGravelerAlolaLevelUpLearnset,
        .teachableLearnset = sGravelerAlolaTeachableLearnset,
        .formSpeciesIdTable = sGravelerFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOLEM_ALOLA},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOLEM_ALOLA}),
    },

    [SPECIES_GOLEM_ALOLA] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 130,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ROCK, TYPE_ELECTRIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 248 : 223,
        .evYield_Defense = 3,
        .itemCommon = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_GALVANIZE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Golem"),
        .cryId = CRY_GOLEM,
        .natDexNum = NATIONAL_DEX_GOLEM,
        .categoryName = _("Megaton"),
        .height = 17,
        .weight = 3160,
        .description = COMPOUND_STRING(
            "It fires rocks charged with electricity.\n"
            "Even if the rock isn't fired that\n"
            "accurately, just grazing an opponent\n"
            "will cause numbness and fainting."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 296,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_GolemAlola,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SHAKE_BACK,
        .backPic = gMonBackPic_GolemAlola,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GolemAlola,
        .shinyPalette = gMonShinyPalette_GolemAlola,
        .iconSprite = gMonIcon_GolemAlola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_L)
        FOOTPRINT(Golem)
        OVERWORLD(
            sPicTable_GolemAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GolemAlola,
            gShinyOverworldPalette_GolemAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sGolemAlolaLevelUpLearnset,
        .teachableLearnset = sGolemAlolaTeachableLearnset,
        .formSpeciesIdTable = sGolemFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_GEODUDE

#if P_FAMILY_PONYTA
    [SPECIES_PONYTA] =
    {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 82 : 152,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Ponyta"),
        .cryId = CRY_PONYTA,
        .natDexNum = NATIONAL_DEX_PONYTA,
        .categoryName = _("Fire Horse"),
        .height = 10,
        .weight = 300,
        .description = COMPOUND_STRING(
            "A Ponyta is very weak at birth. It can\n"
            "barely stand up. Its legs become stronger\n"
            "as it stumbles and falls while trying to\n"
            "keep up with its parent."),
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ponyta,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_GLOW_ORANGE : ANIM_V_SHAKE,
        .frontAnimDelay = P_GBA_STYLE_SPECIES_GFX ? 0 : 10,
        .backPic = gMonBackPic_Ponyta,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 4,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Ponyta,
        .shinyPalette = gMonShinyPalette_Ponyta,
        .iconSprite = gMonIcon_Ponyta,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 7, SHADOW_SIZE_M)
        FOOTPRINT(Ponyta)
        OVERWORLD(
            sPicTable_Ponyta,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ponyta,
            gShinyOverworldPalette_Ponyta
        )
        .levelUpLearnset = sPonytaLevelUpLearnset,
        .teachableLearnset = sPonytaTeachableLearnset,
        .eggMoveLearnset = sPonytaEggMoveLearnset,
        .formSpeciesIdTable = sPonytaFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_RAPIDASH}),
    },

    [SPECIES_RAPIDASH] =
    {
        .baseHP        = 65,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 105,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 192,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Rapidash"),
        .cryId = CRY_RAPIDASH,
        .natDexNum = NATIONAL_DEX_RAPIDASH,
        .categoryName = _("Fire Horse"),
        .height = 17,
        .weight = 950,
        .description = COMPOUND_STRING(
            "It usually canters casually in the fields\n"
            "and plains. But once a Rapidash turns\n"
            "serious, its fiery manes flare and blaze\n"
            "as it gallops its way up to 150 mph."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 289,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Rapidash,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_CIRCULAR_VIBRATE : ANIM_H_SHAKE,
        .backPic = gMonBackPic_Rapidash,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 0,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Rapidash,
        .shinyPalette = gMonShinyPalette_Rapidash,
        .iconSprite = gMonIcon_Rapidash,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Rapidash)
        OVERWORLD(
            sPicTable_Rapidash,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rapidash,
            gShinyOverworldPalette_Rapidash
        )
        .levelUpLearnset = sRapidashLevelUpLearnset,
        .teachableLearnset = sRapidashTeachableLearnset,
        .formSpeciesIdTable = sRapidashFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_PONYTA_GALAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 190,
        .expYield = 82,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_PASTEL_VEIL, ABILITY_ANTICIPATION },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Ponyta"),
        .cryId = CRY_PONYTA,
        .natDexNum = NATIONAL_DEX_PONYTA,
        .categoryName = _("Unique Horn"),
        .height = 8,
        .weight = 240,
        .description = COMPOUND_STRING(
            "Its small horn hides a healing power.\n"
            "This Pokémon will look into your eyes and\n"
            "read the contents of your heart. If it\n"
            "finds evil there, it promptly hides away."),
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PonytaGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_PonytaGalar,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PonytaGalar,
        .shinyPalette = gMonShinyPalette_PonytaGalar,
        .iconSprite = gMonIcon_PonytaGalar,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 5, SHADOW_SIZE_M)
        FOOTPRINT(Ponyta)
        OVERWORLD(
            sPicTable_PonytaGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_PonytaGalar,
            gShinyOverworldPalette_PonytaGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sPonytaGalarLevelUpLearnset,
        .teachableLearnset = sPonytaGalarTeachableLearnset,
        .eggMoveLearnset = sPonytaGalarEggMoveLearnset,
        .formSpeciesIdTable = sPonytaFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_RAPIDASH_GALAR}),
    },

    [SPECIES_RAPIDASH_GALAR] =
    {
        .baseHP        = 65,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 105,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FAIRY),
        .catchRate = 60,
        .expYield = 175,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_PASTEL_VEIL, ABILITY_ANTICIPATION },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Rapidash"),
        .cryId = CRY_RAPIDASH,
        .natDexNum = NATIONAL_DEX_RAPIDASH,
        .categoryName = _("Unique Horn"),
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Little can stand up to its psycho cut.\n"
            "Unleashed from this Pokémon's horn,\n"
            "the move will punch a hole right\n"
            "through a thick metal sheet."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 289,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_RapidashGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_RapidashGalar,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RapidashGalar,
        .shinyPalette = gMonShinyPalette_RapidashGalar,
        .iconSprite = gMonIcon_RapidashGalar,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Rapidash)
        OVERWORLD(
            sPicTable_RapidashGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_RapidashGalar,
            gShinyOverworldPalette_RapidashGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sRapidashGalarLevelUpLearnset,
        .teachableLearnset = sRapidashGalarTeachableLearnset,
        .formSpeciesIdTable = sRapidashFormSpeciesIdTable,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_PONYTA

#if P_FAMILY_SLOWPOKE
    [SPECIES_SLOWPOKE] =
    {
        .baseHP        = 90,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 15,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_WATER, TYPE_PSYCHIC),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 63 : 99,
        .evYield_HP = 1,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Slowpoke"),
        .cryId = CRY_SLOWPOKE,
        .natDexNum = NATIONAL_DEX_SLOWPOKE,
        .categoryName = _("Dopey"),
        .height = 12,
        .weight = 360,
        .description = COMPOUND_STRING(
            "It catches prey by dipping its tail in\n"
            "water at the side of a river. But it often\n"
            "forgets what it is doing and spends entire\n"
            "days just loafing at water's edge."),
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Slowpoke,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Slowpoke,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Slowpoke,
        .shinyPalette = gMonShinyPalette_Slowpoke,
        .iconSprite = gMonIcon_Slowpoke,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, -5, SHADOW_SIZE_L)
        FOOTPRINT(Slowpoke)
        OVERWORLD(
            sPicTable_Slowpoke,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Slowpoke,
            gShinyOverworldPalette_Slowpoke
        )
        .levelUpLearnset = sSlowpokeLevelUpLearnset,
        .teachableLearnset = sSlowpokeTeachableLearnset,
        .eggMoveLearnset = sSlowpokeEggMoveLearnset,
        .formSpeciesIdTable = sSlowpokeFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_SLOWBRO}
                            #if P_GEN_2_CROSS_EVOS
                                ,{EVO_TRADE, 0, SPECIES_SLOWKING, CONDITIONS({IF_HOLD_ITEM, ITEM_KINGS_ROCK})},
                                {EVO_ITEM, ITEM_KINGS_ROCK, SPECIES_SLOWKING}
                            #endif
                            ),
    },

    [SPECIES_SLOWBRO] =
    {
        .baseHP        = 95,
        .baseAttack    = 75,
        .baseDefense   = 110,
        .baseSpeed     = 30,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 100 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_WATER, TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 164,
        .evYield_Defense = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Slowbro"),
        .cryId = CRY_SLOWBRO,
        .natDexNum = NATIONAL_DEX_SLOWBRO,
        .categoryName = _("Hermit Crab"),
        .height = 16,
        .weight = 785,
        .description = COMPOUND_STRING(
            "Its tail has a Shellder firmly attached\n"
            "with a bite. As a result, the tail can't be\n"
            "used for fishing anymore. This forces it\n"
            "to reluctantly swim and catch prey."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 296,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Slowbro,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE : ANIM_H_STRETCH,
        .backPic = gMonBackPic_Slowbro,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Slowbro,
        .shinyPalette = gMonShinyPalette_Slowbro,
        .iconSprite = gMonIcon_Slowbro,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_L)
        FOOTPRINT(Slowbro)
        OVERWORLD(
            sPicTable_Slowbro,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Slowbro,
            gShinyOverworldPalette_Slowbro
        )
        .levelUpLearnset = sSlowbroLevelUpLearnset,
        .teachableLearnset = sSlowbroTeachableLearnset,
        .formSpeciesIdTable = sSlowbroFormSpeciesIdTable,
        .formChangeTable = sSlowbroFormChangeTable,
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_SLOWKING] =
    {
        .baseHP        = 95,
        .baseAttack    = 75,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_WATER, TYPE_PSYCHIC),
        .catchRate = 70,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 164,
        .evYield_SpDefense = (P_UPDATED_EVS >= GEN_8) ? 2 : 3,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Slowking"),
        .cryId = CRY_SLOWKING,
        .natDexNum = NATIONAL_DEX_SLOWKING,
        .categoryName = _("Royal"),
        .height = 20,
        .weight = 795,
        .description = COMPOUND_STRING(
            "It undertakes research every day to\n"
            "solve the mysteries of the world.\n"
            "However, it apparently forgets everything\n"
            "if the Shellder on its head comes off."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
        .frontPic = gMonFrontPic_Slowking,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 64) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Slowking,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 3,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Slowking,
        .shinyPalette = gMonShinyPalette_Slowking,
        .iconSprite = gMonIcon_Slowking,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Slowking)
        OVERWORLD(
            sPicTable_Slowking,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Slowking,
            gShinyOverworldPalette_Slowking
        )
        .levelUpLearnset = sSlowkingLevelUpLearnset,
        .teachableLearnset = sSlowkingTeachableLearnset,
        .formSpeciesIdTable = sSlowkingFormSpeciesIdTable,
    },
#endif //P_GEN_2_CROSS_EVOS

#if P_MEGA_EVOLUTIONS
    [SPECIES_SLOWBRO_MEGA] =
    {
        .baseHP        = 95,
        .baseAttack    = 75,
        .baseDefense   = 180,
        .baseSpeed     = 30,
        .baseSpAttack  = 130,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_WATER, TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = 207,
        .evYield_Defense = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_SHELL_ARMOR, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Slowbro"),
        .cryId = CRY_SLOWBRO_MEGA,
        .natDexNum = NATIONAL_DEX_SLOWBRO,
        .categoryName = _("Hermit Crab"),
        .height = 20,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "When bathed in the energy of Mega\n"
            "Evolution, Shellder converts into\n"
            "impregnable armor. There is virtually no\n"
            "change in Slowpoke."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 296,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_SlowbroMega,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_SlowbroMega,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_SlowbroMega,
        .shinyPalette = gMonShinyPalette_SlowbroMega,
        .iconSprite = gMonIcon_SlowbroMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_L)
        FOOTPRINT(Slowbro)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_SlowbroMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SlowbroMega,
            gShinyOverworldPalette_SlowbroMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSlowbroLevelUpLearnset,
        .teachableLearnset = sSlowbroTeachableLearnset,
        .formSpeciesIdTable = sSlowbroFormSpeciesIdTable,
        .formChangeTable = sSlowbroFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GALARIAN_FORMS
    [SPECIES_SLOWPOKE_GALAR] =
    {
        .baseHP        = 90,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 15,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 190,
        .expYield = 63,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_GLUTTONY, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Slowpoke"),
        .cryId = CRY_SLOWPOKE_GALAR,
        .natDexNum = NATIONAL_DEX_SLOWPOKE,
        .categoryName = _("Dopey"),
        .height = 12,
        .weight = 360,
        .description = COMPOUND_STRING(
            "Although it is normally zoned out, its\n"
            "expression abruptly sharpens on occasion.\n"
            "The cause seems to lie in Slowpoke's diet,\n"
            "which also give their tails a spicy flavor."),
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SlowpokeGalar,
        .frontPicSize = MON_COORDS_SIZE(56, 32),
        .frontPicYOffset = 19,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SlowpokeGalar,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SlowpokeGalar,
        .shinyPalette = gMonShinyPalette_SlowpokeGalar,
        .iconSprite = gMonIcon_SlowpokeGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, -8, SHADOW_SIZE_L)
        FOOTPRINT(Slowpoke)
        OVERWORLD(
            sPicTable_SlowpokeGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SlowpokeGalar,
            gShinyOverworldPalette_SlowpokeGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sSlowpokeGalarLevelUpLearnset,
        .teachableLearnset = sSlowpokeGalarTeachableLearnset,
        .eggMoveLearnset = sSlowpokeGalarEggMoveLearnset,
        .formSpeciesIdTable = sSlowpokeFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_GALARICA_CUFF, SPECIES_SLOWBRO_GALAR}
                            #if P_GEN_2_CROSS_EVOS
                                ,{EVO_ITEM, ITEM_GALARICA_WREATH, SPECIES_SLOWKING_GALAR}
                            #endif
                            ),
    },

    [SPECIES_SLOWBRO_GALAR] =
    {
        .baseHP        = 95,
        .baseAttack    = 100,
        .baseDefense   = 95,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_POISON, TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = 172,
        .evYield_Attack = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_QUICK_DRAW, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Slowbro"),
        .cryId = CRY_SLOWBRO,
        .natDexNum = NATIONAL_DEX_SLOWBRO,
        .categoryName = _("Hermit Crab"),
        .height = 16,
        .weight = 705,
        .description = COMPOUND_STRING(
            "A Shellder bite set off a chemical reaction\n"
            "with the spices inside Slowbro's body,\n"
            "causing Slowbro to become a\n"
            "Poison-type Pokémon."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 296,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_SlowbroGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SlowbroGalar,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SlowbroGalar,
        .shinyPalette = gMonShinyPalette_SlowbroGalar,
        .iconSprite = gMonIcon_SlowbroGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 9, SHADOW_SIZE_L)
        FOOTPRINT(Slowbro)
        OVERWORLD(
            sPicTable_SlowbroGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_SlowbroGalar,
            gShinyOverworldPalette_SlowbroGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sSlowbroGalarLevelUpLearnset,
        .teachableLearnset = sSlowbroGalarTeachableLearnset,
        .formSpeciesIdTable = sSlowbroFormSpeciesIdTable,
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_SLOWKING_GALAR] =
    {
        .baseHP        = 95,
        .baseAttack    = 65,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 110,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_POISON, TYPE_PSYCHIC),
        .catchRate = 70,
        .expYield = 172,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_CURIOUS_MEDICINE, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Slowking"),
        .cryId = CRY_SLOWKING,
        .natDexNum = NATIONAL_DEX_SLOWKING,
        .categoryName = _("Hexpert"),
        .height = 18,
        .weight = 795,
        .description = COMPOUND_STRING(
            "A combination of toxins and the shock of\n"
            "evolving has increased Shellder's\n"
            "intelligence to the point that Shellder\n"
            "now controls Slowking."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
        .frontPic = gMonFrontPic_SlowkingGalar,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SlowkingGalar,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SlowkingGalar,
        .shinyPalette = gMonShinyPalette_SlowkingGalar,
        .iconSprite = gMonIcon_SlowkingGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 12, SHADOW_SIZE_M)
        FOOTPRINT(Slowking)
        OVERWORLD(
            sPicTable_SlowkingGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SlowkingGalar,
            gShinyOverworldPalette_SlowkingGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sSlowkingGalarLevelUpLearnset,
        .teachableLearnset = sSlowkingGalarTeachableLearnset,
        .formSpeciesIdTable = sSlowkingFormSpeciesIdTable,
    },
#endif //P_GEN_2_CROSS_EVOS
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_SLOWPOKE

#if P_FAMILY_MAGNEMITE
#define MAGNEMITE_FAMILY_TYPE2 (P_UPDATED_TYPES >= GEN_2 ? TYPE_STEEL : TYPE_ELECTRIC)

    [SPECIES_MAGNEMITE] =
    {
        .baseHP        = 25,
        .baseAttack    = 35,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 95,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 55 : 95,
        .types = MON_TYPES(TYPE_ELECTRIC, MAGNEMITE_FAMILY_TYPE2),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 65 : 89,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Magnemite"),
        .cryId = CRY_MAGNEMITE,
        .natDexNum = NATIONAL_DEX_MAGNEMITE,
        .categoryName = _("Magnet"),
        .height = 3,
        .weight = 60,
        .description = COMPOUND_STRING(
            "The units at its sides are extremely\n"
            "powerful magnets. They generate enough\n"
            "magnetism to draw in iron objects from\n"
            "over 300 feet away."),
        .pokemonScale = 288,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magnemite,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 24) : MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 21 : 20,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 28),
            ANIMCMD_FRAME(1, 28),
            ANIMCMD_FRAME(0, 28),
            ANIMCMD_FRAME(1, 28),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_TUMBLING_FRONT_FLIP_TWICE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 16 : 17,
        .backPic = gMonBackPic_Magnemite,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 24) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 15,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Magnemite,
        .shinyPalette = gMonShinyPalette_Magnemite,
        .iconSprite = gMonIcon_Magnemite,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_S)
        FOOTPRINT(Magnemite)
        OVERWORLD(
            sPicTable_Magnemite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Magnemite,
            gShinyOverworldPalette_Magnemite
        )
        .levelUpLearnset = sMagnemiteLevelUpLearnset,
        .teachableLearnset = sMagnemiteTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_MAGNETON}),
    },

    [SPECIES_MAGNETON] =
    {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 95,
        .baseSpeed     = 70,
        .baseSpAttack  = 120,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 70 : 120,
        .types = MON_TYPES(TYPE_ELECTRIC, MAGNEMITE_FAMILY_TYPE2),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 161,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Magneton"),
        .cryId = CRY_MAGNETON,
        .natDexNum = NATIONAL_DEX_MAGNETON,
        .categoryName = _("Magnet"),
        .height = 10,
        .weight = 600,
        .description = COMPOUND_STRING(
            "It is actually three Magnemite linked\n"
            "by magnetism. It generates powerful radio\n"
            "waves that raise temperatures by 3.6\n"
            "degrees F within a 3,300-foot radius."),
        .pokemonScale = 292,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magneton,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
        ),
        .frontAnimId = ANIM_FLASH_YELLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .backPic = gMonBackPic_Magneton,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Magneton,
        .shinyPalette = gMonShinyPalette_Magneton,
        .iconSprite = gMonIcon_Magneton,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_M)
        FOOTPRINT(Magneton)
        OVERWORLD(
            sPicTable_Magneton,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Magneton,
            gShinyOverworldPalette_Magneton
        )
        .levelUpLearnset = sMagnetonLevelUpLearnset,
        .teachableLearnset = sMagnetonTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_MAGNEZONE, CONDITIONS({IF_IN_MAPSEC, MAPSEC_NEW_MAUVILLE})},
                                {EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_MAGNEZONE}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGNEZONE] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 115,
        .baseSpeed     = 60,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_STEEL),
        .catchRate = 30,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 268,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 241,
    #else
        .expYield = 211,
    #endif
        .evYield_SpAttack = 3,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Magnezone"),
        .cryId = CRY_MAGNEZONE,
        .natDexNum = NATIONAL_DEX_MAGNEZONE,
        .categoryName = _("Magnet Area"),
        .height = 12,
        .weight = 1800,
        .description = COMPOUND_STRING(
            "As it zooms through the sky, this\n"
            "Pokémon seems to be receiving signals\n"
            "of unknown origin, while transmitting its\n"
            "own signals of unknown purpose."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magnezone,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_Magnezone,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Magnezone,
        .shinyPalette = gMonShinyPalette_Magnezone,
        .iconSprite = gMonIcon_Magnezone,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Magnezone)
        OVERWORLD(
            sPicTable_Magnezone,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Magnezone,
            gShinyOverworldPalette_Magnezone
        )
        .levelUpLearnset = sMagnezoneLevelUpLearnset,
        .teachableLearnset = sMagnezoneTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MAGNEMITE

#if P_FAMILY_FARFETCHD
    [SPECIES_FARFETCHD] =
    {
        .baseHP        = 52,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 90 : 65,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 58,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 62 : 58,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 132,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 123,
    #else
        .expYield = 94,
    #endif
        .evYield_Attack = 1,
        .itemRare = ITEM_LEEK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_FIELD),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_INNER_FOCUS, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Farfetch'd"),
        .cryId = CRY_FARFETCHD,
        .natDexNum = NATIONAL_DEX_FARFETCHD,
        .categoryName = _("Wild Duck"),
        .height = 8,
        .weight = 150,
        .description = COMPOUND_STRING(
            "It is always seen with a stick from a plant.\n"
            "Apparently, there are good sticks and bad\n"
            "sticks. This Pokémon occasionally fights\n"
            "with others over choice sticks."),
        .pokemonScale = 330,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Farfetchd,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .backPic = gMonBackPic_Farfetchd,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Farfetchd,
        .shinyPalette = gMonShinyPalette_Farfetchd,
        .iconSprite = gMonIcon_Farfetchd,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Farfetchd)
        OVERWORLD(
            sPicTable_Farfetchd,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following_Asym,
            gOverworldPalette_Farfetchd,
            gShinyOverworldPalette_Farfetchd
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sFarfetchdLevelUpLearnset,
        .teachableLearnset = sFarfetchdTeachableLearnset,
        .eggMoveLearnset = sFarfetchdEggMoveLearnset,
        .formSpeciesIdTable = sFarfetchdFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_FARFETCHD_GALAR] =
    {
        .baseHP        = 52,
        .baseAttack    = 95,
        .baseDefense   = 55,
        .baseSpeed     = 55,
        .baseSpAttack  = 58,
        .baseSpDefense = 62,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 132,
        .evYield_Attack = 1,
        .itemCommon = ITEM_LEEK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_FIELD),
        .abilities = { ABILITY_STEADFAST, ABILITY_NONE, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Farfetch'd"),
        .cryId = CRY_FARFETCHD,
        .natDexNum = NATIONAL_DEX_FARFETCHD,
        .categoryName = _("Wild Duck"),
        .height = 8,
        .weight = 420,
        .description = COMPOUND_STRING(
            "The stalks of leeks are thicker and longer\n"
            "in the Galar region. Brave Farfetch'd\n"
            "warriors that adapted to these stalks\n"
            "took on a unique form."),
        .pokemonScale = 330,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_FarfetchdGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_FarfetchdGalar,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_FarfetchdGalar,
        .shinyPalette = gMonShinyPalette_FarfetchdGalar,
        .iconSprite = gMonIcon_FarfetchdGalar,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 2, SHADOW_SIZE_L)
        FOOTPRINT(Farfetchd)
        OVERWORLD(
            sPicTable_FarfetchdGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_FarfetchdGalar,
            gShinyOverworldPalette_FarfetchdGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sFarfetchdGalarLevelUpLearnset,
        .teachableLearnset = sFarfetchdGalarTeachableLearnset,
        .eggMoveLearnset = sFarfetchdGalarEggMoveLearnset,
        .formSpeciesIdTable = sFarfetchdFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_BATTLE_END, 0, SPECIES_SIRFETCHD, CONDITIONS({IF_CRITICAL_HITS_GE, 3})}),
    },

    [SPECIES_SIRFETCHD] =
    {
        .baseHP        = 62,
        .baseAttack    = 135,
        .baseDefense   = 95,
        .baseSpeed     = 65,
        .baseSpAttack  = 68,
        .baseSpDefense = 82,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .itemRare = ITEM_LEEK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_FIELD),
        .abilities = { ABILITY_STEADFAST, ABILITY_NONE, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Sirfetch'd"),
        .cryId = CRY_SIRFETCHD,
        .natDexNum = NATIONAL_DEX_SIRFETCHD,
        .categoryName = _("Wild Duck"),
        .height = 8,
        .weight = 1170,
        .description = COMPOUND_STRING(
            "Only Farfetch'd that have survived many\n"
            "battles can attain this evolution. When\n"
            "this Pokémon's leek withers, it will\n"
            "retire from combat."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sirfetchd,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sirfetchd,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sirfetchd,
        .shinyPalette = gMonShinyPalette_Sirfetchd,
        .iconSprite = gMonIcon_Sirfetchd,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Sirfetchd)
        OVERWORLD(
            sPicTable_Sirfetchd,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sirfetchd,
            gShinyOverworldPalette_Sirfetchd
        )
        .levelUpLearnset = sSirfetchdLevelUpLearnset,
        .teachableLearnset = sSirfetchdTeachableLearnset,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_FARFETCHD

#if P_FAMILY_DODUO
    [SPECIES_DODUO] =
    {
        .baseHP        = 35,
        .baseAttack    = 85,
        .baseDefense   = 45,
        .baseSpeed     = 75,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 96,
        .evYield_Attack = 1,
        .itemRare = ITEM_SHARP_BEAK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_EARLY_BIRD, ABILITY_TANGLED_FEET },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Doduo"),
        .cryId = CRY_DODUO,
        .natDexNum = NATIONAL_DEX_DODUO,
        .categoryName = _("Twin Bird"),
        .height = 14,
        .weight = 392,
        .description = COMPOUND_STRING(
            "Even while eating or sleeping, one of the\n"
            "heads remains always vigilant for any sign\n"
            "of danger. When threatened, it flees at\n"
            "over 60 miles per hour."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = -1,
        .frontPic = gMonFrontPic_Doduo,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 18),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 18),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        .backPic = gMonBackPic_Doduo,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Doduo,
        .shinyPalette = gMonShinyPalette_Doduo,
        .iconSprite = gMonIcon_Doduo,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_DoduoF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_DoduoF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 5, SHADOW_SIZE_M)
        FOOTPRINT(Doduo)
        OVERWORLD(
            sPicTable_Doduo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Doduo,
            gShinyOverworldPalette_Doduo
        )
        OVERWORLD_FEMALE(
            sPicTable_DoduoF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sDoduoLevelUpLearnset,
        .teachableLearnset = sDoduoTeachableLearnset,
        .eggMoveLearnset = sDoduoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_DODRIO}),
    },

    [SPECIES_DODRIO] =
    {
        .baseHP        = 60,
        .baseAttack    = 110,
        .baseDefense   = 70,
        .baseSpeed     = P_UPDATED_STATS >= GEN_7 ? 110 : 100,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 165,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 161,
    #else
        .expYield = 158,
    #endif
        .evYield_Attack = 2,
        .itemRare = ITEM_SHARP_BEAK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_EARLY_BIRD, ABILITY_TANGLED_FEET },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Dodrio"),
        .cryId = CRY_DODRIO,
        .natDexNum = NATIONAL_DEX_DODRIO,
        .categoryName = _("Triple Bird"),
        .height = 18,
        .weight = 852,
        .description = COMPOUND_STRING(
            "A peculiar Pokémon species with three\n"
            "heads. It vigorously races across grassy\n"
            "plains even in arid seasons with little\n"
            "rainfall."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dodrio,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_LUNGE_GROW : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Dodrio,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 3,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Dodrio,
        .shinyPalette = gMonShinyPalette_Dodrio,
        .iconSprite = gMonIcon_Dodrio,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_DodrioF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_DodrioF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 12, SHADOW_SIZE_L)
        FOOTPRINT(Dodrio)
        OVERWORLD(
            sPicTable_Dodrio,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dodrio,
            gShinyOverworldPalette_Dodrio
        )
        OVERWORLD_FEMALE(
            sPicTable_DodrioF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sDodrioLevelUpLearnset,
        .teachableLearnset = sDodrioTeachableLearnset,
    },
#endif //P_FAMILY_DODUO

#if P_FAMILY_SEEL
    [SPECIES_SEEL] =
    {
        .baseHP        = 65,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 45,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 45 : 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 65 : 100,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_THICK_FAT, ABILITY_HYDRATION, ABILITY_ICE_BODY },
    #else
        .abilities = { ABILITY_THICK_FAT, ABILITY_NONE, ABILITY_ICE_BODY },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Seel"),
        .cryId = CRY_SEEL,
        .natDexNum = NATIONAL_DEX_SEEL,
        .categoryName = _("Sea Lion"),
        .height = 11,
        .weight = 900,
        .description = COMPOUND_STRING(
            "Seel hunt for prey in frigid, ice-covered\n"
            "seas. When it needs to breathe, it punches\n"
            "a hole through the ice with the sharply\n"
            "protruding section of its head."),
        .pokemonScale = 297,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Seel,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE : ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Seel,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Seel,
        .shinyPalette = gMonShinyPalette_Seel,
        .iconSprite = gMonIcon_Seel,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_L)
        FOOTPRINT(Seel)
        OVERWORLD(
            sPicTable_Seel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Seel,
            gShinyOverworldPalette_Seel
        )
        .levelUpLearnset = sSeelLevelUpLearnset,
        .teachableLearnset = sSeelTeachableLearnset,
        .eggMoveLearnset = sSeelEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_DEWGONG}),
    },

    [SPECIES_DEWGONG] =
    {
        .baseHP        = 90,
        .baseAttack    = 70,
        .baseDefense   = 80,
        .baseSpeed     = 70,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 70 : 95,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 166 : 176,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_THICK_FAT, ABILITY_HYDRATION, ABILITY_ICE_BODY },
    #else
        .abilities = { ABILITY_THICK_FAT, ABILITY_NONE, ABILITY_ICE_BODY },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Dewgong"),
        .cryId = CRY_DEWGONG,
        .natDexNum = NATIONAL_DEX_DEWGONG,
        .categoryName = _("Sea Lion"),
        .height = 17,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "It loves to snooze on bitterly cold ice.\n"
            "The sight of this Pokémon sleeping on\n"
            "a glacier was mistakenly thought to be\n"
            "a mermaid by a mariner long ago."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 275,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dewgong,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Dewgong,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Dewgong,
        .shinyPalette = gMonShinyPalette_Dewgong,
        .iconSprite = gMonIcon_Dewgong,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Dewgong)
        OVERWORLD(
            sPicTable_Dewgong,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dewgong,
            gShinyOverworldPalette_Dewgong
        )
        .levelUpLearnset = sDewgongLevelUpLearnset,
        .teachableLearnset = sDewgongTeachableLearnset,
    },
#endif //P_FAMILY_SEEL

#if P_FAMILY_GRIMER
    [SPECIES_GRIMER] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 50 : 40,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 65 : 90,
        .evYield_HP = 1,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_STENCH, ABILITY_STICKY_HOLD, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Grimer"),
        .cryId = CRY_GRIMER,
        .natDexNum = NATIONAL_DEX_GRIMER,
        .categoryName = _("Sludge"),
        .height = 9,
        .weight = 300,
        .description = COMPOUND_STRING(
            "Born from polluted sludge in the sea,\n"
            "Grimer's favorite food is anything filthy.\n"
            "They feed on wastewater pumped out from\n"
            "factories."),
        .pokemonScale = 258,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Grimer,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Grimer,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 13,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Grimer,
        .shinyPalette = gMonShinyPalette_Grimer,
        .iconSprite = gMonIcon_Grimer,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 3, SHADOW_SIZE_M)
        FOOTPRINT(Grimer)
        OVERWORLD(
            sPicTable_Grimer,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Grimer,
            gShinyOverworldPalette_Grimer
        )
        .levelUpLearnset = sGrimerLevelUpLearnset,
        .teachableLearnset = sGrimerTeachableLearnset,
        .eggMoveLearnset = sGrimerEggMoveLearnset,
        .formSpeciesIdTable = sGrimerFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_MUK}),
    },

    [SPECIES_MUK] =
    {
        .baseHP        = 105,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 100 : 65,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 157,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_STENCH, ABILITY_STICKY_HOLD, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Muk"),
        .cryId = CRY_MUK,
        .natDexNum = NATIONAL_DEX_MUK,
        .categoryName = _("Sludge"),
        .height = 12,
        .weight = 300,
        .description = COMPOUND_STRING(
            "It prefers warm and humid habitats.\n"
            "In the summertime, the toxic substances\n"
            "in its body intensify, making Muk reek like\n"
            "putrid kitchen garbage."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Muk,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = 45,
        .backPic = gMonBackPic_Muk,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 9,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Muk,
        .shinyPalette = gMonShinyPalette_Muk,
        .iconSprite = gMonIcon_Muk,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Muk)
        OVERWORLD(
            sPicTable_Muk,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Muk,
            gShinyOverworldPalette_Muk
        )
        .levelUpLearnset = sMukLevelUpLearnset,
        .teachableLearnset = sMukTeachableLearnset,
        .formSpeciesIdTable = sMukFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_GRIMER_ALOLA] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_POISON, TYPE_DARK),
        .catchRate = 190,
        .expYield = 65,
        .evYield_HP = 1,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_POISON_TOUCH, ABILITY_GLUTTONY, ABILITY_POWER_OF_ALCHEMY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Grimer"),
        .cryId = CRY_GRIMER,
        .natDexNum = NATIONAL_DEX_GRIMER,
        .categoryName = _("Sludge"),
        .height = 7,
        .weight = 420,
        .description = COMPOUND_STRING(
            "There are a hundred or so of them living\n"
            "in Alola's waste-disposal site. They're all\n"
            "hard workers who eat a lot of trash. Grimer\n"
            "seems to relish any and all kinds of trash."),
        .pokemonScale = 258,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GrimerAlola,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_GrimerAlola,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GrimerAlola,
        .shinyPalette = gMonShinyPalette_GrimerAlola,
        .iconSprite = gMonIcon_GrimerAlola,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 1, SHADOW_SIZE_M)
        FOOTPRINT(Grimer)
        OVERWORLD(
            sPicTable_GrimerAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GrimerAlola,
            gShinyOverworldPalette_GrimerAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sGrimerAlolaLevelUpLearnset,
        .teachableLearnset = sGrimerAlolaTeachableLearnset,
        .eggMoveLearnset = sGrimerAlolaEggMoveLearnset,
        .formSpeciesIdTable = sGrimerFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_MUK_ALOLA}),
    },

    [SPECIES_MUK_ALOLA] =
    {
        .baseHP        = 105,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_POISON, TYPE_DARK),
        .catchRate = 75,
        .expYield = 175,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_POISON_TOUCH, ABILITY_GLUTTONY, ABILITY_POWER_OF_ALCHEMY },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Muk"),
        .cryId = CRY_MUK,
        .natDexNum = NATIONAL_DEX_MUK,
        .categoryName = _("Sludge"),
        .height = 10,
        .weight = 520,
        .description = COMPOUND_STRING(
            "While it's unexpectedly quiet and friendly,\n"
            "if it's not fed any trash for a while,,\n"
            "it will smash its Trainer's furnishings,\n"
            "and eat up the fragments."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MukAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_STRETCH_BOTH_ENDS_SLOW,
        .backPic = gMonBackPic_MukAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MukAlola,
        .shinyPalette = gMonShinyPalette_MukAlola,
        .iconSprite = gMonIcon_MukAlola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 7, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Muk)
        OVERWORLD(
            sPicTable_MukAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_MukAlola,
            gShinyOverworldPalette_MukAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sMukAlolaLevelUpLearnset,
        .teachableLearnset = sMukAlolaTeachableLearnset,
        .formSpeciesIdTable = sMukFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_GRIMER

#if P_FAMILY_SHELLDER
    [SPECIES_SHELLDER] =
    {
        .baseHP        = 30,
        .baseAttack    = 65,
        .baseDefense   = 100,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 25 : 45,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 61 : 97,
        .evYield_Defense = 1,
        .itemCommon = ITEM_PEARL,
        .itemRare = ITEM_BIG_PEARL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_SKILL_LINK, ABILITY_OVERCOAT },
    #else
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_NONE, ABILITY_OVERCOAT },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Shellder"),
        .cryId = CRY_SHELLDER,
        .natDexNum = NATIONAL_DEX_SHELLDER,
        .categoryName = _("Bivalve"),
        .height = 3,
        .weight = 40,
        .description = COMPOUND_STRING(
            "At night, it burrows a hole in the seafloor\n"
            "with its broad tongue to make a place to\n"
            "sleep. While asleep, it closes its shell,\n"
            "but leaves its tongue hanging out."),
        .pokemonScale = 675,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shellder,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_TWIST,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Shellder,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 24),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 21,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Shellder,
        .shinyPalette = gMonShinyPalette_Shellder,
        .iconSprite = gMonIcon_Shellder,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -4, SHADOW_SIZE_S)
        FOOTPRINT(Shellder)
        OVERWORLD(
            sPicTable_Shellder,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Shellder,
            gShinyOverworldPalette_Shellder
        )
        .levelUpLearnset = sShellderLevelUpLearnset,
        .teachableLearnset = sShellderTeachableLearnset,
        .eggMoveLearnset = sShellderEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_WATER_STONE, SPECIES_CLOYSTER}),
    },

    [SPECIES_CLOYSTER] =
    {
        .baseHP        = 50,
        .baseAttack    = 95,
        .baseDefense   = 180,
        .baseSpeed     = 70,
        .baseSpAttack  = 85,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 45 : 85,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 203,
        .evYield_Defense = 2,
        .itemCommon = ITEM_PEARL,
        .itemRare = ITEM_BIG_PEARL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_SKILL_LINK, ABILITY_OVERCOAT },
    #else
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_NONE, ABILITY_OVERCOAT },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Cloyster"),
        .cryId = CRY_CLOYSTER,
        .natDexNum = NATIONAL_DEX_CLOYSTER,
        .categoryName = _("Bivalve"),
        .height = 15,
        .weight = 1325,
        .description = COMPOUND_STRING(
            "It swims in the sea by swallowing water,\n"
            "then jetting it out toward the rear.\n"
            "The Cloyster shoots spikes from its\n"
            "shell using the same system."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 269,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Cloyster,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SLIDE_WOBBLE : ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Cloyster,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Cloyster,
        .shinyPalette = gMonShinyPalette_Cloyster,
        .iconSprite = gMonIcon_Cloyster,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_M)
        FOOTPRINT(Cloyster)
        OVERWORLD(
            sPicTable_Cloyster,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Cloyster,
            gShinyOverworldPalette_Cloyster
        )
        .levelUpLearnset = sCloysterLevelUpLearnset,
        .teachableLearnset = sCloysterTeachableLearnset,
    },
#endif //P_FAMILY_SHELLDER

#if P_FAMILY_GASTLY
    [SPECIES_GASTLY] =
    {
        .baseHP        = 30,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 35 : 100,
        .types = MON_TYPES(TYPE_GHOST, TYPE_POISON),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 95,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gastly"),
        .cryId = CRY_GASTLY,
        .natDexNum = NATIONAL_DEX_GASTLY,
        .categoryName = _("Gas"),
        .height = 13,
        .weight = 1,
        .description = COMPOUND_STRING(
            "When exposed to a strong wind, a Gastly's\n"
            "gaseous body quickly dwindles away.\n"
            "They cluster under the eaves of houses\n"
            "to escape the ravages of wind."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gastly,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_GLOW_BLACK : ANIM_SHRINK_GROW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 4 : 13,
        .backPic = gMonBackPic_Gastly,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Gastly,
        .shinyPalette = gMonShinyPalette_Gastly,
        .iconSprite = gMonIcon_Gastly,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_S)
        FOOTPRINT(Gastly)
        OVERWORLD(
            sPicTable_Gastly,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Gastly,
            gShinyOverworldPalette_Gastly
        )
        .levelUpLearnset = sGastlyLevelUpLearnset,
        .teachableLearnset = sGastlyTeachableLearnset,
        .eggMoveLearnset = sGastlyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_HAUNTER}),
    },

    [SPECIES_HAUNTER] =
    {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 115,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 55 : 115,
        .types = MON_TYPES(TYPE_GHOST, TYPE_POISON),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 126,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Haunter"),
        .cryId = CRY_HAUNTER,
        .natDexNum = NATIONAL_DEX_HAUNTER,
        .categoryName = _("Gas"),
        .height = 16,
        .weight = 1,
        .description = COMPOUND_STRING(
            "If a Haunter beckons you while it is\n"
            "floating in darkness, don't approach it.\n"
            "This Pokémon will try to lick you with its\n"
            "tongue and steal your life away."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Haunter,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_FLICKER_INCREASING,
        .frontAnimDelay = 23,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 4 : 14,
        .backPic = gMonBackPic_Haunter,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 4,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Haunter,
        .shinyPalette = gMonShinyPalette_Haunter,
        .iconSprite = gMonIcon_Haunter,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Haunter)
        OVERWORLD(
            sPicTable_Haunter,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Haunter,
            gShinyOverworldPalette_Haunter
        )
        .levelUpLearnset = sHaunterLevelUpLearnset,
        .teachableLearnset = sHaunterTeachableLearnset,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GENGAR},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GENGAR}),
    },

#define GENGAR_SP_DEF (P_UPDATED_STATS >= GEN_2 ? 75 : 130)

#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define GENGAR_EXP_YIELD 250
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define GENGAR_EXP_YIELD 225
#else
    #define GENGAR_EXP_YIELD 190
#endif

#if P_UPDATED_ABILITIES >= GEN_7
    #define GENGAR_ABILITIES {ABILITY_CURSED_BODY, ABILITY_NONE, ABILITY_NONE}
#else
    #define GENGAR_ABILITIES {ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE}
#endif

    [SPECIES_GENGAR] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = GENGAR_SP_DEF,
        .types = MON_TYPES(TYPE_GHOST, TYPE_POISON),
        .catchRate = 45,
        .expYield = GENGAR_EXP_YIELD,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = GENGAR_ABILITIES,
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gengar"),
        .cryId = CRY_GENGAR,
        .natDexNum = NATIONAL_DEX_GENGAR,
        .categoryName = _("Shadow"),
        .height = 15,
        .weight = 405,
        .description = COMPOUND_STRING(
            "Deep in the night, your shadow cast by\n"
            "a streetlight may suddenly overtake you.\n"
            "It is actually a Gengar running past\n"
            "you, pretending to be your shadow."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 302,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Gengar,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .backPic = gMonBackPic_Gengar,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Gengar,
        .shinyPalette = gMonShinyPalette_Gengar,
        .iconSprite = gMonIcon_Gengar,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 5, SHADOW_SIZE_L)
        FOOTPRINT(Gengar)
        OVERWORLD(
            sPicTable_Gengar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gengar,
            gShinyOverworldPalette_Gengar
        )
        .levelUpLearnset = sGengarLevelUpLearnset,
        .teachableLearnset = sGengarTeachableLearnset,
        .formSpeciesIdTable = sGengarFormSpeciesIdTable,
        .formChangeTable = sGengarFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_GENGAR_MEGA] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 80,
        .baseSpeed     = 130,
        .baseSpAttack  = 170,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_GHOST, TYPE_POISON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_SHADOW_TAG, ABILITY_SHADOW_TAG, ABILITY_SHADOW_TAG },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gengar"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_GENGAR_MEGA,
    #else
        .cryId = CRY_GENGAR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_GENGAR,
        .categoryName = _("Shadow"),
        .height = 14,
        .weight = 405,
        .description = COMPOUND_STRING(
            "Gengar's relationships are warped. It\n"
            "tries to take the lives of anyone and\n"
            "everyone. It will even try to curse the\n"
            "Trainer who is its master!"),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 302,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_GengarMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 23),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        .backPic = gMonBackPic_GengarMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_GengarMega,
        .shinyPalette = gMonShinyPalette_GengarMega,
        .iconSprite = gMonIcon_GengarMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 1, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Gengar)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_GengarMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GengarMega,
            gShinyOverworldPalette_GengarMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .isTelekinesisBanned = TRUE,
        .levelUpLearnset = sGengarLevelUpLearnset,
        .teachableLearnset = sGengarTeachableLearnset,
        .formSpeciesIdTable = sGengarFormSpeciesIdTable,
        .formChangeTable = sGengarFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GIGANTAMAX_FORMS
    [SPECIES_GENGAR_GMAX] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = GENGAR_SP_DEF,
        .types = MON_TYPES(TYPE_GHOST, TYPE_POISON),
        .catchRate = 45,
        .expYield = GENGAR_EXP_YIELD,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = GENGAR_ABILITIES,
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gengar"),
        .cryId = CRY_GENGAR,
        .natDexNum = NATIONAL_DEX_GENGAR,
        .categoryName = _("Shadow"),
        .height = 200,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Rumor has it that its gigantic\n"
            "mouth leads not into its body, filled\n"
            "with cursed energy, but instead\n"
            "directly to the afterlife."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 302,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_GengarGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GengarGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GengarGmax,
        .shinyPalette = gMonShinyPalette_GengarGmax,
        .iconSprite = gMonIcon_GengarGmax,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Gengar)
        .isGigantamax = TRUE,
        .levelUpLearnset = sGengarLevelUpLearnset,
        .teachableLearnset = sGengarTeachableLearnset,
        .formSpeciesIdTable = sGengarFormSpeciesIdTable,
        .formChangeTable = sGengarFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_GASTLY

#if P_FAMILY_ONIX
    [SPECIES_ONIX] =
    {
        .baseHP        = 35,
        .baseAttack    = 45,
        .baseDefense   = 160,
        .baseSpeed     = 70,
        .baseSpAttack  = 30,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 45 : 30,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GROUND),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 77 : 108,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Onix"),
        .cryId = CRY_ONIX,
        .natDexNum = NATIONAL_DEX_ONIX,
        .categoryName = _("Rock Snake"),
        .height = 88,
        .weight = 2100,
        .description = COMPOUND_STRING(
            "There is a magnet in its brain that\n"
            "prevents an Onix from losing direction\n"
            "while tunneling. As it grows older, its body\n"
            "becomes steadily rounder and smoother."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 515,
        .trainerOffset = 14,
        .frontPic = gMonFrontPic_Onix,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_RAPID_H_HOPS : ANIM_H_SHAKE,
        .backPic = gMonBackPic_Onix,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Onix,
        .shinyPalette = gMonShinyPalette_Onix,
        .iconSprite = gMonIcon_Onix,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Onix)
        OVERWORLD(
            sPicTable_Onix,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Onix,
            gShinyOverworldPalette_Onix
        )
        .levelUpLearnset = sOnixLevelUpLearnset,
        .teachableLearnset = sOnixTeachableLearnset,
        .eggMoveLearnset = sOnixEggMoveLearnset,
    #if P_GEN_2_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_STEELIX, CONDITIONS({IF_HOLD_ITEM, ITEM_METAL_COAT})},
                                {EVO_ITEM, ITEM_METAL_COAT, SPECIES_STEELIX}),
    #endif
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_STEELIX] =
    {
        .baseHP        = 75,
        .baseAttack    = 85,
        .baseDefense   = 200,
        .baseSpeed     = 30,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_STEEL, TYPE_GROUND),
        .catchRate = 25,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 179 : 196,
        .evYield_Defense = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Steelix"),
        .cryId = CRY_STEELIX,
        .natDexNum = NATIONAL_DEX_STEELIX,
        .categoryName = _("Iron Snake"),
        .height = 92,
        .weight = 4000,
        .description = COMPOUND_STRING(
            "Steelix live even further underground\n"
            "than Onix. This Pokémon is known to dig\n"
            "toward the earth's core, reaching a depth\n"
            "of over six-tenths of a mile underground."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 516,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_Steelix,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 21),
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 21),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SHAKE : ANIM_V_SHAKE,
        .frontAnimDelay = 45,
        .backPic = gMonBackPic_Steelix,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Steelix,
        .shinyPalette = gMonShinyPalette_Steelix,
        .iconSprite = gMonIcon_Steelix,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SteelixF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_SteelixF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Steelix)
        OVERWORLD(
            sPicTable_Steelix,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Steelix,
            gShinyOverworldPalette_Steelix
        )
        OVERWORLD_FEMALE(
            sPicTable_SteelixF,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSteelixLevelUpLearnset,
        .teachableLearnset = sSteelixTeachableLearnset,
        .formSpeciesIdTable = sSteelixFormSpeciesIdTable,
        .formChangeTable = sSteelixFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_STEELIX_MEGA] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 230,
        .baseSpeed     = 30,
        .baseSpAttack  = 55,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_STEEL, TYPE_GROUND),
        .catchRate = 25,
        .expYield = 214,
        .evYield_Defense = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SAND_FORCE, ABILITY_SAND_FORCE, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Steelix"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_STEELIX_MEGA,
    #else
        .cryId = CRY_STEELIX,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_STEELIX,
        .categoryName = _("Iron Snake"),
        .height = 105,
        .weight = 7400,
        .description = COMPOUND_STRING(
            "The cells within its body, crystallized by\n"
            "the energy produced from Mega Evolution,\n"
            "are stronger than any mineral and able\n"
            "to withstand any temperature."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 516,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_SteelixMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SteelixMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_SteelixMega,
        .shinyPalette = gMonShinyPalette_SteelixMega,
        .iconSprite = gMonIcon_SteelixMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Steelix)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_SteelixMega,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_SteelixMega,
            gShinyOverworldPalette_SteelixMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSteelixLevelUpLearnset,
        .teachableLearnset = sSteelixTeachableLearnset,
        .formSpeciesIdTable = sSteelixFormSpeciesIdTable,
        .formChangeTable = sSteelixFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_ONIX

#if P_FAMILY_DROWZEE
    [SPECIES_DROWZEE] =
    {
        .baseHP        = 60,
        .baseAttack    = 48,
        .baseDefense   = 45,
        .baseSpeed     = 42,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 43 : 90,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 102,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INSOMNIA, ABILITY_FOREWARN, ABILITY_INNER_FOCUS },
    #else
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_INNER_FOCUS },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Drowzee"),
        .cryId = CRY_DROWZEE,
        .natDexNum = NATIONAL_DEX_DROWZEE,
        .categoryName = _("Hypnosis"),
        .height = 10,
        .weight = 324,
        .description = COMPOUND_STRING(
            "If your nose becomes itchy while you are\n"
            "sleeping, it's a sure sign that a Drowzee is\n"
            "standing above your pillow and trying to\n"
            "eat your dream through your nostrils."),
        .pokemonScale = 274,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Drowzee,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_CIRCLE_C_CLOCKWISE_SLOW : ANIM_V_STRETCH,
        .frontAnimDelay = 48,
        .backPic = gMonBackPic_Drowzee,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 9,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Drowzee,
        .shinyPalette = gMonShinyPalette_Drowzee,
        .iconSprite = gMonIcon_Drowzee,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 6, SHADOW_SIZE_M)
        FOOTPRINT(Drowzee)
        OVERWORLD(
            sPicTable_Drowzee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Drowzee,
            gShinyOverworldPalette_Drowzee
        )
        .levelUpLearnset = sDrowzeeLevelUpLearnset,
        .teachableLearnset = sDrowzeeTeachableLearnset,
        .eggMoveLearnset = sDrowzeeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_HYPNO}),
    },

    [SPECIES_HYPNO] =
    {
        .baseHP        = 85,
        .baseAttack    = 73,
        .baseDefense   = 70,
        .baseSpeed     = 67,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 73 : 115,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 169 : 165,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INSOMNIA, ABILITY_FOREWARN, ABILITY_INNER_FOCUS },
    #else
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_INNER_FOCUS },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Hypno"),
        .cryId = CRY_HYPNO,
        .natDexNum = NATIONAL_DEX_HYPNO,
        .categoryName = _("Hypnosis"),
        .height = 16,
        .weight = 756,
        .description = COMPOUND_STRING(
            "The arcing movement and glitter of the\n"
            "pendulum in a Hypno's hand lull the foe\n"
            "into deep hypnosis. While searching for\n"
            "prey, it polishes the pendulum."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hypno,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .frontAnimDelay = 40,
        .backPic = gMonBackPic_Hypno,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 5,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Hypno,
        .shinyPalette = gMonShinyPalette_Hypno,
        .iconSprite = gMonIcon_Hypno,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_HypnoF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_HypnoF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 9, SHADOW_SIZE_L)
        FOOTPRINT(Hypno)
        OVERWORLD(
            sPicTable_Hypno,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hypno,
            gShinyOverworldPalette_Hypno
        )
        OVERWORLD_FEMALE(
            sPicTable_HypnoF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sHypnoLevelUpLearnset,
        .teachableLearnset = sHypnoTeachableLearnset,
    },
#endif //P_FAMILY_DROWZEE

#if P_FAMILY_KRABBY
    [SPECIES_KRABBY] =
    {
        .baseHP        = 30,
        .baseAttack    = 105,
        .baseDefense   = 90,
        .baseSpeed     = 50,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 65 : 115,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SHELL_ARMOR, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Krabby"),
        .cryId = CRY_KRABBY,
        .natDexNum = NATIONAL_DEX_KRABBY,
        .categoryName = _("River Crab"),
        .height = 4,
        .weight = 65,
        .description = COMPOUND_STRING(
            "Krabby live in holes dug into beaches.\n"
            "On sandy shores with little in the way\n"
            "of food, they can be seen squabbling with\n"
            "each other over territory."),
        .pokemonScale = 469,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Krabby,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SLIDE : ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Krabby,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 15,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Krabby,
        .shinyPalette = gMonShinyPalette_Krabby,
        .iconSprite = gMonIcon_Krabby,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -1, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Krabby)
        OVERWORLD(
            sPicTable_Krabby,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Krabby,
            gShinyOverworldPalette_Krabby
        )
        .levelUpLearnset = sKrabbyLevelUpLearnset,
        .teachableLearnset = sKrabbyTeachableLearnset,
        .eggMoveLearnset = sKrabbyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_KINGLER}),
    },

    [SPECIES_KINGLER] =
    {
        .baseHP        = 55,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 166 : 206,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SHELL_ARMOR, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Kingler"),
        .cryId = CRY_KINGLER,
        .natDexNum = NATIONAL_DEX_KINGLER,
        .categoryName = _("Pincer"),
        .height = 13,
        .weight = 600,
        .description = COMPOUND_STRING(
            "It waves its huge, oversized claw in the\n"
            "air to communicate with others.\n"
            "But since the claw is so heavy, this\n"
            "Pokémon quickly tires."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kingler,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 14),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_ZIGZAG_SLOW : ANIM_V_SHAKE_TWICE,
        .frontAnimDelay = P_GBA_STYLE_SPECIES_GFX ? 0 : 4,
        .backPic = gMonBackPic_Kingler,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Kingler,
        .shinyPalette = gMonShinyPalette_Kingler,
        .iconSprite = gMonIcon_Kingler,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 4, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kingler)
        OVERWORLD(
            sPicTable_Kingler,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Kingler,
            gShinyOverworldPalette_Kingler
        )
        .levelUpLearnset = sKinglerLevelUpLearnset,
        .teachableLearnset = sKinglerTeachableLearnset,
        .formSpeciesIdTable = sKinglerFormSpeciesIdTable,
        .formChangeTable = sKinglerFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_KINGLER_GMAX] =
    {
        .baseHP        = 55,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 166 : 206,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SHELL_ARMOR, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Kingler"),
        .cryId = CRY_KINGLER,
        .natDexNum = NATIONAL_DEX_KINGLER,
        .categoryName = _("Pincer"),
        .height = 190,
        .weight = 0,
        .description = COMPOUND_STRING(
            "The flow of Gigantamax energy has\n"
            "spurred this Pokémon's left pincer\n"
            "to grow to an enormous size. That\n"
            "claw can pulverize anything."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KinglerGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_KinglerGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_KinglerGmax,
        .shinyPalette = gMonShinyPalette_KinglerGmax,
        .iconSprite = gMonIcon_KinglerGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kingler)
        .isGigantamax = TRUE,
        .levelUpLearnset = sKinglerLevelUpLearnset,
        .teachableLearnset = sKinglerTeachableLearnset,
        .formSpeciesIdTable = sKinglerFormSpeciesIdTable,
        .formChangeTable = sKinglerFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_KRABBY

#if P_FAMILY_VOLTORB
    [SPECIES_VOLTORB] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 100,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 103,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_STATIC, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Voltorb"),
        .cryId = CRY_VOLTORB,
        .natDexNum = NATIONAL_DEX_VOLTORB,
        .categoryName = _("Ball"),
        .height = 5,
        .weight = 104,
        .description = COMPOUND_STRING(
            "It bears an uncanny and unexplained\n"
            "resemblance to a Poké Ball. Because it\n"
            "explodes at the slightest shock, even\n"
            "veteran Trainers treat it with caution."),
        .pokemonScale = 364,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Voltorb,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 32) : MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 19 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_SWING_CONCAVE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 10 : 0,
        .backPic = gMonBackPic_Voltorb,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Voltorb,
        .shinyPalette = gMonShinyPalette_Voltorb,
        .iconSprite = gMonIcon_Voltorb,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, -2, SHADOW_SIZE_S)
        FOOTPRINT(Voltorb)
        OVERWORLD(
            sPicTable_Voltorb,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Voltorb,
            gShinyOverworldPalette_Voltorb
        )
        .levelUpLearnset = sVoltorbLevelUpLearnset,
        .teachableLearnset = sVoltorbTeachableLearnset,
        .formSpeciesIdTable = sVoltorbFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ELECTRODE}),
    },

    [SPECIES_ELECTRODE] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 70,
        .baseSpeed     = P_UPDATED_STATS >= GEN_7 ? 150 : 140,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 60,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 172,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 168,
    #else
        .expYield = 150,
    #endif
        .evYield_Speed = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_STATIC, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Electrode"),
        .cryId = CRY_ELECTRODE,
        .natDexNum = NATIONAL_DEX_ELECTRODE,
        .categoryName = _("Ball"),
        .height = 12,
        .weight = 666,
        .description = COMPOUND_STRING(
            "They appear in great numbers at electric\n"
            "power plants. Because they feed on\n"
            "electricity, they cause massive and\n"
            "chaotic blackouts in nearby cities."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Electrode,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 34),
            ANIMCMD_FRAME(1, 34),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_SHRINK_GROW_VIBRATE_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 12 : 0,
        .backPic = gMonBackPic_Electrode,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Electrode,
        .shinyPalette = gMonShinyPalette_Electrode,
        .iconSprite = gMonIcon_Electrode,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Electrode)
        OVERWORLD(
            sPicTable_Electrode,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Electrode,
            gShinyOverworldPalette_Electrode
        )
        .levelUpLearnset = sElectrodeLevelUpLearnset,
        .teachableLearnset = sElectrodeTeachableLearnset,
        .formSpeciesIdTable = sElectrodeFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_VOLTORB_HISUI] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 100,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_GRASS),
        .catchRate = 190,
        .expYield = 66,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_STATIC, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Voltorb"),
        .cryId = CRY_VOLTORB,
        .natDexNum = NATIONAL_DEX_VOLTORB,
        .categoryName = _("Sphere"),
        .height = 5,
        .weight = 130,
        .description = COMPOUND_STRING(
            "It resembles an ancient Poké Ball design.\n"
            "When excited, it discharges the electric\n"
            "current it has stored in its belly, then\n"
            "lets out a great, uproarious laugh."),
        .pokemonScale = 364,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_VoltorbHisui,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_VoltorbHisui,
        .backPicSize = MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_VoltorbHisui,
        .shinyPalette = gMonShinyPalette_VoltorbHisui,
        .iconSprite = gMonIcon_VoltorbHisui,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, -4, SHADOW_SIZE_S)
        FOOTPRINT(Voltorb)
        OVERWORLD(
            sPicTable_VoltorbHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_VoltorbHisui,
            gShinyOverworldPalette_VoltorbHisui
        )
        .isHisuianForm = TRUE,
        .levelUpLearnset = sVoltorbHisuiLevelUpLearnset,
        .teachableLearnset = sVoltorbHisuiTeachableLearnset,
        .formSpeciesIdTable = sVoltorbFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_ELECTRODE_HISUI}),
    },

    [SPECIES_ELECTRODE_HISUI] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 70,
        .baseSpeed     = 150,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_GRASS),
        .catchRate = 60,
        .expYield = 172,
        .evYield_Speed = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_STATIC, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Electrode"),
        .cryId = CRY_ELECTRODE,
        .natDexNum = NATIONAL_DEX_ELECTRODE,
        .categoryName = _("Sphere"),
        .height = 12,
        .weight = 710,
        .description = COMPOUND_STRING(
            "The tissue on the surface of its body is\n"
            "similar in composition to an Apricorn.\n"
            "When irritated, it lets loose an electric\n"
            "current equal to 20 lightning bolts."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ElectrodeHisui,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ElectrodeHisui,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ElectrodeHisui,
        .shinyPalette = gMonShinyPalette_ElectrodeHisui,
        .iconSprite = gMonIcon_ElectrodeHisui,
        .iconPalIndex = 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 4, SHADOW_SIZE_M)
        FOOTPRINT(Electrode)
        OVERWORLD(
            sPicTable_ElectrodeHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ElectrodeHisui,
            gShinyOverworldPalette_ElectrodeHisui
        )
        .isHisuianForm = TRUE,
        .levelUpLearnset = sElectrodeHisuiLevelUpLearnset,
        .teachableLearnset = sElectrodeHisuiTeachableLearnset,
        .formSpeciesIdTable = sElectrodeFormSpeciesIdTable,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_VOLTORB

#if P_FAMILY_EXEGGCUTE
    [SPECIES_EXEGGCUTE] =
    {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 80,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 45 : 60,
        .types = MON_TYPES(TYPE_GRASS, TYPE_PSYCHIC),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 65 : 98,
        .evYield_Defense = 1,
        .itemRare = ITEM_PSYCHIC_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Exeggcute"),
        .cryId = CRY_EXEGGCUTE,
        .natDexNum = NATIONAL_DEX_EXEGGCUTE,
        .categoryName = _("Egg"),
        .height = 4,
        .weight = 25,
        .description = COMPOUND_STRING(
            "It consists of six eggs that care for each\n"
            "other. The eggs attract each other and\n"
            "spin around. When cracks increasingly\n"
            "appear, it is close to evolution."),
        .pokemonScale = 489,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Exeggcute,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Exeggcute,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 18,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Exeggcute,
        .shinyPalette = gMonShinyPalette_Exeggcute,
        .iconSprite = gMonIcon_Exeggcute,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -5, SHADOW_SIZE_L)
        FOOTPRINT(Exeggcute)
        OVERWORLD(
            sPicTable_Exeggcute,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Exeggcute,
            gShinyOverworldPalette_Exeggcute
        )
        .levelUpLearnset = sExeggcuteLevelUpLearnset,
        .teachableLearnset = sExeggcuteTeachableLearnset,
        .eggMoveLearnset = sExeggcuteEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_EXEGGUTOR, CONDITIONS({IF_NOT_REGION, REGION_ALOLA})}
                            #if P_ALOLAN_FORMS
                                ,{EVO_ITEM, ITEM_LEAF_STONE, SPECIES_EXEGGUTOR_ALOLA, CONDITIONS({IF_REGION, REGION_ALOLA})}
                            #endif
                            ),
    },

    [SPECIES_EXEGGUTOR] =
    {
        .baseHP        = 95,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 125,
    #if P_UPDATED_STATS >= GEN_7
        .baseSpDefense = 75,
    #elif P_UPDATED_STATS >= GEN_2
        .baseSpDefense = 65,
    #else
        .baseSpDefense = 125,
    #endif
        .types = MON_TYPES(TYPE_GRASS, TYPE_PSYCHIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 186,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 182,
    #else
        .expYield = 212,
    #endif
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Exeggutor"),
        .cryId = CRY_EXEGGUTOR,
        .natDexNum = NATIONAL_DEX_EXEGGUTOR,
        .categoryName = _("Coconut"),
        .height = 20,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "Originally from the tropics, Exeggutor's\n"
            "heads grow larger from exposure to strong\n"
            "sunlight. It is said that when the heads\n"
            "fall, they group to form an Exeggcute."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
        .frontPic = gMonFrontPic_Exeggutor,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Exeggutor,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Exeggutor,
        .shinyPalette = gMonShinyPalette_Exeggutor,
        .iconSprite = gMonIcon_Exeggutor,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_L)
        FOOTPRINT(Exeggutor)
        OVERWORLD(
            sPicTable_Exeggutor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Exeggutor,
            gShinyOverworldPalette_Exeggutor
        )
        .levelUpLearnset = sExeggutorLevelUpLearnset,
        .teachableLearnset = sExeggutorTeachableLearnset,
        .formSpeciesIdTable = sExeggutorFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_EXEGGUTOR_ALOLA] =
    {
        .baseHP        = 95,
        .baseAttack    = 105,
        .baseDefense   = 85,
        .baseSpeed     = 45,
        .baseSpAttack  = 125,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 186,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_FRISK, ABILITY_NONE, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Exeggutor"),
        .cryId = CRY_EXEGGUTOR,
        .natDexNum = NATIONAL_DEX_EXEGGUTOR,
        .categoryName = _("Coconut"),
        .height = 109,
        .weight = 4156,
        .description = COMPOUND_STRING(
            "Alola is the best environment for\n"
            "this Pokémon. Local people take pride\n"
            "in its appearance, saying this is how\n"
            "Exeggutor ought to look."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
        .frontPic = gMonFrontPic_ExeggutorAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SHAKE_LOW_TWICE,
        .backPic = gMonBackPic_ExeggutorAlola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ExeggutorAlola,
        .shinyPalette = gMonShinyPalette_ExeggutorAlola,
        .iconSprite = gMonIcon_ExeggutorAlola,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Exeggutor)
        OVERWORLD(
            sPicTable_ExeggutorAlola,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ExeggutorAlola,
            gShinyOverworldPalette_ExeggutorAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sExeggutorAlolaLevelUpLearnset,
        .teachableLearnset = sExeggutorAlolaTeachableLearnset,
        .formSpeciesIdTable = sExeggutorFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_EXEGGCUTE

#if P_FAMILY_CUBONE
    [SPECIES_CUBONE] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 95,
        .baseSpeed     = 35,
        .baseSpAttack  = 40,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 50 : 40,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 64 : 87,
        .evYield_Defense = 1,
        .itemRare = ITEM_THICK_CLUB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_LIGHTNING_ROD, ABILITY_BATTLE_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Cubone"),
        .cryId = CRY_CUBONE,
        .natDexNum = NATIONAL_DEX_CUBONE,
        .categoryName = _("Lonely"),
        .height = 4,
        .weight = 65,
        .description = COMPOUND_STRING(
            "It pines for the mother it will never see\n"
            "again. Seeing a likeness of its mother in\n"
            "the full moon, it cries. The stains on the\n"
            "skull it wears are from its tears."),
        .pokemonScale = 545,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cubone,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_LOOP(1),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL : ANIM_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = P_GBA_STYLE_SPECIES_GFX ? 0 : 30,
        .backPic = gMonBackPic_Cubone,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Cubone,
        .shinyPalette = gMonShinyPalette_Cubone,
        .iconSprite = gMonIcon_Cubone,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Cubone)
        OVERWORLD(
            sPicTable_Cubone,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Cubone,
            gShinyOverworldPalette_Cubone
        )
        .levelUpLearnset = sCuboneLevelUpLearnset,
        .teachableLearnset = sCuboneTeachableLearnset,
        .eggMoveLearnset = sCuboneEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_MAROWAK, CONDITIONS({IF_NOT_REGION, REGION_ALOLA})}
                            #if P_ALOLAN_FORMS
                                ,{EVO_LEVEL, 28, SPECIES_MAROWAK_ALOLA, CONDITIONS({IF_REGION, REGION_ALOLA}, {IF_TIME, TIME_NIGHT})},
                                {EVO_NONE, 0, SPECIES_MAROWAK_ALOLA_TOTEM}
                            #endif
                            ),
    },

    [SPECIES_MAROWAK] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 80 : 50,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 149 : 124,
        .evYield_Defense = 2,
        .itemRare = ITEM_THICK_CLUB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_LIGHTNING_ROD, ABILITY_BATTLE_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Marowak"),
        .cryId = CRY_MAROWAK,
        .natDexNum = NATIONAL_DEX_MAROWAK,
        .categoryName = _("Bone Keeper"),
        .height = 10,
        .weight = 450,
        .description = COMPOUND_STRING(
            "A Marowak is the evolved form of a Cubone\n"
            "that has grown tough by overcoming the\n"
            "grief of losing its mother. Its tempered\n"
            "and hardened spirit is not easily broken."),
        .pokemonScale = 293,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Marowak,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .backPic = gMonBackPic_Marowak,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Marowak,
        .shinyPalette = gMonShinyPalette_Marowak,
        .iconSprite = gMonIcon_Marowak,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 6, SHADOW_SIZE_M)
        FOOTPRINT(Marowak)
        OVERWORLD(
            sPicTable_Marowak,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Marowak,
            gShinyOverworldPalette_Marowak
        )
        .levelUpLearnset = sMarowakLevelUpLearnset,
        .teachableLearnset = sMarowakTeachableLearnset,
        .formSpeciesIdTable = sMarowakFormSpeciesIdTable,
    },

#if P_ALOLAN_FORMS
    [SPECIES_MAROWAK_ALOLA] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 75,
        .expYield = 149,
        .evYield_Defense = 2,
        .itemRare = ITEM_THICK_CLUB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_CURSED_BODY, ABILITY_LIGHTNING_ROD, ABILITY_ROCK_HEAD },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
        .speciesName = _("Marowak"),
        .cryId = CRY_MAROWAK,
        .natDexNum = NATIONAL_DEX_MAROWAK,
        .categoryName = _("Bone Keeper"),
        .height = 10,
        .weight = 340,
        .description = gMarowakAlolaPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MarowakAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_MarowakAlola,
        .frontAnimId = ANIM_CONCAVE_ARC_SMALL_TWICE,
        .backPic = gMonBackPic_MarowakAlola,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MarowakAlola,
        .shinyPalette = gMonShinyPalette_MarowakAlola,
        .iconSprite = gMonIcon_MarowakAlola,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 11, SHADOW_SIZE_M)
        FOOTPRINT(Marowak)
        OVERWORLD(
            sPicTable_MarowakAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_MarowakAlola,
            gShinyOverworldPalette_MarowakAlola
        )
        .isAlolanForm = TRUE,
        .levelUpLearnset = sMarowakAlolaLevelUpLearnset,
        .teachableLearnset = sMarowakAlolaTeachableLearnset,
        .formSpeciesIdTable = sMarowakFormSpeciesIdTable,
    },

    [SPECIES_MAROWAK_ALOLA_TOTEM] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 75,
        .expYield = 149,
        .evYield_Defense = 2,
        .itemRare = ITEM_THICK_CLUB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Marowak"),
        .cryId = CRY_MAROWAK,
        .natDexNum = NATIONAL_DEX_MAROWAK,
        .categoryName = _("Bone Keeper"),
        .height = 17,
        .weight = 980,
        .description = gMarowakAlolaPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MarowakAlola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_MarowakAlola,
        .frontAnimId = ANIM_CONCAVE_ARC_SMALL_TWICE,
        .backPic = gMonBackPic_MarowakAlola,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MarowakAlola,
        .shinyPalette = gMonShinyPalette_MarowakAlola,
        .iconSprite = gMonIcon_MarowakAlola,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 11, SHADOW_SIZE_M)
        FOOTPRINT(Marowak)
        OVERWORLD(
            sPicTable_MarowakAlola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MarowakAlola,
            gShinyOverworldPalette_MarowakAlola
        )
        .isTotem = TRUE,
        .isAlolanForm = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMarowakAlolaLevelUpLearnset,
        .teachableLearnset = sMarowakAlolaTeachableLearnset,
        .formSpeciesIdTable = sMarowakFormSpeciesIdTable,
    },
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_CUBONE

#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
    [SPECIES_TYROGUE] =
    {
        .baseHP        = 35,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 42 : 91,
        .evYield_Attack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_GUTS, ABILITY_STEADFAST, ABILITY_VITAL_SPIRIT },
    #else
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_VITAL_SPIRIT },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Tyrogue"),
        .cryId = CRY_TYROGUE,
        .natDexNum = NATIONAL_DEX_TYROGUE,
        .categoryName = _("Scuffle"),
        .height = 7,
        .weight = 210,
        .description = COMPOUND_STRING(
            "Tyrogue become stressed out if they do\n"
            "not get to train every day. When raising\n"
            "this Pokémon, the Trainer must establish\n"
            "a regular training schedule."),
        .pokemonScale = 292,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tyrogue,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_STRETCH : ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Tyrogue,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Tyrogue,
        .shinyPalette = gMonShinyPalette_Tyrogue,
        .iconSprite = gMonIcon_Tyrogue,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 4, SHADOW_SIZE_S)
        FOOTPRINT(Tyrogue)
        OVERWORLD(
            sPicTable_Tyrogue,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tyrogue,
            gShinyOverworldPalette_Tyrogue
        )
        .levelUpLearnset = sTyrogueLevelUpLearnset,
        .teachableLearnset = sTyrogueTeachableLearnset,
        .eggMoveLearnset = sTyrogueEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_HITMONCHAN, CONDITIONS({IF_ATK_LT_DEF})},
                                {EVO_LEVEL, 20, SPECIES_HITMONLEE, CONDITIONS({IF_ATK_GT_DEF})},
                                {EVO_LEVEL, 20, SPECIES_HITMONTOP, CONDITIONS({IF_ATK_EQ_DEF})}),
    },
#endif //P_GEN_2_CROSS_EVOS

    [SPECIES_HITMONLEE] =
    {
        .baseHP        = 50,
        .baseAttack    = 120,
        .baseDefense   = 53,
        .baseSpeed     = 87,
        .baseSpAttack  = 35,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 110 : 35,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 139,
        .evYield_Attack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_LIMBER, ABILITY_RECKLESS, ABILITY_UNBURDEN },
    #else
        .abilities = { ABILITY_LIMBER, ABILITY_NONE, ABILITY_UNBURDEN },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hitmonlee"),
        .cryId = CRY_HITMONLEE,
        .natDexNum = NATIONAL_DEX_HITMONLEE,
        .categoryName = _("Kicking"),
        .height = 15,
        .weight = 498,
        .description = COMPOUND_STRING(
            "Its legs freely stretch and contract.\n"
            "Using these springlike limbs, it bowls over\n"
            "foes with devastating kicks. After battle,\n"
            "it rubs down its tired legs."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 259,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Hitmonlee,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_STRETCH : ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Hitmonlee,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 4,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Hitmonlee,
        .shinyPalette = gMonShinyPalette_Hitmonlee,
        .iconSprite = gMonIcon_Hitmonlee,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Hitmonlee)
        OVERWORLD(
            sPicTable_Hitmonlee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hitmonlee,
            gShinyOverworldPalette_Hitmonlee
        )
        .levelUpLearnset = sHitmonleeLevelUpLearnset,
        .teachableLearnset = sHitmonleeTeachableLearnset,
    },

    [SPECIES_HITMONCHAN] =
    {
        .baseHP        = 50,
        .baseAttack    = 105,
        .baseDefense   = 79,
        .baseSpeed     = 76,
        .baseSpAttack  = 35,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 110 : 35,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 140,
        .evYield_SpDefense = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_KEEN_EYE, ABILITY_IRON_FIST, ABILITY_INNER_FOCUS },
    #else
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_INNER_FOCUS },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hitmonchan"),
        .cryId = CRY_HITMONCHAN,
        .natDexNum = NATIONAL_DEX_HITMONCHAN,
        .categoryName = _("Punching"),
        .height = 14,
        .weight = 502,
        .description = COMPOUND_STRING(
            "A Hitmonchan is said to possess the\n"
            "spirit of a boxer who aimed to become the\n"
            "world champion. Having an indomitable\n"
            "spirit means that it will never give up."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 277,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Hitmonchan,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 17),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Hitmonchan,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Hitmonchan,
        .shinyPalette = gMonShinyPalette_Hitmonchan,
        .iconSprite = gMonIcon_Hitmonchan,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Hitmonchan)
        OVERWORLD(
            sPicTable_Hitmonchan,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hitmonchan,
            gShinyOverworldPalette_Hitmonchan
        )
        .levelUpLearnset = sHitmonchanLevelUpLearnset,
        .teachableLearnset = sHitmonchanTeachableLearnset,
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_HITMONTOP] =
    {
        .baseHP        = 50,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 70,
        .baseSpAttack  = 35,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 138,
        .evYield_SpDefense = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INTIMIDATE, ABILITY_TECHNICIAN, ABILITY_STEADFAST },
    #else
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_STEADFAST },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hitmontop"),
        .cryId = CRY_HITMONTOP,
        .natDexNum = NATIONAL_DEX_HITMONTOP,
        .categoryName = _("Handstand"),
        .height = 14,
        .weight = 480,
        .description = COMPOUND_STRING(
            "Its technique of kicking while spinning is\n"
            "a remarkable mix of both offense and\n"
            "defense. Hitmontop travel faster\n"
            "spinning than they do walking."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hitmontop,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 26),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_VIBRATE : ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Hitmontop,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        .palette = gMonPalette_Hitmontop,
        .shinyPalette = gMonShinyPalette_Hitmontop,
        .iconSprite = gMonIcon_Hitmontop,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Hitmontop)
        OVERWORLD(
            sPicTable_Hitmontop,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hitmontop,
            gShinyOverworldPalette_Hitmontop
        )
        .levelUpLearnset = sHitmontopLevelUpLearnset,
        .teachableLearnset = sHitmontopTeachableLearnset,
    },
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_HITMONS

#if P_FAMILY_LICKITUNG
    [SPECIES_LICKITUNG] =
    {
        .baseHP        = 90,
        .baseAttack    = 55,
        .baseDefense   = 75,
        .baseSpeed     = 30,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 75 : 60,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 77 : 127,
        .evYield_HP = 2,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_OBLIVIOUS, ABILITY_CLOUD_NINE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Lickitung"),
        .cryId = CRY_LICKITUNG,
        .natDexNum = NATIONAL_DEX_LICKITUNG,
        .categoryName = _("Licking"),
        .height = 12,
        .weight = 655,
        .description = COMPOUND_STRING(
            "Whenever it sees something unfamiliar,\n"
            "it always licks the object because it\n"
            "memorizes things by texture and taste.\n"
            "It is somewhat put off by sour things."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lickitung,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE_SLOW : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Lickitung,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Lickitung,
        .shinyPalette = gMonShinyPalette_Lickitung,
        .iconSprite = gMonIcon_Lickitung,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 6, SHADOW_SIZE_M)
        FOOTPRINT(Lickitung)
        OVERWORLD(
            sPicTable_Lickitung,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lickitung,
            gShinyOverworldPalette_Lickitung
        )
        .levelUpLearnset = sLickitungLevelUpLearnset,
        .teachableLearnset = sLickitungTeachableLearnset,
        .eggMoveLearnset = sLickitungEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_LICKILICKY, CONDITIONS({IF_KNOWS_MOVE, MOVE_ROLLOUT})}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_LICKILICKY] =
    {
        .baseHP        = 110,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 50,
        .baseSpAttack  = 80,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 180 : 193,
        .evYield_HP = 3,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_OBLIVIOUS, ABILITY_CLOUD_NINE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Lickilicky"),
        .cryId = CRY_LICKILICKY,
        .natDexNum = NATIONAL_DEX_LICKILICKY,
        .categoryName = _("Licking"),
        .height = 17,
        .weight = 1400,
        .description = COMPOUND_STRING(
            "The long tongue is always soggy with\n"
            "slobber. The saliva contains a solvent\n"
            "that causes numbness. Getting too close\n"
            "to it will leave you soaked with drool."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Lickilicky,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 50),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Lickilicky,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Lickilicky,
        .shinyPalette = gMonShinyPalette_Lickilicky,
        .iconSprite = gMonIcon_Lickilicky,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_M)
        FOOTPRINT(Lickilicky)
        OVERWORLD(
            sPicTable_Lickilicky,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lickilicky,
            gShinyOverworldPalette_Lickilicky
        )
        .levelUpLearnset = sLickilickyLevelUpLearnset,
        .teachableLearnset = sLickilickyTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_LICKITUNG

#if P_FAMILY_KOFFING
    [SPECIES_KOFFING] =
    {
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 95,
        .baseSpeed     = 35,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 45 : 60,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 68 : 114,
        .evYield_Defense = 1,
        .itemRare = ITEM_SMOKE_BALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_8
        .abilities = { ABILITY_LEVITATE, ABILITY_NEUTRALIZING_GAS, ABILITY_STENCH },
    #else
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Koffing"),
        .cryId = CRY_KOFFING,
        .natDexNum = NATIONAL_DEX_KOFFING,
        .categoryName = _("Poison Gas"),
        .height = 6,
        .weight = 10,
        .description = COMPOUND_STRING(
            "Getting up close to a Koffing will give\n"
            "you a chance to observe, through its thin\n"
            "skin, the toxic gases swirling inside. It\n"
            "blows up at the slightest stimulation."),
        .pokemonScale = 369,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Koffing,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SHRINK_GROW : ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 14,
        .backPic = gMonBackPic_Koffing,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 3,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Koffing,
        .shinyPalette = gMonShinyPalette_Koffing,
        .iconSprite = gMonIcon_Koffing,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_S)
        FOOTPRINT(Koffing)
        OVERWORLD(
            sPicTable_Koffing,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Koffing,
            gShinyOverworldPalette_Koffing
        )
        .levelUpLearnset = sKoffingLevelUpLearnset,
        .teachableLearnset = sKoffingTeachableLearnset,
        .eggMoveLearnset = sKoffingEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_WEEZING, CONDITIONS({IF_NOT_REGION, REGION_GALAR})}
                            #if P_GALARIAN_FORMS
                                ,{EVO_LEVEL, 35, SPECIES_WEEZING_GALAR, CONDITIONS({IF_REGION, REGION_GALAR})}
                            #endif
                            ),
    },

    [SPECIES_WEEZING] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 120,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 70 : 85,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 173,
        .evYield_Defense = 2,
        .itemRare = ITEM_SMOKE_BALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_8
        .abilities = { ABILITY_LEVITATE, ABILITY_NEUTRALIZING_GAS, ABILITY_STENCH },
    #else
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
        .speciesName = _("Weezing"),
        .cryId = CRY_WEEZING,
        .natDexNum = NATIONAL_DEX_WEEZING,
        .categoryName = _("Poison Gas"),
        .height = 12,
        .weight = 95,
        .description = COMPOUND_STRING(
            "By diluting its toxic gases with a special\n"
            "process, the highest grade of perfume can\n"
            "be extracted. To Weezing, gases emanating\n"
            "from garbage are the ultimate feast."),
        .pokemonScale = 305,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Weezing,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 3,
        .backPic = gMonBackPic_Weezing,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 9,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Weezing,
        .shinyPalette = gMonShinyPalette_Weezing,
        .iconSprite = gMonIcon_Weezing,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 14, SHADOW_SIZE_M)
        FOOTPRINT(Weezing)
        OVERWORLD(
            sPicTable_Weezing,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following_Asym,
            gOverworldPalette_Weezing,
            gShinyOverworldPalette_Weezing
        )
        .levelUpLearnset = sWeezingLevelUpLearnset,
        .teachableLearnset = sWeezingTeachableLearnset,
        .formSpeciesIdTable = sWeezingFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_WEEZING_GALAR] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 120,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_POISON, TYPE_FAIRY),
        .catchRate = 60,
        .expYield = 172,
        .evYield_Defense = 2,
        .itemRare = ITEM_MISTY_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NEUTRALIZING_GAS, ABILITY_MISTY_SURGE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Weezing"),
        .cryId = CRY_WEEZING,
        .natDexNum = NATIONAL_DEX_WEEZING,
        .categoryName = _("Poison Gas"),
        .height = 30,
        .weight = 160,
        .description = COMPOUND_STRING(
            "Long ago, when droves of factories fouled\n"
            "the air with pollution, it changed into this\n"
            "form for some reason. It consumes air\n"
            "pollutant particles, expelling clean air."),
        .pokemonScale = 305,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_WeezingGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_WeezingGalar,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_WeezingGalar,
        .shinyPalette = gMonShinyPalette_WeezingGalar,
        .iconSprite = gMonIcon_WeezingGalar,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 17, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Weezing)
        OVERWORLD(
            sPicTable_WeezingGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_WeezingGalar,
            gShinyOverworldPalette_WeezingGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sWeezingGalarLevelUpLearnset,
        .teachableLearnset = sWeezingGalarTeachableLearnset,
        .formSpeciesIdTable = sWeezingFormSpeciesIdTable,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_KOFFING

#if P_FAMILY_RHYHORN
    [SPECIES_RHYHORN] =
    {
        .baseHP        = 80,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 25,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_GROUND, TYPE_ROCK),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 69 : 135,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_ROCK_HEAD, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Rhyhorn"),
        .cryId = CRY_RHYHORN,
        .natDexNum = NATIONAL_DEX_RHYHORN,
        .categoryName = _("Spikes"),
        .height = 10,
        .weight = 1150,
        .description = COMPOUND_STRING(
            "Once it starts running, it doesn't stop.\n"
            "Its tiny brain makes it so stupid that it\n"
            "can't remember why it started running in\n"
            "the first place."),
        .pokemonScale = 267,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rhyhorn,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Rhyhorn,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Rhyhorn,
        .shinyPalette = gMonShinyPalette_Rhyhorn,
        .iconSprite = gMonIcon_Rhyhorn,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_RhyhornF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 40),
        .backPicFemale = gMonBackPic_RhyhornF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 0, SHADOW_SIZE_L)
        FOOTPRINT(Rhyhorn)
        OVERWORLD(
            sPicTable_Rhyhorn,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rhyhorn,
            gShinyOverworldPalette_Rhyhorn
        )
        OVERWORLD_FEMALE(
            sPicTable_RhyhornF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sRhyhornLevelUpLearnset,
        .teachableLearnset = sRhyhornTeachableLearnset,
        .eggMoveLearnset = sRhyhornEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_RHYDON}),
    },

    [SPECIES_RHYDON] =
    {
        .baseHP        = 105,
        .baseAttack    = 130,
        .baseDefense   = 120,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GROUND, TYPE_ROCK),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 170 : 204,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_ROCK_HEAD, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Rhydon"),
        .cryId = CRY_RHYDON,
        .natDexNum = NATIONAL_DEX_RHYDON,
        .categoryName = _("Drill"),
        .height = 19,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "Its horn, which rotates like a drill,\n"
            "destroys tall buildings with one strike.\n"
            "It stands on its hind legs, and its brain\n"
            "is well developed."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 299,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Rhydon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SHRINK_GROW : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Rhydon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 5,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Rhydon,
        .shinyPalette = gMonShinyPalette_Rhydon,
        .iconSprite = gMonIcon_Rhydon,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_RhydonF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_RhydonF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Rhydon)
        OVERWORLD(
            sPicTable_Rhydon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rhydon,
            gShinyOverworldPalette_Rhydon
        )
        OVERWORLD_FEMALE(
            sPicTable_RhydonF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sRhydonLevelUpLearnset,
        .teachableLearnset = sRhydonTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_RHYPERIOR, CONDITIONS({IF_HOLD_ITEM, ITEM_PROTECTOR})},
                                {EVO_ITEM, ITEM_PROTECTOR, SPECIES_RHYPERIOR}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_RHYPERIOR] =
    {
        .baseHP        = 115,
        .baseAttack    = 140,
        .baseDefense   = 130,
        .baseSpeed     = 40,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GROUND, TYPE_ROCK),
        .catchRate = 30,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 268,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 241,
    #else
        .expYield = 217,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_SOLID_ROCK, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Rhyperior"),
        .cryId = CRY_RHYPERIOR,
        .natDexNum = NATIONAL_DEX_RHYPERIOR,
        .categoryName = _("Drill"),
        .height = 24,
        .weight = 2828,
        .description = COMPOUND_STRING(
            "It can launch a rock held in its hand\n"
            "like a missile by tightening and then\n"
            "expanding its muscles instantaneously.\n"
            "Geodude are shot at rare times."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Rhyperior,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 50),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Rhyperior,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Rhyperior,
        .shinyPalette = gMonShinyPalette_Rhyperior,
        .iconSprite = gMonIcon_Rhyperior,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_RhyperiorF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_RhyperiorF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Rhyperior)
        OVERWORLD(
            sPicTable_Rhyperior,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rhyperior,
            gShinyOverworldPalette_Rhyperior
        )
        OVERWORLD_FEMALE(
            sPicTable_RhyperiorF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sRhyperiorLevelUpLearnset,
        .teachableLearnset = sRhyperiorTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_RHYHORN

#if P_FAMILY_CHANSEY
#if P_GEN_4_CROSS_EVOS
    [SPECIES_HAPPINY] =
    {
        .baseHP        = 100,
        .baseAttack    = 5,
        .baseDefense   = 5,
        .baseSpeed     = 30,
        .baseSpAttack  = 15,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 130,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 110 : 255,
        .evYield_HP = 1,
        .itemRare = ITEM_OVAL_STONE,
        .genderRatio = MON_FEMALE,
        .eggCycles = 40,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_SERENE_GRACE, ABILITY_FRIEND_GUARD },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Happiny"),
        .cryId = CRY_HAPPINY,
        .natDexNum = NATIONAL_DEX_HAPPINY,
        .categoryName = _("Playhouse"),
        .height = 6,
        .weight = 244,
        .description = COMPOUND_STRING(
            "It carries a round white rock in its\n"
            "belly pouch. If it gets along well with\n"
            "someone, it will sometimes give that\n"
            "person the rock."),
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Happiny,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Happiny,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Happiny,
        .shinyPalette = gMonShinyPalette_Happiny,
        .iconSprite = gMonIcon_Happiny,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Happiny)
        OVERWORLD(
            sPicTable_Happiny,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Happiny,
            gShinyOverworldPalette_Happiny
        )
        .levelUpLearnset = sHappinyLevelUpLearnset,
        .teachableLearnset = sHappinyTeachableLearnset,
        .eggMoveLearnset = sHappinyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_CHANSEY, CONDITIONS({IF_NOT_TIME, TIME_NIGHT},{IF_HOLD_ITEM, ITEM_OVAL_STONE})},
                                {EVO_ITEM, ITEM_OVAL_STONE, SPECIES_CHANSEY, CONDITIONS({IF_NOT_TIME, TIME_NIGHT})}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_CHANSEY] =
    {
        .baseHP        = 250,
        .baseAttack    = 5,
        .baseDefense   = 5,
        .baseSpeed     = 50,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 35 : 105,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 395 : 255,
        .evYield_HP = 2,
        .itemCommon = ITEM_OVAL_STONE,
        .genderRatio = MON_FEMALE,
        .eggCycles = 40,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_SERENE_GRACE, ABILITY_HEALER },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Chansey"),
        .cryId = CRY_CHANSEY,
        .natDexNum = NATIONAL_DEX_CHANSEY,
        .categoryName = _("Egg"),
        .height = 11,
        .weight = 346,
        .description = COMPOUND_STRING(
            "Chansey lay nutritionally excellent eggs\n"
            "every day. The eggs are so delicious, they\n"
            "are eagerly devoured by even those people\n"
            "who have lost their appetite."),
        .pokemonScale = 257,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chansey,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE_SLOW : ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Chansey,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Chansey,
        .shinyPalette = gMonShinyPalette_Chansey,
        .iconSprite = gMonIcon_Chansey,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 4, SHADOW_SIZE_L)
        FOOTPRINT(Chansey)
        OVERWORLD(
            sPicTable_Chansey,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Chansey,
            gShinyOverworldPalette_Chansey
        )
        .levelUpLearnset = sChanseyLevelUpLearnset,
        .teachableLearnset = sChanseyTeachableLearnset,
        .eggMoveLearnset = sChanseyEggMoveLearnset,
    #if P_GEN_2_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_BLISSEY, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    #endif
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_BLISSEY] =
    {
        .baseHP        = 255,
        .baseAttack    = 10,
        .baseDefense   = 10,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 30,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 635,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 608,
    #else
        .expYield = 255,
    #endif
        .evYield_HP = (P_UPDATED_EVS >= GEN_4) ? 3 : 2,
        .itemCommon = ITEM_OVAL_STONE,
        .genderRatio = MON_FEMALE,
        .eggCycles = 40,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_SERENE_GRACE, ABILITY_HEALER },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Blissey"),
        .cryId = CRY_BLISSEY,
        .natDexNum = NATIONAL_DEX_BLISSEY,
        .categoryName = _("Happiness"),
        .height = 15,
        .weight = 468,
        .description = COMPOUND_STRING(
            "If it senses sadness with its fluffy fur,\n"
            "a Blissey will rush over to the sad person,\n"
            "however far away, to share an egg of\n"
            "happiness that brings a smile to any face."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 310,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Blissey,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Blissey,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 16,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Blissey,
        .shinyPalette = gMonShinyPalette_Blissey,
        .iconSprite = gMonIcon_Blissey,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 8, SHADOW_SIZE_L)
        FOOTPRINT(Blissey)
        OVERWORLD(
            sPicTable_Blissey,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Blissey,
            gShinyOverworldPalette_Blissey
        )
        .levelUpLearnset = sBlisseyLevelUpLearnset,
        .teachableLearnset = sBlisseyTeachableLearnset,
    },
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_CHANSEY

#if P_FAMILY_TANGELA
    [SPECIES_TANGELA] =
    {
        .baseHP        = 65,
        .baseAttack    = 55,
        .baseDefense   = 115,
        .baseSpeed     = 60,
        .baseSpAttack  = 100,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 40 : 100,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 87 : 166,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_REGENERATOR },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_REGENERATOR },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Tangela"),
        .cryId = CRY_TANGELA,
        .natDexNum = NATIONAL_DEX_TANGELA,
        .categoryName = _("Vine"),
        .height = 10,
        .weight = 350,
        .description = COMPOUND_STRING(
            "Its vines snap off easily and painlessly\n"
            "if they are grabbed, allowing it to make a\n"
            "quick getaway. The lost vines are replaced\n"
            "by new growth the very next day."),
        .pokemonScale = 304,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tangela,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 40),
            ANIMCMD_FRAME(1, 24),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL : ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Tangela,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Tangela,
        .shinyPalette = gMonShinyPalette_Tangela,
        .iconSprite = gMonIcon_Tangela,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 1, SHADOW_SIZE_M)
        FOOTPRINT(Tangela)
        OVERWORLD(
            sPicTable_Tangela,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tangela,
            gShinyOverworldPalette_Tangela
        )
        .levelUpLearnset = sTangelaLevelUpLearnset,
        .teachableLearnset = sTangelaTeachableLearnset,
        .eggMoveLearnset = sTangelaEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_TANGROWTH, CONDITIONS({IF_KNOWS_MOVE, MOVE_ANCIENT_POWER})}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_TANGROWTH] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 125,
        .baseSpeed     = 50,
        .baseSpAttack  = 110,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 187 : 211,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Tangrowth"),
        .cryId = CRY_TANGROWTH,
        .natDexNum = NATIONAL_DEX_TANGROWTH,
        .categoryName = _("Vine"),
        .height = 20,
        .weight = 1286,
        .description = COMPOUND_STRING(
            "It ensnares prey by extending arms made\n"
            "of vines. Even if one of its arms is eaten,\n"
            "it's fine. The Pokémon regenerates quickly\n"
            "and will go right back to normal."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Tangrowth,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Tangrowth,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Tangrowth,
        .shinyPalette = gMonShinyPalette_Tangrowth,
        .iconSprite = gMonIcon_Tangrowth,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_TangrowthF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Tangrowth)
        OVERWORLD(
            sPicTable_Tangrowth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tangrowth,
            gShinyOverworldPalette_Tangrowth
        )
        OVERWORLD_FEMALE(
            sPicTable_TangrowthF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sTangrowthLevelUpLearnset,
        .teachableLearnset = sTangrowthTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_TANGELA

#if P_FAMILY_KANGASKHAN
    [SPECIES_KANGASKHAN] =
    {
        .baseHP        = 105,
        .baseAttack    = 95,
        .baseDefense   = 80,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 80 : 40,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 175,
        .evYield_HP = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_EARLY_BIRD, ABILITY_SCRAPPY, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kangaskhan"),
        .cryId = CRY_KANGASKHAN,
        .natDexNum = NATIONAL_DEX_KANGASKHAN,
        .categoryName = _("Parent"),
        .height = 22,
        .weight = 800,
        .description = COMPOUND_STRING(
            "If you come across a young Kangaskhan\n"
            "playing by itself, never try to catch it.\n"
            "The baby's parent is sure to be in the area,\n"
            "and it will become violently enraged."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Kangaskhan,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Kangaskhan,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Kangaskhan,
        .shinyPalette = gMonShinyPalette_Kangaskhan,
        .iconSprite = gMonIcon_Kangaskhan,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kangaskhan)
        OVERWORLD(
            sPicTable_Kangaskhan,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kangaskhan,
            gShinyOverworldPalette_Kangaskhan
        )
        .levelUpLearnset = sKangaskhanLevelUpLearnset,
        .teachableLearnset = sKangaskhanTeachableLearnset,
        .eggMoveLearnset = sKangaskhanEggMoveLearnset,
        .formSpeciesIdTable = sKangaskhanFormSpeciesIdTable,
        .formChangeTable = sKangaskhanFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_KANGASKHAN_MEGA] =
    {
        .baseHP        = 105,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 60,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 207,
        .evYield_HP = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_PARENTAL_BOND, ABILITY_PARENTAL_BOND, ABILITY_PARENTAL_BOND },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kangaskhan"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_KANGASKHAN_MEGA,
    #else
        .cryId = CRY_KANGASKHAN,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_KANGASKHAN,
        .categoryName = _("Parent"),
        .height = 22,
        .weight = 1000,
        .description = COMPOUND_STRING(
            "When the mother sees the back of her\n"
            "Mega-Evolved child, it makes her think\n"
            "of the day when her child will inevitably\n"
            "leave her."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_KangaskhanMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_KangaskhanMega,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_KangaskhanMega,
        .shinyPalette = gMonShinyPalette_KangaskhanMega,
        .iconSprite = gMonIcon_KangaskhanMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kangaskhan)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_KangaskhanMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_KangaskhanMega,
            gShinyOverworldPalette_KangaskhanMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sKangaskhanLevelUpLearnset,
        .teachableLearnset = sKangaskhanTeachableLearnset,
        .eggMoveLearnset = sKangaskhanEggMoveLearnset,
        .formSpeciesIdTable = sKangaskhanFormSpeciesIdTable,
        .formChangeTable = sKangaskhanFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_KANGASKHAN

#if P_FAMILY_HORSEA
    [SPECIES_HORSEA] =
    {
        .baseHP        = 30,
        .baseAttack    = 40,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 25 : 70,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 59 : 83,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_DRAGON_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_SNIPER, ABILITY_DAMP },
    #else
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_DAMP },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Horsea"),
        .cryId = CRY_HORSEA,
        .natDexNum = NATIONAL_DEX_HORSEA,
        .categoryName = _("Dragon"),
        .height = 4,
        .weight = 80,
        .description = COMPOUND_STRING(
            "By cleverly flicking the fins on its back\n"
            "side to side, it moves in any direction\n"
            "while facing forward. It spits ink to\n"
            "escape if it senses danger."),
        .pokemonScale = 399,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Horsea,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_TWIST : ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Horsea,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 14,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Horsea,
        .shinyPalette = gMonShinyPalette_Horsea,
        .iconSprite = gMonIcon_Horsea,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Horsea)
        OVERWORLD(
            sPicTable_Horsea,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Horsea,
            gShinyOverworldPalette_Horsea
        )
        .levelUpLearnset = sHorseaLevelUpLearnset,
        .teachableLearnset = sHorseaTeachableLearnset,
        .eggMoveLearnset = sHorseaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_SEADRA}),
    },

    [SPECIES_SEADRA] =
    {
        .baseHP        = 55,
        .baseAttack    = 65,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 45 : 95,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 154 : 155,
        .evYield_Defense = 1,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_DRAGON_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_POISON_POINT, ABILITY_SNIPER, ABILITY_DAMP },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_NONE, ABILITY_DAMP },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Seadra"),
        .cryId = CRY_SEADRA,
        .natDexNum = NATIONAL_DEX_SEADRA,
        .categoryName = _("Dragon"),
        .height = 12,
        .weight = 250,
        .description = COMPOUND_STRING(
            "The poisonous barbs all over its body are\n"
            "highly valued as ingredients for making\n"
            "traditional herbal medicine. It shows no\n"
            "mercy to anything approaching its nest."),
        .pokemonScale = 299,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Seadra,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Seadra,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Seadra,
        .shinyPalette = gMonShinyPalette_Seadra,
        .iconSprite = gMonIcon_Seadra,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 7, SHADOW_SIZE_M)
        FOOTPRINT(Seadra)
        OVERWORLD(
            sPicTable_Seadra,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Seadra,
            gShinyOverworldPalette_Seadra
        )
        .levelUpLearnset = sSeadraLevelUpLearnset,
        .teachableLearnset = sSeadraTeachableLearnset,
    #if P_GEN_2_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_KINGDRA, CONDITIONS({IF_HOLD_ITEM, ITEM_DRAGON_SCALE})},
                                {EVO_ITEM, ITEM_DRAGON_SCALE, SPECIES_KINGDRA}),
    #endif
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_KINGDRA] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 270,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 243,
    #else
        .expYield = 207,
    #endif
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_DRAGON_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_SNIPER, ABILITY_DAMP },
    #else
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_DAMP },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Kingdra"),
        .cryId = CRY_KINGDRA,
        .natDexNum = NATIONAL_DEX_KINGDRA,
        .categoryName = _("Dragon"),
        .height = 18,
        .weight = 1520,
        .description = COMPOUND_STRING(
            "It sleeps quietly, deep on the seafloor.\n"
            "When it comes up to the surface, it\n"
            "creates a huge whirlpool that can swallow\n"
            "even ships."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 287,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kingdra,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_CIRCLE_INTO_BG,
        .backPic = gMonBackPic_Kingdra,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Kingdra,
        .shinyPalette = gMonShinyPalette_Kingdra,
        .iconSprite = gMonIcon_Kingdra,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 12, SHADOW_SIZE_M)
        FOOTPRINT(Kingdra)
        OVERWORLD(
            sPicTable_Kingdra,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Kingdra,
            gShinyOverworldPalette_Kingdra
        )
        .levelUpLearnset = sKingdraLevelUpLearnset,
        .teachableLearnset = sKingdraTeachableLearnset,
    },
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_HORSEA

#if P_FAMILY_GOLDEEN
    [SPECIES_GOLDEEN] =
    {
        .baseHP        = 45,
        .baseAttack    = 67,
        .baseDefense   = 60,
        .baseSpeed     = 63,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 35 : 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 64 : 111,
        .evYield_Attack = 1,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_WATER_VEIL, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Goldeen"),
        .cryId = CRY_GOLDEEN,
        .natDexNum = NATIONAL_DEX_GOLDEEN,
        .categoryName = _("Goldfish"),
        .height = 6,
        .weight = 150,
        .description = COMPOUND_STRING(
            "In the springtime, schools of Goldeen\n"
            "can be seen swimming up falls and rivers.\n"
            "It metes out staggering damage with its\n"
            "single horn."),
        .pokemonScale = 379,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Goldeen,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONVEX : ANIM_H_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Goldeen,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Goldeen,
        .shinyPalette = gMonShinyPalette_Goldeen,
        .iconSprite = gMonIcon_Goldeen,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GoldeenF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 40),
        .backPicFemale = gMonBackPic_GoldeenF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 0, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Goldeen)
        OVERWORLD(
            sPicTable_Goldeen,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Goldeen,
            gShinyOverworldPalette_Goldeen
        )
        OVERWORLD_FEMALE(
            sPicTable_GoldeenF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGoldeenLevelUpLearnset,
        .teachableLearnset = sGoldeenTeachableLearnset,
        .eggMoveLearnset = sGoldeenEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_SEAKING}),
    },

    [SPECIES_SEAKING] =
    {
        .baseHP        = 80,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 68,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 65 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 158 : 170,
        .evYield_Attack = 2,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_WATER_VEIL, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Seaking"),
        .cryId = CRY_SEAKING,
        .natDexNum = NATIONAL_DEX_SEAKING,
        .categoryName = _("Goldfish"),
        .height = 13,
        .weight = 390,
        .description = COMPOUND_STRING(
            "It punches holes in boulders on stream-\n"
            "beds. This is a clever innovation that\n"
            "prevents its eggs from being attacked or\n"
            "washed away by the current."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Seaking,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Seaking,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Seaking,
        .shinyPalette = gMonShinyPalette_Seaking,
        .iconSprite = gMonIcon_Seaking,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SeakingF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_SeakingF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Seaking)
        OVERWORLD(
            sPicTable_Seaking,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Seaking,
            gShinyOverworldPalette_Seaking
        )
        OVERWORLD_FEMALE(
            sPicTable_SeakingF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sSeakingLevelUpLearnset,
        .teachableLearnset = sSeakingTeachableLearnset,
    },
#endif //P_FAMILY_GOLDEEN

#if P_FAMILY_STARYU
    [SPECIES_STARYU] =
    {
        .baseHP        = 30,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 70,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 55 : 70,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 68 : 106,
        .evYield_Speed = 1,
        .itemCommon = ITEM_STARDUST,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_ILLUMINATE, ABILITY_NATURAL_CURE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Staryu"),
        .cryId = CRY_STARYU,
        .natDexNum = NATIONAL_DEX_STARYU,
        .categoryName = _("Star Shape"),
        .height = 8,
        .weight = 345,
        .description = COMPOUND_STRING(
            "It gathers with others in the night and\n"
            "makes its red core glow on and off with\n"
            "the twinkling stars. It can regenerate\n"
            "limbs if they are severed from its body."),
        .pokemonScale = 326,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Staryu,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_TWIST_TWICE,
        .backPic = gMonBackPic_Staryu,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 6,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Staryu,
        .shinyPalette = gMonShinyPalette_Staryu,
        .iconSprite = gMonIcon_Staryu,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Staryu)
        OVERWORLD(
            sPicTable_Staryu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Staryu,
            gShinyOverworldPalette_Staryu
        )
        .levelUpLearnset = sStaryuLevelUpLearnset,
        .teachableLearnset = sStaryuTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_WATER_STONE, SPECIES_STARMIE}),
    },

    [SPECIES_STARMIE] =
    {
        .baseHP        = 60,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 115,
        .baseSpAttack  = 100,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 85 : 100,
        .types = MON_TYPES(TYPE_WATER, TYPE_PSYCHIC),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 182 : 207,
        .evYield_Speed = 2,
        .itemCommon = ITEM_STARDUST,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_ILLUMINATE, ABILITY_NATURAL_CURE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Starmie"),
        .cryId = CRY_STARMIE,
        .natDexNum = NATIONAL_DEX_STARMIE,
        .categoryName = _("Mysterious"),
        .height = 11,
        .weight = 800,
        .description = COMPOUND_STRING(
            "People in ancient times imagined that\n"
            "Starmie were transformed from the\n"
            "reflections of stars that twinkled on\n"
            "gentle waves at night."),
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Starmie,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_TWIST,
        .backPic = gMonBackPic_Starmie,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 4,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Starmie,
        .shinyPalette = gMonShinyPalette_Starmie,
        .iconSprite = gMonIcon_Starmie,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_L)
        FOOTPRINT(Starmie)
        OVERWORLD(
            sPicTable_Starmie,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Starmie,
            gShinyOverworldPalette_Starmie
        )
        .levelUpLearnset = sStarmieLevelUpLearnset,
        .teachableLearnset = sStarmieTeachableLearnset,
        .formSpeciesIdTable = sStarmieFormSpeciesIdTable,
        .formChangeTable = sStarmieFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_STARMIE_MEGA] =
    {
        .baseHP        = 60,
        .baseAttack    = 100,
        .baseDefense   = 105,
        .baseSpeed     = 120,
        .baseSpAttack  = 130,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_WATER, TYPE_PSYCHIC),
        .catchRate = 60,
        .expYield = 182,
        .evYield_Speed = 2,
        .itemCommon = ITEM_STARDUST,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_HUGE_POWER, ABILITY_HUGE_POWER, ABILITY_HUGE_POWER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Starmie"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_STARMIE_MEGA,
    #else
        .cryId = CRY_STARMIE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_STARMIE,
        .categoryName = _("Mysterious"),
        .height = 23,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Its movements have become more\n"
            "humanlike. Whether it's simply\n"
            "trying to communicate or wants to\n"
            "supplant humanity is unclear."),
        .frontPic = gMonFrontPic_StarmieMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_StarmieMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_StarmieMega,
        .shinyPalette = gMonShinyPalette_StarmieMega,
        .iconSprite = gMonIcon_StarmieMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Starmie)
        SHADOW(0, 15, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sStarmieLevelUpLearnset,
        .teachableLearnset = sStarmieTeachableLearnset,
        .formSpeciesIdTable = sStarmieFormSpeciesIdTable,
        .formChangeTable = sStarmieFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_STARYU

#if P_FAMILY_MR_MIME
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MIME_JR] =
    {
        .baseHP        = 20,
        .baseAttack    = 25,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 90,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_PSYCHIC),
    #endif
        .catchRate = 145,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 78,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_FILTER, ABILITY_TECHNICIAN },
    #else
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_NONE, ABILITY_TECHNICIAN },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Mime Jr."),
        .cryId = CRY_MIME_JR,
        .natDexNum = NATIONAL_DEX_MIME_JR,
        .categoryName = _("Mime"),
        .height = 6,
        .weight = 130,
        .description = COMPOUND_STRING(
            "In an attempt to confuse its enemy,\n"
            "it mimics the enemy's movements.\n"
            "Once mimicked, the foe cannot take\n"
            "its eyes off this Pokémon."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MimeJr,
        .frontPicSize = MON_COORDS_SIZE(32, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_MimeJr,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_MimeJr,
        .shinyPalette = gMonShinyPalette_MimeJr,
        .iconSprite = gMonIcon_MimeJr,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-5, 4, SHADOW_SIZE_S)
        FOOTPRINT(MimeJr)
        OVERWORLD(
            sPicTable_MimeJr,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MimeJr,
            gShinyOverworldPalette_MimeJr
        )
        .levelUpLearnset = sMimeJrLevelUpLearnset,
        .teachableLearnset = sMimeJrTeachableLearnset,
        .eggMoveLearnset = sMimeJrEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_MR_MIME, CONDITIONS({IF_KNOWS_MOVE, MOVE_MIMIC}, {IF_NOT_REGION, REGION_GALAR})}
                            #if P_GALARIAN_FORMS
                                ,{EVO_LEVEL, 0, SPECIES_MR_MIME_GALAR, CONDITIONS({IF_KNOWS_MOVE, MOVE_MIMIC}, {IF_REGION, REGION_GALAR})}
                            #endif
                            ),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_MR_MIME] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 65,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 120 : 100,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_PSYCHIC),
    #endif
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 161 : 136,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_FILTER, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Mr. Mime"),
        .cryId = CRY_MR_MIME,
        .natDexNum = NATIONAL_DEX_MR_MIME,
        .categoryName = _("Barrier"),
        .height = 13,
        .weight = 545,
        .description = COMPOUND_STRING(
            "A Mr. Mime is a master of pantomime. It can\n"
            "convince others that something unseeable\n"
            "actually exists. Once believed, the\n"
            "imaginary object does become real."),
        .pokemonScale = 258,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MrMime,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_MrMime,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_MrMime,
        .shinyPalette = gMonShinyPalette_MrMime,
        .iconSprite = gMonIcon_MrMime,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 7, SHADOW_SIZE_M)
        FOOTPRINT(MrMime)
        OVERWORLD(
            sPicTable_MrMime,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MrMime,
            gShinyOverworldPalette_MrMime
        )
        .levelUpLearnset = sMrMimeLevelUpLearnset,
        .teachableLearnset = sMrMimeTeachableLearnset,
        .eggMoveLearnset = sMrMimeEggMoveLearnset,
        .formSpeciesIdTable = sMrMimeFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_MR_MIME_GALAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 90,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ICE, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 161,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_SCREEN_CLEANER, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Mr. Mime"),
        .cryId = CRY_MR_MIME,
        .natDexNum = NATIONAL_DEX_MR_MIME,
        .categoryName = _("Dancing"),
        .height = 14,
        .weight = 568,
        .description = COMPOUND_STRING(
            "Its talent is tap-dancing. It can radiate\n"
            "chilliness from the bottoms of its feet to\n"
            "to create a floor of ice, which this\n"
            "Pokémon can kick up to use as a barrier."),
        .pokemonScale = 258,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MrMimeGalar,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MrMimeGalar,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MrMimeGalar,
        .shinyPalette = gMonShinyPalette_MrMimeGalar,
        .iconSprite = gMonIcon_MrMimeGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_M)
        FOOTPRINT(MrMime)
        OVERWORLD(
            sPicTable_MrMimeGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MrMimeGalar,
            gShinyOverworldPalette_MrMimeGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sMrMimeGalarLevelUpLearnset,
        .teachableLearnset = sMrMimeGalarTeachableLearnset,
        .eggMoveLearnset = sMrMimeGalarEggMoveLearnset,
        .formSpeciesIdTable = sMrMimeFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_MR_RIME}),
    },

    [SPECIES_MR_RIME] =
    {
        .baseHP        = 80,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 70,
        .baseSpAttack  = 110,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_ICE, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 182,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_TANGLED_FEET, ABILITY_SCREEN_CLEANER, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
        .speciesName = _("Mr. Rime"),
        .cryId = CRY_MR_RIME,
        .natDexNum = NATIONAL_DEX_MR_RIME,
        .categoryName = _("Comedian"),
        .height = 15,
        .weight = 582,
        .description = COMPOUND_STRING(
            "It's highly skilled at tap-dancing. It\n"
            "waves its cane of ice in time with its\n"
            "graceful movements."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MrRime,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MrRime,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MrRime,
        .shinyPalette = gMonShinyPalette_MrRime,
        .iconSprite = gMonIcon_MrRime,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 9, SHADOW_SIZE_L)
        FOOTPRINT(MrRime)
        OVERWORLD(
            sPicTable_MrRime,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MrRime,
            gShinyOverworldPalette_MrRime
        )
        .levelUpLearnset = sMrRimeLevelUpLearnset,
        .teachableLearnset = sMrRimeTeachableLearnset,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_MR_MIME

#if P_FAMILY_SCYTHER
    [SPECIES_SCYTHER] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 80,
        .baseSpeed     = 105,
        .baseSpAttack  = 55,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 80 : 55,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 100 : 187,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SWARM, ABILITY_TECHNICIAN, ABILITY_STEADFAST },
    #else
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_STEADFAST },
    #endif
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Scyther"),
        .cryId = CRY_SCYTHER,
        .natDexNum = NATIONAL_DEX_SCYTHER,
        .categoryName = _("Mantis"),
        .height = 15,
        .weight = 560,
        .description = COMPOUND_STRING(
            "Its blindingly fast speed adds to the\n"
            "sharpness of its twin forearm scythes.\n"
            "The scythes can slice through thick logs\n"
            "in one wicked stroke."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 293,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Scyther,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Scyther,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 3,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Scyther,
        .shinyPalette = gMonShinyPalette_Scyther,
        .iconSprite = gMonIcon_Scyther,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_ScytherF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_L)
        FOOTPRINT(Scyther)
        OVERWORLD(
            sPicTable_Scyther,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Scyther,
            gShinyOverworldPalette_Scyther
        )
        OVERWORLD_FEMALE(
            sPicTable_ScytherF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sScytherLevelUpLearnset,
        .teachableLearnset = sScytherTeachableLearnset,
        .eggMoveLearnset = sScytherEggMoveLearnset,
    #if P_GEN_2_CROSS_EVOS || P_GEN_8_CROSS_EVOS
        .evolutions = EVOLUTION(
                            #if P_GEN_2_CROSS_EVOS
                                {EVO_TRADE, 0, SPECIES_SCIZOR, CONDITIONS({IF_HOLD_ITEM, ITEM_METAL_COAT})},
                                {EVO_ITEM, ITEM_METAL_COAT, SPECIES_SCIZOR}
                            #if P_GEN_8_CROSS_EVOS
                                ,
                            #endif
                            #endif
                            #if P_GEN_8_CROSS_EVOS
                                {EVO_ITEM, ITEM_BLACK_AUGURITE, SPECIES_KLEAVOR}
                            #endif
                            ),
    #endif
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_SCIZOR] =
    {
        .baseHP        = 70,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_STEEL),
        .catchRate = 25,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 200,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SWARM, ABILITY_TECHNICIAN, ABILITY_LIGHT_METAL },
    #else
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_LIGHT_METAL },
    #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Scizor"),
        .cryId = CRY_SCIZOR,
        .natDexNum = NATIONAL_DEX_SCIZOR,
        .categoryName = _("Pincer"),
        .height = 18,
        .weight = 1180,
        .description = COMPOUND_STRING(
            "A Scizor has a body with the hardness of\n"
            "steel. It is not easily fazed by ordinary\n"
            "sorts of attacks. It flaps its wings to\n"
            "regulate its body temperature."),
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Scizor,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .frontAnimDelay = 19,
        .backPic = gMonBackPic_Scizor,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Scizor,
        .shinyPalette = gMonShinyPalette_Scizor,
        .iconSprite = gMonIcon_Scizor,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_ScizorF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Scizor)
        OVERWORLD(
            sPicTable_Scizor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Scizor,
            gShinyOverworldPalette_Scizor
        )
        OVERWORLD_FEMALE(
            sPicTable_ScizorF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sScizorLevelUpLearnset,
        .teachableLearnset = sScizorTeachableLearnset,
        .formSpeciesIdTable = sScizorFormSpeciesIdTable,
        .formChangeTable = sScizorFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_SCIZOR_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 150,
        .baseDefense   = 140,
        .baseSpeed     = 75,
        .baseSpAttack  = 65,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_BUG, TYPE_STEEL),
        .catchRate = 25,
        .expYield = 210,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_TECHNICIAN, ABILITY_TECHNICIAN, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Scizor"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SCIZOR_MEGA,
    #else
        .cryId = CRY_SCIZOR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SCIZOR,
        .categoryName = _("Pincer"),
        .height = 20,
        .weight = 1250,
        .description = COMPOUND_STRING(
            "The excess energy that bathes this\n"
            "Pokémon keeps it in constant danger of\n"
            "overflow. It can't sustain a battle over\n"
            "long periods of time."),
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ScizorMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ScizorMega,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_ScizorMega,
        .shinyPalette = gMonShinyPalette_ScizorMega,
        .iconSprite = gMonIcon_ScizorMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 15, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Scizor)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_ScizorMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ScizorMega,
            gShinyOverworldPalette_ScizorMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sScizorLevelUpLearnset,
        .teachableLearnset = sScizorTeachableLearnset,
        .formSpeciesIdTable = sScizorFormSpeciesIdTable,
        .formChangeTable = sScizorFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_GEN_2_CROSS_EVOS

#if P_GEN_8_CROSS_EVOS
    [SPECIES_KLEAVOR] =
    {
        .baseHP        = 70,
        .baseAttack    = 135,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 45,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_BUG, TYPE_ROCK),
        .catchRate = 15,
        .expYield = 175,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_SHEER_FORCE, ABILITY_SHARPNESS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kleavor"),
        .cryId = CRY_KLEAVOR,
        .natDexNum = NATIONAL_DEX_KLEAVOR,
        .categoryName = _("Axe"),
        .height = 18,
        .weight = 890,
        .description = COMPOUND_STRING(
            "A violent creature that fells trees with\n"
            "its crude axes and shields itself with hard\n"
            "stone. Should one encounter this Pokémon\n"
            "in the wild, one's only recourse is to flee."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Kleavor,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kleavor,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Kleavor,
        .shinyPalette = gMonShinyPalette_Kleavor,
        .iconSprite = gMonIcon_Kleavor,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kleavor)
        OVERWORLD(
            sPicTable_Kleavor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kleavor,
            gShinyOverworldPalette_Kleavor
        )
        .levelUpLearnset = sKleavorLevelUpLearnset,
        .teachableLearnset = sKleavorTeachableLearnset,
    },
#endif //P_GEN_8_CROSS_EVOS
#endif //P_FAMILY_SCYTHER

#if P_FAMILY_JYNX
#if P_GEN_2_CROSS_EVOS
    [SPECIES_SMOOCHUM] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 15,
        .baseSpeed     = 65,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ICE, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 61 : 87,
        .evYield_SpAttack = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_FOREWARN, ABILITY_HYDRATION },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_HYDRATION },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Smoochum"),
        .cryId = CRY_SMOOCHUM,
        .natDexNum = NATIONAL_DEX_SMOOCHUM,
        .categoryName = _("Kiss"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "It actively runs about, but also falls\n"
            "often. Whenever it falls, it will check its\n"
            "reflection on a lake's surface to make\n"
            "sure its face hasn't become dirty."),
        .pokemonScale = 440,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Smoochum,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(24, 40) : MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .frontAnimDelay = 40,
        .backPic = gMonBackPic_Smoochum,
        .backPicSize = MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Smoochum,
        .shinyPalette = gMonShinyPalette_Smoochum,
        .iconSprite = gMonIcon_Smoochum,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Smoochum)
        OVERWORLD(
            sPicTable_Smoochum,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Smoochum,
            gShinyOverworldPalette_Smoochum
        )
        .levelUpLearnset = sSmoochumLevelUpLearnset,
        .teachableLearnset = sSmoochumTeachableLearnset,
        .eggMoveLearnset = sSmoochumEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_JYNX}),
    },
#endif //P_GEN_2_CROSS_EVOS

    [SPECIES_JYNX] =
    {
        .baseHP        = 65,
        .baseAttack    = 50,
        .baseDefense   = 35,
        .baseSpeed     = 95,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 115 : 95,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_ICE, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 137,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_FOREWARN, ABILITY_DRY_SKIN },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_DRY_SKIN },
    #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Jynx"),
        .cryId = CRY_JYNX,
        .natDexNum = NATIONAL_DEX_JYNX,
        .categoryName = _("Human Shape"),
        .height = 14,
        .weight = 406,
        .description = COMPOUND_STRING(
            "A Jynx sashays rhythmically as if it were\n"
            "dancing. Its motions are so bouncingly\n"
            "alluring, people seeing it are compelled to\n"
            "shake their hips without noticing."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 300,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Jynx,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Jynx,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 3,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Jynx,
        .shinyPalette = gMonShinyPalette_Jynx,
        .iconSprite = gMonIcon_Jynx,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_L)
        FOOTPRINT(Jynx)
        OVERWORLD(
            sPicTable_Jynx,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Jynx,
            gShinyOverworldPalette_Jynx
        )
        .levelUpLearnset = sJynxLevelUpLearnset,
        .teachableLearnset = sJynxTeachableLearnset,
    },
#endif //P_FAMILY_JYNX

#if P_FAMILY_ELECTABUZZ
#if P_GEN_2_CROSS_EVOS
    [SPECIES_ELEKID] =
    {
        .baseHP        = 45,
        .baseAttack    = 63,
        .baseDefense   = 37,
        .baseSpeed     = 95,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 72 : 106,
        .evYield_Speed = 1,
        .itemRare = ITEM_ELECTIRIZER,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_VITAL_SPIRIT },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Elekid"),
        .cryId = CRY_ELEKID,
        .natDexNum = NATIONAL_DEX_ELEKID,
        .categoryName = _("Electric"),
        .height = 6,
        .weight = 235,
        .description = COMPOUND_STRING(
            "If it touches metal and discharges the\n"
            "electricity it has stored in its body, an\n"
            "Elekid begins swinging its arms in circles\n"
            "to recharge itself."),
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Elekid,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_FLASH_YELLOW,
        .backPic = gMonBackPic_Elekid,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Elekid,
        .shinyPalette = gMonShinyPalette_Elekid,
        .iconSprite = gMonIcon_Elekid,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-1, 1, SHADOW_SIZE_M)
        FOOTPRINT(Elekid)
        OVERWORLD(
            sPicTable_Elekid,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Elekid,
            gShinyOverworldPalette_Elekid
        )
        .levelUpLearnset = sElekidLevelUpLearnset,
        .teachableLearnset = sElekidTeachableLearnset,
        .eggMoveLearnset = sElekidEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ELECTABUZZ}),
    },
#endif //P_GEN_2_CROSS_EVOS

    [SPECIES_ELECTABUZZ] =
    {
        .baseHP        = 65,
        .baseAttack    = 83,
        .baseDefense   = 57,
        .baseSpeed     = 105,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 95 : 85,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 156,
        .evYield_Speed = 2,
        .itemRare = ITEM_ELECTIRIZER,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_VITAL_SPIRIT },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .speciesName = _("Electabuzz"),
        .cryId = CRY_ELECTABUZZ,
        .natDexNum = NATIONAL_DEX_ELECTABUZZ,
        .categoryName = _("Electric"),
        .height = 11,
        .weight = 300,
        .description = COMPOUND_STRING(
            "When a storm approaches, it competes with\n"
            "others to scale heights that are likely to\n"
            "be stricken by lightning. Some towns use\n"
            "Electabuzz in place of lightning rods."),
        .pokemonScale = 351,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Electabuzz,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_FLASH_YELLOW : ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        .backPic = gMonBackPic_Electabuzz,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 4,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Electabuzz,
        .shinyPalette = gMonShinyPalette_Electabuzz,
        .iconSprite = gMonIcon_Electabuzz,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 9, SHADOW_SIZE_L)
        FOOTPRINT(Electabuzz)
        OVERWORLD(
            sPicTable_Electabuzz,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Electabuzz,
            gShinyOverworldPalette_Electabuzz
        )
        .levelUpLearnset = sElectabuzzLevelUpLearnset,
        .teachableLearnset = sElectabuzzTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_ELECTIVIRE, CONDITIONS({IF_HOLD_ITEM, ITEM_ELECTIRIZER})},
                                {EVO_ITEM, ITEM_ELECTIRIZER, SPECIES_ELECTIVIRE}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_ELECTIVIRE] =
    {
        .baseHP        = 75,
        .baseAttack    = 123,
        .baseDefense   = 67,
        .baseSpeed     = 95,
        .baseSpAttack  = 95,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 30,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 270,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 243,
    #else
        .expYield = 199,
    #endif
        .evYield_Attack = 3,
        .itemRare = ITEM_ELECTIRIZER,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_MOTOR_DRIVE, ABILITY_NONE, ABILITY_VITAL_SPIRIT },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Electivire"),
        .cryId = CRY_ELECTIVIRE,
        .natDexNum = NATIONAL_DEX_ELECTIVIRE,
        .categoryName = _("Thunderbolt"),
        .height = 18,
        .weight = 1386,
        .description = COMPOUND_STRING(
            "When it gets excited, it thumps its chest.\n"
            "With every thud, thunder roars, electric\n"
            "sparks shower all around and blue sparks\n"
            "begin to crackle between its horns."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Electivire,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GLOW_YELLOW,
        .backPic = gMonBackPic_Electivire,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Electivire,
        .shinyPalette = gMonShinyPalette_Electivire,
        .iconSprite = gMonIcon_Electivire,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Electivire)
        OVERWORLD(
            sPicTable_Electivire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Electivire,
            gShinyOverworldPalette_Electivire
        )
        .levelUpLearnset = sElectivireLevelUpLearnset,
        .teachableLearnset = sElectivireTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_ELECTABUZZ

#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
    [SPECIES_MAGBY] =
    {
        .baseHP        = 45,
        .baseAttack    = 75,
        .baseDefense   = 37,
        .baseSpeed     = 83,
        .baseSpAttack  = 70,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 73 : 117,
        .evYield_Speed = 1,
        .itemRare = ITEM_MAGMARIZER,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_VITAL_SPIRIT },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Magby"),
        .cryId = CRY_MAGBY,
        .natDexNum = NATIONAL_DEX_MAGBY,
        .categoryName = _("Live Coal"),
        .height = 7,
        .weight = 214,
        .description = COMPOUND_STRING(
            "If a Magby is spouting yellow flames from\n"
            "its mouth, it is in good health. When it is\n"
            "fatigued, black smoke will be mixed in with\n"
            "the flames."),
        .pokemonScale = 284,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magby,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Magby,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 10,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Magby,
        .shinyPalette = gMonShinyPalette_Magby,
        .iconSprite = gMonIcon_Magby,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Magby)
        OVERWORLD(
            sPicTable_Magby,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Magby,
            gShinyOverworldPalette_Magby
        )
        .levelUpLearnset = sMagbyLevelUpLearnset,
        .teachableLearnset = sMagbyTeachableLearnset,
        .eggMoveLearnset = sMagbyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_MAGMAR}),
    },
#endif //P_GEN_2_CROSS_EVOS

    [SPECIES_MAGMAR] =
    {
        .baseHP        = 65,
        .baseAttack    = 95,
        .baseDefense   = 57,
        .baseSpeed     = 93,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 100 : 85,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 173 : 167,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_MAGMARIZER,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_VITAL_SPIRIT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Magmar"),
        .cryId = CRY_MAGMAR,
        .natDexNum = NATIONAL_DEX_MAGMAR,
        .categoryName = _("Spitfire"),
        .height = 13,
        .weight = 445,
        .description = COMPOUND_STRING(
            "In battle, it blows out intense flames from\n"
            "all over its body to intimidate its foe.\n"
            "These fiery bursts create heat waves that\n"
            "ignite grass and trees in the area."),
        .pokemonScale = 277,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magmar,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Magmar,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Magmar,
        .shinyPalette = gMonShinyPalette_Magmar,
        .iconSprite = gMonIcon_Magmar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 8, SHADOW_SIZE_L)
        FOOTPRINT(Magmar)
        OVERWORLD(
            sPicTable_Magmar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Magmar,
            gShinyOverworldPalette_Magmar
        )
        .levelUpLearnset = sMagmarLevelUpLearnset,
        .teachableLearnset = sMagmarTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_MAGMORTAR, CONDITIONS({IF_HOLD_ITEM, ITEM_MAGMARIZER})},
                                {EVO_ITEM, ITEM_MAGMARIZER, SPECIES_MAGMORTAR}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAGMORTAR] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 67,
        .baseSpeed     = 83,
        .baseSpAttack  = 125,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 30,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 270,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 243,
    #else
        .expYield = 199,
    #endif
        .evYield_SpAttack = 3,
        .itemRare = ITEM_MAGMARIZER,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_VITAL_SPIRIT },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Magmortar"),
        .cryId = CRY_MAGMORTAR,
        .natDexNum = NATIONAL_DEX_MAGMORTAR,
        .categoryName = _("Blast"),
        .height = 16,
        .weight = 680,
        .description = COMPOUND_STRING(
            "According to what is known, a single pair\n"
            "of male and female Magmortar lives in\n"
            "one volcano. From its arm, it launches\n"
            "fireballs hotter than 3,600ºF."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Magmortar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Magmortar,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Magmortar,
        .shinyPalette = gMonShinyPalette_Magmortar,
        .iconSprite = gMonIcon_Magmortar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Magmortar)
        OVERWORLD(
            sPicTable_Magmortar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Magmortar,
            gShinyOverworldPalette_Magmortar
        )
        .levelUpLearnset = sMagmortarLevelUpLearnset,
        .teachableLearnset = sMagmortarTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MAGMAR

#if P_FAMILY_PINSIR
    [SPECIES_PINSIR] =
    {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 70 : 55,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 200,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_MOLD_BREAKER, ABILITY_MOXIE },
    #else
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_NONE, ABILITY_MOXIE },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pinsir"),
        .cryId = CRY_PINSIR,
        .natDexNum = NATIONAL_DEX_PINSIR,
        .categoryName = _("Stag Beetle"),
        .height = 15,
        .weight = 550,
        .description = COMPOUND_STRING(
            "Their pincers are strong enough to\n"
            "shatter thick logs. Because they dislike\n"
            "cold, Pinsir burrow and sleep under\n"
            "the ground on chilly nights."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pinsir,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_GROW_VIBRATE : ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Pinsir,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Pinsir,
        .shinyPalette = gMonShinyPalette_Pinsir,
        .iconSprite = gMonIcon_Pinsir,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 7, SHADOW_SIZE_L)
        FOOTPRINT(Pinsir)
        OVERWORLD(
            sPicTable_Pinsir,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pinsir,
            gShinyOverworldPalette_Pinsir
        )
        .levelUpLearnset = sPinsirLevelUpLearnset,
        .teachableLearnset = sPinsirTeachableLearnset,
        .eggMoveLearnset = sPinsirEggMoveLearnset,
        .formSpeciesIdTable = sPinsirFormSpeciesIdTable,
        .formChangeTable = sPinsirFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_PINSIR_MEGA] =
    {
        .baseHP        = 65,
        .baseAttack    = 155,
        .baseDefense   = 120,
        .baseSpeed     = 105,
        .baseSpAttack  = 65,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 210,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_AERILATE, ABILITY_AERILATE, ABILITY_AERILATE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pinsir"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_PINSIR_MEGA,
    #else
        .cryId = CRY_PINSIR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_PINSIR,
        .categoryName = _("Stag Beetle"),
        .height = 17,
        .weight = 590,
        .description = COMPOUND_STRING(
            "The influence of Mega Evolution leaves it\n"
            "in a state of constant excitement.\n"
            "It pierces enemies with its two large\n"
            "horns before shredding them."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PinsirMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE,
        .frontAnimDelay = 40,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_PinsirMega,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_PinsirMega,
        .shinyPalette = gMonShinyPalette_PinsirMega,
        .iconSprite = gMonIcon_PinsirMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 12, SHADOW_SIZE_L)
        FOOTPRINT(Pinsir)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_PinsirMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_PinsirMega,
            gShinyOverworldPalette_PinsirMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sPinsirLevelUpLearnset,
        .teachableLearnset = sPinsirTeachableLearnset,
        .eggMoveLearnset = sPinsirEggMoveLearnset,
        .formSpeciesIdTable = sPinsirFormSpeciesIdTable,
        .formChangeTable = sPinsirFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_PINSIR

#if P_FAMILY_TAUROS
    [SPECIES_TAUROS] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 95,
        .baseSpeed     = 110,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 40 : 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 211,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INTIMIDATE, ABILITY_ANGER_POINT, ABILITY_SHEER_FORCE },
    #else
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_SHEER_FORCE },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Tauros"),
        .cryId = CRY_TAUROS,
        .natDexNum = NATIONAL_DEX_TAUROS,
        .categoryName = _("Wild Bull"),
        .height = 14,
        .weight = 884,
        .description = COMPOUND_STRING(
            "It is not satisfied unless it is rampaging\n"
            "at all times. If there is no opponent for\n"
            "Tauros to battle, it will charge at thick\n"
            "trees and knock them down to calm itself."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tauros,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Tauros,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Tauros,
        .shinyPalette = gMonShinyPalette_Tauros,
        .iconSprite = gMonIcon_Tauros,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Tauros)
        OVERWORLD(
            sPicTable_Tauros,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tauros,
            gShinyOverworldPalette_Tauros
        )
        .levelUpLearnset = sTaurosLevelUpLearnset,
        .teachableLearnset = sTaurosTeachableLearnset,
        .formSpeciesIdTable = sTaurosFormSpeciesIdTable,
    },

#if P_PALDEAN_FORMS
    [SPECIES_TAUROS_PALDEA_COMBAT] =
    {
        .baseHP        = 75,
        .baseAttack    = 110,
        .baseDefense   = 105,
        .baseSpeed     = 100,
        .baseSpAttack  = 30,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_ANGER_POINT, ABILITY_CUD_CHEW },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Tauros"),
        .cryId = CRY_TAUROS,
        .natDexNum = NATIONAL_DEX_TAUROS,
        .categoryName = _("Wild Bull"),
        .height = 14,
        .weight = 1150,
        .description = COMPOUND_STRING(
            "This Pokémon has a muscular body\n"
            "and excels at close-quarters combat.\n"
            "It uses its short horns to strike\n"
            "the opponent’s weak spots."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TaurosPaldeaCombat,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_TaurosPaldeaCombat,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_TaurosPaldeaCombat,
        .shinyPalette = gMonShinyPalette_TaurosPaldeaCombat,
        .iconSprite = gMonIcon_TaurosPaldeaCombat,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Tauros)
        OVERWORLD(
            sPicTable_TaurosPaldeaCombat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TaurosPaldeaCombat,
            gShinyOverworldPalette_TaurosPaldeaCombat
        )
        .isPaldeanForm = TRUE,
        .levelUpLearnset = sTaurosPaldeaCombatLevelUpLearnset,
        .teachableLearnset = sTaurosPaldeaCombatTeachableLearnset,
        .eggMoveLearnset = sTaurosPaldeaCombatEggMoveLearnset,
        .formSpeciesIdTable = sTaurosFormSpeciesIdTable,
    },

    [SPECIES_TAUROS_PALDEA_BLAZE] =
    {
        .baseHP        = 75,
        .baseAttack    = 110,
        .baseDefense   = 105,
        .baseSpeed     = 100,
        .baseSpAttack  = 30,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_ANGER_POINT, ABILITY_CUD_CHEW },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Tauros"),
        .cryId = CRY_TAUROS,
        .natDexNum = NATIONAL_DEX_TAUROS,
        .categoryName = _("Wild Bull"),
        .height = 14,
        .weight = 850,
        .description = COMPOUND_STRING(
            "When heated by fire energy, its horns can\n"
            "get hotter than 1,800 degrees Fahrenheit.\n"
            "Those gored by them will suffer\n"
            "both wounds and burns."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TaurosPaldeaBlaze,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_TaurosPaldeaBlaze,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_TaurosPaldeaBlaze,
        .shinyPalette = gMonShinyPalette_TaurosPaldeaBlaze,
        .iconSprite = gMonIcon_TaurosPaldeaBlaze,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Tauros)
        OVERWORLD(
            sPicTable_TaurosPaldeaBlaze,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TaurosPaldeaBlaze,
            gShinyOverworldPalette_TaurosPaldeaBlaze
        )
        .isPaldeanForm = TRUE,
        .levelUpLearnset = sTaurosPaldeaBlazeLevelUpLearnset,
        .teachableLearnset = sTaurosPaldeaBlazeTeachableLearnset,
        .eggMoveLearnset = sTaurosPaldeaBlazeEggMoveLearnset,
        .formSpeciesIdTable = sTaurosFormSpeciesIdTable,
    },

    [SPECIES_TAUROS_PALDEA_AQUA] =
    {
        .baseHP        = 75,
        .baseAttack    = 110,
        .baseDefense   = 105,
        .baseSpeed     = 100,
        .baseSpAttack  = 30,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_WATER),
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_ANGER_POINT, ABILITY_CUD_CHEW },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Tauros"),
        .cryId = CRY_TAUROS,
        .natDexNum = NATIONAL_DEX_TAUROS,
        .categoryName = _("Wild Bull"),
        .height = 14,
        .weight = 1100,
        .description = COMPOUND_STRING(
            "This Pokémon blasts water from holes on\n"
            "the tips of its horns--the high-pressure\n"
            "jets pierce right through\n"
            "Tauros’s enemies."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TaurosPaldeaAqua,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_TaurosPaldeaAqua,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_TaurosPaldeaAqua,
        .shinyPalette = gMonShinyPalette_TaurosPaldeaAqua,
        .iconSprite = gMonIcon_TaurosPaldeaAqua,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Tauros)
        OVERWORLD(
            sPicTable_TaurosPaldeaAqua,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TaurosPaldeaAqua,
            gShinyOverworldPalette_TaurosPaldeaAqua
        )
        .isPaldeanForm = TRUE,
        .levelUpLearnset = sTaurosPaldeaAquaLevelUpLearnset,
        .teachableLearnset = sTaurosPaldeaAquaTeachableLearnset,
        .eggMoveLearnset = sTaurosPaldeaAquaEggMoveLearnset,
        .formSpeciesIdTable = sTaurosFormSpeciesIdTable,
    },
#endif //P_PALDEAN_FORMS
#endif //P_FAMILY_TAUROS

#if P_FAMILY_MAGIKARP
    [SPECIES_MAGIKARP] =
    {
        .baseHP        = 20,
        .baseAttack    = 10,
        .baseDefense   = 55,
        .baseSpeed     = 80,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 15 : 20,
        .baseSpDefense = 20,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 40 : 20,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Magikarp"),
        .cryId = CRY_MAGIKARP,
        .natDexNum = NATIONAL_DEX_MAGIKARP,
        .categoryName = _("Fish"),
        .height = 9,
        .weight = 100,
        .description = COMPOUND_STRING(
            "Its swimming muscles are weak, so it is\n"
            "easily washed away by currents. In places\n"
            "where water pools, you can see many\n"
            "Magikarp deposited there by the flow."),
        .pokemonScale = 310,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magikarp,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .backPic = gMonBackPic_Magikarp,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Magikarp,
        .shinyPalette = gMonShinyPalette_Magikarp,
        .iconSprite = gMonIcon_Magikarp,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_MagikarpF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 56),
        .backPicFemale = gMonBackPic_MagikarpF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_M)
        FOOTPRINT(Magikarp)
        OVERWORLD(
            sPicTable_Magikarp,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Magikarp,
            gShinyOverworldPalette_Magikarp
        )
        OVERWORLD_FEMALE(
            sPicTable_MagikarpF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sMagikarpLevelUpLearnset,
        .teachableLearnset = sMagikarpTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_GYARADOS}),
    },

    [SPECIES_GYARADOS] =
    {
        .baseHP        = 95,
        .baseAttack    = 125,
        .baseDefense   = 79,
        .baseSpeed     = 81,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 60 : 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 189 : 214,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Gyarados"),
        .cryId = CRY_GYARADOS,
        .natDexNum = NATIONAL_DEX_GYARADOS,
        .categoryName = _("Atrocious"),
        .height = 65,
        .weight = 2350,
        .description = COMPOUND_STRING(
            "It is an extremely vicious and violent\n"
            "Pokémon. When humans begin to fight,\n"
            "it will appear and burn everything to the\n"
            "ground with intensely hot flames."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 481,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_Gyarados,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .backPic = gMonBackPic_Gyarados,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 5,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Gyarados,
        .shinyPalette = gMonShinyPalette_Gyarados,
        .iconSprite = gMonIcon_Gyarados,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GyaradosF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_GyaradosF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Gyarados)
        OVERWORLD(
            sPicTable_Gyarados,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Gyarados,
            gShinyOverworldPalette_Gyarados
        )
        OVERWORLD_FEMALE(
            sPicTable_GyaradosF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sGyaradosLevelUpLearnset,
        .teachableLearnset = sGyaradosTeachableLearnset,
        .formSpeciesIdTable = sGyaradosFormSpeciesIdTable,
        .formChangeTable = sGyaradosFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_GYARADOS_MEGA] =
    {
        .baseHP        = 95,
        .baseAttack    = 155,
        .baseDefense   = 109,
        .baseSpeed     = 81,
        .baseSpAttack  = 70,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_WATER, TYPE_DARK),
        .catchRate = 45,
        .expYield = 224,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_MOLD_BREAKER, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Gyarados"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_GYARADOS_MEGA,
    #else
        .cryId = CRY_GYARADOS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_GYARADOS,
        .categoryName = _("Atrocious"),
        .height = 65,
        .weight = 3050,
        .description = COMPOUND_STRING(
            "Although it obeys its instinctive drive to\n"
            "destroy everything within its reach, it\n"
            "will respond to orders from a Trainer it\n"
            "truly trusts."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 481,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_GyaradosMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_STUTTER_SLOW,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_GyaradosMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_GyaradosMega,
        .shinyPalette = gMonShinyPalette_GyaradosMega,
        .iconSprite = gMonIcon_GyaradosMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 17, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Gyarados)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_GyaradosMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_GyaradosMega,
            gShinyOverworldPalette_GyaradosMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sGyaradosLevelUpLearnset,
        .teachableLearnset = sGyaradosTeachableLearnset,
        .formSpeciesIdTable = sGyaradosFormSpeciesIdTable,
        .formChangeTable = sGyaradosFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_MAGIKARP

#if P_FAMILY_LAPRAS
    [SPECIES_LAPRAS] =
    {
        .baseHP        = 130,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 85 : 95,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 187 : 219,
        .evYield_HP = 2,
        .itemCommon = ITEM_MYSTIC_WATER,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_SHELL_ARMOR, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lapras"),
        .cryId = CRY_LAPRAS,
        .natDexNum = NATIONAL_DEX_LAPRAS,
        .categoryName = _("Transport"),
        .height = 25,
        .weight = 2200,
        .description = COMPOUND_STRING(
            "People have driven Lapras almost to the\n"
            "point of extinction. In the evenings,\n"
            "it is said to sing plaintively as it seeks\n"
            "what few others of its kind still remain."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Lapras,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Lapras,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Lapras,
        .shinyPalette = gMonShinyPalette_Lapras,
        .iconSprite = gMonIcon_Lapras,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Lapras)
        OVERWORLD(
            sPicTable_Lapras,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Lapras,
            gShinyOverworldPalette_Lapras
        )
        .levelUpLearnset = sLaprasLevelUpLearnset,
        .teachableLearnset = sLaprasTeachableLearnset,
        .eggMoveLearnset = sLaprasEggMoveLearnset,
        .formSpeciesIdTable = sLaprasFormSpeciesIdTable,
        .formChangeTable = sLaprasFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_LAPRAS_GMAX] =
    {
        .baseHP        = 130,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 85 : 95,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 187 : 219,
        .evYield_HP = 2,
        .itemCommon = ITEM_MYSTIC_WATER,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_SHELL_ARMOR, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lapras"),
        .cryId = CRY_LAPRAS,
        .natDexNum = NATIONAL_DEX_LAPRAS,
        .categoryName = _("Transport"),
        .height = 240,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Over 5,000 people can ride on its\n"
            "shell at once. And it's a very\n"
            "comfortable ride, without the slightest\n"
            "shaking or swaying."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_LaprasGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_LaprasGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_LaprasGmax,
        .shinyPalette = gMonShinyPalette_LaprasGmax,
        .iconSprite = gMonIcon_LaprasGmax,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Lapras)
        .isGigantamax = TRUE,
        .levelUpLearnset = sLaprasLevelUpLearnset,
        .teachableLearnset = sLaprasTeachableLearnset,
        .eggMoveLearnset = sLaprasEggMoveLearnset,
        .formSpeciesIdTable = sLaprasFormSpeciesIdTable,
        .formChangeTable = sLaprasFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_LAPRAS

#if P_FAMILY_DITTO
    [SPECIES_DITTO] =
    {
        .baseHP        = 48,
        .baseAttack    = 48,
        .baseDefense   = 48,
        .baseSpeed     = 48,
        .baseSpAttack  = 48,
        .baseSpDefense = 48,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 35,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 101 : 61,
        .evYield_HP = 1,
        .itemCommon = ITEM_QUICK_POWDER,
        .itemRare = ITEM_METAL_POWDER,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DITTO),
        .abilities = { ABILITY_LIMBER, ABILITY_NONE, ABILITY_IMPOSTER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Ditto"),
        .cryId = CRY_DITTO,
        .natDexNum = NATIONAL_DEX_DITTO,
        .categoryName = _("Transform"),
        .height = 3,
        .weight = 40,
        .description = COMPOUND_STRING(
            "A Ditto rearranges its cell structure to\n"
            "transform itself. However, if it tries to\n"
            "change based on its memory, it will get\n"
            "details wrong."),
        .pokemonScale = 633,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ditto,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Ditto,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Ditto,
        .shinyPalette = gMonShinyPalette_Ditto,
        .iconSprite = gMonIcon_Ditto,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -4, SHADOW_SIZE_M)
        FOOTPRINT(Ditto)
        OVERWORLD(
            sPicTable_Ditto,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Ditto,
            gShinyOverworldPalette_Ditto
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sDittoLevelUpLearnset,
        .teachableLearnset = sDittoTeachableLearnset,
    },
#endif //P_FAMILY_DITTO

#if P_FAMILY_EEVEE
#define EEVEE_SP_ATK (P_UPDATED_STATS >= GEN_2 ? 45 : 65)

#if P_UPDATED_ABILITIES >= GEN_4
    #define EEVEE_ABILITIES { ABILITY_RUN_AWAY, ABILITY_ADAPTABILITY, ABILITY_ANTICIPATION }
#else
    #define EEVEE_ABILITIES { ABILITY_RUN_AWAY, ABILITY_NONE, ABILITY_ANTICIPATION }
#endif

    [SPECIES_EEVEE] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = EEVEE_SP_ATK,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 65 : 92,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = EEVEE_ABILITIES,
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Eevee"),
        .cryId = CRY_EEVEE,
        .natDexNum = NATIONAL_DEX_EEVEE,
        .categoryName = _("Evolution"),
        .height = 3,
        .weight = 65,
        .description = gEeveePokedexText,
        .pokemonScale = 476,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Eevee,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Eevee,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Eevee,
        .shinyPalette = gMonShinyPalette_Eevee,
        .iconSprite = gMonIcon_Eevee,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_EeveeF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_EeveeF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 2, SHADOW_SIZE_S)
        FOOTPRINT(Eevee)
        OVERWORLD(
            sPicTable_Eevee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Eevee,
            gShinyOverworldPalette_Eevee
        )
        OVERWORLD_FEMALE(
            sPicTable_EeveeF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sEeveeLevelUpLearnset,
        .teachableLearnset = sEeveeTeachableLearnset,
        .eggMoveLearnset = sEeveeEggMoveLearnset,
        .formSpeciesIdTable = sEeveeFormSpeciesIdTable,
        .formChangeTable = sEeveeFormChangeTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_JOLTEON},
                                {EVO_ITEM, ITEM_WATER_STONE, SPECIES_VAPOREON},
                                {EVO_ITEM, ITEM_FIRE_STONE, SPECIES_FLAREON}
                            #if P_GEN_6_CROSS_EVOS
                                ,{EVO_LEVEL, 0, SPECIES_SYLVEON, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD}, {IF_KNOWS_MOVE_TYPE, TYPE_FAIRY})}
                            #endif
                            #if P_GEN_2_CROSS_EVOS
                                ,{EVO_LEVEL, 0, SPECIES_ESPEON, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD}, {IF_NOT_TIME, TIME_NIGHT})},
                                {EVO_LEVEL, 0, SPECIES_UMBREON, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD}, {IF_TIME, TIME_NIGHT})}
                            #endif
                            #if P_GEN_4_CROSS_EVOS
                                ,{EVO_LEVEL, 0, SPECIES_LEAFEON, CONDITIONS({IF_IN_MAP, MAP_PETALBURG_WOODS})},
                                {EVO_ITEM, ITEM_LEAF_STONE, SPECIES_LEAFEON},
                                {EVO_LEVEL, 0, SPECIES_GLACEON, CONDITIONS({IF_IN_MAP, MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM})},
                                {EVO_ITEM, ITEM_ICE_STONE, SPECIES_GLACEON}
                            #endif
                            ),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_EEVEE_GMAX] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = EEVEE_SP_ATK,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 65 : 92,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = EEVEE_ABILITIES,
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Eevee"),
        .cryId = CRY_EEVEE,
        .natDexNum = NATIONAL_DEX_EEVEE,
        .categoryName = _("Evolution"),
        .height = 180,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Having gotten even friendlier and\n"
            "more innocent, Eevee tries to play\n"
            "with anyone around, only to end up\n"
            "crushing them with its immense body."),
        .pokemonScale = 476,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_EeveeGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_EeveeGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EeveeGmax,
        .shinyPalette = gMonShinyPalette_EeveeGmax,
        .iconSprite = gMonIcon_EeveeGmax,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, -1, SHADOW_SIZE_L)
        FOOTPRINT(Eevee)
        .isGigantamax = TRUE,
        .levelUpLearnset = sEeveeLevelUpLearnset,
        .teachableLearnset = sEeveeTeachableLearnset,
        .eggMoveLearnset = sEeveeEggMoveLearnset,
        .formSpeciesIdTable = sEeveeFormSpeciesIdTable,
        .formChangeTable = sEeveeFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS

    [SPECIES_EEVEE_STARTER] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 75,
        .baseSpAttack  = 65,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 87,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_ADAPTABILITY, ABILITY_ANTICIPATION },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Eevee"),
        .cryId = CRY_EEVEE,
        .natDexNum = NATIONAL_DEX_EEVEE,
        .categoryName = _("Evolution"),
        .height = 3,
        .weight = 65,
        .description = gEeveePokedexText,
        .pokemonScale = 476,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Eevee,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Eevee,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Eevee,
        .shinyPalette = gMonShinyPalette_Eevee,
        .iconSprite = gMonIcon_EeveePartner,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_EeveeF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_EeveeF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        .iconSpriteFemale = gMonIcon_EeveePartnerF,
        .iconPalIndexFemale = 2,
    #endif
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 2, SHADOW_SIZE_S)
        FOOTPRINT(Eevee)
        OVERWORLD(
            sPicTable_Eevee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Eevee,
            gShinyOverworldPalette_Eevee
        )
        .cannotBeTraded = TRUE,
        .perfectIVCount = NUM_STATS,
        .levelUpLearnset = sEeveeLevelUpLearnset,
        .teachableLearnset = sEeveeTeachableLearnset,
        .eggMoveLearnset = sEeveeEggMoveLearnset,
        .formSpeciesIdTable = sEeveeFormSpeciesIdTable,
    },

    [SPECIES_VAPOREON] =
    {
        .baseHP        = 130,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = 110,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 95 : 110,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 196,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_WATER_ABSORB, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Vaporeon"),
        .cryId = CRY_VAPOREON,
        .natDexNum = NATIONAL_DEX_VAPOREON,
        .categoryName = _("Bubble Jet"),
        .height = 10,
        .weight = 290,
        .description = COMPOUND_STRING(
            "Vaporeon underwent a spontaneous\n"
            "mutation and grew fins and gills that\n"
            "allow them to live underwater. They have\n"
            "the ability to freely control water."),
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vaporeon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_GLOW_BLUE,
        .backPic = gMonBackPic_Vaporeon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 5,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Vaporeon,
        .shinyPalette = gMonShinyPalette_Vaporeon,
        .iconSprite = gMonIcon_Vaporeon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 3, SHADOW_SIZE_M)
        FOOTPRINT(Vaporeon)
        OVERWORLD(
            sPicTable_Vaporeon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vaporeon,
            gShinyOverworldPalette_Vaporeon
        )
        .levelUpLearnset = sVaporeonLevelUpLearnset,
        .teachableLearnset = sVaporeonTeachableLearnset,
    },

    [SPECIES_JOLTEON] =
    {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 130,
        .baseSpAttack  = 110,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 95 : 110,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 197,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_VOLT_ABSORB, ABILITY_QUICK_FEET },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Jolteon"),
        .cryId = CRY_JOLTEON,
        .natDexNum = NATIONAL_DEX_JOLTEON,
        .categoryName = _("Lightning"),
        .height = 8,
        .weight = 245,
        .description = COMPOUND_STRING(
            "Its cells generate weak power that is\n"
            "amplified by its fur's static electricity\n"
            "to drop thunderbolts. The bristling fur is\n"
            "made of electrically charged needles."),
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Jolteon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Jolteon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 7,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Jolteon,
        .shinyPalette = gMonShinyPalette_Jolteon,
        .iconSprite = gMonIcon_Jolteon,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(Jolteon)
        OVERWORLD(
            sPicTable_Jolteon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Jolteon,
            gShinyOverworldPalette_Jolteon
        )
        .levelUpLearnset = sJolteonLevelUpLearnset,
        .teachableLearnset = sJolteonTeachableLearnset,
    },

    [SPECIES_FLAREON] =
    {
        .baseHP        = 65,
        .baseAttack    = 130,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 95 : 110,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 198,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLASH_FIRE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Flareon"),
        .cryId = CRY_FLAREON,
        .natDexNum = NATIONAL_DEX_FLAREON,
        .categoryName = _("Flame"),
        .height = 9,
        .weight = 250,
        .description = COMPOUND_STRING(
            "Flareon's fluffy fur releases heat into\n"
            "the air so that its body does not get\n"
            "excessively hot. Its body temperature can\n"
            "rise to a maximum of 1,650 degrees F."),
        .pokemonScale = 306,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Flareon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_V_SHAKE,
        .backPic = gMonBackPic_Flareon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 9,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Flareon,
        .shinyPalette = gMonShinyPalette_Flareon,
        .iconSprite = gMonIcon_Flareon,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 1, SHADOW_SIZE_L)
        FOOTPRINT(Flareon)
        OVERWORLD(
            sPicTable_Flareon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Flareon,
            gShinyOverworldPalette_Flareon
        )
        .levelUpLearnset = sFlareonLevelUpLearnset,
        .teachableLearnset = sFlareonTeachableLearnset,
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_ESPEON] =
    {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 197,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_SYNCHRONIZE, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Espeon"),
        .cryId = CRY_ESPEON,
        .natDexNum = NATIONAL_DEX_ESPEON,
        .categoryName = _("Sun"),
        .height = 9,
        .weight = 265,
        .description = COMPOUND_STRING(
            "An Espeon is extremely loyal to any\n"
            "Trainer it considers to be worthy. It is\n"
            "said to have developed precognitive\n"
            "powers to protect its Trainer from harm."),
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Espeon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Espeon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Espeon,
        .shinyPalette = gMonShinyPalette_Espeon,
        .iconSprite = gMonIcon_Espeon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 4, SHADOW_SIZE_M)
        FOOTPRINT(Espeon)
        OVERWORLD(
            sPicTable_Espeon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Espeon,
            gShinyOverworldPalette_Espeon
        )
        .levelUpLearnset = sEspeonLevelUpLearnset,
        .teachableLearnset = sEspeonTeachableLearnset,
    },

    [SPECIES_UMBREON] =
    {
        .baseHP        = 95,
        .baseAttack    = 65,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 197,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_SYNCHRONIZE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Umbreon"),
        .cryId = CRY_UMBREON,
        .natDexNum = NATIONAL_DEX_UMBREON,
        .categoryName = _("Moonlight"),
        .height = 10,
        .weight = 270,
        .description = COMPOUND_STRING(
            "Umbreon evolved from exposure to the\n"
            "moon's energy pulses. It lurks in darkness\n"
            "and waits for its foes to move. The rings\n"
            "on its body glow when it leaps to attack."),
        .pokemonScale = 317,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Umbreon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Umbreon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Umbreon,
        .shinyPalette = gMonShinyPalette_Umbreon,
        .iconSprite = gMonIcon_Umbreon,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_M)
        FOOTPRINT(Umbreon)
        OVERWORLD(
            sPicTable_Umbreon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Umbreon,
            gShinyOverworldPalette_Umbreon
        )
        .levelUpLearnset = sUmbreonLevelUpLearnset,
        .teachableLearnset = sUmbreonTeachableLearnset,
    },
#endif //P_GEN_2_CROSS_EVOS

#if P_GEN_4_CROSS_EVOS
    [SPECIES_LEAFEON] =
    {
        .baseHP        = 65,
        .baseAttack    = 110,
        .baseDefense   = 130,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 196,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_LEAF_GUARD, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Leafeon"),
        .cryId = CRY_LEAFEON,
        .natDexNum = NATIONAL_DEX_LEAFEON,
        .categoryName = _("Verdant"),
        .height = 10,
        .weight = 255,
        .description = COMPOUND_STRING(
            "Its cellular composition is closer to\n"
            "that of a plant than an animal. It uses\n"
            "photosynthesis to produce its energy\n"
            "supply without eating food."),
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Leafeon,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Leafeon,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Leafeon,
        .shinyPalette = gMonShinyPalette_Leafeon,
        .iconSprite = gMonIcon_Leafeon,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 4, SHADOW_SIZE_M)
        FOOTPRINT(Leafeon)
        OVERWORLD(
            sPicTable_Leafeon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Leafeon,
            gShinyOverworldPalette_Leafeon
        )
        .levelUpLearnset = sLeafeonLevelUpLearnset,
        .teachableLearnset = sLeafeonTeachableLearnset,
    },

    [SPECIES_GLACEON] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = 130,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 196,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_SNOW_CLOAK, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Glaceon"),
        .cryId = CRY_GLACEON,
        .natDexNum = NATIONAL_DEX_GLACEON,
        .categoryName = _("Fresh Snow"),
        .height = 8,
        .weight = 259,
        .description = COMPOUND_STRING(
            "It can control its body temperature\n"
            "at will. This enables it to freeze the\n"
            "moisture in the atmosphere, creating\n"
            "flurries of diamond dust."),
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Glaceon,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Glaceon,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Glaceon,
        .shinyPalette = gMonShinyPalette_Glaceon,
        .iconSprite = gMonIcon_Glaceon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_M)
        FOOTPRINT(Glaceon)
        OVERWORLD(
            sPicTable_Glaceon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Glaceon,
            gShinyOverworldPalette_Glaceon
        )
        .levelUpLearnset = sGlaceonLevelUpLearnset,
        .teachableLearnset = sGlaceonTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS

#if P_GEN_6_CROSS_EVOS
    [SPECIES_SYLVEON] =
    {
        .baseHP        = 95,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 60,
        .baseSpAttack  = 110,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 184,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_CUTE_CHARM, ABILITY_PIXILATE },
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = TRUE,
        .speciesName = _("Sylveon"),
        .cryId = CRY_SYLVEON,
        .natDexNum = NATIONAL_DEX_SYLVEON,
        .categoryName = _("Intertwine"),
        .height = 10,
        .weight = 235,
        .description = COMPOUND_STRING(
            "Its ribbonlike feelers give off an aura\n"
            "that weakens hostility in its prey, causing\n"
            "them to let down their guard. A moment\n"
            "later, it pounces."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sylveon,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Sylveon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Sylveon,
        .shinyPalette = gMonShinyPalette_Sylveon,
        .iconSprite = gMonIcon_Sylveon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 9, SHADOW_SIZE_M)
        FOOTPRINT(Sylveon)
        OVERWORLD(
            sPicTable_Sylveon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Sylveon,
            gShinyOverworldPalette_Sylveon
        )
        .levelUpLearnset = sSylveonLevelUpLearnset,
        .teachableLearnset = sSylveonTeachableLearnset,
    },
#endif //P_GEN_6_CROSS_EVOS
#endif //P_FAMILY_EEVEE

#if P_FAMILY_PORYGON
    [SPECIES_PORYGON] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 85 : 75,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 79 : 130,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_TRACE, ABILITY_DOWNLOAD, ABILITY_ANALYTIC },
    #else
        .abilities = { ABILITY_TRACE, ABILITY_NONE, ABILITY_ANALYTIC },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Porygon"),
        .cryId = CRY_PORYGON,
        .natDexNum = NATIONAL_DEX_PORYGON,
        .categoryName = _("Virtual"),
        .height = 8,
        .weight = 365,
        .description = COMPOUND_STRING(
            "It is capable of reverting itself entirely\n"
            "back to program data in order to enter\n"
            "cyberspace. A Porygon is copy-\n"
            "protected so it cannot be duplicated."),
        .pokemonScale = 328,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Porygon,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Porygon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Porygon,
        .shinyPalette = gMonShinyPalette_Porygon,
        .iconSprite = gMonIcon_Porygon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, -2, SHADOW_SIZE_S)
        FOOTPRINT(Porygon)
        OVERWORLD(
            sPicTable_Porygon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Porygon,
            gShinyOverworldPalette_Porygon
        )
        .levelUpLearnset = sPorygonLevelUpLearnset,
        .teachableLearnset = sPorygonTeachableLearnset,
    #if P_GEN_2_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_PORYGON2, CONDITIONS({IF_HOLD_ITEM, ITEM_UPGRADE})},
                                {EVO_ITEM, ITEM_UPGRADE, SPECIES_PORYGON2}),
    #endif
    },

#if P_GEN_2_CROSS_EVOS
    [SPECIES_PORYGON2] =
    {
        .baseHP        = 85,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 105,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 180,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_TRACE, ABILITY_DOWNLOAD, ABILITY_ANALYTIC },
    #else
        .abilities = { ABILITY_TRACE, ABILITY_NONE, ABILITY_ANALYTIC },
    #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Porygon2"),
        .cryId = CRY_PORYGON2,
        .natDexNum = NATIONAL_DEX_PORYGON2,
        .categoryName = _("Virtual"),
        .height = 6,
        .weight = 325,
        .description = COMPOUND_STRING(
            "It was created by humans using the power\n"
            "of science. It has been given artificial\n"
            "intelligence that enables it to learn new\n"
            "gestures and emotions on its own."),
        .pokemonScale = 320,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Porygon2,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 0 : 9,
        .backPic = gMonBackPic_Porygon2,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Porygon2,
        .shinyPalette = gMonShinyPalette_Porygon2,
        .iconSprite = gMonIcon_Porygon2,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 5, SHADOW_SIZE_S)
        FOOTPRINT(Porygon2)
        OVERWORLD(
            sPicTable_Porygon2,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Porygon2,
            gShinyOverworldPalette_Porygon2
        )
        .levelUpLearnset = sPorygon2LevelUpLearnset,
        .teachableLearnset = sPorygon2TeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_PORYGON_Z, CONDITIONS({IF_HOLD_ITEM, ITEM_DUBIOUS_DISC})},
                                {EVO_ITEM, ITEM_DUBIOUS_DISC, SPECIES_PORYGON_Z}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_PORYGON_Z] =
    {
        .baseHP        = 85,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 135,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 30,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 268,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 241,
    #else
        .expYield = 185,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_DOWNLOAD, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Porygon-Z"),
        .cryId = CRY_PORYGON_Z,
        .natDexNum = NATIONAL_DEX_PORYGON_Z,
        .categoryName = _("Virtual"),
        .height = 9,
        .weight = 340,
        .description = COMPOUND_STRING(
            "In order to create a more advanced\n"
            "Pokémon, an additional program was\n"
            "installed, but apparently it contained a\n"
            "defect that made it move oddly."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PorygonZ,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 40),
        ),
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .enemyMonElevation = 12,
        .backPic = gMonBackPic_PorygonZ,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_PorygonZ,
        .shinyPalette = gMonShinyPalette_PorygonZ,
        .iconSprite = gMonIcon_PorygonZ,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 17, SHADOW_SIZE_S)
        FOOTPRINT(PorygonZ)
        OVERWORLD(
            sPicTable_PorygonZ,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_PorygonZ,
            gShinyOverworldPalette_PorygonZ
        )
        .levelUpLearnset = sPorygonZLevelUpLearnset,
        .teachableLearnset = sPorygonZTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_PORYGON

#if P_FAMILY_OMANYTE
    [SPECIES_OMANYTE] =
    {
        .baseHP        = 35,
        .baseAttack    = 40,
        .baseDefense   = 100,
        .baseSpeed     = 35,
        .baseSpAttack  = 90,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 55 : 90,
        .types = MON_TYPES(TYPE_ROCK, TYPE_WATER),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 71,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 99,
    #else
        .expYield = 120,
    #endif
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Omanyte"),
        .cryId = CRY_OMANYTE,
        .natDexNum = NATIONAL_DEX_OMANYTE,
        .categoryName = _("Spiral"),
        .height = 4,
        .weight = 75,
        .description = COMPOUND_STRING(
            "One of the ancient and long-since-extinct\n"
            "Pokémon that have been regenerated\n"
            "from fossils by humans. If attacked,\n"
            "it withdraws into its hard shell."),
        .pokemonScale = 521,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Omanyte,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .backPic = gMonBackPic_Omanyte,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Omanyte,
        .shinyPalette = gMonShinyPalette_Omanyte,
        .iconSprite = gMonIcon_Omanyte,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, -2, SHADOW_SIZE_S)
        FOOTPRINT(Omanyte)
        OVERWORLD(
            sPicTable_Omanyte,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Omanyte,
            gShinyOverworldPalette_Omanyte
        )
        .levelUpLearnset = sOmanyteLevelUpLearnset,
        .teachableLearnset = sOmanyteTeachableLearnset,
        .eggMoveLearnset = sOmanyteEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_OMASTAR}),
    },

    [SPECIES_OMASTAR] =
    {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 125,
        .baseSpeed     = 55,
        .baseSpAttack  = 115,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 70 : 115,
        .types = MON_TYPES(TYPE_ROCK, TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 173 : 199,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Omastar"),
        .cryId = CRY_OMASTAR,
        .natDexNum = NATIONAL_DEX_OMASTAR,
        .categoryName = _("Spiral"),
        .height = 10,
        .weight = 350,
        .description = COMPOUND_STRING(
            "An Omastar uses its tentacles to capture\n"
            "its prey. It is believed to have become\n"
            "extinct because its shell grew too large,\n"
            "making its movements slow and ponderous."),
        .pokemonScale = 307,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Omastar,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Omastar,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Omastar,
        .shinyPalette = gMonShinyPalette_Omastar,
        .iconSprite = gMonIcon_Omastar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 4, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Omastar)
        OVERWORLD(
            sPicTable_Omastar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Omastar,
            gShinyOverworldPalette_Omastar
        )
        .levelUpLearnset = sOmastarLevelUpLearnset,
        .teachableLearnset = sOmastarTeachableLearnset,
    },
#endif //P_FAMILY_OMANYTE

#if P_FAMILY_KABUTO
    [SPECIES_KABUTO] =
    {
        .baseHP        = 30,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 55,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 55 : 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ROCK, TYPE_WATER),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 71,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 99,
    #else
        .expYield = 119,
    #endif
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_BATTLE_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kabuto"),
        .cryId = CRY_KABUTO,
        .natDexNum = NATIONAL_DEX_KABUTO,
        .categoryName = _("Shellfish"),
        .height = 5,
        .weight = 115,
        .description = COMPOUND_STRING(
            "It is a Pokémon that has been regenerated\n"
            "from a fossil. However, in rare cases, living\n"
            "examples have been discovered. Kabuto\n"
            "have not changed for 300 million years."),
        .pokemonScale = 454,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kabuto,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Kabuto,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Kabuto,
        .shinyPalette = gMonShinyPalette_Kabuto,
        .iconSprite = gMonIcon_Kabuto,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, -3, SHADOW_SIZE_S)
        FOOTPRINT(Kabuto)
        OVERWORLD(
            sPicTable_Kabuto,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Kabuto,
            gShinyOverworldPalette_Kabuto
        )
        .levelUpLearnset = sKabutoLevelUpLearnset,
        .teachableLearnset = sKabutoTeachableLearnset,
        .eggMoveLearnset = sKabutoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_KABUTOPS}),
    },

    [SPECIES_KABUTOPS] =
    {
        .baseHP        = 60,
        .baseAttack    = 115,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 65 : 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ROCK, TYPE_WATER),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 173,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 199,
    #else
        .expYield = 201,
    #endif
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_BATTLE_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kabutops"),
        .cryId = CRY_KABUTOPS,
        .natDexNum = NATIONAL_DEX_KABUTOPS,
        .categoryName = _("Shellfish"),
        .height = 13,
        .weight = 405,
        .description = COMPOUND_STRING(
            "Kabutops once swam underwater to hunt \n"
            "for prey. It was apparently evolving from\n"
            "being a water dweller to living on land as\n"
            "evident from changes in its gills and legs."),
        .pokemonScale = 271,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kabutops,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Kabutops,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Kabutops,
        .shinyPalette = gMonShinyPalette_Kabutops,
        .iconSprite = gMonIcon_Kabutops,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kabutops)
        OVERWORLD(
            sPicTable_Kabutops,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kabutops,
            gShinyOverworldPalette_Kabutops
        )
        .levelUpLearnset = sKabutopsLevelUpLearnset,
        .teachableLearnset = sKabutopsTeachableLearnset,
    },
#endif //P_FAMILY_KABUTO

#if P_FAMILY_AERODACTYL
    [SPECIES_AERODACTYL] =
    {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 65,
        .baseSpeed     = 130,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 75 : 60,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 180 : 202,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_PRESSURE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Aerodactyl"),
        .cryId = CRY_AERODACTYL,
        .natDexNum = NATIONAL_DEX_AERODACTYL,
        .categoryName = _("Fossil"),
        .height = 18,
        .weight = 590,
        .description = COMPOUND_STRING(
            "Aerodactyl is a Pokémon from the age\n"
            "of dinosaurs. It was regenerated from DNA\n"
            "extracted from amber. It is imagined to\n"
            "have been the king of the skies."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 302,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Aerodactyl,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 25),
        ),
        .frontAnimId = ANIM_V_SLIDE_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 7 : 9,
        .backPic = gMonBackPic_Aerodactyl,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Aerodactyl,
        .shinyPalette = gMonShinyPalette_Aerodactyl,
        .iconSprite = gMonIcon_Aerodactyl,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 16, SHADOW_SIZE_M)
        FOOTPRINT(Aerodactyl)
        OVERWORLD(
            sPicTable_Aerodactyl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Aerodactyl,
            gShinyOverworldPalette_Aerodactyl
        )
        .levelUpLearnset = sAerodactylLevelUpLearnset,
        .teachableLearnset = sAerodactylTeachableLearnset,
        .eggMoveLearnset = sAerodactylEggMoveLearnset,
        .formSpeciesIdTable = sAerodactylFormSpeciesIdTable,
        .formChangeTable = sAerodactylFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_AERODACTYL_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 135,
        .baseDefense   = 85,
        .baseSpeed     = 150,
        .baseSpAttack  = 70,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 215,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_TOUGH_CLAWS, ABILITY_TOUGH_CLAWS },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Aerodactyl"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_AERODACTYL_MEGA,
    #else
        .cryId = CRY_AERODACTYL,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_AERODACTYL,
        .categoryName = _("Fossil"),
        .height = 21,
        .weight = 790,
        .description = COMPOUND_STRING(
            "The power of Mega Evolution has\n"
            "completely restored its genes. The rocks\n"
            "on its body are harder than diamond."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 302,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_AerodactylMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_GROW_STUTTER_SLOW,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_AerodactylMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_AerodactylMega,
        .shinyPalette = gMonShinyPalette_AerodactylMega,
        .iconSprite = gMonIcon_AerodactylMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 18, SHADOW_SIZE_M)
        FOOTPRINT(Aerodactyl)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_AerodactylMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_AerodactylMega,
            gShinyOverworldPalette_AerodactylMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAerodactylLevelUpLearnset,
        .teachableLearnset = sAerodactylTeachableLearnset,
        .eggMoveLearnset = sAerodactylEggMoveLearnset,
        .formSpeciesIdTable = sAerodactylFormSpeciesIdTable,
        .formChangeTable = sAerodactylFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_AERODACTYL

#if P_FAMILY_SNORLAX
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MUNCHLAX] =
    {
        .baseHP        = 135,
        .baseAttack    = 85,
        .baseDefense   = 40,
        .baseSpeed     = 5,
        .baseSpAttack  = 40,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 50,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 78 : 94,
        .evYield_HP = 1,
        .itemCommon = ITEM_LEFTOVERS,
        .itemRare = ITEM_LEFTOVERS,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PICKUP, ABILITY_THICK_FAT, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Munchlax"),
        .cryId = CRY_MUNCHLAX,
        .natDexNum = NATIONAL_DEX_MUNCHLAX,
        .categoryName = _("Big Eater"),
        .height = 6,
        .weight = 1050,
        .description = COMPOUND_STRING(
            "When it finds something that looks like\n"
            "it might be edible, it goes right ahead\n"
            "and swallows it whole. That's why it gets\n"
            "fatter day by day."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Munchlax,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Munchlax,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Munchlax,
        .shinyPalette = gMonShinyPalette_Munchlax,
        .iconSprite = gMonIcon_Munchlax,
        .iconPalIndex = 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Munchlax)
        OVERWORLD(
            sPicTable_Munchlax,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Munchlax,
            gShinyOverworldPalette_Munchlax
        )
        .levelUpLearnset = sMunchlaxLevelUpLearnset,
        .teachableLearnset = sMunchlaxTeachableLearnset,
        .eggMoveLearnset = sMunchlaxEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_SNORLAX, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_SNORLAX] =
    {
        .baseHP        = 160,
        .baseAttack    = 110,
        .baseDefense   = 65,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 110 : 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 25,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 189 : 154,
        .evYield_HP = 2,
        .itemCommon = ITEM_LEFTOVERS,
        .itemRare = ITEM_LEFTOVERS,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_IMMUNITY, ABILITY_THICK_FAT, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Snorlax"),
        .cryId = CRY_SNORLAX,
        .natDexNum = NATIONAL_DEX_SNORLAX,
        .categoryName = _("Sleeping"),
        .height = 21,
        .weight = 4600,
        .description = COMPOUND_STRING(
            "Snorlax's typical day consists of nothing\n"
            "more than eating and sleeping. It is such\n"
            "a docile Pokémon that there are children\n"
            "who use its big belly as a place to play."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 423,
        .trainerOffset = 11,
        .frontPic = gMonFrontPic_Snorlax,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Snorlax,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Snorlax,
        .shinyPalette = gMonShinyPalette_Snorlax,
        .iconSprite = gMonIcon_Snorlax,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Snorlax)
        OVERWORLD(
            sPicTable_Snorlax,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Snorlax,
            gShinyOverworldPalette_Snorlax
        )
        .levelUpLearnset = sSnorlaxLevelUpLearnset,
        .teachableLearnset = sSnorlaxTeachableLearnset,
        .eggMoveLearnset = sSnorlaxEggMoveLearnset,
        .formSpeciesIdTable = sSnorlaxFormSpeciesIdTable,
        .formChangeTable = sSnorlaxFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_SNORLAX_GMAX] =
    {
        .baseHP        = 160,
        .baseAttack    = 110,
        .baseDefense   = 65,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 110 : 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 25,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 189 : 154,
        .evYield_HP = 2,
        .itemCommon = ITEM_LEFTOVERS,
        .itemRare = ITEM_LEFTOVERS,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_IMMUNITY, ABILITY_THICK_FAT, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Snorlax"),
        .cryId = CRY_SNORLAX,
        .natDexNum = NATIONAL_DEX_SNORLAX,
        .categoryName = _("Sleeping"),
        .height = 350,
        .weight = 0,
        .description = COMPOUND_STRING(
            "Gigantamax energy has affected\n"
            "stray seeds and even pebbles that\n"
            "got stuck to Snorlax, making them grow\n"
            "to a huge size."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 423,
        .trainerOffset = 11,
        .frontPic = gMonFrontPic_SnorlaxGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SnorlaxGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SnorlaxGmax,
        .shinyPalette = gMonShinyPalette_SnorlaxGmax,
        .iconSprite = gMonIcon_SnorlaxGmax,
        .iconPalIndex = 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Snorlax)
        .isGigantamax = TRUE,
        .levelUpLearnset = sSnorlaxLevelUpLearnset,
        .teachableLearnset = sSnorlaxTeachableLearnset,
        .eggMoveLearnset = sSnorlaxEggMoveLearnset,
        .formSpeciesIdTable = sSnorlaxFormSpeciesIdTable,
        .formChangeTable = sSnorlaxFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SNORLAX

#if P_FAMILY_ARTICUNO
    [SPECIES_ARTICUNO] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 100,
        .baseSpeed     = 85,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_2 ? 95 : 125,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_ICE, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 215,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_SNOW_CLOAK },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Articuno"),
        .cryId = CRY_ARTICUNO,
        .natDexNum = NATIONAL_DEX_ARTICUNO,
        .categoryName = _("Freeze"),
        .height = 17,
        .weight = 554,
        .description = COMPOUND_STRING(
            "Articuno is a legendary bird Pokémon that\n"
            "can control ice. The flapping of its wings\n"
            "chills the air. As a result, it is said that\n"
            "when this Pokémon flies, snow will fall."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Articuno,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 0,
        .backPic = gMonBackPic_Articuno,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 5,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Articuno,
        .shinyPalette = gMonShinyPalette_Articuno,
        .iconSprite = gMonIcon_Articuno,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 10, SHADOW_SIZE_M)
        FOOTPRINT(Articuno)
        OVERWORLD(
            sPicTable_Articuno,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Articuno,
            gShinyOverworldPalette_Articuno
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sArticunoLevelUpLearnset,
        .teachableLearnset = sArticunoTeachableLearnset,
        .formSpeciesIdTable = sArticunoFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_ARTICUNO_GALAR] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 85,
        .baseSpeed     = 95,
        .baseSpAttack  = 125,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_COMPETITIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Articuno"),
        .cryId = CRY_ARTICUNO,
        .natDexNum = NATIONAL_DEX_ARTICUNO,
        .categoryName = _("Cruel"),
        .height = 17,
        .weight = 509,
        .description = COMPOUND_STRING(
            "It fires beams that immobilize opponents\n"
            "as if they had been frozen solid.\n"
            "Its feather-like blades of psychic energy\n"
            "rip through thick iron sheets like paper."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_ArticunoGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ArticunoGalar,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ArticunoGalar,
        .shinyPalette = gMonShinyPalette_ArticunoGalar,
        .iconSprite = gMonIcon_ArticunoGalar,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 14, SHADOW_SIZE_M)
        FOOTPRINT(Articuno)
        OVERWORLD(
            sPicTable_ArticunoGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ArticunoGalar,
            gShinyOverworldPalette_ArticunoGalar
        )
        .isSubLegendary = TRUE,
        .isGalarianForm = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sArticunoGalarLevelUpLearnset,
        .teachableLearnset = sArticunoGalarTeachableLearnset,
        .formSpeciesIdTable = sArticunoFormSpeciesIdTable,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_ARTICUNO

#if P_FAMILY_ZAPDOS
    [SPECIES_ZAPDOS] =
    {
        .baseHP        = 90,
        .baseAttack    = 90,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 125,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 90 : 125,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 216,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_STATIC },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Zapdos"),
        .cryId = CRY_ZAPDOS,
        .natDexNum = NATIONAL_DEX_ZAPDOS,
        .categoryName = _("Electric"),
        .height = 16,
        .weight = 526,
        .description = COMPOUND_STRING(
            "Zapdos is a legendary bird Pokémon that\n"
            "has the ability to control electricity.\n"
            "It usually lives in thunderclouds. It gains\n"
            "power if it is stricken by lightning bolts."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 318,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Zapdos,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_FLASH_YELLOW,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Zapdos,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 12,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Zapdos,
        .shinyPalette = gMonShinyPalette_Zapdos,
        .iconSprite = gMonIcon_Zapdos,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 15, SHADOW_SIZE_M)
        FOOTPRINT(Zapdos)
        OVERWORLD(
            sPicTable_Zapdos,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Zapdos,
            gShinyOverworldPalette_Zapdos
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZapdosLevelUpLearnset,
        .teachableLearnset = sZapdosTeachableLearnset,
        .formSpeciesIdTable = sZapdosFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_ZAPDOS_GALAR] =
    {
        .baseHP        = 90,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 100,
        .baseSpAttack  = 85,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_FLYING),
        .catchRate = 3,
        .expYield = 290,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DEFIANT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Zapdos"),
        .cryId = CRY_ZAPDOS,
        .natDexNum = NATIONAL_DEX_ZAPDOS,
        .categoryName = _("Strong Legs"),
        .height = 16,
        .weight = 582,
        .description = COMPOUND_STRING(
            "When its feathers rub together, they\n"
            "produce a crackling sound like the\n"
            "zapping of electricity. Apparently, it runs\n"
            "through the mountains at over 180 mph."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 318,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_ZapdosGalar,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZapdosGalar,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZapdosGalar,
        .shinyPalette = gMonShinyPalette_ZapdosGalar,
        .iconSprite = gMonIcon_ZapdosGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Zapdos)
        OVERWORLD(
            sPicTable_ZapdosGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZapdosGalar,
            gShinyOverworldPalette_ZapdosGalar
        )
        .isSubLegendary = TRUE,
        .isGalarianForm = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZapdosGalarLevelUpLearnset,
        .teachableLearnset = sZapdosGalarTeachableLearnset,
        .formSpeciesIdTable = sZapdosFormSpeciesIdTable,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_ZAPDOS

#if P_FAMILY_MOLTRES
    [SPECIES_MOLTRES] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 125,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 85 : 125,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 217,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Moltres"),
        .cryId = CRY_MOLTRES,
        .natDexNum = NATIONAL_DEX_MOLTRES,
        .categoryName = _("Flame"),
        .height = 20,
        .weight = 600,
        .description = COMPOUND_STRING(
            "Moltres is a legendary bird Pokémon\n"
            "that can control fire. If injured, it is said\n"
            "to dip its body in the molten magma of\n"
            "a volcano to burn and heal itself."),
        .pokemonScale = 270,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Moltres,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 5 : 0,
        .backPic = gMonBackPic_Moltres,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Moltres,
        .shinyPalette = gMonShinyPalette_Moltres,
        .iconSprite = gMonIcon_Moltres,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Moltres)
        OVERWORLD(
            sPicTable_Moltres,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Moltres,
            gShinyOverworldPalette_Moltres
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMoltresLevelUpLearnset,
        .teachableLearnset = sMoltresTeachableLearnset,
        .formSpeciesIdTable = sMoltresFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_MOLTRES_GALAR] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_BERSERK, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Moltres"),
        .cryId = CRY_MOLTRES,
        .natDexNum = NATIONAL_DEX_MOLTRES,
        .categoryName = _("Malevolent"),
        .height = 20,
        .weight = 660,
        .description = COMPOUND_STRING(
            "This Pokémon's sinister, flame-like aura\n"
            "will consume the spirit of any creature\n"
            "it hits. Victims become burned-out\n"
            "shadows of themselves."),
        .pokemonScale = 270,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_MoltresGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MoltresGalar,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MoltresGalar,
        .shinyPalette = gMonShinyPalette_MoltresGalar,
        .iconSprite = gMonIcon_MoltresGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_M)
        FOOTPRINT(Moltres)
        OVERWORLD(
            sPicTable_MoltresGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MoltresGalar,
            gShinyOverworldPalette_MoltresGalar
        )
        .isSubLegendary = TRUE,
        .isGalarianForm = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMoltresGalarLevelUpLearnset,
        .teachableLearnset = sMoltresGalarTeachableLearnset,
        .formSpeciesIdTable = sMoltresFormSpeciesIdTable,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_MOLTRES

#if P_FAMILY_DRATINI
    [SPECIES_DRATINI] =
    {
        .baseHP        = 41,
        .baseAttack    = 64,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 67,
        .evYield_Attack = 1,
        .itemRare = ITEM_DRAGON_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_MARVEL_SCALE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Dratini"),
        .cryId = CRY_DRATINI,
        .natDexNum = NATIONAL_DEX_DRATINI,
        .categoryName = _("Dragon"),
        .height = 18,
        .weight = 33,
        .description = COMPOUND_STRING(
            "A Dratini continually molts and sloughs\n"
            "off its old skin. It does so because the\n"
            "life energy within its body steadily builds\n"
            "to reach uncontrollable levels."),
        .pokemonScale = 256,
        .pokemonOffset = 8,
        .trainerScale = 386,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Dratini,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dratini,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Dratini,
        .shinyPalette = gMonShinyPalette_Dratini,
        .iconSprite = gMonIcon_Dratini,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 3, SHADOW_SIZE_L)
        FOOTPRINT(Dratini)
        OVERWORLD(
            sPicTable_Dratini,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Dratini,
            gShinyOverworldPalette_Dratini
        )
        .levelUpLearnset = sDratiniLevelUpLearnset,
        .teachableLearnset = sDratiniTeachableLearnset,
        .eggMoveLearnset = sDratiniEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_DRAGONAIR}),
    },

    [SPECIES_DRAGONAIR] =
    {
        .baseHP        = 61,
        .baseAttack    = 84,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 144,
        .evYield_Attack = 2,
        .itemRare = ITEM_DRAGON_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_MARVEL_SCALE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Dragonair"),
        .cryId = CRY_DRAGONAIR,
        .natDexNum = NATIONAL_DEX_DRAGONAIR,
        .categoryName = _("Dragon"),
        .height = 40,
        .weight = 165,
        .description = COMPOUND_STRING(
            "A Dragonair stores an enormous amount of\n"
            "energy inside its body. It is said to alter\n"
            "the weather around it by loosing energy\n"
            "from the crystals on its neck and tail."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 411,
        .trainerOffset = 5,
        .frontPic = gMonFrontPic_Dragonair,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE : ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Dragonair,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(40, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 4,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Dragonair,
        .shinyPalette = gMonShinyPalette_Dragonair,
        .iconSprite = gMonIcon_Dragonair,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Dragonair)
        OVERWORLD(
            sPicTable_Dragonair,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Dragonair,
            gShinyOverworldPalette_Dragonair
        )
        .levelUpLearnset = sDragonairLevelUpLearnset,
        .teachableLearnset = sDragonairTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 55, SPECIES_DRAGONITE}),
    },

    [SPECIES_DRAGONITE] =
    {
        .baseHP        = 91,
        .baseAttack    = 134,
        .baseDefense   = 95,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 218,
    #endif
        .evYield_Attack = 3,
        .itemRare = ITEM_DRAGON_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_MULTISCALE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Dragonite"),
        .cryId = CRY_DRAGONITE,
        .natDexNum = NATIONAL_DEX_DRAGONITE,
        .categoryName = _("Dragon"),
        .height = 22,
        .weight = 2100,
        .description = COMPOUND_STRING(
            "It can circle the globe in just 16 hours.\n"
            "It is a kindhearted Pokémon that leads\n"
            "lost and foundering ships in a storm\n"
            "to the safety of land."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Dragonite,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SLIDE_SLOW : ANIM_V_SHAKE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 0,
        .backPic = gMonBackPic_Dragonite,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 1,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Dragonite,
        .shinyPalette = gMonShinyPalette_Dragonite,
        .iconSprite = gMonIcon_Dragonite,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Dragonite)
        OVERWORLD(
            sPicTable_Dragonite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Dragonite,
            gShinyOverworldPalette_Dragonite
        )
        .levelUpLearnset = sDragoniteLevelUpLearnset,
        .teachableLearnset = sDragoniteTeachableLearnset,
        .formSpeciesIdTable = sDragoniteFormSpeciesIdTable,
        .formChangeTable = sDragoniteFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_DRAGONITE_MEGA] =
    {
        .baseHP        = 91,
        .baseAttack    = 124,
        .baseDefense   = 115,
        .baseSpeed     = 100,
        .baseSpAttack  = 145,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 300,
        .evYield_Attack = 3,
        .itemRare = ITEM_DRAGON_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_MULTISCALE, ABILITY_MULTISCALE, ABILITY_MULTISCALE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Dragonite"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_DRAGONITE_MEGA,
    #else
        .cryId = CRY_DRAGONITE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_DRAGONITE,
        .categoryName = _("Dragon"),
        .height = 22,
        .weight = 2900,
        .description = COMPOUND_STRING(
            "Mega Evolution has excessively\n"
            "powered up this Pokémon's feelings\n"
            "of kindness. It finishes off its\n"
            "opponents with mercy in its heart."),
        .frontPic = gMonFrontPic_DragoniteMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_DragoniteMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DragoniteMega,
        .shinyPalette = gMonShinyPalette_DragoniteMega,
        .iconSprite = gMonIcon_DragoniteMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Dragonite)
        SHADOW(4, 20, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sDragoniteLevelUpLearnset,
        .teachableLearnset = sDragoniteTeachableLearnset,
        .formSpeciesIdTable = sDragoniteFormSpeciesIdTable,
        .formChangeTable = sDragoniteFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_DRATINI

#if P_FAMILY_MEWTWO
    [SPECIES_MEWTWO] =
    {
        .baseHP        = 106,
        .baseAttack    = 110,
        .baseDefense   = 90,
        .baseSpeed     = 130,
        .baseSpAttack  = 154,
        .baseSpDefense = P_UPDATED_STATS >= GEN_2 ? 90 : 154,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mewtwo"),
        .cryId = CRY_MEWTWO,
        .natDexNum = NATIONAL_DEX_MEWTWO,
        .categoryName = _("Genetic"),
        .height = 20,
        .weight = 1220,
        .description = COMPOUND_STRING(
            "A Pokémon that was created by genetic\n"
            "manipulation. However, even though the\n"
            "scientific power of humans made its body,\n"
            "they failed to give it a warm heart."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Mewtwo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Mewtwo,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Mewtwo,
        .shinyPalette = gMonShinyPalette_Mewtwo,
        .iconSprite = gMonIcon_Mewtwo,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Mewtwo)
        OVERWORLD(
            sPicTable_Mewtwo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mewtwo,
            gShinyOverworldPalette_Mewtwo
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMewtwoLevelUpLearnset,
        .teachableLearnset = sMewtwoTeachableLearnset,
        .formSpeciesIdTable = sMewtwoFormSpeciesIdTable,
        .formChangeTable = sMewtwoFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_MEWTWO_MEGA_X] =
    {
        .baseHP        = 106,
        .baseAttack    = 190,
        .baseDefense   = 100,
        .baseSpeed     = 130,
        .baseSpAttack  = 154,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 390 : 351,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STEADFAST, ABILITY_STEADFAST, ABILITY_STEADFAST },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mewtwo"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_MEWTWO_MEGA_X,
    #else
        .cryId = CRY_MEWTWO,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_MEWTWO,
        .categoryName = _("Genetic"),
        .height = 23,
        .weight = 1270,
        .description = COMPOUND_STRING(
            "Psychic power has augmented its muscles.\n"
            "It has a grip strength of one ton and can\n"
            "sprint a hundred meters in two seconds\n"
            "flat!"),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_MewtwoMegaX,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_GROW_STUTTER,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_MewtwoMegaX,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_MewtwoMegaX,
        .shinyPalette = gMonShinyPalette_MewtwoMegaX,
        .iconSprite = gMonIcon_MewtwoMegaX,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Mewtwo)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_MewtwoMegaX,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MewtwoMegaX,
            gShinyOverworldPalette_MewtwoMegaX
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isRestrictedLegendary = TRUE,
        .isMegaEvolution = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMewtwoLevelUpLearnset,
        .teachableLearnset = sMewtwoTeachableLearnset,
        .formSpeciesIdTable = sMewtwoFormSpeciesIdTable,
        .formChangeTable = sMewtwoFormChangeTable,
    },

    [SPECIES_MEWTWO_MEGA_Y] =
    {
        .baseHP        = 106,
        .baseAttack    = 150,
        .baseDefense   = 70,
        .baseSpeed     = 140,
        .baseSpAttack  = 194,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 390 : 351,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_INSOMNIA, ABILITY_INSOMNIA, ABILITY_INSOMNIA },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mewtwo"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_MEWTWO_MEGA_Y,
    #else
        .cryId = CRY_MEWTWO,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_MEWTWO,
        .categoryName = _("Genetic"),
        .height = 15,
        .weight = 330,
        .description = COMPOUND_STRING(
            "Despite its diminished size, its mental\n"
            "power has grown phenomenally. With a mere\n"
            "thought, it can smash a skyscraper to\n"
            "smithereens."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_MewtwoMegaY,
        .frontPicSize = MON_COORDS_SIZE(40, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .frontAnimDelay = 10,
		.enemyMonElevation = 3,
        .backPic = gMonBackPic_MewtwoMegaY,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_MewtwoMegaY,
        .shinyPalette = gMonShinyPalette_MewtwoMegaY,
        .iconSprite = gMonIcon_MewtwoMegaY,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_S)
        FOOTPRINT(Mewtwo)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_MewtwoMegaY,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MewtwoMegaY,
            gShinyOverworldPalette_MewtwoMegaY
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isRestrictedLegendary = TRUE,
        .isMegaEvolution = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMewtwoLevelUpLearnset,
        .teachableLearnset = sMewtwoTeachableLearnset,
        .formSpeciesIdTable = sMewtwoFormSpeciesIdTable,
        .formChangeTable = sMewtwoFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_MEWTWO

#if P_FAMILY_MEW
    [SPECIES_MEW] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 64,
    #endif
        .evYield_HP = 3,
        .itemCommon = ITEM_LUM_BERRY,
        .itemRare = ITEM_LUM_BERRY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Mew"),
        .cryId = CRY_MEW,
        .natDexNum = NATIONAL_DEX_MEW,
        .categoryName = _("New Species"),
        .height = 4,
        .weight = 40,
        .description = COMPOUND_STRING(
            "A Mew is said to possess the genes of all\n"
            "Pokémon. It is capable of making itself\n"
            "invisible at will, so it entirely avoids\n"
            "notice even if it approaches people."),
        .pokemonScale = 457,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mew,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONVEX : ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 11,
        .backPic = gMonBackPic_Mew,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Mew,
        .shinyPalette = gMonShinyPalette_Mew,
        .iconSprite = gMonIcon_Mew,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_S)
        FOOTPRINT(Mew)
        OVERWORLD(
            sPicTable_Mew,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Mew,
            gShinyOverworldPalette_Mew
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .teachingType = ALL_TEACHABLES,
        .levelUpLearnset = sMewLevelUpLearnset,
        .teachableLearnset = sMewTeachableLearnset,
    },
#endif //P_FAMILY_MEW

#ifdef __INTELLISENSE__
};
#endif
