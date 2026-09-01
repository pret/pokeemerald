#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_COUNTER) == EFFECT_REFLECT_DAMAGE);
    ASSUME(GetMoveReflectDamage_DamagePercent(MOVE_COUNTER) == 200);
    ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_COUNTER) == (1u << DAMAGE_CATEGORY_PHYSICAL));

    ASSUME(GetMoveEffect(MOVE_MIRROR_COAT) == EFFECT_REFLECT_DAMAGE);
    ASSUME(GetMoveReflectDamage_DamagePercent(MOVE_MIRROR_COAT) == 200);
    ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_MIRROR_COAT) == (1u << DAMAGE_CATEGORY_SPECIAL));

    ASSUME(GetMoveEffect(MOVE_METAL_BURST) == EFFECT_REFLECT_DAMAGE);
    ASSUME(GetMoveReflectDamage_DamagePercent(MOVE_METAL_BURST) == 150);
    ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_METAL_BURST) == (1u << DAMAGE_CATEGORY_PHYSICAL | 1u << DAMAGE_CATEGORY_SPECIAL));

    ASSUME(GetMoveCategory(MOVE_POUND) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Reflect Damage: Counter is not affected by Protect effects if it doesn't damage")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }
    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_BURNING_BULWARK; }
    PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    PARAMETRIZE { move = MOVE_OBSTRUCT; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, player);
            if (move == MOVE_SPIKY_SHIELD) {
                HP_BAR(player);
            } else if (move == MOVE_BANEFUL_BUNKER) {
                STATUS_ICON(player, STATUS1_POISON);
            } else if (move == MOVE_BURNING_BULWARK) {
                STATUS_ICON(player, STATUS1_BURN);
            } else { // all others cause a stat drop
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Counter is affected by Protect effects if it was damaged by that battler")
{
    // Commented moves are instructBanned.
    enum Move move;

    PARAMETRIZE { move = MOVE_SPIKY_SHIELD; }
    PARAMETRIZE { move = MOVE_BANEFUL_BUNKER; }
    PARAMETRIZE { move = MOVE_BURNING_BULWARK; }
    // PARAMETRIZE { move = MOVE_KINGS_SHIELD; }
    PARAMETRIZE { move = MOVE_SILK_TRAP; }
    // PARAMETRIZE { move = MOVE_OBSTRUCT; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WYNAUT) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponentLeft, move); MOVE(playerLeft, MOVE_COUNTER); }
        TURN { MOVE(opponentRight, MOVE_INSTRUCT, target: opponentLeft, WITH_RNG(RNG_PROTECT_FAIL, 1)); MOVE(opponentLeft, MOVE_POUND, target: playerLeft); MOVE(playerLeft, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, playerLeft);
        if (move == MOVE_SPIKY_SHIELD) {
            HP_BAR(playerLeft);
        } else if (move == MOVE_BANEFUL_BUNKER) {
            STATUS_ICON(playerLeft, STATUS1_POISON);
        } else if (move == MOVE_BURNING_BULWARK) {
            STATUS_ICON(playerLeft, STATUS1_BURN);
        } else if (move == MOVE_SILK_TRAP) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Counter will do twice as much damage received from the opponent")
{
    s16 normalDmg;
    s16 counterDmg;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POUND); MOVE(player, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponent);
        HP_BAR(player, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, player);
        HP_BAR(opponent, captureDamage: &counterDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), counterDmg);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Counter ignores ally Pokémon's attack from Gen 5 onwards")
{
    u32 config;
    PARAMETRIZE { config = GEN_5; }
    PARAMETRIZE { config = GEN_4; }
    GIVEN {
        WITH_CONFIG(B_COUNTER_MIRROR_COAT_ALLY, config);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_POUND, target: playerRight);
            MOVE(playerLeft, MOVE_POUND, target: playerRight);
            MOVE(playerRight, MOVE_COUNTER);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        if (config >= GEN_5) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, playerRight);
            HP_BAR(opponentLeft);
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, playerRight);
                HP_BAR(opponentLeft);
                HP_BAR(playerLeft);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Counter hits the last opponent that hit the user")
{
    s16 normalDmg;
    s16 counterDmg;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_POUND, target: playerLeft);
            MOVE(opponentRight, MOVE_SLAM, target: playerLeft);
            MOVE(playerLeft, MOVE_COUNTER);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLAM, opponentRight);
        HP_BAR(playerLeft, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, playerLeft);
        HP_BAR(opponentRight, captureDamage: &counterDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), counterDmg);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Counter respects Follow me")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_FOLLOW_ME);
            MOVE(opponentLeft, MOVE_POUND, target: playerLeft);
            MOVE(playerLeft, MOVE_COUNTER, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Counter fails if mon that damaged Counter user is no longer on the field (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(B_COUNTER_TRY_HIT_PARTNER, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_POUND, target: playerLeft);
            MOVE(playerRight, MOVE_POUND, target: opponentLeft);
            MOVE(playerLeft, MOVE_COUNTER, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Counter deals 1 damage when the attack received is blocked by Disguise")
{
    s16 counterDmg;
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SHADOW_SNEAK) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHADOW_SNEAK); MOVE(player, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHADOW_SNEAK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, player);
        HP_BAR(opponent, captureDamage: &counterDmg);
    } THEN {
        EXPECT_EQ(counterDmg, 1);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Counter works when surviving OHKO move")
{
    s16 normalDmg;
    s16 counterDmg;
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_FISSURE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) {MaxHP(100); HP(100); Item(ITEM_FOCUS_SASH);};
        OPPONENT(SPECIES_WOBBUFFET) {MaxHP(500); HP(500);};
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); MOVE(player, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, opponent);
        HP_BAR(player, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, player);
        HP_BAR(opponent, captureDamage: &counterDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), counterDmg);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Counter works when surviving OHKO move with Disguise")
{
    s16 counterDmg;
    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_8);
        ASSUME(GetMoveCategory(MOVE_FISSURE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); MaxHP(64); HP(64);};
        OPPONENT(SPECIES_WOBBUFFET) {MaxHP(500); HP(500);};
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); MOVE(player, MOVE_COUNTER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, player);
        HP_BAR(opponent, captureDamage: &counterDmg);
    } THEN {
        EXPECT_EQ(counterDmg, 1);
    }
}

