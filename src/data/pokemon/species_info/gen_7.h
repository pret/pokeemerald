#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen7[] =
{
#endif

#if P_FAMILY_ROWLET
    [SPECIES_ROWLET] =
    {
        .baseHP        = 68,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 42,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 64,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LONG_REACH },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Rowlet"),
        .cryId = CRY_ROWLET,
        .natDexNum = NATIONAL_DEX_ROWLET,
        .categoryName = _("Grass Quill"),
        .height = 3,
        .weight = 15,
        .description = COMPOUND_STRING(
            "This wary Pokémon uses photosynthesis\n"
            "to store up energy during the day, while\n"
            "becoming active at night. Silently it\n"
            "glides, drawing near to its target."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Rowlet, 31, 37),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Rowlet,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Rowlet, 43, 36),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Rowlet),
        ICON(Rowlet, 0),
        .footprint = gMonFootprint_Rowlet,
        LEARNSETS(Rowlet),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_DARTRIX}),
    },

    [SPECIES_DARTRIX] =
    {
        .baseHP        = 78,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 52,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 147,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LONG_REACH },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Dartrix"),
        .cryId = CRY_DARTRIX,
        .natDexNum = NATIONAL_DEX_DARTRIX,
        .categoryName = _("Blade Quill"),
        .height = 7,
        .weight = 160,
        .description = COMPOUND_STRING(
            "A bit of a dandy, it spends its free time\n"
            "preening its wings. Its preoccupation\n"
            "with any dirt on its plumage can leave\n"
            "it unable to battle."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dartrix, 34, 47),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Dartrix,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Dartrix, 56, 54),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Dartrix),
        ICON(Dartrix, 1),
        .footprint = gMonFootprint_Dartrix,
        LEARNSETS(Dartrix),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_DECIDUEYE},
                                {EVO_NONE, 0, SPECIES_DECIDUEYE_HISUIAN}),
    },

#define DECIDUEYE_MISC_INFO                                     \
        .catchRate = 45,                                        \
        .expYield = 239,                                        \
        .evYield_Attack = 3,                                    \
        .genderRatio = PERCENT_FEMALE(12.5),                    \
        .eggCycles = 15,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_SLOW,                       \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },    \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .speciesName = _("Decidueye"),                          \
        .cryId = CRY_DECIDUEYE,                                 \
        .natDexNum = NATIONAL_DEX_DECIDUEYE,                    \
        .categoryName = _("Arrow Quill"),                       \
        .height = 16,                                           \
        .pokemonScale = 259,                                    \
        .pokemonOffset = 1,                                     \
        .trainerScale = 296,                                    \
        .trainerOffset = 1,                                     \
        .footprint = gMonFootprint_Decidueye,                   \
        .formSpeciesIdTable = sDecidueyeFormSpeciesIdTable

    [SPECIES_DECIDUEYE] =
    {
        DECIDUEYE_MISC_INFO,
        .baseHP        = 78,
        .baseAttack    = 107,
        .baseDefense   = 75,
        .baseSpeed     = 70,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_GHOST },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LONG_REACH },
        .weight = 366,
        .description = COMPOUND_STRING(
            "Decidueye is cool and cautious.\n"
            "It fires arrow quills from its wings with\n"
            "such precision, they can pierce a pebble\n"
            "at distances of over a hundred yards."),
        FRONT_PIC(Decidueye, 45, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Decidueye,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Decidueye, 46, 62),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Decidueye),
        ICON(Decidueye, 1),
        LEARNSETS(Decidueye),
    },

#if P_HISUIAN_FORMS
    [SPECIES_DECIDUEYE_HISUIAN] =
    {
        DECIDUEYE_MISC_INFO,
        .baseHP        = 88,
        .baseAttack    = 112,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 95,
        .baseSpDefense = 95,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_SCRAPPY },
        .weight = 370,
        .description = COMPOUND_STRING(
            "The air stored inside the rachises\n"
            "of Decidueye's feathers insulates\n"
            "the Pokémon against Hisui's extreme\n"
            "cold."),
        FRONT_PIC(DecidueyeHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DecidueyeHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DecidueyeHisuian, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DecidueyeHisuian),
        ICON(DecidueyeHisuian, 0),
        LEARNSETS(DecidueyeHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_ROWLET

#if P_FAMILY_LITTEN
    [SPECIES_LITTEN] =
    {
        .baseHP        = 45,
        .baseAttack    = 65,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 40,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 64,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Litten"),
        .cryId = CRY_LITTEN,
        .natDexNum = NATIONAL_DEX_LITTEN,
        .categoryName = _("Fire Cat"),
        .height = 4,
        .weight = 43,
        .description = COMPOUND_STRING(
            "While grooming itself, it builds up fur\n"
            "inside its stomach. It sets the fur alight\n"
            "and spews fiery attacks, which change\n"
            "based on how it coughs."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Litten, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Litten,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Litten, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Litten),
        ICON(Litten, 0),
        .footprint = gMonFootprint_Litten,
        LEARNSETS(Litten),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_TORRACAT}),
    },

    [SPECIES_TORRACAT] =
    {
        .baseHP        = 65,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 90,
        .baseSpAttack  = 80,
        .baseSpDefense = 50,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Torracat"),
        .cryId = CRY_TORRACAT,
        .natDexNum = NATIONAL_DEX_TORRACAT,
        .categoryName = _("Fire Cat"),
        .height = 7,
        .weight = 250,
        .description = COMPOUND_STRING(
            "At its throat, it bears a bell of fire. The\n"
            "bell rings brightly whenever this Pokémon\n"
            "spits fire. With a single punch, it can bend\n"
            "an iron bar right over."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Torracat, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Torracat,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Torracat, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Torracat),
        ICON(Torracat, 0),
        .footprint = gMonFootprint_Torracat,
        LEARNSETS(Torracat),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_INCINEROAR}),
    },

    [SPECIES_INCINEROAR] =
    {
        .baseHP        = 95,
        .baseAttack    = 115,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = { TYPE_FIRE, TYPE_DARK },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Incineroar"),
        .cryId = CRY_INCINEROAR,
        .natDexNum = NATIONAL_DEX_INCINEROAR,
        .categoryName = _("Heel"),
        .height = 18,
        .weight = 830,
        .description = COMPOUND_STRING(
            "This Pokémon has a violent, selfish\n"
            "disposition. If it's not in the mood to\n"
            "listen, it will ignore its Trainer's orders\n"
            "with complete nonchalance."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Incineroar, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Incineroar,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Incineroar, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Incineroar),
        ICON(Incineroar, 0),
        .footprint = gMonFootprint_Incineroar,
        LEARNSETS(Incineroar),
    },
#endif //P_FAMILY_LITTEN

#if P_FAMILY_POPPLIO
    [SPECIES_POPPLIO] =
    {
        .baseHP        = 50,
        .baseAttack    = 54,
        .baseDefense   = 54,
        .baseSpeed     = 40,
        .baseSpAttack  = 66,
        .baseSpDefense = 56,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_LIQUID_VOICE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Popplio"),
        .cryId = CRY_POPPLIO,
        .natDexNum = NATIONAL_DEX_POPPLIO,
        .categoryName = _("Sea Lion"),
        .height = 4,
        .weight = 75,
        .description = COMPOUND_STRING(
            "This Pokémon snorts body fluids from\n"
            "its nose, blowing balloons to smash into\n"
            "its foes. It practices diligently so it can\n"
            "learn to make big bubbles."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Popplio, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Popplio,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Popplio, 48, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Popplio),
        ICON(Popplio, 0),
        .footprint = gMonFootprint_Popplio,
        LEARNSETS(Popplio),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_BRIONNE}),
    },

    [SPECIES_BRIONNE] =
    {
        .baseHP        = 60,
        .baseAttack    = 69,
        .baseDefense   = 69,
        .baseSpeed     = 50,
        .baseSpAttack  = 91,
        .baseSpDefense = 81,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 147,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_LIQUID_VOICE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Brionne"),
        .cryId = CRY_BRIONNE,
        .natDexNum = NATIONAL_DEX_BRIONNE,
        .categoryName = _("Pop Star"),
        .height = 6,
        .weight = 175,
        .description = COMPOUND_STRING(
            "It cares deeply for its companions.\n"
            "When its Trainer is feeling down, it\n"
            "performs a cheery dance with a sequence\n"
            "of water balloons  to try and help."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Brionne, 48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Brionne,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Brionne, 48, 56),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Brionne),
        ICON(Brionne, 0),
        .footprint = gMonFootprint_Brionne,
        LEARNSETS(Brionne),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_PRIMARINA}),
    },

    [SPECIES_PRIMARINA] =
    {
        .baseHP        = 80,
        .baseAttack    = 74,
        .baseDefense   = 74,
        .baseSpeed     = 60,
        .baseSpAttack  = 126,
        .baseSpDefense = 116,
        .types = { TYPE_WATER, TYPE_FAIRY },
        .catchRate = 45,
        .expYield = 239,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_LIQUID_VOICE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Primarina"),
        .cryId = CRY_PRIMARINA,
        .natDexNum = NATIONAL_DEX_PRIMARINA,
        .categoryName = _("Soloist"),
        .height = 18,
        .weight = 440,
        .description = COMPOUND_STRING(
            "It controls its water balloons with song.\n"
            "The melody is learned from others of\n"
            "its kind and is passed down from one\n"
            "generation to the next."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Primarina, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Primarina,
        .frontAnimId = ANIM_SHAKE_GLOW_BLUE_SLOW,
        BACK_PIC(Primarina, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Primarina),
        ICON(Primarina, 0),
        .footprint = gMonFootprint_Primarina,
        LEARNSETS(Primarina),
    },
#endif //P_FAMILY_POPPLIO

#if P_FAMILY_PIKIPEK
    [SPECIES_PIKIPEK] =
    {
        .baseHP        = 35,
        .baseAttack    = 75,
        .baseDefense   = 30,
        .baseSpeed     = 65,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 53,
        .evYield_Attack = 1,
        .itemRare = ITEM_ORAN_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SKILL_LINK, ABILITY_PICKUP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Pikipek"),
        .cryId = CRY_PIKIPEK,
        .natDexNum = NATIONAL_DEX_PIKIPEK,
        .categoryName = _("Woodpecker"),
        .height = 3,
        .weight = 12,
        .description = COMPOUND_STRING(
            "This Pokémon feeds on berries, whose\n"
            "leftover seeds become the ammunition for\n"
            "the attacks it fires off from its mouth.\n"
            "It uses holes in trees for nesting."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pikipek, 29, 40),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Pikipek,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Pikipek, 48, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Pikipek),
        ICON(Pikipek, 2),
        .footprint = gMonFootprint_Pikipek,
        LEARNSETS(Pikipek),
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_TRUMBEAK}),
    },

    [SPECIES_TRUMBEAK] =
    {
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 124,
        .evYield_Attack = 2,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SKILL_LINK, ABILITY_PICKUP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Trumbeak"),
        .cryId = CRY_TRUMBEAK,
        .natDexNum = NATIONAL_DEX_TRUMBEAK,
        .categoryName = _("Bugle Beak"),
        .height = 6,
        .weight = 148,
        .description = COMPOUND_STRING(
            "By bending its beak, it can produce a\n"
            "variety of calls and brand itself a noisy\n"
            "nuisance for its neighbors. It eats\n"
            "berries and stores their seeds in its beak."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Trumbeak, 44, 53),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Trumbeak,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Trumbeak, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Trumbeak),
        ICON(Trumbeak, 0),
        .footprint = gMonFootprint_Trumbeak,
        LEARNSETS(Trumbeak),
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_TOUCANNON}),
    },

    [SPECIES_TOUCANNON] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 75,
        .baseSpeed     = 60,
        .baseSpAttack  = 75,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 218,
        .evYield_Attack = 3,
        .itemRare = ITEM_RAWST_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SKILL_LINK, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Toucannon"),
        .cryId = CRY_TOUCANNON,
        .natDexNum = NATIONAL_DEX_TOUCANNON,
        .categoryName = _("Cannon"),
        .height = 11,
        .weight = 260,
        .description = COMPOUND_STRING(
            "When it battles, within its beak, its\n"
            "internal gases ignite, explosively\n"
            "launching seeds with enough power to\n"
            "pulverize boulders."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Toucannon, 59, 59),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Toucannon,
        .frontAnimId = ANIM_SHAKE_GLOW_RED_SLOW,
        BACK_PIC(Toucannon, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Toucannon),
        ICON(Toucannon, 0),
        .footprint = gMonFootprint_Toucannon,
        LEARNSETS(Toucannon),
    },
#endif //P_FAMILY_PIKIPEK

#if P_FAMILY_YUNGOOS
    [SPECIES_YUNGOOS] =
    {
        .baseHP        = 48,
        .baseAttack    = 70,
        .baseDefense   = 30,
        .baseSpeed     = 45,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 51,
        .evYield_Attack = 1,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STAKEOUT, ABILITY_STRONG_JAW, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Yungoos"),
        .cryId = CRY_YUNGOOS,
        .natDexNum = NATIONAL_DEX_YUNGOOS,
        .categoryName = _("Loitering"),
        .height = 4,
        .weight = 60,
        .description = COMPOUND_STRING(
            "With its sharp fangs, it will bite anything.\n"
            "It wanders around in a never-ending\n"
            "search for food. At dusk, it collapses\n"
            "and falls asleep on the spot."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Yungoos, 64, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Yungoos,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Yungoos, 48, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Yungoos),
        ICON(Yungoos, 2),
        .footprint = gMonFootprint_Yungoos,
        LEARNSETS(Yungoos),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 20, SPECIES_GUMSHOOS}),
    },

    [SPECIES_GUMSHOOS] =
    {
        .baseHP        = 88,
        .baseAttack    = 110,
        .baseDefense   = 60,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 127,
        .expYield = 146,
        .evYield_Attack = 2,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STAKEOUT, ABILITY_STRONG_JAW, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Gumshoos"),
        .cryId = CRY_GUMSHOOS,
        .natDexNum = NATIONAL_DEX_GUMSHOOS,
        .categoryName = _("Stakeout"),
        .height = 7,
        .weight = 142,
        .description = COMPOUND_STRING(
            "When it finds a trace of its prey, it\n"
            "patiently stakes out the location...\n"
            "but as it's diurnal, it's always snoozing\n"
            "by nightfall."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gumshoos, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Gumshoos,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Gumshoos, 48, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Gumshoos),
        ICON(Gumshoos, 2),
        .footprint = gMonFootprint_Gumshoos,
        LEARNSETS(Gumshoos),
    },
#endif //P_FAMILY_YUNGOOS

