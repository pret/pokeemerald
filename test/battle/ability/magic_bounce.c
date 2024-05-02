#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Magic Bounce bounces back status moves")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        MESSAGE("Wynaut's Toxic was bounced back by Foe Espeon's Magic Bounce!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
        STATUS_ICON(player, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Magic Bounce bounces back powder moves")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_STUN_SPORE].powderMove);
        ASSUME(gMovesInfo[MOVE_STUN_SPORE].effect == EFFECT_PARALYZE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        MESSAGE("Wynaut's Stun Spore was bounced back by Foe Espeon's Magic Bounce!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, opponent);
        STATUS_ICON(player, paralysis: TRUE);
    }
}

SINGLE_BATTLE_TEST("Magic Bounce cannot bounce back powder moves against Grass Types")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_STUN_SPORE].powderMove);
        ASSUME(gSpeciesInfo[SPECIES_ODDISH].types[0] == TYPE_GRASS);
        PLAYER(SPECIES_ODDISH);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUN_SPORE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, player);
        MESSAGE("Oddish's Stun Spore was bounced back by Foe Espeon's Magic Bounce!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STUN_SPORE, opponent);
        MESSAGE("It doesn't affect Oddish…");
        NOT STATUS_ICON(player, paralysis: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Magic Bounce bounces back moves hitting both foes at two foes")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_LEER].effect == EFFECT_DEFENSE_DOWN);
        ASSUME(gMovesInfo[MOVE_LEER].target == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_ABRA);
        PLAYER(SPECIES_KADABRA);
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LEER); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, playerLeft);
        MESSAGE("Abra's Leer was bounced back by Foe Espeon's Magic Bounce!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEER, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Abra's Defense fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Kadabra's Defense fell!");
        // Also check if second original target gets hit by Leer as this was once bugged
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Wynaut's Defense fell!");
    }
}

DOUBLE_BATTLE_TEST("Magic Bounce bounces back moves hitting foes field")
{
    u32 battlerOne, battlerTwo, abilityBattlerOne, abilityBattlerTwo;

    PARAMETRIZE { battlerOne = SPECIES_NATU; abilityBattlerOne = ABILITY_MAGIC_BOUNCE;
                  battlerTwo = SPECIES_ESPEON; abilityBattlerTwo = ABILITY_SYNCHRONIZE; }
    PARAMETRIZE { battlerOne = SPECIES_NATU; abilityBattlerOne = ABILITY_KEEN_EYE;
                  battlerTwo = SPECIES_ESPEON; abilityBattlerTwo = ABILITY_MAGIC_BOUNCE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_STEALTH_ROCK].target == MOVE_TARGET_OPPONENTS_FIELD);
        PLAYER(SPECIES_ABRA);
        PLAYER(SPECIES_KADABRA);
        OPPONENT(battlerOne) { Ability(abilityBattlerOne); }
        OPPONENT(battlerTwo) { Ability(abilityBattlerTwo); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STEALTH_ROCK); }
    } SCENE {
        if (abilityBattlerOne == ABILITY_MAGIC_BOUNCE)
            ABILITY_POPUP(opponentLeft, ABILITY_MAGIC_BOUNCE);
        else
            ABILITY_POPUP(opponentRight, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, playerLeft);
        if (abilityBattlerOne == ABILITY_MAGIC_BOUNCE) {
            MESSAGE("Abra's Stealth Rock was bounced back by Foe Natu's Magic Bounce!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentLeft);
        } else {
            MESSAGE("Abra's Stealth Rock was bounced back by Foe Espeon's Magic Bounce!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentRight);
        }
    }
}

SINGLE_BATTLE_TEST("Magic Bounce bounced back status moves can not be bounced back by Magic Bounce")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOXIC].effect == EFFECT_TOXIC);
        PLAYER(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
        OPPONENT(SPECIES_ESPEON) { Ability(ABILITY_MAGIC_BOUNCE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_MAGIC_BOUNCE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        MESSAGE("Espeon's Toxic was bounced back by Foe Espeon's Magic Bounce!");
        NOT ABILITY_POPUP(player, ABILITY_MAGIC_BOUNCE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, opponent);
        STATUS_ICON(player, badPoison: TRUE);
    }
}
