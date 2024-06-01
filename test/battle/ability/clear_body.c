#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Clear Body prevents intimidate")
{
    s16 turnOneHit;
    s16 turnTwoHit;

    GIVEN {
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_SHED_SKIN); };
        PLAYER(SPECIES_EKANS) { Ability(ABILITY_INTIMIDATE); };
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); };
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_TACKLE); }

    } SCENE {
        HP_BAR(player, captureDamage: &turnOneHit);
        ABILITY_POPUP(player, ABILITY_INTIMIDATE);
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent); }
        ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
        MESSAGE("Foe Beldum's Clear Body prevents stat loss!");
        HP_BAR(player, captureDamage: &turnTwoHit);
    } THEN {
        EXPECT_EQ(turnOneHit, turnTwoHit);
    }
}

SINGLE_BATTLE_TEST("Clear Body prevents stat stage reduction from moves")
{
    u16 move;
    PARAMETRIZE{ move = MOVE_GROWL; }
    PARAMETRIZE{ move = MOVE_LEER; }
    PARAMETRIZE{ move = MOVE_CONFIDE; }
    PARAMETRIZE{ move = MOVE_FAKE_TEARS; }
    PARAMETRIZE{ move = MOVE_SCARY_FACE; }
    PARAMETRIZE{ move = MOVE_SWEET_SCENT; }
    PARAMETRIZE{ move = MOVE_SAND_ATTACK; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_GROWL].effect == EFFECT_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_LEER].effect == EFFECT_DEFENSE_DOWN);
        ASSUME(gMovesInfo[MOVE_CONFIDE].effect == EFFECT_SPECIAL_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_FAKE_TEARS].effect == EFFECT_SPECIAL_DEFENSE_DOWN);
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_SWEET_SCENT].effect == EFFECT_EVASION_DOWN);
        ASSUME(gMovesInfo[MOVE_SAND_ATTACK].effect == EFFECT_ACCURACY_DOWN);
        PLAYER(SPECIES_WOBBUFFET) { Moves(move); }
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN{ MOVE(player, move); }
    } SCENE {
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent); }
        ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
        MESSAGE("Foe Beldum's Clear Body prevents stat loss!");
    }
}

SINGLE_BATTLE_TEST("Clear Body prevents Sticky Web")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_STICKY_WEB].effect == EFFECT_STICKY_WEB);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN{ MOVE(player, MOVE_STICKY_WEB); MOVE(opponent, MOVE_CELEBRATE); }
        TURN{ SWITCH(opponent, 1); }
    } SCENE {
        NONE_OF { ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent); }
        ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
        MESSAGE("Foe Beldum's Clear Body prevents stat loss!");
    }
}

SINGLE_BATTLE_TEST("Clear Body doesn't prevent stat stage reduction from moves used by the user")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SUPERPOWER].additionalEffects->moveEffect == MOVE_EFFECT_ATK_DEF_DOWN);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_BELDUM) { Moves(MOVE_SUPERPOWER);  Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN{ MOVE(opponent, MOVE_SUPERPOWER); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY); MESSAGE("Foe Beldum's Clear Body prevents stat loss!"); }
    }
}

SINGLE_BATTLE_TEST("Clear Body is ignored by Mold Breaker")
{
    u16 move;
    PARAMETRIZE{ move = MOVE_GROWL; }
    PARAMETRIZE{ move = MOVE_LEER; }
    PARAMETRIZE{ move = MOVE_CONFIDE; }
    PARAMETRIZE{ move = MOVE_FAKE_TEARS; }
    PARAMETRIZE{ move = MOVE_SCARY_FACE; }
    PARAMETRIZE{ move = MOVE_SWEET_SCENT; }
    PARAMETRIZE{ move = MOVE_SAND_ATTACK; }

    GIVEN {
        ASSUME(gMovesInfo[MOVE_GROWL].effect == EFFECT_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_LEER].effect == EFFECT_DEFENSE_DOWN);
        ASSUME(gMovesInfo[MOVE_CONFIDE].effect == EFFECT_SPECIAL_ATTACK_DOWN);
        ASSUME(gMovesInfo[MOVE_FAKE_TEARS].effect == EFFECT_SPECIAL_DEFENSE_DOWN);
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_SWEET_SCENT].effect == EFFECT_EVASION_DOWN);
        ASSUME(gMovesInfo[MOVE_SAND_ATTACK].effect == EFFECT_ACCURACY_DOWN);
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); Moves(move); }
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN{ MOVE(player, move); }
    } SCENE {
        NONE_OF { ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY); MESSAGE("Foe Beldum's Clear Body prevents stat loss!"); }
    }
}

