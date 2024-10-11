#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Anticipation causes notifies if an opponent has a super-effective move");
TO_DO_BATTLE_TEST("Anticipation causes notifies if an opponent has a One-hit KO move");
TO_DO_BATTLE_TEST("Anticipation causes notifies if an opponent has a Self-Destruct or Explosion (Gen4)");
TO_DO_BATTLE_TEST("Anticipation treats Self-Destruct and Explosion like all other Normal types (Gen5+)");

TO_DO_BATTLE_TEST("Anticipation considers Scrappy and Normalize into their effectiveness (Gen4)");
TO_DO_BATTLE_TEST("Anticipation doesn't consider Scrappy and Normalize into their effectiveness (Gen5+)");
TO_DO_BATTLE_TEST("Anticipation considers Gravity into their effectiveness (Gen4)");
TO_DO_BATTLE_TEST("Anticipation doesn't consider Gravity into their effectiveness (Gen5+)");
TO_DO_BATTLE_TEST("Anticipation doesn't trigger from Counter, Metal Burst or Mirror Coat (Gen4)");
TO_DO_BATTLE_TEST("Anticipation counts Counter, Metal Burst or Mirror Coat as attacking moves of their types (Gen5+)");
TO_DO_BATTLE_TEST("Anticipation considers Synchronoise as an ordinary Psychic-type move");
TO_DO_BATTLE_TEST("Anticipation considers Freeze-Dry as an ordinary Ice-type move");
TO_DO_BATTLE_TEST("Anticipation considers Flying Press as an ordinary Fighting-type move");
TO_DO_BATTLE_TEST("Anticipation considers Aura Wheel as an ordinary Electric-type move");
TO_DO_BATTLE_TEST("Anticipation considers Inverse Battle types"); //Check with Normal-type moves
TO_DO_BATTLE_TEST("Anticipation treats dynamic move types as their base type (Normal)"); // Judgment, Weather Ball, Natural Gift, Techno Blast, Revelation Dance, Multi Attack
TO_DO_BATTLE_TEST("Anticipation treats Hidden Power as Normal Type (Gen4-5)");
TO_DO_BATTLE_TEST("Anticipation treats Hidden Power as its dynamic type (Gen6+)");
TO_DO_BATTLE_TEST("Anticipation does not consider Strong Winds on type matchups");
TO_DO_BATTLE_TEST("Anticipation does not consider ate-abilities");
