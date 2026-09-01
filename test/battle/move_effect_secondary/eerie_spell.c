#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_EERIE_SPELL, MOVE_EFFECT_EERIE_SPELL));
}

SINGLE_BATTLE_TEST("Eerie Spell reduces the PP of the target's last move by 3")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_EERIE_SPELL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EERIE_SPELL, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet lost 3 PP from Scratch!");
    } THEN {
        EXPECT_EQ(opponent->pp[0], GetMovePP(MOVE_SCRATCH) - 4); // 1 from Scratch use + 3 from Eerie Spell
    }
}

SINGLE_BATTLE_TEST("Eerie Spell reduces the PP of a Max Move's base move by 3")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(player, MOVE_EERIE_SPELL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EERIE_SPELL, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet lost 3 PP from Scratch!");
    } THEN {
        EXPECT_EQ(opponent->pp[0], GetMovePP(MOVE_SCRATCH) - 4); // 1 from Max Move use + 3 from Eerie Spell
    }
}

SINGLE_BATTLE_TEST("Eerie Spell's PP reduction is blocked by Shield Dust")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VIVILLON) { Ability(ABILITY_SHIELD_DUST); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_EERIE_SPELL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EERIE_SPELL, player);
        HP_BAR(opponent);
        NOT MESSAGE("The opposing Vivillon lost 3 PP from Scratch!");
    } THEN {
        EXPECT_EQ(opponent->pp[0], GetMovePP(MOVE_SCRATCH) - 1);
    }
}

SINGLE_BATTLE_TEST("Eerie Spell's PP reduction is blocked by Covert Cloak")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_COVERT_CLOAK].holdEffect == HOLD_EFFECT_COVERT_CLOAK);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_COVERT_CLOAK); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_EERIE_SPELL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EERIE_SPELL, player);
        HP_BAR(opponent);
        NOT MESSAGE("The opposing Wobbuffet lost 3 PP from Scratch!");
    } THEN {
        EXPECT_EQ(opponent->pp[0], GetMovePP(MOVE_SCRATCH) - 1);
    }
}

SINGLE_BATTLE_TEST("Eerie Spell does not reduce PP if the target faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_EERIE_SPELL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EERIE_SPELL, player);
        HP_BAR(opponent);
        NOT MESSAGE("The opposing Wobbuffet lost 3 PP from Scratch!");
    } THEN {
        EXPECT_EQ(opponent->pp[0], GetMovePP(MOVE_SCRATCH) - 1); // Eerie Spell's PP reduction happens after fainting checks
    }
}
