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
#include "party_menu.h"
#include "field_weather.h"
#include "constants/weather.h"
#include "battle.h" // A workaround to include the expansion's constants/form_change_types.h without breaking Pret/Pokeemerald compatibility.
#include "string_util.h"
#include "daycare.h"
#include "wonder_trade.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "gba/defines.h"
#include "data.h"
#include "gba/types.h"
#include "constants/global.h"

// This file's functions.
static u8 GetWonderTradeOT(u8 *name);

struct WonderTrade {
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 species;
    u8 ivs[NUM_STATS];
    u8 abilityNum;
    u32 otId;
    u8 conditions[CONTEST_CATEGORIES_COUNT];
    u32 personality;
    u16 heldItem;
    u8 mailNum;
    u8 otName[TRAINER_NAME_LENGTH + 1];
    u8 otGender;
    u8 sheen;
    u16 requestedSpecies;
};

static u8 GetWonderTradeOT(u8 *name)
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

static u32 ReturnRandomSpecies()
{   
    u16 species = 0xFF;
    u16 counter = 0;
    u16 counter2 = 0;
    bool8 rerollMon;
    u8 partyCount;
    int i;

    species = GetSpeciesRandomNotSeeded(species * GetSpeciesRandomNotSeeded(VarGet(VAR_PIT_FLOOR) + 1));
    //species = SPECIES_GROUDON; //Test setting for reroll tests

    if (FlagGet(FLAG_NO_DUPLICATES))
    {
        do
        {
            rerollMon = FALSE;
            //reroll in case any legendaries, mythics or ultra beasts are determined
            if (FlagGet(FLAG_NO_LEGENDARIES))
            {
                while (((IsSpeciesLegendary(species) || IsSpeciesMythical(species) || IsSpeciesUltraBeast(species) || IsSpeciesParadoxMon(species)) || species > GetMaxNumberOfSpecies()) && counter < 10)
                {
                    // +counter to handle edge cases
                    species = GetSpeciesRandomNotSeeded(species * GetSpeciesRandomNotSeeded(VarGet(VAR_PIT_FLOOR) + counter2)) + counter;
                    counter ++;
                    DebugPrintf("%d, rerolled non-legend species = %d", counter, species);
                }
            }

            //check for duplicates against the player's party
            partyCount = CalculatePlayerPartyCount();
            if (partyCount > 2 && rerollMon == FALSE) //only the case after obtaining the third mon
            {
                for (i=0; i<partyCount; i++)
                {
                    if (species == GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
                    {
                        rerollMon = TRUE;
                        DebugPrintf("gPlayerParty[%d] = %d", i, species);
                    }
                }
            }
            //exit in case of infinite loop
            if (counter2 == 10)
            {
                rerollMon = FALSE;
                // default species could be specified here!
                DebugPrintf("no valid species found. Default: %d", species);
            }
            //reroll
            if (rerollMon)
            {
                counter2++;
                species = GetSpeciesRandomNotSeeded(species * GetSpeciesRandomNotSeeded(VarGet(VAR_PIT_FLOOR) + 1));
                counter = 0; //reset counter for legendary rerolls
                DebugPrintf("--- reroll ---");
            }
        }
        while (rerollMon);

        //save species for rerolls
        DebugPrintf("Found species = %d", species);
        //sAlreadyRolledSpecies[9]++; //9 = counter of successfully rolled mons
    }
    else
    {
        //reroll in case any legendaries, mythics or ultra beasts are determined
        if (FlagGet(FLAG_NO_LEGENDARIES))
        {
            while ((IsSpeciesLegendary(species) || IsSpeciesMythical(species) || IsSpeciesUltraBeast(species) || IsSpeciesParadoxMon(species)) && counter < 100)
            {
                species = GetSpeciesRandomNotSeeded(species * GetSpeciesRandomNotSeeded(VarGet(VAR_PIT_FLOOR) + 1));
                counter++;
            }
        }
    }

    return species;
}

void CreateWonderTradePokemon(void)
{
    u16 wonderTradeSpecies = ReturnRandomSpecies();
    u8 playerMonLevel = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LEVEL);
    u16 newHeldItem = ITEM_NONE;
    u16 playerMonHeldItem = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HELD_ITEM);
    u32 i;

    u8 abilityNum;

    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u8 genderOT = GetWonderTradeOT(otName);
    u8 metLocation = METLOC_IN_GAME_TRADE;
    struct WonderTrade sWonderTrades[] =
    {
        [0] = {
            .nickname = _(""),
            .species = wonderTradeSpecies,
            .ivs = {(Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32)},
            .abilityNum = (Random() % 2), // Can't use NUM_NORMAL_ABILITY_SLOTS because it's not present in Pret/Pokeemerald.
            .otId = 0, // Handled by CreateMon->CreateBoxMon.
            .conditions = {0, 0, 0, 0, 0},
            .personality = 0, // Handled by CreateMon->CreateBoxMon.
            .heldItem = newHeldItem,
            .mailNum = -1,
            .otName = _("ERROR"),
            .otGender = FEMALE, // Decided by the personality generated in CreateMon->CreateBoxMon.
            .sheen = 0,
            .requestedSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES)
        },
    };
    struct WonderTrade *wonderTrade = &sWonderTrades[0];

    // Creates the base of a Pokémon in the first slot of a nonexistent enemy's party.
    CreateMon(&gEnemyParty[0], wonderTradeSpecies, playerMonLevel, USE_RANDOM_IVS, FALSE, 0, OT_ID_PRESET, ((Random() << 16) | Random()));

    // 10% chance of giving the incoming Pokémon their HA, if they have one
    if (gSpeciesInfo[wonderTradeSpecies].abilities[2] != ABILITY_NONE && (Random() % 99) < 50)
    {
        if ((Random() % 99) < 10)
        {
            abilityNum = 2;
            SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityNum);
        }
    }

    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &newHeldItem);
    SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &wonderTrade->ivs[0]);
    SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &wonderTrade->ivs[1]);
    SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &wonderTrade->ivs[2]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &wonderTrade->ivs[3]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &wonderTrade->ivs[4]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &wonderTrade->ivs[5]);

    StringCopy(monName, GetSpeciesName(wonderTradeSpecies));

    SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, monName);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, otName);
    SetMonData(&gEnemyParty[0], MON_DATA_BEAUTY, &wonderTrade->conditions[1]);
    SetMonData(&gEnemyParty[0], MON_DATA_CUTE, &wonderTrade->conditions[2]);
    SetMonData(&gEnemyParty[0], MON_DATA_COOL, &wonderTrade->conditions[0]);
    SetMonData(&gEnemyParty[0], MON_DATA_SMART, &wonderTrade->conditions[3]);
    SetMonData(&gEnemyParty[0], MON_DATA_TOUGH, &wonderTrade->conditions[4]);
    SetMonData(&gEnemyParty[0], MON_DATA_SHEEN, &wonderTrade->sheen);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_GENDER, &genderOT);
    SetMonData(&gEnemyParty[0], MON_DATA_MET_LOCATION, &metLocation);
    CalculateMonStats(&gEnemyParty[0]);
}
