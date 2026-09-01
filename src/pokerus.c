#include "global.h"
#include "event_data.h"
#include "config_changes.h"
#include "pokemon.h"
#include "pokerus.h"
#include "random.h"
#include "config/pokerus.h"

u32 GetDaysLeftBasedOnStrain(u32 strain)
{
    u32 daysLeft = (strain % 4) + 1;
    return daysLeft;
}

static u32 GetRandomPokerusStrain(void)
{
    if (P_POKERUS_STRAIN_DISTRIBUTION < GEN_3) // Gen 1 - 2 (Gen 1 had no Pokérus but we default it with gen 2)
        return RandomWeighted(RNG_POKERUS_STRAIN_DISTRIBUTION, 15, 30, 30, 30, 30, 30, 30, 30, 30, 1, 1, 1, 1, 1, 1, 1);
    else if (P_POKERUS_STRAIN_DISTRIBUTION < GEN_4) //Gen 3 (Ruby/Sapphire only)
        return RandomWeighted(RNG_POKERUS_STRAIN_DISTRIBUTION, 30, 31, 31, 31, 31, 31, 31, 31, 1, 1, 1, 1, 1, 1, 1, 1);
    else // Gen 4+ (Pokérus was disabled in gen 9 but we default it here)
        return RandomWeighted(RNG_POKERUS_STRAIN_DISTRIBUTION, 0, 31, 31, 31, 31, 31, 31, 31, 0, 1, 1, 1, 1, 1, 1, 1);
}

void RandomlyGivePartyPokerus(void)
{
    if (!GetConfig(POKERUS_ENABLED))
        return;

    if ((GetConfig(POKERUS_INFECT_AGAIN) > GEN_2) && IsPokerusInParty())
        return;

    if (P_POKERUS_FLAG_INFECTION && !FlagGet(P_POKERUS_FLAG_INFECTION))
        return;

    if (RandomUniform(RNG_POKERUS_INFECTION, 0, MAX_u16) < P_POKERUS_INFECTION_ODDS)
    {
        struct Pokemon *mon;
        u32 randomIndex;
        u32 validTargetsCount = 0;
        s32 validTargets[PARTY_SIZE];

        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            mon = &gParties[B_TRAINER_PLAYER][i];
            if (!GetMonData(mon, MON_DATA_SPECIES))
                continue;
            else if (!GetConfig(POKERUS_INFECT_EGG) && GetMonData(mon, MON_DATA_IS_EGG))
                continue;
            else if (!GetConfig(POKERUS_HERD_IMMUNITY) && CheckMonHasHadPokerus(mon))
                continue;
            validTargets[validTargetsCount] = i;
            validTargetsCount++;
        }

        if (validTargetsCount == 0)
            return;

        randomIndex = RandomUniform(RNG_POKERUS_PARTY_MEMBER, 0, validTargetsCount - 1);
        mon = &gParties[B_TRAINER_PLAYER][validTargets[randomIndex]];

        if (!CheckMonHasHadPokerus(mon))
        {
            u32 strain = GetRandomPokerusStrain();
            u32 daysLeft = GetDaysLeftBasedOnStrain(strain);

            SetMonData(mon, MON_DATA_POKERUS_STRAIN, &strain);
            SetMonData(mon, MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
        }
    }
}

bool32 IsPokerusInParty(void)
{
    if (!GetConfig(POKERUS_ENABLED))
        return FALSE;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES))
            continue;

        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_DAYS_LEFT))
            return TRUE;
    }

    return FALSE;
}

bool32 CheckMonPokerus(struct Pokemon *mon)
{
    if (!GetConfig(POKERUS_ENABLED))
        return FALSE;

    if (GetMonData(mon, MON_DATA_POKERUS_DAYS_LEFT))
        return TRUE;

    return FALSE;
}

