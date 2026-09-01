#include "global.h"
#include "test/battle.h"

// Basic Functionality
SINGLE_BATTLE_TEST("(Z-MOVE) Z-Moves do not retain priority")
{
    GIVEN {
        WITH_CONFIG(B_MEGA_EVO_TURN_ORDER, GEN_7); // TODO: Decouple this config from other gimmicks
        ASSUME(GetMoveType(MOVE_QUICK_ATTACK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH);
               MOVE(player, MOVE_QUICK_ATTACK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Moves are not affected by -ate abilities")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 1) == TYPE_FLYING);
        PLAYER(SPECIES_AURORUS) { Ability(ABILITY_REFRIGERATE); Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_SWELLOW);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        NOT { MESSAGE("It's super effective!"); }
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Moves are affected by Ion Deluge")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_ION_DELUGE) == EFFECT_ION_DELUGE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_SWELLOW);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ION_DELUGE); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        MESSAGE("It's super effective!");
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Moves deal 1/4 damage through protect", s16 damage)
{
    bool32 protected;
    PARAMETRIZE { protected = TRUE; }
    PARAMETRIZE { protected = FALSE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_PROTECT) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (protected)
            TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); MOVE(opponent, MOVE_PROTECT); }
        else
            TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(4), results[1].damage);
    }
}

// Status Z-Effects
SINGLE_BATTLE_TEST("(Z-MOVE) Z_EFFECT_RESET_STATS clears a battler's negative stat stages")
{
    GIVEN {
        ASSUME(GetMoveZEffect(MOVE_LEECH_SEED) == Z_EFFECT_RESET_STATS);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_GRASSIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); MOVE(opponent, MOVE_SCREECH); }
        TURN { MOVE(player, MOVE_LEECH_SEED, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z_EFFECT_ALL_STATS_UP raises all of a battler's stat stages by one")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_CELEBRATE) == TYPE_NORMAL);
        ASSUME(GetMoveZEffect(MOVE_CELEBRATE) == Z_EFFECT_ALL_STATS_UP_1);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z_EFFECT_BOOST_CRITS raises a battler's critical hit ratio by 2 stages")
{
    u32 genConfig = 0, chance;
    for (u32 j = GEN_1; j <= GEN_5; j++)
        PARAMETRIZE { genConfig = j; chance = 4; } // 25%
    for (u32 j = GEN_6; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; chance = 2; } // 50%
    PASSES_RANDOMLY(1, chance, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetMoveType(MOVE_FORESIGHT) == TYPE_NORMAL);
        ASSUME(GetMoveZEffect(MOVE_FORESIGHT) == Z_EFFECT_BOOST_CRITS);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FORESIGHT, gimmick: GIMMICK_Z_MOVE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FORESIGHT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        MESSAGE("A critical hit!");
    }
}

DOUBLE_BATTLE_TEST("(Z-MOVE) Z_EFFECT_FOLLOW_ME redirects attacks to the user")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_DESTINY_BOND) == TYPE_GHOST);
        ASSUME(GetMoveZEffect(MOVE_DESTINY_BOND) == Z_EFFECT_FOLLOW_ME);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_GHOSTIUM_Z); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DESTINY_BOND, gimmick: GIMMICK_Z_MOVE);
               MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DESTINY_BOND, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        NOT { HP_BAR(playerRight); }
        HP_BAR(playerLeft);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z_EFFECT_RESTORE_REPLACEMENT_HP fully heals the replacement battler's HP")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_PARTING_SHOT) == TYPE_DARK);
        ASSUME(GetMoveZEffect(MOVE_PARTING_SHOT) == Z_EFFECT_RESTORE_REPLACEMENT_HP);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_DARKINIUM_Z); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT, gimmick: GIMMICK_Z_MOVE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

