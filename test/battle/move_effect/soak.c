#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SOAK) == EFFECT_SOAK);
    ASSUME(GetMoveEffect(MOVE_MAGIC_POWDER) == EFFECT_SOAK);
}

TO_DO_BATTLE_TEST("Soak/Magic Powder changes the target's type to pure Water/Psychic");

SINGLE_BATTLE_TEST("Soak/Magic Powder's type change is overwitten if the target changes form")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SOAK; }
    PARAMETRIZE { move = MOVE_MAGIC_POWDER; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        // Turn 1
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        switch (move) {
            case MOVE_SOAK:         MESSAGE("Mimikyu transformed into the Water type!"); break;
            case MOVE_MAGIC_POWDER: MESSAGE("Mimikyu transformed into the Psychic type!"); break;
            default: break;
        }
        // Turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        NOT MESSAGE("It doesn't affect Mimikyu…");
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        // Turn 3
        MESSAGE("It doesn't affect Mimikyu…");
    }
}

TO_DO_BATTLE_TEST("Soak/Magic Powder's type change overritten if the target transforms");
TO_DO_BATTLE_TEST("(TERA) Soak/Magic Powder's type change overritten if the target Terastalizes");
TO_DO_BATTLE_TEST("Soak/Magic Powder fails if the target is behind a Substitute");
TO_DO_BATTLE_TEST("Soak/Magic Powder fails if the target is already Water/Psychic");
TO_DO_BATTLE_TEST("Soak/Magic Powder fails if the target has Multitype or RKS System");
