#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen2[] =
{
#endif

#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] =
    {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 65,
        .baseSpeed     = 45,
        .baseSpAttack  = 49,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Chikorita"),
        .cryId = CRY_CHIKORITA,
        .natDexNum = NATIONAL_DEX_CHIKORITA,
        .categoryName = _("Leaf"),
        .height = 9,
        .weight = 64,
        .description = COMPOUND_STRING(
            "It waves its leaf around to keep foes\n"
            "at bay. However, a sweet fragrance also\n"
            "wafts from the leaf, creating a friendly\n"
            "atmosphere that becalms the battlers."),
        .pokemonScale = 512,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chikorita,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Chikorita,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Chikorita,
        .shinyPalette = gMonShinyPalette_Chikorita,
        .iconSprite = gMonIcon_Chikorita,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Chikorita)
        OVERWORLD(
            sPicTable_Chikorita,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Chikorita,
            gShinyOverworldPalette_Chikorita
        )
        .levelUpLearnset = sChikoritaLevelUpLearnset,
        .teachableLearnset = sChikoritaTeachableLearnset,
        .eggMoveLearnset = sChikoritaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_BAYLEEF}),
    },

    [SPECIES_BAYLEEF] =
    {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 63,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 141,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bayleef"),
        .cryId = CRY_BAYLEEF,
        .natDexNum = NATIONAL_DEX_BAYLEEF,
        .categoryName = _("Leaf"),
        .height = 12,
        .weight = 158,
        .description = COMPOUND_STRING(
            "A Bayleef's neck is ringed by curled-up\n"
            "leaves. Inside each leaf is a small tree\n"
            "shoot. The fragrance of this shoot\n"
            "makes people peppy."),
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bayleef,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Bayleef,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Bayleef,
        .shinyPalette = gMonShinyPalette_Bayleef,
        .iconSprite = gMonIcon_Bayleef,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 10, SHADOW_SIZE_M)
        FOOTPRINT(Bayleef)
        OVERWORLD(
            sPicTable_Bayleef,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bayleef,
            gShinyOverworldPalette_Bayleef
        )
        .levelUpLearnset = sBayleefLevelUpLearnset,
        .teachableLearnset = sBayleefTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_MEGANIUM}),
    },

    [SPECIES_MEGANIUM] =
    {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 100,
        .baseSpeed     = 80,
        .baseSpAttack  = 83,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 263,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 236,
    #else
        .expYield = 208,
    #endif
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Meganium"),
        .cryId = CRY_MEGANIUM,
        .natDexNum = NATIONAL_DEX_MEGANIUM,
        .categoryName = _("Herb"),
        .height = 18,
        .weight = 1005,
        .description = COMPOUND_STRING(
            "The fragrance of a Meganium's flower\n"
            "soothes and calms emotions. In battle,\n"
            "it gives off more of its becalming scent\n"
            "to blunt the foe's fighting spirit."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 277,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Meganium,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Meganium,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Meganium,
        .shinyPalette = gMonShinyPalette_Meganium,
        .iconSprite = gMonIcon_Meganium,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_MeganiumF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 64),
        .backPicFemale = gMonBackPic_MeganiumF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_M)
        FOOTPRINT(Meganium)
        OVERWORLD(
            sPicTable_Meganium,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Meganium,
            gShinyOverworldPalette_Meganium
        )
        OVERWORLD_FEMALE(
            sPicTable_MeganiumF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sMeganiumLevelUpLearnset,
        .teachableLearnset = sMeganiumTeachableLearnset,
        .formSpeciesIdTable = sMeganiumFormSpeciesIdTable,
        .formChangeTable = sMeganiumFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_MEGANIUM_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 92,
        .baseDefense   = 115,
        .baseSpeed     = 80,
        .baseSpAttack  = 143,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 263,
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_MEGA_SOL, ABILITY_MEGA_SOL, ABILITY_MEGA_SOL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Meganium"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_MEGANIUM_MEGA,
    #else
        .cryId = CRY_MEGANIUM,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_MEGANIUM,
        .categoryName = _("Herb"),
        .height = 24,
        .weight = 2010,
        .description = COMPOUND_STRING(
            "This Pokémon can fire a tremendously\n"
            "powerful Solar Beam from its four\n"
            "flowers. Another name for this is\n"
            "Mega Sol Cannon."),
        .frontPic = gMonFrontPic_MeganiumMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MeganiumMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MeganiumMega,
        .shinyPalette = gMonShinyPalette_MeganiumMega,
        .iconSprite = gMonIcon_MeganiumMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Meganium)
        SHADOW(-2, 13, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sMeganiumLevelUpLearnset,
        .teachableLearnset = sMeganiumTeachableLearnset,
        .formSpeciesIdTable = sMeganiumFormSpeciesIdTable,
        .formChangeTable = sMeganiumFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_CHIKORITA

#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] =
    {
        .baseHP        = 39,
        .baseAttack    = 52,
        .baseDefense   = 43,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 65,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Cyndaquil"),
        .cryId = CRY_CYNDAQUIL,
        .natDexNum = NATIONAL_DEX_CYNDAQUIL,
        .categoryName = _("Fire Mouse"),
        .height = 5,
        .weight = 79,
        .description = COMPOUND_STRING(
            "It flares flames from its back to protect\n"
            "itself. The fire burns vigorously if the\n"
            "Pokémon is angry. When it is tired,\n"
            "it sputters with incomplete combustion."),
        .pokemonScale = 539,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cyndaquil,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_JUMPS_SMALL : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Cyndaquil,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Cyndaquil,
        .shinyPalette = gMonShinyPalette_Cyndaquil,
        .iconSprite = gMonIcon_Cyndaquil,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -1, SHADOW_SIZE_S)
        FOOTPRINT(Cyndaquil)
        OVERWORLD(
            sPicTable_Cyndaquil,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cyndaquil,
            gShinyOverworldPalette_Cyndaquil
        )
        .levelUpLearnset = sCyndaquilLevelUpLearnset,
        .teachableLearnset = sCyndaquilTeachableLearnset,
        .eggMoveLearnset = sCyndaquilEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_QUILAVA}),
    },

    [SPECIES_QUILAVA] =
    {
        .baseHP        = 58,
        .baseAttack    = 64,
        .baseDefense   = 58,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
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
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Quilava"),
        .cryId = CRY_QUILAVA,
        .natDexNum = NATIONAL_DEX_QUILAVA,
        .categoryName = _("Volcano"),
        .height = 9,
        .weight = 190,
        .description = COMPOUND_STRING(
            "It intimidates foes with intense gusts of\n"
            "flames and superheated air. Its quick\n"
            "nimbleness lets it dodge attacks even\n"
            "while scorching an enemy."),
        .pokemonScale = 329,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Quilava,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_H_STRETCH,
        .backPic = gMonBackPic_Quilava,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 0,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Quilava,
        .shinyPalette = gMonShinyPalette_Quilava,
        .iconSprite = gMonIcon_Quilava,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(Quilava)
        OVERWORLD(
            sPicTable_Quilava,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Quilava,
            gShinyOverworldPalette_Quilava
        )
        .levelUpLearnset = sQuilavaLevelUpLearnset,
        .teachableLearnset = sQuilavaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_TYPHLOSION, CONDITIONS({IF_NOT_REGION, REGION_HISUI})}
                            #if P_HISUIAN_FORMS
                                ,{EVO_LEVEL, 36, SPECIES_TYPHLOSION_HISUI, CONDITIONS({IF_REGION, REGION_HISUI})}
                            #endif
                            ),
    },

    [SPECIES_TYPHLOSION] =
    {
        .baseHP        = 78,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = 109,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 267,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 240,
    #else
        .expYield = 209,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Typhlosion"),
        .cryId = CRY_TYPHLOSION,
        .natDexNum = NATIONAL_DEX_TYPHLOSION,
        .categoryName = _("Volcano"),
        .height = 17,
        .weight = 795,
        .description = COMPOUND_STRING(
            "It can hide behind a shimmering heat haze\n"
            "that it creates using its intense flames.\n"
            "Typhlosion create blazing explosive\n"
            "blasts that burn everything to cinders."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Typhlosion,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Typhlosion,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Typhlosion,
        .shinyPalette = gMonShinyPalette_Typhlosion,
        .iconSprite = gMonIcon_Typhlosion,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 14, SHADOW_SIZE_L)
        FOOTPRINT(Typhlosion)
        OVERWORLD(
            sPicTable_Typhlosion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Typhlosion,
            gShinyOverworldPalette_Typhlosion
        )
        .levelUpLearnset = sTyphlosionLevelUpLearnset,
        .teachableLearnset = sTyphlosionTeachableLearnset,
        .formSpeciesIdTable = sTyphlosionFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_TYPHLOSION_HISUI] =
    {
        .baseHP        = 73,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 95,
        .baseSpAttack  = 119,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 267,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Typhlosion"),
        .cryId = CRY_TYPHLOSION,
        .natDexNum = NATIONAL_DEX_TYPHLOSION,
        .categoryName = _("Ghost Flame"),
        .height = 16,
        .weight = 698,
        .description = COMPOUND_STRING(
            "Said to purify lost, forsaken souls with\n"
            "its flames and guide them to the afterlife.\n"
            "It's believed its form was influenced by\n"
            "the energy of Mt. Coronet in ancient times."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_TyphlosionHisui,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TyphlosionHisui,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TyphlosionHisui,
        .shinyPalette = gMonShinyPalette_TyphlosionHisui,
        .iconSprite = gMonIcon_TyphlosionHisui,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_L)
        FOOTPRINT(Typhlosion)
        OVERWORLD(
            sPicTable_TyphlosionHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TyphlosionHisui,
            gShinyOverworldPalette_TyphlosionHisui
        )
        .isHisuianForm = TRUE,
        .levelUpLearnset = sTyphlosionHisuiLevelUpLearnset,
        .teachableLearnset = sTyphlosionHisuiTeachableLearnset,
        .formSpeciesIdTable = sTyphlosionFormSpeciesIdTable,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_CYNDAQUIL

#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 64,
        .baseSpeed     = 43,
        .baseSpAttack  = 44,
        .baseSpDefense = 48,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 63 : 66,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Totodile"),
        .cryId = CRY_TOTODILE,
        .natDexNum = NATIONAL_DEX_TOTODILE,
        .categoryName = _("Big Jaw"),
        .height = 6,
        .weight = 95,
        .description = COMPOUND_STRING(
            "Despite its small body, Totodile's jaws\n"
            "are very powerful. While it may think it is\n"
            "just playfully nipping, its bite has enough\n"
            "strength to cause serious injury."),
        .pokemonScale = 487,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Totodile,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = gMonBackPic_Totodile,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Totodile,
        .shinyPalette = gMonShinyPalette_Totodile,
        .iconSprite = gMonIcon_Totodile,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Totodile)
        OVERWORLD(
            sPicTable_Totodile,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Totodile,
            gShinyOverworldPalette_Totodile
        )
        .levelUpLearnset = sTotodileLevelUpLearnset,
        .teachableLearnset = sTotodileTeachableLearnset,
        .eggMoveLearnset = sTotodileEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_CROCONAW}),
    },

    [SPECIES_CROCONAW] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 58,
        .baseSpAttack  = 59,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 143,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Croconaw"),
        .cryId = CRY_CROCONAW,
        .natDexNum = NATIONAL_DEX_CROCONAW,
        .categoryName = _("Big Jaw"),
        .height = 11,
        .weight = 250,
        .description = COMPOUND_STRING(
            "Once its jaws clamp down on its foe, it will\n"
            "absolutely not let go. Because the tips of\n"
            "its fangs are forked back like fishhooks,\n"
            "they become irremovably embedded."),
        .pokemonScale = 378,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Croconaw,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Croconaw,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 2,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Croconaw,
        .shinyPalette = gMonShinyPalette_Croconaw,
        .iconSprite = gMonIcon_Croconaw,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Croconaw)
        OVERWORLD(
            sPicTable_Croconaw,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Croconaw,
            gShinyOverworldPalette_Croconaw
        )
        .levelUpLearnset = sCroconawLevelUpLearnset,
        .teachableLearnset = sCroconawTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_FERALIGATR}),
    },

    [SPECIES_FERALIGATR] =
    {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 100,
        .baseSpeed     = 78,
        .baseSpAttack  = 79,
        .baseSpDefense = 83,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 265,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 239,
    #else
        .expYield = 210,
    #endif
        .evYield_Attack = 2,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Feraligatr"),
        .cryId = CRY_FERALIGATR,
        .natDexNum = NATIONAL_DEX_FERALIGATR,
        .categoryName = _("Big Jaw"),
        .height = 23,
        .weight = 888,
        .description = COMPOUND_STRING(
            "It opens its huge mouth to intimidate\n"
            "enemies. In battle, it runs using its thick\n"
            "and powerful hind legs to charge the\n"
            "foe with incredible speed."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Feraligatr,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 40),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 5,
        .backPic = gMonBackPic_Feraligatr,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Feraligatr,
        .shinyPalette = gMonShinyPalette_Feraligatr,
        .iconSprite = gMonIcon_Feraligatr,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Feraligatr)
        OVERWORLD(
            sPicTable_Feraligatr,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Feraligatr,
            gShinyOverworldPalette_Feraligatr
        )
        .levelUpLearnset = sFeraligatrLevelUpLearnset,
        .teachableLearnset = sFeraligatrTeachableLearnset,
        .formSpeciesIdTable = sFeraligatrFormSpeciesIdTable,
        .formChangeTable = sFeraligatrFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_FERALIGATR_MEGA] =
    {
        .baseHP        = 85,
        .baseAttack    = 160,
        .baseDefense   = 125,
        .baseSpeed     = 78,
        .baseSpAttack  = 89,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Attack = 2,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_DRAGONIZE, ABILITY_NONE, ABILITY_DRAGONIZE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Feraligatr"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_FERALIGATR_MEGA,
    #else
        .cryId = CRY_FERALIGATR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_FERALIGATR,
        .categoryName = _("Double Jaw"),
        .height = 23,
        .weight = 1088,
        .description = COMPOUND_STRING(
            "With its arms and hoodlike fin, this\n"
            "Pokémon forms a gigantic set of jaws\n"
            "with a bite 10 times as powerful\n"
            "as Mega Feraligatr's actual jaws."),
        .frontPic = gMonFrontPic_FeraligatrMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_FeraligatrMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_FeraligatrMega,
        .shinyPalette = gMonShinyPalette_FeraligatrMega,
        .iconSprite = gMonIcon_FeraligatrMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Feraligatr)
        SHADOW(2, 13, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sFeraligatrLevelUpLearnset,
        .teachableLearnset = sFeraligatrTeachableLearnset,
        .formSpeciesIdTable = sFeraligatrFormSpeciesIdTable,
        .formChangeTable = sFeraligatrFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_TOTODILE

#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] =
    {
        .baseHP        = 35,
        .baseAttack    = 46,
        .baseDefense   = 34,
        .baseSpeed     = 20,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 43 : 57,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KEEN_EYE, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Sentret"),
        .cryId = CRY_SENTRET,
        .natDexNum = NATIONAL_DEX_SENTRET,
        .categoryName = _("Scout"),
        .height = 8,
        .weight = 60,
        .description = COMPOUND_STRING(
            "They take turns standing guard when it\n"
            "is time to sleep. The sentry awakens the\n"
            "others if it senses danger. If one becomes\n"
            "separated, it turns sleepless with fear."),
        .pokemonScale = 439,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sentret,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 56) : MON_COORDS_SIZE(40, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sentret,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(48, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Sentret,
        .shinyPalette = gMonShinyPalette_Sentret,
        .iconSprite = gMonIcon_Sentret,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_S)
        FOOTPRINT(Sentret)
        OVERWORLD(
            sPicTable_Sentret,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sentret,
            gShinyOverworldPalette_Sentret
        )
        .levelUpLearnset = sSentretLevelUpLearnset,
        .teachableLearnset = sSentretTeachableLearnset,
        .eggMoveLearnset = sSentretEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_FURRET}),
    },

    [SPECIES_FURRET] =
    {
        .baseHP        = 85,
        .baseAttack    = 76,
        .baseDefense   = 64,
        .baseSpeed     = 90,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 145 : 116,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KEEN_EYE, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Furret"),
        .cryId = CRY_FURRET,
        .natDexNum = NATIONAL_DEX_FURRET,
        .categoryName = _("Long Body"),
        .height = 18,
        .weight = 325,
        .description = COMPOUND_STRING(
            "A Furret has a very slim build. When under\n"
            "attack, it can squirm through narrow\n"
            "spaces and get away. In spite of its short\n"
            "limbs, it is very nimble and fleet."),
        .pokemonScale = 346,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Furret,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Furret,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Furret,
        .shinyPalette = gMonShinyPalette_Furret,
        .iconSprite = gMonIcon_Furret,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Furret)
        OVERWORLD(
            sPicTable_Furret,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Furret,
            gShinyOverworldPalette_Furret
        )
        .levelUpLearnset = sFurretLevelUpLearnset,
        .teachableLearnset = sFurretTeachableLearnset,
    },
#endif //P_FAMILY_SENTRET

#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] =
    {
        .baseHP        = 60,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 50,
        .baseSpAttack  = 36,
        .baseSpDefense = 56,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 52 : 58,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INSOMNIA, ABILITY_KEEN_EYE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hoothoot"),
        .cryId = CRY_HOOTHOOT,
        .natDexNum = NATIONAL_DEX_HOOTHOOT,
        .categoryName = _("Owl"),
        .height = 7,
        .weight = 212,
        .description = COMPOUND_STRING(
            "It has an internal organ that senses\n"
            "the earth's rotation. Using this special\n"
            "organ, a Hoothoot begins hooting at\n"
            "precisely the same time every day."),
        .pokemonScale = 380,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hoothoot,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_V_SLIDE_SLOW,
        .backPic = gMonBackPic_Hoothoot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 4,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Hoothoot,
        .shinyPalette = gMonShinyPalette_Hoothoot,
        .iconSprite = gMonIcon_Hoothoot,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Hoothoot)
        OVERWORLD(
            sPicTable_Hoothoot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hoothoot,
            gShinyOverworldPalette_Hoothoot
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sHoothootLevelUpLearnset,
        .teachableLearnset = sHoothootTeachableLearnset,
        .eggMoveLearnset = sHoothootEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_NOCTOWL}),
    },

    [SPECIES_NOCTOWL] =
    {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 86 : 76,
        .baseSpDefense = 96,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 90,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 158,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 155,
    #else
        .expYield = 162,
    #endif
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INSOMNIA, ABILITY_KEEN_EYE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Noctowl"),
        .cryId = CRY_NOCTOWL,
        .natDexNum = NATIONAL_DEX_NOCTOWL,
        .categoryName = _("Owl"),
        .height = 16,
        .weight = 408,
        .description = COMPOUND_STRING(
            "It unfailingly catches prey in darkness.\n"
            "Noctowl owe their success to superior\n"
            "vision that allows them to see in minimal\n"
            "light, and to their supple and silent wings."),
        .pokemonScale = 278,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Noctowl,
        .frontPicSize = MON_COORDS_SIZE(40, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Noctowl,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Noctowl,
        .shinyPalette = gMonShinyPalette_Noctowl,
        .iconSprite = gMonIcon_Noctowl,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 10, SHADOW_SIZE_S)
        FOOTPRINT(Noctowl)
        OVERWORLD(
            sPicTable_Noctowl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Noctowl,
            gShinyOverworldPalette_Noctowl
        )
        .levelUpLearnset = sNoctowlLevelUpLearnset,
        .teachableLearnset = sNoctowlTeachableLearnset,
    },