// Gen 1
TO_DO_BATTLE_TEST("Reflect Damage: Counter can only counter Normal and Fighting-type moves (Gen 1)");
TO_DO_BATTLE_TEST("Reflect Damage: Counter can hit ghost-type Pokémon (Gen 1)");
TO_DO_BATTLE_TEST("Reflect Damage: Counter can return damage dealt to a substitute (Gen 1)");

// Gen 2-3
TO_DO_BATTLE_TEST("Reflect Damage: Counter can counter Hidden Power regardless of type (Gen 2-3)");

// Gen 2+
TO_DO_BATTLE_TEST("Reflect Damage: Counter can only counter physical moves (Gen 2+)");
TO_DO_BATTLE_TEST("Reflect Damage: Counter cannot hit ghost-type Pokémon (Gen 2+)");
TO_DO_BATTLE_TEST("Reflect Damage: Counter cannot return damage dealt to a substitute (Gen 2+)");

// Triple Battles required to test
//TO_DO_BATTLE_TEST("Reflect Damage: Counter can hit non-adjacent opponents if they were the last Pokémon to hit the user");

SINGLE_BATTLE_TEST("Reflect Damage: Mirror Coat will do twice as much damage received from the opponent")
{
    s16 normalDmg;
    s16 mirrorCoatDmg;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROUND); MOVE(player, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponent);
        HP_BAR(player, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, player);
        HP_BAR(opponent, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), mirrorCoatDmg);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Mirror Coat ignores ally Pokémon's attack from Gen 5 onwards")
{
    u32 config;
    PARAMETRIZE { config = GEN_5; }
    PARAMETRIZE { config = GEN_4; }
    GIVEN {
        WITH_CONFIG(B_COUNTER_MIRROR_COAT_ALLY, config);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROUND, target: playerRight);
            MOVE(playerLeft, MOVE_ROUND, target: playerRight);
            MOVE(playerRight, MOVE_MIRROR_COAT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, playerLeft);
        if (config >= GEN_5) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerRight);
            HP_BAR(opponentLeft);
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerRight);
                HP_BAR(opponentLeft);
                HP_BAR(playerLeft);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Mirror Coat hits the last opponent that hit the user")
{
    s16 normalDmg;
    s16 mirrorCoatDmg;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(opponentRight, MOVE_ROUND, target: playerLeft);
            MOVE(playerLeft, MOVE_MIRROR_COAT);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentRight);
        HP_BAR(playerLeft, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerLeft);
        HP_BAR(opponentRight, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), mirrorCoatDmg);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Mirror Coat respects Follow Me")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_FOLLOW_ME);
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(playerLeft, MOVE_MIRROR_COAT, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Mirror Coat fails if mon that damaged Mirror Coat user is no longer on the field (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(B_COUNTER_TRY_HIT_PARTNER, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(playerRight, MOVE_ROUND, target: opponentLeft);
            MOVE(playerLeft, MOVE_MIRROR_COAT, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Mirror Coat deals 1 damage when the attack received is blocked by Disguise")
{
    s16 mirrorCoatDmg;
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_HEX) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEX); MOVE(player, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEX, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, player);
        HP_BAR(opponent, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_EQ(mirrorCoatDmg, 1);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Mirror Coat works when surviving OHKO move")
{
    s16 normalDmg;
    s16 mirrorCoatDmg;
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SHEER_COLD) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) {MaxHP(100); HP(100); Item(ITEM_FOCUS_SASH);};
        OPPONENT(SPECIES_WOBBUFFET) {MaxHP(500); HP(500);};
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHEER_COLD); MOVE(player, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, opponent);
        HP_BAR(player, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, player);
        HP_BAR(opponent, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(2.0), mirrorCoatDmg);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Mirror Coat works when surviving OHKO move with Disguise")
{
    s16 mirrorCoatDmg;
    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_8);
        ASSUME(GetMoveCategory(MOVE_SHEER_COLD) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); MaxHP(64); HP(64);};
        OPPONENT(SPECIES_WOBBUFFET) {MaxHP(500); HP(500);};
    } WHEN {
        TURN { MOVE(opponent, MOVE_SHEER_COLD); MOVE(player, MOVE_MIRROR_COAT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIRROR_COAT, player);
        HP_BAR(opponent, captureDamage: &mirrorCoatDmg);
    } THEN {
        EXPECT_EQ(mirrorCoatDmg, 1);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Metal Burst will do 150% of the damage received from the opponent")
{
    s16 normalDmg;
    s16 metalBurstDmg;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROUND); MOVE(player, MOVE_METAL_BURST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponent);
        HP_BAR(player, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
        HP_BAR(opponent, captureDamage: &metalBurstDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(1.5), metalBurstDmg);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Metal Burst ignores ally Pokémon's attack from Gen 5 onwards")
{
    u32 config;
    PARAMETRIZE { config = GEN_5; }
    PARAMETRIZE { config = GEN_4; }
    GIVEN {
        WITH_CONFIG(B_COUNTER_MIRROR_COAT_ALLY, config);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROUND, target: playerRight);
            MOVE(playerLeft, MOVE_POUND, target: playerRight);
            MOVE(playerRight, MOVE_METAL_BURST);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        if (config >= GEN_5) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerRight);
            HP_BAR(opponentLeft);
        } else {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerRight);
                HP_BAR(opponentLeft);
                HP_BAR(playerLeft);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Metal Burst hits the last opponent that hit the user")
{
    s16 normalDmg;
    s16 metalBurstDmg;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_POUND, target: playerLeft);
            MOVE(opponentRight, MOVE_ROUND, target: playerLeft);
            MOVE(playerLeft, MOVE_METAL_BURST);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentRight);
        HP_BAR(playerLeft, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
        HP_BAR(opponentRight, captureDamage: &metalBurstDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(1.5), metalBurstDmg);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Metal Burst respects Follow Me")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_FOLLOW_ME);
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(playerLeft, MOVE_METAL_BURST, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FOLLOW_ME, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Reflect Damage: Metal Burst fails if mon that damaged Metal Burst user is no longer on the field (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(B_COUNTER_TRY_HIT_PARTNER, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ROUND, target: playerLeft);
            MOVE(playerRight, MOVE_ROUND, target: opponentLeft);
            MOVE(playerLeft, MOVE_METAL_BURST, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, playerRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Metal Burst deals 1 damage when the attack received is blocked by Disguise")
{
    s16 metalBurstDmg;
    GIVEN {
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEX); MOVE(player, MOVE_METAL_BURST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEX, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
        HP_BAR(opponent, captureDamage: &metalBurstDmg);
    } THEN {
        EXPECT_EQ(metalBurstDmg, 1);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Metal Burst works when surviving OHKO move")
{
    s16 normalDmg;
    s16 metalBurstDmg;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {MaxHP(100); HP(100); Item(ITEM_FOCUS_SASH);};
        OPPONENT(SPECIES_WOBBUFFET) {MaxHP(500); HP(500);};
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); MOVE(player, MOVE_METAL_BURST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, opponent);
        HP_BAR(player, captureDamage: &normalDmg);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
        HP_BAR(opponent, captureDamage: &metalBurstDmg);
    } THEN {
        EXPECT_MUL_EQ(normalDmg, Q_4_12(1.5), metalBurstDmg);
    }
}

SINGLE_BATTLE_TEST("Reflect Damage: Metal Burst works when surviving OHKO move with Disguise")
{
    s16 metalBurstDmg;
    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_8);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); MaxHP(64); HP(64);};
        OPPONENT(SPECIES_WOBBUFFET) {MaxHP(500); HP(500);};
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); MOVE(player, MOVE_METAL_BURST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METAL_BURST, player);
        HP_BAR(opponent, captureDamage: &metalBurstDmg);
    } THEN {
        EXPECT_EQ(metalBurstDmg, 1);
    }
}