#if P_FAMILY_GRUBBIN
    [SPECIES_GRUBBIN] =
    {
        .baseHP        = 47,
        .baseAttack    = 62,
        .baseDefense   = 45,
        .baseSpeed     = 46,
        .baseSpAttack  = 55,
        .baseSpDefense = 45,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Grubbin"),
        .cryId = CRY_GRUBBIN,
        .natDexNum = NATIONAL_DEX_GRUBBIN,
        .categoryName = _("Larva"),
        .height = 4,
        .weight = 44,
        .description = COMPOUND_STRING(
            "They often gather near places frequented\n"
            "by electric Pokémon in order to avoid being\n"
            "attacked by bird Pokémon, though it\n"
            "normally lives underground."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Grubbin, 48, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Grubbin,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Grubbin, 64, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Grubbin),
        ICON(Grubbin, 0),
        .footprint = gMonFootprint_Grubbin,
        LEARNSETS(Grubbin),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_CHARJABUG}),
    },

    [SPECIES_CHARJABUG] =
    {
        .baseHP        = 57,
        .baseAttack    = 82,
        .baseDefense   = 95,
        .baseSpeed     = 36,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 120,
        .expYield = 140,
        .evYield_Defense = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_BATTERY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Charjabug"),
        .cryId = CRY_CHARJABUG,
        .natDexNum = NATIONAL_DEX_CHARJABUG,
        .categoryName = _("Battery"),
        .height = 5,
        .weight = 105,
        .description = COMPOUND_STRING(
            "From the food it digests, it generates\n"
            "electricity, and it stores this energy in\n"
            "its electric sac. On camping trips, people\n"
            "are grateful to have one around."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Charjabug, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Charjabug,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW_SLOW,
        BACK_PIC(Charjabug, 64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Charjabug),
        ICON(Charjabug, 1),
        .footprint = gMonFootprint_Charjabug,
        LEARNSETS(Charjabug),
        .evolutions = EVOLUTION({EVO_MAPSEC, MAPSEC_NEW_MAUVILLE, SPECIES_VIKAVOLT},
                                {EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VIKAVOLT}),
    },

    [SPECIES_VIKAVOLT] =
    {
        .baseHP        = 77,
        .baseAttack    = 70,
        .baseDefense   = 90,
        .baseSpeed     = 43,
        .baseSpAttack  = 145,
        .baseSpDefense = 75,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 45,
        .expYield = 225,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Vikavolt"),
        .cryId = CRY_VIKAVOLT,
        .natDexNum = NATIONAL_DEX_VIKAVOLT,
        .categoryName = _("Stag Beetle"),
        .height = 15,
        .weight = 450,
        .description = COMPOUND_STRING(
            "It concentrates electrical energy within\n"
            "its large jaws and uses it to zap its foes.\n"
            "It overwhelms bird Pokémon with shocking\n"
            "beams of electrical energy."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Vikavolt, 64, 56),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Vikavolt,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .enemyMonElevation = 8,
        BACK_PIC(Vikavolt, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Vikavolt),
        ICON(Vikavolt, 0),
        .footprint = gMonFootprint_Vikavolt,
        LEARNSETS(Vikavolt),
    },
#endif //P_FAMILY_GRUBBIN

#if P_FAMILY_CRABRAWLER
    [SPECIES_CRABRAWLER] =
    {
        .baseHP        = 47,
        .baseAttack    = 82,
        .baseDefense   = 57,
        .baseSpeed     = 63,
        .baseSpAttack  = 42,
        .baseSpDefense = 47,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 225,
        .expYield = 68,
        .evYield_Attack = 1,
        .itemRare = ITEM_ASPEAR_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_IRON_FIST, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Crabrawler"),
        .cryId = CRY_CRABRAWLER,
        .natDexNum = NATIONAL_DEX_CRABRAWLER,
        .categoryName = _("Boxing"),
        .height = 6,
        .weight = 70,
        .description = COMPOUND_STRING(
            "While guarding its weak points with its\n"
            "pincers, it looks for an opening and\n"
            "unleashes punches. When it loses, it\n"
            "foams at the mouth and faints."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Crabrawler, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Crabrawler,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Crabrawler, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Crabrawler),
        ICON(Crabrawler, 2),
        .footprint = gMonFootprint_Crabrawler,
        LEARNSETS(Crabrawler),
        .evolutions = EVOLUTION({EVO_SPECIFIC_MAP, MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM, SPECIES_CRABOMINABLE},
                                {EVO_ITEM, ITEM_ICE_STONE, SPECIES_CRABOMINABLE}),
    },

    [SPECIES_CRABOMINABLE] =
    {
        .baseHP        = 97,
        .baseAttack    = 132,
        .baseDefense   = 77,
        .baseSpeed     = 43,
        .baseSpAttack  = 62,
        .baseSpDefense = 67,
        .types = { TYPE_FIGHTING, TYPE_ICE },
        .catchRate = 60,
        .expYield = 167,
        .evYield_Attack = 2,
        .itemRare = ITEM_CHERI_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_IRON_FIST, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Crabminabl"),
        .cryId = CRY_CRABOMINABLE,
        .natDexNum = NATIONAL_DEX_CRABOMINABLE,
        .categoryName = _("Woolly Crab"),
        .height = 17,
        .weight = 1800,
        .description = COMPOUND_STRING(
            "It aimed for the top but got lost and\n"
            "ended up on a snowy mountain. Being forced\n"
            "to endure the cold, this Pokémon evolved\n"
            "and grew thick fur."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Crabominable, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Crabominable,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Crabominable, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Crabominable),
        ICON(Crabominable, 2),
        .footprint = gMonFootprint_Crabominable,
        LEARNSETS(Crabominable),
    },
#endif //P_FAMILY_CRABRAWLER

#if P_FAMILY_ORICORIO
#define ORICORIO_MISC_INFO                                      \
        .baseHP        = 75,                                    \
        .baseAttack    = 70,                                    \
        .baseDefense   = 70,                                    \
        .baseSpeed     = 93,                                    \
        .baseSpAttack  = 98,                                    \
        .baseSpDefense = 70,                                    \
        .catchRate = 45,                                        \
        .expYield = 167,                                        \
        .evYield_SpAttack = 2,                                  \
        .itemRare = ITEM_HONEY,                                 \
        .genderRatio = PERCENT_FEMALE(75),                      \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },    \
        .abilities = { ABILITY_DANCER, ABILITY_NONE },          \
        .speciesName = _("Oricorio"),                           \
        .natDexNum = NATIONAL_DEX_ORICORIO,                     \
        .categoryName = _("Dancing"),                           \
        .height = 6,                                            \
        .weight = 34,                                           \
        .pokemonScale = 422,                                    \
        .pokemonOffset = 12,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .frontAnimFrames = sAnims_Oricorio,                     \
        .backPicYOffset = 0,                                    \
        .footprint = gMonFootprint_Oricorio,                    \
        LEARNSETS(Oricorio),                                    \
        .formSpeciesIdTable = sOricorioFormSpeciesIdTable,      \
        .formChangeTable = sOricorioFormChangeTable
        //.backAnimId = BACK_ANIM_NONE,                       \

    [SPECIES_ORICORIO_BAILE] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .bodyColor = BODY_COLOR_RED,
        .cryId = CRY_ORICORIO_BAILE,
        .description = COMPOUND_STRING(
            "It wins the hearts of its enemies\n"
            "with its passionate dancing and then\n"
            "uses the opening it creates to\n"
            "burn them up with blazing flames."),
        FRONT_PIC(OricorioBaile, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimId = ANIM_CONCAVE_ARC_SMALL,
        BACK_PIC(OricorioBaile, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioBaile),
        ICON(OricorioBaile, 0),
    },

    [SPECIES_ORICORIO_POM_POM] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_ELECTRIC, TYPE_FLYING },
        .bodyColor = BODY_COLOR_YELLOW,
        .cryId = CRY_ORICORIO_POM_POM,
        .description = COMPOUND_STRING(
            "This form of Oricorio has sipped\n"
            "yellow nectar. It uses nimble steps to\n"
            "approach opponents, then knocks\n"
            "them out with electric punches."),
        FRONT_PIC(OricorioPomPom, 56, 56),
        .frontPicYOffset = 5,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(OricorioPomPom, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioPomPom),
        ICON(OricorioPomPom, 1),
    },

    [SPECIES_ORICORIO_PAU] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .bodyColor = BODY_COLOR_PINK,
        .cryId = CRY_ORICORIO_PAU,
        .description = COMPOUND_STRING(
            "This form of Oricorio has sipped\n"
            "pink nectar. It elevates its mind with\n"
            "the gentle steps of its dance, then\n"
            "unleashes its psychic energy."),
        FRONT_PIC(OricorioPau, 56, 64),
        .frontPicYOffset = 3,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(OricorioPau, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioPau),
        ICON(OricorioPau, 1),
    },

    [SPECIES_ORICORIO_SENSU] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_GHOST, TYPE_FLYING },
        .bodyColor = BODY_COLOR_PURPLE,
        .cryId = CRY_ORICORIO_SENSU,
        .description = COMPOUND_STRING(
            "It charms its opponents with its\n"
            "refined dancing. When they let their\n"
            "guard down, it places a curse on\n"
            "them that will bring on their demise."),
        FRONT_PIC(OricorioSensu, 64, 56),
        .frontPicYOffset = 4,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(OricorioSensu, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioSensu),
        ICON(OricorioSensu, 0),
    },
#endif //P_FAMILY_ORICORIO

#if P_FAMILY_CUTIEFLY
    [SPECIES_CUTIEFLY] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 84,
        .baseSpAttack  = 55,
        .baseSpDefense = 40,
        .types = { TYPE_BUG, TYPE_FAIRY },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Speed = 1,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HONEY_GATHER, ABILITY_SHIELD_DUST, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Cutiefly"),
        .cryId = CRY_CUTIEFLY,
        .natDexNum = NATIONAL_DEX_CUTIEFLY,
        .categoryName = _("Bee Fly"),
        .height = 1,
        .weight = 2,
        .description = COMPOUND_STRING(
            "Myriads of Cutiefly flutter above the\n"
            "heads of people who have auras resembling\n"
            "those of flowers. It can identify which\n"
            "flowers are about to bloom."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cutiefly, 33, 35),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Cutiefly,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        BACK_PIC(Cutiefly, 56, 48),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Cutiefly),
        ICON(Cutiefly, 2),
        .footprint = gMonFootprint_Cutiefly,
        LEARNSETS(Cutiefly),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_RIBOMBEE}),
    },

    [SPECIES_RIBOMBEE] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 60,
        .baseSpeed     = 124,
        .baseSpAttack  = 95,
        .baseSpDefense = 70,
        .types = { TYPE_BUG, TYPE_FAIRY },
        .catchRate = 75,
        .expYield = 162,
        .evYield_Speed = 2,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HONEY_GATHER, ABILITY_SHIELD_DUST, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Ribombee"),
        .cryId = CRY_RIBOMBEE,
        .natDexNum = NATIONAL_DEX_RIBOMBEE,
        .categoryName = _("Bee Fly"),
        .height = 2,
        .weight = 5,
        .description = COMPOUND_STRING(
            "Ribombee rolls up pollen into puffs.\n"
            "It makes many different varieties, some\n"
            "used as food and others used in battle.\n"
            "They are sometimes sold as supplements."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ribombee, 32, 47),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Ribombee,
        .frontAnimId = ANIM_CONVEX_DOUBLE_ARC_TWICE,
        .enemyMonElevation = 6,
        BACK_PIC(Ribombee, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Ribombee),
        ICON(Ribombee, 2),
        .footprint = gMonFootprint_Ribombee,
        LEARNSETS(Ribombee),
    },
#endif //P_FAMILY_CUTIEFLY

#if P_FAMILY_ROCKRUFF
#define ROCKRUFF_MISC_INFO                                      \
        .baseHP        = 45,                                    \
        .baseAttack    = 65,                                    \
        .baseDefense   = 40,                                    \
        .baseSpeed     = 60,                                    \
        .baseSpAttack  = 30,                                    \
        .baseSpDefense = 40,                                    \
        .types = { TYPE_ROCK, TYPE_ROCK },                      \
        .catchRate = 190,                                       \
        .expYield = 56,                                         \
        .evYield_Attack = 1,                                    \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 15,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },      \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .speciesName = _("Rockruff"),                           \
        .cryId = CRY_ROCKRUFF,                                  \
        .natDexNum = NATIONAL_DEX_ROCKRUFF,                     \
        .categoryName = _("Puppy"),                             \
        .height = 5,                                            \
        .weight = 92,                                           \
        .description = gRockruffPokedexText,                    \
        .pokemonScale = 432,                                    \
        .pokemonOffset = 13,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .frontPicYOffset = 11,                                  \
        .frontAnimFrames = sAnims_Rockruff,                     \
        .frontAnimId = ANIM_V_STRETCH,                          \
        .backPicYOffset = 7,                                    \
        PALETTES(Rockruff),                                     \
        ICON(Rockruff, 2),                                      \
        .footprint = gMonFootprint_Rockruff,                    \
        LEARNSETS(Rockruff),                                    \
        .formSpeciesIdTable = sRockruffFormSpeciesIdTable

    [SPECIES_ROCKRUFF] =
    {
        ROCKRUFF_MISC_INFO,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_VITAL_SPIRIT, ABILITY_STEADFAST },
        FRONT_PIC(Rockruff, 37, 39),
        BACK_PIC(Rockruff, 64, 56),
        .backAnimId = BACK_ANIM_V_STRETCH,
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 25, SPECIES_LYCANROC_MIDDAY},
                                {EVO_LEVEL_NIGHT, 25, SPECIES_LYCANROC_MIDNIGHT}),
    },

    [SPECIES_ROCKRUFF_OWN_TEMPO] =
    {
        ROCKRUFF_MISC_INFO,
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_NONE, ABILITY_NONE },
        FRONT_PIC(Rockruff, 40, 48),
        BACK_PIC(Rockruff, 64, 56),
        //.backAnimId = BACK_ANIM_NONE,
        .evolutions = EVOLUTION({EVO_LEVEL_DUSK, 25, SPECIES_LYCANROC_DUSK}),
    },

