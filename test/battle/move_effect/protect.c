#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_DETECT) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_KINGS_SHIELD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_SILK_TRAP) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_SPIKY_SHIELD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_WIDE_GUARD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_QUICK_GUARD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_CRAFTY_SHIELD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_BANEFUL_BUNKER) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_BURNING_BULWARK) == EFFECT_PROTECT);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(GetMoveCategory(MOVE_LEER) == DAMAGE_CATEGORY_STATUS);
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(!(MoveMakesContact(MOVE_WATER_GUN)));
}

SINGLE_BATTLE_TEST("Protect: Protect, Detect, Spiky Shield, Baneful Bunker and Burning Bulwark protect from all moves")
{
    u32 j;
    static const enum Move protectMoves[] = {
        MOVE_PROTECT,
        MOVE_DETECT,
        MOVE_SPIKY_SHIELD,
        MOVE_BANEFUL_BUNKER,
    };
    enum Move protectMove = MOVE_NONE;
    enum Move usedMove = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(protectMoves); j++)
    {
        PARAMETRIZE { protectMove = protectMoves[j]; usedMove = MOVE_SCRATCH; }
        PARAMETRIZE { protectMove = protectMoves[j]; usedMove = MOVE_LEER; }
        PARAMETRIZE { protectMove = protectMoves[j]; usedMove = MOVE_WATER_GUN; }
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, protectMove); MOVE(player, usedMove); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("The opposing Wobbuffet protected itself!");
        if (usedMove == MOVE_LEER) {
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        } else {
            NOT HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: King's Shield, Silk Trap and Obstruct protect from damaging moves and lower stats on contact")
{
    u32 j;
    static const struct {
        enum Move move;
        enum Stat statId;
        s8 lowersBy;
    } protectMoves[] =
    {   // Move             Stat      Stages
        {MOVE_KINGS_SHIELD, STAT_ATK,   (B_KINGS_SHIELD_LOWER_ATK >= GEN_8) ? 1 : 2},
        {MOVE_SILK_TRAP,    STAT_SPEED, 1},
        {MOVE_OBSTRUCT,     STAT_DEF,   2},
    };
    enum Move protectMove = MOVE_NONE;
    enum Move usedMove = MOVE_NONE;
    u16 statId = 0, lowersBy = 0;

    for (j = 0; j < ARRAY_COUNT(protectMoves); j++)
    {
        PARAMETRIZE { usedMove = MOVE_SCRATCH; protectMove = protectMoves[j].move; statId = protectMoves[j].statId; lowersBy = protectMoves[j].lowersBy; }
        PARAMETRIZE { usedMove = MOVE_LEER; protectMove = protectMoves[j].move; statId = 0; lowersBy = 0; }
        PARAMETRIZE { usedMove = MOVE_WATER_GUN; protectMove = protectMoves[j].move; statId = 0; lowersBy = 0; }
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, protectMove); MOVE(player, usedMove); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");
        if (usedMove == MOVE_LEER) {
            ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            NOT MESSAGE("The opposing Wobbuffet protected itself!");
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
            MESSAGE("The opposing Wobbuffet protected itself!");
            if (usedMove == MOVE_SCRATCH) {
                NOT HP_BAR(opponent);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
                if (statId == STAT_ATK) {
                    #if B_KINGS_SHIELD_LOWER_ATK >= GEN_8
                    MESSAGE("Wobbuffet's Attack fell!");
                    #else
                    MESSAGE("Wobbuffet's Attack harshly fell!");
                    #endif
                } else if (statId == STAT_SPEED) {
                    MESSAGE("Wobbuffet's Speed fell!");
                } else if (statId == STAT_DEF) {
                    if (lowersBy == 2) {
                        MESSAGE("Wobbuffet's Defense harshly fell!");
                    }
                }
            } else {
                NONE_OF {
                    HP_BAR(opponent);
                    ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
                }
            }
        }
    } THEN {
        if (usedMove == MOVE_SCRATCH) {
            EXPECT_EQ(player->statStages[statId], DEFAULT_STAT_STAGE - lowersBy);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: King's Shield, Silk Trap and Obstruct don't lower stats when charging a two turn move")
{
    enum Move move, protectMove;
    PARAMETRIZE { move = MOVE_BOUNCE; protectMove = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_DIG;    protectMove = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_BOUNCE; protectMove = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_DIG;    protectMove = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_BOUNCE; protectMove = MOVE_OBSTRUCT; }
    PARAMETRIZE { move = MOVE_DIG;    protectMove = MOVE_OBSTRUCT; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_BOUNCE));
        ASSUME(MoveMakesContact(MOVE_DIG));
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_BOUNCE)].twoTurnEffect);
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_DIG)].twoTurnEffect);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, protectMove); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, protectMove, player);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            HP_BAR(player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Spiky Shield does 1/8 dmg of max hp of attackers making contact and may faint them")
{
    enum Move usedMove = MOVE_NONE;
    u16 hp = 400, maxHp = 400;

    PARAMETRIZE { usedMove = MOVE_SCRATCH; hp = 1; }
    PARAMETRIZE { usedMove = MOVE_SCRATCH; }
    PARAMETRIZE { usedMove = MOVE_LEER; }
    PARAMETRIZE { usedMove = MOVE_WATER_GUN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); MaxHP(maxHp); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (hp == 1) {
            TURN { MOVE(opponent, MOVE_SPIKY_SHIELD); MOVE(player, usedMove); SEND_OUT(player, 1); }
        } else {
            TURN { MOVE(opponent, MOVE_SPIKY_SHIELD); MOVE(player, usedMove); }
        }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKY_SHIELD, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("The opposing Wobbuffet protected itself!");
        NOT HP_BAR(opponent);
        if (usedMove == MOVE_SCRATCH) {
            HP_BAR(player, maxHp / 8);
            if (hp == 1) {
                MESSAGE("Wobbuffet fainted!");
                SEND_IN_MESSAGE("Wobbuffet");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Spiky Shield doesn't hurt attacker when charging a two turn move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_BOUNCE; }
    PARAMETRIZE { move = MOVE_DIG; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_BOUNCE));
        ASSUME(MoveMakesContact(MOVE_DIG));
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_BOUNCE)].twoTurnEffect);
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_DIG)].twoTurnEffect);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPIKY_SHIELD); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKY_SHIELD, player);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            HP_BAR(player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Baneful Bunker poisons Pokémon for moves making contact")
{
    enum Move usedMove = MOVE_NONE;

    PARAMETRIZE { usedMove = MOVE_SCRATCH; }
    PARAMETRIZE { usedMove = MOVE_LEER; }
    PARAMETRIZE { usedMove = MOVE_WATER_GUN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BANEFUL_BUNKER); MOVE(player, usedMove); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BANEFUL_BUNKER, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("The opposing Wobbuffet protected itself!");
        if (usedMove == MOVE_SCRATCH) {
            NOT HP_BAR(opponent);
            STATUS_ICON(player, STATUS1_POISON);
        } else {
            NONE_OF {
                HP_BAR(opponent);
                STATUS_ICON(player, STATUS1_POISON);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Baneful Bunker can't poison Pokémon if they are already statused")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WILL_O_WISP); }
        TURN { MOVE(opponent, MOVE_BANEFUL_BUNKER); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, opponent);
        STATUS_ICON(player, STATUS1_BURN);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BANEFUL_BUNKER, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
            STATUS_ICON(player, STATUS1_POISON);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Baneful Bunker doesn't poison attacker when charging a two turn move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_BOUNCE; }
    PARAMETRIZE { move = MOVE_DIG; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_BOUNCE));
        ASSUME(MoveMakesContact(MOVE_DIG));
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_BOUNCE)].twoTurnEffect);
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_DIG)].twoTurnEffect);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BANEFUL_BUNKER); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BANEFUL_BUNKER, player);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            HP_BAR(player);
            STATUS_ICON(opponent, STATUS1_POISON);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Burning Bulwark burns Pokémon for moves making contact")
{
    enum Move usedMove = MOVE_NONE;

    PARAMETRIZE { usedMove = MOVE_SCRATCH; }
    PARAMETRIZE { usedMove = MOVE_WATER_GUN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BURNING_BULWARK); MOVE(player, usedMove); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURNING_BULWARK, opponent);
        MESSAGE("The opposing Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("The opposing Wobbuffet protected itself!");
        if (usedMove == MOVE_SCRATCH) {
            NOT HP_BAR(opponent);
            STATUS_ICON(player, STATUS1_BURN);
        } else {
            NONE_OF {
                HP_BAR(opponent);
                STATUS_ICON(player, STATUS1_BURN);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Burning Bulwark can't burn Pokémon if they are already statused")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC); }
        TURN { MOVE(opponent, MOVE_BURNING_BULWARK); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
        STATUS_ICON(player, STATUS1_TOXIC_POISON);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURNING_BULWARK, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
            STATUS_ICON(player, STATUS1_BURN);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Burning Bulwark doesn't burn attacker when charging a two turn move")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_BOUNCE; }
    PARAMETRIZE { move = MOVE_DIG; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_BOUNCE));
        ASSUME(MoveMakesContact(MOVE_DIG));
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_BOUNCE)].twoTurnEffect);
        ASSUME(gBattleMoveEffects[GetMoveEffect(MOVE_DIG)].twoTurnEffect);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BURNING_BULWARK); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURNING_BULWARK, player);

        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            HP_BAR(player);
            STATUS_ICON(opponent, STATUS1_BURN);
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Recoil damage is not applied if target was protected")
{
    u32 j, k;
    static const enum Move protectMoves[] = {MOVE_PROTECT, MOVE_DETECT, MOVE_KINGS_SHIELD, MOVE_BANEFUL_BUNKER, MOVE_SILK_TRAP, MOVE_OBSTRUCT, MOVE_SPIKY_SHIELD};
    static const enum Move recoilMoves[] = {MOVE_VOLT_TACKLE, MOVE_HEAD_SMASH, MOVE_TAKE_DOWN, MOVE_DOUBLE_EDGE};
    enum Move protectMove = MOVE_NONE;
    enum Move recoilMove = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(protectMoves); j++)
    {
        for (k = 0; k < ARRAY_COUNT(recoilMoves); k++)
        {
            PARAMETRIZE { protectMove = protectMoves[j]; recoilMove = recoilMoves[k]; }
        }
    }


    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_VOLT_TACKLE) > 0);
        ASSUME(GetMoveRecoil(MOVE_HEAD_SMASH) > 0);
        ASSUME(GetMoveRecoil(MOVE_TAKE_DOWN) > 0);
        ASSUME(GetMoveRecoil(MOVE_DOUBLE_EDGE) > 0);
        PLAYER(SPECIES_RAPIDASH);
        OPPONENT(SPECIES_BEAUTIFLY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(opponent, protectMove); MOVE(player, recoilMove); }
        TURN {}
    } SCENE {
        // 1st turn
        MESSAGE("The opposing Beautifly used Scratch!");
        MESSAGE("Rapidash used Scratch!");
        // 2nd turn
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        MESSAGE("The opposing Beautifly protected itself!");
        // MESSAGE("Rapidash used recoilMove!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, recoilMove, player);
            MESSAGE("Rapidash was damaged by the recoil!");
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Multi-hit moves don't hit a protected target and fail only once")
{
    enum Move move = MOVE_NONE;

    PARAMETRIZE { move = MOVE_PROTECT; }
    PARAMETRIZE { move = MOVE_DETECT; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }
    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }

    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_ARM_THRUST));
        PLAYER(SPECIES_RAPIDASH);
        OPPONENT(SPECIES_BEAUTIFLY);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_ARM_THRUST); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        MESSAGE("The opposing Beautifly protected itself!");
        MESSAGE("Rapidash used Arm Thrust!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ARM_THRUST, player);
        MESSAGE("The opposing Beautifly protected itself!");
        // Each effect happens only once.
        if (move == MOVE_KINGS_SHIELD || move == MOVE_SILK_TRAP || move == MOVE_OBSTRUCT) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        } else if (move == MOVE_SPIKY_SHIELD) {
            HP_BAR(player);
        } else if (move == MOVE_BANEFUL_BUNKER) {
            STATUS_ICON(player, STATUS1_POISON);
        }
        NONE_OF {
            if (move == MOVE_KINGS_SHIELD || move == MOVE_SILK_TRAP || move == MOVE_OBSTRUCT) {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            } else if (move == MOVE_SPIKY_SHIELD) {
                HP_BAR(player);
            }
            MESSAGE("The Pokémon was hit 2 times!");
            MESSAGE("The Pokémon was hit 3 times!");
            MESSAGE("The Pokémon was hit 4 times!");
            MESSAGE("The Pokémon was hit 5 times!");
        }
    }
}

