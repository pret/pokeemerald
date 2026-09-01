#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_EMBARGO) == EFFECT_EMBARGO);
}

SINGLE_BATTLE_TEST("Embargo blocks the effect of an affected Pokémon's held item")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBARGO); }
        TURN { MOVE(player, MOVE_FISSURE); }
    } SCENE {
        // Turn 1
        MESSAGE("Wobbuffet used Embargo!");
        MESSAGE("The opposing Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("Wobbuffet used Fissure!");
        HP_BAR(opponent, hp: 0);
    }
}

SINGLE_BATTLE_TEST("Embargo blocks an affected Pokémon's trainer from using items")
{
    // As of writing, the battle tests system doesn't perform all the operations involved
    // in the action of an NPC using an item in battle.
    KNOWN_FAILING;
    GIVEN {
        ASSUME(gItemsInfo[ITEM_POTION].battleUsage == EFFECT_ITEM_RESTORE_HP);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBARGO); }
        TURN { USE_ITEM(opponent, ITEM_POTION, partyIndex: 0); }
    } SCENE {
        MESSAGE("Wobbuffet used Embargo!");
        MESSAGE("The opposing Wobbuffet can't use items anymore!");
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
    }
}

WILD_BATTLE_TEST("Embargo doesn't block held item effects that affect experience gain", s32 exp)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_LUCKY_EGG; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(20); Item(item); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
        ASSUME(gItemsInfo[ITEM_LUCKY_EGG].holdEffect == HOLD_EFFECT_LUCKY_EGG);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("The wild Caterpie used Embargo!");
        MESSAGE("Wobbuffet can't use items anymore!");
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The wild Caterpie fainted!");
        EXPERIENCE_BAR(player, captureGainedExp: &results[i].exp);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].exp, Q_4_12(1.5), results[0].exp);
    }
}

WILD_BATTLE_TEST("Embargo doesn't block held item effects that affect effort values")
{
    u32 finalHPEVAmount;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_WEIGHT); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        ASSUME(gItemsInfo[ITEM_POWER_WEIGHT].holdEffect == HOLD_EFFECT_POWER_ITEM);
        ASSUME(gItemsInfo[ITEM_POWER_WEIGHT].holdEffectParam != 0);
        ASSUME(gItemsInfo[ITEM_POWER_WEIGHT].secondaryId == STAT_HP);
        ASSUME(gSpeciesInfo[SPECIES_CATERPIE].evYield_HP == 1);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        // Turn 1
        MESSAGE("The wild Caterpie used Embargo!");
        MESSAGE("Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("Wobbuffet used Scratch!");
        MESSAGE("The wild Caterpie fainted!");
    } THEN {
        finalHPEVAmount = (GetMonData(&PLAYER_PARTY[0], MON_DATA_HP_EV) + gItemsInfo[ITEM_POWER_WEIGHT].holdEffectParam + gSpeciesInfo[SPECIES_CATERPIE].evYield_HP);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HP_EV), finalHPEVAmount);
    }
}

SINGLE_BATTLE_TEST("Embargo negates a held item's Speed reduction")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(19); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_MACHO_BRACE); Speed(20); }
        ASSUME(gItemsInfo[ITEM_MACHO_BRACE].holdEffect == HOLD_EFFECT_MACHO_BRACE);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBARGO); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        // Turn 1
        MESSAGE("Wobbuffet used Embargo!");
        MESSAGE("The opposing Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("The opposing Wobbuffet used Scratch!");
        MESSAGE("Wobbuffet used Scratch!");
    }
}

// This is a useful test, but under the current circumstances, we can't actually test this without modifying
// X_ITEM_FRIENDSHIP_INCREASE. Since HOLD_EFFECT_FRIENDSHIP_UP applies a 1.5x modifier, and the stock
// Friendship increase is 1, the held item effect actually does not affect the Friendship gained.
//
// WILD_BATTLE_TEST("Embargo doesn't block held item effects that affect friendship")
// {
//     u32 initialFriendship;
//     u32 finalFriendship;