#endif //P_FAMILY_HOOTHOOT

#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] =
    {
        .baseHP        = 40,
        .baseAttack    = 20,
        .baseDefense   = 30,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 53 : 54,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_EARLY_BIRD, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ledyba"),
        .cryId = CRY_LEDYBA,
        .natDexNum = NATIONAL_DEX_LEDYBA,
        .categoryName = _("Five Star"),
        .height = 10,
        .weight = 108,
        .description = COMPOUND_STRING(
            "Ledyba communicate using a fluid that\n"
            "they secrete from where the legs join the\n"
            "body. They are said to convey feelings to\n"
            "others by altering the fluid's scent."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ledyba,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Ledyba,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Ledyba,
        .shinyPalette = gMonShinyPalette_Ledyba,
        .iconSprite = gMonIcon_Ledyba,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_LedybaF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 48),
        .backPicFemale = gMonBackPic_LedybaF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 4, SHADOW_SIZE_M)
        FOOTPRINT(Ledyba)
        OVERWORLD(
            sPicTable_Ledyba,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Ledyba,
            gShinyOverworldPalette_Ledyba
        )
        OVERWORLD_FEMALE(
            sPicTable_LedybaF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following
        )
        .levelUpLearnset = sLedybaLevelUpLearnset,
        .teachableLearnset = sLedybaTeachableLearnset,
        .eggMoveLearnset = sLedybaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_LEDIAN}),
    },

    [SPECIES_LEDIAN] =
    {
        .baseHP        = 55,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 137 : 134,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_EARLY_BIRD, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ledian"),
        .cryId = CRY_LEDIAN,
        .natDexNum = NATIONAL_DEX_LEDIAN,
        .categoryName = _("Five Star"),
        .height = 14,
        .weight = 356,
        .description = COMPOUND_STRING(
            "It is said that in lands with clean air,\n"
            "where the stars fill the sky, there live\n"
            "many Ledian. For good reason, they use\n"
            "the light of the stars as energy."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ledian,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SLIDE_SLOW : ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .backPic = gMonBackPic_Ledian,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Ledian,
        .shinyPalette = gMonShinyPalette_Ledian,
        .iconSprite = gMonIcon_Ledian,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_LedianF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 56),
        .backPicFemale = gMonBackPic_LedianF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_S)
        FOOTPRINT(Ledian)
        OVERWORLD(
            sPicTable_Ledian,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ledian,
            gShinyOverworldPalette_Ledian
        )
        OVERWORLD_FEMALE(
            sPicTable_LedianF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sLedianLevelUpLearnset,
        .teachableLearnset = sLedianTeachableLearnset,
    },
#endif //P_FAMILY_LEDYBA

#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] =
    {
        .baseHP        = 40,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 50 : 54,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_INSOMNIA, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Spinarak"),
        .cryId = CRY_SPINARAK,
        .natDexNum = NATIONAL_DEX_SPINARAK,
        .categoryName = _("String Spit"),
        .height = 5,
        .weight = 85,
        .description = COMPOUND_STRING(
            "The web it spins can be considered its\n"
            "second nervous system. It is said that a\n"
            "Spinarak determines its prey by the tiny\n"
            "vibrations it feels through the web."),
        .pokemonScale = 414,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Spinarak,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 19 : 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .backPic = gMonBackPic_Spinarak,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 24) : MON_COORDS_SIZE(64, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 21 : 16,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Spinarak,
        .shinyPalette = gMonShinyPalette_Spinarak,
        .iconSprite = gMonIcon_Spinarak,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -8, SHADOW_SIZE_M)
        FOOTPRINT(Spinarak)
        OVERWORLD(
            sPicTable_Spinarak,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Spinarak,
            gShinyOverworldPalette_Spinarak
        )
        .levelUpLearnset = sSpinarakLevelUpLearnset,
        .teachableLearnset = sSpinarakTeachableLearnset,
        .eggMoveLearnset = sSpinarakEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_ARIADOS}),
    },

    [SPECIES_ARIADOS] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_7 ? 70 : 60,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 90,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 140,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 137,
    #else
        .expYield = 134,
    #endif
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_INSOMNIA, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ariados"),
        .cryId = CRY_ARIADOS,
        .natDexNum = NATIONAL_DEX_ARIADOS,
        .categoryName = _("Long Leg"),
        .height = 11,
        .weight = 335,
        .description = COMPOUND_STRING(
            "Its feet are tipped with tiny hooked claws\n"
            "that enable it to scuttle on ceilings and\n"
            "vertical walls. It constricts its foe with\n"
            "thin and strong silk webbing."),
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ariados,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Ariados,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Ariados,
        .shinyPalette = gMonShinyPalette_Ariados,
        .iconSprite = gMonIcon_Ariados,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 3, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Ariados)
        OVERWORLD(
            sPicTable_Ariados,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Ariados,
            gShinyOverworldPalette_Ariados
        )
        .levelUpLearnset = sAriadosLevelUpLearnset,
        .teachableLearnset = sAriadosTeachableLearnset,
    },
#endif //P_FAMILY_SPINARAK

#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] =
    {
        .baseHP        = 75,
        .baseAttack    = 38,
        .baseDefense   = 38,
        .baseSpeed     = 67,
        .baseSpAttack  = 56,
        .baseSpDefense = 56,
        .types = MON_TYPES(TYPE_WATER, TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 90,
        .evYield_HP = 1,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_ILLUMINATE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Chinchou"),
        .cryId = CRY_CHINCHOU,
        .natDexNum = NATIONAL_DEX_CHINCHOU,
        .categoryName = _("Angler"),
        .height = 5,
        .weight = 120,
        .description = COMPOUND_STRING(
            "When it senses danger, it discharges\n"
            "positive and negative electricity from its\n"
            "two antennae. It lives in depths beyond\n"
            "sunlight's reach."),
        .pokemonScale = 424,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chinchou,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Chinchou,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 11,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Chinchou,
        .shinyPalette = gMonShinyPalette_Chinchou,
        .iconSprite = gMonIcon_Chinchou,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 1, SHADOW_SIZE_M)
        FOOTPRINT(Chinchou)
        OVERWORLD(
            sPicTable_Chinchou,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Chinchou,
            gShinyOverworldPalette_Chinchou
        )
        .levelUpLearnset = sChinchouLevelUpLearnset,
        .teachableLearnset = sChinchouTeachableLearnset,
        .eggMoveLearnset = sChinchouEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_LANTURN}),
    },

    [SPECIES_LANTURN] =
    {
        .baseHP        = 125,
        .baseAttack    = 58,
        .baseDefense   = 58,
        .baseSpeed     = 67,
        .baseSpAttack  = 76,
        .baseSpDefense = 76,
        .types = MON_TYPES(TYPE_WATER, TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 161 : 156,
        .evYield_HP = 2,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_ILLUMINATE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lanturn"),
        .cryId = CRY_LANTURN,
        .natDexNum = NATIONAL_DEX_LANTURN,
        .categoryName = _("Light"),
        .height = 12,
        .weight = 225,
        .description = COMPOUND_STRING(
            "The light-emitting orbs on its back are\n"
            "very bright. They are formed from a part of\n"
            "its dorsal fin. This Pokémon illuminates\n"
            "the inky darkness of deep seas."),
        .pokemonScale = 269,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lanturn,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .backPic = gMonBackPic_Lanturn,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Lanturn,
        .shinyPalette = gMonShinyPalette_Lanturn,
        .iconSprite = gMonIcon_Lanturn,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 4, SHADOW_SIZE_M)
        FOOTPRINT(Lanturn)
        OVERWORLD(
            sPicTable_Lanturn,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Lanturn,
            gShinyOverworldPalette_Lanturn
        )
        .levelUpLearnset = sLanturnLevelUpLearnset,
        .teachableLearnset = sLanturnTeachableLearnset,
    },
#endif //P_FAMILY_CHINCHOU

#if P_FAMILY_TOGEPI
#define TOGEPI_FAMILY_TYPE1 (P_UPDATED_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL)

    [SPECIES_TOGEPI] =
    {
        .baseHP        = 35,
        .baseAttack    = 20,
        .baseDefense   = 65,
        .baseSpeed     = 20,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        .types = MON_TYPES(TOGEPI_FAMILY_TYPE1),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 49 : 74,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_HUSTLE, ABILITY_SERENE_GRACE, ABILITY_SUPER_LUCK },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Togepi"),
        .cryId = CRY_TOGEPI,
        .natDexNum = NATIONAL_DEX_TOGEPI,
        .categoryName = _("Spike Ball"),
        .height = 3,
        .weight = 15,
        .description = COMPOUND_STRING(
            "As its energy, it uses the feelings of\n"
            "compassion and pleasure exuded by\n"
            "people and Pokémon. It stores up happy\n"
            "feelings in its shell, then shares them out."),
        .pokemonScale = 507,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Togepi,
        .frontPicSize = MON_COORDS_SIZE(24, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE : ANIM_V_JUMPS_BIG,
        .backPic = gMonBackPic_Togepi,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 12,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Togepi,
        .shinyPalette = gMonShinyPalette_Togepi,
        .iconSprite = gMonIcon_Togepi,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -3, SHADOW_SIZE_S)
        FOOTPRINT(Togepi)
        OVERWORLD(
            sPicTable_Togepi,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Togepi,
            gShinyOverworldPalette_Togepi
        )
        .levelUpLearnset = sTogepiLevelUpLearnset,
        .teachableLearnset = sTogepiTeachableLearnset,
        .eggMoveLearnset = sTogepiEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_TOGETIC, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },

    [SPECIES_TOGETIC] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 80,
        .baseSpDefense = 105,
        .types = MON_TYPES(TOGEPI_FAMILY_TYPE1, TYPE_FLYING),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 114,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HUSTLE, ABILITY_SERENE_GRACE, ABILITY_SUPER_LUCK },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Togetic"),
        .cryId = CRY_TOGETIC,
        .natDexNum = NATIONAL_DEX_TOGETIC,
        .categoryName = _("Happiness"),
        .height = 6,
        .weight = 32,
        .description = COMPOUND_STRING(
            "It is said to be a Pokémon that brings good\n"
            "fortune. When it spots someone who is pure\n"
            "of heart, a Togetic appears and shares its\n"
            "happiness with that person."),
        .pokemonScale = 424,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Togetic,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Togetic,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Togetic,
        .shinyPalette = gMonShinyPalette_Togetic,
        .iconSprite = gMonIcon_Togetic,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_S)
        FOOTPRINT(Togetic)
        OVERWORLD(
            sPicTable_Togetic,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Togetic,
            gShinyOverworldPalette_Togetic
        )
        .levelUpLearnset = sTogeticLevelUpLearnset,
        .teachableLearnset = sTogeticTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_TOGEKISS}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_TOGEKISS] =
    {
        .baseHP        = 85,
        .baseAttack    = 50,
        .baseDefense   = 95,
        .baseSpeed     = 80,
        .baseSpAttack  = 120,
        .baseSpDefense = 115,
        .types = MON_TYPES(TOGEPI_FAMILY_TYPE1, TYPE_FLYING),
        .catchRate = 30,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 273,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 245,
    #else
        .expYield = 220,
    #endif
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HUSTLE, ABILITY_SERENE_GRACE, ABILITY_SUPER_LUCK },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Togekiss"),
        .cryId = CRY_TOGEKISS,
        .natDexNum = NATIONAL_DEX_TOGEKISS,
        .categoryName = _("Jubilee"),
        .height = 15,
        .weight = 380,
        .description = COMPOUND_STRING(
            "As everyone knows, it visits peaceful\n"
            "regions, bringing them gifts of kindness\n"
            "and sweet blessings. It will never appear\n"
            "where there is strife."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Togekiss,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 14,
        .backPic = gMonBackPic_Togekiss,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Togekiss,
        .shinyPalette = gMonShinyPalette_Togekiss,
        .iconSprite = gMonIcon_Togekiss,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 15, SHADOW_SIZE_M)
        FOOTPRINT(Togekiss)
        OVERWORLD(
            sPicTable_Togekiss,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Togekiss,
            gShinyOverworldPalette_Togekiss
        )
        .levelUpLearnset = sTogekissLevelUpLearnset,
        .teachableLearnset = sTogekissTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_TOGEPI

#if P_FAMILY_NATU
    [SPECIES_NATU] =
    {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 64 : 73,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_EARLY_BIRD, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Natu"),
        .cryId = CRY_NATU,
        .natDexNum = NATIONAL_DEX_NATU,
        .categoryName = _("Tiny Bird"),
        .height = 2,
        .weight = 20,
        .description = COMPOUND_STRING(
            "It runs up short trees that grow on the\n"
            "savanna to peck at new shoots.\n"
            "A Natu's eyes look as if they are\n"
            "always observing something."),
        .pokemonScale = 610,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Natu,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_JUMPS,
        .frontAnimDelay = 30,
        .backPic = gMonBackPic_Natu,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(40, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Natu,
        .shinyPalette = gMonShinyPalette_Natu,
        .iconSprite = gMonIcon_Natu,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, -4, SHADOW_SIZE_S)
        FOOTPRINT(Natu)
        OVERWORLD(
            sPicTable_Natu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Natu,
            gShinyOverworldPalette_Natu
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sNatuLevelUpLearnset,
        .teachableLearnset = sNatuTeachableLearnset,
        .eggMoveLearnset = sNatuEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_XATU}),
    },

    [SPECIES_XATU] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 95,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 165 : 171,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_EARLY_BIRD, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Xatu"),
        .cryId = CRY_XATU,
        .natDexNum = NATIONAL_DEX_XATU,
        .categoryName = _("Mystic"),
        .height = 15,
        .weight = 150,
        .description = COMPOUND_STRING(
            "It has the enigmatic power of foreseeing\n"
            "the future. Some people in different lands\n"
            "have long believed that Xatu are\n"
            "emissaries from another world."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 318,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Xatu,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 56) : MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Xatu,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Xatu,
        .shinyPalette = gMonShinyPalette_Xatu,
        .iconSprite = gMonIcon_Xatu,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 1,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_XatuF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 56),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_S)
        FOOTPRINT(Xatu)
        OVERWORLD(
            sPicTable_Xatu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Xatu,
            gShinyOverworldPalette_Xatu
        )
        OVERWORLD_FEMALE(
            sPicTable_XatuF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sXatuLevelUpLearnset,
        .teachableLearnset = sXatuTeachableLearnset,
    },
#endif //P_FAMILY_NATU

#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 235,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 56 : 59,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_PLUS },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Mareep"),
        .cryId = CRY_MAREEP,
        .natDexNum = NATIONAL_DEX_MAREEP,
        .categoryName = _("Wool"),
        .height = 6,
        .weight = 78,
        .description = COMPOUND_STRING(
            "Its fluffy wool rubs together and builds\n"
            "a static charge. The more energy is\n"
            "charged, the more brightly the lightbulb\n"
            "at the tip of its tail glows."),
        .pokemonScale = 379,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mareep,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = 50,
        .backPic = gMonBackPic_Mareep,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Mareep,
        .shinyPalette = gMonShinyPalette_Mareep,
        .iconSprite = gMonIcon_Mareep,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 1, SHADOW_SIZE_M)
        FOOTPRINT(Mareep)
        OVERWORLD(
            sPicTable_Mareep,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mareep,
            gShinyOverworldPalette_Mareep
        )
        .levelUpLearnset = sMareepLevelUpLearnset,
        .teachableLearnset = sMareepTeachableLearnset,
        .eggMoveLearnset = sMareepEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_FLAAFFY}),
    },

    [SPECIES_FLAAFFY] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 45,
        .baseSpAttack  = 80,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 128 : 117,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_PLUS },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Flaaffy"),
        .cryId = CRY_FLAAFFY,
        .natDexNum = NATIONAL_DEX_FLAAFFY,
        .categoryName = _("Wool"),
        .height = 8,
        .weight = 133,
        .description = COMPOUND_STRING(
            "Its fleece quality changes to generate\n"
            "strong static electricity with a small\n"
            "amount of wool. The bare, slick parts of its\n"
            "hide are shielded against electricity."),
        .pokemonScale = 372,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Flaaffy,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_JUMPS_BIG : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Flaaffy,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 7,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Flaaffy,
        .shinyPalette = gMonShinyPalette_Flaaffy,
        .iconSprite = gMonIcon_Flaaffy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 4, SHADOW_SIZE_S)
        FOOTPRINT(Flaaffy)
        OVERWORLD(
            sPicTable_Flaaffy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Flaaffy,
            gShinyOverworldPalette_Flaaffy
        )
        .levelUpLearnset = sFlaaffyLevelUpLearnset,
        .teachableLearnset = sFlaaffyTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_AMPHAROS}),
    },

    [SPECIES_AMPHAROS] =
    {
        .baseHP        = 90,
        .baseAttack    = 75,
        .baseDefense   = P_UPDATED_STATS >= GEN_6 ? 85 : 75,
        .baseSpeed     = 55,
        .baseSpAttack  = 115,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 255,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 230,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 225,
    #else
        .expYield = 194,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_PLUS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Ampharos"),
        .cryId = CRY_AMPHAROS,
        .natDexNum = NATIONAL_DEX_AMPHAROS,
        .categoryName = _("Light"),
        .height = 14,
        .weight = 615,
        .description = COMPOUND_STRING(
            "It gives off so much light that it can be\n"
            "seen even from space. People in the old\n"
            "days used its light to send signals back\n"
            "and forth with others far away."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ampharos,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_FLASH_YELLOW,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Ampharos,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 3,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Ampharos,
        .shinyPalette = gMonShinyPalette_Ampharos,
        .iconSprite = gMonIcon_Ampharos,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 11, SHADOW_SIZE_M)
        FOOTPRINT(Ampharos)
        OVERWORLD(
            sPicTable_Ampharos,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ampharos,
            gShinyOverworldPalette_Ampharos
        )
        .levelUpLearnset = sAmpharosLevelUpLearnset,
        .teachableLearnset = sAmpharosTeachableLearnset,
        .formSpeciesIdTable = sAmpharosFormSpeciesIdTable,
        .formChangeTable = sAmpharosFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_AMPHAROS_MEGA] =
    {
        .baseHP        = 90,
        .baseAttack    = 95,
        .baseDefense   = 105,
        .baseSpeed     = 45,
        .baseSpAttack  = 165,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 305 : 275,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_MOLD_BREAKER, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Ampharos"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_AMPHAROS_MEGA,
    #else
        .cryId = CRY_AMPHAROS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_AMPHAROS,
        .categoryName = _("Light"),
        .height = 14,
        .weight = 615,
        .description = COMPOUND_STRING(
            "Massive amounts of energy intensely\n"
            "stimulated Ampharos's cells, apparently\n"
            "awakening its long-sleeping dragon's\n"
            "blood."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AmpharosMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AmpharosMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_AmpharosMega,
        .shinyPalette = gMonShinyPalette_AmpharosMega,
        .iconSprite = gMonIcon_AmpharosMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 13, SHADOW_SIZE_M)
        FOOTPRINT(Ampharos)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_AmpharosMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_AmpharosMega,
            gShinyOverworldPalette_AmpharosMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAmpharosLevelUpLearnset,
        .teachableLearnset = sAmpharosTeachableLearnset,
        .formSpeciesIdTable = sAmpharosFormSpeciesIdTable,
        .formChangeTable = sAmpharosFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_MAREEP

#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
    [SPECIES_AZURILL] =
    {
        .baseHP        = 50,
        .baseAttack    = 20,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 20,
        .baseSpDefense = 40,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_NORMAL),
    #endif
        .catchRate = 150,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 38 : 33,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_THICK_FAT, ABILITY_HUGE_POWER, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Azurill"),
        .cryId = CRY_AZURILL,
        .natDexNum = NATIONAL_DEX_AZURILL,
        .categoryName = _("Polka Dot"),
        .height = 2,
        .weight = 20,
        .description = COMPOUND_STRING(
            "Its tail, which is packed with nutrition,\n"
            "is very bouncy like a rubber ball. On sunny\n"
            "days they gather at the edge of water and\n"
            "splash about for fun."),
        .pokemonScale = 603,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Azurill,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Azurill,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Azurill,
        .shinyPalette = gMonShinyPalette_Azurill,
        .iconSprite = gMonIcon_Azurill,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-4, 3, SHADOW_SIZE_S)
        FOOTPRINT(Azurill)
        OVERWORLD(
            sPicTable_Azurill,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Azurill,
            gShinyOverworldPalette_Azurill
        )
        .levelUpLearnset = sAzurillLevelUpLearnset,
        .teachableLearnset = sAzurillTeachableLearnset,
        .eggMoveLearnset = sAzurillEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_MARILL, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },
