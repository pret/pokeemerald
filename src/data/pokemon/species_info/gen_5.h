#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen5[] =
{
#endif

#if P_FAMILY_VICTINI
    [SPECIES_VICTINI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_FIRE },
        .catchRate = 3,
        .expYield = 270,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_VICTORY_STAR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .isMythical = TRUE,
        .speciesName = _("Victini"),
        .cryId = CRY_VICTINI,
        .natDexNum = NATIONAL_DEX_VICTINI,
        .categoryName = _("Victory"),
        .height = 4,
        .weight = 40,
        .description = COMPOUND_STRING(
            "This Pokémon brings victory.\n"
            "It is said that Trainers with Victini\n"
            "always win, regardless of the type\n"
            "of encounter."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Victini, 48, 56),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Victini,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Victini, 40, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Victini),
        ICON(Victini, 0),
        .footprint = gMonFootprint_Victini,
        LEARNSETS(Victini),
    },
#endif //P_FAMILY_VICTINI

#if P_FAMILY_SNIVY
    [SPECIES_SNIVY] =
    {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 63,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Snivy"),
        .cryId = CRY_SNIVY,
        .natDexNum = NATIONAL_DEX_SNIVY,
        .categoryName = _("Grass Snake"),
        .height = 6,
        .weight = 81,
        .description = COMPOUND_STRING(
            "It is very intelligent and calm.\n"
            "Being exposed to lots of sunlight makes\n"
            "its movements swifter. When they are\n"
            "not feeling well, their tails droop."),
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Snivy, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Snivy,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Snivy, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Snivy),
        ICON(Snivy, 1),
        .footprint = gMonFootprint_Snivy,
        LEARNSETS(Snivy),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_SERVINE}),
    },

    [SPECIES_SERVINE] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 83,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 145,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Servine"),
        .cryId = CRY_SERVINE,
        .natDexNum = NATIONAL_DEX_SERVINE,
        .categoryName = _("Grass Snake"),
        .height = 8,
        .weight = 160,
        .description = COMPOUND_STRING(
            "When it gets dirty, its leaves can't be\n"
            "used in photosynthesis, so it always keeps\n"
            "clean. They avoid attacks by sinking into\n"
            "the shadows of thick foliage."),
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Servine, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Servine,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Servine, 48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Servine),
        ICON(Servine, 1),
        .footprint = gMonFootprint_Servine,
        LEARNSETS(Servine),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SERPERIOR}),
    },

    [SPECIES_SERPERIOR] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 95,
        .baseSpeed     = 113,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 238,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Serperior"),
        .cryId = CRY_SERPERIOR,
        .natDexNum = NATIONAL_DEX_SERPERIOR,
        .categoryName = _("Regal"),
        .height = 33,
        .weight = 630,
        .description = COMPOUND_STRING(
            "They raise their heads to intimidate foes,\n"
            "but only give it their all when fighting\n"
            "powerful opponents who are not fazed\n"
            "by the glare from its noble eyes."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
        FRONT_PIC(Serperior, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Serperior,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Serperior, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Serperior),
        ICON(Serperior, 1),
        .footprint = gMonFootprint_Serperior,
        LEARNSETS(Serperior),
    },
#endif //P_FAMILY_SNIVY

#if P_FAMILY_TEPIG
    [SPECIES_TEPIG] =
    {
        .baseHP        = 65,
        .baseAttack    = 63,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Tepig"),
        .cryId = CRY_TEPIG,
        .natDexNum = NATIONAL_DEX_TEPIG,
        .categoryName = _("Fire Pig"),
        .height = 5,
        .weight = 99,
        .description = COMPOUND_STRING(
            "It loves to eat roasted berries, but\n"
            "sometimes it gets too excited and burns\n"
            "them to a crisp. It blows fire through\n"
            "its nose."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tepig, 40, 48),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Tepig,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Tepig, 48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Tepig),
        ICON(Tepig, 0),
        .footprint = gMonFootprint_Tepig,
        LEARNSETS(Tepig),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_PIGNITE}),
    },

    [SPECIES_PIGNITE] =
    {
        .baseHP        = 90,
        .baseAttack    = 93,
        .baseDefense   = 55,
        .baseSpeed     = 55,
        .baseSpAttack  = 70,
        .baseSpDefense = 55,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 146,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Pignite"),
        .cryId = CRY_PIGNITE,
        .natDexNum = NATIONAL_DEX_PIGNITE,
        .categoryName = _("Fire Pig"),
        .height = 10,
        .weight = 555,
        .description = COMPOUND_STRING(
            "The more it eats, the more fuel it has\n"
            "to make the fire in its stomach stronger.\n"
            "When it is angered, the intensity of the\n"
            "flame increases."),
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Pignite, 56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Pignite,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Pignite, 64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Pignite),
        ICON(Pignite, 0),
        .footprint = gMonFootprint_Pignite,
        LEARNSETS(Pignite),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_EMBOAR}),
    },

    [SPECIES_EMBOAR] =
    {
        .baseHP        = 110,
        .baseAttack    = 123,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 238,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Emboar"),
        .cryId = CRY_EMBOAR,
        .natDexNum = NATIONAL_DEX_EMBOAR,
        .categoryName = _("Fire Pig"),
        .height = 16,
        .weight = 1500,
        .description = COMPOUND_STRING(
            "It is adept at using many different moves.\n"
            "It can throw a fire punch by setting its\n"
            "fists on fire with its fiery chin.\n"
            "It cares deeply about its friends."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Emboar, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Emboar,
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Emboar, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Emboar),
        ICON(Emboar, 0),
        .footprint = gMonFootprint_Emboar,
        LEARNSETS(Emboar),
    },
#endif //P_FAMILY_TEPIG

#if P_FAMILY_OSHAWOTT
    [SPECIES_OSHAWOTT] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 63,
        .baseSpDefense = 45,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Oshawott"),
        .cryId = CRY_OSHAWOTT,
        .natDexNum = NATIONAL_DEX_OSHAWOTT,
        .categoryName = _("Sea Otter"),
        .height = 5,
        .weight = 59,
        .description = COMPOUND_STRING(
            "The scalchop on its stomach isn't just\n"
            "used for battle, it can be used to break\n"
            "open hard berries as well. It is made\n"
            "from the same element as its claws."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Oshawott, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Oshawott,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Oshawott, 40, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Oshawott),
        ICON(Oshawott, 0),
        .footprint = gMonFootprint_Oshawott,
        LEARNSETS(Oshawott),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_DEWOTT}),
    },

    [SPECIES_DEWOTT] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 83,
        .baseSpDefense = 60,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 145,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Dewott"),
        .cryId = CRY_DEWOTT,
        .natDexNum = NATIONAL_DEX_DEWOTT,
        .categoryName = _("Discipline"),
        .height = 8,
        .weight = 245,
        .description = COMPOUND_STRING(
            "Strict training and disclipine leads it\n"
            "to master its flowing double-scalchop\n"
            "technique. Scalchop techniques differ\n"
            "from one Dewott to another."),
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Dewott, 40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Dewott,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Dewott, 56, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Dewott),
        ICON(Dewott, 0),
        .footprint = gMonFootprint_Dewott,
        LEARNSETS(Dewott),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SAMUROTT},
                                {EVO_NONE, 0, SPECIES_SAMUROTT_HISUIAN}),
    },

#define SAMUROTT_MISC_INFO                                                  \
        .catchRate = 45,                                                    \
        .expYield = 238,                                                    \
        .genderRatio = PERCENT_FEMALE(12.5),                                \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                  \
        .bodyColor = BODY_COLOR_BLUE,                                       \
        .speciesName = _("Samurott"),                                       \
        .cryId = CRY_SAMUROTT,                                              \
        .natDexNum = NATIONAL_DEX_SAMUROTT,                                 \
        .categoryName = _("Formidable"),                                    \
        .height = 15,                                                       \
        .pokemonScale = 268,                                                \
        .pokemonOffset = 2,                                                 \
        .trainerScale = 271,                                                \
        .trainerOffset = 0,                                                 \
        .footprint = gMonFootprint_Samurott,                                \
        .formSpeciesIdTable = sSamurottFormSpeciesIdTable

    [SPECIES_SAMUROTT] =
    {
        SAMUROTT_MISC_INFO,
        .baseHP        = 95,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 70,
        .baseSpAttack  = 108,
        .baseSpDefense = 70,
        .types = { TYPE_WATER, TYPE_WATER },
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .weight = 946,
        .description = COMPOUND_STRING(
            "One swing of the seamitars attached\n"
            "to its armor can fell an opponent.\n"
            "A simple glare from one of them is\n"
            "enough to intimidate most enemies."),
        FRONT_PIC(Samurott, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Samurott,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Samurott, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(Samurott),
        ICON(Samurott, 2),
        LEARNSETS(Samurott),
    },

#if P_HISUIAN_FORMS
    [SPECIES_SAMUROTT_HISUIAN] =
    {
        SAMUROTT_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 108,
        .baseDefense   = 80,
        .baseSpeed     = 85,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = { TYPE_WATER, TYPE_DARK },
        .evYield_Attack = 3,
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHARPNESS },
        .weight = 582,
        .description = COMPOUND_STRING(
            "Hard of heart and deft of blade,\n"
            "this rare form of Samurott is a\n"
            "product of the Pokémon's evolution in the\n"
            "region of Hisui."),
        FRONT_PIC(SamurottHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SamurottHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(SamurottHisuian, 64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(SamurottHisuian),
        ICON(SamurottHisuian, 0),
        LEARNSETS(SamurottHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_OSHAWOTT

#if P_FAMILY_PATRAT
    [SPECIES_PATRAT] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 39,
        .baseSpeed     = 42,
        .baseSpAttack  = 35,
        .baseSpDefense = 39,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 51,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KEEN_EYE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Patrat"),
        .cryId = CRY_PATRAT,
        .natDexNum = NATIONAL_DEX_PATRAT,
        .categoryName = _("Scout"),
        .height = 5,
        .weight = 116,
        .description = COMPOUND_STRING(
            "Extremely cautious, they take shifts to\n"
            "maintain a constant watch of their nest.\n"
            "Using food stored in cheek pouches,\n"
            "they can keep watch for days."),
        .pokemonScale = 432,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Patrat, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Patrat,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Patrat, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Patrat),
        ICON(Patrat, 2),
        .footprint = gMonFootprint_Patrat,
        LEARNSETS(Patrat),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_WATCHOG}),
    },

    [SPECIES_WATCHOG] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 69,
        .baseSpeed     = 77,
        .baseSpAttack  = 60,
        .baseSpDefense = 69,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_ILLUMINATE, ABILITY_KEEN_EYE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Watchog"),
        .cryId = CRY_WATCHOG,
        .natDexNum = NATIONAL_DEX_WATCHOG,
        .categoryName = _("Lookout"),
        .height = 11,
        .weight = 270,
        .description = COMPOUND_STRING(
            "Using luminescent matter, it makes its\n"
            "eyes and body glow and stuns attacking\n"
            "opponents. Keen eyesight lets them see\n"
            "in the dark."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Watchog, 32, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Watchog,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Watchog, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Watchog),
        ICON(Watchog, 2),
        .footprint = gMonFootprint_Watchog,
        LEARNSETS(Watchog),
    },
#endif //P_FAMILY_PATRAT

#if P_FAMILY_LILLIPUP
    [SPECIES_LILLIPUP] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 55,
        .baseSpAttack  = 25,
        .baseSpDefense = 45,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 55,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_PICKUP, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Lillipup"),
        .cryId = CRY_LILLIPUP,
        .natDexNum = NATIONAL_DEX_LILLIPUP,
        .categoryName = _("Puppy"),
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "It faces strong opponents with great\n"
            "courage. Because it doesn't yelp, it's\n"
            "extremely popular with Trainers who live\n"
            "in apartment buildings."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lillipup, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Lillipup,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Lillipup, 48, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Lillipup),
        ICON(Lillipup, 2),
        .footprint = gMonFootprint_Lillipup,
        LEARNSETS(Lillipup),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_HERDIER}),
    },

    [SPECIES_HERDIER] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 65,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 120,
        .expYield = 130,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SAND_RUSH, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Herdier"),
        .cryId = CRY_HERDIER,
        .natDexNum = NATIONAL_DEX_HERDIER,
        .categoryName = _("Loyal Dog"),
        .height = 9,
        .weight = 147,
        .description = COMPOUND_STRING(
            "Its dense black fur grows continuously.\n"
            "The high cost of keeping its hard fur\n"
            "properly groomed makes this a\n"
            "troublesome Pokémon to train."),
        .pokemonScale = 338,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Herdier, 48, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Herdier,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Herdier, 48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Herdier),
        ICON(Herdier, 2),
        .footprint = gMonFootprint_Herdier,
        LEARNSETS(Herdier),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_STOUTLAND}),
    },

    [SPECIES_STOUTLAND] =
    {
        .baseHP        = 85,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 110 : 100,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 225,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SAND_RUSH, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Stoutland"),
        .cryId = CRY_STOUTLAND,
        .natDexNum = NATIONAL_DEX_STOUTLAND,
        .categoryName = _("Big-Hearted"),
        .height = 12,
        .weight = 610,
        .description = COMPOUND_STRING(
            "Intelligent, good-natured, and valiant,\n"
            "there could be no concern that it would\n"
            "ever attack people. Some parents even\n"
            "trust it to babysit."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Stoutland, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Stoutland,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Stoutland, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Stoutland),
        ICON(Stoutland, 2),
        .footprint = gMonFootprint_Stoutland,
        LEARNSETS(Stoutland),
    },
#endif //P_FAMILY_LILLIPUP

#if P_FAMILY_PURRLOIN
    [SPECIES_PURRLOIN] =
    {
        .baseHP        = 41,
        .baseAttack    = 50,
        .baseDefense   = 37,
        .baseSpeed     = 66,
        .baseSpAttack  = 50,
        .baseSpDefense = 37,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Purrloin"),
        .cryId = CRY_PURRLOIN,
        .natDexNum = NATIONAL_DEX_PURRLOIN,
        .categoryName = _("Devious"),
        .height = 4,
        .weight = 101,
        .description = COMPOUND_STRING(
            "Their deceptively cute act is the\n"
            "perfect ruse. They steal from people for\n"
            "fun, but their victims can't help but\n"
            "forgive them."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Purrloin, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Purrloin,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Purrloin, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Purrloin),
        ICON(Purrloin, 0),
        .footprint = gMonFootprint_Purrloin,
        LEARNSETS(Purrloin),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_LIEPARD}),
    },

    [SPECIES_LIEPARD] =
    {
        .baseHP        = 64,
        .baseAttack    = 88,
        .baseDefense   = 50,
        .baseSpeed     = 106,
        .baseSpAttack  = 88,
        .baseSpDefense = 50,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 90,
        .expYield = 156,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Liepard"),
        .cryId = CRY_LIEPARD,
        .natDexNum = NATIONAL_DEX_LIEPARD,
        .categoryName = _("Cruel"),
        .height = 11,
        .weight = 375,
        .description = COMPOUND_STRING(
            "Many Trainers are drawn to their\n"
            "beautiful form and fur. These Pokémon\n"
            "vanish and appear unexpectedly.\n"
            "They run silently in the night."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Liepard, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Liepard,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Liepard, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Liepard),
        ICON(Liepard, 0),
        .footprint = gMonFootprint_Liepard,
        LEARNSETS(Liepard),
    },
#endif //P_FAMILY_PURRLOIN

#if P_FAMILY_PANSAGE
    [SPECIES_PANSAGE] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_OVERGROW },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Pansage"),
        .cryId = CRY_PANSAGE,
        .natDexNum = NATIONAL_DEX_PANSAGE,
        .categoryName = _("Grass Monkey"),
        .height = 6,
        .weight = 105,
        .description = COMPOUND_STRING(
            "This Pokémon dwells deep in the forest.\n"
            "It's good at finding berries and gathers\n"
            "them from all over. It's kind enough to\n"
            "share them with friends."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pansage, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Pansage,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Pansage, 48, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Pansage),
        ICON(Pansage, 1),
        .footprint = gMonFootprint_Pansage,
        LEARNSETS(Pansage),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_SIMISAGE}),
    },

    [SPECIES_SIMISAGE] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_OVERGROW },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Simisage"),
        .cryId = CRY_SIMISAGE,
        .natDexNum = NATIONAL_DEX_SIMISAGE,
        .categoryName = _("Thorn Monkey"),
        .height = 11,
        .weight = 305,
        .description = COMPOUND_STRING(
            "Ill tempered, it attacks enemies by\n"
            "swinging its barbed tail around wildly.\n"
            "The leaf growing on its head is\n"
            "very bitter."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Simisage, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Simisage,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Simisage, 56, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Simisage),
        ICON(Simisage, 1),
        .footprint = gMonFootprint_Simisage,
        LEARNSETS(Simisage),
    },
#endif //P_FAMILY_PANSAGE

#if P_FAMILY_PANSEAR
    [SPECIES_PANSEAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_BLAZE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Pansear"),
        .cryId = CRY_PANSEAR,
        .natDexNum = NATIONAL_DEX_PANSEAR,
        .categoryName = _("High Temp"),
        .height = 6,
        .weight = 110,
        .description = COMPOUND_STRING(
            "The fire within the tuft on its head can\n"
            "reach up to 600ºF. Very intelligent,\n"
            "it roasts berries before eating them.\n"
            "It likes to help people."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pansear, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Pansear,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Pansear, 48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Pansear),
        ICON(Pansear, 2),
        .footprint = gMonFootprint_Pansear,
        LEARNSETS(Pansear),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_FIRE_STONE, SPECIES_SIMISEAR}),
    },

    [SPECIES_SIMISEAR] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_BLAZE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Simisear"),
        .cryId = CRY_SIMISEAR,
        .natDexNum = NATIONAL_DEX_SIMISEAR,
        .categoryName = _("Ember"),
        .height = 10,
        .weight = 280,
        .description = COMPOUND_STRING(
            "It loves sweets because they become\n"
            "energy for the fire burning inside its\n"
            "body. It scatters embers from its head\n"
            "and tail to sear its opponents."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Simisear, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Simisear,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST,
        BACK_PIC(Simisear, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Simisear),
        ICON(Simisear, 2),
        .footprint = gMonFootprint_Simisear,
        LEARNSETS(Simisear),
    },
#endif //P_FAMILY_PANSEAR

#if P_FAMILY_PANPOUR
    [SPECIES_PANPOUR] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_TORRENT },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Panpour"),
        .cryId = CRY_PANPOUR,
        .natDexNum = NATIONAL_DEX_PANPOUR,
        .categoryName = _("Spray"),
        .height = 6,
        .weight = 135,
        .description = COMPOUND_STRING(
            "The water stored inside the tuft of its\n"
            "head is rich in nutrients. It waters\n"
            "plants using its tail, plants that\n"
            "receive its water grow large."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Panpour, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Panpour,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Panpour, 48, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Panpour),
        ICON(Panpour, 2),
        .footprint = gMonFootprint_Panpour,
        LEARNSETS(Panpour),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_WATER_STONE, SPECIES_SIMIPOUR}),
    },

    [SPECIES_SIMIPOUR] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_TORRENT },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Simipour"),
        .cryId = CRY_SIMIPOUR,
        .natDexNum = NATIONAL_DEX_SIMIPOUR,
        .categoryName = _("Geyser"),
        .height = 10,
        .weight = 290,
        .description = COMPOUND_STRING(
            "It can shoot highly-pressurised water\n"
            "from its tail with enough power to\n"
            "break through a solid concrete wall.\n"
            "It prefers places with clean water."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Simipour, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Simipour,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Simipour, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Simipour),
        ICON(Simipour, 2),
        .footprint = gMonFootprint_Simipour,
        LEARNSETS(Simipour),
    },
#endif //P_FAMILY_PANPOUR

#if P_FAMILY_MUNNA
    [SPECIES_MUNNA] =
    {
        .baseHP        = 76,
        .baseAttack    = 25,
        .baseDefense   = 45,
        .baseSpeed     = 24,
        .baseSpAttack  = 67,
        .baseSpDefense = 55,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 190,
        .expYield = 58,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FOREWARN, ABILITY_SYNCHRONIZE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Munna"),
        .cryId = CRY_MUNNA,
        .natDexNum = NATIONAL_DEX_MUNNA,
        .categoryName = _("Dream Eater"),
        .height = 6,
        .weight = 233,
        .description = COMPOUND_STRING(
            "This Pokémon appears before people\n"
            "and Pokémon who are having nightmares\n"
            "and eats those dreams. Munna always\n"
            "float in the air. "),
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Munna, 32, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Munna,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 7,
        BACK_PIC(Munna, 48, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Munna),
        ICON(Munna, 0),
        .footprint = gMonFootprint_Munna,
        LEARNSETS(Munna),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_MUSHARNA}),
    },

    [SPECIES_MUSHARNA] =
    {
        .baseHP        = 116,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 29,
        .baseSpAttack  = 107,
        .baseSpDefense = 95,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 75,
        .expYield = 170,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FOREWARN, ABILITY_SYNCHRONIZE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Musharna"),
        .cryId = CRY_MUSHARNA,
        .natDexNum = NATIONAL_DEX_MUSHARNA,
        .categoryName = _("Drowsing"),
        .height = 11,
        .weight = 605,
        .description = COMPOUND_STRING(
            "The mist emanating from their foreheads\n"
            "is packed with the dreams of people and\n"
            "Pokémon. It changes into different colors\n"
            "depending on the dream that was eaten."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Musharna, 64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Musharna,
        .frontAnimId = ANIM_ROTATE_TO_SIDES_TWICE,
        .enemyMonElevation = 5,
        BACK_PIC(Musharna, 64, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Musharna),
        ICON(Musharna, 0),
        .footprint = gMonFootprint_Musharna,
        LEARNSETS(Musharna),
    },
#endif //P_FAMILY_MUNNA

#if P_FAMILY_PIDOVE
    [SPECIES_PIDOVE] =
    {
        .baseHP        = 50,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 43,
        .baseSpAttack  = 36,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 53,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Pidove"),
        .cryId = CRY_PIDOVE,
        .natDexNum = NATIONAL_DEX_PIDOVE,
        .categoryName = _("Tiny Pigeon"),
        .height = 3,
        .weight = 21,
        .description = COMPOUND_STRING(
            "This very forgetful Pokémon will wait for\n"
            "a new order from its Trainer even though\n"
            "it already has one. Flocks often gather\n"
            "in parks and plazas."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pidove, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Pidove,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Pidove, 48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Pidove),
        ICON(Pidove, 0),
        .footprint = gMonFootprint_Pidove,
        LEARNSETS(Pidove),
        .evolutions = EVOLUTION({EVO_LEVEL, 21, SPECIES_TRANQUILL}),
    },

    [SPECIES_TRANQUILL] =
    {
        .baseHP        = 62,
        .baseAttack    = 77,
        .baseDefense   = 62,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 42,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 125,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Tranquill"),
        .cryId = CRY_TRANQUILL,
        .natDexNum = NATIONAL_DEX_TRANQUILL,
        .categoryName = _("Wild Pigeon"),
        .height = 6,
        .weight = 150,
        .description = COMPOUND_STRING(
            "No matter where in the world it goes,\n"
            "it knows where its nest is, so it can\n"
            "always return to its Trainer's location\n"
            "regardless of the distance."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tranquill, 40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Tranquill,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Tranquill, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Tranquill),
        ICON(Tranquill, 0),
        .footprint = gMonFootprint_Tranquill,
        LEARNSETS(Tranquill),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_UNFEZANT}),
    },

    [SPECIES_UNFEZANT] =
    {
        .baseHP        = 80,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 115 : 105,
        .baseDefense   = 80,
        .baseSpeed     = 93,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 220,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Unfezant"),
        .cryId = CRY_UNFEZANT,
        .natDexNum = NATIONAL_DEX_UNFEZANT,
        .categoryName = _("Proud"),
        .height = 12,
        .weight = 290,
        .description = COMPOUND_STRING(
            "Males have plumage on their heads.\n"
            "The females' flying abilities surpass\n"
            "those of the males. They will only let\n"
            "themselves feel close to their Trainers."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Unfezant, 56, 64),
        FRONT_PIC_FEMALE(Unfezant, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Unfezant,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Unfezant, 64, 64),
        BACK_PIC_FEMALE(Unfezant, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Unfezant),
        PALETTE_FEMALE(Unfezant),
        ICON(Unfezant, 1),
        ICON_FEMALE(Unfezant, 1),
        .footprint = gMonFootprint_Unfezant,
        LEARNSETS(Unfezant),
    },
