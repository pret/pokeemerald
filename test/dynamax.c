#include "global.h"
#include "test_battle.h"

// TODO:
// Max Moves cannot miss.
// Max Guard protects against Transform, Block (not Mean Look), Flower Shield, Gear Up, and so on (see Bulba).
// Max Moves penetrate Protect, but not Max Guard.
// Feint damages through Max Guard, but doesn't break it.
// You can ignore the effect of Encore / Disable with Max Moves.
// You can Encore the base move of a Max Move after Dynamax, but not Disable or Instruct.
// Imprison doesn't stop Max Moves.
// Copycat copies the base move of a Max Move (even Trick Room!).
// Assault Vest prevents the use of Max Guard; so does Taunt.
// Max Moves change type as you'd expect with Normalize, Weather Ball, etc.
// Dynamax Cannon and such do double damage on Dynamaxed opponents.

// DYNAMAX FEATURES
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamax increases HP and max HP by 1.5x")
{
    GIVEN { // TODO: Dynamax level
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(80); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } FINALLY {
        EXPECT_EQ(player->hp, 120);
        EXPECT_EQ(player->maxHP, 150);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamax expires after three turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(80); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); } // 1st max move
        TURN { MOVE(player, MOVE_TACKLE); } // 2nd max move
        TURN { MOVE(player, MOVE_TACKLE); } // 3rd max move
    } SCENE {
        int i;
        for (i = 0; i < DYNAMAX_TURNS; ++i) {
            MESSAGE("Wobbuffet used Max Strike!");
            MESSAGE("Foe Wobbuffet used Celebrate!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } FINALLY {
        EXPECT_EQ(player->hp, 80);
        EXPECT_EQ(player->maxHP, 100);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot be flinched")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FAKE_OUT].effect == EFFECT_FAKE_OUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Fake Out!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot be hit by weight-based moves")
{
    // Message is "Steelix shook its head. It seems like it can't use this move..."?
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_HEAVY_SLAM].effect == EFFECT_HEAT_CRASH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAVY_SLAM); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Heavy Slam!");
        MESSAGE("Wobbuffet is unaffected!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot be hit by OHKO moves")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FISSURE].effect == EFFECT_OHKO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FISSURE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Fissure!");
        MESSAGE("Wobbuffet is unaffected!");
        NONE_OF { HP_BAR(player); }
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

// can't be used at all in Raid, see "Documenting Dynamax"
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by Destiny Bond")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DESTINY_BOND); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Destiny Bond!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet fainted!");
        NONE_OF { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are affected by Grudge")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRUDGE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Grudge!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Wobbuffet's Tackle lost all its PP due to the GRUDGE!");
        MESSAGE("Foe Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by phazing moves, but still take damage")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_DRAGON_TAIL].effect == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN {}
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Dragon Tail!");
        MESSAGE("The move was blocked by the power of Dynamax!");
        HP_BAR(player);
        MESSAGE("Wobbuffet used Max Guard!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by Red Card")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("Foe Wobbuffet held up its Red Card against Wobbuffet!");
        MESSAGE("The move was blocked by the power of Dynamax!");
    } FINALLY {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can be switched out by Eject Button")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Button!");
    } FINALLY {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot have their ability swapped with another Pokemon")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_RUNERIGUS) { Ability(ABILITY_WANDERING_SPIRIT); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Skill Swap!");
        MESSAGE("But it failed!");
    } FINALLY {
        EXPECT_EQ(player->ability, ABILITY_SHADOW_TAG);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can have their ability changed")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_SIMPLE_BEAM); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Simple Beam!");
        MESSAGE("Wobbuffet acquired Simple!");
    } FINALLY {
        EXPECT_EQ(player->ability, ABILITY_SIMPLE);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Encore")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_ENCORE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Encore!");
        MESSAGE("But it failed!");
    }
}

// TODO: Test Cursed Body, too.
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon's Max Moves cannot be disabled")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_DISABLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Disable!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can have base moves disabled on their first turn")
{
    KNOWN_FAILING;
    GIVEN {
        ASSUME(B_DISABLE_TURNS >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DISABLE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN {}
        TURN {}
        TURN {} // TODO: Tackle should still be disabled.
    } SCENE {
        MESSAGE("Foe Wobbuffet used Disable!");
        MESSAGE("Wobbuffet's Tackle was disabled!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Torment")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_TORMENT); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Torment!");
        MESSAGE("But it failed!");
    }
}

// This is true for all item-removing moves.
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not immune to Knock Off")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_KNOCK_OFF); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Knock Off!");
        MESSAGE("Wobbuffet's Potion was knocked off!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon lose their substitutes")
{
    KNOWN_FAILING;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Substitute!");
        MESSAGE("Wobbuffet set up a substitute!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        HP_BAR(player);
    }
}

// ============= MAX MOVE EFFECTS ===================
SINGLE_BATTLE_TEST("(DYNAMAX) Max Strike lowers single opponent's speed")
{
    GIVEN {
        // Fails?: ASSUME(GetMaxMove(B_POSITION_PLAYER_LEFT, MOVE_TACKLE) == MOVE_MAX_STRIKE);
        ASSUME(gBattleMoves[MOVE_MAX_STRIKE].argument == MAX_EFFECT_LOWER_SPEED);
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        // turn 1
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) Max Strike lowers both opponents' speed")
{
    GIVEN {
        // Fails? ASSUME(GetMaxMove(B_POSITION_PLAYER_LEFT, MOVE_TACKLE) == MOVE_MAX_STRIKE);
        ASSUME(gBattleMoves[MOVE_MAX_STRIKE].argument == MAX_EFFECT_LOWER_SPEED);
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(79); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(99); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft, dynamax: TRUE); \
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); \
               MOVE(opponentRight, MOVE_TACKLE, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); \
               MOVE(opponentRight, MOVE_TACKLE, target: playerLeft); }
    } SCENE {
        // turn 1
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Wobbuffet's speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Wobbuffet's speed fell!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Tackle!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Flare sets up sunlight")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_FLARE].argument == MAX_EFFECT_SUN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Flare!");
        MESSAGE("The sunlight got bright!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SUN_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Geyser sets up heavy rain")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_GEYSER].argument == MAX_EFFECT_RAIN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Geyser!");
        MESSAGE("It started to rain!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Hailstorm sets up hail")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_HAILSTORM].argument == MAX_EFFECT_HAIL);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWDER_SNOW, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Hailstorm!");
        MESSAGE("It started to hail!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HAIL_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Rockfall sets up a sandstorm")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_ROCKFALL].argument == MAX_EFFECT_SANDSTORM);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Rockfall!");
        MESSAGE("A sandstorm brewed!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SANDSTORM_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Overgrowth sets up Grassy Terrain")
{
    KNOWN_FAILING; // Grassy terrain bugged #2820
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_OVERGROWTH].argument == MAX_EFFECT_GRASSY_TERRAIN);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(256); HP(128); };
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(256); HP(128); };
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_VINE_WHIP); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Overgrowth!");
        MESSAGE("Foe Wobbuffet cannot use Celebrate!");
        HP_BAR(player, damage: -256/16);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Mindstorm sets up Psychic Terrain")
{
    // TODO: BG doesn't seem to load?
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_MINDSTORM].argument == MAX_EFFECT_PSYCHIC_TERRAIN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_PSYCHIC, dynamax: TRUE); }
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used ExtremeSpeed!");
        MESSAGE("Wobbuffet used Max Mindstorm!");
        MESSAGE("Foe Wobbuffet cannot use ExtremeSpeed!");
        MESSAGE("Wobbuffet used Max Mindstorm!");
    }
}