bool32 CheckMonHasHadPokerus(struct Pokemon *mon)
{
    if (!GetConfig(POKERUS_ENABLED))
        return FALSE;

    if (GetMonData(mon, MON_DATA_POKERUS))
        return TRUE;

    return FALSE;
}

bool32 IsPokerusVisible(struct Pokemon *mon)
{
    if ((P_POKERUS_VISIBLE_ON_EGG >= GEN_3 && P_POKERUS_VISIBLE_ON_EGG <= GEN_6) || !GetMonData(mon, MON_DATA_IS_EGG))
        return TRUE;
    return FALSE;
}

bool32 ShouldPokemonShowActivePokerus(struct Pokemon *mon)
{
    if (!IsPokerusVisible(mon))
        return FALSE;
    return CheckMonPokerus(mon);
}

bool32 ShouldPokemonShowCuredPokerus(struct Pokemon *mon)
{
    if (!IsPokerusVisible(mon))
        return FALSE;
    if (CheckMonPokerus(mon))
        return FALSE;
    return CheckMonHasHadPokerus(mon);
}

void UpdatePartyPokerusTime(u32 days)
{
    if (!GetConfig(POKERUS_ENABLED))
        return;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES))
            continue;

        u32 strain = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_STRAIN);
        u32 daysLeft = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_DAYS_LEFT);
        if (daysLeft)
        {
            if (daysLeft < days)
                daysLeft = 0;
            else
                daysLeft -= days;

            //If the strain was 0, we changed it to 1 when the Pokérus disappear to remember the Pokémon was infected by Pokérus
            // (otherwise its data would look the same as unaffected Pokémon)
            if (daysLeft == 0 && strain == 0)
            {
                strain = 1;
                SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_STRAIN, &strain);
            }

            SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
        }
    }
}

static void SpreadPokerusToSpecificMon(struct Pokemon *mon, u32 strain, u32 daysLeft)
{
    SetMonData(mon, MON_DATA_POKERUS_STRAIN, &strain);
    if (GetConfig(POKERUS_SPREAD_DAYS_LEFT) < GEN_3)
        daysLeft = GetDaysLeftBasedOnStrain(strain);
    SetMonData(mon, MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
}

static bool32 CanReceivePokerusFromSpread(struct Pokemon *mon)
{
    if (GetConfig(POKERUS_WEAK_VARIANT))
        return !GetMonData(mon, MON_DATA_POKERUS_STRAIN);
    return !GetMonData(mon, MON_DATA_POKERUS);
}

void PartySpreadPokerus(void)
{
    if (!GetConfig(POKERUS_ENABLED))
        return;

    if (RandomUniform(RNG_POKERUS_SPREAD, 0, MAX_u16) >= P_POKERUS_SPREAD_ODDS)
        return;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES))
            continue;

        u32 strain = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_STRAIN);
        u32 daysLeft = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_DAYS_LEFT);
        if (daysLeft)
        {
            bool32 spreadUp = TRUE, spreadDown = TRUE;
            if (GetConfig(POKERUS_SPREAD_ADJACENCY) < GEN_3)
            {
                if (i == (gPartiesCount[B_TRAINER_PLAYER] - 1))
                    spreadUp = FALSE;
                else if (RandomUniform(RNG_POKERUS_SPREAD_SIDE, 0, 1))
                    spreadDown = FALSE;
                else
                    spreadUp = FALSE;
            }
            if (spreadDown && i != 0 && CanReceivePokerusFromSpread(&gParties[B_TRAINER_PLAYER][i - 1]))
                SpreadPokerusToSpecificMon(&gParties[B_TRAINER_PLAYER][i - 1], strain, daysLeft);
            if (spreadUp && i != (PARTY_SIZE - 1) && CanReceivePokerusFromSpread(&gParties[B_TRAINER_PLAYER][i + 1]))
            {
                SpreadPokerusToSpecificMon(&gParties[B_TRAINER_PLAYER][i + 1], strain, daysLeft);
                i++;
            }
        }
    }
}
