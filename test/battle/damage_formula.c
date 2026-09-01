#include "global.h"
#include "test/battle.h"

// From https://bulbapedia.bulbagarden.net/wiki/Damage#Example

SINGLE_BATTLE_TEST("Damage calculation matches Gen5+")
{
    s16 dmg;
    s16 expectedDamage;
    PARAMETRIZE { expectedDamage = 196; }
    PARAMETRIZE { expectedDamage = 192; }
    PARAMETRIZE { expectedDamage = 192; }
    PARAMETRIZE { expectedDamage = 192; }
    PARAMETRIZE { expectedDamage = 184; }
    PARAMETRIZE { expectedDamage = 184; }
    PARAMETRIZE { expectedDamage = 184; }
    PARAMETRIZE { expectedDamage = 180; }
    PARAMETRIZE { expectedDamage = 180; }
    PARAMETRIZE { expectedDamage = 180; }
    PARAMETRIZE { expectedDamage = 172; }
    PARAMETRIZE { expectedDamage = 172; }
    PARAMETRIZE { expectedDamage = 172; }
    PARAMETRIZE { expectedDamage = 168; }
    PARAMETRIZE { expectedDamage = 168; }
    PARAMETRIZE { expectedDamage = 168; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ICE_FANG) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_GLACEON) { Level(75); Attack(123); }
        OPPONENT(SPECIES_GARCHOMP) { Defense(163); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_ICE_FANG, WITH_RNG(RNG_DAMAGE_MODIFIER, i));
        }
    }
    SCENE {
        MESSAGE("Glaceon used Ice Fang!");
        HP_BAR(opponent, captureDamage: &dmg);
    }
    THEN {
        EXPECT_EQ(expectedDamage, dmg);
    }
}

SINGLE_BATTLE_TEST("Damage calculation matches Gen6+ (Muscle Band, crit)")
{
    s16 dmg;
    s16 expectedDamage;
    PARAMETRIZE { expectedDamage = 324; }
    PARAMETRIZE { expectedDamage = 316; }
    PARAMETRIZE { expectedDamage = 312; }
    PARAMETRIZE { expectedDamage = 312; }
    PARAMETRIZE { expectedDamage = 304; }
    PARAMETRIZE { expectedDamage = 304; }
    PARAMETRIZE { expectedDamage = 300; }
    PARAMETRIZE { expectedDamage = 300; }
    PARAMETRIZE { expectedDamage = 292; }
    PARAMETRIZE { expectedDamage = 292; }
    PARAMETRIZE { expectedDamage = 288; }
    PARAMETRIZE { expectedDamage = 288; }
    PARAMETRIZE { expectedDamage = 280; }
    PARAMETRIZE { expectedDamage = 276; }
    PARAMETRIZE { expectedDamage = 276; }
    PARAMETRIZE { expectedDamage = 268; }
    GIVEN {
        WITH_CONFIG(B_CRIT_MULTIPLIER, GEN_6);
        ASSUME(GetMoveCategory(MOVE_ICE_FANG) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_GLACEON) { Level(75); Attack(123); Item(ITEM_MUSCLE_BAND); }
        OPPONENT(SPECIES_GARCHOMP) { Defense(163); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_ICE_FANG, WITH_RNG(RNG_DAMAGE_MODIFIER, i), criticalHit: TRUE);
        }
    }
    SCENE {
        MESSAGE("Glaceon used Ice Fang!");
        HP_BAR(opponent, captureDamage: &dmg);
    }
    THEN {
        EXPECT_EQ(expectedDamage, dmg);
    }
}

SINGLE_BATTLE_TEST("Damage calculation matches Gen5+ (Marshadow vs Mawile)")
{
    s16 dmg;
    s16 expectedDamage;
    PARAMETRIZE { expectedDamage = 145; }
    PARAMETRIZE { expectedDamage = 144; }
    PARAMETRIZE { expectedDamage = 142; }
    PARAMETRIZE { expectedDamage = 141; }
    PARAMETRIZE { expectedDamage = 139; }
    PARAMETRIZE { expectedDamage = 138; }
    PARAMETRIZE { expectedDamage = 136; }
    PARAMETRIZE { expectedDamage = 135; }
    PARAMETRIZE { expectedDamage = 133; }
    PARAMETRIZE { expectedDamage = 132; }
    PARAMETRIZE { expectedDamage = 130; }
    PARAMETRIZE { expectedDamage = 129; }
    PARAMETRIZE { expectedDamage = 127; }
    PARAMETRIZE { expectedDamage = 126; }
    PARAMETRIZE { expectedDamage = 124; }
    PARAMETRIZE { expectedDamage = 123; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SPECTRAL_THIEF) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(B_UPDATED_TYPE_MATCHUPS >= GEN_6); // Steel resists Ghost in Gen2-5
        PLAYER(SPECIES_MARSHADOW) { Level(100); Attack(286); }
        OPPONENT(SPECIES_MAWILE) { Level(100); Defense(226); HP(241); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_SPECTRAL_THIEF, WITH_RNG(RNG_DAMAGE_MODIFIER, i), criticalHit: FALSE);
        }
    }
    SCENE{
        MESSAGE("Marshadow used Spectral Thief!");
        HP_BAR(opponent, captureDamage: &dmg);
    }
    THEN{
        EXPECT_EQ(expectedDamage, dmg);
    }
}