#endif //P_GEN_3_CROSS_EVOS

    [SPECIES_MARILL] =
    {
        .baseHP        = 70,
        .baseAttack    = 20,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 20,
        .baseSpDefense = 50,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_WATER, TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_WATER),
    #endif
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 88 : 58,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_THICK_FAT, ABILITY_HUGE_POWER, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Marill"),
        .cryId = CRY_MARILL,
        .natDexNum = NATIONAL_DEX_MARILL,
        .categoryName = _("Aqua Mouse"),
        .height = 4,
        .weight = 85,
        .description = COMPOUND_STRING(
            "Its body is covered with water-repellent\n"
            "fur. Because of the fur, it can swim\n"
            "through water at high speed without being\n"
            "slowed by the water's resistance."),
        .pokemonScale = 476,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Marill,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Marill,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Marill,
        .shinyPalette = gMonShinyPalette_Marill,
        .iconSprite = gMonIcon_Marill,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Marill)
        OVERWORLD(
            sPicTable_Marill,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Marill,
            gShinyOverworldPalette_Marill
        )
        .levelUpLearnset = sMarillLevelUpLearnset,
        .teachableLearnset = sMarillTeachableLearnset,
        .eggMoveLearnset = sMarillEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_AZUMARILL}),
    },

    [SPECIES_AZUMARILL] =
    {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_6 ? 60 : 50,
        .baseSpDefense = 80,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_WATER, TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_WATER),
    #endif
        .catchRate = 75,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 210,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 189,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 185,
    #else
        .expYield = 153,
    #endif
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_THICK_FAT, ABILITY_HUGE_POWER, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Azumarill"),
        .cryId = CRY_AZUMARILL,
        .natDexNum = NATIONAL_DEX_AZUMARILL,
        .categoryName = _("Aqua Rabbit"),
        .height = 8,
        .weight = 285,
        .description = COMPOUND_STRING(
            "It lives in water virtually all day long.\n"
            "Its body color and pattern act as\n"
            "camouflage that makes it tough for\n"
            "enemies to spot in water."),
        .pokemonScale = 448,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Azumarill,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW : ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Azumarill,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 3,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Azumarill,
        .shinyPalette = gMonShinyPalette_Azumarill,
        .iconSprite = gMonIcon_Azumarill,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 8, SHADOW_SIZE_S)
        FOOTPRINT(Azumarill)
        OVERWORLD(
            sPicTable_Azumarill,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Azumarill,
            gShinyOverworldPalette_Azumarill
        )
        .levelUpLearnset = sAzumarillLevelUpLearnset,
        .teachableLearnset = sAzumarillTeachableLearnset,
    },
#endif //P_FAMILY_MARILL

#if P_FAMILY_SUDOWOODO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BONSLY] =
    {
        .baseHP        = 50,
        .baseAttack    = 80,
        .baseDefense   = 95,
        .baseSpeed     = 10,
        .baseSpAttack  = 10,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 68,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STURDY, ABILITY_ROCK_HEAD, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bonsly"),
        .cryId = CRY_BONSLY,
        .natDexNum = NATIONAL_DEX_BONSLY,
        .categoryName = _("Bonsai"),
        .height = 5,
        .weight = 150,
        .description = COMPOUND_STRING(
            "Bonsly prefers an arid atmosphere.\n"
            "In order to adjust the level of fluids\n"
            "in its body, it exudes water from its eyes.\n"
            "This makes it appear to be crying."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bonsly,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .backPic = gMonBackPic_Bonsly,
        .backPicSize = MON_COORDS_SIZE(40, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Bonsly,
        .shinyPalette = gMonShinyPalette_Bonsly,
        .iconSprite = gMonIcon_Bonsly,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-3, 4, SHADOW_SIZE_S)
        FOOTPRINT(Bonsly)
        OVERWORLD(
            sPicTable_Bonsly,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bonsly,
            gShinyOverworldPalette_Bonsly
        )
        .levelUpLearnset = sBonslyLevelUpLearnset,
        .teachableLearnset = sBonslyTeachableLearnset,
        .eggMoveLearnset = sBonslyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_SUDOWOODO, CONDITIONS({IF_KNOWS_MOVE, MOVE_MIMIC})}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_SUDOWOODO] =
    {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 65,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 144 : 135,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STURDY, ABILITY_ROCK_HEAD, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Sudowoodo"),
        .cryId = CRY_SUDOWOODO,
        .natDexNum = NATIONAL_DEX_SUDOWOODO,
        .categoryName = _("Imitation"),
        .height = 12,
        .weight = 380,
        .description = COMPOUND_STRING(
            "It mimics a tree to avoid being attacked\n"
            "by enemies. But since its forelegs\n"
            "remain green throughout the year, it is\n"
            "easily identified as a fake in the winter."),
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sudowoodo,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Sudowoodo,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Sudowoodo,
        .shinyPalette = gMonShinyPalette_Sudowoodo,
        .iconSprite = gMonIcon_Sudowoodo,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SudowoodoF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 56),
        .backPicFemale = gMonBackPic_SudowoodoF,
        .backPicSizeFemale = MON_COORDS_SIZE(48, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 7, SHADOW_SIZE_S)
        FOOTPRINT(Sudowoodo)
        OVERWORLD(
            sPicTable_Sudowoodo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sudowoodo,
            gShinyOverworldPalette_Sudowoodo
        )
        OVERWORLD_FEMALE(
            sPicTable_SudowoodoF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sSudowoodoLevelUpLearnset,
        .teachableLearnset = sSudowoodoTeachableLearnset,
        .eggMoveLearnset = sSudowoodoEggMoveLearnset,
    },
#endif //P_FAMILY_SUDOWOODO

#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] =
    {
        .baseHP        = 35,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 35,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 50 : 74,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_INFILTRATOR },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_INFILTRATOR },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Hoppip"),
        .cryId = CRY_HOPPIP,
        .natDexNum = NATIONAL_DEX_HOPPIP,
        .categoryName = _("Cottonweed"),
        .height = 4,
        .weight = 5,
        .description = COMPOUND_STRING(
            "This Pokémon drifts and floats with the\n"
            "wind. If it senses the approach of strong\n"
            "winds, a Hoppip links leaves with others\n"
            "to prepare against being blown away."),
        .pokemonScale = 562,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hoppip,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 11 : 15,
        .backPic = gMonBackPic_Hoppip,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Hoppip,
        .shinyPalette = gMonShinyPalette_Hoppip,
        .iconSprite = gMonIcon_Hoppip,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 12, SHADOW_SIZE_S)
        FOOTPRINT(Hoppip)
        OVERWORLD(
            sPicTable_Hoppip,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Hoppip,
            gShinyOverworldPalette_Hoppip
        )
        .levelUpLearnset = sHoppipLevelUpLearnset,
        .teachableLearnset = sHoppipTeachableLearnset,
        .eggMoveLearnset = sHoppipEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_SKIPLOOM}),
    },

    [SPECIES_SKIPLOOM] =
    {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FLYING),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 119 : 136,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_INFILTRATOR },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_INFILTRATOR },
    #endif
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Skiploom"),
        .cryId = CRY_SKIPLOOM,
        .natDexNum = NATIONAL_DEX_SKIPLOOM,
        .categoryName = _("Cottonweed"),
        .height = 6,
        .weight = 10,
        .description = COMPOUND_STRING(
            "It blossoms when the temperature rises\n"
            "above 64 degrees F. Because its flower's\n"
            "blooming changes with the temperature,\n"
            "it is sometimes used as a thermometer."),
        .pokemonScale = 387,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Skiploom,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 12 : 15,
        .backPic = gMonBackPic_Skiploom,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 4,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Skiploom,
        .shinyPalette = gMonShinyPalette_Skiploom,
        .iconSprite = gMonIcon_Skiploom,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 10, SHADOW_SIZE_S)
        FOOTPRINT(Skiploom)
        OVERWORLD(
            sPicTable_Skiploom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Skiploom,
            gShinyOverworldPalette_Skiploom
        )
        .levelUpLearnset = sSkiploomLevelUpLearnset,
        .teachableLearnset = sSkiploomTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_JUMPLUFF}),
    },

    [SPECIES_JUMPLUFF] =
    {
        .baseHP        = 75,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 110,
        .baseSpAttack  = 55,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 230,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 207,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 203,
    #else
        .expYield = 176,
    #endif
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_INFILTRATOR },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_INFILTRATOR },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Jumpluff"),
        .cryId = CRY_JUMPLUFF,
        .natDexNum = NATIONAL_DEX_JUMPLUFF,
        .categoryName = _("Cottonweed"),
        .height = 8,
        .weight = 30,
        .description = COMPOUND_STRING(
            "Jumpluff ride warm southern winds to\n"
            "cross the sea and fly to foreign lands.\n"
            "This Pokémon lands when it encounters\n"
            "cold air while it is floating."),
        .pokemonScale = 418,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Jumpluff,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 9,
        .backPic = gMonBackPic_Jumpluff,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Jumpluff,
        .shinyPalette = gMonShinyPalette_Jumpluff,
        .iconSprite = gMonIcon_Jumpluff,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 11, SHADOW_SIZE_S)
        FOOTPRINT(Jumpluff)
        OVERWORLD(
            sPicTable_Jumpluff,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Jumpluff,
            gShinyOverworldPalette_Jumpluff
        )
        .levelUpLearnset = sJumpluffLevelUpLearnset,
        .teachableLearnset = sJumpluffTeachableLearnset,
    },
#endif //P_FAMILY_HOPPIP

#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] =
    {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 40,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 72 : 94,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_PICKUP, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Aipom"),
        .cryId = CRY_AIPOM,
        .natDexNum = NATIONAL_DEX_AIPOM,
        .categoryName = _("Long Tail"),
        .height = 8,
        .weight = 115,
        .description = COMPOUND_STRING(
            "Its tail ends with a dexterous, handlike\n"
            "appendage. However, because it uses the\n"
            "tail so much, Aipom's real hands have\n"
            "become rather clumsy."),
        .pokemonScale = 363,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Aipom,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 64) : MON_COORDS_SIZE(32, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Aipom,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Aipom,
        .shinyPalette = gMonShinyPalette_Aipom,
        .iconSprite = gMonIcon_Aipom,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_AipomF,
        .frontPicSizeFemale = MON_COORDS_SIZE(32, 64),
        .backPicFemale = gMonBackPic_AipomF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_S)
        FOOTPRINT(Aipom)
        OVERWORLD(
            sPicTable_Aipom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Aipom,
            gShinyOverworldPalette_Aipom
        )
        OVERWORLD_FEMALE(
            sPicTable_AipomF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sAipomLevelUpLearnset,
        .teachableLearnset = sAipomTeachableLearnset,
        .eggMoveLearnset = sAipomEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_AMBIPOM, CONDITIONS({IF_KNOWS_MOVE, MOVE_DOUBLE_HIT})}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_AMBIPOM] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 66,
        .baseSpeed     = 115,
        .baseSpAttack  = 60,
        .baseSpDefense = 66,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 169 : 186,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 100,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TECHNICIAN, ABILITY_PICKUP, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Ambipom"),
        .cryId = CRY_AMBIPOM,
        .natDexNum = NATIONAL_DEX_AMBIPOM,
        .categoryName = _("Long Tail"),
        .height = 12,
        .weight = 203,
        .description = COMPOUND_STRING(
            "They live on large trees. Split into two,\n"
            "the tails are so adept at handling and\n"
            "doing things, Ambipom rarely uses\n"
            "its hands now."),
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ambipom,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Ambipom,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Ambipom,
        .shinyPalette = gMonShinyPalette_Ambipom,
        .iconSprite = gMonIcon_Ambipom,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_AmbipomF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_AmbipomF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_S)
        FOOTPRINT(Ambipom)
        OVERWORLD(
            sPicTable_Ambipom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ambipom,
            gShinyOverworldPalette_Ambipom
        )
        OVERWORLD_FEMALE(
            sPicTable_AmbipomF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sAmbipomLevelUpLearnset,
        .teachableLearnset = sAmbipomTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_AIPOM

#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] =
    {
        .baseHP        = 30,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 235,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 36 : 52,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SOLAR_POWER, ABILITY_EARLY_BIRD },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_EARLY_BIRD },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Sunkern"),
        .cryId = CRY_SUNKERN,
        .natDexNum = NATIONAL_DEX_SUNKERN,
        .categoryName = _("Seed"),
        .height = 3,
        .weight = 18,
        .description = COMPOUND_STRING(
            "Sunkern try to minimize movement to\n"
            "conserve the nutrients they have stored\n"
            "in their bodies for evolution. They will\n"
            "not eat, subsisting only on morning dew."),
        .pokemonScale = 541,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sunkern,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 32) : MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_JUMPS_SMALL : ANIM_H_JUMPS,
        .backPic = gMonBackPic_Sunkern,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Sunkern,
        .shinyPalette = gMonShinyPalette_Sunkern,
        .iconSprite = gMonIcon_Sunkern,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -4, SHADOW_SIZE_S)
        FOOTPRINT(Sunkern)
        OVERWORLD(
            sPicTable_Sunkern,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Sunkern,
            gShinyOverworldPalette_Sunkern
        )
        .levelUpLearnset = sSunkernLevelUpLearnset,
        .teachableLearnset = sSunkernTeachableLearnset,
        .eggMoveLearnset = sSunkernEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_SUNFLORA}),
    },

    [SPECIES_SUNFLORA] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 105,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 149 : 146,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SOLAR_POWER, ABILITY_EARLY_BIRD },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_EARLY_BIRD },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Sunflora"),
        .cryId = CRY_SUNFLORA,
        .natDexNum = NATIONAL_DEX_SUNFLORA,
        .categoryName = _("Sun"),
        .height = 8,
        .weight = 85,
        .description = COMPOUND_STRING(
            "Sunflora convert solar energy into\n"
            "nutrition. They are highly active in the\n"
            "warm daytime but suddenly stop moving as\n"
            "soon as the sun sets."),
        .pokemonScale = 444,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sunflora,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sunflora,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Sunflora,
        .shinyPalette = gMonShinyPalette_Sunflora,
        .iconSprite = gMonIcon_Sunflora,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_S)
        FOOTPRINT(Sunflora)
        OVERWORLD(
            sPicTable_Sunflora,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sunflora,
            gShinyOverworldPalette_Sunflora
        )
        .levelUpLearnset = sSunfloraLevelUpLearnset,
        .teachableLearnset = sSunfloraTeachableLearnset,
    },
#endif //P_FAMILY_SUNKERN

#if P_FAMILY_YANMA
    [SPECIES_YANMA] =
    {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 78 : 147,
        .evYield_Speed = (P_UPDATED_EVS >= GEN_4) ? 1 : 2,
        .itemRare = ITEM_WIDE_LENS,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SPEED_BOOST, ABILITY_COMPOUND_EYES, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Yanma"),
        .cryId = CRY_YANMA,
        .natDexNum = NATIONAL_DEX_YANMA,
        .categoryName = _("Clear Wing"),
        .height = 12,
        .weight = 380,
        .description = COMPOUND_STRING(
            "It can see 360 degrees without moving\n"
            "its eyes. It is a great flier capable of\n"
            "making sudden stops and turning midair to\n"
            "quickly chase down targeted prey."),
        .pokemonScale = 274,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Yanma,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 20),
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
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 13,
        .backPic = gMonBackPic_Yanma,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Yanma,
        .shinyPalette = gMonShinyPalette_Yanma,
        .iconSprite = gMonIcon_Yanma,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 10, SHADOW_SIZE_S)
        FOOTPRINT(Yanma)
        OVERWORLD(
            sPicTable_Yanma,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Yanma,
            gShinyOverworldPalette_Yanma
        )
        .levelUpLearnset = sYanmaLevelUpLearnset,
        .teachableLearnset = sYanmaTeachableLearnset,
        .eggMoveLearnset = sYanmaEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_YANMEGA, CONDITIONS({IF_KNOWS_MOVE, MOVE_ANCIENT_POWER})}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_YANMEGA] =
    {
        .baseHP        = 86,
        .baseAttack    = 76,
        .baseDefense   = 86,
        .baseSpeed     = 95,
        .baseSpAttack  = 116,
        .baseSpDefense = 56,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 180 : 198,
        .evYield_Attack = 2,
        .itemRare = ITEM_WIDE_LENS,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SPEED_BOOST, ABILITY_TINTED_LENS, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Yanmega"),
        .cryId = CRY_YANMEGA,
        .natDexNum = NATIONAL_DEX_YANMEGA,
        .categoryName = _("Ogre Darner"),
        .height = 19,
        .weight = 515,
        .description = COMPOUND_STRING(
            "This six-legged Pokémon is easily capable\n"
            "of transporting an adult in flight. It is\n"
            "adept at biting apart foes while flying\n"
            "by at high speed."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Yanmega,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
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
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Yanmega,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Yanmega,
        .shinyPalette = gMonShinyPalette_Yanmega,
        .iconSprite = gMonIcon_Yanmega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Yanmega)
        OVERWORLD(
            sPicTable_Yanmega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Yanmega,
            gShinyOverworldPalette_Yanmega
        )
        .levelUpLearnset = sYanmegaLevelUpLearnset,
        .teachableLearnset = sYanmegaTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_YANMA

#if P_FAMILY_WOOPER
    [SPECIES_WOOPER] =
    {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 42 : 52,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_DAMP, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Wooper"),
        .cryId = CRY_WOOPER,
        .natDexNum = NATIONAL_DEX_WOOPER,
        .categoryName = _("Water Fish"),
        .height = 4,
        .weight = 85,
        .description = COMPOUND_STRING(
            "Wooper usually live in water but come\n"
            "out onto land seeking food occasionally.\n"
            "On land, they coat their bodies with a\n"
            "gooey, toxic film."),
        .pokemonScale = 479,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wooper,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Wooper,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Wooper,
        .shinyPalette = gMonShinyPalette_Wooper,
        .iconSprite = gMonIcon_Wooper,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_WooperF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 32),
        .backPicFemale = gMonBackPic_WooperF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 40),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Wooper)
        OVERWORLD(
            sPicTable_Wooper,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wooper,
            gShinyOverworldPalette_Wooper
        )
        OVERWORLD_FEMALE(
            sPicTable_WooperF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sWooperLevelUpLearnset,
        .teachableLearnset = sWooperTeachableLearnset,
        .eggMoveLearnset = sWooperEggMoveLearnset,
        .formSpeciesIdTable = sWooperFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_QUAGSIRE}),
    },

    [SPECIES_QUAGSIRE] =
    {
        .baseHP        = 95,
        .baseAttack    = 85,
        .baseDefense   = 85,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 151 : 137,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_DAMP, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Quagsire"),
        .cryId = CRY_QUAGSIRE,
        .natDexNum = NATIONAL_DEX_QUAGSIRE,
        .categoryName = _("Water Fish"),
        .height = 14,
        .weight = 750,
        .description = COMPOUND_STRING(
            "A Quagsire hunts by leaving its mouth wide\n"
            "open in water and waiting for its prey to\n"
            "blunder in. Because it doesn't move, it\n"
            "does not get very hungry."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Quagsire,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Quagsire,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Quagsire,
        .shinyPalette = gMonShinyPalette_Quagsire,
        .iconSprite = gMonIcon_Quagsire,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_QuagsireF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_QuagsireF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_M)
        FOOTPRINT(Quagsire)
        OVERWORLD(
            sPicTable_Quagsire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Quagsire,
            gShinyOverworldPalette_Quagsire
        )
        OVERWORLD_FEMALE(
            sPicTable_QuagsireF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sQuagsireLevelUpLearnset,
        .teachableLearnset = sQuagsireTeachableLearnset,
    },

#if P_PALDEAN_FORMS
    [SPECIES_WOOPER_PALDEA] =
    {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_POISON, TYPE_GROUND),
        .catchRate = 255,
        .expYield = 42,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_POISON_POINT, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Wooper"),
        .cryId = CRY_WOOPER,
        .natDexNum = NATIONAL_DEX_WOOPER,
        .categoryName = _("Poison Fish"),
        .height = 4,
        .weight = 110,
        .description = COMPOUND_STRING(
            "After losing a territorial struggle,\n"
            "Wooper began living on land.\n"
            "The Pokémon changed over time, developing\n"
            "a poisonous film to protect its body."),
        .pokemonScale = 479,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_WooperPaldea,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_WooperPaldea,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_WooperPaldea,
        .shinyPalette = gMonShinyPalette_WooperPaldea,
        .iconSprite = gMonIcon_WooperPaldea,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Wooper)
        OVERWORLD(
            sPicTable_WooperPaldea,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_WooperPaldea,
            gShinyOverworldPalette_WooperPaldea
        )
        .isPaldeanForm = TRUE,
        .levelUpLearnset = sWooperPaldeaLevelUpLearnset,
        .teachableLearnset = sWooperPaldeaTeachableLearnset,
        .eggMoveLearnset = sWooperPaldeaEggMoveLearnset,
        .formSpeciesIdTable = sWooperFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_CLODSIRE}),
    },

    [SPECIES_CLODSIRE] =
    {
        .baseHP        = 130,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 20,
        .baseSpAttack  = 45,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_POISON, TYPE_GROUND),
        .catchRate = 90,
        .expYield = 151,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_POISON_POINT, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Clodsire"),
        .cryId = CRY_CLODSIRE,
        .natDexNum = NATIONAL_DEX_CLODSIRE,
        .categoryName = _("Spiny Fish"),
        .height = 18,
        .weight = 2230,
        .description = COMPOUND_STRING(
            "When attacked, this Pokémon will\n"
            "retaliate by sticking thick spines out\n"
            "from its body. It's a risky move\n"
            "that puts everything on the line."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Clodsire,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Clodsire,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Clodsire,
        .shinyPalette = gMonShinyPalette_Clodsire,
        .iconSprite = gMonIcon_Clodsire,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 3, SHADOW_SIZE_L)
        FOOTPRINT(Clodsire)
        OVERWORLD(
            sPicTable_Clodsire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Clodsire,
            gShinyOverworldPalette_Clodsire
        )
        .levelUpLearnset = sClodsireLevelUpLearnset,
        .teachableLearnset = sClodsireTeachableLearnset,
    },
