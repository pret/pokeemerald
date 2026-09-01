#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Iron Barbs: Damages attackers that make contact")
{
    const u32 maxHP = 800;
    const u32 ironBarbsDamage = maxHP / 8;

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_POPULATION_BOMB));
        ASSUME(GetMoveEffect(MOVE_POPULATION_BOMB) == EFFECT_POPULATION_BOMB);
        ASSUME(GetItemHoldEffect(ITEM_LOADED_DICE) == HOLD_EFFECT_LOADED_DICE);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(maxHP); HP(maxHP); Item(ITEM_LOADED_DICE); }
        OPPONENT(SPECIES_FERROSEED) { Ability(ABILITY_IRON_BARBS); }
    } WHEN {
        TURN { MOVE(player, MOVE_POPULATION_BOMB, WITH_RNG(RNG_LOADED_DICE, 4)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        MESSAGE("The Pokémon was hit 4 times!");
        NONE_OF {
            HP_BAR(player);
            MESSAGE("Wobbuffet was hurt by the opposing Ferroseed's Iron Barbs!");
        }
    } THEN {
        EXPECT_EQ(player->hp, maxHP - ironBarbsDamage * 4);
    }
}

SINGLE_BATTLE_TEST("Rough Skin and Iron Barbs cause the attacker to take damage when using a contact move")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_GARCHOMP; ability = ABILITY_ROUGH_SKIN; }
    PARAMETRIZE { species = SPECIES_FERROTHORN; ability = ABILITY_IRON_BARBS; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (ability == ABILITY_ROUGH_SKIN)
            ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        else
            ABILITY_POPUP(opponent, ABILITY_IRON_BARBS);
    }
}

TO_DO_BATTLE_TEST("TODO: Write Iron Barbs (Ability) test titles")
