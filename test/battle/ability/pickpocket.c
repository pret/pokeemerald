#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveMakesContact(MOVE_BREAKING_SWIPE));
    ASSUME(MoveMakesContact(MOVE_SCRATCH));
}

DOUBLE_BATTLE_TEST("Pickpocket checks contact/effect per target for spread moves")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CLEFAIRY, 0) == TYPE_FAIRY);
        ASSUME(GetMoveType(MOVE_BREAKING_SWIPE) == TYPE_DRAGON);
        ASSUME(GetMoveTarget(MOVE_BREAKING_SWIPE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MAGOST_BERRY); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
        OPPONENT(SPECIES_CLEFAIRY);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BREAKING_SWIPE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponentLeft->item == ITEM_MAGOST_BERRY);
        EXPECT(playerLeft->item == ITEM_NONE);
    }
}

DOUBLE_BATTLE_TEST("Pickpocket activates for the fastest itemless target when both are hit by a contact spread move")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_BREAKING_SWIPE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_MAGOST_BERRY); }
        PLAYER(SPECIES_WYNAUT) { Speed(10); }
        OPPONENT(SPECIES_SNEASEL) { Speed(40); Ability(ABILITY_PICKPOCKET); }
        OPPONENT(SPECIES_SNEASEL) { Speed(30); Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BREAKING_SWIPE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponentLeft->item == ITEM_MAGOST_BERRY);
        EXPECT(opponentRight->item == ITEM_NONE);
        EXPECT(playerLeft->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket steals the attacker's item unless it already has one")
{
    bool32 targetHasItem;
    PARAMETRIZE { targetHasItem = FALSE; }
    PARAMETRIZE { targetHasItem = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MAGOST_BERRY); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(targetHasItem ? ITEM_EVIOLITE : ITEM_NONE); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        if (targetHasItem) {
            NONE_OF {
                ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
                MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
            }
        } else {
            ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
            MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
        }
    } THEN {
        if (targetHasItem) {
            EXPECT(opponent->item == ITEM_EVIOLITE);
            EXPECT(player->item == ITEM_MAGOST_BERRY);
        } else {
            EXPECT(opponent->item == ITEM_MAGOST_BERRY);
            EXPECT(player->item == ITEM_NONE);
        }
    }
}

SINGLE_BATTLE_TEST("Pickpocket does not activate if the user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MAGOST_BERRY); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
            MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
        }
        MESSAGE("The opposing Sneasel fainted!");
    } THEN {
        EXPECT(opponent->item == ITEM_NONE);
        EXPECT(player->item == ITEM_MAGOST_BERRY);
    }
}

SINGLE_BATTLE_TEST("Pickpocket cannot steal from Sticky Hold")
{
    GIVEN {
        PLAYER(SPECIES_GRIMER) { Ability(ABILITY_STICKY_HOLD); Item(ITEM_MAGOST_BERRY); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        ABILITY_POPUP(player, ABILITY_STICKY_HOLD);
        MESSAGE("Grimer's item cannot be removed!");
    } THEN {
        EXPECT(opponent->item == ITEM_NONE);
        EXPECT(player->item == ITEM_MAGOST_BERRY);
    }
}

SINGLE_BATTLE_TEST("Pickpocket cannot steal restricted held items")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_NORMALIUM_Z].holdEffect == HOLD_EFFECT_Z_CRYSTAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        }
    } THEN {
        EXPECT(opponent->item == ITEM_NONE);
        EXPECT(player->item == ITEM_NORMALIUM_Z);
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates after the final hit of a multi-strike move")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_FURY_SWIPES));
        ASSUME(MoveMakesContact(MOVE_FURY_SWIPES));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MAGOST_BERRY); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_FURY_SWIPES, WITH_RNG(RNG_HITS, 3)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FURY_SWIPES, player);
        MESSAGE("The Pokémon was hit 3 times!");
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponent->item == ITEM_MAGOST_BERRY);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates after Magician steals an item")
{
    GIVEN {
        PLAYER(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_MAGOST_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MAGICIAN);
        MESSAGE("Delphox stole the opposing Sneasel's Magost Berry!");
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Delphox's Magost Berry!");
    } THEN {
        EXPECT(opponent->item == ITEM_MAGOST_BERRY);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates after Sticky Barb transfers")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_STICKY_BARB].holdEffect == HOLD_EFFECT_STICKY_BARB);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_STICKY_BARB); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("The Sticky Barb attached itself to Wobbuffet!");
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Sticky Barb!");
    } THEN {
        EXPECT(opponent->item == ITEM_STICKY_BARB);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates after Thief or Covet steals an item")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_THIEF; }
    PARAMETRIZE { move = MOVE_COVET; }
    GIVEN {
        ASSUME(GetMoveEffect(move) == EFFECT_STEAL_ITEM);
        ASSUME(MoveMakesContact(move));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_MAGOST_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        MESSAGE("Wobbuffet stole the opposing Sneasel's Magost Berry!");
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponent->item == ITEM_MAGOST_BERRY);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates after Focus Sash is consumed")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SEISMIC_TOSS));
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MAGOST_BERRY); Level(100); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_FOCUS_SASH); MaxHP(6); HP(6); }
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, player);
        MESSAGE("The opposing Sneasel hung on using its Focus Sash!");
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponent->item == ITEM_MAGOST_BERRY);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates after Knock Off, Bug Bite, or Pluck")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_KNOCK_OFF; }
    PARAMETRIZE { move = MOVE_BUG_BITE; }
    PARAMETRIZE { move = MOVE_PLUCK; }
    GIVEN {
        ASSUME(MoveMakesContact(move));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MAGOST_BERRY); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Magost Berry!");
    } THEN {
        EXPECT(opponent->item == ITEM_MAGOST_BERRY);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket steals Life Orb after it activates")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LIFE_ORB); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet lost some of its HP!");
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Life Orb!");
    } THEN {
        EXPECT(opponent->item == ITEM_LIFE_ORB);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket steals Shell Bell after it heals the user")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_SHELL_BELL].holdEffect == HOLD_EFFECT_SHELL_BELL);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_SHELL_BELL); MaxHP(100); HP(66); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(player);
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Shell Bell!");
    } THEN {
        EXPECT(opponent->item == ITEM_SHELL_BELL);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket does not prevent King's Rock or Razor Fang flinches")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_KINGS_ROCK].holdEffect == HOLD_EFFECT_FLINCH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_KINGS_ROCK); }
        OPPONENT(SPECIES_SNEASEL) { Speed(10); Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_HOLD_EFFECT_FLINCH, 1)); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's King's Rock!");
        MESSAGE("The opposing Sneasel flinched and couldn't move!");
    } THEN {
        EXPECT(opponent->item == ITEM_KINGS_ROCK);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates when user has Protective Pads, but not with Punching Glove or Long Reach")
{
    enum Item item;
    enum Ability ability;

    PARAMETRIZE { item = ITEM_PROTECTIVE_PADS; ability = ABILITY_OVERGROW;   }
    PARAMETRIZE { item = ITEM_PUNCHING_GLOVE;  ability = ABILITY_OVERGROW;   }
    PARAMETRIZE { item = ITEM_NONE;            ability = ABILITY_LONG_REACH; }

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_MACH_PUNCH));
        ASSUME(IsPunchingMove(MOVE_MACH_PUNCH));
        ASSUME(GetItemHoldEffect(ITEM_PROTECTIVE_PADS) == HOLD_EFFECT_PROTECTIVE_PADS);
        ASSUME(GetItemHoldEffect(ITEM_PUNCHING_GLOVE) == HOLD_EFFECT_PUNCHING_GLOVE);
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_DECIDUEYE) { Ability(ability); Item(item); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_MACH_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MACH_PUNCH, player);

        if (item == ITEM_PROTECTIVE_PADS) {
            ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        } else {
            NOT ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        }
    }
}