#endif //P_PALDEAN_FORMS
#endif //P_FAMILY_WOOPER

#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 42,
        .baseSpeed     = 91,
        .baseSpAttack  = 85,
        .baseSpDefense = 42,
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 81 : 107,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INSOMNIA, ABILITY_SUPER_LUCK, ABILITY_PRANKSTER },
    #else
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_PRANKSTER },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Murkrow"),
        .cryId = CRY_MURKROW,
        .natDexNum = NATIONAL_DEX_MURKROW,
        .categoryName = _("Darkness"),
        .height = 5,
        .weight = 21,
        .description = COMPOUND_STRING(
            "Murkrow were feared as the alleged\n"
            "bearers of ill fortune. It shows strong\n"
            "interest in anything that sparkles. It will\n"
            "even try to steal rings from women."),
        .pokemonScale = 401,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Murkrow,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 0 : 12,
        .backPic = gMonBackPic_Murkrow,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Murkrow,
        .shinyPalette = gMonShinyPalette_Murkrow,
        .iconSprite = gMonIcon_Murkrow,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_MurkrowF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 40),
        .backPicFemale = gMonBackPic_MurkrowF,
        .backPicSizeFemale = MON_COORDS_SIZE(40, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_S)
        FOOTPRINT(Murkrow)
        OVERWORLD(
            sPicTable_Murkrow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Murkrow,
            gShinyOverworldPalette_Murkrow
        )
        OVERWORLD_FEMALE(
            sPicTable_MurkrowF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sMurkrowLevelUpLearnset,
        .teachableLearnset = sMurkrowTeachableLearnset,
        .eggMoveLearnset = sMurkrowEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_HONCHKROW}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_HONCHKROW] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 52,
        .baseSpeed     = 71,
        .baseSpAttack  = 105,
        .baseSpDefense = 52,
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 177 : 187,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INSOMNIA, ABILITY_SUPER_LUCK, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Honchkrow"),
        .cryId = CRY_HONCHKROW,
        .natDexNum = NATIONAL_DEX_HONCHKROW,
        .categoryName = _("Big Boss"),
        .height = 9,
        .weight = 273,
        .description = COMPOUND_STRING(
            "Becoming active at night, it is known\n"
            "to swarm with numerous Murkrow in tow.\n"
            "It is said that it never forgives the\n"
            "mistakes of its cronies."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Honchkrow,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 21),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Honchkrow,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Honchkrow,
        .shinyPalette = gMonShinyPalette_Honchkrow,
        .iconSprite = gMonIcon_Honchkrow,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 7, SHADOW_SIZE_M)
        FOOTPRINT(Honchkrow)
        OVERWORLD(
            sPicTable_Honchkrow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Honchkrow,
            gShinyOverworldPalette_Honchkrow
        )
        .levelUpLearnset = sHonchkrowLevelUpLearnset,
        .teachableLearnset = sHonchkrowTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MURKROW

#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 87 : 147,
        .evYield_SpAttack = (P_UPDATED_EVS >= GEN_4) ? 0 : 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Misdreavus"),
        .cryId = CRY_MISDREAVUS,
        .natDexNum = NATIONAL_DEX_MISDREAVUS,
        .categoryName = _("Screech"),
        .height = 7,
        .weight = 10,
        .description = COMPOUND_STRING(
            "A Misdreavus frightens people with a\n"
            "creepy, sobbing cry. It apparently uses\n"
            "its red spheres to absorb the fear of foes\n"
            "as its nutrition."),
        .pokemonScale = 407,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Misdreavus,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
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
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 12,
        .backPic = gMonBackPic_Misdreavus,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Misdreavus,
        .shinyPalette = gMonShinyPalette_Misdreavus,
        .iconSprite = gMonIcon_Misdreavus,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_S)
        FOOTPRINT(Misdreavus)
        OVERWORLD(
            sPicTable_Misdreavus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Misdreavus,
            gShinyOverworldPalette_Misdreavus
        )
        .levelUpLearnset = sMisdreavusLevelUpLearnset,
        .teachableLearnset = sMisdreavusTeachableLearnset,
        .eggMoveLearnset = sMisdreavusEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_MISMAGIUS}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_MISMAGIUS] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 105,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 173 : 187,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mismagius"),
        .cryId = CRY_MISMAGIUS,
        .natDexNum = NATIONAL_DEX_MISMAGIUS,
        .categoryName = _("Magical"),
        .height = 9,
        .weight = 44,
        .description = COMPOUND_STRING(
            "Its cries sound like incantations.\n"
            "Those hearing it are tormented by\n"
            "headaches and hallucinations.\n"
            "It appears where you least expect it."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mismagius,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
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
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 3,
        .backPic = gMonBackPic_Mismagius,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Mismagius,
        .shinyPalette = gMonShinyPalette_Mismagius,
        .iconSprite = gMonIcon_Mismagius,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_M)
        FOOTPRINT(Mismagius)
        OVERWORLD(
            sPicTable_Mismagius,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mismagius,
            gShinyOverworldPalette_Mismagius
        )
        .levelUpLearnset = sMismagiusLevelUpLearnset,
        .teachableLearnset = sMismagiusTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MISDREAVUS

#if P_FAMILY_UNOWN
#define UNOWN_MISC_INFO(letter, _noFlip, frontWidth, frontHeight, backWidth, backHeight, backYOffset)   \
    {                                                                                                   \
        .baseHP        = 48,                                                                            \
        .baseAttack    = 72,                                                                            \
        .baseDefense   = 48,                                                                            \
        .baseSpeed     = 48,                                                                            \
        .baseSpAttack  = 72,                                                                            \
        .baseSpDefense = 48,                                                                            \
        .types = MON_TYPES(TYPE_PSYCHIC),                                                               \
        .catchRate = 225,                                                                               \
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 118 : 61,                                         \
        .evYield_Attack = 1,                                                                            \
        .evYield_SpAttack = 1,                                                                          \
        .genderRatio = MON_GENDERLESS,                                                                  \
        .eggCycles = 40,                                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                                               \
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),                                      \
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },                                  \
        .bodyColor = BODY_COLOR_BLACK,                                                                  \
        .noFlip = _noFlip,                                                                              \
        .speciesName = _("Unown"),                                                                      \
        .cryId = CRY_UNOWN,                                                                             \
        .natDexNum = NATIONAL_DEX_UNOWN,                                                                \
        .categoryName = _("Symbol"),                                                                    \
        .height = 5,                                                                                    \
        .weight = 50,                                                                                   \
        .description = gUnownPokedexText,                                                               \
        .pokemonScale = 411,                                                                            \
        .pokemonOffset = 2,                                                                             \
        .trainerScale = 256,                                                                            \
        .trainerOffset = 0,                                                                             \
        .frontPic = gMonFrontPic_Unown ##letter,                                                        \
        .frontPicSize = MON_COORDS_SIZE(frontWidth, frontHeight),                                       \
        .frontPicYOffset = 16,                                                                          \
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,                                               \
        .frontAnimId = ANIM_ZIGZAG_FAST,                                                                \
        .enemyMonElevation = 8,                                                                         \
        .backPic = gMonBackPic_Unown ##letter,                                                          \
        .backPicSize = MON_COORDS_SIZE(backWidth, backHeight),                                          \
        .backPicYOffset = backYOffset,                                                                  \
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,                                                    \
        .palette = gMonPalette_Unown,                                                                   \
        .shinyPalette = gMonShinyPalette_Unown,                                                         \
        .iconSprite = gMonIcon_Unown ##letter,                                                          \
        .iconPalIndex = 0,                                                                              \
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,                                                         \
        SHADOW(0, 3, SHADOW_SIZE_S)                                                                     \
        FOOTPRINT(Unown)                                                                                \
        OVERWORLD(                                                                                      \
            sPicTable_Unown ##letter,                                                                   \
            SIZE_32x32,                                                                                 \
            SHADOW_SIZE_M,                                                                              \
            TRACKS_NONE,                                                                                \
            sAnimTable_Following,                                                                       \
            gOverworldPalette_Unown,                                                                    \
            gShinyOverworldPalette_Unown,                                                               \
        )                                                                                               \
        .teachingType = TM_ILLITERATE,                                                                  \
        .levelUpLearnset = sUnownLevelUpLearnset,                                                       \
        .teachableLearnset = sUnownTeachableLearnset,                                                   \
        .formSpeciesIdTable = sUnownFormSpeciesIdTable,                                                 \
    }

    [SPECIES_UNOWN]             = UNOWN_MISC_INFO(A,           FALSE, 24, 40, 24, 48,  8 ),
    [SPECIES_UNOWN_B]           = UNOWN_MISC_INFO(B,           TRUE,  24, 32, 40, 48,  9 ),
    [SPECIES_UNOWN_C]           = UNOWN_MISC_INFO(C,           TRUE,  32, 32, 48, 56,  6 ),
    [SPECIES_UNOWN_D]           = UNOWN_MISC_INFO(D,           TRUE,  32, 32, 40, 48,  8 ),
    [SPECIES_UNOWN_E]           = UNOWN_MISC_INFO(E,           TRUE,  32, 32, 40, 48, 10 ),
    [SPECIES_UNOWN_F]           = UNOWN_MISC_INFO(F,           TRUE,  32, 32, 48, 48, 10 ),
    [SPECIES_UNOWN_G]           = UNOWN_MISC_INFO(G,           TRUE,  24, 40, 40, 56,  5 ),
    [SPECIES_UNOWN_H]           = UNOWN_MISC_INFO(H,           TRUE,  32, 32, 48, 48,  8 ),
    [SPECIES_UNOWN_I]           = UNOWN_MISC_INFO(I,           FALSE, 24, 32, 24, 56,  7 ),
    [SPECIES_UNOWN_J]           = UNOWN_MISC_INFO(J,           TRUE,  24, 32, 32, 48,  9 ),
    [SPECIES_UNOWN_K]           = UNOWN_MISC_INFO(K,           TRUE,  32, 32, 40, 56,  7 ),
    [SPECIES_UNOWN_L]           = UNOWN_MISC_INFO(L,           TRUE,  24, 32, 32, 48, 10 ),
    [SPECIES_UNOWN_M]           = UNOWN_MISC_INFO(M,           FALSE, 32, 32, 48, 40, 13 ),
    [SPECIES_UNOWN_N]           = UNOWN_MISC_INFO(N,           TRUE,  32, 24, 48, 40, 13 ),
    [SPECIES_UNOWN_O]           = UNOWN_MISC_INFO(O,           FALSE, 32, 32, 48, 48,  8 ),
    [SPECIES_UNOWN_P]           = UNOWN_MISC_INFO(P,           TRUE,  24, 32, 32, 48, 10 ),
    [SPECIES_UNOWN_Q]           = UNOWN_MISC_INFO(Q,           TRUE,  32, 24, 40, 40, 15 ),
    [SPECIES_UNOWN_R]           = UNOWN_MISC_INFO(R,           TRUE,  24, 32, 32, 40, 12 ),
    [SPECIES_UNOWN_S]           = UNOWN_MISC_INFO(S,           TRUE,  32, 40, 40, 56,  4 ),
    [SPECIES_UNOWN_T]           = UNOWN_MISC_INFO(T,           FALSE, 24, 32, 32, 40, 13 ),
    [SPECIES_UNOWN_U]           = UNOWN_MISC_INFO(U,           FALSE, 32, 32, 48, 40, 13 ),
    [SPECIES_UNOWN_V]           = UNOWN_MISC_INFO(V,           TRUE,  32, 32, 40, 48, 11 ),
    [SPECIES_UNOWN_W]           = UNOWN_MISC_INFO(W,           FALSE, 32, 32, 40, 40, 13 ),
    [SPECIES_UNOWN_X]           = UNOWN_MISC_INFO(X,           FALSE, 24, 24, 40, 40, 15 ),
    [SPECIES_UNOWN_Y]           = UNOWN_MISC_INFO(Y,           FALSE, 24, 32, 32, 48, 10 ),
    [SPECIES_UNOWN_Z]           = UNOWN_MISC_INFO(Z,           TRUE,  24, 32, 32, 48, 10 ),
    [SPECIES_UNOWN_EXCLAMATION] = UNOWN_MISC_INFO(Exclamation, FALSE, 24, 40, 24, 56,  6 ),
    [SPECIES_UNOWN_QUESTION]    = UNOWN_MISC_INFO(Question,    TRUE,  24, 40, 32, 56,  6 ),
#endif //P_FAMILY_UNOWN

#if P_FAMILY_WOBBUFFET
#if P_GEN_3_CROSS_EVOS
    [SPECIES_WYNAUT] =
    {
        .baseHP        = 95,
        .baseAttack    = 23,
        .baseDefense   = 48,
        .baseSpeed     = 23,
        .baseSpAttack  = 23,
        .baseSpDefense = 48,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 125,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 52 : 44,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SHADOW_TAG, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Wynaut"),
        .cryId = CRY_WYNAUT,
        .natDexNum = NATIONAL_DEX_WYNAUT,
        .categoryName = _("Bright"),
        .height = 6,
        .weight = 140,
        .description = COMPOUND_STRING(
            "A Wynaut loves to eat sweet fruits.\n"
            "It cleverly picks fruits using its earlike\n"
            "arms. They gather in fruit gardens, drawn\n"
            "by the fragrance."),
        .pokemonScale = 484,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wynaut,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .frontAnimDelay = 15,
        .backPic = gMonBackPic_Wynaut,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Wynaut,
        .shinyPalette = gMonShinyPalette_Wynaut,
        .iconSprite = gMonIcon_Wynaut,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Wynaut)
        OVERWORLD(
            sPicTable_Wynaut,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wynaut,
            gShinyOverworldPalette_Wynaut
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sWynautLevelUpLearnset,
        .teachableLearnset = sWynautTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_WOBBUFFET}),
    },
#endif //P_GEN_3_CROSS_EVOS

    [SPECIES_WOBBUFFET] =
    {
        .baseHP        = 190,
        .baseAttack    = 33,
        .baseDefense   = 58,
        .baseSpeed     = 33,
        .baseSpAttack  = 33,
        .baseSpDefense = 58,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 177,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_SHADOW_TAG, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Wobbuffet"),
        .cryId = CRY_WOBBUFFET,
        .natDexNum = NATIONAL_DEX_WOBBUFFET,
        .categoryName = _("Patient"),
        .height = 13,
        .weight = 285,
        .description = COMPOUND_STRING(
            "Usually docile, a Wobbuffet strikes back\n"
            "ferociously if its black tail is attacked.\n"
            "It makes its lair in caves where it waits\n"
            "for nightfall."),
        .pokemonScale = 274,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wobbuffet,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_DEEP_V_SQUISH_AND_BOUNCE : ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Wobbuffet,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Wobbuffet,
        .shinyPalette = gMonShinyPalette_Wobbuffet,
        .iconSprite = gMonIcon_Wobbuffet,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_WobbuffetF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_WobbuffetF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 56),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        .iconSpriteFemale = gMonIcon_WobbuffetF,
        .iconPalIndexFemale = 0,
    #endif
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 8, SHADOW_SIZE_M)
        FOOTPRINT(Wobbuffet)
        OVERWORLD(
            sPicTable_Wobbuffet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wobbuffet,
            gShinyOverworldPalette_Wobbuffet
        )
        OVERWORLD_FEMALE(
            sPicTable_WobbuffetF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sWobbuffetLevelUpLearnset,
        .teachableLearnset = sWobbuffetTeachableLearnset,
    },
#endif //P_FAMILY_WOBBUFFET

