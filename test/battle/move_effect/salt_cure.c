#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_SALT_CURE].effect == EFFECT_SALT_CURE);
}

SINGLE_BATTLE_TEST("Salt Cure inflicts 1/8 of the target's maximum HP as damage per turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SALT_CURE); }
        for (i = 0; i < 3; i++)
            TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SALT_CURE, player);
        MESSAGE("Foe Wobbuffet is being salt cured!");
        for (i = 0; i < 4; i++) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SALT_CURE_DAMAGE, opponent);
            HP_BAR(opponent, damage: maxHP / 8);
            MESSAGE("Foe Wobbuffet is hurt by Salt Cure!");
        }
    }
}

SINGLE_BATTLE_TEST("Salt Cure inflicts 1/4 to Water/Steel types of their maximum HP as damage per turn")
{
    u32 species;

    PARAMETRIZE { species = SPECIES_LAPRAS; };
    PARAMETRIZE { species = SPECIES_JIRACHI; };

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species);
    } WHEN {
        TURN { MOVE(player, MOVE_SALT_CURE); }
        TURN {}
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SALT_CURE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SALT_CURE_DAMAGE, opponent);
        HP_BAR(opponent, damage: maxHP / 4);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SALT_CURE_DAMAGE, opponent);
        HP_BAR(opponent, damage: maxHP / 4);
    }
}

SINGLE_BATTLE_TEST("Salt Cure is removed when the afflicted Pokémon is switched out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_SALT_CURE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SALT_CURE, player);
        MESSAGE("Foe Wobbuffet is being salt cured!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SALT_CURE_DAMAGE, opponent);
        MESSAGE("Foe Wobbuffet is hurt by Salt Cure!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SALT_CURE_DAMAGE, opponent);
            MESSAGE("Foe Wobbuffet is hurt by Salt Cure!");
        }
    }
}
