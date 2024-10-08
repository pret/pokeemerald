#include "global.h"
#include "test/battle.h"

AI_SINGLE_BATTLE_TEST("AI gets baited by Protect Switch tactics") // This behavior is to be fixed.
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_STUNFISK);
        PLAYER(SPECIES_PELIPPER);
        OPPONENT(SPECIES_DARKRAI) { Moves(MOVE_TACKLE, MOVE_PECK, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_SCIZOR) { Moves(MOVE_HYPER_BEAM, MOVE_FACADE, MOVE_GIGA_IMPACT, MOVE_EXTREME_SPEED); }
    } WHEN {

        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); } // E-quake
        TURN { SWITCH(player, 1);           EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); } // E-quake
        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); } // T-Bolt
        TURN { SWITCH(player, 0);           EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); } // T-Bolt
        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_EARTHQUAKE); } // E-quake
        TURN { SWITCH(player, 1);           EXPECT_MOVE(opponent, MOVE_EARTHQUAKE);} // E-quake
        TURN { MOVE(player, MOVE_PROTECT);  EXPECT_MOVE(opponent, MOVE_THUNDERBOLT); } // T-Bolt
    }
}

// General switching behaviour
AI_SINGLE_BATTLE_TEST("AI switches if Perish Song is about to kill")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) {Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_CROBAT) {Moves(MOVE_TACKLE); }
    } WHEN {
            TURN { MOVE(player, MOVE_PERISH_SONG); }
            TURN { ; }
            TURN { ; }
            TURN { EXPECT_SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("{PKMN} TRAINER LEAF sent out Crobat!");
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not try to switch for the same pokemon for 2 spots in a double battle")
{
    u32 flags;

    PARAMETRIZE {flags = AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE {flags = 0; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | flags);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage player.
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_HAUNTER) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentLeft, 3); };
    } SCENE {
        MESSAGE("{PKMN} TRAINER LEAF withdrew Gengar!");
        MESSAGE("{PKMN} TRAINER LEAF sent out Raticate!");
        NONE_OF {
            MESSAGE("{PKMN} TRAINER LEAF withdrew Haunter!");
            MESSAGE("{PKMN} TRAINER LEAF sent out Raticate!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: U-Turn will send out Ace Mon if it's the only one remaining")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_U_TURN].effect == EFFECT_HIT_ESCAPE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_ACE_POKEMON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_U_TURN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_U_TURN); EXPECT_SEND_OUT(opponent, 1); }
    }
}