#endif //P_FAMILY_PIDOVE

#if P_FAMILY_BLITZLE
    [SPECIES_BLITZLE] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 32,
        .baseSpeed     = 76,
        .baseSpAttack  = 50,
        .baseSpDefense = 32,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 190,
        .expYield = 59,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_MOTOR_DRIVE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Blitzle"),
        .cryId = CRY_BLITZLE,
        .natDexNum = NATIONAL_DEX_BLITZLE,
        .categoryName = _("Electrified"),
        .height = 8,
        .weight = 298,
        .description = COMPOUND_STRING(
            "Its mane shines when it discharges\n"
            "electricity. They use the frequency and\n"
            "rhythm of these flashes to communicate\n"
            "with one another."),
        .pokemonScale = 366,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Blitzle, 40, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Blitzle,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Blitzle, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Blitzle),
        ICON(Blitzle, 2),
        .footprint = gMonFootprint_Blitzle,
        LEARNSETS(Blitzle),
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_ZEBSTRIKA}),
    },

    [SPECIES_ZEBSTRIKA] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 63,
        .baseSpeed     = 116,
        .baseSpAttack  = 80,
        .baseSpDefense = 63,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_MOTOR_DRIVE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Zebstrika"),
        .cryId = CRY_ZEBSTRIKA,
        .natDexNum = NATIONAL_DEX_ZEBSTRIKA,
        .categoryName = _("Thunderbolt"),
        .height = 16,
        .weight = 795,
        .description = COMPOUND_STRING(
            "When Zebstrika run at full speed, the\n"
            "sound of thunder reverberates. It is\n"
            "dangerous when it's angry as it shoots\n"
            "lightning from its mane in all directions."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Zebstrika, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Zebstrika,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Zebstrika, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Zebstrika),
        ICON(Zebstrika, 2),
        .footprint = gMonFootprint_Zebstrika,
        LEARNSETS(Zebstrika),
    },
#endif //P_FAMILY_BLITZLE

#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Defense = 1,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_WEAK_ARMOR, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Roggenrola"),
        .cryId = CRY_ROGGENROLA,
        .natDexNum = NATIONAL_DEX_ROGGENROLA,
        .categoryName = _("Mantle"),
        .height = 4,
        .weight = 180,
        .description = COMPOUND_STRING(
            "The hexagonal cavity is its ear.\n"
            "It walks in the direction of sounds it\n"
            "hears, but if the sounds cease, it panics\n"
            "and topples over."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Roggenrola, 24, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Roggenrola,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Roggenrola, 40, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Roggenrola),
        ICON(Roggenrola, 2),
        .footprint = gMonFootprint_Roggenrola,
        LEARNSETS(Roggenrola),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_BOLDORE}),
    },

    [SPECIES_BOLDORE] =
    {
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 105,
        .baseSpeed     = 20,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 120,
        .expYield = 137,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_WEAK_ARMOR, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Boldore"),
        .cryId = CRY_BOLDORE,
        .natDexNum = NATIONAL_DEX_BOLDORE,
        .categoryName = _("Ore"),
        .height = 9,
        .weight = 1020,
        .description = COMPOUND_STRING(
            "Its orange crystal is a mass of energy.\n"
            "Just one crystal fragment would provide\n"
            "enough fuel for a hundred dump trucks.\n"
            "When it is healthy, its core sticks out."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Boldore, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Boldore,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Boldore, 64, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Boldore),
        ICON(Boldore, 0),
        .footprint = gMonFootprint_Boldore,
        LEARNSETS(Boldore),
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GIGALITH},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GIGALITH}),
    },

    [SPECIES_GIGALITH] =
    {
        .baseHP        = 85,
        .baseAttack    = 135,
        .baseDefense   = 130,
        .baseSpeed     = 25,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 232,
        .evYield_Attack = 3,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_SAND_STREAM, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Gigalith"),
        .cryId = CRY_GIGALITH,
        .natDexNum = NATIONAL_DEX_GIGALITH,
        .categoryName = _("Compressed"),
        .height = 17,
        .weight = 2600,
        .description = COMPOUND_STRING(
            "The blasts of energy it makes from\n"
            "sunbeams have terrifying power.\n"
            "However, it's not able to fire its blasts\n"
            "at night or on rainy days."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Gigalith, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Gigalith,
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        BACK_PIC(Gigalith, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Gigalith),
        ICON(Gigalith, 0),
        .footprint = gMonFootprint_Gigalith,
        LEARNSETS(Gigalith),
    },
#endif //P_FAMILY_ROGGENROLA

#if P_FAMILY_WOOBAT
    [SPECIES_WOOBAT] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 65 : 55,
        .baseAttack    = 45,
        .baseDefense   = 43,
        .baseSpeed     = 72,
        .baseSpAttack  = 55,
        .baseSpDefense = 43,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 65,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FLYING },
        .abilities = { ABILITY_UNAWARE, ABILITY_KLUTZ, ABILITY_SIMPLE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Woobat"),
        .cryId = CRY_WOOBAT,
        .natDexNum = NATIONAL_DEX_WOOBAT,
        .categoryName = _("Bat"),
        .height = 4,
        .weight = 21,
        .description = COMPOUND_STRING(
            "Its habitat is dark forests and caves.\n"
            "Suction from its nostrils enables it\n"
            "to stick to cave walls during sleep.\n"
            "It leaves a heart-shaped mark behind."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Woobat, 64, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Woobat,
        .frontAnimId = ANIM_FOUR_PETAL,
        .enemyMonElevation = 19,
        BACK_PIC(Woobat, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Woobat),
        ICON(Woobat, 0),
        .footprint = gMonFootprint_Woobat,
        LEARNSETS(Woobat),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_SWOOBAT}),
    },

    [SPECIES_SWOOBAT] =
    {
        .baseHP        = 67,
        .baseAttack    = 57,
        .baseDefense   = 55,
        .baseSpeed     = 114,
        .baseSpAttack  = 77,
        .baseSpDefense = 55,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 149,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FLYING },
        .abilities = { ABILITY_UNAWARE, ABILITY_KLUTZ, ABILITY_SIMPLE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Swoobat"),
        .cryId = CRY_SWOOBAT,
        .natDexNum = NATIONAL_DEX_SWOOBAT,
        .categoryName = _("Courting"),
        .height = 9,
        .weight = 105,
        .description = COMPOUND_STRING(
            "Anyone who comes into contact with\n"
            "the ultrasonic waves emitted by a\n"
            "courting male experiences a positive\n"
            "mood shift."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swoobat, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Swoobat,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .enemyMonElevation = 10,
        BACK_PIC(Swoobat, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Swoobat),
        ICON(Swoobat, 0),
        .footprint = gMonFootprint_Swoobat,
        LEARNSETS(Swoobat),
    },
#endif //P_FAMILY_WOOBAT

#if P_FAMILY_DRILBUR
    [SPECIES_DRILBUR] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 40,
        .baseSpeed     = 68,
        .baseSpAttack  = 30,
        .baseSpDefense = 45,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 120,
        .expYield = 66,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAND_RUSH, ABILITY_SAND_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Drilbur"),
        .cryId = CRY_DRILBUR,
        .natDexNum = NATIONAL_DEX_DRILBUR,
        .categoryName = _("Mole"),
        .height = 3,
        .weight = 85,
        .description = COMPOUND_STRING(
            "It can dig through the ground at a\n"
            "speed of 30 mph by spinning its body.\n"
            "It could give a car running aboveground\n"
            "a good race."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drilbur, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Drilbur,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        BACK_PIC(Drilbur, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Drilbur),
        ICON(Drilbur, 0),
        .footprint = gMonFootprint_Drilbur,
        LEARNSETS(Drilbur),
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_EXCADRILL}),
    },

    [SPECIES_EXCADRILL] =
    {
        .baseHP        = 110,
        .baseAttack    = 135,
        .baseDefense   = 60,
        .baseSpeed     = 88,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        .types = { TYPE_GROUND, TYPE_STEEL },
        .catchRate = 60,
        .expYield = 178,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAND_RUSH, ABILITY_SAND_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Excadrill"),
        .cryId = CRY_EXCADRILL,
        .natDexNum = NATIONAL_DEX_EXCADRILL,
        .categoryName = _("Subterrene"),
        .height = 7,
        .weight = 404,
        .description = COMPOUND_STRING(
            "More than 300 feet below the surface,\n"
            "they build mazelike nests. Their activity\n"
            "can be destructive to subway tunnels,\n"
            "but it can also help with construction."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Excadrill, 64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Excadrill,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Excadrill, 64, 64),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Excadrill),
        ICON(Excadrill, 0),
        .footprint = gMonFootprint_Excadrill,
        LEARNSETS(Excadrill),
    },
#endif //P_FAMILY_DRILBUR

#define AUDINO_MISC_INFO                                    \
        .catchRate = 255,                                   \
        .evYield_HP = 2,                                    \
        .itemCommon = ITEM_ORAN_BERRY,                      \
        .itemRare = ITEM_SITRUS_BERRY,                      \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_FAST,                          \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },  \
        .speciesName = _("Audino"),                         \
        .natDexNum = NATIONAL_DEX_AUDINO,                   \
        .categoryName = _("Hearing"),                       \
        .footprint = gMonFootprint_Audino,                  \
        LEARNSETS(Audino),                                  \
        .formSpeciesIdTable = sAudinoFormSpeciesIdTable,    \
        .formChangeTable = sAudinoFormChangeTable

#if P_FAMILY_AUDINO
    [SPECIES_AUDINO] =
    {
        AUDINO_MISC_INFO,
        .baseHP        = 103,
        .baseAttack    = 60,
        .baseDefense   = 86,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 86,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .expYield = 390,
        .abilities = { ABILITY_HEALER, ABILITY_REGENERATOR, ABILITY_KLUTZ },
        .bodyColor = BODY_COLOR_PINK,
        .cryId = CRY_AUDINO,
        .height = 11,
        .weight = 310,
        .description = COMPOUND_STRING(
            "Its auditory sense is astounding.\n"
            "Using the feelers on its ears, it can tell\n"
            "how someone is feeling or when an egg\n"
            "might hatch."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Audino, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Audino,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Audino, 56, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Audino),
        ICON(Audino, 1),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_AUDINO_MEGA] =
    {
        AUDINO_MISC_INFO,
        .baseHP        = 103,
        .baseAttack    = 60,
        .baseDefense   = 126,
        .baseSpeed     = 50,
        .baseSpAttack  = 80,
        .baseSpDefense = 126,
        .types = { TYPE_NORMAL, TYPE_FAIRY },
        .expYield = 425,
        .abilities = { ABILITY_HEALER, ABILITY_HEALER, ABILITY_HEALER },
        .bodyColor = BODY_COLOR_WHITE,
        .cryId = CRY_AUDINO_MEGA,
        .height = 15,
        .weight = 320,
        .description = COMPOUND_STRING(
            "Mega Audino emits a soothing pulse from\n"
            "its body that reduces hostility in others.\n"
            "Anything that comes into contact with its\n"
            "second feelers will fall into a deep sleep."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(AudinoMega, 48, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_AudinoMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AudinoMega, 56, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(AudinoMega),
        ICON(AudinoMega, 1),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_AUDINO

#if P_FAMILY_TIMBURR
    [SPECIES_TIMBURR] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 55,
        .baseSpeed     = 35,
        .baseSpAttack  = 25,
        .baseSpDefense = 35,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 180,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = 70,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Timburr"),
        .cryId = CRY_TIMBURR,
        .natDexNum = NATIONAL_DEX_TIMBURR,
        .categoryName = _("Muscular"),
        .height = 6,
        .weight = 125,
        .description = COMPOUND_STRING(
            "These Pokémon appear at building\n"
            "sites and help out with construction.\n"
            "They always carry squared logs.\n"
            "As they grow, they carry bigger logs."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Timburr, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Timburr,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Timburr, 64, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Timburr),
        ICON(Timburr, 1),
        .footprint = gMonFootprint_Timburr,
        LEARNSETS(Timburr),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_GURDURR}),
    },

    [SPECIES_GURDURR] =
    {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 90,
        .expYield = 142,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Gurdurr"),
        .cryId = CRY_GURDURR,
        .natDexNum = NATIONAL_DEX_GURDURR,
        .categoryName = _("Muscular"),
        .height = 12,
        .weight = 400,
        .description = COMPOUND_STRING(
            "They strengthen their bodies by carrying\n"
            "steel beams. This Pokémon is so muscular\n"
            "and strongly built that even a group of\n"
            "wrestlers could not make it budge an inch."),
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gurdurr, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Gurdurr,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Gurdurr, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Gurdurr),
        ICON(Gurdurr, 1),
        .footprint = gMonFootprint_Gurdurr,
        LEARNSETS(Gurdurr),
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_CONKELDURR},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_CONKELDURR}),
    },

    [SPECIES_CONKELDURR] =
    {
        .baseHP        = 105,
        .baseAttack    = 140,
        .baseDefense   = 95,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 227,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Conkeldurr"),
        .cryId = CRY_CONKELDURR,
        .natDexNum = NATIONAL_DEX_CONKELDURR,
        .categoryName = _("Muscular"),
        .height = 14,
        .weight = 870,
        .description = COMPOUND_STRING(
            "They use concrete pillars as walking\n"
            "canes. Rather than rely solely on force,\n"
            "they master moves that utilize the\n"
            "centrifugal force of spinning concrete."),
        .pokemonScale = 265,
        .pokemonOffset = 3,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Conkeldurr, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Conkeldurr,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Conkeldurr, 64, 56),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Conkeldurr),
        ICON(Conkeldurr, 1),
        .footprint = gMonFootprint_Conkeldurr,
        LEARNSETS(Conkeldurr),
    },
#endif //P_FAMILY_TIMBURR

#if P_FAMILY_TYMPOLE
    [SPECIES_TYMPOLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 64,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 255,
        .expYield = 59,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_HYDRATION, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Tympole"),
        .cryId = CRY_TYMPOLE,
        .natDexNum = NATIONAL_DEX_TYMPOLE,
        .categoryName = _("Tadpole"),
        .height = 5,
        .weight = 45,
        .description = COMPOUND_STRING(
            "By vibrating its cheeks, it emits sound\n"
            "waves imperceptible to humans. It uses\n"
            "the rhythm of these sounds to talk and\n"
            "warns others of danger."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tympole, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Tympole,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Tympole, 40, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_SPRING,
        PALETTES(Tympole),
        ICON(Tympole, 2),
        .footprint = gMonFootprint_Tympole,
        LEARNSETS(Tympole),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_PALPITOAD}),
    },

    [SPECIES_PALPITOAD] =
    {
        .baseHP        = 75,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 69,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = { TYPE_WATER, TYPE_GROUND },
        .catchRate = 120,
        .expYield = 134,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_HYDRATION, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Palpitoad"),
        .cryId = CRY_PALPITOAD,
        .natDexNum = NATIONAL_DEX_PALPITOAD,
        .categoryName = _("Vibration"),
        .height = 8,
        .weight = 170,
        .description = COMPOUND_STRING(
            "It lives in the water and on land.\n"
            "When they vibrate the bumps on their\n"
            "heads, they can make waves in water\n"
            "or earthquake-like vibrations on land."),
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Palpitoad, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Palpitoad,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Palpitoad, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Palpitoad),
        ICON(Palpitoad, 2),
        .footprint = gMonFootprint_Palpitoad,
        LEARNSETS(Palpitoad),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SEISMITOAD}),
    },

    [SPECIES_SEISMITOAD] =
    {
        .baseHP        = 105,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .baseDefense   = 75,
        .baseSpeed     = 74,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = { TYPE_WATER, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 229,
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_POISON_TOUCH, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Seismitoad"),
        .cryId = CRY_SEISMITOAD,
        .natDexNum = NATIONAL_DEX_SEISMITOAD,
        .categoryName = _("Vibration"),
        .height = 15,
        .weight = 620,
        .description = COMPOUND_STRING(
            "It increases the power of its punches\n"
            "by vibrating the bumps on its fists.\n"
            "They can also shoot paralyzing liquid\n"
            "from their head bumps."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Seismitoad, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Seismitoad,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Seismitoad, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Seismitoad),
        ICON(Seismitoad, 0),
        .footprint = gMonFootprint_Seismitoad,
        LEARNSETS(Seismitoad),
    },
#endif //P_FAMILY_TYMPOLE

#if P_FAMILY_THROH
    [SPECIES_THROH] =
    {
        .baseHP        = 120,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 45,
        .baseSpAttack  = 30,
        .baseSpDefense = 85,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 163,
        .evYield_HP = 2,
        .itemRare = ITEM_BLACK_BELT,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_INNER_FOCUS, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Throh"),
        .cryId = CRY_THROH,
        .natDexNum = NATIONAL_DEX_THROH,
        .categoryName = _("Judo"),
        .height = 13,
        .weight = 555,
        .description = COMPOUND_STRING(
            "When it tightens its belt, it becomes\n"
            "stronger. Wild Throh use vines to weave\n"
            "their own belts. It changes belts as it\n"
            "gets more powerful."),
        .pokemonScale = 272,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Throh, 64, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Throh,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Throh, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Throh),
        ICON(Throh, 0),
        .footprint = gMonFootprint_Throh,
        LEARNSETS(Throh),
    },
#endif //P_FAMILY_THROH

#if P_FAMILY_SAWK
    [SPECIES_SAWK] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 30,
        .baseSpDefense = 75,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 163,
        .evYield_Attack = 2,
        .itemRare = ITEM_BLACK_BELT,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_STURDY, ABILITY_INNER_FOCUS, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Sawk"),
        .cryId = CRY_SAWK,
        .natDexNum = NATIONAL_DEX_SAWK,
        .categoryName = _("Karate"),
        .height = 14,
        .weight = 510,
        .description = COMPOUND_STRING(
            "The sound of Sawk punching boulders\n"
            "and trees can be heard all the way from\n"
            "the mountains where they train.\n"
            "Disturbing their training angers them."),
        .pokemonScale = 265,
        .pokemonOffset = 4,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Sawk, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Sawk,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Sawk, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Sawk),
        ICON(Sawk, 0),
        .footprint = gMonFootprint_Sawk,
        LEARNSETS(Sawk),
    },
#endif //P_FAMILY_SAWK

#if P_FAMILY_SEWADDLE
    [SPECIES_SEWADDLE] =
    {
        .baseHP        = 45,
        .baseAttack    = 53,
        .baseDefense   = 70,
        .baseSpeed     = 42,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_GRASS },
        .catchRate = 255,
        .expYield = 62,
        .evYield_Defense = 1,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Sewaddle"),
        .cryId = CRY_SEWADDLE,
        .natDexNum = NATIONAL_DEX_SEWADDLE,
        .categoryName = _("Sewing"),
        .height = 3,
        .weight = 25,
        .description = COMPOUND_STRING(
            "It chews up leaves and sews them with\n"
            "sticky thread extruded from its mouth.\n"
            "Since this Pokémon makes its own clothes,\n"
            "it is a mascot for fashion designers."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sewaddle, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Sewaddle,
        .frontAnimId = ANIM_CIRCLE_INTO_BG,
        BACK_PIC(Sewaddle, 40, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Sewaddle),
        ICON(Sewaddle, 1),
        .footprint = gMonFootprint_Sewaddle,
        LEARNSETS(Sewaddle),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_SWADLOON}),
    },

    [SPECIES_SWADLOON] =
    {
        .baseHP        = 55,
        .baseAttack    = 63,
        .baseDefense   = 90,
        .baseSpeed     = 42,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        .types = { TYPE_BUG, TYPE_GRASS },
        .catchRate = 120,
        .expYield = 133,
        .evYield_Defense = 2,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Swadloon"),
        .cryId = CRY_SWADLOON,
        .natDexNum = NATIONAL_DEX_SWADLOON,
        .categoryName = _("Leaf-Wrapped"),
        .height = 5,
        .weight = 73,
        .description = COMPOUND_STRING(
            "Forests where Swadloon live have\n"
            "superb foliage because the nutrients\n"
            "they make from fallen leaves nourish\n"
            "the plant life."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swadloon, 56, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Swadloon,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Swadloon, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Swadloon),
        ICON(Swadloon, 1),
        .footprint = gMonFootprint_Swadloon,
        LEARNSETS(Swadloon),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_LEAVANNY}),
    },

    [SPECIES_LEAVANNY] =
    {
        .baseHP        = 75,
        .baseAttack    = 103,
        .baseDefense   = 80,
        .baseSpeed     = 92,
        .baseSpAttack  = 70,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .types = { TYPE_BUG, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 225,
        .evYield_Attack = 3,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Leavanny"),
        .cryId = CRY_LEAVANNY,
        .natDexNum = NATIONAL_DEX_LEAVANNY,
        .categoryName = _("Nurturing"),
        .height = 12,
        .weight = 205,
        .description = COMPOUND_STRING(
            "It keeps its eggs warm with heat from\n"
            "fermenting leaves. It also uses leaves to\n"
            "weave warm wrappings for Sewaddle by\n"
            "using the silk secreted from its mouth."),
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Leavanny, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Leavanny,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Leavanny, 56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Leavanny),
        ICON(Leavanny, 1),
        .footprint = gMonFootprint_Leavanny,
        LEARNSETS(Leavanny),
    },
#endif //P_FAMILY_SEWADDLE

