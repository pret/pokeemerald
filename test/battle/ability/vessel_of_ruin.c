#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveEffect(MOVE_ENTRAINMENT) == EFFECT_ENTRAINMENT);
}

SINGLE_BATTLE_TEST("Vessel of Ruin reduces Sp. Atk if opposing mon's ability doesn't match")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_TING_LU) { Ability(ABILITY_VESSEL_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); MOVE(player, MOVE_ENTRAINMENT); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_VESSEL_OF_RUIN);
        MESSAGE("Ting-Lu's Vessel of Ruin weakened the Sp. Atk of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENTRAINMENT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.33), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Vessel of Ruin's message displays correctly after all battlers fainted - Player")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_TING_LU);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_RUINATION); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
        // Everyone faints.
        MESSAGE("Go! Ting-Lu!");
        MESSAGE("2 sent out Wobbuffet!");
        ABILITY_POPUP(player, ABILITY_VESSEL_OF_RUIN);
        MESSAGE("Ting-Lu's Vessel of Ruin weakened the Sp. Atk of all surrounding Pokémon!");
    }
}

SINGLE_BATTLE_TEST("Vessel of Ruin's message displays correctly after all battlers fainted - Opponent")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_TING_LU);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_RUINATION); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        // Everyone faints.
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("2 sent out Ting-Lu!");
        ABILITY_POPUP(opponent, ABILITY_VESSEL_OF_RUIN);
        MESSAGE("The opposing Ting-Lu's Vessel of Ruin weakened the Sp. Atk of all surrounding Pokémon!");
    }
}

DOUBLE_BATTLE_TEST("Vessel of Ruin does not reduce Sp. Atk if Neutralizing Gas is on the field")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_TING_LU) { Ability(ABILITY_VESSEL_OF_RUIN); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_WATER_GUN, target: opponentLeft);
        }
        TURN {
            SWITCH(opponentRight, 2);
            MOVE(playerLeft, MOVE_WATER_GUN, target: opponentLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(1.33), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Vessel of Ruin is still active if removed by Mold Breaker + Entrainment")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_TING_LU) { Ability(ABILITY_VESSEL_OF_RUIN); }
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_ENTRAINMENT); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_VESSEL_OF_RUIN);
        MESSAGE("Ting-Lu's Vessel of Ruin weakened the Sp. Atk of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENTRAINMENT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

DOUBLE_BATTLE_TEST("Vessel of Ruin is active if removed by Mold Breaker Entrainment and Sword of Ruin is active after obtaining it")
{
    GIVEN {
        PLAYER(SPECIES_TING_LU) { Ability(ABILITY_VESSEL_OF_RUIN); }
        PLAYER(SPECIES_CHIEN_PAO) { Ability(ABILITY_SWORD_OF_RUIN); }
        OPPONENT(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); }
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_ENTRAINMENT, target: playerLeft);
            MOVE(opponentRight, MOVE_SKILL_SWAP, target: playerLeft);
            MOVE(playerRight, MOVE_SKILL_SWAP, target: playerLeft);
        }
    } THEN {
        bool32 isVesselOfRuinActive = gBattleMons[B_POSITION_PLAYER_LEFT].volatiles.vesselOfRuin;
        bool32 isSwordOfRuinActive = gBattleMons[B_POSITION_PLAYER_LEFT].volatiles.swordOfRuin;
        EXPECT_EQ(isVesselOfRuinActive, TRUE);
        EXPECT_EQ(isSwordOfRuinActive, TRUE);
    }
}

DOUBLE_BATTLE_TEST("Vessel of Ruin affects a Gastro Acid-suppressed Vessel of Ruin user")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_TING_LU) { Ability(ABILITY_VESSEL_OF_RUIN); }
        PLAYER(SPECIES_TING_LU) { Ability(ABILITY_VESSEL_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); }
        TURN { MOVE(opponentRight, MOVE_GASTRO_ACID, target: playerRight); }
        TURN { MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GASTRO_ACID, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerRight);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(1.33), damage[0]);
    }
}
