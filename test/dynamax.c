#include "global.h"
#include "test_battle.h"

// TODO:
// ==========
// TEST: Max Guard protects against Transform, Block (not Mean Look), Flower Shield, Gear Up, and so on (see Bulba).
// TEST: Imprison doesn't stop Max Moves. (YES!)
// TEST: Max Moves change type as you'd expect with Normalize, Weather Ball, etc. (YES!)
// TEST: You use Struggle while Dynamaxed if out of PP. (YES!)
// Dynamax should not reset Speed Swap, Soak, or anything else from form changing. (NO)
// Max Moves cannot be used against allies. (NO)

// ============= DYNAMAX AND MAX MOVE INTERACTIONS ===================
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamax increases HP and max HP by 1.5x")
{
    GIVEN { // TODO: Dynamax level
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(80); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } FINALLY {
        EXPECT_EQ(player->hp, 120);
        EXPECT_EQ(player->maxHP, 150);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamax expires after three turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); HP(80); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); } // 1st max move
        TURN { MOVE(player, MOVE_TACKLE); } // 2nd max move
        TURN { MOVE(player, MOVE_TACKLE); } // 3rd max move
    } SCENE {
        int i;
        for (i = 0; i < DYNAMAX_TURNS; ++i) {
            MESSAGE("Wobbuffet used Max Strike!");
            MESSAGE("Foe Wobbuffet used Celebrate!");
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } FINALLY {
        EXPECT_EQ(player->hp, 80);
        EXPECT_EQ(player->maxHP, 100);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot be flinched")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FAKE_OUT].effect == EFFECT_FAKE_OUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_FAKE_OUT); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Fake Out!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

// Message is "Steelix shook its head. It seems like it can't use this move..."?
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot be hit by weight-based moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_HEAVY_SLAM].effect == EFFECT_HEAT_CRASH);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_HEAVY_SLAM); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Heavy Slam!");
        MESSAGE("The move was blocked by the power of Dynamax!");
        NONE_OF { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot be hit by OHKO moves")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_FISSURE].effect == EFFECT_OHKO);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_FISSURE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Machamp used Fissure!");
        MESSAGE("Wobbuffet is unaffected!");
        NONE_OF { HP_BAR(player); }
    }
}

// can't be used at all in Raid, see "Documenting Dynamax"
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by Destiny Bond")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DESTINY_BOND); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Destiny Bond!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet fainted!");
        NONE_OF { HP_BAR(player); }
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are affected by Grudge")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); };
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRUDGE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Grudge!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Wobbuffet's Tackle lost all its PP due to the GRUDGE!");
        MESSAGE("Foe Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by phazing moves, but still take damage")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_DRAGON_TAIL].effect == EFFECT_HIT_SWITCH_TARGET);
        ASSUME(gBattleMoves[MOVE_WHIRLWIND].effect == EFFECT_ROAR);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN { MOVE(opponent, MOVE_WHIRLWIND); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Dragon Tail!");
        HP_BAR(player);
        MESSAGE("The move was blocked by the power of Dynamax!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Whirlwind!");
        MESSAGE("The move was blocked by the power of Dynamax!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by Red Card")
{
    GIVEN {
        ASSUME(gItems[ITEM_RED_CARD].holdEffect == HOLD_EFFECT_RED_CARD);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_RED_CARD); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        MESSAGE("Foe Wobbuffet held up its Red Card against Wobbuffet!");
        MESSAGE("The move was blocked by the power of Dynamax!");
    } FINALLY {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can be switched out by Eject Button")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_TACKLE); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Wobbuffet is switched out with the Eject Button!");
    } FINALLY {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot have their ability swapped to another Pokemon's")
{
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        PLAYER(SPECIES_MILTANK) { Ability(ABILITY_SCRAPPY); }
        OPPONENT(SPECIES_RUNERIGUS) { Ability(ABILITY_WANDERING_SPIRIT); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_SKILL_SWAP); }
    } SCENE {
        MESSAGE("Miltank used Max Strike!");
        MESSAGE("Foe Runerigus used Skill Swap!");
        MESSAGE("But it failed!");
    } FINALLY {
        EXPECT_EQ(player->ability, ABILITY_SCRAPPY);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can have their ability changed or suppressed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_SIMPLE_BEAM); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Simple Beam!");
        MESSAGE("Wobbuffet acquired Simple!");
    } FINALLY {
        EXPECT_EQ(player->ability, ABILITY_SIMPLE);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Encore")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_ENCORE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Encore!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can be encored immediately after reverting")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); };
    } WHEN {
        TURN { MOVE(player, MOVE_ARM_THRUST, dynamax: TRUE); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(player, MOVE_ARM_THRUST); }
        TURN { MOVE(opponent, MOVE_ENCORE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Wobbuffet used Max Knuckle!");
        MESSAGE("Foe Wobbuffet used Encore!");
        MESSAGE("Wobbuffet used Arm Thrust!");
    }
}

// Max Moves don't make contact, so Cursed Body doesn't need to be tested? Implemented a check anyway
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon's Max Moves cannot be disabled")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_DISABLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Disable!");
        MESSAGE("But it failed!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can have base moves disabled on their first turn")
{
    GIVEN {
        ASSUME(B_DISABLE_TURNS >= GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); };
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_TACKLE); }
        TURN { MOVE(opponent, MOVE_DISABLE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN {}
        TURN {}
        TURN { MOVE(player, MOVE_TACKLE, allowed: FALSE); MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Celebrate!");
        MESSAGE("Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Disable!");
        MESSAGE("Wobbuffet's Tackle was disabled!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Torment")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_TORMENT); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Torment!");
        MESSAGE("But it failed!");
    }
}