// General AI_FLAG_SMART_MON_CHOICES behaviour
AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Number of hits to KO calculation checks whether incoming damage is less than recurring healing to avoid an infinite loop")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_VENUSAUR) { Level(30); Moves(MOVE_TACKLE); }
        // Opponent party courtesy of Skolgrahd, who triggered the bug in the first place
        OPPONENT(SPECIES_PIKACHU) { Level(100); Moves(MOVE_ZIPPY_ZAP, MOVE_EXTREME_SPEED, MOVE_IRON_TAIL, MOVE_KNOCK_OFF); }
        OPPONENT(SPECIES_NINETALES_ALOLAN) { Level(100); Moves(MOVE_AURORA_VEIL, MOVE_BLIZZARD, MOVE_MOONBLAST, MOVE_DISABLE); }
        OPPONENT(SPECIES_WEAVILE) { Level(100); Moves(MOVE_NIGHT_SLASH, MOVE_TRIPLE_AXEL, MOVE_ICE_SHARD, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_DITTO) { Level(100); Moves(MOVE_TRANSFORM); }
        OPPONENT(SPECIES_TYPHLOSION) { Level(100); Moves(MOVE_ERUPTION, MOVE_HEAT_WAVE, MOVE_FOCUS_BLAST, MOVE_EXTRASENSORY); }
        OPPONENT(SPECIES_UMBREON) { Level(100); Item(ITEM_LEFTOVERS); Moves(MOVE_FOUL_PLAY, MOVE_SNARL, MOVE_HELPING_HAND, MOVE_THUNDER_WAVE); }
    } WHEN {
            TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVES(opponent, MOVE_ZIPPY_ZAP, MOVE_EXTREME_SPEED, MOVE_IRON_TAIL, MOVE_KNOCK_OFF); }
    } SCENE {
        MESSAGE("Venusaur fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Number of hits to KO calculation checks whether incoming damage is zero to avoid an infinite loop")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LEFTOVERS].holdEffect == HOLD_EFFECT_LEFTOVERS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_BULBASAUR) { Level(5); Moves(MOVE_SWORDS_DANCE, MOVE_WHIRLWIND, MOVE_SAND_ATTACK, MOVE_TAIL_WHIP); }
        // Scenario courtesy of Duke, who triggered the bug in the first place
        OPPONENT(SPECIES_GEODUDE) { Level(100); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_GEODUDE) { Level(100); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_NOSEPASS) { Level(100); Moves(MOVE_TACKLE); }
    } WHEN {
            TURN { MOVE(player, MOVE_SWORDS_DANCE); EXPECT_MOVES(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Bulbasaur fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Avoid infinite loop if damage taken is equal to recurring healing")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LEFTOVERS].holdEffect == HOLD_EFFECT_LEFTOVERS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_MEOWTH_GALARIAN) { Level(100); Moves(MOVE_GROWL, MOVE_FAKE_OUT, MOVE_HONE_CLAWS); }
        // Scenario courtesy of Duke, who triggered the bug in the first place
        OPPONENT(SPECIES_MEOWTH_GALARIAN) { Level(5); Moves(MOVE_GROWL, MOVE_FAKE_OUT, MOVE_HONE_CLAWS); }
        OPPONENT(SPECIES_GEODUDE) { Level(5); Moves(MOVE_DOUBLE_EDGE); }
        OPPONENT(SPECIES_GEODUDE) { Level(5); Moves(MOVE_DOUBLE_EDGE); }
        OPPONENT(SPECIES_NOSEPASS) { Level(5); Moves(MOVE_DOUBLE_EDGE); }
        OPPONENT(SPECIES_HOUNDSTONE) { Level(5); Moves(MOVE_NIGHT_SHADE, MOVE_BODY_PRESS, MOVE_WILL_O_WISP, MOVE_PROTECT); Item(ITEM_LEFTOVERS); }
    } WHEN {
            TURN { MOVE(player, MOVE_FAKE_OUT); EXPECT_MOVES(opponent, MOVE_FAKE_OUT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will not switch in a Pokemon which is slower and gets 1HKOed after fainting")
{
    bool32 alakazamFirst;
    u32 speedAlakazm;
    u32 aiSmartSwitchFlags = 0;

    PARAMETRIZE { speedAlakazm = 200; alakazamFirst = TRUE; } // AI will always send out Alakazan as it sees a KO with Focus Blast, even if Alakazam dies before it can get it off
    PARAMETRIZE { speedAlakazm = 200; alakazamFirst = FALSE; aiSmartSwitchFlags = AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES; } // AI_FLAG_SMART_MON_CHOICES lets AI see that Alakazam would be KO'd before it can KO, and won't switch it in
    PARAMETRIZE { speedAlakazm = 400; alakazamFirst = TRUE; aiSmartSwitchFlags = AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES; } // AI_FLAG_SMART_MON_CHOICES recognizes that Alakazam is faster and can KO, and will switch it in

    GIVEN {
        ASSUME(gMovesInfo[MOVE_PSYCHIC].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_FOCUS_BLAST].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_BUBBLE_BEAM].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_WATER_GUN].category == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(gMovesInfo[MOVE_STRENGTH].category == DAMAGE_CATEGORY_PHYSICAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSmartSwitchFlags);
        PLAYER(SPECIES_WEAVILE) { Speed(300); Ability(ABILITY_SHADOW_TAG); } // Weavile has Shadow Tag, so AI can't switch on the first turn, but has to do it after fainting.
        OPPONENT(SPECIES_KADABRA) { Speed(200); Moves(MOVE_PSYCHIC, MOVE_DISABLE, MOVE_TAUNT, MOVE_CALM_MIND); }
        OPPONENT(SPECIES_ALAKAZAM) { Speed(speedAlakazm); Moves(MOVE_FOCUS_BLAST, MOVE_PSYCHIC); } // Alakazam has a move which OHKOes Weavile, but it doesn't matter if he's getting KO-ed first.
        OPPONENT(SPECIES_BLASTOISE) { Speed(200); Moves(MOVE_BUBBLE_BEAM, MOVE_WATER_GUN, MOVE_LEER, MOVE_STRENGTH); } // Can't OHKO, but survives a hit from Weavile's Night Slash.
    } WHEN {
            TURN { MOVE(player, MOVE_NIGHT_SLASH) ; EXPECT_SEND_OUT(opponent, alakazamFirst ? 1 : 2); } // AI doesn't send out Alakazam if it gets outsped
    } SCENE {
        MESSAGE("Foe Kadabra fainted!");
        if (alakazamFirst) {
            MESSAGE("{PKMN} TRAINER LEAF sent out Alakazam!");
        } else {
            MESSAGE("{PKMN} TRAINER LEAF sent out Blastoise!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI considers hazard damage when choosing which Pokemon to switch in")
{
    u32 aiIsSmart = 0;
    u32 aiSmartSwitchFlags = 0;

    PARAMETRIZE { aiIsSmart = 0; aiSmartSwitchFlags = 0; } // AI doesn't care about hazard damage resulting in Pokemon being KO'd
    PARAMETRIZE { aiIsSmart = 1; aiSmartSwitchFlags = AI_FLAG_SMART_MON_CHOICES; } // AI_FLAG_SMART_MON_CHOICES avoids being KO'd as a result of hazards damage

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSmartSwitchFlags);
        PLAYER(SPECIES_MEGANIUM) { Speed(100); SpDefense(328); SpAttack(265); Moves(MOVE_STEALTH_ROCK, MOVE_SURF); } // Meganium does ~56% minimum ~66% maximum, enough to KO Charizard after rocks and never KO Typhlosion after rocks
        OPPONENT(SPECIES_PONYTA) { Level(5); Speed(5); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_CHARIZARD) { Speed(200); Moves(MOVE_FLAMETHROWER); SpAttack(317); SpDefense(207); MaxHP(297); } // Outspeends and 2HKOs Meganium
        OPPONENT(SPECIES_TYPHLOSION) { Speed(200); Moves(MOVE_FLAMETHROWER); SpAttack(317); SpDefense(207); MaxHP(297); } // Outspeends and 2HKOs Meganium
    } WHEN {
            TURN { MOVE(player, MOVE_STEALTH_ROCK) ;}
            TURN { MOVE(player, MOVE_SURF); EXPECT_SEND_OUT(opponent, aiIsSmart ? 2 : 1); } // AI sends out Typhlosion to get the KO with the flag rather than Charizard
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize type matchup + SE move, then type matchup")
{
    u32 aiSmartSwitchFlags = 0;
    u32 move1;
    u32 move2;
    u32 expectedIndex;

    PARAMETRIZE { expectedIndex = 3; move1 = MOVE_TACKLE; move2 = MOVE_TACKLE; aiSmartSwitchFlags = 0; } // When not smart, AI will only switch in a defensive mon if it has a SE move, otherwise will just default to damage
    PARAMETRIZE { expectedIndex = 1; move1 = MOVE_GIGA_DRAIN; move2 = MOVE_TACKLE; aiSmartSwitchFlags = 0; }
    PARAMETRIZE { expectedIndex = 2; move1 = MOVE_TACKLE; move2 = MOVE_TACKLE; aiSmartSwitchFlags = AI_FLAG_SMART_MON_CHOICES; } // When smart, AI will prioritize SE move, but still switch in good type matchup without SE move
    PARAMETRIZE { expectedIndex = 1; move1 = MOVE_GIGA_DRAIN; move2 = MOVE_TACKLE; aiSmartSwitchFlags = AI_FLAG_SMART_MON_CHOICES; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSmartSwitchFlags);
        PLAYER(SPECIES_MARSHTOMP) { Level(30); Moves(MOVE_MUD_BOMB, MOVE_WATER_GUN, MOVE_GROWL, MOVE_MUD_SHOT); Speed(5); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Moves(MOVE_NONE); Speed(6); } // Forces switchout
        OPPONENT(SPECIES_TANGELA) { Level(30); Moves(move1); Speed(4); }
        OPPONENT(SPECIES_LOMBRE) { Level(30); Moves(move2); Speed(4); }
        OPPONENT(SPECIES_HARIYAMA) { Level(30); Moves(MOVE_VITAL_THROW); Speed(4); }
    } WHEN {
            TURN { MOVE(player, MOVE_GROWL); EXPECT_SWITCH(opponent, expectedIndex); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize defensive options")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_WING_ATTACK, MOVE_BOOMBURST); Speed(5); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Moves(MOVE_NONE); Speed(4); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_HEADBUTT); Speed(4); SpDefense(41); } // Mid battle, AI sends out Aron
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Moves(MOVE_CHARGE_BEAM); Speed(6); }
    } WHEN {
            TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Post-KO switches prioritize offensive options")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_WING_ATTACK, MOVE_BOOMBURST); Speed(5); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Moves(MOVE_TACKLE); Speed(4); }
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_HEADBUTT); Speed(4); } // Mid battle, AI sends out Aron
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Moves(MOVE_CHARGE_BEAM); Speed(6); }
    } WHEN {
            TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Post-KO switches factor in Trick Room for revenge killing")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TRICK_ROOM].effect == EFFECT_TRICK_ROOM);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_SWELLOW) { Level(30); Speed(10); Moves(MOVE_WING_ATTACK, MOVE_GROWL); }
        OPPONENT(SPECIES_BALTOY) { Level(1); Speed(10); Moves(MOVE_TRICK_ROOM); }
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Speed(5); Moves(MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Speed(15); Moves(MOVE_THUNDERBOLT); }
    } WHEN {
            TURN { EXPECT_MOVE(opponent, MOVE_TRICK_ROOM); MOVE(player, MOVE_GROWL); }
            TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SEND_OUT(opponent, 1); }
    }
}

// General AI_FLAG_SMART_SWITCHING behaviour
AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI switches out after sufficient stat drops")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_HITMONTOP) { Level(30); Moves(MOVE_CHARM, MOVE_TACKLE); Ability(ABILITY_INTIMIDATE); Speed(5); }
        OPPONENT(SPECIES_GRIMER) { Level(30); Moves(MOVE_TACKLE); Speed(4); }
        OPPONENT(SPECIES_PONYTA) { Level(30); Moves(MOVE_HEADBUTT); Speed(4); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not switch out if Pokemon would faint to hazards unless party member can clear them")
{
    u32 move1;

    PARAMETRIZE { move1 = MOVE_TACKLE; }
    PARAMETRIZE { move1 = MOVE_RAPID_SPIN; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_RAPID_SPIN].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_EARTHQUAKE].category == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gMovesInfo[MOVE_HEADBUTT].category == DAMAGE_CATEGORY_PHYSICAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_HITMONTOP) { Level(30); Moves(MOVE_CHARM, MOVE_TACKLE, MOVE_STEALTH_ROCK, MOVE_EARTHQUAKE); Ability(ABILITY_INTIMIDATE); Speed(5); }
        OPPONENT(SPECIES_GRIMER) { Level(30); Moves(MOVE_TACKLE); Item(ITEM_FOCUS_SASH); Speed(4); }
        OPPONENT(SPECIES_PONYTA) { Level(30); Moves(MOVE_HEADBUTT, move1); Speed(4); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { // If the AI has a mon that can remove hazards, don't prevent them switching out
            MOVE(player, MOVE_CHARM);
            if (move1 == MOVE_RAPID_SPIN)
                EXPECT_SWITCH(opponent, 1);
            else if (move1 == MOVE_TACKLE)
                EXPECT_MOVE(opponent, MOVE_TACKLE);
        }
    }
}

