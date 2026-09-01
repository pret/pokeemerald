#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Leaf Guard prevents non-volatile status conditions in sun")
{
    enum Move move;
    u16 status;
    PARAMETRIZE { move = MOVE_WILL_O_WISP; status = STATUS1_BURN; }
    PARAMETRIZE { move = MOVE_HYPNOSIS; status = STATUS1_SLEEP; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; status = STATUS1_PARALYSIS; }
    PARAMETRIZE { move = MOVE_TOXIC; status = STATUS1_TOXIC_POISON; }
    // PARAMETRIZE { move = MOVE_POWDER_SNOW; status = STATUS1_FREEZE; } // Pointless since you can't freeze in sunlight anyway
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(GetMoveEffect(MOVE_HYPNOSIS) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_HYPNOSIS) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, move); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        ABILITY_POPUP(player, ABILITY_LEAF_GUARD);
        MESSAGE("It doesn't affect Leafeon…");
        NOT STATUS_ICON(player, status);
    }
}

SINGLE_BATTLE_TEST("Leaf Guard doesn't prevent non-volatile status conditions if Cloud Nine/Air Lock is on the field")
{
    enum Move move;
    enum Species species;
    enum Ability ability;
    u16 status;
    PARAMETRIZE { move = MOVE_WILL_O_WISP;  status = STATUS1_BURN;         species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { move = MOVE_HYPNOSIS;     status = STATUS1_SLEEP;        species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; status = STATUS1_PARALYSIS;    species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { move = MOVE_TOXIC;        status = STATUS1_TOXIC_POISON; species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { move = MOVE_WILL_O_WISP;  status = STATUS1_BURN;         species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    PARAMETRIZE { move = MOVE_HYPNOSIS;     status = STATUS1_SLEEP;        species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    PARAMETRIZE { move = MOVE_THUNDER_WAVE; status = STATUS1_PARALYSIS;    species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    PARAMETRIZE { move = MOVE_TOXIC;        status = STATUS1_TOXIC_POISON; species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    // PARAMETRIZE { move = MOVE_POWDER_SNOW; status = STATUS1_FREEZE; } // Pointless since you can't freeze in sunlight anyway
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WILL_O_WISP) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_WILL_O_WISP) == MOVE_EFFECT_BURN);
        ASSUME(GetMoveEffect(MOVE_HYPNOSIS) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_HYPNOSIS) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
        ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        NONE_OF {
            ABILITY_POPUP(player, ABILITY_LEAF_GUARD);
            MESSAGE("It doesn't affect Leafeon…");
        }
        STATUS_ICON(player, status);
    }
}

SINGLE_BATTLE_TEST("Leaf Guard prevents status conditions from Flame Orb and Toxic Orb")
{
    enum Item item;
    PARAMETRIZE { item = ITEM_FLAME_ORB; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        if (item == ITEM_FLAME_ORB) {
            NONE_OF { MESSAGE("Leafeon was burned!"); STATUS_ICON(player, burn: TRUE); }
        }
        else {
            NONE_OF { MESSAGE("Leafeon was badly poisoned!"); STATUS_ICON(player, badPoison: TRUE); }
        }
    }
}

SINGLE_BATTLE_TEST("Leaf Guard doesn't prevent status conditions from Flame Orb and Toxic Orb if Cloud Nine/Air Lock is on the field")
{
    enum Item item;
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { item = ITEM_FLAME_ORB; species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { item = ITEM_FLAME_ORB; species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    PARAMETRIZE { item = ITEM_TOXIC_ORB; species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FLAME_ORB].holdEffect == HOLD_EFFECT_FLAME_ORB);
        ASSUME(gItemsInfo[ITEM_TOXIC_ORB].holdEffect == HOLD_EFFECT_TOXIC_ORB);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); Item(item); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUNNY_DAY); }
    } SCENE {
        if (item == ITEM_FLAME_ORB) {
            MESSAGE("Leafeon was burned!");
            STATUS_ICON(player, burn: TRUE);
        }
        else {
            MESSAGE("Leafeon was badly poisoned!");
            STATUS_ICON(player, badPoison: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Leaf Guard prevents Rest during sun (Gen 5+)")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_4; }
    PARAMETRIZE { gen = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_LEAF_GUARD_PREVENTS_REST, gen);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); HP(100); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_REST); }
    } SCENE {
        if (gen >= GEN_5) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
                STATUS_ICON(player, sleep: TRUE);
                HP_BAR(player);
            }
        }
        else {
            STATUS_ICON(player, sleep: TRUE);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Leaf Guard doesn't prevent Rest if Cloud Nine/Air Lock is on the field")
{
    enum Species species;
    enum Ability ability;
    PARAMETRIZE { species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }
    GIVEN {
        WITH_CONFIG(B_LEAF_GUARD_PREVENTS_REST, GEN_5);
        ASSUME(GetMoveEffect(MOVE_REST) == EFFECT_REST);
        PLAYER(SPECIES_LEAFEON) { Ability(ABILITY_LEAF_GUARD); HP(100); MaxHP(200); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); MOVE(player, MOVE_REST); }
    } SCENE {
        STATUS_ICON(player, sleep: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REST, player);
        HP_BAR(player);
    }
}