// This is true for all item-removing moves.
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not immune to Knock Off")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POTION); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_KNOCK_OFF); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Knock Off!");
        MESSAGE("Foe Wobbuffet knocked off Wobbuffet's Potion!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon lose their substitutes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Substitute!");
        MESSAGE("Wobbuffet made a SUBSTITUTE!");
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        HP_BAR(player);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon can have their base moves copied by Copycat")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TRICK_ROOM, dynamax: TRUE, target: opponentLeft); MOVE(playerRight, MOVE_COPYCAT, target: opponentLeft); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Guard!");
        MESSAGE("Wynaut used Trick Room!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon take double damage from Dynamax Cannon", s16 damage)
{
    bool32 dynamaxed;
    PARAMETRIZE { dynamaxed = FALSE; }
    PARAMETRIZE { dynamaxed = TRUE; }
    GIVEN {
        ASSUME(gBattleMoves[MOVE_DYNAMAX_CANNON].effect == EFFECT_DYNAMAX_DOUBLE_DMG);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: dynamaxed); MOVE(opponent, MOVE_DYNAMAX_CANNON); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Moves deal 1/4 damage through protect", s16 damage)
{
    bool32 protected;
    KNOWN_FAILING; // // damage isn't equal because RNG misbehaves
    PARAMETRIZE { protected = FALSE; }
    PARAMETRIZE { protected = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (protected)
            TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_PROTECT); }
        else
            TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(0.25), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Moves don't bypass Max Guard")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_PROTECT, dynamax: TRUE); }
    } SCENE {
        NONE_OF { HP_BAR(opponent); }
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) Feint bypasses Max Guard but doesn't break it")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PROTECT, dynamax: TRUE);
               MOVE(opponentLeft, MOVE_FEINT, target: playerLeft);
               MOVE(opponentRight, MOVE_TACKLE, target: playerLeft);
        }
    } SCENE {
        MESSAGE("Wobbuffet used Max Guard!");
        MESSAGE("Foe Wobbuffet used Feint!");
        HP_BAR(playerLeft);
        MESSAGE("Foe Wynaut used Tackle!");
        NONE_OF { HP_BAR(playerLeft); }
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are immune to Instruct")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, dynamax: TRUE, target: opponentLeft);
               MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft);
        }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Wynaut used Instruct!");
        MESSAGE("But it failed!");
    }
}

// TODO: Gigantamax factor
SINGLE_BATTLE_TEST("(DYNAMAX) Pokemon with Gigantamax forms change upon Dynamaxing")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } FINALLY {
        EXPECT_EQ(gBattleMons[B_POSITION_PLAYER_LEFT].species, SPECIES_VENUSAUR_GMAX);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Pokemon with Gigantamax forms revert upon switching")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } FINALLY {
        EXPECT_EQ(gBattleMons[B_POSITION_PLAYER_LEFT].species, SPECIES_VENUSAUR);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Pokemon with Gigantamax forms revert upon fainting")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { HP(1); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); MOVE(opponent, MOVE_TACKLE); }
    } FINALLY {
        EXPECT_EQ(gBattleMons[B_POSITION_PLAYER_LEFT].species, SPECIES_VENUSAUR);
    }
}

