#include "global.h"
#include "test/battle.h"

// Please add Sandstorm interactions with move, item and ability effects on their respective files.
SINGLE_BATTLE_TEST("Sandstorm deals 1/16 damage per turn")
{
    s16 sandstormDamage;

    GIVEN {
        PLAYER(SPECIES_SANDSLASH);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet is buffeted by the sandstorm!");
        HP_BAR(opponent, captureDamage: &sandstormDamage);
   } THEN { EXPECT_EQ(sandstormDamage, opponent->maxHP / 16); }
}

SINGLE_BATTLE_TEST("Sandstorm multiplies the special defense of Rock-types by 1.5x (Gen4+)", s16 damage)
{
    enum Move move;
    u32 config;
    PARAMETRIZE { move = MOVE_CELEBRATE; config = GEN_3; }
    PARAMETRIZE { move = MOVE_SANDSTORM; config = GEN_3; }
    PARAMETRIZE { move = MOVE_SANDSTORM; config = GEN_4; }
    GIVEN {
        WITH_CONFIG(B_SANDSTORM_SPDEF_BOOST, config);
        ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) ;
        OPPONENT(SPECIES_NOSEPASS);
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[0].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Sandstorm damage does not hurt Ground, Rock, and Steel-type Pokémon")
{
    u32 mon;
    PARAMETRIZE { mon = SPECIES_SANDSLASH; }
    PARAMETRIZE { mon = SPECIES_NOSEPASS; }
    PARAMETRIZE { mon = SPECIES_REGISTEEL; }
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SANDSLASH, 0) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_NOSEPASS, 0) == TYPE_ROCK);
        ASSUME(GetSpeciesType(SPECIES_REGISTEEL, 0) == TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(mon);
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        switch (mon)
        {
        case SPECIES_SANDSLASH:
            NOT MESSAGE("The opposing Sandslash is buffeted by the sandstorm!");
            break;
        case SPECIES_NOSEPASS:
            NOT MESSAGE("The opposing Nosepass is buffeted by the sandstorm!");
            break;
        case SPECIES_REGISTEEL:
            NOT MESSAGE("The opposing Registeel is buffeted by the sandstorm!");
            break;
        }
    }
}

DOUBLE_BATTLE_TEST("Sandstorm deals damage based on turn order")
{
    GIVEN {
        PLAYER(SPECIES_PHANPY) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SANDSTORM); }
    } SCENE {
        NOT HP_BAR(playerLeft);
        HP_BAR(opponentRight);
        HP_BAR(opponentLeft);
        HP_BAR(playerRight);
   }
}

SINGLE_BATTLE_TEST("Sandstorm damage rounds properly when maxHP < 16")
{
    GIVEN {
        PLAYER(SPECIES_MAGIKARP) { Level(1); MaxHP(11); HP(11); }
        OPPONENT(SPECIES_SANDSLASH);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
    } SCENE {
        HP_BAR(player, damage: 1);
    }
}

SINGLE_BATTLE_TEST("Sandstorm doesn't do damage when weather is negated")
{
    enum Type type1 = GetSpeciesType(SPECIES_STOUTLAND, 0);
    enum Type type2 = GetSpeciesType(SPECIES_STOUTLAND, 1);
    GIVEN {
        ASSUME(type1 != TYPE_ROCK && type2 != TYPE_ROCK);
        ASSUME(type1 != TYPE_GROUND && type2 != TYPE_GROUND);
        ASSUME(type1 != TYPE_STEEL && type2 != TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SANDSTORM); }
    } SCENE {
        NOT HP_BAR(player);
    }
}