#define LYCANROC_MISC_INFO                                  \
        .types = { TYPE_ROCK, TYPE_ROCK },                  \
        .catchRate = 90,                                    \
        .expYield = 170,                                    \
        .evYield_Attack = 2,                                \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 15,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .speciesName = _("Lycanroc"),                       \
        .natDexNum = NATIONAL_DEX_LYCANROC,                 \
        .categoryName = _("Wolf"),                          \
        .weight = 250,                                      \
        .pokemonScale = 366,                                \
        .pokemonOffset = 7,                                 \
        .trainerScale = 257,                                \
        .trainerOffset = 0,                                 \
        BACK_PIC(LycanrocMidday, 64, 56),                   \
        .footprint = gMonFootprint_Lycanroc,                \
        .formSpeciesIdTable = sLycanrocFormSpeciesIdTable

    [SPECIES_LYCANROC_MIDDAY] =
    {
        LYCANROC_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 112,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SAND_RUSH, ABILITY_STEADFAST },
        .bodyColor = BODY_COLOR_BROWN,
        .cryId = CRY_LYCANROC_MIDDAY,
        .height = 8,
        .description = COMPOUND_STRING(
            "It has a calm and collected\n"
            "demeanor. It swiftly closes in on its prey,\n"
            "then slices them with the rocks in\n"
            "its mane."),
        FRONT_PIC(LycanrocMidday, 57, 53),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_LycanrocMidday,
        .frontAnimId = ANIM_V_SHAKE,
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(LycanrocMidday),
        ICON(LycanrocMidday, 2),
        LEARNSETS(LycanrocMidday),
    },

    [SPECIES_LYCANROC_MIDNIGHT] =
    {
        LYCANROC_MISC_INFO,
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 75,
        .baseSpeed     = 82,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_VITAL_SPIRIT, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_RED,
        .cryId = CRY_LYCANROC_MIDNIGHT,
        .height = 11,
        .description = COMPOUND_STRING(
            "This Pokémon uses its rocky mane\n"
            "to slash any who approach. It will\n"
            "even disobey its Trainer if it dislikes\n"
            "the orders it was given."),
        FRONT_PIC(LycanrocMidnight, 56, 61),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_LycanrocMidnight,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_SLOW,
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(LycanrocMidnight),
        ICON(LycanrocMidnight, 0),
        LEARNSETS(LycanrocMidnight),
    },

    [SPECIES_LYCANROC_DUSK] =
    {
        LYCANROC_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 117,
        .baseDefense   = 65,
        .baseSpeed     = 110,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .cryId = CRY_LYCANROC_DUSK,
        .height = 8,
        .description = COMPOUND_STRING(
            "These Pokémon have both calm and\n"
            "ferocious qualities. It's said that\n"
            "this form of Lycanroc is the most\n"
            "troublesome to raise."),
        FRONT_PIC(LycanrocDusk, 57, 58),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_LycanrocDusk,
        .frontAnimId = ANIM_V_SHAKE,
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(LycanrocDusk),
        ICON(LycanrocDusk, 0),
        LEARNSETS(LycanrocDusk),
    },
#endif //P_FAMILY_ROCKRUFF

#if P_FAMILY_WISHIWASHI
#define WISHIWASHI_MISC_INFO                                    \
        .types = { TYPE_WATER, TYPE_WATER },                    \
        .catchRate = 60,                                        \
        .expYield = 61,                                         \
        .evYield_HP = 1,                                        \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 15,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_FAST,                              \
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },  \
        .abilities = { ABILITY_SCHOOLING, ABILITY_NONE },       \
        .bodyColor = BODY_COLOR_BLUE,                           \
        .speciesName = _("Wishiwashi"),                         \
        .natDexNum = NATIONAL_DEX_WISHIWASHI,                   \
        .categoryName = _("Small Fry"),                         \
        .pokemonScale = 682,                                    \
        .pokemonOffset = 24,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Wishiwashi,                  \
        LEARNSETS(Wishiwashi),                                  \
        .formSpeciesIdTable = sWishiwashiFormSpeciesIdTable,    \
        .formChangeTable = sWishiwashiFormChangeTable

    [SPECIES_WISHIWASHI_SOLO] =
    {
        WISHIWASHI_MISC_INFO,
        .baseHP        = 45,
        .baseAttack    = 20,
        .baseDefense   = 20,
        .baseSpeed     = 40,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .cryId = CRY_WISHIWASHI_SOLO,
        .height = 2,
        .weight = 3,
        .description = COMPOUND_STRING(
            "Individually, they're incredibly\n"
            "weak. It's by gathering up into\n"
            "schools that they're able to confront\n"
            "opponents."),
        FRONT_PIC(WishiwashiSolo, 40, 24),
        .frontPicYOffset = 20,
        .frontAnimFrames = sAnims_WishiwashiSolo,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 12,
        BACK_PIC(WishiwashiSolo, 56, 32),
        .backPicYOffset = 18,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(WishiwashiSolo),
        ICON(WishiwashiSolo, 2),
    },

    [SPECIES_WISHIWASHI_SCHOOL] =
    {
        WISHIWASHI_MISC_INFO,
        .baseHP        = 45,
        .baseAttack    = 140,
        .baseDefense   = 130,
        .baseSpeed     = 30,
        .baseSpAttack  = 140,
        .baseSpDefense = 135,
        .cryId = CRY_WISHIWASHI_SCHOOL,
        .height = 82,
        .weight = 786,
        .description = COMPOUND_STRING(
            "When facing tough opponents, they\n"
            "get into formation. But if they get\n"
            "wounded in battle, they'll scatter\n"
            "and become solitary again."),
        FRONT_PIC(WishiwashiSchool, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_WishiwashiSchool,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE, //Todo
        BACK_PIC(WishiwashiSchool, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(WishiwashiSchool),
        ICON(WishiwashiSchool, 0),
    },
#endif //P_FAMILY_WISHIWASHI

#if P_FAMILY_MAREANIE
    [SPECIES_MAREANIE] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 62,
        .baseSpeed     = 45,
        .baseSpAttack  = 43,
        .baseSpDefense = 52,
        .types = { TYPE_POISON, TYPE_WATER },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_MERCILESS, ABILITY_LIMBER, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Mareanie"),
        .cryId = CRY_MAREANIE,
        .natDexNum = NATIONAL_DEX_MAREANIE,
        .categoryName = _("Brutal Star"),
        .height = 4,
        .weight = 80,
        .description = COMPOUND_STRING(
            "It's found crawling on beaches and\n"
            "seafloors. The coral that grows on\n"
            "Corsola's head is as good as a five-star\n"
            "banquet to this Pokémon."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mareanie, 48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Mareanie,
        .frontAnimId = ANIM_GLOW_PURPLE,
        BACK_PIC(Mareanie, 64, 48),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Mareanie),
        ICON(Mareanie, 2),
        .footprint = gMonFootprint_Mareanie,
        LEARNSETS(Mareanie),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_TOXAPEX}),
    },

    [SPECIES_TOXAPEX] =
    {
        .baseHP        = 50,
        .baseAttack    = 63,
        .baseDefense   = 152,
        .baseSpeed     = 35,
        .baseSpAttack  = 53,
        .baseSpDefense = 142,
        .types = { TYPE_POISON, TYPE_WATER },
        .catchRate = 75,
        .expYield = 173,
        .evYield_Defense = 2,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_MERCILESS, ABILITY_LIMBER, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Toxapex"),
        .cryId = CRY_TOXAPEX,
        .natDexNum = NATIONAL_DEX_TOXAPEX,
        .categoryName = _("Brutal Star"),
        .height = 7,
        .weight = 145,
        .description = COMPOUND_STRING(
            "Those attacked by Toxapex's poison will\n"
            "suffer intense pain for three days and\n"
            "three nights. Post-recovery, there will be\n"
            "some aftereffects."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Toxapex, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Toxapex,
        .frontAnimId = ANIM_SHAKE_GLOW_PURPLE_SLOW,
        BACK_PIC(Toxapex, 64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Toxapex),
        ICON(Toxapex, 0),
        .footprint = gMonFootprint_Toxapex,
        LEARNSETS(Toxapex),
    },
#endif //P_FAMILY_MAREANIE

#if P_FAMILY_MUDBRAY
    [SPECIES_MUDBRAY] =
    {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 190,
        .expYield = 77,
        .evYield_Attack = 1,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_STAMINA, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mudbray"),
        .cryId = CRY_MUDBRAY,
        .natDexNum = NATIONAL_DEX_MUDBRAY,
        .categoryName = _("Donkey"),
        .height = 10,
        .weight = 1100,
        .description = COMPOUND_STRING(
            "The mud stuck to Mudbray's hooves\n"
            "enhances its grip and its powerful running\n"
            "gait. Eating dirt, making mud, and playing\n"
            "in the mire form its daily routine."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Mudbray, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Mudbray,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Mudbray, 64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Mudbray),
        ICON(Mudbray, 2),
        .footprint = gMonFootprint_Mudbray,
        LEARNSETS(Mudbray),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_MUDSDALE}),
    },

    [SPECIES_MUDSDALE] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 35,
        .baseSpAttack  = 55,
        .baseSpDefense = 85,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 60,
        .expYield = 175,
        .evYield_Attack = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_STAMINA, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mudsdale"),
        .cryId = CRY_MUDSDALE,
        .natDexNum = NATIONAL_DEX_MUDSDALE,
        .categoryName = _("Draft Horse"),
        .height = 25,
        .weight = 9200,
        .description = COMPOUND_STRING(
            "Its heavy, mud-covered kicks are its\n"
            "best means of attack, and it can reduce\n"
            "large trucks to scrap without breaking\n"
            "a sweat."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Mudsdale, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Mudsdale,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Mudsdale, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Mudsdale),
        ICON(Mudsdale, 0),
        .footprint = gMonFootprint_Mudsdale,
        LEARNSETS(Mudsdale),
    },
#endif //P_FAMILY_MUDBRAY

#if P_FAMILY_DEWPIDER
    [SPECIES_DEWPIDER] =
    {
        .baseHP        = 38,
        .baseAttack    = 40,
        .baseDefense   = 52,
        .baseSpeed     = 27,
        .baseSpAttack  = 40,
        .baseSpDefense = 72,
        .types = { TYPE_WATER, TYPE_BUG },
        .catchRate = 200,
        .expYield = 54,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_BUG },
        .abilities = { ABILITY_WATER_BUBBLE, ABILITY_NONE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Dewpider"),
        .cryId = CRY_DEWPIDER,
        .natDexNum = NATIONAL_DEX_DEWPIDER,
        .categoryName = _("Water Bubble"),
        .height = 3,
        .weight = 40,
        .description = COMPOUND_STRING(
            "It crawls onto the land in search of food.\n"
            "When it comes across enemies or potential\n"
            "prey, this Pokémon smashes its\n"
            "water-bubble-covered head into them."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dewpider, 32, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Dewpider,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Dewpider, 40, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dewpider),
        ICON(Dewpider, 0),
        .footprint = gMonFootprint_Dewpider,
        LEARNSETS(Dewpider),
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_ARAQUANID}),
    },

    [SPECIES_ARAQUANID] =
    {
        .baseHP        = 68,
        .baseAttack    = 70,
        .baseDefense   = 92,
        .baseSpeed     = 42,
        .baseSpAttack  = 50,
        .baseSpDefense = 132,
        .types = { TYPE_WATER, TYPE_BUG },
        .catchRate = 100,
        .expYield = 159,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_BUG },
        .abilities = { ABILITY_WATER_BUBBLE, ABILITY_NONE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Araquanid"),
        .cryId = CRY_ARAQUANID,
        .natDexNum = NATIONAL_DEX_ARAQUANID,
        .categoryName = _("Water Bubble"),
        .height = 18,
        .weight = 820,
        .description = COMPOUND_STRING(
            "Despite what its appearance suggests,\n"
            "it cares for others. If it finds vulnerable,\n"
            "weak Pokémon, it protectively brings\n"
            "them into its water bubble."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Araquanid, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Araquanid,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Araquanid, 64, 48),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Araquanid),
        ICON(Araquanid, 2),
        .footprint = gMonFootprint_Araquanid,
        LEARNSETS(Araquanid),
    },
#endif //P_FAMILY_DEWPIDER

#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 35,
        .baseSpeed     = 35,
        .baseSpAttack  = 50,
        .baseSpDefense = 35,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 50,
        .evYield_Attack = 1,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Fomantis"),
        .cryId = CRY_FOMANTIS,
        .natDexNum = NATIONAL_DEX_FOMANTIS,
        .categoryName = _("Sickle Grass"),
        .height = 3,
        .weight = 15,
        .description = COMPOUND_STRING(
            "During the day, it sleeps and soaks up\n"
            "light. They give off a sweet and refreshing\n"
            "scent. Cutiefly often gather near the tall\n"
            "grass where Fomantis are hiding."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fomantis, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Fomantis,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Fomantis, 40, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Fomantis),
        ICON(Fomantis, 1),
        .footprint = gMonFootprint_Fomantis,
        LEARNSETS(Fomantis),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 34, SPECIES_LURANTIS}),
    },

    [SPECIES_LURANTIS] =
    {
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 90,
        .baseSpeed     = 45,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 75,
        .expYield = 168,
        .evYield_Attack = 2,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Lurantis"),
        .cryId = CRY_LURANTIS,
        .natDexNum = NATIONAL_DEX_LURANTIS,
        .categoryName = _("Bloom Sickle"),
        .height = 9,
        .weight = 185,
        .description = COMPOUND_STRING(
            "It requires a lot of effort to maintain\n"
            "Lurantis's vivid coloring, but some\n"
            "collectors enjoy this work and treat it\n"
            "as their hobby."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lurantis, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Lurantis,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Lurantis, 56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Lurantis),
        ICON(Lurantis, 1),
        .footprint = gMonFootprint_Lurantis,
        LEARNSETS(Lurantis),
    },
#endif //P_FAMILY_FOMANTIS

#if P_FAMILY_MORELULL
    [SPECIES_MORELULL] =
    {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 55,
        .baseSpeed     = 15,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FAIRY },
        .catchRate = 190,
        .expYield = 57,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_ILLUMINATE, ABILITY_EFFECT_SPORE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Morelull"),
        .cryId = CRY_MORELULL,
        .natDexNum = NATIONAL_DEX_MORELULL,
        .categoryName = _("Illuminate"),
        .height = 2,
        .weight = 15,
        .description = COMPOUND_STRING(
            "As it drowses the day away, it nourishes\n"
            "itself by sucking from tree roots.\n"
            "It wakens at the fall of night, wandering\n"
            "off in search of a new tree."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Morelull, 24, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Morelull,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW,
        BACK_PIC(Morelull, 40, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Morelull),
        ICON(Morelull, 0),
        .footprint = gMonFootprint_Morelull,
        LEARNSETS(Morelull),
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_SHIINOTIC}),
    },

    [SPECIES_SHIINOTIC] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_FAIRY },
        .catchRate = 75,
        .expYield = 142,
        .evYield_SpDefense = 2,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_ILLUMINATE, ABILITY_EFFECT_SPORE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Shiinotic"),
        .cryId = CRY_SHIINOTIC,
        .natDexNum = NATIONAL_DEX_SHIINOTIC,
        .categoryName = _("Illuminate"),
        .height = 10,
        .weight = 115,
        .description = COMPOUND_STRING(
            "Forests where Shiinotic live are\n"
            "treacherous to enter at night.\n"
            "People confused by its strange lights\n"
            "can never find their way home again."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Shiinotic, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Shiinotic,
        .frontAnimId = ANIM_SHAKE_GLOW_WHITE_SLOW,
        BACK_PIC(Shiinotic, 64, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Shiinotic),
        ICON(Shiinotic, 1),
        .footprint = gMonFootprint_Shiinotic,
        LEARNSETS(Shiinotic),
    },