// Move selection tests can't be simulated :(
SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon are not affected by Choice items", s16 damage)
{
    u16 item;
    PARAMETRIZE { item = ITEM_CHOICE_BAND; }
    PARAMETRIZE { item = ITEM_NONE; }
    GIVEN {
        ASSUME(gItems[ITEM_CHOICE_BAND].holdEffect == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Dynamaxed Pokemon cannot use Max Guard while holding Assault Vest")
{
    GIVEN {
        ASSUME(gItems[ITEM_ASSAULT_VEST].holdEffect == HOLD_EFFECT_ASSAULT_VEST);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_ASSAULT_VEST); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN { MOVE(player, MOVE_PROTECT, allowed: FALSE); MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("Wobbuffet used Max Strike!");
    }
}

// Almost anything that calculates gBattleMoveDamage based on HP has been changed to non-Dynamax HP.
// This includes Leftovers, Life Orb, Heal Pulse, Rocky Helmet, Sandstorm, etc. etc.
// There are some redundant cases (i.e Substitute) that can never be used by a Dynamaxed pokemon.
// Anything that is conditional based off max HP still uses gBattleMons[battler].maxHP.
// Below are some tests, but very far from all encompassing:

SINGLE_BATTLE_TEST("(DYNAMAX) Endeavor uses a Pokemon's non-Dynamax HP")
{
    s16 damage;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_ENDEAVOR].effect == EFFECT_ENDEAVOR);
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(100); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); MaxHP(100); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENDEAVOR); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Endeavor!");
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, 99); // difference between foe's HP and player's non-dynamax HP
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Super Fang uses a Pokemon's non-Dynamax HP")
{
    s16 damage;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_SUPER_FANG].effect == EFFECT_SUPER_FANG);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPER_FANG); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Super Fang!");
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, 25);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Pain Split uses a Pokemon's non-Dynamax HP")
{
    s16 damage;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_PAIN_SPLIT].effect == EFFECT_PAIN_SPLIT);
        PLAYER(SPECIES_WOBBUFFET) { HP(60); MaxHP(100); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(40); MaxHP(100); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PAIN_SPLIT); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Pain Split!");
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, 10);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Sitrus Berries heal based on a Pokemon's non-Dynamax HP")
{
    s16 damage;
    GIVEN {
        ASSUME(I_SITRUS_BERRY_HEAL >= GEN_4);
        ASSUME(gItems[ITEM_SITRUS_BERRY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
        PLAYER(SPECIES_WOBBUFFET) { HP(60); MaxHP(100); Speed(50); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(40); MaxHP(100); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_PAIN_SPLIT); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Pain Split!");
        HP_BAR(player);
        MESSAGE("Wobbuffet's Sitrus Berry restored health!");
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, 25);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Heal Pulse heals based on a Pokemon's non-Dynamax HP")
{
    s16 damage;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_HEAL_PULSE].effect == EFFECT_HEAL_PULSE);
        PLAYER(SPECIES_WOBBUFFET) { HP(50); MaxHP(100); Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_PULSE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used Heal Pulse!");
        HP_BAR(player, captureDamage: &damage);
    } FINALLY {
        EXPECT_EQ(damage, 50);
    }
}

// ============= MAX MOVE EFFECTS ==========================================
SINGLE_BATTLE_TEST("(DYNAMAX) Max Strike lowers single opponent's speed")
{
    GIVEN {
        // Fails?: ASSUME(GetMaxMove(B_POSITION_PLAYER_LEFT, MOVE_TACKLE) == MOVE_MAX_STRIKE);
        ASSUME(gBattleMoves[MOVE_MAX_STRIKE].argument == MAX_EFFECT_LOWER_SPEED);
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); MOVE(player, MOVE_TACKLE, dynamax: TRUE); }
        TURN { MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        // turn 1
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

// This test should apply to all stat-lowering Max Moves, including G-Max Foam Burst and G-Max Tartness.
DOUBLE_BATTLE_TEST("(DYNAMAX) Max Strike lowers both opponents' speed")
{
    GIVEN {
        // Fails? ASSUME(GetMaxMove(B_POSITION_PLAYER_LEFT, MOVE_TACKLE) == MOVE_MAX_STRIKE);
        ASSUME(gBattleMoves[MOVE_MAX_STRIKE].argument == MAX_EFFECT_LOWER_SPEED);
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(79); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(99); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft, dynamax: TRUE); \
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); \
               MOVE(opponentRight, MOVE_TACKLE, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_TACKLE, target: playerLeft); \
               MOVE(opponentRight, MOVE_TACKLE, target: playerLeft); }
    } SCENE {
        // turn 1
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Wobbuffet's speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("Foe Wobbuffet's speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("Foe Wobbuffet's speed fell!");
        MESSAGE("Foe Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Tackle!");
    }
}

