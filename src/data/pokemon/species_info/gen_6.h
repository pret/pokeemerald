#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen6[] =
{
#endif

#if P_FAMILY_CHESPIN
    [SPECIES_CHESPIN] =
    {
        .baseHP        = 56,
        .baseAttack    = 61,
        .baseDefense   = 65,
        .baseSpeed     = 38,
        .baseSpAttack  = 48,
        .baseSpDefense = 45,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 63,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Chespin"),
        .cryId = CRY_CHESPIN,
        .natDexNum = NATIONAL_DEX_CHESPIN,
        .categoryName = _("Spiny Nut"),
        .height = 4,
        .weight = 90,
        .description = COMPOUND_STRING(
            "The quills on its head are usually soft.\n"
            "When it flexes them, the points become\n"
            "so hard and sharp that they can pierce\n"
            "rock without any effort."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Chespin, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Chespin,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Chespin, 56, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Chespin),
        ICON(Chespin, 1),
        .footprint = gMonFootprint_Chespin,
        LEARNSETS(Chespin),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_QUILLADIN}),
    },

    [SPECIES_QUILLADIN] =
    {
        .baseHP        = 61,
        .baseAttack    = 78,
        .baseDefense   = 95,
        .baseSpeed     = 57,
        .baseSpAttack  = 56,
        .baseSpDefense = 58,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Quilladin"),
        .cryId = CRY_QUILLADIN,
        .natDexNum = NATIONAL_DEX_QUILLADIN,
        .categoryName = _("Spiny Armor"),
        .height = 7,
        .weight = 290,
        .description = COMPOUND_STRING(
            "They strengthen the sturdy shell covering\n"
            "their bodies by running into one another.\n"
            "They are very kind and won't start fights,\n"
            "but will counterattack with sharp quills."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Quilladin, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Quilladin,
        .frontAnimId = ANIM_LUNGE_GROW,
        BACK_PIC(Quilladin, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Quilladin),
        ICON(Quilladin, 1),
        .footprint = gMonFootprint_Quilladin,
        LEARNSETS(Quilladin),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_CHESNAUGHT}),
    },

    [SPECIES_CHESNAUGHT] =
    {
        .baseHP        = 88,
        .baseAttack    = 107,
        .baseDefense   = 122,
        .baseSpeed     = 64,
        .baseSpAttack  = 74,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Chesnaught"),
        .cryId = CRY_CHESNAUGHT,
        .natDexNum = NATIONAL_DEX_CHESNAUGHT,
        .categoryName = _("Spiny Armor"),
        .height = 16,
        .weight = 900,
        .description = COMPOUND_STRING(
            "It shields its allies from danger with\n"
            "its own body. When it takes a defensive\n"
            "posture with its fists guarding its face,\n"
            "it can withstand a bomb blast."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Chesnaught, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Chesnaught,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        BACK_PIC(Chesnaught, 64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Chesnaught),
        ICON(Chesnaught, 1),
        .footprint = gMonFootprint_Chesnaught,
        LEARNSETS(Chesnaught),
    },
#endif //P_FAMILY_CHESPIN

#if P_FAMILY_FENNEKIN
    [SPECIES_FENNEKIN] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 62,
        .baseSpDefense = 60,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 61,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Fennekin"),
        .cryId = CRY_FENNEKIN,
        .natDexNum = NATIONAL_DEX_FENNEKIN,
        .categoryName = _("Fox"),
        .height = 4,
        .weight = 94,
        .description = COMPOUND_STRING(
            "As it walks, it munches on a twig to fill\n"
            "itself with energy in place of a snack.\n"
            "It intimidates opponents by puffing hot\n"
            "air out of its roomy ears."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fennekin, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Fennekin,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Fennekin, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Fennekin),
        ICON(Fennekin, 0),
        .footprint = gMonFootprint_Fennekin,
        LEARNSETS(Fennekin),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_BRAIXEN}),
    },

    [SPECIES_BRAIXEN] =
    {
        .baseHP        = 59,
        .baseAttack    = 59,
        .baseDefense   = 58,
        .baseSpeed     = 73,
        .baseSpAttack  = 90,
        .baseSpDefense = 70,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 143,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Braixen"),
        .cryId = CRY_BRAIXEN,
        .natDexNum = NATIONAL_DEX_BRAIXEN,
        .categoryName = _("Fox"),
        .height = 10,
        .weight = 145,
        .description = COMPOUND_STRING(
            "Braixen has a twig stuck in its tail.\n"
            "When the twig is plucked from its tail,\n"
            "friction sets the twig alight. The flame\n"
            "is used to send signals to its allies."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Braixen, 48, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Braixen,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Braixen, 64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Braixen),
        ICON(Braixen, 0),
        .footprint = gMonFootprint_Braixen,
        LEARNSETS(Braixen),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_DELPHOX}),
    },

    [SPECIES_DELPHOX] =
    {
        .baseHP        = 75,
        .baseAttack    = 69,
        .baseDefense   = 72,
        .baseSpeed     = 104,
        .baseSpAttack  = 114,
        .baseSpDefense = 100,
        .types = { TYPE_FIRE, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 240,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Delphox"),
        .cryId = CRY_DELPHOX,
        .natDexNum = NATIONAL_DEX_DELPHOX,
        .categoryName = _("Fox"),
        .height = 15,
        .weight = 390,
        .description = COMPOUND_STRING(
            "It gazes into the flame at the tip of its\n"
            "branch to achieve a focused state, which\n"
            "allows it to see into the future. It uses\n"
            "psychic power to incinerate its foes."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Delphox, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Delphox,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Delphox, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Delphox),
        ICON(Delphox, 0),
        .footprint = gMonFootprint_Delphox,
        LEARNSETS(Delphox),
    },
#endif //P_FAMILY_FENNEKIN

#if P_FAMILY_FROAKIE
    [SPECIES_FROAKIE] =
    {
        .baseHP        = 41,
        .baseAttack    = 56,
        .baseDefense   = 40,
        .baseSpeed     = 71,
        .baseSpAttack  = 62,
        .baseSpDefense = 44,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Froakie"),
        .cryId = CRY_FROAKIE,
        .natDexNum = NATIONAL_DEX_FROAKIE,
        .categoryName = _("Bubble Frog"),
        .height = 3,
        .weight = 70,
        .description = COMPOUND_STRING(
            "It protects its skin by covering its body\n"
            "in bubbles it secretes from its chest and\n"
            "back. Beneath its happy-go-lucky air, it\n"
            "keeps a watchful eye on its surroundings."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Froakie, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Froakie,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Froakie, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Froakie),
        ICON(Froakie, 0),
        .footprint = gMonFootprint_Froakie,
        LEARNSETS(Froakie),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_FROGADIER}),
    },

    [SPECIES_FROGADIER] =
    {
        .baseHP        = 54,
        .baseAttack    = 63,
        .baseDefense   = 52,
        .baseSpeed     = 97,
        .baseSpAttack  = 83,
        .baseSpDefense = 56,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Frogadier"),
        .cryId = CRY_FROGADIER,
        .natDexNum = NATIONAL_DEX_FROGADIER,
        .categoryName = _("Bubble Frog"),
        .height = 6,
        .weight = 109,
        .description = COMPOUND_STRING(
            "It can throw bubble-covered pebbles with\n"
            "precise control, hitting empty cans up to\n"
            "a hundred feet away. Frogadier's swiftness\n"
            "is unparalleled."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Frogadier, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Frogadier,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Frogadier, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Frogadier),
        ICON(Frogadier, 0),
        .footprint = gMonFootprint_Frogadier,
        LEARNSETS(Frogadier),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GRENINJA}),
    },

#define GRENINJA_NORMAL_MISC_INFO           \
        .baseHP        = 72,                \
        .baseAttack    = 95,                \
        .baseDefense   = 67,                \
        .baseSpeed     = 122,               \
        .baseSpAttack  = 103,               \
        .baseSpDefense = 71,                \
        .expYield = 239,                    \
        .description = gGreninjaPokedexText,\
        FRONT_PIC(Greninja, 64, 56),        \
        .frontPicYOffset = 7,               \
        .frontAnimFrames = sAnims_Greninja, \
        BACK_PIC(Greninja, 64, 48),         \
        .backPicYOffset = 11,               \
        PALETTES(Greninja),                 \
        ICON(Greninja, 0)

#define GRENINJA_MISC_INFO                              \
        .types = { TYPE_WATER, TYPE_DARK },             \
        .catchRate = 45,                                \
        .evYield_Speed = 3,                             \
        .eggCycles = 20,                                \
        .friendship = STANDARD_FRIENDSHIP,              \
        .growthRate = GROWTH_MEDIUM_SLOW,               \
        .bodyColor = BODY_COLOR_BLUE,                   \
        .noFlip = TRUE,                                 \
        .speciesName = _("Greninja"),                   \
        .cryId = CRY_GRENINJA,                          \
        .natDexNum = NATIONAL_DEX_GRENINJA,             \
        .categoryName = _("Ninja"),                     \
        .height = 15,                                   \
        .weight = 400,                                  \
        .pokemonScale = 268,                            \
        .pokemonOffset = 2,                             \
        .trainerScale = 271,                            \
        .trainerOffset = 0,                             \
        .footprint = gMonFootprint_Greninja,            \
        LEARNSETS(Greninja),                            \
        .formSpeciesIdTable = sGreninjaFormSpeciesIdTable

    [SPECIES_GRENINJA] =
    {
        GRENINJA_MISC_INFO,
        GRENINJA_NORMAL_MISC_INFO,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN },
        .frontAnimId = ANIM_V_STRETCH,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
    },

    [SPECIES_GRENINJA_BATTLE_BOND] =
    {
        GRENINJA_MISC_INFO,
        GRENINJA_NORMAL_MISC_INFO,
        .genderRatio = MON_MALE,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BATTLE_BOND, ABILITY_NONE, ABILITY_NONE },
        .frontAnimId = ANIM_FLICKER_INCREASING,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .formChangeTable = sGreninjaBattleBondFormChangeTable,
    },

    [SPECIES_GRENINJA_ASH] =
    {
        GRENINJA_MISC_INFO,
        .baseHP        = 72,
        .baseAttack    = 145,
        .baseDefense   = 67,
        .baseSpeed     = 132,
        .baseSpAttack  = 153,
        .baseSpDefense = 71,
        .expYield = 288,
        .genderRatio = MON_MALE,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BATTLE_BOND, ABILITY_NONE, ABILITY_NONE },
        .description = COMPOUND_STRING(
            "It appears and vanishes with a ninja's\n"
            "grace. It toys with its enemies using swift\n"
            "movements, while slicing them with throwing\n"
            "stars made of compressed water."),
        FRONT_PIC(GreninjaAsh, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_GreninjaAsh,
        BACK_PIC(GreninjaAsh, 64, 48),
        .backPicYOffset = 11,
        PALETTES(GreninjaAsh),
        ICON(GreninjaAsh, 0),
        .frontAnimId = ANIM_FLICKER_INCREASING,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .formChangeTable = sGreninjaBattleBondFormChangeTable,
    },
#endif //P_FAMILY_FROAKIE

#if P_FAMILY_BUNNELBY
    [SPECIES_BUNNELBY] =
    {
        .baseHP        = 38,
        .baseAttack    = 36,
        .baseDefense   = 38,
        .baseSpeed     = 57,
        .baseSpAttack  = 32,
        .baseSpDefense = 36,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 47,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PICKUP, ABILITY_CHEEK_POUCH, ABILITY_HUGE_POWER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bunnelby"),
        .cryId = CRY_BUNNELBY,
        .natDexNum = NATIONAL_DEX_BUNNELBY,
        .categoryName = _("Digging"),
        .height = 4,
        .weight = 50,
        .description = COMPOUND_STRING(
            "It has ears like shovels. Digging holes\n"
            "strengthens its ears so much that they\n"
            "can sever thick roots effortlessly.\n"
            "Bunnelby dig the whole night through."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bunnelby, 48, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Bunnelby,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Bunnelby, 48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Bunnelby),
        ICON(Bunnelby, 2),
        .footprint = gMonFootprint_Bunnelby,
        LEARNSETS(Bunnelby),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_DIGGERSBY}),
    },

    [SPECIES_DIGGERSBY] =
    {
        .baseHP        = 85,
        .baseAttack    = 56,
        .baseDefense   = 77,
        .baseSpeed     = 78,
        .baseSpAttack  = 50,
        .baseSpDefense = 77,
        .types = { TYPE_NORMAL, TYPE_GROUND },
        .catchRate = 127,
        .expYield = 148,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PICKUP, ABILITY_CHEEK_POUCH, ABILITY_HUGE_POWER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Diggersby"),
        .cryId = CRY_DIGGERSBY,
        .natDexNum = NATIONAL_DEX_DIGGERSBY,
        .categoryName = _("Digging"),
        .height = 10,
        .weight = 424,
        .description = COMPOUND_STRING(
            "With its powerful ears it reduces dense\n"
            "bedrock to rubble. It can be a big help\n"
            "at construction sites. When it's finished\n"
            "digging, it lounges about lazily."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Diggersby, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Diggersby,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Diggersby, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Diggersby),
        ICON(Diggersby, 2),
        .footprint = gMonFootprint_Diggersby,
        LEARNSETS(Diggersby),
    },
#endif //P_FAMILY_BUNNELBY

