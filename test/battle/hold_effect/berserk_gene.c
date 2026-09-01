#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_BERSERK_GENE].holdEffect == HOLD_EFFECT_BERSERK_GENE);
}

SINGLE_BATTLE_TEST("Berserk Gene sharply raises attack at the start of a single battle", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BERSERK_GENE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_CONFUSION, FALSE)); }
    } SCENE {
        if (item == ITEM_BERSERK_GENE)
        {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("The Berserk Gene sharply boosted Wobbuffet's Attack!");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
            MESSAGE("Wobbuffet became confused!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Berserk Gene sharply raises attack at the start of a double battle", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BERSERK_GENE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target:opponentLeft, WITH_RNG(RNG_CONFUSION, FALSE)); }
    } SCENE {
        if (item == ITEM_BERSERK_GENE)
        {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("The Berserk Gene sharply boosted Wobbuffet's Attack!");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, playerRight);
            MESSAGE("Wobbuffet became confused!");
        }
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Berserk Gene activates on switch in", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BERSERK_GENE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_SCRATCH, WITH_RNG(RNG_CONFUSION, FALSE)); }
    } SCENE {
        if (item == ITEM_BERSERK_GENE)
        {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("The Berserk Gene sharply boosted Wobbuffet's Attack!");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
            MESSAGE("Wobbuffet became confused!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Berserk Gene does not confuse a Pokemon with Own Tempo but still raises attack sharply in a single battle", s16 damage)
{
    enum Item item;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BERSERK_GENE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_SLOWBRO) { Ability(ABILITY_OWN_TEMPO); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_SCRATCH);
        }
    } SCENE {
        if (item == ITEM_BERSERK_GENE)
        {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("The Berserk Gene sharply boosted Slowbro's Attack!");
            ABILITY_POPUP(player, ABILITY_OWN_TEMPO);
            MESSAGE("Slowbro cannot be confused!");
        }
        HP_BAR(opponent, captureDamage: &results[i].damage);
        NOT MESSAGE("Slowbro became confused!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Berserk Gene does not confuse a Pokemon with Own Tempo but still raises attack sharply in a double battle", s16 damage)
{
    enum Item item;
    bool8 positionLeft = FALSE;

    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_BERSERK_GENE; positionLeft = TRUE; }
    PARAMETRIZE { item = ITEM_BERSERK_GENE; positionLeft = FALSE; }
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        if (positionLeft) {
            PLAYER(SPECIES_SLOWBRO) { Ability(ABILITY_OWN_TEMPO); Item(item); }
            PLAYER(SPECIES_WOBBUFFET);
        } else {
            PLAYER(SPECIES_WOBBUFFET);
            PLAYER(SPECIES_SLOWBRO) { Ability(ABILITY_OWN_TEMPO); Item(item); }
        }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(positionLeft ? playerLeft : playerRight, MOVE_SCRATCH, target: opponentLeft);
        }
    } SCENE {
        if (item == ITEM_BERSERK_GENE)
        {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, (positionLeft) ? playerLeft : playerRight);
            MESSAGE("The Berserk Gene sharply boosted Slowbro's Attack!");
            ABILITY_POPUP(positionLeft ? playerLeft : playerRight, ABILITY_OWN_TEMPO);
            MESSAGE("Slowbro cannot be confused!");
        }
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
        NOT MESSAGE("Slowbro became confused!");
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[2].damage);
        EXPECT_EQ((positionLeft ? playerLeft : playerRight)->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Berserk Gene does not confuse on Misty Terrain but still raises attack sharply")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_TAPU_FINI) { Ability(ABILITY_MISTY_SURGE); Item(ITEM_BERSERK_GENE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Berserk Gene sharply boosted Tapu Fini's Attack!");
        NOT MESSAGE("Tapu Fini became confused!");
    }
}

SINGLE_BATTLE_TEST("Berserk Gene does not confuse when Safeguard is active")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BERSERK_GENE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SAFEGUARD); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("The Berserk Gene sharply boosted Wobbuffet's Attack!");
        MESSAGE("Wobbuffet is protected by Safeguard!");
        NOT MESSAGE("Wobbuffet became confused!");
    }
}

SINGLE_BATTLE_TEST("Berserk Gene causes confusion for more than 5 turns") // how else would be check for infinite?
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BERSERK_GENE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        NOT MESSAGE("Wobbuffet snapped out of confusion!");
    }
}

SINGLE_BATTLE_TEST("Berserk Gene causes confusion timer to not tick down", u32 confusionTimer)
{
    u32 turns;
    PARAMETRIZE { turns = 1; }
    PARAMETRIZE { turns = 2; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BERSERK_GENE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        u32 count;
        for (count = 0; count < turns; count++) {
            TURN {}
        }
    } THEN {
        results[i].confusionTimer = player->volatiles.confusionTimer;
    } FINALLY {
        EXPECT_EQ(results[0].confusionTimer, results[1].confusionTimer);
    }
}

SINGLE_BATTLE_TEST("Berserk Gene does not cause an infinite loop")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_BESTOW) == EFFECT_BESTOW);
        PLAYER(SPECIES_TOXEL) { Item(ITEM_BERSERK_GENE); Ability(ABILITY_KLUTZ); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BESTOW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The Berserk Gene sharply boosted the opposing Wobbuffet's Attack!");
    }
}

SINGLE_BATTLE_TEST("Berserker Gene confusion can be healed with bag items")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_FULL_HEAL; }
    PARAMETRIZE { item = ITEM_HEAL_POWDER; }
    PARAMETRIZE { item = ITEM_PEWTER_CRUNCHIES; }
    PARAMETRIZE { item = ITEM_LAVA_COOKIE; }
    PARAMETRIZE { item = ITEM_RAGE_CANDY_BAR; }
    PARAMETRIZE { item = ITEM_OLD_GATEAU; }
    PARAMETRIZE { item = ITEM_CASTELIACONE; }
    PARAMETRIZE { item = ITEM_LUMIOSE_GALETTE; }
    PARAMETRIZE { item = ITEM_SHALOUR_SABLE; }
    PARAMETRIZE { item = ITEM_BIG_MALASADA; }
    PARAMETRIZE { item = ITEM_JUBILIFE_MUFFIN; }
    GIVEN {
        ASSUME(gItemsInfo[item].battleUsage == EFFECT_ITEM_CURE_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BERSERK_GENE); }
        OPPONENT(SPECIES_GENGAR);
    } WHEN {
        TURN { USE_ITEM(player, item, partyIndex: 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        MESSAGE("Wobbuffet snapped out of its confusion!");
    } THEN {
        EXPECT(player->volatiles.confusionTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Berserker Gene confusion can be healed with used held items")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_PERSIM_BERRY; }
    PARAMETRIZE { item = ITEM_LUM_BERRY; }

    GIVEN {
        ASSUME(gItemsInfo[ITEM_PERSIM_BERRY].holdEffect == HOLD_EFFECT_CURE_CONFUSION);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_BERSERK_GENE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_COVET, WITH_RNG(RNG_CONFUSION, FALSE)); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, player);
    } THEN {
        EXPECT(player->volatiles.confusionTimer == 0);
    }
}