SINGLE_BATTLE_TEST("Clear Body doesn't prevent Speed reduction from Iron Ball")
{
    u16 heldItem;
    PARAMETRIZE{ heldItem = ITEM_NONE; }
    PARAMETRIZE{ heldItem = ITEM_IRON_BALL; }
    GIVEN {
        ASSUME(gItemsInfo[ITEM_IRON_BALL].holdEffect == HOLD_EFFECT_IRON_BALL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_BELDUM) { Speed(6); Ability(ABILITY_CLEAR_BODY); Item(heldItem); }
    } WHEN {
        TURN{ MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (heldItem == ITEM_IRON_BALL)
        {
            MESSAGE("Wobbuffet used Celebrate!");
            MESSAGE("Foe Beldum used Celebrate!");
        }
        else
        {
            MESSAGE("Foe Beldum used Celebrate!");
            MESSAGE("Wobbuffet used Celebrate!");
        }
    }
}

SINGLE_BATTLE_TEST("Clear Body doesn't prevent Speed reduction from paralysis")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_THUNDER_WAVE); }
        OPPONENT(SPECIES_BELDUM) { Speed(6); Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN{ MOVE(player, MOVE_THUNDER_WAVE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN{ MOVE(player, MOVE_THUNDER_WAVE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
            MESSAGE("Foe Beldum used Celebrate!");
            MESSAGE("Wobbuffet used Thunder Wave!");
            MESSAGE("Wobbuffet used Thunder Wave!");
            ONE_OF {
                MESSAGE("Foe Beldum used Celebrate!");
                MESSAGE("Foe Beldum is paralyzed! It can't move!");
            }
    }
}

SINGLE_BATTLE_TEST("Clear Body doesn't prevent Attack reduction from burn", s16 damage)
{
    bool32 burned;
    PARAMETRIZE{ burned = FALSE; }
    PARAMETRIZE{ burned = TRUE; }
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TACKLE].category == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET)
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); if (burned) Status1(STATUS1_BURN); }
    } WHEN {
        TURN{ MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Clear Body doesn't prevent receiving negative stat changes from Baton Pass")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_BATON_PASS].effect == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_SCARY_FACE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_BATON_PASS); }
        OPPONENT(SPECIES_BELDUM) { Speed(6); Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN{ MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN{ MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
            MESSAGE("Wobbuffet used Scary Face!");
            MESSAGE("Foe Beldum used Celebrate!");
    }
}

SINGLE_BATTLE_TEST("Clear Body doesn't prevent Topsy-Turvy")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_TOPSY_TURVY].effect == EFFECT_TOPSY_TURVY);
        ASSUME(gMovesInfo[MOVE_SCARY_FACE].effect == EFFECT_SPEED_DOWN_2);
        ASSUME(gMovesInfo[MOVE_BATON_PASS].effect == EFFECT_BATON_PASS);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_SCARY_FACE, MOVE_TOPSY_TURVY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(3); Moves(MOVE_BATON_PASS); }
        OPPONENT(SPECIES_BELDUM) { Speed(6); Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN{ MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
        TURN{ MOVE(player, MOVE_TOPSY_TURVY); MOVE(opponent, MOVE_CELEBRATE); }
        TURN{ MOVE(player, MOVE_SCARY_FACE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
            MESSAGE("Wobbuffet used Topsy-Turvy!");
            MESSAGE("Foe Beldum used Celebrate!");
            MESSAGE("Foe Beldum used Celebrate!");
            MESSAGE("Wobbuffet used Scary Face!");
    }
}

SINGLE_BATTLE_TEST("Clear Body doesn't prevent Spectral Thief from resetting positive stat changes")
{
    GIVEN {
        ASSUME(gMovesInfo[MOVE_SPECTRAL_THIEF].additionalEffects->moveEffect == MOVE_EFFECT_SPECTRAL_THIEF);
        ASSUME(gMovesInfo[MOVE_AGILITY].effect == EFFECT_SPEED_UP_2);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); Moves(MOVE_SPECTRAL_THIEF, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_BELDUM) { Speed(5); Ability(ABILITY_CLEAR_BODY); Moves(MOVE_AGILITY, MOVE_CELEBRATE); }
    } WHEN {
        TURN{ MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_AGILITY); }
        TURN{ MOVE(player, MOVE_SPECTRAL_THIEF); MOVE(opponent, MOVE_CELEBRATE); }
        TURN{ MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
            MESSAGE("Foe Beldum used Agility!");
            MESSAGE("Wobbuffet used Celebrate!");
            MESSAGE("Foe Beldum used Celebrate!");
            MESSAGE("Wobbuffet used SpectrlThief!");
            MESSAGE("Wobbuffet used Celebrate!");
            MESSAGE("Foe Beldum used Celebrate!");
    }
}
