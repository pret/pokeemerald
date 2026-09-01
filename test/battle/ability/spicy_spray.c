#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Spicy Spray burns the attacker")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        STATUS_ICON(player, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Spicy Spray burns the attacker even if the attacker is behind a Substitute")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_SUBSTITUTE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        STATUS_ICON(player, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Spicy Spray does not burn the attacker if the defender is behind a Substitute")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_SWIFT; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(!MoveMakesContact(MOVE_SWIFT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE, gimmick: GIMMICK_MEGA); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
            STATUS_ICON(player, burn: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Spicy Spray burns the attacker even if the attacker has Sheer Force")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CRUNCH; }
    PARAMETRIZE { move = MOVE_ICE_BEAM; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_CRUNCH));
        ASSUME(!MoveMakesContact(MOVE_ICE_BEAM));
        PLAYER(SPECIES_FERALIGATR) { Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        STATUS_ICON(player, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Spicy Spray burns the attacker even if the defender faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        STATUS_ICON(player, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Spicy Spray burns the attacker even if the defender behind a Substitute takes damage")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
        STATUS_ICON(player, burn: TRUE);
    }
}

SINGLE_BATTLE_TEST("Spicy Spray does not activate if Future Sight attacker is not on the field")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FUTURE_SIGHT) == EFFECT_FUTURE_SIGHT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SCOVILLAIN) { Item(ITEM_SCOVILLAINITE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(player, MOVE_FUTURE_SIGHT); }
        TURN { SWITCH(player, 1); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_SPICY_SPRAY);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
            STATUS_ICON(player, burn: TRUE);
        }
    }
}
