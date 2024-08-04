#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SPICY_EXTRACT].effect == EFFECT_SPICY_EXTRACT);
}

SINGLE_BATTLE_TEST("Spicy Extract raises target's Attack by 2 stages and lowers target's Defense by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Attack sharply rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Defense harshly fell!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 2);
    }
}

SINGLE_BATTLE_TEST("Spicy Extract is prevented by target's ability if it's Attack stat is maxed out")
{
    u16 ability;

    PARAMETRIZE { ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { ability = ABILITY_LIGHT_METAL; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_SWORDS_DANCE].effect == EFFECT_ATTACK_UP_2);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BELDUM) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Wobbuffet used Spicy Extract!");
        if (ability == ABILITY_CLEAR_BODY) {
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
            MESSAGE("Foe Beldum's Clear Body prevents stat loss!");
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            }
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Spicy Extract Defense loss is prevented by Big Pecks")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Pidgey's Attack sharply rose!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Wobbuffet's Defense harshly fell!");
        }
        ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
        MESSAGE("Foe Pidgey's Big Pecks prevents Defense loss!");
    }
}

SINGLE_BATTLE_TEST("Spicy Extract bypasses accuracy checks")
{
    PASSES_RANDOMLY(100, 100, RNG_ACCURACY);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        NOT MESSAGE("Wobbuffet's attack missed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Attack sharply rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's Defense harshly fell!");
    }
}

SINGLE_BATTLE_TEST("Spicy Extract will fail if target is in a semi-invulnerability state")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DIVE); MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Dive!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DIVE, opponent);
        MESSAGE("Wobbuffet used Spicy Extract!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        MESSAGE("Wobbuffet's attack missed!");
    }
}

SINGLE_BATTLE_TEST("Spicy Extract stat changes will be inverted by Contrary")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Snivy's Attack harshly fell!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Snivy's Defense sharply rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE - 2);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Spicy Extract against Clear Amulet and Contrary raises Defense only")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPICY_EXTRACT); }
    } SCENE {
        MESSAGE("Wobbuffet used Spicy Extract!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPICY_EXTRACT, player);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Foe Snivy's Attack harshly fell!");
        }
        MESSAGE("Foe Snivy's Clear Amulet prevents its stats from being lowered!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Snivy's Defense sharply rose!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}

AI_DOUBLE_BATTLE_TEST("Spicy Extract user will use it if partner holds Clear Amulet and a physical move")
{
    u32 move;

    PARAMETRIZE { move = MOVE_TACKLE; }
    PARAMETRIZE { move = MOVE_SWIFT;}

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_CLEAR_AMULET); Moves(move); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_TACKLE, MOVE_SPICY_EXTRACT); }
    } WHEN {
        TURN {
            if (move == MOVE_TACKLE)
                EXPECT_MOVE(opponentRight, MOVE_SPICY_EXTRACT);
            else
                EXPECT_MOVE(opponentRight, MOVE_TACKLE);
        }
    }
}

AI_DOUBLE_BATTLE_TEST("Spicy Extract user will not choose the move if it does not benefit partner")
{
    u32 species;
    u32 ability;

    PARAMETRIZE { species = SPECIES_GHOLDENGO; ability = ABILITY_GOOD_AS_GOLD; }
    PARAMETRIZE { species = SPECIES_SNIVY; ability = ABILITY_CONTRARY; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(species) { Speed(20); Ability(ability); Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(40); Moves(MOVE_TACKLE, MOVE_SPICY_EXTRACT); }
    } WHEN {
        TURN {
            EXPECT_MOVE(opponentRight, MOVE_TACKLE);
        }
    }
}
