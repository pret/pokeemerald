#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_POWDER_SNOW].effect == EFFECT_FREEZE_HIT);
    ASSUME(gBattleMoves[MOVE_BLIZZARD].accuracy == 70);
}

SINGLE_BATTLE_TEST("Powder Snow inflicts freeze")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWDER_SNOW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER_SNOW, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, opponent);
        STATUS_ICON(opponent, freeze: TRUE);
    }
}

SINGLE_BATTLE_TEST("Powder Snow cannot freeze an Ice-type Pokémon")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SNORUNT].types[0] == TYPE_ICE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNORUNT);
    } WHEN {
        TURN { MOVE(player, MOVE_POWDER_SNOW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER_SNOW, player);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_FRZ, opponent);
            STATUS_ICON(opponent, freeze: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Freeze cannot be inflicted in Sunlight")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_ICE_BEAM); }
    } SCENE {
        NOT MESSAGE("Wobbuffet was frozen solid!");
    }
}

SINGLE_BATTLE_TEST("Blizzard bypasses accuracy checks in Hail and Snow")
{
    u32 move;
    PARAMETRIZE { move = MOVE_HAIL; }
    PARAMETRIZE { move = MOVE_SNOWSCAPE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_BLIZZARD); }
    } SCENE {
        NOT MESSAGE("Wobbuffet's attack missed!");
    }
}
