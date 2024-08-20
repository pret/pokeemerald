#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_PROTECT].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_DETECT].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_KINGS_SHIELD].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_SILK_TRAP].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_SPIKY_SHIELD].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_WIDE_GUARD].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_QUICK_GUARD].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_CRAFTY_SHIELD].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_BANEFUL_BUNKER].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_BURNING_BULWARK].effect == EFFECT_PROTECT);
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_TACKLE].makesContact);
    ASSUME(gMovesInfo[MOVE_LEER].category == DAMAGE_CATEGORY_STATUS);
    ASSUME(gMovesInfo[MOVE_WATER_GUN].category == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(!(gMovesInfo[MOVE_WATER_GUN].makesContact));
}

SINGLE_BATTLE_TEST("Protect, Detect, Spiky Shield, Baneful Bunker and Burning Bulwark protect from all moves")
{
    u32 j;
    static const u16 protectMoves[] = {
        MOVE_PROTECT,
        MOVE_DETECT,
        MOVE_SPIKY_SHIELD,
        MOVE_BANEFUL_BUNKER,
        MOVE_BURNING_BULWARK,
    };
    u16 protectMove = MOVE_NONE;
    u16 usedMove = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(protectMoves); j++)
    {
        PARAMETRIZE { protectMove = protectMoves[j]; usedMove = MOVE_TACKLE; }
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
        MESSAGE("Foe Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("Foe Wobbuffet protected itself!");
        if (usedMove == MOVE_LEER) {
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        } else {
            NOT HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("King's Shield, Silk Trap and Obstruct protect from damaging moves and lower stats on contact")
{
    u32 j;
    static const u16 protectMoves[][3] =
    {   // Move             Stat      Stages
        {MOVE_KINGS_SHIELD, STAT_ATK,   1},
        {MOVE_SILK_TRAP,    STAT_SPEED, 1},
        {MOVE_OBSTRUCT,     STAT_DEF,   2},
    };
    u16 protectMove = MOVE_NONE;
    u16 usedMove = MOVE_NONE;
    u16 statId = 0, lowersBy = 0;

    for (j = 0; j < ARRAY_COUNT(protectMoves); j++)
    {
        PARAMETRIZE { usedMove = MOVE_TACKLE; protectMove = protectMoves[j][0]; statId = protectMoves[j][1]; lowersBy = protectMoves[j][2]; }
        PARAMETRIZE { usedMove = MOVE_LEER; protectMove = protectMoves[j][0]; statId = 0; lowersBy = 0; }
        PARAMETRIZE { usedMove = MOVE_WATER_GUN; protectMove = protectMoves[j][0]; statId = 0; lowersBy = 0; }
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, protectMove); MOVE(player, usedMove); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        MESSAGE("Foe Wobbuffet protected itself!");
        if (usedMove == MOVE_LEER) {
            ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            NOT MESSAGE("Foe Wobbuffet protected itself!");
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
            MESSAGE("Foe Wobbuffet protected itself!");
            if (usedMove == MOVE_TACKLE) {
                NOT HP_BAR(opponent);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
                if (statId == STAT_ATK) {
                    MESSAGE("Wobbuffet's Attack fell!");
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
        if (usedMove == MOVE_TACKLE) {
            EXPECT_EQ(player->statStages[statId], DEFAULT_STAT_STAGE - lowersBy);
        }
    }
}

SINGLE_BATTLE_TEST("Spiky Shield does 1/8 dmg of max hp of attackers making contact and may faint them")
{
    u16 usedMove = MOVE_NONE;
    u16 hp = 400, maxHp = 400;

    PARAMETRIZE { usedMove = MOVE_TACKLE; hp = 1; }
    PARAMETRIZE { usedMove = MOVE_TACKLE; }
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
        MESSAGE("Foe Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("Foe Wobbuffet protected itself!");
        NOT HP_BAR(opponent);
        if (usedMove == MOVE_TACKLE) {
            HP_BAR(player, maxHp / 8);
            if (hp == 1) {
                MESSAGE("Wobbuffet fainted!");
                SEND_IN_MESSAGE("Wobbuffet");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Baneful Bunker poisons pokemon for moves making contact")
{
    u16 usedMove = MOVE_NONE;

    PARAMETRIZE {usedMove = MOVE_TACKLE; }
    PARAMETRIZE {usedMove = MOVE_LEER; }
    PARAMETRIZE {usedMove = MOVE_WATER_GUN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BANEFUL_BUNKER); MOVE(player, usedMove); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BANEFUL_BUNKER, opponent);
        MESSAGE("Foe Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("Foe Wobbuffet protected itself!");
        if (usedMove == MOVE_TACKLE) {
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

SINGLE_BATTLE_TEST("Burning Bulwark burns pokemon for moves making contact")
{
    u16 usedMove = MOVE_NONE;

    PARAMETRIZE {usedMove = MOVE_TACKLE; }
    PARAMETRIZE {usedMove = MOVE_LEER; }
    PARAMETRIZE {usedMove = MOVE_WATER_GUN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BURNING_BULWARK); MOVE(player, usedMove); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURNING_BULWARK, opponent);
        MESSAGE("Foe Wobbuffet protected itself!");
        NOT ANIMATION(ANIM_TYPE_MOVE, usedMove, player);
        MESSAGE("Foe Wobbuffet protected itself!");
        if (usedMove == MOVE_TACKLE) {
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

SINGLE_BATTLE_TEST("Recoil damage is not applied if target was protected")
{
    u32 j, k;
    static const u16 protectMoves[] = { MOVE_PROTECT, MOVE_DETECT, MOVE_KINGS_SHIELD, MOVE_BANEFUL_BUNKER, MOVE_SILK_TRAP, MOVE_OBSTRUCT, MOVE_SPIKY_SHIELD };
    static const u16 recoilMoves[] = { MOVE_VOLT_TACKLE, MOVE_HEAD_SMASH, MOVE_TAKE_DOWN, MOVE_DOUBLE_EDGE };
    u16 protectMove = MOVE_NONE;
    u16 recoilMove = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(protectMoves); j++)
    {
        for (k = 0; k < ARRAY_COUNT(recoilMoves); k++)
        {
            PARAMETRIZE { protectMove = protectMoves[j]; recoilMove = recoilMoves[k]; }
        }
    }


    GIVEN {
        ASSUME(gMovesInfo[MOVE_VOLT_TACKLE].recoil > 0);
        ASSUME(gMovesInfo[MOVE_HEAD_SMASH].recoil > 0);
        ASSUME(gMovesInfo[MOVE_TAKE_DOWN].recoil > 0);
        ASSUME(gMovesInfo[MOVE_DOUBLE_EDGE].recoil > 0);
        PLAYER(SPECIES_RAPIDASH);
        OPPONENT(SPECIES_BEAUTIFLY);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(opponent, protectMove); MOVE(player, recoilMove); }
        TURN {}
    } SCENE {
        // 1st turn
        MESSAGE("Foe Beautifly used Tackle!");
        MESSAGE("Rapidash used Tackle!");
        // 2nd turn
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        MESSAGE("Foe Beautifly protected itself!");
        // MESSAGE("Rapidash used recoilMove!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, recoilMove, player);
            MESSAGE("Rapidash is hit with recoil!");
        }
    }
}

SINGLE_BATTLE_TEST("Multi-hit moves don't hit a protected target and fail only once")
{
    u16 move = MOVE_NONE;

    PARAMETRIZE { move = MOVE_PROTECT; }
    PARAMETRIZE { move = MOVE_DETECT; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }
    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_ARM_THRUST].effect == EFFECT_MULTI_HIT);
        PLAYER(SPECIES_RAPIDASH);
        OPPONENT(SPECIES_BEAUTIFLY);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_ARM_THRUST); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        MESSAGE("Foe Beautifly protected itself!");
        MESSAGE("Rapidash used Arm Thrust!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_ARM_THRUST, player);
        MESSAGE("Foe Beautifly protected itself!");
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
            MESSAGE("Hit 2 time(s)!");
            MESSAGE("Hit 3 time(s)!");
            MESSAGE("Hit 4 time(s)!");
            MESSAGE("Hit 5 time(s)!");
        }
    }
}

DOUBLE_BATTLE_TEST("Wide Guard protects self and ally from multi-target moves")
{
    u16 move = MOVE_NONE;

    PARAMETRIZE { move = MOVE_TACKLE; }      // Single target
    PARAMETRIZE { move = MOVE_SURF; }        // All targets
    PARAMETRIZE { move = MOVE_HYPER_VOICE; } // 2 foes

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].target == MOVE_TARGET_SELECTED);
        ASSUME(gMovesInfo[MOVE_SURF].target == MOVE_TARGET_FOES_AND_ALLY);
        ASSUME(gMovesInfo[MOVE_HYPER_VOICE].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WIDE_GUARD); MOVE(playerLeft, move, target: opponentLeft); }
        TURN {}
    } SCENE {
        MESSAGE("Foe Wobbuffet used Wide Guard!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, opponentLeft);
        if (move == MOVE_TACKLE) {
            MESSAGE("Wobbuffet used Tackle!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
            HP_BAR(opponentLeft);
        } else if (move == MOVE_HYPER_VOICE) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(opponentLeft);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(opponentRight);
        } else { // Surf
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(opponentLeft);
            HP_BAR(playerRight);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Wide Guard can not fail on consecutive turns")
{
    u8 turns;

    PASSES_RANDOMLY(2, 2);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_HYPER_VOICE].target == MOVE_TARGET_BOTH);
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
            MESSAGE("Foe Wobbuffet used Wide Guard!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, opponentLeft);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(opponentLeft);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Quick Guard protects self and ally from priority moves")
{
    u16 move = MOVE_NONE;
    struct BattlePokemon *targetOpponent = NULL;

    PARAMETRIZE { move = MOVE_TACKLE; targetOpponent = opponentLeft; }
    PARAMETRIZE { move = MOVE_TACKLE; targetOpponent = opponentRight; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; targetOpponent = opponentLeft; }
    PARAMETRIZE { move = MOVE_QUICK_ATTACK; targetOpponent = opponentRight; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].priority == 0);
        ASSUME(gMovesInfo[MOVE_QUICK_ATTACK].priority == 1);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_QUICK_GUARD); MOVE(playerLeft, move, target:targetOpponent); }
        TURN {}
    } SCENE {
        MESSAGE("Foe Wobbuffet used Quick Guard!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_GUARD, opponentLeft);
        if (move == MOVE_TACKLE) {
            MESSAGE("Wobbuffet used Tackle!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
            HP_BAR(targetOpponent);
        } else if (move == MOVE_QUICK_ATTACK) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerLeft);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(targetOpponent);
        }
    }
}

