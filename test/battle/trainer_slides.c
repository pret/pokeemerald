#include "global.h"
#include "test/battle.h"
#include "battle_setup.h"

// SINGLES TESTS START
AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Before First Turn")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_BEFORE_FIRST_TURN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("Trainer A: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Defender Takes First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_CRITICAL_HIT);
        ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_LASER_FOCUS); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LASER_FOCUS, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
        MESSAGE("Trainer A: This message plays after the defender takes their first critical hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Lands First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_CRITICAL_HIT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SURGING_STRIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponent);
        MESSAGE("A critical hit!");
        MESSAGE("Trainer A: This message plays after the attacker lands their first critical hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Defender Takes First Super Effective Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_SUPER_EFFECTIVE_HIT);
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_BITE); }
    } SCENE {
        MESSAGE("It's super effective!");
        MESSAGE("Trainer A: This message plays after the defender takes their first super effective hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Lands First Super Effective Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_SUPER_EFFECTIVE_HIT);
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_BITE); }
    } SCENE {
        MESSAGE("It's super effective!");
        MESSAGE("Trainer A: This message plays after the attacker lands their first super effective hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Defender Takes First STAB Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_STAB_MOVE);
        ASSUME((GetMoveType(MOVE_VINE_WHIP)) == GetSpeciesType(SPECIES_BULBASAUR, 0));
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP); }
    } SCENE {
        MESSAGE("Bulbasaur used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, player);
        MESSAGE("Trainer A: Defender takes their first STAB move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Lands First STAB Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_STAB_MOVE);
        ASSUME((GetMoveType(MOVE_VINE_WHIP)) == GetSpeciesType(SPECIES_BULBASAUR, 0));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BULBASAUR);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_VINE_WHIP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, opponent);
        MESSAGE("Trainer A: Attacker lands their first STAB move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Defender Takes First Down")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponent,1); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the defender loses one mon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Lands First Down")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEALING_WISH); SEND_OUT(player,1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the attacker KOs one opponent mon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Mon Unaffected")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_MON_UNAFFECTED);
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_GLALIE);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, opponent);
        MESSAGE("Trainer A: Attacker attacked opponent with ineffective move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Self Mon Unaffected")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_MON_UNAFFECTED);
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        MESSAGE("It doesn't affect the opposing Glalie…");
        MESSAGE("Trainer A: Opponent attacked defender with ineffective move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Last Switchin")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_SWITCHIN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_HEALING_WISH); SEND_OUT(player,1); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the opponent switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Self Last Switchin")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_SWITCHIN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponent,1); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the battler switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Last Half Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_HALF_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        MESSAGE("Trainer A: Opponent last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Self Last Half Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_HALF_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        MESSAGE("Trainer A: Self last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Last Low Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_LOW_HP);
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { Defense(1); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(999); Speed(1); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_FALSE_SWIPE); }
    } SCENE {
        MESSAGE("Trainer A: Opponent last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Self Last Low Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_LOW_HP);
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { Attack(999); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(1); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_FALSE_SWIPE); }
    } SCENE {
        MESSAGE("Trainer A: Self last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Mega Evolution")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_MEGA_EVOLUTION);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LOPUNNY) { Item(ITEM_LOPUNNITE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        MESSAGE("The opposing Lopunny has Mega Evolved into Mega Lopunny!");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Z Move")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_Z_MOVE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponent);
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Dynamax")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_DYNAMAX);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, opponent);
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Attacker Tera")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_TERA);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN { EXPECT_MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponent);
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Mega Evolution")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_MEGA_EVOLUTION);
        PLAYER(SPECIES_LOPUNNY) {Item(ITEM_LOPUNNITE); };
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Lopunny has Mega Evolved into Mega Lopunny!");
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Z Move")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_Z_MOVE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Dynamax")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_DYNAMAX);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
    }
}

AI_SINGLE_BATTLE_TEST("Trainer Slide: Singles: Opponent Tera")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_TERA);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, player);
    }
}
// SINGLES TESTS END

