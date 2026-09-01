#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ROOST) == EFFECT_ROOST);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) != TYPE_FLYING);
    ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) != TYPE_FLYING);
    // One attack of each type to verify typelessness
    ASSUME(GetMoveType(MOVE_POUND) == TYPE_NORMAL);
    ASSUME(GetMoveType(MOVE_KARATE_CHOP) == TYPE_FIGHTING);
    ASSUME(GetMoveType(MOVE_GUST) == TYPE_FLYING);
    ASSUME(GetMoveType(MOVE_POISON_STING) == TYPE_POISON);
    ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
    ASSUME(GetMoveType(MOVE_ROCK_THROW) == TYPE_ROCK);
    ASSUME(GetMoveType(MOVE_LEECH_LIFE) == TYPE_BUG);
    ASSUME(GetMoveType(MOVE_LICK) == TYPE_GHOST);
    ASSUME(GetMoveType(MOVE_STEEL_WING) == TYPE_STEEL);
    ASSUME(GetMoveType(MOVE_EMBER) == TYPE_FIRE);
    ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
    ASSUME(GetMoveType(MOVE_VINE_WHIP) == TYPE_GRASS);
    ASSUME(GetMoveType(MOVE_THUNDER_SHOCK) == TYPE_ELECTRIC);
    ASSUME(GetMoveType(MOVE_CONFUSION) == TYPE_PSYCHIC);
    ASSUME(GetMoveType(MOVE_ICE_BEAM) == TYPE_ICE);
    ASSUME(GetMoveType(MOVE_DRAGON_BREATH) == TYPE_DRAGON);
    ASSUME(GetMoveType(MOVE_BITE) == TYPE_DARK);
    ASSUME(GetMoveType(MOVE_DISARMING_VOICE) == TYPE_FAIRY);
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
        ASSUME(GetSpeciesType(SPECIES_SKARMORY, 0) == TYPE_STEEL);
        ASSUME(GetSpeciesType(SPECIES_SKARMORY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_SKARMORY) { HP(50); MaxHP(100); Ability(ABILITY_STURDY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_EARTHQUAKE); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        // Turn 1: EQ hits when Roosted
        MESSAGE("Skarmory used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Skarmory's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        MESSAGE("It's super effective!");
        // Turn 2: EQ has no effect because Roost expired
        MESSAGE("The opposing Wobbuffet used Earthquake!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        MESSAGE("It doesn't affect Skarmory…");
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Roost, if used by a Flying/Flying type, treats the user as a Normal-type (or Typeless in Gen. 4) until the end of the turn")
{
    u32 damagingMove;
    PARAMETRIZE { damagingMove = MOVE_POUND; }
    PARAMETRIZE { damagingMove = MOVE_KARATE_CHOP; }
    PARAMETRIZE { damagingMove = MOVE_GUST; }
    PARAMETRIZE { damagingMove = MOVE_POISON_STING; }
    PARAMETRIZE { damagingMove = MOVE_EARTHQUAKE; }
    PARAMETRIZE { damagingMove = MOVE_ROCK_THROW; }
    PARAMETRIZE { damagingMove = MOVE_LEECH_LIFE; }
    PARAMETRIZE { damagingMove = MOVE_LICK; }
    PARAMETRIZE { damagingMove = MOVE_STEEL_WING; }
    PARAMETRIZE { damagingMove = MOVE_EMBER; }
    PARAMETRIZE { damagingMove = MOVE_WATER_GUN; }
    PARAMETRIZE { damagingMove = MOVE_VINE_WHIP; }
    PARAMETRIZE { damagingMove = MOVE_THUNDER_SHOCK; }
    PARAMETRIZE { damagingMove = MOVE_CONFUSION; }
    PARAMETRIZE { damagingMove = MOVE_ICE_BEAM; }
    PARAMETRIZE { damagingMove = MOVE_DRAGON_BREATH; }
    PARAMETRIZE { damagingMove = MOVE_BITE; }
    PARAMETRIZE { damagingMove = MOVE_DISARMING_VOICE; }

    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 0) == TYPE_FLYING);
        ASSUME(GetSpeciesType(SPECIES_TORNADUS, 1) == TYPE_FLYING);
        PLAYER(SPECIES_TORNADUS) { HP(50); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, damagingMove); }
    } SCENE {
        MESSAGE("Tornadus used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Tornadus's HP was restored.");

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
    PARAMETRIZE { damagingMove = MOVE_POUND; }
    PARAMETRIZE { damagingMove = MOVE_KARATE_CHOP; }
    PARAMETRIZE { damagingMove = MOVE_GUST; }
    PARAMETRIZE { damagingMove = MOVE_POISON_STING; }
    PARAMETRIZE { damagingMove = MOVE_EARTHQUAKE; }
    PARAMETRIZE { damagingMove = MOVE_ROCK_THROW; }
    PARAMETRIZE { damagingMove = MOVE_LEECH_LIFE; }
    PARAMETRIZE { damagingMove = MOVE_LICK; }
    PARAMETRIZE { damagingMove = MOVE_STEEL_WING; }
    PARAMETRIZE { damagingMove = MOVE_EMBER; }
    PARAMETRIZE { damagingMove = MOVE_WATER_GUN; }
    PARAMETRIZE { damagingMove = MOVE_VINE_WHIP; }
    PARAMETRIZE { damagingMove = MOVE_THUNDER_SHOCK; }
    PARAMETRIZE { damagingMove = MOVE_CONFUSION; }
    PARAMETRIZE { damagingMove = MOVE_ICE_BEAM; }
    PARAMETRIZE { damagingMove = MOVE_DRAGON_BREATH; }
    PARAMETRIZE { damagingMove = MOVE_BITE; }
    PARAMETRIZE { damagingMove = MOVE_DISARMING_VOICE; }

    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_MOLTRES, 0) == TYPE_FIRE);
        ASSUME(GetSpeciesType(SPECIES_MOLTRES, 1) == TYPE_FLYING);
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
        MESSAGE("Moltres's HP was restored.");
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
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_FLYING);
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_FLYING);
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
        MESSAGE("Kecleon's HP was restored.");
        MESSAGE("The opposing Pidgey used Gust!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponentLeft);
        MESSAGE("Kecleon's type changed to Flying!");
        MESSAGE("The opposing Sandshrew used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponentRight);
        MESSAGE("Kecleon's type changed to Ground!");
    }
}