#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 90,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 149,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_EARLY_BIRD, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Girafarig"),
        .cryId = CRY_GIRAFARIG,
        .natDexNum = NATIONAL_DEX_GIRAFARIG,
        .categoryName = _("Long Neck"),
        .height = 15,
        .weight = 415,
        .description = COMPOUND_STRING(
            "A Girafarig is an herbivore--it eats\n"
            "grass and tree shoots. While it is eating,\n"
            "its tail makes chewing and swallowing\n"
            "motions as if it were also eating."),
        .pokemonScale = 281,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Girafarig,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_JUMPS_BIG : ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Girafarig,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 1,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Girafarig,
        .shinyPalette = gMonShinyPalette_Girafarig,
        .iconSprite = gMonIcon_Girafarig,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GirafarigF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 64),
        .backPicFemale = gMonBackPic_GirafarigF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_M)
        FOOTPRINT(Girafarig)
        OVERWORLD(
            sPicTable_Girafarig,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Girafarig,
            gShinyOverworldPalette_Girafarig
        )
        OVERWORLD_FEMALE(
            sPicTable_GirafarigF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGirafarigLevelUpLearnset,
        .teachableLearnset = sGirafarigTeachableLearnset,
        .eggMoveLearnset = sGirafarigEggMoveLearnset,
    #if P_GEN_9_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_FARIGIRAF, CONDITIONS({IF_KNOWS_MOVE, MOVE_TWIN_BEAM})}),
    #endif
    },

#if P_GEN_9_CROSS_EVOS
    [SPECIES_FARIGIRAF] =
    {
        .baseHP        = 120,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 110,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 260,
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CUD_CHEW, ABILITY_ARMOR_TAIL, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Farigiraf"),
        .cryId = CRY_FARIGIRAF,
        .natDexNum = NATIONAL_DEX_FARIGIRAF,
        .categoryName = _("Long Neck"),
        .height = 32,
        .weight = 1600,
        .description = COMPOUND_STRING(
            "Now that the brain waves from the\n"
            "head and tail are synced up, the\n"
            "psychic power of this Pokémon is 10\n"
            "times stronger than Girafarig's."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Farigiraf,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Farigiraf,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Farigiraf,
        .shinyPalette = gMonShinyPalette_Farigiraf,
        .iconSprite = gMonIcon_Farigiraf,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(11, 13, SHADOW_SIZE_L)
        FOOTPRINT(Farigiraf)
        OVERWORLD(
            sPicTable_Farigiraf,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Farigiraf,
            gShinyOverworldPalette_Farigiraf
        )
        .levelUpLearnset = sFarigirafLevelUpLearnset,
        .teachableLearnset = sFarigirafTeachableLearnset,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_GIRAFARIG

#if P_FAMILY_PINECO
    [SPECIES_PINECO] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 90,
        .baseSpeed     = 15,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 60,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Pineco"),
        .cryId = CRY_PINECO,
        .natDexNum = NATIONAL_DEX_PINECO,
        .categoryName = _("Bagworm"),
        .height = 6,
        .weight = 72,
        .description = COMPOUND_STRING(
            "A Pineco hangs from a tree branch and\n"
            "waits for prey. While eating, if it is\n"
            "disturbed by someone shaking its tree, it\n"
            "falls on the ground and suddenly explodes."),
        .pokemonScale = 445,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pineco,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
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
        .frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Pineco,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 13,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Pineco,
        .shinyPalette = gMonShinyPalette_Pineco,
        .iconSprite = gMonIcon_Pineco,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Pineco)
        OVERWORLD(
            sPicTable_Pineco,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Pineco,
            gShinyOverworldPalette_Pineco
        )
        .levelUpLearnset = sPinecoLevelUpLearnset,
        .teachableLearnset = sPinecoTeachableLearnset,
        .eggMoveLearnset = sPinecoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_FORRETRESS}),
    },

    [SPECIES_FORRETRESS] =
    {
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 140,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_BUG, TYPE_STEEL),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 118,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Forretress"),
        .cryId = CRY_FORRETRESS,
        .natDexNum = NATIONAL_DEX_FORRETRESS,
        .categoryName = _("Bagworm"),
        .height = 12,
        .weight = 1258,
        .description = COMPOUND_STRING(
            "It keeps itself inside its steel shell.\n"
            "The shell is opened when it is catching\n"
            "prey, but it is so quick that the shell's\n"
            "inside cannot be seen."),
        .pokemonScale = 293,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Forretress,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Forretress,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Forretress,
        .shinyPalette = gMonShinyPalette_Forretress,
        .iconSprite = gMonIcon_Forretress,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_L)
        FOOTPRINT(Forretress)
        OVERWORLD(
            sPicTable_Forretress,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Forretress,
            gShinyOverworldPalette_Forretress
        )
        .levelUpLearnset = sForretressLevelUpLearnset,
        .teachableLearnset = sForretressTeachableLearnset,
    },
#endif //P_FAMILY_PINECO

#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] =
    {
        .baseHP        = 100,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 190,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 145,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 125,
    #else
        .expYield = 75,
    #endif
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_RUN_AWAY, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Dunsparce"),
        .cryId = CRY_DUNSPARCE,
        .natDexNum = NATIONAL_DEX_DUNSPARCE,
        .categoryName = _("Land Snake"),
        .height = 15,
        .weight = 140,
        .description = COMPOUND_STRING(
            "Its drill-tipped tail is used to burrow into\n"
            "the ground backwards. This Pokémon is\n"
            "known to make its nest in complex shapes\n"
            "deep under the ground."),
        .pokemonScale = 316,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dunsparce,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 32) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Dunsparce,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(56, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 17,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Dunsparce,
        .shinyPalette = gMonShinyPalette_Dunsparce,
        .iconSprite = gMonIcon_Dunsparce,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, -4, SHADOW_SIZE_M)
        FOOTPRINT(Dunsparce)
        OVERWORLD(
            sPicTable_Dunsparce,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Dunsparce,
            gShinyOverworldPalette_Dunsparce
        )
        .levelUpLearnset = sDunsparceLevelUpLearnset,
        .teachableLearnset = sDunsparceTeachableLearnset,
        .eggMoveLearnset = sDunsparceEggMoveLearnset,
    #if P_GEN_9_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_DUDUNSPARCE_TWO_SEGMENT, CONDITIONS({IF_KNOWS_MOVE, MOVE_HYPER_DRILL}, {IF_PID_MODULO_100_GT, 0})},
                                {EVO_LEVEL, 0, SPECIES_DUDUNSPARCE_THREE_SEGMENT, CONDITIONS({IF_KNOWS_MOVE, MOVE_HYPER_DRILL}, {IF_PID_MODULO_100_EQ, 0})}),
    #endif
    },

#if P_GEN_9_CROSS_EVOS
    [SPECIES_DUDUNSPARCE_TWO_SEGMENT] =
    {
        .baseHP        = 125,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 182,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_RUN_AWAY, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Dudunsparce"),
        .cryId = CRY_DUDUNSPARCE,
        .natDexNum = NATIONAL_DEX_DUDUNSPARCE,
        .categoryName = _("Land Snake"),
        .height = 36,
        .weight = 392,
        .description = COMPOUND_STRING(
            "This Pokémon uses its hard tail to\n"
            "make its nest by boring holes into\n"
            "bedrock deep underground. The nest\n"
            "can reach lengths of over six miles."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DudunsparceTwoSegment,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_DudunsparceTwoSegment,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dudunsparce,
        .shinyPalette = gMonShinyPalette_Dudunsparce,
        .iconSprite = gMonIcon_Dudunsparce,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 5, SHADOW_SIZE_L)
        FOOTPRINT(Dudunsparce)
        OVERWORLD(
            sPicTable_DudunsparceTwoSegment,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Dudunsparce,
            gShinyOverworldPalette_Dudunsparce
        )
        .levelUpLearnset = sDudunsparceLevelUpLearnset,
        .teachableLearnset = sDudunsparceTeachableLearnset,
        .formSpeciesIdTable = sDudunsparceFormSpeciesIdTable,
    },

    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] =
    {
        .baseHP        = 125,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 182,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_RUN_AWAY, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Dudunsparce"),
        .cryId = CRY_DUDUNSPARCE,
        .natDexNum = NATIONAL_DEX_DUDUNSPARCE,
        .categoryName = _("Land Snake"),
        .height = 45,
        .weight = 474,
        .description = COMPOUND_STRING(
            "A recent study uncovered that the\n"
            "number of segments a Dudunsparce's\n"
            "body has is determined by the\n"
            "Pokémon's genes."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DudunsparceThreeSegment,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_DudunsparceThreeSegment,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dudunsparce,
        .shinyPalette = gMonShinyPalette_Dudunsparce,
        .iconSprite = gMonIcon_Dudunsparce,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 4, SHADOW_SIZE_L)
        FOOTPRINT(Dudunsparce)
        OVERWORLD(
            sPicTable_DudunsparceThreeSegment,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_DudunsparceThreeSegment,
            gShinyOverworldPalette_DudunsparceThreeSegment
        )
        .levelUpLearnset = sDudunsparceLevelUpLearnset,
        .teachableLearnset = sDudunsparceTeachableLearnset,
        .formSpeciesIdTable = sDudunsparceFormSpeciesIdTable,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_DUNSPARCE

#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 105,
        .baseSpeed     = 85,
        .baseSpAttack  = 35,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 86 : 108,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SAND_VEIL, ABILITY_IMMUNITY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gligar"),
        .cryId = CRY_GLIGAR,
        .natDexNum = NATIONAL_DEX_GLIGAR,
        .categoryName = _("Fly Scorpion"),
        .height = 11,
        .weight = 648,
        .description = COMPOUND_STRING(
            "It glides without making a single sound.\n"
            "It grasps the face of its foe using its\n"
            "hind and large front claws, then stabs\n"
            "with its poison barb."),
        .pokemonScale = 350,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gligar,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 17),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 8,
        .backPic = gMonBackPic_Gligar,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 2,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Gligar,
        .shinyPalette = gMonShinyPalette_Gligar,
        .iconSprite = gMonIcon_Gligar,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GligarF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_GligarF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_S)
        FOOTPRINT(Gligar)
        OVERWORLD(
            sPicTable_Gligar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Gligar,
            gShinyOverworldPalette_Gligar
        )
        OVERWORLD_FEMALE(
            sPicTable_GligarF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following
        )
        .levelUpLearnset = sGligarLevelUpLearnset,
        .teachableLearnset = sGligarTeachableLearnset,
        .eggMoveLearnset = sGligarEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_GLISCOR, CONDITIONS({IF_TIME, TIME_NIGHT}, {IF_HOLD_ITEM, ITEM_RAZOR_FANG})},
                                {EVO_ITEM, ITEM_RAZOR_FANG, SPECIES_GLISCOR, CONDITIONS({IF_TIME, TIME_NIGHT})}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_GLISCOR] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 125,
        .baseSpeed     = 95,
        .baseSpAttack  = 45,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 179 : 192,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SAND_VEIL, ABILITY_POISON_HEAL },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Gliscor"),
        .cryId = CRY_GLISCOR,
        .natDexNum = NATIONAL_DEX_GLISCOR,
        .categoryName = _("Fang Scorp"),
        .height = 20,
        .weight = 425,
        .description = COMPOUND_STRING(
            "Gliscor observes prey while hanging\n"
            "upside down from branches. Its flight is\n"
            "soundless. When the chance presents\n"
            "itself, it swoops!"),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Gliscor,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 40),
        ),
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 9,
        .backPic = gMonBackPic_Gliscor,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gliscor,
        .shinyPalette = gMonShinyPalette_Gliscor,
        .iconSprite = gMonIcon_Gliscor,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_M)
        FOOTPRINT(Gliscor)
        OVERWORLD(
            sPicTable_Gliscor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gliscor,
            gShinyOverworldPalette_Gliscor
        )
        .levelUpLearnset = sGliscorLevelUpLearnset,
        .teachableLearnset = sGliscorTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_GLIGAR

#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_NORMAL),
    #endif
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 63,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_RUN_AWAY, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Snubbull"),
        .cryId = CRY_SNUBBULL,
        .natDexNum = NATIONAL_DEX_SNUBBULL,
        .categoryName = _("Fairy"),
        .height = 6,
        .weight = 78,
        .description = COMPOUND_STRING(
            "By baring its fangs and making a scary\n"
            "face, it sends smaller Pokémon scurrying\n"
            "in terror. The Snubbull does seem a\n"
            "little sad at making its foes flee."),
        .pokemonScale = 465,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Snubbull,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Snubbull,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Snubbull,
        .shinyPalette = gMonShinyPalette_Snubbull,
        .iconSprite = gMonIcon_Snubbull,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Snubbull)
        OVERWORLD(
            sPicTable_Snubbull,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Snubbull,
            gShinyOverworldPalette_Snubbull
        )
        .levelUpLearnset = sSnubbullLevelUpLearnset,
        .teachableLearnset = sSnubbullTeachableLearnset,
        .eggMoveLearnset = sSnubbullEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 23, SPECIES_GRANBULL}),
    },

    [SPECIES_GRANBULL] =
    {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 75,
        .baseSpeed     = 45,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_NORMAL),
    #endif
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 158 : 178,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INTIMIDATE, ABILITY_QUICK_FEET, ABILITY_RATTLED },
    #else
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_RATTLED },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Granbull"),
        .cryId = CRY_GRANBULL,
        .natDexNum = NATIONAL_DEX_GRANBULL,
        .categoryName = _("Fairy"),
        .height = 14,
        .weight = 487,
        .description = COMPOUND_STRING(
            "It has a particularly well-developed lower\n"
            "jaw. The huge fangs are heavy, causing\n"
            "it to tilt its head. Unless it is startled,\n"
            "it will not try to bite."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Granbull,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 56) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Granbull,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 8,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Granbull,
        .shinyPalette = gMonShinyPalette_Granbull,
        .iconSprite = gMonIcon_Granbull,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 10, SHADOW_SIZE_L)
        FOOTPRINT(Granbull)
        OVERWORLD(
            sPicTable_Granbull,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Granbull,
            gShinyOverworldPalette_Granbull
        )
        .levelUpLearnset = sGranbullLevelUpLearnset,
        .teachableLearnset = sGranbullTeachableLearnset,
    },
#endif //P_FAMILY_SNUBBULL

#if P_FAMILY_QWILFISH
    [SPECIES_QWILFISH] =
    {
        .baseHP        = 65,
        .baseAttack    = 95,
        .baseDefense   = P_UPDATED_STATS >= GEN_7 ? 85 : 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER, TYPE_POISON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 88,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 86,
    #else
        .expYield = 100,
    #endif
        .evYield_Attack = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWIFT_SWIM, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Qwilfish"),
        .cryId = CRY_QWILFISH,
        .natDexNum = NATIONAL_DEX_QWILFISH,
        .categoryName = _("Balloon"),
        .height = 5,
        .weight = 39,
        .description = COMPOUND_STRING(
            "A Qwilfish uses the pressure of water\n"
            "it swallows to shoot toxic quills all at\n"
            "once from all over its body. It finds\n"
            "swimming to be somewhat challenging."),
        .pokemonScale = 430,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Qwilfish,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .frontAnimDelay = 39,
        .backPic = gMonBackPic_Qwilfish,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 6,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Qwilfish,
        .shinyPalette = gMonShinyPalette_Qwilfish,
        .iconSprite = gMonIcon_Qwilfish,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 3, SHADOW_SIZE_S)
        FOOTPRINT(Qwilfish)
        OVERWORLD(
            sPicTable_Qwilfish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Qwilfish,
            gShinyOverworldPalette_Qwilfish
        )
        .levelUpLearnset = sQwilfishLevelUpLearnset,
        .teachableLearnset = sQwilfishTeachableLearnset,
        .eggMoveLearnset = sQwilfishEggMoveLearnset,
        .formSpeciesIdTable = sQwilfishFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_QWILFISH_HISUI] =
    {
        .baseHP        = 65,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_DARK, TYPE_POISON),
        .catchRate = 45,
        .expYield = 88,
        .evYield_Attack = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWIFT_SWIM, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .speciesName = _("Qwilfish"),
        .cryId = CRY_QWILFISH,
        .natDexNum = NATIONAL_DEX_QWILFISH,
        .categoryName = _("Balloon"),
        .height = 5,
        .weight = 39,
        .description = COMPOUND_STRING(
            "A form of Qwilfish from the distant past.\n"
            "Fishers detest this troublesome Pokémon\n"
            "because it sprays poison from its spines,\n"
            "getting it everywhere."),
        .pokemonScale = 430,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_QwilfishHisui,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 9,
        .backPic = gMonBackPic_QwilfishHisui,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_QwilfishHisui,
        .shinyPalette = gMonShinyPalette_QwilfishHisui,
        .iconSprite = gMonIcon_QwilfishHisui,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 4, SHADOW_SIZE_S)
        FOOTPRINT(Qwilfish)
        OVERWORLD(
            sPicTable_QwilfishHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_QwilfishHisui,
            gShinyOverworldPalette_QwilfishHisui
        )
        .isHisuianForm = TRUE,
        .levelUpLearnset = sQwilfishHisuiLevelUpLearnset,
        .teachableLearnset = sQwilfishHisuiTeachableLearnset,
        .eggMoveLearnset = sQwilfishHisuiEggMoveLearnset,
        .formSpeciesIdTable = sQwilfishFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_OVERQWIL, CONDITIONS({IF_KNOWS_MOVE, MOVE_BARB_BARRAGE})}),
    },

    [SPECIES_OVERQWIL] =
    {
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DARK, TYPE_POISON),
        .catchRate = 45,
        .expYield = 179,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWIFT_SWIM, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .speciesName = _("Overqwil"),
        .cryId = CRY_OVERQWIL,
        .natDexNum = NATIONAL_DEX_OVERQWIL,
        .categoryName = _("Pin Cluster"),
        .height = 25,
        .weight = 605,
        .description = COMPOUND_STRING(
            "Its lancelike spikes and savage\n"
            "temperament have earned it the\n"
            "nickname “Sea Fiend”.\n"
            "It slurps up poison to nourish itself."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Overqwil,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Overqwil,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Overqwil,
        .shinyPalette = gMonShinyPalette_Overqwil,
        .iconSprite = gMonIcon_Overqwil,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Overqwil)
        OVERWORLD(
            sPicTable_Overqwil,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Overqwil,
            gShinyOverworldPalette_Overqwil
        )
        .levelUpLearnset = sOverqwilLevelUpLearnset,
        .teachableLearnset = sOverqwilTeachableLearnset,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_QWILFISH

#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] =
    {
        .baseHP        = 20,
        .baseAttack    = 10,
        .baseDefense   = 230,
        .baseSpeed     = 5,
        .baseSpAttack  = 10,
        .baseSpDefense = 230,
        .types = MON_TYPES(TYPE_BUG, TYPE_ROCK),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 177 : 80,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_BERRY_JUICE,
        .itemRare = ITEM_BERRY_JUICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_STURDY, ABILITY_GLUTTONY, ABILITY_CONTRARY },
    #else
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_CONTRARY },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Shuckle"),
        .cryId = CRY_SHUCKLE,
        .natDexNum = NATIONAL_DEX_SHUCKLE,
        .categoryName = _("Mold"),
        .height = 6,
        .weight = 205,
        .description = COMPOUND_STRING(
            "A Shuckle hides under rocks, keeping its\n"
            "body concealed inside its shell while\n"
            "eating stored berries. The berries mix with\n"
            "its body fluids to become a juice."),
        .pokemonScale = 485,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shuckle,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Shuckle,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Shuckle,
        .shinyPalette = gMonShinyPalette_Shuckle,
        .iconSprite = gMonIcon_Shuckle,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, 3, SHADOW_SIZE_M)
        FOOTPRINT(Shuckle)
        OVERWORLD(
            sPicTable_Shuckle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Shuckle,
            gShinyOverworldPalette_Shuckle
        )
        .levelUpLearnset = sShuckleLevelUpLearnset,
        .teachableLearnset = sShuckleTeachableLearnset,
        .eggMoveLearnset = sShuckleEggMoveLearnset,
    },