// DOUBLES TESTS START - Tests message activation & message not activating twice
AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Before First Turn")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_BEFORE_FIRST_TURN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Defender Takes First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_CRITICAL_HIT);
        ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LASER_FOCUS); }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LASER_FOCUS, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        MESSAGE("A critical hit!");
        MESSAGE("Trainer A: This message plays after the defender takes their first critical hit.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the defender takes their first critical hit.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Lands First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_CRITICAL_HIT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_SURGING_STRIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponentLeft);
        MESSAGE("A critical hit!");
        MESSAGE("Trainer A: This message plays after the attacker lands their first critical hit.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the attacker lands their first critical hit.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Defender Takes First STAB Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_STAB_MOVE);
        ASSUME((GetMoveType(MOVE_VINE_WHIP)) == GetSpeciesType(SPECIES_BULBASAUR, 0));
        PLAYER(SPECIES_BULBASAUR);
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_VINE_WHIP, target: opponentLeft); }
    } SCENE {
        MESSAGE("Bulbasaur used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, playerLeft);
        MESSAGE("Trainer A: Defender takes their first STAB move.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: Defender takes their first STAB move.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Lands First STAB Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_STAB_MOVE);
        ASSUME((GetMoveType(MOVE_VINE_WHIP)) == GetSpeciesType(SPECIES_BULBASAUR, 0));
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_BULBASAUR);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_VINE_WHIP); }
        TURN { EXPECT_MOVE(opponentRight, MOVE_VINE_WHIP); }
    } SCENE {
        MESSAGE("The opposing Bulbasaur used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, opponentLeft);
        MESSAGE("Trainer A: Attacker lands their first STAB move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Bulbasaur used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, opponentRight);
        NONE_OF {
            MESSAGE("Trainer A: Attacker lands their first STAB move.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Defender Takes First Super Effective Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_SUPER_EFFECTIVE_HIT);
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BITE, target: opponentLeft); }
        TURN { MOVE(playerRight, MOVE_BITE, target: opponentRight); }
    } SCENE {
        MESSAGE("It's super effective!");
        MESSAGE("Trainer A: This message plays after the defender takes their first super effective hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("It's super effective!");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the defender takes their first super effective hit.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Lands First Super Effective Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_SUPER_EFFECTIVE_HIT);
        ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_BITE); }
        TURN { EXPECT_MOVE(opponentRight, MOVE_BITE); }
    } SCENE {
        MESSAGE("It's super effective!");
        MESSAGE("Trainer A: This message plays after the attacker lands their first super effective hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("It's super effective!");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the attacker lands their first super effective hit.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Defender Takes First Down")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponentLeft,2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the defender loses one mon.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the defender loses one mon.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Lands First Down")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HEALING_WISH); SEND_OUT(playerLeft,2); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the attacker KOs one opponent mon.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the attacker KOs one opponent mon.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Self Mon Unaffected")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_MON_UNAFFECTED);
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE);
        OPPONENT(SPECIES_GLALIE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, playerLeft);
        MESSAGE("It doesn't affect the opposing Glalie…");
        MESSAGE("Trainer A: Opponent attacked defender with ineffective move.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: Opponent attacked defender with ineffective move.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Mon Unaffected")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_MON_UNAFFECTED);
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_GLALIE);
        PLAYER(SPECIES_GLALIE);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_SHEER_COLD); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, opponentLeft);
        MESSAGE("It doesn't affect Glalie…");
        MESSAGE("Trainer A: Attacker attacked opponent with ineffective move.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: Attacker attacked opponent with ineffective move.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Self Last Switchin")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_SWITCHIN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponentLeft,2); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the battler switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the battler switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Last Switchin")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_SWITCHIN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HEALING_WISH); SEND_OUT(playerLeft,2); }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the opponent switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays after the opponent switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Self Last Half Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_HALF_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_MEMENTO); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SUPER_FANG, target: opponentRight); }
    } SCENE {
        MESSAGE("Trainer A: Self last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: Self last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Last Half Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_HALF_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_MEMENTO); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_MEMENTO, target: playerLeft);
            EXPECT_MOVE(opponentLeft, MOVE_SUPER_FANG);}
    } SCENE {
        MESSAGE("Trainer A: Opponent last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: Opponent last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Self Last Low Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_LOW_HP);
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { Attack(999); Speed(2); }
        PLAYER(SPECIES_WOBBUFFET) { Attack(999); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(1); Speed(4); Moves(MOVE_MEMENTO);}
        OPPONENT(SPECIES_WOBBUFFET) { Defense(1); Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FALSE_SWIPE, target: opponentRight); }
    } SCENE {
        MESSAGE("Trainer A: Self last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: Self last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Last Low Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_LOW_HP);
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { Defense(1); Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Defense(1); Speed(3); Moves(MOVE_MEMENTO); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(999); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Attack(999); Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_MEMENTO, target: playerLeft);
            EXPECT_MOVE(opponentLeft, MOVE_FALSE_SWIPE);
        }
    } SCENE {
        MESSAGE("Trainer A: Opponent last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: Opponent last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Mega Evolution")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_MEGA_EVOLUTION);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LOPUNNY) { Item(ITEM_LOPUNNITE); };
        OPPONENT(SPECIES_LOPUNNY);
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentLeft);
        MESSAGE("The opposing Lopunny has Mega Evolved into Mega Lopunny!");
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Z Move")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_Z_MOVE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the attacker activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        }
        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponentLeft);
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Dynamax")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_DYNAMAX);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN { EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the attacker activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, opponentLeft);
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Attacker Tera")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_TERA);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN { EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the attacker activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentLeft);
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Mega Evolution")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_MEGA_EVOLUTION);
        PLAYER(SPECIES_LOPUNNY) { Item(ITEM_LOPUNNITE); };
        PLAYER(SPECIES_LOPUNNY);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        MESSAGE("Lopunny has Mega Evolved into Mega Lopunny!");
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Z Move")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_Z_MOVE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        }
        MESSAGE("Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, playerLeft);
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Dynamax")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_DYNAMAX);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
            TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, playerLeft);
    }
}