#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] =
    {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 43,
        .baseSpeed     = 62,
        .baseSpAttack  = 40,
        .baseSpDefense = 38,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_NONE, ABILITY_GALE_WINGS },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Fletchling"),
        .cryId = CRY_FLETCHLING,
        .natDexNum = NATIONAL_DEX_FLETCHLING,
        .categoryName = _("Tiny Robin"),
        .height = 3,
        .weight = 17,
        .description = COMPOUND_STRING(
            "This amiable Pokémon is easy to train.\n"
            "But when battle is joined, it shows its\n"
            "ferocious side. It's merciless to\n"
            "intruders that enter its territory."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fletchling, 40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Fletchling,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Fletchling, 64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Fletchling),
        ICON(Fletchling, 2),
        .footprint = gMonFootprint_Fletchling,
        LEARNSETS(Fletchling),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_FLETCHINDER}),
    },

    [SPECIES_FLETCHINDER] =
    {
        .baseHP        = 62,
        .baseAttack    = 73,
        .baseDefense   = 55,
        .baseSpeed     = 84,
        .baseSpAttack  = 56,
        .baseSpDefense = 52,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 134,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_GALE_WINGS },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Flechinder"),
        .cryId = CRY_FLETCHINDER,
        .natDexNum = NATIONAL_DEX_FLETCHINDER,
        .categoryName = _("Ember"),
        .height = 7,
        .weight = 160,
        .description = COMPOUND_STRING(
            "From its beak, it expels embers that set\n"
            "the tall grass on fire. Then it pounces on\n"
            "any bewildered Pokémon that pop out of\n"
            "the grass."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fletchinder, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Fletchinder,
        .frontAnimId = ANIM_V_SLIDE_SLOW,
        .enemyMonElevation = 9,
        BACK_PIC(Fletchinder, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Fletchinder),
        ICON(Fletchinder, 2),
        .footprint = gMonFootprint_Fletchinder,
        LEARNSETS(Fletchinder),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_TALONFLAME}),
    },

    [SPECIES_TALONFLAME] =
    {
        .baseHP        = 78,
        .baseAttack    = 81,
        .baseDefense   = 71,
        .baseSpeed     = 126,
        .baseSpAttack  = 74,
        .baseSpDefense = 69,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 175,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_GALE_WINGS },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Talonflame"),
        .cryId = CRY_TALONFLAME,
        .natDexNum = NATIONAL_DEX_TALONFLAME,
        .categoryName = _("Scorching"),
        .height = 12,
        .weight = 245,
        .description = COMPOUND_STRING(
            "In the fever of an exciting battle, it\n"
            "showers embers from the gaps between its\n"
            "feathers and takes to the air. It finishes\n"
            "its prey off with a colossal kick."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Talonflame, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Talonflame,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 7,
        BACK_PIC(Talonflame, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Talonflame),
        ICON(Talonflame, 2),
        .footprint = gMonFootprint_Talonflame,
        LEARNSETS(Talonflame),
    },
#endif //P_FAMILY_FLETCHLING

#if P_FAMILY_SCATTERBUG
    [SPECIES_SCATTERBUG] =
    {
        .baseHP        = 38,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 27,
        .baseSpDefense = 25,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 40,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_COMPOUND_EYES, ABILITY_FRIEND_GUARD },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Scatterbug"),
        .cryId = CRY_SCATTERBUG,
        .natDexNum = NATIONAL_DEX_SCATTERBUG,
        .categoryName = _("Scatterdust"),
        .height = 3,
        .weight = 25,
        .description = COMPOUND_STRING(
            "When under attack from bird Pokémon,\n"
            "it spews a poisonous black powder that\n"
            "causes paralysis on contact. Scatterbug\n"
            "can live in any region or climate."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Scatterbug, 32, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Scatterbug,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Scatterbug, 40, 56),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Scatterbug),
        ICON(Scatterbug, 1),
        .footprint = gMonFootprint_Scatterbug,
        LEARNSETS(Scatterbug),
        .evolutions = EVOLUTION({EVO_LEVEL, 9, SPECIES_SPEWPA}),
    },

    [SPECIES_SPEWPA] =
    {
        .baseHP        = 45,
        .baseAttack    = 22,
        .baseDefense   = 60,
        .baseSpeed     = 29,
        .baseSpAttack  = 27,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 120,
        .expYield = 75,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_FRIEND_GUARD },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Spewpa"),
        .cryId = CRY_SPEWPA,
        .natDexNum = NATIONAL_DEX_SPEWPA,
        .categoryName = _("Scatterdust"),
        .height = 3,
        .weight = 84,
        .description = COMPOUND_STRING(
            "It lives hidden within thicket shadows.\n"
            "When predators attack, it quickly bristles\n"
            "the fur covering its body in an effort to\n"
            "threaten them."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Spewpa, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Spewpa,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Spewpa, 48, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Spewpa),
        ICON(Spewpa, 1),
        .footprint = gMonFootprint_Spewpa,
        LEARNSETS(Spewpa),
        .evolutions = EVOLUTION({EVO_LEVEL, 12, SPECIES_VIVILLON_ICY_SNOW}),
    },