// This test should apply to all stat-boosting Max Moves, too.
DOUBLE_BATTLE_TEST("(DYNAMAX) Max Knuckle raises both allies' attack")
{
    s16 damage[4];
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_KNUCKLE].argument == MAX_EFFECT_RAISE_TEAM_ATTACK);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CLOSE_COMBAT, target: opponentLeft, dynamax: TRUE); \
               MOVE(playerRight, MOVE_TACKLE, target: opponentRight); }
        TURN { MOVE(playerLeft, MOVE_CLOSE_COMBAT, target: opponentLeft); \
               MOVE(playerRight, MOVE_TACKLE, target: opponentRight); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Max Knuckle!");
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's attack rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Wynaut's attack rose!");
        MESSAGE("Wynaut used Tackle!");
        HP_BAR(opponentRight, captureDamage: &damage[1]);
        MESSAGE("Foe Wobbuffet used Celebrate!");
        MESSAGE("Foe Wynaut used Celebrate!");
        // turn 2
        MESSAGE("Wobbuffet used Max Knuckle!");
        HP_BAR(opponentLeft, captureDamage: &damage[2]);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's attack rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Wynaut's attack rose!");
        MESSAGE("Wynaut used Tackle!");
        HP_BAR(opponentRight, captureDamage: &damage[3]);
    } FINALLY {
        EXPECT_GT(damage[2], damage[0]);
        EXPECT_GT(damage[3], damage[1]);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Flare sets up sunlight")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_FLARE].argument == MAX_EFFECT_SUN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Flare!");
        MESSAGE("The sunlight got bright!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SUN_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Geyser sets up heavy rain")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_GEYSER].argument == MAX_EFFECT_RAIN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Geyser!");
        MESSAGE("It started to rain!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Hailstorm sets up hail")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_HAILSTORM].argument == MAX_EFFECT_HAIL);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWDER_SNOW, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Hailstorm!");
        MESSAGE("It started to hail!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HAIL_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Rockfall sets up a sandstorm")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_ROCKFALL].argument == MAX_EFFECT_SANDSTORM);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Rockfall!");
        MESSAGE("A sandstorm brewed!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SANDSTORM_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Overgrowth sets up Grassy Terrain")
{
    KNOWN_FAILING; // Grassy terrain bugged #2820
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_OVERGROWTH].argument == MAX_EFFECT_GRASSY_TERRAIN);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(256); HP(128); };
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(256); HP(128); };
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP, dynamax: TRUE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_VINE_WHIP); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Overgrowth!");
        MESSAGE("Foe Wobbuffet cannot use Celebrate!");
        HP_BAR(player, damage: -256/16);
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Mindstorm sets up Psychic Terrain")
{
    // TODO: BG doesn't seem to load?
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_MINDSTORM].argument == MAX_EFFECT_PSYCHIC_TERRAIN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_PSYCHIC, dynamax: TRUE); }
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        MESSAGE("Foe Wobbuffet used ExtremeSpeed!");
        MESSAGE("Wobbuffet used Max Mindstorm!");
        MESSAGE("Foe Wobbuffet cannot use ExtremeSpeed!");
        MESSAGE("Wobbuffet used Max Mindstorm!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Lightning sets up Electric Terrain")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_LIGHTNING].argument == MAX_EFFECT_ELECTRIC_TERRAIN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT, dynamax: TRUE); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Lightning!");
        MESSAGE("Foe Wobbuffet used Spore!");
        MESSAGE("Wobbuffet surrounds itself with electrified terrain!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) Max Starfall sets up Misty Terrain")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_MAX_STARFALL].argument == MAX_EFFECT_MISTY_TERRAIN);
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MOONBLAST, dynamax: TRUE); MOVE(opponent, MOVE_TOXIC); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Starfall!");
        MESSAGE("Foe Wobbuffet used Toxic!");
        MESSAGE("Wobbuffet surrounds itself with a protective mist!");
    }
}

SINGLE_BATTLE_TEST("(DYNAMAX) G-Max Stonesurge sets up Stealth Rocks")
{
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_STONESURGE].argument == MAX_EFFECT_STEALTH_ROCK);
        PLAYER(SPECIES_DREDNAW);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LIQUIDATION, dynamax: TRUE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        // turn 1
        MESSAGE("Drednaw used G-Max Stonesurge!");
        MESSAGE("Pointed stones float in the air around the opposing team!");
        // turn 2
        MESSAGE("Pointed stones dug into Foe Wobbuffet!");
    }
}

