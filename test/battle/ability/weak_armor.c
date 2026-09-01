#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_GUST) == DAMAGE_CATEGORY_SPECIAL);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Weak Armor lowers Defense by 1 and boosts Speed by 1 (Gen5-6) or 2 (Gen7+) when hit by a physical attack")
{
    enum Move move;
    u32 gen;

    PARAMETRIZE { move = MOVE_SCRATCH; gen = GEN_6; }
    PARAMETRIZE { move = MOVE_SCRATCH; gen = GEN_7; }
    PARAMETRIZE { move = MOVE_GUST;    gen = GEN_7; }

    GIVEN {
        WITH_CONFIG(B_WEAK_ARMOR_SPEED, gen);
        PLAYER(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        HP_BAR(player);
        if (move == MOVE_SCRATCH) {
            ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        } else {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            }
        }
    } THEN {
        if (move == MOVE_SCRATCH) {
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + (gen == GEN_7 ? 2 : 1));
        } else {
            EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
            EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        }
    }
}

// Oddly specific, but it was a bug at one point.
SINGLE_BATTLE_TEST("Weak Armor does not trigger when brought in by Dragon Tail and taking Stealth Rock damage")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STEALTH_ROCK) == EFFECT_STEALTH_ROCK);
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, opponent);
        HP_BAR(player);
        MESSAGE("Slugma was dragged out!");
        HP_BAR(player);
        MESSAGE("Pointed stones dug into Slugma!");
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Slugma's Defense fell!");
            MESSAGE("Slugma's Speed rose sharply!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Weak Armor still boosts Speed if Defense can't go any lower")
{
    u16 gen;

    PARAMETRIZE { gen = GEN_6; }
    PARAMETRIZE { gen = GEN_7; }
    GIVEN {
        WITH_CONFIG(B_WEAK_ARMOR_SPEED, gen);
        PLAYER(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCREECH); }
        TURN { MOVE(opponent, MOVE_SCREECH); }
        TURN { MOVE(opponent, MOVE_SCREECH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Slugma's Defense fell!");
        }
        MESSAGE("Slugma's Defense won't go any lower!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        if (gen == GEN_6)
            MESSAGE("Slugma's Speed rose!");
        else
            MESSAGE("Slugma's Speed rose sharply!");

    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], MIN_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + (gen == GEN_7 ? 2 : 1));
    }
}

SINGLE_BATTLE_TEST("Weak Armor still lowers Defense if Speed can't go any higher")
{
    GIVEN {
        PLAYER(SPECIES_SLUGMA) { Ability(ABILITY_WEAK_ARMOR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Slugma's Defense fell!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Slugma's Speed rose sharply!");
        }
        MESSAGE("Slugma's Speed won't go any higher!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Weak Armor doesn't interrupt multi hit moves if Defense can't go any lower")
{
    u32 j;
    GIVEN {
        WITH_CONFIG(B_WEAK_ARMOR_SPEED, GEN_7);
        PLAYER(SPECIES_MAGCARGO) { Ability(ABILITY_WEAK_ARMOR); Defense(999); }
        OPPONENT(SPECIES_CLOYSTER) { Ability(ABILITY_SKILL_LINK); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCREECH); }
        TURN { MOVE(opponent, MOVE_SCREECH); }
        TURN { MOVE(opponent, MOVE_FURY_SWIPES); }
    } SCENE {
        for (j = 0; j < 2; j++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
            ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
            MESSAGE("Magcargo's Defense fell!");
            MESSAGE("Magcargo's Speed rose sharply!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        MESSAGE("Magcargo's Defense won't go any lower!");
        MESSAGE("Magcargo's Speed rose sharply!");
        for (j = 0; j < 2; j++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
            // Ability doesn't activate if neither stat can be changed.
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
                MESSAGE("Magcargo's Defense won't go any lower!");
                MESSAGE("Magcargo's Speed won't go any higher!");
            }
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], MIN_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Weak Armor doesn't interrupt multi hit moves if Speed can't go any higher")
{
    u32 j;
    GIVEN {
        WITH_CONFIG(B_WEAK_ARMOR_SPEED, GEN_7);
        PLAYER(SPECIES_MAGCARGO) { Ability(ABILITY_WEAK_ARMOR); Defense(999); }
        OPPONENT(SPECIES_CLOYSTER) { Ability(ABILITY_SKILL_LINK); }
    } WHEN {
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(player, MOVE_AGILITY); }
        TURN { MOVE(opponent, MOVE_FURY_SWIPES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
        ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
        MESSAGE("Magcargo's Defense fell!");
        MESSAGE("Magcargo's Speed rose sharply!");
        for (j = 0; j < 4; j++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, opponent);
            ABILITY_POPUP(player, ABILITY_WEAK_ARMOR);
            MESSAGE("Magcargo's Defense fell!");
            MESSAGE("Magcargo's Speed won't go any higher!");
        }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 5);
        EXPECT_EQ(player->statStages[STAT_SPEED], MAX_STAT_STAGE);
    }
}
