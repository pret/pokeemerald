#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_BLUNDER_POLICY].holdEffect == HOLD_EFFECT_BLUNDER_POLICY);
}

SINGLE_BATTLE_TEST("Blunder Policy raises the users speed by 2 stages if the user misses")
{
    PASSES_RANDOMLY(3, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_FOCUS_BLAST) == 70);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_BLAST); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_BLAST, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}


SINGLE_BATTLE_TEST("Blunder Policy will never trigger if the move fails due to an immunity")
{
    PASSES_RANDOMLY(10, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_FOCUS_BLAST) == 70);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_FOCUS_BLAST); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_BLAST, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    } THEN {
        EXPECT(player->item == ITEM_BLUNDER_POLICY);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy will never trigger if the move fails due to Protect")
{
    PASSES_RANDOMLY(10, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_FOCUS_BLAST) == 70);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_FOCUS_BLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_BLAST, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    } THEN {
        EXPECT(player->item == ITEM_BLUNDER_POLICY);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy will never trigger if an OHKO move fails")
{
    PASSES_RANDOMLY(7, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_FISSURE) == 30);
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    } THEN {
        EXPECT(player->item == ITEM_BLUNDER_POLICY);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy will never trigger if the move misses due to semi-invulnerability")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLY); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLY, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    } THEN {
        EXPECT(player->item == ITEM_BLUNDER_POLICY);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy state is cleared between actions if it could not activate")
{
    PASSES_RANDOMLY(3, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_FOCUS_BLAST) == 70);
        ASSUME_STAT_CHANGE(MOVE_AGILITY, speed: +2);
        ASSUME(GetMoveEffect(MOVE_CURSE) == EFFECT_CURSE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_FOCUS_BLAST); }
        TURN { MOVE(player, MOVE_CURSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FOCUS_BLAST, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CURSE, player);
    } THEN {
        EXPECT(player->item == ITEM_BLUNDER_POLICY);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 5);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy activates if the first strike of Triple Kick misses")
{
    PASSES_RANDOMLY(1, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_TRIPLE_KICK) == 90);
        ASSUME(GetMoveEffect(MOVE_TRIPLE_KICK) == EFFECT_TRIPLE_KICK);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_KICK); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy does not activate if Triple Kick misses after the first strike")
{
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_TRIPLE_KICK) == 90);
        ASSUME(GetMoveEffect(MOVE_TRIPLE_KICK) == EFFECT_TRIPLE_KICK);
        ASSUME(MoveMakesContact(MOVE_TRIPLE_KICK));
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_OINKOLOGNE) { Ability(ABILITY_LINGERING_AROMA); }
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_KICK, WITH_RNG(RNG_ACCURACY, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
        ABILITY_POPUP(opponent, ABILITY_LINGERING_AROMA);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    } THEN {
        EXPECT(player->item == ITEM_BLUNDER_POLICY);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->ability, ABILITY_LINGERING_AROMA);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy activates if the first strike of Population Bomb misses")
{
    PASSES_RANDOMLY(1, 10, RNG_ACCURACY);
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_POPULATION_BOMB) == 90);
        ASSUME(GetMoveEffect(MOVE_POPULATION_BOMB) == EFFECT_POPULATION_BOMB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POPULATION_BOMB); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT(player->item == ITEM_NONE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Blunder Policy does not activate if Population Bomb misses after the first strike")
{
    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_POPULATION_BOMB) == 90);
        ASSUME(GetMoveEffect(MOVE_POPULATION_BOMB) == EFFECT_POPULATION_BOMB);
        ASSUME(MoveMakesContact(MOVE_POPULATION_BOMB));
        PLAYER(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); Item(ITEM_BLUNDER_POLICY); }
        OPPONENT(SPECIES_OINKOLOGNE) { Ability(ABILITY_LINGERING_AROMA); }
    } WHEN {
        TURN { MOVE(player, MOVE_POPULATION_BOMB, WITH_RNG(RNG_ACCURACY, FALSE)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
        ABILITY_POPUP(opponent, ABILITY_LINGERING_AROMA);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POPULATION_BOMB, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        }
    } THEN {
        EXPECT(player->item == ITEM_BLUNDER_POLICY);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->ability, ABILITY_LINGERING_AROMA);
    }
}

DOUBLE_BATTLE_TEST("Blunder Policy activates for Dragon Darts if one target misses for accuracy but the other target is hit twice")
{
    struct BattlePokemon *chosenTarget = NULL;
    struct BattlePokemon *finalTarget = NULL;
    enum Item itemLeft, itemRight;
    PARAMETRIZE { chosenTarget = opponentLeft;  finalTarget = opponentRight; itemLeft = ITEM_BRIGHT_POWDER;  itemRight = ITEM_NONE; }
    PARAMETRIZE { chosenTarget = opponentRight; finalTarget = opponentLeft;  itemLeft = ITEM_NONE;           itemRight = ITEM_BRIGHT_POWDER; }

    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_DRAGON_DARTS) == 100);
        ASSUME(GetMoveTarget(MOVE_DRAGON_DARTS) == TARGET_SMART);
        ASSUME(GetItemHoldEffect(ITEM_BRIGHT_POWDER) == HOLD_EFFECT_EVASION_UP);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BLUNDER_POLICY); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(itemLeft); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(itemRight); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_DARTS, target: chosenTarget, hit: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_DARTS, playerLeft);
        HP_BAR(finalTarget);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
    } THEN {
        EXPECT(playerLeft->item == ITEM_NONE);
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(chosenTarget->hp, chosenTarget->maxHP);
        EXPECT_LT(finalTarget->hp, finalTarget->maxHP);
    }
}
