#include "global.h"
#include "test/battle.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"

AI_SINGLE_BATTLE_TEST("AI gets baited by Protect Switch tactics") // This behavior is to be fixed.
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_STUNFISK);
        PLAYER(SPECIES_PELIPPER);
        OPPONENT(SPECIES_DARKRAI) { Moves(MOVE_SCRATCH, MOVE_PECK, MOVE_EARTHQUAKE, MOVE_THUNDERBOLT); }
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

AI_SINGLE_BATTLE_TEST("AI picks an injured ally to receive Healing Wish") // Healing Wish heals the next switch-in; expect the AI to pick its 1 HP burned mon
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HEALING_WISH); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Status1(STATUS1_BURN); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI avoids wasting Healing Wish on a mon that dies to hazards") // Stealth Rock up; AI should not send in a 1 HP mon weak to Rock
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SHUCKLE) { Moves(MOVE_STEALTH_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_HEALING_WISH); }
        OPPONENT(SPECIES_CHARIZARD) { HP(1); Moves(MOVE_SCRATCH); } // would faint on entry
        OPPONENT(SPECIES_BLISSEY) { HP(50); MaxHP(400); Moves(MOVE_SEISMIC_TOSS); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); EXPECT_MOVE(opponent, MOVE_HEALING_WISH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI chooses best post-KO switch with stored Wish") // Wish is active; should pick mon that benefits from heal AND can win 1v1
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_BLISSEY) { HP(1); Moves(MOVE_WISH); }
        OPPONENT(SPECIES_PIDGEOT) { HP(100); MaxHP(200); Moves(MOVE_GUST); } // 50% HP, gains 50% from Wish (>25% threshold), can win 1v1
        OPPONENT(SPECIES_GOLEM) { HP(390); MaxHP(400); Moves(MOVE_ROCK_THROW); } // 97.5% HP, gains only 2.5% (<25% threshold)
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_WISH); MOVE(player, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI revives the best fainted ally with Revival Blessing") // Fainted Pidgey (has damaging move) should be picked over Splash Magikarp
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_AUDINO) { Moves(MOVE_REVIVAL_BLESSING); }
        OPPONENT(SPECIES_PIDGEY) { HP(0); Moves(MOVE_GUST); }
        OPPONENT(SPECIES_MAGIKARP) { HP(0); Moves(MOVE_SPLASH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_REVIVAL_BLESSING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVIVAL_BLESSING, opponent);
        MESSAGE("Pidgey was revived and is ready to fight again!");
    }
}

AI_MULTI_BATTLE_TEST("AI will not revive a partner's party member with Revival Blessing")
{
    struct BattlePokemon *user = NULL;
    enum Move move1, move2, move3;
    PARAMETRIZE { user = opponentLeft, move1 = MOVE_REVIVAL_BLESSING, move2 = MOVE_CELEBRATE, move3 = MOVE_CELEBRATE; }
    PARAMETRIZE { user = playerRight, move1 = MOVE_CELEBRATE, move2 = MOVE_REVIVAL_BLESSING, move3 = MOVE_CELEBRATE; }
    PARAMETRIZE { user = opponentRight, move1 = MOVE_CELEBRATE, move2 = MOVE_CELEBRATE, move3 = MOVE_REVIVAL_BLESSING; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_REVIVAL_BLESSING) == EFFECT_REVIVAL_BLESSING);
        PLAYER(SPECIES_CLEFABLE);
        PLAYER(SPECIES_CLEFABLE) { HP(0); }
        PLAYER(SPECIES_CLEFABLE);
        PARTNER(SPECIES_CLEFAIRY) { Moves(move2); }
        PARTNER(SPECIES_CLEFAIRY);
        PARTNER(SPECIES_CLEFAIRY);
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(move1); }
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_B(SPECIES_WYNAUT) { Moves(move3); }
        OPPONENT_B(SPECIES_WYNAUT) { HP(0); }
        OPPONENT_B(SPECIES_WYNAUT);
    } WHEN {
        TURN { EXPECT_MOVE(playerRight, move2); } // EXPECT_MOVE makes battler2 AI-controlled
    } SCENE {
        if (user == opponentLeft) {
            MESSAGE("The opposing Wobbuffet used Revival Blessing!");
            MESSAGE("But it failed!");
        } else if (user == playerRight) {
            MESSAGE("Clefairy used Revival Blessing!");
            MESSAGE("But it failed!");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_REVIVAL_BLESSING, opponentRight);
            MESSAGE("Wynaut was revived and is ready to fight again!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI switches to pass Wish when matchup is bad and ally benefits")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_WISH_PASSING_PERCENTAGE, 100, RNG_AI_SWITCH_WISH_PASSING);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_MACHAMP) { Moves(MOVE_CROSS_CHOP, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_BLISSEY) { HP(400); MaxHP(400); Moves(MOVE_WISH, MOVE_SOFT_BOILED); }
        OPPONENT(SPECIES_CROBAT) { HP(100); MaxHP(200); Moves(MOVE_BRAVE_BIRD); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_WISH); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI does not switch for Wish if current mon has good matchup")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_COUNTER, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_BLISSEY) { HP(400); MaxHP(400); Moves(MOVE_WISH, MOVE_TACKLE); }
        OPPONENT(SPECIES_PIDGEOT) { HP(100); MaxHP(200); Moves(MOVE_AERIAL_ACE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_WISH); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI does not switch for Wish if ally would faint to hazards")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_MACHAMP) { Moves(MOVE_CROSS_CHOP, MOVE_STEALTH_ROCK, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_BLISSEY) { HP(400); MaxHP(400); Moves(MOVE_WISH, MOVE_TACKLE); }
        OPPONENT(SPECIES_CHARIZARD) { HP(1); MaxHP(200); Moves(MOVE_FLAMETHROWER); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); EXPECT_MOVE(opponent, MOVE_WISH); }
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI does not switch for Wish if it predicts Heal Block")
{
    PASSES_RANDOMLY(PREDICT_MOVE_CHANCE, 100, RNG_AI_PREDICT_MOVE);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT | AI_FLAG_PREDICT_MOVE);
        PLAYER(SPECIES_MACHAMP) { Moves(MOVE_CROSS_CHOP, MOVE_HEAL_BLOCK, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_BLISSEY) { HP(100); MaxHP(400); Moves(MOVE_WISH, MOVE_TACKLE); }
        OPPONENT(SPECIES_PIDGEOT) { HP(100); MaxHP(200); Moves(MOVE_AERIAL_ACE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_WISH); }
        TURN { MOVE(player, MOVE_HEAL_BLOCK); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

// General switching behaviour
AI_SINGLE_BATTLE_TEST("AI switches if Perish Song is about to kill")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_PERISH_SONG_PERCENTAGE, 100, RNG_AI_SWITCH_PERISH_SONG);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_CROBAT) { Moves(MOVE_SCRATCH); }
    } WHEN {
            TURN { MOVE(player, MOVE_PERISH_SONG); }
            TURN {}
            TURN {}
            TURN { EXPECT_SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE(AI_TRAINER_NAME " sent out Crobat!");
    }
}

AI_SINGLE_BATTLE_TEST("AI sees on-field player ability correctly and does not see previous Pokémon's ability after player uses a pivot move when choosing a post-KO switch")
{
    enum Ability testAbility;
    PARAMETRIZE { testAbility = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { testAbility = ABILITY_VOLT_ABSORB; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_PIKACHU) { Level(100); Moves(MOVE_VOLT_SWITCH, MOVE_SPARKLY_SWIRL); Ability(ABILITY_LIGHTNING_ROD); }
        PLAYER(SPECIES_LANTURN) { Level(44); Moves(MOVE_SCALD); Ability(testAbility); }
        OPPONENT(SPECIES_SOBBLE) { Level(44); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_BOMBIRDIER) { Level(42); Moves(MOVE_ROCK_SLIDE); }
        OPPONENT(SPECIES_IRON_THORNS) { Level(43); Moves(MOVE_SUPERCELL_SLAM, MOVE_ICE_PUNCH); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_VOLT_SWITCH);
            SEND_OUT(player, 1);
            EXPECT_MOVE(opponent, MOVE_SCRATCH);
            testAbility == ABILITY_WATER_ABSORB ? EXPECT_SEND_OUT(opponent, 2) : EXPECT_SEND_OUT(opponent, 1);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not try to switch for the same Pokémon for 2 spots in a double battle (all bad moves)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(flags);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage player.
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_HAUNTER) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentLeft, 2); }
    } SCENE {
        MESSAGE(AI_TRAINER_NAME " withdrew Gengar!");
        MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_TRAINER_NAME " withdrew Haunter!");
            MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not try to switch for the same Pokémon for 2 spots in a double battle (all bad moves, reversed)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        AI_FLAGS(flags);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage player.
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_HAUNTER) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentRight, 2); }
    } SCENE {
        MESSAGE(AI_TRAINER_NAME " withdrew Haunter!");
        MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_TRAINER_NAME " withdrew Gengar!");
            MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        }
    }
}

// Used to test EXPECT_SWITCH only on partner
AI_MULTI_BATTLE_TEST("AI partner will not switch mid-turn into a player Pokémon (multi)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_HAUNTER);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        PARTNER(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        PARTNER(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }
        OPPONENT_A(SPECIES_RATTATA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_KANGASKHAN) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { EXPECT_SWITCH(playerRight, 2); }
    } SCENE {
        MESSAGE(AI_PARTNER_NAME " withdrew Gengar!");
        MESSAGE(AI_PARTNER_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_PARTNER_NAME " withdrew Gengar!");
            MESSAGE(AI_PARTNER_NAME " sent out Rattata!");
        }
    }
}

// Used to test EXPECT_SWITCH only on partner
AI_TWO_VS_ONE_BATTLE_TEST("AI partner will not switch mid-turn into a player Pokémon (2v1)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_HAUNTER);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        PARTNER(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        PARTNER(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }
        OPPONENT_A(SPECIES_RATTATA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_KANGASKHAN) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { EXPECT_SWITCH(playerRight, 2); }
    } SCENE {
        MESSAGE(AI_PARTNER_NAME " withdrew Gengar!");
        MESSAGE(AI_PARTNER_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_PARTNER_NAME " withdrew Gengar!");
            MESSAGE(AI_PARTNER_NAME " sent out Rattata!");
        }
    }
}

// Used to test EXPECT_SEND_OUT only on partner
AI_MULTI_BATTLE_TEST("AI partner will not switch into a player Pokémon after fainting (multi)")
{
    u32 flags;

    PARAMETRIZE {flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE {flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_GENGAR);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); HP(1); }
        PARTNER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        OPPONENT_A(SPECIES_TRAPINCH) { Ability(ABILITY_ARENA_TRAP); Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_VIBRAVA) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_CELEBRATE); EXPECT_SEND_OUT(playerRight, 2); }
    } SCENE {
        MESSAGE(AI_PARTNER_NAME " sent out Haunter!");
        NONE_OF {
            MESSAGE(AI_PARTNER_NAME " sent out Rattata!");
        }
    }
}

// Used to test EXPECT_SEND_OUT only on partner
AI_TWO_VS_ONE_BATTLE_TEST("AI partner will not switch into a player Pokémon after fainting (2v1)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_GENGAR);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); HP(1); }
        PARTNER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        OPPONENT_A(SPECIES_TRAPINCH) { Ability(ABILITY_ARENA_TRAP); Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_VIBRAVA) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_CELEBRATE); EXPECT_SEND_OUT(playerRight, 2); }
    } SCENE {
        MESSAGE(AI_PARTNER_NAME " sent out Haunter!");
        NONE_OF {
            MESSAGE(AI_PARTNER_NAME " sent out Rattata!");
        }
    }
}

// Used to test EXPECT_SWITCH, EXPECT_SEND_OUT, and EXPECT_MOVE on partner
AI_MULTI_BATTLE_TEST("AI partner will not switch into a player Pokémon (multi)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = 0; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | flags);
        PLAYER(SPECIES_HAUNTER);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        PARTNER(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); HP(1); }
        OPPONENT_A(SPECIES_RATTATA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_KANGASKHAN) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AURA_SPHERE, target:playerRight); EXPECT_SWITCH(playerRight, 1); EXPECT_SEND_OUT(playerRight, 0); }
        TURN { EXPECT_MOVE(playerRight, MOVE_SHADOW_BALL, target:opponentLeft); }
    } SCENE {
        MESSAGE(AI_PARTNER_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_PARTNER_NAME " sent out Rattata!");
        }
    }
}

