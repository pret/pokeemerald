#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Octolock")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Foe Wobbuffet can no longer escape because of Octolock!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Defense fell!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Sp. Def fell!");
    }
}

SINGLE_BATTLE_TEST("Octolock 2")
{
    u32 species;
    u32 ability;

    PARAMETRIZE { species = SPECIES_BELDUM; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        if (species == SPECIES_BELDUM)
        {
            MESSAGE("Foe Beldum can no longer escape because of Octolock!");
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
            MESSAGE("Foe Beldum's Clear Body prevents stat loss!");
            NOT MESSAGE("Foe Beldum's Defense fell!");
            NOT MESSAGE("Foe Beldum's Sp. Def fell!");
        }
        else if (species == SPECIES_TORKOAL)
        {
            MESSAGE("Foe Torkoal can no longer escape because of Octolock!");
            ABILITY_POPUP(opponent, ABILITY_WHITE_SMOKE);
            MESSAGE("Foe Torkoal's White Smoke prevents stat loss!");
            NOT MESSAGE("Foe Torkoal's Defense fell!");
            NOT MESSAGE("Foe Torkoal's Sp. Def fell!");
        }
        else if (species == SPECIES_SOLGALEO)
        {
            MESSAGE("Foe Solgaleo can no longer escape because of Octolock!");
            ABILITY_POPUP(opponent, ABILITY_FULL_METAL_BODY);
            MESSAGE("Foe Solgaleo's Full Metal Body prevents stat loss!");
            NOT MESSAGE("Foe Solgaleo's Defense fell!");
            NOT MESSAGE("Foe Solgaleo's Sp. Def fell!");
        }
    }
}

SINGLE_BATTLE_TEST("Octolock 3")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Foe Pidgey can no longer escape because of Octolock!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT MESSAGE("Foe Pidgey's Defense fell!");
        ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
        MESSAGE("Foe Pidgey's Big Pecks prevents stat loss!");
        MESSAGE("Foe Wobbuffet's Sp. Def fell!");
    }
}

SINGLE_BATTLE_TEST("Octolock 4")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Foe Wobbuffet can no longer escape because of Octolock!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT MESSAGE("Foe Wobbuffet's Defense fell!");
        NOT MESSAGE("Foe Wobbuffet's Sp. Def fell!");
    }
}