#define VIVILLON_MISC_INFO(form, color, iconPal)                                            \
        .baseHP        = 80,                                                                \
        .baseAttack    = 52,                                                                \
        .baseDefense   = 50,                                                                \
        .baseSpeed     = 89,                                                                \
        .baseSpAttack  = 90,                                                                \
        .baseSpDefense = 50,                                                                \
        .types = { TYPE_BUG, TYPE_FLYING },                                                 \
        .catchRate = 45,                                                                    \
        .expYield = 185,                                                                    \
        .evYield_HP = 1,                                                                    \
        .evYield_Speed = 1,                                                                 \
        .evYield_SpAttack = 1,                                                              \
        .genderRatio = PERCENT_FEMALE(50),                                                  \
        .eggCycles = 15,                                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                                   \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },                                      \
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_COMPOUND_EYES, ABILITY_FRIEND_GUARD },  \
        .bodyColor = color,                                                                 \
        .speciesName = _("Vivillon"),                                                       \
        .cryId = CRY_VIVILLON,                                                              \
        .natDexNum = NATIONAL_DEX_VIVILLON,                                                 \
        .categoryName = _("Scale"),                                                         \
        .height = 12,                                                                       \
        .weight = 170,                                                                      \
        .pokemonScale = 282,                                                                \
        .pokemonOffset = 4,                                                                 \
        .trainerScale = 256,                                                                \
        .trainerOffset = 0,                                                                 \
        FRONT_PIC(Vivillon ##form, 64, 64),                                                 \
        .frontPicYOffset = 0,                                                               \
        .frontAnimFrames = sAnims_Vivillon,                                                 \
        .frontAnimId = ANIM_ZIGZAG_SLOW,                                                    \
        .enemyMonElevation = 9,                                                             \
        BACK_PIC(Vivillon ##form, 64, 64),                                                  \
        .backPicYOffset = 0,                                                                \
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,                                    \
        PALETTES(Vivillon ##form),                                                           \
        ICON(Vivillon ##form, iconPal),                                                     \
        .footprint = gMonFootprint_Vivillon,                                                \
        LEARNSETS(Vivillon),                                                                \
        .formSpeciesIdTable = sVivillonFormSpeciesIdTable

    [SPECIES_VIVILLON_ICY_SNOW] =
    {
        VIVILLON_MISC_INFO(IcySnow, BODY_COLOR_WHITE, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from frigid lands.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_POLAR] =
    {
        VIVILLON_MISC_INFO(Polar, BODY_COLOR_BLUE, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from snowy lands.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_TUNDRA] =
    {
        VIVILLON_MISC_INFO(Tundra, BODY_COLOR_BLUE, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from lands of severe cold.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_CONTINENTAL] =
    {
        VIVILLON_MISC_INFO(Continental, BODY_COLOR_YELLOW, 2),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from lands of vast space.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_GARDEN] =
    {
        VIVILLON_MISC_INFO(Garden, BODY_COLOR_GREEN, 1),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from verdant lands.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_ELEGANT] =
    {
        VIVILLON_MISC_INFO(Elegant, BODY_COLOR_PURPLE, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands with distinct seasons.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_MEADOW] =
    {
        VIVILLON_MISC_INFO(Meadow, BODY_COLOR_PINK, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands where flowers bloom.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_MODERN] =
    {
        VIVILLON_MISC_INFO(Modern, BODY_COLOR_RED, 2),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from sun-drenched lands.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_MARINE] =
    {
        VIVILLON_MISC_INFO(Marine, BODY_COLOR_BLUE, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands with ocean breezes.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_ARCHIPELAGO] =
    {
        VIVILLON_MISC_INFO(Archipelago, BODY_COLOR_BROWN, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from places with many islands.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_HIGH_PLAINS] =
    {
        VIVILLON_MISC_INFO(HighPlains, BODY_COLOR_BROWN, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from lands with little rain.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_SANDSTORM] =
    {
        VIVILLON_MISC_INFO(Sandstorm, BODY_COLOR_BROWN, 1),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from parched lands.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_RIVER] =
    {
        VIVILLON_MISC_INFO(River, BODY_COLOR_BROWN, 2),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands where large rivers flow.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_MONSOON] =
    {
        VIVILLON_MISC_INFO(Monsoon, BODY_COLOR_GRAY, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands with intense rainfall.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_SAVANNA] =
    {
        VIVILLON_MISC_INFO(Savanna, BODY_COLOR_GREEN, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands with a tropical climate.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_SUN] =
    {
        VIVILLON_MISC_INFO(Sun, BODY_COLOR_RED, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from lands bathed in light.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_OCEAN] =
    {
        VIVILLON_MISC_INFO(Ocean, BODY_COLOR_RED, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands of perpetual summer.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_JUNGLE] =
    {
        VIVILLON_MISC_INFO(Jungle, BODY_COLOR_GREEN, 0),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in. This\n"
            "form is from lands of tropical rainforests.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_FANCY] =
    {
        VIVILLON_MISC_INFO(Fancy, BODY_COLOR_PINK, 1),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from a mysterious land.\n"
            "It scatters toxic color scales in battle."),
    },
    [SPECIES_VIVILLON_POKE_BALL] =
    {
        VIVILLON_MISC_INFO(PokeBall, BODY_COLOR_RED, 2),
        .description = COMPOUND_STRING(
            "Its pattern depends on the climate and\n"
            "topography of the land it was born in.\n"
            "This form is from a special land.\n"
            "It scatters toxic color scales in battle."),
    },
#endif //P_FAMILY_SCATTERBUG

#if P_FAMILY_LITLEO
    [SPECIES_LITLEO] =
    {
        .baseHP        = 62,
        .baseAttack    = 50,
        .baseDefense   = 58,
        .baseSpeed     = 72,
        .baseSpAttack  = 73,
        .baseSpDefense = 54,
        .types = { TYPE_FIRE, TYPE_NORMAL },
        .catchRate = 220,
        .expYield = 74,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(87.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RIVALRY, ABILITY_UNNERVE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Litleo"),
        .cryId = CRY_LITLEO,
        .natDexNum = NATIONAL_DEX_LITLEO,
        .categoryName = _("Lion Cub"),
        .height = 6,
        .weight = 135,
        .description = COMPOUND_STRING(
            "They set off on their own from their pride\n"
            "and live by themselves to become stronger.\n"
            "These hot-blooded Pokémon are quick\n"
            "to start a fight."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Litleo, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Litleo,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Litleo, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Litleo),
        ICON(Litleo, 2),
        .footprint = gMonFootprint_Litleo,
        LEARNSETS(Litleo),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_PYROAR}),
    },

    [SPECIES_PYROAR] =
    {
        .baseHP        = 86,
        .baseAttack    = 68,
        .baseDefense   = 72,
        .baseSpeed     = 106,
        .baseSpAttack  = 109,
        .baseSpDefense = 66,
        .types = { TYPE_FIRE, TYPE_NORMAL },
        .catchRate = 65,
        .expYield = 177,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(87.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RIVALRY, ABILITY_UNNERVE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pyroar"),
        .cryId = CRY_PYROAR,
        .natDexNum = NATIONAL_DEX_PYROAR,
        .categoryName = _("Royal"),
        .height = 15,
        .weight = 815,
        .description = COMPOUND_STRING(
            "The male with the largest mane of fire\n"
            "is the leader of the pride. The females\n"
            "protect the pride's cubs. They viciously\n"
            "threaten any challenger."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Pyroar, 64, 64),
        FRONT_PIC_FEMALE(Pyroar, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Pyroar,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Pyroar, 64, 64),
        BACK_PIC_FEMALE(Pyroar, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Pyroar),
        ICON(Pyroar, 2),
        ICON_FEMALE(Pyroar, 2),
        .footprint = gMonFootprint_Pyroar,
        LEARNSETS(Pyroar),
    },
#endif //P_FAMILY_LITLEO

#if P_FAMILY_FLABEBE
#define FLABEBE_MISC_INFO(Form, FORM, iconPal)                                  \
        .baseHP        = 44,                                                    \
        .baseAttack    = 38,                                                    \
        .baseDefense   = 39,                                                    \
        .baseSpeed     = 42,                                                    \
        .baseSpAttack  = 61,                                                    \
        .baseSpDefense = 79,                                                    \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                    \
        .catchRate = 225,                                                       \
        .expYield = 61,                                                         \
        .evYield_SpDefense = 1,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },                      \
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS },  \
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .speciesName = _("Flabébé"),                                            \
        .cryId = CRY_FLABEBE,                                                   \
        .natDexNum = NATIONAL_DEX_FLABEBE,                                      \
        .categoryName = _("Single Bloom"),                                      \
        .height = 1,                                                            \
        .weight = 1,                                                            \
        .pokemonScale = 682,                                                    \
        .pokemonOffset = 24,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        FRONT_PIC(Flabebe, 48, 56),                                             \
        .frontPicYOffset = 6,                                                   \
        .frontAnimFrames = sAnims_Flabebe,                                      \
        .frontAnimId = ANIM_H_SLIDE_SLOW,                                       \
        .enemyMonElevation = 6,                                                 \
        BACK_PIC(Flabebe, 64, 40),                                              \
        .backPicYOffset = 12,                                                   \
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,                              \
        PALETTES(Flabebe##Form##Flower),                                         \
        ICON(Flabebe##Form##Flower, iconPal),                                   \
        .footprint = gMonFootprint_Flabebe,                                     \
        LEARNSETS(Flabebe),                                                     \
        .formSpeciesIdTable = sFlabebeFormSpeciesIdTable,                       \
        .evolutions = EVOLUTION({EVO_LEVEL, 19, SPECIES_FLOETTE_ ##FORM##_FLOWER})

    [SPECIES_FLABEBE_RED_FLOWER] =
    {
        FLABEBE_MISC_INFO(Red, RED, 1),
        .description = COMPOUND_STRING(
            "This Flabébé rides a red flower.\n"
            "Immediately after birth, this Pokémon\n"
            "begins flying around in search of a\n"
            "flower it likes."),
    },
    [SPECIES_FLABEBE_YELLOW_FLOWER] =
    {
        FLABEBE_MISC_INFO(Yellow, YELLOW, 1),
        .description = COMPOUND_STRING(
            "It unleashes a variety of moves by\n"
            "drawing forth the power hidden\n"
            "within flowers. This Pokémon is\n"
            "particularly fond of yellow flowers."),
    },
    [SPECIES_FLABEBE_ORANGE_FLOWER] =
    {
        FLABEBE_MISC_INFO(Orange, ORANGE, 0),
        .description = COMPOUND_STRING(
            "It receives strength from flowers\n"
            "and gives them some of its energy in\n"
            "return. This Pokémon likes orange\n"
            "flowers best of all."),
    },
    [SPECIES_FLABEBE_BLUE_FLOWER]   =
    {
        FLABEBE_MISC_INFO(Blue, BLUE, 0),
        .description = COMPOUND_STRING(
            "This Pokémon likes blue flowers\n"
            "best of all. It floats upward using the\n"
            "power emanating from its flower\n"
            "and bobs along lightly through the air."),
    },
    [SPECIES_FLABEBE_WHITE_FLOWER]  =
    {
        FLABEBE_MISC_INFO(White, WHITE, 1),
        .description = COMPOUND_STRING(
            "When evening falls, it searches out\n"
            "a place blooming with flowers of\n"
            "the same white color as itself, and\n"
            "then it goes to sleep."),
    },

#define FLOETTE_MISC_INFO(form, FORM, iconPal)                                  \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                    \
        .catchRate = 120,                                                       \
        .evYield_SpDefense = 2,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS },  \
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .speciesName = _("Floette"),                                            \
        .natDexNum = NATIONAL_DEX_FLOETTE,                                      \
        .categoryName = _("Single Bloom"),                                      \
        .height = 2,                                                            \
        .weight = 9,                                                            \
        .pokemonScale = 682,                                                    \
        .pokemonOffset = 24,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        .frontAnimFrames = sAnims_Floette,                                      \
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,                                     \
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,                              \
        PALETTES(Floette ##form##Flower),                                        \
        ICON(Floette##form##Flower, iconPal),                                   \
        .footprint = gMonFootprint_Floette,                                     \
        .formSpeciesIdTable = sFloetteFormSpeciesIdTable

#define FLOETTE_NORMAL_INFO(form, FORM, iconPal)                                                \
        .baseHP        = 54,                                                                    \
        .baseAttack    = 45,                                                                    \
        .baseDefense   = 47,                                                                    \
        .baseSpeed     = 52,                                                                    \
        .baseSpAttack  = 75,                                                                    \
        .baseSpDefense = 98,                                                                    \
        .expYield = 130,                                                                        \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },                                      \
        .cryId = CRY_FLOETTE,                                                                   \
        FRONT_PIC(Floette, 48, 64),                                                             \
        .frontPicYOffset = 3,                                                                   \
        .enemyMonElevation = 4,                                                                 \
        BACK_PIC(Floette, 64, 64),                                                              \
        .backPicYOffset = 2,                                                                    \
        LEARNSETS(Floette),                                                                     \
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_FLORGES_ ##FORM##_FLOWER}),\
        FLOETTE_MISC_INFO(form, FORM, iconPal)

    [SPECIES_FLOETTE_RED_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Red, RED, 1),
        .description = COMPOUND_STRING(
            "This Pokémon uses red wavelengths\n"
            "of light to pour its own energy\n"
            "into flowers and draw forth their\n"
            "latent potential."),
    },
    [SPECIES_FLOETTE_YELLOW_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Yellow, YELLOW, 1),
        .description = COMPOUND_STRING(
            "This Pokémon can draw forth the\n"
            "power hidden within yellow flowers.\n"
            "This power then becomes the moves\n"
            "Floette uses to protect itself."),
    },
    [SPECIES_FLOETTE_ORANGE_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Orange, ORANGE, 0),
        .description = COMPOUND_STRING(
            "This Pokémon can draw forth the\n"
            "most power when in sync with orange\n"
            "flowers, compared to flowers of other\n"
            "colors."),
    },
    [SPECIES_FLOETTE_BLUE_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Blue, BLUE, 0),
        .description = COMPOUND_STRING(
            "Whenever this Pokémon finds\n"
            "flowering plants that are withering, it\n"
            "will bring them back to its territory\n"
            "and care for them."),
    },
    [SPECIES_FLOETTE_WHITE_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(White, WHITE, 1),
        .description = COMPOUND_STRING(
            "If it finds someone messing up a\n"
            "flower bed, it will attack them\n"
            "without mercy. This Floette takes\n"
            "particularly good care of white flowers."),
    },
    [SPECIES_FLOETTE_ETERNAL_FLOWER] =
    {
        FLOETTE_MISC_INFO(Eternal, ETERNAL, 0),
        .baseHP        = 74,
        .baseAttack    = 65,
        .baseDefense   = 67,
        .baseSpeed     = 92,
        .baseSpAttack  = 125,
        .baseSpDefense = 128,
        .expYield = 243,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .description = COMPOUND_STRING(
            "The flower it's holding can no\n"
            "longer be found blooming anywhere. It's\n"
            "also thought to contain terrifying\n"
            "power."),
        .cryId = CRY_FLOETTE_ETERNAL_FLOWER,
        FRONT_PIC(FloetteEternalFlower, 64, 64),
        .frontPicYOffset = 3,
        .enemyMonElevation = 4,
        BACK_PIC(FloetteEternalFlower, 64, 64),
        .backPicYOffset = 2,
        LEARNSETS(FloetteEternalFlower),
    },

#define FLORGES_MISC_INFO(Form, iconPal)                                        \
        .baseHP        = 78,                                                    \
        .baseAttack    = 65,                                                    \
        .baseDefense   = 68,                                                    \
        .baseSpeed     = 75,                                                    \
        .baseSpAttack  = 112,                                                   \
        .baseSpDefense = 154,                                                   \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                    \
        .catchRate = 45,                                                        \
        .expYield = 248,                                                        \
        .evYield_SpDefense = 3,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },                      \
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS },  \
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .speciesName = _("Florges"),                                            \
        .cryId = CRY_FLORGES,                                                   \
        .natDexNum = NATIONAL_DEX_FLORGES,                                      \
        .categoryName = _("Garden"),                                            \
        .height = 11,                                                           \
        .weight = 100,                                                          \
        .pokemonScale = 320,                                                    \
        .pokemonOffset = 7,                                                     \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        FRONT_PIC(Florges, 64, 64),                                             \
        .frontPicYOffset = 0,                                                   \
        .frontAnimFrames = sAnims_Florges,                                      \
        .frontAnimId = ANIM_V_SLIDE_SLOW,                                       \
        BACK_PIC(Florges, 64, 48),                                              \
        .backPicYOffset = 9,                                                    \
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,                            \
        PALETTES(Florges##Form##Flower),                                         \
        ICON(Florges##Form##Flower, iconPal),                                   \
        .footprint = gMonFootprint_Florges,                                     \
        LEARNSETS(Florges),                                                     \
        .formSpeciesIdTable = sFlorgesFormSpeciesIdTable

    [SPECIES_FLORGES_RED_FLOWER] =
    {
        FLORGES_MISC_INFO(Red, 0),
        .description = COMPOUND_STRING(
            "This Pokémon creates an\n"
            "impressive flower garden in its territory. It\n"
            "draws forth the power of the red\n"
            "flowers around its neck."),
    },
    [SPECIES_FLORGES_YELLOW_FLOWER] =
    {
        FLORGES_MISC_INFO(Yellow, 1),
        .description = COMPOUND_STRING(
            "This Pokémon battles by drawing\n"
            "forth the power of yellow flowers. It\n"
            "ruthlessly punishes anyone who\n"
            "tramples on flowering plants."),
    },
    [SPECIES_FLORGES_ORANGE_FLOWER] =
    {
        FLORGES_MISC_INFO(Orange, 0),
        .description = COMPOUND_STRING(
            "In times long past, castle\n"
            "governors would lovingly raise Florges to\n"
            "care for their castles' exquisite\n"
            "gardens."),
    },
    [SPECIES_FLORGES_BLUE_FLOWER] =
    {
        FLORGES_MISC_INFO(Blue, 0),
        .description = COMPOUND_STRING(
            "Blue pigments were tremendously\n"
            "expensive in the past, so paintings\n"
            "of blue Florges are highly valuable."),
    },
    [SPECIES_FLORGES_WHITE_FLOWER] =
    {
        FLORGES_MISC_INFO(White, 0),
        .description = COMPOUND_STRING(
            "A flower garden made by a white-\n"
            "flowered Florges will be beautifully\n"
            "decorated with flowering plants of\n"
            "many different colors."),
    },
#endif //P_FAMILY_FLABEBE

#if P_FAMILY_SKIDDO
    [SPECIES_SKIDDO] =
    {
        .baseHP        = 66,
        .baseAttack    = 65,
        .baseDefense   = 48,
        .baseSpeed     = 52,
        .baseSpAttack  = 62,
        .baseSpDefense = 57,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 200,
        .expYield = 70,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_NONE, ABILITY_GRASS_PELT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Skiddo"),
        .cryId = CRY_SKIDDO,
        .natDexNum = NATIONAL_DEX_SKIDDO,
        .categoryName = _("Mount"),
        .height = 9,
        .weight = 310,
        .description = COMPOUND_STRING(
            "If it has sunshine and water, it doesn't\n"
            "need to eat, because it can generate\n"
            "energy from the leaves on its back.\n"
            "It has a placid disposition."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Skiddo, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Skiddo,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Skiddo, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Skiddo),
        ICON(Skiddo, 1),
        .footprint = gMonFootprint_Skiddo,
        LEARNSETS(Skiddo),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_GOGOAT}),
    },

    [SPECIES_GOGOAT] =
    {
        .baseHP        = 123,
        .baseAttack    = 100,
        .baseDefense   = 62,
        .baseSpeed     = 68,
        .baseSpAttack  = 97,
        .baseSpDefense = 81,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 186,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_NONE, ABILITY_GRASS_PELT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Gogoat"),
        .cryId = CRY_GOGOAT,
        .natDexNum = NATIONAL_DEX_GOGOAT,
        .categoryName = _("Mount"),
        .height = 17,
        .weight = 910,
        .description = COMPOUND_STRING(
            "It can tell how its trainer is feeling by\n"
            "subtle shifts in the grip on its horns. This\n"
            "empathetic sense lets them run as if one\n"
            "being. They inhabit mountainous regions."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Gogoat, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Gogoat,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Gogoat, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Gogoat),
        ICON(Gogoat, 1),
        .footprint = gMonFootprint_Gogoat,
        LEARNSETS(Gogoat),
    },
#endif //P_FAMILY_SKIDDO

#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] =
    {
        .baseHP        = 67,
        .baseAttack    = 82,
        .baseDefense   = 62,
        .baseSpeed     = 43,
        .baseSpAttack  = 46,
        .baseSpDefense = 48,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 220,
        .expYield = 70,
        .evYield_Attack = 1,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_IRON_FIST, ABILITY_MOLD_BREAKER, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Pancham"),
        .cryId = CRY_PANCHAM,
        .natDexNum = NATIONAL_DEX_PANCHAM,
        .categoryName = _("Playful"),
        .height = 6,
        .weight = 80,
        .description = COMPOUND_STRING(
            "There's no point to the leaf in its mouth,\n"
            "aside from an effort to look cool. It's\n"
            "mischievous, so it's not well suited to\n"
            "inexperienced Trainers."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pancham, 32, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Pancham,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Pancham, 48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Pancham),
        ICON(Pancham, 1),
        .footprint = gMonFootprint_Pancham,
        LEARNSETS(Pancham),
        .evolutions = EVOLUTION({EVO_LEVEL_DARK_TYPE_MON_IN_PARTY, 32, SPECIES_PANGORO}),
    },

    [SPECIES_PANGORO] =
    {
        .baseHP        = 95,
        .baseAttack    = 124,
        .baseDefense   = 78,
        .baseSpeed     = 58,
        .baseSpAttack  = 69,
        .baseSpDefense = 71,
        .types = { TYPE_FIGHTING, TYPE_DARK },
        .catchRate = 65,
        .expYield = 173,
        .evYield_Attack = 2,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_IRON_FIST, ABILITY_MOLD_BREAKER, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Pangoro"),
        .cryId = CRY_PANGORO,
        .natDexNum = NATIONAL_DEX_PANGORO,
        .categoryName = _("Daunting"),
        .height = 21,
        .weight = 1360,
        .description = COMPOUND_STRING(
            "It boasts superb physical strength.\n"
            "Those who wish to become Pangoro's\n"
            "Trainer have no choice but to converse\n"
            "with their fists."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Pangoro, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Pangoro,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Pangoro, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Pangoro),
        ICON(Pangoro, 1),
        .footprint = gMonFootprint_Pangoro,
        LEARNSETS(Pangoro),
    },
#endif //P_FAMILY_PANCHAM

#if P_FAMILY_FURFROU
#define FURFROU_MISC_INFO                                   \
        .baseHP        = 75,                                \
        .baseAttack    = 80,                                \
        .baseDefense   = 60,                                \
        .baseSpeed     = 102,                               \
        .baseSpAttack  = 65,                                \
        .baseSpDefense = 90,                                \
        .types = { TYPE_NORMAL, TYPE_NORMAL },              \
        .catchRate = 160,                                   \
        .expYield = 165,                                    \
        .evYield_Speed = 1,                                 \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .abilities = { ABILITY_FUR_COAT, ABILITY_NONE },    \
        .bodyColor = BODY_COLOR_WHITE,                      \
        .speciesName = _("Furfrou"),                        \
        .cryId = CRY_FURFROU,                               \
        .natDexNum = NATIONAL_DEX_FURFROU,                  \
        .categoryName = _("Poodle"),                        \
        .height = 12,                                       \
        .weight = 280,                                      \
        .description = gFurfrouPokedexText,                 \
        .pokemonScale = 282,                                \
        .pokemonOffset = 4,                                 \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .frontAnimFrames = sAnims_Furfrou,                  \
        .frontAnimId = ANIM_H_SLIDE,                        \
        .backAnimId = BACK_ANIM_V_STRETCH,                  \
        .footprint = gMonFootprint_Furfrou,                 \
        LEARNSETS(Furfrou),                                 \
        .formSpeciesIdTable = sFurfrouFormSpeciesIdTable

    [SPECIES_FURFROU_NATURAL] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouNatural, 48, 64),
        .frontPicYOffset = 3,
        BACK_PIC(FurfrouNatural, 56, 64),
        .backPicYOffset = 0,
        PALETTES(FurfrouNatural),
        ICON(FurfrouNatural, 0),
    },
    [SPECIES_FURFROU_HEART_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouHeartTrim, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouHeartTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouHeartTrim),
        ICON(FurfrouHeartTrim, 0),
    },
    [SPECIES_FURFROU_STAR_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouStarTrim, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouStarTrim, 64, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouStarTrim),
        ICON(FurfrouStarTrim, 0),
    },
    [SPECIES_FURFROU_DIAMOND_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouDiamondTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouDiamondTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouDiamondTrim),
        ICON(FurfrouDiamondTrim, 0),
    },
    [SPECIES_FURFROU_DEBUTANTE_TRIM] =
    {
        FURFROU_MISC_INFO,
        .noFlip = TRUE,
        FRONT_PIC(FurfrouDebutanteTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouDebutanteTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouDebutanteTrim),
        ICON(FurfrouDebutanteTrim, 2),
    },
    [SPECIES_FURFROU_MATRON_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouMatronTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouMatronTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouMatronTrim),
        ICON(FurfrouMatronTrim, 2),
    },
    [SPECIES_FURFROU_DANDY_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouDandyTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouDandyTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouDandyTrim),
        ICON(FurfrouDandyTrim, 1),
    },
    [SPECIES_FURFROU_LA_REINE_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouLaReineTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouLaReineTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouLaReineTrim),
        ICON(FurfrouLaReineTrim, 0),
    },
    [SPECIES_FURFROU_KABUKI_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouKabukiTrim, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouKabukiTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouKabukiTrim),
        ICON(FurfrouKabukiTrim, 0),
    },
    [SPECIES_FURFROU_PHARAOH_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouPharaohTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouPharaohTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouPharaohTrim),
        ICON(FurfrouPharaohTrim, 0),
    },
#endif //P_FAMILY_FURFROU

#if P_FAMILY_ESPURR
    [SPECIES_ESPURR] =
    {
        .baseHP        = 62,
        .baseAttack    = 48,
        .baseDefense   = 54,
        .baseSpeed     = 68,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 190,
        .expYield = 71,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_INFILTRATOR, ABILITY_OWN_TEMPO },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Espurr"),
        .cryId = CRY_ESPURR,
        .natDexNum = NATIONAL_DEX_ESPURR,
        .categoryName = _("Restraint"),
        .height = 3,
        .weight = 35,
        .description = COMPOUND_STRING(
            "It has enough psychic energy to blast\n"
            "everything within 300 feet of itself.\n"
            "The organ that emits its intense psychic\n"
            "power is sheltered by its ears."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Espurr, 32, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Espurr,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Espurr, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Espurr),
        ICON(Espurr, 2),
        .footprint = gMonFootprint_Espurr,
        LEARNSETS(Espurr),
        .evolutions = EVOLUTION({EVO_LEVEL_MALE, 25, SPECIES_MEOWSTIC_MALE},
                                {EVO_LEVEL_FEMALE, 25, SPECIES_MEOWSTIC_FEMALE}),
    },

#define MEOWSTIC_MISC_INFO                                  \
        .baseHP        = 74,                                \
        .baseAttack    = 48,                                \
        .baseDefense   = 76,                                \
        .baseSpeed     = 104,                               \
        .baseSpAttack  = 83,                                \
        .baseSpDefense = 81,                                \
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },            \
        .catchRate = 75,                                    \
        .expYield = 163,                                    \
        .evYield_Speed = 2,                                 \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .speciesName = _("Meowstic"),                       \
        .cryId = CRY_MEOWSTIC,                              \
        .natDexNum = NATIONAL_DEX_MEOWSTIC,                 \
        .categoryName = _("Constraint"),                    \
        .height = 6,                                        \
        .weight = 85,                                       \
        .pokemonScale = 422,                                \
        .pokemonOffset = 12,                                \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .frontAnimFrames = sAnims_Meowstic,                 \
        .frontAnimId = ANIM_GROW_VIBRATE,                   \
        .backPicYOffset = 9,                                \
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,          \
        .footprint = gMonFootprint_Meowstic,                \
        .formSpeciesIdTable = sMeowsticFormSpeciesIdTable

    [SPECIES_MEOWSTIC_MALE] =
    {
        MEOWSTIC_MISC_INFO,
        .genderRatio = MON_MALE,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_INFILTRATOR, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_BLUE,
        .description = COMPOUND_STRING(
            "The defensive instinct of the\n"
            "males is strong. It's when they're\n"
            "protecting themselves or their partners\n"
            "that they unleash their full power."),
        FRONT_PIC(MeowsticMale, 48, 64),
        .frontPicYOffset = 3,
        BACK_PIC(MeowsticMale, 64, 64),
        PALETTES(MeowsticMale),
        ICON(MeowsticMale, 0),
        LEARNSETS(MeowsticMale),
    },

    [SPECIES_MEOWSTIC_FEMALE] =
    {
        MEOWSTIC_MISC_INFO,
        .genderRatio = MON_FEMALE,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_INFILTRATOR, ABILITY_COMPETITIVE },
        .bodyColor = BODY_COLOR_WHITE,
        .description = COMPOUND_STRING(
            "Females are a bit more selfish and\n"
            "aggressive than males. If they\n"
            "don't get what they want, they will\n"
            "torment you with their psychic abilities."),
        FRONT_PIC(MeowsticFemale, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(MeowsticFemale, 48, 64),
        PALETTES(MeowsticFemale),
        ICON(MeowsticFemale, 0),
        LEARNSETS(MeowsticFemale),
    },
