#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
    ASSUME(GetMoveDamagePercentage(MOVE_SUPER_FANG) == 50);
}

SINGLE_BATTLE_TEST("Emergency Exit switches out when taking 50% max-hp damage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(262); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit does not switch out when going below 50% max-HP but healed via held item back above the threshold")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(262); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit switches out when going below 50% max-HP but healing via held item is not enough to go back above the threshold")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(133); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

DOUBLE_BATTLE_TEST("Only the fastest Wimp Out (Emergency Exit) user switches out")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_ZAPDOS) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WIMPOD) { Speed(1); Ability(ABILITY_WIMP_OUT); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WIMPOD) { Speed(2); Ability(ABILITY_WIMP_OUT); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); SEND_OUT(opponentRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        ABILITY_POPUP(opponentRight, ABILITY_WIMP_OUT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit activates when taking residual damage and falling under 50% max-hp - Burn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(134); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit activates when healing from under 50% max-hp and taking residual damage to under 50% max-hp - Burn")
{
    // Might fail if users set healing higher than burn damage
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AQUA_RING) == EFFECT_AQUA_RING);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(130); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AQUA_RING); SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit activates when taking residual damage and falling under 50% max-hp - Weather")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(134); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit doesn't activate when taking residual damage to under 50% max-hp then healing above 50% max-hp - Weather")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(134); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        HP_BAR(opponent);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit activates when healing from under 50% max-hp and taking residual damage to under 50% max-hp - Sticky Barb")
{
    // Might fail if users set healing higher than sticky barb damage
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_AQUA_RING) == EFFECT_AQUA_RING);
        ASSUME(GetItemHoldEffect(ITEM_STICKY_BARB) == HOLD_EFFECT_STICKY_BARB);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(130); Item(ITEM_STICKY_BARB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AQUA_RING); SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit activates when taking residual damage and falling under 50% max-hp - Salt Cure")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SALT_CURE, MOVE_EFFECT_SALT_CURE));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SALT_CURE); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SALT_CURE, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

// This is a real interaction according to jpwiki, despite Golisopod not being on the field anymore
DOUBLE_BATTLE_TEST("Emergency Exit activates when taking Sea of Fire damage and can be healed by Grassy Terrain after leaving the field")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FIRE_PLEDGE) == EFFECT_PLEDGE);
        ASSUME(GetMoveEffect(MOVE_GRASS_PLEDGE) == EFFECT_PLEDGE);
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_GRASSY_TERRAIN) == B_TERRAIN_GRASSY);
        ASSUME(GetItemHoldEffect(ITEM_AIR_BALLOON) == HOLD_EFFECT_AIR_BALLOON);
        // Air Balloon is ignored once the battler leaves the field
        PLAYER(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(132); Item(ITEM_AIR_BALLOON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FIRE_PLEDGE, target: playerRight);
               MOVE(opponentRight, MOVE_GRASS_PLEDGE, target: playerRight);
               MOVE(playerRight, MOVE_GRASSY_TERRAIN);
               SEND_OUT(playerLeft, 2); }
    } SCENE {
        HP_BAR(playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_EMERGENCY_EXIT);
        MESSAGE("Golisopod is healed by the grassy terrain!");
        HP_BAR(playerLeft);
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

DOUBLE_BATTLE_TEST("Emergency Exit activates when taking residual damage and battler doesn't get affected by events until replacement switches in")
{
    // Leech Seed damage occurs first, then Poison and Salt Cure damage
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SALT_CURE, MOVE_EFFECT_SALT_CURE));
        ASSUME(GetMoveEffect(MOVE_LEECH_SEED) == EFFECT_LEECH_SEED);
        PLAYER(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(160); Status1(STATUS1_POISON); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SALT_CURE, target: playerLeft);
               MOVE(opponentRight, MOVE_LEECH_SEED, target: playerLeft);
               SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SALT_CURE, opponentLeft);
        HP_BAR(playerLeft);

        // Leech Seed damage and healing
        HP_BAR(playerLeft);
        HP_BAR(opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_EMERGENCY_EXIT);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SALT_CURE_DAMAGE, playerLeft);
            HP_BAR(playerLeft);
        }
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

WILD_BATTLE_TEST("Emergency Exit makes the pokemon flee during wild battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(262); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_MON_TELEPORTED);
    }
}

WILD_BATTLE_TEST("Emergency Exit activates when taking residual damage and falling under 50% max-hp (wild battle)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(134); Status1(STATUS1_BURN); }
    } WHEN {
        TURN {}
    } SCENE {
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_MON_TELEPORTED);
    }
}

WILD_BATTLE_TEST("Emergency Exit makes the player ran during wild battle")
{
    GIVEN {
        PLAYER(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(262); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPER_FANG, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_EMERGENCY_EXIT);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_PLAYER_TELEPORTED);
    }
}

WILD_BATTLE_TEST("Emergency Exit activates when taking residual damage and falling under 50% max-hp (wild battle player side)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        PLAYER(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(134); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
    } SCENE {
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_EMERGENCY_EXIT);
    } THEN {
        EXPECT_EQ(gBattleOutcome, B_OUTCOME_PLAYER_TELEPORTED);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit will trigger due to recoil damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIND_BLOWN) == EFFECT_MAX_HP_50_RECOIL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(262); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIND_BLOWN); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, opponent);
        HP_BAR(player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit will not trigger due to confusion damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(133); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_CONFUSE_RAY);
            MOVE(opponent, MOVE_POUND);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit is not triggered by Pain Split")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PAIN_SPLIT) == EFFECT_PAIN_SPLIT);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(133); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PAIN_SPLIT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PAIN_SPLIT, player);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit will trigger due to Jump Kick recoil")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_JUMP_KICK) == EFFECT_RECOIL_IF_MISS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(263); HP(262); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_JUMP_KICK, hit: FALSE); SEND_OUT(opponent, 1); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_JUMP_KICK, opponent);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit activates and attacker's Throat Spray activates before replacement enters")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_THROAT_SPRAY) == HOLD_EFFECT_THROAT_SPRAY);
        ASSUME(IsSoundMove(MOVE_HYPER_VOICE));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_THROAT_SPRAY); }
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); HP(251); MaxHP(500); }
        OPPONENT(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_HYPER_VOICE); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        ABILITY_POPUP(opponent, ABILITY_INTIMIDATE);
    }
}

SINGLE_BATTLE_TEST("Emergency Exit will trigger even if Shell Bell heals user back above half HP")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIND_BLOWN) == EFFECT_MAX_HP_50_RECOIL);
        ASSUME(GetItemHoldEffect(ITEM_SHELL_BELL) == HOLD_EFFECT_SHELL_BELL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); Item(ITEM_SHELL_BELL); MaxHP(263); HP(262); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIND_BLOWN); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIND_BLOWN, opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_EMERGENCY_EXIT);
    }
}
