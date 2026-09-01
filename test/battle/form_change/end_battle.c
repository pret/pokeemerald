#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Xerneas returns its Neutral Form upon battle end")
{
    GIVEN {
        PLAYER(SPECIES_XERNEAS_NEUTRAL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_XERNEAS_NEUTRAL);
    }
}

SINGLE_BATTLE_TEST("Zacian returns its Hero Form upon battle end")
{
    GIVEN {
        PLAYER(SPECIES_ZACIAN_HERO) { Item(ITEM_RUSTED_SWORD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_ZACIAN_HERO);
    }
}

SINGLE_BATTLE_TEST("Zacian returns its Hero Form upon battle end")
{
    GIVEN {
        ASSUME(GetMovePP(MOVE_BEHEMOTH_BLADE) == 5);
        PLAYER(SPECIES_ZACIAN_HERO) { Item(ITEM_RUSTED_SWORD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_ZACIAN_HERO);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1), MOVE_IRON_HEAD);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_PP1), 5); // Behemoth Blade's PP
    }
}

SINGLE_BATTLE_TEST("Zamazenta returns its Hero Form upon battle end")
{
    GIVEN {
        PLAYER(SPECIES_ZAMAZENTA_HERO) { Item(ITEM_RUSTED_SHIELD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_ZAMAZENTA_HERO);
    }
}

SINGLE_BATTLE_TEST("Zamazenta returns its Hero Form upon battle end")
{
    GIVEN {
        ASSUME(GetMovePP(MOVE_BEHEMOTH_BASH) == 5);
        PLAYER(SPECIES_ZAMAZENTA_HERO) { Item(ITEM_RUSTED_SHIELD); Moves(MOVE_IRON_HEAD, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_ZAMAZENTA_HERO);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_MOVE1), MOVE_IRON_HEAD);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_PP1), 5); // Behemoth Bash's PP
    }
}

SINGLE_BATTLE_TEST("Palafin returns to Zero form upon battle end")
{
    GIVEN {
        PLAYER(SPECIES_PALAFIN_ZERO) { Ability(ABILITY_ZERO_TO_HERO); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
        TURN { SWITCH(player, 0); }
    } SCENE {
        SWITCH_OUT_MESSAGE("Palafin");
        SEND_IN_MESSAGE("Wobbuffet");
        SWITCH_OUT_MESSAGE("Wobbuffet");
        SEND_IN_MESSAGE("Palafin");
        ABILITY_POPUP(player, ABILITY_ZERO_TO_HERO);
        MESSAGE("Palafin underwent a heroic transformation!");
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_PALAFIN_ZERO);
    }
}

SINGLE_BATTLE_TEST("Shaymin retains Land form if it was frozen or frostbitten in battle")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POWDER_SNOW, MOVE_EFFECT_FREEZE_OR_FROSTBITE));
        PLAYER(SPECIES_SHAYMIN_SKY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_POWDER_SNOW); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWDER_SNOW, opponent);
        FREEZE_OR_FROSTBURN_STATUS(player, TRUE);
        NOT HP_BAR(player); // Regression caused by Mimikyu form change
        MESSAGE("Shaymin transformed!");
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_SHAYMIN_LAND);
    }
}

SINGLE_BATTLE_TEST("Meloetta returns to Aria form upon battle end after using Relic Song")
{
    GIVEN {
        PLAYER(SPECIES_MELOETTA_ARIA);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        MESSAGE("Meloetta transformed!");
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_MELOETTA_ARIA);
    }
}

SINGLE_BATTLE_TEST("Battle Bond Greninja returns to base form upon battle end after knocking out an opponent")
{
    GIVEN {
        WITH_CONFIG(B_BATTLE_BOND, GEN_8);
        PLAYER(SPECIES_GRENINJA_BATTLE_BOND);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN); SEND_OUT(opponent, 1); }
    } SCENE {
        HP_BAR(opponent);
        MESSAGE("The opposing Wobbuffet fainted!");
        ABILITY_POPUP(player, ABILITY_BATTLE_BOND);
        MESSAGE("Greninja became fully charged due to its bond with its trainer!");
        MESSAGE("Greninja became Ash-Greninja!");
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_GRENINJA_BATTLE_BOND);
    }
}

