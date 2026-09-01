#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveEffect(MOVE_ROLE_PLAY) == EFFECT_ROLE_PLAY);
}

SINGLE_BATTLE_TEST("Beads of Ruin reduces Sp. Def if opposing mon's ability doesn't match")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); MOVE(opponent, MOVE_ROLE_PLAY); }
        TURN { MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN);
        MESSAGE("Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(1.33), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Beads of Ruin's message displays correctly after all battlers fainted - Player")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_CHI_YU);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_RUINATION); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
        // Everyone faints.
        MESSAGE("Go! Chi-Yu!");
        MESSAGE("2 sent out Wobbuffet!");
        ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN);
        MESSAGE("Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
    }
}

SINGLE_BATTLE_TEST("Beads of Ruin's message displays correctly after all battlers fainted - Opponent")
{
    GIVEN {
        ASSUME(IsExplosionMove(MOVE_EXPLOSION));
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_CHI_YU);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_RUINATION); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        // Everyone faints.
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("2 sent out Chi-Yu!");
        ABILITY_POPUP(opponent, ABILITY_BEADS_OF_RUIN);
        MESSAGE("The opposing Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
    }
}

DOUBLE_BATTLE_TEST("Beads of Ruin increases damage taken by physical moves in Wonder Room", s16 damage)
{
    bool32 useWonderRoom;
    enum Move move;

    PARAMETRIZE { useWonderRoom = FALSE; move = MOVE_SCRATCH; }
    PARAMETRIZE { useWonderRoom = FALSE; move = MOVE_ROUND;   }
    PARAMETRIZE { useWonderRoom = TRUE;  move = MOVE_SCRATCH; }
    PARAMETRIZE { useWonderRoom = TRUE;  move = MOVE_ROUND;   }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveEffect(MOVE_ROUND) != EFFECT_PSYSHOCK);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useWonderRoom)
            TURN { MOVE(opponentLeft, MOVE_WONDER_ROOM); MOVE(playerRight, move, target: opponentLeft); }
        else
            TURN { MOVE(playerRight, move, target: opponentLeft); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_BEADS_OF_RUIN);
        MESSAGE("Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, move, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_GT(results[2].damage, results[0].damage); // In Wonder Room, physical move deals more damage
        EXPECT_LT(results[3].damage, results[1].damage); // In Wonder Room, special move deals less damage
    }
}

SINGLE_BATTLE_TEST("Beads of Ruin doesn't activate when dragged out by Mold Breaker attacker")
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    PARAMETRIZE { ability = ABILITY_SAND_RUSH; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        OPPONENT(SPECIES_EXCADRILL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, opponent);
        if (ability == ABILITY_MOLD_BREAKER)
        {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN);
                MESSAGE("Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
            }
        }
        else
        {
            ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN);
            MESSAGE("Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
        }
    }
}

DOUBLE_BATTLE_TEST("Beads of Ruin's Sp. Def reduction is not ignored by Mold Breaker", s16 damage)
{
    enum Ability ability;

    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    PARAMETRIZE { ability = ABILITY_SAND_RUSH; }

    GIVEN {
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_EXCADRILL) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_ROUND, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_BEADS_OF_RUIN);
        MESSAGE("Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Beads of Ruin's Sp. Def reduction is ignored by Gastro Acid", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_GASTRO_ACID; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, move, target: playerLeft); MOVE(opponentLeft, MOVE_ROUND, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_BEADS_OF_RUIN);
        MESSAGE("Chi-Yu's Beads of Ruin weakened the Sp. Def of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponentLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_LT(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Beads of Ruin reduces Sp. Def if opposing mon's ability doesn't match (Neutralizing switches in and out)")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_CELEBRATE); }
        TURN { SWITCH(opponent, 0); MOVE(player, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);

        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[1], damage[0]);
    }
}

DOUBLE_BATTLE_TEST("Beads of Ruin will not reactivate after Sunsteel Strike faints Neutralizing Gas target")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(MoveIgnoresTargetAbility(MOVE_SUNSTEEL_STRIKE));
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
           MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight);
           MOVE(playerRight, MOVE_SUNSTEEL_STRIKE, target: opponentLeft);
           SEND_OUT(opponentLeft, 2);
        }
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        NOT ABILITY_POPUP(playerLeft, ABILITY_BEADS_OF_RUIN);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNSTEEL_STRIKE, playerRight);
        HP_BAR(opponentLeft);
        MESSAGE("The opposing Weezing fainted!");

        NOT ABILITY_POPUP(playerLeft, ABILITY_BEADS_OF_RUIN);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[1], damage[0]);
    }
}

DOUBLE_BATTLE_TEST("Beads of Ruin will not be deactivated with Ability Shield")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gItemsInfo[ITEM_ABILITY_SHIELD].holdEffect == HOLD_EFFECT_ABILITY_SHIELD);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); Item(ITEM_ABILITY_SHIELD); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight); }
        TURN { SWITCH(opponentLeft, 2); MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_BEADS_OF_RUIN);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[0]);

        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[1], damage[0]);
    }
}

DOUBLE_BATTLE_TEST("Beads of Ruin will still be active while suppressed after Ability Shield is removed")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gItemsInfo[ITEM_ABILITY_SHIELD].holdEffect == HOLD_EFFECT_ABILITY_SHIELD);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); Item(ITEM_ABILITY_SHIELD); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight); }
        TURN {
            SWITCH(opponentLeft, 2);
            MOVE(opponentRight, MOVE_KNOCK_OFF, target: playerLeft);
            MOVE(playerLeft, MOVE_WATER_GUN, target: opponentRight);
        }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_BEADS_OF_RUIN);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[0]);

        ABILITY_POPUP(opponentLeft, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, opponentRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[1], damage[0]);
    }
}

SINGLE_BATTLE_TEST("Beads of Ruin does not apply any damage reduction on an opposing Beads of Ruin user even if it is deactivated")
{
    s16 damage[2];

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_EXCADRILL) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_CHI_YU) { Ability(ABILITY_BEADS_OF_RUIN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
        TURN { SWITCH(opponent, 1); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, opponent);
        NOT ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN); // Move use on deactivated Beads of Ruin

        ABILITY_POPUP(opponent, ABILITY_BEADS_OF_RUIN);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);

        ABILITY_POPUP(player, ABILITY_BEADS_OF_RUIN); // Move use on activated Beads of Ruin
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[1], damage[0]);
    }
}