#if P_FAMILY_VENIPEDE
    [SPECIES_VENIPEDE] =
    {
        .baseHP        = 30,
        .baseAttack    = 45,
        .baseDefense   = 59,
        .baseSpeed     = 57,
        .baseSpAttack  = 30,
        .baseSpDefense = 39,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 255,
        .expYield = 52,
        .evYield_Defense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
        #else
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
        #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Venipede"),
        .cryId = CRY_VENIPEDE,
        .natDexNum = NATIONAL_DEX_VENIPEDE,
        .categoryName = _("Centipede"),
        .height = 4,
        .weight = 53,
        .description = COMPOUND_STRING(
            "Using the feelers on its head and tail,\n"
            "it picks up vibrations in the air to\n"
            "determine its prey's location and state.\n"
            "It is brutally aggressive."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Venipede, 48, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Venipede,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Venipede, 64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Venipede),
        ICON(Venipede, 1),
        .footprint = gMonFootprint_Venipede,
        LEARNSETS(Venipede),
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_WHIRLIPEDE}),
    },

    [SPECIES_WHIRLIPEDE] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 99,
        .baseSpeed     = 47,
        .baseSpAttack  = 40,
        .baseSpDefense = 79,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 120,
        .expYield = 126,
        .evYield_Defense = 2,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
        #else
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
        #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Whirlipede"),
        .cryId = CRY_WHIRLIPEDE,
        .natDexNum = NATIONAL_DEX_WHIRLIPEDE,
        .categoryName = _("Curlipede"),
        .height = 12,
        .weight = 585,
        .description = COMPOUND_STRING(
            "Storing energy for evolution, it sits.\n"
            "But when attacked, it spins its body at\n"
            "high speed like a wheel and then\n"
            "crashes furiously into its opponent."),
        .pokemonScale = 282,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Whirlipede, 56, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Whirlipede,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(Whirlipede, 64, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Whirlipede),
        ICON(Whirlipede, 2),
        .footprint = gMonFootprint_Whirlipede,
        LEARNSETS(Whirlipede),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SCOLIPEDE}),
    },

    [SPECIES_SCOLIPEDE] =
    {
        .baseHP        = 60,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 100 : 90,
        .baseDefense   = 89,
        .baseSpeed     = 112,
        .baseSpAttack  = 55,
        .baseSpDefense = 69,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 45,
        .expYield = 218,
        .evYield_Speed = 3,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
        #else
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
        #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Scolipede"),
        .cryId = CRY_SCOLIPEDE,
        .natDexNum = NATIONAL_DEX_SCOLIPEDE,
        .categoryName = _("Megapede"),
        .height = 25,
        .weight = 2005,
        .description = COMPOUND_STRING(
            "With quick movements, it chases down\n"
            "its foes, attacking relentlessly with its\n"
            "horns until it prevails. Then it finishes\n"
            "them off with deadly poison."),
        .pokemonScale = 257,
        .pokemonOffset = 2,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Scolipede, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Scolipede,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Scolipede, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Scolipede),
        ICON(Scolipede, 2),
        .footprint = gMonFootprint_Scolipede,
        LEARNSETS(Scolipede),
    },
#endif //P_FAMILY_VENIPEDE

#if P_FAMILY_COTTONEE
#if P_UPDATED_TYPES >= GEN_6
    #define COTTONEE_FAMILY_TYPES { TYPE_GRASS, TYPE_FAIRY }
#else
    #define COTTONEE_FAMILY_TYPES { TYPE_GRASS, TYPE_GRASS }
#endif

    [SPECIES_COTTONEE] =
    {
        .baseHP        = 40,
        .baseAttack    = 27,
        .baseDefense   = 60,
        .baseSpeed     = 66,
        .baseSpAttack  = 37,
        .baseSpDefense = 50,
        .types = COTTONEE_FAMILY_TYPES,
        .catchRate = 190,
        .expYield = 56,
        .evYield_Speed = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_PRANKSTER, ABILITY_INFILTRATOR, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Cottonee"),
        .cryId = CRY_COTTONEE,
        .natDexNum = NATIONAL_DEX_COTTONEE,
        .categoryName = _("Cotton Puff"),
        .height = 3,
        .weight = 6,
        .description = COMPOUND_STRING(
            "When it finds others of its kind, they all\n"
            "stick together. When enough of them\n"
            "have collected, the mass resembles a\n"
            "cumulonimbus cloud."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cottonee, 48, 32),
        .frontPicYOffset = 18,
        .frontAnimFrames = sAnims_Cottonee,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cottonee, 64, 32),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Cottonee),
        ICON(Cottonee, 1),
        .footprint = gMonFootprint_Cottonee,
        LEARNSETS(Cottonee),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_WHIMSICOTT}),
    },

    [SPECIES_WHIMSICOTT] =
    {
        .baseHP        = 60,
        .baseAttack    = 67,
        .baseDefense   = 85,
        .baseSpeed     = 116,
        .baseSpAttack  = 77,
        .baseSpDefense = 75,
        .types = COTTONEE_FAMILY_TYPES,
        .catchRate = 75,
        .expYield = 168,
        .evYield_Speed = 2,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_PRANKSTER, ABILITY_INFILTRATOR, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Whimsicott"),
        .cryId = CRY_WHIMSICOTT,
        .natDexNum = NATIONAL_DEX_WHIMSICOTT,
        .categoryName = _("Windveiled"),
        .height = 7,
        .weight = 66,
        .description = COMPOUND_STRING(
            "It rides on the wind and slips into\n"
            "people's homes. After it has turned a\n"
            "room into a cotton-filled mess, it giggles\n"
            "to itself and takes off."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Whimsicott, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Whimsicott,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Whimsicott, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Whimsicott),
        ICON(Whimsicott, 1),
        .footprint = gMonFootprint_Whimsicott,
        LEARNSETS(Whimsicott),
    },
#endif //P_FAMILY_COTTONEE

#if P_FAMILY_PETILIL
    [SPECIES_PETILIL] =
    {
        .baseHP        = 45,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 56,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_OWN_TEMPO, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Petilil"),
        .cryId = CRY_PETILIL,
        .natDexNum = NATIONAL_DEX_PETILIL,
        .categoryName = _("Bulb"),
        .height = 5,
        .weight = 66,
        .description = COMPOUND_STRING(
            "By pruning the leaves on its head with\n"
            "regularity, this Pokémon can be grown\n"
            "into a fine plump shape. These bitter\n"
            "leaves refresh those who eat them."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Petilil, 32, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Petilil,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .enemyMonElevation = 7,
        BACK_PIC(Petilil, 40, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Petilil),
        ICON(Petilil, 1),
        .footprint = gMonFootprint_Petilil,
        LEARNSETS(Petilil),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_LILLIGANT},
                                {EVO_NONE, 0, SPECIES_LILLIGANT_HISUIAN}),
    },

#define LILLIGANT_MISC_INFO                                 \
        .catchRate = 75,                                    \
        .expYield = 168,                                    \
        .itemRare = ITEM_ABSORB_BULB,                       \
        .genderRatio = MON_FEMALE,                          \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },  \
        .bodyColor = BODY_COLOR_GREEN,                      \
        .noFlip = TRUE,                                     \
        .speciesName = _("Lilligant"),                      \
        .cryId = CRY_LILLIGANT,                             \
        .natDexNum = NATIONAL_DEX_LILLIGANT,                \
        .footprint = gMonFootprint_Lilligant,               \
        .formSpeciesIdTable = sLilligantFormSpeciesIdTable

    [SPECIES_LILLIGANT] =
    {
        LILLIGANT_MISC_INFO,
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 90,
        .baseSpAttack  = 110,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .evYield_SpAttack = 2,
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_OWN_TEMPO, ABILITY_LEAF_GUARD },
        .categoryName = _("Flowering"),
        .height = 11,
        .weight = 163,
        .description = COMPOUND_STRING(
            "Even veteran Trainers face a challenge\n"
            "in getting its beautiful flower to bloom.\n"
            "It withers away if a trainer does not\n"
            "take good care of it."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lilligant, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Lilligant,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Lilligant, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Lilligant),
        ICON(Lilligant, 1),
        LEARNSETS(Lilligant),
    },

#if P_HISUIAN_FORMS
    [SPECIES_LILLIGANT_HISUIAN] =
    {
        LILLIGANT_MISC_INFO,
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 105,
        .baseSpAttack  = 50,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_HUSTLE, ABILITY_LEAF_GUARD },
        .categoryName = _("Spinning"),
        .height = 12,
        .weight = 192,
        .description = COMPOUND_STRING(
            "Its well-developed legs are the result of\n"
            "a life spent on mountains covered in deep\n"
            "snow. The scent it exudes from its flower\n"
            "crown heartens those in proximity."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(LilligantHisuian, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_LilligantHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(LilligantHisuian, 56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(LilligantHisuian),
        ICON(LilligantHisuian, 1),
        LEARNSETS(LilligantHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_PETILIL

#if P_FAMILY_BASCULIN
#define BASCULIN_MISC_INFO                                      \
        .baseHP        = 70,                                    \
        .baseAttack    = 92,                                    \
        .baseDefense   = 65,                                    \
        .baseSpeed     = 98,                                    \
        .baseSpAttack  = 80,                                    \
        .baseSpDefense = 55,                                    \
        .types = { TYPE_WATER, TYPE_WATER },                    \
        .catchRate = 190,                                       \
        .expYield = 161,                                        \
        .evYield_Speed = 2,                                     \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },  \
        .bodyColor = BODY_COLOR_GREEN,                          \
        .speciesName = _("Basculin"),                           \
        .cryId = CRY_BASCULIN,                                  \
        .natDexNum = NATIONAL_DEX_BASCULIN,                     \
        .height = 10,                                           \
        .weight = 180,                                          \
        .pokemonScale = 316,                                    \
        .pokemonOffset = 7,                                     \
        .trainerScale = 257,                                    \
        .trainerOffset = 0,                                     \
        .enemyMonElevation = 6,                                 \
        .footprint = gMonFootprint_Basculin,                    \
        .formSpeciesIdTable = sBasculinFormSpeciesIdTable

    [SPECIES_BASCULIN_RED_STRIPED] =
    {
        BASCULIN_MISC_INFO,
        .itemRare = ITEM_DEEP_SEA_TOOTH,
        .abilities = { ABILITY_RECKLESS, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .categoryName = _("Hostile"),
        .description = COMPOUND_STRING(
            "It used to be a common food source. The\n"
            "meat of red Basculin is on the fatty side\n"
            "and it's more popular with the youth.\n"
            "Its temperament is vicious and aggressive."),
        FRONT_PIC(BasculinRedStriped, 56, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(BasculinRedStriped, 64, 48),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(BasculinRedStriped),
        ICON(BasculinRedStriped, 1),
        LEARNSETS(Basculin),
    },

    [SPECIES_BASCULIN_BLUE_STRIPED] =
    {
        BASCULIN_MISC_INFO,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .categoryName = _("Hostile"),
        .description = COMPOUND_STRING(
            "They form schools with others of the same\n"
            "color. The greatest foe of a school of blue\n"
            "Basculin is a school of red Basculin.\n"
            "Its flavor is light and inoffensive."),
        FRONT_PIC(BasculinBlueStriped, 56, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(BasculinBlueStriped, 64, 48),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(BasculinBlueStriped),
        ICON(BasculinBlueStriped, 0),
        LEARNSETS(Basculin),
    },

#if P_HISUIAN_FORMS
    [SPECIES_BASCULIN_WHITE_STRIPED] =
    {
        BASCULIN_MISC_INFO,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .abilities = { ABILITY_RATTLED, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .categoryName = _("Mellow"),
        .description = COMPOUND_STRING(
            "While this ancient form of Basculin shares\n"
            "a vast array of qualities with other forms,\n"
            "it differs in several respects, including\n"
            "demeanor, being much gentler than others."),
        FRONT_PIC(BasculinWhiteStriped, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(BasculinWhiteStriped, 64, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(BasculinWhiteStriped),
        ICON(BasculinWhiteStriped, 0),
        LEARNSETS(BasculinWhiteStriped),
        .evolutions = EVOLUTION({EVO_NONE, 0, SPECIES_BASCULEGION_MALE},
                                {EVO_NONE, 0, SPECIES_BASCULEGION_FEMALE}),
    },

#define BASCULEGION_MISC_INFO                                                               \
        .types = { TYPE_WATER, TYPE_GHOST },                                                \
        .catchRate = 45,                                                                    \
        .expYield = 265,                                                                    \
        .evYield_HP = 3,                                                                    \
        .eggCycles = 20,                                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                                   \
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },                              \
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },    \
        .bodyColor = BODY_COLOR_GREEN,                                                      \
        .speciesName = _("Bsculegion"),                                                     \
        .cryId = CRY_BASCULEGION,                                                           \
        .natDexNum = NATIONAL_DEX_BASCULEGION,                                              \
        .categoryName = _("Big Fish"),                                                      \
        .height = 30,                                                                       \
        .weight = 1100,                                                                     \
        .pokemonScale = 275,                                                                \
        .pokemonOffset = 7,                                                                 \
        .trainerScale = 256,                                                                \
        .trainerOffset = 0,                                                                 \
        .frontAnimFrames = sAnims_Basculegion,                                              \
        .frontPicYOffset = 0,                                                               \
        .enemyMonElevation = 5,                                                             \
        .backPicYOffset = 8,                                                                \
        LEARNSETS(Basculegion),                                                             \
        .formSpeciesIdTable = sBasculegionFormSpeciesIdTable
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        //.backAnimId = BACK_ANIM_NONE,
        //.footprint = gMonFootprint_Basculegion,

    [SPECIES_BASCULEGION_MALE] =
    {
        BASCULEGION_MISC_INFO,
        .baseHP        = 120,
        .baseAttack    = 112,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .genderRatio = MON_MALE,
        .description = COMPOUND_STRING(
            "Clads itself in the souls of comrades that\n"
            "perished before fulfilling their goals of\n"
            "journeying upstream. No other species in\n"
            "all Hisui's rivers is Basculegion's equal."),
        FRONT_PIC(BasculegionMale, 64, 64),
        BACK_PIC(BasculegionMale, 64, 64),
        PALETTES(BasculegionMale),
        ICON(BasculegionMale, 1),
    },

    [SPECIES_BASCULEGION_FEMALE] =
    {
        BASCULEGION_MISC_INFO,
        .baseHP        = 120,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .genderRatio = MON_FEMALE,
        .description = COMPOUND_STRING(
            "The souls of its comrades cloak its\n"
            "body and propel it effortlessly\n"
            "through even raging rapids."),
        FRONT_PIC(BasculegionFemale, 64, 64),
        BACK_PIC(BasculegionFemale, 64, 64),
        PALETTES(BasculegionFemale),
        ICON(BasculegionFemale, 0),
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_BASCULIN

#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] =
    {
        .baseHP        = 50,
        .baseAttack    = 72,
        .baseDefense   = 35,
        .baseSpeed     = 65,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = { TYPE_GROUND, TYPE_DARK },
        .catchRate = 180,
        .expYield = 58,
        .evYield_Attack = 1,
        .itemRare = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Sandile"),
        .cryId = CRY_SANDILE,
        .natDexNum = NATIONAL_DEX_SANDILE,
        .categoryName = _("Desert Croc"),
        .height = 7,
        .weight = 152,
        .description = COMPOUND_STRING(
            "It conceals itself in the sand and\n"
            "chomps down on the legs of any prey\n"
            "that unwarily walk over it. Its favorite\n"
            "food is Trapinch."),
        .pokemonScale = 365,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sandile, 48, 32),
        .frontPicYOffset = 18,
        .frontAnimFrames = sAnims_Sandile,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sandile, 64, 32),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Sandile),
        ICON(Sandile, 1),
        .footprint = gMonFootprint_Sandile,
        LEARNSETS(Sandile),
        .evolutions = EVOLUTION({EVO_LEVEL, 29, SPECIES_KROKOROK}),
    },

    [SPECIES_KROKOROK] =
    {
        .baseHP        = 60,
        .baseAttack    = 82,
        .baseDefense   = 45,
        .baseSpeed     = 74,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_GROUND, TYPE_DARK },
        .catchRate = 90,
        .expYield = 123,
        .evYield_Attack = 2,
        .itemRare = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Krokorok"),
        .cryId = CRY_KROKOROK,
        .natDexNum = NATIONAL_DEX_KROKOROK,
        .categoryName = _("Desert Croc"),
        .height = 10,
        .weight = 334,
        .description = COMPOUND_STRING(
            "They move in groups of a few individuals.\n"
            "Thanks to the special membrane covering\n"
            "its eyes, it can see its surroundings\n"
            "clearly, even in the dead of night."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Krokorok, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Krokorok,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Krokorok, 56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Krokorok),
        ICON(Krokorok, 1),
        .footprint = gMonFootprint_Krokorok,
        LEARNSETS(Krokorok),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_KROOKODILE}),
    },

    [SPECIES_KROOKODILE] =
    {
        .baseHP        = 95,
        .baseAttack    = 117,
        .baseDefense   = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .baseSpeed     = 92,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = { TYPE_GROUND, TYPE_DARK },
        .catchRate = 45,
        .expYield = 234,
        .evYield_Attack = 3,
        .itemCommon = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Krookodile"),
        .cryId = CRY_KROOKODILE,
        .natDexNum = NATIONAL_DEX_KROOKODILE,
        .categoryName = _("Intimidate"),
        .height = 15,
        .weight = 963,
        .description = COMPOUND_STRING(
            "Very violent Pokémon, they never allow\n"
            "their prey to escape. Their jaws are so\n"
            "powerful, they can crush the body of\n"
            "an automobile."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Krookodile, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Krookodile,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        BACK_PIC(Krookodile, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Krookodile),
        ICON(Krookodile, 0),
        .footprint = gMonFootprint_Krookodile,
        LEARNSETS(Krookodile),
    },
#endif //P_FAMILY_SANDILE

#if P_FAMILY_DARUMAKA
#define DARUMAKA_MISC_INFO                                                  \
        .baseHP        = 70,                                                \
        .baseAttack    = 90,                                                \
        .baseDefense   = 45,                                                \
        .baseSpeed     = 50,                                                \
        .baseSpAttack  = 15,                                                \
        .baseSpDefense = 45,                                                \
        .catchRate = 120,                                                   \
        .expYield = 63,                                                     \
        .evYield_Attack = 1,                                                \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                  \
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE, ABILITY_INNER_FOCUS }, \
        .speciesName = _("Darumaka"),                                       \
        .cryId = CRY_DARUMAKA,                                              \
        .natDexNum = NATIONAL_DEX_DARUMAKA,                                 \
        .categoryName = _("Zen Charm"),                                     \
        .footprint = gMonFootprint_Darumaka,                                \
        .formSpeciesIdTable = sDarumakaFormSpeciesIdTable

    [SPECIES_DARUMAKA] =
    {
        DARUMAKA_MISC_INFO,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .bodyColor = BODY_COLOR_RED,
        .height = 6,
        .weight = 375,
        .description = COMPOUND_STRING(
            "When its internal fire is burning, it\n"
            "cannot calm down and it runs around.\n"
            "When the fire diminishes, it pulls its\n"
            "limbs into its body and falls asleep."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Darumaka, 40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Darumaka,
        .frontAnimId = ANIM_SWING_CONCAVE,
        BACK_PIC(Darumaka, 56, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Darumaka),
        ICON(Darumaka, 0),
        LEARNSETS(Darumaka),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_DARMANITAN_STANDARD_MODE}),
    },

#define DARMANITAN_MISC_INFO                                \
        .catchRate = 60,                                    \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .speciesName = _("Darmanitan"),                     \
        .cryId = CRY_DARMANITAN,                            \
        .natDexNum = NATIONAL_DEX_DARMANITAN,               \
        .footprint = gMonFootprint_Darmanitan,              \
        .formSpeciesIdTable = sDarmanitanFormSpeciesIdTable

#define DARMANITAN_STANDARD_MISC_INFO   \
        .baseHP        = 105,           \
        .baseAttack    = 140,           \
        .baseDefense   = 55,            \
        .baseSpeed     = 95,            \
        .baseSpAttack  = 30,            \
        .baseSpDefense = 55,            \
        .expYield = 168,                \
        .evYield_Attack = 2,            \
        DARMANITAN_MISC_INFO

#define DARMANITAN_ZEN_MODE_MISC_INFO   \
        .expYield = 189,                \
        .evYield_SpAttack = 2,          \
        .categoryName = _("Blazing"),   \
        DARMANITAN_MISC_INFO

#define DARMANITAN_UNOVAN_MISC_INFO                                         \
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_ZEN_MODE },\
        .height = 13,                                                       \
        .weight = 929,                                                      \
        .pokemonScale = 272,                                                \
        .pokemonOffset = 3,                                                 \
        .trainerScale = 256,                                                \
        .trainerOffset = 0,                                                 \
        LEARNSETS(Darmanitan),                                              \
        .formChangeTable = sDarmanitanFormChangeTable

    [SPECIES_DARMANITAN_STANDARD_MODE] =
    {
        DARMANITAN_STANDARD_MISC_INFO,
        DARMANITAN_UNOVAN_MISC_INFO,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .bodyColor = BODY_COLOR_RED,
        .categoryName = _("Blazing"),
        .description = COMPOUND_STRING(
            "When one is injured in a fierce battle,\n"
            "it transforms into a stone statue.\n"
            "Then it meditates and sharpens its\n"
            "mind and fights on mentally."),
        FRONT_PIC(DarmanitanStandardMode, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_DarmanitanStandardMode,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(DarmanitanStandardMode, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(DarmanitanStandardMode),
        ICON(DarmanitanStandardMode, 0),
    },

    [SPECIES_DARMANITAN_ZEN_MODE] =
    {
        DARMANITAN_ZEN_MODE_MISC_INFO,
        DARMANITAN_UNOVAN_MISC_INFO,
        .baseHP        = 105,
        .baseAttack    = 30,
        .baseDefense   = 105,
        .baseSpeed     = 55,
        .baseSpAttack  = 140,
        .baseSpDefense = 105,
        .types = { TYPE_FIRE, TYPE_PSYCHIC },
        .bodyColor = BODY_COLOR_BLUE,
        .description = COMPOUND_STRING(
            "When wounded, it stops moving. It\n"
            "goes as still as stone to meditate,\n"
            "sharpening its mind and spirit."),
        FRONT_PIC(DarmanitanZenMode, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_DarmanitanZenMode,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(DarmanitanZenMode, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(DarmanitanZenMode),
        ICON(DarmanitanZenMode, 0),
    },

#if P_GALARIAN_FORMS
    [SPECIES_DARUMAKA_GALARIAN] =
    {
        DARUMAKA_MISC_INFO,
        .types = { TYPE_ICE, TYPE_ICE },
        .bodyColor = BODY_COLOR_WHITE,
        .height = 7,
        .weight = 400,
        .description = COMPOUND_STRING(
            "The colder they get, the more\n"
            "energetic they are. They freeze their\n"
            "breath to make snowballs, using them\n"
            "as ammo for playful snowball fights."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(DarumakaGalarian, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_DarumakaGalarian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DarumakaGalarian, 56, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DarumakaGalarian),
        ICON(DarumakaGalarian, 0),
        LEARNSETS(DarumakaGalarian),
        .isGalarianForm = TRUE,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_ICE_STONE, SPECIES_DARMANITAN_GALARIAN_STANDARD_MODE}),
    },

#define DARMANITAN_GALARIAN_MISC_INFO                                           \
        .abilities = { ABILITY_GORILLA_TACTICS, ABILITY_NONE, ABILITY_ZEN_MODE },\
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .height = 17,                                                           \
        .weight = 1200,                                                         \
        .pokemonScale = 272,                                                    \
        .pokemonOffset = 3,                                                     \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        LEARNSETS(DarmanitanGalarian),                                          \
        .formChangeTable = sDarmanitanGalarianFormChangeTable,                  \
        .isGalarianForm = TRUE

    [SPECIES_DARMANITAN_GALARIAN_STANDARD_MODE] =
    {
        DARMANITAN_GALARIAN_MISC_INFO,
        DARMANITAN_STANDARD_MISC_INFO,
        .types = { TYPE_ICE, TYPE_ICE },
        .categoryName = _("Zen Charm"),
        .description = COMPOUND_STRING(
            "On days when blizzards blow\n"
            "through, it comes down to where people\n"
            "live. It stashes food in the snowball on\n"
            "its head, taking it home for later."),
        FRONT_PIC(DarmanitanGalarianStandardMode, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DarmanitanGalarianStandardMode,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DarmanitanGalarianStandardMode, 56, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DarmanitanGalarianStandardMode),
        ICON(DarmanitanGalarianStandardMode, 0),
    },

    [SPECIES_DARMANITAN_GALARIAN_ZEN_MODE] =
    {
        DARMANITAN_GALARIAN_MISC_INFO,
        DARMANITAN_ZEN_MODE_MISC_INFO,
        .baseHP        = 105,
        .baseAttack    = 160,
        .baseDefense   = 55,
        .baseSpeed     = 135,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = { TYPE_ICE, TYPE_FIRE },
        .description = COMPOUND_STRING(
            "Darmanitan takes this form when\n"
            "enraged. It won't stop spewing flames\n"
            "until its rage has settled, even if\n"
            "its body starts to melt."),
        FRONT_PIC(DarmanitanGalarianZenMode, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_DarmanitanGalarianZenMode,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DarmanitanGalarianZenMode, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DarmanitanGalarianZenMode),
        ICON(DarmanitanGalarianZenMode, 0),
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_DARUMAKA

#if P_FAMILY_MARACTUS
    [SPECIES_MARACTUS] =
    {
        .baseHP        = 75,
        .baseAttack    = 86,
        .baseDefense   = 67,
        .baseSpeed     = 60,
        .baseSpAttack  = 106,
        .baseSpDefense = 67,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 255,
        .expYield = 161,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CHLOROPHYLL, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Maractus"),
        .cryId = CRY_MARACTUS,
        .natDexNum = NATIONAL_DEX_MARACTUS,
        .categoryName = _("Cactus"),
        .height = 10,
        .weight = 280,
        .description = COMPOUND_STRING(
            "Arid regions are their habitat.\n"
            "When it moves rhythmically, it makes a\n"
            "sound similar to maracas, making the\n"
            "surprised Pokémon flee."),
        .pokemonScale = 305,
        .pokemonOffset = 6,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Maractus, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Maractus,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Maractus, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Maractus),
        ICON(Maractus, 1),
        .footprint = gMonFootprint_Maractus,
        LEARNSETS(Maractus),
    },
#endif //P_FAMILY_MARACTUS

#if P_FAMILY_DWEBBLE
    [SPECIES_DWEBBLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = { TYPE_BUG, TYPE_ROCK },
        .catchRate = 190,
        .expYield = 65,
        .evYield_Defense = 1,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Dwebble"),
        .cryId = CRY_DWEBBLE,
        .natDexNum = NATIONAL_DEX_DWEBBLE,
        .categoryName = _("Rock Inn"),
        .height = 3,
        .weight = 145,
        .description = COMPOUND_STRING(
            "It makes a hole in a stone of a suitable\n"
            "size. If that rock breaks, the Pokémon\n"
            "remains agitated until it locates\n"
            "a replacement."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dwebble, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Dwebble,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Dwebble, 56, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Dwebble),
        ICON(Dwebble, 0),
        .footprint = gMonFootprint_Dwebble,
        LEARNSETS(Dwebble),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_CRUSTLE}),
    },

    [SPECIES_CRUSTLE] =
    {
        .baseHP        = 70,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 105 : 95,
        .baseDefense   = 125,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = { TYPE_BUG, TYPE_ROCK },
        .catchRate = 75,
        .expYield = 170,
        .evYield_Defense = 2,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Crustle"),
        .cryId = CRY_CRUSTLE,
        .natDexNum = NATIONAL_DEX_CRUSTLE,
        .categoryName = _("Stone Home"),
        .height = 14,
        .weight = 2000,
        .description = COMPOUND_STRING(
            "Competing for territory, Crustle fight\n"
            "viciously. The one whose boulder is\n"
            "broken is the loser of the battle and\n"
            "begins to weaken."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Crustle, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Crustle,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Crustle, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Crustle),
        ICON(Crustle, 2),
        .footprint = gMonFootprint_Crustle,
        LEARNSETS(Crustle),
    },
#endif //P_FAMILY_DWEBBLE

#if P_FAMILY_SCRAGGY
    [SPECIES_SCRAGGY] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 48,
        .baseSpAttack  = 35,
        .baseSpDefense = 70,
        .types = { TYPE_DARK, TYPE_FIGHTING },
        .catchRate = 180,
        .expYield = 70,
        .evYield_Attack = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_MOXIE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Scraggy"),
        .cryId = CRY_SCRAGGY,
        .natDexNum = NATIONAL_DEX_SCRAGGY,
        .categoryName = _("Shedding"),
        .height = 6,
        .weight = 118,
        .description = COMPOUND_STRING(
            "Its skin has a rubbery elasticity, so it\n"
            "can reduce damage by defensively\n"
            "pulling its skin up to its neck.\n"
            "Its skull is massively thick."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Scraggy, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Scraggy,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Scraggy, 48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Scraggy),
        ICON(Scraggy, 2),
        .footprint = gMonFootprint_Scraggy,
        LEARNSETS(Scraggy),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_SCRAFTY}),
    },

    [SPECIES_SCRAFTY] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 115,
        .baseSpeed     = 58,
        .baseSpAttack  = 45,
        .baseSpDefense = 115,
        .types = { TYPE_DARK, TYPE_FIGHTING },
        .catchRate = 90,
        .expYield = 171,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_MOXIE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Scrafty"),
        .cryId = CRY_SCRAFTY,
        .natDexNum = NATIONAL_DEX_SCRAFTY,
        .categoryName = _("Hoodlum"),
        .height = 11,
        .weight = 300,
        .description = COMPOUND_STRING(
            "Groups of them beat up anything that\n"
            "enters their territory. The one with the\n"
            "biggest crest is the group leader, and\n"
            "is the most respected."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Scrafty, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Scrafty,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Scrafty, 48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Scrafty),
        ICON(Scrafty, 0),
        .footprint = gMonFootprint_Scrafty,
        LEARNSETS(Scrafty),
    },
