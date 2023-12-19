#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gBattleMoves[MOVE_ROOST].effect == EFFECT_ROOST);
    ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] != TYPE_FLYING);
    ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[1] != TYPE_FLYING);
    // One attack of each type to verify typelessness
    ASSUME(gBattleMoves[MOVE_POUND].type == TYPE_NORMAL);
    ASSUME(gBattleMoves[MOVE_KARATE_CHOP].type == TYPE_FIGHTING);
    ASSUME(gBattleMoves[MOVE_GUST].type == TYPE_FLYING);
    ASSUME(gBattleMoves[MOVE_POISON_STING].type == TYPE_POISON);
    ASSUME(gBattleMoves[MOVE_EARTHQUAKE].type == TYPE_GROUND);
    ASSUME(gBattleMoves[MOVE_ROCK_THROW].type == TYPE_ROCK);
    ASSUME(gBattleMoves[MOVE_LEECH_LIFE].type == TYPE_BUG);
    ASSUME(gBattleMoves[MOVE_LICK].type == TYPE_GHOST);
    ASSUME(gBattleMoves[MOVE_STEEL_WING].type == TYPE_STEEL);
    ASSUME(gBattleMoves[MOVE_EMBER].type == TYPE_FIRE);
    ASSUME(gBattleMoves[MOVE_WATER_GUN].type == TYPE_WATER);
    ASSUME(gBattleMoves[MOVE_VINE_WHIP].type == TYPE_GRASS);
    ASSUME(gBattleMoves[MOVE_THUNDER_SHOCK].type == TYPE_ELECTRIC);
    ASSUME(gBattleMoves[MOVE_CONFUSION].type == TYPE_PSYCHIC);
    ASSUME(gBattleMoves[MOVE_ICE_BEAM].type == TYPE_ICE);
    ASSUME(gBattleMoves[MOVE_DRAGON_BREATH].type == TYPE_DRAGON);
    ASSUME(gBattleMoves[MOVE_BITE].type == TYPE_DARK);
    ASSUME(gBattleMoves[MOVE_DISARMING_VOICE].type == TYPE_FAIRY);
}

SINGLE_BATTLE_TEST("Roost fails when user is at full HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); }
    } SCENE {
        MESSAGE("Wobbuffet's HP is full!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Roost fails if the user is under the effects of Heal Block")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_BLOCK); MOVE(player, MOVE_ROOST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEAL_BLOCK, opponent);
        MESSAGE("Wobbuffet was prevented from healing!"); // Message when Heal Block is applied
        MESSAGE("Wobbuffet was prevented from healing!"); // Message when trying to heal under Heal Block
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Roost recovers 50% of the user's Max HP")
{
    u16 hp;

    KNOWN_FAILING; // All healing is currently rounded down
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(99); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        HP_BAR(player, captureHP: &hp);
    } THEN {
        //if (B_UPDATED_MOVE_DATA >= GEN_5)
            EXPECT(hp == 51); // Rounds up
        //else
        //    EXPECT(hp == 50); // Rounds down
    }
}

