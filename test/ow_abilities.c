#include "global.h"
#include "ow_abilities.h"
#include "test/overworld_script.h"
#include "test/test.h"

ASSUMPTIONS
{
    ASSUME(GetSpeciesAbility(SPECIES_PHIONE, 0) == ABILITY_HYDRATION);
    ASSUME(GetSpeciesAbility(SPECIES_CHARMANDER, 0) != ABILITY_HYDRATION);
}

TEST("DoesLeadingMonHaveAbilityEffect returns FALSE if the party is empty")
{
    const enum Ability abilityArray[] = {ABILITY_HYDRATION, ABILITY_DRIZZLE, ABILITY_NONE};
    ZeroPlayerPartyMons();
    EXPECT_EQ(DoesLeadingMonHaveAbilityEffect(abilityArray), FALSE);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PHIONE 100, abilityNum=0;
    );
    EXPECT_EQ(DoesLeadingMonHaveAbilityEffect(abilityArray), TRUE);
}

TEST("DoesLeadingMonHaveAbilityEffect returns FALSE if the first mon in party is an egg")
{
    const enum Ability abilityArray[] = {ABILITY_HYDRATION, ABILITY_DRIZZLE, ABILITY_NONE};
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PHIONE 100, abilityNum=0;
    );
    EXPECT_EQ(DoesLeadingMonHaveAbilityEffect(abilityArray), TRUE);
    bool32 isEgg = TRUE;
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_IS_EGG, &isEgg);
    EXPECT_EQ(DoesLeadingMonHaveAbilityEffect(abilityArray), FALSE);
}

TEST("DoesLeadingMonHaveAbilityEffect returns FALSE if the first mon in party does not have one of the abilities present in the given array")
{
    const enum Ability abilityArray[] = {ABILITY_DRIZZLE, ABILITY_HYDRATION, ABILITY_NONE};
    const enum Ability abilityArray2[] = {ABILITY_STENCH, ABILITY_SPEED_BOOST, ABILITY_NONE};
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PHIONE 100, abilityNum=0;
    );
    EXPECT_EQ(DoesLeadingMonHaveAbilityEffect(abilityArray), TRUE);
    EXPECT_EQ(DoesLeadingMonHaveAbilityEffect(abilityArray2), FALSE);
}

TEST("DoesPartyMemberHaveAbilityEffect returns FALSE if the party is empty")
{
    const enum Ability abilityArray[] = {ABILITY_HYDRATION, ABILITY_DRIZZLE, ABILITY_NONE};
    ZeroPlayerPartyMons();
    EXPECT_EQ(DoesPartyMemberHaveAbilityEffect(abilityArray), FALSE);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_CHARMANDER 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
    );
    EXPECT_EQ(DoesPartyMemberHaveAbilityEffect(abilityArray), TRUE);
}

TEST("DoesPartyMemberHaveAbilityEffect returns FALSE if the ability is owned by an egg")
{
    const enum Ability abilityArray[] = {ABILITY_HYDRATION, ABILITY_DRIZZLE, ABILITY_NONE};
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
    );
    EXPECT_EQ(DoesPartyMemberHaveAbilityEffect(abilityArray), TRUE);
    bool32 isEgg = TRUE;
    for (u32 j = 0; j < 6; j++)
        SetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_IS_EGG, &isEgg);
    EXPECT_EQ(DoesPartyMemberHaveAbilityEffect(abilityArray), FALSE);
}

TEST("DoesPartyMemberHaveAbilityEffect returns FALSE if none of the mons in party have one of the abilities present in the given array")
{
    const enum Ability abilityArray[] = {ABILITY_DRIZZLE, ABILITY_HYDRATION, ABILITY_NONE};
    const enum Ability abilityArray2[] = {ABILITY_STENCH, ABILITY_SPEED_BOOST, ABILITY_NONE};
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
        givemon SPECIES_PHIONE 100, abilityNum=0;
    );
    EXPECT_EQ(DoesPartyMemberHaveAbilityEffect(abilityArray), TRUE);
    EXPECT_EQ(DoesPartyMemberHaveAbilityEffect(abilityArray2), FALSE);
}

TEST("DoesPartyMemberHaveAbilityEffect returns TRUE no matter the party position of the mon with the ability")
{
    const enum Ability abilityArray[] = {ABILITY_DRIZZLE, ABILITY_HYDRATION, ABILITY_NONE};
    u32 partyIndex = 0;
    u32 j;
    for (j = 0; j < 6; j++)
    {
        PARAMETRIZE { partyIndex = j;}
    }
    ZeroPlayerPartyMons();
    for (j = 0; j < 6; j++)
    {
        if (j == partyIndex)
        {
            RUN_OVERWORLD_SCRIPT(
                givemon SPECIES_PHIONE 100, abilityNum=0;
            );
        }
        else
        {
            RUN_OVERWORLD_SCRIPT(
                givemon SPECIES_CHARMANDER 100, abilityNum=0;
            );
        }
    
    }
    EXPECT_EQ(DoesPartyMemberHaveAbilityEffect(abilityArray), TRUE);
}
