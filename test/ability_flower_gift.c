#include "global.h"
#include "test_battle.h"

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim in harsh sunlight")
{
    GIVEN {
        PLAYER(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FLOWER_GIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
    }
}

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim back to normal when weather changes")
{
    GIVEN {
        PLAYER(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { MOVE(opponent, MOVE_RAIN_DANCE); }
    } SCENE {
        // transforms in sun
        ABILITY_POPUP(player, ABILITY_FLOWER_GIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
        // back to normal
        ABILITY_POPUP(player, ABILITY_FLOWER_GIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
    }
}

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim back to normal when its ability is suppressed")
{
    GIVEN {
        PLAYER(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { MOVE(opponent, MOVE_GASTRO_ACID); }
    } SCENE {
        // transforms in sun
        ABILITY_POPUP(player, ABILITY_FLOWER_GIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
        // back to normal
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
    }
}

DOUBLE_BATTLE_TEST("Flower Gift increases the attack of Cherrim's ally by 1.5x", s16 damage)
{
    bool32 sunny;
    PARAMETRIZE { sunny = FALSE; }
    PARAMETRIZE { sunny = TRUE; }
    GIVEN {
        PLAYER(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); };
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (sunny)
            TURN { MOVE(playerLeft, MOVE_SUNNY_DAY); }
        TURN { MOVE(playerRight, MOVE_TACKLE, target: opponentLeft); }
    } SCENE {
        // Sun activates
        if (sunny) {
            ABILITY_POPUP(playerLeft, ABILITY_FLOWER_GIFT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, playerLeft);
            MESSAGE("Cherrim transformed!");
        }
        // Partner uses Tackle
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.5), results[1].damage);
    }
}

TO_DO_BATTLE_TEST("Flower Gift does not transform Cherrim back to normal when suppressed if Cherrim is Dynamaxed");
