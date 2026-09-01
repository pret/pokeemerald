#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_DOUBLE_BATTLE_TEST("AI_FLAG_ATTACKS_PARTNER is willing to kill either the partner or the player")
{
    ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);

    enum Move move;
    u32 level;

    PARAMETRIZE { move = MOVE_BRUTAL_SWING; level = 1; }
    PARAMETRIZE { move = MOVE_MIGHTY_CLEAVE; level = 1; }
    PARAMETRIZE { move = MOVE_BRUTAL_SWING; level = 100; }
    PARAMETRIZE { move = MOVE_MIGHTY_CLEAVE; level = 100; }
    PARAMETRIZE { move = MOVE_BRUTAL_SWING; level = 50; }
    PARAMETRIZE { move = MOVE_MIGHTY_CLEAVE; level = 50; }

    GIVEN {
        ASSUME(GetMovePower(MOVE_OVERDRIVE) == 80);
        ASSUME(GetMovePower(MOVE_BRUTAL_SWING) == 60);
        ASSUME(GetMovePower(MOVE_MIGHTY_CLEAVE) == 95);
        ASSUME(gSpeciesInfo[SPECIES_ZIGZAGOON].baseAttack == gSpeciesInfo[SPECIES_ZIGZAGOON].baseSpAttack);
        ASSUME(gSpeciesInfo[SPECIES_ZIGZAGOON].baseDefense == gSpeciesInfo[SPECIES_ZIGZAGOON].baseSpDefense);
        ASSUME(gSpeciesInfo[SPECIES_ZIGZAGOON].baseHP == 38);
        ASSUME(gSpeciesInfo[SPECIES_ZIGZAGOON].baseAttack == 30);
        ASSUME(gSpeciesInfo[SPECIES_ZIGZAGOON].baseDefense == 41);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ATTACKS_PARTNER);
        PLAYER(SPECIES_ZIGZAGOON) { Level(50); }
        PLAYER(SPECIES_ZIGZAGOON) { Level(16); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(50); Moves(move, MOVE_OVERDRIVE, MOVE_TACKLE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Level(level); Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN {
            if (move == MOVE_MIGHTY_CLEAVE)
            {
                if (level == 1)
                    EXPECT_MOVE(opponentLeft, move, target: opponentRight);
                else
                    EXPECT_MOVE(opponentLeft, move, target: playerRight);
            }
            else
            {
                if (level == 1 || AI_FLAG_ATTACKS_PARTNER_FOCUSES_PARTNER)
                    EXPECT_MOVE(opponentLeft, move);
                else
                    EXPECT_MOVE(opponentLeft, MOVE_OVERDRIVE);
            }
        }
    }
}

AI_DOUBLE_BATTLE_TEST("AI_FLAG_ATTACKS_PARTNER steps on its ally's weather")
{
    u32 weather1, move1, weather2, move2;

    PARAMETRIZE { weather1 = MOVE_SUNNY_DAY; move1 = MOVE_SOLAR_BEAM; weather2 = MOVE_RAIN_DANCE; move2 = MOVE_THUNDER; }
    PARAMETRIZE { weather1 = MOVE_RAIN_DANCE; move1 = MOVE_THUNDER; weather2 = MOVE_SUNNY_DAY; move2 = MOVE_SOLAR_BEAM; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_ATTACKS_PARTNER);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(75); Moves(weather1, move1, MOVE_HEADBUTT); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Moves(weather2, move2, MOVE_HEADBUTT); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentLeft, weather1);
            EXPECT_MOVE(opponentRight, weather2);
        }
        TURN {
            EXPECT_MOVE(opponentLeft, move1);
            EXPECT_MOVE(opponentRight, weather2);
        }
    }
}
