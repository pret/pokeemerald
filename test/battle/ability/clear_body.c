#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;
    u32 species, ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); };
        OPPONENT(species) { Ability(ability); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TACKLE); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo's Full Metal Body prevents stat loss!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal's White Smoke prevents stat loss!");
        else
            MESSAGE("Foe Metang's Clear Body prevents stat loss!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent stat stage reduction from moves")
{
    u16 move = MOVE_NONE;
    u32 j, species = SPECIES_NONE, ability = ABILITY_NONE;
    static const u16 statReductionMoves[] = {
        MOVE_GROWL,
        MOVE_LEER,
        MOVE_CONFIDE,
        MOVE_FAKE_TEARS,
        MOVE_SCARY_FACE,
        MOVE_SWEET_SCENT,
        MOVE_SAND_ATTACK,
    };
    for (j = 0; j < ARRAY_COUNT(statReductionMoves); j++)
        {
            PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; move = statReductionMoves[j]; }
            PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; move = statReductionMoves[j]; }
            PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; move = statReductionMoves[j]; }
        }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_GROWL].effect == EFFECT_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_LEER].effect == EFFECT_DEFENSE_DOWN);
        ASSUME(gMovesInfo[MOVE_CONFIDE].effect == EFFECT_SPECIAL_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_FAKE_TEARS].effect == EFFECT_SPECIAL_DEFENSE_DOWN_2);
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_SWEET_SCENT].effect == (B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN));
        ASSUME(gMovesInfo[MOVE_SAND_ATTACK].effect == EFFECT_ACCURACY_DOWN);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo's Full Metal Body prevents stat loss!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal's White Smoke prevents stat loss!");
        else
            MESSAGE("Foe Metang's Clear Body prevents stat loss!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke prevent Sticky Web effect on switchin")
{
    u32 species, ability;
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_STICKY_WEB].effect == EFFECT_STICKY_WEB);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_STICKY_WEB); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo's Full Metal Body prevents stat loss!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal's White Smoke prevents stat loss!");
        else
            MESSAGE("Foe Metang's Clear Body prevents stat loss!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent stat stage reduction from moves used by the user")
{
    u32 species, ability;
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_SUPERPOWER, MOVE_EFFECT_ATK_DEF_DOWN) == TRUE);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUPERPOWER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUPERPOWER, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ability); 
            MESSAGE("Foe Solgaleo's Full Metal Body prevents stat loss!");
            MESSAGE("Foe Torkoal's White Smoke prevents stat loss!");
            MESSAGE("Foe Metang's Clear Body prevents stat loss!");
        }
    }
}