#endif //P_FAMILY_SCRAGGY

#if P_FAMILY_SIGILYPH
    [SPECIES_SIGILYPH] =
    {
        .baseHP        = 72,
        .baseAttack    = 58,
        .baseDefense   = 80,
        .baseSpeed     = 97,
        .baseSpAttack  = 103,
        .baseSpDefense = 80,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 172,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_WONDER_SKIN, ABILITY_MAGIC_GUARD, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Sigilyph"),
        .cryId = CRY_SIGILYPH,
        .natDexNum = NATIONAL_DEX_SIGILYPH,
        .categoryName = _("Avianoid"),
        .height = 14,
        .weight = 140,
        .description = COMPOUND_STRING(
            "The guardians of an ancient city, they\n"
            "always fly the same route while keeping\n"
            "watch for invaders. They use their\n"
            "psychic power to attack enemies."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Sigilyph, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Sigilyph,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(Sigilyph, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Sigilyph),
        ICON(Sigilyph, 0),
        .footprint = gMonFootprint_Sigilyph,
        LEARNSETS(Sigilyph),
    },
#endif //P_FAMILY_SIGILYPH

#if P_FAMILY_YAMASK
#define YAMASK_MISC_INFO                                            \
        .catchRate = 190,                                           \
        .expYield = 61,                                             \
        .evYield_Defense = 1,                                       \
        .genderRatio = PERCENT_FEMALE(50),                          \
        .eggCycles = 25,                                            \
        .friendship = STANDARD_FRIENDSHIP,                          \
        .growthRate = GROWTH_MEDIUM_FAST,                           \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },    \
        .bodyColor = BODY_COLOR_BLACK,                              \
        .speciesName = _("Yamask"),                                 \
        .cryId = CRY_YAMASK,                                        \
        .natDexNum = NATIONAL_DEX_YAMASK,                           \
        .categoryName = _("Spirit"),                                \
        .height = 5,                                                \
        .weight = 15,                                               \
        .pokemonScale = 432,                                        \
        .pokemonOffset = 13,                                        \
        .trainerScale = 256,                                        \
        .trainerOffset = 0,                                         \
        .footprint = gMonFootprint_Yamask,                          \
        .formSpeciesIdTable = sYamaskFormSpeciesIdTable

    [SPECIES_YAMASK] =
    {
        YAMASK_MISC_INFO,
        .baseHP        = 38,
        .baseAttack    = 30,
        .baseDefense   = 85,
        .baseSpeed     = 30,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .itemRare = ITEM_SPELL_TAG,
        .abilities = { ABILITY_MUMMY, ABILITY_NONE },
        .description = COMPOUND_STRING(
            "These Pokémon arose from the spirits\n"
            "of people interred in graves in past ages.\n"
            "Each of them carries a mask that used\n"
            "to be its face when it was human."),
        FRONT_PIC(Yamask, 48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Yamask,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        BACK_PIC(Yamask, 40, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Yamask),
        ICON(Yamask, 0),
        LEARNSETS(Yamask),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_COFAGRIGUS}),
    },

    [SPECIES_COFAGRIGUS] =
    {
        .baseHP        = 58,
        .baseAttack    = 50,
        .baseDefense   = 145,
        .baseSpeed     = 30,
        .baseSpAttack  = 95,
        .baseSpDefense = 105,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_MUMMY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Cofagrigus"),
        .cryId = CRY_COFAGRIGUS,
        .natDexNum = NATIONAL_DEX_COFAGRIGUS,
        .categoryName = _("Coffin"),
        .height = 17,
        .weight = 765,
        .description = COMPOUND_STRING(
            "Grave robbers who mistake them for\n"
            "real coffins and get too close end up\n"
            "trapped inside their bodies. Their bodies\n"
            "are covered in pure gold."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Cofagrigus, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cofagrigus,
        .frontAnimId = ANIM_GLOW_BLACK,
        BACK_PIC(Cofagrigus, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Cofagrigus),
        ICON(Cofagrigus, 0),
        .footprint = gMonFootprint_Cofagrigus,
        LEARNSETS(Cofagrigus),
    },

#if P_GALARIAN_FORMS
    [SPECIES_YAMASK_GALARIAN] =
    {
        YAMASK_MISC_INFO,
        .baseHP        = 38,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .abilities = { ABILITY_WANDERING_SPIRIT, ABILITY_NONE },
        .description = COMPOUND_STRING(
            "A clay slab with cursed engravings\n"
            "took possession of a Yamask. The\n"
            "slab is said to be absorbing the\n"
            "Yamask's dark power."),
        FRONT_PIC(YamaskGalarian, 48, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_YamaskGalarian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 4,
        BACK_PIC(YamaskGalarian, 40, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(YamaskGalarian),
        ICON(YamaskGalarian, 2),
        LEARNSETS(YamaskGalarian),
        .isGalarianForm = TRUE,
        .evolutions = EVOLUTION({EVO_SCRIPT_TRIGGER_DMG, 49, SPECIES_RUNERIGUS}),
    },

    [SPECIES_RUNERIGUS] =
    {
        .baseHP        = 58,
        .baseAttack    = 95,
        .baseDefense   = 145,
        .baseSpeed     = 30,
        .baseSpAttack  = 50,
        .baseSpDefense = 105,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WANDERING_SPIRIT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Runerigus"),
        .cryId = CRY_RUNERIGUS,
        .natDexNum = NATIONAL_DEX_RUNERIGUS,
        .categoryName = _("Grudge"),
        .height = 16,
        .weight = 666,
        .description = COMPOUND_STRING(
            "A powerful curse was woven into an ancient\n"
            "painting. After absorbing the spirit of\n"
            "a Yamask, the painting began to move."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Runerigus, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Runerigus,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(Runerigus, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Runerigus),
        ICON(Runerigus, 2),
        .footprint = gMonFootprint_Runerigus,
        LEARNSETS(Runerigus),
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_YAMASK

#if P_FAMILY_TIRTOUGA
    [SPECIES_TIRTOUGA] =
    {
        .baseHP        = 54,
        .baseAttack    = 78,
        .baseDefense   = 103,
        .baseSpeed     = 22,
        .baseSpAttack  = 53,
        .baseSpDefense = 45,
        .types = { TYPE_WATER, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 71,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_SOLID_ROCK, ABILITY_STURDY, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Tirtouga"),
        .cryId = CRY_TIRTOUGA,
        .natDexNum = NATIONAL_DEX_TIRTOUGA,
        .categoryName = _("Prototurtle"),
        .height = 7,
        .weight = 165,
        .description = COMPOUND_STRING(
            "Reputed to be the ancestor of most\n"
            "turtle Pokémon, it lived in warm seas\n"
            "about a hundred million years ago.\n"
            "It was restored from a fossil."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tirtouga, 56, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Tirtouga,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Tirtouga, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Tirtouga),
        ICON(Tirtouga, 2),
        .footprint = gMonFootprint_Tirtouga,
        LEARNSETS(Tirtouga),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_CARRACOSTA}),
    },

    [SPECIES_CARRACOSTA] =
    {
        .baseHP        = 74,
        .baseAttack    = 108,
        .baseDefense   = 133,
        .baseSpeed     = 32,
        .baseSpAttack  = 83,
        .baseSpDefense = 65,
        .types = { TYPE_WATER, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 173,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_SOLID_ROCK, ABILITY_STURDY, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Carracosta"),
        .cryId = CRY_CARRACOSTA,
        .natDexNum = NATIONAL_DEX_CARRACOSTA,
        .categoryName = _("Prototurtle"),
        .height = 12,
        .weight = 810,
        .description = COMPOUND_STRING(
            "They can live both in the ocean and\n"
            "on land. Incredible jaw strength enables\n"
            "them to chew up steel beams and rocks\n"
            "along with their prey."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Carracosta, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Carracosta,
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        BACK_PIC(Carracosta, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Carracosta),
        ICON(Carracosta, 2),
        .footprint = gMonFootprint_Carracosta,
        LEARNSETS(Carracosta),
    },
#endif //P_FAMILY_TIRTOUGA

#if P_FAMILY_ARCHEN
    [SPECIES_ARCHEN] =
    {
        .baseHP        = 55,
        .baseAttack    = 112,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 74,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 71,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_DEFEATIST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Archen"),
        .cryId = CRY_ARCHEN,
        .natDexNum = NATIONAL_DEX_ARCHEN,
        .categoryName = _("First Bird"),
        .height = 5,
        .weight = 95,
        .description = COMPOUND_STRING(
            "Said to be the ancestor of all bird\n"
            "Pokémon, Archen itself could not actually\n"
            "fly but moved by hopping from treetop\n"
            "to treetop."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Archen, 56, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Archen,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Archen, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Archen),
        ICON(Archen, 0),
        .footprint = gMonFootprint_Archen,
        LEARNSETS(Archen),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_ARCHEOPS}),
    },

    [SPECIES_ARCHEOPS] =
    {
        .baseHP        = 75,
        .baseAttack    = 140,
        .baseDefense   = 65,
        .baseSpeed     = 110,
        .baseSpAttack  = 112,
        .baseSpDefense = 65,
        .types = { TYPE_ROCK, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_DEFEATIST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Archeops"),
        .cryId = CRY_ARCHEOPS,
        .natDexNum = NATIONAL_DEX_ARCHEOPS,
        .categoryName = _("First Bird"),
        .height = 14,
        .weight = 320,
        .description = COMPOUND_STRING(
            "They are intelligent and will cooperate\n"
            "to catch prey. When one Archeops\n"
            "had the prey cornered, another would\n"
            "swoop on it."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Archeops, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Archeops,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 11,
        BACK_PIC(Archeops, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Archeops),
        ICON(Archeops, 0),
        .footprint = gMonFootprint_Archeops,
        LEARNSETS(Archeops),
    },
#endif //P_FAMILY_ARCHEN

#if P_FAMILY_TRUBBISH
    [SPECIES_TRUBBISH] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 62,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 62,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 190,
        .expYield = 66,
        .evYield_Speed = 1,
        .itemRare = ITEM_SILK_SCARF,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STENCH, ABILITY_STICKY_HOLD, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Trubbish"),
        .cryId = CRY_TRUBBISH,
        .natDexNum = NATIONAL_DEX_TRUBBISH,
        .categoryName = _("Trash Bag"),
        .height = 6,
        .weight = 310,
        .description = COMPOUND_STRING(
            "It gorges on trash until its stomach\n"
            "is full. Then it belches toxic gas.\n"
            "An unlucky whiff of this gas will put\n"
            "a person in the hospital."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Trubbish, 48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Trubbish,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Trubbish, 48, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Trubbish),
        ICON(Trubbish, 1),
        .footprint = gMonFootprint_Trubbish,
        LEARNSETS(Trubbish),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GARBODOR}),
    },

#define GARBODOR_MISC_INFO                                                      \
        .baseHP        = 80,                                                    \
        .baseAttack    = 95,                                                    \
        .baseDefense   = 82,                                                    \
        .baseSpeed     = 75,                                                    \
        .baseSpAttack  = 60,                                                    \
        .baseSpDefense = 82,                                                    \
        .types = { TYPE_POISON, TYPE_POISON },                                  \
        .catchRate = 60,                                                        \
        .expYield = 166,                                                        \
        .evYield_Attack = 2,                                                    \
        .itemCommon = ITEM_SILK_SCARF,                                          \
        .itemRare = ITEM_BLACK_SLUDGE,                                          \
        .genderRatio = PERCENT_FEMALE(50),                                      \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },                  \
        .abilities = { ABILITY_STENCH, ABILITY_WEAK_ARMOR, ABILITY_AFTERMATH }, \
        .bodyColor = BODY_COLOR_GREEN,                                          \
        .noFlip = TRUE,                                                         \
        .speciesName = _("Garbodor"),                                           \
        .cryId = CRY_GARBODOR,                                                  \
        .natDexNum = NATIONAL_DEX_GARBODOR,                                     \
        .categoryName = _("Trash Heap"),                                        \
        .footprint = gMonFootprint_Garbodor,                                    \
        LEARNSETS(Garbodor),                                                    \
        .formSpeciesIdTable = sGarbodorFormSpeciesIdTable,                      \
        .formChangeTable = sGarbodorFormChangeTable

    [SPECIES_GARBODOR] =
    {
        GARBODOR_MISC_INFO,
        .height = 19,
        .weight = 1073,
        .description = COMPOUND_STRING(
            "Beware the poisonous liquid it shoots\n"
            "from its right arm. If even a little of it\n"
            "gets on you, you'll experience the full\n"
            "effects of this unidentified toxin."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(Garbodor, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Garbodor,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Garbodor, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Garbodor),
        ICON(Garbodor, 1),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_GARBODOR_GIGANTAMAX] =
    {
        GARBODOR_MISC_INFO,
        .height = 210,
        .weight = 0,
        .description = COMPOUND_STRING(
            "It sprays toxic gas from its mouth\n"
            "and fingers. If the gas engulfs you,\n"
            "the toxins will seep in all the way\n"
            "down to your bones."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(GarbodorGigantamax, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_GarbodorGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(GarbodorGigantamax, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(GarbodorGigantamax),
        ICON(GarbodorGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_TRUBBISH

#if P_FAMILY_ZORUA
#define ZORUA_MISC_INFO                                     \
        .catchRate = 75,                                    \
        .expYield = 66,                                     \
        .evYield_SpAttack = 1,                              \
        .genderRatio = PERCENT_FEMALE(12.5),                \
        .eggCycles = 25,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE },    \
        .bodyColor = BODY_COLOR_GRAY,                       \
        .speciesName = _("Zorua"),                          \
        .cryId = CRY_ZORUA,                                 \
        .natDexNum = NATIONAL_DEX_ZORUA,                    \
        .height = 7,                                        \
        .weight = 125,                                      \
        .pokemonScale = 365,                                \
        .pokemonOffset = 12,                                \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .footprint = gMonFootprint_Zorua,                   \
        .formSpeciesIdTable = sZoruaFormSpeciesIdTable

#define ZOROARK_MISC_INFO                                   \
        .catchRate = 45,                                    \
        .expYield = 179,                                    \
        .evYield_SpAttack = 2,                              \
        .genderRatio = PERCENT_FEMALE(12.5),                \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE },    \
        .bodyColor = BODY_COLOR_GRAY,                       \
        .speciesName = _("Zoroark"),                        \
        .cryId = CRY_ZOROARK,                               \
        .natDexNum = NATIONAL_DEX_ZOROARK,                  \
        .height = 16,                                       \
        .pokemonScale = 259,                                \
        .pokemonOffset = 1,                                 \
        .trainerScale = 296,                                \
        .trainerOffset = 1,                                 \
        .footprint = gMonFootprint_Zoroark,                 \
        .formSpeciesIdTable = sZoroarkFormSpeciesIdTable

    [SPECIES_ZORUA] =
    {
        ZORUA_MISC_INFO,
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 80,
        .baseSpDefense = 40,
        .types = { TYPE_DARK, TYPE_DARK },
        .categoryName = _("Tricky Fox"),
        .description = COMPOUND_STRING(
            "To protect themselves from danger, they\n"
            "hide their true identities by transforming\n"
            "into people and Pokémon. Apparently, it\n"
            "often transforms into a silent child."),
        FRONT_PIC(Zorua, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Zorua,
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        BACK_PIC(Zorua, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Zorua),
        ICON(Zorua, 0),
        LEARNSETS(Zorua),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ZOROARK}),
    },

    [SPECIES_ZOROARK] =
    {
        ZOROARK_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 105,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 120,
        .baseSpDefense = 60,
        .types = { TYPE_DARK, TYPE_DARK },
        .categoryName = _("Illusion Fox"),
        .weight = 811,
        .description = COMPOUND_STRING(
            "Bonds between these Pokémon are very\n"
            "strong. It protects the safety of its\n"
            "pack by tricking its opponents. They\n"
            "defend their lair with illusory scenery."),
        FRONT_PIC(Zoroark, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Zoroark,
        .frontAnimId = ANIM_FLICKER_INCREASING,
        BACK_PIC(Zoroark, 64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Zoroark),
        ICON(Zoroark, 0),
        LEARNSETS(Zoroark),
    },

#if P_HISUIAN_FORMS
    [SPECIES_ZORUA_HISUIAN] =
    {
        ZORUA_MISC_INFO,
        .baseHP        = 35,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 85,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_GHOST },
        .categoryName = _("Spiteful Fox"),
        .description = COMPOUND_STRING(
            "Derives power from resentment,\n"
            "which rises as energy atop its head and\n"
            "takes on the forms of foes. In this\n"
            "way, Zorua vents lingering malice."),
        FRONT_PIC(ZoruaHisuian, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_ZoruaHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZoruaHisuian, 56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZoruaHisuian),
        ICON(ZoruaHisuian, 0),
        LEARNSETS(ZoruaHisuian),
        .isHisuianForm = TRUE,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ZOROARK_HISUIAN}),
    },

    [SPECIES_ZOROARK_HISUIAN] =
    {
        ZOROARK_MISC_INFO,
        .baseHP        = 55,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 125,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_GHOST },
        .categoryName = _("Baneful Fox"),
        .weight = 730,
        .description = COMPOUND_STRING(
            "Heedless of its own safety,\n"
            "Zoroark attacks its nemeses with a bitter\n"
            "energy so intense, it lacerates\n"
            "Zoroark's own body."),
        FRONT_PIC(ZoroarkHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_ZoroarkHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZoroarkHisuian, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZoroarkHisuian),
        ICON(ZoroarkHisuian, 0),
        LEARNSETS(ZoroarkHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_ZORUA

#if P_FAMILY_MINCCINO
    [SPECIES_MINCCINO] =
    {
        .baseHP        = 55,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_TECHNICIAN, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Minccino"),
        .cryId = CRY_MINCCINO,
        .natDexNum = NATIONAL_DEX_MINCCINO,
        .categoryName = _("Chinchilla"),
        .height = 4,
        .weight = 58,
        .description = COMPOUND_STRING(
            "These Pokémon prefer a tidy habitat.\n"
            "They greet one another by rubbing each\n"
            "other with their tails, which are always\n"
            "kept well groomed and clean."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Minccino, 56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Minccino,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Minccino, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Minccino),
        ICON(Minccino, 0),
        .footprint = gMonFootprint_Minccino,
        LEARNSETS(Minccino),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_CINCCINO}),
    },

    [SPECIES_CINCCINO] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 60,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_TECHNICIAN, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Cinccino"),
        .cryId = CRY_CINCCINO,
        .natDexNum = NATIONAL_DEX_CINCCINO,
        .categoryName = _("Scarf"),
        .height = 5,
        .weight = 75,
        .description = COMPOUND_STRING(
            "Their white fur feels amazing to touch.\n"
            "Cinccino's body is coated in a special\n"
            "oil that repels dust and helps it deflect\n"
            "attacks, such as punches."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cinccino, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Cinccino,
        .frontAnimId = ANIM_V_SLIDE,
        BACK_PIC(Cinccino, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Cinccino),
        ICON(Cinccino, 0),
        .footprint = gMonFootprint_Cinccino,
        LEARNSETS(Cinccino),
    },
#endif //P_FAMILY_MINCCINO

#if P_FAMILY_GOTHITA
    [SPECIES_GOTHITA] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 200,
        .expYield = 58,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gothita"),
        .cryId = CRY_GOTHITA,
        .natDexNum = NATIONAL_DEX_GOTHITA,
        .categoryName = _("Fixation"),
        .height = 4,
        .weight = 58,
        .description = COMPOUND_STRING(
            "They intently observe both Trainers and\n"
            "Pokémon. Apparently, Gothita are looking\n"
            "at something that only they can see. Their\n"
            "ribbonlike feelers increase their power."),
        .pokemonScale = 491,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gothita, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Gothita,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Gothita, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Gothita),
        ICON(Gothita, 2),
        .footprint = gMonFootprint_Gothita,
        LEARNSETS(Gothita),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_GOTHORITA}),
    },

    [SPECIES_GOTHORITA] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 70,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 100,
        .expYield = 137,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gothorita"),
        .cryId = CRY_GOTHORITA,
        .natDexNum = NATIONAL_DEX_GOTHORITA,
        .categoryName = _("Manipulate"),
        .height = 7,
        .weight = 180,
        .description = COMPOUND_STRING(
            "Starlight is the source of their power.\n"
            "They use hypnosis to control people and\n"
            "Pokémon. Tales of Gothorita leading them\n"
            "astray are told in every corner."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gothorita, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Gothorita,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Gothorita, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Gothorita),
        ICON(Gothorita, 2),
        .footprint = gMonFootprint_Gothorita,
        LEARNSETS(Gothorita),
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_GOTHITELLE}),
    },

    [SPECIES_GOTHITELLE] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 95,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = 110,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 50,
        .expYield = 221,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gothitelle"),
        .cryId = CRY_GOTHITELLE,
        .natDexNum = NATIONAL_DEX_GOTHITELLE,
        .categoryName = _("Astral Body"),
        .height = 15,
        .weight = 440,
        .description = COMPOUND_STRING(
            "Starry skies thousands of light-years\n"
            "away are visible in the space distorted by\n"
            "their intense psychic power. When it learns\n"
            "its Trainer's life span, it cries in sadness."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Gothitelle, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Gothitelle,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Gothitelle, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Gothitelle),
        ICON(Gothitelle, 2),
        .footprint = gMonFootprint_Gothitelle,
        LEARNSETS(Gothitelle),
    },
