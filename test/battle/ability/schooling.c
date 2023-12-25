#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Schooling switches Level 20+ Wishiwashi's form when HP is 25-percent or less at the end of the turn")
{
    u16 level;
    PARAMETRIZE { level = 19; }
    PARAMETRIZE { level = 20; }

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_WISHIWASHI_SOLO].baseHP == gSpeciesInfo[SPECIES_WISHIWASHI_SCHOOL].baseHP);
        PLAYER(SPECIES_WISHIWASHI_SOLO)
        {
            Level(level);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 2);
            Ability(ABILITY_SCHOOLING);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SUPER_FANG); }
    } SCENE {
        if (level >= 20)
        {
            ABILITY_POPUP(player, ABILITY_SCHOOLING);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
        MESSAGE("Wishiwashi used Celebrate!");
        MESSAGE("Foe Wobbuffet used Super Fang!");
        HP_BAR(player);
        if (level >= 20)
        {
            ABILITY_POPUP(player, ABILITY_SCHOOLING);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WISHIWASHI_SOLO);
    }
}

SINGLE_BATTLE_TEST("Schooling switches Level 20+ Wishiwashi's form when HP is over 25-percent before the first turn")
{
    u16 level;
    bool32 overQuarterHP;
    PARAMETRIZE { level = 19; overQuarterHP = FALSE; }
    PARAMETRIZE { level = 20; overQuarterHP = FALSE; }
    PARAMETRIZE { level = 19; overQuarterHP = TRUE; }
    PARAMETRIZE { level = 20; overQuarterHP = TRUE; }

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_WISHIWASHI_SOLO].baseHP == gSpeciesInfo[SPECIES_WISHIWASHI_SCHOOL].baseHP);
        PLAYER(SPECIES_WISHIWASHI_SOLO)
        {
            Level(level);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / (overQuarterHP ? 2 : 4));
            Ability(ABILITY_SCHOOLING);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (level >= 20 && overQuarterHP)
        {
            ABILITY_POPUP(player, ABILITY_SCHOOLING);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
        MESSAGE("Wishiwashi used Celebrate!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    } THEN {
        if (level >= 20 && overQuarterHP)
            EXPECT_EQ(player->species, SPECIES_WISHIWASHI_SCHOOL);
        else
            EXPECT_EQ(player->species, SPECIES_WISHIWASHI_SOLO);
    }
}

SINGLE_BATTLE_TEST("Schooling switches Level 20+ Wishiwashi's form when HP is healed above 25-percent")
{
    u16 level;
    PARAMETRIZE { level = 19; }
    PARAMETRIZE { level = 20; }

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_WISHIWASHI_SOLO].baseHP == gSpeciesInfo[SPECIES_WISHIWASHI_SCHOOL].baseHP);
        PLAYER(SPECIES_WISHIWASHI_SOLO)
        {
            Level(level);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 4);
            Ability(ABILITY_SCHOOLING);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_HEAL_PULSE); }
    } SCENE {
        MESSAGE("Wishiwashi used Celebrate!");
        MESSAGE("Foe Wobbuffet used Heal Pulse!");
        HP_BAR(player);
        if (level >= 20)
        {
            ABILITY_POPUP(player, ABILITY_SCHOOLING);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        }
    } THEN {
        if (level >= 20)
            EXPECT_EQ(player->species, SPECIES_WISHIWASHI_SCHOOL);
        else
            EXPECT_EQ(player->species, SPECIES_WISHIWASHI_SOLO);
    }
}