#endif //P_FAMILY_ESPURR

#if P_FAMILY_HONEDGE
    [SPECIES_HONEDGE] =
    {
        .baseHP        = 45,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 28,
        .baseSpAttack  = 35,
        .baseSpDefense = 37,
        .types = { TYPE_STEEL, TYPE_GHOST },
        .catchRate = 180,
        .expYield = 65,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Honedge"),
        .cryId = CRY_HONEDGE,
        .natDexNum = NATIONAL_DEX_HONEDGE,
        .categoryName = _("Sword"),
        .height = 8,
        .weight = 20,
        .description = COMPOUND_STRING(
            "If anyone dares to grab its hilt, it\n"
            "wraps a blue cloth around that person's\n"
            "arm and drains that person's life\n"
            "energy completely."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Honedge, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Honedge,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 4,
        BACK_PIC(Honedge, 48, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Honedge),
        ICON(Honedge, 2),
        .footprint = gMonFootprint_Honedge,
        LEARNSETS(Honedge),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_DOUBLADE}),
    },

    [SPECIES_DOUBLADE] =
    {
        .baseHP        = 59,
        .baseAttack    = 110,
        .baseDefense   = 150,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 49,
        .types = { TYPE_STEEL, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 157,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Doublade"),
        .cryId = CRY_DOUBLADE,
        .natDexNum = NATIONAL_DEX_DOUBLADE,
        .categoryName = _("Sword"),
        .height = 8,
        .weight = 45,
        .description = COMPOUND_STRING(
            "When Honedge evolves, it divides into\n"
            "two swords. The complex attack patterns\n"
            "of its two swords are unstoppable, even\n"
            "against those skilled at swordplay."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Doublade, 64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Doublade,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 5,
        BACK_PIC(Doublade, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Doublade),
        ICON(Doublade, 2),
        .footprint = gMonFootprint_Doublade,
        LEARNSETS(Doublade),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_AEGISLASH_SHIELD}),
    },

#define AEGISLASH_MISC_INFO                                     \
        .types = { TYPE_STEEL, TYPE_GHOST },                    \
        .catchRate = 45,                                        \
        .expYield = 234,                                        \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },  \
        .abilities = { ABILITY_STANCE_CHANGE, ABILITY_NONE },   \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .speciesName = _("Aegislash"),                          \
        .cryId = CRY_AEGISLASH,                                 \
        .natDexNum = NATIONAL_DEX_AEGISLASH,                    \
        .categoryName = _("Royal Sword"),                       \
        .height = 17,                                           \
        .weight = 530,                                          \
        .pokemonScale = 259,                                    \
        .pokemonOffset = 0,                                     \
        .trainerScale = 290,                                    \
        .trainerOffset = 1,                                     \
        .footprint = gMonFootprint_Aegislash,                   \
        LEARNSETS(Aegislash),                                   \
        .formSpeciesIdTable = sAegislashFormSpeciesIdTable,     \
        .formChangeTable = sAegislashFormChangeTable

