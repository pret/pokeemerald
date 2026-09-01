#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_CHOICE_SPECS].holdEffect == HOLD_EFFECT_CHOICE_SPECS);
    ASSUME(gItemsInfo[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
    ASSUME(gItemsInfo[ITEM_CHOICE_SCARF].holdEffect == HOLD_EFFECT_CHOICE_SCARF);
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon switch out after using a status move once")
{
    u32 j;
    enum Item heldItem = ITEM_NONE;
    enum Ability ability = ABILITY_NONE;

    static const enum Item choiceItems[] = {
        ITEM_CHOICE_SPECS,
        ITEM_CHOICE_BAND,
        ITEM_CHOICE_SCARF,
    };

    for (j = 0; j < ARRAY_COUNT(choiceItems); j++)
    {
        PARAMETRIZE { ability = ABILITY_NONE;    heldItem = choiceItems[j]; }
        PARAMETRIZE { ability = ABILITY_KLUTZ;   heldItem = choiceItems[j]; }
    }

    PASSES_RANDOMLY(SHOULD_SWITCH_CHOICE_LOCKED_PERCENTAGE, 100, RNG_AI_SWITCH_CHOICE_LOCKED);

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_YAWN) == DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RHYDON)
        OPPONENT(SPECIES_LOPUNNY) { Moves(MOVE_YAWN, MOVE_SCRATCH); Item(heldItem); Ability(ability); }
        OPPONENT(SPECIES_SWAMPERT) { Moves(MOVE_WATERFALL); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_YAWN); }
        if (ability == ABILITY_KLUTZ) { // Klutz ignores item
            TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        }
        else {
            TURN { EXPECT_SWITCH(opponent, 1); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon only consider their own status moves when determining if they should switch")
{
    GIVEN
    {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_ZIGZAGOON) { Speed(4); Moves(MOVE_TAIL_WHIP, MOVE_SCRATCH); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(5); Moves(MOVE_SCRATCH); Item(ITEM_CHOICE_BAND); }
        OPPONENT(SPECIES_ZIGZAGOON) { Speed(5); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_TAIL_WHIP); }
        TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_TAIL_WHIP); }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon won't use stat boosting moves")
{
    // Moves defined by TARGET_USER (with exceptions?)
    u32 j;
    enum Item heldItem = ITEM_NONE;
    enum Ability ability = ABILITY_NONE;

    static const enum Item choiceItems[] = {
        ITEM_CHOICE_SPECS,
        ITEM_CHOICE_BAND,
        ITEM_CHOICE_SCARF,
    };

    for (j = 0; j < ARRAY_COUNT(choiceItems); j++)
    {
        PARAMETRIZE { ability = ABILITY_NONE;    heldItem = choiceItems[j]; }
        PARAMETRIZE { ability = ABILITY_KLUTZ;   heldItem = choiceItems[j]; }
    }

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SWORDS_DANCE) == TARGET_USER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RHYDON)
        OPPONENT(SPECIES_LOPUNNY) { Moves(MOVE_SWORDS_DANCE, MOVE_SCRATCH); Item(heldItem); Ability(ability); }
        OPPONENT(SPECIES_SWAMPERT) { Moves(MOVE_WATERFALL); }
    } WHEN {
        if (ability == ABILITY_KLUTZ) { // Klutz ignores item
            TURN { EXPECT_MOVE(opponent, MOVE_SWORDS_DANCE); }
        }
        else {
            TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon won't use status move if they are the only party member")
{
    u32 j, isAlive = 0;
    enum Item heldItem = ITEM_NONE;
    enum Ability ability = ABILITY_NONE;
    static const enum Item choiceItems[] = {
        ITEM_CHOICE_SPECS,
        ITEM_CHOICE_BAND,
        ITEM_CHOICE_SCARF,
    };

    for (j = 0; j < ARRAY_COUNT(choiceItems); j++)
    {
        PARAMETRIZE { ability = ABILITY_NONE;    heldItem = choiceItems[j]; isAlive = 0; }
        PARAMETRIZE { ability = ABILITY_KLUTZ;   heldItem = choiceItems[j]; isAlive = 0; }
        PARAMETRIZE { ability = ABILITY_NONE;    heldItem = choiceItems[j]; isAlive = 1; }
        PARAMETRIZE { ability = ABILITY_KLUTZ;   heldItem = choiceItems[j]; isAlive = 1; }
    }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_YAWN) == DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RHYDON)
        OPPONENT(SPECIES_LOPUNNY) { Moves(MOVE_YAWN, MOVE_SCRATCH); Item(heldItem); Ability(ability); }
        OPPONENT(SPECIES_SWAMPERT) { HP(isAlive); Moves(MOVE_WATERFALL); }
    } WHEN {
        if (isAlive == 1 || ability == ABILITY_KLUTZ) {
            TURN { EXPECT_MOVE(opponent, MOVE_YAWN); }
        }
        else {
            TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon won't use status move if they don't have a good switchin")
{
    u32 j;
    enum Move move = MOVE_NONE;
    enum Species species = SPECIES_NONE;
    enum Item heldItem = ITEM_NONE;
    enum Ability ability = ABILITY_NONE;
    static const enum Item choiceItems[] = {
        ITEM_CHOICE_SPECS,
        ITEM_CHOICE_BAND,
        ITEM_CHOICE_SCARF,
    };

    for (j = 0; j < ARRAY_COUNT(choiceItems); j++)
    {
        PARAMETRIZE { ability = ABILITY_NONE;    heldItem = choiceItems[j]; species = SPECIES_SWAMPERT; move = MOVE_WATERFALL; }
        PARAMETRIZE { ability = ABILITY_KLUTZ;   heldItem = choiceItems[j]; species = SPECIES_SWAMPERT; move = MOVE_WATERFALL; }
        PARAMETRIZE { ability = ABILITY_NONE;    heldItem = choiceItems[j]; species = SPECIES_ELEKID; move = MOVE_THUNDER_WAVE; }
        PARAMETRIZE { ability = ABILITY_KLUTZ;   heldItem = choiceItems[j]; species = SPECIES_ELEKID; move = MOVE_THUNDER_WAVE; }
    }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_YAWN) == DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_RHYDON)
        OPPONENT(SPECIES_LOPUNNY) { Moves(MOVE_YAWN, MOVE_SCRATCH); Item(heldItem); Ability(ability); }
        OPPONENT(species) { Moves(move); }
    } WHEN {
        if (species == SPECIES_SWAMPERT || ability == ABILITY_KLUTZ) {
            TURN { EXPECT_MOVE(opponent, MOVE_YAWN); }
        }
        else {
            TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon won't use status move if they are trapped")
{
    u32 j;
    enum Ability aiAbility = ABILITY_NONE, playerAbility = ABILITY_NONE;
    enum Species species = SPECIES_NONE;
    enum Item heldItem = ITEM_NONE;

    static const enum Item choiceItems[] = {
        ITEM_CHOICE_SPECS,
        ITEM_CHOICE_BAND,
        ITEM_CHOICE_SCARF,
    };

    for (j = 0; j < ARRAY_COUNT(choiceItems); j++)
    {
        PARAMETRIZE { aiAbility = ABILITY_NONE;    heldItem = choiceItems[j]; species = SPECIES_RHYDON; playerAbility = ABILITY_LIGHTNING_ROD; }
        PARAMETRIZE { aiAbility = ABILITY_KLUTZ;   heldItem = choiceItems[j]; species = SPECIES_RHYDON; playerAbility = ABILITY_LIGHTNING_ROD; }
        PARAMETRIZE { aiAbility = ABILITY_NONE;    heldItem = choiceItems[j]; species = SPECIES_DUGTRIO; playerAbility = ABILITY_ARENA_TRAP; }
        PARAMETRIZE { aiAbility = ABILITY_KLUTZ;   heldItem = choiceItems[j]; species = SPECIES_DUGTRIO; playerAbility = ABILITY_ARENA_TRAP; }
    }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_YAWN) == DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveEffect(MOVE_YAWN) == EFFECT_YAWN);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(species) { Ability(playerAbility); }
        OPPONENT(SPECIES_LOPUNNY) { Moves(MOVE_YAWN, MOVE_SCRATCH); Item(heldItem); Ability(aiAbility); }
        OPPONENT(SPECIES_SWAMPERT) { Moves(MOVE_WATERFALL); }
    } WHEN {
        if (playerAbility != ABILITY_ARENA_TRAP || aiAbility == ABILITY_KLUTZ) {
            TURN { EXPECT_MOVE(opponent, MOVE_YAWN); }
        }
        else {
            TURN { EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon will switch if locked into a move the player is immune to")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_GASTLY, 0) == TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_BODY_SLAM) == TYPE_NORMAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT);
        PLAYER(SPECIES_GASTLY) { Level(1); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); Moves(MOVE_SURF); }
        OPPONENT(SPECIES_ZIGZAGOON) { Item(ITEM_CHOICE_BAND); Moves(MOVE_SURF, MOVE_BODY_SLAM); }
        OPPONENT(SPECIES_ZIGZAGOON) { Item(ITEM_CHOICE_BAND); Moves(MOVE_SURF, MOVE_BODY_SLAM); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SURF); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_SURF); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon will only see choiced moves when considering switching with ShouldSwitchIfHasBadOdds")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_HASBADODDS_PERCENTAGE, 100, RNG_AI_SWITCH_HASBADODDS);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_GASTLY, 0) == TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_SURF) == TYPE_WATER);
        ASSUME(GetMoveType(MOVE_BODY_SLAM) == TYPE_NORMAL);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_GASTLY) { Level(1); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_ZIGZAGOON) { Item(ITEM_CHOICE_BAND); Moves(MOVE_CLOSE_COMBAT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Item(ITEM_CHOICE_BAND); Moves(MOVE_SURF, MOVE_CLOSE_COMBAT); }
        OPPONENT(SPECIES_BRONZONG) { Moves(MOVE_CLOSE_COMBAT); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_SURF); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_CLOSE_COMBAT); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_SINGLE_BATTLE_TEST("Choiced Pokémon will only see choiced moves when considering switching with FindMonThatAbsorbsMove")
{
    PASSES_RANDOMLY(SHOULD_SWITCH_ABSORBS_MOVE_PERCENTAGE, 100, RNG_AI_SWITCH_ABSORBING);
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_SANDSHREW, 0) == TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        ASSUME(GetMoveType(MOVE_THUNDERBOLT) == TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_WATER_GUN) == TYPE_WATER);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_WOOPER) { Ability(ABILITY_WATER_ABSORB); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_DWEBBLE) { Moves(MOVE_SURF); }
        OPPONENT(SPECIES_MUDKIP) { Item(ITEM_CHOICE_SCARF); Moves(MOVE_SCRATCH, MOVE_WATER_GUN); }
        OPPONENT(SPECIES_WOOPER) { Ability(ABILITY_WATER_ABSORB); Moves(MOVE_SCRATCH); }
    } WHEN {
        TURN { SWITCH(player, 1); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SURF); EXPECT_MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_SURF); EXPECT_SWITCH(opponent, 1); }
    }
}