#endif //P_FAMILY_MORELULL

#if P_FAMILY_SALANDIT
    [SPECIES_SALANDIT] =
    {
        .baseHP        = 48,
        .baseAttack    = 44,
        .baseDefense   = 40,
        .baseSpeed     = 77,
        .baseSpAttack  = 71,
        .baseSpDefense = 40,
        .types = { TYPE_POISON, TYPE_FIRE },
        .catchRate = 120,
        .expYield = 64,
        .evYield_Speed = 1,
        .itemRare = ITEM_SMOKE_BALL,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CORROSION, ABILITY_NONE, ABILITY_OBLIVIOUS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Salandit"),
        .cryId = CRY_SALANDIT,
        .natDexNum = NATIONAL_DEX_SALANDIT,
        .categoryName = _("Toxic Lizard"),
        .height = 6,
        .weight = 48,
        .description = COMPOUND_STRING(
            "It burns its bodily fluids to create a\n"
            "sweet-smelling poisonous gas. When its\n"
            "enemies become disoriented from inhaling\n"
            "the gas, it attacks them."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Salandit, 56, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Salandit,
        .frontAnimId = ANIM_GLOW_RED,
        BACK_PIC(Salandit, 56, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Salandit),
        ICON(Salandit, 2),
        .footprint = gMonFootprint_Salandit,
        LEARNSETS(Salandit),
        .evolutions = EVOLUTION({EVO_LEVEL_FEMALE, 33, SPECIES_SALAZZLE}),
    },

    [SPECIES_SALAZZLE] =
    {
        .baseHP        = 68,
        .baseAttack    = 64,
        .baseDefense   = 60,
        .baseSpeed     = 117,
        .baseSpAttack  = 111,
        .baseSpDefense = 60,
        .types = { TYPE_POISON, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 168,
        .evYield_Speed = 2,
        .itemRare = ITEM_SMOKE_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CORROSION, ABILITY_NONE, ABILITY_OBLIVIOUS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Salazzle"),
        .cryId = CRY_SALAZZLE,
        .natDexNum = NATIONAL_DEX_SALAZZLE,
        .categoryName = _("Toxic Lizard"),
        .height = 12,
        .weight = 222,
        .description = COMPOUND_STRING(
            "For some reason, only females have\n"
            "been found. It creates a reverse harem of\n"
            "male Salandit to live with. Its poisonous\n"
            "gas is filled with pheromones."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Salazzle, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Salazzle,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Salazzle, 48, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Salazzle),
        ICON(Salazzle, 0),
        .footprint = gMonFootprint_Salazzle,
        LEARNSETS(Salazzle),
    },
#endif //P_FAMILY_SALANDIT

#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] =
    {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = { TYPE_NORMAL, TYPE_FIGHTING },
        .catchRate = 140,
        .expYield = 68,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FLUFFY, ABILITY_KLUTZ, ABILITY_CUTE_CHARM },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Stufful"),
        .cryId = CRY_STUFFUL,
        .natDexNum = NATIONAL_DEX_STUFFUL,
        .categoryName = _("Flailing"),
        .height = 5,
        .weight = 68,
        .description = COMPOUND_STRING(
            "Despite its adorable appearance, when it\n"
            "gets angry and flails about, its arms and\n"
            "legs could knock a pro wrestler sprawling.\n"
            "It's an incredibly dangerous Pokémon."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Stufful, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Stufful,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Stufful, 56, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Stufful),
        ICON(Stufful, 0),
        .footprint = gMonFootprint_Stufful,
        LEARNSETS(Stufful),
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_BEWEAR}),
    },

    [SPECIES_BEWEAR] =
    {
        .baseHP        = 120,
        .baseAttack    = 125,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_FIGHTING },
        .catchRate = 70,
        .expYield = 175,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FLUFFY, ABILITY_KLUTZ, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Bewear"),
        .cryId = CRY_BEWEAR,
        .natDexNum = NATIONAL_DEX_BEWEAR,
        .categoryName = _("Strong Arm"),
        .height = 21,
        .weight = 1350,
        .description = COMPOUND_STRING(
            "This Pokémon has the habit of hugging its\n"
            "companions. Many Trainers have left this\n"
            "world after their spines were squashed\n"
            "by its hug."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Bewear, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Bewear,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Bewear, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Bewear),
        ICON(Bewear, 0),
        .footprint = gMonFootprint_Bewear,
        LEARNSETS(Bewear),
    },
#endif //P_FAMILY_STUFFUL

#if P_FAMILY_BOUNSWEET
    [SPECIES_BOUNSWEET] =
    {
        .baseHP        = 42,
        .baseAttack    = 30,
        .baseDefense   = 38,
        .baseSpeed     = 32,
        .baseSpAttack  = 30,
        .baseSpDefense = 38,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 235,
        .expYield = 42,
        .evYield_HP = 1,
        .itemRare = ITEM_GRASSY_SEED,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_OBLIVIOUS, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Bounsweet"),
        .cryId = CRY_BOUNSWEET,
        .natDexNum = NATIONAL_DEX_BOUNSWEET,
        .categoryName = _("Fruit"),
        .height = 3,
        .weight = 32,
        .description = COMPOUND_STRING(
            "A delectable aroma pours from its body. \n"
            "Bounsweet's sweat can be watered down\n"
            "into a juice with just the right amount\n"
            "of sweetness."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bounsweet, 32, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Bounsweet,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Bounsweet, 48, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Bounsweet),
        ICON(Bounsweet, 1),
        .footprint = gMonFootprint_Bounsweet,
        LEARNSETS(Bounsweet),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_STEENEE}),
    },

    [SPECIES_STEENEE] =
    {
        .baseHP        = 52,
        .baseAttack    = 40,
        .baseDefense   = 48,
        .baseSpeed     = 62,
        .baseSpAttack  = 40,
        .baseSpDefense = 48,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 120,
        .expYield = 102,
        .evYield_Speed = 2,
        .itemRare = ITEM_GRASSY_SEED,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_OBLIVIOUS, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
        .speciesName = _("Steenee"),
        .cryId = CRY_STEENEE,
        .natDexNum = NATIONAL_DEX_STEENEE,
        .categoryName = _("Fruit"),
        .height = 7,
        .weight = 82,
        .description = COMPOUND_STRING(
            "The sepals on its head developed to\n"
            "protect its body. These are quite hard, so\n"
            "even if pecked by bird Pokémon, this\n"
            "Pokémon is totally fine."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Steenee, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Steenee,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Steenee, 56, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Steenee),
        ICON(Steenee, 1),
        .footprint = gMonFootprint_Steenee,
        LEARNSETS(Steenee),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_STOMP, SPECIES_TSAREENA}),
    },

    [SPECIES_TSAREENA] =
    {
        .baseHP        = 72,
        .baseAttack    = 120,
        .baseDefense   = 98,
        .baseSpeed     = 72,
        .baseSpAttack  = 50,
        .baseSpDefense = 98,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 230,
        .evYield_Attack = 3,
        .itemCommon = ITEM_GRASSY_SEED,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_QUEENLY_MAJESTY, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
        .speciesName = _("Tsareena"),
        .cryId = CRY_TSAREENA,
        .natDexNum = NATIONAL_DEX_TSAREENA,
        .categoryName = _("Fruit"),
        .height = 12,
        .weight = 214,
        .description = COMPOUND_STRING(
            "Its long, striking legs aren't just for\n"
            "show but to be used to kick with skill.\n"
            "In victory, it shows off by kicking the\n"
            "defeated, laughing boisterously."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tsareena, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Tsareena,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Tsareena, 56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Tsareena),
        ICON(Tsareena, 1),
        .footprint = gMonFootprint_Tsareena,
        LEARNSETS(Tsareena),
    },
#endif //P_FAMILY_BOUNSWEET

#if P_FAMILY_COMFEY
    [SPECIES_COMFEY] =
    {
        .baseHP        = 51,
        .baseAttack    = 52,
        .baseDefense   = 90,
        .baseSpeed     = 100,
        .baseSpAttack  = 82,
        .baseSpDefense = 110,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 60,
        .expYield = 170,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_MISTY_SEED,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_TRIAGE, ABILITY_NATURAL_CURE },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Comfey"),
        .cryId = CRY_COMFEY,
        .natDexNum = NATIONAL_DEX_COMFEY,
        .categoryName = _("Posy Picker"),
        .height = 1,
        .weight = 3,
        .description = COMPOUND_STRING(
            "It attaches flowers to its nutritious\n"
            "vine. Baths prepared with the flowers\n"
            "from its vine have a relaxing effect, so\n"
            "this Pokémon is a hit with many people."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Comfey, 48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Comfey,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        BACK_PIC(Comfey, 64, 56),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Comfey),
        ICON(Comfey, 1),
        .footprint = gMonFootprint_Comfey,
        LEARNSETS(Comfey),
    },
#endif //P_FAMILY_COMFEY

#if P_FAMILY_ORANGURU
    [SPECIES_ORANGURU] =
    {
        .baseHP        = 90,
        .baseAttack    = 60,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 90,
        .baseSpDefense = 110,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 172,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_TELEPATHY, ABILITY_SYMBIOSIS },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Oranguru"),
        .cryId = CRY_ORANGURU,
        .natDexNum = NATIONAL_DEX_ORANGURU,
        .categoryName = _("Sage"),
        .height = 15,
        .weight = 760,
        .description = COMPOUND_STRING(
            "Deep in the jungle, high in the lofty\n"
            "canopy, this Pokémon abides. On rare\n"
            "occasions, it shows up at the beach to\n"
            "match wits with Slowking."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Oranguru, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Oranguru,
        .frontAnimId = ANIM_SHRINK_GROW_SLOW,
        BACK_PIC(Oranguru, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Oranguru),
        ICON(Oranguru, 0),
        .footprint = gMonFootprint_Oranguru,
        LEARNSETS(Oranguru),
    },
#endif //P_FAMILY_ORANGURU

#if P_FAMILY_PASSIMIAN
    [SPECIES_PASSIMIAN] =
    {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RECEIVER, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Passimian"),
        .cryId = CRY_PASSIMIAN,
        .natDexNum = NATIONAL_DEX_PASSIMIAN,
        .categoryName = _("Teamwork"),
        .height = 20,
        .weight = 828,
        .description = COMPOUND_STRING(
            "They battle with hard berries for weapons.\n"
            "They form groups of about 20 individuals.\n"
            "Their techniques are passed from the boss\n"
            "to the group, generation upon generation."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Passimian, 57, 60),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Passimian,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Passimian, 51, 52),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Passimian),
        ICON(Passimian, 1),
        .footprint = gMonFootprint_Passimian,
        LEARNSETS(Passimian),
    },
#endif //P_FAMILY_PASSIMIAN

#if P_FAMILY_WIMPOD
    [SPECIES_WIMPOD] =
    {
        .baseHP        = 25,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 80,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_WATER },
        .catchRate = 90,
        .expYield = 46,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_WIMP_OUT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Wimpod"),
        .cryId = CRY_WIMPOD,
        .natDexNum = NATIONAL_DEX_WIMPOD,
        .categoryName = _("Turn Tail"),
        .height = 5,
        .weight = 120,
        .description = COMPOUND_STRING(
            "This Pokémon is a coward. As it desperately\n"
            "dashes off, the flailing of its many legs\n"
            "leaves a sparkling clean path in its wake.\n"
            "It lives on beaches and seabeds."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Wimpod, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Wimpod,
        .frontAnimId = ANIM_V_SHAKE_H_SLIDE_FAST,
        BACK_PIC(Wimpod, 64, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Wimpod),
        ICON(Wimpod, 2),
        .footprint = gMonFootprint_Wimpod,
        LEARNSETS(Wimpod),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_GOLISOPOD}),
    },

    [SPECIES_GOLISOPOD] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 140,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 90,
        .types = { TYPE_BUG, TYPE_WATER },
        .catchRate = 45,
        .expYield = 186,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_EMERGENCY_EXIT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Golisopod"),
        .cryId = CRY_GOLISOPOD,
        .natDexNum = NATIONAL_DEX_GOLISOPOD,
        .categoryName = _("Hard Scale"),
        .height = 20,
        .weight = 1080,
        .description = COMPOUND_STRING(
            "It battles skillfully with its six arms,\n"
            "with a flashing slash of its giant sharp\n"
            "claws, it cleaves seawater--or even\n"
            "air--right in two."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Golisopod, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Golisopod,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Golisopod, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Golisopod),
        ICON(Golisopod, 2),
        .footprint = gMonFootprint_Golisopod,
        LEARNSETS(Golisopod),
    },
#endif //P_FAMILY_WIMPOD

#if P_FAMILY_SANDYGAST
    [SPECIES_SANDYGAST] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 80,
        .baseSpeed     = 15,
        .baseSpAttack  = 70,
        .baseSpDefense = 45,
        .types = { TYPE_GHOST, TYPE_GROUND },
        .catchRate = 140,
        .expYield = 64,
        .evYield_Defense = 1,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_COMPACTION, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Sandygast"),
        .cryId = CRY_SANDYGAST,
        .natDexNum = NATIONAL_DEX_SANDYGAST,
        .categoryName = _("Sand Heap"),
        .height = 5,
        .weight = 700,
        .description = COMPOUND_STRING(
            "It takes control of anyone who puts a hand\n"
            "in its mouth, to add to the accumulation\n"
            "of its sand-mound body. This Pokémon\n"
            "embodies the grudges of the departed."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sandygast, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Sandygast,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Sandygast, 40, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Sandygast),
        ICON(Sandygast, 1),
        .footprint = gMonFootprint_Sandygast,
        LEARNSETS(Sandygast),
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_PALOSSAND}),
    },

    [SPECIES_PALOSSAND] =
    {
        .baseHP        = 85,
        .baseAttack    = 75,
        .baseDefense   = 110,
        .baseSpeed     = 35,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .types = { TYPE_GHOST, TYPE_GROUND },
        .catchRate = 60,
        .expYield = 168,
        .evYield_Defense = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_COMPACTION, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Palossand"),
        .cryId = CRY_PALOSSAND,
        .natDexNum = NATIONAL_DEX_PALOSSAND,
        .categoryName = _("Sand Castle"),
        .height = 13,
        .weight = 2500,
        .description = COMPOUND_STRING(
            "Possessed people controlled by this\n"
            "Pokémon transformed its sand mound into\n"
            "a castle. As it evolved, its power to curse\n"
            "grew ever stronger."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Palossand, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Palossand,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Palossand, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Palossand),
        ICON(Palossand, 2),
        .footprint = gMonFootprint_Palossand,
        LEARNSETS(Palossand),
    },