SINGLE_BATTLE_TEST("Protect fails if user moves last")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_PROTECT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
    }
}

DOUBLE_BATTLE_TEST("Protect fails when the only slower battler is a fainted ally")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
        TURN {
            MOVE(opponentLeft, MOVE_CELEBRATE);
            MOVE(opponentRight, MOVE_CELEBRATE);
            MOVE(playerLeft, MOVE_PROTECT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        MESSAGE("Wynaut fainted!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Protect: Wide Guard protects self and ally from multi-target moves")
{
    enum Move move = MOVE_NONE;

    PARAMETRIZE { move = MOVE_SCRATCH; }      // Single target
    PARAMETRIZE { move = MOVE_SURF; }        // All targets
    PARAMETRIZE { move = MOVE_HYPER_VOICE; } // 2 foes

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SCRATCH) == TARGET_SELECTED);
        ASSUME(GetMoveTarget(MOVE_SURF) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WIDE_GUARD); MOVE(playerLeft, move, target: opponentLeft); }
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Wide Guard!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, opponentLeft);
        if (move == MOVE_SCRATCH) {
            MESSAGE("Wobbuffet used Scratch!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
            HP_BAR(opponentLeft);
        } else if (move == MOVE_HYPER_VOICE) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
            MESSAGE("The opposing Wobbuffet protected itself!");
            MESSAGE("The opposing Wobbuffet protected itself!");
            NONE_OF {
                HP_BAR(opponentLeft);
                HP_BAR(opponentRight);
            }
        } else { // Surf
            MESSAGE("The opposing Wobbuffet protected itself!");
            MESSAGE("The opposing Wobbuffet protected itself!");
            NOT HP_BAR(opponentLeft);
            HP_BAR(playerRight);
            NOT HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Protect: Wide Guard can not fail on consecutive turns (Gen6+)")
{
    u32 turns, config, passes;

    PARAMETRIZE { config = GEN_5; passes = 0; }
    PARAMETRIZE { config = GEN_6; passes = 2; }
    PASSES_RANDOMLY(passes, 2);
    GIVEN {
        WITH_CONFIG(B_WIDE_GUARD, config);
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WIDE_GUARD); MOVE(playerLeft, MOVE_HYPER_VOICE, target: opponentLeft); }
        TURN { MOVE(opponentLeft, MOVE_WIDE_GUARD); MOVE(playerLeft, MOVE_HYPER_VOICE, target: opponentLeft); }
        TURN {}
    } SCENE {
        for (turns = 0; turns < 2; turns++) {
            MESSAGE("The opposing Wobbuffet used Wide Guard!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, opponentLeft);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
            MESSAGE("The opposing Wobbuffet protected itself!");
            NOT HP_BAR(opponentLeft);
            MESSAGE("The opposing Wobbuffet protected itself!");
            NOT HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Protect: Quick Guard protects self and ally from priority moves")
{
    enum Move move = MOVE_NONE;
    struct BattlePokemon *targetOpponent = NULL;

    PARAMETRIZE { move = MOVE_SCRATCH;      targetOpponent = opponentLeft; }
    PARAMETRIZE { move = MOVE_SCRATCH;      targetOpponent = opponentRight; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; targetOpponent = opponentLeft; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; targetOpponent = opponentRight; }

    GIVEN {
        ASSUME(GetMovePriority(MOVE_SCRATCH) == 0);
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_QUICK_GUARD); MOVE(playerLeft, move, target:targetOpponent); }
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Quick Guard!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_GUARD, opponentLeft);
        if (move == MOVE_SCRATCH) {
            MESSAGE("Wobbuffet used Scratch!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
            HP_BAR(targetOpponent);
        } else if (move == MOVE_QUICK_ATTACK) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerLeft);
            MESSAGE("The opposing Wobbuffet protected itself!");
            NOT HP_BAR(targetOpponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Protect: Quick Guard can not fail on consecutive turns (Gen6+)")
{
    u32 turns, config, passes;

    PARAMETRIZE { config = GEN_5; passes = 0; }
    PARAMETRIZE { config = GEN_6; passes = 2; }
    PASSES_RANDOMLY(passes, 2);
    GIVEN {
        WITH_CONFIG(B_QUICK_GUARD, config);
        ASSUME(GetMovePriority(MOVE_QUICK_ATTACK) == 1);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_QUICK_GUARD); MOVE(playerLeft, MOVE_QUICK_ATTACK, target: opponentRight); }
        TURN { MOVE(opponentLeft, MOVE_QUICK_GUARD); MOVE(playerLeft, MOVE_QUICK_ATTACK, target: opponentRight); }
    } SCENE {
        for (turns = 0; turns < 2; turns++) {
            MESSAGE("The opposing Wobbuffet used Quick Guard!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_GUARD, opponentLeft);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerLeft);
            MESSAGE("The opposing Wobbuffet protected itself!");
            NOT HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield protects self and ally from opposing status moves")
{
    enum Move move = MOVE_NONE;
    struct BattlePokemon *targetOpponent = NULL;

    PARAMETRIZE { move = MOVE_HYPER_VOICE; }
    PARAMETRIZE { move = MOVE_LEER; }
    PARAMETRIZE { move = MOVE_SCRATCH; targetOpponent = opponentLeft; }
    PARAMETRIZE { move = MOVE_SCRATCH; targetOpponent = opponentRight; }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_LEER) == TARGET_BOTH);
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        ASSUME(GetMoveCategory(MOVE_HYPER_VOICE) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CRAFTY_SHIELD); (move == MOVE_SCRATCH) ? MOVE(playerLeft, move, target:targetOpponent) : MOVE(playerLeft, move); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        if (move == MOVE_LEER) {
            MESSAGE("Wobbuffet used Leer!");
            MESSAGE("The opposing Wobbuffet protected itself!");
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Wobbuffet protected itself!");
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        } else {
            if (move == MOVE_HYPER_VOICE || targetOpponent == opponentLeft) {
                NOT MESSAGE("The opposing Wobbuffet protected itself!");
                HP_BAR(opponentLeft);
            } else if (move == MOVE_HYPER_VOICE || targetOpponent == opponentRight) {
                NOT MESSAGE("The opposing Wobbuffet protected itself!");
                HP_BAR(opponentRight);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield does not protect against status moves used on the user's side")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_AROMATHERAPY; }
    PARAMETRIZE { move = MOVE_ACUPRESSURE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AROMATHERAPY) == EFFECT_HEAL_BELL);
        ASSUME(GetMoveEffect(MOVE_ACUPRESSURE) == EFFECT_ACUPRESSURE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); Status1(STATUS1_BURN); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_CRAFTY_SHIELD);
            if (move == MOVE_ACUPRESSURE)
                MOVE(opponentRight, move, target: opponentLeft);
            else
                MOVE(opponentRight, move);
        }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        if (move == MOVE_ACUPRESSURE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ACUPRESSURE, opponentRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_AROMATHERAPY, opponentRight);
            STATUS_ICON(opponentRight, none: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield does not protect against entry hazard moves")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SPIKES; }
    PARAMETRIZE { move = MOVE_STEALTH_ROCK; }
    PARAMETRIZE { move = MOVE_TOXIC_SPIKES; }
    PARAMETRIZE { move = MOVE_STICKY_WEB; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CRAFTY_SHIELD); MOVE(playerLeft, move, target: opponentLeft); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        if (move == MOVE_SPIKES) {
            MESSAGE("Spikes were scattered on the ground all around the opposing side!");
        } else if (move == MOVE_TOXIC_SPIKES) {
            MESSAGE("Toxic spikes were scattered on the ground all around the opposing side!");
        } else if (move == MOVE_STEALTH_ROCK) {
            MESSAGE("Pointed stones float in the air on the opposing side!");
        } else {
            MESSAGE("A sticky web has been laid out on the ground on the opposing side!");
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Protect does not block Confide or Decorate")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CONFIDE; }
    PARAMETRIZE { move = MOVE_DECORATE; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CONFIDE, spAtk: -1);
        ASSUME(MoveIgnoresProtect(MOVE_CONFIDE));
        ASSUME_STAT_CHANGE(MOVE_DECORATE, attack: +2, spAtk: +2);
        ASSUME(MoveIgnoresProtect(MOVE_DECORATE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT MESSAGE("The opposing Wobbuffet protected itself!");
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield protects self and ally from Confide and Decorate")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_CONFIDE; }
    PARAMETRIZE { move = MOVE_DECORATE; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CONFIDE, spAtk: -1);
        ASSUME(MoveIgnoresProtect(MOVE_CONFIDE));
        ASSUME_STAT_CHANGE(MOVE_DECORATE, attack: +2, spAtk: +2);
        ASSUME(MoveIgnoresProtect(MOVE_DECORATE));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CRAFTY_SHIELD); MOVE(playerLeft, move, target: opponentLeft); MOVE(playerRight, move, target: opponentRight); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        MESSAGE("The opposing Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, move, playerRight);
        MESSAGE("The opposing Wynaut protected itself!");
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield does not protect against moves that target all battlers")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_FLOWER_SHIELD; }
    PARAMETRIZE { move = MOVE_PERISH_SONG; }

    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_TANGELA, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_TANGROWTH, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_SUNKERN, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_SUNFLORA, 0) == TYPE_GRASS);
        PLAYER(SPECIES_TANGELA);
        PLAYER(SPECIES_TANGROWTH);
        OPPONENT(SPECIES_SUNKERN);
        OPPONENT(SPECIES_SUNFLORA);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CRAFTY_SHIELD); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(playerLeft, move); MOVE(playerRight, MOVE_CELEBRATE); }
    } SCENE {
        if (move == MOVE_FLOWER_SHIELD) {
            MESSAGE("Tangela used Flower Shield!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Tangela's Defense rose!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Tangrowth's Defense rose!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Sunkern's Defense rose!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Sunflora's Defense rose!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_PERISH_SONG, playerLeft);
            NONE_OF {
                MESSAGE("The opposing Sunkern protected itself!");
                MESSAGE("The opposing Sunflora protected itself!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Protect: Quick Guard, Wide Guard and Crafty Shield don't reduce Max Move demage", s16 damage)
{
    s16 dmg[2];
    enum Move move;

    PARAMETRIZE { move = MOVE_WIDE_GUARD; }
    PARAMETRIZE { move = MOVE_QUICK_GUARD; }
    PARAMETRIZE { move = MOVE_CRAFTY_SHIELD; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, move); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &dmg[0]);
        HP_BAR(opponent, captureDamage: &dmg[1]);
    } FINALLY {
        EXPECT_EQ(dmg[0], dmg[1]);
    }
}

SINGLE_BATTLE_TEST("Protect: Quick Guard, Wide Guard and Crafty Shield don't reduce Z-Move demage", s16 damage)
{
    bool32 protected;
    enum Move move;

    PARAMETRIZE { protected = TRUE; move = MOVE_WIDE_GUARD; }
    PARAMETRIZE { protected = FALSE; move = MOVE_WIDE_GUARD; }

    PARAMETRIZE { protected = TRUE; move = MOVE_QUICK_GUARD; }
    PARAMETRIZE { protected = FALSE; move = MOVE_QUICK_GUARD; }

    PARAMETRIZE { protected = TRUE; move = MOVE_CRAFTY_SHIELD; }
    PARAMETRIZE { protected = FALSE; move = MOVE_CRAFTY_SHIELD; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (protected)
            TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); MOVE(opponent, move); }
        else
            TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[2].damage, results[3].damage);
        EXPECT_EQ(results[4].damage, results[5].damage);
    }
}

SINGLE_BATTLE_TEST("Protect: Protective Pads protects from secondary effects")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_PROTECTIVE_PADS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BURNING_BULWARK); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURNING_BULWARK, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            HP_BAR(opponent);
            STATUS_ICON(player, STATUS1_BURN);
        }
    }
}

