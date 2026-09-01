#include "global.h"
#include "malloc.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokerus.h"
#include "config_changes.h"
#include "random.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "config/pokerus.h"

TEST("(Pokerus) No infection when POKERUS_ENABLED is false")
{
    bool32 enabled;
    PARAMETRIZE { enabled = TRUE; }
    PARAMETRIZE { enabled = FALSE; }
    SetConfig(CONFIG_POKERUS_ENABLED, enabled);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100
    );

    SET_RNG(RNG_POKERUS_INFECTION, 0);

    CalculatePlayerPartyCount();
    RandomlyGivePartyPokerus();

    EXPECT_EQ((GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS) > 0), enabled);
}

TEST("(Pokerus) RandomlyGivePartyPokerus doesn't freeze if the party is empty")
{
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    ZeroPlayerPartyMons();
    SET_RNG(RNG_POKERUS_INFECTION, 0);

    CalculatePlayerPartyCount();
    RandomlyGivePartyPokerus();

    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], 0);
}

TEST("(Pokerus) Eggs can only be infected if POKERUS_INFECT_EGG is TRUE")
{
    bool32 infectEgg;
    PARAMETRIZE { infectEgg = TRUE; }
    PARAMETRIZE { infectEgg = FALSE; }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_INFECT_EGG, infectEgg);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100
    );

    bool32 isEgg = TRUE;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_IS_EGG, &isEgg);

    SET_RNG(RNG_POKERUS_INFECTION, 0);

    CalculatePlayerPartyCount();
    RandomlyGivePartyPokerus();

    EXPECT_EQ((GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS) > 0), infectEgg);
}

TEST("(Pokerus) No infection when POKERUS_INFECT_AGAIN is false and you already have active pokerus in party")
{
    u32 infectAgain;
    PARAMETRIZE { infectAgain = GEN_2; }
    PARAMETRIZE { infectAgain = GEN_3; }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_INFECT_AGAIN, infectAgain);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100;
        givemon SPECIES_PIKACHU, 100;
    );

    u8 pokerus = 1;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &pokerus);

    SET_RNG(RNG_POKERUS_INFECTION, 0);

    CalculatePlayerPartyCount();
    RandomlyGivePartyPokerus();

    EXPECT_EQ((GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS) > 0), infectAgain == GEN_2);
}

TEST("(Pokerus) Test POKERUS_HERD_IMMUNITY config in RandomlyGivePartyPokerus")
{
    u32 herdImmunity;
    PARAMETRIZE { herdImmunity = TRUE; }
    PARAMETRIZE { herdImmunity = FALSE; }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_HERD_IMMUNITY, herdImmunity);
    SetConfig(CONFIG_POKERUS_INFECT_AGAIN, GEN_2);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100;
        givemon SPECIES_PIKACHU, 100;
    );

    u8 pokerus = 1;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &pokerus);

    SET_RNG(RNG_POKERUS_INFECTION, 0);
    SET_RNG(RNG_POKERUS_PARTY_MEMBER, 0);

    CalculatePlayerPartyCount();
    RandomlyGivePartyPokerus();

    EXPECT_EQ((GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS) == 0), herdImmunity);
}

#if P_POKERUS_FLAG_INFECTION
TEST("(Pokerus) No infection when P_POKERUS_FLAG_INFECTION is clear")
{
    u32 flag;
    PARAMETRIZE { flag = TRUE; }
    PARAMETRIZE { flag = FALSE; }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100;
        givemon SPECIES_PIKACHU, 100;
    );

    u8 pokerus = 1;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &pokerus);

    if (flag)
        FlagSet(P_POKERUS_FLAG_INFECTION);
    else
        FlagClear(P_POKERUS_FLAG_INFECTION);

    SET_RNG(RNG_POKERUS_INFECTION, 0);

    CalculatePlayerPartyCount();
    RandomlyGivePartyPokerus();

    EXPECT_EQ((GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS) > 0), flag);
}
#endif

TEST("(Pokerus) Test GetMonData for MON_DATA_POKERUS_DAYS_LEFT and MON_DATA_POKERUS_STRAIN")
{
    u32 strain = 0; 
    u32 daysLeft = 0;
    for (u32 i = 0; i < 16; i++)
    {
        for (u32 j = 0; j < 16; j++)
        {
            PARAMETRIZE { strain = i; daysLeft = j;}
        }
    }

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100;
    );

    u8 pokerus = (strain << 4) | daysLeft;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &pokerus);

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_STRAIN), strain);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_DAYS_LEFT), daysLeft);
}