#endif //P_FAMILY_SANDYGAST

#if P_FAMILY_PYUKUMUKU
    [SPECIES_PYUKUMUKU] =
    {
        .baseHP        = 55,
        .baseAttack    = 60,
        .baseDefense   = 130,
        .baseSpeed     = 5,
        .baseSpAttack  = 30,
        .baseSpDefense = 130,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 60,
        .expYield = 144,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_INNARDS_OUT, ABILITY_NONE, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Pyukumuku"),
        .cryId = CRY_PYUKUMUKU,
        .natDexNum = NATIONAL_DEX_PYUKUMUKU,
        .categoryName = _("Sea Cucumber"),
        .height = 3,
        .weight = 12,
        .description = COMPOUND_STRING(
            "It lives in shallow seas, such as areas\n"
            "near a beach. The sticky mucous that\n"
            "covers their bodies can be used to soothe\n"
            "sunburned skin. How convenient!"),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pyukumuku, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Pyukumuku,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Pyukumuku, 48, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Pyukumuku),
        ICON(Pyukumuku, 0),
        .footprint = gMonFootprint_Pyukumuku,
        LEARNSETS(Pyukumuku),
    },
#endif //P_FAMILY_PYUKUMUKU

#if P_FAMILY_TYPE_NULL
    [SPECIES_TYPE_NULL] =
    {
        .baseHP        = 95,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 59,
        .baseSpAttack  = 95,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 3,
        .expYield = 107,
        .evYield_HP = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .isLegendary = TRUE,
        .speciesName = _("Type: Null"),
        .cryId = CRY_TYPE_NULL,
        .natDexNum = NATIONAL_DEX_TYPE_NULL,
        .categoryName = _("Synthetic"),
        .height = 19,
        .weight = 1205,
        .description = COMPOUND_STRING(
            "Due to the danger that this synthetic\n"
            "Pokémon may go on a rampage, it wears a\n"
            "control mask to restrain its capabilities.\n"
            "It has some hidden special power."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(TypeNull, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_TypeNull,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(TypeNull, 56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TypeNull),
        ICON(TypeNull, 0),
        .footprint = gMonFootprint_Type_Null,
        LEARNSETS(TypeNull),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_SILVALLY_NORMAL}),
    },

#define SILVALLY_SPECIES_INFO(type, palette)                                            \
    {                                                                                   \
        .baseHP        = 95,                                                            \
        .baseAttack    = 95,                                                            \
        .baseDefense   = 95,                                                            \
        .baseSpeed     = 95,                                                            \
        .baseSpAttack  = 95,                                                            \
        .baseSpDefense = 95,                                                            \
        .types = { type, type },                                                        \
        .catchRate = 3,                                                                 \
        .expYield = 257,                                                                \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_RKS_SYSTEM, ABILITY_NONE },                              \
        .bodyColor = BODY_COLOR_GRAY,                                                   \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Silvally"),                                                   \
        .cryId = CRY_SILVALLY,                                                          \
        .natDexNum = NATIONAL_DEX_SILVALLY,                                             \
        .categoryName = _("Synthetic"),                                                 \
        .height = 23,                                                                   \
        .weight = 1005,                                                                 \
        .description = (type == TYPE_NORMAL                                             \
            ? gSilvallyNormalPokedexText                                                \
            : gSilvallyMemoryPokedexText),                                              \
        .pokemonScale = 256,                                                            \
        .pokemonOffset = 0,                                                             \
        .trainerScale = 342,                                                            \
        .trainerOffset = 7,                                                             \
        FRONT_PIC(Silvally, 64, 64),                                                    \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Silvally,                                             \
        .frontAnimId = ANIM_V_SHAKE,                                                    \
        BACK_PIC(Silvally, 56, 64),                                                     \
        .backPicYOffset = 0,                                                            \
        PALETTES(palette),                                                              \
        ICON(Silvally, 0),                                                              \
        .footprint = gMonFootprint_Silvally,                                            \
        LEARNSETS(Silvally),                                                            \
        .formSpeciesIdTable = sSilvallyFormSpeciesIdTable,                              \
        .formChangeTable = sSilvallyFormChangeTable,                                    \
   }
        //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_SILVALLY_NORMAL]   = SILVALLY_SPECIES_INFO(TYPE_NORMAL, SilvallyNormal),
    [SPECIES_SILVALLY_FIGHTING] = SILVALLY_SPECIES_INFO(TYPE_FIGHTING, SilvallyFighting),
    [SPECIES_SILVALLY_FLYING]   = SILVALLY_SPECIES_INFO(TYPE_FLYING, SilvallyFlying),
    [SPECIES_SILVALLY_POISON]   = SILVALLY_SPECIES_INFO(TYPE_POISON, SilvallyPoison),
    [SPECIES_SILVALLY_GROUND]   = SILVALLY_SPECIES_INFO(TYPE_GROUND, SilvallyGround),
    [SPECIES_SILVALLY_ROCK]     = SILVALLY_SPECIES_INFO(TYPE_ROCK, SilvallyRock),
    [SPECIES_SILVALLY_BUG]      = SILVALLY_SPECIES_INFO(TYPE_BUG, SilvallyBug),
    [SPECIES_SILVALLY_GHOST]    = SILVALLY_SPECIES_INFO(TYPE_GHOST, SilvallyGhost),
    [SPECIES_SILVALLY_STEEL]    = SILVALLY_SPECIES_INFO(TYPE_STEEL, SilvallySteel),
    [SPECIES_SILVALLY_FIRE]     = SILVALLY_SPECIES_INFO(TYPE_FIRE, SilvallyFire),
    [SPECIES_SILVALLY_WATER]    = SILVALLY_SPECIES_INFO(TYPE_WATER, SilvallyWater),
    [SPECIES_SILVALLY_GRASS]    = SILVALLY_SPECIES_INFO(TYPE_GRASS, SilvallyGrass),
    [SPECIES_SILVALLY_ELECTRIC] = SILVALLY_SPECIES_INFO(TYPE_ELECTRIC, SilvallyElectric),
    [SPECIES_SILVALLY_PSYCHIC]  = SILVALLY_SPECIES_INFO(TYPE_PSYCHIC, SilvallyPsychic),
    [SPECIES_SILVALLY_ICE]      = SILVALLY_SPECIES_INFO(TYPE_ICE, SilvallyIce),
    [SPECIES_SILVALLY_DRAGON]   = SILVALLY_SPECIES_INFO(TYPE_DRAGON, SilvallyDragon),
    [SPECIES_SILVALLY_DARK]     = SILVALLY_SPECIES_INFO(TYPE_DARK, SilvallyDark),
    [SPECIES_SILVALLY_FAIRY]    = SILVALLY_SPECIES_INFO(TYPE_FAIRY, SilvallyFairy),
#endif //P_FAMILY_TYPE_NULL

#if P_FAMILY_MINIOR
#define MINIOR_MISC_INFO(color)                                 \
        .types = { TYPE_ROCK, TYPE_FLYING },                    \
        .catchRate = 30,                                        \
        .expYield = 154,                                        \
        .evYield_Defense = 1,                                   \
        .evYield_SpDefense = 1,                                 \
        .itemRare = ITEM_STAR_PIECE,                            \
        .genderRatio = MON_GENDERLESS,                          \
        .eggCycles = 25,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_SLOW,                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },  \
        .abilities = { ABILITY_SHIELDS_DOWN, ABILITY_NONE },    \
        .bodyColor = color,                                     \
        .noFlip = TRUE,                                         \
        .speciesName = _("Minior"),                             \
        .cryId = CRY_MINIOR,                                    \
        .natDexNum = NATIONAL_DEX_MINIOR,                       \
        .categoryName = _("Meteor"),                            \
        .height = 3,                                            \
        .pokemonScale = 530,                                    \
        .pokemonOffset = 13,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Minior,                      \
        LEARNSETS(Minior),                                      \
        .formSpeciesIdTable = sMiniorFormSpeciesIdTable

#define MINIOR_METEOR_SPECIES_INFO(Form)                        \
    {                                                           \
        .baseHP        = 60,                                    \
        .baseAttack    = 60,                                    \
        .baseDefense   = 100,                                   \
        .baseSpeed     = 60,                                    \
        .baseSpAttack  = 60,                                    \
        .baseSpDefense = 100,                                   \
        .weight = 400,                                          \
        FRONT_PIC(MiniorMeteor, 48, 40),                        \
        .frontPicYOffset = 14,                                  \
        .frontAnimFrames = sAnims_MiniorMeteor,                 \
        .frontAnimId = ANIM_TUMBLING_FRONT_FLIP_TWICE,          \
        .enemyMonElevation = 17,                                \
        BACK_PIC(MiniorMeteor, 56, 40),                         \
        .backPicYOffset = 14,                                   \
        PALETTES(MiniorMeteor),                                 \
        ICON(MiniorMeteor, 0),                                  \
        .formChangeTable = sMinior ##Form##FormChangeTable,     \
        MINIOR_MISC_INFO(BODY_COLOR_BROWN),                     \
    }
    //.backAnimId = BACK_ANIM_NONE,

#define MINIOR_CORE_SPECIES_INFO(Form, color, iconPal)          \
    {                                                           \
        .baseHP        = 60,                                    \
        .baseAttack    = 100,                                   \
        .baseDefense   = 60,                                    \
        .baseSpeed     = 120,                                   \
        .baseSpAttack  = 100,                                   \
        .baseSpDefense = 60,                                    \
        .weight = 3,                                            \
        .description = gMiniorCorePokedexText,                  \
        FRONT_PIC(MiniorCore, 48, 40),                          \
        .frontPicYOffset = 16,                                  \
        .frontAnimFrames = sAnims_MiniorMeteor,                 \
        .frontAnimId = ANIM_TUMBLING_FRONT_FLIP_TWICE,          \
        .enemyMonElevation = 17,                                \
        BACK_PIC(MiniorCore, 56, 40),                           \
        .backPicYOffset = 15,                                   \
        .palette = gMonPalette_MiniorCore##Form,                \
        .shinyPalette = gMonShinyPalette_MiniorCore,            \
        ICON(MiniorCore##Form, iconPal),                        \
        .formChangeTable = sMinior ##Form##FormChangeTable,     \
        MINIOR_MISC_INFO(color),                                \
    }
    //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_MINIOR_METEOR_RED]    = MINIOR_METEOR_SPECIES_INFO(Red),
    [SPECIES_MINIOR_METEOR_ORANGE] = MINIOR_METEOR_SPECIES_INFO(Orange),
    [SPECIES_MINIOR_METEOR_YELLOW] = MINIOR_METEOR_SPECIES_INFO(Yellow),
    [SPECIES_MINIOR_METEOR_GREEN]  = MINIOR_METEOR_SPECIES_INFO(Green),
    [SPECIES_MINIOR_METEOR_BLUE]   = MINIOR_METEOR_SPECIES_INFO(Blue),
    [SPECIES_MINIOR_METEOR_INDIGO] = MINIOR_METEOR_SPECIES_INFO(Indigo),
    [SPECIES_MINIOR_METEOR_VIOLET] = MINIOR_METEOR_SPECIES_INFO(Violet),
    [SPECIES_MINIOR_CORE_RED]      = MINIOR_CORE_SPECIES_INFO(Red,    BODY_COLOR_RED,    0),
    [SPECIES_MINIOR_CORE_ORANGE]   = MINIOR_CORE_SPECIES_INFO(Orange, BODY_COLOR_RED,    0),
    [SPECIES_MINIOR_CORE_YELLOW]   = MINIOR_CORE_SPECIES_INFO(Yellow, BODY_COLOR_YELLOW, 0),
    [SPECIES_MINIOR_CORE_GREEN]    = MINIOR_CORE_SPECIES_INFO(Green,  BODY_COLOR_GREEN,  1),
    [SPECIES_MINIOR_CORE_BLUE]     = MINIOR_CORE_SPECIES_INFO(Blue,   BODY_COLOR_BLUE,   0),
    [SPECIES_MINIOR_CORE_INDIGO]   = MINIOR_CORE_SPECIES_INFO(Indigo, BODY_COLOR_BLUE,   0),
    [SPECIES_MINIOR_CORE_VIOLET]   = MINIOR_CORE_SPECIES_INFO(Violet, BODY_COLOR_PURPLE, 2),
#endif //P_FAMILY_MINIOR

#if P_FAMILY_KOMALA
    [SPECIES_KOMALA] =
    {
        .baseHP        = 65,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 168,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_COMATOSE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Komala"),
        .cryId = CRY_KOMALA,
        .natDexNum = NATIONAL_DEX_KOMALA,
        .categoryName = _("Drowsing"),
        .height = 4,
        .weight = 199,
        .description = COMPOUND_STRING(
            "It is born asleep, and it dies asleep.\n"
            "All its movements are apparently no more\n"
            "than the results of it tossing and turning\n"
            "in its dreams."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Komala, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Komala,
        .frontAnimId = ANIM_H_DIP,
        BACK_PIC(Komala, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Komala),
        ICON(Komala, 2),
        .footprint = gMonFootprint_Komala,
        LEARNSETS(Komala),
    },
#endif //P_FAMILY_KOMALA

#if P_FAMILY_TURTONATOR
    [SPECIES_TURTONATOR] =
    {
        .baseHP        = 60,
        .baseAttack    = 78,
        .baseDefense   = 135,
        .baseSpeed     = 36,
        .baseSpAttack  = 91,
        .baseSpDefense = 85,
        .types = { TYPE_FIRE, TYPE_DRAGON },
        .catchRate = 70,
        .expYield = 170,
        .evYield_Defense = 2,
        .itemRare = ITEM_CHARCOAL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Turtonator"),
        .cryId = CRY_TURTONATOR,
        .natDexNum = NATIONAL_DEX_TURTONATOR,
        .categoryName = _("Blast Turtle"),
        .height = 20,
        .weight = 2120,
        .description = COMPOUND_STRING(
            "The shell on its back is chemically\n"
            "unstable and explodes violently if struck.\n"
            "The hole in its stomach is its weak point.\n"
            "It gushes fire from its nostrils."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Turtonator, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Turtonator,
        .frontAnimId = ANIM_SHAKE_GLOW_RED,
        BACK_PIC(Turtonator, 64, 56),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Turtonator),
        ICON(Turtonator, 0),
        .footprint = gMonFootprint_Turtonator,
        LEARNSETS(Turtonator),
    },
#endif //P_FAMILY_TURTONATOR

#if P_FAMILY_TOGEDEMARU
    [SPECIES_TOGEDEMARU] =
    {
        .baseHP        = 65,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 96,
        .baseSpAttack  = 40,
        .baseSpDefense = 73,
        .types = { TYPE_ELECTRIC, TYPE_STEEL },
        .catchRate = 180,
        .expYield = 152,
        .evYield_Attack = 2,
        .itemRare = ITEM_ELECTRIC_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_IRON_BARBS, ABILITY_LIGHTNING_ROD, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Togedemaru"),
        .cryId = CRY_TOGEDEMARU,
        .natDexNum = NATIONAL_DEX_TOGEDEMARU,
        .categoryName = _("Roly-Poly"),
        .height = 3,
        .weight = 33,
        .description = COMPOUND_STRING(
            "The spiny fur on its back is normally\n"
            "at rest. When this Pokémon becomes\n"
            "agitated, its fur stands on end and stabs\n"
            "into its attackers."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Togedemaru, 40, 40),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Togedemaru,
        .frontAnimId = ANIM_FLASH_YELLOW,
        BACK_PIC(Togedemaru, 64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Togedemaru),
        ICON(Togedemaru, 2),
        .footprint = gMonFootprint_Togedemaru,
        LEARNSETS(Togedemaru),
    },
#endif //P_FAMILY_TOGEDEMARU

#if P_FAMILY_MIMIKYU
#define MIMIKYU_MISC_INFO                                           \
        .baseHP        = 55,                                        \
        .baseAttack    = 90,                                        \
        .baseDefense   = 80,                                        \
        .baseSpeed     = 96,                                        \
        .baseSpAttack  = 50,                                        \
        .baseSpDefense = 105,                                       \
        .types = { TYPE_GHOST, TYPE_FAIRY },                        \
        .catchRate = 45,                                            \
        .expYield = 167,                                            \
        .evYield_SpDefense = 2,                                     \
        .itemRare = ITEM_CHESTO_BERRY,                              \
        .genderRatio = PERCENT_FEMALE(50),                          \
        .eggCycles = 20,                                            \
        .friendship = STANDARD_FRIENDSHIP,                          \
        .growthRate = GROWTH_MEDIUM_FAST,                           \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },  \
        .abilities = { ABILITY_DISGUISE, ABILITY_NONE },            \
        .bodyColor = BODY_COLOR_YELLOW,                             \
        .speciesName = _("Mimikyu"),                                \
        .cryId = CRY_MIMIKYU,                                       \
        .natDexNum = NATIONAL_DEX_MIMIKYU,                          \
        .categoryName = _("Disguise"),                              \
        .height = 2,                                                \
        .weight = 7,                                                \
        .pokemonScale = 682,                                        \
        .pokemonOffset = 24,                                        \
        .trainerScale = 256,                                        \
        .trainerOffset = 0,                                         \
        .footprint = gMonFootprint_Mimikyu,                         \
        LEARNSETS(Mimikyu),                                         \
        .formSpeciesIdTable = sMimikyuFormSpeciesIdTable,           \
        .formChangeTable = sMimikyuFormChangeTable

    [SPECIES_MIMIKYU_DISGUISED] =
    {
        MIMIKYU_MISC_INFO,
        .description = COMPOUND_STRING(
            "A lonely Pokémon, it hides its terrifying\n"
            "appearance beneath an old rag so it can\n"
            "get closer to people and other Pokémon.\n"
            "Its actual appearance is unknown."),
        FRONT_PIC(MimikyuDisguised, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_MimikyuDisguised,
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MimikyuDisguised, 56, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MimikyuDisguised),
        ICON(MimikyuDisguised, 1),
    },

    [SPECIES_MIMIKYU_BUSTED] =
    {
        MIMIKYU_MISC_INFO,
        .description = COMPOUND_STRING(
            "After going to all the effort of\n"
            "disguising itself, its neck was\n"
            "broken. Whatever is inside is probably\n"
            "unharmed, but it's still feeling sad."),
        FRONT_PIC(MimikyuBusted, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_MimikyuBusted,
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MimikyuBusted, 64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MimikyuBusted),
        ICON(MimikyuBusted, 1),
    },
#endif //P_FAMILY_MIMIKYU

#if P_FAMILY_BRUXISH
    [SPECIES_BRUXISH] =
    {
        .baseHP        = 68,
        .baseAttack    = 105,
        .baseDefense   = 70,
        .baseSpeed     = 92,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = { TYPE_WATER, TYPE_PSYCHIC },
        .catchRate = 80,
        .expYield = 166,
        .evYield_Attack = 2,
        .itemRare = ITEM_RAZOR_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_DAZZLING, ABILITY_STRONG_JAW, ABILITY_WONDER_SKIN },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Bruxish"),
        .cryId = CRY_BRUXISH,
        .natDexNum = NATIONAL_DEX_BRUXISH,
        .categoryName = _("Gnash Teeth"),
        .height = 9,
        .weight = 190,
        .description = COMPOUND_STRING(
            "It stuns its prey with its psychic powers\n"
            "and then grinds them to mush with its\n"
            "strong teeth. Even Shellder's shell is no\n"
            "match for it."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bruxish, 56, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Bruxish,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Bruxish, 64, 48),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Bruxish),
        ICON(Bruxish, 0),
        .footprint = gMonFootprint_Bruxish,
        LEARNSETS(Bruxish),
    },