SINGLE_BATTLE_TEST("Aegislash reverts to Shield Form upon battle end after using an attack")
{
    GIVEN {
        PLAYER(SPECIES_AEGISLASH_SHIELD);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_AEGISLASH_SHIELD);
    }
}

SINGLE_BATTLE_TEST("Wishiwashi reverts to Solo form upon battle end after changing form at the beginning of the battle")
{
    GIVEN {
        PLAYER(SPECIES_WISHIWASHI_SOLO) { Level(100); Ability(ABILITY_SCHOOLING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SCHOOLING);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_WISHIWASHI_SOLO);
    }
}

SINGLE_BATTLE_TEST("Minior Meteor reverts to Core form upon battle end after changing form at the beginning of the battle")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_MINIOR_CORE) { Ability(ABILITY_SHIELDS_DOWN); HP(51); MaxHP(101); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); SEND_OUT(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SHIELDS_DOWN);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_SPECIES), SPECIES_MINIOR_CORE);
    }
}

SINGLE_BATTLE_TEST("Mimikyu Busted reverts to Disguised form upon battle end after busting its Disguise in battle")
{
    enum Species species;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; }
    GIVEN {
        WITH_CONFIG(B_DISGUISE_HP_LOSS, GEN_7);
        PLAYER(species) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_DISGUISE, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), species);
    }
}

SINGLE_BATTLE_TEST("Cramorant reverts to base Form upon battle end after using Surf in battle")
{
    GIVEN {
        PLAYER(SPECIES_CRAMORANT) { Ability(ABILITY_GULP_MISSILE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SURF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SURF, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE_INSTANT, player);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_CRAMORANT);
    }
}

SINGLE_BATTLE_TEST("Eiscue Noice reverts to Ice Form upon battle end after being hit by a physical move in battle")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_EISCUE_ICE);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_ICE_FACE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Eiscue transformed!");
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_EISCUE_ICE);
    }
}

SINGLE_BATTLE_TEST("Morpeko Hangry reverts to Full Belly Form upon battle end after changing forms at the end of the turn")
{
    GIVEN {
        PLAYER(SPECIES_MORPEKO_FULL_BELLY) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Morpeko used Celebrate!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_MORPEKO_FULL_BELLY);
    }
}

SINGLE_BATTLE_TEST("Ogerpon reverts to the correct form upon battle end after terastallizing")
{
    enum Species species;
    enum Item item;
    PARAMETRIZE { species = SPECIES_OGERPON_TEAL;        item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING;  item = ITEM_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME; item = ITEM_HEARTHFLAME_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE; item = ITEM_CORNERSTONE_MASK; }
    GIVEN {
        PLAYER(species) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), species);
    }
}

SINGLE_BATTLE_TEST("Terapagos reverts to the correct form upon battle end after terastallizing")
{
    GIVEN {
        PLAYER(SPECIES_TERAPAGOS_NORMAL);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_TERA); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_TERAPAGOS_NORMAL);
    }
}

SINGLE_BATTLE_TEST("Power Construct Zygarde reverts to its original form upon battle end")
{
    enum Species baseSpecies;
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_10_POWER_CONSTRUCT; }
    PARAMETRIZE { baseSpecies = SPECIES_ZYGARDE_50_POWER_CONSTRUCT; }

    GIVEN {
        PLAYER(baseSpecies)
        {
            Ability(ABILITY_POWER_CONSTRUCT);
            HP((GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 2) + 1);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("You sense the presence of many!");
        ABILITY_POPUP(player, ABILITY_POWER_CONSTRUCT);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_POWER_CONSTRUCT, player);

    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), baseSpecies);
    }
}
