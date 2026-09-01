#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_PSYCHIC_NOISE, MOVE_EFFECT_PSYCHIC_NOISE));
    ASSUME(GetMoveEffect(MOVE_RECOVER) == EFFECT_RESTORE_HP);
}

SINGLE_BATTLE_TEST("Psychic Noise blocks healing moves for 2 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_NOISE); MOVE(opponent, MOVE_RECOVER); }
        TURN { MOVE(opponent, MOVE_RECOVER, allowed: FALSE); }
        TURN { MOVE(opponent, MOVE_RECOVER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_NOISE, player);
        MESSAGE("The opposing Wobbuffet was prevented from healing!");
        MESSAGE("The opposing Wobbuffet was prevented from healing!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, opponent);
        MESSAGE("The opposing Wobbuffet is no longer prevented from healing!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, opponent);
    }
}

SINGLE_BATTLE_TEST("Psychic Noise is blocked by Soundproof")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB) { HP(1); Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_NOISE); MOVE(opponent, MOVE_RECOVER); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SOUNDPROOF);
        MESSAGE("It doesn't affect the opposing Voltorb…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, opponent);
    }
}

SINGLE_BATTLE_TEST("Psychic Noise heal block effect is blocked by Aroma Veil")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MILCERY) { Ability(ABILITY_AROMA_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_NOISE); MOVE(opponent, MOVE_RECOVER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_NOISE, player);
        ABILITY_POPUP(opponent, ABILITY_AROMA_VEIL);
        MESSAGE("The opposing Milcery is protected by an aromatic veil!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, opponent);
    }
}

DOUBLE_BATTLE_TEST("Psychic Noise heal block effect is blocked by partners Aroma Veil in doubles")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MILCERY) { Ability(ABILITY_AROMA_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PSYCHIC_NOISE, target: opponentLeft); MOVE(opponentLeft, MOVE_RECOVER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_NOISE, playerLeft);
        ABILITY_POPUP(opponentRight, ABILITY_AROMA_VEIL);
        MESSAGE("The opposing Wobbuffet is protected by an aromatic veil!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RECOVER, opponentLeft);
    }
}