// Used to test EXPECT_SWITCH, EXPECT_SEND_OUT, and EXPECT_MOVE on partner
AI_TWO_VS_ONE_BATTLE_TEST("AI partner will not switch into a player Pokémon (2v1)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_HAUNTER);
        PLAYER(SPECIES_RATTATA);
        // No moves to damage opponents.
        PARTNER(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        PARTNER(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); HP(1); }
        OPPONENT_A(SPECIES_RATTATA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_KANGASKHAN) { Moves(MOVE_CELEBRATE); }

    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AURA_SPHERE, target:playerRight); EXPECT_SWITCH(playerRight, 1); EXPECT_SEND_OUT(playerRight, 0); }
        TURN { EXPECT_MOVE(playerRight, MOVE_SHADOW_BALL, target:opponentLeft); }
    } SCENE {
        MESSAGE(AI_PARTNER_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_PARTNER_NAME " sent out Rattata!");
        }
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("AI will not try to switch for the same pokemon for 2 spots in a 2v1 battle (all bad moves)")
{
    u32 flags;

    PARAMETRIZE {flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE {flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(flags);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        PARTNER(SPECIES_KANGASKHAN);
        // No moves to damage player.
        OPPONENT_A(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT_A(SPECIES_HAUNTER) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT_A(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        OPPONENT_A(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentLeft, 3); }
    } SCENE {
        MESSAGE(AI_TRAINER_NAME " withdrew Gengar!");
        MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        if (flags & AI_FLAG_SMART_SWITCHING)
        {
            MESSAGE(AI_TRAINER_NAME " withdrew Haunter!");
            MESSAGE(AI_TRAINER_NAME " sent out Gastly!");
        }
        NONE_OF {
            MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        }
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("AI will not try to switch for the same pokemon for 2 spots in a 2v1 battle (all bad moves, reversed)")
{
    u32 flags;

    PARAMETRIZE {flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE {flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    // PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        AI_FLAGS(flags);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        PARTNER(SPECIES_KANGASKHAN);
        // No moves to damage player.
        OPPONENT_A(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT_A(SPECIES_HAUNTER) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT_A(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        OPPONENT_A(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentRight, 3); }
    } SCENE {
        if (flags & AI_FLAG_SMART_SWITCHING)
        {
            MESSAGE(AI_TRAINER_NAME " withdrew Gengar!");
            MESSAGE(AI_TRAINER_NAME " sent out Gastly!");
        }
        MESSAGE(AI_TRAINER_NAME " withdrew Haunter!");
        MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        }
    }
}

AI_ONE_VS_TWO_BATTLE_TEST("AI will not switch into a partner Pokémon in a 1v2 battle (all bad moves)")
{
    u32 flags;

    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }

    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_KANGASKHAN);
        // No moves to damage player.
        OPPONENT_A(SPECIES_HAUNTER) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT_B(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT_B(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        OPPONENT_B(SPECIES_RATICATE) { Moves(MOVE_HEADBUTT); }

    } WHEN {
        TURN { EXPECT_SWITCH(opponentRight, 2); }
    } SCENE {
        MESSAGE(AI_TRAINER_2_NAME " withdrew Gengar!");
        MESSAGE(AI_TRAINER_2_NAME " sent out Raticate!");
        NONE_OF {
            MESSAGE(AI_TRAINER_NAME " withdrew Haunter!");
            MESSAGE(AI_TRAINER_NAME " sent out Raticate!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI will switch out if it has no move that affects the player")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RATTATA);
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will switch out if it has no moves that affect either of the player's battlers")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH);}
    } WHEN {
        TURN { EXPECT_SWITCH(opponentLeft, 2); EXPECT_MOVE(opponentRight, MOVE_SCRATCH); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not switch out if it's moves can still affect one of the player's battlers")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_RATTATA);
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH);}
    } WHEN {
        TURN { EXPECT_MOVE(opponentLeft, MOVE_SHADOW_BALL); EXPECT_MOVE(opponentRight, MOVE_SCRATCH); }
    }
}


AI_SINGLE_BATTLE_TEST("When AI switches out due to having no move that affects the player, AI will send in a mon that can hit the player, even if not ideal")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ABRA) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ABRA) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ABRA) { Level(5); Moves(MOVE_CONFUSION); }
        OPPONENT(SPECIES_ABRA) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ABRA) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_BALL); EXPECT_SWITCH(opponent, 2); EXPECT_SEND_OUT(opponent, 4); }
        TURN { MOVE(player, MOVE_SHADOW_BALL); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not try to switch for the same Pokémon for 2 spots in a double battle (Wonder Guard)")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SHEDINJA);
        PLAYER(SPECIES_SHEDINJA);
        // No moves to damage player.
        OPPONENT(SPECIES_LINOONE) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_SENTRET) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentLeft, 3); }
    } SCENE {
        MESSAGE(AI_TRAINER_NAME " withdrew Linoone!");
        MESSAGE(AI_TRAINER_NAME " sent out Gengar!");
        NONE_OF {
            MESSAGE(AI_TRAINER_NAME "sent out Linoone!");
            MESSAGE(AI_TRAINER_NAME " sent out Gengar!");
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not try to switch for the same Pokémon for 2 spots in a double battle (Wonder Guard, reversed)")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SHEDINJA);
        PLAYER(SPECIES_SHEDINJA);
        // No moves to damage player.
        OPPONENT(SPECIES_LINOONE) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_SENTRET) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponentRight, 3); }
    } SCENE {
        MESSAGE(AI_TRAINER_NAME " withdrew Zigzagoon!");
        MESSAGE(AI_TRAINER_NAME " sent out Gengar!");
        NONE_OF {
            MESSAGE(AI_TRAINER_NAME "sent out Zigzagoon!");
            MESSAGE(AI_TRAINER_NAME " sent out Gengar!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Switch effect moves will send out Ace Mon if it's the only one remaining")
{
    u32 aiMove = 0;
    // Moves testing all effects in IsSwitchOutEffect
    PARAMETRIZE { aiMove = MOVE_U_TURN; }
    PARAMETRIZE { aiMove = MOVE_TELEPORT; }
    PARAMETRIZE { aiMove = MOVE_PARTING_SHOT; }
    PARAMETRIZE { aiMove = MOVE_BATON_PASS; }
    PARAMETRIZE { aiMove = MOVE_CHILLY_RECEPTION; }
    PARAMETRIZE { aiMove = MOVE_SHED_TAIL; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        ASSUME(GetMoveEffect(MOVE_TELEPORT) == EFFECT_TELEPORT);
        ASSUME(GetMoveEffect(MOVE_PARTING_SHOT) == EFFECT_PARTING_SHOT);
        ASSUME(GetMoveEffect(MOVE_BATON_PASS) == EFFECT_BATON_PASS);
        ASSUME(GetMoveEffect(MOVE_CHILLY_RECEPTION) == EFFECT_WEATHER_AND_SWITCH);
        ASSUME(GetMoveEffect(MOVE_SHED_TAIL) == EFFECT_SHED_TAIL);
        WITH_CONFIG(B_TELEPORT_BEHAVIOR, GEN_8);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_ACE_POKEMON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(aiMove); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { EXPECT_MOVE(opponent, aiMove); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Eject Button will send out Ace Mon if it's the only one remaining")
{
    u32 flags;
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ACE_POKEMON; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_ACE_POKEMON; }
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_LINOONE);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Eject Pack will send out Ace Mon if it's the only one remaining")
{
    u32 flags;
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ACE_POKEMON; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_ACE_POKEMON; }
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        PLAYER(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Item(ITEM_EJECT_PACK); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_LINOONE) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 1); }
    }
}

