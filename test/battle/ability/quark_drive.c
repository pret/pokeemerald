#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Quark Drive boosts the highest stat")
{
    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Iron Moth's Quark Drive!");
        MESSAGE("Iron Moth's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive boosts either Attack or Special Attack, not both")
{
    enum Species species;
    enum Move move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_IRON_VALIANT; move = MOVE_SCRATCH; }
    PARAMETRIZE { species = SPECIES_IRON_VALIANT; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_IRON_MOTH; move = MOVE_SCRATCH; }
    PARAMETRIZE { species = SPECIES_IRON_MOTH; move = MOVE_ROUND; }

    GIVEN {
        PLAYER(species) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { MOVE(opponent, MOVE_ELECTRIC_TERRAIN); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        if ((move == MOVE_SCRATCH && species == SPECIES_IRON_VALIANT) || (move == MOVE_ROUND && species == SPECIES_IRON_MOTH))
            EXPECT_MUL_EQ(damage[0], Q_4_12(1.3), damage[1]);
        else
            EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Quark Drive keeps its initial boosted stat after Speed is lowered")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Ability(ABILITY_QUARK_DRIVE); Attack(10); Defense(10); SpAttack(150); SpDefense(120); Speed(180); Moves(MOVE_ROUND, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Moves(MOVE_CELEBRATE, MOVE_ICY_WIND); Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_ICY_WIND); }
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICY_WIND, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Quark Drive retains its boosted stat after Neutralizing Gas briefly suppresses it")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Ability(ABILITY_QUARK_DRIVE); Attack(10); Defense(10); SpAttack(150); SpDefense(120); Speed(180); Moves(MOVE_ELECTRIC_TERRAIN, MOVE_ROUND, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); Speed(1); }
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); Moves(MOVE_CELEBRATE); Speed(70); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_CELEBRATE); SWITCH(opponent, 0); }
        TURN { MOVE(player, MOVE_ROUND); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
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

SINGLE_BATTLE_TEST("Quark Drive ability pop up activates only once during the duration of electric terrain")
{
    u16 turns;

    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        for (turns = 0; turns < 4; turns++)
            TURN {}
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Iron Moth's Quark Drive!");
        MESSAGE("Iron Moth's Sp. Atk was heightened!");
        NONE_OF {
            for (turns = 0; turns < 4; turns++) {
                ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
                MESSAGE("The Electric Terrain activated Iron Moth's Quark Drive!");
                MESSAGE("Iron Moth's Sp. Atk was heightened!");
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Iron Moth's Quark Drive!");
        MESSAGE("Iron Moth's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive activates on switch-in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_IRON_MOTH) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Iron Moth's Quark Drive!");
        MESSAGE("Iron Moth's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive activates on Electric Terrain even if not grounded")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_IRON_JUGULIS, 0) == TYPE_FLYING || GetSpeciesType(SPECIES_IRON_JUGULIS, 1) == TYPE_FLYING);
        PLAYER(SPECIES_IRON_JUGULIS) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
    }
}

SINGLE_BATTLE_TEST("Quark Drive prioritizes stats in the case of a tie in the following order: Atk, Def, Sp.Atk, Sp.Def, Speed")
{
    u8 stats[] = {1, 1, 1, 1, 1};

    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; stats[1] = 255; stats[0] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; stats[1] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; stats[2] = 255; }
    PARAMETRIZE { stats[4] = 255; stats[3] = 255; }
    GIVEN {
        PLAYER(SPECIES_IRON_TREADS) { Ability(ABILITY_QUARK_DRIVE); Attack(stats[0]); Defense(stats[1]); SpAttack(stats[2]); SpDefense(stats[3]); Speed(stats[4]); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Speed(5); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        switch(i) {
            case 0:
                MESSAGE("Iron Treads's Attack was heightened!");
                break;
            case 1:
                MESSAGE("Iron Treads's Defense was heightened!");
                break;
            case 2:
                MESSAGE("Iron Treads's Sp. Atk was heightened!");
                break;
            case 3:
                MESSAGE("Iron Treads's Sp. Def was heightened!");
                break;
        }
    }
}

SINGLE_BATTLE_TEST("Quark Drive uses Wonder Room swapped defenses when choosing boosted stat")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
        PLAYER(SPECIES_IRON_LEAVES) { Ability(ABILITY_QUARK_DRIVE); Attack(50); Defense(200); SpAttack(40); SpDefense(60); Speed(70); Moves(MOVE_WONDER_ROOM); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_ELECTRIC_TERRAIN); Speed(60); }
    } WHEN {
        TURN { MOVE(player, MOVE_WONDER_ROOM); MOVE(opponent, MOVE_ELECTRIC_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WONDER_ROOM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, opponent);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Iron Leaves's Quark Drive!");
        MESSAGE("Iron Leaves's Sp. Def was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive activates in Electric Terrain before Booster Energy")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_IRON_TREADS) { Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
    } THEN {
        EXPECT_EQ(player->item, ITEM_BOOSTER_ENERGY);
    }
}

SINGLE_BATTLE_TEST("Quark Drive doesn't activate for a transformed battler")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_IRON_TREADS) { Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Item(ITEM_BOOSTER_ENERGY); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TRANSFORM); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_QUARK_DRIVE);
    } THEN {
        EXPECT_EQ(player->item, ITEM_BOOSTER_ENERGY);
        EXPECT_EQ(opponent->item, ITEM_BOOSTER_ENERGY);
        EXPECT_EQ(opponent->ability, ABILITY_QUARK_DRIVE);
    }
}