// Tested in ORAS
SINGLE_BATTLE_TEST("Roost prevents a Flying-type user from being protected by Delta Stream")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_RAYQUAZA_MEGA, 1) == TYPE_FLYING);
        PLAYER(SPECIES_RAYQUAZA) { HP(1); Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE, MOVE_ROOST); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_ICE_BEAM); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_DELTA_STREAM);
        MESSAGE("Rayquaza used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Rayquaza's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Ice Beam!");
        NOT MESSAGE("The mysterious strong winds weakened the attack!");
    }
}

SINGLE_BATTLE_TEST("Roost does not undo other type-changing effects at the end of the turn")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 1) == TYPE_FLYING);
        PLAYER(SPECIES_SWELLOW) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); MOVE(opponent, MOVE_SOAK); }
        TURN { MOVE(opponent, MOVE_VINE_WHIP); }
    } SCENE {
        MESSAGE("Swellow used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Swellow's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Soak!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOAK, opponent);
        MESSAGE("Swellow transformed into the Water type!");
        MESSAGE("The opposing Wobbuffet used Vine Whip!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_VINE_WHIP, opponent);
        MESSAGE("It's super effective!");
    }
}

// https://www.smogon.com/forums/threads/sword-shield-battle-mechanics-research.3655528/page-64#post-9244179
SINGLE_BATTLE_TEST("Roost's effect is lifted after Grassy Terrain's healing")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 1) == TYPE_FLYING);
        PLAYER(SPECIES_SWELLOW) { HP(1); Ability(ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROOST); }
    } SCENE {
        MESSAGE("Swellow used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Swellow's HP was restored.");
        MESSAGE("Swellow is healed by the grassy terrain!");
        HP_BAR(player);
    }
}

// Tested in USUM
SINGLE_BATTLE_TEST("Roost's suppression prevents Reflect Type from copying any Flying typing")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_SWELLOW, 1) == TYPE_FLYING);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 0) == TYPE_PSYCHIC);
        ASSUME(GetSpeciesType(SPECIES_WOBBUFFET, 1) == TYPE_PSYCHIC);
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
        MESSAGE("Swellow's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Reflect Type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT_TYPE, opponent);
        MESSAGE("The opposing Wobbuffet became the same type as Swellow!");
        // Turn 2: EQ hits, Reflect Type on non-Roosted Normal/Flying
        MESSAGE("Swellow used Earthquake!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet used Reflect Type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT_TYPE, opponent);
        MESSAGE("The opposing Wobbuffet became the same type as Swellow!");
        // Turn 3: EQ has no effect
        MESSAGE("Swellow used Earthquake!");
        MESSAGE("It doesn't affect the opposing Wobbuffet…");
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
        MESSAGE("Flygon's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Earthquake!");
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
        MESSAGE("Wobbuffet's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Earthquake!");
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
        MESSAGE("Wobbuffet levitated with electromagnetism!");
        // Turn 2
        MESSAGE("Wobbuffet used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Wobbuffet's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Earthquake!");
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
        MESSAGE("The opposing Wobbuffet used Telekinesis!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TELEKINESIS, opponent);
        MESSAGE("Wobbuffet was hurled into the air!");
        // Turn 2
        MESSAGE("Wobbuffet used Roost!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROOST, player);
        MESSAGE("Wobbuffet's HP was restored.");
        MESSAGE("The opposing Wobbuffet used Earthquake!");
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
