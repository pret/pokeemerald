const struct PokedexEntry gPokedexEntries[] =
{
    [NATIONAL_DEX_NONE] =
    {
        .categoryName = LANGUAGE_STRING("UNKNOWN", "INCONNU", "SCONOSC", "DESCON."),
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
        .categoryName = LANGUAGE_STRING("SEED", "GRAINE", "SEME", "SEMILLA"),
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
        .categoryName = LANGUAGE_STRING("SEED", "GRAINE", "SEME", "SEMILLA"),
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
        .categoryName = LANGUAGE_STRING("SEED", "GRAINE", "SEME", "SEMILLA"),
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
        .categoryName = LANGUAGE_STRING("LIZARD", "LEZARD", "LUCERTOLA", "LAGARTIJA"),
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
        .categoryName = LANGUAGE_STRING("FLAME", "FLAMME", "FIAMMA", "LLAMA"),
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
        .categoryName = LANGUAGE_STRING("FLAME", "FLAMME", "FIAMMA", "LLAMA"),
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
        .categoryName = LANGUAGE_STRING("TINY TURTLE", "MINITORTUE", "TARTAGHINA", "TORTUGUITA"),
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
        .categoryName = LANGUAGE_STRING("TURTLE", "TORTUE", "TARTARUGA", "TORTUGA"),
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
        .categoryName = LANGUAGE_STRING("SHELLFISH", "CARAPACE", "CROSTACEO", "MARISCO"),
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
        .categoryName = LANGUAGE_STRING("WORM", "VER", "BACO", "GUSANO"),
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
        .categoryName = LANGUAGE_STRING("COCOON", "COCON", "BOZZOLO", "CAPULLO"),
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
        .categoryName = LANGUAGE_STRING("BUTTERFLY", "PAPILLON", "FARFALLA", "MARIPOSA"),
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
        .categoryName = LANGUAGE_STRING("HAIRY BUG", "INSECTOPIC", "MILLEPIEDI", "ORUGA"),
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
        .categoryName = LANGUAGE_STRING("COCOON", "COCON", "BOZZOLO", "CAPULLO"),
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
        .categoryName = LANGUAGE_STRING("POISON BEE", "GUEPOISON", "VELENAPE", "ABEJA VEN."),
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
        .categoryName = LANGUAGE_STRING("TINY BIRD", "MINOISEAU", "UCCELLINO", "PAJARITO"),
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
        .categoryName = LANGUAGE_STRING("BIRD", "OISEAU", "UCCELLO", "PÁJARO"),
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
        .categoryName = LANGUAGE_STRING("BIRD", "OISEAU", "UCCELLO", "PÁJARO"),
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
        .categoryName = LANGUAGE_STRING("MOUSE", "SOURIS", "TOPO", "RATÓN"),
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
        .categoryName = LANGUAGE_STRING("MOUSE", "SOURIS", "TOPO", "RATÓN"),
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
        .categoryName = LANGUAGE_STRING("TINY BIRD", "MINOISEAU", "UCCELLINO", "PAJARITO"),
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
        .categoryName = LANGUAGE_STRING("BEAK", "BEC-OISEAU", "BECCO", "PICO"),
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
        .categoryName = LANGUAGE_STRING("SNAKE", "SERPENT", "SERPENTE", "SERPIENTE"),
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
        .categoryName = LANGUAGE_STRING("COBRA", "COBRA", "COBRA", "COBRA"),
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
        .categoryName = LANGUAGE_STRING("MOUSE", "SOURIS", "TOPO", "RATÓN"),
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
        .categoryName = LANGUAGE_STRING("MOUSE", "SOURIS", "TOPO", "RATÓN"),
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
        .categoryName = LANGUAGE_STRING("MOUSE", "SOURIS", "TOPO", "RATÓN"),
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
        .categoryName = LANGUAGE_STRING("MOUSE", "SOURIS", "TOPO", "RATÓN"),
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
        .categoryName = LANGUAGE_STRING("POISON PIN", "VENEPIC", "VELENAGO", "PIN VENENO"),
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
        .categoryName = LANGUAGE_STRING("POISON PIN", "VENEPIC", "VELENAGO", "PIN VENENO"),
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
        .categoryName = LANGUAGE_STRING("DRILL", "PERCEUR", "TRAPANO", "TALADRO"),
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
        .categoryName = LANGUAGE_STRING("POISON PIN", "VENEPIC", "VELENAGO", "PIN VENENO"),
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
        .categoryName = LANGUAGE_STRING("POISON PIN", "VENEPIC", "VELENAGO", "PIN VENENO"),
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
        .categoryName = LANGUAGE_STRING("DRILL", "PERCEUR", "TRAPANO", "TALADRO"),
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
        .categoryName = LANGUAGE_STRING("FAIRY", "FEE", "FATA", "HADA"),
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
        .categoryName = LANGUAGE_STRING("FAIRY", "FEE", "FATA", "HADA"),
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
        .categoryName = LANGUAGE_STRING("FOX", "RENARD", "VOLPE", "ZORRO"),
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
        .categoryName = LANGUAGE_STRING("FOX", "RENARD", "VOLPE", "ZORRO"),
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
        .categoryName = LANGUAGE_STRING("BALLOON", "BOUBOULE", "PALLONE", "GLOBO"),
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
        .categoryName = LANGUAGE_STRING("BALLOON", "BOUBOULE", "PALLONE", "GLOBO"),
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
        .categoryName = LANGUAGE_STRING("BAT", "CHOVSOURIS", "PIPISTREL.", "MURCIÉLAGO"),
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
        .categoryName = LANGUAGE_STRING("BAT", "CHOVSOURIS", "PIPISTREL.", "MURCIÉLAGO"),
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
        .categoryName = LANGUAGE_STRING("WEED", "RACINE", "MALERBA", "HIERBAJO"),
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
        .categoryName = LANGUAGE_STRING("WEED", "RACINE", "MALERBA", "HIERBAJO"),
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
        .categoryName = LANGUAGE_STRING("FLOWER", "FLEUR", "FIORE", "FLOR"),
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
        .categoryName = LANGUAGE_STRING("MUSHROOM", "CHAMPIGNON", "FUNGO", "HONGO"),
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
        .categoryName = LANGUAGE_STRING("MUSHROOM", "CHAMPIGNON", "FUNGO", "HONGO"),
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
        .categoryName = LANGUAGE_STRING("INSECT", "VERMINE", "INSETTO", "INSECTO"),
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
        .categoryName = LANGUAGE_STRING("POISON MOTH", "PAPIPOISON", "VELENTARMA", "POLILLA V."),
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
        .categoryName = LANGUAGE_STRING("MOLE", "TAUPE", "TALPA", "TOPO"),
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
        .categoryName = LANGUAGE_STRING("MOLE", "TAUPE", "TALPA", "TOPO"),
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
        .categoryName = LANGUAGE_STRING("SCRATCH CAT", "CHADEGOUT", "GRAFFIMIAO", "GATO ARAÑA"),
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
        .categoryName = LANGUAGE_STRING("CLASSY CAT", "CHADEVILLE", "NOBILGATTO", "GATO FINO"),
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
        .categoryName = LANGUAGE_STRING("DUCK", "CANARD", "PAPERO", "PATO"),
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
        .categoryName = LANGUAGE_STRING("DUCK", "CANARD", "PAPERO", "PATO"),
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
        .categoryName = LANGUAGE_STRING("PIG MONKEY", "PORSINGE", "SUINPANZÉ", "MONO CERDO"),
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
        .categoryName = LANGUAGE_STRING("PIG MONKEY", "PORSINGE", "SUINPANZÉ", "MONO CERDO"),
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
        .categoryName = LANGUAGE_STRING("PUPPY", "CHIOT", "CAGNOLINO", "PERRITO"),
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
        .categoryName = LANGUAGE_STRING("LEGENDARY", "LEGENDAIRE", "LEGGENDA", "LEGENDARIO"),
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
        .categoryName = LANGUAGE_STRING("TADPOLE", "TETARD", "GIRINO", "RENACUAJO"),
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
        .categoryName = LANGUAGE_STRING("TADPOLE", "TETARD", "GIRINO", "RENACUAJO"),
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
        .categoryName = LANGUAGE_STRING("TADPOLE", "TETARD", "GIRINO", "RENACUAJO"),
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
        .categoryName = LANGUAGE_STRING("PSI", "PSY", "PSICO", "PSI"),
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
        .categoryName = LANGUAGE_STRING("PSI", "PSY", "PSICO", "PSI"),
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
        .categoryName = LANGUAGE_STRING("PSI", "PSY", "PSICO", "PSI"),
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
        .categoryName = LANGUAGE_STRING("SUPERPOWER", "COLOSSE", "MEGAFORZA", "SUPERPODER"),
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
        .categoryName = LANGUAGE_STRING("SUPERPOWER", "COLOSSE", "MEGAFORZA", "SUPERPODER"),
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
        .categoryName = LANGUAGE_STRING("SUPERPOWER", "COLOSSE", "MEGAFORZA", "SUPERPODER"),
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
        .categoryName = LANGUAGE_STRING("FLOWER", "FLEUR", "FIORE", "FLOR"),
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
        .categoryName = LANGUAGE_STRING("FLYCATCHER", "CARNIVORE", "MOSCHIVORO", "MATAMOSCAS"),
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
        .categoryName = LANGUAGE_STRING("FLYCATCHER", "CARNIVORE", "MOSCHIVORO", "MATAMOSCAS"),
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
        .categoryName = LANGUAGE_STRING("JELLYFISH", "MOLLUSQUE", "MEDUSA", "MEDUSA"),
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
        .categoryName = LANGUAGE_STRING("JELLYFISH", "MOLLUSQUE", "MEDUSA", "MEDUSA"),
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
        .categoryName = LANGUAGE_STRING("ROCK", "ROCHE", "ROCCIA", "ROCA"),
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
        .categoryName = LANGUAGE_STRING("ROCK", "ROCHE", "ROCCIA", "ROCA"),
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
        .categoryName = LANGUAGE_STRING("MEGATON", "TITANESQUE", "MEGATONE", "MEGATÓN"),
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
        .categoryName = LANGUAGE_STRING("FIRE HORSE", "CHEVAL FEU", "CAVALFUOCO", "CABALLO F."),
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
        .categoryName = LANGUAGE_STRING("FIRE HORSE", "CHEVAL FEU", "CAVALFUOCO", "CABALLO F."),
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
        .categoryName = LANGUAGE_STRING("DOPEY", "CRETIN", "RONFONE", "ATONTADO"),
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
        .categoryName = LANGUAGE_STRING("HERMIT CRAB", "SYMBIOSE", "PAGURO", "ERMITAÑO"),
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
        .categoryName = LANGUAGE_STRING("MAGNET", "MAGNETIQUE", "CALAMITA", "IMÁN"),
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
        .categoryName = LANGUAGE_STRING("MAGNET", "MAGNETIQUE", "CALAMITA", "IMÁN"),
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
        .categoryName = LANGUAGE_STRING("WILD DUCK", "CANARD FOU", "SELVANATRA", "PATO SALV."),
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
        .categoryName = LANGUAGE_STRING("TWIN BIRD", "DUOISEAU", "BIUCCELLO", "AVE GEMELA"),
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
        .categoryName = LANGUAGE_STRING("TRIPLE BIRD", "TRIOISEAU", "TRIUCCELLO", "AVE TRIPLE"),
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
        .categoryName = LANGUAGE_STRING("SEA LION", "OTARIE", "OTARIA", "LEÓN MAR."),
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
        .categoryName = LANGUAGE_STRING("SEA LION", "OTARIE", "OTARIA", "LEÓN MAR."),
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
        .categoryName = LANGUAGE_STRING("SLUDGE", "DEGUEU", "MELMA", "LODO"),
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
        .categoryName = LANGUAGE_STRING("SLUDGE", "DEGUEU", "MELMA", "LODO"),
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
        .categoryName = LANGUAGE_STRING("BIVALVE", "BIVALVE", "BIVALVE", "BIVALVO"),
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
        .categoryName = LANGUAGE_STRING("BIVALVE", "BIVALVE", "BIVALVE", "BIVALVO"),
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
        .categoryName = LANGUAGE_STRING("GAS", "GAZ", "GAS", "GAS"),
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
        .categoryName = LANGUAGE_STRING("GAS", "GAZ", "GAS", "GAS"),
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
        .categoryName = LANGUAGE_STRING("SHADOW", "OMBRE", "OMBRA", "SOMBRA"),
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
        .categoryName = LANGUAGE_STRING("ROCK SNAKE", "SERPENROC", "SERPESASSO", "SERP. ROCA"),
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
        .categoryName = LANGUAGE_STRING("HYPNOSIS", "HYPNOSE", "IPNOSI", "HIPNOSIS"),
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
        .categoryName = LANGUAGE_STRING("HYPNOSIS", "HYPNOSE", "IPNOSI", "HIPNOSIS"),
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
        .categoryName = LANGUAGE_STRING("RIVER CRAB", "DOUX CRABE", "GRANCHIO", "CANGREJO"),
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
        .categoryName = LANGUAGE_STRING("PINCER", "PINCE", "CHELA", "TENAZA"),
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
        .categoryName = LANGUAGE_STRING("BALL", "BALLE", "BALL", "BOLA"),
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
        .categoryName = LANGUAGE_STRING("BALL", "BALLE", "BALL", "BOLA"),
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
        .categoryName = LANGUAGE_STRING("EGG", "OEUF", "UOVO", "HUEVO"),
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
        .categoryName = LANGUAGE_STRING("COCONUT", "FRUITPALME", "NOCECOCCO", "COCO"),
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
        .categoryName = LANGUAGE_STRING("LONELY", "SOLITAIRE", "SOLITARIO", "SOLITARIO"),
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
        .categoryName = LANGUAGE_STRING("BONE KEEPER", "GARD'OS", "GUARDAOSSI", "APILAHUESO"),
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
        .categoryName = LANGUAGE_STRING("KICKING", "LATTEUR", "TIRACALCI", "PATADA"),
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
        .categoryName = LANGUAGE_STRING("PUNCHING", "PUNCHEUR", "TIRAPUGNI", "PUÑETAZO"),
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
        .categoryName = LANGUAGE_STRING("LICKING", "LECHEUR", "LINGUACCIA", "LAMETAZO"),
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
        .categoryName = LANGUAGE_STRING("POISON GAS", "GAZ MORTEL", "VELENUVOLA", "GAS VENENO"),
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
        .categoryName = LANGUAGE_STRING("POISON GAS", "GAZ MORTEL", "VELENUVOLA", "GAS VENENO"),
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
        .categoryName = LANGUAGE_STRING("SPIKES", "PIQUANT", "PUNZONI", "CLAVOS"),
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
        .categoryName = LANGUAGE_STRING("DRILL", "PERCEUR", "TRAPANO", "TALADRO"),
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
        .categoryName = LANGUAGE_STRING("EGG", "OEUF", "UOVO", "HUEVO"),
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
        .categoryName = LANGUAGE_STRING("VINE", "VIGNE", "LIANA", "ENREDADERA"),
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
        .categoryName = LANGUAGE_STRING("PARENT", "MATERNEL", "GENITORE", "PADRES"),
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
        .categoryName = LANGUAGE_STRING("DRAGON", "DRAGON", "DRAGO", "DRAGÓN"),
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
        .categoryName = LANGUAGE_STRING("DRAGON", "DRAGON", "DRAGO", "DRAGÓN"),
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
        .categoryName = LANGUAGE_STRING("GOLDFISH", "POISSON", "PESCEROSSO", "PEZ COLOR"),
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
        .categoryName = LANGUAGE_STRING("GOLDFISH", "POISSON", "PESCEROSSO", "PEZ COLOR"),
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
        .categoryName = LANGUAGE_STRING("STAR SHAPE", "ETOILE", "STELLA", "ESTRELLADA"),
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
        .categoryName = LANGUAGE_STRING("MYSTERIOUS", "MYSTERIEUX", "MISTERIOSO", "MISTERIOSO"),
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
        .categoryName = LANGUAGE_STRING("BARRIER", "BLOQUEUR", "BARRIERA", "BARRERA"),
        .height = 13,
        .weight = 545,
        .description = gMrMimePokedexText,
        .pokemonScale = 258,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SCYTHER] =
    {
        .categoryName = LANGUAGE_STRING("MANTIS", "MANTE", "MANTIDE", "MANTIS"),
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
        .categoryName = LANGUAGE_STRING("HUMAN SHAPE", "HUMANOIDE", "UMANOIDE", "F. HUMANA"),
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
        .categoryName = LANGUAGE_STRING("ELECTRIC", "ELECTRIQUE", "ELETTRICO", "ELÉCTRICO"),
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
        .categoryName = LANGUAGE_STRING("SPITFIRE", "CRACHE-FEU", "SPUTAFUOCO", "ESCUPFUEGO"),
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
        .categoryName = LANGUAGE_STRING("STAG BEETLE", "SCARABEE", "CERVOLANTE", "ESCARABAJO"),
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
        .categoryName = LANGUAGE_STRING("WILD BULL", "BUFFLE", "TOROBRADO", "TORO BRAVO"),
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
        .categoryName = LANGUAGE_STRING("FISH", "POISSON", "PESCE", "PEZ"),
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
        .categoryName = LANGUAGE_STRING("ATROCIOUS", "TERRIFIANT", "ATROCE", "ATROCIDAD"),
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
        .categoryName = LANGUAGE_STRING("TRANSPORT", "TRANSPORT", "TRASPORTO", "TRANSPORTE"),
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
        .categoryName = LANGUAGE_STRING("TRANSFORM", "MORPHING", "MUTANTE", "TRANSFORM."),
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
        .categoryName = LANGUAGE_STRING("EVOLUTION", "EVOLUTIF", "EVOLUZIONE", "EVOLUCIÓN"),
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
        .categoryName = LANGUAGE_STRING("BUBBLE JET", "BULLEUR", "BOLLAJET", "BURBUJA"),
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
        .categoryName = LANGUAGE_STRING("LIGHTNING", "ORAGE", "LUMINOSO", "RELÁMPAGO"),
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
        .categoryName = LANGUAGE_STRING("FLAME", "FLAMME", "FIAMMA", "LLAMA"),
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
        .categoryName = LANGUAGE_STRING("VIRTUAL", "VIRTUEL", "VIRTUALE", "VIRTUAL"),
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
        .categoryName = LANGUAGE_STRING("SPIRAL", "SPIRALE", "SPIRALE", "ESPIRAL"),
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
        .categoryName = LANGUAGE_STRING("SPIRAL", "SPIRALE", "SPIRALE", "ESPIRAL"),
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
        .categoryName = LANGUAGE_STRING("SHELLFISH", "CARAPACE", "CROSTACEO", "MARISCO"),
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
        .categoryName = LANGUAGE_STRING("SHELLFISH", "CARAPACE", "CROSTACEO", "MARISCO"),
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
        .categoryName = LANGUAGE_STRING("FOSSIL", "FOSSILE", "FOSSILE", "FÓSIL"),
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
        .categoryName = LANGUAGE_STRING("SLEEPING", "PIONCEUR", "SONNO", "DORMIR"),
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
        .categoryName = LANGUAGE_STRING("FREEZE", "GLACIAIRE", "GELO", "CONGELAR"),
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
        .categoryName = LANGUAGE_STRING("ELECTRIC", "ELECTRIQUE", "ELETTRICO", "ELÉCTRICO"),
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
        .categoryName = LANGUAGE_STRING("FLAME", "FLAMME", "FIAMMA", "LLAMA"),
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
        .categoryName = LANGUAGE_STRING("DRAGON", "DRAGON", "DRAGO", "DRAGÓN"),
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
        .categoryName = LANGUAGE_STRING("DRAGON", "DRAGON", "DRAGO", "DRAGÓN"),
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
        .categoryName = LANGUAGE_STRING("DRAGON", "DRAGON", "DRAGO", "DRAGÓN"),
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
        .categoryName = LANGUAGE_STRING("GENETIC", "GENETIQUE", "GENETICO", "GENÉTICO"),
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
        .categoryName = LANGUAGE_STRING("NEW SPECIES", "NOUVEAU", "NOVASPECIE", "N. ESPECIE"),
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
        .categoryName = LANGUAGE_STRING("LEAF", "FEUILLE", "FOGLIA", "HOJA"),
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
        .categoryName = LANGUAGE_STRING("LEAF", "FEUILLE", "FOGLIA", "HOJA"),
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
        .categoryName = LANGUAGE_STRING("HERB", "HERBE", "ERBE", "HIERBA"),
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
        .categoryName = LANGUAGE_STRING("FIRE MOUSE", "SOURIS FEU", "FUOCOTOPO", "RATÓNFUEGO"),
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
        .categoryName = LANGUAGE_STRING("VOLCANO", "VOLCAN", "VULCANO", "VOLCÁN"),
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
        .categoryName = LANGUAGE_STRING("VOLCANO", "VOLCAN", "VULCANO", "VOLCÁN"),
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
        .categoryName = LANGUAGE_STRING("BIG JAW", "MACHOIRE", "MASCELLONE", "FAUCES"),
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
        .categoryName = LANGUAGE_STRING("BIG JAW", "MACHOIRE", "MASCELLONE", "FAUCES"),
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
        .categoryName = LANGUAGE_STRING("BIG JAW", "MACHOIRE", "MASCELLONE", "FAUCES"),
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
        .categoryName = LANGUAGE_STRING("SCOUT", "ESPION", "ESPLORANTE", "EXPLORADOR"),
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
        .categoryName = LANGUAGE_STRING("LONG BODY", "ALLONGE", "LUNGOCORPO", "ALARGADO"),
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
        .categoryName = LANGUAGE_STRING("OWL", "HIBOU", "GUFO", "BÚHO"),
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
        .categoryName = LANGUAGE_STRING("OWL", "HIBOU", "GUFO", "BÚHO"),
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
        .categoryName = LANGUAGE_STRING("FIVE STAR", "5 ETOILES", "PENTASTRA", "5ESTRELLAS"),
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
        .categoryName = LANGUAGE_STRING("FIVE STAR", "5 ETOILES", "PENTASTRA", "5ESTRELLAS"),
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
        .categoryName = LANGUAGE_STRING("STRING SPIT", "CRACHE FIL", "TELA", "ESCUPESOGA"),
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
        .categoryName = LANGUAGE_STRING("LONG LEG", "LONG-PATTE", "LUNGAZAMPA", "PATA LARGA"),
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
        .categoryName = LANGUAGE_STRING("BAT", "CHOVSOURIS", "PIPISTREL.", "MURCIÉLAGO"),
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
        .categoryName = LANGUAGE_STRING("ANGLER", "POISSON", "PESCATORE", "RAPE"),
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
        .categoryName = LANGUAGE_STRING("LIGHT", "LUMIERE", "LUCE", "LUZ"),
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
        .categoryName = LANGUAGE_STRING("TINY MOUSE", "MINISOURIS", "TOPINO", "RATONCITO"),
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
        .categoryName = LANGUAGE_STRING("STAR SHAPE", "ETOILE", "STELLA", "ESTRELLADA"),
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
        .categoryName = LANGUAGE_STRING("BALLOON", "BOUBOULE", "PALLONE", "GLOBO"),
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
        .categoryName = LANGUAGE_STRING("SPIKE BALL", "BALLE PIC", "PALLAPUNTE", "BOLACLAVOS"),
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
        .categoryName = LANGUAGE_STRING("HAPPINESS", "BONHEUR", "FELICITÀ", "FELICIDAD"),
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
        .categoryName = LANGUAGE_STRING("TINY BIRD", "MINOISEAU", "UCCELLINO", "PAJARITO"),
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
        .categoryName = LANGUAGE_STRING("MYSTIC", "MYSTIQUE", "MAGICO", "MÍSTICO"),
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
        .categoryName = LANGUAGE_STRING("WOOL", "LAINE", "LANA", "LANA"),
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
        .categoryName = LANGUAGE_STRING("WOOL", "LAINE", "LANA", "LANA"),
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
        .categoryName = LANGUAGE_STRING("LIGHT", "LUMIERE", "LUCE", "LUZ"),
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
        .categoryName = LANGUAGE_STRING("FLOWER", "FLEUR", "FIORE", "FLOR"),
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
        .categoryName = LANGUAGE_STRING("AQUA MOUSE", "AQUASOURIS", "ACQUATOPO", "RATÓN AGUA"),
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
        .categoryName = LANGUAGE_STRING("AQUA RABBIT", "AQUALAPIN", "ACQUNIGLIO", "CONEJOAGUA"),
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
        .categoryName = LANGUAGE_STRING("IMITATION", "IMITATION", "IMITAZIONE", "IMITACIÓN"),
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
        .categoryName = LANGUAGE_STRING("FROG", "GRENOUILLE", "RANA", "RANA"),
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
        .categoryName = LANGUAGE_STRING("COTTONWEED", "PISSENLIT", "GRAMIGNA", "ALGADÓN"),
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
        .categoryName = LANGUAGE_STRING("COTTONWEED", "PISSENLIT", "GRAMIGNA", "ALGADÓN"),
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
        .categoryName = LANGUAGE_STRING("COTTONWEED", "PISSENLIT", "GRAMIGNA", "ALGADÓN"),
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
        .categoryName = LANGUAGE_STRING("LONG TAIL", "LONGQUEUE", "LUNGACODA", "COLA LARGA"),
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
        .categoryName = LANGUAGE_STRING("SEED", "GRAINE", "SEME", "SEMILLA"),
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
        .categoryName = LANGUAGE_STRING("SUN", "SOLEIL", "SOLE", "SOL"),
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
        .categoryName = LANGUAGE_STRING("CLEAR WING", "TRANSLAILE", "ALACHIARA", "ALA CLARA"),
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
        .categoryName = LANGUAGE_STRING("WATER FISH", "POISSON", "ACQUAPESCE", "PEZ AGUA"),
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
        .categoryName = LANGUAGE_STRING("WATER FISH", "POISSON", "ACQUAPESCE", "PEZ AGUA"),
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
        .categoryName = LANGUAGE_STRING("SUN", "SOLEIL", "SOLE", "SOL"),
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
        .categoryName = LANGUAGE_STRING("MOONLIGHT", "LUNE", "LUCELUNARE", "LUZ LUNAR"),
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
        .categoryName = LANGUAGE_STRING("DARKNESS", "OBSCURITE", "OSCURITÀ", "OSCURIDAD"),
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
        .categoryName = LANGUAGE_STRING("ROYAL", "ROYAL", "REALE", "REGIO"),
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
        .categoryName = LANGUAGE_STRING("SCREECH", "STRIDENT", "STRIDO", "CHIRRIDO"),
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
        .categoryName = LANGUAGE_STRING("SYMBOL", "SYMBOLIQUE", "SIMBOLO", "SÍMBOLO"),
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
        .categoryName = LANGUAGE_STRING("PATIENT", "PATIENT", "PAZIENZA", "PACIENTE"),
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
        .categoryName = LANGUAGE_STRING("LONG NECK", "LONG-COU", "LUNGOCOLLO", "GRANCUELLO"),
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
        .categoryName = LANGUAGE_STRING("BAGWORM", "VER CACHE", "LARVA", "LARVA"),
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
        .categoryName = LANGUAGE_STRING("BAGWORM", "VER CACHE", "LARVA", "LARVA"),
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
        .categoryName = LANGUAGE_STRING("LAND SNAKE", "SERPENT", "TERRASERPE", "SERPTIERRA"),
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
        .categoryName = LANGUAGE_STRING("FLYSCORPION", "SCORPIVOL", "ALISCORPIO", "ESCORPIALA"),
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
        .categoryName = LANGUAGE_STRING("IRON SNAKE", "SERPENFER", "FERROSERPE", "SERPFÉRREA"),
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
        .categoryName = LANGUAGE_STRING("FAIRY", "FEE", "FATA", "HADA"),
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
        .categoryName = LANGUAGE_STRING("FAIRY", "FEE", "FATA", "HADA"),
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
        .categoryName = LANGUAGE_STRING("BALLOON", "BOUBOULE", "PALLONE", "GLOBO"),
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
        .categoryName = LANGUAGE_STRING("PINCER", "PINCE", "CHELA", "TENAZA"),
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
        .categoryName = LANGUAGE_STRING("MOLD", "POURRI", "MUFFA", "MOHO"),
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
        .categoryName = LANGUAGE_STRING("SINGLE HORN", "UNICORNE", "MONOCORNO", "UNICORNIO"),
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
        .categoryName = LANGUAGE_STRING("SHARP CLAW", "GRIFACEREE", "LAMARTIGLI", "GARRA FILO"),
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
        .categoryName = LANGUAGE_STRING("LITTLE BEAR", "MINI OURS", "ORSETTO", "OSITO"),
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
        .categoryName = LANGUAGE_STRING("HIBERNATOR", "HIBERNANT", "LETARGO", "HIBERNANTE"),
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
        .categoryName = LANGUAGE_STRING("LAVA", "LAVE", "LAVA", "LAVA"),
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
        .categoryName = LANGUAGE_STRING("LAVA", "LAVE", "LAVA", "LAVA"),
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
        .categoryName = LANGUAGE_STRING("PIG", "COCHON", "MAIALE", "CERDO"),
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
        .categoryName = LANGUAGE_STRING("SWINE", "PORC", "SUINO", "PUERCO"),
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
        .categoryName = LANGUAGE_STRING("CORAL", "CORAIL", "CORALLO", "CORAL"),
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
        .categoryName = LANGUAGE_STRING("JET", "JET", "JET", "REACTOR"),
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
        .categoryName = LANGUAGE_STRING("JET", "JET", "JET", "REACTOR"),
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
        .categoryName = LANGUAGE_STRING("DELIVERY", "LIVRAISON", "CONSEGNA", "REPARTO"),
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
        .categoryName = LANGUAGE_STRING("KITE", "CERVOLANT", "AQUILONE", "MILANO"),
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
        .categoryName = LANGUAGE_STRING("ARMOR BIRD", "ARMOISEAU", "ARMUCCELLO", "CORAZA AVE"),
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
        .categoryName = LANGUAGE_STRING("DARK", "SOMBRE", "BUIO", "SINIESTRO"),
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
        .categoryName = LANGUAGE_STRING("DARK", "SOMBRE", "BUIO", "SINIESTRO"),
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
        .categoryName = LANGUAGE_STRING("DRAGON", "DRAGON", "DRAGO", "DRAGÓN"),
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
        .categoryName = LANGUAGE_STRING("LONG NOSE", "LONG-NEZ", "NASONE", "NARIZOTAS"),
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
        .categoryName = LANGUAGE_STRING("ARMOR", "ARMURE", "ARMATURA", "CORAZA"),
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
        .categoryName = LANGUAGE_STRING("VIRTUAL", "VIRTUEL", "VIRTUALE", "VIRTUAL"),
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
        .categoryName = LANGUAGE_STRING("BIG HORN", "MAXI CORNE", "GRANCORNO", "GRANCUERNO"),
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
        .categoryName = LANGUAGE_STRING("PAINTER", "PEINTRE", "PITTORE", "PINTOR"),
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
        .categoryName = LANGUAGE_STRING("SCUFFLE", "BAGARREUR", "BARUFFA", "PELEÓN"),
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
        .categoryName = LANGUAGE_STRING("HANDSTAND", "POIRIER", "VERTICALE", "BOCA ABAJO"),
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
        .categoryName = LANGUAGE_STRING("KISS", "BISOU", "BACIO", "BESO"),
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
        .categoryName = LANGUAGE_STRING("ELECTRIC", "ELECTRIQUE", "ELETTRICO", "ELÉCTRICO"),
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
        .categoryName = LANGUAGE_STRING("LIVE COAL", "CHARBON", "CARBONVIVO", "ASCUAS"),
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
        .categoryName = LANGUAGE_STRING("MILK COW", "VACHALAIT", "BOVINO", "LECHERA"),
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
        .categoryName = LANGUAGE_STRING("HAPPINESS", "BONHEUR", "FELICITÀ", "FELICIDAD"),
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
        .categoryName = LANGUAGE_STRING("THUNDER", "FOUDRE", "TUONO", "TRUENO"),
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
        .categoryName = LANGUAGE_STRING("VOLCANO", "VOLCAN", "VULCANO", "VOLCÁN"),
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
        .categoryName = LANGUAGE_STRING("AURORA", "AURORE", "AURORA", "AURORA"),
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
        .categoryName = LANGUAGE_STRING("ROCK SKIN", "PEAUPIERRE", "PELDISASSO", "PIEL ROCA"),
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
        .categoryName = LANGUAGE_STRING("HARD SHELL", "CARAPADURE", "GUSCIODURO", "CAPARAZÓN"),
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
        .categoryName = LANGUAGE_STRING("ARMOR", "ARMURE", "ARMATURA", "CORAZA"),
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
        .categoryName = LANGUAGE_STRING("DIVING", "PLONGEON", "IMMERSIONE", "BUCEO"),
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
        .categoryName = LANGUAGE_STRING("RAINBOW", "ARCENCIEL", "ARCOBALENO", "ARCO IRIS"),
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
        .categoryName = LANGUAGE_STRING("TIME TRAVEL", "TEMPOREL", "TEMPOVIA", "VIAJETIEMPO"),
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
        .categoryName = LANGUAGE_STRING("WOOD GECKO", "BOIS GECKO", "LEGNOGECO", "GECO BOSQUE"),
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
        .categoryName = LANGUAGE_STRING("WOOD GECKO", "BOIS GECKO", "LEGNOGECO", "GECO BOSQUE"),
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
        .categoryName = LANGUAGE_STRING("FOREST", "FORET", "FORESTA", "MONTE"),
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
        .categoryName = LANGUAGE_STRING("CHICK", "POUSSIN", "PULCINO", "POLLUELO"),
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
        .categoryName = LANGUAGE_STRING("YOUNG FOWL", "POULET", "RAMPOLLO", "AVE CORRAL"),
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
        .categoryName = LANGUAGE_STRING("BLAZE", "ARDENT", "VAMPE", "LLAMEANTE"),
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
        .categoryName = LANGUAGE_STRING("MUD FISH", "POISSONBOUE", "FANGO PESCE", "PEZ LODO"),
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
        .categoryName = LANGUAGE_STRING("MUD FISH", "POISSONBOUE", "FANGO PESCE", "PEZ LODO"),
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
        .categoryName = LANGUAGE_STRING("MUD FISH", "POISSONBOUE", "FANGO PESCE", "PEZ LODO"),
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
        .categoryName = LANGUAGE_STRING("BITE", "MORSURE", "MORSO", "MORDISCO"),
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
        .categoryName = LANGUAGE_STRING("BITE", "MORSURE", "MORSO", "MORDISCO"),
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
        .categoryName = LANGUAGE_STRING("TINYRACCOON", "PETIT RATON", "PROCIONE", "MAPACHITO"),
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
        .categoryName = LANGUAGE_STRING("RUSHING", "FONCEUR", "SFRECCIANTE", "LANZADO"),
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
        .categoryName = LANGUAGE_STRING("WORM", "VER", "BACO", "GUSANO"),
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
        .categoryName = LANGUAGE_STRING("COCOON", "COCON", "BOZZOLO", "CAPULLO"),
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
        .categoryName = LANGUAGE_STRING("BUTTERFLY", "PAPILLON", "FARFALLA", "MARIPOSA"),
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
        .categoryName = LANGUAGE_STRING("COCOON", "COCON", "BOZZOLO", "CAPULLO"),
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
        .categoryName = LANGUAGE_STRING("POISON MOTH", "PAPIPOISON", "VELENTARMA", "POLILLA V."),
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
        .categoryName = LANGUAGE_STRING("WATER WEED", "AQUAPLANTE", "ALGA", "ALGA"),
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
        .categoryName = LANGUAGE_STRING("JOLLY", "JOVIAL", "GIOCOSO", "ALEGRE"),
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
        .categoryName = LANGUAGE_STRING("CAREFREE", "INSOUCIANT", "SPENSIERATO", "OPTIMISTA"),
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
        .categoryName = LANGUAGE_STRING("ACORN", "GLAND", "GHIANDA", "BELLOTA"),
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
        .categoryName = LANGUAGE_STRING("WILY", "MALIN", "SCALTRO", "ASTUTO"),
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
        .categoryName = LANGUAGE_STRING("WICKED", "MALVEILLANT", "BURBERO", "MALVADO"),
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
        .categoryName = LANGUAGE_STRING("TINYSWALLOW", "MINIRONDEL", "RONDINELLA", "PEQUEBUCHE"),
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
        .categoryName = LANGUAGE_STRING("SWALLOW", "HIRONDELLE", "RONDINE", "BUCHE"),
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
        .categoryName = LANGUAGE_STRING("SEAGULL", "MOUETTE", "GABBIANO", "GAVIOTA"),
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
        .categoryName = LANGUAGE_STRING("WATER BIRD", "OISEAUDO", "ALACQUATICO", "AVE AGUA"),
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
        .categoryName = LANGUAGE_STRING("FEELING", "SENTIMENT", "SENSAZIONE", "SENSIBLE"),
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
        .categoryName = LANGUAGE_STRING("EMOTION", "EMOTION", "EMOZIONE", "SENSORIO"),
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
        .categoryName = LANGUAGE_STRING("EMBRACE", "ETREINTE", "ABBRACCIO", "ENVOLVENTE"),
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
        .categoryName = LANGUAGE_STRING("POND SKATER", "MARESURFEUR", "SFIORAPOZZE", "ZAPATERO"),
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
        .categoryName = LANGUAGE_STRING("EYEBALL", "BOULE OEIL", "OCCHI", "GLOBOCULAR"),
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
        .categoryName = LANGUAGE_STRING("MUSHROOM", "CHAMPIGNON", "FUNGO", "HONGO"),
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
        .categoryName = LANGUAGE_STRING("MUSHROOM", "CHAMPIGNON", "FUNGO", "HONGO"),
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
        .categoryName = LANGUAGE_STRING("SLACKER", "FLANEUR", "OZIOSO", "GANDUL"),
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
        .categoryName = LANGUAGE_STRING("WILD MONKEY", "TURBUSINGE", "INDOCILE", "MONO FEROZ"),
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
        .categoryName = LANGUAGE_STRING("LAZY", "FAINEANT", "PIGRIZIA", "HOLGAZÁN"),
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
        .categoryName = LANGUAGE_STRING("TRAINEE", "APPRENTI", "NOVIZIO", "APRENDIZ"),
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
        .categoryName = LANGUAGE_STRING("NINJA", "NINJA", "NINJA", "NINJA"),
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
        .categoryName = LANGUAGE_STRING("SHED", "EXUVIE", "CAMBIAPELLE", "MUDA"),
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
        .categoryName = LANGUAGE_STRING("WHISPER", "CHUCHOTEUR", "SUSSURRO", "SUSURRO"),
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
        .categoryName = LANGUAGE_STRING("BIG VOICE", "GROSSE VOIX", "VOCIONE", "CHILLÓN"),
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
        .categoryName = LANGUAGE_STRING("LOUD NOISE", "BRUIT SOURD", "FRAGORE", "ESCANDALOSO"),
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
        .categoryName = LANGUAGE_STRING("GUTS", "TENACE", "CORAGGIO", "VALIENTE"),
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
        .categoryName = LANGUAGE_STRING("ARM THRUST", "COGNEUR", "SBERLETESE", "EMPUJE"),
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
        .categoryName = LANGUAGE_STRING("POLKA DOT", "POINT POLKA", "POIS", "A TOPOS"),
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
        .categoryName = LANGUAGE_STRING("COMPASS", "BOUSSOLE", "BUSSOLA", "BRÚJULA"),
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
        .categoryName = LANGUAGE_STRING("KITTEN", "CHATON", "MICIO", "GATITO"),
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
        .categoryName = LANGUAGE_STRING("PRIM", "GUINDE", "FINEZZA", "CURSI"),
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
        .categoryName = LANGUAGE_STRING("DARKNESS", "OBSCURITE", "OSCURITÀ", "OSCURIDAD"),
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
        .categoryName = LANGUAGE_STRING("DECEIVER", "TROMPEUR", "INGANNO", "TRAMPOSO"),
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
        .categoryName = LANGUAGE_STRING("IRON ARMOR", "ARMURFER", "CORAZZA", "COR. FÉRREA"),
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
        .categoryName = LANGUAGE_STRING("IRON ARMOR", "ARMURFER", "CORAZZA", "COR. FÉRREA"),
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
        .categoryName = LANGUAGE_STRING("IRON ARMOR", "ARMURFER", "CORAZZA", "COR. FÉRREA"),
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
        .categoryName = LANGUAGE_STRING("MEDITATE", "MEDITATION", "MEDITAZIONE", "MEDITADOR"),
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
        .categoryName = LANGUAGE_STRING("MEDITATE", "MEDITATION", "MEDITAZIONE", "MEDITADOR"),
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
        .categoryName = LANGUAGE_STRING("LIGHTNING", "ORAGE", "LAMPO", "CALAMBRE"),
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
        .categoryName = LANGUAGE_STRING("DISCHARGE", "DECHARGE", "SCOSSA", "DESCARGA"),
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
        .categoryName = LANGUAGE_STRING("CHEERING", "ACCLAMEUR", "INCITAMENTO", "ÁNIMO"),
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
        .categoryName = LANGUAGE_STRING("CHEERING", "ACCLAMEUR", "INCITAMENTO", "ÁNIMO"),
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
        .categoryName = LANGUAGE_STRING("FIREFLY", "LUCIOLE", "LUCCIOLA", "LUCIÉRNAGA"),
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
        .categoryName = LANGUAGE_STRING("FIREFLY", "LUCIOLE", "LUCCIOLA", "LUCIÉRNAGA"),
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
        .categoryName = LANGUAGE_STRING("THORN", "EPINE", "SPINA", "ESPINA"),
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
        .categoryName = LANGUAGE_STRING("STOMACH", "ESTOMAC", "STOMACO", "ESTÓMAGO"),
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
        .categoryName = LANGUAGE_STRING("POISON BAG", "SAC POISON", "VELENOSACCO", "BOLSA VEN."),
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
        .categoryName = LANGUAGE_STRING("SAVAGE", "FEROCE", "FEROCE", "FEROZ"),
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
        .categoryName = LANGUAGE_STRING("BRUTAL", "BRUTAL", "BRUTALE", "VORAZ"),
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
        .categoryName = LANGUAGE_STRING("BALL WHALE", "BALEINBOULE", "BALENOTTERO", "BALLENABOLA"),
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
        .categoryName = LANGUAGE_STRING("FLOAT WHALE", "CACHABOUEE", "MEGABALENA", "BALLENAFLOT"),
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
        .categoryName = LANGUAGE_STRING("NUMB", "ENGOURDI", "TORPORE", "TORPE"),
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
        .categoryName = LANGUAGE_STRING("ERUPTION", "ERUPTION", "ERUZIONE", "ERUPCIÓN"),
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
        .categoryName = LANGUAGE_STRING("COAL", "CHARBON", "CARBONE", "CARBÓN"),
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
        .categoryName = LANGUAGE_STRING("BOUNCE", "REBOND", "MOLLA", "SALTARÍN"),
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
        .categoryName = LANGUAGE_STRING("MANIPULATE", "MAGOUILLEUR", "RAGGIRO", "MANIPULADOR"),
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
        .categoryName = LANGUAGE_STRING("SPOT PANDA", "PANDA TACHE", "MACCHIPANDA", "PANDA TOPOS"),
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
        .categoryName = LANGUAGE_STRING("ANT PIT", "PIEGEUR", "TRAPPOLA", "HORMIGALEÓN"),
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
        .categoryName = LANGUAGE_STRING("VIBRATION", "VIBRATION", "VIBRAZIONE", "VIBRANTE"),
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
        .categoryName = LANGUAGE_STRING("MYSTIC", "MYSTIQUE", "MAGICO", "MÍSTICO"),
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
        .categoryName = LANGUAGE_STRING("CACTUS", "CACTUS", "CACTUS", "CACTUS"),
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
        .categoryName = LANGUAGE_STRING("SCARECROW", "EPOUVANTAIL", "SPAVENTO", "ESPANTAJO"),
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
        .categoryName = LANGUAGE_STRING("COTTON BIRD", "OISEAUCOTON", "ALIDICOTONE", "AVE ALGODÓN"),
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
        .categoryName = LANGUAGE_STRING("HUMMING", "VIREVOLTEUR", "CANTERINO", "CANTOR"),
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
        .categoryName = LANGUAGE_STRING("CAT FERRET", "CHAT FURET", "FUROGATTO", "GATO HURÓN"),
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
        .categoryName = LANGUAGE_STRING("FANG SNAKE", "SERPACROC", "ZANNASERPE", "COLMILLOS"),
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
        .categoryName = LANGUAGE_STRING("METEORITE", "METEORITE", "METEORITE", "METEORITO"),
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
        .categoryName = LANGUAGE_STRING("METEORITE", "METEORITE", "METEORITE", "METEORITO"),
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
        .categoryName = LANGUAGE_STRING("WHISKERS", "BARBILLON", "BAFFETTI", "BIGOTUDO"),
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
        .categoryName = LANGUAGE_STRING("WHISKERS", "BARBILLON", "BAFFETTI", "BIGOTUDO"),
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
        .categoryName = LANGUAGE_STRING("RUFFIAN", "BRUTE", "BIRBONE", "RUFIÁN"),
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
        .categoryName = LANGUAGE_STRING("ROGUE", "CRAPULE", "CANAGLIA", "GRANUJA"),
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
        .categoryName = LANGUAGE_STRING("CLAY DOLL", "POUPARGILE", "ARGILLA", "MUÑ. BARRO"),
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
        .categoryName = LANGUAGE_STRING("CLAY DOLL", "POUPARGILE", "ARGILLA", "MUÑ. BARRO"),
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
        .categoryName = LANGUAGE_STRING("SEA LILY", "LIS D'EAU", "FIORDIMARE", "LILA MAR"),
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
        .categoryName = LANGUAGE_STRING("BARNACLE", "BERNACLE", "LEPADE", "PERCEBE"),
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
        .categoryName = LANGUAGE_STRING("OLD SHRIMP", "CRUSTAGE", "PRIMACEO", "CAMARÓN"),
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
        .categoryName = LANGUAGE_STRING("PLATE", "BLINDAGE", "PIASTRE", "ARMADURA"),
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
        .categoryName = LANGUAGE_STRING("FISH", "POISSON", "PESCE", "PEZ"),
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
        .categoryName = LANGUAGE_STRING("TENDER", "TENDRE", "TENEREZZA", "TIERNO"),
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
        .categoryName = LANGUAGE_STRING("WEATHER", "CLIMAT", "METEO", "CLIMA"),
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
        .categoryName = LANGUAGE_STRING("COLOR SWAP", "MULTICOLOR", "MUTACOLORE", "CAMALEÓNICO"),
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
        .categoryName = LANGUAGE_STRING("PUPPET", "POUPEE", "PUPAZZO", "TÍTERE"),
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
        .categoryName = LANGUAGE_STRING("MARIONETTE", "MARIONETTE", "MARIONETTA", "MARIONETA"),
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
        .categoryName = LANGUAGE_STRING("REQUIEM", "REQUIEM", "REQUIEM", "RÉQUIEM"),
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
        .categoryName = LANGUAGE_STRING("BECKON", "APPEL", "IPNOSGUARDO", "ATRAYENTE"),
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
        .categoryName = LANGUAGE_STRING("FRUIT", "FRUIT", "FRUTTO", "FRUTO"),
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
        .categoryName = LANGUAGE_STRING("WIND CHIME", "CARILLON", "VENCAMPANA", "SONIDO AIRE"),
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
        .categoryName = LANGUAGE_STRING("DISASTER", "DESASTRE", "CATASTROFE", "CATÁSTROFE"),
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
        .categoryName = LANGUAGE_STRING("BRIGHT", "RAVI", "BRILLANTE", "RADIANTE"),
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
        .categoryName = LANGUAGE_STRING("SNOW HAT", "CAPUCHE", "CAPPELNEVE", "GORRO NIEVE"),
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
        .categoryName = LANGUAGE_STRING("FACE", "FACE", "TUTTOMUSO", "CARA"),
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
        .categoryName = LANGUAGE_STRING("CLAP", "CLAP CLAP", "ROTOLANTE", "APLAUSO"),
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
        .categoryName = LANGUAGE_STRING("BALL ROLL", "ROULE BOULE", "ROTAPALLA", "RODABOLA"),
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
        .categoryName = LANGUAGE_STRING("ICE BREAK", "BRISE GLACE", "SPACCAGELO", "ROMPEHIELO"),
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
        .categoryName = LANGUAGE_STRING("BIVALVE", "BIVALVE", "BIVALVE", "BIVALVO"),
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
        .categoryName = LANGUAGE_STRING("DEEP SEA", "ABYSSE", "ABISSI", "ABISAL"),
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
        .categoryName = LANGUAGE_STRING("SOUTH SEA", "MER DU SUD", "SUDMARINO", "MAR DEL SUR"),
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
        .categoryName = LANGUAGE_STRING("LONGEVITY", "LONGEVITE", "LONGEVITÀ", "LONGEVO"),
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
        .categoryName = LANGUAGE_STRING("RENDEZVOUS", "RENDEZVOUS", "RENDEZVOUS", "CITA"),
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
        .categoryName = LANGUAGE_STRING("ROCK HEAD", "TETE DE ROC", "ROCCIOTESTA", "CABEZA ROCA"),
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
        .categoryName = LANGUAGE_STRING("ENDURANCE", "ENDURANT", "RESISTENZA", "RESISTENCIA"),
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
        .categoryName = LANGUAGE_STRING("DRAGON", "DRAGON", "DRAGO", "DRAGÓN"),
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
        .categoryName = LANGUAGE_STRING("IRON BALL", "BOULEFER", "FERROSFERA", "BOLA HIERRO"),
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
        .categoryName = LANGUAGE_STRING("IRON CLAW", "PINCEFER", "FERRUNGHIA", "GARRAHIERRO"),
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
        .categoryName = LANGUAGE_STRING("IRON LEG", "PATTEFER", "FERRARTO", "PATA HIERRO"),
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
        .categoryName = LANGUAGE_STRING("ROCK PEAK", "PIC ROCHEUX", "PICCO", "PICO ROCA"),
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
        .categoryName = LANGUAGE_STRING("ICEBERG", "ICEBERG", "ICEBERG", "ICEBERG"),
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
        .categoryName = LANGUAGE_STRING("IRON", "FER", "FERRO", "HIERRO"),
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
        .categoryName = LANGUAGE_STRING("EON", "EON", "EONE", "EÓN"),
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
        .categoryName = LANGUAGE_STRING("EON", "EON", "EONE", "EÓN"),
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
        .categoryName = LANGUAGE_STRING("SEA BASIN", "BASSINMARIN", "OCEANO", "CUENCA MAR"),
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
        .categoryName = LANGUAGE_STRING("CONTINENT", "CONTINENT", "CONTINENTE", "CONTINENTE"),
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
        .categoryName = LANGUAGE_STRING("SKY HIGH", "CIEUX", "STRATOSFERA", "CIELO"),
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
        .categoryName = LANGUAGE_STRING("WISH", "SOUHAIT", "DESIDERIO", "DESEO"),
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
        .categoryName = LANGUAGE_STRING("DNA", "ADN", "DNA", "ADN"),
        .height = 17,
        .weight = 608,
        .description = gDeoxysPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
    },
};

