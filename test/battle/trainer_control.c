#include "global.h"
#include "test/test.h"
#include "battle.h"
#include "battle_main.h"
#include "data.h"
#include "malloc.h"
#include "random.h"
#include "string_util.h"
#include "constants/item.h"
#include "constants/abilities.h"
#include "constants/trainers.h"
#include "constants/battle.h"

static const struct Trainer sTestTrainers[] =
{
#include "trainer_control.h"
};

TEST("CreateNPCTrainerPartyForTrainer generates customized Pokémon")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u8 nickBuffer[20];
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[0], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(IsMonShiny(&testParty[0]));
    EXPECT(!IsMonShiny(&testParty[1]));

    EXPECT(GetMonData(&testParty[0], MON_DATA_POKEBALL, 0) == ITEM_MASTER_BALL);
    EXPECT(GetMonData(&testParty[1], MON_DATA_POKEBALL, 0) == ITEM_POKE_BALL);

    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES, 0) == SPECIES_WOBBUFFET);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPECIES, 0) == SPECIES_WOBBUFFET);

    EXPECT(GetMonAbility(&testParty[0]) == ABILITY_TELEPATHY);
    EXPECT(GetMonAbility(&testParty[1]) == ABILITY_SHADOW_TAG);
    EXPECT(GetMonAbility(&testParty[2]) == ABILITY_SHADOW_TAG);

    EXPECT(GetMonData(&testParty[0], MON_DATA_FRIENDSHIP, 0) == 42);
    EXPECT(GetMonData(&testParty[1], MON_DATA_FRIENDSHIP, 0) == 0);

    EXPECT(GetMonData(&testParty[0], MON_DATA_HELD_ITEM, 0) == ITEM_ASSAULT_VEST);
    EXPECT(GetMonData(&testParty[1], MON_DATA_HELD_ITEM, 0) == ITEM_NONE);

    EXPECT(GetMonData(&testParty[0], MON_DATA_HP_IV, 0) == 25);
    EXPECT(GetMonData(&testParty[0], MON_DATA_ATK_IV, 0) == 26);
    EXPECT(GetMonData(&testParty[0], MON_DATA_DEF_IV, 0) == 27);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPEED_IV, 0) == 28);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPATK_IV, 0) == 29);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPDEF_IV, 0) == 30);

    EXPECT(GetMonData(&testParty[1], MON_DATA_HP_IV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_ATK_IV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_DEF_IV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPEED_IV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPATK_IV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPDEF_IV, 0) == 0);

    EXPECT(GetMonData(&testParty[0], MON_DATA_HP_EV, 0) == 252);
    EXPECT(GetMonData(&testParty[0], MON_DATA_ATK_EV, 0) == 0);
    EXPECT(GetMonData(&testParty[0], MON_DATA_DEF_EV, 0) == 0);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPEED_EV, 0) == 252);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPATK_EV, 0) == 4);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPDEF_EV, 0) == 0);

    EXPECT(GetMonData(&testParty[1], MON_DATA_HP_EV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_ATK_EV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_DEF_EV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPEED_EV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPATK_EV, 0) == 0);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPDEF_EV, 0) == 0);

    EXPECT(GetMonData(&testParty[0], MON_DATA_LEVEL, 0) == 67);
    EXPECT(GetMonData(&testParty[1], MON_DATA_LEVEL, 0) == 5);

    EXPECT(GetMonData(&testParty[0], MON_DATA_MOVE1, 0) == MOVE_AIR_SLASH);
    EXPECT(GetMonData(&testParty[0], MON_DATA_MOVE2, 0) == MOVE_BARRIER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_MOVE3, 0) == MOVE_SOLAR_BEAM);
    EXPECT(GetMonData(&testParty[0], MON_DATA_MOVE4, 0) == MOVE_EXPLOSION);

    GetMonData(&testParty[0], MON_DATA_NICKNAME, nickBuffer);
    EXPECT(StringCompare(nickBuffer, COMPOUND_STRING("Bubbles")) == 0);

    GetMonData(&testParty[1], MON_DATA_NICKNAME, nickBuffer);
    EXPECT(StringCompare(nickBuffer, COMPOUND_STRING("Wobbuffet")) == 0);

    EXPECT(GetMonGender(&testParty[0]) == MON_FEMALE);
    EXPECT(GetNature(&testParty[0]) == NATURE_HASTY);
    EXPECT(GetNature(&testParty[1]) == NATURE_HARDY);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_DYNAMAX_LEVEL), 5);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_DYNAMAX_LEVEL), 10);

    Free(testParty);
}

TEST("CreateNPCTrainerPartyForTrainer generates different personalities for different mons")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[0], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(testParty[0].box.personality != testParty[1].box.personality);
    Free(testParty);
}

TEST("ModifyPersonalityForNature can set any nature")
{
    u32 personality = 0, nature = 0, j = 0, k = 0;
    for (j = 0; j < 64; j++)
    {
        for (k = 0; k < NUM_NATURES; k++)
        {
            PARAMETRIZE { personality = Random32(); nature = k; }
        }
    }
    ModifyPersonalityForNature(&personality, nature);
    EXPECT_EQ(GetNatureFromPersonality(personality), nature);
}

static const struct TrainerMon sTestParty2[] =
{
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
};

static const struct Trainer sTestTrainer2 =
{
    .trainerName = _("Test2"),
    .trainerClass = TRAINER_CLASS_BLACK_BELT,
    .party = TRAINER_PARTY(sTestParty2),
};

TEST("Trainer Class Balls apply to the entire party")
{
    u32 j;
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainer2, TRUE, BATTLE_TYPE_TRAINER);
    for(j = 0; j < 6; j++)
    {
        EXPECT(GetMonData(&testParty[j], MON_DATA_POKEBALL, 0) == gTrainerClasses[sTestTrainer2.trainerClass].ball);
    }
    Free(testParty);
}