DOUBLE_BATTLE_TEST("Protect is not transferred to a mon that is switched in due to Eject Button")
{
    GIVEN {
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_SQUIRTLE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_PROTECT);
            MOVE(playerLeft, MOVE_POUND, target: opponentRight);
            SEND_OUT(opponentRight, 2);
            MOVE(playerRight, MOVE_POUND, target: opponentRight);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Wide Guard is still activate even if user is switched out due to Eject Button")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_SQUIRTLE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_WIDE_GUARD);
            MOVE(playerLeft, MOVE_POUND, target: opponentRight);
            SEND_OUT(opponentRight, 2);
            MOVE(playerRight, MOVE_HYPER_VOICE, target: opponentRight);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerRight);
            HP_BAR(opponentLeft);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Protect is not ignored after a new mon switched in because of U-Turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerRight, MOVE_PROTECT);
            MOVE(opponentLeft, MOVE_POUND, target: playerRight);
            MOVE(opponentRight, MOVE_U_TURN, target: playerLeft);
            SEND_OUT(opponentRight, 2);
        }
        TURN {
            MOVE(playerLeft, MOVE_DETECT);
            MOVE(opponentLeft, MOVE_POUND, target: playerRight);
            MOVE(opponentRight, MOVE_POUND, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DETECT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentRight);
    }
}

