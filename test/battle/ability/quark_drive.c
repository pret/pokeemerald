#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(gMovesInfo[MOVE_ROUND].category == DAMAGE_CATEGORY_SPECIAL);
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
    u16 species;
    u32 move;
    s16 damage[2];

    PARAMETRIZE { species = SPECIES_IRON_VALIANT; move = MOVE_TACKLE; }
    PARAMETRIZE { species = SPECIES_IRON_VALIANT; move = MOVE_ROUND; }

    PARAMETRIZE { species = SPECIES_IRON_MOTH; move = MOVE_TACKLE; }
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
        if ((move == MOVE_TACKLE && species == SPECIES_IRON_VALIANT) || (move == MOVE_ROUND && species == SPECIES_IRON_MOTH))
            EXPECT_MUL_EQ(damage[0], Q_4_12(1.3), damage[1]);
        else
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
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); };
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
        ASSUME(gSpeciesInfo[SPECIES_IRON_JUGULIS].types[0] == TYPE_FLYING || gSpeciesInfo[SPECIES_IRON_JUGULIS].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_IRON_JUGULIS) { Ability(ABILITY_QUARK_DRIVE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); };
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
    }
}

SINGLE_BATTLE_TEST("Quark Drive boosts Attack 1st in case of a stat tie")
{
    GIVEN {
        PLAYER(SPECIES_IRON_TREADS) { Ability(ABILITY_QUARK_DRIVE); Attack(5); Defense(5); SpAttack(5); SpDefense(5); Speed(5); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Speed(5); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("Iron Treads's Attack was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive boosts Defense 2nd in case of a stat tie")
{
    GIVEN {
        PLAYER(SPECIES_IRON_TREADS) { Ability(ABILITY_QUARK_DRIVE); Attack(4); Defense(5); SpAttack(5); SpDefense(5); Speed(5); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Speed(5); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("Iron Treads's Defense was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive boosts Special Attack 3rd in case of a stat tie")
{
    GIVEN {
        PLAYER(SPECIES_IRON_TREADS) { Ability(ABILITY_QUARK_DRIVE); Attack(4); Defense(4); SpAttack(5); SpDefense(5); Speed(5); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Speed(5); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("Iron Treads's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Quark Drive boosts Special Defense 4th in case of a stat tie")
{
    GIVEN {
        PLAYER(SPECIES_IRON_TREADS) { Ability(ABILITY_QUARK_DRIVE); Attack(4); Defense(4); SpAttack(4); SpDefense(5); Speed(5); }
        OPPONENT(SPECIES_TAPU_KOKO) { Ability(ABILITY_ELECTRIC_SURGE); Speed(5); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("Iron Treads's Sp. Def was heightened!");
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
