#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_WATER_PLEDGE].effect == EFFECT_PLEDGE);
    ASSUME(gMovesInfo[MOVE_FIRE_PLEDGE].effect == EFFECT_PLEDGE);
    ASSUME(gMovesInfo[MOVE_GRASS_PLEDGE].effect == EFFECT_PLEDGE);
}

DOUBLE_BATTLE_TEST("Water and Fire Pledge create a rainbow on the user's side of the field for four turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight);
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Water Pledge!");
        MESSAGE("Wobbuffet is waiting for Wynaut's move…{PAUSE 16}");
        MESSAGE("Wynaut used Fire Pledge!");
        MESSAGE("The two moves become one! It's a combined move!{PAUSE 16}");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerRight);
        HP_BAR(opponentRight);
        MESSAGE("A rainbow appeared in the sky on your team's side!");
        MESSAGE("The rainbow on your side disappeared!");
    }
}

DOUBLE_BATTLE_TEST("Rainbow doubles the chance of secondary move effects")
{
    PASSES_RANDOMLY(20, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_EMBER, MOVE_EFFECT_BURN) == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight);
        }
        TURN { MOVE(playerLeft, MOVE_EMBER, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, playerLeft);
        MESSAGE("Foe Wynaut was burned!");
    }
}

DOUBLE_BATTLE_TEST("Rainbow flinch chance does not stack with Serene Grace")
{
    PASSES_RANDOMLY(60, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_BITE, MOVE_EFFECT_FLINCH) == TRUE);
        PLAYER(SPECIES_TOGEPI) { Speed(8); Ability(ABILITY_SERENE_GRACE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight);
        }
        TURN { MOVE(playerLeft, MOVE_BITE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BITE, playerLeft);
        MESSAGE("Foe Wynaut flinched!");
    }
}

DOUBLE_BATTLE_TEST("Fire and Grass Pledge summons Sea Of Fire for four turns that damages the opponent")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight);
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Fire Pledge!");
        MESSAGE("Wobbuffet is waiting for Wynaut's move…{PAUSE 16}");
        MESSAGE("Wynaut used Grass Pledge!");
        MESSAGE("The two moves become one! It's a combined move!{PAUSE 16}");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        HP_BAR(opponentRight);
        MESSAGE("A sea of fire enveloped the opposing team!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentLeft);
        MESSAGE("The opposing Foe Wobbuffet was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentRight);
        MESSAGE("The opposing Foe Wynaut was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentLeft);
        MESSAGE("The opposing Foe Wobbuffet was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentRight);
        MESSAGE("The opposing Foe Wynaut was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentLeft);
        MESSAGE("The opposing Foe Wobbuffet was hurt by the sea of fire!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, opponentRight);
        MESSAGE("The opposing Foe Wynaut was hurt by the sea of fire!");
        MESSAGE("The sea of fire around the opposing team disappeared!");
    }
}

DOUBLE_BATTLE_TEST("Sea Of Fire deals 1/8th damage per turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight);
        }
    } SCENE {
        s32 maxHPopponentLeft = GetMonData(&OPPONENT_PARTY[0], MON_DATA_MAX_HP);
        s32 maxHPopponentRight = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        HP_BAR(opponentLeft, damage: maxHPopponentLeft / 8);
        HP_BAR(opponentRight, damage: maxHPopponentRight / 8);
    }
}

DOUBLE_BATTLE_TEST("Grass and Water Pledge create a swamp on the user's side of the field for four turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_WATER_PLEDGE, target: opponentRight);
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Grass Pledge!");
        MESSAGE("Wobbuffet is waiting for Wynaut's move…{PAUSE 16}");
        MESSAGE("Wynaut used Water Pledge!");
        MESSAGE("The two moves become one! It's a combined move!{PAUSE 16}");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        HP_BAR(opponentRight);
        MESSAGE("A swamp enveloped the opposing team!");
        MESSAGE("The swamp around the opposing team disappeared!");
    }
}

DOUBLE_BATTLE_TEST("Swamp reduces the speed of the effected side by 1/4th")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(12); }
        OPPONENT(SPECIES_WYNAUT) { Speed(8); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_WATER_PLEDGE, target: opponentRight);
        }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("The base power of a combined pledge move effect is 150")
{
    s16 hyperBeamDamage;
    s16 combinedPledgeDamage;

    GIVEN {
        ASSUME(gMovesInfo[MOVE_HYPER_BEAM].power == 150);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_HYPER_BEAM, target: playerRight);
               MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_BEAM, opponentRight);
        HP_BAR(playerRight, captureDamage: &hyperBeamDamage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerRight);
        HP_BAR(opponentRight, captureDamage: &combinedPledgeDamage);
    } THEN {
        EXPECT_EQ(hyperBeamDamage, combinedPledgeDamage);
    }
}