#define AEGISLASH_MAIN_STAT (P_UPDATED_STATS >= GEN_8 ? 140 : 150)

    [SPECIES_AEGISLASH_SHIELD] =
    {
        AEGISLASH_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = AEGISLASH_MAIN_STAT,
        .baseSpeed     = 60,
        .baseSpAttack  = 50,
        .baseSpDefense = AEGISLASH_MAIN_STAT,
        .evYield_Defense = 2,
        .evYield_SpDefense = 1,
        .description = COMPOUND_STRING(
            "In this defensive stance,\n"
            "Aegislash uses its steel body and a force\n"
            "field of spectral power to reduce the\n"
            "damage of any attack."),
        FRONT_PIC(AegislashShield, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_AegislashShield,
        .frontAnimId = ANIM_H_VIBRATE,
        .enemyMonElevation = 3,
        BACK_PIC(AegislashShield, 64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(AegislashShield),
        ICON(AegislashShield, 2),
    },

    [SPECIES_AEGISLASH_BLADE] =
    {
        AEGISLASH_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = AEGISLASH_MAIN_STAT,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = AEGISLASH_MAIN_STAT,
        .baseSpDefense = 50,
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .description = COMPOUND_STRING(
            "Once upon a time, a king with an\n"
            "Aegislash reigned over the land. His\n"
            "Pokémon eventually drained him of\n"
            "life, and his kingdom fell with him."),
        FRONT_PIC(AegislashBlade, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_AegislashBlade,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .enemyMonElevation = 3,
        BACK_PIC(AegislashBlade, 64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(AegislashBlade),
        ICON(AegislashBlade, 2),
    },
#endif //P_FAMILY_HONEDGE

#if P_FAMILY_SPRITZEE
    [SPECIES_SPRITZEE] =
    {
        .baseHP        = 78,
        .baseAttack    = 52,
        .baseDefense   = 60,
        .baseSpeed     = 23,
        .baseSpAttack  = 63,
        .baseSpDefense = 65,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 200,
        .expYield = 68,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HEALER, ABILITY_NONE, ABILITY_AROMA_VEIL },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Spritzee"),
        .cryId = CRY_SPRITZEE,
        .natDexNum = NATIONAL_DEX_SPRITZEE,
        .categoryName = _("Perfume"),
        .height = 2,
        .weight = 5,
        .description = COMPOUND_STRING(
            "In the past, rather than using perfume,\n"
            "royal ladies carried a Spritzee that would\n"
            "waft a fragrance they liked. Its fragrance\n"
            "changes depending on what it has eaten."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Spritzee, 48, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Spritzee,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 14,
        BACK_PIC(Spritzee, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Spritzee),
        ICON(Spritzee, 0),
        .footprint = gMonFootprint_Spritzee,
        LEARNSETS(Spritzee),
        .evolutions = EVOLUTION({EVO_TRADE_ITEM, ITEM_SACHET, SPECIES_AROMATISSE},
                                {EVO_ITEM, ITEM_SACHET, SPECIES_AROMATISSE}),
    },

    [SPECIES_AROMATISSE] =
    {
        .baseHP        = 101,
        .baseAttack    = 72,
        .baseDefense   = 72,
        .baseSpeed     = 29,
        .baseSpAttack  = 99,
        .baseSpDefense = 89,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 140,
        .expYield = 162,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HEALER, ABILITY_NONE, ABILITY_AROMA_VEIL },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Aromatisse"),
        .cryId = CRY_AROMATISSE,
        .natDexNum = NATIONAL_DEX_AROMATISSE,
        .categoryName = _("Fragrance"),
        .height = 8,
        .weight = 155,
        .description = COMPOUND_STRING(
            "Its scent is so overpowering that,\n"
            "unless a Trainer happens to really enjoy\n"
            "the smell, he or she will have a hard time\n"
            "walking alongside it."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Aromatisse, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Aromatisse,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Aromatisse, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Aromatisse),
        ICON(Aromatisse, 0),
        .footprint = gMonFootprint_Aromatisse,
        LEARNSETS(Aromatisse),
    },
#endif //P_FAMILY_SPRITZEE

#if P_FAMILY_SWIRLIX
    [SPECIES_SWIRLIX] =
    {
        .baseHP        = 62,
        .baseAttack    = 48,
        .baseDefense   = 66,
        .baseSpeed     = 49,
        .baseSpAttack  = 59,
        .baseSpDefense = 57,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 200,
        .expYield = 68,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Swirlix"),
        .cryId = CRY_SWIRLIX,
        .natDexNum = NATIONAL_DEX_SWIRLIX,
        .categoryName = _("Cotton Candy"),
        .height = 4,
        .weight = 35,
        .description = COMPOUND_STRING(
            "Because it eats nothing but sweets, its\n"
            "fur is as sticky sweet as cotton candy.\n"
            "To entangle its opponents in battle, it\n"
            "extrudes sticky white threads."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swirlix, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Swirlix,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Swirlix, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SPRING,
        PALETTES(Swirlix),
        ICON(Swirlix, 1),
        .footprint = gMonFootprint_Swirlix,
        LEARNSETS(Swirlix),
        .evolutions = EVOLUTION({EVO_TRADE_ITEM, ITEM_WHIPPED_DREAM, SPECIES_SLURPUFF},
                                {EVO_ITEM, ITEM_WHIPPED_DREAM, SPECIES_SLURPUFF}),
    },

    [SPECIES_SLURPUFF] =
    {
        .baseHP        = 82,
        .baseAttack    = 80,
        .baseDefense   = 86,
        .baseSpeed     = 72,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 140,
        .expYield = 168,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Slurpuff"),
        .cryId = CRY_SLURPUFF,
        .natDexNum = NATIONAL_DEX_SLURPUFF,
        .categoryName = _("Meringue"),
        .height = 8,
        .weight = 50,
        .description = COMPOUND_STRING(
            "Slurpuff can distinguish even the\n"
            "faintest of scents. It puts its sensitive\n"
            "sense of smell to use by helping pastry\n"
            "chefs in their work."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Slurpuff, 48, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Slurpuff,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Slurpuff, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Slurpuff),
        ICON(Slurpuff, 1),
        .footprint = gMonFootprint_Slurpuff,
        LEARNSETS(Slurpuff),
    },
#endif //P_FAMILY_SWIRLIX

#if P_FAMILY_INKAY
    [SPECIES_INKAY] =
    {
        .baseHP        = 53,
        .baseAttack    = 54,
        .baseDefense   = 53,
        .baseSpeed     = 45,
        .baseSpAttack  = 37,
        .baseSpDefense = 46,
        .types = { TYPE_DARK, TYPE_PSYCHIC },
        .catchRate = 190,
        .expYield = 58,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_CONTRARY, ABILITY_SUCTION_CUPS, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Inkay"),
        .cryId = CRY_INKAY,
        .natDexNum = NATIONAL_DEX_INKAY,
        .categoryName = _("Revolving"),
        .height = 4,
        .weight = 35,
        .description = COMPOUND_STRING(
            "It flashes the light-emitting spots on its\n"
            "body, which drains its opponent's will\n"
            "to fight. It takes the opportunity to\n"
            "scuttle away and hide."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Inkay, 48, 48),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Inkay,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 14,
        BACK_PIC(Inkay, 56, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Inkay),
        ICON(Inkay, 0),
        .footprint = gMonFootprint_Inkay,
        LEARNSETS(Inkay),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_MALAMAR}),
    },

    [SPECIES_MALAMAR] =
    {
        .baseHP        = 86,
        .baseAttack    = 92,
        .baseDefense   = 88,
        .baseSpeed     = 73,
        .baseSpAttack  = 68,
        .baseSpDefense = 75,
        .types = { TYPE_DARK, TYPE_PSYCHIC },
        .catchRate = 80,
        .expYield = 169,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_CONTRARY, ABILITY_SUCTION_CUPS, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Malamar"),
        .cryId = CRY_MALAMAR,
        .natDexNum = NATIONAL_DEX_MALAMAR,
        .categoryName = _("Overturning"),
        .height = 15,
        .weight = 470,
        .description = COMPOUND_STRING(
            "It lures prey close with hypnotic motions,\n"
            "then wraps its tentacles around it before\n"
            "finishing it off with digestive fluids. It\n"
            "forces others to do whatever it wants."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Malamar, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Malamar,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Malamar, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Malamar),
        ICON(Malamar, 2),
        .footprint = gMonFootprint_Malamar,
        LEARNSETS(Malamar),
    },
#endif //P_FAMILY_INKAY

#if P_FAMILY_BINACLE
    [SPECIES_BINACLE] =
    {
        .baseHP        = 42,
        .baseAttack    = 52,
        .baseDefense   = 67,
        .baseSpeed     = 50,
        .baseSpAttack  = 39,
        .baseSpDefense = 56,
        .types = { TYPE_ROCK, TYPE_WATER },
        .catchRate = 120,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_SNIPER, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Binacle"),
        .cryId = CRY_BINACLE,
        .natDexNum = NATIONAL_DEX_BINACLE,
        .categoryName = _("Two-Handed"),
        .height = 5,
        .weight = 310,
        .description = COMPOUND_STRING(
            "They stretch and then contract, yanking\n"
            "their rocks along with them in bold hops.\n"
            "They eat seaweed that washes up on\n"
            "the shoreline."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Binacle, 48, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Binacle,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Binacle, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Binacle),
        ICON(Binacle, 2),
        .footprint = gMonFootprint_Binacle,
        LEARNSETS(Binacle),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_BARBARACLE}),
    },

    [SPECIES_BARBARACLE] =
    {
        .baseHP        = 72,
        .baseAttack    = 105,
        .baseDefense   = 115,
        .baseSpeed     = 68,
        .baseSpAttack  = 54,
        .baseSpDefense = 86,
        .types = { TYPE_ROCK, TYPE_WATER },
        .catchRate = 45,
        .expYield = 175,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_SNIPER, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Barbaracle"),
        .cryId = CRY_BARBARACLE,
        .natDexNum = NATIONAL_DEX_BARBARACLE,
        .categoryName = _("Collective"),
        .height = 13,
        .weight = 960,
        .description = COMPOUND_STRING(
            "Barbaracle's legs and hands have minds\n"
            "of their own, and they will move\n"
            "independently. But they usually follow\n"
            "the head's orders."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Barbaracle, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Barbaracle,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Barbaracle, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Barbaracle),
        ICON(Barbaracle, 2),
        .footprint = gMonFootprint_Barbaracle,
        LEARNSETS(Barbaracle),
    },
#endif //P_FAMILY_BINACLE

#if P_FAMILY_SKRELP
    [SPECIES_SKRELP] =
    {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 30,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = { TYPE_POISON, TYPE_WATER },
        .catchRate = 225,
        .expYield = 64,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_POISON_POINT, ABILITY_POISON_TOUCH, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Skrelp"),
        .cryId = CRY_SKRELP,
        .natDexNum = NATIONAL_DEX_SKRELP,
        .categoryName = _("Mock Kelp"),
        .height = 5,
        .weight = 73,
        .description = COMPOUND_STRING(
            "Camouflaged as rotten kelp, it hides\n"
            "from foes while storing up power for its\n"
            "evolution. They spray liquid poison on\n"
            "prey that approach unawares."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Skrelp, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Skrelp,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        BACK_PIC(Skrelp, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Skrelp),
        ICON(Skrelp, 2),
        .footprint = gMonFootprint_Skrelp,
        LEARNSETS(Skrelp),
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_DRAGALGE}),
    },

    [SPECIES_DRAGALGE] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 90,
        .baseSpeed     = 44,
        .baseSpAttack  = 97,
        .baseSpDefense = 123,
        .types = { TYPE_POISON, TYPE_DRAGON },
        .catchRate = 55,
        .expYield = 173,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_POISON_POINT, ABILITY_POISON_TOUCH, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Dragalge"),
        .cryId = CRY_DRAGALGE,
        .natDexNum = NATIONAL_DEX_DRAGALGE,
        .categoryName = _("Mock Kelp"),
        .height = 18,
        .weight = 815,
        .description = COMPOUND_STRING(
            "Their poison is strong enough to eat\n"
            "through the hull of a tanker. Tales are\n"
            "told of ships that wander into seas where\n"
            "Dragalge live, never to return."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Dragalge, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Dragalge,
        .frontAnimId = ANIM_FRONT_FLIP,
        BACK_PIC(Dragalge, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Dragalge),
        ICON(Dragalge, 5),
        .footprint = gMonFootprint_Dragalge,
        LEARNSETS(Dragalge),
    },
#endif //P_FAMILY_SKRELP

#if P_FAMILY_CLAUNCHER
    [SPECIES_CLAUNCHER] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 62,
        .baseSpeed     = 44,
        .baseSpAttack  = 58,
        .baseSpDefense = 63,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 225,
        .expYield = 66,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_MEGA_LAUNCHER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Clauncher"),
        .cryId = CRY_CLAUNCHER,
        .natDexNum = NATIONAL_DEX_CLAUNCHER,
        .categoryName = _("Water Gun"),
        .height = 5,
        .weight = 83,
        .description = COMPOUND_STRING(
            "Through controlled expulsions of internal\n"
            "gas, it can expel water like a pistol shot.\n"
            "At close distances, it can even shatter\n"
            "large rocks."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Clauncher, 56, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Clauncher,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(Clauncher, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Clauncher),
        ICON(Clauncher, 0),
        .footprint = gMonFootprint_Clauncher,
        LEARNSETS(Clauncher),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_CLAWITZER}),
    },

    [SPECIES_CLAWITZER] =
    {
        .baseHP        = 71,
        .baseAttack    = 73,
        .baseDefense   = 88,
        .baseSpeed     = 59,
        .baseSpAttack  = 120,
        .baseSpDefense = 89,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 55,
        .expYield = 100,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_MEGA_LAUNCHER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Clawitzer"),
        .cryId = CRY_CLAWITZER,
        .natDexNum = NATIONAL_DEX_CLAWITZER,
        .categoryName = _("Howitzer"),
        .height = 13,
        .weight = 353,
        .description = COMPOUND_STRING(
            "By expelling water from the nozzle in the\n"
            "back of its enormous claw, it can move\n"
            "at a speed of 60 knots. They launch\n"
            "cannonballs made of water."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Clawitzer, 64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Clawitzer,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        BACK_PIC(Clawitzer, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Clawitzer),
        ICON(Clawitzer, 0),
        .footprint = gMonFootprint_Clawitzer,
        LEARNSETS(Clawitzer),
    },
#endif //P_FAMILY_CLAUNCHER

#if P_FAMILY_HELIOPTILE
    [SPECIES_HELIOPTILE] =
    {
        .baseHP        = 44,
        .baseAttack    = 38,
        .baseDefense   = 33,
        .baseSpeed     = 70,
        .baseSpAttack  = 61,
        .baseSpDefense = 43,
        .types = { TYPE_ELECTRIC, TYPE_NORMAL },
        .catchRate = 190,
        .expYield = 58,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_DRY_SKIN, ABILITY_SAND_VEIL, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Helioptile"),
        .cryId = CRY_HELIOPTILE,
        .natDexNum = NATIONAL_DEX_HELIOPTILE,
        .categoryName = _("Generator"),
        .height = 5,
        .weight = 60,
        .description = COMPOUND_STRING(
            "They make their home in deserts.\n"
            "They can generate their own energy from\n"
            "basking in the sun, so eating food is not\n"
            "a requirement."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Helioptile, 40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Helioptile,
        .frontAnimId = ANIM_GLOW_YELLOW,
        BACK_PIC(Helioptile, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Helioptile),
        ICON(Helioptile, 2),
        .footprint = gMonFootprint_Helioptile,
        LEARNSETS(Helioptile),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_HELIOLISK}),
    },

    [SPECIES_HELIOLISK] =
    {
        .baseHP        = 62,
        .baseAttack    = 55,
        .baseDefense   = 52,
        .baseSpeed     = 109,
        .baseSpAttack  = 109,
        .baseSpDefense = 94,
        .types = { TYPE_ELECTRIC, TYPE_NORMAL },
        .catchRate = 75,
        .expYield = 168,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_DRY_SKIN, ABILITY_SAND_VEIL, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Heliolisk"),
        .cryId = CRY_HELIOLISK,
        .natDexNum = NATIONAL_DEX_HELIOLISK,
        .categoryName = _("Generator"),
        .height = 10,
        .weight = 210,
        .description = COMPOUND_STRING(
            "A single Heliolisk can generate sufficient\n"
            "electricity to power a skyscraper. It can\n"
            "stimulate its muscles with electricity,\n"
            "boosting the strength in its legs."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Heliolisk, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Heliolisk,
        .frontAnimId = ANIM_RAPID_H_HOPS,
        BACK_PIC(Heliolisk, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Heliolisk),
        ICON(Heliolisk, 2),
        .footprint = gMonFootprint_Heliolisk,
        LEARNSETS(Heliolisk),
    },
#endif //P_FAMILY_HELIOPTILE

#if P_FAMILY_TYRUNT
    [SPECIES_TYRUNT] =
    {
        .baseHP        = 58,
        .baseAttack    = 89,
        .baseDefense   = 77,
        .baseSpeed     = 48,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 72,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_NONE, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Tyrunt"),
        .cryId = CRY_TYRUNT,
        .natDexNum = NATIONAL_DEX_TYRUNT,
        .categoryName = _("Royal Heir"),
        .height = 8,
        .weight = 260,
        .description = COMPOUND_STRING(
            "Its immense jaws have enough destructive\n"
            "force that it can chew up a car. If\n"
            "something happens that it doesn't like,\n"
            "it throws a tantrum and runs wild."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Tyrunt, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Tyrunt,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Tyrunt, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Tyrunt),
        ICON(Tyrunt, 2),
        .footprint = gMonFootprint_Tyrunt,
        LEARNSETS(Tyrunt),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 39, SPECIES_TYRANTRUM}),
    },

    [SPECIES_TYRANTRUM] =
    {
        .baseHP        = 82,
        .baseAttack    = 121,
        .baseDefense   = 119,
        .baseSpeed     = 71,
        .baseSpAttack  = 69,
        .baseSpDefense = 59,
        .types = { TYPE_ROCK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 182,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_NONE, ABILITY_ROCK_HEAD },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Tyrantrum"),
        .cryId = CRY_TYRANTRUM,
        .natDexNum = NATIONAL_DEX_TYRANTRUM,
        .categoryName = _("Despot"),
        .height = 25,
        .weight = 2700,
        .description = COMPOUND_STRING(
            "Thanks to its gargantuan jaws, which could\n"
            "shred thick metal plates as if they were\n"
            "paper, it was invincible in the ancient\n"
            "world it once inhabited."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Tyrantrum, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Tyrantrum,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Tyrantrum, 64, 56),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Tyrantrum),
        ICON(Tyrantrum, 0),
        .footprint = gMonFootprint_Tyrantrum,
        LEARNSETS(Tyrantrum),
    },
#endif //P_FAMILY_TYRUNT