// This tests the functionality of Z_EFFECT_RECOVER_HP and Z_EFFECT_ATK_UP_1 (and thus by extension all stat-up Z-effects)
SINGLE_BATTLE_TEST("(Z-MOVE) Z_EFFECT_CURSE activates Z_EFFECT_RECOVER_HP or Z_EFFECT_ATK_UP_1 depending on the type of the battler")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_DUSCLOPS; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_CURSE) == TYPE_GHOST);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_GHOST);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_GHOST);
        ASSUME(GetSpeciesType(SPECIES_DUSCLOPS, 0) == TYPE_GHOST);
        ASSUME(GetMoveZEffect(MOVE_CURSE) == Z_EFFECT_CURSE);
        PLAYER(species) { Item(ITEM_GHOSTIUM_Z); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CURSE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        if (species == SPECIES_DUSCLOPS) {
            HP_BAR(player);
            NOT { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player); }
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CURSE, player);
            HP_BAR(player);
        } else {
            NOT { HP_BAR(player); }
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CURSE, player);
            NOT { HP_BAR(player); }
        }
    } THEN {
        if (species == SPECIES_DUSCLOPS) {
            EXPECT_MUL_EQ(player->maxHP, UQ_4_12(0.50), player->hp); // heal to full HP then cut by half
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        } else {
            EXPECT_EQ(player->hp, 1);
            EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2); // +1 from Curse, +1 from Z-Effect
        }
    }
}

// Specific Z-Move Interactions
SINGLE_BATTLE_TEST("(Z-MOVE) Z-Mirror Move raises the user's attack by two stages and copies the last used non-status move as a Z-Move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MIRROR_MOVE) == TYPE_FLYING);
        ASSUME(GetMoveZEffect(MOVE_MIRROR_MOVE) == Z_EFFECT_ATK_UP_2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FLYINIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_MIRROR_MOVE, gimmick: GIMMICK_Z_MOVE); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        // extra turn to make sure that everything resets properly
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Mirror Move raises the user's attack by two stages and copies the last used status move regularly")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_MIRROR_MOVE) == TYPE_FLYING);
        ASSUME(GetMoveZEffect(MOVE_MIRROR_MOVE) == Z_EFFECT_ATK_UP_2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FLYINIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCREECH); MOVE(player, MOVE_MIRROR_MOVE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2); // Z-Screech would cause an additional attack stat stage (reaching +3)
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Copycat raises the user's accuracy by one stage and copies the last used non-status move as a Z-Move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_COPYCAT) == TYPE_NORMAL);
        ASSUME(GetMoveZEffect(MOVE_COPYCAT) == Z_EFFECT_ACC_UP_1);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_COPYCAT, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ACC], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Me First raises the user's speed by two stages and copies the last used non-status move as a Z-Move with boosted damage", s16 damage)
{
    u32 meFirst;
    PARAMETRIZE { meFirst = TRUE; }
    PARAMETRIZE { meFirst = FALSE; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_ME_FIRST) == TYPE_NORMAL);
        ASSUME(GetMoveZEffect(MOVE_ME_FIRST) == Z_EFFECT_SPD_UP_2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (meFirst)
            TURN { MOVE(player, MOVE_ME_FIRST, gimmick: GIMMICK_Z_MOVE); MOVE(opponent, MOVE_SCRATCH); }
        else
            TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        if (meFirst)
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } THEN {
        if (meFirst)
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(1.50), results[0].damage);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Nature Power transforms into different Z-Moves based on the current terrain")
{
    enum Move terrainMove = MOVE_NONE;
    enum Move zMove = MOVE_NONE;
    PARAMETRIZE { terrainMove = MOVE_ELECTRIC_TERRAIN;  zMove = gTypesInfo[TYPE_ELECTRIC].zMove; }
    PARAMETRIZE { terrainMove = MOVE_PSYCHIC_TERRAIN;   zMove = gTypesInfo[TYPE_PSYCHIC].zMove; }
    PARAMETRIZE { terrainMove = MOVE_GRASSY_TERRAIN;    zMove = gTypesInfo[TYPE_GRASS].zMove; }
    PARAMETRIZE { terrainMove = MOVE_MISTY_TERRAIN;     zMove = gTypesInfo[TYPE_FAIRY].zMove; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_NATURE_POWER) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, terrainMove); }
        TURN { MOVE(player, MOVE_NATURE_POWER, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, terrainMove, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, zMove, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Hidden Power always transforms into Breakneck Blitz")
{
    u8 iv;
    PARAMETRIZE { iv = 0; } // test different Hidden Power types
    PARAMETRIZE { iv = 10; }
    PARAMETRIZE { iv = 21; }
    PARAMETRIZE { iv = 31; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); AttackIV(iv); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Weather Ball transforms into different Z-Moves based on current weather")
{
    enum Move weatherMove = MOVE_NONE;
    enum Move zMove = MOVE_NONE;
    PARAMETRIZE { weatherMove = MOVE_RAIN_DANCE;  zMove = gTypesInfo[TYPE_WATER].zMove; }
    PARAMETRIZE { weatherMove = MOVE_SUNNY_DAY;   zMove = gTypesInfo[TYPE_FIRE].zMove; }
    PARAMETRIZE { weatherMove = MOVE_SANDSTORM;   zMove = gTypesInfo[TYPE_ROCK].zMove; }
    PARAMETRIZE { weatherMove = MOVE_HAIL;        zMove = gTypesInfo[TYPE_ICE].zMove; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WEATHER_BALL) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, weatherMove); }
        TURN { MOVE(player, MOVE_WEATHER_BALL, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, weatherMove, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, zMove, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Sleep Talk transforms a used non-status move into a Z-Move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SLEEP_TALK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Status1(STATUS1_SLEEP); Moves(MOVE_SLEEP_TALK, MOVE_ABSORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK, gimmick: GIMMICK_Z_MOVE); }
        TURN { MOVE(player, MOVE_SLEEP_TALK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BLOOM_DOOM, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Sleep Talk turns Weather Ball into Breakneck Blitz even under rain")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SLEEP_TALK) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); Status1(STATUS1_SLEEP); Moves(MOVE_SLEEP_TALK, MOVE_WEATHER_BALL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); MOVE(player, MOVE_SLEEP_TALK, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Powder blocks Fire type Z-Moves and deals 25% of maximum HP to the user")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FIRIUM_Z); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_EMBER, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INFERNO_OVERDRIVE, player);
    } THEN {
        EXPECT_MUL_EQ(player->maxHP, UQ_4_12(0.75), player->hp);
    }
}

