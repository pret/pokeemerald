#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_CHLOROBLAST) == EFFECT_CHLOROBLAST);
}

SINGLE_BATTLE_TEST("Chloroblast makes the user lose 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHLOROBLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
        HP_BAR(player, damage: 200);
        NOT MESSAGE("Wobbuffet fainted!"); // Wobb had more than 1/2 of its HP, so it can't faint.
    }
}

SINGLE_BATTLE_TEST("Chloroblast causes the user to faint when below 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200); MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHLOROBLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Chloroblast causes the user & the target to faint when below 1/2 of its Max HP")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(200) ; MaxHP(400); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHLOROBLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
        HP_BAR(opponent, hp: 0);
        MESSAGE("The opposing Wobbuffet fainted!");
        HP_BAR(player, hp: 0);
        MESSAGE("Wobbuffet fainted!");
    }
}

SINGLE_BATTLE_TEST("Chloroblast hp loss is prevented by Magic Guard")
{
    GIVEN {
        PLAYER(SPECIES_CLEFAIRY) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHLOROBLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Chloroblast does not cause recoil damage if the user has Rock Head")
{
    GIVEN {
        PLAYER(SPECIES_AERODACTYL) { Ability(ABILITY_ROCK_HEAD); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHLOROBLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
        HP_BAR(opponent);
        NOT HP_BAR(player);
    }
}

SINGLE_BATTLE_TEST("Chloroblast does not cause the user to lose HP even if the opposing mon protected")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_CHLOROBLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Chloroblast does not cause the user to lose HP even if it is absorbed by Sap Sipper")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_CHLOROBLAST) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOGOAT) { Ability(ABILITY_SAP_SIPPER); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHLOROBLAST); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SAP_SIPPER);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Chloroblast does not cause the user to lose HP if there is no target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MEMENTO); MOVE(player, MOVE_CHLOROBLAST); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MEMENTO, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, player);
            HP_BAR(player);
        }
        MESSAGE("Wobbuffet used Chloroblast!");
        MESSAGE("But it failed!");
        MESSAGE("2 sent out Wobbuffet!");
    }
}

SINGLE_BATTLE_TEST("Chloroblast is not affected by Reckless", s16 damage)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CHLOROBLAST; }
    if (B_UPDATED_MOVE_DATA >= GEN_9) {
        PARAMETRIZE { move = MOVE_FRENZY_PLANT; } // 150 power
    } else {
        PARAMETRIZE { move = MOVE_SEED_FLARE; } // 120 power
    }

    GIVEN {
        ASSUME(GetMovePower(MOVE_CHLOROBLAST) == GetMovePower(move));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Chloroblast has recoil if the target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_CHLOROBLAST); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHLOROBLAST, opponent);
        SUB_HIT(player);
        HP_BAR(opponent, damage: 200);
    }
}
