#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetSpeciesType(SPECIES_UMBREON, 0) == TYPE_DARK);
    ASSUME(GetMoveCategory(MOVE_CONFUSE_RAY) == DAMAGE_CATEGORY_STATUS);
}

SINGLE_BATTLE_TEST("Prankster-affected moves don't affect Dark-type Pokémon (Gen7+)")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_6; }
    PARAMETRIZE { gen = GEN_7; }
    GIVEN {
        WITH_CONFIG(B_PRANKSTER_DARK_TYPES, gen);
        PLAYER(SPECIES_UMBREON);
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
    } SCENE {
        if (gen == GEN_6) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
            MESSAGE("It doesn't affect Umbreon…");
        }
    }
}

SINGLE_BATTLE_TEST("Prankster-affected moves don't affect Dark-type Pokémon after they switch-in")
{
    GIVEN {
        WITH_CONFIG(B_PRANKSTER_DARK_TYPES, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_UMBREON);
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CONFUSE_RAY); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        MESSAGE("It doesn't affect Umbreon…");
    }
}

DOUBLE_BATTLE_TEST("Prankster-affected moves affect Ally Dark-type Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_UMBREON);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CONFUSE_RAY, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, playerLeft);
        NOT MESSAGE("It doesn't affect Umbreon…");
    }
}

SINGLE_BATTLE_TEST("Prankster-affected moves called via Assist don't affect Dark-type Pokémon (Gen 7+)")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_6; }
    PARAMETRIZE { gen = GEN_7; }
    GIVEN {
        WITH_CONFIG(B_PRANKSTER_DARK_TYPES, gen);
        PLAYER(SPECIES_UMBREON);
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_CONFUSE_RAY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ASSIST); }
    } SCENE {
        if (gen == GEN_6) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
            MESSAGE("It doesn't affect Umbreon…");
        }
    }
}

// Tested on Showdown, even though Bulbapedia says otherwise.
DOUBLE_BATTLE_TEST("Prankster-affected moves called via Instruct do not affect Dark-type Pokémon")
{
    u32 gen;
    PARAMETRIZE { gen = GEN_6; }
    PARAMETRIZE { gen = GEN_7; }
    GIVEN {
        WITH_CONFIG(B_PRANKSTER_DARK_TYPES, gen);
        PLAYER(SPECIES_VOLBEAT) { Speed(20); Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_UMBREON) { Speed(15); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_UMBREON) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CONFUSE_RAY, target: opponentLeft);
               MOVE(opponentLeft, MOVE_U_TURN, target: playerRight, WITH_RNG(RNG_CONFUSION, FALSE));
               SEND_OUT(opponentLeft, 2);
               MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft);
        }
    } SCENE {
        if (gen == GEN_6) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, playerLeft);
            MESSAGE("It doesn't affect the opposing Umbreon…");
        }
        MESSAGE("Wobbuffet used Instruct!");
        MESSAGE("Volbeat used Confuse Ray!");
        if (gen == GEN_6) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, playerLeft);
        } else {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, playerLeft);
            MESSAGE("It doesn't affect the opposing Umbreon…");
        }
    }
}

SINGLE_BATTLE_TEST("Prankster increases the priority of moves by 1")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_VOLBEAT) { Speed(5); Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); MOVE(player, MOVE_CELEBRATE, WITH_RNG(RNG_CONFUSION, FALSE)); } // RNG_CONFUSION so that Wobb doesn't hit itself.
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
    }
}

DOUBLE_BATTLE_TEST("Moves called via Prankster-affected After you affect Dark-type Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_VOLBEAT) { Speed(1); Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        OPPONENT(SPECIES_UMBREON) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_AFTER_YOU, target: playerRight);
               MOVE(playerRight, MOVE_CONFUSE_RAY, target: opponentLeft);
        }
    } SCENE {
        MESSAGE("Volbeat used After You!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AFTER_YOU, playerLeft);
        MESSAGE("Wobbuffet used Confuse Ray!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, playerRight);
        MESSAGE("The opposing Umbreon became confused!");
    }
}

SINGLE_BATTLE_TEST("Prankster is blocked by Quick Guard in Gen5+")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_QUICK_GUARD); MOVE(opponent, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_QUICK_GUARD, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, opponent);
        MESSAGE("Wobbuffet protected itself!");
    }
}

DOUBLE_BATTLE_TEST("Prankster-affected moves that target all Pokémon are successful regardless of the presence of Dark-type Pokémon")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_CAPTIVATE) == TARGET_BOTH);
        PLAYER(SPECIES_ILLUMISE) { Ability(ABILITY_PRANKSTER); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_UMBREON);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CAPTIVATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CAPTIVATE, playerLeft);
    }
}

SINGLE_BATTLE_TEST("Prankster-affected moves can still be bounced back by Dark-types using Magic Coat")
{
    GIVEN {
        PLAYER(SPECIES_UMBREON);
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_CONFUSE_RAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("The opposing Volbeat used Confuse Ray!");
        MESSAGE("Umbreon bounced the Confuse Ray back!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("The opposing Volbeat became confused!");
    }
}

SINGLE_BATTLE_TEST("Prankster-affected moves which are reflected by Magic Coat can affect Dark-type Pokémon, unless the Pokémon that bounced the move also has Prankster")
{
    enum Ability sableyeAbility;

    PARAMETRIZE { sableyeAbility = ABILITY_PRANKSTER; }
    PARAMETRIZE { sableyeAbility = ABILITY_KEEN_EYE; }

    GIVEN {
        WITH_CONFIG(B_PRANKSTER_DARK_TYPES, GEN_7);
        PLAYER(SPECIES_SABLEYE) { Ability(sableyeAbility); }
        OPPONENT(SPECIES_MURKROW) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_CONFUSE_RAY); }
    } SCENE {
        MESSAGE("Sableye used Magic Coat!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("The opposing Murkrow used Confuse Ray!");
        MESSAGE("Sableye bounced the Confuse Ray back!");
        if (sableyeAbility == ABILITY_PRANKSTER) {
            NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
            MESSAGE("It doesn't affect the opposing Murkrow…");
        } else {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
            MESSAGE("The opposing Murkrow became confused!");
        }
    }
}

SINGLE_BATTLE_TEST("Prankster-affected moves can still be bounced back by a Dark-type with Magic Bounce")
{
    GIVEN {
        PLAYER(SPECIES_ABSOL) { Item(ITEM_ABSOLITE); }
        OPPONENT(SPECIES_VOLBEAT) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CONFUSE_RAY); }
    } SCENE {
        MESSAGE("The opposing Volbeat's Confuse Ray was bounced back!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
    }
}

SINGLE_BATTLE_TEST("Prankster-affected moves that are bounced back by Magic Bounce can affect Dark-type Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_ABSOL) { Item(ITEM_ABSOLITE); }
        OPPONENT(SPECIES_MURKROW) { Ability(ABILITY_PRANKSTER); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CONFUSE_RAY); }
    } SCENE {
        MESSAGE("The opposing Murkrow's Confuse Ray was bounced back!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CONFUSE_RAY, player);
        MESSAGE("The opposing Murkrow became confused!");
    }
}

TO_DO_BATTLE_TEST("Prankster-affected moves called via Nature Power don't affect Dark-type Pokémon");
TO_DO_BATTLE_TEST("Prankster increases the priority of status Z-Moves by 1");
TO_DO_BATTLE_TEST("Prankster increases the priority of Extreme Evoboost by 1");