DOUBLE_BATTLE_TEST("(Z-MOVE) Powder blocks Fire type Z-Moves (from Z-Mirror Move)")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_MIRROR_MOVE) == TYPE_FLYING);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FLYINIUM_Z); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(opponentLeft, MOVE_EMBER, target: playerLeft); MOVE(playerLeft, MOVE_MIRROR_MOVE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_INFERNO_OVERDRIVE, playerLeft);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Powder blocks Fire type Z-Moves but not boosts granted")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WILL_O_WISP) == TYPE_FIRE);
        ASSUME(GetMoveZEffect(MOVE_WILL_O_WISP) == Z_EFFECT_ATK_UP_1);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_FIRIUM_Z); }
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER); MOVE(player, MOVE_WILL_O_WISP, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_WILL_O_WISP, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

// Miscellaneous Interactions
DOUBLE_BATTLE_TEST("(Z-MOVE) Instruct fails if the target last used a Z-Move")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft, gimmick: GIMMICK_Z_MOVE);
               MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, playerLeft);
        MESSAGE("Wynaut used Instruct!");
        MESSAGE("But it failed!");
    }
}

DOUBLE_BATTLE_TEST("(Z-MOVE) Dancer does not use a Z-Move if the battler has used a Z-Move the same turn")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_DANCER); Item(ITEM_NORMALIUM_Z); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft, gimmick: GIMMICK_Z_MOVE);
               MOVE(playerRight, MOVE_FIERY_DANCE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerRight);
        ABILITY_POPUP(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIERY_DANCE, playerLeft);
    }
}

