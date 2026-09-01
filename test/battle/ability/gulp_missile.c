#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Gulp Missile: Cramorant cannot change between Gorging and Gulping Forms")
{
    enum Species species;
    u32 hp;
    enum Move move;
    PARAMETRIZE { species = SPECIES_CRAMORANT_GULPING; hp = 240; move = MOVE_BELLY_DRUM; }
    PARAMETRIZE { species = SPECIES_CRAMORANT_GORGING; hp = 120; move = MOVE_RECOVER; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BELLY_DRUM) == EFFECT_BELLY_DRUM);
        PLAYER(SPECIES_CRAMORANT) { HP(hp); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); }
        TURN { MOVE(player, move); }
        TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
    } THEN {
        EXPECT_EQ(player->species, species);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: If base Cramorant hits target with Surf it transforms into Gulping form if max HP is over 1/2")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GULPING);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: If base Cramorant hits target with Surf it transforms into Gorging form if max HP is under 1/2")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { HP(120); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GORGING);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: If base Cramorant is under water it transforms into one of its forms")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GULPING);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: Power Herb does not prevent Cramaront from transforming")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        MESSAGE("Cramorant became fully charged due to its Power Herb!");
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GULPING);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: Transformed Cramorant deal 1/4 of damage opposing mon if hit by a damaging move, Gulping also lowers defense")
{
    s16 gulpMissileDamage;

    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent, captureDamage: &gulpMissileDamage);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Defense fell!");
    } THEN {
        EXPECT_EQ(gulpMissileDamage, opponent->maxHP / 4);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: Cramorant in Gorging paralyzes the target if hit by a damaging move")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { HP(120); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: triggers even if the user is fainted by opposing mon")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { HP(1); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: Transformed Cramorant Gulping lowers defense but is prevented by stat reduction preventing abilities")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_METAGROSS; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { species = SPECIES_CORVIKNIGHT; ability = ABILITY_MIRROR_ARMOR; }
    PARAMETRIZE { species = SPECIES_CHATOT; ability = ABILITY_BIG_PECKS; }
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(species) { Ability(ability); HP(9999); MaxHP(9999); } // In Gen 5 data, Surf would be enough to knock out Chatot
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        ABILITY_POPUP(opponent, ability);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: Transformed Cramorant Gulping lowers defense and still triggers other effects after")
{
    // Make sure attacker and target are correct after triggering the ability
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }
    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); Item(ITEM_ROCKY_HELMET); }
        OPPONENT(SPECIES_DRAGAPULT) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        if (ability == ABILITY_INFILTRATOR) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("The opposing Dragapult's Defense fell!");
        } else {
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
        }
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile triggered by explosion doesn't freeze the game")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CRAMORANT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SURF); MOVE(player, MOVE_EXPLOSION); }
    }
}

SINGLE_BATTLE_TEST("(Gulp Missile) Cramorant in Gorging damages an electric type without paralysing")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { HP(120); MaxHP(250); Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_EELEKTROSS);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_GULP_MISSILE);
        HP_BAR(opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile only changes forms for Cramorant")
{
    GIVEN {
        ASSUME(!gAbilitiesInfo[ABILITY_GULP_MISSILE].cantBeSwapped);
        ASSUME(!gAbilitiesInfo[ABILITY_LIGHTNING_ROD].cantBeSwapped);
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(opponent, MOVE_SURF); MOVE(player, MOVE_SURF); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, opponent);
        }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT);
        EXPECT_EQ(opponent->species, SPECIES_PIKACHU);
    }
}

SINGLE_BATTLE_TEST("Gulp Missile: If Cramorant loses Gulp Missile, it cannot spit out its prey")
{
    GIVEN {
        ASSUME(!gAbilitiesInfo[ABILITY_GULP_MISSILE].cantBeSwapped);
        ASSUME(!gAbilitiesInfo[ABILITY_LIGHTNING_ROD].cantBeSwapped);
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); MOVE(opponent, MOVE_SKILL_SWAP); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
            HP_BAR(opponent);
        }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CRAMORANT_GULPING);
        EXPECT_EQ(opponent->species, SPECIES_PIKACHU);
    }
}
