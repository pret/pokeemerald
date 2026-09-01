#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_WEAKNESS_POLICY) == HOLD_EFFECT_WEAKNESS_POLICY);
}

SINGLE_BATTLE_TEST("Weakness Policy does not activate if Disguise blocks the damage")
{
    enum Species species;

    PARAMETRIZE { species = SPECIES_MIMIKYU_BUSTED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_METAL_CLAW) == TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Item(ITEM_WEAKNESS_POLICY); Ability(ABILITY_DISGUISE); }
    } WHEN {
        TURN { MOVE(player, MOVE_METAL_CLAW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_CLAW, player);
        if (species == SPECIES_MIMIKYU_BUSTED)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        else
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Weakness Policy (Hold Effect) test titles")