// Signature Z-Moves
SINGLE_BATTLE_TEST("(Z-MOVE) Light That Burns the Sky uses the battler's highest attacking stat", s16 damage)
{
    bool32 useSwordsDance;
    PARAMETRIZE { useSwordsDance = FALSE; }
    PARAMETRIZE { useSwordsDance = TRUE; }
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_NECROZMA_DUSK_MANE) { Item(ITEM_ULTRANECROZIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }; // hits hard lol
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_ULTRA_BURST); }
        if (useSwordsDance)
            TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_PHOTON_GEYSER, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ULTRA_BURST, player); // implicitly testing double gimmicks :^)
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_THAT_BURNS_THE_SKY, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) 10,000,000 Volt Thunderbolt has an increased critical hit ratio")
{
    u32 genConfig, chance;
    PARAMETRIZE { genConfig = GEN_1; chance = 1; }
    for (u32 j = GEN_2; j <= GEN_5; j++)
        PARAMETRIZE { genConfig = j; chance = 4; }
    for (u32 j = GEN_6; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; chance = 2; }
    PASSES_RANDOMLY(1, chance, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        ASSUME(GetMoveCriticalHitStage(MOVE_10_000_000_VOLT_THUNDERBOLT) == 2);
        ASSUME(GetSpeciesBaseSpeed(SPECIES_PIKACHU_PARTNER) == 90);
        PLAYER(SPECIES_PIKACHU_PARTNER) { Item(ITEM_PIKASHUNIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_10_000_000_VOLT_THUNDERBOLT, player);
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Stoked Sparksurfer paralyzes the target")
{
    GIVEN {
        ASSUME(GetMoveAdditionalEffectById(MOVE_STOKED_SPARKSURFER, 0)->moveEffect == MOVE_EFFECT_PARALYSIS);
        PLAYER(SPECIES_RAICHU_ALOLA) { Item(ITEM_ALORAICHIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STOKED_SPARKSURFER, player);
        STATUS_ICON(opponent, STATUS1_PARALYSIS);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Extreme Evoboost boosts all the user's stats by two stages")
{
    GIVEN {
        WITH_CONFIG(B_LAST_RESORT_SELECTABLE, GEN_9); // The test will fail without this on GEN_CHAMPIONS
        ASSUME(GetMoveEffect(MOVE_EXTREME_EVOBOOST) == EFFECT_EXTREME_EVOBOOST);
        PLAYER(SPECIES_EEVEE) { Item(ITEM_EEVIUM_Z); Moves(MOVE_POUND, MOVE_LAST_RESORT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LAST_RESORT, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXTREME_EVOBOOST, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Genesis Supernova sets up psychic terrain")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_GENESIS_SUPERNOVA, MOVE_EFFECT_PSYCHIC_TERRAIN));
        PLAYER(SPECIES_MEW) { Item(ITEM_MEWNIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC, gimmick: GIMMICK_Z_MOVE); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GENESIS_SUPERNOVA, player);
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player); }
        MESSAGE("The opposing Wobbuffet is protected by the Psychic Terrain!");
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Genesis Supernova sets up psychic terrain when the target is behind a Substitute")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_GENESIS_SUPERNOVA, MOVE_EFFECT_PSYCHIC_TERRAIN));
        PLAYER(SPECIES_MEW) { Item(ITEM_MEWNIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_PSYCHIC, gimmick: GIMMICK_Z_MOVE); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GENESIS_SUPERNOVA, player);
        SUB_HIT(opponent);
        NOT { ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player); }
        MESSAGE("The opposing Wobbuffet is protected by the Psychic Terrain!");
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Splintered Stormshards removes terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPLINTERED_STORMSHARDS) == EFFECT_ICE_SPINNER);
        PLAYER(SPECIES_LYCANROC_DUSK) { Item(ITEM_LYCANIUM_Z); }
        OPPONENT(SPECIES_TAPU_LELE) { Ability(ABILITY_PSYCHIC_SURGE); HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_STONE_EDGE, gimmick: GIMMICK_Z_MOVE); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLINTERED_STORMSHARDS, player);
        MESSAGE("The weirdness disappeared from the battlefield!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Splintered Stormshards removes terrain when the target is behind a Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPLINTERED_STORMSHARDS) == EFFECT_ICE_SPINNER);
        PLAYER(SPECIES_LYCANROC_DUSK) { Item(ITEM_LYCANIUM_Z); }
        OPPONENT(SPECIES_TAPU_LELE) { Ability(ABILITY_PSYCHIC_SURGE); HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_STONE_EDGE, gimmick: GIMMICK_Z_MOVE); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPLINTERED_STORMSHARDS, player);
        SUB_HIT(opponent);
        MESSAGE("The weirdness disappeared from the battlefield!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_ATTACK, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Clangorous Soulblaze boosts all the user's stats by one stage")
{
    GIVEN {
        ASSUME_MOVE_EFFECT_STAT_CHANGE(
            MOVE_CLANGOROUS_SOULBLAZE, self: TRUE,
            attack: 1, defense: 1,
            spAtk: 1, spDef: 1, speed: 1
        );
        PLAYER(SPECIES_KOMMO_O) { Item(ITEM_KOMMONIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CLANGING_SCALES, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLANGOROUS_SOULBLAZE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Guardian of Alola deals 75% of the target's current HP")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GUARDIAN_OF_ALOLA) == EFFECT_FIXED_PERCENT_DAMAGE);
        PLAYER(SPECIES_TAPU_FINI) { Item(ITEM_TAPUNIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_NATURES_MADNESS, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUARDIAN_OF_ALOLA, player);
    } THEN {
        EXPECT_MUL_EQ(opponent->maxHP, UQ_4_12(0.25), opponent->hp);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Searing Sunraze Smash ignores the target's abilities")
{
    GIVEN {
        PLAYER(SPECIES_SOLGALEO) { Item(ITEM_SOLGANIUM_Z); }
        OPPONENT(SPECIES_LAPRAS) { Ability(ABILITY_BATTLE_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNSTEEL_STRIKE, gimmick: GIMMICK_Z_MOVE, criticalHit: TRUE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEARING_SUNRAZE_SMASH, player);
        HP_BAR(opponent);
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Revelation Dance always transforms into Breakneck Blitz")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_ORICORIO_BAILE; }
    PARAMETRIZE { species = SPECIES_ORICORIO_PAU; }
    PARAMETRIZE { species = SPECIES_ORICORIO_POM_POM; }
    PARAMETRIZE { species = SPECIES_ORICORIO_SENSU; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_REVELATION_DANCE) == TYPE_NORMAL);
        PLAYER(species) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REVELATION_DANCE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Every battler can use Z-Moves - Singles")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = player; }
    PARAMETRIZE { battler = opponent; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, battler);
    }
}

DOUBLE_BATTLE_TEST("(Z-MOVE) Every battler can use Z-Moves - Doubles")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, battler);
    }
}

MULTI_BATTLE_TEST("(Z-MOVE) Every battler can use Z-Moves - Multi")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        PARTNER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, battler);
    }
}

TWO_VS_ONE_BATTLE_TEST("(Z-MOVE) Every battler can use Z-Moves - 2v1")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        PARTNER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, battler);
    }
}