TEST("(Pokerus) Test SetMonData for MON_DATA_POKERUS_DAYS_LEFT and MON_DATA_POKERUS_STRAIN")
{
    u32 strain = 0; 
    u32 daysLeft = 0;
    for (u32 i = 0; i < 16; i++)
    {
        for (u32 j = 0; j < 16; j++)
        {
            PARAMETRIZE { strain = i; daysLeft = j; }
        }
    }

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100;
    );

    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_STRAIN, &strain);
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);

    u8 pokerus = (strain << 4) | daysLeft;
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS), pokerus);
}

TEST("(Pokerus) Test IsPokerusInParty general behavior")
{
    u32 enabled = 0;
    u32 partyMember = 0;
    u32 pokerus = 0;
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        for (u32 j = 0; j <= MAX_u8; j++)
        {
            if ((j & 0x0F) == 0)
                continue;
            PARAMETRIZE { enabled = TRUE; partyMember = i; pokerus = j; }
            PARAMETRIZE { enabled = FALSE; partyMember = i, pokerus = j; }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, enabled);

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        RUN_OVERWORLD_SCRIPT(
            givemon SPECIES_PIKACHU, 100
        );
    }

    EXPECT_EQ(IsPokerusInParty(), FALSE);

    u32 tmp = pokerus;
    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS, &tmp);

    EXPECT_EQ(IsPokerusInParty(), enabled);
}

TEST("(Pokerus) Test CheckMonPokerus general behavior")
{
    u32 enabled = 0;
    u32 pokerus = 0;
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        for (u32 j = 0; j <= MAX_u8; j++)
        {
            if ((j & 0x0F) == 0)
                continue;
            PARAMETRIZE { enabled = TRUE; pokerus = j; }
            PARAMETRIZE { enabled = FALSE; pokerus = j; }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, enabled);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100
    );

    EXPECT_EQ(CheckMonPokerus(&gParties[B_TRAINER_PLAYER][0]), FALSE);

    u32 tmp = pokerus;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &tmp);

    EXPECT_EQ(CheckMonPokerus(&gParties[B_TRAINER_PLAYER][0]), enabled);
}

TEST("(Pokerus) Test CheckMonHasHadPokerus general behavior")
{
    u32 enabled = 0;
    u32 pokerus = 0;
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        for (u32 j = 1; j <= MAX_u8; j++)
        {
            PARAMETRIZE { enabled = TRUE; pokerus = j; }
            PARAMETRIZE { enabled = FALSE; pokerus = j; }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, enabled);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100
    );


    EXPECT_EQ(CheckMonHasHadPokerus(&gParties[B_TRAINER_PLAYER][0]), FALSE);

    u32 tmp = pokerus;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &tmp);

    EXPECT_EQ(CheckMonHasHadPokerus(&gParties[B_TRAINER_PLAYER][0]), enabled);
}

TEST("(Pokerus) Test UpdatePartyPokerusTime general behavior")
{
    u32 enabled = 0;
    u32 strain = 0; 
    s32 daysLeft = 0;
    s32 daysPassed = 0;
    for (u32 i = 0; i < 16; i++)
    {
        for (u32 j = 0; j < 16; j++)
        {
            for (u32 k = 1; k < 4; k++)
            {
                PARAMETRIZE { enabled = TRUE; strain = i; daysLeft = j; daysPassed = k; }
                PARAMETRIZE { enabled = FALSE; strain = i; daysLeft = j; daysPassed = k; }
            }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, enabled);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100
    );


    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_STRAIN, &strain);
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
    UpdatePartyPokerusTime(daysPassed);

    if (enabled)
    {
        if (   (strain == 0) //Verify strain 0 is modified to strain 1 when timer is up
            && (daysLeft > 0)
            && ((daysLeft - daysPassed) <= 0)
           )
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_STRAIN), 1);
        else
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_STRAIN), strain);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_DAYS_LEFT), max(0, daysLeft - daysPassed));
    } 
    else
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_STRAIN), strain);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS_DAYS_LEFT), daysLeft);
    }
}


TEST("(Pokerus) Test PartySpreadPokerus general behavior")
{
    u32 partyMember = 0;
    u32 pokerus = 0;
    for (u32 i = 0; i <= MAX_u8; i++)
    {
        if ((i & 0x0F) == 0)
            continue;
        for (u32 k = 0; k < PARTY_SIZE; k++)
        {
            PARAMETRIZE {pokerus = i; partyMember = k;}
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_SPREAD_DAYS_LEFT, GEN_3);
    SetConfig(CONFIG_POKERUS_SPREAD_ADJACENCY, GEN_3);

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        RUN_OVERWORLD_SCRIPT(
            givemon SPECIES_PIKACHU, 100
        );
    }

    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS, &pokerus);
    SET_RNG(RNG_POKERUS_SPREAD, 0);
    PartySpreadPokerus();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS), pokerus);
    if (partyMember == 0)
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS), pokerus);
        for (u32 i = 2; i < PARTY_SIZE; i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);

    }
    else if (partyMember == PARTY_SIZE - 1)
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][PARTY_SIZE - 2], MON_DATA_POKERUS), pokerus);
        for (u32 i = 0; i < (PARTY_SIZE - 2); i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
    }
    else
    {
        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            if ((i < (partyMember - 1)) || (i > (partyMember + 1)))
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
            else
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), pokerus);
        }
    }
}

