#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aftermath damages the attacker by 1/4th of its max HP if fainted by a contact move")
{
    s16 aftermathDamage;

    GIVEN {
        PLAYER(SPECIES_VOLTORB) { HP(1); Ability(ABILITY_AFTERMATH); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {MOVE(opponent, MOVE_TACKLE);}
    } SCENE {
        MESSAGE("Foe Wobbuffet used Tackle!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        MESSAGE("Voltorb fainted!");
        ABILITY_POPUP(player, ABILITY_AFTERMATH);
        HP_BAR(opponent, captureDamage: &aftermathDamage);
    } THEN {
        EXPECT_EQ(aftermathDamage, opponent->maxHP / 4);
    }
}