#endif //P_FAMILY_GOTHITA

#if P_FAMILY_SOLOSIS
    [SPECIES_SOLOSIS] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 105,
        .baseSpDefense = 50,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 200,
        .expYield = 58,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Solosis"),
        .cryId = CRY_SOLOSIS,
        .natDexNum = NATIONAL_DEX_SOLOSIS,
        .categoryName = _("Cell"),
        .height = 3,
        .weight = 10,
        .description = COMPOUND_STRING(
            "Because their bodies are enveloped\n"
            "in a special liquid, they are fine in any\n"
            "environment, no matter how severe. They\n"
            "can use telepathy to talk with others."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Solosis, 32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Solosis,
        .frontAnimId = ANIM_TWIST,
        .enemyMonElevation = 14,
        BACK_PIC(Solosis, 48, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Solosis),
        ICON(Solosis, 1),
        .footprint = gMonFootprint_Solosis,
        LEARNSETS(Solosis),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_DUOSION}),
    },

    [SPECIES_DUOSION] =
    {
        .baseHP        = 65,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 125,
        .baseSpDefense = 60,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 100,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Duosion"),
        .cryId = CRY_DUOSION,
        .natDexNum = NATIONAL_DEX_DUOSION,
        .categoryName = _("Mitosis"),
        .height = 6,
        .weight = 80,
        .description = COMPOUND_STRING(
            "When their brains, now divided in two,\n"
            "are thinking the same thoughts,\n"
            "these Pokémon exhibit their maximized\n"
            "psychic power."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Duosion, 40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Duosion,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 7,
        BACK_PIC(Duosion, 56, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Duosion),
        ICON(Duosion, 1),
        .footprint = gMonFootprint_Duosion,
        LEARNSETS(Duosion),
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_REUNICLUS}),
    },

    [SPECIES_REUNICLUS] =
    {
        .baseHP        = 110,
        .baseAttack    = 65,
        .baseDefense   = 75,
        .baseSpeed     = 30,
        .baseSpAttack  = 125,
        .baseSpDefense = 85,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 50,
        .expYield = 221,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Reuniclus"),
        .cryId = CRY_REUNICLUS,
        .natDexNum = NATIONAL_DEX_REUNICLUS,
        .categoryName = _("Multiplying"),
        .height = 10,
        .weight = 201,
        .description = COMPOUND_STRING(
            "They use psychic power to control their\n"
            "arms, which are made of a special liquid.\n"
            "When Reuniclus shake hands, a network\n"
            "forms between their brains."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Reuniclus, 64, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Reuniclus,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        BACK_PIC(Reuniclus, 64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Reuniclus),
        ICON(Reuniclus, 1),
        .footprint = gMonFootprint_Reuniclus,
        LEARNSETS(Reuniclus),
    },
#endif //P_FAMILY_SOLOSIS

#if P_FAMILY_DUCKLETT
    [SPECIES_DUCKLETT] =
    {
        .baseHP        = 62,
        .baseAttack    = 44,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 44,
        .baseSpDefense = 50,
        .types = { TYPE_WATER, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 61,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_BIG_PECKS, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Ducklett"),
        .cryId = CRY_DUCKLETT,
        .natDexNum = NATIONAL_DEX_DUCKLETT,
        .categoryName = _("Water Bird"),
        .height = 5,
        .weight = 55,
        .description = COMPOUND_STRING(
            "These bird Pokémon are excellent divers.\n"
            "They are better at swimming than flying,\n"
            "and they happily eat their favorite food,\n"
            "peat moss, as they dive underwater."),
        .pokemonScale = 432,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ducklett, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Ducklett,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Ducklett, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Ducklett),
        ICON(Ducklett, 0),
        .footprint = gMonFootprint_Ducklett,
        LEARNSETS(Ducklett),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_SWANNA}),
    },

    [SPECIES_SWANNA] =
    {
        .baseHP        = 75,
        .baseAttack    = 87,
        .baseDefense   = 63,
        .baseSpeed     = 98,
        .baseSpAttack  = 87,
        .baseSpDefense = 63,
        .types = { TYPE_WATER, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 166,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_BIG_PECKS, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Swanna"),
        .cryId = CRY_SWANNA,
        .natDexNum = NATIONAL_DEX_SWANNA,
        .categoryName = _("White Bird"),
        .height = 13,
        .weight = 242,
        .description = COMPOUND_STRING(
            "Despite their elegant appearance, they\n"
            "can flap their wings strongly and fly for\n"
            "thousands of miles. The one in the middle\n"
            "is the leader of the flock."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swanna, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Swanna,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Swanna, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Swanna),
        ICON(Swanna, 2),
        .footprint = gMonFootprint_Swanna,
        LEARNSETS(Swanna),
    },
#endif //P_FAMILY_DUCKLETT

#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] =
    {
        .baseHP        = 36,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 44,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 255,
        .expYield = 61,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Vanillite"),
        .cryId = CRY_VANILLITE,
        .natDexNum = NATIONAL_DEX_VANILLITE,
        .categoryName = _("Fresh Snow"),
        .height = 4,
        .weight = 57,
        .description = COMPOUND_STRING(
            "The temperature of their breath is -58ºF.\n"
            "They create snow crystals and make snow\n"
            "fall in the areas around them. Vanillite is\n"
            "treasured by households in warm regions."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vanillite, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Vanillite,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Vanillite, 40, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Vanillite),
        ICON(Vanillite, 0),
        .footprint = gMonFootprint_Vanillite,
        LEARNSETS(Vanillite),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_VANILLISH}),
    },

    [SPECIES_VANILLISH] =
    {
        .baseHP        = 51,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 59,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 120,
        .expYield = 138,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Vanillish"),
        .cryId = CRY_VANILLISH,
        .natDexNum = NATIONAL_DEX_VANILLISH,
        .categoryName = _("Icy Snow"),
        .height = 11,
        .weight = 410,
        .description = COMPOUND_STRING(
            "Vanillish has existed since the Ice Age.\n"
            "It controls particles of ice, freezes its\n"
            "opponents, and then shatters them with\n"
            "a headbutt."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vanillish, 32, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Vanillish,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Vanillish, 48, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Vanillish),
        ICON(Vanillish, 2),
        .footprint = gMonFootprint_Vanillish,
        LEARNSETS(Vanillish),
        .evolutions = EVOLUTION({EVO_LEVEL, 47, SPECIES_VANILLUXE}),
    },

    [SPECIES_VANILLUXE] =
    {
        .baseHP        = 71,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 79,
        .baseSpAttack  = 110,
        .baseSpDefense = 95,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 45,
        .expYield = 241,
        .evYield_SpAttack = 3,
        .itemCommon = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_WARNING, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Vanilluxe"),
        .cryId = CRY_VANILLUXE,
        .natDexNum = NATIONAL_DEX_VANILLUXE,
        .categoryName = _("Snowstorm"),
        .height = 13,
        .weight = 575,
        .description = COMPOUND_STRING(
            "Each of its two heads has a brain, and\n"
            "when they are in agreement, it attacks\n"
            "its enemies by exhaling a violent blizzard.\n"
            "It makes snow clouds inside its body."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vanilluxe, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Vanilluxe,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Vanilluxe, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Vanilluxe),
        ICON(Vanilluxe, 2),
        .footprint = gMonFootprint_Vanilluxe,
        LEARNSETS(Vanilluxe),
    },
#endif //P_FAMILY_VANILLITE

#if P_FAMILY_DEERLING
#define DEERLING_MISC_INFO                                                              \
        .baseHP        = 60,                                                            \
        .baseAttack    = 60,                                                            \
        .baseDefense   = 50,                                                            \
        .baseSpeed     = 75,                                                            \
        .baseSpAttack  = 40,                                                            \
        .baseSpDefense = 50,                                                            \
        .types = { TYPE_NORMAL, TYPE_GRASS },                                           \
        .catchRate = 190,                                                               \
        .expYield = 67,                                                                 \
        .evYield_Speed = 1,                                                             \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                              \
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE }, \
        .speciesName = _("Deerling"),                                                   \
        .cryId = CRY_DEERLING,                                                          \
        .natDexNum = NATIONAL_DEX_DEERLING,                                             \
        .categoryName = _("Season"),                                                    \
        .height = 6,                                                                    \
        .weight = 195,                                                                  \
        .pokemonScale = 422,                                                            \
        .pokemonOffset = 14,                                                            \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Deerling, 32, 48),                                                    \
        .frontPicYOffset = 11,                                                          \
        .frontAnimFrames = sAnims_Deerling,                                             \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                        \
        BACK_PIC(Deerling, 48, 56),                                                     \
        .backPicYOffset = 9,                                                            \
        .backAnimId = BACK_ANIM_H_SLIDE,                                                \
        .footprint = gMonFootprint_Deerling,                                            \
        LEARNSETS(Deerling),                                                            \
        .formSpeciesIdTable = sDeerlingFormSpeciesIdTable

    [SPECIES_DEERLING_SPRING] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_PINK,
        .description = COMPOUND_STRING(
            "Deerling have different scents\n"
            "depending on the season. In early\n"
            "spring, these Pokémon give off a\n"
            "delicate, sweet, and calming scent."),
        PALETTES(DeerlingSpring),
        ICON(DeerlingSpring, 1),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_SPRING}),
    },
    [SPECIES_DEERLING_SUMMER] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_GREEN,
        .description = COMPOUND_STRING(
            "To prevent Deerling from entering\n"
            "their fields, many farmers will have\n"
            "several Lycanroc stand guard, as\n"
            "they are its natural enemy."),
        PALETTES(DeerlingSummer),
        ICON(DeerlingSummer, 1),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_SUMMER}),
    },
    [SPECIES_DEERLING_AUTUMN] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_RED,
        .description = COMPOUND_STRING(
            "Deerling have different scents\n"
            "depending on the season. In this form,\n"
            "Deerling have a softly sweet scent\n"
            "that lingers in the nose."),
        PALETTES(DeerlingAutumn),
        ICON(DeerlingAutumn, 0),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_AUTUMN}),
    },
    [SPECIES_DEERLING_WINTER] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_BROWN,
        .description = COMPOUND_STRING(
            "Deerling's scent changes with the\n"
            "seasons, but when the Pokémon is in\n"
            "its Winter Form, it has hardly any\n"
            "scent at all."),
        PALETTES(DeerlingWinter),
        ICON(DeerlingWinter, 2),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_WINTER}),
    },

#define SAWSBUCK_MISC_INFO                                                              \
        .baseHP        = 80,                                                            \
        .baseAttack    = 100,                                                           \
        .baseDefense   = 70,                                                            \
        .baseSpeed     = 95,                                                            \
        .baseSpAttack  = 60,                                                            \
        .baseSpDefense = 70,                                                            \
        .types = { TYPE_NORMAL, TYPE_GRASS },                                           \
        .catchRate = 75,                                                                \
        .expYield = 166,                                                                \
        .evYield_Attack = 2,                                                            \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                              \
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE }, \
        .bodyColor = BODY_COLOR_BROWN,                                                  \
        .speciesName = _("Sawsbuck"),                                                   \
        .cryId = CRY_SAWSBUCK,                                                          \
        .natDexNum = NATIONAL_DEX_SAWSBUCK,                                             \
        .categoryName = _("Season"),                                                    \
        .height = 19,                                                                   \
        .weight = 925,                                                                  \
        .pokemonScale = 256,                                                            \
        .pokemonOffset = 1,                                                             \
        .trainerScale = 326,                                                            \
        .trainerOffset = 4,                                                             \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Sawsbuck,                                             \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                        \
        .backPicYOffset = 5,                                                            \
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,                                         \
        .footprint = gMonFootprint_Sawsbuck,                                            \
        LEARNSETS(Sawsbuck),                                                            \
        .formSpeciesIdTable = sSawsbuckFormSpeciesIdTable

    [SPECIES_SAWSBUCK_SPRING] =
    {
        SAWSBUCK_MISC_INFO,
        .description = COMPOUND_STRING(
            "Some people call Sawsbuck the harbingers\n"
            "of spring because the plants growing on\n"
            "its horns change according to the season.\n"
            "The leader possesses magnificent horns."),
        FRONT_PIC(SawsbuckSpring, 56, 64),
        BACK_PIC(SawsbuckSpring, 48, 64),
        PALETTES(SawsbuckSpring),
        ICON(SawsbuckSpring, 1),
    },

    [SPECIES_SAWSBUCK_SUMMER] =
    {
        SAWSBUCK_MISC_INFO,
        .description = COMPOUND_STRING(
            "The thicker and larger the\n"
            "branches and leaves on its antlers, the\n"
            "more majestic the Sawsbuck is thought\n"
            "to be."),
        FRONT_PIC(SawsbuckSummer, 64, 64),
        BACK_PIC(SawsbuckSummer, 64, 64),
        PALETTES(SawsbuckSummer),
        ICON(SawsbuckSummer, 1),
    },

    [SPECIES_SAWSBUCK_AUTUMN] =
    {
        SAWSBUCK_MISC_INFO,
        .description = COMPOUND_STRING(
            "Sawsbuck in their Autumn Form are\n"
            "known for having very short\n"
            "tempers. The males fight each other\n"
            "incessantly."),
        FRONT_PIC(SawsbuckAutumn, 64, 64),
        BACK_PIC(SawsbuckAutumn, 64, 64),
        PALETTES(SawsbuckAutumn),
        ICON(SawsbuckAutumn, 1),
    },

    [SPECIES_SAWSBUCK_WINTER] =
    {
        SAWSBUCK_MISC_INFO,
        .description = COMPOUND_STRING(
            "Though there are many enthusiasts\n"
            "for Sawsbuck as a species, this\n"
            "seasonal form in particular is not\n"
            "very popular."),
        FRONT_PIC(SawsbuckWinter, 56, 64),
        BACK_PIC(SawsbuckWinter, 48, 64),
        PALETTES(SawsbuckWinter),
        ICON(SawsbuckWinter, 1),
    },

#endif //P_FAMILY_DEERLING

#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 103,
        .baseSpAttack  = 75,
        .baseSpDefense = 60,
        .types = { TYPE_ELECTRIC, TYPE_FLYING },
        .catchRate = 200,
        .expYield = 150,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_MOTOR_DRIVE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Emolga"),
        .cryId = CRY_EMOLGA,
        .natDexNum = NATIONAL_DEX_EMOLGA,
        .categoryName = _("Sky Squirrel"),
        .height = 4,
        .weight = 50,
        .description = COMPOUND_STRING(
            "It glides using its cape-like membrane.\n"
            "It grills berries and bug Pokémon with\n"
            "electric shocks from the pouches on its\n"
            "cheeks and makes a meal of them."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Emolga, 64, 48),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Emolga,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .enemyMonElevation = 19,
        BACK_PIC(Emolga, 56, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Emolga),
        ICON(Emolga, 2),
        .footprint = gMonFootprint_Emolga,
        LEARNSETS(Emolga),
    },
#endif //P_FAMILY_EMOLGA

#if P_FAMILY_KARRABLAST
    [SPECIES_KARRABLAST] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 200,
        .expYield = 63,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_SHED_SKIN, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Karrablast"),
        .cryId = CRY_KARRABLAST,
        .natDexNum = NATIONAL_DEX_KARRABLAST,
        .categoryName = _("Clamping"),
        .height = 5,
        .weight = 59,
        .description = COMPOUND_STRING(
            "When they feel threatened, they spit an\n"
            "acidic liquid to drive attackers away.\n"
            "For some reason they evolve while they\n"
            "are in the same place as Shelmet."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Karrablast, 40, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Karrablast,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Karrablast, 48, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Karrablast),
        ICON(Karrablast, 0),
        .footprint = gMonFootprint_Karrablast,
        LEARNSETS(Karrablast),
        .evolutions = EVOLUTION({EVO_TRADE_SPECIFIC_MON, SPECIES_SHELMET, SPECIES_ESCAVALIER}),
    },

    [SPECIES_ESCAVALIER] =
    {
        .baseHP        = 70,
        .baseAttack    = 135,
        .baseDefense   = 105,
        .baseSpeed     = 20,
        .baseSpAttack  = 60,
        .baseSpDefense = 105,
        .types = { TYPE_BUG, TYPE_STEEL },
        .catchRate = 75,
        .expYield = 173,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_SHELL_ARMOR, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Escavalier"),
        .cryId = CRY_ESCAVALIER,
        .natDexNum = NATIONAL_DEX_ESCAVALIER,
        .categoryName = _("Cavalry"),
        .height = 10,
        .weight = 330,
        .description = COMPOUND_STRING(
            "Wearing the shell covering they stole\n"
            "from Shelmet, they defend themselves and\n"
            "attack with two lances. The steel armor\n"
            "protects their whole body."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Escavalier, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Escavalier,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Escavalier, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Escavalier),
        ICON(Escavalier, 0),
        .footprint = gMonFootprint_Escavalier,
        LEARNSETS(Escavalier),
    },
#endif //P_FAMILY_KARRABLAST

#if P_FAMILY_FOONGUS
    [SPECIES_FOONGUS] =
    {
        .baseHP        = 69,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 15,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 190,
        .expYield = 59,
        .evYield_HP = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Foongus"),
        .cryId = CRY_FOONGUS,
        .natDexNum = NATIONAL_DEX_FOONGUS,
        .categoryName = _("Mushroom"),
        .height = 2,
        .weight = 10,
        .description = COMPOUND_STRING(
            "It lures Pokémon in with its pattern that\n"
            "looks just like a Poké Ball, then releases\n"
            "its poison spores. Why it resembles a\n"
            "Poké Ball is unknown."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Foongus, 32, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Foongus,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST,
        BACK_PIC(Foongus, 48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Foongus),
        ICON(Foongus, 0),
        .footprint = gMonFootprint_Foongus,
        LEARNSETS(Foongus),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_AMOONGUSS}),
    },

    [SPECIES_AMOONGUSS] =
    {
        .baseHP        = 114,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 30,
        .baseSpAttack  = 85,
        .baseSpDefense = 80,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 75,
        .expYield = 162,
        .evYield_HP = 2,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Amoonguss"),
        .cryId = CRY_AMOONGUSS,
        .natDexNum = NATIONAL_DEX_AMOONGUSS,
        .categoryName = _("Mushroom"),
        .height = 6,
        .weight = 105,
        .description = COMPOUND_STRING(
            "It lures prey close by dancing and waving\n"
            "its arm caps, which resemble Poké Balls,\n"
            "in a swaying motion, but very few Pokémon\n"
            "are fooled by this."),
        .pokemonScale = 422,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Amoonguss, 56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Amoonguss,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Amoonguss, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Amoonguss),
        ICON(Amoonguss, 1),
        .footprint = gMonFootprint_Amoonguss,
        LEARNSETS(Amoonguss),
    },