// General AI_FLAG_SMART_MON_CHOICES behaviour
AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Move data does not spill over between switch-in candidates")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(IsBattleMoveStatus(MOVE_CELEBRATE));
        ASSUME(gItemsInfo[ITEM_ASSAULT_VEST].holdEffect == HOLD_EFFECT_ASSAULT_VEST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_WOBBUFFET) { HP(80); MaxHP(80); Speed(50); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_MAGIKARP) { HP(1); Speed(10); Moves(MOVE_SPLASH); }
        OPPONENT(SPECIES_ABRA) { HP(30); MaxHP(30); Speed(40); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(200); MaxHP(200); Speed(60); Moves(MOVE_CELEBRATE); Item(ITEM_ASSAULT_VEST); }
        OPPONENT(SPECIES_MAGIKARP) { Speed(30); Moves(MOVE_SPLASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); EXPECT_SEND_OUT(opponent, 3); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Switchin move data is reset before recalculation")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_DRAGON_RAGE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_DRAGON_RAGE); }
    } THEN {
        enum BattlerId battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        enum BattlerId battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        u32 moveIndex = 0;
        EXPECT_GT(gAiLogicData->simulatedDmg[battlerAtk][battlerDef][moveIndex].median, 0);
        EXPECT_GT(gAiLogicData->effectiveness[battlerAtk][battlerDef][moveIndex], 0);
        EXPECT_GT(gAiLogicData->moveAccuracy[battlerAtk][battlerDef][moveIndex], 0);

        gAiLogicData->resistBerryAffected[battlerAtk][battlerDef][moveIndex] = TRUE;
        gAiLogicData->moveLimitations[battlerAtk] |= 1u << moveIndex;
        CalcBattlerAiMovesData(gAiLogicData, battlerAtk, battlerDef, AI_GetWeather(), gFieldStatuses);

        EXPECT_EQ(gAiLogicData->simulatedDmg[battlerAtk][battlerDef][moveIndex].median, 0);
        EXPECT_EQ(gAiLogicData->effectiveness[battlerAtk][battlerDef][moveIndex], 0);
        EXPECT_EQ(gAiLogicData->moveAccuracy[battlerAtk][battlerDef][moveIndex], 0);
        EXPECT(!gAiLogicData->resistBerryAffected[battlerAtk][battlerDef][moveIndex]);
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Number of hits to KO calculation checks whether incoming damage is less than recurring healing to avoid an infinite loop")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_VENUSAUR) { Level(30); Moves(MOVE_SCRATCH); }
        // Opponent party courtesy of Skolgrahd, who triggered the bug in the first place
        OPPONENT(SPECIES_PIKACHU) { Level(100); Moves(MOVE_ZIPPY_ZAP, MOVE_EXTREME_SPEED, MOVE_IRON_TAIL, MOVE_KNOCK_OFF); }
        OPPONENT(SPECIES_NINETALES_ALOLA) { Level(100); Moves(MOVE_AURORA_VEIL, MOVE_BLIZZARD, MOVE_MOONBLAST, MOVE_DISABLE); }
        OPPONENT(SPECIES_WEAVILE) { Level(100); Moves(MOVE_NIGHT_SLASH, MOVE_TRIPLE_AXEL, MOVE_ICE_SHARD, MOVE_FAKE_OUT); }
        OPPONENT(SPECIES_DITTO) { Level(100); Moves(MOVE_TRANSFORM); }
        OPPONENT(SPECIES_TYPHLOSION) { Level(100); Moves(MOVE_ERUPTION, MOVE_HEAT_WAVE, MOVE_FOCUS_BLAST, MOVE_EXTRASENSORY); }
        OPPONENT(SPECIES_UMBREON) { Level(100); Item(ITEM_LEFTOVERS); Moves(MOVE_FOUL_PLAY, MOVE_SNARL, MOVE_HELPING_HAND, MOVE_THUNDER_WAVE); }
    } WHEN {
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVES(opponent, MOVE_ZIPPY_ZAP, MOVE_EXTREME_SPEED, MOVE_IRON_TAIL, MOVE_KNOCK_OFF); }
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
        OPPONENT(SPECIES_GEODUDE) { Level(100); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GEODUDE) { Level(100); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_NOSEPASS) { Level(100); Moves(MOVE_SCRATCH); }
    } WHEN {
            TURN { MOVE(player, MOVE_SWORDS_DANCE); EXPECT_MOVES(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Bulbasaur fainted!");
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Avoid infinite loop if damage taken is equal to recurring healing")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LEFTOVERS].holdEffect == HOLD_EFFECT_LEFTOVERS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_MEOWTH_GALAR) { Level(100); Moves(MOVE_GROWL, MOVE_FAKE_OUT, MOVE_HONE_CLAWS); }
        // Scenario courtesy of Duke, who triggered the bug in the first place
        OPPONENT(SPECIES_MEOWTH_GALAR) { Level(5); Moves(MOVE_GROWL, MOVE_FAKE_OUT, MOVE_HONE_CLAWS); }
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
        ASSUME(GetMoveCategory(MOVE_PSYCHIC) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_FOCUS_BLAST) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_BUBBLE_BEAM) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveCategory(MOVE_STRENGTH) == DAMAGE_CATEGORY_PHYSICAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiSmartSwitchFlags);
        PLAYER(SPECIES_WEAVILE) { Speed(300); Ability(ABILITY_SHADOW_TAG); } // Weavile has Shadow Tag, so AI can't switch on the first turn, but has to do it after fainting.
        OPPONENT(SPECIES_KADABRA) { Speed(200); Moves(MOVE_PSYCHIC, MOVE_DISABLE, MOVE_TAUNT, MOVE_CALM_MIND); }
        OPPONENT(SPECIES_ALAKAZAM) { Speed(speedAlakazm); Moves(MOVE_FOCUS_BLAST, MOVE_PSYCHIC); } // Alakazam has a move which OHKOes Weavile, but it doesn't matter if he's getting KO-ed first.
        OPPONENT(SPECIES_BLASTOISE) { Speed(200); Moves(MOVE_BUBBLE_BEAM, MOVE_WATER_GUN, MOVE_LEER, MOVE_STRENGTH); } // Can't OHKO, but survives a hit from Weavile's Night Slash.
    } WHEN {
            TURN { MOVE(player, MOVE_NIGHT_SLASH) ; EXPECT_SEND_OUT(opponent, alakazamFirst ? 1 : 2); } // AI doesn't send out Alakazam if it gets outsped
    } SCENE {
        MESSAGE("The opposing Kadabra fainted!");
        if (alakazamFirst) {
            MESSAGE(AI_TRAINER_NAME " sent out Alakazam!");
        } else {
            MESSAGE(AI_TRAINER_NAME " sent out Blastoise!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI considers hazard damage when choosing which Pokemon to switch in")
{
    u32 aiIsSmart = 0;
    u32 flags = 0;

    PARAMETRIZE { aiIsSmart = 0; flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; } // AI doesn't care about hazard damage resulting in Pokemon being KO'd
    PARAMETRIZE { aiIsSmart = 1; flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES; } // AI_FLAG_SMART_MON_CHOICES avoids being KO'd as a result of hazards damage

    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_MEGANIUM) { Speed(100); SpDefense(328); SpAttack(265); Moves(MOVE_STEALTH_ROCK, MOVE_SURF); } // Meganium does ~56% minimum ~66% maximum, enough to KO Charizard after rocks and never KO Typhlosion after rocks
        OPPONENT(SPECIES_PONYTA) { Level(5); Speed(5); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_CHARIZARD) { Speed(200); Moves(MOVE_FLAMETHROWER); SpAttack(317); SpDefense(207); MaxHP(297); } // Outspeends and 2HKOs Meganium
        OPPONENT(SPECIES_TYPHLOSION) { Speed(200); Moves(MOVE_FLAMETHROWER); SpAttack(317); SpDefense(207); MaxHP(297); } // Outspeends and 2HKOs Meganium
    } WHEN {
            TURN { MOVE(player, MOVE_STEALTH_ROCK) ; }
            TURN { MOVE(player, MOVE_SURF); EXPECT_SEND_OUT(opponent, aiIsSmart ? 2 : 1); } // AI sends out Typhlosion to get the KO with the flag rather than Charizard
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize type matchup + SE move, then type matchup")
{
    u32 flags = 0;
    enum Move move1;
    enum Move move2;
    u32 expectedIndex;

    PARAMETRIZE { expectedIndex = 3; move1 = MOVE_SCRATCH; move2 = MOVE_SCRATCH; flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; } // When not smart, AI will only switch in a defensive mon if it has a SE move, otherwise will just default to damage
    PARAMETRIZE { expectedIndex = 1; move1 = MOVE_GIGA_DRAIN; move2 = MOVE_SCRATCH; flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }
    PARAMETRIZE { expectedIndex = 2; move1 = MOVE_SCRATCH; move2 = MOVE_WATER_PULSE; flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES; } // When smart, AI will prioritize SE move, but still switch in good type matchup without SE move
    PARAMETRIZE { expectedIndex = 1; move1 = MOVE_GIGA_DRAIN; move2 = MOVE_SCRATCH; flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES; }

    GIVEN {
        AI_FLAGS(flags);
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
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_WING_ATTACK, MOVE_BOOMBURST); Speed(5); SpAttack(50); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Moves(MOVE_NONE); Speed(4); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_IRON_HEAD); Speed(4); SpDefense(50); } // Mid battle, AI sends out Aron
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Ability(ABILITY_STATIC); Moves(MOVE_CHARGE_BEAM); Speed(6); SpDefense(53); }
    } WHEN {
            TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize offensive options after slow U-Turn")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_FALSE_SWIPE, MOVE_BOOMBURST); Speed(5); SpAttack(50); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Moves(MOVE_U_TURN); Speed(4); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_IRON_HEAD); Speed(4); SpDefense(50); }
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Ability(ABILITY_STATIC); Moves(MOVE_CHARGE_BEAM); Speed(6); SpDefense(53); }
    } WHEN {
            TURN { MOVE(player, MOVE_FALSE_SWIPE); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize offensive options after Eject Button")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        ASSUME(GetMoveEffect(MOVE_FALSE_SWIPE) == EFFECT_FALSE_SWIPE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_FALSE_SWIPE, MOVE_BOOMBURST); Speed(5); SpAttack(50); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Item(ITEM_EJECT_BUTTON); Moves(MOVE_SCRATCH); Speed(4); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_IRON_HEAD); Speed(4); SpDefense(50); }
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Ability(ABILITY_STATIC); Moves(MOVE_CHARGE_BEAM); Speed(6); SpDefense(53); }
    } WHEN {
            TURN { MOVE(player, MOVE_FALSE_SWIPE); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize offensive options after Eject Pack")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        ASSUME_STAT_CHANGE(MOVE_GROWL, attack: -1);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_GROWL, MOVE_BOOMBURST); Speed(5); SpAttack(50); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Item(ITEM_EJECT_PACK); Moves(MOVE_SCRATCH); Speed(4); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_IRON_HEAD); Speed(4); SpDefense(50); }
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Ability(ABILITY_STATIC); Moves(MOVE_CHARGE_BEAM); Speed(6); SpDefense(53); }
    } WHEN {
            TURN { MOVE(player, MOVE_GROWL); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize defensive options after Eject Pack if mon outspeeds")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_OVERHEAT, self: TRUE, spAtk: -2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_WING_ATTACK, MOVE_BOOMBURST); Speed(5); SpAttack(50); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Item(ITEM_EJECT_PACK); Moves(MOVE_OVERHEAT); Speed(6); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_IRON_HEAD); Speed(4); SpDefense(50); }
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Ability(ABILITY_STATIC); Moves(MOVE_CHARGE_BEAM); Speed(6); SpDefense(53); }
    } WHEN {
            TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Mid-battle switches prioritize offensive options after Eject Pack if mon outspeeds but was Intimidate'd")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_PACK].holdEffect == HOLD_EFFECT_EJECT_PACK);
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_OVERHEAT, self: TRUE, spAtk: -2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_STARAPTOR) { Level(30); Ability(ABILITY_INTIMIDATE); Moves(MOVE_WING_ATTACK, MOVE_BOOMBURST); Speed(5); SpAttack(50); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Item(ITEM_EJECT_PACK); Moves(MOVE_OVERHEAT); Speed(6); } // Forces switchout
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_IRON_HEAD); Speed(4); SpDefense(50); }
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Ability(ABILITY_STATIC); Moves(MOVE_CHARGE_BEAM); Speed(6); SpDefense(53); }
    } WHEN {
            TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SWITCH(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Post-KO switches prioritize offensive options")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_SWELLOW) { Level(30); Moves(MOVE_WING_ATTACK, MOVE_BOOMBURST); Speed(5); }
        OPPONENT(SPECIES_PONYTA) { Level(1); Moves(MOVE_SCRATCH); Speed(4); }
        OPPONENT(SPECIES_ARON) { Level(30); Moves(MOVE_IRON_HEAD); Speed(4); } // Mid battle, AI sends out Aron
        OPPONENT(SPECIES_ELECTRODE) { Level(30); Ability(ABILITY_STATIC); Moves(MOVE_CHARGE_BEAM); Speed(6); }
    } WHEN {
            TURN { MOVE(player, MOVE_WING_ATTACK); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: Post-KO switches factor in Trick Room for revenge killing")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK_ROOM) == EFFECT_TRICK_ROOM);
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
        PLAYER(SPECIES_HITMONTOP) { Level(30); Moves(MOVE_CHARM, MOVE_SCRATCH); Ability(ABILITY_INTIMIDATE); Speed(5); }
        OPPONENT(SPECIES_GRIMER) { Level(30); Moves(MOVE_SCRATCH); Speed(4); }
        OPPONENT(SPECIES_PONYTA) { Level(30); Moves(MOVE_HEADBUTT); Speed(4); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not switch out if Pokemon would faint to hazards unless party member can clear them")
{
    enum Move move1;

    PARAMETRIZE { move1 = MOVE_SCRATCH; }
    PARAMETRIZE { move1 = MOVE_RAPID_SPIN; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_RAPID_SPIN) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_HEADBUTT) == DAMAGE_CATEGORY_PHYSICAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_HITMONTOP) { Level(30); Moves(MOVE_CHARM, MOVE_SCRATCH, MOVE_STEALTH_ROCK, MOVE_EARTHQUAKE); Ability(ABILITY_INTIMIDATE); Speed(5); }
        OPPONENT(SPECIES_GRIMER) { Level(30); Moves(MOVE_SCRATCH); Item(ITEM_FOCUS_SASH); Speed(4); }
        OPPONENT(SPECIES_PONYTA) { Level(30); Moves(MOVE_HEADBUTT, move1); Speed(4); }
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); }
        TURN { MOVE(player, MOVE_CHARM); }
        TURN { // If the AI has a mon that can remove hazards, don't prevent them switching out
            MOVE(player, MOVE_CHARM);
            if (move1 == MOVE_RAPID_SPIN)
                EXPECT_SWITCH(opponent, 1);
            else if (move1 == MOVE_SCRATCH)
                EXPECT_MOVE(opponent, MOVE_SCRATCH);
        }
    }
}

