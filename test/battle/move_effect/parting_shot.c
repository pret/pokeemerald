#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_PARTING_SHOT) == EFFECT_PARTING_SHOT);
}

SINGLE_BATTLE_TEST("Parting Shot: Passes Substitute and switches the user out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SUBSTITUTE, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SUBSTITUTE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Soundproof and Good as Gold block Parting Shot")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_EXPLOUD;   ability = ABILITY_SOUNDPROOF; }
    PARAMETRIZE { species = SPECIES_GHOLDENGO; ability = ABILITY_GOOD_AS_GOLD; }

    GIVEN {
        ASSUME(IsSoundMove(MOVE_PARTING_SHOT));
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_SOUNDPROOF)
            MESSAGE("It doesn't affect the opposing Exploud…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Hyper Cutter blocks Attack drop but still switches")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_KRABBY) { Ability(ABILITY_HYPER_CUTTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Magic Coat bounces it and switches the target out and original user doesn't switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MAGIC_COAT); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MAGIC_COAT); MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Magic Bounce bounces it and switches the target out and original user doesn't switch out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(opponent, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mirror Armor switches the user even if reflected drops fail")
{
    enum Species species;
    enum Ability ability;
    enum Item item;

    PARAMETRIZE { species = SPECIES_METAGROSS; ability = ABILITY_CLEAR_BODY;      item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_TORKOAL;   ability = ABILITY_WHITE_SMOKE;     item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO;  ability = ABILITY_FULL_METAL_BODY; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_LUCARIO;   ability = ABILITY_INNER_FOCUS;     item = ITEM_CLEAR_AMULET; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(species) { Ability(ability); Item(item); Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        if (ability == ABILITY_CLEAR_BODY) {
            ABILITY_POPUP(player, ABILITY_CLEAR_BODY);
            MESSAGE("Metagross's stats were not lowered!");
        } else if (ability == ABILITY_WHITE_SMOKE) {
            ABILITY_POPUP(player, ABILITY_WHITE_SMOKE);
            MESSAGE("Torkoal's stats were not lowered!");
        } else if (ability == ABILITY_FULL_METAL_BODY) {
            ABILITY_POPUP(player, ABILITY_FULL_METAL_BODY);
            MESSAGE("Solgaleo's stats were not lowered!");
        } else if (item == ITEM_CLEAR_AMULET) {
            MESSAGE("The effects of the Clear Amulet held by Lucario prevents its stats from being lowered!");
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mirror Armor switches even if reflected stats are at minimum")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); Moves(MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SMASH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SHELL_SMASH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SHELL_SMASH); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_TOPSY_TURVY); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Does not switch if both stats are at minimum (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_OMASTAR) { Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Omastar's Attack won't go any lower!");
        MESSAGE("The opposing Omastar's Sp. Atk won't go any lower!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MIN_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MIN_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Does not switch if Contrary is at maximum stats (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_INKAY) { Ability(ABILITY_CONTRARY); Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("The opposing Inkay's Attack won't go any higher!");
        MESSAGE("The opposing Inkay's Sp. Atk won't go any higher!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MAX_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Stat drop prevention by abilities/items does not switch (Gen7+)")
{
    enum Species species;
    enum Ability ability;
    enum Item item;

    PARAMETRIZE { species = SPECIES_METAGROSS; ability = ABILITY_CLEAR_BODY;      item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_TORKOAL;   ability = ABILITY_WHITE_SMOKE;     item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO;  ability = ABILITY_FULL_METAL_BODY; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_LUCARIO;   ability = ABILITY_INNER_FOCUS;     item = ITEM_CLEAR_AMULET; }

    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_7);
        ASSUME(gItemsInfo[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mist prevents stat drops and does not switch (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MIST, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_PARTING_SHOT); }
    } SCENE {
        // ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player); ???
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

DOUBLE_BATTLE_TEST("Parting Shot: Flower Veil prevents stat drops and does not switch (Gen7+)")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_BULBASAUR, 0) == TYPE_GRASS);
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PARTING_SHOT, target: opponentLeft); MOVE(playerRight, MOVE_CELEBRATE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, playerLeft);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerLeft->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Switches if both stats are at minimum (Gen6)")
{
    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_OMASTAR) { Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("The opposing Omastar's Attack won't go any lower!");
        MESSAGE("The opposing Omastar's Sp. Atk won't go any lower!");
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MIN_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MIN_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Switches if Contrary is at maximum stats (Gen6)")
{
    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_TOPSY_TURVY, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_INKAY) { Ability(ABILITY_CONTRARY); Moves(MOVE_SHELL_SMASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SHELL_SMASH); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_PARTING_SHOT); MOVE(opponent, MOVE_CELEBRATE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("The opposing Inkay's Attack won't go any higher!");
        MESSAGE("The opposing Inkay's Sp. Atk won't go any higher!");
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], MAX_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], MAX_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Stat drop prevention by abilities/items switches (Gen6)")
{
    enum Species species;
    enum Ability ability;
    enum Item item;

    PARAMETRIZE { species = SPECIES_METAGROSS; ability = ABILITY_CLEAR_BODY;      item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_TORKOAL;   ability = ABILITY_WHITE_SMOKE;     item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO;  ability = ABILITY_FULL_METAL_BODY; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_LUCARIO;   ability = ABILITY_INNER_FOCUS;     item = ITEM_CLEAR_AMULET; }

    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_6);
        ASSUME(gItemsInfo[ITEM_CLEAR_AMULET].holdEffect == HOLD_EFFECT_CLEAR_AMULET);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(species) { Ability(ability); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Parting Shot: Mist prevents stat drops and switches (Gen6)")
{
    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_6);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_MIST, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_PARTING_SHOT); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, player);
        SEND_IN_MESSAGE("Wynaut");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

DOUBLE_BATTLE_TEST("Parting Shot: Flower Veil prevents stat drops and switches (Gen6)")
{
    GIVEN {
        WITH_CONFIG(B_PARTING_SHOT_SWITCH, GEN_6);
        ASSUME(GetSpeciesType(SPECIES_BULBASAUR, 0) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_PARTING_SHOT); }
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PARTING_SHOT, target: opponentLeft); MOVE(playerRight, MOVE_CELEBRATE); SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PARTING_SHOT, playerLeft);
        SEND_IN_MESSAGE("Pikachu");
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(playerLeft->species, SPECIES_PIKACHU);
    }
}