#endif //P_FAMILY_FOONGUS

#if P_FAMILY_FRILLISH
    [SPECIES_FRILLISH] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 65,
        .baseSpDefense = 85,
        .types = { TYPE_WATER, TYPE_GHOST },
        .catchRate = 190,
        .expYield = 67,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Frillish"),
        .cryId = CRY_FRILLISH,
        .natDexNum = NATIONAL_DEX_FRILLISH,
        .categoryName = _("Floating"),
        .height = 12,
        .weight = 330,
        .description = COMPOUND_STRING(
            "If its veil-like arms stun and wrap an\n"
            "opponent, that foe will be dragged\n"
            "five miles below the surface to its lair,\n"
            "never to return."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Frillish, 56, 56),
        FRONT_PIC_FEMALE(Frillish, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Frillish,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Frillish, 40, 56),
        BACK_PIC_FEMALE(Frillish, 40, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Frillish),
        PALETTE_FEMALE(Frillish),
        ICON(Frillish, 0),
        ICON_FEMALE(Frillish, 1),
        .footprint = gMonFootprint_Frillish,
        LEARNSETS(Frillish),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_JELLICENT}),
    },

    [SPECIES_JELLICENT] =
    {
        .baseHP        = 100,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 105,
        .types = { TYPE_WATER, TYPE_GHOST },
        .catchRate = 60,
        .expYield = 168,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Jellicent"),
        .cryId = CRY_JELLICENT,
        .natDexNum = NATIONAL_DEX_JELLICENT,
        .categoryName = _("Floating"),
        .height = 22,
        .weight = 1350,
        .description = COMPOUND_STRING(
            "They propel themselves by expelling\n"
            "absorbed seawater from their bodies.\n"
            "It's said there's a castle of ships\n"
            "Jellicent have sunk on the seafloor."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(Jellicent, 64, 64),
        FRONT_PIC_FEMALE(Jellicent, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Jellicent,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Jellicent, 64, 48),
        BACK_PIC_FEMALE(Jellicent, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Jellicent),
        PALETTE_FEMALE(Jellicent),
        ICON(Jellicent, 0),
        ICON_FEMALE(Jellicent, 1),
        .footprint = gMonFootprint_Jellicent,
        LEARNSETS(Jellicent),
    },
#endif //P_FAMILY_FRILLISH

#if P_FAMILY_ALOMOMOLA
    [SPECIES_ALOMOMOLA] =
    {
        .baseHP        = 165,
        .baseAttack    = 75,
        .baseDefense   = 80,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 165,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_HEALER, ABILITY_HYDRATION, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Alomomola"),
        .cryId = CRY_ALOMOMOLA,
        .natDexNum = NATIONAL_DEX_ALOMOMOLA,
        .categoryName = _("Caring"),
        .height = 12,
        .weight = 316,
        .description = COMPOUND_STRING(
            "When they find a wounded Pokémon,\n"
            "they embrace it and bring it to shore.\n"
            "The special membrane enveloping\n"
            "Alomomola has the ability to heal wounds."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Alomomola, 32, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Alomomola,
        .frontAnimId = ANIM_SWING_CONCAVE,
        BACK_PIC(Alomomola, 48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Alomomola),
        ICON(Alomomola, 0),
        .footprint = gMonFootprint_Alomomola,
        LEARNSETS(Alomomola),
    },
#endif //P_FAMILY_ALOMOMOLA

#if P_FAMILY_JOLTIK
    [SPECIES_JOLTIK] =
    {
        .baseHP        = 50,
        .baseAttack    = 47,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 57,
        .baseSpDefense = 50,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 190,
        .expYield = 64,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_UNNERVE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Joltik"),
        .cryId = CRY_JOLTIK,
        .natDexNum = NATIONAL_DEX_JOLTIK,
        .categoryName = _("Attaching"),
        .height = 1,
        .weight = 6,
        .description = COMPOUND_STRING(
            "Since they can't generate their own\n"
            "electricity, they attach themselves to\n"
            "large-bodied Pokémon and absorb static\n"
            "electricity, which they store in a pouch."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Joltik, 32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Joltik,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Joltik, 48, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Joltik),
        ICON(Joltik, 0),
        .footprint = gMonFootprint_Joltik,
        LEARNSETS(Joltik),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GALVANTULA}),
    },

    [SPECIES_GALVANTULA] =
    {
        .baseHP        = 70,
        .baseAttack    = 77,
        .baseDefense   = 60,
        .baseSpeed     = 108,
        .baseSpAttack  = 97,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 75,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_UNNERVE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Galvantula"),
        .cryId = CRY_GALVANTULA,
        .natDexNum = NATIONAL_DEX_GALVANTULA,
        .categoryName = _("EleSpider"),
        .height = 8,
        .weight = 143,
        .description = COMPOUND_STRING(
            "It creates barriers from electrified silk\n"
            "that stun foes. This works as a weapon as\n"
            "well as a defense. While it is immobilized\n"
            "by shock, they leisurely consume it."),
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Galvantula, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Galvantula,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        BACK_PIC(Galvantula, 64, 40),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Galvantula),
        ICON(Galvantula, 2),
        .footprint = gMonFootprint_Galvantula,
        LEARNSETS(Galvantula),
    },
#endif //P_FAMILY_JOLTIK

#if P_FAMILY_FERROSEED
    [SPECIES_FERROSEED] =
    {
        .baseHP        = 44,
        .baseAttack    = 50,
        .baseDefense   = 91,
        .baseSpeed     = 10,
        .baseSpAttack  = 24,
        .baseSpDefense = 86,
        .types = { TYPE_GRASS, TYPE_STEEL },
        .catchRate = 255,
        .expYield = 61,
        .evYield_Defense = 1,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_BARBS, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Ferroseed"),
        .cryId = CRY_FERROSEED,
        .natDexNum = NATIONAL_DEX_FERROSEED,
        .categoryName = _("Thorn Seed"),
        .height = 6,
        .weight = 188,
        .description = COMPOUND_STRING(
            "It absorbs the iron it finds in the rock\n"
            "while clinging to the ceiling of caves.\n"
            "When threatened, it attacks by shooting\n"
            "a barrage of spikes."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ferroseed, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Ferroseed,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Ferroseed, 48, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Ferroseed),
        ICON(Ferroseed, 1),
        .footprint = gMonFootprint_Ferroseed,
        LEARNSETS(Ferroseed),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_FERROTHORN}),
    },

    [SPECIES_FERROTHORN] =
    {
        .baseHP        = 74,
        .baseAttack    = 94,
        .baseDefense   = 131,
        .baseSpeed     = 20,
        .baseSpAttack  = 54,
        .baseSpDefense = 116,
        .types = { TYPE_GRASS, TYPE_STEEL },
        .catchRate = 90,
        .expYield = 171,
        .evYield_Defense = 2,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_BARBS, ABILITY_NONE, ABILITY_ANTICIPATION },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Ferrothorn"),
        .cryId = CRY_FERROTHORN,
        .natDexNum = NATIONAL_DEX_FERROTHORN,
        .categoryName = _("Thorn Pod"),
        .height = 10,
        .weight = 1100,
        .description = COMPOUND_STRING(
            "It fights by swinging around its three\n"
            "spiky feelers and shooting spikes.\n"
            "A hit from these steel spikes can reduce\n"
            "a boulder to rubble."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Ferrothorn, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Ferrothorn,
        .frontAnimId = ANIM_V_SHAKE,
        .enemyMonElevation = 10,
        BACK_PIC(Ferrothorn, 64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Ferrothorn),
        ICON(Ferrothorn, 1),
        .footprint = gMonFootprint_Ferrothorn,
        LEARNSETS(Ferrothorn),
    },
#endif //P_FAMILY_FERROSEED

#if P_FAMILY_KLINK
    [SPECIES_KLINK] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 30,
        .baseSpAttack  = 45,
        .baseSpDefense = 60,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 130,
        .expYield = 60,
        .evYield_Defense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Klink"),
        .cryId = CRY_KLINK,
        .natDexNum = NATIONAL_DEX_KLINK,
        .categoryName = _("Gear"),
        .height = 3,
        .weight = 210,
        .description = COMPOUND_STRING(
            "Two bodies comprise a fixed pair.\n"
            "The two minigears that mesh together\n"
            "are predetermined. Each will rebound from\n"
            "other minigears without meshing."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klink, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Klink,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 12,
        BACK_PIC(Klink, 64, 64),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Klink),
        ICON(Klink, 0),
        .footprint = gMonFootprint_Klink,
        LEARNSETS(Klink),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_KLANG}),
    },

    [SPECIES_KLANG] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 95,
        .baseSpeed     = 50,
        .baseSpAttack  = 70,
        .baseSpDefense = 85,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 60,
        .expYield = 154,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Klang"),
        .cryId = CRY_KLANG,
        .natDexNum = NATIONAL_DEX_KLANG,
        .categoryName = _("Gear"),
        .height = 6,
        .weight = 510,
        .description = COMPOUND_STRING(
            "A minigear and big gear comprise its\n"
            "body. Spinning minigears are rotated\n"
            "at high speed and repeatedly fired away.\n"
            "It is dangerous if the gears don't return."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klang, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Klang,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 8,
        BACK_PIC(Klang, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Klang),
        ICON(Klang, 0),
        .footprint = gMonFootprint_Klang,
        LEARNSETS(Klang),
        .evolutions = EVOLUTION({EVO_LEVEL, 49, SPECIES_KLINKLANG}),
    },

    [SPECIES_KLINKLANG] =
    {
        .baseHP        = 60,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 85,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 30,
        .expYield = 234,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Klinklang"),
        .cryId = CRY_KLINKLANG,
        .natDexNum = NATIONAL_DEX_KLINKLANG,
        .categoryName = _("Gear"),
        .height = 6,
        .weight = 810,
        .description = COMPOUND_STRING(
            "Its red core functions as an energy tank.\n"
            "It is rotated at high speed for a rapid\n"
            "energy charge. It fires the charged energy\n"
            "through its spikes into an area."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klinklang, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Klinklang,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 4,
        BACK_PIC(Klinklang, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Klinklang),
        ICON(Klinklang, 0),
        .footprint = gMonFootprint_Klinklang,
        LEARNSETS(Klinklang),
    },
#endif //P_FAMILY_KLINK

#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 40,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 190,
        .expYield = 55,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Tynamo"),
        .cryId = CRY_TYNAMO,
        .natDexNum = NATIONAL_DEX_TYNAMO,
        .categoryName = _("EleFish"),
        .height = 2,
        .weight = 3,
        .description = COMPOUND_STRING(
            "These Pokémon move in schools.\n"
            "One alone can emit only a trickle of\n"
            "electricity, so a group of them gathers\n"
            "to unleash a powerful electric shock."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tynamo, 40, 24),
        .frontPicYOffset = 22,
        .frontAnimFrames = sAnims_Tynamo,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 16,
        BACK_PIC(Tynamo, 64, 24),
        .backPicYOffset = 21,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Tynamo),
        ICON(Tynamo, 0),
        .footprint = gMonFootprint_Tynamo,
        LEARNSETS(Tynamo),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_EELEKTRIK}),
    },

    [SPECIES_EELEKTRIK] =
    {
        .baseHP        = 65,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 60,
        .expYield = 142,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Eelektrik"),
        .cryId = CRY_EELEKTRIK,
        .natDexNum = NATIONAL_DEX_EELEKTRIK,
        .categoryName = _("EleFish"),
        .height = 12,
        .weight = 220,
        .description = COMPOUND_STRING(
            "These Pokémon have a big appetite.\n"
            "It wraps itself around its prey and\n"
            "paralyzes it with electricity from the\n"
            "round spots on its sides. Then it chomps."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Eelektrik, 48, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Eelektrik,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        BACK_PIC(Eelektrik, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Eelektrik),
        ICON(Eelektrik, 0),
        .footprint = gMonFootprint_Eelektrik,
        LEARNSETS(Eelektrik),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_EELEKTROSS}),
    },

    [SPECIES_EELEKTROSS] =
    {
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 30,
        .expYield = 232,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Eelektross"),
        .cryId = CRY_EELEKTROSS,
        .natDexNum = NATIONAL_DEX_EELEKTROSS,
        .categoryName = _("EleFish"),
        .height = 21,
        .weight = 805,
        .description = COMPOUND_STRING(
            "They crawl out of the ocean using their\n"
            "arms. They will attack prey on shore and\n"
            "immediately drag it into the ocean, with\n"
            "their sucker mouths."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Eelektross, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Eelektross,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        .enemyMonElevation = 8,
        BACK_PIC(Eelektross, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Eelektross),
        ICON(Eelektross, 0),
        .footprint = gMonFootprint_Eelektross,
        LEARNSETS(Eelektross),
    },
#endif //P_FAMILY_TYNAMO

#if P_FAMILY_ELGYEM
    [SPECIES_ELGYEM] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 85,
        .baseSpDefense = 55,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 255,
        .expYield = 67,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Elgyem"),
        .cryId = CRY_ELGYEM,
        .natDexNum = NATIONAL_DEX_ELGYEM,
        .categoryName = _("Cerebral"),
        .height = 5,
        .weight = 90,
        .description = COMPOUND_STRING(
            "It psychically squeezes the brain of\n"
            "its foe, causing unendurable headaches.\n"
            "Rumors of its origin are linked to a UFO\n"
            "crash site in the desert 50 years ago."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Elgyem, 32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Elgyem,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Elgyem, 48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Elgyem),
        ICON(Elgyem, 0),
        .footprint = gMonFootprint_Elgyem,
        LEARNSETS(Elgyem),
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_BEHEEYEM}),
    },

    [SPECIES_BEHEEYEM] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 40,
        .baseSpAttack  = 125,
        .baseSpDefense = 95,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 90,
        .expYield = 170,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Beheeyem"),
        .cryId = CRY_BEHEEYEM,
        .natDexNum = NATIONAL_DEX_BEHEEYEM,
        .categoryName = _("Cerebral"),
        .height = 10,
        .weight = 345,
        .description = COMPOUND_STRING(
            "It can manipulate an opponent's memory.\n"
            "Apparently, it communicates by flashing\n"
            "its three fingers, but those patterns\n"
            "haven't been decoded. "),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Beheeyem, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Beheeyem,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Beheeyem, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Beheeyem),
        ICON(Beheeyem, 2),
        .footprint = gMonFootprint_Beheeyem,
        LEARNSETS(Beheeyem),
    },
#endif //P_FAMILY_ELGYEM

#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] =
    {
        .baseHP        = 50,
        .baseAttack    = 30,
        .baseDefense   = 55,
        .baseSpeed     = 20,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = { TYPE_GHOST, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 55,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
        #else
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
        #endif
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Litwick"),
        .cryId = CRY_LITWICK,
        .natDexNum = NATIONAL_DEX_LITWICK,
        .categoryName = _("Candle"),
        .height = 3,
        .weight = 31,
        .description = COMPOUND_STRING(
            "While Litwick shines a light and pretends\n"
            "to be a guide, it absorbs the life force of\n"
            "any who follow it, which becomes the fuel\n"
            "that it burns."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Litwick, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Litwick,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Litwick, 40, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Litwick),
        ICON(Litwick, 2),
        .footprint = gMonFootprint_Litwick,
        LEARNSETS(Litwick),
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_LAMPENT}),
    },

    [SPECIES_LAMPENT] =
    {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = { TYPE_GHOST, TYPE_FIRE },
        .catchRate = 90,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
        #else
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
        #endif
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Lampent"),
        .cryId = CRY_LAMPENT,
        .natDexNum = NATIONAL_DEX_LAMPENT,
        .categoryName = _("Lamp"),
        .height = 6,
        .weight = 130,
        .description = COMPOUND_STRING(
            "This ominous Pokémon is feared.\n"
            "Through cities it wanders, searching\n"
            "for the spirits of the fallen. The spirits\n"
            "it absorbs fuel its baleful fire."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lampent, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Lampent,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Lampent, 56, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Lampent),
        ICON(Lampent, 2),
        .footprint = gMonFootprint_Lampent,
        LEARNSETS(Lampent),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_CHANDELURE}),
    },

    [SPECIES_CHANDELURE] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 145,
        .baseSpDefense = 90,
        .types = { TYPE_GHOST, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 234,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
        #else
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
        #endif
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Chandelure"),
        .cryId = CRY_CHANDELURE,
        .natDexNum = NATIONAL_DEX_CHANDELURE,
        .categoryName = _("Luring"),
        .height = 10,
        .weight = 343,
        .description = COMPOUND_STRING(
            "Being consumed in Chandelure's flame burns\n"
            "up the spirit, leaving the body behind.\n"
            "By waving the flames on its arms, it puts\n"
            "its foes into a hypnotic trance."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Chandelure, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Chandelure,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Chandelure, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Chandelure),
        ICON(Chandelure, 2),
        .footprint = gMonFootprint_Chandelure,
        LEARNSETS(Chandelure),
    },
#endif //P_FAMILY_LITWICK

#if P_FAMILY_AXEW
    [SPECIES_AXEW] =
    {
        .baseHP        = 46,
        .baseAttack    = 87,
        .baseDefense   = 60,
        .baseSpeed     = 57,
        .baseSpAttack  = 30,
        .baseSpDefense = 40,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 75,
        .expYield = 64,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Axew"),
        .cryId = CRY_AXEW,
        .natDexNum = NATIONAL_DEX_AXEW,
        .categoryName = _("Tusk"),
        .height = 6,
        .weight = 180,
        .description = COMPOUND_STRING(
            "They mark their territory by leaving\n"
            "gashes in trees with their tusks. If a\n"
            "tusk breaks, a new one grows in quickly,\n"
            "harder and sturdier than the last."),
        .pokemonScale = 422,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Axew, 40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Axew,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Axew, 48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Axew),
        ICON(Axew, 1),
        .footprint = gMonFootprint_Axew,
        LEARNSETS(Axew),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_FRAXURE}),
    },

    [SPECIES_FRAXURE] =
    {
        .baseHP        = 66,
        .baseAttack    = 117,
        .baseDefense   = 70,
        .baseSpeed     = 67,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 60,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Fraxure"),
        .cryId = CRY_FRAXURE,
        .natDexNum = NATIONAL_DEX_FRAXURE,
        .categoryName = _("Axe Jaw"),
        .height = 10,
        .weight = 360,
        .description = COMPOUND_STRING(
            "Their tusks can shatter rocks.\n"
            "A broken tusk will not grow back,\n"
            "so it diligently sharpens its tusks on\n"
            "river rocks after the end of a battle."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Fraxure, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Fraxure,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Fraxure, 64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Fraxure),
        ICON(Fraxure, 1),
        .footprint = gMonFootprint_Fraxure,
        LEARNSETS(Fraxure),
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_HAXORUS}),
    },

    [SPECIES_HAXORUS] =
    {
        .baseHP        = 76,
        .baseAttack    = 147,
        .baseDefense   = 90,
        .baseSpeed     = 97,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 243,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Haxorus"),
        .cryId = CRY_HAXORUS,
        .natDexNum = NATIONAL_DEX_HAXORUS,
        .categoryName = _("Axe Jaw"),
        .height = 18,
        .weight = 1055,
        .description = COMPOUND_STRING(
            "They are kind but can be relentless\n"
            "when defending territory. Their sturdy\n"
            "tusks will stay sharp even if used to cut\n"
            "steel beams."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Haxorus, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Haxorus,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Haxorus, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Haxorus),
        ICON(Haxorus, 2),
        .footprint = gMonFootprint_Haxorus,
        LEARNSETS(Haxorus),
    },
#endif //P_FAMILY_AXEW

#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] =
    {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 40,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 120,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_SLUSH_RUSH, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Cubchoo"),
        .cryId = CRY_CUBCHOO,
        .natDexNum = NATIONAL_DEX_CUBCHOO,
        .categoryName = _("Chill"),
        .height = 5,
        .weight = 85,
        .description = COMPOUND_STRING(
            "Its nose is always running.\n"
            "Their snot is a barometer of health.\n"
            "When healthy, their snot is sticky and\n"
            "the power of their ice moves increases."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cubchoo, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Cubchoo,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cubchoo, 40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Cubchoo),
        ICON(Cubchoo, 0),
        .footprint = gMonFootprint_Cubchoo,
        LEARNSETS(Cubchoo),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_BEARTIC}),
    },

    [SPECIES_BEARTIC] =
    {
        .baseHP        = 95,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 130 : 110,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 60,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_SLUSH_RUSH, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Beartic"),
        .cryId = CRY_BEARTIC,
        .natDexNum = NATIONAL_DEX_BEARTIC,
        .categoryName = _("Freezing"),
        .height = 26,
        .weight = 2600,
        .description = COMPOUND_STRING(
            "It freezes its breath to create fangs\n"
            "and claws of ice to fight with.\n"
            "Very able in the water, it swims around\n"
            "in northern seas and catches prey."),
        .pokemonScale = 266,
        .pokemonOffset = 3,
        .trainerScale = 399,
        .trainerOffset = 4,
        FRONT_PIC(Beartic, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Beartic,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Beartic, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Beartic),
        ICON(Beartic, 0),
        .footprint = gMonFootprint_Beartic,
        LEARNSETS(Beartic),
    },
#endif //P_FAMILY_CUBCHOO

