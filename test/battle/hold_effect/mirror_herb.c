#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_MIRROR_HERB].holdEffect == HOLD_EFFECT_MIRROR_HERB);
}

SINGLE_BATTLE_TEST("Mirror Herb copies all of foe's positive stat changes in a turn", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_MIRROR_HERB; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_DANCE); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (item == ITEM_NONE) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player, captureDamage: &results[i].damage);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player, captureDamage: &results[i].damage);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        }
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_EQ(player->statStages[STAT_ATK], opponent->statStages[STAT_ATK]);
        EXPECT_EQ(player->statStages[STAT_SPEED], opponent->statStages[STAT_SPEED]);
    }
}

SINGLE_BATTLE_TEST("Mirror Herb copies all of Stuff Cheeks' stat boosts")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LIECHI_BERRY].holdEffect == HOLD_EFFECT_ATTACK_UP);
        PLAYER(SPECIES_SKWOVET) { Item(ITEM_LIECHI_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
    } WHEN {
        TURN { MOVE(player, MOVE_STUFF_CHEEKS); }
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], opponent->statStages[STAT_ATK]);
        EXPECT_EQ(player->statStages[STAT_DEF], opponent->statStages[STAT_DEF]);
    }
}

DOUBLE_BATTLE_TEST("Mirror Herb does not trigger for Ally's Soul Heart's stat raise")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
        PLAYER(SPECIES_WYNAUT) { Ability(ABILITY_SOUL_HEART); } // Raises Sp. Atk after fainting am on
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target:opponentLeft); }
    } SCENE {
        MESSAGE("Wynaut used Scratch!");
        MESSAGE("The opposing Wobbuffet fainted!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
            MESSAGE("Wobbuffet used its Mirror Herb to mirror its opponent's stat changes!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        }
    }
    THEN {
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Mirror Herb copies the boost gained by an ability")
{
    GIVEN {
        PLAYER(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Mirror Herb activates after a Mega Evolution")
{
    GIVEN {
        PLAYER(SPECIES_MANECTRIC) { Item(ITEM_MANECTITE); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
        OPPONENT(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ABILITY_POPUP(opponentLeft, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Mirror Herb does not activate or get consumed if no copied stat can be raised")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(opponent, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_MIRROR_HERB);
        EXPECT_EQ(player->statStages[STAT_ATK], MAX_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Mirror Herb does not copy stat increases gained via Mirror Herb")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->item, ITEM_MIRROR_HERB);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Mirror Herb activates with Contrary if stat is at +6")
{
    GIVEN {
        ASSUME_STAT_CHANGE(MOVE_SWORDS_DANCE, attack: +2);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
        OPPONENT(SPECIES_SNIVY) { Ability(ABILITY_CONTRARY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SKILL_SWAP); MOVE(opponent, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 4);
    }
}

SINGLE_BATTLE_TEST("Mirror Herb copies the stats boosted by Speed Boost")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MIRROR_HERB); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_SPEED_BOOST); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SPEED_BOOST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}