SINGLE_BATTLE_TEST("Protect may fail if used consecutively - 2nd time has 1/2 or 1/3 odds")
{
    u32 numRolls = (B_PROTECT_FAILURE_RATE < GEN_5 ? 2 : 3);
    PASSES_RANDOMLY(1, numRolls, RNG_PROTECT_FAIL);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_PROTECT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
    }
}

SINGLE_BATTLE_TEST("Protect may fail if used consecutively - 3rd time has 1/4 or 1/9 odds")
{
    u32 numRolls = (B_PROTECT_FAILURE_RATE < GEN_5 ? 4 : 9);
    PASSES_RANDOMLY(1, numRolls, RNG_PROTECT_FAIL);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, 1)); }
        TURN { MOVE(player, MOVE_PROTECT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
    }
}

SINGLE_BATTLE_TEST("Protect may fail if used consecutively - 4th time has 1/8 or 1/27 odds")
{
    u32 numRolls = (B_PROTECT_FAILURE_RATE < GEN_5 ? 8 : 27);
    PASSES_RANDOMLY(1, numRolls, RNG_PROTECT_FAIL);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); }
        TURN { MOVE(player, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, 1)); }
        TURN { MOVE(player, MOVE_PROTECT, WITH_RNG(RNG_PROTECT_FAIL, 1)); }
        TURN { MOVE(player, MOVE_PROTECT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
    }
}

