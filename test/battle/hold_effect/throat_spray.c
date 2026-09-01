#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_THROAT_SPRAY) == HOLD_EFFECT_THROAT_SPRAY);
}

DOUBLE_BATTLE_TEST("Throat Spray activates after both hits of a spread move")
{
    s16 firstHit, secondHit;

    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE) == TRUE);
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &firstHit);
        HP_BAR(opponentRight, captureDamage: &secondHit);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
    } THEN {
        EXPECT_EQ(firstHit, secondHit);
    }
}

DOUBLE_BATTLE_TEST("Throat Spray activates after both hits of a spread move, even if one foe protects")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_BOOMBURST) == TRUE);
        ASSUME(GetMoveTarget(MOVE_BOOMBURST) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BOOMBURST); MOVE(opponentRight, MOVE_PROTECT);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BOOMBURST, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Throat Spray does not activate if both foes take no damage from a move that targets both")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE) == TRUE);
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SOUNDPROOF); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE);}
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
	}
    }
}

SINGLE_BATTLE_TEST("Throat Spray increases Sp. Atk by one stage")
{
    s16 normalHit;
    s16 boostedHit;

    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_VOICE); }
        TURN { MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, player);
        HP_BAR(opponent, captureDamage: &normalHit);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, player);
        HP_BAR(opponent, captureDamage: &boostedHit);
    } THEN {
        EXPECT_MUL_EQ(normalHit, Q_4_12(1.5), boostedHit);
    }
}

SINGLE_BATTLE_TEST("Throat Spray activates when a sound move is used")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SWIFT; }
    PARAMETRIZE { move = MOVE_HOWL; }
    PARAMETRIZE { move = MOVE_ECHOED_VOICE; }

    GIVEN {
        ASSUME(IsSoundMove(MOVE_HOWL) == TRUE);
        ASSUME(IsSoundMove(MOVE_ECHOED_VOICE) == TRUE);
        ASSUME(IsSoundMove(MOVE_SWIFT) == FALSE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_HOWL)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        else if (move == MOVE_ECHOED_VOICE)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        else
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    }
}



SINGLE_BATTLE_TEST("Throat Spray does not activate if move fails")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_PARTING_SHOT) == TRUE);
        ASSUME(IsSoundMove(MOVE_TORCH_SONG) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_PARTING_SHOT); }
	TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE);  }
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_TORCH_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TORCH_SONG, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    }
}

SINGLE_BATTLE_TEST("Throat Spray does not activate if user flinches")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    }
}

SINGLE_BATTLE_TEST("Throat Spray does not activate if user flinches with status move")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_HOWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    }
}

SINGLE_BATTLE_TEST("Throat Spray is not blocked by Sheer Force")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_BUG_BUZZ) == TRUE);
        PLAYER(SPECIES_NIDOKING) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BUZZ); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BUZZ, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    }
}

SINGLE_BATTLE_TEST("Throat Spray will not activate if the mon just switched in")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent); // red card
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player); // throat spray
    }
}

DOUBLE_BATTLE_TEST("Throat Spray activates on user and bouncer if at least one target if affected by sound move")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_SOUNDPROOF; }
    PARAMETRIZE { ability = ABILITY_RATTLED; }

    GIVEN {
        ASSUME(IsSoundMove(MOVE_GROWL));
        ASSUME(MoveCanBeBouncedBack(MOVE_GROWL));
        ASSUME(GetMoveTarget(MOVE_GROWL) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_HATTERENE) { Ability(ABILITY_MAGIC_BOUNCE); Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_WHISMUR) { Ability(ability); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GROWL); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        if (ability == ABILITY_SOUNDPROOF)
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        else
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
    }
}