TEST("(Pokerus) Test PartySpreadPokerus: Pokerus can spread to and from eggs")
{
    u32 partyMember = 0;
    u32 pokerus = 0;
    for (u32 i = 0; i <= MAX_u8; i++)
    {
        if ((i & 0x0F) == 0)
            continue;
        for (u32 k = 0; k < PARTY_SIZE; k++)
        {
            PARAMETRIZE {pokerus = i; partyMember = k;}
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_SPREAD_DAYS_LEFT, GEN_3);
    SetConfig(CONFIG_POKERUS_SPREAD_ADJACENCY, GEN_3);

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        RUN_OVERWORLD_SCRIPT(
            givemon SPECIES_PIKACHU, 100
        );
        bool32 isEgg = TRUE;
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_IS_EGG, &isEgg);
    }

    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS, &pokerus);
    SET_RNG(RNG_POKERUS_SPREAD, 0);
    PartySpreadPokerus();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS), pokerus);
    if (partyMember == 0)
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS), pokerus);
        for (u32 i = 2; i < PARTY_SIZE; i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);

    }
    else if (partyMember == PARTY_SIZE - 1)
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][PARTY_SIZE - 2], MON_DATA_POKERUS), pokerus);
        for (u32 i = 0; i < (PARTY_SIZE - 2); i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
    }
    else
    {
        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            if ((i < (partyMember - 1)) || (i > (partyMember + 1)))
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
            else
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), pokerus);
        }
    }
}

TEST("(Pokerus) Test PartySpreadPokerus: do not spread inactive pokerus")
{
    u32 partyMember = 0;
    u32 pokerus = 0;
    for (u32 i = 0; i <= MAX_u8; i++)
    {
        if (i & 0x0F)
            continue;
        for (u32 k = 0; k < PARTY_SIZE; k++)
        {
            PARAMETRIZE { pokerus = i; partyMember = k; }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        RUN_OVERWORLD_SCRIPT(
            givemon SPECIES_PIKACHU, 100
        );
    }

    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS, &pokerus);
    SET_RNG(RNG_POKERUS_SPREAD, 0);

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS), pokerus);
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (i != partyMember)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
    }
}


TEST("(Pokerus) Test PartySpreadPokerus: do not spread if POKERUS_ENABLED is false")
{
    u32 partyMember = 0;
    u32 pokerus = 0;
    for (u32 i = 0; i <= MAX_u8; i++)
    {
        for (u32 k = 0; k < PARTY_SIZE; k++)
        {
            PARAMETRIZE { pokerus = i; partyMember = k; }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, FALSE);

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        RUN_OVERWORLD_SCRIPT(
            givemon SPECIES_PIKACHU, 100
        );
    }

    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS, &pokerus);
    SET_RNG(RNG_POKERUS_SPREAD, 0);
    PartySpreadPokerus();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS), pokerus);
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (i != partyMember)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
    }
}

TEST("(Pokerus) Test PartySpreadPokerus: do not spread to pokemon who got pokerus before")
{
    u32 pokerus1 = 0;
    u32 pokerus2 = 0;
    for (u32 i = 1; i < 16; i++)
    {
        for (u32 j = 1; j < 16; j++)
        {
            PARAMETRIZE { pokerus1 = ((i << 4) | 1); pokerus2 = ((j << 4) | 0); }
            PARAMETRIZE { pokerus1 = ((i << 4) | 2); pokerus2 = ((j << 4) | 1); }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100;
        givemon SPECIES_PIKACHU, 100;
    );

    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &pokerus1);
    SetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS, &pokerus2);
    SET_RNG(RNG_POKERUS_SPREAD, 0);
    PartySpreadPokerus();

    EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS), GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS));
}

