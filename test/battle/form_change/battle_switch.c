#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Aegislash reverts to Shield Form upon switching out")
{
    GIVEN {
        PLAYER(SPECIES_AEGISLASH_SHIELD);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_STANCE_CHANGE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Aegislash used Scratch!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_AEGISLASH_SHIELD);
    }
}

SINGLE_BATTLE_TEST("Meloetta reverts to Aria Form upon switching out")
{
    u32 trial = 0;

    PARAMETRIZE { trial = 0; }
    PARAMETRIZE { trial = 1; }
    PARAMETRIZE { trial = 2; }
    
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_HONCHKROW) { Ability(ABILITY_INSOMNIA); }
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
        TURN { 
            switch (trial)
            {
            case 0:
                SWITCH(player, 1);
                break;
            case 1:
                MOVE(player, MOVE_PARTING_SHOT);
                SEND_OUT(player, 1);
                break;
            case 2:
                MOVE(opponent, MOVE_DRAGON_TAIL);
                break;
            }
        }
        TURN { SWITCH(player, 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_MELOETTA_ARIA);
    }
}
