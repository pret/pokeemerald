#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flash Fire boosts fire type moves by 50% but no subsequent increase is applied")
{
    s16 damage[3];

    GIVEN {
        PLAYER(SPECIES_HEATRAN) { Ability(ABILITY_FLASH_FIRE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, secondaryEffect: FALSE); MOVE(opponent, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_EMBER, secondaryEffect: FALSE); MOVE(opponent, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_EMBER, secondaryEffect: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ABILITY_POPUP(player, ABILITY_FLASH_FIRE);
        MESSAGE("The power of Heatran's Fire-type moves rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
        ABILITY_POPUP(player, ABILITY_FLASH_FIRE);
        MESSAGE("Heatran made it ineffective!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        HP_BAR(opponent, captureDamage: &damage[2]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], UQ_4_12(1.5), damage[1]);
        EXPECT_EQ(damage[1], damage[2]);
    }
}