// Trapping behaviour
AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch in trapping mon mid battle")
{
    u32 flags = 0;
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING; }
    PASSES_RANDOMLY(SHOULD_SWITCH_TRAPPER_PERCENTAGE, 100, RNG_AI_SWITCH_TRAPPER);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_GOLURK, 0) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_GOLURK, 1) == TYPE_GHOST);
        AI_FLAGS(flags);
        PLAYER(SPECIES_ELECTRODE) { Speed(4); Moves(MOVE_THUNDERBOLT, MOVE_AURA_SPHERE, MOVE_PROTECT); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_SNORLAX) { Speed(1); Moves(MOVE_HEADBUTT); }
        OPPONENT(SPECIES_DUGTRIO) { Speed(3); Ability(ABILITY_ARENA_TRAP); Moves(MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_GOLURK) { Speed(5); Moves(MOVE_EARTHQUAKE); }
    } WHEN {
        if (flags & AI_FLAG_SMART_SWITCHING)
            TURN { MOVE(player, MOVE_AURA_SPHERE) ; EXPECT_SWITCH(opponent, 1); }
        else
            TURN { MOVE(player, MOVE_AURA_SPHERE) ; EXPECT_MOVE(opponent, MOVE_HEADBUTT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will switch in trapping mon after KO")
{
    u32 flags = 0; // Enables trapping behaviour after KOs
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; } // No trapping behaviour
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES; } // Traps with mid battle switches
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_MAWILE, 0) == TYPE_STEEL);
        AI_FLAGS(flags);
        PLAYER(SPECIES_MAWILE) { Speed(2); Moves(MOVE_PROTECT, MOVE_SCRATCH); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_SNORLAX) { Speed(3); Moves(MOVE_SELF_DESTRUCT); }
        OPPONENT(SPECIES_MAGNEZONE) { Speed(1); Ability(ABILITY_MAGNET_PULL); Moves(MOVE_SHOCK_WAVE); }
        OPPONENT(SPECIES_MEGANIUM) { Speed(3); Moves(MOVE_EARTH_POWER); }
    } WHEN {
        if (flags & AI_FLAG_SMART_MON_CHOICES)
            TURN{ MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_SELF_DESTRUCT); EXPECT_SEND_OUT(opponent, 1); }
        else
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_SELF_DESTRUCT); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI won't use trapping behaviour if player only has 1 mon left")
{
    u32 flags = 0; // Enables trapping behaviour after KOs
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT; } // No trapping behaviour
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES; } // Traps with mid battle switches
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_MAWILE, 0) == TYPE_STEEL);
        AI_FLAGS(flags);
        PLAYER(SPECIES_MAWILE) { Speed(2); Moves(MOVE_PROTECT, MOVE_SCRATCH); }
        OPPONENT(SPECIES_SNORLAX) { Speed(3); Moves(MOVE_SELF_DESTRUCT); }
        OPPONENT(SPECIES_MAGNEZONE) { Speed(1); Ability(ABILITY_MAGNET_PULL); Moves(MOVE_SHOCK_WAVE); }
        OPPONENT(SPECIES_MEGANIUM) { Speed(3); Moves(MOVE_EARTH_POWER); }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_SELF_DESTRUCT); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will trap player using Trace if player has a trapper")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_TRAPPER_PERCENTAGE, 100, RNG_AI_SWITCH_TRAPPER);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_DUGTRIO) { Ability(ABILITY_ARENA_TRAP); Moves(MOVE_ROCK_TOMB); }
        PLAYER(SPECIES_DUGTRIO);
        OPPONENT(SPECIES_GENGAR);
        OPPONENT(SPECIES_PORYGON2) { Ability(ABILITY_TRACE); Item(ITEM_EVIOLITE); Moves(MOVE_ICE_BEAM); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_TOMB); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if mon would be OKHO'd and they have a good switchin 50% of the time")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_HASBADODDS_PERCENTAGE, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_RHYDON, 0) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_PELIPPER, 0) == TYPE_WATER);
        ASSUME(GetSpeciesType(SPECIES_PELIPPER, 1) == TYPE_FLYING);
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);

        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ELECTRODE) { Moves(MOVE_THUNDERBOLT, MOVE_THUNDER_WAVE, MOVE_THUNDER_SHOCK); }
        OPPONENT(SPECIES_PELIPPER) { Moves(MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_RHYDON) { Moves(MOVE_EARTHQUAKE); Ability(ABILITY_ROCK_HEAD); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI will switch out if it can't deal damage to a mon with Wonder Guard")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_WONDER_GUARD_PERCENTAGE, 100, RNG_AI_SWITCH_WONDER_GUARD);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SHEDINJA, 0) == TYPE_BUG);
        ASSUME(GetSpeciesType(SPECIES_SHEDINJA, 1) == TYPE_GHOST);
        ASSUME(GetSpeciesAbility(SPECIES_SHEDINJA, 0) == ABILITY_WONDER_GUARD);
        ASSUME(GetSpeciesAbility(SPECIES_SHEDINJA, 1) == ABILITY_NONE);
        ASSUME(GetSpeciesAbility(SPECIES_SHEDINJA, 2) == ABILITY_NONE);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_SHEDINJA) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it can't deal damage to a mon with Wonder Guard")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_WONDER_GUARD_PERCENTAGE, 100, RNG_AI_SWITCH_WONDER_GUARD);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SHEDINJA, 0) == TYPE_BUG);
        ASSUME(GetSpeciesType(SPECIES_SHEDINJA, 1) == TYPE_GHOST);
        ASSUME(GetSpeciesAbility(SPECIES_SHEDINJA, 0) == ABILITY_WONDER_GUARD);
        ASSUME(GetSpeciesAbility(SPECIES_SHEDINJA, 1) == ABILITY_NONE);
        ASSUME(GetSpeciesAbility(SPECIES_SHEDINJA, 2) == ABILITY_NONE);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_SHADOW_BALL) == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SHEDINJA) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been Toxic'd for at least two turns 50% of the time with more than 1/3 HP remaining with good switchin")
{
    enum Species species = SPECIES_NONE;
    u32 odds = 0;
    PARAMETRIZE { species = SPECIES_ZIGZAGOON, odds = 0; }
    PARAMETRIZE { species = SPECIES_HARIYAMA, odds = SHOULD_SWITCH_BADLY_POISONED_PERCENTAGE; }
    PASSES_RANDOMLY(odds, 100, RNG_AI_SWITCH_BADLY_POISONED);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        ASSUME(GetMovePower(MOVE_AURA_SPHERE) == 80); // Gen 5's 90 power causes too much damage
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH, MOVE_CELEBRATE, MOVE_TOXIC, MOVE_AURA_SPHERE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(species) { Moves(MOVE_ROCK_SMASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_AURA_SPHERE); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_AURA_SPHERE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been Curse'd 50% of the time")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_CURSED_PERCENTAGE, 100, RNG_AI_SWITCH_CURSED);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CURSE) == EFFECT_CURSE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_DUSCLOPS) { Moves(MOVE_FIRE_PUNCH, MOVE_CURSE); }
        PLAYER(SPECIES_MILOTIC) { Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_DUSCLOPS) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_DUSCLOPS) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_CURSE) ; EXPECT_MOVE(opponent, MOVE_SHADOW_BALL); }
        TURN { MOVE(player, MOVE_FIRE_PUNCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been Nightmare'd 33% of the time")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_NIGHTMARE_PERCENTAGE, 100, RNG_AI_SWITCH_NIGHTMARE);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NIGHTMARE) == EFFECT_NIGHTMARE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_GENGAR) { Moves(MOVE_NIGHTMARE); }
        OPPONENT(SPECIES_DUSCLOPS) { Moves(MOVE_SHADOW_BALL); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_DUSCLOPS) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_NIGHTMARE) ; EXPECT_MOVE(opponent, MOVE_SHADOW_BALL); }
        TURN { MOVE(player, MOVE_NIGHTMARE) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been Leech Seed'd 25% of the time")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_SEEDED_PERCENTAGE, 100, RNG_AI_SWITCH_SEEDED);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_LEECH_SEED) == EFFECT_LEECH_SEED);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_WHIMSICOTT) { Moves(MOVE_LEECH_SEED); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_LEECH_SEED) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_LEECH_SEED); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been infatuated")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_INFATUATION_PERCENTAGE, 100, RNG_AI_SWITCH_INFATUATION);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_LUVDISC) { Moves(MOVE_ATTRACT); Gender(MON_FEMALE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); Gender(MON_MALE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); Gender(MON_MALE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ATTRACT) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_ATTRACT) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been Yawn'd with more than 1/3 HP remaining and it has a good switchin")
{
    u32 hp;
    PARAMETRIZE { hp = 30; }
    PARAMETRIZE { hp = 10; }
    PASSES_RANDOMLY(SHOULD_SWITCH_YAWN_PERCENTAGE, 100, RNG_AI_SWITCH_YAWN);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH, MOVE_YAWN); }
        OPPONENT(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH); HP(hp); MaxHP(30); }
        OPPONENT(SPECIES_SLAKOTH) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { MOVE(player, MOVE_YAWN) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        if (hp == 30)
            TURN { MOVE(player, MOVE_YAWN) ; EXPECT_SWITCH(opponent, 1); }
        else
            TURN { MOVE(player, MOVE_YAWN) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not switch out if it has been Yawn'd with more than 1/3 HP remaining and it does not have a good switchin")
{
    u32 hp;
    PARAMETRIZE { hp = 30; }
    PARAMETRIZE { hp = 10; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH, MOVE_YAWN); }
        OPPONENT(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH); HP(hp); MaxHP(30); }
        OPPONENT(SPECIES_SLAKOTH) { Level(1); Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { MOVE(player, MOVE_YAWN) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SCRATCH) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been Yawn'd with more than 1/3 HP remaining (Doubles)")
{
    u32 hp;
    PARAMETRIZE { hp = 30; }
    PARAMETRIZE { hp = 10; }
    PASSES_RANDOMLY(SHOULD_SWITCH_YAWN_PERCENTAGE, 100, RNG_AI_SWITCH_YAWN);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH, MOVE_CELEBRATE, MOVE_YAWN); }
        PLAYER(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH, MOVE_CELEBRATE, MOVE_YAWN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); HP(hp); MaxHP(30); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_YAWN, target: opponentLeft); MOVE(playerRight, MOVE_CELEBRATE, target: opponentLeft); }
        if (hp == 30)
            TURN { MOVE(playerLeft, MOVE_YAWN, target: opponentLeft); MOVE(playerRight, MOVE_CELEBRATE, target: opponentLeft); EXPECT_SWITCH(opponentLeft, 2); }
        else
            TURN { MOVE(playerLeft, MOVE_YAWN, target: opponentLeft); MOVE(playerRight, MOVE_CELEBRATE, target: opponentLeft); EXPECT_MOVE(opponentLeft, MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if player's mon is semi-invulnerable and it has a good switchin")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_FREE_TURN_PERCENTAGE, 100, RNG_AI_SWITCH_FREE_TURN);
    GIVEN {
        ASSUME(GetMoveType(MOVE_DIVE) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_LUVDISC) { Level(50); Moves(MOVE_DIVE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_PIKACHU) { Moves(MOVE_THUNDERBOLT); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { SKIP_TURN(player); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out on turn 1 if it predicts a semi-invulnerable move and it has a good switchin")
{
    PASSES_RANDOMLY(PREDICT_MOVE_CHANCE, 100, RNG_AI_PREDICT_MOVE);
    PASSES_RANDOMLY(SHOULD_SWITCH_FREE_TURN_PERCENTAGE, 100, RNG_AI_SWITCH_FREE_TURN);
    GIVEN {
        ASSUME(GetMoveType(MOVE_DIVE) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT | AI_FLAG_PREDICT_MOVE);
        PLAYER(SPECIES_LUVDISC) { Level(50); Moves(MOVE_DIVE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_PIKACHU) { Moves(MOVE_THUNDERBOLT); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIVE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has an absorber but current mon has SE move 33% of the time")
{
    PASSES_RANDOMLY(33, 100, RNG_AI_SWITCH_ABSORBING_STAY_IN);
    GIVEN {
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_LUVDISC) { Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SHOCK_WAVE); }
        OPPONENT(SPECIES_MANTINE) { Moves(MOVE_SCRATCH); Ability(ABILITY_WATER_ABSORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN) ; EXPECT_MOVE(opponent, MOVE_SHOCK_WAVE); }
        TURN { MOVE(player, MOVE_WATER_GUN) ; EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if player's mon is charging and it has an absorber")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ABSORBS_MOVE_PERCENTAGE, 100, RNG_AI_SWITCH_ABSORBING);
    GIVEN {
        ASSUME(GetMoveType(MOVE_SOLAR_BEAM) == TYPE_GRASS);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_BELLOSSOM) { Moves(MOVE_SOLAR_BEAM, MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_AZUMARILL) { Moves(MOVE_PLAY_ROUGH); Ability(ABILITY_SAP_SIPPER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { SKIP_TURN(player); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if player's mon is charging and it has a good switchin immunity (type)")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_FREE_TURN_PERCENTAGE, 100, RNG_AI_SWITCH_FREE_TURN);
    GIVEN {
        ASSUME(GetMoveType(MOVE_DIG) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SANDSHREW) { Moves(MOVE_DIG); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_SWELLOW) { Moves(MOVE_WING_ATTACK); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIG) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { SKIP_TURN(player); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if player's mon is charging and it has a good switchin immunity (ability)")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ABSORBS_MOVE_PERCENTAGE, 100, RNG_AI_SWITCH_ABSORBING);
    GIVEN {
        ASSUME(GetMoveType(MOVE_DIG) == TYPE_GROUND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SANDSHREW) { Moves(MOVE_DIG); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_BRONZONG) { Moves(MOVE_PSYCHIC); Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DIG) ; EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { SKIP_TURN(player); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has an absorber and current mon loses the 1v1")
{
    u32 aiMon;
    enum Move move;
    enum Ability absorbingAbility;
    PARAMETRIZE { aiMon = SPECIES_NINETALES; absorbingAbility = ABILITY_FLASH_FIRE; move = MOVE_FLAMETHROWER; }
    PARAMETRIZE { aiMon = SPECIES_DACHSBUN;  absorbingAbility = ABILITY_WELL_BAKED_BODY; move = MOVE_FLAMETHROWER; }
    PARAMETRIZE { aiMon = SPECIES_MANTINE;   absorbingAbility = ABILITY_WATER_ABSORB; move = MOVE_SURF; }
    PARAMETRIZE { aiMon = SPECIES_TOXICROAK; absorbingAbility = ABILITY_DRY_SKIN; move = MOVE_SURF; }
    PARAMETRIZE { aiMon = SPECIES_GASTRODON; absorbingAbility = ABILITY_STORM_DRAIN; move = MOVE_SURF; }
    PARAMETRIZE { aiMon = SPECIES_JOLTEON; absorbingAbility = ABILITY_VOLT_ABSORB; move = MOVE_THUNDERBOLT; }
    PARAMETRIZE { aiMon = SPECIES_ELECTIVIRE; absorbingAbility = ABILITY_MOTOR_DRIVE; move = MOVE_THUNDERBOLT; }
    PARAMETRIZE { aiMon = SPECIES_MANECTRIC; absorbingAbility = ABILITY_LIGHTNING_ROD; move = MOVE_THUNDERBOLT; }
    PARAMETRIZE { aiMon = SPECIES_AZUMARILL; absorbingAbility = ABILITY_SAP_SIPPER; move = MOVE_GIGA_DRAIN; }
    PARAMETRIZE { aiMon = SPECIES_ORTHWORM; absorbingAbility = ABILITY_EARTH_EATER; move = MOVE_EARTHQUAKE; }
    PARAMETRIZE { aiMon = SPECIES_BRONZONG; absorbingAbility = ABILITY_LEVITATE; move = MOVE_EARTHQUAKE; }
    PARAMETRIZE { aiMon = SPECIES_ELECTRODE; absorbingAbility = ABILITY_SOUNDPROOF; move = MOVE_HYPER_VOICE; }
    PARAMETRIZE { aiMon = SPECIES_CHESNAUGHT; absorbingAbility = ABILITY_BULLETPROOF; move = MOVE_SLUDGE_BOMB; }
    PARAMETRIZE { aiMon = SPECIES_BRAMBLEGHAST; absorbingAbility = ABILITY_WIND_RIDER; move = MOVE_HURRICANE; }
    PARAMETRIZE { aiMon = SPECIES_BRAMBLEGHAST; absorbingAbility = ABILITY_WIND_RIDER; move = MOVE_HEAT_WAVE; }
    PARAMETRIZE { aiMon = SPECIES_SHELLDER; absorbingAbility = ABILITY_OVERCOAT; move = MOVE_MAGIC_POWDER; }
    PARAMETRIZE { aiMon = SPECIES_SHELLDER; absorbingAbility = ABILITY_OVERCOAT; move = MOVE_STUN_SPORE; }
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        WITH_CONFIG(B_POWDER_OVERCOAT, GEN_6);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(move, MOVE_STRENGTH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(aiMon) { Moves(MOVE_SCRATCH); Ability(absorbingAbility); }
    } WHEN {
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, move); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if opponent uses two-turn move and it has a switchin that wins 1v1")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_SKY_ATTACK; }
    PARAMETRIZE { move = MOVE_FLY; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        ASSUME(GetMoveEffect(MOVE_SKY_ATTACK) == EFFECT_TWO_TURNS_ATTACK);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_SWELLOW) { Moves(move); }
        OPPONENT(SPECIES_MILOTIC) { Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_LAIRON) { Moves(MOVE_ROCK_SLIDE); }
    } WHEN {
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, MOVE_WATER_GUN); }
        TURN { SKIP_TURN(player); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI will switch out if badly statused with >= 50% HP remaining and has Natural Cure and a good switchin 66% of the time")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_NATURAL_CURE_STRONG_PERCENTAGE, 100, RNG_AI_SWITCH_NATURAL_CURE);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ODDISH) { Moves(MOVE_TOXIC, MOVE_SCRATCH); }
        OPPONENT(SPECIES_SWABLU) { Ability(ABILITY_NATURAL_CURE); Moves(MOVE_SCRATCH, MOVE_PECK); }
        OPPONENT(SPECIES_SWABLU) { Ability(ABILITY_NATURAL_CURE); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); EXPECT_MOVE(opponent, MOVE_PECK); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI will switch out if it has <= 66% HP remaining and has Regenerator and a good switchin 50% of the time")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_REGENERATOR_PERCENTAGE, 100, RNG_AI_SWITCH_REGENERATOR);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_SLOWBRO) { MaxHP(100); HP(65); Ability(ABILITY_REGENERATOR); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_SLOWBRO) { Ability(ABILITY_REGENERATOR); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out to cycle Intimidate when facing a physical attacker")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_INTIMIDATE_PERCENTAGE, 100, RNG_AI_SWITCH_INTIMIDATE);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not cycle Intimidate when target blocks or punishes Attack drops")
{
    enum Species Species = SPECIES_NONE;
    enum Ability ability;
    PARAMETRIZE { Species = SPECIES_TENTACRUEL; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { Species = SPECIES_BRAVIARY; ability = ABILITY_DEFIANT; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(Species) { Ability(ability); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not cycle Intimidate when target is a special attacker")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); EXPECT_MOVE(opponent, MOVE_TACKLE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out to cycle Intimidate in doubles when at least one target is valid")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_INTIMIDATE_PERCENTAGE, 100, RNG_AI_SWITCH_INTIMIDATE);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentRight); EXPECT_SWITCH(opponentLeft, 2); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not cycle Intimidate in doubles when both targets block Attack drops")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_TENTACRUEL) { Ability(ABILITY_CLEAR_BODY); Moves(MOVE_TACKLE); }
        PLAYER(SPECIES_KINGLER) { Ability(ABILITY_HYPER_CUTTER); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); MOVE(playerRight, MOVE_TACKLE, target: opponentRight); EXPECT_MOVE(opponentLeft, MOVE_TACKLE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not cycle Intimidate in doubles when one target punishes stat drops")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_BRAVIARY) { Ability(ABILITY_DEFIANT); Moves(MOVE_TACKLE); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); MOVE(playerRight, MOVE_TACKLE, target: opponentRight); EXPECT_MOVE(opponentLeft, MOVE_TACKLE); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will not cycle Intimidate in doubles when both targets are special attackers")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_WATER_GUN); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ARCANINE) { Ability(ABILITY_INTIMIDATE); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentRight); EXPECT_MOVE(opponentLeft, MOVE_TACKLE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if it has been Encore'd into a status move")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ENCORE_STATUS_PERCENTAGE, 100, RNG_AI_SWITCH_ENCORE);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_AZURILL) { Moves(MOVE_SCRATCH, MOVE_ENCORE); }
        OPPONENT(SPECIES_ODDISH) { Moves(MOVE_TOXIC, MOVE_SWEET_SCENT, MOVE_INGRAIN, MOVE_SCRATCH); }
        OPPONENT(SPECIES_ARON) { Moves(MOVE_METAL_CLAW); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_TOXIC); MOVE(player, MOVE_ENCORE); }
        TURN { MOVE(player, MOVE_ENCORE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will stay in if Encore'd into super effective move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        ASSUME(GetSpeciesType(SPECIES_AZURILL, 0) == TYPE_NORMAL);
        ASSUME(GetSpeciesType(SPECIES_AZURILL, 1) == TYPE_FAIRY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_AZURILL) { Moves(MOVE_SCRATCH, MOVE_ENCORE); }
        OPPONENT(SPECIES_ODDISH) { Moves(MOVE_ACID); }
        OPPONENT(SPECIES_ARON) { Moves(MOVE_METAL_CLAW); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_ACID); MOVE(player, MOVE_ENCORE); }
        TURN { EXPECT_MOVE(opponent, MOVE_ACID); MOVE(player, MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if Encore'd into neutral move with good switchin 50% of the time")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ENCORE_DAMAGE_PERCENTAGE, 100, RNG_AI_SWITCH_ENCORE);
    GIVEN {
        WITH_CONFIG(B_ENCORE_TARGET, GEN_3);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_AZURILL) { Moves(MOVE_SCRATCH, MOVE_ENCORE); }
        OPPONENT(SPECIES_ODDISH) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ARON) { Moves(MOVE_METAL_CLAW); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_ENCORE); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if Encore'd into neutral move with good switchin 50% of the time (Gen 5+)")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ENCORE_DAMAGE_PERCENTAGE, 100, RNG_AI_SWITCH_ENCORE);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_AZURILL) { Moves(MOVE_SCRATCH, MOVE_ENCORE); }
        OPPONENT(SPECIES_ODDISH) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ARON) { Moves(MOVE_METAL_CLAW); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_ENCORE); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI will switch out if mon has Truant and opponent has Protect")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_TRUANT_PERCENTAGE, 100, RNG_AI_SWITCH_TRUANT);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ARON) { Moves(MOVE_SCRATCH, MOVE_PROTECT); }
        OPPONENT(SPECIES_SLAKING) { Ability(ABILITY_TRUANT); Moves(MOVE_BRICK_BREAK); }
        OPPONENT(SPECIES_ARON) { Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_BRICK_BREAK); MOVE(player, MOVE_PROTECT); }
        TURN { EXPECT_SWITCH(opponent, 1); MOVE(player, MOVE_SCRATCH); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI will switch out if mon has Truant and opponent has invulnerability move and is faster")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_TRUANT_PERCENTAGE, 100, RNG_AI_SWITCH_TRUANT);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_SWELLOW) { Speed(5); Moves(MOVE_FLY); }
        OPPONENT(SPECIES_SLAKING) { Speed(4); Ability(ABILITY_TRUANT); Moves(MOVE_ROCK_SLIDE); }
        OPPONENT(SPECIES_ARON) { Speed(4); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLY); EXPECT_MOVE(opponent, MOVE_ROCK_SLIDE); }
        TURN { SKIP_TURN(player); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if main attacking stat lowered by 2 stages with good switchin candidate 50% of the time")
{
    enum Species aiSpecies = SPECIES_NONE;
    enum Move aiMove = MOVE_NONE, move = MOVE_NONE;

    PASSES_RANDOMLY(SHOULD_SWITCH_ATTACKING_STAT_MINUS_TWO_PERCENTAGE, 100, RNG_AI_SWITCH_STATS_LOWERED);
    PARAMETRIZE { move = MOVE_CHARM; aiSpecies = SPECIES_FLAREON; aiMove = MOVE_FIRE_FANG; }
    PARAMETRIZE { move = MOVE_EERIE_IMPULSE; aiSpecies = SPECIES_ESPEON; aiMove = MOVE_CONFUSION; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        ASSUME_STAT_CHANGE(MOVE_EERIE_IMPULSE, spAtk: -2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_ARON) { Moves(move, MOVE_SCRATCH); }
        OPPONENT(aiSpecies) { Moves(aiMove); }
        OPPONENT(SPECIES_MILOTIC) { Moves(MOVE_SURF); }
    } WHEN {
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, aiMove); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if main attacking stat lowered by 3+ stages")
{
    enum Species aiSpecies = SPECIES_NONE;
    enum Move aiMove = MOVE_NONE, move = MOVE_NONE, move2 = MOVE_NONE;

    PASSES_RANDOMLY(SHOULD_SWITCH_ATTACKING_STAT_MINUS_THREE_PLUS_PERCENTAGE, 100, RNG_AI_SWITCH_STATS_LOWERED);
    PARAMETRIZE { move = MOVE_GROWL; move2 = MOVE_CHARM; aiSpecies = SPECIES_FLAREON; aiMove = MOVE_FIRE_FANG; }
    PARAMETRIZE { move = MOVE_CONFIDE; move2 = MOVE_EERIE_IMPULSE; aiSpecies = SPECIES_ESPEON; aiMove = MOVE_STORED_POWER; }

    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_CHARM, attack: -2);
        ASSUME_STAT_CHANGE(MOVE_EERIE_IMPULSE, spAtk: -2);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_ARON) { Moves(move, move2, MOVE_SCRATCH); }
        OPPONENT(aiSpecies) { Moves(aiMove); }
        OPPONENT(SPECIES_MILOTIC) { Moves(MOVE_SURF); }
    } WHEN {
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, aiMove); }
        TURN { MOVE(player, move2); EXPECT_MOVE(opponent, aiMove); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI correctly handles abilities when scoring moves")
{
    GIVEN {
        WITH_CONFIG(B_PRANKSTER_DARK_TYPES, GEN_7);
        ASSUME(GetSpeciesType(SPECIES_GRENINJA, 1) == TYPE_DARK);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_GRENINJA) { Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WHIMSICOTT) { Ability(ABILITY_PRANKSTER); Moves(MOVE_LEECH_SEED, MOVE_STUN_SPORE, MOVE_ABSORB); }
        OPPONENT(SPECIES_WHIMSICOTT) { Ability(ABILITY_INFILTRATOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); EXPECT_MOVE(opponent, MOVE_ABSORB); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI won't switch out if Yawn'd with only Ace mon remaining")
{
    u32 flags;
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_SMART_SWITCHING | AI_FLAG_ACE_POKEMON; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(flags);
        PLAYER(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH, MOVE_YAWN); }
        OPPONENT(SPECIES_SLAKOTH) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_SLAKOTH) { Moves(MOVE_HEADBUTT); }
    } WHEN {
        TURN { MOVE(player, MOVE_YAWN); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        if (flags & AI_FLAG_ACE_POKEMON)
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        else
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI won't switch in ace mon after U-Turn if other options available")
{
    u32 flags;
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_SMART_SWITCHING; }
    PARAMETRIZE { flags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ACE_POKEMON | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_SMART_SWITCHING; }
    GIVEN {
        AI_FLAGS(flags);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SURF); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_U_TURN); }
        OPPONENT(SPECIES_NUMEL) { Level(5); Moves(MOVE_SPLASH); }
        OPPONENT(SPECIES_SCIZOR) { Moves(MOVE_BUG_BITE); }
    } WHEN {
        if (flags & AI_FLAG_ACE_POKEMON)
            TURN { EXPECT_MOVE(opponent, MOVE_U_TURN); EXPECT_SEND_OUT(opponent, 1); MOVE(player, MOVE_SURF); }
        else
            TURN { EXPECT_MOVE(opponent, MOVE_U_TURN); EXPECT_SEND_OUT(opponent, 2); MOVE(player, MOVE_SURF); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI won't switch in ace mon after U-Turn if other options available")
{
    u32 flag;
    PARAMETRIZE{ flag = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT; }
    PARAMETRIZE{ flag = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ACE_POKEMON | AI_FLAG_CHECK_VIABILITY | AI_FLAG_OMNISCIENT; }
    GIVEN {
        AI_FLAGS(flag);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SURF); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_U_TURN); }
        OPPONENT(SPECIES_NUMEL) { Level(5); Moves(MOVE_SPLASH); }
        OPPONENT(SPECIES_SCIZOR) { Moves(MOVE_BUG_BITE); }
    } WHEN {
        if (flag & AI_FLAG_ACE_POKEMON)
            TURN { EXPECT_MOVE(opponent, MOVE_U_TURN); EXPECT_SEND_OUT(opponent, 1); MOVE(player, MOVE_SURF); }
        else
            TURN { EXPECT_MOVE(opponent, MOVE_U_TURN); EXPECT_SEND_OUT(opponent, 2); MOVE(player, MOVE_SURF); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI won't switch in absorbing mon immediately after sending out new mon")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_BLAZIKEN) { Moves(MOVE_FLAMETHROWER, MOVE_CLOSE_COMBAT); }
        OPPONENT(SPECIES_FERROTHORN) { Moves(MOVE_GYRO_BALL); }
        OPPONENT(SPECIES_DIALGA) { Moves(MOVE_DRACO_METEOR); }
        OPPONENT(SPECIES_HEATRAN) { Moves(MOVE_EARTH_POWER, MOVE_FLAMETHROWER); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLAMETHROWER); EXPECT_SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_CLOSE_COMBAT); EXPECT_MOVE(opponent, MOVE_DRACO_METEOR); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will consider choice-locked player when determining which mon to send out")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_JOLTEON) { Speed(5); Moves(MOVE_EARTHQUAKE, MOVE_THUNDERBOLT); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); HP(1); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_MACHAMP) { Speed(4); Moves(MOVE_REVENGE); }
        OPPONENT(SPECIES_GYARADOS) { Speed(4); Moves(MOVE_EARTHQUAKE); }
    } WHEN {
        TURN { MOVE(player, MOVE_EARTHQUAKE); EXPECT_MOVE(opponent, MOVE_TACKLE); item == ITEM_NONE ? EXPECT_SEND_OUT(opponent, 1) : EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if all moves deal zero damage")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_SCORES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_SCORES_BAD);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(GetMoveEffect(MOVE_POLTERGEIST) == EFFECT_POLTERGEIST);
        ASSUME(GetMoveType(MOVE_SCALD) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_MANTINE, 1) == TYPE_FLYING);
        ASSUME(GetItemHoldEffect(ITEM_WATER_GEM) == HOLD_EFFECT_GEMS);
        ASSUME(GetItemSecondaryId(ITEM_WATER_GEM) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_MANTINE) { Speed(5); Moves(MOVE_ROOST, MOVE_SCALD); Ability(ABILITY_WATER_VEIL); Item(ITEM_WATER_GEM); }
        OPPONENT(SPECIES_DUSKNOIR) { Speed(6); Moves(MOVE_WILL_O_WISP, MOVE_POLTERGEIST, MOVE_EARTHQUAKE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(6); Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_POLTERGEIST); MOVE(player, MOVE_SCALD); }
        TURN { EXPECT_SWITCH(opponent, 1); MOVE(player, MOVE_ROOST); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will switch out if all moves deal zero damage (absorbing ability)")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_SCORES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_SCORES_BAD);
    GIVEN {
        ASSUME(GetMoveType(MOVE_THUNDER_PUNCH) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_FAKE_OUT) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_RETURN) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_DRAIN_PUNCH) == TYPE_FIGHTING);
        ASSUME(gSpeciesInfo[SPECIES_MAROWAK_ALOLA].types[1] == TYPE_GHOST);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_MAROWAK_ALOLA) { Ability(ABILITY_LIGHTNING_ROD); Moves(MOVE_SHADOW_BONE); }
        OPPONENT(SPECIES_LOPUNNY) { Moves(MOVE_FAKE_OUT, MOVE_RETURN, MOVE_DRAIN_PUNCH, MOVE_THUNDER_PUNCH); Ability(ABILITY_LIMBER); }
        OPPONENT(SPECIES_CHANDELURE) { Moves(MOVE_SHADOW_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHADOW_BONE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: AI will switch out if Palafin-Zero isn't transformed yet")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_FINIZEN);
        OPPONENT(SPECIES_PALAFIN_ZERO);
        OPPONENT(SPECIES_FINIZEN);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: Palafin-Hero does not switch to activate Zero to Hero again (Single)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GLISCOR) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PALAFIN_HERO) { Ability(ABILITY_ZERO_TO_HERO); Moves(MOVE_JET_PUNCH); }
        OPPONENT(SPECIES_GLISCOR) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_JET_PUNCH); }
    }
}

AI_DOUBLE_BATTLE_TEST("Switch AI: Palafin-Hero does not switch to activate Zero to Hero again (Doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GLISCOR) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_GLISCOR) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PALAFIN_HERO) { Ability(ABILITY_ZERO_TO_HERO); Moves(MOVE_JET_PUNCH); }
        OPPONENT(SPECIES_GLISCOR) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GLISCOR) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE);
            MOVE(playerRight, MOVE_CELEBRATE);
            EXPECT_MOVE(opponentLeft, MOVE_JET_PUNCH);
            EXPECT_MOVE(opponentRight, MOVE_CELEBRATE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: Palafin uses Flip Turn when faster to transform (Single)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GLISCOR) { Speed(10); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(20); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_FLIP_TURN); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("Switch AI: Palafin uses Flip Turn when faster to transform (Doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GLISCOR) { Speed(10); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_GLISCOR) { Speed(15); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(20); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(5); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(4); Moves(MOVE_TACKLE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, target:opponentLeft);
            MOVE(playerRight, MOVE_CELEBRATE, target:opponentLeft);
            EXPECT_MOVE(opponentLeft, MOVE_FLIP_TURN, target:playerLeft);
            EXPECT_MOVE(opponentRight, MOVE_CELEBRATE);
            EXPECT_SEND_OUT(opponentLeft, 2);
        }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: Palafin hard switches when slower even with Flip Turn (Single)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GLISCOR) { Speed(30); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(10); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("Switch AI: Palafin hard switches when slower even with Flip Turn (Doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GLISCOR) { Speed(25); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_GLISCOR) { Speed(15); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(10); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(8); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(7); Moves(MOVE_TACKLE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, target:opponentLeft);
            MOVE(playerRight, MOVE_CELEBRATE, target:opponentLeft);
            EXPECT_SWITCH(opponentLeft, 2);
            EXPECT_MOVE(opponentRight, MOVE_CELEBRATE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: Palafin hard switches into absorb abilities instead of Flip Turn (Single)")
{
    enum Species palafinAbsorbSpecies;
    enum Ability palafinAbsorbAbility;
    PARAMETRIZE { palafinAbsorbSpecies = SPECIES_GASTRODON; palafinAbsorbAbility = ABILITY_STORM_DRAIN; }
    PARAMETRIZE { palafinAbsorbSpecies = SPECIES_VAPOREON;  palafinAbsorbAbility = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { palafinAbsorbSpecies = SPECIES_PARASECT;  palafinAbsorbAbility = ABILITY_DRY_SKIN; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(palafinAbsorbSpecies) { Speed(10); Ability(palafinAbsorbAbility); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(20); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(8); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("Switch AI: Palafin hard switches into absorb abilities instead of Flip Turn (Doubles)")
{
    enum Species palafinAbsorbSpecies;
    enum Ability palafinAbsorbAbility;
    PARAMETRIZE { palafinAbsorbSpecies = SPECIES_GASTRODON; palafinAbsorbAbility = ABILITY_STORM_DRAIN; }
    PARAMETRIZE { palafinAbsorbSpecies = SPECIES_VAPOREON;  palafinAbsorbAbility = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { palafinAbsorbSpecies = SPECIES_PARASECT;  palafinAbsorbAbility = ABILITY_DRY_SKIN; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(palafinAbsorbSpecies) { Speed(5); Ability(palafinAbsorbAbility); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_GLISCOR) { Speed(4); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(20); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(8); }
    } WHEN {
        if (palafinAbsorbAbility == ABILITY_STORM_DRAIN)
        {
            TURN {
                MOVE(playerLeft, MOVE_CELEBRATE, target:opponentLeft);
                MOVE(playerRight, MOVE_CELEBRATE, target:opponentLeft);
                EXPECT_SWITCH(opponentLeft, 2);
                EXPECT_MOVE(opponentRight, MOVE_CELEBRATE);
            }
        }
        else
        {
            TURN {
                MOVE(playerLeft, MOVE_CELEBRATE, target:opponentLeft);
                MOVE(playerRight, MOVE_CELEBRATE, target:opponentLeft);
                EXPECT_MOVE(opponentLeft, MOVE_FLIP_TURN, target:playerRight);
                EXPECT_SEND_OUT(opponentLeft, 2);
                EXPECT_MOVE(opponentRight, MOVE_CELEBRATE);
            }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Switch AI: Palafin hard switches under harsh sunlight (Single)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GROUDON_PRIMAL) { Speed(15); Ability(ABILITY_DESOLATE_LAND); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(20); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("Switch AI: Palafin hard switches under harsh sunlight (Doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_GROUDON_PRIMAL) { Speed(18); Ability(ABILITY_DESOLATE_LAND); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_GLISCOR) { Speed(16); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); Speed(20); Moves(MOVE_FLIP_TURN, MOVE_TACKLE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(6); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_GLISCOR) { Speed(7); Moves(MOVE_TACKLE); }
    } WHEN {
        TURN {
            MOVE(playerLeft, MOVE_CELEBRATE, target:opponentLeft);
            MOVE(playerRight, MOVE_CELEBRATE, target:opponentLeft);
            EXPECT_SWITCH(opponentLeft, 2);
            EXPECT_MOVE(opponentRight, MOVE_CELEBRATE);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI won't send out defensive mon that can lose 1v1, or switch out a mon that can win 1v1 even with bad type matchup")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_PANPOUR) {
            Level(15);
            Moves(MOVE_WATER_PULSE, MOVE_PLAY_NICE, MOVE_FURY_SWIPES, MOVE_LICK);
            Item(ITEM_MYSTIC_WATER);
            Ability(ABILITY_GLUTTONY);
            Nature(NATURE_MODEST);
            HPIV(31);
            AttackIV(31);
            DefenseIV(31);
            SpAttackIV(31);
            SpDefenseIV(31);
            SpeedIV(31); }
        OPPONENT(SPECIES_RHYHORN) {
            Level(14);
            Moves(MOVE_ROCK_TOMB, MOVE_HORN_ATTACK, MOVE_BULLDOZE, MOVE_ROCK_SMASH);
            Item(ITEM_RINDO_BERRY);
            Ability(ABILITY_LIGHTNING_ROD);
            Nature(NATURE_ADAMANT);
            HPIV(31);
            AttackIV(31);
            DefenseIV(31);
            SpAttackIV(31);
            SpDefenseIV(31);
            SpeedIV(31); }
        OPPONENT(SPECIES_GLIGAR) {
            Level(15);
            Moves(MOVE_WING_ATTACK, MOVE_QUICK_ATTACK, MOVE_BULLDOZE);
            Item(ITEM_ORAN_BERRY);
            Ability(ABILITY_SAND_VEIL);
            Nature(NATURE_ADAMANT);
            HPIV(31);
            AttackIV(31);
            DefenseIV(31);
            SpAttackIV(31);
            SpDefenseIV(31);
            SpeedIV(31); }
        OPPONENT(SPECIES_WOOPER_PALDEA) {
            Level(15);
            Moves(MOVE_MUD_SHOT, MOVE_ACID_SPRAY, MOVE_YAWN, MOVE_SANDSTORM);
            Item(ITEM_ORAN_BERRY);
            Ability(ABILITY_WATER_ABSORB);
            Nature(NATURE_MODEST);
            HPIV(31);
            AttackIV(31);
            DefenseIV(31);
            SpAttackIV(31);
            SpDefenseIV(31);
            SpeedIV(31); }
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_PULSE); EXPECT_MOVE(opponent, MOVE_BULLDOZE); EXPECT_SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_WATER_PULSE); EXPECT_MOVE(opponent, MOVE_BULLDOZE); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI considers 0 hits to KO as losing a 1v1")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_JOLTEON) { Level(100); Ability(ABILITY_VOLT_ABSORB); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); HP(1); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_TANGELA) { Level(100); Moves(MOVE_THUNDERBOLT); }
        OPPONENT(SPECIES_TANGELA) { Level(100); Moves(MOVE_GIGA_DRAIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI sees Echoed Voice damage correctly")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); Moves(MOVE_SCRATCH, MOVE_ECHOED_VOICE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(4); Level(55); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_DRAPION) { Speed(4); SpDefense(25); Moves(MOVE_WICKED_BLOW); Ability(ABILITY_SNIPER); }
        OPPONENT(SPECIES_GASTLY) { Speed(4); Level(1); Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_CELEBRATE); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_SMART_MON_CHOICES: AI sees its own weather setting ability when considering switchin candidates")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { ability = ABILITY_DRIZZLE; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(2); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); Level(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_POLITOED) { Speed(5); Ability(ability); Moves(MOVE_BUBBLE_BEAM); }
        OPPONENT(SPECIES_CONKELDURR) { Speed(1); Ability(ABILITY_GUTS); Moves(MOVE_SUPERPOWER); }
    } WHEN {
        if (ability == ABILITY_DRIZZLE)
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 1); }
        else
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will properly consider immunities when determining switchin type matchup")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_WHIMSICOTT, 0) == TYPE_GRASS);
        ASSUME(GetSpeciesType(SPECIES_WHIMSICOTT, 1) == TYPE_FAIRY); // Gen 5's pure Grass type makes the test fail
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_POLIWRATH) { Moves(MOVE_WATER_GUN, MOVE_KARATE_CHOP); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_CERULEDGE) { Moves(MOVE_SPARK); }
        OPPONENT(SPECIES_WHIMSICOTT) { Moves(MOVE_MEGA_DRAIN); }
    } WHEN {
        TURN { MOVE(player, MOVE_KARATE_CHOP); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will properly consider immunities when determining switchin type matchup (Doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_POLIWRATH) { Moves(MOVE_WATER_GUN, MOVE_KARATE_CHOP); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_CERULEDGE) { Moves(MOVE_SPARK); }
        OPPONENT(SPECIES_WHIMSICOTT) { Moves(MOVE_MEGA_DRAIN); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_KARATE_CHOP, target:opponentLeft); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_CELEBRATE); EXPECT_MOVE(opponentRight, MOVE_CELEBRATE); EXPECT_SEND_OUT(opponentLeft, 3); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI won't switch out due to bad odds if it can OHKO with a priority move")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        OPPONENT(SPECIES_CETODDLE) { Level(14); HP(30); Speed(1); Moves(MOVE_ICE_FANG, MOVE_ROCK_SMASH, MOVE_BULLDOZE, MOVE_ICE_SHARD); }
        OPPONENT(SPECIES_SPHEAL) { Level(14); Speed(1); Ability(ABILITY_THICK_FAT); Moves(MOVE_ICY_WIND, MOVE_BRINE, MOVE_HIDDEN_POWER, MOVE_SIGNAL_BEAM); }
        PLAYER(SPECIES_LITTEN) { Level(15); HP(1); Speed(2); Ability(ABILITY_BLAZE); Moves(MOVE_FIRE_FANG, MOVE_EMBER, MOVE_LICK, MOVE_FAKE_OUT); }
    } WHEN {
        TURN { MOVE(player, MOVE_FIRE_FANG); EXPECT_MOVE(opponent, MOVE_ICE_SHARD); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will consider player's priority when evaluating switchin candidates")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); HP(1); Moves(MOVE_HEADBUTT); }
        OPPONENT(SPECIES_ANNIHILAPE) { Speed(5); Moves(MOVE_DRAIN_PUNCH); }
        OPPONENT(SPECIES_GENGAR) { Speed(10); Moves(MOVE_FOCUS_BLAST); }
        PLAYER(SPECIES_KINGAMBIT) { Speed(2); Moves(MOVE_SUCKER_PUNCH, MOVE_KNOCK_OFF); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF); EXPECT_MOVE(opponent, MOVE_HEADBUTT); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will consider player's priority when evaluating Bad Odds 1v1")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_HASBADODDS_PERCENTAGE, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        OPPONENT(SPECIES_GENGAR) { Speed(10); Moves(MOVE_FOCUS_BLAST); }
        OPPONENT(SPECIES_SCRAFTY) { Speed(5); Moves(MOVE_DRAIN_PUNCH); }
        PLAYER(SPECIES_KINGAMBIT) { Speed(2); Moves(MOVE_SUCKER_PUNCH, MOVE_KNOCK_OFF); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will consider player's endure effects when evaluating Bad Odds 1v1")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_HASBADODDS_PERCENTAGE, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        OPPONENT(SPECIES_GENGAR) { Speed(10); Moves(MOVE_FOCUS_BLAST); }
        OPPONENT(SPECIES_SCRAFTY) { Speed(5); Moves(MOVE_DRAIN_PUNCH); }
        PLAYER(SPECIES_KINGAMBIT) { Speed(2); Item(ITEM_FOCUS_SASH); Moves(MOVE_KNOCK_OFF); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will consider player's endure effects when evaluating switchin candidates")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_FOCUS_SASH; }
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(10); HP(1); MaxHP(400); Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_GENGAR) { Speed(10); Moves(MOVE_FOCUS_BLAST); }
        OPPONENT(SPECIES_SCRAFTY) { Speed(5); Moves(MOVE_DRAIN_PUNCH); }
        PLAYER(SPECIES_KINGAMBIT) { Speed(2); Item(item); Moves(MOVE_PROTECT, MOVE_KNOCK_OFF); }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); item == ITEM_FOCUS_SASH ? EXPECT_SEND_OUT(opponent, 2) : EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: AI will consider Hidden Power when triggering absorbing switches")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ABSORBS_HIDDEN_POWER_PERCENTAGE, 100, RNG_AI_SWITCH_ABSORBING_HIDDEN_POWER);
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_HIDDEN_POWER); HPIV(31); AttackIV(30); DefenseIV(31); SpAttackIV(30); SpDefenseIV(31); SpeedIV(30); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_NINETALES) { Moves(MOVE_SCRATCH); Ability(ABILITY_FLASH_FIRE); }
    } WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_HIDDEN_POWER); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_SWITCHING: Fake Out style moves won't confuse choiced AI into thinking it does no damage")
{

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHOICE_SCARF].holdEffect == HOLD_EFFECT_CHOICE_SCARF);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_FAKE_OUT, MOVE_SCRATCH); }
        OPPONENT(SPECIES_INFERNAPE) { Item(ITEM_CHOICE_SCARF); Moves(MOVE_CLOSE_COMBAT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_FAKE_OUT); EXPECT_MOVE(opponent, MOVE_CLOSE_COMBAT); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_CLOSE_COMBAT); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI will consider choice-locked player priority when determining which mon to send out")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_LYCANROC) { Speed(5); Moves(MOVE_ACCELEROCK, MOVE_MIGHTY_CLEAVE); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); HP(1); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_DECIDUEYE_HISUI) { Speed(4); Moves(MOVE_LEAF_BLADE); }
        OPPONENT(SPECIES_PHEROMOSA) { Speed(6); HP(1); Moves(MOVE_EARTHQUAKE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIGHTY_CLEAVE); EXPECT_MOVE(opponent, MOVE_TACKLE); item == ITEM_NONE ? EXPECT_SEND_OUT(opponent, 1) : EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI considers both meeting and exceeding KO thresholds correctly")
{
    u32 hp;
    PARAMETRIZE { hp = 40; }
    PARAMETRIZE { hp = 80; }
    PARAMETRIZE { hp = 79; }
    PARAMETRIZE { hp = 81; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(5); HP(hp); Moves(MOVE_PROTECT, MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(6); Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(6); Moves(MOVE_DRAGON_RAGE); }
        OPPONENT(SPECIES_BELDUM) { Speed(4); Moves(MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); hp > 80 ? EXPECT_SEND_OUT(opponent, 2) : EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI will not choose to switch out Dondozo with Commander Tatsugiri")
{
    PASSES_RANDOMLY(100, 100);
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_PERISH_SONG) == EFFECT_PERISH_SONG);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        OPPONENT(SPECIES_DONDOZO) { Level(50); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_TATSUGIRI) { Moves(MOVE_WATER_GUN); Ability(ABILITY_COMMANDER); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_HEADBUTT); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_CELEBRATE, MOVE_PERISH_SONG); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves (MOVE_CELEBRATE); }
    } WHEN {
        // Commander Tatsugiri cannot act while swallowed, so skip its turn explicitly.
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_PERISH_SONG); SKIP_TURN(opponentRight); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); SKIP_TURN(opponentRight); }
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); SKIP_TURN(opponentRight); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_WATER_GUN); SKIP_TURN(opponentRight); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RANDOMIZE_SWITCHIN: AI will randomly choose between eligible switchin candidates of the same category")
{
    u32 trials; // Two trial counts to ensure randomization is scalable
    PARAMETRIZE { trials = 30; }
    PARAMETRIZE { trials = 50; }
    PASSES_RANDOMLY(10, trials, RNG_AI_RANDOM_SWITCHIN_POST_KO);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_RANDOMIZE_SWITCHIN);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_PROTECT, MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_CLOSE_COMBAT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_CLOSE_COMBAT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_CLOSE_COMBAT); }
        if (trials == 50)
        {
            OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_CLOSE_COMBAT); }
            OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_CLOSE_COMBAT); }
        }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RANDOMIZE_SWITCHIN: AI will randomly choose between all valid switchin candidates if no good options are available")
{
    u32 trials; // Two trial counts to ensure randomization is scalable
    PARAMETRIZE { trials = 30; }
    PARAMETRIZE { trials = 50; }
    PASSES_RANDOMLY(10, trials, RNG_AI_RANDOM_VALID_SWITCHIN_POST_KO);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_RANDOMIZE_SWITCHIN);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_PROTECT, MOVE_BITE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        if (trials == 50)
        {
            OPPONENT(SPECIES_GASTLY) { Moves(MOVE_LICK); }
            OPPONENT(SPECIES_GASTLY) { Moves(MOVE_LICK); }
        }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_SMART_MON_CHOICES: AI sees its own terrain setting ability when considering switchin candidates")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_MACHAMP) { Speed(1); Ability(ABILITY_NO_GUARD); Moves(MOVE_PROTECT, MOVE_SHEER_COLD); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(2); Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_INDEEDEE_F) { Speed(2); Ability(ABILITY_PSYCHIC_SURGE); Moves(MOVE_PSYCHIC); }
        OPPONENT(SPECIES_INDEEDEE_F) { Speed(2); Ability(ABILITY_INNER_FOCUS); Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_SMART_MON_CHOICES: AI sees its own terrain setting ability's effect on failed moves when considering switchin candidates")
{
    KNOWN_FAILING; // Fails because the AI can't currently see the arbitrary terrain passed to AI_CalcDamage in CanAbilityBlockMove
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_PROTECT, MOVE_QUICK_ATTACK); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_INDEEDEE_F) { HP(1); Ability(ABILITY_PSYCHIC_SURGE); Moves(MOVE_CONFUSION); }
        OPPONENT(SPECIES_INDEEDEE_F) { HP(1); Ability(ABILITY_INNER_FOCUS); Moves(MOVE_CONFUSION); }
    } WHEN {
        TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RANDOMIZE_SWITCHIN: AI will consider all mons that meet the specified threshold (damage)")
{
    u64 aiFlag = 0;
    PARAMETRIZE { aiFlag = 0; }
    PARAMETRIZE { aiFlag = AI_FLAG_RANDOMIZE_SWITCHIN; }
    if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
        PASSES_RANDOMLY(1, 5, RNG_AI_RANDOM_SWITCHIN_POST_KO);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | aiFlag | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_PROTECT, MOVE_BODY_SLAM); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_HEADBUTT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH); }
    } WHEN {
        if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 5); }
        else
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RANDOMIZE_SWITCHIN: AI will consider all mons that meet the specified threshold (type matchup)")
{
    u64 aiFlag = 0;
    PARAMETRIZE { aiFlag = 0; }
    PARAMETRIZE { aiFlag = AI_FLAG_RANDOMIZE_SWITCHIN; }
    if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
        PASSES_RANDOMLY(1, 5, RNG_AI_RANDOM_SWITCHIN_POST_KO);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | aiFlag | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_PROTECT, MOVE_BODY_SLAM); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_GEODUDE) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ARON) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GEODUDE) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GEODUDE) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_GEODUDE) { Moves(MOVE_SCRATCH); }
    } WHEN {
        if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 5); }
        else
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RANDOMIZE_SWITCHIN: AI will consider all mons that meet the specified threshold (type matchup effective move)")
{
    u64 aiFlag = 0;
    PARAMETRIZE { aiFlag = 0; }
    PARAMETRIZE { aiFlag = AI_FLAG_RANDOMIZE_SWITCHIN; }
    if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
        PASSES_RANDOMLY(1, 5, RNG_AI_RANDOM_SWITCHIN_POST_KO);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | aiFlag | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(MOVE_PROTECT, MOVE_BODY_SLAM); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_EXPLOSION); }
        OPPONENT(SPECIES_GEODUDE) { Level(70); Moves(MOVE_KARATE_CHOP); }
        OPPONENT(SPECIES_ARON) { Level(70); Moves(MOVE_KARATE_CHOP); }
        OPPONENT(SPECIES_GEODUDE) { Level(70); Moves(MOVE_KARATE_CHOP); }
        OPPONENT(SPECIES_GEODUDE) { Level(70); Moves(MOVE_KARATE_CHOP); }
        OPPONENT(SPECIES_GEODUDE) { Level(70); Moves(MOVE_KARATE_CHOP); }
    } WHEN {
        if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 5); }
        else
            TURN { MOVE(player, MOVE_PROTECT); EXPECT_MOVE(opponent, MOVE_EXPLOSION); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_RANDOMIZE_SWITCHIN: AI will consider all mons that meet the specified threshold (defensive)")
{
    u64 aiFlag = 0;
    PARAMETRIZE { aiFlag = 0; }
    PARAMETRIZE { aiFlag = AI_FLAG_RANDOMIZE_SWITCHIN; }
    if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
        PASSES_RANDOMLY(1, 5, RNG_AI_RANDOM_SWITCHIN_MID_BATTLE);
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | aiFlag | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(1); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(2); Moves(MOVE_U_TURN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); SpDefense(150); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); SpDefense(400); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); SpDefense(150); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); SpDefense(150); Moves(MOVE_WATER_GUN); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); SpDefense(150); Moves(MOVE_WATER_GUN); }
    } WHEN {
        if (aiFlag == AI_FLAG_RANDOMIZE_SWITCHIN)
            TURN { MOVE(player, MOVE_WATER_GUN); EXPECT_MOVE(opponent, MOVE_U_TURN); EXPECT_SEND_OUT(opponent, 5); }
        else
            TURN { MOVE(player, MOVE_WATER_GUN); EXPECT_MOVE(opponent, MOVE_U_TURN); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_MULTI_BATTLE_TEST("AI will not switch out if the opposite battler is absent and its moves can still affect the other opponent")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { HP(41); Speed(1); }
        PARTNER(SPECIES_DRAKLOAK) { HP(41); MaxHP(100); Speed(4); Item(ITEM_LIFE_ORB); Moves(MOVE_DRAGON_RAGE, MOVE_SHADOW_BALL); }
        PARTNER(SPECIES_DRAGAPULT) { Speed(4); Moves(MOVE_SHADOW_BALL); }
        OPPONENT_A(SPECIES_CYCLIZAR) { HP(41); MaxHP(100); Speed(3); Item(ITEM_LIFE_ORB); Moves(MOVE_BODY_SLAM, MOVE_DRAGON_RAGE); }
        OPPONENT_A(SPECIES_DRAMPA) { Speed(3); Moves(MOVE_BODY_SLAM); }
        OPPONENT_B(SPECIES_WYNAUT) { Speed(2); HP(41); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_BODY_SLAM, target: playerLeft);
            EXPECT_MOVE(playerRight, MOVE_SHADOW_BALL, target: opponentRight);
        }
        TURN {
            EXPECT_MOVE(opponentLeft, MOVE_DRAGON_RAGE, target: playerRight);
            EXPECT_MOVE(playerRight, MOVE_DRAGON_RAGE, target: opponentLeft);
        }
    }
}

