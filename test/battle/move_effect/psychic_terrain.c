#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Psychic Terrain protects grounded battlers from priority moves")
{
    GIVEN {
        PLAYER(SPECIES_CLAYDOL) { Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_QUICK_ATTACK); MOVE(opponent, MOVE_QUICK_ATTACK); }
    } SCENE {
        MESSAGE("Claydol used Psychic Terrain!");
        MESSAGE("The opposing Wobbuffet is protected by the Psychic Terrain!");
        NOT { HP_BAR(opponent); }
        MESSAGE("The opposing Wobbuffet used Quick Attack!");
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain increases power of Psychic-type moves by 30/50 percent", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_CONFUSION); }
    } SCENE {
        MESSAGE("Wobbuffet used Confusion!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_TERRAIN_TYPE_BOOST >= GEN_8)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
        else
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain doesn't blocks priority moves that target the user")
{
    GIVEN {
        PLAYER(SPECIES_SABLEYE) { Ability(ABILITY_PRANKSTER); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_RECOVER); }
    } SCENE {
        MESSAGE("Sableye used Psychic Terrain!");
        MESSAGE("Sableye used Recover!");
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain doesn't block priority moves that target all battlers")
{
    GIVEN {
        PLAYER(SPECIES_SABLEYE) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_HAZE); }
    } SCENE {
        MESSAGE("Sableye used Psychic Terrain!");
        MESSAGE("Sableye used Haze!");
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain doesn't block priority moves that target all opponents")
{
    GIVEN {
        PLAYER(SPECIES_SABLEYE) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_SPIKES); }
    } SCENE {
        MESSAGE("Sableye used Psychic Terrain!");
        MESSAGE("Sableye used Spikes!");
    }
}

DOUBLE_BATTLE_TEST("Psychic Terrain doesn't block priority moves that target allies")
{
    GIVEN {
        PLAYER(SPECIES_SABLEYE) { Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(playerLeft, MOVE_HEAL_PULSE, target: playerRight); }
    } SCENE {
        MESSAGE("Sableye used Psychic Terrain!");
        MESSAGE("Sableye used Heal Pulse!");
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain doesn't block priority field moves")
{
    GIVEN {
        PLAYER(SPECIES_SABLEYE) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        MESSAGE("Sableye used Psychic Terrain!");
        MESSAGE("Sableye used Sunny Day!");
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain doesn't block priority moves against semi-invulnerable targets")
{
    enum Move move = MOVE_NONE;
    bool32 shouldWork = FALSE;
    PARAMETRIZE { move = MOVE_SOLAR_BEAM; shouldWork = FALSE; }
    PARAMETRIZE { move = MOVE_FLY; shouldWork = TRUE; }
    GIVEN {
        WITH_CONFIG(B_TOXIC_NEVER_MISS, GEN_6);
        ASSUME(IsSpeciesOfType(SPECIES_SHROODLE, TYPE_POISON));
        PLAYER(SPECIES_SHROODLE) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); MOVE(opponent,move); }
        TURN { MOVE(player, MOVE_TOXIC); SKIP_TURN(opponent); }
    } SCENE {
        if (shouldWork)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
        }
        else
        {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            }
        }
    } THEN {
        if (shouldWork)
            EXPECT(opponent->status1 & STATUS1_TOXIC_POISON);
        else
            EXPECT(!(opponent->status1 & STATUS1_TOXIC_POISON));
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain lasts for 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, player);
        MESSAGE("The battlefield got weird!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");

        MESSAGE("The weirdness disappeared from the battlefield!");
    }
}

DOUBLE_BATTLE_TEST("Psychic Terrain protects grounded battlers from priority moves in doubles - Left")
{
    GIVEN {
        PLAYER(SPECIES_CLAYDOL) { Ability(ABILITY_LEVITATE); }
        PLAYER(SPECIES_TAPU_LELE) { Ability(ABILITY_PSYCHIC_SURGE); }
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_COTTON_SPORE); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_PSYCHIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COTTON_SPORE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    }
}

DOUBLE_BATTLE_TEST("Psychic Terrain protects grounded battlers from priority moves in doubles - Right")
{
    GIVEN {
        PLAYER(SPECIES_TAPU_LELE) { Ability(ABILITY_PSYCHIC_SURGE); }
        PLAYER(SPECIES_CLAYDOL) { Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_COTTON_SPORE); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_PSYCHIC_SURGE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COTTON_SPORE, opponentLeft);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    }
}

SINGLE_BATTLE_TEST("Psychic Terrain prevents priority status moves before Magic Bounce can bounce them")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PSYCHIC_TERRAIN) == EFFECT_TERRAIN);
        ASSUME(GetMoveTerrainType(MOVE_PSYCHIC_TERRAIN) == B_TERRAIN_PSYCHIC);
        ASSUME(IsBattleMoveStatus(MOVE_CONFUSE_RAY));
        ASSUME(MoveCanBeBouncedBack(MOVE_CONFUSE_RAY));
        PLAYER(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC_TERRAIN); }
        TURN { MOVE(player, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PSYCHIC_TERRAIN, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
            ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        }
    }
}
