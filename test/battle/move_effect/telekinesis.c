#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_TELEKINESIS].effect == EFFECT_TELEKINESIS);
}

SINGLE_BATTLE_TEST("Telekinesis makes the target unable to avoid any attacks made against it")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MINIMIZE].effect == EFFECT_MINIMIZE); // Raises evs by 2
        ASSUME(gBattleMoves[MOVE_SCREECH].accuracy < 100);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); MOVE(opponent, MOVE_MINIMIZE); }
        TURN { MOVE(player, MOVE_SCREECH, hit:FALSE); }
    } SCENE {
        MESSAGE("Wobbuffet used Telekinesis!");
        MESSAGE("Foe Wynaut was hurled into the air!");
        MESSAGE("Foe Wynaut used Minimize!");
        MESSAGE("Wobbuffet used Screech!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
        NOT MESSAGE("Wobbuffet's attack missed!");
    }
}

SINGLE_BATTLE_TEST("Telekinesis ends after 3 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN { }
        TURN { }
    } SCENE {
        MESSAGE("Wobbuffet used Telekinesis!");
        MESSAGE("Foe Wynaut was hurled into the air!");
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("Foe Wynaut was freed from the telekinesis!");
    }
}

SINGLE_BATTLE_TEST("Telekinesis makes the target immune to Ground-type attacks")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_BULLDOZE].type == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLDOZE); }
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN { MOVE(player, MOVE_BULLDOZE); }
    } SCENE {
        MESSAGE("Wobbuffet used Bulldoze!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, player);
        HP_BAR(opponent);
        MESSAGE("Wobbuffet used Telekinesis!");
        MESSAGE("Foe Wynaut was hurled into the air!");
        MESSAGE("Wobbuffet used Bulldoze!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, player);
            HP_BAR(opponent);
        }
        MESSAGE("It doesn't affect Foe Wynaut…");
    }
}