// The test below also tests that sharp steel does type-based damage and can be Defogged away.
SINGLE_BATTLE_TEST("(DYNAMAX) G-Max Steelsurge sets up sharp steel")
{
    s16 damage;
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_STEELSURGE].argument == MAX_EFFECT_STEELSURGE);
        PLAYER(SPECIES_COPPERAJAH);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFABLE) { MaxHP(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_HEAD, dynamax: TRUE); }
        TURN { SWITCH(opponent, 1); }
        TURN { } // wait out Dynamax
        TURN { MOVE(opponent, MOVE_DEFOG); }
    } SCENE {
        // turn 1
        MESSAGE("Copperajah used G-Max Steelsurge!");
        MESSAGE("Sharp-pointed steel floats around the opposing team!");
        // turn 2
        HP_BAR(opponent, captureDamage: &damage);
        MESSAGE("Sharp steel bit into Foe Clefable!");
        // turn 4
        MESSAGE("Foe Clefable used Defog!");
        MESSAGE("The sharp steel disappeared from the ground around the opposing team!");
    } FINALLY {
        EXPECT_EQ(damage, 25);
    }
}

// The test below should apply to G-Max Fireball and G-Max Drum Solo, too.
SINGLE_BATTLE_TEST("(DYNAMAX) G-Max Hydrosnipe has fixed power and ignores abilities", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_WATER_GUN; }
    PARAMETRIZE { move = MOVE_HYDRO_CANNON; }
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_HYDROSNIPE].argument == MAX_EFFECT_FIXED_POWER);
        PLAYER(SPECIES_INTELEON);
        OPPONENT(SPECIES_ARCTOVISH) { Ability(ABILITY_WATER_ABSORB); }
    } WHEN {
        TURN { MOVE(player, move, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Inteleon used G-Max Hydrosnipe!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Volt Crash paralyzes both opponents")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_G_MAX_VOLT_CRASH].argument == MAX_EFFECT_PARALYZE_FOES);
        PLAYER(SPECIES_PIKACHU);
        PLAYER(SPECIES_PICHU);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_THUNDERBOLT, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Pikachu used G-Max Volt Crash!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentLeft);
        STATUS_ICON(opponentLeft, paralysis: TRUE);
        MESSAGE("Foe Wobbuffet is paralyzed! It may be unable to move!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentRight);
        STATUS_ICON(opponentRight, paralysis: TRUE);
        MESSAGE("Foe Wynaut is paralyzed! It may be unable to move!");
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Stun Shock paralyzes or poisons both opponents")
{
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_STUN_SHOCK].argument == MAX_EFFECT_POISON_PARALYZE_FOES);
        PLAYER(SPECIES_TOXTRICITY);
        PLAYER(SPECIES_TOXEL);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_THUNDERBOLT, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Toxtricity used G-Max Stun Shock!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentLeft);
        STATUS_ICON(opponentLeft, poison: TRUE);
        MESSAGE("Foe Wobbuffet was poisoned!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentRight);
        STATUS_ICON(opponentRight, paralysis: TRUE);
        MESSAGE("Foe Wynaut is paralyzed! It may be unable to move!");
    }
}