DOUBLE_BATTLE_TEST("Quick Guard can not fail on consecutive turns")
{
    u8 turns;

    PASSES_RANDOMLY(2, 2);
    GIVEN {
        ASSUME(gMovesInfo[MOVE_QUICK_ATTACK].priority == 1);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_QUICK_GUARD); MOVE(playerLeft, MOVE_QUICK_ATTACK, target: opponentRight); }
        TURN { MOVE(opponentLeft, MOVE_QUICK_GUARD); MOVE(playerLeft, MOVE_QUICK_ATTACK, target: opponentRight); }
    } SCENE {
        for (turns = 0; turns < 2; turns++) {
            MESSAGE("Foe Wobbuffet used Quick Guard!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_GUARD, opponentLeft);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, playerLeft);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield protects self and ally from status moves")
{
    u16 move = MOVE_NONE;
    struct BattlePokemon *targetOpponent = NULL;

    PARAMETRIZE { move = MOVE_HYPER_VOICE; }
    PARAMETRIZE { move = MOVE_LEER; }
    PARAMETRIZE { move = MOVE_TACKLE; targetOpponent = opponentLeft; }
    PARAMETRIZE { move = MOVE_TACKLE; targetOpponent = opponentRight; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_LEER].target == MOVE_TARGET_BOTH);
        ASSUME(gMovesInfo[MOVE_HYPER_VOICE].target == MOVE_TARGET_BOTH);
        ASSUME(gMovesInfo[MOVE_HYPER_VOICE].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CRAFTY_SHIELD); (move == MOVE_TACKLE) ? MOVE(playerLeft, move, target:targetOpponent) : MOVE(playerLeft, move); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRAFTY_SHIELD, opponentLeft);
        if (move == MOVE_LEER) {
            MESSAGE("Wobbuffet used Leer!");
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Foe Wobbuffet protected itself!");
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        } else {
            if (move == MOVE_HYPER_VOICE || targetOpponent == opponentLeft) {
                NOT MESSAGE("Foe Wobbuffet protected itself!");
                HP_BAR(opponentLeft);
            } else if (move == MOVE_HYPER_VOICE || targetOpponent == opponentRight) {
                NOT MESSAGE("Foe Wobbuffet protected itself!");
                HP_BAR(opponentRight);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Protect does not block Confide")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_CONFIDE].effect == EFFECT_SPECIAL_ATTACK_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_CONFIDE); }
    } SCENE {
        MESSAGE("Wobbuffet used Confide!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFIDE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        NOT MESSAGE("Foe Wobbuffet protected itself!");
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield protects self and ally from Confide")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_CONFIDE].effect == EFFECT_SPECIAL_ATTACK_DOWN);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CRAFTY_SHIELD); MOVE(playerLeft, MOVE_CONFIDE, target: opponentLeft); MOVE(playerRight, MOVE_CONFIDE, target: opponentRight); }
    } SCENE {
        MESSAGE("Wobbuffet used Confide!");
        MESSAGE("Foe Wobbuffet protected itself!");
        MESSAGE("Wynaut used Confide!");
        MESSAGE("Foe Wynaut protected itself!");
    }
}

DOUBLE_BATTLE_TEST("Crafty Shield does not protect against moves that target all battlers")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FLOWER_SHIELD].target == MOVE_TARGET_ALL_BATTLERS);
        ASSUME(gSpeciesInfo[SPECIES_TANGELA].types[0] == TYPE_GRASS);
        ASSUME(gSpeciesInfo[SPECIES_TANGROWTH].types[0] == TYPE_GRASS);
        ASSUME(gSpeciesInfo[SPECIES_SUNKERN].types[0] == TYPE_GRASS);
        ASSUME(gSpeciesInfo[SPECIES_SUNFLORA].types[0] == TYPE_GRASS);
        PLAYER(SPECIES_TANGELA);
        PLAYER(SPECIES_TANGROWTH);
        OPPONENT(SPECIES_SUNKERN);
        OPPONENT(SPECIES_SUNFLORA);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CRAFTY_SHIELD); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(playerLeft, MOVE_FLOWER_SHIELD); MOVE(playerRight, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Tangela used Flower Shield!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Tangela's Defense rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Sunkern's Defense rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Tangrowth's Defense rose!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLOWER_SHIELD, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Sunflora's Defense rose!");
    }
}
