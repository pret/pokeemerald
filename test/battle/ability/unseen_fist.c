#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
    ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_KINGS_SHIELD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_SPIKY_SHIELD) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_BANEFUL_BUNKER) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_BURNING_BULWARK) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_OBSTRUCT) == EFFECT_PROTECT);
    ASSUME(GetMoveEffect(MOVE_SILK_TRAP) == EFFECT_PROTECT);
}

TO_DO_BATTLE_TEST("TODO: Write Unseen Fist (Ability) test titles")

SINGLE_BATTLE_TEST("Unseen Fist ignores Protect when user has Protective Pads, but not with Punching Glove", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; }
    PARAMETRIZE { item = ITEM_PUNCHING_GLOVE; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MACH_PUNCH));
        ASSUME(IsPunchingMove(MOVE_MACH_PUNCH));
        ASSUME(GetItemHoldEffect(ITEM_PROTECTIVE_PADS) == HOLD_EFFECT_PROTECTIVE_PADS);
        ASSUME(GetItemHoldEffect(ITEM_PUNCHING_GLOVE) == HOLD_EFFECT_PUNCHING_GLOVE);
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_MACH_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        if (item != ITEM_PUNCHING_GLOVE)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
        else
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);
    }
}

SINGLE_BATTLE_TEST("Unseen Fist bypasses protect effects without triggering their contact effects (Gens 8-9)")
{
    enum Move protectMove = MOVE_NONE;
    u8 loweredStat = 0;

    PARAMETRIZE { protectMove = MOVE_SPIKY_SHIELD;    loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_KINGS_SHIELD;    loweredStat = STAT_ATK; }
    PARAMETRIZE { protectMove = MOVE_BANEFUL_BUNKER;  loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_BURNING_BULWARK; loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_OBSTRUCT;        loweredStat = STAT_DEF; }
    PARAMETRIZE { protectMove = MOVE_SILK_TRAP;       loweredStat = STAT_SPEED; }

    GIVEN {
        WITH_CONFIG(B_UNSEEN_FIST_PIERCING_DRILL, GEN_9);
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, protectMove); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        NONE_OF {
            HP_BAR(player);
            STATUS_ICON(player, STATUS1_POISON);
            STATUS_ICON(player, STATUS1_BURN);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->status1, STATUS1_NONE);
        if (loweredStat != 0)
            EXPECT_EQ(player->statStages[loweredStat], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Unseen Fist continues bypassing protect effects after being replaced during a multi-strike move")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SURGING_STRIKES));
        ASSUME(GetMoveStrikeCount(MOVE_SURGING_STRIKES) == 3);
        ASSUME(GetMoveEffect(MOVE_OBSTRUCT) == EFFECT_PROTECT);
        PLAYER(SPECIES_URSHIFU_RAPID_STRIKE) { Ability(ABILITY_UNSEEN_FIST); Attack(1); }
        OPPONENT(SPECIES_COFAGRIGUS) { Ability(ABILITY_MUMMY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_OBSTRUCT); MOVE(player, MOVE_SURGING_STRIKES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OBSTRUCT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_MUMMY);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURGING_STRIKES, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->ability, ABILITY_MUMMY);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Unseen Fist no longer bypasses the contact effects of protect moves (Champions)")
{
    enum Move protectMove = MOVE_NONE;
    u8 loweredStat = 0;

    PARAMETRIZE { protectMove = MOVE_SPIKY_SHIELD;    loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_KINGS_SHIELD;    loweredStat = STAT_ATK; }
    PARAMETRIZE { protectMove = MOVE_BANEFUL_BUNKER;  loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_BURNING_BULWARK; loweredStat = 0; }
    PARAMETRIZE { protectMove = MOVE_OBSTRUCT;        loweredStat = STAT_DEF; }
    PARAMETRIZE { protectMove = MOVE_SILK_TRAP;       loweredStat = STAT_SPEED; }

    GIVEN {
        WITH_CONFIG(B_UNSEEN_FIST_PIERCING_DRILL, GEN_CHAMPIONS);
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, protectMove); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, protectMove, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        switch (protectMove)
        {
        case MOVE_BANEFUL_BUNKER:
            STATUS_ICON(player, poison: TRUE);
            break;
        case MOVE_BURNING_BULWARK:
            STATUS_ICON(player, burn: TRUE);
            break;
        default:
            break;
        }
    } THEN {
        switch (protectMove)
        {
        case MOVE_SPIKY_SHIELD:
            EXPECT_LT(player->hp, player->maxHP);
            break;
        case MOVE_KINGS_SHIELD:
        case MOVE_OBSTRUCT:
        case MOVE_SILK_TRAP:
            EXPECT_NE(player->statStages[loweredStat], DEFAULT_STAT_STAGE);
            break;
        default:
            break;
        }
    }
}

SINGLE_BATTLE_TEST("Unseen Fist deals 25% of the damage dealt to protected targets (Champions)", s16 damage)
{
    u32 genConfig;
    PARAMETRIZE { genConfig = GEN_9; }
    PARAMETRIZE { genConfig = GEN_CHAMPIONS; }

    GIVEN {
        WITH_CONFIG(B_UNSEEN_FIST_PIERCING_DRILL, genConfig);
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.25), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Unseen Fist still deals 100% of the damage dealt with Phantom Force (Champions)", s16 damage)
{
    u32 genConfig;
    PARAMETRIZE { genConfig = GEN_9; }
    PARAMETRIZE { genConfig = GEN_CHAMPIONS; }

    GIVEN {
        WITH_CONFIG(B_UNSEEN_FIST_PIERCING_DRILL, genConfig);
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PHANTOM_FORCE); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_PROTECT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PHANTOM_FORCE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Unseen Fist KOs protected targets with OHKO moves (Champions)")
{
    GIVEN {
        WITH_CONFIG(B_UNSEEN_FIST_PIERCING_DRILL, GEN_CHAMPIONS);
        PLAYER(SPECIES_EXCADRILL) { Item(ITEM_EXCADRITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_HORN_DRILL, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HORN_DRILL, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet fainted!");
    }
}

DOUBLE_BATTLE_TEST("Unseen Fist shows its ability pop-up on each affected target (Champions)")
{
    enum Move move = MOVE_NONE;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_BRUTAL_SWING; }

    GIVEN {
        PLAYER(SPECIES_URSHIFU) { Ability(ABILITY_UNSEEN_FIST); }
        PLAYER(SPECIES_GARCHOMP) {Ability(ABILITY_ROUGH_SKIN); }
        OPPONENT(SPECIES_GLIMMORA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_PROTECT);
            MOVE(opponentRight, MOVE_PROTECT);
            MOVE(playerLeft, move, target: opponentLeft);
            MOVE(playerRight, MOVE_PROTECT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        if (move == MOVE_BRUTAL_SWING)
        {
            EFFECTIVENESS_SE(opponentLeft, SE_SUPER_EFFECTIVE);
        } else {
            EFFECTIVENESS_SE(opponentLeft, SE_NOT_EFFECTIVE);
        }
        HP_BAR(opponentLeft);
        ABILITY_POPUP(playerLeft);
        if (move == MOVE_BRUTAL_SWING)
        {
            ABILITY_POPUP(playerLeft);
            ABILITY_POPUP(playerLeft);
        }
    }
}
