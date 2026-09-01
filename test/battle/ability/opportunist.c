#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
}

SINGLE_BATTLE_TEST("Opportunist only copies foe's positive stat changes in a turn", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_FRISK; }
    PARAMETRIZE { ability = ABILITY_OPPORTUNIST; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_ESPATHRA) { Speed(5); Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_SMASH); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        if (ability == ABILITY_FRISK) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SMASH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player, captureDamage: &results[i].damage);
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SHELL_SMASH, player);
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
            HP_BAR(player, captureDamage: &results[i].damage);
        }
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.0), results[1].damage);
        // stat boosts should be the same
        EXPECT_EQ(player->statStages[STAT_ATK], opponent->statStages[STAT_ATK]);
        EXPECT_EQ(player->statStages[STAT_SPATK], opponent->statStages[STAT_SPATK]);
        EXPECT_EQ(player->statStages[STAT_SPEED], opponent->statStages[STAT_SPEED]);
        // opportunist should not copy stat drops from shell smash
        EXPECT_LT(player->statStages[STAT_DEF], opponent->statStages[STAT_DEF]);
        EXPECT_LT(player->statStages[STAT_SPDEF], opponent->statStages[STAT_SPDEF]);
    }
}


DOUBLE_BATTLE_TEST("Opportunist raises Attack only once when partner has Intimidate against Contrary foe in a double battle", s16 damageLeft, s16 damageRight)
{
    enum Ability abilityLeft, abilityRight;

    PARAMETRIZE { abilityLeft = ABILITY_CONTRARY; abilityRight = ABILITY_CONTRARY; }
    PARAMETRIZE { abilityLeft = ABILITY_TANGLED_FEET; abilityRight = ABILITY_TANGLED_FEET; }
    PARAMETRIZE { abilityLeft = ABILITY_CONTRARY; abilityRight = ABILITY_TANGLED_FEET; }
    PARAMETRIZE { abilityLeft = ABILITY_TANGLED_FEET; abilityRight = ABILITY_CONTRARY; }

    GIVEN {
        PLAYER(SPECIES_MIGHTYENA) { Ability(ABILITY_INTIMIDATE); }
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_SPINDA) { Ability(abilityLeft); }
        OPPONENT(SPECIES_SPINDA) { Ability(abilityRight); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        if (abilityLeft == ABILITY_CONTRARY) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Spinda's Attack rose!");
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("The opposing Spinda's Attack fell!");
        }
        if (abilityRight == ABILITY_CONTRARY) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Spinda's Attack rose!");
        } else {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
            MESSAGE("The opposing Spinda's Attack fell!");
        }

        if ((abilityLeft == ABILITY_CONTRARY && abilityRight != ABILITY_CONTRARY)
                || (abilityLeft != ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY)) {
            ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Espathra's Attack rose!");
        } else if (abilityLeft == ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY) {
            ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Espathra's Attack rose sharply!");
        }

        HP_BAR(playerLeft, captureDamage: &results[i].damageLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damageRight);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK],  DEFAULT_STAT_STAGE + (abilityLeft  == ABILITY_CONTRARY ? 1 : - 1));
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + (abilityRight == ABILITY_CONTRARY ? 1 : - 1));
        if ((abilityLeft == ABILITY_CONTRARY && abilityRight != ABILITY_CONTRARY)
                || (abilityLeft != ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY)) {
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        } else if (abilityLeft == ABILITY_CONTRARY && abilityRight == ABILITY_CONTRARY) {
            EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        }
    }
    FINALLY {
        EXPECT_MUL_EQ(results[1].damageLeft, Q_4_12(2.25), results[0].damageLeft);
        EXPECT_MUL_EQ(results[1].damageRight, Q_4_12(2.25), results[0].damageRight);
    }
}

SINGLE_BATTLE_TEST("Opportunist does not accumulate opposing mon's stat changes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 4);
    }
}

SINGLE_BATTLE_TEST("Opportunist copies each stat increase individually from ability and move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTREPID_SWORD);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 3);
    }
}