AI_DOUBLE_BATTLE_TEST("Trainer Slide: Doubles: Opponent Tera")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_TERA);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
            TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerLeft);
    }
}

// DOUBLES TESTS END

// MULTI TESTS START
AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Before First Turn")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_BEFORE_FIRST_TURN);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: This message plays before the first turn.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Defender Takes First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_CRITICAL_HIT);
        ASSUME(GetMoveEffect(MOVE_LASER_FOCUS) == EFFECT_LASER_FOCUS);
        PLAYER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LASER_FOCUS); }
        TURN { MOVE(playerLeft, MOVE_SURF, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LASER_FOCUS, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, playerLeft);
        MESSAGE("A critical hit on the opposing Wobbuffet!");
        MESSAGE("A critical hit on the opposing Wobbuffet!");
        MESSAGE("Trainer A: This message plays after the defender takes their first critical hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays after the defender takes their first critical hit.{PAUSE_UNTIL_PRESS}");
        // Note: Planned PR for additional slides will change slides from using "Player/Opponent" side to "Attacker/Target" side
        // MESSAGE("Trainer Partner: This message plays after the defender takes their first critical hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Lands First Critical Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_CRITICAL_HIT);
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_ENDURE);
            EXPECT_MOVE(opponentLeft, MOVE_SURGING_STRIKES);
            EXPECT_MOVE(opponentRight, MOVE_SURGING_STRIKES);
            MOVE(playerRight, MOVE_SURGING_STRIKES, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDURE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponentLeft);
        MESSAGE("A critical hit!");
        MESSAGE("A critical hit!");
        MESSAGE("A critical hit!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, opponentRight);
        MESSAGE("A critical hit!");
        MESSAGE("A critical hit!");
        MESSAGE("A critical hit!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, playerRight);
        MESSAGE("A critical hit!");
        MESSAGE("A critical hit!");
        MESSAGE("A critical hit!");
        MESSAGE("Trainer A: This message plays after the attacker lands their first critical hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays after the attacker lands their first critical hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: This message plays after the attacker lands their first critical hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Defender Takes First STAB Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_STAB_MOVE);
        ASSUME((GetMoveType(MOVE_EARTHQUAKE)) == GetSpeciesType(SPECIES_SANDSHREW, 0));
        PLAYER(SPECIES_SANDSHREW) { Speed(4); }
        PARTNER(SPECIES_GOLEM) { Speed(2); Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_GOLEM) { Speed(3); }
        OPPONENT_B(SPECIES_GOLEM) { Speed(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_EARTHQUAKE);
            EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE);
        }
    } SCENE {
        MESSAGE("Sandshrew used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        MESSAGE("The opposing Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        MESSAGE("Trainer A: Defender takes their first STAB move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Defender takes their first STAB move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: Defender takes their first STAB move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Lands First STAB Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_STAB_MOVE);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 0) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 1) == TYPE_GROUND);
        PLAYER(SPECIES_GOLEM) { Speed(1); Defense(999); Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_GOLEM) { Speed(3); Defense(999); }
        OPPONENT_A(SPECIES_GOLEM) { Speed(4); Defense(999); }
        OPPONENT_B(SPECIES_GOLEM) { Speed(2); Defense(999); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE);
            MOVE(playerRight, MOVE_EARTHQUAKE);
            EXPECT_MOVE(opponentRight, MOVE_EARTHQUAKE);
        }
    } SCENE {
        MESSAGE("The opposing Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        MESSAGE("Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerRight);
        MESSAGE("The opposing Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentRight);

        MESSAGE("Trainer A: Attacker lands their first STAB move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Attacker lands their first STAB move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: Attacker lands their first STAB move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Defender Takes First Super Effective Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_SUPER_EFFECTIVE_HIT);
        ASSUME((GetMoveType(MOVE_EARTHQUAKE)) == GetSpeciesType(SPECIES_SANDSHREW, 0));
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 0) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 1) == TYPE_GROUND);
        PLAYER(SPECIES_SANDSHREW) { Speed(4); }
        PARTNER(SPECIES_GOLEM) { Speed(2); Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_GOLEM) { Speed(3); }
        OPPONENT_B(SPECIES_GOLEM) { Speed(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_EARTHQUAKE);
            EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE);
        }
    } SCENE {
        MESSAGE("Sandshrew used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        MESSAGE("The opposing Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        MESSAGE("Trainer A: This message plays after the defender takes their first super effective hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays after the defender takes their first super effective hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: This message plays after the defender takes their first super effective hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Lands First Super Effective Hit")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_SUPER_EFFECTIVE_HIT);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 0) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_GOLEM, 1) == TYPE_GROUND);
        PLAYER(SPECIES_GOLEM) { Speed(1); Defense(999); Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_GOLEM) { Speed(3); Defense(999); }
        OPPONENT_A(SPECIES_GOLEM) { Speed(4); Defense(999); }
        OPPONENT_B(SPECIES_GOLEM) { Speed(2); Defense(999); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_EARTHQUAKE);
            MOVE(playerRight, MOVE_EARTHQUAKE);
            EXPECT_MOVE(opponentRight, MOVE_EARTHQUAKE);
        }
    } SCENE {
        MESSAGE("The opposing Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentLeft);
        MESSAGE("Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerRight);
        MESSAGE("The opposing Golem used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentRight);

        MESSAGE("Trainer A: This message plays after the attacker lands their first super effective hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays after the attacker lands their first super effective hit.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: This message plays after the attacker lands their first super effective hit.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Defender Takes First Down")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_DEFENDER_TAKES_FIRST_DOWN);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PARTNER(SPECIES_RATICATE) { Speed(2); }
        PARTNER(SPECIES_RATTATA) { Speed(2); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT_A(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT_B(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(3); }
    } WHEN {
        TURN {
            EXPECT_MOVE(playerRight, MOVE_HEALING_WISH); EXPECT_SEND_OUT(playerRight,1);
            EXPECT_MOVE(opponentLeft, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponentLeft,1);
            EXPECT_MOVE(opponentRight, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponentRight,1);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the defender loses one mon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wynaut fainted!");
        MESSAGE("Trainer B: This message plays after the defender loses one mon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Raticate fainted!");
        MESSAGE("Trainer Partner: This message plays after the defender loses one mon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Lands First Down")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_LANDS_FIRST_DOWN);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); }
        PARTNER(SPECIES_RATICATE) { Speed(3); }
        PARTNER(SPECIES_RATTATA) { Speed(3); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT_A(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT_B(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_HEALING_WISH); SEND_OUT(playerLeft,1);
            MOVE(playerRight, MOVE_HEALING_WISH); SEND_OUT(playerRight,1);
            EXPECT_MOVE(opponentLeft, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponentLeft,1);
            EXPECT_MOVE(opponentRight, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponentRight,1);
        }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("Trainer A: This message plays after the attacker KOs one opponent mon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Raticate fainted!");
        MESSAGE("Trainer B: This message plays after the attacker KOs one opponent mon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Trainer Partner: This message plays after the attacker KOs one opponent mon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Self Mon Unaffected")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_MON_UNAFFECTED);
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_GASTLY);
        OPPONENT_A(SPECIES_GENGAR);
        OPPONENT_B(SPECIES_HAUNTER);
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_BOOMBURST);
            EXPECT_MOVE(opponentLeft, MOVE_BOOMBURST);
        }
    } SCENE {
        MESSAGE("It doesn't affect Gastly…");
        MESSAGE("It doesn't affect the opposing Gengar…");
        MESSAGE("It doesn't affect the opposing Haunter…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BOOMBURST, playerLeft);
        MESSAGE("It doesn't affect the opposing Haunter…");
        MESSAGE("It doesn't affect Gastly…");
        MESSAGE("It doesn't affect Gastly…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BOOMBURST, opponentLeft);
        MESSAGE("Trainer A: Opponent attacked defender with ineffective move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Opponent attacked defender with ineffective move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: Opponent attacked defender with ineffective move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Mon Unaffected")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_MON_UNAFFECTED);
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_GASTLY);
        OPPONENT_A(SPECIES_GENGAR);
        OPPONENT_B(SPECIES_HAUNTER);
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_BOOMBURST);
            MOVE(playerRight, MOVE_BOOMBURST);
            EXPECT_MOVE(opponentRight, MOVE_BOOMBURST);
        }
    } SCENE {
        MESSAGE("It doesn't affect the opposing Haunter…");
        MESSAGE("It doesn't affect Gastly…");
        MESSAGE("It doesn't affect Gastly…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BOOMBURST, opponentLeft);

        MESSAGE("It doesn't affect Gastly…");
        MESSAGE("It doesn't affect the opposing Gengar…");
        MESSAGE("It doesn't affect the opposing Haunter…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BOOMBURST, playerRight);

        MESSAGE("It doesn't affect the opposing Gengar…");
        MESSAGE("It doesn't affect Gastly…");
        MESSAGE("It doesn't affect Gastly…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_BOOMBURST, opponentRight);

        MESSAGE("Trainer A: Attacker attacked opponent with ineffective move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Attacker attacked opponent with ineffective move.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: Attacker attacked opponent with ineffective move.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Self Last Switchin")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_SWITCHIN);
        TIE_BREAK_TARGET(TARGET_TIE_HI, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PARTNER(SPECIES_RATICATE) { Speed(3); }
        PARTNER(SPECIES_RATTATA) { Speed(3); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT_A(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT_B(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_MEMENTO); EXPECT_SEND_OUT(opponentLeft,1);
            MOVE(playerRight, MOVE_MEMENTO, target: opponentRight); SEND_OUT(playerRight,1);
            EXPECT_MOVE(opponentRight, MOVE_MEMENTO); EXPECT_SEND_OUT(opponentRight,1);
        }
    } SCENE {
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Raticate fainted!");
        MESSAGE("The opposing Wynaut fainted!");
        MESSAGE("Trainer A: This message plays after the battler switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: This message plays after the battler switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays after the battler switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Last Switchin")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_SWITCHIN);
        TIE_BREAK_TARGET(TARGET_TIE_HI, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); }
        PARTNER(SPECIES_RATICATE) { Speed(2); }
        PARTNER(SPECIES_RATTATA) { Speed(2); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT_A(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT_B(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_MEMENTO, target: opponentRight); SEND_OUT(playerLeft,1);
            EXPECT_MOVE(opponentLeft, MOVE_MEMENTO); EXPECT_SEND_OUT(opponentLeft,1);
            MOVE(playerRight, MOVE_MEMENTO, target: opponentRight); SEND_OUT(playerRight,1);
            EXPECT_MOVE(opponentRight, MOVE_CELEBRATE);
        }
    } SCENE {
        MESSAGE("Wobbuffet fainted!");
        MESSAGE("The opposing Wobbuffet fainted!");
        MESSAGE("Raticate fainted!");
        MESSAGE("Trainer A: This message plays after the opponent switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: This message plays after the opponent switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays after the opponent switches in their last Pokemon.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Self Last Half Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_HALF_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); HP(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_SURF); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_SUPER_FANG); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SUPER_FANG, target: opponentLeft); SEND_OUT(playerLeft, 1);
            MOVE(playerRight, MOVE_SUPER_FANG, target: opponentRight); }
    } SCENE {
        MESSAGE("Trainer A: Self last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Self last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: Self last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Last Half Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_HALF_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_BELLY_DRUM);
            EXPECT_MOVE(opponentLeft, MOVE_BELLY_DRUM);
            MOVE(playerRight, MOVE_BELLY_DRUM);
            EXPECT_MOVE(opponentRight, MOVE_BELLY_DRUM);
        }
    } SCENE {
        MESSAGE("Trainer A: Opponent last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Opponent last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer Partner: Opponent last Mon has < 51% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Self Last Low Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_SELF_LAST_LOW_HP);
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); MaxHP(400); HP(201); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(3); MaxHP(400); HP(201); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(2); MaxHP(400); HP(201); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); MaxHP(400); HP(201); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_BELLY_DRUM);
            EXPECT_MOVE(opponentRight, MOVE_BELLY_DRUM);
        } TURN {
            MOVE(playerLeft, MOVE_BELLY_DRUM);
            MOVE(playerRight, MOVE_BELLY_DRUM);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, opponentRight);
        MESSAGE("Trainer A: Self last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Self last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, playerRight);
        MESSAGE("Trainer Partner: Self last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Last Low Hp")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_LAST_LOW_HP);
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); MaxHP(400); HP(201); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); MaxHP(400); HP(201); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(4); MaxHP(400); HP(201); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(3); MaxHP(400); HP(201); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_BELLY_DRUM);
            EXPECT_MOVE(opponentRight, MOVE_BELLY_DRUM);
        } TURN {
            MOVE(playerLeft, MOVE_BELLY_DRUM);
            MOVE(playerRight, MOVE_BELLY_DRUM);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, opponentRight);
        MESSAGE("Trainer Partner: Opponent last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, playerLeft);
        MESSAGE("Trainer A: Opponent last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: Opponent last Mon has < 26% HP.{PAUSE_UNTIL_PRESS}");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Mega Evolution")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_MEGA_EVOLUTION);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_AERODACTYL) { Speed(2); Item(ITEM_AERODACTYLITE); }
        OPPONENT_A(SPECIES_LOPUNNY) { Speed(3); Item(ITEM_LOPUNNITE); }
        OPPONENT_B(SPECIES_MEDICHAM) { Speed(1); Item(ITEM_MEDICHAMITE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            EXPECT_MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentLeft);
        MESSAGE("The opposing Lopunny has Mega Evolved into Mega Lopunny!");

        MESSAGE("Trainer Partner: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerRight);
        MESSAGE("Aerodactyl has Mega Evolved into Mega Aerodactyl!");

        MESSAGE("Trainer B: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentRight);
        MESSAGE("The opposing Medicham has Mega Evolved into Mega Medicham!");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Z Move")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_Z_MOVE);
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_NORMALIUM_Z); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); Item(ITEM_NORMALIUM_Z); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE);
            MOVE(playerRight, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE, target: opponentLeft);
            EXPECT_MOVE(opponentRight, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE);
        }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponentLeft);

        MESSAGE("Trainer Partner: This message plays before the attacker activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, playerRight);

        MESSAGE("Trainer B: This message plays before the attacker activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponentRight);
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Dynamax")
{
    s32 dynamaxLevelA = 0, dynamaxLevelB = 0;

    PARAMETRIZE { dynamaxLevelA = 10;  dynamaxLevelB = -1;  }
    PARAMETRIZE { dynamaxLevelA = -1;   dynamaxLevelB = 10; }

    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_DYNAMAX);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); DynamaxLevel(10); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); DynamaxLevel(dynamaxLevelA); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); DynamaxLevel(dynamaxLevelB); }
    } WHEN {
            TURN {
                if (dynamaxLevelA == 10)
                    EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX);
                else
                    EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_NONE);

                MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX);

                if (dynamaxLevelB == 10)
                    EXPECT_MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX);
                else
                    EXPECT_MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_NONE);
            }
    } SCENE {
        if (dynamaxLevelA == 10)
        {
            MESSAGE("Trainer A: This message plays before the attacker activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, opponentLeft);
        }
        MESSAGE("Trainer Partner: This message plays before the attacker activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, playerRight);
        if (dynamaxLevelB == 10)
        {
            MESSAGE("Trainer B: This message plays before the attacker activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, opponentRight);
        }
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Attacker Tera")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_ATTACKER_TERA);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN {
                EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
                MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
                EXPECT_MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
            }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the attacker activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentLeft);

        MESSAGE("Trainer Partner: This message plays before the attacker activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerRight);

        MESSAGE("Trainer B: This message plays before the attacker activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentRight);
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Mega Evolution")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_MEGA_EVOLUTION);
        PLAYER(SPECIES_MANECTRIC) { Speed(4); Item(ITEM_MANECTITE); }
        PARTNER(SPECIES_AERODACTYL) { Speed(2); Item(ITEM_AERODACTYLITE); }
        OPPONENT_A(SPECIES_LOPUNNY) { Speed(3); Item(ITEM_LOPUNNITE); }
        OPPONENT_B(SPECIES_MEDICHAM) { Speed(1); Item(ITEM_MEDICHAMITE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            EXPECT_MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {

        NOT MESSAGE("Trainer Partner: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer A: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        NOT MESSAGE("Trainer Partner: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        MESSAGE("Manectric has Mega Evolved into Mega Manectric!");

        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer B: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        }
        MESSAGE("Trainer Partner: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer B: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentLeft);
        MESSAGE("The opposing Lopunny has Mega Evolved into Mega Lopunny!");

        NOT MESSAGE("Trainer Partner: This message plays before the attacker activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerRight);
        MESSAGE("Aerodactyl has Mega Evolved into Mega Aerodactyl!");

        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer Partner: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer B: This message plays before the opponent activates the Mega Evolution gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentRight);
        MESSAGE("The opposing Medicham has Mega Evolved into Mega Medicham!");
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Z Move")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_Z_MOVE);
        TIE_BREAK_TARGET(TARGET_TIE_LO, 0);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Item(ITEM_NORMALIUM_Z); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_NORMALIUM_Z); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); Item(ITEM_NORMALIUM_Z); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE, target: opponentLeft);
            EXPECT_MOVE(opponentLeft, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE);
            MOVE(playerRight, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE, target: opponentLeft);
            EXPECT_MOVE(opponentRight, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE);
        }
    } SCENE {
        NONE_OF {
            MESSAGE("Trainer Partner: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer B: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        }
        MESSAGE("Trainer A: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        NONE_OF {
            MESSAGE("Trainer Partner: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer A: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        }
        MESSAGE("Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, playerLeft);

        MESSAGE("Trainer Partner: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponentLeft);

        NONE_OF {
            MESSAGE("Trainer Partner: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer A: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer B: This message plays before the opponent activates the Z-Move gimmick.{PAUSE_UNTIL_PRESS}");
        }

        MESSAGE("Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, playerRight);

        MESSAGE("The opposing Wobbuffet surrounded itself with its Z-Power!");
        MESSAGE("The opposing Wobbuffet unleashes its full-force Z-Move!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, opponentRight);
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Dynamax")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_DYNAMAX);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); DynamaxLevel(10); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); DynamaxLevel(10); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN {
                EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX);
                MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_DYNAMAX);
            }
    } SCENE {
        MESSAGE("Trainer Partner: This message plays before the opponent activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, opponentLeft);

        MESSAGE("Trainer A: This message plays before the opponent activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        // Ideally we would get both trainer A and B messages, however not currently possible
        //MESSAGE("Trainer B: This message plays before the opponent activates the Dynamax gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, playerRight);
    }
}

AI_MULTI_BATTLE_TEST("Trainer Slide: Multi: Opponent Tera")
{
    GIVEN {
        FLAG_SET(TESTING_FLAG_TRAINER_SLIDES);
        VAR_SET(TESTING_VAR_TRAINER_SLIDES, TRAINER_SLIDE_OPPONENT_TERA);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PARTNER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Speed(1); Moves(MOVE_CELEBRATE); }
    } WHEN {
            TURN {
                MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
                EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
                MOVE(playerRight, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
                EXPECT_MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_TERA);
            }
    } SCENE {
        MESSAGE("Trainer A: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        MESSAGE("Trainer B: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerLeft);

        MESSAGE("Trainer Partner: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentLeft);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, playerRight);

        NONE_OF {
            MESSAGE("Trainer A: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer Partner: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
            MESSAGE("Trainer B: This message plays before the opponent activates the Tera gimmick.{PAUSE_UNTIL_PRESS}");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_CHARGE, opponentRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_TERA_ACTIVATE, opponentRight);
    }
}

// MULTI TESTS END