TEST("(Pokerus) Test PartySpreadPokerus: strain 0 can be spread to if POKERUS_WEAK_VARIANT is true")
{
    u32 weakVariant = 0;
    u32 pokerus2 = 0;
    for (u32 i = 2; i <= MAX_u8; i++)
    {
        if ((i & 0x0F) == 0)
            continue;
        PARAMETRIZE { weakVariant = TRUE; pokerus2 = i; }
        PARAMETRIZE { weakVariant = FALSE; pokerus2 = i; }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_WEAK_VARIANT, weakVariant);

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PIKACHU, 100;
        givemon SPECIES_PIKACHU, 100;
    );

    u32 pokerus1 = 1;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS, &pokerus1);
    SetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS, &pokerus2);
    SET_RNG(RNG_POKERUS_SPREAD, 0);
    PartySpreadPokerus();

    if (weakVariant)
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS), GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS));
    else
        EXPECT_NE(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_POKERUS), GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS));
}

TEST("(Pokerus) Test PartySpreadPokerus when POKERUS_SPREAD_DAYS_LEFT is set to GEN2")
{
    u32 partyMember = 0;
    u32 strain = 0;
    u32 daysLeft = 0;
    for (u32 i = 0; i < 16; i++)
    {
        for (u32 j = 1; j < 16; j++)
        {
            for (u32 k = 0; k < PARTY_SIZE; k++)
            {
                PARAMETRIZE {strain = i; daysLeft = j; partyMember = k;}
            }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_SPREAD_DAYS_LEFT, GEN_2);
    SetConfig(CONFIG_POKERUS_SPREAD_ADJACENCY, GEN_3);

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        RUN_OVERWORLD_SCRIPT(
            givemon SPECIES_PIKACHU, 100
        );
    }

    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS_STRAIN, &strain);
    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS_DAYS_LEFT, &daysLeft);
    SET_RNG(RNG_POKERUS_SPREAD, 0);
    PartySpreadPokerus();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS_STRAIN), strain);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS_DAYS_LEFT), daysLeft);
    if (partyMember == 0)
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS_STRAIN), strain);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS_DAYS_LEFT), GetDaysLeftBasedOnStrain(strain));
        for (u32 i = 2; i < PARTY_SIZE; i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);

    }
    else if (partyMember == PARTY_SIZE - 1)
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][PARTY_SIZE - 2], MON_DATA_POKERUS_STRAIN), strain);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][PARTY_SIZE - 2], MON_DATA_POKERUS_DAYS_LEFT), GetDaysLeftBasedOnStrain(strain));
        for (u32 i = 0; i < (PARTY_SIZE - 2); i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
    }
    else
    {
        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            if ((i < (partyMember - 1)) || (i > (partyMember + 1)))
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
            else if (i != partyMember)
            {
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_STRAIN), strain);
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS_DAYS_LEFT), GetDaysLeftBasedOnStrain(strain));
            }
        }
    }
}

TEST("(Pokerus) Test PartySpreadPokerus using gen2 adjacency")
{
    u32 partyMember = 0;
    u32 pokerus = 0;
    u32 spreadUp = 0; //spread in ascending order of party index
    for (u32 i = 0; i <= MAX_u8; i++)
    {
        if ((i & 0x0F) == 0)
            continue;
        for (u32 k = 0; k < PARTY_SIZE; k++)
        {
            PARAMETRIZE { pokerus = i; partyMember = k; spreadUp = TRUE; }
            PARAMETRIZE { pokerus = i; partyMember = k; spreadUp = FALSE; }
        }
    }
    SetConfig(CONFIG_POKERUS_ENABLED, TRUE);
    SetConfig(CONFIG_POKERUS_SPREAD_DAYS_LEFT, GEN_3);
    SetConfig(CONFIG_POKERUS_SPREAD_ADJACENCY, GEN_2);

    ZeroPlayerPartyMons();
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        RUN_OVERWORLD_SCRIPT(
            givemon SPECIES_PIKACHU, 100
        );
    }

    SetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS, &pokerus);

    SET_RNG(RNG_POKERUS_SPREAD, 0);
    SET_RNG(RNG_POKERUS_SPREAD_SIDE, spreadUp);

    PartySpreadPokerus();

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][partyMember], MON_DATA_POKERUS), pokerus);
    if (partyMember == 0)
    {
        if (spreadUp)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS), pokerus);
        else
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKERUS), 0);
        for (u32 i = 2; i < PARTY_SIZE; i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);

    }
    else if (partyMember == PARTY_SIZE - 1)
    {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][PARTY_SIZE - 2], MON_DATA_POKERUS), pokerus);
        for (u32 i = 0; i < (PARTY_SIZE - 2); i++)
            EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
    }
    else
    {
        for (u32 i = 0; i < PARTY_SIZE; i++)
        {
            if (!spreadUp && (i == (partyMember - 1)))
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), pokerus);
            else if (spreadUp && (i == (partyMember + 1)))
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), pokerus);
            else if (i != partyMember)
                EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_POKERUS), 0);
        }
    }
}
