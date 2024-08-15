#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    // ASSUME(gMovesInfo[MOVE_AERIAL_ACE].category == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("(Gulp Missile) If base Cramorant hits target with Surf it transforms into Gulping form if max HP is over 1/2")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GULPING);
    }
}

SINGLE_BATTLE_TEST("(Gulp Missile) If base Cramorant hits target with Surf it transforms into Gorging form if max HP is under 1/2")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { HP(120); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GORGING);
    }
}

SINGLE_BATTLE_TEST("(Gulp Missile) If base Cramorant is under water it transforms into one of its forms")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        NOT HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GULPING);
    }
}

SINGLE_BATTLE_TEST("(Gulp Missile) Power Herb does not prevent Cramaront from transforming")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        MESSAGE("Cramorant became fully charged due to its Power Herb!");
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GULPING);
    }
}

SINGLE_BATTLE_TEST("(Gulp Missile) Transformed Cramorant deal 1/4 of damage opposing mon if hit by a damaging move, Gulping also lowers defense")
{
    s16 gulpMissileDamage;

    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        HP_BAR(opponent, captureDamage: &gulpMissileDamage);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Defense fell!");
    } THEN {
        EXPECT_EQ(gulpMissileDamage, opponent->maxHP / 4);
    }
}

SINGLE_BATTLE_TEST("(Gulp Missile) Cramorant in Gorging paralyzes the target if hit by a damaging move")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { HP(120); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("(Gulp Missile) triggers even if the user is fainted by opposing mon")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { HP(1); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        HP_BAR(opponent);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}
