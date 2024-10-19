#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_REVIVAL_BLESSING].effect == EFFECT_REVIVAL_BLESSING);
}

SINGLE_BATTLE_TEST("Revival Blessing revives a chosen fainted party member for the player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING, partyIndex:2); }
    } SCENE {
        MESSAGE("Wobbuffet used Revival Blessing!");
        MESSAGE("Wynaut was revived and is ready to fight again!");
    }
}

SINGLE_BATTLE_TEST("Revival Blessing revives a fainted party member for an opponent")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU);
        OPPONENT(SPECIES_PICHU) { HP(0); }
        OPPONENT(SPECIES_PIKACHU) { HP(0); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_REVIVAL_BLESSING, partyIndex:1); }
    } SCENE {
        MESSAGE("Foe Raichu used Revival Blessing!");
        MESSAGE("Pichu was revived and is ready to fight again!");
    }
}

SINGLE_BATTLE_TEST("Revival Blessing fails if no party members are fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING); }
    } SCENE {
        MESSAGE("Wobbuffet used Revival Blessing!");
        MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("Revival Blessing cannot revive a partner's party member")
{
    KNOWN_FAILING;
    struct BattlePokemon *user = NULL;
    gBattleTypeFlags |= BATTLE_TYPE_TWO_OPPONENTS;
    PARAMETRIZE { user = opponentLeft; }
    PARAMETRIZE { user = opponentRight; }
    GIVEN {
        ASSUME((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) != FALSE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(user, MOVE_REVIVAL_BLESSING, partyIndex:4); }
    } SCENE {
        if (user == opponentLeft) {
            MESSAGE("Foe Wobbuffet used Revival Blessing!");
            MESSAGE("But it failed!");
        } else {
            MESSAGE("Foe Wynaut used Revival Blessing!");
            MESSAGE("Wynaut was revived and is ready to fight again!");
        }
    }
}

DOUBLE_BATTLE_TEST("Revival Blessing doesn't prevent revived battlers from losing their turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentRight);
               MOVE(opponentLeft, MOVE_REVIVAL_BLESSING, partyIndex: 1); }
    } SCENE {
        MESSAGE("Wobbuffet used Tackle!");
        MESSAGE("Foe Wynaut fainted!");
        MESSAGE("Foe Wobbuffet used Revival Blessing!");
        MESSAGE("Wynaut was revived and is ready to fight again!");
        NOT { MESSAGE("Wynaut used Celebrate!"); }
    }
}

DOUBLE_BATTLE_TEST("Revival Blessing correctly updates battler absent flags")
{
    GIVEN {
        PLAYER(SPECIES_SALAMENCE) { Level(40); }
        PLAYER(SPECIES_PIDGEOT) { Level(40); }
        OPPONENT(SPECIES_GEODUDE) { Level(5); Ability(ABILITY_ROCK_HEAD); }
        OPPONENT(SPECIES_STARLY) { Level(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE);
               MOVE(opponentRight, MOVE_REVIVAL_BLESSING, partyIndex: 0); }
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        // Turn 1
        MESSAGE("Salamence used Earthquake!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Geodude fainted!");
        MESSAGE("It doesn't affect Pidgeot…");
        MESSAGE("It doesn't affect Foe Starly…");
        MESSAGE("Foe Starly used Revival Blessing!");
        MESSAGE("Geodude was revived and is ready to fight again!"); // Should have prefix but it doesn't currently.
        // Turn 2
        MESSAGE("Salamence used Earthquake!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Geodude fainted!");
        MESSAGE("It doesn't affect Pidgeot…");
        MESSAGE("It doesn't affect Foe Starly…");
    }
}