//     KNOWN_FAILING; // Pokémon are currently not obtaining Friendship for using items in battle.
//     GIVEN {
//         ASSUME(gItemsInfo[ITEM_X_ACCURACY].battleUsage == EFFECT_ITEM_INCREASE_STAT);
//         PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SOOTHE_BELL); }
//         OPPONENT(SPECIES_WOBBUFFET);
//     } WHEN {
//         TURN { USE_ITEM(player, ITEM_X_ACCURACY); }
//         TURN { MOVE(player, MOVE_SING); }
//     } SCENE {
//         MESSAGE("Wobbuffet used Sing!");
//         MESSAGE("Wild Wobbuffet fell asleep!");
//     } THEN {
//         initialFriendship = GetMonData(&PLAYER_PARTY[0], MON_DATA_FRIENDSHIP);
//         finalFriendship = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_FRIENDSHIP);
//         EXPECT_EQ(finalFriendship, initialFriendship + 2);
//     }
// }

SINGLE_BATTLE_TEST("Embargo doesn't block a held item's form-changing effect, but it does block its other effects", s16 damage)
{
    enum Item heldItem;

    PARAMETRIZE { heldItem = ITEM_NONE; }
    PARAMETRIZE { heldItem = ITEM_MEADOW_PLATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ARCEUS_GRASS) { Item(heldItem); }
        ASSUME(gItemsInfo[ITEM_MEADOW_PLATE].holdEffect == HOLD_EFFECT_PLATE);
        ASSUME(gItemsInfo[ITEM_MEADOW_PLATE].holdEffectParam == 20);
        ASSUME(gItemsInfo[ITEM_MEADOW_PLATE].secondaryId == TYPE_GRASS);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBARGO); MOVE(opponent, MOVE_RAZOR_LEAF); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Embargo makes Fling and Natural Gift fail")
{
    enum Item heldItem;
    enum Move moveId;

    PARAMETRIZE { heldItem = ITEM_LIGHT_BALL; moveId = MOVE_FLING; }
    PARAMETRIZE { heldItem = ITEM_CHERI_BERRY; moveId = MOVE_NATURAL_GIFT; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(heldItem); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); }
        TURN { MOVE(player, moveId); }
    } SCENE {
        // Turn 1
        MESSAGE("The opposing Wobbuffet used Embargo!");
        MESSAGE("Wobbuffet can't use items anymore!");
        // Turn 2
        if (moveId == MOVE_FLING)
            MESSAGE("Wobbuffet used Fling!");
        else
            MESSAGE("Wobbuffet used Natural Gift!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Embargo doesn't stop an item flung at an affected target from activating")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIGHT_BALL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBARGO); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        // Turn 1
        MESSAGE("Wobbuffet used Embargo!");
        MESSAGE("The opposing Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("Wobbuffet used Fling!");
        MESSAGE("Wobbuffet flung its Light Ball!");
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
    }
}

SINGLE_BATTLE_TEST("Baton Pass passes Embargo's effect")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_LIGHT_BALL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); }
        TURN { MOVE(player, MOVE_BATON_PASS); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        // Turn 1
        MESSAGE("The opposing Wobbuffet used Embargo!");
        MESSAGE("Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("Wobbuffet used Baton Pass!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, player);
        SEND_IN_MESSAGE("Wynaut");
        // Turn 3
        MESSAGE("Wynaut used Fling!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Embargo doesn't block the effects of berries obtained through Bug Bite or Pluck")
{
    u32 hp = 10;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); }
        TURN { MOVE(player, MOVE_PLUCK); }
    } SCENE {
        // Turn 1
        MESSAGE("The opposing Wobbuffet used Embargo!");
        MESSAGE("Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("Wobbuffet used Pluck!");
        HP_BAR(opponent);
        MESSAGE("Wobbuffet stole and ate its target's Oran Berry!");
        HP_BAR(player, damage: -hp);
    }
}