#if P_FAMILY_CRYOGONAL
    [SPECIES_CRYOGONAL] =
    {
        .baseAttack    = 50,
        .baseSpeed     = 105,
        .baseSpAttack  = 95,
        .baseSpDefense = 135,
        #if P_UPDATED_STATS >= GEN_7
            .baseHP        = 80,
            .baseDefense   = 50,
        #else
            .baseHP        = 70,
            .baseDefense   = 30,
        #endif
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 25,
        .expYield = 180,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cryogonal"),
        .cryId = CRY_CRYOGONAL,
        .natDexNum = NATIONAL_DEX_CRYOGONAL,
        .categoryName = _("Crystallize"),
        .height = 11,
        .weight = 1480,
        .description = COMPOUND_STRING(
            "They are born in snow clouds. When\n"
            "its body temperature goes up, it turns\n"
            "into steam and vanishes. When its\n"
            "temperature lowers, it returns to ice."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cryogonal, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cryogonal,
        .frontAnimId = ANIM_SHRINK_GROW,
        .enemyMonElevation = 3,
        BACK_PIC(Cryogonal, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Cryogonal),
        ICON(Cryogonal, 0),
        .footprint = gMonFootprint_Cryogonal,
        LEARNSETS(Cryogonal),
    },
#endif //P_FAMILY_CRYOGONAL

#if P_FAMILY_SHELMET
    [SPECIES_SHELMET] =
    {
        .baseHP        = 50,
        .baseAttack    = 40,
        .baseDefense   = 85,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 200,
        .expYield = 61,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_HYDRATION, ABILITY_SHELL_ARMOR, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Shelmet"),
        .cryId = CRY_SHELMET,
        .natDexNum = NATIONAL_DEX_SHELMET,
        .categoryName = _("Snail"),
        .height = 4,
        .weight = 77,
        .description = COMPOUND_STRING(
            "When attacked, it defends itself by\n"
            "closing the lid of its shell. It evolves\n"
            "when bathed in an electric-like energy\n"
            "along with Karrablast."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Shelmet, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Shelmet,
        .frontAnimId = ANIM_TWIST,
        BACK_PIC(Shelmet, 64, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Shelmet),
        ICON(Shelmet, 1),
        .footprint = gMonFootprint_Shelmet,
        LEARNSETS(Shelmet),
        .evolutions = EVOLUTION({EVO_TRADE_SPECIFIC_MON, SPECIES_KARRABLAST, SPECIES_ACCELGOR}),
    },

    [SPECIES_ACCELGOR] =
    {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 145,
        .baseSpAttack  = 100,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 75,
        .expYield = 173,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_HYDRATION, ABILITY_STICKY_HOLD, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Accelgor"),
        .cryId = CRY_ACCELGOR,
        .natDexNum = NATIONAL_DEX_ACCELGOR,
        .categoryName = _("Shell Out"),
        .height = 8,
        .weight = 253,
        .description = COMPOUND_STRING(
            "When its body dries out, it weakens. So, to\n"
            "prevent dehydration, it wraps itself in\n"
            "layers of thin membrane. It is very light\n"
            "and fights with ninja-like movements."),
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Accelgor, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Accelgor,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Accelgor, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_H_SPRING_REPEATED,
        PALETTES(Accelgor),
        ICON(Accelgor, 1),
        .footprint = gMonFootprint_Accelgor,
        LEARNSETS(Accelgor),
    },
#endif //P_FAMILY_SHELMET

#if P_FAMILY_STUNFISK
#define STUNFISK_MISC_INFO                                          \
        .catchRate = 75,                                            \
        .expYield = 165,                                            \
        .evYield_HP = 2,                                            \
        .genderRatio = PERCENT_FEMALE(50),                          \
        .eggCycles = 20,                                            \
        .growthRate = GROWTH_MEDIUM_FAST,                           \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS },    \
        .speciesName = _("Stunfisk"),                               \
        .cryId = CRY_STUNFISK,                                      \
        .natDexNum = NATIONAL_DEX_STUNFISK,                         \
        .categoryName = _("Trap"),                                  \
        .height = 7,                                                \
        .pokemonScale = 365,                                        \
        .pokemonOffset = 14,                                        \
        .trainerScale = 256,                                        \
        .trainerOffset = 0,                                         \
        .footprint = gMonFootprint_Stunfisk,                        \
        .formSpeciesIdTable = sStunfiskFormSpeciesIdTable

    [SPECIES_STUNFISK] =
    {
        STUNFISK_MISC_INFO,
        .baseHP        = 109,
        .baseAttack    = 66,
        .baseDefense   = 84,
        .baseSpeed     = 32,
        .baseSpAttack  = 81,
        .baseSpDefense = 99,
        .types = { TYPE_GROUND, TYPE_ELECTRIC },
        .itemRare = ITEM_SOFT_SAND,
        .friendship = 70,
        .abilities = { ABILITY_STATIC, ABILITY_LIMBER, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .weight = 110,
        .description = COMPOUND_STRING(
            "It conceals itself in the mud of the\n"
            "seashore. Then it waits. When prey touch\n"
            "it, it delivers a jolt of electricity.\n"
            "It smiles when transmitting electricity."),
        FRONT_PIC(Stunfisk, 56, 48),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Stunfisk,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Stunfisk, 64, 24),
        .backPicYOffset = 22,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Stunfisk),
        ICON(Stunfisk, 2),
        LEARNSETS(Stunfisk),
    },

#if P_GALARIAN_FORMS
    [SPECIES_STUNFISK_GALARIAN] =
    {
        STUNFISK_MISC_INFO,
        .baseHP        = 109,
        .baseAttack    = 81,
        .baseDefense   = 99,
        .baseSpeed     = 32,
        .baseSpAttack  = 66,
        .baseSpDefense = 84,
        .types = { TYPE_GROUND, TYPE_STEEL },
        .friendship = STANDARD_FRIENDSHIP,
        .abilities = { ABILITY_MIMICRY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .weight = 205,
        .description = COMPOUND_STRING(
            "Its conspicuous lips lure prey in\n"
            "as it lies in wait in the mud. When\n"
            "prey gets close, Stunfisk clamps its\n"
            "jagged steel fins down on them."),
        FRONT_PIC(StunfiskGalarian, 48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_StunfiskGalarian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(StunfiskGalarian, 64, 24),
        .backPicYOffset = 23,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(StunfiskGalarian),
        ICON(StunfiskGalarian, 1),
        LEARNSETS(StunfiskGalarian),
        .isGalarianForm = TRUE,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_STUNFISK

#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] =
    {
        .baseHP        = 45,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 180,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_REGENERATOR, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Mienfoo"),
        .cryId = CRY_MIENFOO,
        .natDexNum = NATIONAL_DEX_MIENFOO,
        .categoryName = _("Martial Arts"),
        .height = 9,
        .weight = 200,
        .description = COMPOUND_STRING(
            "They have mastered elegant combos.\n"
            "As they concentrate, their battle moves\n"
            "become swifter and more precise. What it\n"
            "lacks in power, it makes up for in quantity."),
        .pokemonScale = 338,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mienfoo, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Mienfoo,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Mienfoo, 56, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Mienfoo),
        ICON(Mienfoo, 1),
        .footprint = gMonFootprint_Mienfoo,
        LEARNSETS(Mienfoo),
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_MIENSHAO}),
    },

    [SPECIES_MIENSHAO] =
    {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 179,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_REGENERATOR, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mienshao"),
        .cryId = CRY_MIENSHAO,
        .natDexNum = NATIONAL_DEX_MIENSHAO,
        .categoryName = _("Martial Arts"),
        .height = 14,
        .weight = 355,
        .description = COMPOUND_STRING(
            "They use the long fur on their arms as\n"
            "a whip to strike their opponents. Its arm\n"
            "attacks come with such rapidity that they\n"
            "cannot even be seen."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Mienshao, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Mienshao,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Mienshao, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Mienshao),
        ICON(Mienshao, 2),
        .footprint = gMonFootprint_Mienshao,
        LEARNSETS(Mienshao),
    },
#endif //P_FAMILY_MIENFOO

#if P_FAMILY_DRUDDIGON
    [SPECIES_DRUDDIGON] =
    {
        .baseHP        = 77,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 48,
        .baseSpAttack  = 60,
        .baseSpDefense = 90,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 170,
        .evYield_Attack = 2,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_ROUGH_SKIN, ABILITY_SHEER_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Druddigon"),
        .cryId = CRY_DRUDDIGON,
        .natDexNum = NATIONAL_DEX_DRUDDIGON,
        .categoryName = _("Cave"),
        .height = 16,
        .weight = 1390,
        .description = COMPOUND_STRING(
            "It warms its body by absorbing sunlight\n"
            "with its wings. When its body temperature\n"
            "falls, it can no longer move. It uses its\n"
            "sharp claws to catch prey."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Druddigon, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Druddigon,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        BACK_PIC(Druddigon, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Druddigon),
        ICON(Druddigon, 0),
        .footprint = gMonFootprint_Druddigon,
        LEARNSETS(Druddigon),
    },
#endif //P_FAMILY_DRUDDIGON

#if P_FAMILY_GOLETT
    [SPECIES_GOLETT] =
    {
        .baseHP        = 59,
        .baseAttack    = 74,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 50,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Attack = 1,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_FIST, ABILITY_KLUTZ, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Golett"),
        .cryId = CRY_GOLETT,
        .natDexNum = NATIONAL_DEX_GOLETT,
        .categoryName = _("Automaton"),
        .height = 10,
        .weight = 920,
        .description = COMPOUND_STRING(
            "These Pokémon are thought to have\n"
            "been created by the science of an\n"
            "ancient and mysterious civilization.\n"
            "It's been active for thousands of years."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Golett, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Golett,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Golett, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Golett),
        ICON(Golett, 0),
        .footprint = gMonFootprint_Golett,
        LEARNSETS(Golett),
        .evolutions = EVOLUTION({EVO_LEVEL, 43, SPECIES_GOLURK}),
    },

    [SPECIES_GOLURK] =
    {
        .baseHP        = 89,
        .baseAttack    = 124,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Attack = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_FIST, ABILITY_KLUTZ, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Golurk"),
        .cryId = CRY_GOLURK,
        .natDexNum = NATIONAL_DEX_GOLURK,
        .categoryName = _("Automaton"),
        .height = 28,
        .weight = 3300,
        .description = COMPOUND_STRING(
            "Golurk were created to protect people\n"
            "and Pokémon by an ancient civilisation.\n"
            "Removing the seal on its chest makes its\n"
            "internal energy go out of control."),
        .pokemonScale = 275,
        .pokemonOffset = 3,
        .trainerScale = 300,
        .trainerOffset = 0,
        FRONT_PIC(Golurk, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Golurk,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Golurk, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Golurk),
        ICON(Golurk, 0),
        .footprint = gMonFootprint_Golurk,
        LEARNSETS(Golurk),
    },
#endif //P_FAMILY_GOLETT

#if P_FAMILY_PAWNIARD
    [SPECIES_PAWNIARD] =
    {
        .baseHP        = 45,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_DARK, TYPE_STEEL },
        .catchRate = 120,
        .expYield = 68,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_DEFIANT, ABILITY_INNER_FOCUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Pawniard"),
        .cryId = CRY_PAWNIARD,
        .natDexNum = NATIONAL_DEX_PAWNIARD,
        .categoryName = _("Sharp Blade"),
        .height = 5,
        .weight = 102,
        .description = COMPOUND_STRING(
            "Ignoring their injuries, groups attack by\n"
            "sinking the blades that cover their bodies\n"
            "into their prey. If battling dulls them, it\n"
            "sharpens them on stones by the river."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pawniard, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Pawniard,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Pawniard, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Pawniard),
        ICON(Pawniard, 0),
        .footprint = gMonFootprint_Pawniard,
        LEARNSETS(Pawniard),
        .evolutions = EVOLUTION({EVO_LEVEL, 52, SPECIES_BISHARP}),
    },

    [SPECIES_BISHARP] =
    {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = { TYPE_DARK, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_DEFIANT, ABILITY_INNER_FOCUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Bisharp"),
        .cryId = CRY_BISHARP,
        .natDexNum = NATIONAL_DEX_BISHARP,
        .categoryName = _("Sword Blade"),
        .height = 16,
        .weight = 700,
        .description = COMPOUND_STRING(
            "This pitiless Pokémon commands a group\n"
            "of Pawniard to hound prey into immobility.\n"
            "It battles to become the boss, but will be\n"
            "driven from the group if it loses."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Bisharp, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Bisharp,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Bisharp, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Bisharp),
        ICON(Bisharp, 0),
        .footprint = gMonFootprint_Bisharp,
        LEARNSETS(Bisharp),
        .evolutions = EVOLUTION({EVO_NONE, 0, SPECIES_KINGAMBIT}),
    },

#if P_GEN_9_CROSS_EVOS
    [SPECIES_KINGAMBIT] =
    {
        .baseHP        = 100,
        .baseAttack    = 135,
        .baseDefense   = 120,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 85,
        .types = { TYPE_DARK, TYPE_STEEL },
        .catchRate = 25,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_DEFIANT, ABILITY_SUPREME_OVERLORD, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Kingambit"),
        .cryId = CRY_KINGAMBIT,
        .natDexNum = NATIONAL_DEX_KINGAMBIT,
        .categoryName = _("Big Blade"),
        .height = 20,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "Though it commands a massive army\n"
            "in battle, it's not skilled at\n"
            "devising complex strategies. It just uses\n"
            "brute strength to keep pushing."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Kingambit, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Kingambit,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Kingambit, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Kingambit),
        ICON(Kingambit, 3),
        //.footprint = gMonFootprint_Kingambit,
        LEARNSETS(Kingambit),
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_PAWNIARD

#if P_FAMILY_BOUFFALANT
    [SPECIES_BOUFFALANT] =
    {
        .baseHP        = 95,
        .baseAttack    = 110,
        .baseDefense   = 95,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RECKLESS, ABILITY_SAP_SIPPER, ABILITY_SOUNDPROOF },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bouffalant"),
        .cryId = CRY_BOUFFALANT,
        .natDexNum = NATIONAL_DEX_BOUFFALANT,
        .categoryName = _("Bash Buffalo"),
        .height = 16,
        .weight = 946,
        .description = COMPOUND_STRING(
            "Their fluffy fur absorbs damage, even\n"
            "if they strike foes with a fierce headbutt.\n"
            "Their headbutts have enough destructive\n"
            "force to derail a train."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Bouffalant, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Bouffalant,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Bouffalant, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Bouffalant),
        ICON(Bouffalant, 2),
        .footprint = gMonFootprint_Bouffalant,
        LEARNSETS(Bouffalant),
    },
#endif //P_FAMILY_BOUFFALANT

#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] =
    {
        .baseHP        = 70,
        .baseAttack    = 83,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = 37,
        .baseSpDefense = 50,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Rufflet"),
        .cryId = CRY_RUFFLET,
        .natDexNum = NATIONAL_DEX_RUFFLET,
        .categoryName = _("Eaglet"),
        .height = 5,
        .weight = 105,
        .description = COMPOUND_STRING(
            "With its sharp claws, this Pokémon pierces\n"
            "its prey, and then it pecks at them.\n"
            "Although it also consumes berries, it's a\n"
            "carnivore at heart."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Rufflet, 32, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Rufflet,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Rufflet, 48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Rufflet),
        ICON(Rufflet, 2),
        .footprint = gMonFootprint_Rufflet,
        LEARNSETS(Rufflet),
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_BRAVIARY},
                                {EVO_NONE, 0, SPECIES_BRAVIARY_HISUIAN}),
    },

#define BRAVIARY_MISC_INFO                                      \
        .catchRate = 60,                                        \
        .expYield = 179,                                        \
        .genderRatio = MON_MALE,                                \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },    \
        .speciesName = _("Braviary"),                           \
        .cryId = CRY_BRAVIARY,                                  \
        .natDexNum = NATIONAL_DEX_BRAVIARY,                     \
        .footprint = gMonFootprint_Braviary,                    \
        .formSpeciesIdTable = sBraviaryFormSpeciesIdTable

    [SPECIES_BRAVIARY] =
    {
        BRAVIARY_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 123,
        .baseDefense   = 75,
        .baseSpeed     = 80,
        .baseSpAttack  = 57,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .evYield_Attack = 2,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_RED,
        .categoryName = _("Valiant"),
        .height = 15,
        .weight = 410,
        .description = COMPOUND_STRING(
            "For the sake of its friends, this brave\n"
            "warrior of the sky will not stop battling,\n"
            "even if it is injured. One can carry a car\n"
            "while flying."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Braviary, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Braviary,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        BACK_PIC(Braviary, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Braviary),
        ICON(Braviary, 0),
        LEARNSETS(Braviary),
    },

#if P_HISUIAN_FORMS
    [SPECIES_BRAVIARY_HISUIAN] =
    {
        BRAVIARY_MISC_INFO,
        .baseHP        = 110,
        .baseAttack    = 83,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 112,
        .baseSpDefense = 70,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .evYield_SpAttack = 2,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_WHITE,
        .categoryName = _("Battle Cry"),
        .height = 17,
        .weight = 434,
        .description = COMPOUND_STRING(
            "Screaming a bloodcurdling battle\n"
            "cry, this huge and ferocious bird\n"
            "Pokémon goes out on the hunt."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(BraviaryHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_BraviaryHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 3,
        BACK_PIC(BraviaryHisuian, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(BraviaryHisuian),
        ICON(BraviaryHisuian, 2),
        LEARNSETS(BraviaryHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_RUFFLET

#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 75,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 74,
        .evYield_Defense = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_OVERCOAT, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Vullaby"),
        .cryId = CRY_VULLABY,
        .natDexNum = NATIONAL_DEX_VULLABY,
        .categoryName = _("Diapered"),
        .height = 5,
        .weight = 90,
        .description = COMPOUND_STRING(
            "It can't fly yet and must wait until its\n"
            "wings have developed more. They guard\n"
            "their posteriors with bones that were\n"
            "gathered by Mandibuzz."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vullaby, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Vullaby,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Vullaby, 64, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Vullaby),
        ICON(Vullaby, 0),
        .footprint = gMonFootprint_Vullaby,
        LEARNSETS(Vullaby),
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_MANDIBUZZ}),
    },

    [SPECIES_MANDIBUZZ] =
    {
        .baseHP        = 110,
        .baseAttack    = 65,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = 55,
        .baseSpDefense = 95,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 60,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_OVERCOAT, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mandibuzz"),
        .cryId = CRY_MANDIBUZZ,
        .natDexNum = NATIONAL_DEX_MANDIBUZZ,
        .categoryName = _("Bone Vulture"),
        .height = 12,
        .weight = 395,
        .description = COMPOUND_STRING(
            "They adorn themselves beautifully with\n"
            "bones. This is supposedly an effort to\n"
            "attract males, but no male Mandibuzz\n"
            "have ever been found."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mandibuzz, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Mandibuzz,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Mandibuzz, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Mandibuzz),
        ICON(Mandibuzz, 1),
        .footprint = gMonFootprint_Mandibuzz,
        LEARNSETS(Mandibuzz),
    },
#endif //P_FAMILY_VULLABY

#if P_FAMILY_HEATMOR
    [SPECIES_HEATMOR] =
    {
        .baseHP        = 85,
        .baseAttack    = 97,
        .baseDefense   = 66,
        .baseSpeed     = 65,
        .baseSpAttack  = 105,
        .baseSpDefense = 66,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 90,
        .expYield = 169,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Heatmor"),
        .cryId = CRY_HEATMOR,
        .natDexNum = NATIONAL_DEX_HEATMOR,
        .categoryName = _("Anteater"),
        .height = 14,
        .weight = 580,
        .description = COMPOUND_STRING(
            "It draws in air through its tail, transforms\n"
            "it into fire, and uses it like a tongue.\n"
            "They burn through Durant's steel bodies\n"
            "and consume their insides."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Heatmor, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Heatmor,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Heatmor, 64, 24),
        .backPicYOffset = 21,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Heatmor),
        ICON(Heatmor, 2),
        .footprint = gMonFootprint_Heatmor,
        LEARNSETS(Heatmor),
    },
#endif //P_FAMILY_HEATMOR

#if P_FAMILY_DURANT
    [SPECIES_DURANT] =
    {
        .baseHP        = 58,
        .baseAttack    = 109,
        .baseDefense   = 112,
        .baseSpeed     = 109,
        .baseSpAttack  = 48,
        .baseSpDefense = 48,
        .types = { TYPE_BUG, TYPE_STEEL },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_HUSTLE, ABILITY_TRUANT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Durant"),
        .cryId = CRY_DURANT,
        .natDexNum = NATIONAL_DEX_DURANT,
        .categoryName = _("Iron Ant"),
        .height = 3,
        .weight = 330,
        .description = COMPOUND_STRING(
            "Durant dig nests in mountains.\n"
            "Individuals each play different roles in\n"
            "driving Heatmor, their natural predator,\n"
            "away from their colony."),
        .pokemonScale = 530,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Durant, 48, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Durant,
        .frontAnimId = ANIM_RAPID_H_HOPS,
        BACK_PIC(Durant, 64, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Durant),
        ICON(Durant, 0),
        .footprint = gMonFootprint_Durant,
        LEARNSETS(Durant),
    },
#endif //P_FAMILY_DURANT

#if P_FAMILY_DEINO
    [SPECIES_DEINO] =
    {
        .baseHP        = 52,
        .baseAttack    = 65,
        .baseDefense   = 50,
        .baseSpeed     = 38,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Deino"),
        .cryId = CRY_DEINO,
        .natDexNum = NATIONAL_DEX_DEINO,
        .categoryName = _("Irate"),
        .height = 8,
        .weight = 173,
        .description = COMPOUND_STRING(
            "Lacking sight, it's unaware of its\n"
            "surroundings, so it bumps into things and\n"
            "eats anything that moves. Approaching\n"
            "it carelessly is dangerous."),
        .pokemonScale = 366,
        .pokemonOffset = 12,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Deino, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Deino,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Deino, 48, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Deino),
        ICON(Deino, 2),
        .footprint = gMonFootprint_Deino,
        LEARNSETS(Deino),
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_ZWEILOUS}),
    },

    [SPECIES_ZWEILOUS] =
    {
        .baseHP        = 72,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Zweilous"),
        .cryId = CRY_ZWEILOUS,
        .natDexNum = NATIONAL_DEX_ZWEILOUS,
        .categoryName = _("Hostile"),
        .height = 14,
        .weight = 500,
        .description = COMPOUND_STRING(
            "After it has eaten up all the food in its\n"
            "territory, it moves on to another area.\n"
            "Whichever head eats more than the other\n"
            "gets to be the leader."),
        .pokemonScale = 265,
        .pokemonOffset = 3,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Zweilous, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Zweilous,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Zweilous, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Zweilous),
        ICON(Zweilous, 2),
        .footprint = gMonFootprint_Zweilous,
        LEARNSETS(Zweilous),
        .evolutions = EVOLUTION({EVO_LEVEL, 64, SPECIES_HYDREIGON}),
    },

    [SPECIES_HYDREIGON] =
    {
        .baseHP        = 92,
        .baseAttack    = 105,
        .baseDefense   = 90,
        .baseSpeed     = 98,
        .baseSpAttack  = 125,
        .baseSpDefense = 90,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 270,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Hydreigon"),
        .cryId = CRY_HYDREIGON,
        .natDexNum = NATIONAL_DEX_HYDREIGON,
        .categoryName = _("Brutal"),
        .height = 18,
        .weight = 1600,
        .description = COMPOUND_STRING(
            "This brutal Pokémon travels the skies on\n"
            "its six wings. The heads on their arms do\n"
            "not have brains. They use all three heads\n"
            "to consume and destroy everything."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Hydreigon, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Hydreigon,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 3,
        BACK_PIC(Hydreigon, 64, 56),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Hydreigon),
        ICON(Hydreigon, 2),
        .footprint = gMonFootprint_Hydreigon,
        LEARNSETS(Hydreigon),
    },
#endif //P_FAMILY_DEINO