#endif //P_FAMILY_SHUCKLE

#if P_FAMILY_HERACROSS
    [SPECIES_HERACROSS] =
    {
        .baseHP        = 80,
        .baseAttack    = 125,
        .baseDefense   = 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 40,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_BUG, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 200,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_GUTS, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Heracross"),
        .cryId = CRY_HERACROSS,
        .natDexNum = NATIONAL_DEX_HERACROSS,
        .categoryName = _("Single Horn"),
        .height = 15,
        .weight = 540,
        .description = COMPOUND_STRING(
            "They gather in forests seeking the sweet\n"
            "sap of trees. It is completely clad in a\n"
            "steel-hard shell. It is proud of its horn,\n"
            "which it uses to fling foes."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Heracross,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_LUNGE_GROW : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Heracross,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(48, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Heracross,
        .shinyPalette = gMonShinyPalette_Heracross,
        .iconSprite = gMonIcon_Heracross,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_HeracrossF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_HeracrossF,
        .backPicSizeFemale = MON_COORDS_SIZE(48, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 10, SHADOW_SIZE_M)
        FOOTPRINT(Heracross)
        OVERWORLD(
            sPicTable_Heracross,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Heracross,
            gShinyOverworldPalette_Heracross
        )
        OVERWORLD_FEMALE(
            sPicTable_HeracrossF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sHeracrossLevelUpLearnset,
        .teachableLearnset = sHeracrossTeachableLearnset,
        .eggMoveLearnset = sHeracrossEggMoveLearnset,
        .formSpeciesIdTable = sHeracrossFormSpeciesIdTable,
        .formChangeTable = sHeracrossFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_HERACROSS_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 185,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_BUG, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 210,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SKILL_LINK, ABILITY_SKILL_LINK, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Heracross"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_HERACROSS_MEGA,
    #else
        .cryId = CRY_HERACROSS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_HERACROSS,
        .categoryName = _("Single Horn"),
        .height = 17,
        .weight = 625,
        .description = COMPOUND_STRING(
            "A tremendous influx of energy builds it up,\n"
            "but when Mega Evolution ends, Heracross\n"
            "is bothered by terrible soreness in its\n"
            "muscles."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_HeracrossMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_HeracrossMega,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_HeracrossMega,
        .shinyPalette = gMonShinyPalette_HeracrossMega,
        .iconSprite = gMonIcon_HeracrossMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_M)
        FOOTPRINT(Heracross)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_HeracrossMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_HeracrossMega,
            gShinyOverworldPalette_HeracrossMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sHeracrossLevelUpLearnset,
        .teachableLearnset = sHeracrossTeachableLearnset,
        .eggMoveLearnset = sHeracrossEggMoveLearnset,
        .formSpeciesIdTable = sHeracrossFormSpeciesIdTable,
        .formChangeTable = sHeracrossFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_HERACROSS

#if P_FAMILY_SNEASEL
    [SPECIES_SNEASEL] =
    {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 55,
        .baseSpeed     = 115,
        .baseSpAttack  = 35,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_DARK, TYPE_ICE),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 86 : 132,
        .evYield_Speed = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_KEEN_EYE, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .speciesName = _("Sneasel"),
        .cryId = CRY_SNEASEL,
        .natDexNum = NATIONAL_DEX_SNEASEL,
        .categoryName = _("Sharp Claw"),
        .height = 9,
        .weight = 280,
        .description = COMPOUND_STRING(
            "A Sneasel scales trees by punching its\n"
            "hooked claws into the bark. It seeks out\n"
            "unguarded nests and steals eggs for food\n"
            "while the parents are away."),
        .pokemonScale = 413,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sneasel,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_STRETCH : ANIM_H_JUMPS,
        .backPic = gMonBackPic_Sneasel,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 3,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Sneasel,
        .shinyPalette = gMonShinyPalette_Sneasel,
        .iconSprite = gMonIcon_Sneasel,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SneaselF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 48),
        .backPicFemale = gMonBackPic_SneaselF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 5, SHADOW_SIZE_S)
        FOOTPRINT(Sneasel)
        OVERWORLD(
            sPicTable_Sneasel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Sneasel,
            gShinyOverworldPalette_Sneasel
        )
        OVERWORLD_FEMALE(
            sPicTable_SneaselF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym
        )
        .levelUpLearnset = sSneaselLevelUpLearnset,
        .teachableLearnset = sSneaselTeachableLearnset,
        .eggMoveLearnset = sSneaselEggMoveLearnset,
        .formSpeciesIdTable = sSneaselFormSpeciesIdTable,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_WEAVILE, CONDITIONS({IF_TIME, TIME_NIGHT}, {IF_HOLD_ITEM, ITEM_RAZOR_CLAW})},
                                {EVO_ITEM, ITEM_RAZOR_CLAW, SPECIES_WEAVILE, CONDITIONS({IF_TIME, TIME_NIGHT})}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_WEAVILE] =
    {
        .baseHP        = 70,
        .baseAttack    = 120,
        .baseDefense   = 65,
        .baseSpeed     = 125,
        .baseSpAttack  = 45,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_DARK, TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 179 : 199,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Weavile"),
        .cryId = CRY_WEAVILE,
        .natDexNum = NATIONAL_DEX_WEAVILE,
        .categoryName = _("Sharp Claw"),
        .height = 11,
        .weight = 340,
        .description = COMPOUND_STRING(
            "They travel in groups of four or five,\n"
            "leaving signs for one another on trees\n"
            "and rocks. They bring down their prey\n"
            "with coordinated attacks."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Weavile,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Weavile,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Weavile,
        .shinyPalette = gMonShinyPalette_Weavile,
        .iconSprite = gMonIcon_Weavile,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_WeavileF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_WeavileF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 10, SHADOW_SIZE_M)
        FOOTPRINT(Weavile)
        OVERWORLD(
            sPicTable_Weavile,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Weavile,
            gShinyOverworldPalette_Weavile
        )
        OVERWORLD_FEMALE(
            sPicTable_WeavileF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sWeavileLevelUpLearnset,
        .teachableLearnset = sWeavileTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS

#if P_HISUIAN_FORMS
    [SPECIES_SNEASEL_HISUI] =
    {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 55,
        .baseSpeed     = 115,
        .baseSpAttack  = 35,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_POISON),
        .catchRate = 60,
        .expYield = 86,
        .evYield_Speed = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_KEEN_EYE, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Sneasel"),
        .cryId = CRY_SNEASEL,
        .natDexNum = NATIONAL_DEX_SNEASEL,
        .categoryName = _("Sharp Claw"),
        .height = 9,
        .weight = 270,
        .description = COMPOUND_STRING(
            "Its sturdy, curved claws are ideal for\n"
            "traversing precipitous cliffs. From the\n"
            "tips of these claws drips a venom that\n"
            "infiltrates the nerves of any prey caught."),
        .pokemonScale = 413,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SneaselHisui,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SneaselHisui,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SneaselHisui,
        .shinyPalette = gMonShinyPalette_SneaselHisui,
        .iconSprite = gMonIcon_SneaselHisui,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_SneaselHisuiF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SneaselHisuiF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 5, SHADOW_SIZE_S)
        FOOTPRINT(Sneasel)
        OVERWORLD(
            sPicTable_SneaselHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SneaselHisui,
            gShinyOverworldPalette_SneaselHisui
        )
        OVERWORLD_FEMALE(
            sPicTable_SneaselHisuiF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .isHisuianForm = TRUE,
        .levelUpLearnset = sSneaselHisuiLevelUpLearnset,
        .teachableLearnset = sSneaselHisuiTeachableLearnset,
        .eggMoveLearnset = sSneaselHisuiEggMoveLearnset,
        .formSpeciesIdTable = sSneaselFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_SNEASLER, CONDITIONS({IF_NOT_TIME, TIME_NIGHT}, {IF_HOLD_ITEM, ITEM_RAZOR_CLAW})},
                                {EVO_ITEM, ITEM_RAZOR_CLAW, SPECIES_SNEASLER, CONDITIONS({IF_NOT_TIME, TIME_NIGHT})}),
    },

    [SPECIES_SNEASLER] =
    {
        .baseHP        = 80,
        .baseAttack    = 130,
        .baseDefense   = 60,
        .baseSpeed     = 120,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_POISON),
        .catchRate = 20,
        .expYield = 102,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PRESSURE, ABILITY_UNBURDEN, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Sneasler"),
        .cryId = CRY_SNEASLER,
        .natDexNum = NATIONAL_DEX_SNEASLER,
        .categoryName = _("Free Climb"),
        .height = 13,
        .weight = 430,
        .description = COMPOUND_STRING(
            "Because of its wicked poison and daunting\n"
            "physical prowess, no other species could\n"
            "hope to best it on frozen highlands. It\n"
            "prefers solitude and doesn't form packs."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sneasler,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sneasler,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sneasler,
        .shinyPalette = gMonShinyPalette_Sneasler,
        .iconSprite = gMonIcon_Sneasler,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Sneasler)
        OVERWORLD(
            sPicTable_Sneasler,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sneasler,
            gShinyOverworldPalette_Sneasler
        )
        .levelUpLearnset = sSneaslerLevelUpLearnset,
        .teachableLearnset = sSneaslerTeachableLearnset,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_SNEASEL

#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 124,
        .evYield_Attack = 1,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_PICKUP, ABILITY_QUICK_FEET, ABILITY_HONEY_GATHER },
    #else
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_HONEY_GATHER },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Teddiursa"),
        .cryId = CRY_TEDDIURSA,
        .natDexNum = NATIONAL_DEX_TEDDIURSA,
        .categoryName = _("Little Bear"),
        .height = 6,
        .weight = 88,
        .description = COMPOUND_STRING(
            "It licks its palms that are sweetened by\n"
            "being soaked in honey. A Teddiursa makes\n"
            "its own honey by blending fruits and pollen\n"
            "collected by Beedrill."),
        .pokemonScale = 455,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Teddiursa,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Teddiursa,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Teddiursa,
        .shinyPalette = gMonShinyPalette_Teddiursa,
        .iconSprite = gMonIcon_Teddiursa,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 1, SHADOW_SIZE_S)
        FOOTPRINT(Teddiursa)
        OVERWORLD(
            sPicTable_Teddiursa,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Teddiursa,
            gShinyOverworldPalette_Teddiursa
        )
        .levelUpLearnset = sTeddiursaLevelUpLearnset,
        .teachableLearnset = sTeddiursaTeachableLearnset,
        .eggMoveLearnset = sTeddiursaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_URSARING}),
    },

    [SPECIES_URSARING] =
    {
        .baseHP        = 90,
        .baseAttack    = 130,
        .baseDefense   = 75,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 189,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_GUTS, ABILITY_QUICK_FEET, ABILITY_UNNERVE },
    #else
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_UNNERVE },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Ursaring"),
        .cryId = CRY_URSARING,
        .natDexNum = NATIONAL_DEX_URSARING,
        .categoryName = _("Hibernator"),
        .height = 18,
        .weight = 1258,
        .description = COMPOUND_STRING(
            "In forests, it is said that there are many\n"
            "streams and towering trees where an\n"
            "Ursaring gathers food. It walks through\n"
            "its forest collecting food every day."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ursaring,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE : ANIM_H_SHAKE,
        .backPic = gMonBackPic_Ursaring,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Ursaring,
        .shinyPalette = gMonShinyPalette_Ursaring,
        .iconSprite = gMonIcon_Ursaring,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_UrsaringF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_UrsaringF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 14, SHADOW_SIZE_L)
        FOOTPRINT(Ursaring)
        OVERWORLD(
            sPicTable_Ursaring,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ursaring,
            gShinyOverworldPalette_Ursaring
        )
        OVERWORLD_FEMALE(
            sPicTable_UrsaringF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sUrsaringLevelUpLearnset,
        .teachableLearnset = sUrsaringTeachableLearnset,
    #if P_GEN_8_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_PEAT_BLOCK, SPECIES_URSALUNA, CONDITIONS({IF_REGION, REGION_HISUI}, {IF_TIME, TIME_NIGHT})},
                                {EVO_NONE, 0, SPECIES_URSALUNA_BLOODMOON}),
    #endif
    },

#if P_GEN_8_CROSS_EVOS
    [SPECIES_URSALUNA] =
    {
        .baseHP        = 130,
        .baseAttack    = 140,
        .baseDefense   = 105,
        .baseSpeed     = 50,
        .baseSpAttack  = 45,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GROUND, TYPE_NORMAL),
        .catchRate = 20,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GUTS, ABILITY_BULLETPROOF, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Ursaluna"),
        .cryId = CRY_URSALUNA,
        .natDexNum = NATIONAL_DEX_URSALUNA,
        .categoryName = _("Peat"),
        .height = 24,
        .weight = 2900,
        .description = COMPOUND_STRING(
            "Swampy terrain gives Ursaluna its burly\n"
            "physique and newfound capacity to\n"
            "manipulate peat at will."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Ursaluna,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Ursaluna,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Ursaluna,
        .shinyPalette = gMonShinyPalette_Ursaluna,
        .iconSprite = gMonIcon_Ursaluna,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 4, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Ursaluna)
        OVERWORLD(
            sPicTable_Ursaluna,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ursaluna,
            gShinyOverworldPalette_Ursaluna
        )
        .levelUpLearnset = sUrsalunaLevelUpLearnset,
        .teachableLearnset = sUrsalunaTeachableLearnset,
        .formSpeciesIdTable = sUrsalunaFormSpeciesIdTable,
    },

    [SPECIES_URSALUNA_BLOODMOON] =
    {
        .baseHP        = 113,
        .baseAttack    = 70,
        .baseDefense   = 120,
        .baseSpeed     = 52,
        .baseSpAttack  = 135,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GROUND, TYPE_NORMAL),
        .catchRate = 5,
        .expYield = 278,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_MINDS_EYE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Ursaluna"),
        .cryId = CRY_URSALUNA_BLOODMOON,
        .natDexNum = NATIONAL_DEX_URSALUNA,
        .categoryName = _("Peat"),
        .height = 27,
        .weight = 3330,
        .description = COMPOUND_STRING(
            "It crossed the sea and drifted\n"
            "ashore in a new land. Surviving in this\n"
            "place led it to take on a unique\n"
            "appearance and gain special powers."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_UrsalunaBloodmoon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_UrsalunaBloodmoon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_UrsalunaBloodmoon,
        .shinyPalette = gMonShinyPalette_UrsalunaBloodmoon,
        .iconSprite = gMonIcon_UrsalunaBloodmoon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 11, SHADOW_SIZE_L)
        FOOTPRINT(Ursaluna)
        OVERWORLD(
            sPicTable_UrsalunaBloodmoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_UrsalunaBloodmoon,
            gShinyOverworldPalette_UrsalunaBloodmoon
        )
        .levelUpLearnset = sUrsalunaBloodmoonLevelUpLearnset,
        .teachableLearnset = sUrsalunaBloodmoonTeachableLearnset,
        .formSpeciesIdTable = sUrsalunaFormSpeciesIdTable,
    },
#endif //P_GEN_8_CROSS_EVOS
#endif //P_FAMILY_TEDDIURSA

#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 70,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 50 : 78,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_FLAME_BODY, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Slugma"),
        .cryId = CRY_SLUGMA,
        .natDexNum = NATIONAL_DEX_SLUGMA,
        .categoryName = _("Lava"),
        .height = 7,
        .weight = 350,
        .description = COMPOUND_STRING(
            "It is a species of Pokémon that lives in\n"
            "volcanic areas. If its body cools, its skin\n"
            "hardens and immobilizes it. To avoid that,\n"
            "it sleeps near magma."),
        .pokemonScale = 329,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Slugma,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Slugma,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Slugma,
        .shinyPalette = gMonShinyPalette_Slugma,
        .iconSprite = gMonIcon_Slugma,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Slugma)
        OVERWORLD(
            sPicTable_Slugma,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Slugma,
            gShinyOverworldPalette_Slugma
        )
        .levelUpLearnset = sSlugmaLevelUpLearnset,
        .teachableLearnset = sSlugmaTeachableLearnset,
        .eggMoveLearnset = sSlugmaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_MAGCARGO}),
    },

    [SPECIES_MAGCARGO] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 60 : 50,
        .baseAttack    = 50,
        .baseDefense   = 120,
        .baseSpeed     = 30,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 90 : 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE, TYPE_ROCK),
        .catchRate = 75,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 151,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 144,
    #else
        .expYield = 154,
    #endif
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_FLAME_BODY, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Magcargo"),
        .cryId = CRY_MAGCARGO,
        .natDexNum = NATIONAL_DEX_MAGCARGO,
        .categoryName = _("Lava"),
        .height = 8,
        .weight = 550,
        .description = COMPOUND_STRING(
            "The shell on its back is made of hardened\n"
            "magma. Tens of thousands of years spent\n"
            "living in volcanic craters have turned\n"
            "Magcargo's bodies into magma."),
        .pokemonScale = 332,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Magcargo,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 56) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Magcargo,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Magcargo,
        .shinyPalette = gMonShinyPalette_Magcargo,
        .iconSprite = gMonIcon_Magcargo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 5, SHADOW_SIZE_M)
        FOOTPRINT(Magcargo)
        OVERWORLD(
            sPicTable_Magcargo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following_Asym,
            gOverworldPalette_Magcargo,
            gShinyOverworldPalette_Magcargo
        )
        .levelUpLearnset = sMagcargoLevelUpLearnset,
        .teachableLearnset = sMagcargoTeachableLearnset,
    },
#endif //P_FAMILY_SLUGMA