// This test extends to G-Max Befuddle, too.
DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Stun Shock chooses statuses before considering immunities")
{
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_STUN_SHOCK].argument == MAX_EFFECT_POISON_PARALYZE_FOES);
        PLAYER(SPECIES_TOXTRICITY);
        PLAYER(SPECIES_TOXEL);
        OPPONENT(SPECIES_GARBODOR);
        OPPONENT(SPECIES_TRUBBISH);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_NUZZLE, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Toxtricity used G-Max Stun Shock!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentLeft);
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentLeft);
        }
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentRight);
        MESSAGE("Foe Trubbish is paralyzed! It may be unable to move!");
        STATUS_ICON(opponentRight, paralysis: TRUE);
    } FINALLY {
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].status1, STATUS1_NONE);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Befuddle paralyzes, poisons, or sleeps both opponents")
{
    GIVEN {
        RNGSeed(0x10000);
        ASSUME(gBattleMoves[MOVE_G_MAX_BEFUDDLE].argument == MAX_EFFECT_EFFECT_SPORE_FOES);
        PLAYER(SPECIES_BUTTERFREE);
        PLAYER(SPECIES_CATERPIE);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BUG_BITE, target: opponentLeft, dynamax: TRUE); }
        TURN { SWITCH(opponentLeft, 2); SWITCH(opponentRight, 3); \
               MOVE(playerLeft, MOVE_BUG_BITE, target: opponentLeft); }
    } SCENE {
        // turn 1
        MESSAGE("Butterfree used G-Max Befuddle!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentLeft);
        STATUS_ICON(opponentLeft, poison: TRUE);
        MESSAGE("Foe Wobbuffet was poisoned!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
        STATUS_ICON(opponentRight, sleep: TRUE);
        MESSAGE("Foe Wobbuffet fell asleep!");
        // turn 2
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentLeft);
        MESSAGE("Foe Wobbuffet is paralyzed! It may be unable to move!");
        STATUS_ICON(opponentLeft, paralysis: TRUE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponentRight);
        MESSAGE("Foe Wobbuffet was poisoned!");
        STATUS_ICON(opponentRight, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Gold Rush confuses both opponents and generates money")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_G_MAX_GOLD_RUSH].argument == MAX_EFFECT_CONFUSE_FOES_PAY_DAY);
        PLAYER(SPECIES_MEOWTH);
        PLAYER(SPECIES_PERSIAN);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Meowth used G-Max Gold Rush!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentLeft);
        MESSAGE("Foe Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentRight);
        MESSAGE("Foe Wobbuffet became confused!");
        MESSAGE("Coins scattered everywhere!");
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Smite confuses both opponents")
{
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_SMITE].argument == MAX_EFFECT_CONFUSE_FOES);
        PLAYER(SPECIES_HATTERENE);
        PLAYER(SPECIES_HATENNA);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MOONBLAST, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Hatterene used G-Max Smite!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentLeft);
        MESSAGE("Foe Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentRight);
        MESSAGE("Foe Wobbuffet became confused!");
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Cuddle infatuates both opponents, if possible")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_G_MAX_CUDDLE].argument == MAX_EFFECT_INFATUATE_FOES);
        PLAYER(SPECIES_EEVEE) { Gender(MON_MALE); }
        PLAYER(SPECIES_EEVEE);
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_MALE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Eevee used G-Max Cuddle!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_INFATUATION, opponentLeft);
        MESSAGE("Foe Wobbuffet fell in love!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_INFATUATION, opponentRight);
            MESSAGE("Foe Wobbuffet became confused!");
        }
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Terror traps both opponents")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_G_MAX_TERROR].argument == MAX_EFFECT_MEAN_LOOK);
        PLAYER(SPECIES_GENGAR);
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LICK, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Gengar used G-Max Terror!");
        MESSAGE("Foe Wobbuffet can't escape now!");
        MESSAGE("Foe Wobbuffet can't escape now!");
    } FINALLY { // Can't find good way to test trapping
        EXPECT(gBattleMons[B_POSITION_OPPONENT_LEFT].status2 & STATUS2_ESCAPE_PREVENTION);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Meltdown torments both opponents for 3 turns")
{
    GIVEN {
        ASSUME(P_GEN_7_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_MELTDOWN].argument == MAX_EFFECT_TORMENT_FOES);
        PLAYER(SPECIES_MELMETAL);
        PLAYER(SPECIES_MELTAN);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_SPLASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_IRON_HEAD, target: opponentLeft, dynamax: TRUE); \
               MOVE(opponentLeft, MOVE_SPLASH); MOVE(opponentRight, MOVE_SPLASH); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_SPLASH, allowed: FALSE); \
               MOVE(opponentLeft, MOVE_CELEBRATE); \
               MOVE(opponentRight, MOVE_SPLASH, allowed: FALSE); \
               MOVE(opponentRight, MOVE_CELEBRATE); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_SPLASH); \
               MOVE(opponentRight, MOVE_SPLASH); }
    } SCENE {
        // turn 1
        MESSAGE("Melmetal used G-Max Meltdown!");
        MESSAGE("Foe Wobbuffet was subjected to torment!");
        MESSAGE("Foe Wynaut was subjected to torment!");
        MESSAGE("Foe Wobbuffet used Splash!");
        MESSAGE("Foe Wynaut used Splash!");
        // turn 2
        MESSAGE("Foe Wobbuffet used Celebrate!");
        MESSAGE("Foe Wynaut used Celebrate!");
        // end of turn 3
        MESSAGE("Foe Wobbuffet is tormented no more!");
        MESSAGE("Foe Wynaut is tormented no more!");
    }
}