#if P_FAMILY_AMAURA
    [SPECIES_AMAURA] =
    {
        .baseHP        = 77,
        .baseAttack    = 59,
        .baseDefense   = 50,
        .baseSpeed     = 46,
        .baseSpAttack  = 67,
        .baseSpDefense = 63,
        .types = { TYPE_ROCK, TYPE_ICE },
        .catchRate = 45,
        .expYield = 72,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_REFRIGERATE, ABILITY_NONE, ABILITY_SNOW_WARNING },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Amaura"),
        .cryId = CRY_AMAURA,
        .natDexNum = NATIONAL_DEX_AMAURA,
        .categoryName = _("Tundra"),
        .height = 13,
        .weight = 252,
        .description = COMPOUND_STRING(
            "This ancient Pokémon was restored from\n"
            "part of its body that had been frozen in\n"
            "ice for over 100 million years. It lived in a\n"
            "cold land where there were no predators."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Amaura, 32, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Amaura,
        .frontAnimId = ANIM_CONCAVE_ARC_SMALL_TWICE,
        BACK_PIC(Amaura, 40, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Amaura),
        ICON(Amaura, 0),
        .footprint = gMonFootprint_Amaura,
        LEARNSETS(Amaura),
        .evolutions = EVOLUTION({EVO_LEVEL_NIGHT, 39, SPECIES_AURORUS}),
    },

    [SPECIES_AURORUS] =
    {
        .baseHP        = 123,
        .baseAttack    = 77,
        .baseDefense   = 72,
        .baseSpeed     = 58,
        .baseSpAttack  = 99,
        .baseSpDefense = 92,
        .types = { TYPE_ROCK, TYPE_ICE },
        .catchRate = 45,
        .expYield = 104,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_REFRIGERATE, ABILITY_NONE, ABILITY_SNOW_WARNING },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Aurorus"),
        .cryId = CRY_AURORUS,
        .natDexNum = NATIONAL_DEX_AURORUS,
        .categoryName = _("Tundra"),
        .height = 27,
        .weight = 2250,
        .description = COMPOUND_STRING(
            "Using the diamond-shaped crystals on its\n"
            "body it can instantly create a wall of ice\n"
            "to block an opponent's attack, or encase\n"
            "them in ice."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Aurorus, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Aurorus,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Aurorus, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Aurorus),
        ICON(Aurorus, 0),
        .footprint = gMonFootprint_Aurorus,
        LEARNSETS(Aurorus),
    },
#endif //P_FAMILY_AMAURA

#if P_FAMILY_HAWLUCHA
    [SPECIES_HAWLUCHA] =
    {
        .baseHP        = 78,
        .baseAttack    = 92,
        .baseDefense   = 75,
        .baseSpeed     = 118,
        .baseSpAttack  = 74,
        .baseSpDefense = 63,
        .types = { TYPE_FIGHTING, TYPE_FLYING },
        .catchRate = 100,
        .expYield = 175,
        .evYield_Attack = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_HUMAN_LIKE },
        #else
            .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        #endif
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Hawlucha"),
        .cryId = CRY_HAWLUCHA,
        .natDexNum = NATIONAL_DEX_HAWLUCHA,
        .categoryName = _("Wrestling"),
        .height = 8,
        .weight = 215,
        .description = COMPOUND_STRING(
            "With its wings, it controls its position in\n"
            "the air. Its proficient fighting skills\n"
            "enable it to keep up with big bruisers\n"
            "like Machamp and Hariyama."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Hawlucha, 64, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Hawlucha,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Hawlucha, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Hawlucha),
        ICON(Hawlucha, 0),
        .footprint = gMonFootprint_Hawlucha,
        LEARNSETS(Hawlucha),
    },
#endif //P_FAMILY_HAWLUCHA

#if P_FAMILY_DEDENNE
    [SPECIES_DEDENNE] =
    {
        .baseHP        = 67,
        .baseAttack    = 58,
        .baseDefense   = 57,
        .baseSpeed     = 101,
        .baseSpAttack  = 81,
        .baseSpDefense = 67,
        .types = { TYPE_ELECTRIC, TYPE_FAIRY },
        .catchRate = 180,
        .expYield = 151,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_CHEEK_POUCH, ABILITY_PICKUP, ABILITY_PLUS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Dedenne"),
        .cryId = CRY_DEDENNE,
        .natDexNum = NATIONAL_DEX_DEDENNE,
        .categoryName = _("Antenna"),
        .height = 2,
        .weight = 22,
        .description = COMPOUND_STRING(
            "Its whiskers serve as antennas.\n"
            "By sending and receiving electrical\n"
            "waves, it can communicate with others\n"
            "over vast distances."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dedenne, 64, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Dedenne,
        .frontAnimId = ANIM_GLOW_YELLOW,
        BACK_PIC(Dedenne, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Dedenne),
        ICON(Dedenne, 0),
        .footprint = gMonFootprint_Dedenne,
        LEARNSETS(Dedenne),
    },
#endif //P_FAMILY_DEDENNE

#if P_FAMILY_CARBINK
    [SPECIES_CARBINK] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 150,
        .types = { TYPE_ROCK, TYPE_FAIRY },
        .catchRate = 60,
        .expYield = 100,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Carbink"),
        .cryId = CRY_CARBINK,
        .natDexNum = NATIONAL_DEX_CARBINK,
        .categoryName = _("Jewel"),
        .height = 3,
        .weight = 57,
        .description = COMPOUND_STRING(
            "Born from the high temperatures and\n"
            "pressures deep underground, it defends\n"
            "itself by firing beams from the jewel part\n"
            "of its body."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Carbink, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Carbink,
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = 4,
        BACK_PIC(Carbink, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Carbink),
        ICON(Carbink, 2),
        .footprint = gMonFootprint_Carbink,
        LEARNSETS(Carbink),
    },
#endif //P_FAMILY_CARBINK

#if P_FAMILY_GOOMY
    [SPECIES_GOOMY] =
    {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 35,
        .baseSpeed     = 40,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 60,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_HYDRATION, ABILITY_GOOEY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Goomy"),
        .cryId = CRY_GOOMY,
        .natDexNum = NATIONAL_DEX_GOOMY,
        .categoryName = _("Soft Tissue"),
        .height = 3,
        .weight = 28,
        .description = COMPOUND_STRING(
            "Its source of protection is its slimy,\n"
            "germ-laden mucous membrane. Anyone\n"
            "who touches it will need some thorough\n"
            "hand-washing."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Goomy, 32, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Goomy,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Goomy, 48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SPRING,
        PALETTES(Goomy),
        ICON(Goomy, 5),
        .footprint = gMonFootprint_Goomy,
        LEARNSETS(Goomy),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_SLIGGOO},
                                {EVO_NONE, 0, SPECIES_SLIGGOO_HISUIAN}),
    },

#define SLIGGOO_MISC_INFO                                       \
        .catchRate = 45,                                        \
        .expYield = 158,                                        \
        .evYield_SpDefense = 2,                                 \
        .itemRare = ITEM_SHED_SHELL,                            \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = 35,                                       \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },    \
        .bodyColor = BODY_COLOR_PURPLE,                         \
        .speciesName = _("Sliggoo"),                            \
        .cryId = CRY_SLIGGOO,                                   \
        .natDexNum = NATIONAL_DEX_SLIGGOO,                      \
        .footprint = gMonFootprint_Sliggoo,                     \
        .formSpeciesIdTable = sSliggooFormSpeciesIdTable

    [SPECIES_SLIGGOO] =
    {
        SLIGGOO_MISC_INFO,
        .baseHP        = 68,
        .baseAttack    = 75,
        .baseDefense   = 53,
        .baseSpeed     = 60,
        .baseSpAttack  = 83,
        .baseSpDefense = 113,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_HYDRATION, ABILITY_GOOEY },
        .categoryName = _("Soft Tissue"),
        .height = 8,
        .weight = 175,
        .description = COMPOUND_STRING(
            "This Pokémon's mucous can dissolve\n"
            "anything. Toothless, it sprays mucous\n"
            "on its prey. Once they're nicely dissolved,\n"
            "it slurps them up."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Sliggoo, 32, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Sliggoo,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sliggoo, 48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Sliggoo),
        ICON(Sliggoo, 5),
        LEARNSETS(Sliggoo),
        .evolutions = EVOLUTION({EVO_LEVEL_RAIN, 50, SPECIES_GOODRA},
                                {EVO_LEVEL_FOG, 50, SPECIES_GOODRA}),
    },

#define GOODRA_MISC_INFO                                        \
        .catchRate = 45,                                        \
        .expYield = 270,                                        \
        .evYield_SpDefense = 3,                                 \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = 35,                                       \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },    \
        .bodyColor = BODY_COLOR_PURPLE,                         \
        .speciesName = _("Goodra"),                             \
        .cryId = CRY_GOODRA,                                    \
        .natDexNum = NATIONAL_DEX_GOODRA,                       \
        .footprint = gMonFootprint_Goodra,                      \
        .formSpeciesIdTable = sGoodraFormSpeciesIdTable

    [SPECIES_GOODRA] =
    {
        GOODRA_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 80,
        .baseSpAttack  = 110,
        .baseSpDefense = 150,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_HYDRATION, ABILITY_GOOEY },
        .categoryName = _("Dragon"),
        .height = 20,
        .weight = 1505,
        .description = COMPOUND_STRING(
            "It gets picked on because it's meek.\n"
            "But then, whoever teased it gets to feel\n"
            "the full force of its horns and a good\n"
            "swatting from its thick tail."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Goodra, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Goodra,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Goodra, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Goodra),
        ICON(Goodra, 5),
        LEARNSETS(Goodra),
    },

#if P_HISUIAN_FORMS
    [SPECIES_SLIGGOO_HISUIAN] =
    {
        SLIGGOO_MISC_INFO,
        .baseHP        = 58,
        .baseAttack    = 75,
        .baseDefense   = 83,
        .baseSpeed     = 40,
        .baseSpAttack  = 83,
        .baseSpDefense = 113,
        .types = { TYPE_DRAGON, TYPE_STEEL },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_SHELL_ARMOR, ABILITY_GOOEY },
        .categoryName = _("Snail"),
        .height = 7,
        .weight = 685,
        .description = COMPOUND_STRING(
            "A creature given to melancholy.\n"
            "Its metallic shell developed as a\n"
            "result of the mucus on its skin reacting\n"
            "with the iron in Hisui's water."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(SliggooHisuian, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SliggooHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(SliggooHisuian, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(SliggooHisuian),
        ICON(SliggooHisuian, 2),
        LEARNSETS(SliggooHisuian),
        .isHisuianForm = TRUE,
        .evolutions = EVOLUTION({EVO_LEVEL_RAIN, 50, SPECIES_GOODRA_HISUIAN},
                                {EVO_LEVEL_FOG, 50, SPECIES_GOODRA_HISUIAN}),
    },

    [SPECIES_GOODRA_HISUIAN] =
    {
        GOODRA_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 60,
        .baseSpAttack  = 110,
        .baseSpDefense = 150,
        .types = { TYPE_DRAGON, TYPE_STEEL },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_SHELL_ARMOR, ABILITY_GOOEY },
        .categoryName = _("Shell Bunker"),
        .height = 17,
        .weight = 3341,
        .description = COMPOUND_STRING(
            "It loathes solitude and is\n"
            "extremely clingy-it will fume and run riot if\n"
            "those dearest to it ever leave its\n"
            "side."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(GoodraHisuian, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_GoodraHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(GoodraHisuian, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(GoodraHisuian),
        ICON(GoodraHisuian, 2),
        LEARNSETS(GoodraHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_GOOMY

#if P_FAMILY_KLEFKI
    [SPECIES_KLEFKI] =
    {
        .baseHP        = 57,
        .baseAttack    = 80,
        .baseDefense   = 91,
        .baseSpeed     = 75,
        .baseSpAttack  = 80,
        .baseSpDefense = 87,
        .types = { TYPE_STEEL, TYPE_FAIRY },
        .catchRate = 75,
        .expYield = 165,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Klefki"),
        .cryId = CRY_KLEFKI,
        .natDexNum = NATIONAL_DEX_KLEFKI,
        .categoryName = _("Key Ring"),
        .height = 2,
        .weight = 30,
        .description = COMPOUND_STRING(
            "These key collectors threaten any\n"
            "attackers by fiercely jingling their keys\n"
            "at them. It will sneak into people's homes\n"
            "to steal their keys."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klefki, 40, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Klefki,
        .frontAnimId = ANIM_FOUR_PETAL,
        .enemyMonElevation = 5,
        BACK_PIC(Klefki, 56, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Klefki),
        ICON(Klefki, 0),
        .footprint = gMonFootprint_Klefki,
        LEARNSETS(Klefki),
    },
#endif //P_FAMILY_KLEFKI

#if P_FAMILY_PHANTUMP
    [SPECIES_PHANTUMP] =
    {
        .baseHP        = 43,
        .baseAttack    = 70,
        .baseDefense   = 48,
        .baseSpeed     = 38,
        .baseSpAttack  = 50,
        .baseSpDefense = 60,
        .types = { TYPE_GHOST, TYPE_GRASS },
        .catchRate = 120,
        .expYield = 62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_FRISK, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Phantump"),
        .cryId = CRY_PHANTUMP,
        .natDexNum = NATIONAL_DEX_PHANTUMP,
        .categoryName = _("Stump"),
        .height = 4,
        .weight = 70,
        .description = COMPOUND_STRING(
            "According to legend, medicine to cure\n"
            "any illness can be made by plucking the\n"
            "green leaves on its head, brewing them,\n"
            "and boiling down the liquid."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Phantump, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Phantump,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(Phantump, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Phantump),
        ICON(Phantump, 1),
        .footprint = gMonFootprint_Phantump,
        LEARNSETS(Phantump),
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_TREVENANT},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_TREVENANT}),
    },

    [SPECIES_TREVENANT] =
    {
        .baseHP        = 85,
        .baseAttack    = 110,
        .baseDefense   = 76,
        .baseSpeed     = 56,
        .baseSpAttack  = 65,
        .baseSpDefense = 82,
        .types = { TYPE_GHOST, TYPE_GRASS },
        .catchRate = 60,
        .expYield = 166,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_FRISK, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Trevenant"),
        .cryId = CRY_TREVENANT,
        .natDexNum = NATIONAL_DEX_TREVENANT,
        .categoryName = _("Elder Tree"),
        .height = 15,
        .weight = 710,
        .description = COMPOUND_STRING(
            "Through its roots, it exerts control over\n"
            "other trees. A deadly curse falls upon\n"
            "anyone cutting down trees in forests\n"
            "where Trevenant dwell."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Trevenant, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Trevenant,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Trevenant, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Trevenant),
        ICON(Trevenant, 1),
        .footprint = gMonFootprint_Trevenant,
        LEARNSETS(Trevenant),
    },
#endif //P_FAMILY_PHANTUMP

#if P_FAMILY_PUMPKABOO
#define PUMPKABOO_MISC_INFO                                                 \
        .types = { TYPE_GHOST, TYPE_GRASS },                                \
        .catchRate = 120,                                                   \
        .expYield = 67,                                                     \
        .evYield_Defense = 1,                                               \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },          \
        .abilities = { ABILITY_PICKUP, ABILITY_FRISK, ABILITY_INSOMNIA },   \
        .bodyColor = BODY_COLOR_BROWN,                                      \
        .speciesName = _("Pumpkaboo"),                                      \
        .natDexNum = NATIONAL_DEX_PUMPKABOO,                                \
        .categoryName = _("Pumpkin"),                                       \
        .frontAnimFrames = sAnims_Pumpkaboo,                                \
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,                                 \
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,                              \
        PALETTES(Pumpkaboo),                                                \
        ICON(Pumpkaboo, 2),                                                 \
        .footprint = gMonFootprint_Pumpkaboo,                               \
        LEARNSETS(Pumpkaboo),                                               \
        .formSpeciesIdTable = sPumpkabooFormSpeciesIdTable

    [SPECIES_PUMPKABOO_AVERAGE] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 49,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 51,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .cryId = CRY_PUMPKABOO,
        .height = 4,
        .weight = 50,
        .description = COMPOUND_STRING(
            "The light that streams out from\n"
            "the holes in the pumpkin can\n"
            "hypnotize and control the people and\n"
            "Pokémon that see it."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooAverage, 40, 40),
        .frontPicYOffset = 13,
        BACK_PIC(PumpkabooAverage, 56, 48),
        .backPicYOffset = 13,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_AVERAGE},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_AVERAGE}),
    },

    [SPECIES_PUMPKABOO_SMALL] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 44,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 56,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .cryId = CRY_PUMPKABOO,
        .height = 3,
        .weight = 35,
        .description = COMPOUND_STRING(
            "When taking spirits to the\n"
            "afterlife, small Pumpkaboo prefer the\n"
            "spirits of children to those of adults."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooSmall, 40, 40),
        .frontPicYOffset = 15,
        BACK_PIC(PumpkabooSmall, 56, 48),
        .backPicYOffset = 14,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_SMALL},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_SMALL}),
    },

    [SPECIES_PUMPKABOO_LARGE] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 54,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 46,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .cryId = CRY_PUMPKABOO,
        .height = 5,
        .weight = 75,
        .description = COMPOUND_STRING(
            "When taking spirits to the\n"
            "afterlife, large Pumpkaboo prefer the\n"
            "spirits of adults to those of children."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooLarge, 48, 48),
        .frontPicYOffset = 12,
        BACK_PIC(PumpkabooLarge, 56, 48),
        .backPicYOffset = 13,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_LARGE},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_LARGE}),
    },

    [SPECIES_PUMPKABOO_SUPER] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 59,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 41,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .itemCommon = ITEM_MIRACLE_SEED,
        .itemRare = ITEM_MIRACLE_SEED,
        .cryId = CRY_PUMPKABOO_SUPER,
        .height = 8,
        .weight = 150,
        .description = COMPOUND_STRING(
            "Supersized Pumpkaboo are very\n"
            "partial to the spirits of people who\n"
            "were of similarly superior proportions."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooSuper, 48, 48),
        .frontPicYOffset = 10,
        BACK_PIC(PumpkabooSuper, 56, 48),
        .backPicYOffset = 12,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_SUPER},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_SUPER}),
    },

