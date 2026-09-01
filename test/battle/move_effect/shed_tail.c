#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SHED_TAIL) == EFFECT_SHED_TAIL);
}

SINGLE_BATTLE_TEST("Shed Tail creates a Substitute at the cost of 1/2 users maximum HP and switches the user out")
{
    s16 maxHP = 0;
    s16 costHP = 0;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHED_TAIL); SEND_OUT(player, 1); }
    } SCENE {
        maxHP = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHED_TAIL, player);
        HP_BAR(player, captureDamage: &costHP);
        MESSAGE("Wobbuffet shed its tail to create a decoy!");
        SEND_IN_MESSAGE("Wynaut");
    }THEN {
        EXPECT_EQ(maxHP / 2, costHP);
    }
}

SINGLE_BATTLE_TEST("Shed Tail fails if the user doesn't have enough HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHED_TAIL); }
    } SCENE {
        MESSAGE("But it does not have enough HP left to make a substitute!");
    }
}

SINGLE_BATTLE_TEST("Shed Tail's HP cost can trigger a berry before the user switches out")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SITRUS_BERRY].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SITRUS_BERRY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHED_TAIL); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHED_TAIL, player);
        SEND_IN_MESSAGE("Wynaut");
    }
}

SINGLE_BATTLE_TEST("Shed Tail fails if there are no usable Pokémon left")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET)
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHED_TAIL); }
    } SCENE {
        MESSAGE("Wobbuffet used Shed Tail!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Shed Tail's HP cost doesn't trigger effects that trigger on damage taken")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHED_TAIL); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHED_TAIL, player);
        MESSAGE("Wobbuffet shed its tail to create a decoy!");
        NOT MESSAGE("Wobbuffet's Air Balloon popped!");
    }
}

AI_SINGLE_BATTLE_TEST("AI will use Shed Tail to pivot to another mon while in damage stalemate with player rather than hard switching")
{
    u32 aiFlags;
    PARAMETRIZE { aiFlags = 0; }
    PARAMETRIZE { aiFlags = AI_FLAG_SMART_SWITCHING | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_MON_CHOICES; }
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT | aiFlags);
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Ability(ABILITY_RUN_AWAY); Moves(MOVE_SCRATCH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Ability(ABILITY_RUN_AWAY); Moves(MOVE_CONFUSION, MOVE_SHED_TAIL); }
        OPPONENT(SPECIES_SCIZOR) { Speed(101); Moves(MOVE_CELEBRATE, MOVE_X_SCISSOR); }
    } WHEN {
        if (aiFlags == 0)
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_CONFUSION); }
        TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_SHED_TAIL); }
    }
}

SINGLE_BATTLE_TEST("Shed Tail creates a Substitute with 1/4 of user maximum health")
{
    u32 hp;
    PARAMETRIZE { hp = 160; }
    PARAMETRIZE { hp = 164; }

    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_BULBASAUR) { MaxHP(hp); }
        PLAYER(SPECIES_BULBASAUR);
        OPPONENT(SPECIES_CHARMANDER);
    } WHEN {
        TURN { MOVE(player, MOVE_SHED_TAIL); MOVE(opponent, MOVE_DRAGON_RAGE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHED_TAIL, player);
        if (hp == 160)
            MESSAGE("Bulbasaur's substitute faded!");
        else
            NOT MESSAGE("Bulbasaur's substitute faded!");
    }
}
