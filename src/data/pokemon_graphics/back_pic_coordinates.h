// All Pokémon pics are 64x64, but this data table defines where in this 64x64 frame
// the sprite's non-transparent pixels actually are.
// .size is the dimensions of this drawn pixel area.
// .y_offset is the number of pixels between the drawn pixel area and the bottom edge.
const struct MonCoords gMonBackPicCoords[] =
{
    [SPECIES_NONE] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 12,
    },
    [SPECIES_BULBASAUR] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_IVYSAUR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_VENUSAUR] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_CHARMANDER] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_CHARMELEON] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_CHARIZARD] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_SQUIRTLE] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_WARTORTLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_BLASTOISE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_CATERPIE] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 12,
    },
    [SPECIES_METAPOD] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 8,
    },
    [SPECIES_BUTTERFREE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_WEEDLE] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_KAKUNA] =
    {
        .size = MON_COORDS_SIZE(32, 40),
        .y_offset = 12,
    },
    [SPECIES_BEEDRILL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_PIDGEY] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_PIDGEOTTO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_PIDGEOT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_RATTATA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_RATICATE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_SPEAROW] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_FEAROW] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_EKANS] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_ARBOK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_PIKACHU] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_RAICHU] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SANDSHREW] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_SANDSLASH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_NIDORAN_F] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_NIDORINA] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_NIDOQUEEN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_NIDORAN_M] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_NIDORINO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_NIDOKING] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_CLEFAIRY] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_CLEFABLE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_VULPIX] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_NINETALES] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_JIGGLYPUFF] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 12,
    },
    [SPECIES_WIGGLYTUFF] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_ZUBAT] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_GOLBAT] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_ODDISH] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_GLOOM] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_VILEPLUME] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_PARAS] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 18,
    },
    [SPECIES_PARASECT] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_VENONAT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_VENOMOTH] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_DIGLETT] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 14,
    },
    [SPECIES_DUGTRIO] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 17,
    },
    [SPECIES_MEOWTH] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_PERSIAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_PSYDUCK] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_GOLDUCK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_MANKEY] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_PRIMEAPE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_GROWLITHE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_ARCANINE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_POLIWAG] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 18,
    },
    [SPECIES_POLIWHIRL] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_POLIWRATH] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_ABRA] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 12,
    },
    [SPECIES_KADABRA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_ALAKAZAM] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_MACHOP] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_MACHOKE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_MACHAMP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_BELLSPROUT] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 11,
    },
    [SPECIES_WEEPINBELL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_VICTREEBEL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_TENTACOOL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_TENTACRUEL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_GEODUDE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_GRAVELER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_GOLEM] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_PONYTA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_RAPIDASH] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SLOWPOKE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_SLOWBRO] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_MAGNEMITE] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 15,
    },
    [SPECIES_MAGNETON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_FARFETCHD] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_DODUO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_DODRIO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_SEEL] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_DEWGONG] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_GRIMER] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_MUK] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_SHELLDER] =
    {
        .size = MON_COORDS_SIZE(48, 24),
        .y_offset = 21,
    },
    [SPECIES_CLOYSTER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_GASTLY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_HAUNTER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_GENGAR] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_ONIX] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_DROWZEE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_HYPNO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_KRABBY] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_KINGLER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_VOLTORB] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 14,
    },
    [SPECIES_ELECTRODE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_EXEGGCUTE] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 18,
    },
    [SPECIES_EXEGGUTOR] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_CUBONE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_MAROWAK] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_HITMONLEE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_HITMONCHAN] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_LICKITUNG] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_KOFFING] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_WEEZING] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_RHYHORN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_RHYDON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_CHANSEY] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_TANGELA] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_KANGASKHAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_HORSEA] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 14,
    },
    [SPECIES_SEADRA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_GOLDEEN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_SEAKING] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_STARYU] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_STARMIE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_MR_MIME] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_SCYTHER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_JYNX] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_ELECTABUZZ] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_MAGMAR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_PINSIR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_TAUROS] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 13,
    },
    [SPECIES_MAGIKARP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_GYARADOS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_LAPRAS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_DITTO] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 17,
    },
    [SPECIES_EEVEE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_VAPOREON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_JOLTEON] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_FLAREON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_PORYGON] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_OMANYTE] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 12,
    },
    [SPECIES_OMASTAR] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_KABUTO] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_KABUTOPS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_AERODACTYL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_SNORLAX] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_ARTICUNO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_ZAPDOS] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_MOLTRES] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_DRATINI] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_DRAGONAIR] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 4,
    },
    [SPECIES_DRAGONITE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_MEWTWO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_MEW] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_CHIKORITA] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_BAYLEEF] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_MEGANIUM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_CYNDAQUIL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_QUILAVA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_TYPHLOSION] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_TOTODILE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_CROCONAW] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_FERALIGATR] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_SENTRET] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    [SPECIES_FURRET] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_HOOTHOOT] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 4,
    },
    [SPECIES_NOCTOWL] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 3,
    },
    [SPECIES_LEDYBA] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_LEDIAN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_SPINARAK] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_ARIADOS] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_CROBAT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_CHINCHOU] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_LANTURN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_PICHU] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_CLEFFA] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_IGGLYBUFF] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 13,
    },
    [SPECIES_TOGEPI] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 12,
    },
    [SPECIES_TOGETIC] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_NATU] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 15,
    },
    [SPECIES_XATU] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_MAREEP] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_FLAAFFY] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_AMPHAROS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_BELLOSSOM] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 11,
    },
    [SPECIES_MARILL] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_AZUMARILL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_SUDOWOODO] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 5,
    },
    [SPECIES_POLITOED] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_HOPPIP] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_SKIPLOOM] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_JUMPLUFF] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_AIPOM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_SUNKERN] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_SUNFLORA] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_YANMA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_WOOPER] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_QUAGSIRE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_ESPEON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_UMBREON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_MURKROW] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 10,
    },
    [SPECIES_SLOWKING] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_MISDREAVUS] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_UNOWN] =
    {
        .size = MON_COORDS_SIZE(24, 48),
        .y_offset = 8,
    },
    [SPECIES_WOBBUFFET] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 10,
    },
    [SPECIES_GIRAFARIG] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_PINECO] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_FORRETRESS] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_DUNSPARCE] =
    {
        .size = MON_COORDS_SIZE(56, 32),
        .y_offset = 17,
    },
    [SPECIES_GLIGAR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_STEELIX] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_SNUBBULL] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_GRANBULL] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_QWILFISH] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_SCIZOR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_SHUCKLE] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 11,
    },
    [SPECIES_HERACROSS] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 2,
    },
    [SPECIES_SNEASEL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_TEDDIURSA] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_URSARING] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_SLUGMA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_MAGCARGO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_SWINUB] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_PILOSWINE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_CORSOLA] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_REMORAID] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_OCTILLERY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_DELIBIRD] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_MANTINE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_SKARMORY] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 1,
    },
    [SPECIES_HOUNDOUR] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 10,
    },
    [SPECIES_HOUNDOOM] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_KINGDRA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_PHANPY] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_DONPHAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_PORYGON2] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_STANTLER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_SMEARGLE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_TYROGUE] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_HITMONTOP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SMOOCHUM] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 9,
    },
    [SPECIES_ELEKID] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_MAGBY] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 10,
    },
    [SPECIES_MILTANK] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_BLISSEY] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_RAIKOU] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_ENTEI] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_SUICUNE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_LARVITAR] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 8,
    },
    [SPECIES_PUPITAR] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_TYRANITAR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_LUGIA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_HO_OH] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_CELEBI] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_TREECKO] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_GROVYLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_SCEPTILE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_TORCHIC] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 10,
    },
    [SPECIES_COMBUSKEN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_BLAZIKEN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_MUDKIP] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_MARSHTOMP] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_SWAMPERT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_POOCHYENA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_MIGHTYENA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ZIGZAGOON] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_LINOONE] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_WURMPLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SILCOON] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_BEAUTIFLY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_CASCOON] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_DUSTOX] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_LOTAD] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_LOMBRE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_LUDICOLO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SEEDOT] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_NUZLEAF] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_SHIFTRY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_NINCADA] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 18,
    },
    [SPECIES_NINJASK] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_SHEDINJA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_TAILLOW] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_SWELLOW] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_SHROOMISH] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_BRELOOM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_SPINDA] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 4,
    },
    [SPECIES_WINGULL] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_PELIPPER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SURSKIT] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_MASQUERAIN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_WAILMER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_WAILORD] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 14,
    },
    [SPECIES_SKITTY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_DELCATTY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_KECLEON] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_BALTOY] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_CLAYDOL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_NOSEPASS] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_TORKOAL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_SABLEYE] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 13,
    },
    [SPECIES_BARBOACH] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_WHISCASH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_LUVDISC] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 10,
    },
    [SPECIES_CORPHISH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_CRAWDAUNT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_FEEBAS] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_MILOTIC] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_CARVANHA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_SHARPEDO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_TRAPINCH] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_VIBRAVA] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_FLYGON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_MAKUHITA] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 8,
    },
    [SPECIES_HARIYAMA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_ELECTRIKE] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_MANECTRIC] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_NUMEL] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_CAMERUPT] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_SPHEAL] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 15,
    },
    [SPECIES_SEALEO] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_WALREIN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_CACNEA] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_CACTURNE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SNORUNT] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_GLALIE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_LUNATONE] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 8,
    },
    [SPECIES_SOLROCK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_AZURILL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SPOINK] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 4,
    },
    [SPECIES_GRUMPIG] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_PLUSLE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_MINUN] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 4,
    },
    [SPECIES_MAWILE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_MEDITITE] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_MEDICHAM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SWABLU] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_ALTARIA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_WYNAUT] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 11,
    },
    [SPECIES_DUSKULL] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 8,
    },
    [SPECIES_DUSCLOPS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_ROSELIA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_SLAKOTH] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_VIGOROTH] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SLAKING] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_GULPIN] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_SWALOT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_TROPIUS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_WHISMUR] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_LOUDRED] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_EXPLOUD] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_CLAMPERL] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_HUNTAIL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_GOREBYSS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_ABSOL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_SHUPPET] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_BANETTE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_SEVIPER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_ZANGOOSE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_RELICANTH] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_ARON] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 12,
    },
    [SPECIES_LAIRON] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 15,
    },
    [SPECIES_AGGRON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_CASTFORM] =
    {
        .size = MON_COORDS_SIZE(32, 64),
        .y_offset = 0,
    },
    [SPECIES_VOLBEAT] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 3,
    },
    [SPECIES_ILLUMISE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_LILEEP] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 8,
    },
    [SPECIES_CRADILY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_ANORITH] =
    {
        .size = MON_COORDS_SIZE(56, 32),
        .y_offset = 19,
    },
    [SPECIES_ARMALDO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_RALTS] =
    {
        .size = MON_COORDS_SIZE(32, 40),
        .y_offset = 13,
    },
    [SPECIES_KIRLIA] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_GARDEVOIR] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_BAGON] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_SHELGON] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_SALAMENCE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 4,
    },
    [SPECIES_BELDUM] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_METANG] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_METAGROSS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_REGIROCK] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 10,
    },
    [SPECIES_REGICE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_REGISTEEL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_KYOGRE] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 18,
    },
    [SPECIES_GROUDON] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_RAYQUAZA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_LATIAS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_LATIOS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_JIRACHI] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_DEOXYS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_CHIMECHO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_TURTWIG] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_GROTLE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_TORTERRA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_CHIMCHAR] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_MONFERNO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_INFERNAPE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_PIPLUP] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 10,
    },
    [SPECIES_PRINPLUP] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_EMPOLEON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_STARLY] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_STARAVIA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_STARAPTOR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_BIDOOF] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_BIBAREL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_KRICKETOT] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_KRICKETUNE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_SHINX] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_LUXIO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_LUXRAY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_BUDEW] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 11,
    },
    [SPECIES_ROSERADE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_CRANIDOS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_RAMPARDOS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_SHIELDON] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_BASTIODON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_BURMY] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 6,
    },
    [SPECIES_WORMADAM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_MOTHIM] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_COMBEE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 22,
    },
    [SPECIES_VESPIQUEN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_PACHIRISU] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_BUIZEL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_FLOATZEL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_CHERUBI] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_CHERRIM] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 9,
    },
    [SPECIES_SHELLOS] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 8,
    },
    [SPECIES_GASTRODON] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_AMBIPOM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_DRIFLOON] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 0,
    },
    [SPECIES_DRIFBLIM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_BUNEARY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_LOPUNNY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_MISMAGIUS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_HONCHKROW] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_GLAMEOW] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_PURUGLY] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_CHINGLING] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 13,
    },
    [SPECIES_STUNKY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_SKUNTANK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_BRONZOR] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 9,
    },
    [SPECIES_BRONZONG] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_BONSLY] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 6,
    },
    [SPECIES_MIME_JR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_HAPPINY] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_CHATOT] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_SPIRITOMB] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_GIBLE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_GABITE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_GARCHOMP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_MUNCHLAX] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_RIOLU] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 8,
    },
    [SPECIES_LUCARIO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_HIPPOPOTAS] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 14,
    },
    [SPECIES_HIPPOWDON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SKORUPI] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_DRAPION] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_CROAGUNK] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_TOXICROAK] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_CARNIVINE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_FINNEON] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_LUMINEON] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_MANTYKE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SNOVER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_ABOMASNOW] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_WEAVILE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_MAGNEZONE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_LICKILICKY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_RHYPERIOR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_TANGROWTH] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_ELECTIVIRE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_MAGMORTAR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_TOGEKISS] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_YANMEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_LEAFEON] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    [SPECIES_GLACEON] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 6,
    },
    [SPECIES_GLISCOR] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_MAMOSWINE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_PORYGON_Z] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_GALLADE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_PROBOPASS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_DUSKNOIR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_FROSLASS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ROTOM] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_UXIE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_MESPRIT] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_AZELF] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_DIALGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_PALKIA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_HEATRAN] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_REGIGIGAS] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_GIRATINA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_CRESSELIA] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_PHIONE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_MANAPHY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 10,
    },
    [SPECIES_DARKRAI] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SHAYMIN] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_ARCEUS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_VICTINI] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 7,
    },
    [SPECIES_SNIVY] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_SERVINE] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 5,
    },
    [SPECIES_SERPERIOR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_TEPIG] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_PIGNITE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 9,
    },
    [SPECIES_EMBOAR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_OSHAWOTT] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 14,
    },
    [SPECIES_DEWOTT] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 5,
    },
    [SPECIES_SAMUROTT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_PATRAT] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_WATCHOG] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_LILLIPUP] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 12,
    },
    [SPECIES_HERDIER] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 10,
    },
    [SPECIES_STOUTLAND] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_PURRLOIN] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_LIEPARD] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_PANSAGE] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_SIMISAGE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 6,
    },
    [SPECIES_PANSEAR] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 10,
    },
    [SPECIES_SIMISEAR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_PANPOUR] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 9,
    },
    [SPECIES_SIMIPOUR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_MUNNA] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 16,
    },
    [SPECIES_MUSHARNA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 8,
    },
    [SPECIES_PIDOVE] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_TRANQUILL] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_UNFEZANT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_BLITZLE] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_ZEBSTRIKA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_ROGGENROLA] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 13,
    },
    [SPECIES_BOLDORE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 16,
    },
    [SPECIES_GIGALITH] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_WOOBAT] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_SWOOBAT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_DRILBUR] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_EXCADRILL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 11,
    },
    [SPECIES_AUDINO] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 9,
    },
    [SPECIES_TIMBURR] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 15,
    },
    [SPECIES_GURDURR] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_CONKELDURR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 13,
    },
    [SPECIES_TYMPOLE] =
    {
        .size = MON_COORDS_SIZE(40, 32),
        .y_offset = 17,
    },
    [SPECIES_PALPITOAD] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_SEISMITOAD] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_THROH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_SAWK] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_SEWADDLE] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 13,
    },
    [SPECIES_SWADLOON] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_LEAVANNY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_VENIPEDE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 14,
    },
    [SPECIES_WHIRLIPEDE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 15,
    },
    [SPECIES_SCOLIPEDE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_COTTONEE] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 18,
    },
    [SPECIES_WHIMSICOTT] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_PETILIL] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 9,
    },
    [SPECIES_LILLIGANT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_BASCULIN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 16,
    },
    [SPECIES_SANDILE] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 18,
    },
    [SPECIES_KROKOROK] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_KROOKODILE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_DARUMAKA] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 12,
    },
    [SPECIES_DARMANITAN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_MARACTUS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_DWEBBLE] =
    {
        .size = MON_COORDS_SIZE(56, 32),
        .y_offset = 17,
    },
    [SPECIES_CRUSTLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_SCRAGGY] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_SCRAFTY] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 5,
    },
    [SPECIES_SIGILYPH] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_YAMASK] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 14,
    },
    [SPECIES_COFAGRIGUS] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_TIRTOUGA] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_CARRACOSTA] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_ARCHEN] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_ARCHEOPS] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_TRUBBISH] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 13,
    },
    [SPECIES_GARBODOR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_ZORUA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_ZOROARK] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 10,
    },
    [SPECIES_MINCCINO] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_CINCCINO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_GOTHITA] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_GOTHORITA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_GOTHITELLE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SOLOSIS] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 19,
    },
    [SPECIES_DUOSION] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 13,
    },
    [SPECIES_REUNICLUS] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 13,
    },
    [SPECIES_DUCKLETT] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_SWANNA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_VANILLITE] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 9,
    },
    [SPECIES_VANILLISH] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 4,
    },
    [SPECIES_VANILLUXE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_DEERLING] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_SAWSBUCK] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 5,
    },
    [SPECIES_EMOLGA] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 16,
    },
    [SPECIES_KARRABLAST] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 14,
    },
    [SPECIES_ESCAVALIER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_FOONGUS] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_AMOONGUSS] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 12,
    },
    [SPECIES_FRILLISH] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 7,
    },
    [SPECIES_JELLICENT] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_ALOMOMOLA] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    [SPECIES_JOLTIK] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 19,
    },
    [SPECIES_GALVANTULA] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 18,
    },
    [SPECIES_FERROSEED] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 15,
    },
    [SPECIES_FERROTHORN] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 14,
    },
    [SPECIES_KLINK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 17,
    },
    [SPECIES_KLANG] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_KLINKLANG] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_TYNAMO] =
    {
        .size = MON_COORDS_SIZE(64, 24),
        .y_offset = 21,
    },
    [SPECIES_EELEKTRIK] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 4,
    },
    [SPECIES_EELEKTROSS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_ELGYEM] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 10,
    },
    [SPECIES_BEHEEYEM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_LITWICK] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 14,
    },
    [SPECIES_LAMPENT] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 12,
    },
    [SPECIES_CHANDELURE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_AXEW] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_FRAXURE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 13,
    },
    [SPECIES_HAXORUS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_CUBCHOO] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 12,
    },
    [SPECIES_BEARTIC] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_CRYOGONAL] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 4,
    },
    [SPECIES_SHELMET] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 19,
    },
    [SPECIES_ACCELGOR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_STUNFISK] =
    {
        .size = MON_COORDS_SIZE(64, 24),
        .y_offset = 22,
    },
    [SPECIES_MIENFOO] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_MIENSHAO] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_DRUDDIGON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_GOLETT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_GOLURK] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_PAWNIARD] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_BISHARP] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_BOUFFALANT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_RUFFLET] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_BRAVIARY] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_VULLABY] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 14,
    },
    [SPECIES_MANDIBUZZ] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_HEATMOR] =
    {
        .size = MON_COORDS_SIZE(64, 24),
        .y_offset = 21,
    },
    [SPECIES_DURANT] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 17,
    },
    [SPECIES_DEINO] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 14,
    },
    [SPECIES_ZWEILOUS] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_HYDREIGON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 11,
    },
    [SPECIES_LARVESTA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 12,
    },
    [SPECIES_VOLCARONA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_COBALION] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 6,
    },
    [SPECIES_TERRAKION] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_VIRIZION] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_TORNADUS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_THUNDURUS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_RESHIRAM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_ZEKROM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_LANDORUS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_KYUREM] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_KELDEO] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 4,
    },
    [SPECIES_MELOETTA] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_GENESECT] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_CHESPIN] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 6,
    },
    [SPECIES_QUILLADIN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_CHESNAUGHT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 10,
    },
    [SPECIES_FENNEKIN] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_BRAIXEN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 10,
    },
    [SPECIES_DELPHOX] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_FROAKIE] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_FROGADIER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_GRENINJA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_BUNNELBY] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    [SPECIES_DIGGERSBY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_FLETCHLING] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 14,
    },
    [SPECIES_FLETCHINDER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_TALONFLAME] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_SCATTERBUG] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 12,
    },
    [SPECIES_SPEWPA] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 12,
    },
    [SPECIES_VIVILLON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_LITLEO] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_PYROAR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_FLABEBE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_FLOETTE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_FLORGES] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_SKIDDO] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_GOGOAT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_PANCHAM] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_PANGORO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_FURFROU] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_ESPURR] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_MEOWSTIC] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 9,
    },
    [SPECIES_HONEDGE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 4,
    },
    [SPECIES_DOUBLADE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_AEGISLASH] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 9,
    },
    [SPECIES_SPRITZEE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_AROMATISSE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_SWIRLIX] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_SLURPUFF] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_INKAY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 9,
    },
    [SPECIES_MALAMAR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_BINACLE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_BARBARACLE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SKRELP] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_DRAGALGE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_CLAUNCHER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_CLAWITZER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_HELIOPTILE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_HELIOLISK] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_TYRUNT] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_TYRANTRUM] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 11,
    },
    [SPECIES_AMAURA] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 3,
    },
    [SPECIES_AURORUS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SYLVEON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_HAWLUCHA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_DEDENNE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 12,
    },
    [SPECIES_CARBINK] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_GOOMY] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_SLIGGOO] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    [SPECIES_GOODRA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_KLEFKI] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 8,
    },
    [SPECIES_PHANTUMP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_TREVENANT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_PUMPKABOO] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 13,
    },
    [SPECIES_GOURGEIST] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 3,
    },
    [SPECIES_BERGMITE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 13,
    },
    [SPECIES_AVALUGG] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_NOIBAT] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 7,
    },
    [SPECIES_NOIVERN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_XERNEAS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_YVELTAL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_ZYGARDE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_DIANCIE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_HOOPA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_VOLCANION] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ROWLET] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 15,
    },
    [SPECIES_DARTRIX] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 4,
    },
    [SPECIES_DECIDUEYE] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    [SPECIES_LITTEN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_TORRACAT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_INCINEROAR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_POPPLIO] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 11,
    },
    [SPECIES_BRIONNE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_PRIMARINA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_PIKIPEK] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 8,
    },
    [SPECIES_TRUMBEAK] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_TOUCANNON] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_YUNGOOS] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 14,
    },
    [SPECIES_GUMSHOOS] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_GRUBBIN] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_CHARJABUG] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 15,
    },
    [SPECIES_VIKAVOLT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_CRABRAWLER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_CRABOMINABLE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ORICORIO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_CUTIEFLY] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 15,
    },
    [SPECIES_RIBOMBEE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_ROCKRUFF] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_LYCANROC] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_WISHIWASHI] =
    {
        .size = MON_COORDS_SIZE(56, 32),
        .y_offset = 18,
    },
    [SPECIES_MAREANIE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 15,
    },
    [SPECIES_TOXAPEX] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_MUDBRAY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_MUDSDALE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_DEWPIDER] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 8,
    },
    [SPECIES_ARAQUANID] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 12,
    },
    [SPECIES_FOMANTIS] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 5,
    },
    [SPECIES_LURANTIS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_MORELULL] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 9,
    },
    [SPECIES_SHIINOTIC] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_SALANDIT] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_SALAZZLE] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 3,
    },
    [SPECIES_STUFFUL] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 12,
    },
    [SPECIES_BEWEAR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_BOUNSWEET] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 14,
    },
    [SPECIES_STEENEE] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 8,
    },
    [SPECIES_TSAREENA] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_COMFEY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 11,
    },
    [SPECIES_ORANGURU] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 12,
    },
    [SPECIES_PASSIMIAN] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_WIMPOD] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_GOLISOPOD] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_SANDYGAST] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 11,
    },
    [SPECIES_PALOSSAND] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_PYUKUMUKU] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 16,
    },
    [SPECIES_TYPE_NULL] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_SILVALLY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_MINIOR] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_KOMALA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_TURTONATOR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 9,
    },
    [SPECIES_TOGEDEMARU] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 13,
    },
    [SPECIES_MIMIKYU] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_BRUXISH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 14,
    },
    [SPECIES_DRAMPA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_DHELMISE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_JANGMO_O] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 7,
    },
    [SPECIES_HAKAMO_O] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 5,
    },
    [SPECIES_KOMMO_O] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_TAPU_KOKO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_TAPU_LELE] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_TAPU_BULU] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_TAPU_FINI] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_COSMOG] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_COSMOEM] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 17,
    },
    [SPECIES_SOLGALEO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_LUNALA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_NIHILEGO] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_BUZZWOLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 14,
    },
    [SPECIES_PHEROMOSA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_XURKITREE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_CELESTEELA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_KARTANA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_GUZZLORD] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 10,
    },
    [SPECIES_NECROZMA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_MAGEARNA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_MARSHADOW] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 6,
    },
    [SPECIES_POIPOLE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_NAGANADEL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_STAKATAKA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 12,
    },
    [SPECIES_BLACEPHALON] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_ZERAORA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 11,
    },
    [SPECIES_MELTAN] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 12,
    },
    [SPECIES_MELMETAL] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_GROOKEY] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_THWACKEY] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_RILLABOOM] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_SCORBUNNY] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 4,
    },
    [SPECIES_RABOOT] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_CINDERACE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 4,
    },
    [SPECIES_SOBBLE] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 8,
    },
    [SPECIES_DRIZZILE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_INTELEON] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 4,
    },
    [SPECIES_SKWOVET] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_GREEDENT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_ROOKIDEE] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 17,
    },
    [SPECIES_CORVISQUIRE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_CORVIKNIGHT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_BLIPBUG] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 7,
    },
    [SPECIES_DOTTLER] =
    {
        .size = MON_COORDS_SIZE(56, 32),
        .y_offset = 17,
    },
    [SPECIES_ORBEETLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_NICKIT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_THIEVUL] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_GOSSIFLEUR] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 15,
    },
    [SPECIES_ELDEGOSS] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 15,
    },
    [SPECIES_WOOLOO] =
    {
        .size = MON_COORDS_SIZE(56, 32),
        .y_offset = 18,
    },
    [SPECIES_DUBWOOL] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_CHEWTLE] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 8,
    },
    [SPECIES_DREDNAW] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 18,
    },
    [SPECIES_YAMPER] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 13,
    },
    [SPECIES_BOLTUND] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_ROLYCOLY] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 17,
    },
    [SPECIES_CARKOL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_COALOSSAL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_APPLIN] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 15,
    },
    [SPECIES_FLAPPLE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_APPLETUN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 11,
    },
    [SPECIES_SILICOBRA] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    [SPECIES_SANDACONDA] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_CRAMORANT] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_ARROKUDA] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 15,
    },
    [SPECIES_BARRASKEWDA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_TOXEL] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_TOXTRICITY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SIZZLIPEDE] =
    {
        .size = MON_COORDS_SIZE(40, 32),
        .y_offset = 16,
    },
    [SPECIES_CENTISKORCH] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_CLOBBOPUS] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 14,
    },
    [SPECIES_GRAPPLOCT] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_SINISTEA] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 16,
    },
    [SPECIES_POLTEAGEIST] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_HATENNA] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 12,
    },
    [SPECIES_HATTREM] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_HATTERENE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_IMPIDIMP] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_MORGREM] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_GRIMMSNARL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_OBSTAGOON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_PERRSERKER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_CURSOLA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_SIRFETCHD] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_MR_RIME] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_RUNERIGUS] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_MILCERY] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 16,
    },
    [SPECIES_ALCREMIE] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_FALINKS] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 15,
    },
    [SPECIES_PINCURCHIN] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_SNOM] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 17,
    },
    [SPECIES_FROSMOTH] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_STONJOURNER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_EISCUE] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    [SPECIES_INDEEDEE] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 7,
    },
    [SPECIES_MORPEKO] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    [SPECIES_CUFANT] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_COPPERAJAH] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 16,
    },
    [SPECIES_DRACOZOLT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_ARCTOZOLT] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_DRACOVISH] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_ARCTOVISH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_DURALUDON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_DREEPY] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_DRAKLOAK] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_DRAGAPULT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_ZACIAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_ZAMAZENTA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_ETERNATUS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_KUBFU] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_URSHIFU] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_ZARUDE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_REGIELEKI] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_REGIDRAGO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_GLASTRIER] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 5,
    },
    [SPECIES_SPECTRIER] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_CALYREX] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    // Megas
    [SPECIES_VENUSAUR_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 8,
    },
    [SPECIES_CHARIZARD_MEGA_X] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_CHARIZARD_MEGA_Y] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_BLASTOISE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_BEEDRILL_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_PIDGEOT_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_ALAKAZAM_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SLOWBRO_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_GENGAR_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_KANGASKHAN_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_PINSIR_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_GYARADOS_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_AERODACTYL_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 8,
    },
    [SPECIES_MEWTWO_MEGA_X] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_MEWTWO_MEGA_Y] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_AMPHAROS_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_STEELIX_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SCIZOR_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_HERACROSS_MEGA] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_HOUNDOOM_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_TYRANITAR_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SCEPTILE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_BLAZIKEN_MEGA] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SWAMPERT_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_GARDEVOIR_MEGA] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_SABLEYE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 13,
    },
    [SPECIES_MAWILE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 6,
    },
    [SPECIES_AGGRON_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_MEDICHAM_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_MANECTRIC_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_SHARPEDO_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_CAMERUPT_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 9,
    },
    [SPECIES_ALTARIA_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_BANETTE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_ABSOL_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_GLALIE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_SALAMENCE_MEGA] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_METAGROSS_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_LATIAS_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_LATIOS_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_LOPUNNY_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_GARCHOMP_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_LUCARIO_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_ABOMASNOW_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_GALLADE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_AUDINO_MEGA] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_DIANCIE_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    // Special Mega + Primals
    [SPECIES_RAYQUAZA_MEGA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_KYOGRE_PRIMAL] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 18,
    },
    [SPECIES_GROUDON_PRIMAL] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    // Alolan Forms
    [SPECIES_RATTATA_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_RATICATE_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_RAICHU_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    [SPECIES_SANDSHREW_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 13,
    },
    [SPECIES_SANDSLASH_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_VULPIX_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_NINETALES_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_DIGLETT_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 14,
    },
    [SPECIES_DUGTRIO_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 32),
        .y_offset = 17,
    },
    [SPECIES_MEOWTH_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_PERSIAN_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_GEODUDE_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 13,
    },
    [SPECIES_GRAVELER_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 10,
    },
    [SPECIES_GOLEM_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 13,
    },
    [SPECIES_GRIMER_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 14,
    },
    [SPECIES_MUK_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_EXEGGUTOR_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_MAROWAK_ALOLAN] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 6,
    },
    // Galarian Forms
    [SPECIES_MEOWTH_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_PONYTA_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_RAPIDASH_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    [SPECIES_SLOWPOKE_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_SLOWBRO_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_FARFETCHD_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_WEEZING_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_MR_MIME_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_ARTICUNO_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    [SPECIES_ZAPDOS_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 9,
    },
    [SPECIES_MOLTRES_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(56, 56),
        .y_offset = 5,
    },
    [SPECIES_SLOWKING_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    [SPECIES_CORSOLA_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    [SPECIES_ZIGZAGOON_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 12,
    },
    [SPECIES_LINOONE_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    [SPECIES_DARUMAKA_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_DARMANITAN_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_YAMASK_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 13,
    },
    [SPECIES_STUNFISK_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 24),
        .y_offset = 23,
    },
    // Misc Forms
    // Cosplay Pikachu
    [SPECIES_PIKACHU_COSPLAY] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_ROCK_STAR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_BELLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_POP_STAR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_PH_D] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_LIBRE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    // Cap Pikachu
    [SPECIES_PIKACHU_ORIGINAL_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_HOENN_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_SINNOH_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_UNOVA_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_KALOS_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_ALOLA_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_PARTNER_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    [SPECIES_PIKACHU_WORLD_CAP] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    // Pichu
    [SPECIES_PICHU_SPIKY_EARED] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    // Unown
    [SPECIES_UNOWN_B] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 9,
    },
    [SPECIES_UNOWN_C] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 6,
    },
    [SPECIES_UNOWN_D] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 8,
    },
    [SPECIES_UNOWN_E] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 10,
    },
    [SPECIES_UNOWN_F] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 10,
    },
    [SPECIES_UNOWN_G] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 5,
    },
    [SPECIES_UNOWN_H] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 8,
    },
    [SPECIES_UNOWN_I] =
    {
        .size = MON_COORDS_SIZE(24, 56),
        .y_offset = 7,
    },
    [SPECIES_UNOWN_J] =
    {
        .size = MON_COORDS_SIZE(32, 48),
        .y_offset = 9,
    },
    [SPECIES_UNOWN_K] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 7,
    },
    [SPECIES_UNOWN_L] =
    {
        .size = MON_COORDS_SIZE(32, 48),
        .y_offset = 10,
    },
    [SPECIES_UNOWN_M] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_UNOWN_N] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_UNOWN_O] =
    {
        .size = MON_COORDS_SIZE(48, 48),
        .y_offset = 8,
    },
    [SPECIES_UNOWN_P] =
    {
        .size = MON_COORDS_SIZE(32, 48),
        .y_offset = 10,
    },
    [SPECIES_UNOWN_Q] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 15,
    },
    [SPECIES_UNOWN_R] =
    {
        .size = MON_COORDS_SIZE(32, 40),
        .y_offset = 12,
    },
    [SPECIES_UNOWN_S] =
    {
        .size = MON_COORDS_SIZE(40, 56),
        .y_offset = 4,
    },
    [SPECIES_UNOWN_T] =
    {
        .size = MON_COORDS_SIZE(32, 40),
        .y_offset = 13,
    },
    [SPECIES_UNOWN_U] =
    {
        .size = MON_COORDS_SIZE(48, 40),
        .y_offset = 13,
    },
    [SPECIES_UNOWN_V] =
    {
        .size = MON_COORDS_SIZE(40, 48),
        .y_offset = 11,
    },
    [SPECIES_UNOWN_W] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 13,
    },
    [SPECIES_UNOWN_X] =
    {
        .size = MON_COORDS_SIZE(40, 40),
        .y_offset = 15,
    },
    [SPECIES_UNOWN_Y] =
    {
        .size = MON_COORDS_SIZE(32, 48),
        .y_offset = 10,
    },
    [SPECIES_UNOWN_Z] =
    {
        .size = MON_COORDS_SIZE(32, 48),
        .y_offset = 10,
    },
    [SPECIES_UNOWN_EMARK] =
    {
        .size = MON_COORDS_SIZE(24, 56),
        .y_offset = 6,
    },
    [SPECIES_UNOWN_QMARK] =
    {
        .size = MON_COORDS_SIZE(32, 56),
        .y_offset = 6,
    },
    // Castform
    [SPECIES_CASTFORM_SUNNY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_CASTFORM_RAINY] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 0,
    },
    [SPECIES_CASTFORM_SNOWY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    // Deoxys
    [SPECIES_DEOXYS_ATTACK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_DEOXYS_DEFENSE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_DEOXYS_SPEED] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    // Burmy
    [SPECIES_BURMY_SANDY_CLOAK] =
    {
        .size = MON_COORDS_SIZE(32, 56),
        .y_offset = 7,
    },
    [SPECIES_BURMY_TRASH_CLOAK] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 0,
    },
    // Wormadam
    [SPECIES_WORMADAM_SANDY_CLOAK] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    [SPECIES_WORMADAM_TRASH_CLOAK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    // Cherrim
    [SPECIES_CHERRIM_SUNSHINE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    // Shellos
    [SPECIES_SHELLOS_EAST_SEA] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 8,
    },
    // Gastrodon
    [SPECIES_GASTRODON_EAST_SEA] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 3,
    },
    // Rotom
    [SPECIES_ROTOM_HEAT] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_ROTOM_WASH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_ROTOM_FROST] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_ROTOM_FAN] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_ROTOM_MOW] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 10,
    },
    // Giratina
    [SPECIES_GIRATINA_ORIGIN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    // Shaymin
    [SPECIES_SHAYMIN_SKY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 2,
    },
    // Arceus
    [SPECIES_ARCEUS_FIGHTING] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_FLYING] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_POISON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_GROUND] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_ROCK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_BUG] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_GHOST] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_STEEL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_FIRE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_WATER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_GRASS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_ELECTRIC] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_PSYCHIC] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_ICE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_DRAGON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_DARK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    [SPECIES_ARCEUS_FAIRY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    // Basculin
    [SPECIES_BASCULIN_BLUE_STRIPED] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 16,
    },
    // Darmanitan
    [SPECIES_DARMANITAN_ZEN_MODE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 11,
    },
    [SPECIES_DARMANITAN_ZEN_MODE_GALARIAN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    // Deerling
    [SPECIES_DEERLING_SUMMER] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_DEERLING_AUTUMN] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_DEERLING_WINTER] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    // Sawsbuck
    [SPECIES_SAWSBUCK_SUMMER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_SAWSBUCK_AUTUMN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_SAWSBUCK_WINTER] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 5,
    },
    // Therian Forms
    [SPECIES_TORNADUS_THERIAN] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_THUNDURUS_THERIAN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 5,
    },
    [SPECIES_LANDORUS_THERIAN] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    // Kyurem
    [SPECIES_KYUREM_WHITE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_KYUREM_BLACK] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    // Keldeo
    [SPECIES_KELDEO_RESOLUTE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    // Meloetta
    [SPECIES_MELOETTA_PIROUETTE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 4,
    },
    // Genesect
    [SPECIES_GENESECT_DOUSE_DRIVE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_GENESECT_SHOCK_DRIVE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_GENESECT_BURN_DRIVE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    [SPECIES_GENESECT_CHILL_DRIVE] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 8,
    },
    // Greninja
    [SPECIES_GRENINJA_BATTLE_BOND] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    [SPECIES_GRENINJA_ASH] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 11,
    },
    // Vivillon
    [SPECIES_VIVILLON_POLAR] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_TUNDRA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_CONTINENTAL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_GARDEN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_ELEGANT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_MEADOW] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_MODERN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_MARINE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_ARCHIPELAGO] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_HIGH_PLAINS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_SANDSTORM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_RIVER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_MONSOON] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_SAVANNA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_SUN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_OCEAN] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_JUNGLE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_FANCY] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_VIVILLON_POKE_BALL] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    // Flabébé
    [SPECIES_FLABEBE_YELLOW_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_FLABEBE_ORANGE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_FLABEBE_BLUE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    [SPECIES_FLABEBE_WHITE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 12,
    },
    // Floette
    [SPECIES_FLOETTE_YELLOW_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_FLOETTE_ORANGE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_FLOETTE_BLUE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_FLOETTE_WHITE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_FLOETTE_ETERNAL_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    // Florges
    [SPECIES_FLORGES_YELLOW_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_FLORGES_ORANGE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_FLORGES_BLUE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    [SPECIES_FLORGES_WHITE_FLOWER] =
    {
        .size = MON_COORDS_SIZE(64, 48),
        .y_offset = 9,
    },
    // Furfrou
    [SPECIES_FURFROU_HEART_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_STAR_TRIM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_DIAMOND_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_DEBUTANTE_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_MATRON_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_DANDY_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_LA_REINE_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_KABUKI_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    [SPECIES_FURFROU_PHARAOH_TRIM] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    // Meowstic
    [SPECIES_MEOWSTIC_FEMALE] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 9,
    },
    // Aegislash
    [SPECIES_AEGISLASH_BLADE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 9,
    },
    // Pumpkaboo
    [SPECIES_PUMPKABOO_SMALL] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 14,
    },
    [SPECIES_PUMPKABOO_LARGE] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 13,
    },
    [SPECIES_PUMPKABOO_SUPER] =
    {
        .size = MON_COORDS_SIZE(56, 48),
        .y_offset = 12,
    },
    // Gourgeist
    [SPECIES_GOURGEIST_SMALL] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 4,
    },
    [SPECIES_GOURGEIST_LARGE] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 2,
    },
    [SPECIES_GOURGEIST_SUPER] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 1,
    },
    // Xerneas
    [SPECIES_XERNEAS_ACTIVE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    // Zygarde
    [SPECIES_ZYGARDE_10] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 8,
    },
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 4,
    },
    [SPECIES_ZYGARDE_COMPLETE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    // Hoopa
    [SPECIES_HOOPA_UNBOUND] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    // Oricorio
    [SPECIES_ORICORIO_POM_POM] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_ORICORIO_PAU] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    [SPECIES_ORICORIO_SENSU] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 0,
    },
    // Rockruff
    [SPECIES_ROCKRUFF_OWN_TEMPO] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    // Lycanroc
    [SPECIES_LYCANROC_MIDNIGHT] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    [SPECIES_LYCANROC_DUSK] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    // Wishiwashi
    [SPECIES_WISHIWASHI_SCHOOL] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    // Silvally
    [SPECIES_SILVALLY_FIGHTING] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_FLYING] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_POISON] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_GROUND] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_ROCK] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_BUG] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_GHOST] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_STEEL] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_FIRE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_WATER] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_GRASS] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_ELECTRIC] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_PSYCHIC] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_ICE] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_DRAGON] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_DARK] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    [SPECIES_SILVALLY_FAIRY] =
    {
        .size = MON_COORDS_SIZE(56, 64),
        .y_offset = 0,
    },
    // Minior
    [SPECIES_MINIOR_METEOR_ORANGE] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_MINIOR_METEOR_YELLOW] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_MINIOR_METEOR_GREEN] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_MINIOR_METEOR_BLUE] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_MINIOR_METEOR_INDIGO] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_MINIOR_METEOR_VIOLET] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 14,
    },
    [SPECIES_MINIOR_CORE_RED] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_MINIOR_CORE_ORANGE] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_MINIOR_CORE_YELLOW] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_MINIOR_CORE_GREEN] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_MINIOR_CORE_BLUE] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_MINIOR_CORE_INDIGO] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    [SPECIES_MINIOR_CORE_VIOLET] =
    {
        .size = MON_COORDS_SIZE(56, 40),
        .y_offset = 15,
    },
    // Mimikyu
    [SPECIES_MIMIKYU_BUSTED] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 15,
    },
    // Necrozma
    [SPECIES_NECROZMA_DUSK_MANE] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_NECROZMA_DAWN_WINGS] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 2,
    },
    [SPECIES_NECROZMA_ULTRA] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    // Magearna
    [SPECIES_MAGEARNA_ORIGINAL_COLOR] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    // Cramorant
    [SPECIES_CRAMORANT_GULPING] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    [SPECIES_CRAMORANT_GORGING] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 1,
    },
    // Toxtricity
    [SPECIES_TOXTRICITY_LOW_KEY] =
    {
        .size = MON_COORDS_SIZE(48, 64),
        .y_offset = 0,
    },
    // Sinistea
    [SPECIES_SINISTEA_ANTIQUE] =
    {
        .size = MON_COORDS_SIZE(48, 32),
        .y_offset = 16,
    },
    // Polteageist
    [SPECIES_POLTEAGEIST_ANTIQUE] =
    {
        .size = MON_COORDS_SIZE(64, 40),
        .y_offset = 13,
    },
    // Alcremie
    [SPECIES_ALCREMIE_RUBY_CREAM] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_ALCREMIE_MATCHA_CREAM] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_ALCREMIE_MINT_CREAM] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_ALCREMIE_LEMON_CREAM] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_ALCREMIE_SALTED_CREAM] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_ALCREMIE_RUBY_SWIRL] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_ALCREMIE_CARAMEL_SWIRL] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    [SPECIES_ALCREMIE_RAINBOW_SWIRL] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 9,
    },
    // Eiscue
    [SPECIES_EISCUE_NOICE_FACE] =
    {
        .size = MON_COORDS_SIZE(40, 64),
        .y_offset = 0,
    },
    // Indeedee
    [SPECIES_INDEEDEE_FEMALE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    // Morpeko
    [SPECIES_MORPEKO_HANGRY] =
    {
        .size = MON_COORDS_SIZE(48, 56),
        .y_offset = 8,
    },
    // Zacian
    [SPECIES_ZACIAN_CROWNED_SWORD] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 6,
    },
    // Zamazenta
    [SPECIES_ZAMAZENTA_CROWNED_SHIELD] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 3,
    },
    // Eternatus
    [SPECIES_ETERNATUS_ETERNAMAX] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    // Urshifu
    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 4,
    },
    // Zarude
    [SPECIES_ZARUDE_DADA] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 5,
    },
    // Calyrex
    [SPECIES_CALYREX_ICE_RIDER] =
    {
        .size = MON_COORDS_SIZE(64, 64),
        .y_offset = 7,
    },
    [SPECIES_CALYREX_SHADOW_RIDER] =
    {
        .size = MON_COORDS_SIZE(64, 56),
        .y_offset = 7,
    },
    // Egg
    [SPECIES_EGG] =
    {
        .size = MON_COORDS_SIZE(24, 24),
        .y_offset = 20,
    },
};
