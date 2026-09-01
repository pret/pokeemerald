#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ASSURANCE) == EFFECT_ASSURANCE);
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if False Swipe connected but didn't do any damage")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        ASSUME(GetMoveEffect(MOVE_RECOVER) == EFFECT_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ASSURANCE, target: playerRight); }
        TURN {
            MOVE(opponentLeft, MOVE_FALSE_SWIPE, target: playerLeft);
            MOVE(playerLeft, MOVE_RECOVER);
            MOVE(opponentRight, MOVE_ASSURANCE, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerRight, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FALSE_SWIPE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance does not double in power if the target's damage is blocked by Substitute")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_HOPPIP) { Ability(ABILITY_INFILTRATOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft); }
        TURN {
            MOVE(playerLeft, MOVE_SUBSTITUTE);
            MOVE(opponentRight, MOVE_POUND, target: playerLeft);
            MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentRight);
        SUB_HIT(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[1]);
    } THEN {
        EXPECT_EQ(hits[0], hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance does not double in power if the target took damage from confusion")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CONFUSE_RAY) == EFFECT_CONFUSE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_EQ(hits[0], hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Life Orb")
{
    s16 hits[2];

    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_POUND); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(player); // life orb
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Recoil")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_TAKE_DOWN) > 0);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_TAKE_DOWN); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(player); // recoil
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Crash")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_JUMP_KICK) == EFFECT_RECOIL_IF_MISS);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(999); HP(999); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN {
            MOVE(player, MOVE_JUMP_KICK, hit: FALSE);
            MOVE(opponent, MOVE_ASSURANCE);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_JUMP_KICK, player);
        HP_BAR(player); // self recoil
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Rocky Helmet")
{
    s16 hits[2];

    GIVEN {
        ASSUME(gItemsInfo[ITEM_ROCKY_HELMET].holdEffect == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_POUND); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent);
        HP_BAR(player); // rocky helmet
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Rough Skin")
{
    s16 hits[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GIBLE) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_POUND); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        HP_BAR(player); // rough skin
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Iron Barbs")
{
    s16 hits[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(999); HP(999); };
        OPPONENT(SPECIES_TOGEDEMARU) { Ability(ABILITY_IRON_BARBS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_POUND); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_IRON_BARBS);
        HP_BAR(player); // iron barbs
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Liquid Ooze")
{
    s16 hits[2];

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_ABSORB, MOVE_EFFECT_ABSORB));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TENTACOOL) { Ability(ABILITY_LIQUID_OOZE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_ABSORB); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ABSORB, player);
        HP_BAR(opponent);
        HP_BAR(player); // Liquid Ooze
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Aftermath")
{
    s16 hits[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB) { HP(1); Ability(ABILITY_AFTERMATH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ASSURANCE, target: playerLeft); }
        TURN {
            MOVE(playerLeft, MOVE_POUND, target: opponentLeft);
            MOVE(opponentRight, MOVE_ASSURANCE, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_AFTERMATH);
        HP_BAR(playerLeft); // aftermath
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Innards Out")
{
    s16 hits[2];

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PYUKUMUKU) { HP(1); Ability(ABILITY_INNARDS_OUT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ASSURANCE, target: playerLeft); }
        TURN {
            MOVE(playerLeft, MOVE_POUND, target: opponentLeft);
            MOVE(opponentRight, MOVE_ASSURANCE, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_INNARDS_OUT);
        HP_BAR(playerLeft); // innards out
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Jaboca Berry")
{
    s16 hits[2];

    GIVEN {
        ASSUME(gItemsInfo[ITEM_JABOCA_BERRY].holdEffect == HOLD_EFFECT_JABOCA_BERRY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_JABOCA_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_POUND); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        HP_BAR(player); // jaboca berry
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Rowap Berry")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gItemsInfo[ITEM_ROWAP_BERRY].holdEffect == HOLD_EFFECT_ROWAP_BERRY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROWAP_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_SWIFT); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        HP_BAR(player); // rowap berry
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Spiky Shield")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPIKY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft); }
        TURN {
            MOVE(opponentLeft, MOVE_SPIKY_SHIELD);
            MOVE(playerLeft, MOVE_POUND, target: opponentLeft);
            MOVE(opponentRight, MOVE_ASSURANCE, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKY_SHIELD, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, playerLeft);
        HP_BAR(playerLeft); // spiky shield
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentRight);
        HP_BAR(playerLeft, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if Ice Face has been broken by attacker")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        PLAYER(SPECIES_EISCUE) { Speed(1); Ability(ABILITY_ICE_FACE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(9); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POUND, target: playerLeft); }
        TURN {
            MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft);
            MOVE(playerLeft, MOVE_HAIL);
        }
        TURN {
            MOVE(opponentRight, MOVE_POUND, target: playerLeft);
            MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_ICE_FACE);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_ICE_FACE);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_POUND, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_ICE_FACE);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if Disguise has been broken")
{
    s16 hits[2];

    GIVEN {
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Speed(1); Ability(ABILITY_DISGUISE); }
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Speed(2); Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); };
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); }
        TURN { MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft); }

        TURN {
            MOVE(opponentRight, MOVE_WATER_GUN, target: playerRight);
            MOVE(opponentLeft, MOVE_ASSURANCE, target: playerRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponentRight);
        ABILITY_POPUP(playerLeft, ABILITY_DISGUISE);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponentRight);
        ABILITY_POPUP(playerRight, ABILITY_DISGUISE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerRight, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Powder")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_POWDER) == EFFECT_POWDER);
        ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft); }
        TURN {
            MOVE(opponentRight, MOVE_POWDER, target: playerLeft);
            MOVE(playerLeft, MOVE_EMBER, target: opponentLeft);
            MOVE(opponentLeft, MOVE_ASSURANCE, target: playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerLeft);
        HP_BAR(playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

DOUBLE_BATTLE_TEST("Assurance doubles in power if the target has been damaged by Flame Burst residual damage")
{
    s16 hits[2];

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_EMBER, MOVE_EFFECT_BURN));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_ASSURANCE, target: opponentRight); }
        TURN {
            MOVE(playerLeft, MOVE_FLAME_BURST, target: opponentLeft);
            MOVE(playerRight, MOVE_ASSURANCE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, playerRight);
        HP_BAR(opponentRight, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLAME_BURST, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, playerRight);
        HP_BAR(opponentRight, captureDamage: &hits[1]);
    } THEN {
        EXPECT_MUL_EQ(hits[0], Q_4_12(2.0), hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance does not double in power if HP was reduced by Belly Drum")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(999); HP(999); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELLY_DRUM); MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BELLY_DRUM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_EQ(hits[0], hits[1]);
    }
}

SINGLE_BATTLE_TEST("Assurance does not double in power if the target was damaged Pain Split")
{
    s16 hits[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PAIN_SPLIT) == EFFECT_PAIN_SPLIT);
        PLAYER(SPECIES_WOBBUFFET) { HP(500); MaxHP(1000); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSURANCE); }
        TURN { MOVE(player, MOVE_PAIN_SPLIT); MOVE(opponent, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PAIN_SPLIT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, opponent);
        HP_BAR(player, captureDamage: &hits[1]);
    } THEN {
        EXPECT_EQ(hits[0], hits[1]);
    }
}