SINGLE_BATTLE_TEST("Embargo disables the effect of the Plate items on the move Judgment", s16 damage)
{
    enum Item heldItem;

    PARAMETRIZE { heldItem = ITEM_NONE; }
    PARAMETRIZE { heldItem = ITEM_PIXIE_PLATE; }
    GIVEN {
        PLAYER(SPECIES_ARCEUS) { Item(heldItem); }
        OPPONENT(SPECIES_DRAGONITE);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); MOVE(player, MOVE_JUDGMENT); }
    } SCENE {
        MESSAGE("The opposing Dragonite used Embargo!");
        MESSAGE("Arceus can't use items anymore!");
        MESSAGE("Arceus used Judgment!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Embargo disables the effect of the Drive items on the move Techno Blast", s16 damage)
{
    enum Item heldItem;

    PARAMETRIZE { heldItem = ITEM_NONE; }
    PARAMETRIZE { heldItem = ITEM_SHOCK_DRIVE; }
    GIVEN {
        PLAYER(SPECIES_GENESECT) { Item(heldItem); }
        OPPONENT(SPECIES_GYARADOS);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); MOVE(player, MOVE_TECHNO_BLAST); }
    } SCENE {
        MESSAGE("The opposing Gyarados used Embargo!");
        MESSAGE("Genesect can't use items anymore!");
        MESSAGE("Genesect used Techno Blast!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Embargo disables the effect of the Memory items on the move Multi Attack", s16 damage)
{
    enum Item heldItem;

    PARAMETRIZE { heldItem = ITEM_NONE; }
    PARAMETRIZE { heldItem = ITEM_FIRE_MEMORY; }
    GIVEN {
        PLAYER(SPECIES_SILVALLY) { Item(heldItem); }
        OPPONENT(SPECIES_VENUSAUR);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBARGO); MOVE(player, MOVE_MULTI_ATTACK); }
    } SCENE {
        MESSAGE("The opposing Venusaur used Embargo!");
        MESSAGE("Silvally can't use items anymore!");
        MESSAGE("Silvally used Multi-Attack!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Embargo can be reflected by Magic Coat")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LIGHT_BALL); }
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_EMBARGO); }
        TURN { MOVE(opponent, MOVE_FLING); }
    } SCENE {
        // Turn 1
        MESSAGE("Wobbuffet used Magic Coat!");
        MESSAGE("Wobbuffet shrouded itself with Magic Coat!");
        MESSAGE("The opposing Wobbuffet used Embargo!");
        MESSAGE("Wobbuffet bounced the Embargo back!");
        MESSAGE("The opposing Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("The opposing Wobbuffet used Fling!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("Embargo doesn't prevent Mega Evolution")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHARIZARD) { Item(ITEM_CHARIZARDITE_Y); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBARGO); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        // Turn 1
        MESSAGE("Wobbuffet used Embargo!");
        MESSAGE("The opposing Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("The opposing Wobbuffet used Baton Pass!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        MESSAGE("2 sent out Charizard!");
        // Turn 3
        MESSAGE("The opposing Charizard's Charizardite Y is reacting to 2's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        MESSAGE("The opposing Charizard has Mega Evolved into Mega Charizard!");
    }
}

SINGLE_BATTLE_TEST("Embargo doesn't prevent Primal Reversion")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GROUDON) { Item(ITEM_RED_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBARGO); }
        TURN { MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(opponent, MOVE_FLING); }
    } SCENE {
        // Turn 1
        MESSAGE("Wobbuffet used Embargo!");
        MESSAGE("The opposing Wobbuffet can't use items anymore!");
        // Turn 2
        MESSAGE("The opposing Wobbuffet used Baton Pass!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
        MESSAGE("2 sent out Groudon!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_PRIMAL_REVERSION, opponent);
        MESSAGE("The opposing Groudon's Primal Reversion! It reverted to its primal state!");
        ABILITY_POPUP(opponent);
        // Turn 3
        MESSAGE("The opposing Groudon used Fling!");
        MESSAGE("But it failed!");
    }
}

TO_DO_BATTLE_TEST("Embargo doesn't prevent the usage of Z-Moves")
TO_DO_BATTLE_TEST("Embargo doesn't block held item effects that affect prize money")