ONE_VS_TWO_BATTLE_TEST("(Z-MOVE) Every battler can use Z-Moves - 1v2")
{
    struct BattlePokemon *battler = NULL;
    PARAMETRIZE { battler = playerLeft; }
    PARAMETRIZE { battler = playerRight; }
    PARAMETRIZE { battler = opponentLeft; }
    PARAMETRIZE { battler = opponentRight; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT_A(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT_B(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
    } WHEN {
        TURN { MOVE(battler, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, battler);
    }
}

SINGLE_BATTLE_TEST("(Z-MOVE) Z-Move power is based on the base move", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SCRATCH; }
    PARAMETRIZE { move = MOVE_MEGA_KICK; }

    GIVEN {
        ASSUME(GetMovePower(MOVE_SCRATCH) == 40);
        ASSUME(GetMovePower(MOVE_MEGA_KICK) == 120);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[1].damage, results[0].damage);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected under Taunt")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_NORMALIUM_Z); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAUNT); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected while Tormented")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TORMENT) == EFFECT_TORMENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_NORMALIUM_Z); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TORMENT); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected while Disabled")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DISABLE) == EFFECT_DISABLE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_NORMALIUM_Z); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_DISABLE); }
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected while Encored")
{
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_5);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_NORMALIUM_Z); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_ENCORE); }
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected while Imprisoned")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_IMPRISON) == EFFECT_IMPRISON);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_NORMALIUM_Z); Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_IMPRISON, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_IMPRISON); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_IMPRISON, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected under Heal Block")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        ASSUME(GetMoveEffect(MOVE_RECOVER) == EFFECT_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); HP(1); Item(ITEM_NORMALIUM_Z); Moves(MOVE_RECOVER, MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_RECOVER, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BLOCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected and executed under Throat Chop")
{
    GIVEN {
        ASSUME(IsSoundMove(MOVE_GROWL));
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_NORMALIUM_Z); Moves(MOVE_GROWL, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_THROAT_CHOP); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_GROWL, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Moves can be selected under Gravity but Gravity still prevents execution")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRAVITY) == EFFECT_GRAVITY);
        ASSUME(IsMoveGravityBanned(MOVE_FLY));
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_FLYINIUM_Z); Moves(MOVE_FLY, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRAVITY); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_FLY, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAVITY, opponent);
        MESSAGE("Wobbuffet can't use Supersonic Skystrike because of gravity!");
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Z-Move: Z-Belch can be selected without eating a Berry")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BELCH) == EFFECT_BELCH);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POISONIUM_Z); Moves(MOVE_BELCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        HP_BAR(opponent);
    }
}

TO_DO_BATTLE_TEST("(Z-MOVE) Stat changes from status Z-Moves are not inverted by Contrary")
TO_DO_BATTLE_TEST("(Z-MOVE) Stat changes from Extreme Evoboost are inverted by Contrary")
TO_DO_BATTLE_TEST("(Z-MOVE) Stat changes from Clangorous Soulblaze are inverted by Contrary")