#define GOURGEIST_MISC_INFO                                                 \
        .types = { TYPE_GHOST, TYPE_GRASS },                                \
        .catchRate = 60,                                                    \
        .expYield = 173,                                                    \
        .evYield_Defense = 2,                                               \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },          \
        .abilities = { ABILITY_PICKUP, ABILITY_FRISK, ABILITY_INSOMNIA },   \
        .bodyColor = BODY_COLOR_BROWN,                                      \
        .speciesName = _("Gourgeist"),                                      \
        .natDexNum = NATIONAL_DEX_GOURGEIST,                                \
        .categoryName = _("Pumpkin"),                                       \
        .frontAnimFrames = sAnims_Gourgeist,                                \
        .frontAnimId = ANIM_SHRINK_GROW,                                    \
        .backAnimId = BACK_ANIM_V_STRETCH,                                  \
        PALETTES(Gourgeist),                                                \
        ICON(Gourgeist, 2),                                                 \
        .footprint = gMonFootprint_Gourgeist,                               \
        LEARNSETS(Gourgeist),                                               \
        .formSpeciesIdTable = sGourgeistFormSpeciesIdTable

    [SPECIES_GOURGEIST_AVERAGE] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 122,
        .baseSpeed     = 84,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .cryId = CRY_GOURGEIST,
        .height = 9,
        .weight = 125,
        .description = COMPOUND_STRING(
            "Eerie cries emanate from its body\n"
            "in the dead of night. The sounds are\n"
            "said to be the wails of spirits who\n"
            "are suffering in the afterlife."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistAverage, 64, 64),
        .frontPicYOffset = 4,
        BACK_PIC(GourgeistAverage, 48, 64),
        .backPicYOffset = 3,
    },

    [SPECIES_GOURGEIST_SMALL] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 122,
        .baseSpeed     = 99,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .cryId = CRY_GOURGEIST,
        .height = 7,
        .weight = 95,
        .description = COMPOUND_STRING(
            "A small-sized Pumpkaboo evolves\n"
            "into a small-sized Gourgeist. Its\n"
            "bodily proportions also get passed on\n"
            "to its descendants."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistSmall, 56, 64),
        .frontPicYOffset = 5,
        BACK_PIC(GourgeistSmall, 48, 56),
        .backPicYOffset = 4,
    },

    [SPECIES_GOURGEIST_LARGE] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 122,
        .baseSpeed     = 69,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .cryId = CRY_GOURGEIST,
        .height = 11,
        .weight = 140,
        .description = COMPOUND_STRING(
            "A large-sized Pumpkaboo evolves\n"
            "into a large-sized Gourgeist. Its\n"
            "bodily proportions also get passed on\n"
            "to its descendants."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistLarge, 64, 64),
        .frontPicYOffset = 2,
        BACK_PIC(GourgeistLarge, 48, 64),
        .backPicYOffset = 2,
    },

    [SPECIES_GOURGEIST_SUPER] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 85,
        .baseAttack    = 100,
        .baseDefense   = 122,
        .baseSpeed     = 54,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .itemCommon = ITEM_MIRACLE_SEED,
        .itemRare = ITEM_MIRACLE_SEED,
        .cryId = CRY_GOURGEIST_SUPER,
        .height = 17,
        .weight = 390,
        .description = COMPOUND_STRING(
            "A supersized Pumpkaboo evolves\n"
            "into a supersized Gourgeist. Its\n"
            "bodily proportions also get passed on to\n"
            "its descendants."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistSuper, 64, 64),
        .frontPicYOffset = 0,
        BACK_PIC(GourgeistSuper, 56, 64),
        .backPicYOffset = 1,
    },
#endif //P_FAMILY_PUMPKABOO

#if P_FAMILY_BERGMITE
#if P_UPDATED_EGG_GROUPS >= GEN_8
    #define BERGMITE_EGG_GROUPS {EGG_GROUP_MONSTER, EGG_GROUP_MINERAL }
#else
    #define BERGMITE_EGG_GROUPS {EGG_GROUP_MONSTER, EGG_GROUP_MONSTER }
#endif

    [SPECIES_BERGMITE] =
    {
        .baseHP        = 55,
        .baseAttack    = 69,
        .baseDefense   = 85,
        .baseSpeed     = 28,
        .baseSpAttack  = 32,
        .baseSpDefense = 35,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = BERGMITE_EGG_GROUPS,
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_ICE_BODY, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Bergmite"),
        .cryId = CRY_BERGMITE,
        .natDexNum = NATIONAL_DEX_BERGMITE,
        .categoryName = _("Ice Chunk"),
        .height = 10,
        .weight = 995,
        .description = COMPOUND_STRING(
            "It blocks opponents' attacks with the ice\n"
            "that shields its body. It uses cold air to\n"
            "repair any cracks with new ice. They live\n"
            "in herds on snowy mountains."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Bergmite, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Bergmite,
        .frontAnimId = ANIM_LUNGE_GROW,
        BACK_PIC(Bergmite, 56, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Bergmite),
        ICON(Bergmite, 0),
        .footprint = gMonFootprint_Bergmite,
        LEARNSETS(Bergmite),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_AVALUGG},
                                {EVO_NONE, 0, SPECIES_AVALUGG_HISUIAN}),
    },

#define AVALUGG_MISC_INFO                               \
        .catchRate = 55,                                \
        .expYield = 180,                                \
        .evYield_Defense = 2,                           \
        .genderRatio = PERCENT_FEMALE(50),              \
        .eggCycles = 20,                                \
        .friendship = STANDARD_FRIENDSHIP,              \
        .growthRate = GROWTH_MEDIUM_FAST,               \
        .eggGroups = BERGMITE_EGG_GROUPS,               \
        .bodyColor = BODY_COLOR_BLUE,                   \
        .speciesName = _("Avalugg"),                    \
        .cryId = CRY_AVALUGG,                           \
        .natDexNum = NATIONAL_DEX_AVALUGG,              \
        .categoryName = _("Iceberg"),                   \
        .footprint = gMonFootprint_Avalugg,             \
        .formSpeciesIdTable = sAvaluggFormSpeciesIdTable

    [SPECIES_AVALUGG] =
    {
        AVALUGG_MISC_INFO,
        .baseHP        = 95,
        .baseAttack    = 117,
        .baseDefense   = 184,
        .baseSpeed     = 28,
        .baseSpAttack  = 44,
        .baseSpDefense = 46,
        .types = { TYPE_ICE, TYPE_ICE },
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_ICE_BODY, ABILITY_STURDY },
        .height = 20,
        .weight = 5050,
        .description = COMPOUND_STRING(
            "The way several Bergmite huddle on its\n"
            "back make it look like an aircraft carrier\n"
            "made of ice. Its cumbersome frame crushes\n"
            "anything that stands in its way.")
,
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Avalugg, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Avalugg,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Avalugg, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Avalugg),
        ICON(Avalugg, 0),
        LEARNSETS(Avalugg),
    },

