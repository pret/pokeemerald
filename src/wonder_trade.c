#include "global.h"
#include "pokemon.h"
#include "strings.h"
#include "random.h"
#include "text.h"
#include "event_data.h"
#include "region_map.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "data/text/wonder_trade_OT_names.h"
#include "constants/region_map_sections.h"
#include "item.h"
#include "constants/item.h"
#include "constants/hold_effects.h"
#include "mail.h"
#include "constants/pokemon.h"
#ifdef POKEMON_EXPANSION
#include "party_menu.h"
#include "field_weather.h"
#include "constants/weather.h"
#endif

extern struct Evolution gEvolutionTable[][EVOS_PER_MON];

struct InGameTrade {
    /*0x00*/ u8 name[11];
    /*0x0C*/ u16 species;
    /*0x0E*/ u8 ivs[6];
    /*0x14*/ bool8 ability;
    /*0x18*/ u32 otId;
    /*0x1C*/ u8 stats[5];
    /*0x24*/ u32 personality;
    /*0x28*/ u16 heldItem;
    /*0x2A*/ u8 mailNum;
    /*0x2B*/ u8 otName[11];
    /*0x36*/ u8 otGender;
    /*0x37*/ u8 sheen;
    /*0x38*/ u16 playerSpecies;
};

#ifndef POKEMON_EXPANSION
// This is a list of items that were not used in vanilla.
// Feel free to delete it and remove the check that uses it.
static const u16 sInvalidItem[] = {
    [ITEM_034] = 1,
    [ITEM_035] = 1,
    [ITEM_036] = 1,
    [ITEM_037] = 1,
    [ITEM_038] = 1,
    [ITEM_039] = 1,
    [ITEM_03A] = 1,
    [ITEM_03B] = 1,
    [ITEM_03C] = 1,
    [ITEM_03D] = 1,
    [ITEM_03E] = 1,
    [ITEM_048] = 1,
    [ITEM_052] = 1,
    [ITEM_057] = 1,
    [ITEM_058] = 1,
    [ITEM_059] = 1,
    [ITEM_05A] = 1,
    [ITEM_05B] = 1,
    [ITEM_05C] = 1,
    [ITEM_063] = 1,
    [ITEM_064] = 1,
    [ITEM_065] = 1,
    [ITEM_066] = 1,
    [ITEM_069] = 1,
    [ITEM_070] = 1,
    [ITEM_071] = 1,
    [ITEM_072] = 1,
    [ITEM_073] = 1,
    [ITEM_074] = 1,
    [ITEM_075] = 1,
    [ITEM_076] = 1,
    [ITEM_077] = 1,
    [ITEM_078] = 1,
    [ITEM_UNUSED_BERRY_1] = 1,
    [ITEM_UNUSED_BERRY_2] = 1,
    [ITEM_UNUSED_BERRY_3] = 1,
    [ITEM_0E2] = 1,
    [ITEM_0E3] = 1,
    [ITEM_0E4] = 1,
    [ITEM_0E5] = 1,
    [ITEM_0E6] = 1,
    [ITEM_0E7] = 1,
    [ITEM_0E8] = 1,
    [ITEM_0E9] = 1,
    [ITEM_0EA] = 1,
    [ITEM_0EB] = 1,
    [ITEM_0EC] = 1,
    [ITEM_0ED] = 1,
    [ITEM_0EE] = 1,
    [ITEM_0EF] = 1,
    [ITEM_0F0] = 1,
    [ITEM_0F1] = 1,
    [ITEM_0F2] = 1,
    [ITEM_0F3] = 1,
    [ITEM_0F4] = 1,
    [ITEM_0F5] = 1,
    [ITEM_0F6] = 1,
    [ITEM_0F7] = 1,
    [ITEM_0F8] = 1,
    [ITEM_0F9] = 1,
    [ITEM_0FA] = 1,
    [ITEM_0FB] = 1,
    [ITEM_0FC] = 1,
    [ITEM_0FD] = 1,
    [ITEM_10B] = 1,
    [ITEM_15B] = 1,
    [ITEM_15C] = 1,
};
#endif