#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] =
    {
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 50,
        .baseSpDefense = 55,
        .types = { TYPE_BUG, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 72,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Larvesta"),
        .cryId = CRY_LARVESTA,
        .natDexNum = NATIONAL_DEX_LARVESTA,
        .categoryName = _("Torch"),
        .height = 11,
        .weight = 288,
        .description = COMPOUND_STRING(
            "This Pokémon was believed to have\n"
            "been born from the sun. It spews fire from\n"
            "its horns and encases itself in a cocoon\n"
            "of fire when it evolves."),
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Larvesta, 40, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Larvesta,
        .frontAnimId = ANIM_GLOW_ORANGE,
        BACK_PIC(Larvesta, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Larvesta),
        ICON(Larvesta, 0),
        .footprint = gMonFootprint_Larvesta,
        LEARNSETS(Larvesta),
        .evolutions = EVOLUTION({EVO_LEVEL, 59, SPECIES_VOLCARONA}),
    },

    [SPECIES_VOLCARONA] =
    {
        .baseHP        = 85,
        .baseAttack    = 60,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 135,
        .baseSpDefense = 105,
        .types = { TYPE_BUG, TYPE_FIRE },
        .catchRate = 15,
        .expYield = 248,
        .evYield_SpAttack = 3,
        .itemCommon = ITEM_SILVER_POWDER,
        .itemRare = ITEM_SILVER_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Volcarona"),
        .cryId = CRY_VOLCARONA,
        .natDexNum = NATIONAL_DEX_VOLCARONA,
        .categoryName = _("Sun"),
        .height = 16,
        .weight = 460,
        .description = COMPOUND_STRING(
            "When volcanic ash darkened the\n"
            "atmosphere, it appeared and saved Pokémon\n"
            "from freezing, Volcarona's fire provided a\n"
            "replacement for the sun."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Volcarona, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Volcarona,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Volcarona, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Volcarona),
        ICON(Volcarona, 0),
        .footprint = gMonFootprint_Volcarona,
        LEARNSETS(Volcarona),
    },
#endif //P_FAMILY_LARVESTA

#if P_FAMILY_COBALION
    [SPECIES_COBALION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 129,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 72,
        .types = { TYPE_STEEL, TYPE_FIGHTING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Cobalion"),
        .cryId = CRY_COBALION,
        .natDexNum = NATIONAL_DEX_COBALION,
        .categoryName = _("Iron Will"),
        .height = 21,
        .weight = 2500,
        .description = COMPOUND_STRING(
            "It has a body and heart of steel. This\n"
            "legendary Pokémon battled against humans\n"
            "to protect Pokémon. Its personality\n"
            "is calm and composed."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Cobalion, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cobalion,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Cobalion, 48, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Cobalion),
        ICON(Cobalion, 0),
        .footprint = gMonFootprint_Cobalion,
        LEARNSETS(Cobalion),
    },
#endif //P_FAMILY_COBALION

#if P_FAMILY_TERRAKION
    [SPECIES_TERRAKION] =
    {
        .baseHP        = 91,
        .baseAttack    = 129,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 72,
        .baseSpDefense = 90,
        .types = { TYPE_ROCK, TYPE_FIGHTING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .isLegendary = TRUE,
        .speciesName = _("Terrakion"),
        .cryId = CRY_TERRAKION,
        .natDexNum = NATIONAL_DEX_TERRAKION,
        .categoryName = _("Cavern"),
        .height = 19,
        .weight = 2600,
        .description = COMPOUND_STRING(
            "Spoken of in legend, this Pokémon used\n"
            "its phenomenal power to destroy a castle\n"
            "in its effort to protect Pokémon that had\n"
            "lost their homes in a war among humans."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 336,
        .trainerOffset = 4,
        FRONT_PIC(Terrakion, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Terrakion,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Terrakion, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Terrakion),
        ICON(Terrakion, 2),
        .footprint = gMonFootprint_Terrakion,
        LEARNSETS(Terrakion),
    },
#endif //P_FAMILY_TERRAKION

#if P_FAMILY_VIRIZION
    [SPECIES_VIRIZION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 72,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 129,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .isLegendary = TRUE,
        .speciesName = _("Virizion"),
        .cryId = CRY_VIRIZION,
        .natDexNum = NATIONAL_DEX_VIRIZION,
        .categoryName = _("Grassland"),
        .height = 20,
        .weight = 2000,
        .description = COMPOUND_STRING(
            "Its head sprouts horns as sharp as blades.\n"
            "Legends say this Pokémon used\n"
            "whirlwind-like movements to confound\n"
            "and swiftly cut its opponents."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 344,
        .trainerOffset = 4,
        FRONT_PIC(Virizion, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Virizion,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Virizion, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Virizion),
        ICON(Virizion, 1),
        .footprint = gMonFootprint_Virizion,
        LEARNSETS(Virizion),
    },
#endif //P_FAMILY_VIRIZION

#if P_FAMILY_TORNADUS
#define TORNADUS_MISC_INFO                                                              \
        .types = { TYPE_FLYING, TYPE_FLYING },                                          \
        .catchRate = 3,                                                                 \
        .expYield = 261,                                                                \
        .evYield_Attack = 3,                                                            \
        .genderRatio = MON_MALE,                                                        \
        .eggCycles = 120,                                                               \
        .friendship = 90,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_GREEN,                                                  \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Tornadus"),                                                   \
        .natDexNum = NATIONAL_DEX_TORNADUS,                                             \
        .categoryName = _("Cyclone"),                                                   \
        .weight = 630,                                                                  \
        .footprint = gMonFootprint_Tornadus,                                            \
        LEARNSETS(Tornadus),                                                            \
        .formSpeciesIdTable = sTornadusFormSpeciesIdTable,                              \
        .formChangeTable = sTornadusFormChangeTable

    [SPECIES_TORNADUS_INCARNATE] =
    {
        TORNADUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .cryId = CRY_TORNADUS_INCARNATE,
        .height = 15,
        .description = COMPOUND_STRING(
            "Tornadus expels massive energy from\n"
            "its tail, causing severe storms.\n"
            "Its power can blow entire houses away.\n"
            "It zooms through the sky at 200 mph."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(TornadusIncarnate, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_TornadusIncarnate,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(TornadusIncarnate, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(TornadusIncarnate),
        ICON(TornadusIncarnate, 1),
    },

    [SPECIES_TORNADUS_THERIAN] =
    {
        TORNADUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 121,
        .baseSpAttack  = 110,
        .baseSpDefense = 90,
        .abilities = { ABILITY_REGENERATOR, ABILITY_NONE, ABILITY_REGENERATOR },
        .cryId = CRY_TORNADUS_THERIAN,
        .height = 14,
        .description = COMPOUND_STRING(
            "An example of what is known as a\n"
            "“form change”. Tornadus has been\n"
            "sighted crossing the ocean while in this\n"
            "form."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(TornadusTherian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TornadusTherian,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(TornadusTherian, 56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(TornadusTherian),
        ICON(TornadusTherian, 1),
    },
#endif //P_FAMILY_TORNADUS

#if P_FAMILY_THUNDURUS
#define THUNDURUS_MISC_INFO                                                             \
        .types = { TYPE_ELECTRIC, TYPE_FLYING },                                        \
        .catchRate = 3,                                                                 \
        .expYield = 261,                                                                \
        .genderRatio = MON_MALE,                                                        \
        .eggCycles = 120,                                                               \
        .friendship = 90,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_BLUE,                                                   \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Thundurus"),                                                  \
        .natDexNum = NATIONAL_DEX_THUNDURUS,                                            \
        .categoryName = _("Bolt Strike"),                                               \
        .weight = 610,                                                                  \
        .footprint = gMonFootprint_Thundurus,                                           \
        LEARNSETS(Thundurus),                                                           \
        .formSpeciesIdTable = sThundurusFormSpeciesIdTable,                             \
        .formChangeTable = sThundurusFormChangeTable

    [SPECIES_THUNDURUS_INCARNATE] =
    {
        THUNDURUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .evYield_Attack = 3,
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .cryId = CRY_THUNDURUS_INCARNATE,
        .height = 15,
        .description = COMPOUND_STRING(
            "The spikes on its tail discharge immense\n"
            "bolts of lightning. Countless charred\n"
            "remains mar the landscape of places\n"
            "through which Thundurus has passed."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(ThundurusIncarnate, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_ThundurusIncarnate,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(ThundurusIncarnate, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(ThundurusIncarnate),
        ICON(ThundurusIncarnate, 0),
    },

    [SPECIES_THUNDURUS_THERIAN] =
    {
        THUNDURUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 105,
        .baseDefense   = 70,
        .baseSpeed     = 101,
        .baseSpAttack  = 145,
        .baseSpDefense = 80,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NONE, ABILITY_VOLT_ABSORB },
        .cryId = CRY_THUNDURUS_THERIAN,
        .height = 30,
        .description = COMPOUND_STRING(
            "It pulverizes foes into\n"
            "nothingness with showers of devastatingly\n"
            "powerful lightning bolts launched from\n"
            "the string of orbs on its tail."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(ThundurusTherian, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_ThundurusTherian,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 7,
        BACK_PIC(ThundurusTherian, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(ThundurusTherian),
        ICON(ThundurusTherian, 0),
    },
#endif //P_FAMILY_THUNDURUS

#if P_FAMILY_RESHIRAM
    [SPECIES_RESHIRAM] =
    {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .types = { TYPE_DRAGON, TYPE_FIRE },
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isLegendary = TRUE,
        .speciesName = _("Reshiram"),
        .cryId = CRY_RESHIRAM,
        .natDexNum = NATIONAL_DEX_RESHIRAM,
        .categoryName = _("Vast White"),
        .height = 32,
        .weight = 3300,
        .description = COMPOUND_STRING(
            "This Pokémon appears in legends. It\n"
            "sends flames into the air from its tail,\n"
            "burning up everything around it. It helps\n"
            "those who want to build a world of truth."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 445,
        .trainerOffset = 8,
        FRONT_PIC(Reshiram, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Reshiram,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Reshiram, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Reshiram),
        ICON(Reshiram, 0),
        .footprint = gMonFootprint_Reshiram,
        LEARNSETS(Reshiram),
    },
#endif //P_FAMILY_RESHIRAM

#if P_FAMILY_ZEKROM
    [SPECIES_ZEKROM] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        .types = { TYPE_DRAGON, TYPE_ELECTRIC },
        .catchRate = 3,
        .expYield = 306,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isLegendary = TRUE,
        .speciesName = _("Zekrom"),
        .cryId = CRY_ZEKROM,
        .natDexNum = NATIONAL_DEX_ZEKROM,
        .categoryName = _("Deep Black"),
        .height = 29,
        .weight = 3450,
        .description = COMPOUND_STRING(
            "This legendary Pokémon can scorch the\n"
            "world with lightning. It has a generator\n"
            "that creates electricity in its tail. It\n"
            "assists those with strong ideals."),
        .pokemonScale = 275,
        .pokemonOffset = 2,
        .trainerScale = 412,
        .trainerOffset = 10,
        FRONT_PIC(Zekrom, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Zekrom,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Zekrom, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(Zekrom),
        ICON(Zekrom, 2),
        .footprint = gMonFootprint_Zekrom,
        LEARNSETS(Zekrom),
    },
#endif //P_FAMILY_ZEKROM

#if P_FAMILY_LANDORUS
#define LANDORUS_MISC_INFO                                                              \
        .types = { TYPE_GROUND, TYPE_FLYING },                                          \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .genderRatio = MON_MALE,                                                        \
        .eggCycles = 120,                                                               \
        .friendship = 90,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_BROWN,                                                  \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Landorus"),                                                   \
        .natDexNum = NATIONAL_DEX_LANDORUS,                                             \
        .categoryName = _("Abundance"),                                                 \
        .weight = 680,                                                                  \
        .footprint = gMonFootprint_Landorus,                                            \
        LEARNSETS(Landorus),                                                            \
        .formSpeciesIdTable = sLandorusFormSpeciesIdTable,                              \
        .formChangeTable = sLandorusFormChangeTable

    [SPECIES_LANDORUS_INCARNATE] =
    {
        LANDORUS_MISC_INFO,
        .baseHP        = 89,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 101,
        .baseSpAttack  = 115,
        .baseSpDefense = 80,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_SAND_FORCE, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .cryId = CRY_LANDORUS_INCARNATE,
        .height = 15,
        .description = COMPOUND_STRING(
            "The energy that comes pouring from its tail\n"
            "increases the nutrition in the soil, making\n"
            "crops grow to great size. It has been\n"
            "hailed as “The Guardian of the Fields.”"),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(LandorusIncarnate, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_LandorusIncarnate,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(LandorusIncarnate, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(LandorusIncarnate),
        ICON(LandorusIncarnate, 0),
    },

    [SPECIES_LANDORUS_THERIAN] =
    {
        LANDORUS_MISC_INFO,
        .baseHP        = 89,
        .baseAttack    = 145,
        .baseDefense   = 90,
        .baseSpeed     = 91,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .evYield_Attack = 3,
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE },
        .cryId = CRY_LANDORUS_THERIAN,
        .height = 13,
        .description = COMPOUND_STRING(
            "Landorus soars through the sky in\n"
            "this form, bestowing plentiful\n"
            "harvests upon the land and earning the\n"
            "people's reverence."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(LandorusTherian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_LandorusTherian,
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        BACK_PIC(LandorusTherian, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(LandorusTherian),
        ICON(LandorusTherian, 0),
    },
#endif //P_FAMILY_LANDORUS

#if P_FAMILY_KYUREM
#define KYUREM_MISC_INFO                                                                \
        .types = { TYPE_DRAGON, TYPE_ICE },                                             \
        .catchRate = 3,                                                                 \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_GRAY,                                                   \
        .noFlip = TRUE,                                                                 \
        .speciesName = _("Kyurem"),                                                     \
        .natDexNum = NATIONAL_DEX_KYUREM,                                               \
        .categoryName = _("Boundary"),                                                  \
        .weight = 3250,                                                                 \
        .footprint = gMonFootprint_Kyurem,                                              \
        .formSpeciesIdTable = sKyuremFormSpeciesIdTable,                                \
        .isLegendary = TRUE

    [SPECIES_KYUREM] =
    {
        KYUREM_MISC_INFO,
        .baseHP        = 125,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .expYield = 297,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE },
        .cryId = CRY_KYUREM,
        .height = 30,
        .description = COMPOUND_STRING(
            "This legendary ice Pokémon waits for a\n"
            "hero to fill in the missing parts of its\n"
            "body with truth or ideals. Its body became\n"
            "frozen when its energy leaked out."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        FRONT_PIC(Kyurem, 64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Kyurem,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Kyurem, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Kyurem),
        ICON(Kyurem, 0),
        LEARNSETS(Kyurem),
    },

#if P_FUSION_FORMS
    [SPECIES_KYUREM_WHITE] =
    {
        KYUREM_MISC_INFO,
        .baseHP        = 125,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 170,
        .baseSpDefense = 100,
        .expYield = 315,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE },
        .cryId = CRY_KYUREM_WHITE,
        .height = 36,
        .description = COMPOUND_STRING(
            "The sameness of Reshiram's and\n"
            "Kyurem's genes allowed Kyurem to\n"
            "absorb Reshiram. Kyurem can now use the\n"
            "power of both fire and ice."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        FRONT_PIC(KyuremWhite, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_KyuremWhite,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(KyuremWhite, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(KyuremWhite),
        ICON(KyuremWhite, 0),
        .levelUpLearnset = sKyuremWhiteLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .cannotBeTraded = TRUE,
    },

    [SPECIES_KYUREM_BLACK] =
    {
        KYUREM_MISC_INFO,
        .baseHP        = 125,
        .baseAttack    = 170,
        .baseDefense   = 100,
        .baseSpeed     = 95,
        .baseSpAttack  = 120,
        .baseSpDefense = 90,
        .expYield = 315,
        .evYield_Attack = 3,
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE },
        .cryId = CRY_KYUREM_BLACK,
        .height = 33,
        .description = COMPOUND_STRING(
            "The sameness of Zekrom's and\n"
            "Kyurem's genes allowed Kyurem to absorb\n"
            "Zekrom. Kyurem can now use the\n"
            "power of both electricity and ice."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        FRONT_PIC(KyuremBlack, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_KyuremBlack,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(KyuremBlack, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(KyuremBlack),
        ICON(KyuremBlack, 0),
        .levelUpLearnset = sKyuremBlackLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .cannotBeTraded = TRUE,
    },
#endif //P_FUSION_FORMS
#endif //P_FAMILY_KYUREM

#if P_FAMILY_KELDEO
#define KELDEO_MISC_INFO                                                                \
        .baseHP        = 91,                                                            \
        .baseAttack    = 72,                                                            \
        .baseDefense   = 90,                                                            \
        .baseSpeed     = 108,                                                           \
        .baseSpAttack  = 129,                                                           \
        .baseSpDefense = 90,                                                            \
        .types = { TYPE_WATER, TYPE_FIGHTING },                                         \
        .catchRate = 3,                                                                 \
        .expYield = 261,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 80,                                                                \
        .friendship = 35,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },                               \
        .bodyColor = BODY_COLOR_YELLOW,                                                 \
        .isMythical = TRUE,                                                             \
        .speciesName = _("Keldeo"),                                                     \
        .cryId = CRY_KELDEO,                                                            \
        .natDexNum = NATIONAL_DEX_KELDEO,                                               \
        .categoryName = _("Colt"),                                                      \
        .height = 14,                                                                   \
        .weight = 485,                                                                  \
        .pokemonScale = 265,                                                            \
        .pokemonOffset = 2,                                                             \
        .trainerScale = 262,                                                            \
        .trainerOffset = 0,                                                             \
        .footprint = gMonFootprint_Keldeo,                                              \
        LEARNSETS(Keldeo),                                                              \
        .formSpeciesIdTable = sKeldeoFormSpeciesIdTable,                                \
        .formChangeTable = sKeldeoFormChangeTable

    [SPECIES_KELDEO_ORDINARY] =
    {
        KELDEO_MISC_INFO,
        .description = COMPOUND_STRING(
            "When it is resolute, its body fills with\n"
            "power and it becomes swifter. It crosses\n"
            "the world, running over the surfaces of\n"
            "oceans and rivers."),
        FRONT_PIC(KeldeoOrdinary, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_KeldeoOrdinary,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(KeldeoOrdinary, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(KeldeoOrdinary),
        ICON(KeldeoOrdinary, 0),
    },

    [SPECIES_KELDEO_RESOLUTE] =
    {
        KELDEO_MISC_INFO,
        .noFlip = TRUE,
        .description = COMPOUND_STRING(
            "The power that lay hidden in its\n"
            "body now covers its horn, turning it\n"
            "into a sword that can slice through\n"
            "anything."),
        FRONT_PIC(KeldeoResolute, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_KeldeoResolute,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(KeldeoResolute, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(KeldeoResolute),
        ICON(KeldeoResolute, 0),
    },
#endif //P_FAMILY_KELDEO

#if P_FAMILY_MELOETTA
#define MELOETTA_MISC_INFO                                                              \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_Speed = 1,                                                             \
        .itemCommon = ITEM_STAR_PIECE,                                                  \
        .itemRare = ITEM_STAR_PIECE,                                                    \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 100,                                                              \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_NONE },                            \
        .bodyColor = BODY_COLOR_WHITE,                                                  \
        .noFlip = TRUE,                                                                 \
        .isMythical = TRUE,                                                             \
        .speciesName = _("Meloetta"),                                                   \
        .cryId = CRY_MELOETTA,                                                          \
        .natDexNum = NATIONAL_DEX_MELOETTA,                                             \
        .categoryName = _("Melody"),                                                    \
        .height = 6,                                                                    \
        .weight = 65,                                                                   \
        .pokemonScale = 422,                                                            \
        .pokemonOffset = 12,                                                            \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        .footprint = gMonFootprint_Meloetta,                                            \
        LEARNSETS(Meloetta),                                                            \
        .formSpeciesIdTable = sMeloettaFormSpeciesIdTable,                              \
        .formChangeTable = sMeloettaFormChangeTable

    [SPECIES_MELOETTA_ARIA] =
    {
        MELOETTA_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 77,
        .baseDefense   = 77,
        .baseSpeed     = 90,
        .baseSpAttack  = 128,
        .baseSpDefense = 128,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC },
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .description = COMPOUND_STRING(
            "The melodies sung by Meloetta have the\n"
            "power to make Pokémon that hear them\n"
            "happy or sad. Many famous songs have been\n"
            "inspired by the tunes that Meloetta plays."),
        FRONT_PIC(MeloettaAria, 32, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_MeloettaAria,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 8,
        BACK_PIC(MeloettaAria, 48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(MeloettaAria),
        ICON(MeloettaAria, 4),
    },

    [SPECIES_MELOETTA_PIROUETTE] =
    {
        MELOETTA_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 128,
        .baseDefense   = 90,
        .baseSpeed     = 128,
        .baseSpAttack  = 77,
        .baseSpDefense = 77,
        .types = { TYPE_NORMAL, TYPE_FIGHTING },
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .description = COMPOUND_STRING(
            "Meloetta's melodies are sung with\n"
            "a special vocalization method that can\n"
            "control the feelings of those who hear it."),
        FRONT_PIC(MeloettaPirouette, 40, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_MeloettaPirouette,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .enemyMonElevation = 5,
        BACK_PIC(MeloettaPirouette, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(MeloettaPirouette),
        ICON(MeloettaPirouette, 0),
    },
#endif //P_FAMILY_MELOETTA

#if P_FAMILY_GENESECT
#define GENESECT_SPECIES_INFO(form)                                                     \
    {                                                                                   \
        .baseHP        = 71,                                                            \
        .baseAttack    = 120,                                                           \
        .baseDefense   = 95,                                                            \
        .baseSpeed     = 99,                                                            \
        .baseSpAttack  = 120,                                                           \
        .baseSpDefense = 95,                                                            \
        .types = { TYPE_BUG, TYPE_STEEL },                                              \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_Attack = 1,                                                            \
        .evYield_Speed = 1,                                                             \
        .evYield_SpAttack = 1,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_DOWNLOAD, ABILITY_NONE },                                \
        .bodyColor = BODY_COLOR_PURPLE,                                                 \
        .speciesName = _("Genesect"),                                                   \
        .cryId = CRY_GENESECT,                                                          \
        .natDexNum = NATIONAL_DEX_GENESECT,                                             \
        .categoryName = _("Paleozoic"),                                                 \
        .height = 15,                                                                   \
        .weight = 825,                                                                  \
        .description = gGenesectPokedexText,                                            \
        .pokemonScale = 268,                                                            \
        .pokemonOffset = 2,                                                             \
        .trainerScale = 271,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Genesect, 56, 64),                                                    \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Genesect,                                             \
        .frontAnimId = ANIM_H_VIBRATE,                                                  \
        BACK_PIC(Genesect, 64, 48),                                                     \
        .backPicYOffset = 8,                                                            \
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,                                \
        PALETTES(form),                                                                 \
        ICON(Genesect, 2),                                                              \
        .footprint = gMonFootprint_Genesect,                                            \
        LEARNSETS(Genesect),                                                            \
        .formSpeciesIdTable = sGenesectFormSpeciesIdTable,                              \
        .formChangeTable = sGenesectFormChangeTable,                                    \
        .isMythical = TRUE,                                                             \
    }

    [SPECIES_GENESECT]             = GENESECT_SPECIES_INFO(Genesect),
    [SPECIES_GENESECT_DOUSE_DRIVE] = GENESECT_SPECIES_INFO(GenesectDouseDrive),
    [SPECIES_GENESECT_SHOCK_DRIVE] = GENESECT_SPECIES_INFO(GenesectShockDrive),
    [SPECIES_GENESECT_BURN_DRIVE]  = GENESECT_SPECIES_INFO(GenesectBurnDrive),
    [SPECIES_GENESECT_CHILL_DRIVE] = GENESECT_SPECIES_INFO(GenesectChillDrive),
#endif //P_FAMILY_GENESECT

#ifdef __INTELLISENSE__
};
#endif