DOUBLE_BATTLE_TEST("A spread move will do correct damage to the second mon if the first target faints from first hit of the spread move (double battle)")
{
    s16 damage[6];
    GIVEN {
        PLAYER(SPECIES_REGIROCK);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); MOVE(playerRight, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(opponentRight, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[2]);
        HP_BAR(opponentRight, captureDamage: &damage[3]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerRight);
        HP_BAR(opponentRight, captureDamage: &damage[4]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[5]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
        EXPECT_EQ(damage[1], damage[3]);
        EXPECT_MUL_EQ(damage[5], UQ_4_12(0.75), damage[3]);
        EXPECT_EQ(damage[4], damage[5]);
    }
}

MULTI_BATTLE_TEST("A spread move will do correct damage to the second mon if the first target faints from first hit of the spread move (multibattle)")
{
    s16 damage[6];
    GIVEN {
        PLAYER(SPECIES_REGIROCK);
        PARTNER(SPECIES_REGIROCK);
        OPPONENT_A(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT_B(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); MOVE(playerRight, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(opponentRight, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[2]);
        HP_BAR(opponentRight, captureDamage: &damage[3]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerRight);
        HP_BAR(opponentRight, captureDamage: &damage[4]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[5]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
        EXPECT_EQ(damage[1], damage[3]);
        EXPECT_MUL_EQ(damage[5], UQ_4_12(0.75), damage[3]);
        EXPECT_EQ(damage[4], damage[5]);
    }
}

TWO_VS_ONE_BATTLE_TEST("A spread move will do correct damage to the second mon if the first target faints from first hit of the spread move (2v1)")
{
    s16 damage[6];
    GIVEN {
        PLAYER(SPECIES_REGIROCK);
        PARTNER(SPECIES_REGIROCK);
        OPPONENT_A(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT_A(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); MOVE(playerRight, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(opponentRight, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[2]);
        HP_BAR(opponentRight, captureDamage: &damage[3]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerRight);
        HP_BAR(opponentRight, captureDamage: &damage[4]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[5]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
        EXPECT_EQ(damage[1], damage[3]);
        EXPECT_MUL_EQ(damage[5], UQ_4_12(0.75), damage[3]);
        EXPECT_EQ(damage[4], damage[5]);
    }
}

ONE_VS_TWO_BATTLE_TEST("A spread move will do correct damage to the second mon if the first target faints from first hit of the spread move (1v2)")
{
    s16 damage[6];
    GIVEN {
        PLAYER(SPECIES_REGIROCK);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT_A(SPECIES_WOBBUFFET) { HP(200); }
        OPPONENT_B(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); MOVE(playerRight, MOVE_ROCK_SLIDE); }
        TURN { MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(opponentRight, captureDamage: &damage[1]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[2]);
        HP_BAR(opponentRight, captureDamage: &damage[3]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerRight);
        HP_BAR(opponentRight, captureDamage: &damage[4]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[5]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
        EXPECT_EQ(damage[1], damage[3]);
        EXPECT_MUL_EQ(damage[5], UQ_4_12(0.75), damage[3]);
        EXPECT_EQ(damage[4], damage[5]);
    }
}

SINGLE_BATTLE_TEST("Punching Glove vs Muscle Band Damage calculation")
{
    s16 dmgPlayer, dmgOpponent;
    s16 expectedDamagePlayer, expectedDamageOpponent;
    PARAMETRIZE { expectedDamagePlayer = 204, expectedDamageOpponent = 201; }
    PARAMETRIZE { expectedDamagePlayer = 201, expectedDamageOpponent = 198; }
    PARAMETRIZE { expectedDamagePlayer = 199, expectedDamageOpponent = 196; }
    PARAMETRIZE { expectedDamagePlayer = 196, expectedDamageOpponent = 193; }
    PARAMETRIZE { expectedDamagePlayer = 195, expectedDamageOpponent = 192; }
    PARAMETRIZE { expectedDamagePlayer = 193, expectedDamageOpponent = 190; }
    PARAMETRIZE { expectedDamagePlayer = 190, expectedDamageOpponent = 187; }
    PARAMETRIZE { expectedDamagePlayer = 189, expectedDamageOpponent = 186; }
    PARAMETRIZE { expectedDamagePlayer = 187, expectedDamageOpponent = 184; }
    PARAMETRIZE { expectedDamagePlayer = 184, expectedDamageOpponent = 181; }
    PARAMETRIZE { expectedDamagePlayer = 183, expectedDamageOpponent = 180; }
    PARAMETRIZE { expectedDamagePlayer = 181, expectedDamageOpponent = 178; }
    PARAMETRIZE { expectedDamagePlayer = 178, expectedDamageOpponent = 175; }
    PARAMETRIZE { expectedDamagePlayer = 177, expectedDamageOpponent = 174; }
    PARAMETRIZE { expectedDamagePlayer = 174, expectedDamageOpponent = 172; }
    PARAMETRIZE { expectedDamagePlayer = 172, expectedDamageOpponent = 169; }
    GIVEN {
        PLAYER(SPECIES_MAKUHITA) { Item(ITEM_PUNCHING_GLOVE); }
        OPPONENT(SPECIES_MAKUHITA) { Item(ITEM_MUSCLE_BAND); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_DRAIN_PUNCH, WITH_RNG(RNG_DAMAGE_MODIFIER, i));
            MOVE(opponent, MOVE_DRAIN_PUNCH, WITH_RNG(RNG_DAMAGE_MODIFIER, i));
        }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAIN_PUNCH, player);
        HP_BAR(opponent, captureDamage: &dmgPlayer);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAIN_PUNCH, opponent);
        HP_BAR(player, captureDamage: &dmgOpponent);
    }
    THEN {
        EXPECT_EQ(expectedDamagePlayer, dmgPlayer);
        EXPECT_EQ(expectedDamageOpponent, dmgOpponent);
    }
}

SINGLE_BATTLE_TEST("Gem boosted Damage calculation")
{
    s16 dmg;
    s16 expectedDamage;
#if I_GEM_BOOST_POWER >= GEN_6
    PARAMETRIZE { expectedDamage = 240; }
    PARAMETRIZE { expectedDamage = 237; }
    PARAMETRIZE { expectedDamage = 234; }
    PARAMETRIZE { expectedDamage = 232; }
    PARAMETRIZE { expectedDamage = 229; }
    PARAMETRIZE { expectedDamage = 228; }
    PARAMETRIZE { expectedDamage = 225; }
    PARAMETRIZE { expectedDamage = 222; }
    PARAMETRIZE { expectedDamage = 220; }
    PARAMETRIZE { expectedDamage = 217; }
    PARAMETRIZE { expectedDamage = 216; }
    PARAMETRIZE { expectedDamage = 213; }
    PARAMETRIZE { expectedDamage = 210; }
    PARAMETRIZE { expectedDamage = 208; }
    PARAMETRIZE { expectedDamage = 205; }
    PARAMETRIZE { expectedDamage = 204; }
#else
    PARAMETRIZE { expectedDamage = 273; }
    PARAMETRIZE { expectedDamage = 270; }
    PARAMETRIZE { expectedDamage = 267; }
    PARAMETRIZE { expectedDamage = 264; }
    PARAMETRIZE { expectedDamage = 261; }
    PARAMETRIZE { expectedDamage = 258; }
    PARAMETRIZE { expectedDamage = 256; }
    PARAMETRIZE { expectedDamage = 253; }
    PARAMETRIZE { expectedDamage = 250; }
    PARAMETRIZE { expectedDamage = 247; }
    PARAMETRIZE { expectedDamage = 244; }
    PARAMETRIZE { expectedDamage = 241; }
    PARAMETRIZE { expectedDamage = 240; }
    PARAMETRIZE { expectedDamage = 237; }
    PARAMETRIZE { expectedDamage = 234; }
    PARAMETRIZE { expectedDamage = 231; }
#endif
    GIVEN {
        PLAYER(SPECIES_MAKUHITA) { Item(ITEM_FIGHTING_GEM); }
        OPPONENT(SPECIES_MAKUHITA) { MaxHP(999); HP(999); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_DRAIN_PUNCH, WITH_RNG(RNG_DAMAGE_MODIFIER, i));
        }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAIN_PUNCH, player);
        HP_BAR(opponent, captureDamage: &dmg);
    }
    THEN {
        EXPECT_EQ(expectedDamage, dmg);
    }
}

#define NUM_DAMAGE_SPREADS (DMG_ROLL_PERCENT_HI - DMG_ROLL_PERCENT_LO) + 1

static const s16 sThunderShockTransistorSpreadGen9[] = { 54, 55, 56, 57, 57, 58, 59, 60, 60, 60, 61, 62, 63, 63, 64, 65 };
static const s16 sThunderShockTransistorSpreadGen8[] = { 63, 64, 65, 66, 66, 67, 68, 69, 69, 70, 71, 72, 72, 73, 74, 75 };
static const s16 sThunderShockRegularSpread[] = { 42, 42, 43, 43, 44, 45, 45, 45, 46, 46, 47, 48, 48, 48, 49, 50 };
static const s16 sWildChargeTransistorSpreadGen9[] = { 123, 124, 126, 127, 129, 130, 132, 133, 135, 136, 138, 139, 141, 142, 144, 145 };
static const s16 sWildChargeTransistorSpreadGen8[] = { 141, 143, 145, 147, 148, 150, 151, 153, 155, 156, 158, 160, 162, 163, 165, 167 };
static const s16 sWildChargeRegularSpread[] = { 94, 96, 96, 98, 99, 100, 101, 102, 103, 105, 105, 107, 108, 109, 110, 111 };

DOUBLE_BATTLE_TEST("Transistor Damage calculation", s16 damage)
{
    s16 expectedDamageTransistorSpec = 0, expectedDamageRegularPhys = 0, expectedDamageRegularSpec = 0, expectedDamageTransistorPhys = 0;
    s16 damagePlayerLeft, damagePlayerRight, damageOpponentLeft, damageOpponentRight;
    u32 gen = 0;
    for (u32 spread = 0; spread < 16; ++spread) {
        PARAMETRIZE { gen = GEN_9,
                      expectedDamageTransistorSpec = sThunderShockTransistorSpreadGen9[spread],
                      expectedDamageRegularSpec = sThunderShockRegularSpread[spread];
                      expectedDamageTransistorPhys = sWildChargeTransistorSpreadGen9[spread],
                      expectedDamageRegularPhys = sWildChargeRegularSpread[spread];
                    }
    }
    for (u32 spread = 0; spread < 16; ++spread) {
        PARAMETRIZE { gen = GEN_8,
                      expectedDamageTransistorSpec = sThunderShockTransistorSpreadGen8[spread],
                      expectedDamageRegularSpec = sThunderShockRegularSpread[spread],
                      expectedDamageTransistorPhys = sWildChargeTransistorSpreadGen8[spread],
                      expectedDamageRegularPhys = sWildChargeRegularSpread[spread];
                    }
    }
    GIVEN {
        WITH_CONFIG(B_TRANSISTOR_BOOST, gen);
        ASSUME(GetMoveType(MOVE_WILD_CHARGE) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
        ASSUME(GetMoveCategory(MOVE_WILD_CHARGE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_THUNDER_SHOCK) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(NUM_DAMAGE_SPREADS == 16);

        PLAYER(SPECIES_REGIELEKI) { Ability(ABILITY_KLUTZ); }
        PLAYER(SPECIES_REGIELEKI) { Ability(ABILITY_TRANSISTOR); }
        OPPONENT(SPECIES_REGIELEKI) { Ability(ABILITY_KLUTZ); }
        OPPONENT(SPECIES_REGIELEKI) { Ability(ABILITY_TRANSISTOR); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_THUNDER_SHOCK, target: opponentLeft, WITH_RNG(RNG_DAMAGE_MODIFIER, 15 - (i % 16)));
            MOVE(playerRight, MOVE_THUNDER_SHOCK, target: opponentRight, WITH_RNG(RNG_DAMAGE_MODIFIER, 15 - (i % 16)));
            MOVE(opponentLeft, MOVE_WILD_CHARGE, target: playerLeft, WITH_RNG(RNG_DAMAGE_MODIFIER, 15 - (i % 16)));
            MOVE(opponentRight, MOVE_WILD_CHARGE, target: playerRight, WITH_RNG(RNG_DAMAGE_MODIFIER, 15 - (i % 16)));
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damageOpponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_SHOCK, playerRight);
        HP_BAR(opponentRight, captureDamage: &damageOpponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILD_CHARGE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &damagePlayerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WILD_CHARGE, opponentRight);
        HP_BAR(playerRight, captureDamage: &damagePlayerRight);
    } THEN {
        EXPECT_EQ(damageOpponentLeft, expectedDamageRegularSpec);
        EXPECT_EQ(damageOpponentRight, expectedDamageTransistorSpec);
        EXPECT_EQ(damagePlayerLeft, expectedDamageRegularPhys);
        EXPECT_EQ(damagePlayerRight, expectedDamageTransistorPhys);
    }
}
