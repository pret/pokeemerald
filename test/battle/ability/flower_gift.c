#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim in harsh sunlight")
{
    GIVEN {
        PLAYER(SPECIES_CHERRIM_OVERCAST) { Ability(ABILITY_FLOWER_GIFT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_FLOWER_GIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CHERRIM_SUNSHINE);
    }
}

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim back to normal when weather changes")
{
    GIVEN {
        PLAYER(SPECIES_CHERRIM_OVERCAST) { Ability(ABILITY_FLOWER_GIFT); }
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
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CHERRIM_OVERCAST);
    }
}

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim back to normal when its ability is suppressed")
{
    GIVEN {
        ASSUME(B_WEATHER_FORMS >= GEN_5);
        PLAYER(SPECIES_CHERRIM_OVERCAST) { Ability(ABILITY_FLOWER_GIFT); }
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
    } THEN {
        EXPECT_EQ(player->species, SPECIES_CHERRIM_OVERCAST);
    }
}

DOUBLE_BATTLE_TEST("Flower Gift increases the attack of Cherrim and its allies by 1.5x", s16 damageL, s16 damageR)
{
    bool32 sunny;
    PARAMETRIZE { sunny = FALSE; }
    PARAMETRIZE { sunny = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_CHERRIM_OVERCAST) { Ability(ABILITY_FLOWER_GIFT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (sunny)
            TURN { MOVE(playerLeft, MOVE_SUNNY_DAY); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft);
               MOVE(playerRight, MOVE_TACKLE, target: opponentLeft); }
    } SCENE {
        // sun activates
        if (sunny) {
            ABILITY_POPUP(playerLeft, ABILITY_FLOWER_GIFT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, playerLeft);
            MESSAGE("Cherrim transformed!");
        }
        // player uses Tackle
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damageL);
        // partner uses Tackle
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, playerRight);
        HP_BAR(opponentLeft, captureDamage: &results[i].damageR);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damageL, UQ_4_12(1.5), results[1].damageL);
        EXPECT_MUL_EQ(results[0].damageR, UQ_4_12(1.5), results[1].damageR);
    }
}

DOUBLE_BATTLE_TEST("Flower Gift increases the Sp. Def of Cherrim and its allies by 1.5x", s16 damageL, s16 damageR)
{
    bool32 sunny;
    PARAMETRIZE { sunny = FALSE; }
    PARAMETRIZE { sunny = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_HYPER_VOICE].category == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_CHERRIM_OVERCAST) { Ability(ABILITY_FLOWER_GIFT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (sunny)
            TURN { MOVE(playerLeft, MOVE_SUNNY_DAY); }
        TURN { MOVE(opponentLeft, MOVE_HYPER_VOICE, target: playerLeft); }
    } SCENE {
        // sun activates
        if (sunny) {
            ABILITY_POPUP(playerLeft, ABILITY_FLOWER_GIFT);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, playerLeft);
            MESSAGE("Cherrim transformed!");
        }
        // opponentLeft uses Hyper Voice
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damageL);
        HP_BAR(playerRight, captureDamage: &results[i].damageR);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damageL, UQ_4_12(1.5), results[0].damageL);
        EXPECT_MUL_EQ(results[1].damageR, UQ_4_12(1.5), results[0].damageR);
    }
}

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim back when it switches out")
{
    GIVEN {
        ASSUME(B_WEATHER_FORMS >= GEN_5);
        PLAYER(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        // transforms in sun
        ABILITY_POPUP(player, ABILITY_FLOWER_GIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
        MESSAGE("Cherrim, that's enough! Come back!");
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_CHERRIM);
    }
}

SINGLE_BATTLE_TEST("Flower Gift transforms Cherrim back when it uses a move that forces it to switch out")
{
    GIVEN {
        ASSUME(B_WEATHER_FORMS >= GEN_5);
        PLAYER(SPECIES_CHERRIM) { Ability(ABILITY_FLOWER_GIFT); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        // transforms in sun
        ABILITY_POPUP(player, ABILITY_FLOWER_GIFT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Cherrim transformed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_CHERRIM);
    }
}

TO_DO_BATTLE_TEST("Flower Gift does not transform Cherrim back to normal when suppressed if Cherrim is Dynamaxed");