#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ICE, TYPE_GROUND),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 50 : 78,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_SNOW_CLOAK, ABILITY_THICK_FAT },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_THICK_FAT },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Swinub"),
        .cryId = CRY_SWINUB,
        .natDexNum = NATIONAL_DEX_SWINUB,
        .categoryName = _("Pig"),
        .height = 4,
        .weight = 65,
        .description = COMPOUND_STRING(
            "It roots for food by rubbing its snout\n"
            "against the ground. Its favorite food is a\n"
            "mushroom that grows under dried grass.\n"
            "It occasionally roots out hot springs."),
        .pokemonScale = 324,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Swinub,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 24) : MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 18,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Swinub,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 24) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 21 : 15,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Swinub,
        .shinyPalette = gMonShinyPalette_Swinub,
        .iconSprite = gMonIcon_Swinub,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, -6, SHADOW_SIZE_S)
        FOOTPRINT(Swinub)
        OVERWORLD(
            sPicTable_Swinub,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Swinub,
            gShinyOverworldPalette_Swinub
        )
        .levelUpLearnset = sSwinubLevelUpLearnset,
        .teachableLearnset = sSwinubTeachableLearnset,
        .eggMoveLearnset = sSwinubEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_PILOSWINE}),
    },

    [SPECIES_PILOSWINE] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ICE, TYPE_GROUND),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 158 : 160,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_SNOW_CLOAK, ABILITY_THICK_FAT },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_THICK_FAT },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Piloswine"),
        .cryId = CRY_PILOSWINE,
        .natDexNum = NATIONAL_DEX_PILOSWINE,
        .categoryName = _("Swine"),
        .height = 11,
        .weight = 558,
        .description = COMPOUND_STRING(
            "A Piloswine is covered by a thick coat\n"
            "of long hair for enduring freezing cold.\n"
            "It uses its tusks to dig up food that has\n"
            "been buried under ice."),
        .pokemonScale = 306,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Piloswine,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Piloswine,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 8,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Piloswine,
        .shinyPalette = gMonShinyPalette_Piloswine,
        .iconSprite = gMonIcon_Piloswine,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_PiloswineF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 56),
        .backPicFemale = gMonBackPic_PiloswineF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 3, SHADOW_SIZE_M)
        FOOTPRINT(Piloswine)
        OVERWORLD(
            sPicTable_Piloswine,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Piloswine,
            gShinyOverworldPalette_Piloswine
        )
        OVERWORLD_FEMALE(
            sPicTable_PiloswineF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sPiloswineLevelUpLearnset,
        .teachableLearnset = sPiloswineTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_MAMOSWINE, CONDITIONS({IF_KNOWS_MOVE, MOVE_ANCIENT_POWER})}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAMOSWINE] =
    {
        .baseHP        = 110,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 70,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ICE, TYPE_GROUND),
        .catchRate = 50,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 265,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 239,
    #else
        .expYield = 207,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_SNOW_CLOAK, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mamoswine"),
        .cryId = CRY_MAMOSWINE,
        .natDexNum = NATIONAL_DEX_MAMOSWINE,
        .categoryName = _("Twin Tusk"),
        .height = 25,
        .weight = 2910,
        .description = COMPOUND_STRING(
            "A frozen Mamoswine was dug from ice\n"
            "dating back 10,000 years. It woke up to\n"
            "much amazement. This Pokémon has been\n"
            "around for a long, long, long time."),
        .pokemonScale = 257,
        .pokemonOffset = 6,
        .trainerScale = 423,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Mamoswine,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Mamoswine,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Mamoswine,
        .shinyPalette = gMonShinyPalette_Mamoswine,
        .iconSprite = gMonIcon_Mamoswine,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_MamoswineF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 7, SHADOW_SIZE_L)
        FOOTPRINT(Mamoswine)
        OVERWORLD(
            sPicTable_Mamoswine,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mamoswine,
            gShinyOverworldPalette_Mamoswine
        )
        OVERWORLD_FEMALE(
            sPicTable_MamoswineF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sMamoswineLevelUpLearnset,
        .teachableLearnset = sMamoswineTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_SWINUB

#if P_FAMILY_CORSOLA
    [SPECIES_CORSOLA] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 65 : 55,
        .baseAttack    = 55,
        .baseDefense   = P_UPDATED_STATS >= GEN_7 ? 95 : 85,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = P_UPDATED_STATS >= GEN_7 ? 95 : 85,
        .types = MON_TYPES(TYPE_WATER, TYPE_ROCK),
        .catchRate = 60,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 144,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 133,
    #else
        .expYield = 113,
    #endif
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_LUMINOUS_MOSS,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_HUSTLE, ABILITY_NATURAL_CURE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Corsola"),
        .cryId = CRY_CORSOLA,
        .natDexNum = NATIONAL_DEX_CORSOLA,
        .categoryName = _("Coral"),
        .height = 6,
        .weight = 50,
        .description = COMPOUND_STRING(
            "Corsola live in warm southern seas.\n"
            "If the sea becomes polluted, the beautiful\n"
            "coral stalks become discolored and crumble\n"
            "away in tatters."),
        .pokemonScale = 410,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Corsola,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Corsola,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 8,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Corsola,
        .shinyPalette = gMonShinyPalette_Corsola,
        .iconSprite = gMonIcon_Corsola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 1, SHADOW_SIZE_M)
        FOOTPRINT(Corsola)
        OVERWORLD(
            sPicTable_Corsola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Corsola,
            gShinyOverworldPalette_Corsola
        )
        .levelUpLearnset = sCorsolaLevelUpLearnset,
        .teachableLearnset = sCorsolaTeachableLearnset,
        .eggMoveLearnset = sCorsolaEggMoveLearnset,
        .formSpeciesIdTable = sCorsolaFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_CORSOLA_GALAR] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 100,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 60,
        .expYield = 144,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Corsola"),
        .cryId = CRY_CORSOLA,
        .natDexNum = NATIONAL_DEX_CORSOLA,
        .categoryName = _("Coral"),
        .height = 6,
        .weight = 5,
        .description = COMPOUND_STRING(
            "Sudden climate change wiped out this\n"
            "ancient kind of Corsola. With its branches,\n"
            "it absorbs others' life-force. It curses\n"
            "those unaware that kick it by accident."),
        .pokemonScale = 410,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CorsolaGalar,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CorsolaGalar,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CorsolaGalar,
        .shinyPalette = gMonShinyPalette_CorsolaGalar,
        .iconSprite = gMonIcon_CorsolaGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(Corsola)
        OVERWORLD(
            sPicTable_CorsolaGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_CorsolaGalar,
            gShinyOverworldPalette_CorsolaGalar
        )
        .isGalarianForm = TRUE,
        .levelUpLearnset = sCorsolaGalarLevelUpLearnset,
        .teachableLearnset = sCorsolaGalarTeachableLearnset,
        .eggMoveLearnset = sCorsolaGalarEggMoveLearnset,
        .formSpeciesIdTable = sCorsolaFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_CURSOLA}),
    },

    [SPECIES_CURSOLA] =
    {
        .baseHP        = 60,
        .baseAttack    = 95,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 145,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 30,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_PERISH_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Cursola"),
        .cryId = CRY_CURSOLA,
        .natDexNum = NATIONAL_DEX_CURSOLA,
        .categoryName = _("Coral"),
        .height = 10,
        .weight = 4,
        .description = COMPOUND_STRING(
            "Its shell is overflowing with its\n"
            "heightened otherworldly energy. The\n"
            "ectoplasm serves as protection for this\n"
            "Pokémon's core spirit."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cursola,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cursola,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Cursola,
        .shinyPalette = gMonShinyPalette_Cursola,
        .iconSprite = gMonIcon_Cursola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 13, SHADOW_SIZE_S)
        FOOTPRINT(Cursola)
        OVERWORLD(
            sPicTable_Cursola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cursola,
            gShinyOverworldPalette_Cursola
        )
        .levelUpLearnset = sCursolaLevelUpLearnset,
        .teachableLearnset = sCursolaTeachableLearnset,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_CORSOLA

#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] =
    {
        .baseHP        = 35,
        .baseAttack    = 65,
        .baseDefense   = 35,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 78,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_2),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_HUSTLE, ABILITY_SNIPER, ABILITY_MOODY },
    #else
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE, ABILITY_MOODY },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Remoraid"),
        .cryId = CRY_REMORAID,
        .natDexNum = NATIONAL_DEX_REMORAID,
        .categoryName = _("Jet"),
        .height = 6,
        .weight = 120,
        .description = COMPOUND_STRING(
            "A Remoraid uses its abdominal muscles\n"
            "to forcefully expel swallowed water, then\n"
            "shoot down flying prey. When evolution\n"
            "approaches, it travels down rivers."),
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Remoraid,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_JUMPS_SMALL : ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Remoraid,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Remoraid,
        .shinyPalette = gMonShinyPalette_Remoraid,
        .iconSprite = gMonIcon_Remoraid,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Remoraid)
        OVERWORLD(
            sPicTable_Remoraid,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Remoraid,
            gShinyOverworldPalette_Remoraid
        )
        .levelUpLearnset = sRemoraidLevelUpLearnset,
        .teachableLearnset = sRemoraidTeachableLearnset,
        .eggMoveLearnset = sRemoraidEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_OCTILLERY}),
    },

    [SPECIES_OCTILLERY] =
    {
        .baseHP        = 75,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 45,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 168 : 164,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_2),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SUCTION_CUPS, ABILITY_SNIPER, ABILITY_MOODY },
    #else
        .abilities = { ABILITY_SUCTION_CUPS, ABILITY_NONE, ABILITY_MOODY },
    #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Octillery"),
        .cryId = CRY_OCTILLERY,
        .natDexNum = NATIONAL_DEX_OCTILLERY,
        .categoryName = _("Jet"),
        .height = 9,
        .weight = 285,
        .description = COMPOUND_STRING(
            "It ensnares its foe with its suction-\n"
            "cupped tentacles before delivering the\n"
            "finishing blow. If the foe turns out to be\n"
            "too strong, it spews ink to escape."),
        .pokemonScale = 296,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Octillery,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Octillery,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Octillery,
        .shinyPalette = gMonShinyPalette_Octillery,
        .iconSprite = gMonIcon_Octillery,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_OctilleryF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 48),
        .backPicFemale = gMonBackPic_OctilleryF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 4, SHADOW_SIZE_M)
        FOOTPRINT(Octillery)
        OVERWORLD(
            sPicTable_Octillery,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Octillery,
            gShinyOverworldPalette_Octillery
        )
        OVERWORLD_FEMALE(
            sPicTable_OctilleryF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sOctilleryLevelUpLearnset,
        .teachableLearnset = sOctilleryTeachableLearnset,
    },
#endif //P_FAMILY_REMORAID

#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 75,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ICE, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 116 : 183,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_HUSTLE, ABILITY_INSOMNIA },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Delibird"),
        .cryId = CRY_DELIBIRD,
        .natDexNum = NATIONAL_DEX_DELIBIRD,
        .categoryName = _("Delivery"),
        .height = 9,
        .weight = 160,
        .description = COMPOUND_STRING(
            "It carries food bundled up in its tail.\n"
            "There was a famous explorer who\n"
            "managed to scale Mt. Everest thanks\n"
            "to a Delibird sharing its food."),
        .pokemonScale = 293,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Delibird,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_JUMPS_SMALL : ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Delibird,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Delibird,
        .shinyPalette = gMonShinyPalette_Delibird,
        .iconSprite = gMonIcon_Delibird,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_M)
        FOOTPRINT(Delibird)
        OVERWORLD(
            sPicTable_Delibird,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Delibird,
            gShinyOverworldPalette_Delibird
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sDelibirdLevelUpLearnset,
        .teachableLearnset = sDelibirdTeachableLearnset,
        .eggMoveLearnset = sDelibirdEggMoveLearnset,
    },
#endif //P_FAMILY_DELIBIRD

#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MANTYKE] =
    {
        .baseHP        = 45,
        .baseAttack    = 20,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 25,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 69 : 108,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_WATER_ABSORB, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Mantyke"),
        .cryId = CRY_MANTYKE,
        .natDexNum = NATIONAL_DEX_MANTYKE,
        .categoryName = _("Kite"),
        .height = 10,
        .weight = 650,
        .description = COMPOUND_STRING(
            "When it swims close to the surface\n"
            "of the ocean, people aboard ships are\n"
            "able to observe the pattern on its back.\n"
            "It often swims in a school of Remoraid."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mantyke,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_TWIST_TWICE,
        .backPic = gMonBackPic_Mantyke,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Mantyke,
        .shinyPalette = gMonShinyPalette_Mantyke,
        .iconSprite = gMonIcon_Mantyke,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 3, SHADOW_SIZE_S)
        FOOTPRINT(Mantyke)
        OVERWORLD(
            sPicTable_Mantyke,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mantyke,
            gShinyOverworldPalette_Mantyke
        )
        .levelUpLearnset = sMantykeLevelUpLearnset,
        .teachableLearnset = sMantykeTeachableLearnset,
        .eggMoveLearnset = sMantykeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_MANTINE, CONDITIONS({IF_SPECIES_IN_PARTY, SPECIES_REMORAID})}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_MANTINE] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 85 : 65,
        .baseAttack    = 40,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 80,
        .baseSpDefense = 140,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 25,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 170,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 163,
    #else
        .expYield = 168,
    #endif
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_WATER_ABSORB, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = P_GBA_STYLE_SPECIES_GFX,
        .speciesName = _("Mantine"),
        .cryId = CRY_MANTINE,
        .natDexNum = NATIONAL_DEX_MANTINE,
        .categoryName = _("Kite"),
        .height = 21,
        .weight = 2200,
        .description = COMPOUND_STRING(
            "On sunny days, schools of Mantine can be\n"
            "seen elegantly leaping over the waves.\n"
            "It is not bothered by the Remoraid that\n"
            "hitches rides."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Mantine,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 40),
        ),
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 0 : 6,
        .backPic = gMonBackPic_Mantine,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 2,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Mantine,
        .shinyPalette = gMonShinyPalette_Mantine,
        .iconSprite = gMonIcon_Mantine,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Mantine)
        OVERWORLD(
            sPicTable_Mantine,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Mantine,
            gShinyOverworldPalette_Mantine
        )
        .levelUpLearnset = sMantineLevelUpLearnset,
        .teachableLearnset = sMantineTeachableLearnset,
        .eggMoveLearnset = sMantineEggMoveLearnset,
    },
#endif //P_FAMILY_MANTINE

#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 140,
        .baseSpeed     = 70,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_STEEL, TYPE_FLYING),
        .catchRate = 25,
        .expYield = 163,
        .evYield_Defense = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_STURDY, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Skarmory"),
        .cryId = CRY_SKARMORY,
        .natDexNum = NATIONAL_DEX_SKARMORY,
        .categoryName = _("Armor Bird"),
        .height = 17,
        .weight = 505,
        .description = COMPOUND_STRING(
            "A Pokémon that has a body and wings of\n"
            "steel. People in the past used feathers\n"
            "fallen from Skarmory to make swords and\n"
            "knives."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 271,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Skarmory,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_STRETCH : ANIM_V_SHAKE,
        .backPic = gMonBackPic_Skarmory,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(48, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 1,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Skarmory,
        .shinyPalette = gMonShinyPalette_Skarmory,
        .iconSprite = gMonIcon_Skarmory,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 9, SHADOW_SIZE_M)
        FOOTPRINT(Skarmory)
        OVERWORLD(
            sPicTable_Skarmory,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Skarmory,
            gShinyOverworldPalette_Skarmory
        )
        .levelUpLearnset = sSkarmoryLevelUpLearnset,
        .teachableLearnset = sSkarmoryTeachableLearnset,
        .eggMoveLearnset = sSkarmoryEggMoveLearnset,
        .formSpeciesIdTable = sSkarmoryFormSpeciesIdTable,
        .formChangeTable = sSkarmoryFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_SKARMORY_MEGA] =
    {
        .baseHP        = 65,
        .baseAttack    = 140,
        .baseDefense   = 110,
        .baseSpeed     = 110,
        .baseSpAttack  = 40,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_STEEL, TYPE_FLYING),
        .catchRate = 25,
        .expYield = 163,
        .evYield_Defense = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_STALWART, ABILITY_STALWART, ABILITY_STALWART },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Skarmory"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SKARMORY_MEGA,
    #else
        .cryId = CRY_SKARMORY,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SKARMORY,
        .categoryName = _("Armor Bird"),
        .height = 17,
        .weight = 404,
        .description = COMPOUND_STRING(
            "Due to the effects of Mega Evolution,\n"
            "its pincers have taken a more\n"
            "diabolical form, ripping anything\n"
            "they pierce to shreds."),
        .frontPic = gMonFrontPic_SkarmoryMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_SkarmoryMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SkarmoryMega,
        .shinyPalette = gMonShinyPalette_SkarmoryMega,
        .iconSprite = gMonIcon_SkarmoryMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Skarmory)
        SHADOW(2, 16, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSkarmoryLevelUpLearnset,
        .teachableLearnset = sSkarmoryTeachableLearnset,
        .formSpeciesIdTable = sSkarmoryFormSpeciesIdTable,
        .formChangeTable = sSkarmoryFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_SKARMORY

#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 65,
        .baseSpAttack  = 80,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DARK, TYPE_FIRE),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 114,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_EARLY_BIRD, ABILITY_FLASH_FIRE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Houndour"),
        .cryId = CRY_HOUNDOUR,
        .natDexNum = NATIONAL_DEX_HOUNDOUR,
        .categoryName = _("Dark"),
        .height = 6,
        .weight = 108,
        .description = COMPOUND_STRING(
            "Houndour communicate with each other\n"
            "using a variety of cries to corner their\n"
            "prey. This Pokémon's remarkable teamwork\n"
            "is simply unparalleled."),
        .pokemonScale = 393,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Houndour,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Houndour,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Houndour,
        .shinyPalette = gMonShinyPalette_Houndour,
        .iconSprite = gMonIcon_Houndour,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 4, SHADOW_SIZE_M)
        FOOTPRINT(Houndour)
        OVERWORLD(
            sPicTable_Houndour,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Houndour,
            gShinyOverworldPalette_Houndour
        )
        .levelUpLearnset = sHoundourLevelUpLearnset,
        .teachableLearnset = sHoundourTeachableLearnset,
        .eggMoveLearnset = sHoundourEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_HOUNDOOM}),
    },

    [SPECIES_HOUNDOOM] =
    {
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 50,
        .baseSpeed     = 95,
        .baseSpAttack  = 110,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_DARK, TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 204,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_EARLY_BIRD, ABILITY_FLASH_FIRE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Houndoom"),
        .cryId = CRY_HOUNDOOM,
        .natDexNum = NATIONAL_DEX_HOUNDOOM,
        .categoryName = _("Dark"),
        .height = 14,
        .weight = 350,
        .description = COMPOUND_STRING(
            "In a Houndoom pack, the one with its horns\n"
            "raked sharply back serves a leadership\n"
            "role. They choose their leader by fighting\n"
            "among themselves."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Houndoom,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Houndoom,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 6,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Houndoom,
        .shinyPalette = gMonShinyPalette_Houndoom,
        .iconSprite = gMonIcon_Houndoom,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_HoundoomF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_HoundoomF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 13, SHADOW_SIZE_L)
        FOOTPRINT(Houndoom)
        OVERWORLD(
            sPicTable_Houndoom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Houndoom,
            gShinyOverworldPalette_Houndoom
        )
        OVERWORLD_FEMALE(
            sPicTable_HoundoomF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sHoundoomLevelUpLearnset,
        .teachableLearnset = sHoundoomTeachableLearnset,
        .formSpeciesIdTable = sHoundoomFormSpeciesIdTable,
        .formChangeTable = sHoundoomFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_HOUNDOOM_MEGA] =
    {
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 90,
        .baseSpeed     = 115,
        .baseSpAttack  = 140,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DARK, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 210,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SOLAR_POWER, ABILITY_SOLAR_POWER, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Houndoom"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_HOUNDOOM_MEGA,
    #else
        .cryId = CRY_HOUNDOOM,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_HOUNDOOM,
        .categoryName = _("Dark"),
        .height = 19,
        .weight = 495,
        .description = COMPOUND_STRING(
            "Its red claws and the tips of its tail are\n"
            "melting from high internal temperatures\n"
            "that are painful to Houndoom itself.\n"),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_HoundoomMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_HoundoomMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_HoundoomMega,
        .shinyPalette = gMonShinyPalette_HoundoomMega,
        .iconSprite = gMonIcon_HoundoomMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 13, SHADOW_SIZE_L)
        FOOTPRINT(Houndoom)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_HoundoomMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_HoundoomMega,
            gShinyOverworldPalette_HoundoomMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sHoundoomLevelUpLearnset,
        .teachableLearnset = sHoundoomTeachableLearnset,
        .formSpeciesIdTable = sHoundoomFormSpeciesIdTable,
        .formChangeTable = sHoundoomFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_HOUNDOUR

#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] =
    {
        .baseHP        = 90,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 124,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Phanpy"),
        .cryId = CRY_PHANPY,
        .natDexNum = NATIONAL_DEX_PHANPY,
        .categoryName = _("Long Nose"),
        .height = 5,
        .weight = 335,
        .description = COMPOUND_STRING(
            "Phanpy's big ears serve as broad fans.\n"
            "When it becomes hot, it flaps the ears\n"
            "busily to cool down. Even the young are\n"
            "very strong."),
        .pokemonScale = 465,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Phanpy,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Phanpy,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 12,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Phanpy,
        .shinyPalette = gMonShinyPalette_Phanpy,
        .iconSprite = gMonIcon_Phanpy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(3, -2, SHADOW_SIZE_M)
        FOOTPRINT(Phanpy)
        OVERWORLD(
            sPicTable_Phanpy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Phanpy,
            gShinyOverworldPalette_Phanpy
        )
        .levelUpLearnset = sPhanpyLevelUpLearnset,
        .teachableLearnset = sPhanpyTeachableLearnset,
        .eggMoveLearnset = sPhanpyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_DONPHAN}),
    },

    [SPECIES_DONPHAN] =
    {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 189,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Donphan"),
        .cryId = CRY_DONPHAN,
        .natDexNum = NATIONAL_DEX_DONPHAN,
        .categoryName = _("Armor"),
        .height = 11,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "A Donphan is so strong it can easily haul\n"
            "a dump truck. Its hide has toughened to a\n"
            "rock-hard state. An ordinary sort of\n"
            "attack won't even leave a scratch."),
        .pokemonScale = 313,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Donphan,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE_TWICE : ANIM_ROTATE_UP_SLAM_DOWN,
        .backPic = gMonBackPic_Donphan,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Donphan,
        .shinyPalette = gMonShinyPalette_Donphan,
        .iconSprite = gMonIcon_Donphan,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_DonphanF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 48),
        .backPicFemale = gMonBackPic_DonphanF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 2, SHADOW_SIZE_L)
        FOOTPRINT(Donphan)
        OVERWORLD(
            sPicTable_Donphan,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Donphan,
            gShinyOverworldPalette_Donphan
        )
        OVERWORLD_FEMALE(
            sPicTable_DonphanF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sDonphanLevelUpLearnset,
        .teachableLearnset = sDonphanTeachableLearnset,
    },