SINGLE_BATTLE_TEST("Pickpocket activates after an Item was knocked off")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        OPPONENT(SPECIES_SNEASEL) { Item(ITEM_POTION); Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, player);
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
    } THEN {
        EXPECT(opponent->item == ITEM_POTION);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket can steal the attacker's Air Balloon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Wobbuffet floats in the air with its Air Balloon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Air Balloon!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
        EXPECT_EQ(opponent->item, ITEM_AIR_BALLOON);
    }
}

SINGLE_BATTLE_TEST("Pickpocket steals from the original U-turn user before it switches out")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_U_TURN));
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        PLAYER(SPECIES_WYNAUT) { Item(ITEM_POKE_BALL); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Potion!");
    } THEN {
        EXPECT(opponent->item == ITEM_POTION);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket steals the attacker's item even after Red Card forces a switch")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POKE_BALL); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_RED_CARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Sneasel held up its Red Card against Wobbuffet!");
        MESSAGE("Wynaut was dragged out!");
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Wobbuffet's Poké Ball!");
    } THEN {
        EXPECT(opponent->item == ITEM_POKE_BALL);
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Pickpocket does not activate if its user switches out with Eject Button")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("The opposing Sneasel is switched out with the Eject Button!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
            MESSAGE("The opposing Sneasel stole Wobbuffet's Potion!");
        }
    } THEN {
        EXPECT(opponent->item == ITEM_NONE);
        EXPECT(player->item == ITEM_POTION);
    }
}

SINGLE_BATTLE_TEST("Pickpocket cannot steal an item if hit by a contact move that's boosted by Sheer Force (Gen9-)")
{
    GIVEN {
        // GIVEN(B_SHEER_FORCE_AGAINST_ABILITIES, GEN_9);
        ASSUME(gMovesInfo[MOVE_CRUNCH].additionalEffects->moveEffect == MOVE_EFFECT_STAT_MINUS);
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_LANDORUS) { Item(ITEM_LIFE_ORB); Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_CRUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, player);
        HP_BAR(opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
            MESSAGE("The opposing Sneasel stole Landorus's Life Orb!");
        }
    } THEN {
        EXPECT(opponent->item == ITEM_NONE);
        EXPECT(player->item == ITEM_LIFE_ORB);
    }
}

SINGLE_BATTLE_TEST("Pickpocket can steal an item even if hit by a contact move that's boosted by Sheer Force (Champions)")
{
    KNOWN_FAILING;
    GIVEN {
        // GIVEN(B_SHEER_FORCE_AGAINST_ABILITIES, GEN_CHAMPIONS);
        ASSUME(gMovesInfo[MOVE_CRUNCH].additionalEffects->moveEffect == MOVE_EFFECT_STAT_MINUS);
        ASSUME(gItemsInfo[ITEM_LIFE_ORB].holdEffect == HOLD_EFFECT_LIFE_ORB);
        PLAYER(SPECIES_LANDORUS) { Item(ITEM_LIFE_ORB); Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_SNEASEL) { Ability(ABILITY_PICKPOCKET); }
    } WHEN {
        TURN { MOVE(player, MOVE_CRUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, player);
        HP_BAR(opponent);
        ABILITY_POPUP(opponent, ABILITY_PICKPOCKET);
        MESSAGE("The opposing Sneasel stole Landorus's Life Orb!");
    } THEN {
        EXPECT(opponent->item == ITEM_LIFE_ORB);
        EXPECT(player->item == ITEM_NONE);
    }
}