static const u16 sValidSpecies[] =
{
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PIDGEY,
    SPECIES_RATTATA,
    SPECIES_SPEAROW,
    SPECIES_EKANS,
    SPECIES_SANDSHREW,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_VULPIX,
    SPECIES_ZUBAT,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_DIGLETT,
    SPECIES_MEOWTH,
    SPECIES_PSYDUCK,
    SPECIES_MANKEY,
    SPECIES_GROWLITHE,
    SPECIES_POLIWAG,
    SPECIES_ABRA,
    SPECIES_MACHOP,
    SPECIES_BELLSPROUT,
    SPECIES_TENTACOOL,
    SPECIES_GEODUDE,
    SPECIES_PONYTA,
    SPECIES_SLOWPOKE,
    SPECIES_MAGNEMITE,
    SPECIES_FARFETCHD,
    SPECIES_DODUO,
    SPECIES_SEEL,
    SPECIES_GRIMER,
    SPECIES_SHELLDER,
    SPECIES_GASTLY,
    SPECIES_ONIX,
    SPECIES_DROWZEE,
    SPECIES_KRABBY,
    SPECIES_VOLTORB,
    SPECIES_EXEGGCUTE,
    SPECIES_CUBONE,
    SPECIES_LICKITUNG,
    SPECIES_KOFFING,
    SPECIES_RHYHORN,
    SPECIES_CHANSEY,
    SPECIES_TANGELA,
    SPECIES_KANGASKHAN,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_MR_MIME,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
    SPECIES_TAUROS,
    SPECIES_MAGIKARP,
    SPECIES_LAPRAS,
    SPECIES_DITTO,
    SPECIES_EEVEE,
    SPECIES_PORYGON,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_AERODACTYL,
#ifndef POKEMON_EXPANSION
    SPECIES_SNORLAX,
#endif
    SPECIES_DRATINI,
    SPECIES_CHIKORITA,
    SPECIES_TOTODILE,
    SPECIES_SENTRET,
    SPECIES_HOOTHOOT,
    SPECIES_LEDYBA,
    SPECIES_SPINARAK,
    SPECIES_CHINCHOU,
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_TOGEPI,
    SPECIES_NATU,
    SPECIES_MAREEP,
    SPECIES_SUDOWOODO,
    SPECIES_HOPPIP,
    SPECIES_AIPOM,
    SPECIES_SUNKERN,
    SPECIES_YANMA,
    SPECIES_WOOPER,
    SPECIES_MURKROW,
    SPECIES_MISDREAVUS,
    SPECIES_UNOWN,
    SPECIES_GIRAFARIG,
    SPECIES_PINECO,
    SPECIES_DUNSPARCE,
    SPECIES_GLIGAR,
    SPECIES_SNUBBULL,
    SPECIES_QWILFISH,
    SPECIES_SHUCKLE,
    SPECIES_HERACROSS,
    SPECIES_SNEASEL,
    SPECIES_TEDDIURSA,
    SPECIES_SLUGMA,
    SPECIES_SWINUB,
    SPECIES_CORSOLA,
    SPECIES_REMORAID,
    SPECIES_DELIBIRD,
    SPECIES_MANTINE,
    SPECIES_SKARMORY,
    SPECIES_HOUNDOUR,
    SPECIES_PHANPY,
    SPECIES_STANTLER,
    SPECIES_SMEARGLE,
    SPECIES_TYROGUE,
    SPECIES_SMOOCHUM,
    SPECIES_ELEKID,
    SPECIES_MAGBY,
    SPECIES_MILTANK,
    SPECIES_LARVITAR,
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_POOCHYENA,
    SPECIES_ZIGZAGOON,
    SPECIES_WURMPLE,
    SPECIES_LOTAD,
    SPECIES_SEEDOT,
    SPECIES_NINCADA,
    SPECIES_TAILLOW,
    SPECIES_SHROOMISH,
    SPECIES_SPINDA,
    SPECIES_WINGULL,
    SPECIES_SURSKIT,
    SPECIES_WAILMER,
    SPECIES_SKITTY,
    SPECIES_KECLEON,
    SPECIES_BALTOY,
    SPECIES_NOSEPASS,
    SPECIES_TORKOAL,
    SPECIES_SABLEYE,
    SPECIES_BARBOACH,
    SPECIES_LUVDISC,
    SPECIES_CORPHISH,
    SPECIES_FEEBAS,
    SPECIES_CARVANHA,
    SPECIES_TRAPINCH,
    SPECIES_MAKUHITA,
    SPECIES_ELECTRIKE,
    SPECIES_NUMEL,
    SPECIES_SPHEAL,
    SPECIES_CACNEA,
    SPECIES_SNORUNT,
    SPECIES_LUNATONE,
    SPECIES_SOLROCK,
    SPECIES_AZURILL,
    SPECIES_SPOINK,
    SPECIES_PLUSLE,
    SPECIES_MINUN,
    SPECIES_MAWILE,
    SPECIES_MEDITITE,
    SPECIES_SWABLU,
    SPECIES_WYNAUT,
    SPECIES_DUSKULL,
    SPECIES_ROSELIA,
    SPECIES_SLAKOTH,
    SPECIES_GULPIN,
    SPECIES_TROPIUS,
    SPECIES_WHISMUR,
    SPECIES_CLAMPERL,
    SPECIES_ABSOL,
    SPECIES_SHUPPET,
    SPECIES_SEVIPER,
    SPECIES_ZANGOOSE,
    SPECIES_RELICANTH,
    SPECIES_ARON,
    SPECIES_CASTFORM,
    SPECIES_VOLBEAT,
    SPECIES_ILLUMISE,
    SPECIES_LILEEP,
    SPECIES_ANORITH,
    SPECIES_RALTS,
    SPECIES_BAGON,
    SPECIES_BELDUM,
    SPECIES_CHIMECHO,
#ifdef POKEMON_EXPANSION
    SPECIES_TURTWIG,
    SPECIES_CHIMCHAR,
    SPECIES_PIPLUP,
    SPECIES_STARLY,
    SPECIES_BIDOOF,
    SPECIES_KRICKETOT,
    SPECIES_SHINX,
    SPECIES_BUDEW,
    SPECIES_CRANIDOS,
    SPECIES_SHIELDON,
    SPECIES_BURMY,
    SPECIES_COMBEE,
    SPECIES_PACHIRISU,
    SPECIES_BUIZEL,
    SPECIES_CHERUBI,
    SPECIES_SHELLOS,
    SPECIES_DRIFLOON,
    SPECIES_BUNEARY,
    SPECIES_GLAMEOW,
    SPECIES_CHINGLING,
    SPECIES_STUNKY,
    SPECIES_BRONZOR,
    SPECIES_BONSLY,
    SPECIES_MIME_JR,
    SPECIES_HAPPINY,
    SPECIES_CHATOT,
    SPECIES_SPIRITOMB,
    SPECIES_GIBLE,
    SPECIES_MUNCHLAX,
    SPECIES_RIOLU,
    SPECIES_HIPPOPOTAS,
    SPECIES_SKORUPI,
    SPECIES_CROAGUNK,
    SPECIES_CARNIVINE,
    SPECIES_FINNEON,
    SPECIES_MANTYKE,
    SPECIES_SNOVER,
    SPECIES_ROTOM,
    SPECIES_SNIVY,
    SPECIES_TEPIG,
    SPECIES_OSHAWOTT,
    SPECIES_PATRAT,
    SPECIES_LILLIPUP,
    SPECIES_PURRLOIN,
    SPECIES_PANSAGE,
    SPECIES_PANSEAR,
    SPECIES_PANPOUR,
    SPECIES_MUNNA,
    SPECIES_PIDOVE,
    SPECIES_BLITZLE,
    SPECIES_ROGGENROLA,
    SPECIES_WOOBAT,
    SPECIES_DRILBUR,
    SPECIES_AUDINO,
    SPECIES_TIMBURR,
    SPECIES_TYMPOLE,
    SPECIES_THROH,
    SPECIES_SAWK,
    SPECIES_SEWADDLE,
    SPECIES_VENIPEDE,
    SPECIES_COTTONEE,
    SPECIES_PETILIL,
    SPECIES_BASCULIN,
    SPECIES_SANDILE,
    SPECIES_DARUMAKA,
    SPECIES_MARACTUS,
    SPECIES_DWEBBLE,
    SPECIES_SCRAGGY,
    SPECIES_SIGILYPH,
    SPECIES_YAMASK,
    SPECIES_TIRTOUGA,
    SPECIES_ARCHEN,
    SPECIES_TRUBBISH,
    SPECIES_ZORUA,
    SPECIES_MINCCINO,
    SPECIES_GOTHITA,
    SPECIES_SOLOSIS,
    SPECIES_DUCKLETT,
    SPECIES_VANILLITE,
    SPECIES_DEERLING,
    SPECIES_EMOLGA,
    SPECIES_KARRABLAST,
    SPECIES_FOONGUS,
    SPECIES_FRILLISH,
    SPECIES_ALOMOMOLA,
    SPECIES_JOLTIK,
    SPECIES_FERROSEED,
    SPECIES_KLINK,
    SPECIES_TYNAMO,
    SPECIES_ELGYEM,
    SPECIES_LITWICK,
    SPECIES_AXEW,
    SPECIES_CUBCHOO,
    SPECIES_CRYOGONAL,
    SPECIES_SHELMET,
    SPECIES_STUNFISK,
    SPECIES_MIENFOO,
    SPECIES_DRUDDIGON,
    SPECIES_GOLETT,
    SPECIES_PAWNIARD,
    SPECIES_BOUFFALANT,
    SPECIES_RUFFLET,
    SPECIES_VULLABY,
    SPECIES_HEATMOR,
    SPECIES_DURANT,
    SPECIES_DEINO,
    SPECIES_LARVESTA,
    SPECIES_CHESPIN,
    SPECIES_FENNEKIN,
    SPECIES_FROAKIE,
    SPECIES_BUNNELBY,
    SPECIES_FLETCHLING,
    SPECIES_SCATTERBUG,
    SPECIES_LITLEO,
    SPECIES_FLABEBE,
    SPECIES_SKIDDO,
    SPECIES_PANCHAM,
    SPECIES_FURFROU,
    SPECIES_ESPURR,
    SPECIES_HONEDGE,
    SPECIES_SPRITZEE,
    SPECIES_SWIRLIX,
    SPECIES_INKAY,
    SPECIES_BINACLE,
    SPECIES_SKRELP,
    SPECIES_CLAUNCHER,
    SPECIES_HELIOPTILE,
    SPECIES_TYRUNT,
    SPECIES_AMAURA,
    SPECIES_HAWLUCHA,
    SPECIES_DEDENNE,
    SPECIES_CARBINK,
    SPECIES_GOOMY,
    SPECIES_KLEFKI,
    SPECIES_PHANTUMP,
    SPECIES_PUMPKABOO,
    SPECIES_BERGMITE,
    SPECIES_NOIBAT,
    SPECIES_ROWLET,
    SPECIES_LITTEN,
    SPECIES_POPPLIO,
    SPECIES_PIKIPEK,
    SPECIES_YUNGOOS,
    SPECIES_GRUBBIN,
    SPECIES_CRABRAWLER,
    SPECIES_ORICORIO,
    SPECIES_CUTIEFLY,
    SPECIES_ROCKRUFF,
    SPECIES_WISHIWASHI,
    SPECIES_MAREANIE,
    SPECIES_MUDBRAY,
    SPECIES_DEWPIDER,
    SPECIES_FOMANTIS,
    SPECIES_MORELULL,
    SPECIES_SALANDIT,
    SPECIES_STUFFUL,
    SPECIES_BOUNSWEET,
    SPECIES_COMFEY,
    SPECIES_PASSIMIAN,
    SPECIES_WIMPOD,
    SPECIES_SANDYGAST,
    SPECIES_PYUKUMUKU,
    SPECIES_MINIOR,
    SPECIES_KOMALA,
    SPECIES_TURTONATOR,
    SPECIES_TOGEDEMARU,
    SPECIES_MIMIKYU,
    SPECIES_BRUXISH,
    SPECIES_DRAMPA,
    SPECIES_DHELMISE,
    SPECIES_JANGMO_O,
    SPECIES_MELTAN,
    SPECIES_GROOKEY,
    SPECIES_SCORBUNNY,
    SPECIES_SOBBLE,
    SPECIES_SKWOVET,
    SPECIES_ROOKIDEE,
    SPECIES_BLIPBUG,
    SPECIES_NICKIT,
    SPECIES_GOSSIFLEUR,
    SPECIES_WOOLOO,
    SPECIES_CHEWTLE,
    SPECIES_YAMPER,
    SPECIES_ROLYCOLY,
    SPECIES_APPLIN,
    SPECIES_SILICOBRA,
    SPECIES_CRAMORANT,
    SPECIES_ARROKUDA,
    SPECIES_TOXEL,
    SPECIES_SIZZLIPEDE,
    SPECIES_CLOBBOPUS,
    SPECIES_SINISTEA,
    SPECIES_HATENNA,
    SPECIES_IMPIDIMP,
    SPECIES_MILCERY,
    SPECIES_FALINKS,
    SPECIES_PINCURCHIN,
    SPECIES_SNOM,
    SPECIES_EISCUE,
    SPECIES_INDEEDEE,
    SPECIES_MORPEKO,
    SPECIES_CUFANT,
    SPECIES_DRACOZOLT,
    SPECIES_ARCTOZOLT,
    SPECIES_DRACOVISH,
    SPECIES_ARCTOVISH,
    SPECIES_DURALUDON,
    SPECIES_DREEPY,
    SPECIES_RATTATA_ALOLAN,
    SPECIES_SANDSHREW_ALOLAN,
    SPECIES_VULPIX_ALOLAN,
    SPECIES_DIGLETT_ALOLAN,
    SPECIES_MEOWTH_ALOLAN,
    SPECIES_GEODUDE_ALOLAN,
    SPECIES_GRIMER_ALOLAN,
    SPECIES_MEOWTH_GALARIAN,
    SPECIES_PONYTA_GALARIAN,
    SPECIES_SLOWPOKE_GALARIAN,
    SPECIES_FARFETCHD_GALARIAN,
    SPECIES_MR_MIME_GALARIAN,
    SPECIES_CORSOLA_GALARIAN,
    SPECIES_ZIGZAGOON_GALARIAN,
    SPECIES_DARUMAKA_GALARIAN,
    SPECIES_YAMASK_GALARIAN,
    SPECIES_STUNFISK_GALARIAN,
    SPECIES_GROWLITHE_HISUIAN,
    SPECIES_VOLTORB_HISUIAN,
    SPECIES_QWILFISH_HISUIAN,
    SPECIES_SNEASEL_HISUIAN,
    SPECIES_ZORUA_HISUIAN,
    SPECIES_BURMY_SANDY_CLOAK,
    SPECIES_BURMY_TRASH_CLOAK,
    SPECIES_SHELLOS_EAST_SEA,
    SPECIES_BASCULIN_BLUE_STRIPED,
    SPECIES_BASCULIN_WHITE_STRIPED,
    SPECIES_DEERLING_SUMMER,
    SPECIES_DEERLING_AUTUMN,
    SPECIES_DEERLING_WINTER,
    SPECIES_FLABEBE_YELLOW_FLOWER,
    SPECIES_FLABEBE_ORANGE_FLOWER,
    SPECIES_FLABEBE_BLUE_FLOWER,
    SPECIES_FLABEBE_WHITE_FLOWER,
    SPECIES_MEOWSTIC_FEMALE,
    SPECIES_PUMPKABOO_SMALL,
    SPECIES_PUMPKABOO_LARGE,
    SPECIES_PUMPKABOO_SUPER,
    SPECIES_ORICORIO_POM_POM,
    SPECIES_ORICORIO_PAU,
    SPECIES_ORICORIO_SENSU,
    SPECIES_ROCKRUFF_OWN_TEMPO,
    SPECIES_MINIOR_METEOR_ORANGE,
    SPECIES_MINIOR_METEOR_YELLOW,
    SPECIES_MINIOR_METEOR_GREEN,
    SPECIES_MINIOR_METEOR_BLUE,
    SPECIES_MINIOR_METEOR_INDIGO,
    SPECIES_MINIOR_METEOR_VIOLET,
    SPECIES_SINISTEA_ANTIQUE,
    SPECIES_INDEEDEE_FEMALE,
#endif
};