AI_DOUBLE_BATTLE_TEST("Choiced Pokémon won't switch out if they can still affect one opposing Pokémon in doubles")
{
    enum Species defendingSpecies = SPECIES_NONE;
    enum Ability defendingAbility = ABILITY_NONE;
    PARAMETRIZE { defendingSpecies = SPECIES_VAPOREON; defendingAbility = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { defendingSpecies = SPECIES_ZIGZAGOON; defendingAbility = ABILITY_GLUTTONY; }

    PASSES_RANDOMLY(SHOULD_SWITCH_CHOICE_LOCKED_PERCENTAGE, 100, RNG_AI_SWITCH_CHOICE_LOCKED);

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 0);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_CHARMANDER) { Level(5); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); Moves(MOVE_CELEBRATE); }
        PLAYER(defendingSpecies) { Ability(defendingAbility); SpDefense(500); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_VAPOREON) { Moves(MOVE_SCALD); Item(ITEM_CHOICE_SPECS); }
        OPPONENT(SPECIES_VAPOREON) { Moves(MOVE_SCALD); Item(ITEM_CHOICE_SPECS); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_SCALD, target:playerLeft); EXPECT_MOVE(opponentRight, MOVE_SCALD, target:playerLeft); }
        if (defendingSpecies == SPECIES_VAPOREON)
            TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_SWITCH(opponentLeft, 2); EXPECT_MOVE(opponentRight, MOVE_SCALD); }
        else
            TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_SCALD, target:playerLeft); EXPECT_MOVE(opponentRight, MOVE_SCALD, target:playerLeft); SEND_OUT(playerLeft, 0); }
    }
}

