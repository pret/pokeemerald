#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Burmy changes form based on the environment it appeared in-battle")
{
    u32 currentForm = 0, newForm = 0, environment = 0;

    static u32 sBurmyForms[] = {
        SPECIES_BURMY_PLANT,
        SPECIES_BURMY_SANDY,
        SPECIES_BURMY_TRASH,
    };

    for (u32 j = 0; j < ARRAY_COUNT(sBurmyForms); j++) {
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_PLANT; environment = BATTLE_ENVIRONMENT_GRASS; }
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_PLANT; environment = BATTLE_ENVIRONMENT_LONG_GRASS; }
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_PLANT; environment = BATTLE_ENVIRONMENT_POND; }
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_PLANT; environment = BATTLE_ENVIRONMENT_MOUNTAIN; }
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_PLANT; environment = BATTLE_ENVIRONMENT_PLAIN; }
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_SANDY; environment = BATTLE_ENVIRONMENT_CAVE; }
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_SANDY; environment = BATTLE_ENVIRONMENT_SAND; }
        PARAMETRIZE { currentForm = sBurmyForms[j]; newForm = SPECIES_BURMY_TRASH; environment = BATTLE_ENVIRONMENT_BUILDING; }
    }
    GIVEN {
        PLAYER(currentForm);
        OPPONENT(SPECIES_WOBBUFFET);
        Environment(environment);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), newForm);
    }
}