static u16 PickRandomSpecies(void);
void CreateWonderTradePokemon(u8 whichPlayerMon);
u16 determineEvolution(struct Pokemon *);
u8 getWonderTradeOT(u8 *name);
u16 GetValidWonderTradeItem(u16 item);

static u16 PickRandomSpecies() // picks only base forms
{
    u16 species = sValidSpecies[Random() % NELEMS(sValidSpecies)];
    return species;
}

u8 getWonderTradeOT(u8 *name)
{
    u8 randGender = (Random() % 2); // 0 for male, 1 for female
    u8 numOTNames = 250;
    u8 selectedName = Random() %numOTNames;
    u8 i;
    if (randGender == MALE) // male OT selected
    {
        randGender = 0;
        for (i = 0; i < 8; ++i)
        {
            name[i] = maleWTNames[selectedName][i];
        }
        name[8] = EOS;
    }
    else                    // female OT selected
    {
        randGender = 0xFF;
        for (i = 0; i < 8; ++i)
        {
            name[i] = femaleWTNames[selectedName][i];
        }
        name[8] = EOS;
    }
    return randGender;
}

void CreateWonderTradePokemon(u8 whichPlayerMon)
{
    struct InGameTrade *inGameTrade;
    struct Pokemon *pokemon = &gEnemyParty[0];
    u16 species = PickRandomSpecies();
    u8 chanceToEvolve = Random() % 255;
    u8 name[POKEMON_NAME_LENGTH + 1];
    u8 nameOT[8];
    u8 genderOT;
#ifdef POKEMON_EXPANSION
    u8 abilityNum;
#endif
    u8 level = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LEVEL); // gets level of player's selected Pokemon
    u16 playerSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES); // gets species of player's selected Pokemon
    u32 OTID = ((Random() << 16) | Random());
    u32 personality = ((Random() << 16) | Random());
    u16 heldItem = 0;
    u16 currHeldItem = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HELD_ITEM);
    u8 metLocation = METLOC_IN_GAME_TRADE;
    u8 i;
    struct InGameTrade gIngameTrades[] = {
        {
            _(""), species,
            (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32),
            (Random() % 2), OTID,
            0, 0, 0, 0, 0,
            personality,
            heldItem, -1,
            _("ERROR"), FEMALE, 0,
            playerSpecies
        }
    };

    genderOT = getWonderTradeOT(nameOT);
    inGameTrade = &gIngameTrades[0];
    CreateMon(pokemon, species, level, 0, FALSE, 0, TRUE, (Random() << 16) | Random());

    if (chanceToEvolve >= 200) // evolves to highest stage
    {
        species = determineEvolution(pokemon);
        CreateMon(pokemon, species, level, 0, FALSE, 0, TRUE, (Random() << 16) | Random());
        species = determineEvolution(pokemon);
        CreateMon(pokemon, species, level, 0, FALSE, 0, TRUE, (Random() << 16) | Random());
    }
    else if (chanceToEvolve >= 100 && chanceToEvolve < 200) // evolves once
    {
        species = determineEvolution(pokemon);
        CreateMon(pokemon, species, level, 0, FALSE, 0, TRUE, (Random() << 16) | Random());
    }

    GetSpeciesName(name, species);

    // 10% chance of having the generated Wonder Traded 'mon carry an item.
    if ((Random() % 99) < 10)
        heldItem = GetValidWonderTradeItem(heldItem);

    if (currHeldItem == ITEM_NONE)
    {
        for (i = 0; i < EVOS_PER_MON; i++)
        {
            if (gEvolutionTable[species][i].method == EVO_TRADE)
            {
                // 30% chance for the in coming Pokémon to hold an Everstone if they evolve by trading
                if (Random() % 255 <= 77)
                {
                    heldItem = ITEM_EVERSTONE;
                    SetMonData(pokemon, MON_DATA_HELD_ITEM, &heldItem);
                }
            }
            else if (gEvolutionTable[species][i].method == EVO_TRADE_ITEM)
            {
                // 30% chance for the in coming Pokémon to hold the item they need to evolve if they need one
                if (Random() % 255 <= 77)
                {
                    heldItem = gEvolutionTable[species][i].param;
                    SetMonData(pokemon, MON_DATA_HELD_ITEM, &heldItem);
                }
            }
        }
    }