// Trapping behaviour
AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch in trapping mon mid battle")
{
    u32 aiSmartSwitchingFlag = 0;
    PARAMETRIZE { aiSmartSwitchingFlag = 0; }
    PARAMETRIZE { aiSmartSwitchingFlag = AI_FLAG_SMART_SWITCHING; }

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_GOLURK].types[0] == TYPE_GROUND);
        ASSUME(gSpeciesInfo[SPECIES_GOLURK].types[1] == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSmartSwitchingFlag);
        PLAYER(SPECIES_ELECTRODE) { Speed(4); Moves(MOVE_THUNDERBOLT, MOVE_AURA_SPHERE, MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); };
        OPPONENT(SPECIES_SNORLAX) { Speed(1); Moves(MOVE_HEADBUTT); }
        OPPONENT(SPECIES_DUGTRIO) { Speed(3); Ability(ABILITY_ARENA_TRAP); Moves(MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_GOLURK) { Speed(5); Moves(MOVE_EARTHQUAKE); }
    } WHEN {
        if (aiSmartSwitchingFlag == AI_FLAG_SMART_SWITCHING)
            TURN { MOVE(player, MOVE_AURA_SPHERE) ; EXPECT_SWITCH(opponent, 1); }
        else
            TURN { MOVE(player, MOVE_AURA_SPHERE) ; EXPECT_MOVE(opponent, MOVE_HEADBUTT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will switch in trapping mon after KO")
{
    u32 aiSmartMonChoicesFlag = 0; // Enables trapping behaviour after KOs
    PARAMETRIZE { aiSmartMonChoicesFlag = 0; } // No trapping behaviour
    PARAMETRIZE { aiSmartMonChoicesFlag = AI_FLAG_SMART_MON_CHOICES; } // Traps with mid battle switches
    GIVEN{
        ASSUME(gSpeciesInfo[SPECIES_MAWILE].types[0] == TYPE_STEEL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSmartMonChoicesFlag);
        PLAYER(SPECIES_MAWILE) { Speed(2); Moves(MOVE_PROTECT, MOVE_TACKLE); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_SNORLAX) { Speed(3); Moves(MOVE_SELF_DESTRUCT); }
        OPPONENT(SPECIES_MAGNEZONE) { Speed(1); Ability(ABILITY_MAGNET_PULL); Moves(MOVE_SHOCK_WAVE); }
        OPPONENT(SPECIES_MEGANIUM) { Speed(3); Moves(MOVE_EARTH_POWER); }
    } WHEN {
        if (aiSmartMonChoicesFlag == AI_FLAG_SMART_MON_CHOICES)
            TURN{ MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_SELF_DESTRUCT); EXPECT_SEND_OUT(opponent, 1); }
        else
            TURN{ MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_SELF_DESTRUCT); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use trapping behaviour if player only has 1 mon left")
{
    u32 aiSmartMonChoicesFlag = 0; // Enables trapping behaviour after KOs
    PARAMETRIZE { aiSmartMonChoicesFlag = 0; } // No trapping behaviour
    PARAMETRIZE { aiSmartMonChoicesFlag = AI_FLAG_SMART_MON_CHOICES; } // Traps with mid battle switches
    GIVEN{
        ASSUME(gSpeciesInfo[SPECIES_MAWILE].types[0] == TYPE_STEEL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSmartMonChoicesFlag);
        PLAYER(SPECIES_MAWILE) { Speed(2); Moves(MOVE_PROTECT, MOVE_TACKLE); }
        OPPONENT(SPECIES_SNORLAX) { Speed(3); Moves(MOVE_SELF_DESTRUCT); }
        OPPONENT(SPECIES_MAGNEZONE) { Speed(1); Ability(ABILITY_MAGNET_PULL); Moves(MOVE_SHOCK_WAVE); }
        OPPONENT(SPECIES_MEGANIUM) { Speed(3); Moves(MOVE_EARTH_POWER); }
    } WHEN {
            TURN{ MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_SELF_DESTRUCT); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if mon would be OKHO'd and they have a good switchin 50% of the time")
{
    PASSES_RANDOMLY(50, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_RHYDON].types[0] == TYPE_GROUND);
        ASSUME(gSpeciesInfo[SPECIES_PELIPPER].types[0] == TYPE_WATER);
        ASSUME(gSpeciesInfo[SPECIES_PELIPPER].types[1] == TYPE_FLYING);
        ASSUME(gMovesInfo[MOVE_THUNDERBOLT].type == TYPE_ELECTRIC);
        ASSUME(gMovesInfo[MOVE_EARTHQUAKE].type == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_ELECTRODE) { Moves(MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_THUNDER_SHOCK); }
        OPPONENT(SPECIES_PELIPPER) { Moves(MOVE_EARTHQUAKE); };
        OPPONENT(SPECIES_RHYDON) { Moves(MOVE_EARTHQUAKE); Ability(ABILITY_ROCK_HEAD); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI will switch out if it can't deal damage to a mon with Wonder Guard 66% of the time")
{
    PASSES_RANDOMLY(66, 100, RNG_AI_SWITCH_WONDER_GUARD);
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SHEDINJA].types[0] == TYPE_BUG);
        ASSUME(gSpeciesInfo[SPECIES_SHEDINJA].types[1] == TYPE_GHOST);
        ASSUME(gMovesInfo[MOVE_TACKLE].type == TYPE_NORMAL);
        ASSUME(gMovesInfo[MOVE_SHADOW_BALL].type == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SHEDINJA) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it can't deal damage to a mon with Wonder Guard 100% of the time")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SWITCH_WONDER_GUARD);
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_SHEDINJA].types[0] == TYPE_BUG);
        ASSUME(gSpeciesInfo[SPECIES_SHEDINJA].types[1] == TYPE_GHOST);
        ASSUME(gSpeciesInfo[SPECIES_SHEDINJA].abilities[0] == ABILITY_WONDER_GUARD);
        ASSUME(gSpeciesInfo[SPECIES_SHEDINJA].abilities[1] == ABILITY_NONE);
        ASSUME(gSpeciesInfo[SPECIES_SHEDINJA].abilities[2] == ABILITY_NONE);
        ASSUME(gMovesInfo[MOVE_TACKLE].type == TYPE_NORMAL);
        ASSUME(gMovesInfo[MOVE_SHADOW_BALL].type == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SHEDINJA) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE) ; EXPECT_SWITCH(opponent, 1); }
    }
}