#endif //P_FAMILY_PHANPY

#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] =
    {
        .baseHP        = 73,
        .baseAttack    = 95,
        .baseDefense   = 62,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 165,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_SAP_SIPPER },
    #else
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_SAP_SIPPER },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Stantler"),
        .cryId = CRY_STANTLER,
        .natDexNum = NATIONAL_DEX_STANTLER,
        .categoryName = _("Big Horn"),
        .height = 14,
        .weight = 712,
        .description = COMPOUND_STRING(
            "Stantler's magnificent antlers were\n"
            "once traded at high prices as works of art.\n"
            "As a result, this Pokémon was hunted\n"
            "close to extinction."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Stantler,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Stantler,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 1,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Stantler,
        .shinyPalette = gMonShinyPalette_Stantler,
        .iconSprite = gMonIcon_Stantler,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 13, SHADOW_SIZE_M)
        FOOTPRINT(Stantler)
        OVERWORLD(
            sPicTable_Stantler,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Stantler,
            gShinyOverworldPalette_Stantler
        )
        .levelUpLearnset = sStantlerLevelUpLearnset,
        .teachableLearnset = sStantlerTeachableLearnset,
        .eggMoveLearnset = sStantlerEggMoveLearnset,
    #if P_GEN_8_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_WYRDEER, CONDITIONS({IF_USED_MOVE_X_TIMES, MOVE_PSYSHIELD_BASH, 20})}),
    #endif
    },

#if P_GEN_8_CROSS_EVOS
    [SPECIES_WYRDEER] =
    {
        .baseHP        = 103,
        .baseAttack    = 105,
        .baseDefense   = 72,
        .baseSpeed     = 65,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 263,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Wyrdeer"),
        .cryId = CRY_WYRDEER,
        .natDexNum = NATIONAL_DEX_WYRDEER,
        .categoryName = _("Big Horn"),
        .height = 18,
        .weight = 951,
        .description = COMPOUND_STRING(
            "The black orbs shine with an uncanny light\n"
            "when it is erecting invisible barriers.\n"
            "The fur shed from its beard retains heat\n"
            "and is useful for winter clothing."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Wyrdeer,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Wyrdeer,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Wyrdeer,
        .shinyPalette = gMonShinyPalette_Wyrdeer,
        .iconSprite = gMonIcon_Wyrdeer,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_M)
        FOOTPRINT(Wyrdeer)
        OVERWORLD(
            sPicTable_Wyrdeer,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wyrdeer,
            gShinyOverworldPalette_Wyrdeer
        )
        .levelUpLearnset = sWyrdeerLevelUpLearnset,
        .teachableLearnset = sWyrdeerTeachableLearnset,
    },
#endif //P_GEN_8_CROSS_EVOS
#endif //P_FAMILY_STANTLER

#if P_FAMILY_SMEARGLE
    [SPECIES_SMEARGLE] =
    {
        .baseHP        = 55,
        .baseAttack    = 20,
        .baseDefense   = 35,
        .baseSpeed     = 75,
        .baseSpAttack  = 20,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 88 : 106,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_TECHNICIAN, ABILITY_MOODY },
    #else
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_NONE, ABILITY_MOODY },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Smeargle"),
        .cryId = CRY_SMEARGLE,
        .natDexNum = NATIONAL_DEX_SMEARGLE,
        .categoryName = _("Painter"),
        .height = 12,
        .weight = 580,
        .description = COMPOUND_STRING(
            "A Smeargle marks its territory using a\n"
            "fluid that leaks out from the tip of its\n"
            "tail. About 5,000 different marks left by\n"
            "this Pokémon have been found."),
        .pokemonScale = 287,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Smeargle,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_JUMPS : ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Smeargle,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Smeargle,
        .shinyPalette = gMonShinyPalette_Smeargle,
        .iconSprite = gMonIcon_Smeargle,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 7, SHADOW_SIZE_S)
        FOOTPRINT(Smeargle)
        OVERWORLD(
            sPicTable_Smeargle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Smeargle,
            gShinyOverworldPalette_Smeargle
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sSmeargleLevelUpLearnset,
        .teachableLearnset = sSmeargleTeachableLearnset,
    },
#endif //P_FAMILY_SMEARGLE

#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] =
    {
        .baseHP        = 95,
        .baseAttack    = 80,
        .baseDefense   = 105,
        .baseSpeed     = 100,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 200,
        .evYield_Defense = 2,
        .itemCommon = ITEM_MOOMOO_MILK,
        .itemRare = ITEM_MOOMOO_MILK,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_THICK_FAT, ABILITY_SCRAPPY, ABILITY_SAP_SIPPER },
    #else
        .abilities = { ABILITY_THICK_FAT, ABILITY_NONE, ABILITY_SAP_SIPPER },
    #endif
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Miltank"),
        .cryId = CRY_MILTANK,
        .natDexNum = NATIONAL_DEX_MILTANK,
        .categoryName = _("Milk Cow"),
        .height = 12,
        .weight = 755,
        .description = COMPOUND_STRING(
            "It gives over five gallons of milk daily.\n"
            "Its sweet milk is enjoyed by children and\n"
            "grown-ups alike. People who can't drink\n"
            "milk turn it into yogurt and eat it instead."),
        .pokemonScale = 280,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Miltank,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Miltank,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Miltank,
        .shinyPalette = gMonShinyPalette_Miltank,
        .iconSprite = gMonIcon_Miltank,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 4, SHADOW_SIZE_M)
        FOOTPRINT(Miltank)
        OVERWORLD(
            sPicTable_Miltank,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Miltank,
            gShinyOverworldPalette_Miltank
        )
        .levelUpLearnset = sMiltankLevelUpLearnset,
        .teachableLearnset = sMiltankTeachableLearnset,
        .eggMoveLearnset = sMiltankEggMoveLearnset,
    },
#endif //P_FAMILY_MILTANK

#if P_FAMILY_RAIKOU
    [SPECIES_RAIKOU] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 115,
        .baseSpAttack  = 115,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 216,
    #endif
        .evYield_Speed = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_VOLT_ABSORB },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Raikou"),
        .cryId = CRY_RAIKOU,
        .natDexNum = NATIONAL_DEX_RAIKOU,
        .categoryName = _("Thunder"),
        .height = 19,
        .weight = 1780,
        .description = COMPOUND_STRING(
            "Raikou embodies the speed of lightning.\n"
            "Its roars send shock waves shuddering\n"
            "through the air and ground as if\n"
            "lightning bolts were crashing down."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Raikou,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_FLASH_YELLOW : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Raikou,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 6,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Raikou,
        .shinyPalette = gMonShinyPalette_Raikou,
        .iconSprite = gMonIcon_Raikou,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 7, SHADOW_SIZE_L)
        FOOTPRINT(Raikou)
        OVERWORLD(
            sPicTable_Raikou,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Raikou,
            gShinyOverworldPalette_Raikou
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRaikouLevelUpLearnset,
        .teachableLearnset = sRaikouTeachableLearnset,
    },
#endif //P_FAMILY_RAIKOU

#if P_FAMILY_ENTEI
    [SPECIES_ENTEI] =
    {
        .baseHP        = 115,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 90,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 217,
    #endif
        .evYield_HP = 1,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FLASH_FIRE },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Entei"),
        .cryId = CRY_ENTEI,
        .natDexNum = NATIONAL_DEX_ENTEI,
        .categoryName = _("Volcano"),
        .height = 21,
        .weight = 1980,
        .description = COMPOUND_STRING(
            "Entei embodies the passion of magma.\n"
            "It is thought to have been born in the\n"
            "eruption of a volcano. It blasts fire that\n"
            "consumes all that it touches."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Entei,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Entei,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 11,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Entei,
        .shinyPalette = gMonShinyPalette_Entei,
        .iconSprite = gMonIcon_Entei,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_L)
        FOOTPRINT(Entei)
        OVERWORLD(
            sPicTable_Entei,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Entei,
            gShinyOverworldPalette_Entei
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sEnteiLevelUpLearnset,
        .teachableLearnset = sEnteiTeachableLearnset,
    },
#endif //P_FAMILY_ENTEI

#if P_FAMILY_SUICUNE
    [SPECIES_SUICUNE] =
    {
        .baseHP        = 100,
        .baseAttack    = 75,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 90,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 215,
    #endif
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_WATER_ABSORB },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Suicune"),
        .cryId = CRY_SUICUNE,
        .natDexNum = NATIONAL_DEX_SUICUNE,
        .categoryName = _("Aurora"),
        .height = 20,
        .weight = 1870,
        .description = COMPOUND_STRING(
            "Suicune embodies the compassion of\n"
            "a pure spring of water. It runs across\n"
            "the land with gliding elegance. It has the\n"
            "power to purify dirty water."),
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Suicune,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Suicune,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Suicune,
        .shinyPalette = gMonShinyPalette_Suicune,
        .iconSprite = gMonIcon_Suicune,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Suicune)
        OVERWORLD(
            sPicTable_Suicune,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Suicune,
            gShinyOverworldPalette_Suicune
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sSuicuneLevelUpLearnset,
        .teachableLearnset = sSuicuneTeachableLearnset,
    },
#endif //P_FAMILY_SUICUNE

#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 64,
        .baseDefense   = 50,
        .baseSpeed     = 41,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GROUND),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 67,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Larvitar"),
        .cryId = CRY_LARVITAR,
        .natDexNum = NATIONAL_DEX_LARVITAR,
        .categoryName = _("Rock Skin"),
        .height = 6,
        .weight = 720,
        .description = COMPOUND_STRING(
            "A Larvitar is born deep under the ground.\n"
            "It must eat its way through the soil above\n"
            "and reach the surface for it to see its\n"
            "parents' faces."),
        .pokemonScale = 472,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Larvitar,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Larvitar,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Larvitar,
        .shinyPalette = gMonShinyPalette_Larvitar,
        .iconSprite = gMonIcon_Larvitar,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 3, SHADOW_SIZE_S)
        FOOTPRINT(Larvitar)
        OVERWORLD(
            sPicTable_Larvitar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Larvitar,
            gShinyOverworldPalette_Larvitar
        )
        .levelUpLearnset = sLarvitarLevelUpLearnset,
        .teachableLearnset = sLarvitarTeachableLearnset,
        .eggMoveLearnset = sLarvitarEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_PUPITAR}),
    },

    [SPECIES_PUPITAR] =
    {
        .baseHP        = 70,
        .baseAttack    = 84,
        .baseDefense   = 70,
        .baseSpeed     = 51,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GROUND),
        .catchRate = 45,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Pupitar"),
        .cryId = CRY_PUPITAR,
        .natDexNum = NATIONAL_DEX_PUPITAR,
        .categoryName = _("Hard Shell"),
        .height = 12,
        .weight = 1520,
        .description = COMPOUND_STRING(
            "A Pupitar creates a gas inside its body\n"
            "that it ejects under compression to propel\n"
            "itself like a jet. Its body can withstand\n"
            "a collision with solid steel."),
        .pokemonScale = 292,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pupitar,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE : ANIM_H_SHAKE,
        .backPic = gMonBackPic_Pupitar,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 9,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Pupitar,
        .shinyPalette = gMonShinyPalette_Pupitar,
        .iconSprite = gMonIcon_Pupitar,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 3, SHADOW_SIZE_S)
        FOOTPRINT(Pupitar)
        OVERWORLD(
            sPicTable_Pupitar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Pupitar,
            gShinyOverworldPalette_Pupitar
        )
        .levelUpLearnset = sPupitarLevelUpLearnset,
        .teachableLearnset = sPupitarTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 55, SPECIES_TYRANITAR}),
    },

    [SPECIES_TYRANITAR] =
    {
        .baseHP        = 100,
        .baseAttack    = 134,
        .baseDefense   = 110,
        .baseSpeed     = 61,
        .baseSpAttack  = 95,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_ROCK, TYPE_DARK),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 218,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_SAND_STREAM, ABILITY_NONE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Tyranitar"),
        .cryId = CRY_TYRANITAR,
        .natDexNum = NATIONAL_DEX_TYRANITAR,
        .categoryName = _("Armor"),
        .height = 20,
        .weight = 2020,
        .description = COMPOUND_STRING(
            "A Tyranitar is so overwhelmingly powerful,\n"
            "it can bring down a whole mountain to make\n"
            "its nest. It roams in mountains seeking\n"
            "new opponents to fight."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Tyranitar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SHAKE : ANIM_V_SHAKE,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Tyranitar,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Tyranitar,
        .shinyPalette = gMonShinyPalette_Tyranitar,
        .iconSprite = gMonIcon_Tyranitar,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 4,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Tyranitar)
        OVERWORLD(
            sPicTable_Tyranitar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tyranitar,
            gShinyOverworldPalette_Tyranitar
        )
        .levelUpLearnset = sTyranitarLevelUpLearnset,
        .teachableLearnset = sTyranitarTeachableLearnset,
        .formSpeciesIdTable = sTyranitarFormSpeciesIdTable,
        .formChangeTable = sTyranitarFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_TYRANITAR_MEGA] =
    {
        .baseHP        = 100,
        .baseAttack    = 164,
        .baseDefense   = 150,
        .baseSpeed     = 71,
        .baseSpAttack  = 95,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_ROCK, TYPE_DARK),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_SAND_STREAM, ABILITY_SAND_STREAM, ABILITY_SAND_STREAM },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Tyranitar"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_TYRANITAR_MEGA,
    #else
        .cryId = CRY_TYRANITAR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_TYRANITAR,
        .categoryName = _("Armor"),
        .height = 25,
        .weight = 2550,
        .description = COMPOUND_STRING(
            "Due to the colossal power poured into it,\n"
            "this Pokémon's back split right open. Its\n"
            "destructive instincts are the only thing\n"
            "keeping it moving."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_TyranitarMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TyranitarMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_TyranitarMega,
        .shinyPalette = gMonShinyPalette_TyranitarMega,
        .iconSprite = gMonIcon_TyranitarMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Tyranitar)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_TyranitarMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TyranitarMega,
            gShinyOverworldPalette_TyranitarMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sTyranitarLevelUpLearnset,
        .teachableLearnset = sTyranitarTeachableLearnset,
        .formSpeciesIdTable = sTyranitarFormSpeciesIdTable,
        .formChangeTable = sTyranitarFormChangeTable,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_LARVITAR

#if P_FAMILY_LUGIA
    [SPECIES_LUGIA] =
    {
        .baseHP        = 106,
        .baseAttack    = 90,
        .baseDefense   = 130,
        .baseSpeed     = 110,
        .baseSpAttack  = 90,
        .baseSpDefense = 154,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_MULTISCALE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Lugia"),
        .cryId = CRY_LUGIA,
        .natDexNum = NATIONAL_DEX_LUGIA,
        .categoryName = _("Diving"),
        .height = 52,
        .weight = 2160,
        .description = COMPOUND_STRING(
            "Lugia is so powerful even a light\n"
            "fluttering of its wings can blow apart\n"
            "houses. As a result, it chooses to live out\n"
            "of sight deep under the sea."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        .frontPic = gMonFrontPic_Lugia,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .frontAnimDelay = 20,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Lugia,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Lugia,
        .shinyPalette = gMonShinyPalette_Lugia,
        .iconSprite = gMonIcon_Lugia,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_L)
        FOOTPRINT(Lugia)
        OVERWORLD(
            sPicTable_Lugia,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Lugia,
            gShinyOverworldPalette_Lugia
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sLugiaLevelUpLearnset,
        .teachableLearnset = sLugiaTeachableLearnset,
    },
#endif //P_FAMILY_LUGIA

#if P_FAMILY_HO_OH
    [SPECIES_HO_OH] =
    {
        .baseHP        = 106,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 110,
        .baseSpDefense = 154,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpDefense = 3,
        .itemCommon = ITEM_SACRED_ASH,
        .itemRare   = ITEM_SACRED_ASH,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ho-Oh"),
        .cryId = CRY_HO_OH,
        .natDexNum = NATIONAL_DEX_HO_OH,
        .categoryName = _("Rainbow"),
        .height = 38,
        .weight = 1990,
        .description = COMPOUND_STRING(
            "Its feathers--which glow in seven colors\n"
            "depending on the angle at which they are\n"
            "struck by light--are thought to bring joy.\n"
            "It is said to live at the foot of a rainbow."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        .frontPic = gMonFrontPic_HoOh,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_HoOh,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 2,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_HoOh,
        .shinyPalette = gMonShinyPalette_HoOh,
        .iconSprite = gMonIcon_HoOh,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 17, SHADOW_SIZE_L)
        FOOTPRINT(HoOh)
        OVERWORLD(
            sPicTable_HoOh,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_HoOh,
            gShinyOverworldPalette_HoOh
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sHoOhLevelUpLearnset,
        .teachableLearnset = sHoOhTeachableLearnset,
    },
#endif //P_FAMILY_HO_OH

#if P_FAMILY_CELEBI
    [SPECIES_CELEBI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_GRASS),
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
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Celebi"),
        .cryId = CRY_CELEBI,
        .natDexNum = NATIONAL_DEX_CELEBI,
        .categoryName = _("Time Travel"),
        .height = 6,
        .weight = 50,
        .description = COMPOUND_STRING(
            "This Pokémon came from the future by\n"
            "crossing over time. It is thought that so\n"
            "long as Celebi appears, a bright and\n"
            "shining future awaits us."),
        .pokemonScale = 393,
        .pokemonOffset = -10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Celebi,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_RISING_WOBBLE : ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 15,
        .backPic = gMonBackPic_Celebi,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_Celebi,
        .shinyPalette = gMonShinyPalette_Celebi,
        .iconSprite = gMonIcon_Celebi,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_S)
        FOOTPRINT(Celebi)
        OVERWORLD(
            sPicTable_Celebi,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Celebi,
            gShinyOverworldPalette_Celebi
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sCelebiLevelUpLearnset,
        .teachableLearnset = sCelebiTeachableLearnset,
    },
#endif //P_FAMILY_CELEBI

#ifdef __INTELLISENSE__
};
#endif