SINGLE_BATTLE_TEST("Roost suppresses the user's Flying-typing this turn, then restores it at the end of the turn")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SKARMORY].types[0] == TYPE_STEEL);
        ASSUME(gSpeciesInfo[SPECIES_SKARMORY].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_SKARMORY) { HP(50); MaxHP(100); Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        // Turn 1: EQ hits when Roosted
        MESSAGE("Skarmory used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Skarmory regained health!");
        MESSAGE("Foe Wobbuffet used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        MESSAGE("It's super effective!");
        // Turn 2: EQ has no effect because Roost expired
        MESSAGE("Foe Wobbuffet used Earthquake!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        MESSAGE("It doesn't affect Skarmory…");
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Roost, if used by a Flying/Flying type, treats the user as a Normal-type (or Typeless in Gen. 4) until the end of the turn")
{
    u32 damagingMove;
    PARAMETRIZE{ damagingMove = MOVE_POUND; }
    PARAMETRIZE{ damagingMove = MOVE_KARATE_CHOP; }
    PARAMETRIZE{ damagingMove = MOVE_GUST; }
    PARAMETRIZE{ damagingMove = MOVE_POISON_STING; }
    PARAMETRIZE{ damagingMove = MOVE_EARTHQUAKE; }
    PARAMETRIZE{ damagingMove = MOVE_ROCK_THROW; }
    PARAMETRIZE{ damagingMove = MOVE_LEECH_LIFE; }
    PARAMETRIZE{ damagingMove = MOVE_LICK; }
    PARAMETRIZE{ damagingMove = MOVE_STEEL_WING; }
    PARAMETRIZE{ damagingMove = MOVE_EMBER; }
    PARAMETRIZE{ damagingMove = MOVE_WATER_GUN; }
    PARAMETRIZE{ damagingMove = MOVE_VINE_WHIP; }
    PARAMETRIZE{ damagingMove = MOVE_THUNDER_SHOCK; }
    PARAMETRIZE{ damagingMove = MOVE_CONFUSION; }
    PARAMETRIZE{ damagingMove = MOVE_ICE_BEAM; }
    PARAMETRIZE{ damagingMove = MOVE_DRAGON_BREATH; }
    PARAMETRIZE{ damagingMove = MOVE_BITE; }
    PARAMETRIZE{ damagingMove = MOVE_DISARMING_VOICE; }

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_TORNADUS].types[0] == TYPE_FLYING);
        ASSUME(gSpeciesInfo[SPECIES_TORNADUS].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_TORNADUS) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, damagingMove); }
    } SCENE {
        MESSAGE("Tornadus used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Tornadus regained health!");

        if (B_ROOST_PURE_FLYING >= GEN_5) // >= Gen. 5, Pokemon becomes pure Normal-type
        {
            if (damagingMove == MOVE_KARATE_CHOP)
            {
                ANIMATION(ANIM_TYPE_MOVE, damagingMove, opponent);
                MESSAGE("It's super effective!");
            }
            else if (damagingMove == MOVE_LICK)
            {
                NOT ANIMATION(ANIM_TYPE_MOVE, damagingMove, opponent);
                MESSAGE("It doesn't affect Tornadus…");
            }
            else
            {
                ANIMATION(ANIM_TYPE_MOVE, damagingMove, opponent);
                NONE_OF {
                    MESSAGE("It's super effective!");
                    MESSAGE("It's not very effective…");
                    MESSAGE("It doesn't affect Tornadus…");
                }
            }
        }
        else // <= Gen. 4, Pokemon becomes Typeless
        {
            // Should not see any effectiveness messages
            NONE_OF {
                MESSAGE("It's super effective!");
                MESSAGE("It's not very effective…");
                MESSAGE("It doesn't affect Tornadus…");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Roost, if used by a Mystery/Flying type, treats the user as a Mystery/Mystery type until the end of the turn")
{
    u32 damagingMove;
    PARAMETRIZE{ damagingMove = MOVE_POUND; }
    PARAMETRIZE{ damagingMove = MOVE_KARATE_CHOP; }
    PARAMETRIZE{ damagingMove = MOVE_GUST; }
    PARAMETRIZE{ damagingMove = MOVE_POISON_STING; }
    PARAMETRIZE{ damagingMove = MOVE_EARTHQUAKE; }
    PARAMETRIZE{ damagingMove = MOVE_ROCK_THROW; }
    PARAMETRIZE{ damagingMove = MOVE_LEECH_LIFE; }
    PARAMETRIZE{ damagingMove = MOVE_LICK; }
    PARAMETRIZE{ damagingMove = MOVE_STEEL_WING; }
    PARAMETRIZE{ damagingMove = MOVE_EMBER; }
    PARAMETRIZE{ damagingMove = MOVE_WATER_GUN; }
    PARAMETRIZE{ damagingMove = MOVE_VINE_WHIP; }
    PARAMETRIZE{ damagingMove = MOVE_THUNDER_SHOCK; }
    PARAMETRIZE{ damagingMove = MOVE_CONFUSION; }
    PARAMETRIZE{ damagingMove = MOVE_ICE_BEAM; }
    PARAMETRIZE{ damagingMove = MOVE_DRAGON_BREATH; }
    PARAMETRIZE{ damagingMove = MOVE_BITE; }
    PARAMETRIZE{ damagingMove = MOVE_DISARMING_VOICE; }

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_MOLTRES].types[0] == TYPE_FIRE);
        ASSUME(gSpeciesInfo[SPECIES_MOLTRES].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_MOLTRES) { HP(300); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BURN_UP); }
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, damagingMove); }
    } SCENE {
        // Turn 1: Use Burn Up to change from Fire/Flying to Mystery/Flying
        MESSAGE("Moltres used Burn Up!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BURN_UP, player);
        MESSAGE("Moltres burned itself out!");
        // Turn 2: Use Roost to now be treated as a Mystery/Mystery type
        MESSAGE("Moltres used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Moltres regained health!");
        ANIMATION(ANIM_TYPE_MOVE, damagingMove, opponent);
        NONE_OF {
            MESSAGE("It's super effective!");
            MESSAGE("It's not very effective…");
            MESSAGE("It doesn't affect Moltres…");
        }
    }
}

// Tested in ORAS
DOUBLE_BATTLE_TEST("Roost suppresses the user's not-yet-aquired Flying-type this turn")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_KECLEON].types[0] != TYPE_FLYING);
        ASSUME(gSpeciesInfo[SPECIES_KECLEON].types[1] != TYPE_FLYING);
        PLAYER(SPECIES_KECLEON) { Speed(40); HP(150); Ability(ABILITY_COLOR_CHANGE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_PIDGEY) { Speed(30); }
        OPPONENT(SPECIES_SANDSHREW) { Speed(20); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_ROOST);
               MOVE(opponentLeft, MOVE_GUST, target: playerLeft);
               MOVE(opponentRight, MOVE_EARTHQUAKE, target: playerLeft); }
    } SCENE {
        MESSAGE("Kecleon used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, playerLeft);
        MESSAGE("Kecleon regained health!");
        MESSAGE("Foe Pidgey used Gust!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponentLeft);
        MESSAGE("Kecleon's Color Change made it the Flying type!");
        MESSAGE("Foe Sandshrew used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentRight);
        MESSAGE("Kecleon's Color Change made it the Ground type!");
    }
}

// Tested in ORAS
SINGLE_BATTLE_TEST("Roost prevents a Flying-type user from being protected by Delta Stream")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_RAYQUAZA].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_RAYQUAZA) { HP(1); Ability(ABILITY_DELTA_STREAM); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_ICE_BEAM); }
    } SCENE {
        MESSAGE("Rayquaza used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Rayquaza regained health!");
        MESSAGE("Foe Wobbuffet used Ice Beam!");
        NOT MESSAGE("The mysterious strong winds weakened the attack!");
    }
}

