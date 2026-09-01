#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Protosynthesis boosts the highest stat")
{
    GIVEN {
        PLAYER(SPECIES_WALKING_WAKE) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
        MESSAGE("Walking Wake's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis boosts either Attack or Special Attack, not both")
{
    enum Species species;
    enum Move move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_ROARING_MOON; move = MOVE_SCRATCH; }
    PARAMETRIZE { species = SPECIES_ROARING_MOON; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_WALKING_WAKE; move = MOVE_SCRATCH; }
    PARAMETRIZE { species = SPECIES_WALKING_WAKE; move = MOVE_ROUND; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        if ((move == MOVE_SCRATCH && species == SPECIES_ROARING_MOON) || (move == MOVE_ROUND && species == SPECIES_WALKING_WAKE))
            EXPECT_MUL_EQ(damage[0], Q_4_12(1.3), damage[1]);
        else
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis ability pop up activates only once during the duration of sunny day")
{
    u16 turns;

    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        PLAYER(SPECIES_WALKING_WAKE) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        for (turns = 0; turns < 5; turns++)
            TURN {}
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
        MESSAGE("Walking Wake's Sp. Atk was heightened!");
        NONE_OF {
            for (turns = 0; turns < 4; turns++) {
                ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
                MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
                MESSAGE("Walking Wake's Sp. Atk was heightened!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Walking Wake's Protosynthesis!");
        MESSAGE("Walking Wake's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis activates on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ROARING_MOON) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Roaring Moon's Protosynthesis!");
        MESSAGE("Roaring Moon's Attack was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis prioritizes stats in the case of a tie in the following order: Atk, Def, Sp.Atk, Sp.Def, Speed")
{
    u8 stats[] = {1, 1, 1, 1, 1};

    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; stats[1] = 255; stats[0] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; stats[1] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; }
    GIVEN {
        PLAYER(SPECIES_GREAT_TUSK) { Ability(ABILITY_PROTOSYNTHESIS); Attack(stats[0]); Defense(stats[1]); SpAttack(stats[2]); SpDefense(stats[3]); Speed(stats[4]); }
        OPPONENT(SPECIES_GROUDON) { Ability(ABILITY_DROUGHT); Speed(5); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        switch(i) {
            case 0:
                MESSAGE("Great Tusk's Attack was heightened!");
                break;
            case 1:
                MESSAGE("Great Tusk's Defense was heightened!");
                break;
            case 2:
                MESSAGE("Great Tusk's Sp. Atk was heightened!");
                break;
            case 3:
                MESSAGE("Great Tusk's Sp. Def was heightened!");
                break;
        }
    }
}

SINGLE_BATTLE_TEST("Protosynthesis uses Wonder Room swapped defenses when choosing boosted stat")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
        PLAYER(SPECIES_ROARING_MOON) { Ability(ABILITY_PROTOSYNTHESIS); Attack(50); Defense(200); SpAttack(40); SpDefense(60); Speed(70); Moves(MOVE_WONDER_ROOM); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SUNNY_DAY); Speed(60); }
    } WHEN {
        TURN { MOVE(player, MOVE_WONDER_ROOM); MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WONDER_ROOM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Roaring Moon's Protosynthesis!");
        MESSAGE("Roaring Moon's Sp. Def was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis activates in Sun before Booster Energy")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GREAT_TUSK) { Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
    } THEN {
        EXPECT_EQ(player->item, ITEM_BOOSTER_ENERGY);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis doesn't activate for a transformed battler")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_GREAT_TUSK) { Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); Item(ITEM_BOOSTER_ENERGY); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_PROTOSYNTHESIS);
    } THEN {
        EXPECT_EQ(player->item, ITEM_BOOSTER_ENERGY);
        EXPECT_EQ(opponent->item, ITEM_BOOSTER_ENERGY);
        EXPECT_EQ(opponent->ability, ABILITY_PROTOSYNTHESIS);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis activates even if the Pokémon is holding an Utility Umbrella")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_UTILITY_UMBRELLA].holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA);
        PLAYER(SPECIES_GREAT_TUSK) { Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_UTILITY_UMBRELLA); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis doesn't activate if Cloud Nine/Air Lock is on the field")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    PARAMETRIZE { species = SPECIES_GOLDUCK; ability = ABILITY_CLOUD_NINE; }

    GIVEN {
        PLAYER(SPECIES_GREAT_TUSK) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        NOT ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis activates after weather was reset")
{
    GIVEN {
        PLAYER(SPECIES_WALKING_WAKE) { Ability(ABILITY_PROTOSYNTHESIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAIN_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis accounts for Sticky Web when determining the boosted stat")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_FLUTTER_MANE) { Ability(ABILITY_PROTOSYNTHESIS); Attack(50); Defense(50); SpAttack(150); SpDefense(140); Speed(180); }
        OPPONENT(SPECIES_GALVANTULA) { Speed(60); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_STICKY_WEB); MOVE(player, MOVE_SUNNY_DAY); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_SPLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Flutter Mane's Protosynthesis!");
        MESSAGE("Flutter Mane's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis keeps its initial boosted stat after Speed is lowered")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_FLUTTER_MANE) { Ability(ABILITY_PROTOSYNTHESIS); Attack(10); Defense(10); SpAttack(150); SpDefense(120); Speed(180); Moves(MOVE_ROUND); }
        OPPONENT(SPECIES_NINETALES) { Ability(ABILITY_DROUGHT); Moves(MOVE_ICY_WIND, MOVE_CELEBRATE); Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_ICY_WIND); }
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICY_WIND, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis recalculates the boosted stat after Neutralizing Gas leaves the field")
{
    GIVEN {
        PLAYER(SPECIES_FLUTTER_MANE) { Ability(ABILITY_PROTOSYNTHESIS); Attack(10); Defense(10); SpAttack(150); SpDefense(120); Speed(180); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Moves(MOVE_ICY_WIND); Speed(70); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_ICY_WIND); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        NOT ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICY_WIND, opponent);
        MESSAGE("The effects of the neutralizing gas wore off!");
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Flutter Mane's Protosynthesis!");
        MESSAGE("Flutter Mane's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Protosynthesis retains its boosted stat after Neutralizing Gas briefly suppresses it")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_FLUTTER_MANE) { Ability(ABILITY_PROTOSYNTHESIS); Attack(10); Defense(10); SpAttack(150); SpDefense(120); Speed(180); Moves(MOVE_SUNNY_DAY, MOVE_ROUND, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); Speed(1); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Moves(MOVE_CELEBRATE); Speed(70); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_CELEBRATE); SWITCH(opponent, 0); }
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Neutralizing gas filled the area!");
        MESSAGE("The effects of the neutralizing gas wore off!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Protosynthesis damage calculation is correct")
{
    s16 dmg;
    s16 expectedDamage;

    PARAMETRIZE { expectedDamage = 127; }
    PARAMETRIZE { expectedDamage = 126; }
    PARAMETRIZE { expectedDamage = 124; }
    PARAMETRIZE { expectedDamage = 123; }
    PARAMETRIZE { expectedDamage = 121; }
    PARAMETRIZE { expectedDamage = 120; }
    PARAMETRIZE { expectedDamage = 118; }
    PARAMETRIZE { expectedDamage = 118; }
    PARAMETRIZE { expectedDamage = 117; }
    PARAMETRIZE { expectedDamage = 115; }
    PARAMETRIZE { expectedDamage = 114; }
    PARAMETRIZE { expectedDamage = 112; }
    PARAMETRIZE { expectedDamage = 111; }
    PARAMETRIZE { expectedDamage = 109; }
    PARAMETRIZE { expectedDamage = 109; }
    PARAMETRIZE { expectedDamage = 108; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_CLOSE_COMBAT) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_GOUGING_FIRE) { Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_URSHIFU_RAPID_STRIKE);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CLOSE_COMBAT, WITH_RNG(RNG_DAMAGE_MODIFIER, i)); }
    } SCENE {
        HP_BAR(player, captureDamage: &dmg);
    } THEN {
        EXPECT_EQ(expectedDamage, dmg);
    }
}
