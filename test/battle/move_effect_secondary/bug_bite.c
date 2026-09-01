#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_BUG_BITE, MOVE_EFFECT_BUG_BITE));
    ASSUME(GetMovePP(MOVE_BUG_BITE) == 20);
}

// Pretty much copy/paste of the Berry Fling Test.
SINGLE_BATTLE_TEST("Bug Bite eats the target's berry and immediately gains its effect")
{
    enum Item item = ITEM_NONE;
    u32 status1 = STATUS1_NONE;
    enum HoldEffect effect = HOLD_EFFECT_NONE;
    enum Stat statId = STAT_HP;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_ORAN_BERRY; effect = HOLD_EFFECT_RESTORE_HP; }
    PARAMETRIZE { item = ITEM_SITRUS_BERRY; effect = HOLD_EFFECT_RESTORE_HP; }
    PARAMETRIZE { item = ITEM_ENIGMA_BERRY; effect = HOLD_EFFECT_ENIGMA_BERRY; }
    PARAMETRIZE { item = ITEM_LEPPA_BERRY; effect = HOLD_EFFECT_RESTORE_PP; }
    PARAMETRIZE { item = ITEM_CHESTO_BERRY; effect = HOLD_EFFECT_CURE_SLP; status1 = STATUS1_SLEEP; }
    PARAMETRIZE { item = ITEM_CHERI_BERRY; effect = HOLD_EFFECT_CURE_PAR; status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { item = ITEM_PECHA_BERRY; effect = HOLD_EFFECT_CURE_PSN; status1 = STATUS1_POISON; }
    PARAMETRIZE { item = ITEM_PECHA_BERRY; effect = HOLD_EFFECT_CURE_PSN; status1 = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { item = ITEM_RAWST_BERRY; effect = HOLD_EFFECT_CURE_BRN; status1 = STATUS1_BURN; }
    PARAMETRIZE { item = ITEM_ASPEAR_BERRY; effect = HOLD_EFFECT_CURE_FRZ; status1 = STATUS1_FROSTBITE; }
    PARAMETRIZE { item = ITEM_APICOT_BERRY; effect = HOLD_EFFECT_SP_DEFENSE_UP; statId = STAT_SPDEF; }
    PARAMETRIZE { item = ITEM_MARANGA_BERRY; effect = HOLD_EFFECT_MARANGA_BERRY; statId = STAT_SPDEF; }
    PARAMETRIZE { item = ITEM_GANLON_BERRY; effect = HOLD_EFFECT_DEFENSE_UP; statId = STAT_DEF; }
    PARAMETRIZE { item = ITEM_KEE_BERRY; effect = HOLD_EFFECT_KEE_BERRY; statId = STAT_DEF; }
    PARAMETRIZE { item = ITEM_LIECHI_BERRY; effect = HOLD_EFFECT_ATTACK_UP; statId = STAT_ATK; }
    PARAMETRIZE { item = ITEM_PETAYA_BERRY; effect = HOLD_EFFECT_SP_ATTACK_UP; statId = STAT_SPATK; }
    PARAMETRIZE { item = ITEM_SALAC_BERRY; effect = HOLD_EFFECT_SPEED_UP; statId = STAT_SPEED; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(399); MaxHP(400); Status1(status1); Moves(MOVE_SLEEP_TALK, MOVE_BUG_BITE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        // Chesto Berry can only be applied if the Pokémon is asleep and uses Sleep Talk.
        if (item == ITEM_CHESTO_BERRY) {
            TURN { MOVE(player, MOVE_SLEEP_TALK); }
        } else {
            TURN { MOVE(player, MOVE_BUG_BITE, WITH_RNG(RNG_PARALYSIS, FALSE)); }
        }

    } SCENE {
        if (item == ITEM_CHESTO_BERRY)
        {
            MESSAGE("Wobbuffet used Sleep Talk!");
        }
        MESSAGE("Wobbuffet used Bug Bite!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, player);
        HP_BAR(opponent);
        if (status1 != STATUS1_NONE) {
            if (status1 == STATUS1_BURN) {
                MESSAGE("Wobbuffet's Rawst Berry cured its burn!");
            } else if (status1 == STATUS1_SLEEP) {
                MESSAGE("Wobbuffet's Chesto Berry woke it up!");
            } else if (status1 == STATUS1_PARALYSIS) {
                MESSAGE("Wobbuffet's Cheri Berry cured its paralysis!");
            } else if (status1 == STATUS1_TOXIC_POISON || status1 == STATUS1_POISON) {
                MESSAGE("Wobbuffet's Pecha Berry cured its poison!");
            } else if (status1 == STATUS1_FROSTBITE) {
                MESSAGE("Wobbuffet's Aspear Berry cured its frostbite!");
            }
            NOT STATUS_ICON(player, status1);
        }
        else if (statId != 0) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            if (statId == STAT_ATK) {
                MESSAGE("The Liechi Berry boosted Wobbuffet's Attack!");
            } else if (statId == STAT_DEF) {
                if (item == ITEM_GANLON_BERRY) {
                    MESSAGE("The Ganlon Berry boosted Wobbuffet's Defense!");
                } else {
                    MESSAGE("The Kee Berry boosted Wobbuffet's Defense!");
                }
            } else if (statId == STAT_SPDEF) {
                if (item == ITEM_APICOT_BERRY) {
                    MESSAGE("The Apicot Berry boosted Wobbuffet's Sp. Def!");
                } else {
                    MESSAGE("The Maranga Berry boosted Wobbuffet's Sp. Def!");
                }
            } else if (statId == STAT_SPEED) {
                MESSAGE("The Salac Berry boosted Wobbuffet's Speed!");
            } else if (statId == STAT_SPATK) {
                MESSAGE("The Petaya Berry boosted Wobbuffet's Sp. Atk!");
            }
        }
    } THEN {
        if (effect == HOLD_EFFECT_RESTORE_HP) {
            EXPECT_EQ(player->hp, player->maxHP);
        } else if (effect == HOLD_EFFECT_RESTORE_PP) {
            EXPECT_EQ(player->pp[1], 20);
        } else if (status1 != STATUS1_NONE) {
            EXPECT_EQ(player->status1, STATUS1_NONE);
        }
        else if (statId != 0) {
            EXPECT_EQ(player->statStages[statId], DEFAULT_STAT_STAGE + 1);
        }
        EXPECT_EQ(opponent->item, ITEM_NONE); // Opponent's Berry was eaten.
    }
}

SINGLE_BATTLE_TEST("Tanga Berry activates before Bug Bite")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_TANGA_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_TANGA_BERRY].holdEffectParam == TYPE_BUG);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_TANGA_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        MESSAGE("Wobbuffet used Bug Bite!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, player);
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet's Tanga Berry lessened the damage it took!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Bug Bite ignores Unnerve")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_TYRANITAR) { Ability(ABILITY_UNNERVE); Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_BUG_BITE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BUG_BITE, player);
        HP_BAR(player);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}
