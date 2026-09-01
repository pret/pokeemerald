#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Cud Chew will activate Kee Berry effect again on the next turn")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_KEE_BERRY].holdEffect == HOLD_EFFECT_KEE_BERRY);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TAUROS_PALDEA_COMBAT) { Ability(ABILITY_CUD_CHEW); Item(ITEM_KEE_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ABILITY_POPUP(opponent, ABILITY_CUD_CHEW);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Cud Chew will activate Oran Berry effect again on the next turn")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffect == HOLD_EFFECT_RESTORE_HP);
        ASSUME(gItemsInfo[ITEM_ORAN_BERRY].holdEffectParam == 10);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        ASSUME(GetMoveFixedHPDamage(MOVE_DRAGON_RAGE) == 40);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TAUROS_PALDEA_COMBAT) { MaxHP(60); HP(60); Ability(ABILITY_CUD_CHEW); Item(ITEM_ORAN_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_RAGE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_RAGE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ABILITY_POPUP(opponent, ABILITY_CUD_CHEW);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
    } THEN {
        EXPECT_EQ(opponent->hp, 40);
    }
}

SINGLE_BATTLE_TEST("Cud Chew will activate Lum Berry effect again on the next turn")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TAUROS_PALDEA_COMBAT) { Ability(ABILITY_CUD_CHEW); Item(ITEM_LUM_BERRY); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, paralysis: FALSE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
        STATUS_ICON(opponent, paralysis: TRUE);
        ABILITY_POPUP(opponent, ABILITY_CUD_CHEW);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponent);
        STATUS_ICON(opponent, paralysis: FALSE);
    }
}
