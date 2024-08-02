#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_BOOSTER_ENERGY].holdEffect == HOLD_EFFECT_BOOSTER_ENERGY);
}

SINGLE_BATTLE_TEST("Booster Energy will activate Quark Drive after Electric Terrain ends")
{
    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Attack(100); Defense(100); Speed(100); SpAttack(110); SpDefense(100); Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_TAPU_KOKO) { Speed(100); Ability(ABILITY_ELECTRIC_SURGE); };
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Iron Moth used its Booster Energy to activate Quark Drive!");
            MESSAGE("Iron Moth's Sp. Atk was heightened!");
        }
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("The Electric Terrain activated Iron Moth's Quark Drive!");
        MESSAGE("Iron Moth's Sp. Atk was heightened!");
        MESSAGE("The electricity disappeared from the battlefield.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("Iron Moth used its Booster Energy to activate Quark Drive!");
        MESSAGE("Iron Moth's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Booster Energy will activate Protosynthesis after harsh sunlight ends")
{
    GIVEN {
        PLAYER(SPECIES_RAGING_BOLT) { Attack(100); Defense(100); Speed(100); SpAttack(110); SpDefense(100); Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_TORKOAL) { Speed(100); Ability(ABILITY_DROUGHT); };
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Raging Bolt used its Booster Energy to activate Protosynthesis!");
            MESSAGE("Raging Bolt's Sp. Atk was heightened!");
        }
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("The harsh sunlight activated Raging Bolt's Protosynthesis!");
        MESSAGE("Raging Bolt's Sp. Atk was heightened!");
        MESSAGE("The sunlight faded.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("Raging Bolt used its Booster Energy to activate Protosynthesis!");
        MESSAGE("Raging Bolt's Sp. Atk was heightened!");
    }
}

SINGLE_BATTLE_TEST("Booster Energy activates Protosynthesis and increases highest stat")
{
    u32 attack, defense, speed, spAttack, spDefense;

    PARAMETRIZE { attack = 110; defense = 100; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 110; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 110; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 110; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 100; spDefense = 110; }

    GIVEN {
        PLAYER(SPECIES_RAGING_BOLT) { Attack(attack); Defense(defense); Speed(speed); SpAttack(spAttack); SpDefense(spDefense); Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); };
    } WHEN {
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("Raging Bolt used its Booster Energy to activate Protosynthesis!");
        if (attack == 110)
            MESSAGE("Raging Bolt's Attack was heightened!");
        else if (defense == 110)
            MESSAGE("Raging Bolt's Defense was heightened!");
        else if (speed == 110)
            MESSAGE("Raging Bolt's Speed was heightened!");
        else if (spAttack == 110)
            MESSAGE("Raging Bolt's Sp. Atk was heightened!");
        else if (spDefense == 110)
            MESSAGE("Raging Bolt's Sp. Def was heightened!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Booster Energy activates Quark Drive and increases highest stat")
{
    u32 attack, defense, speed, spAttack, spDefense;

    PARAMETRIZE { attack = 110; defense = 100; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 110; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 110; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 110; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 100; spDefense = 110; }

    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Attack(attack); Defense(defense); Speed(speed); SpAttack(spAttack); SpDefense(spDefense); Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); };
    } WHEN {
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        if (attack == 110)
            MESSAGE("Iron Moth's Attack was heightened!");
        else if (defense == 110)
            MESSAGE("Iron Moth's Defense was heightened!");
        else if (speed == 110)
            MESSAGE("Iron Moth's Speed was heightened!");
        else if (spAttack == 110)
            MESSAGE("Iron Moth's Sp. Atk was heightened!");
        else if (spDefense == 110)
            MESSAGE("Iron Moth's Sp. Def was heightened!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Booster Energy increases special attack by 30% if it is the highest stat", s16 damage)
{
    u32 species;
    u32 ability;
    u32 item;

    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_BOOSTER_ENERGY; }

    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_BOOSTER_ENERGY; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_ROUND].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(species) { Attack(100); Defense(100); Speed(100); SpAttack(110); SpDefense(100); Ability(ability); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); };
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Booster Energy increases special defense by 30% if it is the highest stat", s16 damage)
{
    u32 species;
    u32 ability;
    u32 item;

    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_BOOSTER_ENERGY; }

    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_BOOSTER_ENERGY; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_ROUND].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(species) { Attack(100); Defense(100); Speed(100); SpAttack(100); SpDefense(110); Ability(ability); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.7), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Booster Energy can't be flung if a Paradox species is involved")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_IRON_MOTH].isParadox == TRUE);
        PLAYER(SPECIES_IRON_MOTH);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BOOSTER_ENERGY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLING); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, opponent);
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Booster Energy can't be tricked if a Paradox species is involved")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_IRON_MOTH].isParadox == TRUE);
        PLAYER(SPECIES_IRON_MOTH) { Item(ITEM_BERRY_JUICE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BOOSTER_ENERGY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRICK); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
        MESSAGE("But it failed!");
    }
}