#ifdef POKEMON_EXPANSION
    // 10% chance of giving the in coming Pokémon their HA, if they have one
    // Uncomment if your copy of the pokemon_expansion is up-to-date.
    //if (gBaseStats[species].abilities[2] != ABILITY_NONE && (Random() % 99) < 10)
    //{
    //    abilityNum = 2;
    //    SetMonData(pokemon, MON_DATA_ABILITY_NUM, &abilityNum);
    //}

    // Uncomment if your copy of the pokemon_expansion is not up-to-date.
    //if (gBaseStats[species].abilityHidden != ABILITY_NONE && (Random() % 99) < 10)
    //{
    //    abilityNum = 2;
    //    SetMonData(pokemon, MON_DATA_ABILITY_NUM, &abilityNum);
    //}
#endif

    SetMonData(pokemon, MON_DATA_HELD_ITEM, &heldItem);
    SetMonData(pokemon, MON_DATA_HP_IV, &inGameTrade->ivs[0]);
    SetMonData(pokemon, MON_DATA_ATK_IV, &inGameTrade->ivs[1]);
    SetMonData(pokemon, MON_DATA_DEF_IV, &inGameTrade->ivs[2]);
    SetMonData(pokemon, MON_DATA_SPEED_IV, &inGameTrade->ivs[3]);
    SetMonData(pokemon, MON_DATA_SPATK_IV, &inGameTrade->ivs[4]);
    SetMonData(pokemon, MON_DATA_SPDEF_IV, &inGameTrade->ivs[5]);
    SetMonData(pokemon, MON_DATA_NICKNAME, name);
    SetMonData(pokemon, MON_DATA_OT_NAME, nameOT);
    SetMonData(pokemon, MON_DATA_BEAUTY, &inGameTrade->stats[1]);
    SetMonData(pokemon, MON_DATA_CUTE, &inGameTrade->stats[2]);
    SetMonData(pokemon, MON_DATA_COOL, &inGameTrade->stats[0]);
    SetMonData(pokemon, MON_DATA_SMART, &inGameTrade->stats[3]);
    SetMonData(pokemon, MON_DATA_TOUGH, &inGameTrade->stats[4]);
    SetMonData(pokemon, MON_DATA_SHEEN, &inGameTrade->sheen);
    SetMonData(pokemon, MON_DATA_MET_LOCATION, &metLocation);
    SetMonData(pokemon, MON_DATA_OT_GENDER, &genderOT);
    CalculateMonStats(&gEnemyParty[0]);
}