#if P_HISUIAN_FORMS
    [SPECIES_AVALUGG_HISUIAN] =
    {
        AVALUGG_MISC_INFO,
        .baseHP        = 95,
        .baseAttack    = 127,
        .baseDefense   = 184,
        .baseSpeed     = 38,
        .baseSpAttack  = 34,
        .baseSpDefense = 36,
        .types = { TYPE_ICE, TYPE_ROCK },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_ICE_BODY, ABILITY_STURDY },
        .height = 14,
        .weight = 2624,
        .description = COMPOUND_STRING(
            "The armor of ice covering its lower\n"
            "jaw puts steel to shame and can\n"
            "shatter rocks with ease."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(AvaluggHisuian, 64, 48),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_AvaluggHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AvaluggHisuian, 64, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(AvaluggHisuian),
        ICON(AvaluggHisuian, 5),
        LEARNSETS(AvaluggHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_BERGMITE

#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 35,
        .baseSpeed     = 55,
        .baseSpAttack  = 45,
        .baseSpDefense = 40,
        .types = { TYPE_FLYING, TYPE_DRAGON },
        .catchRate = 190,
        .expYield = 49,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_DRAGON },
        #else
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        #endif
        .abilities = { ABILITY_FRISK, ABILITY_INFILTRATOR, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Noibat"),
        .cryId = CRY_NOIBAT,
        .natDexNum = NATIONAL_DEX_NOIBAT,
        .categoryName = _("Sound Wave"),
        .height = 5,
        .weight = 80,
        .description = COMPOUND_STRING(
            "They live in pitch-black caves. Even a\n"
            "robust wrestler will become dizzy and\n"
            "unable to stand when exposed to its\n"
            "200,000-hertz ultrasonic waves."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Noibat, 64, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Noibat,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 8,
        BACK_PIC(Noibat, 56, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Noibat),
        ICON(Noibat, 2),
        .footprint = gMonFootprint_Noibat,
        LEARNSETS(Noibat),
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_NOIVERN}),
    },

    [SPECIES_NOIVERN] =
    {
        .baseHP        = 85,
        .baseAttack    = 70,
        .baseDefense   = 80,
        .baseSpeed     = 123,
        .baseSpAttack  = 97,
        .baseSpDefense = 80,
        .types = { TYPE_FLYING, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 187,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_DRAGON },
        #else
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        #endif
        .abilities = { ABILITY_FRISK, ABILITY_INFILTRATOR, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Noivern"),
        .cryId = CRY_NOIVERN,
        .natDexNum = NATIONAL_DEX_NOIVERN,
        .categoryName = _("Sound Wave"),
        .height = 15,
        .weight = 850,
        .description = COMPOUND_STRING(
            "They fly around on moonless nights and\n"
            "attack careless prey. The ultrasonic waves\n"
            "it emits from its ears can reduce a large\n"
            "boulder to pebbles."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Noivern, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Noivern,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Noivern, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Noivern),
        ICON(Noivern, 2),
        .footprint = gMonFootprint_Noivern,
        LEARNSETS(Noivern),
    },
#endif //P_FAMILY_NOIBAT

#if P_FAMILY_XERNEAS
#define XERNEAS_MISC_INFO(Form)                                                         \
    {                                                                                   \
        .baseHP        = 126,                                                           \
        .baseAttack    = 131,                                                           \
        .baseDefense   = 95,                                                            \
        .baseSpeed     = 99,                                                            \
        .baseSpAttack  = 131,                                                           \
        .baseSpDefense = 98,                                                            \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                            \
        .catchRate = 45,                                                                \
        .expYield = 306,                                                                \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_FAIRY_AURA, ABILITY_NONE },                              \
        .bodyColor = BODY_COLOR_BLUE,                                                   \
        .speciesName = _("Xerneas"),                                                    \
        .cryId = CRY_XERNEAS,                                                           \
        .natDexNum = NATIONAL_DEX_XERNEAS,                                              \
        .categoryName = _("Life"),                                                      \
        .height = 30,                                                                   \
        .weight = 2150,                                                                 \
        .description = gXerneasPokedexText,                                             \
        .pokemonScale = 275,                                                            \
        .pokemonOffset = 7,                                                             \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Xerneas##Form, 64, 64),                                               \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Xerneas,                                              \
        .frontAnimId = ANIM_GROW_VIBRATE,                                               \
        BACK_PIC(Xerneas##Form, 64, 64),                                                \
        .backPicYOffset = 0,                                                            \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                        \
        PALETTES(Xerneas##Form),                                                        \
        ICON(Xerneas##Form, 0),                                                         \
        .footprint = gMonFootprint_Xerneas,                                             \
        LEARNSETS(Xerneas),                                                             \
        .formSpeciesIdTable = sXerneasFormSpeciesIdTable,                               \
        .formChangeTable = sXerneasFormChangeTable,                                     \
        .isLegendary = TRUE,                                                            \
    }

    [SPECIES_XERNEAS_NEUTRAL] = XERNEAS_MISC_INFO(Neutral),
    [SPECIES_XERNEAS_ACTIVE]  = XERNEAS_MISC_INFO(Active),
#endif //P_FAMILY_XERNEAS

#if P_FAMILY_YVELTAL
    [SPECIES_YVELTAL] =
    {
        .baseHP        = 126,
        .baseAttack    = 131,
        .baseDefense   = 95,
        .baseSpeed     = 99,
        .baseSpAttack  = 131,
        .baseSpDefense = 98,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 306,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_DARK_AURA, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .isLegendary = TRUE,
        .speciesName = _("Yveltal"),
        .cryId = CRY_YVELTAL,
        .natDexNum = NATIONAL_DEX_YVELTAL,
        .categoryName = _("Destruction"),
        .height = 58,
        .weight = 2030,
        .description = COMPOUND_STRING(
            "When its life comes to an end, its wings\n"
            "and tail spread wide and glow red, and\n"
            "it absorbs the life energy of every living\n"
            "thing and turns into a cocoon."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 360,
        .trainerOffset = 7,
        FRONT_PIC(Yveltal, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Yveltal,
        .frontAnimId = ANIM_FRONT_FLIP,
        .enemyMonElevation = 5,
        BACK_PIC(Yveltal, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Yveltal),
        ICON(Yveltal, 0),
        .footprint = gMonFootprint_Yveltal,
        LEARNSETS(Yveltal),
    },
#endif //P_FAMILY_YVELTAL

#if P_FAMILY_ZYGARDE
#define ZYGARDE_MISC_INFO(ability)                                                      \
        .types = { TYPE_DRAGON, TYPE_GROUND },                                          \
        .catchRate = 3,                                                                 \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ability, ABILITY_NONE },                                         \
        .noFlip = TRUE,                                                                 \
        .speciesName = _("Zygarde"),                                                    \
        .natDexNum = NATIONAL_DEX_ZYGARDE,                                              \
        .categoryName = _("Order"),                                                     \
        .footprint = gMonFootprint_Zygarde,                                             \
        LEARNSETS(Zygarde),                                                             \
        .formSpeciesIdTable = sZygardeFormSpeciesIdTable,                               \
        .isLegendary = TRUE

#define ZYGARDE_50_SPECIES_INFO(ability)                        \
    {                                                           \
        .baseHP        = 108,                                   \
        .baseAttack    = 100,                                   \
        .baseDefense   = 121,                                   \
        .baseSpeed     = 95,                                    \
        .baseSpAttack  = 81,                                    \
        .baseSpDefense = 95,                                    \
        .expYield = 270,                                        \
        .bodyColor = BODY_COLOR_GREEN,                          \
        .cryId = CRY_ZYGARDE_50,                                \
        .height = 50,                                           \
        .weight = 3050,                                         \
        .description = gZygarde50PokedexText,                   \
        .pokemonScale = 256,                                    \
        .pokemonOffset = 0,                                     \
        .trainerScale = 721,                                    \
        .trainerOffset = 19,                                    \
        FRONT_PIC(Zygarde50, 64, 64),                           \
        .frontPicYOffset = 0,                                   \
        .frontAnimFrames = sAnims_Zygarde50,                    \
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,                   \
        BACK_PIC(Zygarde50, 64, 64),                            \
        .backPicYOffset = 4,                                    \
        .backAnimId = (ability == ABILITY_POWER_CONSTRUCT       \
            ? BACK_ANIM_SHAKE_GLOW_GREEN                        \
            : BACK_ANIM_V_STRETCH),                             \
        PALETTES(Zygarde50),                                    \
        ICON(Zygarde50, 1),                                     \
        .formChangeTable = (ability == ABILITY_POWER_CONSTRUCT  \
            ? sZygarde50PowerConstructFormChangeTable           \
            : sZygarde50AuraBreakFormChangeTable),              \
        ZYGARDE_MISC_INFO(ability),                             \
    }

#define ZYGARDE_10_SPECIES_INFO(ability)                        \
    {                                                           \
        .baseHP        = 54,                                    \
        .baseAttack    = 100,                                   \
        .baseDefense   = 71,                                    \
        .baseSpeed     = 115,                                   \
        .baseSpAttack  = 61,                                    \
        .baseSpDefense = 85,                                    \
        .expYield = 219,                                        \
        .bodyColor = BODY_COLOR_BLACK,                          \
        .cryId = CRY_ZYGARDE_10,                                \
        .height = 12,                                           \
        .weight = 335,                                          \
        .description = gZygarde10PokedexText,                   \
        .pokemonScale = 256,                                    \
        .pokemonOffset = 0,                                     \
        .trainerScale = 721,                                    \
        .trainerOffset = 19,                                    \
        FRONT_PIC(Zygarde10, 56, 64),                           \
        .frontPicYOffset = 2,                                   \
        .frontAnimFrames = sAnims_Zygarde10,                    \
        BACK_PIC(Zygarde10, 64, 56),                            \
        .backPicYOffset = 8,                                    \
        .backAnimId = (ability == ABILITY_POWER_CONSTRUCT       \
            ? BACK_ANIM_SHAKE_GLOW_GREEN                        \
            : BACK_ANIM_JOLT_RIGHT),                            \
        PALETTES(Zygarde10),                                    \
        ICON(Zygarde10, 1),                                     \
        .formChangeTable = (ability == ABILITY_POWER_CONSTRUCT  \
            ? sZygarde10PowerConstructFormChangeTable           \
            : sZygarde10AuraBreakFormChangeTable),              \
        ZYGARDE_MISC_INFO(ability),                             \
    }
    //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,

    [SPECIES_ZYGARDE_50_AURA_BREAK]      = ZYGARDE_50_SPECIES_INFO(ABILITY_AURA_BREAK),
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = ZYGARDE_50_SPECIES_INFO(ABILITY_POWER_CONSTRUCT),
    [SPECIES_ZYGARDE_10_AURA_BREAK]      = ZYGARDE_10_SPECIES_INFO(ABILITY_AURA_BREAK),
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = ZYGARDE_10_SPECIES_INFO(ABILITY_POWER_CONSTRUCT),
    [SPECIES_ZYGARDE_COMPLETE] =
    {
        ZYGARDE_MISC_INFO(ABILITY_POWER_CONSTRUCT),
        .baseHP        = 216,
        .baseAttack    = 100,
        .baseDefense   = 121,
        .baseSpeed     = 85,
        .baseSpAttack  = 91,
        .baseSpDefense = 95,
        .expYield = 319,
        .bodyColor = BODY_COLOR_BLACK,
        .cryId = CRY_ZYGARDE_COMPLETE,
        .height = 45,
        .weight = 6100,
        .description = COMPOUND_STRING(
            "This is Zygarde's perfected form.\n"
            "From the orifice on its chest, it\n"
            "radiates high-powered energy that\n"
            "eliminates everything."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(ZygardeComplete, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_ZygardeComplete,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(ZygardeComplete, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        PALETTES(ZygardeComplete),
        ICON(ZygardeComplete, 1),
        .formChangeTable = sZygardeCompleteFormChangeTable,
    },
#endif //P_FAMILY_ZYGARDE

#if P_FAMILY_DIANCIE
#define DIANCE_MISC_INFO                                                                \
        .types = { TYPE_ROCK, TYPE_FAIRY },                                             \
        .catchRate = 3,                                                                 \
        .evYield_Defense = 1,                                                           \
        .evYield_SpDefense = 2,                                                         \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 25,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_PINK,                                                   \
        .speciesName = _("Diancie"),                                                    \
        .natDexNum = NATIONAL_DEX_DIANCIE,                                              \
        .categoryName = _("Jewel"),                                                     \
        .footprint = gMonFootprint_Diancie,                                             \
        LEARNSETS(Diancie),                                                             \
        .formSpeciesIdTable = sDiancieFormSpeciesIdTable,                               \
        .formChangeTable = sDiancieFormChangeTable,                                     \
        .isMythical = TRUE

    [SPECIES_DIANCIE] =
    {
        DIANCE_MISC_INFO,
        .baseHP        = 50,
        .baseAttack    = 100,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 100,
        .baseSpDefense = 150,
        .expYield = 270,
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE },
        .cryId = CRY_DIANCIE,
        .height = 7,
        .weight = 88,
        .description = COMPOUND_STRING(
            "A sudden transformation of Carbink,\n"
            "its pink, glimmering body is said to be\n"
            "the loveliest sight in the whole world.\n"
            "It creates diamonds between its hands."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Diancie, 40, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Diancie,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Diancie, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Diancie),
        ICON(Diancie, 1),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_DIANCIE_MEGA] =
    {
        DIANCE_MISC_INFO,
        .baseHP        = 50,
        .baseAttack    = 160,
        .baseDefense   = 110,
        .baseSpeed     = 110,
        .baseSpAttack  = 160,
        .baseSpDefense = 110,
        .expYield = 315,
        .abilities = { ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE },
        .cryId = CRY_DIANCIE_MEGA,
        .height = 11,
        .weight = 278,
        .description = COMPOUND_STRING(
            ""),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(DiancieMega, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DiancieMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DiancieMega, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DiancieMega),
        ICON(DiancieMega, 0),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_DIANCIE

#if P_FAMILY_HOOPA
#define HOOPA_MISC_INFO                                                                 \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_MAGICIAN, ABILITY_NONE },                                \
        .bodyColor = BODY_COLOR_PURPLE,                                                 \
        .speciesName = _("Hoopa"),                                                      \
        .natDexNum = NATIONAL_DEX_HOOPA,                                                \
        .footprint = gMonFootprint_Hoopa,                                               \
        .formSpeciesIdTable = sHoopaFormSpeciesIdTable,                                 \
        .formChangeTable = sHoopaFormChangeTable,                                       \
        .isMythical = TRUE

    [SPECIES_HOOPA_CONFINED] =
    {
        HOOPA_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 110,
        .baseDefense   = 60,
        .baseSpeed     = 70,
        .baseSpAttack  = 150,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_GHOST },
        .friendship = 100,
        .cryId = CRY_HOOPA_CONFINED,
        .categoryName = _("Mischief"),
        .height = 5,
        .weight = 90,
        .description = COMPOUND_STRING(
            "In its true form, it possess a huge amount\n"
            "of power. When its powers are sealed away,\n"
            "it is transformed into a much smaller form.\n"
            "It teleports things to a secret place."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HoopaConfined, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_HoopaConfined,
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = 13,
        BACK_PIC(HoopaConfined, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(HoopaConfined),
        ICON(HoopaConfined, 0),
        LEARNSETS(HoopaConfined),
    },

    [SPECIES_HOOPA_UNBOUND] =
    {
        HOOPA_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 160,
        .baseDefense   = 60,
        .baseSpeed     = 80,
        .baseSpAttack  = 170,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_DARK },
        .friendship = P_UPDATED_FRIENDSHIP >= GEN_8 ? STANDARD_FRIENDSHIP : 100,
        .cryId = CRY_HOOPA_UNBOUND,
        .categoryName = _("Djinn"),
        .height = 65,
        .weight = 490,
        .description = COMPOUND_STRING(
            ""),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HoopaUnbound, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_HoopaUnbound,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .enemyMonElevation = 3,
        BACK_PIC(HoopaUnbound, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(HoopaUnbound),
        ICON(HoopaUnbound, 0),
        LEARNSETS(HoopaUnbound),
    },
#endif //P_FAMILY_HOOPA

#if P_FAMILY_VOLCANION
    [SPECIES_VOLCANION] =
    {
        .baseHP        = 80,
        .baseAttack    = 110,
        .baseDefense   = 120,
        .baseSpeed     = 70,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .types = { TYPE_FIRE, TYPE_WATER },
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .isMythical = TRUE,
        .speciesName = _("Volcanion"),
        .cryId = CRY_VOLCANION,
        .natDexNum = NATIONAL_DEX_VOLCANION,
        .categoryName = _("Steam"),
        .height = 17,
        .weight = 1950,
        .description = COMPOUND_STRING(
            "It lets out billows of steam from the arms\n"
            "on its back and disappears into the dense\n"
            "fog. It's said to live in mountains where\n"
            "humans do not tread."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Volcanion, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Volcanion,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Volcanion, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Volcanion),
        ICON(Volcanion, 0),
        .footprint = gMonFootprint_Volcanion,
        LEARNSETS(Volcanion),
    },
#endif //P_FAMILY_VOLCANION

#ifdef __INTELLISENSE__
};
#endif