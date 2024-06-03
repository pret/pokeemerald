#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Battle Message: Send-in message depends on foe HP")
{
    u32 hp;

    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); MaxHP(100); }
    } WHEN {
        TURN { SWITCH(player, 1);  }
    } SCENE {
        if (hp > 69)
            MESSAGE("Go! Wynaut!");
        else if (hp > 39)
            MESSAGE("Do it! Wynaut!");
        else if (hp > 9)
            MESSAGE("Go for it, Wynaut!");
        else
            MESSAGE("Your foe's weak! Get 'em, Wynaut!");
    }
}

TO_DO_BATTLE_TEST("Battle Message: Switch-out message changes based on conditions")
/*{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1);  }
    } SCENE {
        if (???)
            MESSAGE("Wynaut, that's enough! Come back!");
        else if (???)
            MESSAGE("Wynaut, come back!");
        else if (???)
            MESSAGE("Wynaut, OK! Come back!");
        else
            MESSAGE("Wynaut, good! Come back!");
    }
}*/