#ifdef POKEMON_EXPANSION
u16 determineEvolution(struct Pokemon *mon)
{
    int i, j;
    u16 targetSpecies = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    u16 upperPersonality = personality >> 16;
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    u16 eeveelution = Random() % 8;
    u16 alcrememe = Random() % 9;
    u16 currentMap;

    if (species == SPECIES_NINCADA && level >= 20)
    {
        if ((Random() % 2) == 0)
            targetSpecies = SPECIES_NINJASK;
        else
            targetSpecies = SPECIES_SHEDINJA;
        return targetSpecies;
    }
    else if (species == SPECIES_EEVEE && level >= 25)
    {
        if (eeveelution == 0)
            targetSpecies = SPECIES_VAPOREON;
        else if (eeveelution == 1)
            targetSpecies = SPECIES_JOLTEON;
        else if (eeveelution == 2)
            targetSpecies = SPECIES_FLAREON;
        else if (eeveelution == 3)
            targetSpecies = SPECIES_ESPEON;
        else if (eeveelution == 4)
            targetSpecies = SPECIES_UMBREON;
        else if (eeveelution == 5)
            targetSpecies = SPECIES_LEAFEON;
        else if (eeveelution == 6)
            targetSpecies = SPECIES_GLACEON;
        else if (eeveelution == 7)
            targetSpecies = SPECIES_SYLVEON;
        return targetSpecies;
    }
    else if (species == SPECIES_MILCERY && level >= 25)
    {
        if (alcrememe == 0)
            targetSpecies = SPECIES_ALCREMIE;
        else if (alcrememe == 1)
            targetSpecies = SPECIES_ALCREMIE_RUBY_CREAM;
        else if (alcrememe == 2)
            targetSpecies = SPECIES_ALCREMIE_MATCHA_CREAM;
        else if (alcrememe == 3)
            targetSpecies = SPECIES_ALCREMIE_MINT_CREAM;
        else if (alcrememe == 4)
            targetSpecies = SPECIES_ALCREMIE_LEMON_CREAM;
        else if (alcrememe == 5)
            targetSpecies = SPECIES_ALCREMIE_SALTED_CREAM;
        else if (alcrememe == 6)
            targetSpecies = SPECIES_ALCREMIE_RUBY_SWIRL;
        else if (alcrememe == 7)
            targetSpecies = SPECIES_ALCREMIE_CARAMEL_SWIRL;
        else if (alcrememe == 8)
            targetSpecies = SPECIES_ALCREMIE_RAINBOW_SWIRL;
        return targetSpecies;
    }

    for (i = 0; i < 5; i++)
    {
        switch (gEvolutionTable[species][i].method)
        {
        case EVO_FRIENDSHIP:
            if ((species == SPECIES_PICHU || species == SPECIES_CLEFFA || species == SPECIES_IGGLYBUFF
              || species == SPECIES_TOGEPI || species == SPECIES_AZURILL || species == SPECIES_BUDEW
              || species == SPECIES_BUNEARY || species == SPECIES_SWOOBAT || species == SPECIES_SWADLOON)
              && level >= 16)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            else if (species == SPECIES_MEOWTH_ALOLAN && level >= 28)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            else if ((species == SPECIES_GOLBAT || species == SPECIES_CHANSEY
                   || species == SPECIES_MUNCHLAX) && level >= 35)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_LEVEL:
            if (species == SPECIES_SLOWPOKE && level >= 37)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_SLOWBRO;
                else
                    targetSpecies = SPECIES_SLOWKING;
            }
            else if (species == SPECIES_TOXEL && level >= 30)
            {
                if (GetNature(mon) == NATURE_HARDY || GetNature(mon) == NATURE_BRAVE
                 || GetNature(mon) == NATURE_ADAMANT || GetNature(mon) == NATURE_NAUGHTY
                 || GetNature(mon) == NATURE_DOCILE || GetNature(mon) == NATURE_IMPISH
                 || GetNature(mon) == NATURE_LAX || GetNature(mon) == NATURE_HASTY
                 || GetNature(mon) == NATURE_JOLLY || GetNature(mon) == NATURE_NAIVE
                 || GetNature(mon) == NATURE_RASH || GetNature(mon) == NATURE_SASSY
                 || GetNature(mon) == NATURE_QUIRKY)
                    targetSpecies = SPECIES_TOXTRICITY;
                else
                    targetSpecies = SPECIES_TOXTRICITY_LOW_KEY;
            }
            else if (gEvolutionTable[species][i].param <= level)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_GT_DEF:
            if (gEvolutionTable[species][i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) > GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_EQ_DEF:
            if (gEvolutionTable[species][i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) == GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_LT_DEF:
            if (gEvolutionTable[species][i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) < GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_SILCOON:
            if (gEvolutionTable[species][i].param <= level && (upperPersonality % 10) <= 4)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_LEVEL_CASCOON:
            if (gEvolutionTable[species][i].param <= level && (upperPersonality % 10) > 4)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_BEAUTY:
            if (level >= 30)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_ITEM:
            if (species == SPECIES_GLOOM && level >= 36)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_VILEPLUME;
                else
                    targetSpecies = SPECIES_BELLOSSOM;
            }
            else if (species == SPECIES_WEEPINBELL && level >= 36)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_VULPIX || species == SPECIES_GROWLITHE) && level >= 32)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_SHELLDER || species == SPECIES_STARYU) && level >= 43)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_NIDORINA || species == SPECIES_NIDORINO || species == SPECIES_EXEGGCUTE) && level >= 26)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_JIGGLYPUFF || species == SPECIES_CLEFAIRY || species == SPECIES_SKITTY) && level >= 38)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_LOMBRE || species == SPECIES_NUZLEAF) && level >= 38)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_POLIWHIRL && level >= 44)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_POLIWRATH;
                else
                    targetSpecies = SPECIES_POLITOED;
            }
            else if (species == SPECIES_PIKACHU && level >= 27)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_SUNKERN && level >= 15)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_MURKROW || species == SPECIES_MISDREAVUS
                   || species == SPECIES_MUNNA || species == SPECIES_DOUBLADE
                   || species == SPECIES_SINISTEA || species == SPECIES_SANDSHREW_ALOLAN
                   || species == SPECIES_VULPIX_ALOLAN || species == SPECIES_SINISTEA_ANTIQUE)
                   && level >= 25)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_PANSAGE || species == SPECIES_PANSEAR
                   || species == SPECIES_PANPOUR || species == SPECIES_COTTONEE
                   || species == SPECIES_PETILIL || species == SPECIES_MINCCINO
                   || species == SPECIES_FLOETTE || species == SPECIES_FLOETTE_YELLOW_FLOWER
                   || species == SPECIES_FLOETTE_ORANGE_FLOWER || species == SPECIES_FLOETTE_BLUE_FLOWER
                   || species == SPECIES_FLOETTE_WHITE_FLOWER) && level >= 15)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_EELEKTRIK || species == SPECIES_LAMPENT
                   || species == SPECIES_HELIOPTILE || species == SPECIES_CHARJABUG
                   || species == SPECIES_DARUMAKA_GALARIAN) && level >= 35)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_APPLIN && level >= 30)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_FLAPPLE;
                else
                    targetSpecies = SPECIES_APPLETUN;
            }
            else if (species == SPECIES_SLOWPOKE_GALARIAN && level >= 37)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_SLOWBRO_GALARIAN;
                else
                    targetSpecies = SPECIES_SLOWKING_GALARIAN;
            }
            break;
        case EVO_ITEM_FEMALE:
            if (GetMonGender(mon) == MON_FEMALE && species == SPECIES_SNORUNT && level >= 35)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_ITEM_MALE:
            if (GetMonGender(mon) == MON_MALE && species == SPECIES_KIRLIA && level >= 35)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_MOVE:
            if (MonKnowsMove(mon, gEvolutionTable[species][i].param))
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_MOVE_TYPE:
            for (j = 0; j < 4; j++)
            {
                if (gBattleMoves[GetMonData(mon, MON_DATA_MOVE1 + j, NULL)].type == gEvolutionTable[species][i].param)
                {
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                    break;
                }
            }
            break;
        case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
            if (gEvolutionTable[species][i].param <= level)
            {
                for (j = 0; j < PARTY_SIZE; j++)
                {
                    u16 currSpecies = GetMonData(&gPlayerParty[j], MON_DATA_SPECIES, NULL);
                    if (gBaseStats[currSpecies].type1 == TYPE_DARK
                     || gBaseStats[currSpecies].type2 == TYPE_DARK)
                    {
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                        break;
                    }
                }
            }
            break;
        case EVO_LEVEL_RAIN:
            j = GetCurrentWeather();
            if (j == WEATHER_RAIN || j == WEATHER_RAIN_THUNDERSTORM || j == WEATHER_DOWNPOUR)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_MAPSEC:
            if (gMapHeader.regionMapSectionId == gEvolutionTable[species][i].param)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_SPECIFIC_MAP:
            currentMap = ((gSaveBlock1Ptr->location.mapGroup) << 8 | gSaveBlock1Ptr->location.mapNum);
            if (currentMap == gEvolutionTable[species][i].param)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_SPECIFIC_MON_IN_PARTY:
            for (j = 0; j < PARTY_SIZE; j++)
            {
                if (GetMonData(&gPlayerParty[j], MON_DATA_SPECIES) == gEvolutionTable[species][i].param)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_TRADE:
            targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_TRADE_ITEM:
            {
                u16 currHeldItem = GetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM);
                if (gEvolutionTable[species][i].param == currHeldItem)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        }
    }

    if (targetSpecies == 0)
        return species;
    else
        return targetSpecies;
}
#else
u16 determineEvolution(struct Pokemon *mon)
{
    int i;
    u16 targetSpecies = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    u16 upperPersonality = personality >> 16;
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    u16 eeveelution = Random() % 5;

    if (species == SPECIES_EEVEE || species == SPECIES_NINCADA)
    {
        if (species == SPECIES_NINCADA && level >= 20)
        {
            if ((Random() % 2) == 0)
                targetSpecies = SPECIES_NINJASK;
            else
                targetSpecies = SPECIES_SHEDINJA;
            return targetSpecies;
        }
        else if (species == SPECIES_EEVEE && level >= 25)
        {
            if (eeveelution == 0)
                targetSpecies = SPECIES_VAPOREON;
            else if (eeveelution == 1)
                targetSpecies = SPECIES_JOLTEON;
            else if (eeveelution == 2)
                targetSpecies = SPECIES_FLAREON;
            else if (eeveelution == 3)
                targetSpecies = SPECIES_ESPEON;
            else if (eeveelution == 4)
                targetSpecies = SPECIES_UMBREON;
            return targetSpecies;
        }
    }

    for (i = 0; i < 5; i++)
    {
        switch (gEvolutionTable[species][i].method)
        {
        case EVO_FRIENDSHIP:
            if ((species == SPECIES_PICHU || species == SPECIES_CLEFFA || species == SPECIES_IGGLYBUFF
              || species == SPECIES_TOGEPI || species == SPECIES_AZURILL) && level >= 16)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            else if ((species == SPECIES_GOLBAT || species == SPECIES_CHANSEY) && level >= 35)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_LEVEL:
            if (species == SPECIES_SLOWPOKE && level >= 37)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_SLOWBRO;
                else
                    targetSpecies = SPECIES_SLOWKING;
            }
            else if (gEvolutionTable[species][i].param <= level)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_GT_DEF:
            if (gEvolutionTable[species][i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) > GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_EQ_DEF:
            if (gEvolutionTable[species][i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) == GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_ATK_LT_DEF:
            if (gEvolutionTable[species][i].param <= level)
            {
                if (GetMonData(mon, MON_DATA_ATK, 0) < GetMonData(mon, MON_DATA_DEF, 0))
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_LEVEL_SILCOON:
            if (gEvolutionTable[species][i].param <= level && (upperPersonality % 10) <= 4)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_LEVEL_CASCOON:
            if (gEvolutionTable[species][i].param <= level && (upperPersonality % 10) > 4)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_BEAUTY:
            if (level >= 30)
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            break;
        case EVO_ITEM:
            if (species == SPECIES_GLOOM && level >= 36)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_VILEPLUME;
                else
                    targetSpecies = SPECIES_BELLOSSOM;
            }
            else if (species == SPECIES_WEEPINBELL && level >= 36)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_VULPIX || species == SPECIES_GROWLITHE) && level >= 32)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_SHELLDER || species == SPECIES_STARYU) && level >= 43)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_NIDORINA || species == SPECIES_NIDORINO || species == SPECIES_EXEGGCUTE) && level >= 26)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_JIGGLYPUFF || species == SPECIES_CLEFAIRY || species == SPECIES_SKITTY) && level >= 38)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if ((species == SPECIES_LOMBRE || species == SPECIES_NUZLEAF) && level >= 38)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_POLIWHIRL && level >= 44)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_POLIWRATH;
                else
                    targetSpecies = SPECIES_POLITOED;
            }
            else if (species == SPECIES_PIKACHU && level >= 27)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_SUNKERN && level >= 15)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            break;
        case EVO_TRADE_ITEM:
            if ((species == SPECIES_ONIX || species == SPECIES_SEADRA) && level >= 40)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_SCYTHER && level >= 26)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_PORYGON && level >= 21)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
            }
            else if (species == SPECIES_CLAMPERL && level >= 22)
            {
                if ((Random() % 2) == 0)
                    targetSpecies = SPECIES_HUNTAIL;
                else
                    targetSpecies = SPECIES_GOREBYSS;
            }
            break;
        }
    }

    if (targetSpecies == 0)
        return species;
    else
        return targetSpecies;
}
#endif