DOUBLE_BATTLE_TEST("Pledge moves can not be redirected by absorbing abilities")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LILEEP) { Ability(ABILITY_STORM_DRAIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentRight);}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge status timer does not reset if combined move is used again")
{
    u16 pledgeMove1, pledgeMove2;

    PARAMETRIZE { pledgeMove1 = MOVE_WATER_PLEDGE; pledgeMove2 = MOVE_FIRE_PLEDGE; }
    PARAMETRIZE { pledgeMove1 = MOVE_FIRE_PLEDGE; pledgeMove2 = MOVE_GRASS_PLEDGE; }
    PARAMETRIZE { pledgeMove1 = MOVE_GRASS_PLEDGE; pledgeMove2 = MOVE_WATER_PLEDGE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, pledgeMove1, target: opponentLeft);
               MOVE(playerRight, pledgeMove2, target: opponentRight);
        }
        TURN { MOVE(playerLeft, pledgeMove1, target: opponentLeft);
               MOVE(playerRight, pledgeMove2, target: opponentRight);
        }
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, pledgeMove1, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, pledgeMove1, playerRight);
        if (pledgeMove1 == MOVE_WATER_PLEDGE && pledgeMove2 == MOVE_FIRE_PLEDGE)
        {
            NOT MESSAGE("A rainbow appeared in the sky on your team's side!");
            MESSAGE("The rainbow on your side disappeared!");
        }
        if (pledgeMove1 == MOVE_FIRE_PLEDGE && pledgeMove2 == MOVE_GRASS_PLEDGE)
        {
            NOT MESSAGE("A sea of fire enveloped the opposing team!");
            MESSAGE("The sea of fire around the opposing team disappeared!");
        }
        if (pledgeMove1 == MOVE_GRASS_PLEDGE && pledgeMove2 == MOVE_WATER_PLEDGE)
        {
            NOT MESSAGE("A swamp enveloped the opposing team!");
            MESSAGE("The swamp around the opposing team disappeared!");
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge moves get same attack type bonus from partner", s16 damage)
{
    u32 species;

    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_CHARMANDER; }

    GIVEN {
        PLAYER(species) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentLeft);
               MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        HP_BAR(opponentRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Damage calculation: Combined pledge move")
{
    s16 dmg;
    s16 expectedDamage;
    PARAMETRIZE { expectedDamage = 159; }
    PARAMETRIZE { expectedDamage = 156; }
    PARAMETRIZE { expectedDamage = 154; }
    PARAMETRIZE { expectedDamage = 153; }
    PARAMETRIZE { expectedDamage = 151; }
    PARAMETRIZE { expectedDamage = 150; }
    PARAMETRIZE { expectedDamage = 148; }
    PARAMETRIZE { expectedDamage = 147; }
    PARAMETRIZE { expectedDamage = 145; }
    PARAMETRIZE { expectedDamage = 144; }
    PARAMETRIZE { expectedDamage = 142; }
    PARAMETRIZE { expectedDamage = 141; }
    PARAMETRIZE { expectedDamage = 139; }
    PARAMETRIZE { expectedDamage = 138; }
    PARAMETRIZE { expectedDamage = 136; }
    PARAMETRIZE { expectedDamage = 135; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_GRASS_PLEDGE].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { HP(521); SpDefense(152); Speed(3); }
        OPPONENT(SPECIES_CHARIZARD) { Speed(8); }
        OPPONENT(SPECIES_EEVEE) { SpAttack(126); Speed(5); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FIRE_PLEDGE, target: playerLeft, WITH_RNG(RNG_DAMAGE_MODIFIER, i));
               MOVE(opponentRight, MOVE_GRASS_PLEDGE, target: playerRight, WITH_RNG(RNG_DAMAGE_MODIFIER, i));
        }
    }
    SCENE {
        HP_BAR(playerRight, captureDamage: &dmg);
    }
    THEN {
        EXPECT_EQ(expectedDamage, dmg);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo interactions with Powder are correct")
{
    // Fire Pledge as the first move or Fire Pledge combo should fail
    u32 moveLeft, moveRight, speedLeft, speedRight;
    PARAMETRIZE { moveLeft = MOVE_FIRE_PLEDGE; moveRight = MOVE_WATER_PLEDGE; speedLeft = 4; speedRight = 3; } // FAIL 1
    PARAMETRIZE { moveLeft = MOVE_FIRE_PLEDGE; moveRight = MOVE_WATER_PLEDGE; speedLeft = 3; speedRight = 4; }
    PARAMETRIZE { moveLeft = MOVE_WATER_PLEDGE; moveRight = MOVE_FIRE_PLEDGE; speedLeft = 4; speedRight = 3; }
    PARAMETRIZE { moveLeft = MOVE_WATER_PLEDGE; moveRight = MOVE_FIRE_PLEDGE; speedLeft = 3; speedRight = 4; }
    PARAMETRIZE { moveLeft = MOVE_FIRE_PLEDGE; moveRight = MOVE_GRASS_PLEDGE; speedLeft = 4; speedRight = 3; } // FAIL 1
    PARAMETRIZE { moveLeft = MOVE_FIRE_PLEDGE; moveRight = MOVE_GRASS_PLEDGE; speedLeft = 3; speedRight = 4; } // FAIL 2
    PARAMETRIZE { moveLeft = MOVE_GRASS_PLEDGE; moveRight = MOVE_FIRE_PLEDGE; speedLeft = 4; speedRight = 3; }
    PARAMETRIZE { moveLeft = MOVE_GRASS_PLEDGE; moveRight = MOVE_FIRE_PLEDGE; speedLeft = 3; speedRight = 4; } // FAIL 2
    GIVEN {
        ASSUME(gMovesInfo[MOVE_FIRE_PLEDGE].type == TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedLeft); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedRight); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_VIVILLON) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_POWDER, target: playerLeft); MOVE(playerLeft, moveLeft, target: opponentLeft); MOVE(playerRight, moveRight, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER, opponentRight);
        if (speedLeft > speedRight && moveLeft == MOVE_FIRE_PLEDGE) { // FAIL 1
            NOT ANIMATION(ANIM_TYPE_MOVE, moveLeft, playerLeft);
            HP_BAR(playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, moveRight, playerRight);
        }
        else if (speedLeft > speedRight) {
            NOT HP_BAR(playerLeft);
            if (moveLeft == MOVE_GRASS_PLEDGE)
                ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            else
                ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerRight);
        }
        else if (moveLeft == MOVE_WATER_PLEDGE || moveRight == MOVE_WATER_PLEDGE) {
            NOT HP_BAR(playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        }
        else { // FAIL 2
            HP_BAR(playerLeft);
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Sleep Right")
{
    u32 speedPLeft, speedPRight, speedOLeft, speedORight;
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 40; speedPRight = 30; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 40; speedPRight = 30; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 40; speedPRight = 30; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 30; speedPRight = 40; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 30; speedPRight = 40; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 30; speedPRight = 40; speedOLeft = 8; speedORight = 1; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPLeft); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedPRight); Status1(STATUS1_SLEEP_TURN(2)); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOLeft); }
        OPPONENT(SPECIES_WYNAUT) { Speed(speedORight); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        if (speedPLeft < speedPRight) {
            MESSAGE("Wynaut is fast asleep.");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            MESSAGE("Wynaut is fast asleep.");
        }
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Sleep Left")
{
    u32 speedPLeft, speedPRight, speedOLeft, speedORight;
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 40; speedPRight = 30; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 40; speedPRight = 30; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 40; speedPRight = 30; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 30; speedPRight = 40; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 30; speedPRight = 40; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 30; speedPRight = 40; speedOLeft = 8; speedORight = 1; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPLeft); Status1(STATUS1_SLEEP_TURN(2)); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedPRight); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOLeft); }
        OPPONENT(SPECIES_WYNAUT) { Speed(speedORight); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        if (speedPRight < speedPLeft) {
            MESSAGE("Wobbuffet is fast asleep.");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            MESSAGE("Wobbuffet is fast asleep.");
        }
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Flinch Right")
{
    u32 speedPLeft, speedPRight, speedOLeft, speedORight;
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 1; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPLeft); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedPRight); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOLeft); }
        OPPONENT(SPECIES_WYNAUT) { Speed(speedORight); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FAKE_OUT, target: playerRight); MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        if (speedPLeft < speedPRight) {
            MESSAGE("Wynaut flinched!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            MESSAGE("Wynaut flinched!");
        }
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Flinch Left")
{
    u32 speedPLeft, speedPRight, speedOLeft, speedORight;
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 4; speedPRight = 3; speedOLeft = 8; speedORight = 1; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 2; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 5; }
    PARAMETRIZE { speedPLeft = 3; speedPRight = 4; speedOLeft = 8; speedORight = 1; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedPLeft); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedPRight); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(speedOLeft); }
        OPPONENT(SPECIES_WYNAUT) { Speed(speedORight); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FAKE_OUT, target: playerLeft); MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        if (speedPRight < speedPLeft) {
            MESSAGE("Wobbuffet flinched!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            MESSAGE("Wobbuffet flinched!");
        }
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't fail if any mon wakes up")
{
    u32 statusLeft, statusRight;
    PARAMETRIZE { statusLeft = STATUS1_SLEEP_TURN(1); statusRight = 0; }
    PARAMETRIZE { statusLeft = 0; statusRight = STATUS1_SLEEP_TURN(1); }
    PARAMETRIZE { statusLeft = STATUS1_SLEEP_TURN(1); statusRight = STATUS1_SLEEP_TURN(1); }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Status1(statusLeft); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); Status1(statusRight); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            MESSAGE("Wobbuffet is fast asleep.");
            MESSAGE("Wynaut is fast asleep.");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't fail if any mon thaws out")
{
    u32 statusLeft, statusRight;
    PARAMETRIZE { statusLeft = STATUS1_FREEZE; statusRight = 0; }
    PARAMETRIZE { statusLeft = 0; statusRight = STATUS1_FREEZE; }
    PARAMETRIZE { statusLeft = STATUS1_FREEZE; statusRight = STATUS1_FREEZE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Status1(statusLeft); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); Status1(statusRight); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight, WITH_RNG(RNG_FROZEN, 1)); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight, WITH_RNG(RNG_FROZEN, 1)); }
    } SCENE {
        NONE_OF {
            MESSAGE("Wobbuffet is frozen solid!");
            MESSAGE("Wynaut is frozen solid!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Sleep Both Left Wake Up")
{
    u32 speedLeft, speedRight;
    PARAMETRIZE { speedLeft = 4; speedRight = 3; }
    PARAMETRIZE { speedLeft = 3; speedRight = 4; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedLeft); Status1(STATUS1_SLEEP_TURN(1)); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedRight); Status1(STATUS1_SLEEP_TURN(2)); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        if (speedLeft < speedRight) {
            MESSAGE("Wynaut is fast asleep.");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            MESSAGE("Wynaut is fast asleep.");
        }
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Sleep Both Right Wake Up")
{
    u32 speedLeft, speedRight;
    PARAMETRIZE { speedLeft = 4; speedRight = 3; }
    PARAMETRIZE { speedLeft = 3; speedRight = 4; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(speedLeft); Status1(STATUS1_SLEEP_TURN(2)); }
        PLAYER(SPECIES_WYNAUT) { Speed(speedRight); Status1(STATUS1_SLEEP_TURN(1)); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        if (speedRight < speedLeft) {
            MESSAGE("Wobbuffet is fast asleep.");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
            MESSAGE("Wobbuffet is fast asleep.");
        }
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Sleep Both Left Faster")
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(2); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(3); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(4); }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Status1(status1); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); Status1(status1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        MESSAGE("Wobbuffet is fast asleep.");
        MESSAGE("Wynaut is fast asleep.");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Sleep Both Right Faster")
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(2); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(3); }
    PARAMETRIZE { status1 = STATUS1_SLEEP_TURN(4); }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Status1(status1); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); Status1(status1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        MESSAGE("Wynaut is fast asleep.");
        MESSAGE("Wobbuffet is fast asleep.");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Frozen Both Left Faster")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Status1(STATUS1_FREEZE); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight, WITH_RNG(RNG_FROZEN, 0)); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight, WITH_RNG(RNG_FROZEN, 0)); }
    } SCENE {
        MESSAGE("Wobbuffet is frozen solid!");
        MESSAGE("Wynaut is frozen solid!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Frozen Both Right Faster")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); Status1(STATUS1_FREEZE); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); Status1(STATUS1_FREEZE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight, WITH_RNG(RNG_FROZEN, 0)); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight, WITH_RNG(RNG_FROZEN, 0)); }
    } SCENE {
        MESSAGE("Wynaut is frozen solid!");
        MESSAGE("Wobbuffet is frozen solid!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Paralyzed Both Left Faster")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); Status1(STATUS1_PARALYSIS); }
        PLAYER(SPECIES_WYNAUT) { Speed(30); Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight, WITH_RNG(RNG_PARALYSIS, 0)); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight, WITH_RNG(RNG_PARALYSIS, 0)); }
    } SCENE {
        MESSAGE("Wobbuffet is paralyzed! It can't move!");
        MESSAGE("Wynaut is paralyzed! It can't move!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Paralyzed Both Right Faster")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); Status1(STATUS1_PARALYSIS); }
        PLAYER(SPECIES_WYNAUT) { Speed(40); Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(80); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight, WITH_RNG(RNG_PARALYSIS, 0)); MOVE(playerRight, MOVE_GRASS_PLEDGE, target: opponentRight, WITH_RNG(RNG_PARALYSIS, 0)); }
    } SCENE {
        MESSAGE("Wynaut is paralyzed! It can't move!");
        MESSAGE("Wobbuffet is paralyzed! It can't move!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerRight);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Flinch Both Left Faster")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FAKE_OUT, target: playerLeft); MOVE(opponentRight, MOVE_FAKE_OUT, target: playerRight); MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentRight);
        MESSAGE("Wobbuffet flinched!");
        MESSAGE("Wynaut flinched!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo fails if ally fails to act - Flinch Both Right Faster")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectWithChance(MOVE_FAKE_OUT, MOVE_EFFECT_FLINCH, 100));
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_WYNAUT) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(2); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FAKE_OUT, target: playerLeft); MOVE(opponentRight, MOVE_FAKE_OUT, target: playerRight); MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentRight); MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAKE_OUT, opponentRight);
        MESSAGE("Wynaut flinched!");
        MESSAGE("Wobbuffet flinched!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SEA_OF_FIRE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
            HP_BAR(opponentRight);
        }
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Sleep")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); Status1(STATUS1_SLEEP_TURN(2)); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_GRASS_PLEDGE, target: playerLeft); 
               MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Freeze")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(8); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); Status1(STATUS1_FREEZE); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FIRE_PLEDGE, target: playerLeft); MOVE(opponentRight, MOVE_GRASS_PLEDGE, target: playerLeft, WITH_RNG(RNG_FROZEN, 0)); MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Powder")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_POWDER, target: opponentRight);
               MOVE(opponentLeft, MOVE_GRASS_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(playerRight, MOVE_FIRE_PLEDGE, target: opponentLeft); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerRight);
        HP_BAR(opponentLeft);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Electrify")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ELECTRIFY].effect == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_MAROWAK) { Ability(ABILITY_LIGHTNING_ROD); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_ELECTRIFY, target: opponentRight);
               MOVE(opponentLeft, MOVE_GRASS_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Storm Drain")
{
    GIVEN {
        PLAYER(SPECIES_GASTRODON) { Ability(ABILITY_STORM_DRAIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_WATER_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Sap Sipper")
{
    GIVEN {
        PLAYER(SPECIES_GOODRA) { Ability(ABILITY_SAP_SIPPER); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_WATER_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_GRASS_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Dry Skin")
{
    GIVEN {
        PLAYER(SPECIES_PARASECT) { Ability(ABILITY_DRY_SKIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_WATER_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Flash Fire")
{
    GIVEN {
        PLAYER(SPECIES_HEATRAN) { Ability(ABILITY_FLASH_FIRE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_GRASS_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Motor Drive")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ELECTRIFY].effect == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_ELECTIVIRE) { Ability(ABILITY_MOTOR_DRIVE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_ELECTRIFY, target: opponentRight);
               MOVE(opponentLeft, MOVE_WATER_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_GRASS_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_FIRE_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Volt Absorb")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_ELECTRIFY].effect == EFFECT_ELECTRIFY);
        PLAYER(SPECIES_JOLTEON) { Ability(ABILITY_VOLT_ABSORB); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_ELECTRIFY, target: opponentRight);
               MOVE(opponentLeft, MOVE_WATER_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_GRASS_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Water Absorb")
{
    GIVEN {
        PLAYER(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_WATER_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_GRASS_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Pledge move combo doesn't trigger on opponent's Pledge move - Well Baked Body")
{
    GIVEN {
        PLAYER(SPECIES_DACHSBUN) { Ability(ABILITY_WELL_BAKED_BODY); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_GRASS_PLEDGE, target: playerLeft);
               MOVE(opponentRight, MOVE_FIRE_PLEDGE, target: playerLeft);
               MOVE(playerLeft, MOVE_WATER_PLEDGE, target: opponentRight); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentLeft);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASS_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, opponentRight);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FIRE_PLEDGE, playerLeft);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_PLEDGE, playerLeft);
        HP_BAR(opponentRight);
    }
}