SINGLE_BATTLE_TEST("Roost does not undo other type-changing effects at the end of the turn")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SWELLOW].types[0] == TYPE_NORMAL);
        ASSUME(gSpeciesInfo[SPECIES_SWELLOW].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_SWELLOW) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_SOAK); }
        TURN { MOVE(opponent, MOVE_VINE_WHIP); }
    } SCENE {
        MESSAGE("Swellow used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Swellow regained health!");
        MESSAGE("Foe Wobbuffet used Soak!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, opponent);
        MESSAGE("Swellow transformed into the Water type!");
        MESSAGE("Foe Wobbuffet used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, opponent);
        MESSAGE("It's super effective!");
    }
}

// https://www.smogon.com/forums/threads/sword-shield-battle-mechanics-research.3655528/page-64#post-9244179
SINGLE_BATTLE_TEST("Roost's effect is lifted after Grassy Terrain's healing")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SWELLOW].types[0] == TYPE_NORMAL);
        ASSUME(gSpeciesInfo[SPECIES_SWELLOW].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_SWELLOW) { HP(1); Ability(ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); }
    } SCENE {
        MESSAGE("Swellow used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Swellow regained health!");
        MESSAGE("Swellow is healed by the grassy terrain!");
        HP_BAR(player);
    }
}

// Tested in USUM
SINGLE_BATTLE_TEST("Roost's suppression prevents Reflect Type from copying any Flying typing")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SWELLOW].types[0] == TYPE_NORMAL);
        ASSUME(gSpeciesInfo[SPECIES_SWELLOW].types[1] == TYPE_FLYING);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[0] == TYPE_PSYCHIC);
        ASSUME(gSpeciesInfo[SPECIES_WOBBUFFET].types[1] == TYPE_PSYCHIC);
        PLAYER(SPECIES_SWELLOW) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_REFLECT_TYPE); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); MOVE(opponent, MOVE_REFLECT_TYPE); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
    } SCENE {
        // Turn 1: Reflect Type on Roosted Normal/Flying
        MESSAGE("Swellow used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Swellow regained health!");
        MESSAGE("Foe Wobbuffet used Reflect Type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT_TYPE, opponent);
        MESSAGE("Foe Wobbuffet's type changed to match the Swellow's!");
        // Turn 2: EQ hits, Reflect Type on non-Roosted Normal/Flying
        MESSAGE("Swellow used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
        MESSAGE("Foe Wobbuffet used Reflect Type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT_TYPE, opponent);
        MESSAGE("Foe Wobbuffet's type changed to match the Swellow's!");
        // Turn 3: EQ has no effect
        MESSAGE("Swellow used Earthquake!");
        MESSAGE("It doesn't affect Foe Wobbuffet…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Roost does not suppress the ungrounded effect of Levitate")
{
    GIVEN {
        PLAYER(SPECIES_FLYGON) { HP(1); Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Flygon used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Flygon regained health!");
        MESSAGE("Foe Wobbuffet used Earthquake!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Roost does not suppress the ungrounded effect of Air Balloon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Wobbuffet used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Wobbuffet regained health!");
        MESSAGE("Foe Wobbuffet used Earthquake!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Roost does not suppress the ungrounded effect of Magnet Rise")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGNET_RISE); }
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        // Turn 1: Magnet Rise
        MESSAGE("Wobbuffet used Magnet Rise!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGNET_RISE, player);
        MESSAGE("Wobbuffet levitated on electromagnetism!");
        // Turn 2
        MESSAGE("Wobbuffet used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Wobbuffet regained health!");
        MESSAGE("Foe Wobbuffet used Earthquake!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Roost does not suppress the ungrounded effect of Telekinesis")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TELEKINESIS); }
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        // Turn 1: Telekinesis
        MESSAGE("Foe Wobbuffet used Telekinesis!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TELEKINESIS, opponent);
        MESSAGE("Wobbuffet was hurled into the air!");
        // Turn 2
        MESSAGE("Wobbuffet used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Wobbuffet regained health!");
        MESSAGE("Foe Wobbuffet used Earthquake!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
            HP_BAR(player);
        }
    }
}

// Tested in ORAS
// Transform does not copy the Roost "status" either.
// Probably better as a Transform test.
TO_DO_BATTLE_TEST("Roost's suppression does not prevent others who are Transforming into the user from copying its Flying-type");
