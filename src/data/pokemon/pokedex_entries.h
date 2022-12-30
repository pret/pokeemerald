const struct PokedexEntry gPokedexEntries[] =
{
    [NATIONAL_DEX_NONE] =
    {
    #if ENGLISH
        .categoryName = _("UNKNOWN"),
    #elif FRENCH
        .categoryName = _("INCONNU"),
    #elif ITALIAN
        .categoryName = _("SCONOSC"),
    #endif
        .height = 0,
        .weight = 0,
        .description = gDummyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BULBASAUR] =
    {
    #if ENGLISH
        .categoryName = _("SEED"),
    #elif FRENCH
        .categoryName = _("GRAINE"),
    #elif ITALIAN
        .categoryName = _("SEME"),
    #endif
        .height = 7,
        .weight = 69,
        .description = gBulbasaurPokedexText,
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_IVYSAUR] =
    {
    #if ENGLISH
        .categoryName = _("SEED"),
    #elif FRENCH
        .categoryName = _("GRAINE"),
    #elif ITALIAN
        .categoryName = _("SEME"),
    #endif
        .height = 10,
        .weight = 130,
        .description = gIvysaurPokedexText,
        .pokemonScale = 335,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VENUSAUR] =
    {
    #if ENGLISH
        .categoryName = _("SEED"),
    #elif FRENCH
        .categoryName = _("GRAINE"),
    #elif ITALIAN
        .categoryName = _("SEME"),
    #endif
        .height = 20,
        .weight = 1000,
        .description = gVenusaurPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_CHARMANDER] =
    {
    #if ENGLISH
        .categoryName = _("LIZARD"),
    #elif FRENCH
        .categoryName = _("LEZARD"),
    #elif ITALIAN
        .categoryName = _("LUCERTOLA"),
    #endif
        .height = 6,
        .weight = 85,
        .description = gCharmanderPokedexText,
        .pokemonScale = 444,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHARMELEON] =
    {
    #if ENGLISH
        .categoryName = _("FLAME"),
    #elif FRENCH
        .categoryName = _("FLAMME"),
    #elif ITALIAN
        .categoryName = _("FIAMMA"),
    #endif
        .height = 11,
        .weight = 190,
        .description = gCharmeleonPokedexText,
        .pokemonScale = 302,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHARIZARD] =
    {
    #if ENGLISH
        .categoryName = _("FLAME"),
    #elif FRENCH
        .categoryName = _("FLAMME"),
    #elif ITALIAN
        .categoryName = _("FIAMMA"),
    #endif
        .height = 17,
        .weight = 905,
        .description = gCharizardPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_SQUIRTLE] =
    {
    #if ENGLISH
        .categoryName = _("TINY TURTLE"),
    #elif FRENCH
        .categoryName = _("MINITORTUE"),
    #elif ITALIAN
        .categoryName = _("TARTAGHINA"),
    #endif
        .height = 5,
        .weight = 90,
        .description = gSquirtlePokedexText,
        .pokemonScale = 412,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WARTORTLE] =
    {
    #if ENGLISH
        .categoryName = _("TURTLE"),
    #elif FRENCH
        .categoryName = _("TORTUE"),
    #elif ITALIAN
        .categoryName = _("TARTARUGA"),
    #endif
        .height = 10,
        .weight = 225,
        .description = gWartortlePokedexText,
        .pokemonScale = 332,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BLASTOISE] =
    {
    #if ENGLISH
        .categoryName = _("SHELLFISH"),
    #elif FRENCH
        .categoryName = _("CARAPACE"),
    #elif ITALIAN
        .categoryName = _("CROSTACEO"),
    #endif
        .height = 16,
        .weight = 855,
        .description = gBlastoisePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CATERPIE] =
    {
    #if ENGLISH
        .categoryName = _("WORM"),
    #elif FRENCH
        .categoryName = _("VER"),
    #elif ITALIAN
        .categoryName = _("BACO"),
    #endif
        .height = 3,
        .weight = 29,
        .description = gCaterpiePokedexText,
        .pokemonScale = 549,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_METAPOD] =
    {
    #if ENGLISH
        .categoryName = _("COCOON"),
    #elif FRENCH
        .categoryName = _("COCON"),
    #elif ITALIAN
        .categoryName = _("BOZZOLO"),
    #endif
        .height = 7,
        .weight = 99,
        .description = gMetapodPokedexText,
        .pokemonScale = 350,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BUTTERFREE] =
    {
    #if ENGLISH
        .categoryName = _("BUTTERFLY"),
    #elif FRENCH
        .categoryName = _("PAPILLON"),
    #elif ITALIAN
        .categoryName = _("FARFALLA"),
    #endif
        .height = 11,
        .weight = 320,
        .description = gButterfreePokedexText,
        .pokemonScale = 312,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WEEDLE] =
    {
    #if ENGLISH
        .categoryName = _("HAIRY BUG"),
    #elif FRENCH
        .categoryName = _("INSECTOPIC"),
    #elif ITALIAN
        .categoryName = _("MILLEPIEDI"),
    #endif
        .height = 3,
        .weight = 32,
        .description = gWeedlePokedexText,
        .pokemonScale = 455,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KAKUNA] =
    {
    #if ENGLISH
        .categoryName = _("COCOON"),
    #elif FRENCH
        .categoryName = _("COCON"),
    #elif ITALIAN
        .categoryName = _("BOZZOLO"),
    #endif
        .height = 6,
        .weight = 100,
        .description = gKakunaPokedexText,
        .pokemonScale = 424,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BEEDRILL] =
    {
    #if ENGLISH
        .categoryName = _("POISON BEE"),
    #elif FRENCH
        .categoryName = _("GUEPOISON"),
    #elif ITALIAN
        .categoryName = _("VELENAPE"),
    #endif
        .height = 10,
        .weight = 295,
        .description = gBeedrillPokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PIDGEY] =
    {
    #if ENGLISH
        .categoryName = _("TINY BIRD"),
    #elif FRENCH
        .categoryName = _("MINOISEAU"),
    #elif ITALIAN
        .categoryName = _("UCCELLINO"),
    #endif
        .height = 3,
        .weight = 18,
        .description = gPidgeyPokedexText,
        .pokemonScale = 508,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PIDGEOTTO] =
    {
    #if ENGLISH
        .categoryName = _("BIRD"),
    #elif FRENCH
        .categoryName = _("OISEAU"),
    #elif ITALIAN
        .categoryName = _("UCCELLO"),
    #endif
        .height = 11,
        .weight = 300,
        .description = gPidgeottoPokedexText,
        .pokemonScale = 331,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PIDGEOT] =
    {
    #if ENGLISH
        .categoryName = _("BIRD"),
    #elif FRENCH
        .categoryName = _("OISEAU"),
    #elif ITALIAN
        .categoryName = _("UCCELLO"),
    #endif
        .height = 15,
        .weight = 395,
        .description = gPidgeotPokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RATTATA] =
    {
    #if ENGLISH
        .categoryName = _("MOUSE"),
    #elif FRENCH
        .categoryName = _("SOURIS"),
    #elif ITALIAN
        .categoryName = _("TOPO"),
    #endif
        .height = 3,
        .weight = 35,
        .description = gRattataPokedexText,
        .pokemonScale = 481,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RATICATE] =
    {
    #if ENGLISH
        .categoryName = _("MOUSE"),
    #elif FRENCH
        .categoryName = _("SOURIS"),
    #elif ITALIAN
        .categoryName = _("TOPO"),
    #endif
        .height = 7,
        .weight = 185,
        .description = gRaticatePokedexText,
        .pokemonScale = 459,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPEAROW] =
    {
    #if ENGLISH
        .categoryName = _("TINY BIRD"),
    #elif FRENCH
        .categoryName = _("MINOISEAU"),
    #elif ITALIAN
        .categoryName = _("UCCELLINO"),
    #endif
        .height = 3,
        .weight = 20,
        .description = gSpearowPokedexText,
        .pokemonScale = 571,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FEAROW] =
    {
    #if ENGLISH
        .categoryName = _("BEAK"),
    #elif FRENCH
        .categoryName = _("BEC-OISEAU"),
    #elif ITALIAN
        .categoryName = _("BECCO"),
    #endif
        .height = 12,
        .weight = 380,
        .description = gFearowPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_EKANS] =
    {
    #if ENGLISH
        .categoryName = _("SNAKE"),
    #elif FRENCH
        .categoryName = _("SERPENT"),
    #elif ITALIAN
        .categoryName = _("SERPENTE"),
    #endif
        .height = 20,
        .weight = 69,
        .description = gEkansPokedexText,
        .pokemonScale = 298,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARBOK] =
    {
    #if ENGLISH
        .categoryName = _("COBRA"),
    #elif FRENCH
        .categoryName = _("COBRA"),
    #elif ITALIAN
        .categoryName = _("COBRA"),
    #endif
        .height = 35,
        .weight = 650,
        .description = gArbokPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_PIKACHU] =
    {
    #if ENGLISH
        .categoryName = _("MOUSE"),
    #elif FRENCH
        .categoryName = _("SOURIS"),
    #elif ITALIAN
        .categoryName = _("TOPO"),
    #endif
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RAICHU] =
    {
    #if ENGLISH
        .categoryName = _("MOUSE"),
    #elif FRENCH
        .categoryName = _("SOURIS"),
    #elif ITALIAN
        .categoryName = _("TOPO"),
    #endif
        .height = 8,
        .weight = 300,
        .description = gRaichuPokedexText,
        .pokemonScale = 426,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SANDSHREW] =
    {
    #if ENGLISH
        .categoryName = _("MOUSE"),
    #elif FRENCH
        .categoryName = _("SOURIS"),
    #elif ITALIAN
        .categoryName = _("TOPO"),
    #endif
        .height = 6,
        .weight = 120,
        .description = gSandshrewPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SANDSLASH] =
    {
    #if ENGLISH
        .categoryName = _("MOUSE"),
    #elif FRENCH
        .categoryName = _("SOURIS"),
    #elif ITALIAN
        .categoryName = _("TOPO"),
    #endif
        .height = 10,
        .weight = 295,
        .description = gSandslashPokedexText,
        .pokemonScale = 341,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NIDORAN_F] =
    {
    #if ENGLISH
        .categoryName = _("POISON PIN"),
    #elif FRENCH
        .categoryName = _("VENEPIC"),
    #elif ITALIAN
        .categoryName = _("VELENAGO"),
    #endif
        .height = 4,
        .weight = 70,
        .description = gNidoranFPokedexText,
        .pokemonScale = 488,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NIDORINA] =
    {
    #if ENGLISH
        .categoryName = _("POISON PIN"),
    #elif FRENCH
        .categoryName = _("VENEPIC"),
    #elif ITALIAN
        .categoryName = _("VELENAGO"),
    #endif
        .height = 8,
        .weight = 200,
        .description = gNidorinaPokedexText,
        .pokemonScale = 381,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NIDOQUEEN] =
    {
    #if ENGLISH
        .categoryName = _("DRILL"),
    #elif FRENCH
        .categoryName = _("PERCEUR"),
    #elif ITALIAN
        .categoryName = _("TRAPANO"),
    #endif
        .height = 13,
        .weight = 600,
        .description = gNidoqueenPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NIDORAN_M] =
    {
    #if ENGLISH
        .categoryName = _("POISON PIN"),
    #elif FRENCH
        .categoryName = _("VENEPIC"),
    #elif ITALIAN
        .categoryName = _("VELENAGO"),
    #endif
        .height = 5,
        .weight = 90,
        .description = gNidoranMPokedexText,
        .pokemonScale = 511,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NIDORINO] =
    {
    #if ENGLISH
        .categoryName = _("POISON PIN"),
    #elif FRENCH
        .categoryName = _("VENEPIC"),
    #elif ITALIAN
        .categoryName = _("VELENAGO"),
    #endif
        .height = 9,
        .weight = 195,
        .description = gNidorinoPokedexText,
        .pokemonScale = 408,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NIDOKING] =
    {
    #if ENGLISH
        .categoryName = _("DRILL"),
    #elif FRENCH
        .categoryName = _("PERCEUR"),
    #elif ITALIAN
        .categoryName = _("TRAPANO"),
    #endif
        .height = 14,
        .weight = 620,
        .description = gNidokingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLEFAIRY] =
    {
    #if ENGLISH
        .categoryName = _("FAIRY"),
    #elif FRENCH
        .categoryName = _("FEE"),
    #elif ITALIAN
        .categoryName = _("FATA"),
    #endif
        .height = 6,
        .weight = 75,
        .description = gClefairyPokedexText,
        .pokemonScale = 441,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLEFABLE] =
    {
    #if ENGLISH
        .categoryName = _("FAIRY"),
    #elif FRENCH
        .categoryName = _("FEE"),
    #elif ITALIAN
        .categoryName = _("FATA"),
    #endif
        .height = 13,
        .weight = 400,
        .description = gClefablePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VULPIX] =
    {
    #if ENGLISH
        .categoryName = _("FOX"),
    #elif FRENCH
        .categoryName = _("RENARD"),
    #elif ITALIAN
        .categoryName = _("VOLPE"),
    #endif
        .height = 6,
        .weight = 99,
        .description = gVulpixPokedexText,
        .pokemonScale = 542,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NINETALES] =
    {
    #if ENGLISH
        .categoryName = _("FOX"),
    #elif FRENCH
        .categoryName = _("RENARD"),
    #elif ITALIAN
        .categoryName = _("VOLPE"),
    #endif
        .height = 11,
        .weight = 199,
        .description = gNinetalesPokedexText,
        .pokemonScale = 339,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_JIGGLYPUFF] =
    {
    #if ENGLISH
        .categoryName = _("BALLOON"),
    #elif FRENCH
        .categoryName = _("BOUBOULE"),
    #elif ITALIAN
        .categoryName = _("PALLONE"),
    #endif
        .height = 5,
        .weight = 55,
        .description = gJigglypuffPokedexText,
        .pokemonScale = 433,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WIGGLYTUFF] =
    {
    #if ENGLISH
        .categoryName = _("BALLOON"),
    #elif FRENCH
        .categoryName = _("BOUBOULE"),
    #elif ITALIAN
        .categoryName = _("PALLONE"),
    #endif
        .height = 10,
        .weight = 120,
        .description = gWigglytuffPokedexText,
        .pokemonScale = 328,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZUBAT] =
    {
    #if ENGLISH
        .categoryName = _("BAT"),
    #elif FRENCH
        .categoryName = _("CHOVSOURIS"),
    #elif ITALIAN
        .categoryName = _("PIPISTREL."),
    #endif
        .height = 8,
        .weight = 75,
        .description = gZubatPokedexText,
        .pokemonScale = 362,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOLBAT] =
    {
    #if ENGLISH
        .categoryName = _("BAT"),
    #elif FRENCH
        .categoryName = _("CHOVSOURIS"),
    #elif ITALIAN
        .categoryName = _("PIPISTREL."),
    #endif
        .height = 16,
        .weight = 550,
        .description = gGolbatPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ODDISH] =
    {
    #if ENGLISH
        .categoryName = _("WEED"),
    #elif FRENCH
        .categoryName = _("RACINE"),
    #elif ITALIAN
        .categoryName = _("MALERBA"),
    #endif
        .height = 5,
        .weight = 54,
        .description = gOddishPokedexText,
        .pokemonScale = 423,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GLOOM] =
    {
    #if ENGLISH
        .categoryName = _("WEED"),
    #elif FRENCH
        .categoryName = _("RACINE"),
    #elif ITALIAN
        .categoryName = _("MALERBA"),
    #endif
        .height = 8,
        .weight = 86,
        .description = gGloomPokedexText,
        .pokemonScale = 329,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VILEPLUME] =
    {
    #if ENGLISH
        .categoryName = _("FLOWER"),
    #elif FRENCH
        .categoryName = _("FLEUR"),
    #elif ITALIAN
        .categoryName = _("FIORE"),
    #endif
        .height = 12,
        .weight = 186,
        .description = gVileplumePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PARAS] =
    {
    #if ENGLISH
        .categoryName = _("MUSHROOM"),
    #elif FRENCH
        .categoryName = _("CHAMPIGNON"),
    #elif ITALIAN
        .categoryName = _("FUNGO"),
    #endif
        .height = 3,
        .weight = 54,
        .description = gParasPokedexText,
        .pokemonScale = 593,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PARASECT] =
    {
    #if ENGLISH
        .categoryName = _("MUSHROOM"),
    #elif FRENCH
        .categoryName = _("CHAMPIGNON"),
    #elif ITALIAN
        .categoryName = _("FUNGO"),
    #endif
        .height = 10,
        .weight = 295,
        .description = gParasectPokedexText,
        .pokemonScale = 307,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VENONAT] =
    {
    #if ENGLISH
        .categoryName = _("INSECT"),
    #elif FRENCH
        .categoryName = _("VERMINE"),
    #elif ITALIAN
        .categoryName = _("INSETTO"),
    #endif
        .height = 10,
        .weight = 300,
        .description = gVenonatPokedexText,
        .pokemonScale = 360,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_VENOMOTH] =
    {
    #if ENGLISH
        .categoryName = _("POISON MOTH"),
    #elif FRENCH
        .categoryName = _("PAPIPOISON"),
    #elif ITALIAN
        .categoryName = _("VELENTARMA"),
    #endif
        .height = 15,
        .weight = 125,
        .description = gVenomothPokedexText,
        .pokemonScale = 285,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_DIGLETT] =
    {
    #if ENGLISH
        .categoryName = _("MOLE"),
    #elif FRENCH
        .categoryName = _("TAUPE"),
    #elif ITALIAN
        .categoryName = _("TALPA"),
    #endif
        .height = 2,
        .weight = 8,
        .description = gDiglettPokedexText,
        .pokemonScale = 833,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DUGTRIO] =
    {
    #if ENGLISH
        .categoryName = _("MOLE"),
    #elif FRENCH
        .categoryName = _("TAUPE"),
    #elif ITALIAN
        .categoryName = _("TALPA"),
    #endif
        .height = 7,
        .weight = 333,
        .description = gDugtrioPokedexText,
        .pokemonScale = 406,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MEOWTH] =
    {
    #if ENGLISH
        .categoryName = _("SCRATCH CAT"),
    #elif FRENCH
        .categoryName = _("CHADEGOUT"),
    #elif ITALIAN
        .categoryName = _("GRAFFIMIAO"),
    #endif
        .height = 4,
        .weight = 42,
        .description = gMeowthPokedexText,
        .pokemonScale = 480,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PERSIAN] =
    {
    #if ENGLISH
        .categoryName = _("CLASSY CAT"),
    #elif FRENCH
        .categoryName = _("CHADEVILLE"),
    #elif ITALIAN
        .categoryName = _("NOBILGATTO"),
    #endif
        .height = 10,
        .weight = 320,
        .description = gPersianPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PSYDUCK] =
    {
    #if ENGLISH
        .categoryName = _("DUCK"),
    #elif FRENCH
        .categoryName = _("CANARD"),
    #elif ITALIAN
        .categoryName = _("PAPERO"),
    #endif
        .height = 8,
        .weight = 196,
        .description = gPsyduckPokedexText,
        .pokemonScale = 369,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOLDUCK] =
    {
    #if ENGLISH
        .categoryName = _("DUCK"),
    #elif FRENCH
        .categoryName = _("CANARD"),
    #elif ITALIAN
        .categoryName = _("PAPERO"),
    #endif
        .height = 17,
        .weight = 766,
        .description = gGolduckPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 273,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_MANKEY] =
    {
    #if ENGLISH
        .categoryName = _("PIG MONKEY"),
    #elif FRENCH
        .categoryName = _("PORSINGE"),
    #elif ITALIAN
        .categoryName = _("SUINPANZÉ"),
    #endif
        .height = 5,
        .weight = 280,
        .description = gMankeyPokedexText,
        .pokemonScale = 404,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PRIMEAPE] =
    {
    #if ENGLISH
        .categoryName = _("PIG MONKEY"),
    #elif FRENCH
        .categoryName = _("PORSINGE"),
    #elif ITALIAN
        .categoryName = _("SUINPANZÉ"),
    #endif
        .height = 10,
        .weight = 320,
        .description = gPrimeapePokedexText,
        .pokemonScale = 326,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GROWLITHE] =
    {
    #if ENGLISH
        .categoryName = _("PUPPY"),
    #elif FRENCH
        .categoryName = _("CHIOT"),
    #elif ITALIAN
        .categoryName = _("CAGNOLINO"),
    #endif
        .height = 7,
        .weight = 190,
        .description = gGrowlithePokedexText,
        .pokemonScale = 346,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARCANINE] =
    {
    #if ENGLISH
        .categoryName = _("LEGENDARY"),
    #elif FRENCH
        .categoryName = _("LEGENDAIRE"),
    #elif ITALIAN
        .categoryName = _("LEGGENDA"),
    #endif
        .height = 19,
        .weight = 1550,
        .description = gArcaninePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 312,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_POLIWAG] =
    {
    #if ENGLISH
        .categoryName = _("TADPOLE"),
    #elif FRENCH
        .categoryName = _("TETARD"),
    #elif ITALIAN
        .categoryName = _("GIRINO"),
    #endif
        .height = 6,
        .weight = 124,
        .description = gPoliwagPokedexText,
        .pokemonScale = 369,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_POLIWHIRL] =
    {
    #if ENGLISH
        .categoryName = _("TADPOLE"),
    #elif FRENCH
        .categoryName = _("TETARD"),
    #elif ITALIAN
        .categoryName = _("GIRINO"),
    #endif
        .height = 10,
        .weight = 200,
        .description = gPoliwhirlPokedexText,
        .pokemonScale = 288,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_POLIWRATH] =
    {
    #if ENGLISH
        .categoryName = _("TADPOLE"),
    #elif FRENCH
        .categoryName = _("TETARD"),
    #elif ITALIAN
        .categoryName = _("GIRINO"),
    #endif
        .height = 13,
        .weight = 540,
        .description = gPoliwrathPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ABRA] =
    {
    #if ENGLISH
        .categoryName = _("PSI"),
    #elif FRENCH
        .categoryName = _("PSY"),
    #elif ITALIAN
        .categoryName = _("PSICO"),
    #endif
        .height = 9,
        .weight = 195,
        .description = gAbraPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KADABRA] =
    {
    #if ENGLISH
        .categoryName = _("PSI"),
    #elif FRENCH
        .categoryName = _("PSY"),
    #elif ITALIAN
        .categoryName = _("PSICO"),
    #endif
        .height = 13,
        .weight = 565,
        .description = gKadabraPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ALAKAZAM] =
    {
    #if ENGLISH
        .categoryName = _("PSI"),
    #elif FRENCH
        .categoryName = _("PSY"),
    #elif ITALIAN
        .categoryName = _("PSICO"),
    #endif
        .height = 15,
        .weight = 480,
        .description = gAlakazamPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MACHOP] =
    {
    #if ENGLISH
        .categoryName = _("SUPERPOWER"),
    #elif FRENCH
        .categoryName = _("COLOSSE"),
    #elif ITALIAN
        .categoryName = _("MEGAFORZA"),
    #endif
        .height = 8,
        .weight = 195,
        .description = gMachopPokedexText,
        .pokemonScale = 342,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MACHOKE] =
    {
    #if ENGLISH
        .categoryName = _("SUPERPOWER"),
    #elif FRENCH
        .categoryName = _("COLOSSE"),
    #elif ITALIAN
        .categoryName = _("MEGAFORZA"),
    #endif
        .height = 15,
        .weight = 705,
        .description = gMachokePokedexText,
        .pokemonScale = 323,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MACHAMP] =
    {
    #if ENGLISH
        .categoryName = _("SUPERPOWER"),
    #elif FRENCH
        .categoryName = _("COLOSSE"),
    #elif ITALIAN
        .categoryName = _("MEGAFORZA"),
    #endif
        .height = 16,
        .weight = 1300,
        .description = gMachampPokedexText,
        .pokemonScale = 280,
        .pokemonOffset = 1,
        .trainerScale = 269,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_BELLSPROUT] =
    {
    #if ENGLISH
        .categoryName = _("FLOWER"),
    #elif FRENCH
        .categoryName = _("FLEUR"),
    #elif ITALIAN
        .categoryName = _("FIORE"),
    #endif
        .height = 7,
        .weight = 40,
        .description = gBellsproutPokedexText,
        .pokemonScale = 354,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WEEPINBELL] =
    {
    #if ENGLISH
        .categoryName = _("FLYCATCHER"),
    #elif FRENCH
        .categoryName = _("CARNIVORE"),
    #elif ITALIAN
        .categoryName = _("MOSCHIVORO"),
    #endif
        .height = 10,
        .weight = 64,
        .description = gWeepinbellPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VICTREEBEL] =
    {
    #if ENGLISH
        .categoryName = _("FLYCATCHER"),
    #elif FRENCH
        .categoryName = _("CARNIVORE"),
    #elif ITALIAN
        .categoryName = _("MOSCHIVORO"),
    #endif
        .height = 17,
        .weight = 155,
        .description = gVictreebelPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 312,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_TENTACOOL] =
    {
    #if ENGLISH
        .categoryName = _("JELLYFISH"),
    #elif FRENCH
        .categoryName = _("MOLLUSQUE"),
    #elif ITALIAN
        .categoryName = _("MEDUSA"),
    #endif
        .height = 9,
        .weight = 455,
        .description = gTentacoolPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TENTACRUEL] =
    {
    #if ENGLISH
        .categoryName = _("JELLYFISH"),
    #elif FRENCH
        .categoryName = _("MOLLUSQUE"),
    #elif ITALIAN
        .categoryName = _("MEDUSA"),
    #endif
        .height = 16,
        .weight = 550,
        .description = gTentacruelPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 312,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_GEODUDE] =
    {
    #if ENGLISH
        .categoryName = _("ROCK"),
    #elif FRENCH
        .categoryName = _("ROCHE"),
    #elif ITALIAN
        .categoryName = _("ROCCIA"),
    #endif
        .height = 4,
        .weight = 200,
        .description = gGeodudePokedexText,
        .pokemonScale = 347,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GRAVELER] =
    {
    #if ENGLISH
        .categoryName = _("ROCK"),
    #elif FRENCH
        .categoryName = _("ROCHE"),
    #elif ITALIAN
        .categoryName = _("ROCCIA"),
    #endif
        .height = 10,
        .weight = 1050,
        .description = gGravelerPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOLEM] =
    {
    #if ENGLISH
        .categoryName = _("MEGATON"),
    #elif FRENCH
        .categoryName = _("TITANESQUE"),
    #elif ITALIAN
        .categoryName = _("MEGATONE"),
    #endif
        .height = 14,
        .weight = 3000,
        .description = gGolemPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_PONYTA] =
    {
    #if ENGLISH
        .categoryName = _("FIRE HORSE"),
    #elif FRENCH
        .categoryName = _("CHEVAL FEU"),
    #elif ITALIAN
        .categoryName = _("CAVALFUOCO"),
    #endif
        .height = 10,
        .weight = 300,
        .description = gPonytaPokedexText,
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RAPIDASH] =
    {
    #if ENGLISH
        .categoryName = _("FIRE HORSE"),
    #elif FRENCH
        .categoryName = _("CHEVAL FEU"),
    #elif ITALIAN
        .categoryName = _("CAVALFUOCO"),
    #endif
        .height = 17,
        .weight = 950,
        .description = gRapidashPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 289,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SLOWPOKE] =
    {
    #if ENGLISH
        .categoryName = _("DOPEY"),
    #elif FRENCH
        .categoryName = _("CRETIN"),
    #elif ITALIAN
        .categoryName = _("RONFONE"),
    #endif
        .height = 12,
        .weight = 360,
        .description = gSlowpokePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLOWBRO] =
    {
    #if ENGLISH
        .categoryName = _("HERMIT CRAB"),
    #elif FRENCH
        .categoryName = _("SYMBIOSE"),
    #elif ITALIAN
        .categoryName = _("PAGURO"),
    #endif
        .height = 16,
        .weight = 785,
        .description = gSlowbroPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_MAGNEMITE] =
    {
    #if ENGLISH
        .categoryName = _("MAGNET"),
    #elif FRENCH
        .categoryName = _("MAGNETIQUE"),
    #elif ITALIAN
        .categoryName = _("CALAMITA"),
    #endif
        .height = 3,
        .weight = 60,
        .description = gMagnemitePokedexText,
        .pokemonScale = 288,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGNETON] =
    {
    #if ENGLISH
        .categoryName = _("MAGNET"),
    #elif FRENCH
        .categoryName = _("MAGNETIQUE"),
    #elif ITALIAN
        .categoryName = _("CALAMITA"),
    #endif
        .height = 10,
        .weight = 600,
        .description = gMagnetonPokedexText,
        .pokemonScale = 292,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FARFETCHD] =
    {
    #if ENGLISH
        .categoryName = _("WILD DUCK"),
    #elif FRENCH
        .categoryName = _("CANARD FOU"),
    #elif ITALIAN
        .categoryName = _("SELVANATRA"),
    #endif
        .height = 8,
        .weight = 150,
        .description = gFarfetchdPokedexText,
        .pokemonScale = 330,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_DODUO] =
    {
    #if ENGLISH
        .categoryName = _("TWIN BIRD"),
    #elif FRENCH
        .categoryName = _("DUOISEAU"),
    #elif ITALIAN
        .categoryName = _("BIUCCELLO"),
    #endif
        .height = 14,
        .weight = 392,
        .description = gDoduoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_DODRIO] =
    {
    #if ENGLISH
        .categoryName = _("TRIPLE BIRD"),
    #elif FRENCH
        .categoryName = _("TRIOISEAU"),
    #elif ITALIAN
        .categoryName = _("TRIUCCELLO"),
    #endif
        .height = 18,
        .weight = 852,
        .description = gDodrioPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SEEL] =
    {
    #if ENGLISH
        .categoryName = _("SEA LION"),
    #elif FRENCH
        .categoryName = _("OTARIE"),
    #elif ITALIAN
        .categoryName = _("OTARIA"),
    #endif
        .height = 11,
        .weight = 900,
        .description = gSeelPokedexText,
        .pokemonScale = 297,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DEWGONG] =
    {
    #if ENGLISH
        .categoryName = _("SEA LION"),
    #elif FRENCH
        .categoryName = _("OTARIE"),
    #elif ITALIAN
        .categoryName = _("OTARIA"),
    #endif
        .height = 17,
        .weight = 1200,
        .description = gDewgongPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 275,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GRIMER] =
    {
    #if ENGLISH
        .categoryName = _("SLUDGE"),
    #elif FRENCH
        .categoryName = _("DEGUEU"),
    #elif ITALIAN
        .categoryName = _("MELMA"),
    #endif
        .height = 9,
        .weight = 300,
        .description = gGrimerPokedexText,
        .pokemonScale = 258,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MUK] =
    {
    #if ENGLISH
        .categoryName = _("SLUDGE"),
    #elif FRENCH
        .categoryName = _("DEGUEU"),
    #elif ITALIAN
        .categoryName = _("MELMA"),
    #endif
        .height = 12,
        .weight = 300,
        .description = gMukPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHELLDER] =
    {
    #if ENGLISH
        .categoryName = _("BIVALVE"),
    #elif FRENCH
        .categoryName = _("BIVALVE"),
    #elif ITALIAN
        .categoryName = _("BIVALVE"),
    #endif
        .height = 3,
        .weight = 40,
        .description = gShellderPokedexText,
        .pokemonScale = 675,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLOYSTER] =
    {
    #if ENGLISH
        .categoryName = _("BIVALVE"),
    #elif FRENCH
        .categoryName = _("BIVALVE"),
    #elif ITALIAN
        .categoryName = _("BIVALVE"),
    #endif
        .height = 15,
        .weight = 1325,
        .description = gCloysterPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 269,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_GASTLY] =
    {
    #if ENGLISH
        .categoryName = _("GAS"),
    #elif FRENCH
        .categoryName = _("GAZ"),
    #elif ITALIAN
        .categoryName = _("GAS"),
    #endif
        .height = 13,
        .weight = 1,
        .description = gGastlyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HAUNTER] =
    {
    #if ENGLISH
        .categoryName = _("GAS"),
    #elif FRENCH
        .categoryName = _("GAZ"),
    #elif ITALIAN
        .categoryName = _("GAS"),
    #endif
        .height = 16,
        .weight = 1,
        .description = gHaunterPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_GENGAR] =
    {
    #if ENGLISH
        .categoryName = _("SHADOW"),
    #elif FRENCH
        .categoryName = _("OMBRE"),
    #elif ITALIAN
        .categoryName = _("OMBRA"),
    #endif
        .height = 15,
        .weight = 405,
        .description = gGengarPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 302,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_ONIX] =
    {
    #if ENGLISH
        .categoryName = _("ROCK SNAKE"),
    #elif FRENCH
        .categoryName = _("SERPENROC"),
    #elif ITALIAN
        .categoryName = _("SERPESASSO"),
    #endif
        .height = 88,
        .weight = 2100,
        .description = gOnixPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 515,
        .trainerOffset = 14,
    },

    [NATIONAL_DEX_DROWZEE] =
    {
    #if ENGLISH
        .categoryName = _("HYPNOSIS"),
    #elif FRENCH
        .categoryName = _("HYPNOSE"),
    #elif ITALIAN
        .categoryName = _("IPNOSI"),
    #endif
        .height = 10,
        .weight = 324,
        .description = gDrowzeePokedexText,
        .pokemonScale = 274,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HYPNO] =
    {
    #if ENGLISH
        .categoryName = _("HYPNOSIS"),
    #elif FRENCH
        .categoryName = _("HYPNOSE"),
    #elif ITALIAN
        .categoryName = _("IPNOSI"),
    #endif
        .height = 16,
        .weight = 756,
        .description = gHypnoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KRABBY] =
    {
    #if ENGLISH
        .categoryName = _("RIVER CRAB"),
    #elif FRENCH
        .categoryName = _("DOUX CRABE"),
    #elif ITALIAN
        .categoryName = _("GRANCHIO"),
    #endif
        .height = 4,
        .weight = 65,
        .description = gKrabbyPokedexText,
        .pokemonScale = 469,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KINGLER] =
    {
    #if ENGLISH
        .categoryName = _("PINCER"),
    #elif FRENCH
        .categoryName = _("PINCE"),
    #elif ITALIAN
        .categoryName = _("CHELA"),
    #endif
        .height = 13,
        .weight = 600,
        .description = gKinglerPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VOLTORB] =
    {
    #if ENGLISH
        .categoryName = _("BALL"),
    #elif FRENCH
        .categoryName = _("BALLE"),
    #elif ITALIAN
        .categoryName = _("BALL"),
    #endif
        .height = 5,
        .weight = 104,
        .description = gVoltorbPokedexText,
        .pokemonScale = 364,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ELECTRODE] =
    {
    #if ENGLISH
        .categoryName = _("BALL"),
    #elif FRENCH
        .categoryName = _("BALLE"),
    #elif ITALIAN
        .categoryName = _("BALL"),
    #endif
        .height = 12,
        .weight = 666,
        .description = gElectrodePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_EXEGGCUTE] =
    {
    #if ENGLISH
        .categoryName = _("EGG"),
    #elif FRENCH
        .categoryName = _("OEUF"),
    #elif ITALIAN
        .categoryName = _("UOVO"),
    #endif
        .height = 4,
        .weight = 25,
        .description = gExeggcutePokedexText,
        .pokemonScale = 489,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_EXEGGUTOR] =
    {
    #if ENGLISH
        .categoryName = _("COCONUT"),
    #elif FRENCH
        .categoryName = _("FRUITPALME"),
    #elif ITALIAN
        .categoryName = _("NOCECOCCO"),
    #endif
        .height = 20,
        .weight = 1200,
        .description = gExeggutorPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_CUBONE] =
    {
    #if ENGLISH
        .categoryName = _("LONELY"),
    #elif FRENCH
        .categoryName = _("SOLITAIRE"),
    #elif ITALIAN
        .categoryName = _("SOLITARIO"),
    #endif
        .height = 4,
        .weight = 65,
        .description = gCubonePokedexText,
        .pokemonScale = 545,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAROWAK] =
    {
    #if ENGLISH
        .categoryName = _("BONE KEEPER"),
    #elif FRENCH
        .categoryName = _("GARD'OS"),
    #elif ITALIAN
        .categoryName = _("GUARDAOSSI"),
    #endif
        .height = 10,
        .weight = 450,
        .description = gMarowakPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HITMONLEE] =
    {
    #if ENGLISH
        .categoryName = _("KICKING"),
    #elif FRENCH
        .categoryName = _("LATTEUR"),
    #elif ITALIAN
        .categoryName = _("TIRACALCI"),
    #endif
        .height = 15,
        .weight = 498,
        .description = gHitmonleePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 259,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_HITMONCHAN] =
    {
    #if ENGLISH
        .categoryName = _("PUNCHING"),
    #elif FRENCH
        .categoryName = _("PUNCHEUR"),
    #elif ITALIAN
        .categoryName = _("TIRAPUGNI"),
    #endif
        .height = 14,
        .weight = 502,
        .description = gHitmonchanPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 277,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_LICKITUNG] =
    {
    #if ENGLISH
        .categoryName = _("LICKING"),
    #elif FRENCH
        .categoryName = _("LECHEUR"),
    #elif ITALIAN
        .categoryName = _("LINGUACCIA"),
    #endif
        .height = 12,
        .weight = 655,
        .description = gLickitungPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KOFFING] =
    {
    #if ENGLISH
        .categoryName = _("POISON GAS"),
    #elif FRENCH
        .categoryName = _("GAZ MORTEL"),
    #elif ITALIAN
        .categoryName = _("VELENUVOLA"),
    #endif
        .height = 6,
        .weight = 10,
        .description = gKoffingPokedexText,
        .pokemonScale = 369,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WEEZING] =
    {
    #if ENGLISH
        .categoryName = _("POISON GAS"),
    #elif FRENCH
        .categoryName = _("GAZ MORTEL"),
    #elif ITALIAN
        .categoryName = _("VELENUVOLA"),
    #endif
        .height = 12,
        .weight = 95,
        .description = gWeezingPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RHYHORN] =
    {
    #if ENGLISH
        .categoryName = _("SPIKES"),
    #elif FRENCH
        .categoryName = _("PIQUANT"),
    #elif ITALIAN
        .categoryName = _("PUNZONI"),
    #endif
        .height = 10,
        .weight = 1150,
        .description = gRhyhornPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RHYDON] =
    {
    #if ENGLISH
        .categoryName = _("DRILL"),
    #elif FRENCH
        .categoryName = _("PERCEUR"),
    #elif ITALIAN
        .categoryName = _("TRAPANO"),
    #endif
        .height = 19,
        .weight = 1200,
        .description = gRhydonPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 299,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_CHANSEY] =
    {
    #if ENGLISH
        .categoryName = _("EGG"),
    #elif FRENCH
        .categoryName = _("OEUF"),
    #elif ITALIAN
        .categoryName = _("UOVO"),
    #endif
        .height = 11,
        .weight = 346,
        .description = gChanseyPokedexText,
        .pokemonScale = 257,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TANGELA] =
    {
    #if ENGLISH
        .categoryName = _("VINE"),
    #elif FRENCH
        .categoryName = _("VIGNE"),
    #elif ITALIAN
        .categoryName = _("LIANA"),
    #endif
        .height = 10,
        .weight = 350,
        .description = gTangelaPokedexText,
        .pokemonScale = 304,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KANGASKHAN] =
    {
    #if ENGLISH
        .categoryName = _("PARENT"),
    #elif FRENCH
        .categoryName = _("MATERNEL"),
    #elif ITALIAN
        .categoryName = _("GENITORE"),
    #endif
        .height = 22,
        .weight = 800,
        .description = gKangaskhanPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_HORSEA] =
    {
    #if ENGLISH
        .categoryName = _("DRAGON"),
    #elif FRENCH
        .categoryName = _("DRAGON"),
    #elif ITALIAN
        .categoryName = _("DRAGO"),
    #endif
        .height = 4,
        .weight = 80,
        .description = gHorseaPokedexText,
        .pokemonScale = 399,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SEADRA] =
    {
    #if ENGLISH
        .categoryName = _("DRAGON"),
    #elif FRENCH
        .categoryName = _("DRAGON"),
    #elif ITALIAN
        .categoryName = _("DRAGO"),
    #endif
        .height = 12,
        .weight = 250,
        .description = gSeadraPokedexText,
        .pokemonScale = 299,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOLDEEN] =
    {
    #if ENGLISH
        .categoryName = _("GOLDFISH"),
    #elif FRENCH
        .categoryName = _("POISSON"),
    #elif ITALIAN
        .categoryName = _("PESCEROSSO"),
    #endif
        .height = 6,
        .weight = 150,
        .description = gGoldeenPokedexText,
        .pokemonScale = 379,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SEAKING] =
    {
    #if ENGLISH
        .categoryName = _("GOLDFISH"),
    #elif FRENCH
        .categoryName = _("POISSON"),
    #elif ITALIAN
        .categoryName = _("PESCEROSSO"),
    #endif
        .height = 13,
        .weight = 390,
        .description = gSeakingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_STARYU] =
    {
    #if ENGLISH
        .categoryName = _("STAR SHAPE"),
    #elif FRENCH
        .categoryName = _("ETOILE"),
    #elif ITALIAN
        .categoryName = _("STELLA"),
    #endif
        .height = 8,
        .weight = 345,
        .description = gStaryuPokedexText,
        .pokemonScale = 326,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_STARMIE] =
    {
    #if ENGLISH
        .categoryName = _("MYSTERIOUS"),
    #elif FRENCH
        .categoryName = _("MYSTERIEUX"),
    #elif ITALIAN
        .categoryName = _("MISTERIOSO"),
    #endif
        .height = 11,
        .weight = 800,
        .description = gStarmiePokedexText,
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MR_MIME] =
    {
    #if ENGLISH
        .categoryName = _("BARRIER"),
    #elif FRENCH
        .categoryName = _("BLOQUEUR"),
    #elif ITALIAN
        .categoryName = _("BARRIERA"),
    #endif
        .height = 13,
        .weight = 545,
        .description = gMrmimePokedexText,
        .pokemonScale = 258,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SCYTHER] =
    {
    #if ENGLISH
        .categoryName = _("MANTIS"),
    #elif FRENCH
        .categoryName = _("MANTE"),
    #elif ITALIAN
        .categoryName = _("MANTIDE"),
    #endif
        .height = 15,
        .weight = 560,
        .description = gScytherPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_JYNX] =
    {
    #if ENGLISH
        .categoryName = _("HUMAN SHAPE"),
    #elif FRENCH
        .categoryName = _("HUMANOIDE"),
    #elif ITALIAN
        .categoryName = _("UMANOIDE"),
    #endif
        .height = 14,
        .weight = 406,
        .description = gJynxPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 300,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ELECTABUZZ] =
    {
    #if ENGLISH
        .categoryName = _("ELECTRIC"),
    #elif FRENCH
        .categoryName = _("ELECTRIQUE"),
    #elif ITALIAN
        .categoryName = _("ELETTRICO"),
    #endif
        .height = 11,
        .weight = 300,
        .description = gElectabuzzPokedexText,
        .pokemonScale = 351,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGMAR] =
    {
    #if ENGLISH
        .categoryName = _("SPITFIRE"),
    #elif FRENCH
        .categoryName = _("CRACHE-FEU"),
    #elif ITALIAN
        .categoryName = _("SPUTAFUOCO"),
    #endif
        .height = 13,
        .weight = 445,
        .description = gMagmarPokedexText,
        .pokemonScale = 277,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PINSIR] =
    {
    #if ENGLISH
        .categoryName = _("STAG BEETLE"),
    #elif FRENCH
        .categoryName = _("SCARABEE"),
    #elif ITALIAN
        .categoryName = _("CERVOLANTE"),
    #endif
        .height = 15,
        .weight = 550,
        .description = gPinsirPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TAUROS] =
    {
    #if ENGLISH
        .categoryName = _("WILD BULL"),
    #elif FRENCH
        .categoryName = _("BUFFLE"),
    #elif ITALIAN
        .categoryName = _("TOROBRADO"),
    #endif
        .height = 14,
        .weight = 884,
        .description = gTaurosPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGIKARP] =
    {
    #if ENGLISH
        .categoryName = _("FISH"),
    #elif FRENCH
        .categoryName = _("POISSON"),
    #elif ITALIAN
        .categoryName = _("PESCE"),
    #endif
        .height = 9,
        .weight = 100,
        .description = gMagikarpPokedexText,
        .pokemonScale = 310,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GYARADOS] =
    {
    #if ENGLISH
        .categoryName = _("ATROCIOUS"),
    #elif FRENCH
        .categoryName = _("TERRIFIANT"),
    #elif ITALIAN
        .categoryName = _("ATROCE"),
    #endif
        .height = 65,
        .weight = 2350,
        .description = gGyaradosPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 481,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_LAPRAS] =
    {
    #if ENGLISH
        .categoryName = _("TRANSPORT"),
    #elif FRENCH
        .categoryName = _("TRANSPORT"),
    #elif ITALIAN
        .categoryName = _("TRASPORTO"),
    #endif
        .height = 25,
        .weight = 2200,
        .description = gLaprasPokedexText,
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_DITTO] =
    {
    #if ENGLISH
        .categoryName = _("TRANSFORM"),
    #elif FRENCH
        .categoryName = _("MORPHING"),
    #elif ITALIAN
        .categoryName = _("MUTANTE"),
    #endif
        .height = 3,
        .weight = 40,
        .description = gDittoPokedexText,
        .pokemonScale = 633,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_EEVEE] =
    {
    #if ENGLISH
        .categoryName = _("EVOLUTION"),
    #elif FRENCH
        .categoryName = _("EVOLUTIF"),
    #elif ITALIAN
        .categoryName = _("EVOLUZIONE"),
    #endif
        .height = 3,
        .weight = 65,
        .description = gEeveePokedexText,
        .pokemonScale = 476,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VAPOREON] =
    {
    #if ENGLISH
        .categoryName = _("BUBBLE JET"),
    #elif FRENCH
        .categoryName = _("BULLEUR"),
    #elif ITALIAN
        .categoryName = _("BOLLAJET"),
    #endif
        .height = 10,
        .weight = 290,
        .description = gVaporeonPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_JOLTEON] =
    {
    #if ENGLISH
        .categoryName = _("LIGHTNING"),
    #elif FRENCH
        .categoryName = _("ORAGE"),
    #elif ITALIAN
        .categoryName = _("LUMINOSO"),
    #endif
        .height = 8,
        .weight = 245,
        .description = gJolteonPokedexText,
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLAREON] =
    {
    #if ENGLISH
        .categoryName = _("FLAME"),
    #elif FRENCH
        .categoryName = _("FLAMME"),
    #elif ITALIAN
        .categoryName = _("FIAMMA"),
    #endif
        .height = 9,
        .weight = 250,
        .description = gFlareonPokedexText,
        .pokemonScale = 306,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PORYGON] =
    {
    #if ENGLISH
        .categoryName = _("VIRTUAL"),
    #elif FRENCH
        .categoryName = _("VIRTUEL"),
    #elif ITALIAN
        .categoryName = _("VIRTUALE"),
    #endif
        .height = 8,
        .weight = 365,
        .description = gPorygonPokedexText,
        .pokemonScale = 328,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_OMANYTE] =
    {
    #if ENGLISH
        .categoryName = _("SPIRAL"),
    #elif FRENCH
        .categoryName = _("SPIRALE"),
    #elif ITALIAN
        .categoryName = _("SPIRALE"),
    #endif
        .height = 4,
        .weight = 75,
        .description = gOmanytePokedexText,
        .pokemonScale = 521,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_OMASTAR] =
    {
    #if ENGLISH
        .categoryName = _("SPIRAL"),
    #elif FRENCH
        .categoryName = _("SPIRALE"),
    #elif ITALIAN
        .categoryName = _("SPIRALE"),
    #endif
        .height = 10,
        .weight = 350,
        .description = gOmastarPokedexText,
        .pokemonScale = 307,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KABUTO] =
    {
    #if ENGLISH
        .categoryName = _("SHELLFISH"),
    #elif FRENCH
        .categoryName = _("CARAPACE"),
    #elif ITALIAN
        .categoryName = _("CROSTACEO"),
    #endif
        .height = 5,
        .weight = 115,
        .description = gKabutoPokedexText,
        .pokemonScale = 454,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KABUTOPS] =
    {
    #if ENGLISH
        .categoryName = _("SHELLFISH"),
    #elif FRENCH
        .categoryName = _("CARAPACE"),
    #elif ITALIAN
        .categoryName = _("CROSTACEO"),
    #endif
        .height = 13,
        .weight = 405,
        .description = gKabutopsPokedexText,
        .pokemonScale = 271,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AERODACTYL] =
    {
    #if ENGLISH
        .categoryName = _("FOSSIL"),
    #elif FRENCH
        .categoryName = _("FOSSILE"),
    #elif ITALIAN
        .categoryName = _("FOSSILE"),
    #endif
        .height = 18,
        .weight = 590,
        .description = gAerodactylPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 302,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_SNORLAX] =
    {
    #if ENGLISH
        .categoryName = _("SLEEPING"),
    #elif FRENCH
        .categoryName = _("PIONCEUR"),
    #elif ITALIAN
        .categoryName = _("SONNO"),
    #endif
        .height = 21,
        .weight = 4600,
        .description = gSnorlaxPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 423,
        .trainerOffset = 11,
    },

    [NATIONAL_DEX_ARTICUNO] =
    {
    #if ENGLISH
        .categoryName = _("FREEZE"),
    #elif FRENCH
        .categoryName = _("GLACIAIRE"),
    #elif ITALIAN
        .categoryName = _("GELO"),
    #endif
        .height = 17,
        .weight = 554,
        .description = gArticunoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_ZAPDOS] =
    {
    #if ENGLISH
        .categoryName = _("ELECTRIC"),
    #elif FRENCH
        .categoryName = _("ELECTRIQUE"),
    #elif ITALIAN
        .categoryName = _("ELETTRICO"),
    #endif
        .height = 16,
        .weight = 526,
        .description = gZapdosPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 318,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_MOLTRES] =
    {
    #if ENGLISH
        .categoryName = _("FLAME"),
    #elif FRENCH
        .categoryName = _("FLAMME"),
    #elif ITALIAN
        .categoryName = _("FIAMMA"),
    #endif
        .height = 20,
        .weight = 600,
        .description = gMoltresPokedexText,
        .pokemonScale = 270,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_DRATINI] =
    {
    #if ENGLISH
        .categoryName = _("DRAGON"),
    #elif FRENCH
        .categoryName = _("DRAGON"),
    #elif ITALIAN
        .categoryName = _("DRAGO"),
    #endif
        .height = 18,
        .weight = 33,
        .description = gDratiniPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 8,
        .trainerScale = 386,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_DRAGONAIR] =
    {
    #if ENGLISH
        .categoryName = _("DRAGON"),
    #elif FRENCH
        .categoryName = _("DRAGON"),
    #elif ITALIAN
        .categoryName = _("DRAGO"),
    #endif
        .height = 40,
        .weight = 165,
        .description = gDragonairPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 411,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_DRAGONITE] =
    {
    #if ENGLISH
        .categoryName = _("DRAGON"),
    #elif FRENCH
        .categoryName = _("DRAGON"),
    #elif ITALIAN
        .categoryName = _("DRAGO"),
    #endif
        .height = 22,
        .weight = 2100,
        .description = gDragonitePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MEWTWO] =
    {
    #if ENGLISH
        .categoryName = _("GENETIC"),
    #elif FRENCH
        .categoryName = _("GENETIQUE"),
    #elif ITALIAN
        .categoryName = _("GENETICO"),
    #endif
        .height = 20,
        .weight = 1220,
        .description = gMewtwoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MEW] =
    {
    #if ENGLISH
        .categoryName = _("NEW SPECIES"),
    #elif FRENCH
        .categoryName = _("NOUVEAU"),
    #elif ITALIAN
        .categoryName = _("NOVASPECIE"),
    #endif
        .height = 4,
        .weight = 40,
        .description = gMewPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHIKORITA] =
    {
    #if ENGLISH
        .categoryName = _("LEAF"),
    #elif FRENCH
        .categoryName = _("FEUILLE"),
    #elif ITALIAN
        .categoryName = _("FOGLIA"),
    #endif
        .height = 9,
        .weight = 64,
        .description = gChikoritaPokedexText,
        .pokemonScale = 512,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BAYLEEF] =
    {
    #if ENGLISH
        .categoryName = _("LEAF"),
    #elif FRENCH
        .categoryName = _("FEUILLE"),
    #elif ITALIAN
        .categoryName = _("FOGLIA"),
    #endif
        .height = 12,
        .weight = 158,
        .description = gBayleefPokedexText,
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MEGANIUM] =
    {
    #if ENGLISH
        .categoryName = _("HERB"),
    #elif FRENCH
        .categoryName = _("HERBE"),
    #elif ITALIAN
        .categoryName = _("ERBE"),
    #endif
        .height = 18,
        .weight = 1005,
        .description = gMeganiumPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 277,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CYNDAQUIL] =
    {
    #if ENGLISH
        .categoryName = _("FIRE MOUSE"),
    #elif FRENCH
        .categoryName = _("SOURIS FEU"),
    #elif ITALIAN
        .categoryName = _("FUOCOTOPO"),
    #endif
        .height = 5,
        .weight = 79,
        .description = gCyndaquilPokedexText,
        .pokemonScale = 539,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_QUILAVA] =
    {
    #if ENGLISH
        .categoryName = _("VOLCANO"),
    #elif FRENCH
        .categoryName = _("VOLCAN"),
    #elif ITALIAN
        .categoryName = _("VULCANO"),
    #endif
        .height = 9,
        .weight = 190,
        .description = gQuilavaPokedexText,
        .pokemonScale = 329,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TYPHLOSION] =
    {
    #if ENGLISH
        .categoryName = _("VOLCANO"),
    #elif FRENCH
        .categoryName = _("VOLCAN"),
    #elif ITALIAN
        .categoryName = _("VULCANO"),
    #endif
        .height = 17,
        .weight = 795,
        .description = gTyphlosionPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_TOTODILE] =
    {
    #if ENGLISH
        .categoryName = _("BIG JAW"),
    #elif FRENCH
        .categoryName = _("MACHOIRE"),
    #elif ITALIAN
        .categoryName = _("MASCELLONE"),
    #endif
        .height = 6,
        .weight = 95,
        .description = gTotodilePokedexText,
        .pokemonScale = 487,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CROCONAW] =
    {
    #if ENGLISH
        .categoryName = _("BIG JAW"),
    #elif FRENCH
        .categoryName = _("MACHOIRE"),
    #elif ITALIAN
        .categoryName = _("MASCELLONE"),
    #endif
        .height = 11,
        .weight = 250,
        .description = gCroconawPokedexText,
        .pokemonScale = 378,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FERALIGATR] =
    {
    #if ENGLISH
        .categoryName = _("BIG JAW"),
    #elif FRENCH
        .categoryName = _("MACHOIRE"),
    #elif ITALIAN
        .categoryName = _("MASCELLONE"),
    #endif
        .height = 23,
        .weight = 888,
        .description = gFeraligatrPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_SENTRET] =
    {
    #if ENGLISH
        .categoryName = _("SCOUT"),
    #elif FRENCH
        .categoryName = _("ESPION"),
    #elif ITALIAN
        .categoryName = _("ESPLORANTE"),
    #endif
        .height = 8,
        .weight = 60,
        .description = gSentretPokedexText,
        .pokemonScale = 439,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FURRET] =
    {
    #if ENGLISH
        .categoryName = _("LONG BODY"),
    #elif FRENCH
        .categoryName = _("ALLONGE"),
    #elif ITALIAN
        .categoryName = _("LUNGOCORPO"),
    #endif
        .height = 18,
        .weight = 325,
        .description = gFurretPokedexText,
        .pokemonScale = 346,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HOOTHOOT] =
    {
    #if ENGLISH
        .categoryName = _("OWL"),
    #elif FRENCH
        .categoryName = _("HIBOU"),
    #elif ITALIAN
        .categoryName = _("GUFO"),
    #endif
        .height = 7,
        .weight = 212,
        .description = gHoothootPokedexText,
        .pokemonScale = 380,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NOCTOWL] =
    {
    #if ENGLISH
        .categoryName = _("OWL"),
    #elif FRENCH
        .categoryName = _("HIBOU"),
    #elif ITALIAN
        .categoryName = _("GUFO"),
    #endif
        .height = 16,
        .weight = 408,
        .description = gNoctowlPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LEDYBA] =
    {
    #if ENGLISH
        .categoryName = _("FIVE STAR"),
    #elif FRENCH
        .categoryName = _("5 ETOILES"),
    #elif ITALIAN
        .categoryName = _("PENTASTRA"),
    #endif
        .height = 10,
        .weight = 108,
        .description = gLedybaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LEDIAN] =
    {
    #if ENGLISH
        .categoryName = _("FIVE STAR"),
    #elif FRENCH
        .categoryName = _("5 ETOILES"),
    #elif ITALIAN
        .categoryName = _("PENTASTRA"),
    #endif
        .height = 14,
        .weight = 356,
        .description = gLedianPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPINARAK] =
    {
    #if ENGLISH
        .categoryName = _("STRING SPIT"),
    #elif FRENCH
        .categoryName = _("CRACHE FIL"),
    #elif ITALIAN
        .categoryName = _("TELA"),
    #endif
        .height = 5,
        .weight = 85,
        .description = gSpinarakPokedexText,
        .pokemonScale = 414,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARIADOS] =
    {
    #if ENGLISH
        .categoryName = _("LONG LEG"),
    #elif FRENCH
        .categoryName = _("LONG-PATTE"),
    #elif ITALIAN
        .categoryName = _("LUNGAZAMPA"),
    #endif
        .height = 11,
        .weight = 335,
        .description = gAriadosPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CROBAT] =
    {
    #if ENGLISH
        .categoryName = _("BAT"),
    #elif FRENCH
        .categoryName = _("CHOVSOURIS"),
    #elif ITALIAN
        .categoryName = _("PIPISTREL."),
    #endif
        .height = 18,
        .weight = 750,
        .description = gCrobatPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 281,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CHINCHOU] =
    {
    #if ENGLISH
        .categoryName = _("ANGLER"),
    #elif FRENCH
        .categoryName = _("POISSON"),
    #elif ITALIAN
        .categoryName = _("PESCATORE"),
    #endif
        .height = 5,
        .weight = 120,
        .description = gChinchouPokedexText,
        .pokemonScale = 424,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LANTURN] =
    {
    #if ENGLISH
        .categoryName = _("LIGHT"),
    #elif FRENCH
        .categoryName = _("LUMIERE"),
    #elif ITALIAN
        .categoryName = _("LUCE"),
    #endif
        .height = 12,
        .weight = 225,
        .description = gLanturnPokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PICHU] =
    {
    #if ENGLISH
        .categoryName = _("TINY MOUSE"),
    #elif FRENCH
        .categoryName = _("MINISOURIS"),
    #elif ITALIAN
        .categoryName = _("TOPINO"),
    #endif
        .height = 3,
        .weight = 20,
        .description = gPichuPokedexText,
        .pokemonScale = 508,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLEFFA] =
    {
    #if ENGLISH
        .categoryName = _("STAR SHAPE"),
    #elif FRENCH
        .categoryName = _("ETOILE"),
    #elif ITALIAN
        .categoryName = _("STELLA"),
    #endif
        .height = 3,
        .weight = 30,
        .description = gCleffaPokedexText,
        .pokemonScale = 462,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_IGGLYBUFF] =
    {
    #if ENGLISH
        .categoryName = _("BALLOON"),
    #elif FRENCH
        .categoryName = _("BOUBOULE"),
    #elif ITALIAN
        .categoryName = _("PALLONE"),
    #endif
        .height = 3,
        .weight = 10,
        .description = gIgglybuffPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TOGEPI] =
    {
    #if ENGLISH
        .categoryName = _("SPIKE BALL"),
    #elif FRENCH
        .categoryName = _("BALLE PIC"),
    #elif ITALIAN
        .categoryName = _("PALLAPUNTE"),
    #endif
        .height = 3,
        .weight = 15,
        .description = gTogepiPokedexText,
        .pokemonScale = 507,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TOGETIC] =
    {
    #if ENGLISH
        .categoryName = _("HAPPINESS"),
    #elif FRENCH
        .categoryName = _("BONHEUR"),
    #elif ITALIAN
        .categoryName = _("FELICITÀ"),
    #endif
        .height = 6,
        .weight = 32,
        .description = gTogeticPokedexText,
        .pokemonScale = 424,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NATU] =
    {
    #if ENGLISH
        .categoryName = _("TINY BIRD"),
    #elif FRENCH
        .categoryName = _("MINOISEAU"),
    #elif ITALIAN
        .categoryName = _("UCCELLINO"),
    #endif
        .height = 2,
        .weight = 20,
        .description = gNatuPokedexText,
        .pokemonScale = 610,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_XATU] =
    {
    #if ENGLISH
        .categoryName = _("MYSTIC"),
    #elif FRENCH
        .categoryName = _("MYSTIQUE"),
    #elif ITALIAN
        .categoryName = _("MAGICO"),
    #endif
        .height = 15,
        .weight = 150,
        .description = gXatuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 318,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MAREEP] =
    {
    #if ENGLISH
        .categoryName = _("WOOL"),
    #elif FRENCH
        .categoryName = _("LAINE"),
    #elif ITALIAN
        .categoryName = _("LANA"),
    #endif
        .height = 6,
        .weight = 78,
        .description = gMareepPokedexText,
        .pokemonScale = 379,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLAAFFY] =
    {
    #if ENGLISH
        .categoryName = _("WOOL"),
    #elif FRENCH
        .categoryName = _("LAINE"),
    #elif ITALIAN
        .categoryName = _("LANA"),
    #endif
        .height = 8,
        .weight = 133,
        .description = gFlaaffyPokedexText,
        .pokemonScale = 372,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AMPHAROS] =
    {
    #if ENGLISH
        .categoryName = _("LIGHT"),
    #elif FRENCH
        .categoryName = _("LUMIERE"),
    #elif ITALIAN
        .categoryName = _("LUCE"),
    #endif
        .height = 14,
        .weight = 615,
        .description = gAmpharosPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BELLOSSOM] =
    {
    #if ENGLISH
        .categoryName = _("FLOWER"),
    #elif FRENCH
        .categoryName = _("FLEUR"),
    #elif ITALIAN
        .categoryName = _("FIORE"),
    #endif
        .height = 4,
        .weight = 58,
        .description = gBellossomPokedexText,
        .pokemonScale = 472,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MARILL] =
    {
    #if ENGLISH
        .categoryName = _("AQUA MOUSE"),
    #elif FRENCH
        .categoryName = _("AQUASOURIS"),
    #elif ITALIAN
        .categoryName = _("ACQUATOPO"),
    #endif
        .height = 4,
        .weight = 85,
        .description = gMarillPokedexText,
        .pokemonScale = 476,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AZUMARILL] =
    {
    #if ENGLISH
        .categoryName = _("AQUA RABBIT"),
    #elif FRENCH
        .categoryName = _("AQUALAPIN"),
    #elif ITALIAN
        .categoryName = _("ACQUNIGLIO"),
    #endif
        .height = 8,
        .weight = 285,
        .description = gAzumarillPokedexText,
        .pokemonScale = 448,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SUDOWOODO] =
    {
    #if ENGLISH
        .categoryName = _("IMITATION"),
    #elif FRENCH
        .categoryName = _("IMITATION"),
    #elif ITALIAN
        .categoryName = _("IMITAZIONE"),
    #endif
        .height = 12,
        .weight = 380,
        .description = gSudowoodoPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_POLITOED] =
    {
    #if ENGLISH
        .categoryName = _("FROG"),
    #elif FRENCH
        .categoryName = _("GRENOUILLE"),
    #elif ITALIAN
        .categoryName = _("RANA"),
    #endif
        .height = 11,
        .weight = 339,
        .description = gPolitoedPokedexText,
        .pokemonScale = 289,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HOPPIP] =
    {
    #if ENGLISH
        .categoryName = _("COTTONWEED"),
    #elif FRENCH
        .categoryName = _("PISSENLIT"),
    #elif ITALIAN
        .categoryName = _("GRAMIGNA"),
    #endif
        .height = 4,
        .weight = 5,
        .description = gHoppipPokedexText,
        .pokemonScale = 562,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SKIPLOOM] =
    {
    #if ENGLISH
        .categoryName = _("COTTONWEED"),
    #elif FRENCH
        .categoryName = _("PISSENLIT"),
    #elif ITALIAN
        .categoryName = _("GRAMIGNA"),
    #endif
        .height = 6,
        .weight = 10,
        .description = gSkiploomPokedexText,
        .pokemonScale = 387,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_JUMPLUFF] =
    {
    #if ENGLISH
        .categoryName = _("COTTONWEED"),
    #elif FRENCH
        .categoryName = _("PISSENLIT"),
    #elif ITALIAN
        .categoryName = _("GRAMIGNA"),
    #endif
        .height = 8,
        .weight = 30,
        .description = gJumpluffPokedexText,
        .pokemonScale = 418,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AIPOM] =
    {
    #if ENGLISH
        .categoryName = _("LONG TAIL"),
    #elif FRENCH
        .categoryName = _("LONGQUEUE"),
    #elif ITALIAN
        .categoryName = _("LUNGACODA"),
    #endif
        .height = 8,
        .weight = 115,
        .description = gAipomPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SUNKERN] =
    {
    #if ENGLISH
        .categoryName = _("SEED"),
    #elif FRENCH
        .categoryName = _("GRAINE"),
    #elif ITALIAN
        .categoryName = _("SEME"),
    #endif
        .height = 3,
        .weight = 18,
        .description = gSunkernPokedexText,
        .pokemonScale = 541,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SUNFLORA] =
    {
    #if ENGLISH
        .categoryName = _("SUN"),
    #elif FRENCH
        .categoryName = _("SOLEIL"),
    #elif ITALIAN
        .categoryName = _("SOLE"),
    #endif
        .height = 8,
        .weight = 85,
        .description = gSunfloraPokedexText,
        .pokemonScale = 444,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YANMA] =
    {
    #if ENGLISH
        .categoryName = _("CLEAR WING"),
    #elif FRENCH
        .categoryName = _("TRANSLAILE"),
    #elif ITALIAN
        .categoryName = _("ALACHIARA"),
    #endif
        .height = 12,
        .weight = 380,
        .description = gYanmaPokedexText,
        .pokemonScale = 274,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WOOPER] =
    {
    #if ENGLISH
        .categoryName = _("WATER FISH"),
    #elif FRENCH
        .categoryName = _("POISSON"),
    #elif ITALIAN
        .categoryName = _("ACQUAPESCE"),
    #endif
        .height = 4,
        .weight = 85,
        .description = gWooperPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_QUAGSIRE] =
    {
    #if ENGLISH
        .categoryName = _("WATER FISH"),
    #elif FRENCH
        .categoryName = _("POISSON"),
    #elif ITALIAN
        .categoryName = _("ACQUAPESCE"),
    #endif
        .height = 14,
        .weight = 750,
        .description = gQuagsirePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ESPEON] =
    {
    #if ENGLISH
        .categoryName = _("SUN"),
    #elif FRENCH
        .categoryName = _("SOLEIL"),
    #elif ITALIAN
        .categoryName = _("SOLE"),
    #endif
        .height = 9,
        .weight = 265,
        .description = gEspeonPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_UMBREON] =
    {
    #if ENGLISH
        .categoryName = _("MOONLIGHT"),
    #elif FRENCH
        .categoryName = _("LUNE"),
    #elif ITALIAN
        .categoryName = _("LUCELUNARE"),
    #endif
        .height = 10,
        .weight = 270,
        .description = gUmbreonPokedexText,
        .pokemonScale = 317,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MURKROW] =
    {
    #if ENGLISH
        .categoryName = _("DARKNESS"),
    #elif FRENCH
        .categoryName = _("OBSCURITE"),
    #elif ITALIAN
        .categoryName = _("OSCURITÀ"),
    #endif
        .height = 5,
        .weight = 21,
        .description = gMurkrowPokedexText,
        .pokemonScale = 401,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SLOWKING] =
    {
    #if ENGLISH
        .categoryName = _("ROYAL"),
    #elif FRENCH
        .categoryName = _("ROYAL"),
    #elif ITALIAN
        .categoryName = _("REALE"),
    #endif
        .height = 20,
        .weight = 795,
        .description = gSlowkingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_MISDREAVUS] =
    {
    #if ENGLISH
        .categoryName = _("SCREECH"),
    #elif FRENCH
        .categoryName = _("STRIDENT"),
    #elif ITALIAN
        .categoryName = _("STRIDO"),
    #endif
        .height = 7,
        .weight = 10,
        .description = gMisdreavusPokedexText,
        .pokemonScale = 407,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_UNOWN] =
    {
    #if ENGLISH
        .categoryName = _("SYMBOL"),
    #elif FRENCH
        .categoryName = _("SYMBOLIQUE"),
    #elif ITALIAN
        .categoryName = _("SIMBOLO"),
    #endif
        .height = 5,
        .weight = 50,
        .description = gUnownPokedexText,
        .pokemonScale = 411,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WOBBUFFET] =
    {
    #if ENGLISH
        .categoryName = _("PATIENT"),
    #elif FRENCH
        .categoryName = _("PATIENT"),
    #elif ITALIAN
        .categoryName = _("PAZIENZA"),
    #endif
        .height = 13,
        .weight = 285,
        .description = gWobbuffetPokedexText,
        .pokemonScale = 274,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GIRAFARIG] =
    {
    #if ENGLISH
        .categoryName = _("LONG NECK"),
    #elif FRENCH
        .categoryName = _("LONG-COU"),
    #elif ITALIAN
        .categoryName = _("LUNGOCOLLO"),
    #endif
        .height = 15,
        .weight = 415,
        .description = gGirafarigPokedexText,
        .pokemonScale = 281,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PINECO] =
    {
    #if ENGLISH
        .categoryName = _("BAGWORM"),
    #elif FRENCH
        .categoryName = _("VER CACHE"),
    #elif ITALIAN
        .categoryName = _("LARVA"),
    #endif
        .height = 6,
        .weight = 72,
        .description = gPinecoPokedexText,
        .pokemonScale = 445,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FORRETRESS] =
    {
    #if ENGLISH
        .categoryName = _("BAGWORM"),
    #elif FRENCH
        .categoryName = _("VER CACHE"),
    #elif ITALIAN
        .categoryName = _("LARVA"),
    #endif
        .height = 12,
        .weight = 1258,
        .description = gForretressPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DUNSPARCE] =
    {
    #if ENGLISH
        .categoryName = _("LAND SNAKE"),
    #elif FRENCH
        .categoryName = _("SERPENT"),
    #elif ITALIAN
        .categoryName = _("TERRASERPE"),
    #endif
        .height = 15,
        .weight = 140,
        .description = gDunsparcePokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GLIGAR] =
    {
    #if ENGLISH
        .categoryName = _("FLYSCORPION"),
    #elif FRENCH
        .categoryName = _("SCORPIVOL"),
    #elif ITALIAN
        .categoryName = _("ALISCORPIO"),
    #endif
        .height = 11,
        .weight = 648,
        .description = gGligarPokedexText,
        .pokemonScale = 350,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_STEELIX] =
    {
    #if ENGLISH
        .categoryName = _("IRON SNAKE"),
    #elif FRENCH
        .categoryName = _("SERPENFER"),
    #elif ITALIAN
        .categoryName = _("FERROSERPE"),
    #endif
        .height = 92,
        .weight = 4000,
        .description = gSteelixPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 516,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_SNUBBULL] =
    {
    #if ENGLISH
        .categoryName = _("FAIRY"),
    #elif FRENCH
        .categoryName = _("FEE"),
    #elif ITALIAN
        .categoryName = _("FATA"),
    #endif
        .height = 6,
        .weight = 78,
        .description = gSnubbullPokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GRANBULL] =
    {
    #if ENGLISH
        .categoryName = _("FAIRY"),
    #elif FRENCH
        .categoryName = _("FEE"),
    #elif ITALIAN
        .categoryName = _("FATA"),
    #endif
        .height = 14,
        .weight = 487,
        .description = gGranbullPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_QWILFISH] =
    {
    #if ENGLISH
        .categoryName = _("BALLOON"),
    #elif FRENCH
        .categoryName = _("BOUBOULE"),
    #elif ITALIAN
        .categoryName = _("PALLONE"),
    #endif
        .height = 5,
        .weight = 39,
        .description = gQwilfishPokedexText,
        .pokemonScale = 430,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SCIZOR] =
    {
    #if ENGLISH
        .categoryName = _("PINCER"),
    #elif FRENCH
        .categoryName = _("PINCE"),
    #elif ITALIAN
        .categoryName = _("CHELA"),
    #endif
        .height = 18,
        .weight = 1180,
        .description = gScizorPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHUCKLE] =
    {
    #if ENGLISH
        .categoryName = _("MOLD"),
    #elif FRENCH
        .categoryName = _("POURRI"),
    #elif ITALIAN
        .categoryName = _("MUFFA"),
    #endif
        .height = 6,
        .weight = 205,
        .description = gShucklePokedexText,
        .pokemonScale = 485,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HERACROSS] =
    {
    #if ENGLISH
        .categoryName = _("SINGLE HORN"),
    #elif FRENCH
        .categoryName = _("UNICORNE"),
    #elif ITALIAN
        .categoryName = _("MONOCORNO"),
    #endif
        .height = 15,
        .weight = 540,
        .description = gHeracrossPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SNEASEL] =
    {
    #if ENGLISH
        .categoryName = _("SHARP CLAW"),
    #elif FRENCH
        .categoryName = _("GRIFACEREE"),
    #elif ITALIAN
        .categoryName = _("LAMARTIGLI"),
    #endif
        .height = 9,
        .weight = 280,
        .description = gSneaselPokedexText,
        .pokemonScale = 413,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TEDDIURSA] =
    {
    #if ENGLISH
        .categoryName = _("LITTLE BEAR"),
    #elif FRENCH
        .categoryName = _("MINI OURS"),
    #elif ITALIAN
        .categoryName = _("ORSETTO"),
    #endif
        .height = 6,
        .weight = 88,
        .description = gTeddiursaPokedexText,
        .pokemonScale = 455,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_URSARING] =
    {
    #if ENGLISH
        .categoryName = _("HIBERNATOR"),
    #elif FRENCH
        .categoryName = _("HIBERNANT"),
    #elif ITALIAN
        .categoryName = _("LETARGO"),
    #endif
        .height = 18,
        .weight = 1258,
        .description = gUrsaringPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLUGMA] =
    {
    #if ENGLISH
        .categoryName = _("LAVA"),
    #elif FRENCH
        .categoryName = _("LAVE"),
    #elif ITALIAN
        .categoryName = _("LAVA"),
    #endif
        .height = 7,
        .weight = 350,
        .description = gSlugmaPokedexText,
        .pokemonScale = 329,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGCARGO] =
    {
    #if ENGLISH
        .categoryName = _("LAVA"),
    #elif FRENCH
        .categoryName = _("LAVE"),
    #elif ITALIAN
        .categoryName = _("LAVA"),
    #endif
        .height = 8,
        .weight = 550,
        .description = gMagcargoPokedexText,
        .pokemonScale = 332,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SWINUB] =
    {
    #if ENGLISH
        .categoryName = _("PIG"),
    #elif FRENCH
        .categoryName = _("COCHON"),
    #elif ITALIAN
        .categoryName = _("MAIALE"),
    #endif
        .height = 4,
        .weight = 65,
        .description = gSwinubPokedexText,
        .pokemonScale = 324,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PILOSWINE] =
    {
    #if ENGLISH
        .categoryName = _("SWINE"),
    #elif FRENCH
        .categoryName = _("PORC"),
    #elif ITALIAN
        .categoryName = _("SUINO"),
    #endif
        .height = 11,
        .weight = 558,
        .description = gPiloswinePokedexText,
        .pokemonScale = 306,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CORSOLA] =
    {
    #if ENGLISH
        .categoryName = _("CORAL"),
    #elif FRENCH
        .categoryName = _("CORAIL"),
    #elif ITALIAN
        .categoryName = _("CORALLO"),
    #endif
        .height = 6,
        .weight = 50,
        .description = gCorsolaPokedexText,
        .pokemonScale = 410,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_REMORAID] =
    {
    #if ENGLISH
        .categoryName = _("JET"),
    #elif FRENCH
        .categoryName = _("JET"),
    #elif ITALIAN
        .categoryName = _("JET"),
    #endif
        .height = 6,
        .weight = 120,
        .description = gRemoraidPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_OCTILLERY] =
    {
    #if ENGLISH
        .categoryName = _("JET"),
    #elif FRENCH
        .categoryName = _("JET"),
    #elif ITALIAN
        .categoryName = _("JET"),
    #endif
        .height = 9,
        .weight = 285,
        .description = gOctilleryPokedexText,
        .pokemonScale = 296,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DELIBIRD] =
    {
    #if ENGLISH
        .categoryName = _("DELIVERY"),
    #elif FRENCH
        .categoryName = _("LIVRAISON"),
    #elif ITALIAN
        .categoryName = _("CONSEGNA"),
    #endif
        .height = 9,
        .weight = 160,
        .description = gDelibirdPokedexText,
        .pokemonScale = 293,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MANTINE] =
    {
    #if ENGLISH
        .categoryName = _("KITE"),
    #elif FRENCH
        .categoryName = _("CERVOLANT"),
    #elif ITALIAN
        .categoryName = _("AQUILONE"),
    #endif
        .height = 21,
        .weight = 2200,
        .description = gMantinePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_SKARMORY] =
    {
    #if ENGLISH
        .categoryName = _("ARMOR BIRD"),
    #elif FRENCH
        .categoryName = _("ARMOISEAU"),
    #elif ITALIAN
        .categoryName = _("ARMUCCELLO"),
    #endif
        .height = 17,
        .weight = 505,
        .description = gSkarmoryPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 271,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_HOUNDOUR] =
    {
    #if ENGLISH
        .categoryName = _("DARK"),
    #elif FRENCH
        .categoryName = _("SOMBRE"),
    #elif ITALIAN
        .categoryName = _("BUIO"),
    #endif
        .height = 6,
        .weight = 108,
        .description = gHoundourPokedexText,
        .pokemonScale = 393,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HOUNDOOM] =
    {
    #if ENGLISH
        .categoryName = _("DARK"),
    #elif FRENCH
        .categoryName = _("SOMBRE"),
    #elif ITALIAN
        .categoryName = _("BUIO"),
    #endif
        .height = 14,
        .weight = 350,
        .description = gHoundoomPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KINGDRA] =
    {
    #if ENGLISH
        .categoryName = _("DRAGON"),
    #elif FRENCH
        .categoryName = _("DRAGON"),
    #elif ITALIAN
        .categoryName = _("DRAGO"),
    #endif
        .height = 18,
        .weight = 1520,
        .description = gKingdraPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 287,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PHANPY] =
    {
    #if ENGLISH
        .categoryName = _("LONG NOSE"),
    #elif FRENCH
        .categoryName = _("LONG-NEZ"),
    #elif ITALIAN
        .categoryName = _("NASONE"),
    #endif
        .height = 5,
        .weight = 335,
        .description = gPhanpyPokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DONPHAN] =
    {
    #if ENGLISH
        .categoryName = _("ARMOR"),
    #elif FRENCH
        .categoryName = _("ARMURE"),
    #elif ITALIAN
        .categoryName = _("ARMATURA"),
    #endif
        .height = 11,
        .weight = 1200,
        .description = gDonphanPokedexText,
        .pokemonScale = 313,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PORYGON2] =
    {
    #if ENGLISH
        .categoryName = _("VIRTUAL"),
    #elif FRENCH
        .categoryName = _("VIRTUEL"),
    #elif ITALIAN
        .categoryName = _("VIRTUALE"),
    #endif
        .height = 6,
        .weight = 325,
        .description = gPorygon2PokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_STANTLER] =
    {
    #if ENGLISH
        .categoryName = _("BIG HORN"),
    #elif FRENCH
        .categoryName = _("MAXI CORNE"),
    #elif ITALIAN
        .categoryName = _("GRANCORNO"),
    #endif
        .height = 14,
        .weight = 712,
        .description = gStantlerPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SMEARGLE] =
    {
    #if ENGLISH
        .categoryName = _("PAINTER"),
    #elif FRENCH
        .categoryName = _("PEINTRE"),
    #elif ITALIAN
        .categoryName = _("PITTORE"),
    #endif
        .height = 12,
        .weight = 580,
        .description = gSmearglePokedexText,
        .pokemonScale = 287,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TYROGUE] =
    {
    #if ENGLISH
        .categoryName = _("SCUFFLE"),
    #elif FRENCH
        .categoryName = _("BAGARREUR"),
    #elif ITALIAN
        .categoryName = _("BARUFFA"),
    #endif
        .height = 7,
        .weight = 210,
        .description = gTyroguePokedexText,
        .pokemonScale = 292,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HITMONTOP] =
    {
    #if ENGLISH
        .categoryName = _("HANDSTAND"),
    #elif FRENCH
        .categoryName = _("POIRIER"),
    #elif ITALIAN
        .categoryName = _("VERTICALE"),
    #endif
        .height = 14,
        .weight = 480,
        .description = gHitmontopPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SMOOCHUM] =
    {
    #if ENGLISH
        .categoryName = _("KISS"),
    #elif FRENCH
        .categoryName = _("BISOU"),
    #elif ITALIAN
        .categoryName = _("BACIO"),
    #endif
        .height = 4,
        .weight = 60,
        .description = gSmoochumPokedexText,
        .pokemonScale = 440,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ELEKID] =
    {
    #if ENGLISH
        .categoryName = _("ELECTRIC"),
    #elif FRENCH
        .categoryName = _("ELECTRIQUE"),
    #elif ITALIAN
        .categoryName = _("ELETTRICO"),
    #endif
        .height = 6,
        .weight = 235,
        .description = gElekidPokedexText,
        .pokemonScale = 363,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGBY] =
    {
    #if ENGLISH
        .categoryName = _("LIVE COAL"),
    #elif FRENCH
        .categoryName = _("CHARBON"),
    #elif ITALIAN
        .categoryName = _("CARBONVIVO"),
    #endif
        .height = 7,
        .weight = 214,
        .description = gMagbyPokedexText,
        .pokemonScale = 284,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MILTANK] =
    {
    #if ENGLISH
        .categoryName = _("MILK COW"),
    #elif FRENCH
        .categoryName = _("VACHALAIT"),
    #elif ITALIAN
        .categoryName = _("BOVINO"),
    #endif
        .height = 12,
        .weight = 755,
        .description = gMiltankPokedexText,
        .pokemonScale = 280,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BLISSEY] =
    {
    #if ENGLISH
        .categoryName = _("HAPPINESS"),
    #elif FRENCH
        .categoryName = _("BONHEUR"),
    #elif ITALIAN
        .categoryName = _("FELICITÀ"),
    #endif
        .height = 15,
        .weight = 468,
        .description = gBlisseyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 310,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_RAIKOU] =
    {
    #if ENGLISH
        .categoryName = _("THUNDER"),
    #elif FRENCH
        .categoryName = _("FOUDRE"),
    #elif ITALIAN
        .categoryName = _("TUONO"),
    #endif
        .height = 19,
        .weight = 1780,
        .description = gRaikouPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_ENTEI] =
    {
    #if ENGLISH
        .categoryName = _("VOLCANO"),
    #elif FRENCH
        .categoryName = _("VOLCAN"),
    #elif ITALIAN
        .categoryName = _("VULCANO"),
    #endif
        .height = 21,
        .weight = 1980,
        .description = gEnteiPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_SUICUNE] =
    {
    #if ENGLISH
        .categoryName = _("AURORA"),
    #elif FRENCH
        .categoryName = _("AURORE"),
    #elif ITALIAN
        .categoryName = _("AURORA"),
    #endif
        .height = 20,
        .weight = 1870,
        .description = gSuicunePokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_LARVITAR] =
    {
    #if ENGLISH
        .categoryName = _("ROCK SKIN"),
    #elif FRENCH
        .categoryName = _("PEAUPIERRE"),
    #elif ITALIAN
        .categoryName = _("PELDISASSO"),
    #endif
        .height = 6,
        .weight = 720,
        .description = gLarvitarPokedexText,
        .pokemonScale = 472,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PUPITAR] =
    {
    #if ENGLISH
        .categoryName = _("HARD SHELL"),
    #elif FRENCH
        .categoryName = _("CARAPADURE"),
    #elif ITALIAN
        .categoryName = _("GUSCIODURO"),
    #endif
        .height = 12,
        .weight = 1520,
        .description = gPupitarPokedexText,
        .pokemonScale = 292,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TYRANITAR] =
    {
    #if ENGLISH
        .categoryName = _("ARMOR"),
    #elif FRENCH
        .categoryName = _("ARMURE"),
    #elif ITALIAN
        .categoryName = _("ARMATURA"),
    #endif
        .height = 20,
        .weight = 2020,
        .description = gTyranitarPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_LUGIA] =
    {
    #if ENGLISH
        .categoryName = _("DIVING"),
    #elif FRENCH
        .categoryName = _("PLONGEON"),
    #elif ITALIAN
        .categoryName = _("IMMERSIONE"),
    #endif
        .height = 52,
        .weight = 2160,
        .description = gLugiaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
    },

    [NATIONAL_DEX_HO_OH] =
    {
    #if ENGLISH
        .categoryName = _("RAINBOW"),
    #elif FRENCH
        .categoryName = _("ARCENCIEL"),
    #elif ITALIAN
        .categoryName = _("ARCOBALENO"),
    #endif
        .height = 38,
        .weight = 1990,
        .description = gHoOhPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
    },

    [NATIONAL_DEX_CELEBI] =
    {
    #if ENGLISH
        .categoryName = _("TIME TRAVEL"),
    #elif FRENCH
        .categoryName = _("TEMPOREL"),
    #elif ITALIAN
        .categoryName = _("TEMPOVIA"),
    #endif
        .height = 6,
        .weight = 50,
        .description = gCelebiPokedexText,
        .pokemonScale = 393,
        .pokemonOffset = -10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TREECKO] =
    {
    #if ENGLISH
        .categoryName = _("WOOD GECKO"),
    #elif FRENCH
        .categoryName = _("BOIS GECKO"),
    #elif ITALIAN
        .categoryName = _("LEGNOGECO"),
    #endif
        .height = 5,
        .weight = 50,
        .description = gTreeckoPokedexText,
        .pokemonScale = 541,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GROVYLE] =
    {
    #if ENGLISH
        .categoryName = _("WOOD GECKO"),
    #elif FRENCH
        .categoryName = _("BOIS GECKO"),
    #elif ITALIAN
        .categoryName = _("LEGNOGECO"),
    #endif
        .height = 9,
        .weight = 216,
        .description = gGrovylePokedexText,
        .pokemonScale = 360,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SCEPTILE] =
    {
    #if ENGLISH
        .categoryName = _("FOREST"),
    #elif FRENCH
        .categoryName = _("FORET"),
    #elif ITALIAN
        .categoryName = _("FORESTA"),
    #endif
        .height = 17,
        .weight = 522,
        .description = gSceptilePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 275,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_TORCHIC] =
    {
    #if ENGLISH
        .categoryName = _("CHICK"),
    #elif FRENCH
        .categoryName = _("POUSSIN"),
    #elif ITALIAN
        .categoryName = _("PULCINO"),
    #endif
        .height = 4,
        .weight = 25,
        .description = gTorchicPokedexText,
        .pokemonScale = 566,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_COMBUSKEN] =
    {
    #if ENGLISH
        .categoryName = _("YOUNG FOWL"),
    #elif FRENCH
        .categoryName = _("POULET"),
    #elif ITALIAN
        .categoryName = _("RAMPOLLO"),
    #endif
        .height = 9,
        .weight = 195,
        .description = gCombuskenPokedexText,
        .pokemonScale = 343,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BLAZIKEN] =
    {
    #if ENGLISH
        .categoryName = _("BLAZE"),
    #elif FRENCH
        .categoryName = _("ARDENT"),
    #elif ITALIAN
        .categoryName = _("VAMPE"),
    #endif
        .height = 19,
        .weight = 520,
        .description = gBlazikenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MUDKIP] =
    {
    #if ENGLISH
        .categoryName = _("MUD FISH"),
    #elif FRENCH
        .categoryName = _("POISSONBOUE"),
    #elif ITALIAN
        .categoryName = _("FANGO PESCE"),
    #endif
        .height = 4,
        .weight = 76,
        .description = gMudkipPokedexText,
        .pokemonScale = 535,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MARSHTOMP] =
    {
    #if ENGLISH
        .categoryName = _("MUD FISH"),
    #elif FRENCH
        .categoryName = _("POISSONBOUE"),
    #elif ITALIAN
        .categoryName = _("FANGO PESCE"),
    #endif
        .height = 7,
        .weight = 280,
        .description = gMarshtompPokedexText,
        .pokemonScale = 340,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SWAMPERT] =
    {
    #if ENGLISH
        .categoryName = _("MUD FISH"),
    #elif FRENCH
        .categoryName = _("POISSONBOUE"),
    #elif ITALIAN
        .categoryName = _("FANGO PESCE"),
    #endif
        .height = 15,
        .weight = 819,
        .description = gSwampertPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_POOCHYENA] =
    {
    #if ENGLISH
        .categoryName = _("BITE"),
    #elif FRENCH
        .categoryName = _("MORSURE"),
    #elif ITALIAN
        .categoryName = _("MORSO"),
    #endif
        .height = 5,
        .weight = 136,
        .description = gPoochyenaPokedexText,
        .pokemonScale = 481,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MIGHTYENA] =
    {
    #if ENGLISH
        .categoryName = _("BITE"),
    #elif FRENCH
        .categoryName = _("MORSURE"),
    #elif ITALIAN
        .categoryName = _("MORSO"),
    #endif
        .height = 10,
        .weight = 370,
        .description = gMightyenaPokedexText,
        .pokemonScale = 362,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZIGZAGOON] =
    {
    #if ENGLISH
        .categoryName = _("TINYRACCOON"),
    #elif FRENCH
        .categoryName = _("PETIT RATON"),
    #elif ITALIAN
        .categoryName = _("PROCIONE"),
    #endif
        .height = 4,
        .weight = 175,
        .description = gZigzagoonPokedexText,
        .pokemonScale = 560,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LINOONE] =
    {
    #if ENGLISH
        .categoryName = _("RUSHING"),
    #elif FRENCH
        .categoryName = _("FONCEUR"),
    #elif ITALIAN
        .categoryName = _("SFRECCIANTE"),
    #endif
        .height = 5,
        .weight = 325,
        .description = gLinoonePokedexText,
        .pokemonScale = 321,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WURMPLE] =
    {
    #if ENGLISH
        .categoryName = _("WORM"),
    #elif FRENCH
        .categoryName = _("VER"),
    #elif ITALIAN
        .categoryName = _("BACO"),
    #endif
        .height = 3,
        .weight = 36,
        .description = gWurmplePokedexText,
        .pokemonScale = 711,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SILCOON] =
    {
    #if ENGLISH
        .categoryName = _("COCOON"),
    #elif FRENCH
        .categoryName = _("COCON"),
    #elif ITALIAN
        .categoryName = _("BOZZOLO"),
    #endif
        .height = 6,
        .weight = 100,
        .description = gSilcoonPokedexText,
        .pokemonScale = 431,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BEAUTIFLY] =
    {
    #if ENGLISH
        .categoryName = _("BUTTERFLY"),
    #elif FRENCH
        .categoryName = _("PAPILLON"),
    #elif ITALIAN
        .categoryName = _("FARFALLA"),
    #endif
        .height = 10,
        .weight = 284,
        .description = gBeautiflyPokedexText,
        .pokemonScale = 298,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CASCOON] =
    {
    #if ENGLISH
        .categoryName = _("COCOON"),
    #elif FRENCH
        .categoryName = _("COCON"),
    #elif ITALIAN
        .categoryName = _("BOZZOLO"),
    #endif
        .height = 7,
        .weight = 115,
        .description = gCascoonPokedexText,
        .pokemonScale = 391,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DUSTOX] =
    {
    #if ENGLISH
        .categoryName = _("POISON MOTH"),
    #elif FRENCH
        .categoryName = _("PAPIPOISON"),
    #elif ITALIAN
        .categoryName = _("VELENTARMA"),
    #endif
        .height = 12,
        .weight = 316,
        .description = gDustoxPokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LOTAD] =
    {
    #if ENGLISH
        .categoryName = _("WATER WEED"),
    #elif FRENCH
        .categoryName = _("AQUAPLANTE"),
    #elif ITALIAN
        .categoryName = _("ALGA"),
    #endif
        .height = 5,
        .weight = 26,
        .description = gLotadPokedexText,
        .pokemonScale = 406,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LOMBRE] =
    {
    #if ENGLISH
        .categoryName = _("JOLLY"),
    #elif FRENCH
        .categoryName = _("JOVIAL"),
    #elif ITALIAN
        .categoryName = _("GIOCOSO"),
    #endif
        .height = 12,
        .weight = 325,
        .description = gLombrePokedexText,
        .pokemonScale = 277,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUDICOLO] =
    {
    #if ENGLISH
        .categoryName = _("CAREFREE"),
    #elif FRENCH
        .categoryName = _("INSOUCIANT"),
    #elif ITALIAN
        .categoryName = _("SPENSIERATO"),
    #endif
        .height = 15,
        .weight = 550,
        .description = gLudicoloPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_SEEDOT] =
    {
    #if ENGLISH
        .categoryName = _("ACORN"),
    #elif FRENCH
        .categoryName = _("GLAND"),
    #elif ITALIAN
        .categoryName = _("GHIANDA"),
    #endif
        .height = 5,
        .weight = 40,
        .description = gSeedotPokedexText,
        .pokemonScale = 472,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NUZLEAF] =
    {
    #if ENGLISH
        .categoryName = _("WILY"),
    #elif FRENCH
        .categoryName = _("MALIN"),
    #elif ITALIAN
        .categoryName = _("SCALTRO"),
    #endif
        .height = 10,
        .weight = 280,
        .description = gNuzleafPokedexText,
        .pokemonScale = 299,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHIFTRY] =
    {
    #if ENGLISH
        .categoryName = _("WICKED"),
    #elif FRENCH
        .categoryName = _("MALVEILLANT"),
    #elif ITALIAN
        .categoryName = _("BURBERO"),
    #endif
        .height = 13,
        .weight = 596,
        .description = gShiftryPokedexText,
        .pokemonScale = 290,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TAILLOW] =
    {
    #if ENGLISH
        .categoryName = _("TINYSWALLOW"),
    #elif FRENCH
        .categoryName = _("MINIRONDEL"),
    #elif ITALIAN
        .categoryName = _("RONDINELLA"),
    #endif
        .height = 3,
        .weight = 23,
        .description = gTaillowPokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SWELLOW] =
    {
    #if ENGLISH
        .categoryName = _("SWALLOW"),
    #elif FRENCH
        .categoryName = _("HIRONDELLE"),
    #elif ITALIAN
        .categoryName = _("RONDINE"),
    #endif
        .height = 7,
        .weight = 198,
        .description = gSwellowPokedexText,
        .pokemonScale = 428,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WINGULL] =
    {
    #if ENGLISH
        .categoryName = _("SEAGULL"),
    #elif FRENCH
        .categoryName = _("MOUETTE"),
    #elif ITALIAN
        .categoryName = _("GABBIANO"),
    #endif
        .height = 6,
        .weight = 95,
        .description = gWingullPokedexText,
        .pokemonScale = 295,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PELIPPER] =
    {
    #if ENGLISH
        .categoryName = _("WATER BIRD"),
    #elif FRENCH
        .categoryName = _("OISEAUDO"),
    #elif ITALIAN
        .categoryName = _("ALACQUATICO"),
    #endif
        .height = 12,
        .weight = 280,
        .description = gPelipperPokedexText,
        .pokemonScale = 288,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RALTS] =
    {
    #if ENGLISH
        .categoryName = _("FEELING"),
    #elif FRENCH
        .categoryName = _("SENTIMENT"),
    #elif ITALIAN
        .categoryName = _("SENSAZIONE"),
    #endif
        .height = 4,
        .weight = 66,
        .description = gRaltsPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KIRLIA] =
    {
    #if ENGLISH
        .categoryName = _("EMOTION"),
    #elif FRENCH
        .categoryName = _("EMOTION"),
    #elif ITALIAN
        .categoryName = _("EMOZIONE"),
    #endif
        .height = 8,
        .weight = 202,
        .description = gKirliaPokedexText,
        .pokemonScale = 354,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GARDEVOIR] =
    {
    #if ENGLISH
        .categoryName = _("EMBRACE"),
    #elif FRENCH
        .categoryName = _("ETREINTE"),
    #elif ITALIAN
        .categoryName = _("ABBRACCIO"),
    #endif
        .height = 16,
        .weight = 484,
        .description = gGardevoirPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SURSKIT] =
    {
    #if ENGLISH
        .categoryName = _("POND SKATER"),
    #elif FRENCH
        .categoryName = _("MARESURFEUR"),
    #elif ITALIAN
        .categoryName = _("SFIORAPOZZE"),
    #endif
        .height = 5,
        .weight = 17,
        .description = gSurskitPokedexText,
        .pokemonScale = 375,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MASQUERAIN] =
    {
    #if ENGLISH
        .categoryName = _("EYEBALL"),
    #elif FRENCH
        .categoryName = _("BOULE OEIL"),
    #elif ITALIAN
        .categoryName = _("OCCHI"),
    #endif
        .height = 8,
        .weight = 36,
        .description = gMasquerainPokedexText,
        .pokemonScale = 378,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHROOMISH] =
    {
    #if ENGLISH
        .categoryName = _("MUSHROOM"),
    #elif FRENCH
        .categoryName = _("CHAMPIGNON"),
    #elif ITALIAN
        .categoryName = _("FUNGO"),
    #endif
        .height = 4,
        .weight = 45,
        .description = gShroomishPokedexText,
        .pokemonScale = 513,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BRELOOM] =
    {
    #if ENGLISH
        .categoryName = _("MUSHROOM"),
    #elif FRENCH
        .categoryName = _("CHAMPIGNON"),
    #elif ITALIAN
        .categoryName = _("FUNGO"),
    #endif
        .height = 12,
        .weight = 392,
        .description = gBreloomPokedexText,
        .pokemonScale = 324,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLAKOTH] =
    {
    #if ENGLISH
        .categoryName = _("SLACKER"),
    #elif FRENCH
        .categoryName = _("FLANEUR"),
    #elif ITALIAN
        .categoryName = _("OZIOSO"),
    #endif
        .height = 8,
        .weight = 240,
        .description = gSlakothPokedexText,
        .pokemonScale = 291,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VIGOROTH] =
    {
    #if ENGLISH
        .categoryName = _("WILD MONKEY"),
    #elif FRENCH
        .categoryName = _("TURBUSINGE"),
    #elif ITALIAN
        .categoryName = _("INDOCILE"),
    #endif
        .height = 14,
        .weight = 465,
        .description = gVigorothPokedexText,
        .pokemonScale = 301,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLAKING] =
    {
    #if ENGLISH
        .categoryName = _("LAZY"),
    #elif FRENCH
        .categoryName = _("FAINEANT"),
    #elif ITALIAN
        .categoryName = _("PIGRIZIA"),
    #endif
        .height = 20,
        .weight = 1305,
        .description = gSlakingPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 300,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_NINCADA] =
    {
    #if ENGLISH
        .categoryName = _("TRAINEE"),
    #elif FRENCH
        .categoryName = _("APPRENTI"),
    #elif ITALIAN
        .categoryName = _("NOVIZIO"),
    #endif
        .height = 5,
        .weight = 55,
        .description = gNincadaPokedexText,
        .pokemonScale = 405,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NINJASK] =
    {
    #if ENGLISH
        .categoryName = _("NINJA"),
    #elif FRENCH
        .categoryName = _("NINJA"),
    #elif ITALIAN
        .categoryName = _("NINJA"),
    #endif
        .height = 8,
        .weight = 120,
        .description = gNinjaskPokedexText,
        .pokemonScale = 383,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHEDINJA] =
    {
    #if ENGLISH
        .categoryName = _("SHED"),
    #elif FRENCH
        .categoryName = _("EXUVIE"),
    #elif ITALIAN
        .categoryName = _("CAMBIAPELLE"),
    #endif
        .height = 8,
        .weight = 12,
        .description = gShedinjaPokedexText,
        .pokemonScale = 372,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WHISMUR] =
    {
    #if ENGLISH
        .categoryName = _("WHISPER"),
    #elif FRENCH
        .categoryName = _("CHUCHOTEUR"),
    #elif ITALIAN
        .categoryName = _("SUSSURRO"),
    #endif
        .height = 6,
        .weight = 163,
        .description = gWhismurPokedexText,
        .pokemonScale = 373,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LOUDRED] =
    {
    #if ENGLISH
        .categoryName = _("BIG VOICE"),
    #elif FRENCH
        .categoryName = _("GROSSE VOIX"),
    #elif ITALIAN
        .categoryName = _("VOCIONE"),
    #endif
        .height = 10,
        .weight = 405,
        .description = gLoudredPokedexText,
        .pokemonScale = 356,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_EXPLOUD] =
    {
    #if ENGLISH
        .categoryName = _("LOUD NOISE"),
    #elif FRENCH
        .categoryName = _("BRUIT SOURD"),
    #elif ITALIAN
        .categoryName = _("FRAGORE"),
    #endif
        .height = 15,
        .weight = 840,
        .description = gExploudPokedexText,
        .pokemonScale = 284,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAKUHITA] =
    {
    #if ENGLISH
        .categoryName = _("GUTS"),
    #elif FRENCH
        .categoryName = _("TENACE"),
    #elif ITALIAN
        .categoryName = _("CORAGGIO"),
    #endif
        .height = 10,
        .weight = 864,
        .description = gMakuhitaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HARIYAMA] =
    {
    #if ENGLISH
        .categoryName = _("ARM THRUST"),
    #elif FRENCH
        .categoryName = _("COGNEUR"),
    #elif ITALIAN
        .categoryName = _("SBERLETESE"),
    #endif
        .height = 23,
        .weight = 2538,
        .description = gHariyamaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 343,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_AZURILL] =
    {
    #if ENGLISH
        .categoryName = _("POLKA DOT"),
    #elif FRENCH
        .categoryName = _("POINT POLKA"),
    #elif ITALIAN
        .categoryName = _("POIS"),
    #endif
        .height = 2,
        .weight = 20,
        .description = gAzurillPokedexText,
        .pokemonScale = 603,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NOSEPASS] =
    {
    #if ENGLISH
        .categoryName = _("COMPASS"),
    #elif FRENCH
        .categoryName = _("BOUSSOLE"),
    #elif ITALIAN
        .categoryName = _("BUSSOLA"),
    #endif
        .height = 10,
        .weight = 970,
        .description = gNosepassPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 9,
        .trainerScale = 289,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_SKITTY] =
    {
    #if ENGLISH
        .categoryName = _("KITTEN"),
    #elif FRENCH
        .categoryName = _("CHATON"),
    #elif ITALIAN
        .categoryName = _("MICIO"),
    #endif
        .height = 6,
        .weight = 110,
        .description = gSkittyPokedexText,
        .pokemonScale = 492,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DELCATTY] =
    {
    #if ENGLISH
        .categoryName = _("PRIM"),
    #elif FRENCH
        .categoryName = _("GUINDE"),
    #elif ITALIAN
        .categoryName = _("FINEZZA"),
    #endif
        .height = 11,
        .weight = 326,
        .description = gDelcattyPokedexText,
        .pokemonScale = 322,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SABLEYE] =
    {
    #if ENGLISH
        .categoryName = _("DARKNESS"),
    #elif FRENCH
        .categoryName = _("OBSCURITE"),
    #elif ITALIAN
        .categoryName = _("OSCURITÀ"),
    #endif
        .height = 5,
        .weight = 110,
        .description = gSableyePokedexText,
        .pokemonScale = 451,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAWILE] =
    {
    #if ENGLISH
        .categoryName = _("DECEIVER"),
    #elif FRENCH
        .categoryName = _("TROMPEUR"),
    #elif ITALIAN
        .categoryName = _("INGANNO"),
    #endif
        .height = 6,
        .weight = 115,
        .description = gMawilePokedexText,
        .pokemonScale = 466,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARON] =
    {
    #if ENGLISH
        .categoryName = _("IRON ARMOR"),
    #elif FRENCH
        .categoryName = _("ARMURFER"),
    #elif ITALIAN
        .categoryName = _("CORAZZA"),
    #endif
        .height = 4,
        .weight = 600,
        .description = gAronPokedexText,
        .pokemonScale = 419,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LAIRON] =
    {
    #if ENGLISH
        .categoryName = _("IRON ARMOR"),
    #elif FRENCH
        .categoryName = _("ARMURFER"),
    #elif ITALIAN
        .categoryName = _("CORAZZA"),
    #endif
        .height = 9,
        .weight = 1200,
        .description = gLaironPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AGGRON] =
    {
    #if ENGLISH
        .categoryName = _("IRON ARMOR"),
    #elif FRENCH
        .categoryName = _("ARMURFER"),
    #elif ITALIAN
        .categoryName = _("CORAZZA"),
    #endif
        .height = 21,
        .weight = 3600,
        .description = gAggronPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 350,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_MEDITITE] =
    {
    #if ENGLISH
        .categoryName = _("MEDITATE"),
    #elif FRENCH
        .categoryName = _("MEDITATION"),
    #elif ITALIAN
        .categoryName = _("MEDITAZIONE"),
    #endif
        .height = 6,
        .weight = 112,
        .description = gMedititePokedexText,
        .pokemonScale = 465,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MEDICHAM] =
    {
    #if ENGLISH
        .categoryName = _("MEDITATE"),
    #elif FRENCH
        .categoryName = _("MEDITATION"),
    #elif ITALIAN
        .categoryName = _("MEDITAZIONE"),
    #endif
        .height = 13,
        .weight = 315,
        .description = gMedichamPokedexText,
        .pokemonScale = 298,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ELECTRIKE] =
    {
    #if ENGLISH
        .categoryName = _("LIGHTNING"),
    #elif FRENCH
        .categoryName = _("ORAGE"),
    #elif ITALIAN
        .categoryName = _("LAMPO"),
    #endif
        .height = 6,
        .weight = 152,
        .description = gElectrikePokedexText,
        .pokemonScale = 290,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MANECTRIC] =
    {
    #if ENGLISH
        .categoryName = _("DISCHARGE"),
    #elif FRENCH
        .categoryName = _("DECHARGE"),
    #elif ITALIAN
        .categoryName = _("SCOSSA"),
    #endif
        .height = 15,
        .weight = 402,
        .description = gManectricPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PLUSLE] =
    {
    #if ENGLISH
        .categoryName = _("CHEERING"),
    #elif FRENCH
        .categoryName = _("ACCLAMEUR"),
    #elif ITALIAN
        .categoryName = _("INCITAMENTO"),
    #endif
        .height = 4,
        .weight = 42,
        .description = gPluslePokedexText,
        .pokemonScale = 515,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MINUN] =
    {
    #if ENGLISH
        .categoryName = _("CHEERING"),
    #elif FRENCH
        .categoryName = _("ACCLAMEUR"),
    #elif ITALIAN
        .categoryName = _("INCITAMENTO"),
    #endif
        .height = 4,
        .weight = 42,
        .description = gMinunPokedexText,
        .pokemonScale = 512,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VOLBEAT] =
    {
    #if ENGLISH
        .categoryName = _("FIREFLY"),
    #elif FRENCH
        .categoryName = _("LUCIOLE"),
    #elif ITALIAN
        .categoryName = _("LUCCIOLA"),
    #endif
        .height = 7,
        .weight = 177,
        .description = gVolbeatPokedexText,
        .pokemonScale = 442,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ILLUMISE] =
    {
    #if ENGLISH
        .categoryName = _("FIREFLY"),
    #elif FRENCH
        .categoryName = _("LUCIOLE"),
    #elif ITALIAN
        .categoryName = _("LUCCIOLA"),
    #endif
        .height = 6,
        .weight = 177,
        .description = gIllumisePokedexText,
        .pokemonScale = 572,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ROSELIA] =
    {
    #if ENGLISH
        .categoryName = _("THORN"),
    #elif FRENCH
        .categoryName = _("EPINE"),
    #elif ITALIAN
        .categoryName = _("SPINA"),
    #endif
        .height = 3,
        .weight = 20,
        .description = gRoseliaPokedexText,
        .pokemonScale = 677,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GULPIN] =
    {
    #if ENGLISH
        .categoryName = _("STOMACH"),
    #elif FRENCH
        .categoryName = _("ESTOMAC"),
    #elif ITALIAN
        .categoryName = _("STOMACO"),
    #endif
        .height = 4,
        .weight = 103,
        .description = gGulpinPokedexText,
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SWALOT] =
    {
    #if ENGLISH
        .categoryName = _("POISON BAG"),
    #elif FRENCH
        .categoryName = _("SAC POISON"),
    #elif ITALIAN
        .categoryName = _("VELENOSACCO"),
    #endif
        .height = 17,
        .weight = 800,
        .description = gSwalotPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_CARVANHA] =
    {
    #if ENGLISH
        .categoryName = _("SAVAGE"),
    #elif FRENCH
        .categoryName = _("FEROCE"),
    #elif ITALIAN
        .categoryName = _("FEROCE"),
    #endif
        .height = 8,
        .weight = 208,
        .description = gCarvanhaPokedexText,
        .pokemonScale = 362,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHARPEDO] =
    {
    #if ENGLISH
        .categoryName = _("BRUTAL"),
    #elif FRENCH
        .categoryName = _("BRUTAL"),
    #elif ITALIAN
        .categoryName = _("BRUTALE"),
    #endif
        .height = 18,
        .weight = 888,
        .description = gSharpedoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 317,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_WAILMER] =
    {
    #if ENGLISH
        .categoryName = _("BALL WHALE"),
    #elif FRENCH
        .categoryName = _("BALEINBOULE"),
    #elif ITALIAN
        .categoryName = _("BALENOTTERO"),
    #endif
        .height = 20,
        .weight = 1300,
        .description = gWailmerPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 493,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WAILORD] =
    {
    #if ENGLISH
        .categoryName = _("FLOAT WHALE"),
    #elif FRENCH
        .categoryName = _("CACHABOUEE"),
    #elif ITALIAN
        .categoryName = _("MEGABALENA"),
    #endif
        .height = 145,
        .weight = 3980,
        .description = gWailordPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 1352,
        .trainerOffset = 18,
    },

    [NATIONAL_DEX_NUMEL] =
    {
    #if ENGLISH
        .categoryName = _("NUMB"),
    #elif FRENCH
        .categoryName = _("ENGOURDI"),
    #elif ITALIAN
        .categoryName = _("TORPORE"),
    #endif
        .height = 7,
        .weight = 240,
        .description = gNumelPokedexText,
        .pokemonScale = 342,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CAMERUPT] =
    {
    #if ENGLISH
        .categoryName = _("ERUPTION"),
    #elif FRENCH
        .categoryName = _("ERUPTION"),
    #elif ITALIAN
        .categoryName = _("ERUZIONE"),
    #endif
        .height = 19,
        .weight = 2200,
        .description = gCameruptPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 7,
        .trainerScale = 345,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_TORKOAL] =
    {
    #if ENGLISH
        .categoryName = _("COAL"),
    #elif FRENCH
        .categoryName = _("CHARBON"),
    #elif ITALIAN
        .categoryName = _("CARBONE"),
    #endif
        .height = 5,
        .weight = 804,
        .description = gTorkoalPokedexText,
        .pokemonScale = 390,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPOINK] =
    {
    #if ENGLISH
        .categoryName = _("BOUNCE"),
    #elif FRENCH
        .categoryName = _("REBOND"),
    #elif ITALIAN
        .categoryName = _("MOLLA"),
    #endif
        .height = 7,
        .weight = 306,
        .description = gSpoinkPokedexText,
        .pokemonScale = 423,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GRUMPIG] =
    {
    #if ENGLISH
        .categoryName = _("MANIPULATE"),
    #elif FRENCH
        .categoryName = _("MAGOUILLEUR"),
    #elif ITALIAN
        .categoryName = _("RAGGIRO"),
    #endif
        .height = 9,
        .weight = 715,
        .description = gGrumpigPokedexText,
        .pokemonScale = 358,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPINDA] =
    {
    #if ENGLISH
        .categoryName = _("SPOT PANDA"),
    #elif FRENCH
        .categoryName = _("PANDA TACHE"),
    #elif ITALIAN
        .categoryName = _("MACCHIPANDA"),
    #endif
        .height = 11,
        .weight = 50,
        .description = gSpindaPokedexText,
        .pokemonScale = 321,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TRAPINCH] =
    {
    #if ENGLISH
        .categoryName = _("ANT PIT"),
    #elif FRENCH
        .categoryName = _("PIEGEUR"),
    #elif ITALIAN
        .categoryName = _("TRAPPOLA"),
    #endif
        .height = 7,
        .weight = 150,
        .description = gTrapinchPokedexText,
        .pokemonScale = 298,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VIBRAVA] =
    {
    #if ENGLISH
        .categoryName = _("VIBRATION"),
    #elif FRENCH
        .categoryName = _("VIBRATION"),
    #elif ITALIAN
        .categoryName = _("VIBRAZIONE"),
    #endif
        .height = 11,
        .weight = 153,
        .description = gVibravaPokedexText,
        .pokemonScale = 370,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLYGON] =
    {
    #if ENGLISH
        .categoryName = _("MYSTIC"),
    #elif FRENCH
        .categoryName = _("MYSTIQUE"),
    #elif ITALIAN
        .categoryName = _("MAGICO"),
    #endif
        .height = 20,
        .weight = 820,
        .description = gFlygonPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_CACNEA] =
    {
    #if ENGLISH
        .categoryName = _("CACTUS"),
    #elif FRENCH
        .categoryName = _("CACTUS"),
    #elif ITALIAN
        .categoryName = _("CACTUS"),
    #endif
        .height = 4,
        .weight = 513,
        .description = gCacneaPokedexText,
        .pokemonScale = 455,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CACTURNE] =
    {
    #if ENGLISH
        .categoryName = _("SCARECROW"),
    #elif FRENCH
        .categoryName = _("EPOUVANTAIL"),
    #elif ITALIAN
        .categoryName = _("SPAVENTO"),
    #endif
        .height = 13,
        .weight = 774,
        .description = gCacturnePokedexText,
        .pokemonScale = 327,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SWABLU] =
    {
    #if ENGLISH
        .categoryName = _("COTTON BIRD"),
    #elif FRENCH
        .categoryName = _("OISEAUCOTON"),
    #elif ITALIAN
        .categoryName = _("ALIDICOTONE"),
    #endif
        .height = 4,
        .weight = 12,
        .description = gSwabluPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ALTARIA] =
    {
    #if ENGLISH
        .categoryName = _("HUMMING"),
    #elif FRENCH
        .categoryName = _("VIREVOLTEUR"),
    #elif ITALIAN
        .categoryName = _("CANTERINO"),
    #endif
        .height = 11,
        .weight = 206,
        .description = gAltariaPokedexText,
        .pokemonScale = 327,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZANGOOSE] =
    {
    #if ENGLISH
        .categoryName = _("CAT FERRET"),
    #elif FRENCH
        .categoryName = _("CHAT FURET"),
    #elif ITALIAN
        .categoryName = _("FUROGATTO"),
    #endif
        .height = 13,
        .weight = 403,
        .description = gZangoosePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SEVIPER] =
    {
    #if ENGLISH
        .categoryName = _("FANG SNAKE"),
    #elif FRENCH
        .categoryName = _("SERPACROC"),
    #elif ITALIAN
        .categoryName = _("ZANNASERPE"),
    #endif
        .height = 27,
        .weight = 525,
        .description = gSeviperPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUNATONE] =
    {
    #if ENGLISH
        .categoryName = _("METEORITE"),
    #elif FRENCH
        .categoryName = _("METEORITE"),
    #elif ITALIAN
        .categoryName = _("METEORITE"),
    #endif
        .height = 10,
        .weight = 1680,
        .description = gLunatonePokedexText,
        .pokemonScale = 300,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SOLROCK] =
    {
    #if ENGLISH
        .categoryName = _("METEORITE"),
    #elif FRENCH
        .categoryName = _("METEORITE"),
    #elif ITALIAN
        .categoryName = _("METEORITE"),
    #endif
        .height = 12,
        .weight = 1540,
        .description = gSolrockPokedexText,
        .pokemonScale = 328,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BARBOACH] =
    {
    #if ENGLISH
        .categoryName = _("WHISKERS"),
    #elif FRENCH
        .categoryName = _("BARBILLON"),
    #elif ITALIAN
        .categoryName = _("BAFFETTI"),
    #endif
        .height = 4,
        .weight = 19,
        .description = gBarboachPokedexText,
        .pokemonScale = 581,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WHISCASH] =
    {
    #if ENGLISH
        .categoryName = _("WHISKERS"),
    #elif FRENCH
        .categoryName = _("BARBILLON"),
    #elif ITALIAN
        .categoryName = _("BAFFETTI"),
    #endif
        .height = 9,
        .weight = 236,
        .description = gWhiscashPokedexText,
        .pokemonScale = 317,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CORPHISH] =
    {
    #if ENGLISH
        .categoryName = _("RUFFIAN"),
    #elif FRENCH
        .categoryName = _("BRUTE"),
    #elif ITALIAN
        .categoryName = _("BIRBONE"),
    #endif
        .height = 6,
        .weight = 115,
        .description = gCorphishPokedexText,
        .pokemonScale = 484,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CRAWDAUNT] =
    {
    #if ENGLISH
        .categoryName = _("ROGUE"),
    #elif FRENCH
        .categoryName = _("CRAPULE"),
    #elif ITALIAN
        .categoryName = _("CANAGLIA"),
    #endif
        .height = 11,
        .weight = 328,
        .description = gCrawdauntPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BALTOY] =
    {
    #if ENGLISH
        .categoryName = _("CLAY DOLL"),
    #elif FRENCH
        .categoryName = _("POUPARGILE"),
    #elif ITALIAN
        .categoryName = _("ARGILLA"),
    #endif
        .height = 5,
        .weight = 215,
        .description = gBaltoyPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLAYDOL] =
    {
    #if ENGLISH
        .categoryName = _("CLAY DOLL"),
    #elif FRENCH
        .categoryName = _("POUPARGILE"),
    #elif ITALIAN
        .categoryName = _("ARGILLA"),
    #endif
        .height = 15,
        .weight = 1080,
        .description = gClaydolPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 280,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_LILEEP] =
    {
    #if ENGLISH
        .categoryName = _("SEA LILY"),
    #elif FRENCH
        .categoryName = _("LIS D'EAU"),
    #elif ITALIAN
        .categoryName = _("FIORDIMARE"),
    #endif
        .height = 10,
        .weight = 238,
        .description = gLileepPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CRADILY] =
    {
    #if ENGLISH
        .categoryName = _("BARNACLE"),
    #elif FRENCH
        .categoryName = _("BERNACLE"),
    #elif ITALIAN
        .categoryName = _("LEPADE"),
    #endif
        .height = 15,
        .weight = 604,
        .description = gCradilyPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ANORITH] =
    {
    #if ENGLISH
        .categoryName = _("OLD SHRIMP"),
    #elif FRENCH
        .categoryName = _("CRUSTAGE"),
    #elif ITALIAN
        .categoryName = _("PRIMACEO"),
    #endif
        .height = 7,
        .weight = 125,
        .description = gAnorithPokedexText,
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARMALDO] =
    {
    #if ENGLISH
        .categoryName = _("PLATE"),
    #elif FRENCH
        .categoryName = _("BLINDAGE"),
    #elif ITALIAN
        .categoryName = _("PIASTRE"),
    #endif
        .height = 15,
        .weight = 682,
        .description = gArmaldoPokedexText,
        .pokemonScale = 312,
        .pokemonOffset = 3,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FEEBAS] =
    {
    #if ENGLISH
        .categoryName = _("FISH"),
    #elif FRENCH
        .categoryName = _("POISSON"),
    #elif ITALIAN
        .categoryName = _("PESCE"),
    #endif
        .height = 6,
        .weight = 74,
        .description = gFeebasPokedexText,
        .pokemonScale = 423,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MILOTIC] =
    {
    #if ENGLISH
        .categoryName = _("TENDER"),
    #elif FRENCH
        .categoryName = _("TENDRE"),
    #elif ITALIAN
        .categoryName = _("TENEREZZA"),
    #endif
        .height = 62,
        .weight = 1620,
        .description = gMiloticPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 360,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CASTFORM] =
    {
    #if ENGLISH
        .categoryName = _("WEATHER"),
    #elif FRENCH
        .categoryName = _("CLIMAT"),
    #elif ITALIAN
        .categoryName = _("METEO"),
    #endif
        .height = 3,
        .weight = 8,
        .description = gCastformPokedexText,
        .pokemonScale = 435,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KECLEON] =
    {
    #if ENGLISH
        .categoryName = _("COLOR SWAP"),
    #elif FRENCH
        .categoryName = _("MULTICOLOR"),
    #elif ITALIAN
        .categoryName = _("MUTACOLORE"),
    #endif
        .height = 10,
        .weight = 220,
        .description = gKecleonPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHUPPET] =
    {
    #if ENGLISH
        .categoryName = _("PUPPET"),
    #elif FRENCH
        .categoryName = _("POUPEE"),
    #elif ITALIAN
        .categoryName = _("PUPAZZO"),
    #endif
        .height = 6,
        .weight = 23,
        .description = gShuppetPokedexText,
        .pokemonScale = 440,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BANETTE] =
    {
    #if ENGLISH
        .categoryName = _("MARIONETTE"),
    #elif FRENCH
        .categoryName = _("MARIONETTE"),
    #elif ITALIAN
        .categoryName = _("MARIONETTA"),
    #endif
        .height = 11,
        .weight = 125,
        .description = gBanettePokedexText,
        .pokemonScale = 262,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DUSKULL] =
    {
    #if ENGLISH
        .categoryName = _("REQUIEM"),
    #elif FRENCH
        .categoryName = _("REQUIEM"),
    #elif ITALIAN
        .categoryName = _("REQUIEM"),
    #endif
        .height = 8,
        .weight = 150,
        .description = gDuskullPokedexText,
        .pokemonScale = 406,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DUSCLOPS] =
    {
    #if ENGLISH
        .categoryName = _("BECKON"),
    #elif FRENCH
        .categoryName = _("APPEL"),
    #elif ITALIAN
        .categoryName = _("IPNOSGUARDO"),
    #endif
        .height = 16,
        .weight = 306,
        .description = gDusclopsPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 299,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_TROPIUS] =
    {
    #if ENGLISH
        .categoryName = _("FRUIT"),
    #elif FRENCH
        .categoryName = _("FRUIT"),
    #elif ITALIAN
        .categoryName = _("FRUTTO"),
    #endif
        .height = 20,
        .weight = 1000,
        .description = gTropiusPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 344,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CHIMECHO] =
    {
    #if ENGLISH
        .categoryName = _("WIND CHIME"),
    #elif FRENCH
        .categoryName = _("CARILLON"),
    #elif ITALIAN
        .categoryName = _("VENCAMPANA"),
    #endif
        .height = 6,
        .weight = 10,
        .description = gChimechoPokedexText,
        .pokemonScale = 505,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ABSOL] =
    {
    #if ENGLISH
        .categoryName = _("DISASTER"),
    #elif FRENCH
        .categoryName = _("DESASTRE"),
    #elif ITALIAN
        .categoryName = _("CATASTROFE"),
    #endif
        .height = 12,
        .weight = 470,
        .description = gAbsolPokedexText,
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WYNAUT] =
    {
    #if ENGLISH
        .categoryName = _("BRIGHT"),
    #elif FRENCH
        .categoryName = _("RAVI"),
    #elif ITALIAN
        .categoryName = _("BRILLANTE"),
    #endif
        .height = 6,
        .weight = 140,
        .description = gWynautPokedexText,
        .pokemonScale = 484,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SNORUNT] =
    {
    #if ENGLISH
        .categoryName = _("SNOW HAT"),
    #elif FRENCH
        .categoryName = _("CAPUCHE"),
    #elif ITALIAN
        .categoryName = _("CAPPELNEVE"),
    #endif
        .height = 7,
        .weight = 168,
        .description = gSnoruntPokedexText,
        .pokemonScale = 380,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GLALIE] =
    {
    #if ENGLISH
        .categoryName = _("FACE"),
    #elif FRENCH
        .categoryName = _("FACE"),
    #elif ITALIAN
        .categoryName = _("TUTTOMUSO"),
    #endif
        .height = 15,
        .weight = 2565,
        .description = gGlaliePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 344,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPHEAL] =
    {
    #if ENGLISH
        .categoryName = _("CLAP"),
    #elif FRENCH
        .categoryName = _("CLAP CLAP"),
    #elif ITALIAN
        .categoryName = _("ROTOLANTE"),
    #endif
        .height = 8,
        .weight = 395,
        .description = gSphealPokedexText,
        .pokemonScale = 315,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SEALEO] =
    {
    #if ENGLISH
        .categoryName = _("BALL ROLL"),
    #elif FRENCH
        .categoryName = _("ROULE BOULE"),
    #elif ITALIAN
        .categoryName = _("ROTAPALLA"),
    #endif
        .height = 11,
        .weight = 876,
        .description = gSealeoPokedexText,
        .pokemonScale = 338,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WALREIN] =
    {
    #if ENGLISH
        .categoryName = _("ICE BREAK"),
    #elif FRENCH
        .categoryName = _("BRISE GLACE"),
    #elif ITALIAN
        .categoryName = _("SPACCAGELO"),
    #endif
        .height = 14,
        .weight = 1506,
        .description = gWalreinPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CLAMPERL] =
    {
    #if ENGLISH
        .categoryName = _("BIVALVE"),
    #elif FRENCH
        .categoryName = _("BIVALVE"),
    #elif ITALIAN
        .categoryName = _("BIVALVE"),
    #endif
        .height = 4,
        .weight = 525,
        .description = gClamperlPokedexText,
        .pokemonScale = 691,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HUNTAIL] =
    {
    #if ENGLISH
        .categoryName = _("DEEP SEA"),
    #elif FRENCH
        .categoryName = _("ABYSSE"),
    #elif ITALIAN
        .categoryName = _("ABISSI"),
    #endif
        .height = 17,
        .weight = 270,
        .description = gHuntailPokedexText,
        .pokemonScale = 307,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOREBYSS] =
    {
    #if ENGLISH
        .categoryName = _("SOUTH SEA"),
    #elif FRENCH
        .categoryName = _("MER DU SUD"),
    #elif ITALIAN
        .categoryName = _("SUDMARINO"),
    #endif
        .height = 18,
        .weight = 226,
        .description = gGorebyssPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RELICANTH] =
    {
    #if ENGLISH
        .categoryName = _("LONGEVITY"),
    #elif FRENCH
        .categoryName = _("LONGEVITE"),
    #elif ITALIAN
        .categoryName = _("LONGEVITÀ"),
    #endif
        .height = 10,
        .weight = 234,
        .description = gRelicanthPokedexText,
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUVDISC] =
    {
    #if ENGLISH
        .categoryName = _("RENDEZVOUS"),
    #elif FRENCH
        .categoryName = _("RENDEZVOUS"),
    #elif ITALIAN
        .categoryName = _("RENDEZVOUS"),
    #endif
        .height = 6,
        .weight = 87,
        .description = gLuvdiscPokedexText,
        .pokemonScale = 371,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BAGON] =
    {
    #if ENGLISH
        .categoryName = _("ROCK HEAD"),
    #elif FRENCH
        .categoryName = _("TETE DE ROC"),
    #elif ITALIAN
        .categoryName = _("ROCCIOTESTA"),
    #endif
        .height = 6,
        .weight = 421,
        .description = gBagonPokedexText,
        .pokemonScale = 448,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHELGON] =
    {
    #if ENGLISH
        .categoryName = _("ENDURANCE"),
    #elif FRENCH
        .categoryName = _("ENDURANT"),
    #elif ITALIAN
        .categoryName = _("RESISTENZA"),
    #endif
        .height = 11,
        .weight = 1105,
        .description = gShelgonPokedexText,
        .pokemonScale = 311,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SALAMENCE] =
    {
    #if ENGLISH
        .categoryName = _("DRAGON"),
    #elif FRENCH
        .categoryName = _("DRAGON"),
    #elif ITALIAN
        .categoryName = _("DRAGO"),
    #endif
        .height = 15,
        .weight = 1026,
        .description = gSalamencePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BELDUM] =
    {
    #if ENGLISH
        .categoryName = _("IRON BALL"),
    #elif FRENCH
        .categoryName = _("BOULEFER"),
    #elif ITALIAN
        .categoryName = _("FERROSFERA"),
    #endif
        .height = 6,
        .weight = 952,
        .description = gBeldumPokedexText,
        .pokemonScale = 414,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_METANG] =
    {
    #if ENGLISH
        .categoryName = _("IRON CLAW"),
    #elif FRENCH
        .categoryName = _("PINCEFER"),
    #elif ITALIAN
        .categoryName = _("FERRUNGHIA"),
    #endif
        .height = 12,
        .weight = 2025,
        .description = gMetangPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_METAGROSS] =
    {
    #if ENGLISH
        .categoryName = _("IRON LEG"),
    #elif FRENCH
        .categoryName = _("PATTEFER"),
    #elif ITALIAN
        .categoryName = _("FERRARTO"),
    #endif
        .height = 16,
        .weight = 5500,
        .description = gMetagrossPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 447,
        .trainerOffset = 9,
    },

    [NATIONAL_DEX_REGIROCK] =
    {
    #if ENGLISH
        .categoryName = _("ROCK PEAK"),
    #elif FRENCH
        .categoryName = _("PIC ROCHEUX"),
    #elif ITALIAN
        .categoryName = _("PICCO"),
    #endif
        .height = 17,
        .weight = 2300,
        .description = gRegirockPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 309,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_REGICE] =
    {
    #if ENGLISH
        .categoryName = _("ICEBERG"),
    #elif FRENCH
        .categoryName = _("ICEBERG"),
    #elif ITALIAN
        .categoryName = _("ICEBERG"),
    #endif
        .height = 18,
        .weight = 1750,
        .description = gRegicePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_REGISTEEL] =
    {
    #if ENGLISH
        .categoryName = _("IRON"),
    #elif FRENCH
        .categoryName = _("FER"),
    #elif ITALIAN
        .categoryName = _("FERRO"),
    #endif
        .height = 19,
        .weight = 2050,
        .description = gRegisteelPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 359,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_LATIAS] =
    {
    #if ENGLISH
        .categoryName = _("EON"),
    #elif FRENCH
        .categoryName = _("EON"),
    #elif ITALIAN
        .categoryName = _("EONE"),
    #endif
        .height = 14,
        .weight = 400,
        .description = gLatiasPokedexText,
        .pokemonScale = 304,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LATIOS] =
    {
    #if ENGLISH
        .categoryName = _("EON"),
    #elif FRENCH
        .categoryName = _("EON"),
    #elif ITALIAN
        .categoryName = _("EONE"),
    #endif
        .height = 20,
        .weight = 600,
        .description = gLatiosPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 294,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_KYOGRE] =
    {
    #if ENGLISH
        .categoryName = _("SEA BASIN"),
    #elif FRENCH
        .categoryName = _("BASSINMARIN"),
    #elif ITALIAN
        .categoryName = _("OCEANO"),
    #endif
        .height = 45,
        .weight = 3520,
        .description = gKyogrePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 614,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_GROUDON] =
    {
    #if ENGLISH
        .categoryName = _("CONTINENT"),
    #elif FRENCH
        .categoryName = _("CONTINENT"),
    #elif ITALIAN
        .categoryName = _("CONTINENTE"),
    #endif
        .height = 35,
        .weight = 9500,
        .description = gGroudonPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 515,
        .trainerOffset = 14,
    },

    [NATIONAL_DEX_RAYQUAZA] =
    {
    #if ENGLISH
        .categoryName = _("SKY HIGH"),
    #elif FRENCH
        .categoryName = _("CIEUX"),
    #elif ITALIAN
        .categoryName = _("STRATOSFERA"),
    #endif
        .height = 70,
        .weight = 2065,
        .description = gRayquazaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 448,
        .trainerOffset = 12,
    },

    [NATIONAL_DEX_JIRACHI] =
    {
    #if ENGLISH
        .categoryName = _("WISH"),
    #elif FRENCH
        .categoryName = _("SOUHAIT"),
    #elif ITALIAN
        .categoryName = _("DESIDERIO"),
    #endif
        .height = 3,
        .weight = 11,
        .description = gJirachiPokedexText,
        .pokemonScale = 608,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DEOXYS] =
    {
    #if ENGLISH
        .categoryName = _("DNA"),
    #elif FRENCH
        .categoryName = _("ADN"),
    #elif ITALIAN
        .categoryName = _("DNA"),
    #endif
        .height = 17,
        .weight = 608,
        .description = gDeoxysPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
    },
};