SINGLE_BATTLE_TEST("Protect doesn't fail if used consecutively if broken by Feint")
{
    PASSES_RANDOMLY(1, 1, RNG_PROTECT_FAIL);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_FEINT, MOVE_EFFECT_FEINT));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); MOVE(opponent, MOVE_FEINT); }
        TURN { MOVE(player, MOVE_PROTECT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FEINT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, player);
    }
}

SINGLE_BATTLE_TEST("Protect: Contact effects from certain protect moves do not apply if the attacker's contact move fails")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_BURNING_BULWARK; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_SUCKER_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Protect: Contact effects from certain protect moves do not apply if the attacker fails to attack")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_OBSTRUCT; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_SLEEP_TURN(3)); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Protect: Contact effects from certain protect moves do not apply if the attacker's contact move fails (Unseen Fist)")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_BURNING_BULWARK; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_URSHIFU);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_SUCKER_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        NOT MESSAGE("Wobbuffet couldn't fully protect itself and got hurt!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Protect: Mat Block, King's Shield, Obstruct, Burning Bulwark and Silk Trap do not protect the user from status moves")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_BURNING_BULWARK; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_MAT_BLOCK; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_LEER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponent);
        NOT MESSAGE("Wobbuffet protected itself!");
    }
}

SINGLE_BATTLE_TEST("Protect: Wide Guard protects user from spread moves even in Single Battles")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_LEER; }
    PARAMETRIZE { move = MOVE_DAZZLING_GLEAM; }
    PARAMETRIZE { move = MOVE_EARTHQUAKE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WIDE_GUARD); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        MESSAGE("Wobbuffet protected itself!");
    }
}