#endif //P_FAMILY_BRUXISH

#if P_FAMILY_DRAMPA
    [SPECIES_DRAMPA] =
    {
        .baseHP        = 78,
        .baseAttack    = 60,
        .baseDefense   = 85,
        .baseSpeed     = 36,
        .baseSpAttack  = 135,
        .baseSpDefense = 91,
        .types = { TYPE_NORMAL, TYPE_DRAGON },
        .catchRate = 70,
        .expYield = 170,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_PERSIM_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BERSERK, ABILITY_SAP_SIPPER, ABILITY_CLOUD_NINE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Drampa"),
        .cryId = CRY_DRAMPA,
        .natDexNum = NATIONAL_DEX_DRAMPA,
        .categoryName = _("Placid"),
        .height = 30,
        .weight = 1850,
        .description = COMPOUND_STRING(
            "This Pokémon is friendly to people and\n"
            "loves children most of all. It comes from\n"
            "deep in the mountains to play with\n"
            "children it likes in town."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drampa, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Drampa,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Drampa, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Drampa),
        ICON(Drampa, 0),
        .footprint = gMonFootprint_Drampa,
        LEARNSETS(Drampa),
    },
#endif //P_FAMILY_DRAMPA

#if P_FAMILY_DHELMISE
    [SPECIES_DHELMISE] =
    {
        .baseHP        = 70,
        .baseAttack    = 131,
        .baseDefense   = 100,
        .baseSpeed     = 40,
        .baseSpAttack  = 86,
        .baseSpDefense = 90,
        .types = { TYPE_GHOST, TYPE_GRASS },
        .catchRate = 25,
        .expYield = 181,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STEELWORKER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Dhelmise"),
        .cryId = CRY_DHELMISE,
        .natDexNum = NATIONAL_DEX_DHELMISE,
        .categoryName = _("Sea Creeper"),
        .height = 39,
        .weight = 2100,
        .description = COMPOUND_STRING(
            "The soul of seaweed adrift in the waves\n"
            "became reborn as this Pokémon.\n"
            "It maintains itself with new infusions of\n"
            "seabed detritus and seaweed."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 510,
        .trainerOffset = 11,
        FRONT_PIC(Dhelmise, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Dhelmise,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 2,
        BACK_PIC(Dhelmise, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dhelmise),
        ICON(Dhelmise, 1),
        .footprint = gMonFootprint_Dhelmise,
        LEARNSETS(Dhelmise),
    },
#endif //P_FAMILY_DHELMISE

#if P_FAMILY_JANGMO_O
    [SPECIES_JANGMO_O] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 65,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 60,
        .evYield_Defense = 1,
        .itemRare = ITEM_RAZOR_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BULLETPROOF, ABILITY_SOUNDPROOF, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Jangmo-o"),
        .cryId = CRY_JANGMO_O,
        .natDexNum = NATIONAL_DEX_JANGMO_O,
        .categoryName = _("Scaly"),
        .height = 6,
        .weight = 297,
        .description = COMPOUND_STRING(
            "It expresses its feelings by smacking its\n"
            "scales. Metallic sounds echo through the\n"
            "tall mountains where Jangmo-o live. They\n"
            "grow little by little battling one another."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(JangmoO, 36, 43),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Jangmo_O,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(JangmoO, 42, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(JangmoO),
        ICON(JangmoO, 2),
        .footprint = gMonFootprint_JangmoO,
        LEARNSETS(JangmoO),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_HAKAMO_O}),
    },

    [SPECIES_HAKAMO_O] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 90,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = { TYPE_DRAGON, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Defense = 2,
        .itemRare = ITEM_RAZOR_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BULLETPROOF, ABILITY_SOUNDPROOF, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Hakamo-o"),
        .cryId = CRY_HAKAMO_O,
        .natDexNum = NATIONAL_DEX_HAKAMO_O,
        .categoryName = _("Scaly"),
        .height = 12,
        .weight = 470,
        .description = COMPOUND_STRING(
            "It sheds and regrows its scales on a\n"
            "continuous basis. The scales become\n"
            "harder each time they're regrown. Its\n"
            "scaly punches tear its foes to shreds."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HakamoO, 53, 61),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Hakamo_O,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(HakamoO, 49, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(HakamoO),
        ICON(HakamoO, 2),
        .footprint = gMonFootprint_HakamoO,
        LEARNSETS(HakamoO),
        .evolutions = EVOLUTION({EVO_LEVEL, 45, SPECIES_KOMMO_O}),
    },

    [SPECIES_KOMMO_O] =
    {
        .baseHP        = 75,
        .baseAttack    = 110,
        .baseDefense   = 125,
        .baseSpeed     = 85,
        .baseSpAttack  = 100,
        .baseSpDefense = 105,
        .types = { TYPE_DRAGON, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 270,
        .evYield_Defense = 3,
        .itemCommon = ITEM_RAZOR_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BULLETPROOF, ABILITY_SOUNDPROOF, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Kommo-o"),
        .cryId = CRY_KOMMO_O,
        .natDexNum = NATIONAL_DEX_KOMMO_O,
        .categoryName = _("Scaly"),
        .height = 16,
        .weight = 782,
        .description = COMPOUND_STRING(
            "Its rigid scales function as offense and\n"
            "defense. In the past, its scales were\n"
            "processed and used to make weapons\n"
            "and other valuable commodities."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(KommoO, 63, 63),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Kommo_O,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(KommoO, 60, 60),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(KommoO),
        ICON(KommoO, 2),
        .footprint = gMonFootprint_KommoO,
        LEARNSETS(KommoO),
    },
#endif //P_FAMILY_JANGMO_O

#if P_FAMILY_TAPU_KOKO
    [SPECIES_TAPU_KOKO] =
    {
        .baseHP        = 70,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 130,
        .baseSpAttack  = 95,
        .baseSpDefense = 75,
        .types = { TYPE_ELECTRIC, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_ELECTRIC_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_YELLOW,
        .isLegendary = TRUE,
        .speciesName = _("Tapu Koko"),
        .cryId = CRY_TAPU_KOKO,
        .natDexNum = NATIONAL_DEX_TAPU_KOKO,
        .categoryName = _("Land Spirit"),
        .height = 18,
        .weight = 205,
        .description = COMPOUND_STRING(
            "It confuses its enemies by flying too\n"
            "quickly for the eye to follow. It has a\n"
            "hair-trigger temper but forgets what\n"
            "made it angry an instant later."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(TapuKoko, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_TapuKoko,
        .frontAnimId = ANIM_TRIANGLE_DOWN_TWICE,
        .enemyMonElevation = 9,
        BACK_PIC(TapuKoko, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuKoko),
        ICON(TapuKoko, 0),
        .footprint = gMonFootprint_Tapu_Koko,
        LEARNSETS(TapuKoko),
    },
#endif //P_FAMILY_TAPU_KOKO

#if P_FAMILY_TAPU_LELE
    [SPECIES_TAPU_LELE] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 95,
        .baseSpAttack  = 130,
        .baseSpDefense = 115,
        .types = { TYPE_PSYCHIC, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_PSYCHIC_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
        .isLegendary = TRUE,
        .speciesName = _("Tapu Lele"),
        .cryId = CRY_TAPU_LELE,
        .natDexNum = NATIONAL_DEX_TAPU_LELE,
        .categoryName = _("Land Spirit"),
        .height = 12,
        .weight = 186,
        .description = COMPOUND_STRING(
            "A fragrant aroma of flowers follows it.\n"
            "As it flutters about, it scatters its\n"
            "strangely glowing scales. Touching them\n"
            "is said to restore good health."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(TapuLele, 48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_TapuLele,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 8,
        BACK_PIC(TapuLele, 56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuLele),
        ICON(TapuLele, 0),
        .footprint = gMonFootprint_Tapu_Lele,
        LEARNSETS(TapuLele),
    },
#endif //P_FAMILY_TAPU_LELE

#if P_FAMILY_TAPU_BULU
    [SPECIES_TAPU_BULU] =
    {
        .baseHP        = 70,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 85,
        .baseSpDefense = 95,
        .types = { TYPE_GRASS, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_GRASSY_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_RED,
        .isLegendary = TRUE,
        .speciesName = _("Tapu Bulu"),
        .cryId = CRY_TAPU_BULU,
        .natDexNum = NATIONAL_DEX_TAPU_BULU,
        .categoryName = _("Land Spirit"),
        .height = 19,
        .weight = 455,
        .description = COMPOUND_STRING(
            "It causes vegetation to grow, and then\n"
            "it absorbs energy from the growth.\n"
            "It pulls large trees up by the roots and\n"
            "swings them around at its enemies."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(TapuBulu, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TapuBulu,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .enemyMonElevation = 5,
        BACK_PIC(TapuBulu, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuBulu),
        ICON(TapuBulu, 2),
        .footprint = gMonFootprint_Tapu_Bulu,
        LEARNSETS(TapuBulu),
    },
#endif //P_FAMILY_TAPU_BULU

#if P_FAMILY_TAPU_FINI
    [SPECIES_TAPU_FINI] =
    {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 130,
        .types = { TYPE_WATER, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_MISTY_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PURPLE,
        .isLegendary = TRUE,
        .speciesName = _("Tapu Fini"),
        .cryId = CRY_TAPU_FINI,
        .natDexNum = NATIONAL_DEX_TAPU_FINI,
        .categoryName = _("Land Spirit"),
        .height = 13,
        .weight = 212,
        .description = COMPOUND_STRING(
            "People say it can create pure water that\n"
            "will wash away any corruption. The dense\n"
            "fog it creates brings the downfall and\n"
            "destruction of its confused enemies."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(TapuFini, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_TapuFini,
        .frontAnimId = ANIM_SHAKE_GLOW_BLUE_SLOW,
        .frontAnimDelay = 5,
        .enemyMonElevation = 6,
        BACK_PIC(TapuFini, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuFini),
        ICON(TapuFini, 0),
        .footprint = gMonFootprint_Tapu_Fini,
        LEARNSETS(TapuFini),
    },
#endif //P_FAMILY_TAPU_FINI

#if P_FAMILY_COSMOG
    [SPECIES_COSMOG] =
    {
        .baseHP        = 43,
        .baseAttack    = 29,
        .baseDefense   = 31,
        .baseSpeed     = 37,
        .baseSpAttack  = 29,
        .baseSpDefense = 31,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 40,
        .evYield_HP = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_UNAWARE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Cosmog"),
        .cryId = CRY_COSMOG,
        .natDexNum = NATIONAL_DEX_COSMOG,
        .categoryName = _("Nebula"),
        .height = 2,
        .weight = 1,
        .description = COMPOUND_STRING(
            "In ages past, it was called the child of\n"
            "the stars. It's said to be a Pokémon from\n"
            "another world, but no specific details\n"
            "are known."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cosmog, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Cosmog,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .enemyMonElevation = 7,
        BACK_PIC(Cosmog, 64, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cosmog),
        ICON(Cosmog, 2),
        .footprint = gMonFootprint_Cosmog,
        LEARNSETS(Cosmog),
        .evolutions = EVOLUTION({EVO_LEVEL, 43, SPECIES_COSMOEM}),
    },

    [SPECIES_COSMOEM] =
    {
        .baseHP        = 43,
        .baseAttack    = 29,
        .baseDefense   = 131,
        .baseSpeed     = 37,
        .baseSpAttack  = 29,
        .baseSpDefense = 131,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 140,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_STURDY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Cosmoem"),
        .cryId = CRY_COSMOEM,
        .natDexNum = NATIONAL_DEX_COSMOEM,
        .categoryName = _("Protostar"),
        .height = 1,
        .weight = 9999,
        .description = COMPOUND_STRING(
            "Motionless as if dead, its body is faintly\n"
            "warm to the touch. There's something\n"
            "accumulating around the black core\n"
            "within its hard shell."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cosmoem, 48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Cosmoem,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 3,
        BACK_PIC(Cosmoem, 64, 40),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cosmoem),
        ICON(Cosmoem, 0),
        .footprint = gMonFootprint_Cosmoem,
        LEARNSETS(Cosmoem),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 53, SPECIES_SOLGALEO},
                                {EVO_LEVEL_NIGHT, 53, SPECIES_LUNALA}),
    },

    [SPECIES_SOLGALEO] =
    {
        .baseHP        = 137,
        .baseAttack    = 137,
        .baseDefense   = 107,
        .baseSpeed     = 97,
        .baseSpAttack  = 113,
        .baseSpDefense = 89,
        .types = { TYPE_PSYCHIC, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 306,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_FULL_METAL_BODY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isLegendary = TRUE,
        .speciesName = _("Solgaleo"),
        .cryId = CRY_SOLGALEO,
        .natDexNum = NATIONAL_DEX_SOLGALEO,
        .categoryName = _("Sunne"),
        .height = 34,
        .weight = 2300,
        .description = COMPOUND_STRING(
            "It is said to live in another world.\n"
            "The intense light it radiates from the\n"
            "surface of its body can make the darkest\n"
            "of nights light up like midday."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
        FRONT_PIC(Solgaleo, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Solgaleo,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Solgaleo, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Solgaleo),
        ICON(Solgaleo, 0),
        .footprint = gMonFootprint_Solgaleo,
        LEARNSETS(Solgaleo),
    },

    [SPECIES_LUNALA] =
    {
        .baseHP        = 137,
        .baseAttack    = 113,
        .baseDefense   = 89,
        .baseSpeed     = 97,
        .baseSpAttack  = 137,
        .baseSpDefense = 107,
        .types = { TYPE_PSYCHIC, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 306,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_SHADOW_SHIELD, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .isLegendary = TRUE,
        .speciesName = _("Lunala"),
        .cryId = CRY_LUNALA,
        .natDexNum = NATIONAL_DEX_LUNALA,
        .categoryName = _("Moone"),
        .height = 40,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "When its third eye activates, away it flies\n"
            "to another world. This Pokémon devours\n"
            "light, drawing the moonless dark veil of\n"
            "night over the brightness of day."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 411,
        .trainerOffset = 5,
        FRONT_PIC(Lunala, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Lunala,
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .enemyMonElevation = 6,
        BACK_PIC(Lunala, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Lunala),
        ICON(Lunala, 2),
        .footprint = gMonFootprint_Lunala,
        LEARNSETS(Lunala),
    },
#endif //P_FAMILY_COSMOG

#if P_FAMILY_NIHILEGO
    [SPECIES_NIHILEGO] =
    {
        .baseHP        = 109,
        .baseAttack    = 53,
        .baseDefense   = 47,
        .baseSpeed     = 103,
        .baseSpAttack  = 127,
        .baseSpDefense = 131,
        .types = { TYPE_ROCK, TYPE_POISON },
        .catchRate = 45,
        .expYield = 257,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isUltraBeast = TRUE,
        .speciesName = _("Nihilego"),
        .cryId = CRY_NIHILEGO,
        .natDexNum = NATIONAL_DEX_NIHILEGO,
        .categoryName = _("Parasite"),
        .height = 12,
        .weight = 555,
        .description = COMPOUND_STRING(
            "One of several mysterious Ultra Beasts.\n"
            "It's unclear whether or not this Pokémon\n"
            "is sentient, but sometimes it can be\n"
            "observed behaving like a young girl."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Nihilego, 48, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Nihilego,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 6,
        BACK_PIC(Nihilego, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Nihilego),
        ICON(Nihilego, 0),
        .footprint = gMonFootprint_Nihilego,
        LEARNSETS(Nihilego),
    },
#endif //P_FAMILY_NIHILEGO

#if P_FAMILY_BUZZWOLE
    [SPECIES_BUZZWOLE] =
    {
        .baseHP        = 107,
        .baseAttack    = 139,
        .baseDefense   = 139,
        .baseSpeed     = 79,
        .baseSpAttack  = 53,
        .baseSpDefense = 53,
        .types = { TYPE_BUG, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack = 1,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .isUltraBeast = TRUE,
        .speciesName = _("Buzzwole"),
        .cryId = CRY_BUZZWOLE,
        .natDexNum = NATIONAL_DEX_BUZZWOLE,
        .categoryName = _("Swollen"),
        .height = 24,
        .weight = 3336,
        .description = COMPOUND_STRING(
            "This life-form called an Ultra Beast\n"
            "appeared from another world. It shows\n"
            "off its body, but whether that display\n"
            "is a boast or a threat remains unclear."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
        FRONT_PIC(Buzzwole, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Buzzwole,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Buzzwole, 64, 56),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Buzzwole),
        ICON(Buzzwole, 0),
        .footprint = gMonFootprint_Buzzwole,
        LEARNSETS(Buzzwole),
    },
#endif //P_FAMILY_BUZZWOLE

#if P_FAMILY_PHEROMOSA
    [SPECIES_PHEROMOSA] =
    {
        .baseHP        = 71,
        .baseAttack    = 137,
        .baseDefense   = 37,
        .baseSpeed     = 151,
        .baseSpAttack  = 137,
        .baseSpDefense = 37,
        .types = { TYPE_BUG, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isUltraBeast = TRUE,
        .speciesName = _("Pheromosa"),
        .cryId = CRY_PHEROMOSA,
        .natDexNum = NATIONAL_DEX_PHEROMOSA,
        .categoryName = _("Lissome"),
        .height = 18,
        .weight = 250,
        .description = COMPOUND_STRING(
            "One of the dangerous Ultra Beasts,\n"
            "it refuses to touch anything, perhaps\n"
            "because it senses some uncleanness\n"
            "in this world."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Pheromosa, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Pheromosa,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Pheromosa, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Pheromosa),
        ICON(Pheromosa, 2),
        .footprint = gMonFootprint_Pheromosa,
        LEARNSETS(Pheromosa),
    },
#endif //P_FAMILY_PHEROMOSA

#if P_FAMILY_XURKITREE
    [SPECIES_XURKITREE] =
    {
        .baseHP        = 83,
        .baseAttack    = 89,
        .baseDefense   = 71,
        .baseSpeed     = 83,
        .baseSpAttack  = 173,
        .baseSpDefense = 71,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 45,
        .expYield = 257,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isUltraBeast = TRUE,
        .speciesName = _("Xurkitree"),
        .cryId = CRY_XURKITREE,
        .natDexNum = NATIONAL_DEX_XURKITREE,
        .categoryName = _("Glowing"),
        .height = 38,
        .weight = 1000,
        .description = COMPOUND_STRING(
            "One of the mysterious life-forms known\n"
            "as Ultra Beasts. Astonishing electric\n"
            "shocks emanate from its entire body,\n"
            "according to witnesses."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        FRONT_PIC(Xurkitree, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Xurkitree,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW_FAST,
        BACK_PIC(Xurkitree, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Xurkitree),
        ICON(Xurkitree, 0),
        .footprint = gMonFootprint_Xurkitree,
        LEARNSETS(Xurkitree),
    },
#endif //P_FAMILY_XURKITREE

#if P_FAMILY_CELESTEELA
    [SPECIES_CELESTEELA] =
    {
        .baseHP        = 97,
        .baseAttack    = 101,
        .baseDefense   = 103,
        .baseSpeed     = 61,
        .baseSpAttack  = 107,
        .baseSpDefense = 101,
        .types = { TYPE_STEEL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .isUltraBeast = TRUE,
        .speciesName = _("Celesteela"),
        .cryId = CRY_CELESTEELA,
        .natDexNum = NATIONAL_DEX_CELESTEELA,
        .categoryName = _("Launch"),
        .height = 92,
        .weight = 9999,
        .description = COMPOUND_STRING(
            "It appeared from the Ultra Wormhole.\n"
            "One kind of Ultra Beast, witnesses saw\n"
            "it flying across the sky by expelling gas\n"
            "from its two arms."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 516,
        .trainerOffset = 13,
        FRONT_PIC(Celesteela, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Celesteela,
        .frontAnimId = ANIM_GROW_STUTTER_SLOW,
        BACK_PIC(Celesteela, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Celesteela),
        ICON(Celesteela, 0),
        .footprint = gMonFootprint_Celesteela,
        LEARNSETS(Celesteela),
    },
#endif //P_FAMILY_CELESTEELA

#if P_FAMILY_KARTANA
    [SPECIES_KARTANA] =
    {
        .baseHP        = 59,
        .baseAttack    = 181,
        .baseDefense   = 131,
        .baseSpeed     = 109,
        .baseSpAttack  = 59,
        .baseSpDefense = 31,
        .types = { TYPE_GRASS, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isUltraBeast = TRUE,
        .speciesName = _("Kartana"),
        .cryId = CRY_KARTANA,
        .natDexNum = NATIONAL_DEX_KARTANA,
        .categoryName = _("Drawn Sword"),
        .height = 3,
        .weight = 1,
        .description = COMPOUND_STRING(
            "This Ultra Beast came from the\n"
            "Ultra Wormhole. It seems not to attack\n"
            "enemies on its own, but its sharp body is\n"
            "a dangerous weapon in itself."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Kartana, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Kartana,
        .frontAnimId = ANIM_H_VIBRATE,
        .enemyMonElevation = 3,
        BACK_PIC(Kartana, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Kartana),
        ICON(Kartana, 0),
        .footprint = gMonFootprint_Kartana,
        LEARNSETS(Kartana),
    },
#endif //P_FAMILY_KARTANA

#if P_FAMILY_GUZZLORD
    [SPECIES_GUZZLORD] =
    {
        .baseHP        = 223,
        .baseAttack    = 101,
        .baseDefense   = 53,
        .baseSpeed     = 43,
        .baseSpAttack  = 97,
        .baseSpDefense = 53,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 257,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isUltraBeast = TRUE,
        .speciesName = _("Guzzlord"),
        .cryId = CRY_GUZZLORD,
        .natDexNum = NATIONAL_DEX_GUZZLORD,
        .categoryName = _("Junkivore"),
        .height = 55,
        .weight = 8880,
        .description = COMPOUND_STRING(
            "A dangerous Ultra Beast, it has gobbled\n"
            "mountains and swallowed whole buildings,\n"
            "according to reports. But for some reason\n"
            "its droppings have never been found."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(Guzzlord, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Guzzlord,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Guzzlord, 64, 56),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Guzzlord),
        ICON(Guzzlord, 0),
        .footprint = gMonFootprint_Guzzlord,
        LEARNSETS(Guzzlord),
    },
#endif //P_FAMILY_GUZZLORD

#if P_FAMILY_NECROZMA
#define NECROZMA_MISC_INFO                                                              \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .noFlip = TRUE,                                                                 \
        .speciesName = _("Necrozma"),                                                   \
        .natDexNum = NATIONAL_DEX_NECROZMA,                                             \
        .categoryName = _("Prism"),                                                     \
        .pokemonScale = 256,                                                            \
        .pokemonOffset = 3,                                                             \
        .trainerScale = 369,                                                            \
        .trainerOffset = 7,                                                             \
        .footprint = gMonFootprint_Necrozma,                                            \
        LEARNSETS(Necrozma),                                                            \
        .formSpeciesIdTable = sNecrozmaFormSpeciesIdTable,                              \
        .isLegendary = TRUE

    [SPECIES_NECROZMA] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 107,
        .baseDefense   = 101,
        .baseSpeed     = 79,
        .baseSpAttack  = 127,
        .baseSpDefense = 89,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 255,
        .expYield = 270,
        .evYield_Attack = 1,
        .evYield_SpAttack = 2,
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .cryId = CRY_NECROZMA,
        .height = 24,
        .weight = 2300,
        .description = COMPOUND_STRING(
            "Reminiscent of the Ultra Beasts, this\n"
            "life-form, apparently asleep underground,\n"
            "is thought to have come from another\n"
            "world in ancient times."),
        FRONT_PIC(Necrozma, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Necrozma,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 6,
        BACK_PIC(Necrozma, 64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Necrozma),
        ICON(Necrozma, 0),
    },

#if P_FUSION_FORMS
    [SPECIES_NECROZMA_DUSK_MANE] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 157,
        .baseDefense   = 127,
        .baseSpeed     = 77,
        .baseSpAttack  = 113,
        .baseSpDefense = 109,
        .types = { TYPE_PSYCHIC, TYPE_STEEL },
        .catchRate = 255,
        .expYield = 306,
        .evYield_Attack = 3,
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .cryId = CRY_NECROZMA_DUSK_MANE,
        .height = 38,
        .weight = 4600,
        .description = COMPOUND_STRING(
            "This is its form while it is\n"
            "devouring the light of Solgaleo. It pounces\n"
            "on foes and then slashes them with\n"
            "the claws on its four limbs and back."),
        FRONT_PIC(NecrozmaDuskMane, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Necrozma,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(NecrozmaDuskMane, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(NecrozmaDuskMane),
        ICON(NecrozmaDuskMane, 0),
        .cannotBeTraded = TRUE,
        .formChangeTable = sNecrozmaDuskManeFormChangeTable,
    },

    [SPECIES_NECROZMA_DAWN_WINGS] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 113,
        .baseDefense   = 109,
        .baseSpeed     = 77,
        .baseSpAttack  = 157,
        .baseSpDefense = 127,
        .types = { TYPE_PSYCHIC, TYPE_GHOST },
        .catchRate = 255,
        .expYield = 306,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .cryId = CRY_NECROZMA_DAWN_WINGS,
        .height = 42,
        .weight = 3500,
        .description = COMPOUND_STRING(
            "This is its form while it's\n"
            "devouring the light of Lunala. It grasps\n"
            "foes in its giant claws and rips them\n"
            "apart with brute force."),
        FRONT_PIC(NecrozmaDawnWings, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Necrozma,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        BACK_PIC(NecrozmaDawnWings, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(NecrozmaDawnWings),
        ICON(NecrozmaDawnWings, 0),
        .cannotBeTraded = TRUE,
        .formChangeTable = sNecrozmaDawnWingsFormChangeTable,
    },

#if P_ULTRA_BURST_FORMS
    [SPECIES_NECROZMA_ULTRA] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 167,
        .baseDefense   = 97,
        .baseSpeed     = 129,
        .baseSpAttack  = 167,
        .baseSpDefense = 97,
        .types = { TYPE_PSYCHIC, TYPE_DRAGON },
        .catchRate = 255,
        .expYield = 339,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .abilities = { ABILITY_NEUROFORCE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .cryId = CRY_NECROZMA_ULTRA,
        .height = 75,
        .weight = 2300,
        .description = COMPOUND_STRING(
            "The light pouring out from all over\n"
            "its body affects living things and\n"
            "nature, impacting them in various\n"
            "ways."),
        FRONT_PIC(NecrozmaUltra, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Necrozma,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(NecrozmaUltra, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(NecrozmaUltra),
        ICON(NecrozmaUltra, 2),
        .cannotBeTraded = TRUE,
        .isUltraBurst = TRUE,
    },
#endif //P_ULTRA_BURST_FORMS
#endif //P_FUSION_FORMS
#endif //P_FAMILY_NECROZMA

#if P_FAMILY_MAGEARNA
#define MAGEARNA_MISC_INFO(Form)                                                        \
        .baseHP        = 80,                                                            \
        .baseAttack    = 95,                                                            \
        .baseDefense   = 115,                                                           \
        .baseSpeed     = 65,                                                            \
        .baseSpAttack  = 130,                                                           \
        .baseSpDefense = 115,                                                           \
        .types = { TYPE_STEEL, TYPE_FAIRY },                                            \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_SOUL_HEART, ABILITY_NONE },                              \
        .speciesName = _("Magearna"),                                                   \
        .cryId = CRY_MAGEARNA,                                                          \
        .natDexNum = NATIONAL_DEX_MAGEARNA,                                             \
        .categoryName = _("Artificial"),                                                \
        .height = 10,                                                                   \
        .weight = 805,                                                                  \
        .pokemonScale = 305,                                                            \
        .pokemonOffset = 7,                                                             \
        .trainerScale = 257,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Form, 56, 64),                                                        \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Magearna,                                             \
        .frontAnimId = ANIM_H_SLIDE_SLOW,                                               \
        BACK_PIC(Form, 64, 56),                                                         \
        .backPicYOffset = 4,                                                            \
        PALETTES(Form),                                                                 \
        ICON(Form, 0),                                                                  \
        .footprint = gMonFootprint_Magearna,                                            \
        LEARNSETS(Magearna),                                                            \
        .formSpeciesIdTable = sMagearnaFormSpeciesIdTable,                              \
        .isMythical = TRUE
    //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_MAGEARNA] =
    {
        MAGEARNA_MISC_INFO(Magearna),
        .bodyColor = BODY_COLOR_GRAY,
        .description = COMPOUND_STRING(
            "This artificial Pokémon, constructed more\n"
            "than 500 years ago, can understand human\n"
            "speech but cannot itself speak. Its true\n"
            "self is its Soul-Heart, an artificial soul."),
    },
    [SPECIES_MAGEARNA_ORIGINAL_COLOR] =
    {
        MAGEARNA_MISC_INFO(MagearnaOriginalColor),
        .bodyColor = BODY_COLOR_RED,
        .description = COMPOUND_STRING(
            "This is its form from almost 500\n"
            "years ago. Its body is nothing more\n"
            "than a container-its artificial heart\n"
            "is the actual life-form."),
    },
#endif //P_FAMILY_MAGEARNA

#if P_FAMILY_MARSHADOW
    [SPECIES_MARSHADOW] =
    {
        .baseHP        = 90,
        .baseAttack    = 125,
        .baseDefense   = 80,
        .baseSpeed     = 125,
        .baseSpAttack  = 90,
        .baseSpDefense = 90,
        .types = { TYPE_FIGHTING, TYPE_GHOST },
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack = 2,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_TECHNICIAN, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Marshadow"),
        .cryId = CRY_MARSHADOW,
        .natDexNum = NATIONAL_DEX_MARSHADOW,
        .categoryName = _("Gloomdwellr"),
        .height = 7,
        .weight = 222,
        .description = COMPOUND_STRING(
            "Able to conceal itself in the shadows of\n"
            "others, it never appears before humans,\n"
            "so its very existence is the stuff of myth.\n"
            "This Pokémon is craven and cowering."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Marshadow, 32, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Marshadow,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Marshadow, 40, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Marshadow),
        ICON(Marshadow, 0),
        .footprint = gMonFootprint_Marshadow,
        LEARNSETS(Marshadow),
        .isMythical = TRUE,
    },
#endif //P_FAMILY_MARSHADOW

#if P_FAMILY_POIPOLE
    [SPECIES_POIPOLE] =
    {
        .baseHP        = 67,
        .baseAttack    = 73,
        .baseDefense   = 67,
        .baseSpeed     = 73,
        .baseSpAttack  = 73,
        .baseSpDefense = 67,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 45,
        .expYield = 189,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .isUltraBeast = TRUE,
        .speciesName = _("Poipole"),
        .cryId = CRY_POIPOLE,
        .natDexNum = NATIONAL_DEX_POIPOLE,
        .categoryName = _("Poison Pin"),
        .height = 6,
        .weight = 18,
        .description = COMPOUND_STRING(
            "This Ultra Beast is well enough\n"
            "liked to be chosen as a\n"
            "first partner in its own world."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Poipole, 40, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Poipole,
        .frontAnimId = ANIM_SHAKE_GLOW_PURPLE_SLOW,
        .enemyMonElevation = 9,
        BACK_PIC(Poipole, 48, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Poipole),
        ICON(Poipole, 0),
        .footprint = gMonFootprint_Poipole,
        LEARNSETS(Poipole),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_DRAGON_PULSE, SPECIES_NAGANADEL}),
    },

    [SPECIES_NAGANADEL] =
    {
        .baseHP        = 73,
        .baseAttack    = 73,
        .baseDefense   = 73,
        .baseSpeed     = 121,
        .baseSpAttack  = 127,
        .baseSpDefense = 73,
        .types = { TYPE_POISON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 243,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .isUltraBeast = TRUE,
        .speciesName = _("Naganadel"),
        .cryId = CRY_NAGANADEL,
        .natDexNum = NATIONAL_DEX_NAGANADEL,
        .categoryName = _("Poison Pin"),
        .height = 36,
        .weight = 1500,
        .description = COMPOUND_STRING(
            "It stores hundreds of liters of poisonous\n"
            "liquid inside its body. It is one of the\n"
            "organisms known as UBs."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
        FRONT_PIC(Naganadel, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Naganadel,
        .frontAnimId = ANIM_TRIANGLE_DOWN_TWICE,
        .enemyMonElevation = 7,
        BACK_PIC(Naganadel, 64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Naganadel),
        ICON(Naganadel, 0),
        .footprint = gMonFootprint_Naganadel,
        LEARNSETS(Naganadel),
    },
#endif //P_FAMILY_POIPOLE

#if P_FAMILY_STAKATAKA
    [SPECIES_STAKATAKA] =
    {
        .baseHP        = 61,
        .baseAttack    = 131,
        .baseDefense   = 211,
        .baseSpeed     = 13,
        .baseSpAttack  = 53,
        .baseSpDefense = 101,
        .types = { TYPE_ROCK, TYPE_STEEL },
        .catchRate = 30,
        .expYield = 257,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .isUltraBeast = TRUE,
        .speciesName = _("Stakataka"),
        .cryId = CRY_STAKATAKA,
        .natDexNum = NATIONAL_DEX_STAKATAKA,
        .categoryName = _("Rampart"),
        .height = 55,
        .weight = 8200,
        .description = COMPOUND_STRING(
            "It appeared from an Ultra Wormhole. Each\n"
            "one appears to be made up of many life-\n"
            "forms stacked one on top of each other."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(Stakataka, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Stakataka,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Stakataka, 64, 48),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Stakataka),
        ICON(Stakataka, 0),
        .footprint = gMonFootprint_Stakataka,
        LEARNSETS(Stakataka),
    },
#endif //P_FAMILY_STAKATAKA

#if P_FAMILY_BLACEPHALON
    [SPECIES_BLACEPHALON] =
    {
        .baseHP        = 53,
        .baseAttack    = 127,
        .baseDefense   = 53,
        .baseSpeed     = 107,
        .baseSpAttack  = 151,
        .baseSpDefense = 79,
        .types = { TYPE_FIRE, TYPE_GHOST },
        .catchRate = 30,
        .expYield = 257,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .isUltraBeast = TRUE,
        .speciesName = _("Blacephaln"),
        .cryId = CRY_BLACEPHALON,
        .natDexNum = NATIONAL_DEX_BLACEPHALON,
        .categoryName = _("Fireworks"),
        .height = 18,
        .weight = 130,
        .description = COMPOUND_STRING(
            "It slithers toward people and explode\n"
            "its head without warning. It is\n"
            "one kind of Ultra Beast."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Blacephalon, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Blacephalon,
        .frontAnimId = ANIM_SHAKE_GLOW_RED,
        BACK_PIC(Blacephalon, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Blacephalon),
        ICON(Blacephalon, 0),
        .footprint = gMonFootprint_Blacephalon,
        LEARNSETS(Blacephalon),
    },
#endif //P_FAMILY_BLACEPHALON

#if P_FAMILY_ZERAORA
    [SPECIES_ZERAORA] =
    {
        .baseHP        = 88,
        .baseAttack    = 112,
        .baseDefense   = 75,
        .baseSpeed     = 143,
        .baseSpAttack  = 102,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 3,
        .expYield = 270,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .isMythical = TRUE,
        .speciesName = _("Zeraora"),
        .cryId = CRY_ZERAORA,
        .natDexNum = NATIONAL_DEX_ZERAORA,
        .categoryName = _("Thunderclap"),
        .height = 15,
        .weight = 445,
        .description = COMPOUND_STRING(
            "It approaches its enemies at the speed\n"
            "of lightning, then tears them limb from\n"
            "limb with its sharp claws."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Zeraora, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Zeraora,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Zeraora, 64, 56),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Zeraora),
        ICON(Zeraora, 0),
        .footprint = gMonFootprint_Zeraora,
        LEARNSETS(Zeraora),
    },
#endif //P_FAMILY_ZERAORA

#if P_FAMILY_MELTAN
    [SPECIES_MELTAN] =
    {
        .baseHP        = 46,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 34,
        .baseSpAttack  = 55,
        .baseSpDefense = 35,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 3,
        .expYield = 135,
        .evYield_Attack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .isMythical = TRUE,
        .speciesName = _("Meltan"),
        .cryId = CRY_MELTAN,
        .natDexNum = NATIONAL_DEX_MELTAN,
        .categoryName = _("Hex Nut"),
        .height = 2,
        .weight = 80,
        .description = COMPOUND_STRING(
            "It melts particles of iron and other metals\n"
            "found in the subsoil, so it can absorb them\n"
            "into its body of molten steel."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Meltan, 32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Meltan,
        .frontAnimId = ANIM_GROW_STUTTER_SLOW,
        BACK_PIC(Meltan, 40, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Meltan),
        ICON(Meltan, 2),
        .footprint = gMonFootprint_Meltan,
        LEARNSETS(Meltan),
    },

#define MELMETAL_MISC_INFO                                                              \
        .baseHP        = 135,                                                           \
        .baseAttack    = 143,                                                           \
        .baseDefense   = 143,                                                           \
        .baseSpeed     = 34,                                                            \
        .baseSpAttack  = 80,                                                            \
        .baseSpDefense = 65,                                                            \
        .types = { TYPE_STEEL, TYPE_STEEL },                                            \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_Attack = 3,                                                            \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_IRON_FIST, ABILITY_NONE },                               \
        .bodyColor = BODY_COLOR_GRAY,                                                   \
        .speciesName = _("Melmetal"),                                                   \
        .cryId = CRY_MELMETAL,                                                          \
        .natDexNum = NATIONAL_DEX_MELMETAL,                                             \
        .categoryName = _("Hex Nut"),                                                   \
        .pokemonScale = 257,                                                            \
        .pokemonOffset = 10,                                                            \
        .trainerScale = 423,                                                            \
        .trainerOffset = 8,                                                             \
        .footprint = gMonFootprint_Melmetal,                                            \
        LEARNSETS(Melmetal),                                                            \
        .formSpeciesIdTable = sMelmetalFormSpeciesIdTable,                              \
        .formChangeTable = sMelmetalFormChangeTable,                                    \
        .isMythical = TRUE

    [SPECIES_MELMETAL] =
    {
        MELMETAL_MISC_INFO,
        .height = 25,
        .weight = 800,
        .description = COMPOUND_STRING(
            "Revered long ago for its capacity to create\n"
            "iron from nothing, for some reason it has\n"
            "come back to life after 3,000 years."),
        FRONT_PIC(Melmetal, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Melmetal,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Melmetal, 64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Melmetal),
        ICON(Melmetal, 2),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_MELMETAL_GIGANTAMAX] =
    {
        MELMETAL_MISC_INFO,
        .isGigantamax = TRUE,
        .height = 250,
        .weight = 0,
        .description = COMPOUND_STRING(
            "In a distant land, there are\n"
            "legends about a cyclopean giant. In fact,\n"
            "the giant was a Melmetal that was\n"
            "flooded with Gigantamax energy."),
        FRONT_PIC(MelmetalGigantamax, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_MelmetalGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MelmetalGigantamax, 64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MelmetalGigantamax),
        ICON(MelmetalGigantamax, 0),
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_MELTAN

#ifdef __INTELLISENSE__
};
#endif