// This test applies to G-Max Cannonade, G-Max Vine Lash, and G-Max Volcalith, too.
DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Wildfire sets a field effect that damages non-Fire types")
{
    s16 damage;
    GIVEN {
        ASSUME(gBattleMoves[MOVE_G_MAX_WILDFIRE].argument == MAX_EFFECT_WILDFIRE);
        PLAYER(SPECIES_CHARIZARD);
        PLAYER(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_WOBBUFFET) { HP(600); MaxHP(600); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ARCANINE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EMBER, target: opponentLeft, dynamax: TRUE); }
        TURN { }
        TURN { SWITCH(opponentLeft, 2); }
        TURN { }
        TURN { }
    } SCENE {
        // turn 1
        MESSAGE("Charizard used G-Max Wildfire!");
        MESSAGE("The opposing team was surrounded by flames!");
        MESSAGE("Foe Wobbuffet is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentLeft, captureDamage: &damage);
        MESSAGE("Foe Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 2
        MESSAGE("Foe Wobbuffet is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 3
        NONE_OF { MESSAGE("Foe Arcanine is burning up within G-Max Wildfire's flames!"); }
        MESSAGE("Foe Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 4
        MESSAGE("Foe Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 5
        NONE_OF { 
            HP_BAR(opponentRight);
            MESSAGE("Foe Wynaut is burning up within G-Max Wildfire's flames!");
        }
    } FINALLY {
        EXPECT_EQ(damage, 100);
    }
}

// This should probably be tested to only occur 50% of the time.
// I had some problems specific to Teatime with this where Snorlax stored
// the used berry in usedHeldItem, while Munchlax stored it in changedItem.
DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Replenish recycles allies' berries")
{
    GIVEN {
        ASSUME(gBattleMoves[MOVE_G_MAX_REPLENISH].argument == MAX_EFFECT_RECYCLE_BERRIES);
        PLAYER(SPECIES_SNORLAX) { Item(ITEM_APICOT_BERRY); }
        PLAYER(SPECIES_MUNCHLAX) { Item(ITEM_APICOT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_APICOT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_APICOT_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STUFF_CHEEKS); \
               MOVE(playerRight, MOVE_STUFF_CHEEKS); \
               MOVE(opponentLeft, MOVE_STUFF_CHEEKS); \
               MOVE(opponentRight, MOVE_STUFF_CHEEKS); }
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        // turn 1
        MESSAGE("Using Apicot Berry, the sp. defense of Snorlax rose!");
        MESSAGE("Using Apicot Berry, the sp. defense of Munchlax rose!");
        MESSAGE("Using Apicot Berry, the sp. defense of Foe Wobbuffet rose!");
        MESSAGE("Using Apicot Berry, the sp. defense of Foe Wobbuffet rose!");
        // turn 2
        MESSAGE("Snorlax used G-Max Replenish!");
        MESSAGE("Snorlax found one Apicot Berry!");
        MESSAGE("Munchlax found one Apicot Berry!");
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Snooze makes only the target drowsy")
{
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_SNOOZE].argument == MAX_EFFECT_YAWN_FOE);
        PLAYER(SPECIES_GRIMMSNARL);
        PLAYER(SPECIES_IMPIDIMP);
        OPPONENT(SPECIES_BLISSEY);
        OPPONENT(SPECIES_CHANSEY);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DARK_PULSE, target: opponentLeft, dynamax: TRUE); }
        TURN { }
    } SCENE {
        // turn 1
        MESSAGE("Grimmsnarl used G-Max Snooze!");
        MESSAGE("Grimmsnarl made Foe Blissey drowsy!");
        NONE_OF { MESSAGE("Grimmsnarl made Foe Chansey drowsy!"); }
        // turn 2
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("Foe Blissey fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentRight);
            STATUS_ICON(opponentRight, sleep: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Finale heals allies by 1/6 of their health")
{
    s16 damage1, damage2;
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_FINALE].argument == MAX_EFFECT_HEAL_TEAM);
        PLAYER(SPECIES_ALCREMIE) { HP(200); MaxHP(300); }
        PLAYER(SPECIES_MILCERY) { HP(200); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MOONBLAST, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        // turn 1
        MESSAGE("Alcremie used G-Max Finale!");
        HP_BAR(playerLeft, captureDamage: &damage1);
        HP_BAR(playerRight, captureDamage: &damage2);
    } FINALLY {
        EXPECT_EQ(damage1, -75); // heals based on Dynamax HP
        EXPECT_EQ(damage2, -50);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Sweetness cures allies' status conditions")
{
    s16 damage1, damage2;
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_SWEETNESS].argument == MAX_EFFECT_AROMATHERAPY);
        PLAYER(SPECIES_APPLETUN) { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_APPLIN)  { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_VINE_WHIP, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Appletun used G-Max Sweetness!");
        STATUS_ICON(playerLeft, none: TRUE);
        MESSAGE("Appletun's status returned to normal!");
        STATUS_ICON(playerRight, none: TRUE);
        MESSAGE("Applin's status returned to normal!");
    }
}

// This test should apply to G-Max Sandblast, too.
DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Centiferno traps both opponents in Fire Spin")
{
    s16 damage1, damage2;
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_CENTIFERNO].argument == MAX_EFFECT_FIRE_SPIN_FOES);
        PLAYER(SPECIES_CENTISKORCH);
        PLAYER(SPECIES_SIZZLIPEDE);
        PLAYER(SPECIES_SIZZLIPEDE);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FLAME_CHARGE, target: opponentLeft, dynamax: TRUE); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        // turn 1
        MESSAGE("Centiskorc used G-Max Centiferno!");
        MESSAGE("Foe Wobbuffet is hurt by Fire Spin!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Wynaut is hurt by Fire Spin!");
        HP_BAR(opponentRight);
        // turn 2 - Fire Spin continues even after Centiskorch switches out
        MESSAGE("Foe Wobbuffet is hurt by Fire Spin!");
        HP_BAR(opponentLeft);
        MESSAGE("Foe Wynaut is hurt by Fire Spin!");
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Chi Strike boosts allies' crit chance")
{
    s16 damage1, damage2;
    GIVEN {
        ASSUME(B_CRIT_CHANCE >= GEN_6);
        ASSUME(gBattleMoves[MOVE_G_MAX_CHI_STRIKE].argument == MAX_EFFECT_CRIT_PLUS);
        PLAYER(SPECIES_MACHAMP);
        PLAYER(SPECIES_MACHOP);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FORCE_PALM, target: opponentLeft, dynamax: TRUE); \
               MOVE(playerRight, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(playerRight, MOVE_FORCE_PALM, target: opponentLeft); }
    } SCENE {
        // turn 1
        MESSAGE("Machamp used G-Max Chi Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Machamp is getting pumped!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Machop is getting pumped!");
        MESSAGE("Machop used Focus Energy!");
        MESSAGE("Machop is getting pumped!");
        // turn 2
        MESSAGE("Machop used Force Palm!"); // Machop is at +3 crit stages, 100% crit chance
        MESSAGE("A critical hit!");
    }
}

DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max Depletion takes away 2 PP from the target's last move")
{
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_DEPLETION].argument == MAX_EFFECT_SPITE);
        PLAYER(SPECIES_DURALUDON);
        PLAYER(SPECIES_WYNAUT);
        // Dynamax behaves weird with test turn order because stats are recalculated.
        OPPONENT(SPECIES_SABLEYE) { Ability(ABILITY_PRANKSTER); } 
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_CLAW, target: opponentLeft, dynamax: TRUE); }
    } SCENE {
        MESSAGE("Foe Sableye used Celebrate!");
        MESSAGE("Duraludon used G-Max Depletion!");
        MESSAGE("Reduced Foe Sableye's Celebrate by 2!");
    }
}

// This test should apply to G-Max Rapid Flow, too.
DOUBLE_BATTLE_TEST("(DYNAMAX) G-Max One Blow bypasses Max Guard for full damage", s16 damage)
{
    bool32 protect;
    KNOWN_FAILING; // damage isn't equal because RNG misbehaves
    PARAMETRIZE { protect = TRUE; }
    PARAMETRIZE { protect = FALSE; }
    GIVEN {
        ASSUME(P_GEN_8_POKEMON == TRUE);
        ASSUME(gBattleMoves[MOVE_G_MAX_ONE_BLOW].argument == MAX_EFFECT_BYPASS_PROTECT);
        PLAYER(SPECIES_URSHIFU);
        PLAYER(SPECIES_KUBFU);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        if (protect)
            TURN { MOVE(playerLeft, MOVE_WICKED_BLOW, target: opponentLeft, dynamax: TRUE); \
                   MOVE(opponentLeft, MOVE_PROTECT, dynamax: TRUE); }
        else
            TURN { MOVE(playerLeft, MOVE_WICKED_BLOW, target: opponentLeft, dynamax: TRUE); \
                   MOVE(opponentLeft, MOVE_PSYCHIC, target: playerLeft, dynamax: TRUE); }
    } SCENE {
        if (protect)
            MESSAGE("Foe Wobbuffet used Max Guard!");
        MESSAGE("Urshifu used G-Max One Blow!");
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}