SINGLE_BATTLE_TEST("Mold Breaker, Teravolt, and Turboblaze ignore Clear Body and White Smoke, but not Full Metal Body")
{
    u32 j, k, species = SPECIES_NONE, ability = ABILITY_NONE;
    u16 breakerAbility = ABILITY_NONE;
    u16 move = ABILITY_NONE;
    static const u16 breakerAbilities[] = {
        ABILITY_MOLD_BREAKER,
        ABILITY_TERAVOLT,
        ABILITY_TURBOBLAZE,
    };
    static const u16 statReductionMoves[] = {
        MOVE_GROWL,
        MOVE_LEER,
        MOVE_CONFIDE,
        MOVE_FAKE_TEARS,
        MOVE_SCARY_FACE,
        MOVE_SWEET_SCENT,
        MOVE_SAND_ATTACK,
    };

    for (j = 0; j < ARRAY_COUNT(statReductionMoves); j++)
    {
        for (k = 0; k < ARRAY_COUNT(breakerAbilities); k++)
        {
            PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
            PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
            PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; move = statReductionMoves[j]; breakerAbility = breakerAbilities[k]; }
        }
    }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_GROWL].effect == EFFECT_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_LEER].effect == EFFECT_DEFENSE_DOWN);
        ASSUME(gMovesInfo[MOVE_CONFIDE].effect == EFFECT_SPECIAL_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_FAKE_TEARS].effect == EFFECT_SPECIAL_DEFENSE_DOWN_2);
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_SWEET_SCENT].effect == (B_UPDATED_MOVE_DATA >= GEN_6 ? EFFECT_EVASION_DOWN_2 : EFFECT_EVASION_DOWN));
        ASSUME(gMovesInfo[MOVE_SAND_ATTACK].effect == EFFECT_ACCURACY_DOWN);
        PLAYER(SPECIES_WOBBUFFET) { Ability(breakerAbility); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (ability == ABILITY_FULL_METAL_BODY){ // Full Metal Body can't be ignored by breaker abilities
            NOT ANIMATION(ANIM_TYPE_MOVE, move, player);
            ABILITY_POPUP(opponent, ability);
            MESSAGE("Foe Solgaleo's Full Metal Body prevents stat loss!");
        }
        else{
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            NONE_OF {
                ABILITY_POPUP(opponent, ability); 
                MESSAGE("Foe Solgaleo's Full Metal Body prevents stat loss!");
                MESSAGE("Foe Torkoal's White Smoke prevents stat loss!");
                MESSAGE("Foe Metang's Clear Body prevents stat loss!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Speed reduction from Iron Ball")
{
    u32 j, species = SPECIES_NONE, ability = ABILITY_NONE;
    u16 heldItem = ITEM_NONE;
    static const u16 heldItems[] = {
        ITEM_NONE,
        ITEM_IRON_BALL,
    };
    for (j = 0; j < ARRAY_COUNT(heldItems); j++)
    {
        PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; heldItem = heldItems[j]; }
        PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; heldItem = heldItems[j]; }
        PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; heldItem = heldItems[j]; }
    }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_IRON_BALL].holdEffect == HOLD_EFFECT_IRON_BALL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(species) { Speed(6); Ability(ability); Item(heldItem); }
    } WHEN {
        TURN { }
    } SCENE {
        NOT ABILITY_POPUP(opponent, ability);
        if (heldItem == ITEM_IRON_BALL) {
            MESSAGE("Wobbuffet used Celebrate!");
            if (ability == ABILITY_FULL_METAL_BODY)
                MESSAGE("Foe Solgaleo used Celebrate!");
            else if (ability == ABILITY_WHITE_SMOKE)
                MESSAGE("Foe Torkoal used Celebrate!");
            else
                MESSAGE("Foe Metang used Celebrate!");
        } else {
            if (ability == ABILITY_FULL_METAL_BODY)
                MESSAGE("Foe Solgaleo used Celebrate!");
            else if (ability == ABILITY_WHITE_SMOKE)
                MESSAGE("Foe Torkoal used Celebrate!");
            else
                MESSAGE("Foe Metang used Celebrate!");
            MESSAGE("Wobbuffet used Celebrate!");
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Speed reduction from paralysis")
{
    u32 species, ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(species) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal used Celebrate!");
        else
            MESSAGE("Foe Metang used Celebrate!");
        MESSAGE("Wobbuffet used Thunder Wave!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THUNDER_WAVE, player);
        NOT ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet used Thunder Wave!");
        ONE_OF {
            MESSAGE("Foe Metang used Celebrate!");
            MESSAGE("Foe Metang is paralyzed! It can't move!");
            MESSAGE("Foe Solgaleo used Celebrate!");
            MESSAGE("Foe Solgaleo is paralyzed! It can't move!");
            MESSAGE("Foe Torkoal used Celebrate!");
            MESSAGE("Foe Torkoal is paralyzed! It can't move!");
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Attack reduction from burn", s16 damage)
{
    bool32 burned = FALSE;
    u32 species, ability;
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; burned = FALSE; }
    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; burned = TRUE; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; burned = FALSE; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; burned = TRUE; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; burned = FALSE; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; burned = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(species) { Ability(ability); if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        NOT ABILITY_POPUP(opponent, ability);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent receiving negative stat changes from Baton Pass")
{
    u32 species, ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_BATON_PASS].effect == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(species) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        MESSAGE("Wobbuffet used Scary Face!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ABILITY_POPUP(opponent, ability);
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal used Celebrate!");
        else
            MESSAGE("Foe Metang used Celebrate!");
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Topsy-Turvy")
{
    u32 species, ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOPSY_TURVY].effect == EFFECT_TOPSY_TURVY);
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_BATON_PASS].effect == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(species) { Speed(6); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_TOPSY_TURVY); }
        TURN { MOVE(player, MOVE_SCARY_FACE); }
    } SCENE {
        MESSAGE("Wobbuffet used Topsy-Turvy!");
        NOT ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOPSY_TURVY, player);
        if (ability == ABILITY_FULL_METAL_BODY) {
            MESSAGE("Foe Solgaleo used Celebrate!");
            MESSAGE("Foe Solgaleo used Celebrate!");
        }
        else if (ability == ABILITY_WHITE_SMOKE) {
            MESSAGE("Foe Torkoal used Celebrate!");
            MESSAGE("Foe Torkoal used Celebrate!");
        }
        else {
            MESSAGE("Foe Metang used Celebrate!");
            MESSAGE("Foe Metang used Celebrate!");
        }
        MESSAGE("Wobbuffet used Scary Face!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
        ABILITY_POPUP(opponent, ability);
    }
}

SINGLE_BATTLE_TEST("Clear Body, Full Metal Body, and White Smoke don't prevent Spectral Thief from resetting positive stat changes")
{
    u32 species, ability;

    PARAMETRIZE{ species = SPECIES_METANG; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE{ species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }
    PARAMETRIZE{ species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SPECTRAL_THIEF, MOVE_EFFECT_SPECTRAL_THIEF) == TRUE);
        ASSUME(gMovesInfo[MOVE_AGILITY].effect == EFFECT_SPEED_UP_2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(species) { Speed(5); Ability(ability); }
    } WHEN {
        TURN{ MOVE(opponent, MOVE_AGILITY); }
        TURN{ MOVE(player, MOVE_SPECTRAL_THIEF); }
        TURN{ }
    } SCENE {
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo used Agility!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal used Agility!");
        else
            MESSAGE("Foe Metang used Agility!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AGILITY, opponent);
        MESSAGE("Wobbuffet used Celebrate!");
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal used Celebrate!");
        else
            MESSAGE("Foe Metang used Celebrate!");
        MESSAGE("Wobbuffet used SpectrlThief!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPECTRAL_THIEF, player);
        NOT ABILITY_POPUP(opponent, ability);
        MESSAGE("Wobbuffet used Celebrate!");
        if (ability == ABILITY_FULL_METAL_BODY)
            MESSAGE("Foe Solgaleo used Celebrate!");
        else if (ability == ABILITY_WHITE_SMOKE)
            MESSAGE("Foe Torkoal used Celebrate!");
        else
            MESSAGE("Foe Metang used Celebrate!");
    }
}
