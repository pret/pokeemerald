#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_AERIAL_ACE].category == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Disguised Mimikyu will lose 1/8 of its max HP upon changing to its busted form")
{
    s16 disguiseDamage;

    GIVEN {
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        HP_BAR(player, captureDamage: &disguiseDamage);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MIMIKYU_BUSTED);
        EXPECT_EQ(disguiseDamage, player->maxHP / 8);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes no damage from a confusion hit and changes to its busted form")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_CONFUSE_RAY].effect == EFFECT_CONFUSE);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        MESSAGE("Mimikyu became confused!");
        MESSAGE("Mimikyu is confused!");
        MESSAGE("It hurt itself in its confusion!");
        NOT HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MIMIKYU_BUSTED);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu's Air Balloon will pop upon changing to its busted form")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        MESSAGE("Mimikyu floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        NOT HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        MESSAGE("Mimikyu's Air Balloon popped!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MIMIKYU_BUSTED);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes damage from secondary damage without breaking the disguise")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_STEALTH_ROCK].effect == EFFECT_STEALTH_ROCK);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        HP_BAR(player);
        MESSAGE("Pointed stones dug into Mimikyu!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MIMIKYU_DISGUISED);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes damage from Rocky Helmet without breaking the disguise")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ROCKY_HELMET].holdEffect == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        HP_BAR(player);
        MESSAGE("Mimikyu was hurt by Foe Wobbuffet's Rocky Helmet!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MIMIKYU_DISGUISED);
    }
}

SINGLE_BATTLE_TEST("Disguised Mimikyu takes damage from Rough Skin without breaking the disguise")
{
    GIVEN {
        PLAYER(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_CARVANHA) { Ability(ABILITY_ROUGH_SKIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
        HP_BAR(player);
        MESSAGE("Mimikyu was hurt by Foe Carvanha's Rough Skin!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MIMIKYU_DISGUISED);
    }
}