#if defined ITEM_EXPANSION && defined POKEMON_EXPANSION
bool32 IsMegaPreEvolution(u16 species, u16 heldStone, bool32 found)
{
    u8 i;

    for (i = 0; i < EVOS_PER_MON; i++)
    {
        if (gEvolutionTable[species][i].targetSpecies != SPECIES_NONE)
        {
            if (gEvolutionTable[species][i].method == EVO_MEGA_EVOLUTION && gEvolutionTable[species][i].param == heldStone)
                found = TRUE;

            found = IsMegaPreEvolution(gEvolutionTable[species][i].targetSpecies, heldStone, found);
        }
    }
    return found;
}

// Generate an item randomly for a Wonder Trade in coming Pokémon to hold, with a few exceptions
u16 GetValidWonderTradeItem(u16 item)
{
    u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    int i;

    ROLL:
        item = Random() % ITEMS_COUNT;

    if (item == ITEM_NONE
     || item == ITEM_ENIGMA_BERRY
     || item == ITEM_GRACIDEA
     || item == ITEM_RED_ORB
     || item == ITEM_BLUE_ORB
     || item == ITEM_ADAMANT_ORB
     || item == ITEM_LUSTROUS_ORB
     || item == ITEM_GRISEOUS_ORB)
        goto ROLL;
    else if (IS_ITEM_MAIL(item))
        goto ROLL;
    else if (ItemId_GetPocket(item) == POCKET_KEY_ITEMS)
        goto ROLL;
    else if (item >= ITEM_HM01 && item <= ITEM_HM08)
        goto ROLL;
    else if ((ItemId_GetHoldEffect(item) == HOLD_EFFECT_MEMORY
           || ItemId_GetHoldEffect(item) == HOLD_EFFECT_DRIVE
           || ItemId_GetHoldEffect(item) == HOLD_EFFECT_PLATE
           || ItemId_GetHoldEffect(item) == HOLD_EFFECT_GEMS)
           && (gBaseStats[species].type1 != ItemId_GetHoldEffectParam(item)
            || gBaseStats[species].type2 != ItemId_GetHoldEffectParam(item)))
        goto ROLL;
    else if (item >= ITEM_NORMALIUM_Z && item <= ITEM_ULTRANECROZIUM_Z)
        goto ROLL;
    else if (item == ITEM_THICK_CLUB
         && (GET_BASE_SPECIES_ID(species) != SPECIES_MAROWAK || GET_BASE_SPECIES_ID(species) != SPECIES_MAROWAK))
        goto ROLL;
    else if (item == ITEM_LIGHT_BALL
         && (GET_BASE_SPECIES_ID(species) != SPECIES_PIKACHU))
        goto ROLL;
    else if (item == ITEM_DEEP_SEA_SCALE
         && (GET_BASE_SPECIES_ID(species) != SPECIES_CLAMPERL))
        goto ROLL;
    else if (item == ITEM_DEEP_SEA_TOOTH
         && (GET_BASE_SPECIES_ID(species) != SPECIES_CLAMPERL))
        goto ROLL;
    else if (item == ITEM_METAL_POWDER
         && (GET_BASE_SPECIES_ID(species) != SPECIES_DITTO))
        goto ROLL;
    else if ((item == ITEM_RED_NECTAR || item == ITEM_YELLOW_NECTAR
           || item == ITEM_PINK_NECTAR || item == ITEM_PURPLE_NECTAR)
           && (GET_BASE_SPECIES_ID(species) != SPECIES_ORICORIO))
        goto ROLL;

    // Make sure that if the Pokémon can Mega Evolve, or it evolves into a species who can, it can get the relevant Mega Stone
    if (ItemId_GetHoldEffect(item) == HOLD_EFFECT_MEGA_STONE)
    {
        if (!IsMegaPreEvolution(species, item, FALSE))
            goto ROLL;
    }

    return item;
}
#else
u16 GetValidWonderTradeItem(u16 item)
{
    int i;
    u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);

    ROLL:
        item = Random() % ITEMS_COUNT;

    if (item == ITEM_NONE || item == ITEM_ENIGMA_BERRY)
        goto ROLL;
    else if (IS_ITEM_MAIL(item))
        goto ROLL;
    else if (ItemId_GetPocket(item) == POCKET_KEY_ITEMS)
        goto ROLL;
    else if (item >= ITEM_HM01 && item <= ITEM_HM08)
        goto ROLL;
    else if (item == ITEM_THICK_CLUB && (species != SPECIES_CUBONE || species != SPECIES_MAROWAK))
        goto ROLL;
    else if (item == ITEM_LIGHT_BALL && species != SPECIES_PIKACHU)
        goto ROLL;
    else if ((item == ITEM_DEEP_SEA_SCALE || item == ITEM_DEEP_SEA_TOOTH) && species != SPECIES_CLAMPERL)
        goto ROLL;
    else if (item == ITEM_METAL_POWDER && species != SPECIES_DITTO)
        goto ROLL;
    else if (sInvalidItem[item])
        goto ROLL;

    return item;
}
#endif