AI_DOUBLE_BATTLE_TEST("Choiced Pokémon won't switch out if they can still affect one opposing Pokémon in doubles (reversed)")
{
    u32 defendingSpecies = SPECIES_NONE;
    enum Ability defendingAbility = ABILITY_NONE;
    PARAMETRIZE { defendingSpecies = SPECIES_VAPOREON; defendingAbility = ABILITY_WATER_ABSORB; }
    PARAMETRIZE { defendingSpecies = SPECIES_ZIGZAGOON; defendingAbility = ABILITY_GLUTTONY; }

    PASSES_RANDOMLY(SHOULD_SWITCH_CHOICE_LOCKED_PERCENTAGE, 100, RNG_AI_SWITCH_CHOICE_LOCKED);

    GIVEN {
        WITH_CONFIG(AI_REVERSE_BATTLER_LOGIC_ORDER_CHANCE, 100);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_RISKY | AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES);
        PLAYER(SPECIES_CHARMANDER) { Level(5); Moves(MOVE_CELEBRATE); }
        PLAYER(SPECIES_VAPOREON) { Ability(ABILITY_WATER_ABSORB); Moves(MOVE_CELEBRATE); }
        PLAYER(defendingSpecies) { Ability(defendingAbility); SpDefense(500); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_VAPOREON) { Moves(MOVE_SCALD); Item(ITEM_CHOICE_SPECS); }
        OPPONENT(SPECIES_VAPOREON) { Moves(MOVE_SCALD); Item(ITEM_CHOICE_SPECS); }
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { SWITCH(playerLeft, 2); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_SCALD, target:playerLeft); EXPECT_MOVE(opponentRight, MOVE_SCALD, target:playerLeft); }
        if (defendingSpecies == SPECIES_VAPOREON)
            TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_SWITCH(opponentRight, 2); EXPECT_MOVE(opponentLeft, MOVE_SCALD); }
        else
            TURN { MOVE(playerLeft, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); EXPECT_MOVE(opponentLeft, MOVE_SCALD, target:playerLeft); EXPECT_MOVE(opponentRight, MOVE_SCALD, target:playerLeft); SEND_OUT(playerLeft, 0); }
    }
}