SINGLE_BATTLE_TEST("Opportunist doesn't copy foe stat increases gained via Opportunist")
{
    GIVEN {
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, player);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
        NOT ABILITY_POPUP(player, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], player->statStages[STAT_ATK]);
    }
}

SINGLE_BATTLE_TEST("Opportunist copies foe stat increase gained via Swagger and Flatter")
{
    GIVEN {
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_FLATTER); }
        TURN { MOVE(opponent, MOVE_SWAGGER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLATTER, opponent);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWAGGER, opponent);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Opportunist doesn't copy ally stat increases")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, playerLeft);
        NOT ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_SPATK], DEFAULT_STAT_STAGE );
    }
}

DOUBLE_BATTLE_TEST("Opportunist copies the stat increase of each opposing mon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SWORDS_DANCE); MOVE(opponentLeft, MOVE_SWORDS_DANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWORDS_DANCE, opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 4);
    }
}


DOUBLE_BATTLE_TEST("Opportunist copies the stat of each Pokémon that were raised at the same time")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ABILITY_POPUP(opponentRight, ABILITY_INTREPID_SWORD);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
        MESSAGE("Espathra's Attack rose sharply!");
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

SINGLE_BATTLE_TEST("Opportunist copies the increase not the stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHARM); MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); MOVE(opponent, MOVE_CHARM); }
        TURN { MOVE(player, MOVE_CHARM); MOVE(opponent, MOVE_GROWL); }
        TURN { MOVE(player, MOVE_BELLY_DRUM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, opponent);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHARM, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);

        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 5); // + 11
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 6); // + 11
    }
}

SINGLE_BATTLE_TEST("Opportunist copies the stat increase from the incoming mon")
{
    GIVEN {
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(opponent, ABILITY_INTREPID_SWORD);
        ABILITY_POPUP(player, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Opportunist and Mirror Herb stack stat increases")
{
    GIVEN {
        PLAYER(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); Item(ITEM_MIRROR_HERB); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_INTREPID_SWORD);
        ABILITY_POPUP(opponent, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPATK], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Opportunist and Mirror Herb resolve correctly")
{
    GIVEN {
        PLAYER(SPECIES_ZACIAN) { Ability(ABILITY_INTREPID_SWORD); }
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_MEOWSCARADA) { Item(ITEM_MIRROR_HERB); }
        OPPONENT(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); Item(ITEM_MIRROR_HERB); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_INTREPID_SWORD);
        ABILITY_POPUP(opponentRight, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
    } THEN {
        EXPECT_EQ(playerLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(opponentRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Opportunist activates after a Mega Evolution")
{
    GIVEN {
        PLAYER(SPECIES_MANECTRIC) { Item(ITEM_MANECTITE); }
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_MANKEY) { Ability(ABILITY_DEFIANT); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_INTIMIDATE);
        ABILITY_POPUP(opponentLeft, ABILITY_DEFIANT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(opponentLeft->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Opportunist copies the stats boosted by Speed Boost")
{
    GIVEN {
        PLAYER(SPECIES_ESPATHRA) { Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_TORCHIC) { Ability(ABILITY_SPEED_BOOST); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SPEED_BOOST);
        ABILITY_POPUP(player, ABILITY_OPPORTUNIST);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

DOUBLE_BATTLE_TEST("Opportunist activates before Mirror Herb during the end turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_MIRROR_HERB); }
        PLAYER(SPECIES_ESPATHRA) { Speed(2); Ability(ABILITY_OPPORTUNIST); }
        OPPONENT(SPECIES_TORCHIC) { Speed(3); Ability(ABILITY_SPEED_BOOST); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_SPEED_BOOST);
        ABILITY_POPUP(playerRight, ABILITY_OPPORTUNIST);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
    } THEN {
        EXPECT_EQ(opponentLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        EXPECT_EQ(playerRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

TO_DO_BATTLE_TEST("Opportunist copies stat changes from the opponent's X Attack and other stat-boosting items.")