AI_SINGLE_BATTLE_TEST("Rage Fist stacks are seen properly for switch logic")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_VICTINI) { Level(70); Speed(2); Ability(ABILITY_VICTORY_STAR); Moves(MOVE_V_CREATE, MOVE_PSYCHIC); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Speed(1); HP(1); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_GROUDON) { Level(85); Speed(3); Moves(MOVE_PRECIPICE_BLADES); }
        OPPONENT(SPECIES_ANNIHILAPE) { Level(85); Speed(3); Moves(MOVE_RAGE_FIST); }
    } WHEN {
        TURN { MOVE(player, MOVE_PSYCHIC); EXPECT_SEND_OUT(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI can switch out both mons on the same turn in double battles")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH);}
    } WHEN {
        TURN { EXPECT_SWITCH(opponentLeft, 2); EXPECT_SWITCH(opponentRight, 3); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI sees stat stage changes on switchin when doing switching calcs")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_LUXIO) { Speed(2); Ability(ABILITY_GUTS); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); HP(1); MaxHP(100); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_LUXIO) { Speed(1); Ability(ABILITY_GUTS); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_LUXIO) { Speed(1); Ability(ABILITY_INTIMIDATE); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI sees status changes on switchin when doing switching calcs")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(2); HP(1); MaxHP(100); Moves(MOVE_TOXIC_SPIKES); }
        PLAYER(SPECIES_LUXIO) { Speed(2); Ability(ABILITY_GUTS); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); HP(1); MaxHP(100); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_LUXIO) { Speed(1); Ability(ABILITY_INTIMIDATE); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_LUXIO) { Speed(1); Ability(ABILITY_GUTS); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); EXPECT_MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI sees volate changes on switchin when doing switching calcs")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_BOOSTER_ENERGY) == HOLD_EFFECT_BOOSTER_ENERGY);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ROARING_MOON) { Speed(2); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); HP(1); MaxHP(100); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ROARING_MOON) { Speed(1); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ROARING_MOON) { Speed(1); Moves(MOVE_SCRATCH); Item(ITEM_BOOSTER_ENERGY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("AI_FLAG_SMART_MON_CHOICES: AI sees HP changes on switchin when doing switchin calcs")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(2); HP(1); MaxHP(100); Moves(MOVE_SPIKES); }
        PLAYER(SPECIES_BLAZIKEN) { Speed(2); HP(130); MaxHP(400); Ability(ABILITY_SPEED_BOOST); Moves(MOVE_EMBER); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(1); HP(1); MaxHP(100); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_BLAZIKEN) { Speed(1); HP(180); MaxHP(400); Ability(ABILITY_SPEED_BOOST); Moves(MOVE_EMBER); }
        OPPONENT(SPECIES_BLAZIKEN) { Speed(1); HP(180); MaxHP(400); Ability(ABILITY_BLAZE); Moves(MOVE_EMBER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPIKES); EXPECT_MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_EMBER); EXPECT_MOVE(opponent, MOVE_SCRATCH); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_SINGLE_BATTLE_TEST("Retaliate sees damage correctly for post ko switch in")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_GABITE) { Level(50); Speed(2);}
        OPPONENT(SPECIES_ZIGZAGOON) { Level(1); Speed(3); HP(1); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_GROUDON) { Level(85); Speed(3); Moves(MOVE_PRECIPICE_BLADES); }
        OPPONENT(SPECIES_STOUTLAND) { Level(50); Speed(3); Moves(MOVE_RETALIATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); EXPECT_SEND_OUT(opponent, 2); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI can switch out both mons on the same turn in double battles (reversed)")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100, RNG_AI_SWITCH_ALL_MOVES_BAD);
    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH);}
    } WHEN {
        TURN { EXPECT_SWITCH(opponentRight, 2); EXPECT_SWITCH(opponentLeft, 3); }
    }
}

AI_DOUBLE_BATTLE_TEST("AI can switch out both mons in either order")
{
    PASSES_RANDOMLY(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100, RNG_AI_REVERSE_BATTLER_LOGIC_ORDER);
    GIVEN {
        WITH_CONFIG(SHOULD_SWITCH_ALL_MOVES_BAD_PERCENTAGE, 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RATTATA);
        PLAYER(SPECIES_RATTATA);
        OPPONENT(SPECIES_GENGAR) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_GASTLY) { Moves(MOVE_SHADOW_BALL); }
        OPPONENT(SPECIES_RATTATA) { Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_SCRATCH);}
    } WHEN {
        TURN { EXPECT_SWITCH(opponentRight, 2); EXPECT_SWITCH(opponentLeft, 3); }
    }
}

AI_SINGLE_BATTLE_TEST("AI can switch out if it loses the 1v1")
{
    PASSES_RANDOMLY(100, 100, RNG_AI_SWITCH_LOSES_1V1);
    GIVEN {
        WITH_CONFIG(SHOULD_SWITCH_LOSES_1V1_PERCENTAGE, 100);
        PLAYER(SPECIES_LINOONE);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_AGGRON);
    } WHEN {
        TURN { EXPECT_SWITCH(opponent, 1); }
    }
}
